# Benchmark Framework Changes Audit During v3 Migration

Date: 2026-04-28 (`date +%Y%m%d` = `20260428`)

Range audited: `7d34960~1..HEAD`

Start commit: `7d34960ee5564de5493a4c02e1bb3edcef135b61`

Current HEAD: `3c0c0a8ffb45979994a1e9e275f99c342db839d0`

Benchmark framework paths checked: `runner/`, `corpus/`, `e2e/`, `micro/`

Policy used for this audit: during the v3 migration, benchmark framework changes should be limited to true bug fixes, test data updates, or necessary image/build wiring for the v3 CLI architecture.

## 1. All Commits In The v3 Migration Window

Command:

```text
git log --oneline 7d34960~1..HEAD
```

Output:

```text
3c0c0a8f docs: record v3 §8 plan B (daemon adapts socket-to-CLI; runner untouched)
3a762d6b feat(runner): add 5 bpfopt-suite CLIs + jq to runner-runtime image
fde5a07c fix(bpfprof): graceful null output when PMU unavailable
bc28da0c test: live minimal pipeline validation (Phase 1.6)
6a600c97 docs: review phase 2 high fix
44efcdb4 fix(bpfverify,bpfprof): align report schema with v3; clarify PMU is not per-program
b42f610b docs: review phase 2 bpfverify bpfprof migration
4d0763ed test: smoke validate Phase 1 CLI on host
5ffbe09c fix(scripts): per-pass-verify side-input plumbing; default zero-side-input passes
e68ddbd6 docs: audit bpfopt v3 conformance
681f5ba8 feat: implement bpfverify (with verifier_log) and bpfprof CLI; remove bpfopt::verifier_log
dbfda9fc docs: record v3 phase 1 completion in plan doc
8ca15b6c fix(bpfget,bpfrejit): respect kernel-sys boundary; --dry-run supports fd_array; --full atomicity
9c38e740 docs: review bpfget bpfrejit cli
aaaaa76a fix(bpfopt): exit 1 on missing required side-input or unavailable kinsn
dc3abe33 feat: implement bpfget and bpfrejit CLI (v3 §2.4 + §2.5)
0929d7ad docs: review bpfopt CLI commit
b0da364e feat(bpfopt): implement v3 CLI (12 pass subcommands + optimize + analyze)
eeb61db0 docs: review bpfopt kernel-sys migration fix
50725715 test: micro BpfReJIT smoke after bpfopt-core merge
a441e221 refactor(bpfopt): make BpfInsn a transparent wrapper around kernel_sys::bpf_insn; align constants with libbpf-sys
defad0a6 fix(micro): restore baseline 'simple' microbench so vm-micro works
18326325 docs: add bpfopt kernel-sys migration assessment
cadeb253 docs: design daemon slimdown
fa503ea4 docs: add bpfrejit CLI design notes
3a47b200 docs: add bpfverify CLI design notes
2e13d9b0 feat(scripts): add per-pass verify loop bash (v3 §4.3)
85ce58e3 docs: research runner cli migration
dbf97b5a docs: review kernel-sys critical fix
588da364 fix(kernel-sys): use BPF_OBJ_GET_INFO_BY_FD orig_prog_* for prog_get_original; verify log + map APIs
25faafd5 test: micro smoke run after bpfopt-core merge
de64cde3 test: remove low-value unit tests; add quality guideline
ecaa34f3 docs: research bpfget CLI design
cae9fb00 docs: review kernel-sys commit
adb2abc9 docs: add bpfprof CLI design research
dde1f291 docs: archive docs/tmp/ files superseded by bpfopt_design_v3
9f59ee43 feat(kernel-sys): introduce kernel-sys crate using libbpf-rs/libbpf-sys
8912da4f docs: record kernel-sys as the only BPF syscall boundary
d973a4fd fix(bpfopt): address merge review findings (transition errata, shell modules, host probing)
57463366 docs: evaluate libbpf-rs bytecode API
3472273e docs: add bpfopt merge review
fc70de0e docs: record CLI no-cross-deps and libbpf-rs preference rules
7d34960e refactor: merge bpfopt-core into bpfopt crate (lib+bin)
```

## 2. Commits Touching Benchmark Framework Paths

Command:

```text
git log --oneline 7d34960~1..HEAD -- runner/ corpus/ e2e/ micro/
```

Output:

