#ifndef BPF_SMC_SKEL_H
#define BPF_SMC_SKEL_H

#include <errno.h>
#include <bpf/libbpf.h>

struct bpf_smc {
    struct bpf_object_skeleton *skeleton;
    struct bpf_object *obj;
    struct {
        struct bpf_map *dummy;
    } maps;
    struct bpf_smc__bss *bss;
};

static inline struct bpf_smc *bpf_smc__open_and_load(void) { return NULL; }
static inline int bpf_smc__attach(struct bpf_smc *s) { (void)s; return -ENOTSUP; }
static inline void bpf_smc__destroy(struct bpf_smc *s) { (void)s; }
static inline struct bpf_smc *bpf_smc__open_opts(const struct bpf_object_open_opts *o)
{
    (void)o;
    return NULL;
}

#endif
