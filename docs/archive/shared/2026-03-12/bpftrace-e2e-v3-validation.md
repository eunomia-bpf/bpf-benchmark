# bpftrace E2E v3 Validation

Date: 2026-03-12

## Scope

Validate the bpftrace end-to-end recompile path against the new v3 policies in `corpus/policies/bpftrace/` on the framework VM kernel.

Policies under test:

- `corpus/policies/bpftrace/open_latency/kretprobe_do_sys_openat2.policy.yaml`
- `corpus/policies/bpftrace/scheduler_latency/tracepoint_sched_sched_switch.policy.yaml`

## Environment

- Kernel image present: `vendor/linux-framework/arch/x86/boot/bzImage`
- Guest kernel used for validation: `7.0.0-rc2-ge52504a75c05-dirty`
- Guest userspace tools:
  - `bpftrace v0.20.2`
  - `bpftool v7.7.0` from `/usr/local/sbin/bpftool`

Note: `e2e/run.py --vm` still rejects `bpftrace`, so the authoritative guest run used the case entrypoint directly:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2 --exec '
  cd /home/yunwei37/workspace/bpf-benchmark &&
  . /home/yunwei37/workspace/.venv/bin/activate &&
  sudo python3 e2e/cases/bpftrace/case.py \
    --skip-build \
    --duration 5 \
    --script open_latency \
    --script scheduler_latency
'
```

## Issues Found

### 1. bpftrace policy lookup missed the v3 files

Observed behavior:

- live bpftrace programs were discovered as shortened names from `bpftool`, e.g. `do_sys_openat2` and `sched_switch`
- v3 policy files are keyed by full program names, e.g. `kretprobe:do_sys_openat2` and `tracepoint:sched:sched_switch`
- result: `policy_matches` was empty and the case silently fell back to stock

Fix:

- move bpftrace policy resolution until after live site discovery, so only eligible programs need policies
- add a bpftrace-specific fallback in `e2e/cases/bpftrace/case.py`:
  - keep exact object+program lookup first
  - if unresolved and the script policy directory has a single v3 policy, use it for the eligible live program
  - otherwise fall back to a unique suffix match on the policy `program:` field

### 2. empty v3 policies hit `EINVAL`

Observed behavior after policy lookup was fixed:

- both shipped bpftrace v3 policies parse and remap correctly
- both policies intentionally contain `sites: []`
- live scanner still found 6 `cmov` sites in each eligible program
- after remap, `remapped_sites = 0`
- the generic helper still called `BPF_PROG_JIT_RECOMPILE` with an empty effective policy and the kernel returned `EINVAL`

Fix:

- in `e2e/common/recompile.py`, detect `remapped_sites == 0` after live remap
- treat this as a clean no-op instead of issuing the syscall
- return:
  - `noop: true`
  - `error: ""`
  - `stdout_tail` explaining that policy filtering left no live sites

## Guest Validation Results

### A. Actual shipped v3 policies

Guest summary:

- `baseline_successes = 2`
- `rejit_successes = 0`
- `scripts_with_sites = 2`
- aggregate live sites: `12 total`, all `cmov`

Per script:

- `open_latency`
  - policy resolved to `kretprobe_do_sys_openat2.policy.yaml`
  - eligible live program count: `1`
  - live site count: `6 cmov`
  - policy remap summary: `explicit_sites=0`, `remapped_sites=0`, `dropped_sites=0`
  - result: clean no-op, no error
  - reason recorded by the case: `policy filtered all live sites`

- `scheduler_latency`
  - policy resolved to `tracepoint_sched_sched_switch.policy.yaml`
  - eligible live program count: `1`
  - live site count: `6 cmov`
  - policy remap summary: `explicit_sites=0`, `remapped_sites=0`, `dropped_sites=0`
  - result: clean no-op, no error
  - reason recorded by the case: `policy filtered all live sites`

Representative guest output for both programs:

```text
Accepted 0 v5 site(s)
Skipped BPF_PROG_JIT_RECOMPILE because policy filtering left no live sites.
```

Conclusion for shipped policies:

- v3 policy loading works
- v3 parsing works
- program-name resolution works in the E2E path after the fix
- live site remap/filtering works
- empty allowlists are now handled correctly as no-op
- no crash and no `EINVAL`

### B. Positive-control guest apply

Because the shipped policies intentionally select zero live sites, they do not exercise the actual syscall apply path after filtering. To verify that the full v3 blob/syscall path still works on the framework kernel, I ran a guest-side positive control:

- workload/script: `scheduler_latency`
- temporary v3 policy:
  - `program: tracepoint:sched:sched_switch`
  - allow exactly one live site: `cmov:40:cond-select-64`

Guest result:

- kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- selected site: `insn=40`, `family=cmov`, `pattern_kind=cond-select-64`
- policy remap summary:
  - `explicit_sites=1`
  - `remapped_sites=1`
  - `live_total_sites=6`
- scanner/apply output:

```text
Accepted 1 v5 site(s)
Policy filter kept 1 of 6 v5 rule(s)
Applied 1 v5 rule(s) via BPF_PROG_JIT_RECOMPILE
```

- post-apply liveness:
  - `process_alive_after_workload = true`
  - `run_cnt_delta_after_apply = 170056`
  - `run_time_ns_delta_after_apply = 27033759`

Conclusion for positive control:

- non-empty v3 policy blobs are accepted by the framework kernel
- `BPF_PROG_JIT_RECOMPILE` succeeds from the bpftrace live-program path
- the traced program continues running after recompile

## Final Verdict

Yes: the bpftrace E2E pipeline works end-to-end with v3 policies in the framework VM after two E2E-side fixes.

What is true after validation:

- shipped bpftrace v3 policies resolve by live program correctly
- v3 policies parse and remap correctly against live scanner manifests
- empty post-filter policies are handled as valid no-op instead of failing with `EINVAL`
- non-empty v3 policies apply successfully via `BPF_PROG_JIT_RECOMPILE` on the framework kernel
- bpftrace programs continue functioning after a successful v3-driven recompile

Files changed during validation:

- `e2e/cases/bpftrace/case.py`
- `e2e/common/recompile.py`
