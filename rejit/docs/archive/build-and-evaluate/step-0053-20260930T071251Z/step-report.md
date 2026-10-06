# Step 0053 — KVM micro bench `bpf_local_call_fanout_dispatch` at `cb1f966a3`

Date: 2026-09-30 UTC (make launch 07:12:51Z; in-VM suite
2026-09-30T07:17:32Z, ~42 s in-VM; VM power-down ~07:17:33Z)

## Scope

Micro-bench increment on the KVM line: `make micro
BENCH=bpf_local_call_fanout_dispatch SAMPLES=1 WARMUPS=0
INNER_REPEAT=10` (default `PLATFORM=kvm`, `ARCH=x86`; only the BENCH
selection + the documented micro knobs, consistent with steps
0042/0045/0046/0052). `bpf_local_call_fanout_dispatch` is a
BPF-to-BPF local-call codegen bench (`io_mode: staged`, 392-byte
input, tags `[call, bpf-to-bpf, local-call, reg-pressure,
pure-jit]`) — a distinct codegen class from the four micro benches
already evidenced this session (`simple`,
`bcc_runqlat_log2_histogram_bucket`, `cgroup_skb_hash_chain`,
`packet_toeplitz_rss_hash`). HEAD `cb1f966a3` (= `origin/master`
after step 0052). x86 image cached; host kernel
`7.3.0-070300rc3-generic`.

## Result

- Run `micro/results/x86_kvm_micro_20260930_071732_207339/`
  `metadata.json` `status: completed`; `details/progress.json`
  `completed_benchmarks: 1 / total_benchmarks: 1`.
- `details/result.json` bench `bpf_local_call_fanout_dispatch`
  (`expected_result: 1171593469689687806`, `expected_retval: 2`,
  `io_mode: staged`, tags `[call, bpf-to-bpf, local-call,
  reg-pressure, pure-jit]`): **all 3 runtimes MATCHED**
  expected result/retval, `INNER_REPEAT=10`:
  - `native`: `result=1171593469689687806` retval 2; `exec_ns=105`;
    `code_size` bpf 4,240 / native 291 bytes.
  - `kernel`: `result=1171593469689687806` retval 2;
    `exec_cycles=14,784,621`; `exec_ns=249`; `code_size` bpf 4,240
    / native 2,193 bytes.
  - `llvmbpf`: `result=1171593469689687806` retval 2;
    `exec_cycles=802`; `exec_ns=217`; `code_size` bpf 4,240 /
    native 869 bytes.
  - No ratio / geomean / rollup computed here (raw sample counters
    only; cross-start comparison is analysis per
    `rejit/docs/evaluation.md` §5).
- No error markers in the host log; suite `status: completed`.

## Evidence pointers

- `make-micro.log` (this dir): retained host log (clean power-down).
- `run-marker.txt` (this dir).
- `micro/results/x86_kvm_micro_20260930_071732_207339/` run dir:
  tracked `metadata.json`, `details/result.json`,
  `details/progress.json` (gitignore verdicts below).

## Caveats

- `SAMPLES=1` + `WARMUPS=0` + `INNER_REPEAT=10` — the documented
  micro quick-check form used in this session's prior micro
  increments; the expected-value check is the primary correctness
  assertion.
- Kernel JIT `exec_cycles` (14.78M) vs llvmbpf (802) — expected
  spread for a kernel-local-call codegen bench under the in-VM
  harness; recorded as-is.
- `code_size` bpf bytecode is 4,240 bytes (largest of the four
  micro benches evidenced so far, vs 1,808 / 72 / 64-class for the
  others) — the local-call fanout expands to multiple sub-programs;
  recorded as-is.

## Open

- `PLATFORM=aws ARCH=arm64` micro/corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.
