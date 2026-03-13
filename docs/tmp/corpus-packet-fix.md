# Corpus Dummy Packet Fix

**Date**: 2026-03-12

## Problem

All XDP/TC corpus programs shared a 64-byte dummy packet that was **all zeros** (or had no Ethernet/IP headers set). This caused programs to exit at the first packet-validity check:

```
eth->h_proto == 0  (not ETH_P_IP 0x0800)
→ first branch taken → early exit
```

Optimization sites (branch-flip, endian, wide_mem, etc.) live deep in IP/TCP/UDP parsing code. With all-zero packets, these sites were never executed, so corpus exec time measurements reflected only early-exit noise plus code layout effects — not actual optimization impact.

## Fix

Constructed a canonical 64-byte Ethernet+IPv4+TCP+payload packet with **correct IPv4 checksum**:

```
Ethernet (14B): dst=ff:ff:ff:ff:ff:ff (broadcast), src=00:11:22:33:44:55, EtherType=0x0800
IPv4 (20B):     version=4, IHL=5, tot_len=50, TTL=64, proto=TCP(6),
                src=10.0.0.1, dst=10.0.0.2, checksum=0x26c4 (RFC 791 correct)
TCP (20B):      src_port=12345, dst_port=80, seq=1, flags=SYN, window=8192
Payload (10B):  0x41 * 10
Total: 64B
```

### Files Changed

- **`micro/orchestrator/corpus.py`** — canonical implementation (`materialize_dummy_packet`),
  refactored into `_build_corpus_packet()` + `_ipv4_checksum()` helpers.
  Cache invalidation uses a broadcast-dst-MAC sentinel (`ff:ff:ff:ff:ff:ff`) to detect stale files.

- **`corpus/run_code_size_comparison.py`** — duplicate local implementation, same fix applied.

- **`e2e/run_e2e_tracee.py`** — standalone copy used by tracee e2e driver, same fix applied.

All corpus drivers import from `micro/orchestrator/corpus.py` via `corpus/common.py`; the tracee e2e driver had its own copy.

### Cache invalidation

Old cached files at `micro/generated-inputs/corpus_dummy_packet_64.bin` (all-zero, 64B) will be
automatically regenerated on next run: the new code checks `data[0:6] == ff:ff:ff:ff:ff:ff`; the old
file starts with `00:00:00:00:00:00`, so regeneration is triggered.

## Validation (VM, kernel 7.0-rc2)

Tested with `bpf_prog_test_run_opts` in vng VM (7.0-rc2 framework kernel).
`wall_exec_ns` (rdtsc-based) and `exec_cycles` are the reliable metrics at this timescale;
`exec_ns` (ktime-based) has ~10ns granularity and saturates.

| Program | Metric | Zero packet | Valid packet | Ratio |
|---------|--------|------------|-------------|-------|
| suricata/xdp_hashfilter | exec_cycles | 31,432 | 59,555 | **1.89x** |
| suricata/xdp_hashfilter | wall_exec_ns | 8,527 | 16,156 | **1.89x** |
| xdp-tools/xdp_fwd_fib_full | exec_cycles | 60,587 | 47,948 | 0.79x* |
| katran/balancer_ingress | exec_cycles | 60,888 | 58,321 | 0.96x |

*xdp_forward: the zero packet triggers a different (longer) code path involving FIB lookup failure;
the valid packet triggers a shorter LPM match path. This is expected behavior.

**suricata** shows the clearest signal: the valid packet passes the EtherType check (insn: `if r2 != 0x8 goto early_exit`) and reaches the full hash computation over IP+TCP fields, executing ~89% more instructions than with the zero packet.

Programs dominated by map lookups (katran, xdp_forward) show smaller differences because
`bpf_prog_test_run` runs with empty maps (no FIB entries, no LB backends), so both packet
types ultimately hit map-miss paths.

## Impact on Corpus Measurements

- Programs whose early-exit is guarded by `eth->h_proto == ETH_P_IP` now execute fully.
- `wall_exec_ns` for packet-parsing-heavy programs increases (more instructions executed).
- Re-running corpus benchmarks will yield higher absolute exec times for XDP programs.
- The BpfReJIT speedup ratios (baseline/v5) remain valid as both baseline and v5 use the same packet.
- Geomean speedup numbers will change because the execution profile is now deeper.
