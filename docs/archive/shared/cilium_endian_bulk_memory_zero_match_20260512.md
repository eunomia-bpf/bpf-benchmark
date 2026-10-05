# Cilium endian_fusion / bulk_memory zero-match investigation

## 1. Verify the zero-match claim

Read first: `CLAUDE.md:70-74` fail-fast/no-fallback rule and the paper-performance guidance in `CLAUDE.md:33-62`. I did not run benchmarks.

Doc baseline: `docs/evaluation.md:310-311` says cilium had:

| pass | cilium doc baseline |
|---|---:|
| `bulk_memory` | `5 / 5` |
| `endian_fusion` | `24 / 24` |

Latest kop-5 run metadata confirms the pass order `rotate, cond_select, extract, endian_fusion, bulk_memory` and start time `2026-05-12T19:01:58Z`: `corpus/results/x86_kvm_corpus_20260512_190158_334233/metadata.json:3-21`.

Current JSON extraction from `corpus/results/x86_kvm_corpus_20260512_190158_334233/details/apps/cilium__agent.json`:

| pass | `bpfopt_summary` entries | sum `sites_matched` | sum `sites_applied` |
|---|---:|---:|---:|
| `endian_fusion` | 21 | 0 | 0 |
| `bulk_memory` | 21 | 0 | 0 |

That verifies the literal zero-match claim for entries that exist. Example zero summaries are visible at `corpus/results/x86_kvm_corpus_20260512_190158_334233/details/apps/cilium__agent.json:1735-1757`.

Important correction: the doc-baseline matching programs mostly do not have `endian_fusion` / `bulk_memory` entries in the latest run because the per-program pass chain stopped earlier at `cond_select`. Example: `cil_xdp_entry` fails at `cond_select` with `diamond join BlockId(28) has external predecessor BlockId(1)` and never reaches `endian_fusion`: `corpus/results/x86_kvm_corpus_20260512_190158_334233/details/apps/cilium__agent.json:1810-1824`.

The kop-6 run has the same shape: metadata includes `prefetch` after `bulk_memory` at `corpus/results/x86_kvm_corpus_20260512_190655_194595/metadata.json:3-22`, and the same `cil_xdp_entry` `cond_select` failure appears at `corpus/results/x86_kvm_corpus_20260512_190655_194595/details/apps/cilium__agent.json:1706-1720`.

Baseline-era matching programs from `corpus/results/x86_kvm_corpus_20260508_051746_445037/details/apps/cilium__agent.json`:

| pass | program IDs / full names | sites |
|---|---|---:|
| `endian_fusion` | 106 `cil_xdp_entry`; 107 `cil_from_host`; 115,121 `cil_to_host`; 131 `cil_to_netdev`; 136 `cil_from_netdev`; 153,162 `cil_from_container` | 8 x 3 = 24 |
| `bulk_memory` | 112,125,134 `tail_handle_snat_fwd_ipv4`; 113,138 `tail_nodeport_nat_egress_ipv4` | 5 x 1 = 5 |

Full names come from `.baseline.bpf`, e.g. `cil_xdp_entry` at `corpus/results/x86_kvm_corpus_20260508_051746_445037/details/apps/cilium__agent.json:23-27`, `tail_handle_snat_fwd_ipv4` at `:68-72`, and `tail_nodeport_nat_egress_ipv4` at `:77-81`.

## 2. Host-side reproduction

KOperation target names from source:

| pass | source | koperation used |
|---|---|---|
| `endian_fusion` | `bpfopt/crates/bpfopt/src/passes/endian.rs:5-19` | `bpf_endian_load16:1,bpf_endian_load32:2,bpf_endian_load64:3` |
| `bulk_memory` | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:8-19` | `bpf_bulk_memcpy:10,bpf_bulk_memset:11` |

Standalone host-side results on canonicalized testbin files:

| input | `endian_fusion` | `bulk_memory` |
|---|---:|---:|
| `bpfopt/testbin/cilium_agent/159_cil_xdp_entry/canonicalize_output.bin` | 3 / 3 | 0 / 0 |
| `bpfopt/testbin/cilium_agent/164_cil_from_host/canonicalize_output.bin` | 3 / 3 | 0 / 0 |
| `bpfopt/testbin/cilium_agent/162_tail_nodeport_nat_egress_ipv4/canonicalize_output.bin` | 0 / 0 | 1 / 1 |

Exact five-pass host sequence (`rotate -> cond_select -> extract -> endian_fusion -> bulk_memory`) still preserves the downstream matches:

| input | `cond_select` | `endian_fusion` after prior passes | `bulk_memory` after prior passes |
|---|---:|---:|---:|
| `159_cil_xdp_entry` | 1 / 0, skip `external predecessor` | 3 / 3 | 0 / 0 |
| `164_cil_from_host` | 8 / 6, 2 skips | 3 / 3 | 0 / 0 |
| `162_tail_nodeport_nat_egress_ipv4` | 3 / 2, 1 skip | 0 / 0 | 1 / 1 |

Scanning all canonical cilium testbins on current HEAD finds these host-side matches:

| pass | full testbin programs |
|---|---|
| `endian_fusion` | `159_cil_xdp_entry`, `164_cil_from_host`, `169_cil_to_host`, `182_cil_to_host`, `192_cil_from_netdev`, `193_cil_to_netdev`, `198_cil_from_container`, `212_cil_from_container` |
| `bulk_memory` | `162_tail_nodeport_nat_egress_ipv4`, `166_tail_handle_snat_fwd_ipv4`, `175_tail_handle_snat_fwd_ipv4`, `176_tail_nodeport_nat_egress_ipv4`, `183_tail_nodeport_nat_egress_ipv4`, `185_tail_handle_snat_fwd_ipv4` |

Conclusion from host reproduction: current `endian_fusion` and `bulk_memory` detectors are not zero on the canonical cilium bytecode. The latest corpus zero entries are explained by earlier per-program aborts plus the remaining non-candidate programs that did reach those passes.

## 3. Pattern detector analysis

`endian_fusion` detector:

| precondition | code |
|---|---|
| first instruction must be `LDX_MEM` | `bpfopt/crates/bpfopt/src/passes/endian.rs:40-45` |
| immediate next instruction may be endian swap on same dst | `bpfopt/crates/bpfopt/src/passes/endian.rs:53-59` |
| widened-load/narrow-swap form only scans W/DW loads | `bpfopt/crates/bpfopt/src/passes/endian.rs:62-70` |
| scan stops at `LD_IMM64`, jump, use of dst, or def of dst | `bpfopt/crates/bpfopt/src/passes/endian.rs:74-80` |
| raw candidate enumeration uses `scan_block_starts(MAX_NARROW_SCAN + 1, ...)` | `bpfopt/crates/bpfopt/src/passes/endian.rs:238-241` |

The byte sequence in `bpfopt/testbin/cilium_agent/159_cil_xdp_entry/canonicalize_output.bin` that should trigger `endian_fusion`:

```text
0248: code=0x69 dst=r4 src=r10 off=-8 imm=0   # LDXH r4, [r10-8]
0249: code=0xdc dst=r4 src=r0  off=0  imm=16  # END BE16 r4

0259: code=0x61 dst=r1 src=r10 off=-8 imm=0   # LDXW r1, [r10-8]
0260: code=0xdc dst=r1 src=r0  off=0  imm=32  # END BE32 r1

0272: code=0x79 dst=r4 src=r10 off=-8 imm=0   # LDXDW r4, [r10-8]
0273: code=0xdc dst=r4 src=r0  off=0  imm=64  # END BE64 r4
```

These match the exact adjacent-load+endian path at `bpfopt/crates/bpfopt/src/passes/endian.rs:53-59`, which is why host-side reports 3 / 3.

`bulk_memory` detector:

| precondition | code |
|---|---|
| scans each block body linearly | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:100-145` |
| memcpy lane is `LDX_MEM` followed by same-width `STX_MEM` from the load dst | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:292-316` |
| memcpy lanes must have same width/base regs and contiguous offsets | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:170-193` |
| total chunk must be at least 32 bytes | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:195-200` |
| memset lane accepts immediate stores or STX from a lifted constant register | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:318-340` |

