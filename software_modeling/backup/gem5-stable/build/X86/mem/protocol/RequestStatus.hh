/** \file RequestStatus.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __RequestStatus_HH__
#define __RequestStatus_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum RequestStatus
 *  \brief ...
 */
enum RequestStatus {
    RequestStatus_FIRST,
    RequestStatus_Ready = RequestStatus_FIRST, /**< The sequencer is ready and the request does not alias */
    RequestStatus_Issued, /**< The sequencer successfully issued the request */
    RequestStatus_BufferFull, /**< Can not issue because the sequencer is full */
    RequestStatus_Aliased, /**< This request aliased with a currently outstanding request */
    RequestStatus_NULL, /**<  */
    RequestStatus_NUM
};

// Code to convert from a string to the enumeration
RequestStatus string_to_RequestStatus(const std::string& str);

// Code to convert state to a string
std::string RequestStatus_to_string(const RequestStatus& obj);

// Code to increment an enumeration type
RequestStatus &operator++(RequestStatus &e);
std::ostream& operator<<(std::ostream& out, const RequestStatus& obj);

#endif // __RequestStatus_HH__
