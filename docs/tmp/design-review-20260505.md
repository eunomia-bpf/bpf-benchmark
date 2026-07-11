# bpfopt-suite design review, 2026-05-05

Scope: strict DELETE-focused review against `CLAUDE.md`, `docs/kernel-jit-optimization-plan.md`, and the latest cumulative `docs/tmp/*-20260505.md` notes. This review documents code that should not exist, names that now mislead, and stale post-deletion residue. It does not propose new features.

## 1. Defensive / debug / sanity-check guards in production hot path

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| MED | `daemon/src/commands.rs:580-602` | `optimize_one_program` snapshots a program, encodes that same snapshot, then bails if `prog_info.id != prog_id` or if `prog_info.insn_cnt` disagrees with the encoded bytes. These are producer-invariant cross-checks inside the optimize hot path, not user/kernel boundary validation. | DELETE both checks; rely on `bpfget::snapshot_program` and `encode_insns` contracts, with invariant coverage in their own tests if needed. |
| MED | `daemon/src/commands.rs:787-795` | `candidate_has_kop_call && !needs_target(&pass_list)` is a runtime guard that protects the daemon's internal pass-to-target mapping from the daemon's own bugs. If a pass can emit a kop, the pass registry/target policy should encode that fact directly. | DELETE the cross-check; make missing target metadata fail at target preparation/pass execution instead of scanning output bytecode for an impossible internal state. |
| MED | `bpfopt/crates/bpfopt/src/main.rs:263-274`, `bpfopt/crates/bpfopt/src/main.rs:353-363` | `catch_unwind` converts internal optimizer panics into generic `internal bpfopt panic` / `internal pass panic` errors. That is a production guard around pass bugs and drops panic context instead of failing fast. | DELETE the panic-catching wrappers and let Rust panic normally; keep normal `Result` errors for user input and IO. |
| MED | `daemon/src/commands.rs:496-510`, `daemon/src/server.rs:79-85` | The daemon catches request/worker panics and serializes them as protocol errors, allowing an internal invariant failure to look like a handled optimization result. | DELETE the panic recovery path or gate it to test-only harnesses; internal panics should crash the daemon so supervision and CI see the defect. |
| LOW | `bpfopt/crates/bpfprof/src/main.rs:982-1018` | `read_u32/read_i64/read_u64` perform a bounds-checked slice read and then report `"slice length changed after bounds check"` if `try_into()` fails. That error is impossible after `get(offset..end)` with a fixed size. | REFACTOR to remove the impossible error branch; keep only real offset overflow/truncation errors. |
| MED | `runner/libs/rejit.py:649-683` | The runner validates `summary.passes_executed == len(passes)` and `summary.total_sites_applied == sum(passes[].sites_applied)`. Both sides are daemon-derived rollups from the same response, so this is a defensive disagreement guard between duplicated fields. | DELETE the cross-check with the summary fields in section 5. Do not touch `runner/libs/` in this review run. |

