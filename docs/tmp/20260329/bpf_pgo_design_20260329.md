# Host-Side Guest-BPF LBR 验证与 BPF PGO 设计（2026-03-29）

状态：design + experiment  
约束：不改 daemon/kernel 代码，不 commit/push  
结论先行：**当前本地 QEMU/KVM 环境下，host `perf` 能录到 guest 样本，也能看到 guest BPF JIT 符号表；但按 `perf record -b -e cycles:Gk -a` / `perf record -e cycles:Gk -a` 这条最直接路径，5 秒窗口内没有任何样本落进 guest BPF JIT 地址范围，因此本轮不能把 host-side LBR/IP 采样认定为“已可用于 guest BPF PGO”。**

---

## 1. 本地验证结论

### 1.1 实验环境

- Host CPU：`Intel(R) Core(TM) Ultra 9 285K`
- Host flags：`arch_lbr` 存在，说明主机硬件支持 Intel Arch LBR
- Host kernel：`6.15.11-061511-generic`
- Host perf：使用 `/usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf`（`perf version 6.14.11`）
- Guest kernel：repo 自编 `vendor/linux-framework/arch/x86/boot/bzImage`
- Guest 运行方式：`vng` / QEMU-KVM

补充说明：

- 仓库里当时已有一个长跑的 `vm-corpus` 会话占用了 repo 的 `vm_global` 锁。
- 我先做了一个短 guest smoke，确认 `execsnoop` 在 guest 内可以正常加载 BPF 并产生事件。
- 真正的 host-side perf 采样结果来自当时已经在跑的 live `vm-corpus` guest；这台 guest 在 perf data header 里暴露了 24 个 guest BPF JIT 符号。

### 1.2 最小 guest smoke：`execsnoop` 确实能在 guest 里跑

短 smoke 的结果：

- guest 里运行 `runner/repos/bcc/libbpf-tools/execsnoop` 成功
- 100 次 `/bin/true` 触发后，`execsnoop.out` 有 `89` 行输出
- `bpftool_prog_show_live.json` 看到两个 JITed program：
  - `tracepoint__syscalls__sys_enter_execve`
  - `tracepoint__syscalls__sys_exit_execve`

对应工件：

- `docs/tmp/20260329/lbr_guest_probe/bpftool_prog_show_live.json`
- `docs/tmp/20260329/lbr_guest_probe/guest_kallsyms_live.txt`

这一步证明的是：**guest BPF workload 本身没问题，guest 里确实有 JITed BPF 程序。**

### 1.3 Host perf 采样：命令与观测

执行过的关键命令：

```bash
sudo /usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf record -b -e cycles:Gk -a \
  -o docs/tmp/20260329/lbr_guest_probe/current_vm_lbr.data -- sleep 5

sudo /usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf record -e cycles:Gk -a \
  -o docs/tmp/20260329/lbr_guest_probe/current_vm_ip.data -- sleep 5
```

关键事实：

- LBR 录制成功，5 秒窗口生成 `16.86 MiB` 数据，header 明确显示 `contains samples with branch stack`
- 普通 IP 采样也成功，5 秒窗口生成 `10.82 MiB` 数据
- 两份 perf data 的 header 都包含 `bpf_prog_info ... addr ... size ...` 条目，共 `24` 个 guest BPF JIT 符号

也就是说：

1. Host 侧 `cycles:Gk` 事件能打开
2. Host 侧 branch-stack/LBR 也能打开
3. perf data 里确实记住了 guest BPF JIT 符号名和地址区间

### 1.4 直接 `perf script` 的结果

对两份 perf data 直接跑 `perf script`：

```bash
/usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf script -i current_vm_lbr.data ...
/usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf script -i current_vm_ip.data ...
```

观测结果：

- `perf script` 输出几乎都落在 host KVM 路径，代表性符号是 `vmx_vmexit`
- 没有直接看到 `bpf_prog_*`

这意味着：

- **按用户给的最直观路径，`perf script` 不能直接把 guest-BPF 采样结果呈现成可用的 BPF JIT profile**
- 至少在当前这台机子和这个 guest workload 上，`perf script` 本身更像是在告诉你“guest sample 发生了”，而不是“guest 内哪个 BPF JIT 地址热”

