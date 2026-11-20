extern unsigned char map_a[],map_b[];
static void *(*const lookup)(void *,const void *)=(void *)1;
struct query { unsigned selector; unsigned char key[260]; };
void *entry(const void *key) { return lookup(map_a,key); }
void *entry_select(struct query *query)
{
    return lookup(query->selector ? map_b : map_a,query->key);
}
