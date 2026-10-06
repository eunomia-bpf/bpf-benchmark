# Diagnostics

## Build

- Base build command: `make -C vendor katran-x86`
- Candidate build command: `make -C vendor katran-x86`
- Restore build command: `make -C vendor katran-x86`
- All builds succeeded; see `base-build.log`, `build.log`, and `restore-build.log`.

## Object Size / Instruction Proxy

Object inspected: `vendor/build/x86/katran/bpf/balancer.bpf.o`

| Variant | xdp section size | Approx BPF instruction slots | Note |
| --- | ---: | ---: | --- |
| clean upstream source | `0x4870` | 2318 | restored artifact baseline |
| phase2 best base | `0x47b8` | 2295 | `cache-vip-metadata`, previous best |
| this attempt | `0x47c0` | 2296 | phase2 best plus QUIC CID version 0 early return |
| restored source | `0x4870` | 2318 | after reverse patch and rebuild |

The candidate added one static instruction slot relative to the phase2 best. The intended benefit was dynamic: pktgen's ordinary UDP payload should hit `connIdVersion == 0` and avoid the remaining v1/v2/v3 parser branches.

## Hot-Path Observation

The runner config sets `F_QUIC_VIP`, so UDP pktgen traffic enters `parse_quic()` even though the payload is not generated as QUIC. Katran's parser uses the top two bits of `connId[0]` as the CID version and only implements versions 1, 2, and 3 for server-id extraction. Version 0 already falls through with `server_id=FURTHER_PROCESSING`, causing CH fallback.

This attempt made that fallback explicit immediately after computing `connIdVersion`.

## Formal Result

| Metric | Value |
| --- | ---: |
| sample 1 pktgen_total_pps | 3276898 |
| sample 2 pktgen_total_pps | 3371790 |
| sample 3 pktgen_total_pps | 3313690 |
| mean pktgen_total_pps | 3320793 |
| total pktgen errors | 716551110 |
| vs clean baseline | +8.4811% |
| vs phase2 best | -0.8394% |

## Decision

Correctness passed, but the formal workload result was below the current katran phase2 best. Do not stack this patch. The next katran phase3 attempt should switch away from parser micro-optimizations and focus on heavier per-packet work: `is_under_flood()` / conn-rate stats, LRU miss stats, or repeated stats map updates.
