# Runner 业务逻辑审查报告

> 审查日期：2026-04-11  
> 审查方法：逐文件读取完整内容，按功能分析必要性  
> 排序：不必要程度 × 行数（越靠前越值得删）

---

## 一、总体结论

runner 中有约 **3,000~4,000 行**代码属于"可删/可大幅精简"范畴，集中在以下几类：
1. AWS 基础设施管理（完整可删）：约 900 行
2. katran 复杂 DSR 网络拓扑管理（可大幅精简）：约 500 行  
3. workload 中的冷僻路径（约 8 种几乎不用的工作负载）：约 150 行
4. rejit.py 中 branch_flip 专用流程（已过时设计）：约 60 行
5. case_common.py 中未被外部调用的 utility 函数：约 40 行
6. reporting.py 的 perf counter 分析层（micro suite 专属，现有路径绕开）：约 80 行
7. test suite 的 fuzz 模式（几乎不作为独立模式跑）：约 40 行

---

## 二、逐文件审查

### 2.1 aws_executor.py (506行) + aws_common.py (207行) + aws_remote_host.py (406行)

**总行数：~1120 行**

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| 启动/复用 EC2 实例（launch/describe/reuse） | **可选** | ARM64 远端 benchmark 用到 |
| 检查实例 AMI、key、subnet 是否匹配并决定是否重建 | **可选** | 是上面功能的一部分 |
| 构建 x86 内核 artifact（调 Makefile） | **可选** | ARM64 CI 流程用到 |
| 构建 ARM64 内核 artifact | **可选** | ARM64 CI 流程用到 |
| SSH 等待、rsync/scp 传输 | **可选** | AWS 传输层 |
| 远程 helper 脚本（aws_remote_host.py）：设置 grubby/dracut/initramfs | **可选** | 只有 AWS 实例换内核时用 |
| 远程检查 BTF/sched_ext 支持 | **可选** | AWS 实例初始化时用 |
| 拉取内核 config（刷新 ARM64 base config）| **可选** | ARM64 内核编译前用 |
| 终止实例、清理失败 run | **可选** | AWS 生命周期管理 |

**判断：整体"可选"，仅限 AWS 远端场景**

- 如果只做 KVM 本地测试，可以完整删除 `aws_executor.py`、`aws_common.py`，并大幅简化 `aws_remote_host.py`（只保留 `run-workspace` 相关的远程执行部分）
- `aws_remote_host.py` 中的 `cmd_setup_kernel_x86`、`cmd_setup_kernel_arm64`（约 70 行）是 AWS 特有的 grubby/dracut 内核安装流程，KVM 模式不需要
- **可节省：若删 AWS 路径，可删 700-900 行**

---

### 2.2 run_contract.py (617行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `RunConfig` dataclass（身份+suite+artifact+remote+aws+kvm 配置） | **必要** | 整个配置流程的核心结构 |
| `to_mapping()` / `from_mapping()` / JSON 序列化 | **必要** | 配置传递给 KVM/AWS executor |
| `_build_run_config_mapping`：从 env 变量组装完整配置 | **必要** | make 调用时的入口 |
| AWS 相关字段组装（`AwsConfig`，约 30 个 AWS_xxx 环境变量） | **可选** | 仅 AWS 目标需要 |
| `_apply_corpus_filter_selection` | **必要** | corpus suite 按 app 过滤 |
| `_apply_e2e_case_selection` | **必要** | e2e suite 按 case 选择 |
| `_validate_test_mode` 支持 `fuzz` 模式 | **可选** | fuzz 模式很少独立跑 |
| `_resolve_run_llvm_dir`（调用 llvm-config） | **必要** | llvmbpf 编译需要 |
| `build_target_config`（仅含 terminate 操作时用） | **可选** | 只有 AWS terminate 动作用 |

**判断：核心逻辑必要，AWS 相关字段可瘦身约 80-100 行**

---

