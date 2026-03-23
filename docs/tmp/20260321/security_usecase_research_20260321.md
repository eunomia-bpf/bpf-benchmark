# BpfReJIT v2 安全 use case 深度调研

日期: 2026-03-21  
范围: eBPF/BPF verifier 漏洞, 恶意 eBPF 滥用, 上游 hardening, 近 3 年论文, 开源项目, 本地 `vendor/linux-framework` 内核代码, 以及基于 BpfReJIT v2 的安全能力设计  
结论基准: 以“**runtime transparent BPF program transformation**”为核心能力, 重点寻找“**高 novelty + 低实现难度 + 高实际价值**”的方向

## 0. TL;DR

最值得先做的不是“再造一个 BPF 监控工具”, 而是做 **live BPF governor**:

1. **危险 helper/kfunc 防火墙 + exfil sinkholing**
   把已加载程序里的 `bpf_probe_write_user` / `bpf_copy_from_user_task` / `bpf_d_path` / ringbuf/perf-event exfil path 直接重写成安全 wrapper 或黑洞 map。
   这是我认为 **最高优先级** 的方向: 高 novelty, 低到中等难度, 高价值。

2. **防御型 BPF 的完整性自愈**
   给 Tetragon/Tracee/Falco/自研探针建立 baseline 指纹; 一旦被替换、降级、移除, 自动用零开销 image swap 恢复。
   现有 signed BPF / token 主要是 **load-time**; 你们能补上 **live-time** 的自愈闭环。

3. **容器/租户作用域守卫注入**
   给 live 程序入口注入 `cgroup_id` / `netns_cookie` / pidns/userns 守卫, 把“本该只影响容器 A”的程序强制局限在容器 A。
   上游 2023 年的 BPF namespace RFC 被 NACK, 2026 年又出现 namespace hooks patch, 说明社区有需求但没有成熟方案。

4. **BPF 漏洞热修复模板库**
   针对 verifier bug 公开后常见的 exploit pattern, 对 live 程序插入额外 range clamp / bounds check / guard branch, 不等内核升级。
   这类能力我没有找到现成系统在做。

5. **审计 grafting / provenance stamping**
   给任意 live BPF 程序透明植入“谁在跑, 什么时候跑, 调了哪些 helper, 往哪类 map 输出”的审计逻辑。
   现有安全产品主要监控系统事件, 很少“给别人的 BPF 程序本体补审计”。

核心判断:

- **已有工作很多都停在 load-time, monitor-time, 或重新设计执行环境**:
  [BPF LSM/KRSI](https://lkml.rescloud.iu.edu/1912.3/03338.html), [BPF token](https://git.kernel.org/), signed/trusted BPF, [SandBPF](https://arxiv.org/abs/2308.01983), [BeeBox](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di), [MOAT](https://www.usenix.org/conference/usenixsecurity24/presentation/lu-hongyi), [HIVE](https://www.usenix.org/conference/usenixsecurity24/presentation/zhang-peihua), [Tracee](https://github.com/aquasecurity/tracee), [Falco](https://github.com/falcosecurity/falco), [Tetragon](https://github.com/cilium/tetragon)。
- **我没有找到** 一个现成系统能对 **任意已加载 live BPF 程序** 做 **透明字节码重写, 再验证, 原子替换** 来实现安全策略。
- 这意味着 BpfReJIT v2 的最大机会不是“再加一个检测器”, 而是把社区已有需求做成 **runtime remediation plane**。

## 1. 调研方法与限制

- 外部检索覆盖了 NVD/CVE, Google Bug Hunters, ZDI, CrowdStrike, USENIX, FSE, arXiv, GitHub, LPC, 以及 LKML/Spinics 镜像。
- `lore.kernel.org` 的查询页面当前有 anti-bot challenge, 因此 patch/RFC 部分主要用 **LKML/Spinics 镜像** 交叉验证。
- 本地代码树同时被检查, 重点看:
  - `kernel/bpf/core.c`
  - `kernel/bpf/verifier.c`
  - `kernel/bpf/token.c`
  - `kernel/bpf/syscall.c`
  - `kernel/bpf/bpf_lsm.c`
  - `security/bpf/hooks.c`
  - `security/security.c`
  - `arch/x86/net/bpf_jit_comp.c`
  - `Documentation/arch/x86/mds.rst`

## 2. 已知 BPF 安全问题/攻击面

### 2.1 verifier bug 导致的漏洞

eBPF 的核心风险一直都不是“程序能不能跑”, 而是 **verifier 是否真的 sound**。这一点最近几年被反复证明。

| CVE / 工作 | 时间 | 主要问题 | 影响 | 证据 |
|---|---:|---|---|---|
| [CVE-2020-8835](https://www.thezdi.com/blog/2021/5/25/cve-2020-8835-a-15-year-old-ebpf-verifier-vulnerability) | 2020/2021 | 15 年历史的 verifier bug | LPE, arbitrary R/W primitive | ZDI |
| [CVE-2021-31440](https://www.thezdi.com/blog/2021/5/26/cve-2021-31440-an-incorrect-bounds-calculation-in-the-linux-kernel-ebpf-verifier) | 2021 | incorrect bounds calculation | OOB access, root, Kubernetes container escape | ZDI |
| [CVE-2021-3490](https://www.crowdstrike.com/en-us/blog/exploiting-cve-2021-3490-for-container-escapes/) | 2021 | verifier bug 导致 kernel R/W primitive | LPE, container escape | CrowdStrike, exploit repo |
| [CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163) | 2023 | incorrect verifier pruning | arbitrary kernel R/W, LPE, container escape | NVD, Google Bug Hunters |
| [State Embedding / SEV](https://www.usenix.org/conference/osdi24/presentation/sun-hao) | OSDI 2024 | verifier correctness validation新方法 | 1 个月发现 15 个未知 logic bug, 其中 2 个可提权 | USENIX OSDI 2024 |
| [BRFuzz / BRF](https://2024.esec-fse.org/details/fse-2024-research-papers/113/BRF-Fuzzing-the-eBPF-runtime) | FSE 2024 | runtime fuzzing | 找到 6 个 runtime 漏洞, 其中 2 个分配了 CVE | FSE 2024 |

关键事实:

- [CVE-2021-31440](https://www.thezdi.com/blog/2021/5/26/cve-2021-31440-an-incorrect-bounds-calculation-in-the-linux-kernel-ebpf-verifier) 明确演示了 **Kubernetes container escape**。
- [CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163) 的 NVD 描述直接写明: `arbitrary read/write in kernel memory, lateral privilege escalation, and container escape`。
- [Google Bug Hunters 对 CVE-2023-2163 的复盘](https://bughunters.google.com/blog/a-deep-dive-into-cve-2023-2163-how-we-found-and-fixed-an-ebpf-linux-kernel-vulnerability) 再次说明 verifier pruning 仍然是现实攻击面。
- [OSDI 2024 SEV 论文](https://www.usenix.org/system/files/osdi24-sun-hao.pdf) 在一个月内挖出 15 个未知 verifier logic bug, 其中 2 个可利用提权, 说明“verifier 已经足够成熟了”这个前提并不成立。

对 BpfReJIT v2 的含义:

- **BPF 程序本身可以成为 verifier bug 的触发器**。
- 因此“只做 load-time admission control”不够, 因为漏洞披露之后, **系统里已经在跑的程序** 仍可能是触发器。
- 你们的框架天然适合做 **post-disclosure live remediation**。

### 2.2 Spectre / transient execution / JIT spray

#### 已有内核现状

本地内核树已经明确包含多层防护:

- `kernel/bpf/core.c` 中存在 `BPF_ST_NOSPEC()` 路径和 `barrier_nospec()`:
  - `kernel/bpf/core.c:2127-2137`
- verifier 会在某些写路径后自动插入 `BPF_ST_NOSPEC()`:
  - `kernel/bpf/verifier.c:22739-22748`
- 默认启用 Spectre v1/v4 mitigations, 且注释写明:
  - “currently no support for reloading programs that were loaded without mitigations”
  - `kernel/bpf/core.c:3090-3094`
- variable-offset stack pointer 在 unprivileged 下被禁止, 注释直接说明原因是 Spectre masking:
  - `kernel/bpf/verifier.c:5867-5874`
- JIT constant blinding 已存在:
  - `kernel/bpf/core.c:1308-1319`
  - `kernel/bpf/core.c:1497-1525`

另外, x86 文档仍然把 **untrusted BPF** 单独点名为特殊风险:

- `Documentation/arch/x86/mds.rst:65-67`:
  “There is one exception, which is untrusted BPF ...”

#### 研究与未合并工作

- [BeeBox, USENIX Security 2024](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di) 把 BPF runtime 当成 transient execution attack surface, 提出 SFI-like sandbox, 目标是抵御 Spectre-PHT 和 Spectre-STL。
- [VeriFence, LPC 2024](https://lpc.events/event/18/contributions/1954/contribution.pdf) 讨论了“用 speculation barriers 而不是直接拒绝程序”来缓解 Spectre-PHT; 幻灯片显示这还是 **prototype patch set** / `Patch Series Draft`, 并未看到 merged 迹象。

判断:

- “BPF Spectre 问题”不是空谈, 上游和论文都在持续投入。
- 但现有机制大多是 **static/load-time**。
- 你们的机会在于 **runtime selective hardening**:
  - 只给高风险 live 程序注入 barrier
  - 只在告警态开启
  - 过后还原原图像

#### JIT spray / constant blinding

- 本地树已经有 constant blinding (`kernel/bpf/core.c:1308-1319`, `1497-1525`)。
- 这说明社区已经承认“JIT 代码生成本身可被滥用”, 只是当前缓解点在 **JIT 编译阶段**。
- BpfReJIT v2 可以把这一思路推广到 **已加载程序的二次 hardening**。

### 2.3 BPF 程序被滥用: rootkit / keylogging / sniffing / offensive helpers

#### 现实 offensive 样本

- [ebpfkit](https://github.com/Gui774ume/ebpfkit): GitHub 描述是 “ebpfkit is a rootkit powered by eBPF.”
- [TripleCross](https://github.com/h3xduck/TripleCross): GitHub 描述是 “A Linux eBPF rootkit with a backdoor, C2, library injection, execution hijacking, persistence and stealth capabilities.”
- [CrowdStrike 对 CVE-2021-3490 的文章](https://www.crowdstrike.com/en-us/blog/exploiting-cve-2021-3490-for-container-escapes/) 还引用了现成 exploit repo: `chompie1337/Linux_LPE_eBPF_CVE-2021-3490`。

#### 被滥用的 helper / 能力

本地 UAPI 文档本身就暴露了几个“危险但合法”的面:

- `bpf_probe_write_user()`:
  - `include/uapi/linux/bpf.h:2705-2719`
  - 文档明确说 **不应拿它实现安全机制**, 而是实验/调试/操纵执行。
- `bpf_probe_read_user*()` / `bpf_probe_read_kernel*()`:
  - `include/uapi/linux/bpf.h:4269-4284`
- `bpf_d_path()`:
  - `include/uapi/linux/bpf.h:4926-4936`
- `bpf_copy_from_user_task()`:
  - `include/uapi/linux/bpf.h:5577-5585`

这几个能力本身就足以支持:

- keylogging / 用户态敏感数据读取
- 文件路径与执行上下文审计/窃取
- 进程执行劫持或 semi-cooperative tampering
- 低噪声 exfiltration 到 ringbuf/perf-event maps

#### 现有监控项目

- [Tracee](https://github.com/aquasecurity/tracee): Linux Runtime Security and Forensics using eBPF
- [Falco](https://github.com/falcosecurity/falco): Cloud Native Runtime Security
- [Tetragon](https://github.com/cilium/tetragon): eBPF-based Security Observability and Runtime Enforcement

这些项目证明 **“用 eBPF 做安全监控”** 已经很成熟, 但它们的治理对象主要是 **系统事件** 或 **它们自己加载的 BPF 程序**。  
我没有找到它们能对“别的组件已经加载的 arbitrary live BPF 程序”做透明重写和热修复。

### 2.4 已有加固工作

#### BPF LSM / KRSI

- [KRSI 初始 patch 主题](https://lkml.rescloud.iu.edu/1912.3/03338.html): `MAC and Audit policy using eBPF (KRSI)`
- 本地树确认 BPF LSM 已集成:
  - `security/bpf/hooks.c:10-27`
  - `security/security.c:5236-5249` 有 `security_bpf_prog_load()`

判断:

- **KRSI/BPF LSM 已经解决了“加载新的防御程序去监督系统”**。
- 但它**没有**解决“把已经在跑的第三方 BPF 程序改写成更安全版本”。

#### BPF token

本地树 UAPI 和实现都在:

- UAPI 描述:
  - `include/uapi/linux/bpf.h:888-912`
- 实现:
  - `kernel/bpf/token.c:17-27`
  - `kernel/bpf/token.c:112-158`
- LSM hooks:
  - `security/security.c:5274-5318`

判断:

- BPF token 是 **权限委托** 机制。
- 它作用于 **谁可以 load / create / attach**。
- 它不处理 **live program remediation / revocation / rewrite**。

#### Signed / trusted BPF

这部分很关键: **你们当前树里已经有 signed BPF 的 UAPI 和校验路径。**

- `BPF_PROG_LOAD` 的 `signature`, `signature_size`, `keyring_id` 字段:
  - `include/uapi/linux/bpf.h:1640-1649`
- `bpf_prog_verify_signature()`:
  - `kernel/bpf/syscall.c:2808-2848`
- `BPF_PROG_LOAD` 时调用签名校验:
  - `kernel/bpf/syscall.c:3033-3036`
- helper/kfunc:
  - `bpf_verify_pkcs7_signature()`
  - `kernel/bpf/helpers.c:4062-4102`

另外, [BPF LSM 2024 会议材料](https://bpfconf.ebpf.io/bpfconf2024/bpfconf2024_material/BPF_LSM_2024.pdf) 讨论了“trusted BPF”模型:

- 用 `fs-verity`
- 用 xattr 存 loader digest/signature
- 用 `bpf_verify_pkcs7_signature`
- 用 BPF LSM hook 只允许 trusted loader 做 `prog_load` / `map_create` / `token_create`

判断:

- “signed BPF” 已经不再是纯想法, 至少在你们当前 base tree 里已经落地。
- 但它仍然主要是 **load-time integrity**。
- 因此你们最该做的不是重复 signed BPF, 而是做 **runtime integrity rollback / live self-healing**。

#### 审计

- 我没有找到一个独立的、通用的 upstream `bpf audit` 子系统。
- 最接近的是:
  - KRSI/BPF LSM 的 “MAC and Audit policy using eBPF” 起源
  - LSM/audit 基础设施
  - 各类运行时安全产品自己的事件管线

这说明:

- **BPF 审计需求存在**
- 但“审计 arbitrary live BPF program 自身行为”仍缺位

## 3. 上游 patch / RFC 深度搜索结论

> 状态基于 2026-03-21 的公开镜像与本地代码树。由于 `lore.kernel.org` 查询页有 anti-bot challenge, 这里用 LKML/Spinics 镜像交叉验证。

| Patch / RFC | 时间 | 状态 | 内容摘要 | 与 BpfReJIT v2 的关系 |
|---|---:|---|---|---|
| [KRSI: MAC and Audit policy using eBPF](https://lkml.rescloud.iu.edu/1912.3/03338.html) | 2019-12 | **Merged 演化为 BPF LSM** | 让 eBPF 附着到 LSM hook 做 MAC / audit policy | 证明社区要“用 BPF 做安全治理”, 但不是 live rewrite |
| [RFC PATCH bpf-next 00/13: Introduce BPF namespace](https://lkml.iu.edu/2304.0/02230.html) | 2023-03 | **NACK / stale** | 试图给容器内 BPF 可见性与隔离语义 | 强烈证明“容器级 BPF 隔离/可见性”有需求, 但方案不成熟 |
| [PATCH 1/4 ns: add bpf hooks](https://www.spinics.net/lists/cgroups/msg53541.html) | 2026-02 | **In review / unmerged** | 给 namespace lifecycle 暴露 BPF hook, 用于监督 namespace creation/install/free | 说明“namespace-aware BPF security policy”仍是活跃方向 |
| [VeriFence / speculation barriers for eBPF](https://lpc.events/event/18/contributions/1954/contribution.pdf) | 2024-09 | **Prototype / patch draft** | 不直接拒绝程序, 而是在需要处插 speculation barrier | 与“runtime Spectre hardening injection”高度相关 |
| signed/trusted BPF | 2024-2026 | **至少在本地树已存在实现** | `BPF_PROG_LOAD` 支持签名与 keyring 验证 | 你们应补 runtime rollback, 而不是重复 load-time signing |
| BPF token | merged | **Merged** | 委托 BPF 权限到 user namespace | 补不了 live revocation / live transform |

### 3.1 对“merged / rejected / stale”的直接判断

- **BPF namespace RFC**: 明确被 Alexei 直接 `It's a Nack.`  
  这说明“另起 BPF namespace”路线在 2023 年那个形态下被否。
- **namespace hooks patch**: 2026-02 还在 review, 说明 namespace-aware security 需求还在持续。
- **VeriFence**: LPC 材料里仍称 `prototype` / `Patch Series Draft`, 未看到 merged 证据。
- **signed BPF**: 你们当前树里已经有 UAPI + `BPF_PROG_LOAD` 校验路径, 对本项目而言可以视为“已存在的 load-time 机制”。

## 4. 近 3 年论文检索

### 4.1 直接相关的高价值论文

| 论文 | 年份 / venue | 主要点 | 对你的启发 |
|---|---:|---|---|
| [Validating the eBPF Verifier via State Embedding](https://www.usenix.org/conference/osdi24/presentation/sun-hao) | OSDI 2024 | 1 个月发现 15 个 verifier logic bugs, 2 个可提权 | verifier bug 不是历史问题; 热修复有现实意义 |
| [BRF: Fuzzing the eBPF runtime](https://2024.esec-fse.org/details/fse-2024-research-papers/113/BRF-Fuzzing-the-eBPF-runtime) | FSE 2024 | 关注 runtime 而不只是 verifier, 找到 6 个漏洞 | “runtime 面”本身也是攻击面 |
| [BeeBox](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di) | USENIX Security 2024 | 用 SFI-like 方法硬化 BPF 对 transient execution 的抵抗力 | 说明 selective hardening 是有论文需求的 |
| [MOAT](https://www.usenix.org/conference/usenixsecurity24/presentation/lu-hongyi) | USENIX Security 2024 | 用 Intel MPK 隔离潜在恶意 BPF 程序 | 社区认可“隔离优于盲目信任 verifier” |
| [HIVE](https://www.usenix.org/conference/usenixsecurity24/presentation/zhang-peihua) | USENIX Security 2024 | 在 AArch64 上做硬件辅助隔离执行环境 | 说明“BPF isolation”是热点, 但实现代价较高 |
| [SandBPF](https://arxiv.org/abs/2308.01983) | 2023 workshop/arXiv | 动态 sandbox unprivileged eBPF | 和你们目标相近, 但它是重新设计执行隔离, 不是 live rewrite |

### 4.2 论文层面的空白

我没有找到近 3 年 top venue 上已经成熟发表、并且专门做下面这件事的工作:

- **对 arbitrary live BPF program 做透明 runtime bytecode transformation 来实施安全策略**

换句话说:

- 隔离类论文有
- verifier correctness / fuzzing 论文有
- 运行时安全产品很多
- 但 “**在不重启、不改应用、不重编程序的前提下, 直接改 live BPF image**” 这一类几乎是空白

这正是 BpfReJIT v2 的研究新颖性所在。

## 5. 开源项目检索

### 5.1 防御 / 监控

| 项目 | 定位 | 局限 |
|---|---|---|
| [Tetragon](https://github.com/cilium/tetragon) | eBPF-based Security Observability and Runtime Enforcement | 主要加载自己的 BPF 程序; 不改第三方 live BPF |
| [Tracee](https://github.com/aquasecurity/tracee) | Linux Runtime Security and Forensics using eBPF | 观测系统事件, 不是治理 arbitrary live BPF bytecode |
| [Falco](https://github.com/falcosecurity/falco) | Cloud Native Runtime Security | 规则/事件导向, 不提供 live BPF rewrite |
| [bpftop](https://github.com/Netflix/bpftop) | 实时查看运行中 BPF 程序的 runtime / EPS / CPU 占用 | 说明 live profiling 有现实价值, 但只观察不治理 |

### 5.2 offensive / 攻击面

| 项目 | 定位 | 含义 |
|---|---|---|
| [ebpfkit](https://github.com/Gui774ume/ebpfkit) | eBPF rootkit | 证明 eBPF 可作为持久化/隐蔽化载体 |
| [TripleCross](https://github.com/h3xduck/TripleCross) | eBPF rootkit with backdoor/C2/injection/stealth | 证明 helper + attach point 组合能做很强 offensive 功能 |
| [Linux_LPE_eBPF_CVE-2021-3490](https://github.com/chompie1337/Linux_LPE_eBPF_CVE-2021-3490) | verifier exploit | 证明 verifier bug exploit 是工程化现实 |

### 5.3 开源项目层面的结论

- 防御项目几乎都在“**自己加载一个 BPF 防御探针**”。
- offensive 项目证明“**恶意 BPF 程序本身**”是现实威胁。
- 但我没看到有项目专门做“**拦截并重写别人的 live BPF 程序**”。

这使得以下方向非常有意思:

- 不是再写一个 Tetragon/Falco
- 而是给 Tetragon/Falco **补一个 live BPF control plane**

## 6. 本地 `vendor/linux-framework` 代码树结论

### 6.1 现有内核里已经有的安全机制

- **BPF LSM 已启用**
  - `security/bpf/hooks.c:10-27`
- **security_bpf_*` load-time hooks 已存在**
  - `security/security.c:5174-5250`
- **BPF token 已存在**
  - `include/uapi/linux/bpf.h:888-912`
  - `kernel/bpf/token.c:17-27`
  - `kernel/bpf/token.c:112-158`
- **signed BPF 已存在于当前树**
  - `include/uapi/linux/bpf.h:1640-1649`
  - `kernel/bpf/syscall.c:2808-2848`
  - `kernel/bpf/syscall.c:3033-3036`
- **Spectre mitigation 和 ST_NOSPEC 已存在**
  - `kernel/bpf/core.c:2127-2137`
  - `kernel/bpf/core.c:3090-3094`
  - `kernel/bpf/verifier.c:22739-22748`
- **JIT constant blinding 已存在**
  - `kernel/bpf/core.c:1308-1319`
  - `kernel/bpf/core.c:1497-1525`

### 6.2 仍然缺失的东西

最重要的缺失不是“能不能控制谁 load BPF”, 而是:

1. **没有 live-time governance**
   现有 hook/token/signature 都主要在 load-time。

2. **没有 post-disclosure remediation**
   当 verifier bug 公布后, 当前树没有“把已经跑着的程序自动补丁化”的路径。

3. **没有 arbitrary third-party BPF policy grafting**
   现有产品通常只控制自己加载的程序。

4. **没有 runtime revocation / rollback plane**
   签名和 token 不能“把已经加载的不安全 image 换掉”。

### 6.3 一个非常关键的侧证

`kernel/bpf/core.c:3090-3094` 的注释写得很直白:

> currenty no support for reloading programs that were loaded without mitigations

这几乎就是在说:

- upstream 当前设计并不擅长 **“事后补救已加载程序”**
- 而 **BpfReJIT v2 正好擅长这个**

## 7. BpfReJIT v2 能做的安全 use case

### 7.0 novelty 评价标准

- **高**: 没找到现成 upstream / 论文 / 开源系统已经实现“同等语义”的东西
- **中**: 有相近方向, 但通常只做到 load-time / monitoring / 自研程序范围
- **低**: 社区已经有成熟实现, 你们更多只是换一种实现方式

### 7.1 Use Case A: 危险 helper/kfunc 防火墙 + exfil sinkholing

对应: 2.1, 2.4, 2.8

#### 思路

把已加载程序里的危险 helper 调用重写成:

- 安全 wrapper kfunc
- 或直接 fail-safe stub
- 或把输出 map 重写为黑洞/审计 map

重点对象:

- `bpf_probe_write_user`
- `bpf_copy_from_user_task`
- `bpf_probe_read_user*`
- `bpf_d_path`
- ringbuf/perf-event 输出路径

#### 为什么它很适合 BpfReJIT v2

- helper call 在 BPF 字节码里是显式 `call imm`
- 你们可以:
  - 识别 call-site
  - 插 guard
  - 或把 helper id 改成 inline kfunc wrapper
  - 再过 verifier
  - 原子替换 live 程序

#### 实现方案

1. daemon 枚举 live programs
2. 读取 original bytecode, program type, attach type, used map ids
3. 静态提取:
   - helper/kfunc 调用集合
   - 输出路径: ringbuf/perf-event/map update
   - 是否读取 user memory / 路径 / task
4. 策略命中后做变换:
   - `bpf_probe_write_user` -> wrapper, 默认 `-EPERM`
   - `bpf_copy_from_user_task` -> wrapper, 允许名单进程/容器, 否则 zero-fill + deny
   - `bpf_d_path` -> wrapper, 仅允许 approved program
   - exfil map helper -> redirect 到 blackhole map 或 audit map
5. 重新提交 verifier
6. 原子替换

#### Novelty / 难度 / 价值

- **Novelty: 高**
  监控工具很多, 但我没找到“对 arbitrary live BPF helper call 做透明防火墙重写”的现成方案。
- **实现难度: 低到中**
  需要写 call-site rewriter 和少量 wrapper kfunc。
- **实际价值: 高**
  这是最直接的“恶意 BPF 中和”能力。

#### 现有工作

- [Tracee](https://github.com/aquasecurity/tracee), [Falco](https://github.com/falcosecurity/falco), [Tetragon](https://github.com/cilium/tetragon) 做监控
- [ebpfkit](https://github.com/Gui774ume/ebpfkit), [TripleCross](https://github.com/h3xduck/TripleCross) 证明 offensive 用法现实存在
- `bpf_probe_write_user` 文档自己都警告不要用于 security mechanism:
  - `include/uapi/linux/bpf.h:2711-2719`

#### 评价

**这是我最推荐的第一阶段项目。**

### 7.2 Use Case B: live BPF 完整性保护与自愈回滚

对应: 2.3, 2.7

#### 思路

对关键程序建立 `golden bytecode hash` baseline:

- 自研安全探针
- Tetragon/Tracee/Falco 程序
- 关键 XDP/TC 生产程序

如果 live image 与 baseline 不符:

- 自动替换回 known-good image
- 或替换成 fail-safe image

#### 为什么它不是“重复 signed BPF”

signed BPF 解决的是:

- 这个程序 load 的时候有没有签名

它不解决:

- 程序后来被谁替换了
- 老版本脆弱 image 还在不在跑
- 防御程序被人热更新成 no-op 了怎么办

#### 实现方案

1. daemon 维护 approved image registry
2. 周期性枚举 live BPF programs
3. 计算:
   - raw/original bytecode hash
   - normalized hash
   - attach metadata
4. 如果发现:
   - 程序 image 不在 allowlist
   - 某个防御型 BPF image 被降级/替换
5. 直接 zero-cost image swap 恢复 approved image
6. 记录审计事件

#### Novelty / 难度 / 价值

- **Novelty: 高**
  load-time signing 已有, 但 live rollback/self-healing 我没有找到现成系统。
- **实现难度: 低**
  哈希 + 对应 image 恢复。
- **实际价值: 高**
  对生产安全产品特别有价值。

#### 评价

**这是第二个最值得做的项目。**

### 7.3 Use Case C: 容器/租户作用域守卫注入

对应: 2.6

#### 思路

给 live 程序入口加作用域检查:

- `cgroup_id`
- `netns_cookie`
- pid namespace / user namespace identity

如果当前上下文不属于允许范围:

- tracing 程序: `r0 = 0; exit`
- XDP/TC: 返回 `PASS` 或策略默认值
- LSM/cgroup 程序: 返回 attach-type 合法默认值

#### 为什么它很 novel

- [2023 BPF namespace RFC](https://lkml.iu.edu/2304.0/02230.html) 被 NACK, 说明“内核里单独引入 BPF namespace”这条路没有走通
- [2026 namespace hooks patch](https://www.spinics.net/lists/cgroups/msg53541.html) 又说明社区仍在找 namespace-aware BPF supervision 的落点
- 你们不需要等 namespace 抽象成熟, 直接对 live program 注入 scope guard 就能拿到 80% 价值

#### 实现方案

1. daemon 把 program 与租户/容器绑定
2. 在程序入口注入:
   - 读取 `bpf_get_current_cgroup_id()` / `bpf_get_netns_cookie()` / inline kfunc
   - 与 allowlist map 或立即数比较
3. mismatch 则返回 attach-type aware safe default
4. hot-swap live image

#### Novelty / 难度 / 价值

- **Novelty: 高**
- **实现难度: 中**
  难点是不同 program type 的默认返回值语义要处理好。
- **实际价值: 高**
  多租户环境直接受益。

#### 评价

**这是第三个最值得做的项目。**

### 7.4 Use Case D: 审计 grafting / provenance stamping

对应: 2.3, 2.8

#### 思路

不是只 audit `BPF_PROG_LOAD`, 而是把审计逻辑 **植入程序本体**:

- 程序入口打点
- 调用敏感 helper 前后打点
- 向 ringbuf/perf-event 输出前打点
- 记录 program hash / program id / attach site / current task / cgroup

#### 实现方案

1. daemon 给目标程序插入一小段前置块
2. 前置块调用 inline kfunc:
   - `audit_bpf_exec(prog_id, hash, helper_mask, tenant_id, ts)`
3. 对敏感 helper call-site 再插 before/after 事件
4. 通过策略控制 sampling rate

#### Novelty / 难度 / 价值

- **Novelty: 高**
  监控产品很多, 但“给任意 live 第三方 BPF image 补 provenance”这一点没看到现成实现。
- **实现难度: 低**
- **实际价值: 高**
  合规、取证、溯源都需要。

#### 评价

**非常适合作为第一批 demo。**

### 7.5 Use Case E: verifier bug 漏洞热修复

对应: 2.5

#### 思路

当新的 verifier bug/PoC 公布后:

- 在程序层面插入 **额外保守检查**
- 不等内核升级
- 不要求应用重编/重启

#### 可行的热修复模板

不是“泛化修所有 verifier bug”, 而是做 **bug-family template**:

- range clamp after suspicious 32/64 narrowing
- variable-offset stack write guard
- branch-pair canonicalization
- anti-pruning anchor blocks
- helper argument sanitization

#### 为什么现实

- [CVE-2021-31440](https://www.thezdi.com/blog/2021/5/26/cve-2021-31440-an-incorrect-bounds-calculation-in-the-linux-kernel-ebpf-verifier)
- [CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163)
- [OSDI 2024 SEV](https://www.usenix.org/conference/osdi24/presentation/sun-hao)

都说明“漏洞公布时系统里可能已经有触发器程序在跑”。

#### 实现方案

1. 把每个公开 bug/PoC 总结成字节码模式
2. daemon 扫描 live programs
3. 命中时自动插入:
   - range mask
   - explicit bounds branch
   - safe exit path
4. verifier 通过后替换

#### Novelty / 难度 / 价值

- **Novelty: 很高**
  我没有找到已有 `live patching of live eBPF programs to avoid verifier bug gadgets` 的系统。
- **实现难度: 中**
  需要针对 bug 家族维护 patch 模板。
- **实际价值: 高**
  尤其适合云环境和需要快速缓解的发行版场景。

#### 评价

**非常有研究亮点, 也有工程价值。**

### 7.6 Use Case F: runtime Spectre barrier 注入

对应: 2.2

#### 思路

对已加载程序进行 selective hardening:

- 检测高风险分支/内存访问模式
- 插入 `BPF_ST_NOSPEC` 或自定义 barrier 指令 / inline kfunc
- 在高威胁等级时打开, 平时恢复原图像

#### 为什么不是重复内核已有逻辑

内核已有:

- static verifier-side ST_NOSPEC
- JIT-level hardening
- constant blinding

但缺的是:

- **对已加载程序的事后补救**
- **按程序/租户/威胁态动态切换**

#### Novelty / 难度 / 价值

- **Novelty: 中到高**
  思路本身已有 BeeBox/VeriFence, 但 live retrofit 方式很新。
- **实现难度: 中**
  需要更强验证与性能评估。
- **实际价值: 中到高**
  取决于你的场景里是否真有 untrusted BPF/multi-tenant。

#### 评价

**适合作为研究型项目, 不建议作为第一批最小可行产品。**

### 7.7 Use Case G: late-bound least privilege / 权限收紧

对应: 2.4

#### 思路

把“权限收紧”拆成两个容易落地的子能力:

1. **helper 收紧**
   危险 helper 统一走 wrapper
2. **map/输出路径收紧**
   把非必要的 map 引用改成 shadow map / blackhole map / read-only proxy

#### 为什么比“做程序静态证明”更现实

完全自动推导“程序只需要哪些权限”很难。  
但做下面两件事已经很有价值:

- 把高危 helper 禁掉
- 把 exfil/output map 换掉

#### Novelty / 难度 / 价值

- **Novelty: 高**
  尤其是 shadow-map substitution / blackhole-map replacement。
- **实现难度: 中**
- **实际价值: 中到高**

#### 评价

如果只做“helper firewall + output sinkholing”, 它其实可以并入 Use Case A。  
如果要做“全面 least privilege inference”, 那就不是低难度项目了。

### 7.8 Use Case H: 恶意 BPF 检测与阻断

对应: 2.1

#### 判断

- **“检测”本身 novelty 不高**
  因为已有大量 security monitoring 工具。
- **“检测 + 对 live arbitrary program 透明中和” novelty 很高**

#### 更好的切法

不要做“AI/签名分类器”作为第一步, 而要做:

- 明确的 helper/attach/map rule
- 命中即改写或 sinkhole

这是因为:

- 恶意 bytecode 的高层语义分类容易被绕过
- helper/attach/output 级别的 policy 更容易解释, 更容易验证, 更容易上线

#### Novelty / 难度 / 价值

- **Novelty: 中**
  如果只是检测
- **Novelty: 高**
  如果是透明 rewrite/block
- **实现难度: 低**
  做 rule engine 即可
- **实际价值: 高**

### 7.9 Use Case I: 动态安全策略执行

对应: 2.8

#### 思路

发生 incident 时:

- 给所有 XDP/TC 程序注入 rate limiting
- 给 tracing/kprobe 程序加额外 logging
- 给 LSM/cgroup BPF 程序加 deny/allow 快速策略

#### 最好的实现方式

不是每次都重写全量逻辑, 而是:

1. 先给选定程序植入一个轻量 policy hook
2. hook 读取一个 daemon 管理的 policy map
3. incident 时只更新 policy map

这样:

- 第一次需要 rewrite
- 后续策略切换几乎零成本

#### Novelty / 难度 / 价值

- **Novelty: 高**
  现有系统会动态调整“自己的程序”, 但不是 arbitrary live program。
- **实现难度: 低到中**
- **实际价值: 高**

## 8. 优先级总表

### 8.1 总排序

| Use Case | Novelty | 实现难度 | 实际价值 | 已有工作 | 我们的优势 |
|---|:---:|:---:|:---:|---|---|
| **A. 危险 helper 防火墙 + exfil sinkholing** | **高** | **低-中** | **高** | 监控工具很多, 但几乎不改第三方 live BPF | helper call 重写最直接, wrapper kfunc 很容易接 |
| **B. 防御型 BPF 完整性自愈/回滚** | **高** | **低** | **高** | signed BPF / token 主要是 load-time | 你们能做 live rollback |
| **C. 容器/租户作用域守卫注入** | **高** | **中** | **高** | BPF namespace RFC 被 NACK, namespace hooks 仍在探索 | 不必等 namespace 抽象成熟, 直接改 live image |
| **D. 审计 grafting / provenance stamping** | **高** | **低** | **高** | KRSI/LSM 有审计能力, 但不审计 arbitrary live BPF image 本体 | 你们能给现有程序补审计 |
| **E. verifier bug 热修复模板库** | **很高** | **中** | **高** | 没找到现成 live patching 方案 | 完全契合“读原始 bytecode + 重写 + swap” |
| **I. 动态 incident-driven policy 执行** | **高** | **低-中** | **高** | 多数系统只管自己的 BPF | 可给任意 live 程序植入 policy hook |
| F. runtime Spectre barrier retrofit | 中-高 | 中 | 中-高 | BeeBox, VeriFence, 内核已有部分 mitigations | 你们能做已加载程序的 selective retrofit |
| G. late-bound least privilege / shadow-map 收紧 | 高 | 中 | 中-高 | BPF token/signed BPF 只做 load-time | 可对 live image 做 helper/map 降权 |
| H. 恶意 BPF 检测与阻断 | 中 / 高* | 低 | 高 | 检测工具已有很多 | *rewrite/block 这一半才是真正新东西 |

### 8.2 最应该先做的项目

符合“**高 novelty + 低难度 + 高价值**”的前三项:

1. **危险 helper 防火墙 + exfil sinkholing**
2. **防御型 BPF 完整性自愈/回滚**
3. **容器/租户作用域守卫注入**

最有论文味道的两个方向:

1. **verifier bug 热修复模板库**
2. **runtime Spectre barrier retrofit**

## 9. 我对每个用户要求点的直接判断

### 9.1 2.1 恶意 BPF 程序检测和阻断

- **检测**: 有人做过类似 runtime security monitoring, novelty 低到中
- **对 arbitrary live program 透明阻断/重写**: 我没找到现成方案, novelty 高
- **建议做法**: 不要先做“恶意分类器”, 先做 rule-driven helper firewall + sinkholing

### 9.2 2.2 Spectre 缓解注入

- 内核已有部分 mitigations
- 研究界仍在推进更强方案
- **runtime retrofit** 我没找到现成系统
- novelty 中到高, 但不是最低难度

### 9.3 2.3 BPF 程序行为审计/合规

- load-time audit 有近亲
- 对 **live program 本体** 植入 provenance/audit 很新
- 低难度, 高价值

### 9.4 2.4 BPF 程序权限收紧

- load-time delegation 已有 BPF token
- **late-bound least privilege** 基本没人做
- 但“完全自动推导”不低难度
- 建议先从 helper/map output 收紧做起

### 9.5 2.5 BPF 程序漏洞热修复

- **我认为最 novel 的方向之一**
- 工程上可做成 bug-family patch template
- 非常适合做论文 + 系统原型

### 9.6 2.6 容器级 BPF 隔离

- 社区需求明确
- 2023 namespace RFC 被 NACK
- 2026 namespace hooks patch 还在推进
- 你们能绕过 namespace 设计争议, 直接做 entry guard injection

### 9.7 2.7 BPF 程序完整性保护

- signed BPF 本身不新
- **live baseline + auto-restore** 新
- 非常适合生产安全产品

### 9.8 2.8 动态安全策略执行

- 非常适合你们
- 尤其是“先植 hook, 后改 policy map”
- 高价值, 低到中等难度

## 10. 不建议优先做的方向

1. **泛化恶意 bytecode classifier**
   太容易被规避, 且不如 helper/policy 规则可解释。

2. **全自动 program semantic least-privilege inference**
   研究价值有, 但不符合“容易实现”。

3. **把 signed BPF 再做一遍**
   当前树里已经有这条路的实现。

## 11. 最小可行原型建议

### MVP-1: helper firewall

- 识别:
  - `bpf_probe_write_user`
  - `bpf_copy_from_user_task`
  - `bpf_d_path`
  - ringbuf/perf-event 输出
- 动作:
  - 替换为 wrapper / deny / blackhole
- 结果:
  - 最快出 demo

### MVP-2: integrity self-healing

- baseline:
  - Tetragon / Tracee / Falco / 自研关键程序
- 动作:
  - 周期性 hash
  - 偏离即恢复
- 结果:
  - 生产价值最强

### MVP-3: container guard injection

- 给指定程序入口加 `cgroup_id` / `netns_cookie` check
- mismatch 返回 safe default
- 结果:
  - 直接证明“BpfReJIT v2 能补上 BPF namespace 没解决的问题”

### MVP-4: verifier-bug hotfix template

- 选一个公开 bug family 做 template
- 扫描 live programs
- 自动插 conservative range clamp
- 结果:
  - 论文亮点最强

## 12. 最终结论

从安全角度看, BpfReJIT v2 最有价值的不是“再造一个 BPF-based security monitor”, 而是做一个 **live BPF remediation layer**:

- load-time 机制已有很多
- monitor-time 工具也很多
- 真正缺的是 **live-time, transparent, arbitrary-program, policy-driven transformation**

因此我最明确的建议是:

1. 先做 **危险 helper 防火墙 + exfil sinkholing**
2. 再做 **完整性自愈/回滚**
3. 然后做 **容器作用域守卫注入**
4. 把 **verifier bug 热修复** 作为最强 research story

如果只允许选一个最应该做的方向:

> **选 “危险 helper 防火墙 + exfil sinkholing”。**

原因:

- 非常容易落地
- 对恶意 rootkit / keylogging / exfil 最直接
- 完全契合你们的 runtime rewrite + atomic swap 模型
- 我没有找到现成系统已经把这件事做成通用能力

## 13. 关键参考资料

### 漏洞 / 利用

- [CVE-2020-8835: A 15-Year-Old eBPF Verifier Vulnerability](https://www.thezdi.com/blog/2021/5/25/cve-2020-8835-a-15-year-old-ebpf-verifier-vulnerability)
- [CVE-2021-31440: Incorrect Bounds Calculation in the Linux Kernel eBPF Verifier](https://www.thezdi.com/blog/2021/5/26/cve-2021-31440-an-incorrect-bounds-calculation-in-the-linux-kernel-ebpf-verifier)
- [Exploiting CVE-2021-3490 for Container Escapes](https://www.crowdstrike.com/en-us/blog/exploiting-cve-2021-3490-for-container-escapes/)
- [NVD: CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163)
- [Google Bug Hunters: CVE-2023-2163 deep dive](https://bughunters.google.com/blog/a-deep-dive-into-cve-2023-2163-how-we-found-and-fixed-an-ebpf-linux-kernel-vulnerability)

### patch / RFC / upstream

- [KRSI / MAC and Audit policy using eBPF](https://lkml.rescloud.iu.edu/1912.3/03338.html)
- [RFC: Introduce BPF namespace](https://lkml.iu.edu/2304.0/02230.html)
- [PATCH 1/4: ns: add bpf hooks](https://www.spinics.net/lists/cgroups/msg53541.html)
- [LPC 2024: Mitigating Spectre-PHT using Speculation Barriers in Linux eBPF / VeriFence](https://lpc.events/event/18/contributions/1954/contribution.pdf)

### 论文

- [OSDI 2024: Validating the eBPF Verifier via State Embedding](https://www.usenix.org/conference/osdi24/presentation/sun-hao)
- [FSE 2024: BRF: Fuzzing the eBPF runtime](https://2024.esec-fse.org/details/fse-2024-research-papers/113/BRF-Fuzzing-the-eBPF-runtime)
- [USENIX Security 2024: BeeBox](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di)
- [USENIX Security 2024: MOAT](https://www.usenix.org/conference/usenixsecurity24/presentation/lu-hongyi)
- [USENIX Security 2024: HIVE](https://www.usenix.org/conference/usenixsecurity24/presentation/zhang-peihua)
- [SandBPF](https://arxiv.org/abs/2308.01983)

### 实务 / 开源

- [Trail of Bits: Pitfalls of relying on eBPF for security monitoring](https://blog.trailofbits.com/2023/09/25/pitfalls-of-relying-on-ebpf-for-security-monitoring-and-some-solutions/)
- [Tetragon](https://github.com/cilium/tetragon)
- [Tracee](https://github.com/aquasecurity/tracee)
- [Falco](https://github.com/falcosecurity/falco)
- [bpftop](https://github.com/Netflix/bpftop)
- [ebpfkit](https://github.com/Gui774ume/ebpfkit)
- [TripleCross](https://github.com/h3xduck/TripleCross)
