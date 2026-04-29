# bpfopt 设计修订 v2（CLI-first）

本文是在通读 [docs/tmp/bpfopt_design.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/bpfopt_design.md) 全文，以及 [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md) §4 系统架构与 §4.6 daemon 设计约束之后，对 `bpfopt` 方案做的 review 和重写。

v2 的核心目标只有两个：

1. 降复杂度，把公开设计面收缩到 CLI + 文件格式。
2. 保留 §4.6 的关键约束，尤其是 per-pass dry-run verify、verifier-in-the-loop、最终一次性 REJIT、结构化 per-pass 记录。

这里的“CLI-first”指的是：

1. 对外支持的接口只有命令行工具和文件格式。
2. 不设计公开 Rust API，不设计 C FFI，不设计稳定 `.a/.so` 接口。
3. 同一仓库内部为了复用代码可以有私有 crate，但那只是实现细节，不是架构承诺。

## 0. 结论摘要

v2 的判断很明确：

1. `bpfopt` 应该是纯 CLI bytecode optimizer，不再把自己设计成公共库。
2. per-pass verifier dry-run 应拆成独立 CLI：`bpfverify`。
3. profiling 应拆成独立 CLI：`bpfprof`。
4. `bpfopt`、`bpfverify`、`bpfprof`、`bpfrejit-daemon` 应放在同一个独立 git repo 中，由 `bpf-benchmark` 以 submodule 固定版本。
5. 现在不做 libbpf FFI；近期兼容路径是“离线预处理纯 bytecode passes”或“load 前 fork+exec CLI”。
6. 原设计里最需要删除的是：公共库 API、C FFI、`ValidationOracle`、symbolic `KinsnRequirement` 输出、自定义 pipe framing、过于泛化的 target/link 抽象。
7. 四工具拆分是合理的；再继续往下拆就过细了。

## 1. 对用户七个问题的明确回答

### 1.1 复杂度要降低：是否应只设计 CLI？

结论：**是。**

理由：

1. 当前真正需要稳定下来的不是函数签名，而是“输入什么文件、输出什么文件、失败时怎么报错”。
2. 现阶段调用方基本只有 daemon、benchmark orchestration，以及未来可能的 loader wrapper；这些都完全可以通过 CLI 集成。
3. 一旦先设计公共库 API，就会过早冻结很多错误的抽象边界，例如 validator trait、link requirement、C ABI schema。
4. §4.6 的关键约束是行为约束，不是进程内调用约束。把它实现成 CLI 不违背计划文档。

因此 v2 删除以下内容：

1. `lib.rs` 导出面设计。
2. `optimize_with_validator()` 这类回调式库接口。
3. C FFI 草案。
4. “未来 libbpf 直接链接库”作为当前设计中心。

保留的公共接口只有：

1. `bpfopt`
2. `bpfverify`
3. `bpfprof`
4. `bpfrejit-daemon`
5. 它们读写的 JSON / binary 文件格式

### 1.2 Validator 是否应独立成 CLI？

结论：**是，应该做成独立 CLI `bpfverify`。**

理由：

1. `BPF_PROG_LOAD` dry-run 是典型 kernel-facing 行为，不属于 optimizer 本体。
2. verifier log 解析虽然服务于优化，但“向内核发起一次 dry-run load”本身不是 bytecode rewrite。
3. 单独做成 `bpfverify` 后，`bpfopt` 就不需要 `ValidationOracle` 这种为库 embedding 服务的抽象。
4. 这也更符合 §4.6 的责任分离：daemon 负责 per-pass verify 流程，但可以通过调用 `bpfverify` 来履行这个责任。

需要强调的一点是：

1. **责任仍在 daemon，不在 `bpfverify`。**
2. `bpfverify` 只是执行一次 dry-run verify 并返回结果。
3. “何时调用、验证失败后是否回滚该 pass、是否继续后续 pass、如何记录 per-pass action”仍是 daemon 的编排职责。

### 1.3 `bpfprof` 是否应独立？

结论：**是。**

理由：

1. profiling 与 optimization 是不同的依赖域：前者依赖运行时采样、PMU、`bpf_stats`，后者只应消费 profile。
2. 把 profiler 留在 daemon 内会再次把 daemon 变成“大而全的优化服务”，与当前降复杂度目标相反。
3. `bpfprof` 输出标准 `profile.json` 后，`bpfopt` 可以纯消费，daemon 可以纯转发，职责清晰。

建议：

