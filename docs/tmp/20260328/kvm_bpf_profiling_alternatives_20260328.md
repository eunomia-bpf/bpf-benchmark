# KVM guest 内 BPF 程序 PMU profiling 替代方案调研（2026-03-28）

## 0. 结论先行

- 在**不改宿主机内核**的前提下，没有一个方案能低工作量、低噪声地直接拿到 guest 内单个 BPF 程序的真实 `cycles / instructions / branch_misses` 三元组。
- 当前最实用的组合路线是：
  - **方案 1：`perf kvm` + guest BPF JIT symbols**，解决“能不能从 host 看见是哪一个 guest BPF JIT 符号热”，适合热点归因。
  - **方案 4：`bpf_prog_test_run` + host `perf stat` delta**，在严格 pinning 和批量重复下，最接近“真实硬件计数器”的可落地方案。
- **Intel PT 在这台机器上不是硬件不支持**。截至 **2026-03-28**，本机 `lscpu` 的 flags 含 `intel_pt`，`/sys/bus/event_source/devices/intel_pt` 也存在；所以对这台宿主机，应按“**Intel PT 实际可用**”处理，而不是按“Arrow Lake 不支持 PT”处理。
- 但 **Intel PT 不是 `branch_misses` 的直接替代**。它适合做 guest kernel 控制流 trace、分支路径和 IPC-like 分析，不适合直接给出单个 BPF 程序的真实 `branch_misses`。
- **重编译 host kernel 删除 hybrid check** 是唯一接近“让 guest 像原生机器一样用 perf/bpftool”的路径，但 upstream 明确认为这在 hybrid CPU 上存在正确性风险；**只删 check + `taskset` pin 到 P-core 不是完整方案**。

## 1. 背景与已确认约束

### 1.1 宿主机与仓库约束

- 宿主机是 `Intel(R) Core(TM) Ultra 9 285K`，Arrow Lake-S，`P-core x8 + E-core x16`，无超线程。
- 仓库现有文档已经把**所有 benchmark 绑定到 P-core** 作为默认策略，以避免 P/E 异构带来的偏差。
- 仓库 vendored 内核源码里，KVM 在 hybrid CPU 上**硬编码禁用 vPMU**：
  - `vendor/linux-framework/arch/x86/kvm/pmu.c` 第 111-120 行直接在 `X86_FEATURE_HYBRID_CPU` 时把 `enable_pmu = false`。
- 仓库已经有 TCG 目标：
  - `runner/machines.yaml` 中已有 `local-x86-vng-tcg`（`--disable-kvm`），所以方案 2 的环境门槛低于“从零搭 TCG”。

### 1.2 本机实测枚举

我在宿主机本地做了只读检查：

```text
$ lscpu
Model name: Intel(R) Core(TM) Ultra 9 285K
Flags: ... vmx ... intel_pt ... arch_lbr ...

$ ls /sys/bus/event_source/devices
... cpu_core cpu_atom intel_pt ...
```

这说明两件事：

- 这台机器的 PMU 确实是 **hybrid split PMU**（`cpu_core` / `cpu_atom`）。
- 这台机器也确实**枚举出了 Intel PT PMU**（`intel_pt`）。

补充观察：

- 当前 shell 里的 `perf` userspace 没有和 `6.15.11-061511` 内核对齐，直接 `perf list` 会提示安装对应 `linux-tools`。这属于工具链问题，不是 PT 硬件能力问题。

### 1.3 现有 timing fallback

- 仓库已经把 `BPF_PROG_TEST_RUN.duration`、`bpf_stats.run_time_ns` 和 `ktime` 作为 timing source 使用。
- 仓库文档已经明确写了 `ktime` 在 `<100ns` benchmark 上有 sub-resolution 风险。

## 2. 六个方向的总评

