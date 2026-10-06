# Step 0061 — QEMU arm64 `make test` gate (zero knobs)

- **Command**: `PLATFORM=qemu ARCH=arm64 make test` (zero knobs;
  `TEST_MODE=test`; `runner.suites.test` via
  `RUNTIME_SUITE_MODULE := runner.suites.test`, Makefile:228/233).
- **Purpose**: arm64 verification-gate counterpart of the KVM x86 `make test`
  suite (increment 14, `7a0da65f0`). Distinguishes a *load-time-plan /
  post-rejit-specific* arm64 gap from a broader one. The test-mode gate loads
  the kop modules, runs the BPF-verifier negative suite (non-fuzz), and runs
  the native-proof micro staged-codegen smoke. `test.py:351` skips the
  native-loader-shim smoke on non-`x86_64` (aarch64 auto-skip, recorded not
  patched).
- **Prev HEAD**: `76f47306f` (= `origin/master`). Launched 12:55:39Z, make
  PID 899323, qemu PID (in-VM) up ~60 s wall. Exited 13:02:25Z.
- **Result dir**: `tests/results/44d305d7/` (token-based; nested run dir
  `native_proof_micro_19700101_000013_259265/`; QEMU in-VM clock is 1970 —
  no RTC, recorded quirk, not a gate).

## Gate result: PASS (5 PASS / 0 FAIL)

- BPF verifier negative smoke (non-fuzz): `PASS valid_xdp_pass`,
  `PASS invalid_opcode errno=22`, `PASS stack_oob_write errno=13`,
  `PASS uninitialized_register errno=13`.
- native_proof verifier rejection smoke: `PASS unchecked_packet_read
  rejected rc=1` (aarch64-sim XDP negative — `invalid access to packet,
  off=64` → `-EACCES`, as expected).
- 5 `PASS`, 0 `FAIL` in `make-test-arm64.log` (excluding the
  `native_compat.h`/`BPF_CORE` macro-expansion note lines that happen to
  contain the token).

## Bonus: native-proof micro staged-codegen 29/29 completed

The test-mode gate also ran the native-proof micro staged-codegen suite
(`suite=micro_staged_codegen`, manifest `micro/config/micro_pure_jit.yaml`):
`details/progress.json` `status: completed`, `completed_benchmarks: 29 /
total_benchmarks: 29`. `details/result.json` `benchmarks[]` (29) each
`runs[]/samples[]` with `result`/`retval`/`compile_ns`/`exec_ns`
(`timing_source: ktime`); `metadata.json` `status: completed`,
`cpu_model: aarch64`. This is an additional arm64 QEMU clean-signal data
point (staged codegen path runs on aarch64), recorded alongside the gate
result. No ratio/geomean/rollup computed.

## Cross-arch readout (analysis per `rejit/docs/evaluation.md` §5, not a gate)

- **The arm64 `make test` gate passes** on QEMU (aarch64). The verifier,
  kop-module load, and native-proof micro staged-codegen all work on
  aarch64.
- The 0059/0060 arm64 corpus failure (all 6 apps `post_rejit: null`,
  `BPFREJIT_SHIM_LOADTIME_PLAN` start fails) is therefore **localized to the
  load-time-plan / post-rejit path**, not to the verifier, kop modules, or
  general test infrastructure. This sharpens the recorded arm64 capability
  gap: it is a post-rejit load-time-plan defect on aarch64, not a broad
  platform-level inability.
- KVM x86 remains the fully-passing reference (0051/0056 all-6 corpus
  completed; 0054 test suite pass).

## Make + QEMU hygiene

- Log `make-test-arm64.log`: clean `sysrq: Power Off` / `reboot: Power
  down`; `test "$(cat .cache/qemu-arm64-root/qemu-status)" = "0"` passed
  before the host copy; 0 real make error markers. The make target exits 0.
- 32 trackable files under the run dir committed (token dir + nested run
  dir: `metadata.json`, `details/progress.json`, `details/result.json`,
  29× `details/code_compare/*.md`).
