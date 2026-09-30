# Step 0057 — KVM `make micro` full default suite (zero knobs) at `c37b6b539`

Date: 2026-09-30 UTC (make launch 09:29:04Z, make PID 770720; in-VM
suite 09:33:45Z → ~09:36Z; VM power-down at in-VM ~175 s)

## Scope

Plain `make micro` (default `PLATFORM=kvm`, `ARCH=x86`, zero knobs;
`SAMPLES=3`, `WARMUPS=0`, `INNER_REPEAT=100000` defaults; no `BENCH`
selector → full default suite `micro/config/micro_pure_jit.yaml`, all 29
workload-derived benchmarks, all 3 runtimes `native`/`llvmbpf`/`kernel`).
Prior micro runs in this session were single-bench matched-value smokes
(BENCH=simple, bcc_runqlat_log2_histogram_bucket,
cgroup_skb_hash_chain, packet_toeplitz_rss_hash,
bpf_local_call_fanout_dispatch); this zero-knob run is the
canonical **whole-micro-suite** timing artifact — the 29-bench
counterpart to the whole-corpus runs (0051 canonical + 0056 variance).

## Result

- Run dir `micro/results/x86_kvm_micro_20260930_093345_919079/`
  (the micro suite records no run token; the dir name
  `<target>_micro_<UTC ts>_<pid-suffix>` is the run identifier);
  `details/progress.json` `status: completed`, `completed_benchmarks:
  29 / total_benchmarks: 29`, `current_benchmark: null`.
- **All 29 × 3 runtimes × 3 samples = 261 samples matched** their
  `expected_result`/`expected_retval` (`result`/`retval` per sample);
  **0 mismatches**. Runtimes covered: `native`, `llvmbpf`, `kernel`.
- Raw per-sample timing recorded for every bench × runtime × sample:
  `compile_ns`, `exec_ns`, `wall_exec_ns`, `code_size.
  bpf_bytecode_bytes`/`native_code_bytes`, `phases_ns
  (memory_prepare_ns, native_load_ns)`, `timing_source:
  clock_monotonic`, `sample_index`.
- `details/code_compare/`: 29 per-bench JIT-dump comparison `.md`
  files (one per benchmark).
- Host log: **0 error markers** (no `make ***`, `Error N`, `FAILED`,
  `fatal`, `Aborted`, `Terminated`, `signal 15`, `did not match`,
  `unexpectedly succeeded`); clean VM power-down (`reboot: Power down`).

## Evidence pointers

- `make-micro.log` (this dir): retained host log (clean power-down).
- `run-marker.txt` (this dir).
- `micro/results/x86_kvm_micro_20260930_093345_919079/` (3 trackable
  files: `metadata.json`, `details/result.json`,
  `details/progress.json`; `git check-ignore` confirms
  `details/jit_dumps/` + `details/code_compare/` stay gitignored via
  `.gitignore` `micro/results/*/details/jit_dumps/` +
  `micro/results/*/details/code_compare/` rules, `!micro/results/**/*.
  json` negation for the .json files).

## Caveats

- No ratio / geomean / rollup computed here (raw per-sample
  `result`/`retval`/`compile_ns`/`exec_ns`/`code_size` only; cross-
  runtime / cross-bench comparison is analysis per
  `docs/evaluation.md` §5).
- `INNER_REPEAT=100000` default (not the suite-config value); the raw
  timing is recorded as measured, not normalized.
- `PLATFORM=aws ARCH=arm64` within caps — **blocked on credentials**:
  no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); re-checked 2026-09-30
  (no `~/.aws`, no aws-cli profiles, no matching `.pem` on the host);
  resume when credentials land.
