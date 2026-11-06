/* Load and execute one real simulator proof; retain verifier and memory counters. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

static void die(const char *what)
{
    perror(what);
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc != 4 && argc != 5) {
        fprintf(stderr,"usage: scale-probe OBJECT VERIFIER_LOG EXPECTED_RESULT [INPUT_BYTE]\n");
        return 1;
    }
    char *end;
    errno=0;
    uint64_t expected=strtoull(argv[3],&end,10);
    if (errno || end==argv[3] || *end) { fprintf(stderr,"invalid expected result\n"); return 1; }
    unsigned long input_byte=1;
    if (argc==5) {
        errno=0;
        input_byte=strtoul(argv[4],&end,10);
        if (errno || end==argv[4] || *end || input_byte>255) { fprintf(stderr,"invalid input byte\n"); return 1; }
    }
    const size_t capacity=128U*1024U*1024U;
    char *log=calloc(1,capacity);
    if (!log) die("allocate verifier log");
    LIBBPF_OPTS(bpf_object_open_opts, opts, .kernel_log_buf=log,
        .kernel_log_size=capacity, .kernel_log_level=4);
    struct bpf_object *object=bpf_object__open_file(argv[1],&opts);
    if (!object) die("open proof object");
    int err=bpf_object__load(object);
    FILE *file=fopen(argv[2],"w");
    if (!file) die("open verifier log");
    size_t bytes=strnlen(log,capacity);
    if (fwrite(log,1,bytes,file)!=bytes || fclose(file)) die("write verifier log");
    if (err) { fprintf(stderr,"load simulator proof: %s\n",strerror(-err)); return 1; }
    struct bpf_program *program=bpf_object__next_program(object,NULL);
    if (!program || bpf_object__next_program(object,program)) {
        fprintf(stderr,"scale fixture must have one BPF program\n"); return 1;
    }
    int fd=bpf_program__fd(program);
    struct bpf_prog_info info={0};
    uint32_t size=sizeof(info);
    if (bpf_obj_get_info_by_fd(fd,&info,&size)) die("read program info");
    char path[64];
    if (snprintf(path,sizeof(path),"/proc/self/fdinfo/%d",fd)>=(int)sizeof(path)) {
        fprintf(stderr,"fdinfo path too long\n"); return 1;
    }
    file=fopen(path,"r");
    if (!file) die("open program fdinfo");
    char *line=NULL;
    size_t line_size=0;
    unsigned long long memlock=0;
    int found=0;
    while (getline(&line,&line_size,file)>=0)
        if (sscanf(line,"memlock: %llu",&memlock)==1) found=1;
    if (ferror(file) || fclose(file)) die("read program fdinfo");
    free(line);
    if (!found) { fprintf(stderr,"program fdinfo omitted memlock\n"); return 1; }
    unsigned char input[64],output[64];
    memset(input,1,sizeof(input));
    memset(input,0,8);
    input[8]=(unsigned char)input_byte;
    LIBBPF_OPTS(bpf_test_run_opts, run, .data_in=input, .data_size_in=sizeof(input),
        .data_out=output, .data_size_out=sizeof(output), .repeat=1);
    if (bpf_prog_test_run_opts(fd,&run)) die("execute simulator proof");
    uint64_t actual=0;
    if (run.data_size_out<8) { fprintf(stderr,"short scale output\n"); return 1; }
    memcpy(&actual,output,sizeof(actual));
    struct rusage usage;
    if (getrusage(RUSAGE_SELF,&usage)) die("read loader resource use");
    printf("{\"program_id\":%u,\"proof_bpf_instructions\":%u,\"verified_instructions\":%u,"
        "\"bytes_jited\":%u,\"program_memlock_bytes\":%llu,\"loader_maxrss_kib\":%ld,"
        "\"result\":%" PRIu64 ",\"expected_result\":%" PRIu64 ",\"retval\":%u}\n",
        info.id,info.xlated_prog_len/(unsigned)sizeof(struct bpf_insn),info.verified_insns,info.jited_prog_len,
        memlock,usage.ru_maxrss,actual,expected,run.retval);
    if (actual!=expected || run.retval!=XDP_PASS) { fprintf(stderr,"scale result mismatch\n"); return 1; }
    if (fflush(stdout)) die("flush scale output");
    bpf_object__close(object);
    free(log);
    return 0;
}