1. `bpfprof` 负责采集 branch profile / `bpf_stats` / PMU 数据并输出统一 JSON。
2. daemon 可以在 session 开始前调用一次 `bpfprof`，也可以完全由 benchmark runner 预先生成 profile 文件再传给 daemon。
3. daemon 不再持有长期 profiler thread，不再内部做 hotness ranking。

### 1.4 统一仓库：一个 repo 还是多个 repo？

结论：**一个独立 repo，随后由 `bpf-benchmark` 以 submodule pin 住。**

不建议：

1. 直接散落在 `bpf-benchmark` 主仓库里长期生长。
2. 把四个工具拆成完全独立、彼此不同步的多个 repo。

推荐结构：

1. 有一个独立工具链仓库，例如 `bpfopt-suite`。
2. 仓库内包含四个 CLI 和若干私有共享 crate。
3. `bpf-benchmark` 通过 submodule 固定一个 commit，保证 benchmark 可复现。

理由：

1. 四个工具共享 schema、测试夹具、内核协议假设、错误语义，版本需要锁步。
2. 完全独立多 repo 会引入 schema drift、兼容矩阵和调试成本。
3. 完全塞进 `bpf-benchmark` 主树又会让“实验框架”和“优化工具链”耦合过紧，不利于单独演进。

### 1.5 libbpf 兼容路径怎么考虑？

结论：**现在不做 FFI，也不以 `.a/.so` 为设计中心。**

v2 的近期兼容路径分两类：

1. **纯 bytecode passes 的离线预处理**
   在 build pipeline 或 object 处理流程中，对 `.bpf.o` 或提取出的 raw BPF insns 调 `bpfopt`。
2. **load 前 wrapper/fork+exec**
   未来如果需要和 libbpf 更紧密结合，可以在 load 前由 wrapper 解析对象、准备 side-input、调用 `bpfopt` CLI，再继续原本的 load。

需要正视一个限制：

1. 在本次 v2 里，我们删掉 delayed kinsn binding。
2. 因此 **target-aware kinsn passes 不能假设离线预处理一定可用**。
3. 这类 pass 通常需要在接近 load/rejit 的时刻拿到 resolved kinsn 信息后再跑。

所以更准确的判断是：

1. **离线预处理适合纯 bytecode passes。**
2. **kinsn passes 更适合 daemon/live loader wrapper 模式。**
3. 如果将来 libbpf integration 真的成为必须，再考虑做一个很薄的 loader-side wrapper，甚至再进一步做库；那是下一阶段问题，不应反向绑架 v2。

### 1.6 现有设计里哪些地方不合理？

结论：原设计最主要的问题不是“方向错了”，而是**为未来 embedding 预留了太多现在根本不需要的抽象**。

逐项回答：

1. `KinsnRequirement` 符号化延迟绑定：**当前是过度设计。**
   在 CLI-only 模式下，`bpfopt` 直接通过 `--target` / `--kinsns` 获得 resolved kinsn 能力即可。当前不需要把“待绑定 requirement”再吐给外部 linker。

2. `ValidationOracle` hook：**过度设计。**
   如果 verifier 由 `bpfverify` 作为独立 CLI 提供，那么 daemon 串起 `bpfopt pass -> bpfverify -> accept/reject` 就足够了。

3. `MapValueSet`：**方向对，但形式应简化成文件输入。**
   不需要把它设计成公开库类型；直接定义 `map-values.json` 即可，内容包含 map metadata 和稀疏 value snapshot。

4. `pack/unpack` + 自定义 pipe framing：**过度设计。**
   v2 不需要为了 shell pipeline 去发明二进制 framing。daemon 完全可以用显式临时文件来编排。

5. `TargetDesc` / `PlatformDesc` / `KinsnCatalog` 多层拆分：**对当前范围过细。**
   v2 直接用一个 `target.json` 文件描述 arch/features/kinsns 即可。

6. “公共 analyze API” 与大量导出 struct：**过度设计。**
   如果还需要分析能力，做成 `bpfopt inspect` 或 `bpfopt list-passes` 子命令即可。

7. 通用 `strictness` 框架：**可以收缩。**
   不要做复杂策略对象。v2 只需要明确的 fail-fast 规则和少量显式 flag。

8. C FFI：**当前完全不该设计。**

同时，也有几样东西应保留，但换个表达方式：

1. 原来的 `specialization_dependencies` 思想是对的，因为 daemon 的 invalidation 确实需要它。
   v2 可以改名为 `invalidation-hints.json`，但不该删。

