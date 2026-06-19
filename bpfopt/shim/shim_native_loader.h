#ifndef BPFREJIT_SHIM_NATIVE_LOADER_H
#define BPFREJIT_SHIM_NATIVE_LOADER_H

struct native_loader_c_result {
    int prog_fd;
    int replaced;
    int cache_hit;
    int prebuilt_proof;
    uint64_t bpf_bytecode_bytes;
    uint64_t native_code_bytes;
    uint64_t total_ns;
    uint64_t manifest_resolve_ns;
    uint64_t native_data_symbols_ns;
    uint64_t companion_map_ptr_extract_ns;
    uint64_t companion_lookup_spec_ns;
    uint64_t cache_lookup_ns;
    uint64_t native_link_exec_ns;
    uint64_t native_link_read_ns;
    uint64_t map_patch_ns;
    uint64_t upload_ns;
    uint64_t prog_load_ns;
    uint64_t native_blob_fnv64;
    uint64_t native_first_reloc_target;
    uint64_t native_last_reloc_target;
    uint32_t native_reloc_count;
    uint32_t native_chunk_count;
    uint32_t native_callee_saved_mask;
    uint32_t native_first_reloc_offset;
    uint32_t native_first_reloc_kind;
    uint32_t native_last_reloc_offset;
    uint32_t native_last_reloc_kind;
    char native_link_summary[4096];
    char error[65536];
};

typedef int (*native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn)(
    int original_prog_fd,
    const char *manifest_path,
    const char *source_bpf_path,
    const int *source_fd_array,
    uint32_t source_fd_array_count,
    uint32_t source_btf_id,
    const void *source_func_info,
    uint32_t source_func_info_count,
    uint32_t source_func_info_rec_size,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out);

static void *shim_native_loader_handle;
static char *shim_native_loader_handle_path;
static native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn
    shim_native_loader_load_fn;
static pthread_mutex_t shim_native_loader_handle_lock = PTHREAD_MUTEX_INITIALIZER;

static int shim_native_loader_enabled(void) {
    const char *e = getenv("BPFREJIT_SHIM_NATIVE_LOADER");
    return e && strcmp(e, "1") == 0;
}

static void shim_native_loader_fatal(void) {
    fflush(NULL);
    _exit(97);
}

