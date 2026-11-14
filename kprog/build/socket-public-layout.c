// Read the unmodified upstream UAPI declarations used by Cilium's source.
#include <linux/bpf.h>
#include <stddef.h>
#include <stdio.h>
#define FIELD(T, F) printf("\"" #F "\":{\"offset\":%zu,\"width\":%zu}", offsetof(struct T,F),sizeof(((struct T *)0)->F))
int main(void)
{
    printf("{\"sock_addr\":{");
    FIELD(bpf_sock_addr,user_family); printf(","); FIELD(bpf_sock_addr,user_ip4); printf(",");
    FIELD(bpf_sock_addr,user_ip6); printf(","); FIELD(bpf_sock_addr,user_port); printf(",");
    FIELD(bpf_sock_addr,family); printf(","); FIELD(bpf_sock_addr,type); printf(",");
    FIELD(bpf_sock_addr,protocol); printf(","); FIELD(bpf_sock_addr,msg_src_ip4); printf(",");
    FIELD(bpf_sock_addr,msg_src_ip6); printf(","); FIELD(bpf_sock_addr,sk);
    printf("},\"sock\":{");
    FIELD(bpf_sock,bound_dev_if); printf(","); FIELD(bpf_sock,family); printf(",");
    FIELD(bpf_sock,type); printf(","); FIELD(bpf_sock,protocol); printf(",");
    FIELD(bpf_sock,mark); printf(","); FIELD(bpf_sock,priority); printf(",");
    FIELD(bpf_sock,src_ip4); printf(","); FIELD(bpf_sock,src_ip6); printf(",");
    FIELD(bpf_sock,src_port); printf(","); FIELD(bpf_sock,dst_port); printf(",");
    FIELD(bpf_sock,dst_ip4); printf(","); FIELD(bpf_sock,dst_ip6); printf(",");
    FIELD(bpf_sock,state); printf("}}\n");
}
