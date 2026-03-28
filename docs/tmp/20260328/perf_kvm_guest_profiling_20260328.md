# perf kvm / guest PMU profiling 调研（2026-03-28）

## TL;DR

- `perf kvm stat` 有两层完全不同的语义，必须分开看：
  - `perf kvm stat record|report|live`：统计 **KVM tracepoint**（`vmexit/mmio/ioport`），不是 PMU。
  - `perf kvm --guest stat ...`：只是 `perf stat` 的 alias 路径；真正决定 guest-only PMU 过滤的是事件修饰符 `:G` / `:Gk` / `:Gu`。
- 在这台宿主机上，`kvm.enable_pmu=N`、guest 内 `perf_event_open=ENOENT` 的前提下：
  - `perf kvm --guest stat record/report/live` 仍然能工作，因为它走的是 **host KVM tracepoints**，不依赖 vPMU。
  - `perf stat -e cycles:Gk,... -p <qemu-pid>` 也能工作，因为它走的是 **host PMU + guest context filter**，不依赖 guest vPMU。
- 如果目标是 guest 里 BPF JIT 程序的 `branch_misses / instructions / cycles`：
  - `perf kvm stat` 不行，它只能看 vCPU 退出原因和退出耗时。
  - `perf stat -e ...:Gk -p <qemu-pid>` 可以拿到 **整台 VM 的 guest-kernel 汇总**。
  - 想靠宿主机进一步细到单个 BPF 程序，最有希望的是 `perf record -e ...:Gk -p <qemu-pid>` + `perf kvm --guest report` + guest kallsyms/BPF JIT symbols。

## 测试环境

- 宿主机内核：`6.15.11-061511-generic`
- 宿主机 CPU：Intel Arrow Lake hybrid，输出被拆成 `cpu_atom/*` 和 `cpu_core/*`
- 宿主机 `kvm.enable_pmu`：`N`
- 宿主机 `perf_event_paranoid`：`2`
- 当前仓库的 `vm_global` 锁已被一个 `vm-e2e` 会话占用，所以没有再启动第二个 VM；本次直接复用现成的 QEMU 进程：
  - QEMU PID：`236532`
- 系统 `/usr/bin/perf` 只是 Ubuntu wrapper，当前 host kernel 对应的 linux-tools 没装；本次实测使用的是从 `vendor/linux-framework/tools/perf` 构出的本地 binary：
  - `perf version 7.0.rc2.gc0938be86146`

额外注意：

- 这个仓库的 `vm-shell` 实际吃的是 `VM_COMMAND`，不是 `VM_EXEC`。
- `make -n vm-shell TARGET=x86 VM_EXEC='sleep 30'` 展开后会得到 `VM_COMMAND=''`，所以用户给的那条命令在本仓库里不会把 `sleep 30` 传进去。
- 如果真要按仓库入口起一个短命 VM，正确变量名应该是 `VM_COMMAND='sleep 30'`。

## 1. `perf kvm stat --guest` 到底是什么

这里有一个常见混淆点：

- `perf kvm stat record|report|live` 是 **KVM exit tracepoint 统计器**。
- `perf kvm --guest stat ...` 是 **`perf stat` 的 alias 路径**。
- `perf kvm stat --guest ...` 这个写法本身是错位的，`--guest` 放在 `stat` 后面时会被当成普通 `perf stat` 的参数，直接报错。

实测：

```text
$ /tmp/perf-host-notest-20260328/perf kvm stat --guest -e cycles -- sleep 0.1
Error: unknown option `guest'
```

而 `perf kvm stat` 不带 `record/report/live` 时，源码会直接落回 `cmd_stat()`。这和帮助输出一致：

```text
$ /tmp/perf-host-notest-20260328/perf kvm stat
Usage: perf kvm stat <command>

# Available commands:
    record: record kvm events
    report: report statistical data of kvm events
    live:   live reporting of statistical data of kvm events

