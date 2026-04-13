# AWS 远端传输重构：Docker Image 统一传输设计

日期：2026-04-12  
状态：设计草案，待实现

---

## 1. 现状分析

### 1.1 当前传输流程（aws_executor.py）

```
本地                                    AWS 远端
------                                  ---------
内核 bzImage / vmlinuz.efi  --scp-->   $REMOTE_KERNEL_STAGE_DIR/boot/
内核模块树                 --tar|ssh-> $REMOTE_KERNEL_STAGE_DIR/lib/modules/<release>/
workspace 子目录           --tar|ssh-> $REMOTE_STAGE_DIR/{runner, daemon, module, ...}
  (含 runtime container image tar)
配置 run-contract.json     --scp-->   $REMOTE_RUN_DIR/run-contract.json
suite-args.json            --scp-->   $REMOTE_RUN_DIR/suite-args.json
结果回传                   <--tar|ssh- $REMOTE_STAGE_DIR/{suite}/results/
日志回传                   <--scp----  $REMOTE_RUN_DIR/remote.log
```

涉及函数：
- `_sync_kernel_stage()` — 传内核 image + 模块树（aws_executor.py:220）
- `_sync_remote_roots()` — 传 workspace 子目录，含 runtime container tar（aws_executor.py:371）
- `_run_remote_suite()` — 传配置文件，触发远端执行（aws_executor.py:411）
- `aws_common._scp_to()` — 单文件 scp 上传
- `aws_common._sync_to()` — 目录 tar over ssh 上传
- `aws_common._sync_from()` — 目录 tar over ssh 下载（保留）
- `aws_common._scp_from()` — 单文件 scp 下载（保留）

### 1.2 传输的内容（按套件）

workspace_layout.py 的 `remote_transfer_roots()` 确定需传内容，包括：

**Python 代码（所有套件）**：
- `runner/__init__.py`
- `runner/libs/`
- `runner/suites/`
- `{micro,corpus,e2e,tests}/` 等

**构建产物（按需）**：
- `.cache/container-images/{arch}-runner-runtime.image.tar` — runtime container
- `daemon/target/{triple}/release/bpfrejit-daemon`
- `runner/build[-arm64]/micro_exec`
- `module/{x86,arm64}/` — kinsn .ko 模块
- `.cache/workload-tools/{arch}/`
- `.cache/micro-programs/{arch}/`
- `.cache/repo-artifacts/{arch}/{bcc,bpftrace,tracee,tetragon,katran,scx}/`

**内核（单独路径）**：
- `.cache/x86-kernel-build/.../bzImage` 或 `arm64/.../vmlinuz.efi`
- `.cache/repo-artifacts/x86_64/kernel-modules/lib/modules/<release>/`

---

## 2. 目标架构

### 2.1 核心思想

在本地构建一个 "deployment image"，以 runtime container image 为 base，把所有需要传输的文件 COPY 进去。一次 `docker save | ssh docker load` 完成传输，替代多次 rsync/tar-over-ssh/scp。

```
本地                                         AWS 远端
------                                       ---------
BUILD deployment image:
  FROM runner-runtime:{arch}
  COPY runner/           /deploy/runner/
  COPY daemon binary     /deploy/daemon/
  COPY .ko 模块          /deploy/module/
  COPY repo-artifacts    /deploy/.cache/repo-artifacts/
  COPY workload-tools    /deploy/.cache/workload-tools/
  COPY 内核 image        /deploy/kernel/boot/
  COPY 内核模块树         /deploy/kernel/lib/modules/<release>/
  COPY run-contract.json /deploy/run-contract.json
  COPY suite-args.json   /deploy/suite-args.json (可选)
  ENV  KERNEL_RELEASE=<version>

docker save deployment-image  \
  | ssh ... docker load       ----一次传输--->  远端 docker image 加载完毕

                              安装内核：
docker run --privileged       
  -v /:/host                  --> 容器内执行 install-kernel 脚本（见 §3.3）
  deployment-image
  /deploy/scripts/install-kernel.sh

                              reboot 远端实例

                              运行 benchmark：
docker run --privileged
  --pid=host --network=host   --> 直接用 deployment image 作为 runtime container
  deployment-image                workspace = /deploy
  python3 -m runner.suites.corpus ...

结果回传：                    <--tar|ssh--   /deploy/{suite}/results/
日志回传：                    <--scp------   remote.log
```

