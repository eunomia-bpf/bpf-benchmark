# runner/ Python 代码审计报告

生成时间：2026-04-10

## 说明

审计范围：`runner/libs/` 下所有 `.py` 文件（共 44 个，约 **15,472 行**）。
不含 `runner/repos/`（第三方仓库）和 `runner/build-*/`（构建产物）。

---

## 一、总览表格

按 **行数 × 不必要程度** 从高到低排列（最应动刀的排最前）。

| 优先级 | 文件（相对 runner/libs/） | 行数 | 职责一句话 | 判断 |
|:---:|---|:---:|---|:---:|
| ★★★★★ | `rejit.py` | 1297 | BpfReJIT daemon 的 scan/optimize 调用、配置加载、pass 策略解析、socket 通信 | **可削减** |
| ★★★★★ | `app_runners/katran.py` | 1219 | Katran XDP 负载均衡器的启动/网络拓扑搭建/BPF map 操作/测包流程 | **可削减** |
| ★★★★ | `input_generators.py` | 1207 | 为 micro benchmark 生成各种二进制输入文件（50+ 个 generate_* 函数） | **可用配置替代** |
| ★★★★ | `case_common.py` | 1126 | E2E benchmark case 共享逻辑：生命周期编排、REJIT 流程、workload 测量 | **可削减** |
| ★★★★ | `workload.py` | 1016 | 各种 workload 执行函数（exec_storm/network/block_io/scheduler 等） | **必要（但可削减）** |
| ★★★ | `reporting.py` | 755 | micro benchmark 结果的统计分析与报告生成（仅用于本地报告工具） | **可削减** |
| ★★★ | `run_contract.py` | 701 | 从 Makefile 环境变量构建 runner manifest 文件 | **必要（但可削减）** |
| ★★★ | `aws_executor.py` | 700 | AWS EC2 实例的启动/销毁/SSH 传文件/远端运行 | **必要（但可削减）** |
| ★★★ | `suite_entrypoint.py` | 685 | 在 guest/远端执行 suite（micro/corpus/e2e）的调度和容器启动 | **必要（但可削减）** |
| ★★★ | `app_runners/tracee.py` | 608 | Tracee 安全监控工具的启动/事件收集/workload 运行 | **可削减** |
| ★★ | `app_runners/tetragon.py` | 474 | Tetragon eBPF 安全工具的启动/BPF 程序等待/workload 运行 | **可削减** |
| ★★ | `app_runners/scx.py` | 402 | sched_ext 调度器的启动/状态检测/workload 运行 | **可削减** |
| ★★ | `app_runners/bcc.py` | 349 | BCC libbpf-tools 工具集的启动和 workload 运行 | **可削减** |
| ★★ | `aws_common.py` | 328 | AWS executor 的 context 构建/SSH 命令封装/instance 查询 | **必要** |
| ★★ | `aws_remote_host.py` | 325 | 在 AWS 远端主机执行的辅助命令集（prepare-dir/uname-r/verify-prereqs 等） | **可删除（部分）** |
| ★★ | `app_runners/process_support.py` | 318 | BPF agent 进程的 IO 采集、AgentSession、ManagedProcessSession 等基础类 | **必要** |
| ★★ | `run_artifacts.py` | 278 | 结果文件目录管理（ArtifactSession、metadata 写入）| **必要** |
| ★★ | `workspace_layout.py` | 270 | workspace 内各产物路径的函数 | **可用配置替代** |
| ★★ | `run_target_suite.py` | 266 | 从 host 触发 local_prep 和 executor 运行（跨 kvm/aws）| **必要（但可削减）** |
| ★ | `results.py` | 238 | UnifiedResultRecord + 各 TypedDict 类型定义（跨 suite 共用 schema）| **必要** |
| ★ | `guest_prereqs.py` | 235 | 在 guest 侧检查/安装工具、加载容器镜像 | **必要** |
| ★ | `arm64_kernel_config.py` | 225 | ARM64 内核编译配置注入（scripts/config 调用封装）| **可削减** |
| ★ | `kinsn.py` | 217 | kinsn 模块加载/卸载/snapshot 捕获 | **必要** |
| ★ | `__init__.py` | 209 | 根模块：ROOT_DIR、run_command、resolve_binary、tail_text 等基础工具 | **必要** |
| ★ | `app_runners/bpftrace.py` | 209 | bpftrace 脚本定义（6 个 ScriptSpec 硬编码）+ 启动/workload | **可用配置替代** |
| ★ | `statistics.py` | 195 | 统计工具：geomean/ns_summary/float_summary/perf_metrics | **必要** |
| ★ | `app_suite_schema.py` | 182 | YAML corpus/e2e 应用配置的数据类 schema 和解析 | **必要** |
| ★ | `vm.py` | 172 | 写 guest 脚本、封装 vng 命令、在 VM 里运行 | **必要** |
| ○ | `agent.py` | 149 | start/stop/wait_healthy + BPF prog 发现 | **必要** |
| ○ | `metrics.py` | 131 | CPU 使用率采样（pid/系统级）、BPF stats | **必要** |
| ○ | `app_runners/__init__.py` | 124 | runner 分发/adapter：把 YAML workload 字段映射到 runner kwargs | **可削减** |
| ○ | `manifest_file.py` | 121 | manifest 文件（KEY=VALUE shell 格式）解析和渲染 | **必要** |
| ○ | `app_runners/base.py` | 109 | AppRunner 抽象基类 | **必要** |
| ○ | `state_file.py` | 101 | JSON state 文件读/写/merge + CLI 入口 | **必要** |
| ○ | `bpf_stats.py` | 87 | bpftool prog show 采样、read_program_stats | **必要** |
| ○ | `app_runners/setup_support.py` | 85 | ELF arch 检测、repo_artifact_root 解析、missing_required_commands | **必要** |
| ○ | `environment.py` | 76 | 读 host 环境文件、validate_publication_environment | **必要** |
| ○ | `prereq_contract.py` | 73 | manifest contract 中的 python/container/command 路径解析 | **必要** |
| ○ | `kvm_executor.py` | 73 | KVM executor：写 guest 脚本并调 run_in_vm | **必要** |
| ○ | `benchmarks.py` | 45 | select_benchmarks + resolve_memory_file | **必要** |
| ○ | `kernel_modules.py` | 40 | modprobe 封装 | **必要** |
| ○ | `process_fd.py` | 28 | pidfd_getfd syscall 封装（dup fd cross-process）| **必要** |
| ○ | `cli_support.py` | 24 | fail/require_path/require_nonempty_dir | **必要** |

