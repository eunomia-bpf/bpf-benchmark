# BPF 程序权限收紧（Privilege Narrowing）深度调研

日期：2026-03-26  
面向：BpfReJIT / OSDI '26 论文预研

## 摘要

生产环境中的 eBPF 程序经常处于“加载时权限很宽、运行时实际能力很窄”的状态。Linux 自 5.8 起已经把 `CAP_BPF`、`CAP_PERFMON` 从过载的 `CAP_SYS_ADMIN` 中拆出；当前内核又提供了 BPF token，可把 `bpf()` 命令、map type、prog type、attach type 的授权做得更细。然而，这些机制主要约束“未来的加载/创建动作”，并不能自动收紧“已经加载、已经拿到危险 helper 的 live 程序”。

基于 2026-03-25 的当前工作区快照，我对 `runner/repos/` 下第三方仓库中的 157 个 BPF 源文件做了静态 helper census，并单独把 `linux-selftests` 当作敏感 helper 的 ground truth。结论是：第三方真实程序中，`bpf_probe_write_user` 和 `bpf_override_return` 的直接使用为 0；149/157（94.9%）文件只使用基础 helper，8/157（5.1%）只涉及只读型用户态内存 helper（`bpf_probe_read_user(_str)` 等），没有发现第三方 tracing/observability 程序为了普通观测而使用高风险 helper。换言之，当前 corpus 中最显著的“过权”并不在字节码里，而在部署包络上：`privileged: true`、`CAP_SYS_ADMIN`、或为了降低运维摩擦而保留的粗粒度 capability。

这意味着，BpfReJIT 的 privilege narrowing 最强论文叙事不应是“现实中大量 observability 程序真的在用 `bpf_probe_write_user`”，而应是：

1. 现实系统普遍存在“部署权限宽于程序真实语义”的错配；
2. BPF token 只能收紧未来加载，不能收紧已加载程序；
3. REJIT 可以把 live 程序从“声明/部署包络”收缩到“静态可达能力包络”，再进一步在有静态证明时收缩到“运行时实际包络”。

同时必须明确一个安全约束：**不能仅凭 live 覆盖率就删除 helper call**。运行时观测只能生成候选集；真正的 NOP/stub rewrite 必须由静态可达性、不可变配置条件、或语义上允许的 fail-closed 替代共同支撑，否则会把冷路径但合法的功能误删。

## 1. 问题定义：BPF 的“过权”到底发生在哪里

### 1.1 三层权限错配

对 eBPF 而言，“权限”至少有三层：

1. **加载权限**：谁能执行 `BPF_PROG_LOAD`、`BPF_MAP_CREATE`、attach、pin、`BPF_OBJ_GET_INFO_BY_FD` 等。
2. **程序权限**：一段已加载字节码在 verifier 和 helper 白名单意义下，理论上能调用哪些 helper / kfunc、依赖哪些 map type、运行在什么 prog type / attach type 上。
3. **路径权限**：这段程序在当前配置和当前 workload 下，真实会走到哪些 helper call site、真实会触发哪些 side effect。

当前 Linux 生态已经开始细化第 1 层，但第 2 层和第 3 层仍大量耦合在“加载时一次性批准”的模型里。一旦一个程序在加载时获准使用高风险 helper，即便该 helper 在生产配置下从不触发，它仍然属于 live attack surface 的一部分。

### 1.2 为什么开发者倾向于申请最大权限

原因并不神秘：

- verifier/capability 失败的反馈链路长，且常发生在上线前最后一步；
- 容器/Kubernetes 部署中，`privileged: true` 往往是最省事的修复方式；
- 历史兼容性压力依然存在。很多工具仍把“旧内核需要 `CAP_SYS_ADMIN`”作为默认文档路径；
- 程序作者通常只知道“某类程序能不能加载”，而不会把 helper、map、attach、token 包络单独建模。

因此，**开发者的最优策略常常不是 least privilege，而是“先保能跑，再考虑细化”**。这正是 BpfReJIT 可介入的现实缝隙。

