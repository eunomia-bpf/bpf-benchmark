#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define X86_SIM_USE_STATE_STRUCT
#define X86_SIM_STACK_BYTES 64U
#include "../../x86/x86_sim_local_bpf.h"

static _Thread_local unsigned recovery;
static _Thread_local unsigned input_visits;
unsigned long native_lab_entry_input(unsigned kind)
{
    assert(kind == NATIVE_LAB_INPUT_UNSPECIFIED);
    ++input_visits;
    return recovery;
}

/* Exercise the real shared handlers and retain their separate ghost tags. */
static unsigned simulate(struct x86_sim_state *state, unsigned form,
                         unsigned base, unsigned width, unsigned operation,
                         unsigned aux, uint64_t immediate)
{
    X86_SIM_L_BIND_COMMON_STATE(state);
    for (unsigned i=0; i<8; ++i) {
        X86_SIM_L_SV_TAG(i)=X86_SIM_TAG_STACK;
        X86_SIM_L_SV_PTR(i)=(void *)(uintptr_t)(0x1000+i*8);
    }
    unsigned flags=width | X86_MEM_LOCK;
    aux |= X86_MEM_AUX_ALU_OP(operation);
    if (form == 0)
        X86_SIM_L_EXEC_ALU_MEM_UNARY(base,flags,aux,immediate);
    else if (form == 1)
        X86_SIM_L_EXEC_ALU_MEM_REG(base,X86_RSI,flags,aux,immediate);
    else
        X86_SIM_L_EXEC_ALU_MEM_IMM(base,flags,aux,immediate);
    unsigned tags=0;
    for (unsigned i=0; i<8; ++i) {
        if (X86_SIM_L_SV_TAG(i)) tags |= 1U<<i;
        else assert(X86_SIM_L_SV_PTR(i) == NULL);
    }
    return tags;
}

static void plain_unary(struct x86_sim_state *state, unsigned base,
                        uint64_t displacement)
{
    X86_SIM_L_BIND_COMMON_STATE(state);
    X86_SIM_L_EXEC_ALU_MEM_UNARY(base,X86_WIDTH_64,
        X86_MEM_AUX(X86_REG_NONE,0) | X86_MEM_AUX_ALU_OP(X86_ALU_INC),displacement);
}

#define HW_BINARY(NAME, SUFFIX, TYPE, MOD) \
static uint64_t hw_##NAME##SUFFIX(TYPE *address, uint64_t rhs, uint64_t initial) \
{ \
    uint64_t flags; \
    __asm__ volatile("pushq %[initial]\n\tpopfq\n\tlock " #NAME #SUFFIX \
                     " %" #MOD "[rhs], (%[address])\n\tpushfq\n\tpopq %[flags]" \
        : [flags] "=&r"(flags) : [address] "r"(address), [rhs] "r"(rhs), \
          [initial] "r"(initial) : "memory", "cc"); \
    return flags; \
}
#define HW_UNARY(NAME, SUFFIX, TYPE) \
static uint64_t hw_##NAME##SUFFIX(TYPE *address, uint64_t rhs, uint64_t initial) \
{ \
    (void)rhs; \
    uint64_t flags; \
    __asm__ volatile("pushq %[initial]\n\tpopfq\n\tlock " #NAME #SUFFIX \
                     " (%[address])\n\tpushfq\n\tpopq %[flags]" \
        : [flags] "=&r"(flags) : [address] "r"(address), \
          [initial] "r"(initial) : "memory", "cc"); \
    return flags; \
}
#define HW_WIDTH(SUFFIX, TYPE, MOD) \
 HW_BINARY(add,SUFFIX,TYPE,MOD) HW_BINARY(sub,SUFFIX,TYPE,MOD) \
 HW_BINARY(adc,SUFFIX,TYPE,MOD) HW_BINARY(sbb,SUFFIX,TYPE,MOD) \
 HW_BINARY(and,SUFFIX,TYPE,MOD) HW_BINARY(or,SUFFIX,TYPE,MOD) \
 HW_BINARY(xor,SUFFIX,TYPE,MOD) HW_UNARY(inc,SUFFIX,TYPE) \
 HW_UNARY(dec,SUFFIX,TYPE) HW_UNARY(not,SUFFIX,TYPE) HW_UNARY(neg,SUFFIX,TYPE)
HW_WIDTH(b,uint8_t,b)
HW_WIDTH(w,uint16_t,w)
HW_WIDTH(l,uint32_t,k)
HW_WIDTH(q,uint64_t,q)

