# Code Size by Program Type

- Generated: 2026-03-11T23:08:40.554041+00:00
- Mode: `dry-run inventory`
- Kernel release: `6.15.11-061511-generic`
- Host: `lab`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Object roots requested: `corpus/expanded_corpus`, `corpus/objects`, `corpus/build`
- Object roots used: `corpus/build`
- Missing object roots skipped: `corpus/expanded_corpus`, `corpus/objects`
- Reference runnability inventory: `docs/tmp/corpus-runnability-results.json` (programs_found=1836, loadable_programs=1214)
- v5 support status: `not_attempted`

## Summary

| Metric | Value |
| --- | --- |
| Objects scanned | 560 |
| Objects with successful program discovery | 463 |
| Objects with discovery failures | 97 |
| Programs discovered | 2010 |
| Loadable programs | 1282 |
| Compile pairs with usable stock/v5 code size | 0 |

## By Program Type

| Prog Type | Programs | Loadable | Compile Pairs | Site+ | Applied | Recompile Failures | Geomean R/S | Median Delta |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| kprobe | 266 | 209 | 0 | 0 | 0 | 0 | n/a | n/a |
| tracepoint | 166 | 130 | 0 | 0 | 0 | 0 | n/a | n/a |
| sched_cls | 202 | 110 | 0 | 0 | 0 | 0 | n/a | n/a |
| fentry | 133 | 88 | 0 | 0 | 0 | 0 | n/a | n/a |
| raw_tracepoint | 118 | 84 | 0 | 0 | 0 | 0 | n/a | n/a |
| uprobe | 125 | 80 | 0 | 0 | 0 | 0 | n/a | n/a |
| tp_btf | 191 | 79 | 0 | 0 | 0 | 0 | n/a | n/a |
| kretprobe | 105 | 79 | 0 | 0 | 0 | 0 | n/a | n/a |
| struct_ops | 111 | 70 | 0 | 0 | 0 | 0 | n/a | n/a |
| syscall | 85 | 53 | 0 | 0 | 0 | 0 | n/a | n/a |
| lsm | 83 | 49 | 0 | 0 | 0 | 0 | n/a | n/a |
| xdp | 115 | 46 | 0 | 0 | 0 | 0 | n/a | n/a |
| iter | 50 | 42 | 0 | 0 | 0 | 0 | n/a | n/a |
| fexit | 72 | 31 | 0 | 0 | 0 | 0 | n/a | n/a |
| uretprobe | 32 | 22 | 0 | 0 | 0 | 0 | n/a | n/a |
| usdt | 21 | 21 | 0 | 0 | 0 | 0 | n/a | n/a |
| perf_event | 21 | 19 | 0 | 0 | 0 | 0 | n/a | n/a |
| cgroup_sockopt | 14 | 11 | 0 | 0 | 0 | 0 | n/a | n/a |
| sock_ops | 12 | 7 | 0 | 0 | 0 | 0 | n/a | n/a |
| socket_filter | 10 | 7 | 0 | 0 | 0 | 0 | n/a | n/a |
| flow_dissector | 8 | 7 | 0 | 0 | 0 | 0 | n/a | n/a |
| cgroup_sock_addr | 12 | 6 | 0 | 0 | 0 | 0 | n/a | n/a |
| cgroup_skb | 8 | 6 | 0 | 0 | 0 | 0 | n/a | n/a |
| fmod_ret | 6 | 5 | 0 | 0 | 0 | 0 | n/a | n/a |
| sk_msg | 5 | 5 | 0 | 0 | 0 | 0 | n/a | n/a |
| sk_skb | 5 | 5 | 0 | 0 | 0 | 0 | n/a | n/a |
| netfilter | 9 | 3 | 0 | 0 | 0 | 0 | n/a | n/a |
| cgroup_sock | 5 | 3 | 0 | 0 | 0 | 0 | n/a | n/a |
| sk_reuseport | 4 | 3 | 0 | 0 | 0 | 0 | n/a | n/a |
| cgroup_sysctl | 1 | 1 | 0 | 0 | 0 | 0 | n/a | n/a |
| sk_lookup | 1 | 1 | 0 | 0 | 0 | 0 | n/a | n/a |
| ext | 7 | 0 | 0 | 0 | 0 | 0 | n/a | n/a |
| unspec | 7 | 0 | 0 | 0 | 0 | 0 | n/a | n/a |

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
| bpf_object__load failed: No data available | 404 |
| bpf_object__load failed: Invalid argument | 207 |
| bpf_object__load failed: Operation not supported | 46 |
| bpf_object__load failed: No such process | 44 |
| bpf_object__load failed: Permission denied | 25 |
| bpf_object__load failed: Unknown error 524 | 1 |
| bpf_object__load failed: Bad file descriptor | 1 |

## Notes

- The harness enumerates programs with `micro_exec list-programs`, then runs `run-kernel --compile-only` once for stock and once for `--recompile-v5 --recompile-all`.
- Program-type grouping refines generic libbpf `prog_type_name` using section roots so `fentry`, `fexit`, `lsm`, `raw_tracepoint`, and `sched_cls` remain separate buckets.
- When the older `corpus/expanded_corpus` and `corpus/objects` paths are absent, the harness falls back to the current canonical `corpus/build` tree from `corpus/config/corpus_manifest.yaml`.
- On 2026-03-11, this checkout's `corpus/build` inventory produced `2010` discovered programs and `1282` loadable programs; the task's `1214` figure matches the older reference inventory in `docs/tmp/corpus-runnability-results.json`.
- This host did not provide usable v5 recompile measurements, so the report should be treated as loadability inventory plus failure diagnostics.
- Host actual smoke on 2026-03-11 reached a site-positive `xdp_probe_prog`, but `BPF_PROG_JIT_RECOMPILE` failed with `Invalid argument (errno=22)`.
- Framework-VM smoke on 2026-03-11 succeeded for `corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog`, changing JIT size from `78` to `84` bytes (`1.077x`) on kernel `7.0.0-rc2-ge52504a75c05`.
- A full framework-VM run was started on 2026-03-11 and progressed through the corpus, but the host killed it with exit code `137` before it could flush complete by-type actual results.
- VM rerun command: `vng --run vendor/linux-framework/arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark --disable-monitor --cpus 1 --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp --exec 'sudo -n python3 corpus/run_code_size_comparison.py --output-json docs/tmp/code-size-by-progtype.json --output-md docs/tmp/code-size-by-progtype.md'`
