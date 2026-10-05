# Map Fixture Replay Report

Date: 2026-03-26

## Scope

Implemented map fixture replay so corpus jobs can preload captured map state into loaded kernel maps before runtime measurement.

## Changes

### Runner

- Added `fixture_path` to `cli_options` in [runner/include/micro_exec.hpp](/home/yunwei37/workspace/bpf-benchmark/runner/include/micro_exec.hpp).
- Added `--fixture-path <path>` CLI parsing and keep-alive JSON support in [runner/src/common.cpp](/home/yunwei37/workspace/bpf-benchmark/runner/src/common.cpp).
- Added batch-spec parsing for `fixture_path` in [runner/src/batch_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp).
- Implemented fixture replay in [runner/src/kernel_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/runner/src/kernel_runner.cpp):
  - parses JSON fixture files via YAML-cpp
  - resolves maps by `map_name` and falls back to `map_id`
  - decodes `key_hex` and `value_hex`
  - updates live kernel maps with `bpf_map_update_elem`
  - handles `PROG_ARRAY` and map-in-map values by translating captured IDs back to live FDs
  - logs `loaded N entries into M maps from fixture ...`
- Replay is invoked on runtime measurement paths, not compile-only paths, so compile timing stays unchanged while runtime jobs still start from the captured fixture state.

### Corpus

- Added `fixture_path` to the resolved object model and manifest parsing in [corpus/modes.py](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py).
- Threaded `fixture_path` into object-batch job generation in [corpus/modes.py](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py).
- Added a short schema comment for the optional field in [corpus/config/macro_corpus.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml).

## Verification

- `make runner`
- `python3 -m py_compile corpus/modes.py`

Both commands completed successfully.

## Notes

- I did not run VM or kernel-runtime corpus measurements in this change.
- Fixture replay currently activates only when a job supplies `fixture_path`.
