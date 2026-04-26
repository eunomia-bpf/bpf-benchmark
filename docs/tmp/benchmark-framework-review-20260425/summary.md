# Benchmark Framework 设计与架构 Review

日期：2026-04-25

本文聚焦当前仓库里的 benchmark framework 主路径，不评审各第三方 app 本身的业务逻辑，也不深入 daemon Rust pass 实现细节；重点是 benchmark orchestration、runner、lifecycle、measurement、执行基础设施和 daemon 交互。

## 先说结论

当前 benchmark framework 已经形成了比较清晰的四层结构：

1. 入口与配置层：`Makefile` + `runner.libs.run_target_suite` + `runner.libs.run_contract`，负责把“用户意图”变成可执行 contract。
2. 执行环境层：KVM/AWS executor + runtime container command，负责把 suite 放到目标内核环境里执行。
3. suite orchestration 层：`micro/driver.py`、`corpus/driver.py`、`e2e/driver.py`，负责 benchmark 语义本身。
4. lifecycle / measurement / daemon 层：`runner.libs.case_common`、`runner.libs.bpf_stats`、`runner.libs.rejit`、`runner.libs.run_artifacts`，负责统一 phase、采样、ReJIT apply 和结果落盘。

但这个框架也有几个明显问题：

- 三层 benchmark 并不对称。`micro` 本质上是 characterization harness，不走 daemon/ReJIT 主路径，和 `corpus` / `e2e` 不是同一种 benchmark。
- lifecycle 抽象比较深，`run_app_runner_lifecycle -> run_case_lifecycle -> run_lifecycle_sessions` 叠了三层，抽象收益存在，但错误模型已经开始混乱。
- 文档和实现有明显漂移：README 仍写 `e2e` 包含 `scx`，runtime architecture 文档声称“不会把整个 host repo mount 到 runtime image”，但代码实际就是 whole-workspace bind mount。
- `corpus` 的“多 app 同时常驻，再统一 baseline/rejit/post_rejit”设计很有研究价值，但实现上高度依赖全局 BPF program table diff，程序归属推断偏脆弱。

下面按模块展开。

## 1. 整体架构

### 1.1 设计思路和分层

从入口到结果输出的主调用链如下：

```text
make vm-micro / vm-corpus / vm-e2e
  -> python -m runner.libs.run_target_suite
     -> build_run_config() 组合 target/suite/env/CLI
     -> local_prep_targets() 预构建 runtime image / daemon / kernel image
     -> kvm_executor.run_vm_suite() 或 aws_executor._run_aws()
        -> docker run ... python -m runner.suites.<suite>
           -> micro/driver.py 或 corpus/driver.py 或 e2e/driver.py
              -> runner / lifecycle / daemon / bpf_stats
              -> ArtifactSession 写 metadata.json + details/*
```

这条链路的代码定位：

- `Makefile:57-129` 暴露 canonical 入口。
- `runner/libs/run_target_suite.py:146-181` 是统一分发入口。
- `runner/libs/run_contract.py:271-420` 负责 contract 构造。
- `runner/libs/kvm_executor.py:112-139` 和 `runner/libs/aws_executor.py:713-725` 分别负责 KVM/AWS。
- `runner/libs/suite_commands.py:96-148` 负责 runtime container 命令拼装。
- `runner/suites/micro.py:126-148`、`runner/suites/corpus.py:67-81`、`runner/suites/e2e.py:63-75` 是 suite entrypoint。
- `runner/libs/run_artifacts.py:19-82` 负责结果目录和 metadata/details 结构。

我认为这个设计的核心优点是“入口统一，suite 分离，lifecycle 复用”。也就是说：

- 用户只需要记住 `Makefile` 和 target/suite 名称。
- KVM/AWS 只是 executor 差异，suite 自身逻辑不需要知道运行在 VM 还是 EC2。
- `corpus` / `e2e` 共用 runner、lifecycle、daemon apply、bpf_stats 和 artifact 落盘。

### 1.2 各目录职责

按当前 active tree 看，关键目录职责如下：

- `runner/`
  - 这是 framework 的控制平面。
  - `runner/targets/*.env` 定义 target contract，比如 `x86-kvm` 用 `virtme-ng`，`aws-*` 用 `aws-ssh`，见 `runner/targets/x86-kvm.env:1-10`、`runner/targets/aws-x86.env:1-13`、`runner/targets/aws-arm64.env:1-13`。
  - `runner/suites/*.env` 定义 suite 级默认值，比如 benchmark VM class、timeout、native repo 依赖，见 `runner/suites/micro.env:1-4`、`runner/suites/corpus.env:1-5`、`runner/suites/e2e.env:1-5`。
  - `runner/libs/` 提供 contract、executor、lifecycle、runner、measurement、artifact 等共享逻辑。
  - `runner/build-*` 和 `micro_exec` 是 micro benchmark 的执行器产物，见 `micro/config/micro_pure_jit.yaml:13-21` 和 `runner/libs/workspace_layout.py:17-21`。

- `micro/`
  - isolated micro benchmark 层。
  - `micro/config/micro_pure_jit.yaml:1-42` 定义 manifest、runtime、defaults、benchmark 列表。
  - `micro/driver.py:395-682` 是完整执行与统计入口。
  - 当前 manifest 里共有 62 个 micro benchmark，我是直接统计 `micro/config/micro_pure_jit.yaml` 里的 `benchmarks:` 列表得到的；类别主要分布在 `memory-local`、`alu-mix`、`control-flow`、`loop-shape`、`dependency-ilp` 等。

