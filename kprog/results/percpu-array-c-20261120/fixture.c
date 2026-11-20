extern unsigned char counts[],same[],other[];
static void *(*const lookup)(void *,const void *)=(void *)1;
void *selected(const void *key) { return lookup(counts,key); }
void *selected_alias(const void *key) { return lookup(same,key); }
void *unselected(const void *key) { return lookup(other,key); }
void *dynamic(void *map,const void *key) { return lookup(map,key); }
