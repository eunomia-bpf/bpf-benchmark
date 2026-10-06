# 危险 Helper 防火墙 + BPF 安全加固深度调研

日期：2026-03-26  
面向项目：BpfReJIT / OSDI '26 论文调研

## 摘要

本文调研了 eBPF helper 的危险面、在本仓库 corpus 中的真实使用分布、以及一个面向 BpfReJIT 的“危险 helper 防火墙”方案。核心结论有五点。

第一，helper 风险在真实程序中高度偏斜。对 `corpus/build/` 下 `568` 个 `.bpf.o` 的静态扫描显示，共有 `91,034` 次真实 helper 调用；若仅按题目给定的“严格危险集”统计，共命中 `155` 个对象、`26,925` 次调用，占全部 helper 调用的 `29.6%`。若把 legacy alias 和紧邻风险 helper 纳入“扩展危险集”，命中上升到 `188` 个对象、`62,013` 次调用，占比达到 `68.1%`。

第二，真正应 fail-closed 的 helper 并不多。`send_signal`、`override_return`、`set_retval` 这类“直接改变控制流/权限结果”的 helper 在 corpus 中极少出现：严格集合里总共只有 `10` 次调用，`set_retval` 为 `0`。这意味着“默认拒绝，仅对白名单程序开放”在兼容性上是现实的。

第三，高频风险面不在“控制流篡改”，而在“信息读取”和“计时”。`probe_read*`、`d_path`、`snprintf_btf`、`find_vma` 等信息泄露 helper，以及 `ktime_get_ns` / `jiffies64` / `ktime_get_boot_ns` 等计时 helper 才是常见面。因此防火墙不能只有 deny；还需要 redaction、coarse timing、safe-substitute、bounded read 等“降权限但保留功能”的策略。

第四，mainline 已经有不少 building blocks，但还没有 helper 级最小权限。BPF LSM、BPF token、trusted loader、`BPF_PROG_GET_NEXT_ID`/`BPF_OBJ_GET_INFO_BY_FD`、`BPF_LINK_UPDATE` 等接口已经支持 admission control、live discovery 和部分原子替换；但 BPF token 只限制 `cmd`/`map`/`prog`/`attach`，**不限制 helper ID**。helper 级 least privilege 仍然是空白。

第五，BpfReJIT 很适合做“已加载程序的安全热修复”。需要强调的是：**live 检测** 可以直接基于 `xlated_prog_insns` 做；但 **live 修复** 不能把当前 `xlated` 直接 patch 后重新喂给 verifier。当前内核/本项目树下，较现实的路线是：

1. 短期：从原始 `.bpf.o` 或保存的 baseline 做 rewrite，再 `re-verify + reload + map reuse + link update`；
2. 中长期：在内核里保存可重放 baseline，提供 internal replay verifier，并复用现有 `jit_directives.c` 的 staged image swap 机制。

## 1. 调研方法

### 1.1 静态扫描方法

本次 corpus 统计采用如下方法：

1. 扫描 `corpus/build/` 下全部 `.bpf.o`；
2. 使用 `llvm-objdump -dr` 解析指令；
3. 仅把 `opcode=0x85` 且 `src_reg==0` 的 `BPF_CALL` 计为真实 helper 调用；
4. 排除 pseudo-call / kfunc / subprog call；
5. helper ID 到 helper 名称的映射来自 `vendor/linux-framework/include/uapi/linux/bpf.h` 中的 `___BPF_FUNC_MAPPER`。

这样做的原因是：对象文件里不只有 helper call，还有 BPF-to-BPF pseudo-call 与 kfunc call。若只看反汇编文本里的 `call` 字样，会把这几类混在一起。当前统计一共排除了 `3,427` 个非 helper call。

另有 `2` 个 `call -1` 无法映射到 helper，均出现在 `corpus/build/datadog-agent/noisy-neighbor-kern.bpf.o`，属于对象级未解析调用位点；不影响整体结论。

### 1.2 统计口径

本文使用两套风险口径：

- 严格危险集：仅覆盖题目点名 helper  
  `probe_read_kernel`, `probe_read_user`, `d_path`, `send_signal`, `override_return`, `set_retval`, `skb_store_bytes`, `xdp_adjust_head`, `ktime_get_ns`
- 扩展危险集：在严格集合上加入 legacy alias 与邻近高风险 helper  
  如 `probe_read`, `probe_read_str`, `probe_read_kernel_str`, `probe_write_user`, `send_signal_thread`, `copy_from_user`, `snprintf_btf`, `find_vma`, `jiffies64`, `ktime_get_boot_ns`, `skb_change_tail`, `xdp_adjust_tail` 等

扩展集合的意义很直接：如果只防 `probe_read_kernel`，而不防 legacy `probe_read`，那么会漏掉 corpus 中最高频的 helper 风险面。

### 1.3 原始产物

原始统计结果保存在：

- [helper_scan/summary.json](helper_scan/summary.json)
- [helper_scan/per_object.json](helper_scan/per_object.json)
- [helper_scan/top_helpers.tsv](helper_scan/top_helpers.tsv)
- [helper_scan/dangerous_objects_strict.tsv](helper_scan/dangerous_objects_strict.tsv)
- [helper_scan/dangerous_objects_extended.tsv](helper_scan/dangerous_objects_extended.tsv)

