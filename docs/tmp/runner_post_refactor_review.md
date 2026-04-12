# Runner 重构后状态审查

**日期**: 2026-04-11
**审查范围**: runner/libs/ + runner/suites/
**总行数**: libs ~11,324 行 + suites ~1,415 行（Python）= 12,739 行

---

## 1. 整体行数概览

### runner/libs/（按行数降序）

| 文件 | 行数 | 一句话描述 | 必要行 | 可削减 |
|------|------|-----------|--------|--------|
| app_runners/katran.py | 784 | Katran XDP 负载均衡器的完整运行器（网络拓扑、多进程管理、BPF map 操作） | ~550 | ~230 |
| rejit.py | 752 | daemon 会话管理、ReJIT 策略解析、benchmark 配置加载 | ~500 | ~250 |
| case_common.py | 749 | corpus/e2e 应用运行的公共流程（quiescence 等待、BPF stats、kinsn 元数据） | ~550 | ~200 |
| workload.py | 705 | 工作负载生成器（HTTP、IO storm、scheduler、exec、network load 等）| ~550 | ~150 |
| input_generators.py | 699 | micro benchmark 输入数据生成（纯计算，LCG 变体，20+ 生成器函数） | ~550 | ~150 |
| run_contract.py | 617 | 运行配置构建（target.env + suite.env → RunConfig dataclass） | ~450 | ~167 |
| reporting.py | 593 | micro 结果统计报告（geomean、CI、group、perf counter 等） | ~500 | ~93 |
| app_runners/tracee.py | 524 | Tracee 安全监控工具的完整运行器（事件收集、health check、多工作负载） | ~420 | ~104 |
| aws_executor.py | 506 | AWS EC2 实例生命周期管理（launch/wait/ssh/terminate） | ~420 | ~86 |
| aws_remote_host.py | 406 | 在远端 AWS 机器上运行的远程辅助脚本（单机自包含） | ~350 | ~56 |
| app_runners/scx.py | 373 | sched_ext 调度器的运行器（hackbench/sysbench/stress-ng 工作负载） | ~300 | ~73 |
| app_runners/bcc.py | 340 | BCC libbpf-tools 工具集运行器（10 个工具、工作负载配置） | ~280 | ~60 |
| app_runners/process_support.py | 315 | 进程会话管理（AgentSession、ManagedProcessSession、程序等待） | ~250 | ~65 |
| run_artifacts.py | 278 | 运行结果 artifact 目录管理与 JSON 写入 | ~230 | ~48 |
| run_target_suite.py | 276 | 高层入口：构建 RunConfig → 本地 prep → aws/kvm 执行 | ~220 | ~56 |
| app_runners/tetragon.py | 269 | Tetragon 安全可观测性工具运行器 | ~220 | ~49 |
| kvm_executor.py | 257 | KVM VM 内部 guest 脚本生成与执行 | ~200 | ~57 |
| kinsn.py | 217 | kinsn 内核模块加载、发现、daemon kinsn 元数据捕获 | ~180 | ~37 |
| results.py | 208 | micro 测试结果数据结构与 JSON 序列化 | ~180 | ~28 |
| aws_common.py | 207 | AWS CLI 调用的公共辅助函数 | ~170 | ~37 |
| app_runners/bpftrace.py | 207 | bpftrace 运行器 | ~170 | ~37 |
| __init__.py | 191 | 公共工具函数（ROOT_DIR、run_command、tail_text 等） | ~160 | ~31 |
| suite_args.py | 185 | 从环境变量构建 suite argv（micro/corpus/e2e/test 四路分支） | ~150 | ~35 |
| statistics.py | 182 | 统计计算（geomean、bootstrap CI） | ~150 | ~32 |
| workspace_layout.py | 174 | 路径解析（artifact/cache 目录、transfer roots） | ~160 | ~14 |
| app_suite_schema.py | 174 | macro_apps.yaml YAML schema（AppSpec、AppSuite） | ~150 | ~24 |
| vm.py | 165 | KVM VM 启动、guest 脚本执行 | ~130 | ~35 |
| agent.py | 149 | bpfrejit-daemon agent 启动/停止/健康检查 | ~120 | ~29 |
| bpf_stats.py | 123 | BPF stats 采样（per-program 运行时统计） | ~100 | ~23 |
| metrics.py | 96 | CPU 使用率采样、delta 计算 | ~80 | ~16 |
| state_file.py | 91 | 运行状态 JSON 文件读写 | ~75 | ~16 |
| app_runners/setup_support.py | 85 | app runner 内部路径解析辅助（repo_artifact_root 等） | ~70 | ~15 |
| environment.py | 76 | 环境信息采集（CPU 拓扑、内核版本等） | ~65 | ~11 |
| benchmarks.py | 45 | micro benchmark 数据结构 | ~40 | ~5 |
| kernel_modules.py | 40 | 内核模块加载（insmod/modprobe 封装） | ~35 | ~5 |
| process_fd.py | 28 | 跨进程 fd dup（用于 Tracee/SCX 输出捕获） | ~25 | ~3 |
| cli_support.py | 24 | fail() 辅助函数 | ~20 | ~4 |
| app_runners/__init__.py | 115 | app runner 工厂函数 | ~90 | ~25 |
| app_runners/base.py | 99 | AppRunner 抽象基类 | ~85 | ~14 |

