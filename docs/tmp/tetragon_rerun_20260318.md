# Tetragon Rerun 20260318

## Status

- `corpus/policies/tetragon/` currently contains `71` checked-in Tetragon policy files.
- All `71/71` files use the refreshed explicit allowlist header:
  - `Selection model: explicit site allowlist; keep every discovered site except skipped families: cmov, extract`
- `cmov` and `extract` exclusion notes are present everywhere they should be.
- I did **not** regenerate policies yet, because the current Tetragon policy set already reflects the intended `cmov,extract` skip behavior, and the worktree has many existing uncommitted policy edits outside this task.

## Tetragon-Only Run Path

- `make vm-e2e` runs all E2E cases, so it is not the right entrypoint for a focused Tetragon rerun.
- There is no dedicated `vm-e2e-tetragon` target in `Makefile`.
- The practical Tetragon-only path is the same `vng` invocation that `vm-e2e` uses internally, but restricted to:
  - `python3 e2e/run.py tetragon`

## VM Smoke Validation

I ran a Tetragon-only VM smoke on March 18, 2026 using the framework kernel:

- kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- command shape: `vng --run ... bash -lc '... python3 e2e/run.py tetragon --smoke ...'`
- diagnostic VM sizing: `--cpus 2 --memory 4G`
- outputs:
  - `e2e/results/dev/tetragon_smoke_20260318_check.json`
  - `e2e/results/dev/tetragon_smoke_20260318_check.md`

### Smoke Findings

- mode: `tetragon_daemon`
- live Tetragon programs observed: `5`
- policy matches: `3`
  - prog `24` -> `bpf_fork/event_wake_up_new_task.policy.yaml`
  - prog `25` -> `bpf_execve_event/event_execve.policy.yaml`
  - prog `32` -> `bpf_execve_map_update/execve_map_update.policy.yaml`
- recompile applied: `2/5`

Important detail:

- `event_execve` live scan reported `29` sites:
  - `branch-flip=14`
  - `cmov=15`
- The refreshed v3 policy remapped only `4` `branch-flip` sites.
- No live `cmov` sites were selected, which confirms the checked-in policy is honoring the intended `cmov` skip.

- `execve_map_update` matched a policy file, but the live remap produced `0` explicit sites, so it correctly no-oped instead of blind-applying.

### Smoke Workload Deltas

These are smoke-only numbers and are not authoritative:

| Workload | App delta | BPF avg ns delta |
| --- | ---: | ---: |
| `connect_storm` | `+72.16%` | `+19.31%` |
| `file_io` | `+2.08%` | `-13.84%` |
| `open_storm` | `-4.08%` | `+36.60%` |
| `stress_exec` | `-2.67%` | `-0.11%` |

Interpretation:

- The smoke run is only useful as a pipeline check.
- It confirms current Tetragon v3 policies are no longer in the old stale state where everything effectively fell back or still carried live `cmov` application.
- It is **not** suitable for comparing against the old real numbers (`+6.7%`, `+4.0%`, `+2.6%`, `-10.2%`).

## Kernel Warning Observed

During smoke, the guest kernel emitted:

- `WARNING: arch/x86/net/bpf_jit_comp.c:893 at bpf_int_jit_compile+0x92d/0xd50`

That line is:

- `WARN_ON_ONCE(READ_ONCE(poke->tailcall_target_stable));`

The run completed successfully despite the warning, but this should be mentioned alongside any later full rerun results.

## Blocker For Authoritative Full Rerun

I have **not** started the full authoritative Tetragon rerun yet.

Reason:

- The host is currently running other benchmark VMs against the same repo/kernel path, including:
  - a long-running `vm_micro` QEMU with `24` vCPUs
  - recurring `corpus v5 vm batch` QEMU runs
- Those concurrent VMs materially contaminate any application-throughput measurement, so a full Tetragon E2E run performed now would not be defensible as authoritative.

## Next Step

Once the concurrent VM benchmarks are stopped or finish, run the full Tetragon-only VM benchmark and then:

1. compare `stress_exec`, `file_io`, `open_storm`, and `connect_storm` against the archived March 11, 2026 results
2. decide whether `connect_storm` still regresses
3. save:
   - `e2e/results/tetragon_authoritative_20260318.json`
4. update this report with the final comparison
