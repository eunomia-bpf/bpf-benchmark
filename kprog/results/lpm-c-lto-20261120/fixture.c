#include <stdint.h>
extern unsigned char map_a[], map_b[];
extern void *bpf_map_lookup_elem(void *, const void *);
struct query { unsigned selector; unsigned char key[260]; };
void *entry(const void *key) { return bpf_map_lookup_elem(map_a, key); }
void *entry_select(struct query *query)
{
    return bpf_map_lookup_elem(query->selector ? map_b : map_a, query->key);
}