- `corpus/`
  - real-world app corpus benchmark 层。
  - `corpus/config/macro_apps.yaml:1-24` 定义默认 app suite。
  - `corpus/config/benchmark_config.yaml:1-52` 定义 ReJIT pass profile。
  - `corpus/driver.py:340-507` 是 corpus suite 的核心运行逻辑。
  - 当前默认 `macro_apps` suite 一共 19 个 app，不包含 `scx`。

- `e2e/`
  - deployment-style end-to-end benchmark 层。
  - `e2e/driver.py:98-124` 定义当前 active case 列表和 `all` 模式。
  - `e2e/cases/*/case.py` 封装各 case 的 phase 设计和报告格式。
  - 当前 active case 只有 5 个：`tracee`、`tetragon`、`bpftrace`、`bcc`、`katran`。

- `daemon/`
  - `bpfrejit-daemon` 用户态控制平面。
  - `daemon/README.md:3-7` 明确它负责发现 live kernel BPF program、运行 rewrite pipeline、并通过 `BPF_PROG_REJIT` 应用新 bytecode。
  - benchmark framework 只依赖它的 `serve` socket 接口，见 `daemon/README.md:18-63` 和 `runner/libs/rejit.py:651-875`。

- `docs/`
  - 背景、架构和临时分析文档。
  - 项目背景看 `docs/kernel-jit-optimization-plan.md:22-25,167-169`。
  - runtime/container/host 边界看 `docs/benchmark-runtime-architecture.md:11-24,118-151`。

### 1.3 数据流：从启动到结果输出

主数据流可以拆成 6 步：

```text
用户参数
  -> Makefile 环境变量
  -> RunConfig / suite_args
  -> executor(KVM/AWS) + runtime container
  -> suite driver(micro/corpus/e2e)
  -> runner.start + workload + bpf_stats + daemon.apply_rejit
  -> ArtifactSession(metadata.json + details/result.json + result.md)
```

细化到代码：

1. `Makefile:57-129` 把 `SAMPLES/WARMUPS/INNER_REPEAT/BENCH` 或 AWS 参数传给 Python 入口。
2. `runner/libs/suite_args.py:57-94` 把环境变量转换成 suite argv。
3. `runner/libs/run_contract.py:271-410` 把 target env、suite env、host env、suite args 合并成 `RunConfig`。
4. `runner/libs/run_target_suite.py:155-180` 根据 `RunConfig.identity.executor` 选择 KVM 或 AWS。
5. `runner/libs/suite_commands.py:96-148` 把 suite 命令包装成 runtime container 命令。
6. suite driver 执行 benchmark，最后用 `ArtifactSession.write()` 写结果，见 `runner/libs/run_artifacts.py:36-82`。

## 2. 三层 benchmark 设计

### 2.1 micro benchmark

#### 是什么

`micro` 是 isolated codegen / execution characterization harness，不是“真实 deployed app + daemon ReJIT”主路径。它比较的是 manifest 里定义的 runtime，例如 `llvmbpf` 和 `kernel`，并且明确拒绝 `policy_mode != stock` 的 runtime，见 `micro/driver.py:212-226`。

这点非常关键：当前三层 benchmark 中，只有 `corpus` 和 `e2e` 真正走 daemon apply ReJIT；`micro` 更接近“上界 characterization”。

#### 怎么跑

主调用链：

```text
make vm-micro
  -> runner.libs.run_target_suite:_run_action()
  -> kvm_executor.run_vm_suite()
  -> runner.suites.micro:_run_micro_suite()
  -> micro/driver.py:main()
  -> micro_exec(run-llvmbpf / test-run)
```

对应代码：

- `runner/suites/micro.py:71-148` 设置 runtime env、指定 runner binary 和 program dir，再调用 `micro/driver.py`。
- `micro/driver.py:335-370` 根据 runtime mode 生成 `micro_exec run-llvmbpf` 或 `micro_exec test-run` 命令。
- `micro/driver.py:540-676` 做 warmup、sample、runtime 交错顺序、统计汇总和 artifact 落盘。

#### 测什么

`micro` 测的是单个 micro target 的 compile / exec 时间与 perf counters，而不是 daemon apply 效果：

- `compile_ns`、`exec_ns`，见 `micro/driver.py:643-655`。
- 可选 `perf_counters` 和 `derived_metrics`，见 `micro/driver.py:653-655`。
- baseline subtraction / adjusted ratio，见 `micro/driver.py:245-308`。
- sample runtime order 也被记录，见 `micro/driver.py:588-597,631`。

manifest 里还定义了 baseline benchmark `simple` 用于 baseline adjustment，见 `micro/config/micro_pure_jit.yaml:26-27`。

### 2.2 corpus benchmark

#### 是什么

`corpus` 是“真实 app 常驻 + 统一 phase 测量”的 benchmark。它不是一个 app 一次起停，而是先把 suite 内所有 app 都启动起来，再在同一个 daemon session 下做 baseline -> rejit -> post_rejit，见 `corpus/driver.py:353-423`。

这是它和 `e2e` 最大的设计区别。

#### 怎么跑

主调用链：

```text
make vm-corpus
  -> runner.suites.corpus
  -> corpus/driver.py:run_suite()
     -> DaemonSession.start()
     -> 逐个 get_app_runner(...).start()
     -> run_lifecycle_sessions(...)
     -> 汇总每个 app 的 baseline/post_rejit/rejit_result
     -> ArtifactSession
```

关键代码：

- `runner/suites/corpus.py:67-81` 先启用 `kernel.bpf_stats_enabled=1`、校验 katran artifact、解析 daemon binary，再调用 `corpus/driver.py`。
- `corpus/driver.py:353-423` 为整个 corpus suite 开一个 daemon session，然后把所有 app start 起来，再统一进入 lifecycle。
- `corpus/driver.py:494-507` 组装最终 payload。