## 2. BPF helper 风险分类

### 2.1 分类原则

本文按“helper 本身能直接扩大的攻击能力”分类，而不是按“helper 当前是否默认对所有 program type 开放”分类。后者由 verifier 的 `get_func_proto()` 与 attach-type 约束决定；前者才是 BpfReJIT 防火墙要压制的对象。

### 2.2 分类结果

| 类别 | 代表 helper | 风险说明 | 推荐默认策略 |
| --- | --- | --- | --- |
| 信息泄露 | `probe_read_kernel`, `probe_read_user`, `probe_read*`, `d_path`, `copy_from_user`, `snprintf_btf`, `find_vma`, `kallsyms_lookup_name` | 读取 kernel/user 地址、路径、BTF 结构或地址空间信息，可直接扩大侦察与 exfiltration 能力 | tracing/observability 程序细粒度白名单；其余 default deny 或 redaction |
| 权限提升/控制流篡改 | `send_signal`, `send_signal_thread`, `override_return`, `set_retval`, `probe_write_user`, `bprm_opts_set`, `sys_bpf` | 直接改变进程执行、返回值、安全决策或用户态内存 | 除显式白名单 security agent 外一律 fail-closed |
| 数据篡改 | `skb_store_bytes`, `xdp_adjust_head`, `xdp_adjust_tail`, `skb_change_tail`, `skb_adjust_room`, `xdp_store_bytes` | 改写包内容、包头/包尾、解析偏移或 room 大小 | 仅对 XDP/TC/LWT 数据面程序开放；对 tracing/LSM 默认拒绝 |
| 侧信道 | `ktime_get_ns`, `ktime_get_boot_ns`, `ktime_get_coarse_ns`, `ktime_get_tai_ns`, `jiffies64` | 提供高精度或可组合的时间源，强化计时侧信道与 covert timing | 不建议简单 deny；建议 coarseify / bucketize / mask lower bits |

### 2.3 为什么这些 helper 危险

从内核 UAPI 注释和实现看，这些 helper 的语义与风险是明确的：

- `bpf_probe_read_kernel()` / `bpf_probe_read_user()` 的语义就是“从 unsafe kernel/user address 读取数据”；这是信息外带能力本身，而不是偶发副作用。
- `bpf_d_path()` 返回 `struct path` 的完整路径；内核源码明确提供了更安全的 `bpf_path_d_path()` kfunc，并注明它应优先于 legacy `bpf_d_path()` 使用。
- `bpf_send_signal()` 直接向当前任务所属进程发信号；实现中还明确提到它与 `bpf_probe_write_user()` 一样存在安全含义。
- `bpf_override_return()` 直接跳过原始被探测函数并改写其返回值；UAPI 注释明确说明它是 error injection helper，且只对 `ALLOW_ERROR_INJECTION` 目标开放。
- `bpf_set_retval()` 虽然开放面窄，但语义上就是改写 cgroup hook 的返回值，因此本质上属于 policy-decision tampering。
- `bpf_skb_store_bytes()` / `bpf_xdp_adjust_head()` 明确会修改包缓冲区，且 helper 文档强调它们会使先前 packet pointer 检查失效，要求重新验证直接包访问。
- `bpf_ktime_get_ns()` 直接暴露高精度单调时钟。在安全工具里它常是 benign timestamp；但在 side-channel 语义上它仍然是危险 primitive。

## 3. 威胁模型

### 3.1 对手能力

本文关注四类现实威胁：

1. 已持有 BPF 加载权限的恶意或被攻陷进程；
2. 本意 benign，但 helper 权限过大的 observability/security agent；
3. verifier 漏洞被披露后，系统中已经存在的 live BPF 程序；
4. 多租户环境中的侧信道/侦察型 BPF 程序。

### 3.2 资产与安全目标

需要保护的对象包括：

- kernel memory / kernel symbol / path / task metadata 的机密性；
- 进程控制流和 LSM/cgroup 决策的完整性；
- 网络数据面的完整性；
- 宿主机与容器边界；
- 已部署安全 agent 的可审计性与最小权限边界。

### 3.3 不在本文范围内

本文**不**把以下问题当作 helper 防火墙本身的解决对象：

- helper 实现本身存在 kernel 内存安全 bug；
- 完全特权、可直接写内核内存的内核对手；
- 没有任何 baseline / 原始 ELF / attach context 的“任意 live xlated 程序通用重写”。

换句话说，helper 防火墙是 impact-reduction 和 least-privilege 机制，不是 verifier correctness 的替代品。

## 4. Corpus 数据结论

### 4.1 总体统计

