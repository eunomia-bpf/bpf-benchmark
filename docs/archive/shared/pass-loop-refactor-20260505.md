# Pass loop refactor 2026-05-05

- Diff summary for final staged commit: +19/-32166, net -32147 (includes deleting generated corpus artifacts that were accidentally committed before this fix-forward commit).
- New per-pass status enum: `daemon/src/commands.rs:206` defines `PassStatus` serialized as `ok`, `unchanged`, `skipped_missing_states`, `failed_bpfopt`, `failed_rejit`.
- Per-pass fields: `daemon/src/commands.rs:217` adds `PassDetail.status` and optional `PassDetail.error`.
- Propagation: `daemon/src/commands.rs:666` runs every requested pass through `run_pass_chain`; `daemon/src/commands.rs:677`, `:712`, `:731`, and `:755` map missing states, bpfopt failure, unchanged, and ReJIT failure into pass records.
- State mutation: `daemon/src/commands.rs:765` updates `verifier_states_ready`, `current_bytes`, and `committed_passes` only after successful `BPF_PROG_REJIT`.
- Removed abort plumbing: `partial_error`, `failure_artifacts`, `last_rejit`, and the `pass_failure_artifacts()` helper are gone.
- Noop hint: removed from the missing-verifier-states path; the pass now records `skipped_missing_states`.
- Unit regression: `daemon/src/commands.rs:1547` constructs a 3-pass chain with pass 1 `failed_rejit` and asserts pass 2 is still reported.
- Smoke run: `SAMPLES=1 BPFREJIT_BENCH_PASSES="rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch,map_inline" BPFREJIT_CORPUS_APPS="tetragon/observer" make vm-corpus`.
- Smoke artifact: `corpus/results/x86_kvm_corpus_20260505_154015_521442`, app status `ok`, 287 programs, all 287 raw daemon records have 7 pass entries.
- Smoke statuses across raw pass records: 237 `ok`, 1671 `unchanged`, 50 `failed_rejit`, 51 `skipped_missing_states`.
- Representative before: `x86_kvm_corpus_20260505_152313_274886`, `event_execve` prog 177 had 1 pass record (`noop`) and program status `error` after `map_inline` missing verifier states.
- Representative after: `x86_kvm_corpus_20260505_154015_521442`, `event_execve` prog 23 has all 7 records: `rotate:unchanged, cond_select:unchanged, extract:unchanged, endian_fusion:unchanged, bulk_memory:unchanged, prefetch:failed_rejit, map_inline:skipped_missing_states`.
- Commit hash: final hash is reported after amend/push; a single commit cannot contain its own final object ID.
