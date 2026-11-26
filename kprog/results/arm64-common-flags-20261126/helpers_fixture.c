typedef unsigned u32;
typedef unsigned long u64;
extern unsigned char array_map[], hash_map[], lpm_map[], percpu_map[];
static void *(*lookup)(void *, const void *) = (void *)1;
static long (*read_user)(void *, u32, const void *) = (void *)112;
static long (*read_kernel)(void *, u32, const void *) = (void *)113;
u64 array_entry(const u32 *key) { u64 *p=lookup(array_map,key); return p?*p:0; }
u64 hash_entry(const u32 *key) { u64 *p=lookup(hash_map,key); return p?*p:0; }
u64 lpm_entry(const void *key) { u64 *p=lookup(lpm_map,key); return p?*p:0; }
u64 percpu_entry(const u32 *key) { u64 *p=lookup(percpu_map,key); return p?*p:0; }
u64 dynamic_entry(void *map,const u32 *key) { u64 *p=lookup(map,key); return p?*p:0; }
long user_entry(const u64 *src) { u64 value=0; long rc=read_user(&value,8,src); return rc?rc:(long)value; }
long kernel_entry(const u64 *src) { u64 value=0; long rc=read_kernel(&value,8,src); return rc?rc:(long)value; }
