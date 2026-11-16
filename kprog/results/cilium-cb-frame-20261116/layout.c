#ifdef KERNEL_VIEW
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern int printf(const char *, ...);
void native_clear(void *);
int main(void)
{
    struct sk_buff skb;
    __builtin_memset(&skb, 0xa5, sizeof(skb));
    native_clear(&skb);
    struct qdisc_skb_cb *q = (void *)skb.cb;
    unsigned int offset = __builtin_offsetof(struct sk_buff, cb) + __builtin_offsetof(struct qdisc_skb_cb, data);
    unsigned int classid = __builtin_offsetof(struct sk_buff, cb) + __builtin_offsetof(struct qdisc_skb_cb, tc_classid);
    for (unsigned long i = 0; i < sizeof(skb); i++) {
        unsigned char expected = (i >= offset && i < offset + 20) ||
            (i >= classid && i < classid + 2) ? 0 : 0xa5;
        if (((unsigned char *)&skb)[i] != expected)
            return printf("context write differs at byte %lu\n", i), 1;
    }
    printf("{\"cb_offset\":%u,\"tc_classid_offset\":%u,\"public_words\":5}\n", offset, classid);
}
#else
#include "linux/bpf.h"
void native_clear(void *pointer)
{
    struct __sk_buff *ctx = pointer;
    for (unsigned int i = 0; i < 5; i++)
        *(volatile __u32 *)&ctx->cb[i] = 0;
    *(volatile __u16 *)&ctx->tc_classid = 0;
}
#endif
