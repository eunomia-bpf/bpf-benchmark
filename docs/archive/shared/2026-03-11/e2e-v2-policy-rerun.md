# E2E v2 Policy Rerun

Generated: 2026-03-12

## Run Notes

- Kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- New result files:
  - `e2e/results/tracee-e2e-v2-policy.json`
  - `e2e/results/tetragon-e2e-v2-policy.json`
  - `e2e/results/bpftrace-e2e-v2-policy.json`
- Blind all-apply comparison sources:
  - Tracee: `e2e/results/tracee-e2e-real.md` (2026-03-11)
  - Tetragon: `e2e/results/tetragon-real-e2e.md` (2026-03-11)
  - bpftrace: `e2e/results/bpftrace_authoritative_20260311.json` and `e2e/results/bpftrace-real-e2e.md` (2026-03-11)
- Two harness fixes were required before this rerun:
  - `e2e/common/recompile.py` now uses the v2 policy `program:` name for `scanner apply --config`, instead of the truncated kernel BPF program name.
  - `e2e/cases/bpftrace/case.py` now falls back to the expected 30s default when `e2e/run.py` omits `--duration`.

## Top Line

| Case | Policy hits | Fallbacks | Config applies | Fallback `--all` applies | Measured stock -> post | Blind all-apply reference |
| --- | --- | --- | --- | --- | --- | --- |
| Tracee | 13 / 15 | 2 | 0 | 0 | no post phase; all config policies reduced to `policy has no rules` | 2026-03-11 blind run had app deltas `+21.65%` / `+5.06%` / `+1.32%` across `exec_storm` / `file_io` / `network` |
| Tetragon | 3 / 5 | 2 | 0 | 2 | mean app `339334.24 -> 336992.29` (`-0.69%`), mean BPF avg ns `3886.73 -> 3958.06` (`+1.84%`) | 2026-03-11 blind run: mean app `320198.94 -> 332335.69` (`+3.79%`), mean BPF avg ns `3627.41 -> 3100.48` (`-14.52%`) |
| bpftrace | 0 / 7 attached programs | 7 | 0 | 3 | geomean `1.056x`, but every reJIT used fallback blind all-apply | 2026-03-11 blind run geomean `0.992x` |

The key result is that the lookup path is wired up, but no case achieved a successful config-mode v2 policy apply on a live program. All observed post-reJIT measurements came either from blind fallback (`policy_mode=all`) or were skipped entirely.

## Per-Case

### Tracee

- New stock baseline:
  - `exec_storm`: app `181.16`, BPF avg ns `70.74`
  - `file_io`: app `885409.88`, BPF avg ns `30.37`
  - `network`: app `4979.72`, BPF avg ns `41.53`
- Policy lookup:
  - hit `13/15` live programs
  - fallback `2/15` (`tracepoint__raw*` programs)
- Recompile outcome:
  - `13/13` config-mode programs failed with stale-site warnings and `BPF_PROG_JIT_RECOMPILE: Invalid argument / policy has no rules`
  - `0/15` programs applied; post-ReJIT phase was skipped
- Comparison to 2026-03-11 blind all-apply:
  - blind `exec_storm`: app `159.16 -> 193.63` (`+21.65%`), BPF avg ns `59.15 -> 57.59`
  - blind `file_io`: app `826273.77 -> 868049.87` (`+5.06%`), BPF avg ns `30.44 -> 30.38`
  - blind `network`: app `5005.82 -> 5072.01` (`+1.32%`), BPF avg ns `41.26 -> 42.02`
- Interpretation:
  - Tracee is no longer falling back blindly for most programs; it is hitting per-program v2 YAMLs.
  - The problem is artifact drift: the live Tracee programs and the stored policy sites no longer align, so the compiled directive set is empty.

### Tetragon

- Policy lookup:
  - config hits `3/5`
  - fallback `2/5`
- Program-by-program mode:
  - `event_exit_acct`: `policy_mode=all`, applied
  - `event_wake_up_new_task`: `policy_mode=config`, not applied
  - `event_execve`: `policy_mode=config`, not applied
  - `tg_kp_bprm_comm`: `policy_mode=all`, applied
  - `execve_map_update`: `policy_mode=config`, not applied
