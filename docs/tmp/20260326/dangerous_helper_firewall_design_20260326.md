# DangerousHelperFirewallPass 实现级设计（2026-03-26）

基于以下输入材料：

- `docs/tmp/20260326/dangerous_helper_firewall_research_20260326.md`
- `docs/tmp/20260326/corpus_call_statistics_20260326.md`
- `daemon/src/passes/skb_load_bytes.rs`
- `daemon/src/passes/bounds_check_merge.rs`
- `daemon/src/pass.rs`
- `daemon/src/insn.rs`
- `daemon/src/passes/mod.rs`

本文给出 `DangerousHelperFirewallPass` 在 BpfReJIT daemon 中的实现级设计。目标不是做一个新的 verifier，而是在现有 `orig_insns -> PassManager -> REJIT -> re-verify` 流水线里，识别并中和 live 程序中的危险 helper 调用。

## TL;DR

- Phase 1 只做三类动作：`deny`、`coarseify`、`audit`。
- `send_signal`、`override_return`、`set_retval` 走 fail-closed：把 `call helper` 改成 `mov64 r0, -1`，即 `-EPERM`。
- `ktime_get_ns` 走 coarseify：把 helper id 从 `5` 改成 `160`，即 `ktime_get_coarse_ns`。
- `probe_read*`、`d_path`、`copy_from_user`、`snprintf_btf`、`find_vma` 等 Phase 1 只审计，不改字节码。
- 对 `send_signal` 这类纯副作用 helper，可以额外删除其单用途参数准备指令；实现上建议直接在 rebuild 阶段省略这些指令，效果等价于“先 NOP out，再清理 NOP”。
- 该 pass 必须放在 pipeline 最后。它是安全策略 pass，不应被后续优化再改写。
- verifier 友好的核心原因是：本设计 Phase 1 会真实改写的 helper 都返回 scalar，不返回 pointer type。
- `set_retval` 有一个必须写清楚的语义 caveat：仅把 helper call 改成 `r0 = -EPERM` 能中和 helper 本身，但不能在所有情况下强制 cgroup 程序整体 fail-closed。

## 1. 目标与非目标

### 1.1 目标

`DangerousHelperFirewallPass` 的 Phase 1 目标是：

1. 在 `BpfProgram.insns` 中识别危险 regular helper call。
2. 按 helper 策略做三种处理：
   - `deny`: 中和 helper 副作用，并给后续代码留下明确错误值。
   - `coarseify`: 用返回类型兼容、语义更保守的 helper 替换。
   - `audit`: 仅记录命中位点，不改字节码。
3. 让 pass 结果能够直接进入现有 REJIT / rollback 流水线。

### 1.2 非目标

Phase 1 明确不做：

- 不在 host kernel 上直接 patch `xlated_prog_insns`。
- 不实现 `probe_read* -> bounded read / dynptr read` 的语义级重写。
- 不实现 `d_path -> bpf_path_d_path` 的跨 helper 语义迁移。
- 不为 packet-mutator helper 建完整 verifier 语义模拟。
- 不修补“helper 实现本身的内核漏洞”。

## 2. 背景结论与设计约束

研究数据给出了三个直接影响实现边界的事实：

1. 全 corpus 一共扫描到 `91,034` 次真实 helper 调用。
2. 真正适合 Phase 1 直接 fail-closed 的权限/控制流 helper 极少：`send_signal + override_return + set_retval` 严格集合里只有 `10` 次，其中 `set_retval` 为 `0`。
3. 高频危险面其实是 `probe_read*` 和 `ktime_get_ns`，所以 Phase 1 必须同时支持“强中和”和“兼容性友好的降权”。

另一个关键约束来自 daemon 当前架构：

- 检测可以基于 live `xlated` 做 inventory。
- 但 pass 真正改写的是 `BpfProgram.insns`，即 daemon 从内核取回的原始 `orig_insns`。
- 因此本文的匹配对象始终是原始 BPF bytecode，而不是 verifier fixup 之后的内部表示。

## 3. Pass 形态与内部数据模型

建议新增一个纯 transform pass：

