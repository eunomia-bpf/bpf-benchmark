# katran phase2 attempt: cache-vip-metadata

Status: accepted-for-analysis

## Hypothesis

The pktgen VIP uses several feature flags on the hot path. Cache `vip_info->flags`
and `vip_info->vip_num` into scalar locals after the VIP map lookup, then pass the
scalars through inlined helpers. This may reduce repeated map-value field reloads
and make the hot path easier for clang/verifier/JIT to optimize.

This attempt stacks the accepted phase2 attempt 1 guard:

- `check_udp_flow_migration()` now checks `*dst` instead of the address of the
  local destination pointer.

## Source changes

- `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Change selected inline helpers from `struct vip_meta *vip_info` arguments to
  scalar `vip_flags` / `vip_num` where only those fields are used.
- Remove unused `vip_info` / `is_ipv6` helper parameters in the global LRU miss
  path.
- Replace repeated `vip_info->flags` reads in `process_packet()` with a local
  `vip_flags`.

## Risk

Low-to-medium. The change should preserve map keys, packet rewrites, helper calls,
and return paths, but it touches multiple inlined helper signatures in the XDP hot
path. Correctness is gated by real katran startup, BPF load, and pktgen workload
success.

## Decision rule

Run the formal single-app source-opt benchmark. If throughput does not beat
phase2 attempt 1, do not stack this patch into future katran attempts.

## Result

- Result path: `corpus/results/x86_kvm_corpus_20260626_004646_185930`
- Primary metric: pktgen total pps mean `3348905`
- Samples: `3390361, 3336180, 3320175`
- Total pktgen errors: `1008452024`
- vs clean baseline mean `3061171`: `+9.40%`
- vs phase2 attempt 1 mean `3305186`: `+1.32%`

Decision: stack this patch as the current katran phase2 best base.
