#include <stdio.h>
extern unsigned long private_sum(unsigned long,unsigned),global_access(unsigned long),pointer_access(unsigned long,volatile unsigned long *),mixed(unsigned long,unsigned,int,volatile unsigned long *),other_local(unsigned long),atomic_local(unsigned long,unsigned);
int main(void) {
    unsigned long seeds[]={0,1,0xffffffffUL,0x100000000UL,0x8000000000000000UL,~0UL};unsigned checks=0;
    for(unsigned s=0;s<6;++s)for(unsigned i=0;i<32;++i) {
        unsigned long value=123,seed=seeds[s];
        if(private_sum(seed,i)!=seed+(i&3) || global_access(seed)!=seed || pointer_access(seed,&value)!=seed || value!=seed || other_local(seed)!=seed || atomic_local(seed,i)!=seed)return 1;
        for(int choose=0;choose<2;++choose)if(mixed(seed,i,choose,&value)!=seed)return 2;
        checks+=7;
    }
    printf("%u private/global/pointer/mixed/atomic executions passed\n",checks);
}
