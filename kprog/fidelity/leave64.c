#define _GNU_SOURCE
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <ucontext.h>
#include <unistd.h>
struct state { uint64_t r[16],flags; };
struct state observed;
uintptr_t saved_rsp;
extern void observe_leave(const struct state *);
extern char leave_pc,leave_next;
static sigjmp_buf recover;
static volatile sig_atomic_t signal_number,trap_number,error_code;
static uint64_t fault_pc,fault_address;
static uint64_t seed=UINT64_C(0x6b70726f67464c56);
static uint64_t random_word(void){seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;return seed;}
static void handler(int sig,siginfo_t *info,void *context){
 ucontext_t *u=context;
 if((uintptr_t)u->uc_mcontext.gregs[REG_RIP]!=(uintptr_t)&leave_pc)_exit(128+sig);
 const int regs[]={REG_RAX,REG_RCX,REG_RDX,REG_RBX,REG_RSP,REG_RBP,REG_RSI,REG_RDI,REG_R8,REG_R9,REG_R10,REG_R11,REG_R12,REG_R13,REG_R14,REG_R15};
 for(unsigned i=0;i<16;i++)observed.r[i]=u->uc_mcontext.gregs[regs[i]];
 observed.flags=u->uc_mcontext.gregs[REG_EFL];
 signal_number=sig;trap_number=u->uc_mcontext.gregs[REG_TRAPNO];error_code=u->uc_mcontext.gregs[REG_ERR];
 fault_pc=u->uc_mcontext.gregs[REG_RIP];fault_address=(uintptr_t)info->si_addr;
 siglongjmp(recover,1);
}
static void execute(const struct state *initial){
 if(sigsetjmp(recover,1)==0)observe_leave(initial);
}
static void state_json(FILE *f,const struct state *s){
 fputs("{\"registers\":[",f);for(unsigned i=0;i<16;i++)fprintf(f,"%s%"PRIu64,i?",":"",s->r[i]);fprintf(f,"],\"flags\":%"PRIu64"}",s->flags);
}
static void fail(const char *s){perror(s);exit(1);}
int main(int argc,char **argv){
 if(argc!=2){fputs("usage: leave64 OUTPUT_DIRECTORY\n",stderr);return 1;}
 long page=sysconf(_SC_PAGESIZE);if(page<4096)fail("page size");
 unsigned char *area=mmap(0,3*(size_t)page,PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);if(area==MAP_FAILED)fail("mmap");
 unsigned char *mem=area+page;if(mprotect(mem,(size_t)page,PROT_READ|PROT_WRITE))fail("mprotect");
 unsigned char *before=malloc((size_t)page);if(!before)fail("malloc");
 stack_t alt={.ss_sp=malloc(SIGSTKSZ*4),.ss_size=SIGSTKSZ*4};if(!alt.ss_sp||sigaltstack(&alt,0))fail("sigaltstack");
 struct sigaction sa={.sa_sigaction=handler,.sa_flags=SA_SIGINFO|SA_ONSTACK};sigemptyset(&sa.sa_mask);
 if(sigaction(SIGSEGV,&sa,0)||sigaction(SIGBUS,&sa,0)||sigaction(SIGILL,&sa,0))fail("sigaction");
 char path[4096];snprintf(path,sizeof(path),"%s/cases.jsonl",argv[1]);FILE *raw=fopen(path,"w");if(!raw)fail("cases output");
 snprintf(path,sizeof(path),"%s/forms.tsv",argv[1]);FILE *table=fopen(path,"w");if(!table)fail("input_class output");
 fputs("input_class\tcases\tsuccesses\tfaults\tsuccess_mismatches\tmemory_writes\tfault_rsp_input\tfault_rsp_frame\tfault_all_gprs_input\n",table);
 const char *names[]={"aligned_frame","unaligned_frame","last_readable_word","cross_page_frame","protected_frame","noncanonical_frame","null_frame","valid_frame_bad_sp"};
 unsigned total_bad=0;
 for(unsigned group=0;group<8;group++){
  unsigned successes=0,faults=0,bad=0,writes=0,rsp_input=0,rsp_frame=0,gprs_input=0;
  for(unsigned k=0;k<1024;k++){
   for(long n=0;n<page;n++){mem[n]=(unsigned char)random_word();}memcpy(before,mem,(size_t)page);
   struct state initial;for(unsigned i=0;i<16;i++)initial.r[i]=random_word();initial.flags=(random_word()&0x8d5)|0x202;
   initial.r[4]=(uintptr_t)(mem+128);uintptr_t bp=(uintptr_t)(mem+256+(random_word()%128)*8);
   if(group==1)bp+=1+random_word()%7;
   if(group==2)bp=(uintptr_t)(mem+page-8);
   if(group==3)bp=(uintptr_t)(mem+page-7);
   if(group==4)bp=(uintptr_t)(mem+page);
   if(group==5)bp=UINT64_C(0x0100000000000000);
   if(group==6)bp=0;
   if(group==7)initial.r[4]=UINT64_C(0x0100000000000000);
   initial.r[5]=bp;signal_number=trap_number=error_code=0;fault_pc=fault_address=0;
   execute(&initial);
   unsigned changed=memcmp(before,mem,(size_t)page)!=0;writes+=changed;
   unsigned mismatch=0;
   if(signal_number){faults++;rsp_input+=observed.r[4]==initial.r[4];rsp_frame+=observed.r[4]==initial.r[5];gprs_input+=memcmp(observed.r,initial.r,sizeof(initial.r))==0;}
   else{
    successes++;struct state expected=initial;uint64_t loaded=0;
    if(bp<(uintptr_t)mem||bp+8>(uintptr_t)(mem+page)){mismatch=1;}
    else{memcpy(&loaded,(void *)bp,8);expected.r[4]=bp+8;expected.r[5]=loaded;mismatch=memcmp(expected.r,observed.r,sizeof(expected.r))!=0||((expected.flags^observed.flags)&0x8d5)!=0;}
    bad+=mismatch;
   }
   fprintf(raw,"{\"input_class\":\"%s\",\"case\":%u,\"input\":",names[group],k);state_json(raw,&initial);fputs(",\"observed\":",raw);state_json(raw,&observed);
   fprintf(raw,",\"signal\":%d,\"trap\":%d,\"error\":%d,\"fault_pc\":%"PRIu64",\"fault_address\":%"PRIu64",\"next_pc\":%"PRIuPTR",\"memory_changed\":%u,\"success_mismatch\":%u,\"readable_bytes\":[",signal_number,trap_number,error_code,fault_pc,fault_address,(uintptr_t)&leave_next,changed,mismatch);
   unsigned n=0;while(n<8&&bp+n>=(uintptr_t)mem&&bp+n<(uintptr_t)(mem+page)){fprintf(raw,"%s%u",n?",":"",*(unsigned char *)(bp+n));n++;}fputs("]}\n",raw);
  }
  fprintf(table,"%s\t1024\t%u\t%u\t%u\t%u\t%u\t%u\t%u\n",names[group],successes,faults,bad,writes,rsp_input,rsp_frame,gprs_input);total_bad+=bad+writes;
 }
 if(fclose(raw)||fclose(table))fail("close output");
 printf("LEAVE64 forms=1 input_classes=8 cases=8192 success_mismatches_or_memory_writes=%u\n",total_bad);return total_bad?1:0;
}