| 指标 | 数值 |
| --- | ---: |
| `.bpf.o` 对象数 | 568 |
| helper 调用总数 | 91,034 |
| 被排除的 pseudo-call / kfunc / subprog call | 3,427 |
| 未映射 `call -1` | 2 |
| 严格危险集 helper 名数 | 9 |
| 严格危险集命中对象 | 155 (`27.3%`) |
| 严格危险集命中调用 | 26,925 (`29.6%`) |
| 扩展危险集 helper 名数 | 34 |
| 扩展危险集命中对象 | 188 (`33.1%`) |
| 扩展危险集命中调用 | 62,013 (`68.1%`) |

最重要的观察不是“危险 helper 很多”，而是：

- 严格集合已经覆盖近三成 helper 调用；
- 一旦把 legacy `probe_read*` 和临近计时/包改写 helper 纳入，风险面直接扩大到三分之二以上。

这说明 helper firewall 必须按**能力类**而不是按**少数具体名字**设计。

### 4.2 全 corpus top helper

| 排名 | helper | 调用次数 |
| --- | --- | ---: |
| 1 | `probe_read` | 28,481 |
| 2 | `probe_read_kernel` | 25,299 |
| 3 | `map_lookup_elem` | 11,571 |
| 4 | `trace_printk` | 4,745 |
| 5 | `probe_read_str` | 4,180 |
| 6 | `map_update_elem` | 2,745 |
| 7 | `probe_read_kernel_str` | 1,727 |
| 8 | `get_current_pid_tgid` | 1,285 |
| 9 | `ktime_get_ns` | 932 |
| 10 | `get_current_task` | 749 |
| 11 | `skb_pull_data` | 703 |
| 12 | `skb_load_bytes` | 590 |
| 13 | `get_current_comm` | 583 |
| 14 | `map_delete_elem` | 537 |
| 15 | `tail_call` | 537 |

高频 helper 前列几乎被 `probe_read*` 家族占据，这也解释了为什么“helper 安全加固”在真实生态里首先是 observability helper 问题，而不是 exotic kfunc 问题。

### 4.3 严格危险集分布

| helper | 命中对象数 | 调用次数 |
| --- | ---: | ---: |
| `probe_read_kernel` | 108 | 25,299 |
| `ktime_get_ns` | 86 | 932 |
| `skb_store_bytes` | 12 | 536 |
| `probe_read_user` | 23 | 126 |
| `xdp_adjust_head` | 5 | 17 |
| `send_signal` | 5 | 7 |
| `d_path` | 3 | 5 |
| `override_return` | 3 | 3 |
| `set_retval` | 0 | 0 |

对应到风险类别：

| 类别 | 命中对象数 | 调用次数 |
| --- | ---: | ---: |
| 信息泄露 | 112 | 25,430 |
| 侧信道 | 86 | 932 |
| 数据篡改 | 17 | 553 |
| 权限提升/控制流篡改 | 6 | 10 |

这里最值得写进论文的事实是：**权限类危险 helper 极少，信息读取类极多**。这为“对权限 helper 做 fail-closed，对读取/计时 helper 做兼容性友好的降权改写”提供了经验基础。

### 4.4 扩展危险集的增量

扩展集合里最重要的新增项不是稀有 helper，而是 legacy alias：

| helper | 调用次数 | 备注 |
| --- | ---: | --- |
| `probe_read` | 28,481 | 全 corpus 第一大 helper；若不纳入，会严重低估信息泄露面 |
| `probe_read_str` | 4,180 | 高频字符串读取 |
| `probe_read_kernel_str` | 1,727 | 内核字符串读取 |
| `jiffies64` | 221 | 另一类计时源 |
| `ktime_get_boot_ns` | 177 | 高精度计时替代源 |
| `probe_read_user_str` | 78 | 用户字符串读取 |
| `snprintf_btf` | 59 | BTF 结构外带 |
| `copy_from_user` | 23 | 用户态数据吸入 |

因此，helper 防火墙如果只封 `probe_read_kernel`/`probe_read_user`，而不处理 `probe_read`/`probe_read_str`/`probe_read_kernel_str`，实际只能压住一部分风险面。

### 4.5 项目热点

| 项目 | 对象数 | 严格危险对象数 | 严格危险调用 | 扩展危险调用 | 观察 |
| --- | ---: | ---: | ---: | ---: | --- |
| `tracee` | 2 | 1 | 21,912 | 26,576 | 单个 `tracee.bpf.o` 主导全局信息读取面 |
| `KubeArmor` | 3 | 3 | 2,754 | 24,974 | legacy `probe_read*` 极其密集 |
| `bcc` | 57 | 50 | 662 | 759 | 典型 observability 工具群，广泛依赖 `probe_read*` 与时间戳 |
| `cilium` | 3 | 3 | 445 | 682 | 数据面 mutator + 计时 helper 明显 |
| `tetragon` | 23 | 19 | 293 | 6,632 | 同时覆盖 observability 与 enforcement helper |
| `loxilb` | 3 | 3 | 271 | 299 | `skb_store_bytes` 高度集中 |
| `linux-selftests` | 369 | 42 | 187 | 334 | 量大但风险 helper 次数不高，主要是测试覆盖 |
| `calico` | 8 | 7 | 139 | 167 | 以 `skb_store_bytes` 与计时为主 |
| `scx` | 4 | 4 | 59 | 72 | 主要是计时 + 少量 kernel read |

