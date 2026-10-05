# Tetragon Reject Root Cause Investigation (2026-05-03)

## Part 1: Why Are the Host Workdirs Empty?

**Root cause: the failure export path is not bind-mounted into the host.**

The daemon is hardcoded (`daemon/src/main.rs:18`) to write failure workdirs to
`/var/tmp/bpfrejit-failures` inside the container. The docker run command built
by `runner/libs/suite_commands.py:build_runtime_container_command` (lines 142–152)
only bind-mounts the suite result directory (e.g. `corpus/results`) and five system
paths (`/sys`, `/sys/fs/bpf`, `/sys/kernel/debug`, `/lib/modules`, `/boot`). It
does **not** mount `/var/tmp/bpfrejit-failures`.

When the container exits, everything under `/var/tmp` inside the container is
discarded. The host path `/var/tmp/bpfrejit-failures/<prog_id>/` that appears
"empty" is actually on the KVM guest filesystem, not on the outer host. The daemon
does create those directories (the `ensure_writable_dir` write-probe succeeds inside
the guest) and then successfully copies files from the workdir into them. But the
copies live only on the guest VM disk image, which is deleted after the run
(`runner/libs/kvm_executor.py:48`, `rm -f "$docker_disk"`).

The `preserve_failure_workdir` code at `daemon/src/commands.rs:134–142` is correct:
it does call `copy_dir_contents`. The missing link is that `FAILURE_ROOT =
"/var/tmp/bpfrejit-failures"` (daemon/src/main.rs:18) is inside the container, while
only `corpus/results` is projected to the host. The P57 design (`docs/tmp/p57_failure_workdir_export.md`)
used the `active-run-details` layout that writes into the corpus run directory — but
that layout was superseded by the current hardcoded path with no corresponding
bind-mount being added to `suite_commands.py`.

**Secondary note on the "v7 run" context:** The v7 run that generated 20+
"preserved failure workdir for prog X" lines was using the current daemon (which
writes to `/var/tmp/bpfrejit-failures`). The daemon stderr with those lines lives at
`/var/tmp/bpfrejit-daemon/bd-<token>/daemon.stderr.log` inside the container, also
not bind-mounted, and is therefore also lost when the container exits.

## Part 2: Why Do Tetragon Programs Reject?

The answer is documented in `docs/tmp/p89h_root_cause.md` from an Apr 30 debug run
(`x86_kvm_p89_kop_tetragon_debug_20260430_134738_850952`), which DID export 22
populated failure workdirs (that run used an older daemon version that wrote failures
into the corpus result directory).

**Root cause: multi-subprogram kop candidates in `bulk_memory` and `extract`.**

All 22 rejecting tetragon progs are `generic_kprobe_` or `generic_retkprobe`
programs with `nr_func_info = 2` or `6` — i.e. multi-subprogram. The bpfopt passes
`bulk_memory` and `extract` were emitting kop replacement candidates into these
programs. The bpfverify dry-run passed (bytecode is verifier-valid), but the kernel
REJIT path rejected because the kop candidate boundary did not preserve subprogram
metadata boundaries required by the ReJIT replacement contract.

Fixes were committed as `858ddd97` (`extract` skips multi-subprog candidates) and
`bad918ea` (`bulk_memory` skips multi-subprog candidates). If the v7 run is using
an image built BEFORE those commits, the same rejections will recur.

The single-insn proof that the code is not actually invalid: the
`bpfverify_report.json` for every failing prog shows `"status": "pass"` — the
problem is not bad bytecode, it is the kop subprogram boundary contract in the
REJIT kernel path.

Tracee progs do not hit this because tracee's `generic_calls` programs are
single-subprogram (the programs that passed in the reference tracee run had
`nr_func_info ≤ 1`).

## Part 3: How to Capture the Actual Error Without Bigger Refactor

Three options, in increasing difficulty:

1. **Read daemon.stderr.log from inside the container before it exits.** The daemon
   stderr file is at `/var/tmp/bpfrejit-daemon/bd-<token>/daemon.stderr.log`. The
   "preserved failure workdir for prog X at ..." lines go there. The corpus driver
   already calls `_daemon_log_tail` on error. If the run fails completely (e.g.
   "empty socket response"), the daemon log tail is included in the Python exception
   message, which is surfaced in the corpus progress JSON and printed to stdout. That
   stdout is captured by the KVM guest script and written to the suite result file on
   the shared filesystem. To verify: look at `corpus/results/<run>/details/progress.json`
   — the error messages there may already contain the daemon stderr tail, including the
   per-prog error strings with the kernel errno.

2. **Check the incremental result JSON for per-prog errors.** The corpus driver writes
   `_write_incremental_app_result` for each app as it completes. For tetragon (which
   crashed the daemon mid-batch), the per-prog `rejit_result` field may already contain
   the per-prog error strings including the kernel errno (the daemon returns these in
   the `optimize` response, line 679 of corpus/driver.py). Check
   `details/apps/tetragon__*.json` if it exists in the v7 run directory.

3. **Fix the bind-mount so workdirs land on host.** The cleanest fix is to change
   `daemon/src/main.rs:FAILURE_ROOT` to use the corpus result `details/failures/`
   directory, or to add a bind-mount of `/var/tmp/bpfrejit-failures` in
   `suite_commands.py`. Pending task P89-116 (`P89-SimplifyFailure`) already targets
   this.

## Recommended Next Step

The multi-subprog guard commits (`858ddd97`, `bad918ea`) should already be in main.
Verify the v7 run was built from an image that INCLUDES those commits. If the image
predates them, rebuild the image and rerun. If the image is current and rejections
still occur, check the incremental result JSON for actual kernel errno (option 2
above) — this requires no code change and no new KVM run.

Do not attempt to directly read `/var/tmp/bpfrejit-failures` on the host — that path
is inside the ephemeral guest disk and is gone after the run exits.
