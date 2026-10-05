# Scanner `pattern_kind` Filtering Investigation

Date: 2026-03-13

## Executive Summary

`pattern_kind` **was a real filtering bug in committed scanner code**, not just a documentation mistake.

- In committed history, `scanner/src/policy_config.cpp::filter_rules_by_policy_detailed()` matched policy sites by `(insn, family)` and ignored `pattern_kind`.
- In the **current working tree**, that bug is already fixed locally: the filter key now includes `pattern_kind`, and the scanner tests were updated to require exact kind matching.
- Python `corpus/policy_utils.py` is **not affected by the same exact bug**. Its v3 parser requires `pattern_kind`, and `remap_policy_v3_to_live()` matches by `(family, pattern_kind)`. Its remaining problem is different: remap is order-based and not site-stable when multiple live sites share the same `(family, pattern_kind)`.

## Direct Answers

### 1. Is `pattern_kind` really used correctly in the current filter?

Yes, in the current working tree it is.

Evidence:

- `scanner/src/policy_config.cpp:182-203` defines `V5PolicySiteKey` with `insn`, `family`, and `pattern_kind`.
- `scanner/src/policy_config.cpp:256-263` converts parsed policy entries into that full key.
- `scanner/src/policy_config.cpp:446-451` now builds the lookup key from:
  - `rule.site_start`
  - `rule.family`
  - `rule_pattern_kind(rule)`
- `scanner/tests/test_scanner.cpp:637-653` now verifies that a policy with `pattern_kind: mismatch-pattern` produces zero matches and one warning.
- `scanner/tests/test_scanner.cpp:586-634` also verifies that two rules at the same `insn` and `family` but different rotate widths are distinguished correctly.

So the current worktree behavior is:

- parse: `pattern_kind` is required and stored
- filter: `pattern_kind` participates in lookup
- output: `pattern_kind` is emitted into both JSON manifest and generated YAML policy templates

Output path evidence:

- `scanner/src/policy_config.cpp:524-543` stores `pattern_kind` into `V5ScanManifestSite`.
- `scanner/src/policy_config.cpp:573-581` emits `pattern_kind` and `site_id` in JSON.
- `scanner/src/policy_config.cpp:600-606` emits `pattern_kind` into generated v3 YAML.
- `scanner/tests/test_scanner.cpp:891-913` checks both JSON and YAML output.

### 2. If the bug exists, which code path is affected?

It existed in the **committed scanner filter path**, not in the current local worktree.

Historical evidence:

- `git show da10f84:scanner/src/policy_config.cpp` shows that v3 parsing already stored `pattern_kind`, but filtering used a separate `V5RuleSiteKey` containing only `insn` and `family`.
- In that version, `filter_rules_by_policy_detailed()` used:
  - `explicit_sites.emplace(V5RuleSiteKey{ .insn = site.insn, .family = site.family }, index);`
  - `V5RuleSiteKey key{ .insn = rule.site_start, .family = rule.family };`
- `git show da10f84:scanner/tests/test_scanner.cpp` shows the mismatch test expected a policy with `pattern_kind: mismatch-pattern` to still match the rotate rule.

That means the bug affected every path that consumes a v3 policy and then calls `filter_rules_by_policy_detailed()`:

- `scanner/src/cli.cpp:851-876` (`compile-policy`)
- `scanner/src/cli.cpp:879-920` (`apply` with `--config`)
- `micro/runner/src/kernel_runner.cpp:1166-1223` (`kernel-recompile` when given a policy config)

The architecture review in `docs/tmp/architecture-review-and-diagrams.md:100-101` correctly described the committed bug, but it is now stale relative to the current working tree because the local code and tests already changed.

### 3. Does this affect v3 policy site matching?

Yes, but only on the direct scanner-side v3 filter path.

#### Scanner-side v3 matching

Affected historically:

- A v3 policy site with the right `insn` and `family` but the wrong `pattern_kind` could still match.
- This mattered when multiple rule variants shared the same `(insn, family)` and differed only by `pattern_kind`.

Not affected in the current worktree:

- The local filter fix closes that gap.

#### Python-side v3 remap

Not affected by the same exact bug:

- `corpus/policy_utils.py:190-201` requires non-empty `pattern_kind`.
- `corpus/policy_utils.py:321-369` groups live sites by `(family, pattern_kind)` and remaps only within that bucket.
- `corpus/tests/test_policy_utils.py:72-121` now verifies exact kind matching and mismatch drop behavior.

But Python still has a separate site-identity issue:

- `remap_policy_v3_to_live()` ignores the original policy `insn` once remap starts.
- If multiple live sites share the same `(family, pattern_kind)`, remap picks them by encounter order.
- This is the issue already called out in `docs/tmp/architecture-review-and-diagrams.md:113-120`.

So the answer is:

- `pattern_kind` bug: scanner direct filter path
- site-stability issue: Python live remap path

They are related, but they are not the same bug.

## Parse -> Filter -> Output Trace

### Scanner C++

Parse:

- `scanner/include/bpf_jit_scanner/policy_config.hpp:13-23`
- `scanner/src/policy_config.cpp:298-359`

Filter:

- `scanner/src/policy_config.cpp:428-480`
- `scanner/src/cli.cpp:860-863`
- `scanner/src/cli.cpp:891-893`
- `micro/runner/src/kernel_runner.cpp:1192-1199`

Output:

- `scanner/src/policy_config.cpp:524-543`
- `scanner/src/policy_config.cpp:545-587`
- `scanner/src/policy_config.cpp:589-607`

### Python

Parse/render:

- `corpus/policy_utils.py:190-241`

Live remap:

- `corpus/policy_utils.py:307-409`
- `e2e/common/recompile.py:236-268`

Generated per-program policies also preserve `pattern_kind`:

- `corpus/generate_default_policies.py:370-393`

## Validation

Commands run:

```bash
cmake --build scanner/build --target test_scanner -j
./scanner/build/test_scanner
python3 -m unittest corpus.tests.test_policy_utils
```

Results:

- `test_scanner`: `PASS 179`
- `corpus.tests.test_policy_utils`: `Ran 4 tests ... OK`

## Final Conclusion

This was **not** a false positive in committed scanner code. The bug was real in the v3 policy filter path and affected `compile-policy`, `apply --config`, and micro runner policy-config filtering.

However, the **current working tree already contains a local fix** plus updated tests. The only remaining item from this investigation was to document the exact status:

- committed history: bug exists
- current worktree: bug fixed locally
- Python remap: exact `pattern_kind` matching is correct, but site identity is still order-based
