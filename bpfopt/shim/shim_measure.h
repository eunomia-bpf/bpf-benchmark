#ifndef BPFREJIT_SHIM_MEASURE_H
#define BPFREJIT_SHIM_MEASURE_H

static uint32_t current_measure_generation;

static int query_prog_info(struct prog_entry *p, struct bpf_prog_info *info) {
    memset(info, 0, sizeof(*info));
    int fd = p->fd;
    int close_fd = 0;
    if (p->kernel_prog_id) {
        union bpf_attr ga = {0};
        ga.prog_id = p->kernel_prog_id;
        fd = (int)real_syscall(SYS_bpf, BPF_PROG_GET_FD_BY_ID, &ga,
                               sizeof(ga));
        if (fd < 0)
            return -1;
        close_fd = 1;
    }
    union bpf_attr ia = {0};
    ia.info.bpf_fd = (uint32_t)fd;
    ia.info.info_len = sizeof(*info);
    ia.info.info = (uintptr_t)info;
    long rc = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia));
    if (close_fd)
        real_close(fd);
    return rc < 0 ? -1 : 0;
}

static void emit_has_programs(int cli) {
    int found = 0;
    pthread_mutex_lock(&state_mutex);
    for (int b = 0; b < BPF_STATE_BUCKETS && !found; b++) {
        for (struct prog_entry *p = prog_table[b]; p; p = p->next) {
            if (p->kernel_prog_id) {
                found = 1;
                break;
            }
        }
    }
    pthread_mutex_unlock(&state_mutex);
    if (!found) {
        dprintf(cli, "{\"status\":\"error\",\"error\":\"no tracked BPF programs\"}\n");
        return;
    }
    dprintf(cli, "{\"status\":\"ok\"}\n");
}

static void emit_measure_start(int cli) {
    uint32_t count = 0;
    discover_bpf_programs();
    pthread_mutex_lock(&state_mutex);
    current_measure_generation++;
    if (current_measure_generation == 0)
        current_measure_generation++;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct prog_entry *p = prog_table[b]; p; p = p->next) {
            struct bpf_prog_info info;
            p->measure_generation = current_measure_generation;
            if (query_prog_info(p, &info) != 0 || info.id == 0) {
                p->measure_active = 0;
                continue;
            }
            p->measure_prog_id = info.id;
            p->measure_run_cnt = info.run_cnt;
            p->measure_run_time_ns = info.run_time_ns;
            p->measure_bytes_jited = info.jited_prog_len;
            p->measure_bytes_xlated = info.xlated_prog_len;
            p->measure_active = 1;
            count++;
        }
    }
    pthread_mutex_unlock(&state_mutex);
    if (count == 0) {
        dprintf(cli, "{\"status\":\"error\",\"error\":\"no tracked BPF programs\"}\n");
        return;
    }
    dprintf(cli, "{\"status\":\"ok\"}\n");
}

static void emit_measure_finish(int cli) {
    size_t cap = 4096, len = 0;
    char *buf = (char *)malloc(cap);
    if (!buf) {
        dprintf(cli, "{\"status\":\"error\",\"error\":\"oom\"}\n");
        return;
    }
    if (buf_appendf(&buf, &cap, &len, "{\"status\":\"ok\",\"bpf\":{") != 0)
        goto oom;

    int first = 1;
    uint32_t emitted = 0;
    pthread_mutex_lock(&state_mutex);
    uint32_t generation = current_measure_generation;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct prog_entry *p = prog_table[b]; p; p = p->next) {
            int existed_at_start = p->measure_generation == generation;
            if (existed_at_start && !p->measure_active)
                continue;
            struct bpf_prog_info info;
            if (query_prog_info(p, &info) != 0 || info.id == 0)
                continue;
            uint64_t start_run_cnt =
                existed_at_start ? p->measure_run_cnt : 0;
            uint64_t start_run_time_ns =
                existed_at_start ? p->measure_run_time_ns : 0;
            uint64_t run_cnt_delta =
                info.run_cnt >= start_run_cnt
                    ? info.run_cnt - start_run_cnt
                    : 0;
            uint64_t run_time_delta =
                info.run_time_ns >= start_run_time_ns
                    ? info.run_time_ns - start_run_time_ns
                    : 0;
            char name[sizeof(info.name) + 1];
            memcpy(name, info.name, sizeof(info.name));
            name[sizeof(info.name)] = 0;
            char name_json[64];
            json_escape_into(name, strnlen(name, sizeof(name)), name_json,
                             sizeof(name_json));
            if (buf_appendf(
                    &buf, &cap, &len,
                    "%s\"%u\":{\"id\":%u,\"name\":\"%s\",\"type\":\"%s\","
                    "\"run_cnt_delta\":%llu,\"run_time_ns_delta\":%llu,"
                    "\"bytes_jited\":%u,\"bytes_xlated\":%u}",
                    first ? "" : ",", info.id, info.id, name_json,
                    prog_type_short_name(info.type),
                    (unsigned long long)run_cnt_delta,
                    (unsigned long long)run_time_delta, info.jited_prog_len,
                    info.xlated_prog_len) != 0) {
                pthread_mutex_unlock(&state_mutex);
                goto oom;
            }
            first = 0;
            emitted++;
        }
    }
    pthread_mutex_unlock(&state_mutex);
    if (emitted == 0) {
        free(buf);
        dprintf(cli, "{\"status\":\"error\",\"error\":\"no BPF program stats\"}\n");
        return;
    }
    if (buf_appendf(&buf, &cap, &len, "}}\n") != 0)
        goto oom;
    (void)!write(cli, buf, len);
    free(buf);
    return;

oom:
    free(buf);
    dprintf(cli, "{\"status\":\"error\",\"error\":\"oom\"}\n");
}

#endif /* BPFREJIT_SHIM_MEASURE_H */
