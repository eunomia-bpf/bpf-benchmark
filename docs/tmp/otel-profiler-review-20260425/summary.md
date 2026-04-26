# opentelemetry-ebpf-profiler 纳入 benchmark 框架可行性评审

## 结论先行

结论：**可以纳入 benchmark 框架，但应按 app-native loader 新增一个专门的 AppRunner，不应继续把它当作 `corpus/build/` 里的 3 个孤立 `.bpf.o` 对象来处理。**

原因有三点：

1. **它真实的运行单元不是当前 corpus 里的 3 个对象，而是上游在 `support/ebpf/Makefile` 里把 17 个 `*.ebpf.c` 链接出来的 `tracer.ebpf.{amd64,arm64}`。**
2. **它能在 KVM VM 跑，且符合“由原生 app 自己 load BPF”的架构要求；更合适的启动形态是 `otelcol-ebpf-profiler`，而不是依赖外部 collector 的 `ebpf-profiler` CLI。**
3. **它相对 Tracee/Tetragon 能补进 `perf_event` 型 app-native profiler 语义；但相对当前 5 个 app 的总体 program-type 并不引入全新 type，因为 `bpftrace` 已经覆盖了 `perf_event`。**

综合建议：**值得作为第 6 个 app 候选加入，但优先级应是“中等”而不是“最高”**。它带来的是**语义多样性**，不是**program type 全新覆盖**；同时还需要补 runtime artifact 打包。

---

## 1. 项目概况

### 1.1 当前框架状态

- `runner/suites/corpus.env` 和 `runner/suites/e2e.env` 当前默认 native repos 都是：
  - `bcc,bpftrace,katran,tracee,tetragon`
- 也就是说，`opentelemetry-ebpf-profiler` **不在当前 app runner 默认集合里**。

### 1.2 本地配置和历史

- `runner/repos.yaml` 当前仍然保留该 repo：
  - `name: opentelemetry-ebpf-profiler`
  - `url: https://github.com/open-telemetry/opentelemetry-ebpf-profiler.git`
- 它进入本仓库 runner 控制面的历史起点是：
  - commit `66b9fb6d` (`runner: register prebuilt corpus repos`, 2026-03-23)
- 本地源码仓已经存在：
  - `runner/repos/opentelemetry-ebpf-profiler/`
  - 当前本地 repo HEAD 是 `582a2cf`

### 1.3 本地 corpus/build 里有什么

`corpus/build/opentelemetry-ebpf-profiler/` 里当前只有 3 个对象：

| 文件 | 大小 | section / 程序概况 |
| --- | ---: | --- |
| `generic_probe.bpf.o` | 65120 B | 1 个 `kprobe/generic` |
| `native_stack_trace.bpf.o` | 165056 B | 3 个程序：`perf_event/native_tracer_entry`、`perf_event/unwind_native`、`kprobe/unwind_native` |
| `sched_monitor.bpf.o` | 32696 B | 2 个 tracepoint 变体：`sched_process_free/v1`、`/v2` |

附带历史结果里也能看到它只以这 3 个 corpus 对象出现：

- `corpus/results/vm_corpus_20260326_034225/metadata.json` 里，`source_name=opentelemetry-ebpf-profiler` 的统计是：
  - `programs=3`
  - `compile_pairs=0`

### 1.4 关键判断

这 3 个对象**不是**上游 app 的真实运行形态，只是 compile corpus 里挑出来的代表性组件对象。

上游真实运行路径是：

- `support/ebpf/Makefile` 先把 17 个 `*.ebpf.c` 分别编成 LLVM IR
- 再用 `llvm-link-17` 把它们链接成一个总对象：
  - `tracer.ebpf.amd64`
  - `tracer.ebpf.arm64`
- 然后由：
  - `support/support_amd64.go`
  - `support/support_arm64.go`
  把这个总对象 embed 进 userspace binary

所以它天然更适合 `docs/kernel-jit-optimization-plan.md` 里要求的 **app-native loader** 路径，而不是 object-centric 路径。

---

## 2. BPF 程序分析

### 2.1 BPF 源码位置

源码都在：

- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/`

本地共找到 **17 个** `*.ebpf.c`：

- `beam_tracer.ebpf.c`
- `dotnet_tracer.ebpf.c`
- `generic_probe.ebpf.c`
- `go_labels.ebpf.c`
- `hotspot_tracer.ebpf.c`
- `integration_test.ebpf.c`
- `interpreter_dispatcher.ebpf.c`
- `kallsyms.ebpf.c`
- `native_stack_trace.ebpf.c`
- `off_cpu.ebpf.c`
- `perl_tracer.ebpf.c`
- `php_tracer.ebpf.c`
- `python_tracer.ebpf.c`
- `ruby_tracer.ebpf.c`
- `sched_monitor.ebpf.c`
- `system_config.ebpf.c`
- `v8_tracer.ebpf.c`

### 2.2 程序数量

按源码里的 `SEC(...)` 和 `MULTI_USE_FUNC(...)` 展开后，**总共 35 个 BPF 程序入口**。

按 program type 分类如下：

| program type | 数量 | 说明 |
| --- | ---: | --- |
| `kprobe` | 16 | 语言 unwinder、generic probe、kallsyms、off-CPU 等 |
| `perf_event` | 13 | 主采样入口和大部分 unwinder |
| `tracepoint` | 5 | `sched_switch`、`sched_process_free`、`sys_enter_bpf`、integration test |
| `raw_tracepoint` | 1 | `raw_tracepoint/sys_enter` |

这 35 个程序在本地已编好的：

- `support/ebpf/tracer.ebpf.amd64`
- `support/ebpf/tracer.ebpf.arm64`

里都能直接看到对应 section。

### 2.3 结构特征

这个项目的结构和 Tracee/Tetragon 很不一样：

- 它不是“很多彼此独立的小 object”
- 而是“**一个 tail-call 驱动的组合式 profiler**”

其中：

- `native_stack_trace.ebpf.c` 提供采样入口和 native unwinder
- `interpreter_dispatcher.ebpf.c` 提供共享 maps、事件通道和 `unwind_stop`
- 各语言 tracer (`python/php/ruby/v8/perl/hotspot/dotnet/beam/go_labels`) 主要是 unwinder 目标
- `off_cpu.ebpf.c` 只在启用 off-CPU profiling 时额外加载
- `generic_probe.ebpf.c` 只在 `-probe-link` / `-load-probe` 场景加载
- `system_config.ebpf.c` 主要用于启动时做内核布局探测

### 2.4 steady-state 默认加载的不是全部 35 个程序

默认配置下：

- collector 默认 `Tracers: "all"`
- `OffCPUThreshold = 0`
- `ProbeLinks = []`
- `LoadProbe = false`

因此 steady-state 常驻加载大致是：

- `perf_event` 主采样链一组
- `sched_process_free` 一个 tracepoint 变体（`v1` / `v2` 二选一）
- `kallsyms` kprobe

按当前代码路径推算，**默认常驻大约 15 个程序**，而不是 35 个全开。

另外，`system_config.ebpf.c` 里的 `raw_tracepoint/sys_enter` 或 `tracepoint/syscalls/sys_enter_bpf` 会在启动探测阶段**短暂 attach**，探测完成后关闭，不属于 steady-state 常驻集合。

---

## 3. 可行性分析

### 3.1 能否在 KVM VM 里跑

**可以，前提是 guest 具备 root / ptrace / perf / BPF 权限。**

本地证据：

- README 明确说明这是 Linux-only profiler，建议 root 或具备相应 capabilities
- `collector/config/config.go` 的 kernel check 要求：
  - amd64 最低 `5.2`
  - arm64 最低 `5.5`
- README 对最低版本的表述更保守，写的是“后续变更可能要求 5.4+”；**文档和当前代码门槛并不完全一致**。如果后续真接入 benchmark，guest 兼容性判断应以**实际启动代码路径**为准，而不是只看 README。
- 代码中不仅用到了 `cilium/ebpf` / `link.*`，还用到了：
  - `perf_event_open`（采样）
  - `ptrace`（进程/线程信息读取）
  - `/proc` / `kallsyms`

对 benchmark VM 的含义：

- 权限模型上，它和当前 Tracee/Tetragon 同类，甚至更“普通”
- 它不依赖 Kubernetes，也不依赖容器 runtime
- 只要 guest 以 root 运行，并允许 perf event + ptrace，即可在 KVM VM 工作

### 3.2 启动方式

有两条启动路径：

1. `ebpf-profiler`

示例命令来自 README：

```sh
sudo ./ebpf-profiler -collection-agent=127.0.0.1:11000 -disable-tls
```

问题：

- 这个 CLI 会先启动 OTLP reporter
- `reporter.Start()` 会阻塞等待外部 gRPC endpoint
- **不适合直接当 benchmark 里的独立 app binary**

2. `otelcol-ebpf-profiler`

示例命令来自 README：

```sh
sudo ./otelcol-ebpf-profiler --feature-gates=+service.profilesSupport --config cmd/otelcol-ebpf-profiler/local.example.yaml
```

关键点：

- 它把 profiler receiver 嵌进 OpenTelemetry Collector
- `cmd/otelcol-ebpf-profiler/manifest.yaml` 已包含 `debugexporter`
- 所以可以改成一个本地 debug/no-op 类 exporter 配置，**不需要外部 collector**

这条路径更适合 AppRunner。

### 3.3 写 AppRunner 的复杂度

结论：**中等复杂度，难点主要不在 lifecycle，而在 artifact 打包。**

容易的部分：

- lifecycle 很清晰：启动一个长期驻留进程，等待 BPF 程序出现，跑 workload，停进程
- workload 选择也简单：它是 CPU sampling profiler，不需要像 Tetragon 那样安装 policy，也不需要像 Katran 那样准备网络拓扑
- 现有 workload（如 CPU / exec / file / scheduler 类）已经足够触发它

麻烦的部分：

1. **当前 runtime image 没给它预装 binary/artifact**

本地 `runner-runtime.Dockerfile` 只给 app-native runner 显式打包了：

- Tracee
- Tetragon

并在最终阶段只建立了：

- `repo-artifact-root/.../tracee`
- `repo-artifact-root/.../tetragon`

没有 OTel profiler 的 artifact。

2. **当前 guest 运行镜像无法现场编译它**

最终 runtime image 会清掉：

- `clang`
- `llvm`
- `git`
- `/usr/local/go`
- `runner/repos`

所以当前 guest 里**既没有源码，也没有 Go/LLVM toolchain**，不能像开发机上一样 `make ebpf-profiler` 或 `make otelcol-ebpf-profiler`。

3. **因此必须补一个 artifact 供应方案**

可选方案只有三种：

- 在 image build 阶段新增 OTel profiler build/artifact stage，像 Tracee/Tetragon 一样放进 `repo-artifacts/<arch>/`
- 保留 guest 编译工具链，在 VM 内现编现跑
- 自己写 repo-owned wrapper binary，把 upstream tracer package 当库嵌进去

其中合理方案只有第一种。

### 3.4 推荐的接入方式

如果要接，建议这样做：

1. 先只做 **amd64**
2. 打包 **`otelcol-ebpf-profiler`**，不要打包 `ebpf-profiler`
3. AppRunner 启动时生成一个最小 collector config：
   - `receivers: profiling`
   - `exporters: debug`
   - `service.pipelines.profiles`
4. 健康检查用“两段式”：
   - 进程未退出
   - `bpftool prog show` 观察到新程序集合稳定
5. 初版 workload 直接复用现有 CPU / exec / scheduler 类 workload

---

## 4. 与现有 app 的对比

### 4.1 与 Tracee / Tetragon 的本质区别

| 维度 | OTel profiler | Tracee | Tetragon |
| --- | --- | --- | --- |
| 角色 | **sampling profiler** | event/security tracer | policy-driven security/observability tracer |
| 主触发机制 | `perf_event` 周期采样 | syscall / raw tracepoint / kprobe | kprobe / tracepoint / raw tracepoint / socket filter |
| userspace 行为 | 长驻 agent，持续采样和 unwind | 长驻 tracer | 长驻 tracer + policy engine |
| workload 依赖 | 任何能制造 CPU 活跃度的 workload | 事件型 workload 更重要 | policy 命中的 workload 更重要 |

它最像的不是 Tracee/Tetragon，而是“一个 app-native、长驻、多语言 unwinder profiler”。

### 4.2 program type 对比

从当前最新 e2e 结果看：

| app | 当前覆盖的 program type |
| --- | --- |
| `tracee` | `raw_tracepoint`, `kprobe`, `cgroup_skb`, `lsm` |
| `tetragon` | `kprobe`, `tracepoint`, `raw_tracepoint`, `socket_filter` |
| `bcc` | `kprobe`, `tracepoint`, `raw_tracepoint`, `tracing` |
| `bpftrace` | `kprobe`, `tracepoint`, `perf_event` |
| `katran` | `xdp`, `sched_cls` |

OTel profiler 的源码/embedded object 覆盖：

- `kprobe`
- `perf_event`
- `tracepoint`
- `raw_tracepoint`

因此结论要分两层看：

1. **相对 Tracee/Tetragon**

- 它能补进 **`perf_event`** 这一类 app-native 采样程序
- 这是它最有价值的差异点

2. **相对当前 5 个 app 的总体并集**

- **它不引入 brand-new program type**
- 因为 `bpftrace` 已经覆盖了 `perf_event`

所以它的价值主要不是“把 type coverage 从 9 种扩到 10 种”，而是：

- 把 **`perf_event` 从脚本型工具扩展到长期驻留的 app-native profiler**
- 引入 **sampling + unwind + tail-call unwinder** 这一整类负载语义

### 4.3 resident program 规模对比

当前最新 e2e 结果里的常驻 program 数量大致是：

- `tracee`: 158
- `tetragon`: 287
- OTel profiler（默认代码路径推算）: 约 15

也就是说，OTel 不是“大量 event hook”型 app，而是“较少 resident 程序 + 高频 perf sampling”型 app。这一点对 benchmark 的多样性是正向的。

---

## 5. git 历史里是否曾经有过 runner 实现

结论：**没有找到。**

我检查了两类证据：

1. 当前工作树

- `runner/libs/app_runners/` 里没有 OTel profiler runner
- `e2e/cases/` 里没有对应 case
- `runner/containers/runner-runtime.Dockerfile` 里没有对应 artifact copy / symlink

2. 仓库 git 历史

- 历史里能稳定找到的只有：
  - `runner/repos.yaml` 注册记录
  - 一系列 `docs/tmp/` 分析文档
  - `corpus/results/` 里它作为 compile corpus 来源的历史记录
- **没有发现曾经存在、后来被删掉的 `AppRunner` / `e2e case` / runtime artifact 集成**

所以它的现状可以概括为：

- **历史上被纳入过 repo/corpus 视野**
- **但从未真正进入 app-native runner 体系**

---

## 6. 最终建议

### 6.1 是否适合加入 benchmark 框架

**适合。**

但我建议把目标说准确：

- 不是“把当前 corpus 里的 3 个 `.bpf.o` 变 runnable”
- 而是“新增一个 OTel profiler 的 app-native runner”

### 6.2 优先级判断

**优先级：中等。**

正面因素：

- 满足 plan 文档对 app-native loader 的要求
- 能在 KVM VM 里以原生方式运行
- 引入 profiler / sampling / unwind 语义
- 相对 Tracee/Tetragon 新增 `perf_event` 维度

限制因素：

- 相对现有 5 app 的总体 type coverage **没有新增全新 type**
- 当前 runtime image 没有可直接启动的 artifact
- 需要补 image build / artifact packaging

### 6.3 建议落地顺序

1. 先加 runtime artifact 打包，目标 binary 选 `otelcol-ebpf-profiler`
2. 新增 `runner/libs/app_runners/otel_profiler.py`
3. 初版只做 amd64
4. 初版只用默认 tracer 集合，不打开 off-CPU / `-load-probe`
5. 先接 corpus，再决定是否单独设计 e2e 指标

amd64-first 的理由：

- 当前 benchmark 主验证路径本来就以 x86/KVM 为主
- README 明确写了 ARM64 下 `.NET` unwinder 例外
- 而 receiver 默认 `Tracers: "all"`，ARM64 上是否要显式裁掉某些 tracer，值得单独再做一轮验证

如果只问一句话版本：

> **值得接，但应作为“第 6 个 app-native profiler loader”来接；不要继续沿用当前 3 个 corpus 对象的 object-centric 处理方式。**
