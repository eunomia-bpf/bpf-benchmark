#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <elf.h>
#include <sys/syscall.h>
#include <linux/bpf.h>
static char log[1<<21];
int main(int argc,char**argv){
  FILE*f=fopen(argv[1],"rb");fseek(f,0,SEEK_END);long n=ftell(f);rewind(f);
  unsigned char*buf=malloc(n);if(fread(buf,1,n,f)!=(size_t)n)return 2;fclose(f);
  Elf64_Ehdr*eh=(Elf64_Ehdr*)buf;Elf64_Shdr*sh=(Elf64_Shdr*)(buf+eh->e_shoff);
  const char*st=(char*)buf+sh[eh->e_shstrndx].sh_offset;
  int idx=-1;for(int i=0;i<eh->e_shnum;i++)if(!strcmp(st+sh[i].sh_name,argv[2]))idx=i;
  union bpf_attr a;memset(&a,0,sizeof a);
  a.prog_type=atoi(argv[3]);a.insns=(unsigned long)(buf+sh[idx].sh_offset);
  a.insn_cnt=sh[idx].sh_size/8;a.license=(unsigned long)"GPL";
  a.log_buf=(unsigned long)log;a.log_size=sizeof log;a.log_level=7;
  int fd=syscall(__NR_bpf,BPF_PROG_LOAD,&a,sizeof a);
  if(fd>=0){printf("ACCEPT\n");return 0;}
  printf("REJECT errno=%d\n",errno);
  fputs(log,stdout);
  return 1;
}
