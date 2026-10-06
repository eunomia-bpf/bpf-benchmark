# rsync vs Docker Image 传输分析报告

**日期**: 2026-04-12  
**目的**: 评估用 Docker image 统一替代 rsync 传输的可行性

---

## 1. rsync 在代码中的位置与用途

### 1.1 本地构建阶段（build.mk）

`runner/mk/build.mk` 中有 5 处 rsync 调用，全部是**本地使用**（控制机上），用于构建过程中的源码同步：

| 位置 | 用途 |
|------|------|
| L388 (BCC) | 将 vendor/bcc 源码 rsync 到构建工作目录，排除 `.git`、`.output` 等 |
| L462 (Tracee) | 将 vendor/tracee 源码 rsync 到构建工作目录 |
| L518 (Tetragon) | 将 vendor/tetragon 源码 rsync 到构建工作目录 |
| L571 (Katran) | 将 vendor/katran 源码 rsync 到构建工作目录 |
| L673 (workload-tools) | 将 workload-tools 源码 rsync 到构建工作目录 |

这些 rsync 都是本地磁盘间复制，**不涉及网络传输**，且专门用于复制源码到隔离构建目录（同时 `--delete` 清理旧状态）。这类用法本质是用 rsync 替代 cp -r（保留增量）。

### 1.2 AWS 远端传输阶段（aws_common.py / aws_executor.py）

这里才是用户关心的**网络 rsync**，有两个方向：

**rsync_to（上传到远端）**：

1. `aws_executor.py:225` — `_sync_kernel_stage()`：将内核模块目录从本地 rsync 到远端 stage 目录  
   ```
   _rsync_to(ctx, ip, modules_root, f"{remote_kernel_stage_dir}/lib/modules/{kernel_release}", excludes=("build", "source"))
   ```
   
2. `aws_executor.py:395` — `_sync_remote_roots()`：将整个 workspace 的多个子目录（runner 代码、构建产物、kinsn 模块等）rsync 到远端  
   ```
   aws_common._rsync_to(ctx, ip, source_path, remote_path, excludes=("results/", "__pycache__/"))
   ```

**rsync_from（从远端下载）**：

3. `aws_executor.py:407` — `_sync_remote_results()`：从远端把 benchmark 结果 rsync 回本地

**远端内部 rsync（aws_remote_host.py）**：

4. `aws_remote_host.py:101` — `cmd_setup_kernel_x86()`：远端安装内核模块时，将 stage 目录的模块 rsync 到 `/lib/modules/<version>/`（带 sudo）  
5. `aws_remote_host.py:124` — `cmd_setup_kernel_arm64()`：同上，ARM64 版

### 1.3 远端必备命令检查（aws_executor.py:190）

`_remote_required_commands()` 列出了远端实例必须安装的命令，其中包含 `"rsync"`。也就是说，当前设计要求目标 AMI 上已经预装 rsync。

---

## 2. Docker image 当前传输流程

### 2.1 镜像种类与构建

系统使用三类 Docker 镜像：

| 镜像 | tar 文件 | 用途 |
|------|----------|------|
| `runner-build:x86_64/arm64` | `.cache/container-images/x86_64-runner-build.image.tar` | 编译内核、各 repo、runner binary 的构建环境 |
| `runner-runtime:x86_64/arm64` | `.cache/container-images/x86_64-runner-runtime.image.tar` | **运行时容器**，用于在远端隔离环境中执行 benchmark |
| `bpftrace-static-build:x86_64/arm64` | `.cache/container-images/x86_64-bpftrace-static-build.image.tar` | 编译 bpftrace 静态二进制 |

`runner-build` 和 `bpftrace-static-build` 仅在本地构建阶段使用（`docker run`），不传到远端。

### 2.2 runner-runtime 镜像传输流程

**本地**：
- `docker build` → `docker save -o *.image.tar` → 存放在 `.cache/container-images/`

**传输到远端**（通过 rsync_to，作为 workspace 子目录的一部分）：
- `workspace_layout.py:124`：`runtime_container_image_tar_path()` 加入 `_artifact_transfer_paths()`
- 因此 `.cache/container-images/arm64-runner-runtime.image.tar` 会被 rsync 到远端

**远端加载**（`_common.py:_ensure_runtime_container_image()`）：
- 检查镜像是否已 load：`docker image inspect <image>`
- 若未 load：`docker load -i <tar_path>`

**远端执行**（`_common.py:run_in_runtime_container()`）：
- `docker run --privileged --pid=host --network=host ...`
- 挂载 `/sys`, `/lib/modules`, `/boot` 等系统路径
- 挂载整个 workspace 目录（`-v workspace:workspace`）

---

## 3. 各类文件通过 rsync vs Docker 传输的对比

