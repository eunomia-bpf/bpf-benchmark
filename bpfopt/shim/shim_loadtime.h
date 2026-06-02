#ifndef BPFREJIT_SHIM_LOADTIME_H
#define BPFREJIT_SHIM_LOADTIME_H

struct loadtime_result {
    union bpf_attr attr;
    char attr_buf[256];
    struct bpf_insn *insns;
    int *fd_array;
    uint32_t fd_array_n;
    unsigned int attr_size;
};

#define LOADTIME_VERIFIER_LOG_INITIAL_SIZE (16u * 1024u * 1024u)

static char **loadtime_env_without_ld_preload(void) {
    size_t n_env = 0;
    while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    if (!clean_env) return NULL;
    size_t j = 0;
    for (size_t i = 0; i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    clean_env[j] = NULL;
    return clean_env;
}

static int loadtime_write_file(const char *path, const void *data, size_t len) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return -1;
    const char *p = (const char *)data;
    size_t off = 0;
    while (off < len) {
        ssize_t n = write(fd, p + off, len - off);
        if (n < 0) {
            if (errno == EINTR) continue;
            real_close(fd);
            return -1;
        }
        if (n == 0) {
            real_close(fd);
            return -1;
        }
        off += (size_t)n;
    }
    real_close(fd);
    return 0;
}

static int loadtime_write_all_fd(int fd, const char *data, size_t len) {
    size_t off = 0;
    while (off < len) {
        ssize_t n = write(fd, data + off, len - off);
        if (n < 0) {
            if (errno == EINTR) continue;
            return -1;
        }
        if (n == 0) return -1;
        off += (size_t)n;
    }
    return 0;
}

static struct bpf_insn *loadtime_read_bytecode(const char *path,
                                               uint32_t *insn_cnt_out) {
    *insn_cnt_out = 0;
    int fd = open(path, O_RDONLY);
    if (fd < 0) return NULL;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size <= 0 ||
        (st.st_size % (off_t)sizeof(struct bpf_insn)) != 0) {
        real_close(fd);
        return NULL;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) {
        real_close(fd);
        return NULL;
    }
    size_t off = 0;
    while (off < bytes) {
        ssize_t n = read(fd, (char *)insns + off, bytes - off);
        if (n > 0) {
            off += (size_t)n;
            continue;
        }
        if (n < 0 && errno == EINTR)
            continue;
        free(insns);
        real_close(fd);
        return NULL;
    }
    real_close(fd);
    *insn_cnt_out = (uint32_t)(bytes / sizeof(struct bpf_insn));
    return insns;
}

static int loadtime_read_text_file(const char *path, char **out) {
    *out = NULL;
    int fd = open(path, O_RDONLY);
    if (fd < 0) return -1;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size <= 0 ||
        st.st_size > 1024 * 1024) {
        real_close(fd);
        return -1;
    }
    char *buf = (char *)malloc((size_t)st.st_size + 1);
    if (!buf) {
        real_close(fd);
        return -1;
    }
    size_t off = 0;
    while (off < (size_t)st.st_size) {
        ssize_t n = read(fd, buf + off, (size_t)st.st_size - off);
        if (n > 0) {
            off += (size_t)n;
            continue;
        }
        if (n < 0 && errno == EINTR)
            continue;
        free(buf);
        real_close(fd);
        return -1;
    }
    real_close(fd);
    buf[off] = 0;
    *out = buf;
    return 0;
}

static int loadtime_json_is_object(const char *payload) {
    jsmntok_t *tokens = NULL;
    int count = 0;
    int ok = json_parse_alloc(payload, &tokens, &count) == 0 && count > 0 &&
             tokens[0].type == JSMN_OBJECT;
    free(tokens);
    return ok;
}

static void loadtime_json_make_single_line(char *payload) {
    if (!payload)
        return;
    for (char *p = payload; *p; p++)
        if (*p == '\n' || *p == '\r')
            *p = ' ';
}

