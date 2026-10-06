# DangerousHelperFirewallPass 实现级设计（2026-03-26）

基于以下输入材料：

- `docs/tmp/20260326/dangerous_helper_firewall_research_20260326.md`
- `docs/tmp/20260326/corpus_call_statistics_20260326.md`
- `daemon/src/passes/skb_load_bytes.rs`
- `daemon/src/passes/bounds_check_merge.rs`
- `daemon/src/pass.rs`
- `daemon/src/insn.rs`
- `daemon/src/passes/mod.rs`
- `docs/kernel-jit-optimization-plan.md` §3.2

本文描述 `DangerousHelperFirewallPass` 在 BpfReJIT daemon 中的实现级设计。它是 **Security pass**，目标是对 live 程序中的危险 helper 做最小权限化重写，而不是做性能优化。

## 0. 先澄清一个 helper 编号问题

你给出的需求里写了 “`ktime_get_ns` (helper `125`) -> `ktime_get_coarse_ns` (helper `160`)”。按当前仓库中的 `dangerous_helper_firewall.rs` 常量定义，以及 `vendor/linux-framework/include/uapi/linux/bpf.h` 的 helper 编号：

- `ktime_get_ns` = `5`
- `ktime_get_boot_ns` = `125`
- `ktime_get_coarse_ns` = `160`

因此本文按 **仓库/UAPI 当前编号** 设计：

- `ktime_get_ns (5)` 默认 coarseify 到 `ktime_get_coarse_ns (160)`
- `ktime_get_boot_ns (125)` 可作为同类扩展项，默认先 `audit`

如果后续策略希望把 `125` 也 coarseify，可复用同一套动作类型，但它不应在文档里和 `ktime_get_ns` 混写。

## 1. 目标与范围

### 1.1 目标

`DangerousHelperFirewallPass` 需要在 `BpfProgram.insns` 上完成四类动作：

1. 识别 regular helper call：`BPF_CALL + src_reg()==0`
2. 依据 helper 策略执行：
   - `deny / fail-closed`
   - `redaction`
   - `coarseify`
   - `allowlist`
3. 对不能安全改写的站点保守降级到 `audit`
4. 产出可直接进入现有 `PassManager -> REJIT -> re-verify` 流水线的字节码

### 1.2 本文覆盖的最小策略集

按题目要求，Phase 1 最少覆盖：

| helper | id | 默认策略 |
| --- | ---: | --- |
| `send_signal` | 109 | `deny`，返回 `-EPERM` |
| `override_return` | 58 | `deny`，返回 `-EPERM` |
| `probe_read_kernel` | 113 | `redaction`，优先“清零 dst + 返回 `-EFAULT`”，无法证明安全时降级 `audit` |
| `ktime_get_ns` | 5 | `coarseify` 到 helper `160` |
| `skb_store_bytes` | 9 | 仅允许 `XDP/TC/LWT`，其余 `deny` |

同一机制自然可扩展到：

- `send_signal_thread (117)`：与 `send_signal` 同类
- `set_retval (187)`：与 `override_return` 同类，但需要额外语义注记
- `ktime_get_boot_ns (125)`：与 `ktime_get_ns` 同类
- `probe_read*` 其他 alias：与 `probe_read_kernel` 同类

### 1.3 非目标

Phase 1 不做以下事情：

- 不直接 patch host kernel 上的 `xlated_prog_insns`
- 不在 pass 里维护完整 verifier helper availability matrix
- 不对所有 memory-writing helper 盲目做 `mov r0, imm`
- 不做“整程序 CFG 级强制 fail path 跳转”作为默认实现
- 不做内核 helper 实现本身的漏洞修复

## 2. 设计依据

研究报告给出了三个直接影响实现边界的事实：

1. `568` 个 `.bpf.o` 对象中扫描到 `91,034` 次真实 helper 调用
2. 严格危险集中，权限/控制流类 helper 很少：`send_signal` `7` 次，`override_return` `3` 次
3. 高频风险面是 `probe_read*` 与时间源 helper，而不是 `send_signal`

这意味着 pass 不能只有一种动作：

- 对极少数高危且语义单纯的 helper，适合 `fail-closed`
- 对计时 helper，适合 `coarseify`
- 对信息读取 helper，必须支持 `redaction` 或保守 `audit`
- 对数据面 mutator，必须支持 `prog_type` allowlist

## 3. 与当前 pass 框架的对接方式

### 3.1 Pass 形态

实现形态保持为一个普通 transform pass：

