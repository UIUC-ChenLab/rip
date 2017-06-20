#ifndef HELP_FUN_H
#define HELP_FUN_H

//#include "systemc.h"
#include "string.h"
/*
#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"

using namespace sc_core;
using namespace sc_dt;
using namespace std;
*/
//hamming distance
template <typename T1> unsigned int hamming(T1 a, T1 b){
  int results = a ^ b;
  return __builtin_popcount(results);
}

//template <typename T> void communication(tlm::tlm_generic_payload* trans, tlm::tlm_command cmd, int main_addr, int* local_addr, 
//  tlm_utils::simple_initiator_socket<T> &socket, sc_time delay, string local_array){
//  trans->set_command(cmd);
//  trans->set_address(main_addr*4);
//  trans->set_data_ptr(reinterpret_cast<unsigned char*>(local_addr));
//  trans->set_data_length(4);
//  trans->set_streaming_width(4);
//  trans->set_byte_enable_ptr(0);
//  trans->set_dmi_allowed(false);
//  trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
//  socket->b_transport(*trans, delay);
//  if(trans->is_response_error())
//    SC_REPORT_ERROR("TLM2", trans->get_response_string().c_str());
//  cout << (cmd ? "write " : "read ") << "local array name: " << local_array << "; data = " << *(local_addr) << "@time" << sc_time_stamp() << endl;
//}
//
#endif
