/** \file MessageSizeType.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/Type.py:550
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/MessageSizeType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const MessageSizeType& obj)
{
    out << MessageSizeType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
MessageSizeType_to_string(const MessageSizeType& obj)
{
    switch(obj) {
      case MessageSizeType_Control:
        return "Control";
      case MessageSizeType_Data:
        return "Data";
      case MessageSizeType_Request_Control:
        return "Request_Control";
      case MessageSizeType_Reissue_Control:
        return "Reissue_Control";
      case MessageSizeType_Response_Data:
        return "Response_Data";
      case MessageSizeType_ResponseL2hit_Data:
        return "ResponseL2hit_Data";
      case MessageSizeType_ResponseLocal_Data:
        return "ResponseLocal_Data";
      case MessageSizeType_Response_Control:
        return "Response_Control";
      case MessageSizeType_Writeback_Data:
        return "Writeback_Data";
      case MessageSizeType_Writeback_Control:
        return "Writeback_Control";
      case MessageSizeType_Broadcast_Control:
        return "Broadcast_Control";
      case MessageSizeType_Multicast_Control:
        return "Multicast_Control";
      case MessageSizeType_Forwarded_Control:
        return "Forwarded_Control";
      case MessageSizeType_Invalidate_Control:
        return "Invalidate_Control";
      case MessageSizeType_Unblock_Control:
        return "Unblock_Control";
      case MessageSizeType_Persistent_Control:
        return "Persistent_Control";
      case MessageSizeType_Completion_Control:
        return "Completion_Control";
      default:
        panic("Invalid range for type MessageSizeType");
    }
}

// Code to convert from a string to the enumeration
MessageSizeType
string_to_MessageSizeType(const string& str)
{
    if (str == "Control") {
        return MessageSizeType_Control;
    } else if (str == "Data") {
        return MessageSizeType_Data;
    } else if (str == "Request_Control") {
        return MessageSizeType_Request_Control;
    } else if (str == "Reissue_Control") {
        return MessageSizeType_Reissue_Control;
    } else if (str == "Response_Data") {
        return MessageSizeType_Response_Data;
    } else if (str == "ResponseL2hit_Data") {
        return MessageSizeType_ResponseL2hit_Data;
    } else if (str == "ResponseLocal_Data") {
        return MessageSizeType_ResponseLocal_Data;
    } else if (str == "Response_Control") {
        return MessageSizeType_Response_Control;
    } else if (str == "Writeback_Data") {
        return MessageSizeType_Writeback_Data;
    } else if (str == "Writeback_Control") {
        return MessageSizeType_Writeback_Control;
    } else if (str == "Broadcast_Control") {
        return MessageSizeType_Broadcast_Control;
    } else if (str == "Multicast_Control") {
        return MessageSizeType_Multicast_Control;
    } else if (str == "Forwarded_Control") {
        return MessageSizeType_Forwarded_Control;
    } else if (str == "Invalidate_Control") {
        return MessageSizeType_Invalidate_Control;
    } else if (str == "Unblock_Control") {
        return MessageSizeType_Unblock_Control;
    } else if (str == "Persistent_Control") {
        return MessageSizeType_Persistent_Control;
    } else if (str == "Completion_Control") {
        return MessageSizeType_Completion_Control;
    } else {
        panic("Invalid string conversion for %s, type MessageSizeType", str);
    }
}

// Code to increment an enumeration type
MessageSizeType&
operator++(MessageSizeType& e)
{
    assert(e < MessageSizeType_NUM);
    return e = MessageSizeType(e+1);
}