#### 测什么

每个 app 的 corpus 结果包含：

- `baseline.workloads[]`：每次 workload 的 `ops_total` / `ops_per_sec` / `duration_s` 等，来自 `WorkloadResult.to_dict()`，见 `runner/libs/workload.py:326-335` 和 `corpus/driver.py:131-165`。
- `baseline.bpf`：按 prog_id 计算的 `run_cnt_delta` / `run_time_ns_delta` / `avg_ns_per_run`，见 `runner/libs/bpf_stats.py:72-92`。
- `post_rejit`：同样的 measurement 结构。
- `rejit_result`：daemon apply 返回的 per-program 结果，见 `runner/libs/rejit.py:767-832`。

#### 当前有哪些 app

当前默认 `macro_apps` suite 在 `corpus/config/macro_apps.yaml:4-23`，共 19 个 app：

- BCC：`capable`、`execsnoop`、`bindsnoop`、`biosnoop`、`vfsstat`、`opensnoop`、`syscount`、`tcpconnect`、`tcplife`、`runqlat`
- Tetragon：`tetragon/default`
- Katran：`katran`
- Tracee：`tracee/default`
- bpftrace：`capable`、`biosnoop`、`vfsstat`、`runqlat`、`tcplife`、`tcpretrans`

值得注意的是：

- `runner/libs/benchmark_catalog.py:68-89` 仍保留了 `scx/rusty` 的 catalog 定义。
- 但默认 suite `corpus/config/macro_apps.yaml:4-23` 已经不再包含 `scx/rusty`。
- `corpus/driver.py:123-161,167-249` 仍保留了 SCX live prog id remap 特殊逻辑。

这说明 corpus framework 仍然“支持 SCX runner”，但当前默认 suite 已经把它移出了主路径。

### 2.3 e2e benchmark

#### 是什么

`e2e` 是 deployment-style case benchmark。它不是“把一组 app 同时常驻”，而是“按 case 逐个跑完整生命周期”，见 `e2e/driver.py:145-265` 和 `268-304`。

和 `corpus` 相比：

- `corpus`：多 app 同时启动，再统一 phase。
- `e2e`：一个 case 一次完整生命周期。

#### 怎么跑

主调用链：

```text
make vm-e2e
  -> runner.suites.e2e
  -> e2e/driver.py
     -> DaemonSession.start()
     -> case.run_<name>_case()
        -> run_case_lifecycle() 或 run_app_runner_lifecycle()
     -> ArtifactSession
```

代码定位：

- `runner/suites/e2e.py:35-40` 定义 case 参数，当前支持 `tracee|tetragon|bpftrace|bcc|katran|all`。
- `e2e/driver.py:66-92` 定义 `CASE_SPECS`。
- `e2e/driver.py:272-297` 的 `all` 模式只开一个 daemon session，然后在 case 之间调用 `wait_for_suite_quiescence()`。

#### 测什么

e2e 的 measurement 形式比 corpus 更 heterogeneous：

- `tracee`：每个 cycle 下每个 workload 都有 throughput + bpf delta，见 `e2e/cases/tracee/case.py:50-71,74-96,315-341`。
- `tetragon`：一个 lifecycle，baseline/post_rejit 各含一组 workload record，见 `e2e/cases/tetragon/case.py:60-101,236-243,272-286`。
- `bpftrace`：对每个 script 分别跑一个 lifecycle，再合并，见 `e2e/cases/bpftrace/case.py:59-117,138-179`。
- `bcc`：对每个 BCC tool 分别跑一个 lifecycle，再合并，见 `e2e/cases/bcc/case.py:38-98,121-172`。
- `katran`：一个 lifecycle，workload 可以是 `network` 或 `test_run`，见 `e2e/cases/katran/case.py:60-131` 和 `runner/libs/app_runners/katran.py:973-1007`。

#### 当前有哪些 app

当前 active e2e case 是 5 个：

- `tracee`
- `tetragon`
- `bpftrace`
- `bcc`
- `katran`

证据：

- `e2e/driver.py:98-100` parser choices 只有这 5 个。
- `e2e/driver.py:124` 的 `ALL_CASES` 也只有这 5 个。

这里有明显漂移：

- `README.md:7-10,23-24` 仍然宣称 `e2e/` 包含 `scx`。
- 但当前 `e2e/driver.py:66-92,98-100,124` 已经没有 `scx`。
- `e2e/cases/scx/` 目录当前只剩 `__pycache__`，没有源码文件。

## 3. Runner 层

### 3.1 AppRunner 基类设计

`AppRunner` 设计得很轻：

- 共享状态：`programs`、`artifacts`、`process_output`、`command_used`，见 `runner/libs/app_runners/base.py:8-14`。
- 抽象接口：`start()`、`run_workload()`、`run_workload_spec()`、`stop()`、`pid`，见 `runner/libs/app_runners/base.py:15-33`。
- `live_rejit_programs()` 默认返回当前 `self.programs`，见 `runner/libs/app_runners/base.py:39-40`。
- `_fail_start()` 负责 start 失败时 stop + 输出 tail，见 `runner/libs/app_runners/base.py:42-54`。

这是一个典型“最小 runner contract”设计：framework 不关心 app 具体怎么 attach，只要求它暴露 live programs 和 workload 接口。

runner 分发在 `runner/libs/app_runners/__init__.py:80-107`：

- `get_app_runner()` 根据 runner 名字动态 import 具体类。
- adapter 负责把 declarative app spec 映射为具体构造参数，比如 BCC 会从 tool name 解析成 `tool_binary + tool_args`，见 `runner/libs/app_runners/__init__.py:11-33`。

