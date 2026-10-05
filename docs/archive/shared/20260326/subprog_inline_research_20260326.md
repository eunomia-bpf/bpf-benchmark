# Subprog Inline 深度调研

日期：2026-03-26  
面向项目：BpfReJIT / OSDI'26 论文调研

## 摘要

本文调研 BPF `bpf2bpf` subprogram call 的内核实现、真实 corpus 使用情况、subprog inline 的潜在收益与 verifier 风险，以及 BpfReJIT 在 bytecode 层实现 inline 的可行方案。核心结论如下。

1. 该内核树中没有“通用的 subprog inline”机制。`jit_subprogs()` 的做法不是 inline，而是把每个 subprog 拆成独立 `func[i]`、两遍 JIT、再把调用点 patch 到真实子函数地址。x86 后端对普通 `bpf2bpf` 调用使用 `call rel32` 直接调用，而不是常态化 trampoline 或 indirect call。
2. 在 `corpus/build/**/*.bpf.o` 的 568 个对象中，只有 67 个对象、220 个 program 含有真实的本地 `bpf2bpf` 调用，总本地调用点 834 个。总体占比不高，但分布极不均匀：`scx` 只有 4 个对象，却贡献了 531 个调用点，占全 corpus 的 63.7%；`bcc` 和 `linux-selftests` 次之。`tracee` 仅 4 个调用点；`tetragon`、`cilium`、`xdp-tools` 在本 corpus 中为 0。
3. Inline 的性能收益主要来自消除 call/ret 与子函数 prologue/epilogue，减少保存/恢复寄存器与 tail-call counter 维护开销，并为跨 subprog 常量传播、DCE、branch simplification 打开空间。`~10-20ns per call` 只能被表述为“现代 x86 上的数量级估计”，不能写成本文已测得的常数。
4. Verifier 风险是真实存在的，但不是“一定不可行”。主要风险是代码膨胀导致 `insn_processed` 更快逼近 `BPF_COMPLEXITY_LIMIT_INSNS=1M`，以及分支复制带来的 state blow-up；主要潜在好处则是减少 call frame 数、缓和 `MAX_CALL_FRAMES=8` 和部分 tail-call + subprog 组合下的栈深约束。
5. 对当前 BpfReJIT 而言，branch offset 修正不是最大障碍，最大的工程障碍反而是 live `BPF_PROG_REJIT` 路径的 metadata：当前 `union bpf_attr.rejit` 不携带新的 `func_info/line_info`，而 generic subprog inline 会改变 subprog 边界和数量。若坚持 live daemon-only 实现，需要扩展 REJIT UAPI 或把 inline 下沉到内核已有 rewrite 阶段。

本文未运行新的 VM 性能 benchmark；call 开销判断来自内核源码与 JIT 代码路径分析，而非本文现场测量。

## 1. 调研方法与统计口径

### 1.1 代码与文献来源

- 内核实现：`vendor/linux-framework/kernel/bpf/verifier.c`、`vendor/linux-framework/kernel/bpf/core.c`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- UAPI 与 verifier 常量：`vendor/linux-framework/include/uapi/linux/bpf.h`、`vendor/linux-framework/include/linux/bpf.h`、`vendor/linux-framework/include/linux/bpf_verifier.h`
- BpfReJIT daemon：`daemon/src/**`
- LLVM/Clang：官方 Clang attribute 文档、LLVM BPF target 源码
- 论文：K2、Merlin、EPSO

### 1.2 Corpus 统计方法

统计对象为 `corpus/build/` 下所有字面意义上的 `*.bpf.o`，共 568 个 ELF。统计过程分两层。

1. 对象级：扫描 relocation，识别真实本地 `bpf2bpf` 调用。
2. program 级：用 `runner/build/micro_exec list-programs --program <obj>` 枚举 entry programs，再基于本地 subprog call graph 计算每个 entry 可达的 subprog 数与调用点数。

### 1.3 “真实 bpf2bpf call”的判定口径

不能把所有 `src_reg=1` 的 `BPF_CALL` 都算成本地 subprog call。原因是 kfunc/extern 也可能以同样的 opcode 形式出现，但 relocation 目标是 `UND` 外部符号，不是本 ELF 内的 subprog。

本文采用的严格口径是：

- 指令编码满足 `code == BPF_JMP | BPF_CALL`
- `src_reg == BPF_PSEUDO_CALL`
- relocation 最终解析到同一 ELF 的本地可执行 section 或本地 `STT_FUNC`

反例是 `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_module.bpf.o`。它含有形如 `85 10 ...` 的 call，但 relocation 目标是 `bpf_testmod_test_mod_kfunc` 等 `UND` 符号，因此应归类为 kfunc/extern，而不是本地 subprog call。

### 1.4 统计稳健性说明

- `list-programs` 在 98 个对象上失败，主要是 upstream selftests 的负例对象。
- 但这 98 个失败对象里，只有 5 个对象真正含有本地 `bpf2bpf` 调用。
- 因此对象级总量统计是稳健的；program 级统计总体也可用，但对少数失败对象采用了“按 ELF 非本地可执行函数回退枚举”的近似。

## 2. BPF bpf2bpf call 机制

### 2.1 Bytecode 编码与 verifier 入口

`bpf2bpf` 调用在 bytecode 层编码为 `BPF_JMP | BPF_CALL`，`src_reg=BPF_PSEUDO_CALL`，`imm` 为 PC-relative offset。BpfReJIT daemon 里也显式同步了这个约定：`daemon/src/insn.rs` 把 `BPF_PSEUDO_CALL` 定义为 1。

