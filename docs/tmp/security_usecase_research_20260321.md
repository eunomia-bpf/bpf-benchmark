# BpfReJIT v2 安全 Use Case 调研

日期：2026-03-21  
工作目录：`/home/yunwei37/workspace/bpf-benchmark`  
主题：在 BpfReJIT v2（runtime-transparent BPF program transformation）下，安全方向最值得做哪些 use case

---

## 0. TL;DR

结论先说：

1. **最值得先做的是“危险 helper 防火墙 + exfil sinkholing”**。
2. 这个方向同时满足：
   - **新颖性高**：现有 eBPF 安全系统大多“监控/告警/策略执行”，很少能对**已经 live 的第三方 BPF 程序**做 helper 级别的**运行时重写和中和**。
   - **实现难度低到中**：helper call 是显式语义点，容易做规则化变换；比“理解整段程序是否恶意”容易得多。
   - **实际价值最高**：可以直接中和 `bpf_probe_read_kernel`、`bpf_send_signal`、`bpf_override_return`、`bpf_probe_write_user` 等高风险能力，并把 `ringbuf/perf_event_output/map exfil` 导到黑洞。
   - **最能体现 BpfReJIT v2 的差异化能力**：不是“旁路监控”，而是**读 live bytecode -> 改字节码 -> verifier 复验 -> 原子替换 live 程序**。

建议优先级：

- **P0**：危险 helper 防火墙 + exfil sinkholing
- **P1**：恶意 BPF 程序检测和阻断；BPF 程序漏洞热修复；权限收紧
- **P2**：完整性保护；行为审计/合规；动态安全策略执行
- **P3**：Spectre 缓解注入；容器级 BPF 隔离

---

## 1. 研究基线与前提

本报告建立在本地已有调研结论之上：

- `docs/tmp/bpf_prog_rewrite_kernel_research_20260321.md`
- `docs/tmp/transparent_replacement_feasibility_20260321.md`
- `docs/tmp/inline_kfunc_feasibility_20260321.md`
- `docs/tmp/bpfrejit_v2_design_gaps_20260321.md`

这些结论对安全 use case 很关键：

1. **live xlated bytecode 不能直接当作通用 reload 输入**。因此安全方案不能假设“从 bpftool dump 出来再改再 load”就够了。
2. **终局方案必须基于 kernel-owned original snapshot + reverify + 原子 JIT image swap**，否则很难做到“runtime transparent”。
3. **vendor tree 已经有一半 inline kfunc 基础设施**，因此“把危险 helper 改写成安全 inline kfunc / no-op kfunc / sinkhole kfunc”是现实路线，而不是纯概念。
4. **现有 `BPF_PROG_JIT_RECOMPILE` 路径已经证明 same-object image swap 是可行的**，这让安全变换可以做到：
   - 不换 `prog_fd` / `prog_id`
   - 不做 dettach + reattach
   - steady state 几乎没有额外 trampoline 开销

也就是说，BpfReJIT v2 的安全价值不在“再做一个 Tetragon/Tracee”，而在：

- **对已经 live 的 BPF 程序做主动、精细、原地、可回滚的安全改写。**

---

## 2. 为什么现在值得做 BPF 安全

截至 **2026-03-21**，近两年的公开 CVE 和研究都说明一件事：**BPF verifier / JIT / LSM / tail call / helper 语义边界仍持续出现安全缺口**，而现有防御大多停在 admission-time、旁路观测、或大改内核执行架构。

这正好给了 BpfReJIT v2 一个独特位置：

- 不是只做 load-time 控制；
- 不是只做旁路告警；
- 不是必须重构 BPF runtime；
- 而是用**运行时透明字节码变换**做安全收缩、补丁、审计和隔离。

---

## 3. 近期相关 CVE、上游 patch、论文、项目

### 3.1 近期 BPF 安全 CVE / 上游 patch

