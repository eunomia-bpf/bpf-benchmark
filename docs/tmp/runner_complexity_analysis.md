# Runner/libs 复杂度本质分析

生成时间：2026-04-11

---

## 一、文件清单及逐文件定性

| 行数 | 文件 | 本质在做什么 |
|------|------|------------|
| 1158 | `app_runners/katran.py` | 用 Python 手动搭建一套虚拟网络拓扑（4 个 network namespace + veth pair + ARP + IP routing），然后用 raw socket 发包，测量 XDP LB 吞吐 |
| 1126 | `case_common.py` | E2E 测试的"粘合胶水"：BPF 程序变更检测、CPU 采样线程、quiescence 等待、kinsn metadata 合并，把 4 种 app runner 的行为统一 |
| 1016 | `workload.py` | 把 stress-ng/hackbench/wrk/dd/fio 等 6+ 种工具的调用封装成统一的 `WorkloadResult`，并实现一个内嵌 HTTP server 用于 tracee 健康检查 |
| 919 | `input_generators.py` | 为 micro benchmark 生成 5 种不同数据分布的二进制输入文件（用 Python 实现 LCG 随机数和手写 struct pack） |
| 899 | `rejit.py` | 封装 BpfReJIT daemon 的 socket 通信、scan/apply 调用、policy 规则匹配，以及从 YAML 文件读取优化策略 |
| 755 | `reporting.py` | 计算 micro/corpus benchmark 的统计指标（geomean、bootstrap CI、wins）并格式化成人类可读报告 |
| 701 | `run_contract.py` | 从 target/suite YAML 配置文件中读取参数，构造 manifest.env 文件，声明一次 benchmark run 所需的所有远端依赖 |
| 700 | `aws_executor.py` | 管理 AWS EC2 实例的生命周期（查找已有实例 / 按 AMI 启动 / 等待 SSH 可用 / rsync 传文件 / SSH 执行 / 取回结果 / 终止实例） |
| 685 | `suite_entrypoint.py` | 在 guest（VM 内或远端机器）上执行 suite：加载 container image、拼接 docker run 参数、执行 prereq 检查、调用具体的 suite driver |
| 608 | `app_runners/tracee.py` | 启动 Tracee，监听其 JSON 事件流，解析事件统计，运行各种 workload，等待输出稳定，收集 BPF stats |
| 474 | `app_runners/tetragon.py` | 与 tracee.py 结构几乎一致：启动 Tetragon，等待 BPF 程序 attach，运行 workload，采集 BPF stats |
| 402 | `app_runners/scx.py` | 启动 sched_ext scheduler，等待 `/sys/kernel/sched_ext/state` 变 enabled，运行 hackbench/sysbench，解析输出 |
| 349 | `app_runners/bcc.py` | 启动 bcc 工具（libbpf-tools），等待健康，运行 workload，停止，收集 BPF stats |
| 328 | `aws_common.py` | AWS executor 的上下文数据结构 + 公用的 `aws ec2 describe-instances` 调用封装 |
| 325 | `aws_remote_host.py` | 在远端 AWS 主机上执行的辅助命令（prepare_dir / uname / volume_size / install_kernel 等），通过 SSH 间接调用 |
| 318 | `app_runners/process_support.py` | subprocess 输出消费线程（ProcessOutputCollector）+ AgentSession 基类（start/stop/health check 通用逻辑） |
| 278 | `run_artifacts.py` | 把 benchmark 结果写成结构化目录（`<run_type>_<timestamp>/metadata.json + details/`），并对大型 benchmark payloads 做摘要裁剪 |
| 266 | `run_target_suite.py` | 顶层入口：生成 run token，调用 local_prep，分发到 aws_executor 或 kvm_executor |
| 238 | `results.py` | 定义 `RunnerSample`/`RejitSummary` 等 TypedDict 数据结构，解析 runner 的 JSON stdout 输出 |
| 235 | `guest_prereqs.py` | 在 guest 上验证或确保所需命令（docker/bpftool/Python 包等）存在 |
| 217 | `kinsn.py` | insmod .ko 文件，检查 lsmod，等待 daemon 输出 kinsn discovery 日志 |
| 209 | `__init__.py` | 公用工具函数：`run_command`、`write_json`、`resolve_bpftool_binary` 等基础设施 |
| 209 | `app_runners/bpftrace.py` | 启动 bpftrace 脚本，等待健康，运行 workload，解析 probe 统计，收集 BPF stats |
| 195 | `statistics.py` | 统计工具函数：geomean、ns_summary、bootstrap CI、perf counter 摘要 |
| 182 | `app_suite_schema.py` | 解析 `macro_apps.yaml`，加载 AppSpec 列表，支持按名称/runner/workload 过滤 |
| 172 | `vm.py` | 调用 virtme-ng 启动 KVM，生成 guest shell 脚本，用 `script` 命令捕获 PTY 输出 |
| 165 | `workspace_layout.py` | 统一管理所有二进制/artifact 的路径（x86 vs arm64 分支），计算需要 rsync 的文件列表 |
| 149 | `agent.py` | 启动 / 停止 / health-check BPF agent 进程，通过 /proc/fdinfo 找到其持有的 BPF 程序 fd |
| 131 | `metrics.py` | 采样 /proc/stat 和 /proc/<pid>/stat CPU 使用率，计算 BPF stats delta |
| 124 | `app_runners/__init__.py` | 将 AppSpec + workload 字符串适配为各 runner 的构造参数（bcc/bpftrace/scx/tracee/tetragon/katran） |
| 121 | `manifest_file.py` | 解析 KEY=VALUE 格式的 .env manifest 文件，支持 bash 数组语法 |
| 109 | `app_runners/base.py` | AppRunner 抽象基类：`start/stop/run_workload` 接口，`select_corpus_program_ids` 默认实现 |
| 101 | `state_file.py` | 读写 JSON 格式的运行状态文件（记录 EC2 instance ID / IP 等） |
| 87 | `bpf_stats.py` | 用 bpftool prog show 读取 BPF 程序 run_cnt / run_time_ns 统计 |
| 85 | `app_runners/setup_support.py` | 验证 ELF 架构匹配，解析 `BPFREJIT_REPO_ARTIFACT_ROOT` 路径 |
| 76 | `environment.py` | 读取 /proc/cpuinfo 等系统信息，验证 benchmark 发表环境（governor / turbo 等） |
| 73 | `prereq_contract.py` | 从 manifest 中提取"需要哪些命令"的逻辑，处理 runtime container 与裸机的差异 |
| 73 | `kvm_executor.py` | KVM executor 入口：拼接 guest 命令行，调用 vm.py 的 `run_in_vm` |
| 45 | `benchmarks.py` | 根据名称筛选 benchmark，调用 `materialize_input` 准备输入文件 |
| 40 | `kernel_modules.py` | 用 modprobe -d 从 repo 目录加载内核模块 |
| 28 | `process_fd.py` | 用 pidfd_getfd syscall 从另一个进程 dup 出 BPF prog 的 fd |
| 24 | `cli_support.py` | 打印 `[TAG][ERROR]` 并 SystemExit |

