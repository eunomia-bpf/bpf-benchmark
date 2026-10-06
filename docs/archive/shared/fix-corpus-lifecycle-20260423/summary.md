# Corpus Lifecycle / Gate / Stabilization Fixes (2026-04-23)

## 修复清单

- `P0 corpus lifecycle bug`
  - 位置：`corpus/driver.py:867-877`, `corpus/driver.py:1174-1194`, `corpus/driver.py:1227-1280`
  - 改动：新增 `_refresh_active_session_programs()`，在共享 baseline 前和共享 scan/apply 前各做一次 live refresh；refresh 用 `runner/libs/app_runners/process_support.py:15-24` 的 `programs_after()` + 反向 session diff，按“当前 live ids 减去更晚启动 session 已认领 ids”重建每个 session 的 live set。
  - 结果：`state.prog_ids` 不再是 startup snapshot；每次进入测量 / scan 前都会被 live set 覆盖。`before_prog_ids` 只作为 refresh 输入，不进入 result/artifact。
  - 代码量：约 `+17` 行 non-comment non-blank。

- `P1 post-ReJIT measurement gate alignment`
  - 位置：`corpus/driver.py:1340-1344`
  - 改动：corpus 的 post phase gate 从 `_rejit_result_has_any_change(...)` 改为复用 `runner.libs.case_common.rejit_result_has_any_apply(...)`。
  - 结果：`all_sites_rolled_back` / `applied_but_identical` 不再被 corpus 压成 baseline-only；语义与 E2E 一致。
  - 代码量：约 `+2` 行 non-comment non-blank。

- `P2 exact-set 2s stabilization too strict`
  - 位置：`runner/libs/app_runners/process_support.py:15-56`, `runner/libs/app_runners/process_support.py:207`
  - 改动：把 `wait_until_program_set_stable()` 从“prog-id exact set 连续 2s 不变”改成“program count 连续 2s 不变且非空”；任何 count 变化才重置计时器，id churn / replacement 不再单独重置。
  - 结果：仍然 fail-loud，但不再因为 reload 换 id 导致 discovery 永远等不到 exact-set 稳定。
  - 代码量：约 `+9` 行 non-comment non-blank。

## 方案选择

- 选 `A`，没选 `B`。
- 原因：当前 corpus 共享 baseline / scan / apply 的骨架已经在用，直接改成 E2E 式 per-app 近距离 apply 会扩大 blast radius，也更容易碰到现有大规模删除后的脏工作树。
- 这次的 `A` 不是保留 snapshot fallback，而是把 snapshot 变成只在 `runner.start()` 后做一次“启动成功”校验；真正进入 baseline 和 scan/apply 之前都强制 live refresh，达到和 E2E 同方向的 live-id 对齐，同时改动面最小。

## 验证

- 已执行并通过：
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile corpus/driver.py runner/libs/app_runners/process_support.py runner/libs/case_common.py`
  - `source /home/yunwei37/workspace/.venv/bin/activate && make check`
  - `make -n vm-corpus`
  - `make -n vm-e2e`

- fresh artifact 对齐检查命令：

```bash
python3 - <<'PY'
import json

corpus = json.load(open('corpus/results/<fresh-corpus-run>/result.json'))
tracee = json.load(open('e2e/results/<fresh-tracee-run>/result.json'))
tetragon = json.load(open('e2e/results/<fresh-tetragon-run>/result.json'))

counts = {row['app']: len(row.get('programs') or []) for row in corpus['results']}
print('tracee corpus/e2e', counts['tracee/default'], len(tracee['preflight']['program_activity']['programs']['programs']))
print('tetragon corpus/e2e', counts['tetragon/default'], len(tetragon['tetragon_programs']))
PY
```

- 预期：`tracee/default` 与 `tetragon/default` 的 corpus/e2e program count 差值明显收敛，不再停留在旧 artifact 的 `37/158`、`35/260` 级别。

## Diff Stats

- 全仓当前 `git diff --shortstat`：`21 files changed, 311 insertions(+), 856 deletions(-)`
- 本轮 touched subset `git diff --shortstat -- corpus/driver.py runner/libs/app_runners/process_support.py`：`2 files changed, 43 insertions(+), 36 deletions(-)`
- `docs/tmp/fix-corpus-lifecycle-20260423/summary.md` 是本轮新建的 untracked 文件，默认不计入上面两条 `git diff --shortstat`
- 本轮新增 non-comment non-blank 代码估算：约 `28` 行，满足 `<= 30` 目标。

## 自我 Review

- `state.prog_ids` 还保留，但语义已经改成“当前 authoritative live set”，不是 startup cache；startup snapshot 没再直接驱动 baseline / scan / apply。
- 没有保留 “refresh 失败就退回 snapshot” 的分支；refresh 失败直接 raise。
- corpus post gate 已经直接复用 E2E helper，没有再保留 corpus-only 的 `changed` gate。
- stabilization 改动没有加 flag / env / config field，也没有动 `vendor/linux-framework/` 或 daemon Rust。