2. verifier log 解析结果作为后续 pass 输入也是对的。
   只是这件事应由 `bpfverify` 产出 `verifier-states.json`，而不是由 `bpfopt` 暴露 validator trait。

### 1.7 Unix 哲学：这样拆是否合理，会不会拆太细？

结论：**这四个工具的拆分是合理的，没有拆太细；但不建议继续往下拆。**

合理之处在于它们分别对应四种完全不同的依赖域：

1. `bpfopt`：纯 bytecode rewrite
2. `bpfverify`：kernel verifier dry-run
3. `bpfprof`：runtime profile collection
4. `bpfrejit-daemon`：live program session / orchestration / final REJIT

不应再往下拆的原因：

1. 不需要再单独拆一个 analyzer binary；分析是 `bpfopt` 的子命令即可。
2. 不需要再拆一个 linker binary；v2 不做 delayed kinsn linking。
3. 不需要再拆一个 side-input remapper binary；这属于 `bpfopt` pass 执行后的附带输出。

所以推荐边界是：

1. 四个顶层 CLI。
2. 仓库内可有共享私有 crate。
3. 对外只承诺 CLI 和文件格式。

## 2. v2 总体架构

### 2.1 角色划分

```
                +------------------+
                |      bpfprof     |
                | collect profile  |
                +--------+---------+
                         |
                    profile.json
                         |
                         v
+-------------+   +------+-------+   +-----------------+
| original     |-->| bpfopt pass |-->| candidate code  |
| bytecode     |   | / pipeline   |   | + pass report   |
+-------------+   +------+-------+   +--------+--------+
                         |                       |
                         |                       v
                         |                +------+------+
                         +--------------->|  bpfverify  |
                                          | dry-run     |
                                          +------+------+
                                                 |
                                   verifier log / states / pass-fail
                                                 |
                                                 v
                                          +------+------+
                                          | bpfrejit-   |
                                          | daemon      |
                                          | orchestrate |
                                          +-------------+
```

### 2.2 关键原则

1. `bpfopt` 不做任何 syscall，不读 live kernel，不探测 host，不做 profiling。
2. `bpfverify` 只做一次 dry-run `BPF_PROG_LOAD`，输出 pass/fail、verifier log、解析后的 verifier states。
3. `bpfprof` 只做采集和 profile 归一化，不做优化决策。
4. `bpfrejit-daemon` 只做 live program snapshot、per-pass orchestration、最终 `BPF_PROG_REJIT`、以及 invalidation 生命周期。
5. 最终对外稳定的是文件 schema，不是进程内类型系统。

## 3. 四个工具的职责与 CLI 形态

### 3.1 `bpfopt`

职责：

1. 读取 raw BPF bytecode。
2. 读取显式 side-input。
3. 执行单个 pass 或一个纯离线 pipeline。
4. 输出新 bytecode、pass report、以及 invalidation hints。

建议保留的子命令：

1. `bpfopt pass`
2. `bpfopt pipeline`
3. `bpfopt inspect`
4. `bpfopt list-passes`

建议接口：

```bash
bpfopt pass \
  --pass const_prop \
  --input in.bin \
  --output out.bin \
  --program program.json \
  --target target.json \
  --profile profile.json \
  --profile-out profile.next.json \
  --verifier-states verifier.json \
  --map-values map-values.json \
  --report pass-report.json \
  --invalidation-out invalidation.json
```

设计说明：

1. `pass` 是 daemon 的主要编排原语，因为 daemon 需要 per-pass verify。
2. `pipeline` 只是本地实验和离线批处理的 convenience wrapper，不是 verifier-in-the-loop 的主路径。
3. 缺失某个被该 pass 明确需要的 side-input 时，`bpfopt` 直接报错退出，不做静默 fallback。
4. 如果输入了 `profile.json`，且该 pass 改变了 PC，`bpfopt` 应输出 remap 后的 `profile.next.json`。
5. 某个 pass 没有 candidate site 时，正常返回 `changed=false`，并在 report 里写明原因。

### 3.2 `bpfverify`

职责：

1. 用 raw BPF syscall 发起一次 dry-run `BPF_PROG_LOAD`。
2. 返回 verifier pass/fail。
3. 返回 verifier log。
4. 把 log 解析成 `verifier-states.json`，供后续 pass 消费。

建议接口：

```bash
bpfverify dry-run \
  --input candidate.bin \
  --program program.json \
  --load-context load-context.json \
  --output verify-report.json \
  --verifier-states-out verifier-states.json
```

设计说明：

