#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char **argv)
{
    if(argc!=3)return 1;
    char log[2<<20]={};
    struct bpf_object_open_opts open={.sz=sizeof(open),.kernel_log_buf=log,
        .kernel_log_size=sizeof(log),.kernel_log_level=2};
    struct bpf_object *object=bpf_object__open_file(argv[1],&open);
    if(!object){perror("open class store");return 1;}
    int result=bpf_object__load(object);
    FILE *file=fopen(argv[2],"w");
    if(!file){perror("open verifier log");bpf_object__close(object);return 1;}
    int wrote=fputs(log,file),closed=fclose(file);
    if(wrote==EOF||closed||result){fprintf(stderr,"stock class store load: %d\n",result);bpf_object__close(object);return 1;}
    struct bpf_program *program=bpf_object__find_program_by_name(object,"class_store");
    if(!program){fprintf(stderr,"missing class_store\n");bpf_object__close(object);return 1;}
    const unsigned values[]={0,0xffff,0x12345678,0xffffffff};
    for(unsigned i=0;i<sizeof(values)/sizeof(values[0]);++i){
        unsigned char data[64];memset(data,0x5a,sizeof(data));
        struct __sk_buff context={.mark=values[i]};
        struct bpf_test_run_opts run={.sz=sizeof(run),.data_in=data,.data_size_in=sizeof(data),
            .ctx_in=&context,.ctx_size_in=sizeof(context),.repeat=1};
        result=bpf_prog_test_run_opts(bpf_program__fd(program),&run);
        unsigned expected=values[i]&0xffff;
        printf("{\"mark\":%u,\"retval\":%u,\"expected\":%u,\"error\":%d}\n",values[i],run.retval,expected,result);
        if(result||run.retval!=expected){bpf_object__close(object);return 1;}
    }
    bpf_object__close(object);return 0;
}