## 2. Linux 现有权限模型：已经能做什么，仍然缺什么

### 2.1 `CAP_BPF` / `CAP_PERFMON` / `CAP_SYS_ADMIN` 的演进

`capabilities(7)` 明确写道，`CAP_BPF` 与 `CAP_PERFMON` 都是在 Linux 5.8 引入，用于把 BPF 与 perf 相关能力从过载的 `CAP_SYS_ADMIN` 中拆分出来。[R1] 同一文档也明确指出：`CAP_SYS_ADMIN` 仍然可以执行 `CAP_BPF` 与 `CAP_PERFMON` 覆盖的操作，因此它依然是一个“向后兼容但过宽”的超级权限。[R1]

Linux UAPI `capability.h` 中对 BPF 能力的注释更具体：

- `CAP_BPF` 允许创建各类 map、使用高级 verifier 特性、加载 BTF、读取 xlated/JIT code、使用 `bpf_spin_lock()`；
- `CAP_PERFMON` 进一步放松 verifier，包括允许某些更强的读能力；
- `CAP_PERFMON + CAP_BPF` 用于加载 tracing 程序；
- `CAP_NET_ADMIN + CAP_BPF` 用于加载 networking 程序；
- `CAP_SYS_ADMIN` 仍被要求用于 `bpf_probe_write_user`。[L1]

这说明 Linux 已经把“程序类别级”的权限拆开了，但**仍没有把“具体 helper-site 级”的 live 能力”单独治理**。

### 2.2 高风险 helper 的特殊地位

`bpf-helpers(7)` 对两个典型高风险 helper 的表述非常直接：

- `bpf_probe_write_user()`：文档明确说它“不应被用来实现任何安全机制”，因为存在 TOCTOU 风险，而且该特性“主要用于实验”，并可能导致系统或进程崩溃。[R2]
- `bpf_override_return()`：文档明确说它“有安全含义（security implications）”，只在内核打开 `CONFIG_BPF_KPROBE_OVERRIDE` 时可用，并且只对标记为 `ALLOW_ERROR_INJECTION` 的函数工作。[R2]

这两个 helper 恰好定义了本文讨论的核心：**它们不是一般意义上的“读数据”能力，而是能够主动改写用户态或内核控制流/结果的 side-effect primitive**。如果一个 live 程序名义上拥有它们，但生产路径实际不需要，那么这就是最值得被收紧的权限面。

### 2.3 BPF token：细粒度，但主要发生在“未来加载”

`bpf(2)` 文档对 `BPF_TOKEN_CREATE` 的定义已经非常接近论文里需要的“最小授权向量”：

- token 内嵌允许的 `bpf()` 命令集合；
- 允许创建的 map type；
- 允许加载的 prog type 与 attach type；
- token 与其派生自的 bpffs 所属 user namespace 绑定，后续 capability 检查在该 user namespace 中完成。[R3]

内核 API 文档还给出了一组配套的 LSM hook：

- `security_bpf_token_create`
- `security_bpf_token_cmd`
- `security_bpf_token_capable` [R4]

这意味着 token 不只是一个授权对象，还是**可被 LSM 进一步裁剪的授权对象**。

但 token 有两个根本限制：

1. 它约束的是后续 `bpf()` 行为，而不是已经在 CPU 上运行的旧程序；
2. 它并不是“拿到 token 就万事大吉”。`linux-selftests` 的 token selftest 明确验证了：在 userns 中创建 privileged map 或加载带 `CAP_BPF` / `CAP_PERFMON` / `CAP_NET_ADMIN` 语义的程序时，**token 与 namespaced capability 必须共同满足**；单独 token 或单独 capability 都不够。[L3]

因此，**BPF token 很适合与 BpfReJIT 配合：前者收紧未来加载，后者收紧当前 live 程序。**

### 2.4 BPF LSM：能做全局 MAC / 审计，但不是 live narrowing

