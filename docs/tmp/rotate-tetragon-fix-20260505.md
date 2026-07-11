# Rotate Tetragon Fix 2026-05-05

## Approach

Approach B-style userspace fix. The current tetragon observer failures were not caused by a committed rotate rewrite: representative failure output showed `rotate` reported `changed=false` and `sites_applied=0`, then the daemon still submitted an unchanged candidate to `BPF_PROG_REJIT(log_level=2)` and failed with verifier-log resource errors such as `errno 28` / `errno 7`. That made `rotate` the failed pass and stopped later passes.

The fix has two parts:

- `bpfopt/crates/bpfopt/src/passes/rotate.rs:270-335` now routes all Pattern A/B matches through `rotate_site`.
- `bpfopt/crates/bpfopt/src/passes/rotate.rs:345-363` rejects matched sites where `dst_reg == tmp_reg`. The packed rotate kop uses `tmp_reg` as verifier proof scratch, so a site whose original OR writes the result into that same temp is not representable by the packed proof ABI. The regression test is at `rotate.rs:445-455`.
- `daemon/src/commands.rs:740-748` treats `report.changed == false` as a no-op pass: it verifies the output bytecode is identical, records the pass report, and continues without submitting an identical bytecode candidate to ReJIT. If a pass claims unchanged but modifies bytes, it fails fast.
- `daemon/src/commands.rs:673`, `daemon/src/commands.rs:687-692`, and `daemon/src/commands.rs:755-760` now report committed ReJIT count separately from executed/no-op passes.

This does not filter or skip BPF programs. It avoids a ReJIT syscall only when there is no transformed candidate bytecode for that pass.

## Validation

Rust validation:

- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`: passed.
- `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml`: passed.
- `cargo test --release --manifest-path daemon/Cargo.toml`: passed.

KVM smoke:

```sh
SAMPLES=1 BPFREJIT_BENCH_PASSES="rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch,map_inline" \
  BPFREJIT_CORPUS_APPS="tetragon/observer" \
  make vm-corpus
```

Result dir: `corpus/results/x86_kvm_corpus_20260505_150239_039494`.

The make command exited 0. The app-level ReJIT status is still `error`, but no remaining failure is at `rotate`; remaining failures are later-pass failures that now surface naturally.

Failure distribution compared with the pre-fix same-pass observer run `corpus/results/x86_kvm_corpus_20260505_091747_214593`:

| pass | before failures | after failures |
| --- | ---: | ---: |
| rotate | 45 | 0 |
| cond_select | 1 | 1 |
| extract | 1 | 0 |
| prefetch | 2 | 46 |
| map_inline | 0 | 2 |

Sites applied for successful tetragon observer programs:

| pass | before sites_applied | after sites_applied |
| --- | ---: | ---: |
| rotate | 0 | 0 |
| cond_select | 0 | 0 |
| extract | 0 | 0 |
| endian_fusion | 0 | 0 |
| bulk_memory | 2 | 2 |
| prefetch | 1346 | 1362 |
| map_inline | 0 | 0 |

Representative formerly blocked program behavior:

- Before: `prog 190` failed at `rotate` after 0 committed passes with `BPF_PROG_REJIT errno 28`.
- After: `prog 190` executed all 7 requested passes; `rotate`, `cond_select`, `extract`, `endian_fusion`, and `bulk_memory` were no-op, `prefetch` applied 10 sites, and `map_inline` was no-op.

## Delta

Code delta before this report: `+86/-38` across:

- `bpfopt/crates/bpfopt/src/passes/rotate.rs`: `+66/-34`
- `daemon/src/commands.rs`: `+20/-4`

Commit hash: see the commit containing this report. A commit cannot embed its own final hash because the hash covers this file content.
