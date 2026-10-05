# 1. What the rewrite actually does

`cond_select` has two matcher shapes in `bpfopt/crates/bpfopt/src/passes/cond_select.rs`.

- Pattern A is the classic four-instruction diamond described in the pass comment: `Jcc`, false `MOV`, `JA`, true `MOV` (`cond_select.rs:21-32`). `try_match_pattern_a()` requires the taken and fallthrough blocks to be distinct (`cond_select.rs:307-309`), each branch body to contain exactly one `MOV` (`cond_select.rs:310-319`), both `MOV`s to write the same destination register (`cond_select.rs:321-323`), and both branch blocks to have the same single successor join (`cond_select.rs:324-332`). The site starts at the conditional branch terminator and has `old_len = 4` (`cond_select.rs:338-346`).
- Pattern C is the shorter shape where the "true" assignment is already in the predecessor body immediately before the conditional branch, while the false arm is a one-instruction fallthrough block (`cond_select.rs:349-390`). It requires `mov_true.dst == mov_false.dst` (`cond_select.rs:365-367`), requires the false block's single successor to be the branch taken block (`cond_select.rs:368-370`), and rejects cases where the pre-branch `MOV` overwrites a register read by the condition (`cond_select.rs:371-376`). The site starts at the pre-branch `MOV` and has `old_len = 3` (`cond_select.rs:382-390`).

Lowering is built before structural replacement. `run_on_bbprogram()` computes `live_after = prog.live_out_site_checked(site.end_site)` (`cond_select.rs:110-113`), then `build_lowering()` creates a prefix plus three register operands for the packed `bpf_select64` kop (`cond_select.rs:416-453`). `condition_prefix()` turns the original branch predicate into a boolean condition register (`cond_select.rs:456-534`). `materialize_value()` places immediate and 32-bit source operands into registers that are not live after the site, except that the destination register itself is allowed because it is the selected output (`cond_select.rs:545-571`, `cond_select.rs:573-586`). The emitted replacement is:

```text
prefix to materialize cond/a/b registers
kop sidecar payload: dst_reg, a_reg, b_reg, cond_reg
call kop bpf_select64
```

The current comment at `cond_select.rs:24-29` is stale for the packed kop ABI: the implementation does not move operands into `r1/r2/r3`; it encodes register operands in the sidecar payload (`cond_select.rs:144-151`, `insn.rs:680-690`).

`pattern_a_for_site()` and `pattern_c_for_site()` then turn the matched instruction site into a `DiamondPattern` (`cond_select.rs:164-255`):

- Pattern A may split a block before the branch if the branch terminator has preceding body instructions (`cond_select.rs:179-191`). It records `predecessor = branch block`, `true_branch = taken`, `false_branch = fallthrough`, and `join = common successor` (`cond_select.rs:192-219`).
- Pattern C may split at the pre-branch true `MOV` if that instruction is not already the first site in the block (`cond_select.rs:226-236`). It records `predecessor = tail block`, `true_branch = predecessor`, `false_branch = fallthrough`, and `join = taken` (`cond_select.rs:237-254`).

The block-level rewrite is not "leave the join untouched." `BBProgram::replace_diamond_with_insns()` calls `replace_diamond_with_insns_in_place()` (`bbprogram_api.rs:456-475`). For `join: Some(join)`, it:

1. Validates the diamond (`bbprogram_api.rs:475`, `bbprogram_api.rs:754-815`).
2. Adds true/false branch blocks to the removal set unless the branch is the predecessor (`bbprogram_api.rs:482-487`).
3. Adds the join block to the removal set unless the join is the predecessor (`bbprogram_api.rs:488-492`).
4. Clones the join block body and terminator (`bbprogram_api.rs:494-498`).
5. Remaps metadata for join-body sites into the predecessor after the replacement prefix (`bbprogram_api.rs:499-516`).
6. Replaces the predecessor body with `replacement + join_body` and replaces the predecessor terminator with the join terminator (`bbprogram_api.rs:517-521`).
7. Removes the branch blocks and the join block, then remaps all remaining block IDs and terminators (`bbprogram_api.rs:546-592`).