内核文档 `LSM BPF Programs` 明确指出：LSM BPF 允许 privileged user 在 LSM hook 上挂载 eBPF 程序，以实现 system-wide 的 MAC 与 audit policy。[R5] 这是“程序级权限控制”和“系统级安全策略”的基础设施。

但 LSM BPF 的主要用途是：

- 决定“某个事件/对象访问是否允许”；
- 决定“某个 BPF load / map create / token cmd / token capable 是否允许”。

它并不直接解决下面这个问题：

> 一个已经通过加载阶段、已经持有若干敏感 helper 的 live 程序，能否在不打断业务的情况下把这些 helper site 从字节码里移除或 stub 掉？

这正是 BpfReJIT 的差异点。

## 3. BpfReJIT 权限收紧方案：正确的设计边界

### 3.1 需要收紧的不是一个集合，而是一个向量

对每个 live 程序，建议把权限建模成四个集合：

- `D`（Declared/Deployed Envelope）  
  部署侧显式声明的 capability / privileged bit / token allowed set。

- `S`（Static Bytecode Envelope）  
  从原始字节码静态提取出的 helper id、kfunc、map op、tail-call 闭包、prog type、attach type、sleepable 属性等。

- `O`（Observed Live Envelope）  
  通过 daemon profile 或 trace 得到的真实执行 helper site / map op 子集。

- `N`（Narrowed Envelope）  
  经过安全证明后，允许 BpfReJIT 保留的最小 live 包络。

理想关系应为：

`O ⊆ N ⊆ S ⊆ D`

其中：

- `D -> S` 解决“部署过权”；
- `S -> N` 解决“静态上可用但当前部署并不需要”的权限面。

### 3.2 推荐的 REJIT 流水线

1. **枚举 live 程序**  
   读取 `bpf_prog_info`、原始/xlated 指令、map 依赖、prog type、attach type、BTF/kfunc 信息。

2. **抽取静态能力包络 `S`**  
   识别所有 helper call site、tail call graph、subprog、freplace/ext attachment、sleepable 标记。

3. **收集运行时观测 `O`**  
   用 daemon 记录真实执行到的 helper site、真实 map op、真实 tail-call 目标。

4. **求可安全收紧的目标 `N`**  
   只把 `O` 当作候选，不把它直接当作“可删除集合的补集”。

5. **选择 rewrite 动作**  
   - 证明不可达：可直接 NOP 或删掉分支；
   - 语义允许 fail-closed：替换成 safe stub；
   - 无法证明：不做 live rewrite，只在未来 token / reload 时收紧。

6. **REJIT + verifier 复验**  
   让 kernel verifier 重新验证收紧后的字节码。

7. **联动 token 与 loader**  
   为下一次升级/重载生成更小的 token 包络，并推动 loader 在 attach 后尽快 drop capability。

### 3.3 关键安全约束：不能只靠 live observation 删除 helper

这是本文最重要的设计约束。

只看 live 观测会出三个问题：

1. **冷路径问题**  
   稀有异常路径、错误恢复路径、feature flag 路径可能长期没跑到，但仍是合法功能。

2. **环境漂移问题**  
   当前 workload、当前内核状态、当前配置未触发的 helper site，未来可能触发。

3. **攻击诱导问题**  
   攻击者可能恰好想把控制流推到“平时没执行、但已被批准”的敏感 helper。

因此，BpfReJIT 的正确做法应是：

- `O` 用于排序与候选生成；
- 真正的 live 删除必须由静态可达性、不可变配置条件、常量传播结果、或操作员显式 policy 共同证明；
- 对副作用强、语义不透明的 helper，宁可只做 future-load narrowing，也不要草率 live 删除。

### 3.4 哪些 helper 适合收紧，哪些要保守

