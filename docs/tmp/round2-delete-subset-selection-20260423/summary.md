# Round 2 Delete Subset Selection (2026-04-23)

## 候删清单

- corpus filter 链
  - `corpus/driver.py --filter`
  - `runner/libs/app_suite_schema.py:_matches_filter()`
  - `runner/libs/run_contract.py:_apply_corpus_filter_selection()`
  - `runner/suites/corpus.py --corpus-filter/--filter/--corpus-filters`
  - `runner/libs/suite_args.py` 的 `AWS_*_CORPUS_FILTERS` / `FILTERS`
  - root `Makefile` 的 `FILTERS` / `--corpus-filters` forwarding
- e2e suite-level filter 链
  - `e2e/driver.py` 的 `_write_suite_temp_yaml()` / `_filter_suite_workloads_config()` / `_configure_*_case_from_suite()` / `apply_suite_case_config()`
  - `e2e/driver.py --suite`
  - `runner/suites/e2e.py --e2e-cases/--e2e-case`
  - `runner/libs/suite_args.py` 的 `E2E_CASE(S)` 读取
  - `runner/libs/run_contract.py` 的 `_apply_e2e_case_selection()` / `_validate_e2e_cases()` / `_native_repos_for_e2e_cases()`
  - root `Makefile` 的 `E2E_CASE` / `--e2e-cases` / `AWS_*_E2E_CASES` forwarding
- tetragon static policy pack
  - `e2e/cases/tetragon/policies/10-kprobes.yaml`
  - `e2e/cases/tetragon/policies/20-tracepoints.yaml`
  - `runner/libs/app_runners/tetragon.py` 的 `DEFAULT_POLICY_DIR` / `_tetragon_policy_paths()` / `--tracing-policy-dir` 注入 / `tetragon_extra_args`
  - `e2e/cases/tetragon/case.py` 的 `policy_dir` / `policy_paths` artifacts plumbing
  - `e2e/cases/tetragon/case.py` 的 `tetragon_extra_args` config 读取
- 建议删收尾
  - `runner/libs/app_runners/tracee.py:wait_for_event(event_names=...)`
  - `runner/libs/app_runners/tracee.py:DEFAULT_CONFIG`

## 已删清单

- corpus
  - 删除 `corpus/driver.py` 的 `--filter` parser surface 和 `filters` metadata/plumbing。
  - 删除 `runner/libs/app_suite_schema.py:_matches_filter()`，`load_app_suite_from_yaml()` 改为始终返回 suite 全集。
  - 删除 `runner/libs/run_contract.py:_apply_corpus_filter_selection()`，corpus contract 不再按 filtered suite 重裁 `native_repos` / `scx_packages`。
  - 删除 `runner/suites/corpus.py` 的 `--corpus-filter` / `--filter` / `--corpus-filters`，wrapper 不再转发 filter。
  - 删除 `runner/libs/suite_args.py` 的 `AWS_*_CORPUS_FILTERS` / `FILTERS` 读取和对应 parser。
  - 删除 root `Makefile` 的 `FILTERS` / `--corpus-filters` surface。
- e2e
  - 删除 `e2e/driver.py` 的 suite temp-YAML/filter 整条链；`all` 现在固定跑 `tracee,tetragon,bpftrace,scx,bcc,katran`。
  - 删除 `e2e/driver.py --suite`。
  - 删除 `runner/suites/e2e.py` 的 `--e2e-cases` / `--e2e-case` / `--suite`，wrapper 统一调用 `e2e/driver.py all`。
  - 删除 `runner/libs/suite_args.py` 的 `E2E_CASE(S)` 读取和对应 parser。
  - 删除 `runner/libs/run_contract.py` 的 e2e case subset selection 逻辑，e2e contract 直接使用 suite 默认全集。
  - 删除 root `Makefile` 的 `E2E_CASE` / `--e2e-cases` / `AWS_*_E2E_CASES` forwarding。
- tetragon
  - `git rm`：
    - `e2e/cases/tetragon/policies/10-kprobes.yaml`
    - `e2e/cases/tetragon/policies/20-tracepoints.yaml`
  - 删除 `runner/libs/app_runners/tetragon.py` 的 `DEFAULT_POLICY_DIR` / `_tetragon_policy_paths()`。
  - 删除 `TetragonRunner` 的 `tetragon_extra_args` 形参和全部 extra-arg plumbing。
  - 删除 `TetragonRunner.start()` 中的 `--tracing-policy-dir` 强制注入；现在直接走 native default CLI。
  - 删除 `e2e/cases/tetragon/case.py` 的 `policy_dir` / `policy_paths` artifacts 和 `tetragon_extra_args` config 读取。
- tracee 收尾
  - 删除 `runner/libs/app_runners/tracee.py:wait_for_event(event_names=...)` 的 event-name filter 参数。
  - 删除 `runner/libs/app_runners/tracee.py:DEFAULT_CONFIG` 死常量。

## 未删原因

- 保留 `runner/libs/app_runners/tracee.py` 的 `--events "*"`。
  - 用户明确要求保留；这是当前 “load all programs” 的核心实现，不属于本轮待删 surface。
- 保留 `e2e/cases/tracee/config.yaml:11` 的 `latency_probe_timeout_s: 20`。
  - 用户明确要求保留；这是 all-events 路径的加载时间补偿，不是 subset selection 逻辑。
- 未修改 `vendor/linux-framework/`。
  - 用户和上层文档都禁止本轮改内核。

## 验证

- 局部 sanity
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile corpus/driver.py runner/libs/app_suite_schema.py runner/libs/run_contract.py runner/suites/corpus.py runner/libs/suite_args.py`
    - exit 0
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile e2e/driver.py runner/suites/e2e.py runner/libs/suite_args.py runner/libs/run_contract.py`
    - exit 0
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
    - exit 0
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py`
    - exit 0
- 全量校验
  - `source /home/yunwei37/workspace/.venv/bin/activate && make check`
    - exit 0
  - `make -n vm-corpus`
    - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm corpus -- --samples "30"`
  - `make -n vm-e2e`
    - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e --`

## git diff shortstat

- 全仓当前 worktree
  - `20 files changed, 264 insertions(+), 834 deletions(-)`
- 本轮 touched subset
  - `12 files changed, 128 insertions(+), 722 deletions(-)`

## 自我 review

- 本轮改动满足净删；不存在新增 flag / env var / 配置字段。
- `tetragon` 删除遵守冲突规避：先看了 `git diff --stat -- runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py` 和全文 diff，再在现有 diff 上继续删，没有回滚主 codex 之前的删除。
- 未运行任何 `make vm-*` 实测；只跑了 `py_compile`、`make check`、`make -n vm-corpus`、`make -n vm-e2e`。
- 手工自查：本轮真正新增的非空代码行控制在 10 行以内，新增仅是删除链路后不可避免的最小重接线；其余均为删代码或删参数。