```rust
pub struct DangerousHelperFirewallPass;
```

trait 形态：

```rust
impl BpfPass for DangerousHelperFirewallPass {
    fn name(&self) -> &str { "dangerous_helper_firewall" }
    fn category(&self) -> PassCategory { PassCategory::Security }
    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }
}
```

理由：

- `PassCategory::Security` 已在 `pass.rs` 中存在，语义上与本 pass 完全匹配
- `branch_targets` 用于扩容重写后的分支修正，及可选的参数准备窗口删除
- `liveness` 用于保守删除 deny 站点前的单用途参数准备

### 3.2 PassContext 依赖

当前 `PassContext` 已提供：

- `prog_type`
- `policy`

因此本设计不需要新上下文类型；只需要扩展 `PolicyConfig` 的 helper firewall 子结构。

## 4. Helper 分类系统

### 4.1 推荐的数据结构

建议将“风险类别”和“动作策略”拆开：

```rust
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum HelperRiskClass {
    FailClosed,
    Redaction,
    Coarseify,
    Allowlist,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PolicyAction {
    Allow,
    Audit,
    Deny { errno: i32 },
    Coarseify { replacement_id: i32 },
    Redact {
        errno: i32,
        strategy: RedactionStrategy,
    },
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RedactionStrategy {
    ZeroDstThenFail,
    BoundedReadAlternative,
}

#[derive(Clone, Copy, Debug)]
struct HelperPolicy {
    helper_id: i32,
    helper_name: &'static str,
    risk_class: HelperRiskClass,
    default_action: PolicyAction,
    allowed_prog_types: &'static [u32],
}
```

核心点：

- `risk_class` 解释“为什么危险”
- `default_action` 解释“当前默认怎么做”
- `allowed_prog_types` 只对 `Allowlist` 类 helper 有意义
- `Allow` 不是内建默认结果，而是 override 后才会出现

### 4.2 最小默认策略表

建议内建一份 hardcoded 默认表，安全上 fail-closed；外部配置只做 override。

| helper | id | 风险类 | 默认动作 | 说明 |
| --- | ---: | --- | --- | --- |
| `send_signal` | 109 | `FailClosed` | `Deny { errno: -1 }` | `-EPERM` |
| `override_return` | 58 | `FailClosed` | `Deny { errno: -1 }` | `-EPERM` |
| `probe_read_kernel` | 113 | `Redaction` | `Redact { errno: -14, strategy: ZeroDstThenFail }` | `-EFAULT` |
| `ktime_get_ns` | 5 | `Coarseify` | `Coarseify { replacement_id: 160 }` | `ktime_get_coarse_ns` |
| `skb_store_bytes` | 9 | `Allowlist` | `Deny { errno: -1 }` outside allowlist | 允许集见下 |

`skb_store_bytes` 默认允许的 `prog_type`：

- `BPF_PROG_TYPE_SCHED_CLS = 3`
- `BPF_PROG_TYPE_SCHED_ACT = 4`
- `BPF_PROG_TYPE_XDP = 6`
- `BPF_PROG_TYPE_LWT_IN = 18`
- `BPF_PROG_TYPE_LWT_OUT = 19`
- `BPF_PROG_TYPE_LWT_XMIT = 20`

这里 **不默认包含 `SK_SKB (14)`**，因为题目要求是 “only allow in XDP/TC/LWT”。如果将来要扩大 allowlist，应通过策略 override 显式打开。

### 4.3 为什么默认表必须 hardcoded

推荐模式是：

1. pass 内 hardcoded 一份最小默认表
2. daemon 启动时可加载 YAML/CLI override
3. 如果配置文件缺失、损坏或字段不认识，回退到内建默认表

原因：

- 这是安全 pass，不应因为缺少配置文件而静默放开 helper
- helper 编号、默认 allowlist、返回 errno 应与当前仓库实现一起版本化
- 配置文件更适合做环境差异化，而不是承载唯一真相

## 5. Pattern Detection

### 5.1 通用 helper 检测规则

线性扫描 `program.insns`，识别条件为：

```text
insn.code == (BPF_JMP | BPF_CALL)
insn.src_reg() == 0
helper_id = insn.imm
```

必须显式排除：

- pseudo-call：`src_reg()==BPF_PSEUDO_CALL`
- kfunc call：`src_reg()==BPF_PSEUDO_KFUNC_CALL`
- kinsn packed / sidecar call

这与研究脚本统计口径一致，也和当前 `dangerous_helper_firewall.rs` 的实现风格一致。

