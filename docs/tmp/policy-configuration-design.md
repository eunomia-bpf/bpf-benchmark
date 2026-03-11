# Policy Configuration Design

## 背景与结论

当前 corpus full recompile geomean 是 `0.868x`，核心原因不是 scanner “找不到 site”，而是“策略层没有 program-level control”。现在大多数 recompile 路径都是“对某个程序把启用 family 的所有匹配 site 全 apply”，而 family 的开关又往往是一次运行级别的全局 CLI 参数，不是附着在具体 BPF 程序上的持久配置。

这意味着：

- `cmov` 这类明显 policy-sensitive 的 family 会在不适合的程序上被盲目打开。
- micro、corpus、e2e 三层没有统一的 policy 数据模型。
- `scanner CLI`、`micro_exec`、`e2e/common/recompile.py` 对 family 的支持范围和可观测性已经开始漂移。

本文结论很直接：短期 MVP 应先做“per-program family allow/deny”，先把 `cmov` 从不适合的程序上拿掉；per-site override 保留为第二阶段能力。

## 1. 现状分析

### 1.1 Scanner 当前 policy 机制

`scanner` 的 v5 CLI 只提供两种策略入口：

- `scan`: 扫描 post-verifier xlated BPF，打印 summary，可选输出 blob。
- `apply`: 扫描当前程序，再把生成的 blob 直接喂给 `BPF_PROG_JIT_RECOMPILE`。

当前 family 选择机制：

- `scanner/src/cli.cpp` 中 `--cmov`、`--wide-mem`、`--rotate`、`--lea`、`--extract`、`--zero-ext`、`--endian`、`--branch-flip` 是正向启用开关。
- 如果没有显式 family 选择，`parse_args()` 会走 `enable_all_families()`，默认启用全部内建 family。
- `scanner CLI` 本身没有 `--skip-families`。`--skip-families` 是 `micro_exec`/corpus 层的参数，不是 scanner CLI 的语义。

当前 site 选择机制：

- `scan_v5_builtin()` 会在整个 xlated 指令流上顺序扫描。
- 对启用的 family，凡是 pattern match 成功的 site，都会生成一条 `V5PolicyRule`。
- 这是“eligibility-based all apply”，不是“profitability-based selective apply”。
- 没有内建成本模型，没有 per-program DB，没有 per-site policy DB。
- `apply` 子命令只是把扫描结果原样打成 blob 并一次性 apply，不会做 program-specific pruning。

当前粒度：

- family 级别：有。
- site 级别：内核 blob 格式本身支持 rule-by-rule 选择，但 scanner CLI 没有暴露“只选某些 site”的配置接口。
- program 级别：没有外部 policy 文件或 DB；只是对当前 `prog_fd` 或 `--xlated` 输入现场生成 blob。

一个重要细节：

- `scanner CLI` 已经支持 8 个 family。
- 但下游消费方并没有全部跟上，这导致“scanner 能扫到”和“实际 recompile 会用到”不是同一件事。

### 1.2 Micro benchmark 的 policy 配置

#### 当前 `run_micro.py` / suite YAML

活跃 micro 路径里，`micro/run_micro.py` 只是 wrapper，真正的 suite orchestration 在 `micro/_driver_impl_run_micro.py`。

当前 active micro suite 没有 policy 配置能力：

- `micro/benchmark_catalog.py` 的 `BenchmarkSpec` 只有 `io_mode`、`kernel_input_size`、`input_generator`、`tags`、`expected_result` 等字段，没有 `policy` 或 `policy_file`。
- `config/micro_pure_jit.yaml` 只定义了 stock `llvmbpf` / `kernel` runtime，也没有 benchmark-level policy 字段。
- `micro/orchestrator/commands.py` 的 `build_micro_benchmark_command()` 在 normal suite path 只传 `program`、`io_mode`、`repeat`、`memory`、`input_size` 等参数；不会传 `--policy-blob`、`--recompile-*`、`--skip-families`。

