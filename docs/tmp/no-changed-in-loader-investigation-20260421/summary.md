# 2026-04-21/22 corpus 调研：`no_programs_changed_in_loader` 与 program 发现数

调研范围：

- Plan doc header 与 `#663`: `docs/kernel-jit-optimization-plan.md:23-25`, `docs/kernel-jit-optimization-plan.md:1039-1040`
- 三个权威 session:
  - `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.md:15-40`
  - `corpus/results/aws_x86_corpus_20260422_012001_472335/result.md:15-40`
  - `corpus/results/aws_arm64_corpus_20260422_044304_037607/result.md:15-40`
- 宏 app 清单: `corpus/config/macro_apps.yaml:1-120`
- corpus / runner / daemon / e2e 代码路径（本文内逐项引用）

先给总结：

- `no_programs_changed_in_loader: 36` 不是“loader 只比 `bytes_jited/xlated`，same-size 改写被误判”的代码事实。当前 corpus 根本不是按字节长度判这个 reason。
- 当前代码里，这个 reason 的真实含义是：`apply` 这条路径最后没有拿到“最终 surviving 的 program change”。它把“0 site 命中”和“中间改了但 verifier 全回滚”都混在一个桶里。
- “20 个 app 只有 ~48 个 program”整体上符合现在的 app-centric 设计，不再是旧 object-centric 的“469 objects / 2019 programs”口径；但个别 runner 的发现逻辑确实有漏口。最明显的是 Tracee；Tetragon 也有 corpus/e2e 口径不一致的问题；Katran 的 1 个则是有意设计。

## 问题 1：`no_programs_changed_in_loader: 36` 是什么？是 bug 吗？

### 1. 判定逻辑在哪里

直接判这个 exclusion reason 的代码在 `corpus/driver.py`：

- `_apply_record_changed()`: `corpus/driver.py:471-496`
- `_rejit_result_has_any_change()`: `corpus/driver.py:499-508`
- `_comparison_exclusion_reason()`: `corpus/driver.py:511-540`
- `changed/comparable` 写入 per-program row: `corpus/driver.py:553-586`

关键分支：

- `corpus/driver.py:524-527`
  - 如果 `_apply_record_changed(apply_record)` 为假，则直接记 `no_programs_changed_in_loader`
- `corpus/driver.py:528-533`
  - 如果没有 post-REJIT measurement，且 `any_changed` 也是假，也同样记 `no_programs_changed_in_loader`
- `corpus/driver.py:570-576`
  - `comparable` 的条件是 `changed == True` 且 baseline / rejit 的 `exec_ns` 都有效；这里没有任何 `bytes_jited/xlated` 比较

### 2. 它到底比较了什么，不比较什么

`_apply_record_changed()` 看的字段只有 daemon/apply 侧的“语义变化信号”，不是 loader bytes：

- `counts.applied_sites > 0`: `corpus/driver.py:474-476`
- `summary.program_changed == true`: `corpus/driver.py:477-482`
- `summary.total_sites_applied > 0`: `corpus/driver.py:477-482`
- `debug_result.changed == true`: `corpus/driver.py:483-486`
- `debug_result.summary.program_changed / total_sites_applied`: `corpus/driver.py:487-492`
- `debug_result.passes_applied` 非空: `corpus/driver.py:493-495`

daemon summary 的来源：

- `OptimizeSummary` 字段定义：`daemon/src/commands.rs:104-113`
- summary 组装：`daemon/src/commands.rs:523-530`
- pipeline 聚合 `total_sites_applied` / `program_changed`: `daemon/src/pass.rs:697-705`, `daemon/src/pass.rs:789-862`
- runner 侧把 daemon response 归一化为 corpus apply record：`runner/libs/rejit.py:586-643`

明确排除：

- 不比较 JIT image content hash
- 不比较 `bytes_jited`
- 不比较 `bytes_xlated`
- 不比较 instruction count