### 5.2 通用扫描骨架

扫描逻辑可复用现有 pass 的线性模板：

```rust
let mut pc = 0usize;
while pc < insns.len() {
    let insn = &insns[pc];
    if insn.is_call() && insn.src_reg() == 0 {
        let helper_id = insn.imm;
        // 查策略表
    }
    pc += insn_width(insn);
}
```

其中 `insn_width()` 必须像 `skb_load_bytes.rs` / `bounds_check_merge.rs` 那样正确处理 `LD_IMM64` 的双槽宽度。

### 5.3 `prog_type` 感知

`PassContext.prog_type` 在本 pass 中的用途不是证明 helper 一定可用，而是决定 policy：

- `skb_store_bytes`：是否在 allowlist 内
- `ktime_get_ns`：是否 coarseify，或在未知 `prog_type` 时退化为 audit
- `probe_read_kernel`：是否允许尝试 redaction，或仅记录 audit

推荐做法：

1. 内部仍然用 **精确的 u32 prog_type 值** 做最终判定
2. 配置层允许用逻辑分组名，例如 `datapath_like` / `tracing_like`
3. 载入配置时把分组名展开成精确 `u32` 集合

### 5.4 `probe_read_kernel` 的额外模式匹配

`probe_read_kernel` 与 `send_signal`/`override_return` 不同：它不仅返回 `r0`，还会向 `dst` 写数据。因此它不能只看 helper ID，还必须知道：

- `r1` 是否是可证明安全的目标地址
- `r2` 是否是可证明的有界长度

推荐 Phase 1 只支持 **fp-relative stack dst + 常量长度** 的 redaction 匹配，方法参考 `skb_load_bytes.rs` 的轻量寄存器抽象解释：

```rust
enum RegValue {
    Unknown,
    Ctx,
    Const(i64),
    FpPlusConst(i32),
}
```

对 `probe_read_kernel(dst=r1, len=r2, src=r3)`，只在以下条件满足时做 redaction rewrite：

1. `r1 == FpPlusConst(off)`，且 `off < 0`
2. `r2 == Const(len)`，且 `0 < len <= MAX_REDACT_LEN`
3. `[fp+off, fp+off+len)` 全部在合法 stack 区间内
4. call PC 不是 branch target

否则降级为 `audit`。

这样做的原因很重要：`probe_read_kernel` 常见目标就是 stack buffer。如果只把 call 改成 `mov r0, -EFAULT`，后续可能读取“原本应被 helper 初始化、现在却未初始化”的 stack 区间，导致 verifier 拒绝或语义不稳。

## 6. Rewrite 动作设计

### 6.1 `deny / fail-closed`

#### 6.1.1 默认实现：等宽替换

对 `send_signal (109)`、`override_return (58)`，默认改写为：

```text
call helper
```

替换成：

```text
mov64 r0, -1
```

即：

```rust
BpfInsn::mov64_imm(0, -1)   // -EPERM
```

优点：

- 单条指令，和原 `call` 同宽
- 指令数不变，不需要 branch fixup
- 后续如果已有 `if r0 != 0 goto err` 或 `if r0 < 0 goto err`，会自然进入错误路径

#### 6.1.2 关于题目里的 `JA +N`

题目里写了 “`r0 = -EPERM; JA +N`”。实现上应将其视为 **可选的 Phase 2 CFG 强化模式**，而不是 Phase 1 默认动作。

原因：

1. 插入 `JA +N` 会改变指令数，需要 rebuild + `addr_map` + branch fixup
2. `N` 不是局部常量，必须先证明“哪个块是 helper 的 fail path”
3. 很多程序本来就有 `if r0 != 0 goto err`，再额外插 `JA` 只会复杂化控制流

因此推荐分两档：

- Phase 1 默认：只做 `mov64 r0, -EPERM`
- Phase 2 可选：若识别到紧随 call 的标准错误分支，可做 `mov64 r0, -EPERM` 后直接跳到既有 error block

### 6.2 `coarseify`

对 `ktime_get_ns`：

```text
call 5
```

替换成：

```text
call 160
```

即只改 `imm`：

```rust
let mut insn = old_insns[pc];
insn.imm = 160;
```

不改：

- `code`
- `regs`
- `off`

这是最简单、最稳妥的一类 rewrite。

### 6.3 `redaction` for `probe_read_kernel`

#### 6.3.1 为什么不能一律只做 `mov64 r0, -14`

