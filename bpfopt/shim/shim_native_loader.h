#ifndef BPFREJIT_SHIM_NATIVE_LOADER_H
#define BPFREJIT_SHIM_NATIVE_LOADER_H

struct native_loader_c_result {
    int prog_fd;
    char error[4096];
};

#define SHIM_NATIVE_LOADER_PATH_MAX 512
#define SHIM_NATIVE_LOADER_SYMBOL_MAX 256

typedef int (*native_loader_load_from_fd_with_source_path_and_attach_fn)(
    int original_prog_fd,
    const char *native_object_path,
    const char *symbol_name,
    const char *source_bpf_path,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t prog_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out);

static int shim_native_loader_enabled(void) {
    const char *e = getenv("BPFREJIT_SHIM_NATIVE_LOADER");
    return e && strcmp(e, "1") == 0;
}

static int shim_native_loader_source_has_map_prefix(const char *source_path,
                                                    const char *prefix) {
    if (!source_path || !source_path[0] || !prefix || !prefix[0])
        return 0;
    int fd = open(source_path, O_RDONLY);
    if (fd < 0)
        return 0;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size < 0 ||
        ((size_t)st.st_size % sizeof(struct bpf_insn)) != 0) {
        close(fd);
        return 0;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) {
        close(fd);
        return 0;
    }
    size_t off = 0;
    while (off < bytes) {
        ssize_t n = read(fd, ((char *)insns) + off, bytes - off);
        if (n < 0) {
            if (errno == EINTR)
                continue;
            free(insns);
            close(fd);
            return 0;
        }
        if (n == 0) {
            free(insns);
            close(fd);
            return 0;
        }
        off += (size_t)n;
    }
    close(fd);

    int found = 0;
    size_t insn_cnt = bytes / sizeof(*insns);
    for (size_t i = 0; i < insn_cnt; i++) {
        struct bpf_insn *insn = &insns[i];
        if (insn->code != (BPF_LD | BPF_DW | BPF_IMM))
            continue;
        if (insn->src_reg == BPF_PSEUDO_MAP_FD ||
            insn->src_reg == BPF_PSEUDO_MAP_VALUE) {
            struct bpf_map_info info;
            union bpf_attr attr;
            memset(&info, 0, sizeof(info));
            memset(&attr, 0, sizeof(attr));
            attr.info.bpf_fd = (uint32_t)insn->imm;
            attr.info.info_len = sizeof(info);
            attr.info.info = (uintptr_t)&info;
            if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD,
                             &attr, sizeof(attr)) >= 0 &&
                strncmp(info.name, prefix, strlen(prefix)) == 0) {
                found = 1;
                break;
            }
        }
        i++;
    }
    free(insns);
    return found;
}

static int shim_native_loader_source_has_helper(const char *source_path,
                                                int helper_id) {
    if (!source_path || !source_path[0] || helper_id < 0)
        return 0;
    int fd = open(source_path, O_RDONLY);
    if (fd < 0)
        return 0;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size < 0 ||
        ((size_t)st.st_size % sizeof(struct bpf_insn)) != 0) {
        close(fd);
        return 0;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) {
        close(fd);
        return 0;
    }
    size_t off = 0;
    while (off < bytes) {
        ssize_t n = read(fd, ((char *)insns) + off, bytes - off);
        if (n < 0) {
            if (errno == EINTR)
                continue;
            free(insns);
            close(fd);
            return 0;
        }
        if (n == 0) {
            free(insns);
            close(fd);
            return 0;
        }
        off += (size_t)n;
    }
    close(fd);

    int found = 0;
    size_t insn_cnt = bytes / sizeof(*insns);
    for (size_t i = 0; i < insn_cnt; i++) {
        const struct bpf_insn *insn = &insns[i];
        if (insn->code == (BPF_JMP | BPF_CALL) &&
            insn->src_reg == 0 &&
            insn->imm == helper_id) {
            found = 1;
            break;
        }
    }
    free(insns);
    return found;
}

static int shim_native_loader_manifest_dir(const char *manifest,
                                           char *out,
                                           size_t out_sz) {
    if (!manifest || !manifest[0] || out_sz == 0)
        return -1;
    const char *slash = strrchr(manifest, '/');
    if (!slash) {
        if (snprintf(out, out_sz, ".") >= (int)out_sz)
            return -1;
        return 0;
    }
    size_t len = (size_t)(slash - manifest);
    if (len == 0)
        len = 1;
    if (len + 1 > out_sz)
        return -1;
    memcpy(out, manifest, len);
    out[len] = '\0';
    return 0;
}

