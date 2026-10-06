# Diagnostics

Pre-run source inspection:
- `update_vip_lru_miss_stats()` computes `address_match`, `port_match`, and
  `proto_match` to decide whether the current VIP should update
  `lru_miss_stats`.
- The original `proto_match` expression used assignment:
  `lru_miss_stat_vip->proto = vip->proto`.
- That writes to `vip_miss_stats` on every LRU miss that reaches this helper
  and makes the proto condition true for nonzero protocol values.
- Replacing it with `==` preserves the intended match semantics and avoids the
  map-value write.

BPF object diagnostics:
- Clean xdp section: `0x4870`.
- Attempt 1 xdp section: `0x4798`.
- This stacked attempt xdp section: `0x4778`.
- `llvm-objdump -d --section=xdp` printed 2213 instruction lines for this
  object; section-size-derived instruction count is about 2287 because wide
  immediate loads occupy two BPF instruction slots.

Rejected diagnostic branch:
- A separate call-site-gate idea was built under
  `../20260625-171243-phase2-flow-migration-callsite-gate/`.
- It produced xdp section `0x47c8`, which was larger than attempt 1, so it was
  not promoted to a formal performance run.
