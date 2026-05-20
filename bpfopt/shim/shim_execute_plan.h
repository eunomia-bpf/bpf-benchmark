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

/* execute_step — daemon-style RPC. Runner sends a pre-resolved shell command
 * (read from runner/config/passes/<pass>/default.yaml), shim substitutes
 * shim-owned vars and runs /bin/sh -c verbatim. Mirrors daemon's contract at
 * daemon/src/commands.rs:execute_one + daemon/src/server.rs:execute_plan.
 *
 *   request:  {"cmd":"execute_step","prog_id":<u32>,"command":"<sh>",
 *              "step_seq":<int optional>}
 *   response: {"ok":<bool>,"exit_code":<int>,"output":"<path>","report":"<path>",
 *              "bpfopt_ms":<u64>,"program":{...},"workdir_tar_b64":"..."}
 */
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
};

static const char *daemon_step_status(const struct step_result *sr) {
    if (sr->ok) return "ok";
    return sr->failure_kind == 1 ? "failed_bpfopt" : "failed_rejit";
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
    size_t n_env = 0; while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    size_t j = 0;
    for (size_t i = 0; clean_env && i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    if (clean_env) clean_env[j] = NULL;
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
     * 16 MB matches daemon's REJIT_VERBOSE_LOG_BUF_SIZE — large progs (e.g.
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
    capture_verifier_states(pd, nxt, target_json, local_kernel_ids, nr_maps,
                            verifier_log);
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
        (void)write_fd_to_id_json(fd_to_id_path, fd2id_fds, fd2id_kids, fd2id_n);
        if (run_canonicalize(bytecode_path, w->cur, w->target_json, map_ids_csv,
                             fd_to_id_path, canon_log) != 0) {
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

/* execute_plan — replaces daemon's execute_plan RPC. Input plan JSON:
 *   {"cmd":"execute_plan",
 *    "programs":[{"prog_id":N,
 *                 "steps":[{"name":"...","command":"...","log_level":N}]}]}
 * Response (same shape as daemon's): {"status":"ok","per_program":{...}}. */
static void emit_execute_plan(int cli, const char *json) {
    const char *progs_end = NULL;
    const char *progs = json_array_at(json, "programs", &progs_end);
    if (!progs) {
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"missing programs\"}\n");
        return;
    }

    size_t cap = 65536, len = 0;
    char *resp = (char *)malloc(cap);
    if (!resp) {
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"oom\"}\n");
        return;
    }
    if (buf_appendf(&resp, &cap, &len, "{\"status\":\"ok\",\"per_program\":{") != 0)
        goto resp_oom;

    const char *cursor = progs;
    const char *po_s, *po_e;
    int first_prog = 1;
    while (json_array_next_obj(&cursor, progs_end, &po_s, &po_e)) {
        size_t plen = (size_t)(po_e - po_s);
        char *po = (char *)malloc(plen + 1);
        if (!po) continue;
        memcpy(po, po_s, plen); po[plen] = 0;

        long pid_l = json_get_int(po, "prog_id");
        if (pid_l <= 0) { free(po); continue; }
        uint32_t want_id = (uint32_t)pid_l;
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
            free(po);
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
            free(po);
            continue;
        }

        /* Per-prog setup (canonicalize + map snapshots) — once per prog. */
        struct prog_workdir w;
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
                        "\"passes\":[]}",
                        escaped, want_id, want_id, prog_name, prog_type_num,
                        orig_insn_count, orig_insn_count);
            free(local_ids); free(local_types); free(local_loader_fds);
            free(po);
            continue;
        }

        /* Step loop. */
        int prog_any_failed = 0;
        uint32_t final_insn_count = orig_insn_count;
        int step_seq = 0;
        pthread_mutex_lock(&state_mutex);
        if (pd) step_seq = pd->step_seq;
        pthread_mutex_unlock(&state_mutex);

        const char *steps_end = NULL;
        const char *steps = json_array_at(po, "steps", &steps_end);
        const char *scur = steps;
        const char *so_s, *so_e;
        int first_step = 1;
        buf_appendf(&resp, &cap, &len, "\"prog_id\":%u,\"passes\":[", want_id);
        while (steps && json_array_next_obj(&scur, steps_end, &so_s, &so_e)) {
            size_t slen = (size_t)(so_e - so_s);
            char *so = (char *)malloc(slen + 1);
            if (!so) continue;
            memcpy(so, so_s, slen); so[slen] = 0;
            char name[64] = {0};
            char cmdbuf[4096] = {0};
            json_get_str(so, "name", name, sizeof(name));
            json_get_str(so, "command", cmdbuf, sizeof(cmdbuf));
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
                        daemon_step_status(&sr));
            if (!sr.ok) {
                /* err_msg already json-escaped + bounded to 2 KB. We do NOT
                 * include workdir_tar_b64 — base64-encoded tarballs of large
                 * prog workdirs (verifier logs, map dumps, bytecode) explode
                 * to hundreds of MB per step and overflow the socket
                 * response buffer. Failure tar is left on-disk under
                 * /tmp/work_<prog_id>/ for KEEP_WORKDIRS=1 collection. */
                buf_appendf(&resp, &cap, &len,
                            "\"error\":\"%s\","
                            "\"exit_code\":%d",
                            sr.err_msg, sr.code);
            } else {
                buf_appendf(&resp, &cap, &len, "\"error\":null");
            }
            buf_appendf(&resp, &cap, &len,
                        ",\"bpfopt_summary\":null,"
                        "\"bpfopt_ms\":%lu,\"rejit_syscall_ms\":%lu",
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
                    "\"final_insn_count\":%u}}",
                    prog_any_failed ? "error" : "ok",
                    final_prog_id, prog_name, prog_type_num,
                    orig_insn_count, final_insn_count);

        free(local_ids); free(local_types); free(local_loader_fds);
        free(po);
        log_line("execute_plan prog_id=%u step_seq=%d status=%s",
                 want_id, step_seq, prog_any_failed ? "error" : "ok");
    }
    buf_appendf(&resp, &cap, &len, "}}\n");
    if (resp) (void)!write(cli, resp, len);
    free(resp);
    return;

resp_oom:
    dprintf(cli, "{\"status\":\"error\",\"error_message\":\"response oom\"}\n");
    free(resp);
}

#endif /* BPFREJIT_SHIM_EXECUTE_PLAN_H */
