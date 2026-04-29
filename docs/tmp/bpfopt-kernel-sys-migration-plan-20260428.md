# bpfopt kernel-sys type/constant migration plan

Date: 2026-04-28

Scope: read-only assessment plus this report. No source code or v3 design document was modified.

## Executive summary

Recommendation: choose **方案 B：thin transparent wrapper** as the first real migration step.

方案 A fully replaces `bpfopt::insn::BpfInsn` with `kernel_sys::bpf_insn`, but it turns a pass-friendly Rust IR into a bindgen FFI struct and forces broad pass/test churn. 方案 C is the smallest patch, but it leaves the bpfopt library's own instruction type and numeric constants in place, so it only partially satisfies the "use libbpf-rs/libbpf-sys whenever possible" preference.

方案 B gives the best balance: use `kernel_sys::bpf_insn` as the stored ABI object, keep bpfopt's ergonomic helpers on top, and centralize UAPI constants through `kernel-sys`. It should also flush out existing drift in local program-type constants, notably `BPF_PROG_TYPE_LWT_{IN,OUT,XMIT}`.

## Current inventory

### kernel-sys status

`kernel-sys` already re-exports the relevant upstream data surface:

- [bpfopt/crates/kernel-sys/src/lib.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/kernel-sys/src/lib.rs:12): `pub use libbpf_rs::{..., ProgramType};`
- [bpfopt/crates/kernel-sys/src/lib.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/kernel-sys/src/lib.rs:15): `pub use libbpf_sys::*;`
- `bpfopt` currently has no `kernel-sys` dependency in [bpfopt/crates/bpfopt/Cargo.toml](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/Cargo.toml:11).

The only direct `libc::syscall(SYS_bpf, ...)` found in the bpfopt workspace is inside [bpfopt/crates/kernel-sys/src/lib.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/kernel-sys/src/lib.rs:139), which is allowed for fork-only commands. `bpfopt/crates/bpfopt/src` has no direct syscall use.

### bpfopt BpfInsn

`bpfopt::insn::BpfInsn` is defined in [bpfopt/crates/bpfopt/src/insn.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/insn.rs:96). The file is 625 lines.

Current shape:

```rust
#[repr(C)]
pub struct BpfInsn {
    pub code: u8,
    pub regs: u8, // dst_reg:4 | src_reg:4
    pub off: i16,
    pub imm: i32,
}
```

It has:

- public scalar fields: `code`, `regs`, `off`, `imm`
- methods: `dst_reg()`, `src_reg()`, `make_regs()`, `raw_bytes()`, `class()`, classification helpers
- constructors: `mov64_reg`, `mov64_imm`, `mov32_imm`, `call_kinsn_with_off`, `ja`, `ldx_mem`, `kinsn_sidecar`, `stx_mem`, `alu64_imm`, `alu64_reg`, `nop`
- dump/debug helpers in the same file
- only a size assertion: `size_of::<BpfInsn>() == 8`; no field-offset test

Current byte parsing and serialization are manual:

- [bpfopt/crates/bpfopt/src/elf_parser.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/elf_parser.rs:458) parses 8-byte chunks into `BpfInsn` with explicit little-endian `off`/`imm`.
- [bpfopt/crates/bpfopt/src/insn.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/insn.rs:128) serializes with explicit little-endian `raw_bytes()`.

### libbpf_sys::bpf_insn layout

The generated libbpf-sys 1.7.0 binding has:

```rust
#[repr(C)]
pub struct bpf_insn {
    pub code: __u8,
    pub _bitfield_align_1: [u8; 0],
    pub _bitfield_1: __BindgenBitfieldUnit<[u8; 1usize]>,
    pub off: __s16,
    pub imm: __s32,
}
```

It also provides `dst_reg()`, `set_dst_reg()`, `src_reg()`, `set_src_reg()`, and `new_bitfield_1(dst, src)`. The upstream UAPI header defines the byte layout as `code` at offset 0, 4-bit `dst_reg` plus 4-bit `src_reg` at byte 1, `off` at offset 2, and `imm` at offset 4. The binding comes from that UAPI struct, so it is the authoritative layout source. The migration should still add a bpfopt/kernel-sys ABI test for size, offsets, and raw byte round trip because the current bpfopt test only checks size.

### bpfopt constants

Instruction constants currently live primarily in [bpfopt/crates/bpfopt/src/insn.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/insn.rs:8):

