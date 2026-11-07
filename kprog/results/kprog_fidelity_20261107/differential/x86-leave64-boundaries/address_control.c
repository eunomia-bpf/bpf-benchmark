#define _GNU_SOURCE
#include <cpuid.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <unistd.h>
extern char control_ds_pc,control_ss_pc;
static sigjmp_buf recover;
static volatile sig_atomic_t sig_number,trap_number,error_code;
static uintptr_t expected_pc,seen_pc,fault_address;
__attribute__((noinline,noclone)) static void load_ds(uint64_t address){
 __asm__ volatile(".global control_ds_pc\ncontrol_ds_pc:\nmovq (%%rdi),%%rax"::"D"(address):"rax","memory");
}
__attribute__((noinline,noclone)) static void load_ss(uint64_t address){
 __asm__ volatile("movq %%rdi,%%rbp\n.global control_ss_pc\ncontrol_ss_pc:\nmovq (%%rbp),%%rax"::"D"(address):"rax","rbp","memory");
}
static void handler(int sig,siginfo_t *info,void *context){
 ucontext_t *u=context;seen_pc=(uintptr_t)u->uc_mcontext.gregs[REG_RIP];
 if(seen_pc!=expected_pc)_exit(128+sig);
 sig_number=sig;trap_number=u->uc_mcontext.gregs[REG_TRAPNO];error_code=u->uc_mcontext.gregs[REG_ERR];fault_address=(uintptr_t)info->si_addr;siglongjmp(recover,1);
}
static void execute(unsigned kind,uint64_t address){
 if(sigsetjmp(recover,1)==0)(kind?load_ss:load_ds)(address);
}
static void probe(FILE *f,const char *name,uint64_t address,unsigned valid){
 for(unsigned kind=0;kind<2;kind++)for(unsigned n=0;n<32;n++){
  expected_pc=(uintptr_t)(kind?&control_ss_pc:&control_ds_pc);sig_number=trap_number=error_code=0;seen_pc=fault_address=0;execute(kind,address);
  if(valid&&sig_number){fputs("mapped control fault\n",stderr);exit(1);}
  fprintf(f,"%s\t%s\t%u\t%"PRIu64"\t%d\t%d\t%d\t%"PRIuPTR"\t%"PRIuPTR"\n",name,kind?"mov_ss":"mov_ds",n,address,sig_number,trap_number,error_code,seen_pc,fault_address);
 }
}
int main(int argc,char **argv){
 if(argc!=3){fputs("usage: address-control INPUT_TSV OUTPUT_DIR\n",stderr);return 1;}
 struct sigaction sa={.sa_sigaction=handler,.sa_flags=SA_SIGINFO};sigemptyset(&sa.sa_mask);
 if(sigaction(SIGSEGV,&sa,0)||sigaction(SIGBUS,&sa,0)||sigaction(SIGILL,&sa,0)){perror("sigaction");return 1;}
 char path[4096];snprintf(path,sizeof(path),"%s/control-cases.tsv",argv[2]);FILE *f=fopen(path,"w");FILE *input=fopen(argv[1],"r");if(!f||!input){perror("open");return 1;}
 fputs("input_class\tinstruction\tcase\taddress\tsignal\ttrap\terror\tfault_pc\tfault_address\n",f);
 uint64_t word=UINT64_C(0x6b70726f67464c56);probe(f,"mapped_control",(uintptr_t)&word,1);
 char name[64];uint64_t address;unsigned count=0;int scanned;
 while((scanned=fscanf(input,"%63s %"SCNx64,name,&address))==2){probe(f,name,address,0);count++;}
 if(scanned!=EOF||ferror(input)||count!=31||word!=UINT64_C(0x6b70726f67464c56)){fputs("incomplete inputs or memory mutation\n",stderr);return 1;}
 if(fclose(input)||fclose(f)){perror("close");return 1;}
 unsigned a=0,b=0,c=0,d=0,lass=0;
 if(__get_cpuid_count(7,1,&a,&b,&c,&d))lass=(a>>6)&1;
 snprintf(path,sizeof(path),"%s/control-profile.json",argv[2]);f=fopen(path,"w");if(!f){perror("profile");return 1;}
 fprintf(f,"{\"cpuid_lass_supported\":%u,\"cpuid_leaf7_subleaf1_eax\":%u,\"samples\":2048,\"instructions\":2,\"cases_per_address_instruction\":32}\n",lass,a);
 if(fclose(f)){perror("close profile");return 1;}
 puts("DS/SS controls: 2048 samples complete");return 0;
}