#define HW_DISPATCH(OP, NAME, SUFFIX) \
    case OP: return hw_##NAME##SUFFIX(address,rhs,initial);
#define HW_SELECT(SUFFIX) \
    switch (operation) { \
    HW_DISPATCH(X86_ALU_ADD,add,SUFFIX) HW_DISPATCH(X86_ALU_SUB,sub,SUFFIX) \
    HW_DISPATCH(X86_ALU_ADC,adc,SUFFIX) HW_DISPATCH(X86_ALU_SBB,sbb,SUFFIX) \
    HW_DISPATCH(X86_ALU_AND,and,SUFFIX) HW_DISPATCH(X86_ALU_OR,or,SUFFIX) \
    HW_DISPATCH(X86_ALU_XOR,xor,SUFFIX) HW_DISPATCH(X86_ALU_INC,inc,SUFFIX) \
    HW_DISPATCH(X86_ALU_DEC,dec,SUFFIX) HW_DISPATCH(X86_ALU_NOT,not,SUFFIX) \
    HW_DISPATCH(X86_ALU_NEG,neg,SUFFIX) \
    }
static uint64_t hardware(void *address, unsigned width, unsigned operation,
                         uint64_t rhs, uint64_t initial)
{
    switch (width) {
    case 1: HW_SELECT(b) break;
    case 2: HW_SELECT(w) break;
    case 4: HW_SELECT(l) break;
    case 8: HW_SELECT(q) break;
    }
    assert(0);
    return 0;
}

static void set_flags(struct x86_sim_state *s, uint64_t f)
{
    s->cf=!!(f&1); s->pf=!!(f&4); s->af=!!(f&16);
    s->zf=!!(f&64); s->sf=!!(f&128); s->of=!!(f&2048);
}
static uint64_t get_flags(const struct x86_sim_state *s)
{
    return s->cf | s->pf*4 | s->af*16 | s->zf*64 | s->sf*128 | s->of*2048;
}

static uint64_t counter;
static void *increment(void *unused)
{
    (void)unused;
    struct x86_sim_state s={0};
    s.abi_kind=X86_SIM_ABI_KIND_RAW;
    s.rdi.ptr=&counter; s.rdi_tag=X86_SIM_TAG_MAP_VALUE;
    for (unsigned i=0; i<20000; ++i)
        simulate(&s,0,X86_RDI,8,X86_ALU_INC,X86_MEM_AUX(X86_REG_NONE,0),0);
    return NULL;
}

