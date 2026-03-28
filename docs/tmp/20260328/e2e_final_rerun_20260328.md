# E2E Final Rerun 2026-03-28

## Scope

This rerun was executed specifically to avoid the old-daemon mismatch from the earlier E2E run.

Commands executed:

```bash
rm -f .cache/runner/vm-locks/vm_global.lock .cache/runner/vm-queue/vm_global.json
make daemon
make runner
stat daemon/target/release/bpfrejit-daemon
make vm-e2e TARGET=x86
```

## Fresh Binary Proof

- Pre-run `stat` was captured at `2026-03-28 14:37:57 PDT`.
- At that moment, `daemon/target/release/bpfrejit-daemon` had:
  - `Modify: 2026-03-28 14:37:46.272691199 -0700`
- The VM E2E guest script started at `2026-03-28 14:38:01 PDT`.
- Therefore this rerun did use a freshly rebuilt daemon binary; it did not reuse the stale `14:20` daemon from the earlier incorrect run.

## Active Performance Passes

Current `corpus/config/benchmark_config.yaml` `passes.performance` list is exactly 11 passes:

1. `wide_mem`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`
6. `map_inline`
7. `const_prop`
8. `dce`
9. `bounds_check_merge`
10. `skb_load_bytes_spec`
11. `bulk_memory`

This same 11-pass set appears in `selected_rejit_passes` for all 6 case artifacts from this rerun.

## Suite Outcome

`make vm-e2e TARGET=x86` finished with non-zero exit status because `katran` failed. The other 5 cases completed successfully.

| Case | Artifact dir | Metadata status | Result status | Started (UTC) | Completed (UTC) | Duration |
| --- | --- | --- | --- | --- | --- | --- |
| `tracee` | `e2e/results/tracee_20260328_213806` | `completed` | `ok` | `2026-03-28T21:38:06.840344+00:00` | `2026-03-28T21:47:46.322172+00:00` | `579.48s` |
| `tetragon` | `e2e/results/tetragon_20260328_214746` | `completed` | `ok` | `2026-03-28T21:47:46.691484+00:00` | `2026-03-28T21:50:34.938051+00:00` | `168.25s` |
| `bpftrace` | `e2e/results/bpftrace_20260328_215036` | `completed` | `ok` | `2026-03-28T21:50:36.575649+00:00` | `2026-03-28T21:58:07.889837+00:00` | `451.31s` |
| `scx` | `e2e/results/scx_20260328_215808` | `completed` | `ok` | `2026-03-28T21:58:08.006623+00:00` | `2026-03-28T21:59:55.632809+00:00` | `107.63s` |
| `katran` | `e2e/results/katran_20260328_215955` | `error` | no `result.json` | `2026-03-28T21:59:55.720416+00:00` | none | failed during setup |
| `bcc` | `e2e/results/bcc_20260328_220000` | `completed` | `ok` | `2026-03-28T22:00:00.025574+00:00` | `2026-03-28T22:12:19.751382+00:00` | `739.73s` |

Console summary from this rerun:

- `tracee OK`
- `tetragon OK`
- `bpftrace OK`
- `scx OK`
- `katran FAILED`
- `bcc OK`

## Tetragon Check

### Short answer

- Top-level Tetragon case is now `ok`.
- There is no top-level Tetragon case failure with `Permission denied`.
- However, the internal per-pass verifier records still contain a `Permission denied` rejection for `event_execve` under `dce`.

### Activity and target programs

From `e2e/results/tetragon_20260328_214746/details/result.json`:

- Hot program is `event_execve` (`prog_id=212`).
- `execve_rate` (`prog_id=211`) remains cold in preflight and workload phases (`run_cnt_delta=0`).

### Per-pass verifier outcomes

For `event_execve` (`prog_id=212`):

- `map_inline`
  - `sites_applied=6`
  - `sites_skipped=26`
  - verify result: rejected
  - first error line: `BPF_PROG_REJIT: Invalid argument (os error 22)`
  - key skip reasons:
    - `lookup key is not a constant stack or pseudo-map-value materialization`: `7`
    - `lookup result is not consumed by fixed-offset scalar loads`: `12`
    - `map lookup failed: map 443 missing key [0, 0, 0, 0, 0, 0, 0, 0]`: `1`
    - `map type 10 not inlineable in v1`: `4`
    - `mutable lookup result has non-load uses`: `2`

- `const_prop`
  - `sites_applied=19`
  - verify result: rejected
  - error includes: `unreachable insn 230`

- `dce`
  - `sites_applied=116`
  - verify result: rejected
  - first error line: `BPF_PROG_REJIT: Permission denied (os error 13)`

Verifier log excerpt for the `dce` rejection:

```text
BPF_PROG_REJIT: Permission denied (os error 13)
verifier log:
func#0 @0
func#1 @1689
func#2 @1880
func#3 @2053
func#4 @2122
func#5 @2145
func#6 @2213
Live regs before insn:
      0: .1........ (bf) r6 = r1
      1: ......6... (85) call bpf_get_current_task#35
      2: 0.....6... (bf) r9 = r0
      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6
      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)
      5: ......6..9 (b7) r1 = 0
      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1
      7: ......6..9 (bf) r2 = r10
      8: ..2...6..9 (07) r2 += -120
      9: ..2...6..9 (18) r1 = 0xffff8b02fd403800
     11: .12...6..9 (85) call bpf_map_lookup_elem#1