static native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn
shim_native_loader_resolve_load_fn(const char *so_path) {
    pthread_mutex_lock(&shim_native_loader_handle_lock);
    if (shim_native_loader_load_fn) {
        if (strcmp(shim_native_loader_handle_path, so_path) != 0) {
            log_line("native-loader refusing to switch shared object from %s to %s",
                     shim_native_loader_handle_path, so_path);
            pthread_mutex_unlock(&shim_native_loader_handle_lock);
            shim_native_loader_fatal();
        }
        native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn load =
            shim_native_loader_load_fn;
        pthread_mutex_unlock(&shim_native_loader_handle_lock);
        return load;
    }

    void *handle = dlopen(so_path, RTLD_NOW | RTLD_LOCAL);
    if (!handle) {
        log_line("native-loader dlopen %s failed: %s", so_path, dlerror());
        pthread_mutex_unlock(&shim_native_loader_handle_lock);
        shim_native_loader_fatal();
    }

    dlerror();
    native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn load =
        (native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn)dlsym(
            handle, "native_loader_load_from_fd_with_manifest_path_btf_and_attach");
    const char *sym_err = dlerror();
    if (sym_err || !load) {
        log_line("native-loader dlsym failed: %s", sym_err ? sym_err : "null");
        dlclose(handle);
        pthread_mutex_unlock(&shim_native_loader_handle_lock);
        shim_native_loader_fatal();
    }

    char *path_copy = strdup(so_path);
    if (!path_copy) {
        log_line("native-loader failed to cache shared object path=%s errno=%d",
                 so_path, errno ? errno : ENOMEM);
        dlclose(handle);
        pthread_mutex_unlock(&shim_native_loader_handle_lock);
        shim_native_loader_fatal();
    }

    shim_native_loader_handle = handle;
    shim_native_loader_handle_path = path_copy;
    shim_native_loader_load_fn = load;
    log_line("native-loader loaded shared object path=%s", so_path);
    pthread_mutex_unlock(&shim_native_loader_handle_lock);
    return load;
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
        prog->prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt == 11 && prog->hash == 0x71725f032fe1d5e4ULL)
        return 1;
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_TRACING &&
        prog->expected_attach_type != 0 && prog->attach_btf_id != 0 &&
        insn_cnt == 3 && prog->hash == 0x145b4e38542e17e8ULL)
        return 1;
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_KPROBE &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        insn_cnt <= 6)
        return 1;
    if (prog && (!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_LSM &&
        prog->expected_attach_type == BPF_LSM_MAC &&
        prog->attach_btf_id != 0 && insn_cnt == 3 &&
        prog->hash == 0x145b4e38542e17e8ULL)
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
         strcmp(name, "probe_lsm_file_") == 0 ||
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

static int shim_native_loader_is_runtime_helper(const struct prog_entry *prog,
                                                const char *manifest) {
    const char *name = prog ? prog->name : "";

    if (!prog || !manifest)
        return 0;
    if (!strstr(manifest, "/tetragon/manifest.json"))
        return 0;

    /* Tetragon dynamically creates this one-shot PROG_RUN helper in
     * pkg/sensors/map_update.go::UpdateStatsMap() to update an internal stats
     * map. It has no stable native symbol because the map fd and value are
     * generated at runtime. */
    if ((!name || !name[0]) &&
        prog->prog_type == BPF_PROG_TYPE_SOCKET_FILTER &&
        strcmp(prog->license, "GPL") == 0 &&
        prog->expected_attach_type == 0 && prog->attach_btf_id == 0 &&
        prog->load_attr.prog_btf_fd == 0 && prog->fd_array_slots_needed == 0 &&
        prog->insn_cnt == 18)
        return 1;

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
        kmsg_line("native jit-info-failed label=%s fd=%d errno=%d",
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
    kmsg_line("native jit-info label=%s fd=%d id=%u type=%u name=%s "
              "jited_len=%u xlated_len=%u nr_ksyms=%u ksym0=0x%llx",
              label ? label : "", fd, info.id, info.type, info.name,
              info.jited_prog_len, info.xlated_prog_len,
              info.nr_jited_ksyms,
              (unsigned long long)ksyms[0]);
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
    kmsg_line("native consider name=%s type=%u insns=%u hash=%016llx fd=%ld",
              prog_name ? prog_name : "", prog ? prog->prog_type : 0,
              prog ? prog->insn_cnt : 0,
              (unsigned long long)(prog ? prog->hash : 0), original_fd);
    if (original_fd < 0) {
        kmsg_line("native invalid-original name=%s fd=%ld",
                  prog_name ? prog_name : "", original_fd);
        errno = EINVAL;
        return -1;
    }
    if (shim_native_loader_is_libbpf_probe(prog)) {
        log_line("native-loader skipped feature probe program name=%s insn_cnt=%u",
                 prog_name ? prog_name : "", prog ? prog->insn_cnt : 0);
        kmsg_line("native skip-feature-probe name=%s fd=%ld",
                  prog_name ? prog_name : "", original_fd);
        return original_fd;
    }
    if (shim_native_loader_is_internal_prog(prog)) {
        log_line("native-loader skipped internal program name=%s insn_cnt=%u",
                 prog_name ? prog_name : "", prog ? prog->insn_cnt : 0);
        kmsg_line("native skip-internal name=%s fd=%ld",
                  prog_name ? prog_name : "", original_fd);
        return original_fd;
    }
    if (!prog || !prog->bytecode_path[0]) {
        log_line("native-loader missing captured source bytecode for prog=%s",
                 prog_name ? prog_name : "");
        kmsg_line("native fatal-missing-bytecode name=%s",
                  prog_name ? prog_name : "");
        shim_native_loader_fatal();
    }
    if (access(prog->bytecode_path, R_OK) != 0) {
        log_line("native-loader source bytecode unreadable prog=%s path=%s errno=%d",
                 prog_name ? prog_name : "", prog->bytecode_path, errno);
        kmsg_line("native fatal-unreadable-bytecode name=%s path=%s errno=%d",
                  prog_name ? prog_name : "", prog->bytecode_path, errno);
        shim_native_loader_fatal();
    }
    const char *manifest = getenv("BPFREJIT_SHIM_NATIVE_MANIFEST");
    if (!manifest || !manifest[0]) {
        log_line("native-loader missing BPFREJIT_SHIM_NATIVE_MANIFEST for prog=%s",
                 prog_name ? prog_name : "");
        kmsg_line("native fatal-missing-manifest name=%s",
                  prog_name ? prog_name : "");
        shim_native_loader_fatal();
    }
    if (shim_native_loader_is_runtime_helper(prog, manifest)) {
        log_line("native-loader skipped runtime helper program name=%s insn_cnt=%u",
                 prog_name ? prog_name : "", prog ? prog->insn_cnt : 0);
        kmsg_line("native skip-runtime-helper name=%s fd=%ld",
                  prog_name ? prog_name : "", original_fd);
        return original_fd;
    }

    const char *so_path = getenv("BPFREJIT_NATIVE_LOADER_SO");
    if (!so_path || !so_path[0])
        so_path = "libnative_loader.so";
    native_loader_load_from_fd_with_manifest_path_btf_and_attach_fn load =
        shim_native_loader_resolve_load_fn(so_path);

    struct native_loader_c_result result;
    memset(&result, 0, sizeof(result));
    result.prog_fd = -1;
    kmsg_line("native load-begin name=%s fd=%ld manifest=%s source=%s",
              prog_name ? prog_name : "", original_fd, manifest,
              prog->bytecode_path);
    if (load((int)original_fd, manifest, prog->bytecode_path,
             prog->fd_array_snapshot, prog->fd_array_snapshot_n,
             prog->prog_btf_kid, prog->func_info_buf,
             prog->func_info_cnt, prog->func_info_rec_size,
             prog->expected_attach_type, prog->attach_btf_id,
             prog->attach_btf_obj_kid, prog->attach_prog_kid,
             &result) != 0) {
        log_line("native-loader failed prog=%s manifest=%s source=%s error=%s",
                 prog_name ? prog_name : "", manifest,
                 prog->bytecode_path, result.error);
        kmsg_line("native load-failed name=%s fd=%ld error=%s",
                  prog_name ? prog_name : "", original_fd, result.error);
        shim_native_loader_fatal();
    }
    kmsg_line("native load-done name=%s fd=%ld replaced=%d native_fd=%d "
              "cache_hit=%d native_bytes=%llu link_exec_ns=%llu "
              "blob_fnv=%016llx relocs=%u chunks=%u callee_saved=%u "
              "first_reloc=%u:%u:0x%016llx last_reloc=%u:%u:0x%016llx",
              prog_name ? prog_name : "", original_fd, result.replaced,
              result.prog_fd, result.cache_hit,
              (unsigned long long)result.native_code_bytes,
              (unsigned long long)result.native_link_exec_ns,
              (unsigned long long)result.native_blob_fnv64,
              result.native_reloc_count, result.native_chunk_count,
              result.native_callee_saved_mask,
              result.native_first_reloc_offset,
              result.native_first_reloc_kind,
              (unsigned long long)result.native_first_reloc_target,
              result.native_last_reloc_offset,
              result.native_last_reloc_kind,
              (unsigned long long)result.native_last_reloc_target);
    if (!result.replaced) {
        if (result.prog_fd >= 0)
            real_close(result.prog_fd);
        log_line("native-loader no manifest match pass-through for prog=%s "
                 "manifest=%s source=%s",
                 prog_name ? prog_name : "", manifest, prog->bytecode_path);
        kmsg_line("native pass-through name=%s fd=%ld",
                  prog_name ? prog_name : "", original_fd);
        return original_fd;
    }
    if (result.prog_fd < 0) {
        log_line("native-loader returned invalid fd for prog=%s",
                 prog_name ? prog_name : "");
        kmsg_line("native invalid-native-fd name=%s fd=%ld native_fd=%d",
                  prog_name ? prog_name : "", original_fd, result.prog_fd);
        shim_native_loader_fatal();
    }

    shim_native_loader_log_jit_info("original", (int)original_fd);
    shim_native_loader_log_jit_info("native", result.prog_fd);
    shim_native_loader_log_jit_dump("original", (int)original_fd);
    shim_native_loader_log_jit_dump("native", result.prog_fd);
    log_line("native-loader timings prog=%s cache_hit=%d prebuilt_proof=%d "
             "bpf_bytes=%llu native_bytes=%llu "
             "total_ns=%llu manifest_resolve_ns=%llu native_data_symbols_ns=%llu "
             "companion_map_ptr_ns=%llu companion_lookup_spec_ns=%llu "
             "cache_lookup_ns=%llu native_link_exec_ns=%llu "
             "native_link_read_ns=%llu map_patch_ns=%llu "
             "upload_ns=%llu prog_load_ns=%llu",
             prog_name ? prog_name : "", result.cache_hit,
             result.prebuilt_proof,
             (unsigned long long)result.bpf_bytecode_bytes,
             (unsigned long long)result.native_code_bytes,
             (unsigned long long)result.total_ns,
             (unsigned long long)result.manifest_resolve_ns,
             (unsigned long long)result.native_data_symbols_ns,
             (unsigned long long)result.companion_map_ptr_extract_ns,
             (unsigned long long)result.companion_lookup_spec_ns,
             (unsigned long long)result.cache_lookup_ns,
             (unsigned long long)result.native_link_exec_ns,
             (unsigned long long)result.native_link_read_ns,
             (unsigned long long)result.map_patch_ns,
             (unsigned long long)result.upload_ns,
             (unsigned long long)result.prog_load_ns);
    if (result.native_link_summary[0]) {
        log_line("native-loader link-plan prog=%s %s",
                 prog_name ? prog_name : "", result.native_link_summary);
    }

    int shadow_original_fd = fcntl((int)original_fd, F_DUPFD_CLOEXEC, 3);
    if (shadow_original_fd < 0) {
        log_line("native-loader failed to dup original fd=%ld errno=%d",
                 original_fd, errno);
        real_close(result.prog_fd);
        shim_native_loader_fatal();
    }
    if (prog->native_loader_original_fd >= 0)
        real_close(prog->native_loader_original_fd);
    prog->native_loader_original_fd = shadow_original_fd;

    if (real_close((int)original_fd) != 0) {
        log_line("native-loader failed to close replaced original fd=%ld errno=%d",
                 original_fd, errno);
        kmsg_line("native close-original-failed name=%s fd=%ld errno=%d",
                  prog_name ? prog_name : "", original_fd, errno);
        real_close(result.prog_fd);
        real_close(shadow_original_fd);
        prog->native_loader_original_fd = -1;
        shim_native_loader_fatal();
    }
    log_line("native-loader replaced prog=%s original_fd=%ld native_fd=%d "
             "manifest=%s source=%s",
             prog_name ? prog_name : "", original_fd, result.prog_fd,
             manifest, prog->bytecode_path);
    kmsg_line("native replaced name=%s original_fd=%ld native_fd=%d",
              prog_name ? prog_name : "", original_fd, result.prog_fd);
    return result.prog_fd;
}

#endif