| helper / 能力 | 建议动作 | 原因 |
| --- | --- | --- |
| `bpf_probe_write_user` | 优先收紧；可替换为 `-EPERM` stub，但最好只对静态上可证明不需要的 site 下手 | 文档已明确其 TOCTOU 风险和实验性 |
| `bpf_send_signal(_thread)` | 适合 fail-closed stub | side effect 清晰，可审计 |
| `bpf_map_update_elem` / `delete_elem` | 可按 map/site 细粒度收紧；必要时改为 dummy map 或 `-EPERM` | 常见于“程序有写能力但生产只读” |
| `bpf_probe_read_user(_str)` | 通常不应默认删除 | 对 tracing 工具常常是功能核心，但属于只读能力 |
| `bpf_override_return` | **最保守**；仅在静态证明 dead / feature-disabled 时删 | 否则会改变“函数本该被跳过”这一核心语义 |

### 3.5 与 BPF token 的最佳组合方式

最合理的组合不是“token 取代 REJIT”，而是分工：

- **token**：收紧未来加载权限  
  例如只允许特定 `BPF_PROG_LOAD`、`BPF_LINK_CREATE`、特定 map type、特定 attach type。

- **REJIT**：收紧当前 live 程序权限  
  删除或 stub 不需要的 helper site / map op。

- **LSM token hook**：组织级策略  
  例如在某个 namespace 内统一禁止 `bpf_probe_write_user`、禁止某类 token command。

## 4. Corpus 数据：真实程序到底怎么用权限

### 4.1 方法

静态 census 范围：

- 时间：当前工作区快照，2026-03-25
- 第三方“真实程序”仓库：`bcc`、`katran`、`libbpf-bootstrap`、`scx`、`systemd`、`tracee`、`xdp-examples`、`xdp-tools`、`xdp-tutorial`
- 共 157 个 BPF 源文件
- 额外把 `linux-selftests` 作为敏感 helper 的 ground truth，而不计入“真实程序”统计

这里采用的是**保守口径**：只纳入命名、路径、或仓库结构上能够较确定识别为 BPF program source 的文件，以避免把 loader-side `.c`、测试桩、或普通用户态源码误计为 BPF 源。像 `cilium`、`tetragon` 这类把大量 eBPF 源保存在更自由的 `.c` 布局中的仓库，更适合在下一轮用 build artifact / object-level 分析单独扩展。

分析方法：

- 用正则提取 `bpf_*(` helper 调用；
- 用 `SEC("...")` 的 section root 区分 tracing-like 程序与 networking/cgroup/LSM 程序；
- 以文件为粒度统计是否出现：
  - **高风险 helper**：`probe_write_user`, `override_return`
  - **中风险/只读型 helper**：`probe_read_user(_str)`, `copy_from_user`, `send_signal(_thread)`

局限性：

- 这是 source-level potential use，不等于 basic-block 级可达 use；
- 宏封装、条件编译、内联可能导致轻微漏记；
- 这里统计的是“程序能力包络”，不是“实时执行路径”。

### 4.2 总体结果

#### 表 1：第三方 corpus 总体 helper 风险分布

| 范围 | 文件数 | 只含基础 helper | 只出现只读型 helper | 出现高风险 helper |
| --- | ---: | ---: | ---: | ---: |
| 第三方 corpus 全体 | 157 | 149 (94.9%) | 8 (5.1%) | 0 |
| tracing-like 子集 | 73 | 65 (89.0%) | 8 (11.0%) | 0 |

#### 表 2：按仓库拆分

| 仓库 | 文件数 | 只含基础 helper | 只读型 helper | 高风险 helper | tracing-like 文件数 |
| --- | ---: | ---: | ---: | ---: | ---: |
| `bcc` | 57 | 50 | 7 | 0 | 54 |
| `katran` | 2 | 2 | 0 | 0 | 0 |
| `libbpf-bootstrap` | 15 | 15 | 0 | 0 | 5 |
| `scx` | 31 | 31 | 0 | 0 | 3 |
| `systemd` | 6 | 6 | 0 | 0 | 1 |
| `tracee` | 3 | 2 | 1 | 0 | 2 |
| `xdp-examples` | 13 | 13 | 0 | 0 | 5 |
| `xdp-tools` | 14 | 14 | 0 | 0 | 1 |
| `xdp-tutorial` | 16 | 16 | 0 | 0 | 2 |

