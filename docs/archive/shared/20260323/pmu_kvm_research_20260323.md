# KVM/QEMU 虚拟机中 PMU 硬件计数器可行性调研

日期：2026-03-23

## 1. 当前 PMU 可用性状态

### Host 环境
- **CPU**: Intel Core Ultra 9 285K (Arrow Lake, 24 核, hybrid P+E 核架构)
- **Host 内核**: 6.15.11-061511-generic
- **Host PMU**: 可用（`cpu_atom` 和 `cpu_core` 两套 PMU 设备）
- **QEMU**: 8.2.2
- **KVM 模块**: `kvm` + `kvm_intel` 已加载
- **perf_event_paranoid**: 2（限制非 root 访问，但 daemon 运行时为 root 无影响）

Host 上 `perf stat -e branches:u,branch-misses:u` 正常工作，branch miss rate ~2.26%。

### VM 环境
- **VM 内核**: 7.0-rc2 (vendor/linux-framework)
- **虚拟化**: vng (virtme-ng) + KVM, QEMU 参数 `-cpu host,topoext=on`
- **VM 内 PMU 设备**: 只有 `breakpoint, kprobe, msr, power, software, tracepoint, uprobe`
- **没有硬件 PMU**（无 `cpu`, `cpu_core`, `cpu_atom`）

### 根因分析

**KVM 模块在 hybrid CPU 上强制禁用 vPMU。**

关键代码位于 `arch/x86/kvm/pmu.c:kvm_init_pmu_capability()`:

```c
if (cpu_feature_enabled(X86_FEATURE_HYBRID_CPU)) {
    enable_pmu = false;
    memset(&kvm_host_pmu, 0, sizeof(kvm_host_pmu));
}
```

注释原文：
> Hybrid PMUs don't play nice with virtualization without careful configuration
> by userspace, and KVM's APIs for reporting supported vPMU features do not
> account for hybrid PMUs. Disable vPMU support for hybrid PMUs until KVM gains
> a way to let userspace opt-in.

验证过程：
1. 手动 `rmmod kvm_intel kvm`，然后 `modprobe kvm enable_pmu=1` —— 此时 `enable_pmu=Y`
2. 再 `modprobe kvm_intel` —— `kvm_init_pmu_capability()` 检测到 hybrid CPU，**强制覆盖为 `enable_pmu=N`**
3. 即使通过 `/etc/modprobe.d/kvm-pmu.conf` 设置 `options kvm enable_pmu=1`，仍被覆盖
4. QEMU 的 `-cpu host,pmu=on` 也无效（KVM 层面已禁用）
5. 使用非 hybrid CPU 模型（如 `Skylake-Server-v4,pmu=on`）同样无效（KVM 模块层面的禁用影响所有 VM）

**结论：在当前 host（Intel Arrow Lake hybrid CPU）+ 主线内核上，KVM guest 无法获得硬件 PMU 计数器。这不是配置问题，而是内核的已知限制。**

### 对 BpfReJIT 的影响

- `daemon/src/profiler.rs` 中 `PmuCounters::open()` 在 VM 内调用 `perf_event_open(PERF_TYPE_HARDWARE, BRANCH_INSTRUCTIONS)` 返回 -1 → 返回 `None`
- `collect_program_profiling()` 的 `branch_miss_rate` 为 `None`
- `BranchFlipPass::run()` 检测到 `branch_miss_rate == None` → 立即返回，不做任何 flip
- 这导致 corpus 里 `branch_flip_sites: 0`，branch_flip pass 在所有 VM 测试中完全无效

## 2. 可行解决方案（按推荐度排序）

### 方案 A：添加 `--assume-low-branch-miss-rate` CLI 选项（推荐 ★★★★★）

**原理**：既然 PMU 不可用，允许用户显式告知 daemon "假设分支预测良好"。

**改动**：
1. `daemon/src/main.rs`：增加 `--assume-branch-miss-rate <float>` CLI 参数
2. `daemon/src/commands.rs`：当 PMU 返回 `None` 且用户设置了 assume 值时，用 assume 值替代
3. `daemon/src/profiler.rs`：无需修改

**优点**：
- 改动极小（~10 行 Rust）
- 不依赖任何硬件/内核变更
- 用户可控：对于已知分支可预测的工作负载（如大部分 corpus 程序），设置 `--assume-branch-miss-rate 0.01`
- 保留安全性：不设置时仍为保守策略（skip）

**缺点**：
- 不是真实 PMU 数据，可能在个别程序上误判
- 需要用户手动设置

**Makefile 改动**：
```makefile
# vm-micro 和 vm-micro-smoke 中的 daemon 启动命令改为：
"$(DAEMON_PATH)" --pgo --assume-branch-miss-rate 0.01 serve --socket "$(DAEMON_SOCKET)"
```

### 方案 B：静态分析估算分支可预测性（推荐 ★★★★）

**原理**：对 BPF 程序做静态分析，根据分支模式估算可预测性。

