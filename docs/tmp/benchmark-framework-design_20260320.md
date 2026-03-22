# Benchmark Framework Design

Date: 2026-03-20

This document is based on an actual read of the current tree under `micro/`, `corpus/`, `e2e/`, `scanner/`, `scripts/`, `config/`, and `tests/`, plus `Makefile`, `micro/Makefile`, `CLAUDE.md`, and `docs/kernel-jit-optimization-plan.md` sections 4.4 and 5.6. `vendor/` was intentionally not expanded.

The design below makes section 5.6 concrete and keeps section 4.4's three-layer safety model intact: policy intent stays in YAML, scanner remains the validation and blob-construction layer, and the kernel only sees a compiled blob.

## 1. Current State Analysis

### 1.1 Actual top-level tree

```text
.
├── CLAUDE.md
├── Makefile
├── README.md
├── REVIEW.md
├── build-arm64/
├── config/
├── corpus/
├── docker/
├── docs/
├── e2e/
├── legacy/
├── micro/
├── reference/
├── requirements.txt
├── scanner/
├── scripts/
├── tests/
├── tmp/
└── vendor/           # intentionally not expanded for this review
```

### 1.2 File counts

Counts below are actual counts from the current tree, excluding `vendor/`.

| Directory | Total files now | First-party framework files | Notes |
| --- | ---: | ---: | --- |
| `micro/` | 1,734 | 560 | Total includes build outputs, generated inputs, JIT dumps, and committed results |
| `corpus/` | 23,243 | 41 | Total is dominated by `repos/`, `bcf/`, policy data, and results |
| `e2e/` | 112 | 45 | Total includes results plus bundled Katran binaries/libs |
| `scanner/` | 93 | 22 | Total includes `build/` and `build-arm64/` outputs |
| `scripts/` | 3 | 2 | One `.pyc` lives under `scripts/__pycache__/` |
| `config/` | 1 | 1 | One benchmark manifest today |
| `tests/` | 65 | 17 | Total includes `tests/kernel/build/` outputs |

`First-party framework files` excludes generated/build/result trees and imported corpora (`corpus/repos`, `corpus/bcf`), so it is the useful count for architecture work.

### 1.3 Directory structure by area

#### `micro/`

```text
micro/
├── Makefile
├── README.md
├── driver.py
├── _driver_impl_run_micro.py
├── _driver_impl_run_rigorous.py
├── _driver_impl_run_rigorous_framework_vm.py
├── benchmark_catalog.py
├── input_generators.py
├── results_layout.py
├── compare_results.py
├── generate_figures.py
├── summarize_rq.py
├── dump_all_jit.sh
├── run_corpus_tracing.sh
├── orchestrator/
│   ├── benchmarks.py
│   ├── catalog.py
│   ├── commands.py
│   ├── corpus.py
│   ├── environment.py
│   ├── inventory.py
│   ├── reporting.py
│   ├── results.py
│   └── rigorous.py
├── programs/
│   ├── Makefile
│   ├── common.h
│   ├── 62x `*.bpf.c`
│   ├── 62x `*.bpf.o`
│   ├── 62x `*.bpf.d`
│   ├── 7x generated `*.bin`
│   └── `.build.stamp`
├── policies/
│   ├── 35 top-level benchmark policy files
│   ├── ablation/
│   └── variants/
├── runner/
│   ├── CMakeLists.txt
│   ├── include/micro_exec.hpp
│   └── src/
│       ├── common.cpp
│       ├── elf_program_loader.cpp
│       ├── kernel_runner.cpp
│       ├── llvmbpf_runner.cpp
│       ├── main.cpp
│       └── perf_counters.cpp
├── generated-inputs/   # generated
├── jit-dumps/          # generated
├── results/            # committed outputs + dev outputs
├── build/              # generated
└── build-arm64/        # generated
```

Immediate file counts:

| Path | Files |
| --- | ---: |
| `micro/` | 15 |
| `micro/orchestrator/` | 10 |
| `micro/programs/` | 196 |
| `micro/policies/` | 35 top-level files, plus large `ablation/` and `variants/` trees |
| `micro/runner/include/` | 1 |
| `micro/runner/src/` | 6 |
| `micro/generated-inputs/` | 66 |
| `micro/jit-dumps/` | 133 |
| `micro/results/` | 8 immediate files |

Key structural facts:

- `micro/orchestrator/` is already a proto-shared library.
- `micro/runner/` is the current C++ execution binary, but it lives under `micro/` even though corpus and e2e depend on the same concepts.
- `micro/programs/` mixes sources and build artifacts in one directory.
- `micro/driver.py` dispatches both micro and corpus modes, so `micro/` is not actually isolated.

#### `corpus/`

