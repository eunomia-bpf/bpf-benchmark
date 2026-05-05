# Failure Artifacts Restore, 2026-05-05

Historical line refs below are from `git show <commit>:<path> | nl -ba`.

## Part A Research

### Introduced: P57 direct workdir export

- Commit: `d065c46c` (`feat(daemon): export failure workdir to host result dir`), 2026-04-29.
- Shape: no socket payload. The daemon copied its temp workdir into a filesystem export root.
- Files/functions:
  - `daemon/src/commands.rs:23-35` added `BPFREJIT_DAEMON_FAILURE_ROOT`, `BPFREJIT_DAEMON_FAILURE_LAYOUT`, runtime-container detection, and result-root suffix scanning.
  - `daemon/src/commands.rs:309-319` added `preserve_failure_workdir()`, copying `WorkDir` into `<failure_root>/<prog_id>`.
  - `daemon/src/commands.rs:344-365` normalized `prog.bin` to `prog.bpf`, `prog_info.json` to `info.json`, copied `bpfrejit_failure_verifier.log` to `verifier.log`, wrote `replay.sh`, and required those files.
  - `daemon/src/commands.rs:1543-1555` called `preserve_failure_workdir()` on `try_apply_one` error and attached the preserved path to the error message.
- Design doc: `docs/tmp/p57_failure_workdir_export.md:12-43` documents the same direct export contract.

### Introduced: P125/P126-style socket artifacts

- Commit: `ef4736ce` (`Return ReJIT failure artifacts over daemon socket`), 2026-05-03.
- Shape: per-program JSON gained an optional `failure_artifacts` object, not a tarball or path:
  - `daemon/src/commands.rs:141-142` added `OptimizeOneResult.failure_artifacts`.
  - `daemon/src/commands.rs:177-184` defined fields: `failed_pass_index`, `failed_pass`, `committed_passes`, `verifier_log`, `pass_error`, `partial_failure_json`.
  - `daemon/src/commands.rs:1040-1080` built that object in `pass_failure_artifacts()`, reading the verifier log file inline.
  - `daemon/src/commands.rs:1005-1008` copied it into the serialized result.
  - `daemon/src/server.rs:413-452` serialized each `OptimizeOneResult` into `per_program`.
- Python persistence:
  - `runner/libs/rejit.py:791-800` added `failure_artifacts_dir` to `apply_daemon_rejit`.
  - `runner/libs/rejit.py:858-870` popped `failure_artifacts` and wrote `failures/<prog_id>/verifier_log.txt`, `pass_error.txt`, and `partial_failure.json`.
  - `runner/libs/rejit.py:934-944` threaded the parameter through `DaemonSession.apply_rejit`.
  - `runner/libs/case_common.py:135-166` stored the destination in `PreparedDaemonSession`.
  - `runner/libs/case_common.py:260-263` passed it into `apply_rejit`.
- Follow-up: `2093d7a8` fixed corpus scope, changing the corpus call from `daemon_session.failure_artifacts_dir` to `prepared_daemon_session.failure_artifacts_dir`.
- Follow-up: `8208e34c` put daemon stdout/stderr in the bind-mounted result dir and set the corpus destination to that same `details` dir.

### Removed/deleted

- `f0eaf4c5` (`Add metadata and progress files for x86 KVM corpus runs; refactor command handling for pass failures`), 2026-05-05, removed the daemon-side socket artifact object:
  - `daemon/src/commands.rs:126-141` no longer has `failure_artifacts`.
  - `daemon/src/commands.rs:208-229` changed `PassDetail` to include optional `verifier_log` summary on a pass, not the `FailureArtifacts` object.
  - `daemon/src/commands.rs:758-768` put a verifier-log summary into a `FailedRejit` pass detail.
  - `daemon/src/commands.rs:963-968` bounded that summary with `kernel_sys::verifier_log_summary`, not full raw log export.
