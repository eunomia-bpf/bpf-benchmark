# const_prop after map_inline hard-fold EACCES, 2026-05-08

## 1. Verdict

Root cause: `const_prop` materialized a provenance-carrying packet-pointer copy as a scalar immediate (`r7 = r1` became `r7 = 62`), so the next packet load used scalar `R7`; `map_inline` hard fold is the exposure point in the default pipeline, but its hard-fold bytecode is not the malformed instruction.

## 2. Evidence

Primary failure artifact:

- `corpus/results/x86_kvm_corpus_20260509_011252_944576/details/apps/katran.json`
- program id/name: `9` / `balancer_ingres`
- failing pass: `const_prop`
- pass stats: `sites_matched=116`, `sites_applied=116`, `insn_delta=64`, `BPF_PROG_REJIT errno 13`
- prior `map_inline`: `status=ok`, `sites_applied=2`, `insn_delta=0`, diagnostics report only `ctl_array` sites `PC=1098` and `PC=1801`

The complete `const_prop` verifier log is in the pass `error` field. I extracted it to `/tmp/katran_011252_const_prop_error.log` for local grep; it is 267 lines / 26084 bytes.

Key verifier log window from the rejected `const_prop` output:

```text
900: (b7) r1 = 62                     ; R1=62
901: (b7) r0 = 34                     ; R0=34
902: (15) if r2 == 0x0 goto pc+2      ; R2=1
903: (bf) r1 = r1                     ; R1=62
904: (05) goto pc+1
906: (0f) r7 += r1                    ; R1=62 R7=pkt(off=62,r=82)
907: (bf) r1 = r7                     ; R1=pkt(off=62,r=82) R7=pkt(off=62,r=82)
908: (07) r1 += 9                     ; R1=pkt(off=71,r=82)
...
946: (bf) r2 = r7                     ; R2=pkt(off=62,r=82) R7=pkt(off=62,r=82)
947: (07) r2 += 17                    ; R2=pkt(off=79,r=82)
948: (b7) r7 = 62                     ; R7=62
949: (79) r1 = *(u64 *)(r10 -144)     ; R1=pkt_end()
950: (2d) if r2 > r1 goto pc+765      ; R2=pkt(off=79,r=82)
951: (71) r2 = *(u8 *)(r7 +0)
R7 invalid mem access 'scalar'
```

The retained pre-`const_prop` disassembly for the same Katran option-parser shape is in `docs/tmp/katran_xlated_post_5pass.disasm`. That file is not the exact `20260509_011252` workdir byte-for-byte because the failing run did not retain a workdir, but it shows the unchanged input pattern in this block: bounds-check through `r2`, preserve the packet pointer by copying `r1` into `r7`, then load from `r7`.

```text
0943: (bf) r2 = r7
0944: (07) r2 += 0x11
0945: (bf) r7 = r1
0946: (79) r1 = *(u64 *)(r10 -144)
0947: (2d) if r2 > r1 goto 1710 (64)
0948: (71) r2 = *(u8 *)(r7 +0)
```

The rejected output changes the provenance-preserving `MOV X` into `MOV K`. The numeric value is plausible on one path (`62`), but the verifier type must remain packet pointer on the path that reaches the dereference.

I also ran the one allowed reproduction command:

```bash
KEEP_WORKDIRS=1 BPFREJIT_BENCH_PASSES="noop,map_inline,const_prop" BPFREJIT_CORPUS_APPS="katran" SAMPLES=1 make corpus
```

Result: `corpus/results/x86_kvm_corpus_20260509_013938_112049`, status `ok`. Its pass list had `map_inline sites_applied=6` and `const_prop sites_applied=126`; no failure tar was emitted. This narrows the trigger: the EACCES depends on the default pre-pass shape (`wide_mem/cond_select/extract/endian_fusion` before `map_inline`), not merely on `noop -> map_inline -> const_prop`.

## 3. Hypotheses tested

**(a) map_inline hard fold emits `BPF_LD_IMM64` const pointer and verifier cannot type it: false.**

`map_inline.rs` hard hints enter through `extract_site_constant_key()` and `build_site_rewrite()`. The hard path reads the live map value, replaces fixed-offset value loads with scalar constants, and removes the lookup/null-check pattern when safe. It does not materialize a fake map-value pointer. In this failure the bad instruction is `const_prop` output `948: r7 = 62`, not a `map_inline` pseudo pointer.

**(b) const_prop folds `*(r0 + offset)` into an immediate and loses pointer deref: false for this failure.**

`const_prop.rs` does not rewrite `BPF_LDX`; `analyze_instruction()` marks `BPF_LDX` destination unknown. The invalid access is caused earlier: a pointer-copy `MOV X` was rewritten into scalar `MOV K`, so the later `LDX` still exists but its base register has scalar type.

