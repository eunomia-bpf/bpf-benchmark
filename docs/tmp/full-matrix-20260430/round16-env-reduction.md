# Round 16 - BPFREJIT_* Env Var 减少审计

## 全量清单

### 删除（已彻底删除）

| 变量 | 原用途 | 决策原因 |
|------|--------|----------|
| `BPFREJIT_RUNTIME_TMPDIR` | `setup_tmpdir()` 把它设成 `TMPDIR` 的同义词，所有读者优先查这个再查 TMPDIR | **完全冗余**：始终等于 `TMPDIR`；删掉赋值，所有读者改为直接用 `TMPDIR` |
| `BPFREJIT_PROGS_DIR` | `test.py` 设置，但无任何读者（C 测试用 `argv[1]`） | **死代码**：设而不读，直接删 |
| `BPFREJIT_DAEMON_PATH` | `test.py` 设置，但无任何读者 | **死代码**：设而不读，直接删 |

### 改为 CLI arg（env 消失，改用 `--keep-all-workdirs`）

| 变量 | 原用途 | 新机制 |
|------|--------|--------|
| `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` | daemon 读取 env，决定是否保留所有 per-prog workdir | daemon 改为读取 `--keep-all-workdirs` CLI flag；`corpus/driver.py` 和 `e2e/driver.py` 读取 env 后转成 flag 传给 `DaemonSession.start()`；daemon 内用 `AtomicBool` 全局替代 env 读取 |

> 注意：`BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` 仍需从 host 传进容器（`suite_commands.py` passthrough），因为 driver.py 在容器内读取它。但 daemon 本身不再读 env。

### 保留（合理 env）

| 变量 | 原因 |
|------|------|
| `BPFREJIT_BENCH_PASSES` | CI/dev override pass list，有合理使用场景 |
| `BPFREJIT_INSIDE_RUNTIME_CONTAINER` | Docker 容器检测，容器 ENV 指令设置 |
| `BPFREJIT_IMAGE_WORKSPACE` | 容器内 workspace 路径，Dockerfile ENV 指令设置 |
| `BPFREJIT_REPO_ARTIFACT_ROOT` | app runner 定位 artifact；跨进程边界必须 |
| `BPFREJIT_REMOTE_PYTHON_BIN` | katran runner 定位 python binary；跨进程边界 |
| `BPFREJIT_KERNEL_MODULES_ROOT` | kernel module 路径；跨进程边界 |
| `BPFREJIT_WORKLOAD_TOOL_BIN_DIR` | workload tool binary 路径；可能不存在时跳过 |
| `BPFREJIT_MICRO_PROGRAM_DIR` | micro suite BPF 程序目录；driver 读取 |
| `BPFREJIT_MICRO_RUNNER_BINARY` | micro suite runner binary；driver 读取 |
| `BPFREJIT_MAP_INLINE_DEBUG` | bpfopt debug flag（不影响正确性） |
| `BPFREJIT_DAEMON_REQUEST_TIMEOUT_S` | socket timeout 调参 |
| `BPFREJIT_BCC_COMPAT_HEADER` / `BPFREJIT_BCC_EXTRA_CFLAGS` | BCC Python compat header 路径；子进程继承 |
| `BPFREJIT_TRACEE_RUNTIME_DIR` | tracee 运行时目录显式 override |
| `BPFREJIT_VM_DOCKER_ROOT/DISK/DISK_SIZE` | VM 层 Docker 配置 |
| `BPFREJIT_IMAGE_BUILD` | Makefile build phase 标志 |
| `BPFREJIT_INSTALL_*` | installer 脚本专用 |

### 关于 IMAGE_WORKSPACE 暂留

`BPFREJIT_IMAGE_WORKSPACE` 在 `runner-runtime.Dockerfile` 里写死为 `${IMAGE_WORKSPACE}` build arg（默认 `/home/yunwei37/workspace/bpf-benchmark`）。这是 user-path 硬编码问题，改成 `/workspace/bpf-benchmark` 需要同步改 Dockerfile + 所有相关路径，属于较大改动，暂留。

## 变更文件详细

| 文件 | 变更 |
|------|------|
| `daemon/src/main.rs` | 新增 `--keep-all-workdirs` bool flag，传给 `cmd_serve` |
| `daemon/src/commands.rs` | 删 `KEEP_ALL_WORKDIRS_ENV` 常量和 `keep_all_workdirs_enabled_from_env()` 函数；新增 `static KEEP_ALL_WORKDIRS: AtomicBool` 和 `init_keep_all_workdirs()`；`preserve_debug_workdir_if_requested` 改读 AtomicBool |
| `daemon/src/server.rs` | `cmd_serve` 接受 `keep_all_workdirs: bool`，调用 `init_keep_all_workdirs` |
| `runner/libs/rejit.py` | `_start_daemon_server` 和 `DaemonSession.start` 新增 `keep_all_workdirs` 参数；读到 true 时追加 `--keep-all-workdirs` 到 cmd |
| `corpus/driver.py` | 新增 `import os`；读 `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` env 传给 `DaemonSession.start()` |
| `e2e/driver.py` | 新增 `import os`；读 `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` env 传给两处 `DaemonSession.start()` |
| `runner/suites/_common.py` | `setup_tmpdir` 删除 `env["BPFREJIT_RUNTIME_TMPDIR"] = env["TMPDIR"]` 赋值行 |
| `runner/libs/app_runners/bcc.py` | 两处读 `BPFREJIT_RUNTIME_TMPDIR` 改为读 `TMPDIR` |
| `runner/libs/app_runners/tracee.py` | 读 `BPFREJIT_RUNTIME_TMPDIR` 改为读 `TMPDIR` |
| `runner/libs/app_runners/otel_profiler.py` | env 探测列表删 `BPFREJIT_RUNTIME_TMPDIR` |
| `runner/libs/workload.py` | `_disk_backed_tmp_root` candidates 删 `BPFREJIT_RUNTIME_TMPDIR` |
| `runner/suites/test.py` | 删 `BPFREJIT_PROGS_DIR` 和 `BPFREJIT_DAEMON_PATH` 赋值；删 `resolve_daemon_binary` import |

## 验证

- `cargo build --release --workspace --manifest-path daemon/Cargo.toml` — 0 warning, 0 error
- `cargo test --release --workspace --manifest-path daemon/Cargo.toml` — 35/35 pass
- `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml` — 0 warning, 0 error
- `python3 -m py_compile` 全部目标文件通过
- `grep -rn BPFREJIT_RUNTIME_TMPDIR .` — 空（已彻底删除）
- `grep -rn BPFREJIT_PROGS_DIR\|BPFREJIT_DAEMON_PATH .` — 空（已彻底删除）