```rust
pub struct DangerousHelperFirewallPass;
```

建议 trait 形态：

```rust
impl BpfPass for DangerousHelperFirewallPass {
    fn name(&self) -> &str { "dangerous_helper_firewall" }
    fn category(&self) -> PassCategory { PassCategory::Security }
    fn required_analyses(&self) -> Vec<&str> { vec!["branch_targets", "liveness"] }
}
```

其中：

- `branch_targets` 用于安全删除参数准备窗口，不跨 branch target 回溯。
- `liveness` 用于证明参数寄存器定义在 helper 后不再活跃。
- 如果 policy 关闭 cleanup，仅有 `deny/coarseify` 时理论上可以不依赖分析；但为减少分支复杂度，v1 仍可固定声明这两个 analysis。

建议在 pass 内维护如下私有结构：

```rust
enum RiskLevel {
    Critical,
    High,
    Medium,
}

enum HelperAction {
    Deny,
    Coarseify { replacement_id: i32 },
    Audit,
    Allow,
}

struct HelperRule {
    helper_id: i32,
    helper_name: &'static str,
    risk: RiskLevel,
    default_action: HelperAction,
    phase1_rewrite: bool,
    pure_side_effect: bool,
}

struct RewriteSite {
    call_pc: usize,
    helper_id: i32,
    helper_name: &'static str,
    action: HelperAction,
    cleanup_pcs: Vec<usize>,
}
```

设计重点：

- `Allow` 只作为 policy override 的结果存在，不出现在内建默认动作表中。
- `pure_side_effect` 只用于决定是否尝试删除参数准备窗口；Phase 1 只建议对 `send_signal` 开启。

## 4. Helper 分类表

### 4.1 Phase 1 内建默认动作

下表是 pass 的内建规则表。Phase 1 默认动作只使用 `deny / coarseify / audit` 三种。

| helper id | helper 名 | 风险级别 | 默认动作 | Phase 1 是否真改写 | 说明 |
| --- | --- | --- | --- | --- | --- |
| 58 | `override_return` | Critical | `deny` | 是 | 直接篡改被探测函数返回路径 |
| 109 | `send_signal` | Critical | `deny` | 是 | 直接向当前进程发信号 |
| 187 | `set_retval` | Critical | `deny` | 是 | 可篡改 cgroup hook 最终 errno |
| 5 | `ktime_get_ns` | Medium | `coarseify` | 是 | 降成低精度时间源 |
| 4 | `probe_read` | High | `audit` | 否 | legacy alias，高频信息读取 |
| 45 | `probe_read_str` | High | `audit` | 否 | 高频字符串读取 |
| 112 | `probe_read_user` | High | `audit` | 否 | 用户态读取 |
| 113 | `probe_read_kernel` | High | `audit` | 否 | 内核态读取 |
| 114 | `probe_read_user_str` | High | `audit` | 否 | 用户字符串读取 |
| 115 | `probe_read_kernel_str` | High | `audit` | 否 | 内核字符串读取 |
| 117 | `send_signal_thread` | Critical | `audit` | 否 | 语义与 `send_signal` 接近，Phase 1 先只记录 |
| 118 | `jiffies64` | Medium | `audit` | 否 | 低精度时间源，先作为 timing inventory |
| 125 | `ktime_get_boot_ns` | Medium | `audit` | 否 | 另一类高精度时间源 |
| 147 | `d_path` | High | `audit` | 否 | 路径泄露 |
| 148 | `copy_from_user` | High | `audit` | 否 | 用户态数据吸入 |
| 149 | `snprintf_btf` | High | `audit` | 否 | BTF 结构外带 |
| 180 | `find_vma` | High | `audit` | 否 | 地址空间信息泄露 |
| 36 | `probe_write_user` | Critical | `audit` | 否 | 风险很高，但 Phase 1 不做 stub |
| 9 | `skb_store_bytes` | High | `audit` | 否 | 数据面包修改，留到后续按 prog_type 细化 |
| 44 | `xdp_adjust_head` | High | `audit` | 否 | 数据面 headroom 修改 |
| 38 | `skb_change_tail` | High | `audit` | 否 | 数据面 tail 修改 |
| 50 | `skb_adjust_room` | High | `audit` | 否 | 数据面 room 修改 |
| 65 | `xdp_adjust_tail` | High | `audit` | 否 | 数据面 tail 修改 |
| 190 | `xdp_store_bytes` | High | `audit` | 否 | XDP 包内容修改 |