verifier 首先通过 `check_subprogs()` 划分 subprog 边界，并要求普通 jump 不能跨 subprog 边界；call 作为唯一合法的跨 subprog 控制转移保留下来。相关代码位于：

- `vendor/linux-framework/kernel/bpf/verifier.c:3998-4051`

这一步已经说明：主线 verifier 的基本模型不是“先 inline 再验证”，而是“保留 call graph，显式跟踪 subprog 边界”。

### 2.2 栈深、call frame 与 tail-call 联动

`check_max_stack_depth_subprog()` 会显式遍历 `bpf2bpf` call graph，维护返回地址栈与 frame 深度，并强制：

- `MAX_CALL_FRAMES = 8`
- 组合栈深不能超过 `MAX_BPF_STACK`
- 当 tail call 与 subprog call 混用时，前序 frame 的深度过大将被拒绝

关键代码位于：

- `vendor/linux-framework/kernel/bpf/verifier.c:7042-7200`
- `vendor/linux-framework/include/linux/bpf_verifier.h:324`

这里有两个和 inline 直接相关的观察。

1. Inline 会减少 verifier 看到的 call frame 数，因此在某些深调用链程序上可能缓解 `MAX_CALL_FRAMES=8` 的硬限制。
2. verifier 针对“tail call reachable + 多层 subprog frame”有额外的深度限制。若 inline 消除了中间 frame，可能间接改善这类程序的接受性。

### 2.3 Global/local subprog 的验证方式

该内核树对 global subprog 和 local/static subprog 的验证方式不同。`do_check_subprogs()` 会把 global subprog 单独拿出来验证成“只要参数类型匹配就安全”；而 local subprog 则更多依赖 caller context。

相关代码：

- `vendor/linux-framework/kernel/bpf/verifier.c:25085-25133`
- `micro/build-arm64/vendor/libbpf/prefix/include/bpf/bpf_helpers.h:64-70`

其中 `__hidden` 注释明确写道：它会把非 static BPF subprogram 在 verifier 视角下“有效地当成 static”，从而允许利用 caller context 做更宽松的验证。这说明 verifier 本身已经具备某种“上下文敏感”的函数分析，但这不等于代码 inline，也不等于优化器可以跨 call boundary 做 DCE/const prop。

### 2.4 `jit_subprogs()` 的真实工作方式

`jit_subprogs()` 是本文最关键的源码点。它的机制不是把 callee 内联进 caller，而是：

1. 扫描整段 bytecode，定位 pseudo call / pseudo func
2. 把 call 目标的 subprog id 暂时写进 `insn->off`
3. 把原始 `imm` 暂存到 `env->insn_aux_data[i].call_imm`
4. 把每个 subprog clone 成独立 `func[i]`
5. 每个 `func[i]` 各自做第一遍 JIT
6. 再把 callsite patch 成指向 `func[subprog]->bpf_func`
7. 做第二遍 JIT，最后把 `prog->aux->func = func`

关键代码：

- `vendor/linux-framework/kernel/bpf/verifier.c:23129-23320`
- `vendor/linux-framework/kernel/bpf/verifier.c:23338-23380`

这意味着 `func[]` 的语义是“JIT 后子函数地址数组”，而不是 inline buffer。`prog->aux->func`/`real_func_cnt` 提供了：

- 第二遍 JIT 的目标地址来源
- 某些架构在偏移不够时的备用地址表
- `BPF_PSEUDO_FUNC` 场景下的真实函数地址

### 2.5 `bpf_jit_get_func_addr()` 与 direct call / address table

`bpf_jit_get_func_addr()` 对 `BPF_PSEUDO_CALL` 的处理也很清楚：

- 首遍 JIT 时地址未知，先放占位
- 额外 pass 时通过 `prog->aux->func[off]->bpf_func` 回填

代码：

- `vendor/linux-framework/kernel/bpf/core.c:1249-1286`

因此，`func[]` 主要承担“地址解析与回填”的角色。对 x86 这样的后端，最终 hot path 仍是 direct call；对偏移编码能力较弱或需要额外寻址的后端，`func[]` 则更像 JIT-time address table。

### 2.6 x86 JIT：普通 subprog call 是 direct `call rel32`

x86 后端的 `emit_call()` 直接发射 opcode `0xE8`，即 `call rel32`：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:574-577`

`BPF_JMP | BPF_CALL` 的 lowering 路径在：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2473-2500`

如果是普通 `bpf2bpf` call，最终就是：

1. 可选：恢复 tail-call counter 指针
2. 可选：保存/恢复私有 frame pointer 辅助寄存器
3. 可选：`CONFIG_CALL_THUNKS` 下插入 call-depth accounting
4. 发射 `call rel32`

因此，对现代 x86 而言，本文研究对象的本质是“direct call + 子函数进入/退出开销”，而不是“indirect call dispatch 开销”。

### 2.7 call overhead 的组成

对 x86 而言，`bpf2bpf` 调用的成本主要由以下部分组成。

1. 调用本身：`call rel32` / `ret`
2. callee 入口/出口：`push rbp`、`mov rbp, rsp`、可选 `sub rsp, rounded_stack_depth`、`leave`
3. 可选 callee-saved 寄存器保存/恢复：`rbx/r13/r14/r15`
4. 可选 tail-call reachable 维护：保存/恢复 `tail_call_cnt_ptr`
5. 可选 private stack / arena / exception callback 相关保存恢复
6. 可选安全缓解：`CONFIG_CALL_THUNKS` 下的 accounting thunk 模板

