# Per-Program Pass Policy Design

## Goal

Add a minimal YAML policy format in `benchmark_config.yaml` so the Python scheduler can choose different REJIT pass sets per program without changing the daemon or the C++ runner.

## YAML Format

Top-level schema:

```yaml
policy:
  default:
    passes: [const_prop, dce, wide_mem]
  rules:
    - match:
        prog_type: xdp
      enable: [map_inline, endian_fusion]
    - match:
        prog_type: kprobe
      passes: [const_prop]
    - match:
        repo: katran
      enable: [map_inline]
    - match:
        has_sites: [map_inline]
      enable: [map_inline]
```

Semantics:

- Start from `policy.default.passes`.
- Apply `policy.rules` in order.
- `passes` replaces the current pass list.
- `enable` appends unique pass names.
- `disable` removes pass names.
- `match` fields are ANDed together.

Supported `match` keys:

- `repo`
- `object` (object basename, for example `balancer.bpf.o`)
- `object_relpath`
- `object_path`
- `program`
- `section`
- `prog_type`
- `test_method`
- `attach_group`
- `family`
- `category`
- `level`
- `has_sites`

`has_sites` matches when a scan reports `sites_found > 0` (or `sites_applied > 0`) for the named pass. This is the intended hook for rules like "only enable `map_inline` when the program actually has map-inline opportunities".

## Code Changes

### `runner/libs/rejit.py`

- Extended benchmark config loading to keep top-level `policy`.
- Added policy resolution helpers:
  - `benchmark_policy_required_site_passes(...)`
  - `resolve_program_enabled_passes(...)`
- `benchmark_config_enabled_passes(...)` now prefers `policy.default.passes` when present.
- Scan-derived site counts now prefer `sites_found` before `sites_applied`.

### `runner/libs/corpus.py`

- Added program-context extraction from `ResolvedProgram`.
- Added optional pre-scan for site-conditional rules using existing `static_verify_object` batch jobs.
- Added `resolve_program_enabled_passes_map(...)` to compute a pass list per program.
- Changed REJIT batch planning so each program gets its own REJIT prepared job and its own `enabled_passes`.

Why the REJIT prepare job changed:

- The existing batch runner applies daemon REJIT object-wide when a prepared state contains multiple loaded programs.
- That would leak one program's pass list onto sibling programs in the same prepared object.
- The Python planner now creates program-scoped REJIT prepared jobs, so each optimize request uses the intended pass set.

### `corpus/modes.py`

- Stopped collapsing benchmark config into one global pass list before calling `run_objects_locally_batch(...)`.
- Now passes `benchmark_config` through so the lower layer can resolve per-program policy.

### `corpus/config/benchmark_config.yaml`

- Added a `policy` scaffold with `default.passes` equal to the existing `performance` pass set.
- `rules` is empty by default, so current behavior stays unchanged.

## Usage Examples

Aggressive XDP, conservative kprobe:

```yaml
policy:
  default:
    passes: [const_prop, dce, wide_mem]
  rules:
    - match: {prog_type: xdp}
      enable: [map_inline, endian_fusion]
    - match: {prog_type: kprobe}
      passes: [const_prop]
```

Enable `map_inline` only for Katran programs:

```yaml
policy:
  default:
    passes: [const_prop, dce]
  rules:
    - match: {repo: katran}
      enable: [map_inline]
```

Enable `map_inline` only when scan data says the program has such sites:

```yaml
policy:
  default:
    passes: [const_prop, dce]
  rules:
    - match: {has_sites: [map_inline]}
      enable: [map_inline]
```

## Backward Compatibility

- If `policy` is absent, behavior stays on the legacy global `passes` config.
- Existing `passes.active`, `passes.active_list`, and named pass lists still work.
- Explicit `enabled_passes` passed into Python helpers still override policy and keep the old all-program behavior.
- No daemon changes.
- No C++ runner changes.

## Validation

Executed:

```bash
pytest tests/python/
```

Result: `45 passed`