```text
corpus/
├── README.md
├── inventory.json
├── repos.yaml
├── common.py
├── policy_utils.py
├── results_layout.py
├── _driver_impl_run_corpus_perf.py
├── _driver_impl_run_corpus_tracing.py
├── _driver_impl_run_corpus_tracing_exec.py
├── _driver_impl_run_corpus_v5_framework.py
├── _driver_impl_run_corpus_v5_vm_batch.py
├── _driver_impl_run_macro_corpus.py
├── _driver_impl_run_production_corpus_v5_framework.py
├── _driver_impl_run_tracing_corpus_vm.py
├── analyze_bytecode.py
├── auto_tune.py
├── build_expanded_corpus.py
├── directive_census.py
├── fetch_bcf_dataset.py
├── fetch_real_world_corpus.py
├── generate_default_policies.py
├── run_code_size_comparison.py
├── run_corpus_runnability.py
├── run_real_world_code_size.py
├── run_real_world_exec_time.py
├── config/
│   ├── corpus_manifest.yaml
│   └── macro_corpus.yaml
├── include/
│   └── netbird_legacy_bpf_map_def.h
├── inputs/
│   ├── macro_dummy_context_64.bin
│   └── macro_dummy_packet_64.bin
├── tests/
│   └── test_policy_utils.py
├── tmp/
│   └── cross_domain_census.py
├── policies/          # very large per-program policy tree
├── repos/             # imported source trees
├── bcf/               # object corpus
├── build/             # generated corpus builds
└── results/
```

Immediate file counts:

| Path | Files |
| --- | ---: |
| `corpus/` | 26 |
| `corpus/config/` | 2 |
| `corpus/include/` | 1 |
| `corpus/inputs/` | 2 |
| `corpus/tests/` | 1 |
| `corpus/tmp/` | 1 |
| `corpus/results/` | 9 immediate files |

Key structural facts:

- Corpus has 8 private driver implementations.
- `corpus/common.py` is effectively a second shared-library layer on top of `micro.orchestrator`.
- `corpus/policy_utils.py` is the real shared policy module today, but it lives under `corpus/` and is imported by e2e.
- `corpus/repos/`, `corpus/bcf/`, and `corpus/policies/` dominate the tree size.

#### `e2e/`

```text
e2e/
├── README.md
├── __init__.py
├── run.py
├── run_e2e_tracee.py
├── common/
│   ├── __init__.py
│   ├── agent.py
│   ├── metrics.py
│   ├── recompile.py
│   ├── vm.py
│   └── workload.py
├── cases/
│   ├── bpftrace/
│   │   ├── case.py
│   │   └── scripts/*.bt
│   ├── katran/
│   │   ├── case.py
│   │   ├── setup.sh
│   │   ├── balancer_ingress.e2e.policy.yaml
│   │   ├── bin/...
│   │   └── lib/...
│   ├── scx/
│   │   └── case.py
│   ├── tetragon/
│   │   ├── case.py
│   │   ├── setup.sh
│   │   └── guest_smoke.sh
│   └── tracee/
│       ├── case.py
│       ├── setup.sh
│       └── config.yaml
└── results/
```

Immediate file counts:

| Path | Files |
| --- | ---: |
| `e2e/` | 4 |
| `e2e/common/` | 7 |
| `e2e/cases/` | 2 immediate files plus per-case trees |
| `e2e/results/` | 8 immediate files |

Key structural facts:

- `e2e/common/` has real shared code, but some of it should be global shared code rather than e2e-private code.
- All five checked-in cases have near-identical orchestration structure.
- `run_e2e_tracee.py` is legacy in style, but it is still live because `e2e/cases/tracee/case.py` imports `Libbpf` and `ManualTraceeSession` from it.

#### `scanner/`

```text
scanner/
├── CMakeLists.txt
├── README.md
├── cmake/bpf_jit_scannerConfig.cmake.in
├── include/bpf_jit_scanner/
│   ├── pattern_v5.hpp
│   ├── policy_config.hpp
│   └── types.h
├── src/
│   ├── cli.cpp
│   ├── pattern_v5.cpp
│   └── policy_config.cpp
├── tests/
│   ├── test_scanner.cpp
│   └── policy_v3_golden/*.yaml
├── build/            # generated
└── build-arm64/      # generated
```

Key structural facts:

- Scanner is already architecturally separate and should stay that way.
- The scanner CLI already exposes the right conceptual boundary: `scan`, `enumerate`, `apply`, `generate-policy`, `compile-policy`, `dump`.
- The build output directories should not be treated as framework source.

#### `scripts/`, `config/`, and `tests/`

```text
scripts/
├── arm64_qemu_smoke.py
└── aws_arm64.sh

config/
└── micro_pure_jit.yaml

tests/
└── kernel/
    ├── Makefile
    ├── README.md
    ├── test_recompile.c
    └── progs/
        ├── 13x `test_*.bpf.c`
```

Key structural facts:

- `scripts/` is already mostly infra-only.
- `config/` is underused; corpus manifests are still in `corpus/config/`.
- `tests/` only contains kernel selftests today; Python tests are split out into `corpus/tests/`.

### 1.4 Current shared-code islands

#### `micro/orchestrator/`

This is the closest thing to the desired `runner/libs/` today.

- `benchmarks.py`: benchmark selection and input resolution
- `catalog.py`: manifest loader for micro and macro/corpus manifests
- `commands.py`: `micro_exec` command construction
- `corpus.py`: subprocess helpers, dummy packet/context generation, section normalization, execution plans, markdown helpers, scanner command helpers
- `environment.py`: build/environment checks
- `inventory.py`: object/program discovery and inventory parsing
- `reporting.py`: RQ/report aggregation and formatting
- `results.py`: runner JSON parsing and normalization
- `rigorous.py`: extracted rigorous-benchmark helper/statistics/environment logic

#### `e2e/common/`