`runner/libs/bpf_stats.py:29-41` 只是把 `bytes_jited` / `bytes_xlated` 作为统计字段采回来；这些字段没有参与 exclusion reason 判定。

### 3. `same-size` 改写会不会被误判成“没变化”

不会，至少不是当前 `no_programs_changed_in_loader` 的判定原因。

反例已经在权威结果里出现：

- `scx/rusty:rusty_exit_task` 在 `aws_arm64` session 里是 `changed=true`、`comparable=true`
- 但它 baseline/rejit 的 `bytes_jited` 都是 `232`、`bytes_xlated` 都是 `2792`
- 见 `corpus/results/aws_arm64_corpus_20260422_044304_037607/result.json:20040-20076`

这说明：

- current corpus 并不会因为 “same-size” 就把 program 打成 `no_programs_changed_in_loader`
- 所以 plan doc header / `#663` 里“same-size 改写、loader 只比字节长度不比内容”的解释，与当前代码不一致：`docs/kernel-jit-optimization-plan.md:25`, `docs/kernel-jit-optimization-plan.md:1040`

### 4. 对四个候选原因逐项判断

#### 候选 1：同字节长度改写，daemon rewrote 了，但 JIT 长度没变

排除为当前 36 的主因。

理由：

- exclusion reason 不看 `bytes_jited/xlated`，只看 `_apply_record_changed()`：`corpus/driver.py:471-540`
- `same-size + changed=true` 的正例已存在：`aws_arm64/result.json:20040-20076`

结论：

- 这不是当前 36 的代码路径解释。

#### 候选 2：daemon `applied=true`，但某个 program 实际 0 site 命中

确认成立，而且是当前 36 的一部分。

关键点：

- daemon 在“最终 program 没变”时依然会返回 `applied=true`
- `daemon/src/commands.rs:737-767` 明确写了：如果 `!pipeline_result.program_changed`，就返回 `"ok"`, `applied=true`, `changed=false`，并跳过 final REJIT
- runner 侧把 `summary.applied` 接成 per-program `applied`：`runner/libs/rejit.py:597-643`

所以：

- `applied=true` 只表示 optimize/apply 请求成功走通
- 不等于“最终 bytecode 真的变了”

这一类的直接样本：

- `tetragon/default:event_execve` 当前 summary 是
  - `applied=true`
  - `passes_changed=0`
  - `program_changed=false`
  - `total_sites_applied=0`
  - `verifier_rejections=2`
  - 见 `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.json:28220-28317`

结论：

- “`applied=true` 但 0 site 命中/最终没变”是真实存在的；这解释了一部分 `36`。

#### 候选 3：测量侧 race，`read_bpf_stats` 在 REJIT 前后读到同一 snapshot

可以排除为当前 `36` 的根因。

理由：

- `no_programs_changed_in_loader` 在 `corpus/driver.py:524-527` 已经会在 apply record 未报告 change 时直接产生
- 这个分支发生在 post-REJIT stats 对比之前，根本不需要依赖 `bytes_jited/xlated` 或 `exec_ns` 的前后差异
- workload 驱动也只要 `rejit_result_has_any_apply()` 为真就会跑 post-REJIT measurement：`runner/libs/case_common.py:88-96`, `runner/libs/case_common.py:483-488`

结论：

- 即使存在独立的 measurement race，它也不是当前这 36 个 reason 的主要解释路径。

#### 候选 4：其他

确认还有一个重要子类：中间 pass 命中了，但 verifier 把所有 tentative rewrite 都回滚了，最终 program 不变。

直接证据：

- `tetragon/default:event_execve` 的 raw debug output 显示：
  - `map_inline` `sites_applied=7`，但 `action="rolled_back"`，`verify_result="rejected"`
  - `const_prop` `sites_applied=1`，但 `action="rolled_back"`，`verify_result="rejected"`
  - 最终 summary 仍是 `program_changed=false`, `total_sites_applied=0`, `passes_changed=0`
  - 见 `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.json:28220-28317`