**启发式规则**：
1. 循环回边（backward branch）→ 高可预测（循环通常 taken）
2. 错误检查分支（`if (ret < 0) goto err`）→ 高可预测（通常 not taken）
3. 数据依赖分支（依赖于外部输入）→ 可能不可预测

**改动**：
1. 新增 `daemon/src/analysis/branch_predict.rs`：静态分支预测分析
2. 修改 `BranchFlipPass` 使用静态分析作为 PMU 的 fallback

**优点**：
- 完全不依赖硬件
- 可以在任何环境工作

**缺点**：
- 实现复杂度高（~100-200 行）
- 静态分析准确度有限
- 需要论文中解释和验证

### 方案 C：在非 hybrid 机器上运行 benchmark（推荐 ★★★）

**原理**：使用非 hybrid CPU（如 Intel Xeon、AMD EPYC、或旧款 Intel Core）的机器。

**已知支持 vPMU 的平台**：
- Intel Xeon (任何代)：非 hybrid → KVM vPMU 可用
- AMD EPYC/Ryzen：KVM vPMU 完整支持
- Intel Core 12代之前：非 hybrid → KVM vPMU 可用
- AWS EC2 metal instances：直接硬件 PMU（无虚拟化层）

**优点**：
- 真实 PMU 数据
- 无需代码改动

**缺点**：
- 需要额外硬件/云资源
- 开发环境仍无法测试

### 方案 D：Host-side profiling + 数据传递（推荐 ★★）

**原理**：在 host 上用 `perf stat` 对 VM 进程收集 PMU 数据，通过文件传递给 VM 内的 daemon。

**改动**：
1. Host 脚本：对 QEMU 进程运行 `perf stat -e branches,branch-misses -p <qemu_pid>`
2. 通过共享目录传递 PMU 数据文件
3. Daemon 增加 `--pmu-data-file` 选项读取外部 PMU 数据

**优点**：
- 真实 PMU 数据（虽然是 QEMU 进程级别，不是 BPF 程序级别）

**缺点**：
- 粒度太粗：host PMU 计数的是 QEMU 进程的分支，不是 BPF 程序的分支
- 实现复杂
- 数据准确性差

### 方案 E：等待 upstream 支持 hybrid vPMU（不推荐）

**状态**：Linux 内核社区正在讨论 hybrid PMU 虚拟化支持，但尚无明确时间表。关键难题：
- Guest 看到的是统一 PMU 接口，但 host 有两套不同的 PMU（P-core / E-core）
- vCPU 可能在 P-core 和 E-core 之间迁移，导致 PMU 事件计数不一致
- QEMU 需要暴露 hybrid topology 给 guest

**时间线**：至少 2-3 个内核版本（6-9 个月）

## 3. 推荐实施路径

### 短期（OSDI '26 论文截止前）

**实施方案 A**：`--assume-branch-miss-rate` 选项。

具体步骤：

1. **修改 `daemon/src/main.rs`**：
```rust
/// Assumed branch miss rate when PMU is unavailable.
/// Set this to enable branch_flip in environments without hardware PMU
/// (e.g., KVM on hybrid CPUs). Typical value: 0.01 (1%).
/// When unset and PMU is unavailable, branch_flip is skipped.
#[arg(long)]
assume_branch_miss_rate: Option<f64>,
```

2. **修改 `daemon/src/commands.rs` 的 `collect_pgo_data()`**：
   当 PMU 返回 `None` 且 `assume_branch_miss_rate` 已设置时，用 assume 值填充 `profiling.branch_miss_rate`。

3. **修改 Makefile**：
   在 daemon 启动命令中添加 `--assume-branch-miss-rate 0.01`。

4. **测试**：在 VM 中运行 `make vm-micro` 验证 branch_flip 生效。

### 中期（如果需要真实 PMU 数据）

**方案 C**：在非 hybrid 机器上运行 authoritative benchmarks。

可选：同时实施方案 B 作为 PMU 的 graceful fallback。

## 4. 当前 Makefile/vng 配置参考

当前 vng 启动参数（从 dry-run 输出）：
```
qemu-system-x86_64 -cpu host,topoext=on -machine accel=kvm:tcg -smp 24 -m 1G ...
```

vng 已经使用 `-cpu host`，这是 PMU 透传的前提条件。问题不在 QEMU/vng 配置，而在 KVM 模块层面对 hybrid CPU 的硬性禁用。

如果未来 KVM 支持 hybrid vPMU，只需确保：
1. `modprobe kvm enable_pmu=1`（或通过 `/etc/modprobe.d/`）
2. vng 的 `-cpu host`（已满足）

## 5. 附录：关键文件路径

- KVM PMU 禁用逻辑：`vendor/linux-framework/arch/x86/kvm/pmu.c:117`
- Daemon profiler：`daemon/src/profiler.rs`（`PmuCounters::open()` 在 L352）
- BranchFlipPass PMU 检查：`daemon/src/passes/branch_flip.rs:84-117`
- Pass 注册表：`daemon/src/passes/mod.rs:50-98`
- Daemon CLI：`daemon/src/main.rs:46-59`
- Makefile daemon 启动：`Makefile:226,235`