### runner/suites/（新创建文件）

| 文件 | 行数 | 说明 |
|------|------|------|
| _common.py | 290 | 四个 suite 共享的辅助函数 |
| test.py | 426 | test suite 独立入口 |
| micro.py | 240 | micro suite 独立入口 |
| corpus.py | 236 | corpus suite 独立入口 |
| e2e.py | 222 | e2e suite 独立入口 |
| *.env | 45 | 四个 suite 的配置文件 |

---

## 2. 为什么还有这么多行？

### 2.1 行数膨胀的真实原因

**原因 1：应用运行器本身复杂（必要的复杂度）**
- katran.py（784 行）：涉及网络 namespace 创建、XDP 附加、BPF map 初始化、TCP 健康检查，这些是 Katran 测试本身的复杂性，不是代码写法问题
- tracee.py（524 行）：多线程输出收集（TraceeOutputCollector）、事件解析、health check、6 种工作负载支持
- scx.py（373 行）：3 种基准工具（hackbench/sysbench/stress-ng）+ sched_ext 状态监控

**原因 2：rejit.py 和 case_common.py 承载核心业务逻辑（必要的复杂度）**
- rejit.py：daemon 会话生命周期 + ReJIT 策略 YAML 解析 + benchmark 配置合并逻辑，本质上是 v2 架构的核心 Python 接口
- case_common.py：quiescence 检测 + BPF stats 采样 + kinsn 元数据管理，这些是测量精度的保证

**原因 3：run_contract.py 是配置合并的巨石（部分可优化）**
- 617 行，功能：读取 target.env + suite.env + 环境变量 → 构建 RunConfig
- 包含大量的 AWS/KVM 分支逻辑（约 200 行），实际使用路径有限

**原因 4：input_generators.py 行数多但结构重复（可以削减）**
- 699 行，有 20+ 个 `_build_xxx` 函数，每个结构几乎相同（LCG 变体 + 写入）
- 实质内容约 200 行，其余是样板重复

### 2.2 为什么创建了新文件？

**runner/suites/ 目录（新增约 1,415 行）**是最大的问题。这不是重构出来的——这是**新增的重复代码层**。

**问题的本质**：每个 suite 文件（micro.py/corpus.py/e2e.py/test.py）都有：
- 相同的 10 个 `parser.add_argument`（workspace/target-arch/target-name/executor/run-token/python-bin/bpftool-bin/container-runtime/runtime-container-image/runtime-python-bin）——在 4 个文件中重复了 40 次
- 相同的 `_runtime_env()` 函数骨架（PATH/PYTHONPATH/BPFTOOL_BIN/BPFREJIT_REPO_ARTIFACT_ROOT/BPFREJIT_KERNEL_MODULES_ROOT 在 4 个文件各设一次）
- 相同的 `_module_argv()` 函数（重新将 args namespace 序列化为 argv list，4 份）
- 相同的 `main()` + container dispatch 逻辑（4 份）

