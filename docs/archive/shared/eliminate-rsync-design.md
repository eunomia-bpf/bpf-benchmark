# 彻底去掉 rsync 的设计方案

日期：2026-04-12

## 一、当前 rsync 用途清单

代码库中共有 **7 处** rsync 调用，分属两类：

### A. 远端传输类（跨网络传输到 AWS 实例）

| 位置 | 文件 | 函数 | 方向 | 用途 |
|---|---|---|---|---|
| A1 | `runner/libs/aws_common.py:142-147` | `_rsync_to` | 本地 → 远端 | 将 workspace 目录树（runner 代码、.ko、artifacts 等）同步到 AWS |
| A2 | `runner/libs/aws_common.py:150-156` | `_rsync_from` | 远端 → 本地 | 将 benchmark 结果目录从远端拉回本地 |
| A3 | `runner/libs/aws_executor.py:225` | `_sync_kernel_stage` | 本地 → 远端 | 将内核模块树 rsync 到远端暂存目录 |
| A4 | `runner/libs/aws_remote_host.py:101` | `cmd_setup_kernel_x86` | 远端本地 | sudo rsync 把模块从暂存目录安装到 /lib/modules/ |
| A5 | `runner/libs/aws_remote_host.py:124` | `cmd_setup_kernel_arm64` | 远端本地 | 同上，ARM64 版本 |

### B. 本地构建类（本地磁盘间的文件复制）

| 位置 | 文件 | 行号 | 用途 |
|---|---|---|---|
| B1 | `runner/mk/build.mk:388` | 构建 BCC 时：将源码 repo 同步到构建目录（保留 `.output`） |
| B2 | `runner/mk/build.mk:462` | 构建 Tracee 时：将源码 repo 同步到构建目录（保留 `dist/`、`build/`） |
| B3 | `runner/mk/build.mk:518` | 构建 Tetragon 时：将源码 repo 同步到构建目录 |
| B4 | `runner/mk/build.mk:571` | 构建 Katran 时：将源码 repo 同步到构建目录 |
| B5 | `runner/mk/build.mk:673` | 构建 workload-tools 时：将源码 repo 同步到构建目录 |

---

## 二、当前流程 vs 新流程对比

### A1/A3：workspace + kernel modules 传输（本地 → 远端）

**当前流程：**
```
本地 make 构建产物 → rsync -a 整个目录树 → 远端 remote_stage_dir/
                   → rsync -a kernel modules → 远端 kernel_stage_dir/lib/modules/
```

**新流程：**
```
本地 make 构建产物 → tar -czf 打包各 entry → ssh cat | tar -xzf 远端解压
```

核心思路：`_rsync_to` 替换为 `_tar_stream_to`，用 ssh pipe 流式传输 tar。

```python
# 替代 _rsync_to 的实现草稿
def _tar_stream_to(ctx, ip, src: Path, dest: str, *, excludes=()):
    tar_cmd = ["tar", "-czf", "-"]
    for ex in excludes:
        tar_cmd += ["--exclude", ex]
    tar_cmd += ["-C", str(src), "."]
    ssh_cmd = ["ssh", *_ssh_base_args(ctx, ip), f"{ctx.remote_user}@{ip}",
               f"mkdir -p {dest} && tar -xzf - -C {dest}"]
    tar_proc = subprocess.Popen(tar_cmd, stdout=subprocess.PIPE)
    ssh_proc = subprocess.Popen(ssh_cmd, stdin=tar_proc.stdout)
    tar_proc.stdout.close()
    ssh_proc.wait(); tar_proc.wait()
    if ssh_proc.returncode != 0 or tar_proc.returncode != 0:
        raise SystemExit(1)
```

对于小文件（单个 .py 等），继续用已有的 `_scp_to`，不变。

### A2：结果回传（远端 → 本地）

**当前流程：**
```
远端 results/ → rsync -a → 本地 results/
```

**新流程：**
```
远端 results/ → tar -czf - | ssh pipe → 本地 tar -xzf -
```

```python
# 替代 _rsync_from 的实现草稿
def _tar_stream_from(ctx, ip, src: str, dest: Path, *, excludes=()):
    dest.mkdir(parents=True, exist_ok=True)
    ex_args = " ".join(f"--exclude={shlex.quote(e)}" for e in excludes)
    remote_cmd = f"tar -czf - {ex_args} -C {shlex.quote(src)} ."
    completed = subprocess.run(
        ["ssh", *_ssh_base_args(ctx, ip), f"{ctx.remote_user}@{ip}", remote_cmd],
        stdout=subprocess.PIPE, check=False
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
    subprocess.run(["tar", "-xzf", "-", "-C", str(dest)],
                   input=completed.stdout, check=True)
```

或者流式实现（避免内存积压大量结果）：用 Popen pipe 同上。