static int loadtime_append_step_report(const char *prog_name,
                                       const char *prog_type,
                                       const char *step_name,
                                       int step_index,
                                       uint64_t elapsed_ms,
                                       const char *workdir,
                                       const char *report_path) {
    const char *reports_path = getenv("BPFREJIT_SHIM_LOADTIME_REPORTS");
    if (!reports_path || !reports_path[0])
        return 0;

    char *report_json = NULL;
    char report_error[256] = {0};
    int report_ok = 0;
    if (loadtime_read_text_file(report_path, &report_json) == 0) {
        report_ok = loadtime_json_is_object(report_json);
        if (report_ok)
            loadtime_json_make_single_line(report_json);
        else
            snprintf(report_error, sizeof(report_error), "invalid JSON report");
    } else {
        snprintf(report_error, sizeof(report_error),
                 "missing report errno=%d", errno);
    }

    char e_prog[96], e_type[64], e_step[128], e_workdir[512], e_report[512],
         e_error[512];
    json_escape_into(prog_name ? prog_name : "", strlen(prog_name ? prog_name : ""),
                     e_prog, sizeof(e_prog));
    json_escape_into(prog_type ? prog_type : "", strlen(prog_type ? prog_type : ""),
                     e_type, sizeof(e_type));
    json_escape_into(step_name ? step_name : "", strlen(step_name ? step_name : ""),
                     e_step, sizeof(e_step));
    json_escape_into(workdir ? workdir : "", strlen(workdir ? workdir : ""),
                     e_workdir, sizeof(e_workdir));
    json_escape_into(report_path ? report_path : "",
                     strlen(report_path ? report_path : ""),
                     e_report, sizeof(e_report));
    json_escape_into(report_error, strlen(report_error), e_error,
                     sizeof(e_error));

    int fd = open(reports_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        free(report_json);
        return -1;
    }
    while (flock(fd, LOCK_EX) != 0) {
        if (errno == EINTR)
            continue;
        real_close(fd);
        free(report_json);
        return -1;
    }

    char prefix[1536];
    int n = snprintf(prefix, sizeof(prefix),
                     "{\"prog_name\":\"%s\",\"prog_type\":\"%s\","
                     "\"step\":\"%s\",\"step_index\":%d,"
                     "\"elapsed_ms\":%llu,\"workdir\":\"%s\","
                     "\"report_path\":\"%s\",\"report\":",
                     e_prog, e_type, e_step, step_index,
                     (unsigned long long)elapsed_ms, e_workdir, e_report);
    if (n < 0 || (size_t)n >= sizeof(prefix) ||
        loadtime_write_all_fd(fd, prefix, (size_t)n) != 0 ||
        loadtime_write_all_fd(fd, report_ok ? report_json : "null",
                              report_ok ? strlen(report_json) : 4) != 0) {
        real_close(fd);
        free(report_json);
        return -1;
    }
    if (report_error[0]) {
        char suffix[640];
        n = snprintf(suffix, sizeof(suffix),
                     ",\"report_error\":\"%s\"}\n", e_error);
        if (n < 0 || (size_t)n >= sizeof(suffix) ||
            loadtime_write_all_fd(fd, suffix, (size_t)n) != 0) {
            real_close(fd);
            free(report_json);
            return -1;
        }
    } else if (loadtime_write_all_fd(fd, "}\n", 2) != 0) {
        real_close(fd);
        free(report_json);
        return -1;
    }
    real_close(fd);
    free(report_json);
    return 0;
}

static void loadtime_substitute_vars(char *out, size_t out_sz, const char *in,
                                     const char *vars[][2], size_t n_vars) {
    size_t o = 0;
    for (size_t i = 0; in[i] && o + 1 < out_sz;) {
        if (in[i] == '$' && in[i + 1] == '{') {
            const char *end = strchr(in + i + 2, '}');
            if (end) {
                size_t name_len = end - (in + i + 2);
                int replaced = 0;
                for (size_t k = 0; k < n_vars; k++) {
                    if (strlen(vars[k][0]) == name_len &&
                        strncmp(in + i + 2, vars[k][0], name_len) == 0) {
                        size_t rl = strlen(vars[k][1]);
                        if (o + rl >= out_sz)
                            rl = out_sz - 1 - o;
                        memcpy(out + o, vars[k][1], rl);
                        o += rl;
                        replaced = 1;
                        break;
                    }
                }
                i = end - in + 1;
                if (!replaced) {
                    size_t lit_len = name_len + 3;
                    if (o + lit_len >= out_sz)
                        lit_len = out_sz - 1 - o;
                    memcpy(out + o, in + i - lit_len, lit_len);
                    o += lit_len;
                }
                continue;
            }
        }
        out[o++] = in[i++];
    }
    out[o] = 0;
}

static void loadtime_command_key_for_prog(const char *prog_name, char *out,
                                          size_t out_sz) {
    size_t o = 0;
    const char prefix[] = "command_";
    for (size_t i = 0; prefix[i] && o + 1 < out_sz; i++)
        out[o++] = prefix[i];
    for (size_t i = 0; prog_name[i] && o + 1 < out_sz; i++) {
        char c = prog_name[i];
        out[o++] = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                    (c >= '0' && c <= '9') || c == '_')
                       ? c
                       : '_';
    }
    out[o] = 0;
}

static void loadtime_command_key_for_prog_insn_count(const char *prog_name,
                                                     uint32_t insn_cnt,
                                                     char *out,
                                                     size_t out_sz) {
    loadtime_command_key_for_prog(prog_name, out, out_sz);
    size_t len = strlen(out);
    if (len >= out_sz)
        return;
    snprintf(out + len, out_sz - len, "_insns_%u", insn_cnt);
}