### 3.2 各 runner 的实现方式

#### TraceeRunner

- `runner/libs/app_runners/tracee.py:316-333` 负责 resolve binary、构造 command、启动 `TraceeAgentSession`、等待 program set 稳定。
- `runner/libs/app_runners/tracee.py:335-345` workload 通过 `run_tracee_workload()`。
- `runner/libs/app_runners/tracee.py:347-355` stop 时保存 stdout/stderr tail。

特点：

- 启动后额外 sleep 一个 startup settle 窗口，见 `runner/libs/app_runners/tracee.py:331-332`。
- 这是“长驻 agent + 外部 workload 驱动”模式。

#### TetragonRunner

- `runner/libs/app_runners/tetragon.py:176-197` 启动 binary，传入 tracing policy dir 和随机回环地址。
- 如果 setup 阶段解析出 `tetragon_bpf_lib_dir`，会显式传 `--bpf-lib`，见 `runner/libs/app_runners/tetragon.py:188-190`。
- `runner/libs/app_runners/tetragon.py:199-207` 用 `run_tetragon_workload()` 触发 workload。

特点：

- setup 信息由 adapter 提前准备好，runner 本身不负责探测 upstream artifact，见 `runner/libs/app_runners/__init__.py:64-71`。

#### BpftraceRunner

- `runner/libs/app_runners/bpftrace.py:137-179` 启动 `bpftrace -q script.bt`。
- attach 判定不是“看到任意新 program”，而是根据 script-specific `program_name_hints` 去匹配实际 attach 的 program name，见 `runner/libs/app_runners/bpftrace.py:127-135,168-175`。
- workload 通过 `run_named_workload()` 执行，见 `runner/libs/app_runners/bpftrace.py:181-207`。

特点：

- 这是 runner 层里比较干净的一类：脚本静态、attach program name 可推断、workload 也比较标准化。

#### BCCRunner

- `runner/libs/app_runners/bcc.py:371-428` 启动具体 BCC tool。
- 在 start 前会先准备 kernel source 和 Python compatibility layer，见 `runner/libs/app_runners/bcc.py:375-381`。
- compatibility layer 通过写临时 header 和 `sitecustomize.py` 修补 BCC 环境，见 `runner/libs/app_runners/bcc.py:326-339`。

特点：

- BCC runner 不是单纯起进程，它实际上承载了不少“发行版兼容层”逻辑。
- 这也是当前 runner 层里技术债最重的一类实现之一。

#### KatranRunner

- `runner/libs/app_runners/katran.py:920-971` 启动时会创建网络拓扑、可选 HTTP server、Katran gRPC server、map 配置和 `prog_test_run` 验证。
- `runner/libs/app_runners/katran.py:973-1007` workload 有两条路径：`test_run` 或真实 `network`。
- `runner/libs/app_runners/katran.py:1009-1030` stop 不只是杀进程，还要 teardown netns / XDP / topology 并等待 BPF teardown 完成。

特点：

- KatranRunner 已经不只是“runner”，而是一个完整的 testbed builder。
- 这是所有 runner 中最重、最基础设施化的一类。

#### ScxRunner

虽然当前 active suite 已不再引用 SCX case，但 runner 仍然保留：

- `runner/libs/app_runners/scx.py:371-377` 支持 `refresh_live_programs()`。
- `runner/libs/app_runners/scx.py:379-388` start 后返回 scheduler program ids。
- `runner/libs/app_runners/scx.py:390-402` workload 走 hackbench / stress-ng / sysbench 等。

其存在意义在于：SCX 程序的 live prog id 可能在运行中变化，所以 runner contract 专门暴露了“刷新 live program 集合”的能力。

### 3.3 runner 生命周期：start -> attach -> workload -> measure -> stop

Runner 层的通用生命周期实际上是：

```text
runner.start()
  -> attach 程序并发现 live prog_ids
  -> framework 用 prog_ids 建 CaseLifecycleState
  -> measure() 内部做:
       before = sample_bpf_stats(prog_ids)
       workload_result = runner.run_workload(...)
       after = sample_bpf_stats(prog_ids)
  -> daemon.apply_rejit(prog_ids)
  -> 再做一次 post_rejit measure()
  -> runner.stop()
```

对应到框架代码：

- `runner/libs/case_common.py:382-410` `run_app_runner_lifecycle()` 把 `AppRunner` 接到 lifecycle 框架里。
- `runner/libs/case_common.py:369-379` 默认会用 `runner.programs` 构造 `CaseLifecycleState`。
- `corpus/driver.py:97-165` 和各 e2e case 的 `measure_workload()` 负责把 `run_workload` 包上一层 bpf_stats delta。

## 4. Lifecycle 机制

### 4.1 三层抽象的职责边界

Lifecycle 相关代码集中在 `runner/libs/case_common.py`。

三层抽象分别是：

- `run_lifecycle_sessions()`：最低层，多 session phase engine，见 `runner/libs/case_common.py:188-299`。
- `run_case_lifecycle()`：把 `setup/start/workload/stop/cleanup` 适配成单 case lifecycle，见 `runner/libs/case_common.py:302-367`。
- `run_app_runner_lifecycle()`：把 `AppRunner` 进一步适配进来，见 `runner/libs/case_common.py:382-410`。

调用链如下：

```text
run_app_runner_lifecycle()
  -> run_case_lifecycle()
     -> setup()
     -> start() -> CaseLifecycleState
     -> run_lifecycle_sessions()
        -> baseline measure
        -> resolve live prog_ids
        -> daemon.apply_rejit()
        -> post_rejit measure
        -> stop()
     -> cleanup()
```

