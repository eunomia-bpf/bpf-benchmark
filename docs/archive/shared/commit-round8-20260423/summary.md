# Round 8 Commit Report (2026-04-23)

说明：我把用户建议的 Commit 2 和 Commit 3 合并了，所以 Round 8 的**实体改动**是 4 个 commit；本文件作为第 5 个 **meta-doc** commit 单独提交，因此下面的 commit 清单覆盖前 4 个实体 commit。

## Commit 清单

- `bbbf28e6` `[runner] delete all program filter/select surfaces, load all native programs`
  - files:
    - `e2e/cases/bcc/case.py`
    - `e2e/cases/bpftrace/case.py`
    - `e2e/cases/scx/case.py`
    - `e2e/cases/tetragon/case.py`
    - `e2e/cases/tetragon/config_execve_rate.yaml`
    - `e2e/cases/tracee/case.py`
    - `e2e/cases/tracee/config.yaml`
    - `runner/libs/app_runners/scx.py`
    - `runner/libs/app_runners/tetragon.py`
    - `runner/libs/app_runners/tracee.py`
- `569f0784` `[runner] delete suite-level subset selection and always run both phases`
  - files:
    - `Makefile`
    - `corpus/driver.py`
    - `e2e/cases/katran/case.py`
    - `e2e/driver.py`
    - `runner/libs/app_runners/process_support.py`
    - `runner/libs/app_suite_schema.py`
    - `runner/libs/case_common.py`
    - `runner/libs/run_contract.py`
    - `runner/libs/suite_args.py`
    - `runner/mk/build.mk`
    - `runner/suites/corpus.py`
    - `runner/suites/e2e.env`
    - `runner/suites/e2e.py`
- `8c714332` `[docs] round 8 investigation and cleanup summaries`
  - files:
    - `docs/tmp/delete-cli-args-20260423/summary.md`
    - `docs/tmp/delete-filters-all-programs-20260423/summary.md`
    - `docs/tmp/delete-post-gate-20260423/summary.md`
    - `docs/tmp/final-review-20260423/summary.md`
    - `docs/tmp/fix-corpus-lifecycle-20260423/summary.md`
    - `docs/tmp/program-coverage-gaps-20260423/summary.md`
    - `docs/tmp/rename-vs-delete-audit-20260423/summary.md`
    - `docs/tmp/review-delete-filters-20260423/summary.md`
    - `docs/tmp/round2-delete-subset-selection-20260423/summary.md`
    - `docs/tmp/tetragon-revert-20260423/summary.md`
- `4e46191c` `[docs] add round 8 plan entry`
  - files:
    - `docs/kernel-jit-optimization-plan.md`

## 决策

- 选择把建议里的 Commit 2 和 Commit 3 合并。
- 理由：`corpus/driver.py` 的 subset 删除、live `prog_ids` refresh、post-gate 删除和结果构建调整交错在同一批生命周期代码里；如果硬拆就需要 `git add -p` 对同文件做交互式分片。当前环境下我刻意避免交互式 staging，直接合并成一个语义完整的“suite 过滤链删除 + 两阶段强制化 + corpus lifecycle 修复”提交，风险更低，边界也仍然清楚。

## `git log --oneline -10`

以下输出是在 plan doc commit（`4e46191c`）之后抓取的：

```text
4e46191c [docs] add round 8 plan entry
8c714332 [docs] round 8 investigation and cleanup summaries
569f0784 [runner] delete suite-level subset selection and always run both phases
bbbf28e6 [runner] delete all program filter/select surfaces, load all native programs
c87babd3 ninini
51e799bc [docs] add round 7 plan entry
1f41e533 [docs] add round 7 working summaries
910bd0c3 [runner/e2e] relax tracee and bpftrace timeouts
f88a3d49 [runner] fail loud on unstable apply state
47f3295c [runner] add six production workload variants
```

## `git diff --stat HEAD~4..HEAD`

基线是 `c87babd3`，范围覆盖 4 个实体 commit：

```text
Makefile                                           |  24 +-
corpus/driver.py                                   |  58 ++---
docs/kernel-jit-optimization-plan.md               |   1 +
docs/tmp/delete-cli-args-20260423/summary.md       |  64 ++++++
docs/tmp/delete-filters-all-programs-20260423/summary.md | 125 +++++++++++
docs/tmp/delete-post-gate-20260423/summary.md      | 182 +++++++++++++++
docs/tmp/final-review-20260423/summary.md          |  94 ++++++++
docs/tmp/fix-corpus-lifecycle-20260423/summary.md  |  67 ++++++
docs/tmp/program-coverage-gaps-20260423/summary.md |  99 +++++++++
docs/tmp/rename-vs-delete-audit-20260423/summary.md | 181 +++++++++++++++
docs/tmp/review-delete-filters-20260423/summary.md |  75 +++++++
docs/tmp/round2-delete-subset-selection-20260423/summary.md |  97 ++++++++
docs/tmp/tetragon-revert-20260423/summary.md       |  62 ++++++
e2e/cases/bcc/case.py                              |  22 +-
e2e/cases/bpftrace/case.py                         |  21 +-
e2e/cases/katran/case.py                           |   5 +-
e2e/cases/scx/case.py                              |  50 +----
e2e/cases/tetragon/case.py                         |  62 +-----
e2e/cases/tetragon/config_execve_rate.yaml         |   7 -
e2e/cases/tracee/case.py                           | 128 +++--------
e2e/cases/tracee/config.yaml                       |  19 +-
e2e/driver.py                                      | 244 +--------------------
runner/libs/app_runners/process_support.py         |  41 ++--
runner/libs/app_runners/scx.py                     |  23 +-
runner/libs/app_runners/tetragon.py                | 163 ++------------
runner/libs/app_runners/tracee.py                  |  29 +--
runner/libs/app_suite_schema.py                    |  27 +--
runner/libs/case_common.py                         |  53 +----
runner/libs/run_contract.py                        |  79 +------
runner/libs/suite_args.py                          |  18 +-
runner/mk/build.mk                                 |   2 -
runner/suites/corpus.py                            |  19 --
runner/suites/e2e.env                              |   1 -
runner/suites/e2e.py                               |  40 +---
34 files changed, 1188 insertions(+), 994 deletions(-)
```

## 自我 Review

- commits 语义独立性：
  - `bbbf28e6` 只收 app-level all-program 语义和对应 case/config 删除。
  - `569f0784` 只收 shared suite/corpus/filter/gate/lifecycle。
  - `8c714332` 只收 Round 8 中间 summary。
  - `4e46191c` 只收 plan doc 条目。
- message 准确性：
  - `bbbf28e6` 准确描述了 Tracee/Tetragon/BCC/bpftrace/SCX 的 all-program 语义变化。
  - `569f0784` 明确写了“subset selection 删除 + 两阶段必跑”，与实际改动一致。
  - 两个 docs commit 都只覆盖文档。
- 无关 hunk：
  - 没有把 `e2e/results/` 或 `corpus/results/` 产物混入任何 commit。
  - 旧 `e2e/results/` untracked 目录始终未 stage。
  - 只按明确文件路径 `git add`，没有使用 `git add -A` / `git add .`。