### A4/A5：远端 sudo 安装内核模块

**当前流程：**
```
远端暂存目录 → sudo rsync -a --delete → /lib/modules/<version>/
```

**新流程：**
```python
# aws_remote_host.py 中替换 rsync：
run_checked("tar", "-czf", "-", "-C", str(modules_root), ".", sudo=False)
# 或者直接用 cp -a（更简单，因为是本地操作）：
run_checked("cp", "-a", f"{modules_root}/.", str(target_root) + "/", sudo=True)
```

因为 A4/A5 是**远端本地操作**（暂存目录 → /lib/modules/），不涉及网络，可以直接用 `cp -a` 或 `tar`（解压到目标目录）替换。

推荐方案：`cp -a "$$modules_root/." "$$target_root/"` 加 sudo，简单直接。

### B1-B5：本地构建目录同步

**当前流程：**
```
vendor/repos/xxx/ → rsync -a --delete [--exclude ...] → .cache/repo-build/.../src/
```

**新流程：**
用 `tar` + 解压替代，或用 `cp -a` + 手动删除排除项。

推荐方案：**`cp -a` + 排除逻辑用 `find ... -prune`**。

更简洁方案：直接用 tar pipe：

```makefile
# 替代 rsync -a --delete --exclude '.git' --exclude 'build' ...
tar -czf - \
    --exclude '.git' \
    --exclude 'build' \
    -C "$$repo_src" . | tar -xzf - -C "$$build_repo"
# 需要先 rm -rf build_repo 再重建（rsync --delete 的效果）
```

但注意这会丢掉增量构建优化（rsync --delete 的 "保留除了排除项之外" 语义），改用 tar 意味着每次都需要全量重建。

**更好的替代方案**：由于 rsync 在这里的核心作用是"把源码镜像到构建目录（同时保留构建产物）"，可以改用 `cp -a --update` 或者直接在源码目录里构建（不做镜像）。

---

## 三、具体要改的文件和函数

### 文件 1：`runner/libs/aws_common.py`

1. **删除** `_rsync_to` 函数（第 142-147 行）
2. **删除** `_rsync_from` 函数（第 150-156 行）
3. **新增** `_tar_stream_to(ctx, ip, src, dest, *, excludes=())`
4. **新增** `_tar_stream_from(ctx, ip, src, dest, *, excludes=())`

### 文件 2：`runner/libs/aws_executor.py`

1. `_sync_kernel_stage`（第 220-226 行）：
   - 将 `aws_common._rsync_to(...)` 改为 `aws_common._tar_stream_to(...)`
2. `_sync_remote_roots`（第 371-397 行）：
   - 将 `aws_common._rsync_to(...)` 改为 `aws_common._tar_stream_to(...)`
3. `_sync_remote_results`（第 400-408 行）：
   - 将 `aws_common._rsync_from(...)` 改为 `aws_common._tar_stream_from(...)`
4. `_remote_required_commands`（第 185-192 行）：
   - 从 commands 列表中**删除** `"rsync"`，因为远端不再需要 rsync

### 文件 3：`runner/libs/aws_remote_host.py`

1. `cmd_setup_kernel_x86`（第 97-117 行，第 101 行）：
   - `run_checked("rsync", "-a", "--delete", ...)` → `run_checked("cp", "-a", f"{modules_root}/.", str(target_root) + "/", sudo=True)`
   - 需要先 `run_checked("rm", "-rf", str(target_root), sudo=True)` 再 mkdir + cp（实现 --delete 效果）
   - 或者用 tar：`tar -czf - -C modules_root . | tar -xzf - -C target_root`（但需要 pipe，run_checked 不支持 pipe）
   - **推荐**：先 rm -rf + mkdir + cp -a

2. `cmd_setup_kernel_arm64`（第 120-131 行，第 124 行）：
   - 同上，替换 rsync 为 cp -a

### 文件 4：`runner/mk/build.mk`

所有 5 处 rsync（B1-B5）替换为 tar pipe 方案：

**BCC（B1，第 388-393 行）：**
```makefile
# 原：
rsync -a --delete --delete-excluded \
    --filter='P libbpf-tools/.output/' \
    --exclude '.git' \
    --exclude 'libbpf-tools/.output/' \
    $(foreach tool,$(ACTIVE_BCC_TOOLS),--exclude 'libbpf-tools/$(tool)') \
    "$$repo_src/" "$$build_repo/";
# 替换为：
# 先清理非保留内容（保留 .output/ 目录），再重新 cp
find "$$build_repo" -mindepth 1 -maxdepth 1 \
    ! -name '.output' -name 'libbpf-tools' -prune -o \
    ! -name 'libbpf-tools' -print0 | xargs -0 rm -rf; \
tar -czf - --exclude='.git' --exclude='libbpf-tools/.output' \
    $(foreach tool,$(ACTIVE_BCC_TOOLS),--exclude='libbpf-tools/$(tool)') \
    -C "$$repo_src" . | tar -xzf - -C "$$build_repo";
```

