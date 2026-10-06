# Corpus Expansion Round 3

Generated on 2026-03-11.

## Summary

- Round 3 grew the on-disk corpus from 532 to 560 `.bpf.o` objects (+28).
- The merged current corpus now covers 23 top-level projects, 2010 discovered programs, 1280 loadable programs, 293 directive-bearing programs, and 391 truly runnable programs.
- New source-backed work this round focused on sched_ext (`scx_*`), Tetragon, systemd, NetBird, and five targeted Linux selftests that close `flow_dissector`, `sk_reuseport`, and `cgroup_skb` gaps.
- Updated totals below are a precise merge of the full baseline sweep in `docs/tmp/corpus-runnability-results.json` with the targeted Round-3 reruns for the modified/new objects, not a brand-new full-corpus rerun.

## Current Corpus Composition

### Projects in `corpus/build/`

| Project | `.bpf.o` objects |
| --- | ---: |
| `linux-selftests` | 369 |
| `bcc` | 57 |
| `xdp-tutorial` | 25 |
| `tetragon` | 23 |
| `real_world_code_size` | 15 |
| `xdp-tools` | 13 |
| `libbpf-bootstrap` | 12 |
| `calico` | 8 |
| `systemd` | 6 |
| `katran` | 5 |
| `scx` | 4 |
| `cilium` | 3 |
| `KubeArmor` | 3 |
| `loxilb` | 3 |
| `opentelemetry-ebpf-profiler` | 3 |
| `datadog-agent` | 2 |
| `manual-test` | 2 |
| `suricata` | 2 |
| `tracee` | 2 |
| `coroot-node-agent` | 1 |
| `netbird` | 1 |
| `tubular` | 1 |
| `xdp-examples` | 0 |

Total: **23 projects / 560 objects**.

### Program-Type Distribution

| Prog type | Programs | Loadable | Site-bearing |
| --- | ---: | ---: | ---: |
| `kprobe` | 549 | 411 | 115 |
| `tracing` | 452 | 243 | 17 |
| `sched_cls` | 186 | 110 | 62 |
| `tracepoint` | 166 | 130 | 16 |
| `raw_tracepoint` | 118 | 84 | 23 |
| `struct_ops` | 111 | 70 | 18 |
| `xdp` | 92 | 46 | 16 |
| `syscall` | 85 | 53 | 1 |
| `lsm` | 83 | 49 | 13 |
| `unspec` | 46 | 0 | 0 |
| `perf_event` | 21 | 19 | 1 |
| `cgroup_sockopt` | 14 | 11 | 0 |
| `cgroup_sock_addr` | 12 | 6 | 0 |
| `sock_ops` | 12 | 7 | 1 |
| `socket_filter` | 10 | 7 | 0 |
| `netfilter` | 9 | 3 | 0 |
| `cgroup_skb` | 8 | 6 | 2 |
| `flow_dissector` | 8 | 7 | 4 |
| `ext` | 7 | 0 | 0 |
| `cgroup_sock` | 5 | 3 | 0 |
| `sk_msg` | 5 | 5 | 3 |
| `sk_skb` | 5 | 5 | 0 |
| `sk_reuseport` | 4 | 3 | 1 |
| `cgroup_sysctl` | 1 | 1 | 0 |
| `sk_lookup` | 1 | 1 | 0 |

### Gap Analysis

- Entirely missing from the current runnable corpus are the routing/tunnel prog types `lwt_in`, `lwt_out`, `lwt_xmit`, and `seg6local`.
- Still extremely sparse (10 programs or fewer) are `cgroup_sysctl` (1), `sk_lookup` (1), `sk_reuseport` (4), `cgroup_sock` (5), `sk_msg` (5), `sk_skb` (5), `ext` (7), `cgroup_skb` (8), `flow_dissector` (8), `netfilter` (9), and `socket_filter` (10).
- Workload coverage is still dominated by tracing/observability and networking datapaths. Underrepresented categories are socket-layer service-mesh datapaths (`sk_msg`/`sk_skb`), tunnel and segment-routing pipelines, production netfilter/NAT firewalls, storage/filesystem-heavy workloads, and honest runnable security/LSM deployments with attach+trigger automation.

## Round-3 Additions And Runnability

