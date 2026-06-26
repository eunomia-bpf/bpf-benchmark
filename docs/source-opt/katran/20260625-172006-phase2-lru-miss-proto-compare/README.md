# katran phase2 attempt: lru-miss proto compare

Status: completed-not-stacked

Goal: stack on the accepted UDP flow-migration `*dst` guard and remove an
unintended map-value write in the LRU miss stats path.

Patch summary:
- Keep the phase2 attempt 1 change: `check_udp_flow_migration()` requires
  `*dst` before checking UDP flow migration maps.
- Change `proto_match` from assignment to comparison in
  `update_vip_lru_miss_stats()`.

Correctness expectation:
- The `proto_match` line now matches the surrounding `address_match` and
  `port_match` semantics.
- `vip_miss_stats` is a selector/config map for which VIP's LRU misses should
  be counted; packet processing should not mutate its configured `proto`.

Diagnostic result before formal run:
- Clean `balancer.bpf.o` xdp section: `0x4870` bytes, about 2318 BPF insns.
- Phase2 attempt 1 xdp section: `0x4798` bytes, about 2291 BPF insns.
- This attempt xdp section: `0x4778` bytes, about 2287 BPF insns.
- Build log: `build.log`
- Patch: `source.diff`

Formal run:
- Command: `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_002120_778242`
- Performance: pktgen_total_pps mean=3288342; samples
  `3267504, 3316271, 3281251`; errors=1647406492.
- vs clean baseline: +7.42%.
- vs phase2 attempt 1: -0.51%.

Decision:
- Valid formal attempt and correctness gates passed.
- Do not stack this patch for the next katran attempt because it regressed
  relative to the phase2 attempt 1 base.