### 1.5 `perf kvm report` 的结果

`perf kvm report` 比直接 `perf script` 更接近真实 guest 视角：

```bash
sudo /usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf kvm report \
  -i current_vm_ip.data --stdio --sort symbol --percent-limit 0
```

它确实给出了大量 raw guest IP：

- IP 采样：`9149` 条 guest-address 聚合行，`7441` 个 unique guest IP
- LBR 采样：`61` 个 unique sample IP

但是：

- 这些地址在本轮都还是 `[g] 0xffffffff...` 的 raw guest 地址
- 没有 guest `kallsyms` 时，它们不会自动解成 `bpf_prog_*`

### 1.6 最关键的交叉验证：样本有没有落进 guest BPF JIT 地址范围？

我把两份 perf data header 里的 `bpf_prog_info` 地址范围，与 `perf kvm report`/LBR script 中出现的 guest 地址做了交集。

结果如下：

| 项目 | 数值 |
| --- | ---: |
| guest BPF JIT 符号数 | 24 |
| IP 采样 guest 地址行数 | 9149 |
| IP 采样 unique guest IP | 7441 |
| IP 采样命中 BPF JIT range | 0 |
| LBR sample IP unique 数 | 61 |
| LBR branch-stack 地址总数 | 698 |
| LBR 命中 BPF JIT range | 0 |

这组结果的含义很明确：

- **不是“perf 完全不知道 guest BPF”**
- 而是“这 5 秒窗口里没有任何 guest sample 落进那 24 个 BPF JIT 地址区间”

### 1.7 任务 1 的最终判定

| 问题 | 结论 |
| --- | --- |
| Host LBR 硬件是否可用？ | **可用**。host 本机 `perf record -b` 正常，guest 模式 `cycles:Gk` 也能录 branch stack。 |
| Host-side LBR 对 guest BPF 是否已验证可用？ | **没有**。本轮没有任何 LBR sample 或 branch-stack 地址落进 guest BPF JIT range。 |
| Host-side 普通 IP 采样对 guest BPF 是否已验证可用？ | **没有**。能拿到 raw guest IP，但本轮 `0` 次命中 guest BPF JIT range。 |
| 地址能映射到 `bpf_prog_xxx` 吗？ | **理论上可以，实测未达成**。perf data header 已带 `bpf_prog_info`；但本轮没有 BPF hit，所以无法完成映射。 |
| 地址能映射到 BPF PC 吗？ | **本轮不能**。没有 BPF hit；即便有 hit，也还需要额外的 native-IP -> BPF-PC 映射层。 |

### 1.8 对结果的解释

我认为这轮结果说明的是：

1. **host-side 录制链路是通的**
   - `cycles:Gk` 可录
   - LBR 可录
   - guest BPF ksymbol/bpf_prog_info 会进入 perf data header
2. **当前失败点不是“完全拿不到 guest 数据”，而是“样本没有落到 BPF JIT”**
3. **因此 host-side KVM sampling 不能作为当前论文版本里唯一依赖的 PGO 数据源**

对 BpfReJIT 来说，这个结论很重要：

- Sampling PGO 可以保留为一个 collector backend
- 但系统设计必须有 instrumentation fallback
- 否则 profiling story 会被环境依赖卡死

---

## 2. AWS 可行性

### 2.1 先说明一个事实

用户指定要读的文件：

```text
docs/tmp/20260328/perf_kvm_guest_profiling_20260328.md
```

我在仓库里没有找到这个文件。当前树里不存在该路径。

因此 AWS 部分我改用：

- 仓库内现有 AWS 跑数记录
- AWS 官方实例页
- Arm 官方 SPE 资料

### 2.2 `t4g.micro`：有没有 SPE？

官方信息：

- AWS T4g 官方页说明：
  - T4g 使用 **AWS Graviton2**
  - `t4g.micro` 规格是 `2 vCPU / 1 GiB`
  - T4g “built on the AWS Nitro System”
- Arm 官方资料说明：
  - SPE 是 Armv8.2-A 的 optional extension
  - **Neoverse N1 是第一代支持 SPE 的处理器**

因此：

