# C4 ladder window growth cap evidence (2026-05-13)

## Verdict
Keep `MAX_LADDER_WINDOW_GROWTH = 24` for now: on the committed `bpfopt/testbin` corpus, raising the cap to 32/48/64/96/128/256 or removing it unlocks 0 additional ladders and 0 additional consumed guards.

## Methodology
Scanned all 542 per-program bytecode dumps under `bpfopt/testbin/*/*/canonicalize_output.bin`.
Program names and types came from `corpus/results/x86_kvm_corpus_20260510_080437_084009/details/apps/*.json`, which matches the testbin layout and counts:

| app | programs |
| --- | ---: |
| bcc/set | 21 |
| bpftrace/set | 9 |
| cilium/agent | 53 |
| katran | 1 |
| otelcol-ebpf-profiler/profiling | 13 |
| tetragon/observer | 287 |
| tracee/monitor | 158 |

Only packet-layout program types can enter `BoundsCheckMergePass`; this corpus has 52 such programs: 51 Cilium `sched_cls`/`xdp` programs and 1 Katran `xdp` program.

The scanner reimplemented the relevant `bounds_check_merge.rs` logic against `ProgramCFG`: `scan_guard_sites`, `detect_guard_candidate`, `can_extend_ladder`, and `interleaves_are_merge_safe`, with a parameterized cap. Guard detection required the same shape as the pass:

```text
mov tmp, root
add tmp, K
jgt/jlt/jge/jle tmp, data_end, slow_path
```

with lifted packet facts proving the same packet root/end, the same compare kind, the same slow target, monotonically increasing `window_end`, no branch/store interleaves, and no branch target entry in the removed setup/check. I then validated the current-cap result by running the real CLI over all 52 packet-layout testbin entries:

```text
actual bounds_check_merge CLI: sites_matched=1, sites_applied=0, sites_skipped=1
only nonzero report: katran/530_balancer_ingress, xdp, skipped PC 6 as "guard not part of a mergeable ladder"
```

The one matched guard decodes to a single Ethernet minimum-length check in Katran:

```text
pc 4: r1 = r8
pc 5: r1 += 14
pc 6: if r1 > r9 goto slow_path
```

No second merge-compatible guard follows it, so no cap value changes the result.

## Step-size histogram
No mergeable ladder edges were found in testbin, so every bucket is zero.

| step bucket | count |
| --- | ---: |
| 1-8 | 0 |
| 9-16 | 0 |
| 17-24 | 0 |
| 25-32 | 0 |
| 33-48 | 0 |
| 49-64 | 0 |
| 65-128 | 0 |
| >128 | 0 |

## Apply-count vs cap K table
`guards consumed` here means removable follow-on guards in accepted ladders, i.e. `sum(ladder_len - 1)`. Since there are no accepted ladders, the pass-level `sites_applied` is also 0 for every cap.

| K | ladders fitting cap | total guards consumed | delta vs K=24 | largest merged window | per-app contribution |
| --- | ---: | ---: | ---: | ---: | --- |
| 24 | 0 | 0 | 0 | none | none |
| 32 | 0 | 0 | 0 | none | none |
| 48 | 0 | 0 | 0 | none | none |
| 64 | 0 | 0 | 0 | none | none |
| 96 | 0 | 0 | 0 | none | none |
| 128 | 0 | 0 | 0 | none | none |
| 256 | 0 | 0 | 0 | none | none |
| no_cap | 0 | 0 | 0 | none | none |

## Split examples
None. No ladder is split by `K=24` in the testbin scan because no two guard candidates form a mergeable ladder even with `no_cap`.

Relevant near-miss in Katran `balancer_ingress`: source-level packet parsing does compile to larger later windows, but the bytecode is outside the current detector shape. For example, after the first matched `14`-byte check, later checks are separated from their setup by stores/reloads or use a different `data_end` register:

```text
pc 42: r3 = r7
pc 43: r3 += 34
pc 44: *(u64 *)(r10 -144) = r2
pc 45: if r3 > r2 goto slow_path

pc 65: r1 = r7
pc 66: r1 += 42
pc 67: r2 = *(u64 *)(r10 -144)
pc 68: if r1 > r2 goto slow_path
```

Those fail the pass's immediate `mov/add/compare` setup requirement, so relaxing the growth cap would not consume them.

## Source patterns
The expected protocol-window sizes are present in source, especially Katran and Cilium, but they do not currently survive as mergeable `scan_guard_sites` ladders in testbin.

Katran has explicit encapsulation bounds checks:

| source | window |
| --- | ---: |
| `katran_balancer.bpf.c:313` `sizeof(struct ipv6hdr) + sizeof(struct ethhdr)` | 54 |
| `katran_balancer.bpf.c:323` `sizeof(struct iphdr) + sizeof(struct ethhdr)` | 34 |
| `katran_balancer.bpf.c:333` `sizeof(struct ipv6hdr) + sizeof(struct ethhdr)` | 54 |
| `katran_balancer.bpf.c:447` `sizeof(struct ipv6hdr) + sizeof(struct ethhdr) + sizeof(struct udphdr) + 1` | 63 |
| `katran_balancer.bpf.c:469` `sizeof(struct iphdr) + sizeof(struct ethhdr) + sizeof(struct udphdr)` | 42 |

Cilium source uses repeated packet revalidation across host/lxc/wireguard/overlay/xdp paths: 44 `revalidate_data*()` call sites in the Cilium testccode files, plus two direct `ctx_no_room()` checks in `cilium_bpf_xdp.bpf.c`. The direct XDP examples are the expected Ethernet+IPv4 and Ethernet+IPv6 windows:

| source | pattern | window |
| --- | --- | ---: |
| `cilium_bpf_xdp.bpf.c:145-148` | `data + sizeof(struct ethhdr)` then `ipv4_hdr + 1` | 34 |
| `cilium_bpf_xdp.bpf.c:217-220` | `data + sizeof(struct ethhdr)` then `ipv6_hdr + 1` | 54 |

So the source-level intuition is valid: Cilium/Katran do contain Ethernet/IP/TCP/encapsulation growth patterns, including steps above 24. The current pass, however, does not see these as ladder candidates in committed testbin bytecode because the compiled code often reloads `data_end`, spills around the setup, or hides the bounds check behind helper-style revalidation.

## Recommended cap
Measured recommendation: keep 24. The cumulative apply rate plateaus immediately because all caps produce 0 consumed guards and no merged window.

If future detector work broadens `scan_guard_sites` to accept common compiled forms such as `mov/add; spill-or-reload-data_end; compare`, rerun this measurement before changing the cap. Based only on source-level protocol sizes, 64 would be the first cap worth testing because it covers Ethernet+IPv6+UDP/GUE marker windows up to 63 while still rejecting unbounded outliers; but testbin provides no apply-count evidence for that change today.
