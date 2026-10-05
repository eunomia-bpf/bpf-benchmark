# BpfReJIT 隔离/安全机制调研

日期：2026-03-20  
范围：只做调研，不改代码。覆盖本仓库 vendor kernel、上游 Linux 主线、相关硬件机制、软件隔离、现有 kernel patch substrate、以及学术方案。

## Executive Summary

结论先行：

1. **没有哪个现成硬件机制能直接把“用户态生成 arbitrary native code”变成“kernel 只做极小检查就可安全执行”。**
   - `PKU` 只管 **user-mode address 的 data access**，**不影响 instruction fetch**，对 supervisor page 的 protection key 也不起作用；它不适合保护内核 JIT text。
   - `CET`/`IBT`/shadow stack 只能约束一部分控制流劫持，**不证明语义正确**，也不约束错误的 memory access。
   - `MTE` 有价值，但主要是 **arm64 memory-safety defense-in-depth**，不是“native code correctness oracle”。
   - `SGX` / `SEV-SNP` / `TrustZone` 主要解决 **机密性/完整性/平台信任**，**不是**“防止 buggy user JIT 把内核打崩”。

2. **最值得追的方向不是 hardware-only，而是“受限 native code + 小型 kernel checker”。**
   - 最现实的候选是 **site-local SFI / restricted native template checker**。
   - 更有论文味道、且能进一步减内核代码的是 **translation validation / proof-carrying code 的简化版**：用户态给 native bytes，再给 certificate；kernel 只做快速 checker。

3. **已有 kernel text patching 机制是“安装 substrate”，不是“安全 substrate”。**
   - `bpf_arch_text_poke()`、`ftrace`、`livepatch` 都能改 text，但**都不替代 native code safety validation**。
   - 其中 `bpf_arch_text_poke()` 在 x86 上本质是 **5-byte call/jmp/nop patch**，适合 redirection，不适合直接做通用 multi-instruction rewrite。

4. **对 BpfReJIT 当前架构，最佳研究路径是：**
   - 保留 **kernel-owned installation path**：`bpf_jit_binary_pack_alloc()`、staged image、`bpf_func` 指针切换、extable/CFI/retpoline/IBT 等现有内核基础设施；
   - 把更多“选什么 codegen / 生成什么 bytes”移到 userspace；
   - 但 kernel 仍保留一个 **小而 sound 的 site-local checker**，检查用户给出的 native region 是否满足一组严格受限的语义/CFG/寄存器/内存规则。

5. **如果论文目标是“用户态拥有更多 JIT control 且内核代码显著减少”，最有价值的 novelty 组合是：**
   - `userspace optimizer + kernel certificate checker + existing staged install`
   - 而不是 `hardware enclave + user JIT`
   - 也不是 `text_poke/livepatch re-expression`

---

## 1. 当前 BpfReJIT / stock BPF JIT 现状

### 1.1 本仓库 vendor kernel 里的关键事实

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` 的 `do_jit()` 主循环里，BpfReJIT 在 stock switch 前插了 rule hook：
  - `has_active_rules` 为真时，先走 `bpf_jit_apply_prog_rule(...)`
  - 成功后可直接消费多条 BPF insn 并发出替代 native region
- `vendor/linux-framework/kernel/bpf/jit_directives.c` 的 `bpf_prog_jit_recompile()` 是 **完整 staged re-JIT**，不是原地小 patch：
  - 先 snapshot
  - 再全 image recompile
  - 多 subprog 时还要 second pass 处理 pseudo-func/pseudo-call target
  - 最后 commit / rollback
- 当前 recompile path 明确 **不支持 blinded program**：
  - `prog->blinded` 时直接 `-EOPNOTSUPP`
  - 这和文档里的“constant blinding 会打乱 offset”约束一致

### 1.2 当前 JIT image 分配 / 安装方式

- `kernel/bpf/core.c:bpf_jit_binary_pack_alloc()`：
  - 最终 text 位于 **RO+X program pack**
  - JIT 实际写的是独立的 **RW shadow buffer**
  - 结束后用 `bpf_jit_binary_pack_finalize()` copy 到最终 RO+X 位置
- `include/linux/filter.h:bpf_jit_binary_lock_ro()` 仍存在，但 x86 eBPF 主路径现在主要走 pack allocator，而不是“先 RW 再 set_memory_rox()”
- `bpf_jit_binary_alloc()` / pack allocator 都会在 image 前留随机 illegal-insn hole

### 1.3 x86 stock JIT 的现有安全/硬化机制

- **convergence loop**：`do_jit()` 多 pass 直到 `proglen == oldproglen`，说明任何“直接 patch 最终 text”的方案都必须处理 branch displacement / extable / CFI layout
- **constant blinding**：在 `bpf_int_jit_compile()` 开始处可能先重写 BPF insn
- **retpoline / indirect thunk / lfence / IBT**：x86 emitter 已内建
- **CFI / ENDBR / FineIBT hook**：x86 prologue 已显式处理

### 1.4 上游 Linux 主线（按 2026-03-20 检查 torvalds/linux master）

我用 `https://raw.githubusercontent.com/torvalds/linux/master/...` 核对了最新主线：

