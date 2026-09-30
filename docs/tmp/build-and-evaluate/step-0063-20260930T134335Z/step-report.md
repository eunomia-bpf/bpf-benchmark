# Step 0063 — QEMU arm64 `make negative-test` gate (zero knobs)

- **Command**: `PLATFORM=qemu ARCH=arm64 make negative-test` (zero knobs;
  `TEST_MODE=negative`, `runner.suites.test`, Makefile:227/233).
- **Purpose**: final target-parity entry — completes the 5-target ×
  2-platform matrix on the arm64 line (KVM x86 ran all 5 targets).
  `negative-test` mode = BPF-verifier negative suite (non-fuzz) plus the
  native-proof micro / native-proof-rejection smoke that the shared
  `__runtime-vm-test` recipe always schedules. The arm64 counterpart of the
  KVM x86 negative-test (increment 16 lineage).
- **Prev HEAD**: `6739525f3` (= `origin/master`). Launched 13:43:35Z, make
  PID 928270, exited 13:50:23Z.
- **Result dir**: `tests/results/30da2a6e/` (token-based; nested run dir
  `native_proof_micro_19700101_000013_504093/`; QEMU in-VM clock is 1970 —
  no RTC, recorded quirk, not a gate).

## Gate result: PASS (5 PASS / 0 FAIL)

- BPF verifier negative smoke: `PASS valid_xdp_pass`, `PASS invalid_opcode
  errno=22`, `PASS stack_oob_write errno=13`, `PASS uninitialized_register
  errno=13`.
- native_proof verifier rejection: `PASS unchecked_packet_read rejected
  rc=1` (aarch64-sim XDP negative — `invalid access to packet, off=64` →
  `-EACCES`, expected).
- 5 PASS / 0 FAIL in `make-negative-test-arm64.log` (lines 17026–17034).

## Bonus: native-proof micro staged-codegen 29/29 completed

`suite=micro_staged_codegen` (manifest `micro/config/micro_pure_jit.yaml`):
`progress.json` `status: completed` 29/29; `metadata.json` `status:
completed`, `run_type=native_proof_micro`. No ratio/geomean/rollup computed.

## KEY FINDING: TEST_MODE does not reach the QEMU arm64 in-VM run

The pre-run prediction ("thinnest gate — BPF-negative-only, ~4 PASS / ~2
files / no nested run dir") was **WRONG** for the actual execution path.
Actual: 5 PASS / 32 files / nested run dir — i.e. the **full default
`test`-mode gate**, not the `negative`-only gate the target name implies.

- **Mechanism**: `Makefile:226-228` sets the target-specific
  `TEST_MODE ?= selftest|negative|test`. But `RUN_MAKE_VARS`
  (`Makefile:192-193`) is **simply expanded at definition time** with
  `$(foreach v,$(SUITE_ENV_NAMES),$(if $($(v)),$(v)='$($(v))'))`; at that
  point `TEST_MODE` is still empty (the target-specific `?=` is applied
  later, during the target's recipe), so the `$(if ...)` guard drops it.
  The QEMU arm64 recipe bakes `$(RUN_MAKE_VARS)` into the generated
  `/qemu-run.sh` (`Makefile:235`), and that script's `export` line therefore
  contains only `TARGET/RUN_TARGET_NAME/RUN_TARGET_ARCH/RUN_EXECUTOR/
  RUNTIME_CONTAINER_IMAGE/RUNTIME_IMAGE_TAR/RUN_REMOTE_PYTHON_BIN/
  RUN_RUNTIME_PYTHON_BIN/RUN_BPFTOOL_BIN/RUN_NATIVE_REPOS_CSV/RUN_TOKEN/
  SAMPLES='3'/FUZZ_ROUNDS='1000'/MERLIN_COMPILETIME_MODE='none'` — **no
  `TEST_MODE`**.
- **In-VM consequence**: `runner/suites/test.py:48`
  `args.test_mode = env_str("TEST_MODE", "test")` falls back to the default
  `test` mode. Because `_mode_needs_bpf_stats` includes `test`
  (`test.py:501`), bpf_stats is enabled — the gate ran as the superset
  full `test`-mode gate, not the thin `negative`-only path.
- **Evidence**: `make -n PLATFORM=qemu ARCH=arm64 {test,selftest,
  negative-test}-qemu-arm64` shows **0 mentions** of `TEST_MODE` in the
  printf-baked script for all three targets; an explicit command-line
  `TEST_MODE=negative` **does** propagate (isolating the target-specific
  `?=` as the culprit, not the `RUN_MAKE_VARS` plumbing itself).
- **Scope of impact**: 0061 (`make test`), 0062 (`make selftest`), 0063
  (`make negative-test`) on QEMU arm64 **all** actually executed the same
  default `test`-mode full gate; the `negative`/`selftest` target names were
  nominal-only on this launch path. Cross-arch check: the KVM x86 host
  sub-make line (`Makefile:230`, `__runtime-vm-test`) **also** omits
  `TEST_MODE` for all three gate targets (0 mentions in `make -n`); the
  in-VM `__runtime-vm-test` env-inheritance path (`export $(SUITE_ENV_NAMES)`
  at `Makefile:183`) is unconfirmed and left as a read-only open question.
- **Evidence quality is unaffected**: the full `test`-mode gate is the
  **superset** of what the `negative`/`selftest` modes would have run, so
  the 0061–0063 gate evidence remains valid (uniformly the full gate).
- **Recorded, not patched**: the launch wiring (`Makefile` + QEMU run-script
  generation) is frozen benchmark wiring; no fix is applied here. This is
  surfaced as a finding for user decision.

## Cross-arch readout (analysis per `docs/evaluation.md` §5, not a gate)

- The arm64 **target-parity matrix is now 5/5 complete** on QEMU arm64:
  micro (0058 clean), corpus ×2 (0059/0060 recorded failure,
  byte-identical/deterministic), test (0061 pass), selftest (0062 pass),
  negative-test (0063 pass). The matrix mirrors the 5 KVM x86 targets.
- Reaffirms the 0061 localization: the arm64 corpus post-rejit/load-time-
  plan failure remains the single open capability issue — specific to the
  load-time-plan/post-rejit path, **not** the verifier, kop modules,
  bpf_stats, or test infrastructure. No framework/app/runner change.
- The TEST_MODE launch-wiring gap above is a recorded finding (frozen
  wiring), not a new validity/admission gate; no ratio, geomean, or rollup
  was computed.

## Make + QEMU hygiene

- Log `make-negative-test-arm64.log` (17039 lines): clean `sysrq: Power Off`
  / `reboot: Power down`; `test "$(cat .cache/qemu-arm64-root/qemu-status)"
  = "0"` passed before the host copy; 0 real make error markers. The make
  target exits 0.
- 32 trackable files under the run dir committed (token + nested run dir:
  `metadata.json`, `details/progress.json`, `details/result.json`, 29×
  `details/code_compare/*.md`).