- **从硅片家族角度看，Graviton2 所属的 Neoverse N1 lineage 是 SPE-capable 的**
- 但 **AWS 官方文档没有明确承诺 `t4g.micro` guest 一定暴露 `arm_spe_pmu`**
- 而 `t4g.micro` 是 Nitro VM，不是 bare metal

所以对“`t4g.micro` 有没有 SPE”最准确的回答是：

> **硬件血统上有 SPE 能力；但在 AWS `t4g.micro` 这种 Nitro 虚拟机里，SPE 是否对 guest 可见，不能只靠产品页下结论，必须上机验证。**

建议的上机验证命令：

```bash
perf list | grep -i arm_spe
ls /sys/bus/event_source/devices/arm_spe_0
```

如果这两项都没有，就不能把 T4g 当成“可用 SPE collector”。

### 2.3 `t3.micro`：有没有 LBR？Intel 还是 AMD？

AWS 官方页明确写了：

- T3 使用 **Intel Xeon Platinum 8000 series**
- 具体是 **1st/2nd gen (Skylake-SP or Cascade Lake)**
- T3 built on **AWS Nitro System**
- `t3.micro` 规格是 `2 vCPU / 1 GiB`

同时 AWS 官方页还明确区分了：

- `T3` 是 Intel
- `T3a` 才是 AMD EPYC 7000

因此：

> **`t3.micro` 是 Intel，不是 AMD。**

从微架构能力看：

- Skylake-SP / Cascade Lake 有 LBR
- 但 `t3.micro` 是 Nitro VM，不是 bare metal
- AWS 文档同样没有承诺 guest 一定暴露完整 LBR/PEBS 能力

所以准确结论是：

> **`t3.micro` 的底层 CPU 家族有 LBR；但 AWS 是否把 LBR 虚拟化给 guest，需要上机用 `perf record -b` 实测。**

建议验证命令：

```bash
perf record -b -e cycles:u -- sleep 1
perf script
```

如果 `-b` 打不开，就不能把 `t3.micro` 当成可靠的 LBR 训练机。

### 2.4 Bare metal 情况

AWS 官方 bare metal 说明写得很直接：

> bare metal instance 提供对 processor 和 memory resources 的 direct access，适合 deep performance analysis tools。

所以：

- 如果工作负载直接跑在 EC2 bare metal OS 上
- 且 BPF 程序也直接跑在该 OS kernel 上

那么 perf/LBR/SPE 就是普通“本机 profiling”问题，不再有 host/guest 这层 KVM 归因障碍。

但这条结论 **不适用于 `t3.micro` / `t4g.micro`**，因为它们都不是 bare metal。

---

## 3. 当前 daemon 的现状

当前代码里已经有一半 PGO 基础设施，但还不是完整 branch-level PGO：

### 3.1 已有能力

- `profiler.rs` 可以轮询 live BPF program 的：
  - `run_cnt`
  - `run_time_ns`
  - `avg_ns`
- snapshot / `profile-start` / `profile-stop` / `profile-save` / `profile-load` 已经存在
- `PassManager::run_with_profiling()` 已经能把 profile 注入 `InsnAnnotation`
- `BranchFlipPass` 已经会消费 `annotation.branch_profile`

### 3.2 当前缺口

- `ProfilingData.branch_profiles` 现在仍然是空的
- 当前 daemon 真正稳定拿到的只有 program-level hotness
- 当前 profiler 里的 PMU `branch_miss_rate` 不是按目标 BPF program 精确归属的 branch-level 数据
- `PrefetchPass` 还没进实现树，`cond_select` 也还不是 profile-driven

### 3.3 这对设计的直接约束

这意味着：

1. **当前 `profiler.rs` 不能直接升级成最终 Sampling PGO 实现**
2. **最现实的集成路径是：外部 collector 先产出 snapshot，再通过 `profile-load` 喂给 daemon**
3. **现有 `inject_profiling()` / `remap_annotations()` 是对的，应保留并扩展**

---

## 4. 推荐总方案：Hybrid PGO（方案 C）

我推荐的不是“只做 Sampling”也不是“只做 Instrumentation”，而是：

> **Hybrid：Sampling 做无侵入发现与粗粒度归因；Instrumentation 只打到 hot 且 sampling 仍不够精确的程序。**

