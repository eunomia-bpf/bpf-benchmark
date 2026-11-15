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
    check((writing?dst==expected_destination:src==expected_source) && size==expected_size && alignment==1,"physical copy source/destination/size/alignment");
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
static void fault(int sig,siginfo_t *info,void *context)
{ (void)context;_exit(sig==SIGSEGV && info->si_addr==fault_address && !draws?0:1); }
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
int main(void)
{
    selector_cases();read_cases();handler_cases();guarded();store_cases();
    printf("x86 shared memory/MOVBE:260 selector cases,%lu read/frame cases,%lu handler/frame cases,7 read probes,%lu store/frame cases,7 store guard/fault/refusal probes\n",reads,handlers,stores);
    return 0;
}
