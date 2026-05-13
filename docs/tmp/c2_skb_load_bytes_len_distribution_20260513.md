# C2 skb_load_bytes len distribution (2026-05-13)

## Verdict
Keep a code-size cap; raise helper-id-26 `bpf_skb_load_bytes` from K=8 to K=20 only if we want the current corpus's remaining constant-length sites, and do not delete the cap.

## Methodology
Scanned the 542 canonicalized testbin optimizer inputs:

```sh
find bpfopt/testbin -mindepth 3 -maxdepth 3 -name canonicalize_output.bin -type f | wc -l
```

Decoder: inline Python using `struct.unpack("<BBhi")` for ABI `struct bpf_insn` bytes. A helper site is a regular helper call when `code == 0x85`, `src_reg == 0`, and `imm == 26` (`BPF_FUNC_skb_load_bytes`). For each site, the scanner searched the previous 8 linear instructions for `r4` constants. It handles `MOV64_IMM`, `MOV32_IMM`, `LDIMM64`, register moves, immediate add/sub chains, and `xor reg, reg` zeroing; it stops at prior helper calls that clobber caller-saved argument registers. The same scanner against `input_step0.bin` produced identical counts, so map-reference canonicalization did not affect the result.

Commands used for source cross-reference:

```sh
rg -n "bpf_skb_load_bytes|bpf_skb_load_bytes_relative|ctx_load_bytes|skb_load_bytes" bpfopt/testccode -g '*.c' -g '*.h'
rg -n "ctx_load_bytes|skb_load_bytes\\(|bpf_skb_load_bytes\\(|load_bytes_relative" runner/repos/cilium/bpf -g '*.c' -g '*.h'
```

Control scan for Tracee's relative helper used helper id 68 (`BPF_FUNC_skb_load_bytes_relative`) only for source-pattern context; it is not included in the cap tables because the pass under review targets helper id 26.

## Histogram

| len bucket | site count | cumulative count |
| --- | ---: | ---: |
| 1 | 48 | 48 |
| 2 | 66 | 114 |
| 3 | 0 | 114 |
| 4 | 45 | 159 |
| 5 | 0 | 159 |
| 6 | 11 | 170 |
| 7 | 2 | 172 |
| 8 | 19 | 191 |
| 9-16 | 0 | 191 |
| 17-32 | 6 | 197 |
| 33-64 | 0 | 197 |
| 65-128 | 0 | 197 |
| 129-256 | 0 | 197 |
| >256 | 0 | 197 |
| non-constant | 0 | 197 |

Observed exact constant lengths: 1, 2, 4, 6, 7, 8, 20. Helper id 26 had 197 sites, all with traceable constant `len`.

## Cap-vs-apply table

The "cost" column uses the requested formula `sum(9 + 2*len)` in BPF-instruction units. The byte estimate in parentheses is `cost * 8`, matching `bytes_xlated` byte units.

| cap K | sites retained | delta vs K=8 | total inline bytes added | per-app breakdown of top contributors |
| ---: | ---: | ---: | ---: | --- |
| 8 | 191 | +0 sites, +0 cost (+0 bytes) | 2903 cost (23224 bytes) | cilium_agent: 189 sites / 2857 cost; tracee_monitor: 2 / 46 |
| 16 | 191 | +0 sites, +0 cost (+0 bytes) | 2903 cost (23224 bytes) | cilium_agent: 189 sites / 2857 cost; tracee_monitor: 2 / 46 |
| 20 | 197 | +6 sites, +294 cost (+2352 bytes) | 3197 cost (25576 bytes) | cilium_agent: 195 sites / 3151 cost; tracee_monitor: 2 / 46 |
| 32 | 197 | +6 sites, +294 cost (+2352 bytes) | 3197 cost (25576 bytes) | cilium_agent: 195 sites / 3151 cost; tracee_monitor: 2 / 46 |
| 40 | 197 | +6 sites, +294 cost (+2352 bytes) | 3197 cost (25576 bytes) | cilium_agent: 195 sites / 3151 cost; tracee_monitor: 2 / 46 |
| 64 | 197 | +6 sites, +294 cost (+2352 bytes) | 3197 cost (25576 bytes) | cilium_agent: 195 sites / 3151 cost; tracee_monitor: 2 / 46 |
| 96 | 197 | +6 sites, +294 cost (+2352 bytes) | 3197 cost (25576 bytes) | cilium_agent: 195 sites / 3151 cost; tracee_monitor: 2 / 46 |
| 128 | 197 | +6 sites, +294 cost (+2352 bytes) | 3197 cost (25576 bytes) | cilium_agent: 195 sites / 3151 cost; tracee_monitor: 2 / 46 |

Per-app exact length distribution:

| app | len distribution |
| --- | --- |
| cilium_agent | 1: 48, 2: 66, 4: 45, 6: 11, 8: 19, 20: 6 |
| tracee_monitor | 7: 2 |

The only cap-driven growth from K=8 to K>=20 is Cilium: six `len == 20` sites in `tail_handle_snat_fwd_ipv4` and `tail_nodeport_nat_ingress_ipv4` variants. Tracee contributes no growth for helper id 26.

## Source patterns

`bpfopt/testccode/*.bpf.c` only exposes Tracee's direct helper calls. Cilium's top-level testccode files include Cilium headers, and `bpfopt/testccode/native_shims/cilium/bpf/ctx/skb.h` maps `ctx_load_bytes` to `skb_load_bytes`; the actual source call patterns are in `runner/repos/cilium/bpf/lib/*.h`.

| N | emitting app | source pattern |
| ---: | --- | --- |
| 1 | cilium_agent | single-byte header fields: IPv4 option type/length in `lib/ip_options.h`, IPv6 hop-limit/nexthdr in `lib/ipv6.h`, ICMP/ICMPv6 type in conntrack/NAT paths |
| 2 | cilium_agent | `sizeof(__be16)`, TCP flags, ICMP identifiers, IPv6 payload length, single L4 port loads |
| 4 | cilium_agent | IPv4 daddr (`offsetof(struct iphdr, daddr)`), two-port L4 loads (`2 * sizeof(__be16)`), 32-bit IPv4 option payloads |
| 6 | cilium_agent | Ethernet MAC address loads via `ETH_ALEN` in `lib/eth.h` |
| 7 | tracee_monitor | `bpf_skb_load_bytes(skb, l7_off, http_min_str, http_min_len)` in `net_l7_is_http`; bytecode materializes `http_min_len == 7` |
| 8 | cilium_agent | `struct icmphdr`, `struct icmp6hdr`, IPv6 fragment header, and IPv4 DSR option sized copies |
| 20 | cilium_agent | `sizeof(struct iphdr)` embedded IPv4 header copies in NAT / NodePort ICMP and DSR paths |

Tracee also has `bpf_skb_load_bytes_relative` source calls for L3/L4 header copies. The helper-id-68 control scan found 6 relative-helper sites in `tracee_monitor`: 2 constant `len == 40` and 4 non-constant. These are driven by `bpf_core_type_size(struct ipv6hdr)`, IPv4 IHL-dependent rereads, and protocol-dependent TCP/UDP header copies. They are outside the helper-id-26 cap under review.

## Recommended cap
Use K=20 if changing the policy. It covers all currently observed constant helper-id-26 sites with only six additional Cilium sites and +294 formula-cost units (+2352 `bytes_xlated` bytes) over K=8. K=16 has zero benefit, and K>20 has zero current coverage benefit while loosening the future code-size budget. If runtime benchmarks do not show a measurable win for the six added Cilium IPv4-header sites, keep K=8.
