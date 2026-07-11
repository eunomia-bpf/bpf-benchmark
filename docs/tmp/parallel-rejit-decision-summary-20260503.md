# Parallel REJIT Crash — Bug + Decision Summary

**Date**: 2026-05-03
**HEAD**: kernel `vendor/linux-framework` @ `37166911e` (mutex commits reverted)
**Status**: root cause identified, fix design analyzed, awaiting decision

## Bug

### One-line summary
Concurrent `BPF_PROG_REJIT` of tail-call-related programs panics the kernel
because in-place mutation of `prog->bpf_func` makes cached
`poke_tab.tailcall_target` addresses stale.

### Hard evidence (real panic, no speculation)

- Repro: `make vm-corpus SAMPLES=1` (22 apps, 16 CPU KVM, default 11-pass) —
  100% deterministic
- Crash point: `kernel BUG at arch/x86/net/bpf_jit_comp.c:4135` (RAX = `-EBUSY` =
  `-16` from `__bpf_arch_text_poke` cmpxchg failure)
- Call trace:
  ```
  bpf_arch_poke_desc_update+0xd8 (BUG_ON ret < 0)
  prog_array_map_poke_run+0xa2/0xe0
  bpf_prog_rejit_poke_target_phase+0xaf/0x100
  bpf_prog_rejit+0xc2f/0xff0
  __sys_bpf
  ```
- Crash thread: PID 23141, daemon trace shows `tid=23141` = `prog 120
  const_prop` ENTER (no EXIT)
- In-flight at crash: 6 otel progs concurrently in `kernel.rejit()` (120, 126,
  127, 129, 130, 131)
- Modules tainted: `bpf_select`, `bpf_rotate`, `bpf_prefetch`, `bpf_extract`,
  `bpf_endian`, `bpf_bulk_memory` (kop modules)

### Root cause (deduced from evidence)

upstream BPF assumes **`prog->bpf_func` is immutable after JIT**. All
`tailcall_target` poke addresses are computed from `caller.bpf_func + offset`
and stored in `caller.aux.poke_tab[i]` — they remain valid for the caller's
lifetime.

Our fork's `BPF_PROG_REJIT` violates this invariant by **in-place swapping**
`prog->bpf_func` (`bpf_prog_rejit_swap` at `kernel/bpf/syscall.c:3381`).
After swap:
- old `bpf_func` memory may be freed/reused (call_rcu deferred)
- but `caller.aux.poke_tab[i].tailcall_target` still points to old address
- a concurrent REJIT of a callee walks `map.poke_progs` → finds caller →
  reads stale `tailcall_target` → calls `__bpf_arch_text_poke(stale_addr,
  expected_old=jump_to_callee, ...)` → bytes at `stale_addr` are not what we
  expect → cmpxchg returns `-EBUSY` → `BUG_ON` panics

### Scope

**Only programs in tail-call relationships are affected.** Programs without
PROG_ARRAY entries or without `poke_tab` entries don't enter
`prog_array_map_poke_run` at all.

In our corpus: otel (perf_unwind chain), tetragon (tail call dispatch), some
bcc/cilium/calico programs. About 10-30% of programs by count, but throughput
contribution varies.

## Why upstream's existing `aux->poke_mutex` is not enough

`prog_array_map_poke_run` is already protected by `aux->poke_mutex` per
prog_array map. This is sufficient in upstream because the invariant
"`prog->bpf_func` is stable" makes `tailcall_target` addresses always valid.

Our REJIT introduces a NEW concurrency angle (cross-prog mutation of
`bpf_func`) that this mutex was never designed to cover.

## Fix options analyzed