注意：BCC 的情况比较特殊，`--filter='P ...'` 是 rsync 的 "protect/preserve" 语义（不删除已有的 build output 目录）。用 tar 替代需要更小心地处理这个逻辑。

**简化方案（BCC/Tracee/Tetragon/Katran/workload-tools）：**

这些 rsync 的用途本质是：把上游 repo 镜像到构建工作目录，同时不破坏已有的构建 cache。

最简单的替代是：**不做 mirror，直接在 `repo_src` 原地构建**（去掉 mirror 步骤），把 `-C "$$repo_src"` 直接传给 make/cmake。这样完全不需要 rsync，也不需要 cp/tar。

但这要改 Docker run 命令的 working dir 和输出目录参数，改动较多。

**次简洁方案**：替换为 `cp -a --update`（`cp --update` 只复制更新的文件，近似 rsync -a 的增量效果，但无法删除旧文件）。

**最保险方案**：用 `cp -a` + 每次完全重建（去掉 incremental 的语义，配合已有的 cache_stamp 机制，cache hit 时不跑，miss 时重跑整个 build）。

---

## 四、实现步骤

### 阶段 1：本地 build.mk 的 rsync（B1-B5，风险最低）

目标：用 `cp -a` 替换本地磁盘间的 rsync，保持已有的 cache_stamp 增量逻辑不变。

步骤：
1. 对每个 rsync 块：
   - 在 rsync 前加一行 `rm -rf "$$build_dir"` 清理目标（如果 cache miss 已经 rm -rf，这里无害；如果 cache hit 则不跑 make recipe，也不到这一行）
   - 将 rsync 替换为 `cp -a "$$repo_src/." "$$build_dir/"`（带排除逻辑见下）
2. 对于 BCC/Tracee 的 "保留构建产物" 语义（`--filter='P ...'`）：
   - 将保留目录用 `mv` 临时移走，cp 后再移回
   - 或者：接受每次 cache miss 时完全重建（把 cache_stamp 检查放在 rsync 之前即可）

### 阶段 2：远端模块安装的 rsync（A4/A5，远端本地操作）

目标：`aws_remote_host.py` 中替换 sudo rsync 为 sudo cp -a。

步骤（`cmd_setup_kernel_x86` 和 `cmd_setup_kernel_arm64`）：
```python
# 原来：
run_checked("rsync", "-a", "--delete", f"{modules_root}/", f"{target_root}/", sudo=True)

# 替换为：
run_checked("rm", "-rf", str(target_root), sudo=True)
run_checked("mkdir", "-p", str(target_root), sudo=True)
run_checked("cp", "-a", f"{modules_root}/.", str(target_root) + "/", sudo=True)
```

### 阶段 3：网络传输 rsync（A1/A2/A3，核心改动）

目标：`aws_common.py` 中新增 tar pipe 函数，替换 `_rsync_to` 和 `_rsync_from`。

步骤：
1. 在 `aws_common.py` 中实现 `_tar_stream_to` 和 `_tar_stream_from`
2. 修改 `aws_executor.py` 中所有调用点：
   - `_sync_kernel_stage`: `_rsync_to` → `_tar_stream_to`
   - `_sync_remote_roots`: `_rsync_to` → `_tar_stream_to`
   - `_sync_remote_results`: `_rsync_from` → `_tar_stream_from`
3. 修改 `_remote_required_commands` 删除 `"rsync"`

### 阶段 4：验证

- 本地：`make vm-e2e`（或 `make vm-corpus`）端到端跑一遍
- 远端：AWS ARM64 benchmark 跑一遍
- 确认无 rsync 调用：`grep -r rsync runner/ Makefile`

---

## 五、`_tar_stream_to` 和 `_tar_stream_from` 的详细实现

