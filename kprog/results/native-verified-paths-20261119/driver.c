#include <stdio.h>
extern unsigned long verified_dispatch(unsigned long),verified_memory(unsigned long),program_check(unsigned long);
int main(void) {
    unsigned cases=0;
    /* The two native compiler contracts have exactly the verifier's valid
     * input domain. Ordinary program decisions are exercised on both sides. */
    for(unsigned n=0;n<1024;++n) {
        unsigned long value=n&7;
        if(verified_dispatch(value)!=value*3 || verified_memory(value)!=value+4)return 1;
        if(program_check(n)!=(n>7?99:n*3))return 2;
        cases+=3;
    }
    printf("%u verified-domain and ordinary-program-check executions passed\n",cases);
}
