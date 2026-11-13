// Public field extents remain the unmodified upstream UAPI definitions.
#include <linux/bpf.h>
#include <stddef.h>
#include <stdio.h>
#define FIELD(T,F) printf("\"" #F "\":{\"offset\":%zu,\"width\":%zu}",offsetof(struct T,F),sizeof(((struct T *)0)->F))
int main(void)
{
    printf("{\"skb\":{");
    FIELD(__sk_buff,len); printf(","); FIELD(__sk_buff,protocol); printf(",");
    FIELD(__sk_buff,vlan_present); printf(","); FIELD(__sk_buff,vlan_tci); printf(",");
    FIELD(__sk_buff,vlan_proto); printf(","); FIELD(__sk_buff,pkt_type); printf(",");
    FIELD(__sk_buff,queue_mapping); printf(",");
    FIELD(__sk_buff,priority); printf(","); FIELD(__sk_buff,ingress_ifindex); printf(",");
    FIELD(__sk_buff,ifindex); printf(","); FIELD(__sk_buff,hash); printf(",");
    FIELD(__sk_buff,mark); printf(","); FIELD(__sk_buff,tc_index); printf(","); FIELD(__sk_buff,cb); printf(",");
    FIELD(__sk_buff,tc_classid); printf(","); FIELD(__sk_buff,wire_len); printf(",");
    FIELD(__sk_buff,data); printf(","); FIELD(__sk_buff,data_end); printf(",");
    FIELD(__sk_buff,data_meta);
    printf("},\"xdp\":{");
    FIELD(xdp_md,data); printf(","); FIELD(xdp_md,data_end); printf(",");
    FIELD(xdp_md,data_meta); printf(","); FIELD(xdp_md,ingress_ifindex); printf(",");
    FIELD(xdp_md,rx_queue_index); printf(","); FIELD(xdp_md,egress_ifindex);
    printf("}}\n");
}
