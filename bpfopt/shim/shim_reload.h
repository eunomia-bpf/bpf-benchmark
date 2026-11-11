#ifndef BPFREJIT_SHIM_RELOAD_H
#define BPFREJIT_SHIM_RELOAD_H

#ifndef BPF_F_REPLACE
#define BPF_F_REPLACE (1U << 2)
#endif

/* Result of reload_and_reattach. */
enum reload_status {
    RELOAD_OK = 0,         /* PROG_LOAD + all attaches succeeded */
    RELOAD_FAILED_REJIT,   /* PROG_LOAD rejected; verifier_log filled */
    RELOAD_PARTIAL_ATTACH, /* LOAD ok, ≥1 attach swap failed mid-way */
    RELOAD_INTERNAL,       /* OOM / I/O before any kernel call */
};

/* Replace the live kernel BPF program identified by `p` with the bytecode at
 * `new_bytecode_path`. After successful return, every link/perf_event that
 * was attached to the old prog points at the new one, and `p` is updated in
 * place so subsequent steps re-load against the new fd/id.
 *
 * Pre-conditions (caller-enforced):
 *   - `map_fds[]` (length nr_fds) is the deduped fd_array the canonicalized
 *     bytecode expects (one fd per BPF_PSEUDO_MAP_IDX slot).
 *   - `p->fd` is still the live, open prog fd.
 *
 * On failure modes:
 *   - RELOAD_FAILED_REJIT: verifier_log (size log_buf_sz) is populated.
 *     Old prog stays attached and live; caller treats step as FailedRejit
 *     and continues without advancing input.
 *   - RELOAD_PARTIAL_ATTACH: the new prog was loaded but ≥1 attach point
 *     swap failed. The kernel state is now mixed; caller logs the error
 *     but the step is best-effort marked as RELOAD_PARTIAL_ATTACH (no
 *     clean rollback exists — BPF_LINK_UPDATE is atomic per-link but
 *     can't undo prior successful swaps without re-applying old fd).
 *
 * Writes `*out_rejit_ms` (CLOCK_MONOTONIC, LOAD + all swap iterations). */
