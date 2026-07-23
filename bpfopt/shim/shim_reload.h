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

/* Recreated links must retain the descriptor number owned by the application.
 * Many stock-kernel link types implement neither BPF_LINK_UPDATE nor
 * BPF_LINK_DETACH, so closing the old link is their only detach operation.
 * dup3 then installs the replacement at the same number so libbpf/Go cleanup
 * paths keep referring to the live link. */
static int preserve_recreated_link_fd(long *link_fd, int desired_fd,
                                      int descriptor_flags) {
    if (!link_fd || *link_fd < 0 || desired_fd < 0) {
        errno = EINVAL;
        return -1;
    }
    if (*link_fd == desired_fd) {
        if (real_syscall(SYS_fcntl, desired_fd, F_SETFD,
                         descriptor_flags & FD_CLOEXEC) < 0)
            return -1;
        return 0;
    }
    int dup_flags = (descriptor_flags & FD_CLOEXEC) ? O_CLOEXEC : 0;
    if (real_syscall(SYS_dup3, (int)*link_fd, desired_fd, dup_flags) < 0)
        return -1;
    real_close((int)*link_fd);
    *link_fd = desired_fd;
    return 0;
}

/* context_specialize emits this impossible fd-array index as a private
 * contract with the live-swap shim.  The shim replaces it with a fresh
 * one-entry PROG_ARRAY containing the retained original program.  Guard
 * misses can therefore tail-call the verifier-approved generic program
 * without putting both the generic and specialized CFGs in one verifier
 * state space. */
#ifndef CONTEXT_FALLBACK_MAP_MARKER
#define CONTEXT_FALLBACK_MAP_MARKER 0x7ffffffeU
#endif

static int prepare_context_fallback_map(struct prog_entry *p,
                                        struct bpf_insn *insns,
                                        uint32_t insn_cnt,
                                        int **fd_array_ptr,
                                        uint32_t *fd_array_n_ptr) {
    uint32_t marker_count = 0;
    for (uint32_t i = 0; i < insn_cnt; i++) {
        struct bpf_insn *insn = &insns[i];
        if (insn->code != (BPF_LD | BPF_DW | BPF_IMM) ||
            insn->src_reg != BPF_PSEUDO_MAP_IDX ||
            (uint32_t)insn->imm != CONTEXT_FALLBACK_MAP_MARKER)
            continue;
        if (i + 1 >= insn_cnt || insns[i + 1].code != 0 ||
            insns[i + 1].dst_reg != 0 || insns[i + 1].src_reg != 0 ||
            insns[i + 1].off != 0 || insns[i + 1].imm != 0) {
            log_line("context fallback marker has malformed LD_IMM64 tail "
                     "at pc=%u", i);
            return -1;
        }
        marker_count++;
        i++;
    }
    if (marker_count == 0)
        return 0;
    if (p->profile_hold_fd < 0) {
        log_line("context fallback marker requires retained original prog "
                 "fd for kid=%u", p->kernel_prog_id);
        return -1;
    }

    uint32_t old_n = *fd_array_n_ptr;
    if (old_n == UINT32_MAX) {
        log_line("context fallback fd_array index overflow for kid=%u",
                 p->kernel_prog_id);
        return -1;
    }
    int *expanded = (int *)realloc(*fd_array_ptr,
                                   (size_t)(old_n + 1) * sizeof(int));
    if (!expanded) {
        log_line("context fallback fd_array allocation failed for kid=%u",
                 p->kernel_prog_id);
        return -1;
    }
    *fd_array_ptr = expanded;

    union bpf_attr create = {0};
    create.map_type = BPF_MAP_TYPE_PROG_ARRAY;
    create.key_size = sizeof(uint32_t);
    create.value_size = sizeof(uint32_t);
    create.max_entries = 1;
    long map_fd = real_syscall(SYS_bpf, BPF_MAP_CREATE, &create,
                               sizeof(create));
    if (map_fd < 0) {
        int saved_errno = errno;
        log_line("context fallback BPF_MAP_CREATE failed for kid=%u: "
                 "errno=%d", p->kernel_prog_id, saved_errno);
        return -1;
    }

    uint32_t key = 0;
    uint32_t prog_fd = (uint32_t)p->profile_hold_fd;
    union bpf_attr update = {0};
    update.map_fd = (uint32_t)map_fd;
    update.key = (uintptr_t)&key;
    update.value = (uintptr_t)&prog_fd;
    update.flags = BPF_ANY;
    if (real_syscall(SYS_bpf, BPF_MAP_UPDATE_ELEM, &update,
                     sizeof(update)) < 0) {
        int saved_errno = errno;
        log_line("context fallback BPF_MAP_UPDATE_ELEM failed for kid=%u "
                 "held_fd=%d: errno=%d", p->kernel_prog_id,
                 p->profile_hold_fd, saved_errno);
        real_close((int)map_fd);
        return -1;
    }

    expanded[old_n] = (int)map_fd;
    *fd_array_n_ptr = old_n + 1;
    for (uint32_t i = 0; i < insn_cnt; i++) {
        struct bpf_insn *insn = &insns[i];
        if (insn->code == (BPF_LD | BPF_DW | BPF_IMM) &&
            insn->src_reg == BPF_PSEUDO_MAP_IDX &&
            (uint32_t)insn->imm == CONTEXT_FALLBACK_MAP_MARKER) {
            insn->imm = (int32_t)old_n;
            i++;
        }
    }
    log_line("context fallback map prepared kid=%u held_fd=%d "
             "fd_array_index=%u markers=%u", p->kernel_prog_id,
             p->profile_hold_fd, old_n, marker_count);
    return 0;
}