代码位置：

- prologue：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:470-556`
- callee 寄存器保存/恢复：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:355-390`
- prologue 中的实际保存：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1712-1738`
- epilogue：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2761-2787`
- call thunk 计数：`vendor/linux-framework/arch/x86/include/asm/alternative.h:117-130` 与 `vendor/linux-framework/arch/x86/kernel/callthunks.c:301-318`

关于数字口径，`~10-20ns per call` 可以作为现代 x86、热路径、常见配置下的数量级估计，但不应被写成本文已经测得的常数。更稳妥的论文表述应是：

> x86 上普通 `bpf2bpf` 调用最终落到 direct call，但仍需承担每次 call 的 prologue/epilogue、可选寄存器保存恢复与 tail-call counter 维护；在 call-dense 程序中，这一端到端开销可达十纳秒量级，且强依赖内核配置、JIT 后端与 callee 形态。

### 2.8 “trampoline” 与 subprog call 的关系

这里需要把三件事分开。

1. 普通 `bpf2bpf` 调用：x86 上是 direct `call rel32`。
2. BPF trampoline：用于 fentry/fexit/freplace/struct_ops 等 attach 或替换路径。
3. call thunk：x86 的安全/CFI 相关 call-depth accounting 机制。

x86 prologue 里有一句注释：“BPF trampoline can be made to work without these nops”，说明入口处预留了 patch 空间：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:517-520`

但这不意味着普通 subprog 调用经由 trampoline 分派。相反，trampoline 更像 attach-time / patch-time 基础设施。对 live REJIT 来说，这一点更明显：`BPF_PROG_REJIT` swap 完 JIT image 后，还会显式调用 `bpf_trampoline_refresh_prog(prog)` 去刷新附着点：

- `vendor/linux-framework/kernel/bpf/syscall.c:3801-3804`
- `vendor/linux-framework/include/linux/bpf.h:1728-1729`

结论是：ordinary `bpf2bpf` call 的 hot path 不经过 trampoline；trampoline 是程序生命周期和 attach 语义的一部分，不是 subprog call dispatch 本身。

### 2.9 `bpf_prog_select_runtime()` 与 tail call

本树里没有 `bpf_prog_select_func()`；对应的运行时选择函数是 `bpf_prog_select_runtime()`：

- `vendor/linux-framework/kernel/bpf/core.c:2511-2575`

它在 runtime 选定之后调用 `bpf_check_tail_call()`，原因是 tail-call 兼容性取决于最终使用 JIT 还是 interpreter，以及该 JIT 是否支持“subprog calls + tail calls”的组合。x86 明确返回支持：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3986-3990`

因此，tail call 和 subprog call 的关系是：

- tail call：跨 program 跳转，不返回
- subprog call：同一 program 内返回式调用
- 兼容性检查在 runtime 选定之后做

这一点对 inline 的启示是：inline 不改变 tail call helper 的语义，但可以减少“为了跨 subprog 保持 tail_call counter 而注入的额外开销”。

## 3. Corpus 数据

### 3.1 全局统计

对象级与 program 级统计结果如下。

| 指标 | 数值 |
|---|---:|
| `.bpf.o` 总数 | 568 |
| 含真实本地 `bpf2bpf` call 的对象数 | 67 |
| 对象占比 | 11.8% |
| program 总数 | 1979 |
| 含真实本地 `bpf2bpf` call 的 program 数 | 220 |
| program 占比 | 11.1% |
| 本地 `bpf2bpf` call site 总数 | 834 |

对 call-using program 的 call graph 统计：

| 指标 | 数值 |
|---|---:|
| 平均可达函数数（含 entry） | 3.45 |
| 平均 callee-only 函数数 | 2.45 |
| 中位数 callee-only 函数数 | 1 |
| 平均每个 call-using program 的可达 call site 数 | 3.81 |
| 中位数每个 call-using program 的可达 call site 数 | 1 |
| P90 每个 call-using program 的可达 call site 数 | 6 |

对 callee 大小分布（按“被某个本地 call 真正指向过的唯一 callee 函数”统计）：

| 指标 | 数值（insns） |
|---|---:|
| unique callee 数 | 262 |
| 平均 callee 大小 | 148.45 |
| 中位数 callee 大小 | 40.5 |
| P90 | 231 |
| P99 | 996 |

这里分布明显重尾。均值被极少数超大 callee 拉高，例如：

- `KubeArmor/enforcer.bpf.o:match_and_enforce_path_hooks`，11348 insns
- `KubeArmor/enforcer.bpf.o:match_net_rules`，2998 insns
- `scx/scx_rusty_main.bpf.o:dom_xfer_task`，1608 insns

因此论文里如果只写“平均 callee 大小约 149 insns”会失真，必须同时给中位数。

### 3.2 项目分布

用户特别点名的项目里，真实结论并不是“tracee/tetragon/cilium 用得多”。结果如下。

