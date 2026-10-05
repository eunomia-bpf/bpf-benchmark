# Code Size by Program Type

- Generated: 2026-03-12T01:55:24.958601+00:00
- Mode: `actual measurement attempt`
- Kernel release: `7.0.0-rc2-ge52504a75c05`
- Host: `virtme-ng`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Object roots requested: `corpus/expanded_corpus`, `corpus/objects`, `corpus/build`
- Object roots used: `corpus/build`
- Missing object roots skipped: `corpus/expanded_corpus`, `corpus/objects`
- Reference runnability inventory: `docs/tmp/corpus-runnability-results.json` (programs_found=1836, loadable_programs=1214)
- v5 support status: `supported`

## Summary

| Metric | Value |
| --- | --- |
| Objects scanned | 560 |
| Objects with successful program discovery | 463 |
| Objects with discovery failures | 97 |
| Programs discovered | 2010 |
| Loadable programs | 1208 |
| Compile pairs with usable stock/v5 code size | 1183 |
| Programs with v5-detected sites | 421 |
| Programs with recompile applied | 414 |
| Programs with recompile failures | 25 |
| Overall geomean code-size ratio (recompile/stock) | 1.003x |
| Overall median code-size delta | +0.0% |

## By Program Type

| Prog Type | Programs | Loadable | Compile Pairs | Site+ | Applied | Recompile Failures | Geomean R/S | Median Delta |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| kprobe | 266 | 206 | 206 | 84 | 84 | 0 | 1.002x | +0.0% |
| tracepoint | 166 | 129 | 129 | 28 | 28 | 0 | 1.002x | +0.0% |
| sched_cls | 202 | 109 | 106 | 87 | 85 | 3 | 1.001x | +0.0% |
| raw_tracepoint | 118 | 86 | 86 | 44 | 44 | 0 | 1.004x | +0.0% |
| fentry | 133 | 82 | 82 | 7 | 7 | 0 | 1.005x | +0.0% |
| uprobe | 125 | 80 | 80 | 27 | 27 | 0 | 1.003x | +0.0% |
| kretprobe | 105 | 79 | 79 | 40 | 40 | 0 | 1.008x | +0.0% |
| tp_btf | 191 | 55 | 55 | 9 | 9 | 0 | 1.006x | +0.0% |
| struct_ops | 111 | 51 | 41 | 11 | 11 | 10 | 1.003x | +0.0% |
| syscall | 85 | 51 | 50 | 4 | 3 | 1 | 1.002x | +0.0% |
| xdp | 115 | 44 | 43 | 27 | 26 | 1 | 1.000x | +0.0% |
| iter | 50 | 42 | 38 | 7 | 6 | 4 | 1.003x | +0.0% |
| lsm | 83 | 36 | 34 | 10 | 10 | 2 | 1.012x | +0.0% |
| fexit | 72 | 27 | 27 | 2 | 2 | 0 | 1.004x | +0.0% |
| uretprobe | 32 | 22 | 22 | 0 | 0 | 0 | 1.000x | +0.0% |
| usdt | 21 | 21 | 21 | 12 | 12 | 0 | 1.000x | +0.0% |
| perf_event | 21 | 18 | 18 | 4 | 4 | 0 | 1.006x | +0.0% |
| cgroup_sockopt | 14 | 11 | 10 | 1 | 0 | 1 | 1.000x | +0.0% |
| socket_filter | 10 | 8 | 8 | 2 | 2 | 0 | 1.006x | +0.0% |
| sock_ops | 12 | 7 | 5 | 0 | 0 | 2 | 1.000x | +0.0% |
| flow_dissector | 8 | 7 | 7 | 4 | 4 | 0 | 1.001x | +0.2% |
| cgroup_sock_addr | 12 | 6 | 6 | 0 | 0 | 0 | 1.000x | +0.0% |
| cgroup_skb | 8 | 6 | 6 | 3 | 3 | 0 | 0.974x | +0.0% |
| sk_msg | 5 | 5 | 5 | 3 | 3 | 0 | 1.015x | +2.5% |
| sk_skb | 5 | 5 | 5 | 0 | 0 | 0 | 1.000x | +0.0% |
| fmod_ret | 6 | 4 | 4 | 1 | 1 | 0 | 1.000x | +0.0% |
| netfilter | 9 | 3 | 3 | 2 | 2 | 0 | 1.005x | +0.0% |
| cgroup_sock | 5 | 3 | 3 | 0 | 0 | 0 | 1.000x | +0.0% |
| sk_reuseport | 4 | 3 | 3 | 1 | 1 | 0 | 0.944x | +0.0% |
| cgroup_sysctl | 1 | 1 | 0 | 1 | 0 | 1 | n/a | n/a |
| sk_lookup | 1 | 1 | 1 | 0 | 0 | 0 | 1.000x | +0.0% |
| ext | 7 | 0 | 0 | 0 | 0 | 0 | n/a | n/a |
| unspec | 7 | 0 | 0 | 0 | 0 | 0 | n/a | n/a |

## Largest Shrinks

