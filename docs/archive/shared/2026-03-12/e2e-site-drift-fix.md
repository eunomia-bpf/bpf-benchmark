# E2E v2 Policy Site Drift Fix

Generated: 2026-03-12

## Summary

- Root cause: `corpus/policies/` stores v2 site coordinates from offline `.bpf.o` section scans, but E2E applies policies to live verified programs via `--prog-fd`, so stored `insn` offsets drift.
- Implemented fix: `e2e/common/recompile.py` now does a live `scanner scan --json --prog-fd <fd>` before config-mode apply, remaps the v2 policy onto live sites by family order, writes a temporary remapped policy, then calls the existing `scanner apply --config`.
- Scope: this is the smallest harness-side fix. It does not change scanner C++ matching semantics or regenerate the whole corpus in-VM.

## Code Changes

### `corpus/policy_utils.py`

- Added `remap_policy_v2_to_live(...)`.
- Input: existing v2 policy + live scan manifest JSON.
- Mapping rule: preserve policy `default`, `program`, and per-site `action`, but rewrite explicit site `insn` values by consuming live sites in order within each `family`.
- Output: remapped v2 YAML text plus a remap summary (`explicit_sites`, `remapped_sites`, dropped family counts, live family counts).

### `e2e/common/recompile.py`

- Added a live-manifest helper that runs `scanner scan --prog-fd ... --json`.
- In `apply_recompile()`:
  - config-mode targets now live-scan first
  - remap the selected v2 policy to live sites
  - write a temporary remapped policy file
  - pass that temporary file to the existing `scanner apply --config`
- Result payloads now include `policy_remap` for debugging and post-run reporting.

## Why This Fix

- It directly addresses the reported failure mode: stale `insn` offsets in config-mode policies.
- It keeps the current corpus format intact.
- It avoids riskier scanner-side fuzzy matching inside the kernel-facing apply path.
- It works with existing `scanner apply --prog-fd` support and existing E2E case code.

## Validation

### `py_compile`

Passed:

```bash
python -m py_compile corpus/policy_utils.py e2e/common/recompile.py
```

### Host Smoke Test

Host kernel: `6.15.11-061511-generic`

Smoke target:

- launched `bpftrace -q e2e/cases/bpftrace/scripts/open_latency.bt`
- selected attached live program `do_sys_openat2`
- scanner live scan found `6` `cmov` sites

Control:

- built a deliberately stale v2 policy by taking the live sites and shifting every `insn` by `+1000`
- direct `scanner apply --config <stale-policy>` on the live program kept `0/6` rules and emitted stale-site warnings

Fixed path:

- `apply_recompile(..., policy_files={prog_id: stale_policy})` live-scanned the same program, remapped the stale policy, and kept `6/6` rules
- observed remap summary:
  - `explicit_sites=6`
  - `remapped_sites=6`
  - `dropped_sites=0`
  - `policy_family_counts={'cmov': 6}`
  - `live_family_counts={'cmov': 6}`

Observed host limitation:

- the host kernel still returned `BPF_PROG_JIT_RECOMPILE: Invalid argument` even after remap
- this also happened for blind `--all` attempts on several host programs, so host is not a reliable environment for end-to-end apply validation
- the smoke test therefore validates the site-drift fix itself (`0/6` rules kept before remap, `6/6` kept after remap), but not final host-side apply success

Relevant smoke output excerpt:

```text
direct stale policy:
  Policy filter kept 0 of 6 v5 rule(s)

remapped apply_recompile:
  Policy filter kept 6 of 6 v5 rule(s)
```

## Expected E2E Impact

- Tracee/Tetragon config-mode runs should no longer collapse to empty rule sets solely because offline and live `insn` offsets drifted.
- Programs with matching family counts should now arrive at `scanner apply` with non-empty rule sets.
- Remaining failures after this fix are more likely to be true kernel-side apply/validator issues rather than stale site coordinates.

## Follow-Up

- Re-run the v2 E2E path on the vendor VM kernel used by `docs/tmp/e2e-v2-policy-rerun.md`.
- If config-mode still fails after this remap, the next debugging target is kernel-side `BPF_PROG_JIT_RECOMPILE` rejection rather than policy lookup drift.