| 方案 | 能否拿真实 cycles | 能否拿真实 instructions | 能否拿真实 branch_misses | 精度 | 工作量 | 总结 |
| --- | --- | --- | --- | --- | --- | --- |
| 1. `perf record -e cycles:Gk` + guest BPF JIT symbols | 近似（采样归因） | 近似（采样归因） | 近似（采样归因） | 中 | 中 | 最适合做热点归因，不适合 authoritative per-prog exact counts |
| 2. QEMU TCG instrumentation | 否（真实硬件） | 是（guest 指令数） | 否（真实硬件） | 对 emulation 高，对真实硬件低 | 中高 | 适合 deterministic insn/branch mix 研究，不是 PMU 替代 |
| 3. Intel PT | 可做 trace-derived 分析 | 可做 trace-derived 分析 | 否，不能直接给真实 mispredict counts | 中高 | 中高 | 适合 guest kernel 控制流 trace，不适合直接替代 `branch_misses` |
| 4. `bpf_prog_test_run` + host `perf stat` delta | 是（measurement window） | 是（measurement window） | 是（measurement window） | 中高 | 中 | 当前最实用的“真计数器”路线 |
| 5. 重编 host kernel 恢复 vPMU | 是 | 是 | 是 | 潜在最高 | 高 | 风险最高；只有在愿意维护 custom host kernel 时才值得做 |
| 6. `bpf_ktime_get_ns()` 计时 | 否 | 否 | 否 | 仅 wall-time | 低 | 只能做 timing fallback，不是 PMU 替代 |

如果把目标缩成一句话：

- **想看“哪个 guest BPF 程序热”**：优先方案 1。
- **想拿最接近真实的 `cycles/instructions/branch_misses`**：优先方案 4。
- **想看 guest kernel 的控制流/分支路径**：方案 3 有价值。
- **想在 guest 内像正常机器一样跑 perf/bpftool**：只有方案 5 真正解决，但代价最高。

## 3. 方案 1：`perf record -e cycles:Gk` + guest BPF JIT symbols

### 3.1 host 侧能不能看到 guest BPF JIT 符号？

**可以，但前提明确。**

前提是 guest 内满足：

- `net.core.bpf_jit_enable=1`
- `net.core.bpf_jit_kallsyms=1`
- `net.core.bpf_jit_harden=0`

依据：

- 内核 sysctl 文档说明 `bpf_jit_kallsyms` 会把 JIT image 地址导出到 `/proc/kallsyms`；若 `bpf_jit_harden` 打开，这个能力会被关闭。
- vendored 内核 `kernel/bpf/core.c` 里，BPF JIT kallsyms 名字就是 `bpf_prog_<tag>_<name>`。

所以，只要 guest 的 `/proc/kallsyms` 里已经出现了 `bpf_prog_xxx_yyy`，host perf 就**有机会按 guest kernel symbol** 来解析这些地址。

### 3.2 guest `/proc/kallsyms` 能不能导出给 host perf？

**可以。**

`perf` 的 guest 文件文档明确支持：

- `--guestkallsyms=<path>`：给 perf 一份从 guest 拷出来的 `/proc/kallsyms`
- `--guestmodules=<path>`：给 perf 一份 guest `/proc/modules`
- `--guestvmlinux=<path>`：给 perf guest 的 `vmlinux`
- `--guestmount=<path>`：直接挂 guest 根文件系统

也就是说，这条链路不是“猜想”，而是 perf 已有设计目标。

### 3.3 `perf kvm --guest report` 需要什么？

文档给出的接口是：

- `--guestmount=<path>`
- 或 `--guestkallsyms=<path> --guestmodules=<path>`
- 或 `--guestvmlinux=<path>`

对本问题的关键点是：

- **要看到 guest BPF JIT 符号，关键是 `guestkallsyms`。**
- `guestmodules` 主要是给 guest kernel modules 做地址映射；BPF JIT 自身不是 module。
- `guestvmlinux` 对普通 guest kernel text 很有帮助，但 **BPF JIT image 本身不在 vmlinux 里**。
- 如果想进一步做 disasm / code bytes 级分析，最好再配 guest `/proc/kcore`，因为 BPF JIT image 在 guest kernel memory 中。

### 3.4 这个方案能不能拿到单个 BPF 程序的 exact counters？

**不能。它更像“按 guest symbol 的统计采样归因”。**

原因：

- `perf record -e cycles:Gk` 是 sampling，不是 exact counting。
- 可以把采样点归到 `bpf_prog_*` 符号上，但最终拿到的是：
  - 哪些 BPF JIT 符号最热
  - 各符号大概占多少 samples
  - 若采样足够多，可估计 cycles/instructions/branch-misses 的热点分布