- `__init__.py`: path helpers, output path helpers, subprocess helpers, root/sudo helpers, bpftool resolution
- `agent.py`: agent process lifecycle and BPF program discovery by PID
- `metrics.py`: `BpfProgInfo`, BPF stats, CPU usage
- `recompile.py`: live-program scan/apply orchestration and policy resolution
- `vm.py`: guest script creation and VM execution
- `workload.py`: reusable workload generators

### 1.5 `_driver_impl_*.py` inventory and overlap

#### Micro drivers: 3 files

| File | Role | Overlap |
| --- | --- | --- |
| `_driver_impl_run_micro.py` | main micro suite runner | Local subprocess/result formatting helpers duplicate corpus/e2e patterns |
| `_driver_impl_run_rigorous.py` | local rigorous runner | Large overlap with `micro/orchestrator/rigorous.py` |
| `_driver_impl_run_rigorous_framework_vm.py` | VM rigorous runner | Shares VM guest-script/build/info logic with corpus VM batch code |

#### Corpus drivers: 8 files

| File | Role | Overlap |
| --- | --- | --- |
| `_driver_impl_run_macro_corpus.py` | declarative macro corpus suite | Re-implements runtime/spec/catalog/statistics structures already present in micro |
| `_driver_impl_run_corpus_perf.py` | packet/test-run corpus measurement | Duplicates command building, dummy input generation, markdown/report logic |
| `_driver_impl_run_corpus_tracing.py` | attach/trigger tracing measurement | Duplicates libbpf wrappers, tracing helpers, report formatting |
| `_driver_impl_run_corpus_tracing_exec.py` | tracing-exec measurement, including VM path | Duplicates tracing wrappers, VM logic, summary/report code, and imports e2e helpers |
| `_driver_impl_run_tracing_corpus_vm.py` | VM wrapper around tracing-exec | Thin wrapper on another driver impl; duplicates guest orchestration |
| `_driver_impl_run_corpus_v5_framework.py` | selected 40-program framework-kernel corpus report | Duplicates runner command, ratios, summary, markdown logic |
| `_driver_impl_run_production_corpus_v5_framework.py` | production corpus framework-kernel measurement | Same ratio/summary/runner/BTF fallback logic as v5 framework scripts |
| `_driver_impl_run_corpus_v5_vm_batch.py` | current VM batch entrypoint | Duplicates runner/scanner command assembly, parsing, report logic, VM helpers |

Net result: corpus does not have one driver with multiple modes; it has eight partially overlapping runners.

### 1.6 Duplication inventory

I excluded trivial repeats like `main()` and `parse_args()`. The list below covers meaningful repeated logic.

#### Shared subprocess and path/output helpers

- `run_command` appears in 10 first-party files.
- `run_text_command` appears in 6 first-party files.
- `ensure_parent` appears in 8 first-party files.
- `relpath` appears in 8 first-party files.
- `authoritative_output_path`, `smoke_output_path`, `latest_output_path`, `refresh_latest_alias`, `maybe_refresh_latest_alias`, and `result_date_stamp` are duplicated across `micro/results_layout.py`, `corpus/results_layout.py`, and `e2e/common/__init__.py`.
- Those three result-layout implementations are not even consistent: `micro` timestamps include time-of-day, `corpus` and `e2e` only include date, and all three alias refresh helpers are currently no-ops.

#### Runner/scanner command construction

- `build_runner_command` appears in 6 first-party files.
- `build_kernel_command` appears in 3 first-party files.
- `parse_scanner_v5_output` exists in both `micro/orchestrator/corpus.py` and `corpus/common.py`.
- `scanner` invocation logic is split between `micro.orchestrator`, `corpus/common.py`, and `e2e/common/recompile.py`.

#### Dummy input materialization and section normalization

- `_ipv4_checksum` appears in 3 files.
- `materialize_dummy_packet` appears in 4 files.
- `materialize_dummy_context` appears in 3 files.
- `execution_plan` appears in 4 files.
- `canonical_section_root` / `normalize_section_root` logic is repeated across corpus scripts.

#### Rigorous benchmark logic

`micro/_driver_impl_run_rigorous.py` and `micro/orchestrator/rigorous.py` duplicate:

- CPU isolation/pinning detection
- governor/turbo inspection and mutation
- heavy-process detection
- bootstrap CI, Wilcoxon, BH adjustment
- mode resolution and command wrapping
- per-iteration output parsing

#### Catalog/spec duplication

- `micro/benchmark_catalog.py` and `micro/orchestrator/catalog.py` duplicate manifest-root/path helpers and overlapping spec types.
- `corpus/_driver_impl_run_macro_corpus.py` duplicates `RuntimeSpec` and `SuiteSpec` concepts that already exist in micro.

#### Tracing/libbpf wrappers

- `Libbpf` exists in 4 first-party files.
- `BpfProgInfo` exists in 4 first-party files.
- `LoadedTracingProgram` exists in both corpus tracing drivers.
- `decode_c_string` / `libbpf_error_string` are duplicated between corpus tracing and e2e tetragon code.

#### E2E case scaffolding

Across `tracee`, `bpftrace`, `katran`, `tetragon`, and `scx`:

- `ensure_artifacts` appears in 5 case files
- `measure_workload` appears in 4
- `run_phase` appears in 4
- `compare_phases` appears in 4
- `summarize_numbers` appears in 4
- `persist_results` appears in 4
- `build_case_parser` appears in 4
- `git_sha` appears in 6
- `host_metadata` appears in 7
- `build_markdown` appears in 14 first-party files across corpus and e2e

This is the strongest case for factoring shared report/phase scaffolding into one reusable layer.

### 1.7 Cross-layer dependencies

These violate the intended boundary `micro|corpus|e2e -> runner`, with no peer-to-peer imports.

| From | To | Current use |
| --- | --- | --- |
| `micro/driver.py` | `corpus/_driver_impl_*` | Micro is the top-level dispatcher for corpus modes |
| `corpus/common.py` | `micro.orchestrator.*` | Corpus wraps micro's shared helpers instead of owning a neutral shared layer |
| `corpus/_driver_impl_run_corpus_perf.py` | `micro.orchestrator.corpus`, `micro.orchestrator.inventory` | Corpus perf mode depends on micro shared internals |
| `corpus/_driver_impl_run_corpus_tracing.py` | `micro.orchestrator.corpus`, `micro.orchestrator.inventory` | Same |
| `corpus/_driver_impl_run_macro_corpus.py` | `micro.orchestrator.catalog`, `micro.orchestrator.inventory` | Macro corpus depends on micro manifest/inventory helpers |
| `corpus/_driver_impl_run_corpus_v5_vm_batch.py` | `micro.orchestrator.inventory`, `micro.orchestrator.results` | Corpus VM batch depends on micro inventory/results |
| `corpus/_driver_impl_run_corpus_tracing_exec.py` | `e2e.common`, `e2e.common.recompile`, `e2e.common.vm` | Corpus depends on e2e helpers |
| `e2e/common/recompile.py` | `corpus.policy_utils` | E2E depends on corpus policy utilities |
| `e2e/cases/tracee/case.py` | `micro.orchestrator.inventory`, `e2e.run_e2e_tracee` | E2E depends on micro internals and a legacy wrapper |
| `e2e/cases/tetragon/case.py` | `micro.orchestrator.inventory` | Same |
| `e2e/cases/katran/case.py` | `micro.orchestrator.inventory` | Same |
| `e2e/run_e2e_tracee.py` | `micro.orchestrator.commands`, `environment`, `inventory`, `results` | Legacy runner depends on micro internals |

In addition, many files use `sys.path.insert(...)` to cross directory boundaries dynamically instead of importing through a stable package boundary.

### 1.8 Dead code, stale code, and non-source artifacts

Confirmed or strongly evidenced issues:

- `legacy/` is inactive historical material.
- `corpus/tmp/cross_domain_census.py` is explicitly archived one-off material by `corpus/README.md`.
- `e2e/README.md` is stale:
  - it still talks about wrapper scripts that no longer exist as source files
  - it describes Katran as future work even though `e2e/run.py` already dispatches Katran
- `e2e/__pycache__/` still contains bytecode for removed wrappers such as `run_e2e_bpftrace.py` and `run_e2e_tetragon.py`.
- `corpus/__pycache__/` still contains bytecode for removed public wrappers.
- `refresh_latest_alias()` and `maybe_refresh_latest_alias()` are stub/no-op implementations in three different modules.
- Generated artifacts are committed or left in source-facing trees:
  - `micro/programs/*.o`, `micro/programs/*.d`, `micro/programs/*.bin`
  - `micro/generated-inputs/`
  - `micro/jit-dumps/`
  - `micro/build/`, `micro/build-arm64/`
  - `scanner/build/`, `scanner/build-arm64/`
  - `tests/kernel/build/`

Important nuance:

- `e2e/run_e2e_tracee.py` is legacy in style, but not dead today because `e2e/cases/tracee/case.py` imports symbols from it.
- `corpus/run_corpus_runnability.py` is not dead, but it is tightly coupled to private `_driver_impl_*` modules and should not survive the cleanup unchanged.

### 1.9 Build/test entrypoints and conventions

Current control plane:

- Root `Makefile` is already the public control surface for most flows.
- `CLAUDE.md` explicitly calls the root `Makefile` the canonical benchmark entrypoint, identifies `micro/orchestrator/` as shared Python reused by corpus and e2e, identifies `micro/runner/` as the current C++ execution binary, and points temporary docs/reports at `docs/tmp/`.

Current root `Makefile` target groups:

- build: `micro`, `scanner`, `kernel`, `kernel-tests`
- VM benchmark flows: `vm-selftest`, `vm-micro-smoke`, `vm-micro`, `vm-corpus`, `vm-e2e`, `vm-all`
- ARM64/AWS helpers: `arm64-qemu-smoke`, `aws-arm64-setup`, `aws-arm64-run`

Current coupling visible in the root `Makefile`:

- `vm-corpus` runs `python3 micro/driver.py corpus v5-vm-batch ...`, which makes `micro/driver.py` the corpus dispatcher
- `vm-e2e` directly runs `python3 e2e/run.py tracee|tetragon|bpftrace|scx|katran`

Current `micro/Makefile` responsibilities:

- build benchmark objects under `micro/programs`
- build `micro_exec` via CMake under `micro/runner`
- build `directive_hint`
- build vendored `libbpf` and `bpftool`
- clean generated inputs, JIT dumps, and build directories while leaving result outputs in place

Implication:

- the root `Makefile` is already the right public entrypoint
- the layering under that entrypoint is what needs restructuring

### 1.10 Current JSON/output problems

The current C++ runner emits one JSON object per invocation, not one line per measurement.

Problems visible in `micro/runner` today:

- same-image pair mode writes `exec_ns` for the recompile pass and `stock_exec_ns` as an extra side field instead of emitting two records
- policy generation, scanner summary, code size, and execution measurement are all mixed into one object
- phase-timing keys are partly dynamic (`prepare_phase_name(...)`, `result_phase_name(...)`) rather than fully canonical
- the object duplicates `bitfield_sites` and `extract_sites`
- downstream Python code then wraps these runner objects in several incompatible higher-level JSON formats

## 2. Ideal Architecture

### 2.1 Design goals

- `runner/` is the only shared foundation for benchmark code.
- `micro/`, `corpus/`, and `e2e/` import `runner.libs.*` but never import one another.
- `scanner/` stays independent and is used through a stable CLI/library contract.
- `micro_exec` only measures and applies a precompiled blob; it does not own policy parsing or scanner logic.
- Root `Makefile` is the only supported user entrypoint.

### 2.2 Target directory layout

```text
.
├── Makefile
├── CLAUDE.md
├── config/
│   ├── micro/
│   │   ├── pure_jit.yaml
│   │   └── rigorous_smoke.yaml
│   ├── corpus/
│   │   ├── packet_test_run.yaml
│   │   ├── macro.yaml
│   │   └── production.yaml
│   └── e2e/
│       ├── tracee.yaml
│       ├── tetragon.yaml
│       ├── bpftrace.yaml
│       ├── scx.yaml
│       └── katran.yaml
├── runner/
│   ├── CMakeLists.txt
│   ├── include/
│   │   └── runner/
│   │       └── micro_exec.hpp
│   ├── src/
│   │   ├── main.cpp
│   │   ├── cli.cpp
│   │   ├── jsonl.cpp
│   │   ├── elf_program_loader.cpp
│   │   ├── kernel_runner.cpp
│   │   ├── llvmbpf_runner.cpp
│   │   ├── perf_counters.cpp
│   │   └── policy_blob.cpp
│   └── libs/
│       ├── __init__.py
│       ├── process.py
│       ├── paths.py
│       ├── commands.py
│       ├── results.py
│       ├── statistics.py
│       ├── catalog.py
│       ├── inventory.py
│       ├── payloads.py
│       ├── policy.py
│       ├── scanner.py
│       ├── live_bpf.py
│       ├── vm.py
│       ├── environment.py
│       └── reporting.py
├── micro/
│   ├── README.md
│   ├── driver.py
│   ├── input_generators.py
│   ├── programs/
│   │   ├── src/*.bpf.c
│   │   ├── include/common.h
│   │   └── generated/        # gitignored
│   ├── policies/
│   │   ├── default/
│   │   ├── ablation/
│   │   └── variants/
│   └── results/
├── corpus/
│   ├── README.md
│   ├── driver.py
│   ├── inventory.json
│   ├── repos.yaml
│   ├── inputs/
│   ├── policies/
│   ├── repos/
│   ├── bcf/
│   ├── results/
│   └── tests/
├── e2e/
│   ├── README.md
│   ├── run.py
│   ├── common/
│   │   ├── agent.py
│   │   └── workload.py
│   ├── cases/
│   │   ├── bpftrace/case.py
│   │   ├── katran/case.py
│   │   ├── scx/case.py
│   │   ├── tetragon/case.py
│   │   └── tracee/case.py
│   └── results/
├── scanner/
│   ├── CMakeLists.txt
│   ├── README.md
│   ├── include/...
│   ├── src/...
│   └── tests/...
├── scripts/
│   ├── arm64_qemu_smoke.py
│   └── aws_arm64.sh
└── tests/
    ├── kernel/
    ├── python/
    │   ├── test_runner_results.py
    │   ├── test_catalog.py
    │   ├── test_policy.py
    │   └── test_inventory.py
    └── integration/
        └── test_make_entrypoints.py
```

### 2.3 Responsibilities and boundaries

#### `runner/libs/` module list and API surface