So the current generic rewrite collapses `predecessor -> true/false -> join` into one predecessor block containing the new select code plus the old join body, with the old join terminator. The join block is deleted.

The dataflow assumption is therefore stronger than "the branch-local selected destination is equivalent." It assumes:

- The true and false branch blocks are owned by the diamond and can be deleted. `validate_diamond()` enforces this by requiring each non-predecessor/non-join branch block to have exactly `[predecessor]` as its predecessor list (`bbprogram_api.rs:777-789`).
- The join block is owned by the diamond and can be moved into the predecessor and deleted. `validate_diamond()` currently enforces this by rejecting every join predecessor outside `{predecessor, true_branch, false_branch}` (`bbprogram_api.rs:790-803`).
- Along the collapsed diamond paths, the only live-in register intentionally changed at join entry is `dst_reg`, and it must receive exactly the value selected by the old true/false `MOV`s. Other join live-in registers must be preserved by choosing dead temps from `live_after` (`cond_select.rs:110-119`, `cond_select.rs:573-586`). Stack live-ins are assumed unchanged because the detected branch bodies are single `MOV` instructions (`cond_select.rs:310-319`, `cond_select.rs:357-364`) and the replacement prefix/call does not emit stack loads or stores.

# 2. Why the external-predecessor check exists at all

The original structural assertion is in `validate_diamond()`:

```rust
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

This is `bbprogram_api.rs:790-803`. `git blame` attributes the function to commit `57cac8a0` ("Add Phase 3 TDD test migration and test-loss review documentation", 2026-05-10). The current pass-local skip mirrors that exact predicate in `external_join_predecessor_skip()` (`cond_select.rs:257-273`) and calls it before the trial replacement (`cond_select.rs:126-132`) and again before the final replacement (`cond_select.rs:152-157`). `git blame` attributes those skip calls and helper to `18ff261a0` ("Fix BR daemon target.json preparation and cond_select diamond handling", 2026-05-12).

The test that motivated the guard is `cond_select_skips_diamond_join_with_external_predecessor` (`cond_select_tests.rs:148-164`). It builds:

```text
pc0: if r9 == 0 goto pc5        ; external edge to join/exit
pc1: if r1 != 0 goto pc4        ; cond_select diamond
pc2: r0 = 0
pc3: ja pc5
pc4: r0 = 1
pc5: exit
```

The test asserts `sites_applied == 0`, an `"external predecessor"` skip reason, and byte-for-byte unchanged output (`cond_select_tests.rs:159-163`). This test verifies the workaround, not the desired transformation contract.

The precise property being enforced is structural ownership of the join block. Because `replace_diamond_with_insns_in_place()` moves the join body/terminator into the predecessor and deletes the join (`bbprogram_api.rs:488-521`), no block outside the diamond may still target that join. If one does, `remove_blocks_in_place()` cannot remap that external terminator to a live block ID (`bbprogram_api.rs:571-592`, `bbprogram_api.rs:747-752`).

This is also a dataflow property by consequence: an external predecessor may enter the join with register and stack state produced on a path that did not execute the diamond. Deleting/hoisting the join behind the diamond predecessor only preserves that external path if the algorithm either keeps the join in place or duplicates the join for the diamond path. The current algorithm does neither.

# 3. Is the property actually load-bearing for correctness?

For the current `replace_diamond_with_insns()` algorithm: yes, it is load-bearing.

The prompt premise says the rewrite leaves the join untouched, but the code does not. The code deletes the join block (`bbprogram_api.rs:488-492`) after copying its body and terminator into the predecessor (`bbprogram_api.rs:494-521`). If the external-predecessor check is removed from `cond_select.rs` but left in `validate_diamond()`, the pass hard-fails at `validate_diamond()`. If the check is also removed from `validate_diamond()` without changing the rewrite algorithm, `remove_blocks_in_place()` later tries to remap external predecessors that still target the removed join and fails because the join has `old_to_new[join] = None` (`bbprogram_api.rs:562-579`, `bbprogram_api.rs:706-712`, `bbprogram_api.rs:747-752`).

For the intended cond_select semantics: the property is not fundamentally necessary. A correct cond_select rewrite can preserve the join block when it has external predecessors:

```text
before:
  P -> T/F -> J
  E -------> J

