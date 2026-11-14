/* The same fixed UAPI layout is checked by GCC and CompCert's C frontend.
 * All named fields, array widths, structure sizes and alignment participate. */
#include <stddef.h>
#if defined(__COMPCERT__)
#include "../../arm64/arm64_sim_local_bpf.h"
#define bpf_cast_to_kern_ctx kprog_x86_host_cast_to_kern_ctx
#include "../../x86/x86_sim_local_bpf.h"
#undef bpf_cast_to_kern_ctx
/* Export roots catch a CompCert branch accidentally using the host's zero
 * fixture instead of the same free kind6 entry input as production BPF. */
_Static_assert(!__builtin_constant_p(X86_SIM_L_UNSPECIFIED()), "x86 undefined input must remain free");
_Static_assert(!__builtin_constant_p(ARM64_SIM_L_UNSPECIFIED()), "ARM undefined input must remain free");
unsigned long long test_x86_unspecified_input(void) { return X86_SIM_L_UNSPECIFIED(); }
unsigned long long test_arm64_unspecified_input(void) { return ARM64_SIM_L_UNSPECIFIED(); }
#else
#include <linux/bpf.h>
#endif
#define ABI_STRUCT(TYPE, SIZE, ALIGN) \
  _Static_assert(sizeof(struct TYPE) == (SIZE), #TYPE " size"); \
  _Static_assert(_Alignof(struct TYPE) == (ALIGN), #TYPE " alignment")
#define ABI_FIELD(TYPE, FIELD, OFFSET, SIZE) \
  _Static_assert(offsetof(struct TYPE, FIELD) == (OFFSET), #TYPE "." #FIELD " offset"); \
  _Static_assert(sizeof(((struct TYPE *)0)->FIELD) == (SIZE), #TYPE "." #FIELD " size")
_Static_assert(sizeof(void *) == 8, "64-bit BPF context ABI");
ABI_STRUCT(__sk_buff, 192, 8);
ABI_FIELD(__sk_buff, len, 0, 4);
ABI_FIELD(__sk_buff, pkt_type, 4, 4);
ABI_FIELD(__sk_buff, mark, 8, 4);
ABI_FIELD(__sk_buff, queue_mapping, 12, 4);
ABI_FIELD(__sk_buff, protocol, 16, 4);
ABI_FIELD(__sk_buff, vlan_present, 20, 4);
ABI_FIELD(__sk_buff, vlan_tci, 24, 4);
ABI_FIELD(__sk_buff, vlan_proto, 28, 4);
ABI_FIELD(__sk_buff, priority, 32, 4);
ABI_FIELD(__sk_buff, ingress_ifindex, 36, 4);
ABI_FIELD(__sk_buff, ifindex, 40, 4);
ABI_FIELD(__sk_buff, tc_index, 44, 4);
ABI_FIELD(__sk_buff, cb, 48, 20);
ABI_FIELD(__sk_buff, hash, 68, 4);
ABI_FIELD(__sk_buff, tc_classid, 72, 4);
ABI_FIELD(__sk_buff, data, 76, 4);
ABI_FIELD(__sk_buff, data_end, 80, 4);
ABI_FIELD(__sk_buff, napi_id, 84, 4);
ABI_FIELD(__sk_buff, family, 88, 4);
ABI_FIELD(__sk_buff, remote_ip4, 92, 4);
ABI_FIELD(__sk_buff, local_ip4, 96, 4);
ABI_FIELD(__sk_buff, remote_ip6, 100, 16);
ABI_FIELD(__sk_buff, local_ip6, 116, 16);
ABI_FIELD(__sk_buff, remote_port, 132, 4);
ABI_FIELD(__sk_buff, local_port, 136, 4);
ABI_FIELD(__sk_buff, data_meta, 140, 4);
ABI_FIELD(__sk_buff, flow_keys, 144, 8);
ABI_FIELD(__sk_buff, tstamp, 152, 8);
ABI_FIELD(__sk_buff, wire_len, 160, 4);
ABI_FIELD(__sk_buff, gso_segs, 164, 4);
ABI_FIELD(__sk_buff, sk, 168, 8);
ABI_FIELD(__sk_buff, gso_size, 176, 4);
ABI_FIELD(__sk_buff, tstamp_type, 180, 1);
ABI_FIELD(__sk_buff, hwtstamp, 184, 8);
ABI_STRUCT(xdp_md, 24, 4);
ABI_FIELD(xdp_md, data, 0, 4);
ABI_FIELD(xdp_md, data_end, 4, 4);
ABI_FIELD(xdp_md, data_meta, 8, 4);
ABI_FIELD(xdp_md, ingress_ifindex, 12, 4);
ABI_FIELD(xdp_md, rx_queue_index, 16, 4);
ABI_FIELD(xdp_md, egress_ifindex, 20, 4);
ABI_STRUCT(bpf_dynptr, 16, 8);
ABI_FIELD(bpf_dynptr, __opaque, 0, 16);
#undef ABI_STRUCT
#undef ABI_FIELD
int main(void) { return 0; }