### 2.2 关键设计决策

1. **deployment image = runtime image + 数据层**  
   Base 是已存在的 `bpf-benchmark/runner-runtime:{arch}`。数据通过多个 COPY 层叠加。

2. **内核安装在容器内执行**  
   用 `docker run --privileged -v /:/host` 挂载宿主根文件系统，在容器内执行 install-kernel 脚本（写 /host/lib/modules、/host/boot、调 dracut/grubby）。这替代了现有 `aws_remote_host.py` 的 `cmd_setup_kernel_{x86,arm64}` 通过 ssh + sudo 执行的方式。

3. **benchmark 执行直接用 deployment image**  
   不再需要 `_ensure_runtime_container_image()` + `docker load`，因为 image 已经是 deployment image 本身。`run_in_runtime_container()` 改为直接引用 deployment image tag。

4. **结果回传保留 tar over ssh**  
   结果体积小，单方向，保留现有 `_sync_from()` / `_scp_from()`。

5. **KVM 路径不受影响**  
   `kvm_executor.py` 完全不走 AWS 传输，不需要改。

---

## 3. 详细设计

### 3.1 Dockerfile.deploy 模板

```dockerfile
# 动态生成，由 aws_executor.py 的 _build_deployment_image() 函数写临时文件

ARG RUNTIME_IMAGE
FROM ${RUNTIME_IMAGE}

# workspace 根目录（Python 代码 + 配置）
COPY runner/__init__.py          /deploy/runner/__init__.py
COPY runner/libs/                /deploy/runner/libs/
COPY runner/suites/              /deploy/runner/suites/
# 套件特定代码（按 suite_name 选择）
# corpus: corpus/driver.py, corpus/config/, e2e/cases/
# e2e:    e2e/driver.py, e2e/cases/, corpus/config/
# micro:  micro/driver.py, micro/catalog.py, micro/config/, micro/generated-inputs/
# test:   tests/

# 构建产物（按 ArtifactRequirements 选择）
# COPY .cache/container-images/ 不再需要（deployment image 本身就是 runtime image）
COPY daemon/target/.../bpfrejit-daemon  /deploy/daemon/target/.../bpfrejit-daemon
COPY runner/build[-arm64]/micro_exec    /deploy/runner/build[-arm64]/micro_exec
COPY module/{x86,arm64}/               /deploy/module/{x86,arm64}/
COPY .cache/workload-tools/{arch}/     /deploy/.cache/workload-tools/{arch}/
COPY .cache/micro-programs/{arch}/     /deploy/.cache/micro-programs/{arch}/
COPY .cache/repo-artifacts/{arch}/bcc/ /deploy/.cache/repo-artifacts/{arch}/bcc/
# ... tracee, bpftrace, tetragon, katran, scx 同理

# 内核（安装用）
COPY <kernel_image>                    /deploy/kernel/boot/<image_name>
COPY <modules_root>/                   /deploy/kernel/lib/modules/<release>/

# 运行配置
COPY run-contract.json  /deploy/run-contract.json
COPY suite-args.json    /deploy/suite-args.json    # 可选

# 安装脚本
COPY runner/libs/aws_deploy_scripts/install-kernel-x86.sh   /deploy/scripts/
COPY runner/libs/aws_deploy_scripts/install-kernel-arm64.sh /deploy/scripts/

# 元数据环境变量
ENV BPFREJIT_DEPLOY_WORKSPACE=/deploy
ENV BPFREJIT_KERNEL_RELEASE=<version>
ENV BPFREJIT_INSIDE_RUNTIME_CONTAINER=1

WORKDIR /deploy
```