Otherwise, it is the alias of 'perf stat':
```

### 1.1 正确的命令形态

推荐把三类命令分清：

| 目的 | 正确命令 |
| --- | --- |
| KVM exit 实时统计 | `sudo perf kvm --guest stat live -p <qemu-pid>` |
| KVM exit 录制 + 离线汇总 | `sudo perf kvm --guest stat record -p <qemu-pid> -o file sleep 2` 然后 `sudo perf kvm -i file stat report --stdio` |
| guest PMU 汇总计数 | `sudo perf stat -e cycles:Gk,instructions:Gk,branches:Gk,branch-misses:Gk -p <qemu-pid> --timeout 1000` |
| guest PMU 采样 + 符号化 | `sudo perf record -e cycles:Gk -p <qemu-pid> ...` 然后 `sudo perf kvm -i perf.data --guest report --stdio` |

### 1.2 `perf kvm stat record|report|live` 是否需要 vPMU

不需要。

原因有两层：

- 文档和源码都表明它订阅的是 `kvm:*` tracepoint。
- 本机当前 `kvm.enable_pmu=N`、guest 内 `perf_event_open=ENOENT`，但 `perf kvm stat record/report/live` 仍然工作。

因此它不是从 guest vPMU 读硬件计数器，也不是从 guest 内 `perf` 基础设施取数，而是从宿主机 KVM tracepoint 观察 VM 退出行为。

### 1.3 输出格式是什么

`perf kvm stat live` / `perf kvm stat report` 的输出是按 **VM-EXIT reason** 聚合的表，列包括：

- `Samples`
- `Samples%`
- `Time%`
- `Min Time`
- `Max Time`
- `Avg time`

可以按 `--pid` 和 `--vcpu` 过滤，但粒度是：

- 一台 VM
- 一个 vCPU
- 一类 VM-exit reason

不是：

- 某个 guest 内核函数
- 某个 BPF 程序
- 某个 guest PMU event

### 1.4 是否需要 guest kallsyms / perf.data

分两类看：

- `perf kvm stat live`：不需要 `perf.data`，也不需要 guest kallsyms。
- `perf kvm stat record` + `perf kvm stat report`：需要 `perf.data`，但 **不需要 guest kallsyms**。

这点实测也成立：本次 `kvm stat report` 在完全没提供 guest kallsyms 的情况下正常产出了 VM-exit 汇总表。

## 2. `perf stat -e cycles:G` 是什么

`G` 是 perf event modifier，语义是 **guest counting**。

本地 perf 文档里写得很明确：

- `G`：guest counting
- `H`：host counting
- 可与 `u`/`k` 组合

本地 perf 源码测试也验证了：

- `cycles:G` 会把 `exclude_host=1`
- 同时保留 `exclude_guest=0`

因此：

- `cycles:G`：guest user + guest kernel
- `cycles:Gu`：guest user only
- `cycles:Gk`：guest kernel only
- `cycles:H`：host only

对 guest 里的 BPF JIT 而言，最相关的是 **`Gk`**，因为 BPF 程序运行在 guest kernel。

### 2.1 它是否依赖 vPMU

实测结论：**不依赖 guest vPMU。**

证据：

- guest 内 `perf_event_open` 已知返回 `ENOENT`
- `/sys/module/kvm/parameters/enable_pmu = N`
- 但宿主机侧 `perf stat -e cycles:Gk,... -p 236532` 仍然成功给出了计数

这说明 `:G` / `:Gk` 用的是 **host PMU 的 guest context 过滤**，不是 guest vPMU passthrough。

### 2.2 它和 `perf kvm stat` 的区别

根本区别：

- `perf kvm stat record|report|live`：看 **KVM exit 行为**
- `perf stat -e cycles:Gk,...`：看 **硬件 PMU 计数**

前者回答：

- 为什么 VM 退出
- 退出了多少次
- 每类退出花了多久

后者回答：

- guest 跑了多少 cycles
- 执行了多少 instructions
- 多少 branches / branch-misses

它们不是同一类工具，也不能互相替代。

## 3. 实际测试

### 3.1 KVM tracepoint 权限

当前机器上，`kvm_entry` tracepoint 是 root-only：

```text
$ ls -l /sys/kernel/tracing/events/kvm/kvm_entry/enable
-rw-r----- 1 root root 0 ... /sys/kernel/tracing/events/kvm/kvm_entry/enable
```

所以非 root 跑 `perf kvm stat record` 会直接失败：

```text
$ perf kvm --guest stat record -p 236532 -o /tmp/perf-kvm-record-user.data sleep 1
event syntax error: 'kvm:kvm_entry'
                     \___ can't access trace events