原因很简单：

- 本地 KVM 实验已经证明，host-side sampling 不是稳定可用前提
- 但 sampling 的低开销和零侵入仍然很有价值
- instrumentation 虽然精确，但如果做成“每个 branch 一次 helper/map_update”，开销会很差

所以最合理的是分层：

1. `Hotness layer`
   - 先用现有 `run_cnt/run_time_ns`
   - 决定哪些 program 值得 profiling
2. `Sampling layer`
   - 如果平台支持可归因的 sampling，则先拿 sampling profile
3. `Instrumentation layer`
   - 只对 hot 且 sampling 置信度不够的程序打精确 counters

这和 JVM tiered compilation 的精神是一致的。

---

## 5. PGO 数据结构设计

### 5.1 Program identity：不要只用 `prog_id`

当前 snapshot 用 `prog_id -> ProgramProfile`，这对跨 reload / 跨 variant 不够稳定。

推荐引入：

```rust
pub struct ProgramKey {
    pub orig_prog_digest: [u8; 32],
    pub prog_type: u32,
    pub prog_name: String,
    pub attach_btf_obj_id: u32,
    pub attach_btf_id: u32,
    pub ifindex: u32,
}
```

关键点：

- `prog_id` 是 runtime handle，不是稳定 identity
- `orig_prog_digest` 应来自 canonical baseline bytecode
- 最好的底层材料是 `bpf_prog_info.orig_prog_insns`

这样做的好处：

- profile 可以跨 `BPF_PROG_REJIT` variant 复用
- instrumentation variant 和 optimized variant 可以共享同一个 baseline key

### 5.2 Program-level profile

```rust
pub struct ProgramProfileV2 {
    pub key: ProgramKey,
    pub run_cnt_delta: u64,
    pub run_time_ns_delta: u64,
    pub avg_ns: Option<f64>,
    pub branch_miss_rate: Option<f64>,
    pub cache_miss_rate: Option<f64>,
    pub sample_source: ProfileSource,
    pub sample_count: u64,
    pub confidence: f64,
    pub branches: HashMap<usize, BranchSiteProfile>,
    pub prefetch_sites: HashMap<usize, PrefetchSiteProfile>,
}
```

这里 `usize` 仍然表示：

- **canonical baseline BPF PC**
- 不是某个优化后 variant 的 PC

### 5.3 Branch profile

建议把当前 `BranchProfile` 从只有 taken/not-taken，扩成：

```rust
pub struct BranchSiteProfile {
    pub taken_count: u64,
    pub not_taken_count: u64,
    pub mispredict_count: Option<u64>,
    pub total_samples: u64,
    pub source: ProfileSource,
    pub confidence: f64,
}
```

解释：

- `taken_count/not_taken_count`：BranchFlip 的核心输入
- `mispredict_count`：CMOV policy 的重要输入
- `confidence`：sampling data 不能无条件相信，必须带置信度

### 5.4 Prefetch profile

沿用今天已有的 `PrefetchPass` 设计方向：

```rust
pub struct PrefetchSiteProfile {
    pub execution_count: u64,
    pub cache_miss_rate: Option<f64>,
    pub avg_mem_latency: Option<f64>,
    pub source: ProfileSource,
    pub confidence: f64,
}
```

这里要特别强调：

- **Prefetch 不是 LBR 的最佳受益者**
- 它更适合：
  - Arm SPE
  - Intel PEBS/mem events
  - 或 instrumentation

---

## 6. 采集接口设计

### 6.1 Sampling collector

统一抽象：

```rust
pub enum ProfileSource {
    HotnessOnly,
    PerfGuestIp,
    PerfGuestLbr,
    PerfBpfProgStat,
    ArmSpe,
    Instrumentation,
}
```

Sampling collector 输出：

- program-level hotness
- 可选的 branch/site profile
- confidence

建议支持三类 backend：

1. `perf kvm` host-side guest collector
   - 本地 QEMU/KVM / nested guest 场景
   - 依赖 guest address resolution
2. `perf` in-instance collector
   - AWS bare metal 或普通单机 Linux
   - 没有 guest/host 归因问题