`mov64 r0, -14` 本身是合法指令，但 **不等于“总是 verifier-safe 的 helper 替身”**。问题不在返回值，而在 helper 的副作用：

- 原 helper 会初始化 `dst` 指向的内存
- 纯 `mov r0, -EFAULT` 不会初始化任何内存
- 若后续代码仍读取该内存，重写后的程序可能触发未初始化 stack 读

因此：

- 对 `send_signal` / `override_return`，单纯 `mov r0, imm` 是合理的
- 对 `probe_read_kernel`，必须使用“带内存语义的 redaction”，或保守退回 `audit`

#### 6.3.2 推荐的 Phase 1 redaction 形态

当检测到 `dst` 是 fp-relative stack 且 `len` 是有界常量时，生成：

1. 若需要，先把 `r0` 置零作为 store 源
2. 向 `[fp+off, fp+off+len)` 写零
3. 最后 `mov64 r0, -14`

语义是：

- 不再泄露真实内核数据
- 但目标 buffer 仍然被初始化为确定值
- 后续代码读取该 buffer 时 verifier 仍可接受
- 返回值明确表示 helper 失败

示意：

```text
call bpf_probe_read_kernel(dst, len, src)
```

改写为：

```text
r0 = 0
*(dst + 0 .. len-1) = 0
r0 = -EFAULT
```

Phase 1 只建议支持小长度、常量长度的 stack redaction，例如 `MAX_REDACT_LEN = 64`。超过上限或目标不是 stack 时，直接降级 `audit`。

#### 6.3.3 `BoundedReadAlternative`

如果将来要做更强的兼容性保留，可把 `RedactionStrategy::BoundedReadAlternative` 留作 Phase 2：

- 例如转成受限的安全读取 helper/kfunc
- 或在已知上下文中转成显式边界检查后的逐字节读取

Phase 1 不建议在没有强上下文证明的情况下实现它。

### 6.4 `allowlist` for `skb_store_bytes`

`skb_store_bytes (9)` 的处理规则：

1. 如果 `prog_type` 属于 `{3,4,6,18,19,20}`，保留原 call
2. 否则阻断，默认改写为：

```rust
BpfInsn::mov64_imm(0, -1)   // -EPERM
```

为什么这类 helper 用 allowlist 而不是纯 deny：

- 它本身是数据面 mutator，在 datapath 程序里经常是合理能力
- 同样的 helper 出现在 tracing/LSM/cgroup 程序里，风险就明显更高

与 `send_signal` 类似，Phase 2 可以增加“直接跳到既有错误块”的强化版 CFG rewrite；Phase 1 默认只做等宽 deny。

## 7. 寄存器 clobber、宽度与分支修正

### 7.1 helper ABI 约束

regular helper call 的 ABI 语义是：

- `r0` 保存返回值
- `r1-r5` 视为 call-clobbered
- `r6-r9` 保持
- `r10` 是 frame pointer

### 7.2 为什么 `mov64 r0, imm` 仍然可行

`mov64 r0, imm` 只显式写 `r0`，不像 helper call 那样“杀死” `r1-r5`。这在本设计中可接受，原因是：

1. 原程序已经通过 verifier，合法程序本来就不能在 helper call 之后继续依赖旧 `r1-r5`
2. 因此把 call 替换成 `mov r0, imm` 不会让合法原程序出现新的真实依赖
3. 对需要更多 scratch 的扩容 rewrite，可以只使用 `r0-r5`，仍然 ABI 兼容

### 7.3 什么时候需要 branch fixup

不需要 branch fixup 的情况：

- `deny` 的等宽 `call -> mov64`
- `coarseify` 的 `imm` 原位替换

需要 branch fixup 的情况：

- `probe_read_kernel` 扩容 redaction
- 插入 `JA +N` 的强化 fail-closed 模式
- 删除 dead 参数准备窗口

实现方式应复用现有 pass 的通用模式：

1. 构造 `replacements` / `deleted_pcs`
2. rebuild 新指令流
3. 生成 `addr_map`
4. 调用 `fixup_all_branches(&mut new_insns, &old_insns, &addr_map)`
5. `program.remap_annotations(&addr_map)`

这与 `skb_load_bytes.rs`、`bounds_check_merge.rs` 的做法一致。

## 8. Verifier 接受性分析

### 8.1 `send_signal` / `override_return`

这两类 helper 适合直接 `mov r0, -EPERM`，原因是：

