# Tracing Corpus VM Results

- Generated: 2026-03-12T02:17:31.733946+00:00
- Driver: `corpus/run_tracing_corpus_vm.py`
- Kernel image: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage`
- Target section roots: `fentry, fexit, fmod_ret, kprobe, kretprobe, ksyscall, kretsyscall, lsm, raw_tp, raw_tracepoint, tp, tp_btf, tracepoint`
- Discovery mode: `host-preflight`
- Preview ready programs: 473
- Preview skipped programs: 251
- Layout note: Current repo layout uses corpus/build/ as the canonical object root; corpus/expanded_corpus/ and corpus/objects/ are absent in this snapshot.

## Preview Summary

| Metric | Value |
| --- | --- |
| Ready kprobe-family programs | 108 |
| Ready tracepoint-family programs | 178 |
| Ready raw_tracepoint-family programs | 50 |
| Ready lsm programs | 33 |
| Ready fentry programs | 74 |
| Ready fexit programs | 30 |

## Measured Comparison

- Generated: 2026-03-12T02:51:48.635173+00:00
- Mode: `vm-guest-isolated`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.latest.json`
- Objects discovered: 429
- Programs considered: 473
- Attached programs: 315
- Paired measurements: 167
- Paired measurements with applied v5 sites: 17
- Attach failures: 158
- Skipped programs: 0
- Zero-run programs: 148
- Speedup geomean (baseline/recompile): 1.003x
- Applied-only speedup geomean: 1.019x

## Summary Statistics

| Metric | Value |
| --- | --- |
| Inventory failures | 0 |
| Failure reason buckets | 10 |

## Paired Measurements