这三层的收益是：

- `e2e` case 可以写得非常薄。
- `corpus` 又可以直接跳过上层 adapter，直接使用 `run_lifecycle_sessions()` 跑多 session。

问题是：

- 错误处理逻辑也被拆在三层里，已经出现重复和语义重叠，后面第 8 节详细说。

### 4.2 baseline -> rejit -> post_rejit 的流程

`run_lifecycle_sessions()` 把三阶段写得非常直白：

- baseline：`runner/libs/case_common.py:242-260`
- refresh/resolve prog ids：`runner/libs/case_common.py:262-276`
- apply ReJIT：`runner/libs/case_common.py:278-285`
- post_rejit：`runner/libs/case_common.py:286-291`

更具体地说：

1. 可选 `refresh_sessions(..., "baseline")`
2. 对每个 session 调 `measure(..., "baseline")`
3. 可选 `refresh_sessions(..., "rejit")`
4. 用 `live_rejit_prog_ids()` 或 `resolve_rejit_prog_ids()` 拿 apply 目标 prog ids，见 `runner/libs/case_common.py:73-85,267-273`
5. `daemon_session.apply_rejit(prog_ids, enabled_passes=...)`
6. 再调一次 `measure(..., "post_rejit")`
7. finally 统一 stop 所有还没停掉的 session，见 `runner/libs/case_common.py:294-297`

### 4.3 daemon session 的管理

daemon session 的主路径是：

```text
DaemonSession.start()
  -> _start_daemon_server()
  -> prepare_daemon_session()
  -> run_lifecycle_sessions(... daemon_session=PreparedDaemonSession ...)
  -> DaemonSession.close()
```

代码定位：

- `runner/libs/rejit.py:847-857` `DaemonSession.start()` 启 daemon，并在需要时准备 kinsn metadata。
- `runner/libs/rejit.py:651-667` `_start_daemon_server()` 用 `serve --socket` 起 Unix socket server。
- `runner/libs/case_common.py:162-171` `prepare_daemon_session()` 会把 kinsn metadata deep-copy 一份，避免后续被 session 生命周期污染。

suite 对 daemon session 的粒度也不一样：

- `corpus`：整个 suite 共用一个 daemon session，见 `corpus/driver.py:353-354`。
- `e2e all`：整个 `all` 跑法共用一个 daemon session，case 之间用 `wait_for_suite_quiescence()` 隔离，见 `e2e/driver.py:272-297`。
- 单个 e2e case：一个 case 一个 daemon session，见 `e2e/driver.py:299-304`。

### 4.4 CaseLifecycleState 的作用

`CaseLifecycleState` 很简单，但非常关键：

- 定义在 `runner/libs/case_common.py:128-133`
- 字段只有：
  - `runtime: AppRunner`
  - `prog_ids: list[int]`
  - `artifacts: dict[str, object]`

它本质上是跨 phase 的 mutable state bag，承担 3 件事：

1. 保存当前 live prog ids。
2. 保存 runner object。
3. 保存 phase 之间需要传递的 artifacts，比如：
   - `programs`
   - `tracee_programs`
   - `rejit_policy_context`
   - SCX live remap 辅助信息

我对它的评价是：够用，但已经开始承担过多“弱类型胶水”的职责。

## 5. 测量系统

### 5.1 bpf_stats：怎么采集、delta 怎么算

`bpf_stats` 采集链路：

```text
bpftool_prog_show_records()
  -> sample_bpf_stats()
  -> _record_to_stats()
  -> compute_delta(before, after)
```

代码：

- `runner/libs/bpf_stats.py:14-15` 读 `bpftool` 记录。
- `runner/libs/bpf_stats.py:26-38` 提取 `run_cnt`、`run_time_ns`、`bytes_jited`、`bytes_xlated`，并算单点 `exec_ns`。
- `runner/libs/bpf_stats.py:66-69` 采样指定 prog_ids。
- `runner/libs/bpf_stats.py:72-92` 计算 delta。

delta 结果字段是：

- `run_cnt_delta`
- `run_time_ns_delta`
- `avg_ns_per_run`
- `bytes_jited`
- `bytes_xlated`

其中 `avg_ns_per_run = run_time_delta / run_cnt_delta`，只有 `run_cnt_delta > 0` 才有值，见 `runner/libs/bpf_stats.py:80-90`。

另外，真正把内核 `kernel.bpf_stats_enabled=1` 打开的不是 `enable_bpf_stats()`，而是 suite `_common`：

- `runner/libs/bpf_stats.py:9-11` 的 `enable_bpf_stats()` 实际上只是一个 no-op context manager。
- 真正做 sysctl 的是 `runner/suites/_common.py:171-190`。

这点后面会单独点名，因为 API 名字很误导。

### 5.2 throughput 测量方式

所有 workload 最终都返回 `WorkloadResult`：

- `runner/libs/workload.py:326-335` 定义 `ops_total`、`ops_per_sec`、`duration_s`、`stdout`、`stderr`
- `runner/libs/workload.py:385-400` 统一按 `ops_total / duration_s` 算 `ops_per_sec`

三层 benchmark 的 throughput 语义分别是：

- `micro`
  - 不用 `WorkloadResult`，直接吃 `micro_exec` 返回的 `compile_ns` / `exec_ns`，见 `micro/driver.py:373-392`。

- `corpus`
  - workload 结果通过 `runner.run_workload(...).to_dict()` 进入 `baseline.workloads[]` / `post_rejit.workloads[]`，见 `corpus/driver.py:131-165`。