int main(void)
{
    const unsigned ops[]={X86_ALU_ADD,X86_ALU_SUB,X86_ALU_ADC,X86_ALU_SBB,
        X86_ALU_AND,X86_ALU_OR,X86_ALU_XOR,X86_ALU_INC,X86_ALU_DEC,
        X86_ALU_NOT,X86_ALU_NEG};
    const uint64_t values[]={0,1,0x7f,0x80,0x7fff,0x8000,0x7fffffff,
        0x80000000,0x7fffffffffffffffULL,0x8000000000000000ULL,UINT64_MAX};
    unsigned vectors=0;
    for (unsigned w=1; w<=8; w*=2) for (unsigned opi=0; opi<11; ++opi)
    for (unsigned a=0; a<11; ++a) for (unsigned b=0; b<11; ++b)
    for (unsigned carry=0; carry<2; ++carry) {
        unsigned op=ops[opi];
        int unary=op==X86_ALU_INC || op==X86_ALU_DEC || op==X86_ALU_NOT || op==X86_ALU_NEG;
        for (unsigned form=unary?0:1; form<=(unary?0:2); ++form) {
            uint64_t sim[3]={0xaaaaaaaaaaaaaaaaULL,values[a],0x5555555555555555ULL};
            uint64_t expected[3]; memcpy(expected,sim,sizeof(sim));
            uint64_t rhs=form==2?(uint64_t)(int64_t)(int32_t)values[b]:values[b];
            uint64_t initial=0x202 | (carry?0x8d5:0x94);
            struct x86_sim_state s={0};
            s.abi_kind=X86_SIM_ABI_KIND_RAW;
            s.rdi.ptr=&sim[0]; s.rdi_tag=X86_SIM_TAG_MAP_VALUE;
            s.rsi.ptr=(void *)(uintptr_t)rhs; s.rcx.ptr=(void *)2;
            set_flags(&s,initial);
            /* Base + index*4 - 0 reaches the second word. */
            uint64_t imm=form==2?(uint32_t)rhs:0;
            assert(simulate(&s,form,X86_RDI,w,op,X86_MEM_AUX(X86_RCX,2),imm)==255);
            uint64_t flags=hardware(&expected[1],w,op,rhs,initial);
            unsigned mask=(op==X86_ALU_AND || op==X86_ALU_OR || op==X86_ALU_XOR)?0x8c5:0x8d5;
            if (memcmp(sim,expected,sizeof(sim)) || ((flags^get_flags(&s))&mask)) {
                fprintf(stderr,"width=%u op=%u form=%u lhs=%llx rhs=%llx flags=%llx/%llx\n",
                        w,op,form,(unsigned long long)values[a],(unsigned long long)rhs,
                        (unsigned long long)flags,(unsigned long long)get_flags(&s));
                return 1;
            }
            ++vectors;
        }
    }
    /* RSP offsets and stack aliases invalidate only their overlapping slot. */
    for (unsigned alias=0; alias<2; ++alias) {
        struct x86_sim_state s={0};
        s.abi_kind=X86_SIM_ABI_KIND_RAW;
        s.rsp.ptr=(void *)(intptr_t)-32;
        s.rdi.ptr=&s.stack_mem.b[32]; s.rdi_tag=X86_SIM_TAG_STACK;
        s.stack_mem.q[4]=17;
        assert(simulate(&s,0,alias?X86_RDI:X86_RSP,8,X86_ALU_INC,
                        X86_MEM_AUX(X86_REG_NONE,0),0)==(255U ^ 16U));
        assert(s.stack_mem.q[4]==18);
    }
    for (unsigned form=0; form<3; ++form) {
        struct x86_sim_state s={0}; uint64_t words[3]={11,17,23};
        s.abi_kind=X86_SIM_ABI_KIND_RAW;
        s.rdi.ptr=&words[2]; s.rdi_tag=X86_SIM_TAG_MAP_VALUE;
        s.rsi.ptr=(void *)5;
        uint64_t imm=form==2?((uint64_t)(uint32_t)-8<<32)|5:(uint64_t)-8;
        assert(simulate(&s,form,X86_RDI,8,form?X86_ALU_ADD:X86_ALU_INC,
                        X86_MEM_AUX(X86_REG_NONE,0),imm)==255);
        assert(words[0]==11 && words[1]==(form?22:18) && words[2]==23);
    }
    /* Released private bytes use the same independent input visits as the
     * ordinary private read/write: their physical arena is not shared data. */
    for (unsigned alias=0; alias<2; ++alias) {
        struct x86_sim_state s={0};
        s.abi_kind=X86_SIM_ABI_KIND_RAW;
        s.rsp.ptr=(void *)(intptr_t)-16;
        s.rdi.ptr=&s.stack_mem.b[40]; s.rdi_tag=X86_SIM_TAG_STACK;
        s.stack_mem.q[5]=UINT64_MAX;
        struct x86_sim_state prior=s;
        prior.rdi.ptr=&prior.stack_mem.b[40];
        input_visits=0;
        plain_unary(&prior,alias?X86_RDI:X86_RSP,alias?0:(uint64_t)-8);
        unsigned prior_visits=input_visits;
        input_visits=0;
        assert(simulate(&s,0,alias?X86_RDI:X86_RSP,8,X86_ALU_INC,
                        X86_MEM_AUX(X86_REG_NONE,0),alias?0:(uint64_t)-8)==(255U^32U));
        assert(s.stack_mem.q[5]==prior.stack_mem.q[5]);
        assert(get_flags(&s)==get_flags(&prior) && input_visits==prior_visits);
    }
    /* Existing recovery observes failure before the atomic and changes no flags. */
    struct x86_sim_state fault={0}; uint64_t memory=91;
    fault.rdi.ptr=&memory; fault.rdi_tag=X86_SIM_TAG_SCALAR;
    fault.cf=1; recovery=1;
    assert(simulate(&fault,0,X86_RDI,8,X86_ALU_INC,X86_MEM_AUX(X86_REG_NONE,0),0)==255);
    assert(memory==91 && fault.cf==1);
    recovery=0;
    pthread_t threads[4];
    for (unsigned i=0; i<4; ++i) assert(pthread_create(&threads[i],NULL,increment,NULL)==0);
    for (unsigned i=0; i<4; ++i) assert(pthread_join(threads[i],NULL)==0);
    assert(counter==80000);
    printf("%u hardware flag/memory vectors; 2 live and 2 released stack aliases; 3 negative displacements; recovery; 80000 concurrent increments passed\n",vectors);
    return 0;
}
