#include <linux/bpf.h>
#define SEC(s) __attribute__((section(s),used))
#define PREDICATE(name,expression) SEC("xdp") int name(struct xdp_md *ctx) { \
    long size=(long)ctx->data_end-(long)ctx->data; return (expression); }
PREDICATE(less,size<64)
PREDICATE(at_most,size<=64)
PREDICATE(at_least,size>=64)
PREDICATE(more,size>64)
PREDICATE(unsigned_less,(unsigned long)size<64)
PREDICATE(unsigned_more,(unsigned long)size>64)
// Scalar arithmetic with similar field positions must remain ordinary code.
SEC("ordinary") int scalar(struct xdp_md *ctx) { return (long)ctx->data_end-(long)ctx->data<64; }