| 项目 | 对象数 | 含调用对象 | 调用点 | program 数 | 含调用 program | 备注 |
|---|---:|---:|---:|---:|---:|---|
| linux-selftests | 369 | 31 | 173 | 821 | 59 | 对象数最多，但多为测试覆盖 |
| bcc | 57 | 24 | 92 | 365 | 92 | 中等密度，工具类程序常见 |
| scx | 4 | 4 | 531 | 71 | 47 | 绝对热点，调用密度极高 |
| KubeArmor | 3 | 1 | 10 | 63 | 7 | callee 极重尾 |
| tracee | 2 | 1 | 4 | 170 | 2 | 真实本地 subprog 使用很少 |
| loxilb | 3 | 2 | 5 | 18 | 4 | 轻度使用 |
| katran | 5 | 1 | 3 | 5 | 1 | 轻度使用 |
| tetragon | 23 | 0 | 0 | 90 | 0 | 本 corpus 为 0 |
| cilium | 3 | 0 | 0 | 36 | 0 | 本 corpus 为 0 |
| xdp-tools | 13 | 0 | 0 | 99 | 0 | 本 corpus 为 0 |
| bpftrace | 5 | 0 | 0 | 7 | 0 | 本 corpus 为 0 |

三个最重要的观察。

1. `scx` 虽然对象数很少，但贡献了 531/834 = 63.7% 的全部本地 call site，是最值得做 inline 的真实热点。
2. `tracee` 在对象和 program 数量上很大，但真实本地 `bpf2bpf` call 极少，说明“函数多”不等于“子程序调用多”。
3. `tetragon`、`cilium` 在当前 corpus 中没有真实本地 subprog call，因此不能把它们当成 subprog inline 的主战场。

### 3.3 Top objects 与 Top programs

按对象级调用点数排序，前几名如下。

| 排名 | 对象 | 调用点数 |
|---|---|---:|
| 1 | `scx/scx_lavd_main.bpf.o` | 455 |
| 2 | `scx/scx_rusty_main.bpf.o` | 53 |
| 3 | `linux-selftests/.../cpumask_success.bpf.o` | 43 |
| 4 | `linux-selftests/.../test_usdt.bpf.o` | 25 |
| 5 | `linux-selftests/.../map_kptr.bpf.o` | 22 |
| 6 | `scx/scx_flash_main.bpf.o` | 16 |
| 7 | `bcc/libbpf-tools/memleak.bpf.o` | 16 |

按 program 级可达调用点数排序，前几名几乎都来自 `scx`：

| 排名 | program | 对象 | 可达 call site | 可达函数数 |
|---|---|---|---:|---:|
| 1 | `lavd_enqueue` | `scx_lavd_main.bpf.o` | 84 | 34 |
| 2 | `lavd_dispatch` | `scx_lavd_main.bpf.o` | 69 | 38 |
| 3 | `lavd_select_cpu` | `scx_lavd_main.bpf.o` | 60 | 21 |
| 4 | `lavd_cpu_offline` | `scx_lavd_main.bpf.o` | 40 | 21 |
| 5 | `lavd_cpu_online` | `scx_lavd_main.bpf.o` | 40 | 21 |

这说明对 `scx` 这类 program，subprog inline 不应被视为“微优化”，而可能是重要的 hot-path 优化入口。

### 3.4 对论文表述的直接启示

最稳妥的论文表述不是“bpf2bpf calls are ubiquitous”，而是：

> 在大规模 corpus 中，真实本地 `bpf2bpf` 调用只出现于约 11% 的对象和 program；但其分布高度集中，`scx` 这类调度器式程序形成显著热点，恰好是 subprog inline 最可能带来真实收益的工作负载。

## 4. Inline 收益分析

### 4.1 直接收益：消除 call/ret 与 prologue/epilogue

对 x86 而言，普通 `bpf2bpf` call 已经是 direct call，因此 inline 的第一层收益不是“把 indirect 改成 direct”，而是把整个 call boundary 拿掉：

- `call rel32`
- callee entry/exit
- 可选寄存器保存恢复
- 可选 tail-call counter 维护
- 可选 thunk / CFI 相关模板

如果某个 hot program 每次包处理、调度决策或事件处理都要跨越数个小 subprog，这部分成本会稳定出现。`scx` 的 top programs 正好属于这种高 call 密度场景。

### 4.2 间接收益：减少 spill/fill 与保存恢复

当前 verifier/JIT 已经有一套“fastcall + spill/fill 清理”的 call-adjacent 优化，其意图很明确：如果 helper/kfunc 最终会被 inline 或被 JIT 特判，外围 spill/fill 就是冗余的，可以删除。

相关代码：

- `vendor/linux-framework/kernel/bpf/verifier.c:18616-18629`
- `vendor/linux-framework/kernel/bpf/verifier.c:18728-18810`

这说明内核开发者也承认“跨 call boundary 的冗余保存恢复”是值得消掉的。把这一思路推广到 generic subprog inline，是自然延伸。

### 4.3 更重要的收益：跨 subprog 常量传播与 DCE

Inline 真正的高价值不只在 call overhead，而在于把 caller 里的常量、条件与 dead path 带进 callee。

典型收益包括：

1. 常量参数穿透 call boundary，触发 callee 内部比较折叠
2. callee 内 dead branch、dead load、dead stack slot 被 DCE 掉
3. caller/callee 之间多余的 move、spill、reload 被合并
4. 后续的 branch flip、rotate、extract、wide-mem 等局部 pass 可以跨原函数边界看到更长的 pattern

对 BpfReJIT 这类 bytecode optimizer 来说，这一层通常比单纯省掉 call/ret 更重要。

### 4.4 Inline 对 verifier 接受性的潜在正收益

Inline 并非只会让 verifier 更难，也可能让 verifier 更容易：

