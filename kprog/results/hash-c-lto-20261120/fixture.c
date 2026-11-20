extern unsigned char map_a[],map_b[],map_c[];
static void *(*const lookup)(void *,const void *)=(void *)1;
void *entry(const void *key) { return lookup(map_a,key); }
void *entry_b(const void *key) { return lookup(map_b,key); }
struct query { unsigned selector; unsigned char key[260]; };
void *entry_select(struct query *q) { return lookup(q->selector?map_b:map_a,q->key); }
void *entry_unknown(const void *key) { return lookup(map_c,key); }