### 2.3 katran.py (784行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `KatranDsrTopology`：3个 netns + 6条 veth + IP/路由/neigh 配置（约 120行） | **必要** | katran e2e 测试需要真实 DSR 拓扑 |
| `KatranServerSession`：启动 katran_server_grpc，discover maps/programs（约 90行） | **必要** | katran runner 核心 |
| `configure_katran_maps`：写入 VIP/real/ch_ring（65537项 batch write）（约 30行） | **必要** | 测试需要配置好负载均衡器 |
| `reattach_xdp_program`：在 driver/native/generic 模式间切换 XDP attachment | **必要** | network workload 用 xdpgeneric，test_run 用 native |
| `NamespaceHttpServer`：在 real netns 启动 HTTP 服务（约 50行） | **必要** | network workload 需要 backend server |
| `PARALLEL_CLIENT_REQUEST_SCRIPT`：内嵌 Python HTTP 客户端脚本（约 100行） | **可选** | 可以用 wrk/ab/curl 替代，但内嵌脚本更精确 |
| `run_katran_prog_test_run`：bpftool prog run 验证包路径正确性 | **必要** | 验证 XDP 程序返回 XDP_TX |
| `wait_for_katran_teardown`：等待 prog_id 消失 + netns 消失 | **必要** | 防止下一个 case 污染 |
| `KatranRunner` 支持两种 workload_kind：`network` 和 `test_run` | **必要** | 两种用于不同场景 |

**判断：katran 功能整体必要，但 `PARALLEL_CLIENT_REQUEST_SCRIPT`（约100行内嵌 Python）可以用外部工具替代，是最可删的部分**

**整个 katran runner 的必要性**：katran 作为 XDP LB 是 BpfReJIT 论文中 corpus/e2e 重要案例，不建议删除。但如果只做 micro/corpus 不含 katran，可删整个 `katran.py`（784行）。

---

### 2.4 rejit.py (752行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `load_benchmark_config` / `_load_benchmark_root_config`：读取 YAML 配置 | **必要** | 控制哪些 pass 对哪些程序生效 |
| `benchmark_policy_candidate_passes`：计算 scan 时需要探测哪些 pass | **必要** | 决定 scan 请求包含哪些 pass |
| `resolve_program_enabled_passes`：按 policy rules 为每个程序选择 pass | **必要** | per-program 差异化 pass 选择 |
| `benchmark_config_iterations/warmups/repeat`：从配置读整数参数 | **必要** | 控制 micro benchmark 参数 |
| `scan_programs`：发送 dry_run optimize 请求，返回各 program 的 site counts | **必要** | scan 阶段核心 |
| `apply_daemon_rejit`：逐个发送 optimize 请求，合并结果 | **必要** | apply 阶段核心 |
| `_prepare_branch_flip_profile`：发 `profile-start` / `profile-stop` 命令（约60行） | **不必要** | branch_flip pass 需要 daemon 先采一次 perf profile；但 branch_flip 在当前 benchmark_config 中是否实际启用？是实验性特性 |
| `_site_counts_from_optimize_response` / `applied_site_totals_from_rejit_result` 等计数归一化（约 80行） | **可选** | 报告层需要，但多次计数路径有冗余 |
| `DaemonSession`：context manager，封装 daemon 进程生命周期 | **必要** | 所有 daemon 通信通过这个 |
| `_start_daemon_server` / `_stop_daemon_server` / `_kill_proc` | **必要** | daemon 进程管理 |
| `collect_effective_enabled_passes`：从 rejit 结果树里递归搜集实际用了哪些 pass | **可选** | 只用于审计/reporting，不在关键路径上 |
| `_deep_merge`：YAML 配置的 deep merge | **必要** | profile override 需要 |
| `_policy_rule_matches` / `_policy_context_text` 等 policy 规则匹配（约 80行） | **必要** | policy-based pass 选择 |

**重点不必要项：`_prepare_branch_flip_profile`（约 60 行）**
- 这套 profile-start/stop 协议是专门为 `branch_flip` pass 设计的
- 需要 daemon 支持额外的 profile 命令，增加了 daemon 协议复杂度
- 如果 branch_flip 没有在当前 benchmark 配置中启用为默认 pass，这 60 行永远不走

---