- classes: `BPF_LD`, `BPF_LDX`, `BPF_ST`, `BPF_STX`, `BPF_ALU`, `BPF_JMP`, `BPF_JMP32`, `BPF_ALU64`
- sizes/modes/sources: `BPF_W`, `BPF_H`, `BPF_B`, `BPF_DW`, `BPF_IMM`, `BPF_MEM`, `BPF_K`, `BPF_X`
- ops: `BPF_AND`, `BPF_OR`, `BPF_LSH`, `BPF_RSH`, `BPF_MOV`
- jumps/calls: `BPF_JA`, `BPF_JEQ`, `BPF_JGT`, `BPF_JGE`, `BPF_JSET`, `BPF_JNE`, `BPF_JLT`, `BPF_JLE`, `BPF_JSGT`, `BPF_JSGE`, `BPF_JSLT`, `BPF_JSLE`, `BPF_CALL`, `BPF_EXIT`
- pseudo tags: `BPF_PSEUDO_CALL`, `BPF_PSEUDO_KFUNC_CALL`, `BPF_PSEUDO_FUNC`
- project/fork-specific tags: `BPF_PSEUDO_KINSN_SIDECAR`, `BPF_PSEUDO_KINSN_CALL`, `BPF_KINSN_ENC_PACKED_CALL`

Other local constants exist in pass modules:

- ALU ops not in `insn.rs`: `BPF_ADD`, `BPF_SUB`, `BPF_MUL`, `BPF_DIV`, `BPF_XOR`, `BPF_MOD`, `BPF_ARSH`, `BPF_NEG`
- endian ops: `BPF_END`, `BPF_TO_BE`
- pseudo map tags: `BPF_PSEUDO_MAP_FD`, `BPF_PSEUDO_MAP_VALUE`
- helper/map-type constants in tests and map analysis

`BPF_REG_0..10` are not used or defined in `bpfopt/crates/bpfopt/src` today. `libbpf-sys` does expose them.

### helper macro functions

`bpfopt::insn` defines function equivalents for UAPI macros:

- `bpf_class(code) = code & 0x07`
- `bpf_size(code) = code & 0x18`
- `bpf_mode(code) = code & 0xe0`
- `bpf_op(code) = code & 0xf0`
- `bpf_src(code) = code & 0x08`

The C macros exist in `linux/bpf_common.h`, but bindgen/libbpf-sys does not expose function-like macros such as `BPF_CLASS`, `BPF_SIZE`, `BPF_MODE`, `BPF_OP`, or `BPF_SRC`. Keeping small Rust helper functions, or moving them into `kernel-sys`, is unavoidable unless the project uses `libc`'s Linux helpers. I would keep them in bpfopt for the thin-wrapper migration and explicitly derive their masks from UAPI macro semantics.

### Program type constants

There is no bpfopt program-type enum. Current code uses raw `u32`:

- [bpfopt/crates/bpfopt/src/pass.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/pass.rs:587): `PassContext::prog_type: u32`
- [bpfopt/crates/bpfopt/src/elf_parser.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/elf_parser.rs:23): local `BPF_PROG_TYPE_*` constants and section-name inference
- [bpfopt/crates/bpfopt/src/passes/wide_mem.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/wide_mem.rs:323), [bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:16), and [bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:17): local pass-specific constants

Important drift found:

| Constant | bpfopt local value | libbpf-sys value |
| --- | ---: | ---: |
| `BPF_PROG_TYPE_LWT_IN` | 18 | 10 |
| `BPF_PROG_TYPE_LWT_OUT` | 19 | 11 |
| `BPF_PROG_TYPE_LWT_XMIT` | 20 | 12 |

The local values 18/19/20 correspond to different modern UAPI entries (`CGROUP_SOCK_ADDR`, `LWT_SEG6LOCAL`, `LIRC_MODE2`). Migrating program-type constants to `kernel_sys::BPF_PROG_TYPE_*` should be treated as a correctness fix, not just cleanup.

## Reference counts

Commands were run against `bpfopt/crates/bpfopt/src`.

| Pattern | Count |
| --- | ---: |
| `rg -n "\bBpfInsn\b" ...` matching lines | 1,722 |
| `rg -o "\bBpfInsn\b" ...` occurrences | 1,742 |
| files containing `BpfInsn` | 27 |
| `rg -n "BPF_LD\|BPF_ALU64\|BPF_REG_" ...`-style UAPI constant matching lines | 1,193 |
| UAPI constant occurrences with the broader inventory regex | 1,534 |
| files containing those constants | 28 |
| `BPF_REG_` matches | 0 |
| `BpfInsn {` direct/literal matches, including definitions/debug strings | 155 |

High-count `BpfInsn` users:

| File | Occurrences |
| --- | ---: |
| `passes/map_inline_tests.rs` | 356 |
| `passes/wide_mem_tests.rs` | 193 |
| `passes/const_prop.rs` | 124 |
| `passes/skb_load_bytes.rs` | 110 |
| `passes/rotate.rs` | 97 |
| `passes/cond_select_tests.rs` | 90 |
| `passes/bounds_check_merge.rs` | 82 |
| `passes/branch_flip.rs` | 82 |

Field/method surface is also broad:

| Pattern | Matching lines |
| --- | ---: |
| `.code` | 145 |
| `.regs` | 33 |
| `.off` | 109 |
| `.imm` | 139 |
| `dst_reg(` | 139 |
| `src_reg(` | 135 |
| `make_regs` | 77 |
| direct field mutations, excluding `==` comparisons | 18 |

This means any approach that removes public fields has real but bounded churn. Any approach that removes the `BpfInsn` name entirely has broad churn across pass logic and tests.

## Option comparison

| Option | What changes | Estimated source churn | Risk | Preference fit |
| --- | --- | ---: | --- | --- |
| A. Full replacement | Delete bpfopt `BpfInsn`; use `kernel_sys::bpf_insn` everywhere; update constructors, pass code, tests, constants, dumps | roughly 1.5k-3k changed lines across most of the 27 `BpfInsn` files | High: bindgen bitfield ergonomics leak everywhere; constants are `u32` while `code` is `u8`; many tests need literal rewrites | Strongest on "no own type", weakest on engineering stability |
| B. Thin wrapper | Store `kernel_sys::bpf_insn` inside `bpfopt::insn::BpfInsn`; expose bpfopt methods/constructors; alias constants from `kernel_sys`; migrate field access to methods where needed | roughly 400-900 changed lines, mostly `insn.rs`, direct field accesses, literal constructors, prog_type constants | Medium: bitfield setters/getters, constructor `const fn` compatibility, slice casting tests | Best balance: upstream ABI type internally, ergonomic bpfopt API externally |
| C. Boundary conversion | Keep current `BpfInsn`; convert to/from `kernel_sys::bpf_insn` at CLI/stdin/stdout or ELF boundaries | roughly 50-150 changed lines once a raw bytecode CLI exists; almost no pass/test churn | Low short-term, but dual representations can drift | Partial only; own type/constants remain, so it does not fully satisfy the preference |

## Option A details

Implementation shape:

- Add `kernel-sys` as a path dependency to `bpfopt`.
- Replace `BpfProgram.insns: Vec<BpfInsn>` with `Vec<kernel_sys::bpf_insn>` or a type alias.
- Replace all constructors with helper functions returning `bpf_insn`.
- Replace direct `.regs` usage with `dst_reg()/src_reg()/set_*`.
- Replace current `u8` constants with casts from `kernel_sys::*`, because libbpf-sys constants are mostly `u32`.
- Rewrite byte dumps and tests to handle bindgen bitfield storage.

Risks:

- `bpf_insn` has no `.regs` field; direct struct literals require `_bitfield_align_1` and `_bitfield_1`, which is noisy and easy to get wrong.
- The generated `new_bitfield_1()` helper is not `const fn`. Existing bpfopt constructors are `const fn`; callers do not appear to require const contexts, but the public API changes.
- Tests that currently assert against simple `BpfInsn { code, regs, off, imm }` literals need mechanical rewrites.
- Pass code becomes less readable: bytecode transformation logic would carry FFI/bindgen details.

Could tests pass? Yes, but only after a broad update. This is not a minimum-change path.

## Option B details

Implementation shape:

```rust
#[repr(transparent)]
pub struct BpfInsn(kernel_sys::bpf_insn);
```

Keep bpfopt's semantic API:

- `code()`, `set_code()`
- `regs()`, `set_regs()`
- `dst_reg()`, `set_dst_reg()`
- `src_reg()`, `set_src_reg()`
- `off()`, `set_off()`
- `imm()`, `set_imm()`
- constructors such as `mov64_reg`, `ja`, `ldx_mem`
- `raw_bytes()` and bytecode dump helpers
- `as_kernel()` / `from_kernel()` helpers and slice conversions where needed

The current public fields cannot be preserved with a transparent newtype. That is the main migration work: update `.code`, `.regs`, `.off`, `.imm` callers to method accessors or focused mutators. This is still much smaller than replacing the type name everywhere.

Constant migration under B:

- Replace local numeric instruction constants with aliases derived from `kernel_sys::*`, for example `pub const BPF_LD: u8 = kernel_sys::BPF_LD as u8;`.
- Keep only project/fork-specific constants that libbpf-sys does not provide, such as `BPF_PSEUDO_KINSN_SIDECAR`, `BPF_PSEUDO_KINSN_CALL`, and `BPF_KINSN_ENC_PACKED_CALL`.
- Keep helper functions for `BPF_CLASS`/`BPF_SIZE`/`BPF_MODE`/`BPF_OP`/`BPF_SRC` because libbpf-sys does not expose function-like macros.
- Replace local `BPF_PROG_TYPE_*` constants with `kernel_sys::BPF_PROG_TYPE_*` or `kernel_sys::ProgramType as u32`. The lower-churn first step is still `u32` because `PassContext::prog_type` is `u32`.

Why this fits:

- bpfopt still owns an IR wrapper, but it no longer owns the ABI layout.
- Passes keep a readable Rust API.
- UAPI byte layout can be proven with tests on the wrapper.
- It avoids leaking `_bitfield_1` into pass code.

## Option C details

Implementation shape:

- Keep current `BpfInsn` unchanged.
- Add conversions:
  - `impl From<kernel_sys::bpf_insn> for BpfInsn`
  - `impl From<BpfInsn> for kernel_sys::bpf_insn`
- Use conversions at CLI stdin/stdout or object parsing boundaries.

Issue: the current `bpfopt` CLI only supports `list-passes` in [bpfopt/crates/bpfopt/src/main.rs](/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src/main.rs:14). There is not yet an optimize subcommand that reads raw bytecode from stdin and writes raw bytecode to stdout. So a pure CLI-boundary conversion has little immediate effect unless the migration also touches the ELF parser/test boundary.

Preference fit: partial at best. It uses libbpf-sys at the edge, but bpfopt's library continues to define and operate on its own ABI-shaped instruction struct and local numeric constants. It also would not fix the local program-type drift unless that is handled separately.

## Testing impact

方案 A:

- Many test fixtures and helper constructors need updates.
- Requires full `cargo test -p bpfopt` plus kernel-sys tests.
- High chance of incidental failures from bitfield construction or constant cast mistakes.

方案 B:

- Existing pass behavior should remain intact if the wrapper preserves methods and constructors.
- Tests need updates where they access public fields or construct struct literals.
- Add targeted ABI tests:
  - `size_of::<BpfInsn>() == size_of::<kernel_sys::bpf_insn>() == 8`
  - offsets for `code`, `off`, `imm`
  - raw byte round trip for `code`, packed regs, `off`, `imm`
  - `dst_reg`/`src_reg` set/get round trip
  - `LD_IMM64` two-slot raw encoding round trip
- Then run `cargo test -p bpfopt` and `cargo test -p kernel-sys`.

方案 C:

- Existing tests mostly unchanged.
- Add conversion round-trip tests.
- Does not exercise pass logic on the upstream ABI type, so it gives weaker confidence for the stated migration goal.

## Kernel UAPI compatibility

All three options can preserve the 8-byte instruction encoding if implemented carefully:

- Option A relies directly on `libbpf_sys::bpf_insn`, so it is closest to UAPI.
- Option B relies directly on `libbpf_sys::bpf_insn` internally and is also close to UAPI, provided the wrapper has layout tests.
- Option C keeps the current manual struct internally; correctness depends on conversion functions and current explicit little-endian serialization.

Current bpfopt compatibility:

- `#[repr(C)]` plus `u8, u8, i16, i32` strongly implies the intended 8-byte layout on supported targets.
- The code explicitly serializes `off` and `imm` as little-endian bytes.
- It only asserts size, not offsets. This is weaker than a tested wrapper around `libbpf_sys::bpf_insn`.

libbpf-sys compatibility:

- Generated from the upstream `struct bpf_insn`.
- Represents regs as bindgen bitfields rather than a public `regs: u8`.
- Provides safe-ish generated accessors for dst/src regs.
- Constants are mostly `u32`, so bpfopt's `u8` opcode expressions need explicit casting or a local alias layer.

## Recommended migration plan

1. Add dependency.
   - In `bpfopt/crates/bpfopt/Cargo.toml`, add `kernel-sys = { path = "../kernel-sys" }`.
   - Do not add direct `libbpf-rs`, `libbpf-sys`, or `libc` dependencies to bpfopt.

2. Centralize constants in `insn.rs`.
   - Replace numeric instruction constants with `kernel_sys::*`-derived aliases.
   - Keep aliases typed as `u8` for existing opcode arithmetic.
   - Keep project/fork-specific constants local and clearly mark why libbpf-sys does not provide them.
   - Keep `bpf_class`, `bpf_size`, `bpf_mode`, `bpf_op`, and `bpf_src` helper functions because libbpf-sys does not expose the function-like macros.

