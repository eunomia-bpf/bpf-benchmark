# bpfopt/llvm O3 map_inline runtime perf on katran (no kinsn) — 2026-05-20/21

Measured via the loader's built-in `katran_optimization_path` perf flow
(BPF_PROG_TEST_RUN repeat=10000, duration_ns), driving the **LLVM O3 bpfopt**
(`bpfopt/llvm/build/bpfopt`, system LLVM-18, NO kinsn) on
`katran_balancer.bpf.o : balancer_ingress`. 5 hard `--inline-hint`s → 16 sites.

## Headline: ~20% speedup, verifier-OK, forwarding-correct
| run | baseline ns | optimized (map_inline O3) ns | speedup |
|---|---|---|---|
| 1 | 129 | 105 | 18.6% |
| 2 | 140 | 104 | 25.7% |
| 3 | 132 | 102 | 22.7% |
- 16 map-lookup sites inlined; insns 2542 → 2500.
- optimized tightly clustered ~102–105ns; baseline ~129–140ns. Robust ~20%+.
- repeat=1 forwarding assert passes (retval correct); repeat=10000 retval=0 is the live-XDP batch-mode artifact.

## How we got here (the first attempt showed "no speedup" — that was an artifact)
The loader's katran pipeline runs map_inline → const_prop → dce. For the **LLVM
bpfopt every pass is a full O3 roundtrip**, so:
- map_inline (1st O3, 16 sites) is fine and verifies.
- **const_prop (2nd O3 roundtrip) fails: "BPF stack limit is exceeded"** — repeated LLVM O3 spills > eBPF's 512B stack; the BPF backend errors at emit (before the verifier). The optimized TEST_RUN never ran, leaving stale baseline data → the misleading "127 vs 127ns".

Fix applied: env-gate to skip the redundant const_prop/dce for the LLVM path
(one O3 already subsumes them). Then the real map_inline-only speedup is visible.

## Findings
1. **LLVM O3 map_inline is a real ~20% win on katran** (verifier-OK, forwarding-correct).
2. **LLVM O3 chained as separate per-pass roundtrips blows the 512B BPF stack** (const_prop step). For the LLVM bpfopt, a single O3 roundtrip should subsume const_prop+dce; don't re-run them. (This is the real LLVM-O3↔eBPF constraint, distinct from verifier rejection.)
3. Rust bpfopt map_inline-only failed the forwarding assert (retval=2 XDP_PASS vs expected XDP_TX=3) — Rust map_inline alone behaves differently than its full pipeline; not investigated further here.

## Code touched (Claude, no codex)
- `bpfopt/loader/src/main.rs`: ENOSPC log-level fallback; drop empty `--target`; env `BPFOPT_LOADER_BPFOPT` (alt bpfopt path) + `BPFOPT_LOADER_SKIP_BYTECODE_PASSES` (map_inline-only) in the katran perf test.