1. call frame 数减少，缓解 `MAX_CALL_FRAMES=8`
2. 某些跨 frame 的 stack-depth 累积约束变弱
3. dead subprog 分支先被常量传播裁掉，反而降低 processed states

因此，subprog inline 的论文叙事不应该只强调“可能导致程序变大”，也要指出它可能减少 verifier 看到的动态验证搜索空间。

### 4.5 成本与负面收益

最大的负面收益来自代码复制：

1. 多 callsite 共享的大 callee 会被复制，导致代码膨胀
2. 被复制的条件分支会把 verifier state 空间也复制一遍
3. 更大的 JIT image 可能伤害 I-cache

这在 `scx` 和 `KubeArmor` 上尤其重要：前者调用密度高，后者 callee 大小极重尾。对这类程序做“全量 aggressive inline”很危险。

## 5. Verifier 接受性与风险

### 5.1 相关硬限制

该内核树中，与 subprog inline 最相关的 verifier 限制是：

- `BPF_COMPLEXITY_LIMIT_INSNS = 1,000,000`
  - `vendor/linux-framework/include/linux/bpf.h:2311`
  - enforced at `vendor/linux-framework/kernel/bpf/verifier.c:21578-21582`
- `BPF_COMPLEXITY_LIMIT_STATES = 64`
  - `vendor/linux-framework/kernel/bpf/verifier.c:196`
  - checked at `vendor/linux-framework/kernel/bpf/verifier.c:21059-21060`
- `MAX_CALL_FRAMES = 8`
  - `vendor/linux-framework/include/linux/bpf_verifier.h:324`
- `BPF_MAX_SUBPROGS = 256`
  - `vendor/linux-framework/include/linux/bpf_verifier.h:638`

其中最该注意的是：`1M` 限制是 processed instructions，而不是静态指令数。inline 造成的分支复制会使 `env->insn_processed` 上升得更快。

### 5.2 为什么 inline 会导致 state blow-up

如果一个 callee 含有：

- 多个条件分支
- 指针类型分叉
- map/nullability 分叉
- 循环展开后的复杂条件

那么把它复制到多个 caller 后，verifier 不再只分析“一份函数体 + 多次调用边”，而是分析“多份已复制函数体 + 多份 caller 上下文”。这会增加：

- CFG 节点数
- 每个 insn 的 state 合并压力
- processed instructions

因此，对“多 callsite、分支丰富、callee 较大”的函数，inline 很可能是 verifier 负优化。

### 5.3 为什么 inline 仍然可能有利于 verifier

反过来，如果 callee：

- 很小
- 只有 1 个或很少 callsite
- caller 传入的是常量或窄化后的寄存器状态

那么 inline 后常量传播和 DCE 能够直接把一部分分支裁掉，最终让 verifier 看到的有效路径更少。Corpus 里 call-using program 的中位数只有 1 个 callee、1 个 callsite，这正好说明“保守 inline”是有现实土壤的。

### 5.4 建议的 verifier-friendly 预算策略

对论文和原型都建议采用 budgeted inline，而不是 blanket inline。一个可辩护的初始策略是：

1. 只 inline leaf subprog 或单 callsite subprog
2. callee 静态大小先设阈值，如 `<= 64` 或 `<= 128` insns
3. 预测代码增长不能超过 caller 原始大小的一定比例，例如 `<= 20%`
4. 跳过 address-taken 的 callee，即被 `BPF_PSEUDO_FUNC` 引用的 callback/function pointer
5. 跳过含复杂分支、异常 callback、超大 stack frame 的 callee
6. 若 projected reachable callsites 很多，但 callee 很大，则只对 hot callsite 做 PGO-guided inline

这是更符合 corpus 真实分布的策略：优先抓住大量“小而单次调用”的机会，避免被 `scx`/`KubeArmor` 的重尾工作负载拖进 verifier 泥潭。

## 6. 已有实现与论文

### 6.1 主线/本树已有的“局部 inline”机制

该内核树没有 generic subprog inline，但已经存在三类“局部 inline-like”机制。

1. helper inline 判定  
   `verifier_inlines_helper_call()` 会把特定 helper 视为 JIT/修正阶段可 inline 的对象。

2. fastcall spill/fill 清理  
   `mark_fastcall_pattern_for_call()` 与后续逻辑会识别围绕 call 的 spill/fill 模式，如果 helper/kfunc 最终按 fastcall/inline 处理，就删掉冗余保存恢复。

3. `bpf_loop` inline  
   `inline_bpf_loop()` / `optimize_bpf_loop()` 会直接把 helper 调用替换成显式循环 bytecode。

代码位置：

- helper inline：`vendor/linux-framework/kernel/bpf/verifier.c:18616-18629`
- fastcall pattern：`vendor/linux-framework/kernel/bpf/verifier.c:18728-18810`
- `bpf_loop` inline：`vendor/linux-framework/kernel/bpf/verifier.c:24721-24856`

因此，“内核已经接受有限形式的 inline rewrite”是成立的；“内核已经支持通用 subprog inline”则不成立。

### 6.2 LLVM BPF backend 与 `always_inline`

Clang 官方文档对 `always_inline` 的定义是：

- 禁用普通 inline heuristics
- regardless of optimization level, always attempt to inline
- 但不保证一定发生 inline

来源：Clang AttributeReference 的 `always_inline` 条目。

同时，从 LLVM BPF target 的官方源码看，BPF target 有自己的若干 target-specific passes，例如：

- `BPFCheckAndAdjustIR`
- `BPFPreserveStaticOffsetPass`
- `BPFIRPeepholePass`
- `BPFASpaceCastSimplifyPass`

