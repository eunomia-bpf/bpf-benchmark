# Live Policy Discovery Switch

Date: 2026-03-20

## Context

`corpus/generate_default_policies.py` was generating v3 YAMLs from offline object scans:

- inventory: `discover_object_programs(...)`
- site discovery: `scanner scan <object> --program-name ... --all --json`

That misses live-only families such as `branch-flip` when the family only appears after verifier / loader fixups. The shared E2E failure mode was:

- Katran: live `branch-flip` sites never entered the generated policy input
- Tetragon: several live programs had live `branch-flip` but no policy coverage
- Tracee: same class of policy/input drift

## What Changed

### 1. Common live-policy helpers

`runner/libs/policy.py`

- added `live_policy_dir()` and `live_policy_path_for_program()`
- added `resolve_live_policy_path()`
- added `policy_sites_from_manifest()` and `render_manifest_policy_v3_text()`
- split live family totals from explicit selected-family totals so generated-policy accounting is correct when `cmov` is skipped

### 2. `generate_default_policies.py` live mode

`corpus/generate_default_policies.py`

- kept the existing offline object-scan path as `mode=offline`
- added `--live` mode
- live mode discovers targets via `bpftool prog show` through `runner.libs.profiler.resolve_target_programs()`
- per program, it scans with `scanner enumerate --prog-id <id> --all --json`
- writes per-program live YAMLs under `corpus/policies/live/`
- added live filters:
  - `--prog-id`
  - `--name-contains`
  - `--type`
  - `--max-programs`
- stale cleanup is now mode-scoped:
  - offline runs no longer delete `corpus/policies/live/*`
  - live runs only prune stale files under the live policy subdir

The live YAML generation keeps the existing default selection model:

- explicit allowlist
- keep every discovered live site
- skip `cmov` by default unless `--skip-families` is changed

### 3. E2E recompile fallback

`runner/libs/recompile.py`

- `resolve_policy_files()` now prefers a live policy artifact from `corpus/policies/live/` before falling back to the object-derived corpus policy
- exported `enumerate_program_record()` for shared live enumerate use
- changed `apply_recompile()` behavior when no pre-generated policy is found:
  - old behavior: stock/no-op
  - new behavior: enumerate the live program, auto-generate a temporary live-derived v3 policy, then apply `enumerate --prog-id --recompile`
- auto-generated fallback policy mode is reported as `live-auto-policy`
- fallback policy uses the same default skip rule as corpus generation: skip `cmov`, keep the rest

This closes the shared E2E gap without touching each case file separately.

### 4. Tests

Added `tests/test_live_policy_discovery.py` covering:

- manifest-to-policy rendering with live vs explicit family counts
- live policy path resolution
- resolver preference for live policy artifacts
- `apply_recompile()` auto-generation when no policy file is configured

## Validation

Commands run locally on 2026-03-20:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 -m py_compile \
  corpus/generate_default_policies.py \
  runner/libs/policy.py \
  runner/libs/recompile.py \
  runner/libs/profiler.py \
  runner/scripts/profile_guided_policy.py \
  tests/test_live_policy_discovery.py
```

Result: OK

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 -m unittest discover -s tests -p 'test_*.py'
```

Result: `Ran 8 tests ... OK`

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make smoke
```

Result: OK

Additional smoke checks for the policy generator:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 corpus/generate_default_policies.py --dry-run --max-objects 1 --filter libbpf-bootstrap/examples/c/profile
```

Result: script ran successfully in `mode=offline`

```bash
source /home/yunwei37/workspace/.venv/bin/activate
sudo -n python3 corpus/generate_default_policies.py --live --dry-run --prog-id 52
```

Result:

- `would write corpus/policies/live/00052_s_snapd_desktop.policy.yaml`
- `summary: mode=live ... policies=planned=1`

Notes:

- direct non-root `bpftool prog show` failed with `Operation not permitted`
- `sudo -n` worked in this environment, so the live CLI path was exercised without VM use

## Limitations

- No VM validation was run, per task constraint.
- I did not rerun full Katran / Tetragon / Tracee E2E workloads on a live benchmark VM.
- Persisted live policies are currently written under `corpus/policies/live/` and keyed primarily by current live program identity; the critical correctness path is the new runtime fallback in `apply_recompile()`, which does not depend on those files already existing.

## Expected Impact

The shared policy-discovery root cause is removed:

- offline corpus policy generation can remain for corpus characterization
- live enumerate is now available for real runtime policy generation
- E2E recompile no longer turns into stock/no-op just because a program lacks a pre-generated object-derived policy

That should allow Katran / Tetragon / Tracee live-only families, especially `branch-flip`, to enter the candidate policy set instead of being dropped at discovery time.
