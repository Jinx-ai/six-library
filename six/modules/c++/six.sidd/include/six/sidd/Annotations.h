/* =========================================================================
 * This file is part of six.sidd-c++
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * six.sidd-c++ is free software; you can redistribute it and/or modify
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
#ifndef __SIX_SIDD_ANNOTATIONS_H__
#define __SIX_SIDD_ANNOTATIONS_H__

#include <import/six.h>
#include "six/sidd/SFA.h"

namespace six
{
namespace sidd
{

struct Annotation
{
    std::string identifier;
    mem::ScopedCopyablePtr<SFAReferenceSystem> spatialReferenceSystem;
    std::vector<mem::ScopedCopyablePtr<SFAGeometry> > objects;

    Annotation() {}

    Annotation(const Annotation& other)
    {
        identifier = other.identifier;
        spatialReferenceSystem = other.spatialReferenceSystem;
        objects.resize(other.objects.size());
        for (size_t ii = 0; ii < other.objects.size(); ++ii)
        {
            objects[ii].reset(other.objects[ii]->clone());
        }
    }
};

typedef std::vector<mem::ScopedCopyablePtr<Annotation> > Annotations;

}
}
#endif