但没有看到“BPF backend 专门实现一个 generic function inline pass”的证据。换言之：

- `always_inline` 是 Clang/LLVM 通用 inliner 语义
- BPF target 会做一些 verifier-friendly/target-friendly IR 与 peephole 调整
- 剩余的 `bpf2bpf` call 并不是由“BPF backend 故意保留函数边界以便 JIT 优化”导致，而更多是普通 inline 代价模型、代码复用、`__noinline` 注解或目标代码大小权衡的结果

补充一点：libbpf 常用的 `bpf_helpers.h` 里也把 `__always_inline` 直接定义成 `inline __attribute__((always_inline))`：

- `micro/build-arm64/vendor/libbpf/prefix/include/bpf/bpf_helpers.h:53-55`

### 6.3 K2

K2 的论文是：

- Qiongwen Xu et al., *Synthesizing Safe and Efficient Kernel Extensions for Packet Processing*, SIGCOMM 2021

K2 的核心是对 BPF bytecode 做 synthesis-based rewrite 与等价性/安全性检查。论文中把 helper/function call 视为会限制跨 call 优化边界的因素，并未呈现一个“专门针对 BPF subprog 的 generic inline pass”。因此它更像“跨全程序搜索 + 保守 call 建模”，而不是“系统性消灭 subprog calls”。

### 6.4 Merlin

Merlin 的论文是：

- Jinsong Mao et al., *Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness*, ASPLOS 2024

Merlin 的卖点是 customized LLVM passes + bytecode refinement，主打 instruction merging 与 strength reduction。它并没有把“generic subprog inline”当成一个明确独立贡献。

论文中还有一句对本文很关键的话：有 7 个 local functions 不能单独验证，而是在 main function 的上下文中验证。这说明 Merlin 依赖并顺应了内核 verifier 对 local/global 函数的既有机制，而不是自己重写 subprog 结构。

### 6.5 EPSO

EPSO 的论文是：

- Xiaokang Huang et al., *EPSO: Collaborative Optimization of eBPF Bytecode for Lightweight JIT Execution*, arXiv 2025

从论文描述看，EPSO 的核心是 intra-block、固定窗口、协同优化与 JIT 友好变换，并非 interprocedural / inter-subprog 优化框架。因此它与本文讨论的 generic subprog inline 基本不在同一层面。

### 6.6 结论

现有工作可以分为三类：

1. 主线内核：接受若干 ad-hoc inline-like rewrite，但没有 generic subprog inline
2. LLVM/Clang：有通用 inliner 与 `always_inline`，但没有 BPF-specific generic subprog inline
3. 研究系统：K2/Merlin/EPSO 都没有把“系统性 subprog inline”做成主角

这意味着：如果 BpfReJIT 把“budgeted subprog inline”做好，它在论文上是有新意的，但 claim boundary 必须谨慎，不能把它包装成“整个 BPF 社区此前完全没有 inline 语义”。

## 7. BpfReJIT 实现方案

### 7.1 当前 daemon 已具备的基础设施

当前 daemon 不是从零开始。已经有几块关键的 subprog-aware 基础设施。

1. `CFGAnalysis` 能识别 pseudo-call 目标并记录 subprog entries  
   `daemon/src/analysis/cfg.rs:43-185`

2. `fixup_all_branches()` 已经会修 surviving pseudo-call 的 PC-relative offset  
   `daemon/src/passes/utils.rs:20-53`

3. `eliminate_unreachable_blocks_with_cfg()` 已经知道“dead callsite 被删后，orphaned subprog 也要删”，避免 verifier 报 unreachable insn  
   `daemon/src/passes/utils.rs:70-140`

4. DCE 单测已经覆盖“preserve live subprog / delete orphaned subprog”  
   `daemon/src/passes/dce.rs:183-288`

同时，也有很明确的现状证据：现有 transform pass 仍把 subprog 当成未支持特性。例如 `RotatePass` 明确写着“当前 safety checks 是 intraprocedural；遇到 pseudo-calls 就跳过”：

- `daemon/src/passes/rotate.rs:58-73`

这意味着新 pass 的正确定位不是“重写整个 pass framework”，而是“补上一个真正 subprog-aware 的 pass，并让现有 pass 在 inline 之后吃到更长的基本块”。

### 7.2 建议的 `SubprogInlinePass` 算法

推荐做成一个独立 pass：`SubprogInlinePass`，放在 `const_prop` 之前或和 `const_prop`/`dce` 形成小闭环。

#### 步骤 1：建立 call graph 与候选集

对每个 pseudo-call：

1. 找到 caller subprog 与 callee subprog
2. 统计 callee 大小、callsite 数、是否 leaf、是否 address-taken
3. 估计 inline 后的代码增长

初始版本建议只选：

- leaf callee
- 单 callsite callee
- 小 callee
- 非 callback / 非 address-taken

#### 步骤 2：复制 callee 指令到 caller

对选中的某个 callsite `pc = k`：

1. 删除原 `call` 指令
2. 把 callee body clone 到 `k`
3. 对 clone 内所有 `EXIT` 改写成跳往 continuation 的 `JA`

如果 callee 内还含有对子 subprog 的 pseudo-call，有两种策略：

- v1：保留这些 nested call，不递归 inline
- v2：递归 inline，但受全局 budget 限制

v1 更稳妥，也更适合先落地。

#### 步骤 3：修复 branch offset

