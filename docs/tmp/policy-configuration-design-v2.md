# Policy Configuration Design v2

## 背景与 v2 结论

当前问题不是 scanner 不够通用，而是 apply 阶段还停留在 blind all-apply。

- scanner 已经能对任意 `.bpf.o` 或 live `prog_fd` 自动发现 eligible sites，这一层已经是程序无关的。
- 真正缺的是 profitability 判断，而这也应该是程序无关的。
- “程序无关”不等于“所有程序共用一份 policy”，而是“不需要人类理解某个 eBPF 程序在做什么，再手工给它写 family 开关”。

因此，v2 的核心修正是：

1. policy tuning 的主入口不再是“人类手写 per-program policy”，而是“auto-tuner 自动生成 per-program policy artifact”。
2. steady-state 默认不应再走 implicit all-apply；all-apply 只应作为 tuner 的搜索点和 debug override。
3. YAML policy 是版本控制里的 source of truth；v5 blob 只是 scanner 按需编译出来的执行产物。
4. scanner 需要从“site discoverer”升级为“site discoverer + policy compiler”。

一句话总结：

> Scanner 负责自动发现 site，auto-tuner 负责自动判断 profitability，policy YAML 是自动调优结果的持久化 artifact，runner/agent 只负责执行。

## 1. v2 的核心澄清

### 1.1 “程序无关”到底是什么意思

这里的“程序无关”指的是 tuning workflow 对程序语义不做人工假设：

- 不需要人类知道某个 eBPF 程序是 XDP fast path、Tracee probe 还是 Tetragon hook。
- 不需要人类手动判断“这个程序该禁 cmov，那个程序该留 endian”。
- 只需要一个 workload trigger，能够稳定触发该程序并给出可测量的性能信号。

也就是说：

- discovery 是黑盒的 pattern scan；
- profitability 是黑盒的 measurement loop；
- 输出虽然是 per-program policy，但生成过程不依赖人工理解该 program。

### 1.2 v1 到 v2 的真正变化

v1 的主轴还是“把 policy 从 CLI 状态变成 per-program 数据”；这件事是对的，但仍然容易让人把 YAML 理解成“人类主要维护的配置”。

v2 要把主从关系改掉：

- 主路径：auto-tuner 生成 YAML。
- 辅路径：人类只在需要 override 时编辑 YAML。
- debug 路径：`--skip-families`、`scanner apply --all` 继续保留，但不再承担主策略表达。

### 1.3 默认行为也要跟着改

如果目标是通用自动 tuning，那么 steady-state 默认行为应改成：

- 有 tuned policy：按 policy 生成 blob 并 apply。
- 没有 tuned policy：默认 stock。
- 只有在显式 exploration/tuning/debug 模式下，才跑 all-apply。

否则系统还是会回到“还没调好之前先盲目全开”的旧问题。

## 2. 程序无关的自动 tuning 设计

### 2.1 角色分工

v2 中三层职责应明确分离：

- `scanner`
  - 发现 site
  - 导出 machine-readable site manifest
  - 读取 policy YAML
  - 过滤 discovered rules
  - 编译 v5 blob
- `auto-tuner`
  - 跑 stock / all-apply / ablation
  - 选择最优 family 组合
  - 生成 policy YAML
- `micro` / `corpus` / `e2e`
  - 提供 workload trigger
  - 提供测量接口
  - 在 steady-state 使用已经生成的 policy

这三个角色里，只有 workload trigger 是 layer-specific；search logic 本身应共享。

### 2.2 输入与输出

auto-tuner 的逻辑输入应是：

- 一个 `.bpf.o`
- 一个 workload trigger
- 可选的 objective/constraint 配置

逻辑输出应是：

- 该程序或该对象内各 program 的最优 policy YAML
- 一份 tuning report（JSON/Markdown）

需要注意多 program object：

- 输入虽然可以是一个 `.bpf.o`，但 tuner 应自动枚举其中可 load 的 program。
- search unit 是单个 program，不是整个 object 一刀切。
- 因此，一个 object 输入可能产出多个 YAML 文件。