struct declared_perf_fd {
    int fd;
    uint64_t event_id;
};

static int declared_perf_fd_cmp(const void *lhs, const void *rhs) {
    const struct declared_perf_fd *a =
        (const struct declared_perf_fd *)lhs;
    const struct declared_perf_fd *b =
        (const struct declared_perf_fd *)rhs;
    if (a->event_id < b->event_id) return -1;
    if (a->event_id > b->event_id) return 1;
    return 0;
}

static int read_online_cpu_ids(int **cpu_ids_out, uint32_t *cpu_count_out) {
    *cpu_ids_out = NULL;
    *cpu_count_out = 0;
    FILE *fp = fopen("/sys/devices/system/cpu/online", "r");
    if (!fp) {
        log_line("declared perf discovery: cannot open online CPU list: "
                 "errno=%d", errno);
        return -1;
    }
    char buf[4096];
    if (!fgets(buf, sizeof(buf), fp)) {
        int saved_errno = errno;
        fclose(fp);
        log_line("declared perf discovery: cannot read online CPU list: "
                 "errno=%d", saved_errno);
        return -1;
    }
    fclose(fp);

    int *ids = NULL;
    uint32_t count = 0, capacity = 0;
    const char *cursor = buf;
    while (*cursor != '\0' && *cursor != '\n') {
        errno = 0;
        char *end = NULL;
        long first = strtol(cursor, &end, 10);
        if (errno != 0 || end == cursor || first < 0 || first > INT_MAX) {
            free(ids);
            log_line("declared perf discovery: malformed online CPU list: %s",
                     buf);
            return -1;
        }
        long last = first;
        cursor = end;
        if (*cursor == '-') {
            cursor++;
            errno = 0;
            last = strtol(cursor, &end, 10);
            if (errno != 0 || end == cursor || last < first ||
                last > INT_MAX) {
                free(ids);
                log_line("declared perf discovery: malformed online CPU "
                         "range: %s", buf);
                return -1;
            }
            cursor = end;
        }
        for (long cpu = first; cpu <= last; cpu++) {
            if (count == capacity) {
                uint32_t new_capacity = capacity == 0 ? 16 : capacity * 2;
                if (new_capacity < capacity) {
                    free(ids);
                    return -1;
                }
                int *expanded =
                    (int *)realloc(ids, (size_t)new_capacity * sizeof(*ids));
                if (!expanded) {
                    free(ids);
                    return -1;
                }
                ids = expanded;
                capacity = new_capacity;
            }
            ids[count++] = (int)cpu;
        }
        if (*cursor == ',') {
            cursor++;
            continue;
        }
        if (*cursor != '\0' && *cursor != '\n') {
            free(ids);
            log_line("declared perf discovery: malformed online CPU "
                     "separator: %s", buf);
            return -1;
        }
    }
    if (count == 0) {
        free(ids);
        log_line("declared perf discovery: online CPU list is empty");
        return -1;
    }
    *cpu_ids_out = ids;
    *cpu_count_out = count;
    return 0;
}

static int declared_perf_fd_is_reserved(int fd, uint64_t event_id) {
    int reserved = 0;
    pthread_mutex_lock(&state_mutex);
    if (perf_find(fd)) {
        reserved = 1;
        log_line("declared perf scan: fd=%d event_id=%llu reserved=perf_table",
                 fd, (unsigned long long)event_id);
    } else {
        for (int bucket = 0; bucket < BPF_STATE_BUCKETS && !reserved;
             bucket++) {
            for (struct link_entry *link = link_table[bucket]; link;
                 link = link->next) {
                if (link->attach_type != BPF_PERF_EVENT) continue;
                int targets[2] = {
                    (int)link->target_fd,
                    link->target_hold_fd,
                };
                for (uint32_t i = 0; i < 2; i++) {
                    if (targets[i] < 0) continue;
                    if (targets[i] == fd) {
                        reserved = 1;
                        log_line("declared perf scan: fd=%d event_id=%llu "
                                 "reserved=link_target_fd", fd,
                                 (unsigned long long)event_id);
                        break;
                    }
                    uint64_t target_event_id = 0;
                    if (real_ioctl(targets[i], PERF_EVENT_IOC_ID,
                                   &target_event_id) == 0 &&
                        target_event_id == event_id) {
                        reserved = 1;
                        log_line("declared perf scan: fd=%d event_id=%llu "
                                 "reserved=link_target_event_id target_fd=%d",
                                 fd, (unsigned long long)event_id, targets[i]);
                        break;
                    }
                }
                if (reserved) break;
            }
        }
    }
    pthread_mutex_unlock(&state_mutex);
    return reserved;
}

