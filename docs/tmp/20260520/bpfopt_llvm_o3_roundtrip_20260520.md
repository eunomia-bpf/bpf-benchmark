# bpfopt LLVM O3 Roundtrip Host Check - 2026-05-20

## Verdict

- LLVM `bpfopt` built successfully with CMake in `bpfopt/llvm/build`; `bpfopt-loader` built successfully with Cargo.
- Control `--pass noop` verified every loader-prepared program: 352/352 programs passed `BPF_PROG_LOAD` after roundtrip.
- Direct LLVM `--pass map_inline` reached O3 roundtrip and verifier reload for 135/135 attempted programs; all attempted programs passed. No transformed-bytecode verifier rejection was observed in the attempted set.
- Direct LLVM `map_inline` applied zero map-inline sites on the generic object sweep because the default loader YAML passes no hard `--inline-hint` values. It still exercised the non-noop/O3 path.
- Coverage blocker: direct `map_inline` could not prepare 217 programs in 3 large objects because initial libbpf load at verifier `log_level=2` exhausted the 64 MiB verifier log buffer and returned `-ENOSPC` before LLVM ran.
- Katran direct LLVM `map_inline` verified and `BPF_PROG_TEST_RUN` executed, but applied 0 sites and returned `retval=2`. The existing hard-hint wrapper around the same LLVM binary applied 16 sites, verified, and `BPF_PROG_TEST_RUN` returned `retval=3`.

## Build And Tools

- No existing Make target for `bpfopt/llvm` was found; I used the README CMake flow:

```sh
cmake -S bpfopt/llvm -B bpfopt/llvm/build -DCMAKE_BUILD_TYPE=Release
cmake --build bpfopt/llvm/build -j
cargo build --manifest-path bpfopt/Cargo.toml -p bpfopt-loader
```

- LLVM binary: `bpfopt/llvm/build/bpfopt`.
- Loader source: `bpfopt/loader/src/main.rs`; loader binary: `bpfopt/target/debug/bpfopt-loader`.
- Loader usage confirmed from `bpfopt/loader/README.md` and `--help`: `bpfopt-loader --obj <file> --pass <name> --bpfopt <path> [--workdir <dir>] [--bpftestrun] [--katran-maps]`.
- Main raw artifacts: `/tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/summary.json` plus per-object workdirs and logs under the same directory.

## Test Corpus

- Discovered 35 objects under `bpfopt/testobject/*.bpf.o`.
- No `bpfopt/crates/**/testobject*` or `testobjects*` object corpus was present.
- 9 bpftrace fixture objects opened with rc=0 but exposed 0 loader-prepared programs: bpftrace_base.bpf.o, bpftrace_map_map.bpf.o, bpftrace_process_process.bpf.o, bpftrace_strings_strings.bpf.o, bpftrace_system_system.bpf.o, bpftrace_task_task.bpf.o, bpftrace_task_vma.bpf.o, bpftrace_test_test.bpf.o, bpftrace_usdt_usdt.bpf.o.
- 3 OTel objects failed before program preparation in both passes because the loader requires `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64`, which is absent: otel_generic_probe.bpf.o, otel_native_stack_trace.bpf.o, otel_sched_monitor.bpf.o.

## Verifier Failure Categories

| Category | Pass | Count | Scope | Error |
|---|---:|---:|---|---|
| Transformed bytecode rejected by `BPF_PROG_LOAD` | noop | 0 | 352 programs attempted | none |
| Transformed bytecode rejected by `BPF_PROG_LOAD` | map_inline/O3 | 0 | 135 programs attempted | none |
| Initial object load verifier log exhausted before roundtrip | map_inline/O3 | 217 programs / 3 objects | not a roundtrip verifier result | `No space left on device (os error 28)` from libbpf load with failing programs at 64 MiB verifier logs |
| Missing linked OTel tracer before program prep | noop and map_inline/O3 | 3 objects | not per-program | `OTel split object ... requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64` |

Objects blocked by initial `-ENOSPC` in direct `map_inline`:

| Object | Programs not O3-tested | First failing loader program from log | Exact loader error |
|---|---:|---|---|
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | 35 | `tail_handle_ipv4_cont` | `error: libbpf failed to load /tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/map_inline/cilium_bpf_lxc.bpf.o/loader-compatible-pinning.bpf.o: No space left on device (os error 28)` |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | 13 | `tail_nodeport_nat_ingress_ipv6` | `error: libbpf failed to load /tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/map_inline/cilium_bpf_xdp.bpf.o/loader-compatible-pinning.bpf.o: No space left on device (os error 28)` |
| `bpfopt/testobject/tracee_tracee.bpf.o` | 169 | `lkm_seeker_modtree_loop` | `error: libbpf failed to load /tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/map_inline/tracee_tracee.bpf.o/loader-compatible.bpf.o: No space left on device (os error 28)` |

## Katran Host Result

Object: `bpfopt/testobject/katran_balancer.bpf.o`; program: `balancer_ingress`.

| Run | bpfopt path | Verify | sites_applied | insns before -> after | TEST_RUN | retval | data_size_out | verifier tail | artifacts |
|---|---|---|---:|---|---|---:|---:|---|---|
| Direct LLVM map_inline | `bpfopt/llvm/build/bpfopt` | pass | 0 | 2542 -> 2559 | ran | 2 | 64 | `processed 524969 insns (limit 1000000) max_states_per_insn 23 total_states 29390 peak_states 1244 mark_read 41` | `/tmp/bpfopt-llvm-katran-mapinline.OfBgNo` |
| Existing hard-hint wrapper | `docs/tmp/bpfopt_llvm_mapinline_katran_wrapper.sh` -> LLVM binary | pass | 16 | 2542 -> 2500 | ran | 3 | 84 | `processed 9028 insns (limit 1000000) max_states_per_insn 7 total_states 476 peak_states 401 mark_read 31` | `/tmp/bpfopt-llvm-katran-mapinline-wrapper.Mjsmxz` |

Interpretation: the direct `map_inline` loader command verifies and runs, but it has no hard hints, so it is an O3 roundtrip with `sites_applied=0`. A direct LLVM `noop` baseline also verified and ran with `retval=2` (`/tmp/bpfopt-llvm-katran-noop.yczyP2`). The wrapper result is the actual Katran hard-hint map-inline smoke: 16 lookup sites inlined, verifier pass, and `BPF_PROG_TEST_RUN` returned XDP_TX (`retval=3`).

## Object Summary

