# Production Corpus v5 Results

- Generated: 2026-03-10T22:33:55.460830+00:00
- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel release: `7.0.0-rc2-g1572a4ddb52b-dirty`
- Kernel tree: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Kernel branch: ``
- Kernel commit: ``
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- BTF candidates: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux`
- Repeat: 100

## Summary

| Metric | Value |
| --- | --- |
| Objects attempted | 3 |
| Objects discovered via libbpf | 3 |
| Objects with discovery failures | 0 |
| Programs attempted | 18 |
| Perf-capable targets | 0 |
| Compile-only targets | 18 |
| Baseline compile successes | 0 |
| v5 compile successes | 0 |
| Scanner successes | 0 |
| Programs with framework-detected sites | 0 |
| Programs with recompile applied | 0 |
| Programs with recompile syscall failures | 0 |
| Compile-only size pairs | 0 |
| Measured runtime pairs | 0 |
| Speedup geomean | n/a |
| Speedup median | n/a |
| Speedup min | n/a |
| Speedup max | n/a |
| Code-size ratio geomean (baseline/v5) | n/a |
| Code-size median delta | n/a |
| Code-size min delta | n/a |
| Code-size max delta | n/a |
| Framework CMOV sites | 0 |
| Framework WIDE sites | 0 |
| Framework ROTATE sites | 0 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o | loxilb | yes | 8 | 8 | 0 | 0 |  |
| corpus/build/loxilb/llb_ebpf_main.bpf.o | loxilb | yes | 8 | 8 | 0 | 0 |  |
| corpus/build/loxilb/llb_xdp_main.bpf.o | loxilb | yes | 2 | 2 | 0 | 0 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_csum_func1 | tc_packet_hook4 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_csum_func2 | tc_packet_hook5 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func | tc_packet_hook1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_fast | tc_packet_hook0 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_fw | tc_packet_hook3 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_masq | tc_packet_hook7 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_packet_func_slow | tc_packet_hook2 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o:tc_slow_unp_func | tc_packet_hook6 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_csum_func1 | tc_packet_hook4 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_csum_func2 | tc_packet_hook5 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func | tc_packet_hook1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_fast | tc_packet_hook0 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_fw | tc_packet_hook3 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_masq | tc_packet_hook7 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_func_slow | tc_packet_hook2 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_slow_unp_func | tc_packet_hook6 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_xdp_main.bpf.o:xdp_packet_func | xdp_packet_hook | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/loxilb/llb_xdp_main.bpf.o:xdp_pass_func | xdp_pass | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Invalid argument (exit=1) | 18 |

## Notes

- These results were collected inside the guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