**(c) map_inline verifier-state log has stale const-ptr type: false / no supporting evidence.**

The failure window is before the two hard-folded `ctl_array` sites (`1098`, `1801`) and `map_inline` reports `insn_delta=0`. The kernel verifier itself shows the correct path state immediately before the bad replacement: `R1=pkt(off=71,r=82)` and old `R7=pkt(off=62,r=82)`. The type information is not a stale const pointer; `const_prop` discarded provenance by emitting a scalar.

**(d) const_prop has a provenance-incompatible local-constant bug: true.**

Current `const_prop` intentionally avoids oracle materialization for `MOV X`, but local evaluation can still fold `MOV X` when its abstract state says the source register has an exact scalar. That abstract state is not verifier-type-aware. In this control-flow shape, the numeric constant `62` reaches the `r7 = r1` candidate, while the verifier state at that program point requires `r1`/`r7` to be packet pointers. The pass needs a verifier-backed scalar-provenance guard before emitting scalar replacements.

## 4. Fix dimensions

**Path A: disable `MOV X` materialization.**

- File/function: `bpfopt/crates/bpfopt/src/passes/const_prop.rs`, `fold_alu_instruction()` / `evaluate_alu_result()`.
- Size: about 5-15 LOC.
- #244 impact: keeps map-name hard hint interface and kernel-write filter untouched.
- Test impact: add a regression that a reg-to-reg move from an exact local scalar is tracked internally but not emitted as `MOV K`.
- Pros: smallest safe hotfix; directly blocks `r7 = r1 -> r7 = 62`.
- Cons: gives up legitimate scalar copy folding globally.

**Path B: reject replacements whose destination reaches pointer-sensitive use.**

- File/function: `const_prop.rs`, around replacement insertion in `simulate_block()` / `fold_alu_instruction()`.
- Size: about 80-160 LOC if limited to same-basic-block memory-base uses; more if helper arg table is included.
- #244 impact: untouched.
- Test impact: add one memory-base regression and one helper-arg regression.
- Pros: preserves more scalar MOV/ALU folds than Path A.
- Cons: use scanning is easy to under-approximate; previous helper-arg-only designs would not catch this packet-load failure unless memory bases are covered too.

**Path C: require verifier-observed scalar post-state before emitting any scalar replacement.**

- File/function: `const_prop.rs`, extend `VerifierExactConstOracle` with a guard like `post_state_proves_scalar_exact(pc, frame, dst, value, width)` and call it from `fold_alu_instruction()` for both local-eval and oracle-derived replacements.
- Size: about 100-180 LOC.
- #244 impact: untouched.
- Test impact: add a regression where local eval wants to fold `MOV X`, but verifier states for the destination at that PC are `pkt`; add a scalar-positive test to preserve useful ALU folding.
- Pros: directly matches the verifier-in-the-loop contract. If original bytecode's post-state is pointer, map value, ctx, fp, or omitted/conflicting, `const_prop` fails closed instead of emitting a scalar.
- Cons: may reduce `sites_applied` when verifier logs omit a register; should report a skip diagnostic rather than silently dropping sites.

## 5. 推荐路径

Use Path C as the real fix, with Path A as an emergency one-line mitigation if a quick measurement unblock is needed.

The bug is not specific to `ctl_array`, map lookup, or helper ABI. It is the general rule "numeric equality is not verifier provenance." A verifier-observed scalar guard catches this failure and the older helper-pointer failure class without adding map_inline-specific special cases. It also leaves #244's hint syntax (`ctl_array:!00000000`) and kernel-write map filter unchanged.

Implementation detail: continue allowing `const_prop` to compute local constants for state propagation, but only emit a bytecode replacement when every retained verifier visit for that instruction/destination agrees that the original post-state is scalar exact with the same value. Missing, non-scalar, or multi-frame disagreement should become a `sites_skipped` reason such as `verifier post-state is not scalar-exact`.

## 6. 预期 ratio after fix

The fix should remove the pathological `1.2323` regression by letting `const_prop` and downstream passes complete. It should not by itself create a new map_inline speedup; it mainly prevents one unsafe scalar materialization and preserves the rest of the pipeline.

Expected Katran ratio after fix: roughly back near the Phase 1 result (`0.9715`), plausibly `0.97-1.00` in the same VM/noise window. If Path C only skips the bad pointer-copy and a few analogous provenance-sensitive sites, `const_prop` should still apply on the order of the current `116` sites, with downstream `dce/bounds_check_merge/skb_load_bytes_spec/bulk_memory/prefetch` no longer skipped.