- 但它不是每个 program 的 exact `counter delta`。

### 3.5 额外限制

- **符号快照时机很重要。** BPF 程序 load / unload / REJIT 后地址会变化；guest `kallsyms` 要在目标程序稳定驻留后导出。
- **推断**：这条路大概率只能稳定到 “symbol-level attribution”，很难自然延伸到 guest BPF 的 `prog_id/BTF/line_info` 级别。原因是 perf 里 BPF metadata synthesis 的逻辑本质上是从**当前内核**枚举 live BPF 程序；host perf 并不能像在 host kernel 上那样直接枚举 guest 的 BPF 对象。

### 3.6 评价

- **可行性**：中高
- **精度**：中
- **工作量**：中
- **结论**：这是当前最好的 **“先看得见 guest BPF JIT hotspot”** 路线，但不是 exact per-program PMU counter 方案。

## 4. 方案 2：QEMU TCG instrumentation

### 4.1 `qemu -plugin` 能不能 hook guest 指令执行？

**可以。**

QEMU TCG plugin 文档明确说：

- plugin 可以在 translation 和 execution 两个阶段订阅事件；
- 可以下钻到**单条 guest 指令粒度**；
- 可以订阅 load/store；
- plugin 只能**被动观察**，不能改 guest state。

当前 master 文档还提供了：

- 单指令 instrumentation
- control-flow discontinuity callback
- 线程安全 scoreboard

这已经足够做“某个 guest 地址范围内执行了多少条指令、多少次 branch、哪些 PC 热”的统计。

### 4.2 有没有现成 plugin 统计 `branch_miss`？

**没有我能确认到的现成官方 plugin。**

官方例子里有：

- `insn`：计指令数
- `hotblocks`：热点 block
- `hotpages`：热点页
- `execlog`：执行 trace
- `cache`：cache model
- `uftrace`：函数级 trace
- `howvec`：指令分类

但我没有找到“真实 branch mispredict”或“branch predictor model”插件。

可以自己做两类东西：

- **计 branch / discontinuity 次数**：可行
- **自己模拟 predictor，定义一个 synthetic branch-miss**：也可行

但后者不再是 Arrow Lake 真硬件上的 `branch_misses`。

### 4.3 最大缺点

这是官方文档明确写出来的：

- TCG `icount` **不是 cycle-accurate emulation**
- QEMU 不尝试模拟真实硬件上一条指令需要多少时间

因此：

- **真实 cycles**：拿不到
- **真实 branch_misses**：拿不到
- **真实 instructions**：可以拿 guest instruction count，但那是“在 QEMU 下执行的 guest 指令数”，不是 host PMU 的 `instructions` 语义

### 4.4 对本仓库的实际意义

这一项对你们仓库不是纸上谈兵，因为：

- `runner/machines.yaml` 已经有 `local-x86-vng-tcg`

所以最小落地成本并不高。你们真正要补的是：

- 如何把 guest BPF JIT address range 映射到具体 `bpf_prog_*`
- 如何输出每个 BPF prog 的 insn count / branch count / hot PCs

### 4.5 评价

- **可行性**：高
- **精度**：对“deterministic 指令/分支行为”高；对“真实硬件 PMU”低
- **工作量**：中高
- **结论**：非常适合做 **deterministic instruction-count / branch-mix / control-flow** 调研；不适合替代真实 `cycles / branch_misses`。

## 5. 方案 3：Intel PT

### 5.1 Intel PT 能不能 trace guest？

**可以。**

perf 的 Intel PT 文档给了 KVM guest trace 的完整例子：

- `perf kvm --guest --host --guestkallsyms ... record --kcore -e intel_pt/.../k -p <KVM pid> --per-thread`
- 后续 `perf script` / `perf kvm report` 会区分 host 和 `[guest.kernel.kallsyms]`

这说明 Intel PT 的 guest trace 是 perf 官方支持的用法，不依赖 guest vPMU。

### 5.2 `perf intel-pt` 能不能区分 guest / host？

**可以。**