| Source | Objects | Inventory ok | Inventory fail | Programs | Loadable | Site-bearing | Total sites | Truly runnable | Notes |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| `scx` | 4 | 4 | 0 | 85 | 39 | 13 | 50 | 0 | adds struct_ops-heavy sched_ext hot path; scx_lavd still 0/46 loadable |
| `tetragon` | 23 | 23 | 0 | 90 | 14 | 0 | 0 | 0 | security/tracing breadth improves, but attach/trigger paths are still missing |
| `systemd` | 6 | 6 | 0 | 14 | 9 | 4 | 4 | 0 | reproducible source-backed rebuild; adds cgroup_sysctl and LSM coverage |
| `netbird` | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | source-backed rebuild succeeded, but libbpf open still fails on legacy maps |
| `linux-selftests (5 new objects)` | 5 | 5 | 0 | 14 | 13 | 6 | 12 | 10 | closes flow_dissector, sk_reuseport, and cgroup_skb gaps |

### Objects Added Or Rebuilt This Round

- `scx`: `scx_bpfland_main.bpf.o`, `scx_flash_main.bpf.o`, `scx_lavd_main.bpf.o`, `scx_rusty_main.bpf.o`.
- `tetragon`: promoted 23 upstream objects including `bpf_execve_event.bpf.o`, `bpf_generic_kprobe.bpf.o`, `bpf_generic_tracepoint.bpf.o`, `bpf_generic_rawtp.bpf.o`, `bpf_generic_lsm_core.bpf.o`, `bpf_cgroup*.bpf.o`, and enforcement variants.
- `systemd`: rebuilt `bind-iface.bpf.o`, `restrict-fs.bpf.o`, `restrict-ifaces.bpf.o`, `socket-bind.bpf.o`, `sysctl-monitor.bpf.o`, and `userns-restrict.bpf.o` from upstream sources.
- `netbird`: rebuilt `prog.bpf.o` from `client/firewall/uspfilter/ebpf/prog.c` using the new compatibility header `corpus/include/netbird_legacy_bpf_map_def.h`.
- `linux-selftests`: added `bpf_flow.bpf.o`, `cgroup_skb_sk_lookup_kern.bpf.o`, `test_assign_reuse.bpf.o`, `test_migrate_reuseport.bpf.o`, and `trace_dummy_st_ops.bpf.o`.

## Updated Corpus Totals

| Metric | Baseline | Current merged total | Delta |
| --- | ---: | ---: | ---: |
| On-disk `.bpf.o` files | 532 | 560 | +28 |
| Inventoryable objects | 433 | 463 | +30 |
| Programs discovered | 1836 | 2010 | +174 |
| Loadable programs | 1214 | 1280 | +66 |
| Directive-bearing programs | 274 | 293 | +19 |
| Packet-runnable programs | 166 | 176 | +10 |
| Paired baseline/recompile programs | 79 | 84 | +5 |
| Truly runnable programs | 381 | 391 | +10 |
| CMOV sites | 840 | 894 | +54 |
| WIDE sites | 389 | 396 | +7 |
| ROTATE sites | 1840 | 1840 | +0 |
| LEA sites | 0 | 1 | +1 |

## Remaining Gaps

- `scx` is now represented well enough for directive census work, but it is still not truly runnable in the current harness because struct_ops registration and sched_ext lifecycle management are outside `test_run`.
- `tetragon`, `tracee`, and `KubeArmor` now give strong security/tracing breadth, but the corpus still lacks production-grade attach+trigger automation for most of those programs; they are largely load-only inputs today.
- `netbird`, `cilium`, and `opentelemetry-ebpf-profiler` remain blocked at object-open time; they need either older/libbpf-compatible objects, explicit legacy-map handling, or composite-link support in the runner.
- Linux selftests still account for most inventory failures (89/97), so future rounds should prioritize a small curated subset of additional selftests that actually open and diversify prog types rather than bulk-promoting more selftest objects.

## Artifacts

- Manifest: `config/corpus_manifest.yaml`
- Priority-source rerun: `docs/tmp/corpus-expansion-round3-priority-runnability.md` / `.json`
- New selftests rerun: `docs/tmp/corpus-expansion-round3-selftests-runnability.md` / `.json`
- This summary: `docs/tmp/corpus-expansion-round3.md`
