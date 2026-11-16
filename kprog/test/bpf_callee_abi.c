#include <stdint.h>
extern uint64_t supplied5(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
extern uint64_t supplied_load(const uint64_t *, uint64_t);
extern uint64_t supplied_stack(uint64_t, uint64_t);
extern uint64_t supplied_bytes(const unsigned char *, uint64_t);
extern uint64_t supplied_branch(int64_t, uint64_t);
extern uint32_t supplied_narrow(uint64_t, uint64_t);
extern void supplied_store(uint64_t *, uint64_t);
static uint64_t (*volatile call5)(uint64_t,uint64_t,uint64_t,uint64_t,uint64_t) = supplied5;
static uint64_t (*volatile load)(const uint64_t *,uint64_t) = supplied_load;
static uint64_t (*volatile stack)(uint64_t,uint64_t) = supplied_stack;
static uint64_t (*volatile bytes)(const unsigned char *,uint64_t) = supplied_bytes;
static uint64_t (*volatile branch)(int64_t,uint64_t) = supplied_branch;
static uint32_t (*volatile narrow)(uint64_t,uint64_t) = supplied_narrow;
static void (*volatile store)(uint64_t *,uint64_t) = supplied_store;
int main(int argc, char **argv)
{
    (void)argc; (void)argv;
    unsigned char data[32];
    for (unsigned i=0;i<32;++i) data[i]=(unsigned char)(i*7+3);
    for (uint64_t i=0;i<256;++i) {
        uint64_t a=i*0x9e3779b97f4a7c15ULL, b=~a;
        if (call5(a,b,i,0x123456789abcdefULL,i*17) != a+b+i+0x123456789abcdefULL+i*17) return 1;
        uint64_t value=a;
        if (load(&value,b) != a+b || stack(a,b) != a+b) return 2;
        uint64_t unaligned;
        __builtin_memcpy(&unaligned,data+1,sizeof(unaligned));
        if (load((const uint64_t *)(data+1),b) != unaligned+b) return 7;
        uint64_t sum=0, length=i%33;
        for (unsigned j=0;j<length;++j) sum+=data[j];
        if (bytes(data,length) != sum) return 3;
        if (branch((int64_t)a,i) != ((int64_t)a>0 ? i : -i)) return 4;
        if (narrow(a,b) != (uint32_t)(b-1)) return 5;
        store(&value,b);
        if (value != b) return 6;
    }
    return 0;
}