after:
  P' ------> J
  E -------> J
```

In that algorithm, `E -> J` is untouched, so no output register or stack slot at `J` changes along the external path. The current bug is that the generic helper combines "replace the diamond-local branch computation" with "hoist and delete the join."

Concrete cilium site: `bpfopt/testbin/cilium_agent/164_cil_from_host/canonicalize_output.bin`.

Read-only command used:

```sh
cargo run -q --manifest-path bpfopt/Cargo.toml -p bpfopt -- \
  --pass cond_select \
  --input bpfopt/testbin/cilium_agent/164_cil_from_host/canonicalize_output.bin \
  --output /tmp/cond_select_164.bin \
  --report /tmp/cond_select_164.json \
  --koperation bpf_select64:5555
```

Report:

```json
{
  "sites_applied": 6,
  "sites_matched": 8,
  "sites_skipped": 2,
  "skip_reasons": {
    "diamond join BlockId(32) has external predecessor BlockId(3)": 1,
    "diamond join BlockId(60) has external predecessor BlockId(56)": 1
  },
  "skipped_sites": [
    {
      "pc": 39,
      "reason": "diamond join BlockId(32) has external predecessor BlockId(3)"
    },
    {
      "pc": 335,
      "reason": "diamond join BlockId(60) has external predecessor BlockId(56)"
    }
  ]
}
```

Chosen site: original PC 39. The lifted CFG around the site is:

```text
BlockId(3) pc 26..31 preds=[1] term: if r4 > r2 goto BlockId(32) else BlockId(4)
  pc 26: mov64 r4, r1
  pc 27: add64 r4, r3
  pc 28: mov32 r0, -1
  pc 29: mov64 r9, 0
  pc 30: jgt r4, r2, +143       ; external edge to BlockId(32)

BlockId(6) pc 39..41 preds=[5] term: if r1 == 56710 goto BlockId(32) else BlockId(7)
  pc 39: mov32 r0, -100         ; true value
  pc 40: jeq32 r1, 56710, +133

BlockId(7) pc 41..43 preds=[6] term: jump BlockId(32)
  pc 41: mov32 r0, -3           ; false value
  pc 42: ja +131

BlockId(32) pc 174..175 preds=[3, 4, 6, 7, 8, 30, 31]
  pc 174: jsgt32 r0, -1, +11
```

Register liveness from a BBProgram-equivalent host script:

```text
BlockId(6) live_out=[0,3,4,5,6,9,10]
BlockId(7) live_out=[0,3,4,5,6,9,10]
BlockId(32) live_in=[0,3,4,5,6,9,10]
```

Along the external `BlockId(3) -> BlockId(32)` path before any rewrite, `r0 = -1` at join entry. A preserve-join rewrite does not modify BlockId(3), its terminator, or BlockId(32), so the external path still enters BlockId(32) with `r0 = -1` and identical `r3/r4/r5/r6/r9/r10` and stack state.

Along the diamond paths, the old semantics at BlockId(32) are:

- `BlockId(6) taken`: `r1 == 56710`, so `r0 = -100`.
- `BlockId(6) fallthrough -> BlockId(7)`: `r1 != 56710`, so `r0 = -3`.

The lowering selected by the current algorithm for this site is:

```text
mov64 r0, 0                         ; predicate = false
jne32 r1, 56710, +1                 ; if original condition false, skip predicate=true
mov64 r0, 1                         ; predicate = true
mov32 r1, -100                      ; a
mov32 r2, -3                        ; b
kop_sidecar payload 0x210         ; dst=r0, a=r1, b=r2, cond=r0
call_kop bpf_select64:5555
```

`r1` and `r2` are legal temps here because they are not in `BlockId(32)`'s live-in set. The replacement only changes `r0`, exactly the selected destination. It does not touch `r3/r4/r5/r6/r9/r10` or stack.

The current generic helper would try this invalid structural transformation:

```diff
 BlockId(6):