### 2.3 workload trigger 是唯一需要外部提供的东西

对一份静态 `.bpf.o` 来说，系统无法凭空知道 production workload。

所以 v2 的边界应该说清楚：

- 人类或 harness 需要提供“怎么触发这个程序”的 workload trigger；
- 但不需要提供“这个程序应该开哪些 family”的 policy 知识。

这已经满足“policy tuning 不依赖人类理解具体程序”的要求。

不同层的 trigger 可以不同：

- micro：固定 benchmark 输入和 repeat 配置
- corpus：`BPF_PROG_TEST_RUN`、attach+trigger、trace workload 等
- e2e：agent case 自带的真实 workload driver

### 2.4 auto-tuner 的标准搜索流程

v2 推荐的主流程就是用户要求的那条线：

1. `stock`
2. `all-apply`
3. `per-family ablation`
4. `选最优组合`
5. `生成 policy YAML`

更具体地说：

#### Phase A: Discovery

先用 scanner 对 program 做一次自动 discovery：

- 导出 site manifest
- 得到 program 实际出现的 family 集合
- 统计每个 family 的 site 数

这一步完全程序无关，而且可以直接缩小搜索空间。没有 site 的 family 不进入后续搜索。

#### Phase B: Stock baseline

在完全不 apply policy 的情况下跑 workload，得到 baseline。

#### Phase C: All-apply screening

对“该程序实际出现的全部 family”跑一次 all-apply。

这里有两个关键点：

- all-apply 是 tuner 的探索动作，不是 steady-state 默认行为。
- all-apply 使用的是该 program 的 eligible families，而不是“理论上的所有 family”。

#### Phase D: Per-family ablation

如果 all-apply 没有稳定胜过 stock，就对实际出现的每个 family 做一次 ablation：

- `all - cmov`
- `all - wide`
- `all - rotate`
- `all - lea`
- `all - extract`
- `all - zero-ext`
- `all - endian`
- `all - branch-flip`

当然，只有 manifest 里出现过的 family 才需要试。

这一阶段的目标不是让人手工看表，而是让 tuner 自动回答：

- 哪个 family 是主要回归源
- 哪些 family 可以保留
- 哪些 family 组合值得继续搜索

#### Phase E: 组合搜索

在 per-family ablation 之后，组合搜索不需要从 `2^8` 暴力全搜开始。

推荐规则：

- 先只在“移除后明显改善 all-apply”的 family 子集上继续搜索
- 如果该子集大小 `k <= 4`，直接穷举
- 如果 `k > 4`，先用 greedy 或 beam search，再对 top candidates 精搜

这样可以让搜索仍然是全自动的，同时避免组合爆炸。

#### Phase F: Validation

选出候选 winner 后，再用 winner policy 重跑一次验证：

- 结果是否稳定
- correctness 是否不变
- apply 是否成功
- 是否确实优于 stock 或者至少不差于 stock

若最终结论是“stock 仍然最好”，也应显式产出一个 policy YAML，表示：

- 这个 program 在该 workload 下当前最优决策就是“不 apply 任何 family”

### 2.5 评价指标应保持程序无关

profitability 判断也不能依赖“程序语义分类器”，而应依赖统一测量接口。

推荐：

- micro / corpus
  - 主目标：`exec_ns`
  - 约束：correctness、apply success、可选 code-size guardrail
- e2e
  - 主目标：应用吞吐或 case 定义的主 KPI
  - 次目标：agent CPU、BPF avg ns、drops 等

无论哪一层，tuner 都只看 measurement，不看“这个程序应该是什么类型”。

### 2.6 生成的 steady-state policy 应优先用 allowlist

虽然搜索过程会自然产生很多 `all - family` 结果，但最终写入仓库的 YAML 应默认使用 allowlist 形式：

- 搜索空间：可以是 `all` / `all - family`
- 持久化 artifact：应优先写成显式 `allowlist`

原因很简单：

- denylist 依赖“当前 scanner 能发现哪些 family”
- 如果未来 scanner 从 8 family 扩到 9 family，denylist 可能会静默启用一个新 family
- allowlist 更适合做稳定、可 diff、可审核的仓库 artifact

