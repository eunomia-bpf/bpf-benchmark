# katran phase2 diagnostic: lru-miss-early-mismatch

Status: rejected-before-formal-run

## Hypothesis

Stack phase2 attempt 3 (`cache-vip-metadata`) and rewrite
`update_vip_lru_miss_stats()` so the default non-matching `vip_miss_stats`
configuration returns after the address mismatch instead of computing separate
address/port/proto booleans. This also replaces the original protocol
assignment with an equality check.

## Source changes

- `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Includes all phase2 attempt 3 changes.
- Changes the miss-stats VIP match into explicit mismatch early returns.

## Diagnostic Result

Rejected before a formal run. The patch builds and is semantically cleaner, but
the generated XDP program is larger than the current best phase2 base.

- clean source XDP section: `0x4870`
- phase2 attempt 3 XDP section: `0x47b8`
- this candidate XDP section: `0x47c8`
- displayed XDP instruction lines: 2223

## Decision

Do not run formally and do not stack. This is a stats-path cleanup with a small
static regression, and the previous stats-path formal run underperformed.