| Option | LOC | Upstream acceptance | Safety | Effort |
|---|---|---|---|---|
| X1: RCU prog replacement (don't mutate `bpf_func` in place; allocate new prog, RCU-swap all references, preserve prog_id via `idr_replace`) | +1700 / -560 net +1160, 18-35 files | **moderate** (the only design upstream would seriously consider) | high (preserves all upstream invariants) | **25-35 person-days** |
| X2: hold all referenced map `poke_mutex` during REJIT swap + update own poke_tab.tailcall_target | ~50-100 LOC | low-to-moderate (still mutates `bpf_func`; upstream will ask "why not RCU?") | medium (lock ordering risk: must sort by map_id to avoid deadlock) | 2-5 days |
| Narrow mutex: serialize REJIT only for progs with PROG_ARRAY relationships (caller poke_tab OR callee in prog_array) | ~10-15 LOC daemon-side | n/a (fork-only userspace workaround) | high (no kernel changes; non-tail-call progs stay parallel) | hours |
| Global mutex: serialize ALL REJIT regardless | 5 LOC kernel | extremely low (obvious bottleneck) | high | hours |
| X3: BUG_ON → retry on EBUSY | 5 LOC | none (hides the bug) | low (silent wrong behavior possible) | hours |

Detailed analysis: `docs/tmp/x1-rcu-rejit-patch-proposal-20260503.md` (940
lines, full mutation audit + reference owner table + diff sketch).

## Decision (recommended path)

### Short term — paper benchmark deadline
Use **narrow mutex** in daemon: detect programs with PROG_ARRAY relationships
via `prog_info.used_maps`, serialize only their REJIT through a single global
mutex. Other programs stay fully parallel.

This is fork-userspace-only, no kernel changes, ~10-15 LOC. Trade-off in
paper "Limitations":
- "Programs participating in tail call chains require serialized REJIT due to
  in-place mutation of `bpf_func`. This affects ~X% of corpus programs but
  does not bottleneck most apps. Future work: replace in-place REJIT with
  RCU-based program replacement to remove this restriction."

### Long term — upstream RFC
**X1 (RCU prog replacement)** is the only direction worth investing in for
upstream. Plan:
- Phase 1: Stable logical program identity (preserve prog_id via
  `idr_replace`) and FD/pin/link replacement registry (~10 days)
- Phase 2: Convert `bpf_prog_rejit` to allocate new `struct bpf_prog`, RCU
  swap all references, free old via grace period (~10 days)
- Phase 3: Per-owner replacement callbacks for prog_array, attached events,
  trampolines, XDP private refs (~10 days)
- Phase 4: Selftests + RFC submission (~5 days)

Estimated 25-35 person-days. **Not part of this paper cycle** — separate
follow-on project.

### Anti-recommendations
- Do **not** add a global mutex (it's worse than narrow mutex for the same
  result and harder to defend in paper)
- Do **not** ship X3 (BUG_ON → retry) — risks silent wrong behavior
- Do **not** ship X2 standalone — upstream review will reject it for the same
  reason as global mutex (the underlying invariant is still broken)

## Performance implications

| Scenario | in-place + narrow mutex | X1 RCU |
|---|---|---|
| Single REJIT latency | ~5ms | ~7ms (40% slower) |
| Parallel REJIT throughput (tail-call progs) | bottlenecked by mutex | full parallel |
| Parallel REJIT throughput (non-tail-call progs) | full parallel | full parallel |
| BPF program execution | identical, zero overhead | identical, zero overhead |
| Peak memory | baseline | ~2x prog size briefly during RCU grace period (KB scale, negligible) |

X1 has no net performance penalty; it actually improves throughput for batch
REJIT of tail-call programs.

## Related docs
- `docs/tmp/parallel-rejit-rootcause-analysis-20260503.md` — sonnet's
  preliminary analysis (200 lines)
- `docs/tmp/x1-rcu-rejit-patch-proposal-20260503.md` — codex's full X1
  proposal with mutation audit + diff sketch (940 lines)
- `docs/tmp/otel-mid-rejit-crash-investigation-20260503.md` — early
  (incorrect) "not reproducible" report, kept for context
- `docs/tmp/tetragon-287-batch-crash-investigation-20260503.md` — earlier
  related disk-fill investigation (different bug)
- `docs/tmp/prog43-e2big-rejit-investigation-20260503.md` — kernel page cap
  investigation (different bug)

## Diagnostics infrastructure added during this investigation (kept)
- `daemon/src/commands.rs`: per-pass REJIT enter/exit eprintln with
  thread-id, elapsed time
- `runner/libs/rejit.py`: daemon stderr/stdout to bind-mounted
  `corpus/results/<run>/details/daemon.{stderr,stdout}.log` so host can read
  after VM crash
- `runner/libs/vm.py`: preserve `script -qfec` pty log on KVM failure (for
  kernel panic backtrace), `vng --verbose` for kernel console capture, and
  `--append "loglevel=7 panic=30 oops=panic"` to defeat vng's default
  silencing of panic messages

These together gave us the smoking-gun evidence above.