---

## 二、最该动刀的文件——详细分析

### 1. `rejit.py`（1297 行）★★★★★ 可削减

**职责混合严重**，一个文件承担了：
1. 配置文件加载和 deep merge（约 120 行）
2. Pass 策略计算（约 150 行，`_policy_rules_for_program`、`resolve_program_enabled_passes`）
3. Daemon socket 通信（约 250 行：`_scan_request`、`_optimize_request`、`_profile_request`）
4. Daemon 进程生命周期管理（约 200 行，`DaemonSession` context manager，`_start_daemon_server`）
5. 上层 API（约 300 行：`apply_daemon_rejit`、`scan_programs_via_daemon` 等）
6. 辅助函数和常量（100+ 行）

**可以删掉或合并的部分**：

| 函数/代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| `_deep_merge` + `_mapping_dict` | ~20 | 用 `dict.update` 或 PyYAML merge key 替代，不需要自定义 |
| `_benchmark_config_skeleton` | ~15 | 硬编码骨架可以直接写在 YAML 文件里 |
| `_zero_site_counts` | ~20 | 应移到 `results.py` 的 TypedDict 定义旁边，或完全删掉（调用者可用 `{}.get(key, 0)` 直接处理缺失 key） |
| `collect_effective_enabled_passes` | ~30 | 仅被 `kinsn.py` 调用一处，可以内联到调用方 |
| `_site_summary_from_counts` | ~20 | 纯字符串格式化，可删（调用方直接格式化） |
| `_ordered_unique_passes` / `_normalize_pass_list` | ~25 | 重复逻辑，合并为一个函数即可 |
| `_parse_enabled_passes` / `_benchmark_config_enabled_passes` | ~20 | 两层 lru_cache 封装同一个功能，合并 |
| 整个 `profile_via_daemon` | ~80 | profiling 流程不在核心路径，可以移出主模块，单独放 profiling 工具 |