- upstream `arch/x86/net/bpf_jit_comp.c` 的 `do_jit()` 仍是 **直接进入 switch**，**没有** BpfReJIT 的 rule hook
- upstream 仍使用：
  - `bpf_jit_binary_pack_alloc()`
  - `bpf_jit_binary_pack_finalize()`
  - `bpf_arch_text_poke()`
- upstream x86 JIT 仍有 `emit_prologue()` / IBT / ENDBR / retpoline 逻辑
- 没看到通用 “JIT hook point for user-supplied site rewrite” 的新 substrate

因此：**上游最新主线没有出现能直接承载 BpfReJIT 的新 hook 机制**。现有能复用的主要还是：

1. RO+X JIT image allocator / installer
2. text poke / trampoline patch substrate
3. function-entry patching substrate（ftrace/livepatch）

---

## 2. 评估维度

本文统一用以下维度比较：

- **可行性评分（1-5）**：5 为最现实
- **内核改动估算**：
  - `XS`：<200 LOC
  - `S`：200-800 LOC
  - `M`：0.8-2 kLOC
  - `L`：2-5 kLOC
  - `XL`：>5 kLOC 或需要大范围内核/平台改造
- **安全保证**：
  - `弱`：明显低于当前 validator
  - `中`：只能做 defense-in-depth
  - `中强`：在受限模型下接近当前 validator
  - `强`：理论上可达到或超过当前 validator
- **论文价值**：
  - `低`：更多是 engineering
  - `中`
  - `高`
  - `很高`

---

## 3. Hardware Isolation Mechanisms

### 3.1 总表

| 机制 | 可行性 | 内核改动 | 安全保证 | 性能 | 论文价值 | 结论 |
|---|---:|---:|---|---|---|---|
| Intel PKU | 1/5 | S | 弱 | 低开销 | 中 | 不适合作为 kernel JIT text 安全边界 |
| Intel CET | 2/5 | XS-S | 中偏弱 | 低开销 | 中 | 只能做 CFI/ROP defense-in-depth |
| ARM MTE | 2/5（x86 主线）/ 3/5（arm64 特化） | M-L | 中 | 中低开销 | 中高 | 可做 runtime sandbox 辅助，不能替代 correctness validation |
| Intel SGX | 1/5 | XL | 弱（对 kernel safety） | 高开销/高复杂度 | 中 | 保护 optimizer，不保护 kernel 免受错误 codegen |
| AMD SEV-SNP | 1/5 | XL | 弱（对 kernel safety） | 中高开销 | 低中 | 保护 guest against hypervisor，方向错位 |
| ARM TrustZone | 1/5 | XL | 弱（对 kernel safety） | 平台相关 | 低中 | 需要 secure world 协同，工程太重 |
| SMEP/SMAP | 1/5 | 0 | 弱 | 已有 | 低 | 已是现有基础防线，不能反向复用 |

### 3.2 Intel PKU

**核心判断：不适合。**

Intel SDM 对 protection keys 的语义很明确：

- protection key 只额外控制 **user-mode addresses 的 data access**
- **不影响 instruction fetch**
- **supervisor-mode address 的 protection key 被忽略**

这直接卡死了 PKU 作为 kernel JIT text 安全边界的想法：

1. BPF JIT native code 最终运行在 **kernel/supervisor text**，PKU 不覆盖它
2. 即便把 code 先放 user page，PKU 也**不能阻止执行**，因为 instruction fetch 不看 PKU
3. 内核本来就靠 `SMEP` 防止执行 user page；要“反过来”让 kernel 安全执行 user page，本质是在推翻现有隔离模型

PKU 最多能做的只是：

- 保护 userspace 里的临时 code buffer / certificate buffer
- 让同一 userspace 进程内的优化器和其他逻辑隔离得更细

但这只是在 **用户态内部做 compartmentalization**，对“kernel 能否信任这些 native bytes”几乎没帮助。

**评分**：

- 可行性：`1/5`
- 内核改动：`S`
- 安全保证：`弱`
- 论文价值：`中`

### 3.3 Intel CET

**核心判断：有用，但只能做 defense-in-depth。**