| Module | API surface | Responsibility |
| --- | --- | --- |
| `process.py` | `run_command()`, `run_text_command()`, `run_json_command()` | One subprocess layer for all benchmark code |
| `paths.py` | `ensure_parent()`, `result_date_stamp()`, `authoritative_output_path()`, `smoke_output_path()`, `latest_output_path()` | Shared output/path naming and directory creation |
| `commands.py` | `build_runner_command()`, `build_list_programs_command()`, `build_scanner_command()`, `wrap_with_sudo()`, `wrap_with_taskset()` | Canonical CLI construction |
| `results.py` | `parse_json_lines()`, `parse_measurement_line()`, `normalize_measurement()`, `summarize_phase_timings()` | Schema handling and normalization |
| `statistics.py` | `ns_summary()`, `geomean()`, `bootstrap_ci()`, `wilcoxon_signed_rank()`, `benjamini_hochberg_adjust()` | Shared math/statistics |
| `catalog.py` | `load_manifest()`, `load_micro_manifest()`, `load_corpus_manifest()`, `resolve_runtime()` | All benchmark manifest loading |
| `inventory.py` | `parse_program_inventory()`, `discover_object_programs()`, `discover_corpus_objects()`, `load_packet_test_run_targets()` | Object/program discovery |
| `payloads.py` | `materialize_dummy_packet()`, `materialize_dummy_context()`, `execution_plan()`, `normalize_section_root()` | Shared packet/context preparation |
| `policy.py` | `resolve_policy_path()`, `parse_policy_v3()`, `render_policy_v3_text()`, `remap_policy_v3_to_live()`, `canonical_policy_family_name()` | Policy pathing and YAML semantics |
| `scanner.py` | `scan_xlated()`, `compile_policy()`, `enumerate_live()`, `apply_live()` | Stable wrapper over `bpf-jit-scanner` CLI |
| `live_bpf.py` | `BpfProgInfo`, `Libbpf`, `enable_bpf_stats()`, `sample_bpf_stats()`, `find_live_programs()` | Shared live-program metrics/helpers for corpus and e2e |
| `vm.py` | `write_guest_script()`, `run_in_vm()`, `collect_guest_info()` | Shared VM execution path |
| `environment.py` | `read_required_text()`, `read_optional_text()`, `sudo_available()`, `ensure_build_steps()` | Environment/build helpers |
| `reporting.py` | `markdown_table()`, `format_ns()`, `format_ratio()`, `build_summary()` | Shared human-readable reporting |

Rule: if logic is used by more than one top-level benchmark area, it belongs here.

#### `runner/src/` C++ components

| File | Responsibility |
| --- | --- |
| `main.cpp` | CLI entrypoint and subcommand dispatch |
| `cli.cpp` | Parse options and validate combinations |
| `jsonl.cpp` | Emit one canonical JSON line per measurement |
| `elf_program_loader.cpp` | Load ELF objects and enumerate programs |
| `kernel_runner.cpp` | Kernel execution path and same-image paired measurement |
| `llvmbpf_runner.cpp` | Userspace llvmbpf execution path |
| `perf_counters.cpp` | Perf-event capture |
| `policy_blob.cpp` | Read/apply precompiled policy blobs only |

Critical boundary: `runner/src/` does not parse YAML policy and does not embed scanner logic. It consumes a compiled blob or does no recompile at all.

### 2.4 Dependency graph

```text
Makefile
  -> runner/ (build micro_exec)
  -> scanner/ (build bpf-jit-scanner)
  -> micro/driver.py
  -> corpus/driver.py
  -> e2e/run.py
  -> tests/kernel

micro/driver.py
  -> runner.libs.{catalog,commands,results,statistics,reporting,paths,payloads}
  -> micro-local code/data only

corpus/driver.py
  -> runner.libs.{catalog,inventory,policy,scanner,commands,results,reporting,vm,live_bpf,paths,payloads}
  -> corpus-local data only

e2e/run.py and e2e/cases/*
  -> runner.libs.{policy,scanner,results,vm,live_bpf,paths}
  -> e2e.common.{agent,workload}
  -> case-local assets only

scanner/
  -> no imports from micro/corpus/e2e/runner.libs

runner.libs/*
  -> no imports from micro/, corpus/, or e2e/
```

There are no peer imports between `micro`, `corpus`, and `e2e`.

### 2.5 What stays where

#### `micro/`

Keep in `micro/`:

- benchmark sources under `programs/src/`
- benchmark-only input generation in `input_generators.py`
- micro-only policy files under `policies/`
- micro result outputs
- one public `driver.py`

Move out of `micro/` into `runner/`:

- `runner/`
- `orchestrator/`
- `benchmark_catalog.py`
- `results_layout.py`

#### `corpus/`

Keep in `corpus/`:

- corpus data: `repos/`, `bcf/`, `inventory.json`
- corpus policy files
- corpus inputs
- one public `driver.py`

Move out of `corpus/` into `runner/`:

- `common.py`
- `policy_utils.py`
- all shared subprocess/report/path helpers

Replace with:

- one `corpus/driver.py` with a `mode` parameter
- optional internal helper functions, but no user-facing `_driver_impl_*` files

#### `e2e/`

Keep in `e2e/`:

- case definitions and case-local assets
- agent lifecycle helpers
- workload generators
- one public `run.py`

Move out of `e2e/` into `runner/`:

- generic output/path helpers from `e2e/common/__init__.py`
- generic VM helpers from `e2e/common/vm.py`
- generic live-program recompile helpers from `e2e/common/recompile.py`
- generic live BPF metrics helpers from `e2e/common/metrics.py`

#### `scanner/`

Keep scanner independent.

Expose only:

- CLI contract: `scan`, `enumerate`, `apply`, `generate-policy`, `compile-policy`, `dump`
- optional C++ library for scanner unit tests or future direct consumers

Do not let scanner import or depend on benchmark orchestration code.

#### `scripts/`

Belongs here:

- machine/bootstrap helpers
- AWS helpers
- CI wrappers
- local smoke/provisioning scripts

Does not belong here:

- benchmark orchestration logic
- report generation required by benchmark runs
- shared runtime/policy helpers

#### `tests/`

- `tests/kernel/`: kernel selftests and BPF programs
- `scanner/tests/`: scanner-specific C++ unit tests and golden policies
- `tests/python/`: Python unit tests for `runner.libs.*`
- `tests/integration/`: end-to-end tests for `make` entrypoints and schema compatibility

