# Production Corpus v5 Results

- Generated: 2026-03-10T21:45:52.105971+00:00
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
| Objects attempted | 46 |
| Objects discovered via libbpf | 43 |
| Objects with discovery failures | 3 |
| Programs attempted | 155 |
| Perf-capable targets | 68 |
| Compile-only targets | 87 |
| Baseline compile successes | 38 |
| v5 compile successes | 38 |
| Scanner successes | 38 |
| Programs with framework-detected sites | 15 |
| Programs with recompile applied | 0 |
| Programs with recompile syscall failures | 15 |
| Compile-only size pairs | 38 |
| Measured runtime pairs | 29 |
| Speedup geomean | 0.908x |
| Speedup median | 1.000x |
| Speedup min | 0.108x |
| Speedup max | 5.000x |
| Code-size ratio geomean (baseline/v5) | 1.000x |
| Code-size median delta | +0.0% |
| Code-size min delta | +0.0% |
| Code-size max delta | +0.0% |
| Framework CMOV sites | 20 |
| Framework WIDE sites | 7 |
| Framework ROTATE sites | 0 |
| Framework LEA sites | 0 |

## Objects

| Object | Source | Discovery | Discovered Programs | Tested Programs | Compile Successes | Measured | Note |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/cilium/bpf_lxc.bpf.o | cilium | no | 0 | 0 | 0 | 0 | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/cilium/bpf_overlay.bpf.o | cilium | no | 0 | 0 | 0 | 0 | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/cilium/bpf_xdp.bpf.o | cilium | no | 0 | 0 | 0 | 0 | bpf_object__open_file failed: Operation not supported (exit=1) |
| corpus/build/katran/balancer.bpf.o | katran | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/katran/healthchecking.bpf.o | katran | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/katran/healthchecking_ipip.bpf.o | katran | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/katran/xdp_pktcntr.bpf.o | katran | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/katran/xdp_root.bpf.o | katran | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tools/xdp_basic.bpf.o | xdp-tools | yes | 15 | 15 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_flowtable.bpf.o | xdp-tools | yes | 2 | 2 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_flowtable_sample.bpf.o | xdp-tools | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_forward.bpf.o | xdp-tools | yes | 2 | 2 | 2 | 2 |  |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o | xdp-tools | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tools/xdp_monitor.bpf.o | xdp-tools | yes | 8 | 8 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o | xdp-tools | yes | 10 | 10 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o | xdp-tools | yes | 20 | 20 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o | xdp-tools | yes | 12 | 12 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o | xdp-tools | yes | 12 | 12 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_sample.bpf.o | xdp-tools | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o | xdp-tools | yes | 14 | 14 | 0 | 0 |  |
| corpus/build/xdp-tools/xdpsock.bpf.o | xdp-tools | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 2 | 2 | 2 | 2 |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 3 | 3 | 3 | 3 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail1.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail2.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail3.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 5 | 5 | 0 | 0 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern2.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern3.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern4.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_02.bpf.o | xdp-tutorial | yes | 3 | 3 | 0 | 0 |  |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o | xdp-tutorial | yes | 5 | 5 | 0 | 0 |  |
| corpus/build/xdp-tutorial/packet-solutions/xdp_vlan01_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/packet-solutions/xdp_vlan02_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/packet01-parsing/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 0 | 0 |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 3 | 3 | 3 | 3 |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 5 | 5 | 5 | 5 |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/trace_prog_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 0 |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o | xdp-tutorial | yes | 8 | 8 | 8 | 0 |  |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o | xdp-tutorial | yes | 1 | 1 | 1 | 1 |  |

## Per-Program Results