1. `program.json` 是优化器也会用到的程序元数据。
2. `load-context.json` 是 verifier/rejit 专用上下文，例如重放 `BPF_PROG_LOAD` 所需的 attr、map FD 绑定、fd_array、attach 相关信息。
3. `bpfverify` 不决定是否保留该 pass，只返回事实。
4. `bpfverify` 不得依赖 libbpf，只用 raw syscall，保持与 §4.6 一致。

### 3.3 `bpfprof`

职责：

1. 采集 branch profile / `bpf_stats` / PMU 等运行时统计。
2. 统一归一化为 `profile.json`。
3. 不做优化建议，不做 pass 选择，不做 REJIT。

建议接口：

```bash
bpfprof collect \
  --prog-id 123 \
  --duration-ms 500 \
  --output profile.json
```

可以后续扩展的子命令：

1. `collect`
2. `merge`
3. `show`

但 v2 只需要 `collect`。

### 3.4 `bpfrejit-daemon`

职责：

1. 枚举 live programs，抓 original bytecode。
2. 维护 session 生命周期。
3. 组织 `bpfopt`、`bpfverify`、`bpfprof` 的调用。
4. 最终调用 `BPF_PROG_REJIT`。
5. 维护 map invalidation / reoptimize 生命周期。
6. 记录结构化 per-pass 结果。

关键点：

1. daemon 是唯一的 session owner。
2. daemon crash 就是 benchmark failure，不自动重启。
3. daemon 只在最后做一次 `BPF_PROG_REJIT` 原子替换。
4. daemon 对优化逻辑的了解应降到最低，只知道“跑哪个 pass、是否接受、最终是否 REJIT”。

## 4. 数据契约

v2 的重点不是把 schema 做得无限泛化，而是做到：

1. 能支撑当前 pass；
2. 能支撑 daemon per-pass orchestration；
3. 对错误显式；
4. 不把 live kernel handle 泄漏进 `bpfopt`。

### 4.1 `program.json`

`program.json` 是优化器相关的程序元数据，不包含 live FD。

最小建议形态：

```json
{
  "schema": "bpfopt/v2/program",
  "program_name": "foo",
  "prog_type": "xdp",
  "expected_attach_type": null,
  "map_bindings": [
    {
      "insn_pc": 12,
      "pseudo_kind": "map_fd",
      "logical_map_id": "kernel-map-id:123"
    }
  ]
}
```

说明：

1. `prog_type` 用人类可读字符串即可，不需要在 schema 里过早抽象成复杂枚举系统。
2. `logical_map_id` 是 `map-values.json` 和 invalidation hints 的连接点。
3. 若某些 verifier 重放必需字段不属于 optimizer 语义，则放到 `load-context.json`，不要混进这里。

### 4.2 `target.json`

`target.json` 是 `bpfopt` 的 target-aware 输入，包含 arch/features 以及 resolved kinsn 能力。

建议形态：

```json
{
  "schema": "bpfopt/v2/target",
  "arch": "x86_64",
  "march": "x86_64-v3",
  "features": ["cmov", "movbe", "bmi2", "rorx"],
  "kinsns": {
    "bpf_rotate64": {
      "available": true,
      "encoding": "packed_call",
      "btf_func_id": 12345
    },
    "bpf_select64": {
      "available": true,
      "encoding": "packed_call",
      "btf_func_id": 12346
    }
  }
}
```

说明：

1. v2 中 `bpfopt` 直接消费 resolved kinsn 能力。
2. 缺少某个被请求 pass 所要求的 kinsn 时，`bpfopt` 应直接报错退出，不能静默降级。
3. 这里不再引入 symbolic `KinsnRequirement` 输出，也不设计独立 linker 阶段。

### 4.3 `load-context.json`

这是 **`bpfverify` / daemon 专用** 的 kernel-facing 输入，不给 `bpfopt` 用。

它应包含：

1. dry-run `BPF_PROG_LOAD` 需要重放的 verifier 相关 attr。
2. map FD 绑定。
3. kfunc/kinsn 相关 fd_array。
4. 其他 attach / BTF / flag 上下文。

这样做的原因是：

1. 优化器不需要知道 live FD。
2. verifier/rejit 需要知道。
3. 把它和 `program.json` 分离，能避免把 kernel handle 语义污染到 optimizer 输入。

### 4.4 `profile.json`

`profile.json` 保持为标准 side-input。

建议包含：

1. 程序级 branch miss rate。
2. site 级 taken/not-taken 计数。
3. 采集窗口和 producer 信息。

