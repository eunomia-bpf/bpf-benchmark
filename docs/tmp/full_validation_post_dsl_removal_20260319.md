# Full Validation Post DSL Removal - 2026-03-19

## Status

This validation run is **incomplete / mixed-state**.

- `vm-micro` completed.
- `vm-e2e` partially completed:
  - `tracee` completed.
  - `tetragon` failed / hung under the current guest kernel and produced no JSON.
  - `bpftrace` completed.
  - `scx` completed.
- `vm-corpus REPEAT=200` was **aborted** after the harness reported that kernel sources were newer than `bzImage` and started rebuilding the kernel.

Because the kernel / repo state changed underneath the run, the results below should be treated as a **partial checkpoint**, not a final authoritative validation.

## Build-State Divergence

Initial checks before `vm-micro`:

- No `qemu` / `vng` processes.
- `bzImage`: `vendor/linux-framework/arch/x86/boot/bzImage`
- Timestamp observed at start: `2026-03-19 12:00`

`vm-micro` / `vm-e2e` ran with:

- Kernel commit reported by harness: `8c70a729d`
- Scanner commit reported by harness: `7d85607`

When `vm-corpus` started, the harness reported:

- `WARNING: kernel source is newer than bzImage — consider: make kernel`
- Kernel commit now reported by harness: `53cd480804`
- Scanner / repo commit now reported by harness: `be31e64297`
- `bzImage` timestamp observed later: `2026-03-19 12:40:45`

Current worktree snapshot observed after interruption:

- Top-level `HEAD`: `be31e64297`
- `vendor/linux-framework` `HEAD`: `53cd480804`
- `vendor/linux-framework` has local modifications in:
  - `include/linux/bpf.h`
  - `include/uapi/linux/bpf.h`
  - `kernel/bpf/jit_directives.c`
  - `kernel/bpf/syscall.c`
  - `tools/bpf/bpftool/prog.c`
  - `tools/include/uapi/linux/bpf.h`

Conclusion:

- The run no longer reflects a single stable build/image state.
- `vm-micro` and `vm-e2e` almost certainly did **not** run on the latest kernel/image that `vm-corpus` wanted to use.

## Step 1: vm-micro

Command run:

- `make vm-micro`

Output file:

- `micro/results/dev/vm_micro.json`

### Summary

`kernel-recompile / kernel` exec median ratios:

| Metric | Value |
| --- | --- |
| Overall geomean | `1.012x` |
| Applied-only geomean | `n/a` |
| Non-applied geomean | `1.012x` |
| Benchmarks | `62` |
| Result mismatches | `0` |
| Retval mismatches | `0` |
| Incomplete benchmarks | `0` |

Comparison with prior authority:

| Metric | Old authority | This run | Delta vs old |
| --- | --- | --- | --- |
| Overall geomean | `1.024x` | `1.012x` | `-1.17%` |
| Applied-only geomean | `1.110x` | `n/a` | `n/a` |

### Applied Benchmarks

None.

Strictly speaking, this run had **zero applied benchmarks**.

### Recompile Failures

The following 7 benchmarks all hit `BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)` and therefore did not actually apply:

- `cmov_dense`
- `bounds_ladder`
- `large_mixed_500`
- `large_mixed_1000`
- `bpf_call_chain`
- `rotate64_hash`
- `rotate_dense`

These are the same benchmarks that previously formed the applied subset. In this run they all fell back to non-applied behavior.

### Correctness / Crash Check

- No result mismatches.
- No retval mismatches.
- No benchmark-level crash/incomplete record in `vm_micro.json`.

## Step 2: E2E

Attempted command:

- `make vm-e2e`

Observed behavior:

- `tracee` completed and wrote `e2e/results/dev/tracee.json`.
- `make vm-e2e` then failed at `tetragon` with `make: *** [Makefile:302: vm-e2e] Error 255`.
- No `tetragon.json` was produced.
- I then continued the remaining requested cases manually, one VM at a time, with the same guest command shape as the Makefile.

### tracee

Output:

- `e2e/results/dev/tracee.json`

Recompile summary:

- Requested programs: `15`
- Applied programs: `13`
- Errors: none
- Comparable: yes

Workload deltas (`post-rejit` vs baseline):