### 4.2 为什么 `send_signal` / `override_return` / `set_retval` 先做 hard rewrite

因为它们同时满足三条：

1. 真实使用量极低，兼容性风险可接受。
2. 风险语义非常直接，不需要上下文解释。
3. helper 返回值都是 scalar，适合直接 stub。

### 4.3 为什么 `probe_read*` 先只审计

因为这类 helper 高频且经常是 observability agent 的主体功能。Phase 1 如果直接改成 `r0 = -EFAULT`，兼容性破坏会非常大；而语义保真的 bounded read / dynptr rewrite 又超出当前 pass 的最小实现范围。

## 5. Pattern Detection

## 5.1 regular helper call 的识别规则

危险 helper 的匹配条件是：

```text
insn.code == (BPF_JMP | BPF_CALL)
insn.src_reg() == 0
insn.imm == helper_id
```

这里必须明确排除：

- pseudo-call：`src_reg() == BPF_PSEUDO_CALL (1)`
- kfunc call：`src_reg() == BPF_PSEUDO_KFUNC_CALL (2)`
- kinsn sidecar / packed call

因此 matcher 不应该只看 `insn.is_call()`，还必须同时检查 `src_reg() == 0`。

## 5.2 扫描方式

建议沿用现有 pass 的线性扫描风格：

1. `pc = 0`
2. 逐条读取 `program.insns[pc]`
3. 如果是 regular helper call，则取 `helper_id = insn.imm`
4. 查规则表，决定是否生成 `RewriteSite`
5. `pc += insn_width(insn)`；`LD_IMM64` 仍按 2-slot 前进

这里不需要完整 dataflow；helper 检测只看 call 本体即可。

## 5.3 `prog_type` 在检测阶段的作用

`PassContext.prog_type` 在 Phase 1 主要用于两件事：

1. 选择 policy profile。
2. 判断“该 helper 在该程序类型下是否属于 expected but dangerous”。

建议在 pass 内引入一个轻量分组，而不是硬编码完整 kernel helper availability matrix：

```rust
enum ProgramClass {
    TracingLike,
    DatapathLike,
    CgroupLike,
    Other,
}
```

示意映射：

- `TracingLike`: `KPROBE / TRACEPOINT / PERF_EVENT / RAW_TRACEPOINT / TRACING / LSM`
- `DatapathLike`: `SCHED_CLS / SCHED_ACT / XDP / SK_SKB / LWT_*`
- `CgroupLike`: 各类 cgroup hook
- 其余为 `Other`

注意：

- v1 不用 `prog_type` 证明 helper 一定可用。
- 真正的 helper 可用性仍交给 REJIT 之后的 verifier。
- `prog_type` 只是用于 policy 选择和审计分级。

## 6. Rewrite 算法

## 6.1 总体流程

建议 `run()` 分成四步：

1. 扫描 `insns`，收集 `RewriteSite` 与 `audit` 命中。
2. 对 `deny/coarseify` 站点构造替换计划。
3. 如果存在可删参数准备窗口，走一次 rebuild，生成 `addr_map` 并修正 branch。
4. 记录 `PassResult`：
   - 改写站点进入 `sites_applied`
   - 纯审计站点进入 `sites_skipped`
   - audit summary 放进 `diagnostics`

## 6.2 Fail-Closed Stub

### 6.2.1 基本规则

对以下 helper：

- `send_signal` (`109`)
- `override_return` (`58`)
- `set_retval` (`187`)

把原来的：

```text
call helper_id
```

改成：

```text
mov64 r0, -1
```

即：

```rust
BpfInsn::mov64_imm(0, -1)
```

原因：