static enum reload_status reload_and_reattach(struct prog_entry *p,
                                              const char *new_bytecode_path,
                                              const char *target_json_path,
                                              const uint32_t *map_fds,
                                              uint32_t nr_fds,
                                              char *verifier_log,
                                              size_t log_buf_sz,
                                              uint64_t *out_rejit_ms) {
    if (out_rejit_ms) *out_rejit_ms = 0;
    if (verifier_log && log_buf_sz > 0) verifier_log[0] = 0;

    int bfd = open(new_bytecode_path, O_RDONLY);
    if (bfd < 0) return RELOAD_INTERNAL;
    struct stat st;
    if (fstat(bfd, &st) != 0 || st.st_size <= 0 ||
        (st.st_size % (off_t)sizeof(struct bpf_insn)) != 0) {
        real_close(bfd);
        return RELOAD_INTERNAL;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) { real_close(bfd); return RELOAD_INTERNAL; }
    ssize_t rd = read(bfd, insns, bytes);
    real_close(bfd);
    if (rd != (ssize_t)bytes) { free(insns); return RELOAD_INTERNAL; }

    /* Full fd_array: maps + BTF module fds (read from target.json). */
    int *fd_array = NULL;
    uint32_t fd_array_n = 0;
    (void)build_full_fd_array(target_json_path, map_fds, nr_fds,
                              &fd_array, &fd_array_n);

    /* Use the caller-supplied verifier_log buffer (or a small heap one if
     * absent) for diagnostics on failure. Successful loads run with verifier
     * logging disabled so large accepted programs cannot fail with ENOSPC. */
    char *log_buf = verifier_log;
    size_t log_size = log_buf_sz;
    char *owned_log = NULL;
    if (!log_buf) {
        log_size = 1 * 1024 * 1024;
        owned_log = (char *)malloc(log_size);
        log_buf = owned_log;
        if (!log_buf) {
            if (fd_array) {
                for (uint32_t i = 0; i < nr_fds; i++)
                    if (fd_array[i] >= 0) real_close(fd_array[i]);
                free(fd_array);
            }
            free(insns);
            return RELOAD_INTERNAL;
        }
    }

    /* Start from the captured original PROG_LOAD attr — preserves every
     * field tracee/etc. passed (line_info, func_info, core_relos, etc.)
     * without us having to enumerate them. Only patch the fields the reload
     * actually needs to swap, plus the fd-typed fields which we dup at
     * intercept time (the originals may already be closed). */
    union bpf_attr a = p->load_attr;
    a.insns = (uintptr_t)insns;
    a.insn_cnt = (uint32_t)(bytes / sizeof(struct bpf_insn));
    a.license = (uintptr_t)p->license;
    /* Open fresh fds for the BTF / attach-prog objects we captured by id.
     * These get closed below after PROG_LOAD returns (kernel takes refs
     * during the syscall; we only need the fd alive across the call). */
    int prog_btf_resolved = -1;
    int attach_btf_obj_resolved = -1;
    int attach_prog_resolved = -1;
    if (p->prog_btf_kid) {
        union bpf_attr ia = {0};
        ia.btf_id = p->prog_btf_kid;
        long r = real_syscall(SYS_bpf, BPF_BTF_GET_FD_BY_ID, &ia, sizeof(ia));
        if (r >= 0) prog_btf_resolved = (int)r;
    }
    if (p->attach_btf_obj_kid) {
        union bpf_attr ia = {0};
        ia.btf_id = p->attach_btf_obj_kid;
        long r = real_syscall(SYS_bpf, BPF_BTF_GET_FD_BY_ID, &ia, sizeof(ia));
        if (r >= 0) attach_btf_obj_resolved = (int)r;
    }
    if (p->attach_prog_kid) {
        union bpf_attr ia = {0};
        ia.prog_id = p->attach_prog_kid;
        long r = real_syscall(SYS_bpf, BPF_PROG_GET_FD_BY_ID, &ia, sizeof(ia));
        if (r >= 0) attach_prog_resolved = (int)r;
    }
    a.prog_btf_fd = (prog_btf_resolved >= 0) ? (uint32_t)prog_btf_resolved : 0;
    a.attach_btf_obj_fd = (attach_btf_obj_resolved >= 0)
                          ? (uint32_t)attach_btf_obj_resolved : 0;
    a.attach_prog_fd = (attach_prog_resolved >= 0)
                       ? (uint32_t)attach_prog_resolved : 0;
    /* Drop func_info / line_info / core_relos for fresh re-load.
     *
     * Per audit (docs/tmp/20260519-shim-audit/REPORT.md §2,§4): replaying
     * the original loader's func_info/line_info after a transformed
     * bytecode produces 'func_info BTF section doesn't match subprog
     * layout' (kernel check_btf_func) because the new bytecode has
     * different insn_off boundaries. The kernel hasn't yet finished
     * validating fresh-load metadata for transformed bytes — drop these
     * pointer/count pairs and let the kernel synthesise minimal info. */
    a.func_info = 0;
    a.func_info_cnt = 0;
    a.func_info_rec_size = 0;
    a.line_info = 0;
    a.line_info_cnt = 0;
    a.line_info_rec_size = 0;
    a.core_relos = 0;
    a.core_relo_cnt = 0;
    a.core_relo_rec_size = 0;
    /* BPF_F_TOKEN_FD requires a live token fd; clear it because the
     * loader's token fd may have been closed and we don't have a kid for
     * it. Kernel falls back to system-wide capability checks. Hard-coded
     * bit (1U<<8) so this works even when libbpf-sys is too old to expose
     * the constant. */
    a.prog_flags &= ~((uint32_t)(1U << 8));
    log_line("reload prog kid=%u type=%u prog_btf_fd=%u attach_btf_obj_fd=%u "
             "attach_prog_fd=%u attach_btf_id=%u expected_attach=%u "
             "nr_map_fds=%u",
             p->kernel_prog_id, p->prog_type, a.prog_btf_fd,
             a.attach_btf_obj_fd, a.attach_prog_fd, a.attach_btf_id,
             a.expected_attach_type, nr_fds);
    a.log_level = 0;
    a.log_buf = 0;
    a.log_size = 0;
    a.log_true_size = 0;
    if (fd_array) a.fd_array = (uintptr_t)fd_array;
    /* Clear fd_array_cnt from the captured load_attr. The original loader
     * may have set fd_array_cnt to its own array size; when kernel sees
     * a non-zero count it eagerly walks fd_array[0..fd_array_cnt) and
     * binds every entry as a map. Because our fd_array has BTF module
     * fds at higher slots (post-map-prefix shift), that eager bind fails
     * with EBADF/EINVAL ("fd N not pointing to valid bpf_map or btf").
     * fd_array_cnt == 0 keeps the kernel on the on-demand fdget path used by
     * the ReJIT path.
     *
     * libbpf-sys's union bpf_attr may lack the fd_array_cnt field name,
     * so we patch at the UAPI offset (148: 4 bytes after prog_token_fd
     * at 144) on a 256B buffer that's also generously sized for any
     * post-attr_buf tail-zero check. */
    char attr_buf[256] = {0};
    memcpy(attr_buf, &a, sizeof(a));
    /* offset 148 = fd_array_cnt; offset 144 = prog_token_fd. Zero both
     * so the kernel doesn't try eager map binding via the loader's
     * stale count and doesn't try to validate a closed token fd. */
    memset(attr_buf + 144, 0, 8);

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    long new_pfd = real_syscall(SYS_bpf, BPF_PROG_LOAD, attr_buf,
                                sizeof(attr_buf));
    int load_errno = (new_pfd < 0) ? errno : 0;
    if (new_pfd < 0 && log_buf && log_size > 0) {
        memset(log_buf, 0, log_size);
        char diag_attr_buf[256];
        memcpy(diag_attr_buf, attr_buf, sizeof(diag_attr_buf));
        union bpf_attr *diag = (union bpf_attr *)(void *)diag_attr_buf;
        diag->log_level = 1;
        diag->log_buf = (uintptr_t)log_buf;
        diag->log_size = (uint32_t)(log_size > 128 ? log_size - 128 : log_size);
        diag->log_true_size = 0;
        long diag_pfd = real_syscall(SYS_bpf, BPF_PROG_LOAD, diag_attr_buf,
                                     sizeof(diag_attr_buf));
        if (diag_pfd >= 0)
            real_close((int)diag_pfd);
    }

    /* Snapshot the fd_array (before freeing) so the failure context below
     * can report how many slots were -1. */
    uint32_t arr_neg1 = 0;
    if (fd_array) {
        for (uint32_t i = 0; i < fd_array_n; i++)
            if (fd_array[i] < 0) arr_neg1++;
    }
    free_full_fd_array(fd_array, fd_array_n);
    free(insns);
    /* Drop the per-reload BTF/prog fds — kernel held refs across the
     * syscall; our fds are not needed afterwards. */
    if (prog_btf_resolved >= 0) real_close(prog_btf_resolved);
    if (attach_btf_obj_resolved >= 0) real_close(attach_btf_obj_resolved);
    if (attach_prog_resolved >= 0) real_close(attach_prog_resolved);

    if (new_pfd < 0) {
        /* Always append the actual errno — verifier may have accepted (so the
         * log shows a success summary) yet PROG_LOAD still failed in a later
         * stage (JIT, attach validation, BTF resolution). The errno is the
         * only useful signal in those cases. */
        /* log_size includes the 128B reserved tail; lg is bounded by the
         * shrunk window passed to the kernel, so we always have room. */
        size_t lg = strnlen(log_buf, log_size);
        snprintf(log_buf + lg, log_size - lg,
                 "\nBPF_PROG_LOAD errno=%d (post-verifier)\n"
                 "ctx: prog_btf_fd=%u attach_btf_obj_fd=%u attach_prog_fd=%u "
                 "attach_btf_id=%u expected_attach=%u nr_map_fds=%u "
                 "prog_type=%u fd_array_n=%u fd_array_neg1=%u "
                 "prog_flags=0x%x insn_cnt=%u\n",
                 load_errno,
                 a.prog_btf_fd, a.attach_btf_obj_fd, a.attach_prog_fd,
                 a.attach_btf_id, a.expected_attach_type, nr_fds,
                 p->prog_type, fd_array_n, arr_neg1,
                 a.prog_flags, a.insn_cnt);
        clock_gettime(CLOCK_MONOTONIC, &t1);
        if (out_rejit_ms) *out_rejit_ms = (t1.tv_sec - t0.tv_sec) * 1000ULL
                                          + (t1.tv_nsec - t0.tv_nsec) / 1000000;
        free(owned_log);
        return RELOAD_FAILED_REJIT;
    }

    /* Swap attaches. BPF_LINK_UPDATE is atomic per-link. */
    int partial = 0;
    pthread_mutex_lock(&state_mutex);
    /* Snapshot lists locally — reattach syscalls release state_mutex
     * via real_syscall (kernel side, not shim re-entry, but be safe). */
    uint32_t nlinks = p->n_links, nperfs = p->n_perfs;
    uint32_t n_prog_attaches = p->n_prog_attaches, n_raw_tps = p->n_raw_tps;
    int *links = NULL, *perfs = NULL, *raw_tps = NULL;
    struct prog_attach_point *prog_attaches = NULL;
    if (nlinks) {
        links = (int *)malloc(nlinks * sizeof(int));
        if (links) memcpy(links, p->attached_link_fds, nlinks * sizeof(int));
        else nlinks = 0;
    }
    if (nperfs) {
        perfs = (int *)malloc(nperfs * sizeof(int));
        if (perfs) memcpy(perfs, p->attached_perf_fds, nperfs * sizeof(int));
        else nperfs = 0;
    }
    if (n_prog_attaches) {
        prog_attaches = (struct prog_attach_point *)
            malloc(n_prog_attaches * sizeof(*prog_attaches));
        if (prog_attaches)
            memcpy(prog_attaches, p->prog_attaches,
                   n_prog_attaches * sizeof(*prog_attaches));
        else
            n_prog_attaches = 0;
    }
    if (n_raw_tps) {
        raw_tps = (int *)malloc(n_raw_tps * sizeof(int));
        if (raw_tps) memcpy(raw_tps, p->attached_raw_tp_fds,
                            n_raw_tps * sizeof(int));
        else n_raw_tps = 0;
    }
    int old_prog_fd = p->fd;
    pthread_mutex_unlock(&state_mutex);

    /* Append per-failure detail into verifier_log (which the caller exposes
     * to the runner) so partial-attach errors are diagnostic, not opaque. */
    char *partial_detail = verifier_log;
    size_t partial_cap = log_buf_sz;
    size_t partial_len = partial_detail ? strnlen(partial_detail, partial_cap) : 0;
#define APPEND_DETAIL(...) do {                                              \
    if (partial_detail && partial_len < partial_cap - 1) {                   \
        int _n = snprintf(partial_detail + partial_len,                       \
                          partial_cap - partial_len, __VA_ARGS__);            \
        if (_n > 0) partial_len += (size_t)_n;                                \
        if (partial_len >= partial_cap) partial_len = partial_cap - 1;        \
    }                                                                         \
} while (0)
    /* Track new fds replacing old ones so the prog's attached_link_fds list
     * stays consistent after fallback-recreate. */
    int *replaced_with = (int *)malloc(nlinks * sizeof(int));
    if (replaced_with) for (uint32_t i = 0; i < nlinks; i++) replaced_with[i] = -1;
    for (uint32_t i = 0; i < nlinks; i++) {
        union bpf_attr u;
        memset(&u, 0, sizeof(u));
        u.link_update.link_fd = (uint32_t)links[i];
        u.link_update.new_prog_fd = (uint32_t)new_pfd;
        u.link_update.flags = 0;
        long r = real_syscall(SYS_bpf, BPF_LINK_UPDATE, &u, sizeof(u));
        if (r >= 0) continue;
        int upd_err = errno;
        /* Most BPF link types don't implement update_prog (only cgroup, tcx,
         * netns, bpf_iter do — see kernel/bpf/syscall.c). Fall back to:
         *   1. close(old_link_fd) — destroys the kernel attach
         *   2. BPF_LINK_CREATE with saved attrs and new prog_fd → new link
         *   3. record new fd so attached_link_fds reflects new state
         * The loader's old fd value becomes EBADF on subsequent use; for
         * benchmarks this is OK since the loader doesn't operate on links
         * during measurement. */
        pthread_mutex_lock(&state_mutex);
        struct link_entry *le = link_find(links[i]);
        char saved_blob[80];
        int have_blob = 0;
        if (le) {
            memcpy(saved_blob, le->create_attr_blob, sizeof(saved_blob));
            have_blob = 1;
        }
        pthread_mutex_unlock(&state_mutex);
        if (!have_blob) {
            log_line("reload_and_reattach: LINK_UPDATE failed and no saved "
                     "create attrs for link_fd=%d (errno=%d)",
                     links[i], upd_err);
            APPEND_DETAIL("link_fd=%d: LINK_UPDATE errno=%d, no saved attrs; ",
                          links[i], upd_err);
            partial = 1;
            continue;
        }
        union bpf_attr c;
        memset(&c, 0, sizeof(c));
        memcpy(&c.link_create, saved_blob, sizeof(c.link_create));
        c.link_create.prog_fd = (uint32_t)new_pfd;
        real_close(links[i]);
        long new_link = real_syscall(SYS_bpf, BPF_LINK_CREATE, &c, sizeof(c));
        if (new_link < 0) {
            int cre_err = errno;
            log_line("reload_and_reattach: LINK_UPDATE failed (errno=%d) and "
                     "fallback BPF_LINK_CREATE failed (errno=%d) for old_link_fd=%d",
                     upd_err, cre_err, links[i]);
            APPEND_DETAIL("link_fd=%d: LINK_UPDATE errno=%d, "
                          "LINK_CREATE fallback errno=%d (target_fd=%u attach=%u); ",
                          links[i], upd_err, cre_err,
                          c.link_create.target_fd, c.link_create.attach_type);
            partial = 1;
            continue;
        }
        if (replaced_with) replaced_with[i] = (int)new_link;
        log_line("reload_and_reattach: LINK_UPDATE→CREATE fallback OK "
                 "old_fd=%d → new_fd=%ld (errno=%d on update)",
                 links[i], new_link, upd_err);
    }
    /* Update the prog's attached_link_fds: replace each old fd with the new
     * one returned by the fallback (or leave as-is if UPDATE succeeded). */
    if (replaced_with) {
        pthread_mutex_lock(&state_mutex);
        for (uint32_t i = 0; i < nlinks; i++) {
            if (replaced_with[i] < 0) continue;
            for (uint32_t k = 0; k < p->n_links; k++) {
                if (p->attached_link_fds[k] == links[i]) {
                    p->attached_link_fds[k] = replaced_with[i];
                    break;
                }
            }
        }
        pthread_mutex_unlock(&state_mutex);
        free(replaced_with);
    }
    for (uint32_t i = 0; i < n_prog_attaches; i++) {
        union bpf_attr a;
        memset(&a, 0, sizeof(a));
        a.target_fd = (uint32_t)prog_attaches[i].target_fd;
        a.attach_bpf_fd = (uint32_t)new_pfd;
        a.attach_type = prog_attaches[i].attach_type;
        a.attach_flags = prog_attaches[i].attach_flags | BPF_F_REPLACE;
        a.replace_bpf_fd = (uint32_t)old_prog_fd;
        long r = real_syscall(SYS_bpf, BPF_PROG_ATTACH, &a, sizeof(a));
        if (r >= 0) {
            log_line("reload_and_reattach: PROG_ATTACH replace target_fd=%d "
                     "attach=%u → new_prog_fd=%ld OK",
                     prog_attaches[i].target_fd,
                     prog_attaches[i].attach_type, new_pfd);
            continue;
        }
        int replace_err = errno;
        union bpf_attr d;
        memset(&d, 0, sizeof(d));
        d.target_fd = (uint32_t)prog_attaches[i].target_fd;
        d.attach_bpf_fd = (uint32_t)old_prog_fd;
        d.attach_type = prog_attaches[i].attach_type;
        long dr = real_syscall(SYS_bpf, BPF_PROG_DETACH, &d, sizeof(d));
        int detach_err = errno;
        memset(&a, 0, sizeof(a));
        a.target_fd = (uint32_t)prog_attaches[i].target_fd;
        a.attach_bpf_fd = (uint32_t)new_pfd;
        a.attach_type = prog_attaches[i].attach_type;
        a.attach_flags = prog_attaches[i].attach_flags;
        long ar = dr >= 0 ? real_syscall(SYS_bpf, BPF_PROG_ATTACH, &a,
                                         sizeof(a)) : -1;
        int attach_err = errno;
        if (dr >= 0 && ar >= 0) {
            log_line("reload_and_reattach: PROG_ATTACH detach→attach fallback "
                     "target_fd=%d attach=%u → new_prog_fd=%ld OK "
                     "(replace errno=%d)",
                     prog_attaches[i].target_fd,
                     prog_attaches[i].attach_type, new_pfd, replace_err);
            continue;
        }
        APPEND_DETAIL("prog_attach target_fd=%d attach=%u: replace errno=%d, "
                      "detach errno=%d, attach errno=%d; ",
                      prog_attaches[i].target_fd,
                      prog_attaches[i].attach_type, replace_err,
                      dr < 0 ? detach_err : 0, ar < 0 ? attach_err : 0);
        partial = 1;
    }
    int *perf_replaced = (int *)malloc(nperfs * sizeof(int));
    if (perf_replaced) for (uint32_t i = 0; i < nperfs; i++) perf_replaced[i] = -1;
    for (uint32_t i = 0; i < nperfs; i++) {
        int r = real_ioctl(perfs[i], PERF_EVENT_IOC_SET_BPF,
                           (void *)(intptr_t)new_pfd);
        if (r == 0) continue;
        int set_err = errno;
        /* SET_BPF returns EEXIST when the event already has a BPF prog
         * attached (kernel doesn't support replacement). Fallback: close
         * old event, perf_event_open a fresh one with saved attrs,
         * SET_BPF the new prog. */
        pthread_mutex_lock(&state_mutex);
        struct perf_entry *pe = perf_find(perfs[i]);
        char saved_attr[256];
        uint32_t saved_attr_size = 0;
        int32_t saved_pid = 0, saved_cpu = 0, saved_group = -1;
        uint32_t saved_flags = 0;
        if (pe && pe->attr_size > 0) {
            memcpy(saved_attr, pe->attr_blob, pe->attr_size);
            saved_attr_size = pe->attr_size;
            saved_pid = pe->pid;
            saved_cpu = pe->cpu;
            saved_group = pe->group_fd;
            saved_flags = pe->open_flags;
        }
        pthread_mutex_unlock(&state_mutex);
        if (saved_attr_size == 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF errno=%d, no saved attrs; ",
                          perfs[i], set_err);
            partial = 1;
            continue;
        }
        real_close(perfs[i]);
        long new_perf_fd = real_syscall(SYS_perf_event_open,
                                         (long)(intptr_t)saved_attr,
                                         (long)saved_pid, (long)saved_cpu,
                                         (long)saved_group, (long)saved_flags, 0);
        if (new_perf_fd < 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF errno=%d, "
                          "perf_event_open fallback errno=%d (type=%llu config=%llu); ",
                          perfs[i], set_err, errno,
                          (unsigned long long)((struct perf_event_attr *)saved_attr)->type,
                          (unsigned long long)((struct perf_event_attr *)saved_attr)->config);
            partial = 1;
            continue;
        }
        /* Enable + attach the new prog. */
        (void)real_ioctl((int)new_perf_fd, PERF_EVENT_IOC_ENABLE, NULL);
        int sr = real_ioctl((int)new_perf_fd, PERF_EVENT_IOC_SET_BPF,
                            (void *)(intptr_t)new_pfd);
        if (sr != 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF on new event errno=%d; ",
                          perfs[i], errno);
            real_close((int)new_perf_fd);
            partial = 1;
            continue;
        }
        if (perf_replaced) perf_replaced[i] = (int)new_perf_fd;
        /* The reopen path bypassed the perf_event_open intercept (in_shim=1),
         * so the new fd isn't in perf_table. Re-insert it with the saved
         * attrs so the next reload's SET_BPF fallback finds the entry
         * instead of bailing with "no saved attrs". */
        struct perf_entry *ne = (struct perf_entry *)calloc(1, sizeof(*ne));
        if (ne) {
            ne->fd = (int)new_perf_fd;
            ne->type = ((const struct perf_event_attr *)saved_attr)->type;
            ne->config = ((const struct perf_event_attr *)saved_attr)->config;
            ne->pid = saved_pid;
            ne->cpu = saved_cpu;
            ne->group_fd = saved_group;
            ne->open_flags = saved_flags;
            ne->attached_prog_fd = (int)new_pfd;
            memcpy(ne->attr_blob, saved_attr, saved_attr_size);
            ne->attr_size = saved_attr_size;
            pthread_mutex_lock(&state_mutex);
            perf_insert(ne);
            pthread_mutex_unlock(&state_mutex);
        }
        log_line("reload_and_reattach: perf SET_BPF→reopen fallback OK "
                 "old_fd=%d → new_fd=%ld (errno=%d on initial SET_BPF)",
                 perfs[i], new_perf_fd, set_err);
    }
    /* Update attached_perf_fds to the new fds. */
    if (perf_replaced) {
        pthread_mutex_lock(&state_mutex);
        for (uint32_t i = 0; i < nperfs; i++) {
            if (perf_replaced[i] < 0) continue;
            for (uint32_t k = 0; k < p->n_perfs; k++) {
                if (p->attached_perf_fds[k] == perfs[i]) {
                    p->attached_perf_fds[k] = perf_replaced[i];
                    break;
                }
            }
        }
        pthread_mutex_unlock(&state_mutex);
        free(perf_replaced);
    }
    int *raw_replaced = (int *)malloc(n_raw_tps * sizeof(int));
    if (raw_replaced) for (uint32_t i = 0; i < n_raw_tps; i++) raw_replaced[i] = -1;
    for (uint32_t i = 0; i < n_raw_tps; i++) {
        char raw_name[128] = {0};
        pthread_mutex_lock(&state_mutex);
        struct raw_tp_entry *rt = raw_tp_find(raw_tps[i]);
        if (rt) snprintf(raw_name, sizeof(raw_name), "%s", rt->name);
        pthread_mutex_unlock(&state_mutex);
        if (!raw_name[0]) {
            APPEND_DETAIL("raw_tp_fd=%d: no saved name; ", raw_tps[i]);
            partial = 1;
            continue;
        }
        union bpf_attr rta;
        memset(&rta, 0, sizeof(rta));
        rta.raw_tracepoint.name = (uintptr_t)raw_name;
        rta.raw_tracepoint.prog_fd = (uint32_t)new_pfd;
        real_close(raw_tps[i]);
        long new_raw = real_syscall(SYS_bpf, BPF_RAW_TRACEPOINT_OPEN,
                                    &rta, sizeof(rta));
        if (new_raw < 0) {
            APPEND_DETAIL("raw_tp_fd=%d name=%s: reopen errno=%d; ",
                          raw_tps[i], raw_name, errno);
            partial = 1;
            continue;
        }
        if (raw_replaced) raw_replaced[i] = (int)new_raw;
        struct raw_tp_entry *ne = (struct raw_tp_entry *)calloc(1, sizeof(*ne));
        if (ne) {
            ne->fd = (int)new_raw;
            ne->prog_fd = (uint32_t)new_pfd;
            snprintf(ne->name, sizeof(ne->name), "%s", raw_name);
            pthread_mutex_lock(&state_mutex);
            raw_tp_remove(raw_tps[i]);
            raw_tp_insert(ne);
            pthread_mutex_unlock(&state_mutex);
        }
        log_line("reload_and_reattach: RAW_TRACEPOINT_OPEN name=%s "
                 "old_fd=%d → new_fd=%ld OK", raw_name, raw_tps[i], new_raw);
    }
    if (raw_replaced) {
        pthread_mutex_lock(&state_mutex);
        for (uint32_t i = 0; i < n_raw_tps; i++) {
            if (raw_replaced[i] < 0) continue;
            for (uint32_t k = 0; k < p->n_raw_tps; k++) {
                if (p->attached_raw_tp_fds[k] == raw_tps[i]) {
                    p->attached_raw_tp_fds[k] = raw_replaced[i];
                    break;
                }
            }
        }
        pthread_mutex_unlock(&state_mutex);
        free(raw_replaced);
    }
    /* XDP netlink reattach. The app (katran, iproute2, libbpf<0.8) bound
     * the original prog via RTM_SETLINK + IFLA_XDP_FD; that path is
     * invisible to LINK_UPDATE / SET_BPF, so without explicit replay the
     * netdev keeps dispatching to the original prog and the workload
     * sees no bytecode change. We send a fresh RTM_SETLINK against every
     * captured (ifindex, flags) pair using the new_pfd. */
    pthread_mutex_lock(&state_mutex);
    uint32_t n_xdp = p->n_xdp;
    struct xdp_nl_attach *xdp_snap = NULL;
    if (n_xdp) {
        xdp_snap = (struct xdp_nl_attach *)malloc(n_xdp * sizeof(*xdp_snap));
        if (xdp_snap)
            memcpy(xdp_snap, p->xdp_attaches, n_xdp * sizeof(*xdp_snap));
        else
            n_xdp = 0;
    }
    pthread_mutex_unlock(&state_mutex);
    /* Discovery fallback: if no in-process netlink attach was observed but
     * the prog is an XDP type, the attach was performed by an out-of-process
     * runner (katran's `bpftool net attach xdp ... dev <iface>`). Walk all
     * netdevs and ask the kernel which prog_id is bound; any match against
     * our kid means we own that attach and must replay. */
    if (n_xdp == 0 && p->prog_type == BPF_PROG_TYPE_XDP &&
        p->kernel_prog_id != 0) {
        DIR *nd = opendir("/sys/class/net");
        if (nd) {
            struct xdp_nl_attach *discovered = NULL;
            uint32_t n_discovered = 0;
            struct dirent *de;
            while ((de = readdir(nd)) != NULL) {
                if (de->d_name[0] == '.') continue;
                char ifindex_path[256];
                snprintf(ifindex_path, sizeof(ifindex_path),
                         "/sys/class/net/%s/ifindex", de->d_name);
                FILE *fi = fopen(ifindex_path, "r");
                if (!fi) continue;
                unsigned ifindex = 0;
                if (fscanf(fi, "%u", &ifindex) != 1) {
                    fclose(fi);
                    continue;
                }
                fclose(fi);
                /* Query the kernel for the XDP-bound prog id on this iface
                 * via RTM_GETLINK + IFLA_XDP. We could parse /proc but the
                 * netlink path is cleaner and the response includes the
                 * exact flags (skb/native/hw) the original attach used. */
                int s = socket(AF_NETLINK, SOCK_RAW | SOCK_CLOEXEC, NETLINK_ROUTE);
                if (s < 0) continue;
                struct {
                    struct nlmsghdr nh;
                    struct ifinfomsg ifi;
                } q;
                memset(&q, 0, sizeof(q));
                q.nh.nlmsg_type = RTM_GETLINK;
                q.nh.nlmsg_flags = NLM_F_REQUEST;
                q.nh.nlmsg_seq = 1 + ifindex;
                q.nh.nlmsg_len = sizeof(q);
                q.ifi.ifi_family = AF_UNSPEC;
                q.ifi.ifi_index = (int)ifindex;
                struct sockaddr_nl sa;
                memset(&sa, 0, sizeof(sa));
                sa.nl_family = AF_NETLINK;
                if (sendto(s, &q, q.nh.nlmsg_len, 0,
                           (struct sockaddr *)&sa, sizeof(sa)) < 0) {
                    real_close(s);
                    continue;
                }
                char resp[16384];
                ssize_t rn = recv(s, resp, sizeof(resp), 0);
                real_close(s);
                if (rn < (ssize_t)NLMSG_HDRLEN) continue;
                /* Walk response: find IFLA_XDP -> IFLA_XDP_PROG_ID and
                 * IFLA_XDP_ATTACHED. */
                const struct nlmsghdr *nh = (const struct nlmsghdr *)resp;
                size_t left = (size_t)rn;
                while (NLMSG_OK(nh, left)) {
                    if (nh->nlmsg_type != RTM_NEWLINK) {
                        nh = NLMSG_NEXT(nh, left);
                        continue;
                    }
                    const struct ifinfomsg *ifi =
                        (const struct ifinfomsg *)NLMSG_DATA(nh);
                    size_t alen = nh->nlmsg_len - NLMSG_LENGTH(sizeof(*ifi));
                    const struct rtattr *rta =
                        (const struct rtattr *)IFLA_RTA(ifi);
                    while (RTA_OK(rta, alen)) {
                        if (rta->rta_type == IFLA_XDP) {
                            size_t nl = RTA_PAYLOAD(rta);
                            const struct rtattr *xa =
                                (const struct rtattr *)RTA_DATA(rta);
                            uint32_t attached_pid = 0;
                            uint8_t mode = 0;
                            while (RTA_OK(xa, nl)) {
                                if (xa->rta_type == IFLA_XDP_PROG_ID &&
                                    RTA_PAYLOAD(xa) >= 4) {
                                    memcpy(&attached_pid, RTA_DATA(xa), 4);
                                } else if (xa->rta_type == IFLA_XDP_ATTACHED &&
                                           RTA_PAYLOAD(xa) >= 1) {
                                    memcpy(&mode, RTA_DATA(xa), 1);
                                }
                                xa = RTA_NEXT(xa, nl);
                            }
                            if (attached_pid == p->kernel_prog_id) {
                                /* Reconstruct xdp_flags from
                                 * enum xdp_attached_mode:
                                 * 1=DRV(native), 2=SKB(generic), 3=HW. */
                                uint32_t mode_flag = 0;
                                if (mode == XDP_ATTACHED_DRV)
                                    mode_flag = XDP_FLAGS_DRV_MODE;
                                else if (mode == XDP_ATTACHED_SKB)
                                    mode_flag = XDP_FLAGS_SKB_MODE;
                                else if (mode == XDP_ATTACHED_HW)
                                    mode_flag = XDP_FLAGS_HW_MODE;
                                struct xdp_nl_attach *grown =
                                    (struct xdp_nl_attach *)realloc(
                                        discovered,
                                        (n_discovered + 1) *
                                            sizeof(*discovered));
                                if (grown) {
                                    discovered = grown;
                                    discovered[n_discovered].ifindex = ifindex;
                                    discovered[n_discovered].xdp_flags =
                                        mode_flag;
                                    n_discovered++;
                                    log_line("XDP discovery: kid=%u found on "
                                             "ifindex=%u ifname=%s mode=%u "
                                             "(flags=0x%x)",
                                             attached_pid, ifindex,
                                             de->d_name, mode, mode_flag);
                                }
                            }
                            break;
                        }
                        rta = RTA_NEXT(rta, alen);
                    }
                    nh = NLMSG_NEXT(nh, left);
                }
            }
            closedir(nd);
            if (n_discovered > 0) {
                n_xdp = n_discovered;
                xdp_snap = discovered;
            }
        }
    }
    /* Guard so the shim's own sendto/recv inside the replay don't get
     * intercepted by the shim's own sendto/sendmsg wrappers — that would
     * either log spurious "no known prog_entry" entries or deadlock. */
    in_shim = 1;
    /* The kernel rejects a plain re-attach over an existing XDP prog with
     * EEXIST unless we either set XDP_FLAGS_UPDATE_IF_NOEXIST (a first-time
     * attach, wrong here) or perform an atomic REPLACE with
     * IFLA_XDP_EXPECTED_FD pointing at the currently-attached prog. The
     * loader's original fd is gone, but at this point p->kernel_prog_id is
     * still the OLD prog id (it is bumped to the new id only after this
     * block), so open a fresh fd to it for the EXPECTED_FD check. */
    int old_xdp_fd = -1;
    if (n_xdp > 0 && p->kernel_prog_id != 0) {
        union bpf_attr ga = {0};
        ga.prog_id = p->kernel_prog_id;
        long ofd = real_syscall(SYS_bpf, BPF_PROG_GET_FD_BY_ID, &ga,
                                sizeof(ga));
        if (ofd >= 0) old_xdp_fd = (int)ofd;
    }
    for (uint32_t i = 0; i < n_xdp; i++) {
        int r = nl_send_setlink_xdp_replace(xdp_snap[i].ifindex,
                                            (int)new_pfd, old_xdp_fd,
                                            xdp_snap[i].xdp_flags);
        if (r < 0) {
            APPEND_DETAIL("xdp ifindex=%u: nl_send_setlink_xdp_replace "
                          "failed (errno=%d); ",
                          xdp_snap[i].ifindex, errno);
            partial = 1;
            log_line("reload_and_reattach: XDP netlink reattach ifindex=%u "
                     "FAILED errno=%d (new_pfd=%ld flags=0x%x)",
                     xdp_snap[i].ifindex, errno, new_pfd,
                     xdp_snap[i].xdp_flags);
        } else {
            log_line("reload_and_reattach: XDP netlink reattach ifindex=%u "
                     "flags=0x%x → new_prog_fd=%ld OK",
                     xdp_snap[i].ifindex, xdp_snap[i].xdp_flags, new_pfd);
        }
    }
    if (old_xdp_fd >= 0) real_close(old_xdp_fd);
    in_shim = 0;
    free(xdp_snap);
#undef APPEND_DETAIL
    free(links);
    free(perfs);
    free(prog_attaches);
    free(raw_tps);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    if (out_rejit_ms) *out_rejit_ms = (t1.tv_sec - t0.tv_sec) * 1000ULL
                                      + (t1.tv_nsec - t0.tv_nsec) / 1000000;

    /* Resolve the new kernel id and commit the swap into prog_entry. The
     * old fd is closed so the kernel can release the old prog when no
     * link/perf_event still references it (after BPF_LINK_UPDATE, no link
     * should). */
    uint32_t new_kid = resolve_kernel_id((int)new_pfd);
    pthread_mutex_lock(&state_mutex);
    /* Reload p in case state was swapped under us (shouldn't happen during a
     * single execute_plan, but cheap to defensively re-lookup). */
    p->fd = (int)new_pfd;
    if (new_kid) p->kernel_prog_id = new_kid;
    pthread_mutex_unlock(&state_mutex);
    if (old_prog_fd >= 0 && old_prog_fd != (int)new_pfd)
        real_close(old_prog_fd);

    free(owned_log);
    return partial ? RELOAD_PARTIAL_ATTACH : RELOAD_OK;
}

#endif /* BPFREJIT_SHIM_RELOAD_H */