/* Go issues perf_event_open and PERF_EVENT_IOC_SET_BPF through raw assembly
 * syscalls, which cannot cross an LD_PRELOAD boundary. Apps with that ABI
 * provide an explicit program:frequency contract. OTEL creates one CPU-clock
 * event per online CPU in a single ascending-CPU loop before it creates its
 * scheduler and perf-output events. We therefore require the earliest N
 * unreserved kernel event IDs to form one consecutive creation block, where
 * N is the online-CPU count. Later application perf events are outside that
 * declared block. Missing, interleaved, or aliased state is an error; no
 * guessed attachment is accepted. */
static int discover_declared_cpu_clock_perfs(struct prog_entry *p) {
    const char *spec = getenv("BPFREJIT_SHIM_PERF_CPU_CLOCK_SPEC");
    if (!spec || !spec[0]) return 0;

    char prog_name[BPF_OBJ_NAME_LEN] = {0};
    unsigned long long frequency = 0;
    int consumed = 0;
    if (sscanf(spec, "%15[^:]:%llu%n", prog_name, &frequency,
               &consumed) != 2 || spec[consumed] != '\0' || frequency == 0) {
        log_line("declared perf discovery: invalid CPU-clock spec: %s", spec);
        return -1;
    }
    if (strcmp(p->name, prog_name) != 0) return 0;

    pthread_mutex_lock(&state_mutex);
    uint32_t already_captured = p->n_perfs;
    pthread_mutex_unlock(&state_mutex);
    if (already_captured > 0) {
        log_line("declared perf discovery: prog=%s already has %u captured "
                 "perf events", p->name, already_captured);
        return 0;
    }

    int *cpu_ids = NULL;
    uint32_t cpu_count = 0;
    if (read_online_cpu_ids(&cpu_ids, &cpu_count) != 0) return -1;

    struct declared_perf_fd *events = NULL;
    uint32_t event_count = 0, event_capacity = 0;
    DIR *fd_dir = opendir("/proc/self/fd");
    if (!fd_dir) {
        int saved_errno = errno;
        free(events);
        free(cpu_ids);
        log_line("declared perf discovery: cannot scan /proc/self/fd: "
                 "errno=%d", saved_errno);
        return -1;
    }

    struct dirent *de;
    while ((de = readdir(fd_dir)) != NULL) {
        if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
        int fd = atoi(de->d_name);
        if (fd < 0) continue;
        char fdpath[64], target[64];
        snprintf(fdpath, sizeof(fdpath), "/proc/self/fd/%d", fd);
        ssize_t len = readlink(fdpath, target, sizeof(target) - 1);
        if (len <= 0) continue;
        target[len] = '\0';
        if (strcmp(target, "anon_inode:[perf_event]") != 0) continue;
        uint64_t event_id = 0;
        if (real_ioctl(fd, PERF_EVENT_IOC_ID, &event_id) != 0 ||
            event_id == 0) {
            int saved_errno = errno;
            closedir(fd_dir);
            free(events);
            free(cpu_ids);
            log_line("declared perf discovery: PERF_EVENT_IOC_ID fd=%d "
                     "failed: errno=%d", fd, saved_errno);
            return -1;
        }
        /* Perf events already captured by libc interception, plus retained
         * BPF_PERF_EVENT link targets, have independent attachment records.
         * The declaration covers only raw-syscall events absent from those
         * tables. */
        if (declared_perf_fd_is_reserved(fd, event_id)) continue;
        if (event_count == event_capacity) {
            uint32_t new_capacity =
                event_capacity == 0 ? 32 : event_capacity * 2;
            if (new_capacity < event_capacity) {
                closedir(fd_dir);
                free(events);
                free(cpu_ids);
                log_line("declared perf discovery: event capacity overflow "
                         "for prog=%s", p->name);
                return -1;
            }
            struct declared_perf_fd *expanded =
                (struct declared_perf_fd *)realloc(
                    events, (size_t)new_capacity * sizeof(*events));
            if (!expanded) {
                closedir(fd_dir);
                free(events);
                free(cpu_ids);
                return -1;
            }
            events = expanded;
            event_capacity = new_capacity;
        }
        events[event_count].fd = fd;
        events[event_count].event_id = event_id;
        event_count++;
    }
    closedir(fd_dir);
    if (event_count < cpu_count) {
        log_line("declared perf discovery: prog=%s expected at least %u "
                 "CPU-clock events, found %u", p->name, cpu_count,
                 event_count);
        free(events);
        free(cpu_ids);
        return -1;
    }
    qsort(events, event_count, sizeof(*events), declared_perf_fd_cmp);

    for (uint32_t i = 1; i < cpu_count; i++) {
        if (events[i - 1].event_id == UINT64_MAX ||
            events[i].event_id != events[i - 1].event_id + 1) {
            log_line("declared perf discovery: prog=%s CPU-clock creation "
                     "block is not consecutive at index=%u prev_id=%llu "
                     "event_id=%llu", p->name, i,
                     (unsigned long long)events[i - 1].event_id,
                     (unsigned long long)events[i].event_id);
            free(events);
            free(cpu_ids);
            return -1;
        }
    }
    if (event_count > cpu_count &&
        events[cpu_count].event_id <= events[cpu_count - 1].event_id) {
        log_line("declared perf discovery: prog=%s event alias overlaps "
                 "CPU-clock creation block at event_id=%llu", p->name,
                 (unsigned long long)events[cpu_count].event_id);
        free(events);
        free(cpu_ids);
        return -1;
    }
    if (event_count > cpu_count) {
        log_line("declared perf discovery: prog=%s excluded %u later perf "
                 "events after CPU-clock block", p->name,
                 event_count - cpu_count);
    }

    uint32_t selected_count = cpu_count;

    struct perf_entry **entries =
        (struct perf_entry **)calloc(selected_count, sizeof(*entries));
    int *perf_fds = (int *)calloc(selected_count, sizeof(*perf_fds));
    if (!entries || !perf_fds) {
        free(entries);
        free(perf_fds);
        free(events);
        free(cpu_ids);
        return -1;
    }
    for (uint32_t i = 0; i < selected_count; i++) {
        struct perf_event_attr attr;
        memset(&attr, 0, sizeof(attr));
        attr.type = PERF_TYPE_SOFTWARE;
        attr.size = sizeof(attr);
        attr.config = PERF_COUNT_SW_CPU_CLOCK;
        attr.sample_freq = (uint64_t)frequency;
        attr.freq = 1;

        struct perf_entry *entry =
            (struct perf_entry *)calloc(1, sizeof(*entry));
        if (!entry) {
            for (uint32_t k = 0; k < i; k++) free(entries[k]);
            free(entries);
            free(perf_fds);
            free(events);
            free(cpu_ids);
            return -1;
        }
        entry->fd = events[i].fd;
        entry->type = attr.type;
        entry->config = attr.config;
        entry->pid = -1;
        entry->cpu = cpu_ids[i];
        entry->group_fd = -1;
        entry->open_flags = PERF_FLAG_FD_CLOEXEC;
        entry->attached_prog_fd = p->fd;
        memcpy(entry->attr_blob, &attr, sizeof(attr));
        entry->attr_size = sizeof(attr);
        entries[i] = entry;
        perf_fds[i] = events[i].fd;
    }

    pthread_mutex_lock(&state_mutex);
    if (p->n_perfs != 0) {
        pthread_mutex_unlock(&state_mutex);
        for (uint32_t i = 0; i < selected_count; i++) free(entries[i]);
        free(entries);
        free(perf_fds);
        free(events);
        free(cpu_ids);
        log_line("declared perf discovery: attachment state changed during "
                 "scan for prog=%s", p->name);
        return -1;
    }
    for (uint32_t i = 0; i < selected_count; i++) perf_insert(entries[i]);
    p->attached_perf_fds = perf_fds;
    p->n_perfs = selected_count;
    pthread_mutex_unlock(&state_mutex);

    log_line("declared perf discovery: prog=%s frequency=%llu events=%u "
             "event_id_first=%llu event_id_last=%llu cpu_first=%d "
             "cpu_last=%d", p->name, frequency, selected_count,
             (unsigned long long)events[0].event_id,
             (unsigned long long)events[selected_count - 1].event_id,
             cpu_ids[0], cpu_ids[selected_count - 1]);
    free(entries);
    free(events);
    free(cpu_ids);
    return 0;
}

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

    if (discover_declared_cpu_clock_perfs(p) != 0)
        return RELOAD_INTERNAL;

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
    if (build_full_fd_array(target_json_path, map_fds, nr_fds,
                            &fd_array, &fd_array_n) != 0) {
        free(insns);
        return RELOAD_INTERNAL;
    }
    if (prepare_context_fallback_map(
            p, insns, (uint32_t)(bytes / sizeof(struct bpf_insn)),
            &fd_array, &fd_array_n) != 0) {
        free_full_fd_array(fd_array, fd_array_n);
        free(insns);
        return RELOAD_INTERNAL;
    }

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
                for (uint32_t i = 0; i < fd_array_n; i++)
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
     * it. Kernel falls back to system-wide capability checks. Hard-code
     * the UAPI value (1U << 16) so this still builds against system headers
     * that predate BPF token support. */
    a.prog_flags &= ~((uint32_t)(1U << 16));
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

    uint32_t new_kid = resolve_kernel_id((int)new_pfd);
    if (!new_kid) {
        real_close((int)new_pfd);
        free(owned_log);
        return RELOAD_INTERNAL;
    }

    /* Swap attaches. BPF_LINK_UPDATE is atomic per-link. */
    int partial = 0;
    pthread_mutex_lock(&state_mutex);
    /* Snapshot lists locally — reattach syscalls release state_mutex
     * via real_syscall (kernel side, not shim re-entry, but be safe). */
    uint32_t nlinks = p->n_links, nperfs = p->n_perfs;
    uint32_t n_prog_attaches = p->n_prog_attaches, n_raw_tps = p->n_raw_tps;
    uint32_t old_kid = p->kernel_prog_id;
    uint32_t n_prog_array_slots = 0;
    struct prog_array_slot_ref *prog_array_refs = NULL;
    int prog_array_snapshot_rc = prog_array_slots_for_target(
        old_kid, &prog_array_refs, &n_prog_array_slots);
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
    int old_prog_hold_fd = p->profile_hold_fd;
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
    if (prog_array_snapshot_rc != 0) {
        APPEND_DETAIL("prog_array attachment snapshot allocation failed; ");
        partial = 1;
    }
    /* Program-array slots are attachment points for tail-call targets. Update
     * every observed slot to the freshly verified program fd. A failed slot
     * update is an explicit partial replacement, never a successful live
     * swap. */
    in_shim = 1;
    for (uint32_t i = 0; i < n_prog_array_slots; i++) {
        union bpf_attr get = {0};
        get.map_id = prog_array_refs[i].map_id;
        long map_fd = real_syscall(SYS_bpf, BPF_MAP_GET_FD_BY_ID, &get,
                                   sizeof(get));
        if (map_fd < 0) {
            APPEND_DETAIL("prog_array map_id=%u key=%u: get_fd errno=%d; ",
                          prog_array_refs[i].map_id, prog_array_refs[i].key,
                          errno);
            partial = 1;
            continue;
        }
        uint32_t key = prog_array_refs[i].key;
        uint32_t value = (uint32_t)new_pfd;
        union bpf_attr update = {0};
        update.map_fd = (uint32_t)map_fd;
        update.key = (uintptr_t)&key;
        update.value = (uintptr_t)&value;
        update.flags = BPF_ANY;
        long update_rc = real_syscall(SYS_bpf, BPF_MAP_UPDATE_ELEM, &update,
                                      sizeof(update));
        int update_errno = errno;
        real_close((int)map_fd);
        if (update_rc < 0) {
            APPEND_DETAIL("prog_array map_id=%u key=%u: update errno=%d; ",
                          prog_array_refs[i].map_id, key, update_errno);
            partial = 1;
            continue;
        }
        pthread_mutex_lock(&state_mutex);
        prog_array_slot_retarget(prog_array_refs[i].map_id, key, old_kid,
                                 new_kid);
        pthread_mutex_unlock(&state_mutex);
        log_line("reload_and_reattach: prog_array map_id=%u key=%u -> "
                 "new_prog_id=%u OK",
                 prog_array_refs[i].map_id, key, new_kid);
    }
    in_shim = 0;
    free(prog_array_refs);

    /* Track new fds replacing old ones so the prog's attached_link_fds list
     * stays consistent after fallback-recreate. */
    int *replaced_with = (int *)malloc(nlinks * sizeof(int));
    if (replaced_with) for (uint32_t i = 0; i < nlinks; i++) replaced_with[i] = -1;
    for (uint32_t i = 0; i < nlinks; i++) {
        union bpf_attr u;
        memset(&u, 0, sizeof(u));
        u.link_update.new_prog_fd = (uint32_t)new_pfd;
        u.link_update.flags = 0;
        long r = -1;
        int upd_err = 0;
        /* Most BPF link types don't implement update_prog.  When UPDATE is
         * unsupported, close every fd referencing the old link before CREATE:
         * many link types (including raw tracepoint, tracing, and perf-event)
         * also implement no BPF_LINK_DETACH operation.  Recreate or roll back
         * the old program at the application-owned descriptor number. */
        pthread_mutex_lock(&state_mutex);
        struct link_entry *le = link_find(links[i]);
        char saved_blob[80];
        char saved_perf_attr[256] = {0};
        char saved_probe_target[128] = {0};
        uint32_t saved_perf_attr_size = 0;
        int32_t saved_perf_pid = 0, saved_perf_cpu = 0;
        int32_t saved_perf_group_fd = -1;
        uint32_t saved_perf_open_flags = 0;
        int saved_target_hold_fd = -1;
        uint32_t saved_create_attr_size = 0;
        uint32_t saved_link_id = 0;
        int have_blob = 0;
        if (le) {
            memcpy(saved_blob, le->create_attr_blob, sizeof(saved_blob));
            saved_create_attr_size = le->create_attr_size;
            if (le->target_perf_attr_size > 0 &&
                le->target_perf_attr_size <= sizeof(saved_perf_attr)) {
                saved_perf_attr_size = le->target_perf_attr_size;
                memcpy(saved_perf_attr, le->target_perf_attr_blob,
                       saved_perf_attr_size);
                saved_perf_pid = le->target_perf_pid;
                saved_perf_cpu = le->target_perf_cpu;
                saved_perf_group_fd = le->target_perf_group_fd;
                saved_perf_open_flags = le->target_perf_open_flags;
                snprintf(saved_probe_target, sizeof(saved_probe_target),
                         "%s", le->target_perf_probe_target);
            }
            if (le->target_hold_fd >= 0) {
                long duplicate = real_syscall(
                    SYS_fcntl, le->target_hold_fd, F_DUPFD_CLOEXEC, 3);
                if (duplicate >= 0)
                    saved_target_hold_fd = (int)duplicate;
            }
            saved_link_id = le->kernel_link_id;
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
        union bpf_attr get_link = {0};
        get_link.link_id = saved_link_id;
        long live_link_fd = real_syscall(SYS_bpf, BPF_LINK_GET_FD_BY_ID,
                                         &get_link, sizeof(get_link));
        if (live_link_fd < 0) {
            int link_get_err = errno;
            if (saved_target_hold_fd >= 0)
                real_close(saved_target_hold_fd);
            APPEND_DETAIL("link_fd=%d link_id=%u: get_fd errno=%d; ",
                          links[i], saved_link_id, link_get_err);
            partial = 1;
            continue;
        }
        u.link_update.link_fd = (uint32_t)live_link_fd;
        r = real_syscall(SYS_bpf, BPF_LINK_UPDATE, &u, sizeof(u));
        if (r >= 0) {
            if (saved_target_hold_fd >= 0)
                real_close(saved_target_hold_fd);
            real_close((int)live_link_fd);
            continue;
        }
        upd_err = errno;
        union bpf_attr c;
        memset(&c, 0, sizeof(c));
        memcpy(&c.link_create, saved_blob, sizeof(c.link_create));
        c.link_create.prog_fd = (uint32_t)new_pfd;
        if (saved_create_attr_size == 0 ||
            saved_create_attr_size > sizeof(c)) {
            if (saved_target_hold_fd >= 0)
                real_close(saved_target_hold_fd);
            APPEND_DETAIL("link_fd=%d: invalid saved BPF_LINK_CREATE attr "
                          "size=%u; ",
                          links[i], saved_create_attr_size);
            partial = 1;
            real_close((int)live_link_fd);
            continue;
        }

        long reopened_perf_fd = -1;
        if (c.link_create.attach_type == BPF_PERF_EVENT) {
            if (saved_target_hold_fd >= 0) {
                c.link_create.target_fd = (uint32_t)saved_target_hold_fd;
            } else if (saved_perf_attr_size == 0) {
                APPEND_DETAIL("link_fd=%d: BPF_PERF_EVENT target snapshot missing; ",
                              links[i]);
                partial = 1;
                real_close((int)live_link_fd);
                continue;
            }
            pthread_mutex_lock(&state_mutex);
            int original_target_live =
                saved_target_hold_fd >= 0 ||
                perf_find((int)c.link_create.target_fd) != NULL;
            pthread_mutex_unlock(&state_mutex);
            if (!original_target_live) {
                struct perf_event_attr *reopen_attr =
                    (struct perf_event_attr *)saved_perf_attr;
                if (saved_probe_target[0])
                    reopen_attr->config1 = (uintptr_t)saved_probe_target;
                reopened_perf_fd = real_syscall(
                    SYS_perf_event_open, (long)(intptr_t)reopen_attr,
                    (long)saved_perf_pid, (long)saved_perf_cpu,
                    (long)saved_perf_group_fd,
                    (long)saved_perf_open_flags, 0);
                if (reopened_perf_fd < 0) {
                    APPEND_DETAIL(
                        "link_fd=%d: perf_event_open fallback errno=%d; ",
                        links[i], errno);
                    partial = 1;
                    real_close((int)live_link_fd);
                    continue;
                }
                c.link_create.target_fd = (uint32_t)reopened_perf_fd;
            }
        }

        struct link_entry *replacement =
            (struct link_entry *)calloc(1, sizeof(*replacement));
        if (!replacement) {
            if (saved_target_hold_fd >= 0)
                real_close(saved_target_hold_fd);
            if (reopened_perf_fd >= 0)
                real_close((int)reopened_perf_fd);
            APPEND_DETAIL("link_fd=%d: replacement state allocation failed; ",
                          links[i]);
            partial = 1;
            real_close((int)live_link_fd);
            continue;
        }
        replacement->target_hold_fd = saved_target_hold_fd;
        saved_target_hold_fd = -1;
        int saved_link_fd_flags = 0;
        saved_link_fd_flags = (int)real_syscall(
            SYS_fcntl, links[i], F_GETFD, 0);
        if (saved_link_fd_flags < 0) {
            int flags_err = errno;
            APPEND_DETAIL("link_fd=%d link_id=%u: F_GETFD errno=%d; ",
                          links[i], saved_link_id, flags_err);
            link_entry_free(replacement);
            if (reopened_perf_fd >= 0)
                real_close((int)reopened_perf_fd);
            real_close((int)live_link_fd);
            partial = 1;
            continue;
        }
        if (real_close(links[i]) < 0) {
            int close_err = errno;
            APPEND_DETAIL("link_fd=%d link_id=%u: close errno=%d; ",
                          links[i], saved_link_id, close_err);
            link_entry_free(replacement);
            if (reopened_perf_fd >= 0)
                real_close((int)reopened_perf_fd);
            real_close((int)live_link_fd);
            partial = 1;
            continue;
        }
        /* BPF_LINK_GET_FD_BY_ID added a second reference.  Both link fds must
         * close before the unsupported-UPDATE link can be recreated. */
        real_close((int)live_link_fd);
        long new_link = real_syscall(SYS_bpf, BPF_LINK_CREATE, &c,
                                     saved_create_attr_size);
        int cre_err = new_link < 0 ? errno : 0;
        if (new_link >= 0 &&
            preserve_recreated_link_fd(
                &new_link, links[i], saved_link_fd_flags) != 0) {
            cre_err = errno;
            real_close((int)new_link);
            new_link = -1;
        }
        if (new_link < 0) {
            int rollback_err = 0;
            long rollback_link = -1;
            int rollback_prog_fd = old_prog_fd >= 0
                                       ? old_prog_fd
                                       : old_prog_hold_fd;
            if (rollback_prog_fd >= 0) {
                union bpf_attr old_c = c;
                old_c.link_create.prog_fd = (uint32_t)rollback_prog_fd;
                rollback_link = real_syscall(SYS_bpf, BPF_LINK_CREATE,
                                             &old_c, saved_create_attr_size);
                if (rollback_link >= 0 &&
                    preserve_recreated_link_fd(
                        &rollback_link, links[i], saved_link_fd_flags) != 0) {
                    rollback_err = errno;
                    real_close((int)rollback_link);
                    rollback_link = -1;
                }
                if (rollback_link >= 0) {
                    replacement->fd = (int)rollback_link;
                    replacement->prog_fd = (uint32_t)rollback_prog_fd;
                    replacement->target_fd = old_c.link_create.target_fd;
                    replacement->attach_type = old_c.link_create.attach_type;
                    replacement->kernel_link_id =
                        resolve_kernel_id((int)rollback_link);
                    replacement->create_attr_size = saved_create_attr_size;
                    memcpy(replacement->create_attr_blob,
                           &old_c.link_create,
                           sizeof(old_c.link_create) <
                                   sizeof(replacement->create_attr_blob)
                               ? sizeof(old_c.link_create)
                               : sizeof(replacement->create_attr_blob));
                }
                else if (rollback_err == 0)
                    rollback_err = errno;
            }
            log_line("reload_and_reattach: LINK_UPDATE failed (errno=%d) and "
                     "fallback BPF_LINK_CREATE failed (errno=%d) for "
                     "old_link_fd=%d; rollback ret=%ld errno=%d",
                     upd_err, cre_err, links[i], rollback_link,
                     rollback_err);
            APPEND_DETAIL("link_fd=%d: LINK_UPDATE errno=%d, "
                          "LINK_CREATE fallback errno=%d (target_fd=%u "
                          "attach=%u flags=%u perf_type=%u perf_config=%llu; "
                          "rollback_ret=%ld rollback_errno=%d); ",
                          links[i], upd_err, cre_err,
                          c.link_create.target_fd, c.link_create.attach_type,
                          c.link_create.flags,
                          saved_perf_attr_size > 0
                              ? ((const struct perf_event_attr *)saved_perf_attr)->type
                              : 0,
                          saved_perf_attr_size > 0
                              ? (unsigned long long)((const struct perf_event_attr *)saved_perf_attr)->config
                              : 0,
                          rollback_link, rollback_err);
            if (rollback_link >= 0) {
                if (saved_perf_attr_size > 0) {
                    memcpy(replacement->target_perf_attr_blob,
                           saved_perf_attr, saved_perf_attr_size);
                    replacement->target_perf_attr_size = saved_perf_attr_size;
                    replacement->target_perf_pid = saved_perf_pid;
                    replacement->target_perf_cpu = saved_perf_cpu;
                    replacement->target_perf_group_fd = saved_perf_group_fd;
                    replacement->target_perf_open_flags = saved_perf_open_flags;
                    snprintf(replacement->target_perf_probe_target,
                             sizeof(replacement->target_perf_probe_target),
                             "%s", saved_probe_target);
                }
                pthread_mutex_lock(&state_mutex);
                link_remove(links[i]);
                link_insert(replacement);
                pthread_mutex_unlock(&state_mutex);
                if (replaced_with)
                    replaced_with[i] = (int)rollback_link;
            } else {
                link_entry_free(replacement);
            }
            if (reopened_perf_fd >= 0) {
                if (rollback_link >= 0)
                    (void)real_ioctl((int)reopened_perf_fd,
                                     PERF_EVENT_IOC_ENABLE, NULL);
                real_close((int)reopened_perf_fd);
            }
            partial = 1;
            continue;
        }
        if (reopened_perf_fd >= 0) {
            (void)real_ioctl((int)reopened_perf_fd,
                             PERF_EVENT_IOC_ENABLE, NULL);
            real_close((int)reopened_perf_fd);
        }

        replacement->fd = (int)new_link;
        replacement->prog_fd = (uint32_t)new_pfd;
        replacement->target_fd = c.link_create.target_fd;
        replacement->attach_type = c.link_create.attach_type;
        replacement->kernel_link_id = resolve_kernel_id((int)new_link);
        replacement->create_attr_size = saved_create_attr_size;
        memcpy(replacement->create_attr_blob, &c.link_create,
               sizeof(c.link_create) < sizeof(replacement->create_attr_blob)
                   ? sizeof(c.link_create)
                   : sizeof(replacement->create_attr_blob));
        if (saved_perf_attr_size > 0) {
            memcpy(replacement->target_perf_attr_blob, saved_perf_attr,
                   saved_perf_attr_size);
            replacement->target_perf_attr_size = saved_perf_attr_size;
            replacement->target_perf_pid = saved_perf_pid;
            replacement->target_perf_cpu = saved_perf_cpu;
            replacement->target_perf_group_fd = saved_perf_group_fd;
            replacement->target_perf_open_flags = saved_perf_open_flags;
            snprintf(replacement->target_perf_probe_target,
                     sizeof(replacement->target_perf_probe_target), "%s",
                     saved_probe_target);
        }

        pthread_mutex_lock(&state_mutex);
        link_remove(links[i]);
        link_insert(replacement);
        pthread_mutex_unlock(&state_mutex);
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
    for (uint32_t i = 0; i < nperfs; i++) {
        int r = real_ioctl(perfs[i], PERF_EVENT_IOC_SET_BPF,
                           (void *)(intptr_t)new_pfd);
        if (r == 0) {
            pthread_mutex_lock(&state_mutex);
            struct perf_entry *updated = perf_find(perfs[i]);
            if (updated) updated->attached_prog_fd = (int)new_pfd;
            pthread_mutex_unlock(&state_mutex);
            continue;
        }
        int set_err = errno;
        /* SET_BPF returns EEXIST when the event already has a BPF prog
         * attached (kernel doesn't support replacement). Build and enable a
         * fresh event first, then dup3 it over the old fd. Preserving the fd
         * number is required for app runtimes such as Go that retain the
         * original integer in their event object. */
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
        int sr = real_ioctl((int)new_perf_fd, PERF_EVENT_IOC_SET_BPF,
                            (void *)(intptr_t)new_pfd);
        if (sr != 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF on new event errno=%d; ",
                          perfs[i], errno);
            real_close((int)new_perf_fd);
            partial = 1;
            continue;
        }
        if (real_ioctl((int)new_perf_fd, PERF_EVENT_IOC_ENABLE, NULL) != 0) {
            APPEND_DETAIL("perf_fd=%d: ENABLE on new event errno=%d; ",
                          perfs[i], errno);
            real_close((int)new_perf_fd);
            partial = 1;
            continue;
        }
        int status_flags = fcntl(perfs[i], F_GETFL);
        int descriptor_flags = fcntl(perfs[i], F_GETFD);
        if (status_flags < 0 || descriptor_flags < 0 ||
            fcntl((int)new_perf_fd, F_SETFL, status_flags) != 0) {
            APPEND_DETAIL("perf_fd=%d: preserve fd flags errno=%d; ",
                          perfs[i], errno);
            real_close((int)new_perf_fd);
            partial = 1;
            continue;
        }
        int dup_flags = (descriptor_flags & FD_CLOEXEC) ? O_CLOEXEC : 0;
        if (real_syscall(SYS_dup3, (int)new_perf_fd, perfs[i],
                         dup_flags) < 0) {
            APPEND_DETAIL("perf_fd=%d: dup3 replacement errno=%d; ",
                          perfs[i], errno);
            real_close((int)new_perf_fd);
            partial = 1;
            continue;
        }
        real_close((int)new_perf_fd);
        /* dup3 preserved the table key, so only the attached program changes. */
        pthread_mutex_lock(&state_mutex);
        struct perf_entry *updated = perf_find(perfs[i]);
        if (updated) updated->attached_prog_fd = (int)new_pfd;
        pthread_mutex_unlock(&state_mutex);
        if (!updated) {
            APPEND_DETAIL("perf_fd=%d: state disappeared after replacement; ",
                          perfs[i]);
            partial = 1;
            continue;
        }
        log_line("reload_and_reattach: perf SET_BPF→reopen fallback OK "
                 "fd=%d preserved via temp_fd=%ld (errno=%d on initial "
                 "SET_BPF)", perfs[i], new_perf_fd, set_err);
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
            ne->prog_id = new_kid;
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

    /* Preserve the loader-visible program fd number when possible. Attached
     * corpus workloads dispatch through kernel attach objects, but micro's
     * kernel_rejit path keeps the original fd in micro_exec and issues
     * BPF_PROG_TEST_RUN on it after the shim reloads. Move the new program
     * back onto that fd so both paths observe the optimized bytecode. */
    int final_prog_fd = (int)new_pfd;
    if (old_prog_fd >= 0 && old_prog_fd != (int)new_pfd) {
        long dup_ret = real_syscall(SYS_dup3, (int)new_pfd, old_prog_fd,
                                    O_CLOEXEC);
        if (dup_ret >= 0) {
            final_prog_fd = old_prog_fd;
            real_close((int)new_pfd);
            log_line("reload_and_reattach: preserved loader prog fd=%d "
                     "with new kid pending", old_prog_fd);
        } else {
            int dup_errno = errno;
            log_line("reload_and_reattach: failed to preserve loader prog "
                     "fd old=%d new=%ld errno=%d; continuing with new fd",
                     old_prog_fd, new_pfd, dup_errno);
            real_close(old_prog_fd);
        }
    }

    /* Resolve the new kernel id and commit the swap into prog_entry. */
    pthread_mutex_lock(&state_mutex);
    /* Reload p in case state was swapped under us (shouldn't happen during a
     * single execute_plan, but cheap to defensively re-lookup). */
    int previous_fd = p->fd;
    p->fd = final_prog_fd;
    if (new_kid) p->kernel_prog_id = new_kid;
    if (p->fd != previous_fd)
        prog_rebucket_locked(p, previous_fd);
    pthread_mutex_unlock(&state_mutex);

    free(owned_log);
    return partial ? RELOAD_PARTIAL_ATTACH : RELOAD_OK;
}

#endif /* BPFREJIT_SHIM_RELOAD_H */
