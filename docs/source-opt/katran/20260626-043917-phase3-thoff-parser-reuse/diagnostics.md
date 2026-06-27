# Diagnostics

## Build

- Clean source build command: `make -C vendor katran-x86`
- Candidate build command: `make -C vendor katran-x86`
- Restore build command: `make -C vendor katran-x86`
- All builds succeeded; see `clean-build.log`, `build.log`, and `restore-build.log`.

## Object Size / Instruction Proxy

Object inspected: `vendor/build/x86/katran/bpf/balancer.bpf.o`

| Variant | xdp section size | Approx BPF instruction slots | Note |
| --- | ---: | ---: | --- |
| clean upstream source | `0x4870` | 2318 | pre-attempt clean artifact |
| phase2 best base | `0x47b8` | 2295 | `cache-vip-metadata`, previous best |
| this attempt | `0x4760` | 2284 | phase2 best plus transport-offset reuse |
| restored source | `0x4870` | 2318 | after reverse patch and rebuild |

The candidate removed about 11 static BPF instruction slots relative to the phase2 best base and about 34 slots relative to clean source.

## Hot-Path Observation

The katran runner drives IPv4/UDP pktgen traffic with VIP flags enabling QUIC, global LRU, source/destination port hashing, UDP stable routing, and UDP flow migration. `parse_l3_headers()` already computes `th_off`, but the UDP parser, QUIC parser, and stable-routing parser each recomputed the transport offset through `calc_offset()`.

This attempt threaded the existing offset through those helpers. It preserved all packet bounds checks by keeping each parser's own `data + off + sizeof(...)` validation.

## Formal Result

| Metric | Value |
| --- | ---: |
| sample 1 pktgen_total_pps | 3337569 |
| sample 2 pktgen_total_pps | 3357814 |
| sample 3 pktgen_total_pps | 3320853 |
| mean pktgen_total_pps | 3338745 |
| total pktgen errors | 893490992 |
| vs clean baseline | +9.0676% |
| vs phase2 best | -0.3034% |

## Decision

Correctness passed, but the formal workload result did not beat the current katran phase2 best. Do not stack this patch. For the next katran attempt, change direction toward larger hot-path work: map/helper placement, stats-path cost, or branch layout around the fixed runner VIP flag mix, while preserving all fallback semantics.