- `-1` 在 Linux errno 语义里就是 `-EPERM`
- 这是单条指令，和原 `call` 同宽
- 后续若存在 `if r0 != 0 goto err`、`if r0 < 0 goto err` 之类错误检查，仍能自然落到 fail path

### 6.2.2 为什么不能直接改成 NOP

不能把 `call` 直接删掉或改成 `ja +0`，因为：

1. helper call 定义了 `r0`
2. 后续代码很可能立刻分支检查 `r0`
3. 裸 NOP 会让后继指令读取旧 `r0`

所以 fail-closed 必须显式写 `r0`。

### 6.2.3 `r0` 被后续检查时的语义

典型例子：

```text
call 109
if r0 != 0 goto err
...
```

改写后：

```text
mov64 r0, -1
if r0 != 0 goto err
...
```

结果是程序稳定走错误分支；这就是期望的 fail-closed 行为。

### 6.2.4 `set_retval` 的特殊 caveat

`set_retval` 与 `send_signal` / `override_return` 不同，它的危险性来自 helper 的副作用，而不是 helper 返回值本身。

例如 UAPI 文档明确给出了这种模式：

```c
bpf_set_retval(-EPERM);
return 1;
```

如果仅把 helper 改成：

```text
mov64 r0, -1
```

那么：

- helper 的“写最终返回值”副作用被中和了
- 但程序后面如果继续 `return 1`，整个 cgroup hook 未必 fail-closed

因此 v1 设计应明确：

1. `set_retval -> mov64 r0, -1` 只保证中和危险 helper primitive。
2. 它不保证“整个程序最终一定拒绝”。
3. 若扫描发现 `set_retval` 后 helper 返回值未被检查，pass 应追加高优先级审计诊断。
4. 真正的“强制整程序 fail-closed”要到 Phase 2 再做 CFG-aware exit rewrite。

这不是实现 bug，而是 `set_retval` 语义本身决定的限制。

## 6.3 Coarseify

### 6.3.1 基本规则

对：

- `ktime_get_ns` (`5`)

把：

```text
call 5
```

改成：

```text
call 160
```

即：

- `imm: 5 -> 160`
- `code/off/regs` 原样保持

### 6.3.2 为什么这是安全替换

设计上依赖两条事实：

1. `ktime_get_ns` 与 `ktime_get_coarse_ns` 都是无参数 helper。
2. 两者返回值都是 `u64` scalar。

因此 coarseify 不需要改参数准备，也不会改变后续对 `r0` 的类型假设。

### 6.3.3 `prog_type` 与 coarseify

v1 不试图在 daemon 里维护一份完整 helper availability matrix。建议策略是：

- 对已知 profile 默认执行 coarseify。
- 对 `prog_type == 0` 或 operator 明确要求保守模式时，降级成 `audit`。
- 最终接受性仍以 REJIT verifier 为准。

## 6.4 Audit-Only

对 audit-only helper，pass 不改字节码。

建议行为：

1. 记录一个审计事件，包含：
   - `pc`
   - `helper_id`
   - `helper_name`
   - `prog_type`
   - `risk_level`
2. 在当前 pass framework 下，不额外扩展 `PassResult` 结构，直接把 audit 命中编码进：
   - `sites_skipped`
   - `diagnostics`

建议 skip reason 文案类似：

```text
audit-only dangerous helper probe_read_kernel (#113)
```

这样 `cmd_rewrite` 与 server JSON 都能直接看到。

## 6.5 参数准备窗口删除（逻辑上的 NOP out）

### 6.5.1 适用范围

用户要求里提到：对纯副作用 helper，例如 `send_signal`，在 deny 后还应尽量 NOP out 它的参数准备。

v1 建议只对 `send_signal` 开启，原因是：

- 只有一个实参，窗口最容易证明。
- 删除后不影响 replacement 指令。
- `override_return` / `set_retval` 的参数语义更复杂，收益没那么高。

### 6.5.2 安全删除条件

对 `send_signal` 的 deny site，向前回溯单用途参数准备窗口，只有同时满足以下条件才删：