**合计：14,395 行，44 个文件（含 app_runners/ 子目录）**

---

## 二、系统本质功能（3 句话）

1. **在若干目标机器（本地 KVM VM / 远端 AWS 实例）上运行 BPF 程序**，以测量 BpfReJIT 优化前后的执行时间差异。
2. **每次 run** 的核心操作是：把必要的二进制文件传到目标机、启动目标应用（tracee/katran/bpftrace 等）、施加标准化负载、收集 BPF 程序运行时间统计、把结果写回 JSON 文件。
3. **横向支撑**包括：将 benchmark 参数化（target × suite × workload 的笛卡尔积）、管理 AWS EC2 实例生命周期、以及对结果做统计汇总（geomean、bootstrap CI）。

---

## 三、复杂度分类

### 核心复杂度（问题本身固有，无法消除）

这是 benchmark 系统的"物理约束"带来的。

| 功能域 | 说明 | 估计行数（如从零写）|
|--------|------|-----|
| Katran 网络拓扑搭建 | XDP LB 测试必须有真实的 veth/namespace 拓扑 | ~300 |
| 各 app runner 的启停逻辑 | 6 个不同应用各有不同的健康检查信号 | ~400 |
| rejit.py daemon 通信 | 通过 UNIX socket 与 daemon 交互，解析优化结果 | ~200 |
| input_generators.py | micro benchmark 需要确定性输入数据 | ~150（可用 C 重写为工具） |
| AWS EC2 生命周期 | ssh + rsync + aws CLI 的基本操作 | ~200 |
| KVM 启动 | virtme-ng 调用 + PTY 捕获 | ~80 |
| BPF stats 采集 | /proc/fdinfo + bpftool 读 run_cnt | ~80 |
| 统计计算 | geomean、bootstrap CI | ~100 |
| 结果 JSON 输出 | 结构化存储 | ~80 |

