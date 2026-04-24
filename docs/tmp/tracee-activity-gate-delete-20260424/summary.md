# Tracee Activity Gate Delete 2026-04-24

## 1. 起点状态

- 按要求先读取了 `docs/kernel-jit-optimization-plan.md` 和 `docs/tmp/tetragon-revert-20260423/summary.md`。
- 开工前 `git diff --stat` 为：
  - `e2e/cases/bpftrace/case.py | 9 +++++++--`
  - `e2e/driver.py | 18 ++++++++++--------`
  - `runner/libs/app_runners/tracee.py | 4 +++-`
  - 合计 `3 files changed, 20 insertions(+), 11 deletions(-)`
- `runner/libs/app_runners/tracee.py` 在起点已是脏状态；本轮只读取语义，没有修改。
- Tracee 残留 gate 位于：
  - `e2e/cases/tracee/config.yaml:1` 的 `require_program_activity: true`
  - `e2e/cases/tracee/case.py` 里的 `require_program_activity` 读取、`require_tracee_activity` 参数链、以及 preflight skip/abort 分支

## 2. 删除清单

- `e2e/cases/tracee/config.yaml:1`
  - 删除 `require_program_activity` 配置项。
- `e2e/cases/tracee/case.py:394`
  - `verify_phase_measurement()` 签名删除 `require_tracee_activity` 参数。
  - 删除 `if not require_tracee_activity: return`，校验体本身不再受 flag 控制。
- `e2e/cases/tracee/case.py:1037-1082`
  - `run_phase()` 签名删除 `require_tracee_activity` 参数。
  - 调用点不再传 flag；非 `control` phase 统一执行 `verify_phase_measurement()`。
- `e2e/cases/tracee/case.py:1127-1164`
  - 删除 `require_program_activity = bool(config.get(...))`。
  - 删除 `require_program_activity` 依赖 `preflight_duration_s > 0` 的报错分支。
- `e2e/cases/tracee/case.py:1257-1266`
  - 保留 preflight `program_activity` 汇总，但删除 “flag=false 就跳过” 的分支。
  - preflight 汇总到的 `total_run_cnt <= 0` 现在直接 `raise RuntimeError(...)`，变成 loud fail。
- `e2e/cases/tracee/case.py:1287`
  - baseline/post-ReJIT workload 调用点删除 `require_tracee_activity=True` 参数传递。

## 3. 语义结果

- Tracee 的 measurement 校验不再依赖任何 config flag。
- `control` phase 仍然不做 Tracee event/BPF activity 校验，因为它本来就不启动 Tracee；这不是 activity gate，只是 phase 语义区分。
- `preflight` / `baseline` / `post_rejit` 现在统一是 fail-loud：
  - event file parse error > 0 直接报错
  - `events_total <= 0` 直接报错
  - `lost_event_count` / `lost_write_count` > 0 直接报错
  - `bpf.summary.total_events <= 0` 直接报错
  - preflight 汇总出的 discovered program set `total_run_cnt <= 0` 直接报错
- 没有保留 backward-compat shim，也没有新增 flag / env / config。

## 4. LOC

- subset shortstat：
  - `git diff --shortstat -- e2e/cases/tracee/config.yaml e2e/cases/tracee/case.py`
  - 结果：`2 files changed, 6 insertions(+), 29 deletions(-)`
- 全仓 shortstat（写报告前）：
  - `git diff --shortstat`
  - 结果：`5 files changed, 26 insertions(+), 40 deletions(-)`
- 满足“净 LOC 减少”要求。

## 5. 验证

- live-code grep：
  - 命令：`source /home/yunwei37/workspace/.venv/bin/activate && rg -n --glob '!e2e/results/**' --glob '!runner/build-*/toolchain/**' 'require_program_activity|require_tracee_activity' runner/ e2e/`
  - 结果：`exit 1`，即 0 命中
- Python 编译：
  - 命令：`source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py`
  - 结果：`exit 0`
- 仓库检查：
  - 命令：`source /home/yunwei37/workspace/.venv/bin/activate && make check`
  - 结果：`exit 0`
- 按要求未运行任何 `make vm-*`。

## 6. 提交要求

- 当前分支：`main`
- 提交信息：`[e2e/tracee] delete require_program_activity activity gate`
- 提交正文将包含：
  - 本轮删除 Tracee activity gate 的摘要
  - `Co-Authored-By: Claude Opus 4.7 (1M context) <noreply@anthropic.com>`