`_common.py`（290 行）**虽然已提取了部分公共函数，但这还远不够**。真正可复用的 argparse 基础和 _runtime_env 基础仍然在每个 suite 文件中重复。

**suite_args.py（185 行）**：这个文件存在的原因是将"从环境变量构建 argv"的逻辑与 suite 的解析逻辑分离。这是合理的抽象。但内部有与 `_common.py` 重复的 `_csv_tokens`/`_join_csv` 函数（3 处重复：run_contract.py、suite_args.py、suites/_common.py）。

**_.env 文件（45 行总计）**：这些文件是必要的——它们是 `run_contract.py` 中 `_load_assignment_file(SUITES_DIR / f"{suite_name}.env")` 的配置输入，不可删除。

---

## 3. 每个 >200 行的文件深度分析

### katran.py（784 行）
- **做什么**：Katran XDP 负载均衡器的完整测试驱动。创建 3 个网络 namespace（router/client/real），设置 IP 路由，运行 katran_server_grpc，发送测试包，验证 XDP 转发
- **必要行估计**：~550 行。涉及网络拓扑的代码无法大幅简化
- **可削减**：约 230 行。主要是：(1) IP/MAC 常量可以用 dataclass 压缩；(2) `_setup_*` 系列函数存在模式重复（每个 namespace 设置 ~30 行）；(3) 错误消息字符串太详细

### rejit.py（752 行）
- **做什么**：`DaemonSession`（daemon 启动/停止/apply）+ `BenchmarkConfig`（YAML policy 解析）+ `RejitPolicy`（策略匹配逻辑）
- **必要行估计**：~500 行
- **可削减**：约 250 行。`_PASS_TO_SITE_FIELD`/`_TOTAL_SITE_FIELDS` 等字段映射可以大幅压缩；`BenchmarkConfig` 的 deep_merge 和 YAML 解析辅助函数约 100 行可以简化

### case_common.py（749 行）
- **做什么**：corpus/e2e 测试公共流程——quiescence 等待（等待 BPF 程序稳定）、kinsn 生命周期元数据、CPU/BPF stats 采样线程管理
- **必要行估计**：~550 行
- **可削减**：约 200 行。`wait_for_suite_quiescence` 的容错逻辑较冗长；部分统计辅助函数与 statistics.py 有重叠

### workload.py（705 行）
- **做什么**：所有工作负载生成函数（`run_tracee_default_load`/`run_network_load`/`run_file_open_load` 等）+ `LocalHttpServer`
- **必要行估计**：~550 行（工作负载种类多，每种各需配置）
- **可削减**：约 150 行。多个 `run_*` 函数有相同的 timeout/subprocess 处理骨架可以合并

### input_generators.py（699 行）
- **做什么**：为 micro benchmark 生成二进制输入文件（LCG seed、各种数据排列）
- **必要行估计**：~400 行
- **可削减**：约 300 行（最大单块）。20+ 个 `_build_xxx` 函数结构几乎完全相同（读 spec → LCG 计算 → struct.pack → write），可以用参数化的通用函数替换，代码可减少 40%

### run_contract.py（617 行）
- **做什么**：读取 target/suite env 文件 + 用户环境变量 → 构建 `RunConfig` dataclass，包含所有 AWS/KVM/remote 执行参数
- **必要行估计**：~450 行
- **可削减**：约 167 行。`_build_run_config_mapping` 函数（约 200 行）有大量重复的 `run_xxx = ""` 初始化 + 赋值模式；AWS 分支约 80 行，其中一半是样板验证

### reporting.py（593 行）
- **做什么**：micro 测试结果的统计分析和 Markdown/JSON 报告生成
- **必要行估计**：~500 行（报告内容丰富，复杂度合理）
- **可削减**：约 90 行（较少）

---

## 4. 核心问题：suite 层的重复

### 4.1 重复统计