Error: No permissions to read /sys/kernel/tracing//events/kvm/kvm_entry
```

### 3.2 `perf kvm --guest stat live`

按 perf 自测脚本的方式，用 `sleep 10 | timeout 5s ...` 保持 stdin 打开，得到稳定的实时汇总输出：

命令：

```bash
sudo bash -lc 'sleep 10 | timeout 5s /tmp/perf-host-notest-20260328/perf kvm --guest stat live -p 236532 --event vmexit --key sample > /tmp/perf-kvm-live-20260328.log 2>&1'
```

实际输出片段：

```text
RC=124
14:42:37.584830

Analyze events for pid(s) 236532, all VCPUs:

                                 VM-EXIT    Samples  Samples%     Time%    Min Time    Max Time         Avg time

                                     HLT      42148    75.72%    87.89%      0.36us  15668.98us    276.60us ( +-   1.25% )
                               MSR_WRITE      11697    21.01%    10.53%      0.56us  12262.10us    119.42us ( +-   5.57% )
                      EXTERNAL_INTERRUPT        960     1.72%     0.92%      0.69us  15253.27us    127.37us ( +-  25.45% )
                        PREEMPTION_TIMER        746     1.34%     0.55%      0.40us   7300.20us     98.64us ( +-  23.56% )
```

结论：

- `perf kvm stat live` 在当前机器上是可用的。
- 输出是 VM-exit 汇总，不是 PMU 汇总。

### 3.3 `perf kvm --guest stat record` + `stat report`

命令：

```bash
sudo /tmp/perf-host-notest-20260328/perf kvm --guest stat record -p 236532 -o /tmp/perf-kvm-record-20260328.data sleep 2
sudo /tmp/perf-host-notest-20260328/perf kvm -i /tmp/perf-kvm-record-20260328.data stat report --stdio
```

实际输出：

```text
RC=0
[ perf record: Woken up 27 times to write data ]
[ perf record: Captured and wrote 79.241 MB /tmp/perf-kvm-record-20260328.data (704426 samples) ]
```

报告：

```text
Analyze events for all VMs, all VCPUs:

                                 VM-EXIT    Samples  Samples%     Time%    Min Time    Max Time         Avg time

                                     HLT     239111    75.17%    99.72%      0.36us  15261.51us    143.66us ( +-   0.37% )
                               MSR_WRITE      68094    21.41%     0.22%      0.53us      9.23us      1.12us ( +-   0.11% )
                      EXTERNAL_INTERRUPT       5401     1.70%     0.04%      0.66us     56.49us      2.67us ( +-   0.90% )
                        PREEMPTION_TIMER       4905     1.54%     0.01%      0.33us      4.46us      0.77us ( +-   0.41% )
                       PAUSE_INSTRUCTION        489     0.15%     0.00%      0.56us      4.15us      1.45us ( +-   1.64% )
```

这再次证明：

- `perf kvm stat` 看的是 VM exits
- 不需要 vPMU
- 也拿不到 `cycles / instructions / branch-misses`

### 3.4 `perf stat -e cycles:G,...`

命令：

```bash
sudo /tmp/perf-host-notest-20260328/perf stat \
  -e cycles:G,instructions:G,branches:G,branch-misses:G \
  -p 236532 --timeout 2000
```

实际输出：

```text
Performance counter stats for process id '236532':

          78350563      cpu_atom/cycles/G
         754343732      cpu_core/cycles/G
          48041331      cpu_atom/instructions/G
         666728975      cpu_core/instructions/G
           8818291      cpu_atom/branches/G
         119010575      cpu_core/branches/G
            169464      cpu_atom/branch-misses/G
            686053      cpu_core/branch-misses/G

       2.006693590 seconds time elapsed
