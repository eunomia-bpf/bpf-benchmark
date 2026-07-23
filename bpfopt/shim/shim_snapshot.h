#ifndef BPFREJIT_SHIM_SNAPSHOT_H
#define BPFREJIT_SHIM_SNAPSHOT_H

#ifndef BPF_PSEUDO_KOP_CALL
#define BPF_PSEUDO_KOP_CALL 4
#endif

/* --- snapshot helpers (MAP_IDS / MAP_VALUES / canonicalize) --- */

/* Map types that can produce useful bpftool JSON snapshots for map_inline. */
static int map_type_needs_dump(uint32_t t) {
    return t == BPF_MAP_TYPE_HASH || t == BPF_MAP_TYPE_ARRAY ||
           t == BPF_MAP_TYPE_PERCPU_ARRAY || t == BPF_MAP_TYPE_LRU_HASH ||
           t == BPF_MAP_TYPE_LPM_TRIE;
}

/* Dedup an (fd, kid, type) snapshot into per-unique-kid arrays. The result
 * matches what the downstream `--map-ids` CSV needs (one slot per unique
 * kernel map) plus a representative loader fd per kid (used to rebuild
 * fd_array during verifier-state probes). Caller frees all three arrays. */
static int dedup_snapshot_by_kid(const uint32_t *snap_fds,
                                 const uint32_t *snap_kids,
                                 const uint32_t *snap_types,
                                 uint32_t snap_n,
                                 uint32_t **kids_out, uint32_t **types_out,
                                 uint32_t **rep_fds_out, uint32_t *n_out) {
    uint32_t cap = snap_n + 1;
    uint32_t *kids = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *types = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *fds = (uint32_t *)calloc(cap, sizeof(uint32_t));
    if (!kids || !types || !fds) { free(kids); free(types); free(fds); return -1; }
    uint32_t n = 0;
    for (uint32_t i = 0; i < snap_n; i++) {
        if (snap_kids[i] == 0) continue;
        uint32_t k = 0;
        for (; k < n; k++) if (kids[k] == snap_kids[i]) break;
        if (k < n) continue;
        kids[n] = snap_kids[i];
        types[n] = snap_types[i];
        fds[n] = snap_fds[i];
        n++;
    }
    *kids_out = kids; *types_out = types; *rep_fds_out = fds; *n_out = n;
    return 0;
}

static void format_map_ids_csv(uint32_t *ids, uint32_t n, char *out, size_t out_sz) {
    if (n == 0 || !ids) { snprintf(out, out_sz, "0"); return; }
    size_t o = 0;
    for (uint32_t i = 0; i < n && o + 16 < out_sz; i++)
        o += snprintf(out + o, out_sz - o, "%s%u", i ? "," : "", ids[i]);
}

struct shim_map_ref {
    uint32_t pc;
    int loader_fd;
    uint32_t kernel_id;
    uint32_t map_type;
    uint32_t key_size;
    uint32_t value_size;
    uint32_t max_entries;
    char name[17];
};

static uint64_t fnv1a64_update(uint64_t h, const void *data, size_t len) {
    const uint8_t *p = (const uint8_t *)data;
    for (size_t i = 0; i < len; i++) {
        h ^= p[i];
        h *= 0x100000001b3ULL;
    }
    return h;
}

static uint64_t normalized_prog_hash(const struct bpf_insn *insns,
                                     uint32_t insn_cnt) {
    uint64_t h = 1469598103934665603ULL;
    for (uint32_t pc = 0; pc < insn_cnt; pc++) {
        struct bpf_insn copy = insns[pc];
        if (copy.code == (BPF_LD | BPF_DW | BPF_IMM) &&
            (copy.src_reg == BPF_PSEUDO_MAP_FD ||
             copy.src_reg == BPF_PSEUDO_MAP_VALUE ||
             copy.src_reg == BPF_PSEUDO_MAP_IDX ||
             copy.src_reg == BPF_PSEUDO_MAP_IDX_VALUE)) {
            copy.imm = 0;
            h = fnv1a64_update(h, &copy, sizeof(copy));
            if (pc + 1 < insn_cnt) {
                struct bpf_insn next = insns[++pc];
                next.imm = 0;
                h = fnv1a64_update(h, &next, sizeof(next));
            }
            continue;
        }
        h = fnv1a64_update(h, &copy, sizeof(copy));
    }
    return h;
}