| CVE | 发布时间 | 问题摘要 | 上游 patch | 对本课题的意义 |
| --- | --- | --- | --- | --- |
| [CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163) | 2024-05 NVD 更新 | verifier pruning 错误，可能导致 arbitrary read/write、提权、container escape | [71b547f56124](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=71b547f561247897a0a14f3082730156c0533fed) | 说明“已通过 verifier”不等于绝对安全，支撑“恶意检测/阻断”和“热修复” |
| [CVE-2023-53024](https://nvd.nist.gov/vuln/detail/CVE-2023-53024) | 2025-03-27 | 不充分的 speculative store bypass 缓解导致 pointer leak；修复涉及 `lfence` 类屏障 | [01bdcc73dbe7](https://git.kernel.org/stable/c/01bdcc73dbe7be3ad4d4ee9a59b71e42f461a528) | 直接支撑“Spectre 缓解注入” |
| [CVE-2024-42067](https://nvd.nist.gov/vuln/detail/CVE-2024-42067) | 2024-07-29 | `set_memory_rox()` 失败时 JIT 内存可能保持未保护状态 | [044da7ae7afd](https://git.kernel.org/stable/c/044da7ae7afd4ef60806d73654a2e6a79aa4ed7a) | 直接支撑“BPF 程序完整性保护” |
| [CVE-2024-47703](https://nvd.nist.gov/vuln/detail/CVE-2024-47703) | 2024-10-21 | BPF LSM 返回值校验缺失，正值返回可触发 panic | [1050727d83e7](https://git.kernel.org/stable/c/1050727d83e70449991c29dd1cf29fe936a63da3) | 说明 hook-specific 语义漏洞真实存在，支撑“热修复”“动态策略执行” |
| [CVE-2024-50063](https://nvd.nist.gov/vuln/detail/CVE-2024-50063) | 2024-10-21 | 不同 hook 之间的 tail call 可绕过 ctx/return-value 假设 | [28ead3eaabc1](https://git.kernel.org/stable/c/28ead3eaabc16ecc907cfb71876da028080f6356) | 直接支撑“权限收紧”“热修复”“容器隔离” |
| [CVE-2024-58098](https://nvd.nist.gov/vuln/detail/CVE-2024-58098) | 2025-05-05 | global function 中 helper 对 `changes_pkt_data` 的影响未向上传播，导致 verifier 接受 unsafe program | [1d572c60488b](https://git.kernel.org/stable/c/1d572c60488b52882b719ed273767ee3b280413d) | 直接支撑“危险 helper 防火墙”“热修复” |

观察：

- **2024-2025 仍持续出现 verifier / helper / LSM / tail call 相关缺陷**。
- 这意味着“只靠 admission-time verifier”并不足够。
- **runtime-side BPF neutralization / policy tightening / hot patch** 有现实需求，不只是 paper idea。

### 3.2 相关论文

| 论文 | 年份 | 结论摘要 | 对我们意味着什么 |
| --- | --- | --- | --- |
| [BeeBox: Hardening BPF against Transient Execution Attacks](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di) | USENIX Security 2024 | 为 BPF 引入针对 transient execution 的 SFI-like sandbox；Katran 平均 overhead 约 20%，而 Linux 当时缓解约 112% | 说明 Spectre/BPF 方向是热点，但 BeeBox 需要 runtime 架构改造；BpfReJIT v2 可做更轻量的“定向 barrier 注入” |
| [MOAT: Towards Safe BPF Kernel Extension](https://www.usenix.org/system/files/usenixsecurity24-lu-hongyi.pdf) | USENIX Security 2024 | 用 Intel MPK 隔离潜在恶意 BPF 程序 | 说明“隔离 BPF”有明确学术价值，但侵入性大；BpfReJIT v2 可走“按程序收权/改写”这条更工程化路线 |
| [SafeBPF: Hardware-assisted Defense-in-depth for eBPF Kernel Extensions](https://tfjmp.org/publications/2024-ccsw.pdf) | CCSW 2024 | 用 SFI / ARM MTE 做 runtime isolation；宏基准最高约 4% overhead | 再次证明“只信 verifier 不够”；但 SafeBPF 改运行时，我们改 live program，本质路线不同 |
| [Cross Container Attacks: The Bewildered eBPF on Clouds](https://www.usenix.org/conference/usenixsecurity23/presentation/he) | USENIX Security 2023 | eBPF 在云容器中引入新攻击面，且可放大到跨容器/跨节点 | 强烈支撑“容器级 BPF 隔离”和“权限收紧” |
| [BPFContain: Fixing the Soft Underbelly of Container Security](https://arxiv.org/abs/2102.06972) | 2021 | 用 eBPF 做容器 confinement | 说明容器隔离已有工作，但重点是用 BPF 防容器，不是防 BPF 本身 |
| [bpfbox: Simple Precise Process Confinement with eBPF](https://github.com/willfindlay/bpfbox) | CCSW 2020 / GitHub | 用 BPF LSM/KRSI 做进程级精细 confinement | 说明“动态安全策略执行”已有先例，但不是对 live BPF 程序自身做 rewrite |
| [VeriFence: Lightweight and Precise Spectre Defenses for Untrusted Linux Kernel Extensions](https://arxiv.org/abs/2405.00078) | 2024 | 面向不可信内核扩展的轻量 Spectre 防御 | 可作为“Spectre 注入”相关对照工作 |
| [BPFflow: Preventing information leaks from eBPF](https://people.cs.vt.edu/djwillia/papers/ebpf25-bpfflow.pdf) | 2025 | 直接聚焦 eBPF 信息泄露防护 | 是“helper 防火墙 + sinkholing”最近的研究邻域，但它不是 runtime transparent live rewrite |

### 3.3 相关 GitHub / 开源项目

#### 防御 / 观测类

- [Tetragon](https://github.com/cilium/tetragon): eBPF-based security observability and runtime enforcement
- [Tracee](https://github.com/aquasecurity/tracee): Linux runtime security and forensics using eBPF
- [KubeArmor](https://kubearmor.com/): 基于 eBPF/LSM 的 runtime security enforcement
- [Pulsar](https://github.com/exein-io/pulsar): 面向 Linux/IoT 的 eBPF runtime security
- [bpfman](https://github.com/bpfman/bpfman): eBPF manager，支持从 OCI image 部署程序

#### 进攻 / offensive PoC 类

- [TripleCross](https://github.com/h3xduck/TripleCross): eBPF rootkit，展示 backdoor / stealth / hijacking
- [ebpfkit](https://github.com/Gui774ume/ebpfkit): eBPF rootkit

核心判断：

- 这些系统说明 **“BPF security 有真实市场和真实攻击面”**。
- 但它们**几乎都不提供**：对**任意已 live 的 BPF 程序**做**字节码级 runtime neutralization**。
- 这正是 BpfReJIT v2 的差异化窗口。

### 3.4 上游文档 / helper 语义

- [BPF Token](https://docs.ebpf.io/linux/concepts/token/): Linux v6.9 起支持把部分 BPF 能力委托给容器/非特权进程。它解决的是**load-time delegation**，不是 **live-program least privilege**。
- [BPF LSM program type](https://docs.ebpf.io/linux/program-type/BPF_PROG_TYPE_LSM/): 支持 `BPF_LSM_MAC` 和 `BPF_LSM_CGROUP`，说明 BPF 已直接进入 enforcement path。
- 风险 helper 文档：
  - [`bpf_probe_read_kernel`](https://docs.ebpf.io/linux/helper-function/bpf_probe_read_kernel/)
  - [`bpf_send_signal`](https://docs.ebpf.io/linux/helper-function/bpf_send_signal/)
  - [`bpf_override_return`](https://docs.ebpf.io/linux/helper-function/bpf_override_return/)
  - [`bpf_probe_write_user`](https://docs.ebpf.io/linux/helper-function/bpf_probe_write_user/)
- JIT hardening 文档：
  - [`bpf_jit_harden`](https://docs.kernel.org/6.8/admin-guide/sysctl/net.html)

这些文档给出的关键信息是：

- `bpf_probe_read_kernel` 明确可读取 kernel memory；
- `bpf_send_signal` 可向当前进程发送信号；
- `bpf_override_return` 可直接改被 probe 函数返回值；
- `bpf_probe_write_user` 文档明确写着**不应拿来实现安全机制**，并提示有 TOCTOU 和 crash 风险。

这几乎天然构成了“危险 helper 列表”的第一版。

---

## 4. BpfReJIT v2 的安全差异化能力

相对于现有工作，BpfReJIT v2 最独特的不是“能看见 BPF”，而是下面这一整套组合能力：

1. **枚举全部 live BPF program**
2. **读取原始 bytecode / canonical rewrite baseline**
3. **在 BPF bytecode 层做任意变换**
4. **重新提交 verifier 验证**
5. **原子替换 live 程序，不换 identity**
6. **注册 inline kfunc，在 JIT 阶段内联安全语义**
7. **运行时 profiling，为策略自动收敛提供反馈**

把这组能力映射到安全语义，就是：

- 能对 BPF 程序做 **live patching**
- 能对 BPF 程序做 **live least-privilege**
- 能对 BPF 程序做 **live neutralization**
- 能对 BPF 程序做 **live attestation + rollback**

这与现有系统的区别：

- `Tetragon/Tracee/KubeArmor/Pulsar`：偏观测、告警、策略执行
- `MOAT/SafeBPF/BeeBox`：偏执行环境隔离/硬化
- `BPF Token/CAP_BPF`：偏 load-time privilege
- **BpfReJIT v2**：偏 **live code transformation**

---

## 5. 9 个安全 use case 逐项分析

## 5.1 恶意 BPF 程序检测和阻断

### 这个 use case 做什么

- 枚举所有 live program，提取风险特征：
  - helper 集合
  - map 类型
  - attach 点
  - tail-call 图
  - kfunc / inline kfunc 使用
  - output sink（ringbuf、perf event、map update）
  - destructive 行为（signal、override return、write user）
- 对高风险程序执行：
  - 替换为 no-op / safe stub
  - 删除危险子路径
  - 把输出 sink 改成黑洞

### 新颖性

- **中高**
- 现有安全产品多是“监控系统行为”，不是“监控并重写 BPF 本身”
- offensive 侧已有 [TripleCross](https://github.com/h3xduck/TripleCross) 和 [ebpfkit](https://github.com/Gui774ume/ebpfkit) 证明“恶意 BPF/根套件”不是空想

### 实现难度

- **中高**
- 真正难点不是替换，而是**判断“恶意”**
- 如果只做规则型 detection（危险 helper + attach 点 + sink 组合），难度可先降到中
- 如果追求语义级恶意分类，难度会明显上升

### 实际价值

- **高**
- 能直接处理：
  - rootkit 风格 BPF
  - 被攻陷控制平面留下的异常 tracing BPF
  - 第三方代理/观测组件装入的超权限程序

### 已有工作

- offensive PoC: [TripleCross](https://github.com/h3xduck/TripleCross), [ebpfkit](https://github.com/Gui774ume/ebpfkit)
- defensive runtime tools: [Tetragon](https://github.com/cilium/tetragon), [Tracee](https://github.com/aquasecurity/tracee), [Pulsar](https://github.com/exein-io/pulsar)
- 但这些系统通常是**围绕 syscall/process/file/network 事件检测**，而不是**对 live BPF 程序本身做 neutralization**

### 我们的优势

- 可以不杀用户态进程，不 detach hook，直接替换同一个 live `struct bpf_prog`
- 可以做 attach-type-aware safe stub：
  - XDP 程序可改成 `XDP_PASS`
  - TC 程序可改成 `TC_ACT_OK` / `TCX_PASS`
  - tracing 程序可改成“只 return 0”
  - LSM 程序可改成“只保守放行或保守拒绝”，取决于 attach 语义
- 可以在保留 benign 部分逻辑的同时，只切掉恶意 helper/sink

### 判断

- **值得做，但作为第一篇/第一个原型不是最优。**
- 更适合作为“helper firewall”做完后的第二阶段。

---

## 5.2 危险 helper 防火墙 + exfil sinkholing

### 这个 use case 做什么

目标是把 helper 视为 **BPF 内部 system call ABI**，对高风险 helper 做运行时防火墙。

第一批候选：

- 读敏感内核数据：
  - [`bpf_probe_read_kernel`](https://docs.ebpf.io/linux/helper-function/bpf_probe_read_kernel/)
  - `bpf_probe_read_kernel_str`
  - tracing/LSM 中的 `bpf_copy_from_user` / `bpf_copy_from_user_task`
- 主动扰动系统：
  - [`bpf_send_signal`](https://docs.ebpf.io/linux/helper-function/bpf_send_signal/)
  - `bpf_send_signal_thread`
  - [`bpf_override_return`](https://docs.ebpf.io/linux/helper-function/bpf_override_return/)
  - [`bpf_probe_write_user`](https://docs.ebpf.io/linux/helper-function/bpf_probe_write_user/)
- 输出/外传 sink：
  - `bpf_perf_event_output`
  - `bpf_ringbuf_output`
  - `bpf_ringbuf_reserve/submit/discard`
  - 某些 `map_update_elem` 到共享 exfil map 的模式

典型变换：

1. **source neutralization**
   - `bpf_probe_read_kernel(dst, n, ptr)` 改写为：
     - 零填充 `dst`
     - 返回 `-EPERM` 或固定错误
     - 或只允许读取白名单结构字段
2. **action neutralization**
   - `bpf_send_signal(sig)` -> no-op + audit counter
   - `bpf_override_return()` -> 固定失败/拒绝
   - `bpf_probe_write_user()` -> 恒定 `-EPERM`
3. **sink sinkholing**
   - `ringbuf/perf output` 改写到黑洞 map/ring
   - 只记录 metadata，不发 payload
   - 直接 drop submit

### 新颖性

- **高**
- 现有 Linux 安全边界大多在：
  - load-time verifier
  - program-type helper allowlist
  - CAP_BPF / token delegation
- 但它们都**不是对“已 live 程序”的 per-program helper policy**
- `BPFflow` 说明“防信息泄露”是研究热点，但 **runtime transparent helper rewrite** 仍然非常少见

### 实现难度

- **低到中**
- 原因：
  - helper call 是显式 opcode 语义点
  - 风险 helper 列表天然可枚举
  - 局部 rewrite 足以完成大量策略
  - verifier 复验路径相对清晰
- 难点主要在：
  - 不同 prog type 的 return/value 兼容性
  - sinkhole 后程序是否还满足功能正确性

### 实际价值

- **最高**
- 直接解决三类真实风险：
  - kernel data exfil
  - 主动系统扰动
  - BPF 自身成为 covert channel
- 对企业用户也好解释：**“把 live BPF 程序里最危险的能力关掉”**

### 已有工作

- helper 官方文档本身已经给出风险线索：
  - `bpf_probe_read_kernel` 可读 kernel memory
  - `bpf_send_signal` 可向当前进程发信号
  - `bpf_override_return` 可覆写目标函数返回
  - `bpf_probe_write_user` 文档明确说**不要用于安全机制**
- 防御产品侧：
  - [Tetragon](https://github.com/cilium/tetragon)
  - [Tracee](https://github.com/aquasecurity/tracee)
  - [KubeArmor](https://kubearmor.com/)
  - [Pulsar](https://github.com/exein-io/pulsar)
- 这些系统更多是在 BPF 之外做检测/执行，不是对**目标 BPF 程序的 helper ABI** 进行 live firewall

### 我们的优势

- **这是最贴合 BpfReJIT v2 的 use case**
- 因为我们可以：
  - 在 bytecode 层识别 helper id
  - 直接把 call 改写成安全 inline kfunc
  - reverify
  - 原子替换 live 程序
- 还能做到：
  - **零 steady-state trampoline 开销**
  - **不改 loader、不重启 agent、不换 prog identity**
  - **按程序、按租户、按 attach 点差异化策略**

### 判断

- **第一优先级，强烈推荐作为 P0。**

---

## 5.3 Spectre 缓解注入（运行时插入 `lfence` / speculation barrier）

### 这个 use case 做什么

- 对高风险 BPF 程序，在关键点插入 barrier：
  - pointer spill / unspill
  - helper 返回后可能形成数据依赖错觉的位置
  - 通过 profiling 标记的高风险路径

### 新颖性

- **中等**
- 这个方向已经有较强相关工作：
  - [BeeBox](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di)
  - [VeriFence](https://arxiv.org/abs/2405.00078)
  - Linux 上游针对 BPF Spectre/SSB 的持续补丁

### 实现难度

- **中等**
- 需要：
  - x86/arm64 特化
  - 精准定位 barrier 插入点
  - 评估 barrier 对吞吐/尾延迟的影响

### 实际价值

- **中高**
- 对多租户、共享内核、允许第三方 BPF 的平台尤其有意义
- 但前提是目标用户真的在意 transient execution 风险

### 已有工作

- [CVE-2023-53024](https://nvd.nist.gov/vuln/detail/CVE-2023-53024): 说明 BPF 侧 Spectre v4 / SSB 缓解并未一次到位
- [BeeBox](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di): 用运行时 sandbox 防 transient execution
- [VeriFence](https://arxiv.org/abs/2405.00078): 面向内核扩展的轻量 Spectre 防御

### 我们的优势

- 无需替换整个 BPF runtime
- 可以**只对高风险 live 程序**插 barrier，而不是全局打开最重缓解
- 可与 profiling 结合，做 selective hardening

### 判断

- **科研价值存在，但不建议先做。**
- 更适合作为第二梯队论文方向，而不是第一版系统。

---

## 5.4 BPF 程序行为审计 / 合规

### 这个 use case 做什么

- 给每个 live BPF 程序输出：
  - attach 点
  - helper / kfunc / map 使用
  - tail-call 图
  - 读写能力标签
  - 风险分级
  - 与声明策略/源码 manifest 的偏差
- 进一步可在程序中注入低成本 audit counter / policy marker

### 新颖性

- **中低**
- 行为观测/审计是拥挤赛道
- 但“**审计 live BPF 程序自身，而不是它观测到的系统事件**”这一点仍有差异化

### 实现难度

- **低到中**
- 很多信息来自静态 program inventory
- 难点在于如何把合规语义建模得足够有说服力

### 实际价值

- **高**
- 对受监管环境、BPF 平台运营侧、第三方 agent 管理尤其有价值

### 已有工作

- [Tetragon](https://github.com/cilium/tetragon), [Tracee](https://github.com/aquasecurity/tracee), [KubeArmor](https://kubearmor.com/), [bpfman](https://github.com/bpfman/bpfman)
- 这些系统会给出 runtime security / inventory / policy，但少有对**实际 live bytecode 权限面**做完整审计

### 我们的优势

- 我们看到的是**实际在跑的程序**，不是源码，不是期望配置
- 可以把审计和 neutralization 打通：
  - 先审计
  - 再自动 shrink 权限或打补丁

### 判断

- **很适合做平台功能，但 paper novelty 不够强。**
- 更像 supporting feature，而不是主打 use case。

---

## 5.5 BPF 程序权限收紧

### 这个 use case 做什么

- 对 live 程序执行 least-privilege rewrite：
  - 删除危险 helper
  - 切断不必要 tail-call 边
  - 把宽松读写变成白名单读写
  - 把 tracing 程序从“读任意 kernel object”收缩为“只能读经过许可的字段/对象”

### 新颖性

- **高**
- 上游已有：
  - [BPF Token](https://docs.ebpf.io/linux/concepts/token/)
  - `CAP_BPF`
  - `BPF_LSM_CGROUP`
- 但这些都是 **load-time / coarse-grained privilege**
- 几乎没有“**对已经 live 的程序做 per-program least privilege rewrite**”

### 实现难度

- **中等**
- 难点是策略推导：
  - 静态规则
  - profile 驱动
  - 用户声明 manifest

### 实际价值

- **高**
- 特别适合：
  - 多租户 BPF 平台
  - 第三方 agent 托管
  - Kubernetes 节点上大量安全/观测 agent 混跑

### 已有工作

- [BPF Token](https://docs.ebpf.io/linux/concepts/token/)
- [BPF LSM](https://docs.ebpf.io/linux/program-type/BPF_PROG_TYPE_LSM/)
- [Cross Container Attacks](https://www.usenix.org/conference/usenixsecurity23/presentation/he)

### 我们的优势

- token 只能决定“是否允许 load 某类程序”
- 我们能决定“**这个已经 live 的具体程序，接下来还能做什么**”
- 这是明显更细粒度、也更贴近实际运营的控制面

### 判断

- **很强的第二梯队方向**
- 可与“危险 helper 防火墙”复用大量实现

---

## 5.6 BPF 程序漏洞热修复（verifier bug 发现后对 live 程序打补丁）

### 这个 use case 做什么

- 在 kernel patch 尚未完全 rollout 前，对已 load 的 live 程序实施缓解：
  - 删除已知危险 pattern
  - 替换危险 helper
  - 限制 tail-call 形态
  - 为特定 hook return 语义补 guard
  - 必要时整段替换为 safe stub

### 新颖性

- **非常高**
- 现有 response 大多是：
  - 升级内核
  - 关闭 unprivileged BPF
  - 禁用某类 agent
- 很少有“**不换对象、不中断业务、直接热补 live BPF**”

### 实现难度

- **高**
- 因为需要：
  - 对具体漏洞机理理解非常扎实
  - 语义 patch 正确
  - 保证 reverify / runtime 行为不回归

### 实际价值

- **非常高**
- 尤其适合云平台和大规模 fleet：
  - kernel patch rollout 慢
  - 业务不能重启
  - 某些 BPF agent 又不能直接停

### 已有工作 / 证据

- [CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163): verifier pruning 失效
- [CVE-2024-58098](https://nvd.nist.gov/vuln/detail/CVE-2024-58098): helper side effect 在 global function 传播失效
- [CVE-2024-50063](https://nvd.nist.gov/vuln/detail/CVE-2024-50063): cross-hook tail call 绕过 verifier 假设
- [CVE-2024-47703](https://nvd.nist.gov/vuln/detail/CVE-2024-47703): BPF LSM return 语义漏洞

### 我们的优势

- 可把“修 kernel bug”拆成两层：
  - **长期**：内核上游修复
  - **短期**：BpfReJIT v2 对 live 程序打补丁/降权/隔离
- 可做“漏洞签名 -> patch recipe -> fleet push”

### 需要强调的边界

- 这不是“替代内核安全更新”
- 而是 **在正式内核修复之前，降低 exploitable live BPF surface**

### 判断

- **论文价值很强，工程价值也强**
- 但第一版落地比 helper firewall 更难

---

## 5.7 容器级 BPF 隔离

### 这个 use case 做什么

- 按 cgroup / container / pod 对 live BPF 程序做隔离：
  - 限定 helper 能力
  - 限定可见对象范围
  - 限定 attach 行为和 tail-call 图
  - 按租户推送不同 rewrite 策略

### 新颖性

- **中等**
- 容器隔离本身不是新题目
- 新的是“**隔离 BPF 本身，而不是只用 BPF 去隔离容器**”

### 实现难度

- **高**
- 原因：
  - 很多 BPF hook 是 node-global，不天然按容器分界
  - 需要把 live program 可靠映射到租户
  - 需要与 token/cgroup attach/namespace 语义配合

### 实际价值

- **中高**
- 在多租户云上有价值
- 但是否能稳定 productize，取决于 attach 点覆盖和租户建模

### 已有工作

- [Cross Container Attacks](https://www.usenix.org/conference/usenixsecurity23/presentation/he)
- [BPFContain](https://arxiv.org/abs/2102.06972)
- [bpfbox](https://github.com/willfindlay/bpfbox)
- [BPF Token](https://docs.ebpf.io/linux/concepts/token/)

### 我们的优势

- 可以在不更改应用 loader 的情况下，对第三方 BPF agent 做租户级 shrink
- 可以把 node-global 程序重写成“只对指定 cgroup 生效”的更保守版本

### 判断

- **方向成立，但落地复杂，优先级不应太高。**

---

## 5.8 BPF 程序完整性保护

### 这个 use case 做什么

- 建立 BPF program integrity chain：
  - 对 canonical original snapshot 做 hash / sign / whitelist
  - 定期比对 live bytecode / helper set / attach metadata
  - 检测被替换、被篡改、被降级的程序
  - 异常时自动 rollback 到 safe image

### 新颖性

- **中高**
- 现有生态更多关注：
  - 如何安全部署 BPF（如 [bpfman](https://github.com/bpfman/bpfman)）
  - 如何给 JIT 开 ROX / hardening（如 `bpf_jit_harden`）
- 但对 **live BPF 自身的持续完整性自愈** 做得不多

### 实现难度

- **中等**
- 难点在于：
  - “何为 canonical image”
  - 如何处理合法 recompile / version drift
  - 如何应对 root 权限对用户态控制面的攻击

### 实际价值

- **高**
- 尤其能保护：
  - 安全 agent 自己的 BPF 程序
  - 多团队共享节点上的关键 datapath / telemetry BPF

### 已有工作

- [`bpf_jit_harden`](https://docs.kernel.org/6.8/admin-guide/sysctl/net.html)
- [CVE-2024-42067](https://nvd.nist.gov/vuln/detail/CVE-2024-42067): JIT memory 保护失败会留完整性缺口
- [bpfman](https://github.com/bpfman/bpfman): 安全部署/管理

### 我们的优势

- 我们不只“发现篡改”，还可以：
  - **原子回滚**
  - **替换成安全 image**
  - **在不换 identity 的情况下恢复**

### 判断

- **很实用，也适合平台 feature**
- paper novelty 高于 audit，但低于 helper firewall / hot patch

---

## 5.9 动态安全策略执行

### 这个 use case 做什么

- 把高层策略编译为 BPF rewrite：
  - incident response 时提升拦截级别
  - suspicious host 上开启更强审计/隔离
  - 低风险 host 上回退到低开销策略
- 这与“加载新的 security BPF 程序”不同，重点是：
  - **对已有 live 程序直接改写**
  - **不增加 steady-state hop**

### 新颖性

- **中高**
- 动态策略系统很多，但“基于 live code rewriting 的动态策略执行”不多

### 实现难度

- **中等**
- 需要策略 DSL、编译器、冲突处理和回滚机制

### 实际价值

- **中高**
- 非常适合 SOC / fleet security / multi-profile deployment

### 已有工作

- [KubeArmor](https://kubearmor.com/)
- [Tetragon](https://github.com/cilium/tetragon)
- [Tracee](https://github.com/aquasecurity/tracee)
- [Pulsar](https://github.com/exein-io/pulsar)

### 我们的优势

- 这些系统通常通过新增/更新自己的 BPF sensors 或 LSM policies 达成策略切换
- 我们的差异在于：
  - **直接改已有程序**
  - **不引入额外 attach 路径**
  - **可以复用 profiling 做自动策略收敛**

### 判断

- **适合做系统完整度，但不如 helper firewall 那样锋利。**

---

## 6. 综合优先级排序

下面的排序综合考虑：

- 新颖性
- 实现难度
- 实际价值
- 与 BpfReJIT v2 差异化能力的贴合度

评分规则：

- 新颖性 / 实际价值：1-5，越高越好
- 难度：1-5，越低越好
- 综合优先级：结合 novelty、value、feasibility 的工程判断，不是机械加权

| 排名 | Use case | 新颖性 | 难度 | 实际价值 | 综合优先级 | 结论 |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | 危险 helper 防火墙 + exfil sinkholing | 5 | 2-3 | 5 | **P0** | **最推荐先做** |
| 2 | 恶意 BPF 程序检测和阻断 | 4 | 3-4 | 5 | **P1** | 很有价值，但判断恶意比 helper rewrite 更难 |
| 3 | BPF 程序漏洞热修复 | 5 | 4-5 | 5 | **P1** | 论文价值很高，但第一版实现难 |
| 4 | BPF 程序权限收紧 | 4 | 3 | 4-5 | **P1** | 与 helper firewall 强耦合，适合第二阶段 |
| 5 | BPF 程序完整性保护 | 4 | 3 | 4 | **P2** | 工程价值高，paper novelty 中上 |
| 6 | BPF 程序行为审计 / 合规 | 2-3 | 2 | 4 | **P2** | 容易做，但赛道拥挤 |
| 7 | 动态安全策略执行 | 3-4 | 3 | 4 | **P2** | 系统完整度好，但不够锋利 |
| 8 | Spectre 缓解注入 | 3 | 3-4 | 3-4 | **P3** | 有研究价值，但已有工作强，且评估复杂 |
| 9 | 容器级 BPF 隔离 | 3 | 4-5 | 3-4 | **P3** | 问题真实，但边界复杂、hook 语义不统一 |

---

## 7. 为什么第一优先级必须是“危险 helper 防火墙 + exfil sinkholing”

这是本报告最明确的推荐结论。

### 7.1 它最能体现 BpfReJIT v2 的独特性

如果只是监控 helper 使用，现有工具就能做一部分。  
真正有差异化的是：

- 把危险 helper **在 live program 里直接换掉**
- 保留无害逻辑
- reverify
- 原子替换

这正是 BpfReJIT v2 的主场。

### 7.2 它的实现路径最短

相比“恶意 BPF 检测”，它不要求先解决语义级分类问题。

第一版完全可以做成规则型系统：

1. 建立 helper 风险等级表
2. 识别 live bytecode 中的 helper call
3. 按策略改写：
   - deny
   - no-op
   - safe shim
   - sinkhole
4. reverify + swap

### 7.3 它的评估也最清晰

可以直接做如下实验：

- benign workloads：
  - Tetragon / Tracee / Falco-like sensors
  - networking datapath（无危险 helper）
- risky workloads / PoC：
  - tracing 程序中使用 `bpf_probe_read_kernel`
  - `bpf_send_signal`
  - `bpf_override_return`
  - `bpf_probe_write_user`
  - output sink exfil

指标可以非常直接：

- 阻断率
- 误杀率
- verifier 接受率
- rewrite/swap 延迟
- steady-state 吞吐开销
- 对 benign 程序功能影响

### 7.4 它天然能扩展出后续方向

helper firewall 做好之后，下面这些几乎都能顺势长出来：

- 权限收紧
- 恶意 BPF 阻断
- 漏洞热修复
- 容器租户级差异化 shrink
- 程序完整性策略

换句话说：

- **helper firewall 不是一个孤立 demo，而是整个安全线的基础设施层。**

---

## 8. 建议的最小可行研究计划

### Phase 1：P0 原型

做一个 **风险 helper 中和器**：

- 支持 helper：
  - `bpf_probe_read_kernel`
  - `bpf_send_signal`
  - `bpf_override_return`
  - `bpf_probe_write_user`
  - `bpf_perf_event_output` / `bpf_ringbuf_output`
- 支持策略：
  - `deny`
  - `nop`
  - `sinkhole`
  - `audit-only`

### Phase 2：按 attach type 生成 safe stub

- XDP / TC / tracing / LSM 分别做正确返回语义
- 保证 block 行为不破坏宿主 hook 语义

### Phase 3：inline kfunc 化

- 用 inline kfunc 承载“安全替代语义”
- 减少额外 helper call 开销
- 形成可扩展安全 ABI

### Phase 4：自动 profile 驱动 least-privilege

- 运行时 profiling
- 根据 helper 实际使用情况自动生成 shrink policy

---

## 9. 最终结论

如果目标是做一条**既有论文新意、又能较快落地、还能真正体现 BpfReJIT v2 差异化价值**的安全线，那么推荐顺序非常明确：

1. **先做“危险 helper 防火墙 + exfil sinkholing”**
2. 再扩展到：
   - 恶意 BPF 程序检测和阻断
   - BPF 程序权限收紧
   - BPF 程序漏洞热修复

不推荐第一步就做：

- 容器级 BPF 隔离
- Spectre 缓解注入

原因不是它们不重要，而是：

- 前者问题边界太大、tenant mapping 太复杂
- 后者已有工作较强、性能评估成本更高

**最终推荐结论：先做“危险 helper 防火墙 + exfil sinkholing”。**

---

## 10. 参考链接

### CVE / Patch

- https://nvd.nist.gov/vuln/detail/CVE-2023-2163
- https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=71b547f561247897a0a14f3082730156c0533fed
- https://nvd.nist.gov/vuln/detail/CVE-2023-53024
- https://git.kernel.org/stable/c/01bdcc73dbe7be3ad4d4ee9a59b71e42f461a528
- https://nvd.nist.gov/vuln/detail/CVE-2024-42067
- https://git.kernel.org/stable/c/044da7ae7afd4ef60806d73654a2e6a79aa4ed7a
- https://nvd.nist.gov/vuln/detail/CVE-2024-47703
- https://git.kernel.org/stable/c/1050727d83e70449991c29dd1cf29fe936a63da3
- https://nvd.nist.gov/vuln/detail/CVE-2024-50063
- https://git.kernel.org/stable/c/28ead3eaabc16ecc907cfb71876da028080f6356
- https://nvd.nist.gov/vuln/detail/CVE-2024-58098
- https://git.kernel.org/stable/c/1d572c60488b52882b719ed273767ee3b280413d

### 论文 / 文档

- https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di
- https://www.usenix.org/system/files/usenixsecurity24-lu-hongyi.pdf
- https://tfjmp.org/publications/2024-ccsw.pdf
- https://www.usenix.org/conference/usenixsecurity23/presentation/he
- https://arxiv.org/abs/2102.06972
- https://arxiv.org/abs/2405.00078
- https://people.cs.vt.edu/djwillia/papers/ebpf25-bpfflow.pdf
- https://docs.ebpf.io/linux/concepts/token/
- https://docs.ebpf.io/linux/program-type/BPF_PROG_TYPE_LSM/
- https://docs.ebpf.io/linux/helper-function/bpf_probe_read_kernel/
- https://docs.ebpf.io/linux/helper-function/bpf_send_signal/
- https://docs.ebpf.io/linux/helper-function/bpf_override_return/
- https://docs.ebpf.io/linux/helper-function/bpf_probe_write_user/
- https://docs.kernel.org/6.8/admin-guide/sysctl/net.html

### GitHub / 开源项目

- https://github.com/cilium/tetragon
- https://github.com/aquasecurity/tracee
- https://kubearmor.com/
- https://github.com/exein-io/pulsar
- https://github.com/bpfman/bpfman
- https://github.com/h3xduck/TripleCross
- https://github.com/Gui774ume/ebpfkit
- https://github.com/willfindlay/bpfbox