需要区分两类 offset。

1. clone 内部的局部 branch  
   这些 offset 必须在 clone 生成时重算，因为它们现在跳的是 clone 内新位置。

2. 程序其余部分的 branch / pseudo-call  
   这些可以继续复用 daemon 现有的 `fixup_all_branches()` 逻辑做全局修正。

换句话说，inline pass 只需要自己处理“新复制出来的内部边”，而现有基础设施已经足够处理“旧指令被整体平移后的外部边”。

#### 步骤 4：处理 stack frame

这是 bytecode 层 inline 的真正难点。

问题本质是：原本 callee 的局部栈槽相对于 callee 自己的 `r10` 定位；inline 之后，caller 与 callee 共享同一个物理 frame pointer `r10`，如果不做重映射，两者栈槽会冲突。

推荐做法是“frame-base delta 重写”。

1. 先静态估计 callee 的局部栈深 `callee_stack`
2. 给这次 inline 实例分配一个新的栈片段 `delta = round_up(callee_stack, 8)`
3. 对 clone 内所有“源自 `r10 + const` 的栈地址”统一减去 `delta`

这里不能只改 `[r10 + off]` 这种直接访存，还要处理常见的 helper 参数 materialization：

- `r1 = r10`
- `r1 += -32`
- `call helper(...)`

因此需要一个小型的 intraprocedural frame-pointer provenance analysis，跟踪每个寄存器是否等于：

- `r10 + const`
- unknown

然后对所有以此类寄存器为 base 的 stack access / helper arg setup 做 rebasing。

这是可以做的，因为 BPF verifier 本身就要求栈地址必须是 frame-pointer-derived 且偏移可静态追踪；也正因为如此，分析域不需要很复杂。

#### 步骤 5：删除孤儿 subprog

如果某个 callee 的所有 direct callers 都被 inline 且它又不是 address-taken function，那么原 subprog 需要被删除；否则 verifier 可能把它视为 unreachable code。

这一步可以直接复用当前 daemon 对 orphaned subprog 的处理思路：

- `daemon/src/passes/utils.rs:70-140`
- `daemon/src/passes/dce.rs:209-288`

#### 步骤 6：inline 之后立刻跑 `const_prop + dce`

Inline 本身只创造机会，不会自动产生全部收益。最合理的局部 pipeline 是：

1. `subprog_inline`
2. `const_prop`
3. `dce`
4. 必要时再跑一次 branch simplification

这样 caller 传入的常量才能尽快穿透到 clone 内部，真正把代码膨胀压回去。

### 7.3 成本模型建议

建议把成本模型写成一个简单可解释的式子：

`benefit(site, callee) = hotness * (T_call + T_save_restore + T_cross_boundary_opt) - lambda * code_growth - mu * verifier_risk`

其中：

- `hotness` 可来自 BpfReJIT 现有 profiler / `run_cnt` / PGO
- `T_call` 是十纳秒量级的 direct-call boundary 成本
- `T_save_restore` 是可选 spill/fill 与 prologue/epilogue 成本
- `T_cross_boundary_opt` 代表 const prop/DCE 带来的附加收益
- `code_growth` 由 callee 大小与 callsite 数估计
- `verifier_risk` 用预测后的指令数、分支数、callee 是否分支重等 proxy 近似

若没有 PGO，建议退化成保守启发式：

- 单 callsite优先
- leaf 优先
- 小 callee 优先

### 7.4 当前 live REJIT 路径的真正障碍：metadata

对当前 BpfReJIT 来说，generic subprog inline 最大的工程障碍不是 branch fixup，而是 metadata。

当前 `union bpf_attr.rejit` 的 UAPI 只有：

- `prog_fd`
- `insn_cnt`
- `insns`
- `log_level/log_size/log_buf`
- `fd_array/fd_array_cnt`
- `flags`

见：

- `vendor/linux-framework/include/uapi/linux/bpf.h:1935-1945`

也就是说，REJIT 并不接收新的 `func_info` / `line_info`。内核里 `bpf_prog_rejit()` 甚至明确写道：

- 由于 REJIT attr 不传 BTF/func_info，只对 `BPF_PROG_TYPE_EXT` 特判复制旧的 `btf/func_info/func_info_aux`

代码：

- `vendor/linux-framework/kernel/bpf/syscall.c:3688-3724`

而 verifier 的 `check_btf_info_early()` / `check_btf_info()` 也明确说明：如果 attr 里 `func_info_cnt` 与 `line_info_cnt` 都为 0，就直接跳过这条 metadata 路径：

- `vendor/linux-framework/kernel/bpf/verifier.c:19792-19836`

这带来一个直接结论：

> 纯 userspace daemon 侧的 live subprog inline 如果改变了 subprog 边界/数量，就很难与现有 REJIT UAPI 的 metadata 语义兼容。

进一步的证据是，内核自己的 rewrite 路径会同步裁剪 `func_info` 并在最终阶段重写 `insn_off`：

- 删除/压缩 `func_info`：`vendor/linux-framework/kernel/bpf/verifier.c:22462-22472`
- 最终按 subprog start 重写 `func_info[i].insn_off`：`vendor/linux-framework/kernel/bpf/verifier.c:19584-19590`

这说明“metadata 同步维护”本身并非不可做，但最好放在内核已有 rewrite 流程里做，而不是完全丢给当前的 daemon-only REJIT 接口。

### 7.5 三种落地路径

#### 路径 A：纯 daemon、只改指令流

优点：