结论：

- active micro suite 默认根本不做 recompile。
- 更不存在 per-benchmark policy。

#### 当前 `micro_exec run-kernel` 的 recompile 流程

`micro_exec` 自己其实有 recompile 能力，但它是 runner-level CLI，不是 suite manifest-level config。

它支持两种模式：

- auto-scan recompile：`--recompile-v5` + `--recompile-*` / `--recompile-all`
- explicit blob：`--policy-blob <file>`

流程如下：

1. 正常 `bpf_object__load()` 或 manual load，拿到 `program_fd`
2. 根据 `--recompile-*` 和 `--skip-families` 计算要启用的 family
3. 如果是 auto-scan：
   - 从 live program 读取 xlated
   - 直接调用链接进来的 `bpf_jit_scanner::scan_v5_builtin(...)`
   - 生成 summary 和 v5 blob
4. 如果是 `--policy-blob`：
   - 从磁盘读 blob
   - 用 live program 的 `xlated_insn_cnt` 和 `prog_tag` patch header
5. 把最终 policy bytes 写入 sealed memfd
6. 调 `BPF_PROG_JIT_RECOMPILE`
7. 失败是 non-fatal，runner 继续用 stock image 跑

这说明：

- `micro_exec` 已经有“显式 policy blob”这个很好的底层挂点。
- 但上层 `run_micro.py` 和 YAML 没把它变成 benchmark-level 数据模型。

#### `--skip-families` 在 micro 里是什么

`--skip-families` 是 `micro_exec run-kernel` 的参数，作用是：

- 仅对 auto-scan recompile 生效。
- 仅是这次 `micro_exec` 进程的一次运行级过滤。
- 不能与 `--policy-blob` 同时使用。

更关键的是，`micro_exec` 目前只把 5 个 family 接进了 auto-scan 路径：

- `cmov`
- `wide`
- `rotate`
- `lea`
- `extract`

它还没有把 scanner v5 的 `zero-ext`、`endian`、`branch-flip` 接入自己的 `--recompile-all` / `--skip-families` 语义。

这意味着：

- micro runner 和 scanner CLI 的 family surface 已经不一致。
- 基于 `micro_exec --recompile-all` 的实验，实际上不是 scanner 全家桶的“all”。

#### 额外说明

仓库里确实有少量 ad-hoc policy 脚本，例如 `micro/archive/scripts/demo_policy_iteration.py` 会硬编码某些 case 用 `--recompile-cmov` 或 `--recompile-all`。但这不是 active micro suite 的 manifest-driven policy 系统，不能替代 benchmark-level 配置机制。

### 1.3 Corpus recompile 的 policy 配置

#### `run_corpus_v5_vm_batch.py` 当前如何调用 scanner / runner

`corpus/run_corpus_v5_vm_batch.py` 只是 wrapper，真正逻辑在 `_driver_impl_run_corpus_v5_vm_batch.py`。

这个 batch flow 里有两条不同路径：

- scanner CLI：只用于 baseline compile 之后的 offline census / metadata
- 实际 recompile：通过 `micro_exec run-kernel`

当前 baseline/offline scan 流程：

1. 先跑 baseline `micro_exec run-kernel --compile-only --dump-xlated <tmp>`
2. 再跑 `bpf-jit-scanner scan --xlated <tmp> --all --v5`
3. 如果 scanner CLI 失败，再退回用 runner 的 `directive_scan` summary

当前真正 recompile 流程：

- 对每个 target program 单独跑一次 `micro_exec run-kernel`
- 传 `--recompile-v5 --recompile-all`
- 如果用户在 batch 命令行上给了 `--skip-families`，就把同一组 family 传给每个 target
- 不传 `--policy-blob`
- 不传单独的 per-program policy file

结论：

- policy blob 是 per-program 现场生成的，但“策略来源”不是 per-program config，而是“统一的 auto-scan-all，再减去一组全局 skip families”。
- batch 层没有 per-program override。