**核心复杂度合计：约 1,600 行**

### 偶然复杂度（设计选择带来的，可以消除）

| 类别 | 代表文件 | 描述 | 估计浪费行数 |
|------|---------|------|------------|
| **manifest.env 协议层** | `manifest_file.py`（121）、`run_contract.py`（701）、`prereq_contract.py`（73）、`state_file.py`（101） | 用 Python 解析 shell `KEY=VALUE` 文件、在 Python 和 shell 之间来回转换，本来 make 直接传变量就够 | ~800 |
| **工件传输抽象** | `workspace_layout.py`（165）、`run_artifacts.py`（278）、`aws_remote_host.py`（325）部分 | 用 Python 管理"哪些文件需要 rsync"，实际是 Makefile 的 rsync 目标能做的事 | ~500 |
| **Container 层级** | `guest_prereqs.py`（235）、`suite_entrypoint.py`（685） | Python 代码动态拼接 `docker run` 命令行，并判断"当前是否在 container 里"——这是 Makefile 目标直接调用就能解决的 | ~600 |
| **进程输出收集框架** | `app_runners/process_support.py`（318）、`agent.py`（149）部分 | 手写 threading + deque 的 stdout/stderr 消费框架，标准库 `subprocess` + `asyncio.create_subprocess_exec` 或简单 shell 管道可替代 | ~250 |
| **AppRunner 继承体系** | `app_runners/base.py`（109）、`app_runners/__init__.py`（124）、`app_suite_schema.py`（182） | 用 ABC + TypedDict + YAML schema 实现了一套"插件注册"机制，而所有 runner 的 `start/stop/run_workload` 差异可以用 3 个 shell 函数表达 | ~350 |
| **case_common.py 胶水层** | `case_common.py`（1126） | 把 4 个 app runner 的公共行为（quiescence、metadata merge、CPU sampler）抽象为共享库，但这些逻辑本质上是每个 runner 里几行 sleep + bpftool 调用 | ~700 |
| **workload.py 封装** | `workload.py`（1016） | 用 Python 封装 6 种工具的调用（其中 HTTP server 是真的必要的约 100 行，其余是重复的 subprocess 模板） | ~700 |
| **reporting.py 重复** | `reporting.py`（755） | bootstrap CI + geomean + 格式化表格，2/3 的代码在 `statistics.py` 里已有基础实现，此处大量重复聚合逻辑 | ~400 |
| **aws_common.py 分拆** | `aws_common.py`（328）+ `aws_executor.py`（700） | context dataclass + 大量 `_require`/`_optional` helper 包装，可以直接用字典 + 2 个函数搞定 | ~400 |

**偶然复杂度合计：约 4,700 行**（占总量 33%）

剩余约 8,000 行是"必要但可简化"的——代码做对了事，但用了比需要多 2-3 倍的代码量来做。

### 总结量化

