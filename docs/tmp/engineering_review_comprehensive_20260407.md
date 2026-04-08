# 工程质量全面审查 (2026-04-07)

> 审查范围：shell-to-Python 重构后的 working tree 状态（非 git HEAD）。
> 所有路径均为工作树中实际存在的文件。

## 总结表

| ID | 优先级 | 类型 | 文件 | 行号 | 说明 |
|---|---|---|---|---|---|
| P0-1 | **P0** | 运行时崩溃 | `runner/libs/workload.py` | 866, 877 | `_run_mixed_workload` 被调用但从未定义 |
| P1-1 | P1 | 未使用导入 | `runner/libs/aws_remote_prep.py` | 5, 18, 19 | `subprocess`, `parse_manifest`, `read_state` 导入但未使用 |
| P1-2 | P1 | 未使用导入 | `runner/libs/aws_local_prep.py` | 31 | `run_command` 导入但未使用 |
| P1-3 | P1 | 未使用导入 | `runner/libs/kvm_local_prep.py` | 20 | `run_command` 导入但未使用 |
| P1-4 | P1 | 未使用导入 | `runner/libs/arm64_container_build.py` | 5, 6 | `pwd`, `grp` 导入但未使用 |
| P1-5 | P1 | 未使用导入 | `runner/libs/kvm_executor.py` | 3 | `os` 导入但未使用 |
| P1-6 | P1 | 未使用导入 | `runner/libs/case_common.py` | 21 | `ROOT_DIR` 导入但未使用 |
| P1-7 | P1 | 未使用导入 | `runner/libs/app_runners/bcc.py` | 12 | `Any` 导入但未使用 |
| P1-8 | P1 | 未使用导入 | `runner/libs/app_runners/__init__.py` | 6 | `Any` 导入但未使用 |
| P1-9 | P1 | 未使用导入 | `runner/libs/app_runners/katran_support.py` | 12 | `Any` 导入但未使用 |
| P1-10 | P1 | 未使用导入 | `runner/libs/app_runners/process_support.py` | 8 | `Callable` 导入但未使用 |
| P1-11 | P1 | 死变量 | `runner/libs/arm64_host_build.py` | 450, 452, 638-641 | `usr_lib`, `lib`, `lib64` 赋值但未使用 |
| P1-12 | P1 | 死变量 | `runner/libs/workload.py` | 770 | `requests_per_sec` 赋值但未使用 |
| P1-13 | P1 | 未跟踪文件 | `runner/libs/app_runners/setup_support.py` | - | 新文件未 git add，bcc.py 等依赖它 |
| P2-1 | P2 | 重复代码 | 16 个文件 | 各文件 | `_die()` / `die()` 函数重复定义 19 次 |
| P2-2 | P2 | 重复代码 | 3 个文件 | 各文件 | `_require_path` / `_require_nonempty_dir` 重复定义 |

---

## P0 -- 运行时崩溃

### P0-1: `_run_mixed_workload` 未定义（NameError）

**文件**: `runner/libs/workload.py`
**行号**: 866, 877

```python
# line 865-866
if kind == "mixed_system":
    return _run_mixed_workload(float(seconds))
# line 876-877
if kind == "system_telemetry_mix":
    return _run_mixed_workload(float(seconds))
```

**问题**: `_run_mixed_workload` 在整个文件中没有定义（`grep` 确认为 0 匹配）。
当 workload kind 为 `"mixed_system"` 或 `"system_telemetry_mix"` 时，
`run_named_workload()` 会立刻抛出 `NameError`。

**影响范围**: `run_named_workload` 被 `bcc.py`（line 25）等 app runner 调用。
如果 E2E/corpus 配置中指定了上述两种 workload，整个 benchmark run 会崩溃。

**证据**:
- pyflakes: `runner/libs/workload.py:866:16: undefined name '_run_mixed_workload'`
- pyflakes: `runner/libs/workload.py:877:16: undefined name '_run_mixed_workload'`
- `grep -n 'def _run_mixed_workload' runner/libs/workload.py` → 无结果

**建议操作**: 实现 `_run_mixed_workload` 函数，或将两个 `if` 分支改为调用已有的复合
workload（例如 `run_exec_storm` + `run_file_open_load` 交替）。

---

## P1 -- 死代码与未使用导入

### P1-1: aws_remote_prep.py 三处未使用导入

**文件**: `runner/libs/aws_remote_prep.py`