- `e2e`
  - 各 case 自己决定字段名，但核心都是 `throughput` 或 `app_throughput` 加 `metric`：
    - `tracee`：`app_throughput`，见 `e2e/cases/tracee/case.py:64-71`
    - `tetragon`：`throughput`，见 `e2e/cases/tetragon/case.py:78-84`
    - `bpftrace` / `bcc` / `katran` 也都是 `throughput`，见 `e2e/cases/bpftrace/case.py:54-58`、`e2e/cases/bcc/case.py:33-37`、`e2e/cases/katran/case.py:37-45`

### 5.3 结果存储格式

结果落盘统一走 `ArtifactSession`，见 `runner/libs/run_artifacts.py:19-82`。

结果目录结构是：

```text
<suite>/results/<run_type>_<timestamp>/
  metadata.json
  details/
    progress.json
    result.json
    result.md            # corpus / e2e
    live_samples/*.json  # micro 可选
```

`metadata.json` 记录：

- `run_type`
- `status`
- `started_at`
- `last_updated_at`
- `completed_at`（如果完成）
- `error_message`（如果失败）
- `details_dir`

micro 的 progressive 落盘：

- `micro/driver.py:500-529` 创建 session 并持续写 `progress.json` / `result.json`
- `micro/driver.py:619-629` 可选写 `live_samples/*.json`

corpus / e2e 的落盘：

- `corpus/driver.py:563-600` 和 `e2e/driver.py:186-247`
- 都会把 Markdown 报告写成 `details/result.md`

## 6. 基础设施

### 6.1 KVM / VM 运行方式（virtme-ng）

KVM target contract 在 `runner/targets/x86-kvm.env:1-10`：

- executor = `kvm`
- backend = `vng`
- executable = `vng`
- 默认 benchmark VM 配置为 4 CPU / 32G 内存

本地运行 KVM suite 的主链路：

```text
run_target_suite._run_action()
  -> _run_local_prep()
  -> kvm_executor.run_vm_suite()
     -> write_guest_script()
     -> run_in_vm()
        -> guest 中启动 dockerd（若需要）
        -> 安装 runtime image tar
        -> docker run suite container
```

关键代码：

- `runner/libs/run_target_suite.py:172-179`
- `runner/libs/kvm_executor.py:90-103` 生成 guest shell command
- `runner/libs/kvm_executor.py:27-87` 的 `_docker_prelude_shell()` 会在 guest 中临时启动 dockerd
- `runner/libs/kvm_executor.py:112-139` 用 `run_in_vm()` 真正执行

local prep 产物由 `runner/libs/workspace_layout.py:109-120` 决定：

- runtime image tar
- daemon binary
- KVM kernel image

### 6.2 AWS 远端运行

AWS 路径比 KVM 重很多：

```text
run_target_suite._run_action()
  -> aws_executor._run_aws()
     -> _ensure_instance_for_suite()
        -> _launch_instance() / _setup_instance()
        -> _ensure_remote_runtime_image_loaded()
     -> _run_remote_suite()
        -> ssh + docker run suite container
        -> sync results back
     -> terminate instance
```

关键代码：

- `runner/libs/aws_executor.py:543-575` 确保 instance、runtime image、kernel/BTF/sched_ext 条件
- `runner/libs/aws_executor.py:648-686` 在远端跑 suite container 并同步 log/result
- `runner/libs/aws_executor.py:713-725` run 完后 terminate instance

AWS 还有一个独特步骤：内核安装不是在宿主机手工做，而是由 runtime image 作为 privileged installer container 执行，见 `runner/libs/aws_executor.py:379-438,441-485`。这和 `docs/benchmark-runtime-architecture.md:20-24,104-116` 的设计描述是一致的。

### 6.3 Makefile 入口

根 `Makefile` 是唯一公开入口，README 也明确这么写，见 `README.md:57-60`。

常用 benchmark 入口：

- `Makefile:98-105`：`vm-micro` / `vm-corpus` / `vm-e2e`
- `Makefile:113-129`：`aws-arm64-*` / `aws-x86-*`
- `Makefile:107-111`：`vm-all`

这些目标本质上只是 `python -m runner.libs.run_target_suite` 的薄壳，见 `Makefile:17,89-129`。

### 6.4 配置系统

配置系统有三层：

#### 1. target/suite contract

- `runner/targets/*.env`
- `runner/suites/*.env`
- 合并逻辑在 `runner/libs/run_contract.py:271-410`

这里会生成 `RunConfig`，字段包括：

- target identity
- executor
- suite requirements
- remote config
- AWS config
- KVM config

见 `runner/libs/run_contract.py:155-175` 和 `389-410`。

#### 2. suite args

`runner/libs/suite_args.py:57-94` 把 env 转成每个 suite 的 CLI 参数：

- micro：`--samples --warmups --inner-repeat --bench`
- corpus：`--samples`
- e2e：当前没有额外 suite arg
- test：`--test-mode` 等

#### 3. benchmark-specific config

- `corpus/config/benchmark_config.yaml:1-52` 定义 benchmark 默认 pass 和 profile。
- `runner/libs/rejit.py:144-163,345-360` 加载 profile，并生成 `benchmark_run_provenance()`。
- `runner/libs/app_suite_schema.py:96-154` 负责加载 corpus app suite YAML。

当前 schema v2 很“硬”：

- 只允许在 `apps[]` 里写名字
- 不允许 per-app override
- 见 `runner/libs/app_suite_schema.py:115-123`

这简化了默认 suite，但也让实验型 suite 定制能力偏弱。

## 7. Daemon 交互

### 7.1 daemon 是什么

`daemon/README.md:3-7` 对 daemon 的定义很清楚：