static int query_map_info_by_fd(int fd, struct bpf_map_info *info) {
    memset(info, 0, sizeof(*info));
    union bpf_attr ia = {0};
    ia.info.bpf_fd = (uint32_t)fd;
    ia.info.info_len = sizeof(*info);
    ia.info.info = (uintptr_t)info;
    return real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) < 0
               ? -1
               : 0;
}

static void fill_map_ref_from_info(struct shim_map_ref *ref,
                                   uint32_t pc,
                                   int loader_fd,
                                   const struct bpf_map_info *info) {
    memset(ref, 0, sizeof(*ref));
    ref->pc = pc;
    ref->loader_fd = loader_fd;
    ref->kernel_id = info->id;
    ref->map_type = info->type;
    ref->key_size = info->key_size;
    ref->value_size = info->value_size;
    ref->max_entries = info->max_entries;
    memcpy(ref->name, info->name, 16);
    ref->name[16] = 0;
}

static int append_map_ref(struct shim_map_ref **refs, uint32_t *n,
                          uint32_t *cap, const struct shim_map_ref *ref) {
    if (*n == *cap) {
        uint32_t next_cap = *cap ? *cap * 2 : 8;
        struct shim_map_ref *nr = (struct shim_map_ref *)realloc(
            *refs, (size_t)next_cap * sizeof(**refs));
        if (!nr) return -1;
        *refs = nr;
        *cap = next_cap;
    }
    (*refs)[(*n)++] = *ref;
    return 0;
}

static int collect_current_map_refs(const struct bpf_insn *insns,
                                    uint32_t insn_cnt,
                                    struct shim_map_ref **refs_out,
                                    uint32_t *n_out) {
    *refs_out = NULL;
    *n_out = 0;
    uint32_t cap = 0;
    struct shim_map_ref *refs = NULL;
    for (uint32_t pc = 0; pc < insn_cnt; pc++) {
        const struct bpf_insn *insn = &insns[pc];
        if (insn->code != (BPF_LD | BPF_DW | BPF_IMM))
            continue;
        if (insn->src_reg != BPF_PSEUDO_MAP_FD &&
            insn->src_reg != BPF_PSEUDO_MAP_VALUE)
            continue;
        if (pc + 1 >= insn_cnt)
            break;
        int fd = insn->imm;
        if (fd < 0) {
            pc++;
            continue;
        }
        struct bpf_map_info mi;
        if (query_map_info_by_fd(fd, &mi) != 0 || mi.id == 0) {
            log_line("map ref fd resolution failed: fd=%d errno=%d",
                     fd, errno);
            free(refs);
            return -1;
        }
        struct shim_map_ref ref;
        fill_map_ref_from_info(&ref, pc, fd, &mi);
        if (append_map_ref(&refs, n_out, &cap, &ref) != 0) {
            free(refs);
            return -1;
        }
        pc++;
    }
    *refs_out = refs;
    return 0;
}

static int mkdir_one(const char *path) {
    if (mkdir(path, 0755) == 0 || errno == EEXIST)
        return 0;
    return -1;
}

static int run_bpftool_to_file(char *const argv[], const char *out_path);

static char **snapshot_env_without_ld_preload(void) {
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

/* Run `bpftool <args...>` redirecting stdout to `out_path`. Returns 0 on
 * exit 0, else -1. Args must be NULL-terminated. */
static int run_bpftool_to_file(char *const argv[], const char *out_path) {
    posix_spawn_file_actions_t fa;
    if (posix_spawn_file_actions_init(&fa) != 0) return -1;
    posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, out_path,
                                     O_WRONLY | O_CREAT | O_TRUNC, 0644);
    /* /dev/null for stderr to keep the log tidy; bpftool warnings can be
     * inspected via the saved JSON file if missing. */
    posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, "/dev/null",
                                     O_WRONLY, 0);
    pid_t pid;
    char **clean_env = snapshot_env_without_ld_preload();
    int rc = posix_spawnp(&pid, argv[0], &fa, NULL, argv,
                          clean_env ? clean_env : environ);
    posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0) return -1;
    int st = 0;
    waitpid(pid, &st, 0);
    return (WIFEXITED(st) && WEXITSTATUS(st) == 0) ? 0 : -1;
}