3. Fix program-type constants through kernel-sys.
   - In `elf_parser.rs`, `wide_mem.rs`, `bounds_check_merge.rs`, and `skb_load_bytes.rs`, replace local `BPF_PROG_TYPE_*` definitions with `kernel_sys::BPF_PROG_TYPE_*` aliases.
   - Keep `PassContext::prog_type: u32` in this step to avoid pass-wide type churn.
   - This will correct the current LWT values from 18/19/20 to 10/11/12.

4. Introduce transparent wrapper.
   - Change `BpfInsn` to `#[repr(transparent)] struct BpfInsn(kernel_sys::bpf_insn)`.
   - Implement `new_raw(code, regs, off, imm)` and `new(code, dst, src, off, imm)` constructors.
   - Implement getters/setters for all current public fields.
   - Implement `From<kernel_sys::bpf_insn>` and `From<BpfInsn> for kernel_sys::bpf_insn`.
   - Add slice helpers only if the CLI or verifier path needs zero-copy conversion.

5. Migrate direct field users.
   - Replace `.code`, `.regs`, `.off`, `.imm` reads with method calls.
   - Replace the 18 direct mutations with setter methods.
   - Replace `BpfInsn { ... }` literal construction with `BpfInsn::new_raw(...)` or semantic constructors.
   - Prefer semantic constructors in tests where they improve intent; use `new_raw` for ABI/encoding tests.

6. Update byte parsing/dumping.
   - In `elf_parser.rs`, parse raw 8-byte chunks through `BpfInsn::new_raw(...)`.
   - Keep explicit byte parsing for ELF input unless the project decides to require host-endian object bytecode.
   - In `raw_bytes()`, derive packed regs via the wrapper and assert round trips.

7. Add focused tests.
   - Add bpf instruction layout/round-trip tests with field offsets, not just size.
   - Add program-type constant tests for LWT values and section inference.
   - Avoid broad tests that only prove standard-library or bindgen behavior.

8. Run verification.
   - `cd bpfopt && cargo test -p bpfopt`
   - `cd bpfopt && cargo test -p kernel-sys`
   - If any pass tests fail, inspect for field setter/cast mistakes before changing pass behavior.

## Risks and open questions

- `LD_IMM64`: bpfopt already models it as two consecutive 8-byte instructions and many analyses skip `pc += 2`. `libbpf_sys::bpf_insn` is still a single 8-byte instruction, so no upstream type will hide the two-slot rule. The wrapper must preserve `is_ldimm64()` and existing two-slot handling.
- Constructor `const fn`: current bpfopt constructors are `const fn`. `libbpf_sys::bpf_insn::new_bitfield_1()` is not const. Dropping `const` is likely harmless because current callers appear runtime/test-only, but this should be checked during implementation.
- Bitfield endian semantics: bindgen's bitfield unit accounts for target endian in getters/setters. Current bpfopt packs `regs = dst | (src << 4)` explicitly. The wrapper should use libbpf-sys setters for semantic access and raw-byte tests for the expected little-endian corpus encoding.
- Function-like UAPI macros: libbpf-sys exposes numeric constants but not `BPF_CLASS`, `BPF_SIZE`, `BPF_MODE`, `BPF_OP`, or `BPF_SRC`. bpfopt must retain helper functions or kernel-sys must grow them.
- ProgramType choice: `kernel_sys::ProgramType` is a libbpf-rs enum and `kernel_sys::BPF_PROG_TYPE_*` are libbpf-sys constants. For minimal churn, use constants and keep `u32`; later a typed `ProgramType` conversion can be considered.
- Binary dependency shape: adding `kernel-sys` to bpfopt pulls in libbpf-rs/libbpf-sys at compile/link time. The rules allow this for data APIs, and bpfopt must still avoid calling syscalls.
- Display/disassembly: bpfopt has a simple custom `Debug`/`Display` and byte dump. I found no `bpf_disasm` binding exposed by libbpf-sys. Do not migrate display logic to libbpf in the first pass.
- Local non-instruction constants: map types and helper IDs are also duplicated in tests/analysis. They are outside the narrow `BpfInsn` migration, but the same kernel-sys alias approach should be used when touching those files.

## Final recommendation

Implement 方案 B first. It satisfies the important part of the preference, because the actual stored ABI instruction becomes `kernel_sys::bpf_insn`, while keeping bpfopt pass code readable and testable. It also creates a natural place to enforce byte layout tests and to replace drifted program-type constants.

Do not choose 方案 C as the final answer. It is acceptable only as a temporary bridge for a raw-byte CLI boundary, and today that boundary barely exists. Do not choose 方案 A unless the project is ready for a broad pass/test rewrite and wants to accept bindgen ergonomics everywhere.
