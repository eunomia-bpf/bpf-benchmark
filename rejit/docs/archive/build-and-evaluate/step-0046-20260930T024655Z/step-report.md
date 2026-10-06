# Step 0046 — KVM micro bench `cgroup_skb_hash_chain` at `42553ea42`

Date: 2026-09-30 UTC (attempt 1 02:46:55Z interrupted; attempt 2 02:50Z →
02:54:41Z; VM suite ~02:54 → 02:55:58)

## Scope

Third micro increment on the KVM line, a bench of a *different shape* than
the two prior ones: `make micro BENCH="cgroup_skb_hash_chain" SAMPLES=1
WARMUPS=0 INNER_REPEAT=10` — default `PLATFORM=kvm ARCH=x86`, same
sanity knobs as steps 0042/0045, zero extra env vars. HEAD
`42553ea42` (= `origin/master` after step 0045). x86 image cached from
the step 0041 build. Bench profile: cgroup-skb hash chain over a 72-byte
staged input, tags `[cgroup-skb, pure-jit, non-xdp, kernel-only]`,
`expected_result 12027228624407116210`, `expected_retval 1`. This is the
first micro bench with `expected_retval != 2` and a non-XDP program type
(the prior two — `simple`, `bcc_runqlat_log2_histogram_bucket` — were
both staged XDP, retval 2).

## Attempt 1 — host-harness SIGTERM during VM boot (recorded)

First launch (02:46:55Z) was killed by `SIGTERM from pid 361074 (omp)`
during VM boot (`qemu-system-x86_64: terminating on signal 15`), before
any suite work: no run dir created. This is an external session-teardown
interrupt, not a suite failure. Preserved in
`make-micro-interrupted-attempt1.log`; noted in `run-marker.txt`.

## Attempt 2 — success

- Run `micro/results/x86_kvm_micro_20260930_025441_553888/`
  `status: completed` (`progress.json`: 1/1 benchmark completed); VM
  powered down cleanly; no make error markers in the 473-line retained
  log.
- All three runtimes matched `expected_result 12027228624407116210` /
  `retval 1` (result-correctness hold, same check as the step 0042/0045
  runs). Raw per-runtime sample-0 counters (`details/result.json`, raw
  only, no ratios):

  | runtime | `compile_ns` | `exec_ns` | `bpf_bytecode_bytes` | `native_code_bytes` |
  |---------|-------------|-----------|----------------------|---------------------|
  | native  | 34,931  | 209 | 936 | 561 |
  | kernel  | 1,187,083 | 294 | 936 | 520 |
  | llvmbpf | 9,658,372 | 455 | 936 | 275 |

  - `kernel` extras (raw): `jited_prog_len 520`, `xlated_prog_len 936`,
    `exec_cycles 1,329`, `tsc_freq_hz 3,686,055,316`,
    `timing_source ktime`/`timing_source_wall rdtsc`.
  - `llvmbpf` extras (raw): `exec_cycles 1,676`, `tsc_freq_hz
    3,686,108,108`, `timing_source rdtsc`/`timing_source_wall
    unavailable`.
- `details/jit_dumps/` on disk (ignored): `...__kernel__sample00.jited.bin`
  520 B, `...__kernel__sample00.xlated.bin` 936 B,
  `...__llvmbpf__sample00.jited.bin` 275 B — consistent with the
  `code_size` / `jited_prog_len` / `xlated_prog_len` fields.
- Tracked-file pattern identical to the step 0042/0045 micro runs:
  `metadata.json`, `details/result.json`, `details/progress.json`;
  `code_compare/` and `jit_dumps/` stay ignored.

## Evidence pointers

- `make-micro.log` (this dir): retained 473-line host log (attempt 2).
- `make-micro-interrupted-attempt1.log` (this dir): SIGTERM'd first launch.
- `run-marker.txt` (this dir): attempt-1 interruption note.
- `micro/results/x86_kvm_micro_20260930_025441_553888/` run dir.

## Caveats

- Single bench (`cgroup_skb_hash_chain`); the other pure-jit benches are
  out of scope for this increment.
- `SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` (same sanity knobs as steps 0042
  / 0045), not the default `SAMPLES=3` — a fast smoke, not a variance
  sample.
- Raw per-runtime counters only; no ratio, geomean, or rollup — analysis
  per `rejit/docs/evaluation.md` §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from step 0041
  build. Paper-B speculative evidence stays blocked.

## Open

- `PLATFORM=aws ARCH=arm64` micro/corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Genuine
  external blocker; resume when credentials land.