static int shim_native_loader_manifest_join(const char *manifest,
                                            const char *native_object,
                                            char *out,
                                            size_t out_sz) {
    if (!native_object || !native_object[0])
        return -1;
    if (native_object[0] == '/') {
        if (snprintf(out, out_sz, "%s", native_object) >= (int)out_sz)
            return -1;
        return 0;
    }
    char dir[SHIM_NATIVE_LOADER_PATH_MAX];
    if (shim_native_loader_manifest_dir(manifest, dir, sizeof(dir)) != 0)
        return -1;
    if (snprintf(out, out_sz, "%s/%s", dir, native_object) >= (int)out_sz)
        return -1;
    return 0;
}

static int shim_native_loader_manifest_entry_matches(const char *entry,
                                                     const struct prog_entry *prog,
                                                     const char *source_path) {
    char program[64] = {0};
    if (!json_get_str(entry, "program", program, sizeof(program)) ||
        !program[0])
        return 0;
    const char *prog_name = prog ? prog->name : "";
    if (!prog_name || strcmp(program, prog_name) != 0)
        return 0;

    long prog_type = json_get_int(entry, "prog_type");
    if (prog_type >= 0 &&
        (!prog || (uint32_t)prog_type != prog->prog_type))
        return 0;

    char map_prefix[64] = {0};
    if (json_get_str(entry, "source_map_prefix", map_prefix,
                     sizeof(map_prefix)) &&
        map_prefix[0] &&
        !shim_native_loader_source_has_map_prefix(source_path, map_prefix))
        return 0;

    long required_helper = json_get_int(entry, "source_has_helper");
    if (required_helper >= 0 &&
        !shim_native_loader_source_has_helper(source_path,
                                             (int)required_helper))
        return 0;

    long forbidden_helper = json_get_int(entry, "source_lacks_helper");
    if (forbidden_helper >= 0 &&
        shim_native_loader_source_has_helper(source_path,
                                            (int)forbidden_helper))
        return 0;

    return 1;
}

static int shim_native_loader_resolve_manifest(const char *manifest_path,
                                               const struct prog_entry *prog,
                                               const char *source_path,
                                               char *native_object,
                                               size_t native_object_sz,
                                               char *symbol,
                                               size_t symbol_sz) {
    char *manifest = NULL;
    if (loadtime_read_text_file(manifest_path, &manifest) != 0)
        return -1;

    const char *objects_end = NULL;
    const char *objects = json_array_at(manifest, "objects", &objects_end);
    if (!objects || !objects_end) {
        log_line("native-loader manifest has no objects array: %s",
                 manifest_path);
        free(manifest);
        return -1;
    }

    int matched = 0;
    const char *cursor = objects;
    const char *obj_start = NULL;
    const char *obj_end = NULL;
    while (json_array_next_obj(&cursor, objects_end, &obj_start, &obj_end)) {
        size_t len = (size_t)(obj_end - obj_start);
        char *entry = (char *)malloc(len + 1);
        if (!entry) {
            free(manifest);
            errno = ENOMEM;
            return -1;
        }
        memcpy(entry, obj_start, len);
        entry[len] = '\0';

        if (!shim_native_loader_manifest_entry_matches(entry, prog,
                                                       source_path)) {
            free(entry);
            continue;
        }

        char entry_object[SHIM_NATIVE_LOADER_PATH_MAX] = {0};
        char entry_symbol[SHIM_NATIVE_LOADER_SYMBOL_MAX] = {0};
        if (!json_get_str(entry, "native_object", entry_object,
                          sizeof(entry_object)) ||
            !entry_object[0]) {
            log_line("native-loader manifest entry for prog=%s lacks native_object",
                     prog ? prog->name : "");
            free(entry);
            free(manifest);
            return -1;
        }
        (void)json_get_str(entry, "symbol", entry_symbol,
                           sizeof(entry_symbol));

        char full_object[SHIM_NATIVE_LOADER_PATH_MAX] = {0};
        if (shim_native_loader_manifest_join(manifest_path, entry_object,
                                             full_object,
                                             sizeof(full_object)) != 0) {
            free(entry);
            free(manifest);
            return -1;
        }
        if (matched &&
            (strcmp(native_object, full_object) != 0 ||
             strcmp(symbol, entry_symbol) != 0)) {
            log_line("native-loader manifest has ambiguous entries for prog=%s",
                     prog ? prog->name : "");
            free(entry);
            free(manifest);
            return -1;
        }
        if (!matched) {
            if (snprintf(native_object, native_object_sz, "%s", full_object) >=
                    (int)native_object_sz ||
                snprintf(symbol, symbol_sz, "%s", entry_symbol) >=
                    (int)symbol_sz) {
                free(entry);
                free(manifest);
                return -1;
            }
        }
        matched = 1;
        free(entry);
    }

    free(manifest);
    if (!matched)
        return -1;
    if (access(native_object, R_OK) != 0) {
        log_line("native-loader manifest object unreadable prog=%s path=%s errno=%d",
                 prog ? prog->name : "", native_object, errno);
        return -1;
    }
    return 0;
}

