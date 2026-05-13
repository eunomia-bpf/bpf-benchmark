# Cond Select No-Remove Algorithm Investigation

Read-only investigation except for this findings file. No benchmark target was run.

## 1. Is "never remove blocks" semantically equivalent to current behavior?

No, not as a complete verifier-accepted BPF program.

The current helper is already split into two behaviors. `replace_diamond_with_insns_in_place()` validates the pattern and normalizes the replacement at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:465-481`, computes `branch_shared`, `join_shared`, and `preserve_join` at `bbprogram_api.rs:483-508`, removes only unshared branch blocks at `bbprogram_api.rs:510-515`, and removes the join only when `preserve_join == false` at `bbprogram_api.rs:516-520`.

The existing `preserve_join` path already performs the important semantic rewrite: it replaces the predecessor body with the select sequence and changes the predecessor terminator to `Jump { target: join }` at `bbprogram_api.rs:522-533`. The old join stays in place. The default path is the risky one: it clones the join body/terminator into the predecessor and deletes the join at `bbprogram_api.rs:535-587`.

For dynamic values on paths that still reach the join, a preserve-join rewrite is semantically right:

- predecessor path: old `P -> T/F -> J` becomes `P' -> J`, with `P'` computing the same selected destination register;
- external predecessors to `J` are untouched;
- external predecessors to `T` or `F`, if any, still execute `T/F -> J` if those branch blocks are preserved.

The blocker is the "T/F have no external predecessors" case. If the predecessor jumps directly to `J` and private `T/F` are left in the linear bytecode, those branch blocks become unreachable from program entry. That is not just dead code; the kernel verifier rejects unreachable instructions before the program can be installed. The current `preserve_join` path avoids this by still removing private `T/F` blocks.

The no-join branch has the same problem. Today, `join == None` requires both branches to share a terminator and then installs that terminator on the predecessor at `bbprogram_api.rs:563-576`. Leaving `T/F` behind would again create unreachable instructions. There is also no canonical `target_join` to jump to if the shared terminator is `Exit`.

Conclusion: "always preserve the join" is safe and desirable. "Never remove true/false blocks" is not safe unless another same-pass cleanup removes the newly unreachable blocks before lowering/ReJIT.

## 2. Block-ordering safety

PC assignment is based on the `blocks` vector order. Lowering builds `block_order = 0..prog.blocks.len()` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:14-18`, assigns block start PCs in that order at `bbprogram_lower.rs:79-95`, and emits terminators against those recomputed PCs at `bbprogram_lower.rs:98-168`. The analysis-side `current_site_pcs()` also walks `prog.blocks()` in vector order at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1085-1108`.

If no blocks are removed, unrelated blocks keep the same relative order. The predecessor's body length changes, so later PCs shift by a constant delta, but branch offsets are recomputed during lower. The predecessor no longer has a conditional fallthrough; it has an explicit `JA` to `join`, so predecessor-to-join physical adjacency is not required.

That said, block-order safety is separate from verifier reachability. A no-remove rewrite can be perfectly lowerable and still rejected by `bpf_check()` because private `T/F` instructions are unreachable.

The safer algorithm is: always preserve `join`, but still remove private `T/F`. That removes the join-hoist physical-contiguity assumption while avoiding verifier-unreachable branch bodies. It should make the pass-local `physically_contiguous()` guard removable; that guard is currently enforced at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:314-319`, `cond_select.rs:365-369`, with the helper at `cond_select.rs:382-392`.

## 3. Why does current preserve_join+contiguity still panic on tetragon kinsn-6?

The available artifacts do not prove `cond_select` is the crashing pass.

The kinsn-5 tetragon run at `corpus/results/x86_kvm_corpus_20260513_024139_382635` completed. Its metadata enables `rotate`, `cond_select`, `extract`, `endian_fusion`, and `bulk_memory`; see `metadata.json`. The app payload shows `cond_select` was heavily exercised: local `jq` over `details/apps/tetragon__observer.json` found 1,636 `cond_select` applications across 170 programs, while the run still completed.

The kinsn-6 run at `corpus/results/x86_kvm_corpus_20260513_025046_252709` adds only `prefetch` in `metadata.json`. It has no `details/apps` payload because the VM died during the run. The pty log `/tmp/vng-pty-log.d140dqei` shows:

- tetragon baseline completed, then `rejit_start` began for 287 programs;
- three `bpf_rejit: retaining old JIT image after refresh failure` messages appeared;
- then an `int3` oops occurred with code bytes almost entirely `cc`;
- the stack is `trace_call_bpf -> kprobe_perf_func -> kprobe_ftrace_handler -> bpf_check -> bpf_prog_rejit -> __sys_bpf`;
- loaded modules include `bpf_prefetch`.

Those facts point to a rewritten tetragon kprobe program firing while `bpf_check()` is verifying another ReJIT candidate. The crash happens during ReJIT, not after a clean `rejit_done`. Since kinsn-5 already survived many `cond_select` rewrites, the strongest local hypothesis is that `prefetch`, or `prefetch` interacting with a prior kinsn rewrite, introduced a runtime JIT-image hazard.

Relevant prefetch code: the pass inserts a packed kinsn call with `old_len = 0` through `apply_candidates_reverse()` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:76-86` and `bpfopt/crates/bpfopt/src/pass.rs:601-617`. The x86 module proves the kinsn as `BPF_JMP_A(0)` at `module/x86/bpf_prefetch.c:34-45` and emits native `PREFETCHT0 [reg]` bytes at `module/x86/bpf_prefetch.c:58-105`.

The current cond_select block-removal path could still be a latent issue, but this panic is not evidence that a pure no-remove cond_select fix would avoid it. A pure no-remove fix would likely fail earlier with verifier-unreachable branch bodies.

## 4. Dead-code accumulation

The prompt assumption that downstream `dce` will remove unreachable `T/F` blocks is false for the current tree.

`DcePass` only removes dead register definitions. Its loop iterates `prog.def_sites()`, checks `uses_for_def(def).is_empty()`, and deletes removable dead-def instructions at `bpfopt/crates/bpfopt/src/passes/dce.rs:20-39`. It does not call `delete_unreachable_blocks()`.

There is a CFG unreachable-block API at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:370-395`, but the only production caller found is `cleanup_map_inline_bbprogram()` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1627-1633`. It is not part of `dce`.

Even if a later cleanup pass existed, it would be too late for v3 orchestration. The daemon invokes `bpfopt --pass <name>` and immediately calls `BPF_PROG_REJIT` after each pass, per the project architecture. A `cond_select` output containing unreachable private `T/F` blocks would be rejected before a later `dce` pass could run.

Size estimate, if this were only a size issue: Pattern A leaves roughly the old false `MOV`, false `JA`, and true `MOV` behind, about 3 instructions per diamond; Pattern C leaves roughly 1-2 branch-side instructions. For ~1,671 tetragon diamonds, that is on the order of 5k-7k dead instructions. That is below the 1M verifier instruction limit, but the verifier reachability rule is the real blocker.

## 5. Concrete diff sketch for the algorithm change

The pure no-remove sketch below is the tempting version, but it is not safe because it leaves private `T/F` unreachable:

```diff
diff --git a/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs b/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs
@@
         let (replacement, new_second_slots) = logical_replacement(replacement)?;
@@
-        let mut remove = BTreeSet::new();
-        ...
-
         if let Some(join) = pattern.join {
-            if preserve_join {
-                ...
-                predecessor.insns = replacement;
-                predecessor.terminator = Terminator::Jump {
-                    insn: BpfInsn::ja(0),
-                    target: join,
-                };
-            } else {
-                ... clone join body/terminator into predecessor ...
-            }
+            self.remap_metadata_sites(|site| Some(site));
+            let predecessor = self.block_mut(pattern.predecessor)?;
+            predecessor.insns = replacement;
+            predecessor.terminator = Terminator::Jump {
+                insn: BpfInsn::ja(0),
+                target: join,
+            };
         } else {
             ...
         }
@@
-        self.remove_blocks_in_place(&remove)?;
         Ok(())
```

The safe variant is "always preserve join, still remove private branch blocks":

```diff
diff --git a/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs b/bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs
@@
-        let any_branch_shared =
-            branch_shared(pattern.true_branch) || branch_shared(pattern.false_branch);
-        let join_shared = pattern.join.is_some_and(|join| {
-            let allowed = [
-                pattern.predecessor,
-                pattern.true_branch,
-                pattern.false_branch,
-            ];
-            self.predecessors(join)
-                .iter()
-                .any(|pred| !allowed.contains(pred))
-        });
-        let preserve_join = pattern.join.is_some() && (any_branch_shared || join_shared);
+        let preserve_join = pattern.join.is_some();
@@
         let mut remove = BTreeSet::new();
         for block in [pattern.true_branch, pattern.false_branch] {
             if block != pattern.predecessor && !branch_shared(block) {
                 remove.insert(block);
             }
         }