这和 daemon 逻辑一致：

- pipeline 只把 `changed=true` 的 pass 计入 `program_changed` / `total_sites_applied`：`daemon/src/pass.rs:816-832`, `daemon/src/pass.rs:847-860`
- 如果最终 `pipeline_result.program_changed == false`，daemon 直接走 “restored_original / no_change” 返回：`daemon/src/commands.rs:737-767`

结论：

- 当前 `36` 里除了纯 no-op/0-hit，还有“尝试改写过，但全部 verifier rollback”的样本。

### 5. 代码级结论

结论分两层：

1. 这不是 apply fake-success bug。
   `Wave 1` 之后 daemon 确实上报了 `summary.applied + pass counters`，而 corpus 也在读这些字段：`runner/libs/rejit.py:597-643`, `corpus/driver.py:471-496`。

2. 这也不是 plan doc 里说的“same-size / bytes_jited gap”。
   当前代码没有这么判。

更准确的结论是：

- `no_programs_changed_in_loader` 是一个命名不准确的 observability bucket
- 它的真实语义是“loader/apply 这条路径最后没有拿到 surviving 的 program change”
- 它把至少三类情况混在一起：
  - 0 site 命中
  - pass 命中但全部被 verifier rollback
  - apply 成功但最终 `program_changed=false`

因此：

- 这是 measurement taxonomy / observability gap
- 严格说属于 corpus 侧 reason 命名与分桶过粗的 bug
- 不是 daemon apply correctness bug

### 6. 如果要修，应该改哪里

首改点：

- `corpus/driver.py:511-540`
  - 把 `no_programs_changed_in_loader` 拆成更细 reason，至少分出：
    - `no_final_program_change`
    - `no_sites_matched`
    - `all_tentative_changes_rolled_back`
    - `missing_post_rejit_measurement`

判定依据：

- `summary.program_changed`
- `summary.total_sites_applied`
- `summary.verifier_rejections`
- `debug_result.passes[*].action`
- `debug_result.passes[*].verify_result`

次改点：

- `runner/libs/rejit.py:586-643`
  - 保留更结构化的 per-pass rollback/rejection 摘要，减少 corpus 侧从 `debug_result` 原始 JSON 反推 reason

不建议的修法：

- 不要把 `bytes_jited/xlated` 变成 primary 判据
- 不要靠 JIT image hash 去替换现有 `summary.program_changed` 语义；那会把“semantic rewrite succeeded but size unchanged”的正确样本重新打坏

## 问题 2：为什么 20 个 app 只发现 ~48 个 program，而不是历史上的“几百个”

### 1. 当前 `Programs` 列的来源

现在 corpus 是 app-centric，不是旧的 object-centric。

证据：

- `macro_apps.yaml` 只定义 20 个 app 实例，没有 program count 字段：`corpus/config/macro_apps.yaml:1-120`
- `AppSpec` 字段只有 `name/runner/workload/duration_s/args`：`runner/libs/app_suite_schema.py:24-33`
- YAML 多余字段只会进 `args`，schema 本身没有 `programs:` 之类声明：`runner/libs/app_suite_schema.py:83-94`, `runner/libs/app_suite_schema.py:136-149`
- corpus driver 用 `runner.start()` 返回的 live `prog_ids` 和 `runner.programs` 建立 state：`corpus/driver.py:810-835`, `corpus/driver.py:1177-1183`
- result.md 的 `Programs` 列最终就是 `len(program_rows)`：`corpus/driver.py:648-689`

所以：

- `Programs` 列不是 YAML 声明值
- 是 runner 当场发现到的 live program 数

### 2. “几百个”到底对应哪个历史口径

plan doc 里“几百个 / 2019 prog / 469 objects”对应的是旧 object-centric corpus，不是现在这 20 个 macro app：

