# Full Validation Final 2026-03-19

## Scope

- Activated virtualenv: `source /home/yunwei37/workspace/.venv/bin/activate`
- Only code change made for this task: `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
- No commit, no push
- VM runs were kept serial; `ps aux | grep -E 'qemu|vng' | grep -v grep` was empty before each new validation phase

## Task 1: Fix tools UAPI mirror

Initial diff between:

- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h`

showed that the `tools` mirror was missing these main-UAPI definitions:

- `BPF_PROG_JIT_RECOMPILE` in `enum bpf_cmd`
- The v5 JIT policy blob definitions after `BPF_F_RB_OVERWRITE`
  - `BPF_JIT_POLICY_MAGIC`
  - `BPF_JIT_POLICY_FORMAT_VERSION`
  - `BPF_JIT_ARCH_*`
  - `struct bpf_jit_policy_hdr`
  - `enum bpf_jit_canonical_form`
  - per-family native-choice enums
  - `struct bpf_jit_rewrite_rule_v2`
- `union bpf_attr.jit_recompile`

Action taken:

- Synced `vendor/linux-framework/tools/include/uapi/linux/bpf.h` to match the main UAPI exactly
- Re-ran `diff -u vendor/linux-framework/include/uapi/linux/bpf.h vendor/linux-framework/tools/include/uapi/linux/bpf.h`
- Result: zero diff

## Build and Selftest

- `cd vendor/linux-framework && make -j$(nproc) bzImage`
  - Passed
  - Result: `arch/x86/boot/bzImage is ready  (#61)`
- First `make vm-selftest` (task 1)
  - Passed
  - Result: `PASS all 19 test(s)`
- Second `make vm-selftest` (task 2 full validation rerun)
  - Passed
  - Result: `PASS all 19 test(s)`

## Task 2: Micro Validation

Run:

- `make vm-micro`

Artifact:

- `micro/results/dev/vm_micro.json`
- Generated: `2026-03-19T20:29:24.571062+00:00`

Run notes from the benchmark harness:

- CPU governor reported as `unknown` rather than `performance`
- Turbo boost enabled
- `perf_event_paranoid=2`
- No CPU affinity pinning

These warnings do not invalidate the run, but they do mean this is not a strict authoritative environment.

### Micro Summary

- Valid benchmarks: `62/62`
- Overall geomean (`stock / recompile`): `1.017239x`
- Applied-only geomean (`stock / recompile`): `1.078055x`
- Applied benchmarks in this run: `7`

### Applied Benchmarks

| Benchmark | Stock median ns | Recompile median ns | Ratio (`stock / recompile`) |
| --- | ---: | ---: | ---: |
| `bounds_ladder` | 140.0 | 139.0 | `1.007194x` |
| `bpf_call_chain` | 364.0 | 364.0 | `1.000000x` |
| `cmov_dense` | 38.0 | 36.0 | `1.055556x` |
| `large_mixed_1000` | 1090.5 | 1078.5 | `1.011127x` |
| `large_mixed_500` | 457.5 | 434.0 | `1.054147x` |
| `rotate64_hash` | 48.0 | 40.0 | `1.200000x` |
| `rotate_dense` | 170.5 | 137.0 | `1.244526x` |

### Recovery Check

Requested recovered applied set:

- `rotate_dense`
- `rotate64_hash`
- `cmov_dense`
- `large_mixed_500`
- `large_mixed_1000`
- `bounds_ladder`
- `bpf_call_chain`

Result:

- All 7 were present in the applied set for this run
- 6/7 showed `stock / recompile > 1.0`
- `bpf_call_chain` was flat at `1.000000x`
- No requested applied benchmark regressed below `1.0x`

## Task 2: E2E Validation

### What happened

Requested step:

- `make vm-e2e`

Observed behavior:

- `tracee` completed and wrote fresh results
- The first `tetragon` leg inside `make vm-e2e` caused `make` to exit with:
  - `make: *** [Makefile:369: vm-e2e] Error 255`

To finish validation with the same kernel and the same per-case commands, each E2E leg was then re-run manually, still one VM at a time:

- `tracee`: already fresh from the `make vm-e2e` attempt
- `tetragon`: re-run individually, succeeded
- `bpftrace`: re-run individually, succeeded
- `scx`: re-run individually, succeeded
- `katran`: failed twice reproducibly with the same error

Fresh artifacts from this validation:

- `e2e/results/dev/tracee.json` at `2026-03-19 13:59:58`
- `e2e/results/dev/tetragon.json` at `2026-03-19 14:07:53`
- `e2e/results/dev/bpftrace.json` at `2026-03-19 14:11:23`
- `e2e/results/dev/scx.json` at `2026-03-19 14:13:09`

No fresh `katran.json` / `katran.md` was produced because baseline failed before result persistence.

### Tracee

Artifact:

- `e2e/results/dev/tracee.json`
- Generated: `2026-03-19T20:59:58.634117+00:00`

Summary:

- Applied programs: `13 / 15`
- Applied successfully: `true`

Workload deltas (`post-ReJIT` vs baseline):

- `exec_storm`
  - app throughput: `-10.747420%`
  - events/s: `-10.824412%`
  - agent CPU: `-7.360089%`
  - BPF avg ns/run: `+22.676227%`
