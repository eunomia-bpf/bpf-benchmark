# katran phase2 diagnostic: reuse-transport-offset

Status: rejected-before-formal-run

## Hypothesis

Stack phase2 attempt 3 (`cache-vip-metadata`) and reuse the transport-header
offset already computed by `parse_l3_headers()` when parsing TCP, UDP, QUIC,
and UDP stable-routing headers. The intended hot-path benefit is to avoid
recomputing `calc_offset()` for ordinary non-ICMP IPv4/UDP pktgen packets while
preserving the original ICMP inner-packet offset behavior.

## Source changes

- `vendor/repos/katran/katran/lib/bpf/balancer.c`
- `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Includes all phase2 attempt 3 changes.
- Changes parser signatures to accept `th_off`; ICMP paths still recompute the
  original inner transport offset with `calc_offset()`.

## Diagnostic Result

Rejected before a formal run. The patch builds, but the generated XDP program
is much larger than both clean source and the current best phase2 base.

- clean source XDP section: `0x4870`
- phase2 attempt 3 XDP section: `0x47b8`
- this candidate XDP section: `0x4af8`
- displayed XDP instruction lines: 2325

## Decision

Do not run formally and do not stack. The extra parameter plumbing and ICMP
guards increase verifier-visible code enough that the hot-path offset reuse is
not worth testing as-is.
