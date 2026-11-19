union x86_sim_stack_mem { unsigned char b[32]; unsigned long q[4]; };
volatile union x86_sim_stack_mem global_state;
unsigned long private_sum(unsigned long seed,unsigned index) {
    volatile union x86_sim_stack_mem state;
    state.q[0]=seed;state.q[1]=seed+1;state.q[2]=seed+2;state.q[3]=seed+3;
    return state.q[index&3];
}
unsigned long global_access(unsigned long seed) { global_state.q[0]=seed;return global_state.q[0]; }
unsigned long pointer_access(unsigned long seed,volatile unsigned long *p) { *p=seed;return *p; }
unsigned long mixed(unsigned long seed,unsigned index,int choose,volatile unsigned long *external) {
    volatile union x86_sim_stack_mem state;
    volatile unsigned long *p=choose ? &state.q[index&3] : external;
    *p=seed;return *p;
}
unsigned long other_local(unsigned long seed) { volatile unsigned long value=seed;return value; }
unsigned long atomic_local(unsigned long seed,unsigned index) {
    union x86_sim_stack_mem state;
    volatile _Atomic unsigned long *p=(volatile _Atomic unsigned long *)&state.q[index&3];
    __c11_atomic_store(p,seed,0);return __c11_atomic_load(p,0);
}
