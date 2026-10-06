# Corpus YAML v2 Implementation Report

Date: 2026-03-26

## Summary

Implemented the corpus YAML v2 restructure as an object-centric schema with `schema_version: 2` and per-object `programs:` sublists.

Scope completed:

- Added `corpus/scripts/migrate_v1_to_v2.py`
- Migrated `corpus/config/macro_corpus.yaml` from v1 flat `programs:` entries to v2 `objects:`
- Reworked `corpus/modes.py` to parse v2 objects/programs and build object-session batch plans
- Extended runner prepared-kernel reuse so one loaded object can serve multiple per-program compile/run jobs
- Wrote and ran verification

Current migrated corpus size:

- Objects: 477
- Programs: 2019

## Implementation Notes

### 1. Migration Script

`corpus/scripts/migrate_v1_to_v2.py` now:

- Groups v1 entries by `source`
- Validates program inventory with `runner/build/micro_exec list-programs --program <path>`
- Preserves execution metadata such as `test_method`, `prog_type`, `section`, `io_mode`, `test_input`, `input_size`, `trigger`, `trigger_timeout_seconds`, `family`, `category`, `level`, `description`, `hypothesis`, and `tags`
- Lifts only truly shared values to the object level
- Expands grouped `program_names` into individual `programs:` nodes
- Is rerunnable: if the manifest is already v2, it exits successfully without re-migrating

Special-case merge handling:

- `bcc/libbpf-tools/offcputime.bpf.o:sched_switch` appeared in both a single-program and grouped v1 entry.
- The migrator prefers the more specific fragment for per-program overrides.

### 2. `modes.py`

`corpus/modes.py` now:

- Accepts only v2 corpus manifests for `load_targets_from_yaml()`
- Resolves objects into `ResolvedObject` values with nested `ResolvedProgram` values
- Computes canonical names as `repo:object_relpath:program_name`
- Selects/filter programs within objects instead of flattening to one target per manifest entry
- Emits v2-style result payloads with `object_records` and `program_records`
- Aggregates by object, by repo, and overall

### 3. Runner / Batch Reuse

Runner changes added multi-program prepared-object reuse:

- `prepared_kernel_state` now tracks multiple loaded programs
- Prepared refs can be reused for:
  - program-specific compile-only inspection
  - `run-kernel`
  - `run-kernel-attach`
- REJIT application is tracked per program within a prepared object
- `batch_runner.cpp` validation now allows prepared refs/keys for attach-mode jobs and compile-only prepared refs

## Discovery Fallbacks

`list-programs` failed for 7 objects, which were migrated as object-only `compile_only` entries with `programs: []`:

- `corpus/build/cilium/bpf_lxc.bpf.o`
- `corpus/build/cilium/bpf_overlay.bpf.o`
- `corpus/build/cilium/bpf_xdp.bpf.o`
- `corpus/build/netbird/prog.bpf.o`
- `corpus/build/opentelemetry-ebpf-profiler/generic_probe.bpf.o`
- `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o`
- `corpus/build/opentelemetry-ebpf-profiler/sched_monitor.bpf.o`

## Verification

Commands run:

```bash
make runner
python3 corpus/scripts/migrate_v1_to_v2.py
python3 - <<'PY'
import yaml
with open('corpus/config/macro_corpus.yaml') as f:
    d = yaml.safe_load(f)
print(f"objects={len(d['objects'])} programs={sum(len(o.get('programs', [])) for o in d['objects'])}")
PY
python3 -m py_compile corpus/scripts/migrate_v1_to_v2.py
python3 -m py_compile corpus/modes.py
python3 - <<'PY'
from corpus import modes
report = modes.load_corpus_build_report(modes.DEFAULT_CORPUS_BUILD_REPORT)
objects, summary = modes.load_targets_from_yaml(modes.DEFAULT_MACRO_CORPUS_YAML, report, None, None)
print(len(objects), sum(len(obj.programs) for obj in objects), summary['selected_objects'], summary['selected_programs'])
PY
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- `make runner`: passed
- migration script: passed
- manifest count check: `objects=477 programs=2019`
- `py_compile corpus/scripts/migrate_v1_to_v2.py`: passed
- `py_compile corpus/modes.py`: passed
- loader smoke check against the build report: passed
- daemon tests: passed
  - `454 passed; 0 failed; 12 ignored`

## Files Changed

- `corpus/config/macro_corpus.yaml`
- `corpus/modes.py`
- `corpus/scripts/migrate_v1_to_v2.py`
- `runner/src/batch_runner.cpp`
- `runner/src/kernel_runner.cpp`