### 2.5 case_common.py (749行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `run_case_lifecycle`：基础生命周期框架（setup→baseline→scan→apply→post）| **必要** | 所有 e2e 案例依赖这个框架 |
| `run_app_runner_lifecycle`：对 AppRunner 的封装 | **必要** | corpus/e2e 使用 |
| `run_app_runner_phase_records`：组装 baseline/rejit phase records | **必要** | corpus driver 调用 |
| `measure_app_runner_workload`：测量工作负载 + BPF stats + CPU 采样 | **必要** | e2e 测量核心 |
| `_resolve_scan_pass_selection` / `_resolve_apply_passes_by_program`：pass 选择 | **必要** | 委托给 rejit.py |
| `_merge_group_rejit_results`：合并多个 program 组的 rejit 结果 | **必要** | 支持 per-program 差异化 pass |
| `_program_policy_context`：从 program 记录提取 context 字段（object, section, family 等）| **必要** | policy 匹配需要 |
| `wait_for_suite_quiescence`：等待 BPF 程序表稳定 | **必要** | 防止相邻 case 污染 |
| `prepare_daemon_session` / `PreparedDaemonSession` | **必要** | daemon 会话准备 |
| `CaseLifecycleState` / `LifecycleRunResult` / `LifecycleAbort` dataclass | **必要** | 生命周期状态载体 |
| `_pending_kinsn_metadata` 全局列表 + `attach_pending_result_metadata` | **可选** | kinsn 模块元数据收集，用于 research，非 benchmark 核心 |
| `_append_pending_kinsn_metadata` / `reset_pending_result_metadata` | **可选** | 同上 |
| `summarize_numbers` / `percent_delta` / `speedup_ratio` / `percentile` （约40行） | **不必要** | 这4个 utility 函数定义在 case_common.py 里，但在此文件中没有被调用，且 `wait_for_suite_quiescence` 也未被任何外部 suite 文件调用（只定义在这里） |

**等待 quiescence 函数（约 25行）**：定义在 case_common，但外部 suite 没有导入调用它（搜索结果只在 corpus/driver.py 和 e2e/case.py 的 `.cache` 快照里有引用，说明在实际运行路径上会用到，是必要的）。

**utility 函数（约 40行）**：`summarize_numbers`、`percent_delta`、`speedup_ratio`、`percentile` 四个函数定义在 case_common 但没有被 case_common 内部使用，推测是从外部 e2e case 调用的，但核心 benchmark 路径未用。

---

### 2.6 workload.py (705行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `run_exec_storm`：stress-ng exec workload（tracee e2e 核心）| **必要** | exec_storm 是 tracee e2e 主要测量 |
| `run_file_io`：fio 文件 IO workload | **必要** | tracee e2e file_io 测量 |
| `run_network_load`：wrk HTTP 负载 | **必要** | tracee/katran e2e network 测量 |
| `run_user_exec_loop`：简单 exec 循环 | **必要** | 多处使用 |
| `run_rapid_open_storm`/`run_open_storm` | **必要** | tetragon/tracee 的 open 工作负载 |
| `run_rapid_connect_storm`/`run_connect_storm` | **必要** | tracee network workload 的一部分 |
| `run_rapid_bind_storm`/`run_bind_storm` | **可选** | 只在 mixed_workload 里用 |
| `run_tracee_default_load`：混合 exec+open+connect | **必要** | tracee "tracee_default" workload |
| `run_tcp_retransmit_load`：netem delay+loss，12% packet loss（约80行）| **不必要** | 只有 bpftrace 的 tcp_retransmit 脚本用这个，极少跑 |
| `run_block_io_load`：null_blk 设备 DD 读写（约30行）| **不必要** | 只有 bpftrace block_io 和 tracee block_io workload 用，需要 null_blk 模块，很少跑 |
| `run_vfs_create_write_fsync_load`（约15行）| **不必要** | 只有 bpftrace vfs_sync 脚本用 |
| `run_tcp_connect_load`：curl IPv4+IPv6 连接（约30行）| **可选** | tracee_default/mixed 用 network_as_tcp_connect 时走这里 |
| `run_scheduler_load`：hackbench（约20行）| **可选** | 只在 mixed_workload 和 scx 中用 |
| `run_mixed_workload`：6种 workload 的时间片组合（约25行）| **可选** | bcc/scx 的 "mixed" workload 用 |
| `run_named_workload`：20+种 workload 名字的 dispatcher（约70行）| **必要** | 所有 workload 的入口 |
| `LocalHttpServer`：本地 HTTP 服务器（约45行）| **必要** | run_network_load 和 run_tcp_connect_load 需要 |
| `run_rapid_exec_storm`：简单 exec 循环 | **必要** | user_exec_loop 基础 |
| `_disk_backed_tmp_root` / `_shared_unprivileged_tmp_root`（约30行）| **必要** | exec_storm 需要 |
| `oom_stress`、`iterator_poll`、`sysctl_write`、`userns_unshare`、`security_policy_mix`（约40行）| **不必要** | dispatcher 里的小众 workload，实际 suite 配置中没有用到 |