The byte sequence in `bpfopt/testbin/cilium_agent/162_tail_nodeport_nat_egress_ipv4/canonicalize_output.bin` that should trigger `bulk_memory`:

```text
0236: code=0xb7 dst=r8  src=r0 off=0    imm=0  # MOV64 r8, 0
0238: code=0x7b dst=r10 src=r8 off=-120 imm=0  # STXDW [r10-120], r8
0239: code=0x7b dst=r10 src=r8 off=-112 imm=0  # STXDW [r10-112], r8
0240: code=0x7b dst=r10 src=r8 off=-104 imm=0  # STXDW [r10-104], r8
0241: code=0x7b dst=r10 src=r8 off=-96  imm=0  # STXDW [r10-96], r8
0242: code=0x7b dst=r10 src=r8 off=-88  imm=0  # STXDW [r10-88], r8
```

That is a 40-byte zero-fill run. `compute_lifted_reg_facts()` records `r8` as constant 0 before the stores (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1428-1461`), and `memset_lane_at()` accepts the STX constant-fill lane at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:331-340`. Host-side reports 1 / 1.

Trace of the latest corpus miss: for baseline candidate programs such as current run ID 106 `cil_xdp_entry`, the detector does not miss the byte sequence. The detector is never invoked because `cond_select` exits 1 first: `corpus/results/x86_kvm_corpus_20260512_190158_334233/details/apps/cilium__agent.json:1810-1824`.

## 4. Git archaeology

The exact commands in the prompt with `--follow` and multiple pathspecs fail with `fatal: --follow requires exactly one pathspec`. Equivalent useful logs:

```text
git log --oneline -- bpfopt/crates/bpfopt/src/passes/endian.rs bpfopt/crates/bpfopt/src/passes/bulk_memory.rs | head -30
fb8758dc Add results and metadata for x86 KVM corpus runs
a8c5b966 Refactor mutation methods in BBProgram to use a transactional rollback pattern for improved safety and clarity
9a61ab1a Refactor code to remove MakeReplacement enum and update related functions for improved clarity and consistency
b7e1b3a8 Refactor KopDescriptor to replace canonical_name with name and remove unused proof_len functions across multiple passes
b42632e0 Refactor BPF optimization passes for improved clarity and performance
44be6efb Implement V4c fix cleanup and V5 architectural refactor documentation
08b51e1b Refactor passes to remove MakeReplacement usage and improve site skipping
01e1a7bb Refactor BPF optimization passes to improve code structure and maintainability
...
```

```text
git log --oneline -- bpfopt/crates/bpfopt/src/analysis/bbprogram*.rs | head -30
a8c5b966 Refactor mutation methods in BBProgram to use a transactional rollback pattern for improved safety and clarity
3969eb16 Add results and metadata for x86 KVM corpus runs; cleanup review notes
9a61ab1a Refactor code to remove MakeReplacement enum and update related functions for improved clarity and consistency
b42632e0 Refactor BPF optimization passes for improved clarity and performance
44be6efb Implement V4c fix cleanup and V5 architectural refactor documentation
08b51e1b Refactor passes to remove MakeReplacement usage and improve site skipping
01e1a7bb Refactor BPF optimization passes to improve code structure and maintainability
...
```

Recent suspects:

| commit | plausibility |
|---|---|
| `44be6efb` | Direct cause. It removed the local `validate_diamond_site()` wrapper and called `trial.replace_diamond_with_insns(...)` directly in `cond_select`; invalid external-predecessor joins then surfaced as hard errors from `validate_diamond()` instead of a skip. Diff shows the direct call added in `bpfopt/crates/bpfopt/src/passes/cond_select.rs`; hard error is from `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:790-802`. |
| `18ff261a` | Fix, not cause. It added `external_join_predecessor_skip()` and checks before trial/final replacement: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:126-132`, `:152-158`, `:257-273`. Existing note: `docs/tmp/cond_select_diamond_fix_20260512.md:15-23`. |
| `a8c5b966` | Plausible area because it touched `BBProgram` mutation transactions and `bulk_memory`, but not the observed zero-match root cause. Current host-side reproduction after this commit still finds cilium endian/bulk sites. |
| `9a61ab1a` | Plausible area because it changed replacement APIs and touched `bulk_memory`, `cond_select`, and `BBProgram`; current host-side reproduction rules it out as the direct zero-match cause. |
| `b7e1b3a8`, `b42632e0`, `08b51e1b`, `01e1a7bb` | Broad pass/BBProgram refactors within the last week. They could affect detector enumeration in principle, but current HEAD detects the canonical endian/bulk patterns, so they are not the cause of this latest cilium zero in the corpus artifacts. |

Timing: the failing kop-5 run started at `2026-05-12T19:01:58Z` (`corpus/results/x86_kvm_corpus_20260512_190158_334233/metadata.json:21`), i.e. before `18ff261a` at `2026-05-12 13:25:37 -0700`. The run therefore predates the fix commit.

## 5. Root cause

This is not a missing `endian_fusion` or `bulk_memory` pattern variant. It is not a BBProgram lift change that hides load/endian or memset runs from those passes. The canonical bytecode still matches both detectors on current HEAD.

The actual filtering/abort point in the failing corpus run is before those passes:

```rust
// bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:790-802
let allowed_preds = [
    pattern.predecessor,
    pattern.true_branch,
    pattern.false_branch,
];
for pred in prog.predecessors(join) {
    if !allowed_preds.contains(pred) {
        anyhow::bail!(
            "diamond join {:?} has external predecessor {:?}",
            join,
            pred
        );
    }
}
```

Before `18ff261a`, `cond_select` let `replace_diamond_with_insns()` reach that hard error for cilium diamonds with shared joins. Because the daemon's per-program pass chain is fail-fast, downstream passes were not run for the baseline candidate programs. The zero summaries are only from programs that survived `cond_select` and had no endian/bulk candidates.

Current HEAD already contains the correct source-level fix:

```rust
// bpfopt/crates/bpfopt/src/passes/cond_select.rs:126-132
let mut trial = prog.clone();
let pattern = diamond_pattern_for_site(&mut trial, &site)?;
if let Some(reason) = external_join_predecessor_skip(&trial, pattern) {
    skipped.push(site.skip(reason));
    continue;
}
trial.replace_diamond_with_insns(pattern, vec![BpfInsn::nop()])?;
```

and the final-application guard at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:152-158`. The helper mirrors the same allowed-predecessor rule at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:257-273`.

Classification: (d) something else. A prior pass (`cond_select`) treated an unsupported diamond shape as a hard bpfopt failure, aborting per-program orchestration before `endian_fusion` / `bulk_memory`.

## 6. Proposed fix

Minimal diff against the failing revision: keep the fail-fast hard error inside `BBProgram::replace_diamond_with_insns()` for invalid mutations, but make `cond_select` pre-classify known unsupported external-predecessor diamonds as per-site skips before invoking that mutator.

Text diff:

1. Add `external_join_predecessor_skip(prog, pattern) -> Option<String>` to `cond_select.rs`, using the same allowed predecessor set as `validate_diamond()`.
2. In the trial validation path, after `diamond_pattern_for_site()` and before `trial.replace_diamond_with_insns(...)`, push `site.skip(reason)` and `continue` when the helper returns a reason.
3. Repeat the same guard before the final `prog.replace_diamond_with_insns(...)`, and count only actually applied sites.

This is a correct fix, not a fallback path: it preserves `BBProgram`'s structural invariant as a hard error for callers that try invalid mutations, while teaching the `cond_select` detector that this specific candidate shape is unsupported and should be reported as a skipped site. It does not add a secondary endian/bulk detector, does not mask subprocess failures generally, and does not reinterpret missing kop support as success.

Verdict: Root cause: `cond_select` aborted cilium candidate programs on external-predecessor diamonds before `endian_fusion` / `bulk_memory` could run. Fix: keep the `BBProgram` invariant hard error and pre-skip those unsupported diamonds inside `cond_select` as implemented by `18ff261a`.