3. `perf stat --bpf-prog` style program collector
   - 用于 coarse gate
   - 不提供 site-level 数据

### 6.2 Instrumentation collector

用户提议的：

> 每个分支前 `map_update(counter_map, branch_id, +1)`

我不建议直接这么做。

原因：

- 它会给每个 dynamic branch 引入一个 helper call 和 map op
- 对 hot loop 会非常重
- 会把训练版本变成“测 instrumentation cost”，不是测原程序行为

更合理的精确版 instrumentation 应该是：

1. 用 `PERCPU_ARRAY` 或固定布局 counter slab
2. 每次 program invocation 只做一次 `map_lookup_elem`
3. 后续 branch site 直接对返回的 value 指针做 in-place 计数递增

推荐计数布局：

```rust
pub struct BranchCounter {
    pub exec_count: u64,
    pub taken_count: u64,
}
```

做法：

- 分支前 `exec_count += 1`
- 仅在 taken edge 上 `taken_count += 1`
- `not_taken = exec_count - taken_count`

这样比 `map_update_elem` per branch 轻得多。

---

## 7. JIT 地址 -> BPF PC 映射

这是整个方案最关键的实现点。

### 7.1 先说结论

**不要把“完全通用的 native-IP -> 任意 BPF-PC 映射器”作为 P0。**

P0 更现实的目标是：

> **只为 policy-sensitive candidate sites 建 targeted map。**

也就是：

- BranchFlip 只映射候选 branch sites
- Prefetch 只映射候选 load sites

这样比“全程序每条 native insn 精确逆映射”可落地得多。

### 7.2 可利用的 kernel UAPI

当前 kernel UAPI 已经有足够多的原料：

- `orig_prog_insns`
- `xlated_prog_insns`
- `jited_prog_insns`
- `jited_prog_len`
- `jited_ksyms`
- `jited_func_lens`
- `line_info`
- `jited_line_info`

这意味着 daemon / collector 至少可以得到：

1. canonical BPF bytecode
2. JIT machine code bytes
3. 每个 subprog 的 native start address / length

### 7.3 推荐的 P0 映射方法：site-targeted matching

对 `BranchFlipPass`：

1. 先在 canonical BPF bytecode 上枚举 candidate branch sites
2. 对每个 site 构造一个 branch fingerprint：
   - 条件类型
   - then/else layout
   - branch target delta
   - compare immediate / register pattern
3. 反汇编 `jited_prog_insns`
4. 在对应 subprog 的 native range 内找匹配的 native branch
5. 生成：

```rust
pub struct BranchSiteNativeMap {
    pub bpf_pc: usize,
    pub native_from: u64,
    pub native_to_taken: Option<u64>,
    pub native_to_fallthrough: Option<u64>,
}
```

然后：

- LBR `from/to` 直接匹配 `native_from`
- taken/not-taken 从 LBR edge 聚合

这一方案的好处：

- 不要求完整通用 mapper
- 直接服务于 `BranchFlipPass`
- 跟 pass 的 candidate 扫描天然对齐

### 7.4 对 Prefetch 的映射

Prefetch 比 BranchFlip 更难：

- 需要识别 load site
- 更希望拿到 cache-miss / latency 信息，而不是纯 branch edge

所以我建议：

- **P0 不要求用 host-side cycles/LBR 给 Prefetch 做精确 site attribution**
- Prefetch PGO 优先依赖：
  - Arm SPE
  - precise memory events
  - 或 instrumentation

### 7.5 为什么本轮没法映射到 BPF PC

本轮实验里：

- perf data header 确实带了 `bpf_prog_info` 地址区间
- 但 `0` 个 sample hit / `0` 个 LBR branch record 落进这些区间

所以：

- 连 `native IP -> bpf_prog_xxx` 都没有实际 hit
- 更不可能继续往下做 `native IP -> BPF PC`

本轮结论不是“映射方案不存在”，而是“采样命中前提没成立”。

---

## 8. 消费接口：哪些 pass 用 PGO

### 8.1 `BranchFlipPass`

最适合先吃到 branch-level PGO。

需要：

- `taken_count`
- `not_taken_count`
- 可选 `mispredict_count`
- sample confidence