| Workload | BPF avg ns delta | App throughput delta | Events/sec delta | Agent CPU delta |
| --- | --- | --- | --- | --- |
| `exec_storm` | `-3.28%` | `+9.36%` | `+9.24%` | `+7.94%` |
| `file_io` | `+0.77%` | `-2.08%` | `+0.08%` | `+14.29%` |
| `network` | `+1.46%` | `-0.10%` | `-0.10%` | `+1.58%` |

Program-level comparable deltas:

- ID `17` `tracepoint__raw`: `+1.24%`
- ID `21` `tracepoint__raw`: `+0.96%`
- ID `29` `tracepoint__sch`: `+3.38%`

### tetragon

Output:

- No `e2e/results/dev/tetragon.json`

Failure mode:

- `make vm-e2e` failed here with exit `255`.
- Manual VM rerun confirmed guest shell startup and Python entry, then emitted repeated libbpf errors such as:
  - `bpf_create_map_xattr(execve_calls): Invalid argument(-22)`
  - `bpf_create_map_xattr(string_maps_heap): Invalid argument(-22)`
  - `bpf_create_map_xattr(string_prefix_maps.inner): Invalid argument(-22)`
  - `bpf_create_map_xattr(string_postfix_maps.inner): Invalid argument(-22)`
  - `bpf_create_map_xattr(addr4lpm_maps.inner): Invalid argument(-22)`
  - `bpf_create_map_xattr(addr6lpm_maps.inner): Invalid argument(-22)`
  - `bpf_create_map_xattr(kprobe_calls): Invalid argument(-22)`
- After extended wait there was still no JSON output, so the debug rerun was interrupted manually.

Current interpretation:

- `tetragon` is **not runnable to completion** on the current guest kernel/image state.

### bpftrace

Output:

- `e2e/results/dev/bpftrace.json`

Summary:

- Baseline successes: `5`
- ReJIT successes: `0`
- Scripts with sites: `3`
- Geomean speedup: `n/a`

Per-script results:

| Script | Sites | Baseline | ReJIT | Note |
| --- | --- | --- | --- | --- |
| `open_latency` | `6` | `ok` | `skipped` | `policy filtered all live sites` |
| `exec_trace` | `0` | `ok` | `skipped` | `no eligible directive sites` |
| `scheduler_latency` | `6` | `ok` | `skipped` | `policy filtered all live sites` |
| `vfs_read_count` | `0` | `ok` | `skipped` | `no eligible directive sites` |
| `tcp_connect` | `1` | `ok` | `skipped` | `BPF_PROG_JIT_RECOMPILE did not apply` |

### scx

Output:

- `e2e/results/dev/scx.json`

Summary:

- Requested programs: `13`
- Applied programs: `0`
- Errors: none
- Site-bearing programs: `11`
- Site totals:
  - `cmov_sites=67`
  - `lea_sites=1`
  - `total_sites=213`
- Comparable: no
- Reason: `post-ReJIT measurements are unavailable`

## Step 3: Corpus

Attempted command:

- `make vm-corpus REPEAT=200`

Observed behavior:

- Harness immediately warned that kernel sources were newer than `bzImage`.
- It began rebuilding the kernel image.
- Because this revealed that the earlier steps had already run against an older build/image state, I interrupted the build instead of continuing with a mixed-state corpus result.

No current corpus result was produced for this run.

## Interim Conclusion

The most important signal from the completed parts is:

- `vm-micro` no longer has any successfully applied benchmark; the previously applied 7-case subset now all fails with `EINVAL`.
- `tracee` still produces comparable output and applies to most requested programs.
- `bpftrace` does not get any successful rejit run.
- `scx` produces no post-ReJIT comparison.
- `tetragon` is currently blocked by libbpf/map-creation `EINVAL` on the guest kernel/image used here.

However, because the repo/kernel state changed during the run and `vm-corpus` detected that mismatch explicitly, this should not be treated as a final end-to-end validation.

## Recommended Next Action

To obtain a clean authoritative answer, rerun the full sequence from Step 0 after first stabilizing the build state:

1. Make sure the intended top-level / kernel / scanner commits are final.
2. Rebuild the kernel image once.
3. Rerun `vm-micro`, `tracee`, `tetragon`, `bpftrace`, `scx`, and `vm-corpus` against that same image.
