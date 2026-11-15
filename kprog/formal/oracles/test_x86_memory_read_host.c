/* Catch fixed/indexed address selection, released aliases, full pointer loads,
 * recovery-before-read and MOVBE composition errors in the actual C roots. */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Memory.h"

static unsigned long reads,handlers,stores;
static unsigned draws,copies;
static int writing;
static int paired;
static __u64 choice;
static const void *expected_source;
static void *expected_destination;
static size_t expected_size;
static void check(int ok,const char *why)
{
    if (!ok) { fprintf(stderr,"memory reads=%lu handlers=%lu: %s\n",reads,handlers,why); exit(1); }
}
unsigned long native_lab_entry_input(unsigned kind)
{ check(kind==NATIVE_LAB_INPUT_UNSPECIFIED,"free input kind"); draws++; return choice; }
void kprog_c_trap(void) { _exit(77); }
void *kprog_c_context_pointer(const void *ctx,__u8 kind,__u32 offset)
{ (void)ctx;(void)kind;(void)offset; check(0,"unexpected context field"); abort(); }
__u64 kprog_c_pointer_bits(const void *pointer)
{ (void)pointer; check(0,"unexpected context exposure"); abort(); }
void __builtin_memcpy_aligned(void *dst,const void *src,size_t size,size_t alignment)
{
    size_t lane=paired?copies*8:0;
    check((writing?dst==(char *)expected_destination+lane:src==(const char *)expected_source+lane) && size==expected_size && alignment==1,"physical copy source/destination/size/alignment");
    copies++; memcpy(dst,src,size);
}
static __u64 little(const __u8 *p,unsigned n)
{ __u64 v=0;for (unsigned i=0;i<n;i++) v|=(__u64)p[i]<<(8*i);return v; }
static __u64 reverse(__u64 v,unsigned n)
{ __u64 out=0;for (unsigned i=0;i<n;i++) out=(out<<8)|((v>>(8*i))&255);return out; }
static void reset(void) { draws=copies=0; }
static void copy_count(unsigned expected)
{
#if defined(__COMPCERT__)
    check(copies==expected,"selected physical copy count");
#else
    (void)expected;check(!copies,"native uses actual accesses");
#endif
}
static void selector_cases(void)
{
    const __u64 extra[]={256,0x100000001ULL,0x100000008ULL,~0ULL};
    for (unsigned i=0;i<260;i++) {
        __u64 flags=i<256?i:extra[i-256],probe=flags;__u8 value;
        unsigned expected=flags?(__u8)flags:8;
        check(kprog_x86_movbe_width(flags)==expected,"width raw truth before capture");
        for (unsigned facade=0;facade<2;facade++) {
            probe=flags;
            if (facade) value=KPROG_X86_MOVBE_WIDTH(probe++);
            else KPROG_X86_MOVBE_WIDTH_INTO(value,probe++);
            check(value==(flags?(__u8)(flags+1):8) && probe==flags+(flags?2:1),"width second evaluation");
        }
        check(kprog_x86_movbe_arm(flags)==(flags?0:1),"arm full truth");
        probe=flags;KPROG_X86_MOVBE_ARM_INTO(value,probe++);
        check(value==(flags?0:1) && probe==flags+1,"arm single capture");
    }
}
static void read_cases(void)
{
    const unsigned capacities[]={9,64,200,376};
    const __u64 widths[]={0,1,2,4,8,256,0x100000001ULL,0x100000008ULL};
    const unsigned tags[]={0,1,2,3,4,5,255};
    _Alignas(8) __u8 memory[1024],before[1024];
    for (unsigned i=0;i<sizeof(memory);i++) memory[i]=(__u8)(i*37+0x83);
    memcpy(before,memory,sizeof(memory));
    struct kprog_x86_arena arena={.b=memory+256,.q=(void *)(memory+256),.w=(void *)(memory+256),.d=(void *)(memory+256)};
    struct x86_sim_register_state state,initial;
    for (unsigned c=0;c<4;c++) for (unsigned t=0;t<7;t++) for (unsigned wi=0;wi<8;wi++)
    for (unsigned at=0;at<8;at++) for (unsigned indexed=0;indexed<2;indexed++)
    for (unsigned store=0;store<2;store++) for (unsigned released=0;released<2;released++) {
        unsigned capacity=capacities[c],code=(__u8)widths[wi];if (!code) code=8;
        unsigned n=code; if (at+n>capacity) continue;
        __s64 off=(__s64)at-capacity;
        memset(&state,0x6b,sizeof(state));state.is_xdp=0;state.abi_kind=X86_SIM_ABI_KIND_RAW;
        state.gpr_cells[7].value.ptr=memory+256+at-3;state.gpr_cells[7].tag=tags[t];
        state.gpr_cells[2].value.ptr=(void *)(intptr_t)1;state.gpr_cells[2].tag=0;
        state.rsp.ptr=(void *)(intptr_t)(off+released);
        __u64 aux=X86_MEM_AUX(indexed?2:X86_REG_NONE,indexed?1:0);
        __s64 disp=indexed?1:3;__u64 imm=store?(__u64)(unsigned)disp<<32|0xa1b2c3d4U:(__u64)disp;
        memcpy(&initial,&state,sizeof(state));expected_source=memory+256+at;expected_size=n;
        for (unsigned v=0;v<3;v++) {
            choice=v==0?0:v==1?~0ULL:0xa1b2c3d4e5f60718ULL;reset();
            int replaced=indexed && tags[t]==4 && released;
            __u64 expected=replaced?choice & (n==8?~0ULL:(1ULL<<(8*n))-1):little(expected_source,n);
            __u64 result=kprog_x86_read_mem_value(&state,tags[t]==4?&arena:NULL,capacity,7,aux,imm,widths[wi],store);
            check(result==expected && draws==(unsigned)replaced,"fixed/indexed/disp/released-alias value");
            copy_count(1);
            check(!memcmp(&state,&initial,sizeof(state)) && !memcmp(memory,before,sizeof(memory)),"read complete frame");reads++;
        }
        /* RSP addresses are private coordinates and never a physical pointer. */
        state.rsp.ptr=(void *)(intptr_t)off;memcpy(&initial,&state,sizeof(state));reset();
        check(kprog_x86_read_mem_value(&state,&arena,capacity,4,X86_MEM_AUX(X86_REG_NONE,0),0,widths[wi],0)==little(expected_source,n),"RSP route precedence/private coordinate");
        check(!draws && !copies && !memcmp(&state,&initial,sizeof(state)),"stack route observations/frame");reads++;
    }
}
static void handler_cases(void)
{
    const unsigned tags[]={0,1,2,3,4,255};const unsigned widths[]={0,1,2,4,8};
    _Alignas(8) __u8 bytes[96],initial_bytes[96],expected_bytes[96];
    struct kprog_x86_arena arena={.b=bytes,.q=(void *)bytes,.w=(void *)bytes,.d=(void *)bytes};
    __u8 fact_tags[8],saved_tags[8],expected_tags[8];void *pointers[8],*saved_pointers[8],*expected_pointers[8];
    struct kprog_x86_stack_fact facts[8];
    for (unsigned i=0;i<8;i++) { facts[i].tag=&fact_tags[i];facts[i].pointer=&pointers[i]; }
    for (unsigned ti=0;ti<6;ti++) for (unsigned wi=0;wi<5;wi++)
    for (unsigned dst=0;dst<17;dst++) for (unsigned src=6;src<=7;src++)
    for (unsigned indexed=0;indexed<2;indexed++) for (unsigned recover=0;recover<2;recover++) {
        if (recover && tags[ti]==0 && dst==4) continue; /* Nonreturn tested separately. */
        struct x86_sim_register_state initial,state,expected;
        memset(&initial,0x6b,sizeof(initial));initial.is_xdp=0;initial.abi_kind=X86_SIM_ABI_KIND_RAW;
        initial.rsp.ptr=(void *)(intptr_t)-64;
        for (unsigned i=0;i<96;i++) bytes[i]=(__u8)(i*29+0x51);
        for (unsigned i=0;i<8;i++) { fact_tags[i]=(i%3)?4:1;pointers[i]=bytes+8*i; }
        initial.gpr_cells[src].value.ptr=bytes+8;initial.gpr_cells[src].tag=tags[ti];
        initial.gpr_cells[2].value.ptr=(void *)(intptr_t)1;initial.gpr_cells[2].tag=0;
        memcpy(initial_bytes,bytes,sizeof(bytes));memcpy(saved_tags,fact_tags,sizeof(fact_tags));memcpy(saved_pointers,pointers,sizeof(pointers));
        unsigned n=widths[wi]?widths[wi]:8,reg=dst==16?255:dst;
        __u64 aux=X86_MEM_AUX(indexed?2:X86_REG_NONE,0),imm=indexed?2:3;
        expected_source=bytes+11;expected_size=n;choice=recover?1:0;
        expected=initial;reset();
        int rejected=tags[ti]==0 && recover;
        __u64 value=rejected?0:reverse(little(expected_source,n),n);
        /* Check composition with the separately exported, independently tested
         * writer, including RSP release/fact/free-input effects. */
        kprog_x86_write_reg(&expected,&arena,facts,64,reg,value,rejected?8:n,0);
        unsigned expected_draws=draws+(tags[ti]==0);
        memcpy(expected_bytes,bytes,sizeof(bytes));memcpy(expected_tags,fact_tags,sizeof(fact_tags));memcpy(expected_pointers,pointers,sizeof(pointers));
        memcpy(bytes,initial_bytes,sizeof(bytes));memcpy(fact_tags,saved_tags,sizeof(fact_tags));memcpy(pointers,saved_pointers,sizeof(pointers));
        state=initial;reset();kprog_x86_movbe_load(&state,&arena,facts,64,reg,src,widths[wi],aux,imm);
        check(!memcmp(&state,&expected,sizeof(state)) && !memcmp(bytes,expected_bytes,sizeof(bytes)) &&
              !memcmp(fact_tags,expected_tags,sizeof(fact_tags)) && !memcmp(pointers,expected_pointers,sizeof(pointers)),"MOVBE reversal/alias/writer/recovery full frame");
        check(draws==expected_draws,"MOVBE recovery/release input count");copy_count(!rejected);handlers++;
    }
}
static const void *fault_address;
static unsigned fault_draws;
static void fault(int sig,siginfo_t *info,void *context)
{ (void)context;_exit(sig==SIGSEGV && info->si_addr==fault_address && draws==fault_draws?0:1); }
static void guarded(void)
{
    long page=sysconf(_SC_PAGESIZE);check(page>0,"page size");
    __u8 *mem=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    check(mem!=MAP_FAILED && !mprotect(mem+page,page,PROT_NONE),"guard mapping");
    struct x86_sim_register_state state={0};state.abi_kind=X86_SIM_ABI_KIND_RAW;
    state.gpr_cells[7].tag=1;
    void *pointer=(void *)(uintptr_t)0xfedcba9876543210ULL;
    memcpy(mem+page-8,&pointer,8);expected_source=mem+page-8;expected_size=8;reset();
    state.gpr_cells[7].value.ptr=mem+page-9;state.gpr_cells[2].value.ptr=(void *)(intptr_t)1;
    check(kprog_x86_read_mem_value(&state,NULL,0,7,X86_MEM_AUX(2,0),0,8,0)==(uintptr_t)pointer,"indexed pointer load full window");copy_count(1);
    for (unsigned w=1;w<=8;w*=2) {
        state.gpr_cells[7].value.ptr=mem+page-w;state.gpr_cells[7].tag=2;
        expected_source=mem+page-w;expected_size=w;reset();
        check(kprog_x86_read_mem_value(&state,NULL,0,7,X86_MEM_AUX(X86_REG_NONE,0),0,w,0)==little(mem+page-w,w),"guarded fixed read size");copy_count(1);
    }
    check(!mprotect(mem,page,PROT_NONE),"guard first byte");fault_address=mem+page-1;
    pid_t pid=fork();check(pid>=0,"fault fork");
    if (!pid) {
        struct sigaction a={0};a.sa_sigaction=fault;a.sa_flags=SA_SIGINFO;
        if (sigemptyset(&a.sa_mask) || sigaction(SIGSEGV,&a,NULL)) _exit(2);
        state.gpr_cells[7].tag=4;state.gpr_cells[7].value.ptr=(void *)fault_address;
        struct kprog_x86_arena arena={.b=(void *)fault_address};state.rsp.ptr=0;
        expected_source=fault_address;expected_size=8;reset();
        (void)kprog_x86_read_mem_value(&state,&arena,64,7,X86_MEM_AUX(2,0),~0ULL,8,0);_exit(3);
    }
    int status;check(waitpid(pid,&status,0)==pid && WIFEXITED(status) && !WEXITSTATUS(status),"physical fault before alias/release draw");
    pid=fork();check(pid>=0,"recovery fork");
    if (!pid) {
        state.gpr_cells[7].tag=0;state.gpr_cells[7].value.ptr=0;choice=0;reset();
        kprog_x86_movbe_load(&state,NULL,NULL,0,4,7,8,X86_MEM_AUX(X86_REG_NONE,0),0);_exit(3);
    }
    check(waitpid(pid,&status,0)==pid,"wait RSP recovery");
#if defined(__COMPCERT__)
    check(WIFEXITED(status) && WEXITSTATUS(status)==77,"RSP recovery nonreturn platform fixture");
#else
    check(WIFSIGNALED(status) && WTERMSIG(status)==SIGILL,"RSP recovery native trap before memory");
#endif
    check(!munmap(mem,page*2),"guard unmap");
}
static void store_cases(void)
{
    const __u64 widths[]={0,1,2,4,8,256,0x100000008ULL};
    const __u64 values[]={0,~0ULL,0x123456789abcdef0ULL,0x8000000000000000ULL};
    __u8 memory[80],expected[80];writing=1;
    for (unsigned wi=0;wi<7;wi++) for (unsigned offset=0;offset<32;offset++)
    for (unsigned v=0;v<4;v++) {
        unsigned n=(__u8)widths[wi];if (!n) n=8;
        for (unsigned i=0;i<sizeof(memory);i++) memory[i]=(__u8)(i*29+0x51);
        memcpy(expected,memory,sizeof(memory));
        for (unsigned i=0;i<n;i++) expected[offset+i]=(__u8)(values[v]>>(8*i));
        expected_destination=memory+offset;expected_size=n;reset();
        kprog_x86_store_memory(memory+offset,widths[wi],values[v]);
        check(!draws && !memcmp(memory,expected,sizeof(memory)),"unaligned physical store width/capture/full byte frame");copy_count(1);stores++;
    }
    long page=sysconf(_SC_PAGESIZE);check(page>0,"store page size");
    __u8 *memory_guard=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    check(memory_guard!=MAP_FAILED && !mprotect(memory_guard+page,page,PROT_NONE),"store guard mapping");
    for (unsigned n=1;n<=8;n*=2) {
        memset(memory_guard,0x39,page);expected_destination=memory_guard+page-n;expected_size=n;reset();
        kprog_x86_store_memory(expected_destination,n,0xa1b2c3d4e5f60718ULL);
        for (unsigned i=0;i<n;i++) check(memory_guard[page-n+i]==(__u8)(0xa1b2c3d4e5f60718ULL>>(8*i)),"guarded selected store bytes");
        check(memory_guard[page-n-1]==0x39 && !draws,"guarded store prefix/frame");copy_count(1);
    }
    pid_t pid=fork();check(pid>=0,"store fault fork");
    if (!pid) {
        struct sigaction a={0};a.sa_sigaction=fault;a.sa_flags=SA_SIGINFO;
        if (sigemptyset(&a.sa_mask) || sigaction(SIGSEGV,&a,NULL)) _exit(2);
        fault_address=expected_destination=memory_guard+page;expected_size=8;reset();
        kprog_x86_store_memory(expected_destination,8,~0ULL);_exit(3);
    }
    int status;check(waitpid(pid,&status,0)==pid && WIFEXITED(status) && !WEXITSTATUS(status),"store permission fault/no free input");
    const unsigned invalid[]={3,255};
    for (unsigned i=0;i<2;i++) {
        pid=fork();check(pid>=0,"invalid store-width fork");
        if (!pid) {
            expected_destination=NULL;expected_size=8;reset();
            kprog_x86_store_memory(NULL,invalid[i],~0ULL);_exit(3);
        }
        check(waitpid(pid,&status,0)==pid,"wait invalid store width");
#if defined(__COMPCERT__)
        check(WIFEXITED(status) && WEXITSTATUS(status)==77,"unsupported store width nonreturn fixture");
#else
        check(WIFSIGNALED(status) && WTERMSIG(status)==SIGILL,"unsupported store width native trap");
#endif
    }
    check(!munmap(memory_guard,page*2),"store guard unmap");writing=0;
}
/* Two distinct lanes, absolute-load/null-store asymmetry, released observations
 * and complete metadata/state frames. These execute the exported C bodies. */