**核心发现**：

1. 在当前第三方 corpus 中，没有发现真实程序直接调用 `bpf_probe_write_user` 或 `bpf_override_return`。
2. tracing 工具确实常见 `bpf_probe_read_user(_str)`，但这是只读型 helper，不等价于“危险写/篡改 helper”。
3. 因而当前 corpus 呈现出的主导现象是：**部署权限比实际 helper 语义宽**，而不是“生产工具广泛实际调用高风险 helper”。

### 4.3 回答两个具体问题

#### Q1. 哪些程序声明了 `CAP_SYS_ADMIN`，但只用了基础 helper？

从当前工作区能直接举出四类代表：

| 程序/系统 | 显式声明/部署证据 | 实际程序语义 | 收紧机会 |
| --- | --- | --- | --- |
| `systemd-networkd` | `networkd.c` 保留 `CAP_SYS_ADMIN` 与 `CAP_BPF`；`networkd-manager.c` 明确写“Loading BPF programs requires CAP_SYS_ADMIN and CAP_BPF” [L9][L10] | 6 个 BPF 文件全部只含基础 helper；典型是 `map_lookup_elem`、`ringbuf_output`、`get_current_pid_tgid` [L11] | 对 BPF 侧可做 token/REJIT 收紧；但 systemd 进程整体仍可能因其他系统管理职责保留更宽 capability |
| `Tracee` | 文档给出“`CAP_BPF`+`CAP_PERFMON` 或 `CAP_SYS_ADMIN`”，默认 K8s manifest 使用 `privileged: true` [L4][L5] | `tracee.bpf.c` 只发现 `probe_read_user` 与读/观测类 helper，无高风险 helper [L8] | 能把“默认 privileged”收紧到按 feature 组合发 capability；网络 cgroup probe 未启用时还能避免 `CAP_NET_ADMIN` [L6][L7] |
| `bcc` 工具容器 | 官方 QuickStart/INSTALL 直接建议 `--privileged` 容器 [L12] | 57 个工具中 50 个只含基础 helper，7 个仅用 `probe_read_user(_str)`，0 个高风险 helper | 容器级 `--privileged` 明显宽于程序级需求 |
| `xdp-synproxy` | DaemonSet 声明 `privileged: true`，并额外加 `NET_ADMIN` [L13] | XDP 程序只使用网络路径 helper，如 `map_lookup_elem`、`xdp_ct_lookup`、`ktime_get_ns` | 典型“部署级全权，程序级语义很窄”案例 |

严格地说，这些例子里有一部分“宽权限”属于**进程/容器部署权限**，未必完全等价于“BPF 字节码声明权限”。但对 BpfReJIT 而言，这恰好是最现实的论文落点：**程序已经在一个过宽的运维包络里跑起来了，而 REJIT 可以把 live 字节码能力面降下来。**

#### Q2. 哪些程序用了 `bpf_probe_write_user`，但其实只是 tracing？

在当前第三方 corpus 中，**没有找到这样的真实程序**。

发现如下：

- 第三方 corpus：0 个文件直接调用 `bpf_probe_write_user`
- `linux-selftests`：`test_probe_user.c` 明确调用 `bpf_probe_write_user`
- `linux-selftests`：`kprobe_multi_override.c` 明确调用 `bpf_override_return`

这意味着，至少在当前工作区 snapshot 上，不能把“observability 工具常常实际用 `bpf_probe_write_user`”当成已证实事实。更准确的表述应该是：

> 现实系统中更普遍的是“部署时赋予过宽 capability / privileged container”，而不是“生产 tracing 工具在正常功能路径里普遍依赖高风险 helper”。

这并不削弱 privilege narrowing 的价值；相反，它让论文结论更扎实：**BpfReJIT 的主要价值，是把粗粒度部署包络和细粒度程序语义重新对齐。**

