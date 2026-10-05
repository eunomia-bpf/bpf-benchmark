# bpfopt crate code audit 2026-05-12

Scope: `bpfopt/crates/bpfopt/src/` only. `daemon` was not reviewed.

Pre-read checks:
- `cargo check -p bpfopt --message-format=short` from repo root failed because the workspace root has no `Cargo.toml`; rerun from `bpfopt/` passed with no warnings.
- Signal scan used `rg` for `TODO`, `FIXME`, `allow`, `dead_code`, `ok()`, `unwrap_or_default`, `let _ =`, `Result<..., String>`, `panic!`, `unwrap`, and `expect`. It found 158 hits, mainly test unwraps, verifier-log tolerant parsing, and nested `anyhow::Result<Result<T, String>>` pass-local APIs.
- All files requested in the prompt were read. `map_inline.rs` was split into four reads because it is 3508 lines.

## A. Duplicate / 重复逻辑

- [A1] `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1300` - `fn compute_liveness(prog: &BBProgram) -> LivenessSets` and `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1371` - `fn compute_site_liveness(prog: &BBProgram) -> anyhow::Result<SiteLivenessSets>`.
  Why: block-level and site-level liveness both rebuild use/def sets and run the same fixed-point equation. The two versions already diverge in kop implicit-use treatment, so a future bug fix can land in only one path.
  Recommendation: factor the fixed-point engine into one helper parameterized by node type, successor iterator, and public live-out policy.

- [A2] `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:928` - `collect_map_bindings(...)`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2018` - `fn map_id_for_ref(...)`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3439` - `fn analyze_map_info(...)`.
  Why: map FD/index to map-id resolution is implemented three times with slightly different fallbacks and error behavior. This is high-risk because map identity is a correctness boundary for `map_inline`.
  Recommendation: expose one `BBProgram` map-reference resolver and have `map_inline` consume it.

- [A3] `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2102` - `find_direct_map_load_for_reg_before_site_inner(...)`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2238` - `find_prev_reg_def(...)`, and `bpfopt/crates/bpfopt/src/passes/prefetch.rs:154` - `if let Some(ptr_def) = aliases[base_reg as usize]`.
  Why: multiple passes implement local linear alias/reaching-def tracking instead of using the existing use-def graph. These copies share the same CFG blind spot.
  Recommendation: add a common reaching-def/dominance query to `analysis/` and require pass code to use it for pointer identity.

- [A4] `bpfopt/crates/bpfopt/src/passes/extract.rs:50` - cross-block skip scan, `bpfopt/crates/bpfopt/src/passes/endian.rs:218` - similar scan, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:100` - custom `while idx < body.insns.len()`, and `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:179` - `prog.scan_block_starts(...)`.
  Why: consecutive-sequence detection and branch-target admission are repeated per pass. Some use `check_cross_block_pair_pattern`, some use bespoke logic, and wide/bulk have their own skip accounting.
  Recommendation: create one sequence scanner that reports candidates plus interior-target/cross-block skips.

## B. Dead code / unused

- [B1] `bpfopt/crates/bpfopt/src/pass.rs:77` - `pub branch_misses: u64`, `bpfopt/crates/bpfopt/src/pass.rs:87` - `pub cache_references: u64`, and `bpfopt/crates/bpfopt/src/pass.rs:89` - `pub miss_rate: f64`.
  Why: `rg` shows `branch_misses`, `PrefetchProfile.cache_references`, and prefetch `miss_rate` are written/deserialized but not read by production code. For branch_flip this is also a policy bug because real per-site PMU requires branch misses, not just a provided miss-rate float.
  Recommendation: either validate/use these fields or remove them from the current schema until consumed.

- [B2] `bpfopt/crates/bpfopt/src/pass.rs:573` - `pub has_bmi1`, `bpfopt/crates/bpfopt/src/pass.rs:574` - `pub has_bmi2`, `bpfopt/crates/bpfopt/src/pass.rs:576` - `pub has_movbe`, `bpfopt/crates/bpfopt/src/pass.rs:577` - `pub has_rorx`.
  Why: these CPU capability fields are set in `main.rs:376-379`, but production pass code no longer reads them; pass admission is kop-target based.
  Recommendation: delete the stale fields or wire them into explicit pass requirements if they are still meant to matter.