CET 提供两类东西：

- shadow stack：保护 return edge
- IBT：间接跳转目标必须落到 `ENDBR`

Linux x86 文档也明确 CET 包含 shadow stack 和 IBT；目前 64-bit kernel 侧主要支持 **kernel IBT** 与 **userspace shadow stack**。

如果 BPF JIT text 也满足 CET/IBT 约束，能得到的好处是：

- 减少一部分 ROP/JOP 式控制流劫持面
- 让 trampoline / indirect target 更规范

但它**不能**保证：

- 生成的 native code 与原始 BPF 语义等价
- memory access 仍然 bounded/safe
- code 不会 clobber 错误寄存器
- site 内 CFG 不会逃逸

也就是说，CET **不能替代当前 validator**。它最多让“validator 漏掉 bug 后的 exploitability”下降。

对 BpfReJIT 更现实的定位是：

- 作为 **附加约束**：要求用户态生成的 code 不引入新的 indirect target，或 target 必须带 `ENDBR`
- 不是主安全模型

**评分**：

- 可行性：`2/5`
- 内核改动：`XS-S`
- 安全保证：`中偏弱`
- 论文价值：`中`

### 3.4 ARM MTE

**核心判断：值得关注，但更像 runtime fault containment，不是 native-code proof。**

MTE 给每个 16-byte granule 一个 tag，CPU 在 memory access 时比较 pointer tag 与 allocation tag。Linux 文档里也明确：

- `PROT_MTE` 面向 **userspace**
- mismatch 触发 sync/async fault

它对 JIT 安全的帮助主要是：

1. **检测越界/悬挂指针类 memory bug**
2. 如果把 eBPF/native code 放进隔离 memory domain，能降低某些内存破坏的 blast radius

但 MTE 依然**不证明**：

- control flow 合法
- native semantics 与 BPF semantics 一致
- 禁止调用任意 kernel helper / 任意 branch escape

最有价值的参考是 **SafeBPF (2024)**：它明确探索了

- 纯软件 SFI
- 以及基于 ARM MTE 的 hardware-assisted defense-in-depth

这说明 MTE 很适合做 **“运行时隔离增强”**，但不适合做 **“把 validator 删除掉”** 的唯一替代。

对 BpfReJIT 的现实意义：

- 如果以后认真做 arm64 分支，MTE 可以成为 **辅助 runtime sandbox**
- 但在当前 x86 主战场里，不是主路线

**评分**：

- 可行性：`2/5`（当前 x86 主线）
- 可行性：`3/5`（若单做 arm64 研究分支）
- 内核改动：`M-L`
- 安全保证：`中`
- 论文价值：`中高`

### 3.5 Intel SGX

**核心判断：方向错位。**

把 userspace optimizer / code generator 放进 enclave，最多证明：

- host / other processes 不容易篡改 optimizer
- 可以给 optimization policy / profile data 一点保密性

但你真正需要的是：

- **kernel 不被错误 native code 伤害**

SGX 不会自动给这个性质。就算 optimizer 在 enclave 里，生成出来的 native bytes 仍可能是错的；kernel 仍然要验证。  
而且 SGX 还带来：

- enclave runtime / EDMM / page permission / attestation 复杂度
- 性能损耗
- 生态维护成本

Intel 的 SGX Enclave Memory Manager 甚至明确把 **dynamic code loader / JIT compiler** 视作复杂 runtime 用户之一，这进一步说明它解决的是“如何在 enclave 里支持 JIT”，不是“如何让 kernel 信任 JIT 结果”。

**评分**：

- 可行性：`1/5`
- 内核改动：`XL`
- 安全保证：`弱`
- 论文价值：`中`

### 3.6 AMD SEV / SEV-SNP

**核心判断：同样方向错位。**

SEV-SNP 的目标是：

- guest memory confidentiality
- 以及比 SEV/SEV-ES 更强的 integrity / attestation
- 保护 guest 免受 malicious hypervisor 影响

这很适合 cloud confidential computing，但 BpfReJIT 面对的问题是：

- **同一个 kernel 是否能安全安装并运行用户引导生成的 native code**

SEV-SNP 保护的是 **VM boundary**，不是 **kernel 内部 JIT boundary**。  
除非你把整个 optimizer/JIT 放进单独 confidential VM，再通过某种 attested channel 向宿主 kernel 交付 code/certificate；但这样：

- 架构极重
- 部署复杂
- 仍然没有绕开最终的 kernel-side code validation

**评分**：

- 可行性：`1/5`
- 内核改动：`XL`
- 安全保证：`弱`
- 论文价值：`低中`

### 3.7 ARM TrustZone

