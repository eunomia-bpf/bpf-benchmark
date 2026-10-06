# Verifier-PC vs Raw-PC Namespace Divergence — Root Cause

Empirical investigation following codex's 2026-05-13 report.

## Root cause (different from codex hypothesis)

**Kernel verifier patches `(sidecar, kinsn_call)` pairs into multi-insn proof sequences DURING `do_check()`, then restores them after `do_check()` completes.** The verifier log emitted at `log_level=2` is in the **proof-expanded** PC space, not the user-bytecode PC space.

Code path: `vendor/linux-framework/kernel/bpf/verifier.c:3795–3810` — for every kinsn region:
- `verifier_remove_insns(env, i-1, 1)` removes the sidecar
- `bpf_patch_insn_data(env, i-1, proof_buf, cnt)` inserts `cnt` proof-sequence insns
- `do_check()` walks this expanded program (PCs in expanded space)
- `restore_kinsn_proof_regions()` reverses the patches before JIT/return

Each kinsn's `proof_len` is module-specific (rotate / cond_select / extract / endian_fusion / ccmp / bulk_memory / prefetch all have different proof lengths). There is no log-side marker recording region boundaries (`verifier_log_step14.log` contains zero `kinsn` / `proof` / `region` strings).

## Empirical evidence (katran prog 9, 17-step pipeline)

| quantity | value |
|---|---|
| raw `output_step14.bin` slots | 2456 |
| LD_IMM64 second slots | 83 |
| kinsn `(sidecar, call)` pairs | 69 |
| pseudo-subprog calls | 3 at raw PC 1293, 1296, 1980 |
| max verifier-log PC | **2493** (raw max is 2455) |

Tested four "simple skip" hypotheses for raw_pc → verifier_pc:

| hypothesis | total verifier PCs |
|---|---|
| (A) no skip | 2456 |
| (B) skip LD_IMM64 second slot | 2373 |
| (C) skip kinsn sidecar slot | 2387 |
| (D) skip both | 2304 |

None match observed verifier max PC = 2493 — verifier sees **more** insns than raw, not fewer. This contradicts the "skip sidecars" hypothesis from the prior report.

Verifier expansion budget:
```
verifier_size = raw_size − 2·num_kinsn_pairs + Σ proof_len[k]
2493         = 2456     − 138                + Σ proof_len[k]
Σ proof_len[k] = 175 → average 2.54 insns per kinsn
```

This matches the kernel code: each `(sidecar, call)` 2-slot pair is replaced by a proof sequence whose length depends on the kinsn module.

## Why step 1 map_inline works but step 15 const_prop fails

- Step 0 noop → verifier log on the **original user bytecode** (no kinsn yet) → PC namespace matches raw → step 1 map_inline lifts cleanly.
- Steps 4–10 apply kinsn passes (rotate, cond_select, extract, endian_fusion, ccmp, bulk_memory, prefetch) → bytecode now has 69 sidecar+call pairs.
- Step 14 noop → kernel verifies the kinsn-bearing bytecode → log PCs are in proof-expanded space → step 15 const_prop's lifter looks up `pc 2425` in user-bytecode space, finds it's an LD_IMM64 second slot, bails.

## Fix options

### Option A — minimal config change (1 yaml line)
Remove `const_prop` from the trailing pass list in `corpus/config/benchmark_config.yaml`. The "second const_prop after kinsn" was speculative; first const_prop already applied at 15 sites in this run. `dce` does not consume verifier states (per pass registry) and can stay if useful.

LOC delta: ~1 line yaml.

### Option B — bpfopt-side verifier-PC remapper
Build a per-kinsn `proof_len` table mirroring the kernel modules. At lift time, walk the bytecode, compute `verifier_pc[raw_pc]` accounting for proof-sequence expansion at each kinsn site. Use this for state-site lookup.

LOC delta: 200–500 lines, fragile (kernel-drift risk: each new kinsn module must register its proof_len here, and the kernel's `instantiate_insn()` output count varies by sidecar payload, so we'd need to replicate kernel logic in userspace).

### Option C — no verifier-state passes after kinsn (policy)
Run all `needs_verifier_states=true` passes (map_inline, const_prop, bulk_memory) **before** kinsn-emitting passes. Bulk_memory already does this poorly in current `full` policy: it sits at step 9 between ccmp (step 8) and prefetch (step 10), but receives only log_level=1 from step 8 (no useful states; applied=0 confirms it sees nothing). Move bulk_memory before kinsn passes too.

LOC delta: yaml reorder + maybe verify bulk_memory needs_verifier_states is actually being honored.

## Recommendation

Option A for immediate use. Document the constraint in CLAUDE.md or pass-policy comments: "verifier-state consumers must run before kinsn-emitting passes; trailing const_prop/dce after kinsn is currently unsupported."

Don't pursue Option B unless paper results show double-const_prop is worth >200 LOC of kernel-coupled remapper code.

## Independent issue: bulk_memory at step 9

`bulk_memory.needs_verifier_states = true` (per pass registry) but step 9's predecessor (ccmp at step 8) emits `log_level=1` (107 bytes, no states). bulk_memory applied=0 likely because it has no states to consume. Either its yaml `log_level` declaration is wrong, or it tolerates absent states by skipping. Worth a separate check but not the cause of the step 15 failure.

## Separate enhancement: skip failed pass in daemon

`daemon/src/commands.rs:705,798` — on FailedBpfopt or FailedRejit, the loop currently `break`s, abandoning all subsequent passes. Change to `continue` (2 lines) preserves the prior successful `(bytecode, verifier_states_path)` and lets later passes still run. Independent of the verifier-PC issue and should be done regardless.