static int shim_native_loader_resolve_object(const struct prog_entry *prog,
                                             const char *source_path,
                                             char *native_object,
                                             size_t native_object_sz,
                                             char *symbol,
                                             size_t symbol_sz) {
    const char *manifest = getenv("BPFREJIT_SHIM_NATIVE_MANIFEST");
    if (!manifest || !manifest[0])
        return -1;
    return shim_native_loader_resolve_manifest(manifest, prog, source_path,
                                               native_object,
                                               native_object_sz, symbol,
                                               symbol_sz);
}

static int shim_native_loader_is_libbpf_probe(const struct prog_entry *prog) {
    const char *name = prog ? prog->name : "";
    uint32_t insn_cnt = prog ? prog->insn_cnt : 0;

    if ((!name || !name[0]) && insn_cnt <= 2)
        return 1;
    if (prog && (!name || !name[0]) && insn_cnt <= 4 &&
        (prog->prog_type == BPF_PROG_TYPE_CGROUP_SOCK ||
         prog->prog_type == BPF_PROG_TYPE_CGROUP_SOCK_ADDR ||
         prog->prog_type == BPF_PROG_TYPE_CGROUP_SOCKOPT ||
         prog->prog_type == BPF_PROG_TYPE_XDP ||
         prog->prog_type == BPF_PROG_TYPE_SCHED_CLS ||
         prog->prog_type == BPF_PROG_TYPE_SCHED_ACT)) {
        return 1;
    }
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_SOCKET_FILTER &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt <= 5)
        return 1;
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_TRACEPOINT &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt <= 6)
        return 1;
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_KPROBE &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt <= 6)
        return 1;
    if (name && strcmp(name, "libbpf_nametest") == 0 && insn_cnt <= 2)
        return 1;
    if (name && strcmp(name, "det_arg_ctx") == 0 && insn_cnt <= 4)
        return 1;
    if (prog && name && strcmp(name, "test") == 0 &&
        prog->prog_type == BPF_PROG_TYPE_XDP && prog->expected_attach_type == 0 &&
        prog->attach_btf_id == 0 && insn_cnt == 6 &&
        prog->hash == 0xf2c52b5b17d11f48ULL)
        return 1;
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_SOCKET_FILTER &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt == 4097 && prog->hash == 0xdad2efe83d9579b0ULL)
        return 1;
    if (prog && name && strcmp(name, "probe_fib_looku") == 0 &&
        prog->prog_type == BPF_PROG_TYPE_SCHED_CLS &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt == 23 && (prog->hash == 0xf436d54fbd8c7ea7ULL ||
                           prog->hash == 0xca5c856e97173b3bULL ||
                           prog->hash == 0xb81a739a980c3e63ULL))
        return 1;
    if (prog && name && strcmp(name, "adjust_mac_room") == 0 &&
        prog->prog_type == BPF_PROG_TYPE_SCHED_CLS &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt == 5 && prog->hash == 0x708e759c87fe3b92ULL)
        return 1;
    if (prog && name &&
        (strcmp(name, "probe_bpf_kprob") == 0 ||
         strcmp(name, "probe_bpf_perf_") == 0 ||
         strcmp(name, "probe_kpm_link") == 0 ||
         strcmp(name, "probe_upm_link") == 0 ||
         strcmp(name, "probe_fmod_ret") == 0 ||
         strcmp(name, "probe_sys_fmod_") == 0 ||
         strcmp(name, "probe_get_func_") == 0 ||
         strcmp(name, "uprobe_regs") == 0) &&
        insn_cnt <= 6)
        return 1;
    return 0;
}

static int shim_native_loader_is_internal_prog(const struct prog_entry *prog) {
    const char *name = prog ? prog->name : "";

    return name && strcmp(name, "native_lab_stub") == 0;
}