#### `--skip-families` 在 corpus 里是什么

`_driver_impl_run_corpus_v5_vm_batch.py` 暴露了 `--skip-families`，但它的语义是：

- 一次 batch 运行的全局参数
- 对所有选中的 corpus program 都一样
- 仍然只支持 `cmov/wide/rotate/lea/extract`

所以答案很明确：

- 它不是 per-program policy。
- 它甚至不是 scanner CLI 的参数，而是 corpus driver 传给 `micro_exec` 的一次运行级全局过滤。

#### 其他 corpus 脚本

`_driver_impl_run_corpus_v5_framework.py`、`_driver_impl_run_production_corpus_v5_framework.py`、`_driver_impl_run_macro_corpus.py` 等相关 v5 路径，本质上也都是：

- baseline：stock kernel
- recompile：`--recompile-v5 --recompile-all`

差别只在 workload / target selection / output schema，不在 policy 模型。

`macro_corpus.yaml` 里虽然定义了 `kernel_recompile_v5` runtime，但它只是一个 runtime mode，不是 program-attached policy object。

#### Host fallback 模式

在 host fallback 下，batch driver 会禁用 recompile，只做 baseline compile + offline scanner scan。所以 host fallback 甚至不会产生 policy，只会产生“candidate site census”。

### 1.4 E2E 的 policy 配置

当前活跃 e2e 入口是 `e2e/run.py` 调 case module，不是老的单体脚本。

#### 共性：e2e/common/recompile.py

Tracee / Tetragon / bpftrace 共享的 recompile helper 很简单：

- 先根据 `prog_id` 或 caller 提供的 `prog_fds` 获取 FD
- 调 `scanner scan/apply --prog-fd <fd> --all --v5 --program-name <name>`
- 不传 policy blob
- 不传 policy config
- 不支持 per-program family override

这里还有两个当前缺陷：

- helper 的 `_scanner_counts()` 只解析 `total/cmov/wide/rotate/lea`，没有解析 `extract/zero-ext/endian/branch-flip`
- 也就是说，e2e 的 family 可观测性落后于 scanner CLI 的真实能力

#### Tracee

Tracee daemon mode：

- 启动 Tracee 进程
- 找出“相对于 preexisting programs 新加载的、由 Tracee PID 拥有的 BPF programs”
- 把这些 `prog_ids` 全部交给 `scan_programs()` 和 `apply_recompile()`
- 没有 site-based filtering
- 没有 per-program policy file

Tracee manual fallback：

- 从 `tracee.bpf.o` inventory 中选一组固定的 manual targets
- 加载这些固定程序
- 对加载出的所有 handle 全部 scan/apply

结论：

- Tracee 当前是“按 agent-owned program set 全 apply”
- 没有 per-agent policy config
- 也没有 per-program family override

#### Tetragon

Tetragon daemon mode：

- 临时写两份 `TracingPolicy` YAML 来决定 Tetragon 应该 attach 哪些 probe
- 启动 Tetragon
- 收集 session 里加载出的所有新 program
- 对这些 program 全部 `scan` / `apply`

Tetragon manual/direct mode：

- 用固定的 manual target set
- 仍然对这些目标全 apply

结论：

- Tetragon 的 YAML 只是在决定“哪些 probe 会被 agent 加载”
- 不是 BpfReJIT policy
- ReJIT policy 依然是 `scanner apply --all --v5`

#### bpftrace

bpftrace 是三者里唯一有“先筛 eligible program 再 recompile”的 case：

- 启动某个 `.bt` script
- 找到该进程 attach 的 programs
- 先 scan 全部
- 只对 `total_sites > 0` 的那部分程序做 `apply`

但它仍然没有真正的 per-program policy：

- 只是“有没有 site”的过滤
- 一旦进入 apply，仍然是 `--all --v5`

#### 总结