- `2019/2019 程序 100%`：`docs/kernel-jit-optimization-plan.md:863`
- `568 obj / 2019 prog`：`docs/kernel-jit-optimization-plan.md:867`
- `477 obj / 2019 prog` object-centric schema：`docs/kernel-jit-optimization-plan.md:879`
- `Corpus 469 objects`：`docs/kernel-jit-optimization-plan.md:985`
- 新架构切到 `loader-instance lifecycle` / `macro_apps.yaml`：`docs/kernel-jit-optimization-plan.md:1014`

这就是历史口径切换：

- 旧口径：按 `.bpf.o` / section / object 覆盖，天然是几百 object、上千 program
- 新口径：按“真实 app loader instance”测一个 live app，会显著少很多

因此：

- 从“几百个”掉到“~48 个”这一层面，本身是设计变化，不自动代表 bug

### 3. 当前各 runner 怎么发现 program

#### BCC / bpftrace

- 通过 `wait_for_attached_programs()` 等待进程 attach 的 program：`runner/libs/app_runners/process_support.py:16-41`
- 底层调用 `find_bpf_programs(pid)`：`runner/libs/agent.py:110-141`
- `find_bpf_programs(pid)` 的关键限制是：只认 `/proc/<pid>/fdinfo` 里仍然有 `prog_id` 的 program：`runner/libs/agent.py:90-107`, `runner/libs/agent.py:115-141`
- BCC `start()`: `runner/libs/app_runners/bcc.py:436-506`
- bpftrace `start()`: `runner/libs/app_runners/bpftrace.py:151-199`

#### SCX

- 先发现 loader-owned `struct_ops` program，再按名字去全局 `bpftool prog show` 追 live set：`runner/libs/app_runners/scx.py:129-167`
- `start()` 返回的是 refresh 后的 live scheduler program IDs：`runner/libs/app_runners/scx.py:396-412`

#### Tetragon

- 不是 FD-owned 枚举
- 用全局 `bpftool prog show`，再减掉启动前的 `before_ids`：`runner/libs/app_runners/tetragon.py:21-27`, `runner/libs/app_runners/tetragon.py:63-67`
- `start()` 在没给 `expected_program_names` 时，直接收 `session.programs`：`runner/libs/app_runners/tetragon.py:317-340`

#### Tracee

- 入口是 `find_bpf_programs(proc.pid)`，同样依赖 loader-owned FD：`runner/libs/app_runners/tracee.py:257-285`
- `healthy` 判定也要求能在 `find_bpf_programs(proc.pid)` 里看到新 program：`runner/libs/app_runners/tracee.py:257-268`
- `start()` 直接把 `session.programs` 作为 corpus 的 live set：`runner/libs/app_runners/tracee.py:496-521`

#### Katran

- runner 明确只把 `session.program` 这一支 balancer program 暴露给 corpus：`runner/libs/app_runners/katran.py:690-712`

### 4. 对当前几个“问号 app”逐个下结论

#### `katran = 1`

这是正确的 app-centric 设计，不是漏枚举。

理由：

- `KatranRunner.start()` 最后显式做的是 `self.programs = [dict(session.program)]`，返回 `[session.prog_id]`：`runner/libs/app_runners/katran.py:710-712`
- 当前三份 result.md 都显示 `katran` 是 `Programs = 1`：`x86_kvm/result.md:29`, `aws_x86/result.md:29`, `aws_arm64/result.md:29`

结论：

- 不应该把 Katran “修”成统计所有瞬时 loader program；当前 corpus 本来就只测 balancer ingress program。

#### `tracee/default = 2/3`

这更像 runner 发现逻辑漏口，不像“Tracee 现在就只 attach 2 个”。

证据链：

