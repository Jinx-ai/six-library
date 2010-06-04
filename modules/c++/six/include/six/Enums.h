/* =========================================================================
 * This file is part of six-c++ 
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2009, General Dynamics - Advanced Information Systems
 *
 * six-c++ is free software; you can redistribute it and/or modify
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
#ifndef __SIX_ENUMS_H__
#define __SIX_ENUMS_H__

#include <import/except.h>
#include <import/str.h>
#include <import/sys.h>

// -----------------------------------------------------------------------------
// This file is auto-generated - please do NOT edit directly
// -----------------------------------------------------------------------------

namespace six
{


/*!
 *  \struct AppliedType 
 *
 *  Enumeration used to represent AppliedTypes
 */
struct AppliedType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = -1,
        IS_FALSE = 0,
        IS_TRUE = 1
    };

    //! Default constructor
    AppliedType(){ value = NOT_SET; }

    //! string constructor
    AppliedType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "IS_FALSE")
            value = IS_FALSE;
        else if (s == "IS_TRUE")
            value = IS_TRUE;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    AppliedType(int i)
    {
        switch(i)
        {
        case -1:
            value = NOT_SET;
            break;
        case 0:
            value = IS_FALSE;
            break;
        case 1:
            value = IS_TRUE;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~AppliedType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case -1:
            return std::string("NOT_SET");
        case 0:
            return std::string("IS_FALSE");
        case 1:
            return std::string("IS_TRUE");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    AppliedType& operator=(const AppliedType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const AppliedType& o) const { return value == o.value; }
    bool operator!=(const AppliedType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    AppliedType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const AppliedType& o) const { return value < o.value; }
    bool operator>(const AppliedType& o) const { return value > o.value; }
    bool operator<=(const AppliedType& o) const { return value <= o.value; }
    bool operator>=(const AppliedType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct AutofocusType 
 *
 *  Enumeration used to represent AutofocusTypes
 */
struct AutofocusType
{
    //! The enumerations allowed
    enum
    {
        NO = 0,
        GLOBAL = 1,
        SV = 2
    };

    //! Default constructor
    AutofocusType(){ value = NO; }

    //! string constructor
    AutofocusType(std::string s)
    {
        if (s == "NO")
            value = NO;
        else if (s == "GLOBAL")
            value = GLOBAL;
        else if (s == "SV")
            value = SV;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    AutofocusType(int i)
    {
        switch(i)
        {
        case 0:
            value = NO;
            break;
        case 1:
            value = GLOBAL;
            break;
        case 2:
            value = SV;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~AutofocusType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NO");
        case 1:
            return std::string("GLOBAL");
        case 2:
            return std::string("SV");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    AutofocusType& operator=(const AutofocusType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const AutofocusType& o) const { return value == o.value; }
    bool operator!=(const AutofocusType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    AutofocusType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const AutofocusType& o) const { return value < o.value; }
    bool operator>(const AutofocusType& o) const { return value > o.value; }
    bool operator<=(const AutofocusType& o) const { return value <= o.value; }
    bool operator>=(const AutofocusType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct BooleanType 
 *
 *  Enumeration used to represent BooleanTypes
 */
struct BooleanType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = -1,
        IS_FALSE = 0,
        IS_TRUE = 1
    };

    //! Default constructor
    BooleanType(){ value = NOT_SET; }

    //! string constructor
    BooleanType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "IS_FALSE")
            value = IS_FALSE;
        else if (s == "IS_TRUE")
            value = IS_TRUE;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    BooleanType(int i)
    {
        switch(i)
        {
        case -1:
            value = NOT_SET;
            break;
        case 0:
            value = IS_FALSE;
            break;
        case 1:
            value = IS_TRUE;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~BooleanType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case -1:
            return std::string("NOT_SET");
        case 0:
            return std::string("IS_FALSE");
        case 1:
            return std::string("IS_TRUE");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    BooleanType& operator=(const BooleanType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const BooleanType& o) const { return value == o.value; }
    bool operator!=(const BooleanType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    BooleanType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const BooleanType& o) const { return value < o.value; }
    bool operator>(const BooleanType& o) const { return value > o.value; }
    bool operator<=(const BooleanType& o) const { return value <= o.value; }
    bool operator>=(const BooleanType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct ByteSwapping 
 *
 *  Enumeration used to represent ByteSwappings
 */
struct ByteSwapping
{
    //! The enumerations allowed
    enum
    {
        SWAP_OFF = 0,
        SWAP_ON = 1,
        SWAP_AUTO = 2
    };

    //! Default constructor
    ByteSwapping(){ value = SWAP_OFF; }

    //! string constructor
    ByteSwapping(std::string s)
    {
        if (s == "SWAP_OFF")
            value = SWAP_OFF;
        else if (s == "SWAP_ON")
            value = SWAP_ON;
        else if (s == "SWAP_AUTO")
            value = SWAP_AUTO;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    ByteSwapping(int i)
    {
        switch(i)
        {
        case 0:
            value = SWAP_OFF;
            break;
        case 1:
            value = SWAP_ON;
            break;
        case 2:
            value = SWAP_AUTO;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~ByteSwapping(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("SWAP_OFF");
        case 1:
            return std::string("SWAP_ON");
        case 2:
            return std::string("SWAP_AUTO");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    ByteSwapping& operator=(const ByteSwapping& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const ByteSwapping& o) const { return value == o.value; }
    bool operator!=(const ByteSwapping& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    ByteSwapping& operator=(const int& o) { value = o; return *this; }
    bool operator<(const ByteSwapping& o) const { return value < o.value; }
    bool operator>(const ByteSwapping& o) const { return value > o.value; }
    bool operator<=(const ByteSwapping& o) const { return value <= o.value; }
    bool operator>=(const ByteSwapping& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct CollectType 
 *
 *  Enumeration used to represent CollectTypes
 */
struct CollectType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        MONOSTATIC = 1,
        BISTATIC = 2
    };

    //! Default constructor
    CollectType(){ value = NOT_SET; }

    //! string constructor
    CollectType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "MONOSTATIC")
            value = MONOSTATIC;
        else if (s == "BISTATIC")
            value = BISTATIC;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    CollectType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = MONOSTATIC;
            break;
        case 2:
            value = BISTATIC;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~CollectType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("MONOSTATIC");
        case 2:
            return std::string("BISTATIC");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    CollectType& operator=(const CollectType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const CollectType& o) const { return value == o.value; }
    bool operator!=(const CollectType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    CollectType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const CollectType& o) const { return value < o.value; }
    bool operator>(const CollectType& o) const { return value > o.value; }
    bool operator<=(const CollectType& o) const { return value <= o.value; }
    bool operator>=(const CollectType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct ComplexImageGridType 
 *
 *  Enumeration used to represent ComplexImageGridTypes
 */
struct ComplexImageGridType
{
    //! The enumerations allowed
    enum
    {
        RGAZIM = 0,
        RGZERO = 1,
        XRGYCR = 2,
        XCTYAT = 3,
        PLANE = 4
    };

    //! Default constructor
    ComplexImageGridType(){ value = RGAZIM; }

    //! string constructor
    ComplexImageGridType(std::string s)
    {
        if (s == "RGAZIM")
            value = RGAZIM;
        else if (s == "RGZERO")
            value = RGZERO;
        else if (s == "XRGYCR")
            value = XRGYCR;
        else if (s == "XCTYAT")
            value = XCTYAT;
        else if (s == "PLANE")
            value = PLANE;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    ComplexImageGridType(int i)
    {
        switch(i)
        {
        case 0:
            value = RGAZIM;
            break;
        case 1:
            value = RGZERO;
            break;
        case 2:
            value = XRGYCR;
            break;
        case 3:
            value = XCTYAT;
            break;
        case 4:
            value = PLANE;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~ComplexImageGridType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("RGAZIM");
        case 1:
            return std::string("RGZERO");
        case 2:
            return std::string("XRGYCR");
        case 3:
            return std::string("XCTYAT");
        case 4:
            return std::string("PLANE");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    ComplexImageGridType& operator=(const ComplexImageGridType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const ComplexImageGridType& o) const { return value == o.value; }
    bool operator!=(const ComplexImageGridType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    ComplexImageGridType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const ComplexImageGridType& o) const { return value < o.value; }
    bool operator>(const ComplexImageGridType& o) const { return value > o.value; }
    bool operator<=(const ComplexImageGridType& o) const { return value <= o.value; }
    bool operator>=(const ComplexImageGridType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct ComplexImagePlaneType 
 *
 *  Enumeration used to represent ComplexImagePlaneTypes
 */
struct ComplexImagePlaneType
{
    //! The enumerations allowed
    enum
    {
        OTHER = 0,
        SLANT = 1,
        GROUND = 2
    };

    //! Default constructor
    ComplexImagePlaneType(){ value = OTHER; }

    //! string constructor
    ComplexImagePlaneType(std::string s)
    {
        if (s == "OTHER")
            value = OTHER;
        else if (s == "SLANT")
            value = SLANT;
        else if (s == "GROUND")
            value = GROUND;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    ComplexImagePlaneType(int i)
    {
        switch(i)
        {
        case 0:
            value = OTHER;
            break;
        case 1:
            value = SLANT;
            break;
        case 2:
            value = GROUND;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~ComplexImagePlaneType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("OTHER");
        case 1:
            return std::string("SLANT");
        case 2:
            return std::string("GROUND");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    ComplexImagePlaneType& operator=(const ComplexImagePlaneType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const ComplexImagePlaneType& o) const { return value == o.value; }
    bool operator!=(const ComplexImagePlaneType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    ComplexImagePlaneType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const ComplexImagePlaneType& o) const { return value < o.value; }
    bool operator>(const ComplexImagePlaneType& o) const { return value > o.value; }
    bool operator<=(const ComplexImagePlaneType& o) const { return value <= o.value; }
    bool operator>=(const ComplexImagePlaneType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct CornerIndex 
 *
 *  Enumeration used to represent CornerIndexs
 */
struct CornerIndex
{
    //! The enumerations allowed
    enum
    {
        FIRST_ROW_FIRST_COL = 0,
        FIRST_ROW_LAST_COL = 1,
        LAST_ROW_LAST_COL = 2,
        LAST_ROW_FIRST_COL = 3
    };

    //! Default constructor
    CornerIndex(){ value = FIRST_ROW_FIRST_COL; }

    //! string constructor
    CornerIndex(std::string s)
    {
        if (s == "FIRST_ROW_FIRST_COL")
            value = FIRST_ROW_FIRST_COL;
        else if (s == "FIRST_ROW_LAST_COL")
            value = FIRST_ROW_LAST_COL;
        else if (s == "LAST_ROW_LAST_COL")
            value = LAST_ROW_LAST_COL;
        else if (s == "LAST_ROW_FIRST_COL")
            value = LAST_ROW_FIRST_COL;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    CornerIndex(int i)
    {
        switch(i)
        {
        case 0:
            value = FIRST_ROW_FIRST_COL;
            break;
        case 1:
            value = FIRST_ROW_LAST_COL;
            break;
        case 2:
            value = LAST_ROW_LAST_COL;
            break;
        case 3:
            value = LAST_ROW_FIRST_COL;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~CornerIndex(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("FIRST_ROW_FIRST_COL");
        case 1:
            return std::string("FIRST_ROW_LAST_COL");
        case 2:
            return std::string("LAST_ROW_LAST_COL");
        case 3:
            return std::string("LAST_ROW_FIRST_COL");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    CornerIndex& operator=(const CornerIndex& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const CornerIndex& o) const { return value == o.value; }
    bool operator!=(const CornerIndex& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    CornerIndex& operator=(const int& o) { value = o; return *this; }
    bool operator<(const CornerIndex& o) const { return value < o.value; }
    bool operator>(const CornerIndex& o) const { return value > o.value; }
    bool operator<=(const CornerIndex& o) const { return value <= o.value; }
    bool operator>=(const CornerIndex& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct DataClass 
 *
 *  Enumeration used to represent DataClasss
 */
struct DataClass
{
    //! The enumerations allowed
    enum
    {
        UNKNOWN = 0,
        COMPLEX = 1,
        DERIVED = 2
    };

    //! Default constructor
    DataClass(){ value = UNKNOWN; }

    //! string constructor
    DataClass(std::string s)
    {
        if (s == "UNKNOWN")
            value = UNKNOWN;
        else if (s == "COMPLEX")
            value = COMPLEX;
        else if (s == "DERIVED")
            value = DERIVED;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    DataClass(int i)
    {
        switch(i)
        {
        case 0:
            value = UNKNOWN;
            break;
        case 1:
            value = COMPLEX;
            break;
        case 2:
            value = DERIVED;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~DataClass(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("UNKNOWN");
        case 1:
            return std::string("COMPLEX");
        case 2:
            return std::string("DERIVED");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    DataClass& operator=(const DataClass& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const DataClass& o) const { return value == o.value; }
    bool operator!=(const DataClass& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    DataClass& operator=(const int& o) { value = o; return *this; }
    bool operator<(const DataClass& o) const { return value < o.value; }
    bool operator>(const DataClass& o) const { return value > o.value; }
    bool operator<=(const DataClass& o) const { return value <= o.value; }
    bool operator>=(const DataClass& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct DataType 
 *
 *  Enumeration used to represent DataTypes
 */
struct DataType
{
    //! The enumerations allowed
    enum
    {
        UNKNOWN = 0,
        COMPLEX = 1,
        DERIVED = 2
    };

    //! Default constructor
    DataType(){ value = UNKNOWN; }

    //! string constructor
    DataType(std::string s)
    {
        if (s == "UNKNOWN")
            value = UNKNOWN;
        else if (s == "COMPLEX")
            value = COMPLEX;
        else if (s == "DERIVED")
            value = DERIVED;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    DataType(int i)
    {
        switch(i)
        {
        case 0:
            value = UNKNOWN;
            break;
        case 1:
            value = COMPLEX;
            break;
        case 2:
            value = DERIVED;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~DataType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("UNKNOWN");
        case 1:
            return std::string("COMPLEX");
        case 2:
            return std::string("DERIVED");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    DataType& operator=(const DataType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const DataType& o) const { return value == o.value; }
    bool operator!=(const DataType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    DataType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const DataType& o) const { return value < o.value; }
    bool operator>(const DataType& o) const { return value > o.value; }
    bool operator<=(const DataType& o) const { return value <= o.value; }
    bool operator>=(const DataType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct DecimationMethod 
 *
 *  Enumeration used to represent DecimationMethods
 */
struct DecimationMethod
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        NEAREST_NEIGHBOR = 1,
        BILINEAR = 2,
        BRIGHTEST_PIXEL = 3,
        LAGRANGE = 4
    };

    //! Default constructor
    DecimationMethod(){ value = NOT_SET; }

    //! string constructor
    DecimationMethod(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "NEAREST_NEIGHBOR")
            value = NEAREST_NEIGHBOR;
        else if (s == "BILINEAR")
            value = BILINEAR;
        else if (s == "BRIGHTEST_PIXEL")
            value = BRIGHTEST_PIXEL;
        else if (s == "LAGRANGE")
            value = LAGRANGE;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    DecimationMethod(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = NEAREST_NEIGHBOR;
            break;
        case 2:
            value = BILINEAR;
            break;
        case 3:
            value = BRIGHTEST_PIXEL;
            break;
        case 4:
            value = LAGRANGE;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~DecimationMethod(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("NEAREST_NEIGHBOR");
        case 2:
            return std::string("BILINEAR");
        case 3:
            return std::string("BRIGHTEST_PIXEL");
        case 4:
            return std::string("LAGRANGE");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    DecimationMethod& operator=(const DecimationMethod& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const DecimationMethod& o) const { return value == o.value; }
    bool operator!=(const DecimationMethod& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    DecimationMethod& operator=(const int& o) { value = o; return *this; }
    bool operator<(const DecimationMethod& o) const { return value < o.value; }
    bool operator>(const DecimationMethod& o) const { return value > o.value; }
    bool operator<=(const DecimationMethod& o) const { return value <= o.value; }
    bool operator>=(const DecimationMethod& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct DemodType 
 *
 *  Enumeration used to represent DemodTypes
 */
struct DemodType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        STRETCH = 1,
        CHIRP = 2
    };

    //! Default constructor
    DemodType(){ value = NOT_SET; }

    //! string constructor
    DemodType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "STRETCH")
            value = STRETCH;
        else if (s == "CHIRP")
            value = CHIRP;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    DemodType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = STRETCH;
            break;
        case 2:
            value = CHIRP;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~DemodType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("STRETCH");
        case 2:
            return std::string("CHIRP");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    DemodType& operator=(const DemodType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const DemodType& o) const { return value == o.value; }
    bool operator!=(const DemodType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    DemodType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const DemodType& o) const { return value < o.value; }
    bool operator>(const DemodType& o) const { return value > o.value; }
    bool operator<=(const DemodType& o) const { return value <= o.value; }
    bool operator>=(const DemodType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct DisplayType 
 *
 *  Enumeration used to represent DisplayTypes
 */
struct DisplayType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        COLOR = 1,
        MONO = 2
    };

    //! Default constructor
    DisplayType(){ value = NOT_SET; }

    //! string constructor
    DisplayType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "COLOR")
            value = COLOR;
        else if (s == "MONO")
            value = MONO;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    DisplayType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = COLOR;
            break;
        case 2:
            value = MONO;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~DisplayType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("COLOR");
        case 2:
            return std::string("MONO");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    DisplayType& operator=(const DisplayType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const DisplayType& o) const { return value == o.value; }
    bool operator!=(const DisplayType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    DisplayType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const DisplayType& o) const { return value < o.value; }
    bool operator>(const DisplayType& o) const { return value > o.value; }
    bool operator<=(const DisplayType& o) const { return value <= o.value; }
    bool operator>=(const DisplayType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct DualPolarizationType 
 *
 *  Enumeration used to represent DualPolarizationTypes
 */
struct DualPolarizationType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        OTHER = 1,
        V_V = 2,
        V_H = 3,
        H_V = 4,
        H_H = 5,
        RHC_RHC = 6,
        RHC_LHC = 7,
        LHC_LHC = 8
    };

    //! Default constructor
    DualPolarizationType(){ value = NOT_SET; }

    //! string constructor
    DualPolarizationType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "OTHER")
            value = OTHER;
        else if (s == "V_V")
            value = V_V;
        else if (s == "V_H")
            value = V_H;
        else if (s == "H_V")
            value = H_V;
        else if (s == "H_H")
            value = H_H;
        else if (s == "RHC_RHC")
            value = RHC_RHC;
        else if (s == "RHC_LHC")
            value = RHC_LHC;
        else if (s == "LHC_LHC")
            value = LHC_LHC;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    DualPolarizationType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = OTHER;
            break;
        case 2:
            value = V_V;
            break;
        case 3:
            value = V_H;
            break;
        case 4:
            value = H_V;
            break;
        case 5:
            value = H_H;
            break;
        case 6:
            value = RHC_RHC;
            break;
        case 7:
            value = RHC_LHC;
            break;
        case 8:
            value = LHC_LHC;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~DualPolarizationType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("OTHER");
        case 2:
            return std::string("V_V");
        case 3:
            return std::string("V_H");
        case 4:
            return std::string("H_V");
        case 5:
            return std::string("H_H");
        case 6:
            return std::string("RHC_RHC");
        case 7:
            return std::string("RHC_LHC");
        case 8:
            return std::string("LHC_LHC");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    DualPolarizationType& operator=(const DualPolarizationType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const DualPolarizationType& o) const { return value == o.value; }
    bool operator!=(const DualPolarizationType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    DualPolarizationType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const DualPolarizationType& o) const { return value < o.value; }
    bool operator>(const DualPolarizationType& o) const { return value > o.value; }
    bool operator<=(const DualPolarizationType& o) const { return value <= o.value; }
    bool operator>=(const DualPolarizationType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct EarthModelType 
 *
 *  Enumeration used to represent EarthModelTypes
 */
struct EarthModelType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        WGS84 = 1
    };

    //! Default constructor
    EarthModelType(){ value = NOT_SET; }

    //! string constructor
    EarthModelType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "WGS84")
            value = WGS84;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    EarthModelType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = WGS84;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~EarthModelType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("WGS84");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    EarthModelType& operator=(const EarthModelType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const EarthModelType& o) const { return value == o.value; }
    bool operator!=(const EarthModelType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    EarthModelType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const EarthModelType& o) const { return value < o.value; }
    bool operator>(const EarthModelType& o) const { return value > o.value; }
    bool operator<=(const EarthModelType& o) const { return value <= o.value; }
    bool operator>=(const EarthModelType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct FFTSign 
 *
 *  Enumeration used to represent FFTSigns
 */
struct FFTSign
{
    //! The enumerations allowed
    enum
    {
        NEG = -1,
        NOT_SET = 0,
        POS = 1
    };

    //! Default constructor
    FFTSign(){ value = NOT_SET; }

    //! string constructor
    FFTSign(std::string s)
    {
        if (s == "NEG")
            value = NEG;
        else if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "POS")
            value = POS;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    FFTSign(int i)
    {
        switch(i)
        {
        case -1:
            value = NEG;
            break;
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = POS;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~FFTSign(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case -1:
            return std::string("NEG");
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("POS");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    FFTSign& operator=(const FFTSign& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const FFTSign& o) const { return value == o.value; }
    bool operator!=(const FFTSign& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    FFTSign& operator=(const int& o) { value = o; return *this; }
    bool operator<(const FFTSign& o) const { return value < o.value; }
    bool operator>(const FFTSign& o) const { return value > o.value; }
    bool operator<=(const FFTSign& o) const { return value <= o.value; }
    bool operator>=(const FFTSign& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct FrameType 
 *
 *  Enumeration used to represent FrameTypes
 */
struct FrameType
{
    //! The enumerations allowed
    enum
    {
        ECF = 0,
        RIC_ECF = 1,
        RIC_ECI = 2
    };

    //! Default constructor
    FrameType(){ value = ECF; }

    //! string constructor
    FrameType(std::string s)
    {
        if (s == "ECF")
            value = ECF;
        else if (s == "RIC_ECF")
            value = RIC_ECF;
        else if (s == "RIC_ECI")
            value = RIC_ECI;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    FrameType(int i)
    {
        switch(i)
        {
        case 0:
            value = ECF;
            break;
        case 1:
            value = RIC_ECF;
            break;
        case 2:
            value = RIC_ECI;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~FrameType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("ECF");
        case 1:
            return std::string("RIC_ECF");
        case 2:
            return std::string("RIC_ECI");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    FrameType& operator=(const FrameType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const FrameType& o) const { return value == o.value; }
    bool operator!=(const FrameType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    FrameType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const FrameType& o) const { return value < o.value; }
    bool operator>(const FrameType& o) const { return value > o.value; }
    bool operator<=(const FrameType& o) const { return value <= o.value; }
    bool operator>=(const FrameType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct ImageBeamCompensationType 
 *
 *  Enumeration used to represent ImageBeamCompensationTypes
 */
struct ImageBeamCompensationType
{
    //! The enumerations allowed
    enum
    {
        NO = 0,
        SV = 1
    };

    //! Default constructor
    ImageBeamCompensationType(){ value = NO; }

    //! string constructor
    ImageBeamCompensationType(std::string s)
    {
        if (s == "NO")
            value = NO;
        else if (s == "SV")
            value = SV;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    ImageBeamCompensationType(int i)
    {
        switch(i)
        {
        case 0:
            value = NO;
            break;
        case 1:
            value = SV;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~ImageBeamCompensationType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NO");
        case 1:
            return std::string("SV");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    ImageBeamCompensationType& operator=(const ImageBeamCompensationType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const ImageBeamCompensationType& o) const { return value == o.value; }
    bool operator!=(const ImageBeamCompensationType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    ImageBeamCompensationType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const ImageBeamCompensationType& o) const { return value < o.value; }
    bool operator>(const ImageBeamCompensationType& o) const { return value > o.value; }
    bool operator<=(const ImageBeamCompensationType& o) const { return value <= o.value; }
    bool operator>=(const ImageBeamCompensationType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct ImageFormationType 
 *
 *  Enumeration used to represent ImageFormationTypes
 */
struct ImageFormationType
{
    //! The enumerations allowed
    enum
    {
        OTHER = 0,
        PFA = 1,
        RMA = 2,
        RGAZCOMP = 3
    };

    //! Default constructor
    ImageFormationType(){ value = OTHER; }

    //! string constructor
    ImageFormationType(std::string s)
    {
        if (s == "OTHER")
            value = OTHER;
        else if (s == "PFA")
            value = PFA;
        else if (s == "RMA")
            value = RMA;
        else if (s == "RGAZCOMP")
            value = RGAZCOMP;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    ImageFormationType(int i)
    {
        switch(i)
        {
        case 0:
            value = OTHER;
            break;
        case 1:
            value = PFA;
            break;
        case 2:
            value = RMA;
            break;
        case 3:
            value = RGAZCOMP;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~ImageFormationType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("OTHER");
        case 1:
            return std::string("PFA");
        case 2:
            return std::string("RMA");
        case 3:
            return std::string("RGAZCOMP");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    ImageFormationType& operator=(const ImageFormationType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const ImageFormationType& o) const { return value == o.value; }
    bool operator!=(const ImageFormationType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    ImageFormationType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const ImageFormationType& o) const { return value < o.value; }
    bool operator>(const ImageFormationType& o) const { return value > o.value; }
    bool operator<=(const ImageFormationType& o) const { return value <= o.value; }
    bool operator>=(const ImageFormationType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct MagnificationMethod 
 *
 *  Enumeration used to represent MagnificationMethods
 */
struct MagnificationMethod
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        NEAREST_NEIGHBOR = 1,
        BILINEAR = 2
    };

    //! Default constructor
    MagnificationMethod(){ value = NOT_SET; }

    //! string constructor
    MagnificationMethod(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "NEAREST_NEIGHBOR")
            value = NEAREST_NEIGHBOR;
        else if (s == "BILINEAR")
            value = BILINEAR;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    MagnificationMethod(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = NEAREST_NEIGHBOR;
            break;
        case 2:
            value = BILINEAR;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~MagnificationMethod(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("NEAREST_NEIGHBOR");
        case 2:
            return std::string("BILINEAR");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    MagnificationMethod& operator=(const MagnificationMethod& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const MagnificationMethod& o) const { return value == o.value; }
    bool operator!=(const MagnificationMethod& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    MagnificationMethod& operator=(const int& o) { value = o; return *this; }
    bool operator<(const MagnificationMethod& o) const { return value < o.value; }
    bool operator>(const MagnificationMethod& o) const { return value > o.value; }
    bool operator<=(const MagnificationMethod& o) const { return value <= o.value; }
    bool operator>=(const MagnificationMethod& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct OrientationType 
 *
 *  Enumeration used to represent OrientationTypes
 */
struct OrientationType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4,
        ARBITRARY = 5
    };

    //! Default constructor
    OrientationType(){ value = NOT_SET; }

    //! string constructor
    OrientationType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "UP")
            value = UP;
        else if (s == "DOWN")
            value = DOWN;
        else if (s == "LEFT")
            value = LEFT;
        else if (s == "RIGHT")
            value = RIGHT;
        else if (s == "ARBITRARY")
            value = ARBITRARY;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    OrientationType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = UP;
            break;
        case 2:
            value = DOWN;
            break;
        case 3:
            value = LEFT;
            break;
        case 4:
            value = RIGHT;
            break;
        case 5:
            value = ARBITRARY;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~OrientationType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("UP");
        case 2:
            return std::string("DOWN");
        case 3:
            return std::string("LEFT");
        case 4:
            return std::string("RIGHT");
        case 5:
            return std::string("ARBITRARY");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    OrientationType& operator=(const OrientationType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const OrientationType& o) const { return value == o.value; }
    bool operator!=(const OrientationType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    OrientationType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const OrientationType& o) const { return value < o.value; }
    bool operator>(const OrientationType& o) const { return value > o.value; }
    bool operator<=(const OrientationType& o) const { return value <= o.value; }
    bool operator>=(const OrientationType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct PixelType 
 *
 *  Enumeration used to represent PixelTypes
 */
struct PixelType
{
    //! The enumerations allowed
    enum
    {
        UNDEFINED = 0,
        RE32F_IM32F = 1,
        RE16I_IM16I = 2,
        MONO8I = 3,
        MONO16I = 4,
        MONO8LU = 5,
        RGB8LU = 6,
        RGB24I = 7
    };

    //! Default constructor
    PixelType(){ value = UNDEFINED; }

    //! string constructor
    PixelType(std::string s)
    {
        if (s == "UNDEFINED")
            value = UNDEFINED;
        else if (s == "RE32F_IM32F")
            value = RE32F_IM32F;
        else if (s == "RE16I_IM16I")
            value = RE16I_IM16I;
        else if (s == "MONO8I")
            value = MONO8I;
        else if (s == "MONO16I")
            value = MONO16I;
        else if (s == "MONO8LU")
            value = MONO8LU;
        else if (s == "RGB8LU")
            value = RGB8LU;
        else if (s == "RGB24I")
            value = RGB24I;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    PixelType(int i)
    {
        switch(i)
        {
        case 0:
            value = UNDEFINED;
            break;
        case 1:
            value = RE32F_IM32F;
            break;
        case 2:
            value = RE16I_IM16I;
            break;
        case 3:
            value = MONO8I;
            break;
        case 4:
            value = MONO16I;
            break;
        case 5:
            value = MONO8LU;
            break;
        case 6:
            value = RGB8LU;
            break;
        case 7:
            value = RGB24I;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~PixelType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("UNDEFINED");
        case 1:
            return std::string("RE32F_IM32F");
        case 2:
            return std::string("RE16I_IM16I");
        case 3:
            return std::string("MONO8I");
        case 4:
            return std::string("MONO16I");
        case 5:
            return std::string("MONO8LU");
        case 6:
            return std::string("RGB8LU");
        case 7:
            return std::string("RGB24I");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    PixelType& operator=(const PixelType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const PixelType& o) const { return value == o.value; }
    bool operator!=(const PixelType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    PixelType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const PixelType& o) const { return value < o.value; }
    bool operator>(const PixelType& o) const { return value > o.value; }
    bool operator<=(const PixelType& o) const { return value <= o.value; }
    bool operator>=(const PixelType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct PolarizationType 
 *
 *  Enumeration used to represent PolarizationTypes
 */
struct PolarizationType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        OTHER = 1,
        V = 2,
        H = 3,
        RHC = 4,
        LHC = 5
    };

    //! Default constructor
    PolarizationType(){ value = NOT_SET; }

    //! string constructor
    PolarizationType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "OTHER")
            value = OTHER;
        else if (s == "V")
            value = V;
        else if (s == "H")
            value = H;
        else if (s == "RHC")
            value = RHC;
        else if (s == "LHC")
            value = LHC;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    PolarizationType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = OTHER;
            break;
        case 2:
            value = V;
            break;
        case 3:
            value = H;
            break;
        case 4:
            value = RHC;
            break;
        case 5:
            value = LHC;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~PolarizationType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("OTHER");
        case 2:
            return std::string("V");
        case 3:
            return std::string("H");
        case 4:
            return std::string("RHC");
        case 5:
            return std::string("LHC");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    PolarizationType& operator=(const PolarizationType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const PolarizationType& o) const { return value == o.value; }
    bool operator!=(const PolarizationType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    PolarizationType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const PolarizationType& o) const { return value < o.value; }
    bool operator>(const PolarizationType& o) const { return value > o.value; }
    bool operator<=(const PolarizationType& o) const { return value <= o.value; }
    bool operator>=(const PolarizationType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct ProjectionType 
 *
 *  Enumeration used to represent ProjectionTypes
 */
struct ProjectionType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        PLANE = 1,
        GEOGRAPHIC = 2,
        CYLINDRICAL = 3,
        POLYNOMIAL = 4
    };

    //! Default constructor
    ProjectionType(){ value = NOT_SET; }

    //! string constructor
    ProjectionType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "PLANE")
            value = PLANE;
        else if (s == "GEOGRAPHIC")
            value = GEOGRAPHIC;
        else if (s == "CYLINDRICAL")
            value = CYLINDRICAL;
        else if (s == "POLYNOMIAL")
            value = POLYNOMIAL;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    ProjectionType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = PLANE;
            break;
        case 2:
            value = GEOGRAPHIC;
            break;
        case 3:
            value = CYLINDRICAL;
            break;
        case 4:
            value = POLYNOMIAL;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~ProjectionType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("PLANE");
        case 2:
            return std::string("GEOGRAPHIC");
        case 3:
            return std::string("CYLINDRICAL");
        case 4:
            return std::string("POLYNOMIAL");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    ProjectionType& operator=(const ProjectionType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const ProjectionType& o) const { return value == o.value; }
    bool operator!=(const ProjectionType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    ProjectionType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const ProjectionType& o) const { return value < o.value; }
    bool operator>(const ProjectionType& o) const { return value > o.value; }
    bool operator<=(const ProjectionType& o) const { return value <= o.value; }
    bool operator>=(const ProjectionType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct RMAlgoType 
 *
 *  Enumeration used to represent RMAlgoTypes
 */
struct RMAlgoType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        OMEGA_K = 1,
        CSA = 2,
        RG_DOP = 3
    };

    //! Default constructor
    RMAlgoType(){ value = NOT_SET; }

    //! string constructor
    RMAlgoType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "OMEGA_K")
            value = OMEGA_K;
        else if (s == "CSA")
            value = CSA;
        else if (s == "RG_DOP")
            value = RG_DOP;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    RMAlgoType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = OMEGA_K;
            break;
        case 2:
            value = CSA;
            break;
        case 3:
            value = RG_DOP;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~RMAlgoType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("OMEGA_K");
        case 2:
            return std::string("CSA");
        case 3:
            return std::string("RG_DOP");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    RMAlgoType& operator=(const RMAlgoType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const RMAlgoType& o) const { return value == o.value; }
    bool operator!=(const RMAlgoType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    RMAlgoType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const RMAlgoType& o) const { return value < o.value; }
    bool operator>(const RMAlgoType& o) const { return value > o.value; }
    bool operator<=(const RMAlgoType& o) const { return value <= o.value; }
    bool operator>=(const RMAlgoType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct RadarModeType 
 *
 *  Enumeration used to represent RadarModeTypes
 */
struct RadarModeType
{
    //! The enumerations allowed
    enum
    {
        INVALID = 0,
        NOT_SET = 1,
        SPOTLIGHT = 2,
        STRIPMAP = 3,
        DYNAMIC_STRIPMAP = 4
    };

    //! Default constructor
    RadarModeType(){ value = INVALID; }

    //! string constructor
    RadarModeType(std::string s)
    {
        if (s == "INVALID")
            value = INVALID;
        else if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "SPOTLIGHT")
            value = SPOTLIGHT;
        else if (s == "STRIPMAP")
            value = STRIPMAP;
        else if (s == "DYNAMIC_STRIPMAP")
            value = DYNAMIC_STRIPMAP;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    RadarModeType(int i)
    {
        switch(i)
        {
        case 0:
            value = INVALID;
            break;
        case 1:
            value = NOT_SET;
            break;
        case 2:
            value = SPOTLIGHT;
            break;
        case 3:
            value = STRIPMAP;
            break;
        case 4:
            value = DYNAMIC_STRIPMAP;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~RadarModeType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("INVALID");
        case 1:
            return std::string("NOT_SET");
        case 2:
            return std::string("SPOTLIGHT");
        case 3:
            return std::string("STRIPMAP");
        case 4:
            return std::string("DYNAMIC_STRIPMAP");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    RadarModeType& operator=(const RadarModeType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const RadarModeType& o) const { return value == o.value; }
    bool operator!=(const RadarModeType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    RadarModeType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const RadarModeType& o) const { return value < o.value; }
    bool operator>(const RadarModeType& o) const { return value > o.value; }
    bool operator<=(const RadarModeType& o) const { return value <= o.value; }
    bool operator>=(const RadarModeType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct RegionType 
 *
 *  Enumeration used to represent RegionTypes
 */
struct RegionType
{
    //! The enumerations allowed
    enum
    {
        NOT_SET = 0,
        SUB_REGION = 1,
        GEOGRAPHIC_INFO = 2
    };

    //! Default constructor
    RegionType(){ value = NOT_SET; }

    //! string constructor
    RegionType(std::string s)
    {
        if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "SUB_REGION")
            value = SUB_REGION;
        else if (s == "GEOGRAPHIC_INFO")
            value = GEOGRAPHIC_INFO;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    RegionType(int i)
    {
        switch(i)
        {
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = SUB_REGION;
            break;
        case 2:
            value = GEOGRAPHIC_INFO;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~RegionType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("SUB_REGION");
        case 2:
            return std::string("GEOGRAPHIC_INFO");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    RegionType& operator=(const RegionType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const RegionType& o) const { return value == o.value; }
    bool operator!=(const RegionType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    RegionType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const RegionType& o) const { return value < o.value; }
    bool operator>(const RegionType& o) const { return value > o.value; }
    bool operator<=(const RegionType& o) const { return value <= o.value; }
    bool operator>=(const RegionType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct RowColEnum 
 *
 *  Enumeration used to represent RowColEnums
 */
struct RowColEnum
{
    //! The enumerations allowed
    enum
    {
        ROW = 0,
        COL = 1
    };

    //! Default constructor
    RowColEnum(){ value = ROW; }

    //! string constructor
    RowColEnum(std::string s)
    {
        if (s == "ROW")
            value = ROW;
        else if (s == "COL")
            value = COL;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    RowColEnum(int i)
    {
        switch(i)
        {
        case 0:
            value = ROW;
            break;
        case 1:
            value = COL;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~RowColEnum(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("ROW");
        case 1:
            return std::string("COL");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    RowColEnum& operator=(const RowColEnum& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const RowColEnum& o) const { return value == o.value; }
    bool operator!=(const RowColEnum& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    RowColEnum& operator=(const int& o) { value = o; return *this; }
    bool operator<(const RowColEnum& o) const { return value < o.value; }
    bool operator>(const RowColEnum& o) const { return value > o.value; }
    bool operator<=(const RowColEnum& o) const { return value <= o.value; }
    bool operator>=(const RowColEnum& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct SCPType 
 *
 *  Enumeration used to represent SCPTypes
 */
struct SCPType
{
    //! The enumerations allowed
    enum
    {
        SCP_ROW_COL = 0,
        SCP_RG_AZ = 1
    };

    //! Default constructor
    SCPType(){ value = SCP_ROW_COL; }

    //! string constructor
    SCPType(std::string s)
    {
        if (s == "SCP_ROW_COL")
            value = SCP_ROW_COL;
        else if (s == "SCP_RG_AZ")
            value = SCP_RG_AZ;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    SCPType(int i)
    {
        switch(i)
        {
        case 0:
            value = SCP_ROW_COL;
            break;
        case 1:
            value = SCP_RG_AZ;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~SCPType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("SCP_ROW_COL");
        case 1:
            return std::string("SCP_RG_AZ");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    SCPType& operator=(const SCPType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const SCPType& o) const { return value == o.value; }
    bool operator!=(const SCPType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    SCPType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const SCPType& o) const { return value < o.value; }
    bool operator>(const SCPType& o) const { return value > o.value; }
    bool operator<=(const SCPType& o) const { return value <= o.value; }
    bool operator>=(const SCPType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct SideOfTrackType 
 *
 *  Enumeration used to represent SideOfTrackTypes
 */
struct SideOfTrackType
{
    //! The enumerations allowed
    enum
    {
        LEFT = -1,
        NOT_SET = 0,
        RIGHT = 1
    };

    //! Default constructor
    SideOfTrackType(){ value = NOT_SET; }

    //! string constructor
    SideOfTrackType(std::string s)
    {
        if (s == "LEFT")
            value = LEFT;
        else if (s == "NOT_SET")
            value = NOT_SET;
        else if (s == "RIGHT")
            value = RIGHT;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    SideOfTrackType(int i)
    {
        switch(i)
        {
        case -1:
            value = LEFT;
            break;
        case 0:
            value = NOT_SET;
            break;
        case 1:
            value = RIGHT;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~SideOfTrackType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case -1:
            return std::string("LEFT");
        case 0:
            return std::string("NOT_SET");
        case 1:
            return std::string("RIGHT");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    SideOfTrackType& operator=(const SideOfTrackType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const SideOfTrackType& o) const { return value == o.value; }
    bool operator!=(const SideOfTrackType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    SideOfTrackType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const SideOfTrackType& o) const { return value < o.value; }
    bool operator>(const SideOfTrackType& o) const { return value > o.value; }
    bool operator<=(const SideOfTrackType& o) const { return value <= o.value; }
    bool operator>=(const SideOfTrackType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct SlowTimeBeamCompensationType 
 *
 *  Enumeration used to represent SlowTimeBeamCompensationTypes
 */
struct SlowTimeBeamCompensationType
{
    //! The enumerations allowed
    enum
    {
        NO = 0,
        GLOBAL = 1,
        SV = 2
    };

    //! Default constructor
    SlowTimeBeamCompensationType(){ value = NO; }

    //! string constructor
    SlowTimeBeamCompensationType(std::string s)
    {
        if (s == "NO")
            value = NO;
        else if (s == "GLOBAL")
            value = GLOBAL;
        else if (s == "SV")
            value = SV;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    SlowTimeBeamCompensationType(int i)
    {
        switch(i)
        {
        case 0:
            value = NO;
            break;
        case 1:
            value = GLOBAL;
            break;
        case 2:
            value = SV;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~SlowTimeBeamCompensationType(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("NO");
        case 1:
            return std::string("GLOBAL");
        case 2:
            return std::string("SV");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    SlowTimeBeamCompensationType& operator=(const SlowTimeBeamCompensationType& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const SlowTimeBeamCompensationType& o) const { return value == o.value; }
    bool operator!=(const SlowTimeBeamCompensationType& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    SlowTimeBeamCompensationType& operator=(const int& o) { value = o; return *this; }
    bool operator<(const SlowTimeBeamCompensationType& o) const { return value < o.value; }
    bool operator>(const SlowTimeBeamCompensationType& o) const { return value > o.value; }
    bool operator<=(const SlowTimeBeamCompensationType& o) const { return value <= o.value; }
    bool operator>=(const SlowTimeBeamCompensationType& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

/*!
 *  \struct XYZEnum 
 *
 *  Enumeration used to represent XYZEnums
 */
struct XYZEnum
{
    //! The enumerations allowed
    enum
    {
        X = 0,
        Y = 1,
        Z = 2
    };

    //! Default constructor
    XYZEnum(){ value = X; }

    //! string constructor
    XYZEnum(std::string s)
    {
        if (s == "X")
            value = X;
        else if (s == "Y")
            value = Y;
        else if (s == "Z")
            value = Z;
        else
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %s", s.c_str())));
    }

    //! int constructor
    XYZEnum(int i)
    {
        switch(i)
        {
        case 0:
            value = X;
            break;
        case 1:
            value = Y;
            break;
        case 2:
            value = Z;
            break;
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", i)));
        }
    }

    //! destructor
    ~XYZEnum(){}

    //! Returns string representation of the value
    std::string toString() const
    {
        switch(value)
        {
        case 0:
            return std::string("X");
        case 1:
            return std::string("Y");
        case 2:
            return std::string("Z");
        default:
            throw except::InvalidFormatException(Ctxt(FmtX("Invalid enum value: %d", value)));
        }
    }

    //! assignment operator
    XYZEnum& operator=(const XYZEnum& o)
    {
        if (&o != this)
        {
            value = o.value;
        }
        return *this;
    }

    bool operator==(const XYZEnum& o) const { return value == o.value; }
    bool operator!=(const XYZEnum& o) const { return value != o.value; }
    bool operator==(const int& o) const { return value == o; }
    bool operator!=(const int& o) const { return value != o; }
    XYZEnum& operator=(const int& o) { value = o; return *this; }
    bool operator<(const XYZEnum& o) const { return value < o.value; }
    bool operator>(const XYZEnum& o) const { return value > o.value; }
    bool operator<=(const XYZEnum& o) const { return value <= o.value; }
    bool operator>=(const XYZEnum& o) const { return value >= o.value; }
    operator int() const { return value; }

    int value;

};

// code auto-generated 2010-06-04 15:33:32.195605

}

#endif