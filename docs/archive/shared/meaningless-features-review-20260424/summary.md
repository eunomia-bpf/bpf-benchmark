# Meaningless Feature Review (2026-04-24)

只读审查完成。未修改任何代码，未运行任何 `make vm-*`。

已读上下文：
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/delete-smoke-config-20260424/summary.md`
- `docs/tmp/delete-all-activity-gates-20260424/summary.md`
- `docs/tmp/activity-review-fallback-purge-20260424/summary.md`
- `docs/tmp/meta-review-recent-commits-20260424/summary.md`

扫描范围实际覆盖：
- `runner/libs/**/*.py`
- `runner/suites/**/*.py`
- `runner/mk/**/*.mk`
- `Makefile`
- `e2e/**/*.py`
- `e2e/**/*.yaml`
- `corpus/**/*.py`
- `corpus/**/*.yaml`
- `micro/**/*.py`
- `daemon/src/**/*.rs`
- `runner/containers/*.Dockerfile`

## 1. 扫描矩阵 S1-S10

### S1. smoke-like mode 残留
- 命令：
```bash
rg -n -i -S '\b(smoke|quick|fast_mode|light|minimal_mode|mini|lite|ci_mode|dry_run|warmup_only|probe_only|demo|short_run|tiny_run|sample_only|pilot|preview|rehearsal|baseline_only)\b' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src Makefile \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile' --glob 'Makefile'
```
- 命中数：`15`
- 逐项判断：
  - `runner/libs/rejit.py:611,786,791-792,871` -> ✅ `dry_run` 是 daemon 的 scan/apply RPC 分支，用来先做 site census，再决定 apply；不是“轻量 benchmark mode”。
  - `daemon/src/server.rs:392-404` -> ✅ 解析 `dry_run` 到 `OptimizeMode::{DryRun,Apply}`，和上面的 scan/apply 分支一致。
  - `daemon/src/commands.rs:230-233,534-535,658-669` -> ✅ 两值 enum，`DryRun` 走 pipeline 但不 REJIT syscall；这是功能分支，不是 smoke 变体。
  - `runner/libs/app_runners/process_support.py:50-54` -> ✅ `preview` 只是 timeout 诊断里打印最近 prog id 预览。
  - `daemon/src/passes/utils.rs:141` -> ✅ 注释里的 `quick lookup`，非功能。
- follow-up 精确 smoke grep：
```bash
rg -n -i -S '\bsmoke\b|--e2e-smoke|E2E_SMOKE|vm-micro-smoke' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src Makefile \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile' --glob 'Makefile'
```
- 命中数：`0`
- 结论：`smoke / E2E_SMOKE / --e2e-smoke / vm-micro-smoke` 在本次扫描范围内已经清干净。
- 宽词表复扫：
```bash
rg -n -i -S '\b(quick|fast|light|minimal|mini|lite|dry|probe|demo|short|tiny|pilot|preview|rehearsal|baseline)\b' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src Makefile \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile' --glob 'Makefile'
```
- 原始命中数：`199`
- 审核结论：未发现新的“轻量/快速 mode”控制流残留；主要都是词法噪声。
  - `e2e/cases/tracee/case.py:206-215,904-927` -> ✅ `warmup` / `latency_probe` 是真实 startup settle + latency measurement。
  - `micro/config/micro_pure_jit.yaml:47,108,794` -> ✅ `level: tiny/short` 是 benchmark 元数据，不参与控制流。

### S2. 过滤/阀门
- 命令：
```bash
rg -n -S '\b(filter_|skip_if|skip_when|blacklist|whitelist|allowlist|denylist|is_applicable|is_relevant|should_run|prune_|exclude_|discard_|ignore_)\b' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile'
```
- 命中数：`0`
- follow-up 1：把 `skip_*` 放宽到通配，再补查 hyphenated CLI：
```bash
rg -n -i -S 'skip[-_](probe|post|measurement)|skip probe|skip measurement|skip post' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src Makefile \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile' --glob 'Makefile'
```
- 命中数：`8`
- 判断：
  - `Makefile:47,59,66` -> 🟡 `SCX_PROG_SHOW_RACE_SKIP_PROBE` 通过 Makefile/env 暴露了一个 test-suite skip gate。
  - `runner/libs/suite_args.py:123-124` -> 🟡 同一个 skip gate 继续向 suite argv 透传。
  - `runner/suites/test.py:60,195-196` -> 🟡 CLI `--scx-prog-show-race-skip-probe` 最终变成对子测试二进制的 `--skip-probe`。
- follow-up 2：补查语义词 `eligible/applicable/relevant/should_*`：
```bash
rg -n -S '\b(eligible|applicable|relevant|should_run|should_measure|measurement_needed)\b' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile'
```
- 命中数：`5`
- 判断：
  - `e2e/cases/bpftrace/case.py:316`, `e2e/cases/bcc/case.py:339` -> ✅ 说明文字，不是 gate。
  - `daemon/src/passes/skb_load_bytes.rs:50`, `daemon/src/passes/mod.rs:70` -> ✅ “eligible helper sites” 是 pass 语义描述。
  - `runner/libs/workload.py:310` -> ✅ `eligible module candidates` 是 workload 准备阶段的硬条件，不是 benchmark filter。
- 手工补查到一个真正存在的 pass filter：
  - `corpus/config/benchmark_config.yaml:29-34`
  - `runner/libs/case_common.py:205-230`
  - 判断：✅ 这是对 `struct_ops` 关闭 `map_inline`/`dce` 的 correctness guard，不是任意 whitelist/blacklist。

### S3. 条件 post-measurement
- 命令 1：
```bash
rg -n -S 'if .*(applied|changed|modified|rewritten)' runner/libs runner/suites e2e corpus --glob '*.py' --glob '*.yaml' | rg -v test
```
- 命中数：`20`
- 命令 2：
```bash
rg -n -S 'skip_post|skip_measurement|measurement_needed|should_measure' runner/libs runner/suites e2e corpus --glob '*.py' --glob '*.yaml'
```
- 命中数：`0`
- 判断：
  - `e2e/cases/scx/case.py:646-649` -> 🔴 已经拿到了 `baseline` 和 `post_rejit`，但仍然按 `applied_site_total > 0` 才调用 `compare_phases()`；这违反“每 app 无条件两阶段比较”。
  - `runner/libs/case_common.py:470-472` -> ✅ framework lifecycle 对 active sessions 会无条件执行 `measure(..., "post_rejit")`；这里本身是干净的。
  - `corpus/driver.py:551-565,594-601,921-924` -> 🔴 corpus 不跳过 phase 执行，但在 phase 结束后又把结果降级成 `not comparable`，甚至在 `changed && !has_comparable_measurement` 时直接报错，属于 post-measurement gate。

### S4. 单值 mode / 单值 enum
- 命令 1：
```bash
rg -n -S 'mode\s*==\s*["'"'"']' runner/libs runner/suites e2e corpus daemon/src --glob '*.py' --glob '*.yaml' --glob '*.rs'
```
- 命中数：`6`
- 判断：
  - `runner/suites/test.py:315-321` -> ✅ `test_mode` 有 `selftest/negative/fuzz/test` 四个 case。
  - `runner/libs/run_contract.py:372-379` -> ✅ 同一组 `test_mode` 校验/派生逻辑，非单值。
- 命令 2：
```bash
rg -n -S 'kind\s*==\s*["'"'"']' runner/libs runner/suites e2e corpus daemon/src --glob '*.py' --glob '*.yaml' --glob '*.rs'
```
- 命中数：`47`
- 判断：全部是合法多值 workload/probe dispatch，不是单值 enum。
  - `runner/libs/workload.py:1138-1212` -> ✅ workload kind 分发，覆盖大量 workload。
  - `runner/libs/app_runners/tracee.py:464-487` -> ✅ tracee workload kind 分发。
  - `runner/libs/app_runners/tetragon.py:121-129` -> ✅ tetragon workload kind 分发。
  - `runner/libs/app_runners/scx.py:254-258` -> ✅ scx workload kind 分发。
  - `runner/libs/app_runners/katran.py:939-999` -> ✅ katran workload kind 分发。
  - `e2e/cases/tracee/case.py:302-304` -> ✅ latency probe kind 分发。
- 命令 3：
```bash
rg -n -S 'type\s*==\s*["'"'"']' runner/libs runner/suites e2e corpus daemon/src --glob '*.py' --glob '*.yaml' --glob '*.rs'
```
- 命中数：`0`
- 结论：没有发现“只有一个 case 的 switch/enum”。

### S5. 永不命中的 if/else 分支
- 方法：基于 S4/S7 命中手工回看 branch 周边定义。
- 结论：
  - `0` 个有意义的 never-hit if/else。
  - `1` 个小型 tautology：
    - `runner/libs/app_runners/katran.py:278` -> 🟢 `self.router_peer_iface = router_peer_iface or None` 等价于直接赋值；属于死味道，不是有行为影响的 dead branch。

### S6. "deprecated but kept" 标记
- 命令：
```bash
rg -n '# (deprecated|legacy|kept for|unused but|TODO.*(remove|delete|clean))' \
  runner/libs runner/suites runner/mk runner/containers e2e corpus micro daemon/src \
  --glob '*.py' --glob '*.yaml' --glob '*.mk' --glob '*.rs' --glob '*.Dockerfile'
```
- 命中数：`0`
- 结论：这类显式“deprecated/legacy/kept for”残留在扫描范围内已清空。

### S7. 参数 `= None` 下游立刻 `or default()`
- 原始命令：
```bash
rg -n -P '\b\w+\s*=\s*None\s*[,)]' runner/libs e2e/cases corpus --glob '*.py' --glob '*.yaml'
```
- 原始命中数：`137`
- follow-up：对 Python AST 做 immediate-default 复核，只看“参数默认 None 后立刻 `or ...` / `if x is None` / `ifexp` 归一化”的真实候选。
- follow-up 命中数：`53`
- 判断：
  - `runner/libs/__init__.py:26-32,107-120` -> ✅ 正常 helper 默认值：`now or datetime.now()`、`stamp or scratch_date_stamp()`、`cwd or ROOT_DIR`。
  - `runner/libs/rejit.py:835-841` -> ✅ API 归一化：`prog_ids or []` / `enabled_passes is not None`。
  - `runner/libs/reporting.py:281,406` -> ✅ lazy load manifest，不是 fallback shim。
  - `runner/libs/app_runners/katran.py:278` -> 🟢 真正多余的一条：`router_peer_iface or None`。
- 结论：这类问题没有形成系统性坏味道；只有 1 处值得顺手清。

### S8. framework-level 二次分析
- 命令：
```bash
rg -n -S '(remove_outliers|filter_results|trim_samples|drop_invalid|skip_low|discard_stale)' \
  runner/libs runner/suites e2e corpus micro --glob '*.py' --glob '*.yaml'
```
- 命中数：`0`
- 但手工语义复核发现 1 组真正的等价实现：
  - `corpus/driver.py:639-740` -> 🔴 `_comparison_rows()` 把结果拆成 `comparable_rows` / `applied_rows` / `excluded_rows`，后续 `_per_app_breakdown()` / `_build_summary()` 再产出 `applied_only_geomean`、`all_comparable_geomean`、`comparison_exclusions`。这就是 framework-level 二次筛。

### S9. 单 consumer 的配置字段
- 状态：只做了 targeted check，没有做全 YAML key census。
- 复核对象：
  - `SCX_PROG_SHOW_RACE_SKIP_PROBE`
- 命中链路：
  - `Makefile:47,59,66`
  - `runner/libs/suite_args.py:123-124`
  - `runner/suites/test.py:60,195-196`
  - out-of-scope consumer：`tests/negative/scx_prog_show_race.c:119,656-666`
- 判断：
  - 🟡 这是单用途 test/debug knob，不是 framework 核心能力。

### S10. 条件编译 / feature flag
- 命令 1：
```bash
rg -n -S '#\[cfg\(feature = ' daemon/src --glob '*.rs'
```
- 命中数：`0`
- 命令 2：
```bash
rg -n -S 'getenv\(|os\.environ\.get\(' runner/libs runner/suites e2e corpus --glob '*.py' --glob '*.yaml'
```
- 命中数：`22`
- 判断：
  - `runner/libs/rejit.py:470`, `runner/libs/case_common.py:198-220` -> ✅ `BPFREJIT_BENCH_PASSES` 是显式 pass override / ablation knob；当前默认路径不会自动注入它。
  - `runner/libs/workspace_layout.py:43-48` -> ✅ runtime-container 路径探测。
  - `runner/libs/__init__.py:57,94` -> ✅ tool path override。
  - `runner/libs/app_runners/bcc.py:130,146` -> ✅ BCC 兼容头和 extra cflags 覆盖，属于部署/环境适配。
- 结论：没有 Rust `cfg(feature)` 残留；Python env 读取基本都是部署/实验显式覆盖，不像偷塞的 smoke shim。

## 2. 按严重度汇总

### 🔴 BLOCKER 清单

- `corpus/driver.py:551-565`
  - 符号/关键词：`_comparison_exclusion_reason()`, `if not _apply_record_program_changed(apply_record)`
  - 违反原则：phase 已跑完后，再按 `changed` / `had_post_rejit` / `rejit_exec_ns` 把结果打成 `not comparable`。
  - 建议删除动作：删掉 `comparison_exclusion_reason` 这套后置 taxonomy，不要把 phase 结果二次降级成“不可比较”。

- `corpus/driver.py:594-601`, `639-740`
  - 符号/关键词：`comparable`, `_comparison_rows()`, `applied_rows`, `excluded_rows`, `applied_only_geomean`, `all_comparable_geomean`
  - 违反原则：framework-level 二次分析/过滤；报告层不应再筛一轮 program/app/metric。
  - 建议删除动作：删 `comparable_rows/applied_rows/excluded_rows` 三分流，删 `applied_only_geomean` / `all_comparable_geomean` / `comparison_exclusions`，改成直接基于无条件 baseline/post 结果汇总。

- `corpus/driver.py:921-924`
  - 符号/关键词：`has_comparable_measurement`
  - 违反原则：后置 comparability gate 还能把整个 app 直接 fail。
  - 建议删除动作：删这条 `changed && !has_comparable_measurement` hard-fail；phase 结果应该照实报，不应因为比较层的过滤条件失败而升级成 app error。

- `e2e/cases/scx/case.py:646-649`
  - 符号/关键词：`if applied_site_total > 0`
  - 违反原则：Round 8 要求 per-app 无条件两阶段；这里已经拿到 `post_rejit`，却还按 site count 决定是否比较。
  - 建议删除动作：删 `applied_site_total > 0` 条件分支；只要 `post_rejit` 在，就无条件 `compare_phases(baseline, post_rejit)`。

### 🟡 SHOULD 清单

- `Makefile:47,59,66`
  - 符号：`SCX_PROG_SHOW_RACE_SKIP_PROBE`
  - 理由：suite 级 env surface，专门把一个 skip gate 透传给单个负测程序。
  - 建议动作：删 Makefile env/export/argv 注入；如果该负测必须保留两条路径，至少不要再经由顶层 suite surface 暴露。

- `runner/libs/suite_args.py:123-124`
  - 符号：`--scx-prog-show-race-skip-probe`
  - 理由：和上面同一条 forwarding chain；单 consumer，debug/test knob 味道很重。
  - 建议动作：删 suite-args 层的转发。

- `runner/suites/test.py:60,195-196`
  - 符号：`parser.add_argument("--scx-prog-show-race-skip-probe")`, `scx_command.append("--skip-probe")`
  - 理由：test-suite 里仍保留显式 skip gate；不是算法必需，也不是统一测试主路径。
  - 建议动作：删 argparse surface 和 `--skip-probe` 分支，固定为一条 canonical negative-test path。

### 🟢 NICE 清单

- `runner/libs/app_runners/katran.py:278`
  - 符号：`router_peer_iface or None`
  - 理由：参数默认就是 `None`，这里再 `or None` 纯属形式噪声。
  - 建议动作：直接赋值。

- `e2e/cases/tetragon/case.py:465,590`
  - 符号：payload `"mode": "error"` / `"mode": "tetragon_daemon"`
  - 理由：report-only mode 字段，只有展示用途，没有控制流价值。
  - 建议动作：如果报告标题已足够表达场景，可删 `mode` 字段本身。

- `e2e/cases/tracee/case.py:949,1156`
  - 符号：payload `"mode": "error"` / `"mode": "tracee_daemon_same_image_paired"`
  - 理由：同上，属于 report metadata 噪声。
  - 建议动作：若无外部 consumer，删掉。

### ✅ 保留清单（带理由）

- `runner/libs/rejit.py:611,786,791-792,871`
- `daemon/src/server.rs:392-404`
- `daemon/src/commands.rs:230-233,534-535,658-669`
  - 为什么保留：`dry_run` 是 daemon 的 scan/apply 双态，用来先跑 pipeline 拿 site counts，再决定实际 apply；不是 smoke/quick benchmark mode。

- `e2e/cases/tracee/config.yaml:3`
- `e2e/cases/tracee/case.py:206-215,904-927`
  - 为什么保留：`warmup_duration_s` 是 startup settle window。代码先 `warmup_workload()`，随后仍无条件执行真实 `measure_workload()` 并 `verify_phase_measurement(record)`，不是 warmup-only/probe-only mode。

- `e2e/cases/tracee/case.py:300-376,904-927`
  - 为什么保留：`latency_probe_*` 是真实 latency measurement，结果进入 payload 的 `latency_probe` / `latency_ms`；不是 `probe_only` 快速路径。

- `corpus/config/benchmark_config.yaml:29-34`
- `runner/libs/case_common.py:205-230`
  - 为什么保留：`struct_ops` 上禁用 `map_inline` / `dce` 是 correctness guard。注释明确指出 live scheduler-owned kptr state 会被错误冻结；这属于算法/运行时约束，不是随意 filter。

- `runner/libs/__init__.py:26-32,107-120`
  - 为什么保留：`now or datetime.now()`、`stamp or scratch_date_stamp()`、`cwd or ROOT_DIR` 都是正常 helper API 默认值，不是 fallback shim。

- `runner/libs/rejit.py:470`
- `runner/libs/case_common.py:198-220`
  - 为什么保留：`BPFREJIT_BENCH_PASSES` 是显式实验/ablation override。默认路径不依赖它，也没有 Makefile 默认注入。

- `runner/libs/case_common.py:470-472`
  - 为什么保留：framework lifecycle 对 active session 的 `post_rejit` measurement 是无条件执行的；这正是 Round 8 想要的骨架。

## 3. 下一轮清理优先级建议

1. 先删 `corpus/driver.py` 的 comparability/filter 层。
   - 影响最大。
   - 现在的 `comparable/excluded/applied_only` 已经不是“记录结果”，而是在“挑结果”。

2. 再删 `corpus/driver.py:921-924` 的 hard-fail。
   - 否则即使 phase 都跑完，比较层条件也会把 app 变成 error。

3. 删 `e2e/cases/scx/case.py:646-649` 的 site-count comparison gate。
   - 改动点小。
   - 清理净度高，能直接把 SCX 对齐到“有 baseline/post 就比较”。

后续顺手项：
- 清掉 `SCX_PROG_SHOW_RACE_SKIP_PROBE` 这一整条 suite-level skip surface。
- 清掉 `katran/tracee/tetragon` 的 report-only mode 噪声字段。

## 4. 签收

- 当前干净度评分：`3/5`
- 一句话：`smoke` 这层基本清干净了，但框架里仍然有严重的无意义 feature，核心是 `corpus` 的二次 comparability/filter 层和 `scx` 的 site-count comparison gate。
