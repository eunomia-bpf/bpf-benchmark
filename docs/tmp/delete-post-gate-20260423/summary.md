# Delete Post-ReJIT Gate (2026-04-23)

## 1. 调研命中清单

### 1.1 必读上下文

- `docs/kernel-jit-optimization-plan.md`
  - 编辑规则明确要求 benchmark/review 以删除为核心，不保留“以防万一”的旧分支；错误必须 loud fail，不能伪装成 baseline-only。
- `docs/tmp/program-coverage-gaps-20260423/summary.md`
  - `P1` 明确记录了 corpus / E2E 的 post-ReJIT measurement gate 不一致：`corpus/driver.py:549-558`, `corpus/driver.py:1325-1334`, `runner/libs/case_common.py:53-84`, `runner/libs/case_common.py:440-444`。
- `docs/tmp/fix-corpus-lifecycle-20260423/summary.md`
  - 上一轮把 corpus gate 从 `changed` 对齐到了 `rejit_result_has_any_apply(...)`，但这轮目标是进一步彻底删除 gate，而不是继续保留 helper。

### 1.2 当前工作树基线

- `git diff --stat`: `21 files changed, 250 insertions(+), 858 deletions(-)`
- `git diff --shortstat`: `21 files changed, 250 insertions(+), 858 deletions(-)`

### 1.3 直接 gate / helper / 调用点

- `runner/libs/case_common.py:53-84`
  - `rejit_result_has_any_apply(...)` helper；当前把 `changed` / `summary.total_sites_applied` / `debug_result.summary.total_sites_applied` 聚合成 “是否跑 post phase”。
- `runner/libs/case_common.py:344-345`, `440-444`, `486`, `504`, `566`, `580`, `617-622`
  - `should_run_post_rejit` 参数链 + `run_post_rejit` gate + `run_app_runner_phase_records()` 对 “apply/no-apply” 的分支化后处理。
- `corpus/driver.py:550-559`, `604`, `1086`, `1342-1344`
  - `_rejit_result_has_any_change(...)` helper；
  - `_build_program_measurements()` / `_build_app_result()` 使用 “any changed” 决定 comparability/missing-post 报错；
  - `run_suite()` 里直接按 `rejit_result_has_any_apply(session.apply_result)` 跳过 post measurement。
- `e2e/cases/scx/case.py:619-625`
  - `should_run_post_rejit=lambda ... total_sites > 0`，case 级 gate。
- `e2e/cases/tetragon/case.py:707-712`
  - 用 `rejit_result_has_any_apply(...)` 决定报 “reJIT did not apply” 还是 “post-ReJIT missing”。
- `e2e/cases/katran/case.py:145-149`
  - 用 `rejit_result_has_any_apply(...)` 决定把缺 post measurement 记成 error 还是 “measurement skipped”。
- `e2e/cases/tracee/case.py:1359-1362`
  - cycle 校验显式要求 `rejit_result_has_any_apply(...)`，否则报 “reJIT did not apply”。

### 1.4 相关语义 grep

- `rg -n ... 'skip_post|should_run_post|post_phase_enabled|post_measurement_gate|has_any_apply|has_any_change|rejit_result_has|any_program_changed|any_rejit_applied' runner/ e2e/ corpus/ daemon/`
  - live code 命中仅在：
    - `runner/libs/case_common.py`
    - `corpus/driver.py`
    - `e2e/cases/scx/case.py`
    - `e2e/cases/tetragon/case.py`
    - `e2e/cases/katran/case.py`
    - `e2e/cases/tracee/case.py`
- `rg -n ... 'if.*changed.*:|if.*applied.*:' runner/ e2e/ corpus/`
  - 与 post gate 直接相关的 live code 命中：
    - `corpus/driver.py:537`, `539`, `575`, `582`
    - `corpus/driver.py:680`
    - `e2e/cases/scx/case.py:694`
    - `runner/libs/case_common.py:63`, `67`, `71`, `75`
- `rg -n ... 'measurement_phase|run_post_phase|measure_post|post_rejit_phase' runner/ e2e/ corpus/`
  - live code无命中。

### 1.5 config / CLI / env

- `rg -n ... 'post_phase|skip_post|run_post|post_measurement|measure_post' e2e/cases/*/config*.yaml corpus/ runner/`
  - live code无命中。