| 行号 | 导入 | 证据 |
|---|---|---|
| 5 | `import subprocess` | 全文无 `subprocess.` 调用 |
| 18 | `from runner.libs.run_contract import parse_manifest` | 全文无 `parse_manifest(` 调用 |
| 19 | `from runner.libs.state_file import read_state, write_state` | `read_state` 未使用（`write_state` 有使用） |

**建议**: 删除 `subprocess`、`parse_manifest`、`read_state` 导入。

### P1-2: aws_local_prep.py 未使用 `run_command`

**文件**: `runner/libs/aws_local_prep.py`, 行 31

```python
from runner.libs.local_prep_common import (
    ...
    run_command,   # <-- imported but never called in this file
    ...
)
```

**证据**: `grep -n 'run_command(' runner/libs/aws_local_prep.py` → 无匹配

**建议**: 从 import 列表中移除 `run_command`。

### P1-3: kvm_local_prep.py 未使用 `run_command`

**文件**: `runner/libs/kvm_local_prep.py`, 行 20

同 P1-2，`run_command` 导入但未使用。

**证据**: `grep -n 'run_command(' runner/libs/kvm_local_prep.py` → 无匹配

### P1-4: arm64_container_build.py 未使用 `pwd` 和 `grp`

**文件**: `runner/libs/arm64_container_build.py`, 行 5-6

```python
import pwd
import grp
```

**证据**: 全文无 `pwd.` 或 `grp.` 调用。

### P1-5: kvm_executor.py 未使用 `os`

**文件**: `runner/libs/kvm_executor.py`, 行 3

```python
import os
```

**证据**: 全文无 `os.` 调用。

### P1-6: case_common.py 未使用 `ROOT_DIR`

**文件**: `runner/libs/case_common.py`, 行 21

```python
from runner.libs import (
    ROOT_DIR,  # <-- not used anywhere in this file
    ...
)
```

**证据**: `grep -n '\bROOT_DIR\b' runner/libs/case_common.py` → 仅 import 行

### P1-7 ~ P1-10: app_runners 未使用类型导入

| ID | 文件 | 行号 | 未使用导入 |
|---|---|---|---|
| P1-7 | `runner/libs/app_runners/bcc.py` | 12 | `Any` |
| P1-8 | `runner/libs/app_runners/__init__.py` | 6 | `Any` |
| P1-9 | `runner/libs/app_runners/katran_support.py` | 12 | `Any` |
| P1-10 | `runner/libs/app_runners/process_support.py` | 8 | `Callable` |

这些文件都有 `from __future__ import annotations`，所以类型注解在运行时不需要这些名称。pyflakes 确认它们未被使用。

### P1-11: arm64_host_build.py 死变量赋值

**文件**: `runner/libs/arm64_host_build.py`

| 行号 | 变量 | 上下文 |
|---|---|---|
| 450 | `usr_lib` | `_build_scx_host_cross()` 函数 |
| 452 | `lib` | 同上 |
| 638 | `usr_lib` | `_build_workload_tools_host_cross()` 函数 |
| 640 | `lib` | 同上 |
| 641 | `lib64` | 同上 |

这些变量被赋值（如 `usr_lib = sysroot_root / "usr/lib"`）但后续从未引用。

### P1-12: workload.py 死变量 `requests_per_sec`

**文件**: `runner/libs/workload.py`, 行 770

```python
requests_per_sec = float(req_match.group(1))  # assigned, never read
```

解析 wrk 输出时赋值，但最终只使用 `total_requests`。

### P1-13: setup_support.py 未 git add

**文件**: `runner/libs/app_runners/setup_support.py`

`git status` 显示该文件为 `??`（untracked）。但以下文件已经依赖它：
- `runner/libs/app_runners/bcc.py` (line 31)
- `runner/libs/app_runners/tracee_support.py` (line 31)
- `runner/libs/app_runners/tetragon_support.py` (line 14)

**风险**: 如果在不做 `git add` 的情况下切换分支或 `git stash`，这些导入会断裂。

**建议**: 立即 `git add runner/libs/app_runners/setup_support.py`。

---

## P2 -- 重复/冗余代码

### P2-1: `_die()` / `die()` 函数重复 19 次

以下 19 个文件各自定义了几乎完全相同的 `_die(message) -> NoReturn` 函数，
唯一区别是 `[tag]` 前缀：