static void xmm_cases(void)
{
    const unsigned capacities[]={16,64,200,376},tags[]={0,1,2,3,4,6,255};
    unsigned cases=0;
    _Alignas(8) __u8 bytes[512],initial_bytes[512],expected_bytes[512];
    __u8 fact_tags[47],expected_tags[47];void *pointers[47],*expected_pointers[47];
    struct kprog_x86_stack_fact facts[47];
    struct kprog_x86_arena arena={.b=bytes+64,.q=(void *)(bytes+64),.w=(void *)(bytes+64),.d=(void *)(bytes+64)};
    for (unsigned i=0;i<47;i++) { facts[i].tag=&fact_tags[i];facts[i].pointer=&pointers[i]; }
    for (unsigned c=0;c<4;c++) for (unsigned ti=0;ti<7;ti++)
    for (unsigned route=0;route<3;route++) for (unsigned index=0;index<2;index++)
    for (unsigned release=0;release<3;release++) for (unsigned store=0;store<2;store++)
    for (unsigned odd=0;odd<2;odd++) {
        if (route==2 && store && !index) continue; /* Null store needs a full-width index. */
        unsigned capacity=capacities[c],at=capacity==16?0:(odd?1:capacity-16);
        __s64 off=(__s64)at-capacity,sp=off+(release==0?0:release==1?3:12);
        unsigned reg=route==0?X86_RSP:route==1?X86_RSI:X86_REG_NONE;
        struct x86_sim_register_state state,expected;
        memset(&state,0x6b,sizeof(state));state.is_xdp=0;state.abi_kind=X86_SIM_ABI_KIND_RAW;
        state.rsp.ptr=(void *)(intptr_t)sp;
        __u64 aux=X86_MEM_AUX(index?X86_RDX:X86_REG_NONE,0),imm;
        state.gpr_cells[2].value.ptr=(void *)(intptr_t)1;state.gpr_cells[2].tag=0;
        if (route==0) imm=(__u64)(off-sp-index);
        else if (route==1) {
            state.gpr_cells[6].value.ptr=bytes+64+at-3;state.gpr_cells[6].tag=tags[ti];imm=3-index;
        } else if (!store) imm=(__u64)(uintptr_t)(bytes+64+at-index);
        else { imm=3;state.gpr_cells[2].value.ptr=(void *)((uintptr_t)(bytes+64+at)-3); }
        state.xmm0_lo=0x81a2b3c4d5e6f708ULL;state.xmm0_hi=0x192a3b4c5d6e7f80ULL;
        for (unsigned i=0;i<512;i++) bytes[i]=(__u8)(i*31+0x35);
        for (unsigned i=0;i<47;i++) { fact_tags[i]=(i%3)?4:1;pointers[i]=bytes+i; }
        memcpy(initial_bytes,bytes,sizeof(bytes));memcpy(expected_bytes,bytes,sizeof(bytes));
        memcpy(expected_tags,fact_tags,sizeof(fact_tags));memcpy(expected_pointers,pointers,sizeof(pointers));
        memcpy(&expected,&state,sizeof(state));choice=odd?0x1020304050607081ULL:0xf1e2d3c4b5a69788ULL;reset();
        unsigned recovery=!store && route==1 && tags[ti]==0;
        unsigned skip=recovery && odd,draw_count=recovery;
        if (store) {
            for (unsigned i=0;i<16;i++) {
                __u64 v=i<8?state.xmm0_lo:state.xmm0_hi;
                expected_bytes[64+at+i]=(__u8)(v>>(8*(i%8)));
                if ((route==0 || (route==1 && tags[ti]==4)) && off+i<sp) {
                    expected_bytes[64+at+i]=(__u8)choice;draw_count++;
                }
            }
            for (unsigned i=0;i<(capacity+7)/8;i++)
                if (route==2 || (route==1 && tags[ti]==0) ||
                    ((route==0 || (route==1 && tags[ti]==4)) && i*8<at+16 && i*8+8>at)) {
                    expected_tags[i]=0;expected_pointers[i]=NULL;
                }
        } else if (!skip) {
            expected.xmm0_lo=little(initial_bytes+64+at,8);expected.xmm0_hi=little(initial_bytes+72+at,8);
            if (route==0 || (route==1 && tags[ti]==4)) {
                if (off<sp) { expected.xmm0_lo=choice;draw_count++; }
                if (off+8<sp) { expected.xmm0_hi=choice;draw_count++; }
            }
        }
        paired=1;writing=store;expected_size=8;expected_source=expected_destination=bytes+64+at;
        if (store) kprog_x86_store_xmm0(&state,&arena,facts,capacity,reg,aux,imm);
        else kprog_x86_load_xmm0(&state,&arena,facts,capacity,reg,aux,imm);
        check(!memcmp(&state,&expected,sizeof(state)) && !memcmp(bytes,expected_bytes,sizeof(bytes)),"XMM low/high address/value/whole frame");
        if (draws!=draw_count || memcmp(fact_tags,expected_tags,sizeof(fact_tags)) || memcmp(pointers,expected_pointers,sizeof(pointers)))
            fprintf(stderr,"XMM cap=%u tag=%u route=%u index=%u release=%u store=%u odd=%u draws=%u/%u\n",capacity,tags[ti],route,index,release,store,odd,draws,draw_count);
        check(draws==draw_count && !memcmp(fact_tags,expected_tags,sizeof(fact_tags)) && !memcmp(pointers,expected_pointers,sizeof(pointers)),"XMM recovery/release/metadata frame");
        copy_count(route==0 || skip?0:2);cases++;
    }
    for (unsigned i=0;i<260;i++) {
        __u64 value=i<256?i:(1ULL<<(8*(i-255))),probe=value;__u8 arm;
        KPROG_X86_XMM0_ARM_INTO(arm,probe++);
        check(arm==(value?0:1) && probe==value+1 && kprog_x86_xmm0_arm(value)==arm,"XMM arm full truth/single capture");
        uintptr_t imm=0,reg=0;
        check(KPROG_X86_XMM0_BASE_PTR(1,0,++imm,++reg)==(void *)1 && imm==1 && !reg,"absolute load lazy register");
        check(!KPROG_X86_XMM0_BASE_PTR(1,1,++imm,++reg) && imm==1 && !reg,"null store lazy operands");
        check(KPROG_X86_XMM0_BASE_PTR(0,0,++imm,++reg)==(void *)1 && imm==1 && reg==1,"register lazy immediate");
    }
    paired=writing=0;printf("XMM: %u two-lane/full-frame cases,260 selector/lazy cases\n",cases);
}
/* C execution prefixes only: a second-lane fault must retain the low commit,
 * draw order and store fact invalidation. ISA exception correspondence is M5. */