/* Write per-map snapshots into map_values_dir, keyed by kernel map id so the
 * filename matches what map_inline cross-checks against (`show.id`). bpfopt
 * gets a separate fd-to-id.json so canonicalize can route loader-fd-in-imm
 * back to the right kernel map. */
static void write_map_snapshots(const char *map_values_dir,
                                const uint32_t *kernel_ids,
                                const uint32_t *types, uint32_t n) {
    mkdir(map_values_dir, 0755);
    for (uint32_t i = 0; i < n; i++) {
        if (kernel_ids[i] == 0) continue;
        char id_str[16];
        snprintf(id_str, sizeof(id_str), "%u", kernel_ids[i]);
        char show_path[512], dump_path[512];
        snprintf(show_path, sizeof(show_path), "%s/map-%u.show.json",
                 map_values_dir, kernel_ids[i]);
        char *const show_argv[] = {"bpftool", "-j", "map", "show", "id",
                                   id_str, NULL};
        (void)run_bpftool_to_file(show_argv, show_path);
        if (!map_type_needs_dump(types[i])) continue;
        snprintf(dump_path, sizeof(dump_path), "%s/map-%u.dump.json",
                 map_values_dir, kernel_ids[i]);
        /* Pre-filter by max_entries × (key+value) so we don't ask bpftool to
         * walk multi-million-entry maps (katran lru_mapping etc.) — bpftool
         * has no timeout/limit and would block the runner for hours. We
         * query the kernel for map_info via BPF_OBJ_GET_INFO_BY_FD and
         * estimate the dump size before spawning bpftool. */
        const uint64_t MAP_SNAPSHOT_MAX_BYTES = 64ULL * 1024ULL;
        int skip_dump = 0;
        uint64_t estimated = 0;
        {
            union bpf_attr ga = {0};
            ga.map_id = kernel_ids[i];
            long mfd = real_syscall(SYS_bpf, BPF_MAP_GET_FD_BY_ID, &ga, sizeof(ga));
            if (mfd >= 0) {
                struct bpf_map_info mi;
                memset(&mi, 0, sizeof(mi));
                union bpf_attr ia = {0};
                ia.info.bpf_fd = (uint32_t)mfd;
                ia.info.info_len = sizeof(mi);
                ia.info.info = (uintptr_t)&mi;
                if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) >= 0) {
                    estimated = (uint64_t)mi.max_entries *
                                ((uint64_t)mi.key_size + (uint64_t)mi.value_size);
                }
                real_close((int)mfd);
            }
            /* JSON encoding inflates raw bytes by ≈ 4× (hex + commas + keys);
             * compare against 4× threshold to be conservative. */
            if (estimated > MAP_SNAPSHOT_MAX_BYTES * 4) skip_dump = 1;
        }
        if (skip_dump) {
            int wfd = open(dump_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (wfd >= 0) {
                /* Keep the skip-marker schema narrow: bpfopt's map_inline
                 * parses `skipped`, `reason`,
                 * `size_bytes`, `limit_bytes` and rejects unknown keys
                 * like `estimated_bytes`. */
                dprintf(wfd,
                        "{\"skipped\":true,\"reason\":\"size_limit\","
                        "\"size_bytes\":%llu,\"limit_bytes\":%llu}\n",
                        (unsigned long long)estimated,
                        (unsigned long long)MAP_SNAPSHOT_MAX_BYTES);
                real_close(wfd);
            }
            continue;
        }
        char *const dump_argv[] = {"bpftool", "-j", "map", "dump", "id",
                                   id_str, NULL};
        (void)run_bpftool_to_file(dump_argv, dump_path);
        /* Secondary post-dump size check: pre-filter above bails for huge
         * maps before spawning bpftool, but bpftool may still emit JSON
         * larger than the threshold for medium-sized maps. */
        struct stat dst;
        if (stat(dump_path, &dst) == 0 &&
            (uint64_t)dst.st_size > MAP_SNAPSHOT_MAX_BYTES) {
            int wfd = open(dump_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (wfd >= 0) {
                dprintf(wfd,
                        "{\"skipped\":true,\"reason\":\"size_limit\","
                        "\"size_bytes\":%llu,\"limit_bytes\":%llu}\n",
                        (unsigned long long)dst.st_size,
                        (unsigned long long)MAP_SNAPSHOT_MAX_BYTES);
                real_close(wfd);
            }
            /* Skip inner_map_ids supplement when we've dropped the raw dump. */
            continue;
        }
    }
}