## 2. Misleading function/struct/field names

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| MED | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:94`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1243`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1288`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1340-1384` | `FrozenMapValue`, `map_cache: ... FrozenMapValue`, and `resolve_frozen_map_value` no longer check `BPF_F_RDONLY_PROG`, map freeze state, or any invalidation guarantee. They resolve snapshot-backed pseudo-map-value loads. The `frozen` name now overstates safety. | RENAME to `SnapshotMapValue` and `resolve_snapshot_map_value` or equivalent direct-snapshot wording. |
| LOW | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:348`, `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:377` | Test names still say `frozen_pseudo_map_value`, but the tested behavior is snapshot-backed direct pseudo-map-value constantization. | RENAME with the production symbol rename above. |

## 3. Dead code from cumulative deletions

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| MED | `bpfopt/crates/bpfopt/src/pass.rs:538-545`, `bpfopt/crates/bpfopt/src/pass_tests.rs:651-688` | `PassResult::skip_reason_counts()` has no production caller; it is only exercised by `test_pass_result_skip_reason_counts`. It survived as a small summary helper after reporting cleanup. | DELETE the method and its test. |

## 4. Fallback / silenced-error patterns

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| HIGH | `bpfopt/crates/bpfopt/src/pass.rs:637`, `bpfopt/crates/bpfopt/src/pass.rs:677-688` | `supported_encodings_for_target_name()` falls back to `BPF_KOP_ENC_PACKED_CALL` whenever a BTF ID exists but target encoding metadata is missing. Missing v3 target capability data should be a visible defect, not a packed-call downgrade. | DELETE the fallback; require explicit `target_supported_encodings` for any target with a usable BTF ID. |
| MED | `bpfopt/crates/bpfopt/src/main.rs:332-337`, `bpfopt/crates/bpfopt/src/main.rs:1170-1179` | `run_single_pass` writes an `unchanged_report` if the pipeline returns no pass result. For a requested pass, "no pass result" is an internal pipeline/registry defect, not a normal unchanged pass. | DELETE `unchanged_report` and fail if the requested pass does not return exactly one report. |
| MED | `bpfopt/crates/bpfprof/src/main.rs:578-582` | `relative_branch_target()` uses `.ok()?` and checked arithmetic to silently convert impossible branch-target conversion failures into `None`, dropping `taken_target_pc` from the profile. Verifier-valid BPF branch offsets should not disappear silently. | REFACTOR to return `Result<usize>` and propagate conversion/overflow errors. |
| MED | `runner/libs/rejit.py:276-283`, `runner/libs/rejit.py:448-461`, `runner/libs/rejit.py:501-511` | Runner normalization keeps legacy fallbacks: `sites_found`, derived `sites_applied + sites_skipped`, default `action="kept"`, and fallback from `summary.total_sites_applied`. This preserves older daemon shapes instead of making protocol drift fail. | DELETE compatibility fallbacks and require the current daemon response shape, or omit derived site totals entirely with section 5. Do not touch `runner/libs/` in this review run. |
| HIGH | `daemon/src/commands.rs:993-1012` | Map key scan overflow is logged with `eprintln!`, converted into `SkippedMapEntry`, and optimization continues. This is warning-and-continue for fallible live map work, exactly the fail-fast anti-pattern. | DELETE the skip branch; return the scan error with map context. |

Boundary hits reviewed but not flagged: test-only skip messages in `kernel-sys`/`bpfprof` tests, normal CLI stderr printing, non-BPF `perf_event_open`, and optional provenance reads in Python boundary code.

## 5. In-framework summary / aggregation fields

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| HIGH | `daemon/src/commands.rs:126-143`, `daemon/src/commands.rs:213-223`, `daemon/src/commands.rs:811-838` | `OptimizeOneResult` carries `passes_applied` and an `OptimizeSummary`; the daemon computes `total_sites_applied`, `passes_executed`, and `passes_changed`. These are in-framework rollups derived from per-pass records. | DELETE `OptimizeSummary`, `passes_applied`, and the derived count/sum calculations; keep raw per-pass records and errors only. |
| HIGH | `daemon/src/server.rs:230-260` | Multi-program optimize response computes and emits `program_counts.requested/applied/not_applied`. This is a framework-level rollup. | DELETE `program_counts`; return `per_program` plus error/status only. |
| HIGH | `runner/libs/rejit.py:473-512`, `runner/libs/rejit.py:515-529`, `runner/libs/rejit.py:649-695`, `runner/libs/rejit.py:886-893` | Runner code computes `total_sites`, aggregates per-pass site counts across programs, preserves `summary`/`program_counts`, and re-emits `program_counts`. These are in-framework summaries rather than raw measurements. | DELETE applied-site aggregation and summary/program-count artifact fields. Do not touch `runner/libs/` in this review run. |
| MED | `bpfopt/crates/bpfopt/src/pass.rs:786-792`, `bpfopt/crates/bpfopt/src/pass.rs:904-922` | `PipelineResult.total_sites_applied` sums per-pass site counts. Even inside `bpfopt`, it is a summary scalar over pass reports, and several trivial pass-manager tests exist only to assert it. | DELETE `total_sites_applied`; callers should inspect raw `pass_results` if needed. |
| HIGH | `corpus/driver.py:153-162`, `corpus/driver.py:857`, `corpus/driver.py:940`, `corpus/driver.py:952`, `corpus/driver.py:964` | The corpus runner builds and writes `result.md`, a markdown rollup of the result payload. `CLAUDE.md` forbids framework markdown rollups. | DELETE `build_markdown()` and all `detail_texts={"result.md": markdown}` writes. |
| HIGH | `runner/src/common.cpp:60-63`, `runner/src/common.cpp:97-102` | The C++ runner computes and emits `code_size.inflation_ratio`. Ratios are analysis-side, not framework output. | DELETE `inflation_ratio`; keep raw `bpf_bytecode_bytes` and `native_code_bytes`. |

The forbidden named functions (`geometric_mean`, `bootstrap_geometric_mean_ci`, `win_counts`, `comparison_summary`, `derive_perf_metrics`, etc.) were not found in live framework code outside old result data / external analysis-style files.

## 6. Map invalidation residue

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| LOW | `docs/bpfrejit-story.md:182` | The story still describes dynamic map inlining as `map stable -> inline -> invalidation -> re-REJIT` and calls it the paper core story. Current plan context says benchmark model is snapshot once -> inline -> ReJIT -> measure, with no production invalidation polling. | REWRITE or DELETE the stale invalidation wording. |

No live code references to `expected_value`, tracked map entries, polled snapshots, refresh intervals, or map-invalidation tracker state were found. Analysis-cache invalidation references in `bpfopt` are unrelated to the deleted map invalidation tracker.

## 7. Unit tests that violate unit-test quality

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| LOW | `bpfopt/crates/bpfopt/src/pass_tests.rs:473-497` | `test_kop_registry_per_target_call_offsets` tests a direct `HashMap` lookup through `call_off_for_target_name`; it has no bug-specific branch or boundary. | DELETE. |
| LOW | `bpfopt/crates/bpfopt/src/pass_tests.rs:651-688` | `test_pass_result_skip_reason_counts` only tests the dead summary helper from section 3 and mostly re-tests counting strings into a map. | DELETE with `skip_reason_counts()`. |
| LOW | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:482-509`, `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:597-620` | `test_cond_select_register_alias_safety` duplicates the same pattern and semantic assertions already covered by `test_cond_select_emit_with_reg_values`. | DELETE `test_cond_select_register_alias_safety`. |
| LOW | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:689-718`, `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:720-777` | `test_cond_select_alias_cycle_r1_r2` is subsumed by the exhaustive r1/r2/r3 overlap matrix. | DELETE the single-cycle duplicate. |
| LOW | `bpfopt/crates/bpfopt/src/passes/rotate.rs:650-670`, `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:412-427`, `bpfopt/crates/bpfopt/src/passes/extract.rs:592-610`, `bpfopt/crates/bpfopt/src/passes/endian.rs:1195-1213`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:955-976` | These pass-manager integration tests only assert generic `program_changed` / `total_sites_applied` plumbing after pass-local tests already cover the transform behavior. They become especially vestigial if section 5 deletes `total_sites_applied`. | DELETE the pass-manager plumbing tests; keep pass-local bug/regression tests. |

