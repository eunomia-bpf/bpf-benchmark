// Rules from the only kernel's TC/XDP convert_ctx_access implementations.
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern int printf(const char *,...);
#define OFF(T,F) __builtin_offsetof(struct T,F)
#define WIDTH(T,F) sizeof(((struct T *)0)->F)
static int first=1;
static void field(const char *kind,const char *name,long pointer,long pointer2,unsigned long offset,unsigned long width,int is_pointer)
{
    printf("%s{\"kind\":\"%s\",\"field\":\"%s\",\"child\":\"\",\"pointers\":[",first?"":",",kind,name);
    if (pointer>=0) printf("%ld",pointer);
    if (pointer2>=0) printf(",%ld",pointer2);
    printf("],\"offset\":%lu,\"width\":%lu,\"pointer_value\":%s}",offset,width,is_pointer?"true":"false");
    first=0;
}
#define SKB(F,M) field("skb",#F,-1,-1,OFF(sk_buff,M),WIDTH(sk_buff,M),0)
#define QDISC(F,M) field("skb",#F,-1,-1,OFF(sk_buff,cb)+OFF(qdisc_skb_cb,M),WIDTH(qdisc_skb_cb,M),0)
#define SKBPTR(F,M) field("skb",#F,-1,-1,OFF(sk_buff,cb)+OFF(bpf_skb_data_end,M),WIDTH(bpf_skb_data_end,M),1)
#define XDP(F,M) field("xdp",#F,-1,-1,OFF(xdp_buff,M),WIDTH(xdp_buff,M),1)
int main(void)
{
    printf("[");
    SKB(len,len); SKB(protocol,protocol); SKB(priority,priority); SKB(ingress_ifindex,skb_iif);
    SKB(hash,hash); SKB(mark,mark); SKB(tc_index,tc_index);
    SKB(vlan_tci,vlan_tci); SKB(vlan_proto,vlan_proto);
    // Conversion normalizes vlan_all to boolean and masks pkt_type's bitfield.
    printf(",{\"kind\":\"skb\",\"field\":\"vlan_present\",\"child\":\"\",\"pointers\":[],\"offset\":%lu,\"width\":4,\"boolean\":true}",OFF(sk_buff,vlan_all));
    printf(",{\"kind\":\"skb\",\"field\":\"pkt_type\",\"child\":\"\",\"pointers\":[],\"offset\":%lu,\"width\":1,\"mask\":7}",OFF(sk_buff,__pkt_type_offset));
    printf(",{\"kind\":\"skb\",\"field\":\"queue_mapping\",\"child\":\"\",\"pointers\":[],\"offset\":%lu,\"width\":2,\"store_max_exclusive\":65535}",OFF(sk_buff,queue_mapping));
    field("skb","ifindex",OFF(sk_buff,dev),-1,OFF(net_device,ifindex),WIDTH(net_device,ifindex),0);
    QDISC(cb,data); QDISC(tc_classid,tc_classid); QDISC(wire_len,pkt_len);
    field("skb","data",-1,-1,OFF(sk_buff,data),WIDTH(sk_buff,data),1);
    SKBPTR(data_end,data_end); SKBPTR(data_meta,data_meta);
    XDP(data,data); XDP(data_end,data_end); XDP(data_meta,data_meta);
    field("xdp","ingress_ifindex",OFF(xdp_buff,rxq),OFF(xdp_rxq_info,dev),OFF(net_device,ifindex),WIDTH(net_device,ifindex),0);
    field("xdp","rx_queue_index",OFF(xdp_buff,rxq),-1,OFF(xdp_rxq_info,queue_index),WIDTH(xdp_rxq_info,queue_index),0);
    field("xdp","egress_ifindex",OFF(xdp_buff,txq),OFF(xdp_txq_info,dev),OFF(net_device,ifindex),WIDTH(net_device,ifindex),0);
    printf("]\n");
}