**核心判断：比 SGX/SEV 更重，更不贴近 Linux server BPF JIT 的现实路径。**

TrustZone/TEE 更像 platform partition：

- secure world 负责敏感逻辑
- normal world 跑 Linux

它适合做：

- key management
- attestation
- secure monitor / trusted service

不适合做：

- 高频、细粒度、与 Linux BPF JIT 深耦合的 online native code optimization

你当然可以把 optimizer 放 secure world，但和 SGX 一样，它不证明生成 code 的正确性；最终 normal world kernel 还是得验证。

**评分**：

- 可行性：`1/5`
- 内核改动：`XL`
- 安全保证：`弱`
- 论文价值：`低中`

### 3.8 SMEP / SMAP

**核心判断：已有基础防线，不是新方案。**

SMEP/SMAP 的语义是：

- kernel 不执行 user page
- kernel 对 user page 的访问更受限

这和 BpfReJIT 的目标相反：你想让 userspace 生成更多 code，但又让 kernel 维持安全。  
SMEP/SMAP 只能告诉你：

- **不要执行 user page**

而不能告诉你：

- “执行这个 userspace 生成但已验证的 code 是安全的”

所以它只能作为为什么“直接执行 user page code”不可行的反证。

**评分**：

- 可行性：`1/5`
- 内核改动：`0`
- 安全保证：`弱`
- 论文价值：`低`

---

## 4. Software Isolation / Verification Mechanisms

### 4.1 总表

| 机制 | 可行性 | 内核改动 | 安全保证 | 性能 | 论文价值 | 结论 |
|---|---:|---:|---|---|---|---|
| Seccomp / Landlock / namespaces | 2/5 | XS（主要 userspace） | 弱 | 低开销 | 低 | 只能围栏 optimizer 进程 |
| 通用 native-code verifier（任意 x86） | 2/5 | XL | 强（理论上） | 中 | 很高 | 太重，可能比当前更大 |
| 受限 site-local SFI / native template checker | 4/5 | M | 中强 | 低中 | 高 | 最现实的主线候选 |
| Translation validation（推荐 site-local，不推荐 whole-program） | 4/5（site-local） | M-L | 强 | 中 | 很高 | 最有论文味道的路线之一 |
| Proof-carrying code / certificate checker | 3/5 | S-M（kernel checker）+ 大量 userspace proof infra | 强 | 低中 | 很高 | 学术强，但 proof 工程重 |

### 4.2 Seccomp / Landlock / namespaces

这类机制只解决：

- optimizer 进程能调用哪些 syscall
- 能访问哪些文件/网络资源
- 能否把攻击面收敛在一个 sandbox 里

Linux 文档本身也说得很清楚：

- seccomp 是 **minimize exposed kernel surface**
- **不是 sandbox 本身**
- Landlock 则是限制 ambient rights

它们的价值是：

- 限制 recompile daemon/optimizer 被攻破后的系统影响
- 降低 userspace policy/compiler 组件的宿主攻击面

但它们**完全不证明 native code 安全**。因此只能是辅助措施。

**评分**：

- 可行性：`2/5`
- 内核改动：`XS`
- 安全保证：`弱`
- 论文价值：`低`

### 4.3 通用 native-code verifier

思路是让 kernel 直接验证用户提交的 x86 native code 是否：

- 语义等价于原 BPF 片段
- 不做非法 memory access
- 不跳出受限 CFG
- 不破坏 ABI / callee-save / stack discipline

**理论上很强，工程上很危险。**

难点：

1. x86 指令集复杂，decoder + CFG + alias + flags 语义都不轻
2. 一旦想验证“语义等价”，复杂度立刻接近 symbolic execution / theorem proving
3. 如果做成通用 validator，**代码量很可能超过当前 6.4k**

NaCl / RockSalt 的经验说明：  
**x86 native code verifier 只有在你强行限制 code shape 时才会 practical。**

所以“通用 native verifier”更像上界，不像可落地主线。

**评分**：

- 可行性：`2/5`
- 内核改动：`XL`
- 安全保证：`强`
- 论文价值：`很高`

### 4.4 受限 site-local SFI / native template checker

这是我认为**最值得认真推进**的方向。

#### 核心思想

不要让 kernel 验证“任意 native code”，而只验证一个**很窄的受限子集**：

- site-local region
- 无外部 call
- 无 syscall / privileged insn
- 只允许很小的 instruction subset
- 只允许验证前声明的 live-in/live-out reg 读写
- memory access 只能是已知 base+offset pattern
- CFG 只能是 fallthrough + 本地短跳 / 固定 skeleton
- 不允许 interior target

这本质上是 **SFI / validator** 的思路，但把粒度缩到 **canonical site**，而不是整个 program。