```

这说明宿主机侧 guest-only PMU 计数是能拿到的。

### 3.5 `:G` / `:H` / `:Gk` / `:Gu` 的实际对比

为了看清 modifier 语义，对同一 QEMU PID 取了几组 1 秒窗口：

| 命令 | 语义 | 结果概览 |
| --- | --- | --- |
| `perf stat -e cycles -p 236532 --timeout 1000` | guest+host 混合 | `cpu_atom 36.0B` / `cpu_core 42.2B` |
| `perf stat -e cycles:G -p 236532 --timeout 1000` | guest user + guest kernel | `cpu_atom 33.9B` / `cpu_core 42.6B` |
| `perf stat -e cycles:H -p 236532 --timeout 1000` | host only | `cpu_atom 3.9B` / `cpu_core 4.7B` |
| `perf stat -e cycles:Gk -p 236532 --timeout 1000` | guest kernel only | `cpu_atom 31.1B` / `cpu_core 36.9B` |
| `perf stat -e cycles:Gu -p 236532 --timeout 1000` | guest user only | `cpu_atom 2.05B` / `cpu_core 2.14B` |

结论：

- 普通 `cycles` 约等于 `cycles:G + cycles:H`
- 对 guest 内核 BPF，应该用 `:Gk`，不是只用 `:G`
- 当前 VM 的 guest-kernel 周期明显大于 guest-user 周期

### 3.6 非 root 时的限制

非 root 跑 `cycles:G` 时，输出变成了 `Gu`：

```text
$ /tmp/perf-host-notest-20260328/perf stat -e cycles:G -p 236532 --timeout 1000

Performance counter stats for process id '236532':

        1648223146      cpu_atom/cycles/Gu
        2164037337      cpu_core/cycles/Gu
```

而非 root 直接请求 `Gk` 会失败：

```text
$ /tmp/perf-host-notest-20260328/perf stat -e cycles:Gk -p 236532 --timeout 1000
Error:
No supported events found.
...
perf_event_paranoid setting is 2
```

所以在当前 host 配置下：

- 非 root 只能安全地看到 guest user
- 想数 guest kernel（也就是 BPF JIT）需要 `sudo`

## 4. 能不能用于 BPF profiling

### 4.1 `perf kvm stat`

不能。

原因很直接：

- 它没有 PMU 事件接口
- 输出只有 `VM-EXIT reason` 及其时间分布
- 最细粒度是 vCPU，不是 guest 内函数，更不是 BPF 程序

它可以回答：

- 这个 workload 是否因为 `HLT` / `MSR_WRITE` / `EXTERNAL_INTERRUPT` 等退出很多

它不能回答：

- 某个 BPF 程序执行了多少 `branch_misses`
- 某个 BPF 程序用了多少 `instructions`

### 4.2 `perf stat -e ...:Gk -p <qemu-pid>`

可以，但只能拿到 **整台 VM 的 guest-kernel 汇总**。

这条路径对当前目标是有价值的，因为 guest BPF JIT 运行在 guest kernel：

- `cycles:Gk`
- `instructions:Gk`
- `branches:Gk`
- `branch-misses:Gk`

都能从宿主机侧拿到。

但是它的边界也很清楚：

- 粒度是整个 QEMU 进程里的 guest-kernel 活动
- 不是单个 BPF 程序
- 也不是单次 `BPF_PROG_TEST_RUN` 的纯净硬件计数

### 4.3 能否用 `BPF_PROG_TEST_RUN` 前后做 delta

可以做，但只能作为近似值，不能当成“单个 BPF 程序精确 PMU 归因”。

如果要这么用，建议条件尽量收紧：

- 独占一个 VM
- guest 尽量静默，减少后台任务
- 固定 vCPU / CPU 亲和性
- 测试窗口内只跑 `BPF_PROG_TEST_RUN`
- 同一程序重复很多次，做大信号
- 另跑一组无 BPF 或空程序的 baseline，扣掉 harness / syscall / IRQ 噪音

即使这样，delta 仍然会混入：

- guest kernel 里调用 `BPF_PROG_TEST_RUN` 的框架开销
- 中断和调度噪音
- 其他 guest kernel 活动

所以这条路更适合：

- 对比 A/B 版本
- 看趋势
- 做 smoke-level 微架构回归检测

不适合：

- 声称“这是单个 BPF 程序的精确 branch_misses 真值”

## 5. 替代方案

### 5.1 `perf record -e cycles:G / cycles:Gk + guest symbols`

这是最有希望逼近“单个 BPF 程序热点归因”的方案。

本次实测先用 `cycles:G` 验证链路本身是否可用；如果目标明确是 guest kernel 里的 BPF JIT，实际应改成 `cycles:Gk`。

实测命令：

```bash
sudo timeout 1s /tmp/perf-host-notest-20260328/perf record \
  -e cycles:G -p 236532 -o /tmp/perf-cyclesG-20260328.data