- `rg -n ... '\"--post|--skip-post|--no-post|POST_PHASE|SKIP_POST|POST_MEASURE' runner/ e2e/ corpus/`
  - live code无命中。
- 结论：
  - 当前树里没有现役 post-phase YAML/CLI/env 开关；
  - 需要删除的是共享生命周期参数/branch/helper，而不是额外配置面。

### 1.6 结果字段 / 报告语义

- `corpus/driver.py:959`, `1120`
  - `had_post_rejit_measurement` 字段还在，当前会显式记录有没有跑到 post measurement。
- `corpus/driver.py:528-541`, `562-591`
  - `comparison_exclusion_reason` / Round 7 taxonomy (`zero_sites_found`, `all_sites_rolled_back`, `applied_but_identical`) 是 apply 结果分类，不是 gate；按要求保留 taxonomy，但删“是否跑 post”分支。
- `e2e/cases/tetragon/case.py:344-346`, `e2e/cases/tracee/case.py:815-816`
  - `compare_phases(..., post=None)` 仍把缺失 post 概括成 “rejit did not apply successfully”，语义需要改成 post phase 缺失/错误，而不是 no-apply gate。

## 2. 删除清单

- `runner/libs/case_common.py`
  - 删除 `rejit_result_has_any_apply(...)` 定义。
  - 删除 `should_run_post_rejit` 参数链：
    - `run_case_lifecycle(...)`
    - `run_app_runner_lifecycle(...)`
    - `run_app_runner_phase_records(...)`
  - 删除共享 gate：
    - `run_case_lifecycle()` 不再根据任何 `changed` / `total_sites_applied` / callback 判定是否跑 post phase。
    - `run_app_runner_phase_records()` 不再区分 “apply/no-apply” 两个 post 结果分支；只要 `rejit_apply` 存在，就产出 `post_rejit` record，`reason` 只来自 `rejit_apply.error` 或 `"post-ReJIT measurement is missing"`。
- `corpus/driver.py`
  - 删除 `_rejit_result_has_any_change(...)` helper。
  - 删除 `run_suite()` 里的 post-measure skip：
    - 旧逻辑：`if not rejit_result_has_any_apply(session.apply_result): continue`
    - 新逻辑：所有 active session 都直接进入 `_measure_runner_phase(... post-ReJIT ...)`。
  - 删除 `_build_program_measurements()` / `_comparison_exclusion_reason()` 对 loader-level `any_changed` helper 的依赖。
  - 删除结果字段 `had_post_rejit_measurement`。
- `e2e/cases/scx/case.py`
  - 删除 `should_run_post_rejit=lambda ... total_sites > 0` case-level gate。
  - 缺 post phase 统一报 `"scx post-ReJIT phase is missing"`；不再按 `applied_site_total > 0` 决定是否报错。
- `e2e/cases/tetragon/case.py`
  - 删除 `rejit_result_has_any_apply` import 和 `if not rejit_result_has_any_apply(...)` 分支。
  - 删除 `"Tetragon reJIT did not apply"` no-op/skip 语义；保留 `rejit_result.error` 硬错误和 `post_rejit is None` 缺失错误。
- `e2e/cases/katran/case.py`
  - 删除 `rejit_result_has_any_apply` import 和 `"no Katran program was applied; post-ReJIT measurement skipped"` 分支。
  - 缺 post phase 一律报 `"post-ReJIT measurement is missing"`。
- `e2e/cases/tracee/case.py`
  - 删除 `rejit_result_has_any_apply` import。
  - 删除 cycle 校验里的 `Tracee reJIT did not apply in cycle ...` gate；只保留 `post_rejit is None` 硬错误。

### 2.1 config / CLI / env 清理

- 现役源码里没有命中任何 post-phase YAML/CLI/env 开关，因此没有额外配置面需要删除。
- 复核结果：
  - `rg -n ... '"--post|--skip-post|--no-post|POST_PHASE|SKIP_POST|POST_MEASURE' runner/ e2e/ corpus/`：无命中。
  - `rg -n ... 'post_phase|skip_post|run_post' e2e/cases/*/config*.yaml corpus/ runner/`：无配置开关命中。

## 3. 调用点替换说明