**可删/精简量估算：约 150-200 行**（tcp_retransmit + block_io + vfs + oom_stress + iterator_poll + sysctl_write + userns_unshare + security_policy_mix）

---

### 2.7 reporting.py (593行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `BenchmarkStatistics` / `GroupStatistics` / `ComparisonSummary` 等 dataclass | **必要** | micro suite 报告结构 |
| `compute_per_benchmark_statistics`：读取 benchmark 结果，计算 exec 比率 | **必要** | `summarize_rq.py` 调用 |
| `bootstrap_geometric_mean_ci`（约15行）| **必要** | geomean 置信区间 |
| `bootstrap_ratio_ci`（约20行）| **可选** | 只在 baseline 调整比率时用，有 baseline benchmark 时才走 |
| `_perf_runtime_statistics`（约25行）| **不必要** | perf counter 分析（IPC、branch miss rate、cache miss rate）在 e2e/corpus suite 中没有 perf counter 数据；只有 micro suite 的 llvmbpf runner 会采 perf counter，而 `summarize_rq.py` 是 micro 专属工具。**但这块逻辑依赖 `perf_counters_meta`，micro 实际上不通过 reporting.py 汇总**，基本是死代码 |
| `PerfRuntimeStatistics` dataclass（约10行）| **不必要** | 同上 |
| `render_rq_summary_markdown`：输出 markdown 报告（约100行）| **必要** | `summarize_rq.py` 用 |
| `render_corpus_summary_markdown`（约25行）| **必要** | `summarize_rq.py` 用 |
| `format_ns` / `format_ratio` / `format_ci` 等格式化工具（约30行）| **必要** | 报告输出 |
| `win_counts`（约10行）| **必要** | 胜率统计 |

**判断：perf counter 相关约 35 行可删；bootstrap_ratio_ci 路径较复杂但仍有用**

---

### 2.8 statistics.py (182行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `geometric_mean`（约7行）| **必要** | 全局使用 |
| `ns_summary` / `float_summary`（约35行）| **必要** | 所有 benchmark 计时汇总 |
| `summarize_phase_timings`（约10行）| **必要** | micro benchmark phase 时间分析 |
| `summarize_named_counters`（约10行）| **必要** | 硬件计数器汇总 |
| `summarize_optional_ns`（约10行）| **必要** | optional 字段汇总 |
| `summarize_perf_counter_meta`（约50行）| **可选** | 采集 perf counter 元信息（是否开启、错误等）；只有 micro runner 采集，e2e/corpus 不采 |
| `derive_perf_metrics`（约30行）| **可选** | 从 perf counter 派生 IPC/branch miss rate/cache miss rate；同上，只有 micro runner 用 |

**判断：perf counter 相关约 80 行是 micro-only 功能，corpus/e2e 不需要**

---

### 2.9 results.py (208行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `RunnerSample` TypedDict（约25行）| **必要** | runner 输出格式定义 |
| `UnifiedResultRecord` dataclass | **可选** | 定义了但似乎未被广泛使用 |
| `load_json` / `parse_last_json_line` / `parse_json_lines`（约25行）| **必要** | JSON 解析工具 |
| `parse_runner_samples` / `normalize_runner_sample`（约30行）| **必要** | micro runner 输出解析 |
| `collapse_command_samples`（约15行）| **必要** | 合并 stock/rejit 相邻样本 |
| `RejitSummary` TypedDict（约15行）| **必要** | rejit 结果格式 |
| `CodeSizeSummary` TypedDict（约5行）| **必要** | 代码大小信息 |
| `_default_rejit`（约15行）| **必要** | 默认值填充 |

**判断：整体必要，`UnifiedResultRecord` 可能冗余**

---

### 2.10 bpf_stats.py (123行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `list_program_ids`：bpftool prog show 获取所有 prog ID | **必要** | quiescence 检测使用 |
| `read_program_stats`：读取指定 prog ID 的 run_cnt/run_time_ns | **必要** | e2e 测量的 BPF 统计 |
| `sample_bpf_stats`：调用 read_program_stats（`prog_fds` 参数直接 del 了）| **必要** | 但 prog_fds 参数是死参数，永远不用 |
| `compute_delta`：计算 before/after 的 delta | **必要** | e2e 测量核心 |
| `enable_bpf_stats` context manager：yield {"mode": "bpftool"}（约5行）| **不必要** | 这个函数体基本是空的，返回一个固定字典，没有实质逻辑；历史遗留，曾经用 syscall 启用 BPF stats 但现在已经改成 bpftool |