-        if let Some(join) = pattern.join {
-            if join != pattern.predecessor && !preserve_join {
-                remove.insert(join);
-            }
-        }
+        /* Never remove the join in the join-present path. */
@@
         if let Some(join) = pattern.join {
-            if preserve_join {
-                let remap_site = |site: InsnSite| -> Option<InsnSite> {
-                    (!remove.contains(&site.block)).then_some(site)
-                };
-                self.remap_metadata_sites(remap_site);
-                let predecessor = self.block_mut(pattern.predecessor)?;
-                predecessor.insns = replacement;
-                predecessor.terminator = Terminator::Jump {
-                    insn: BpfInsn::ja(0),
-                    target: join,
-                };
-            } else {
-                ... hoist join body/terminator into predecessor ...
-            }
+            let remap_site = |site: InsnSite| -> Option<InsnSite> {
+                (!remove.contains(&site.block)).then_some(site)
+            };
+            self.remap_metadata_sites(remap_site);
+            let predecessor = self.block_mut(pattern.predecessor)?;
+            predecessor.insns = replacement;
+            predecessor.terminator = Terminator::Jump {
+                insn: BpfInsn::ja(0),
+                target: join,
+            };
         } else {
             ...
         }
@@
         self.remove_blocks_in_place(&remove)?;
         Ok(())
```

That still uses block removal, but only for private branch blocks. It removes the join-hoisting/default path and the implicit physical-contiguity assumption without leaving verifier-unreachable branch bodies.

For `join == None`, do not convert to pure no-remove. Either keep the existing deletion/terminator-hoist behavior for that generic case, or split the API so cond_select only calls a join-preserving helper for `join: Some(_)`.

If the project insists that this helper itself never call `remove_blocks_in_place()`, then the replacement pass must call `delete_unreachable_blocks()` before lower/ReJIT. That is still block removal, just moved to a different API, and it has broader cleanup scope than the diamond-local removal.

## 6. What happens to `cond_select_rewrites_diamond_join_with_external_predecessor`?

The existing test is at `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:148-167`. It already asserts `sites_applied == 1` and that the lowered program contains a kinsn call. Under the safe "always preserve join, remove private T/F" variant, that should continue to pass; it is exactly the current shared-join behavior generalized to every join-present diamond.

Under the unsafe pure no-remove variant, the test would probably still pass too, because it does not assert reachability or absence of stale branch blocks. That means the current test is not strong enough to distinguish verifier-safe preserve-join from verifier-invalid no-remove.

Recommended test strengthening:

- keep `sites_applied == 1`;
- keep the `is_call_kinsn()` assertion;
- add an assertion that the old private branch body instructions from the inner diamond are not present as stale unreachable code, or add a CFG reachability assertion if a test-only helper is exposed;
- keep the external predecessor edge to the join covered, because that is the original regression.

No skip-reason assertion should be reintroduced. The external-join skip was a workaround for join deletion, not the desired contract.

## 7. Verifier acceptance

The BPF verifier rejects unreachable instructions. The in-tree kernel source says the first CFG pass rejects programs when "unreachable insns exist" at `vendor/linux-framework/kernel/bpf/verifier.c:56-65`. The actual rejection loop emits `"unreachable insn %d"` and returns `-EINVAL` at `vendor/linux-framework/kernel/bpf/verifier.c:19303-19319`.

Local negative tests encode the same contract:

- `tests/negative/adversarial_rejit.c:124-138` says unreachable code after an unconditional jump is still rejected;
- `tests/unittest/rejit_verifier_negative_tests.c:334-372` constructs a `JA +2` over two dead instructions and expects rejection.

Therefore, a no-remove cond_select rewrite that leaves private `T/F` blocks behind would not merely carry harmless dead code. It would produce a candidate that `BPF_PROG_REJIT` should reject with `EINVAL` before the workload can run.

## Verdict

Algorithm fix has corner case: verifier-rejected unreachable true/false branch blocks. Must handle by either:

- always preserving the join but still removing private `T/F` blocks in the same mutation, or
- running same-pass unreachable-block cleanup before lower/ReJIT.

Do not implement the pure "never remove blocks" algorithm. The recommended algorithm is "never remove the join in join-present diamonds"; that removes the physical-contiguity dependency while preserving verifier acceptance.