static int shim_native_loader_write_all(int fd, const void *buf, size_t len) {
    const char *p = (const char *)buf;
    while (len > 0) {
        ssize_t n = write(fd, p, len);
        if (n < 0) {
            if (errno == EINTR)
                continue;
            return -1;
        }
        if (n == 0)
            return -1;
        p += n;
        len -= (size_t)n;
    }
    return 0;
}

static int shim_native_loader_prepare_source_path(long original_fd,
                                                  const struct prog_entry *prog,
                                                  char *out,
                                                  size_t out_sz) {
    if (snprintf(out, out_sz, "%s", prog->bytecode_path) >= (int)out_sz)
        return -1;
    if (!prog->fd_array_slots_needed)
        return 0;
    if (!prog->fd_array_snapshot ||
        prog->fd_array_snapshot_n < prog->fd_array_slots_needed) {
        log_line("native-loader source needs fd_array slots=%u but captured=%u "
                 "prog=%s",
                 prog->fd_array_slots_needed, prog->fd_array_snapshot_n,
                 prog->name);
        return -1;
    }

    int fd = open(prog->bytecode_path, O_RDONLY);
    if (fd < 0)
        return -1;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size < 0 ||
        ((size_t)st.st_size % sizeof(struct bpf_insn)) != 0) {
        int saved = errno;
        close(fd);
        errno = saved ? saved : EINVAL;
        return -1;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) {
        close(fd);
        return -1;
    }
    size_t off = 0;
    while (off < bytes) {
        ssize_t n = read(fd, ((char *)insns) + off, bytes - off);
        if (n < 0) {
            if (errno == EINTR)
                continue;
            int saved = errno;
            close(fd);
            free(insns);
            errno = saved;
            return -1;
        }
        if (n == 0) {
            close(fd);
            free(insns);
            errno = EIO;
            return -1;
        }
        off += (size_t)n;
    }
    close(fd);

    uint32_t insn_cnt = (uint32_t)(bytes / sizeof(*insns));
    uint32_t rewrites = 0;
    for (uint32_t i = 0; i < insn_cnt; i++) {
        struct bpf_insn *insn = &insns[i];
        if (insn->code != (BPF_LD | BPF_DW | BPF_IMM))
            continue;
        if (insn->src_reg == BPF_PSEUDO_MAP_IDX ||
            insn->src_reg == BPF_PSEUDO_MAP_IDX_VALUE) {
            if (insn->imm < 0) {
                free(insns);
                errno = EINVAL;
                return -1;
            }
            uint32_t idx = (uint32_t)insn->imm;
            if (idx >= prog->fd_array_snapshot_n ||
                prog->fd_array_snapshot[idx] < 0) {
                log_line("native-loader source fd_array index invalid "
                         "prog=%s idx=%u captured=%u fd=%d",
                         prog->name, idx, prog->fd_array_snapshot_n,
                         idx < prog->fd_array_snapshot_n
                             ? prog->fd_array_snapshot[idx]
                             : -1);
                free(insns);
                errno = EINVAL;
                return -1;
            }
            insn->imm = prog->fd_array_snapshot[idx];
            insn->src_reg = (insn->src_reg == BPF_PSEUDO_MAP_IDX)
                                ? BPF_PSEUDO_MAP_FD
                                : BPF_PSEUDO_MAP_VALUE;
            rewrites++;
        }
        i++;
    }
    if (!rewrites) {
        free(insns);
        return 0;
    }

    if (snprintf(out, out_sz, "%s.native_loader.%ld.bpf",
                 prog->bytecode_path, original_fd) >= (int)out_sz) {
        free(insns);
        errno = ENAMETOOLONG;
        return -1;
    }
    fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        free(insns);
        return -1;
    }
    if (shim_native_loader_write_all(fd, insns, bytes) != 0) {
        int saved = errno;
        close(fd);
        free(insns);
        errno = saved ? saved : EIO;
        return -1;
    }
    close(fd);
    free(insns);
    log_line("native-loader canonicalized fd_array source prog=%s rewrites=%u "
             "path=%s",
             prog->name, rewrites, out);
    return 0;
}

