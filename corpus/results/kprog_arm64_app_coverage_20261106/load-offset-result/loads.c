#include <linux/types.h>
#define ARM64_WIDTH_8 1U
#define ARM64_WIDTH_16 2U
#define ARM64_WIDTH_32 4U
#define ARM64_WIDTH_64 8U
#include "/workspaces/repository/kprog/formal/generated/arm64_load_bytes.h"
__u64 load_8_0(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32769, ARM64_WIDTH_8); }
__u64 load_8_1(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32768, ARM64_WIDTH_8); }
__u64 load_8_2(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -16, ARM64_WIDTH_8); }
__u64 load_8_3(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 0, ARM64_WIDTH_8); }
__u64 load_8_4(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 16, ARM64_WIDTH_8); }
__u64 load_8_5(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32767, ARM64_WIDTH_8); }
__u64 load_8_6(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32768, ARM64_WIDTH_8); }
__u64 load_8_dynamic(void *base, long offset) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, offset, ARM64_WIDTH_8); }
__u64 load_16_0(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32769, ARM64_WIDTH_16); }
__u64 load_16_1(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32768, ARM64_WIDTH_16); }
__u64 load_16_2(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -16, ARM64_WIDTH_16); }
__u64 load_16_3(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 0, ARM64_WIDTH_16); }
__u64 load_16_4(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 16, ARM64_WIDTH_16); }
__u64 load_16_5(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32767, ARM64_WIDTH_16); }
__u64 load_16_6(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32768, ARM64_WIDTH_16); }
__u64 load_16_dynamic(void *base, long offset) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, offset, ARM64_WIDTH_16); }
__u64 load_32_0(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32769, ARM64_WIDTH_32); }
__u64 load_32_1(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32768, ARM64_WIDTH_32); }
__u64 load_32_2(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -16, ARM64_WIDTH_32); }
__u64 load_32_3(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 0, ARM64_WIDTH_32); }
__u64 load_32_4(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 16, ARM64_WIDTH_32); }
__u64 load_32_5(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32767, ARM64_WIDTH_32); }
__u64 load_32_6(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32768, ARM64_WIDTH_32); }
__u64 load_32_dynamic(void *base, long offset) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, offset, ARM64_WIDTH_32); }
__u64 load_64_0(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32769, ARM64_WIDTH_64); }
__u64 load_64_1(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -32768, ARM64_WIDTH_64); }
__u64 load_64_2(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, -16, ARM64_WIDTH_64); }
__u64 load_64_3(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 0, ARM64_WIDTH_64); }
__u64 load_64_4(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 16, ARM64_WIDTH_64); }
__u64 load_64_5(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32767, ARM64_WIDTH_64); }
__u64 load_64_6(void *base) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, 32768, ARM64_WIDTH_64); }
__u64 load_64_dynamic(void *base, long offset) { return KPROG_ARM64_LOAD_BYTES_OFFSET(base, offset, ARM64_WIDTH_64); }
#ifndef __BPF__
#include <stdio.h>
int main(void) {
static unsigned char bytes[131088];
for (unsigned i=0; i<sizeof(bytes); ++i) bytes[i]=(i*37+19) & 255;
unsigned char *base=bytes+65536; unsigned cases=0;
if (load_8_0(base) != (((__u64)base[-32769] << 0))) return 1;
++cases;
if (load_8_1(base) != (((__u64)base[-32768] << 0))) return 1;
++cases;
if (load_8_2(base) != (((__u64)base[-16] << 0))) return 1;
++cases;
if (load_8_3(base) != (((__u64)base[0] << 0))) return 1;
++cases;
if (load_8_4(base) != (((__u64)base[16] << 0))) return 1;
++cases;
if (load_8_5(base) != (((__u64)base[32767] << 0))) return 1;
++cases;
if (load_8_6(base) != (((__u64)base[32768] << 0))) return 1;
++cases;
if (load_16_0(base) != (((__u64)base[-32769] << 0) | ((__u64)base[-32768] << 8))) return 1;
++cases;
if (load_16_1(base) != (((__u64)base[-32768] << 0) | ((__u64)base[-32767] << 8))) return 1;
++cases;
if (load_16_2(base) != (((__u64)base[-16] << 0) | ((__u64)base[-15] << 8))) return 1;
++cases;
if (load_16_3(base) != (((__u64)base[0] << 0) | ((__u64)base[1] << 8))) return 1;
++cases;
if (load_16_4(base) != (((__u64)base[16] << 0) | ((__u64)base[17] << 8))) return 1;
++cases;
if (load_16_5(base) != (((__u64)base[32767] << 0) | ((__u64)base[32768] << 8))) return 1;
++cases;
if (load_16_6(base) != (((__u64)base[32768] << 0) | ((__u64)base[32769] << 8))) return 1;
++cases;
if (load_32_0(base) != (((__u64)base[-32769] << 0) | ((__u64)base[-32768] << 8) | ((__u64)base[-32767] << 16) | ((__u64)base[-32766] << 24))) return 1;
++cases;
if (load_32_1(base) != (((__u64)base[-32768] << 0) | ((__u64)base[-32767] << 8) | ((__u64)base[-32766] << 16) | ((__u64)base[-32765] << 24))) return 1;
++cases;
if (load_32_2(base) != (((__u64)base[-16] << 0) | ((__u64)base[-15] << 8) | ((__u64)base[-14] << 16) | ((__u64)base[-13] << 24))) return 1;
++cases;
if (load_32_3(base) != (((__u64)base[0] << 0) | ((__u64)base[1] << 8) | ((__u64)base[2] << 16) | ((__u64)base[3] << 24))) return 1;
++cases;
if (load_32_4(base) != (((__u64)base[16] << 0) | ((__u64)base[17] << 8) | ((__u64)base[18] << 16) | ((__u64)base[19] << 24))) return 1;
++cases;
if (load_32_5(base) != (((__u64)base[32767] << 0) | ((__u64)base[32768] << 8) | ((__u64)base[32769] << 16) | ((__u64)base[32770] << 24))) return 1;
++cases;
if (load_32_6(base) != (((__u64)base[32768] << 0) | ((__u64)base[32769] << 8) | ((__u64)base[32770] << 16) | ((__u64)base[32771] << 24))) return 1;
++cases;
if (load_64_0(base) != (((__u64)base[-32769] << 0) | ((__u64)base[-32768] << 8) | ((__u64)base[-32767] << 16) | ((__u64)base[-32766] << 24) | ((__u64)base[-32765] << 32) | ((__u64)base[-32764] << 40) | ((__u64)base[-32763] << 48) | ((__u64)base[-32762] << 56))) return 1;
++cases;
if (load_64_1(base) != (((__u64)base[-32768] << 0) | ((__u64)base[-32767] << 8) | ((__u64)base[-32766] << 16) | ((__u64)base[-32765] << 24) | ((__u64)base[-32764] << 32) | ((__u64)base[-32763] << 40) | ((__u64)base[-32762] << 48) | ((__u64)base[-32761] << 56))) return 1;
++cases;
if (load_64_2(base) != (((__u64)base[-16] << 0) | ((__u64)base[-15] << 8) | ((__u64)base[-14] << 16) | ((__u64)base[-13] << 24) | ((__u64)base[-12] << 32) | ((__u64)base[-11] << 40) | ((__u64)base[-10] << 48) | ((__u64)base[-9] << 56))) return 1;
++cases;
if (load_64_3(base) != (((__u64)base[0] << 0) | ((__u64)base[1] << 8) | ((__u64)base[2] << 16) | ((__u64)base[3] << 24) | ((__u64)base[4] << 32) | ((__u64)base[5] << 40) | ((__u64)base[6] << 48) | ((__u64)base[7] << 56))) return 1;
++cases;
if (load_64_4(base) != (((__u64)base[16] << 0) | ((__u64)base[17] << 8) | ((__u64)base[18] << 16) | ((__u64)base[19] << 24) | ((__u64)base[20] << 32) | ((__u64)base[21] << 40) | ((__u64)base[22] << 48) | ((__u64)base[23] << 56))) return 1;
++cases;
if (load_64_5(base) != (((__u64)base[32767] << 0) | ((__u64)base[32768] << 8) | ((__u64)base[32769] << 16) | ((__u64)base[32770] << 24) | ((__u64)base[32771] << 32) | ((__u64)base[32772] << 40) | ((__u64)base[32773] << 48) | ((__u64)base[32774] << 56))) return 1;
++cases;
if (load_64_6(base) != (((__u64)base[32768] << 0) | ((__u64)base[32769] << 8) | ((__u64)base[32770] << 16) | ((__u64)base[32771] << 24) | ((__u64)base[32772] << 32) | ((__u64)base[32773] << 40) | ((__u64)base[32774] << 48) | ((__u64)base[32775] << 56))) return 1;
++cases;
for (long off=-32769; off<=32769; off+=257) {
__u64 expected=0;
for (unsigned j=0; j<1; ++j) expected |= (__u64)base[off+j] << (8*j);
if (load_8_dynamic(base,off) != expected) return 2;
++cases;
}
for (long off=-32769; off<=32769; off+=257) {
__u64 expected=0;
for (unsigned j=0; j<2; ++j) expected |= (__u64)base[off+j] << (8*j);
if (load_16_dynamic(base,off) != expected) return 2;
++cases;
}
for (long off=-32769; off<=32769; off+=257) {
__u64 expected=0;
for (unsigned j=0; j<4; ++j) expected |= (__u64)base[off+j] << (8*j);
if (load_32_dynamic(base,off) != expected) return 2;
++cases;
}
for (long off=-32769; off<=32769; off+=257) {
__u64 expected=0;
for (unsigned j=0; j<8; ++j) expected |= (__u64)base[off+j] << (8*j);
if (load_64_dynamic(base,off) != expected) return 2;
++cases;
}
printf("load offset values: %u cases\n",cases); return 0; }
#endif
