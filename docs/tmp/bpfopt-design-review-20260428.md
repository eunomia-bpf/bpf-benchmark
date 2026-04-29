# bpfopt / daemon design review (2026-04-28)

## Executive summary

`daemon/` is the real implementation path and matches the current project design much better than the old `bpfopt/`: `bpfrejit-daemon serve` is the only runtime entry, it discovers live programs, runs the pass pipeline, performs per-pass `BPF_PROG_LOAD` verification, rolls rejected passes back, and finally calls `BPF_PROG_REJIT`.

At the start of this review, `bpfopt/` existed and was not a shared library used by daemon. It was a copied fork of the same pass tree with an offline CLI wrapper. The two copies had already diverged in API and behavior, and `bpfopt-core` tests were broken.

While this review was in progress, `main` advanced to `08f8a7cf refactor: unify bpfopt-core and daemon pass implementations`. That commit chose the recommended cleanup direction: delete `bpfopt/`, keep `daemon/src/` as the single pass implementation, and update the active plan/archive wording. Current HEAD now has no tracked `bpfopt/` files (`git ls-files 'bpfopt/*'` returns 0).

Final recommendation after that commit: keep the current daemon-only source of truth. If an offline optimizer is needed again later, re-extract from daemon with explicit adapter traits instead of copying the pass tree.

## Scope and evidence

