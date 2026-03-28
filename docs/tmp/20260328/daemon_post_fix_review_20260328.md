# Daemon Post-Fix Review 2026-03-28

## Scope

- Reviewed `HEAD^..HEAD` for all modified `daemon/src/**` files:
  - `analysis/map_info.rs`
  - `bpf.rs`
  - `commands.rs`
  - `elf_parser.rs`
  - `insn.rs`
  - `main.rs`
  - `pass.rs`
  - `passes/const_prop.rs`
  - `passes/map_inline.rs`
  - `passes/mod.rs`
  - `server.rs`
  - `test_utils.rs`
- Ran `make daemon-tests`
  - Result: `503 passed, 0 failed, 13 ignored`
- Grepped touched production files for residual risky patterns:
  - `unwrap_or_default`
  - `.ok()`
  - ignored `Result`
  - `TODO|FIXME|hack|HACK`

## Findings

### [High] Rollback attribution is still stored in stale per-pass coordinates, not final program coordinates

- Files:
  - `daemon/src/pass.rs:700-788`
  - `daemon/src/pass.rs:808-845`
  - `daemon/src/commands.rs:319-335`
- Problem:
  - `PassManager::run_single_pass()` records `changed_pc_ranges(&before_insns, &program.insns)` immediately after each pass and pushes those ranges straight into `PipelineResult.attribution`.
  - Later passes can insert/delete instructions before those ranges, but earlier attributions are never remapped or composed forward to the final instruction stream.
  - `attribute_verifier_failure()` then matches the final verifier PC against these stale ranges.
- Impact:
  - A verifier rejection after later layout changes can become unattributable or be attributed to the wrong pass.
  - This is especially likely in the `const_prop` + `dce` fixed-point loop, where `const_prop` changes a site and later `dce` deletes earlier instructions/blocks.
- Why this is real:
  - The code never updates previously recorded `pc_ranges` after subsequent transforms.
  - Existing tests only cover simple append/rewrite cases where later passes do not shift earlier changed PCs.
- Missing coverage:
  - No regression test where pass A changes PC `X`, pass B deletes/inserts before `X`, and rollback must still match the final verifier PC back to pass A.

### [Medium] Server pass-list parsing still allows a silent no-op via empty or whitespace pass names

- File:
  - `daemon/src/server.rs:171-207`
- Problem:
  - `parse_request_pass_list()` trims each string and silently drops empty entries instead of rejecting them.
  - Example: `{"enabled_passes":["   "]}` becomes `enabled_passes = []`, passes validation, and disables the whole pipeline without an error.
- Impact:
  - This reintroduces the exact class of silent no-op behavior that the alias/unknown-pass fix was trying to eliminate.
  - `enabled_passes` / `disabled_passes` validation is registry-consistent for non-empty names, but empty names bypass validation entirely.
- Missing coverage:
  - No test for empty-string or whitespace-only entries.

### [Medium] `serve` / `watch` still silently drop invalidation polling errors

- Files:
  - `daemon/src/server.rs:77-84`
  - `daemon/src/server.rs:309-315`
  - `daemon/src/server.rs:382-390`
- Problem:
  - The call sites use `let _ = process_invalidation_tick(...)`.
  - `process_invalidation_tick()` logs per-program reoptimization failures internally, but errors from `tracker.check_for_invalidations()` or tracker lock poisoning are returned to the caller.
  - Those returned errors are currently discarded with no log and no response propagation.
- Impact:
  - In daemon modes, invalidation polling can fail silently, leaving speculative `map_inline` specializations stale until the next successful poll, or indefinitely if the failure persists.
  - This is a residual silent-swallow point in the same area this patch set was trying to harden.
- Missing coverage:
  - There is only a success-path test for `process_invalidation_tick`; no test covers caller behavior when the function returns `Err`.

### [Low] `list-passes` is no longer a clean early-exit command

- File:
  - `daemon/src/main.rs:107-142`
- Problem:
  - `kfunc_discovery::discover_kinsns()` and platform probing now run before the `match`, so `ListPasses` performs system discovery and prints probe logs to stderr before listing static pass names.
- Impact:
  - This is not a correctness bug, but it is a CLI regression from the previous early-return behavior.
  - A purely informational command now does extra work and has environment-dependent side effects.

## Review Notes

### Error propagation

- The intended fixes are present in the main high-risk paths:
  - `bpf_prog_get_map_ids(...).unwrap_or_default()` call sites in `commands.rs` were converted to propagated errors.
  - `relocate_map_fds_with_bindings()` now hard-fails on unresolved map IDs and `BPF_MAP_GET_FD_BY_ID` failures.
  - `MapInfoAnalysis` now propagates live-map lookup errors into `map_inline`.
  - `iter_prog_ids()` no longer swallows non-`ENOENT` enumeration failures.
- I did not find a new obvious case where these repaired paths bail incorrectly in normal operation.
- The one place where error handling is still too silent is invalidation polling in `server.rs` (finding above).

### Rollback / diff logic

- The new per-pass diffing is directionally better than the old whole-program fallback.
- The remaining correctness gap is coordinate stability across later passes, not the local `changed_pc_ranges()` diff itself.

### `const_prop` jump fix

- The implementation in `fixup_folded_jumps()` is consistent with the specific bug it is fixing: a conditional jump folded to `JA` whose target PC moves after other replacements widen/shrink the program.
- The new unit test covers the important forward-jump + `LD_IMM64` growth case.
- Coverage is still incomplete:
  - no backward-jump case
  - no `JMP32` case
  - no jump-to-`old_insns.len()` case
  - no test where later `dce` also changes layout after the folded jump

### Pass-name validation vs registry

- `server.rs` now validates `enabled_passes` and `disabled_passes` through `passes::validate_pass_names()`.
- `passes::validate_pass_names()` resolves directly against `PASS_REGISTRY`, so canonical-name validation is consistent with the registry.
- Legacy aliases such as `skb_load_bytes` and `bulk_mem` are correctly rejected.
- The only gap I found here is the empty-string bypass in `parse_request_pass_list()` (finding above).

### Dead code / TODOs / ignored tests

- Removed dead-code paths appear to be actually gone:
  - no `PipelineProfile`
  - no `pipeline_profile`
  - no `build_pipeline_for_profile()`
  - no `selected_pass_names()`
- I did not find new `TODO` / `FIXME` / `hack` markers in the touched files.
- The test suite still has existing `#[ignore]` tests for live-kernel/syscall environments, but this patch did not introduce new ignored tests.

## Grep Summary

### Residual hits worth attention

- Ignored `Result` in touched production code:
  - `daemon/src/server.rs:80`
  - `daemon/src/server.rs:311`
  - `daemon/src/server.rs:384`
- Convenience `.ok()` adapters still exist elsewhere, but the remaining hits in this review scope are not in the repaired map-ID / relocation / pass-validation paths.

### No concerning markers found in touched files

- `TODO`
- `FIXME`
- `hack`
- `HACK`

## Overall Assessment

- The patch set materially improves daemon robustness and removes the main silent fallbacks called out in the task description.
- Pass-name validation is much stricter and registry-consistent.
- The new tests are useful and the overall daemon test suite is healthy.
- The biggest remaining issue is that rollback attribution is still not final-PC-correct once later passes move code. That needs to be fixed before the rollback story can be considered complete.