**注意**：Dockerfile 由 Python 代码在内存中动态生成为临时文件，不是静态模板。内容根据 `ArtifactRequirements`、`suite_name`、`target_arch`、`kernel_release` 动态组装。

### 3.2 新增函数：`_build_deployment_image()`

位置：`aws_executor.py`

```python
def _build_deployment_image(
    ctx: AwsExecutorContext,
    *,
    kernel_release: str,
    kernel_image: Path,
    modules_root: Path,
    suite_args_path: Path | None,
) -> str:
    """
    构建 deployment image，返回 image tag（含 sha256 content hash 后缀，用于幂等性）。

    流程：
    1. 根据 ArtifactRequirements 和 suite_name 确定需要 COPY 的文件/目录列表
    2. 计算所有内容的 content hash（快速 md5/sha256）
    3. 如果 image 已存在（tag 匹配），跳过 build（缓存优化）
    4. 在 tmpdir 生成 Dockerfile.deploy
    5. 创建 build context（包含所有需要传输的文件，以 /deploy/ 为根）
    6. docker build -t <tag> -f Dockerfile.deploy <context>
    7. 返回 image tag
    """
    ...
```

### 3.3 内核安装脚本（容器内执行）

新建 `runner/libs/aws_deploy_scripts/install-kernel-x86.sh`：

```bash
#!/bin/bash
# 在 docker run --privileged -v /:/host 容器内执行
# 写入到 /host（= 宿主 /），然后 grubby 设置默认内核
set -euo pipefail

KERNEL_RELEASE="${BPFREJIT_KERNEL_RELEASE}"
DEPLOY_ROOT=/deploy

# 安装模块
mkdir -p "/host/lib/modules/${KERNEL_RELEASE}"
cp -a --no-preserve=ownership "${DEPLOY_ROOT}/kernel/lib/modules/${KERNEL_RELEASE}/." \
    "/host/lib/modules/${KERNEL_RELEASE}/"

# 安装内核 image
install -o root -g root -m 0755 \
    "${DEPLOY_ROOT}/kernel/boot/bzImage" \
    "/host/boot/vmlinuz-${KERNEL_RELEASE}"

# chroot 执行 depmod + dracut + grubby
chroot /host bash -c "
    depmod -a '${KERNEL_RELEASE}'
    dracut --force --no-hostonly --add-drivers 'nvme nvme-core xfs ext4 virtio_blk' \
        '/boot/initramfs-${KERNEL_RELEASE}.img' '${KERNEL_RELEASE}'
    grubby --add-kernel '/boot/vmlinuz-${KERNEL_RELEASE}' \
           --initrd '/boot/initramfs-${KERNEL_RELEASE}.img' \
           --title 'Codex x86 (${KERNEL_RELEASE})' --copy-default
    grubby --set-default '/boot/vmlinuz-${KERNEL_RELEASE}'
"
```

`install-kernel-arm64.sh` 类似，差异：
- 内核文件名 `vmlinuz.efi`，目标 `/host/boot/vmlinuz-${KERNEL_RELEASE}`
- dracut 不加 `--add-drivers`（arm64 不需要）
- grubby title 为 `Codex ARM64 (...)`

**注意**：`chroot /host` 替代了现有 `aws_remote_host.py` 的 `cmd_setup_kernel_{x86,arm64}` 通过 ssh+sudo 在宿主上直接操作的方式。网卡 MAC 绑定（ens5 link file）逻辑也需要移到这里（仅 x86）。

### 3.4 新增函数：`_deploy_image_to_remote()`

位置：`aws_executor.py`

