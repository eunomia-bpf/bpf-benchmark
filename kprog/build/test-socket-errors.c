#include <linux/bpf.h>
#define SEC(S) __attribute__((section(S),used))
#if defined(DYNAMIC)
SEC("cgroup/connect4") int invalid_access(struct bpf_sock_addr *ctx, unsigned offset)
{ return ((volatile unsigned *)ctx)[offset]; }
#elif defined(OUTSIDE)
SEC("cgroup/connect4") int invalid_access(struct bpf_sock_addr *ctx)
{ return *(volatile unsigned *)((char *)ctx+4096); }
#elif defined(ESCAPE)
extern void consume(void *);
SEC("cgroup/connect4") int invalid_access(struct bpf_sock_addr *ctx)
{ consume(&ctx->user_ip4); return 0; }
#else
#error select the compiler regression case
#endif