| Program | Section | Perf-capable | Baseline Load | v5 Load | CMOV | WIDE | ROTATE | LEA | Applied | Baseline JIT Bytes | v5 JIT Bytes | Code Delta | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | yes | yes | yes | 5 | 4 | 0 | 0 | no | 13346 | 13346 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | tc | yes | yes | yes | 1 | 0 | 0 | 0 | no | 1640 | 1640 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 553 | 553 | +0.0% |  |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 180 | 180 | +0.0% |  |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 188 | 188 | +0.0% |  |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_basic_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_parse_load_bytes_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_parse_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_read_data_load_bytes_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_read_data_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_swap_macs_load_bytes_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_basic.bpf.o:xdp_swap_macs_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_flowtable.bpf.o:xdp_fwd_flow_direct | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_flowtable.bpf.o:xdp_fwd_flow_full | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_flowtable_sample.bpf.o:xdp_fwd_flowtable_sample | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | no | 708 | 708 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | no | 705 | 705 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | no | 84 | 84 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_monitor.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:xdp_redirect_load_bytes_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_basic.bpf.o:xdp_redirect_prog | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_drop | xdp/cpumap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_l4_dport | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_l4_filter | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_l4_hash | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_l4_proto | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_l4_sport | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_no_touch | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_pass | xdp/cpumap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_redirect | xdp/cpumap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_round_robin | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:cpumap_touch_data | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:redirect_egress_prog | xdp/devmap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:redir_devmap_general | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:redir_devmap_native | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:xdp_redirect_devmap_egress | xdp/devmap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o:xdp_redirect_devmap_egress_drop | xdp/devmap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:redir_multi_general | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:redir_multi_native | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:xdp_devmap_prog | xdp/devmap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o:xdp_redirect_devmap_egress_drop | xdp/devmap | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_sample.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_cpumap_compat | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_cpumap_enqueue | tp_btf/xdp_cpumap_enqueue | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_cpumap_kthread | tp_btf/xdp_cpumap_kthread | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_devmap_xmit | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_devmap_xmit_multi | tp_btf/xdp_devmap_xmit | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_exception | tp_btf/xdp_exception | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_redirect | tp_btf/xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:tp_xdp_redirect_err | tp_btf/xdp_redirect_err | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No such process (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:xdp_drop | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:xdp_handle_tcp_recv | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:xdp_pass | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:xdp_redirect_notouch | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:xdp_redirect_send_tcp | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdp_trafficgen.bpf.o:xdp_redirect_update_port | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: No data available (exit=1) |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 94 | 94 | +0.0% |  |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 221 | 221 | +0.0% |  |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 31 | 31 | +0.0% |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 31 | 31 | +0.0% |  |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 31 | 31 | +0.0% |  |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 110 | 110 | +0.0% |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 150 | 150 | +0.0% |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 151 | 151 | +0.0% |  |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 151 | 151 | +0.0% |  |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail1.bpf.o:_xdp_fail1 | xdp_fail1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail2.bpf.o:_xdp_fail2 | xdp_fail2 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail3.bpf.o:_xdp_fail3 | xdp_fail3 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o:grow_parse | xdp_tailgrow_parse | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o:tailgrow_pass | xdp_tailgrow | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o:tailgrow_tx | xdp_tailgrow_tx | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o:xdp_pass_func | xdp_pass | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern.bpf.o:xdp_tx_rec | xdp_tx | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern2.bpf.o:_xdp_end_loop | xdp_end_loop | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern3.bpf.o:_xdp_works1 | xdp_works1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern4.bpf.o:_xdp_test1 | xdp_test1 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | tc | yes | yes | yes | 0 | 0 | 0 | 0 | no | 555 | 555 | +0.0% |  |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_02.bpf.o:xdp_pass_func | xdp_pass | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_02.bpf.o:xdp_patch_ports_func | xdp_patch_ports | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_02.bpf.o:xdp_vlan_swap_func | xdp_vlan_swap | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o:xdp_icmp_echo_func | xdp_icmp_echo | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o:xdp_pass_func | xdp_pass | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o:xdp_redirect_func | xdp_redirect | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o:xdp_redirect_map_func | xdp_redirect_map | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_03.bpf.o:xdp_router_func | xdp_router | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_vlan01_kern.bpf.o:xdp_vlan_01 | xdp_vlan01 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet-solutions/xdp_vlan02_kern.bpf.o:xdp_vlan_02 | xdp_vlan02 | no | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Invalid argument (exit=1) |
| corpus/build/xdp-tutorial/packet01-parsing/xdp_prog_kern.bpf.o:xdp_parser_func | xdp | yes | no | no | 0 | 0 | 0 | 0 | no | n/a | n/a | n/a | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | no | 524 | 524 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 31 | 31 | +0.0% |  |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp | yes | yes | yes | 1 | 1 | 0 | 0 | no | 116 | 116 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp | yes | yes | yes | 2 | 0 | 0 | 0 | no | 549 | 549 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 31 | 31 | +0.0% |  |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp | yes | yes | yes | 1 | 1 | 0 | 0 | no | 243 | 243 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp | yes | yes | yes | 1 | 1 | 0 | 0 | no | 379 | 379 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 478 | 478 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/trace_prog_kern.bpf.o:trace_xdp_exception | tracepoint/xdp/xdp_exception | no | yes | yes | 0 | 0 | 0 | 0 | no | 162 | 162 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 28 | 28 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_cpumap_enqueue | tracepoint/xdp/xdp_cpumap_enqueue | no | yes | yes | 0 | 0 | 0 | 0 | no | 167 | 167 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_cpumap_kthread | tracepoint/xdp/xdp_cpumap_kthread | no | yes | yes | 0 | 0 | 0 | 0 | no | 155 | 155 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_devmap_xmit | tracepoint/xdp/xdp_devmap_xmit | no | yes | yes | 0 | 0 | 0 | 0 | no | 214 | 214 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_exception | tracepoint/xdp/xdp_exception | no | yes | yes | 0 | 0 | 0 | 0 | no | 138 | 138 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_redirect | tracepoint/xdp/xdp_redirect | no | yes | yes | 1 | 0 | 0 | 0 | no | 143 | 143 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_redirect_err | tracepoint/xdp/xdp_redirect_err | no | yes | yes | 1 | 0 | 0 | 0 | no | 143 | 143 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_redirect_map | tracepoint/xdp/xdp_redirect_map | no | yes | yes | 1 | 0 | 0 | 0 | no | 143 | 143 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/tracing02-xdp-monitor/trace_prog_kern.bpf.o:trace_xdp_redirect_map_err | tracepoint/xdp/xdp_redirect_map_err | no | yes | yes | 1 | 0 | 0 | 0 | no | 143 | 143 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp | yes | yes | yes | 0 | 0 | 0 | 0 | no | 233 | 233 | +0.0% |  |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp | yes | yes | yes | 1 | 0 | 0 | 0 | no | 174 | 174 | +0.0% | BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) |