**可重构方向**：拆分为 `rejit_config.py`（配置/policy）+ `rejit_daemon.py`（socket 通信/进程）+ 保留 `rejit.py` 只做 API 入口，预计每个文件 200–300 行。

---

### 2. `app_runners/katran.py`（1219 行）★★★★★ 可削减

全文件 90% 是硬编码的网络拓扑 IP/MAC/命名空间常量 + ctypes BPF map 操作 + 包构造。

**可以删掉或合并的部分**：

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| 顶部 30+ 个模块级常量（IP/MAC/接口名/端口） | ~50 | 移入 YAML 配置文件 `e2e/cases/katran/config.yaml`，代码只读取 |
| `pack_u32` / `pack_mac` / `pack_ctl_mac` / `pack_vip_definition` / `pack_vip_meta` / `pack_real_definition` | ~30 | 纯数据序列化，可合并为一个 `_pack_*` 辅助模块或 dataclass，当前分散在 700 行处 |
| `LibbpfMapApi`（150+ 行 ctypes 封装）| ~160 | 整个类（`open`/`update`/`prog_test_run` 等）只服务于 Katran，功能可以用 `bpftool` JSON 命令替代（已有 `run_json_command`），避免维护 ctypes ABI |
| `KatranDsrTopology`（`__enter__`/`__exit__`，网络拓扑 setup/teardown）| ~200 | 逻辑本身必要，但其中大量 `ip_command(["link", "add", ...])` 调用链可以提取为 shell 脚本，Python 层只做状态管理 |
| `xdp_action_name` + `_program_name_variants` | ~20 | 一行 dict lookup，没必要单独函数 |
| `ensure_kernel_module_loaded` | ~10 | 与 `kernel_modules.py` 的 `load_kernel_module` 功能重复 |
| `KatranRunner.run_workload_spec` 内的 HTTP 请求发包逻辑 | ~80 | 可提取为独立的 `_run_katran_http_test` 函数，或移入 workload.py |

**可重构方向**：将常量移 YAML，删掉 `LibbpfMapApi`（改用 bpftool），合并网络拓扑为独立辅助函数，预计可缩减到 400–500 行。

---

### 3. `input_generators.py`（1207 行）★★★★ 可用配置替代

文件全是 50+ 个 `generate_*` 函数，每个函数：
1. 硬编码测试参数（count、seed、state 等）
2. 用 LCG 生成伪随机数据
3. 调用 `output.write_bytes(blob)`

**问题**：参数全部硬编码在 Python 里，增加新 benchmark 需要修改 Python 代码。

**建议**：将 `count`、`seed`、`state` 等参数提取到 `micro/config/input_params.yaml`，Python 只保留：
1. 一个通用的 LCG 生成器（~20 行）
2. 一个从配置读取并分发的 `generate(name, output)` 入口（~30 行）
3. 少数确实需要特殊布局的生成器（二分搜索、bitmap 等，约 5 个，~100 行）

预计从 1207 行缩减到 **150–200 行**。

---

### 4. `case_common.py`（1126 行）★★★★ 可削减

E2E case 的共享逻辑，但职责仍然混乱：

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| `_PENDING_KINSN_METADATA` 全局列表 + `reset_pending_result_metadata` + `attach_pending_result_metadata` | ~50 | 全局可变状态是 anti-pattern。改为 `CaseLifecycleState` 的字段即可，3 个函数合并为 1 |
| `_current_program_ids` + `_new_program_ids` | ~30 | 与 `tetragon.py` 中的 `current_prog_ids` 完全重复；合并到 `bpf_stats.py` |
| `_benchmark_pass_plan` + `_normalize_enabled_passes` + `_program_records_by_id` + `_scan_record_counts` + `_program_policy_context` | ~100 | Pass plan 解析逻辑应集中在 `rejit.py`，这里的 5 个函数是为了调用 `rejit.py` 而引入的间接层 |
| `_merge_group_rejit_results` | ~80 | 仅被 `run_rejit_lifecycle` 内部使用一次，可以内联 |
| `run_app_suite_lifecycle` / `run_rejit_lifecycle` / `run_lifecycle` | ~300 | 三函数有大量重复的前置检查和结果拼装代码，可以用 `@dataclass` pipeline 简化 |
| `measure_app_runner_workload` | ~80 | 功能正确但可以直接移入各 runner 类的 `run_workload` 实现 |