```python
def _deploy_image_to_remote(ctx: AwsExecutorContext, ip: str, image_tag: str) -> None:
    """
    docker save <image_tag> | ssh ... docker load
    单次管道传输替代所有 _sync_to / _scp_to 调用。
    """
    ssh_args = aws_common._ssh_base_args(ctx, ip)
    docker_save = ["docker", "save", image_tag]
    ssh_load = ["ssh", *ssh_args, f"{ctx.remote_user}@{ip}", "docker load"]
    with subprocess.Popen(docker_save, stdout=subprocess.PIPE) as save_proc:
        completed = subprocess.run(ssh_load, stdin=save_proc.stdout, check=False)
        save_proc.stdout.close()
        save_proc.wait()
        if save_proc.returncode != 0:
            raise SystemExit(save_proc.returncode)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)
```

### 3.5 内核安装执行

```python
def _install_kernel_via_container(ctx: AwsExecutorContext, ip: str, image_tag: str) -> None:
    """
    在远端运行 deployment image 来安装内核。
    等价于：docker run --privileged -v /:/host <image> /deploy/scripts/install-kernel-{arch}.sh
    """
    script = f"/deploy/scripts/install-kernel-{_arch_label(ctx.target_name)}.sh"
    aws_common._ssh_exec(
        ctx, ip,
        "docker", "run", "--rm", "--privileged",
        "-v", "/:/host",
        "-e", f"BPFREJIT_KERNEL_RELEASE={kernel_release}",
        image_tag,
        "/bin/bash", script,
    )
```

### 3.6 benchmark 执行

`_run_remote_suite()` 改为：直接 `docker run` deployment image，不再需要：
- `_sync_remote_roots()` — 文件已在 image 内
- `aws_common._scp_to(ctx, ip, ctx.config_path, ...)` — config 已在 image 内
- `_ensure_remote_helper()` + `_run_remote_helper()` — 由 docker run entrypoint 替代

新的执行方式：

```python
def _run_remote_suite_via_container(
    ctx: AwsExecutorContext, ip: str, image_tag: str,
    remote_log: str,
) -> subprocess.CompletedProcess:
    """
    docker run --rm --privileged --pid=host --network=host \
        -e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 \
        -e PYTHONPATH=/deploy \
        -v /sys:/sys -v /sys/fs/bpf:/sys/fs/bpf ... \
        <image_tag> \
        python3 -m runner.suites.<suite_name> \
            --workspace /deploy \
            --target-arch <arch> \
            ... \
        > <remote_log> 2>&1
    """
```

---

## 4. 需要修改的函数

### 4.1 aws_executor.py 改动

| 函数 | 改动 |
|------|------|
| `_sync_kernel_stage()` | **删除**，内核安装改为容器内脚本 |
| `_setup_kernel_instance()` | **重构**：调用 `_build_deployment_image()` + `_deploy_image_to_remote()` + `_install_kernel_via_container()` + reboot |
| `_sync_remote_roots()` | **删除**，文件已在 image 内 |
| `_run_remote_suite()` | **重构**：调用 `_deploy_image_to_remote()` + `_run_remote_suite_via_container()` |
| `_ensure_instance_for_suite()` | 小改：setup 判断逻辑不变，但 setup 本身走新路径 |
| 新增 `_build_deployment_image()` | 构建 deployment image |
| 新增 `_deploy_image_to_remote()` | docker save \| ssh docker load |
| 新增 `_install_kernel_via_container()` | docker run 安装内核 |
| 新增 `_run_remote_suite_via_container()` | docker run 执行 benchmark |
| 新增 `_generate_deploy_dockerfile()` | 生成 Dockerfile 文本 |

### 4.2 aws_common.py 改动