| Program | Prog Type | Stock JIT | v5 JIT | R/S | Delta | Applied | Sites |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o:reuse_accept | sk_reuseport | 572 | 481 | 0.841x | -15.9% | yes | 7 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:inet_sock_set_state | tracepoint | 1913 | 1749 | 0.914x | -8.6% | yes | 23 |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress | cgroup_skb | 19383 | 17799 | 0.918x | -8.2% | yes | 132 |
| corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress | cgroup_skb | 19383 | 17799 | 0.918x | -8.2% | yes | 132 |
| corpus/build/calico/from_hep_debug.bpf.o:calico_tc_maglev | sched_cls | 3260 | 3117 | 0.956x | -4.4% | yes | 13 |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | sched_cls | 549 | 530 | 0.965x | -3.5% | yes | 6 |
| corpus/build/coroot-node-agent/ebpf.bpf.o:nf_ct_deliver_cached_events | kprobe | 301 | 291 | 0.967x | -3.3% | yes | 2 |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | sched_cls | 111 | 108 | 0.973x | -2.7% | yes | 1 |
| corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o:tc_ingress | sched_cls | 111 | 108 | 0.973x | -2.7% | yes | 1 |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | 13412 | 13101 | 0.977x | -2.3% | yes | 94 |
| corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main | xdp | 1816 | 1777 | 0.979x | -2.1% | yes | 8 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o:decap_f | sched_cls | 696 | 683 | 0.981x | -1.9% | yes | 3 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o:sys_enter | raw_tracepoint | 175 | 172 | 0.983x | -1.7% | yes | 3 |
| corpus/build/calico/xdp_debug.bpf.o:calico_xdp_main | xdp | 4427 | 4365 | 0.986x | -1.4% | yes | 12 |
| corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o:socket_handler | socket_filter | 374 | 369 | 0.987x | -1.3% | yes | 1 |

## Largest Growths

| Program | Prog Type | Stock JIT | v5 JIT | R/S | Delta | Applied | Sites |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog3 | raw_tracepoint | 41 | 47 | 1.146x | +14.6% | yes | 1 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_overhead.bpf.o:prog1 | kprobe | 42 | 48 | 1.143x | +14.3% | yes | 1 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_kernel_flag.bpf.o:bpf | lsm | 81 | 92 | 1.136x | +13.6% | yes | 2 |
| corpus/build/bcc/libbpf-tools/funclatency.bpf.o:dummy_kretprobe | kretprobe | 466 | 523 | 1.122x | +12.2% | yes | 9 |
| corpus/build/linux-selftests/test_tc_bpf.bpf.o:pkt_ptr | sched_cls | 53 | 59 | 1.113x | +11.3% | yes | 1 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:mark_page_accessed | fentry | 432 | 480 | 1.111x | +11.1% | yes | 8 |
| corpus/build/bcc/libbpf-tools/readahead.bpf.o:folio_mark_accessed | fentry | 437 | 485 | 1.110x | +11.0% | yes | 8 |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_read_exit | kretprobe | 519 | 576 | 1.110x | +11.0% | yes | 10 |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:getattr_exit | kretprobe | 522 | 579 | 1.109x | +10.9% | yes | 10 |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_write_exit | kretprobe | 522 | 579 | 1.109x | +10.9% | yes | 10 |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_sync_exit | kretprobe | 522 | 579 | 1.109x | +10.9% | yes | 10 |
| corpus/build/bcc/libbpf-tools/fsdist.bpf.o:file_open_exit | kretprobe | 522 | 579 | 1.109x | +10.9% | yes | 10 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o:fexit_module_get | fexit | 56 | 62 | 1.107x | +10.7% | yes | 1 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_perf_skip.bpf.o:handler | perf_event | 61 | 67 | 1.098x | +9.8% | yes | 1 |
| corpus/build/bcc/libbpf-tools/biostacks.bpf.o:block_io_done | tp_btf | 596 | 653 | 1.096x | +9.6% | yes | 10 |

## Object Discovery Failures

| Reason | Count |
| --- | --- |
| bpf_object__open_file failed: No such file or directory | 8 |
| bpf_object__open_file failed: Operation not supported | 7 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/minimal_sched_ext.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o | 1 |
| no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o | 1 |

## Load Failures

| Reason | Count |
| --- | --- |
| bpf_object__load failed: No data available | 412 |
| bpf_object__load failed: Invalid argument | 306 |
| bpf_object__load failed: No such process | 46 |
| bpf_object__load failed: Permission denied | 35 |
| bpf_object__load failed: Unknown error 524 | 1 |
| bpf_object__load failed: Bad file descriptor | 1 |
| bpf_object__load failed: Argument list too long | 1 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| bpf_object__load failed: No data available | 18 |
| BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) | 5 |
| BPF_PROG_JIT_RECOMPILE failed: Argument list too long (errno=7) | 2 |

## Notes

- The harness enumerates programs with `micro_exec list-programs`, then runs `run-kernel --compile-only` once for stock and once for `--recompile-v5 --recompile-all`.
- Program-type grouping refines generic libbpf `prog_type_name` using section roots so `fentry`, `fexit`, `lsm`, `raw_tracepoint`, and `sched_cls` remain separate buckets.
- When the older `corpus/expanded_corpus` and `corpus/objects` paths are absent, the harness falls back to the current canonical `corpus/build` tree from `corpus/config/corpus_manifest.yaml`.
- Ratios are `recompile_jitted_len / stock_jitted_len`; values below `1.0x` mean smaller native code after recompile.
- Equivalent VM rerun command: `vng --run vendor/linux-framework/arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark --disable-monitor --cpus 1 --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp --rwdir /home/yunwei37/workspace/bpf-benchmark/corpus/results --exec 'sudo -n python3 corpus/run_code_size_comparison.py --output-json corpus/results/code_size_full_vm_20260312.json --output-md docs/tmp/code-size-full-vm-results.md'`
