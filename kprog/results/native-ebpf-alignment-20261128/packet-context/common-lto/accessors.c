#include "../ifindex_witness.c"
__attribute__((noinline)) unsigned native_physical_upper(const struct xdp_md *ctx) {
 return (unsigned)((unsigned long)micro_native_xdp_data_end(ctx) >> 32);
}
__attribute__((noinline)) unsigned native_local_copy(const struct xdp_md *ctx) {
 volatile struct xdp_md local; local.ingress_ifindex=51; return local.ingress_ifindex;
}