| 函数 | 改动 |
|------|------|
| `_scp_to()` | **删除**（上传路径全部改为 image 传输） |
| `_sync_to()` | **删除**（上传路径全部改为 image 传输） |
| `_ensure_remote_helper()` | **删除**（不再需要 aws_remote_host.py 在远端） |
| `_run_remote_helper()` | **删除**（替换为 docker run 调用） |
| `_sync_from()` | **保留**（结果回传） |
| `_scp_from()` | **保留**（日志回传） |
| `_ssh_exec()` | **保留**（用于 docker run 命令） |
| `_ssh_base_args()` | **保留** |
| `_wait_for_ssh()` | **保留** |
| `_aws_cmd()` | **保留** |

### 4.3 aws_remote_host.py 改动

远端不再需要 Python 脚本辅助，但部分功能需要迁移：

| 原函数 | 去向 |
|--------|------|
| `cmd_uname_r` | 用 `ssh ... uname -r` 直接替代，无需 Python |
| `cmd_root_volume_size_gb` | 用 `ssh ... lsblk ...` 替代 |
| `cmd_has_runtime_btf` | 用 `ssh ... test -f /sys/kernel/btf/vmlinux` 替代 |
| `cmd_has_sched_ext` | 用 `ssh ... test -e /sys/kernel/sched_ext/state` 替代 |
| `cmd_verify_base_prereqs` | 用 `ssh ... command -v docker python3 ...` 替代 |
| `cmd_print_kernel_config` | 用 `ssh ... cat /boot/config-$(uname -r)` 替代 |
| `cmd_setup_kernel_x86` | **迁移到** `install-kernel-x86.sh`（容器内执行） |
| `cmd_setup_kernel_arm64` | **迁移到** `install-kernel-arm64.sh`（容器内执行） |
| `cmd_verify_kernel` | 用 `ssh ... uname -r && grubby --default-kernel` 替代 |
| `cmd_prepare_dir` | **删除**（不再需要远端目录） |
| `cmd_path_exists` | **删除**（不再需要检查远端 workspace 路径） |
| `cmd_run_workspace` | **删除**（替换为 docker run 直接运行） |

**aws_remote_host.py 可以完全删除**，或保留空壳作为兼容层（建议删除）。

### 4.4 runner/suites/_common.py 改动

`_ensure_runtime_container_image()` 和 `run_in_runtime_container()` 在 AWS 路径下不再需要从 tar 加载 image（image 已经是 deployment image 本身），但本地路径（`inside_runtime_container() == False` 时）仍需要。

**方案**：这两个函数不改（本地路径不变）。AWS 路径下直接用 deployment image tag 作为 `--runtime-container-image` 参数，套件代码中 `inside_runtime_container()` 返回 True（因为 deployment image 内设了 `BPFREJIT_INSIDE_RUNTIME_CONTAINER=1`），不会再次触发 `run_in_runtime_container()`。

### 4.5 workspace_layout.py 改动

- `remote_transfer_roots()` — **可删除**（不再需要列举传输路径，由 Dockerfile COPY 替代）
- `_artifact_transfer_paths()` — **可删除**
- `_base_transfer_paths()` — **可删除**
- `runtime_container_image_tar_path()` — **保留**（本地路径加载 image 时还需要）
- 其他 path helper 函数 — **全部保留**（本地执行路径仍需要）

---

## 5. 架构图（新流程）

```
_run_aws()
  └─ _ensure_instance_for_suite()
       ├─ _launch_instance()            [不变]
       ├─ _wait_for_ssh()               [不变]
       └─ [需要 setup?]
            └─ _setup_instance()
                 ├─ _build_kernel_artifacts()    [不变]
                 ├─ _build_deployment_image()    [新增]
                 │     └─ _generate_deploy_dockerfile()  [新增]
                 │        docker build ...
                 ├─ _deploy_image_to_remote()    [新增]
                 │     docker save | ssh docker load
                 ├─ _install_kernel_via_container()  [新增]
                 │     ssh ... docker run --privileged -v /:/host <image> install-kernel.sh
                 └─ reboot + verify               [不变]

  └─ _run_remote_suite()
       ├─ _build_deployment_image()     [新增，复用 / 幂等]
       ├─ _deploy_image_to_remote()     [新增]
       ├─ _run_remote_suite_via_container()  [新增]
       │     ssh ... docker run --privileged --pid=host ... <image> python3 -m runner.suites.<suite>
       └─ _sync_remote_results()        [保留，改为从容器内的 /deploy/{suite}/results/ 回传]
```

