# Parser Consistency Fix

Date: 2026-03-12

## Goal

Align Python `parse_policy_v2()` and C++ `parse_policy_config_text()` on one v2 policy contract, then lock that contract down with shared golden YAML cases.

## Chosen Contract

- `sites[*].action` is required. Missing action is now rejected on both sides.
- Duplicate YAML mapping keys are invalid.
- Duplicate `sites` entries for the same normalized `(insn, family)` are invalid.
- `default: stock` remains accepted as a compatibility alias, but both parsers now normalize it to `skip`.
- Selection priority remains `site > family > default`.

## Code Changes

- `corpus/policy_utils.py`
  - Added a duplicate-key YAML loader for policy parsing.
  - Normalize `default: stock` to `skip` in `parse_policy_v2()`.
  - Reject duplicate normalized site keys.
- `scanner/src/policy_config.cpp`
  - Require every `sites[*]` entry to carry an explicit scalar `action`.
- Shared tests
  - Added shared golden policies under `scanner/tests/policy_v2_golden/`.
  - Added Python assertions in `corpus/tests/test_policy_utils.py`.
  - Added C++ assertions in `scanner/tests/test_scanner.cpp`.

## Golden Cases

Shared files under `scanner/tests/policy_v2_golden/`:

| File | Expected result |
| --- | --- |
| `01-valid-empty.yaml` | valid; `default=skip`; selects no rules |
| `02-valid-stock-alias.yaml` | valid; `default=stock` normalizes to `skip`; selects no rules |
| `03-valid-family-site-precedence.yaml` | valid; family + site override; selects only `cmov@0` |
| `04-valid-family-alias.yaml` | valid; `cond_select` normalizes to `cmov`; selects only `cmov@0` |
| `05-valid-site-only-apply.yaml` | valid; exact-site allowlist; selects only `rotate@4` |
| `06-invalid-missing-site-action.yaml` | invalid; missing `sites[*].action` |
| `07-invalid-duplicate-site.yaml` | invalid; duplicate `(insn, family)` |
| `08-invalid-duplicate-family-alias.yaml` | invalid; `cond-select` + `cmov` collide after normalization |
| `09-invalid-duplicate-family-key.yaml` | invalid; repeated YAML key |

Behavioral assertions use the same live-discovered toy rule set in both languages:

- `cmov@0`
- `rotate@4`

That keeps the parser contract and the effective selection semantics tied together.

## Validation

Executed:

- `cmake --build scanner/build -j$(nproc)`
- `ctest --test-dir scanner/build --output-on-failure`
- `python3 -m unittest corpus.tests.test_policy_utils`
- `python3 -m py_compile corpus/policy_utils.py corpus/tests/test_policy_utils.py`

All passed locally.
