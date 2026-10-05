# Strict Review Fixes 2026-03-29

- Deleted legacy remote benchmark loaders: `runner/scripts/x86_remote_benchmark.py`, `runner/scripts/arm64_t4g_remote_benchmark.py`.
- Deleted dead object-layer helpers: `runner/libs/commands.py`, `runner/libs/object_discovery.py`.
- Removed silent fallback/degradation paths in `runner/libs/agent.py`, `runner/libs/app_runners/tracee_support.py`, `runner/libs/app_runners/tetragon_support.py`, `runner/libs/app_runners/scx_support.py`, `runner/libs/case_common.py`, `runner/libs/bpf_stats.py`, `runner/libs/workload.py`, `runner/libs/run_artifacts.py`, `runner/src/kernel_runner.cpp`.
- Fixed `corpus/orchestrator.py` so `repeat` performs repeated baseline/REJIT measurements instead of only echoing configuration.
- Fixed `runner/libs/rejit.py` and `runner/libs/daemon_session.py` to preserve loader-instance `prog_fds` identity instead of discarding it.
- Removed dead result summarizer `summarize_corpus_batch_results()` from `runner/libs/results.py`.
- Removed stale `--runner` coupling from `e2e/run.py`, `e2e/cases/bpftrace/case.py`, `e2e/cases/tetragon/case.py`, and `e2e/cases/tracee/case.py`.
- Removed remaining shared-framework object-centric catalog code by moving the micro-only manifest loader from `runner/libs/catalog.py` to `micro/catalog.py`.
- Retired AWS remote benchmark entrypoints in `runner/scripts/aws_x86.sh` and `runner/scripts/aws_arm64.sh` so they no longer reference deleted legacy runners.

Verification:

- Result: `69 passed`