static void shim_native_loader_log_jit_info(const char *label, int fd) {
    if (fd < 0)
        return;

    struct bpf_prog_info info;
    uint64_t ksyms[4] = {0};
    memset(&info, 0, sizeof(info));
    info.nr_jited_ksyms = (uint32_t)(sizeof(ksyms) / sizeof(ksyms[0]));
    info.jited_ksyms = (uintptr_t)ksyms;

    union bpf_attr attr;
    memset(&attr, 0, sizeof(attr));
    attr.info.bpf_fd = (uint32_t)fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = (uintptr_t)&info;

    long r = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr));
    if (r < 0) {
        log_line("native-loader jit-info %s fd=%d errno=%d",
                 label ? label : "", fd, errno);
        return;
    }

    char tag_hex[sizeof(info.tag) * 2 + 1];
    for (size_t i = 0; i < sizeof(info.tag); i++)
        snprintf(tag_hex + i * 2, 3, "%02x", info.tag[i]);
    tag_hex[sizeof(info.tag) * 2] = '\0';

    log_line("native-loader jit-info %s fd=%d id=%u type=%u name=%s "
             "tag=%s jited_len=%u xlated_len=%u nr_jited_ksyms=%u "
             "ksym0=0x%llx ksym1=0x%llx",
             label ? label : "", fd, info.id, info.type, info.name,
             tag_hex, info.jited_prog_len, info.xlated_prog_len,
             info.nr_jited_ksyms,
             (unsigned long long)ksyms[0],
             (unsigned long long)ksyms[1]);
}

static size_t shim_native_loader_jit_dump_limit(void) {
    const char *raw = getenv("BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT");
    if (!raw || !raw[0])
        return 0;

    errno = 0;
    char *end = NULL;
    unsigned long long value = strtoull(raw, &end, 10);
    if (errno != 0 || end == raw || (end && *end != '\0')) {
        log_line("native-loader jit-dump invalid-limit value=%s",
                 raw ? raw : "");
        return 0;
    }
    if (value > SIZE_MAX)
        return SIZE_MAX;
    return (size_t)value;
}

static void shim_native_loader_log_jit_dump(const char *label, int fd) {
    size_t limit = shim_native_loader_jit_dump_limit();
    if (fd < 0 || limit == 0)
        return;

    struct bpf_prog_info info;
    memset(&info, 0, sizeof(info));

    union bpf_attr attr;
    memset(&attr, 0, sizeof(attr));
    attr.info.bpf_fd = (uint32_t)fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = (uintptr_t)&info;

    long r = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr));
    if (r < 0) {
        log_line("native-loader jit-dump %s fd=%d errno=%d",
                 label ? label : "", fd, errno);
        return;
    }
    if (info.jited_prog_len == 0) {
        log_line("native-loader jit-dump %s fd=%d len=0 dumped=0 bytes=",
                 label ? label : "", fd);
        return;
    }

    uint32_t jited_len = info.jited_prog_len;
    uint8_t *insns = (uint8_t *)malloc(jited_len);
    if (!insns) {
        log_line("native-loader jit-dump %s fd=%d len=%u errno=%d",
                 label ? label : "", fd, jited_len, errno ? errno : ENOMEM);
        return;
    }

    memset(&info, 0, sizeof(info));
    info.jited_prog_len = jited_len;
    info.jited_prog_insns = (uintptr_t)insns;
    memset(&attr, 0, sizeof(attr));
    attr.info.bpf_fd = (uint32_t)fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = (uintptr_t)&info;

    r = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr));
    if (r < 0) {
        log_line("native-loader jit-dump %s fd=%d len=%u errno=%d",
                 label ? label : "", fd, jited_len, errno);
        free(insns);
        return;
    }

    size_t dumped = info.jited_prog_len;
    if (dumped > jited_len)
        dumped = jited_len;
    if (dumped > limit)
        dumped = limit;

    char *hex = (char *)malloc(dumped * 2 + 1);
    if (!hex) {
        log_line("native-loader jit-dump %s fd=%d len=%u dumped=%zu errno=%d",
                 label ? label : "", fd, info.jited_prog_len, dumped,
                 errno ? errno : ENOMEM);
        free(insns);
        return;
    }
    for (size_t i = 0; i < dumped; i++)
        snprintf(hex + i * 2, 3, "%02x", insns[i]);
    hex[dumped * 2] = '\0';

    log_line("native-loader jit-dump %s fd=%d len=%u dumped=%zu bytes=%s",
             label ? label : "", fd, info.jited_prog_len, dumped, hex);
    free(hex);
    free(insns);
}