- 发现 live kernel BPF program
- 运行 rewrite pipeline
- 通过 `BPF_PROG_REJIT` 应用重写后的 bytecode

benchmark framework 并不直接调用 Rust 内部接口，而是只走 socket JSON protocol，见 `daemon/README.md:31-63`。

### 7.2 daemon session 怎么管理

session 生命周期：

```text
DaemonSession.start()
  -> fork bpfrejit-daemon serve --socket <tmp>/daemon.sock
  -> 等待 socket 文件出现
  -> benchmark 期间持有 stdout/stderr log 路径
  -> close() 时 terminate + 清理 socket_dir
```

代码：

- `runner/libs/rejit.py:651-667` `_start_daemon_server()`
- `runner/libs/rejit.py:675-678` `_stop_daemon_server()`
- `runner/libs/rejit.py:835-875` `DaemonSession`

`PreparedDaemonSession` 的作用是把“活着的 daemon session”与“需要一起落盘的 kinsn metadata”绑在一起，见 `runner/libs/case_common.py:135-171`。

### 7.3 ReJIT apply 流程

调用链如下：

```text
run_lifecycle_sessions()
  -> DaemonSession.apply_rejit(prog_ids)
     -> apply_daemon_rejit()
        -> _optimize_request(prog_id)
           -> _daemon_request(socket_path, {"cmd":"optimize","prog_id":...})
        -> _apply_result_from_response()
     -> 聚合 per_program / program_counts / error
```

关键代码：

- `runner/libs/case_common.py:279-285`
- `runner/libs/rejit.py:872-875`
- `runner/libs/rejit.py:767-832`
- `runner/libs/rejit.py:726-737`
- `runner/libs/rejit.py:691-723`
- `runner/libs/rejit.py:563-636`

如果启用了 `branch_flip`，apply 前还会做一次 profile-start / profile-stop，见 `runner/libs/rejit.py:740-764,792-810`。

### 7.4 一个重要事实：当前 runner 从未使用 optimize-all

daemon README 和项目背景文档都提到了 `optimize-all`：

- `daemon/README.md:53-57`
- `docs/kernel-jit-optimization-plan.md:167-169`

但 runner 侧实际只发 per-program `{"cmd":"optimize","prog_id":...}`：

- `runner/libs/rejit.py:726-737`
- `runner/libs/rejit.py:811-817`

这说明当前“协议能力”和“benchmark framework 实际使用路径”并没有完全对齐。

## 8. 当前问题和改进建议

下面按严重程度从高到低列问题。

### 8.1 文档和实现有明显漂移

#### 问题

至少有三处明显漂移：

1. README 仍写 `e2e` 包含 `scx`，但当前 driver 已经没有 `scx`
   - `README.md:7-10,23-24`
   - `e2e/driver.py:66-92,98-100,124`

2. runtime architecture 文档声称“不会把整个 host workspace mount 到 runtime image”
   - `docs/benchmark-runtime-architecture.md:128-140,166-167`
   - 但 `runner/libs/suite_commands.py:127-131` 实际上就是 `-v <host_workspace>:<image_workspace>`

3. daemon README 仍说 benchmark/e2e 默认 profile 是 `map_inline,const_prop,dce`
   - `daemon/README.md:89-97`
   - 但当前 `corpus/config/benchmark_config.yaml:1-27` 默认已经是更长的一组 pass

#### 建议

- 把 `README.md`、`docs/benchmark-runtime-architecture.md`、`daemon/README.md` 视为 active contract 文档，和代码一起维护。
- 增加一个轻量 CI check，校验：
  - `e2e/driver.py` 的 case list 与 README 一致
  - runtime mount 策略与 architecture doc 一致
  - daemon default pass 文档与 `benchmark_config.yaml` 一致

### 8.2 lifecycle 错误模型已经混合了三套语义

#### 问题

当前同时存在三套错误语义：

- `LifecycleAbort`，见 `runner/libs/case_common.py:141-146`
- `LifecycleRunResult.error/stop_error/fatal_error`，见 `runner/libs/case_common.py:148-159,204,292-299`
- `run_case_lifecycle()` 最后又把错误重新 raise 成 exception，见 `runner/libs/case_common.py:347-356`

这会导致：

- structured abort 信息很容易在上层被异常化后丢掉。
- 多 session 场景里，某个 session 的 ReJIT prog_id 解析失败会直接触发 suite 级 `fatal_error`，而不是该 session 的局部错误；最明显的点在 `runner/libs/case_common.py:264-285`，其中 `line 274` 直接 `raise RuntimeError(...)`。

#### 建议

- 统一成单一结果模型：`status = ok | abort | error`，不要再混 `abort + error string + fatal_error + raise` 四种出口。
- `run_case_lifecycle()` 应该返回结构化结果，不应把 lifecycle 错误重新异常化；异常只保留给 truly unexpected failure。
- `run_lifecycle_sessions()` 对每个 session 的 ReJIT prog_id 解析失败应局部记录，不应提升成整个 suite 的 fatal。

### 8.3 corpus 的多 app 常驻模型依赖全局 program table diff，归属推断偏脆弱

#### 问题

`corpus` 的核心设计是：

- 先把所有 app 起起来，见 `corpus/driver.py:366-382`
- 再统一做 baseline/rejit/post_rejit，见 `corpus/driver.py:408-423`

为了刷新每个 session 当前属于自己的 live programs，代码使用：

- `programs_after(session.before_prog_ids, records=current_programs)` 取差集
- 再按 reversed session 顺序做 claimed_id 排除
- 见 `corpus/driver.py:279-289`

这个机制的问题是：