另外一个强结论是：`tracee` 与 `KubeArmor` 两个项目就贡献了严格危险调用的 `91.6%`。这意味着论文里的 case study 完全可以围绕“少数大体量安全 agent 占据绝大多数 helper 风险面”展开，而不需要平均对待所有项目。

### 4.6 哪些程序调用了关键危险 helper

#### 4.6.1 权限/控制流 helper

`send_signal` 共 `7` 次，涉及 `5` 个对象：

- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o`
- `corpus/build/tetragon/bpf_multi_enforcer.bpf.o`
- `corpus/build/tetragon/bpf_generic_lsm_core.bpf.o`
- `corpus/build/tetragon/bpf_fmodret_enforcer.bpf.o`
- `corpus/build/tetragon/bpf_enforcer.bpf.o`

`override_return` 共 `3` 次，涉及 `3` 个对象：

- `corpus/build/tetragon/bpf_multi_enforcer.bpf.o`
- `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
- `corpus/build/tetragon/bpf_enforcer.bpf.o`

`set_retval`：`0` 次。

结论：这一类 helper 非常适合**默认拒绝、按程序名/签名/loader 白名单开放**。

#### 4.6.2 路径与读取 helper

`d_path` 共 `5` 次，涉及 `3` 个对象：

- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path.bpf.o`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_d_path_check_rdonly_mem.bpf.o`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_task_vmas.bpf.o`

`probe_read_kernel` 的前几大消费者：

1. `corpus/build/tracee/tracee.bpf.o`：21,732
2. `corpus/build/KubeArmor/system_monitor.bpf.o`：1,532
3. `corpus/build/KubeArmor/enforcer.bpf.o`：882
4. `corpus/build/KubeArmor/protectproc.bpf.o`：274
5. `corpus/build/tetragon/bpf_execve_event.bpf.o`：68

`probe_read`（legacy alias）的前几大消费者：

1. `corpus/build/KubeArmor/system_monitor.bpf.o`：18,668
2. `corpus/build/tetragon/bpf_generic_lsm_core.bpf.o`：2,942
3. `corpus/build/tracee/tracee.bpf.o`：2,103
4. `corpus/build/coroot-node-agent/ebpf.bpf.o`：1,278

结论：真正的大头不是孤立 helper，而是**整个 `probe_read*` 家族**。

#### 4.6.3 数据篡改 helper

`skb_store_bytes` 共 `536` 次，涉及 `12` 个对象，主要出现在：

- `corpus/build/loxilb/llb_ebpf_main.bpf.o`：129
- `corpus/build/loxilb/llb_ebpf_emain.bpf.o`：129
- `corpus/build/cilium/bpf_lxc.bpf.o`：115
- `corpus/build/cilium/bpf_overlay.bpf.o`：100
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o`：20
- `corpus/build/calico/*_debug.bpf.o`：每个 7

`xdp_adjust_head` 共 `17` 次，涉及 `5` 个对象：

- `corpus/build/cilium/bpf_xdp.bpf.o`：9
- `corpus/build/katran/balancer.bpf.o`：4
- `corpus/build/xdp-tutorial/packet-solutions/xdp_prog_kern_02.bpf.o`：2
- `corpus/build/suricata/xdp_lb.bpf.o`：1
- `corpus/build/loxilb/llb_xdp_main.bpf.o`：1

结论：packet mutator helper 大多集中在**明确的数据面程序**，这非常适合 program-type-aware allowlist。

#### 4.6.4 计时 helper

`ktime_get_ns` 共 `932` 次，涉及 `86` 个对象。它既出现在 tracing agent，也出现在网络 datapath：

- `tracee/tracee.bpf.o`：168
- `cilium/bpf_lxc.bpf.o`：89
- `cilium/bpf_overlay.bpf.o`：75
- `bcc/libbpf-tools/klockstat.bpf.o`：59
- `cilium/bpf_xdp.bpf.o`：57
- `KubeArmor/system_monitor.bpf.o`：53

与此同时，扩展集合还发现：

- `jiffies64`：221 次，主要来自 Cilium；
- `ktime_get_boot_ns`：177 次，主要来自 Tracee。

结论：若只 deny `ktime_get_ns`，程序很可能改用其他时间源；因此更合理的策略是**统一计时分辨率治理**，而不是 helper 名单逐个封。

## 5. 危险 helper 防火墙设计

### 5.1 设计目标

目标不是让 daemon 成为新的 verifier，而是做三件 verifier / token / LSM 目前没做好的事：

1. 对**已经加载**的 live 程序进行 helper 风险审计；
2. 对 helper 风险做**helper 级 least privilege**；
3. 在 verifier bug 或策略变更后，对 live 程序做**安全热修复**。

### 5.2 控制环

建议的控制环如下：

