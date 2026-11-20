/* Detect swapped task offsets, lost signed extension, null-task mismatch,
 * or merging repeated helper visits across a real external call. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
static const void *visits[2];
static unsigned next_visit,generic_calls;
extern uint64_t call_pid(void),two_pids(void);
unsigned long long bpf_get_current_task(void)
{ assert(next_visit<2);return (uintptr_t)visits[next_visit++]; }
__attribute__((weak)) unsigned long long bpf_get_current_pid_tgid(void)
{
    const char *task=(void *)(uintptr_t)bpf_get_current_task();int pid,tgid;
    ++generic_calls;
    if(!task)return (uint64_t)-22;
    memcpy(&pid,task+PID,4);memcpy(&tgid,task+TGID,4);
    return ((uint64_t)tgid<<32)|pid;
}
int main(void)
{
    struct vector {int pid,tgid;uint64_t want;} vectors[]={
        {1,2,UINT64_C(0x0000000200000001)},
        {0x7fffffff,(int)0x80000000U,UINT64_C(0x800000007fffffff)},
        {-1,1,UINT64_MAX},
        {(int)0x80000000U,0,UINT64_C(0xffffffff80000000)},
        {0,-1,UINT64_C(0xffffffff00000000)},
        {42,42,UINT64_C(0x0000002a0000002a)}};
    long page=sysconf(_SC_PAGESIZE);assert(page>0);
    size_t bytes=((MAX_OFFSET+4+page-1)/page)*page;
    char *memory=mmap(NULL,(bytes+page)*6,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(memory!=MAP_FAILED);
    const void *tasks[7];uint64_t expected[7];unsigned cases=0;
    for(unsigned i=0;i<6;++i){
        char *guard=memory+i*(bytes+page)+bytes;
        assert(!mprotect(guard,page,PROT_NONE));
        char *task=guard-MAX_OFFSET-4;
        memcpy(task+PID,&vectors[i].pid,4);memcpy(task+TGID,&vectors[i].tgid,4);
        tasks[i]=task;expected[i]=vectors[i].want;
    }
    tasks[6]=NULL;expected[6]=(uint64_t)-22;
    for(unsigned i=0;i<7;++i){
        visits[0]=tasks[i];next_visit=0;
        assert(call_pid()==expected[i]&&next_visit==1);++cases;
        for(unsigned j=0;j<7;++j){
            visits[0]=tasks[i];visits[1]=tasks[j];next_visit=0;
            assert(two_pids()==(expected[i]^(expected[j]<<1))&&next_visit==2);++cases;
        }
    }
    assert(generic_calls==(BEFORE ? 105U : 0U));
    assert(!munmap(memory,(bytes+page)*6));
    printf("%u PID/null/signed/guard/repeated-visit cases; generic PID calls %u\n",cases,generic_calls);
}