- `runner/libs/case_common.py:402-407`
  - 从 “helper/callback 决定要不要跑 post phase” 改成：
    - `rejit_result = _merge_group_rejit_results(...)`
    - `post_rejit = workload(..., "post_rejit")`
  - 共享生命周期现在对每个 app/runner 永远走 baseline + post-ReJIT 两阶段；只有 `apply_rejit()` 自己 raise 或 post workload 自己失败时才以硬错误结束。
- `runner/libs/case_common.py:574-579`
  - `post_rejit` record 改为“只要 `rejit_apply` 存在就建 record”。
  - `reason` 只剩两类：
    - `rejit_apply.error`
    - `"post-ReJIT measurement is missing"`
- `corpus/driver.py:1321-1328`
  - corpus shared apply 之后对每个 `active_session` 都直接 `_measure_runner_phase(...)`，不再看 `changed/applied/total_sites_applied`。
- `corpus/driver.py:1067-1070`
  - `no comparable measurements` 校验不再依赖 `_rejit_result_has_any_change()` helper；改成直接看 `program_measurements` 里是否存在 `changed=true` 的 program。
- `e2e/cases/scx|tetragon|katran|tracee`
  - case-level 后处理统一成：
    - post phase 缺失 => error
    - `rejit_result.error` => error
    - “成功 apply 但 nothing changed” 不再产生 skip/no-apply gate 语义
- `corpus/driver.py:528-541` 的 Round 7 taxonomy 保留：
  - `zero_sites_found`
  - `all_sites_rolled_back`
  - `applied_but_identical`
  - `no_programs_changed_in_loader`
  - 这些仍只用于 apply 结果分类，不再决定是否跑 post phase。

## 4. 验证

- `python3 -m py_compile`（使用 `/home/yunwei37/workspace/.venv/bin/activate`）：
  - 全部当前已修改 Python 文件通过：
    - `corpus/driver.py`
    - `e2e/cases/{bcc,bpftrace,katran,scx,tetragon,tracee}/case.py`
    - `e2e/driver.py`
    - `runner/libs/{case_common,app_suite_schema,run_contract,suite_args}.py`
    - `runner/libs/app_runners/{process_support,scx,tetragon,tracee}.py`
    - `runner/suites/{corpus,e2e}.py`
- `make check`
  - 通过；当前仓库里该 target 展开为一组 `python3 -m py_compile ...`。
- `make -n vm-corpus`
  - 通过；输出：
    - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm corpus -- --samples "30"`
- `make -n vm-e2e`
  - 通过；输出：
    - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e --`
- `git diff --shortstat`
  - 当前：`23 files changed, 262 insertions(+), 953 deletions(-)`
  - 开始前：`21 files changed, 250 insertions(+), 858 deletions(-)`
  - 本轮相对开始前增量：`+12 / -95`，净负 `-83`。

## 5. 自我 Review

- gate helper / gate name 残留：
  - `rg -n ... 'rejit_result_has_any|should_run_post|skip_post|post_phase_enabled' runner/ e2e/ corpus/ daemon/`
  - 结果：无 live code 命中（命令退出码 `1`）。
- 剩余 `if.*rejit.*|if.*changed.*|if.*applied.*` 复核：
  - 仍有命中，但都不是 “是否跑 post phase” gate。
  - 保留的只包括：
    - apply taxonomy / comparability 计算（`corpus/driver.py`）
    - `post_rejit is None` 的硬错误检查（`scx/tetragon/katran/tracee`）
    - `rejit_result.error` 传播
  - 没有任何分支再根据 `changed` / `applied` / `total_sites_applied` 决定跳过 post phase。
- config / CLI / env：
  - 没有现役 `skip_post` / `run_post` / `post_phase_enabled` / `--skip-post` / `POST_PHASE` 控制面残留。
- 新增代码行数：
  - 由于 `corpus/driver.py` 等文件在本轮开始前已处于未提交脏状态，`git diff` 不能精确拆出“本轮新增且非空非注释”的独立计数。
  - 以整仓 `git diff --shortstat` 的增量看，本轮是 `+12 / -95`，整体仍显著删除为主。
  - 手工检查本轮 post-gate patch 的新增逻辑仅剩少量共享错误传播/比较条件替换，没有新增任何新的 flag/config/helper。