/* Write the loader-fd → kernel-map-id JSON for one prog's PROG_LOAD-time
 * snapshot (see prog_entry.snap_*). Canonicalize uses these to collapse
 * N-fds-pointing-to-same-kid into one fd_array slot. */
static int write_fd_to_id_json(const char *path, const uint32_t *fds,
                               const uint32_t *kids, uint32_t n) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return -1;
    FILE *f = fdopen(fd, "w");
    if (!f) { real_close(fd); return -1; }
    fprintf(f, "{");
    int first = 1;
    for (uint32_t i = 0; i < n; i++) {
        if (kids[i] == 0) continue;
        fprintf(f, "%s\"%u\":%u", first ? "" : ",", fds[i], kids[i]);
        first = 0;
    }
    fprintf(f, "}\n");
    fclose(f);
    return 0;
}

/* Invoke `bpfopt --canonicalize-map-refs ...`. Writes canonicalized bytecode
 * to out_path. Captures stdout+stderr into `log_path` (if non-NULL) so a
 * caller can surface the failure reason. Returns 0 on success. */
static int run_canonicalize(const char *input_path, const char *out_path,
                            const char *target_json, const char *map_ids_csv,
                            const char *fd_to_id_json,
                            const char *log_path) {
    char *const argv_with_fd_to_id_and_target[] = {
        "bpfopt", "--canonicalize-map-refs",
        "--input", (char *)input_path,
        "--output", (char *)out_path,
        "--map-ids", (char *)map_ids_csv,
        "--target", (char *)target_json,
        "--target-output", (char *)target_json,
        "--fd-to-id", (char *)fd_to_id_json,
        NULL};
    char *const argv_with_fd_to_id[] = {
        "bpfopt", "--canonicalize-map-refs",
        "--input", (char *)input_path,
        "--output", (char *)out_path,
        "--map-ids", (char *)map_ids_csv,
        "--fd-to-id", (char *)fd_to_id_json,
        NULL};
    char *const argv_kernel_ids_and_target[] = {
        "bpfopt", "--canonicalize-map-refs",
        "--input", (char *)input_path,
        "--output", (char *)out_path,
        "--map-ids", (char *)map_ids_csv,
        "--target", (char *)target_json,
        "--target-output", (char *)target_json,
        NULL};
    char *const argv_kernel_ids[] = {
        "bpfopt", "--canonicalize-map-refs",
        "--input", (char *)input_path,
        "--output", (char *)out_path,
        "--map-ids", (char *)map_ids_csv,
        NULL};
    char *const *argv = NULL;
    if (fd_to_id_json && target_json)
        argv = argv_with_fd_to_id_and_target;
    else if (fd_to_id_json)
        argv = argv_with_fd_to_id;
    else if (target_json)
        argv = argv_kernel_ids_and_target;
    else
        argv = argv_kernel_ids;
    /* Strip LD_PRELOAD so the bpfopt child doesn't re-attach the shim. */
    size_t n_env = 0;
    while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    size_t j = 0;
    for (size_t i = 0; clean_env && i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    if (clean_env) clean_env[j] = NULL;
    posix_spawn_file_actions_t fa;
    int fa_inited = 0;
    if (log_path && posix_spawn_file_actions_init(&fa) == 0) {
        fa_inited = 1;
        posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, log_path,
                                         O_WRONLY | O_CREAT | O_TRUNC, 0644);
        posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, log_path,
                                         O_WRONLY | O_APPEND, 0);
    }
    pid_t pid;
    int rc = posix_spawnp(&pid, "bpfopt", fa_inited ? &fa : NULL, NULL,
                          (char *const *)argv, clean_env ? clean_env : environ);
    if (fa_inited) posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0) {
        if (log_path) {
            int fd = open(log_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd >= 0) {
                dprintf(fd, "failed to spawn bpfopt: %s (rc=%d)\n",
                        strerror(rc), rc);
                real_close(fd);
            }
        }
        return -1;
    }
    int st = 0;
    pid_t waited;
    do {
        waited = waitpid(pid, &st, 0);
    } while (waited < 0 && errno == EINTR);
    if (waited == pid && WIFEXITED(st) && WEXITSTATUS(st) == 0)
        return 0;
    if (log_path) {
        int fd = open(log_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd >= 0) {
            if (waited < 0)
                dprintf(fd, "waitpid for bpfopt failed: %s\n", strerror(errno));
            else if (WIFSIGNALED(st))
                dprintf(fd, "bpfopt terminated by signal %d\n", WTERMSIG(st));
            else
                dprintf(fd, "bpfopt exited with status %d\n",
                        WIFEXITED(st) ? WEXITSTATUS(st) : -1);
            real_close(fd);
        }
    }
    return -1;
}

