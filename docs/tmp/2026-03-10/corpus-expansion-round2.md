# Corpus Expansion Round 2

Generated on 2026-03-10.

## Summary

- Baseline corpus size from the task brief: 493 `.bpf.o` files.
- New `.bpf.o` files added in this round: 21.
- Current on-disk count after promotion into `corpus/build/`: 514.
- New XDP/TC objects: 14 of 21.
- Total directive sites across the 21 new objects: 2146.
- Highest-value additions for networking workloads are `loxilb` TC, `calico` TC/XDP, and `suricata` XDP.

## Projects Attempted

| Source | Repo | Outcome | Notes |
| --- | --- | --- | --- |
| Cloudflare `tubular` | [cloudflare/tubular](https://github.com/cloudflare/tubular) | Promoted | Compiled 1 networking `sk_lookup` dispatcher program. |
| Cloudflare `flowtrackd` | expected `cloudflare/flowtrackd` | Not found | GitHub repo was not publicly reachable at that path on 2026-03-10. |
| Cloudflare `xdp-filter` | expected `cloudflare/xdp-filter` | Not found | GitHub repo was not publicly reachable at that path on 2026-03-10. |
| Cloudflare `rakelern` | name as provided | Not found | No public GitHub repo was identifiable from the provided name. |
| Meta `fboss` | [facebook/fboss](https://github.com/facebook/fboss) | Scanned, not promoted | Public repo exists, but shallow tree scan did not turn up production `*.bpf.c` / `*_kern.c` networking sources. |
| Meta `bpfilter` | expected `facebookincubator/bpfilter` | Not found | No public repo at the expected GitHub path. |
| Suricata | [OISF/suricata](https://github.com/OISF/suricata) | Promoted | Compiled 2 XDP programs from `ebpf/`. |
| DPDK | [DPDK/dpdk](https://github.com/DPDK/dpdk) | Scanned, not promoted | Tree contains a user-space/test BPF engine, but not attractive Linux eBPF XDP/TC production objects for this corpus round. |
| Calico | [projectcalico/calico](https://github.com/projectcalico/calico) | Promoted | Compiled 8 representative `felix/bpf-gpl` XDP/TC build variants. |
| Falco | [falcosecurity/libs](https://github.com/falcosecurity/libs) | Scanned, not promoted | Large tracing corpus, but lower value than networking datapaths for this round. |
| Pixie/Stirling | [pixie-io/pixie](https://github.com/pixie-io/pixie) | Scanned, not promoted | Shallow scan found testing/BCC tracing sources, not production XDP/TC datapaths. |
| systemd | [systemd/systemd](https://github.com/systemd/systemd) | Promoted | Compiled 6 cgroup/LSM programs. |
| iproute2 | [iproute2/iproute2](https://github.com/iproute2/iproute2) | Scanned, not promoted | Mostly examples/tooling; not promoted as production-grade application corpus inputs. |
| Linux `samples/bpf/` | local `vendor/linux-framework/samples/bpf` | Scanned, not promoted | Useful examples exist, but they overlap existing kernel/selftest coverage and are not production applications. |
| bpftrace | [iovisor/bpftrace](https://github.com/iovisor/bpftrace) | Scanned, not promoted | AOT stdlib/tracing programs exist, but not a networking-focused win for this round. |
| aya-rs examples | [aya-rs/aya](https://github.com/aya-rs/aya) | Scanned, not promoted | Integration-test examples only. |
| libbpf-rs examples | [libbpf/libbpf-rs](https://github.com/libbpf/libbpf-rs) | Scanned, not promoted | Examples/tests only; lower production value than Calico/LoxiLB/Suricata. |
| Netbird | [netbirdio/netbird](https://github.com/netbirdio/netbird) | Promoted | Compiled 1 XDP program. |
| Loxilb | [loxilb-io/loxilb](https://github.com/loxilb-io/loxilb) + [loxilb-io/loxilb-ebpf](https://github.com/loxilb-io/loxilb-ebpf) | Promoted | Main repo points at the separate eBPF tree; compiled 3 XDP/TC objects from `loxilb-ebpf`. |

## New Objects By Project

| Project | New objects | Hooks | Instructions | ROTATE | WIDE | LEA | CMOV | Total sites |
| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `calico` | 8 | XDP, TC | 158995 | 10 | 108 | 0 | 196 | 314 |
| `loxilb` | 3 | XDP, TC | 77619 | 0 | 1729 | 0 | 98 | 1827 |
| `netbird` | 1 | XDP | 264 | 0 | 0 | 0 | 0 | 0 |
| `suricata` | 2 | XDP | 744 | 0 | 0 | 0 | 2 | 2 |
| `systemd` | 6 | cgroup, LSM | 668 | 0 | 0 | 0 | 3 | 3 |
| `tubular` | 1 | `sk_lookup` | 124 | 0 | 0 | 0 | 0 | 0 |
| **Total** | **21** |  | **238414** | **10** | **1837** | **0** | **299** | **2146** |

## Directive Site Counts Per Program

| Project | Program | Hook sections | Insns | ROTATE | WIDE | LEA | CMOV | Total |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `tubular` | `inet-kern.bpf.o` | `sk_lookup/dispatcher` | 124 | 0 | 0 | 0 | 0 | 0 |
| `suricata` | `xdp_filter.bpf.o` | `xdp` | 334 | 0 | 0 | 0 | 1 | 1 |
| `suricata` | `xdp_lb.bpf.o` | `xdp` | 410 | 0 | 0 | 0 | 1 | 1 |
| `calico` | `xdp_debug.bpf.o` | `xdp` | 1435 | 0 | 4 | 0 | 0 | 4 |
| `calico` | `xdp_no_log.bpf.o` | `xdp` | 416 | 0 | 2 | 0 | 0 | 2 |
| `calico` | `from_wep_debug.bpf.o` | `tc` | 24628 | 0 | 14 | 0 | 23 | 37 |
| `calico` | `to_wep_debug.bpf.o` | `tc` | 18809 | 0 | 16 | 0 | 28 | 44 |
| `calico` | `from_hep_debug.bpf.o` | `tc` | 28053 | 10 | 18 | 0 | 34 | 62 |
| `calico` | `to_hep_debug.bpf.o` | `tc` | 30897 | 0 | 20 | 0 | 40 | 60 |
| `calico` | `from_nat_debug.bpf.o` | `tc` | 24102 | 0 | 14 | 0 | 31 | 45 |
| `calico` | `to_nat_debug.bpf.o` | `tc` | 30655 | 0 | 20 | 0 | 40 | 60 |
| `loxilb` | `llb_xdp_main.bpf.o` | `xdp_packet_hook`, `xdp_pass` | 1786 | 0 | 3 | 0 | 0 | 3 |
| `loxilb` | `llb_ebpf_main.bpf.o` | `.text`, `tc_packet_hook0..7` | 37895 | 0 | 863 | 0 | 49 | 912 |
| `loxilb` | `llb_ebpf_emain.bpf.o` | `.text`, `tc_packet_hook0..7` | 37938 | 0 | 863 | 0 | 49 | 912 |
| `netbird` | `prog.bpf.o` | `.text`, `xdp` | 264 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | `bind-iface.bpf.o` | `cgroup/sock_create` | 6 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | `restrict-fs.bpf.o` | `lsm/file_open` | 63 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | `restrict-ifaces.bpf.o` | `cgroup_skb/egress`, `cgroup_skb/ingress` | 38 | 0 | 0 | 0 | 2 | 2 |
| `systemd` | `socket-bind.bpf.o` | `cgroup/bind4`, `cgroup/bind6` | 164 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | `sysctl-monitor.bpf.o` | `.text`, `cgroup/sysctl` | 139 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | `userns-restrict.bpf.o` | `.text`, `lsm/path_*`, `task_fix_setgroups`, `kprobe/retire_userns_sysctls` | 258 | 0 | 0 | 0 | 1 | 1 |

## Notable Findings

- `loxilb/llb_ebpf_main.bpf.o` and `loxilb/llb_ebpf_emain.bpf.o` are the clear standouts: 912 sites each, dominated by 863 `WIDE` candidates plus 49 `CMOV` candidates. These are the best new TC datapath inputs from this round.
- `calico` contributes the best variety: 8 real TC/XDP variants, 314 total sites, and one of the few real production `ROTATE` hits in this sweep (`from_hep_debug.bpf.o`, 10 rotate sites).
- `suricata` adds two compact XDP programs that compile cleanly and already expose `CMOV` sites.
- `netbird` compiled cleanly only after adding a tiny legacy `struct bpf_map_def` compatibility header. The repo also ships prebuilt `bpf_bpfel.o`, which is a useful fallback signal if we want to harvest more Go-embedded eBPF projects later.
- `systemd` adds non-networking cgroup/LSM coverage; useful for corpus breadth, but these are not candidates for `bpf_prog_test_run` packet benchmarking.
- `cloudflare/tubular` is public and useful, but its public eBPF payload is `sk_lookup`, not XDP/TC.

## Build Notes

- Repos were shallow-cloned into `/tmp/bpf-corpus-round2/probes`.
- Successful objects were promoted into `corpus/build/<project>/`.
- The compile command was the requested `clang -O2 -g -target bpf -D__TARGET_ARCH_x86 ... -c ... -o ...` pattern, extended with repo-specific include paths plus a small temp compatibility include layer under `/tmp/bpf-corpus-round2/compat` to normalize older `linux/types.h` / `bpf_helpers.h` expectations.
- Directive counts were collected with the same matcher used by `micro.directive_census.analyze_object(...)`.