1. **发现**：通过 `BPF_PROG_GET_NEXT_ID` → `BPF_PROG_GET_FD_BY_ID` → `BPF_OBJ_GET_INFO_BY_FD` 枚举 live program，读取 `type`、`attach_type`、`xlated_prog_insns`、`btf_id`、`name` 等元数据；
2. **分类**：识别 helper call、program type、attach site、签名/loader provenance；
3. **决策**：对每个 helper 位点输出 `allow` / `rewrite` / `deny`；
4. **构造 candidate**：基于原始 `.bpf.o` 或保存的 baseline 生成 candidate；
5. **full re-verify**：在相同 extern universe 下重跑 verifier；
6. **提交**：能走 `BPF_LINK_UPDATE` 的 attach 走 link update；覆盖不到的 attach 走 BpfReJIT image swap；
7. **审计与回滚**：保留旧 image / old_prog_fd / generation tag，支持 RCU-safe rollback。

### 5.3 策略矩阵

| helper 类 | 默认策略 | 改写策略 | 备注 |
| --- | --- | --- | --- |
| 读 kernel/user/path/BTF | 默认审计，非 allowlist 拒绝或脱敏 | `probe_read*` 变 bounded read / dynptr read；`d_path` 变 `bpf_path_d_path`；或 sinkhole 为 error | 这类 helper 高频，不能只用 deny |
| 控制流/权限 | 默认拒绝 | 直接改写为 `r0 = -EPERM` 或 `r0 = 0` | 稀少，兼容性成本低 |
| 包修改 | 仅 XDP/TC/LWT 白名单开放 | 非白名单改为 `-EINVAL`；或替换为只读路径 | 高度上下文相关 |
| 高精度计时 | 默认 coarseify | `ktime_get_ns` → `ktime_get_coarse_ns` / `jiffies64` / 掩码低位 | 比直接 deny 更稳 |

### 5.4 改写动作的可行性

这里有一个对 BpfReJIT 很关键的技术观察：

**题目给出的严格危险 helper 都返回 scalar/integer，而不是 pointer type。**

这意味着对它们做 fail-closed rewrite 时，不需要伪造复杂的 verifier pointer state。常见的安全改写是：

- 原 `call helper`
- 改为若干条安全标量指令，例如 `r0 = -EPERM`

相比之下，如果目标 helper 返回 `PTR_TO_MAP_VALUE_OR_NULL` 一类 pointer type，那么“简单 NOP / simple constant return”就会立刻破坏后续 verifier 状态；但当前这批 helper 没有这个问题。

### 5.5 为什么不能直接 NOP

不建议把危险 helper 直接改成裸 `NOP`，原因有二：

1. helper call 会定义 `R0`；裸 NOP 会让后续代码读到旧值；
2. 某些 helper 还会触发 verifier-side special handling，例如 packet pointer invalidation 或 `override_return` 标记。

因此更合理的 fail-closed 动作是：

- `mov r0, imm` 风格的显式返回值替换；
- 或改成另一个**返回类型兼容**的安全 helper / kfunc。

### 5.6 推荐的 helper-specific 改写

#### `probe_read*`

优先级从高到低：

1. 若有原始 `.bpf.o` 与足够重写空间：改写为 dynptr/kfunc 版本的 bounded read；
2. 若只是临时紧急降级：把读取改为“写零 + 返回错误”；
3. 若连目标写入对象也难安全恢复：直接 `r0 = -EFAULT`，让上层逻辑看到失败。

#### `d_path`

优先使用 `bpf_path_d_path()`。内核源码明确指出它是 legacy `bpf_d_path()` 的“safer variant”，且只能在 BPF LSM program 中调用。若当前 program type/attach type 不满足条件，则应直接拒绝，而不是尝试语义强行迁移。

#### `send_signal` / `override_return` / `set_retval`

这类 helper 最适合简单 fail-closed：

- 非 allowlist 程序统一改写为 `r0 = -EPERM`；
- 论文实现中甚至可以先只支持这类 helper，兼容性损失很小，但安全故事非常强。

#### `skb_store_bytes` / `xdp_adjust_head`

对非数据面程序直接拒绝；对数据面程序保留，但要求：

- program type 与 attach site 在 allowlist；
- loader/provenance 可信；
- 运行期 profile 与 program role 匹配。

#### `ktime_get_ns`

不建议直接 deny。更实际的做法是：

1. 改成 `ktime_get_coarse_ns`；
2. 或保留 `ktime_get_ns` 但清零低若干位；
3. 或替换为 `jiffies64` 级精度。

这对 tracing、latency profiling、scheduler 类工具更友好。

## 6. REJIT 后 verifier 会接受替换吗？

### 6.1 短答案

**检测可以直接基于 live `xlated` 做；修复通常不能。**

更准确地说：

- **helper 检测**：可以。helper imm 在 `xlated_prog_insns` 中可见，scanner 足够完成分类；
- **helper 改写 + re-verify**：若基于原始 `.bpf.o` 或 kernel 保存的 baseline，通常可以；
- **直接 patch 当前 `xlated_prog_insns` 再重跑 verifier**：在当前树里不是最小可行方案。

### 6.2 为什么“同类替换”通常 verifier-friendly

verifier 文档明确说明：

- helper 的可用性由 `get_func_proto()` 决定；
- verifier 会检查寄存器是否满足 helper 参数约束；
- helper call 后，`R0` 被赋予 helper 的返回类型。