策略：

- `bias = taken / (taken + not_taken)`
- `bias >= threshold` 才 flip
- program-level `branch_miss_rate` 作为 coarse gate
- 没有 profile 时保持当前 conservative behavior

### 8.2 `PrefetchPass`

应吃：

- `execution_count`
- `cache_miss_rate`
- `avg_mem_latency`

策略：

- 没 profile 默认 skip
- 只对 hot site / miss-heavy site 插 hint
- 每程序有 budget cap

### 8.3 `cond_select` / CMOV policy

这类 pass 的 gate 与 BranchFlip 不同。

BranchFlip 偏好：

- 强 bias
- 热路径可 fall-through

CMOV/cond-select 更适合：

- branch 不够稳定
- mispredict 高
- 但 data dependence 成本可接受

因此推荐：

- 不要把 `BranchFlip` 和 `CMOV` 共用同一条简单阈值
- 应该让它们消费同一份 branch profile，但各自有不同 policy

---

## 9. 完整 workflow

### 9.1 Cold start

1. live program load
2. daemon / runner 读取 `orig_prog_insns`
3. 计算 `ProgramKey`
4. 用现有 `run_cnt/run_time_ns` 做 hotness 排序
5. 冷程序不做重 profiling

### 9.2 Sampling tier

1. 对 hot program 尝试 sampling collector
2. 如果 collector 成功产生高置信度 site profile：
   - 直接生成 `ProfileSnapshotV2`
   - `profile-load`
   - optimize + REJIT

### 9.3 Instrumentation tier

1. 如果 sampling 失败或置信度不够：
   - 部署 instrumented variant
2. 跑 training workload
3. 读取 counter map
4. 生成精确 `BranchSiteProfile`
5. 切回 optimized variant

### 9.4 Deployment tier

1. daemon 从 snapshot 读取 canonical-PC keyed profile
2. `inject_profiling()` 注入 annotation
3. pass pipeline 在 transform 过程中继续通过 `remap_annotations()` 保持 profile 对齐
4. REJIT 部署最终版本

这一步和当前 pass framework 是高度对齐的，说明现有 `InsnAnnotation`/`remap_annotations()` 方向是对的。

---

## 10. 与现有 `profiler.rs` 的关系

我建议把当前 `profiler.rs` 定位成：

> **Hotness / coarse stats collector，而不是最终 PGO collector。**

原因：

- 它今天稳定提供的是：
  - `run_cnt`
  - `run_time_ns`
  - `avg_ns`
- 这足够做：
  - hot/cold
  - optimize-all 排序
  - amortization 判断

但它不够做：

- per-branch bias
- per-load cache miss attribution
- guest/host side sample resolution

因此演进建议：

1. 保留 `profiler.rs` 的 hotness 角色
2. 新增独立 `profile collectors` 层
3. 让 `profile-load` 成为统一入口
4. 把 `ProfilingData` 扩展成 site-rich schema

---

## 11. 开销分析

### 11.1 Sampling 开销：本机实测

我在 host 上用一个 branch-heavy shell workload 做了 3 轮 wall-clock 对比。

工作负载：

```bash
bash -lc 'i=0; while [ $i -lt 3000000 ]; do i=$((i+1)); done'
```

结果：

| 模式 | 3 轮时间（s） | 中位数（s） | 相对 baseline |
| --- | --- | ---: | ---: |
| baseline | 4.39 / 4.34 / 4.37 | 4.37 | 0.00% |
| `perf record -e cycles:u` | 4.35 / 4.43 / 4.44 | 4.43 | +1.37% |
| `perf record -b -e cycles:u` | 4.39 / 4.45 / 4.45 | 4.45 | +1.83% |
| `perf stat -e cycles,branches,branch-misses` | 4.35 / 4.33 / 4.35 | 4.35 | 约 0%（落在噪声内） |

解读：

- **Counting PMU** 开销几乎可以当 0
- **IP sampling** 是低单 digit %
- **LBR sampling** 比 IP 稍重，但本机仍在低单 digit %

### 11.2 Sampling 数据量

在 live guest 的 5 秒窗口里：

