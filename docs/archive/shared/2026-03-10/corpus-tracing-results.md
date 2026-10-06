# Corpus Tracing Runtime Results

- Generated: 2026-03-10T20:45:41.844097+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.json`
- Objects discovered: 19
- Programs found: 87
- Supported by harness: 43
- Measured programs: 39
- Programs with positive run_cnt delta: 35
- Zero-run programs: 4
- Attach failures: 4
- Skipped programs: 44
- Directive-bearing programs: 36
- Directive-bearing measured programs: 17

## Summary Statistics

| Metric | Value |
| --- | --- |
| Average ns/run min | 25.56 |
| Average ns/run max | 1176.16 |

## Measured Programs

| Program | Section | Trigger | Runs | Run time ns | Avg ns/run | Recompile Applied | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_done | tp_btf/block_io_done | disk-io | 200 | 21750 | 108.75 | no | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_complete_btf | tp_btf/block_rq_complete | disk-io | 250 | 32002 | 128.01 | no | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_complete | raw_tp/block_rq_complete | disk-io | 250 | 41311 | 165.24 | no | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_switch | tp_btf/sched_switch | sched | 1131 | 227635 | 201.27 | no | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_switch | raw_tp/sched_switch | sched | 972 | 200081 | 205.84 | no | 6 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:folio_mark_accessed | fentry/folio_mark_accessed | disk-io | 16071 | 817154 | 50.85 | no | 5 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv | fentry/tcp_rcv_established | tcp-loopback | 227 | 27383 | 120.63 | no | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/bitesize.bpf.o:block_rq_issue | tp_btf/block_rq_issue | disk-io | 202 | 37119 | 183.76 | no | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv_kprobe | kprobe/tcp_v4_syn_recv_sock | tcp-loopback | 50 | 9419 | 188.38 | no | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcpsynbl.bpf.o:tcp_v4_syn_recv | fentry/tcp_v4_syn_recv_sock | tcp-loopback | 50 | 10900 | 218.00 | no | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/tcprtt.bpf.o:tcp_rcv_kprobe | kprobe/tcp_rcv_established | tcp-loopback | 247 | 59384 | 240.42 | no | 4 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_write_entry | kprobe/vfs_write | write-devnull | 53 | 3642 | 68.72 | no | 2 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcpify.bpf.o:mptcpify | fmod_ret/update_socket_protocol | tcp-loopback | 80 | 10044 | 125.55 | no | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler_exit | tp/syscalls/sys_exit_getpid | generic-syscalls | 164 | 37644 | 229.54 | no | 1 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:block_io_done | tp_btf/block_io_done | disk-io | 200 | 48733 | 243.66 | no | 1 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biopattern.bpf.o:handle__block_rq_complete | tracepoint/block/block_rq_complete | disk-io | 250 | 82154 | 328.62 | no | 1 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_merge_bio | kprobe/blk_account_io_merge_bio | disk-io | 366 | 258315 | 705.78 | no | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_signed | raw_tp/sys_exit | generic-syscalls | 8749 | 223638 | 25.56 | no | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_signed | tp/raw_syscalls/sys_exit | generic-syscalls | 1815 | 77679 | 42.80 | no | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler32_unsigned | tp/raw_syscalls/sys_enter | generic-syscalls | 1926 | 85883 | 44.59 | no | 0 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o:handler64_unsigned | raw_tp/sys_enter | generic-syscalls | 1857 | 101300 | 54.55 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink | kprobe/vfs_unlink | unlink | 50 | 2784 | 55.68 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink_ret | kretprobe/vfs_unlink | unlink | 50 | 3210 | 64.20 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:filemap_alloc_folio_noprof_ret | fexit/filemap_alloc_folio_noprof | disk-io | 348 | 24910 | 71.58 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_open | kprobe/vfs_open | open-close | 51 | 4369 | 85.67 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:block_io_start | tp_btf/block_io_start | disk-io | 150 | 51070 | 340.47 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup_new | tp_btf/sched_wakeup_new | sched | 50 | 17509 | 350.18 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue | raw_tp/block_rq_issue | disk-io | 201 | 74042 | 368.37 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup_new | raw_tp/sched_wakeup_new | sched | 50 | 19545 | 390.90 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue_btf | tp_btf/block_rq_issue | disk-io | 202 | 88755 | 439.38 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:sched_wakeup | tp_btf/sched_wakeup | sched | 407 | 225327 | 553.63 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_insert | raw_tp/block_rq_insert | disk-io | 50 | 27959 | 559.18 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_wakeup | raw_tp/sched_wakeup | sched | 465 | 267655 | 575.60 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_insert_btf | tp_btf/block_rq_insert | disk-io | 50 | 42243 | 844.86 | no | 0 | 0 | 0 | 0 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_start | tp_btf/block_io_start | disk-io | 150 | 176424 | 1176.16 | no | 0 | 0 | 0 | 0 |

## Attach Or Measurement Failures

| Program | Section | Trigger | Failure |
| --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:do_page_cache_ra | fentry/do_page_cache_ra | disk-io | bpf_object__load failed: No such process |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:do_page_cache_ra_ret | fexit/do_page_cache_ra | disk-io | bpf_object__load failed: No such process |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:filemap_alloc_folio_ret | fexit/filemap_alloc_folio | disk-io | bpf_object__load failed: No such process |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:page_cache_alloc_ret | fexit/__page_cache_alloc | disk-io | bpf_object__load failed: No such process |

## Skipped Programs

| Program | Section | Reason |
| --- | --- | --- |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_done | fentry/blk_account_io_done | no trigger heuristic for section `fentry/blk_account_io_done` / program `blk_account_io_done` |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:blk_account_io_start | fentry/blk_account_io_start | no trigger heuristic for section `fentry/blk_account_io_start` / program `blk_account_io_start` |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:__blk_account_io_done | kprobe/__blk_account_io_done | no trigger heuristic for section `kprobe/__blk_account_io_done` / program `__blk_account_io_done` |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:__blk_account_io_start | kprobe/__blk_account_io_start | no trigger heuristic for section `kprobe/__blk_account_io_start` / program `__blk_account_io_start` |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_account_io_done | kprobe/blk_account_io_done | no trigger heuristic for section `kprobe/blk_account_io_done` / program `blk_account_io_done` |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_account_io_start | kprobe/blk_account_io_start | no trigger heuristic for section `kprobe/blk_account_io_start` / program `blk_account_io_start` |
| corpus/build/bcc/libbpf-tools/biotop.bpf.o:blk_mq_start_request | kprobe/blk_mq_start_request | no trigger heuristic for section `kprobe/blk_mq_start_request` / program `blk_mq_start_request` |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:security_inode_create | kprobe/security_inode_create | no trigger heuristic for section `kprobe/security_inode_create` / program `security_inode_create` |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_create | kprobe/vfs_create | no trigger heuristic for section `kprobe/vfs_create` / program `vfs_create` |
| corpus/build/bcc/libbpf-tools/filetop.bpf.o:vfs_read_entry | kprobe/vfs_read | no trigger heuristic for section `kprobe/vfs_read` / program `vfs_read_entry` |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_entry | kprobe/dummy_file_open | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_exit | kretprobe/dummy_file_open | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_fentry | fentry/dummy_file_open | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_fexit | fexit/dummy_file_open | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_entry | kprobe/dummy_file_read | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_exit | kretprobe/dummy_file_read | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_fentry | fentry/dummy_file_read | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_fexit | fexit/dummy_file_read | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_entry | kprobe/dummy_file_sync | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_exit | kretprobe/dummy_file_sync | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_fentry | fentry/dummy_file_sync | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_fexit | fexit/dummy_file_sync | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_entry | kprobe/dummy_file_write | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_exit | kretprobe/dummy_file_write | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_fentry | fentry/dummy_file_write | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_fexit | fexit/dummy_file_write | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_entry | kprobe/dummy_getattr | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_exit | kretprobe/dummy_getattr | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_fentry | fentry/dummy_getattr | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_fexit | fexit/dummy_getattr | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_fentry | fentry/dummy_fentry | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_fexit | fexit/dummy_fexit | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kprobe | kprobe/dummy_kprobe | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kretprobe | kretprobe/dummy_kretprobe | dynamic attach target placeholder |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o:kprobe_entry | kprobe/foo | no trigger heuristic for section `kprobe/foo` / program `kprobe_entry` |
| corpus/build/bcc/libbpf-tools/ksnoop.bpf.o:kprobe_return | kretprobe/foo | no trigger heuristic for section `kretprobe/foo` / program `kprobe_return` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o:fexit_init_module | fexit/do_init_module | no trigger heuristic for section `fexit/do_init_module` / program `fexit_init_module` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o:fexit_module_get | fexit/btf_try_get_module | no trigger heuristic for section `fexit/btf_try_get_module` / program `fexit_module_get` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lru_bug.bpf.o:nanosleep | fentry/do_nanosleep | no trigger heuristic for section `fentry/do_nanosleep` / program `nanosleep` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/lru_bug.bpf.o:printk | fentry/bpf_ktime_get_ns | no trigger heuristic for section `fentry/bpf_ktime_get_ns` / program `printk` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog1 | kprobe/__set_task_comm | no trigger heuristic for section `kprobe/__set_task_comm` / program `prog1` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog2 | kretprobe/__set_task_comm | no trigger heuristic for section `kretprobe/__set_task_comm` / program `prog2` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog4 | fentry/__set_task_comm | no trigger heuristic for section `fentry/__set_task_comm` / program `prog4` |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog5 | fexit/__set_task_comm | no trigger heuristic for section `fexit/__set_task_comm` / program `prog5` |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| dynamic attach target placeholder | 24 |
| bpf_object__load failed: No such process | 4 |
| no trigger heuristic for section `fentry/blk_account_io_start` / program `blk_account_io_start` | 1 |
| no trigger heuristic for section `fentry/blk_account_io_done` / program `blk_account_io_done` | 1 |
| no trigger heuristic for section `kprobe/blk_mq_start_request` / program `blk_mq_start_request` | 1 |
| no trigger heuristic for section `kprobe/blk_account_io_start` / program `blk_account_io_start` | 1 |
| no trigger heuristic for section `kprobe/blk_account_io_done` / program `blk_account_io_done` | 1 |
| no trigger heuristic for section `kprobe/__blk_account_io_start` / program `__blk_account_io_start` | 1 |
| no trigger heuristic for section `kprobe/__blk_account_io_done` / program `__blk_account_io_done` | 1 |
| no trigger heuristic for section `kprobe/vfs_create` / program `vfs_create` | 1 |
| no trigger heuristic for section `kprobe/security_inode_create` / program `security_inode_create` | 1 |
| no trigger heuristic for section `kprobe/vfs_read` / program `vfs_read_entry` | 1 |

## Notes

- This harness measures tracing-style programs through load + attach + trigger, then reads `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- `--recompile-all` is probed separately through `micro_exec run-kernel --compile-only`; attached re-JIT plus re-measure is not implemented in this script yet.
- Programs with placeholder section targets such as `kprobe/dummy_*` are skipped because the attach target is supplied dynamically by their original user-space tool.

