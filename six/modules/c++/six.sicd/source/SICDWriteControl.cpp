/* =========================================================================
 * This file is part of six.sicd-c++
 * =========================================================================
 *
 * (C) Copyright 2004 - 2016, MDA Information Systems LLC
 *
 * six.sicd-c++ is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include <six/sicd/SICDWriteControl.h>

namespace six
{
namespace sicd
{
SICDWriteControl::SICDWriteControl(const std::string& outputPathname,
                                   const std::vector<std::string>& schemaPaths) :
    mIO(new nitf::BufferedWriter(outputPathname, DEFAULT_BUFFER_SIZE)),
    mSchemaPaths(schemaPaths),
    mHaveWrittenHeaders(false)
{
}

void SICDWriteControl::initialize(const ComplexData& data)
{
    mem::SharedPtr<Container> container(new Container(
            DataType::COMPLEX));

    // The container wants to take ownership of the data
    // To avoid memory problems, we'll just clone it
    container->addData(data.clone());
    initialize(container);
}

void SICDWriteControl::write(const std::vector<sys::byte>& data)
{
    if (!data.empty())
    {
        mIO->write(&data[0], data.size());
    }
}

void SICDWriteControl::writeHeaders()
{
    mWriter.prepareIO(*mIO, mRecord);

    std::vector<sys::byte> fileHeader;
    std::vector<std::vector<sys::byte> > imageSubheaders;
    std::vector<sys::byte> desSubheaderAndData;
    std::vector<size_t> imageSubheaderFileOffsets;
    size_t desSubheaderFileOffset;
    size_t fileNumBytes;
    getFileLayout(mSchemaPaths,
                  fileHeader,
                  imageSubheaders,
                  desSubheaderAndData,
                  imageSubheaderFileOffsets,
                  desSubheaderFileOffset,
                  fileNumBytes);

    // Write the file header
    write(fileHeader);

    // Write image subheaders
    mImageDataStart.resize(imageSubheaders.size());
    for (size_t ii = 0; ii < imageSubheaders.size(); ++ii)
    {
        mIO->seek(imageSubheaderFileOffsets[ii], NITF_SEEK_SET);
        write(imageSubheaders[ii]);
        mImageDataStart[ii] = mIO->tell();
    }

    // Write DES subheader and data (i.e. XML)
    mIO->seek(desSubheaderFileOffset, NITF_SEEK_SET);
    write(desSubheaderAndData);
}

void SICDWriteControl::save(void* imageData,
                            const types::RowCol<size_t>& offset,
                            const types::RowCol<size_t>& dims,
                            bool restoreData)
{
    if (mContainer.get() == NULL)
    {
        throw except::Exception(Ctxt(
                "initialize() must be called prior to calling save()"));
    }

    // The first time through we'll write out all the headers
    if (!mHaveWrittenHeaders)
    {
        writeHeaders();
        mHaveWrittenHeaders = true;
    }

    const six::Data* const data = mContainer->getData(0);
    static const size_t NUM_BANDS = 2;
    const size_t numBytesPerPixel = data->getNumBytesPerPixel() / NUM_BANDS;
    const size_t numPixelsTotal = dims.area() * NUM_BANDS;
    const bool doByteSwap = shouldByteSwap();

    // Byte swap if needed
    if (doByteSwap)
    {
        sys::byteSwap(imageData,
                      static_cast<unsigned short>(numBytesPerPixel),
                      numPixelsTotal);
    }

    const std::vector <NITFSegmentInfo> imageSegments
                    = mInfos[0]->getImageSegments();

    const size_t globalNumCols = data->getNumCols();
    const size_t imageDataEndRow = offset.row + dims.row;

    for (size_t seg = 0; seg < imageSegments.size(); ++seg)
    {
        // See if we're in this segment
        const size_t segStartRow = imageSegments[seg].firstRow;
        const size_t segEndRow = segStartRow + imageSegments[seg].numRows;

        const size_t startGlobalRowToWrite = std::max(segStartRow, offset.row);
        const size_t endGlobalRowToWrite = std::min(segEndRow, imageDataEndRow);

        if (endGlobalRowToWrite > startGlobalRowToWrite)
        {
            const size_t numRowsToWrite =
                    endGlobalRowToWrite - startGlobalRowToWrite;

            // Figure out what offset of 'imageData' we're writing from
            const size_t startLocalRowToWrite =
                    startGlobalRowToWrite - offset.row;
            const size_t numBytesPerRow = dims.col * numBytesPerPixel * NUM_BANDS;
            const sys::ubyte* imageDataPtr =
                    static_cast<sys::ubyte*>(imageData) +
                    startLocalRowToWrite * numBytesPerRow;

            // Now figure out our offset into the segment
            const size_t startRowInSegToWrite =
                    startGlobalRowToWrite - segStartRow;
            const size_t pixelOffset =
                    startRowInSegToWrite * globalNumCols + offset.col;
            size_t byteOffset = mImageDataStart[seg] +
                    pixelOffset * numBytesPerPixel * NUM_BANDS;

            // TODO: For SIDD we'll have to handle blocking too

            if (dims.col == globalNumCols)
            {
                // Life is easy - one write
                mIO->seek(byteOffset, NITF_SEEK_SET);
                mIO->write(imageDataPtr,
                           numRowsToWrite * dims.col * NUM_BANDS *
                               numBytesPerPixel);
            }
            else
            {
                // Need to write out partial rows
                const size_t rowSeekStride =
                        globalNumCols * numBytesPerPixel * NUM_BANDS;

                for (size_t row = 0;
                     row < numRowsToWrite;
                     ++row, byteOffset += rowSeekStride,
                         imageDataPtr += numBytesPerRow)
                {
                    mIO->seek(byteOffset, NITF_SEEK_SET);
                    mIO->write(imageDataPtr, numBytesPerRow);
                }
            }
        }
    }

    // Byte swap back if needed
    if (doByteSwap && restoreData)
    {
        sys::byteSwap(imageData,
                      static_cast<unsigned short>(numBytesPerPixel),
                      numPixelsTotal);
    }
}

void SICDWriteControl::close()
{
    mIO->close();
}
}
}
