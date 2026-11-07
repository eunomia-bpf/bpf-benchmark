#define _GNU_SOURCE
#include <linux/bpf.h>
#include <bpf/bpf.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
static uint64_t ns(void){struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);return (uint64_t)t.tv_sec*1000000000+t.tv_nsec;}
int main(int argc,char **argv){
 if(argc!=5){fprintf(stderr,"usage: fixed-run test|open|smoke ID COUNT INPUT\n");return 2;}
 unsigned id=strtoul(argv[2],0,10),count=strtoul(argv[3],0,10);
 int fd=-1;if(id){fd=bpf_prog_get_fd_by_id(id);if(fd<0){perror("prog fd");return 2;}}
 if(strcmp(argv[1],"info")==0 || strcmp(argv[1],"dump")==0){
  struct bpf_prog_info info={0};struct bpf_func_info func={0};uint64_t syms[32]={0};uint32_t lens[32]={0};
  info.func_info=(uint64_t)(uintptr_t)&func;info.nr_func_info=1;info.func_info_rec_size=sizeof(func);
  info.jited_ksyms=(uint64_t)(uintptr_t)syms;info.nr_jited_ksyms=32;
  info.jited_func_lens=(uint64_t)(uintptr_t)lens;info.nr_jited_func_lens=32;
  uint32_t info_len=sizeof(info);
  if(bpf_obj_get_info_by_fd(fd,&info,&info_len)<0){perror("prog info");return 2;}
  if(strcmp(argv[1],"dump")==0){
   unsigned size=info.jited_prog_len;void *bytes=malloc(size);
   if(!size||!bytes){fprintf(stderr,"empty JIT image or allocation failure\n");return 2;}
   /* First query reports counts even for unrequested arrays. A fresh request
    * asks only for the byte buffer, preventing NULL line/map/tag copies. */
   struct bpf_prog_info dump={.jited_prog_len=size,.jited_prog_insns=(uint64_t)(uintptr_t)bytes};
   uint32_t dump_len=sizeof(dump);
   if(bpf_obj_get_info_by_fd(fd,&dump,&dump_len)<0){perror("JIT info");return 2;}
   if(dump.jited_prog_len!=size){fprintf(stderr,"JIT size changed\n");return 2;}
   FILE *f=fopen(argv[4],"wb");if(!f){perror("JIT output");return 2;}
   if(fwrite(bytes,1,size,f)!=size||fclose(f)){perror("JIT write");return 2;}free(bytes);
  }
  printf("{\"id\":%u,\"name\":\"%s\",\"type\":%u,\"btf_id\":%u,\"func_type_id\":%u,\"run_cnt\":%llu,\"run_time_ns\":%llu,\"jited_len\":%u,\"jited_addr\":\"0x%llx\",\"first_jited_func_len\":%u}\n",id,info.name,info.type,info.btf_id,func.type_id,(unsigned long long)info.run_cnt,(unsigned long long)info.run_time_ns,info.jited_prog_len,(unsigned long long)syms[0],lens[0]);close(fd);return 0;
 }
 unsigned char input[512]={0},output[4096]={0},gold[4096]={0};unsigned size=0,gold_size=0,gold_ret=0;
 if(strcmp(argv[1],"open")==0){
  uint64_t start=ns();for(unsigned i=0;i<count;i++){int f=open("/dev/null",O_RDONLY|O_CLOEXEC);if(f<0){perror("open");return 2;}close(f);}
  printf("{\"kind\":\"open_dev_null\",\"count\":%u,\"open_calls\":%u,\"close_calls\":%u,\"elapsed_ns\":%llu}\n",count,count,count,(unsigned long long)(ns()-start));return 0;
 }
 FILE *f=fopen(argv[4],"rb");if(!f){perror("input");return 2;}size=fread(input,1,sizeof(input),f);fclose(f);
 uint64_t start=ns(),duration=0;unsigned complete=0;
 for(unsigned i=0;i<count;i++){
  struct bpf_test_run_opts opts={.sz=sizeof(opts),.data_in=input,.data_size_in=size,.data_out=output,.data_size_out=sizeof(output),.repeat=1};
  errno=0;int rc=bpf_prog_test_run_opts(fd,&opts);int err=errno;
  if(rc<0){printf("{\"kind\":\"test_run\",\"prog_id\":%u,\"completed\":%u,\"errno\":%d,\"error\":\"%s\"}\n",id,complete,err,strerror(err));return strcmp(argv[1],"smoke")==0?0:1;}
  if(!i){gold_size=opts.data_size_out;gold_ret=opts.retval;if(gold_size>sizeof(gold))return 3;memcpy(gold,output,gold_size);}
  else if(opts.data_size_out!=gold_size||opts.retval!=gold_ret||memcmp(gold,output,gold_size)){fprintf(stderr,"nonidentical output at run%u\n",i);return 3;}
  duration+=opts.duration;complete++;
 }
 uint64_t hash=1469598103934665603ULL;for(unsigned i=0;i<gold_size;i++){hash^=gold[i];hash*=1099511628211ULL;}
 printf("{\"kind\":\"fresh_input_test_run\",\"prog_id\":%u,\"count\":%u,\"retval\":%u,\"output_size\":%u,\"output_fnv64\":\"%016llx\",\"test_duration_sum_ns\":%llu,\"elapsed_ns\":%llu}\n",id,complete,gold_ret,gold_size,(unsigned long long)hash,(unsigned long long)duration,(unsigned long long)(ns()-start));
 close(fd);return 0;
}