#### 为什么这条路最现实

1. **和 BpfReJIT 当前 canonical-form 结构天然契合**
   - 当前已有 site boundary、canonical params、interior-edge check
2. **比通用 native verifier 小得多**
   - kernel 只需理解一个小 ISA 子集和局部 CFG 规则
3. **比“当前 kernel 自己 emit 全部 native bytes”更容易减代码**
   - emitter 逻辑可更多转去 userspace
   - kernel 变成 “check + install”
4. **fail-closed 容易设计**
   - 任何一条 checker 不通过就 fallback stock emission

#### 关键挑战

- x86 variable-length decode 仍然要做
- 要定义足够严格、又有优化空间的受限 native DSL
- 对 branch-like form（例如 `BRANCH_FLIP`）仍要限制很死，否则 checker 会膨胀

#### 我建议的最小可行模型

每个 site 提交：

1. native bytes
2. site metadata
   - consumed BPF insn range
   - live-in/live-out regs
   - allowed scratch regs
   - allowed memory bases/offset ranges
   - local CFG skeleton id
3. 可选 certificate
   - 例如每条 native insn 对应的抽象 transfer summary

kernel checker 只验证：

- bytes 可正确 decode
- 每条 insn 在 allowlist
- reg def/use 符合声明
- flags / stack / memory 约束不越界
- CFG 只在本 region 内闭合
- region 的 net effect 与 site contract 匹配

这条路的本质不是“无 validator”，而是把 validator 从：

- `pattern-specific + emitter-specific`

改成：

- `small generic checker + userspace-generated code`

**评分**：

- 可行性：`4/5`
- 内核改动：`M`
- 安全保证：`中强`
- 论文价值：`高`

### 4.5 Translation Validation

**这是第二条最值得追的路线，且论文味更强。**

translation validation 的核心是：

- 不证明整个 compiler 永远正确
- 而是对**每次 compilation 结果**做验证

对 BpfReJIT，最合理的不是 whole-program translation validation，而是：

- **site-local translation validation**
- 或 **per-form symbolic validator**

因为 whole-program 会很重：

- 要处理全程序 CFG / helper calls / subprog / extable / CFI / relocation

而 site-local 版本只需证明：

- 这一小块 native region 与对应 canonical site 语义等价

#### 为什么它比纯 SFI 更强

SFI 主要保证“跑不出去/访问不越界”，  
translation validation 还可以追求“**算得对**”。

#### 最有启发的相关工作

- **Icarus (SOSP 2024)**：用 symbolic meta-execution 证明一个 stub generator **可能生成的所有 stub 都安全**
- 这对 BpfReJIT 很有启发，因为你们的 form emitter 本来就是“小 generator”

可借鉴的两种形态：

1. **online checker**
   - kernel 收到 bytes + certificate
   - 快速检查
2. **offline proof + online small checker**
   - 用户态 solver/symbolic executor 产出 witness
   - kernel 只验证 witness

#### 对 BpfReJIT 的现实落点

最好的切入点不是整个 x86 JIT，而是：

- `ROTATE`
- `BITFIELD_EXTRACT`
- `ENDIAN_FUSION`
- `ADDR_CALC`

这些 site-local、无复杂 CFG、参数空间有限的 forms。

**评分**：

- 可行性：`4/5`（site-local）
- 内核改动：`M-L`
- 安全保证：`强`
- 论文价值：`很高`

### 4.6 Proof-Carrying Code

**这是最“学术正统”的减内核路线。**

思路：

- userspace 生成 native code
- 同时提交 machine-checkable proof / certificate
- kernel 只做 proof checking

优点：

- kernel checker 可以远小于完整 analyzer
- 一旦 proof system 设计得好，安全保证很强

缺点：

- 最大难点不在 kernel，而在 **proof artifact 设计**
- 要定义：
  - 语义模型
  - 证据格式
  - proof generation pipeline
  - 快速 checker

对 BpfReJIT，更现实的不是 full PCC，而是 **PCC-lite**：

- 不要求通用 theorem proof
- 只要求几个局部可检 certificate
  - reg effect summary
  - memory safety summary
  - CFG closure summary
  - site semantic equivalence witness

也就是说，**translation validation + certificate** 本质上已经是 PCC 的实用版。

**评分**：

- 可行性：`3/5`
- 内核改动：`S-M`
- 安全保证：`强`
- 论文价值：`很高`

---

## 5. Existing Kernel Mechanisms for Safe Code Injection

### 5.1 总表

