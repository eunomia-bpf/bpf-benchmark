#ifndef BPFREJIT_SHIM_EXECUTE_PLAN_H
#define BPFREJIT_SHIM_EXECUTE_PLAN_H

/* Substitute ${VAR} occurrences in `in` to `out`. Vars known: PROG_ID,
 * PROG_TYPE, INPUT, OUTPUT, REPORT, WORKDIR, TARGET. Unknown vars stay as
 * literal ${VAR} (so /bin/sh's own expansion can still see them via env). */
static void substitute_vars(char *out, size_t out_sz, const char *in,
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
                    /* leave ${VAR} literal so shell can substitute */
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

/* Per-step outcome from the inner execute_plan loop. */
struct step_result {
    int ok;
    int code;                       /* subprocess exit code */
    int failure_kind;               /* 0=none, 1=bpfopt, 2=rejit, 3=partial-reattach */
    uint64_t bpfopt_ms;
    uint64_t rejit_ms;              /* 0 if no reload attempted */
    char err_msg[2048];
    char report_path[320];
    char output_path[320];
    char *report_json;              /* raw validated JSON from ${REPORT}, or NULL */
};

static const char *step_status(const struct step_result *sr) {
    if (sr->ok) return "ok";
    return sr->failure_kind == 1 ? "failed_bpfopt" : "failed_rejit";
}

static void command_key_for_prog(const char *prog_name, char *out,
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

static char **env_without_ld_preload(void) {
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

static char *base64_encode_bytes(const unsigned char *bytes, size_t len) {
    static const char table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t out_len = ((len + 2) / 3) * 4;
    char *out = (char *)malloc(out_len + 1);
    if (!out) return NULL;
    size_t o = 0;
    for (size_t i = 0; i < len; i += 3) {
        size_t rem = len - i;
        unsigned int n = ((unsigned int)bytes[i] << 16) |
                         ((rem > 1 ? (unsigned int)bytes[i + 1] : 0) << 8) |
                         (rem > 2 ? (unsigned int)bytes[i + 2] : 0);
        out[o++] = table[(n >> 18) & 0x3f];
        out[o++] = table[(n >> 12) & 0x3f];
        out[o++] = rem > 1 ? table[(n >> 6) & 0x3f] : '=';
        out[o++] = rem > 2 ? table[n & 0x3f] : '=';
    }
    out[o] = 0;
    return out;
}

static char *tar_workdir_b64(const char *workdir) {
    int pipefd[2];
    if (pipe(pipefd) != 0) {
        log_line("tar workdir pipe failed: errno=%d", errno);
        return NULL;
    }

    posix_spawn_file_actions_t fa;
    int fa_inited = (posix_spawn_file_actions_init(&fa) == 0);
    if (!fa_inited) {
        real_close(pipefd[0]);
        real_close(pipefd[1]);
        return NULL;
    }
    posix_spawn_file_actions_adddup2(&fa, pipefd[1], STDOUT_FILENO);
    posix_spawn_file_actions_addclose(&fa, pipefd[0]);
    posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, "/dev/null",
                                     O_WRONLY, 0);

    char *const argv[] = {"tar", "-czf", "-", "-C", (char *)workdir, ".", NULL};
    char **clean_env = env_without_ld_preload();
    pid_t pid;
    int rc = posix_spawnp(&pid, "tar", &fa, NULL, argv,
                          clean_env ? clean_env : environ);
    free(clean_env);
    posix_spawn_file_actions_destroy(&fa);
    real_close(pipefd[1]);
    if (rc != 0) {
        real_close(pipefd[0]);
        log_line("tar workdir spawn failed: rc=%d workdir=%s", rc, workdir);
        return NULL;
    }

    unsigned char *data = NULL;
    size_t len = 0, cap = 0;
    int read_failed = 0;
    for (;;) {
        unsigned char chunk[8192];
        ssize_t n = read(pipefd[0], chunk, sizeof(chunk));
        if (n > 0) {
            if (len + (size_t)n > cap) {
                size_t want = cap ? cap * 2 : 65536;
                while (want < len + (size_t)n) {
                    size_t next = want * 2;
                    if (next <= want) { read_failed = 1; break; }
                    want = next;
                }
                if (read_failed) break;
                unsigned char *nr = (unsigned char *)realloc(data, want);
                if (!nr) { read_failed = 1; break; }
                data = nr;
                cap = want;
            }
            memcpy(data + len, chunk, (size_t)n);
            len += (size_t)n;
            continue;
        }
        if (n == 0) break;
        if (errno == EINTR) continue;
        read_failed = 1;
        break;
    }
    real_close(pipefd[0]);
    int st = 0;
    waitpid(pid, &st, 0);
    if (read_failed || !WIFEXITED(st) || WEXITSTATUS(st) != 0) {
        log_line("tar workdir failed: read_failed=%d exit=%d workdir=%s",
                 read_failed, WIFEXITED(st) ? WEXITSTATUS(st) : -1, workdir);
        free(data);
        return NULL;
    }
    char *encoded = base64_encode_bytes(data ? data : (const unsigned char *)"", len);
    free(data);
    return encoded;
}

static int append_workdir_tar_b64(char **resp, size_t *cap, size_t *len,
                                  const char *workdir, int *artifact_count,
                                  int artifact_limit) {
    if (artifact_limit >= 0 && *artifact_count >= artifact_limit)
        return 0;
    (*artifact_count)++;
    char *encoded = tar_workdir_b64(workdir);
    if (!encoded)
        return 0;
    int rc = buf_appendf(resp, cap, len, ",\"workdir_tar_b64\":\"%s\"",
                         encoded);
    free(encoded);
    return rc;
}

static int keep_all_workdirs_enabled(void) {
    const char *mode = getenv("KEEP_WORKDIRS");
    if (mode && strcmp(mode, "all") == 0)
        return 1;
    mode = getenv("BPFREJIT_KEEP_ALL_WORKDIRS");
    return mode && mode[0] && strcmp(mode, "0") != 0;
}

static int json_trailing_ws_only(const char *s) {
    for (; *s; s++) {
        if (*s != ' ' && *s != '\n' && *s != '\r' && *s != '\t')
            return 0;
    }
    return 1;
}

static int json_token_is_null(const char *json, const jsmntok_t *tok) {
    return tok->type == JSMN_PRIMITIVE &&
           tok->end - tok->start == 4 &&
           strncmp(json + tok->start, "null", 4) == 0;
}

static void json_minify_in_place(char *s) {
    char *w = s;
    int in_str = 0;
    int escaped = 0;
    for (char *p = s; *p; p++) {
        char c = *p;
        if (in_str) {
            *w++ = c;
            if (escaped) {
                escaped = 0;
            } else if (c == '\\') {
                escaped = 1;
            } else if (c == '"') {
                in_str = 0;
            }
            continue;
        }
        if (c == '"') {
            in_str = 1;
            *w++ = c;
        } else if (c != ' ' && c != '\n' && c != '\r' && c != '\t') {
            *w++ = c;
        }
    }
    *w = 0;
}

static char *read_report_json_or_null(const char *path, char *err,
                                      size_t err_sz) {
    if (err_sz) err[0] = 0;
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        if (errno == ENOENT)
            return NULL;
        snprintf(err, err_sz, "open %s failed errno=%d", path, errno);
        return NULL;
    }
    struct stat st;
    if (fstat(fd, &st) != 0) {
        snprintf(err, err_sz, "stat %s failed errno=%d", path, errno);
        real_close(fd);
        return NULL;
    }
    if (st.st_size <= 0 || st.st_size > 1024 * 1024) {
        snprintf(err, err_sz, "invalid report size at %s: %lld", path,
                 (long long)st.st_size);
        real_close(fd);
        return NULL;
    }
    char *buf = (char *)malloc((size_t)st.st_size + 1);
    if (!buf) {
        snprintf(err, err_sz, "oom reading report %s", path);
        real_close(fd);
        return NULL;
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
        snprintf(err, err_sz, "read %s failed errno=%d", path, errno);
        free(buf);
        real_close(fd);
        return NULL;
    }
    real_close(fd);
    buf[off] = 0;

    jsmntok_t *tokens = NULL;
    int count = 0;
    if (json_parse_alloc(buf, &tokens, &count) != 0 || count <= 0 ||
        tokens[0].start < 0 || tokens[0].end < tokens[0].start ||
        (tokens[0].type != JSMN_OBJECT &&
         !json_token_is_null(buf, &tokens[0])) ||
        !json_trailing_ws_only(buf + tokens[0].end)) {
        snprintf(err, err_sz, "invalid JSON report at %s", path);
        free(tokens);
        free(buf);
        return NULL;
    }
    free(tokens);
    json_minify_in_place(buf);
    return buf;
}

/* Run one bpfopt pass on a prog. Updates `cur` (input bytecode path) and
 * `step_seq` on success and after successful reload_and_reattach. */
static void run_step(struct prog_entry *pd,
                     const char *workdir, const char *prog_type_name,
                     const char *prog_id_str, const char *target_json,
                     const char *map_ids_csv, const char *map_values_dir,
                     uint32_t *local_kernel_ids, uint32_t nr_maps,
                     char *cur, const char *nxt, const char *report,
                     int *step_seq, const char *step_name,
                     const char *command, struct step_result *out) {
    memset(out, 0, sizeof(*out));
    (void)step_name;
    snprintf(out->report_path, sizeof(out->report_path), "%s", report);
    snprintf(out->output_path, sizeof(out->output_path), "%s", cur);

    char verifier_states_in[320], verifier_log[320];
    if (*step_seq == 0)
        snprintf(verifier_states_in, sizeof(verifier_states_in),
                 "%s/verifier_log_initial.log", workdir);
    else
        snprintf(verifier_states_in, sizeof(verifier_states_in),
                 "%s/verifier_log_step%d.log", workdir, *step_seq - 1);
    snprintf(verifier_log, sizeof(verifier_log),
             "%s/verifier_log_step%d.log", workdir, *step_seq);
    unlink(nxt);
    unlink(report);

    const char *vars[10][2] = {
        {"PROG_ID", prog_id_str}, {"PROG_TYPE", prog_type_name},
        {"INPUT", cur}, {"OUTPUT", nxt}, {"REPORT", report},
        {"WORKDIR", workdir}, {"TARGET", target_json},
        {"MAP_IDS", map_ids_csv}, {"MAP_VALUES", map_values_dir},
        {"VERIFIER_STATES", verifier_states_in},
    };
    char resolved[4200];
    substitute_vars(resolved, sizeof(resolved), command, vars, 10);

    /* /bin/sh -c <resolved> with LD_PRELOAD stripped, stdout+stderr to log */
    char **clean_env = env_without_ld_preload();
    char subproc_log[320];
    snprintf(subproc_log, sizeof(subproc_log), "%s/step%d.log", workdir, *step_seq);
    char *const argv[] = {"/bin/sh", "-c", resolved, NULL};
    posix_spawn_file_actions_t fa;
    int fa_inited = (posix_spawn_file_actions_init(&fa) == 0);
    if (fa_inited) {
        posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, subproc_log,
                                         O_WRONLY | O_CREAT | O_TRUNC, 0644);
        posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, subproc_log,
                                         O_WRONLY | O_APPEND, 0);
    }
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    pid_t pid;
    int rc = posix_spawn(&pid, "/bin/sh", fa_inited ? &fa : NULL, NULL, argv,
                         clean_env ? clean_env : environ);
    if (fa_inited) posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0) {
        out->failure_kind = 1;
        snprintf(out->err_msg, sizeof(out->err_msg), "spawn failed rc=%d", rc);
        return;
    }
    int status = 0;
    waitpid(pid, &status, 0);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    out->bpfopt_ms = (uint64_t)(t1.tv_sec - t0.tv_sec) * 1000ULL
                     + (uint64_t)((t1.tv_nsec - t0.tv_nsec) / 1000000);
    int bpfopt_ok = WIFEXITED(status) && WEXITSTATUS(status) == 0;
    out->code = WIFEXITED(status) ? WEXITSTATUS(status) : -1;

    char report_err[512];
    out->report_json = read_report_json_or_null(report, report_err,
                                                sizeof(report_err));
    if (report_err[0]) {
        out->failure_kind = 1;
        char escaped[1024];
        json_escape_into(report_err, strlen(report_err), escaped,
                         sizeof(escaped));
        snprintf(out->err_msg, sizeof(out->err_msg),
                 "read step report at %s: %s", report, escaped);
        return;
    }

    if (!bpfopt_ok) {
        out->failure_kind = 1;
        read_tail_escaped(subproc_log, out->err_msg, sizeof(out->err_msg));
        return;
    }

    /* bpfopt produced output? If empty, this is a utility step; advance seq
     * but do nothing to kernel. */
    struct stat nst;
    if (stat(nxt, &nst) != 0 || nst.st_size == 0) {
        out->ok = 1;
        return;
    }

    /* New bytecode in nxt → reload + reattach + capture verifier states.
     * 16 MB keeps large-prog verifier logs intact — large progs (e.g.
     * katran balancer.bpf.o, 67939 insns) overflow a 1 MB buffer at
     * log_level=2 and the kernel returns -ENOSPC, masking the real cause. */
    const size_t verifier_buf_sz = 16 * 1024 * 1024;
    char *verifier_buf = (char *)malloc(verifier_buf_sz);
    if (!verifier_buf) {
        out->failure_kind = 2;
        snprintf(out->err_msg, sizeof(out->err_msg),
                 "verifier log buffer alloc failed");
        return;
    }
    enum reload_status rs = reload_and_reattach(pd, nxt, target_json,
                                                local_kernel_ids, nr_maps,
                                                verifier_buf,
                                                verifier_buf_sz,
                                                &out->rejit_ms);
    if (rs == RELOAD_FAILED_REJIT) {
        out->failure_kind = 2;
        size_t vl = strnlen(verifier_buf, verifier_buf_sz);
        /* Capture the tail of the verifier log — the actual error message
         * comes LAST, before the summary line. */
        const char *tail = verifier_buf;
        size_t tail_n = vl;
        if (vl > 1800) { tail = verifier_buf + (vl - 1800); tail_n = 1800; }
        json_escape_into(tail, tail_n, out->err_msg, sizeof(out->err_msg));
        free(verifier_buf);
        return;
    }
    if (rs == RELOAD_PARTIAL_ATTACH) {
        out->failure_kind = 3;
        size_t vl = strnlen(verifier_buf, verifier_buf_sz);
        if (vl > 0) {
            const char *tail = verifier_buf;
            size_t tail_n = vl;
            if (vl > 1800) { tail = verifier_buf + (vl - 1800); tail_n = 1800; }
            json_escape_into(tail, tail_n, out->err_msg, sizeof(out->err_msg));
        } else {
            snprintf(out->err_msg, sizeof(out->err_msg),
                     "BPF_PROG_LOAD ok but ≥1 reattach failed (no detail)");
        }
        free(verifier_buf);
        return;
    }
    if (rs != RELOAD_OK) {
        out->failure_kind = 2;
        snprintf(out->err_msg, sizeof(out->err_msg),
                 "reload_and_reattach internal error");
        free(verifier_buf);
        return;
    }
    free(verifier_buf);

    /* Write the new prog's verifier log for the next step. */
    if (pd->discovered_from_fd)
        capture_rejit_verifier_states(pd, nxt, target_json, local_kernel_ids,
                                      nr_maps, verifier_log);
    else
        capture_verifier_states(pd, nxt, target_json, local_kernel_ids,
                                nr_maps, verifier_log);
    rename(nxt, cur);
    pthread_mutex_lock(&state_mutex);
    pd->step_seq = *step_seq + 1;
    pthread_mutex_unlock(&state_mutex);
    (*step_seq)++;
    out->ok = 1;
}

