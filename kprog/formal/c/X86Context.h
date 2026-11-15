/* Production context read bodies; caller supplies the actual entry bindings. */
#ifndef KPROG_X86_CONTEXT_BINDING_H
#define KPROG_X86_CONTEXT_BINDING_H
#include "X86Pointer.h"
__u64 kprog_x86_skb_read(struct x86_sim_register_state *, __u64, __s64, __u64);
__u64 kprog_x86_xdp_read(struct x86_sim_register_state *, const void *, __s64, __u64);
__u64 kprog_x86_cb_read(const void *, __s64, __u64);
__u8 kprog_x86_context_tag(__u64, __s64);
#endif