v2 的关键要求不是 profile 内容有多完整，而是：

1. 格式固定；
2. 缺 profile 时显式；
3. 不由 `bpfopt` 或 daemon 隐式采集。
4. 若 pass 改变 PC，`bpfopt` 必须输出 remap 后的 profile 文件，不能让下一个 pass 消费错位 profile。

### 4.5 `verifier-states.json`

`verifier-states.json` 由 `bpfverify` 生成，`bpfopt` 消费。

它至少要能表达：

1. 每个相关 PC 的寄存器常量信息。
2. range / tnum。
3. 栈槽信息。
4. 必要的 frame/from_pc 上下文。

v2 的关键点是：

1. 这是一个文件格式，不是公共库 struct。
2. 它的 producer 是 `bpfverify`，不是 `bpfopt`。
3. daemon 在 pass accept 后，用新的 `verifier-states.json` 替换旧版本，继续喂给下一个 pass。

### 4.6 `map-values.json`

结论：**用 JSON 文件传入是合理的，但应该是“稀疏 map snapshot”，不是通用 runtime map API。**

最小建议形态：

```json
{
  "schema": "bpfopt/v2/map-values",
  "maps": [
    {
      "logical_map_id": "kernel-map-id:123",
      "map_type": "array",
      "key_size": 4,
      "value_size": 8,
      "max_entries": 1024,
      "frozen": false,
      "entries": [
        { "key_hex": "01000000", "value_hex": "2a00000000000000" },
        { "key_hex": "02000000", "value_hex": null }
      ]
    }
  ]
}
```

说明：

1. `value_hex: null` 表示明确 lookup miss。
2. key 完全没出现表示 unknown，不是 miss。
3. 只需要收集该程序潜在用到的 key，不需要把整个 map 全量 dump 成通用数据库。
4. `bpfopt` 只读这个文件，不进行 live map lookup。

### 4.7 `pass-report.json` 与 `invalidation.json`

每次 `bpfopt pass` 后至少要输出一个 `pass-report.json`：

```json
{
  "pass": "const_prop",
  "changed": true,
  "sites_applied": 3,
  "insn_delta": -5,
  "pc_remapped": true,
  "notes": []
}
```

如果该 pass 产生了 specialization 依赖，还要输出 `invalidation.json`：

```json
{
  "schema": "bpfopt/v2/invalidation-hints",
  "hints": [
    {
      "kind": "map_value_equals",
      "logical_map_id": "kernel-map-id:123",
      "key_hex": "01000000",
      "expected_value_hex": "2a00000000000000"
    }
  ]
}
```

这里不需要把 invalidation hint 抽象成跨语言 API 类型；文件即可。

## 5. daemon 的编排流程

这部分必须与 [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md) §4.6 对齐。

### 5.1 session 级流程

1. daemon 在 benchmark session 开始时启动一次。
2. 读取配置、准备临时工作目录、可选地调用 `bpfprof collect`。
3. 枚举 live programs，抓取 original bytecode 和相关上下文。
4. 对每个 program 执行 per-pass optimize/verify loop。
5. 对 accept 后的最终 bytecode 做一次 `BPF_PROG_REJIT`。
6. 安装 invalidation tracking。
7. session 结束后关闭 daemon。

### 5.2 单个 program 的 per-pass loop

推荐的精确流程如下：

1. 以 original bytecode 作为当前 accepted program。
2. 准备初始 `program.json`、`target.json`、`load-context.json`，以及可选的 `profile.json`、`verifier-states.json`、`map-values.json`。
3. 对 pipeline 中每个 pass 依次执行：
4. 调 `bpfopt pass`，生成 candidate bytecode 和 `pass-report.json`。
5. 若 `changed=false`，直接记录 `action=kept_noop`，进入下一个 pass。
6. 若 `changed=true`，调 `bpfverify dry-run` 对 candidate 做 verify。
7. 若 verify fail：
   记录 `verify_result=rejected`、`action=rolled_back`，丢弃 candidate，保留当前 accepted bytecode，继续下一个 pass。
8. 若 verify pass：
   记录 `verify_result=accepted`、`action=kept`，把 candidate 设为新的 accepted bytecode。
9. 同时用新的 `verifier-states.json` 替换旧版本，供后续 pass 使用。
10. 如果该 pass 产出了 remap 后的 `profile.next.json`，则用它替换旧 `profile.json`。
11. 全部 pass 结束后，只对最终 accepted bytecode 调一次 `BPF_PROG_REJIT`。

这个流程保留了 §4.6 的全部关键点：