1. 只回溯当前 basic block，不跨 branch target。
2. 只考虑最后一次定义 `r1` 的指令链。
3. 指令必须是无副作用、纯寄存器/常量准备：
   - `mov64_imm`
   - `ldimm64`
   - `mov64_reg`
   - `alu64 add/sub imm` 到同一寄存器
4. 这些定义只服务于该 helper，不被别的活跃用途共享。
5. `liveness` 证明这些定义在 `call_pc + 1` 之后不再活跃。

不满足任一条件就保守跳过 cleanup，只做 call stub。

### 6.5.3 实现方式

这里虽然用户表述是“NOP out”，但实现上更好的方式不是原位写 NOP，而是：

1. 扫描阶段把这些 setup PC 记入 `cleanup_pcs`
2. rebuild 新指令流时直接省略这些 PC
3. 生成 `addr_map`
4. 调用 `fixup_all_branches()`

这样做比原位 NOP 更好，因为：

- 能安全处理 `ldimm64` 这类 2-slot 指令
- 不会在最终字节码里留下多余 `ja +0`
- 完全复用现有 `bounds_check_merge.rs` / `utils.rs` 风格

语义上它等价于“先 NOP out，再物理清理 NOP”。

### 6.5.4 rebuild 模式

建议重写器沿用如下模式：

- `replacements: BTreeMap<usize, Vec<BpfInsn>>`
- `skip_pcs: HashSet<usize>`
- `addr_map: Vec<usize>`

遍历原始指令流时：

- 若 `pc` 是 helper call 的替换位点，则发射 replacement
- 若 `pc` 在 `skip_pcs`，则跳过
- 否则复制原指令

完成后：

- `fixup_all_branches(&mut new_insns, &old_insns, &addr_map)`
- `program.remap_annotations(&addr_map)`

若没有 cleanup，`deny/coarseify` 都是等宽改写，可以直接原位改并保留注解长度不变。

## 7. Policy Configuration

## 7.1 不建议只做 allowlist/denylist 二元配置

因为本 pass 有三种默认动作：

- `deny`
- `coarseify`
- `audit`

再加上 operator override 还需要 `allow`。所以纯二元 `allowlist/denylist` 不够表达。

建议使用 YAML 显式动作表。

## 7.2 推荐 YAML 结构

建议新增 daemon 级 policy 文件，例如：

```yaml
version: 1

defaults:
  action_by_helper:
    send_signal: deny
    override_return: deny
    set_retval: deny
    ktime_get_ns: coarseify
    probe_read: audit
    probe_read_str: audit
    probe_read_user: audit
    probe_read_kernel: audit
    probe_read_user_str: audit
    probe_read_kernel_str: audit
    d_path: audit
    copy_from_user: audit
    snprintf_btf: audit
    find_vma: audit

prog_type_overrides:
  tracing_like:
    action_by_helper:
      ktime_get_ns: coarseify
  datapath_like:
    action_by_helper:
      skb_store_bytes: audit
      xdp_adjust_head: audit
  cgroup_like:
    action_by_helper:
      set_retval: deny

options:
  cleanup_send_signal_args: true
  conservative_unknown_prog_type: true
```

### 7.2.1 解析规则

建议：

- YAML 中 helper 优先写名字，加载时统一归一化到 `i32 helper_id`
- `prog_type_overrides` 可以先支持 symbolic class，而不是穷举数值
- 内部表示统一成：

```rust
HashMap<i32, HelperAction>
```

## 7.3 规则优先级

建议优先级：

1. `prog_type` override
2. 全局 `defaults.action_by_helper`
3. 内建默认表
4. 未命中的 helper 视为 `allow`

## 7.4 与现有 `PassContext` 的对接

当前 `PassContext.policy` 只有：

- `enabled_passes`
- `disabled_passes`

实现上建议在 `PolicyConfig` 中追加一个专门子结构，例如：

```rust
pub struct DangerousHelperPolicy {
    pub action_by_helper: HashMap<i32, HelperAction>,
    pub prog_type_overrides: HashMap<ProgramClass, HashMap<i32, HelperAction>>,
    pub cleanup_send_signal_args: bool,
    pub conservative_unknown_prog_type: bool,
}
```

