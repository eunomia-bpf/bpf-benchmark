# P3 Matcher Implementation Report

Date: 2026-05-11

## API Added

- `BlockBodyView<'a>`: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:80`
- `BlockStartWindow<'a>`: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:86`
- `LocalWindowHit<T>`: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:104`
- `WindowHit<T>`: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:110`
- `BBProgram::block_body_view(&self, block: BlockId) -> anyhow::Result<BlockBodyView<'_>>`: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:841`
- `BBProgram::scan_block_starts<F, T>(&self, max_lookahead: usize, f: F) -> anyhow::Result<Vec<WindowHit<T>>>`: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:851`

## Predicates Added

- `BpfInsn::is_alu_imm(&self, class: u8, op: u8) -> bool`: `bpfopt/crates/bpfopt/src/insn.rs:596`
- `BpfInsn::is_alu_reg(&self, class: u8, op: u8) -> bool`: `bpfopt/crates/bpfopt/src/insn.rs:603`
- `BpfInsn::is_ldx_mem_size(&self, size: u8) -> bool`: `bpfopt/crates/bpfopt/src/insn.rs:610`

## LOC Accounting

Measured with `wc -l` before edits and after final formatting.

| file | before | after | delta |
|---|---:|---:|---:|
| `extract.rs` | 175 | 158 | -17 |
| `rotate.rs` | 435 | 370 | -65 |
| `wide_mem.rs` | 516 | 381 | -135 |
| `endian.rs` | 447 | 408 | -39 |
| `bulk_memory.rs` | 785 | 753 | -32 |
| pass total | 2358 | 2070 | -288 |

New production helper code: 137 LOC (`bbprogram.rs` matcher types/methods + `insn.rs` predicates).

Net LOC delta after helper subtraction: `288 - 137 = 151` LOC reduced.

## Pattern Conversion Sample

Before, passes repeated block-site collection, instruction lookup, and local-index mapping:

```rust
let block_sites = prog.sites_in_block(block)?;
for window in block_sites.windows(2) {
    let start = window[0];
    let next = window[1];
    let i0 = prog.insn_at(start).ok_or_else(...)?;
    let i1 = prog.insn_at(next).ok_or_else(...)?;
    let Some(site) = extract_site_from_pair(i0, i1) else { continue; };
}
```

After, the pass only supplies semantic matching:

```rust
let raw_sites = prog.scan_block_starts(2, |window| {
    if window.lookahead.len() < 2 {
        return Ok(None);
    }
    Ok(extract_site_from_pair(&window.lookahead[0], &window.lookahead[1])
        .map(|site| window.hit(window.start_idx, 2, site)))
})?;
```

## Migration Notes

- `extract`: fixed 2-instruction SHR/AND pair now uses `scan_block_starts(2)`. Cross-block interior-target skip remains pass-local.
- `rotate`: uses `scan_block_starts(5)` and preserves the backward provenance case through `LocalWindowHit.start_idx`.
- `wide_mem`: in-block ladder matching uses `scan_block_starts(MAX_WIDE_MEM_LEN)`. Cross-block skip probing remains hand-rolled.
- `endian`: in-block load/endian and narrowing scan use `scan_block_starts(MAX_NARROW_SCAN + 1)`. Cross-block skip and preservation remain pass-local.
- `bulk_memory`: uses `block_body_view` for body iteration; the stateful memcpy/memset run matcher, alias checks, liveness, and register dataflow remain hand-rolled.

## Gates

- `cargo build --release`: pass, clean.
- `cargo test --release`: pass, 216 tests.
- `cargo clippy --release --all-targets -- -D dead_code -D warnings`: pass.
- `cargo fmt --all` and `cargo fmt --all --check`: pass, zero diff after formatting.

## Matcher Fit

The matcher fit the mechanical in-block scan layer. It did not fit cross-block skip reporting, rotate provenance semantics, wide_mem packet/BTF policy, endian preservation logic, or bulk_memory's stateful alias/liveness/dataflow logic; those remain explicit in the individual passes.