e2e 当前的 policy 配置能力基本等于：

- 选择哪些 agent / 哪些脚本 / 哪些 probes 会加载 BPF 程序
- 对选中的 live programs 做 `scanner apply --all --v5`

这不是 program-attached policy config，更不是 workload-specific tuning 结果。

## 2. 当前方案的问题

### 2.1 策略是“命令行状态”，不是“程序数据”

现在的 recompile policy 多数是以下三种之一：

- scanner CLI 默认 `--all`
- runner `--recompile-all`
- 一次 batch 运行级 `--skip-families`

这三者都没有把策略附着到具体 BPF 程序上。跑完实验之后，“为什么这个程序跳过了 cmov”不会沉淀为可复用 artifact。

### 2.2 粒度不对

我们需要的是：

- program A 禁用 `cmov`
- program B 保留 `cmov` 但禁用 `rotate`
- program C 只开 `wide + endian`

现在能做的是：

- 这次整批 run 统一 `--skip-families cmov`

这显然不足以解决 corpus geomean 被少数 family 拖垮的问题。

### 2.3 各层 family surface 已经漂移

当前至少有三种 family surface：

| 层 | 当前能力 |
| --- | --- |
| scanner CLI | 8 family |
| micro_exec auto-scan / corpus recompile | 5 family |
| e2e/common/recompile.py summary parser | 4 family + total |

这会带来两个直接后果：

- 你以为“all”是一致的，其实不是。
- 你以为结果里看不到某 family 是“没有 site”，实际上可能只是“runner/summary 根本没接这个 family”。

### 2.4 scanner CLI 和 runner 路径分叉

`scanner apply --all` 与 `micro_exec --recompile-all` 不是同一条实现路径：

- scanner CLI 直接走 scanner library 的全 family 语义
- micro_exec 只走它自己接出来的子集

这意味着：

- corpus 结果和 e2e 结果所代表的“policy all-apply”并不完全一致
- 设计新 policy 系统时必须先把 family/metadata surface 统一

### 2.5 缺少 machine-readable site manifest

当前 scanner CLI 只打印人类可读 summary，Python 脚本靠 regex 抓计数。

缺失的能力：

- site 列表导出
- site 稳定 ID
- family / pattern kind / start insn 的机器可读输出

没有这些，就很难做 per-site override，也很难做自动 tuning 后的 artifact 持久化。

### 2.6 缺少自动 tuning 回写闭环

现在最多只能做：

- 手工发现 `cmov` 回归
- 再手工加全局 `--skip-families cmov`

缺少的是：

- 识别哪个 program 发生回归
- 只给这个 program 生成 denylist / allowlist
- 把结果写回 policy 文件
- 下次自动复用

## 3. 目标设计

## 3.1 设计原则

1. policy 是数据，不是 CLI 状态
2. program-level family allow/deny 是 MVP
3. per-site override 是可选增强，不阻塞 MVP
4. scanner 负责“discover sites + compile policy blob”，runner 继续负责“load + apply”
5. 所有层都落到同一种 policy schema
6. 所有结果都记录 effective policy source 和 effective families

## 3.2 统一 policy schema

建议把“人类编辑的 policy spec”和“最终给内核的 v5 blob”分开：

- 人类编辑的 spec：YAML 或 JSON
- 机器执行的 artifact：v5 policy blob

推荐 schema：

```yaml
version: 1

match:
  object: corpus/build/calico/xdp_no_log.bpf.o
  program: calico_xdp_main

selection:
  mode: denylist        # denylist | allowlist
  families: [cmov]      # denylist: 全部减去这些；allowlist: 只保留这些

site_overrides:
  - site_id: rotate:482:pattern-rot64
    action: enable      # enable | disable
    note: keep this rotate site even when family default changes

expectation:
  note: cmov regressed in corpus v6 VM batch; keep wide/rotate/lea
  expected_effect: improve exec geomean vs all-apply
  evidence:
    benchmark: corpus_v6_vm_batch
    measured_at: 2026-03-11

metadata:
  owner: corpus
  tuned_by: auto
```