---

### 5. `workload.py`（1016 行）★★★★ 必要但可削减

包含约 20 个 `run_*` workload 函数。问题是每个函数都有类似的循环结构和超时逻辑。

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| `_normalize_workload_limits` + `_work_remaining` | ~30 | 复用好，保留 |
| `LocalHttpServer` + `_SilentHandler` + `_ThreadingHTTPServerV6` | ~60 | 功能有效，但注释名 `_SilentHandler` 里有硬编码的 `"tracee-benchmark"` 响应体，应该参数化 |
| `run_rapid_exec_storm` vs `run_user_exec_loop` vs `run_exec_storm` | ~150 | 三个函数逻辑高度相似（都是循环 exec 命令），可以合并为一个带 `mode` 参数的函数 |
| `parse_stress_ng_bogo_ops` / `parse_hackbench_time` / `parse_sysbench_*` | ~80 | 各 runner 文件也有 regex 解析（如 scx.py 中 `HACKBENCH_TIME_RE`），存在重复 |
| `run_named_workload` | ~30 | dispatch 字典映射，可以保留但字典本身可以用 YAML 配置替代 |

---

### 6. `reporting.py`（755 行）★★★ 可削减

micro benchmark 报告生成工具，只被本地报告脚本调用，**不在 benchmark 关键路径上**。

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| `RQReport` + `BenchmarkStatistics` + `GroupStatistics` + `PerfRuntimeStatistics` | ~60 | 四个 dataclass 定义，功能必要，保留 |
| `_compute_adjusted_stats` / `_compute_bootstrap_ci` | ~100 | 统计计算，可以移入 `statistics.py` |
| `_detect_baseline_name` | ~20 | 启发式逻辑（找 "simple" baseline），应该从 manifest 里直接读取，不要猜 |
| `build_rq_report` | ~200 | 主报告构建函数，300 行的巨函数，内部有大量类似的 `for benchmark in...` 循环，可以用辅助函数提取 |
| `win_counts` / `_safe_ratio` / `_benchmark_raw_ratio` | ~40 | 应移入 `statistics.py` |

---

### 7. `run_contract.py`（701 行）★★★ 可削减

从 Makefile 环境变量构建 manifest 文件。

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| `CORPUS_WORKLOAD_KIND_COMMANDS` dict | ~10 | 应移入 YAML 配置 |
| `_KVM_MANIFEST_INPUTS` / `_AWS_MANIFEST_SUFFIXES` / `_COMMON_MANIFEST_INPUTS` | ~60 | 三个大型集合，硬编码的 "可通过"变量名，可以用 YAML schema 替代 |
| `_suite_repos_for_e2e_cases` / `_native_repos_for_e2e_cases` | ~40 | 硬编码 case→repo 映射，应该改为 YAML 配置 |
| `_apply_e2e_case_selection` | ~40 | 逻辑复杂但可以简化——直接从 YAML app suite 读 runner 名 |
| `build_manifest` / `build_target_manifest` | ~200 | 核心功能，必要，但有大量字符串拼接和条件判断，可以模板化 |

---

### 8. `aws_executor.py`（700 行）★★★ 可削减

AWS EC2 实例 launch/terminate/SSH 流程。

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| ARM64 kernel 构建部分（`_build_arm64_kernel`）| ~60 | 仅在 arm64 路径使用，可以提取为独立文件 `aws_arm64_prep.py` |
| `_remote_required_commands` | ~20 | 硬编码命令列表（`dracut`, `grubby`, `rsync` 等），应该移入 YAML |
| `_describe_instance_type` / `_remote_kernel_release` / `_remote_root_volume_size_gb` / `_remote_has_runtime_btf` / `_remote_has_sched_ext` | ~50 | 5 个结构完全相同的 remote probe 函数，可以用一个通用 `_remote_probe(ctx, ip, subcommand)` 替代 |
| `_require_aws_success` | ~10 | 可以内联，不需要单独函数 |

---