| 机制 | 可行性 | 内核改动 | 安全保证 | 论文价值 | 结论 |
|---|---:|---:|---|---|---|
| `bpf_arch_text_poke()` | 2/5 | XS-S | 弱 | 低 | 好 installer，不是 verifier |
| `ftrace` / `kprobes` | 2/5 | S-M | 弱 | 低 | granularity 不对 |
| `livepatch` | 1/5 | M | 弱 | 低 | 函数级替换，不适合 site rewrite |
| restricted kernel module | 1/5 | XS（core）但扩大 TCB | 弱 | 低中 | 只是把 trust 移到 module |

### 5.2 `bpf_arch_text_poke()`

本地 x86 实现很明确：

- `X86_PATCH_SIZE = 5`
- 只在 old/new `{NOP,CALL,JUMP}` 间切换
- 本质是对固定 patch site 做 5-byte rewrite

这很适合：

- trampoline attach/detach
- tail-call redirection
- 预留 patch pad 上的 call/jmp 切换

不适合直接做：

- 通用 multi-instruction body rewrite
- 任意 site 的 code re-layout

除非你把 BpfReJIT 重新表达成：

- 每个候选 site 预留一个 5-byte detour slot
- detour 到 out-of-line code island / mini-stub

但这样新的问题是：

1. 内核仍要生成并安装 code island
2. 需要 branch-range / extable / CFI 处理
3. 对每个候选 site 预留 patch pad 也会膨胀 JIT layout

所以它是 **可复用安装机制**，不是主安全机制。

**评分**：

- 可行性：`2/5`
- 内核改动：`XS-S`
- 安全保证：`弱`
- 论文价值：`低`

### 5.3 `ftrace` / `kprobes`

`ftrace` 的动态 patching是函数入口级的：

- 基于 `mcount` / `__fentry__`
- 动态在函数开头 call/nop 之间切换

这和 BPF JIT site rewrite 的粒度不匹配：

- 它适合 **function entry redirection**
- 不适合 BPF body 内任意 canonical site

`kprobes`/`optprobes` 虽然可以插到中间位置，但：

- 是 probe/instrumentation substrate
- 语义和性能都不适合作为高频 steady-state rewrite 机制

因此最多只能做：

- debugging / measurement
- 极粗粒度 detour

**评分**：

- 可行性：`2/5`
- 内核改动：`S-M`
- 安全保证：`弱`
- 论文价值：`低`

### 5.4 livepatch

livepatch 文档明确说：

- 它基于 dynamic ftrace
- **只能 patch 可 trace 的函数**
- 且要求 dynamic ftrace 在函数开头

这和 BpfReJIT 的目标完全不匹配：

- 你们要的是 **JIT body 内 site-level rewrite**
- livepatch 是 **function-level replacement**

把整个 BPF prog image 当作“函数”整体替换当然可想象，但 BpfReJIT 已经有：

- staged re-JIT image
- `bpf_func` 切换

livepatch 不会比现有 recompile substrate 更自然。

**评分**：

- 可行性：`1/5`
- 内核改动：`M`
- 安全保证：`弱`
- 论文价值：`低`

### 5.5 kernel module with restricted capabilities

这个方向的诱惑是：

- 把复杂 emitter / optimizer 挪到 module
- 主 kernel core 改动变少

但问题是：

1. **Linux 没有成熟的“module 只能调用白名单 API”安全模型**
2. 一旦 module 在 ring 0，TCB 其实比当前还大
3. 从论文视角，这只是把“信任用户态”改成“信任外置 kernel module”

也就是说，**代码位置变了，安全问题没解决。**

**评分**：

- 可行性：`1/5`
- 内核改动：`XS`（core）但系统 TCB 显著增大
- 安全保证：`弱`
- 论文价值：`低中`

---

## 6. 学术方案与启发

### 6.1 Jitterbug（OSDI 2020）

对 BPF JIT 最直接相关。  
它的价值是：

- 给出精确 JIT correctness spec
- 发现并修复多个真实 BPF JIT bug
- 证明“JIT correctness 可以 formalize”

局限：

- 更偏 **验证已有 kernel JIT**
- 不是“让 kernel 在线接受用户生成 native code”的直接方案

**启发**：  
可把它视为 BpfReJIT form-level translation validation / offline oracle 的强先例。

### 6.2 Formally Verified Native Code Generation in an Effectful JIT（POPL 2023）

这条线直接把 CompCert backend 变成 verified JIT backend。

优点：

- assurance 极强
- 说明“verified JIT”不是空想

缺点：

- 距离 Linux kernel 工程现实较远
- 如果照搬到 BpfReJIT，复杂度会远超一个系统论文 prototype

**启发**：  
不是产品路径，但很适合做“理论上界”和 related work 对比。