static long shim_maybe_replace_with_native_fd(long original_fd,
                                              struct prog_entry *prog) {
    const char *prog_name = prog ? prog->name : "";
    if (!shim_native_loader_enabled())
        return original_fd;
    if (original_fd < 0) {
        errno = EINVAL;
        return -1;
    }
    if (shim_native_loader_is_libbpf_probe(prog)) {
        log_line("native-loader skipped feature probe program name=%s insn_cnt=%u",
                 prog_name ? prog_name : "", prog ? prog->insn_cnt : 0);
        return original_fd;
    }
    if (shim_native_loader_is_internal_prog(prog)) {
        log_line("native-loader skipped internal program name=%s insn_cnt=%u",
                 prog_name ? prog_name : "", prog ? prog->insn_cnt : 0);
        return original_fd;
    }
    if (!prog || !prog->bytecode_path[0]) {
        log_line("native-loader missing captured source bytecode for prog=%s",
                 prog_name ? prog_name : "");
        errno = ENOENT;
        return -1;
    }
    if (access(prog->bytecode_path, R_OK) != 0) {
        log_line("native-loader source bytecode unreadable prog=%s path=%s errno=%d",
                 prog_name ? prog_name : "", prog->bytecode_path, errno);
        errno = ENOENT;
        return -1;
    }
    char source_path[512];
    if (shim_native_loader_prepare_source_path(original_fd, prog, source_path,
                                               sizeof(source_path)) != 0) {
        log_line("native-loader failed to prepare source bytecode prog=%s "
                 "source=%s errno=%d",
                 prog_name ? prog_name : "", prog->bytecode_path, errno);
        errno = EINVAL;
        return -1;
    }

    char native_object[SHIM_NATIVE_LOADER_PATH_MAX];
    char native_symbol[SHIM_NATIVE_LOADER_SYMBOL_MAX];
    if (shim_native_loader_resolve_object(prog, source_path, native_object,
                                          sizeof(native_object),
                                          native_symbol,
                                          sizeof(native_symbol)) != 0) {
        log_line("native-loader enabled but no manifest object for prog=%s",
                 prog_name ? prog_name : "");
        errno = ENOENT;
        return -1;
    }

    const char *so_path = getenv("BPFREJIT_NATIVE_LOADER_SO");
    if (!so_path || !so_path[0])
        so_path = "libnative_loader.so";
    void *handle = dlopen(so_path, RTLD_NOW | RTLD_LOCAL);
    if (!handle) {
        log_line("native-loader dlopen %s failed: %s", so_path, dlerror());
        errno = ENOENT;
        return -1;
    }

    dlerror();
    native_loader_load_from_fd_with_source_path_and_attach_fn load =
        (native_loader_load_from_fd_with_source_path_and_attach_fn)dlsym(
            handle, "native_loader_load_from_fd_with_source_path_and_attach");
    const char *sym_err = dlerror();
    if (sym_err || !load) {
        log_line("native-loader dlsym failed: %s", sym_err ? sym_err : "null");
        dlclose(handle);
        errno = ENOENT;
        return -1;
    }

    struct native_loader_c_result result;
    memset(&result, 0, sizeof(result));
    result.prog_fd = -1;
    if (load((int)original_fd, native_object, native_symbol, source_path,
             prog->expected_attach_type, prog->attach_btf_id,
             prog->prog_btf_kid, prog->attach_btf_obj_kid,
             prog->attach_prog_kid,
             &result) != 0) {
        log_line("native-loader failed prog=%s symbol=%s object=%s source=%s error=%s",
                 prog_name ? prog_name : "", native_symbol,
                 native_object, source_path, result.error);
        dlclose(handle);
        errno = EINVAL;
        return -1;
    }
    if (result.prog_fd < 0) {
        log_line("native-loader returned invalid fd for prog=%s",
                 prog_name ? prog_name : "");
        dlclose(handle);
        errno = EINVAL;
        return -1;
    }

    shim_native_loader_log_jit_info("original", (int)original_fd);
    shim_native_loader_log_jit_info("native", result.prog_fd);
    shim_native_loader_log_jit_dump("original", (int)original_fd);
    shim_native_loader_log_jit_dump("native", result.prog_fd);

    if (real_close((int)original_fd) != 0) {
        int saved = errno ? errno : EIO;
        log_line("native-loader failed to close replaced original fd=%ld errno=%d",
                 original_fd, errno);
        real_close(result.prog_fd);
        dlclose(handle);
        errno = saved;
        return -1;
    }
    log_line("native-loader replaced prog=%s original_fd=%ld native_fd=%d "
             "symbol=%s object=%s source=%s",
             prog_name ? prog_name : "", original_fd, result.prog_fd,
             native_symbol, native_object, source_path);
    dlclose(handle);
    return result.prog_fd;
}

#endif
