# #122 v2 Pipeline Migration Report

Date: 2026-03-12

## Scope

This migration moved the corpus policy pipeline from the old v1 family-level schema to the v2 per-site schema:

```yaml
version: 2
program: <name>
default: apply|skip|stock
sites:
  - {insn: <offset>, family: <name>, action: apply|skip}
```

Completed work:

- `scanner` policy parsing is now v2-only.
- `corpus/generate_default_policies.py` now emits per-program v2 per-site YAML.
- `corpus/auto_tune.py` now writes v2 per-site YAML.
- corpus/e2e policy resolution now expects per-program v2 policy files.
- `corpus/policies/` was regenerated as a full v2 tree.
- Remaining object-level v1 policy path usage was removed from `corpus/policy_utils.py`; the Calico sweep helper was updated to start from the current per-program v2 policy instead of legacy object-level files.

## Code Changes

### Scanner

- `scanner/src/policy_config.cpp` and `scanner/include/bpf_jit_scanner/policy_config.hpp`
  - removed v1 parsing and fallback logic
  - require `version: 2`
  - require `default`
  - require `sites`
  - keep only v2 per-site filtering semantics
- `scanner/tests/test_scanner.cpp`
  - removed v1 compatibility tests
  - added v2-only filter and validation coverage
- `scanner/src/cli.cpp`, `scanner/README.md`
  - updated CLI/help/docs to refer to version 2 policy files

### Corpus / E2E

- `corpus/generate_default_policies.py`
  - enumerates programs with `micro_exec list-programs`
  - obtains site offsets from scanner JSON output
  - writes per-program v2 YAML under `corpus/policies/<relpath>/<object-stem>/<program>.policy.yaml`
  - falls back to `--xlated` scanning when direct object scanning fails for a program
  - preserves the CMOV regressor heuristic when generating defaults
- `corpus/auto_tune.py`
  - renders v2 per-site policy artifacts from the winning manifest/allowlist
- `corpus/policy_utils.py`
  - v2-only parsing/rendering
  - per-program path resolution only
  - removed legacy object-level policy path helper
  - fixed `sanitize_program_name()` so leading underscores are preserved; this eliminated filename collisions such as `blk_account_io_start` vs `__blk_account_io_start`
- `corpus/_driver_impl_run_corpus_v5_framework.py`
- `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
- `e2e/common/recompile.py`
  - steady-state policy lookup now uses per-program v2 files
- `corpus/run_bflip_endian_skip_sweep.py`
  - no longer reads legacy object-level v1 policies
  - now derives Round 2 / Round 3 variants from the current per-program v2 policy and then forces additional family skips

## Policy Regeneration

Command:

```bash
python3 corpus/generate_default_policies.py --workers 8
```

Final successful verification run summary:

- `scanned_objects=560`
- `site_positive_objects=150`
- `site_positive_programs=580`
- `policies=written=580`
- `cmov_skip_objects=18`
- `cmov_skip_programs=222`
- `stale_removed=0`
- `warnings=111`
- `results_json=corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`

Notes on warnings:

- These were best-effort skips, not hard failures.
- Main categories were:
  - Cilium objects with static tail-call programs that `micro_exec list-programs` cannot inventory.
  - Datadog objects that require unavailable BTF/extern context during inventory.
  - Many linux-selftests objects that do not contain a normal loadable program for this pipeline.

Generated artifact checks:

- policy file count: `580`
- no remaining `version: 1` / `families:` files under `corpus/policies/`
- YAML validation over all generated files: `count=580`, `bad_count=0`
- policy filename collision check after the sanitizer fix: `policy_dir_collision_count=0`

## Validation

### Build

```bash
cmake --build scanner/build -j$(nproc)
```

Result: passed

### Scanner Tests

```bash
ctest --test-dir scanner/build --output-on-failure
```

Result: passed (`1/1` tests passed)

### Python Syntax

```bash
python3 -m py_compile \
  corpus/generate_default_policies.py \
  corpus/auto_tune.py \
  corpus/policy_utils.py \
  corpus/_driver_impl_run_corpus_v5_framework.py \
  corpus/_driver_impl_run_corpus_v5_vm_batch.py \
  e2e/common/recompile.py \
  corpus/run_bflip_endian_skip_sweep.py
```

Result: passed

### Generated Policy Format

Checks:

```bash
find corpus/policies -type f -name '*.policy.yaml' | wc -l
rg -n "^version:\\s*1$|^families:" corpus/policies -g'*.policy.yaml'
python3 - <<'PY'
from pathlib import Path
import yaml
bad = []
count = 0
for path in Path('corpus/policies').rglob('*.policy.yaml'):
    count += 1
    data = yaml.safe_load(path.read_text())
    if not isinstance(data, dict) or data.get('version') != 2 or not isinstance(data.get('sites'), list):
        bad.append(str(path))
print({'count': count, 'bad_count': len(bad)})
PY
```

Result:

- `find ... | wc -l` => `580`
- `rg ...` => no matches
- YAML validation => `{'count': 580, 'bad_count': 0}`

### `compile-policy` Smoke Test

Command:

```bash
scanner/build/bpf-jit-scanner compile-policy \
  corpus/build/KubeArmor/enforcer.bpf.o \
  --program-name enforce_cap \
  --config corpus/policies/KubeArmor/enforcer/enforce_cap.policy.yaml \
  --output /tmp/test.blob
```

Result:

- passed
- output: `Wrote 296-byte filtered v5 policy blob (2/2 rules) to /tmp/test.blob`

## Conclusion

`#122` v2 pipeline migration is complete for the requested path:

- scanner parsing is v2-only
- policy generation/tuning emits v2 per-site YAML
- corpus/e2e steady-state policy lookup uses per-program v2 files
- `corpus/policies/` is fully regenerated as v2
- required build/test/py_compile/regeneration/format/compile-policy checks all passed