static void loadtime_command_key_for_hash(uint64_t prog_hash, char *out,
                                          size_t out_sz) {
    snprintf(out, out_sz, "command_hash_%016llx",
             (unsigned long long)prog_hash);
}

static int loadtime_run_shell(const char *command, const char *log_path,
                              uint64_t *elapsed_ms) {
    if (elapsed_ms) *elapsed_ms = 0;
    char **clean_env = loadtime_env_without_ld_preload();
    char *const argv[] = {"/bin/sh", "-c", (char *)command, NULL};
    posix_spawn_file_actions_t fa;
    int fa_inited = (posix_spawn_file_actions_init(&fa) == 0);
    if (fa_inited) {
        posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, log_path,
                                         O_WRONLY | O_CREAT | O_TRUNC, 0644);
        posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, log_path,
                                         O_WRONLY | O_APPEND, 0);
    }
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    pid_t pid;
    int rc = posix_spawn(&pid, "/bin/sh", fa_inited ? &fa : NULL, NULL, argv,
                         clean_env ? clean_env : environ);
    if (fa_inited) posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0)
        return -1;
    int status = 0;
    waitpid(pid, &status, 0);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    if (elapsed_ms)
        *elapsed_ms = (uint64_t)(t1.tv_sec - t0.tv_sec) * 1000ULL
                      + (uint64_t)((t1.tv_nsec - t0.tv_nsec) / 1000000);
    return (WIFEXITED(status) && WEXITSTATUS(status) == 0) ? 0 : -1;
}

static int loadtime_collect_maps(const struct bpf_insn *insns,
                                 uint32_t insn_cnt,
                                 struct shim_map_ref **refs_out,
                                 uint32_t *ref_n_out,
                                 uint32_t **ids_out,
                                 uint32_t **types_out,
                                 uint32_t *n_out,
                                 char *map_ids_csv,
                                 size_t map_ids_csv_sz) {
    *refs_out = NULL;
    *ref_n_out = 0;
    *ids_out = NULL;
    *types_out = NULL;
    *n_out = 0;
    if (map_ids_csv_sz) map_ids_csv[0] = 0;

    if (collect_current_map_refs(insns, insn_cnt, refs_out, ref_n_out) != 0)
        return -1;

    uint32_t cap = 8, n = 0;
    uint32_t *ids = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *types = (uint32_t *)calloc(cap, sizeof(uint32_t));
    if (!ids || !types) {
        free(*refs_out);
        *refs_out = NULL;
        *ref_n_out = 0;
        free(ids);
        free(types);
        return -1;
    }

    for (uint32_t r = 0; r < *ref_n_out; r++) {
        const struct shim_map_ref *ref = &(*refs_out)[r];
        int dup = 0;
        for (uint32_t i = 0; i < n; i++) {
            if (ids[i] == ref->kernel_id) {
                dup = 1;
                break;
            }
        }
        if (!dup) {
            if (n == cap) {
                cap *= 2;
                uint32_t *ni = (uint32_t *)realloc(ids, cap * sizeof(uint32_t));
                uint32_t *nt = (uint32_t *)realloc(types, cap * sizeof(uint32_t));
                if (!ni || !nt) {
                    free(ni ? ni : ids);
                    free(nt ? nt : types);
                    free(*refs_out);
                    *refs_out = NULL;
                    *ref_n_out = 0;
                    return -1;
                }
                ids = ni;
                types = nt;
            }
            ids[n] = ref->kernel_id;
            types[n] = ref->map_type;
            n++;
        }
    }
    format_map_ids_csv(ids, n, map_ids_csv, map_ids_csv_sz);
    *ids_out = ids;
    *types_out = types;
    *n_out = n;
    return 0;
}

static int loadtime_join_path(char *out, size_t out_sz, const char *dir,
                              const char *name, char *err, size_t err_sz) {
    size_t dir_len = strlen(dir);
    size_t name_len = strlen(name);
    if (dir_len + 1 + name_len + 1 > out_sz) {
        snprintf(err, err_sz, "loadtime path too long for %s", name);
        return -1;
    }
    memcpy(out, dir, dir_len);
    out[dir_len] = '/';
    memcpy(out + dir_len + 1, name, name_len + 1);
    return 0;
}