Read:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/daemon-bpfopt-status-20260428.md`
- `CLAUDE.md`
- `daemon/src/**`
- `bpfopt/crates/bpfopt-core/src/**`
- `bpfopt/crates/bpfopt/src/main.rs`

Commands run:

- `git diff --no-index --stat daemon/src/passes bpfopt/crates/bpfopt-core/src/passes`
- `cargo test -p bpfopt-core --manifest-path bpfopt/Cargo.toml`
- `cargo check --manifest-path bpfopt/Cargo.toml`
- `git show --stat --oneline HEAD`
- `git ls-files 'bpfopt/*' | wc -l`

This report therefore has two layers:

- Sections 1, 2, 4, 6, and 7 record the duplicate/forked state observed before `08f8a7cf`.
- Sections 3, 5, and the final assessment state the current HEAD outcome after `08f8a7cf`.

## 1. Duplicate pass implementations and diffs

Both registries list the same 12 pass names, in the same order:

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

`git diff --no-index --stat daemon/src/passes bpfopt/crates/bpfopt-core/src/passes` reports 15 changed pass-side files, with 380 insertions and 422 deletions. There is no pass that exists only in one registry, but several implementations differ materially.

Per-pass diff summary:

| Pass / file | Diff summary | Design impact |
| --- | --- | --- |
| `map_inline.rs` | Largest divergence. Daemon uses `crate::bpf` live map APIs for map metadata and value lookup. bpfopt replaces this with `BpfProgram.map_metadata` and `BpfProgram.map_values` snapshots. Daemon also has newer alias-offset tracking: `alias_regs: HashMap<reg, offset>`, `alias_adjustment()`, offset-aware fixed loads, and fp-alias stack-store handling. bpfopt keeps only `HashSet` alias tracking and dropped related tests. | bpfopt is not feature-equivalent. It can run offline from snapshots, but misses daemon's current map-inline coverage and live-kernel behavior. |
| `bulk_memory.rs` | Daemon imports `ensure_btf_fd_slot()` and turns target BTF FDs into `CALL.off` fd-array slots. bpfopt removes that and uses `ctx.kinsn_registry.call_off_for_target_name()`. | Same rewrite intent, different kinsn transport model. |
| `rotate.rs` | Same as above: daemon records required BTF FD slots; bpfopt uses precomputed `call_off_for_pass()`. Other diff is mostly expanded `PassResult` construction. | Transport/API divergence, not a pass-algorithm improvement. |
| `cond_select.rs` | Same kinsn transport divergence. bpfopt expands daemon's `PassResult::skipped*()` helpers inline. | Transport/API divergence. |
| `extract.rs` | Same kinsn transport divergence. bpfopt tests still assert daemon-only `target_btf_fds` / `required_btf_fds`, so tests are stale. | Broken test state plus transport divergence. |
| `endian.rs` | Same kinsn transport divergence. bpfopt tests still assert daemon-only BTF FD recording. | Broken test state plus transport divergence. |
| `branch_flip.rs` | No substantive algorithm change observed; bpfopt inlines `PassResult` helper construction. | Mostly cosmetic/API drift. |
| `bounds_check_merge.rs` | No substantive algorithm change observed; bpfopt inlines `PassResult` helper construction. | Mostly cosmetic/API drift. |
| `const_prop.rs` | Production logic is effectively the same. Tests switch from daemon `crate::bpf` mock maps to `crate::mock_maps` plus `apply_mock_maps()`. | Test harness divergence only. |
| `dce.rs` | No substantive algorithm change observed; bpfopt inlines `PassResult::unchanged()`. | Mostly cosmetic/API drift. |
| `skb_load_bytes.rs` | No substantive algorithm change observed; bpfopt inlines unchanged results. | Mostly cosmetic/API drift. |
| `wide_mem.rs` | No substantive algorithm change observed; bpfopt inlines unchanged result construction. | Mostly cosmetic/API drift. |
| `utils.rs` | Daemon has `ensure_btf_fd_slot(program, btf_fd) -> i16`; bpfopt deletes it. | This is the common helper that makes daemon kinsn transport work, so its absence is central to the split. |

Support-code diffs that affect pass behavior:

- `analysis/map_info.rs`: daemon resolves live map info through `bpf::bpf_map_get_info_by_id()`. bpfopt resolves only from `program.map_metadata`.
- `pass.rs`: daemon owns verifier/rollback and BTF FD transport state. bpfopt removes those and adds offline map snapshots.
- `elf_parser.rs`: bpfopt has an older test-only copy with different struct_ops handling and a silent `u32::MAX` fallback for oversized global-data sections. Daemon's copy is stricter/newer.
- `mock_maps.rs`: exists only in bpfopt-core to replace daemon's test `crate::bpf` mock-map support.

## 2. bpfopt-core API vs daemon pass API divergence

Main divergences:

| Area | daemon API | bpfopt-core API |
| --- | --- | --- |
| Program metadata | `BpfProgram.required_btf_fds` records descriptor BTF FDs needed by kinsn calls. | No `required_btf_fds`; instead has `map_values` and `map_metadata` offline snapshots. |
| Kinsn transport | `KinsnRegistry.target_btf_fds`, `btf_fd_for_pass()`, `btf_fd_for_target_name()`, `all_btf_fds()`. Passes call `ensure_btf_fd_slot()`. | `KinsnRegistry.target_call_offsets`, `call_off_for_pass()`, `call_off_for_target_name()`. |
| Per-pass verify | `PassResult.verify`, `PassVerifyStatus`, `PassVerifyResult`, `PassRollbackResult`. | No verify/rollback types in production API. |
| Pass manager | `run_with_verifier()` and `run_with_profiling_and_verifier()` verify every changed pass and rollback rejected output. | Only pure `run()` / `run_with_profiling()`. Changed pass output is always kept. |
| Debug trace | Includes `verify` in `PassDebugTrace`. | Only `pass_name`, `changed`, bytecode before/after. |
| Map info | Live kernel map resolver. | Snapshot resolver. |
| Map inline values | Direct live map lookup by map id/key. | Requires preloaded `map-values.json` / mock map snapshots. |
| Helper constructors | Daemon has `PassResult::unchanged()`, `skipped()`, `skipped_with_diagnostics()`. | Removed; many bpfopt pass diffs are just inline struct literals. |

This is not just a crate boundary. It is a different execution model: daemon's pass API is live-REJIT aware, while bpfopt-core is offline bytecode-in/bytecode-out.

## 3. Does the bpfopt CLI still have value?

Not as a project/runtime entry. The plan says daemon CLI has converged to `serve --socket`, and runner code starts `bpfrejit-daemon serve` and sends JSON requests. `runner/mk/build.mk` tracks daemon sources and builds only the daemon artifact; it does not build or package `bpfopt`.

The current `bpfopt` CLI can still be useful only as a developer tool:

- run a single pass on raw 8-byte BPF instruction streams,
- inspect pass lists,
- provide synthetic target/profile/map-value JSON side inputs,
- generate offline reports for golden tests.

But that value was hypothetical: it had no Makefile target, no CI/build surface, and broken core tests. Current HEAD deleted it, which is consistent with daemon-serve being the only supported entry.

## 4. bpfopt-core tests

Before `bpfopt/` was deleted, `cargo test -p bpfopt-core --manifest-path bpfopt/Cargo.toml` did not pass. It failed at test compile time with 43 Rust errors.

Representative failures:

- `PassDebugTrace` has no field `verify`.
- `PassVerifyStatus`, `PassVerifyResult`, and `PassRollbackResult` are undeclared.
- `KinsnRegistry` has no `target_btf_fds` field.
- `KinsnRegistry` has no `btf_fd_for_pass()` or `all_btf_fds()`.
- `PassManager` has no `run_with_verifier()`.
- `BpfProgram` has no `required_btf_fds`.
- `endian.rs` and `extract.rs` tests still assert daemon-only BTF FD recording.

`cargo check --manifest-path bpfopt/Cargo.toml` did pass for non-test builds before deletion. So the library and CLI compiled without test code, but the test suite still referenced old daemon-side APIs and was broken.

There was also no canonical Makefile target for `bpfopt`, so this broken test state was not caught by the project's normal build path. Current HEAD removes the crate, so `bpfopt-core` tests are now not applicable unless an offline crate is reintroduced.

## 5. Integration direction

### Option A: daemon depends on bpfopt-core

This matches the #646 plan text, but only if `bpfopt-core` becomes the real source of truth. Current bpfopt-core is not ready for that:

- tests do not compile,
- map-inline is behind daemon's current implementation,
- kinsn transport has incompatible semantics,
- per-pass verify/rollback is missing from the API even though daemon's runtime correctness depends on it,
- no canonical build target exists.

If choosing A, do not make daemon depend on the current bpfopt-core as-is. Instead, rebuild bpfopt-core from daemon's current pass code and introduce explicit traits/adapters:

- `KinsnCallResolver`: live daemon implementation returns fd-array slots; offline CLI implementation returns precomputed call offsets.
- `MapInfoProvider` / `MapValueProvider`: daemon uses raw BPF syscalls; bpfopt CLI uses JSON snapshots.
- `PassVerifier`: daemon uses `BPF_PROG_LOAD`; offline CLI uses no-op or test verifier.

That would preserve one pass implementation while keeping daemon-specific transport outside pure pass logic.

### Option B: merge bpfopt-core back into daemon and delete bpfopt

This is the most pragmatic near-term direction. It removes a broken, unintegrated duplicate tree and aligns with the current serve-only operational design. It also avoids a second public-ish CLI whose semantics can drift from daemon.

The cost is losing an offline optimizer harness. Based on current code, that harness is not yet reliable enough to justify the maintenance burden.

This is the direction current HEAD took in `08f8a7cf`.

### Option C: staged cleanup

Best practical path:

1. Treat daemon as source of truth immediately.
2. Either delete `bpfopt/` now, or mark it explicitly experimental/dev-only and remove it from design claims.
3. If #646 remains a hard design goal, re-extract from daemon later using provider traits, and only then make daemon depend on `bpfopt-core`.

My recommendation is C with a short-term B bias: remove or quarantine `bpfopt/` first, then re-extract only when there is a concrete need for the offline crate. Current HEAD has already completed the "remove `bpfopt/` first" part.

## 6. bpfopt-only functionality missing from daemon

Before deletion, no unique optimization pass existed only in bpfopt. The pass registry was identical.

bpfopt-only non-runtime features:

- offline `bpfopt` CLI with `optimize`, per-pass subcommands, `analyze`, and `list-passes`;
- raw bytecode stdin/stdout workflow;
- `--target`, `--profile`, `--map-values`, and `--map-ids` side-input JSON;
- `MapMetadata` / `map_values` snapshot model;
- `mock_maps.rs` and `apply_mock_maps()` test support.

These were developer/offline features, not daemon/runtime features. They are gone in current HEAD.

## 7. daemon-only functionality missing from bpfopt

No unique pass name exists only in daemon, but daemon has substantial runtime and pass-manager functionality missing from bpfopt:

- `serve` Unix socket server and JSON request model;
- live BPF program enumeration and `orig_prog_insns` fetch;
- raw `bpf(2)` syscall wrappers for program info, map info, per-pass verify, and final REJIT;
- per-pass `BPF_PROG_LOAD` verification;
- rollback of rejected pass output;
- verifier-log state refresh between passes;
- kfunc/kinsn discovery from kernel BTF;
- descriptor BTF FD lifetime and fd-array construction;
- final `BPF_PROG_REJIT`;
- PMU/profile integration;
- map-inline invalidation tracker and reoptimization;
- stronger current `map_inline` alias-offset handling;
- stricter/newer test-only ELF parser behavior, including struct_ops prog-type handling.

The daemon implementation is therefore not just a wrapper around bpfopt. It is the authoritative optimizer/runtime.

## Final assessment

The pre-`08f8a7cf` bpfopt was not consistent with the project design if the design meant "daemon shares pass implementations from bpfopt-core." It was consistent only with a weaker interpretation: "there exists an offline pure optimizer copy." That weaker interpretation was not very useful for the project because daemon serve is the only runtime path and bpfopt-core tests were broken.

Current HEAD has resolved the inconsistency by deleting `bpfopt/`. The codebase now has exactly one pass implementation source of truth: daemon.
