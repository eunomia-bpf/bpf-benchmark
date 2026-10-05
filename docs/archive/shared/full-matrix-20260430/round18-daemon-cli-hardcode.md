# Round 18: Daemon CLI 硬编码（删除所有非必要 CLI arg）

## 改前 daemon CLI

```
bpfrejit-daemon serve [--socket <path>] [--failure-root <path>] [--cli-dir <path>] [--keep-all-workdirs]
```

`serve` 是唯一 subcommand，携带 4 个 CLI arg（其中 `--failure-root` 实际上是必填）。

## 改后 daemon CLI

```
bpfrejit-daemon [--help] [--version]
```

零自定义 arg，无 subcommand。`--help` / `--version` 由 clap 自动提供。

## 删除内容

| 删除项 | 归宿 |
|---|---|
| `serve` subcommand | 删除，daemon 只做一件事 |
| `--socket <path>` | 硬编码 `/var/tmp/bpfrejit-daemon.sock` |
| `--failure-root <path>` | 硬编码 `/var/tmp/bpfrejit-failures` |
| `--cli-dir <path>` | 删除，依赖 PATH（容器内 bpfopt/bpfprof 已在 PATH） |
| `--keep-all-workdirs` | 删除，死代码路径一起移除 |

## 硬编码路径选择理由

- **socket**: `/var/tmp/bpfrejit-daemon.sock`
  - `/var/tmp` 比 `/tmp` 跨 reboot 存活更久，更适合单 session daemon
  - `/var/run` 在容器内通常需要 root 且易被 tmpfs 覆盖，放弃
  - 与 runner Python `_daemon_runtime_root()` 已用 `/var/tmp/bpfrejit-daemon` 一致
- **failure root**: `/var/tmp/bpfrejit-failures`
  - daemon 与 runner 解耦，runner 不再需要知道失败目录在哪
  - 对应 docker bind mount：`-v <host-failures>:/var/tmp/bpfrejit-failures`（可选）

## 删除的 Rust dead code

- `KEEP_ALL_WORKDIRS: AtomicBool` static（commands.rs）
- `DEBUG_WORKDIR_ROOT_NAME` 常量（commands.rs）
- `preserve_debug_workdir_if_requested()` 函数（commands.rs）
- `init_keep_all_workdirs()` 函数（commands.rs）
- `init_cli_dir(Option<PathBuf>)` 参数 → 改为 `init_cli_dir()`（无参数，始终传 None）
- `Command::Serve { ... }` enum variant 及所有字段（main.rs）
- `Subcommand` derive 和 clap Subcommand import（main.rs）

## runner Python 端变化

**runner/libs/rejit.py**:
- `_start_daemon_server()`: 删除 `failure_root` / `keep_all_workdirs` 参数，daemon 启动命令简化为 `[str(daemon_binary)]`（无 arg）
- `_DAEMON_SOCKET_PATH = Path("/var/tmp/bpfrejit-daemon.sock")` 常量替代动态 socket path
- `_stop_daemon_server()`: 删除 `socket_path` 参数，直接用 `_DAEMON_SOCKET_PATH`
- `DaemonSession.start()`: 删除 `failure_root` / `keep_all_workdirs` 参数

**corpus/driver.py**:
- 删除 `failure_root = output_json.parent / "failures"` 赋值
- 删除 `keep_all_workdirs = os.environ.get(...)` 赋值
- `DaemonSession.start(...)` 调用简化

**e2e/driver.py**:
- 同上，两处 `DaemonSession.start()` 都简化

## 验证结果

```
cargo build --release --workspace  => 0 warnings 0 errors
cargo test --release --workspace   => 35 passed, 0 failed
python3 -m py_compile runner/libs/*.py corpus/*.py e2e/*.py => ALL OK
grep CLI arg strings                => 0 matches
```