字段含义：

- `match`: 这份 policy 绑定到哪个 BPF 程序
- `selection.mode`:
  - `denylist`: 保持当前“默认全开”的迁移兼容语义
  - `allowlist`: 更安全，适合 tuned program 的最终形式
- `selection.families`: family 级主开关
- `site_overrides`: 可选；只在需要时使用
- `expectation`: 用户解释、实验注释、预期效果

### site_id 设计

per-site override 不建议在 MVP 强推，但如果要做，建议 site_id 由 scanner 导出，至少包含：

- family
- site_start / start_insn
- pattern kind / pattern signature

例如：

- `cmov:137:cond-select-64`
- `rotate:482:pattern-rot64`

注意：

- site_id 本质上是“针对当前 xlated form 的 ID”
- 它天然比 family mask 更脆弱
- 所以 per-site override 应该是 phase 2 能力，不应阻塞 per-program family policy MVP

## 3.3 推荐控制流

推荐把 policy 解析和 blob 生成集中在 scanner 层，runner 不解析 YAML。

控制流如下：

1. scanner 对某个程序导出 machine-readable site manifest
2. scanner 读取 YAML/JSON policy spec
3. scanner 按 family mask + site override 过滤 discovered rules
4. scanner 生成最终 v5 blob
5. consumer 使用 blob：
   - micro / corpus：传给 `micro_exec --policy-blob`
   - e2e live prog：scanner 直接 `apply --config`，或 helper 先 compile 再 apply

这样做的好处：

- 不把 YAML parser 和 policy compiler 重复塞进 micro/corpus/e2e 各层
- `micro_exec` 继续只做 apply，不变成配置解释器
- blob patching 逻辑仍然复用 runner 现有 `prog_tag` / `insn_cnt` patch 流程

## 3.4 各层如何落地

### Micro

目标：

- 每个 benchmark YAML 条目可带 `policy` 或 `policy_file`

建议形式：

```yaml
- name: log2_fold
  base_name: log2_fold
  io_mode: staged
  kernel_input_size: 1032
  input_generator: log2_fold
  expected_result: 9
  policy:
    mode: denylist
    families: [cmov]
    note: predictable branches; cmov regressed in prior runs
```

或者：

```yaml
- name: log2_fold
  policy_file: micro/policies/log2_fold.yaml
```

运行时语义：

- stock runtime 不变
- recompile runtime 读取 benchmark policy
- 若 benchmark 没有 policy：
  - 过渡期可支持 fallback to `all`
  - 最终建议切到 `stock unless explicit policy`

### Corpus

目标：

- 支持 per-program 或 per-object policy file

建议：

- 对单程序对象：`corpus/policies/<repo>/<object>/<program>.yaml`
- 对多程序对象：允许一个 object-level file 带 `defaults + programs[]`

例子：

```yaml
version: 1
defaults:
  selection:
    mode: denylist
    families: [cmov]

programs:
  - match:
      program: calico_xdp_main
    selection:
      mode: allowlist
      families: [wide, rotate, lea, endian]
    expectation:
      note: xdp fast path profits from memory/address families
```

为什么 corpus 更适合 object-level file：

- 很多对象会包含多个 section / program
- 同一对象里的程序通常来自同一个 repo / workload 语境
- object-level default 可以减少重复配置

### E2E

目标：

- 每个 agent 有自己的 policy config
- 能按 live program metadata 匹配具体 program

建议文件：

- `e2e/cases/tracee/policy.yaml`
- `e2e/cases/tetragon/policy.yaml`
- `e2e/cases/bpftrace/policy.yaml`

建议 matcher：

- `program_name`
- `program_name_regex`
- `prog_type`
- `section_name`
- `agent_mode`（daemon / manual_fallback）

例子：

