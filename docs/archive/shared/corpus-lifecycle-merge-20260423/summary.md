# Corpus Lifecycle Merge (2026-04-23)

## Design

- 方案：新增 `runner/libs/case_common.py::run_lifecycle_sessions(...)`，统一接收一个或多个**已启动** session，负责 `baseline -> shared scan/apply -> post -> stop`。
- 原因：`run_case_lifecycle()` 继续包装单 session，E2E 调用点零改动；corpus 直接传整组 session，复用同一骨架而不引入 `if corpus else e2e`。
- `before_prog_ids`、baseline 前 refresh、scan/apply 前 refresh、post 无条件执行、grouped apply、slice 回填 都保留。

## File Delta

- `corpus/driver.py`
  - 删除了原手写 lifecycle block（原审计点 `1137-1335`）并改成一次 `run_lifecycle_sessions(...)` 调用。
  - 同时删除本地 `_slice_scan_results()` / `_slice_rejit_result()` 和 `CorpusAppSession` 上那套旧 state-machine 中间字段。
  - `git diff --numstat -- corpus/driver.py`：`+74 / -293`，净 `-219`.
- `runner/libs/case_common.py`
  - 新增多 session helper、把 slice helper 提升到 shared 层，并让 `run_case_lifecycle()` 委托到这个 helper。
  - `git diff --numstat -- runner/libs/case_common.py`：`+231 / -102`，净 `+129`.

## Net Diff

- 代码 touched subset：
  - `git diff --shortstat -- runner/libs/case_common.py corpus/driver.py`
  - `2 files changed, 305 insertions(+), 395 deletions(-)`
- staged change set（含本报告）：
  - `git diff --cached --shortstat`
  - `3 files changed, 345 insertions(+), 395 deletions(-)`
- 结论：最终提交集净删 `53 LOC`，满足“净减 >= 50”。

## Self Review

- Commit 选择：`1 commit`。原因是 `case_common` 的多-session helper 和 `corpus` 的切换是同一个语义单元；拆成两个 commit 会留下一个“helper 已扩展但 corpus 仍保留第二套 state machine”的中间点，既不干净也没有独立验证价值。
- 这次是真合并，不是 `if corpus else e2e`：
  - 单 session 还是 `run_case_lifecycle()`。
  - 多 session 走同一个 `run_lifecycle_sessions()`。
  - 差异只体现在 caller 传入的 session 数量和 refresh callback。
- 保留的 corpus-specific 语义：
  - 多 app 并发启动仍在 corpus 侧。
  - shared helper 内仍按每个 session 的 `prog_ids` 单独算 enabled passes。
  - daemon 仍只做一次 shared scan 和按 pass tuple 分组 apply。
  - apply 结果仍按 session slice 回填，finalization 仍按 app 单独出结果。
