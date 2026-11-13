// Physical layout from the only kernel's generated BTF header. Rules mirror
// sock_addr_convert_ctx_access/bpf_sock_convert_ctx_access in net/core/filter.c.
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern int printf(const char *, ...);
#define OFF(T,F) __builtin_offsetof(struct T,F)
#define WIDTH(T,F) sizeof(((struct T *)0)->F)
static int first = 1;
static void field(const char *kind, const char *name, long pointer, unsigned long offset, unsigned long width, const char *child)
{
    printf("%s{\"kind\":\"%s\",\"field\":\"%s\",\"pointers\":[", first ? "" : ",",kind,name);
    if (pointer >= 0) printf("%ld",pointer);
    printf("],\"offset\":%lu,\"width\":%lu,\"child\":\"%s\"}",offset,width,child);
    first = 0;
}
#define ADDR(F,P,T,M) field("sock_addr",#F,OFF(bpf_sock_addr_kern,P),OFF(T,M),WIDTH(T,M),"")
#define SOCK(F,T,M) field("sock",#F,-1,OFF(T,M),WIDTH(T,M),"")
int main(void)
{
    printf("[");
    ADDR(user_family,uaddr,sockaddr,sa_family);
    ADDR(user_ip4,uaddr,sockaddr_in,sin_addr);
    ADDR(user_ip6,uaddr,sockaddr_in6,sin6_addr);
    ADDR(user_port,uaddr,sockaddr_in6,sin6_port);
    ADDR(family,sk,sock,__sk_common.skc_family);
    ADDR(type,sk,sock,sk_type);
    ADDR(protocol,sk,sock,sk_protocol);
    ADDR(msg_src_ip4,t_ctx,in_addr,s_addr);
    ADDR(msg_src_ip6,t_ctx,in6_addr,in6_u.u6_addr32);
    field("sock_addr","sk",-1,OFF(bpf_sock_addr_kern,sk),WIDTH(bpf_sock_addr_kern,sk),"sock");
    SOCK(bound_dev_if,sock,__sk_common.skc_bound_dev_if);
    SOCK(family,sock,__sk_common.skc_family); SOCK(type,sock,sk_type); SOCK(protocol,sock,sk_protocol);
    SOCK(mark,sock,sk_mark); SOCK(priority,sock,sk_priority);
    SOCK(src_ip4,sock_common,skc_rcv_saddr); SOCK(dst_ip4,sock_common,skc_daddr);
    SOCK(src_ip6,sock_common,skc_v6_rcv_saddr); SOCK(dst_ip6,sock_common,skc_v6_daddr);
    SOCK(src_port,sock_common,skc_num); SOCK(dst_port,sock_common,skc_dport);
    SOCK(state,sock_common,skc_state);
    printf("]\n");
}
