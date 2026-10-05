# katran phase2 attempt: cache-vip-plus-lru-proto-compare

Status: completed-not-stacked

## Hypothesis

Stack phase2 attempt 3 (`cache-vip-metadata`) and fix the LRU miss stats
protocol comparison from assignment to equality:

```c
bool proto_match = lru_miss_stat_vip->proto == vip->proto;
```

The standalone `lru-miss-proto-compare` attempt was not stacked because it was
slower than phase2 attempt 1, but in combination with attempt 3 it reduces the
generated XDP section and also removes a source-level correctness bug in the
stats path.

## Source changes

- `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Includes all phase2 attempt 3 changes.
- Adds the `proto_match` comparison fix in `update_vip_lru_miss_stats()`.

## Risk

Low. The change affects LRU miss stats matching only; routing, map layout,
packet rewrite behavior, and workload setup are unchanged.

## Decision rule

Run the formal single-app source-opt benchmark. Stack this patch only if it
beats phase2 attempt 3.

## Result

- Result path: `corpus/results/x86_kvm_corpus_20260626_011245_701549`
- App result: `corpus/results/x86_kvm_corpus_20260626_011245_701549/details/apps/katran.json`
- Correctness: passed; suite/app status `ok`, `error=""`, `post_rejit=null`,
  `rejit_result.mode="skip_rejit_all"`, 3 workload samples, all component
  return codes 0.
- Primary metric: pktgen total pps mean = 3275764.
- Samples: `3272779, 3268211, 3286301`
- Errors: `555914286, 558097506, 545701692` (total 1659713484)
- vs clean baseline: +7.01%
- vs phase2 attempt 1: -0.89%
- vs phase2 attempt 3: -2.18%
- Source/artifact restored: yes; `balancer.bpf.o` XDP section returned to
  clean `0x4870`.

## Decision

Do not stack. The source-level stats fix is valid, and the combined patch
reduces emitted XDP size from attempt 3, but the formal workload result is
slower than the current best phase2 base.