---

## 6. 传输量对比

| 项目 | 现在 | 新架构 |
|------|------|--------|
| 内核 image（bzImage 约 15MB） | scp | Docker COPY layer |
| 内核模块树（~100-300MB） | tar|ssh | Docker COPY layer |
| runtime container image tar（~200-400MB） | tar|ssh（作为 workspace 一部分） | 不再单独传（image 本身） |
| runner Python 代码（~几 MB） | tar|ssh | Docker COPY layer |
| 构建产物（daemon, .ko, bcc, tracee 等，~GB 级） | tar|ssh | Docker COPY layer |
| 配置 JSON（~1KB） | scp × 2 | Docker COPY layer |
| **总传输次数** | **5-6 次独立 ssh 操作** | **1 次 docker save\|ssh docker load** |

**权衡**：
- Docker image build 在本地需要时间（首次），但有 layer 缓存，后续增量很快
- 传输量基本相同（所有文件仍需传），但 docker save 有压缩，通常优于裸 tar
- 最大收益：传输次数减少（单次 TCP 流 vs 多次 ssh 握手）；远端不再需要展开文件

---

## 7. 幂等性与缓存策略

- **Image tag** 格式：`bpf-benchmark/deploy:{arch}-{suite}-{content_hash[:12]}`
- **content_hash** = sha256 of (所有被 COPY 文件的路径 + mtime + size)
- **本地 build 缓存**：tag 已存在则跳过 build
- **远端 image 缓存**：先 `ssh ... docker image inspect <tag>` 检查，存在则跳过传输
- **setup 重用**：`STATE_KERNEL_RELEASE` 缓存不变，但需加 `STATE_DEPLOY_IMAGE_TAG` 记录已部署的 image tag，避免重复传输

---

## 8. 不受影响的路径

- **KVM executor**（`kvm_executor.py`）：完全独立，不涉及任何 AWS 传输函数
- **本地执行**（`executor=local`）：套件代码不经过 aws_executor.py
- **runtime container 本地加载**（`_ensure_runtime_container_image()`）：本地路径不变

---

## 9. 需要新增的文件

```
runner/libs/aws_deploy_scripts/
  install-kernel-x86.sh    — x86 内核安装脚本（容器内，chroot /host）
  install-kernel-arm64.sh  — arm64 内核安装脚本（容器内，chroot /host）
```

这两个脚本包含的逻辑来自 `aws_remote_host.py` 的 `cmd_setup_kernel_{x86,arm64}()`，加上 chroot 包装。

---

## 10. 实现顺序建议

1. 新增 `runner/libs/aws_deploy_scripts/install-kernel-{x86,arm64}.sh`
2. 在 `aws_executor.py` 新增 `_generate_deploy_dockerfile()` 和 `_build_deployment_image()`
3. 新增 `_deploy_image_to_remote()`
4. 新增 `_install_kernel_via_container()`
5. 重构 `_setup_kernel_instance()` 使用上述新函数
6. 新增 `_run_remote_suite_via_container()`
7. 重构 `_run_remote_suite()` 移除 `_sync_remote_roots()` 和 `_scp_to` 调用
8. 删除 `aws_common.py` 中的 `_scp_to`, `_sync_to`, `_ensure_remote_helper`, `_run_remote_helper`
9. 删除 `aws_remote_host.py`（或标记废弃）
10. 删除 `workspace_layout.py` 中的 `remote_transfer_roots()` 等 AWS 专用函数
11. 端到端测试：x86 + arm64 各跑一次 corpus/e2e
