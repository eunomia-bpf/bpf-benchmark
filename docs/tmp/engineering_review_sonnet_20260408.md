# BPF-Benchmark 工程质量复查报告

**审查日期**: 2026-04-08  
**审查员**: Claude Sonnet 4.6  
**范围**: 全项目 Python 代码、Makefile、YAML 配置的深度检查  
**前提**: 本报告仅报告 Opus 前次审查**未发现**的新问题

---

## 汇总表

| 优先级 | 类型 | 位置 | 简述 |
|--------|------|------|------|
| P0 | 死代码 | `runner/libs/workload.py:287` | `run_python_http_loop()` 定义但从未调用 |
| P0 | 死代码 | `runner/libs/workload.py:301` | `_prepare_read_file()` 定义但从未调用 |
| P1 | Git 不一致 | `runner/libs/runner_artifacts.py` | staged 和 working tree 版本存在重大行为差异（LLVM 环境变量 API 不同） |
| P1 | Git 不一致 | `runner/libs/arm64_container_build.py` | staged 和 working tree 版本不一致（bpftool 返回值、spdlog 库） |
| P2 | Makefile 死变量 | `Makefile:48-50` | `DAEMON`、`DAEMON_ARGS`、`DAEMON_SOCKET` 已定义但无任何目标使用 |
| P2 | Makefile 未定义变量 | `Makefile:262` | `clean` 目标引用 `$(SMOKE_OUTPUT)` 但此变量从未定义 |
| P3 | 私有 API 越界引用 | `runner/libs/app_runners/tetragon_support.py:342` | 运行时从 `workload.py` 导入私有函数 `_parse_stress_ng_bogo_ops` |
| P3 | 导出冗余 | `runner/libs/workload.py.__all__` | 5 个函数在 `__all__` 中但从未被外部导入 |

---

## P0：死函数（从未被调用）

### `run_python_http_loop` — `workload.py:287`

**证据**：
```
grep -n "run_python_http_loop" runner/libs/workload.py
# 输出：287:def run_python_http_loop(...)
# 全文只有一处，即定义本身
```

全项目（`runner/`、`micro/`、`e2e/`、`tests/`）无任何文件导入或调用此函数。它也不在 `__all__` 中。

**函数签名**：`def run_python_http_loop(duration_s: int | float, url: str) -> WorkloadResult`

**建议**：删除此函数，或若有复用预期则移入 `__all__` 并补充测试。

---

### `_prepare_read_file` — `workload.py:301`

**证据**：
```
grep -n "_prepare_read_file" runner/libs/workload.py
# 输出：301:def _prepare_read_file(path: Path, size_mb: int = 64) -> None:
# 全文只有一处，即定义本身
```

同样在整个项目中无任何调用点。与它同级的 `_disk_backed_tmp_root`、`_load_kernel_module`、`_wait_for_block_device` 均有调用，唯此函数孤立存在。

**建议**：删除此函数。

---

## P1：Git staged/working-tree 不一致

### `runner/libs/runner_artifacts.py`（AM 状态）

`git status --short` 显示 `AM`（新文件已 staged，同时有 unstaged 修改），两个版本存在重大语义差异：

| 方面 | staged（旧）| working tree（新）|
|------|------------|-------------------|
| LLVM 解析入口 | `LLVM_DIR` + `LLVM_CONFIG` + `llvm-config --cmakedir` 多路径 | `RUN_LLVM_DIR`（主），`LLVM_DIR`（备） |
| `shutil` | 已导入（用于 `shutil.which`） | 已删除（不再需要） |
| `_build_llvmbpf_library` | 不存在 | 新增：独立构建 llvmbpf 静态库 |
| bpftool `OUTPUT=` | 无尾部斜杠 | 已加尾部斜杠 `OUTPUT={output_dir}/` |
| spdlog 支持 | 不支持 | 新增 `MICRO_LLVMBPF_SPDLOG_LIBRARY` |

**影响**：Python 运行时加载的是 working tree 版本（新 API），但 staged 版本（旧 API）尚未提交，若 `git stash` 或 `git reset` 则会退回旧 API，导致所有依赖 `RUN_LLVM_DIR` 的代码失效。

**建议**：立即 commit working tree 版本。

---

### `runner/libs/arm64_container_build.py`（MM 状态）

`git diff runner/libs/arm64_container_build.py` 显示两处 working tree 修改尚未 staged：

1. **`build_vendor_bpftool()` 返回值**：staged 返回 `None`，working tree 返回 `Path`（供 `build_bcc_artifacts()` 直接使用，避免重复构建）。
2. **spdlog 库路径**：working tree 在 `build_runner()` 中新增了查找 `libspdlogd.a`/`libspdlog.a` 并传递 `MICRO_LLVMBPF_SPDLOG_LIBRARY` 的逻辑；staged 版本没有。
3. **环境变量**：staged 传 `LLVM_CONFIG` + `LLVM_DIR`，working tree 传 `RUN_LLVM_DIR`。

**建议**：staged 与 working tree 协调一致后提交。

---

## P2：Makefile 问题

### 未定义变量 `SMOKE_OUTPUT`（`Makefile:262`）

**证据**：
```makefile
# Makefile:262
rm -f "$(SMOKE_OUTPUT)" "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
```