- Stock vs rerun:
  - mean app throughput `339334.24 -> 336992.29` (`-0.69%`)
  - mean BPF avg ns `3886.73 -> 3958.06` (`+1.84%`, slower)
  - workload deltas:
    - `stress_exec`: `+4.88%`
    - `file_io`: `-0.63%`
    - `open_storm`: `-1.08%`
    - `connect_storm`: `+3.92%`
- Comparison to 2026-03-11 blind all-apply:
  - blind mean app `320198.94 -> 332335.69` (`+3.79%`)
  - blind mean BPF avg ns `3627.41 -> 3100.48` (`-14.52%`)
  - blind workload deltas:
    - `stress_exec`: `+6.74%`
    - `file_io`: `+4.03%`
    - `open_storm`: `+2.58%`
    - `connect_storm`: `-10.16%`
- Interpretation:
  - The rerun did find v2 policies for the three intended Tetragon programs, but none of those three policies applied.
  - The only measured post-ReJIT effects came from the two fallback `--all` programs, so this is not a clean v2-policy win/loss measurement.

### bpftrace

- Policy lookup:
  - config hits `0/7` attached programs
  - fallback `7/7`
- Why lookup failed:
  - `corpus/build/bpftrace/` is empty in the current repo state
  - `corpus/policies/bpftrace/` does not exist
  - the current best-effort mapping in `e2e/cases/bpftrace/case.py` therefore has nothing to resolve
- Rerun outcome:
  - eligible scripts `3`
  - total sites `13`
  - reJIT successes `3`
  - every applied program used fallback `policy_mode=all`
- Per-script results from the fallback rerun:
  - `open_latency`: `324.05 -> 269.18` ns (`1.204x`), ops `95143.99 -> 96220.93`
  - `scheduler_latency`: `164.85 -> 168.55` ns (`0.978x`), ops `41.18 -> 39.44`
  - `tcp_connect`: `947.26 -> 947.81` ns (`0.999x`), ops `18.61 -> 18.68`
- Comparison to 2026-03-11 blind all-apply:
  - old geomean `0.992x`; new fallback rerun geomean `1.056x`
  - old `open_latency`: `277.17 -> 273.77` ns (`1.012x`)
  - old `scheduler_latency`: `158.59 -> 163.27` ns (`0.971x`)
- Interpretation:
  - The bpftrace result file is useful as a new blind-fallback measurement on the March 12 kernel, but it is not a valid v2-policy rerun because no v2 artifacts were present to match.

## Policy Hit/Miss Statistics

| Case | Programs considered for policy lookup | Config hits | Fallbacks | Config applies | Fallback applies |
| --- | --- | --- | --- | --- | --- |
| Tracee | 15 | 13 | 2 | 0 | 0 |
| Tetragon | 5 | 3 | 2 | 0 | 2 |
| bpftrace | 7 attached programs across 5 scripts | 0 | 7 | 0 | 3 |

Across all three reruns, config-mode v2 policies applied to `0` live programs. The effective measured post-ReJIT deltas therefore came from:

- no apply at all for Tracee
- fallback blind all-apply on 2 Tetragon programs
- fallback blind all-apply on 3 bpftrace programs

## Takeaways

- `e2e/common/recompile.py` is now correctly wired to prefer per-program v2 policy files and pass the full policy program name into `scanner apply --config`.
- That wiring is not enough on its own. The current E2E artifact set has two separate correctness gaps:
  - Tracee and Tetragon have policy-file hits, but the stored per-site insn coordinates are stale relative to the live programs, so the policies collapse to zero rules.
  - bpftrace has no policy/object artifacts in `corpus/build/` + `corpus/policies/`, so it always falls back to blind all-apply.
- Compared with the March 11, 2026 blind all-apply baselines, this March 12, 2026 rerun does not show a usable end-to-end improvement from v2 policies, because no live config-mode applies succeeded.

## Follow-Up Needed Before a Clean v2-vs-Blind Comparison

- Refresh Tracee and Tetragon per-program v2 policies against the exact live objects/binaries used by the E2E harness.
- Populate `corpus/build/bpftrace/*.bpf.o` and `corpus/policies/bpftrace/...` so bpftrace can resolve config-mode policies instead of falling back to `--all`.
- Re-run #121 after those artifacts are refreshed; the current JSONs should be treated as a pipeline-validation rerun, not a final policy-performance comparison.