依据有两层：

- 文档例子里明确同时显示 host KVM thread 和 `[guest.kernel.kallsyms]`
- perf source 里也有 guest machine / guest thread / guest sideband 的专门逻辑

但有一个重要限制：

- perf source 里明确写着：**guest user-space decode 不支持**
- 对 guest 只能稳定做 **kernel decode**

这对你们的问题是**可接受的**，因为 guest 里的 BPF JIT 本来就在 kernel space。

### 5.3 Arrow Lake 支不支持 Intel PT？

对于“这台机器”，答案应是：**支持。**

我这里有两类证据：

1. **本机实测枚举**
   - `lscpu` flags 有 `intel_pt`
   - `/sys/bus/event_source/devices/intel_pt` 存在

2. **Intel 公共资料存在冲突**
   - Intel 285K 的公开规格页没有清晰列出 Intel PT
   - Intel 社区支持在 **2025-11-06** 的回复里说：公开规格没有列出，所以“看起来不支持”

这两者冲突时，我建议对**这台具体机器**采用以下判断：

- **以本机 CPUID/sysfs 枚举结果为准**
- 也就是：**这台 285K 上 Intel PT 实际存在**

换句话说，这不是“Arrow Lake 一定不支持 PT”，而更像是“Intel 公共规格披露不完整或不一致”。

### 5.4 Intel PT 能不能给出 `branch_misses`？

**不能直接给出真实 `branch_misses`。**

Intel PT 给的是：

- control-flow packets
- 可选 `cyc` packets
- 因而可恢复 branch path、可做 instruction trace、可做 IPC-like 分析

但它不是 branch predictor misprediction counter。

这里需要明确区分：

- `PT branch trace`：你知道走了哪条边
- `PMU branch_misses`：你知道预测器失误了多少次

这两个不是一回事。

这条结论是**基于 PT 语义的推断**，不是 perf 文档逐字写出的句子。

### 5.5 BPF JIT 上的现实 caveat

Intel PT 文档里针对 guest-sideband workflow 有一句非常关键的话：

- `There is no BPF support at present so, if possible, disable JIT compiling`

这说明：

- guest-sideband + inject 这条官方工作流里，**BPF JIT 不是一等公民**

我不想把这个过度解读成“PT 完全不能看 guest BPF JIT”，但至少应该保守地认为：

- **PT 对 guest kernel 普通符号是成熟路径**
- **PT 对 guest BPF JIT 是“可能可做，但官方未验证/未主打”的路径**

### 5.6 评价

- **可行性**：中高
- **精度**：对 path reconstruction 高；对 exact PMU counters 中
- **工作量**：中高
- **结论**：很适合做 **guest kernel BPF 的控制流 trace / branch path / IPC-like 分析**；不适合直接替代 `branch_misses`，而且 BPF JIT 支持面需要保守看待。

## 6. 方案 4：`bpf_prog_test_run` + host `perf stat` delta

### 6.1 基本思路

guest 内：

- 用 `BPF_PROG_TEST_RUN` 批量运行目标程序

host 侧：

- 对对应的 KVM vCPU thread，或它固定运行的那颗 P-core，做
  - `cycles:Gk`
  - `instructions:Gk`
  - `branch-misses:Gk`
  的 `perf stat` 计数
- 对目标 batch 前后做 delta

这给出的不是“perf sample 估计”，而是**measurement window 的真实 PMU counter delta**。

### 6.2 这个方案的精度本质

它的好处：

- 用的是 **host 真 PMU**
- 不需要 guest vPMU
- 如果事件能成功 open，就是**真实硬件计数**

它的限制：

- 数到的是“measurement window 内的 guest kernel 工作”
- 不是纯 BPF body

窗口里会混进：

- `BPF_PROG_TEST_RUN` syscall/path 开销
- guest 内核包装逻辑
- VM entry/exit 相关扰动
- 任何恰好落在同一 vCPU / 同一时间窗内的 guest kernel 噪声

所以它本质上是：

- **program + harness 的 delta**

不是 free lunch。

### 6.3 噪声大不大？

**可以压到可用，但必须靠实验设计，不是默认就准。**

我认为这一项要成立，至少要满足：

