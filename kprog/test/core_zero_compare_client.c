/* Compare emitted native IR code with original ELF instructions patched by
 * libbpf and executed by the sole stock kernel. */
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#define REQUIRE(C) do { if (!(C)) { fprintf(stderr,"line %d: %s\n",__LINE__,#C); return 1; } } while (0)

int main(int argc,char **argv)
{
    REQUIRE(argc == 4);
    unsigned offset;
    REQUIRE(sscanf(argv[3],"%u",&offset)==1 && offset+8<=4096);
    FILE *file=fopen(argv[1],"rb"); REQUIRE(file);
    REQUIRE(fseek(file,0,SEEK_END)==0);
    long bytes=ftell(file); REQUIRE(bytes>0 && bytes%8==0);
    REQUIRE(fseek(file,0,SEEK_SET)==0);
    size_t prefix=10,count=(size_t)bytes/8;
    struct bpf_insn *code=calloc(prefix+count,sizeof(*code));REQUIRE(code);
    REQUIRE(fread(code+prefix,1,bytes,file)==(size_t)bytes && fclose(file)==0);
    void *handle=dlopen(argv[2],RTLD_NOW);if (!handle) fprintf(stderr,"%s\n",dlerror());REQUIRE(handle);
    dlerror(); int (*native)(void *)=(int (*)(void *))dlsym(handle,"wide_compare");
    REQUIRE(!dlerror() && native);
    int map=bpf_map_create(BPF_MAP_TYPE_ARRAY,"wide_zero",4,4096,1,NULL);REQUIRE(map>=0);
    struct bpf_insn start[]={
        {.code=BPF_LD|BPF_DW|BPF_IMM,.dst_reg=1,.src_reg=BPF_PSEUDO_MAP_FD,.imm=map},
        {},
        {.code=BPF_ST|BPF_W|BPF_MEM,.dst_reg=10,.off=-4},
        {.code=BPF_ALU64|BPF_MOV|BPF_X,.dst_reg=2,.src_reg=10},
        {.code=BPF_ALU64|BPF_ADD|BPF_K,.dst_reg=2,.imm=-4},
        {.code=BPF_JMP|BPF_CALL,.imm=BPF_FUNC_map_lookup_elem},
        {.code=BPF_JMP|BPF_JNE|BPF_K,.dst_reg=0,.off=2},
        {.code=BPF_ALU64|BPF_MOV|BPF_K,.dst_reg=0,.imm=-1},
        {.code=BPF_JMP|BPF_EXIT},
        {.code=BPF_ALU64|BPF_MOV|BPF_X,.dst_reg=1,.src_reg=0},
    };
    REQUIRE(sizeof(start)/sizeof(*start)==prefix);memcpy(code,start,sizeof(start));
    char log[65536]={};LIBBPF_OPTS(bpf_prog_load_opts,opts,.log_buf=log,.log_size=sizeof(log),.log_level=1);
    int prog=bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER,"wide_zero","GPL",code,prefix+count,&opts);
    if (prog<0) fprintf(stderr,"%s\n",log);
    REQUIRE(prog>=0);
    uint64_t boundary[]={0,1,2,65535,65536,0xffffffffULL,0x100000000ULL,
                         0x100000001ULL,0x1000000000000ULL,0x8000000000000000ULL,~0ULL};
    unsigned key=0,executions=0;uint64_t state=0x3b723ab9f61ULL;
    unsigned char data[4096],packet[64]={};
    for (unsigned n=0;n<sizeof(boundary)/sizeof(*boundary)+1024;++n) {
        state^=state<<13;state^=state>>7;state^=state<<17;
        uint64_t value=n<sizeof(boundary)/sizeof(*boundary)?boundary[n]:state;
        if (n>=sizeof(boundary)/sizeof(*boundary) && n%4==0) value=state<<32;
        memset(data,0xa5,sizeof(data));memcpy(data+offset,&value,8);
        REQUIRE(bpf_map_update_elem(map,&key,data,BPF_ANY)==0);
        LIBBPF_OPTS(bpf_test_run_opts,run,.data_in=packet,.data_size_in=sizeof(packet),.repeat=1);
        REQUIRE(bpf_prog_test_run_opts(prog,&run)==0);
        int got=native(data);
        if (got!=(int)run.retval) {
            fprintf(stderr,"input=%llx native=%d BPF=%u\n",(unsigned long long)value,got,run.retval);return 1;
        }
        ++executions;
    }
    printf("{\"executions\":%u,\"failed\":0}\n",executions);
    REQUIRE(close(prog)==0 && close(map)==0 && dlclose(handle)==0);free(code);return 0;
}
