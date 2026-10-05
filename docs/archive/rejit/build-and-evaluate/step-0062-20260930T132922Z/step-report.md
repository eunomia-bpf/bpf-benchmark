# Step 0062 — QEMU arm64 `make selftest` gate (zero knobs)

- **Command**: `PLATFORM=qemu ARCH=arm64 make selftest` (zero knobs;
  `TEST_MODE=selftest`; `runner.suites.test`, Makefile:226/233).
- **Purpose**: completes the arm64 target-parity matrix (KVM x86 ran all 5
  targets). Selftest mode = kop modules + native-proof micro smoke +
  native-proof negative smoke + BPF-verifier negative suite (non-fuzz),
  plus `ensure_bpf_stats_enabled` (`_mode_needs_bpf_stats`,
  `test.py:487`), i.e. the full selftest path. The arm64 counterpart of the
  KVM x86 selftest (increment 2, step 0052 lineage).
- **Prev HEAD**: `d098e6530` (= `origin/master`). Launched 13:29:22Z, make
  PID 914605, exited 13:36:03Z.
- **Result dir**: `tests/results/3736936a/` (token-based; nested run dir
  `native_proof_micro_19700101_000013_422919/`; QEMU in-VM clock is 1970 —
  no RTC, recorded quirk, not a gate).

## Gate result: PASS (5 PASS / 0 FAIL)

- BPF verifier negative smoke: `PASS valid_xdp_pass`, `PASS invalid_opcode
  errno=22`, `PASS stack_oob_write errno=13`, `PASS uninitialized_register
  errno=13`.
- native_proof verifier rejection: `PASS unchecked_packet_read rejected
  rc=1` (aarch64-sim XDP negative — `invalid access to packet, off=64` →
  `-EACCES`, expected).
- 5 PASS / 0 FAIL in `make-selftest-arm64.log`.

## Bonus: native-proof micro staged-codegen 29/29 completed

`suite=micro_staged_codegen` (manifest `micro/config/micro_pure_jit.yaml`):
`progress.json` `status: completed` 29/29; `metadata.json` `status:
completed`, `run_type=native_proof_micro`. No ratio/geomean/rollup computed.

## Cross-arch readout (analysis per `docs/evaluation.md` §5, not a gate)

- Selftest (the fullest gate mode — includes `ensure_bpf_stats_enabled`,
  which `test` mode also needs but `negative` mode does not) **passes on
  aarch64 QEMU**, re-confirming 0061's passing-gate result with stats
  enabled.
- Target-parity matrix now complete for QEMU arm64: micro (0058 clean),
  corpus ×2 (0059/0060 recorded failure, deterministic), test (0061 pass),
  selftest (0062 pass). Only `negative-test` remains.
- Reaffirms the 0061 localization: the arm64 corpus post-rejit failure is
  specific to the load-time-plan/post-rejit path, not the verifier, kop
  modules, bpf_stats, or test infrastructure. No framework/app change.

## Make + QEMU hygiene

- Log `make-selftest-arm64.log`: clean `sysrq: Power Off` / `reboot: Power
  down`; `test "$(cat .cache/qemu-arm64-root/qemu-status)" = "0"` passed
  before the host copy; 0 real make error markers. The make target exits 0.
- 32 trackable files under the run dir committed (token + nested run dir:
  `metadata.json`, `details/progress.json`, `details/result.json`, 29×
  `details/code_compare/*.md`).
