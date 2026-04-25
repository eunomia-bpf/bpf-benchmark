# Tetragon Stabilization Investigation

## Scope

- Read `runner/libs/app_runners/tetragon.py` and `runner/libs/app_runners/process_support.py`.
- Read `e2e/cases/tetragon/case.py`.
- Compared:
  - `e2e/results/tetragon_20260424_025015_828405/metadata.json`
  - `e2e/results/tetragon_20260424_035242_511975/metadata.json`
- Read `e2e/results/tetragon_manual_diag_20260424T054427Z.log`.
- Checked `e2e/cases/tetragon/config.yaml`, policy set under `e2e/cases/tetragon/policies`, and the Tetragon version reported in logs.

## Findings

1. `wait_until_program_set_stable()` uses a strict "non-empty and unchanged for 2s" rule.
   - Current code path is `wait_healthy(... bool(refresh_programs()))` followed by `wait_until_program_set_stable(...)`.
   - This means Tetragon must first expose at least one new BPF program, then the full post-start program set must stop changing before timeout.

2. Upstream policy loading materially extends startup.
   - The policy directory contains 15 upstream policies.
   - Manual diagnostic run shows program count growing like this:
     - `T+001s`: 7 programs
     - `T+002s`: 15 programs
     - `T+010s`: 193 programs
     - `T+016s`: 287 programs
     - `FINAL_PROGRAMS`: 287
   - So "startup complete" is not the 7-program base sensor state once policies are enabled.

3. The successful run and the failing run are not equivalent.
   - Successful run `tetragon_20260424_025015_828405` recorded exactly 7 Tetragon programs and its logs say:
     - `Loading Tracing Policies from directory ignored, directory does not exist`
   - Its persisted `tetragon_launch_command` also omitted `--tracing-policy-dir`.
   - Failed run `tetragon_20260424_035242_511975` failed during startup with:
     - `BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=0, last_program_ids=<none>)`
   - Conclusion: the "success" path was effectively a base-sensor-only startup, while the newer policy-loading path is much heavier.

4. `20s` is too tight once policies are enabled.
   - The manual diagnostic run needed about 16s before the program set stopped growing.
   - With a 2s stabilization window, 20s leaves almost no slack for slower boots, scheduling jitter, or bpftool polling latency.

5. The current stabilization helper had a smaller correctness issue too.
   - It only refreshed the stabilization timer when program count changed.
   - If the set changed while count stayed the same, it could falsely consider the set stable.
   - That is not the main cause of this Tetragon failure, but it is still a real bug in the helper.

6. Tetragon version and config context.
   - Logs report `Starting tetragon` with `version=v1.6.1`.
   - `e2e/cases/tetragon/config.yaml` previously only set workload and `measurement_duration_s`; there was no explicit startup timeout knob.

## Root Cause

The intermittent e2e failure is consistent with a timeout mismatch, not with Tetragon never loading BPF at all.

When upstream tracing policies are enabled, Tetragon keeps attaching programs for much longer than the old 20-second budget assumes. The older successful run avoided that path because it did not actually pass a tracing-policy directory. The stabilization rule itself is reasonable for capturing the full loaded program set, but the timeout was undersized for the policy-enabled startup path.

## Fix Applied

1. Increased the default Tetragon load timeout from `20s` to `45s`.
   - Updated:
     - `runner/libs/app_runners/tetragon.py`
     - `e2e/cases/tetragon/case.py`

2. Made the timeout configurable in the case config.
   - Added `load_timeout_s: 45` to `e2e/cases/tetragon/config.yaml`.
   - `e2e/cases/tetragon/case.py` now reads `load_timeout_s` from config.

3. Tightened stabilization correctness.
   - `runner/libs/app_runners/process_support.py` now resets the stability window when program IDs change, not just when count changes.

## Why I Did Not Switch To "count > 0"

That would likely make the failure disappear, but it would also let Tetragon return after the early 7-program base sensor state and ignore most policy-loaded programs. Since the policy-enabled startup path is intentional in the current runner, the better fix is to keep waiting for the real set to settle and give it enough time.

## Validation

- Static validation to run after the patch:
  - `python3 -m py_compile runner/libs/app_runners/process_support.py runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
- I also attempted a direct local runtime repro in this shell, but it is not privileged enough to run `bpftool prog show`; the attempt failed with:
  - `Operation not permitted`

## Residual Risk

- If policy load time grows beyond ~45s on a much slower environment, the symptom can still recur.
- If that happens, the next step should be collecting one more diagnostic log from the failing environment before increasing the timeout further.