- 当前 Tracee runner 只看 loader-owned FD：`runner/libs/agent.py:90-141`, `runner/libs/app_runners/tracee.py:257-285`
- `macro_apps` 的 `tracee/default` 没有额外 expected-program 配置：`corpus/config/macro_apps.yaml:98-103`
- 当前三个 session 的 result.md 是：
  - KVM x86: `Programs = 3`：`corpus/results/x86_kvm_corpus_20260421_232916_947372/result.md:30`
  - AWS x86: `Programs = 2`：`corpus/results/aws_x86_corpus_20260422_012001_472335/result.md:30`
  - AWS arm64: `Programs = 2`：`corpus/results/aws_arm64_corpus_20260422_044304_037607/result.md:30`
- 当前 KVM x86 的三个 program 是两个 raw-syscalls 再加一个 `sched_process_fork`：
  - `tracepoint__raw_syscalls__sys_enter`: `x86_kvm/result.json:32172-32173`
  - `tracepoint__raw_syscalls__sys_exit`: `x86_kvm/result.json:32468-32469`
  - `tracepoint__sched__sched_process_fork`: `x86_kvm/result.json:33222-33223`
- 但同样的 app-centric 结果在 2026-04-03 本地 VM 里曾经是 `44` 个：`corpus/results/vm_corpus.md:30`
- 旧 VM app-centric 结果里至少还能看到更多 Tracee live programs，例如：
  - `tracepoint__sched__sched_process_fork`: `corpus/results/vm_corpus.json:56599-56600`
  - `sched_process_fork_signal`: `corpus/results/vm_corpus.json:56935-56936`

代码级解释：

- 只要 Tracee attach 后把某些 prog FD 关掉，但 program 依然 live/attached，这些 program 就会从 `find_bpf_programs(proc.pid)` 消失
- 这正是 `runner/libs/agent.py:90-141` 这套发现模型的结构性限制

结论：

- `tracee/default = 2/3` 很可能是 runner census undercount
- 不是 corpus driver 漏 `get_next_id`；是 Tracee runner 发现口径过窄

#### `tetragon/default = 1`

这里不能直接下“完全正确”或“完全错误”的断言；代码上至少存在一个 corpus/e2e 口径不一致的 gap。

先看现状：

- 当前三份 result.md 都是 `Programs = 1`：`x86_kvm/result.md:28`, `aws_x86/result.md:28`, `aws_arm64/result.md:28`
- 当前权威结果里这 1 个就是 `event_execve`：`x86_kvm/result.json:28282-28283`

Tetragon runner 的发现方式本身不是 FD 漏枚举：

- 它用的是全局 `bpftool prog show` before/after diff：`runner/libs/app_runners/tetragon.py:21-27`, `runner/libs/app_runners/tetragon.py:63-67`
- 所以这不是 Tracee 那种“loader-owned FD 看不见 live program”的问题

但当前 corpus runner 还有一个明显缺口：

- `config_execve_rate.yaml` 明确声明了
  - `target_programs = [execve_rate, event_execve]`
  - `apply_programs = [execve_rate, event_execve]`
  - 见 `e2e/cases/tetragon/config_execve_rate.yaml:1-29`
- e2e case 会按这个 config 去 `wait/select` Tetragon programs：`e2e/cases/tetragon/case.py:139-185`, `e2e/cases/tetragon/case.py:705-733`
- 但 corpus 的 shared runner adapter 没有把这些 config 传进 `TetragonRunner`，只传了 `workload_spec`：`runner/libs/app_runners/__init__.py:63-69`, `corpus/driver.py:1177-1183`
- `TetragonRunner.start()` 在没给 `expected_program_names` 时，直接接受 `session.programs`：`runner/libs/app_runners/tetragon.py:317-340`

再看历史：

- 2026-04-03 的 app-centric `vm_corpus` 里，`tetragon/default` 曾经是 `Programs = 8`：`corpus/results/vm_corpus.md:28`
- 旧结果里至少能看到 `execve_rate` 和 `event_execve` 都出现过：`corpus/results/vm_corpus.json:44309`, `corpus/results/vm_corpus.json:44329`

结论：

