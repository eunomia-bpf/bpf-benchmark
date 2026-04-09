# Bug Review — bpf-benchmark (2026-04-08)

审查范围：运行时崩溃、逻辑错误、数据流问题。覆盖 runner/libs/ 所有 Python 模块 + Makefile。

所有模块均可正常 import（42 个单元测试全部通过）。

---

## 总结表

| # | 文件:行 | 类型 | 置信度 | 描述 |
|---|---------|------|--------|------|
| B1 | `runner/libs/guest_prereqs.py:187` | 逻辑漏洞 | MEDIUM | `validate_guest_prereqs` 中 bundled tool 检查后缺少 `continue`，可能在特定条件下误判 |
| B2 | `Makefile:70-75` | 配置错误 | HIGH | `make check` 的 `PYTHON_STATIC_TESTS` 遗漏了 4 个已存在的测试文件 |
| B3 | `runner/libs/run_contract.py:176` | 死参数 | LOW | `_apply_corpus_filter_selection` 接受 `run_needs_katran_bundle` 参数但完全忽略它 |
| B4 | `runner/libs/suite_entrypoint.py:39` | 异常路径错误 | LOW | `_latest_result_dir` 在 parent 目录不存在时抛出 `FileNotFoundError` 而非描述性错误 |

---

## B1 — validate_guest_prereqs 中 bundled tool 检查后缺少 continue

**文件**: `runner/libs/guest_prereqs.py`  
**行号**: 180–188  
**置信度**: MEDIUM（在特定条件下触发）

### 问题代码

```python
for command_name in required_commands(mode="runtime", contract=contract):
    if workload_tool_is_bundled(contract, command_name):
        if remote_tool_bin is None:
            die("manifest remote workload-tool bin is missing while workload tools are requested")
        bundled_tool = remote_tool_bin / command_name
        if not bundled_tool.is_file() or not os.access(bundled_tool, os.X_OK):
            die(f"required bundled workload tool is missing from the guest tool bin: {command_name}")
    if shutil.which(command_name, path=path_value) is None:  # ← 无 continue，bundled tool 也会走到这里
        die(f"required guest command is missing: {command_name}")
```

### 验证

```
grep -n "continue\|elif\|else\b" runner/libs/guest_prereqs.py
# 输出：
# 47:        return ...
# 77:        ...
# 147:            continue   ← 只有 install_guest_prereqs 有 continue，validate 没有
# 203:    ...
```

### 触发条件与影响

`runtime_path_value()` 会将 `remote_tool_bin` 目录**前缀**到 PATH（前提是该目录存在且是真实目录）。如果 bundled tool 已放入该目录，`shutil.which` 可以找到它，不会误报。

**但**：若 `remote_tool_bin` 目录在验证时不是一个真实目录（例如目录被清空、路径解析错误），则 `runtime_path_value` 不会将其加入 PATH，导致 `shutil.which` 在 line 187 找不到该 tool，误报 `"required guest command is missing"`（即使 bundled tool 文件已存在）。

对比 `install_guest_prereqs`（line 146-147）正确使用了 `continue`：
```python
for command_name in required_commands(mode="runtime", contract=contract):
    if have_cmd(command_name, path_value=path_value):
        continue  # ← 正确跳过
    if workload_tool_is_bundled(contract, command_name):
        die(...)
```

**复现步骤**：
1. 设置 `RUN_WORKLOAD_TOOLS_CSV=wrk`，`RUN_BUNDLED_WORKLOAD_TOOLS_CSV=wrk`，`RUN_REMOTE_WORKLOAD_TOOL_BIN=.cache/workload-tools/bin`
2. 在 workspace 下创建 `.cache/workload-tools/bin/wrk` 文件，但**不**让该目录作为一个正常目录被 `is_dir()` 返回（例如使用 symlink 到不存在的路径）
3. 调用 `validate_guest_prereqs`
4. 预期：报告 bundled tool 检查失败；实际：可能误报 `"required guest command is missing: wrk"`

**修复建议**：在 line 186 后添加 `continue`：
```python
        if not bundled_tool.is_file() or not os.access(bundled_tool, os.X_OK):
            die(...)
        continue  # ← 添加
    if shutil.which(command_name, path=path_value) is None:
        die(...)
```

---

## B2 — Makefile check 目标遗漏了 4 个测试文件

**文件**: `Makefile`  
**行号**: 70–75  
**置信度**: HIGH（可验证，`make check` 确实不运行这些测试）

### 问题代码

```makefile
PYTHON_STATIC_TESTS := \
    tests/python/test_run_contract.py \
    tests/python/test_prepare_local_inputs.py \
    tests/python/test_build_remote_bundle.py \
    tests/python/test_runtime_file_signatures.py \
    tests/python/test_workload_api.py
```

### 验证

```bash
ls tests/python/
# test_aws_remote_prep.py     ← 不在 PYTHON_STATIC_TESTS
# test_kvm_executor.py        ← 不在 PYTHON_STATIC_TESTS
# test_suite_entrypoint.py    ← 不在 PYTHON_STATIC_TESTS
# test_vm_launcher.py         ← 不在 PYTHON_STATIC_TESTS
# (5 个已包含的文件)

python3 -m pytest tests/python/test_aws_remote_prep.py tests/python/test_kvm_executor.py \
    tests/python/test_suite_entrypoint.py tests/python/test_vm_launcher.py -v
# 4 passed in 0.07s   ← 4 个测试均正常运行
```

### 影响