## 8. CLI cross-dependencies

No violations found.

Checked:

- `bpfopt/crates/bpfopt/Cargo.toml:1-16` depends on `kernel-sys` only among local crates.
- `bpfopt/crates/bpfprof/Cargo.toml:1-19` depends on `kernel-sys` only among local crates.
- `daemon/Cargo.toml:1-35` depends on daemon-owned `bpfget` and shared `kernel-sys`, not on `bpfopt` or `bpfprof`.

## 9. Direct `libc::syscall(SYS_bpf)` outside `kernel-sys`

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| HIGH | `runner/src/bpf_helpers.cpp:23-33`, `runner/src/bpf_helpers.cpp:48-58`, `runner/src/bpf_helpers.cpp:77-87` | The C++ runner directly invokes `syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, ...)` for standard BPF info/JIT/xlated dumps. `CLAUDE.md` says `kernel-sys` is the only BPF syscall boundary and standard commands should use libbpf/libbpf-sys. | REFACTOR/MOVE this access through an allowed boundary: libbpf APIs in runner C++ if sufficient, or a `kernel-sys`-owned helper exposed to the runner build. |

Allowed direct BPF syscall found: `bpfopt/crates/kernel-sys/src/lib.rs:443-452`, inside `kernel-sys`.

## 10. New informational-only fields

| Severity | File:line | What is wrong | Recommended action |
|---|---:|---|---|
| HIGH | `daemon/src/commands.rs:137-138`, `daemon/src/commands.rs:194-201`, `daemon/src/commands.rs:1002-1010` | `skipped_maps` / `SkippedMapEntry` records a map-inline "capability limitation" instead of failing the map snapshot path. This is the exact `limitations`-style informational-only payload forbidden by `CLAUDE.md`. | DELETE `SkippedMapEntry`, `skipped_maps`, and the scan-overflow skip path; propagate the error. |

The summary fields in section 5 (`summary`, `program_counts`, `passes_applied`, `inflation_ratio`) are also informational/derived payloads, but they are counted under the explicit summary/aggregation rule rather than duplicated here.

## Totals

- Total violations found: 28
- HIGH: 9
- MED: 11
- LOW: 8

Estimated LoC delta if all HIGH+MED recommendations are executed: approximately **-360 LoC**. This treats renames and syscall boundary moves as net-zero, and counts deletion of summary/fallback/defensive code plus their now-vacuous tests.

Top 3 most impactful deletions:

1. DELETE daemon/runner summary payloads and site/program rollups (`summary`, `program_counts`, `passes_applied`, `total_sites*`): largest alignment win for "No In-Framework Computation or Summary".
2. DELETE `SkippedMapEntry` plus map-scan warning-and-continue: removes a clear fail-fast violation and redundant informational field in one cut.
3. DELETE legacy protocol fallbacks in `runner/libs/rejit.py`: stops old daemon shapes and derived summaries from silently surviving after the v3 boundary cleanup.