因此：

- generated policy 默认写 `selection.mode: allowlist`
- `families: []` 明确表示“保持 stock”
- denylist 只保留给临时实验或人工 override

### 2.7 伪代码

```text
auto_tune(object, workload):
    manifest = scanner.scan_json(object)
    for program in manifest.programs:
        eligible = {f | program.site_count[f] > 0}

        stock = measure(program, stock)
        all_candidate = eligible
        all_result = measure(program, policy=all_candidate)

        trial_results = {all_candidate: all_result}

        for family in eligible:
            candidate = eligible - {family}
            trial_results[candidate] = measure(program, policy=candidate)

        promising = select_promising_candidates(trial_results)
        for candidate in combo_search(promising):
            trial_results[candidate] = measure(program, policy=candidate)

        winner = choose_best(trial_results, stock)
        validate(winner)
        emit_policy_yaml(program, allowlist=winner)
```

这里完全没有“人类按程序手写 family”的步骤。

## 3. Policy 文件与目录结构

### 3.1 Source of truth 与 build artifact 要分离

v2 中需要明确三种 artifact：

1. `policy YAML`
   - 持久化 source of truth
   - 进入版本控制
2. `site manifest JSON`
   - scanner discovery 产物
   - 供 tuner/调试使用
   - 不应作为主要持久配置
3. `v5 policy blob`
   - 执行时 artifact
   - 由 scanner 按需编译
   - 不进入版本控制

也就是说：

- 仓库里存 YAML
- 运行时临时生成 blob
- 不要把 blob 当成主要配置文件

### 3.2 目录结构

建议统一为：

- `micro/policies/<benchmark_name>.yaml`
- `corpus/policies/<project>/<object>/<program>.yaml`
- `e2e/policies/<agent>/<program>.yaml`

其中：

- `<benchmark_name>` 对应 micro manifest 里的 benchmark 名
- `<object>` 使用 object stem，不带 `.bpf.o`
- `<program>` 使用 program 名的文件系统安全形式

这三类文件都应该由 auto-tuner 生成，人类只在需要 override 时手动编辑。

### 3.3 版本控制友好约束

为了让这些 YAML 真正可维护，应遵守几个约束：

- 一份文件只描述一个 program 的 steady-state 决策
- family 列表使用 canonical 顺序
- 不把二进制 blob 或大段实验原始数据写进 YAML
- 不把易抖动字段放进主文件，例如 wall-clock 时间戳、完整样本表
- 完整实验细节放到 results JSON/Markdown，YAML 只保留摘要和 report 路径

换句话说，policy YAML 应是“小而稳定的决策文件”，不是实验日志。

### 3.4 最小 schema

v2 推荐的最小 schema 如下：

```yaml
version: 1

match:
  layer: corpus
  project: calico
  object: xdp_no_log
  program: calico_xdp_main

selection:
  mode: allowlist
  families: [wide, rotate, endian]

provenance:
  source: auto-tuner
  workload: packet-test-run/default
  objective: exec_ns
  report: corpus/results/policy-tuning/calico/xdp_no_log/calico_xdp_main.json
  note: all-apply regressed; dropping cmov recovered and won
```

如果 stock 最优，则明确写：

```yaml
selection:
  mode: allowlist
  families: []
```

这比“没有文件所以默认 all”安全得多，也比“没有文件所以不知道怎么办”更可审计。

### 3.5 per-site override 不是 v2 主线

v2 仍然保留将来做 per-site override 的空间，但它不应阻塞当前工作。

因此：

- v2 主线只要求 family-level auto-tuning
- scanner `--json` 需要把 site ID 导出来，为 future site refinement 留接口
- 但 steady-state MVP 不需要人工写 site override

## 4. Scanner 改进：从 discoverer 到 policy compiler

### 4.1 当前缺口

现在 scanner 仍然主要是：

- `scan`
- `apply`
- 文本 summary
- 可选输出 blob

这还不够支撑自动 tuning 闭环。

v2 需要 scanner 明确承担 policy compiler 角色。

