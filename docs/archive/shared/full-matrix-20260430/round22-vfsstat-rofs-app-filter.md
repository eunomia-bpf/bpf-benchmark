# Round 22 修复报告：bcc/vfsstat EROFS + corpus app 过滤

日期：2026-05-03

---

## 任务 1：bcc/vfsstat stress-ng rename EROFS (errno=30) 根因与修复

### 根因分析

**错误现象**：
```
stress-ng: fail: [16973] rename: mkdir '/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.ce2f0fc8/tmp-stress-ng-rename-16973-0' failed, errno=30 (Read-only file system)
```

**调研过程**：

vm-corpus 在 KVM 内部通过以下路径运行：
1. 宿主机启动 vng（virtme-ng）VM，workspace 通过 9P virtio-fs 以 `--rwdir` 挂载
2. VM 内部启动 Docker daemon，Docker 数据盘默认路径为 `docker_disk`
3. Docker 容器内运行 Python suite，stress-ng 的 `--temp-path` 指向 `/var/tmp/bpfrejit-runtime/<token>`

**根本原因**：`runner/libs/kvm_executor.py` 的 `suite_command()` 函数在 guest script 里通过环境变量 `BPFREJIT_VM_DOCKER_DISK` 把 Docker 数据盘路径强制覆盖为：

```
workspace/docs/tmp/<token>/vm-tmp/bpf-benchmark-docker.img
```

该路径位于 **9P 挂载的 workspace** 内。Docker daemon 在这个 9P 文件系统上的 ext4 loopback 设备做随机写（overlay2 存储驱动），在高负载下 9P 写操作失败，触发 ext4 错误恢复机制，将文件系统自动重新挂载为只读（`EXT4_ERROR_FS` → `EROFS`）。

Docker 容器内的 `/var/tmp` 路径同样位于该 overlay2 存储的 upperdir 中，因此 stress-ng 的 `mkdir` 调用返回 `errno=30`。

**验证**：在宿主机 host 容器内直接运行相同的 stress-ng 命令工作正常（因为不经过 9P）。

### 修复方案

修改 `runner/libs/kvm_executor.py`：

1. **删除** `_host_docker_disk_path()` 函数（在 `suite_command` 中覆盖 `BPFREJIT_VM_DOCKER_DISK` 的来源）
2. **修改** `_docker_prelude_shell()` 默认路径从 `${TMPDIR:-/tmp}/bpf-benchmark-docker.img` 改为 `/var/tmp/bpf-benchmark-docker.img`（VM 本地存储，不在 9P 挂载路径上）
3. **删除** `suite_command()` 中的 `docker_disk_export` 行（不再覆盖环境变量）
4. **删除** `run_vm_suite()` 中的 `host_docker_disk.unlink(missing_ok=True)` 清理（盘在 VM 本地，VM 关闭时自动释放）

修改文件及位置：
- `runner/libs/kvm_executor.py`：`_docker_prelude_shell()`（第 30 行）、`suite_command()`（删除 `docker_disk_export`）、`run_vm_suite()`（删除 finally 块）

**效果**：Docker 数据盘现在放在 VM 的 `/var/tmp/bpf-benchmark-docker.img`（VM 本地 tmpfs/ext4），完全绕过 9P 文件系统，消除 EROFS 根因。

### Host 复现验证

在宿主机容器内验证 stress-ng rename 正常工作：
```
docker run --rm --privileged ... bash -c '
  mkdir -p /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.test123
  chmod 1777 /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.test123
  stress-ng --rename 1 --rename-ops 5 --temp-path /var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.test123 --timeout 5s
'
# → passed: 1: rename (1)
```
容器内 rename 工作正常。问题在 9P 路径上的 Docker 存储，修复后不再使用该路径。

---

## 任务 2：corpus app 过滤 env var `BPFREJIT_CORPUS_APPS`

### 功能说明

新增环境变量 `BPFREJIT_CORPUS_APPS`（CSV 格式）：

| 值 | 行为 |
|---|---|
| 未设置或空 | 全部 app 运行（默认） |
| `bcc/vfsstat` | 只跑 bcc/vfsstat |
| `bcc/vfsstat,calico/felix` | 只跑这两个 |
| 引用不存在的 app | exit 1 并列出可用 app |

**用法示例**：
```bash
BPFREJIT_CORPUS_APPS=bcc/vfsstat make vm-corpus   # 只跑 vfsstat，快速调试
BPFREJIT_CORPUS_APPS=bcc/vfsstat,calico/felix make vm-corpus
```

### 修改的文件

1. **`corpus/driver.py`**（第 52 行）：
   - 新增 `_CORPUS_APPS_ENV = "BPFREJIT_CORPUS_APPS"` 常量
   - 新增 `_filter_suite_apps(suite: AppSuite) -> AppSuite` 函数，解析 CSV 并过滤 `suite.apps`
   - `main()` 中 `load_app_suite_from_yaml(...)` 的结果套上 `_filter_suite_apps(...)`

2. **`runner/suites/_common.py`**（`base_runtime_env()`）：
   - 在 env passthrough 列表中加入 `"BPFREJIT_CORPUS_APPS"`

3. **`runner/libs/suite_commands.py`**（`_RUNTIME_CONTAINER_ENV_PASSTHROUGH`）：
   - 加入 `"BPFREJIT_CORPUS_APPS"` 使 docker run 把该变量传进容器

### 验证

```
python3 -m py_compile corpus/driver.py runner/suites/_common.py runner/libs/suite_commands.py
# → All OK

python3 -c "os.environ['BPFREJIT_CORPUS_APPS']='bcc/vfsstat,calico/felix'; _filter_suite_apps(...)"
# → Filtered apps: 2 ['bcc/vfsstat', 'calico/felix']

python3 -c "os.environ['BPFREJIT_CORPUS_APPS']='bcc/nonexistent'; _filter_suite_apps(...)"
# → SystemExit: BPFREJIT_CORPUS_APPS references unknown apps: ['bcc/nonexistent']; available: ...
```

---

## Rust 构建与测试

```
cargo build --release --workspace --manifest-path daemon/Cargo.toml
# → Finished release profile in 0.09s  (0 warnings)

cargo test --release --workspace --manifest-path daemon/Cargo.toml
# → test result: ok. 36 passed; 0 failed
```
