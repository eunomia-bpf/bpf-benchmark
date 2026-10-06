# Step 0052 — KVM micro bench `packet_toeplitz_rss_hash` at `42e1c4e37`

Date: 2026-09-30 UTC (make launch 06:49:36Z; in-VM suite
2026-09-30T06:55:34Z, ~42 s in-VM; VM power-down ~06:56Z)

## Scope

Micro-bench increment on the KVM line: `make micro
BENCH=packet_toeplitz_rss_hash SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`
(default `PLATFORM=kvm`, `ARCH=x86`; only the BENCH selection + the
documented micro knobs, consistent with steps 0042/0045/0046).
`packet_toeplitz_rss_hash` is a packet-io XDP-class hash bench
(`io_mode: packet`, 54-byte packet input, Toeplitz/5-tuple RSS hash
codegen) — a distinct codegen class from the three micro benches
already evidenced this session (`simple`,
`bcc_runqlat_log2_histogram_bucket`, `cgroup_skb_hash_chain`).
HEAD `42e1c4e37` (= `origin/master` after step 0051). x86 image
cached; host kernel `7.3.0-070300rc3-generic`.

## Result

- Run `micro/results/x86_kvm_micro_20260930_065534_021869/`
  `metadata.json` `status: completed`; `details/progress.json`
  `completed_benchmarks: 1 / total_benchmarks: 1`.
- `details/result.json` bench `packet_toeplitz_rss_hash`
  (`expected_result: 13526464303109995596`, `expected_retval: 2`,
  `io_mode: packet`, tags `[packet, hash, toeplitz, rss, pure-jit]`):
  **all 3 runtimes MATCHED** expected result/retval, `INNER_REPEAT=10`:
  - `native`: `result=13526464303109995596` retval 2;
    `exec_ns=511`; `code_size` bpf 1808 / native 799 bytes.
  - `kernel`: `result=13526464303109995596` retval 2;
    `exec_cycles=14861068` (`tsc_freq_hz` ~3.686e9);
    `jited_prog_len=1090`, `xlated_prog_len=1808`;
    `object_load_ns` ~2.72 ms.
  - `llvmbpf`: `result=13526464303109995596` retval 2;
    `exec_cycles=3557`; `code_size` native 846 bytes;
    `jit_compile_ns` ~17.4 ms.
  - No ratio / geomean / rollup computed here (raw sample counters
    only; cross-start comparison is analysis per
    `rejit/docs/evaluation.md` §5).
- No error markers in the host log; suite `status: completed`.

## Evidence pointers

- `make-micro.log` (this dir): retained host log (clean power-down).
- `run-marker.txt` (this dir).
- `micro/results/x86_kvm_micro_20260930_065534_021869/` run dir:
  tracked `metadata.json`, `details/result.json`,
  `details/progress.json` (gitignore verdicts below).

## Caveats

- `SAMPLES=1` + `WARMUPS=0` + `INNER_REPEAT=10` — the documented micro
  quick-check form used in this session's prior micro increments
  (steps 0042/0045/0046); the expected-value check is the primary
  correctness assertion.
- Kernel JIT `exec_cycles` is far larger than llvmbpf's
  (14,861,068 vs 3,557) — expected for this kernel-only XDP-class
  bench under the in-VM measurement harness; recorded as-is.

## Open

- `PLATFORM=aws ARCH=arm64` micro/corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.