- [B3] `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:485` - `} else if insn.is_cond_jmp() || insn.is_ja() {`.
  Why: this branch is unreachable because `is_block_terminator(&insn)` already covers conditional jumps and `ja`; it is dead control-flow in CFG construction.
  Recommendation: delete the branch and keep a single terminator path.

- [B4] `bpfopt/crates/bpfopt/src/insn.rs:475` - `pub fn pseudo_call_to(call_pc: usize, target_pc: usize) -> Self`.
  Why: all observed callers are tests, but the helper is public production API and truncates the computed delta with `imm as i32`.
  Recommendation: move it under `#[cfg(test)]` or make it return `anyhow::Result<Self>` with checked `i32` conversion.

## C. 算法错误 / 正确性 bug

- [C1] `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:263` - `BPF_LD => { defs.insert(insn.dst_reg()); }`.
  Why: classic `LD_ABS` / `LD_IND` packet loads have implicit register semantics: they use packet context (`r6` for skb-style programs), write `r0`, and clobber caller-saved registers. Modeling them as only `dst_reg` defs makes liveness and DCE unsafe around classic packet loads.
  Recommendation: special-case `BPF_LD | BPF_ABS/IND` semantics in use-def, and add liveness/DCE regression tests.

- [C2] `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:190` - `RegUseDefSet { uses, defs: HashSet::new() }`.
  Why: kop calls encode their result destination in the sidecar payload, but use-def models only implicit uses and no defs. A later DCE or use-def query can see stale definitions for the kop destination.
  Recommendation: extend `KopDescriptor` to provide defs as well as uses, or decode destination registers for every kop payload.

- [C3] `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2111` - `let previous_sites = sites_before_in_frame_rev(prog, site)?` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2243` - `for site in sites_before_in_frame_rev(...)`.
  Why: `map_inline` resolves map pointer definitions by linear previous-in-frame scan. At a branch join, the nearest textual def can be from a path that does not dominate the lookup/load, producing the wrong map identity or offset.
  Recommendation: require exactly one reaching definition that dominates the use; otherwise skip the site.

- [C4] `bpfopt/crates/bpfopt/src/passes/map_inline.rs:397` - `lookup_key_setup_sites(...)`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:453` - `sites.insert(site)`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1726` - `lookup_pattern_sites.extend(key.setup_sites.iter().copied())`.
  Why: key stack stores are collected for deletion without proving those stack bytes are lookup-private. If the program reads the same stack key later, removing the stores changes behavior.
  Recommendation: keep key stores unless use-def/liveness proves no non-lookup uses of the stack slots.

- [C5] `bpfopt/crates/bpfopt/src/passes/map_inline.rs:523` - `let Some(map_load_site) = ... else { continue; };`.
  Why: writer helpers with unresolved map argument are silently ignored when building the kernel-mutable map set. That can allow inlining a map that is updated/deleted through an alias the resolver failed to understand.
  Recommendation: fail hard or conservatively mark candidate maps mutable when a writer helper's map argument is unresolved.

- [C6] `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:94` - `if previous.is_some_and(|prev| new_pc <= prev)`.
  Why: BTF remap assumes old record order remains increasing after transformation. `branch_flip` can reorder blocks with `permute_blocks`, so valid remapped PCs can decrease and lowering will bail.
  Recommendation: collect remapped records, sort by new PC, then emit with duplicate line handling.

- [C7] `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:145` - `let miss_rate = prog.branch_miss_rate(site)` while `bpfopt/crates/bpfopt/src/pass.rs:77` stores `branch_misses`.
  Why: branch_flip policy requires real per-site `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken`. The pass never reads or validates `branch_misses`, so placeholder misses plus a fabricated miss rate can pass admission.
  Recommendation: require `branch_misses`, validate it against `branch_count`, and derive or cross-check `miss_rate`.

- [C8] `bpfopt/crates/bpfopt/src/passes/prefetch.rs:154` - map-value alias scan returns on first memory use, and `bpfopt/crates/bpfopt/src/passes/prefetch.rs:166` only breaks on call/exit/pseudo-func/nonzero `ja`.
  Why: the scan crosses conditional branches in layout order and does not verify that the lookup dominates the dereference. It can attach a prefetch to an unrelated block where the register is not the map value on every path.
  Recommendation: use CFG dominance/reaching-def checks for the pointer definition and target dereference.

- [C9] `bpfopt/crates/bpfopt/src/passes/rotate.rs:250` - `(i1.imm as u32, i0.imm as u32, ...)` and `bpfopt/crates/bpfopt/src/passes/rotate.rs:256` - `lsh_amount + rsh_amount == width.bits()`.
  Why: invalid negative shift immediates are cast to large `u32` values and then added. In debug this can panic on overflow; in release it wraps. Verified loaded programs should not contain those shifts, but `bpfopt` should reject malformed bytecode rather than panic or wrap.
  Recommendation: use `u32::try_from`, range-check against width, and `checked_add`.

- [C10] `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:127` - `prog.try_replace_range(*dominant_add, 1, vec![widened], skipped)?;`.
  Why: the boolean admission result is ignored. If `try_replace_range` records a skip and returns `false`, the code still deletes later guard sites and counts the rewrite.
  Recommendation: handle `false` by skipping that rewrite and not deleting dependent sites.

## D. 不一致 / 接口 smell

- [D1] `bpfopt/crates/bpfopt/src/passes/map_inline.rs:469` - `type SiteRewriteResult<T> = anyhow::Result<std::result::Result<T, String>>`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:109` - `anyhow::Result<std::result::Result<u64, String>>`, and `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:112` - `anyhow::Result<std::result::Result<BpfInsn, String>>`.
  Why: hard errors and site-level vetoes are represented as nested result types in some passes and as `Option<String>` in others. This makes it easy to accidentally turn a hard error into a skip or vice versa.
  Recommendation: introduce a shared `RewriteDecision<T> { Apply(T), Skip(String) }` and keep `anyhow::Result` only for hard failures.