1. per-pass verify 用 `BPF_PROG_LOAD dry-run`
2. verifier-in-the-loop
3. 最终只做一次 REJIT
4. 结构化 per-pass 记录

### 5.3 结构化 per-pass 记录

daemon 最终保存的记录至少应包含：

```json
{
  "pass": "const_prop",
  "changed": true,
  "sites_applied": 3,
  "insn_delta": -5,
  "verify_result": "accepted",
  "verify_error": null,
  "action": "kept"
}
```

这与 §4.6 的要求一一对应：

1. `pass`
2. `changed`
3. `sites_applied`
4. `insn_delta`
5. `verify_result`
6. `verify_error`
7. `action`

注意：

1. `pass-report.json` 是 `bpfopt` 的局部输出。
2. 真正的 per-pass session record 由 daemon 汇总 `bpfopt` 和 `bpfverify` 的结果后写出。

## 6. 对旧设计的删改清单

### 6.1 明确删除

以下内容建议从设计文档里明确删除，不再作为 v2 范围：

1. 公共 Rust API 设计。
2. `optimize_with_validator()` / `ValidationOracle`。
3. C FFI 设计。
4. symbolic `KinsnRequirement` 输出。
5. 单独 linker 阶段。
6. `pack/unpack` 和自定义 pipe framing。
7. 通用 strictness 策略对象。
8. 把 profiler 放进 daemon。

### 6.2 保留但简化

以下内容建议保留，但改成更简单的 CLI/file 形式：

1. pass registry
   保留为 `bpfopt list-passes --json`

2. analysis / inspect
   保留为 `bpfopt inspect`

3. verifier states
   保留为 `bpfverify` 产出的 `verifier-states.json`

4. map specialization dependencies
   保留为 `invalidation.json`

5. target-aware passes
   保留，但通过 `target.json` 提供 resolved kinsn 信息

## 7. 推荐的仓库组织

推荐把四个工具放在一个独立仓库中，并作为 Rust workspace 管理。

建议布局：

```text
bpfopt-suite/
  cmd/
    bpfopt/
    bpfverify/
    bpfprof/
    bpfrejit-daemon/
  crates/
    bytecode-core/        # 私有 crate
    verifier-log/         # 私有 crate
    schema/               # 私有 crate
    kernel-sys/           # 私有 crate
  docs/
  tests/
```

这里的原则是：

1. **共享代码可以有，但都是私有实现细节。**
2. **公开承诺只有四个 CLI 和 schema。**
3. **`bpf-benchmark` 使用 submodule pin 住该仓库版本。**

## 8. libbpf 兼容路径

### 8.1 v2 的现实方案

不要在 v2 里承诺 “libbpf 直接链接 bpfopt 库”。

现实可行的路径是：

1. 对纯 bytecode passes：
   在 build pipeline 或对象处理阶段离线调用 `bpfopt`。

2. 对 kinsn passes：
   在接近 load 的时刻，由 wrapper 或 daemon 准备 resolved `target.json` 后调用 `bpfopt`。

3. 对 live 程序 REJIT：
   继续走 daemon + raw syscall。

### 8.2 如果以后真要和 libbpf 对接

推荐顺序是：

1. 先做一个极薄的 loader wrapper，内部 `fork+exec bpfopt`。
2. 只有当进程创建开销、部署复杂度或错误恢复真的成为瓶颈时，再考虑库化。
3. 即使将来库化，也应尽量复用同一套 schema 和 CLI 语义，而不是重新发明另一套 optimizer 协议。

换句话说：

1. v2 不拒绝未来库化。
2. 但 v2 绝不为了未来库化而预先复杂化今天的设计。

## 9. 最终建议

本次修订后的推荐方案可以压缩成一句话：

**把 `bpfopt` 收缩成纯 CLI bytecode optimizer；把 verifier dry-run 拆成 `bpfverify`；把 profile 采集拆成 `bpfprof`；让 `bpfrejit-daemon` 只负责 live kernel orchestration 和最终 REJIT。**

这套方案的优点是：

1. 对当前需求足够。
2. 与 §4.6 的 daemon 约束兼容。
3. 明显比原设计少一层公开 API 和一层跨语言抽象。
4. 给未来 libbpf / loader integration 留出了演进空间，但没有为它提前付复杂度成本。

如果需要一句更强的取舍判断，那就是：

**v2 应优先做“文件格式稳定的四个 CLI 工具”，而不是“一个看起来很完整、但其实为未来假设过度设计的优化库”。**