- 单 guest vCPU 跑测试
- QEMU 的该 vCPU thread 固定绑到**一颗 P-core**
- guest 内跑 `test_run` 的用户线程也固定到对应 vCPU
- 批量重复足够多次，把目标程序放大成 ms 级或更高的 measurement window
- 用一个 **noop / minimal baseline BPF** 做同样 batch，最后做 baseline subtraction
- 避免 guest 背景任务、timer、中断干扰

如果不这样做：

- 你数到的是“整 VM 某个时间窗的 guest kernel cycles”，而不是“这一个 BPF prog”

### 6.4 需要 pin vCPU 到固定物理核心吗？

**是，强烈建议，而且在 hybrid host 上几乎是必需条件。**

原因有两层：

1. **噪声层**
   - P-core / E-core 频率、宽度、PMU 行为不同
   - 迁移会直接破坏统计稳定性

2. **语义层**
   - 这台机器的 PMU 是 split `cpu_core` / `cpu_atom`
   - guest 计数窗口跨 core type 迁移时，计数器语义和性能都不再一致

这和仓库现有文档里“所有 benchmark 绑定 P-core”的策略是完全一致的。

### 6.5 这个方案能不能拿到你要的三元组？

**原则上能。**

前提是你 host 侧对应事件都能成功 open：

- `cycles:Gk`
- `instructions:Gk`
- `branch-misses:Gk`

用户已经确认 `cycles:Gk` 可以工作；`instructions` 和 `branch-misses` 仍需要在当前 host 的 perf userspace / kernel 组合上再做一次本地验证。

### 6.6 评价

- **可行性**：高
- **精度**：中高
- **工作量**：中
- **结论**：这是我认为**当前最实用、最接近目标、且不需要 custom host kernel** 的方案。

## 7. 方案 5：重编宿主机内核删除 hybrid check

### 7.1 这条路是不是只删一行就够？

**不是。**

上游当初禁掉 hybrid vPMU 的 patch 写得很清楚：

- hybrid vPMU 不是完全不可能
- 但前提包括：
  - userspace 把 vCPU pin 到 pCPU
  - VMM 向 guest 准确枚举 topology
  - VMM 向 guest 准确枚举 vPMU capability

而 Sean Christopherson 在 patch 说明里点出的核心难点是：

- **KVM 在向 userspace 枚举 vPMU capability 时，不控制自己运行在哪颗 pCPU 上**

这意味着：

- 你事后 `taskset` 把 vCPU thread 固定到 P-core
- **不等于** 你前面暴露给 guest 的 PMU model 已经正确

### 7.2 如果只删 check + pin 到 P-core，有什么风险？

风险包括：

- guest 看到的 PMU capability 与真实运行 core type 不匹配
- guest perf 访问某些 MSR/event selector 触发异常
- 出现随机 `#GP`
- 结果不稳定，难以说服评审“这是受支持的 measurement path”

这是 upstream 明确担心的问题，不是保守猜测。

### 7.3 这条路的收益

如果做成了，它的收益也最大：

- guest 内可以像原生机器一样用 perf / `bpftool prog profile`
- 可以直接按 guest 视角拿 per-program PMU 指标

这才是“最像目标态”的方案。

### 7.4 工作量评估

我把它评为 **高**，不是因为 patch 行数多，而是因为验证面大：

- patch host kernel
- rebuild + reboot
- 固定 P-core 运行
- 校验 guest PMU self-consistency
- 校验 QEMU/KVM 暴露给 guest 的 PMU 拓扑/能力是否合理
- 校验 perf / `bpftool prog profile` / guest `perf stat` 是否都稳定

### 7.5 评价

- **可行性**：中
- **精度**：潜在最高
- **工作量**：高
- **风险**：高
- **结论**：这是 **last resort**。只有当方案 4 的 window-delta 精度不够，且你们愿意维护 custom host kernel 时，才值得投入。

## 8. 方案 6：guest 内 `bpf_ktime_get_ns()` 计时

### 8.1 够不够？

**对 timing 足够，对 PMU 不够。**

如果目标只是：

- 看优化前后 wall-time 是否下降
- 做 regression guardrail
- 对比同一 harness 下的相对快慢

