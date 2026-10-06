# Dead Alias / libbpf Cleanup - 2026-05-09

Scope:
- Changed `bpfopt/crates/bpfopt/src/**`, plus `bpfopt/crates/bpfopt/tests/cli_pipeline.rs` for integration-test fallout from removing `BpfInsn` constructors.
- Did not edit `bpfopt/crates/bpfopt/src/passes/rewrite.rs`.
- Did not edit `vendor/linux-framework/`, `runner/`, `corpus/`, `e2e/`, or `micro/`.
- Did not touch fork-only daemon syscall wrappers.

## A. BpfInsn Constructor Removal

All listed `BpfInsn::*` convenience constructors were deleted from `insn.rs`. No constructor alias was retained, including the 30+ call-site constructors, because the direct `BpfInsn::new(...)` spelling was kept one-line at call sites and the source tree still had a net LOC reduction.

Call counts are from the requested pre-change `bpfopt/crates/bpfopt/src` grep. `mov64_reg` also had 3 integration-test uses in `tests/cli_pipeline.rs`, which were cleaned up after the constructor deletion surfaced them.

| Constructor | Calls in src | Extra integration calls | Replacement sample |
|---|---:|---:|---|
| `exit` | 308 | 0 | `BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)` |
| `mov64_imm` | 275 | 0 | `BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs(dst, 0), 0, imm)` |
| `ldx_mem` | 176 | 0 | `BpfInsn::new(BPF_LDX | size | BPF_MEM, BpfInsn::make_regs(dst, src), off, 0)` |
| `mov64_reg` | 168 | 3 | `BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_X, BpfInsn::make_regs(dst, src), 0, 0)` |
| `alu64_imm` | 130 | 0 | `BpfInsn::new(BPF_ALU64 | op | BPF_K, BpfInsn::make_regs(dst, 0), 0, imm)` |
| `helper_call` | 97 | 0 | `BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, helper_id)` |
| `st_mem` | 56 | 0 | `BpfInsn::new(BPF_ST | size | BPF_MEM, BpfInsn::make_regs(dst, 0), off, imm)` |
| `alu64_reg` | 56 | 0 | `BpfInsn::new(BPF_ALU64 | op | BPF_X, BpfInsn::make_regs(dst, src), 0, 0)` |
| `ja` | 46 | 0 | `BpfInsn::new(BPF_JMP | BPF_JA, 0, off, 0)` |
| `mov32_imm` | 44 | 0 | `BpfInsn::new(BPF_ALU | BPF_MOV | BPF_K, BpfInsn::make_regs(dst, 0), 0, imm)` |
| `stx_mem` | 23 | 0 | `BpfInsn::new(BPF_STX | size | BPF_MEM, BpfInsn::make_regs(dst, src), off, 0)` |
| `nop` | 22 | 0 | `BpfInsn::new(BPF_JMP | BPF_JA, 0, 0, 0)` |
| `mov32_reg` | 11 | 0 | `BpfInsn::new(BPF_ALU | BPF_MOV | BPF_X, BpfInsn::make_regs(dst, src), 0, 0)` |
| `kinsn_sidecar` | 3 | 0 | `BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs((payload & 0xf) as u8, BPF_PSEUDO_KINSN_SIDECAR), ((payload >> 4) & 0xffffu64) as u16 as i16, ((payload >> 20) & 0xffff_ffffu64) as u32 as i32)` |
| `call_kinsn_with_off` | 3 | 0 | `BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, BPF_PSEUDO_KINSN_CALL), off, btf_id)` |
| `jump_reg` | 2 | 0 | `BpfInsn::new(BPF_JMP | op | BPF_X, BpfInsn::make_regs(dst, src), off, 0)` |
| `jump_imm` | 2 | 0 | `BpfInsn::new(BPF_JMP | op | BPF_K, BpfInsn::make_regs(dst, 0), off, imm)` |
| `call_kfunc` | 2 | 0 | `BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, BPF_PSEUDO_KFUNC_CALL), 0, btf_id)` |
| `call_kfunc_with_off` | 0 | 0 | `BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, BPF_PSEUDO_KFUNC_CALL), off, btf_id)` |