/* Per-program setup performed before the step loop. Returns 0 on success or
 * fills `*err_out` and returns -1. */
struct prog_workdir {
    char workdir[280];
    char cur[320], nxt[320], report[320], target_json[320];
    char map_values_dir[320];
};

static int prog_workdir_init(struct prog_entry *pd, uint32_t want_id,
                             struct prog_workdir *w,
                             uint32_t **out_local_ids, uint32_t **out_local_types,
                             uint32_t **out_local_loader_fds, uint32_t *out_nr_maps,
                             char *map_ids_csv, size_t map_ids_csv_sz,
                             char *err_out, size_t err_sz) {
    pthread_mutex_lock(&state_mutex);
    (void)dedup_snapshot_by_kid(pd->snap_fds, pd->snap_kids, pd->snap_types,
                                pd->snap_n, out_local_ids, out_local_types,
                                out_local_loader_fds, out_nr_maps);
    uint32_t fd2id_n = pd->snap_n;
    uint32_t *fd2id_fds = NULL, *fd2id_kids = NULL;
    if (fd2id_n > 0) {
        fd2id_fds = (uint32_t *)malloc(fd2id_n * sizeof(uint32_t));
        fd2id_kids = (uint32_t *)malloc(fd2id_n * sizeof(uint32_t));
        if (fd2id_fds && fd2id_kids) {
            memcpy(fd2id_fds, pd->snap_fds, fd2id_n * sizeof(uint32_t));
            memcpy(fd2id_kids, pd->snap_kids, fd2id_n * sizeof(uint32_t));
        } else {
            free(fd2id_fds); free(fd2id_kids);
            fd2id_fds = fd2id_kids = NULL;
            fd2id_n = 0;
        }
    }
    int canonicalized = pd->canonicalized;
    int map_refs_are_kernel_ids = pd->map_refs_are_kernel_ids;
    char bytecode_path[256];
    snprintf(bytecode_path, sizeof(bytecode_path), "%s", pd->bytecode_path);
    pthread_mutex_unlock(&state_mutex);

    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    const char *arch = getenv("BPFREJIT_TARGET_ARCH");
    if (!arch) arch = "x86_64";
    snprintf(w->workdir, sizeof(w->workdir), "%s/work_%u", dir, want_id);
    mkdir(w->workdir, 0755);
    snprintf(w->cur, sizeof(w->cur), "%s/output.bin", w->workdir);
    snprintf(w->nxt, sizeof(w->nxt), "%s/output.next.bin", w->workdir);
    snprintf(w->report, sizeof(w->report), "%s/report.json", w->workdir);
    snprintf(w->target_json, sizeof(w->target_json), "%s/target.json", w->workdir);
    snprintf(w->map_values_dir, sizeof(w->map_values_dir), "%s/map-values", w->workdir);

    /* Per-prog target.json: copy from kinsnprober output once. */
    struct stat tst;
    if (stat(w->target_json, &tst) != 0) {
        char shared[320];
        snprintf(shared, sizeof(shared), "%s/target.json", dir);
        int sfd = open(shared, O_RDONLY);
        int wrote = 0;
        if (sfd >= 0) {
            int dfd = open(w->target_json, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (dfd >= 0) {
                char buf[4096]; ssize_t n;
                while ((n = read(sfd, buf, sizeof(buf))) > 0)
                    (void)!write(dfd, buf, n);
                close(dfd);
                wrote = 1;
            }
            real_close(sfd);
        }
        if (!wrote) {
            int fd = open(w->target_json, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd >= 0) {
                char buf[64];
                int n = snprintf(buf, sizeof(buf),
                                 "{\"arch\":\"%s\",\"kinsns\":{}}\n", arch);
                (void)!write(fd, buf, n);
                close(fd);
            }
        }
    }

    format_map_ids_csv(*out_local_ids, *out_nr_maps, map_ids_csv, map_ids_csv_sz);

    if (!canonicalized) {
        char canon_log[320], fd_to_id_path[320];
        snprintf(canon_log, sizeof(canon_log), "%s/canonicalize.log", w->workdir);
        snprintf(fd_to_id_path, sizeof(fd_to_id_path), "%s/fd-to-id.json", w->workdir);
        if (!map_refs_are_kernel_ids)
            (void)write_fd_to_id_json(fd_to_id_path, fd2id_fds, fd2id_kids, fd2id_n);
        if (run_canonicalize(bytecode_path, w->cur, w->target_json, map_ids_csv,
                             map_refs_are_kernel_ids ? NULL : fd_to_id_path,
                             canon_log) != 0) {
            char err_tail[1024] = {0};
            read_tail_escaped(canon_log, err_tail, sizeof(err_tail));
            snprintf(err_out, err_sz,
                     "bpfopt --canonicalize-map-refs failed: %s", err_tail);
            free(fd2id_fds); free(fd2id_kids);
            return -1;
        }
        write_map_snapshots(w->map_values_dir, *out_local_ids, *out_local_types,
                            *out_nr_maps);
        pthread_mutex_lock(&state_mutex);
        pd->canonicalized = 1;
        pthread_mutex_unlock(&state_mutex);
    }
    free(fd2id_fds); free(fd2id_kids);
    return 0;
}

/* execute_plan — app-level shim RPC. The runner sends only pass steps; shim
 * applies them to every BPF program tracked by this process. */
static void emit_execute_plan(int cli, const char *json) {
    const char *unsupported_end = NULL;
    if (json_array_at(json, "programs", &unsupported_end)) {
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"programs/prog_id execute_plan is unsupported by shim; send top-level steps\"}\n");
        return;
    }
    const char *all_steps_end = NULL;
    const char *all_steps = json_array_at(json, "steps", &all_steps_end);
    if (!all_steps) {
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"missing steps\"}\n");
        return;
    }
    discover_bpf_programs();
    uint32_t *all_prog_ids = NULL;
    uint32_t all_prog_n = 0;
    uint32_t all_prog_i = 0;
    pthread_mutex_lock(&state_mutex);
    for (int b = 0; b < BPF_STATE_BUCKETS; b++)
        for (struct prog_entry *e = prog_table[b]; e; e = e->next)
            if (e->kernel_prog_id) all_prog_n++;
    if (all_prog_n == 0) {
        pthread_mutex_unlock(&state_mutex);
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"no tracked BPF programs\"}\n");
        return;
    }
    all_prog_ids = (uint32_t *)calloc(all_prog_n, sizeof(*all_prog_ids));
    if (!all_prog_ids) {
        pthread_mutex_unlock(&state_mutex);
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"oom\"}\n");
        return;
    }
    uint32_t idx = 0;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++)
        for (struct prog_entry *e = prog_table[b]; e; e = e->next)
            if (e->kernel_prog_id && idx < all_prog_n)
                all_prog_ids[idx++] = e->kernel_prog_id;
    pthread_mutex_unlock(&state_mutex);

    size_t cap = 65536, len = 0;
    char *resp = (char *)malloc(cap);
    if (!resp) {
        free(all_prog_ids);
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"oom\"}\n");
        return;
    }
    if (buf_appendf(&resp, &cap, &len, "{\"status\":\"ok\",\"per_program\":{") != 0)
        goto resp_oom;

    int failure_artifacts = 0;
    int keep_all_workdirs = keep_all_workdirs_enabled();
    int artifact_limit = keep_all_workdirs ? -1 : 32;
    int first_prog = 1;
    while (all_prog_i < all_prog_n) {
        uint32_t want_id = all_prog_ids[all_prog_i++];
        char prog_id_str[32];
        snprintf(prog_id_str, sizeof(prog_id_str), "%u", want_id);

        pthread_mutex_lock(&state_mutex);
        struct prog_entry *pd = prog_find_by_kernel_id(want_id);
        char prog_type_name[32] = "socket_filter";
        char prog_name[17] = {0};
        uint32_t orig_insn_count = 0, prog_type_num = 0;
        if (pd) {
            snprintf(prog_type_name, sizeof(prog_type_name), "%s",
                     prog_type_short_name(pd->prog_type));
            memcpy(prog_name, pd->name, sizeof(prog_name));
            prog_type_num = pd->prog_type;
            orig_insn_count = pd->insn_cnt;
        }
        pthread_mutex_unlock(&state_mutex);

        if (buf_appendf(&resp, &cap, &len, "%s\"%u\":{",
                        first_prog ? "" : ",", want_id) != 0) {
            goto resp_oom;
        }
        first_prog = 0;

        if (!pd) {
            buf_appendf(&resp, &cap, &len,
                        "\"status\":\"error\","
                        "\"error_message\":\"prog_id %u not tracked by shim pid=%d\","
                        "\"prog_id\":%u,"
                        "\"program\":{\"prog_id\":%u,\"prog_name\":\"\","
                        "\"prog_type\":0,\"orig_insn_count\":0,"
                        "\"final_insn_count\":0},"
                        "\"passes\":[]}",
                        want_id, getpid(), want_id, want_id);
            continue;
        }

        /* Per-prog setup (canonicalize + map snapshots) — once per prog. */
        struct prog_workdir w;
        memset(&w, 0, sizeof(w));
        uint32_t nr_maps = 0;
        uint32_t *local_ids = NULL, *local_types = NULL, *local_loader_fds = NULL;
        char map_ids_csv[1024];
        char setup_err[1024] = {0};
        int setup_rc = prog_workdir_init(pd, want_id, &w, &local_ids,
                                         &local_types, &local_loader_fds,
                                         &nr_maps, map_ids_csv,
                                         sizeof(map_ids_csv),
                                         setup_err, sizeof(setup_err));
        if (setup_rc != 0) {
            char escaped[1024];
            json_escape_into(setup_err, strlen(setup_err), escaped, sizeof(escaped));
            buf_appendf(&resp, &cap, &len,
                        "\"status\":\"error\","
                        "\"error_message\":\"%s\","
                        "\"prog_id\":%u,"
                        "\"program\":{\"prog_id\":%u,\"prog_name\":\"%s\","
                        "\"prog_type\":%u,\"orig_insn_count\":%u,"
                        "\"final_insn_count\":%u},"
                        "\"passes\":[]",
                        escaped, want_id, want_id, prog_name, prog_type_num,
                        orig_insn_count, orig_insn_count);
            if (w.workdir[0] &&
                append_workdir_tar_b64(&resp, &cap, &len, w.workdir,
                                       &failure_artifacts,
                                       artifact_limit) != 0) {
                free(local_ids); free(local_types); free(local_loader_fds);
                goto resp_oom;
            }
            buf_appendf(&resp, &cap, &len, "}");
            free(local_ids); free(local_types); free(local_loader_fds);
            continue;
        }

        /* Step loop. */
        int prog_any_failed = 0;
        uint32_t final_insn_count = orig_insn_count;
        int step_seq = 0;
        pthread_mutex_lock(&state_mutex);
        if (pd) step_seq = pd->step_seq;
        pthread_mutex_unlock(&state_mutex);

        const char *scur = all_steps;
        const char *so_s, *so_e;
        int first_step = 1;
        buf_appendf(&resp, &cap, &len, "\"prog_id\":%u,\"passes\":[", want_id);
        while (json_array_next_obj(&scur, all_steps_end, &so_s, &so_e)) {
            size_t slen = (size_t)(so_e - so_s);
            char *so = (char *)malloc(slen + 1);
            if (!so) continue;
            memcpy(so, so_s, slen); so[slen] = 0;
            char name[64] = {0};
            char cmdbuf[4096] = {0};
            json_get_str(so, "name", name, sizeof(name));
            json_get_str(so, "command", cmdbuf, sizeof(cmdbuf));
            char command_key[96];
            char override_cmd[4096] = {0};
            command_key_for_prog(prog_name, command_key, sizeof(command_key));
            if (json_get_str(so, command_key, override_cmd,
                             sizeof(override_cmd)))
                snprintf(cmdbuf, sizeof(cmdbuf), "%s", override_cmd);
            long log_level = json_get_int(so, "log_level");
            if (log_level <= 0) log_level = 1;
            free(so);

            struct step_result sr;
            run_step(pd, w.workdir, prog_type_name, prog_id_str, w.target_json,
                     map_ids_csv, w.map_values_dir, local_ids, nr_maps,
                     w.cur, w.nxt, w.report, &step_seq, name, cmdbuf, &sr);
            pthread_mutex_lock(&state_mutex);
            if (pd && pd->kernel_prog_id)
                snprintf(prog_id_str, sizeof(prog_id_str), "%u",
                         pd->kernel_prog_id);
            pthread_mutex_unlock(&state_mutex);

            /* On success-with-new-bytecode, compute final_insn_count from cur. */
            struct stat cst;
            if (stat(w.cur, &cst) == 0 && cst.st_size > 0)
                final_insn_count = (uint32_t)(cst.st_size / sizeof(struct bpf_insn));

            if (!sr.ok) prog_any_failed = 1;
            char name_json[160], cmd_json[8192];
            json_escape_into(name, strlen(name), name_json, sizeof(name_json));
            json_escape_into(cmdbuf, strlen(cmdbuf), cmd_json, sizeof(cmd_json));
            buf_appendf(&resp, &cap, &len,
                        "%s{\"step\":{\"name\":\"%s\","
                        "\"command\":\"%s\",\"log_level\":%ld},"
                        "\"status\":\"%s\",",
                        first_step ? "" : ",",
                        name_json, cmd_json, log_level,
                        step_status(&sr));
            if (!sr.ok) {
                /* err_msg already json-escaped + bounded to 2 KB. Full logs
                 * and side inputs are attached once at the per-program level
                 * through workdir_tar_b64. */
                buf_appendf(&resp, &cap, &len,
                            "\"error\":\"%s\","
                            "\"exit_code\":%d",
                            sr.err_msg, sr.code);
            } else {
                buf_appendf(&resp, &cap, &len, "\"error\":null");
            }
            if (sr.report_json) {
                buf_appendf(&resp, &cap, &len,
                            ",\"bpfopt_summary\":%s", sr.report_json);
                free(sr.report_json);
            } else {
                buf_appendf(&resp, &cap, &len,
                            ",\"bpfopt_summary\":null");
            }
            buf_appendf(&resp, &cap, &len,
                        ",\"bpfopt_ms\":%lu,\"rejit_syscall_ms\":%lu",
                        (unsigned long)sr.bpfopt_ms,
                        (unsigned long)sr.rejit_ms);
            buf_appendf(&resp, &cap, &len, "}");
            first_step = 0;
        }
        uint32_t final_prog_id = want_id;
        pthread_mutex_lock(&state_mutex);
        if (pd && pd->kernel_prog_id)
            final_prog_id = pd->kernel_prog_id;
        pthread_mutex_unlock(&state_mutex);
        buf_appendf(&resp, &cap, &len,
                    "],\"status\":\"%s\","
                    "\"program\":{\"prog_id\":%u,\"prog_name\":\"%s\","
                    "\"prog_type\":%u,\"orig_insn_count\":%u,"
                    "\"final_insn_count\":%u}",
                    prog_any_failed ? "error" : "ok",
                    final_prog_id, prog_name, prog_type_num,
                    orig_insn_count, final_insn_count);
        if ((prog_any_failed || keep_all_workdirs) &&
            append_workdir_tar_b64(&resp, &cap, &len, w.workdir,
                                   &failure_artifacts,
                                   artifact_limit) != 0) {
            free(local_ids); free(local_types); free(local_loader_fds);
            goto resp_oom;
        }
        buf_appendf(&resp, &cap, &len, "}");

        free(local_ids); free(local_types); free(local_loader_fds);
        log_line("execute_plan prog_id=%u step_seq=%d status=%s",
                 want_id, step_seq, prog_any_failed ? "error" : "ok");
    }
    free(all_prog_ids);
    buf_appendf(&resp, &cap, &len, "}}\n");
    if (resp) (void)!write(cli, resp, len);
    free(resp);
    return;

resp_oom:
    free(all_prog_ids);
    dprintf(cli, "{\"status\":\"error\",\"error_message\":\"response oom\"}\n");
    free(resp);
}

#endif /* BPFREJIT_SHIM_EXECUTE_PLAN_H */