| Object | noop | direct map_inline/O3 | Notes |
|---|---:|---:|---|
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | 6/6 pass | 6/6 pass |  |
| `bpfopt/testobject/bcc_capable.bpf.o` | 2/2 pass | 2/2 pass |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | 6/6 pass | 6/6 pass |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | 6/6 pass | 6/6 pass |  |
| `bpfopt/testobject/bcc_syscount.bpf.o` | 2/2 pass | 2/2 pass |  |
| `bpfopt/testobject/bcc_tcpconnect.bpf.o` | 4/4 pass | 4/4 pass |  |
| `bpfopt/testobject/bcc_tcplife.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | 16/16 pass | 16/16 pass |  |
| `bpfopt/testobject/bpftrace_base.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_map_map.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_process_process.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_strings_strings.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_system_system.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_task_task.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_task_vma.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_test_test.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/bpftrace_usdt_usdt.bpf.o` | 0/0 pass | 0/0 pass | 0 loader-prepared programs |
| `bpfopt/testobject/cilium_bpf_alignchecker.bpf.o` | 2/2 pass | 2/2 pass |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | 33/33 pass | 33/33 pass |  |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | 35/35 pass | setup fail rc=1 | error: libbpf failed to load /tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/map_inline/cilium_bpf_lxc.bpf.o/loader-compatible-pinning.bpf.o: No space left on device (os error 28) |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | 22/22 pass | 22/22 pass |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | 9/9 pass | 9/9 pass |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | 19/19 pass | 19/19 pass |  |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | 13/13 pass | setup fail rc=1 | error: libbpf failed to load /tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/map_inline/cilium_bpf_xdp.bpf.o/loader-compatible-pinning.bpf.o: No space left on device (os error 28) |
| `bpfopt/testobject/katran_balancer.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/katran_healthchecking.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/katran_healthchecking_ipip.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/katran_xdp_pktcntr.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/katran_xdp_root.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/otel_generic_probe.bpf.o` | setup fail rc=1 | setup fail rc=1 | error: OTel split object bpfopt/testobject/otel_generic_probe.bpf.o requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64; error: OTel split object bpfopt/testobject/otel_generic_probe.bpf.o requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64 |
| `bpfopt/testobject/otel_native_stack_trace.bpf.o` | setup fail rc=1 | setup fail rc=1 | error: OTel split object bpfopt/testobject/otel_native_stack_trace.bpf.o requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64; error: OTel split object bpfopt/testobject/otel_native_stack_trace.bpf.o requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64 |
| `bpfopt/testobject/otel_sched_monitor.bpf.o` | setup fail rc=1 | setup fail rc=1 | error: OTel split object bpfopt/testobject/otel_sched_monitor.bpf.o requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64; error: OTel split object bpfopt/testobject/otel_sched_monitor.bpf.o requires linked tracer runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64 |
| `bpfopt/testobject/tracee_lsm_support_kprobe_check.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/tracee_lsm_support_lsm_check.bpf.o` | 1/1 pass | 1/1 pass |  |
| `bpfopt/testobject/tracee_tracee.bpf.o` | 169/169 pass | setup fail rc=1 | error: libbpf failed to load /tmp/bpfopt-llvm-o3-roundtrip-ma74xv7c/map_inline/tracee_tracee.bpf.o/loader-compatible.bpf.o: No space left on device (os error 28) |

## Per-Program Results

`map_inline/O3=SETUP_FAIL` means the program never reached LLVM roundtrip/reload because object preparation failed first. It is not counted as a verifier rejection of transformed bytecode.

| Object | Program | noop | direct map_inline/O3 | Note |
|---|---|---|---|---|
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | `blk_account_io_merge_bio` | PASS | PASS |  |
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | `blk_account_io_start` | PASS | PASS |  |
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | `block_io_start` | PASS | PASS |  |
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | `block_rq_complete` | PASS | PASS |  |
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | `block_rq_insert` | PASS | PASS |  |
| `bpfopt/testobject/bcc_biosnoop.bpf.o` | `block_rq_issue` | PASS | PASS |  |
| `bpfopt/testobject/bcc_capable.bpf.o` | `kprobe__cap_capable_entry` | PASS | PASS |  |
| `bpfopt/testobject/bcc_capable.bpf.o` | `kprobe__cap_capable_exit` | PASS | PASS |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | `tracepoint__syscalls__sys_enter_open` | PASS | PASS |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | `tracepoint__syscalls__sys_enter_openat` | PASS | PASS |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | `tracepoint__syscalls__sys_enter_openat2` | PASS | PASS |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | `tracepoint__syscalls__sys_exit_open` | PASS | PASS |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | `tracepoint__syscalls__sys_exit_openat` | PASS | PASS |  |
| `bpfopt/testobject/bcc_opensnoop.bpf.o` | `tracepoint__syscalls__sys_exit_openat2` | PASS | PASS |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | `handle_sched_switch` | PASS | PASS |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | `handle_sched_wakeup` | PASS | PASS |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | `handle_sched_wakeup_new` | PASS | PASS |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | `sched_switch` | PASS | PASS |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | `sched_wakeup` | PASS | PASS |  |
| `bpfopt/testobject/bcc_runqlat.bpf.o` | `sched_wakeup_new` | PASS | PASS |  |
| `bpfopt/testobject/bcc_syscount.bpf.o` | `sys_enter` | PASS | PASS |  |
| `bpfopt/testobject/bcc_syscount.bpf.o` | `sys_exit` | PASS | PASS |  |
| `bpfopt/testobject/bcc_tcpconnect.bpf.o` | `tcp_v4_connect` | PASS | PASS |  |
| `bpfopt/testobject/bcc_tcpconnect.bpf.o` | `tcp_v4_connect_ret` | PASS | PASS |  |
| `bpfopt/testobject/bcc_tcpconnect.bpf.o` | `tcp_v6_connect` | PASS | PASS |  |
| `bpfopt/testobject/bcc_tcpconnect.bpf.o` | `tcp_v6_connect_ret` | PASS | PASS |  |
| `bpfopt/testobject/bcc_tcplife.bpf.o` | `inet_sock_set_state` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_create` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_fsync` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_mkdir` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_open` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_read` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_rmdir` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_unlink` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `fentry_vfs_write` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_create` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_fsync` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_mkdir` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_open` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_read` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_rmdir` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_unlink` | PASS | PASS |  |
| `bpfopt/testobject/bcc_vfsstat.bpf.o` | `kprobe_vfs_write` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_alignchecker.bpf.o` | `tail_icmp6_handle_ns` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_alignchecker.bpf.o` | `tail_icmp6_send_time_exceeded` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `cil_from_host` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `cil_from_netdev` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `cil_host_policy` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `cil_to_host` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `cil_to_netdev` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_drop_notify` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv4_cont_from_host` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv4_cont_from_netdev` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv4_from_host` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv4_from_netdev` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv6_cont_from_host` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv6_cont_from_netdev` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv6_from_host` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_ipv6_from_netdev` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_nat_fwd_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_nat_fwd_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_snat_fwd_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_handle_snat_fwd_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_icmp6_handle_ns` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_icmp6_send_time_exceeded` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_ipv4_host_policy_ingress` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_ipv6_host_policy_ingress` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_ipv4_dsr` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_ipv6_dsr` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_nat_egress_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_nat_egress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_nat_ingress_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_nat_ingress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_rev_dnat_egress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_rev_dnat_ingress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_nodeport_rev_dnat_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_srv6_decap` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_host.bpf.o` | `tail_srv6_encap` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `cil_from_container` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `cil_lxc_policy` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `cil_lxc_policy_egress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `cil_to_container` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_drop_notify` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_handle_arp` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_handle_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_handle_ipv4_cont` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_handle_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_handle_ipv6_cont` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_icmp6_handle_ns` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_icmp6_send_time_exceeded` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv4_ct_egress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv4_ct_ingress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv4_ct_ingress_policy_only` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv4_policy` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv4_to_endpoint` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv6_ct_egress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv6_ct_ingress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv6_ct_ingress_policy_only` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv6_policy` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_ipv6_to_endpoint` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_ipv4_dsr` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_ipv6_dsr` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_nat_egress_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_nat_egress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_nat_ingress_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_nat_ingress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_rev_dnat_egress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_rev_dnat_ingress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_nodeport_rev_dnat_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_policy_denied_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_policy_denied_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_srv6_decap` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_lxc.bpf.o` | `tail_srv6_encap` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `cil_from_overlay` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `cil_to_overlay` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_drop_notify` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_arp` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_inter_cluster_revsnat` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_nat_fwd_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_nat_fwd_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_snat_fwd_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_handle_snat_fwd_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_icmp6_send_time_exceeded` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_mcast_ep_delivery` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_ipv4_dsr` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_ipv6_dsr` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_nat_egress_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_nat_egress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_nat_ingress_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_nat_ingress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_rev_dnat_egress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_rev_dnat_ingress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_overlay.bpf.o` | `tail_nodeport_rev_dnat_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock4_connect` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock4_post_bind` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock4_recvmsg` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock4_sendmsg` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock6_connect` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock6_post_bind` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock6_recvmsg` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock6_sendmsg` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_sock.bpf.o` | `cil_sock_release` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `cil_from_wireguard` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `cil_to_wireguard` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_drop_notify` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_handle_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_handle_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_handle_nat_fwd_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_handle_nat_fwd_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_handle_snat_fwd_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_handle_snat_fwd_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_icmp6_send_time_exceeded` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_ipv4_dsr` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_ipv6_dsr` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_nat_egress_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_nat_egress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_nat_ingress_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_nat_ingress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_rev_dnat_egress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_rev_dnat_ingress_ipv6` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_wireguard.bpf.o` | `tail_nodeport_rev_dnat_ipv4` | PASS | PASS |  |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `cil_xdp_entry` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_drop_notify` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_lb_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_lb_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_ipv4_dsr` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_ipv6_dsr` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_nat_egress_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_nat_egress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_nat_ingress_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_nat_ingress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_rev_dnat_egress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_rev_dnat_ingress_ipv6` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/cilium_bpf_xdp.bpf.o` | `tail_nodeport_rev_dnat_ipv4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/katran_balancer.bpf.o` | `balancer_ingress` | PASS | PASS |  |
| `bpfopt/testobject/katran_healthchecking.bpf.o` | `healthcheck_encap` | PASS | PASS |  |
| `bpfopt/testobject/katran_healthchecking_ipip.bpf.o` | `healthcheck_encap` | PASS | PASS |  |
| `bpfopt/testobject/katran_xdp_pktcntr.bpf.o` | `pktcntr` | PASS | PASS |  |
| `bpfopt/testobject/katran_xdp_root.bpf.o` | `xdp_root` | PASS | PASS |  |
| `bpfopt/testobject/tracee_lsm_support_kprobe_check.bpf.o` | `security_bpf_kprobe` | PASS | PASS |  |
| `bpfopt/testobject/tracee_lsm_support_lsm_check.bpf.o` | `lsm_bpf_check` | PASS | PASS |  |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `cgroup_bpf_run_filter_skb` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `cgroup_mkdir_signal` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `cgroup_rmdir_signal` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `cgroup_skb_egress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `cgroup_skb_ingress` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `empty_kprobe` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `heartbeat_capture` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `kernel_write_magic_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `kernel_write_magic_return` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `lkm_seeker_kset_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `lkm_seeker_mod_tree_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `lkm_seeker_modtree_loop` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `lkm_seeker_new_mod_only_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `lkm_seeker_proc_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `lsm_file_open_test` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `process_execute_failed_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sched_process_exec_event_submit_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sched_process_exec_signal` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sched_process_exit_signal` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sched_process_fork_signal` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `send_bin` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `send_bin_tp` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sys_dup_exit_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sys_enter_init` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sys_enter_submit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sys_exit_init` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `sys_exit_submit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall__accept4` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall__execve_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall__execve_exit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall__execveat_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall__execveat_exit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall__init_module` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `syscall_checker` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace___debugfs_create_file` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace___register_chrdev` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_arch_prctl` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_bpf_check` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_call_usermodehelper` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_cap_capable` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_check_helper_call` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_check_map_func_compatibility` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_chmod_common` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_commit_creds` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_debugfs_create_dir` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_device_add` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_do_exit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_do_init_module` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_do_mmap` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_do_sigaction` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_do_splice` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_do_truncate` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_dup` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_dup2` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_dup3` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_exec_binprm` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_execute_finished` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_fd_install` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_file_modified` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_file_update_time` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_filldir64` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_filp_close` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_inotify_find_inode` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_kallsyms_lookup_name` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_kernel_write` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_load_elf_phdrs` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_mmap_alert` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_proc_create` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_process_vm_writev` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ptrace` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_register_kprobe` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret__register_chrdev` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_arch_prctl` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_do_init_module` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_do_mmap` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_do_splice` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_dup` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_dup2` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_dup3` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_file_modified` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_file_update_time` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_inotify_find_inode` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_kallsyms_lookup_name` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_kernel_write` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_kernel_write_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_process_vm_writev` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_ptrace` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_register_kprobe` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_sock_alloc_file` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_read` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_read_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_readv` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_readv_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_write` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_write_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_writev` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_ret_vfs_writev_tail` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_bpf` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_bpf_map` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_bpf_prog` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_bprm_check` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_bprm_creds_for_exec` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_file_ioctl` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_file_mprotect` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_file_open` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_file_permission` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_inode_mknod` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_inode_rename` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_inode_symlink` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_inode_unlink` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_kernel_post_read_file` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_kernel_read_file` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_mmap_file` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_path_notify` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_sb_mount` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_sb_umount` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_settime64` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_sk_clone` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_accept` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_bind` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_connect` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_create` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_listen` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_recvmsg` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_sendmsg` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_socket_setsockopt` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_task_prctl` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_security_task_setrlimit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_set_fs_pwd` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_sock_alloc_file` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_switch_task_namespaces` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_sys_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_sys_exit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_tracepoint_probe_register_prio_may_exist` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_utimes_common` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_vfs_read` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_vfs_readv` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_vfs_utimes` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_vfs_write` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `trace_vfs_writev` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__cgroup__cgroup_attach_task` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__cgroup__cgroup_mkdir` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__cgroup__cgroup_rmdir` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__exec_test` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__module__module_free` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__module__module_load` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__raw_syscalls__sys_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__raw_syscalls__sys_exit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__sched__sched_process_exec` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__sched__sched_process_exit` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__sched__sched_process_fork` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__sched__sched_process_free` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__sched__sched_switch` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `tracepoint__task__task_rename` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe__features_fallback_arena` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe__features_fallback_arena_tailcall` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe__features_fallback_helper` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe__features_fallback_helper_tailcall` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe__features_fallback_minimal` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe__features_fallback_minimal_tailcall` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe_lkm_seeker` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe_lkm_seeker_submitter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe_mem_dump_trigger` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe_seq_ops_trigger` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `uprobe_syscall_table_check` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `vfs_write_magic_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `vfs_write_magic_return` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `vfs_writev_magic_enter` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
| `bpfopt/testobject/tracee_tracee.bpf.o` | `vfs_writev_magic_return` | PASS | SETUP_FAIL | SETUP_FAIL: initial verifier log_level=2 load hit -ENOSPC before roundtrip |
