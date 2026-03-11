#ifndef __NETBIRD_LEGACY_BPF_MAP_DEF_H
#define __NETBIRD_LEGACY_BPF_MAP_DEF_H

/*
 * NetBird's XDP source still uses the legacy libbpf map definition style.
 * Newer libbpf headers no longer provide this struct, so keep a tiny
 * compatibility shim in-repo for reproducible corpus rebuilds.
 */
struct bpf_map_def {
    unsigned int type;
    unsigned int key_size;
    unsigned int value_size;
    unsigned int max_entries;
    unsigned int map_flags;
};

#endif