static int loadtime_prepare_target(const char *workdir, char *target_json,
                                   size_t target_json_sz,
                                   char *err, size_t err_sz) {
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    char shared[320];
    if (loadtime_join_path(shared, sizeof(shared), dir, "target.json",
                           err, err_sz) != 0 ||
        loadtime_join_path(target_json, target_json_sz, workdir, "target.json",
                           err, err_sz) != 0)
        return -1;
    struct stat st;
    if (stat(shared, &st) == 0) {
        char *target_payload = NULL;
        if (loadtime_read_text_file(shared, &target_payload) != 0)
            return -1;
        int rc = loadtime_write_file(target_json, target_payload,
                                     strlen(target_payload));
        free(target_payload);
        return rc;
    }
    snprintf(err, err_sz, "missing loadtime target.json at %s", shared);
    return -1;
}

static int loadtime_contains_libbpf_map_poison(const struct bpf_insn *insns,
                                               uint32_t insn_cnt) {
    const int poison_base = 2001000000;
    const int poison_limit = 2002000000;
    for (uint32_t pc = 0; pc < insn_cnt; pc++) {
        const struct bpf_insn *insn = &insns[pc];
        if ((insn->code == (BPF_JMP | BPF_CALL) ||
             insn->code == (BPF_JMP32 | BPF_CALL)) &&
            insn->src_reg == 0 &&
            insn->imm >= poison_base &&
            insn->imm < poison_limit)
            return 1;
        if (insn->code == (BPF_LD | BPF_DW | BPF_IMM) && pc + 1 < insn_cnt)
            pc++;
    }
    return 0;
}

static int loadtime_keep_workdirs_enabled(void) {
    const char *raw = getenv("KEEP_WORKDIRS");
    return raw && (strcmp(raw, "1") == 0 || strcmp(raw, "all") == 0 ||
                   strcmp(raw, "true") == 0);
}

static int loadtime_select_workdir_base(char *out, size_t out_sz,
                                        char *err, size_t err_sz) {
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (dir && dir[0]) {
        if (strlen(dir) + 1 > out_sz) {
            snprintf(err, err_sz, "loadtime workdir base path too long");
            return -1;
        }
        memcpy(out, dir, strlen(dir) + 1);
        return 0;
    }
    if (!loadtime_keep_workdirs_enabled()) {
        snprintf(out, out_sz, "/tmp");
        return 0;
    }

    const char *reports_path = getenv("BPFREJIT_SHIM_LOADTIME_REPORTS");
    if (!reports_path || !reports_path[0]) {
        snprintf(out, out_sz, "/tmp");
        return 0;
    }

    char details_dir[320];
    if (strlen(reports_path) + 1 > sizeof(details_dir)) {
        snprintf(err, err_sz, "loadtime reports path too long");
        return -1;
    }
    memcpy(details_dir, reports_path, strlen(reports_path) + 1);
    char *slash = strrchr(details_dir, '/');
    if (!slash) {
        snprintf(out, out_sz, "/tmp");
        return 0;
    }
    *slash = 0;
    slash = strrchr(details_dir, '/');
    if (!slash) {
        snprintf(out, out_sz, "/tmp");
        return 0;
    }
    *slash = 0;

    if (loadtime_join_path(out, out_sz, details_dir, "loadtime-workdirs",
                           err, err_sz) != 0)
        return -1;
    if (mkdir_one(out) != 0) {
        snprintf(err, err_sz,
                 "failed to create loadtime workdir artifact root errno=%d",
                 errno);
        return -1;
    }
    return 0;
}

static int loadtime_bytecode_needs_fd_array(const struct bpf_insn *insns,
                                            uint32_t insn_cnt) {
    for (uint32_t pc = 0; pc < insn_cnt; pc++) {
        const struct bpf_insn *insn = &insns[pc];
        if (insn->code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (insn->src_reg == BPF_PSEUDO_MAP_IDX ||
                insn->src_reg == BPF_PSEUDO_MAP_IDX_VALUE)
                return 1;
            if (pc + 1 < insn_cnt)
                pc++;
            continue;
        }
        if ((insn->code == (BPF_JMP | BPF_CALL) ||
             insn->code == (BPF_JMP32 | BPF_CALL)) &&
            insn->src_reg == BPF_PSEUDO_KINSN_CALL &&
            insn->off != 0)
            return 1;
    }
    return 0;
}

static int loadtime_write_fd_to_id_json(const char *path,
                                        const struct shim_map_ref *refs,
                                        uint32_t ref_n) {
    uint32_t *fds = NULL;
    uint32_t *kids = NULL;
    uint32_t n = 0;
    if (ref_n) {
        fds = (uint32_t *)calloc(ref_n, sizeof(uint32_t));
        kids = (uint32_t *)calloc(ref_n, sizeof(uint32_t));
        if (!fds || !kids) {
            free(fds);
            free(kids);
            return -1;
        }
    }
    for (uint32_t i = 0; i < ref_n; i++) {
        if (refs[i].loader_fd < 0 || refs[i].kernel_id == 0)
            continue;
        int dup = 0;
        for (uint32_t j = 0; j < n; j++) {
            if (fds[j] == (uint32_t)refs[i].loader_fd) {
                dup = 1;
                break;
            }
        }
        if (dup)
            continue;
        fds[n] = (uint32_t)refs[i].loader_fd;
        kids[n] = refs[i].kernel_id;
        n++;
    }
    int rc = write_fd_to_id_json(path, fds, kids, n);
    free(fds);
    free(kids);
    return rc;
}