**`_die()`（16 处）:**
1. `runner/libs/run_target_suite.py:20`
2. `runner/libs/aws_remote_prep.py:22`
3. `runner/libs/build_upstream_selftests.py:17`
4. `runner/libs/execute_workspace.py:12`
5. `runner/libs/arm64_sysroot.py:14`
6. `runner/libs/kvm_executor.py:15`
7. `runner/libs/state_file.py:9`
8. `runner/libs/aws_executor.py:20`
9. `runner/libs/build_remote_bundle.py:17`
10. `runner/libs/arm64_kernel_config.py:11`
11. `runner/libs/run_contract.py:19`
12. `runner/libs/suite_entrypoint.py:20`
13. `runner/libs/prepare_local_inputs.py:14`
14. `runner/libs/arm64_host_build.py:16`
15. `runner/libs/portable_runtime.py:28`
16. `runner/libs/arm64_container_build.py:16`

**`die()`（3 处）:**
17. `runner/libs/guest_prereqs.py:12`
18. `runner/libs/aws_remote_prereqs.py:13`
19. `runner/libs/local_prep_common.py:18`

**建议**: 将 `_die` 提取到公共模块（如 `runner/libs/__init__.py`），
接受 `tag` 参数。当前 `local_prep_common.py` 的 `die()` 已经被多处导入使用，
可以考虑统一。但鉴于每个模块有不同的 tag 前缀，这属于 P2 优化，不影响功能。

### P2-2: `_require_path` / `_require_nonempty_dir` 重复 3 处

| 文件 | 函数名 |
|---|---|
| `runner/libs/local_prep_common.py:36,41` | `require_path`, `require_nonempty_dir` |
| `runner/libs/build_remote_bundle.py:22,27` | `_require_path`, `_require_nonempty_dir` |
| `runner/libs/arm64_host_build.py:95` | `_require_nonempty_dir` |
| `runner/libs/arm64_container_build.py:75` | `_require_nonempty_dir` |

`local_prep_common.py` 的版本已被 `aws_kernel_artifacts.py` 等模块导入使用。
`build_remote_bundle.py` 和 `arm64_host_build.py` 各自有私有副本。

**建议**: `build_remote_bundle.py` 和 `arm64_host_build.py` 中的副本可以改为
导入 `local_prep_common.py` 的公共版本。

---

## 已验证的"非问题"

以下可能被误报为问题的项目经验证后确认无误：

1. **Makefile .sh 引用**: 顶层 Makefile 和 runner/Makefile 中无任何对已删除 .sh 脚本的引用。
   Makefile 中唯一的 `.sh` 引用是 `$(KERNEL_DIR)/scripts/config`（Linux kernel 内置脚本）。

2. **`vng-wrapper.sh` → `vng-wrapper.py`**: `runner/targets/x86-kvm.env` 已更新为
   `TARGET_KVM_EXECUTABLE=runner/scripts/vng-wrapper.py`。

3. **`module/load_all.sh` 删除**: 虽然 `module/load_all.sh` 已从 git 删除，
   但所有 Python 代码使用 `runner/libs/kinsn.py` 的 `load_kinsn_modules()` 函数直接调用 `insmod`。
   无活跃代码引用 `load_all.sh`。（results JSON 中的历史引用不影响运行时。）

4. **`from __future__ import annotations` 下的 `"NoReturn"`**: pyflakes 报告了
   多个文件的 `undefined name 'NoReturn'`，但这些都是字符串注解（如 `-> "NoReturn"`），
   在 `from __future__ import annotations` 下合法，运行时不会出错。

5. **PYTHON_STATIC_TESTS**: Makefile 中列出的两个测试文件均存在且全部通过（14/14 PASSED）。

6. **CI workflows**: `.github/workflows/` 中的 YAML 文件不引用任何已删除的 .sh 脚本。

7. **e2e setup scripts**: `runner/libs/app_runners/tracee.py:23` 和 `tetragon.py:24` 引用
   `e2e/cases/*/setup.sh`，这些文件属于 e2e case 定义目录，不在本次删除范围内。

---

## 已删除测试文件

以下测试文件在 git status 中显示为已删除，但无其他代码依赖它们：

- `tests/python/test_build_remote_bundle.py`
- `tests/python/test_build_upstream_selftests.py`
- `tests/python/test_execute_workspace.py`
- `tests/python/test_run_target_suite.py`
- `tests/python/test_state_file.py`
- `tests/python/test_guest_prereqs.py`

这些测试覆盖的功能（`build_remote_bundle`、`state_file`、`guest_prereqs` 等）
在代码中仍然存在且被其他测试间接覆盖。建议在重构稳定后补回关键模块的单元测试。

---

## 测试验证结果

```
$ python -m pytest tests/python/test_run_contract.py tests/python/test_prepare_local_inputs.py -v
14 passed in 0.07s
```

所有现存测试通过。