| Program | Section | Workload | Baseline ns | Recompile ns | Speedup | Applied | Sites | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZERO-EXT | ENDIAN | BRANCH-FLIP |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_switch | raw_tp/sched_switch | execve | 72.25 | 57.55 | 1.255x | yes | 10 | 9 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_switch | tp_btf/sched_switch | execve | 72.18 | 58.78 | 1.228x | yes | 10 | 9 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kretprobe | kretprobe/dummy_kretprobe | getpid | 65.19 | 56.42 | 1.155x | yes | 9 | 9 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:folio_mark_accessed | fentry/folio_mark_accessed | disk-io | 56.08 | 57.34 | 0.978x | yes | 8 | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv | fentry/tcp_rcv_established | tcp-loopback | 91.32 | 92.22 | 0.990x | yes | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv_kprobe | kprobe/tcp_rcv_established | tcp-loopback | 92.03 | 99.99 | 0.920x | yes | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o:kprobe_return | kretprobe/foo | getpid | 41.52 | 35.95 | 1.155x | yes | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv | fentry/tcp_v4_syn_recv_sock | tcp-loopback | 66.41 | 63.15 | 1.052x | yes | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv_kprobe | kprobe/tcp_v4_syn_recv_sock | tcp-loopback | 76.65 | 76.90 | 0.997x | yes | 5 | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o:kprobe_entry | kprobe/foo | getpid | 37.82 | 37.12 | 1.019x | yes | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o:tcp_sendmsg | kprobe/tcp_sendmsg | tcp-loopback | 399.86 | 553.16 | 0.723x | yes | 4 | 3 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_read_entry | kprobe/vfs_read | read | 112.13 | 99.66 | 1.125x | yes | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_write_entry | kprobe/vfs_write | write | 35.81 | 33.71 | 1.062x | yes | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o:tcp_cleanup_rbuf | kprobe/tcp_cleanup_rbuf | tcp-loopback | 405.64 | 418.03 | 0.970x | yes | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:exit_inet_csk_accept | kretprobe/inet_csk_accept | tcp-loopback | 175.59 | 196.16 | 0.895x | yes | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exit | tp/sched/sched_process_exit | execve | 547.50 | 594.47 | 0.921x | yes | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exit | tp/sched/sched_process_exit | execve | 620.41 | 613.61 | 1.011x | yes | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve | tracepoint/syscalls/sys_enter_execve | execve | 3251.53 | 2374.66 | 1.369x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_exit_execve | tracepoint/syscalls/sys_exit_execve | execve | 425.01 | 509.56 | 0.834x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/exitsnoop.bpf.o:sched_process_exit | tracepoint/sched/sched_process_exit | execve | 678.79 | 907.57 | 0.748x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:security_inode_create | kprobe/security_inode_create | create-unlink | 280.12 | 302.35 | 0.926x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_create | kprobe/vfs_create | create-unlink | 336.96 | 263.19 | 1.280x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_open | kprobe/vfs_open | open-close | 32.66 | 32.53 | 1.004x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink | kprobe/vfs_unlink | unlink | 40.18 | 56.78 | 0.708x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink_ret | kretprobe/vfs_unlink | unlink | 41.84 | 40.79 | 1.026x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kprobe | kprobe/dummy_kprobe | getpid | 94.39 | 74.94 | 1.259x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_enter_openat | tracepoint/syscalls/sys_enter_openat | open-close | 80.15 | 77.63 | 1.033x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_exit_openat | tracepoint/syscalls/sys_exit_openat | open-close | 44.83 | 45.09 | 0.994x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup | raw_tp/sched_wakeup | execve | 135.86 | 133.72 | 1.016x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup_new | raw_tp/sched_wakeup_new | execve | 415.61 | 430.37 | 0.966x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup | tp_btf/sched_wakeup | execve | 174.65 | 117.77 | 1.483x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup_new | tp_btf/sched_wakeup_new | execve | 485.12 | 429.41 | 1.130x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_switch | raw_tp/sched_switch | execve | 58.09 | 57.28 | 1.014x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_wakeup | raw_tp/sched_wakeup | execve | 119.69 | 121.36 | 0.986x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_wakeup_new | raw_tp/sched_wakeup_new | execve | 383.59 | 379.83 | 1.010x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_switch | tp_btf/sched_switch | execve | 57.37 | 58.36 | 0.983x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_wakeup | tp_btf/sched_wakeup | execve | 115.10 | 116.02 | 0.992x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_wakeup_new | tp_btf/sched_wakeup_new | execve | 340.66 | 409.10 | 0.833x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:kill_entry | tracepoint/syscalls/sys_enter_kill | signal | 90.08 | 78.31 | 1.150x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:kill_exit | tracepoint/syscalls/sys_exit_kill | signal | 32.53 | 31.02 | 1.049x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/slabratetop.bpf.o:kmem_cache_alloc_noprof | kprobe/kmem_cache_alloc_noprof | disk-io | 50.79 | 51.96 | 0.977x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstatat_entry | tracepoint/syscalls/sys_enter_newfstatat | stat | 68.29 | 130.23 | 0.524x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstatat_return | tracepoint/syscalls/sys_exit_newfstatat | stat | 49.87 | 50.09 | 0.996x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_fsync | tracepoint/syscalls/sys_enter_fsync | fsync | 81.82 | 80.42 | 1.017x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o:sys_enter | tracepoint/raw_syscalls/sys_enter | generic-syscalls | 98.22 | 98.51 | 0.997x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o:sys_exit | tracepoint/raw_syscalls/sys_exit | generic-syscalls | 56.06 | 53.58 | 1.046x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect | kprobe/tcp_v4_connect | tcp-loopback | 209.82 | 195.83 | 1.071x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect_ret | kretprobe/tcp_v4_connect | tcp-loopback | 50.72 | 53.84 | 0.942x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_rcv_state_process | fentry/tcp_rcv_state_process | tcp-loopback | 35.89 | 36.07 | 0.995x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_v4_connect | fentry/tcp_v4_connect | tcp-loopback | 257.12 | 153.22 | 1.678x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_destroy_sock | tracepoint/tcp/tcp_destroy_sock | tcp-loopback | 74.70 | 93.18 | 0.802x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_rcv_state_process | kprobe/tcp_rcv_state_process | tcp-loopback | 37.07 | 55.34 | 0.670x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_v4_connect | kprobe/tcp_v4_connect | tcp-loopback | 143.78 | 138.51 | 1.038x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcplife.bpf.o:inet_sock_set_state | tracepoint/sock/inet_sock_set_state | tcp-loopback | 145.45 | 150.61 | 0.966x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_destroy_sock_btf | tp_btf/tcp_destroy_sock | tcp-loopback | 190.12 | 202.40 | 0.939x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_probe_btf | tp_btf/tcp_probe | tcp-loopback | 159.36 | 154.68 | 1.030x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_rcv_space_adjust_btf | tp_btf/tcp_rcv_space_adjust | tcp-loopback | 219.10 | 214.53 | 1.021x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpstates.bpf.o:handle_set_state | tracepoint/sock/inet_sock_set_state | tcp-loopback | 175.88 | 170.39 | 1.032x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:enter_tcp_set_state | kprobe/tcp_set_state | tcp-loopback | 120.36 | 123.06 | 0.978x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:entry_trace_close | kprobe/tcp_close | tcp-loopback | 171.47 | 178.88 | 0.959x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v4_connect | kprobe/tcp_v4_connect | tcp-loopback | 128.13 | 130.96 | 0.978x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v4_connect_ret | kretprobe/tcp_v4_connect | tcp-loopback | 59.62 | 47.62 | 1.252x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_create | fentry/vfs_create | create-unlink | 45.79 | 43.95 | 1.042x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_open | fentry/vfs_open | open-close | 38.77 | 34.34 | 1.129x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_read | fentry/vfs_read | read | 37.53 | 36.66 | 1.024x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_unlink | fentry/vfs_unlink | unlink | 35.74 | 35.75 | 1.000x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_write | fentry/vfs_write | write | 32.80 | 30.71 | 1.068x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_create | kprobe/vfs_create | create-unlink | 45.73 | 45.23 | 1.011x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_open | kprobe/vfs_open | open-close | 30.07 | 30.33 | 0.991x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_read | kprobe/vfs_read | read | 39.20 | 38.35 | 1.022x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_unlink | kprobe/vfs_unlink | unlink | 38.13 | 33.10 | 1.152x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_write | kprobe/vfs_write | write | 29.21 | 29.28 | 0.998x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exec | tp/sched/sched_process_exec | execve | 997.77 | 1232.18 | 0.810x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exec | tp/sched/sched_process_exec | execve | 860.38 | 855.59 | 1.006x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o:entry_probe | ksyscall/kill | signal | 35.71 | 31.25 | 1.143x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bench_local_storage_create.bpf.o:socket_post_create | lsm.s/socket_post_create | socket-create | 30.68 | 27.30 | 1.124x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_hashmap_full_update_bench.bpf.o:benchmark | fentry/__x64_sys_getpgid | getpgid | 78.91 | 79.03 | 0.998x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop_bench.bpf.o:benchmark | fentry/__x64_sys_getpgid | getpgid | 7673.69 | 7672.89 | 1.000x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_acquire_leave_in_map | tp_btf/cgroup_mkdir | cgroup-mkdir | 41.59 | 40.05 | 1.038x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_acquire_release_argument | tp_btf/cgroup_mkdir | cgroup-mkdir | 37.20 | 39.22 | 0.948x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_from_id | tp_btf/cgroup_mkdir | cgroup-mkdir | 41.48 | 41.16 | 1.008x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_get_ancestors | tp_btf/cgroup_mkdir | cgroup-mkdir | 42.77 | 41.62 | 1.028x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_get_release | tp_btf/cgroup_mkdir | cgroup-mkdir | 41.14 | 40.82 | 1.008x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_xchg_release | tp_btf/cgroup_mkdir | cgroup-mkdir | 41.66 | 42.71 | 0.975x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_attach_cgroup.bpf.o:update_cookie_tracing | fexit/inet_stream_connect | tcp-loopback | 35.49 | 35.63 | 0.996x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_recursion.bpf.o:on_enter | tp_btf/sys_enter | generic-syscalls | 38.15 | 39.12 | 0.975x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:cgrp1_no_rcu_lock | fentry.s/__x64_sys_getpgid | getpgid | 30.41 | 30.41 | 1.000x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:yes_rcu_lock | fentry.s/__x64_sys_getpgid | getpgid | 26.02 | 26.11 | 0.997x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o:on_enter | tp_btf/sys_enter | generic-syscalls | 26.98 | 26.56 | 1.016x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o:on_exit | tp_btf/sys_exit | generic-syscalls | 26.63 | 26.20 | 1.017x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:core_relo_proto | raw_tracepoint/sys_enter | generic-syscalls | 27.35 | 26.52 | 1.032x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern_overflow.bpf.o:core_relo_proto | raw_tracepoint/sys_enter | generic-syscalls | 25.29 | 27.05 | 0.935x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/exhandler_kern.bpf.o:trace_task_newtask | tp_btf/task_newtask | execve | 47.26 | 49.76 | 0.950x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma.bpf.o:handle_getpid | raw_tp/sys_enter | generic-syscalls | 26.94 | 27.15 | 0.992x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ima.bpf.o:bprm_committed_creds | lsm.s/bprm_committed_creds | execve | 146.63 | 129.62 | 1.131x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ima.bpf.o:bprm_creds_for_exec | lsm.s/bprm_creds_for_exec | execve | 98.63 | 106.53 | 0.926x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:exec | lsm.s/bprm_committed_creds | execve | 139.13 | 142.43 | 0.977x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:socket_bind | lsm.s/socket_bind | socket-bind | 32.67 | 27.21 | 1.201x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:socket_post_create | lsm.s/socket_post_create | socket-create | 32.03 | 36.83 | 0.870x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:unlink_hook | lsm/inode_unlink | unlink | 31.30 | 42.72 | 0.733x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_bench.bpf.o:get_local | fentry/__x64_sys_getpgid | getpgid | 31205.35 | 31027.74 | 1.006x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_rcu_tasks_trace_bench.bpf.o:get_local | fentry/__x64_sys_getpgid | getpgid | 349.12 | 329.26 | 1.060x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lru_bug.bpf.o:nanosleep | fentry/do_nanosleep | nanosleep | 139.02 | 140.70 | 0.988x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_int_hook | lsm/file_mprotect | mprotect | 26.93 | 26.84 | 1.003x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_task_free | lsm/task_free | execve | 40.37 | 29.54 | 1.367x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_void_hook | lsm.s/bprm_committed_creds | execve | 2969.22 | 2542.95 | 1.168x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_tailcall.bpf.o:lsm_file_permission_prog | lsm/file_permission | read | 27.84 | 28.20 | 0.987x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_nested_offset | tp_btf/task_newtask | execve | 61.94 | 60.51 | 1.024x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_read_cpumask | tp_btf/task_newtask | execve | 36.83 | 43.42 | 0.848x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_skb_field | tp_btf/tcp_probe | tcp-loopback | 31.39 | 31.03 | 1.012x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/security_bpf_map.bpf.o:fmod_bpf_map | fmod_ret/security_bpf_map | bpf-map-show | 101.91 | 109.34 | 0.932x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/socket_cookie_prog.bpf.o:update_cookie_tracing | fexit/inet_stream_connect | tcp-loopback | 35.27 | 36.03 | 0.979x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map.bpf.o:oncpu | tracepoint/sched/sched_switch | execve | 1223.59 | 1526.05 | 0.802x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map_skip.bpf.o:oncpu | tracepoint/sched/sched_switch | execve | 415.30 | 419.68 | 0.990x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o:on_enter | tp_btf/sys_enter | generic-syscalls | 27.34 | 25.48 | 1.073x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o:on_exit | tp_btf/sys_exit | generic-syscalls | 26.19 | 26.77 | 0.978x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_recursion.bpf.o:on_enter | tp_btf/sys_enter | generic-syscalls | 25.79 | 26.49 | 0.974x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_uptr.bpf.o:on_enter | tp_btf/sys_enter | generic-syscalls | 28.57 | 26.49 | 1.079x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o:prog1 | raw_tp/sys_enter | generic-syscalls | 25.26 | 25.02 | 1.010x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o:prog2 | raw_tp/sys_exit | generic-syscalls | 26.49 | 26.69 | 0.992x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog1 | raw_tp/sys_enter | generic-syscalls | 24.02 | 25.55 | 0.940x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog2 | raw_tp/sys_exit | generic-syscalls | 26.64 | 27.14 | 0.982x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_raw_tp | raw_tp/sys_enter | generic-syscalls | 26.63 | 26.02 | 1.024x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp_btf | tp_btf/sys_enter | generic-syscalls | 26.19 | 26.12 | 1.003x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:test_int_hook | lsm/file_mprotect | mprotect | 42.14 | 34.86 | 1.209x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:lsm_run | lsm/bpf | bpf-show | 49.07 | 51.46 | 0.954x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:lsm_s_run | lsm.s/bpf | bpf-show | 48.76 | 46.16 | 1.056x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_read_macros.bpf.o:handler | raw_tracepoint/sys_enter | generic-syscalls | 24.94 | 24.85 | 1.003x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o:prog_stat | fentry/security_inode_getattr | stat | 26.44 | 30.73 | 0.861x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o:sys_enter | raw_tp/sys_enter | generic-syscalls | 28.45 | 27.21 | 1.045x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kernel_flag.bpf.o:bpf | lsm.s/bpf | bpf-show | 67.44 | 64.84 | 1.040x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o:dynptr_data_null | lsm.s/bpf | bpf-show | 51.57 | 49.35 | 1.045x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf.bpf.o:handler | raw_tp/sys_enter | generic-syscalls | 32.79 | 31.36 | 1.045x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:map_val_prog | raw_tp/sys_enter | generic-syscalls | 26.26 | 27.31 | 0.961x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:rdonly_map_prog | raw_tp/sys_enter | generic-syscalls | 25.52 | 25.93 | 0.984x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_libbpf_get_fd_by_id_opts.bpf.o:check_access | lsm/bpf_map | bpf-map-show | 63.00 | 63.63 | 0.990x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_lookup_and_delete.bpf.o:bpf_lookup_and_delete_test | tp/syscalls/sys_enter_getpgid | getpgid | 24.45 | 24.43 | 1.001x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_init.bpf.o:sysenter_getpgid | tp/syscalls/sys_enter_getpgid | getpgid | 24.39 | 28.43 | 0.858x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_lookup_percpu_elem.bpf.o:sysenter_getuid | tp/syscalls/sys_enter_getuid | getuid | 24.96 | 28.86 | 0.865x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_for_each_fail | tp/syscalls/sys_enter_getpgid | getpgid | 24.68 | 28.45 | 0.867x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_push | tp/syscalls/sys_enter_getuid | getuid | 27.96 | 27.96 | 1.000x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_update | tp/syscalls/sys_enter_getpid | getpid | 24.78 | 24.76 | 1.001x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog1 | kprobe/__set_task_comm | prctl-set-name | 25.99 | 26.22 | 0.991x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog2 | kretprobe/__set_task_comm | prctl-set-name | 32.29 | 32.49 | 0.994x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog4 | fentry/__set_task_comm | prctl-set-name | 30.74 | 33.20 | 0.926x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog5 | fexit/__set_task_comm | prctl-set-name | 29.34 | 29.28 | 1.002x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o:tailcall_1 | raw_tp/sys_enter | generic-syscalls | 27.28 | 26.74 | 1.020x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ptr_untrusted.bpf.o:lsm_run | lsm.s/bpf | bpf-show | 34.02 | 33.48 | 1.016x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o:send_signal_tp_sched | tracepoint/sched/sched_switch | execve | 29.21 | 29.58 | 0.988x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:inet_csk_accept | fexit/inet_csk_accept | tcp-loopback | 323.90 | 356.31 | 0.909x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_inet_sock_set_state | tp_btf/inet_sock_set_state | tcp-loopback | 131.77 | 135.72 | 0.971x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_tcp_connect | fentry/tcp_connect | tcp-loopback | 268.83 | 265.27 | 1.013x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog1 | raw_tp/sys_enter | generic-syscalls | 34.31 | 33.56 | 1.022x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog2 | raw_tp/sys_exit | generic-syscalls | 42.31 | 41.72 | 1.014x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog3 | raw_tp/sys_enter | generic-syscalls | 40.61 | 39.92 | 1.017x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog4 | raw_tp/sys_exit | generic-syscalls | 42.12 | 42.36 | 0.994x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_unused.bpf.o:main_prog | raw_tp/sys_enter | generic-syscalls | 25.74 | 26.79 | 0.961x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_under_cgroup.bpf.o:lsm_run | lsm.s/bpf | bpf-show | 59.69 | 56.24 | 1.061x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_under_cgroup.bpf.o:tp_btf_run | tp_btf/task_newtask | execve | 88.36 | 70.47 | 1.254x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tracepoint.bpf.o:oncpu | tracepoint/sched/sched_switch | execve | 26.83 | 28.15 | 0.953x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_signed | tp/raw_syscalls/sys_exit | generic-syscalls | 26.76 | 30.40 | 0.880x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_unsigned | tp/raw_syscalls/sys_enter | generic-syscalls | 27.01 | 27.07 | 0.998x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_signed | raw_tp/sys_exit | generic-syscalls | 27.41 | 27.66 | 0.991x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_unsigned | raw_tp/sys_enter | generic-syscalls | 27.61 | 26.64 | 1.036x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler_exit | tp/syscalls/sys_exit_getpid | getpid | 35.55 | 35.52 | 1.001x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_crash.bpf.o:sys_enter | fentry/do_nanosleep | nanosleep | 30.79 | 28.32 | 1.087x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test1 | lsm/file_permission | read | 33.88 | 25.06 | 1.352x | no | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