static int loadtime_probe_bytecode_acceptance(const union bpf_attr *orig_attr,
                                              unsigned int attr_size,
                                              const char *bytecode_path,
                                              const char *target_json_path,
                                              const uint32_t *map_ids,
                                              uint32_t map_n,
                                              const char *log_path) {
    uint32_t insn_cnt = 0;
    struct bpf_insn *insns = loadtime_read_bytecode(bytecode_path, &insn_cnt);
    if (!insns)
        return -1;
    int *fd_array = NULL;
    uint32_t fd_array_n = 0;
    int needs_fd_array = loadtime_bytecode_needs_fd_array(insns, insn_cnt);
    if (needs_fd_array) {
        if (build_full_fd_array(target_json_path, map_ids, map_n,
                                &fd_array, &fd_array_n) != 0) {
            free(insns);
            return -1;
        }
        if (!fd_array || fd_array_n == 0) {
            free_full_fd_array(fd_array, fd_array_n);
            free(insns);
            errno = EINVAL;
            return -1;
        }
    }

    char attr_buf[256] = {0};
    size_t copy = attr_size < sizeof(attr_buf) ? attr_size : sizeof(attr_buf);
    memcpy(attr_buf, orig_attr, copy);
    union bpf_attr *a = (union bpf_attr *)(void *)attr_buf;
    a->insns = (uintptr_t)insns;
    a->insn_cnt = insn_cnt;
    a->log_level = 0;
    a->log_buf = 0;
    a->log_size = 0;
    a->fd_array = 0;
    if (fd_array) a->fd_array = (uintptr_t)fd_array;
    if (sizeof(attr_buf) >= 152)
        memset(attr_buf + 148, 0, 4);
    a->func_info = 0;
    a->func_info_cnt = 0;
    a->func_info_rec_size = 0;
    a->line_info = 0;
    a->line_info_cnt = 0;
    a->line_info_rec_size = 0;
    a->core_relos = 0;
    a->core_relo_cnt = 0;
    a->core_relo_rec_size = 0;

    long pfd = real_syscall(SYS_bpf, BPF_PROG_LOAD, attr_buf,
                            sizeof(attr_buf));
    int saved_errno = errno;
    int wfd = open(log_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (wfd >= 0)
        real_close(wfd);

    if (pfd < 0) {
        size_t log_buf_size = LOADTIME_VERIFIER_LOG_INITIAL_SIZE;
        char *log_buf = (char *)malloc(log_buf_size);
        if (!log_buf) {
            saved_errno = ENOMEM;
        } else {
            memset(log_buf, 0, log_buf_size);
            char diag_attr_buf[256];
            memcpy(diag_attr_buf, attr_buf, sizeof(diag_attr_buf));
            union bpf_attr *diag = (union bpf_attr *)(void *)diag_attr_buf;
            diag->log_level = 1;
            diag->log_buf = (uintptr_t)log_buf;
            diag->log_size = (uint32_t)log_buf_size;
            diag->log_true_size = 0;
            long diag_pfd = real_syscall(SYS_bpf, BPF_PROG_LOAD,
                                         diag_attr_buf, sizeof(diag_attr_buf));
            if (diag_pfd >= 0)
                real_close((int)diag_pfd);
            int lfd = open(log_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (lfd >= 0) {
                (void)!write(lfd, log_buf, strnlen(log_buf, log_buf_size));
                real_close(lfd);
            }
            free(log_buf);
        }
    }
    if (pfd >= 0)
        real_close((int)pfd);
    free_full_fd_array(fd_array, fd_array_n);
    free(insns);
    errno = saved_errno;
    return pfd >= 0 ? 0 : -1;
}

static int loadtime_optimize_prog_load(const union bpf_attr *attr,
                                       unsigned int attr_size,
                                       struct loadtime_result *out,
                                       char *err, size_t err_sz) {
    memset(out, 0, sizeof(*out));
    if (err_sz) err[0] = 0;
    const char *plan_path = getenv("BPFREJIT_SHIM_LOADTIME_PLAN");
    if (!plan_path || !plan_path[0])
        return 0;
    if (!attr || attr->insn_cnt == 0 || !attr->insns) {
        snprintf(err, err_sz, "invalid BPF_PROG_LOAD attr for loadtime optimization");
        return -1;
    }
    const struct bpf_insn *input_insns =
        (const struct bpf_insn *)(uintptr_t)attr->insns;
    if (loadtime_contains_libbpf_map_poison(input_insns, attr->insn_cnt)) {
        snprintf(err, err_sz,
                 "loadtime input contains unresolved libbpf map poison placeholders");
        return -1;
    }

    char *plan_json = NULL;
    if (loadtime_read_text_file(plan_path, &plan_json) != 0) {
        snprintf(err, err_sz, "failed to read loadtime plan %s errno=%d",
                 plan_path, errno);
        return -1;
    }
    const char *steps_end = NULL;
    const char *steps = json_array_at(plan_json, "steps", &steps_end);
    if (!steps) {
        snprintf(err, err_sz, "loadtime plan %s missing steps", plan_path);
        free(plan_json);
        return -1;
    }

    char workdir_base[320];
    if (loadtime_select_workdir_base(workdir_base, sizeof(workdir_base),
                                     err, err_sz) != 0) {
        free(plan_json);
        return -1;
    }
    static uint32_t seq;
    uint32_t my_seq = __sync_fetch_and_add(&seq, 1);
    char workdir_name[64];
    snprintf(workdir_name, sizeof(workdir_name), "loadtime_%d_%u",
             getpid(), my_seq);
    char workdir[360];
    if (loadtime_join_path(workdir, sizeof(workdir), workdir_base,
                           workdir_name, err, err_sz) != 0) {
        free(plan_json);
        return -1;
    }
    if (mkdir(workdir, 0755) != 0 && errno != EEXIST) {
        snprintf(err, err_sz, "failed to create loadtime workdir errno=%d",
                 errno);
        free(plan_json);
        return -1;
    }

    char cur[360], nxt[360], report[360], target_json[360], map_values_dir[360];
    if (loadtime_join_path(cur, sizeof(cur), workdir, "input.bin",
                           err, err_sz) != 0 ||
        loadtime_join_path(nxt, sizeof(nxt), workdir, "output.next.bin",
                           err, err_sz) != 0 ||
        loadtime_join_path(report, sizeof(report), workdir, "report.json",
                           err, err_sz) != 0 ||
        loadtime_join_path(map_values_dir, sizeof(map_values_dir), workdir,
                           "map-values", err, err_sz) != 0) {
        free(plan_json);
        return -1;
    }
    if (loadtime_prepare_target(workdir, target_json, sizeof(target_json),
                                err, err_sz) != 0) {
        snprintf(err, err_sz, "failed to prepare target.json in %s", workdir);
        free(plan_json);
        return -1;
    }

    size_t input_bytes = (size_t)attr->insn_cnt * sizeof(struct bpf_insn);
    uint64_t input_hash = normalized_prog_hash(input_insns, attr->insn_cnt);
    if (loadtime_write_file(cur, input_insns, input_bytes) != 0) {
        snprintf(err, err_sz, "failed to write loadtime input %s errno=%d",
                 cur, errno);
        free(plan_json);
        return -1;
    }

    struct shim_map_ref *map_refs = NULL;
    uint32_t map_ref_n = 0;
    uint32_t *map_ids = NULL, *map_types = NULL, map_n = 0;
    char map_ids_csv[1024];
    if (loadtime_collect_maps(input_insns, attr->insn_cnt, &map_refs,
                              &map_ref_n, &map_ids, &map_types, &map_n,
                              map_ids_csv, sizeof(map_ids_csv)) != 0) {
        snprintf(err, err_sz, "failed to collect loadtime map ids");
        free(plan_json);
        return -1;
    }
    const char *snapshot_root = getenv("BPFREJIT_SHIM_MAP_SNAPSHOT_ROOT");
    if (snapshot_root && snapshot_root[0]) {
        int remap_rc = remap_saved_map_snapshots(map_values_dir, snapshot_root,
                                                 input_insns, attr->insn_cnt,
                                                 attr->prog_type, map_refs,
                                                 map_ref_n, map_ids, map_types,
                                                 map_n, err, err_sz);
        if (remap_rc == SHIM_MAP_SNAPSHOT_UNAVAILABLE) {
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        if (remap_rc != 0) {
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
    } else {
        write_map_snapshots(map_values_dir, map_ids, map_types, map_n);
    }

    char fd_to_id_path[360], canon[360], canon_log[360];
    if (loadtime_join_path(fd_to_id_path, sizeof(fd_to_id_path), workdir,
                           "fd-to-id.json", err, err_sz) != 0 ||
        loadtime_join_path(canon, sizeof(canon), workdir, "input.canon.bin",
                           err, err_sz) != 0 ||
        loadtime_join_path(canon_log, sizeof(canon_log), workdir,
                           "canonicalize.log", err, err_sz) != 0) {
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return -1;
    }
    if (loadtime_write_fd_to_id_json(fd_to_id_path, map_refs, map_ref_n) != 0) {
        snprintf(err, err_sz, "failed to write loadtime fd-to-id map %s errno=%d",
                 fd_to_id_path, errno);
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return -1;
    }
    if (run_canonicalize(cur, canon, target_json, map_ids_csv,
                         fd_to_id_path, canon_log) != 0) {
        char err_tail[1024] = {0};
        read_tail_escaped(canon_log, err_tail, sizeof(err_tail));
        snprintf(err, err_sz, "loadtime canonicalize failed: %s", err_tail);
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return -1;
    }
    if (rename(canon, cur) != 0) {
        snprintf(err, err_sz, "failed to install canonicalized bytecode errno=%d",
                 errno);
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return -1;
    }

    char prog_type_name[32];
    snprintf(prog_type_name, sizeof(prog_type_name), "%s",
             prog_type_short_name(attr->prog_type));
    char prog_name[17] = {0};
    memcpy(prog_name, attr->prog_name, 16);
    log_line("loadtime policy prog=%s policy_hash=%016llx insn_cnt=%u",
             prog_name, (unsigned long long)input_hash, attr->insn_cnt);
    char prog_id_str[] = "0";

    char verifier_log[360];
    if (loadtime_join_path(verifier_log, sizeof(verifier_log), workdir,
                           "verifier_log_initial.log", err, err_sz) != 0) {
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return -1;
    }
    if (loadtime_probe_bytecode_acceptance(attr, attr_size, cur, target_json,
                                           map_ids, map_n, verifier_log) != 0) {
        log_line("loadtime original bytecode rejected by verifier errno=%d "
                 "log=%s; passing original BPF_PROG_LOAD through",
                 errno, verifier_log);
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return 0;
    }

    int step_seq = 0;
    const char *scur = steps;
    const char *so_s, *so_e;
    while (json_array_next_obj(&scur, steps_end, &so_s, &so_e)) {
        size_t slen = (size_t)(so_e - so_s);
        char *so = (char *)malloc(slen + 1);
        if (!so) {
            snprintf(err, err_sz, "oom copying loadtime step");
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        memcpy(so, so_s, slen);
        so[slen] = 0;
        char name[64] = {0};
        char cmdbuf[4096] = {0};
        json_get_str(so, "name", name, sizeof(name));
        json_get_str(so, "command", cmdbuf, sizeof(cmdbuf));
        char command_key[96], override_cmd[4096] = {0};
        loadtime_command_key_for_prog(prog_name, command_key, sizeof(command_key));
        if (json_get_str(so, command_key, override_cmd, sizeof(override_cmd)))
            snprintf(cmdbuf, sizeof(cmdbuf), "%s", override_cmd);
        loadtime_command_key_for_prog_insn_count(prog_name, attr->insn_cnt,
                                                 command_key,
                                                 sizeof(command_key));
        if (json_get_str(so, command_key, override_cmd, sizeof(override_cmd)))
            snprintf(cmdbuf, sizeof(cmdbuf), "%s", override_cmd);
        loadtime_command_key_for_hash(input_hash, command_key,
                                      sizeof(command_key));
        if (json_get_str(so, command_key, override_cmd, sizeof(override_cmd)))
            snprintf(cmdbuf, sizeof(cmdbuf), "%s", override_cmd);
        free(so);

        char step_name_buf[64];
        snprintf(step_name_buf, sizeof(step_name_buf),
                 "verifier_log_step%d.log", step_seq);
        if (loadtime_join_path(verifier_log, sizeof(verifier_log), workdir,
                               step_name_buf, err, err_sz) != 0) {
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        snprintf(step_name_buf, sizeof(step_name_buf),
                 "output.next.%d.bin", step_seq);
        if (loadtime_join_path(nxt, sizeof(nxt), workdir, step_name_buf,
                               err, err_sz) != 0) {
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        snprintf(step_name_buf, sizeof(step_name_buf),
                 "report.%d.json", step_seq);
        if (loadtime_join_path(report, sizeof(report), workdir, step_name_buf,
                               err, err_sz) != 0) {
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        unlink(nxt);
        unlink(report);

        const char *vars[9][2] = {
            {"PROG_ID", prog_id_str}, {"PROG_TYPE", prog_type_name},
            {"INPUT", cur}, {"OUTPUT", nxt}, {"REPORT", report},
            {"WORKDIR", workdir}, {"TARGET", target_json},
            {"MAP_IDS", map_ids_csv}, {"MAP_VALUES", map_values_dir},
        };
        char resolved[4200];
        loadtime_substitute_vars(resolved, sizeof(resolved), cmdbuf, vars, 9);
        char step_log[360];
        snprintf(step_name_buf, sizeof(step_name_buf), "step%d.log", step_seq);
        if (loadtime_join_path(step_log, sizeof(step_log), workdir,
                               step_name_buf, err, err_sz) != 0) {
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        uint64_t elapsed_ms = 0;
        if (loadtime_run_shell(resolved, step_log, &elapsed_ms) != 0) {
            snprintf(err, err_sz, "loadtime bpfopt step %s failed; log=%s",
                     name[0] ? name : "<unnamed>", step_log);
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        struct stat nst;
        if (stat(nxt, &nst) != 0 || nst.st_size == 0) {
            snprintf(err, err_sz,
                     "loadtime bpfopt step %s produced no output bytecode; log=%s",
                     name[0] ? name : "<unnamed>", step_log);
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        if (loadtime_probe_bytecode_acceptance(attr, attr_size, nxt, target_json,
                                               map_ids, map_n, verifier_log) != 0) {
            snprintf(err, err_sz,
                     "loadtime verifier probe failed after step %s errno=%d log=%s",
                     name[0] ? name : "<unnamed>", errno, verifier_log);
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        if (loadtime_append_step_report(prog_name, prog_type_name,
                                        name[0] ? name : "<unnamed>",
                                        step_seq, elapsed_ms, workdir,
                                        report) != 0) {
            snprintf(err, err_sz, "failed to append loadtime report %s errno=%d",
                     getenv("BPFREJIT_SHIM_LOADTIME_REPORTS") ?
                         getenv("BPFREJIT_SHIM_LOADTIME_REPORTS") : "",
                     errno);
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        rename(nxt, cur);
        log_line("loadtime step prog=%s step=%s elapsed_ms=%lu",
                 prog_name, name, (unsigned long)elapsed_ms);
        step_seq++;
    }

    uint32_t out_insn_cnt = 0;
    struct bpf_insn *optimized = loadtime_read_bytecode(cur, &out_insn_cnt);
    if (!optimized || out_insn_cnt == 0) {
        snprintf(err, err_sz, "loadtime optimized bytecode missing at %s", cur);
        free(optimized);
        free(map_refs);
        free(map_ids);
        free(map_types);
        free(plan_json);
        return -1;
    }

    int *fd_array = NULL;
    uint32_t fd_array_n = 0;
    int needs_fd_array = loadtime_bytecode_needs_fd_array(optimized, out_insn_cnt);
    if (needs_fd_array) {
        if (build_full_fd_array(target_json, map_ids, map_n,
                                &fd_array, &fd_array_n) != 0) {
            snprintf(err, err_sz, "failed to build loadtime fd_array");
            free(optimized);
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
        if (!fd_array || fd_array_n == 0) {
            snprintf(err, err_sz, "loadtime bytecode needs fd_array but none was built");
            free_full_fd_array(fd_array, fd_array_n);
            free(optimized);
            free(map_refs);
            free(map_ids);
            free(map_types);
            free(plan_json);
            return -1;
        }
    }

    memset(out->attr_buf, 0, sizeof(out->attr_buf));
    size_t copy = attr_size < sizeof(out->attr_buf) ? attr_size : sizeof(out->attr_buf);
    memcpy(out->attr_buf, attr, copy);
    union bpf_attr *a = (union bpf_attr *)(void *)out->attr_buf;
    a->insns = (uintptr_t)optimized;
    a->insn_cnt = out_insn_cnt;
    a->fd_array = 0;
    if (fd_array) a->fd_array = (uintptr_t)fd_array;
    if (sizeof(out->attr_buf) >= 152)
        memset(out->attr_buf + 148, 0, 4);
    a->func_info = 0;
    a->func_info_cnt = 0;
    a->func_info_rec_size = 0;
    a->line_info = 0;
    a->line_info_cnt = 0;
    a->line_info_rec_size = 0;
    a->core_relos = 0;
    a->core_relo_cnt = 0;
    a->core_relo_rec_size = 0;

    out->insns = optimized;
    out->fd_array = fd_array;
    out->fd_array_n = fd_array_n;
    out->attr_size = sizeof(out->attr_buf);
    log_line("loadtime optimized prog=%s insns=%u->%u maps=%u workdir=%s",
             prog_name, attr->insn_cnt, out_insn_cnt, map_n, workdir);
    free(map_refs);
    free(map_ids);
    free(map_types);
    free(plan_json);
    return 1;
}

static void loadtime_result_free(struct loadtime_result *result) {
    if (!result) return;
    free_full_fd_array(result->fd_array, result->fd_array_n);
    free(result->insns);
    memset(result, 0, sizeof(*result));
}

#endif /* BPFREJIT_SHIM_LOADTIME_H */
