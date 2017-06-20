/** \file CacheRequestType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __CacheRequestType_HH__
#define __CacheRequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum CacheRequestType
 *  \brief ...
 */
enum CacheRequestType {
    CacheRequestType_FIRST,
    CacheRequestType_DataArrayRead = CacheRequestType_FIRST, /**< Read access to the cache's data array */
    CacheRequestType_DataArrayWrite, /**< Write access to the cache's data array */
    CacheRequestType_TagArrayRead, /**< Read access to the cache's tag array */
    CacheRequestType_TagArrayWrite, /**< Write access to the cache's tag array */
    CacheRequestType_NUM
};

// Code to convert from a string to the enumeration
CacheRequestType string_to_CacheRequestType(const std::string& str);

// Code to convert state to a string
std::string CacheRequestType_to_string(const CacheRequestType& obj);

// Code to increment an enumeration type
CacheRequestType &operator++(CacheRequestType &e);
std::ostream& operator<<(std::ostream& out, const CacheRequestType& obj);

#endif // __CacheRequestType_HH__