| 重复项 | 出现次数 | 总重复行数 |
|--------|---------|-----------|
| 10 个公共 argparse 参数定义 | 4×10=40 次 | ~80 行重复 |
| `_runtime_env()` 公共部分（PATH/PYTHONPATH/BPFTOOL_BIN/REPO_ROOT/KERNEL_MODULES） | 4 次 | ~40 行重复 |
| `_module_argv()` 公共参数序列化 | 4 次 | ~40 行重复 |
| `main()` + container dispatch 骨架 | 4 次 | ~40 行重复 |
| `_positive_int`/`_nonnegative_int` | 2+2 次 | ~16 行重复 |
| `_csv_tokens`/`_join_csv` | 3 处 | ~12 行重复 |

**套件层总重复约 228 行，占 suites/ 总行数的 16%**（不算 _common.py 本身已提取的部分）。

### 4.2 suite_args.py 的角色

`suite_args.py`（185 行）是**一个合理但过于冗长的文件**。它的职责是：将 Makefile/CI 环境变量映射为 suite 的 argv list。这个抽象是对的。但：
- 内部 `_csv_tokens`/`_join_csv`/`_merge_csv_and_repeated` 与 `_common.py` 和 `run_contract.py` 各有一份，三处重复
- `suite_selection_from_args` 重新用 argparse 解析 argv 然后再提取 selection，与 suite 文件本身的解析有逻辑重叠

---

## 5. 能继续削减吗？

**可以，而且空间相当大。**

### 5.1 最大的削减机会（按优先级）

**优先级 1：input_generators.py（-300 行，可减至 ~400 行）**
- 20+ 个 `_build_xxx` 函数几乎是同一个模板（LCG + struct.pack），可以用参数化函数 + dispatch dict 替换
- 这是纯机械重复，风险低

**优先级 2：suites/ 层的 argparse 公共基础（-120 行）**
- 在 `_common.py` 中添加 `add_common_suite_args(parser)` 辅助函数，提取 10 个公共参数
- 在 `_common.py` 中添加 `build_common_runtime_env(workspace, args)` 提取 5 个公共 env 设置
- 可将 micro/corpus/e2e/test 各减少约 30 行

**优先级 3：消除 `_csv_tokens`/`_join_csv` 三处重复（-24 行）**
- 统一放在 `_common.py` 或 `cli_support.py`，其他两处 import

**优先级 4：rejit.py 的字段映射表压缩（-50 行）**
- `_PASS_TO_SITE_FIELD` 等常量可以更紧凑地定义

**优先级 5：run_contract.py 的 `_build_run_config_mapping` 重构（-80 行）**
- 21 个 `run_xxx = ""` 初始化 + 赋值模式，可以用 dict 统一处理

### 5.2 不应该动的地方

- katran.py 的网络拓扑代码——复杂度来自 Katran 本身
- case_common.py 的 quiescence 逻辑——测量精度依赖
- workload.py 的各工作负载函数——每种工作负载确实不同
- aws_executor.py——AWS CLI 调用本身就复杂

---

## 6. 总结

### 当前状态
- **总行数**：12,739 行（Python）+ 45 行（env 文件）
- **新增文件**：runner/suites/ 是本次重构新建的，增加了约 1,415 行。其中 _common.py（290 行）是提取公共代码的正确方向，但 4 个 suite 入口文件（1,124 行）有大量内部重复

### 理论最低行数
- 通过消除重复（约 600 行）+ input_generators 重构（约 300 行）：**可减至约 11,800 行**
- 这是不破坏架构、低风险的削减范围

### 最大浪费在哪里
1. **input_generators.py 的 LCG 函数重复**（~300 行可削）
2. **4 个 suite 文件中的 argparse/env/argv 重复**（~200 行可削）
3. **run_contract.py 的配置映射样板**（~80 行可削）
4. **_csv_tokens 等工具函数三处重复**（~30 行可削）

### 建议的下一步
如需继续削减，最具性价比的单一操作是：重写 `input_generators.py`，将 20+ 个结构相同的 `_build_xxx` 函数合并为 3-4 个参数化的生成器，可立即减少约 250-300 行，且风险低（纯数据生成，无 I/O 副作用）。
