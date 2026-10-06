# x86 `bpf_bulk_memory` Module Report

Date: 2026-03-26

## Scope

- Added `module/x86/bpf_bulk_memory.c`.
- Added `bpf_bulk_memory.o` to `module/x86/Makefile`.
- Aligned the daemon-side packed `memcpy` payload with the current kinsn v2 proof-sequence model by carrying an explicit dead scratch BPF register.

## Implemented Behavior

- `bpf_memcpy_bulk`
  - Decodes packed `dst_base`, `src_base`, `dst_off`, `src_off`, `len`, and `tmp_reg`.
  - `instantiate_insn()` lowers to bytewise `LDX_MEM(BPF_B) + STX_MEM(BPF_B)` using the packed dead temp reg.
  - `emit_x86()` saves any architecturally-clobbered live mappings of `RDI` / `RSI` / `RCX`, sets up:
    - `RDI = dst`
    - `RSI = src`
    - `RCX = len`
  - Emits `REP MOVSB` (`F3 A4`).
  - Restores preserved registers and leaves the packed temp reg with the same final byte value as the proof sequence.

- `bpf_memset_bulk`
  - Decodes packed `dst_base`, `val_reg`, `dst_off`, `len`, width metadata, `value_from_reg`, `zero_fill`, and `fill_imm8`.
  - `instantiate_insn()` lowers to bytewise `ST_MEM(BPF_B)` or `STX_MEM(BPF_B)` stores.
  - `emit_x86()` saves/restores `RDI`, `RCX`, and `RAX`, sets up:
    - `RDI = dst`
    - `AL = fill byte`
    - `RCX = len`
  - Emits `REP STOSB` (`F3 AA`).

## Notes

- The current repository still uses `instantiate_insn()` as canonical kinsn semantics. Because of that, `memcpy` needs an explicit scratch BPF reg in the packed payload; a pure memory-effect-only ABI would require a different verifier model than the one implemented in-tree today.
- `memset` remains backward-compatible with the current daemon zero-fill payloads and also accepts the more general packed byte-fill form.

## Verification

- `make kinsn-modules`
  - Result: built `module/x86/bpf_bulk_memory.ko` successfully.
- `cargo test --manifest-path daemon/Cargo.toml bulk_memory`
  - Result: `17 passed, 0 failed`.
- `make daemon-tests`
  - Result: `431 passed, 0 failed, 12 ignored`.