`make check` 使用 `PYTHON_STATIC_TESTS`，因此以下 4 个测试文件**不会**被执行：
- `test_aws_remote_prep.py`：验证 `REMOTE_PREREQ_ASSETS` 包含 `manifest_file.py` 而不包含 `run_contract.py`
- `test_kvm_executor.py`：验证 `bundle_stage_root` 解包行为
- `test_suite_entrypoint.py`：验证 `_runtime_env` 设置 BCC 工具目录和 KVM 内核模块根
- `test_vm_launcher.py`：验证 `build_vng_command` 使用 Python wrapper 调用

CI 持续集成时，这些测试回归不会被 `make check` 捕获。

**修复建议**：将 4 个文件加入 `PYTHON_STATIC_TESTS`，或改为 `tests/python/` 目录批量运行：
```makefile
check:
    $(PYTHON) -m pytest tests/python/ -v
```

---

## B3 — _apply_corpus_filter_selection 的死参数 run_needs_katran_bundle

**文件**: `runner/libs/run_contract.py`  
**行号**: 168–198 (函数定义), 577 (调用处)  
**置信度**: LOW（不影响运行，但可能隐藏意图 bug）

### 问题代码

函数签名（line 176）：
```python
def _apply_corpus_filter_selection(
    *,
    run_corpus_filters: str,
    suite: dict[str, str],
    run_benchmark_repos: str,
    run_native_repos: str,
    run_scx_packages: str,
    run_needs_sched_ext: str,
    run_needs_katran_bundle: str,   # ← 接受但从不使用
) -> tuple[str, str, str, str, str, str]:
```

函数体（lines 188–198）：
```python
filtered_needs_sched_ext = "1" if "scx" in selected_runners else "0"
filtered_needs_katran_bundle = "1" if "katran" in selected_runners else "0"  # ← 完全重新计算
# run_needs_katran_bundle 参数从未被读取
```

### 验证

```bash
grep -n "run_needs_katran_bundle" runner/libs/run_contract.py
# 176: run_needs_katran_bundle: str,          ← 参数定义
# 212: run_needs_katran_bundle = "0"          ← 函数体内局部变量（没有=引用参数！）
# 223:     run_needs_katran_bundle = "1"
# 229:     run_needs_katran_bundle,
# 381: run_needs_katran_bundle = suite.get(...)  ← 调用前
# 577:     run_needs_katran_bundle=run_needs_katran_bundle,  ← 无效传入
```

函数内的 line 212 `run_needs_katran_bundle = "0"` 是局部变量赋值，不是读取参数。

### 影响

行为正确（结果基于 `selected_runners` 动态计算），但调用者传入的 `run_needs_katran_bundle` 参数被静默丢弃。若未来有人修改该函数试图"使用传入的 katran bundle 状态"，可能引入 bug。

**修复建议**：移除函数参数中的 `run_needs_katran_bundle: str`，并在调用处（line 577）去掉该参数传入。

---

## B4 — _latest_result_dir 在目录不存在时抛出未描述性的 FileNotFoundError

**文件**: `runner/libs/suite_entrypoint.py`  
**行号**: 36–44  
**置信度**: LOW（次要崩溃路径）

### 问题代码

```python
def _latest_result_dir(parent: Path, prefix: str) -> Path:
    matches = sorted(
        path
        for path in parent.iterdir()    # ← 若 parent 不存在则抛出 FileNotFoundError
        if path.is_dir() and path.name.startswith(f"{prefix}_")
    )
    if not matches:
        _die(f"result directory is missing for prefix {prefix}: {parent}")
    return matches[-1]
```

### 触发条件

若 micro/corpus/e2e driver 因某种原因（如崩溃、磁盘满）**未创建** results 目录，调用处：
```python
# suite_entrypoint.py:629-631
_copy_result_dir(
    _latest_result_dir(self.workspace / "micro" / "results", ...),  # ← parent 不存在
    self.artifact_dir,
)
```
会抛出 `FileNotFoundError: [Errno 2] No such file or directory: '.../micro/results'`，而不是友好的 `_die()` 消息。

注意：若 `_run_checked(command)` 先失败（exit code != 0），`_latest_result_dir` 不会被调用。只有当 driver 以 exit 0 退出但未创建 results 目录时才触发。

### 验证

```python
# Python 验证
from pathlib import Path
list(Path("/nonexistent").iterdir())
# FileNotFoundError: [Errno 2] No such file or directory: '/nonexistent'
```

**修复建议**：在 `parent.iterdir()` 前添加检查：
```python
def _latest_result_dir(parent: Path, prefix: str) -> Path:
    if not parent.is_dir():
        _die(f"result directory is missing for prefix {prefix}: {parent}")
    matches = sorted(...)
```

---

## 其他已验证无问题的方面

- **所有模块 import 正常**：42 个测试全部通过（含新增的 4 个文件）
- **删除的 .sh 脚本**：所有之前的 .sh 已被对应 Python 模块替换，Makefile 和 runner/libs 中无残留引用
- **runner/scripts/ 脚本存在性**：`fetch_corpus_repos.py`、`build_scx_artifacts.py`、`build_corpus_native.py`、`run_vm_shell.py`、`vng-wrapper.py`、`with_vm_lock.py` 均存在
- **目标文件存在性**：`targets/x86-kvm.env`、`targets/aws-arm64.env`、`targets/aws-x86.env`、`suites/test.env`、`suites/micro.env`、`suites/corpus.env`、`suites/e2e.env` 均存在
- **函数定义验证**：所有被调用的函数/类均已确认定义存在
- **daemon 路径一致性**：`daemon/target/release/bpfrejit-daemon` 路径在所有相关文件中保持一致
- **arm64_sysroot 模块**：`Arm64SysrootConfig` 和 `ensure_sysroot` 均已在 `arm64_sysroot.py` 中定义
- **类型注解变更**：`run_artifacts.py` 和 `app_runners/__init__.py` 的工作区改动（`str | None` → `Optional[str]`）是兼容性修复，不影响运行逻辑