```python
import subprocess
import shlex
from pathlib import Path

def _tar_stream_to(
    ctx: AwsExecutorContext,
    ip: str,
    src: Path,
    dest: str,
    *,
    excludes: tuple[str, ...] = (),
) -> None:
    """Upload a local directory to a remote path via ssh+tar pipe."""
    tar_args = ["tar", "-czf", "-"]
    for pattern in excludes:
        tar_args += ["--exclude", pattern]
    tar_args += ["-C", str(src), "."]

    remote_cmd = f"mkdir -p {shlex.quote(dest)} && tar -xzf - -C {shlex.quote(dest)}"
    ssh_args = ["ssh", *_ssh_base_args(ctx, ip), f"{ctx.remote_user}@{ip}", remote_cmd]

    tar_proc = subprocess.Popen(tar_args, stdout=subprocess.PIPE, cwd=ROOT_DIR)
    ssh_proc = subprocess.Popen(ssh_args, stdin=tar_proc.stdout, cwd=ROOT_DIR)
    tar_proc.stdout.close()  # allow tar_proc to receive SIGPIPE if ssh dies
    ssh_ret = ssh_proc.wait()
    tar_ret = tar_proc.wait()
    if tar_ret != 0 or ssh_ret != 0:
        raise SystemExit(max(tar_ret, ssh_ret))


def _tar_stream_from(
    ctx: AwsExecutorContext,
    ip: str,
    src: str,
    dest: Path,
    *,
    excludes: tuple[str, ...] = (),
) -> None:
    """Download a remote directory to a local path via ssh+tar pipe."""
    dest.mkdir(parents=True, exist_ok=True)
    ex_args = " ".join(f"--exclude={shlex.quote(e)}" for e in excludes)
    remote_cmd = f"tar -czf - {ex_args} -C {shlex.quote(src)} ."
    ssh_args = ["ssh", *_ssh_base_args(ctx, ip), f"{ctx.remote_user}@{ip}", remote_cmd]

    ssh_proc = subprocess.Popen(ssh_args, stdout=subprocess.PIPE, cwd=ROOT_DIR)
    tar_args = ["tar", "-xzf", "-", "-C", str(dest)]
    tar_proc = subprocess.Popen(tar_args, stdin=ssh_proc.stdout, cwd=ROOT_DIR)
    ssh_proc.stdout.close()
    tar_ret = tar_proc.wait()
    ssh_ret = ssh_proc.wait()
    if tar_ret != 0 or ssh_ret != 0:
        raise SystemExit(max(tar_ret, ssh_ret))
```

---

## 六、风险点

### 风险 1：tar 无增量（vs rsync -a 有增量）

- **影响**：每次传输整个目录，比 rsync 慢（首次传输）
- **缓解**：workspace 传输已经有 `remote_transfer_roots` 筛选，只传必要的子目录。内核模块树较大但每个 setup 只传一次（之后 kernel_release 不变则跳过）。benchmark 结果目录通常较小。
- **结论**：可接受

### 风险 2：tar 管道失败时无部分恢复

- **影响**：传输中断时目标目录可能是半解压状态
- **缓解**：现有代码里失败即终止（raise SystemExit），tar 的半解压状态不比 rsync 中断更差；kernel setup 场景有 setup_stamp 记录，会重新触发
- **结论**：可接受

### 风险 3：BCC/Tracee build 的 "保留构建产物" 语义丢失

- **影响**：去掉 `--filter='P ...'` 后，incremental 编译会失效（每次 cache miss 都全量重建）
- **缓解**：已有 cache_stamp 机制，cache hit 时整个 make recipe 不跑；只有 cache miss（容器 image 变化）时才需要全量重建，这时候全量重建本来就是对的
- **结论**：语义上实际更合理，风险低

### 风险 4：cp -a 在不同文件系统/权限场景下的行为

- **影响**：跨文件系统 cp -a 可能丢失 extended attributes、sparse file 等
- **缓解**：内核模块树在同一 ext4/xfs 文件系统；源码 repo 不需要特殊文件属性
- **结论**：无实际影响

### 风险 5：远端不再需要 rsync 工具

- **影响**：需要从 AMI 的 `_remote_required_commands` 列表中移除 rsync 检查
- **缓解**：直接删除即可，rsync 在新方案中完全不使用
- **结论**：需要同步更新 `_remote_required_commands`

### 风险 6：并发 tar 管道进程管理

- **影响**：Popen 管道需要正确关闭 stdout 句柄，否则可能死锁
- **缓解**：实现时严格按照 subprocess 文档的 pipeline pattern（见上面实现草稿）
- **结论**：按标准写法，风险可控

---

## 七、改动文件汇总

| 文件 | 改动内容 |
|---|---|
| `runner/libs/aws_common.py` | 删除 `_rsync_to`、`_rsync_from`；新增 `_tar_stream_to`、`_tar_stream_from` |
| `runner/libs/aws_executor.py` | 调用点替换：`_rsync_to` → `_tar_stream_to`，`_rsync_from` → `_tar_stream_from`；`_remote_required_commands` 删除 `"rsync"` |
| `runner/libs/aws_remote_host.py` | `cmd_setup_kernel_x86`、`cmd_setup_kernel_arm64` 中 sudo rsync → rm -rf + cp -a |
| `runner/mk/build.mk` | 5 处 rsync 替换为 tar pipe 或 cp -a（B1-B5） |

不需要改：
- `runner/libs/workspace_layout.py`（无 rsync）
- `runner/suites/_common.py`（无 rsync）
- `runner/libs/kvm_executor.py`（无 rsync）
- 其他 suite 文件（无 rsync）