那 `ktime`、`BPF_PROG_TEST_RUN.duration`、`bpf_stats.run_time_ns` 已经足够有用。

### 8.2 和 PMU 相比缺什么？

缺的是所有“微架构语义”：

- `instructions`
- `IPC`
- `branch_misses`
- stall / front-end / back-end 行为

另外，若把 `bpf_ktime_get_ns()` helper 直接插进被测程序：

- 它本身会 perturb program
- helper call 本身也有开销

所以它不是无扰动测量。

### 8.3 评价

- **可行性**：高
- **精度**：对 wall-time 中；对 PMU 目标无
- **工作量**：低
- **结论**：保留为 timing fallback，但不能替代 PMU profiling。

## 9. 推荐的落地顺序

### 9.1 推荐顺序

1. **先做方案 1**：验证 host 能否稳定看到 guest `bpf_prog_*` 符号  
   目的：先回答“host 能不能看见 guest BPF JIT symbol”这个基础问题。

2. **主线做方案 4**：`BPF_PROG_TEST_RUN` batch + host `perf stat` delta  
   目的：拿最接近真实的 `cycles / instructions / branch_misses`。

3. **如果需要 branch path / control-flow 证据，再做方案 3**  
   目的：不是为了替代 `branch_misses`，而是为了看 guest BPF 路径、分支行为和 IPC-like 特征。

4. **如果方案 4 仍不够，才考虑方案 5**  
   目的：真正把 guest vPMU 救回来，让 guest perf / bpftool 原生工作。

### 9.2 我建议的最终判断

- **近期最推荐**：方案 4
- **最适合先做可视化确认**：方案 1
- **最适合做深度 trace**：方案 3
- **最适合做 deterministic analysis**：方案 2
- **风险最高但目标态最强**：方案 5
- **仅 timing fallback**：方案 6

### 9.3 一个重要结论

如果你把目标限定成：

- **必须是真实硬件上的 `branch_misses`**

那么真正可选的其实只剩两类：

- **方案 4：host PMU window-delta**
- **方案 5：恢复 guest vPMU**

其余方案都只能解决一部分问题：

- 方案 1：看热点，不给 exact counts
- 方案 2：给 emulated branch 行为，不给真实 branch_misses
- 方案 3：给 branch trace，不给真实 branch_misses
- 方案 6：只给 timing

## 10. 参考资料

### 外部资料

- Linux kernel sysctl 文档：`bpf_jit_kallsyms`  
  https://docs.kernel.org/6.12/admin-guide/sysctl/net.html

- QEMU TCG plugin 文档（current master）  
  https://qemu.readthedocs.io/en/master/devel/tcg-plugins.html

- QEMU TCG instruction counting 文档  
  https://qemu.readthedocs.io/en/v8.2.8/devel/tcg-icount.html

- QEMU emulation 文档（`uftrace` plugin overhead、system tracing 示例）  
  https://qemu.readthedocs.io/en/master/about/emulation.html

- Intel 285K 规格页  
  https://www.intel.com/content/www/us/en/products/sku/241060/intel-core-ultra-9-processor-285k-36m-cache-up-to-5-70-ghz/specifications.html

- LKML patch：hybrid CPU 上禁用 KVM vPMU  
  https://lkml.org/lkml/2023/1/19/1372

- Intel 社区帖子：**2025-11-06** 的官方回复认为 285K 的公开规格未显示 Intel PT  
  https://community.intel.com/t5/Mobile-and-Desktop-Processors/Does-Intel-Core-Ultra-9-285K-support-Intel-Processor-Trace-Intel/m-p/1725617/highlight/true

### 仓库内源码/文档

- `vendor/linux-framework/arch/x86/kvm/pmu.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/tools/perf/Documentation/perf-kvm.txt`
- `vendor/linux-framework/tools/perf/Documentation/guest-files.txt`
- `vendor/linux-framework/tools/perf/Documentation/perf-intel-pt.txt`
- `vendor/linux-framework/tools/perf/util/intel-pt.c`
- `runner/machines.yaml`
- `docs/benchmark-framework-design.md`
- `docs/kernel-jit-optimization-plan.md`
