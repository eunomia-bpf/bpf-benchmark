# Step 0055 — KVM `make negative-test` at `7a0da65f0`

Date: 2026-09-30 UTC (make launch 08:00:27Z; in-VM suite
2026-09-30T08:05:11Z → 08:05:15Z, ~4 s in-VM; VM power-down
~08:05:16Z)

## Scope

Plain `make negative-test` (default `PLATFORM=kvm`, `ARCH=x86`, zero
knobs). The target is intended (`TEST_MODE ?= negative`, Makefile:227) to
run the dedicated negative-only suite (`_run_negative_mode`,
`fuzz=False`, writes `negative.log`, no micro smoke).

**Observed shape = test-mode, not negative-mode.** The run executed the
three-section `test`-mode suite — `native_proof micro smoke`,
`native_proof verifier rejection smoke`, `BPF verifier negative smoke` —
and wrote a `native_proof_micro_<ts>/` dir, **not** a `negative.log`.
Root cause, confirmed by `make -n` dry runs of `negative-test`,
`test`, and `selftest`: the KVM `vng --exec "make -C … __runtime-vm-test
$(RUN_MAKE_VARS)"` command line carries **no `TEST_MODE`** (only
`SAMPLES='3' FUZZ_ROUNDS='1000' MERLIN_COMPILETIME_MODE='none'`). The
target-specific `TEST_MODE ?=` value does not propagate in-VM, so the
in-VM Python suite fell back to its default
`env_str("TEST_MODE","test")` (`runner/suites/test.py:48`). All three
test-family targets (selftest / negative-test / test) therefore run the
default test-mode suite on the KVM path. This is a wiring gap in the
frozen benchmark Makefile — recorded as-is, not patched (frozen), and not
treated as a gate. The shared `BPF verifier negative smoke` section (the
substance of "negative": the verifier must reject invalid programs) still
ran and passed as part of the test-mode suite.

## Result

- Run token `tests/results/4dca07ca/`; artifact
  `tests/results/4dca07ca/native_proof_micro_20260930_080511_037492/`
  `status: completed`, `run_type: native_proof_micro` (in-VM
  08:05:11 → 08:05:15Z).
- `details/progress.json` `completed_benchmarks: 29 /
  total_benchmarks: 29`.
- **All 29 `native_proof` benchmarks matched** their
  `expected_result`/`expected_retval` (`runtime=native_proof`,
  `--samples 1 --warmups 0 --inner-repeat 1`).
- `BPF verifier negative smoke`: **PASS** `valid_xdp_pass`;
  `invalid_opcode` (errno=22/EINVAL); `stack_oob_write`
  (errno=13/EACCES); `uninitialized_register` (errno=13/EACCES) —
  invalid BPF programs rejected by the verifier as required.
- `native_proof verifier rejection smoke`: **PASS
  `unchecked_packet_read rejected rc=1`** (the unsafe `off=64` read
  rejected as required).
- Log: **0 error markers** (no `make ***`, `FAILED`, `fatal`, `Aborted`,
  `Terminated`, `did not match`, `unexpectedly succeeded`); clean VM
  power-down.

## Evidence pointers

- `make-negative-test.log` (this dir): retained host log (clean
  power-down).
- `run-marker.txt` (this dir).
- `tests/results/4dca07ca/` run dir: tracked `metadata.json`,
  `details/result.json`, `details/progress.json`, all 30
  `details/code_compare/*.md` (`git check-ignore` reports 0 ignored; 32
  files total).

## Caveats

- TEST_MODE did not propagate in-VM on the KVM path (gap above), so the
  dedicated negative-only suite (which writes `negative.log`, no micro
  smoke) was **not** exercised; the BPF-verifier-negative substance was
  covered by the shared test-mode section instead. Forcing the dedicated
  shape would require `TEST_MODE=negative` to reach in-VM (outside the
  zero-knob rule) or a frozen-Makefile fix — recorded as an open item,
  not a gate.
- `FUZZ_ROUNDS=1000` is a no-op on the non-fuzz path (the fuzz section
  is exercised by the fuzz mode, not this target).
- No ratio / geomean / rollup computed here (raw sample counters only;
  cross-start comparison is analysis per `docs/evaluation.md` §5).

## Open

- TEST_MODE propagation gap in the KVM in-VM target (frozen Makefile):
  `selftest` / `negative-test` / `test` all run the default test-mode
  suite; the dedicated negative-only suite (`negative.log`) is not
  produced by a zero-knob `make negative-test`. Recorded for follow-up;
  not a blocker.
- `PLATFORM=aws ARCH=arm64` within caps — **blocked on credentials**:
  no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials land.
