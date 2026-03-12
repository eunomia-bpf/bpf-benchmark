# Policy v2 Authoritative Spec

Date: 2026-03-12

This document is the authoritative specification for the current policy format consumed by `scanner` and corpus tooling. It supersedes `docs/tmp/policy-configuration-design-v2.md`.

## 1. Status and Scope

- `scanner` is `version: 2` only.
- The current steady-state format is a per-program `version: 2` document with:
  - `program`
  - `default`
  - optional `families`
  - optional `sites`
- `families` is not a separate legacy mode. It is part of the current v2 schema and participates in normal rule selection.
- The selection priority is:
  - exact `site`
  - `family`
  - global `default`
- `version: 1` is deleted and no longer supported.

## 2. Normative YAML Schema

Recommended canonical shape:

```yaml
version: 2
program: "<program-name>"          # optional
default: apply|skip                # required; stock is a compatibility alias for skip
families:                          # optional
  <family>: apply|skip
sites:                             # optional; emit [] when unused
  - insn: <uint32>
    family: <family>
    action: apply|skip
```

### 2.1 Top-level Fields

| Field | Type | Required | Semantics |
| --- | --- | --- | --- |
| `version` | integer | yes | Must be exactly `2`. Any other version is rejected by `scanner`. |
| `program` | string | no | Human/tooling identifier for the target BPF program. Recommended to match the exact program name. Current C++ filtering logic does not validate it against the live program; selection is driven by discovered rule families/sites. |
| `default` | scalar string | yes | Baseline action for every live-discovered eligible rule before applying `families` or `sites` overrides. Normative values are `apply` or `skip`. `stock` is accepted as a compatibility alias and is semantically identical to `skip`. |
| `families` | mapping `<family> -> <action>` | no | Family-level override applied to all live-discovered rules in that family. If omitted, no family-level overrides exist. |
| `sites` | sequence of site objects | no | Exact override keyed by `(insn, family)` against the live-discovered program. If omitted or `[]`, there are no explicit site overrides. |

### 2.2 `sites[*]` Fields

| Field | Type | Required | Semantics |
| --- | --- | --- | --- |
| `insn` | non-negative integer | yes | Live instruction offset used as part of the exact site key. |
| `family` | scalar string | yes | Rule family for the exact site key. |
| `action` | scalar string | yes in the spec | Exact action override for this `(insn, family)` site. Current C++ parser also tolerates omission and defaults it to `apply`; Python parser does not. New policy files should always write it explicitly. |

### 2.3 Canonical Family Names

Use these canonical names in new policy files:

- `cmov`
- `wide`
- `rotate`
- `lea`
- `extract`
- `zero-ext`
- `endian`
- `branch-flip`

Both C++ and Python accept some aliases, but the accepted alias sets are not perfectly identical. New authoritative policy files should use only the canonical names above.

### 2.4 Validity Rules

Normatively, a valid v2 policy should satisfy all of the following:

- `version` is exactly `2`.
- `default` is `apply` or `skip`.
- `families`, if present, is a mapping from family name to `apply|skip`.
- `sites`, if present, is a list of mappings with `insn`, `family`, and explicit `action`.
- Duplicate `families` entries are invalid.
- Duplicate `sites` entries for the same `(insn, family)` are invalid.

Current parser tolerance is documented in Section 6; do not treat parser tolerance as the format contract.

## 3. Selection Semantics and Priority

Selection is evaluated against the rules discovered from the live program at apply time.

For each live-discovered eligible rule:

1. Start from `default`.
2. If `families[rule.family]` exists, replace the action with that family action.
3. If an exact `sites` entry matches `(rule.site_start, rule.family)`, replace the action with the site action.
4. Only rules whose final action is `apply` are compiled into the filtered v5 policy blob.

In short:

```text
site > family > default
```

### 3.1 Examples

Example A:

```yaml
version: 2
program: "demo"
default: apply
families:
  cmov: skip
sites: []
```

Effect:

- every live `cmov` site is skipped
- every other family is applied

Example B:

```yaml
version: 2
program: "demo"
default: apply
families:
  cmov: skip
sites:
  - insn: 45
    family: cmov
    action: apply
```

Effect:

- live `cmov@45` is applied because exact site override wins
- other live `cmov` sites are still skipped
- other families still follow `default: apply`

Example C:

```yaml
version: 2
program: "demo"
default: skip
sites:
  - insn: 4
    family: rotate
    action: apply
```

Effect:

- only live `rotate@4` is applied
- every other discovered rule is skipped

If a `sites` entry does not match any live `(insn, family)`, it has no effect and current `scanner` emits a warning that the site was not found in the live program.

## 4. Lifecycle and Recommended Usage

### 4.1 Generation Phase