-  pc 39: mov32 r0, -100
-  pc 40: jeq32 r1, 56710, -> BlockId(32)
-BlockId(7):
-  pc 41: mov32 r0, -3
-  pc 42: ja -> BlockId(32)
-BlockId(32):
-  pc174: jsgt32 r0, -1, -> BlockId(35) else BlockId(33)
+  mov64 r0, 0
+  jne32 r1, 56710, +1
+  mov64 r0, 1
+  mov32 r1, -100
+  mov32 r2, -3
+  kop_sidecar payload 0x210
+  call_kop bpf_select64:5555
+  jsgt32 r0, -1, -> BlockId(35) else BlockId(33)
```

and remove both BlockId(7) and BlockId(32). That is not a valid post-CFG because BlockId(3), BlockId(4), BlockId(8), BlockId(30), and BlockId(31) still have semantic edges to the removed join.

The correct post-CFG for an external-join site is instead:

```diff
 BlockId(6):
-  pc 39: mov32 r0, -100
-  pc 40: jeq32 r1, 56710, -> BlockId(32)
-BlockId(7):
-  pc 41: mov32 r0, -3
-  pc 42: ja -> BlockId(32)
+  mov64 r0, 0
+  jne32 r1, 56710, +1
+  mov64 r0, 1
+  mov32 r1, -100
+  mov32 r2, -3
+  kop_sidecar payload 0x210
+  call_kop bpf_select64:5555
+  ja/fallthrough -> BlockId(32)
 BlockId(32):
   pc174: jsgt32 r0, -1, -> BlockId(35) else BlockId(33)
