# Daemon Mock Test Audit Report

**Date**: 2026-03-23
**Scope**: All `#[cfg(test)]` modules and `#[test]` functions in `daemon/src/`
**Context**: Two severe bugs recently shipped because mock tests gave false confidence:
1. `BPF_BTF_GET_NEXT_ID` constant was 22 instead of 23 -- mocked BTF data never exercised the real syscall
2. `relocate_map_fds` extracted `dst_reg` instead of `src_reg` -- synthetic instructions had equal dst/src

---

## Executive Summary

The daemon has **~150 unit tests** across 14 source files. The overall test quality is **good for pass logic** (pattern matching, branch fixup, register alias safety) but **weak for kernel interface correctness** (syscall constants, struct layouts, BTF parsing against real data). Key findings:

- **HIGH risk**: 6 areas where mocks could hide real interface bugs
- **MEDIUM risk**: 8 areas where simplified inputs skip important edge cases
- **LOW risk**: The bulk of tests (pass pattern matching, verifier log parsing, profiler math) are appropriate

After the two recent bugs, several regression tests and constant-sync tests were added (e.g., `test_bpf_cmd_constants_match_kernel_header`, `test_relocate_map_fds_regression_dst_vs_src`). These are good but were added *after* the bugs shipped, confirming the audit's premise: mock tests alone are insufficient for kernel interface code.

---

## File-by-File Audit

### 1. `bpf.rs` -- BPF Syscall Wrappers

