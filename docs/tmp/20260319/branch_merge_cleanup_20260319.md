# Branch Merge Cleanup 2026-03-19

## Source Branch

- `arm64-ci-corpus-exec-fix-20260319-v2`
- compared with `main` via:
  - `git diff main...arm64-ci-corpus-exec-fix-20260319-v2 --name-only`

Files changed on the branch tip:

- `.github/workflows/arm64-benchmark.yml`
- `corpus/run_real_world_exec_time.py`
- `docs/tmp/arm64_ci_corpus_fix_20260319.md`

## Manual Merge Result

1. `.github/workflows/arm64-benchmark.yml`
   - kept `main`'s corpus `llvmbpf` removal
   - kept the corpus exec invocation on the kernel-only path
   - preserved `--context-size 256` for the exec-time run
   - left the workflow summary in the kernel-only/main format

2. `corpus/run_real_world_exec_time.py`
   - kept the per-program packet/context I/O mode logic already present on `main`
   - kept `main`'s runtime model (`kernel`, `kernel-recompile`)
   - did not reintroduce branch-side `llvmbpf` execution, retry, or reporting logic

3. `corpus/run_real_world_code_size.py`
   - branch diff against `main` did not include this file
   - restored the file to `main`'s kernel/kernel-recompile corpus state
   - did not keep the accidental local/staged `llvmbpf` reintroduction

4. `docs/tmp/arm64_ci_corpus_fix_20260319.md`
   - kept the branch report content

## Validation

- `python3 -m py_compile corpus/run_real_world_exec_time.py corpus/run_real_world_code_size.py`
- `ruby -e 'require "yaml"; YAML.load_file(".github/workflows/arm64-benchmark.yml"); puts "yaml ok"'`

## Branch Cleanup

- detached linked worktree `/tmp/bpf-benchmark-arm64-fix-20260320` from `arm64-ci-corpus-exec-fix-20260319-v2`
- deleted local branch `arm64-ci-corpus-exec-fix-20260319`
- deleted local branch `arm64-ci-corpus-exec-fix-20260319-v2`
