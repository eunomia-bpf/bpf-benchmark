# failure-via-socket refactor review - 2026-05-03

Target commit: `ef4736ce` (`Return ReJIT failure artifacts over daemon socket`)

## 1. Net code reduction

Result: PASS

Evidence:
- `git show --stat ef4736ce` reports `171 insertions(+)` and `248 deletions(-)`.
- Net delta is `-77`, matching the commit message.
- Changed files are limited to `corpus/driver.py`, `e2e/driver.py`, `runner/libs/case_common.py`, `runner/libs/rejit.py`, and daemon sources.

## 2. `failure_artifacts` only on failed per-program records

Result: PASS

Evidence:
- `daemon/src/commands.rs:141` marks `failure_artifacts` with `skip_serializing_if = "Option::is_none"`, so successful responses do not serialize a null field.
- `OptimizeOneResult::error` initializes `failure_artifacts: None` at `daemon/src/commands.rs:171`.
- The per-pass optimizer initializes `failure_artifacts` to `None` at `daemon/src/commands.rs:840`.
- The only production assignments to `Some(artifacts)` are the pass failure branches at `daemon/src/commands.rs:862`, `daemon/src/commands.rs:894`, and `daemon/src/commands.rs:921`.
- The final result copies that option directly into `OptimizeOneResult` at `daemon/src/commands.rs:1008`; if no pass failure branch ran, the success path stays `None`.
- Runner disk export is gated by `status == "error"`, mapping-shaped artifacts, and a configured destination at `runner/libs/rejit.py:863` through `runner/libs/rejit.py:870`. Successful programs do not create empty failure directories.
- `daemon/src/server.rs` has regression coverage asserting the success record omits the field (`per_program["10"].get("failure_artifacts").is_none()`).

## 3. Old failure-root mechanism removed

Result: PASS after fix

Initial finding:
- Daemon-local grep for the requested old-mechanism identifiers was clean.
- Full-repo grep for the legacy failure-root env-var token initially found tracked stale references in old `docs/tmp/` notes and historical `corpus/results/` artifacts.

Fix applied:
- Replaced the exact stale legacy env-var spelling with generic wording in:
  - `docs/tmp/p57_failure_workdir_export.md`
  - `docs/tmp/full-matrix-20260430/round16-failure-root-fix.md`
  - `docs/tmp/p63_review_recent_changes.md`
  - `docs/tmp/p89_post_audit.md`
  - `docs/tmp/p89_post_audit_fix.md`
  - `corpus/results/x86_kvm_corpus_20260501_001656_447379/details/progress.json`
  - `corpus/results/x86_kvm_corpus_20260501_001656_447379/metadata.json`
  - `corpus/results/x86_kvm_corpus_20260502_222716_584585/details/progress.json`
  - `corpus/results/x86_kvm_corpus_20260502_222716_584585/metadata.json`

Evidence after fix:
- Daemon-local grep for the requested old-mechanism identifiers returned no matches.
- Full-repo grep for the legacy failure-root env-var token returned no matches.

## 4. No env, CLI flag, bind mount, or cwd hack

Result: PASS

Evidence:
- `git show ef4736ce -- runner/libs/suite_commands.py runner/mk/ Makefile` produced no diff.
- `daemon/src/main.rs:18` through `daemon/src/main.rs:20` still define an empty Clap `Cli {}` with no daemon flag additions.
- Daemon source grep shows no failure-path env configuration; the only current `std::env` daemon use is `std::env::temp_dir()` for transient workdirs.
- Daemon startup still calls `subprocess.Popen(cmd, stdout=out, stderr=err, text=True)` with no `cwd` argument at `runner/libs/rejit.py:723` through `runner/libs/rejit.py:725`.
- `runner/libs/suite_commands.py`, `runner/mk/`, and `Makefile` did not gain a Docker bind mount for daemon failure artifacts.

## 5. Build and tests

Result: PASS

Evidence:
- `cd daemon && cargo check --release` passed:
  - `Finished release profile [optimized] target(s) in 0.49s`
- `cd daemon && cargo test --release` passed:
  - `test result: ok. 40 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 1.21s`
- `python -m pytest tests/python/ -v` passed:
  - `19 passed, 4 subtests passed in 0.61s`

## Summary

The refactor invariants pass in the final reviewed tree. One stale-reference violation was found outside daemon/runtime code in tracked historical docs and result artifacts; it was fixed directly, then the requested Rust and Python checks passed.