Recommended steady-state generation flow:

1. Run an offline scan over the object or other pre-live artifact.
2. Derive a family-level policy from that scan result, tuning result, or heuristic.
3. Persist the result as a per-program v2 YAML.

Recommended steady-state policy shape:

- `default: apply` when most families should be enabled and only a few regressors need to be suppressed
- `families` for coarse, stable control such as `cmov: skip`
- `sites: []` unless there is a specific reason to pin exact sites

This is the shape now emitted by `corpus/generate_default_policies.py`: offline scan informs which families exist, but the persisted policy is typically family-level, not an offline exact-site allowlist.

### 4.2 Apply Phase

Apply-time flow:

1. Perform a live scan on the actual program instance being recompiled.
2. Discover the live eligible rules and their live `(insn, family)` coordinates.
3. Evaluate each live rule with `site > family > default`.
4. Compile the selected live rules into a filtered v5 policy blob.
5. Recompile/apply using that filtered blob.

The key point is that selection happens over live-discovered rules. A family-level policy therefore follows the live program naturally. A site-level policy only works when the stored `(insn, family)` still matches the live program exactly.

### 4.3 Why Per-Site `insn` Offsets Are Fragile

Exact site offsets are brittle across offline scan and live apply because the live xlated program may differ from the offline-scanned artifact. Causes include:

- libbpf/load-time transformations
- verifier rewriting or normalization
- attach-specific lowering differences
- changes in live xlated control flow
- live-only family inventory changes

This means an offline site such as `endian@173` or `cmov@45` may appear at different live offsets, or a live program may gain families that were not visible in the offline artifact. Under `default: skip`, an offline exact-site allowlist can therefore collapse into "apply nothing" once those stored coordinates drift.

For that reason:

- family-level policy is the recommended steady-state mechanism
- exact `sites` should be treated as targeted override/debug/experiment machinery
- avoid relying on offline exact-site allowlists as the primary steady-state artifact

## 5. Difference from Removed v1

Old v1 is not a supported input language anymore.

The removed v1 design used a different schema centered on family-level allowlist/denylist configuration. That format is gone.

Current differences from the removed v1 world:

- `scanner` only accepts `version: 2`
- the old `version: 1` schema is rejected
- the old `selection.mode` schema is gone
- current `families` is a v2 field inside the single current schema, not a separate legacy format
- there is no backward-compatibility path in the `scanner` parser

Migration rule:

- rewrite old files into the v2 schema described in this document
- do not expect runtime compatibility with old policy documents

## 6. Known Python vs C++ Parser Differences

The v2 format contract is this document. Current parser implementations still have a few known differences.

| Topic | C++ scanner parser | Python corpus parser/renderer | Guidance |
| --- | --- | --- | --- |
| Missing `sites[*].action` | Accepted; defaults to `apply` | Rejected | Always write explicit `action` in every site entry. |
| Duplicate `families` entries in YAML text | Rejected after family-name normalization | PyYAML mapping load can silently collapse duplicate keys before `parse_policy_v2()` sees them; practical behavior is often last-key-wins, not an explicit parser error | Treat duplicate family keys as invalid and avoid relying on YAML-loader behavior. |
| Duplicate `sites` entries for the same `(insn, family)` | Rejected | Accepted and preserved in order | Treat duplicates as invalid; new authoritative files must not contain them. |
| `default: stock` | Accepted and normalized to `skip` in the C++ config object | Accepted as a literal default string and preserved as `stock` in the Python document object | Prefer writing `skip` in new files; treat `stock` only as a compatibility alias. |

There is also alias skew at the family-name level. To avoid cross-parser surprises, use only the canonical family names from Section 2.3.

## 7. Recommended Examples

### 7.1 Minimal Policy

Apply every live-discovered eligible rule:

```yaml
version: 2
program: "xdp_pass"
default: apply
sites: []
```

### 7.2 Skip `cmov`

Use family-level suppression for a known regressor:

```yaml
version: 2
program: "xdp_pass"
default: apply
families:
  cmov: skip
sites: []
```

### 7.3 Fine-Grained Control

Start from `skip`, then explicitly enable selected sites:

```yaml
version: 2
program: "mixed-demo"
default: skip
sites:
  - insn: 4
    family: rotate
    action: apply
  - insn: 41
    family: endian
    action: apply
```

This form is valid, but it is intentionally more fragile than the family-level example above because it depends on exact live `(insn, family)` coordinates remaining stable.

## 8. Authoritative Guidance

For new steady-state policy artifacts:

- write `version: 2`
- include `program`
- use `apply`/`skip`, not `stock`
- use canonical family names only
- prefer family-level policy
- keep `sites` empty unless exact-site control is intentionally required

If this document and any older design note disagree, this document wins.
