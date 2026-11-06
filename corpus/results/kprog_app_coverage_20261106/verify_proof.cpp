/* Diagnostic proof load only; corpus applications still start through their upstream loaders. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <vector>
int main(int argc,char **argv)
{
    if(argc!=4){std::fprintf(stderr,"usage: verify-proof OBJECT PROGRAM LOG\n");return 2;}
    bpf_object *object=bpf_object__open_file(argv[1],nullptr);
    if(!object){std::fprintf(stderr,"open proof: %s\n",std::strerror(errno));return 1;}
    bpf_program *chosen=bpf_object__find_program_by_name(object,argv[2]);
    if(!chosen){std::fprintf(stderr,"proof program missing: %s\n",argv[2]);bpf_object__close(object);return 1;}
    bpf_program *program;
    bpf_object__for_each_program(program,object){
        int error=bpf_program__set_autoload(program,program==chosen);
        if(error){std::fprintf(stderr,"select proof program: %d\n",error);bpf_object__close(object);return 1;}
    }
    std::vector<char> log(4*1024*1024);
    int error=bpf_program__set_log_buf(chosen,log.data(),log.size());
    if(!error)error=bpf_program__set_log_level(chosen,1);
    if(error){std::fprintf(stderr,"set verifier log: %d\n",error);bpf_object__close(object);return 1;}
    int status=bpf_object__load(object),saved_errno=errno;
    FILE *output=std::fopen(argv[3],"wb");
    if(!output){std::fprintf(stderr,"open verifier output: %s\n",std::strerror(errno));bpf_object__close(object);return 1;}
    size_t length=strnlen(log.data(),log.size());
    if(std::fwrite(log.data(),1,length,output)!=length || std::fclose(output)){
        std::fprintf(stderr,"write verifier output failed\n");bpf_object__close(object);return 1;
    }
    if(status){std::fprintf(stderr,"proof load: rc=%d errno=%d (%s)\n",status,saved_errno,std::strerror(saved_errno));bpf_object__close(object);return 1;}
    bpf_prog_info info{};unsigned size=sizeof(info);
    error=bpf_obj_get_info_by_fd(bpf_program__fd(chosen),&info,&size);
    if(error){std::fprintf(stderr,"proof info: %s\n",std::strerror(errno));bpf_object__close(object);return 1;}
    std::printf("id=%u type=%u bytes_xlated=%u bytes_jited=%u\n",info.id,info.type,info.xlated_prog_len,info.jited_prog_len);
    bpf_object__close(object);return 0;
}