### 4.2 必须新增的 CLI 能力

#### `scan --json`

scanner 需要 machine-readable site manifest 输出，而不只是文本 summary。

推荐：

```bash
bpf-jit-scanner scan --xlated foo.bpf.o --program-name bar --all --json
```

输出应至少包含：

- program identity
- family summary
- site list
- stable-enough `site_id`
- xlated hash / insn count

#### `scan --config <policy.yaml>`

scanner 需要能读取 policy 后生成 filtered rule set，而不是只能 blind all-apply。

这可以体现在：

- `scan --config <policy.yaml> --output <blob>`
- 或者单独的 `compile-policy` 子命令

#### `compile-policy`

推荐明确增加：

```bash
bpf-jit-scanner compile-policy \
  --xlated foo.bpf.o \
  --program-name bar \
  --config corpus/policies/calico/xdp_no_log/calico_xdp_main.yaml \
  --output /tmp/calico_xdp_main.blob
```

语义很清楚：

- 输入：program + YAML policy
- 输出：filtered v5 blob

#### `apply --config`

对 live program 则应支持：

```bash
bpf-jit-scanner apply --prog-fd 42 --config e2e/policies/tracee/trace_security_file_open.yaml
```

这样 e2e 不需要自己重复做 YAML 解析和 blob staging 逻辑。

### 4.3 推荐的 manifest 结构

`scan --json` 不需要一上来就做得很复杂，但至少应包含：

```json
{
  "program": {
    "name": "calico_xdp_main",
    "insn_cnt": 812,
    "xlated_sha256": "..."
  },
  "summary": {
    "total_sites": 7,
    "cmov_sites": 3,
    "wide_sites": 2,
    "rotate_sites": 0,
    "lea_sites": 0,
    "extract_sites": 0,
    "zero_ext_sites": 0,
    "endian_sites": 2,
    "branch_flip_sites": 0
  },
  "sites": [
    {
      "site_id": "cmov:137:cond-select-64",
      "family": "cmov",
      "start_insn": 137,
      "site_len": 4,
      "pattern": "cond-select-64"
    }
  ]
}
```

设计要求：

- JSON 用 canonical family 名，不暴露 `bflip` 这类文本缩写
- `site_id` 只要求在同一份 xlated form 内稳定
- manifest 是派生数据，不要求被长期提交

### 4.4 scanner library 层也应同步抽象

CLI 之外，scanner 内部最好拆成几块稳定 API：

- `discover_sites_v5(...)`
- `load_policy_config(...)`
- `filter_rules_by_policy(...)`
- `compile_policy_blob_v5(...)`

这样：

- micro/corpus/e2e 不需要各自重复写 policy compiler
- scanner 真正成为统一的 policy backend

## 5. 统一 8-family surface

### 5.1 canonical family set

仓库内所有层应统一到同一套 canonical family 名：

- `cmov`
- `wide`
- `rotate`
- `lea`
- `extract`
- `zero-ext`
- `endian`
- `branch-flip`

文本 summary 可以保留人类友好的缩写，但 machine-readable surface 必须统一。

### 5.2 当前漂移

当前实际情况已经漂移成：

| 层 | 当前 surface |
| --- | --- |
| scanner CLI | 8 family |
| micro_exec auto-scan / `--recompile-all` | 5 family |
| corpus vm batch normalizer | 5 family |
| e2e/common/recompile.py parser | 4 family + total |

而且 corpus 内部还有额外漂移：

- `directive_census.py` 已经是 8 family
- 部分旧 framework / production 汇总路径仍然停在 4 family

### 5.3 v2 的强制要求

在 policy compiler 和 auto-tuner 之前，必须先修 family surface：

- `micro_exec --recompile-all` 覆盖全部 8 family
- `micro_exec --skip-families` 支持全部 8 family
- `micro_exec` JSON `directive_scan` 输出全部 8 family
- `micro/orchestrator/results.py` 的 normalize logic 扩到 8 family
- `corpus` 各 driver 的 `FAMILY_FIELDS` 和 summary 统计扩到 8 family
- `e2e/common/recompile.py` 不再只靠 regex 解析 4 个 family