```yaml
version: 1
agent: tracee

defaults:
  selection:
    mode: denylist
    families: [cmov]

programs:
  - match:
      program_name: trace_security_file_open
    selection:
      mode: allowlist
      families: [wide, lea]
    expectation:
      note: file-open path is memory-heavy; keep cmov disabled
```

这样做的意义：

- e2e 不再只是“把 agent-owned programs 全 apply”
- 可以针对不同 agent 的热点路径保留不同 family set

## 3.5 策略优先级和 override 规则

建议统一优先级：

1. site override
2. program-specific policy
3. object-level default
4. suite / agent default
5. CLI emergency override

CLI override 仍然保留，但角色改变：

- 只作为 experiment/debug override
- 不再是主要的持久化 policy 机制

建议保留一个全局 emergency 入口，例如：

- `--policy-override-skip-families`
- `--policy-override-allow-families`

而不是继续让 `--skip-families` 承担主要策略表达。

## 3.6 结果输出与可观测性

每层结果 JSON 都建议补齐以下字段：

- `policy_source`
  - `implicit_all`
  - `policy_file`
  - `inline_policy`
  - `generated_by_auto_tuner`
- `policy_path`
- `policy_hash`
- `policy_mode`
- `requested_families`
- `eligible_families`
- `effective_families`
- `disabled_by_policy`
- `site_override_count`

另外，scanner 应该新增 machine-readable 输出：

- `scan --json` 或 `scan --output-json`
- 导出 site manifest，而不是只打印文本 summary

这会直接消灭当前 corpus/e2e 里一堆 fragile regex parser。

## 4. 自动 policy tuning 思路

## 4.1 MVP：先解决 family-level regressions

结合当前问题，第一阶段不需要一上来就做 site-level search。

足够有效的 MVP：

1. 先跑一次 stock
2. 再跑一次 full-apply
3. 找出 regression programs
4. 只对 regression programs 做 family ablation
5. 选出最优 family set
6. 自动写回 per-program policy file

这已经足以解决“CMOV 让一部分程序回归”这类问题。

## 4.2 推荐搜索流程

### Phase A：site census

对每个程序先拿到 scanner site manifest，记录：

- 有哪些 family 实际存在
- 各 family site 数量

这样可以立刻缩小搜索空间。没有 site 的 family 根本不用试。

### Phase B：full-apply screening

对每个程序跑：

- stock
- all families

如果 `all` 已经赢，就先生成一个简单 policy：

- `mode: allowlist`
- `families: <该程序实际出现的 families>`

如果 `all` 回归，就进入下一阶段。

### Phase C：leave-one-family-out / one-family-on

对 regression program，先跑低成本搜索：

- `all - cmov`
- `all - wide`
- `all - rotate`
- `all - lea`
- `all - extract`
- 对未来 family 再扩到 `endian/branch-flip/zero-ext`

也可以同时跑：

- `only cmov`
- `only wide`
- `only rotate`
- ...

这能快速判断：

- 哪个 family 是主要回归源
- 哪个 family 单独最赚钱

### Phase D：组合搜索

如果 family 间交互明显，再做组合搜索。

建议只在“该程序实际有 site 的 family 子集”上做组合枚举：

- 若实际出现的 family 数 `k <= 4`，可直接穷举 `2^k`
- 若 `k > 4`，先用 greedy / beam search，再只在 top candidates 上精搜

选择指标建议：

- 主目标：`exec_ns` 或 speedup ratio
- 约束：
  - compile time 不显著恶化
  - code size 不超过阈值
  - 多次重复下结果稳定

### Phase E：可选 site-level refinement

只有在 family-level 最优仍然不理想时，再对某个回归 family 开 site-level refinement。

建议顺序：

1. 先锁定 family set
2. 只在“问题 family 的 site 子集”里做 disable search
3. 每次只改少数 site，避免组合爆炸

这一步适合：

- `cmov` family 内部只有少数 site 真正拖后腿
- 其余 `cmov` site 其实有收益

