# llvmbpf Tracee Round-Trip Follow-up Fix Report

Date: 2026-03-29

## Scope

This follow-up was scoped to the `GET_ORIGINAL -> llvmbpf lift -> opt -> llc -> BPF_PROG_REJIT`
POC under:

- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/`

Allowed code changes in this round:

- POC scripts
- `vendor/llvmbpf`

No changes were made under `vendor/linux-framework`.

## Kept Code Changes

### 1. REJIT fast path now uses `log_level=0`

Changed:

- `guest_helper/src/main.rs`

Before:

- `bpf_prog_rejit_capture_verifier_log(...)`
- always `BPF_PROG_REJIT(log_level=2)`

After:

- `bpf_prog_rejit(...)`
- first try `log_level=0`
- only retry with `log_level=2` on failure

This removes verifier-log buffer pressure from the success path.

### 2. Tracee live-program enumeration now waits for attach stabilization

Changed:

- `llvmbpf_rejit_guest.py`

Problem:

- `TraceeRunner.start()` returns as soon as any new BPF program appears.
- In March 29 reruns this caused the POC to snapshot only `13` live programs, while the earlier iter4 session had `33`.

Fix:

- after `TraceeRunner.start()`, the POC now polls `find_bpf_programs(runner.pid)`
- waits until the program count stops growing for `3s` or a `20s` timeout fires

Effect:

- the stabilized March 29 session attached `37` programs
- this includes the old iter4 `33` plus `4` extra programs

### 3. Host prepare now supports repeatable experiment knobs

Changed:

- `llvmbpf_rejit_host.py`

Added:

- `--llc-extra-arg`
- `--disable-loop-unrolling`
- `--opt-passes`
- `--large-program-threshold`
- `--large-program-opt-level`

This was used only to run the Phase 2 ablations below.

## Methodology Note

There are now two relevant Tracee counts:

1. Old baseline session:
   - `tracee_live_iter4_20260329_201647`
   - `33` programs
2. Stabilized follow-up sessions:
   - `37` programs
   - the old `33` are still present
   - extra `4` are:
     - `process_execute_failed_tail`
     - `syscall_checker`
     - `cgroup_mkdir_signal`
     - `cgroup_rmdir_signal`

For apples-to-apples comparison against the documented `9/33` baseline, the main metric below is:

- `old33`: the 33-name intersection with iter4

I also report `full37` where useful.

## Phase 1: ENOSPC Fix

Reference baseline:

- session: `tracee_live_iter4_20260329_201647`
- result on old 33:
  - `ok=9`
  - `E2BIG=15`
  - `ENOSPC=8`
  - `EPERM=1`

Phase 1 rerun:

- session: `tracee_live_phase1_log0_stable_20260329_231000`
- result on old 33:
  - `ok=10`
  - `E2BIG=22`
  - `ENOSPC=0`
  - `EPERM=1`

Result:

- standalone `ENOSPC` was eliminated on the old `33`
- but the expected `+8 ok` did **not** happen
- only `+1` program became `ok`
- the other `7` old `ENOSPC` cases were actually masked `E2BIG`

Exact old `ENOSPC` transitions:

- `lkm_seeker_modtree_loop`: `ENOSPC -> E2BIG`
- `lkm_seeker_kset_tail`: `ENOSPC -> E2BIG`
- `lkm_seeker_proc_tail`: `ENOSPC -> ok`
- `trace_security_file_open`: `ENOSPC -> E2BIG`
- `trace_ret_vfs_write_tail`: `ENOSPC -> E2BIG`
- `trace_ret_vfs_writev_tail`: `ENOSPC -> E2BIG`
- `trace_ret_kernel_write_tail`: `ENOSPC -> E2BIG`
- `trace_ret_vfs_readv_tail`: `ENOSPC -> E2BIG`

Interpretation:

- the root-cause doc was correct that `log_level=2` caused verifier-log exhaustion
- but those `8` March 29 failures were not all “would succeed if logless”
- on this rerun, `7/8` were diagnostic masking over real page-budget `E2BIG`

For the stabilized full `37` session:

- `ok=13`
- `E2BIG=23`
- `EPERM=1`

The extra `4` programs were `3 ok + 1 E2BIG`.

## Phase 2: Backend-Bloat Mitigation Ablations

Baseline for ablations:

- session: `tracee_live_phase1_log0_stable_20260329_231000`
- `old33 = 10 ok / 22 E2BIG / 1 EPERM`

### Strategy A: `llc -regalloc=greedy`

- session: `tracee_live_regalloc_greedy_20260329_232000`
- config: baseline + `--llc-extra-arg=-regalloc=greedy`

Result:

- `old33 = 10 ok / 22 E2BIG / 1 EPERM`
- `full37 = 13 ok / 23 E2BIG / 1 EPERM`
- `roundtrip_insn_count` changed on `0/33` old-baseline programs

Conclusion:

- no observable effect
- this is consistent with the current backend already behaving equivalently for this workload

### Strategy B: `-bpf-stack-size=512`

This was already active in the existing POC baseline before this task:

- `llvmbpf_rejit_host.py` already passed `--bpf-stack-size=512`

Conclusion:

- no new rerun was needed
- current March 29 baseline already includes this constraint

### Strategy D: disable loop unrolling

- session: `tracee_live_no_unroll_20260329_233000`
- config: baseline + `--disable-loop-unrolling`

Result:

- `old33 = 10 ok / 22 E2BIG / 1 EPERM`
- `full37 = 13 ok / 23 E2BIG / 1 EPERM`

Instruction-count effect:

- only `2/33` old-baseline programs changed:
  - `send_bin`: `-45` insns
  - `send_bin_tp`: `-45` insns
- total delta across old `33`: `-90`

Conclusion:

- loop-unroll is not the dominant source of the large-program bloat
- it can trim a small tail-call/send path, but it does not move any Tracee failure across the page-budget boundary

### Strategy E: `-Oz` for large programs (`original_insn_count > 3000`)

- session: `tracee_live_large_oz_20260329_234000`
- config:
  - default `-O2`
  - `--large-program-threshold 3000`
  - `--large-program-opt-level Oz`

Programs switched to `Oz` in this run: `19`

- `sys_enter_submit` (`3773`)
- `syscall__execve_enter` (`3956`)
- `syscall__execve_exit` (`3958`)
- `syscall__execveat_enter` (`4011`)
- `syscall__execveat_exit` (`4012`)
- `tracepoint__sched__sched_process_fork` (`4042`)
- `lkm_seeker_modtree_loop` (`14236`)
- `lkm_seeker_kset_tail` (`14857`)
- `lkm_seeker_proc_tail` (`13806`)
- `tracepoint__sched__sched_process_exec` (`4364`)
- `sched_process_exec_event_submit_tail` (`4799`)
- `trace_security_file_open` (`4628`)
- `trace_ret_vfs_write_tail` (`6515`)
- `trace_ret_vfs_writev_tail` (`6504`)
- `trace_ret_kernel_write_tail` (`6515`)
- `trace_ret_vfs_read_tail` (`3821`)
- `trace_ret_vfs_readv_tail` (`3940`)
- `trace_load_elf_phdrs` (`3809`)
- `syscall_checker` (`4708`)

Result:

- `old33 = 10 ok / 22 E2BIG / 1 EPERM`
- `full37 = 13 ok / 23 E2BIG / 1 EPERM`
- `roundtrip_insn_count` changed on `0/33` old-baseline programs

Conclusion:

- for this llvmbpf round-trip path, per-program `Oz` did not produce a measurable code-size change on the failing Tracee set
- this matches the earlier root-cause observation that the main inflation is in backend lowering, not in the high-level IR pass pipeline

### Strategy C: lift-stage `noalias` / `restrict` hint

Tried:

- temporarily marked the kernel-compatible `bpf_main(ctx)` pointer argument with:
  - `NoAlias`
  - `NoCapture`
  - `NonNull`

Build:

- rebuilt `host-lifter`

Rerun:

- session: `tracee_live_noalias_20260329_235000`

Result:

- `old33 = 10 ok / 22 E2BIG / 1 EPERM`
- `full37 = 13 ok / 23 E2BIG / 1 EPERM`
- `roundtrip_insn_count` changed on `0/33` old-baseline programs

Conclusion:

- no observable effect on this workload
- the patch was reverted after the experiment to avoid keeping ineffective vendor churn

## Final Status

### Apples-to-apples result on the original Tracee 33

- baseline iter4: `9 ok / 15 E2BIG / 8 ENOSPC / 1 EPERM`
- final kept fix: `10 ok / 22 E2BIG / 0 ENOSPC / 1 EPERM`

Net effect:

- `ENOSPC`: `8 -> 0`
- `ok`: `9 -> 10`
- `E2BIG`: `15 -> 22`
- `EPERM`: unchanged

This is a real improvement in the sense that verifier-log exhaustion is no longer the visible blocker. But it also shows that the remaining problem is even more concentrated than expected:

- almost everything left is genuine `E2BIG`
- the tested backend-parameter tweaks did not reduce that `E2BIG` set

### Full stabilized Tracee attach set

Latest stabilized session:

- `tracee_live_phase1_log0_stable_20260329_231000`

Result on `37` programs:

- `13 ok`
- `23 E2BIG`
- `1 EPERM`

## Remaining Root Cause

After removing `log_level=2` from the success path, the remaining blocker is still the same one identified in the root-cause analysis:

- LLVM BPF backend lowering inflates large programs too much
- dominant growth is still stack spill/reload and helper-call marshaling
- the simple flag-level mitigations tested here did not materially reduce the emitted bytecode

## Recommended Next Steps

The next useful work is no longer “toggle optimizer knobs”. The follow-on options with the highest chance of moving the `22` remaining old-baseline `E2BIG` cases are:

1. add a size-aware skip gate before REJIT for programs already close to `prog->pages`
2. target the specific backend-lowered shapes from the root-cause report in postprocess or in llvmbpf lowering:
   - stack spill/reload collapse
   - helper marshaling shrink
   - 64-bit load/store scalarization repair
3. if size repair is not practical soon, explicitly classify those large Tracee programs as “not safely round-trippable under current page budget” in the experiment harness instead of expecting flag tuning to recover them
