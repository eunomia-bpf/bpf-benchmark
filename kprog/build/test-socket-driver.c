// Observe physical socket storage from the only kernel's generated BTF header.
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern int socket4(void *), socket6(void *), socket_direct(void *);
extern void socket_store_only(void *);
extern int printf(const char *,...);
static void *expected_context;
unsigned long observe_context(void *ctx) { return ctx==expected_context?63:0; }
int main(void)
{
    struct sock sk={};
    struct sockaddr_in addr4={};
    struct sockaddr_in6 addr6={};
    struct in6_addr message={};
    struct { struct bpf_sock_addr_kern ctx; unsigned char padding[128]; } frame={};
    frame.ctx.sk=&sk; frame.ctx.uaddr=(void *)&addr4; frame.ctx.t_ctx=&message;
    sk.__sk_common.skc_family=2; sk.sk_type=1; sk.sk_protocol=6; sk.__sk_common.skc_num=1234;
    addr4.sin_family=2; addr4.sin_port=0x3412; addr4.sin_addr.s_addr=0x04030201;
    expected_context=&frame.ctx;
    int v4=socket4(&frame.ctx);
    if (v4 || addr4.sin_port!=0xbeef || addr4.sin_family!=2 || addr4.sin_addr.s_addr!=0x08070605 ||
        message.in6_u.u6_addr32[0]!=0x12345678) { printf("IPv4 failure %d\n",v4); return 1; }
    socket_store_only(&frame.ctx);
    if (addr4.sin_addr.s_addr!=0x55555555) return 4;
    frame.ctx.uaddr=(void *)&addr6; sk.__sk_common.skc_family=10; sk.sk_protocol=17;
    addr6.sin6_family=10; addr6.sin6_addr.in6_u.u6_addr32[0]=0x11111111;
    addr6.sin6_addr.in6_u.u6_addr32[3]=0x44444444;
    if (socket6(&frame.ctx) || addr6.sin6_addr.in6_u.u6_addr32[1]!=0x12345678 ||
        message.in6_u.u6_addr32[3]!=0x87654321) return 2;
    sk.__sk_common.skc_family=2; sk.sk_protocol=6; sk.__sk_common.skc_dport=0x3412; sk.__sk_common.skc_state=7;
    expected_context=&sk;
    if (socket_direct(&sk) || sk.__sk_common.skc_bound_dev_if!=47 || sk.sk_mark!=53 || sk.sk_priority!=59) return 3;
    printf("IPv4/IPv6 nested ctx, port truncation, helper ctx and direct sock PASS\n");
    return 0;
}