| 模式 | perf.data 大小 | 约每秒数据量 |
| --- | ---: | ---: |
| IP (`cycles:Gk`) | 10.82 MiB | 2.16 MiB/s |
| LBR (`-b cycles:Gk`) | 16.86 MiB | 3.37 MiB/s |

LBR 数据量约是 IP 的 `1.56x`。

### 11.3 Instrumentation 开销估算

先说坏消息：

- **“每个 branch 一次 `map_update_elem`”这个版本我不建议采用。**

一个非常保守的估算：

- 假设一次 helper + map op 只要 `200 ns`
- 每秒 `1M` 个 dynamic branch，就会多出 `200 ms/s`
- 每秒 `10M` 个 dynamic branch，就会多出 `2 s/s`

也就是：

- `1M branches/s` 量级时就可能是 `20%+`
- `10M branches/s` 量级时会直接到 `>100%`

而这还是偏乐观的估算。

所以精确 instrumentation 的正确方向必须是：

- `1 helper / invocation`
- `N direct counter increments / dynamic branches`

这样 overhead 才有机会落到可接受范围。

### 11.4 设计层面的结论

因此：

- `Sampling` 适合作为默认 tier
- `Instrumentation` 适合作为 hot-subset fallback
- **不要把“map_update per branch”写成最终方案**

---

## 12. 推荐落地顺序

### P0

- 扩展 snapshot schema
- 引入 `ProgramKey`
- 保留 `profiler.rs` hotness collector
- 新增 external/offline `profile-load` pipeline

### P1

- x86: branch-site targeted sampling collector
- 先服务 `BranchFlipPass`
- 不要求 Prefetch 先吃到 site-level sampling

### P2

- instrumentation collector
- 精确 per-branch counters
- hot subset training flow

### P3

- Arm SPE / Intel precise memory collector
- 给 `PrefetchPass` 真正提供 site-level memory profile

---

## 13. 最终建议

如果目标是把 BPF PGO 讲成一个可靠的、可跑通的系统故事，我的建议是：

1. **不要把 host-side KVM LBR 当成唯一数据源。**
   - 本地实验已经说明它不是稳定前提。
2. **把当前 `profiler.rs` 明确降格为 hotness collector。**
   - 它不是最终 branch-level profiler。
3. **主推 Hybrid PGO。**
   - Sampling 先做发现和低开销归因。
   - Instrumentation 只打到 hot 且 sampling 不足的程序。
4. **优先打通 `BranchFlipPass`。**
   - 它和 branch profile 的关系最直接，也最容易证明价值。
5. **`PrefetchPass` 不要强行绑定到 today’s cycles/LBR sampling。**
   - 它更适合 SPE / precise memory events / instrumentation。

一句话总结：

> **BPF PGO 在这棵树里是可行的，但必须按“hotness -> sampling -> selective instrumentation”三层来做；不能把 host-side guest-LBR 当成唯一依赖。**

---

## Sources

本地工件：

- `docs/tmp/20260329/lbr_guest_probe/current_vm_lbr.data`
- `docs/tmp/20260329/lbr_guest_probe/current_vm_ip.data`
- `docs/tmp/20260329/lbr_guest_probe/current_vm_lbr.script.txt`
- `docs/tmp/20260329/lbr_guest_probe/current_vm_ip.script.txt`
- `docs/tmp/20260329/lbr_guest_probe/bpftool_prog_show_live.json`
- `docs/tmp/20260320/pgo_policy_design_20260320.md`
- `docs/tmp/20260329/prefetch_kinsn_design_20260329.md`
- `docs/tmp/20260328/aws_arm64_benchmark_20260328.md`
- `docs/tmp/20260328/aws_x86_benchmark_final_20260328.md`

外部官方资料：

- AWS T4g: https://aws.amazon.com/ec2/instance-types/t4/
- AWS T3: https://aws.amazon.com/pt/ec2/instance-types/t3/
- Arm SPE / Neoverse N1: https://developer.arm.com/community/arm-community-blogs/b/tools-software-ides-blog/posts/introduction-to-statistical-profiling-support-in-streamline
- AWS bare metal direct-access statement: https://aws.amazon.com/about-aws/whats-new/2025/04/amazon-ec2-i7ie-bare-metal-instances-sizes/