### 3.1 当前通过 rsync 传输的内容

| 类别 | 传输路径 | 触发位置 |
|------|----------|----------|
| **内核模块**（用于 AWS 自定义内核安装）| 本地 `.cache/repo-artifacts/*/kernel-modules/lib/modules/<version>/` → 远端 stage | `aws_executor.py:225` |
| **runner Python 代码** | `runner/__init__.py`, `runner/libs`, `runner/suites` 等 | `aws_executor.py:395` |
| **benchmark driver 代码** | `micro/driver.py`, `corpus/driver.py`, `e2e/driver.py` 等 | 同上 |
| **kinsn 内核模块**（bpf_*.ko）| `module/x86/` 或 `module/arm64/` 目录 | 同上 |
| **workload-tools binaries** | `.cache/workload-tools/arm64/bin/` | 同上 |
| **native repo 构建产物** | bcc, tracee, bpftrace, katran, tetragon 二进制 | 同上 |
| **SCX packages** | `.cache/repo-artifacts/*/scx/` | 同上 |
| **runner binary** | `runner/build-arm64/micro_exec` | 同上 |
| **daemon binary** | `daemon/target/*/bpfrejit-daemon` | 同上 |
| **runtime container tar** | `.cache/container-images/arm64-runner-runtime.image.tar` | 同上（作为 workspace 的一部分） |
| **micro BPF objects** | `.cache/micro-programs/*/simple.bpf.o` | 同上 |
| **benchmark 结果**（反向） | 远端 `corpus/results/`, `e2e/results/` → 本地 | `aws_executor.py:407` |

### 3.2 当前通过 Docker image 传输的内容

严格来说，**当前没有任何内容是专门通过 Docker image 传输的**。Docker image 的 tar 文件本身是通过 rsync（作为 workspace 目录树的一部分）传到远端的，然后在远端 `docker load` 加载；加载后的镜像作为运行时**执行容器**，只提供系统依赖（RockyLinux 9 + 必要的 rpm 包），benchmark 产物仍通过 workspace 挂载卷注入。

---

## 4. 是否可以把所有内容打包进 Docker image？

### 4.1 理论可行性

**可以打包进 Docker image 的内容：**

1. **kinsn 内核模块（bpf_*.ko）**：文件小（几百 KB），随构建确定，适合打包  
2. **workload-tools binaries**（hackbench, sysbench, wrk）：静态/半静态，适合打包  
3. **native repo 构建产物**（tracee, bpftrace, bcc tools 等）：二进制，适合打包  
4. **micro BPF objects**：小文件，适合打包  
5. **runner binary / daemon binary**：适合打包  
6. **benchmark Python 代码**（runner/libs, corpus/driver.py 等）：适合打包，但频繁改动

**不适合/不可能打包进 Docker image 的内容：**

1. **内核模块树**（kernel-modules，用于自定义内核安装）：与内核版本强绑定，每次 build 可能不同，且安装到 `/lib/modules/` 需要在宿主机运行（不能在容器内完成），因此**不可能通过 docker cp + 容器内安装**解决  
2. **内核 vmlinuz.efi / bzImage**：同上，需要写入宿主 `/boot`，必须在宿主运行  
3. **benchmark 结果**（反向回传）：动态产生，docker image 方案无法回传  
4. **run contract JSON / suite args**：每次运行动态生成，必须实时传输

### 4.2 内核模块安装的特殊性

当前流程（AWS 自定义内核安装）：

```
本地 build → rsync kernel modules → 远端 rsync 到 /lib/modules/ (sudo) → depmod → dracut → reboot
```

这个流程必须在宿主机（非容器内）完成，因为 dracut、grubby 等工具操作的是宿主引导环境。即使将模块文件打包进 Docker image，也需要在远端 `docker cp` 或 `docker create` 提取后，再用 sudo 安装。**流程并没有实质简化，反而增加了步骤**。

### 4.3 `docker cp` 提取方案分析

提取思路：

```bash
# 在远端
docker create --name=artifacts <image> /bin/true
docker cp artifacts:/artifacts/kernel-modules/. /lib/modules/<version>/
docker rm artifacts
sudo depmod -a <version>
```

**问题**：
- 内核模块路径与版本号强绑定，image 构建时无法确定远端版本号（因为是 cross-compile 后传过去）
- 每次内核更新（新的 kernel release）都需要重新 build image，而当前 rsync 方案只需 rsync 新模块
- Docker image 是不可变层叠结构，更新部分文件需要 rebuild 整个 layer，rsync 只传增量

---

## 5. 好处与风险评估

### 5.1 统一用 Docker image 传输的好处