### 6.3 HAVM / end-to-end verified rBPF JIT（2024）

这条线的价值在于：

- 它就在 eBPF/rBPF 上
- 还强调了 **end-to-end verification gap**
- 说明“只验证高层 JIT model，不验证实际提取/运行实现”是不够的

局限：

- 面向 IoT / hybrid VM / subset
- 离 Linux x86-64 eBPF production JIT 仍有距离

**启发**：  
如果做 translation-validation / certificate 路线，论文里应主动讨论“verification gap”。

### 6.4 NaCl / RockSalt / SFI

这是最像 BpfReJIT 可落地路线的先例。

核心教训：

- x86 native sandbox **不是免费午餐**
- 一旦限制：
  - instruction subset
  - alignment / bundle
  - jump target discipline
  - memory masking
  
  validator 就能 practical

**启发**：  
如果 BpfReJIT 愿意牺牲“任意 native code”的自由，改成“受限 site-local native DSL”，就能把内核 checker 做小。

### 6.5 Icarus（SOSP 2024）

这是我认为最值得借鉴的一个新 work。

关键点：

- 不是验证某一次 stub
- 而是验证 **stub generator 可能生成的全部 stub 都安全**

这和 BpfReJIT 的 canonical form emitter 高度契合：

- 每个 form 本来就是一个小 generator
- 完全可以想象：
  - userspace generator 输出 native bytes
  - offline symbolic tool 产出 certificate
  - kernel online checker 只验证 certificate

**启发**：  
比“把所有 emitter 留在 kernel”更有新意，也比“通用 native verifier”更可落地。

### 6.6 SafeBPF（2024）

它最重要的贡献不是“证明用户 native code 可安全注入 kernel”，而是：

- 把 eBPF 与 kernel 之间的 blast radius 缩小
- 用 SFI / ARM MTE 做 defense-in-depth

**启发**：

- 硬件辅助 isolation 最合理的用法，是 **降低 exploitability / containment**
- 不是取代 correctness validation

---

## 7. 最终排序与推荐路线

### 7.1 我建议优先考虑的方案

#### 方案 A：受限 site-local native checker

**推荐度：最高**

形态：

- userspace 负责更大部分 code generation
- kernel 不再自己实现大 emitter
- kernel 只实现：
  - 小 decoder
  - allowlisted insn checker
  - reg/memory/CFG effect checker
  - existing staged image install

优点：

- kernel LOC 下降空间真实
- fail-closed 容易
- 能比较自然地承接当前 canonical-form 设计

缺点：

- 仍需要一个 sound checker
- `BRANCH_FLIP` 这类复杂 CFG form 需要更窄的子集或继续 kernel-owned

#### 方案 B：site-local translation validation / certificate checker

**推荐度：很高**

形态：

- 用户态生成 native bytes
- 同时提交 witness / certificate
- kernel checker 验证 bytes 与 canonical site contract 等价

优点：

- 安全保证比纯 SFI 更强
- 论文 novelty 非常好

缺点：

- toolchain / proof artifact 设计复杂

#### 方案 C：PCC-lite

**推荐度：中高**

形态：

- 不搞 full theorem proof
- 只搞几个快速可检 certificate

适合作为 B 的工程化版本。

### 7.2 不推荐作为主线的方案

- `PKU-only`
- `CET-only`
- `SGX/SEV/TrustZone`
- `livepatch/ftrace 重表达`
- `restricted kernel module`

这些方案要么：

- 解决的是错的问题
- 要么只是安装机制
- 要么只是把 trust 挪位置

### 7.3 我认为最合理的最终架构

如果目标是“**让 userspace 拥有更多 JIT control，同时显著减少 kernel emitter/validator 代码**”，我建议的落点是：

1. **保留 kernel 对最终执行路径的 ownership**
   - 仍由 kernel 分配 RO+X image
   - 仍由 kernel commit / rollback
   - 仍用现有 extable / CFI / retpoline / IBT substrate

2. **把 userspace 提升为 code producer**
   - 不只是 policy selector
   - 而是 site-local native bytes producer

3. **kernel 改成 certificate checker**
   - 不再维护大 form emitter
   - 只维护小而 sound 的 checker

4. **复杂 form 分层**
   - 简单 straight-line forms：走 userspace-native + checker
   - 复杂 CFG forms（如 `BRANCH_FLIP`）：短期保留 kernel-owned，或要求更严格 skeleton

5. **可选 defense-in-depth**
   - optimizer 进程加 seccomp/Landlock/ns
   - x86 上继续吃 CET/IBT
   - arm64 分支可探索 MTE 辅助 containment

---

## 8. 对论文 novelty 的判断