因此，只要改写后的代码满足以下条件，re-verify 一般不会成为主障碍：

1. 参数寄存器不再传给危险 helper；
2. `R0` 被显式写成兼容的 scalar return；
3. 控制流与栈深不被破坏；
4. 若替换为新 helper/kfunc，则新 helper 对当前 `prog_type`/`attach_type` 可用。

对于本文聚焦的严格危险 helper，这些条件相对容易满足。

### 6.3 为什么“直接 patch xlated 再 re-verify”不现实

结合本项目已有内核研究记录，可以得出一个很重要的工程结论：当前树下的 verifier 入口并不接受“post-fixup internal xlated IR 重新验证”。原因包括：

- `xlated` 中已经混入 internal-form opcode 与 fixup 结果；
- load 后很多 `orig_idx`/aux metadata 不再保留；
- `func_info`、`line_info`、subprog topology、poke table 都依赖当前 layout；
- 当前 verifier 缺少 internal replay API。

因此，BpfReJIT 的现实路线不是“拿 live xlated 直接 patch”，而是：

- 要么从原始 `.bpf.o` 重写并 reload；
- 要么在内核里保存 replayable baseline，再做 internal re-verify。

### 6.4 推荐路线

| 路线 | 结论 | 适用场景 |
| --- | --- | --- |
| 用户态从原始 `.bpf.o` 重写 + reload + map reuse + link update | 现阶段最现实 | 原始对象可得、attach 覆盖可接受 |
| 内核保存 baseline + internal replay verifier + same-prog image swap | 长期最优 | 需要 BpfReJIT 内核扩展，追求不改 prog identity |
| 直接 patch live `xlated` 再 re-verify | 不推荐 | 当前树结构不支撑 |

## 7. BPF 程序漏洞热修复：与 BpfReJIT 的天然契合

### 7.1 为什么这是好题

过去几年的高影响 eBPF CVE 大多不是“某个 helper 本身坏了”，而是“verifier 错误地放过了本不该通过的程序”：

- `CVE-2021-3490`：ALU32 bounds tracking 错误，导致 OOB read/write、任意代码执行、容器逃逸；
- `CVE-2021-31440`：incorrect bounds calculation，导致 OOB 与 Kubernetes container escape；
- `CVE-2023-2163`：incorrect verifier pruning，导致 arbitrary kernel read/write、横向提权与 container escape。

这类漏洞有两个共性：

1. 根因在 verifier；
2. 漏洞披露时，系统里可能已经有 live BPF 程序。

load-time 机制只能拦住**之后**要加载的程序，无法处理**已经在跑**的程序。这正是 BpfReJIT 的切入点。

### 7.2 可行的 hotpatch 形态

一个现实的“紧急模式”可以是：

1. daemon 收到新的 CVE profile；
2. 扫描 live program；
3. 对非 allowlist 程序中的危险 helper 应用紧急 rewrite：
   - `send_signal*` / `override_return` / `set_retval` 一律 fail-closed；
   - `probe_read*` / `d_path` 改为 error/redaction；
   - `ktime_get_ns` 降为 coarse；
   - packet mutator 仅保留在签名可信的数据面程序中；
4. full re-verify；
5. 原子替换与回滚。

这不是根因修复，但能在“打补丁前的窗口期”显著缩小攻击面。

### 7.3 与 kernel livepatch 的关系

它像 kernel livepatch，但又更细：

- patch 对象不是整个 kernel text，而是单个 BPF program；
- 回滚粒度更小；
- 可以按 helper class、program provenance、attach site 逐程序决策；
- 对 paper 叙事也更强：这是“动态内核扩展的安全热修复”，不是传统 static kernel patching。

## 8. 权限收紧：helper 级 least privilege

### 8.1 mainline 今天做到哪里

当前 mainline/当前树已经有三类“粗粒度”约束：

1. capability gating：`CAP_BPF` + `CAP_PERFMON` / `CAP_NET_ADMIN`；
2. BPF LSM：可在 `bpf_prog_load`/`map_create`/`token_create` 等点做 MAC / audit policy；
3. BPF token：可限制允许的 syscall command、map type、prog type、attach type。

但 BPF token 的 UAPI 只导出：

- `allowed_cmds`
- `allowed_maps`
- `allowed_progs`
- `allowed_attachs`

**没有 helper allowlist。**

因此“某 tracing 程序为什么能发信号”“某 observability 程序为什么能改包头”这类问题，mainline 目前没有 helper 级回答。

### 8.2 helper 级最小权限策略

建议把 helper 使用权限收紧成三层：

1. **program-class allowlist**  
   例如 XDP/TC 可用 packet mutator；tracing 默认为只读；
2. **provenance allowlist**  
   例如只有 trusted loader / signed agent 才能使用 `send_signal` / `override_return`；
3. **runtime downgrade**  
   已加载程序若超出策略，通过 REJIT 自动收窄 helper 访问范围。

### 8.3 具体例子