#### `config/`

`config/` should hold run manifests only:

- micro suite manifests
- corpus selection/manifests
- e2e case manifests and defaults

Policy YAMLs stay next to the benchmark domain they describe. They are inputs, not top-level manifests.

## 3. Data Flow

### 3.1 YAML config to report

1. `make` chooses a public entrypoint: `micro/driver.py`, `corpus/driver.py`, or `e2e/run.py`.
2. The driver loads a manifest from `config/` through `runner.libs.catalog`.
3. The driver resolves object/program targets through `runner.libs.inventory`.
4. The driver resolves policy YAML through `runner.libs.policy`.
5. If a recompile phase is needed, the driver asks `runner.libs.scanner.compile_policy()` to produce a blob.
6. The driver invokes `runner/micro_exec` through `runner.libs.commands`.
7. `micro_exec` emits one JSON line per measurement.
8. `runner.libs.results` collects JSONL, normalizes schema, and groups lines into runs/pairs.
9. `runner.libs.reporting` produces aggregate JSON and Markdown reports.

### 3.2 Same-image measurement flow

For one object/program/policy combination:

1. Driver invokes `micro_exec --same-image --policy-blob <blob> ...`.
2. `micro_exec` loads the program image once.
3. It measures the stock phase and emits line 1 with `phase=stock`.
4. It applies the precompiled blob.
5. It measures the recompile phase and emits line 2 with `phase=recompile`.
6. Both lines share the same `pair_id`.

Important consequences:

- no `stock_exec_ns` field
- no mixed stock/recompile metrics in one object
- downstream pairing is done by `pair_id`, not by ad hoc field inspection

### 3.3 Policy resolution flow

This should match the section 4.4 safety model.

1. Manifest selects an object and program name.
2. `runner.libs.policy.resolve_policy_path()` finds the YAML policy file.
3. `runner.libs.scanner.compile_policy()` validates the YAML against the live or translated program and produces a policy blob.
4. Driver invokes `micro_exec` with `--policy-blob`.
5. `micro_exec` passes the blob to the kernel recompile/apply path.
6. Kernel either applies or rejects the blob; the measurement line records that outcome.

Scanner owns validation and blob construction. Runner owns timing and measurement. Kernel owns enforcement.

## 4. JSON Output Schema

### 4.1 Record format

`micro_exec` writes JSONL, one line per measurement:

```json
{
  "schema_version": 2,
  "record_type": "measurement",
  "phase": "stock",
  "pair_id": "20260320T120000Z-rotate64_hash-0007",
  "suite": "micro",
  "mode": "suite",
  "benchmark": "rotate64_hash",
  "backend": "kernel",
  "transport": "local",
  "object_path": "micro/programs/generated/rotate64_hash.bpf.o",
  "program_name": "rotate64_hash_xdp",
  "section_name": "xdp",
  "io_mode": "xdp",
  "repeat": 1000,
  "prepare_ns": 5602039,
  "exec_ns": 119,
  "wall_exec_ns": 1007245,
  "exec_cycles": 3712970,
  "timing_source": "ktime",
  "timing_source_wall": "rdtsc",
  "result": 2666935177028490406,
  "retval": 2,
  "jited_prog_len": 2381,
  "xlated_prog_len": 7984,
  "native_code_size": 2381,
  "bpf_insn_count": 998,
  "policy_blob_bytes": 0,
  "policy_applied": false,
  "phases_ns": {
    "load_image_ns": 4031201,
    "prepare_input_ns": 1215,
    "run_wall_ns": 20145086,
    "extract_result_ns": 72
  },
  "perf_counters": {},
  "perf_counters_meta": {
    "requested": false,
    "collected": false,
    "include_kernel": true,
    "scope": "full_repeat_raw",
    "error": ""
  },
  "status": "ok",
  "error": null
}
```

### 4.2 `phase` semantics

- `phase=stock`: baseline execution before any policy blob is applied
- `phase=recompile`: execution after a policy blob is applied

Rules:

- stock and recompile are separate measurement records
- `pair_id` is required when two records are logically paired
- `pair_id` is omitted for standalone one-phase runs

### 4.3 Required vs optional fields

Required:

- `schema_version`
- `record_type`
- `phase`
- `suite`
- `mode`
- `benchmark`
- `backend`
- `transport`
- `object_path`
- `program_name`
- `section_name`
- `repeat`
- `prepare_ns`
- `exec_ns`
- `timing_source`
- `result`
- `retval`
- `status`

Optional:

- `pair_id`
- `io_mode`
- `wall_exec_ns`
- `exec_cycles`
- `timing_source_wall`
- `jited_prog_len`
- `xlated_prog_len`
- `native_code_size`
- `bpf_insn_count`
- `policy_blob_bytes`
- `policy_applied`
- `phases_ns`
- `perf_counters`
- `perf_counters_meta`
- `error`

Notably absent from v2:

- `stock_exec_ns`
- inline policy YAML
- scanner summary fields
- mixed stock and recompile data in one record

Those belong either in separate lines or in run-level metadata produced by the Python drivers.

### 4.4 Backward compatibility plan

`runner.libs.results` should support both current and target schema during migration.

Adapter rules:

1. If a record already has `schema_version=2` and `phase`, parse it directly.
2. If a legacy record has no `stock_exec_ns`, convert it to one synthetic v2 line with `phase=stock`.
3. If a legacy record has `stock_exec_ns`, convert it to two synthetic v2 lines:
   - stock line: `phase=stock`, `exec_ns=stock_exec_ns`
   - recompile line: `phase=recompile`, `exec_ns=<legacy exec_ns>`
4. Preserve the legacy payload in aggregate JSON during the transition if debugging is needed, but do not propagate legacy fields into new reports.

Recommended rollout:

- readers accept both schemas first
- `micro_exec` gains v2 JSONL output next
- writers stop depending on legacy fields last

## 5. Migration Plan

### 5.1 Ordered steps

| Step | Change | Incremental or atomic | Main risk | Mitigation |
| --- | --- | --- | --- | --- |
| 1 | Add tests around current manifest loading, policy parsing/remap, inventory parsing, and runner JSON parsing | Incremental | Locking in the wrong current behavior | Test only the behavior actually used by Makefile paths |
| 2 | Create top-level `runner/` by moving `micro/runner` with no behavior change yet | Incremental | Build-path breakage | Keep root `Makefile` building the old path and new path in parallel temporarily |
| 3 | Move `micro/orchestrator/*` into `runner/libs/*`; leave thin compatibility wrappers in old import locations | Incremental | Import churn across many files | Keep compatibility modules until all callers are switched |
| 4 | Move shared path/output helpers into `runner.libs.paths` and delete duplicate `results_layout` behavior behind wrappers | Incremental | Output filename drift | Freeze filename format in tests before swapping implementations |
| 5 | Move `corpus/policy_utils.py` into `runner.libs.policy` and update e2e/corpus callers | Incremental | Policy-path regression | Add direct unit tests for `resolve_policy_path`, `parse_policy_v3`, and `remap_policy_v3_to_live` |
| 6 | Move VM helpers and live BPF helpers into `runner.libs.vm` and `runner.libs.live_bpf` | Incremental | VM guest-script breakage | Keep old modules as pass-through wrappers until both corpus and e2e are migrated |
| 7 | Introduce one public `corpus/driver.py` with `mode` dispatch; convert `_driver_impl_*` files into internal helpers or remove them | Incremental | CLI churn | Preserve old mode names and wire root `Makefile` to the new driver first |
| 8 | Stop having `micro/driver.py` dispatch corpus; give corpus and e2e their own public entrypoints only | Incremental | Broken automation/scripts | Update root `Makefile` and README examples in the same change |
| 9 | Decouple scanner from C++ runner policy parsing: compile policy blobs in Python through `runner.libs.scanner`, pass blobs into `micro_exec` | Incremental | Policy-compile/apply mismatch | Dual-run old and new paths on a corpus subset and compare blob/application outcomes |
| 10 | Add v2 JSONL output and dual-read support | Incremental if dual-read, atomic if not | Report/parser breakage | Ship reader compatibility before writer switch |
| 11 | Switch root `Makefile` to the new entrypoints only; treat subdirectory scripts/Makefiles as internal | Incremental | User workflow breakage | Keep target names stable even if implementations move |
| 12 | Remove stale wrappers, stale docs, committed build outputs, and no-op compatibility shims | Mostly atomic at the end | Deleting still-live compatibility code | Do this only after grep and Makefile paths show no live references |

### 5.2 What can be incremental

Incremental:

- creating `runner/`
- moving Python shared helpers into `runner.libs`
- moving policy/vm/live-BPF helpers into shared modules
- introducing `corpus/driver.py`
- introducing the v2 schema with dual-read support

Potentially atomic if done carelessly:

- changing `micro_exec` output format without dual-read compatibility
- removing old import paths before all drivers are switched
- deleting `_driver_impl_*` files before the root `Makefile` stops referencing them

### 5.3 Highest-risk cutovers

1. Scanner/runner separation.
   Risk: policy blob contents or apply ordering changes, invalidating historical comparisons.
   Mitigation: compare old and new blob application on a fixed micro subset plus a corpus subset.

2. JSON schema migration.
   Risk: silently wrong paired measurements if `stock_exec_ns` is not translated correctly.
   Mitigation: one parser owns the translation and is tested against archived current samples.

3. Corpus driver consolidation.
   Risk: mode-specific behavior hidden in private modules gets lost.
   Mitigation: migrate one mode at a time behind one public `corpus/driver.py`.

4. VM helper consolidation.
   Risk: `micro`, `corpus`, and `e2e` each have slightly different guest assumptions today.
   Mitigation: first unify script-writing and subprocess transport, then unify semantics.

## 6. Bottom Line

The repo already contains the seeds of the desired architecture:

- `micro/orchestrator/` is the shared Python layer in disguise
- `scanner/` is already an independent subsystem
- the root `Makefile` is already close to the public control plane

The main problems are placement and boundaries:

- the shared layer lives under `micro/`
- corpus has eight overlapping drivers instead of one modeful driver
- e2e and corpus both reach sideways into each other and upward into micro
- `micro_exec` mixes measurement with policy/scanner concerns and emits a mixed single-object schema

The target state is straightforward:

- move shared code to `runner/`
- keep scanner independent
- make corpus one driver with modes
- make the root `Makefile` the only public entrypoint
- emit one JSON line per measurement with explicit `phase=stock|recompile`