/* Parse target.json for the (btf_id, call_offset) pairs of BTF modules that
 * provide kop kfuncs. Pairs are stored adjacent in the JSON by serde_json's
 * alphabetic field ordering: "btf_func_id" < "btf_id" < "call_offset". We
 * scan linearly to extract each (btf_id, call_offset). Skips call_offset==0
 * entries (those mean vmlinux which doesn't need an fd_array slot). Caller
 * frees both arrays. Returns 0 on success even if no modules. */
static int parse_target_btf_modules(const char *target_json_path,
                                    uint32_t **btf_ids_out,
                                    uint32_t **call_offsets_out,
                                    uint32_t *n_out) {
    *btf_ids_out = NULL; *call_offsets_out = NULL; *n_out = 0;
    if (!target_json_path || !target_json_path[0])
        return 0;
    int fd = open(target_json_path, O_RDONLY);
    if (fd < 0) return 0;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size <= 0 || st.st_size > 1024 * 1024) {
        real_close(fd); return 0;
    }
    char *buf = (char *)malloc(st.st_size + 1);
    if (!buf) { real_close(fd); return -1; }
    ssize_t n = read(fd, buf, st.st_size);
    real_close(fd);
    if (n != st.st_size) { free(buf); return -1; }
    buf[n] = 0;
    uint32_t cap = 8, count = 0;
    uint32_t *bids = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *offs = (uint32_t *)calloc(cap, sizeof(uint32_t));
    if (!bids || !offs) { free(bids); free(offs); free(buf); return -1; }
    const char *p = buf;
    while ((p = strstr(p, "\"btf_id\""))) {
        const char *col = strchr(p, ':');
        if (!col) break;
        col++;
        while (*col == ' ' || *col == '\t') col++;
        uint32_t bid = (uint32_t)strtoul(col, NULL, 10);
        const char *co_key = strstr(col, "\"call_offset\"");
        if (!co_key) break;
        const char *co_col = strchr(co_key, ':');
        if (!co_col) break;
        co_col++;
        while (*co_col == ' ' || *co_col == '\t') co_col++;
        uint32_t off = (uint32_t)strtoul(co_col, NULL, 10);
        p = co_col;
        if (off == 0 || bid == 0) continue; /* vmlinux or empty entry */
        int dup = 0;
        for (uint32_t i = 0; i < count; i++)
            if (bids[i] == bid && offs[i] == off) { dup = 1; break; }
        if (dup) continue;
        if (count == cap) {
            cap *= 2;
            uint32_t *nb = (uint32_t *)realloc(bids, cap * sizeof(uint32_t));
            uint32_t *no = (uint32_t *)realloc(offs, cap * sizeof(uint32_t));
            if (!nb || !no) { free(nb ? nb : bids); free(no ? no : offs); free(buf); return -1; }
            bids = nb; offs = no;
        }
        bids[count] = bid; offs[count] = off;
        count++;
    }
    free(buf);
    *btf_ids_out = bids; *call_offsets_out = offs; *n_out = count;
    return 0;
}