Post-cleanup checks:
- `rg 'BpfInsn::(mov64_reg|mov32_reg|mov64_imm|mov32_imm|helper_call|ja|jump_imm|jump_reg|exit|ldx_mem|stx_mem|st_mem|alu64_imm|alu64_reg|nop|call_kfunc|call_kfunc_with_off|call_kinsn_with_off|kinsn_sidecar)\(' bpfopt/crates/bpfopt` returns no matches.

### Bulk-memory BTF IDs

Deleted:
- `const MEMCPY_BTF_ID: i32 = 4101;`
- `const MEMSET_BTF_ID: i32 = 4102;`

Replacement:
- `ctx_with_bulk_kfuncs()` now creates local non-negative IDs, injects them into `ctx.kinsn_registry.memcpy_bulk_btf_id` and `ctx.kinsn_registry.memset_bulk_btf_id`, and callers read the IDs back through `memcpy_btf_id()` / `memset_btf_id()`.
- Remaining `4101` / `4102` occurrences are local setup variables only.

Post-cleanup check:
- `rg 'const\s+\w*BTF\w*|const\s+\w*btf\w*|4101|4102' bpfopt/crates/bpfopt/src daemon/src` only reports the two local setup assignments in `bulk_memory_tests.rs`.

### Helper/prog wrappers

Deleted or replaced with direct libbpf references:
- `HELPER_MAP_LOOKUP_ELEM`
- `HELPER_XDP_ADJUST_HEAD`
- `BPF_FUNC_SKB_LOAD_BYTES`
- `BPF_FUNC_DUMMY_HELPER`
- local `helper_call()` wrapper in `skb_load_bytes_tests.rs`
- local `BPF_PROG_TYPE_*` aliases in `wide_mem`, `prefetch`, `bounds_check_merge`, `skb_load_bytes`, and their tests.

Post-cleanup check:
- `rg '\bHELPER_[A-Z0-9_]*|\bhelper_call\(' bpfopt/crates/bpfopt/src daemon/src` returns no matches.

## B. libbpf Alias Candidate Table

Classification:
- A: same-name, same-type zero-value alias. Deleted and call sites use `libbpf_sys::X`.
- B: type-conversion alias. Kept because call sites need `u8` while bindgen exposes wider integer constants.
- C: zero-value wrapper function. Deleted and call sites use `BpfInsn::new(...)` / direct libbpf IDs.
- D: dead or redundant local alias. Deleted.

| Candidate location | Candidate(s) | Class | Call sites | Disposition |
|---|---|---:|---:|---|
| `insn.rs:9-90` | BPF opcode/register/pseudo constants cast to `u8` | B | many | Kept. Required by `BpfInsn::new` code/register operands. |
| `pass.rs:433-434` | `BPF_PSEUDO_MAP_FD`, `BPF_PSEUDO_MAP_VALUE` cast to `u8` | B | 5 | Kept. Local verifier parsing needs `u8` pseudo tags. |
| `mock_maps.rs:28` | `BPF_MAP_TYPE_PERCPU_ARRAY` | A | 1 | Deleted; direct `libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY`. |
| `wide_mem.rs:423-435` | 7 packet prog-type aliases | A | 7 | Deleted; direct `libbpf_sys::BPF_PROG_TYPE_*`. |
| `prefetch.rs:20-33` | 2 helper aliases, 7 prog-type aliases | A/C | 9 | Deleted; direct `libbpf_sys::BPF_FUNC_* as i32` / `BPF_PROG_TYPE_*`. |
| `prefetch_tests.rs` | imported helper/prog aliases | A/C | 3 | Deleted by using direct libbpf constants in tests. |
| `bounds_check_merge.rs:14-26` | 7 packet prog-type aliases | A | 7 | Deleted; direct `libbpf_sys::BPF_PROG_TYPE_*`. |
| `bounds_check_merge_tests.rs:8-11` | socket/sched/xdp prog-type aliases | A | 21 | Deleted; direct `libbpf_sys::BPF_PROG_TYPE_*`. |
| `skb_load_bytes.rs:11-14` | helper ID alias, 2 prog-type aliases | A/C | 4 | Deleted; direct `libbpf_sys::*`. |
| `skb_load_bytes_tests.rs:8-13` | helper ID aliases, 3 prog-type aliases | A/C | 30 | Deleted; direct `libbpf_sys::*`; local `helper_call()` wrapper also deleted. |
| `mod_tests.rs:9-11` | 2 map-type aliases, duplicate pseudo-map alias | A/D | 4 | Deleted; direct libbpf map types and imported `crate::insn::BPF_PSEUDO_MAP_FD`. |
| `map_inline/map_info.rs:9-18,465-469` | map-type aliases | A | 31 | Deleted; direct `libbpf_sys::BPF_MAP_TYPE_*`. |
| `map_inline/map_info.rs:local pseudo aliases` | pseudo-map aliases via `crate::insn` | D | 18 | Deleted; direct `crate::insn::BPF_PSEUDO_*`. |
| `map_inline_tests.rs:19-25` | map-type aliases | A | 28 | Deleted; direct `libbpf_sys::BPF_MAP_TYPE_*`. |

