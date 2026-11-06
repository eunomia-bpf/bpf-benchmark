#include <stdio.h>
#define PUSH_CASE(BYTES, EXPECTED) do { \
 unsigned long delta; \
 __asm__ volatile("mov %%rsp,%%r11; .byte " BYTES "; mov %%r11,%%rax; sub %%rsp,%%rax; mov %%r11,%%rsp" : "=a"(delta) : : "r11","cc","memory"); \
 printf("PUSH [%s] bytes=%lu expected=%u\n",BYTES,delta,EXPECTED); \
 failures += delta != EXPECTED; \
} while(0)
#define POP_CASE(BYTES, EXPECTED) do { \
 unsigned long delta; \
 __asm__ volatile("mov %%rsp,%%r11; sub $16,%%rsp; .byte " BYTES "; mov %%rsp,%%rax; sub %%r11,%%rax; add $16,%%rax; mov %%r11,%%rsp" : "=a"(delta) : : "r11","cc","memory"); \
 printf("POP [%s] bytes=%lu expected=%u\n",BYTES,delta,EXPECTED); \
 failures += delta != EXPECTED; \
} while(0)
int main(void) {
 unsigned failures=0;
 PUSH_CASE("0x66,0x48,0x53",8);
 PUSH_CASE("0x48,0x66,0x53",2);
 PUSH_CASE("0x66,0x48,0xff,0xf3",8);
 PUSH_CASE("0x48,0x66,0xff,0xf3",2);
 POP_CASE("0x66,0x48,0x58",8);
 POP_CASE("0x48,0x66,0x58",2);
 POP_CASE("0x66,0x48,0x8f,0xc0",8);
 POP_CASE("0x48,0x66,0x8f,0xc0",2);
 return failures != 0;
}