```

成功写出了数据：

```text
[ perf record: Captured and wrote 1.337 MB /tmp/perf-cyclesG-20260328.data (26333 samples) ]
```

然后用 guest 视角 report：

```bash
sudo /tmp/perf-host-notest-20260328/perf kvm -i /tmp/perf-cyclesG-20260328.data --guest report --stdio
```

实际输出片段：

```text
# Samples: 15K of event 'cpu_atom/cycles/G'
#
# Overhead  Command  Shared Object  Symbol
#
     2.10%  :236550  [unknown]      [g] 0xffffffffa9dc1eed
     2.10%  :236538  [unknown]      [g] 0xffffffffa9dc1eed
     1.67%  :236540  [unknown]      [g] 0xffffffffa9dc1eed
```

这说明：

- host 侧 `cycles:G` 采样是可行的
- `perf kvm --guest report` 能识别这些 sample 属于 guest（`[g]`）
- 但因为没有 guest kallsyms / guest vmlinux，符号全是 `[unknown]`

所以要把这条路推进到 BPF 程序级别，还需要：

- guest kallsyms / guest vmlinux / `--guestmount`
- guest 里的 BPF JIT 符号能被导出并被 perf 解析

如果 guest `/proc/kallsyms` 里能看到 JIT 后的 `bpf_prog_*` 符号，那么这条路才有机会把 sample 归到具体 BPF 程序。

### 5.2 `perf stat` 包裹 QEMU / vng

这条路现在就能落地，优点是简单、低开销：

```bash
sudo perf stat \
  -e cycles:Gk,instructions:Gk,branches:Gk,branch-misses:Gk \
  -p <qemu-pid> --timeout <ms>
```

建议：

- 用显式 `:Gk`
- 不要依赖 `perf kvm --guest stat -e cycles ...` 这种 alias 写法

本次实测里，`perf kvm --guest stat -e cycles -p 236532` 的输出没有 `/G` 标记，数值也和普通 `perf stat -e cycles` 非常接近；因此从可读性和确定性上，**直接写 `:Gk` 更稳妥**。

### 5.3 QEMU `-icount` / plugin

这条路适合做：

- 指令数
- 自定义翻译块/访存/分支 instrumentation
- 更确定性的仿真计数

但它不能替代硬件 PMU，因为拿不到真实：

- `cycles`
- `branch_misses`
- 真实微架构层面的 cache / frontend / backend 行为

所以它更像 “功能性 fallback” 或 “确定性分析工具”，不是 `perf stat` 的硬件计数替代品。

## 6. 结论

对当前问题，最实用的结论是：

- `perf kvm stat` 不能用来量 guest BPF 的 `branch_misses / instructions / cycles`；它只能看 KVM exits。
- 宿主机侧 **可以** 在 `kvm.enable_pmu=N` 的前提下，通过 `perf stat -e ...:Gk -p <qemu-pid>` 量到 guest-kernel 的 PMU 汇总。
- 如果只是想给 `BPF_PROG_TEST_RUN` 拿一组可重复的硬件计数，`cycles:Gk / instructions:Gk / branches:Gk / branch-misses:Gk` 是目前最直接可用的方案。
- 如果想进一步细到单个 BPF 程序，应该走 `perf record -e ...:Gk` + `perf kvm --guest report` + guest kallsyms / BPF JIT symbols，而不是继续研究 `perf kvm stat`。

## 7. 本次参考的本地资料

- `vendor/linux-framework/tools/perf/Documentation/perf-kvm.txt`
- `vendor/linux-framework/tools/perf/Documentation/perf-list.txt`
- `vendor/linux-framework/tools/perf/builtin-kvm.c`
- `vendor/linux-framework/tools/perf/tests/parse-events.c`
