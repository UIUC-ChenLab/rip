/** \file MessageSizeType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:454
 */

#ifndef __MessageSizeType_HH__
#define __MessageSizeType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum MessageSizeType
 *  \brief ...
 */
enum MessageSizeType {
    MessageSizeType_FIRST,
    MessageSizeType_Control = MessageSizeType_FIRST, /**< Control Message */
    MessageSizeType_Data, /**< Data Message */
    MessageSizeType_Request_Control, /**< Request */
    MessageSizeType_Reissue_Control, /**< Reissued request */
    MessageSizeType_Response_Data, /**< data response */
    MessageSizeType_ResponseL2hit_Data, /**< data response */
    MessageSizeType_ResponseLocal_Data, /**< data response */
    MessageSizeType_Response_Control, /**< non-data response */
    MessageSizeType_Writeback_Data, /**< Writeback data */
    MessageSizeType_Writeback_Control, /**< Writeback control */
    MessageSizeType_Broadcast_Control, /**< Broadcast control */
    MessageSizeType_Multicast_Control, /**< Multicast control */
    MessageSizeType_Forwarded_Control, /**< Forwarded control */
    MessageSizeType_Invalidate_Control, /**< Invalidate control */
    MessageSizeType_Unblock_Control, /**< Unblock control */
    MessageSizeType_Persistent_Control, /**< Persistent request activation messages */
    MessageSizeType_Completion_Control, /**< Completion messages */
    MessageSizeType_NUM
};

// Code to convert from a string to the enumeration
MessageSizeType string_to_MessageSizeType(const std::string& str);

// Code to convert state to a string
std::string MessageSizeType_to_string(const MessageSizeType& obj);

// Code to increment an enumeration type
MessageSizeType &operator++(MessageSizeType &e);
std::ostream& operator<<(std::ostream& out, const MessageSizeType& obj);

#endif // __MessageSizeType_HH__