### 4.4 selftests 作为敏感 helper 的 ground truth

虽然第三方 corpus 中没有发现高风险 helper 的实际使用，但 `linux-selftests` 给了我们两个重要事实：

1. 敏感 helper 确实是内核权限模型中的一等公民，而不是纸面概念；
2. token/LSM/selftest 已经把这些能力当作可被单独治理的对象。

此外，Tracee 自己在 `tracee.bpf.c` 中还专门追踪“被加载的 BPF 程序是否使用 `bpf_probe_write_user` / `bpf_override_return`”。[L8] 这说明生产安全工具也把这两个 helper 当成需要单独标记的敏感信号。

## 5. 已有工作：与 BpfReJIT privilege narrowing 的关系

### 5.1 BPF token：最接近，但停留在 load-time delegation

最相关的内核机制就是 BPF token。

它已经提供：

- `allowed_cmds`
- `allowed_progs`
- `allowed_attachs`
- `allowed_map_types`
- userns-aware capability 检查 [R3]

配合 LSM token hook，它已经能表达“谁能委托什么”。[R4]

但它做不到：

- 修改已经加载程序的 helper site；
- 把一个已经通过 verifier 的 live 程序从“有权调用 X helper”降成“没有这个 site”；
- 透明地在不中断业务的情况下收紧既有程序。

因此，**BpfReJIT 不是重复 token，而是补上 token 没覆盖的 live phase。**

### 5.2 BPF LSM：能做系统级 MAC，但不是透明收紧

BPF LSM 的定位是“用 eBPF 实现 MAC/audit policy”。[R5]

它很适合做：

- deny 某个 BPF load；
- deny 某个 token command；
- deny 某类对象访问。

但如果目标是：

> 不要求应用重启，不要求 operator 重配，在不改变 attach 点的情况下，把 live 程序的危险 helper 删除或 stub 掉，

那么 BPF LSM 本身并不提供这类 post-load transformation。

### 5.3 Android BPF：中央特权 loader 的静态化实践

Android 的 eBPF 架构非常有启发性：

- Android 文档规定，boot 时系统自动从 `/system/etc/bpf/` 加载预编译对象，并把 program/map pin 到 bpffs；program 还带有 `AID_*` 级别的 owner/loader 语义。[R6]
- Android 网络流量监控文档进一步说明：`trafficController` 负责建图与操作 map，真正把预编译程序 load 并 attach 到 cgroup 的是 privileged `bpfloader`。[R7]

这是一种“中央特权 loader + 静态对象 ownership + pin 后受控访问”的架构。它说明：

- 工业界已经接受“把 BPF 权限集中到小的 trusted loader 中”；
- 但 Android 的方案是 boot-time/static 的，不是 live/post-load 的；
- BpfReJIT 可以被理解为通用 Linux 上的“动态版 Android loader hardening”。

### 5.4 学术相关：最接近的是“用 eBPF 实现 least privilege”，但目标不同

#### `bpfbox`（CCSW'20）

`bpfbox` 用 eBPF 做进程约束（process confinement），论文明确把 least privilege 当作问题背景，并把 eBPF 作为更灵活的 confinement substrate。[R8]  
它的目标是：**用 eBPF 约束 workload**。  
BpfReJIT privilege narrowing 的目标则是：**约束 eBPF workload 自身的 live 能力面**。

#### `Programmable System Call Security with eBPF` / Draco（SOSP'23）

Draco 通过 eBPF 增强 seccomp 的可编程性，并通过 temporal specialization 把某些阶段的 syscall attack surface 最多缩减 55.4%。[R9]  
这和本文最相似的地方在于：**都把“观察到的真实行为”转化为更小的权限面**。  
区别在于：

- Draco 收紧的是 syscall surface；
- BpfReJIT 收紧的是 BPF helper / map / attach / live bytecode surface。

