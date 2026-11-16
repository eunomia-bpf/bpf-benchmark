#ifndef BPFREJIT_SHIM_FUNCTION_INFO_H
#define BPFREJIT_SHIM_FUNCTION_INFO_H

/* Original records are copied before PROG_LOAD and normalized only after that
 * load succeeds. The filename is load-specific even when bytecode is shared. */
static int write_original_function_info(const char *bytecode_path,
                                        uint32_t prog_id, uint32_t btf_id,
                                        const void *records, uint32_t count,
                                        uint32_t stride)
{
    char *path = NULL;
    if (asprintf(&path, "%s.functions.%u.json", bytecode_path, prog_id) < 0)
        return -1;
    FILE *output = fopen(path, "w");
    free(path);
    if (!output) return -1;
    int status = fprintf(output, "{\"version\":1,\"prog_id\":%u,\"btf_id\":%u,\"functions\":[",
                         prog_id, btf_id);
    for (uint32_t i = 0; status >= 0 && i < count; ++i) {
        struct bpf_func_info function;
        memcpy(&function, (const char *)records + (size_t)i * stride, sizeof(function));
        status = fprintf(output, "%s{\"insn_off\":%u,\"type_id\":%u}",
                         i ? "," : "", function.insn_off, function.type_id);
    }
    if (status >= 0) status = fprintf(output, "]}\n");
    const int write_errno = errno;
    const int close_status = fclose(output);
    if (status < 0) { errno = write_errno; return -1; }
    return close_status;
}

#endif
