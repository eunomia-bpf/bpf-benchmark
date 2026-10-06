# Daemon Test Coverage Gap Analysis

Date: 2026-03-23

## 1. Current Test Inventory (before changes)

### A. Daemon Rust Unit Tests (`daemon/src/`)

All tests run via `cargo test` (no BPF/root required):

| Module | Test Count | What It Tests | Mock Level |
|--------|-----------|---------------|------------|
| `insn.rs` | 4 | BpfInsn encoding/decoding, struct size, regs roundtrip, jmp classification | Pure logic |
| `pass.rs` | ~12 | BpfProgram lifecycle, AnalysisCache, PassManager pipeline (NoOp/Append/Rewrite passes) | Pure logic with mock passes |
| `kfunc_discovery.rs` | 10 | BTF parsing (find_func_btf_id), split BTF, mixed kinds, BTF constants, discover_kfuncs smoke | **Mock BTF blobs** only; discover_kfuncs does hit `/sys/kernel/btf/` but only as smoke |
| `verifier_log.rs` | 4 | Verifier log parsing, register state extraction, failure PC extraction | Pure string parsing |
| `commands.rs` | 2 | OptimizeOneResult JSON serialization, rollback serialization | Pure data structure |
| `profiler.rs` | 6 | ProgStatsDelta, PgoAnalysis, hotness scoring, PMU struct layout, PMU graceful fallback | Pure logic (PMU test is graceful no-op without HW) |
| `passes/mod.rs` | 5 | Cross-pass integration (wide_mem+spectre), CFG/liveness/branch_target analysis, default pipeline | **Mock kfunc registry** (btf_id=-1 or hardcoded) |
| `passes/wide_mem.rs` | ~8 | WideMemPass pattern matching, 2/4/8 byte fusion, subprog boundary | Pure pattern matching |
| `passes/rotate.rs` | ~8 | RotatePass pattern matching, shift+or detection, kfunc gating | Mock kfunc BTF ID |
| `passes/cond_select.rs` | ~8 | CondSelectPass branch-over-mov detection, liveness check | Mock kfunc BTF ID |
| `passes/extract.rs` | ~6 | ExtractPass shift+mask detection | Mock kfunc BTF ID |
| `passes/endian.rs` | ~6 | EndianFusionPass byte-swap detection | Mock kfunc BTF ID |
| `passes/spectre.rs` | ~4 | SpectreMitigationPass barrier insertion after cond branches | Mock kfunc BTF ID |
| `passes/branch_flip.rs` | ~6 | BranchFlipPass PGO-guided branch flipping | Pure logic with mock annotations |
| `passes/utils.rs` | ~6 | fixup_all_branches, NOP squashing | Pure instruction manipulation |
| `analysis/cfg.rs` | ~4 | CFG construction, basic block detection, subprogram detection | Pure analysis |
| `analysis/liveness.rs` | ~3 | Liveness analysis across branches | Pure analysis |
| `analysis/branch_target.rs` | ~2 | Branch target detection | Pure analysis |
| `bpf.rs` | 5 | relocate_map_fds (src_reg vs dst_reg, pseudo map value, multiple refs) | Pure instruction manipulation |

**Total: ~108 unit tests**, all pure-logic or mock-based.

### B. Kernel-Side VM Tests (`tests/unittest/`)

All require BpfReJIT kernel + root, run via `make vm-test`:

| Test File | Test Count | What It Tests |
|-----------|-----------|---------------|
| `rejit_poc.c` | 6 | Basic REJIT: same-length, diff-length, fd_array, test_run correctness, info consistency, concurrent safety |
| `rejit_safety_tests.c` | 20 | 15 negative (invalid bytecode rejected) + 5 correctness (identity, semantic-preserving, rollback) |
| `rejit_prog_types.c` | 21 | REJIT across all major prog types (19 PASS, 2 SKIP) |
| `rejit_regression.c` | 4 | text_mutex deadlock, expedited RCU, kallsyms, XDP test_run |
| `rejit_spectre.c` | ~7 | NOP insertion after branches, offset fixup, repeated REJIT |
| `rejit_tail_call.c` | ~3 | Tail call programs with REJIT |
| `rejit_audit_tests.c` | ~5 | Audit/logging tests |

**Total: ~66 VM tests**, all C programs testing kernel REJIT syscall directly.

## 2. Identified Coverage Gaps

### Critical Gap 1: BPF Syscall Constants Never Validated Against Kernel
**Risk: HIGH** (this is exactly the bug that was found)

The `bpf.rs` constants (`BPF_PROG_GET_NEXT_ID=11`, `BPF_BTF_GET_NEXT_ID=23`, etc.) are hardcoded and never cross-checked against the kernel UAPI header enum. A typo or version mismatch silently breaks all operations using that constant.

**Status**: Fixed. Added `test_bpf_cmd_constants_match_kernel_header` which parses the kernel header and validates all 9 constants.

### Critical Gap 2: BTF/Kfunc Discovery Never Tested Against Real Kernel
**Risk: HIGH**