- `c510c646` (`Net -308 LoC: opaque bpfopt summary, fixes 8b0dfaa7 socket regression`), 2026-05-05, removed Python persistence and the caller destination:
  - `corpus/driver.py` diff removed `failure_artifacts_dir=prepared_daemon_session.failure_artifacts_dir` from `apply_rejit` and removed `prepare_daemon_session(..., failure_artifacts_dir=...)`.
  - `runner/libs/rejit.py` diff removed the `failure_artifacts_dir` parameter from `apply_daemon_rejit`, removed the pop/write block for `failure_artifacts`, and left `DaemonSession.apply_rejit()` with `del failure_artifacts_dir`.
  - Current evidence: `runner/libs/rejit.py:326-394` accepts no `failure_artifacts_dir`; `runner/libs/rejit.py:441-448` accepts then deletes it.
  - Current evidence: `corpus/driver.py:677-684` calls `prepare_daemon_session(daemon_session)` without a destination.
- `45c7a647` completed the opaque pass-through shape:
  - Current `daemon/src/commands.rs:173-180` has `PassDetail { pass, status, error, bpfopt_summary }`; no `verifier_log` and no `failure_artifacts`.

I did not find an exact commit message containing `P89-SimplifyFailure`. The nearest related commits are `c61f0559` (deleted active-run-details layout) and `79b54e3b` (removed failure-root CLI/env plumbing), but those predate `ef4736ce`; the socket artifact removal itself is `f0eaf4c5` plus `c510c646`.

## Part B Restore Verdict

- Option 1, daemon stdout/stderr: not viable. Current daemon logs socket lifecycle and errors, but does not print the workdir path on per-pass ReJIT failure. The only path emission is `WorkDir::drop()` failure logging at `daemon/src/commands.rs:84-91`, not normal failure export.
- Option 2, shared `/tmp`: not viable. The verifier log is written under the daemon temp workdir at `daemon/src/commands.rs:467` and `daemon/src/commands.rs:539`, but `WorkDir::drop()` removes that tree before Python receives the socket response.
- Option 3, existing inline response: not viable in current HEAD. Historical `ef4736ce` had inline `failure_artifacts`, but current `OptimizeOneResult` has only `status`, `prog_id`, `program`, `passes`, and `error_message` at `daemon/src/commands.rs:127-135`. Current `PassDetail` has only `error` plus opaque `bpfopt_summary` at `daemon/src/commands.rs:173-180`; `bpfopt_summary` comes from the bpfopt report at `daemon/src/commands.rs:614-645` and does not contain the ReJIT verifier log.
- Option 4, base64 tarball: not found. Historical implementation was inline JSON fields, not a tarball.

Verdict: **不动 daemon 不可行**. The daemon must either serialize the raw verifier log/artifacts into the socket response before `WorkDir::drop()` or preserve/export the workdir before return. `rejit.py` can only persist bytes that already crossed the socket, and current HEAD does not send them.

## Call-Site Research

- Current generic chain still has a parameter:
  - `runner/libs/case_common.py:155-166` accepts and stores `failure_artifacts_dir`.
  - `runner/libs/case_common.py:260-263` forwards it to `DaemonSession.apply_rejit`.
  - `runner/libs/rejit.py:441-448` accepts then deletes it.
- Current real corpus caller does not pass a non-`None` destination:
  - `corpus/driver.py:677-684` starts `DaemonSession` with daemon logs under `details`, then calls `prepare_daemon_session(daemon_session)` with no `failure_artifacts_dir`.
- The old e2e caller that passed `session.run_dir / "details"` was deleted by `f591080b` (`e2e/driver.py` deleted).

## Deletion Items

If a daemon-side artifact mechanism is not restored, these Python residues are dead and should be deleted in a separate cleanup:

- `runner/libs/case_common.py:139` `PreparedDaemonSession.failure_artifacts_dir`.
- `runner/libs/case_common.py:158-166` `prepare_daemon_session(..., failure_artifacts_dir=...)`.
- `runner/libs/case_common.py:260-263` forwarding into `apply_rejit`.
- `runner/libs/rejit.py:446-448` `DaemonSession.apply_rejit(..., failure_artifacts_dir=...)` plus `del failure_artifacts_dir`.

No code changes were made because restoring the lost mechanism requires daemon output changes, which are outside this task's allowed write scope.
