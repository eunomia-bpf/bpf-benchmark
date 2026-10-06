# Step 0054 — KVM `make test` suite at `e4471dcd2`

Date: 2026-09-30 UTC (make launch 07:33:35Z; in-VM suite
2026-09-30T07:38:17Z → 07:38:21Z, ~46 s in-VM; VM power-down
~07:38:22Z)

## Scope

`make test` (default `PLATFORM=kvm`, `ARCH=x86`; `TEST_MODE=test`,
`FUZZ_ROUNDS=1000` default — no knobs, matching the Makefile
target's own defaults). Runs `runner.suites.test` in-VM
(`__runtime-vm-test`, `RUNTIME_SUITE_MODULE=runner.suites.test`),
the last uncovered Make target on the KVM line alongside
selftest/micro/corpus. The `TEST_MODE=test` path executes three
sections:
1. `native_proof micro smoke` — the full 29-bench
   `micro_pure_jit.yaml` set under the `native_proof` runtime
   (`--samples 1 --warmups 0 --inner-repeat 1`), writing a
   `native_proof_micro_<ts>/` artifact under `tests/results/`.
2. `native_proof verifier rejection smoke` — `unchecked_packet_read`
   must be rejected by the verifier (expected
   `invalid access to packet, off=64 size=1` diagnostic, rc≠0).
3. `BPF verifier negative smoke` (`fuzz=False`) —
   `valid_xdp_pass` must load; `invalid_opcode` / `stack_oob_write`
   / `uninitialized_register` must fail.
HEAD `e4471dcd2` (= `origin/master` after step 0053). x86 image
cached; host kernel `7.3.0-070300rc3-generic`.

## Result

- Run token `tests/results/d83499ef/`; artifact
  `tests/results/d83499ef/native_proof_micro_20260930_073817_193862/`
  `metadata.json` `status: completed`, `run_type: native_proof_micro`
  (in-VM 07:38:17 → 07:38:21Z).
- `details/progress.json` `completed_benchmarks: 29 /
  total_benchmarks: 29`.
- `details/result.json`: **all 29 native_proof benchmarks matched**
  their `expected_result`/`expected_retval` (`runtime=native_proof`,
  29/29 samples). The 29-bench set spans the full
  `micro_pure_jit.yaml` catalog (incl. the four benches already
  evidenced standalone this session: `simple`,
  `bcc_runqlat_log2_histogram_bucket`, `cgroup_skb_hash_chain`,
  `packet_toeplitz_rss_hash` — the last re-confirmed here under
  `native_proof` with `result=13526464303109995596`); each bench's
  `code_compare/<bench>.md` (30 total incl. the negative proof) is
  tracked.
- Section 2 `native_proof verifier rejection smoke`:
  **PASS `unchecked_packet_read rejected rc=1`** (the unsafe
  `off=64` read was rejected, as required).
- Section 3 `BPF verifier negative smoke`: **PASS** `valid_xdp_pass`,
  `invalid_opcode` (errno=22/EINVAL), `stack_oob_write`
  (errno=13/EACCES), `uninitialized_register` (errno=13/EACCES).
- Log: **0 error markers** (no `make ***`, `FAILED`, `fatal`,
  `Aborted`, `Terminated`, `did not match`, `unexpectedly
  succeeded`); clean VM power-down.

## Evidence pointers

- `make-test.log` (this dir): retained host log (clean power-down).
- `run-marker.txt` (this dir).
- `tests/results/d83499ef/` run dir: tracked `metadata.json`,
  `details/result.json`, `details/progress.json`, all 30
  `details/code_compare/*.md` (gitignore verdicts below).

## Caveats

- `make test` here is `TEST_MODE=test` (no fuzz pass); the
  `FUZZ_ROUNDS=1000` knob is a no-op for the non-fuzz `test` path —
  the fuzz section is exercised by `make negative-test`/the fuzz
  mode instead. Recorded as-is.
- All native_proof samples are single-shot (`--samples 1`,
  `--inner-repeat 1`) — the expected-value check is the primary
  correctness assertion; no ratio / geomean / rollup computed here
  (raw sample counters only; cross-start comparison is analysis per
  `docs/evaluation.md` §5).
- `code_size`/`exec_ns`/`compile_ns` per bench are raw per-runtime
  counters recorded in the tracked JSON.

## Open

- `PLATFORM=aws ARCH=arm64` test within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.