- 它假设“全局 program table + 启动前 baseline ids + 反向排除”足以恢复每个 app 的 program ownership。
- 一旦 app 自己会卸载/重载程序，或者两个 app attach 的 program name / attach 时机交叠，这种启发式就会很脆。

#### 建议

- 优先让 runner 自己暴露 authoritative live program refresh contract，而不是依赖全局 diff。
- 至少把 `_refresh_active_session_programs()` 的归属规则单独抽成一个策略接口，方便特殊 runner 覆盖。
- 增加一个 serial corpus mode，便于区分“真实并发干扰”与“框架归属推断误差”。

### 8.4 `enable_bpf_stats()` API 命名误导

#### 问题

- `runner/libs/bpf_stats.py:9-11` 的 `enable_bpf_stats()` 实际不做任何 enable，只是 `yield {"mode":"bpftool"}`。
- 真正的 sysctl enable 在 `runner/suites/_common.py:171-190`。

这会导致阅读者直觉上以为：

- driver 进入 `with enable_bpf_stats():` 就真的打开了 stats

但实际不是。

#### 建议

- 要么把 `enable_bpf_stats()` 改成真正的 stateful helper。
- 要么改名为 `bpf_stats_collection_mode()` / `bpf_stats_context()`，避免误导。

### 8.5 daemon 协议支持 `optimize-all`，但 benchmark framework 全部按 prog_id 单发 optimize

#### 问题

- 协议支持 `optimize-all`，见 `daemon/README.md:53-57`
- 但 runner 只用 `_optimize_request()` 单发每个 `prog_id`，见 `runner/libs/rejit.py:726-737,811-817`

这带来两个问题：

- 文档和实现不一致。
- 多 program app 的 apply round-trip 偏多，尤其是 corpus 多 app 同时常驻时。

#### 建议

- 如果 benchmark framework 不需要 `optimize-all`，就删掉文档和架构层对它的强调。
- 如果需要，就在 `apply_daemon_rejit()` 增加 batch path，至少对 corpus 多 program case 做一次 request。

### 8.6 micro 层和 ReJIT 主线语义不对称，容易被误读

#### 问题

- `README.md:5-11` 把 `micro/corpus/e2e` 并列成三层 pipeline。
- 但 `micro/driver.py:212-226` 明确拒绝非 `stock` runtime。
- 也就是说，micro 当前不是 baseline vs rejit 的同构层，而是 llvmbpf vs kernel 的 characterization harness。

#### 建议

- 在 README 和 benchmark 文档里明确写：`micro` 是 characterization layer，不是 daemon-driven ReJIT benchmark。
- 如果论文需要“全三层都能讲同一套 baseline/rejit story”，那就另起一个真正的 micro ReJIT suite，而不是复用当前 harness。

### 8.7 结果 schema 在三层之间不统一

#### 问题

三层结果格式差异很大：

- `micro`：`benchmarks[].runs[].samples[] + compile_ns/exec_ns/perf_counters`，见 `micro/driver.py:433-468,643-660`
- `corpus`：`results[].baseline/post_rejit/rejit_result`，见 `corpus/driver.py:299-328,494-507`
- `e2e`：每个 case 自己定义 payload 形状，比如：
  - `bpftrace`：`records[]`，见 `e2e/cases/bpftrace/case.py:111-117,168-179`
  - `katran`：平铺的 `baseline/post_rejit/process`，见 `e2e/cases/katran/case.py:116-130`
  - `tracee`：`baseline[]/post_rejit[]/rejit_result{cycle}`，见 `e2e/cases/tracee/case.py:355-371`

这对后处理、可视化和 cross-suite report 都不友好。

#### 建议

- 定义一个统一 schema：
  - `run_metadata`
  - `subject`
  - `phases.baseline`
  - `phases.post_rejit`
  - `apply`
  - `artifacts`
- 各 suite/case 只在 `measurement` 内部保留个性化字段，不要再改变顶层结构。

### 8.8 runner / catalog / suite wiring 存在“半退役状态”

#### 问题

当前有一些“支持仍在、但主路径已不再引用”的残留：

- `runner/libs/app_runners/__init__.py:84` 仍支持 `scx`
- `runner/libs/benchmark_catalog.py:79` 仍定义 `scx/rusty`
- `corpus/driver.py:123-161` 仍保留 SCX 特殊测量逻辑
- 但默认 corpus suite `corpus/config/macro_apps.yaml:4-23` 已不包含 `scx`
- 当前 e2e 也已不包含 `scx`，见 `e2e/driver.py:98-100,124`

#### 建议

- 如果 SCX 只是暂时移出主路径，就把这个状态写清楚，并保持 case/source 完整。
- 如果已经决定退出 active benchmark path，就应把 README 文案和多余专用逻辑一起收敛，避免读代码的人误以为它仍在主线 benchmark 里。

## 总体评价

这个 benchmark framework 的核心结构是成立的，特别是：

- 入口统一
- executor 与 suite 解耦
- runner contract 简洁
- lifecycle 和 daemon apply 复用度高
- artifact progressive write 做得比较工程化

但当前最大的问题不是“功能缺失”，而是“主路径已经演化，而文档、抽象边界和部分遗留支持没有同步收口”。如果只做一轮整顿，我建议优先做三件事：

1. 统一文档与 active path，先消灭 README / architecture / daemon README 的漂移。
2. 收敛 lifecycle 错误模型，避免 `abort + error + fatal + raise` 四套并存。
3. 明确哪些 runner / case / app suite 仍在 active benchmark story，哪些已经退到 latent support。

做到这三点以后，这套 framework 的可读性、可维护性和论文叙事一致性都会明显提高。
