/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * NITRO is free software; you can redistribute it and/or modify
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
 * License along with this program; if not, If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __NITF_BANDSOURCE_HPP__
#define __NITF_BANDSOURCE_HPP__

#include <string.h>
#include <string>

#include "nitf/BandSource.h"
#include "nitf/RowSource.h"
#include "nitf/DirectBlockSource.h"
#include "nitf/DataSource.hpp"
#include "nitf/IOHandle.hpp"
#include "nitf/System.hpp"
#include "nitf/ImageReader.hpp"

/*!
 *  \file BandSource.hpp
 *  \brief  Contains wrapper implementations for BandSources
 */
namespace nitf
{
//! BandSource === DataSource
typedef DataSource BandSource;

/*!
 *  \class MemorySource
 *  \brief  The C++ wrapper for the nitf_MemorySource.
 *
 *  The memory source class allows us to read directly from
 *  a data buffer.  In the event that this is a memory-mapped file,
 *  we will likely get a performance gain over the direct fd approach.
 *
 *  The constructor takes in a buffer, a size, and optionally a
 *  sampling factor (Typically, the factor will be applied most
 *  times during the case of memory mapping, although it may be used
 *  to sample down or cut the image into pieces).
 */
class MemorySource : public BandSource
{
public:
    /*!
     *  Constructor
     *  \param data  The memory buffer
     *  \param size  The size of the buffer
     *  \param start  The start offset
     *  \param numBytesPerPixel The number of bytes per pixel
     *  \param pixelSkip  The amount of pixels to skip
     */
    MemorySource(const void* data, size_t size, nitf::Off start,
            int numBytesPerPixel, int pixelSkip);
};

/*!
 *  \class FileSource
 *  \brief  The C++ wrapper for the nitf_FileSource
 *
 *  The FileSource class is a BandSource that comes from an open
 *  file descriptor or handle.  Due to any number of constraints,
 *  not the least of which is the band interleaved by pixel case,
 *  we allow the creator to specify a start point, and a pixel skip
 *  (this would help you create a thumbnail as well).
 */
class FileSource : public BandSource
{
public:
    FileSource(const std::string& fname,
               nitf::Off start,
               int numBytesPerPixel,
               int pixelSkip);

    /*!
     *  Constructor
     *  \param io The handle to store
     *  \param start  The location to seek to (as the beginning)
     *  \param numBytesPerPixel The number of bytes per pixel
     *  \param pixelSkip  The number of pixels to skip each time
     */
    FileSource(nitf::IOHandle& io,
               nitf::Off start,
               int numBytesPerPixel,
               int pixelSkip);
};

struct RowSourceCallback
{
    virtual ~RowSourceCallback()
    {
    }

    virtual void nextRow(nitf::Uint32 band, void* buf) = 0;
};

class RowSource : public BandSource
{
public:
    RowSource(nitf::Uint32 band, nitf::Uint32 numRows, nitf::Uint32 numCols,
            nitf::Uint32 pixelSize, RowSourceCallback *callback);

private:
    static
    NITF_BOOL nextRow(void* algorithm,
                      nitf_Uint32 band,
                      NITF_DATA* buffer,
                      nitf_Error* error);

private:
    nitf::Uint32 mBand, mNumRows, mNumCols, mPixelSize;
};

class DirectBlockSource : public BandSource
{
public:
    DirectBlockSource(nitf::ImageReader& imageReader,
                      nitf::Uint32 numBands);

protected:
    virtual void nextBlock(void* buf,
                           const void* block,
                           nitf::Uint32 blockNumber,
                           nitf::Uint64 blockSize) = 0;
private:
    static
    NITF_BOOL nextBlock(void *algorithm,
                        void* buf,
                        const void* block,
                        nitf_Uint32 blockNumber,
                        nitf_Uint64 blockSize,
                        nitf_Error * error);
};

class CopyBlockSource: public ::nitf::DirectBlockSource
{
public:
    CopyBlockSource(nitf::ImageReader& imageReader, nitf::Uint32 numBands) :
        nitf::DirectBlockSource(imageReader, numBands)
    {}

    virtual ~CopyBlockSource(){}

protected:
    virtual void nextBlock(void* buf,
                           const void* block,
                           nitf::Uint32 /*blockNumber*/,
                           nitf::Uint64 blockSize)
    {
        memcpy(buf, block, blockSize);
    }
};


}

#endif
