# Phase 3 Report-PC Migration - 2026-05-11

## Shared Boundary

- Conversion boundary: `bpfopt/crates/bpfopt/src/main.rs:1141`
- Function: `report_pc(program, site)` calls `program.site_current_pc(site)` for report serialization.
- Report sink users: `site_skip_report` and `site_diagnostic_report`.
- Pass bodies now emit `InsnSite` through `SiteSkipReason` / `SiteDiagnostic`; pass bodies do not emit report PCs.

## Acceptance Gates

- `cd bpfopt && cargo build --release`
  - Passed clean.
- `cd bpfopt && cargo test --release`
  - Passed: lib `188 passed`, main `16 passed`, `bbprogram_roundtrip` `1 passed`, `cli_pipeline` `12 passed`, doc-tests `0 passed`.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`
  - Passed clean.
- `rg "site_pc\(|site_current_pc\(|report_pc\(" bpfopt/crates/bpfopt/src/passes/`
  - Passed: zero matches.
- Smoke reports:
  - `bpfopt --pass dce` report emitted valid JSON with `sites_applied: 1`, `sites_skipped: 0`.
  - `bpfopt --pass const_prop` report emitted `skipped_sites[0].pc: 1`, matching the legacy report PC for the skipped `mov64_reg` site.

## LOC

| File | Before | After | Delta |
|---|---:|---:|---:|
| `const_prop.rs` | 789 | 777 | -12 |
| `wide_mem.rs` | 540 | 525 | -15 |
| `bulk_memory.rs` | 794 | 793 | -1 |
| `rotate.rs` | 443 | 441 | -2 |
| `extract.rs` | 170 | 162 | -8 |
| `endian.rs` | 404 | 401 | -3 |
| Total | 3140 | 3099 | -41 |

## Migration Log

- `const_prop`: replaced `site_pc` report construction with `SiteSkipReason`; ALU fold skips retain `InsnSite`.
- `wide_mem`: converted all skip records to `SiteSkipReason`; added a local skip helper to keep the migration smaller.
- `bulk_memory`: converted scan/admission skips to `SiteSkipReason`; kinsn admission uses the report-site helper.
- `rotate`: converted tmp/provenance and admission skips to `SiteSkipReason`.
- `extract`: converted cross-block skip and admission skip records to `SiteSkipReason`; removed the extra safe-site struct.
- `endian_fusion`: converted narrow-window and cross-block skips to `SiteSkipReason`; removed a redundant kfunc lookup helper to keep the file below its starting LOC.
- Shared consumers: `prefetch` and `branch_flip` now emit site-keyed skips; `map_inline` map binding PC reconstruction no longer uses `site_pc`.
- Report compatibility: JSON still contains `pc` fields, but they are materialized only at the `main.rs` report sink.

## Self Rating

| Pass | Rating | Notes |
|---|---|---|
| `const_prop` | A | No pass-local report-PC conversion remains. |
| `wide_mem` | A | No pass-local report-PC conversion remains. |
| `bulk_memory` | A | No pass-local report-PC conversion remains. |
| `rotate` | A | No pass-local report-PC conversion remains. |
| `extract` | A | No pass-local report-PC conversion remains. |
| `endian_fusion` | A | No pass-local report-PC conversion remains. |