然后：

- daemon 启动时加载 YAML
- 归一化后放进 `PassContext.policy`
- `commands.rs` 里复制 `ctx` 时，这些字段随 `local_ctx` 一起带入

## 8. Pass Context Requirements

## 8.1 必需字段

Phase 1 只要求 `PassContext` 至少提供：

1. `prog_type`
2. helper firewall policy

`prog_type` 已经在现有 `PassContext` 里存在，因此这部分无需新建上下文机制。

## 8.2 为什么必须要 `prog_type`

因为同一个 helper 在不同程序类里的语义预期不同：

- `probe_read*` 在 tracing 类程序里是 expected-but-dangerous
- `skb_store_bytes` / `xdp_adjust_head` 在 datapath 程序里才合理
- `set_retval` 明显属于 cgroup / policy 类上下文

因此 `prog_type` 至少影响：

1. 默认 profile 选择
2. 审计等级
3. 是否对 unknown program 保守退化成 `audit`

## 8.3 Phase 1 不必引入的上下文字段

Phase 1 不强制要求 pass 直接拿到：

- `prog_name`
- `attach_type`
- loader provenance
- ELF 签名信息

这些可以留到后续 admission / trusted-loader 设计再加。当前 pass 只靠 `prog_type + helper policy` 就能落地。

## 9. Verifier Acceptance

## 9.1 为什么 fail-closed stub 一般 verifier-friendly

因为本文 Phase 1 真正改写的 helper 都满足：

- 返回值是 scalar/integer
- 不返回 `PTR_TO_*`

因此把：

```text
call helper
```

换成：

```text
mov64 r0, -1
```

在 verifier 看来只是“显式给 `r0` 一个标量常量值”。

## 9.2 为什么 `ktime_get_ns -> ktime_get_coarse_ns` 一般 verifier-friendly

因为两者：

- 参数个数一致：都无参数
- 返回类型一致：都给 `r0` 一个标量时间值

所以后续对 `r0` 的使用不会出现 type mismatch。

## 9.3 边界条件：不要把该套路泛化到所有 helper

这个 stub 模式不能泛化到：

- 返回 pointer 的 helper
- 会触发 verifier 特殊状态变迁的 helper
- packet pointer invalidation helper

例如 `skb_store_bytes` / `xdp_adjust_head` 这类 helper 可能影响 packet pointer proof；对它们简单 `mov r0, -1` 并不构成通用安全设计。因此 Phase 1 只审计它们。

## 9.4 关于 helper call clobber 的说明

helper call 在 BPF ABI 上会消耗 `r1-r5`，而 `mov64 r0, -1` 不会。

这在 Phase 1 可接受，理由是：

1. 合法编译出来的 BPF 程序本就不应跨 helper call 继续依赖 `r1-r5`
2. 本文只对少数 scalar-return helper 做 stub
3. 真正危险的“call 后特殊 verifier 状态” helper 不在 stub 集合内

但这也是为什么本设计不应用于更宽泛 helper 集。

## 10. PassManager 集成与排序

## 10.1 排序要求

`DangerousHelperFirewallPass` 必须放在 canonical pipeline 最后。

原因：

1. 它是安全策略 pass，不是性能优化 pass。
2. 其输出不应再被后续 pass 合并、折叠或重写。
3. 前面的优化 pass 可能会消掉一部分 helper 周围的冗余代码，最后再做 firewall 命中率更高、逻辑更简单。
4. 参数窗口删除会改指令地址；放最后能减少后续 pass 重新建立地址映射的成本。

## 10.2 在 `PASS_REGISTRY` 中的位置

建议把它注册在 `PASS_REGISTRY` 最后一个条目，连 `speculation_barrier` 之后也要排在它后面：

```text
...
branch_flip
speculation_barrier
dangerous_helper_firewall
```

这样：

