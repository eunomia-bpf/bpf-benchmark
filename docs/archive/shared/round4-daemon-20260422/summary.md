# Round 4 Daemon PassResult Dedup (2026-04-22)

## Scope

- Edited only:
  - `daemon/src/pass.rs`
  - `daemon/src/passes/*.rs` for the 12 pass files in scope
- No changes needed in `daemon/src/commands.rs` or `daemon/src/commands_tests.rs`.
- No VM / corpus / e2e runs were executed.

## Helper

- Added at `daemon/src/pass.rs:301-327`:
  - `PassResult::unchanged(pass_name: impl Into<String>) -> Self`
  - `PassResult::skipped(pass_name: impl Into<String>, reason: SkipReason) -> Self`
  - `PassResult::skipped_with_diagnostics(pass_name: impl Into<String>, reason: SkipReason, diagnostics: Vec<String>) -> Self`
- Usage pattern:
  - Single skip reason sites now call `PassResult::skipped(...)`.
  - Empty / multi-skip / diagnostics / `map_inline_records` cases now use struct update on `PassResult::unchanged(...)`.

## Replacement Sites

Notes:
- Line numbers below are the pre-edit site locations from the grep/review sweep.
- `before -> after` counts are the local return-block sizes at each site.

- `daemon/src/passes/rotate.rs`
  - `31` (`11 -> 7`, `skipped`)
  - `45` (`11 -> 7`, `skipped`)
  - `66` (`11 -> 7`, `skipped`)
  - `124` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/cond_select.rs`
  - `130` (`11 -> 7`, `skipped`)
  - `156` (`15 -> split helper path`: `4`-line unchanged branch when `sites.is_empty()`, `8`-line `skipped_with_diagnostics` branch otherwise)
  - `174` (`11 -> 7`, `skipped`)
  - `239` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/endian.rs`
  - `230` (`11 -> 7`, `skipped`)
  - `256` (`11 -> 7`, `skipped`)
  - `326` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/extract.rs`
  - `113` (`11 -> 7`, `skipped`)
  - `127` (`11 -> 7`, `skipped`)
  - `164` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/bounds_check_merge.rs`
  - `95` (`8 -> 1`, `unchanged`)
  - `110` (`8 -> 4`, `unchanged + sites_skipped`)
  - `165` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/branch_flip.rs`
  - `93` (`8 -> 4`, `unchanged + diagnostics`)
  - `103` (`11 -> 7`, `skipped`)
  - `206` (`8 -> 5`, `unchanged + sites_skipped + diagnostics`)

- `daemon/src/passes/skb_load_bytes.rs`
  - `69` (`8 -> 1`, `unchanged`)
  - `80` (`8 -> 1`, `unchanged`)
  - `93` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/bulk_memory.rs`
  - `111` (`8 -> 1`, `unchanged`)
  - `178` (`8 -> 4`, `unchanged + sites_skipped`)

- `daemon/src/passes/const_prop.rs`
  - `195` (`8 -> 1`, `unchanged`)
  - `235` (`8 -> 1`, `unchanged`)

- `daemon/src/passes/dce.rs`
  - `90` (`8 -> 1`, `unchanged`)

- `daemon/src/passes/map_inline.rs`
  - `986` (`8 -> 5`, `unchanged + sites_skipped + diagnostics`)
  - `1043` (`9 -> 6`, `unchanged + sites_skipped + diagnostics + map_inline_records`)

- `daemon/src/passes/wide_mem.rs`
  - `508` (`8 -> 4`, `unchanged + sites_skipped`)

- Total original early-return scaffolds replaced: `31`

## Grep Verification

- `rg -n "changed:\\s*false|sites_applied:\\s*0" daemon/src/passes daemon/src/pass.rs`
  - Remaining hits are only:
    - `daemon/src/pass.rs:304-305` inside the new `PassResult::unchanged(...)` helper body
    - `daemon/src/pass.rs:977` for `PassDebugTrace.changed`, unrelated to `PassResult`
  - There are no remaining pass-file open-coded `changed: false` / `sites_applied: 0` early-return scaffolds.

- `rg -n "PassResult\\s*\\{" daemon/src/pass.rs daemon/src/passes | wc -l`
  - Remaining count: `29`
  - Breakdown:
    - `13` normal success/final result constructors
    - `14` helper-based struct updates that still need extra fields (`sites_skipped`, `diagnostics`, or `map_inline_records`)
    - `2` `pass.rs` definition/impl anchors

## Verification

- `cargo test --manifest-path daemon/Cargo.toml`
  - Result: `494 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out`
- `make -C daemon release`
  - Result: success
- `make check`
  - Result: success (`python -m py_compile ...`)
- No VM targets were run.

## Diff

- `git diff --shortstat -- daemon/src/pass.rs daemon/src/passes`
  - `13 files changed, 110 insertions(+), 219 deletions(-)`
  - Net: `-109` lines