## Runtime Comparison

| Program | Section | Baseline ns | v5 ns | Speedup | Baseline JIT Bytes | v5 JIT Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/katran/balancer.bpf.o:balancer_ingress | xdp | 36 | 25 | 1.440x | 13346 | 13346 |
| corpus/build/katran/healthchecking.bpf.o:healthcheck_encap | tc | 24 | 21 | 1.143x | 1640 | 1640 |
| corpus/build/katran/healthchecking_ipip.bpf.o:healthcheck_encap | tc | 19 | 21 | 0.905x | 553 | 553 |
| corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr | xdp | 20 | 26 | 0.769x | 180 | 180 |
| corpus/build/katran/xdp_root.bpf.o:xdp_root | xdp | 21 | 21 | 1.000x | 188 | 188 |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct | xdp | 26 | 26 | 1.000x | 708 | 708 |
| corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_full | xdp | 31 | 28 | 1.107x | 705 | 705 |
| corpus/build/xdp-tools/xdp_load_bytes.bpf.o:xdp_probe_prog | xdp | 36 | 38 | 0.947x | 84 | 84 |
| corpus/build/xdp-tools/xdpsock.bpf.o:xdp_sock_prog | xdp | 32 | 30 | 1.067x | 94 | 94 |
| corpus/build/xdp-tutorial/advanced03-AF_XDP/af_xdp_kern.bpf.o:xdp_sock_prog | xdp | 26 | 33 | 0.788x | 221 | 221 |
| corpus/build/xdp-tutorial/basic01-xdp-pass/xdp_pass_kern.bpf.o:xdp_prog_simple | xdp | 19 | 20 | 0.950x | 31 | 31 |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_drop_func | xdp | 18 | 19 | 0.947x | 31 | 31 |
| corpus/build/xdp-tutorial/basic02-prog-by-name/xdp_prog_kern.bpf.o:xdp_pass_func | xdp | 16 | 25 | 0.640x | 31 | 31 |
| corpus/build/xdp-tutorial/basic03-map-counter/xdp_prog_kern.bpf.o:xdp_stats1_func | xdp | 23 | 25 | 0.920x | 110 | 110 |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_abort_func | xdp | 23 | 23 | 1.000x | 150 | 150 |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_drop_func | xdp | 21 | 22 | 0.955x | 151 | 151 |
| corpus/build/xdp-tutorial/basic04-pinning-maps/xdp_prog_kern.bpf.o:xdp_pass_func | xdp | 21 | 20 | 1.050x | 151 | 151 |
| corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o:_fix_port_egress | tc | 13 | 12 | 1.083x | 555 | 555 |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_parser_func | xdp | 60 | 12 | 5.000x | 524 | 524 |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_port_rewrite_func | xdp | 9 | 11 | 0.818x | 31 | 31 |
| corpus/build/xdp-tutorial/packet02-rewriting/xdp_prog_kern.bpf.o:xdp_vlan_swap_func | xdp | 9 | 83 | 0.108x | 116 | 116 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_icmp_echo_func | xdp | 12 | 12 | 1.000x | 549 | 549 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_pass_func | xdp | 8 | 20 | 0.400x | 31 | 31 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_func | xdp | 12 | 12 | 1.000x | 243 | 243 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_redirect_map_func | xdp | 20 | 20 | 1.000x | 379 | 379 |
| corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o:xdp_router_func | xdp | 13 | 12 | 1.083x | 478 | 478 |
| corpus/build/xdp-tutorial/tracing01-xdp-simple/xdp_prog_kern.bpf.o:xdp_drop_func | xdp | 9 | 17 | 0.529x | 28 | 28 |
| corpus/build/xdp-tutorial/tracing03-xdp-debug-print/xdp_prog_kern.bpf.o:xdp_prog_simple | xdp | 446 | 377 | 1.183x | 233 | 233 |
| corpus/build/xdp-tutorial/tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o:xdp_sample_prog | xdp | 298 | 342 | 0.871x | 174 | 174 |