- 默认 pipeline 中，它自然成为最后一个 pass
- 自定义 `--passes` 选择时，仍保持 canonical order
- 原因是现有 `build_default_pipeline()` 与 `build_pipeline_with_passes()` 都按 `PASS_REGISTRY` 顺序迭代；因此只要 registry 尾部追加一次，就能同时约束两条构造路径

## 10.3 是否默认启用

建议默认启用。

理由：

- `send_signal` / `override_return` / `set_retval` 的 corpus 使用极少
- `audit-only` 规则本身不破坏程序
- `ktime_get_ns -> coarseify` 是安全加固，不是激进语义迁移

若 operator 不希望启用，可继续使用现有 `disabled_passes` 机制关闭整个 pass。

## 11. Test Plan

Phase 1 不需要 VM/kernel 运行测试就能完成核心单元验证。建议全部放在 daemon crate 的 `#[cfg(test)]` 单元测试里。

### 11.1 检测类测试

1. `test_detects_regular_helper_call_only`
   - `src_reg == 0` 的 `call 109` 被识别
   - pseudo-call / kfunc call 不被识别
2. `test_helper_scan_skips_unknown_helper`
   - 非规则表 helper 被忽略
3. `test_scan_handles_ldimm64_width`
   - 扫描不会把 `LD_IMM64` 第二槽当成独立指令

### 11.2 Fail-Closed 测试

4. `test_deny_rewrites_send_signal_to_mov_r0_neg1`
5. `test_deny_rewrites_override_return_to_mov_r0_neg1`
6. `test_deny_rewrites_set_retval_to_mov_r0_neg1`
7. `test_deny_preserves_following_r0_error_check`
   - `call -> if r0 != 0 goto err` 改写后仍能工作

### 11.3 Coarseify 测试

8. `test_coarseify_rewrites_ktime_get_ns_5_to_160`
9. `test_coarseify_preserves_code_regs_off`
   - 只改 `imm`

### 11.4 Audit-Only 测试

10. `test_audit_only_probe_read_kernel_reports_skip_without_change`
11. `test_audit_only_d_path_reports_skip_without_change`

### 11.5 Cleanup / NOP Removal 测试

12. `test_cleanup_removes_single_use_send_signal_arg_setup`
13. `test_cleanup_does_not_cross_branch_target`
14. `test_cleanup_does_not_remove_live_arg_setup`
15. `test_cleanup_handles_ldimm64_as_two_slot_delete`

### 11.6 Policy 测试

16. `test_policy_override_allows_helper`
17. `test_policy_override_changes_ktime_from_coarseify_to_audit`
18. `test_unknown_prog_type_uses_conservative_profile`

### 11.7 Pipeline 集成测试

19. `test_firewall_pass_is_last_in_default_pipeline`
20. `test_pipeline_runs_firewall_after_speculation_barrier_when_requested`

## 12. 已知限制与 Phase 2 扩展

Phase 1 已知限制：

1. `set_retval` 只能中和 helper，不保证整程序一定拒绝。
2. `probe_read*` 只审计，不做保语义降权。
3. `send_signal_thread`、`probe_write_user` 等高危 helper 先只审计。
4. `prog_type` 只用于 profile，不在 daemon 内重建完整 helper availability matrix。

Phase 2 可扩展方向：

1. `set_retval` 的 CFG-aware exit rewrite
2. `probe_read* -> bounded read / dynptr read`
3. `d_path -> safer helper/kfunc` 迁移
4. packet-mutator helper 的 prog_type-aware hard deny
5. 将审计事件升级成结构化 telemetry，而不是复用 `sites_skipped`

## 13. 结论

`DangerousHelperFirewallPass` 的最小可行实现并不复杂：helper 检测只需匹配 regular `BPF_CALL`，真正的字节码改写只覆盖 `send_signal` / `override_return` / `set_retval` / `ktime_get_ns` 四类位点，其余危险 helper 先进入审计面。

这个边界之所以成立，核心是 corpus 数据足够偏斜：最危险的权限 helper 极少，而高频风险面主要是信息读取与高精度计时。于是 Phase 1 可以用很小的实现面拿到很强的安全收益，同时保持 verifier 风险可控、和现有 PassManager/REJIT 流水线兼容。
