#include <linux/bpf.h>
#include <bpf_helpers.h>
extern unsigned char counts[] __ksym;
SEC("socket") int entry(void *ctx) {
    unsigned key=0;
    unsigned *value=bpf_map_lookup_elem(counts,&key);
    return value ? *value : 0;
}
char LICENSE[] SEC("license")="GPL";
