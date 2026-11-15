/* One untouched source for the BPF reference and direct native fixture. */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

#define MAP(N) struct { \
    __uint(type, BPF_MAP_TYPE_ARRAY); \
    __uint(max_entries, 1); \
    __type(key, unsigned int); \
    __type(value, unsigned long); \
} map##N SEC(".maps");
MAP(0) MAP(1) MAP(2) MAP(3) MAP(4) MAP(5) MAP(6) MAP(7)

SEC("kprobe/map_lookup_table")
int map_lookup_table(const unsigned long *context)
{
    void *map;
    switch ((unsigned int)context[10] & 15) {
    case 0: map = &map0; break;
    case 1: map = &map1; break;
    case 2: map = &map2; break;
    case 3: map = &map3; break;
    case 4: map = &map4; break;
    case 5: map = &map5; break;
    case 6: map = &map6; break;
    case 7: map = &map7; break;
    default: return 0;
    }
    unsigned int key = 0;
    unsigned long *value = bpf_map_lookup_elem(map, &key);
    return value ? (int)*value : 0;
}

char LICENSE[] SEC("license") = "GPL";