- tracing 程序使用 `send_signal`：标记为 over-privileged，默认重写为 audit-only；
- XDP 程序使用 `probe_read_kernel`：若不是明确调试/USDT 场景，标记为 over-privileged；
- profiling 程序使用高精度计时：降到 coarse timer，而不是整程序封杀；
- LSM enforcement agent：只对白名单二进制或 trusted loader 放行 `send_signal` / `override_return`。

## 9. 相关工作与公开实践

### 9.1 公开实践

#### BPF LSM / KRSI

Linux 官方文档明确把 LSM BPF programs 定位为：由 privileged user 用 eBPF 实现 system-wide 的 MAC 与 audit policy。它非常适合 admission control 与 runtime decision logic，但不负责改写已经加载的 BPF 程序。

#### BPF token / Trusted BPF

公开的 LSF/MM/BPF 资料把 BPF token 描述为 least privilege 的重要方向，并明确提出未来可限制“prog types, map types, helpers, etc?”；但到当前 UAPI 为止，helper 级限制仍未落地。

2024 的 BPF LSM / trusted BPF 资料进一步提出“trusted loader + trusted program”的模型：用 fs-verity 和签名来约束谁有资格执行 `prog_load`、`map_create`、`token_create`。这与 helper firewall 互补：trusted loader 解决“谁能加载”，helper firewall 解决“已加载程序到底能做什么”。

#### Google

Google 在 Android/BPF 社区公开材料里强调：

- verified boot 需要覆盖 BPF loader 链路；
- 可信 loader / BPF signing / fs-verity 是现实需求；
- Android 场景存在“single trusted loader”的工程实践。

这说明“trusted BPF loader”并非论文概念，而是已经有明确工业牵引。

#### Meta

Meta 在 LPC 2023 公开介绍 Sysarmor，称其是部署在高威胁环境中的 eBPF security detection and enforcement daemon，并明确指出它可以利用 BPF-LSM 做规则执行。Meta 的实践证明了两点：

1. helper / hook 级的 BPF 安全策略在真实生产环境有需求；
2. 现有公开系统更偏向 detection/enforcement，而不是 live rewrite/hotpatch。

#### 运营侧粗粒度防御

CrowdStrike 对 `CVE-2021-3490` 的分析还指出：Docker 默认 seccomp 配置下通常无法直接使用 eBPF，而当时默认 Kubernetes seccomp 并不会自动封掉这条路。这反映了今天业界常见的做法仍是“整个 `bpf()` syscall 开或关”，而不是 helper 级 least privilege。

### 9.2 学术/系统工作对比