如果论文想站住脚，最强叙事不是：

- “我们用了 PKU/CET/MTE”

因为这更像 feature engineering。

更强的叙事是：

1. **把 kernel JIT 从 emitter 退化成 certificate checker**
2. **把 safety/optimization 分离进一步推进到 safety/codegen 分离**
3. **在 kernel 内只保留 small trusted checker，而把大部分 code synthesis 移到 userspace**
4. **用 site-local translation validation / PCC-lite 维持 fail-closed**

这比当前 BpfReJIT 更进一步，因为它不只分离：

- safety vs optimization policy

而是进一步分离：

- safety checking vs native code synthesis

这条线的 novelty 明显高于“重写成 livepatch”或“加一个 enclave”。

---

## 9. 最终建议

### 9.1 最终结论

**最佳方向不是找一个单独 hardware feature 来替代 validator。**

最佳方向是：

- **受限 native code**
- **小型 kernel checker**
- **复用现有 JIT image/install substrate**
- **必要时加 certificate / translation-validation witness**

### 9.2 推荐优先级

1. **受限 site-local native checker**  
   可行性最高，最像真正能把 kernel emitter 大幅裁掉的工程路线。

2. **site-local translation validation / certificate checker**  
   论文价值最高，且可和 1 组合。

3. **PCC-lite**  
   作为 2 的工程化落点。

4. **MTE-assisted runtime containment（仅 arm64 分支）**  
   适合作为辅助手段，不是主安全模型。

### 9.3 一句话判断各方向

- **PKU/CET/MTE**：只能增强，不能替代验证
- **SGX/SEV/TrustZone**：保护错了对象
- **text_poke/ftrace/livepatch**：是 patch substrate，不是 safety substrate
- **restricted module**：只是换了 TCB 位置
- **site-local SFI / translation validation / PCC-lite**：才是真正能同时满足“减内核代码”和“保住 fail-closed”的主线

---

## Sources

### Local code / docs

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/emitter_cost_and_branchflip_analysis_20260320.md`
- `docs/tmp/verifier_extension_research_20260320.md`
- `docs/tmp/precompute_inject_research_20260320.md`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/include/linux/filter.h`
- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `vendor/linux-framework/Documentation/livepatch/livepatch.rst`
- `vendor/linux-framework/Documentation/trace/ftrace.rst`
- `vendor/linux-framework/Documentation/userspace-api/seccomp_filter.rst`
- `vendor/linux-framework/Documentation/userspace-api/landlock.rst`

### Upstream Linux / official docs

- torvalds/linux master raw source, checked on 2026-03-20:
  - `https://raw.githubusercontent.com/torvalds/linux/master/arch/x86/net/bpf_jit_comp.c`
  - `https://raw.githubusercontent.com/torvalds/linux/master/kernel/bpf/core.c`
  - `https://raw.githubusercontent.com/torvalds/linux/master/include/linux/filter.h`
- Intel SDM, protection keys:
  - `https://www.intel.co.jp/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-vol-3a-part-1-manual.pdf`
- Linux CET shadow stack / IBT docs:
  - `https://docs.kernel.org/arch/x86/shstk.html`
- Linux AMD memory encryption docs:
  - `https://docs.kernel.org/arch/x86/amd-memory-encryption.html`
- AMD SEV-SNP attestation overview:
  - `https://www.amd.com/content/dam/amd/en/documents/developer/lss-snp-attestation.pdf`
- Linux arm64 MTE docs:
  - `https://docs.kernel.org/6.2/arm64/memory-tagging-extension.html`
- Arm TrustZone / TEE reference docs:
  - `https://www.arm.com/technologies/trustzone-for-cortex-a/tee-reference-documentation`
- Intel SGX EMM / dynamic memory for enclaves:
  - `https://github.com/intel/confidential-computing.sgx.emm`

### Papers / projects

- Jitterbug / OSDI 2020:
  - `https://www.usenix.org/conference/osdi20/presentation/nelson`
- Formally Verified Native Code Generation in an Effectful JIT / POPL 2023:
  - `https://aurele-barriere.github.io/papers/fmjit.pdf`
- HAVM / verified JIT-accelerated eBPF VM:
  - `https://link.springer.com/chapter/10.1007/978-3-031-65627-9_16`
- Icarus / SOSP 2024:
  - `https://www.cs.utexas.edu/~hovav/dist/icarus.pdf`
- SafeBPF / 2024:
  - `https://arxiv.org/abs/2409.07508`
- vWasm / provably-safe multilingual software sandboxing using WebAssembly:
  - `https://www.usenix.org/publications/loginonline/provably-safe-multilingual-software-sandboxing-using-webassembly`