| 类型 | 行数 | 占比 |
|------|------|------|
| 核心复杂度（不可消除） | ~1,600 | 11% |
| 偶然复杂度（可完全消除） | ~4,700 | 33% |
| 必要但过度工程化（可简化） | ~8,100 | 56% |
| **总计** | **14,395** | **100%** |

---

## 四、偶然复杂度根因

### 根因 1：用错了工具（最严重）

**manifest.env 协议**是整个系统最核心的设计错误。系统用 Python 手写了一个 shell variable 解析器（`manifest_file.py`），然后把 Makefile 变量序列化成文件，再在远端 Python 里反序列化。这是一个完整的"自制配置协议"，实际上 Makefile 直接 `$(MAKE) -C $(REMOTE) VAR1=$(VAR1) VAR2=$(VAR2)` 或用 `env` 传递就够了。

**证据：`run_contract.py` 701 行**，几乎全部是把 YAML target 配置转换成 manifest.env 格式，涉及 10+ 个 `render_shell_assignments` / `parse_manifest` 调用层次。

### 根因 2：过度抽象（AppRunner 体系）

AppRunner ABC + 6 个子类，只是为了统一 `start/stop/run_workload` 接口。但实际上这 6 个应用的差异性极大（katran 需要 network namespace，tracee 需要 event parsing，scx 需要 sysfs polling），共享接口带来的"一致性"几乎没有被使用——调用方（corpus/e2e driver）最终还是 `isinstance` 判断或传递 workload_spec 字典绕过抽象。

这导致了 `app_runners/__init__.py` 里的"适配器适配器"（把 AppSpec.args 转成各 runner 的 kwargs），以及 `case_common.py` 里 1126 行的"公共基础设施"。

### 根因 3：应该用 shell 的地方用了 Python

- `guest_prereqs.py`（235 行）：检查命令是否存在 → `command -v foo || die "missing foo"` 一行 shell
- `suite_entrypoint.py`（685 行）：拼接 `docker run` 参数 → 一个 30 行的 shell 函数
- `kvm_executor.py`（73 行）+ `vm.py`（172 行）：调用 virtme-ng → 直接 make 目标
- `aws_remote_host.py`（325 行）：在远端执行 mkdir/chown/uname → 直接 `ssh host "sudo mkdir -p $dir"`

这些模块把"执行 shell 命令"这件事包装成了 Python 类和函数，反而比直接写 shell 多出 5-10 倍代码。

### 根因 4：重复实现（fragmentation）

- `bpf_stats.py`（87）、`metrics.py`（131）、`case_common.py` 中都有"读取 BPF stats"的代码片段
- `state_file.py`（101）和 `manifest_file.py`（121）都是"读写 KEY=VALUE 文件"，格式略有不同但功能高度重叠
- `aws_common.py`（328）和 `aws_executor.py`（700）的边界模糊，`_aws_cmd` / `_describe_instance` 在两个文件里各有一份

---

## 五、从零设计：最小架构草图

### 核心洞见

这个系统的本质是：**给定一组（target, suite）对，在目标机器上执行 shell 脚本，收集 JSON 结果**。

这是 CI 系统 + rsync + ssh 的组合，不需要 14,000 行 Python。

### 理想架构（估计行数）

```
bpf-benchmark/
├── Makefile                    # 200行：所有 run/build/report 入口
├── runner/
│   ├── targets/                # YAML：target 定义（x86-kvm, aws-arm64 等）
│   ├── suites/                 # YAML：suite 定义（micro, corpus, e2e）
│   ├── run.sh                  # 200行：核心 run 脚本（rsync + ssh + 收结果）
│   ├── aws.sh                  # 150行：EC2 生命周期（launch/wait/terminate）
│   └── kvm.sh                  # 80行：virtme-ng 调用
├── drivers/
│   ├── micro_driver.py         # 300行：micro benchmark 驱动（已存在）
│   ├── corpus_driver.py        # 400行：corpus benchmark 驱动
│   └── e2e_driver.py           # 400行：e2e benchmark 驱动
├── app_runners/
│   ├── tracee.py               # 250行：仅保留 start/stop/parse_events
│   ├── tetragon.py             # 200行：仅保留 start/stop
│   ├── katran.py               # 400行（网络拓扑是真实复杂度，无法压缩太多）
│   ├── scx.py                  # 150行
│   └── bcc_bpftrace.py         # 150行（合并，因为逻辑几乎一样）
├── lib/
│   ├── rejit.py                # 200行：daemon 通信
│   ├── bpf_stats.py            # 60行：bpftool stats
│   └── statistics.py           # 120行：geomean + bootstrap CI
└── input_generators/
    └── gen_inputs               # 100行 C 程序，替代 Python LCG
```