`discover_kfuncs()` -> `bpf_btf_get_next_id()` -> `bpf_btf_get_fd_by_id()` -> `bpf_btf_get_info_name()` -> `bpf_btf_get_fd_by_module_name()` -- this entire chain uses BPF syscalls but is only tested with synthetic BTF blobs.

**Status**: Fixed. Added 3 `#[ignore]` tests in `kfunc_discovery.rs` that exercise the real BTF syscall chain when a BPF kernel is available.

### Critical Gap 3: Struct Layout Unverified
**Risk: MEDIUM**

`AttrRejit`, `BtfInfo`, `BpfProgInfo` layout never tested for correctness.

**Status**: Fixed. Added field offset and size tests. Also fixed a latent bug: `AttrRejit._pad` was `128-44` (should be `128-48`), making the struct 136 bytes instead of 128.

### Critical Gap 4: No Smoke Tests for BPF Syscall Wrappers
**Risk: MEDIUM**

`iter_prog_ids()`, `bpf_prog_get_next_id()`, `bpf_btf_get_next_id()` never tested.

**Status**: Fixed. Added 7 `#[ignore]` smoke tests that validate BPF syscall wrappers work against a real kernel.

## 3. Tests Added

### A. `daemon/src/bpf.rs` -- 16 new tests (9 pure + 7 ignored)

**Pure tests (always run):**
1. `test_bpf_cmd_constants_match_kernel_header` -- Parses `enum bpf_cmd` from kernel header, validates all 9 constants
2. `test_attr_struct_sizes_fit_bpf_attr` -- All 4 attr structs are exactly 128 bytes
3. `test_attr_rejit_field_offsets` -- 9 field offsets in AttrRejit match kernel layout
4. `test_bpf_prog_info_size` -- BpfProgInfo size sanity check
5. `test_bpf_prog_info_orig_fields_at_end` -- orig_prog_len/insns are at end
6. `test_bpf_prog_info_name_str` -- name extraction (empty, normal, full-length)
7. `test_btf_info_struct_size` -- BtfInfo is exactly 128 bytes
8. `test_relocate_map_fds_with_non_map_instructions` -- No LD_IMM64 instructions
9. `test_relocate_map_fds_empty_program` -- Empty instruction stream

**BPF runtime tests (need root, `#[ignore]`):**
10. `test_bpf_prog_get_next_id_smoke`
11. `test_iter_prog_ids_returns_some`
12. `test_bpf_prog_get_fd_and_info_smoke`
13. `test_btf_get_next_id_smoke`
14. `test_btf_get_fd_by_id_and_info_smoke`
15. `test_btf_module_enumeration`
16. `test_bpf_btf_get_fd_by_module_name_vmlinux_not_found`

### B. `daemon/src/kfunc_discovery.rs` -- 3 new tests (all ignored)

**BPF runtime tests (need root/BTF, `#[ignore]`):**
1. `test_get_vmlinux_str_len_real` -- Validates vmlinux BTF string section on real kernel
2. `test_find_func_in_real_vmlinux_btf` -- Parses real vmlinux BTF without panic
3. `test_discover_kfuncs_real` -- Full discovery pipeline against real kernel

### C. Bug Fix

**`AttrRejit._pad` size**: Changed from `128 - 44` to `128 - 48`. The fields before `_pad` total 48 bytes (not 44), so the old padding made the struct 136 bytes instead of 128. The kernel accepts oversized attr as long as extra bytes are zero, so this was not causing runtime failures, but it was technically incorrect and passing a 136-byte struct to the syscall.

## 4. Test Results

```
cargo test: 265 passed, 0 failed, 10 ignored
```

All 10 ignored tests are `#[ignore]` BPF runtime tests that need `cargo test -- --ignored` inside a BPF-enabled VM.

## 5. How to Run Ignored Tests

Inside a VM with BPF (e.g., via `make vm-test` environment):
```bash
# Run all ignored (BPF runtime) tests
cargo test --manifest-path daemon/Cargo.toml -- --ignored

# Or run specific ignored tests
cargo test --manifest-path daemon/Cargo.toml -- --ignored test_bpf_prog_get_next_id_smoke
cargo test --manifest-path daemon/Cargo.toml -- --ignored test_discover_kfuncs_real
```

## 6. Remaining Gaps (not addressed in this round)

1. **End-to-end REJIT with daemon passes**: No test loads a real BPF program, runs daemon passes, calls REJIT, and verifies execution correctness. The VM unittest tests only test raw REJIT syscall, not the daemon's pass pipeline.

2. **Map FD relocation end-to-end**: `relocate_map_fds` is only tested with synthetic instructions. No test creates a real BPF program with maps and validates the relocation.

3. **kinsn pass integration**: No automated test loads kinsn modules -> daemon discovers kfuncs -> applies passes -> REJIT with kfunc calls -> verifies correctness. This is covered by `make vm-micro` benchmarks but not by a dedicated correctness test.