## 4.3 自动生成 policy 文件

自动 tuner 跑完之后，直接输出 policy file，而不是只输出实验表格。

建议输出内容：

- 选中的 `mode + families`
- 可选的 `site_overrides`
- `expectation.note`
- 产生该策略的 benchmark 数据摘要

例如：

```yaml
version: 1
match:
  object: corpus/build/tracee/tracee.bpf.o
  program: trace_security_file_open
selection:
  mode: denylist
  families: [cmov]
expectation:
  note: auto-tuned from corpus vm batch; all-apply regressed, all-cmov recovered
  evidence:
    stock_vs_all: 0.91x
    stock_vs_all_minus_cmov: 1.06x
metadata:
  tuned_by: corpus-auto-tuner
  tuned_at: 2026-03-11T...
```

## 4.4 三层 tuning 的建议策略

### Micro

最便宜，适合 exhaustive tuning：

- benchmark 少
- 输入可控
- 噪音低

适合作为：

- family profitability 基准库
- site-level search 试验场

### Corpus

最适合生成 per-program policy DB：

- 程序量大
- workload 接近真实对象
- 但每个程序仍能独立测

建议把 corpus 作为主要 policy learning 层。

### E2E

最贵，不适合大规模组合搜索。

建议：

- 优先复用 corpus/micro 已调好的 per-program policy
- E2E 只做 validation 和 agent-level aggregation
- 只在少数关键 agent program 上做额外手调

## 5. 实现路径

## 5.1 P0：先统一 family surface 和可观测性

这是最优先的，因为不统一 surface，后面的 policy 文件会和执行语义对不上。

需要修改的地方：

- `micro/runner/src/common.cpp`
  - 把 CLI family surface 扩到和 scanner 一致
  - `--skip-families` 至少补齐 `zero-ext/endian/branch-flip`
- `micro/runner/src/kernel_runner.cpp`
  - `--recompile-all` 的 auto-scan 路径补齐 scanner v5 family
  - `directive_scan_summary` / `recompile_summary` 补齐新 family
- `micro/runner/include/micro_exec.hpp`
  - summary struct 扩字段
- `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
  - `FAMILY_FIELDS` / skip family normalization 跟进统一 family set
- `e2e/common/recompile.py`
  - `_scanner_counts()` 解析所有 family，或者直接消费 scanner JSON 输出

优先级理由：

- 这是语义统一问题
- 不解决，后续 policy 文件里的 family 名都没有可靠执行面

## 5.2 P1：给 scanner 增加 machine-readable policy/compiler 接口

建议把这一步放在 scanner 层，而不是散落到每个 Python driver。

建议新增能力：

- `scan --json`：输出 site manifest
- `compile-policy --xlated/--prog-fd --config <policy.{json,yaml}> --output <blob>`
- `apply --config <policy.{json,yaml}>`

或者等价的 library API：

- `discover_sites_v5(...)`
- `filter_rules_by_policy(...)`
- `compile_policy_blob_v5(...)`

需要改的地方：

- `scanner/src/cli.cpp`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp`
- 新增 `scanner/include/.../policy_config.hpp`
- 新增 `scanner/src/policy_config.cpp`

关键目标：

- 让 scanner 不只是“all-apply front end”
- 变成“policy spec -> blob”的统一 compiler

## 5.3 P2：把 Micro 接到 manifest-driven policy

建议改动：

- `micro/benchmark_catalog.py`
  - `BenchmarkSpec` 加 `policy` / `policy_file`
- `config/micro_pure_jit.yaml`
  - 支持 benchmark-level policy 字段
- `micro/_driver_impl_run_micro.py`
  - 在 kernel recompile runtime 下解析 benchmark policy
  - 通过 scanner compiler 生成 blob
  - 调 `micro_exec --policy-blob`
- `micro/orchestrator/commands.py`
  - `build_micro_benchmark_command()` 增加 `policy_blob`