如果这一步不先做，后面的 auto-tuner 就会面临“搜索空间”和“实际执行面”不一致的问题。

### 5.4 e2e 侧最应该直接切到 JSON

e2e 当前最脆弱的一点是 summary parser 还在抓 scanner 文本输出。

v2 推荐：

- 一旦 scanner 有 `scan --json`
- e2e 就直接消费 JSON manifest
- 不再维护 `cmov/wide/rotate/lea` 这种文本 regex parser

这样 family drift 会少很多。

## 6. 端到端工作流

v2 的端到端 workflow 应清楚到可以直接指导实现：

```text
Discovery
  scanner scan --json -> site manifest
      |
      v
Tuning
  auto-tuner:
    stock
    -> all-apply
    -> per-family ablation
    -> combo search
    -> winner
    -> generate policy YAML
      |
      v
Compilation
  scanner compile-policy --config policy.yaml -> filtered v5 blob
      |
      v
Application
  micro_exec --policy-blob <blob>
  or
  scanner apply --config policy.yaml
      |
      v
Validation
  re-run workload with chosen policy
  verify improvement / no regression
```

### 6.1 Discovery

Discovery 阶段只负责回答两个问题：

- 这个 program 有哪些 family 的 eligible sites
- 每个 family 有多少 sites

它不做 profitability 判断。

### 6.2 Tuning

Tuning 阶段由 auto-tuner 完成：

- 跑 stock
- 跑 all-apply
- 跑 per-family ablation
- 必要时做组合搜索
- 输出最优 family allowlist

### 6.3 Compilation

Compilation 阶段由 scanner 完成：

- 读取 YAML
- 重扫或复用 manifest
- 过滤 discovered rules
- 生成最终 v5 blob

这一步把 YAML 和内核可执行 blob 解耦开。

### 6.4 Application

不同层的 apply 路径不同，但 artifact 一致：

- micro / corpus
  - 推荐走 `micro_exec --policy-blob`
- e2e live programs
  - 推荐走 `scanner apply --config`
  - 或 helper 先 compile 再 apply

### 6.5 Validation

Validation 不是可选项，而是 auto-tuner 的最后一步：

- 用 winner policy 再跑一次
- 确认 improvement 真实存在
- 把结果写入 tuning report

只有验证通过后，才把 YAML 视为该 workload 下的 steady-state policy。

## 7. 更新后的实现优先级与 LOC 估计

以下 LOC 都是粗略代码量估计，不含测试、文档和生成的 YAML 文件。

### 7.1 优先级调整原则

相对 v1，v2 有两个重要优先级变化：

1. 旧设计里的 auto-tuner（原 P5）应前移，因为“程序无关自动 tuning”现在是主设计，不再是附属增强。
2. 旧设计里 micro 先落地的顺序要后移；corpus 仍然是第一个高 ROI 消费层，因为当前最痛的回归就在那里。

### 7.2 新的 P0-P4

| 新优先级 | 主要内容 | 对旧计划的关系 | 粗略 LOC |
| --- | --- | --- | --- |
| P0 | 统一 8-family surface 和结果可观测性 | 旧 P0，范围更明确 | 180-320 |
| P1 | scanner `--json` / `--config` / `compile-policy`，把 scanner 变成 policy compiler | 旧 P1，重要性上升 | 350-600 |
| P2 | 共享 auto-tuner 核心：stock/all/ablation/combo search + YAML emit | 旧 P5 前移为核心阶段 | 350-650 |
| P3 | corpus 接入 generated policy：查找 YAML、编译 blob、结果记录 | 旧 P3，仍是第一个主消费层 | 220-420 |
| P4 | micro 与 e2e 接入同一套 policy artifact | 旧 P2 + 旧 P4 合并到最后一层接线 | 300-540 |

总量级大约：

- 核心代码 `1400-2530 LOC`
- 其中最关键的前 3 阶段约 `880-1570 LOC`

这与当前收益面也一致：先把 surface、compiler、auto-tuner 打通，再把 consumers 一个个接上。

