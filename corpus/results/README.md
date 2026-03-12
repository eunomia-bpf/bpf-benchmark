# Corpus Results

Canonical corpus JSON payloads use these names:

- `<suite>_authoritative_YYYYMMDD.json`: the checked-in authoritative snapshot for that suite.
- `<suite>_smoke_YYYYMMDD.json`: smoke, subset, or spotcheck output.
- `<suite>.latest.json`: symlink to the newest authoritative JSON for that suite.

Conventions:

- `YYYYMMDD` is the UTC calendar date from the payload's `generated_at` timestamp.
- Variant suites keep the qualifier in the suite name when needed, such as `real_world_exec_time_v1_smoke_20260307.json` or `tracing_exec_driver_kprobe_smoke_20260311.json`.
- Supporting files such as markdown reports, `bytecode_features.json`, `helper_pareto.json`, and `valid_packet.bin` are auxiliary artifacts and do not use the canonical run naming scheme.

Current authoritative aliases:

- `corpus_v5_vm_batch.latest.json` -> `corpus_v5_vm_batch_authoritative_20260311.json`
- `expanded_corpus_build.latest.json` -> `expanded_corpus_build_authoritative_20260310.json`
- `real_world_code_size.latest.json` -> `real_world_code_size_authoritative_20260307.json`
- `real_world_exec_time.latest.json` -> `real_world_exec_time_authoritative_20260307.json`
- `tracing_corpus_vm.latest.json` -> `tracing_corpus_vm_authoritative_20260311.json`