推荐策略：

- stock runtime 保持不变
- 增加显式 `kernel_recompile_policy` runtime
- 不要隐式把现有 `kernel` runtime 变成带 policy 的路径

## 5.4 P3：把 Corpus 接到 per-program / per-object policy file

建议改动：

- `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
  - 新增 `policy_root` / `policy_mode`
  - 根据 `object_path + program_name` 解析 policy file
  - 若命中 policy，则走 `--policy-blob`
  - 若未命中 policy，则可配置 fallback：
    - `stock`
    - `all`
    - `all-minus-global-skip`
- `corpus/_driver_impl_run_corpus_v5_framework.py`
- `corpus/_driver_impl_run_production_corpus_v5_framework.py`
- `corpus/_driver_impl_run_macro_corpus.py`
- 可选新增 `corpus/policies/`

建议兼容策略：

- 过渡期保留 `--skip-families`，但仅作为 emergency/global override
- 正常路径以 per-program policy file 为主

## 5.5 P4：把 E2E 接到 per-agent policy config

建议改动：

- `e2e/common/recompile.py`
  - 根据 live program metadata 做 policy match
  - 不再直接硬编码 `scanner apply --all`
- `e2e/run.py`
  - 暴露 `--policy-config` 或默认 case-local policy path
- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/bpftrace/case.py`
- 新增：
  - `e2e/cases/tracee/policy.yaml`
  - `e2e/cases/tetragon/policy.yaml`
  - `e2e/cases/bpftrace/policy.yaml`

建议行为：

- Tracee / Tetragon 不再对所有 selected programs 无差别 all-apply
- 先 scan，拿到 live metadata
- 再按 agent policy config 做 per-program family 选择

## 5.6 P5：自动 tuner

建议最后做，因为它依赖前面的 policy artifact 和 machine-readable outputs。

建议新增：

- `micro/tune_policy.py` 或 `tools/tune_policy.py`
- `corpus/tune_policy.py`
- 可选 `e2e/tune_policy.py`

自动 tuner 的职责：

- 跑 family search
- 选最优组合
- 生成 policy file
- 输出 tuning report

## 6. 推荐优先级

推荐顺序：

1. 统一 family surface 和 JSON/site manifest 输出
2. scanner policy compiler
3. corpus per-program family policy
4. micro benchmark YAML policy
5. e2e per-agent policy
6. site-level override
7. auto tuner

原因：

- 当前最痛的问题在 corpus geomean，被 `cmov` 这类 family 拖垮
- 解决它只需要“per-program family policy + 可执行 artifact”
- 不必等到 per-site override 和 auto tuner 全部完成

## 7. 最小可行方案（建议）

如果只追求尽快把 `0.868x` 拉回来，建议最小落地方案是：

1. 先把 `micro_exec` family surface 补齐到和 scanner 一致
2. scanner 增加 machine-readable site manifest + policy compiler
3. corpus 增加 per-program policy file
4. 先只支持：
   - `mode: allowlist|denylist`
   - `families: [...]`
   - `note`
5. 暂时不做 per-site override
6. 先做简单 auto tuning：
   - stock
   - all
   - all minus each family
   - 生成 denylist/allowlist

这个 MVP 已经足以回答当前核心问题：

- 哪些程序该关 `cmov`
- 哪些程序可以继续保留 `cmov`
- 如何把这些结果变成可复用的 policy artifact，而不是一次运行的 CLI 状态

## 8. 最终建议

最终建议不是继续增强 `--skip-families`，而是把它降级成 debug override，并把主策略迁移到“program-attached policy file”。

一句话总结：

- scanner 负责发现 site 并把 policy spec 编译成 blob
- micro/corpus/e2e 负责给每个 program 选中正确的 policy spec
- auto tuner 负责把实验结果沉淀成这些 spec

这样 recompile 才会从“blind all-apply”变成“per-program selective apply”。
