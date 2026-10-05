# map_inline simplification report

Date: 2026-05-11

## LOC delta

- Baseline `map_inline.rs`: 4197 LOC
- Final `map_inline.rs`: 2847 LOC
- Net reduction: 1350 LOC

Step deltas from local checkpoints. S1 and S2 landed in the same editing
checkpoint, so the split below is approximate; their measured combined reduction
was -915 LOC.

- S1 verifier-guided key extraction: approximately -640 LOC.
  - Removed the ad-hoc constant-key data path (`ConstantKey`, `ExtractedConstantKey`,
    `KeyExtractionError`, `FixedLoadUse`, `R0UseClassification`, `ConstantRegValue`,
    `ConstantStackBytes`) and the byte/ALU constant propagation it carried.
- S2 hint chain collapse: approximately -275 LOC.
  - Collapsed the resolved hint chain into `ResolvedMapInlineHint`.
- S3 skip reasons as strings: -56 LOC.
  - Replaced `SiteRewriteError` with `SiteRewriteResult<T> =
    anyhow::Result<Result<T, String>>`.
- Additional same-file consolidation/debug-only trimming: -379 LOC.

## `reg_known_stack_bytes`

Added `BBProgram::reg_known_stack_bytes(site, reg, key_width) -> Option<Vec<u8>>`.

The method inspects verifier states at `site`, requires all observed states to be
non-empty, non-edge-full states, and requires `reg` to be verifier-proven as an
fp-relative pointer. It then reads the requested stack byte range from verifier
`StackState` slot snapshots. Every observed state must produce the same concrete
byte vector or the query returns `None`.

`map_inline` now calls:

```rust
prog.reg_known_stack_bytes(call_site, BPF_REG_2, key_width)
```

from verifier-guided lookup-key extraction. Stack setup-site collection is kept
separate and only feeds deletion metadata.

## Hint collapse

The old resolved hint chain is gone. The pass now uses one resolved hint record:

```rust
pub struct ResolvedMapInlineHint {
    pub site: InsnSite,
    pub map_id: u32,
    pub key_bytes: Vec<u8>,
    pub value_bytes: Option<Vec<u8>>,
    pub mode: MapInlineHintMode,
    pub map_in_map_inner: Option<(u32, u32)>,
    source_anchor: MapInlineHintAnchor,
}
```

`source_anchor` is retained internally so consumed-hint diagnostics still point
back to the user-supplied hint anchor.

## Skip conversion

`KeyExtractionError` and `SiteRewriteError` are removed. Expected per-site
rewrite vetoes now use a plain `String` skip reason. Fatal IO/snapshot/program
errors still propagate through the outer `anyhow::Result`.

## Gates

- `cd bpfopt && cargo build --release`: pass
- `cd bpfopt && cargo test --release`: pass
  - lib: 186 passed
  - bin: 13 passed
  - roundtrip: 1 passed
  - CLI pipeline: 12 passed
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: pass
- `cd bpfopt && cargo fmt --all && cargo fmt --all --check`: pass
- `wc -l bpfopt/crates/bpfopt/src/passes/map_inline.rs`: 2847
- Focused `cargo test map_inline --lib`: 27 passed
