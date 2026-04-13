# Final Review v3 — 2026-04-12

## 1. 正确性验证结果

### 1.1 Import 验证

```
python3 -c "import runner.libs.aws_executor; import runner.libs.aws_common;
    import runner.libs.results; import runner.libs.metrics; import runner.libs.bpf_stats;
    import runner.suites._common; import runner.suites.corpus; import runner.suites.e2e;
    import runner.suites.test; import runner.libs.run_contract; import runner.libs.workspace_layout"
```

结果：**全部通过，无报错**

### 1.2 已删除符号的残留引用检查

| 已删除符号 | runner/*.py 中残留引用 |
|---|---|
| `aws_remote_host` | 无 |
| `_run_remote_helper` | 无 |
| `_ensure_remote_helper` | 无 |
| `env_with_cross_runtime_ld` | 无（已重命名为 `env_with_suite_runtime_ld`，所有调用方已更新） |
| `kernel_stage_dir` | 无（从 `RemoteConfig` 和 `RunConfig` 中删除） |
| `swap_size_gb` | 无（从 `RemoteConfig`、`RunConfig`、.env 文件中删除） |
| `parse_json_lines` | 无 |
| `parse_runner_samples` | 无 |
| `normalize_runner_sample` | 无 |

结果：**所有已删除符号无残留引用**

### 1.3 make check（py_compile 检查）

结果：**通过**（涵盖 29 个 Python 文件，含所有 app_runners、libs、suites）

---

## 2. 还有没有可以删的代码

### 2.1 `workspace_layout.remote_transfer_roots()` — 仍有调用者

`remote_transfer_roots()` 被 `runner/libs/aws_executor.py:416` 的 `_sync_remote_roots()` 调用，**不是死代码**，保留正确。

### 2.2 `aws_common.py` 各函数调用者核查

| 函数 | 调用者数量 | 状态 |
|---|---|---|
| `_build_context` | 2 | 活跃 |
| `_aws_cmd` | 26 | 活跃 |
| `_describe_instance` | 6 | 活跃 |
| `_lookup_target_instance_ids` | 1 | 活跃 |
| `_ssh_base_args` | 7 | 活跃 |
| `_ssh_exec` | 14 | 活跃 |
| `_scp_to` | 3 | 活跃（via `aws_common._scp_to()`） |
| `_rsync_to` | 1 | 活跃（via `aws_common._rsync_to()`，aws_executor.py:438） |
| `_rsync_from` | 1 | 活跃 |
| `_scp_from` | 1 | 活跃 |
| `_wait_for_ssh` | 5 | 活跃 |
| `_load_instance_state` | 9 | 活跃 |
| `_terminate_instance` | 5 | 活跃 |

**结论：aws_common.py 所有函数均有调用者，无死代码。**

注意：之前对 `_rsync_to` 的扫描看到"0 callers"是因为搜索词未包含 `aws_common._rsync_to` 前缀调用形式，实际有调用。

### 2.3 `__init__.py` 各函数调用者核查

| 函数 | 调用者数量 | 状态 |
|---|---|---|
| `ensure_parent` | 3 | 活跃 |
| `scratch_date_stamp` | 2 | 活跃 |
| `docs_tmp_dir` | 3 | 活跃 |
| `tail_text` | 78 | 活跃 |
| `which` | 351（含系统库） | 活跃 |
| `resolve_binary` | 4 | 活跃 |
| `resolve_bpftool_binary` | 18 | 活跃 |
| `run_command` | 67 | 活跃 |
| `run_json_command` | 14 | 活跃 |
| `result_date_stamp` | — | 被 `smoke_output_path` 内部调用 |
| `smoke_output_path` | 2（micro/driver.py, e2e/driver.py）| 活跃 |
| `write_json` | 12 | 活跃 |
| `write_text` | 25 | 活跃 |

**结论：`__init__.py` 所有函数均有调用者，无死代码。**

说明：`result_date_stamp` 和 `smoke_output_path` 之前被认为无调用者（搜索范围限于 runner/），实际由 `micro/driver.py` 和 `e2e/driver.py` 使用。

### 2.4 其他潜在死代码

AST 扫描（限于 runner/libs、runner/suites）发现的"疑似死代码"均为以下情况：
- **接口方法**：`run_workload_spec`、`pid`、`program_fds`、`last_workload_details` 等——通过 ABC 基类或 `get_app_runner()` 动态调度
- **字符串分发**：`generate_*` 函数——通过 `GENERATORS` dict（`_build_generators()` 反射注册）调用
- **`enable_bpf_stats`**：定义在 `bpf_stats.py`，被 `_common.py:ensure_bpf_stats_enabled` 间接调用（通过 `sysctl` 命令而非 Python 直接调用）
- **`float_summary`**：定义在 statistics.py，在 results.py 早期版本中使用，现已从 results.py 的 import 中删除，但 statistics.py 本身其他地方还引用，且属于工具库函数

**真正可删的候选：无**（所有扫描出的项都有间接调用路径或接口要求）

---

## 3. 30 个文件改动分类汇总表

| 文件 | 类型 | 主要改动 |
|---|---|---|
| `Makefile` | 重构+bugfix | 多 --bench 参数支持（comma split）；make check 扩展至更多文件；ARM64 内核构建清理零大小 .o 文件 |
| `e2e/cases/scx/case.py` | bugfix | 在 artifacts 中同时写入 `programs` 和 `scheduler_programs` 键 |
| `runner/containers/runner-build.Dockerfile` | 重构 | 移除 golang RPM 包，改为从 go.dev 安装精确版本（GO_VERSION ARG） |
| `runner/containers/runner-runtime.Dockerfile` | bugfix | 新增 glog、curl-minimal 依赖（运行时缺少） |
| `runner/libs/__init__.py` | 清理 | 将 `result_date_stamp` + `smoke_output_path` 移至文件末尾（不改逻辑，只调整位置） |
| `runner/libs/app_runners/process_support.py` | 清理 | 删除文件末尾多余空行 |
| `runner/libs/app_runners/scx.py` | bugfix+重构 | 新增 `_discover_live_scheduler_programs()` 解决 SCX 程序引用在 rejit 后丢失 PID owner 问题；`_dup_program_fds` 新增 `require_owner` 参数；删除 `threading` import |
| `runner/libs/app_runners/tracee.py` | bugfix | 捕获 `ENODATA` errno（tracee 管道在 KVM 下读到 EOS 时抛出此错误），防止 tracee 输出收集线程崩溃 |
| `runner/libs/aws_common.py` | 清理 | 删除 `_remote_helper_local_path`、`_remote_helper_remote_path`、`_ensure_remote_helper`、`_run_remote_helper`（已被 docker 传输方式替代）；`_ssh_base_args` 去掉无用 ip 参数；`_scp_to/_scp_from` 去掉 `recursive` 参数 |
| `runner/libs/aws_executor.py` | 重构 | 用 docker image 替代 rsync 传输内核文件（`_build_and_push_kernel_image`）；重构 `_setup_instance` |
| `runner/libs/aws_remote_host.py` | 清理 | **整文件删除**（235 行，功能已被 aws_executor 内联的 docker 传输取代） |
| `runner/libs/bpf_stats.py` | 清理 | 从 `__all__` 中删除 `read_program_stats`（已非公开 API） |
| `runner/libs/input_generators.py` | bugfix | `_build_simple_lcg_u64_ii` 修复：`meta_b_key=="seed"` 时返回 seed 而非 header_b |
| `runner/libs/metrics.py` | 清理 | 从 `__all__` 中删除 `enable_bpf_stats`（通过 `_common.ensure_bpf_stats_enabled` 间接调用，非公开 API） |
| `runner/libs/results.py` | 清理 | 删除 `parse_json_lines`、`parse_runner_samples`、`normalize_runner_sample`（77 行，已移至 case_common 或不再使用） |
| `runner/libs/run_artifacts.py` | 清理 | 小幅清理（1 行变更） |
| `runner/libs/run_contract.py` | 清理 | 删除 `kernel_stage_dir`、`swap_size_gb` 字段及对应 env var（`RUN_REMOTE_KERNEL_STAGE_DIR`、`RUN_REMOTE_SWAP_SIZE_GB`） |
| `runner/libs/suite_commands.py` | 清理 | 删除不再使用的 `env_with_cross_runtime_ld` 相关调用（3 行） |
| `runner/libs/workload.py` | bugfix | 新增 `_ensure_null_blk_device_node()` 修复 KVM 内 `/dev/nullb0` 设备节点自动创建问题 |
| `runner/mk/build.mk` | 重构 | 同步 build.mk 与 Makefile 的 ARM64 内核构建清理逻辑 |
| `runner/suites/_common.py` | bugfix+清理 | `run_in_runtime_container` 传递 TMPDIR/TMP/TEMP 环境变量进容器；`suite_runtime_ld_library_path` 只保留 luajit 路径，去掉宽泛的 artifact lib 目录；将 `env_with_cross_runtime_ld` 重命名为 `env_with_suite_runtime_ld` 并改用 suite 路径；`base_suite_runtime_env` 不再主动设置 LD_LIBRARY_PATH |
| `runner/suites/corpus.env` | 清理 | 删除 `SUITE_DEFAULT_REMOTE_COMMANDS=curl,file,ip,tar,taskset`（已废弃，不再读取） |
| `runner/suites/corpus.py` | 清理 | 更新 import：`env_with_cross_runtime_ld` → `env_with_suite_runtime_ld` |
| `runner/suites/e2e.env` | 清理 | 删除 `SUITE_DEFAULT_REMOTE_COMMANDS` |
| `runner/suites/e2e.py` | 清理 | 同上 import 更新 |
| `runner/suites/micro.env` | 清理 | 删除 `SUITE_DEFAULT_REMOTE_COMMANDS=taskset` |
| `runner/suites/test.env` | 清理 | 删除 `SUITE_DEFAULT_REMOTE_COMMANDS=insmod,ip,taskset` 及 5 个 SUITE_DEFAULT_* 变量（值已移入 suite_args.py 硬编码默认值） |
| `runner/suites/test.py` | 清理 | import 更新 |
| `runner/targets/aws-arm64.env` | 清理 | 删除 `TARGET_REMOTE_KERNEL_STAGE_DIR_DEFAULT` 和 `TARGET_REMOTE_SWAP_SIZE_GB_DEFAULT` |
| `runner/targets/aws-x86.env` | 清理 | 同上 |

---

## 4. 最终行数变化（源码文件，排除结果数据）

```
total inserted: 412
total deleted:  575
net:            -163 行
```

删除量主要来自：
- `aws_remote_host.py` 整文件删除：-235 行
- `results.py` 删除三个函数：-77 行
- `aws_common.py` 删除 remote helper 函数群：-41 行
- `run_contract.py` 删除废弃字段：-9 行

新增量主要来自：
- `aws_executor.py` docker 传输逻辑：+176 行（替代了 aws_remote_host.py 的 235 行，更内聚）
- `workload.py` 新增 `_ensure_null_blk_device_node`：+22 行（bugfix）
- `scx.py` 新增 `_discover_live_scheduler_programs` 等：+63 行（bugfix）
- `Makefile` 新增 make check 覆盖范围和 ARM64 清理：+31 行

---

## 5. 总结

- **正确性**：全部 import 通过，make check 通过，无任何已删除符号的悬挂引用
- **死代码**：本轮已彻底清理（aws_remote_host.py 删除，results.py 3 函数删除，aws_common.py 4 函数删除，run_contract.py 2 字段删除）
- **仍可删候选**：无（所有扫描出的"疑似死代码"均有间接调用路径）
- **主要 bugfix**：tracee ENODATA、workload nullb0 设备节点、scx 程序引用 refresh、input_generator seed 字段修复