- `file_io`
  - app throughput: `-4.644681%`
  - events/s: `-0.046261%`
  - agent CPU: `+50.000091%`
  - BPF avg ns/run: `-11.935051%`
- `network`
  - app throughput: `-36.331797%`
  - events/s: `-36.315989%`
  - agent CPU: `-13.424380%`
  - BPF avg ns/run: `+48.732774%`

Interpretation:

- Recompile applied broadly, but this tracee run is net negative/mixed
- `file_io` shows a small throughput drop with lower BPF runtime
- `exec_storm` and especially `network` regress materially

### Tetragon

Artifact:

- `e2e/results/dev/tetragon.json`
- Generated: `2026-03-19T21:07:53.069574+00:00`

Summary:

- Applied programs: `3 / 7`
- Applied successfully: `true`

Per-program `stock / recompile` speedups for site-bearing programs:

- `event_exit_acct`: `0.371229x`
- `event_wake_up_n`: `0.547497x`
- `event_execve`: `0.497433x`
- `tg_kp_bprm_comm`: `0.989590x`
- `execve_rate`, `execve_send`, `execve_map_upda`: no comparable runtime delta available

Workload deltas (`post-ReJIT` vs baseline):

- `connect_storm`
  - app throughput: `+177.848089%`
  - agent CPU: `+156.499058%`
- `file_io`
  - app throughput: `+37.939924%`
  - agent CPU: `-69.999999%`
- `open_storm`
  - app throughput: `+20.608767%`
  - agent CPU: `+10.622142%`
- `stress_exec`
  - app throughput: `-17.554772%`
  - agent CPU: `-11.422501%`

Interpretation:

- Application-level results are mixed-positive
- But the site-bearing program-level `stock / recompile` ratios are mostly below `1.0`, so the applied JIT rewrites themselves are not a clear win in this tetragon run

### bpftrace

Artifact:

- `e2e/results/dev/bpftrace.json`
- Generated: `2026-03-19T21:11:23.058465+00:00`

Summary:

- Scripts selected: `5`
- Baseline successes: `5`
- ReJIT successes: `0`
- Eligible-site scripts: `3`
- Aggregate sites: `13`
- Geomean speedup: `n/a`

Per-script status:

- `open_latency`
  - sites: `6`
  - result: skipped
  - note: `policy filtered all live sites`
- `exec_trace`
  - sites: `0`
  - result: no eligible directive sites
- `scheduler_latency`
  - sites: `6`
  - result: skipped
  - note: `policy filtered all live sites`
- `vfs_read_count`
  - sites: `0`
  - result: no eligible directive sites
- `tcp_connect`
  - sites: `1`
  - result: no applied re-JIT comparison
  - note: `BPF_PROG_JIT_RECOMPILE did not apply`

Interpretation:

- The run itself succeeded, but there is no successful post-reJIT comparison
- So this workload currently provides validation of attachment and scanning, not validation of recompile benefit

### scx

Artifact:

- `e2e/results/dev/scx.json`
- Generated: `2026-03-19T21:13:09.112587+00:00`

Summary:

- Loaded programs: `13`
- Site-bearing programs: `11`
- Total sites: `213`
- Applied programs: `0 / 13`
- Comparable post-reJIT measurement: `false`
- Reason: `post-ReJIT measurements are unavailable`

Baseline only:

- `hackbench`: `6.280865` runs/s
- `stress-ng-cpu`: `11584.53` bogo-ops/s
- `sysbench-cpu`: `17629.39` events/s

Interpretation:

- The scheduler workload ran and loaded many site-bearing programs
- But `BPF_PROG_JIT_RECOMPILE` did not apply to any loaded `scx_rusty` program on this kernel, so there is no post-reJIT comparison

### katran

Status:

- Failed twice reproducibly
- No fresh JSON/MD artifact

Failure:

- `RuntimeError: live DSR request validation failed`
- Both attempts failed during baseline
- All 5 validation requests timed out in both runs

Representative error:

```text
RuntimeError: live DSR request validation failed: [{'index': 0, 'ok': False, 'error': 'timed out', 'bytes': 0, 'latency_ms': None, 'snippet': ''}, ...]
```

Interpretation:

- This is a real blocker for full E2E completion on the current environment/kernel state
- Because it fails before result persistence, there is no trustworthy `katran` comparison artifact to analyze

## Final Status

### Green

- UAPI mirror sync is fixed
- `bzImage` build passed
- `vm-selftest` passed twice (`19/19`)
- `vm-micro` passed with `62/62` valid
- All 7 expected applied micro benchmarks were restored in the applied set
- Fresh E2E results were produced for `tracee`, `tetragon`, `bpftrace`, and `scx`

### Not fully green

- `make vm-e2e` did not complete as a single Make target; it aborted at the first `tetragon` leg with `Error 255`
- Manual serial rerun showed `tetragon` itself can succeed, so the wrapper failure was not reproduced as a deterministic per-case failure
- `katran` failed twice reproducibly with baseline DSR timeouts, so full E2E completion is currently blocked

## Bottom Line

- The requested kernel-header sync is correct and verified by build + selftests
- Micro validation is successful and confirms recovery of the 7 target applied benchmarks
- E2E validation is only partially complete on this environment: `tracee/tetragon/bpftrace/scx` have fresh results, but `katran` is a reproducible blocker and therefore the overall E2E suite is not fully green
