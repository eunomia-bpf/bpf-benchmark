// A dense volatile switch must survive proof->kernel linking without a jump table.
#define CASE(N) case N: asm volatile("" : : "i"(N) : "memory"); input[1+N] += 37+N*3; return input[33+N] ^ (19+N)
__attribute__((section("native-test"),noinline))
unsigned native_switch(volatile unsigned *input)
{
    switch (input[0]) {
    CASE(0); CASE(1); CASE(2); CASE(3); CASE(4); CASE(5); CASE(6); CASE(7);
    CASE(8); CASE(9); CASE(10); CASE(11); CASE(12); CASE(13); CASE(14); CASE(15);
    default: input[17]+=91; return input[49]^73;
    }
}
