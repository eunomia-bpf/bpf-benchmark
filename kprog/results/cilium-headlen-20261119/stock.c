/* Verify all positive predicate fixtures and exercise both length branches. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char **argv)
{
    if(argc!=3)return 1;
    char log[2<<20]={};
    struct bpf_object_open_opts options={.sz=sizeof(options),.kernel_log_buf=log,
        .kernel_log_size=sizeof(log),.kernel_log_level=2};
    struct bpf_object *object=bpf_object__open_file(argv[1],&options);
    if(!object){perror("open predicate fixtures");return 1;}
    int result=bpf_object__load(object);
    FILE *file=fopen(argv[2],"w");
    if(!file){perror("open verifier log");bpf_object__close(object);return 1;}
    int wrote=fputs(log,file),closed=fclose(file);
    if(wrote==EOF||closed||result){fprintf(stderr,"stock fixture load failed: %d\n",result);bpf_object__close(object);return 1;}
    unsigned loaded=0,cases=0;
    struct bpf_program *program;
    bpf_object__for_each_program(program,object)++loaded;
    const char *names[]={"head_ge","head_gt","head_not_lt","head_not_le","head_wide"};
    for(unsigned i=0;i<sizeof(names)/sizeof(names[0]);++i){
        program=bpf_object__find_program_by_name(object,names[i]);
        if(!program){fprintf(stderr,"missing %s\n",names[i]);bpf_object__close(object);return 1;}
        for(unsigned length=32;length<=64;length+=32){
            unsigned char packet[64];memset(packet,0x5a,sizeof(packet));
            struct bpf_test_run_opts run={.sz=sizeof(run),.data_in=packet,.data_size_in=length,.repeat=1};
            result=bpf_prog_test_run_opts(bpf_program__fd(program),&run);
            unsigned expected=length==64?0x5a:0;
            printf("{\"program\":\"%s\",\"packet_bytes\":%u,\"retval\":%u,\"expected\":%u,\"error\":%d}\n",names[i],length,run.retval,expected,result);
            if(result||run.retval!=expected){bpf_object__close(object);return 1;}
            ++cases;
        }
    }
    printf("{\"stock_programs\":%u,\"test_run_cases\":%u}\n",loaded,cases);
    bpf_object__close(object);return 0;
}