#### SandBPF（SIGCOMM eBPF Workshop'23）与 SafeBPF（2024）

SandBPF 的目标是让 unprivileged user 也能安全扩展 kernel；SafeBPF 的目标是把 eBPF 与内核其它部分隔离，降低 verifier 漏洞被利用的风险。[R10][R11]

它们解决的是：

- **谁可以安全加载 eBPF**
- **eBPF 与内核之间如何隔离**

而不是：

- **一个已经被批准并已加载的 privileged eBPF 程序，能否在运行中被透明收紧**

#### 小结

据当前调研，已有工作大致覆盖了四个方向：

1. load-time delegation（BPF token）
2. system-wide policy enforcement（BPF LSM / Android loader）
3. workload least privilege via eBPF（bpfbox）
4. unprivileged/sandboxed eBPF execution（SandBPF / SafeBPF）

**尚未发现公开系统把“已加载 eBPF 程序的 helper/map/live capability surface”作为一等对象进行 post-load narrowing。**  
这正是 BpfReJIT privilege narrowing 可以主张的新点。

## 6. 为什么这不是“BPF 防火墙”

这是论文里必须讲清楚的一点。

### 6.1 防火墙/准入控制的目标

防火墙或 admission policy 解决的是：

- 这段程序应不应该被加载？
- 这个 token / attach / map create 应不应该被允许？
- 这个行为是否违反系统安全策略？

它的主要对象是**恶意程序**、**违规程序**、或**不可信租户**。

### 6.2 privilege narrowing 的目标

privilege narrowing 解决的是：

- 程序本身是合法的；
- 但它当前持有的能力面大于实际需要；
- 如果未来被 bug、配置漂移、或控制流诱导所利用，这些“未使用但已批准”的 helper 会变成攻击面。

因此 privilege narrowing 的关注点是：

- 缩小 blast radius；
- 删除 dormant gadget；
- 让“合法但过权”的程序变成“合法且最小授权”的程序。

### 6.3 关系：互补而非替代

最合理的架构是：

- **防火墙 / LSM / token**：把恶意或不合规程序挡在外面；
- **BpfReJIT narrowing**：把已经在系统里、并且需要继续工作的程序收紧到最小能力面。

一句话概括：

> 防火墙解决“要不要让它进来”，privilege narrowing 解决“既然它必须在里面，它究竟还应当保留多大攻击面”。

## 7. 对 OSDI 论文叙事的直接建议

### 7.1 最稳的论文主张

建议论文主张收敛为下面三点：

1. **生态现状**：现实中的 BPF 过权主要体现为部署/加载包络过宽，而不是第三方程序普遍实际使用高风险 helper。
2. **机制缺口**：Linux 已经有 capability split 与 BPF token，但它们只细化 load-time delegation，没有解决 live program narrowing。
3. **BpfReJIT 新点**：BpfReJIT 能在不要求应用重启的情况下，把 live 程序从部署包络压缩到更小的 verified capability envelope。

### 7.2 不宜过度声称的点

基于当前 corpus，不建议直接写：

- “大量 observability 工具在生产中使用 `bpf_probe_write_user`”
- “真实 tracing 程序经常依赖 `bpf_override_return`”

更稳妥的写法是：

- “高风险 helper 在内核权限模型中具有特殊地位，但在当前第三方 corpus 中十分罕见；现实过权更常来自部署层的粗粒度 capability 授权。”

### 7.3 评测建议

若要把这一点做成论文节，建议至少补四类量化：

1. **包络收缩量**：helper site、map op、token allowed set、capability 需求各减少多少。
2. **兼容性**：收紧后 workload 是否保持正确。
3. **安全收益**：高风险 helper / dormant path / side-effect primitive 被移除多少。
4. **收紧时延与开销**：从 live 观测到 REJIT 完成需要多久，对 steady-state 有无额外开销。

## 8. 结论