### 9. `app_runners/bpftrace.py`（209 行）★ 可用配置替代

文件 1/3 是 `SCRIPTS` 元组：6 个 `ScriptSpec` 硬编码的 bpftrace 脚本名、路径、描述、expected_programs 数量、workload_kind。

**建议**：将 `SCRIPTS` 迁移到 `e2e/cases/bpftrace/scripts.yaml`，Python 代码只读取配置，文件可以从 209 行缩减到 **~80 行**。

---

### 10. `workspace_layout.py`（270 行）★★ 可用配置替代

全是 `def xxx(workspace, target_arch) -> Path` 函数，每个函数一两行。

**现状**：`workspace / ".cache" / "repo-artifacts" / target_arch` 这样的路径规则重复出现 10+ 次。

**建议**：将路径模板集中到一个 YAML/JSON 配置，或者一个常量字典，Python 只保留一个 `artifact_path(category, workspace, arch)` 的统一入口，预计从 270 行缩减到 **~50 行**。

---

### 11. `arm64_kernel_config.py`（225 行）★ 可削减

全是对 `scripts/config` 的 `-e`/`-d` 调用列表，硬编码了 40+ 个内核 CONFIG 选项。

**建议**：将 CONFIG 选项列表提取为 `runner/config/arm64_kernel_config.txt`（标准 `scripts/config` 格式），Python 脚本只做"读文件 → 调用 scripts/config"，从 225 行缩减到 **~30 行**。

---

### 12. `app_runners/__init__.py`（124 行）★ 可削减

`_adapt_bcc`、`_adapt_bpftrace`、`_adapt_scx`、`_adapt_tracee`、`_adapt_tetragon`、`_adapt_katran` 6 个函数几乎结构相同：从 workload/app_name 提取一个字段，塞进 kwargs。

**建议**：用一个 YAML mapping 驱动的通用 `_adapt(runner_name, workload, app_name, kwargs)` 函数替代，删掉 6 个专用函数，预计从 124 行缩减到 **~40 行**。

---

### 13. `suite_entrypoint.py`（685 行）★★★ 可削减

| 代码块 | 行数估算 | 处理建议 |
|---|:---:|---|
| `_run_in_runtime_container` | ~80 | Docker run 命令拼装，大量 `-v` bind mount 枚举，可以改为配置驱动 |
| `SuiteEntrypoint._run_micro` / `_run_corpus` / `_run_e2e` / `_run_test` | ~250 | 四个方法结构高度类似（设置 env → 调 subprocess），可以提取公共 `_run_driver(driver_module, argv)` |
| `SuiteEntrypoint._kinsn_load_command` / `_kinsn_unload_command` | ~40 | 仅构造一个 CLI 调用，可以内联 |

---

## 三、总结：优先动刀顺序

| 顺序 | 文件 | 预计可削减行数 | 主要手段 |
|:---:|---|:---:|---|
| 1 | `input_generators.py` | ~1000 行 | 提取参数到 YAML，Python 只保留通用 LCG 生成器 |
| 2 | `rejit.py` | ~400 行 | 拆分职责，删掉冗余辅助函数，合并 lru_cache 封装 |
| 3 | `app_runners/katran.py` | ~500 行 | 删 LibbpfMapApi ctypes 层，常量移 YAML，提取网络拓扑为 shell 脚本 |
| 4 | `workspace_layout.py` | ~200 行 | 路径规则统一为一个常量字典 |
| 5 | `arm64_kernel_config.py` | ~190 行 | CONFIG 列表移文本文件 |
| 6 | `app_runners/bpftrace.py` | ~130 行 | ScriptSpec 列表移 YAML |
| 7 | `case_common.py` | ~250 行 | 删全局可变状态，合并重复函数，内联单调用函数 |
| 8 | `reporting.py` | ~150 行 | 统计函数移 statistics.py，删启发式 baseline 检测 |
| 9 | `app_runners/__init__.py` | ~80 行 | 6 个 adapter 合并为 1 个通用函数 |
| 10 | `aws_executor.py` | ~150 行 | 5 个 probe 函数合并，ARM64 构建提取 |

**理论上可从 15,472 行减少到约 9,000–10,000 行（削减 35–40%），且功能不减。**