- `tetragon/default = 1` 不是 `get_next_id` 枚举 bug
- 但当前 corpus 路径确实没有对齐 e2e 的 `target_programs/apply_programs` 选择逻辑
- 所以“1 个就是全部应测 program”这个结论，当前代码并不能完全证明

### 5. 对“~48 个 program”这个总数的最终结论

整体结论分两层：

1. 总量层面：`~48` 是 app-centric 设计下的合理量级，不再应该拿旧 object-centric 的“几百 / 2019 prog”作预期。

2. 个别 runner 层面：当前发现数并非全部都可信。
   - `katran = 1`：正确，按设计就是 1
   - `tracee = 2/3`：大概率 undercount，原因是 FD-owned discovery
   - `tetragon = 1`：不是全局枚举 bug，但 corpus 未对齐 e2e 的 configured target/apply selection，当前数字仍有口径 gap

所以更准确的话是：

- “48 个 program” 作为 app-centric corpus 的总量级是正确的
- 但其中 Tracee 明显有 discovery 漏口，Tetragon 至少有 config parity gap；不能把当前每个 per-app count 都当成完全权威

## 应该做什么 / 不应该做什么

### 应该做什么

- 在 `corpus/driver.py:511-540` 拆分 `no_programs_changed_in_loader`，把 “0 hit / verifier rollback / missing post-REJIT” 分成不同 reason。
- 在 `runner/libs/rejit.py:586-643` 增加结构化摘要，把 per-pass `rolled_back` / `verify_result` / `sites_applied` 提炼出来，避免 corpus 侧靠解析 `debug_result.output` 推断。
- 在 `runner/libs/agent.py:90-141` 与 `runner/libs/app_runners/tracee.py:227-289` 增加“live attached census”模式，用 global `bpftool prog show` 前后差或更强 tagging 发现 Tracee live programs；FD duplication 只保留给真正要 apply 的 program。
- 让 corpus 的 Tetragon 路径复用 e2e 的 configured target/apply selection 语义，至少对齐 `e2e/cases/tetragon/config_execve_rate.yaml:11-17` 与 `e2e/cases/tetragon/case.py:139-185,705-733`；改点在 `runner/libs/app_runners/__init__.py:63-69`, `runner/libs/app_runners/tetragon.py:264-340`，必要时把 program 名列表显式写进 `macro_apps.yaml`。
- 给 Tracee/Tetragon 增加一个 corpus debug artifact，至少落：
  - 启动前 program IDs
  - 启动后全局 live programs
  - runner 实际 selected/apply program names
  这样下次不需要再靠 result.json 大海捞针。
- 回写并修正 plan doc 里对 `no_programs_changed_in_loader` 的解释，至少修 `docs/kernel-jit-optimization-plan.md:25` 与 `docs/kernel-jit-optimization-plan.md:1040`，避免后续调研继续沿“same-size bytes gap”这个错误前提展开。

### 不应该做什么

- 不要把 `bytes_jited/xlated` 或 JIT image hash 直接拿来替换现在的 “final program changed” 判据；那会把合法的 same-size rewrite 重新误判掉。
- 不要把 daemon `summary.applied=true` 解释成“最终 program 一定变了”；当前代码明确定义不是这样：`daemon/src/commands.rs:737-767`, `runner/libs/rejit.py:597-643`。
- 不要把当前 36 个 exclusion 归因到 measurement race；现有代码已经能在 compare 前直接产出这个 reason：`corpus/driver.py:524-533`。
- 不要去“修” Katran 的 `Programs = 1`；`runner/libs/app_runners/katran.py:710-712` 说明这就是 runner 的目标 program 选择。
- 不要再拿旧 object-centric 的“469 objects / 2019 prog”去要求当前 macro app suite 必须有几百 program；这两个口径不是一回事：`docs/kernel-jit-optimization-plan.md:863`, `docs/kernel-jit-optimization-plan.md:879`, `docs/kernel-jit-optimization-plan.md:985`, `docs/kernel-jit-optimization-plan.md:1014`。