当前 Linux 已经提供了构建 least-privilege BPF 生态所需的三块关键积木：能力拆分（`CAP_BPF` / `CAP_PERFMON`）、BPF token、以及 BPF LSM。但它们主要约束未来的 load/create/delegate 流程，还没有把“已加载 live 程序的实际 helper/map 能力面”作为可以被透明收紧的对象。

当前 corpus 的关键事实是：第三方真实程序几乎不直接使用 `bpf_probe_write_user` / `bpf_override_return`；过权主要在部署包络上，而不在 helper 实际使用上。这恰好把 BpfReJIT privilege narrowing 的价值聚焦得更清晰：它不是替代防火墙，也不是再发明一遍 token，而是在 live phase 把“合法但过权”的 BPF 程序重新压回 least privilege。

如果论文把这一点讲清楚，再把“runtime evidence 只能做候选、不能直接做删除依据”的 soundness boundary 写扎实，这一节会非常有说服力。

## 参考资料

### 外部一手资料

- [R1] `capabilities(7)` man page: `CAP_BPF` / `CAP_PERFMON` / `CAP_SYS_ADMIN`  
  https://www.man7.org/linux/man-pages/man7/capabilities.7.html
- [R2] `bpf-helpers(7)` man page: `bpf_probe_write_user`, `bpf_override_return`  
  https://man7.org/linux/man-pages/man7/bpf-helpers.7.html
- [R3] Linux `bpf(2)` / `BPF_TOKEN_CREATE` userspace API docs  
  https://docs.kernel.org/userspace-api/ebpf/syscall.html
- [R4] Linux kernel API docs: `security_bpf_token_create/cmd/capable`  
  https://docs.kernel.org/next/core-api/kernel-api.html
- [R5] Linux docs: `LSM BPF Programs`  
  https://docs.kernel.org/bpf/prog_lsm.html
- [R6] Android Open Source Project: `Extend the kernel with eBPF`  
  https://source.android.com/docs/core/architecture/kernel/bpf
- [R7] Android Open Source Project: `eBPF traffic monitoring`  
  https://source.android.com/docs/core/data/ebpf-traffic-monitor
- [R8] Findlay et al., `bpfbox: Simple Precise Process Confinement with eBPF`, CCSW 2020  
  https://www.cisl.carleton.ca/~will/written/conference/bpfbox-ccsw2020.pdf
- [R9] Jia et al., `Programmable System Call Security with eBPF`, SOSP 2023  
  https://www.cc0x1f.net/publications/ebpf_syscall.pdf
- [R10] Lim et al., `Unleashing Unprivileged eBPF Potential with Dynamic Sandboxing`, arXiv:2308.01983  
  https://arxiv.org/abs/2308.01983
- [R11] Lim et al., `SafeBPF: Hardware-assisted Defense-in-depth for eBPF Kernel Extensions`, arXiv:2409.07508  
  https://arxiv.org/abs/2409.07508

### 仓库内证据

- [L1] `runner/repos/linux-selftests/include/uapi/linux/capability.h`
- [L2] `runner/repos/linux-selftests/tools/testing/selftests/bpf/progs/token_lsm.c`
- [L3] `runner/repos/linux-selftests/tools/testing/selftests/bpf/prog_tests/token.c`
- [L4] `runner/repos/tracee/docs/docs/install/prerequisites.md`
- [L5] `runner/repos/tracee/deploy/kubernetes/tracee/tracee.yaml`
- [L6] `runner/repos/tracee/common/capabilities/capabilities.go`
- [L7] `runner/repos/tracee/pkg/ebpf/probes/probe_group.go`
- [L8] `runner/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- [L9] `runner/repos/systemd/src/network/networkd.c`
- [L10] `runner/repos/systemd/src/network/networkd-manager.c`
- [L11] `runner/repos/systemd/src/**/bpf/*.bpf.c`
- [L12] `runner/repos/bcc/QUICKSTART.md`, `runner/repos/bcc/INSTALL.md`
- [L13] `runner/repos/xdp-examples/xdp-synproxy/xdp-synproxy-daemonset.yaml`
