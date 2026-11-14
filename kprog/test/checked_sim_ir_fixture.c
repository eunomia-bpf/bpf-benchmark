typedef unsigned long long u64;
typedef unsigned int u32;
#ifdef INVALID_ASM
u64 invalid(u64 value) { asm volatile("unsupported_sim_operation" : "+r"(value)); return value; }
#else
#define WIDTH(bits) \
u64 load##bits(void *p) { u64 v; asm volatile("%0 = *(u" #bits " *)(%1 - %2)" : "=r"(v) : "r"(p), "i"(3) : "memory"); return v; } \
void store##bits(void *p,u64 v) { asm volatile("*(u" #bits " *)(%0 + %2) = %1" :: "r"(p),"r"(v),"i"(3) : "memory"); }
WIDTH(8)
WIDTH(16)
WIDTH(32)
WIDTH(64)
u64 truncate32(u32 value) { asm volatile("%0 = %0" : "+w"(value)); return value; }
#endif