Post-cleanup candidate grep:
- Only `insn.rs` and `pass.rs` `u8` conversion aliases remain.
- No matching alias candidates remain in `daemon/src`.

## LOC Delta

Task-start source line counts, before -> after:

| File | Before | After | Delta |
|---|---:|---:|---:|
| `bpfopt/crates/bpfopt/src/insn.rs` | 491 | 365 | -126 |
| `bpfopt/crates/bpfopt/src/mock_maps.rs` | 191 | 189 | -2 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs` | 550 | 535 | -15 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge_tests.rs` | 392 | 387 | -5 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs` | 548 | 526 | -22 |
| `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` | 584 | 566 | -18 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 3145 | 3137 | -8 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 294 | 290 | -4 |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs` | 838 | 827 | -11 |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs` | 346 | 341 | -5 |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes_tests.rs` | 358 | 348 | -10 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem.rs` | 673 | 656 | -17 |
| Total source files with line-count changes | 8410 | 8167 | -243 |

Integration-test update:
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs`: 3 constructor call-site rewrites, 0 line-count delta.

Required shortstat relative to `HEAD`:
- `git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src`
- Result: `36 files changed, 2060 insertions(+), 2244 deletions(-)`, net `-184`.

## Test Results

Required commands:
- `cd bpfopt && cargo build --workspace --locked`: passed.
- `cd bpfopt && cargo test --workspace --locked 2>&1 | tail -40`: passed.
- `cd daemon && cargo build --workspace --locked`: passed.
- `cd daemon && cargo test --workspace --locked 2>&1 | tail -20`: passed.

Test inventory from `cargo test --workspace --locked -- --list`:

| Suite | Tests |
|---|---:|
| `bpfopt` lib (`src/lib.rs`) | 332 |
| `bpfopt` bin unit tests (`src/main.rs`) | 12 |
| `bpfopt` CLI pipeline integration tests | 12 |
| `bpfopt` doc tests | 0 |
| `bpfrejit-daemon` unit tests | 25 |
| Total | 381 |

The total meets the Round A baseline requirement of at least 381 tests.

## CLAUDE.md Compliance Self-Check

- Use libbpf directly: same-type `libbpf_sys` aliases were removed and replaced with direct `libbpf_sys::X` references.
- Type conversion aliases: retained only where the code needs `u8` BPF instruction fields while bindgen exposes wider constants.
- No re-wrap: deleted `BpfInsn` convenience constructors and helper/prog/map aliases instead of recreating macro-style builders.
- No dead code: no new `#[allow(dead_code)]`; deleted the local zero-value `helper_call()` test wrapper.
- No silenced errors: `rg '#\[allow\(dead_code\)\]|unwrap_or_default\(|let _ =|\.ok\(\)' bpfopt/crates/bpfopt/src daemon/src` returns no matches.
- Daemon syscall boundary: no daemon syscall wrapper changes; fork-only commands untouched.
- Exclusions: `passes/rewrite.rs`, vendor, runner, corpus, e2e, and micro were not edited by this cleanup.
- No commit and no benchmark run.

## Remaining Items

None for this cleanup.

Kept intentionally:
- `insn.rs` BPF opcode/register/pseudo `u8` aliases.
- `pass.rs` pseudo-map `u8` aliases.

These are type-conversion aliases, not same-type zero-value wrappers.