static void xmm_faults(void)
{
    long page=sysconf(_SC_PAGESIZE);check(page>0,"XMM fault page");
    struct prefix { struct x86_sim_register_state state; __u8 tags[2];void *pointers[2]; };
    struct prefix *p=mmap(NULL,page,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    __u8 *mem=mmap(NULL,page*2,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    check(p!=MAP_FAILED && mem!=MAP_FAILED && !mprotect(mem+page,page,PROT_NONE),"XMM prefix mappings");
    for (unsigned store=0;store<2;store++) {
        memset(p,0,sizeof(*p));memset(mem+page-8,0x35,8);
        p->state.abi_kind=X86_SIM_ABI_KIND_RAW;p->state.gpr_cells[6].value.ptr=mem+page-8;
        p->state.gpr_cells[6].tag=X86_SIM_TAG_STACK;
        p->state.xmm0_lo=0x123456789abcdef0ULL;p->state.xmm0_hi=0xa1b2c3d4e5f60718ULL;
        for (unsigned i=0;i<2;i++) { p->tags[i]=4;p->pointers[i]=mem; }
        pid_t pid=fork();check(pid>=0,"XMM prefix fork");
        if (!pid) {
            struct sigaction a={0};a.sa_sigaction=fault;a.sa_flags=SA_SIGINFO;
            if (sigemptyset(&a.sa_mask) || sigaction(SIGSEGV,&a,NULL)) _exit(2);
            struct kprog_x86_arena arena={.b=mem+page-8};
            struct kprog_x86_stack_fact facts[2]={{&p->tags[0],&p->pointers[0]},{&p->tags[1],&p->pointers[1]}};
            fault_address=mem+page;fault_draws=store?8:1;choice=0x8877665544332211ULL;
            expected_source=expected_destination=mem+page-8;expected_size=8;paired=1;writing=store;reset();
            if (store) kprog_x86_store_xmm0(&p->state,&arena,facts,16,X86_RSI,X86_MEM_AUX(X86_REG_NONE,0),0);
            else kprog_x86_load_xmm0(&p->state,&arena,facts,16,X86_RSI,X86_MEM_AUX(X86_REG_NONE,0),0);
            _exit(3);
        }
        int status;check(waitpid(pid,&status,0)==pid && WIFEXITED(status) && !WEXITSTATUS(status),"XMM second-lane fault/draw prefix");
        check(p->state.xmm0_hi==0xa1b2c3d4e5f60718ULL && p->state.xmm0_lo==(store?0x123456789abcdef0ULL:0x8877665544332211ULL),"XMM low commit/high frame on fault");
        for (unsigned i=0;i<2;i++) check(p->tags[i]==(store?0:4) && p->pointers[i]==(store?NULL:mem),"XMM erase before second store fault");
        for (unsigned i=0;i<8;i++) check(mem[page-8+i]==(store?0x11:0x35),"XMM low store/released prefix");
    }
    check(!munmap(p,page) && !munmap(mem,page*2),"XMM prefix unmap");
    puts("XMM: 2 guarded second-lane C-prefix probes");
}
/* Decode conditions independently, including parity and noncanonical flag
 * bytes. Writer composition uses the separately checked exported primitive. */
static __u64 condition(unsigned cc,const struct x86_sim_register_state *s)
{
    const unsigned values[]={s->of,!s->of,s->cf,!s->cf,s->zf,!s->zf,
        s->cf||s->zf,!s->cf&&!s->zf,s->sf,!s->sf,s->pf,!s->pf,
        s->sf!=s->of,s->sf==s->of,s->zf||s->sf!=s->of,!s->zf&&s->sf==s->of};
    return cc<16?values[cc]:0;
}
static void conditional_cases(void)
{
    const unsigned widths[]={0,1,2,4,8,255},capacities[]={16,64,200,376};
    const unsigned tags[]={0,1,2,4,255},destinations[]={0,4,6,255},shifts[]={0,8,9,255};
    _Alignas(8) __u8 bytes[512],saved[512],expected_bytes[512];
    __u8 ft[47],saved_ft[47],expected_ft[47];void *fp[47],*saved_fp[47],*expected_fp[47];
    struct kprog_x86_stack_fact facts[47];
    struct kprog_x86_arena arena={.b=bytes+64,.q=(void *)(bytes+64),.w=(void *)(bytes+64),.d=(void *)(bytes+64)};
    unsigned counts[4]={0};
    for (unsigned i=0;i<47;i++) { facts[i].tag=&ft[i];facts[i].pointer=&fp[i]; }
    for (unsigned op=0;op<4;op++) for (unsigned c=0;c<4;c++)
    for (unsigned ci=0;ci<32;ci++) for (unsigned f=0;f<34;f++)
    for (unsigned route=0;route<3;route++) for (unsigned wi=0;wi<(op<2?6:1);wi++) {
        unsigned capacity=capacities[c],at=capacity-8-(f&1),width=widths[wi]?widths[wi]:8;
        unsigned cc=ci<16?ci:op==0?0x100+ci-16:240+ci-16;
        unsigned dst=op==3?(route==0?4:route==1?6:255):destinations[ci%4];
        unsigned src=route==0?4:route==1?6:255,tag=tags[(f/2)%5];
        unsigned indexed=route==2 || (f&1),n=op==3?1:(width==255 || (f&1))?4:width;
        __s64 off=(__s64)at-capacity,sp=off+(f%3==0?0:f%3==1?1:5),disp=route==0?off-sp-indexed:-3;
        struct x86_sim_register_state state,initial,expected;
        memset(&state,0x6b,sizeof(state));state.abi_kind=X86_SIM_ABI_KIND_RAW;state.is_xdp=0;
        state.cf=f&1;state.zf=(f>>1)&1;state.sf=(f>>2)&1;state.of=(f>>3)&1;state.pf=(f>>4)&1;
        if (f>=32) { state.of=2;state.sf=255;state.pf=f==32?2:255;state.cf=255;state.zf=0; }
        state.native_stack_base=0x100000;state.rsp.ptr=(void *)(intptr_t)sp;
        state.gpr_cells[6].value.ptr=bytes+64+at-disp-indexed;state.gpr_cells[6].tag=tag;
        state.gpr_cells[2].value.ptr=(void *)(uintptr_t)(route==2?(uintptr_t)(bytes+64+at)-disp:1);state.gpr_cells[2].tag=0;
        __u32 aux=op==0?cc:op==2?cc|(shifts[ci%4]<<8):
            X86_MEM_AUX(indexed?2:X86_REG_NONE,0)|(n<<16)|((cc&255)<<24);
        /* Exercise both memory-width fallback and explicit override. */
        if (op==1 && width!=255 && !(f&1)) aux&=~0xff0000U;
        __u64 imm=op==1?((__u64)(__u32)disp<<32)|0x12345678U:(__u64)disp;
        unsigned recovery=op==1 && route==1 && tag==0,rejected=recovery && (f&1);
        if (rejected && dst==4) continue; /* Nonreturn probe below. */
        choice=(f&1)?0x8192a3b4c5d6e7f9ULL:0x8192a3b4c5d6e7f8ULL;
        for (unsigned i=0;i<512;i++) bytes[i]=(__u8)(i*29+0x57);
        for (unsigned i=0;i<47;i++) { ft[i]=4;fp[i]=bytes+i; }
        memcpy(saved,bytes,sizeof(bytes));memcpy(saved_ft,ft,sizeof(ft));memcpy(saved_fp,fp,sizeof(fp));
        memcpy(&initial,&state,sizeof(state));memcpy(&expected,&state,sizeof(state));reset();
        __u64 truth=condition(cc,&state),value=0;unsigned physical=0;
        if (op==0) value=kprog_x86_read_reg(&state,&arena,capacity,src,8,0);
        if (op==1 && !rejected) {
            value=little(bytes+64+at,n);physical=route!=0;
            if ((route==0 || (route==1 && tag==4 && indexed)) && off<sp) {
                value=choice & (n==8?~0ULL:(1ULL<<(8*n))-1);draws++;
            }
        }
        if (recovery) draws++;
        if (op<2) {
            if (rejected) kprog_x86_write_reg(&expected,&arena,facts,capacity,dst,0,8,0);
            else if (truth) {
                if (op==0 && width==8) kprog_x86_mov_reg(&expected,&arena,facts,capacity,dst,src,8,0);
                else kprog_x86_write_reg(&expected,&arena,facts,capacity,dst,value,width,0);
            } else if (width==4) kprog_x86_write_reg(&expected,&arena,facts,capacity,dst,
                kprog_x86_read_reg(&expected,&arena,capacity,dst,8,0),4,0);
        } else if (op==2) kprog_x86_write_reg(&expected,&arena,facts,capacity,dst,truth,1,shifts[ci%4]==8?8:0);
        else {
            bytes[64+at]=(__u8)truth;physical=route!=0;
            if ((route==0 || (route==1 && tag==4)) && off<sp) { bytes[64+at]=(__u8)choice;draws++; }
            for (unsigned i=0;i<(capacity+7)/8;i++)
                if (route==2 || (route==1 && tag==0) || ((route==0 || tag==4) && i==at/8)) { ft[i]=0;fp[i]=NULL; }
        }
        unsigned expected_draws=draws;
        memcpy(expected_bytes,bytes,sizeof(bytes));memcpy(expected_ft,ft,sizeof(ft));memcpy(expected_fp,fp,sizeof(fp));
        memcpy(bytes,saved,sizeof(bytes));memcpy(ft,saved_ft,sizeof(ft));memcpy(fp,saved_fp,sizeof(fp));
        memcpy(&state,&initial,sizeof(state));reset();writing=op==3;expected_source=expected_destination=bytes+64+at;expected_size=n;
        if (op==0) kprog_x86_cmov(&state,&arena,facts,capacity,dst,src,widths[wi],aux);
        if (op==1) kprog_x86_cmov_mem(&state,&arena,facts,capacity,dst,src,widths[wi],aux,imm);
        if (op==2) kprog_x86_setcc(&state,&arena,facts,capacity,dst,aux);
        if (op==3) kprog_x86_setcc_mem(&state,&arena,facts,capacity,dst,aux,imm);
        if (memcmp(&state,&expected,sizeof(state)) || memcmp(bytes,expected_bytes,sizeof(bytes)) || draws!=expected_draws)
            fprintf(stderr,"conditional op=%u cap=%u cc=%u f=%u route=%u width=%u draws=%u/%u\n",op,capacity,cc,f,route,width,draws,expected_draws);
        check(!memcmp(&state,&expected,sizeof(state)) && !memcmp(bytes,expected_bytes,sizeof(bytes)) &&
            !memcmp(ft,expected_ft,sizeof(ft)) && !memcmp(fp,expected_fp,sizeof(fp)) && draws==expected_draws,"conditional source/condition/writer/complete frame");
        copy_count(physical);counts[op]++;
    }
    writing=0;
    const __u64 extra[]={256,0x100000008ULL,0x1000000ffULL,~0ULL};
    for (unsigned i=0;i<260;i++) {
        __u64 v=i<256?i:extra[i-256],p=v;__u8 out;
        KPROG_X86_CMOV_WRITEBACK_INTO(out,p++);check(out==(v?0:1) && p==v+1 && kprog_x86_cmov_writeback(v)==out,"CMOV truth/capture");
        p=v;KPROG_X86_SETCC_LANE_INTO(out,p++);check(out==(v==8) && p==v+1 && kprog_x86_setcc_lane(v)==out,"SETCC full lane/capture");
        p=v;KPROG_X86_SETCC_MEM_BASE_INTO(out,p++);check(out==(v==255?0:1) && p==v+1 && kprog_x86_setcc_mem_base(v)==out,"SETCC full base/capture");
        p=v;KPROG_X86_SETCC_MEM_ARM_INTO(out,p++);check(out==(v?0:1) && p==v+1 && kprog_x86_setcc_mem_arm(v)==out,"SETCC arm truth/capture");
    }
    printf("conditional full frames: CMOV=%u CMOVmem=%u SETCC=%u SETCCmem=%u;260 selector groups\n",counts[0],counts[1],counts[2],counts[3]);
}
static void conditional_faults(void)
{
    long page=sysconf(_SC_PAGESIZE);check(page>0,"conditional page");
    void *mem=mmap(NULL,page,PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    struct x86_sim_register_state *s=mmap(NULL,page,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0),initial;
    check(mem!=MAP_FAILED && s!=MAP_FAILED,"conditional guard mappings");
    for (unsigned indexed=0;indexed<2;indexed++) {
        memset(s,0x5a,sizeof(*s));s->abi_kind=X86_SIM_ABI_KIND_RAW;s->is_xdp=0;
        s->gpr_cells[6].tag=4;s->gpr_cells[6].value.ptr=(void *)((uintptr_t)mem-indexed);
        s->gpr_cells[2].tag=0;s->gpr_cells[2].value.ptr=(void *)1;memcpy(&initial,s,sizeof(initial));
        pid_t pid=fork();check(pid>=0,"false CMOV fork");
        if (!pid) {
            struct sigaction a={0};a.sa_sigaction=fault;a.sa_flags=SA_SIGINFO;
            if (sigemptyset(&a.sa_mask) || sigaction(SIGSEGV,&a,NULL)) _exit(2);
            fault_address=expected_source=mem;expected_size=4;fault_draws=0;reset();
            kprog_x86_cmov_mem(s,NULL,NULL,0,0,6,4,X86_MEM_AUX(indexed?2:X86_REG_NONE,0)|(16U<<24),0);_exit(3);
        }
        int status;check(waitpid(pid,&status,0)==pid && WIFEXITED(status) && !WEXITSTATUS(status),"false CMOV physical fault before release/condition");
        check(!memcmp(s,&initial,sizeof(initial)),"false CMOV fault precedes 32-bit zero extension");
    }
    pid_t pid=fork();check(pid>=0,"CMOV recovery fork");
    if (!pid) {
        memset(s,0,sizeof(*s));s->abi_kind=X86_SIM_ABI_KIND_RAW;
        kprog_x86_cmov_mem(s,NULL,NULL,0,4,6,8,X86_MEM_AUX(X86_REG_NONE,0)|(16U<<24),0);_exit(3);
    }
    int status;check(waitpid(pid,&status,0)==pid,"CMOV recovery wait");
#if defined(__COMPCERT__)
    check(WIFEXITED(status) && WEXITSTATUS(status)==77,"false CMOV RSP recovery nonreturn");
#else
    check(WIFSIGNALED(status) && WTERMSIG(status)==SIGILL,"false CMOV RSP recovery native trap");
#endif
    check(!munmap(s,page) && !munmap(mem,page),"conditional guard unmap");
    puts("conditional: 2 false-condition first-fault frames,1 RSP recovery nonreturn");
}
int main(void)
{
    selector_cases();read_cases();handler_cases();guarded();store_cases();xmm_cases();xmm_faults();conditional_cases();conditional_faults();
    printf("x86 shared memory/MOVBE:260 selector cases,%lu read/frame cases,%lu handler/frame cases,7 read probes,%lu store/frame cases,7 store guard/fault/refusal probes\n",reads,handlers,stores);
    return 0;
}
