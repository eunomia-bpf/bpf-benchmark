#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern int packet_tc(void *),packet_xdp(void *),printf(const char *,...);
extern void packet_queue(void *,unsigned);
#ifdef BPF_POINTER_ASM
extern unsigned long packet_xdp_length(void *);
extern int packet_xdp_bounds(void *,unsigned long,unsigned long,unsigned long *);
extern int packet_xdp_two(void *,unsigned long,unsigned long *);
#endif
static void *expected;
unsigned long observe_context(void *ctx) { return ctx==expected?63:0; }
int main(void)
{
    struct sk_buff skb={};
    struct net_device dev={},outdev={};
    unsigned char buffer[160]={};
    struct bpf_skb_data_end *cb=(void *)skb.cb;
    cb->qdisc_cb.pkt_len=976; cb->qdisc_cb.tc_classid=0xa1a2;
    unsigned *metadata=(void *)cb->qdisc_cb.data;
    metadata[0]=101; metadata[4]=105;
    skb.data=buffer+16; skb.len=128; skb.skb_iif=41; skb.protocol=0x1234; skb.queue_mapping=42;
    dev.ifindex=37; outdev.ifindex=47; skb.dev=&dev;
    skb.vlan_all=0x56781234; skb.pkt_type=5;
    cb->data_meta=buffer; cb->data_end=buffer+144;
    buffer[16+73]=0xb7; expected=&skb;
    int tc=packet_tc(&skb);
    if (tc!=28) { printf("TC mismatch %d\n",tc); return 1; }
    if (cb->qdisc_cb.pkt_len!=976 || cb->qdisc_cb.tc_classid || metadata[0]!=201 || metadata[4]!=205 ||
        skb.mark!=53 || skb.priority!=59 || buffer[16+73]!=0xc8 || skb.queue_mapping!=42) return 2;
    packet_queue(&skb,65536); if (skb.queue_mapping!=42) return 4;
    packet_queue(&skb,65534); if (skb.queue_mapping!=65534) return 5;
    struct xdp_rxq_info rxq={}; struct xdp_txq_info txq={}; struct xdp_buff xdp={};
    rxq.dev=&dev; rxq.queue_index=43; txq.dev=&outdev;
    xdp.data=buffer+16; xdp.data_end=buffer+144; xdp.data_meta=buffer; xdp.rxq=&rxq; xdp.txq=&txq;
    expected=&xdp;
    if (packet_xdp(&xdp) || buffer[16+73]!=0xd9) return 3;
#ifdef BPF_POINTER_ASM
    unsigned long address;
    if (packet_xdp_length(&xdp)!=128) return 6;
    if (packet_xdp_bounds(&xdp,125,3,&address) || address!=(unsigned long)(buffer+16+125)) return 7;
    if (packet_xdp_bounds(&xdp,126,3,&address)!=-22 || address!=(unsigned long)(buffer+16+126)) return 8;
    if (packet_xdp_bounds(&xdp,0x17d,3,&address) || address!=(unsigned long)(buffer+16+125)) return 9;
    if (packet_xdp_bounds(&xdp,128,0,&address) || address!=(unsigned long)(buffer+144)) return 10;
    if (packet_xdp_two(&xdp,126,&address) || address!=(unsigned long)(buffer+142)) return 11;
    if (packet_xdp_two(&xdp,127,&address)!=-22 || address!=(unsigned long)(buffer+143)) return 12;
    printf("XDP BPF asm length/masked-offset/exact-end/overrun/zero-length/checksum bounds PASS\n");
#endif
    printf("TC qdisc metadata/classid/wire_len, full-width packet pointers, XDP nested interfaces PASS\n");
    return 0;
}