- 返回值是 scalar
- 不向外部内存写初始化结果
- 不产生 verifier 需要跟踪的 pointer/ref 状态

因此 rewrite 后 verifier 看到的只是“`r0` 被赋成常量错误码”。

### 8.2 `ktime_get_ns -> ktime_get_coarse_ns`

接受性理由：

- 参数个数相同：都是无参数 helper
- 返回类型相同：都是 `u64` scalar in `r0`
- call-clobber 语义相同：仍然是 regular helper call

所以这是最稳的一类 rewrite。

### 8.3 `probe_read_kernel`

这里必须明确写出边界：

- “`MOV r0, -EFAULT` 总是 valid instruction” 这句话成立
- 但“把 memory-writing helper 直接替换成 `MOV r0, -EFAULT` 总是 verifier-safe” 这句话 **不成立**

真正安全的结论应是：

- 若 replacement 同时保留“dst 已初始化”的语义，则通常可接受
- 若做不到，就不能强行 rewrite，必须降级成 `audit`

这也是本文把 `probe_read_kernel` 放到 `Redaction` 类，而不是 `FailClosed` 类的根本原因。

### 8.4 `skb_store_bytes`

对 allowlist 之外的 `skb_store_bytes`，`mov r0, -EPERM` 在 verifier 层面通常可接受，因为：

- 返回值是 scalar
- 原 helper 的 packet mutation 不会在 verifier 中变成“必须发生的初始化副作用”

但语义上仍有一条 caveat：

- 如果原程序根本不检查 `r0`，它可能继续走 success path，只是包没有被修改

所以：

- Phase 1 的最小实现是“阻断 helper primitive”
- 真正的“强制整个程序走 fail path”需要 Phase 2 的 CFG-aware rewrite

## 9. Policy 配置

### 9.1 推荐策略：内建默认表 + 可选 YAML override

推荐顺序：

1. hardcoded 默认表
2. 载入 YAML override
3. 最终生成运行时 `HashMap<i32, EffectiveHelperPolicy>`

理由：

- 没有配置文件时仍然有安全默认值
- 不同部署环境可以微调 allowlist 或审计等级
- pass 内部仍保持 O(1) helper_id 查表

### 9.2 推荐的 `PolicyConfig` 扩展

建议在现有 `PolicyConfig` 中增加：

```rust
pub struct DangerousHelperFirewallConfig {
    pub enabled: bool,
    pub global_audit_mode: bool,
    pub helper_overrides: HashMap<i32, PolicyAction>,
    pub prog_type_overrides: HashMap<u32, HashMap<i32, PolicyAction>>,
    pub unknown_prog_type_fallback_audit: bool,
    pub enable_arg_cleanup: bool,
    pub max_redact_len: u32,
}
```

然后挂到：

```rust
pub struct PolicyConfig {
    pub enabled_passes: Vec<String>,
    pub disabled_passes: Vec<String>,
    pub dangerous_helper_firewall: DangerousHelperFirewallConfig,
}
```

### 9.3 推荐 YAML 结构

```yaml
dangerous_helper_firewall:
  enabled: true
  global_audit_mode: false
  unknown_prog_type_fallback_audit: true
  enable_arg_cleanup: true
  max_redact_len: 64

  helper_overrides:
    109: deny
    58: deny
    113: redact
    5: coarseify:160
    9: allowlist

  prog_type_overrides:
    6:
      9: allow
    3:
      9: allow
    4:
      9: allow
    18:
      9: allow
    19:
      9: allow
    20:
      9: allow
```

语义优先级：

1. `global_audit_mode`
2. `prog_type_overrides`
3. `helper_overrides`
4. hardcoded 默认表
5. 未命中的 helper = `Allow`

### 9.4 CLI 接入建议

当前 CLI 只有 `--passes` / `--list-passes` / `--no-rollback` / `--pgo`。建议新增：

- `--dangerous-helper-policy <path>`
- `--dangerous-helper-audit-only`

语义：

- `--dangerous-helper-policy`：加载 YAML override
- `--dangerous-helper-audit-only`：强制本次运行只做 inventory，不改字节码

## 10. Audit Mode 设计

Audit mode 不是简单“忽略 rewrite”，而是：

1. 仍然跑完整检测和策略决策
2. 计算“本来会执行什么动作”
3. 不修改 `program.insns`
4. 把结果编码进 `PassResult.sites_skipped` 和 `diagnostics`

推荐文案：