```

That preserves every live-in value at BlockId(32) on the external path and preserves the selected `r0` value on the diamond path.

# 4. What `validate_diamond` should look like after fixing the algorithm

The minimal necessary checks depend on the replacement mode.

For the existing join-hoist/delete mode, the external-join check is necessary. Removing it without changing `replace_diamond_with_insns_in_place()` is incorrect.

For a corrected cond_select-capable mode that preserves joins with external predecessors, the necessary checks are:

- The predecessor is a conditional branch (`bbprogram_api.rs:755-763`).
- The pattern is one of the supported shapes: Pattern A has `taken == true_branch`, `fallthrough == false_branch`, and both branches reach the join; Pattern C has `true_branch == predecessor`, `taken == join`, `fallthrough == false_branch`, and the false branch reaches the join (`bbprogram_api.rs:765-776`).
- Every branch block that will be removed has exactly one predecessor, the diamond predecessor (`bbprogram_api.rs:777-789`). This remains load-bearing because true/false branch blocks are deleted.
- The join must be a valid block and must be reached by the diamond branches, but it does not need to be exclusively owned if the algorithm keeps it in place.
- If the algorithm keeps the join, the predecessor must be retargeted to the existing join after emitting the select replacement. If the algorithm deletes the join, the current exclusive-join predecessor check must stay.

Text-only diff sketch for the actual fix:

```diff
diff --git a/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs b/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs
@@
     fn replace_diamond_with_insns_in_place(
         &mut self,
         pattern: DiamondPattern,
         replacement: Vec<BpfInsn>,
     ) -> anyhow::Result<()> {
@@
-        let mut remove = BTreeSet::new();
+        let preserve_join = pattern.join.is_some_and(|join| {
+            let allowed_preds = [
+                pattern.predecessor,
+                pattern.true_branch,
+                pattern.false_branch,
+            ];
+            self.predecessors(join)
+                .iter()
+                .any(|pred| !allowed_preds.contains(pred))
+        });
+        let mut remove = BTreeSet::new();
         for block in [pattern.true_branch, pattern.false_branch] {
             if block != pattern.predecessor {
                 remove.insert(block);
             }
         }
         if let Some(join) = pattern.join {
-            if join != pattern.predecessor {
+            if join != pattern.predecessor && !preserve_join {
                 remove.insert(join);
             }
         }
@@
-        if let Some(join) = pattern.join {
+        if let Some(join) = pattern.join {
+            if preserve_join {
+                let remap_site = |site: InsnSite| -> Option<InsnSite> {
+                    (!remove.contains(&site.block)).then_some(site)
+                };
+                self.remap_metadata_sites(remap_site);
+                let predecessor = self.block_mut(pattern.predecessor)?;
+                predecessor.insns = replacement;
+                predecessor.terminator = Terminator::Jump {
+                    insn: BpfInsn::ja(0),
+                    target: join,
+                };
+            } else {
             let join_body = self.block(join)?.insns.clone();
             let join_body_len = join_body.len();
             let join_terminator = self.block(join)?.terminator;
@@
             predecessor.insns.extend_from_slice(&replacement);
             predecessor.insns.extend_from_slice(&join_body);
             predecessor.terminator = join_terminator;
+            }
         } else {
@@
 fn validate_diamond(prog: &BBProgram, pattern: DiamondPattern) -> anyhow::Result<()> {
@@
-        let allowed_preds = [
-            pattern.predecessor,
-            pattern.true_branch,
-            pattern.false_branch,
-        ];
-        for pred in prog.predecessors(join) {
-            if !allowed_preds.contains(pred) {
-                anyhow::bail!(
-                    "diamond join {:?} has external predecessor {:?}",
-                    join,
-                    pred
-                );
-            }
-        }
     } else {
```

This sketch intentionally keeps the branch-predecessor check. It also preserves the existing join-hoist behavior when the join is exclusively owned. A production patch should add a helper rather than inline `preserve_join` twice, and it should add regression tests for both Pattern A and Pattern C external joins.

Text-only diff sketch for removing the cond_select pre-filter:

```diff
diff --git a/bpfopt/crates/bpfopt/src/passes/cond_select.rs b/bpfopt/crates/bpfopt/src/passes/cond_select.rs
@@
         let mut trial = prog.clone();
         let pattern = diamond_pattern_for_site(&mut trial, &site)?;
-        if let Some(reason) = external_join_predecessor_skip(&trial, pattern) {
-            skipped.push(site.skip(reason));
-            continue;
-        }
         trial.replace_diamond_with_insns(pattern, vec![BpfInsn::nop()])?;
@@
         let pattern = diamond_pattern_for_site(prog, site)?;
-        if let Some(reason) = external_join_predecessor_skip(prog, pattern) {
-            skipped.push(site.skip(reason));
-            continue;
-        }
         prog.replace_diamond_with_insns(pattern, replacement)?;
         applied += 1;
@@
-fn external_join_predecessor_skip(prog: &BBProgram, pattern: DiamondPattern) -> Option<String> {
-    let join = pattern.join?;
-    let allowed_preds = [
-        pattern.predecessor,
-        pattern.true_branch,
-        pattern.false_branch,
-    ];
-    let pred = prog
-        .predecessors(join)
-        .iter()
-        .copied()
-        .find(|pred| !allowed_preds.contains(pred))?;
-    Some(format!(
-        "diamond join {:?} has external predecessor {:?}",
-        join, pred
-    ))
-}
```

Regression test direction:

- Delete `cond_select_skips_diamond_join_with_external_predecessor` (`cond_select_tests.rs:148-164`) or convert it to `cond_select_rewrites_diamond_join_with_external_predecessor`.
- The converted test should assert `sites_applied == 1`, assert a `bpf_select64` call is present, and assert the external edge still reaches the original join/exit without executing the replacement. The current assertion that the output is unchanged is the bug, not the contract.

# 5. Where else this guard pattern leaks

Search result: `replace_diamond_with_insns()` is only used by `cond_select` (`cond_select.rs:132`, `cond_select.rs:157`). There is no other pass-level mirror of `validate_diamond()`'s external-join check.

Other structural skip patterns found:

- `ccmp` has `validate_chain_edges()` (`ccmp.rs:227-274`) and calls it in the safe-site staging path (`ccmp.rs:118-121`) and again before applying (`ccmp.rs:159-162`). This is not currently converted into a skip reason; it hard-fails on unexpected chain shape. The predecessor check at `ccmp.rs:265-271` is load-bearing because `apply_ccmp_site()` merges the chain blocks (`ccmp.rs:162-201`). It should still be audited under the same proof standard, but it is not the same "skip if validate would reject" pattern.
- `branch_flip` skips `"interior branch target from external source"` (`branch_flip.rs:114-116`) before swapping block ranges. This is a real structural hazard: the pass permutes then/else block ranges (`branch_flip.rs:222-299`), so an external branch into the body could land in a different control context after the swap. It is profile-guided and outside the default policy, but it warrants proof documentation.
- `extract` and `endian_fusion` use `check_cross_block_pair_pattern()` to report `"interior branch target"` when a two-instruction pair straddles a block boundary (`extract.rs:48-59`, `endian.rs:215-235`, `pass.rs:667-709`). This protects in-block pair replacement from deleting a valid branch entry point. The root cause is explicit and local.
- `wide_mem` has a broader `"interior branch target"` skip for a multi-instruction load ladder (`wide_mem.rs:202-208`, `wide_mem.rs:271-299`). This is the same class as extract/endian: replacing a range is unsafe if control can enter inside the range.
- `bulk_memory` has a conservative alias skip for different-base memcpy sites when stack/non-stack classification cannot prove non-aliasing (`bulk_memory.rs:111-120`, `bulk_memory.rs:148-163`). This is a semantic proof-failure skip, not a validation-mirror skip, and it deserves a separate audit if the policy is "no prophylactic skip without proof."
- `rotate` skips when its temporary register is live after the matched window (`rotate.rs:45-59`). This is load-bearing because the replacement does not preserve `tmp_reg`.

# 6. Concrete cilium-site evidence

Static read-only scan over `bpfopt/testbin/cilium_agent/*/canonicalize_output.bin` used the host-side `bpfopt` CLI with `--pass cond_select`, `--output /tmp/...`, `--report /tmp/...`, and `--koperation bpf_select64:5555`. No benchmark target was run.

Aggregate from the static scan:

```text
programs scanned: 53
cond_select applied/matched/skipped: 172 / 244 / 72
external-predecessor skips: 62
```

Examples with multiple guard-skipped diamonds:

```text
164_cil_from_host:                    6 / 8, skips at pc 39 and pc 335
166_tail_handle_snat_fwd_ipv4:        8 / 11, three external-join skips
170_tail_nodeport_nat_ingress_ipv4:  12 / 15, three external-join skips
202_cil_lxc_policy:                  7 / 11, three external-join skips plus one temp-reg skip
220_tail_ipv4_to_endpoint:           5 / 9, three external-join skips plus one temp-reg skip
```

The doc baseline records cilium `cond_select` at `208 / 218` and tetragon at `1 331 / 1 753` (`docs/evaluation.md:305-309`). The static cilium testbin scan is not the same as the full kop-5 corpus pipeline, but it demonstrates that the current pass-level guard has corpus-scale impact: most cilium cond_select skips in these snapshots are the mirrored external-join predicate, not real lowering failures.

For the PC 39 site in `164_cil_from_host`, the live-in verification is:

- External path `BlockId(3) -> BlockId(32)`: before rewrite, `r0 = -1`; after a preserve-join rewrite, BlockId(3) and BlockId(32) are unchanged, so `r0 = -1` and all other live-ins are identical.
- Diamond true path `BlockId(6) -> BlockId(32)`: before rewrite, `r0 = -100`; after replacement, `bpf_select64(-100, -3, true)` writes `r0 = -100`.
- Diamond false path `BlockId(6) -> BlockId(7) -> BlockId(32)`: before rewrite, `r0 = -3`; after replacement, `bpf_select64(-100, -3, false)` writes `r0 = -3`.
- Join live-in set is `[r0,r3,r4,r5,r6,r9,r10]`; the replacement temps are `r1` and `r2`, and the predicate reuses `r0` before the kop overwrites `r0` with the selected result. No stack slot is read or written by the old true/false blocks or the replacement.

Therefore the external predecessor is not a semantic blocker for cond_select if the join is preserved. It is only a blocker for the current generic helper because the helper deletes the join.

Verdict: Guard needed for the current join-deleting rewrite; remove the pass-level guard only after fixing `replace_diamond_with_insns()` to preserve externally-predecessored joins.
