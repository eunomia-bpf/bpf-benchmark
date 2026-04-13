# Final Review v2

Date: 2026-04-12

## 1. 逻辑正确性问题

### 已修复

**1. Makefile check target 引用已删除文件**
- `Makefile:135` 的 `check` target 中包含 `runner/libs/aws_remote_host.py`，但该文件已在本次 diff 中删除
- 修复：从 Makefile check target 中删除该行

**2. aws_executor.py 内部 import shlex**
- `_run_remote_suite()` 中有 `import shlex as _shlex` 局部导入，但 `shlex` 应该是顶层导入
- 修复：移至顶层，所有 `_shlex.` 改为 `shlex.`

**3. aws_executor.py 内部 import read_run_config_file**
- `_build_remote_suite_command()` 中有 `from runner.libs.run_contract import read_run_config_file` 局部导入
- 修复：移至顶层 `from runner.libs.run_contract import RunConfig, read_run_config_file`

**4. kernel_dest 变量两分支赋值相同**
- `_build_and_push_kernel_image()` 中 x86/arm64 两个分支对 `kernel_dest` 赋同一个值，违反 DRY
- 修复：提到 if/else 块之外，只对 `install_image_cmd` 做分支

### 验证通过（无问题）

- `aws_common.py` 删除 `_run_remote_helper`、`_ensure_remote_helper` 后，runner/ 内无残留引用
- `aws_remote_host.py` 已删除，runner/ 内（除 Makefile check 行，已修复）无其他 import 或引用
- `_common.py` 函数改名 `env_with_cross_runtime_ld` → `env_with_suite_runtime_ld`，corpus.py/e2e.py/test.py 全部更新
- test.py / corpus.py / e2e.py import 全部正确
- `run_contract.py` 删除 `kernel_stage_dir`、`swap_size_gb` 字段后，runner/ 内无残留引用
- `("",) * 19` 元组数量正确（原 21 个，删除 2 个后 19 个）
- `_ssh_base_args` 签名变更（删除 `ip` 参数），aws_common.py 内所有调用点都已更新
- `_scp_to`、`_scp_from` 删除 `recursive` 参数，所有调用点已更新

### import 验证

```
python3 -c "import runner.libs.aws_executor; ..." -> all imports: OK
```

所有关键模块 import 均通过。

## 2. 删除的死代码

### 本次审查新增删除（在原有 diff 基础上）

| 文件 | 删除内容 | 理由 |
|------|---------|------|
| `runner/libs/__init__.py` | `result_date_stamp()` (4 行) | 仅被 `smoke_output_path` 调用，而后者在 runner/ 内无调用者 |
| `runner/libs/__init__.py` | `smoke_output_path()` (2 行) | runner/ 内无任何调用者 |
| `runner/libs/__init__.py` | `write_json()` (3 行) | runner/ 内无调用者（Path.write_text 不算） |
| `runner/libs/__init__.py` | `write_text()` (3 行) | runner/ 内无调用者 |
| `runner/libs/__init__.py` | `from datetime import timezone` | 删除以上函数后 timezone 未使用 |
| `Makefile` | `runner/libs/aws_remote_host.py` check 行 | 文件已删除 |
| `runner/libs/aws_executor.py` | 内部 `import shlex as _shlex` | 改为顶层导入 |
| `runner/libs/aws_executor.py` | 内部 `from runner.libs.run_contract import read_run_config_file` | 改为顶层导入 |
| `runner/libs/aws_executor.py` | `kernel_dest` 重复赋值 (1 行) | 两分支赋同一值，合并为一行 |

### 原有 diff 已删除（确认无遗漏）

- `aws_remote_host.py` (235 行) - 整文件删除
- `_run_remote_helper()` / `_ensure_remote_helper()` / `_remote_helper_*()` (40 行) - aws_common.py 中删除
- `_verify_remote_base_prereqs()` / `_require_remote_base_prereqs()` / `_remote_required_commands()` / `_ordered_unique()` (30 行) - aws_executor.py 中删除
- `_sync_kernel_stage()` / `_setup_kernel_instance()` (30 行) - aws_executor.py 中删除，合并进 `_setup_instance()`
- `RUN_REMOTE_KERNEL_STAGE_DIR` / `RUN_REMOTE_SWAP_SIZE_GB` 字段 (多处)
- `_scp_to recursive` / `_scp_from recursive` 参数 (简化)
- LD_LIBRARY_PATH 各 lib 目录 (suite_runtime_ld_library_path 精简)
- `SUITE_DEFAULT_REMOTE_COMMANDS` / `SUITE_DEFAULT_FUZZ_ROUNDS` 等 env 键

## 3. 尚未删除（有调用者的函数）

以下函数看似内部但实际有调用者，保留正确：

- `remote_transfer_roots()` / `local_prep_targets()` - workspace_layout.py - 被 aws_executor.py 和 run_target_suite.py 调用
- `cross_runtime_ld_library_path()` - _common.py - 被 micro.py 和 suite_runtime_ld_library_path 调用
- `suite_runtime_ld_library_path()` - _common.py - 被 env_with_suite_runtime_ld 调用
- `cleanup_failed_run_for_config()` - aws_executor.py - 被 run_target_suite.py 调用
- `build_micro_suite_argv()` 等 4 个独立 builder - suite_commands.py - 被 build_suite_argv() 调用（dispatcher pattern）

## 4. 行数统计

### 核心文件

| 文件 | 行数 |
|------|------|
| runner/libs/aws_executor.py | 572 |
| runner/libs/aws_common.py | 166 |
| runner/libs/__init__.py | 149 (原 166) |
| runner/suites/_common.py | 405 |
| runner/libs/run_contract.py | 602 |
| runner/libs/suite_commands.py | 188 |
| runner/libs/workspace_layout.py | 174 |

### 净删除统计

- 原有 diff (不含本次): 370 insertions, 483 deletions = 净 -113 行
- 加上本次审查修改: 402 insertions, 505 deletions = 净 -103 行
- 本次审查新增净删除: ~22 行（修复 + 死代码删除）

## 5. Docker 内核安装逻辑验证

`_build_and_push_kernel_image()` 流程：
1. 本地 tmpdir 创建 docker build context
2. 复制 kernel image 到 ctx/kernel/boot/
3. **对 modules_root 做符号链接**（避免复制 GB 级数据）→ docker build 时 COPY 会跟随符号链接
4. FROM scratch + COPY kernel /kernel 构建最小镜像
5. docker save | ssh docker load 传输到远端
6. docker run --privileged -v /:/host 执行安装脚本

**已知风险点**：
- 符号链接指向 tmpdir 外的绝对路径，docker build 会跟随并复制。这对 modules 是有意为之，但意味着仍需复制 GB 级数据（只是避免了额外 rsync）
- arch="arm64" 分支在 `_die` 后 `kernel_release`/`arch` 理论上未绑定，但 `_die` 通过 `sys.exit` 终止进程，运行时安全

**逻辑正确**：`_setup_instance` 中 `arch` 变量在两个有效分支中都赋值，`else: _die(...)` 不会返回。