- 实现简单
- 与现有 pass framework 最一致

缺点：

- 一旦 subprog 边界变化，就会撞上 `func_info/line_info` 问题

结论：不适合作为最终形态，除非 pass 被严格限制到“不改变 subprog 数量和边界”，而这几乎等于放弃 generic inline。

#### 路径 B：扩展 `BPF_PROG_REJIT` UAPI

思路是给 REJIT attr 增加：

- `prog_btf_fd`
- `func_info`
- `func_info_cnt`
- `line_info`
- `line_info_cnt`

让 daemon 在 userspace 重写完 bytecode 之后，把匹配的新 metadata 一并提交。

优点：

- 保持 daemon 主导
- 论文 story 清晰

缺点：

- 需要改 UAPI 和内核 REJIT 路径
- userspace 还要学会重写 BTF.ext 对应记录

#### 路径 C：daemon 生成 inline plan，内核在 verifier rewrite 阶段执行

思路是：

1. daemon 负责候选选择、热度判断、成本模型
2. 内核在 `bpf_check()` 期间、类似 `optimize_bpf_loop()` 的位置，执行真正的 subprog inline
3. 复用内核现有的 `subprog_info`/`func_info`/`linfo` 调整逻辑

优点：

- 最符合现有 verifier/JIT 架构
- metadata 问题最自然

缺点：

- 需要 kernel-side pass
- “daemon 在 bytecode 层做 inline”这一叙事会弱一些

如果目标是 OSDI 论文和可稳定复现的系统实现，我认为路径 C 的工程风险最低。

### 7.6 推荐的分阶段原型

#### Phase 1：分析版，不真正 inline

输出每个 live program 的：

- call graph
- 每个 callee 的大小、callsite 数、stack 深度估计
- projected inline growth

先把真实可 inline 候选集暴露出来，顺便验证成本模型。

#### Phase 2：只做 leaf + single-callsite + small callee

限制：

- 无 `BPF_PSEUDO_FUNC`
- 无 callback
- callee <= 64/128 insns
- projected growth 小

这是最容易在 corpus 中形成“高成功率、低 verifier 风险”的版本。

#### Phase 3：PGO-guided selective inline

对 `scx` 这类密集工作负载，只 inline 热 callsite，不做全量复制。

#### Phase 4：metadata-aware full inline

配合 REJIT UAPI 扩展或 kernel-side inline，把真正改变 subprog 布局的版本做完整。

## 8. 对论文写作的建议

### 8.1 可以稳写的 claim

1. 主线内核/本树没有 generic subprog inline；已有的是 helper inline、fastcall spill/fill 清理、`bpf_loop` inline 这类特例。
2. 真正的本地 `bpf2bpf` call 在大 corpus 中总体占比不高，但在 `scx` 等 hot workload 上高度集中。
3. x86 上 subprog call 已经是 direct call，因此 inline 的主要收益来自 call boundary elimination 和 cross-boundary optimization，而不是“把 indirect 改 direct”。
4. budgeted inline 有望在 call-dense 程序上带来真实收益，但 blanket inline 会引入 verifier/code-size 风险。

### 8.2 不建议直接写死的 claim

1. “每次 call 固定省 10-20ns”  
   应改成“十纳秒量级、配置相关”

2. “tracee/tetragon/cilium 是主要受益对象”  
   当前 corpus 证据不支持

3. “inline 必然让 verifier 更难”  
   证据不充分，且与 call-frame 减少的正效应相矛盾

### 8.3 最值得做的实验

1. `scx` 上做 selective inline 与 full inline 对比
2. 对 call-using program 测：
   - verifier processed insns
   - max_states_per_insn
   - final insn count
   - JIT image size
   - runtime
3. 把“单 callsite 小 callee”与“多 callsite 大 callee”分开汇报，避免均值误导

## 参考资料

### 内核与项目代码

1. `vendor/linux-framework/kernel/bpf/verifier.c`
2. `vendor/linux-framework/kernel/bpf/core.c`
3. `vendor/linux-framework/kernel/bpf/syscall.c`
4. `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
5. `vendor/linux-framework/include/uapi/linux/bpf.h`
6. `vendor/linux-framework/include/linux/bpf.h`
7. `vendor/linux-framework/include/linux/bpf_verifier.h`
8. `daemon/src/analysis/cfg.rs`
9. `daemon/src/passes/utils.rs`
10. `daemon/src/passes/rotate.rs`

### 文献与官方文档

1. Qiongwen Xu, Michael D. Wong, Tanvi Wagle, Srinivas Narayana, Anirudh Sivaraman. *Synthesizing Safe and Efficient Kernel Extensions for Packet Processing*. SIGCOMM 2021.  
   https://doi.org/10.1145/3452296.3472929
2. Jinsong Mao, Hailun Ding, Juan Zhai, Shiqing Ma. *Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness*. ASPLOS 2024.  
   https://www.asplos-conference.org/asplos2024/main-program/abstracts/index.html
3. Xiaokang Huang et al. *EPSO: Collaborative Optimization of eBPF Bytecode for Lightweight JIT Execution*. arXiv 2025.  
   https://arxiv.org/abs/2511.15589
4. Clang Attribute Reference: `always_inline`.  
   https://clang.llvm.org/docs/AttributeReference.html
5. LLVM BPF target source (`BPFTargetMachine.cpp`, `BPFISelLowering.cpp`).  
   https://github.com/llvm/llvm-project/tree/main/llvm/lib/Target/BPF