| 工作 | 目标 | 粒度 | 是否 live retrofit 已加载程序 | 与本文关系 |
| --- | --- | --- | --- | --- |
| BPF LSM / KRSI | 用 BPF 做 MAC / audit policy | hook / admission / decision | 否 | 互补；适合 pre-load / admission，不解决 post-load rewrite |
| BeeBox (USENIX Security '24) | 抗 transient execution 的 BPF runtime hardening | verifier/JIT/runtime | 否 | 证明 BPF hardening 是强需求，但不是 helper least privilege |
| VeriFence (RAID '24) | 更精确的 Spectre defense，减少误拒 | verifier precision | 否 | 关注 verifier-side static defense，不是 live helper firewall |
| Agni (CAV '23) | 验证 verifier range analysis 正确性 | verifier correctness | 否 | 解决根因、缩小 verifier TCB；但不处理已加载程序的紧急缓解 |
| SafeBPF (2024) | 用 SFI/MTE 把 BPF 与 kernel 隔离 | runtime isolation | 否 | 更强的隔离方案，但不提供 helper policy 与 live patch 工作流 |
| ePass (2025, eBPF Foundation) | verifier-cooperative runtime enforcement | load-time transform + re-verify | 部分，偏 load path | 与本文最接近；但它公开材料主要讨论 verifier pipeline 内 pass，不是对已加载 live 程序的透明替换 |

本文方案相对这些工作的差异化主要有三点：

1. **post-load**：不是只控制“能否 load”，而是控制“已经 load 的程序还能做什么”；
2. **helper-centric**：不是泛化 verifier precision，而是把 helper 当作 capability surface；
3. **hotpatch-oriented**：目标不是更聪明地接受程序，而是更快地把危险行为关掉。

## 10. 对 OSDI 论文叙事的建议

如果把这一方向写成论文 use case，最强的叙事不是“我们发明了一个 helper classifier”，而是：

1. **现实问题**：today’s BPF least privilege is too coarse  
   现在只有 `CAP_*`、token、trusted loader、syscall-level seccomp；helper 级最小权限缺失。
2. **经验事实**：helper 风险面高度偏斜  
   少数安全 agent 占据绝大多数高危读取面；真正的权限 helper 稀少，因此 fail-closed 成本低。
3. **系统切入点**：BpfReJIT 允许 post-load retrofit  
   比 BPF LSM 更晚、更细；比 kernel livepatch 更小粒度。
4. **安全价值**：漏洞窗口期 mitigation  
   当 verifier bug 刚披露、系统尚未 reboot 时，可以立即缩小 live attack surface。

建议论文实验至少包含三类 case：

1. `Tracee`/`KubeArmor` 的信息读取 helper 审计与降权；
2. `Tetragon` enforcement helper 的 fail-closed 与 allowlist；
3. `Cilium`/`Katran` 数据面 helper 的 role-aware allowlist。

## 11. 结论

本文调研支持一个明确判断：**危险 helper 防火墙是 BpfReJIT 很强的安全 use case。**

原因不在于“helper 本身多么神秘”，而在于三件事刚好同时成立：

1. 真实生态中 helper 风险面极不均匀，适合 targeted policy；
2. mainline 今天缺 helper 级 least privilege；
3. BpfReJIT 天然适合做 post-load retrofit 与热修复。

从工程路线看，建议分两阶段推进：

- **Phase 1（最现实）**：live scanner + policy engine + 从原始 `.bpf.o` 重写 + `re-verify + reload + map reuse + link update`
- **Phase 2（论文亮点）**：kernel baseline snapshot + internal replay verifier + same-prog image swap，实现真正的 live helper firewall / hotpatch

## 参考资料

### 官方文档与源码

1. Linux kernel docs, “eBPF verifier”  
   https://docs.kernel.org/bpf/verifier.html
2. Linux kernel docs, “LSM BPF Programs”  
   https://docs.kernel.org/bpf/prog_lsm.html
3. Linux kernel docs, “eBPF Syscall”  
   https://docs.kernel.org/6.14/userspace-api/ebpf/syscall.html
4. 本仓库内核树：`vendor/linux-framework/include/uapi/linux/bpf.h`
5. 本仓库内核树：`vendor/linux-framework/kernel/bpf/syscall.c`
6. 本仓库内核树：`vendor/linux-framework/kernel/bpf/verifier.c`
7. 本仓库内核树：`vendor/linux-framework/kernel/trace/bpf_trace.c`
8. 本仓库内核树：`vendor/linux-framework/net/core/filter.c`
9. 本仓库内核树：`vendor/linux-framework/fs/bpf_fs_kfuncs.c`

### BPF LSM、token、trusted loader、产业实践

10. Andrii Nakryiko, “Trusted unprivileged BPF”, LSF/MM/BPF 2023  
    https://bpfconf.ebpf.io/bpfconf2023/bpfconf2023_material/Trusted_unprivileged_BPF_LSFMM2023.pdf
11. KP Singh, “BPF LSM etc.”, LSF/MM/BPF 2024  
    https://bpfconf.ebpf.io/bpfconf2024/bpfconf2024_material/BPF_LSM_2024.pdf
12. Neill Kapron, “Verified Boot with BPF”, LSF/MM/BPF 2024  
    https://bpfconf.ebpf.io/bpfconf2024/bpfconf2024_material/LSFMMBPF24_kapron_verified_boot.pdf
13. Meta, “Sysarmor: Meta's eBPF Security Detection and Enforcement Tool”, LPC 2023  
    https://lpc.events/event/17/contributions/1602/
14. eBPF.io, “Introduction, Tutorials & Community Resources”  
    https://ebpf.io/

### CVE 与安全分析

15. NVD, “CVE-2021-3490”  
    https://nvd.nist.gov/vuln/detail/CVE-2021-3490
16. Zero Day Initiative, “CVE-2021-31440: An Incorrect Bounds Calculation in the Linux Kernel eBPF Verifier”  
    https://www.thezdi.com/blog/2021/5/26/cve-2021-31440-an-incorrect-bounds-calculation-in-the-linux-kernel-ebpf-verifier
17. NVD, “CVE-2023-2163”  
    https://nvd.nist.gov/vuln/detail/CVE-2023-2163
18. CrowdStrike, “Exploiting CVE-2021-3490 for Container Escapes”  
    https://www.crowdstrike.com/en-us/blog/exploiting-cve-2021-3490-for-container-escapes/

### 学术与系统工作

19. Di Jin et al., “BeeBox: Hardening BPF against Transient Execution Attacks,” USENIX Security 2024  
    https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di
20. Luis Gerhorst et al., “VeriFence: Lightweight and Precise Spectre Defenses for Untrusted Linux Kernel Extensions,” RAID 2024 / arXiv  
    https://arxiv.org/abs/2405.00078
21. Harishankar Vishwanathan et al., “Verifying the Verifier: eBPF Range Analysis Verification,” CAV 2023  
    https://link.springer.com/chapter/10.1007/978-3-031-37709-9_12
22. Soo Yee Lim et al., “SafeBPF: Hardware-assisted Defense-in-depth for eBPF Kernel Extensions,” 2024  
    https://arxiv.org/abs/2409.07508
23. eBPF Foundation, “ePass: Verifier-Cooperative Runtime Enforcement for eBPF,” 2025  
    https://ebpf.foundation/epass-verifier-cooperative-runtime-enforcement-for-ebpf/

### 本项目相关内部研究

24. `docs/tmp/20260321/bpf_prog_rewrite_kernel_research_20260321.md`
25. `docs/tmp/20260321/bpfrejit_v2_design_gaps_20260321.md`
26. `docs/tmp/20260321/userspace_framework_design_research_20260321.md`
