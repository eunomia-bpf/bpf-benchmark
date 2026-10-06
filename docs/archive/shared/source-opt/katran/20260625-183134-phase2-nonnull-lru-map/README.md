# katran phase2 attempt: nonnull-lru-map

Status: completed-not-stacked

## Hypothesis

Stack phase2 attempt 3 (`cache-vip-metadata`) and remove redundant `lru_map`
null checks after `process_packet()` has already selected either the per-CPU LRU
map or `fallback_cache`. The intended benefit is a smaller branch dependency in
the packet hot path without changing map layout, routing policy, statistics, or
workload behavior.

## Source changes

- `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Includes all phase2 attempt 3 changes.
- Removes two `lru_map &&` guards in paths reached only after `lru_map` has
  been made non-null.

## Risk

Low. The code already assigns `lru_map = &fallback_cache` or returns before the
changed call sites. No packet metadata, map ABI, tail-call layout, or stats key
is changed.

## Decision rule

Run the formal single-app source-opt benchmark. Stack this patch only if it
beats phase2 attempt 3.

## Result

- Result path: `corpus/results/x86_kvm_corpus_20260626_013906_982440`
- App result: `corpus/results/x86_kvm_corpus_20260626_013906_982440/details/apps/katran.json`
- Correctness: passed; suite/app status `ok`, `error=""`, `post_rejit=null`,
  `rejit_result.mode="skip_rejit_all"`, 3 workload samples, all component
  return codes 0.
- Primary metric: pktgen total pps mean = 3301431.
- Samples: `3317221, 3295753, 3291320`
- Errors: `526151700, 541091256, 533465066` (total 1600708022)
- vs clean baseline: +7.85%
- vs phase2 attempt 1: -0.11%
- vs phase2 attempt 3: -1.42%
- Source/artifact restored: yes; `balancer.bpf.o` XDP section returned to
  clean `0x4870`.

## Decision

Do not stack. The patch preserved correctness but did not beat the current best
phase2 base (`cache-vip-metadata`).
