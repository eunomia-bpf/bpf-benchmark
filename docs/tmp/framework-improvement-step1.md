# Framework Improvement Step 1

Date: 2026-03-11

## Scope completed

This step implemented the first shared orchestration extraction described in `docs/tmp/benchmark-framework-analysis.md` P1 follow-up:

- added `micro/orchestrator/` with:
  - `commands.py`: shared `micro_exec` command builders, including `list-programs` and micro benchmark runtime commands
  - `results.py`: shared JSON parsing, runner-sample normalization, summary helpers, and a unified `UnifiedResultRecord` schema dataclass
  - `environment.py`: shared environment validation, sudo probing, build-step execution, and path/text helpers
  - `inventory.py`: shared program inventory helpers for micro targets and corpus object discovery
  - `__init__.py`: package exports
- migrated `micro/run_micro.py` to use the shared command, results, and environment helpers instead of maintaining its own copies
- fixed stale metadata:
  - `micro/README.md` benchmark counts now reflect the current manifests: `55` pure-JIT, `11` runtime, `66` on-disk benchmark objects
  - `micro/directive_census.py` no longer warns against a hardcoded `62`; it now derives the expected micro object count from `micro/programs/*.bpf.c`

## Unified result schema

`micro/orchestrator/results.py` now defines `UnifiedResultRecord`, a core schema intended to span:

- micro suite runs
- corpus recompile runs
- rigorous benchmark runs

The core fields are:

- `suite`
- `target`
- `backend`
- `policy_mode`
- `transport`
- optional `manifest`, `host`, `inventory`, `artifacts`
- optional `compile`, `execution`, `directive_scan`, `recompile`, `perf_counters`
- `samples`
- optional `statistics`, `correctness`, `metadata`

This keeps the shared schema aligned with the core structure proposed in the P1 analysis while staying compatible with the current per-driver JSON outputs.

## Verification

Executed successfully:

- `python3 -m py_compile micro/orchestrator/__init__.py micro/orchestrator/commands.py micro/orchestrator/environment.py micro/orchestrator/inventory.py micro/orchestrator/results.py micro/run_micro.py micro/directive_census.py`
- `python3 -c "from micro.orchestrator import commands, results, environment, inventory; print('OK')"`
- `python3 micro/run_micro.py --list`
- `python3 micro/directive_census.py --help`
- `python3 micro/run_corpus_perf.py --help`
- `make -C micro micro_exec programs`
- `python3 micro/run_micro.py --bench simple --runtime llvmbpf --iterations 1 --warmups 0 --repeat 1 --output /tmp/run_micro_smoke.json`

Observed result:

- the import smoke test printed `OK`
- the `run_micro.py` smoke run completed and wrote `/tmp/run_micro_smoke.json`

## Next step

The next low-risk migration is to switch corpus and rigorous drivers onto `micro/orchestrator.results` and `micro/orchestrator.inventory`, then converge their outer JSON documents onto `UnifiedResultRecord`.
