# Phase 3 I3 Other-Pass Cleanup - 2026-05-11

## Scope

Modified only the assigned pass files:

- `bpfopt/crates/bpfopt/src/passes/cond_select.rs`
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs`
- `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs`
- `bpfopt/crates/bpfopt/src/passes/endian.rs`
- `bpfopt/crates/bpfopt/src/passes/extract.rs`
- `bpfopt/crates/bpfopt/src/passes/rotate.rs`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`

## Changes

- Replaced direct `InsnSite.block` reads in the five assigned passes with contract APIs:
  - `prog.site_block(site)`
  - `prog.terminator_at_site(site)`
- Preserved the false-positive local fields:
  - `CondBranchShape.block`
  - `BranchTerm.block`
- Migrated `const_prop` LD_IMM64 second-slot lookup from `prog.ldimm64_second_slots.get(&site)` to `prog.ldimm64_second_slot(site)`.
- Migrated `rotate` away from consuming `Range<usize>` returned by admission. It now consumes the opaque admission window through `start_site()` and `end_site()`.
- No pass-side raw verifier type imports were present in these seven files after the cleanup.

## LOC

| file | before | after | delta |
|---|---:|---:|---:|
| `cond_select.rs` | 670 | 677 | +7 |
| `ccmp.rs` | 530 | 530 | 0 |
| `bounds_check_merge.rs` | 557 | 560 | +3 |
| `endian.rs` | 446 | 447 | +1 |
| `extract.rs` | 174 | 175 | +1 |
| `rotate.rs` | 441 | 435 | -6 |
| `const_prop.rs` | 503 | 502 | -1 |
| total | 3321 | 3326 | +5 |

## Gates

- `cd bpfopt && cargo build --release`: FAIL, expected while I1 API migration is not landed. First failures are missing `BBProgram::site_block`, missing `BBProgram::terminator_at_site`, and old `rep_admit_kinsn_site_window` still returning `(BlockId, Range<usize>)` instead of `KinsnAdmissionWindow`.
- Formatting applied to the seven assigned files with `rustfmt`.
- `cd bpfopt && cargo fmt --all -- --check`: FAIL on unowned `crates/bpfopt/src/passes/prefetch.rs:178`. I left it untouched because it is outside this job's write set.

## Required Greps

All required greps over the seven assigned files returned no matches:

- `rg "site_pc|site_current_pc|original_pc|block_start_pc" ...`
- `rg "VerifierInsn\\b|VerifierOracle\\b|RegState\\b|Tnum\\b|ScalarRange\\b|StackState\\b" ...`
- `rg "\\bsite\\.block\\b|\\bstart_site\\.block\\b|\\bjcc_site\\.block\\b|null_check_site\\.block\\b" ...`
- `rg "ldimm64_second_slots\\b" ...`
- `rg "admission_range" crates/bpfopt/src/passes/rotate.rs`
