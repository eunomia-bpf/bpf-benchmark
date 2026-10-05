# Step 0045 — KVM micro bench `bcc_runqlat_log2_histogram_bucket` at `944ff6fb7`

Date: 2026-09-30 UTC (run 02:23:11Z → 02:24:14Z; ~4.8 min wall, cached
image)

## Scope

Second micro increment on the KVM line, a non-`simple` pure-jit bench to
extend the step 0042 micro-sanity evidence:
`make micro BENCH="bcc_runqlat_log2_histogram_bucket" SAMPLES=1 WARMUPS=0
INNER_REPEAT=10` — default `PLATFORM=kvm ARCH=x86`, zero extra env vars
beyond the bench knob. HEAD `944ff6fb7` (= `origin/master` after step 0044).
x86 image cached from the step 0041 build. Bench profile: BCC-style `log2`
histogram bucketing over a 1032-byte staged input, tags
`[bcc, tracing, log2, histogram, pure-jit]`, `expected_result
17790125373615940312`, `expected_retval 2`.

## Verification

- Suite `status: completed` (`progress.json`: 1/1 benchmark completed); VM
  powered down cleanly; no make error markers in the 473-line retained log.
- All three runtimes matched `expected_result 17790125373615940312` /
  `retval 2` (result-correctness hold, same check as step 0042's
  `12345678` for `simple`). Raw per-runtime sample-0 counters
  (`details/result.json`, raw only, no ratios):

  | runtime | `compile_ns` | `exec_ns` | `bpf_bytecode_bytes` | `native_code_bytes` |
  |---------|-------------|-----------|----------------------|---------------------|
  | native  | 33,855     | 1,952 | 1,416 | 340 |
  | kernel  | 79,885,857 | 2,023 | 1,368 | 720 |
  | llvmbpf | 12,549,987 | 1,213 | 1,416 | 434 |

  - `kernel` extras (raw): `jited_prog_len 720`, `xlated_prog_len 1368`,
    `exec_cycles 14,822,490`, `tsc_freq_hz 3,686,168,041`,
    `timing_source ktime`/`timing_source_wall rdtsc`.
  - `llvmbpf` extras (raw): `exec_cycles 4,470`, `tsc_freq_hz
    3,686,226,999`, `timing_source rdtsc`/`timing_source_wall
    unavailable`.
- `details/jit_dumps/` on disk (ignored): `...__kernel__sample00.jited.bin`
  720 B, `...__kernel__sample00.xlated.bin` 1,368 B,
  `...__llvmbpf__sample00.jited.bin` 434 B — consistent with the
  `code_size` / `jited_prog_len` / `xlated_prog_len` fields.
- Tracked-file pattern identical to step 0042 (`micro/results/x86_kvm_micro_20260930_001655_090124/`):
  `metadata.json`, `details/result.json`, `details/progress.json`;
  `code_compare/` and `jit_dumps/` stay ignored.

## Evidence pointers

- `make-micro.log` (this dir): retained 473-line host log.
- `run-marker.txt` (this dir).
- `micro/results/x86_kvm_micro_20260930_022413_595750/` run dir.

## Caveats

- Single bench (`bcc_runqlat_log2_histogram_bucket`); the other 24 pure-jit
  benches are out of scope for this increment.
- `SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` (same sanity knobs as step 0042),
  not the default `SAMPLES=3` — a fast smoke, not a variance sample.
- Raw per-runtime counters only; no ratio, geomean, or rollup — analysis
  per `docs/evaluation.md` §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from step 0041
  build. Paper-B speculative evidence stays blocked.

## Open

- `PLATFORM=aws ARCH=arm64` micro/corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Record as a
  genuine external blocker; resume when credentials land.