| Test Name | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `test_bpf_cmd_constants_match_kernel_header` | Nothing (parses real kernel header) | **LOW** | Good test -- parses `vendor/linux-framework/include/uapi/linux/bpf.h` and verifies all constants. Added post-bug-1. | Keep. Consider running as part of CI build (not just `cargo test`). |
| `test_attr_struct_sizes_fit_bpf_attr` | Nothing (compile-time layout check) | **LOW** | Verifies all attr structs are 128 bytes. Good. | Keep. |
| `test_attr_rejit_field_offsets` | Nothing (compile-time layout check) | **LOW** | Verifies AttrRejit field offsets match kernel layout. Good. | Keep. |
| `test_bpf_prog_info_size` | Nothing (compile-time layout check) | **MEDIUM** | Checks `>= 216` and `<= 512` -- loose bounds. Does NOT verify that `BpfProgInfo` field layout matches kernel's `struct bpf_prog_info` field-by-field. If a kernel update inserts a field in the middle, our struct would be silently wrong. | Add a field-offset test similar to `test_attr_rejit_field_offsets` that verifies offsets of critical fields (`prog_type`, `id`, `xlated_prog_len`, `btf_id`, `nr_map_ids`, `orig_prog_len`, `orig_prog_insns`) against known kernel offsets. |
| `test_bpf_prog_info_orig_fields_at_end` | Nothing (layout check) | **MEDIUM** | Only checks relative ordering, not absolute offsets. `orig_prog_len` and `orig_prog_insns` are custom BpfReJIT fields -- if the stock `bpf_prog_info` grows, these offsets shift. | Parse the kernel header to compute expected offsets, similar to `parse_bpf_cmd_enum`. |
| `test_bpf_prog_info_name_str` | Constructs BpfProgInfo manually | **LOW** | Tests string extraction from byte array. Simple and correct. | Keep. |
| `test_btf_info_struct_size` | Nothing (layout check) | **LOW** | Verifies BtfInfo is 128 bytes. Good. | Keep. |
| `test_relocate_map_fds_*` (6 tests) | Constructs synthetic LD_IMM64 instructions | **MEDIUM** | Tests src_reg vs dst_reg extraction correctly (regression for bug #2). However, none test the *full* relocate path (open map FDs by ID, patch instructions, return owned FDs) because that requires real BPF maps. The critical `bpf_map_get_fd_by_id` call is never tested. | The `#[ignore]` smoke tests partially cover this. Add a focused `#[ignore]` test that loads a real BPF program with maps, calls `bpf_prog_get_map_ids`, then `relocate_map_fds`, and verifies the patched FDs are valid. |
| `test_bpf_prog_get_next_id_smoke` (ignored) | Nothing (real syscall) | **LOW** | Good -- exercises real BPF syscall. Correctly `#[ignore]`'d for non-root. | Keep. Ensure VM test pipeline runs `cargo test -- --ignored`. |
| `test_iter_prog_ids_returns_some` (ignored) | Nothing (real syscall) | **LOW** | Good. | Keep. |
| `test_bpf_prog_get_fd_and_info_smoke` (ignored) | Nothing (real syscall) | **LOW** | Good -- tests the full prog_id -> fd -> info path. | Keep. |
| `test_btf_get_next_id_smoke` (ignored) | Nothing (real syscall) | **LOW** | Good -- directly validates BPF_BTF_GET_NEXT_ID constant. | Keep. |
| `test_btf_get_fd_by_id_and_info_smoke` (ignored) | Nothing (real syscall) | **LOW** | Good. | Keep. |
| `test_btf_module_enumeration` (ignored) | Nothing (real syscall) | **LOW** | Good -- exercises the full BTF enumeration chain. | Keep. |
| `test_bpf_btf_get_fd_by_module_name_vmlinux_not_found` (ignored) | Nothing (real syscall) | **LOW** | Good -- tests the negative case. | Keep. |

**HIGH-risk gap in `bpf.rs`**: No unit test verifies `BpfProgInfo` field layout against the actual kernel struct. The struct has 30+ fields and any insertion by the kernel would silently corrupt all fields after it. The `test_bpf_prog_info_size` test only checks total size bounds, not individual field offsets.

**Recommendation**: Add a test that parses `struct bpf_prog_info` from the kernel header (similar to `parse_bpf_cmd_enum`) and verifies critical field offsets.

---

### 2. `kfunc_discovery.rs` -- BTF Parsing and Kfunc Discovery

| Test Name | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `test_find_func_btf_id_found` | Hand-built BTF blob (1 FUNC type) | **MEDIUM** | Uses `build_btf_blob` which creates a minimal valid BTF with a single FUNC. Real module BTF has dozens of types with variable-length extra data. The test passes but does NOT exercise the `vlen`-based skip logic for most BTF kinds. | The `test_find_func_in_mixed_btf` test covers this. Mark as LOW. |
| `test_find_func_btf_id_not_found` | Same mock blob | **LOW** | Tests negative case. Fine. | Keep. |
| `test_find_func_btf_id_empty_data` | Empty input | **LOW** | Boundary check. Fine. | Keep. |
| `test_find_func_btf_id_bad_magic` | Corrupted mock blob | **LOW** | Tests error handling. Fine. | Keep. |
| `test_find_func_btf_id_multiple_types` | Hand-built BTF with 2 FUNCs | **LOW** | Tests type ID counting. Fine. | Keep. |
| `test_find_func_in_mixed_btf` | Hand-built BTF with INT, PTR, STRUCT, FUNC_PROTO, FUNC | **LOW** | Good -- exercises the vlen skip logic for INT (4 bytes), STRUCT (12*vlen), FUNC_PROTO (8*vlen). This is the most comprehensive synthetic BTF test. | Keep. Consider adding ENUM, VAR, DATASEC, ENUM64 variants for completeness. |
| `test_find_func_split_btf` | Hand-built split BTF blob | **LOW** | Good -- tests the base_str_off logic that real module BTF uses. | Keep. |
| `test_discover_kfuncs_no_modules_loaded` | Nothing (real filesystem) | **LOW** | Runs `discover_kfuncs()` against the real `/sys/kernel/btf/`. On a host without kinsn modules, validates the graceful fallback. | Keep. |
| `test_btf_header_size` / `test_btf_type_size` | Nothing (compile-time) | **LOW** | Layout checks. Fine. | Keep. |
| `test_btf_kind_constants_match_kernel` | Nothing (hardcoded values) | **MEDIUM** | Verifies BTF_KIND_* constants match expected values, but these values are hardcoded in the test, NOT parsed from the kernel header. If the kernel changes BTF kind numbering, both the constants and the test would need updating together (the test wouldn't catch a stale constant). | Parse `vendor/linux-framework/include/uapi/linux/btf.h` to verify constants, similar to `parse_bpf_cmd_enum` for bpf_cmd. |
| `test_get_vmlinux_str_len_real` (ignored) | Nothing (real filesystem) | **LOW** | Good -- reads real vmlinux BTF. | Keep. |
| `test_find_func_in_real_vmlinux_btf` (ignored) | Nothing (real BTF) | **LOW** | Good -- but doesn't assert the result. Should assert `result.is_some()` for a well-known kernel function. | Strengthen assertion: `assert!(result.is_some(), "bpf_prog_run_xdp should exist in vmlinux BTF")`. |
| `test_discover_kfuncs_real` (ignored) | Nothing (real BPF syscall chain) | **LOW** | Good -- validates the full BTF_GET_NEXT_ID -> BTF_GET_FD_BY_ID -> GET_INFO_BY_FD chain. Would have caught bug #1 if it had been run. | **Must run in VM CI**. This is the most valuable integration test for kfunc discovery. |

**HIGH-risk gap in `kfunc_discovery.rs`**: The `test_btf_kind_constants_match_kernel` test hardcodes expected values instead of parsing the kernel header. If the kernel adds a new BTF kind that shifts existing values, this test would pass with stale constants.

---

### 3. `pass.rs` -- Pass Framework, PassManager, Analysis Cache

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| PassManager tests (~30 tests) | Uses synthetic NoOpPass, AppendNopPass, RewriteMovImmPass | **LOW** | These test the pass framework itself (ordering, cache invalidation, profiling injection, disabled passes, attribution). The mock passes are appropriate -- real passes are tested separately. | Keep. |
| `PassContext::test_default()` | All kfunc btf_ids = -1, all platform caps = false | **LOW** | Correct default for testing pass logic when kfuncs are unavailable. | Keep. |
| BpfProgram tests | Synthetic instruction streams | **LOW** | Tests `sync_annotations`, `remap_annotations`, `inject_profiling`, `log_transform`. Pure data structure operations. | Keep. |

No HIGH-risk findings in `pass.rs`. The framework tests are well-designed.

---

### 4. `passes/rotate.rs` -- Rotate Pass

| Test Name | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `test_rotate_pass_pattern_match` | Synthetic 4-insn rotate pattern | **LOW** | Tests the canonical pattern. Good. | Keep. |
| `test_rotate_pass_pattern_b_match` | Synthetic LSH-first variant | **LOW** | Tests both orderings. Good. | Keep. |
| `test_rotate_pass_no_match_wrong_sum` | Sum != 64 | **LOW** | Edge case. Good. | Keep. |
| `test_rotate_pass_no_match_without_provenance` | Missing MOV provenance | **LOW** | Tests safety check. Good. | Keep. |
| `test_rotate_pass_no_match_wrong_provenance` | Wrong MOV source | **LOW** | Tests safety check. Good. | Keep. |
| `test_rotate_pass_emit_kfunc_call` | Synthetic program + mock kfunc btf_id | **MEDIUM** | Tests that a kfunc call is emitted with the correct btf_id. However, does NOT test that the emitted bytecode would pass the kernel verifier. The kfunc call has `src_reg=2` and a fake btf_id=9999 -- in a real kernel, the verifier would reject this if the BTF ID doesn't match a loaded kfunc. | Add `#[ignore]` integration test that loads a real BPF program, applies RotatePass with real kfunc BTF IDs, and verifies via REJIT. |
| `test_rotate_pass_caller_saved_conflict` | Synthetic program with r3 live-out | **LOW** | Safety check. Good. | Keep. |
| `test_rotate_pass_tmp_live_out_conflict` | Synthetic program with r6 live-out | **LOW** | Safety check. Good. | Keep. |
| `test_rotate_pass_no_match_dst_overwritten_*` (3 tests) | Various provenance-breaking patterns | **LOW** | Good edge case coverage. | Keep. |
| `test_rotate_pass_integration_with_pass_manager` | Synthetic program via PassManager | **LOW** | Tests integration with analysis pipeline. Good. | Keep. |

**MEDIUM risk**: All rotate tests use synthetic 4-7 instruction programs. Real programs have hundreds of instructions with complex control flow. The liveness analysis used by the safety checks is tested separately, so this is acceptable, but a test with a real compiled BPF program's rotate pattern would increase confidence.

---

### 5. `passes/cond_select.rs` -- Conditional Select Pass

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| Detection tests (6) | Synthetic JCC+MOV diamond patterns | **LOW** | Comprehensive pattern matching. Tests both 4-insn diamond and negative cases. Good. | Keep. |
| Emit tests (10+) | Synthetic programs + mock btf_id | **LOW** | The `simulate_param_setup` helper is excellent -- it simulates register moves to verify the parallel-copy algorithm produces correct argument ordering. | Keep. |
| `test_cond_select_alias_all_overlap_combinations` | Exhaustive 3^3 = 27 combinations of (cond_reg, true_src, false_src) among r1/r2/r3 | **LOW** | Outstanding test -- catches the exact class of alias bug that was found. | Keep. |
| JEQ swap test | Synthetic JEQ pattern | **LOW** | Tests the true/false value swap for JEQ vs JNE. Good. | Keep. |

No HIGH-risk findings. This is the best-tested pass in the daemon.

---

### 6. `passes/endian.rs` -- Endian Fusion Pass

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| Pattern scanning (8 tests) | Synthetic LDX_MEM + ENDIAN_TO_BE patterns | **LOW** | Tests all three sizes (16, 32, 64), mismatches, multiple sites. Good. | Keep. |
| Pass execution (12 tests) | Synthetic programs + mock btf_ids | **LOW** | Tests kfunc emission, zero/nonzero offset, caller-saved conflict, interior branch target, branch fixup, module FD recording, size-specific kfunc unavailability. Good. | Keep. |

No HIGH-risk findings. Good test coverage.

---

### 7. `passes/extract.rs` -- Extract Pass

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `contiguous_mask_len` (1 test) | Pure function, no mock | **LOW** | Excellent edge case coverage (0, powers of 2 - 1, non-contiguous). | Keep. |
| Pattern scanning (8 tests) | Synthetic RSH+AND patterns | **LOW** | Tests widths 1, 8, 16, 32, shift=0, out-of-range shift+width. Good. | Keep. |
| Pass execution (10 tests) | Synthetic programs + mock btf_id | **LOW** | Tests kfunc emission, caller-saved conflict, branch fixup, dst=r0 optimization. Good. | Keep. |

No HIGH-risk findings. Good test coverage.

---

### 8. `passes/branch_flip.rs` -- Branch Flip (PGO) Pass

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| Diamond detection (2 tests) | Synthetic Jcc+JA diamond patterns | **LOW** | Tests symmetric and asymmetric diamonds. Good. | Keep. |
| PGO-gated flip (10 tests) | Synthetic programs + injected BranchProfile | **MEDIUM** | All PGO data is synthetic (fixed taken/not_taken counts). The tests verify that the pass correctly uses the min_bias threshold and PMU miss rate. However, they don't test the *source* of PGO data (the profiler module). If the profiler produces data in a different format than expected, these tests would still pass. | Add integration test that uses `collect_program_profiling` -> pass pipeline. |
| PMU threshold tests (3 tests) | Synthetic branch_miss_rate values | **LOW** | Tests the high/low/absent miss rate logic. Good. | Keep. |
| JCC inversion (1 test) | Pure function roundtrip | **LOW** | Tests all 10 JCC opcode pairs. Good. | Keep. |

**MEDIUM risk**: PGO tests use synthetic profiling data. This is acceptable for unit testing, but there should be an integration test that connects the profiler to the pass pipeline.

---

### 9. `passes/spectre.rs` -- Speculation Barrier Pass

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| Barrier insertion (15+ tests) | Synthetic programs + mock btf_id | **LOW** | Extensive: all JCC opcodes, chained branches, LDIMM64 handling, idempotency, branch fixup, JMP32 variant, realistic Spectre v1 pattern. | Keep. |

No HIGH-risk findings. Excellent test coverage.

---

### 10. `passes/wide_mem.rs` -- Wide Memory Pass

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| Pattern matching | Synthetic byte-ladder patterns | **MEDIUM** | Tests variant A (low-byte-first) and variant B (high-byte-first) for widths 2-8. However, the patterns are hand-constructed. Real clang output may have subtle differences (e.g., register allocation choices, intervening instructions). | Add a test that compiles a real C program with clang, extracts the bytecode, and verifies `scan_wide_mem` finds the expected sites. |
| Emission | Synthetic programs | **LOW** | Tests the `emit_ldx_wide` replacement. | Keep. |

---

### 11. `passes/utils.rs` -- Shared Utilities

| Test Name | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `test_fixup_all_branches_forward_jump` | Synthetic 3-insn program + addr_map | **LOW** | Tests basic branch fixup. | Keep. |
| `test_emit_kfunc_call_basic` | Pure function, no mock | **LOW** | Good. | Keep. |
| `test_emit_kfunc_call_dst_is_r0` | Pure function | **LOW** | Tests r0 optimization. Good. | Keep. |
| `test_emit_kfunc_call_swap_safe` | Pure function | **LOW** | Tests cycle-breaking via r0 scratch. Good. | Keep. |
| `test_emit_kfunc_call_no_redundant_mov` | Pure function | **LOW** | Tests identity-mov elimination. Good. | Keep. |
| `test_insn_iter_*` | Pure iterator logic | **LOW** | Good. | Keep. |

No HIGH-risk findings.

---

### 12. `insn.rs` -- BPF Instruction Encoding

| Test Name | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `test_bpf_insn_encoding` | Pure construction/accessors | **LOW** | Tests all constructors and field accessors. Good. | Keep. |
| `test_struct_size` | Compile-time check | **LOW** | Verifies `sizeof(BpfInsn) == 8`. Good. | Keep. |
| `test_make_regs_roundtrip` | Exhaustive 16x16 roundtrip | **LOW** | Excellent -- tests all 256 combinations. This test would have caught the bug #2 if `relocate_map_fds` had used the `dst_reg()`/`src_reg()` accessors instead of inline bit extraction. | Keep. |
| `test_cond_jmp_classification` | Synthetic instructions | **LOW** | Tests JMP and JMP32 classification. Good. | Keep. |

No HIGH-risk findings. The `test_make_regs_roundtrip` test is a model for how register encoding should be tested.

---

### 13. `verifier_log.rs` -- Verifier Log Parser

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `parses_real_style_branch_and_insn_states` | Real-style verifier log text | **LOW** | Uses realistic log format. Tests reg type parsing, offset extraction, scalar bounds. | Keep. |
| `parses_constants_and_repeated_bounds_from_real_messages` | Real-style verifier log text | **LOW** | Tests constant folding patterns. Good. | Keep. |
| `ignores_non_state_lines` | Verifier output with no state info | **LOW** | Negative case. Good. | Keep. |
| `parse_verifier_rejection_from_rejit_error` | Simulated REJIT error message | **LOW** | Tests the exact string parsing logic used by `cmd_apply`. Good. | Keep. |
| `extract_failure_pc_*` (4 tests) | Simulated verifier error logs | **LOW** | Tests type mismatch, invalid insn, fallback, empty log, jump out of range. Good. | Keep. |

No HIGH-risk findings. The verifier log parser tests use realistic log formats.

---

### 14. `profiler.rs` -- Runtime Profiler

| Test Area | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `delta_uses_monotonic_counter_difference` | Hand-built ProgStatsSnapshot | **LOW** | Tests pure math. Good. | Keep. |
| `delta_saturates_if_counters_go_backwards` | Hand-built snapshots with counter regression | **LOW** | Tests saturating_sub. Good. | Keep. |
| `pgo_analysis_*` (3 tests) | Hand-built deltas | **LOW** | Tests hotness score, is_hot predicate. Good. | Keep. |
| `hotness_ranking_orders_by_activity` | Hand-built analyses | **LOW** | Tests sorting. Good. | Keep. |
| `profiling_data_from_pgo_analysis` | Hand-built data | **LOW** | Tests struct construction. Good. | Keep. |
| `pmu_open_returns_some_or_none_gracefully` | Real perf_event_open | **LOW** | Tests graceful fallback when PMU is absent. Good. | Keep. |
| `perf_event_attr_layout_is_correct` | Pure layout check | **LOW** | Verifies PerfEventAttr fields. Good. | Keep. |

No HIGH-risk findings. The profiler tests use hand-built snapshots, which is appropriate since the actual BPF stats polling requires a running program.

---

### 15. `commands.rs` -- Subcommand Implementations

| Test Name | Mocks What | Risk | Why Dangerous | Recommendation |
|-----------|-----------|------|---------------|----------------|
| `test_optimize_one_result_serialization` | Hand-built OptimizeOneResult struct | **LOW** | Tests JSON serialization format. Good for API stability. | Keep. |
| `test_optimize_one_result_with_rollback` | Hand-built struct with rollback history | **LOW** | Tests serialization with rollback attempts. Good. | Keep. |
| `test_pass_detail_from_pass_result` | Hand-built PassResult | **LOW** | Tests conversion logic. Good. | Keep. |

**HIGH-risk gap in `commands.rs`**: There are **zero** tests for `cmd_apply`, `cmd_enumerate`, `cmd_rewrite`, `cmd_apply_all`, or `try_apply_one`. These are the core functions that orchestrate the entire REJIT pipeline (fetch program -> run passes -> relocate map FDs -> call BPF_PROG_REJIT). All tests only exercise JSON serialization structures.

The entire REJIT flow -- `bpf_prog_get_fd_by_id` -> `bpf_prog_get_info` -> `relocate_map_fds` -> `bpf_prog_rejit` -- is tested only by the `#[ignore]` smoke tests in `bpf.rs` and the VM integration tests. There is no mock-level test that verifies the orchestration logic (e.g., the rollback loop, disabled passes propagation, profiling injection).

---

## HIGH-Risk Summary Table

| # | File | What's Missing | Risk | Impact if Bug Ships | Recommendation |
|---|------|---------------|------|-------------------|----------------|
| 1 | `bpf.rs` | `BpfProgInfo` field-by-field layout verification against kernel header | **HIGH** | Silent data corruption in all fields after any kernel struct change. Could cause wrong program names, wrong insn counts, wrong map IDs, wrong BTF IDs. | Add test that parses `struct bpf_prog_info` from kernel header and verifies field offsets. |
| 2 | `bpf.rs` | No test for `relocate_map_fds` full path (open map FDs, patch, return) | **HIGH** | Map FD relocation could fail silently, causing REJIT to pass with stale/wrong map FDs. Programs would run with wrong map data. | Add `#[ignore]` VM test: load program with maps, call relocate_map_fds, verify patched FDs are valid. |
| 3 | `commands.rs` | No unit/integration test for `cmd_apply` / `try_apply_one` orchestration | **HIGH** | The rollback logic, disabled passes propagation, map FD relocation ordering, fd_array construction -- all untested except in full VM runs. Any bug in the orchestration (e.g., wrong order of operations) would only be caught by running `make vm-micro`. | Add a mock-based test for `try_apply_one` that uses a trait-abstracted BPF interface to verify the orchestration without real syscalls. Or add targeted `#[ignore]` tests for specific sub-flows. |
| 4 | `kfunc_discovery.rs` | `BTF_KIND_*` constants hardcoded in test, not parsed from kernel header | **HIGH** | If kernel changes BTF kind values (unlikely but possible), both constants and tests would be wrong together. | Parse `vendor/linux-framework/include/uapi/linux/btf.h` to verify BTF kind constants. |
| 5 | `bpf.rs` | `BtfInfo` struct layout not verified against kernel header | **HIGH** | `BtfInfo` is used to get BTF object names for module discovery. Wrong layout would silently return garbage names, causing kfunc discovery to fail (no module match). | Add field-offset test for `BtfInfo` (btf, btf_size, id, name, name_len, kernel_btf). |
| 6 | All passes | No test uses real compiled BPF program bytecode | **HIGH** | All pass tests use hand-constructed instruction sequences. Real clang output may have patterns that trigger edge cases in pattern matching (e.g., different register allocation, extra NOPs from alignment, BPF-to-BPF calls). | Extract bytecode from at least one real benchmark program (e.g., `micro/programs/rotate_rol8.bpf.o`) and add a test that runs the full pass pipeline on it. |

---

## MEDIUM-Risk Summary Table

| # | File | Test Area | Risk | Recommendation |
|---|------|-----------|------|----------------|
| 1 | `bpf.rs` | `BpfProgInfo` size check uses loose bounds (>= 216, <= 512) | **MEDIUM** | Tighten to exact expected size or parse from kernel header. |
| 2 | `bpf.rs` | `orig_prog_len`/`orig_prog_insns` offset check uses relative ordering only | **MEDIUM** | Verify absolute offsets against kernel struct definition. |
| 3 | `kfunc_discovery.rs` | `test_find_func_in_real_vmlinux_btf` doesn't assert result | **MEDIUM** | Change `let _ = result` to `assert!(result.is_some())` for a known function. |
| 4 | `passes/branch_flip.rs` | PGO data is entirely synthetic; profiler -> pass integration untested | **MEDIUM** | Add integration test using real profiling. |
| 5 | `passes/wide_mem.rs` | Byte-ladder patterns are hand-constructed, not from real clang output | **MEDIUM** | Test with real compiled program. |
| 6 | `passes/rotate.rs` | All patterns hand-constructed, never tested against real program | **MEDIUM** | Test with real compiled program. |
| 7 | `passes/endian.rs` | All patterns hand-constructed | **MEDIUM** | Test with real compiled program. |
| 8 | `passes/extract.rs` | All patterns hand-constructed | **MEDIUM** | Test with real compiled program. |

---

## Specific Recommendations (Priority Order)

### P0: Must-fix (could hide data-corruption bugs)

1. **Add `BpfProgInfo` field-offset test** (`bpf.rs`): Parse `struct bpf_prog_info` from `vendor/linux-framework/include/uapi/linux/bpf.h` and verify offsets of at least: `prog_type` (offset 0), `id` (offset 4), `xlated_prog_len` (offset 12), `nr_map_ids` (offset 36), `map_ids` (offset 40), `name` (offset 48), `btf_id` (offset 112), `orig_prog_len` (offset 224), `orig_prog_insns` (offset 228).

2. **Add `BtfInfo` field-offset test** (`bpf.rs`): Verify `btf` at 0, `btf_size` at 8, `id` at 12, `name` at 16, `name_len` at 24, `kernel_btf` at 28.

3. **Parse BTF_KIND constants from kernel header** (`kfunc_discovery.rs`): Replace hardcoded assertions with values parsed from `vendor/linux-framework/include/uapi/linux/btf.h`.

### P1: Should-fix (would catch real bugs faster)

4. **Add real-bytecode pass pipeline test**: Load a `.bpf.o` file (e.g., `micro/build/programs/rotate_rol8.bpf.o`), extract instructions via ELF parsing, run the full pass pipeline, and verify the output is structurally valid (correct EXIT, no dangling branches, correct instruction count change).

5. **Ensure `#[ignore]` tests run in VM CI**: The `bpf.rs` and `kfunc_discovery.rs` `#[ignore]` tests are the most valuable integration tests. Add a `make vm-daemon-test` target that runs `cargo test -- --ignored` inside the VM.

6. **Add `relocate_map_fds` integration test** (ignored): Load a real BPF program with maps, call the full relocation path, verify the patched FDs are valid by reading back the map info.

### P2: Nice-to-have

7. **Add `try_apply_one` orchestration test**: Use trait abstraction or conditional compilation to inject a mock BPF interface that validates the call sequence (get_info -> relocate_map_fds -> rejit) without requiring real syscalls.

8. **Strengthen `test_find_func_in_real_vmlinux_btf`**: Assert `result.is_some()` instead of `let _ = result`.

9. **Add more BTF kind variants to `test_find_func_in_mixed_btf`**: Include ENUM, VAR, DATASEC, ENUM64 to exercise all skip-size branches.

---

## What the Tests Do Well

- **Register alias safety** (`cond_select.rs`): The exhaustive 27-combination test and `simulate_param_setup` are excellent.
- **BPF cmd constant sync** (`bpf.rs`): Parsing the kernel header to verify constants is the gold standard for kernel interface testing.
- **Struct layout verification** (`bpf.rs`): AttrRejit field-offset test is a model. Extend this pattern to BpfProgInfo and BtfInfo.
- **Edge case coverage** (`extract.rs`): Width=1, width=32, shift=0, shift+width>64 are all covered.
- **Safety checks** (all passes): Interior branch target, caller-saved conflict, tmp_reg live-out are consistently tested across all passes.
- **Regression tests** (`bpf.rs`): Post-bug regression tests for both bug #1 and #2 are present and effective.
