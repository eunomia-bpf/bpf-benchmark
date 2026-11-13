/* Equal-work JIT capture through libbpf; no application or program is loaded. */
#include <bpf/bpf.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    struct bpf_prog_info info = {};
    __u32 size = sizeof(info);
    char *end;
    if (argc != 3) return 2;
    errno = 0;
    unsigned long id = strtoul(argv[1], &end, 10);
    if (errno || *end || !id || id > UINT32_MAX) return 2;
    int fd = bpf_prog_get_fd_by_id(id);
    if (fd < 0) { perror("bpf_prog_get_fd_by_id"); return 1; }
    if (bpf_obj_get_info_by_fd(fd, &info, &size)) {
        perror("bpf_obj_get_info_by_fd(length)"); return 1;
    }
    __u32 capacity = info.jited_prog_len;
    if (!capacity) { fprintf(stderr, "program has no JIT bytes\n"); return 1; }
    void *bytes = malloc(capacity);
    if (!bytes) { perror("malloc"); return 1; }
    __u64 address = 0;
    info = (struct bpf_prog_info) { .jited_prog_len = capacity,
        .jited_prog_insns = (uintptr_t)bytes,
        .nr_jited_ksyms = 1, .jited_ksyms = (uintptr_t)&address };
    if (bpf_obj_get_info_by_fd(fd, &info, &size)) {
        perror("bpf_obj_get_info_by_fd(bytes)"); return 1;
    }
    if (info.jited_prog_len > capacity) return 1;
    FILE *out = fopen(argv[2], "wb");
    if (!out) { perror("fopen"); return 1; }
    if (fwrite(bytes, 1, info.jited_prog_len, out) != info.jited_prog_len) {
        perror("fwrite"); return 1;
    }
    if (fclose(out)) { perror("fclose"); return 1; }
    if (close(fd)) { perror("close"); return 1; }
    free(bytes);
    printf("id=%u jited_len=%u address=0x%llx\n", info.id,
           info.jited_prog_len, (unsigned long long)address);
    return 0;
}