项目内所有 `.mk` 文件和主 Makefile 均无 `SMOKE_OUTPUT` 定义：
```
grep -rn "SMOKE_OUTPUT" Makefile runner/mk/
# 输出：仅 Makefile:262 一处，无定义
```

Make 对空变量不报错，只是 `clean` 时静默跳过。`smoke_output_path()` 函数仍存在于 `runner/libs/__init__.py` 并被 `micro/driver.py`、`e2e/driver.py` 使用，但路径通过 Python 生成，不依赖此 Makefile 变量。

**建议**：从 `clean` 目标中删除 `"$(SMOKE_OUTPUT)"` 这一项，或补充变量定义（若仍有 smoke 产物需清理）。

---

### 死变量 `DAEMON`、`DAEMON_ARGS`、`DAEMON_SOCKET`（`Makefile:48-50`）

**证据**：
```
grep "DAEMON" Makefile
# 输出：
# DAEMON_DIR := $(ROOT_DIR)/daemon       <- 仍被 cargo clean 使用
# DAEMON  ?= daemon/target/release/bpfrejit-daemon  <- 从未被展开
# DAEMON_ARGS ?=                         <- 从未被展开
# DAEMON_SOCKET ?= /tmp/bpfrejit.sock    <- 从未被展开
```

`DAEMON_DIR` 被 `cargo clean` 正确使用。但 `DAEMON`、`DAEMON_ARGS`、`DAEMON_SOCKET` 三个变量在 Makefile 的任何目标中均未被引用（疑似删除了启动 daemon 的旧目标但未清理变量定义）。

**建议**：删除 `DAEMON`、`DAEMON_ARGS`、`DAEMON_SOCKET` 三行定义，或恢复使用它们的目标。

---

## P3：代码质量问题

### 越界引用私有函数（`tetragon_support.py:342`）

**证据**：
```python
# runner/libs/app_runners/tetragon_support.py:342
from runner.libs.workload import _parse_stress_ng_bogo_ops  # noqa: PLC0415
```

这是一个运行时延迟导入，引用了 `workload.py` 中以单下划线开头的私有函数。该函数确实存在（`workload.py:115`），当前不会崩溃，但：
- 违反 Python 私有约定
- 任何对 `_parse_stress_ng_bogo_ops` 的重命名/重构都会导致静默失效（`noqa` 屏蔽了 lint 警告）
- 放在 `noqa` 注释的运行时导入难以追踪

**建议**：将 `_parse_stress_ng_bogo_ops` 加入 `workload.py` 的 `__all__` 并去掉下划线前缀，或将该逻辑内联到 tetragon_support 中。

---

### `workload.__all__` 中 5 个从未被外部导入的函数

通过脚本验证，以下函数在 `__all__` 中声明为公开 API，但整个项目（`.cache` 和 `__pycache__` 除外）无任何文件从外部导入它们：

```
run_rapid_bind_storm
run_rapid_connect_storm
run_rapid_open_storm
run_tcp_retransmit_load
run_vfs_create_write_fsync_load
```

其中：
- `run_rapid_bind_storm/connect_storm/open_storm`：仅作为 `run_bind_storm`、`run_connect_storm`、`run_open_storm` 的内部实现助手
- `run_tcp_retransmit_load`、`run_vfs_create_write_fsync_load`：仅通过 `run_named_workload()` 间接调用

**建议**：若无外部调用场景，将三个 `run_rapid_*` 移出 `__all__`（或改为私有）；`run_tcp_retransmit_load` 和 `run_vfs_create_write_fsync_load` 可保留（作为 named workload 的备用路径，语义上合理）。

---

## Info：测试代码异味


```python
monkeypatch.setattr(execute_workspace.SuiteEntrypoint, "from_contract", staticmethod(fake_from_contract))
```

`SuiteEntrypoint.from_contract` 实际上是 `@classmethod`（`suite_entrypoint.py:189`），但 monkeypatch 使用 `staticmethod()` 包装。功能上恰好可以工作（测试全部通过），但语义上混淆了 classmethod 和 staticmethod 的区别。

**建议**：改为 `monkeypatch.setattr(execute_workspace.SuiteEntrypoint, "from_contract", classmethod(fake_from_contract))`，或换用 `staticmethod` 但不假装它是 classmethod。

---

## 验证结论

- Opus 前次审查报告的问题（`_run_mixed_workload` 未定义、8 文件死导入、`setup_support.py` 未 git-add）**均已修复**
- 本次发现的问题主要集中在：死函数（2 个）、Makefile 清理残留（3 个死变量 + 1 个未定义变量）、git staged/working-tree 不一致（需尽快 commit）、私有 API 越界引用（1 处）

---

## 文件路径快速索引

| 文件 | 关键发现位置 |
|------|-------------|
| `runner/libs/workload.py` | L287 (`run_python_http_loop`), L301 (`_prepare_read_file`), `__all__` |
| `runner/libs/runner_artifacts.py` | staged vs working tree LLVM API 差异 |
| `runner/libs/arm64_container_build.py` | staged vs working tree 不一致 |
| `runner/libs/app_runners/tetragon_support.py` | L342 私有 API 导入 |
| `Makefile` | L48-50 (死变量), L262 (未定义 `SMOKE_OUTPUT`) |
