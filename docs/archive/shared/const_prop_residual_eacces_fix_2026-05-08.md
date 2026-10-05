# const_prop residual EACCES fix, 2026-05-08

## Artifact

Source result:

- `corpus/results/x86_kvm_corpus_20260509_022932_614897/details/apps/katran.json`
- program: `9` / `balancer_ingress`
- failing pass: `const_prop`
- summary: `sites_applied=20`, `sites_skipped=100`, `insn_delta=4`, `errno=13`
- diagnostics present in this artifact: only `const_prop_alu_materialized=20`

The artifact does not retain a per-site applied list. From the summary, all 20 applied sites are ALU materializations. `insn_delta=4` means four of those ALU sites emitted two-insn `LD_IMM64` constants and the other sixteen emitted one-insn immediate materializations. The failing verifier window identifies the unsafe applied class.

## Verifier Failure

Key verifier log lines:

```text
690: (15) if r1 == 0x11 goto pc+33 724: ... R3=fp-72 ... R7=pkt(r=82) ...
724: (57) r2 &= 1                     ; R2=1
725: (b7) r4 = 62                     ; R4=62
726: (b7) r3 = 34                     ; R3=34
727: (15) if r2 == 0x0 goto pc+2      ; R2=1
731: (bf) r3 = r7                     ; R3=pkt(r=82) R7=pkt(r=82)
732: (b7) r3 = 34                     ; R3=34
733: (bf) r4 = r3                     ; R3=34 R4=34
734: (07) r4 += 8                     ; R4=42
735: (79) r5 = *(u64 *)(r10 -144)     ; R5=pkt_end()
736: (2d) if r4 > r5 goto pc+800      ; R4=42 R5=pkt_end()
747: (69) r2 = *(u16 *)(r3 +2)
R3 invalid mem access 'scalar'
```

Failure PC/type: PC 747, `R3 invalid mem access 'scalar'`.

Unsafe fold class: ALU pointer arithmetic materialization. After `731: r3 = r7` establishes `R3` as a packet pointer, const_prop materialized the following pointer-offset computation at PC 732 as scalar `r3 = 34`. The later bounds/data access still uses `r3` as a packet pointer, so verifier rejects.

## Root Cause

True hypothesis: a variant of (b)/(c). Path C was checking scalar exactness using an oracle that mixed real instruction post-states with `PcFullState` / `EdgeFullState`. Those full states describe state at control-flow entry to a PC, not necessarily the post-state after executing that PC's instruction. In the 13-pass shape, an entry/full state can prove a numeric scalar for a register at PC N while the instruction at PC N is actually provenance-carrying pointer arithmetic.

Rejected hypotheses:

- (a) stale PC fail-open from inserted instructions: not the direct failure. Missing instruction post-state now fails closed; the bad site had enough non-instruction state to satisfy the older guard.
- (d) width looseness: not the observed failure. The bad instruction is a 64-bit immediate materialization of pointer provenance, not a 32/64 width mismatch.
- LD_IMM64 typed pointer rewrite: not the failure. The rejected instruction is `MOV64 K` at PC 732.

## Fix

Changed only `bpfopt/crates/bpfopt/src/passes/const_prop.rs`.

The original Path C guard remains in place. A second proof table now records scalar exact post-states from `VerifierInsnKind::InsnDeltaState` only. `fold_alu_instruction()` requires both:

- existing Path C: every retained verifier state for that PC/frame/dst agrees on scalar exact value
- new guard: every real instruction post-state (`InsnDeltaState`) for that PC/frame/dst agrees on the same scalar exact value

If the second proof is absent or conflicting, the site is skipped with:

```text
verifier instruction post-state is not scalar-exact
```

This catches entry/full-state-only false proofs while preserving the older fail-closed behavior for missing or conflicting Path C observations.

## Test Coverage

Added regression:

- `const_prop_rejects_edge_state_only_pointer_arithmetic_materialization`

It builds the bad shape: a packet pointer copy, an ALU offset on that pointer, then a packet load. The verifier input provides an `EdgeFullState` scalar exact value at the ALU PC but no `InsnDeltaState` scalar proof for that instruction. The pass now skips the fold and leaves bytecode unchanged.

Existing positive coverage still verifies scalar MOV materialization when `InsnDeltaState` proves scalar exactness.

Verification:

```text
cargo test -p bpfopt
```

Result:

```text
319 passed; 0 failed
9 passed; 0 failed
11 passed; 0 failed
Doc-tests bpfopt: 0 passed; 0 failed
```

## Expected Ratio After Fix

No corpus benchmark was run. Expected behavior is that Katran no longer stops at `const_prop` EACCES, allowing downstream default passes to execute. Performance should move back toward the prior successful Path C range rather than keeping the failed-run regression; exact ratio must be measured by the follow-up corpus run.