/* Build the fd_array passed to BPF_PROG_LOAD for an optimized bytecode.
 * Layout:
 *   - slots [0..nr_map_fds): map fds (dup'd from loader fds)
 *   - slots at each module's `call_offset`: BTF module fds (from
 *     BPF_BTF_GET_FD_BY_ID(btf_id))
 *   - padding -1 for unused slots between
 *
 * `*out_fd_array` is heap-allocated; *out_count = total slot count. Caller
 * frees the array and `real_close()`s each non-negative fd. Returns 0 on
 * success, -1 on OOM/IO. */
/* `map_kernel_ids[i]` is the kernel-side BPF map id (stable). We open a fresh
 * fd via BPF_MAP_GET_FD_BY_ID for every reload — loader-side fds captured at
 * PROG_LOAD time may have been closed by the host app after init (tracee
 * drops its loader map fds once libbpf is done with them; reusing the
 * cached fd would return -EBADF). */
static int build_full_fd_array(const char *target_json_path,
                               const uint32_t *map_kernel_ids,
                               uint32_t nr_maps,
                               int **out_fd_array,
                               uint32_t *out_count) {
    *out_fd_array = NULL; *out_count = 0;
    uint32_t *btf_ids = NULL, *call_offsets = NULL, n_mods = 0;
    if (parse_target_btf_modules(target_json_path, &btf_ids, &call_offsets,
                                 &n_mods) != 0)
        return -1;

    /* Determine total slot count = max(nr_maps, max(call_offset) + 1). */
    uint32_t total = nr_maps;
    for (uint32_t i = 0; i < n_mods; i++) {
        uint32_t need = call_offsets[i] + 1;
        if (need > total) total = need;
    }
    if (total == 0) {
        *out_count = 0;
        free(btf_ids); free(call_offsets);
        return 0;
    }
    int *arr = (int *)malloc(total * sizeof(int));
    if (!arr) { free(btf_ids); free(call_offsets); return -1; }
    for (uint32_t i = 0; i < total; i++) arr[i] = -1;
    /* Map fds in [0, nr_maps). Resolve fresh from kernel id; the snapshot's
     * loader-side fds may have been closed since PROG_LOAD. */
    for (uint32_t i = 0; i < nr_maps; i++) {
        uint32_t kid = map_kernel_ids[i];
        if (kid == 0) { arr[i] = -1; continue; }
        union bpf_attr ga = {0};
        ga.map_id = kid;
        long mfd = real_syscall(SYS_bpf, BPF_MAP_GET_FD_BY_ID, &ga, sizeof(ga));
        arr[i] = (mfd >= 0) ? (int)mfd : -1;
    }
    /* BTF module fds at call_offset slots. */
    for (uint32_t i = 0; i < n_mods; i++) {
        union bpf_attr ga = {0};
        ga.info.bpf_fd = 0;        /* unused for BTF_GET_FD_BY_ID */
        ga.btf_id = btf_ids[i];
        long bfd = real_syscall(SYS_bpf, BPF_BTF_GET_FD_BY_ID, &ga, sizeof(ga));
        if (bfd >= 0) {
            if (call_offsets[i] < total) arr[call_offsets[i]] = (int)bfd;
            else real_close((int)bfd);
        }
    }
    /* Slot [0] sanity: if no maps but ≥1 module, fd_array[0] must be a
     * valid BTF fd (kernel verifier pre-scans). Reuse the first module fd. */
    if (nr_maps == 0 && n_mods > 0) {
        for (uint32_t i = 0; i < total; i++)
            if (arr[i] >= 0) { arr[0] = arr[i]; break; }
    }
    free(btf_ids); free(call_offsets);
    *out_fd_array = arr;
    *out_count = total;
    return 0;
}

/* Close every non-negative fd in arr and free arr. Pairs with build_full_fd_array. */
static void free_full_fd_array(int *arr, uint32_t count) {
    if (!arr) return;
    /* Slot 0 may alias a higher slot when nr_maps==0; deduplicate before close. */
    for (uint32_t i = 0; i < count; i++) {
        if (arr[i] < 0) continue;
        int dupd = 0;
        for (uint32_t j = i + 1; j < count; j++) if (arr[j] == arr[i]) { arr[j] = -1; dupd = 1; break; }
        (void)dupd;
        real_close(arr[i]);
        arr[i] = -1;
    }
    free(arr);
}

#endif /* BPFREJIT_SHIM_SNAPSHOT_H */
