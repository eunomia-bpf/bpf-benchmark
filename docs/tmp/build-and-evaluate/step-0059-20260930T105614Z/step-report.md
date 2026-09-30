# Step 0059 — QEMU arm64 `make corpus` full default suite (zero knobs) at `2201b2375`

Date: 2026-09-30 UTC (make launch 10:56:14Z, make PID 863149; arm64 build
chain 10:56 → 11:01Z; QEMU run 11:01 → ~11:41Z, in-VM ~39 min; QEMU power-down
at in-VM ~2367 s)

## Scope

`PLATFORM=qemu ARCH=arm64 make corpus` (zero knobs; `SAMPLES=3`,
`WORKLOAD_DURATION=30s`, `WARMUPS=1`, `skip_rejit=false`; full default
suite `corpus/config/macro_apps.yaml`, all 6 apps `tracee`/`tetragon`/
`bcc`/`katran`/`cilium`/`otelcol-ebpf-profiler`, arm64 pass group `full`
per `corpus/config/benchmark_config.yaml` `platforms.arm64`). This is the
**arm64 whole-corpus counterpart of the KVM x86 full-corpus runs
0051/0056** (`42e1c4e37` / `c37b6b539`). It exercises the local QEMU arm64
path (`corpus-qemu-arm64`, Makefile:278–293), a public Makefile target
needing **no** external credentials (unlike `PLATFORM=aws ARCH=arm64`,
the credential-blocked line).

## Result

- Run dir `corpus/results/arm64_qemu_corpus_19700101_000006_146493/`
  (QEMU in-VM clock is 1970 — no RTC; `metadata.json` `completed_at:
  None`, `generated_at` 1970, `run_type: arm64_qemu_corpus` — recorded
  as a QEMU clock quirk, not a gate).
- **Suite `status: error`** (`details/result.json`);
  `details/progress.json` `status: error`,
  `error_message: "corpus suite reported errors"`, `failed_at` 1970.
- **All 6 apps `status: error`**, each with a distinct recorded error —
  none hidden/gated. Cross-arch signature: the **baseline** start of the
  two-start protocol works (shim tracks BPF programs; raw
  `run_cnt_delta`/`run_time_ns_delta` captured) for 5/6 apps, but the
  **`post_rejit_start` phase (`BPFREJIT_SHIM_LOADTIME_PLAN`) fails for
  all 6**. `details/apps/<app>.json` `post_rejit` is `null` for every
  app. This contrasts with KVM x86 0051/0056, where all 6 apps
  completed and `post_rejit` carried `run_cnt_delta`/`run_time_ns_delta`.

### Per-app recorded errors + raw counters (no ratio / geomean computed)

- **`bcc/set`** → `no tracked BPF programs`. Baseline captured hot progs:
  `sys_enter` `run_cnt_delta=2037428`, `sys_exit` `2037321`,
  `sched_switch` `869618`, `sched_wakeup` `510175`,
  `fentry_vfs_open` `86484`; 3 stress-ng `--syscall` workload samples
  rc=0, dur ~31–38 s. `post_rejit: null`.
- **`otelcol-ebpf-profiler/profiling`** → `no tracked BPF programs`.
  Baseline hot: `native_tracer_engine` `run_cnt_delta=259770`; workload
  samples rc=None (otel_mixed_workload, no rc/dur fields). `post_rejit:
  null`.
- **`cilium/agent`** → `Remote end closed connection without response;
  cilium-agent output tail: …Start hook executed…`. Baseline hot:
  `cil_from_container` `run_cnt_delta=4216666`/`4215728`,
  `cil_xdp_entry` `1`. `post_rejit: null`.
- **`katran`** → `Katran server did not expose an attached XDP program on
  katran0`. Baseline hot: `balancer_ingress` `run_cnt_delta=17595617`; 3
  xdp_pktgen samples rc=0, dur ~32 s. `post_rejit: null`.
- **`tetragon/observer`** → `Tetragon exited before BPF programs were
  tracked by shim` (`rejit_result: null`; **failed at baseline**, no
  baseline BPF data, no `loadtime-reports/tetragon__observer.jsonl`).
- **`tracee/monitor`** → `failed to launch Tracee: /artifacts/tracee/bin/
  tracee --events '*' …`. Baseline captured hot progs:
  `trace_sys_enter` `run_cnt_delta=1067318`, `trace_sys_exit` `1066348`,
  `tracepoint_raw_sys_enter/exit` `1067308`/`1066359`,
  `tracepoint_sched_wakeup` `226228`; 3 stress-ng `--cap` samples rc=0,
  dur ~31 s. `post_rejit: null` (post-rejit tracee launch failed).

## Cross-arch observation (raw, no ratio computed)

On QEMU arm64 the **post-rejit (loadtime-plan) path does not yet
complete** for any of the 6 apps, whereas on KVM x86 (0051/0056) all 6
completed and recorded `post_rejit` `run_cnt_delta`/`run_time_ns_delta`.
The baseline start still records raw BPF counters for 5/6 apps on arm64
(tetragon fails early at baseline). No ratio / geomean / rollup computed
here — cross-arch / cross-runtime comparison is analysis per
`docs/evaluation.md` §5.

## Evidence pointers

- `make-corpus-arm64.log` (this dir): retained host log (clean QEMU
  power-down, `qemu-status=0`).
- `run-marker.txt` (this dir).
- `corpus/results/arm64_qemu_corpus_19700101_000006_146493/` (14
  trackable files: `metadata.json`, `details/progress.json`,
  `details/result.json`, 6× `details/apps/*.json`, 5×
  `details/loadtime-reports/*.jsonl` — tetragon's `.jsonl` absent because
  it failed before the shim tracked programs; `git check-ignore`
  confirms `details/shim-logs/` + `details/loadtime-plans/` stay
  gitignored).

## Caveats

- `PLATFORM=aws ARCH=arm64` (the AWS line, not the local QEMU line)
  remains **blocked on credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30:
  no `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.
- QEMU in-VM clock is 1970 (no RTC); `completed_at`/`generated_at`
  reflect that, recorded as a quirk.
- The all-6-app post-rejit failure on arm64 is a **recorded capability
  gap** (surfaces naturally in the per-app `error` field and the suite
  `status: error`), not a hidden/gated result; it is recorded here
  additively and not relabeled/dropped.
- No ratio / geomean / rollup computed here (raw per-app
  `run_cnt_delta`/`run_time_ns_delta` + workload counters only;
  cross-arch / cross-runtime comparison is analysis per
  `docs/evaluation.md` §5).