- [D2] `bpfopt/crates/bpfopt/src/passes/mod.rs:154` - `BranchFlipPass { min_bias: 0.7, max_branch_miss_rate: 0.05 }`.
  Why: branch_flip policy defaults are pass-local metadata but live in the global registry. Other pass-specific parsing/defaults are mostly colocated with their pass.
  Recommendation: move these defaults into `branch_flip.rs`, e.g. `BranchFlipPass::default_policy()`.

- [D3] `bpfopt/crates/bpfopt/src/passes/ccmp.rs:409` - `pack_u4((regs.len() - 2) as u8, 4)`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:411` - `pack_u4(fail_mode as u8, 6)`, and `bpfopt/crates/bpfopt/src/passes/ccmp.rs:412` - `pack_u4(width as u8, 7)`.
  Why: 4-bit fields are packed at overlapping bit offsets. Current enum values are 0/1, so it works today, but the encoding shape is misleading and brittle.
  Recommendation: use explicit 1-bit packing for `fail_mode` and `width`, or document/assert the single-bit ABI.

- [D4] `bpfopt/crates/bpfopt/src/pass.rs:570` - `PlatformCapabilities` has CPU-feature flags, while `bpfopt/crates/bpfopt/src/passes/mod.rs:100` and following use kop requirements.
  Why: the interface exposes two capability models, but only kop availability is enforced in production. Tests still toggle CPU flags, which can imply coverage that is no longer real.
  Recommendation: collapse to kop-target requirements plus `arch`, or make CPU features first-class requirements.

- [D5] `bpfopt/crates/bpfopt/src/test_helpers.rs:71` - `materialize_site_skips_for_tests(...)` drains `site_skipped` into a cfg(test) `sites_skipped` mirror.
  Why: production and tests observe different result shapes. This is understandable for PC materialization, but it creates a second skip-reporting API used only by tests.
  Recommendation: expose a shared reporting helper that tests and CLI both call, instead of a test-only field on `PassResult`.

## E. Test 质量问题

- [E1] `bpfopt/crates/bpfopt/src/test_helpers.rs:31` - `pass.run(&mut prog, ctx)` and `bpfopt/crates/bpfopt/src/test_helpers.rs:61` - `pass.run(&mut prog, ctx)`.
  Why: tests bypass `run_pass_once`, so they do not exercise production pass result accounting (`insns_before`, `insns_after`) or the wrapper-level invalidation policy.
  Recommendation: make test helpers call `run_pass_once`.

- [E2] `bpfopt/crates/bpfopt/src/verifier_log_tests.rs:172` - `unknown_verifier_attribute_does_not_fail_state_parse` and `bpfopt/crates/bpfopt/src/verifier_log_tests.rs:180` - `bad_verifier_attribute_value_does_not_fail_state_parse`.
  Why: these tests lock in tolerant parsing of malformed verifier facts. That conflicts with the fail-fast rule for verifier-state-dependent optimizations.
  Recommendation: replace them with strict-error tests for known attributes used by passes; only truly irrelevant unknown tokens should be ignored.

- [E3] `bpfopt/crates/bpfopt/src/analysis/bbprogram_liveness_tests.rs:35` - helper-call clobber test and `bpfopt/crates/bpfopt/src/analysis/bbprogram_liveness_tests.rs:49` - kop implicit-use test.
  Why: liveness tests cover helper calls and kop uses, but not classic `LD_ABS` / `LD_IND`. That gap would have caught C1.
  Recommendation: add a regression that proves classic packet loads use/clobber the correct registers and are protected from DCE.

- [E4] `bpfopt/crates/bpfopt/src/test_helpers.rs:235` - `branch_profile(taken, not_taken, miss_rate)` computes `branch_misses`, while `bpfopt/crates/bpfopt/src/passes/branch_flip_tests.rs:33` and following test only missing program/site data.
  Why: branch_flip tests never supply inconsistent or placeholder `branch_misses`, so they do not enforce the real-PMU requirement.
  Recommendation: add a test where `branch_misses` disagrees with `branch_count * miss_rate` and require a hard error.

- [E5] `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:14` - `fn lookup_program(old_fd: i32) -> Vec<BpfInsn>` and `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:499` - `map_inline_skips_kernel_mutable_map`.
  Why: map_inline tests cover linear lookup fixtures and one direct kernel-mutable case, but not CFG joins, unresolved writer-helper aliases, or lookup key stack stores reused after the lookup. Those are the main risk areas found in C3-C5.
  Recommendation: add targeted CFG/use-def regression tests before refactoring map_inline.

- [E6] `bpfopt/crates/bpfopt/src/passes/branch_flip_tests.rs:62` - `branch_flip_flips_biased_diamond_with_low_miss_rate`.
  Why: branch_flip tests validate instruction order changes without attaching BTF records. That misses the BTF non-increasing remap failure in C6.
  Recommendation: add a branch_flip test with func/line info that reorders across BTF offsets and then lowers successfully.

## Top 10 must-fix

1. Fix `LD_ABS` / `LD_IND` use-def modeling (C1). Estimate: 30-50 LOC plus tests. Impact: analysis, DCE, any liveness-dependent pass.
2. Model kop result definitions in use-def (C2). Estimate: 60-100 LOC. Impact: all kop passes followed by DCE/use-def consumers.
3. Replace map_inline linear previous-def scans with reaching-def/dominance checks (C3). Estimate: 120-200 LOC. Impact: map identity correctness.
4. Make unresolved map writer helpers conservative or hard errors (C5). Estimate: 20-40 LOC. Impact: map_inline safety for mutable maps.
5. Prove lookup key stack stores are private before deleting them (C4). Estimate: 60-100 LOC. Impact: map_inline semantic preservation.
6. Sort remapped BTF records after block permutation (C6). Estimate: 40-70 LOC. Impact: branch_flip and any future block reorder pass with BTF metadata.
7. Enforce branch_flip `branch_misses` validity (C7). Estimate: 20-35 LOC. Impact: Paper-B PGO integrity.
8. Make prefetch pointer discovery CFG/dominance-aware (C8). Estimate: 80-120 LOC. Impact: verifier safety for inserted prefetches.
9. Honor `try_replace_range` false in bounds_check_merge (C10). Estimate: 10-20 LOC. Impact: prevents partial guard deletion after admission skip.
10. Convert verifier-log known-field parse warnings into hard errors (E2/C-related). Estimate: 60-100 LOC. Impact: const_prop/map_inline verifier-state trust boundary.
