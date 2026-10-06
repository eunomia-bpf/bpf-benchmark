# Corpus BPF Runtime Performance Results

- Generated: 2026-03-10T20:43:53.392907+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Dummy packet: `/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/corpus_dummy_packet_64.bin`
- Dummy context: `/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/corpus_dummy_context_64.bin`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.json`
- Corpus BPF objects discovered: 429
- Skipped non-BPF `.bpf.o` artifacts: 0
- Programs found: 1259
- Loadable programs: 856
- Baseline-runnable programs: 273
- Recompile-runnable programs: 273
- Paired baseline/recompile measurements: 273
- Directive-bearing loadable programs: 80
- Directive-bearing paired programs: 29
- Correctness mismatches: 0
- Speedup geomean (baseline/recompile): 1.002x
- Speedup median (baseline/recompile): 1.013x

## Summary Statistics

| Metric | Value |
| --- | --- |
| CMOV sites | 182 |
| WIDE sites | 7 |
| ROTATE sites | 1810 |
| LEA sites | 0 |
| Speedup min | 0.345x |
| Speedup max | 3.058x |

## Runnable Programs

| Program | Section | Baseline ns | Recompile ns | Speedup | Applied | Correct | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_complete | raw_tp/block_rq_complete | 4411 | 5937 | 0.743x | no | match | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_insert | raw_tp/block_rq_insert | 5011 | 4743 | 1.057x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue | raw_tp/block_rq_issue | 7015 | 6066 | 1.156x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:blk_account_io_start | fentry/blk_account_io_start | 2166 | 2612 | 0.829x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_start | fentry/blk_account_io_start | 2739 | 1710 | 1.602x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:fentry_add_to_page_cache_lru | fentry/add_to_page_cache_lru | 3831 | 1996 | 1.919x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:fentry_mark_buffer_dirty | fentry/mark_buffer_dirty | 2244 | 2264 | 0.991x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:fentry_mark_page_accessed | fentry/mark_page_accessed | 2521 | 2907 | 0.867x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/drsnoop.bpf.o:direct_reclaim_begin | raw_tp/mm_vmscan_direct_reclaim_begin | 7232 | 5632 | 1.284x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/drsnoop.bpf.o:direct_reclaim_end | raw_tp/mm_vmscan_direct_reclaim_end | 5425 | 4708 | 1.152x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o:irq_handler_entry | raw_tp/irq_handler_entry | 6091 | 2769 | 2.200x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o:irq_handler_exit | raw_tp/irq_handler_exit | 4677 | 8591 | 0.544x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read | fentry/down_read | 2145 | 2699 | 0.795x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_exit | fexit/down_read | 2147 | 3291 | 0.652x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_interruptible | fentry/down_read_interruptible | 2920 | 2151 | 1.358x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_interruptible_exit | fexit/down_read_interruptible | 5738 | 2857 | 2.008x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_killable | fentry/down_read_killable | 2693 | 3012 | 0.894x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_killable_exit | fexit/down_read_killable | 3086 | 2073 | 1.489x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_read_trylock_exit | fexit/down_read_trylock | 6965 | 2278 | 3.058x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_write | fentry/down_write | 1923 | 2810 | 0.684x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_write_exit | fexit/down_write | 2679 | 2958 | 0.906x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_write_killable | fentry/down_write_killable | 1936 | 3655 | 0.530x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_write_killable_exit | fexit/down_write_killable | 2110 | 3081 | 0.685x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:down_write_trylock_exit | fexit/down_write_trylock | 2117 | 3043 | 0.696x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_lock | fentry/mutex_lock | 2656 | 2425 | 1.095x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_lock_exit | fexit/mutex_lock | 3127 | 2260 | 1.384x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_lock_interruptible | fentry/mutex_lock_interruptible | 2715 | 2741 | 0.991x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_lock_interruptible_exit | fexit/mutex_lock_interruptible | 2243 | 2080 | 1.078x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_lock_killable | fentry/mutex_lock_killable | 2287 | 2946 | 0.776x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_lock_killable_exit | fexit/mutex_lock_killable | 2652 | 2477 | 1.071x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_trylock_exit | fexit/mutex_trylock | 3145 | 3126 | 1.006x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:mutex_unlock | fentry/mutex_unlock | 2077 | 2235 | 0.929x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:netlink_dump | fentry/netlink_dump | 4071 | 2189 | 1.860x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:netlink_dump_exit | fexit/netlink_dump | 2852 | 2591 | 1.101x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:rtnetlink_rcv_msg | fentry/rtnetlink_rcv_msg | 3006 | 2279 | 1.319x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:rtnetlink_rcv_msg_exit | fexit/rtnetlink_rcv_msg | 2451 | 3119 | 0.786x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:sock_do_ioctl | fentry/sock_do_ioctl | 2673 | 3303 | 0.809x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:sock_do_ioctl_exit | fexit/sock_do_ioctl | 2284 | 2111 | 1.082x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:up_read | fentry/up_read | 2936 | 3066 | 0.958x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:up_write | fentry/up_write | 2993 | 2724 | 1.099x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/mdflush.bpf.o:md_flush_request | fentry/md_flush_request | 2126 | 1899 | 1.120x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fentry_migrate_misplaced_folio | fentry/migrate_misplaced_folio | 2377 | 2546 | 0.934x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fexit_migrate_misplaced_folio_exit | fexit/migrate_misplaced_folio | 2182 | 1975 | 1.105x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:filemap_alloc_folio_noprof_ret | fexit/filemap_alloc_folio_noprof | 2315 | 3945 | 0.587x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:folio_mark_accessed | fentry/folio_mark_accessed | 3510 | 2057 | 1.706x | no | match | 5 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:mark_page_accessed | fentry/mark_page_accessed | 2266 | 1687 | 1.343x | no | match | 5 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_switch | raw_tp/sched_switch | 4514 | 3937 | 1.147x | no | match | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup | raw_tp/sched_wakeup | 3673 | 6114 | 0.601x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup_new | raw_tp/sched_wakeup_new | 4752 | 3412 | 1.393x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_switch | raw_tp/sched_switch | 3493 | 3804 | 0.918x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_wakeup | raw_tp/sched_wakeup | 4126 | 4909 | 0.840x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:handle_sched_wakeup_new | raw_tp/sched_wakeup_new | 3350 | 3222 | 1.040x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o:softirq_entry | raw_tp/softirq_entry | 4575 | 4223 | 1.083x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/solisten.bpf.o:inet_listen_fexit | fexit/inet_listen | 2084 | 1455 | 1.432x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_rcv_state_process | fentry/tcp_rcv_state_process | 3170 | 2226 | 1.424x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_v4_connect | fentry/tcp_v4_connect | 3583 | 3648 | 0.982x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_v6_connect | fentry/tcp_v6_connect | 1973 | 2011 | 0.981x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv | fentry/tcp_rcv_established | 2744 | 1843 | 1.489x | no | match | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv | fentry/tcp_v4_syn_recv_sock | 2131 | 1745 | 1.221x | no | match | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v6_syn_recv | fentry/tcp_v6_syn_recv_sock | 2587 | 1781 | 1.453x | no | match | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_create | fentry/vfs_create | 3616 | 3037 | 1.191x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_fsync | fentry/vfs_fsync | 3431 | 2022 | 1.697x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_mkdir | fentry/vfs_mkdir | 2678 | 2001 | 1.338x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_open | fentry/vfs_open | 1896 | 3980 | 0.476x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_read | fentry/vfs_read | 2146 | 2572 | 0.834x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_rmdir | fentry/vfs_rmdir | 2371 | 2084 | 1.138x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_unlink | fentry/vfs_unlink | 2693 | 2292 | 1.175x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:fentry_vfs_write | fentry/vfs_write | 2801 | 3898 | 0.719x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat | fentry/do_unlinkat | 3353 | 2731 | 1.228x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat_exit | fexit/do_unlinkat | 2308 | 2533 | 0.911x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | tc | 8 | 9 | 0.889x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_htab.bpf.o:arena_htab_llvm | syscall | 3070 | 3316 | 0.926x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_htab_asm.bpf.o:arena_htab_asm | syscall | 52405900 | 52674758 | 0.995x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_list.bpf.o:arena_list_add | syscall | 2250 | 1885 | 1.194x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/arena_list.bpf.o:arena_list_del | syscall | 1769 | 4075 | 0.434x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bench_local_storage_create.bpf.o:kmalloc | raw_tp/kmalloc | 4566 | 3437 | 1.328x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:big_jump_table | syscall | 1843 | 2138 | 0.862x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:one_jump_two_maps | syscall | 1805 | 3327 | 0.543x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:one_map_two_jumps | syscall | 2671 | 1847 | 1.446x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:one_switch | syscall | 1619 | 3353 | 0.483x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:one_switch_non_zero_sec_off | syscall | 1751 | 1699 | 1.031x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:simple_test_other_sec | syscall | 1869 | 1919 | 0.974x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:two_switches | syscall | 1415 | 1491 | 0.949x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:use_nonstatic_global1 | syscall | 3253 | 2830 | 1.149x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:use_nonstatic_global2 | syscall | 1917 | 3498 | 0.548x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:use_nonstatic_global_other_sec | syscall | 1510 | 1952 | 0.774x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:use_static_global1 | syscall | 2235 | 1679 | 1.331x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:use_static_global2 | syscall | 3094 | 2611 | 1.185x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_gotox.bpf.o:use_static_global_other_sec | syscall | 2206 | 2793 | 0.790x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_hashmap_full_update_bench.bpf.o:benchmark | fentry/__x64_sys_getpgid | 3153 | 2013 | 1.566x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o:prog_invalid_flags | fentry/__x64_sys_nanosleep | 2617 | 2030 | 1.289x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o:prog_nested_calls | fentry/__x64_sys_nanosleep | 3050 | 3663 | 0.833x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o:prog_non_constant_callback | fentry/__x64_sys_nanosleep | 3342 | 2650 | 1.261x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o:prog_null_ctx | fentry/__x64_sys_nanosleep | 4563 | 3234 | 1.411x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o:stack_check | fentry/__x64_sys_nanosleep | 3053 | 1971 | 1.549x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop.bpf.o:test_prog | fentry/__x64_sys_nanosleep | 2646 | 2418 | 1.094x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_loop_bench.bpf.o:benchmark | fentry/__x64_sys_getpgid | 2695 | 2620 | 1.029x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o:fexit_init_module | fexit/do_init_module | 2422 | 3340 | 0.725x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o:fexit_module_get | fexit/btf_try_get_module | 1633 | 2846 | 0.574x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o:widen_race | fmod_ret.s/bpf_fentry_test1 | 1770 | 2297 | 0.771x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_type_tag.bpf.o:sub | fentry/bpf_fentry_test1 | 3231 | 1856 | 1.741x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_ancestor.bpf.o:log_cgroup_id | tc | 9 | 19 | 0.474x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_from_id_ns | syscall | 3989 | 3231 | 1.235x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_attach_cgroup.bpf.o:update_cookie_tracing | fexit/inet_stream_connect | 3011 | 2521 | 1.194x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_recursion.bpf.o:on_update | fentry/bpf_local_storage_update | 2952 | 2628 | 1.123x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:cgrp1_no_rcu_lock | fentry.s/__x64_sys_getpgid | 2022 | 3017 | 0.670x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:yes_rcu_lock | fentry.s/__x64_sys_getpgid | 2031 | 2520 | 0.806x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:balancer_ingress | tc | 593 | 502 | 1.181x | no | match | 0 | 0 | 818 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:core_relo_proto | raw_tracepoint/sys_enter | 3804 | 6750 | 0.564x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:fentry_eth_type_trans | fentry/eth_type_trans | 2691 | 3097 | 0.869x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:fexit_eth_type_trans | fexit/eth_type_trans | 2566 | 1865 | 1.376x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern_overflow.bpf.o:core_relo_proto | raw_tracepoint/sys_enter | 4428 | 5108 | 0.867x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o:decap_sanity | tc | 9 | 10 | 0.900x | no | match | 2 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/fexit_sleep.bpf.o:nanosleep_fentry | fentry/__x64_sys_nanosleep | 2030 | 2573 | 0.789x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/fexit_sleep.bpf.o:nanosleep_fexit | fexit/__x64_sys_nanosleep | 3543 | 5490 | 0.645x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma.bpf.o:handle_getpid | raw_tp/sys_enter | 4743 | 3680 | 1.289x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_array_map_elem.bpf.o:test_pkt_access | tc | 47 | 47 | 1.000x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_map_elem.bpf.o:test_pkt_access | tc | 24 | 27 | 0.889x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_hash_modify.bpf.o:test_pkt_access | tc | 484 | 339 | 1.428x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_multi_maps.bpf.o:test_pkt_access | tc | 38 | 35 | 1.086x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_bench.bpf.o:get_local | fentry/__x64_sys_getpgid | 3568 | 2825 | 1.263x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_rcu_tasks_trace_bench.bpf.o:get_local | fentry/__x64_sys_getpgid | 2650 | 3132 | 0.846x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_rcu_tasks_trace_bench.bpf.o:postgp | fentry/rcu_tasks_trace_postgp | 2767 | 2596 | 1.066x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage_rcu_tasks_trace_bench.bpf.o:pregp_step | fentry/rcu_tasks_trace_pregp_step | 2697 | 3200 | 0.843x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lru_bug.bpf.o:nanosleep | fentry/do_nanosleep | 3449 | 3408 | 1.012x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lru_bug.bpf.o:printk | fentry/bpf_ktime_get_ns | 1987 | 1760 | 1.129x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_sys_setdomainname | fentry.s/__x64_sys_setdomainname | 4022 | 3507 | 1.147x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_tp_recursion.bpf.o:trigger | fentry/bpf_modify_return_test | 3000 | 2182 | 1.375x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mmap_inner_array.bpf.o:add_to_list_in_inner_array | fentry/__x64_sys_nanosleep | 2689 | 2470 | 1.089x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sock.bpf.o:trace_mptcp_pm_new_connection | fentry/mptcp_pm_new_connection | 2249 | 3061 | 0.735x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcpify.bpf.o:mptcpify | fmod_ret/update_socket_protocol | 2469 | 1962 | 1.258x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_prog.bpf.o:xdp_prog1 | xdp | 18 | 8 | 2.250x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/recursion.bpf.o:on_delete | fentry/htab_map_delete_elem | 3495 | 3398 | 1.029x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test | tc | 1880868 | 1878243 | 1.001x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_AB | tc | 27 | 56 | 0.482x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_BA | tc | 29 | 28 | 1.036x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o:res_spin_lock_test_held_lock_max | tc | 250563943 | 250578962 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/security_bpf_map.bpf.o:fentry_dummy1 | fentry/bpf_fentry_test1 | 2740 | 1968 | 1.392x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/security_bpf_map.bpf.o:fmod_bpf_map | fmod_ret/security_bpf_map | 1913 | 1651 | 1.159x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sk_storage_omem_uncharge.bpf.o:bpf_sk_storage_free | fexit/bpf_sk_storage_free | 2060 | 2201 | 0.936x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sk_storage_omem_uncharge.bpf.o:inet6_sock_destruct | fentry/inet6_sock_destruct | 2136 | 2424 | 0.881x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/skb_pkt_end.bpf.o:main_prog | tc | 8 | 17 | 0.471x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/socket_cookie_prog.bpf.o:update_cookie_tracing | fexit/inet_stream_connect | 3481 | 2421 | 1.438x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o:rawtp_test | raw_tp/bpf_testmod_test_read | 7053 | 10311 | 0.684x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes | tc | 10 | 11 | 0.909x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_changes_with_subprogs | tc | 12 | 25 | 0.480x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_change | tc | 17 | 17 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage_exit_creds.bpf.o:trace_exit_creds | fentry/exit_creds | 2888 | 2560 | 1.128x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_recursion.bpf.o:on_update | fentry/bpf_local_storage_update | 1743 | 2452 | 0.711x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_access_variable_array.bpf.o:fentry_fentry | fentry/sched_balance_rq | 2604 | 2509 | 1.038x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o:prog1 | raw_tp/sys_enter | 3074 | 2303 | 1.335x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoattach.bpf.o:prog2 | raw_tp/sys_exit | 2392 | 4669 | 0.512x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog1 | raw_tp/sys_enter | 4315 | 3840 | 1.124x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog2 | raw_tp/sys_exit | 5304 | 2707 | 1.959x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:fentry_test1 | fentry/bpf_fentry_test1 | 2321 | 3039 | 0.764x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:fexit_test1 | fexit/bpf_fentry_test1 | 4043 | 3014 | 1.341x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:fmod_ret_test | fmod_ret/bpf_modify_return_test | 2347 | 3825 | 0.614x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_raw_tp | raw_tp/sys_enter | 5313 | 6466 | 0.822x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_tuple | tc | 11 | 14 | 0.786x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_tuple | xdp | 23 | 22 | 1.045x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_decl_tag.bpf.o:sub | fentry/bpf_fentry_test1 | 1996 | 2010 | 0.993x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o:cls_ingress | tc | 9 | 9 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_read_macros.bpf.o:handler | raw_tracepoint/sys_enter | 4147 | 5508 | 0.753x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o:prog_close | fentry/filp_close | 2984 | 1961 | 1.522x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o:prog_fallocate | fentry/vfs_fallocate | 3246 | 2022 | 1.605x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o:prog_stat | fentry/security_inode_getattr | 1755 | 2750 | 0.638x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o:sys_enter | raw_tp/sys_enter | 2559 | 3466 | 0.738x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:arg_tag_ctx_raw_tp | raw_tp | 7413 | 6194 | 1.197x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:raw_tp_ctx | raw_tp | 7743 | 10528 | 0.735x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:raw_tp_writable_ctx | raw_tp | 9847 | 7880 | 1.250x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf.bpf.o:handler | raw_tp/sys_enter | 3197 | 2667 | 1.199x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_tc | tc | 19 | 19 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:map_val_prog | raw_tp/sys_enter | 3980 | 2708 | 1.470x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:rdonly_map_prog | raw_tp/sys_enter | 3434 | 2881 | 1.192x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog3 | raw_tp/task_rename | 2944 | 2613 | 1.127x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog4 | fentry/__set_task_comm | 2790 | 2510 | 1.112x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog5 | fexit/__set_task_comm | 2122 | 2235 | 0.949x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o:tailcall_1 | raw_tp/sys_enter | 3179 | 3147 | 1.010x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ptr_untrusted.bpf.o:raw_tp_run | raw_tracepoint | 3312 | 4008 | 0.826x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_raw_tp_test_run.bpf.o:rename | raw_tp/task_rename | 4203 | 2466 | 1.704x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:inet_csk_accept | fexit/inet_csk_accept | 3475 | 3147 | 1.104x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_inet_csk_listen_start | fentry/inet_csk_listen_start | 2823 | 2627 | 1.075x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_tcp_connect | fentry/tcp_connect | 2687 | 1855 | 1.449x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o:test_skb_helpers | tc | 51 | 27 | 1.889x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skc_to_unix_sock.bpf.o:unix_listen | fentry/unix_listen | 2196 | 3213 | 0.683x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_update.bpf.o:copy_sock_map | tc | 11 | 21 | 0.524x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog1 | raw_tp/sys_enter | 4775 | 4714 | 1.013x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog2 | raw_tp/sys_exit | 4938 | 4662 | 1.059x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog3 | raw_tp/sys_enter | 4291 | 3289 | 1.305x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o:prog4 | raw_tp/sys_exit | 4677 | 3594 | 1.301x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_unused.bpf.o:main_prog | raw_tp/sys_enter | 2930 | 2463 | 1.190x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_local_data.bpf.o:task_main | syscall | 2211 | 2289 | 0.966x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | tc/ingress | 11 | 24 | 0.458x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_eth | tc | 18 | 8 | 2.250x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_mpls | tc | 8 | 19 | 0.421x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_gre_none | tc | 9 | 9 | 1.000x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_eth | tc | 8 | 17 | 0.471x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_mpls | tc | 8 | 8 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6gre_none | tc | 8 | 8 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6tnl_none | tc | 9 | 8 | 1.125x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_eth | tc | 8 | 18 | 0.444x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_mpls | tc | 18 | 18 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6udp_none | tc | 8 | 18 | 0.444x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ip6vxlan_eth | tc | 9 | 18 | 0.500x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip6_none | tc | 8 | 18 | 0.444x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_ipip_none | tc | 9 | 9 | 1.000x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_sit_none | tc | 8 | 8 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_eth | tc | 9 | 8 | 1.125x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_mpls | tc | 18 | 18 | 1.000x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_udp_none | tc | 18 | 17 | 1.059x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:__encap_vxlan_eth | tc | 8 | 8 | 1.000x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | tc | 8 | 8 | 1.000x | no | match | 0 | 1 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_unpriv_bpf_disabled.bpf.o:sys_nanosleep_enter | fentry/__x64_sys_nanosleep | 2108 | 3041 | 0.693x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_signed | raw_tp/sys_exit | 4228 | 2994 | 1.412x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_unsigned | raw_tp/sys_enter | 3675 | 2782 | 1.321x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o:balancer_ingress | tc | 691 | 637 | 1.085x | no | match | 0 | 0 | 992 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:tc_count_pkts | tc | 8 | 10 | 0.800x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_count_pkts | xdp | 18 | 19 | 0.947x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect | xdp | 19 | 18 | 1.056x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_111 | xdp | 24 | 11 | 2.182x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_do_redirect.bpf.o:xdp_redirect_to_222 | xdp | 23 | 11 | 2.091x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_crash.bpf.o:sys_enter | fentry/do_nanosleep | 2273 | 1986 | 1.145x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_start_deadlock.bpf.o:start_timer | syscall | 5327 | 3827 | 1.392x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/trace_printk.bpf.o:sys_enter | fentry/__x64_sys_nanosleep | 1680 | 1636 | 1.027x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/trace_vprintk.bpf.o:sys_enter | fentry/__x64_sys_nanosleep | 2943 | 2404 | 1.224x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_failure.bpf.o:test_spin_lock | fentry/bpf_spin_lock | 2737 | 1840 | 1.488x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_failure.bpf.o:test_spin_unlock | fentry/bpf_spin_unlock | 1998 | 1934 | 1.033x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uptr_update_failure.bpf.o:not_used | syscall | 2232 | 6472 | 0.345x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:arena_kfuncs_under_bpf_lock | syscall | 1790 | 1974 | 0.907x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1 | syscall | 2132 | 4207 | 0.507x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc1_nosleep | socket | 19 | 8 | 2.375x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2 | syscall | 1427 | 1884 | 0.757x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc2_nosleep | socket | 8 | 9 | 0.889x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc3 | syscall | 5641 | 9265 | 0.609x | no | match | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1 | syscall | 2966 | 1646 | 1.802x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve1_nosleep | socket | 18 | 8 | 2.250x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2 | syscall | 1852 | 1579 | 1.173x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_reserve2_nosleep | socket | 8 | 8 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region | syscall | 1726 | 1929 | 0.895x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_invalid_region_nosleep | socket | 8 | 8 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice | syscall | 2160 | 2735 | 0.790x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:reserve_twice_nosleep | socket | 8 | 8 | 1.000x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_globals1.bpf.o:check_relocation | syscall | 2365 | 1626 | 1.454x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_globals1.bpf.o:check_reserve1 | syscall | 2269 | 2083 | 1.089x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_globals2.bpf.o:check_reserve2 | syscall | 2732 | 1977 | 1.382x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_large.bpf.o:access_reserved | syscall | 1885 | 1595 | 1.182x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_large.bpf.o:big_alloc1 | syscall | 2431 | 2734 | 0.889x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_large.bpf.o:free_reserved | syscall | 2622 | 3169 | 0.827x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena_large.bpf.o:request_partially_reserved | syscall | 3366 | 3795 | 0.887x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:bad_words | syscall | 19695 | 12338 | 1.596x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:bit_index | syscall | 1917 | 3958 | 0.484x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:bits_copy | syscall | 2430 | 2728 | 0.891x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:bits_memalloc | syscall | 9586 | 7875 | 1.217x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:bits_too_big | syscall | 3913 | 2131 | 1.836x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:fewer_words | syscall | 3465 | 3685 | 0.940x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:huge_words | syscall | 3030 | 2904 | 1.043x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:max_words | syscall | 10924 | 7090 | 1.541x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:null_pointer | syscall | 2175 | 3345 | 0.650x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:zero_words | syscall | 2364 | 1839 | 1.285x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx2 | tc/ingress | 89 | 42 | 2.119x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx3 | tc/ingress | 42 | 40 | 1.050x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx5 | tc/ingress | 11 | 13 | 0.846x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx6 | tc/ingress | 11 | 24 | 0.458x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unmodified_ctx_pointer_to_helper | tc | 9 | 20 | 0.450x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_jit_inline.bpf.o:inline_bpf_get_current_task | fentry/bpf_fentry_test1 | 2647 | 3192 | 0.829x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cgrp_kfunc_syscall | syscall | 6146 | 4147 | 1.482x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cpumask_kfunc_syscall | syscall | 14181 | 9385 | 1.511x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:task_kfunc_syscall | syscall | 6357 | 3384 | 1.879x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_mtu.bpf.o:tc_uninit_mtu | tc/ingress | 11 | 21 | 0.524x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_typedef.bpf.o:resolve_typedef | fentry/bpf_fentry_test_sinfo | 2123 | 2795 | 0.760x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:redirect | xdp | 12 | 11 | 1.091x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | tc | 14 | 15 | 0.933x | no | match | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | 14 | 14 | 1.000x | no | match | 2 | 3 | 0 | 0 |

## Loadable But Not Runnable

| Program | Section | Applied | CMOV | WIDE | ROTATE | LEA | Failure |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/bashreadline.bpf.o:printret | uretprobe/readline | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o:ipv4_bind_entry | kprobe/inet_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o:ipv4_bind_exit | kretprobe/inet_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o:ipv6_bind_entry | kprobe/inet6_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o:ipv6_bind_exit | kretprobe/inet6_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_complete_btf | tp_btf/block_rq_complete | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_insert_btf | tp_btf/block_rq_insert | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue_btf | tp_btf/block_rq_issue | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biopattern.bpf.o:handle__block_rq_complete | tracepoint/block/block_rq_complete | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:blk_account_io_merge_bio | kprobe/blk_account_io_merge_bio | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_io_start | tp_btf/block_io_start | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_rq_complete | tp_btf/block_rq_complete | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_rq_insert | tp_btf/block_rq_insert | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biosnoop.bpf.o:block_rq_issue | tp_btf/block_rq_issue | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_merge_bio | kprobe/blk_account_io_merge_bio | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_done | tp_btf/block_io_done | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_start | tp_btf/block_io_start | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:__blk_account_io_done | kprobe/__blk_account_io_done | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:__blk_account_io_start | kprobe/__blk_account_io_start | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_account_io_done | kprobe/blk_account_io_done | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_account_io_start | kprobe/blk_account_io_start | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_mq_start_request | kprobe/blk_mq_start_request | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:block_io_done | tp_btf/block_io_done | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:block_io_start | tp_btf/block_io_start | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/bitesize.bpf.o:block_rq_issue | tp_btf/block_rq_issue | no | 4 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_account_page_dirtied | kprobe/account_page_dirtied | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_add_to_page_cache_lru | kprobe/add_to_page_cache_lru | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_folio_account_dirtied | kprobe/folio_account_dirtied | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_mark_buffer_dirty | kprobe/mark_buffer_dirty | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:kprobe_mark_page_accessed | kprobe/mark_page_accessed | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:tracepoint__writeback_dirty_folio | tracepoint/writeback/writeback_dirty_folio | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:tracepoint__writeback_dirty_page | tracepoint/writeback/writeback_dirty_page | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/cpufreq.bpf.o:cpu_frequency | tp_btf/cpu_frequency | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/cpufreq.bpf.o:do_sample | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/drsnoop.bpf.o:direct_reclaim_begin_btf | tp_btf/mm_vmscan_direct_reclaim_begin | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/drsnoop.bpf.o:direct_reclaim_end_btf | tp_btf/mm_vmscan_direct_reclaim_end | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve | tracepoint/syscalls/sys_enter_execve | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_exit_execve | tracepoint/syscalls/sys_exit_execve | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/exitsnoop.bpf.o:sched_process_exit | tracepoint/sched/sched_process_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:security_inode_create | kprobe/security_inode_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_create | kprobe/vfs_create | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_open | kprobe/vfs_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink | kprobe/vfs_unlink | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink_ret | kretprobe/vfs_unlink | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_read_entry | kprobe/vfs_read | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_write_entry | kprobe/vfs_write | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_entry | kprobe/dummy_file_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_exit | kretprobe/dummy_file_open | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_entry | kprobe/dummy_file_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_exit | kretprobe/dummy_file_read | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_entry | kprobe/dummy_file_sync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_exit | kretprobe/dummy_file_sync | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_entry | kprobe/dummy_file_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_exit | kretprobe/dummy_file_write | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_entry | kprobe/dummy_getattr | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_exit | kretprobe/dummy_getattr | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_open_entry | kprobe/dummy_file_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_open_exit | kretprobe/dummy_file_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_read_entry | kprobe/dummy_file_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_read_exit | kretprobe/dummy_file_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_sync_entry | kprobe/dummy_file_sync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_sync_exit | kretprobe/dummy_file_sync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_write_entry | kprobe/dummy_file_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_write_exit | kretprobe/dummy_file_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kprobe | kprobe/dummy_kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kretprobe | kretprobe/dummy_kretprobe | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/gethostlatency.bpf.o:handle_entry | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/gethostlatency.bpf.o:handle_return | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o:irq_handler_entry_btf | tp_btf/irq_handler_entry | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/hardirqs.bpf.o:irq_handler_exit_btf | tp_btf/irq_handler_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/javagc.bpf.o:handle_gc_end | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/javagc.bpf.o:handle_gc_start | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/javagc.bpf.o:handle_mem_pool_gc_end | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/javagc.bpf.o:handle_mem_pool_gc_start | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read | kprobe/down_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_exit | kretprobe/down_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_exit_nested | kretprobe/down_read_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_interruptible | kprobe/down_read_interruptible | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_interruptible_exit | kretprobe/down_read_interruptible | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable | kprobe/down_read_killable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable_exit | kretprobe/down_read_killable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable_exit_nested | kretprobe/down_read_killable_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_killable_nested | kprobe/down_read_killable_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_nested | kprobe/down_read_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_trylock | kprobe/down_read_trylock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_read_trylock_exit | kretprobe/down_read_trylock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write | kprobe/down_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_exit | kretprobe/down_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_exit_nested | kretprobe/down_write_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_killable | kprobe/down_write_killable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_killable_exit | kretprobe/down_write_killable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_killable_exit_nested | kretprobe/down_write_killable_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_killable_nested | kprobe/down_write_killable_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_nested | kprobe/down_write_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_trylock | kprobe/down_write_trylock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_down_write_trylock_exit | kretprobe/down_write_trylock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock | kprobe/mutex_lock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_exit | kretprobe/mutex_lock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_exit_nested | kretprobe/mutex_lock_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_interruptible | kprobe/mutex_lock_interruptible | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_interruptible_exit | kretprobe/mutex_lock_interruptible | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_interruptible_exit_nested | kretprobe/mutex_lock_interruptible_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_interruptible_nested | kprobe/mutex_lock_interruptible_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_killable | kprobe/mutex_lock_killable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_killable_exit | kretprobe/mutex_lock_killable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_killable_exit_nested | kretprobe/mutex_lock_killable_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_killable_nested | kprobe/mutex_lock_killable_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_nested | kprobe/mutex_lock_nested | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_trylock | kprobe/mutex_trylock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_trylock_exit | kretprobe/mutex_trylock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_mutex_unlock | kprobe/mutex_unlock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_netlink_dump | kprobe/netlink_dump | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_netlink_dump_exit | kretprobe/netlink_dump | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_rtnetlink_rcv_msg | kprobe/rtnetlink_rcv_msg | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_rtnetlink_rcv_msg_exit | kretprobe/rtnetlink_rcv_msg | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_sock_do_ioctl | kprobe/sock_do_ioctl | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_sock_do_ioctl_exit | kretprobe/sock_do_ioctl | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_up_read | kprobe/up_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/klockstat.bpf.o:kprobe_up_write | kprobe/up_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o:kprobe_entry | kprobe/foo | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o:kprobe_return | kretprobe/foo | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/llcstat.bpf.o:on_cache_miss | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/llcstat.bpf.o:on_cache_ref | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mdflush.bpf.o:kprobe_md_flush_request | kprobe/md_flush_request | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:fsconfig_entry | tracepoint/syscalls/sys_enter_fsconfig | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:fsconfig_exit | tracepoint/syscalls/sys_exit_fsconfig | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:fsmount_entry | tracepoint/syscalls/sys_enter_fsmount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:fsmount_exit | tracepoint/syscalls/sys_exit_fsmount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:fsopen_entry | tracepoint/syscalls/sys_enter_fsopen | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:fsopen_exit | tracepoint/syscalls/sys_exit_fsopen | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:mount_entry | tracepoint/syscalls/sys_enter_mount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:mount_exit | tracepoint/syscalls/sys_exit_mount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:move_mount_entry | tracepoint/syscalls/sys_enter_move_mount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:move_mount_exit | tracepoint/syscalls/sys_exit_move_mount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:umount_entry | tracepoint/syscalls/sys_enter_umount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/mountsnoop.bpf.o:umount_exit | tracepoint/syscalls/sys_exit_umount | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kprobe_migrate_misplaced_folio | kprobe/migrate_misplaced_folio | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kprobe_migrate_misplaced_page | kprobe/migrate_misplaced_page | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kretprobe_migrate_misplaced_folio_exit | kretprobe/migrate_misplaced_folio | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:kretprobe_migrate_misplaced_page_exit | kretprobe/migrate_misplaced_page | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/oomkill.bpf.o:oom_kill_process | kprobe/oom_kill_process | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_enter_open | tracepoint/syscalls/sys_enter_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_enter_openat | tracepoint/syscalls/sys_enter_openat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_enter_openat2 | tracepoint/syscalls/sys_enter_openat2 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_exit_open | tracepoint/syscalls/sys_exit_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_exit_openat | tracepoint/syscalls/sys_exit_openat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/opensnoop.bpf.o:tracepoint__syscalls__sys_exit_openat2 | tracepoint/syscalls/sys_exit_openat2 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_switch | tp_btf/sched_switch | no | 6 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup | tp_btf/sched_wakeup | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup_new | tp_btf/sched_wakeup_new | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/runqlen.bpf.o:do_sample | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_switch | tp_btf/sched_switch | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_wakeup | tp_btf/sched_wakeup | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/runqslower.bpf.o:sched_wakeup_new | tp_btf/sched_wakeup_new | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:kill_entry | tracepoint/syscalls/sys_enter_kill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:kill_exit | tracepoint/syscalls/sys_exit_kill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:sig_trace | tracepoint/signal/signal_generate | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:tgkill_entry | tracepoint/syscalls/sys_enter_tgkill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:tgkill_exit | tracepoint/syscalls/sys_exit_tgkill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:tkill_entry | tracepoint/syscalls/sys_enter_tkill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/sigsnoop.bpf.o:tkill_exit | tracepoint/syscalls/sys_exit_tkill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/slabratetop.bpf.o:kmem_cache_alloc | kprobe/kmem_cache_alloc | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/slabratetop.bpf.o:kmem_cache_alloc_noprof | kprobe/kmem_cache_alloc_noprof | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o:softirq_entry_btf | tp_btf/softirq_entry | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/solisten.bpf.o:inet_listen_entry | kprobe/inet_listen | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/solisten.bpf.o:inet_listen_exit | kretprobe/inet_listen | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstat_entry | tracepoint/syscalls/sys_enter_newfstat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstat_return | tracepoint/syscalls/sys_exit_newfstat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstatat_entry | tracepoint/syscalls/sys_enter_newfstatat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newfstatat_return | tracepoint/syscalls/sys_exit_newfstatat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newlstat_entry | tracepoint/syscalls/sys_enter_newlstat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newlstat_return | tracepoint/syscalls/sys_exit_newlstat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newstat_entry | tracepoint/syscalls/sys_enter_newstat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_newstat_return | tracepoint/syscalls/sys_exit_newstat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_statfs_entry | tracepoint/syscalls/sys_enter_statfs | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_statfs_return | tracepoint/syscalls/sys_exit_statfs | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_statx_entry | tracepoint/syscalls/sys_enter_statx | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/statsnoop.bpf.o:handle_statx_return | tracepoint/syscalls/sys_exit_statx | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_arm_sync_file_range | tracepoint/syscalls/sys_enter_arm_sync_file_range | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_fdatasync | tracepoint/syscalls/sys_enter_fdatasync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_fsync | tracepoint/syscalls/sys_enter_fsync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_msync | tracepoint/syscalls/sys_enter_msync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_sync | tracepoint/syscalls/sys_enter_sync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_sync_file_range | tracepoint/syscalls/sys_enter_sync_file_range | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_sync_file_range2 | tracepoint/syscalls/sys_enter_sync_file_range2 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syncsnoop.bpf.o:tracepoint__syscalls__sys_enter_syncfs | tracepoint/syscalls/sys_enter_syncfs | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o:sys_enter | tracepoint/raw_syscalls/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/syscount.bpf.o:sys_exit | tracepoint/raw_syscalls/sys_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect | kprobe/tcp_v4_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect_ret | kretprobe/tcp_v4_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v6_connect | kprobe/tcp_v6_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v6_connect_ret | kretprobe/tcp_v6_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_destroy_sock | tracepoint/tcp/tcp_destroy_sock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_rcv_state_process | kprobe/tcp_rcv_state_process | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_v4_connect | kprobe/tcp_v4_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpconnlat.bpf.o:tcp_v6_connect | kprobe/tcp_v6_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcplife.bpf.o:inet_sock_set_state | tracepoint/sock/inet_sock_set_state | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_destroy_sock_btf | tp_btf/tcp_destroy_sock | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_probe_btf | tp_btf/tcp_probe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_rcv_space_adjust_btf | tp_btf/tcp_rcv_space_adjust | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv_kprobe | kprobe/tcp_rcv_established | no | 4 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpstates.bpf.o:handle_set_state | tracepoint/sock/inet_sock_set_state | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv_kprobe | kprobe/tcp_v4_syn_recv_sock | no | 4 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v6_syn_recv_kprobe | kprobe/tcp_v6_syn_recv_sock | no | 4 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o:tcp_cleanup_rbuf | kprobe/tcp_cleanup_rbuf | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptop.bpf.o:tcp_sendmsg | kprobe/tcp_sendmsg | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:enter_tcp_set_state | kprobe/tcp_set_state | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:entry_trace_close | kprobe/tcp_close | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:exit_inet_csk_accept | kretprobe/inet_csk_accept | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v4_connect | kprobe/tcp_v4_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v4_connect_ret | kretprobe/tcp_v4_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v6_connect | kprobe/tcp_v6_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/tcptracer.bpf.o:tcp_v6_connect_ret | kretprobe/tcp_v6_connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_create | kprobe/vfs_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_fsync | kprobe/vfs_fsync | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_mkdir | kprobe/vfs_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_open | kprobe/vfs_open | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_read | kprobe/vfs_read | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_rmdir | kprobe/vfs_rmdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_unlink | kprobe/vfs_unlink | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/bcc/libbpf-tools/vfsstat.bpf.o:kprobe_vfs_write | kprobe/vfs_write | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exec | tp/sched/sched_process_exec | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exit | tp/sched/sched_process_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exec | tp/sched/sched_process_exec | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exit | tp/sched/sched_process_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o:do_unlinkat | kprobe/do_unlinkat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o:do_unlinkat_exit | kretprobe/do_unlinkat | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o:entry_probe | ksyscall/kill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o:tgkill_entry | ksyscall/tgkill | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/profile.bpf.o:profile | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/task_iter.bpf.o:get_tasks | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/uprobe.bpf.o:uprobe_add | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/uprobe.bpf.o:uprobe_sub | uprobe//proc/self/exe:uprobed_sub | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/uprobe.bpf.o:uretprobe_add | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/uprobe.bpf.o:uretprobe_sub | uretprobe//proc/self/exe:uprobed_sub | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/usdt.bpf.o:usdt_auto_attach | usdt/libc.so.6:libc:setjmp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/usdt.bpf.o:usdt_manual_attach | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bench_local_storage_create.bpf.o:sched_process_fork | tp_btf/sched_process_fork | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bench_local_storage_create.bpf.o:socket_post_create | lsm.s/socket_post_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_acked | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_cong_control | struct_ops | no | 4 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_cwnd_event | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_init | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_recalc_ssthresh | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_state | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cc_cubic.bpf.o:bpf_cubic_undo_cwnd | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_acked | struct_ops | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_cong_avoid | struct_ops | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_cwnd_event | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_init | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_recalc_ssthresh | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_state | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_cubic.bpf.o:bpf_cubic_undo_cwnd | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_cong_avoid | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_cwnd_event | struct_ops | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_cwnd_undo | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_init | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_ssthresh | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_state | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp.bpf.o:bpf_dctcp_update_alpha | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_array_map.bpf.o:dump_bpf_array_map | iter/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_hash_map.bpf.o:dump_bpf_hash_map | iter/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_hash_map.bpf.o:sleepable_dummy_dump | iter.s/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_link.bpf.o:dump_bpf_link | iter/bpf_link | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_map.bpf.o:dump_bpf_map | iter/bpf_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_percpu_array_map.bpf.o:dump_bpf_percpu_array_map | iter/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_percpu_hash_map.bpf.o:dump_bpf_percpu_hash_map | iter/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_helpers.bpf.o:delete_bpf_sk_storage_map | iter/bpf_sk_storage_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_helpers.bpf.o:fill_socket_owner | iter/task_file | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_helpers.bpf.o:negate_socket_local_storage | iter/tcp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_map.bpf.o:oob_write_bpf_sk_storage_map | iter/bpf_sk_storage_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_bpf_sk_storage_map.bpf.o:rw_bpf_sk_storage_map | iter/bpf_sk_storage_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_ipv6_route.bpf.o:dump_ipv6_route | iter/ipv6_route | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_ksym.bpf.o:dump_ksym | iter/ksym | no | 3 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_map_elem.bpf.o:dump_bpf_map_values | iter/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_netlink.bpf.o:dump_netlink | iter/netlink | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_setsockopt.bpf.o:change_tcp_cc | iter/tcp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_sockmap.bpf.o:copy | iter/sockmap | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_btf.bpf.o:dump_task_struct | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_file.bpf.o:dump_task_file | iter/task_file | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_stack.bpf.o:dump_task_stack | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_stack.bpf.o:get_task_user_stacks | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_vmas.bpf.o:proc_maps | iter/task_vma | no | 3 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_tasks.bpf.o:dump_task | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_tasks.bpf.o:dump_task_sleepable | iter.s/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern1.bpf.o:dump_task | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern2.bpf.o:dump_task | iter/task | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern4.bpf.o:dump_bpf_map | iter/bpf_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern5.bpf.o:dump_bpf_hash_map | iter/bpf_map_elem | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_unix.bpf.o:dump_unix | iter/unix | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_vma_offset.bpf.o:get_vma_offset | iter/task_vma | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_syscall_macro.bpf.o:handle_sys_prctl | kprobe/__x64_sys_prctl | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_syscall_macro.bpf.o:prctl_enter | ksyscall/prctl | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_syscall_macro.bpf.o:splice_enter | ksyscall/splice | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_iter.bpf.o:cgroup_id_printer | iter/cgroup | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_mprog.bpf.o:getsockopt_1 | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_mprog.bpf.o:getsockopt_2 | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_mprog.bpf.o:getsockopt_3 | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_mprog.bpf.o:getsockopt_4 | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_preorder.bpf.o:child | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_preorder.bpf.o:child_2 | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_preorder.bpf.o:parent | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_preorder.bpf.o:parent_2 | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access | cgroup_skb/ingress | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_acquire_leave_in_map | tp_btf/cgroup_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_acquire_release_argument | tp_btf/cgroup_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_from_id | tp_btf/cgroup_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_get_ancestors | tp_btf/cgroup_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_get_release | tp_btf/cgroup_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o:test_cgrp_xchg_release | tp_btf/cgroup_mkdir | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_attach_cgroup.bpf.o:set_cookie | cgroup/connect6 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_attach_cgroup.bpf.o:update_cookie_sockops | sockops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_recursion.bpf.o:on_enter | tp_btf/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:cgroup_iter | iter.s/cgroup | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o:on_enter | tp_btf/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_tp_btf.bpf.o:on_exit | tp_btf/sys_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_alloc_free_cpumask | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_and_or_xor | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_copy_any_anyand | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_cpumask_weight | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_first_firstzero_cpu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_firstand_nocpu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_array_l2_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_array_one_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_array_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_deep_array_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_deep_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_nested_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_global_mask_rcu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_insert_leave | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_insert_remove_release | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_intersects_subset | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate_reject_small_mask | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_populate_reject_unaligned | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_refcount_null_tracking | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_set_clear_cpu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_setall_clear_cpu | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o:test_test_and_set_clear | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/dummy_st_ops_success.bpf.o:test_1 | struct_ops/test_1 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/dummy_st_ops_success.bpf.o:test_2 | struct_ops/test_2 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/dummy_st_ops_success.bpf.o:test_sleepable | struct_ops.s/test_sleepable | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/exhandler_kern.bpf.o:trace_task_newtask | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma.bpf.o:handle_pe | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/get_func_ip_uprobe_test.bpf.o:test1 | uprobe//proc/self/exe:uprobe_trigger_body+1 | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ima.bpf.o:bprm_committed_creds | lsm.s/bprm_committed_creds | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ima.bpf.o:bprm_creds_for_exec | lsm.s/bprm_creds_for_exec | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ima.bpf.o:kernel_read_file | lsm.s/kernel_read_file | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ip_check_defrag.bpf.o:defrag | netfilter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_multi_verifier.bpf.o:kprobe_session_return_0 | kprobe.session | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_multi_verifier.bpf.o:kprobe_session_return_1 | kprobe.session | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:exec | lsm.s/bprm_committed_creds | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:inode_rename | lsm.s/inode_rename | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:socket_bind | lsm.s/socket_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:socket_post_create | lsm.s/socket_post_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/local_storage.bpf.o:unlink_hook | lsm/inode_unlink | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop1.bpf.o:nested_loops | raw_tracepoint/kfree_skb | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop2.bpf.o:while_true | raw_tracepoint/consume_skb | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop6.bpf.o:trace_virtqueue_add_sgs | kprobe/virtqueue_add_sgs | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_int_hook | lsm/file_mprotect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_task_free | lsm/task_free | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm.bpf.o:test_void_hook | lsm.s/bprm_committed_creds | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o:socket_alloc | lsm_cgroup/sk_alloc_security | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o:socket_bind | lsm_cgroup/socket_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o:socket_bind2 | lsm_cgroup/socket_bind | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o:socket_clone | lsm_cgroup/inet_csk_clone | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o:socket_post_create | lsm_cgroup/socket_post_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup.bpf.o:socket_post_create2 | lsm_cgroup/socket_post_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_tailcall.bpf.o:lsm_file_permission_prog | lsm/file_permission | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_tailcall.bpf.o:lsm_kernfs_init_security_entry | lsm/kernfs_init_security | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_tailcall.bpf.o:lsm_kernfs_init_security_prog | lsm/kernfs_init_security | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_percpu_stats.bpf.o:dump_bpf_map | iter/bpf_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_tp_recursion.bpf.o:test1 | kprobe/bpf_fentry_test1 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_tp_recursion.bpf.o:test2 | tp/bpf_trace/bpf_trace_printk | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_tp_recursion.bpf.o:test3 | tp/bpf_trace/bpf_trace_printk | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_tp_recursion.bpf.o:test4 | tp/bpf_trace/bpf_trace_printk | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sock.bpf.o:_sockops | sockops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sockmap.bpf.o:mptcp_sockmap_inject | sockops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sockmap.bpf.o:mptcp_sockmap_redirect | sk_skb/stream_verdict | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_nested_offset | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_read_cpumask | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_success.bpf.o:test_skb_field | tp_btf/tcp_probe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netif_receive_skb.bpf.o:trace_netif_receive_skb | tp_btf/netif_receive_skb | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_cgroup_skb | cgroup_skb/ingress | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_sk_msg | sk_msg | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_sockops | sockops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netns_cookie_prog.bpf.o:get_netns_cookie_tcx | tcx/ingress | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/perf_event_stackmap.bpf.o:oncpu | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/prepare.bpf.o:program | cgroup_skb/egress | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/setget_sockopt.bpf.o:_getsockopt | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/setget_sockopt.bpf.o:skops_sockopt | sockops | no | 3 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/setget_sockopt.bpf.o:socket_post_create | lsm_cgroup/socket_post_create | no | 3 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o:iter_tcp6_client | iter/tcp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o:iter_tcp6_server | iter/tcp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o:iter_udp6_client | iter/udp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o:iter_udp6_server | iter/udp | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog.bpf.o:sock_connect | cgroup/connect6 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/socket_cookie_prog.bpf.o:set_cookie | cgroup/connect6 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/socket_cookie_prog.bpf.o:update_cookie_sockops | sockops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sockopt_qos_to_cc.bpf.o:sockopt_qos_to_cc | cgroup/setsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o:kprobe_multi_test | kprobe.multi | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o:kprobe_test | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map.bpf.o:oncpu | tracepoint/sched/sched_switch | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_map_skip.bpf.o:oncpu | tracepoint/sched/sched_switch | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_does_not_sleep | uprobe.s | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_might_sleep | uprobe.s | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o:main_might_sleep_with_subprogs | uprobe.s | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o:on_enter | tp_btf/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_local_storage.bpf.o:on_exit | tp_btf/sys_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_recursion.bpf.o:on_enter | tp_btf/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_ls_uptr.bpf.o:on_enter | tp_btf/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_storage_nodeadlock.bpf.o:socket_post_create | lsm.s/socket_post_create | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_incompl_cong_ops.bpf.o:incompl_cong_ops_ssthresh | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_incompl_cong_ops.bpf.o:incompl_cong_ops_undo_cwnd | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_update.bpf.o:ca_update_1_init | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_update.bpf.o:ca_update_2_init | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_update.bpf.o:ca_update_cong_control | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_update.bpf.o:ca_update_ssthresh | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_update.bpf.o:ca_update_undo_cwnd | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_write_sk_pacing.bpf.o:write_sk_pacing_cong_control | struct_ops | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_write_sk_pacing.bpf.o:write_sk_pacing_init | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_write_sk_pacing.bpf.o:write_sk_pacing_ssthresh | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_write_sk_pacing.bpf.o:write_sk_pacing_undo_cwnd | struct_ops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_kprobe_sleepable.bpf.o:handle_kprobe_sleepable | kprobe/__x64_sys_nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_kprobe_auto | ksyscall/nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_kretprobe_auto | kretsyscall/nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uprobe_byname | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uprobe_byname2 | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uprobe_byname3 | uprobe//proc/self/exe:trigger_func3 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uprobe_byname3_sleepable | uprobe.s//proc/self/exe:trigger_func3 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uprobe_ref_ctr | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uretprobe_byname | uretprobe//proc/self/exe:trigger_func2 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uretprobe_byname2 | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uretprobe_byname3 | uretprobe//proc/self/exe:trigger_func3 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uretprobe_byname3_sleepable | uretprobe.s//proc/self/exe:trigger_func3 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o:handle_uretprobe_ref_ctr | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe_manual.bpf.o:handle_kprobe | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe_manual.bpf.o:handle_kretprobe | kretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe_manual.bpf.o:handle_uprobe | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe_manual.bpf.o:handle_uprobe_byname | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe_manual.bpf.o:handle_uretprobe | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_kprobe | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_kretprobe | kretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_pe | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp1 | tp/syscalls/sys_enter_nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp2 | tp/syscalls/sys_enter_nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp3 | tp/syscalls/sys_enter_nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_tp_btf | tp_btf/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_uprobe | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:handle_uretprobe | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_cookie.bpf.o:test_int_hook | lsm/file_mprotect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_build_id.bpf.o:uprobe_nofault | uprobe.multi/./uprobe_multi:uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_build_id.bpf.o:uprobe_sleepable | uprobe.multi.s/./uprobe_multi:uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:lsm_run | lsm/bpf | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:lsm_s_run | lsm.s/bpf | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o:kprobe1 | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o:event_run | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o:kmulti_run | kprobe.multi | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o:kprobe_run | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o:tp_run | tracepoint | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o:umulti_run | uprobe.multi | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_fill_link_info.bpf.o:uprobe_run | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:arg_tag_ctx_kprobe | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:arg_tag_ctx_perf | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:kprobe_resolved_ctx | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:kprobe_typedef_ctx | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:kprobe_workaround_ctx | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func_ctx_args.bpf.o:perf_event_ctx | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kernel_flag.bpf.o:bpf | lsm.s/bpf | no | 2 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o:dynptr_data_null | lsm.s/bpf | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:_getsockopt | cgroup/getsockopt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_libbpf_get_fd_by_id_opts.bpf.o:check_access | lsm/bpf_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_lookup_and_delete.bpf.o:bpf_lookup_and_delete_test | tp/syscalls/sys_enter_getpgid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_init.bpf.o:sysenter_getpgid | tp/syscalls/sys_enter_getpgid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_lookup_percpu_elem.bpf.o:sysenter_getuid | tp/syscalls/sys_enter_getuid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_delete | tp/syscalls/sys_enter_getppid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_for_each_fail | tp/syscalls/sys_enter_getpgid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_for_each_pass | tp/syscalls/sys_enter_gettid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_peek | tp/syscalls/sys_enter_getgid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_pop | tp/syscalls/sys_enter_geteuid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_push | tp/syscalls/sys_enter_getuid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_map_ops.bpf.o:map_update | tp/syscalls/sys_enter_getpid | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_netfilter_link_attach.bpf.o:nf_link_attach_test | netfilter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog1 | kprobe/__set_task_comm | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog2 | kretprobe/__set_task_comm | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_perf_link.bpf.o:handler | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_perf_skip.bpf.o:handler | perf_event | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_probe_user.bpf.o:handle_sys_connect | ksyscall/connect | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ptr_untrusted.bpf.o:lsm_run | lsm.s/bpf | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o:send_signal_perf | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o:send_signal_tp | tracepoint/syscalls/sys_enter_nanosleep | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o:send_signal_tp_sched | tracepoint/sched/sched_switch | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:tcp_bad_csum | tp_btf/tcp_bad_csum | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:tcp_retransmit_synack | tp_btf/tcp_retransmit_synack | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_tracing.bpf.o:trace_inet_sock_set_state | tp_btf/inet_sock_set_state | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skmsg_load_helpers.bpf.o:prog_msg_verdict | sk_msg | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skmsg_load_helpers.bpf.o:prog_msg_verdict_clone | sk_msg | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skmsg_load_helpers.bpf.o:prog_msg_verdict_clone2 | sk_msg | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skmsg_load_helpers.bpf.o:prog_skb_verdict | sk_skb/stream_verdict | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_change_tail.bpf.o:prog_skb_verdict | sk_skb | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_progs_query.bpf.o:prog_skb_verdict | sk_skb | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_progs_query.bpf.o:prog_skmsg_verdict | sk_msg | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_skb_verdict_attach.bpf.o:prog_skb_verdict | sk_skb/verdict | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_pt_regs.bpf.o:handle_uprobe | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_under_cgroup.bpf.o:lsm_run | lsm.s/bpf | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_under_cgroup.bpf.o:tp_btf_run | tp_btf/task_newtask | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tcpbpf_kern.bpf.o:bpf_testcb | sockops | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tracepoint.bpf.o:oncpu | tracepoint/sched/sched_switch | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_unpriv_bpf_disabled.bpf.o:handle_perf_event | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o:test1 | uprobe/./liburandom_read.so:urandlib_api_sameoffset | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o:test2 | uprobe/./liburandom_read.so:urandlib_api_sameoffset@LIBURANDOM_READ_1.0.0 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o:test3 | uretprobe/./liburandom_read.so:urandlib_api_sameoffset@@LIBURANDOM_READ_2.0.0 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o:test4 | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o:handle_uprobe_byname | uprobe//proc/self/exe:autoattach_trigger_func | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o:handle_uprobe_byname2 | uprobe/libc.so.6:fopen | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o:handle_uprobe_noautoattach | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o:handle_uretprobe_byname | uretprobe//proc/self/exe:autoattach_trigger_func | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe_autoattach.bpf.o:handle_uretprobe_byname2 | uretprobe/libc.so.6:fopen | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_urandom_usdt.bpf.o:urand_read_with_sema | usdt/./urandom_read:urand:read_with_sema | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_urandom_usdt.bpf.o:urand_read_without_sema | usdt/./urandom_read:urand:read_without_sema | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_urandom_usdt.bpf.o:urandlib_read_with_sema | usdt/./liburandom_read.so:urandlib:read_with_sema | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_urandom_usdt.bpf.o:urandlib_read_without_sema | usdt/./liburandom_read.so:urandlib:read_without_sema | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o:usdt0 | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o:usdt12 | usdt//proc/self/exe:test:usdt12 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o:usdt3 | usdt//proc/self/exe:test:usdt3 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o:usdt_sib | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_signed | tp/raw_syscalls/sys_exit | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_unsigned | tp/raw_syscalls/sys_enter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler_exit | tp/syscalls/sys_exit_getpid | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/timer_start_deadlock.bpf.o:tp_hrtimer_cancel | tp_btf/hrtimer_cancel | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/token_lsm.bpf.o:token_capable | lsm/bpf_token_capable | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/token_lsm.bpf.o:token_cmd | lsm/bpf_token_cmd | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:uprobe | uprobe.multi//proc/self/exe:uprobe_multi_func_* | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:uprobe_extra | uprobe.multi//proc/self/exe:uprobe_multi_func_* | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:uprobe_sleep | uprobe.multi.s//proc/self/exe:uprobe_multi_func_* | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:uretprobe | uretprobe.multi//proc/self/exe:uprobe_multi_func_* | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:uretprobe_sleep | uretprobe.multi.s//proc/self/exe:uprobe_multi_func_* | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:usdt_extra | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o:usdt_pid | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_pid_filter.bpf.o:uprobe_multi_0 | uprobe.multi | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_pid_filter.bpf.o:uprobe_multi_1 | uprobe.multi | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_pid_filter.bpf.o:uprobe_multi_2 | uprobe.multi | no | 1 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_usdt.bpf.o:usdt0 | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_verifier.bpf.o:uprobe_sesison_return_0 | uprobe.session | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_verifier.bpf.o:uprobe_sesison_return_1 | uprobe.session | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall.bpf.o:probe | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o:test_uprobe | uprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o:test_uprobe_multi | uprobe.multi | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o:test_uprobe_session | uprobe.session | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o:test_uretprobe | uretprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o:test_uretprobe_multi | uretprobe.multi | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_syscall_executed.bpf.o:test_usdt | usdt | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:uprobe_1 | uprobe//proc/self/exe:target_1 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:uprobe_2 | uprobe//proc/self/exe:target_2 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:uprobe_3 | uprobe//proc/self/exe:target_3 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:uprobe_4 | uprobe//proc/self/exe:target_4 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:uretprobe_1 | uretprobe//proc/self/exe:target_1 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:uretprobe_4 | uretprobe//proc/self/exe:target_4 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uretprobe_stack.bpf.o:usdt_probe | usdt//proc/self/exe:uretprobe_stack:target | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:iter_maps1 | iter.s/bpf_map | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Bad address (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_btf_unreliable_prog.bpf.o:btf_unreliable_kprobe | kprobe | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:null_check_5_null_connect | cgroup/connect4 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:null_check_6_null_bind | cgroup/post_bind4 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:null_check_7_ctx_bind | cgroup/post_bind4 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:or_null_check_1_ctx | cgroup/sendmsg6 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:or_null_check_2_null | cgroup/sendmsg6 | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:padding_ctx_access_bpf_sk_lookup | sk_lookup | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cgrp_kfunc_perf_event | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cgrp_kfunc_tracepoint | tracepoint | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cpumask_kfunc_perf_event | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cpumask_kfunc_tracepoint | tracepoint | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:task_kfunc_perf_event | perf_event | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:task_kfunc_tracepoint | tracepoint | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:bool_retval_test1 | lsm/audit_rule_known | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:bool_retval_test2 | lsm/audit_rule_known | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test1 | lsm/file_permission | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test2 | lsm/file_permission | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:no_null_check | lsm/mmap_file | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:null_check | lsm/mmap_file | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:void_retval_test1 | lsm/file_free_security | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:void_retval_test2 | lsm/file_free_security | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o:with_valid_ctx_access_test6 | netfilter | no | 0 | 0 | 0 | 0 | bpf_prog_test_run_opts failed: Invalid argument (exit=1) |

## Load Failures

| Program | Section | Failure |
| --- | --- | --- |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_done | fentry/blk_account_io_done | bpf_object__load failed: No such file or directory (exit=1) |
| corpus/build/bcc/libbpf-tools/cachestat.bpf.o:fentry_account_page_dirtied | fentry/account_page_dirtied | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/capable.bpf.o:kprobe__cap_capable_entry | kprobe/cap_capable | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/capable.bpf.o:kprobe__cap_capable_exit | kretprobe/cap_capable | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/cpudist.bpf.o:sched_switch_btf | tp_btf/sched_switch | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/cpudist.bpf.o:sched_switch_tp | raw_tp/sched_switch | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_fentry | fentry/dummy_file_open | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_fexit | fexit/dummy_file_open | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_fentry | fentry/dummy_file_read | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_fexit | fexit/dummy_file_read | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_fentry | fentry/dummy_file_sync | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_fexit | fexit/dummy_file_sync | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_fentry | fentry/dummy_file_write | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_fexit | fexit/dummy_file_write | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_fentry | fentry/dummy_getattr | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_fexit | fexit/dummy_getattr | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_open_fentry | fentry/dummy_file_open | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_open_fexit | fexit/dummy_file_open | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_read_fentry | fentry/dummy_file_read | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_read_fexit | fexit/dummy_file_read | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_sync_fentry | fentry/dummy_file_sync | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_sync_fexit | fexit/dummy_file_sync | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_write_fentry | fentry/dummy_file_write | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/fsslower.bpf.o:file_write_fexit | fexit/dummy_file_write | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_fentry | fentry/dummy_fentry | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_fexit | fexit/dummy_fexit | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/futexctn.bpf.o:futex_enter | tracepoint/syscalls/sys_enter_futex | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/futexctn.bpf.o:futex_exit | tracepoint/syscalls/sys_exit_futex | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:aligned_alloc_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:aligned_alloc_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:calloc_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:calloc_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:free_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:malloc_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:malloc_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memalign_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memalign_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kfree | tracepoint/kmem/kfree | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmalloc | tracepoint/kmem/kmalloc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmalloc_node | tracepoint/kmem/kmalloc_node | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmem_cache_alloc | tracepoint/kmem/kmem_cache_alloc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmem_cache_alloc_node | tracepoint/kmem/kmem_cache_alloc_node | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__kmem_cache_free | tracepoint/kmem/kmem_cache_free | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__mm_page_alloc | tracepoint/kmem/mm_page_alloc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__mm_page_free | tracepoint/kmem/mm_page_free | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__percpu_alloc_percpu | tracepoint/percpu/percpu_alloc_percpu | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:memleak__percpu_free_percpu | tracepoint/percpu/percpu_free_percpu | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:mmap_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:mmap_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:mremap_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:mremap_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:munmap_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:posix_memalign_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:posix_memalign_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:pvalloc_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:pvalloc_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:realloc_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:realloc_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:valloc_enter | uprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/memleak.bpf.o:valloc_exit | uretprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fentry_migrate_misplaced_page | fentry/migrate_misplaced_page | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/numamove.bpf.o:fexit_migrate_misplaced_page_exit | fexit/migrate_misplaced_page | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/offcputime.bpf.o:sched_switch | tp_btf/sched_switch | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/offcputime.bpf.o:sched_switch_raw | raw_tp/sched_switch | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/profile.bpf.o:do_perf_event | perf_event | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:do_page_cache_ra | fentry/do_page_cache_ra | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:do_page_cache_ra_ret | fexit/do_page_cache_ra | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:filemap_alloc_folio_ret | fexit/filemap_alloc_folio | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:page_cache_alloc_ret | fexit/__page_cache_alloc | bpf_object__load failed: No such process (exit=1) |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o:softirq_exit | raw_tp/softirq_exit | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/bcc/libbpf-tools/softirqs.bpf.o:softirq_exit_btf | tp_btf/softirq_exit | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_destroy_sock | raw_tp/tcp_destroy_sock | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_probe | raw_tp/tcp_probe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/tcppktlat.bpf.o:tcp_rcv_space_adjust | raw_tp/tcp_rcv_space_adjust | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/wakeuptime.bpf.o:sched_switch | tp_btf/sched_switch | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/bcc/libbpf-tools/wakeuptime.bpf.o:sched_wakeup | tp_btf/sched_wakeup | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/libbpf-bootstrap/examples/c/lsm.bpf.o:lsm_bpf | lsm/bpf | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/async_stack_depth.bpf.o:async_call_root_check | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/async_stack_depth.bpf.o:pseudo_call_check | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_dctcp_release.bpf.o:dctcp_nouse_release | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_hashmap_lookup.bpf.o:benchmark | fentry/__x64_sys_getpgid | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern3.bpf.o:dump_task | iter/task | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_test_kern6.bpf.o:dump_bpf_hash_map | iter/bpf_map_elem | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_tcp_nogpl.bpf.o:nogpltcp_init | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_type_tag_user.bpf.o:test_sys_getsockname | fentry/__sys_getsockname | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_type_tag_user.bpf.o:test_user1 | fentry/bpf_testmod_test_btf_type_tag_user_1 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_type_tag_user.bpf.o:test_user2 | fentry/bpf_testmod_test_btf_type_tag_user_2 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cb_refs.bpf.o:leak_prog | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cb_refs.bpf.o:nested_cb | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cb_refs.bpf.o:non_cb_transfer_ref | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cb_refs.bpf.o:underflow_prog | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_hierarchical_stats.bpf.o:counter | tp_btf/cgroup_attach_task | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_hierarchical_stats.bpf.o:dumper | iter.s/cgroup | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_hierarchical_stats.bpf.o:flusher | fentry/bpf_rstat_flush | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_fp | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_no_null_check | tp_btf/cgroup_mkdir | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_null | tp_btf/cgroup_mkdir | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_trusted_walked | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_unreleased | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_unsafe_kretprobe | kretprobe/cgroup_destroy_locked | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_acquire_untrusted | tp_btf/cgroup_mkdir | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_rcu_get_release | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_fp | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_null | tp_btf/cgroup_mkdir | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_unacquired | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_release_untrusted | tp_btf/cgroup_mkdir | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o:cgrp_kfunc_xchg_unreleased | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_negative.bpf.o:on_enter | tp_btf/sys_enter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_ls_sleepable.bpf.o:no_rcu_lock | fentry.s/__x64_sys_getpgid | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_acquire_wrong_cpumask | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_alloc_double_release | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_alloc_no_release | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_cpumask_null | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_global_mask_no_null_check | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_global_mask_out_of_rcu | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_global_mask_rcu_no_null_check | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_insert_remove_no_release | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_invalid_nested_array | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_mutate_cpumask | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_populate_invalid_destination | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o:test_populate_invalid_source | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/dummy_st_ops_fail.bpf.o:test_unsupported_field_sleepable | struct_ops.s/test_2 | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma_fail1.bpf.o:handle_getpid | raw_tp/sys_enter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/find_vma_fail2.bpf.o:handle_getpid | raw_tp/sys_enter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/for_each_map_elem_write_key.bpf.o:test_map_key_write | raw_tp/sys_enter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/freplace_unreliable_prog.bpf.o:replace_btf_unreliable_kprobe | freplace/btf_unreliable_kprobe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/get_branch_snapshot.bpf.o:test1 | fexit/bpf_testmod_loop_test | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_empty | raw_tp/sys_enter | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_full | raw_tp/sys_enter | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_getter_after_bad | raw_tp | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_getter_before_bad | raw_tp | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_getter_good | socket | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/iters_testmod_seq.bpf.o:testmod_seq_truncated | raw_tp/sys_enter | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/jeq_infer_not_null_fail.bpf.o:jeq_infer_not_null_ptr_to_btfid | raw_tp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/jit_probe_mem.bpf.o:test_jit_probe_mem | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_destructive.bpf.o:kfunc_destructive_test | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_call_test_get_mem_fail_not_const | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_call_test_get_mem_fail_oob | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_call_test_get_mem_fail_rdonly | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_call_test_get_mem_fail_use_after_free | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_call_test_mem_acquire_fail | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_call_test_pointer_arg_type_mismatch | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_syscall_test_fail | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_fail.bpf.o:kfunc_syscall_test_null_fail | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_race.bpf.o:kfunc_call_fail | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_ctx | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test1 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test2 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test4 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test_get_mem | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test_pass | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test_ref_btf_id | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_call_test_static_unused_arg | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_syscall_test | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test.bpf.o:kfunc_syscall_test_null | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_call_test_subprog.bpf.o:kfunc_call_test1 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_implicit_args.bpf.o:test_kfunc_implicit_arg | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_implicit_args.bpf.o:test_kfunc_implicit_arg_impl_illegal | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_implicit_args.bpf.o:test_kfunc_implicit_arg_legacy | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kfunc_implicit_args.bpf.o:test_kfunc_implicit_arg_legacy_impl | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_multi_verifier.bpf.o:kprobe_session_return_2 | kprobe.session | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_write_ctx.bpf.o:kprobe_multi_write_ctx | kprobe.multi | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/kprobe_write_ctx.bpf.o:kprobe_write_ctx | kprobe | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ksym_race.bpf.o:ksym_fail | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop3.bpf.o:while_true | raw_tracepoint/consume_skb | bpf_object__load failed: Argument list too long (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lsm_cgroup_nonvoid.bpf.o:nonvoid_socket_clone | lsm_cgroup/inet_csk_clone | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:count_ref | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_cgrp_map_kptr | tp_btf/cgroup_mkdir | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_inode_map_kptr | lsm/inode_unlink | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_ls_map_kptr_ref1 | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_ls_map_kptr_ref2 | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_ls_map_kptr_ref_del | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_map_in_map_kptr | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_map_kptr | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_map_kptr_ref1 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_map_kptr_ref2 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_map_kptr_ref3 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_sk_map_kptr | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o:test_task_map_kptr | lsm/inode_unlink | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:correct_btf_id_check_size | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:inherit_untrusted_on_walk | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:kptr_xchg_possibly_null | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:kptr_xchg_ref_state | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:mark_ref_as_untrusted_or_null | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:marked_as_untrusted_or_null | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:misaligned_access_read | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:misaligned_access_write | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:non_const_var_off | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:non_const_var_off_kptr_xchg | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_bad_type_match | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_bad_type_xchg | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_indirect_global_func_access | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_indirect_helper_access | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_kptr_xchg_on_unref | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_member_of_ref_xchg | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_untrusted_store_to_ref | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_untrusted_xchg | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:reject_var_off_store | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_fail.bpf.o:size_not_bpf_dw | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:count_ref | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:htab_map_free | fexit/htab_map_free | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:map_put | fentry/bpf_map_put | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:sk_map_free | fexit/bpf_sk_storage_map_free | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:test_htab_leak | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:test_percpu_htab_leak | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr_race.bpf.o:test_sk_ls_leak | tp_btf/inet_sock_set_state | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe.bpf.o:test1 | kprobe/bpf_fentry_test1 | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe.bpf.o:test2 | kprobe/bpf_kfunc_common_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe.bpf.o:trigger | fentry/bpf_modify_return_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:test1 | kprobe.multi/bpf_fentry_test1 | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:test2 | kprobe/bpf_kfunc_common_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:test3 | kprobe/bpf_kfunc_common_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:test4 | kprobe/bpf_kfunc_common_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:test5 | kprobe.multi/bpf_kfunc_common_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:test6 | kprobe.session/bpf_kfunc_common_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/missed_kprobe_recursion.bpf.o:trigger | fentry/bpf_modify_return_test | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_acquire.bpf.o:test_nested_acquire_nonzero | tp_btf/tcp_probe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_acquire.bpf.o:test_nested_acquire_zero | tp_btf/tcp_probe | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_failure.bpf.o:test_invalid_nested_user_cpus | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/nested_trust_failure.bpf.o:test_invalid_skb_field | tp_btf/tcp_probe | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_freplace_prog.bpf.o:new_xdp_prog2 | freplace/xdp_prog1 | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/raw_tp_null.bpf.o:test_raw_tp_null | tp_btf/bpf_testmod_test_raw_tp_null_tp | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/raw_tp_null_fail.bpf.o:test_raw_tp_null_bpf_testmod_test_raw_tp_null_arg_1 | tp_btf/bpf_testmod_test_raw_tp_null_tp | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/raw_tp_null_fail.bpf.o:test_raw_tp_null_sched_pi_setprio_arg_2 | tp_btf/sched_pi_setprio | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/rcu_tasks_trace_gp.bpf.o:call_rcu_tasks_trace | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:close_sock | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:init_sock | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:kernel_bind | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:kernel_connect | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:kernel_getpeername | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:kernel_getsockname | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:kernel_listen | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:kernel_sendmsg | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_addr_kern.bpf.o:sock_sendmsg | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/sock_destroy_prog_fail.bpf.o:trace_tcp_destroy_sock | tp_btf/tcp_destroy_sock | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o:fentry_test | fentry/bpf_testmod_stacktrace_test | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/stacktrace_ips.bpf.o:fexit_test | fexit/bpf_testmod_stacktrace_test | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization_freplace.bpf.o:changes_pkt_data | freplace | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization_freplace.bpf.o:does_not_change_pkt_data | freplace | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization_freplace.bpf.o:does_not_sleep | freplace | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization_freplace.bpf.o:might_sleep | freplace | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_fentry.bpf.o:fentry | fentry/subprog_tail | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_fexit.bpf.o:fexit | fexit/subprog_tail | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_hierarchy_fentry.bpf.o:fentry | fentry/dummy | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm1 | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm2 | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm3 | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_access_comm4 | fentry/__set_task_comm | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_fp | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_null | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_release_no_null_check | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_unreleased | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_unsafe_kretprobe | kretprobe/free_task | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_unsafe_kretprobe_rcu | kretprobe/free_task | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_acquire_untrusted | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_from_lsm_task_free | lsm/task_free | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_from_pid_no_null_check | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_from_vpid_no_null_check | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_fp | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_in_map | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_null | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_unacquired | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_release_untrusted | tp_btf/task_newtask | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o:task_kfunc_xchg_unreleased | tp_btf/task_newtask | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:cong_avoid | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:cong_control | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:cwnd_event | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:in_ack_event | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:init | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:min_tso_segs | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:pkts_acked | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:set_state | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:sndbuf_expand | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:ssthresh | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_kfunc.bpf.o:undo_cwnd | struct_ops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tcp_ca_unsupp_cong_op.bpf.o:unsupp_cong_op_get_info | struct_ops | bpf_object__load failed: Unknown error 524 (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_autoload.bpf.o:prog3 | fentry/unexisting-kprobe-will-fail-if-loaded | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf.bpf.o:nf_skb_ct_test | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf.bpf.o:nf_xdp_ct_test | xdp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:alloc_release | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:change_status_after_alloc | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:change_timeout_after_alloc | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:insert_insert | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_insert | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:lookup_null_bpf_opts | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:set_status_after_insert | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:set_timeout_after_insert | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:write_not_allowlisted_field | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf_fail.bpf.o:xdp_lookup_null_bpf_opts | xdp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_cgroup1_hierarchy.bpf.o:fentry_run | fentry | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_reloc_module.bpf.o:test_core_module_direct | tp_btf/bpf_testmod_test_read | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_reloc_module.bpf.o:test_core_module_probed | raw_tp/bpf_testmod_test_read | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o:abc1 | abc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o:abc2 | abc/whatever | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o:custom1 | custom | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o:custom2 | custom/something | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_custom_sec_handlers.bpf.o:xyz | xyz/blah | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_rdonly_mem.bpf.o:d_path_check_rdonly_mem | fentry/security_inode_getattr | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_types.bpf.o:d_path_check_rdonly_mem | fentry/security_inode_getattr | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_func17.bpf.o:global_func17 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_map_resize.bpf.o:bss_array_sum | tp/syscalls/sys_enter_getpid | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_map_resize.bpf.o:data_array_sum | tp/syscalls/sys_enter_getuid | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_global_map_resize.bpf.o:test_1 | struct_ops/test_1 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o:not_ptr_to_stack | lsm.s/bpf | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kfunc_dynptr_param.bpf.o:not_valid_dynptr | lsm.s/bpf | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_null_check.bpf.o:handler | raw_tp/sys_enter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_write_check.bpf.o:handler1 | raw_tp/sys_enter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_btf_write_check.bpf.o:handler2 | raw_tp/sys_enter | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_module.bpf.o:load | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_module.bpf.o:load_256 | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_weak.bpf.o:pass_handler | raw_tp/sys_enter | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ldsx_insn.bpf.o:test_ptr_struct_arg | fentry/bpf_testmod_test_arg_ptr_to_struct | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o:entry | raw_tp/sys_enter | bpf_object__load failed: Bad file descriptor (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sk_storage_trace_itself.bpf.o:trace_bpf_sk_storage_free | fentry/bpf_sk_storage_free | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_sockmap_invalid_update.bpf.o:bpf_sockmap | sockops | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_extable.bpf.o:handle_fexit_ret_subprogs | fexit/bpf_testmod_return_ptr | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_extable.bpf.o:handle_fexit_ret_subprogs2 | fexit/bpf_testmod_return_ptr | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs_extable.bpf.o:handle_fexit_ret_subprogs3 | fexit/bpf_testmod_return_ptr | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_trace_ext_tracing.bpf.o:fentry | fentry/test_pkt_md_access_new | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_trace_ext_tracing.bpf.o:fexit | fexit/test_pkt_md_access_new | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o:test_regs_change | uprobe | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_uprobe.bpf.o:test_regs_change_ip | uprobe | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_devmap_tailcall.bpf.o:xdp_devmap | xdp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_devmap_tailcall.bpf.o:xdp_entry | xdp | bpf_object__load failed: Bad file descriptor (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_failure.bpf.o:fexit_noreturns | fexit/do_exit | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_failure.bpf.o:tracing_deny | fentry/__rcu_read_lock | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_1 | fentry/bpf_testmod_test_struct_arg_1 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_10 | fexit/bpf_testmod_test_struct_arg_5 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_11 | fentry/bpf_testmod_test_struct_arg_6 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_2 | fexit/bpf_testmod_test_struct_arg_1 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_3 | fentry/bpf_testmod_test_struct_arg_2 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_4 | fexit/bpf_testmod_test_struct_arg_2 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_5 | fentry/bpf_testmod_test_struct_arg_3 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_6 | fexit/bpf_testmod_test_struct_arg_3 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_7 | fentry/bpf_testmod_test_struct_arg_4 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_8 | fexit/bpf_testmod_test_struct_arg_4 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_struct_arg_9 | fentry/bpf_testmod_test_struct_arg_5 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_union_arg_1 | fexit/bpf_testmod_test_union_arg_1 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct.bpf.o:test_union_arg_2 | fexit/bpf_testmod_test_union_arg_2 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o:test_struct_many_args_1 | fentry/bpf_testmod_test_struct_arg_7 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o:test_struct_many_args_2 | fexit/bpf_testmod_test_struct_arg_7 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o:test_struct_many_args_3 | fentry/bpf_testmod_test_struct_arg_8 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o:test_struct_many_args_4 | fexit/bpf_testmod_test_struct_arg_8 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o:test_struct_many_args_5 | fentry/bpf_testmod_test_struct_arg_9 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/tracing_struct_many_args.bpf.o:test_struct_many_args_6 | fexit/bpf_testmod_test_struct_arg_9 | bpf_object__load failed: No such process (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi_verifier.bpf.o:uprobe_sesison_return_2 | uprobe.session | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:basic_alloc3_nosleep | socket | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:iter_maps2 | iter.s/bpf_map | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_arena.bpf.o:iter_maps3 | iter.s/bpf_map | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:destroy_uninit | iter/cgroup | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:next_uninit | iter/cgroup | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o:no_destroy | iter.s/cgroup | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:bprm | lsm.s/bprm_committed_creds | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx1 | tc/ingress | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx4 | tc/ingress | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_const.bpf.o:tcx7 | tc/ingress | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:context_stores_via_bpf_atomic | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:ctx_pointer_to_helper_1 | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:ctx_pointer_to_helper_2 | socket | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:ctx_pointer_to_helper_3 | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_load__sk_buffsk | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sock_addrsk | cgroup/bind4 | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sock_opssk | sockops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sock_opsskb_data | sockops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sock_opsskb_data_end | sockops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sock_opsskb_hwtstamp | sockops | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sockoptoptval | cgroup/getsockopt | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sockoptoptval_end | cgroup/getsockopt | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:invalid_narrow_loadbpf_sockoptsk | cgroup/getsockopt | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:make_ptr_to_ctx_unusable | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:null_check_4_ctx_const | cgroup/sendmsg6 | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:null_check_8_null_bind | cgroup/post_bind4 | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:or_null_check_3_1 | cgroup/sendmsg6 | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:padding_ctx_access___sk_buff | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:padding_ctx_access_bpf_sock | cgroup/post_bind4 | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:padding_ctx_access_bpf_sock_addr | cgroup/bind4 | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:padding_ctx_access_sk_reuseport_md | sk_reuseport | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unaligned_ctx_access___sk_buffdata | flow_dissector | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o:unaligned_ctx_access_bpf_nf_ctxskb | netfilter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_default_trusted_ptr.bpf.o:test_default_trusted_ptr | syscall | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cgrp_kfunc_raw_tp | raw_tp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:cpumask_kfunc_raw_tp | raw_tp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o:task_kfunc_raw_tp | raw_tp | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:bool_retval_test3 | lsm/audit_rule_known | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:bool_retval_test4 | lsm/audit_rule_known | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:disabled_hook_test1 | lsm/getprocattr | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:disabled_hook_test2 | lsm/setprocattr | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:disabled_hook_test3 | lsm/ismaclabel | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test4 | lsm/file_mprotect | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test5 | lsm/file_mprotect | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_lsm.bpf.o:errno_zero_retval_test6 | lsm/file_mprotect | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o:with_invalid_ctx_access_test1 | netfilter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o:with_invalid_ctx_access_test2 | netfilter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o:with_invalid_ctx_access_test3 | netfilter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o:with_invalid_ctx_access_test4 | netfilter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_netfilter_ctx.bpf.o:with_invalid_ctx_access_test5 | netfilter | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_unpriv_perf.bpf.o:fill_of_different_pointers_ldx | perf_event | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_flowtable.bpf.o:xdp_flowtable_do_lookup | xdp.frags | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_hw_metadata.bpf.o:rx | xdp.frags | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o:rx | xdp | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata2.bpf.o:freplace_rx | freplace/rx | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xfrm_info.bpf.o:get_xfrm_info | tc | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xfrm_info.bpf.o:set_xfrm_info | tc | bpf_object__load failed: Invalid argument (exit=1) |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_prog_test_run_opts failed: Unknown error 524 (exit=1) | 422 |
| bpf_object__load failed: Invalid argument (exit=1) | 250 |
| bpf_prog_test_run_opts failed: Bad address (exit=1) | 116 |
| bpf_object__load failed: Permission denied (exit=1) | 81 |
| bpf_object__load failed: No such process (exit=1) | 67 |
| bpf_prog_test_run_opts failed: Operation not supported (exit=1) | 32 |
| bpf_prog_test_run_opts failed: Invalid argument (exit=1) | 13 |
| bpf_object__load failed: Bad file descriptor (exit=1) | 2 |
| bpf_object__load failed: No such file or directory (exit=1) | 1 |
| bpf_object__load failed: Argument list too long (exit=1) | 1 |

## Inventory Failures

| Object | Failure |
| --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bitfield_vs_int.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bitfield_vs_int.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___err_too_big_bitfield.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___err_too_big_bitfield.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___just_big_enough.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___just_big_enough.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___err_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___err_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___val3_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___val3_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___err_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___err_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___val3_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___val3_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___minimal.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___minimal.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___wrong_field_defs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___wrong_field_defs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors__err_wrong_name.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors__err_wrong_name.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___bool.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___bool.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___reverse_sign.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___reverse_sign.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_misc.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_misc.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___mod_swap.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___mod_swap.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___typedefs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___typedefs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___anon_embed.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___anon_embed.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___dup_compat_types.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___dup_compat_types.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_field.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_field.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_dup_incompat_types.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_dup_incompat_types.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_field.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_field.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_nonstruct_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_nonstruct_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_partial_match_dups.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_partial_match_dups.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_too_deep.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_too_deep.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___extra_nesting.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___extra_nesting.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___struct_union_mixup.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___struct_union_mixup.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_enum_def.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_enum_def.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_func_proto.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_func_proto.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_ptr_type.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_ptr_type.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_enum.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_enum.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_int.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_int.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_ptr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_ptr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_offs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_offs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___err_ambiguous.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___err_ambiguous.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___all_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___all_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___fn_wrong_args.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___fn_wrong_args.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___incompat.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___incompat.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id___missing_targets.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id___missing_targets.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_data.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_data.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_bitfields.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_bitfields.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_multidim.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_multidim.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_namespacing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_namespacing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_ordering.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_ordering.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_packing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_packing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_padding.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_padding.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_syntax.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_syntax.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_funcs1.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_funcs2.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_maps1.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_maps2.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_vars1.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/linked_vars2.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_map.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/priv_map.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_pinning_htab.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_pinning_htab.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt_multispec.bpf.o | bpf_object__open_file failed: No such file or directory (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uptr_map_failure.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uptr_map_failure.bpf.o (exit=1) |

## Notes

- Discovery reuses `micro/directive_census.py` filtering, so only `EM_BPF` corpus objects are executed.
- Execution uses the existing `micro_exec run-kernel` path with `bpf_prog_test_run_opts` and scanner-backed `--recompile-all`.
- Non-runnable programs are expected in this corpus. The harness records load-only success separately from full runtime success.
- Packet programs use the synthetic 64-byte Ethernet/IPv4/TCP packet, while non-packet programs use `context` mode with empty or zero-filled `ctx_in`.