**总估计：约 3,200 行 Python + 500 行 shell + 100 行 C ≈ 3,800 行**

相比现有 14,395 行，减少约 **73%**。

### 关键改变

1. **manifest.env 协议完全删除**：target 配置用 YAML，运行时参数用环境变量直传，无需序列化/反序列化层
2. **AppRunner ABC 删除**：每个 app runner 只是一个 Python 模块，暴露 `start(config) → pid`、`stop(pid)`、`parse_results(output) → dict` 三个函数，不需要继承
3. **suite_entrypoint.py + guest_prereqs.py 合并为 run.sh**：用 bash 检查命令、docker load、执行 driver
4. **case_common.py 拆解**：把真正共用的（quiescence、CPU sampler）各 20 行，移入各 driver 的开头；不再有"公共 E2E 基础设施"
5. **workload.py 简化**：只保留 `run_workload(cmd, duration) → (ops, elapsed)` 一个函数，6 种工具的参数差异在 YAML 里声明，不在 Python 里 if/else
6. **input_generators.py 替换为 C 工具**：LCG 生成二进制文件，用一个 100 行 C 程序（`gen_inputs.c`）替代 919 行 Python，并且更快

### 哪些文件可以完全用 shell/Makefile/配置替代

| 现有文件（行数）| 替代方案 |
|----------------|---------|
| `manifest_file.py`（121）| 删除，改用 `make VAR=val` 直传 |
| `run_contract.py`（701）| 删除，target 参数直接在 YAML + Makefile 里声明 |
| `prereq_contract.py`（73）| 10 行 shell：`command -v foo || die "missing"` |
| `guest_prereqs.py`（235）| 30 行 shell 脚本 |
| `suite_entrypoint.py`（685）| 50 行 shell 脚本（docker run 封装） |
| `kvm_executor.py`（73）| 并入 `kvm.sh` 的 5 行 |
| `aws_remote_host.py`（325）| 20 行 ssh 调用（`ssh host "sudo mkdir $dir"` 等） |
| `state_file.py`（101）| 变量直接写 `.env` 文件，一行 shell 读取 |
| `workspace_layout.py`（165）| Makefile 变量定义，路径通过 make 展开 |
| `cli_support.py`（24）| `die() { echo "[ERROR] $1"; exit 1; }` |
| `environment.py`（76）| shell 里 `cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor` |

合计可以用 shell/Makefile 替代的：**~2,579 行 Python**

---

## 六、结论

这个 runner 系统的根本问题是：**把 Makefile + shell 的工作用 Python 做了**，然后为了让 Python 代码"有结构"，又叠加了一层 OOP 抽象，形成"抽象的抽象"。

最深层的设计失误是 **manifest.env 协议**——一个 Python 自制的 shell 变量序列化器，把本来 make/shell 天然支持的参数传递变成了 700 行的"配置层"。这一个决策级联出了 `run_contract.py`、`manifest_file.py`、`prereq_contract.py`、`state_file.py`、`suite_entrypoint.py`、`guest_prereqs.py` 共约 1,900 行代码，全部是围绕这一协议的"适配器"。

真正需要 Python 做的事情只有：驱动 benchmark（运行/计时/收集）、统计分析、rejit daemon 通信。这些合计约 1,600 行核心 + 1,600 行必要实现 = 3,200 行。当前 14,395 行中有超过 **11,000 行是可以通过重新设计来消除的**。