```text
3a762d6b feat(runner): add 5 bpfopt-suite CLIs + jq to runner-runtime image
defad0a6 fix(micro): restore baseline 'simple' microbench so vm-micro works
7d34960e refactor: merge bpfopt-core into bpfopt crate (lib+bin)
```

Files changed by those commits:

| Commit | Message | Files |
|---|---|---|
| `3a762d6b` | `feat(runner): add 5 bpfopt-suite CLIs + jq to runner-runtime image` | `runner/containers/runner-runtime.Dockerfile`, `runner/mk/build.mk` |
| `defad0a6` | `fix(micro): restore baseline 'simple' microbench so vm-micro works` | `micro/config/micro_pure_jit.yaml`, `micro/driver.py` |
| `7d34960e` | `refactor: merge bpfopt-core into bpfopt crate (lib+bin)` | `runner/mk/build.mk` |

No commits in the audited range changed files under `corpus/` or `e2e/`.

The known `a441e221` `BpfInsn` API migration commit does not touch `runner/`, `corpus/`, `e2e/`, or `micro/`; it is not a benchmark framework change.

## 3. Per-File Assessment

| Commit | File | Change Type | Rating | Assessment |
|---|---|---|---|---|
| `7d34960e` | `runner/mk/build.mk` | Build dependency tracking update after `bpfopt-core` merged into `bpfopt` | Necessary | This points `BPFOPT_SOURCE_FILES` at the new crate location and keeps daemon image rebuild tracking valid during the transition where the daemon still depends on `bpfopt` library code. This is v3 build plumbing, not benchmark behavior. |
| `defad0a6` | `micro/driver.py` | Bug fix | Necessary | `attach_baseline_adjustments` now tolerates a missing baseline only for incomplete/error artifacts. This matches the known baseline regression fix and prevents artifact generation from masking the original failed run. |
| `defad0a6` | `micro/config/micro_pure_jit.yaml` | Test data update | Necessary | Updates stale `expected_result` values for pure-JIT micro benchmarks. This is explicitly allowed test data maintenance and matches the known stale expected-result fix. |
| `3a762d6b` | `runner/containers/runner-runtime.Dockerfile` | Runtime image dependency/artifact wiring | Necessary | Adds `jq`, builds the 5 v3 CLI binaries (`bpfopt`, `bpfget`, `bpfrejit`, `bpfverify`, `bpfprof`), installs them into `/usr/local/bin`, and cleans Rust build intermediates. This is required for v3 CLI execution in the runner image and is not runner Python or benchmark logic churn. |
| `3a762d6b` | `runner/mk/build.mk` | Build script wiring for v3 CLI artifacts | Necessary | Adds `ACTIVE_BPFOPT_*` variables, `BPFOPT_SOURCE_FILES`, `image-bpfopt-artifacts`, and `cargo build` rules for the 5 CLI crates. Including `BPFOPT_SOURCE_FILES` in image/build inputs is needed so CLI source changes rebuild the runtime image. |

## 4. Notes On The "Need To Confirm" Items

- `runner/containers/runner-runtime.Dockerfile` adding the 5 CLI binaries and `jq` in `3a762d6b`: necessary. The runtime image must contain the external v3 tools that benchmark execution will call. Adding these binaries to the image is image/build plumbing, not an app-level benchmark behavior change.
- `runner/mk/build.mk` adding `BPFOPT_SOURCE_FILES` and `image-bpfopt-artifacts` in `3a762d6b`: necessary. It gives Docker/build cache invalidation a source-file set for the new CLI artifacts and avoids relying on stale runtime images.
- Other unexpected benchmark framework changes: none found. The only committed benchmark path changes are the three commits listed above.

## 5. Current Working Tree Status

Command:

```text
git status --porcelain=v1 --untracked-files=all
```

Output: no output.

Current working tree is clean. There are no uncommitted changes under `runner/`, `corpus/`, `e2e/`, or `micro/`, and therefore no uncommitted benchmark diff summary to list.

## 6. Conclusion

All committed benchmark framework changes in `7d34960~1..HEAD` are reasonable under the stated policy.

No non-essential benchmark framework refactor was found.

Recommended reverts: none.

Keep:

- `7d34960e` `runner/mk/build.mk` build-source tracking update.
- `defad0a6` `micro/driver.py` baseline regression fix.
- `defad0a6` `micro/config/micro_pure_jit.yaml` expected-result test data update.
- `3a762d6b` runner runtime image and build rules for v3 CLI artifacts.
