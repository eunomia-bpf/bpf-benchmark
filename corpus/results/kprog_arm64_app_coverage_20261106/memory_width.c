/* Detect split BPF accesses, unaligned host UB, and writes outside the width. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#include "../../../kprog/formal/generated/arm64_width.h"
#include "../../../kprog/formal/generated/arm64_load_bytes.h"
#include "../../../kprog/formal/generated/arm64_store_bytes.h"

#define WIDTH_CASE(BITS, WIDTH) \
__attribute__((used,noinline)) __u64 read##BITS(const __u8 *p) { \
    return KPROG_ARM64_LOAD_BYTES(p+3, WIDTH); \
} \
__attribute__((used,noinline)) void write##BITS(__u8 *p, __u64 value) { \
    KPROG_ARM64_STORE_BYTES(p+3, WIDTH, value); \
}
WIDTH_CASE(8,ARM64_WIDTH_8)
WIDTH_CASE(16,ARM64_WIDTH_16)
WIDTH_CASE(32,ARM64_WIDTH_32)
WIDTH_CASE(64,ARM64_WIDTH_64)

#if !defined(__bpf__) && !defined(__BPF__)
#include <stdio.h>
int main(void)
{
    __u64 (*reads[])(const __u8 *)={read8,read16,read32,read64};
    void (*writes[])(__u8 *,__u64)={write8,write16,write32,write64};
    unsigned count=0;
    for (unsigned width=0;width<4;width++) for (unsigned offset=0;offset<16;offset++)
        for (unsigned seed=0;seed<16;seed++) {
            __u8 bytes[40];
            for (unsigned i=0;i<sizeof(bytes);i++) bytes[i]=i*17+seed*13;
            __u64 expected=0;
            for (unsigned i=0;i<(1U<<width);i++) expected|=(__u64)bytes[offset+3+i]<<(8*i);
            if (reads[width](bytes+offset)!=expected) return 1;
            __u64 value=0x0123456789abcdefULL ^ ((0xfedcba9876543210ULL/15)*seed);
            writes[width](bytes+offset,value);
            for (unsigned i=0;i<sizeof(bytes);i++) {
                __u8 want=(i>=offset+3 && i<offset+3+(1U<<width)) ?
                    (__u8)(value>>(8*(i-offset-3))) : (__u8)(i*17+seed*13);
                if (bytes[i]!=want) return 2;
            }
            count++;
        }
    printf("%u unaligned load/store scenes pass ASan/UBSan with exact bytes and untouched neighbors\n",count);
    return 0;
}
#endif