## Discovery Failures

| Object | Error | Fallback CMOV | Fallback WIDE | Fallback ROTATE | Fallback LEA | Exec Sections |
| --- | --- | --- | --- | --- | --- | --- |
| corpus/build/cilium/bpf_lxc.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) | 142 | 0 | 0 | 0 | 3 |
| corpus/build/cilium/bpf_overlay.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) | 108 | 0 | 0 | 0 | 3 |
| corpus/build/cilium/bpf_xdp.bpf.o | bpf_object__open_file failed: Operation not supported (exit=1) | 408 | 0 | 0 | 0 | 3 |

### corpus/build/cilium/bpf_lxc.bpf.o

| Section | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | --- | --- | --- | --- | --- |
| tc/tail | 40776 | 139 | 0 | 0 | 0 | 139 |
| tc/entry | 1097 | 3 | 0 | 0 | 0 | 3 |

### corpus/build/cilium/bpf_overlay.bpf.o

| Section | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | --- | --- | --- | --- | --- |
| tc/tail | 28753 | 106 | 0 | 0 | 0 | 106 |
| tc/entry | 829 | 2 | 0 | 0 | 0 | 2 |

### corpus/build/cilium/bpf_xdp.bpf.o

| Section | Insns | CMOV | WIDE | ROTATE | LEA | Total |
| --- | --- | --- | --- | --- | --- | --- |
| xdp/tail | 25495 | 399 | 0 | 0 | 0 | 399 |
| xdp/entry | 626 | 9 | 0 | 0 | 0 | 9 |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: No such process (exit=1) | 60 |
| bpf_object__load failed: No data available (exit=1) | 35 |
| bpf_object__load failed: Invalid argument (exit=1) | 21 |
| bpf_object__open_file failed: Operation not supported (exit=1) | 3 |
| bpf_object__load failed: Permission denied (exit=1) | 1 |

## Recompile Failures

| Reason | Count |
| --- | --- |
| BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22) | 15 |

## Notes

- These results were collected inside the framework guest booted from `vendor/linux`.
- Site counts come from the scanner CLI run on dumped post-verifier xlated bytecode. When that scan fails, the report falls back to the runner's `directive_scan` summary.
- The harness tries `/sys/kernel/btf/vmlinux` first and retries with the shared build-tree `vendor/linux/vmlinux` only for BTF/CO-RE-looking failures.
- Objects that libbpf could not enumerate are still included through compile-time section census fallback so their directive-bearing sections are documented.