- `would_deny dangerous helper send_signal (#109)`
- `would_redact dangerous helper probe_read_kernel (#113)`
- `would_coarseify dangerous helper ktime_get_ns (#5 -> #160)`
- `would_deny disallowed helper skb_store_bytes (#9) for prog_type 5`

这样：

- `rewrite` 子命令能直接看到 policy 命中
- `apply` / `serve` JSON 输出也能直接带出审计结果

## 11. 测试计划

### 11.1 分类与匹配

1. `regular helper` 检测：`src_reg()==0` 才命中
2. pseudo-call / kfunc call 不命中
3. 未列入策略表的 helper 不命中
4. `LD_IMM64` 双槽扫描不串位

### 11.2 `deny`

1. `send_signal` 改为 `mov64 r0, -1`
2. `override_return` 改为 `mov64 r0, -1`
3. 若后继存在 `if r0 != 0 goto err`，rewrite 后仍走错误分支
4. dead 参数准备窗口只在 `liveness + branch_targets` 证明安全时删除

### 11.3 `coarseify`

1. `ktime_get_ns (5)` 改为 `ktime_get_coarse_ns (160)`
2. 只改 `imm`
3. `prog_type==0` 且策略要求保守时，退化为 `audit`

### 11.4 `redaction`

1. `probe_read_kernel` 的 `fp-relative stack + const len` 站点可被 redaction
2. rewrite 后 stack 目标区被写零且 `r0==-EFAULT`
3. call 后读取该 buffer 的程序仍能通过单元级 verifier 预期
4. 非 stack dst 或超长 len 退化为 `audit`

### 11.5 allowlist

1. `skb_store_bytes` 在 `XDP/TC/LWT` 不改写
2. `skb_store_bytes` 在 tracing/其他 `prog_type` 改为 `mov64 r0, -EPERM`
3. allowlist 决策受 YAML override 影响

### 11.6 Audit mode

1. `global_audit_mode=true` 时永不改字节码
2. 但 `sites_skipped` / `diagnostics` 正确反映“would_*”动作

### 11.7 集成测试

1. `dangerous_helper_firewall` 在默认 pipeline 中必须是最后一个 pass
2. 自定义 `--passes` 仍按 canonical order 排在最后
3. 对扩容 rewrite，`fixup_all_branches()` 后跳转目标正确

## 12. Pass 排序与集成建议

### 12.1 结论：放在最后

推荐 `DangerousHelperFirewallPass` 放在 canonical pipeline 最后，理由是：

1. 它是 security pass，不应再被后续优化 pass 改写
2. 其他 pass 先运行，能把 helper 周围的冗余代码、常量传播和死代码先简化掉
3. firewall 最终看到的是“优化后的最终 helper 形态”，命中最准确
4. 扩容 rewrite 或 cleanup 会产生地址映射变化；最后做能减少后续 pass 的重新分析成本

### 12.2 与当前仓库状态

当前 `daemon/src/passes/mod.rs` 已经把 `dangerous_helper_firewall` 放在 `PASS_REGISTRY` 最后，这一排序应保持不变。

## 13. 与当前树内实现的差异

截至当前树内实现，`daemon/src/passes/dangerous_helper_firewall.rs` 已经具备：

- `send_signal` / `override_return` / `send_signal_thread` / `set_retval` 的 deny
- `ktime_get_ns (5) -> ktime_get_coarse_ns (160)` 的 coarseify
- 多种危险 helper 的 `audit`
- 基于 `liveness` 的保守参数清理

但与本文目标设计相比，还缺少：

1. `probe_read_kernel` 的真正 `redaction` rewrite
2. `skb_store_bytes` 的 `prog_type` allowlist enforcement
3. daemon 级 YAML/CLI policy override
4. 全局 audit-only 模式
5. 可选的 Phase 2 `JA +N` CFG 强化模式

因此本文应视为 **DangerousHelperFirewallPass 的 v2 设计文档**：它兼容当前 pass 框架和当前实现风格，但把题目要求的安全语义补全到了真正可落地的实现边界上。

## 14. 最终建议

推荐按以下顺序实现：

1. 保持 pass 末尾排序不变
2. 先补 `PolicyConfig` 扩展和 `global_audit_mode`
3. 补 `skb_store_bytes` 的 `prog_type` allowlist
4. 实现 `probe_read_kernel` 的 `stack-zero + -EFAULT` redaction
5. 将 `JA +N` 留到后续 CFG-aware Phase 2

这样可以先把“helper 分类、配置、allowlist、审计模式”落地，再处理最难的 memory-initialization rewrite。