**判断：`enable_bpf_stats` 是一个空 context manager，约5行形式代码可删**

---

### 2.11 state_file.py (91行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `read_json_object` / `write_json_object`（约15行）| **必要** | JSON 读写工具 |
| `read_state` / `write_state`（约15行）| **必要** | 状态文件读写（string-only） |
| `merge_state`（约10行）| **必要** | AWS instance state 更新 |
| `main` CLI：支持 `write` 和 `merge` 子命令（约40行）| **可选** | 只有 Makefile 中的 shell 脚本会直接调用这个 |

**判断：整体必要，CLI 部分如果没有 shell 脚本调用可删**

---

### 2.12 input_generators.py (699行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| 24种手写 generator（`generate_*` 函数，约400行）| **必要** | 每个对应一个 micro benchmark 案例 |
| 22种 YAML spec 驱动的 generator（`_KIND_BUILDERS`，约270行）| **必要** | 通过 input_specs.yaml 配置驱动 |
| `materialize_input`：写文件到 `micro/generated-inputs/`（约15行）| **必要** | micro suite 调用 |

**判断：整体必要，没有冗余**（每个 generator 对应一个 benchmark，如果有 benchmark 被删，相应 generator 才可删）

---

### 2.13 test suite (test.py, 426行)

#### 功能列表

| 功能 | 判断 | 原因 |
|------|------|------|
| `selftest` 模式：运行 rejit_* 单元测试 + 负向测试 | **必要** | 基础正确性验证 |
| `negative` 模式：adversarial_rejit + fuzz_rejit + scx_prog_show_race | **必要** | 对抗性测试 |
| `test` 模式（full test）：含 kernel selftest | **必要** | 完整测试 |
| `fuzz` 模式：只跑 fuzz_rejit | **可选** | 是 negative 模式的子集，单独拆出来是为了 CI 中专门跑 fuzz；但如果 fuzz CI 已整合进 negative，这个模式可合并 |
| `_run_fuzz_mode`（约15行）| **可选** | 同上 |
| SCX race 测试（约30行）| **必要** | sched_ext 并发 prog_show 竞态检测 |
| `_discover_unittest_binaries`（约10行）| **必要** | 发现 rejit_* 测试二进制 |

**判断：fuzz 模式约 40 行可合并进 negative 模式**

---

### 2.14 app_runners 各模块

#### tracee.py (524行)
- `TraceeOutputCollector`（约160行）：实时消费 tracee stdout/stderr/event 文件，支持 `wait_for_event`。**必要**，但 `wait_for_event` 是否实际用到？（在 e2e case.py 中用于等待特定事件确认工作负载触发了 tracee hook）
- `run_exec_storm_in_cgroup`（约50行）：在 cgroup 内运行 stress-ng exec，用于 tetragon 隔离测量。**必要**
- `TetragonRunner` / `BpftraceRunner`（各约100行）：**必要**

#### scx.py (373行)
- `ScxSchedulerSession`（约100行）：**必要**
- `ScxRunner`（约150行）：**必要**
- sysbench/hackbench 输出解析正则（约5行）：**必要**

#### bcc.py (340行)
- `BCCWorkloadSpec` / `_bcc_tool_specs`：从 YAML 读 BCC 工具配置。**必要**
- `_TailCapture`（约30行）：线程安全的尾部捕获缓冲区。**可选**（其他地方也有类似实现，有一定重复）
- `BccRunner`（约150行）：**必要**

#### bpftrace.py (207行)
- 3个预定义 script spec（block_io/tcp_retransmit/vfs_sync）：**可选**，依赖极少用的 workload
- `BpftraceRunner`（约130行）：**必要**（如果整个 bpftrace case 保留）

---

## 三、重复实现清单

| 重复功能 | 在哪些地方 | 建议 |
|----------|-----------|------|
| `percentile` 函数 | `case_common.py`、`reporting.py`、`katran.py`（内嵌脚本）、`scx.py` | 应合并到 `statistics.py` |
| 进程 stderr/stdout tail 捕获 | `bcc.py`（`_TailCapture`）、`tracee.py`（`TraceeOutputCollector`）、`libs/__init__.py`（`tail_text`）、`process_support.py` | 4处实现，可统一 |
| BPF program 发现（bpftool prog show）| `bpf_stats.py`（`_prog_show_payload`）、`katran.py`（`_current_prog_ids`）、`agent.py`（`find_bpf_programs`） | 3处实现，应统一 |
| `_ordered_unique`/去重列表 | `case_common.py`（`_normalize_enabled_passes`）、`rejit.py`（`_ordered_unique_passes`）、`aws_executor.py`（`_ordered_unique`） | 3处实现 |

