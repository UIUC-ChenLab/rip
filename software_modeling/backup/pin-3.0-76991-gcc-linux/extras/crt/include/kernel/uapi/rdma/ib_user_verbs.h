/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef IB_USER_VERBS_H
#define IB_USER_VERBS_H
#include <linux/types.h>
#define IB_USER_VERBS_ABI_VERSION 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IB_USER_VERBS_CMD_THRESHOLD 50
enum {
 IB_USER_VERBS_CMD_GET_CONTEXT,
 IB_USER_VERBS_CMD_QUERY_DEVICE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_QUERY_PORT,
 IB_USER_VERBS_CMD_ALLOC_PD,
 IB_USER_VERBS_CMD_DEALLOC_PD,
 IB_USER_VERBS_CMD_CREATE_AH,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_MODIFY_AH,
 IB_USER_VERBS_CMD_QUERY_AH,
 IB_USER_VERBS_CMD_DESTROY_AH,
 IB_USER_VERBS_CMD_REG_MR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_REG_SMR,
 IB_USER_VERBS_CMD_REREG_MR,
 IB_USER_VERBS_CMD_QUERY_MR,
 IB_USER_VERBS_CMD_DEREG_MR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_ALLOC_MW,
 IB_USER_VERBS_CMD_BIND_MW,
 IB_USER_VERBS_CMD_DEALLOC_MW,
 IB_USER_VERBS_CMD_CREATE_COMP_CHANNEL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_CREATE_CQ,
 IB_USER_VERBS_CMD_RESIZE_CQ,
 IB_USER_VERBS_CMD_DESTROY_CQ,
 IB_USER_VERBS_CMD_POLL_CQ,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_PEEK_CQ,
 IB_USER_VERBS_CMD_REQ_NOTIFY_CQ,
 IB_USER_VERBS_CMD_CREATE_QP,
 IB_USER_VERBS_CMD_QUERY_QP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_MODIFY_QP,
 IB_USER_VERBS_CMD_DESTROY_QP,
 IB_USER_VERBS_CMD_POST_SEND,
 IB_USER_VERBS_CMD_POST_RECV,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_ATTACH_MCAST,
 IB_USER_VERBS_CMD_DETACH_MCAST,
 IB_USER_VERBS_CMD_CREATE_SRQ,
 IB_USER_VERBS_CMD_MODIFY_SRQ,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_QUERY_SRQ,
 IB_USER_VERBS_CMD_DESTROY_SRQ,
 IB_USER_VERBS_CMD_POST_SRQ_RECV,
 IB_USER_VERBS_CMD_OPEN_XRCD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IB_USER_VERBS_CMD_CLOSE_XRCD,
 IB_USER_VERBS_CMD_CREATE_XSRQ,
 IB_USER_VERBS_CMD_OPEN_QP,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
 IB_USER_VERBS_EX_CMD_CREATE_FLOW = IB_USER_VERBS_CMD_THRESHOLD,
 IB_USER_VERBS_EX_CMD_DESTROY_FLOW
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_async_event_desc {
 __u64 element;
 __u32 event_type;
 __u32 reserved;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_comp_event_desc {
 __u64 cq_handle;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IB_USER_VERBS_CMD_COMMAND_MASK 0xff
#define IB_USER_VERBS_CMD_FLAGS_MASK 0xff000000u
#define IB_USER_VERBS_CMD_FLAGS_SHIFT 24
#define IB_USER_VERBS_CMD_FLAG_EXTENDED 0x80
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_cmd_hdr {
 __u32 command;
 __u16 in_words;
 __u16 out_words;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_ex_cmd_hdr {
 __u64 response;
 __u16 provider_in_words;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 provider_out_words;
 __u32 cmd_hdr_reserved;
};
struct ib_uverbs_get_context {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u64 driver_data[0];
};
struct ib_uverbs_get_context_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 async_fd;
 __u32 num_comp_vectors;
};
struct ib_uverbs_query_device {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u64 driver_data[0];
};
struct ib_uverbs_query_device_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 fw_ver;
 __be64 node_guid;
 __be64 sys_image_guid;
 __u64 max_mr_size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 page_size_cap;
 __u32 vendor_id;
 __u32 vendor_part_id;
 __u32 hw_ver;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_qp;
 __u32 max_qp_wr;
 __u32 device_cap_flags;
 __u32 max_sge;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_sge_rd;
 __u32 max_cq;
 __u32 max_cqe;
 __u32 max_mr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_pd;
 __u32 max_qp_rd_atom;
 __u32 max_ee_rd_atom;
 __u32 max_res_rd_atom;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_qp_init_rd_atom;
 __u32 max_ee_init_rd_atom;
 __u32 atomic_cap;
 __u32 max_ee;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_rdd;
 __u32 max_mw;
 __u32 max_raw_ipv6_qp;
 __u32 max_raw_ethy_qp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_mcast_grp;
 __u32 max_mcast_qp_attach;
 __u32 max_total_mcast_qp_attach;
 __u32 max_ah;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_fmr;
 __u32 max_map_per_fmr;
 __u32 max_srq;
 __u32 max_srq_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_srq_sge;
 __u16 max_pkeys;
 __u8 local_ca_ack_delay;
 __u8 phys_port_cnt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 reserved[4];
};
struct ib_uverbs_query_port {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 port_num;
 __u8 reserved[7];
 __u64 driver_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_query_port_resp {
 __u32 port_cap_flags;
 __u32 max_msg_sz;
 __u32 bad_pkey_cntr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qkey_viol_cntr;
 __u32 gid_tbl_len;
 __u16 pkey_tbl_len;
 __u16 lid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 sm_lid;
 __u8 state;
 __u8 max_mtu;
 __u8 active_mtu;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 lmc;
 __u8 max_vl_num;
 __u8 sm_sl;
 __u8 subnet_timeout;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 init_type_reply;
 __u8 active_width;
 __u8 active_speed;
 __u8 phys_state;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 link_layer;
 __u8 reserved[2];
};
struct ib_uverbs_alloc_pd {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u64 driver_data[0];
};
struct ib_uverbs_alloc_pd_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pd_handle;
};
struct ib_uverbs_dealloc_pd {
 __u32 pd_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_open_xrcd {
 __u64 response;
 __u32 fd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 oflags;
 __u64 driver_data[0];
};
struct ib_uverbs_open_xrcd_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 xrcd_handle;
};
struct ib_uverbs_close_xrcd {
 __u32 xrcd_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_reg_mr {
 __u64 response;
 __u64 start;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 length;
 __u64 hca_va;
 __u32 pd_handle;
 __u32 access_flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 driver_data[0];
};
struct ib_uverbs_reg_mr_resp {
 __u32 mr_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 lkey;
 __u32 rkey;
};
struct ib_uverbs_dereg_mr {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 mr_handle;
};
struct ib_uverbs_alloc_mw {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pd_handle;
 __u8 mw_type;
 __u8 reserved[3];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_alloc_mw_resp {
 __u32 mw_handle;
 __u32 rkey;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_dealloc_mw {
 __u32 mw_handle;
};
struct ib_uverbs_create_comp_channel {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
};
struct ib_uverbs_create_comp_channel_resp {
 __u32 fd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_create_cq {
 __u64 response;
 __u64 user_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 cqe;
 __u32 comp_vector;
 __s32 comp_channel;
 __u32 reserved;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 driver_data[0];
};
struct ib_uverbs_create_cq_resp {
 __u32 cq_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 cqe;
};
struct ib_uverbs_resize_cq {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 cq_handle;
 __u32 cqe;
 __u64 driver_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_resize_cq_resp {
 __u32 cqe;
 __u32 reserved;
 __u64 driver_data[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_poll_cq {
 __u64 response;
 __u32 cq_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ne;
};
struct ib_uverbs_wc {
 __u64 wr_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 status;
 __u32 opcode;
 __u32 vendor_err;
 __u32 byte_len;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 union {
 __u32 imm_data;
 __u32 invalidate_rkey;
 } ex;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_num;
 __u32 src_qp;
 __u32 wc_flags;
 __u16 pkey_index;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 slid;
 __u8 sl;
 __u8 dlid_path_bits;
 __u8 port_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 reserved;
};
struct ib_uverbs_poll_cq_resp {
 __u32 count;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 reserved;
 struct ib_uverbs_wc wc[0];
};
struct ib_uverbs_req_notify_cq {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 cq_handle;
 __u32 solicited_only;
};
struct ib_uverbs_destroy_cq {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u32 cq_handle;
 __u32 reserved;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_destroy_cq_resp {
 __u32 comp_events_reported;
 __u32 async_events_reported;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_global_route {
 __u8 dgid[16];
 __u32 flow_label;
 __u8 sgid_index;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 hop_limit;
 __u8 traffic_class;
 __u8 reserved;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_ah_attr {
 struct ib_uverbs_global_route grh;
 __u16 dlid;
 __u8 sl;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 src_path_bits;
 __u8 static_rate;
 __u8 is_global;
 __u8 port_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 reserved;
};
struct ib_uverbs_qp_attr {
 __u32 qp_attr_mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_state;
 __u32 cur_qp_state;
 __u32 path_mtu;
 __u32 path_mig_state;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qkey;
 __u32 rq_psn;
 __u32 sq_psn;
 __u32 dest_qp_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_access_flags;
 struct ib_uverbs_ah_attr ah_attr;
 struct ib_uverbs_ah_attr alt_ah_attr;
 __u32 max_send_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_recv_wr;
 __u32 max_send_sge;
 __u32 max_recv_sge;
 __u32 max_inline_data;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 pkey_index;
 __u16 alt_pkey_index;
 __u8 en_sqd_async_notify;
 __u8 sq_draining;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 max_rd_atomic;
 __u8 max_dest_rd_atomic;
 __u8 min_rnr_timer;
 __u8 port_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 timeout;
 __u8 retry_cnt;
 __u8 rnr_retry;
 __u8 alt_port_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 alt_timeout;
 __u8 reserved[5];
};
struct ib_uverbs_create_qp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u64 user_handle;
 __u32 pd_handle;
 __u32 send_cq_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 recv_cq_handle;
 __u32 srq_handle;
 __u32 max_send_wr;
 __u32 max_recv_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_send_sge;
 __u32 max_recv_sge;
 __u32 max_inline_data;
 __u8 sq_sig_all;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 qp_type;
 __u8 is_srq;
 __u8 reserved;
 __u64 driver_data[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_open_qp {
 __u64 response;
 __u64 user_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pd_handle;
 __u32 qpn;
 __u8 qp_type;
 __u8 reserved[7];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 driver_data[0];
};
struct ib_uverbs_create_qp_resp {
 __u32 qp_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qpn;
 __u32 max_send_wr;
 __u32 max_recv_wr;
 __u32 max_send_sge;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_recv_sge;
 __u32 max_inline_data;
 __u32 reserved;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_qp_dest {
 __u8 dgid[16];
 __u32 flow_label;
 __u16 dlid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 reserved;
 __u8 sgid_index;
 __u8 hop_limit;
 __u8 traffic_class;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 sl;
 __u8 src_path_bits;
 __u8 static_rate;
 __u8 is_global;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 port_num;
};
struct ib_uverbs_query_qp {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_handle;
 __u32 attr_mask;
 __u64 driver_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_query_qp_resp {
 struct ib_uverbs_qp_dest dest;
 struct ib_uverbs_qp_dest alt_dest;
 __u32 max_send_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_recv_wr;
 __u32 max_send_sge;
 __u32 max_recv_sge;
 __u32 max_inline_data;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qkey;
 __u32 rq_psn;
 __u32 sq_psn;
 __u32 dest_qp_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_access_flags;
 __u16 pkey_index;
 __u16 alt_pkey_index;
 __u8 qp_state;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 cur_qp_state;
 __u8 path_mtu;
 __u8 path_mig_state;
 __u8 sq_draining;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 max_rd_atomic;
 __u8 max_dest_rd_atomic;
 __u8 min_rnr_timer;
 __u8 port_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 timeout;
 __u8 retry_cnt;
 __u8 rnr_retry;
 __u8 alt_port_num;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 alt_timeout;
 __u8 sq_sig_all;
 __u8 reserved[5];
 __u64 driver_data[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_modify_qp {
 struct ib_uverbs_qp_dest dest;
 struct ib_uverbs_qp_dest alt_dest;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_handle;
 __u32 attr_mask;
 __u32 qkey;
 __u32 rq_psn;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 sq_psn;
 __u32 dest_qp_num;
 __u32 qp_access_flags;
 __u16 pkey_index;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 alt_pkey_index;
 __u8 qp_state;
 __u8 cur_qp_state;
 __u8 path_mtu;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 path_mig_state;
 __u8 en_sqd_async_notify;
 __u8 max_rd_atomic;
 __u8 max_dest_rd_atomic;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 min_rnr_timer;
 __u8 port_num;
 __u8 timeout;
 __u8 retry_cnt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 rnr_retry;
 __u8 alt_port_num;
 __u8 alt_timeout;
 __u8 reserved[2];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 driver_data[0];
};
struct ib_uverbs_modify_qp_resp {
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_destroy_qp {
 __u64 response;
 __u32 qp_handle;
 __u32 reserved;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_destroy_qp_resp {
 __u32 events_reported;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_sge {
 __u64 addr;
 __u32 length;
 __u32 lkey;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_send_wr {
 __u64 wr_id;
 __u32 num_sge;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 opcode;
 __u32 send_flags;
 union {
 __u32 imm_data;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 invalidate_rkey;
 } ex;
 union {
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 remote_addr;
 __u32 rkey;
 __u32 reserved;
 } rdma;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct {
 __u64 remote_addr;
 __u64 compare_add;
 __u64 swap;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 rkey;
 __u32 reserved;
 } atomic;
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ah;
 __u32 remote_qpn;
 __u32 remote_qkey;
 __u32 reserved;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 } ud;
 } wr;
};
struct ib_uverbs_post_send {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u32 qp_handle;
 __u32 wr_count;
 __u32 sge_count;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 wqe_size;
 struct ib_uverbs_send_wr send_wr[0];
};
struct ib_uverbs_post_send_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 bad_wr;
};
struct ib_uverbs_recv_wr {
 __u64 wr_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 num_sge;
 __u32 reserved;
};
struct ib_uverbs_post_recv {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u32 qp_handle;
 __u32 wr_count;
 __u32 sge_count;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 wqe_size;
 struct ib_uverbs_recv_wr recv_wr[0];
};
struct ib_uverbs_post_recv_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 bad_wr;
};
struct ib_uverbs_post_srq_recv {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 srq_handle;
 __u32 wr_count;
 __u32 sge_count;
 __u32 wqe_size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct ib_uverbs_recv_wr recv[0];
};
struct ib_uverbs_post_srq_recv_resp {
 __u32 bad_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_create_ah {
 __u64 response;
 __u64 user_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pd_handle;
 __u32 reserved;
 struct ib_uverbs_ah_attr attr;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_create_ah_resp {
 __u32 ah_handle;
};
struct ib_uverbs_destroy_ah {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ah_handle;
};
struct ib_uverbs_attach_mcast {
 __u8 gid[16];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_handle;
 __u16 mlid;
 __u16 reserved;
 __u64 driver_data[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_detach_mcast {
 __u8 gid[16];
 __u32 qp_handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 mlid;
 __u16 reserved;
 __u64 driver_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_spec_hdr {
 __u32 type;
 __u16 size;
 __u16 reserved;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 flow_spec_data[0];
};
struct ib_uverbs_flow_eth_filter {
 __u8 dst_mac[6];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 src_mac[6];
 __be16 ether_type;
 __be16 vlan_tag;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_spec_eth {
 union {
 struct ib_uverbs_flow_spec_hdr hdr;
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 type;
 __u16 size;
 __u16 reserved;
 };
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 };
 struct ib_uverbs_flow_eth_filter val;
 struct ib_uverbs_flow_eth_filter mask;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_ipv4_filter {
 __be32 src_ip;
 __be32 dst_ip;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_spec_ipv4 {
 union {
 struct ib_uverbs_flow_spec_hdr hdr;
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 type;
 __u16 size;
 __u16 reserved;
 };
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 };
 struct ib_uverbs_flow_ipv4_filter val;
 struct ib_uverbs_flow_ipv4_filter mask;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_tcp_udp_filter {
 __be16 dst_port;
 __be16 src_port;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_spec_tcp_udp {
 union {
 struct ib_uverbs_flow_spec_hdr hdr;
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 type;
 __u16 size;
 __u16 reserved;
 };
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 };
 struct ib_uverbs_flow_tcp_udp_filter val;
 struct ib_uverbs_flow_tcp_udp_filter mask;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_flow_attr {
 __u32 type;
 __u16 size;
 __u16 priority;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 num_of_specs;
 __u8 reserved[2];
 __u8 port;
 __u32 flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct ib_uverbs_flow_spec_hdr flow_specs[0];
};
struct ib_uverbs_create_flow {
 __u32 comp_mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 qp_handle;
 struct ib_uverbs_flow_attr flow_attr;
};
struct ib_uverbs_create_flow_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 comp_mask;
 __u32 flow_handle;
};
struct ib_uverbs_destroy_flow {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 comp_mask;
 __u32 flow_handle;
};
struct ib_uverbs_create_srq {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 response;
 __u64 user_handle;
 __u32 pd_handle;
 __u32 max_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_sge;
 __u32 srq_limit;
 __u64 driver_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_create_xsrq {
 __u64 response;
 __u64 user_handle;
 __u32 srq_type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pd_handle;
 __u32 max_wr;
 __u32 max_sge;
 __u32 srq_limit;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 reserved;
 __u32 xrcd_handle;
 __u32 cq_handle;
 __u64 driver_data[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ib_uverbs_create_srq_resp {
 __u32 srq_handle;
 __u32 max_wr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 max_sge;
 __u32 srqn;
};
struct ib_uverbs_modify_srq {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 srq_handle;
 __u32 attr_mask;
 __u32 max_wr;
 __u32 srq_limit;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 driver_data[0];
};
struct ib_uverbs_query_srq {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 srq_handle;
 __u32 reserved;
 __u64 driver_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ib_uverbs_query_srq_resp {
 __u32 max_wr;
 __u32 max_sge;
 __u32 srq_limit;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 reserved;
};
struct ib_uverbs_destroy_srq {
 __u64 response;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 srq_handle;
 __u32 reserved;
};
struct ib_uverbs_destroy_srq_resp {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 events_reported;
};
#endif