```

### Interpretation

- The earlier top-level Tetragon `Permission denied` symptom is gone at the case level.
- But this rerun does **not** show a clean verifier state for `event_execve`.
- `const_prop` still records `unreachable insn 230`.
- `dce` still records a non-empty `Permission denied` verifier failure.

So the rerun validates that the harness is no longer failing the entire Tetragon case with `Permission denied`, but it does **not** prove that all pass-specific verifier issues are gone.

## Katran Check

### Short answer

- This rerun produced **no Katran apply result**.
- Therefore there is **no rerun value** for `map_inline` sites or Katran skip reasons.

### Failure mode

`e2e/results/katran_20260328_215955/metadata.json` reports:

```text
failed to load kernel module veth: repo_candidates=/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/drivers/net/veth.ko:False; modprobe rc=1: modprobe: ERROR: could not insert 'veth': Unknown symbol in module, or unknown parameter (see dmesg); insmod /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/.virtme_mods/lib/modules/0.0.0/kernel/drivers/net/veth.ko rc=1: insmod: ERROR: could not load module /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/.virtme_mods/lib/modules/0.0.0/kernel/drivers/net/veth.ko: No such file or directory
```

Observed consequences:

- `e2e/results/katran_20260328_215955/details/result.json` does not exist.
- `e2e/results/katran_20260328_215955/details/result.md` does not exist.
- The case failed before scan/apply/report generation.

Therefore:

- `map_inline` site count: unavailable in this rerun
- Katran skip reasons: unavailable in this rerun

## Requested Fixes: What This Rerun Actually Validated

### Confirmed by this rerun

- `benchmark_config.yaml` 11 performance passes:
  - confirmed from YAML
  - confirmed in all 6 case artifacts

- E2E used a freshly rebuilt daemon binary:
  - confirmed by pre-run `stat` timestamp preceding VM E2E start

- PGO socket/control-plane path did not visibly fail in successful cases:
  - `tracee`, `tetragon`, `bpftrace`, `scx`, `bcc` all completed without top-level daemon/protocol/socket error strings in their artifacts

### Indirectly covered, but not isolated

- per-pass verify after retry-loop removal:
  - Tetragon artifacts now surface pass-specific verifier failures directly inside one run
  - no evidence of hidden retry masking in this rerun

- `verifier_retries` optional parsing:
  - no configuration parse failure surfaced in this rerun

- mutable writeback guard site-local:
  - no dedicated regression signature surfaced in the successful cases
  - this rerun does not isolate that change on its own

### Not cleanly validated by this rerun

- `const_prop fixup_folded_jumps`:
  - Tetragon `event_execve` still reports `unreachable insn 230` during `const_prop` verify
  - so this full-pipeline rerun does not establish a clean end-to-end success for that specific verifier issue

- Katran `map_inline` coverage recovery:
  - not measurable in this rerun because Katran failed before result generation

## Bottom Line

- This rerun fixed the original stale-binary problem: the E2E suite was executed with a freshly rebuilt daemon.
- 5/6 cases completed successfully with the expected 11-pass configuration.
- Tetragon no longer fails at the case level with `Permission denied`, but `event_execve` still contains pass-specific verifier rejections internally, including a `dce` `Permission denied`.
- Katran could not be validated in this rerun because it failed during `veth` module setup, before any `map_inline`/skip-reason statistics were produced.