## Attach Or Measurement Failures

| Program | Section | Workload | Failure |
| --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:blk_account_io_start | fentry/blk_account_io_start | disk-io | attach failed: Device or resource busy |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_start | fentry/blk_account_io_start | disk-io | attach failed: Device or resource busy |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_done | fentry/blk_account_io_done | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_account_io_start | kprobe/blk_account_io_start | disk-io | attach failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_account_io_done | kprobe/blk_account_io_done | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:__blk_account_io_start | kprobe/__blk_account_io_start | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:__blk_account_io_done | kprobe/__blk_account_io_done | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:fentry_account_page_dirtied | fentry/account_page_dirtied | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_account_page_dirtied | kprobe/account_page_dirtied | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_folio_account_dirtied | kprobe/folio_account_dirtied | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/cpudist.bpf.o:sched_switch_btf | tp_btf/sched_switch | execve | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/cpudist.bpf.o:sched_switch_tp | raw_tp/sched_switch | execve | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_fentry | fentry/dummy_fentry | getpid | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_fexit | fexit/dummy_fexit | getpid | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/futexctn.bpf.o:futex_enter | tracepoint/syscalls/sys_enter_futex | futex | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/futexctn.bpf.o:futex_exit | tracepoint/syscalls/sys_exit_futex | futex | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_nested | kprobe/down_read_nested | read | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_exit_nested | kretprobe/down_read_nested | read | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable_nested | kprobe/down_read_killable_nested | read | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable_exit_nested | kretprobe/down_read_killable_nested | read | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_nested | kprobe/down_write_nested | write | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_exit_nested | kretprobe/down_write_nested | write | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_killable_nested | kprobe/down_write_killable_nested | write | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_killable_exit_nested | kretprobe/down_write_killable_nested | write | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmem_cache_alloc | tracepoint/kmem/kmem_cache_alloc | disk-io | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmem_cache_free | tracepoint/kmem/kmem_cache_free | disk-io | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__mm_page_alloc | tracepoint/kmem/mm_page_alloc | disk-io | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__mm_page_free | tracepoint/kmem/mm_page_free | disk-io | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fentry_migrate_misplaced_page | fentry/migrate_misplaced_page | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fentry_migrate_misplaced_folio | fentry/migrate_misplaced_folio | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kprobe_migrate_misplaced_page | kprobe/migrate_misplaced_page | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kprobe_migrate_misplaced_folio | kprobe/migrate_misplaced_folio | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fexit_migrate_misplaced_page_exit | fexit/migrate_misplaced_page | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fexit_migrate_misplaced_folio_exit | fexit/migrate_misplaced_folio | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kretprobe_migrate_misplaced_page_exit | kretprobe/migrate_misplaced_page | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kretprobe_migrate_misplaced_folio_exit | kretprobe/migrate_misplaced_folio | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/offcputime.bpf.o:sched_switch | tp_btf/sched_switch | execve | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/offcputime.bpf.o:sched_switch_raw | raw_tp/sched_switch | execve | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:page_cache_alloc_ret | fexit/__page_cache_alloc | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:filemap_alloc_folio_ret | fexit/filemap_alloc_folio | disk-io | bpf_program__set_attach_target failed: No such process |
| corpus/build/bcc/libbpf-tools/slabratetop.bpf.o:kmem_cache_alloc | kprobe/kmem_cache_alloc | disk-io | attach failed: No such file or directory |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_probe | raw_tp/tcp_probe | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_rcv_space_adjust | raw_tp/tcp_rcv_space_adjust | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_destroy_sock | raw_tp/tcp_destroy_sock | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/wakeuptime.bpf.o:sched_switch | tp_btf/sched_switch | execve | bpf_object__load failed: Invalid argument |
| corpus/build/bcc/libbpf-tools/wakeuptime.bpf.o:sched_wakeup | tp_btf/sched_wakeup | execve | bpf_object__load failed: Invalid argument |
| corpus/build/libbpf-bootstrap/examples/c/lsm.bpf.o:lsm_bpf | lsm/bpf | bpf-show | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_hashmap_lookup.bpf.o:benchmark | fentry/__x64_sys_getpgid | getpgid | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_untrusted | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_no_null_check | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_fp | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_trusted_walked | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_null | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_unreleased | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_xchg_unreleased | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_rcu_get_release | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_untrusted | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_fp | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_null | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_unacquired | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_negative.bpf.o:on_enter | tp_btf/sys_enter | generic-syscalls | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:no_rcu_lock | fentry.s/__x64_sys_getpgid | getpgid | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_alloc_no_release | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_alloc_double_release | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_acquire_wrong_cpumask | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_mutate_cpumask | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_insert_remove_no_release | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_cpumask_null | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_global_mask_out_of_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_global_mask_no_null_check | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_global_mask_rcu_no_null_check | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_invalid_nested_array | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_populate_invalid_destination | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_populate_invalid_source | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_alloc_free_cpumask | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_set_clear_cpu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_setall_clear_cpu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_first_firstzero_cpu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_firstand_nocpu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_test_and_set_clear | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_and_or_xor | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_intersects_subset | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_copy_any_anyand | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_insert_leave | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_insert_remove_release | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_array_one_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_array_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_array_l2_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_deep_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_deep_array_rcu | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_cpumask_weight | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_refcount_null_tracking | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate_reject_small_mask | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate_reject_unaligned | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma_fail1.bpf.o:handle_getpid | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma_fail2.bpf.o:handle_getpid | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_map_elem_write_key.bpf.o:test_map_key_write | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_empty | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_full | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_truncated | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop2.bpf.o:while_true | raw_tracepoint/consume_skb | tcp-loopback | attach failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop3.bpf.o:while_true | raw_tracepoint/consume_skb | tcp-loopback | bpf_object__load failed: Argument list too long |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_cgrp_map_kptr | tp_btf/cgroup_mkdir | cgroup-mkdir | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_task_map_kptr | lsm/inode_unlink | unlink | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_inode_map_kptr | lsm/inode_unlink | unlink | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:test_sk_ls_leak | tp_btf/inet_sock_set_state | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:map_put | fentry/bpf_map_put | bpf-map-show | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:sk_map_free | fexit/bpf_sk_storage_map_free | bpf-map-show | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcpify.bpf.o:mptcpify | fmod_ret/update_socket_protocol | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_acquire.bpf.o:test_nested_acquire_nonzero | tp_btf/tcp_probe | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_acquire.bpf.o:test_nested_acquire_zero | tp_btf/tcp_probe | tcp-loopback | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_failure.bpf.o:test_invalid_nested_user_cpus | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_failure.bpf.o:test_invalid_skb_field | tp_btf/tcp_probe | tcp-loopback | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog_fail.bpf.o:trace_tcp_destroy_sock | tp_btf/tcp_destroy_sock | tcp-loopback | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o:rawtp_test | raw_tp/bpf_testmod_test_read | read | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_untrusted | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_fp | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_null | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_unreleased | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_xchg_unreleased | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_release_no_null_check | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_untrusted | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_fp | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_null | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_unacquired | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_from_pid_no_null_check | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_from_vpid_no_null_check | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm1 | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm2 | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm3 | tp_btf/task_newtask | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_in_map | tp_btf/task_newtask | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_unsafe_kretprobe | kretprobe/free_task | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_unsafe_kretprobe_rcu | kretprobe/free_task | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_from_lsm_task_free | lsm/task_free | execve | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm4 | fentry/__set_task_comm | prctl-set-name | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_storage_nodeadlock.bpf.o:socket_post_create | lsm.s/socket_post_create | socket-create | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_reloc_module.bpf.o:test_core_module_probed | raw_tp/bpf_testmod_test_read | read | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_reloc_module.bpf.o:test_core_module_direct | tp_btf/bpf_testmod_test_read | read | bpf_program__set_attach_target failed: No such process |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_rdonly_mem.bpf.o:d_path_check_rdonly_mem | fentry/security_inode_getattr | stat | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_types.bpf.o:d_path_check_rdonly_mem | fentry/security_inode_getattr | stat | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_map_resize.bpf.o:bss_array_sum | tp/syscalls/sys_enter_getpid | getpid | subprocess exit -11 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_map_resize.bpf.o:data_array_sum | tp/syscalls/sys_enter_getuid | getuid | subprocess exit -11 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o:not_valid_dynptr | lsm.s/bpf | bpf-show | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o:not_ptr_to_stack | lsm.s/bpf | bpf-show | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_null_check.bpf.o:handler | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_write_check.bpf.o:handler1 | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_write_check.bpf.o:handler2 | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_weak.bpf.o:pass_handler | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o:entry | raw_tp/sys_enter | generic-syscalls | bpf_object__load failed: Bad file descriptor |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_failure.bpf.o:tracing_deny | fentry/__rcu_read_lock | read | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:bprm | lsm.s/bprm_committed_creds | execve | bpf_object__load failed: Permission denied |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test2 | lsm/file_permission | read | [Errno 4095] Unknown error 4095 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test4 | lsm/file_mprotect | mprotect | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test5 | lsm/file_mprotect | mprotect | bpf_object__load failed: Invalid argument |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test6 | lsm/file_mprotect | mprotect | bpf_object__load failed: Invalid argument |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| [Errno 4095] Unknown error 4095 | 1 |
| attach failed: Device or resource busy | 2 |
| attach failed: Invalid argument | 2 |
| attach failed: No such file or directory | 18 |
| bpf_object__load failed: Argument list too long | 1 |
| bpf_object__load failed: Bad file descriptor | 1 |
| bpf_object__load failed: Invalid argument | 84 |
| bpf_object__load failed: Permission denied | 36 |
| bpf_program__set_attach_target failed: No such process | 11 |
| subprocess exit -11 | 2 |

## Notes

- Each attached program is measured twice in one load session: baseline workload, then `scanner apply --all --v5`, then post-recompile workload.
- Average exec time is derived from `bpf_prog_info.run_time_ns / run_cnt` deltas around each workload phase.
- Programs that can be loaded but not matched to an attach target or workload are recorded with explicit skip reasons.
