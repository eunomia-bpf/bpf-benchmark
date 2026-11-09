#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
extern __u64 bpf_arm64_native_lab_atomic16(__u16 *word, __u64 value, __u32 operation, __u32 order) __ksym;
#define UNIT(NAME, OP, ORDER, AFTER) SEC("xdp") int NAME(struct xdp_md *ctx) { \
    struct { __u16 left,word,right; } data={0xaaaa,0x1234,0xbbbb}; \
    __u64 old=bpf_arm64_native_lab_atomic16(&data.word,0x1111,OP,ORDER); \
    return old==0x1234 && data.word==AFTER && data.left==0xaaaa && data.right==0xbbbb ? 2 : 0; }
UNIT(narrow_add,0,__ATOMIC_ACQ_REL,0x2345)
UNIT(narrow_set,1,__ATOMIC_ACQUIRE,0x1335)
UNIT(narrow_clr,2,__ATOMIC_RELEASE,0x1010)
char LICENSE[] SEC("license")="GPL";