---

## 四、整个 App Runner 可删性评估

| Runner | 行数 | 可删？ | 依据 |
|--------|------|--------|------|
| `katran.py` | 784 | 可选删 | 只有 e2e 的 katran case 用；论文有结果但如果不再 benchmark katran 可删 |
| `bpftrace.py` | 207 | 可选删 | 只有 e2e 的 bpftrace case 用；bpftrace 工具 coverage 弱，3个脚本都是小众 workload |
| `scx.py` | 373 | 可选删 | 只有 e2e 的 scx case 用；sched_ext 需要特殊内核配置 |
| `bcc.py` | 340 | 可选删 | 只有 e2e 的 bcc case 用 |
| `tetragon.py` | 269 | 可选删 | 只有 e2e 的 tetragon case 用 |
| `tracee.py` | 524 | **不可删** | tracee 是论文主要 e2e 案例，结果权重最大 |

**结论：如果只保留 tracee（主要 e2e 案例），可删 ~1200 行 app runner 代码**

---

## 五、AWS 路径代码量

| 文件 | 总行数 | AWS 专属行数 | KVM 模式可删行数 |
|------|--------|-------------|----------------|
| `aws_executor.py` | 506 | **506** | **506**（整个文件可删） |
| `aws_common.py` | 207 | **207** | **207**（整个文件可删） |
| `aws_remote_host.py` | 406 | ~300（内核安装相关）| ~300 |
| `run_contract.py` | 617 | ~120（AwsConfig + AWS env 字段）| ~120 |

**AWS 路径总计可删：约 1100-1130 行**

---

## 六、优先级排序（按不必要程度 × 行数）

| 排序 | 目标 | 行数 | 不必要理由 |
|------|------|------|-----------|
| 1 | `aws_executor.py` 整个删除 | 506 | 只有 AWS 远端目标用，KVM 模式完全不需要 |
| 2 | `aws_common.py` 整个删除 | 207 | 同上 |
| 3 | `aws_remote_host.py` 中的内核安装命令（`setup_kernel_x86/arm64` 等） | ~300 | AWS 内核烧录专用，KVM 不需要 |
| 4 | `workload.py` 冷僻路径（tcp_retransmit/block_io/vfs/oom/iterator） | ~150 | 几乎不跑的 workload，依赖特殊硬件或内核模块 |
| 5 | `katran.py` 内嵌 `PARALLEL_CLIENT_REQUEST_SCRIPT`（Python 脚本） | ~100 | 可用外部工具替代，维护成本高 |
| 6 | `rejit.py` 的 `_prepare_branch_flip_profile`（profile-start/stop 协议） | ~60 | branch_flip 实验性特性，增加 daemon 协议复杂度 |
| 7 | `statistics.py` / `reporting.py` 的 perf counter 汇总层 | ~80 | e2e/corpus 不采 perf counter，这段代码实际是 micro-only 且绕开 |
| 8 | `case_common.py` 中4个未调用的 utility 函数（`summarize_numbers` 等） | ~40 | 定义但未被内部调用 |
| 9 | `bpf_stats.py` 的 `enable_bpf_stats`（空 context manager） | ~5 | 历史遗留，函数体是空的 |
| 10 | `test.py` 的独立 fuzz 模式 | ~40 | negative 模式的子集，可合并 |

---

## 七、如果只做 KVM 本地测试能删多少？

假设只保留 `x86-kvm` 和 `arm64-kvm` 两个 target，并保留全部4个 suite（micro/corpus/e2e/test）：

| 类别 | 可删行数 |
|------|---------|
| AWS executor（aws_executor + aws_common）| 713 |
| aws_remote_host 中 AWS 内核安装部分 | ~300 |
| run_contract.py 中 AWS 配置字段 | ~120 |
| 合计 | **约 1130 行** |

这约占当前 runner/libs 代码量（~11300行 含 app_runners）的 **10%**，但占"基础设施/配置"层代码的 **~30%**。
