# Native Loader Boundary Cleanup Todo (2026-05-28)

Scope:
- Keep the shim/runner boundary stable: frontends capture program/load context and call `libnativeloader`; `native-link` owns machine-code rewriting.
- Split oversized `libnativeloader` internals into focused headers when that removes coupling.
- Keep corpus and micro native loads correct after each cleanup step.
- Reduce `/proc/kallsyms` dependency only when the replacement source is complete and deterministic.

Todo:
- [x] Split manifest/source matching/map-rule parsing out of `native_loader.cpp` into `native_loader_manifest.hpp`.
- [x] Validate the split with `make micro` and full native-shim `make corpus`.
- [x] Remove the broken source/JIT helper-call oracle experiment.
- [x] Re-run `make micro BENCH=simple` after removing the oracle path.
- [x] Re-run `make corpus` for `bcc/set` after removing the oracle path.
- [x] Scan for dead fields/APIs left by the cleanup.
- [x] Run full `make micro`.
- [x] Run full native-shim `make corpus`.

Current finding:

The source/JIT oracle cannot be the authoritative target source as currently
implemented. Corpus programs routinely load source bytecode that contains
helper/map callsites which the verifier removes or rewrites using rodata,
map facts, and reachability. The native C object still contains static
calls for those source-level paths, so every native callsite still needs a
valid target even when the original verified JIT has no corresponding call.
Using source call order to consume original JIT calls therefore fails for
real corpus apps such as `bcc/set`.

Safe follow-up design:

Reducing kallsyms should be done through a complete source of kernel-owned
facts, not by best-effort source/JIT sequence matching. Two viable paths are:
- Native-side DCE/constant propagation that proves the same callsites dead
  before linking, so missing original-JIT targets are not needed.
- A kernel-owned map-op query interface in the native_lab module for map
  operation pointers that are not available through public helper symbols.

Until one of those exists, the loader must pass explicit helper/map target
schema and fail fast when a required symbol or map fact is missing.

Validation log:
- `cargo check --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml`
  passed after deleting `--oracle-*`.
- `TIMEOUT=3600 make micro BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`
  passed; artifact:
  `micro/results/x86_kvm_micro_20260528_002945_429953/metadata.json`.
- `BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit
  BPFREJIT_CORPUS_APPS="bcc/set" SAMPLES=1 WORKLOAD_DURATION=10
  TIMEOUT=3600 make corpus` passed; artifact:
  `corpus/results/x86_kvm_corpus_20260528_003434_860470/metadata.json`.
- Dead-code scan found no remaining `oracle_*`, `helper_args`,
  `use_helper_oracle`, `target_from_oracle`, `load_jited_program`,
  `load_jited_ksyms`, `MapSiteOracleTargets`, `OracleCall`, or
  `OracleMapSite` references under `native-sim/libnativeloader/src` and
  `native-sim/x86/native_lab/native_link/src`.
- Current cleanup diff for the touched native-loader/native-link files is
  67 insertions and 584 deletions.
- `TIMEOUT=7200 make micro` passed 29/29; artifact:
  `micro/results/x86_kvm_micro_20260528_004112_345515/metadata.json`.
  A result/retval mismatch scan returned an empty mismatch list.
- `BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit
  TIMEOUT=7200 make corpus` passed all six supported corpus apps with
  `SAMPLES=3` and the default 30 second workload duration; artifact:
  `corpus/results/x86_kvm_corpus_20260528_004858_428315/metadata.json`.
  Per-app status files under `details/apps/` report `ok` for `bcc/set`,
  `otelcol-ebpf-profiler/profiling`, `cilium/agent`, `tetragon/observer`,
  `katran`, and `tracee/monitor`.
- `git diff --check` on the touched native-loader/native-link/doc files
  passed.