| 好处 | 说明 |
|------|------|
| **去掉 rsync 依赖** | AMI 不需要预装 rsync，简化镜像要求 |
| **内容版本化** | Docker image tag/digest 可明确标记构建版本，传输内容与 commit 绑定 |
| **可用 registry 分发** | 将来可推送到 ECR 等，用 `docker pull` 代替文件传输，无需 SSH 大文件传输 |
| **构建产物与运行环境统一** | 所有 benchmark 产物在 image 层内，不依赖宿主文件系统布局 |

### 5.2 风险与代价

| 风险/代价 | 说明 |
|-----------|------|
| **内核安装流程无法消除 rsync** | 内核模块安装到宿主 `/lib/modules/` 是刚需，必须在宿主机操作；docker cp 方案只是替换了 rsync 的文件复制步骤，但额外增加 create/cp/rm 操作，实际更复杂 |
| **Image 体积膨胀** | benchmark 产物（tracee ~50MB, katran 依赖 ~200MB+, bpftrace ~100MB）全部打包会使 image 体积从当前 ~200MB 膨胀到 ~1GB+，传输时间反而可能更长 |
| **增量更新代价高** | rsync 天然支持增量（只传变化的文件），docker image 每次 rebuild 即使只改了一个 .py 文件也要重新 push/pull 整层 |
| **开发迭代成本** | 改一行 runner 代码，需要 rebuild image → save → rsync → remote docker load，而现在只需 rsync 那一个文件 |
| **结果回传无法通过 Docker** | benchmark 结果是运行后动态产生的，必须用 rsync/scp 回传，无法用 image |
| **kinsn 模块频繁迭代** | 论文研究阶段 kinsn 模块经常改动，打包进 image 意味着每次改 .ko 都要 rebuild image |

---

## 6. 结论与建议

### 6.1 结论

**不建议完全用 Docker image 替代 rsync**，原因如下：

1. **内核安装场景无法绕开宿主机操作**：内核模块、vmlinuz、dracut、grubby 等操作必须在 AMI 宿主机上以 root 执行，无论如何都需要某种宿主级文件传输机制

2. **rsync 的增量优势在这个场景下价值显著**：benchmark 代码和产物频繁改动，rsync 增量传输远比 image 重新 build+transfer 高效

3. **结果回传没有 Docker 方案**：rsync 在 `_sync_remote_results()` 的用途无法被 Docker 替代

### 6.2 可行的局部优化

如果目标是**减少 rsync 依赖**而非彻底消除：

**方案 A：仅去掉远端宿主级 rsync（aws_remote_host.py 中的两处）**

将 `cmd_setup_kernel_x86/arm64` 中的 `rsync -a --delete` 替换为 `cp -a` 或 `tar`，这样远端 AMI 不需要预装 rsync。本地→远端的传输（`aws_common._rsync_to()`）仍用 rsync。

**方案 B：对 runtime 镜像和产物使用 registry**

将 runner-runtime image 和不常变化的构建产物（workload-tools, native repos）推送到私有 ECR registry，远端 `docker pull` 而非 rsync。kinsn 模块、内核相关、Python 代码仍用 rsync。这样可以减少大文件的 rsync 传输量。

**方案 C（最小改动）：去掉远端 AMI 对 rsync 的依赖**

只改 `aws_remote_host.py` 中的两处 rsync（用 `cp -r` 或 `tar`），同时从 `_remote_required_commands()` 的检查列表中移除 `rsync`。本地 build.mk 和 aws_executor.py 中的 rsync 保持不变，因为控制机本地始终有 rsync。

**推荐方案 C**，改动最小、风险最低，且实际上解决了"AMI 需要预装 rsync"的问题。

---

## 7. 相关代码位置速查

| 文件 | 关键位置 | 说明 |
|------|----------|------|
| `runner/libs/aws_executor.py` | L225, L395, L407 | 网络 rsync 调用（上传 kernel modules、workspace；下载结果） |
| `runner/libs/aws_common.py` | L142-156 | `_rsync_to()` / `_rsync_from()` 函数定义 |
| `runner/libs/aws_remote_host.py` | L101, L124 | 远端宿主级 rsync（模块安装时，带 sudo） |
| `runner/libs/aws_executor.py` | L190 | `rsync` 在远端必备命令列表中 |
| `runner/suites/_common.py` | L67-88 | `_ensure_runtime_container_image()`：docker load 逻辑 |
| `runner/suites/_common.py` | L91-127 | `run_in_runtime_container()`：docker run 逻辑 |
| `runner/libs/workspace_layout.py` | L124 | runtime image tar 加入传输列表（导致 image tar 也被 rsync） |
| `runner/mk/build.mk` | L388, L462, L518, L571, L673 | 本地构建阶段 rsync（与网络无关） |