### 7.3 分阶段说明

#### P0：统一 family surface 和 schema

目标：

- 把 scanner / micro / corpus / e2e 全部对齐到 8 family
- 统一 canonical family naming
- 统一 JSON/result schema

预估：

- C++：`micro_exec` family 开关和 summary 扩展
- Python：`normalize_directive_scan`、corpus family fields、e2e parser 更新
- 约 `180-320 LOC`

这是 blocker；不先做，后面 auto-tuner 的搜索和 apply 语义会错位。

#### P1：scanner policy compiler

目标：

- `scan --json`
- `compile-policy`
- `apply --config`
- scanner library policy filter/compiler API

预估：

- CLI 解析和子命令：`120-180 LOC`
- JSON manifest serializer：`80-140 LOC`
- policy config load + rule filter + blob compile glue：`150-280 LOC`
- 合计 `350-600 LOC`

这是整个 v2 的中枢。

#### P2：auto-tuner 核心

目标：

- 共享 search loop
- workload adapter interface
- winner selection
- YAML emit
- tuning report 输出

预估：

- shared tuner core：`220-380 LOC`
- YAML/report emit：`80-140 LOC`
- combo-search / candidate ranking：`50-130 LOC`
- 合计 `350-650 LOC`

这一步做完，系统才真正从“手工写 policy”转向“自动生成 policy”。

#### P3：corpus 先接入

目标：

- 按 `corpus/policies/<project>/<object>/<program>.yaml` 查找 policy
- 缺省走 stock，而不是 blind all
- 调 scanner compiler 生成 blob
- 记录 effective policy source / path / families

预估：

- policy lookup 和 blob plumbing：`120-220 LOC`
- results/report schema：`60-120 LOC`
- CLI fallback / override：`40-80 LOC`
- 合计 `220-420 LOC`

corpus 是第一优先 consumer，因为：

- 当前核心 regressions 在 corpus
- per-program policy 在 corpus 上最有直接回报
- 这里也是最适合主学习 policy DB 的层

#### P4：micro + e2e 接线

目标：

- micro 读取 `micro/policies/<benchmark>.yaml`
- e2e 读取 `e2e/policies/<agent>/<program>.yaml`
- 两者都复用 scanner compiler，不再各自实现 policy 解释器

预估：

- micro：`120-220 LOC`
- e2e：`180-320 LOC`
- 合并约 `300-540 LOC`

把它放在最后，是因为它们都依赖前面的 artifact 形态已经稳定。

### 7.4 延后项

以下能力不应阻塞 v2 主线：

- per-site auto-tuning
- site-level override 编辑体验
- 更复杂的 profitability model

这些可以放到后续阶段。

## 8. 推荐的最小可行落地方案

如果目标是尽快把“程序无关自动 tuning”做成可用系统，而不是继续停在设计上，最小可行方案应是：

1. 先统一 8-family surface
2. scanner 增加 `scan --json` 和 `compile-policy --config`
3. 实现共享 auto-tuner，只做 family-level search
4. 先把 corpus 接上 generated policy
5. generated YAML 一律写 allowlist
6. 缺 policy 默认 stock

这样就能形成闭环：

- discovery 自动
- tuning 自动
- policy 持久化自动
- steady-state apply 不再 blind all-apply

这才是“program-agnostic policy tuning”的正确落点。

## 9. 最终结论

v2 的关键不是继续增强 `--skip-families`，也不是让人手工维护越来越多的 per-program YAML。

真正该做的是：

- 把 scanner 保持为程序无关的 site discoverer，并升级为 policy compiler
- 把 profitability 判断也做成程序无关的 auto-tuner
- 把 per-program YAML 明确定义为 auto-tuner 输出，而不是人工输入

最终 steady-state 形态应该是：

- `scanner scan --json` 自动发现 sites
- `auto-tuner` 自动搜索最优 family 组合
- `scanner compile-policy --config` 自动生成 blob
- `micro/corpus/e2e` 自动消费 YAML/blob

这样 policy 系统才真正摆脱“知道具体程序的人手工写策略”这一前提。
