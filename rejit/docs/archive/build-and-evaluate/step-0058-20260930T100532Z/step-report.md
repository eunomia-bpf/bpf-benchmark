# Step 0058 — QEMU arm64 `make micro` full default suite (zero knobs) at `840c2ed47`

Date: 2026-09-30 UTC (make launch 10:05:32Z, make PID 786540; arm64 build
chain 10:05 → ~10:22Z (kernel `Image` check + cilium daemon Go build +
arm64 BPF artifacts + arm64 runner-runtime image build, Docker stage #30+);
QEMU run ~10:22 → ~10:36Z; QEMU power-down at in-VM ~845 s)

## Scope

`PLATFORM=qemu ARCH=arm64 make micro` (zero knobs; `SAMPLES=3`,
`WARMUPS=0`, `INNER_REPEAT=100000` defaults; no `BENCH` selector → full
default suite `micro/config/micro_pure_jit.yaml`, all 29
workload-derived benchmarks, all 3 runtimes `native`/`llvmbpf`/`kernel`).
This is the **arm64 cross-arch counterpart of the step-0057 KVM
full-suite micro run** (`840c2ed47`). It exercises the local QEMU arm64
path (`micro-qemu-arm64`, Makefile:278–293), which is a public Makefile
target needing **no** external credentials (unlike
`PLATFORM=aws ARCH=arm64`, which is the credential-blocked line). All
prerequisites were present on the host: `qemu-system-aarch64`
(0x20 bin), arm64 kernel `vendor/build/arm64/linux/arch/arm64/boot/Image`
(42 MB), prepared `qemu-arm64-root/qemu-init`, and the 680 MB arm64
runner-runtime image tar — the arm64 build chain (kernel check, cilium
daemon Go cross-build, BPF artifacts, runtime image) still ran as part
of the target.

## Result

- Run dir `micro/results/arm64_qemu_micro_recorded_20260930_vmclock_000008_942047/`
  (the QEMU in-VM clock is 1970 — no RTC set in the VM; the dir name
  and `metadata.json` `completed_at` reflect that, not a real timestamp;
  recorded as a QEMU clock quirk, not a gate).
- `details/progress.json` `status: completed`,
  `completed_benchmarks: 29 / total_benchmarks: 29`,
  `current_benchmark: null`.
- **All 29 × 3 runtimes × 3 samples = 261 samples matched** their
  `expected_result`/`expected_retval` (`result`/`retval` per sample);
  0 mismatches; runtimes covered `native`, `llvmbpf`, `kernel`.
- Raw per-sample timing recorded for every bench × runtime × sample:
  `compile_ns`, `exec_ns`, `wall_exec_ns`, `code_size.
  bpf_bytecode_bytes`/`native_code_bytes`, `phases_ns
  (memory_prepare_ns, native_load_ns)`, `timing_source:
  clock_monotonic`, `sample_index`.
- `details/code_compare/`: 29 per-bench JIT-dump comparison `.md`
  files (one per benchmark).
- QEMU exit clean: `qemu-status` = `0`; in-VM `sysrq: Power Off` +
  `reboot: Power down`; 0 real error markers (the only two `panic`
  hits in the host log are the kernel cmdline string
  `panic=30 oops=panic`, not a fault).

## Cross-arch observation (raw, no ratio computed)

arm64 sample values differ from the x86 KVM full-suite run (0057) as
expected — e.g. `simple`: native/llvmbpf/kernel `exec last` 21/39/103 ns
(x86) vs `compile last` arm64 native ~6.3–8.9 ms, llvmbpf ~2.3–2.5 s,
kernel ~65–888 µs across the 29 benches; `result` values are the
same deterministic per-bench expected values on both arches (the
matched-value check is arch-independent). No ratio / geomean / rollup
computed here — cross-arch comparison is analysis per
`rejit/docs/evaluation.md` §5.

## Evidence pointers

- `make-micro-arm64.log` (this dir): retained host log (clean QEMU
  power-down, `qemu-status=0`).
- `run-marker.txt` (this dir).
- `micro/results/arm64_qemu_micro_recorded_20260930_vmclock_000008_942047/` (3
  trackable files: `metadata.json`, `details/result.json`,
  `details/progress.json`; `git check-ignore` confirms
  `details/jit_dumps/` + `details/code_compare/` stay gitignored via
  `.gitignore` `micro/results/*/details/jit_dumps/` +
  `micro/results/*/details/code_compare/` rules,
  `!micro/results/**/*.json` negation for the .json files).

## Caveats

- `PLATFORM=aws ARCH=arm64` (the AWS line, not the local QEMU line)
  remains **blocked on credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30:
  no `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.
- QEMU in-VM clock is 1970 (no RTC); `completed_at` / dir name reflect
  that, recorded as a quirk.
- `INNER_REPEAT=100000` default; raw timing recorded as measured, not
  normalized.
- No ratio / geomean / rollup computed here (raw per-sample
  `result`/`retval`/`compile_ns`/`exec_ns`/`code_size` only;
  cross-arch / cross-runtime comparison is analysis per
  `rejit/docs/evaluation.md` §5).
