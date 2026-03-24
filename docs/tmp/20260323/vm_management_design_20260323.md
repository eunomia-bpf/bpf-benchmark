# VM / 远端机器统一管理设计

日期：2026-03-23

## 1. 结论先行

当前仓库里已经有 4 套彼此独立的“机器管理”路径：

1. 本地 x86 `vng`/`virtme-ng` VM
2. 本地 ARM64 `QEMU` + rootfs
3. AWS ARM64 远端 SSH 机器
4. GitHub Actions CI runner

它们都能跑各自的一部分任务，但控制面是分裂的：

- 机器入口分散在 `Makefile`、`corpus/modes.py`、`runner/libs/vm.py`、`runner/scripts/aws_arm64.sh`、`.github/workflows/*.yml`
- 没有统一的机器注册表
- 没有统一的 capability / arch / exclusivity 模型
- 没有统一的 busy/idle 状态
- “同一时间只能一个 agent 跑 VM 测试”目前只是文档约束，不是系统约束

建议方案是：

- 引入一个中心 YAML 机器注册表
- 用一个轻量 machine resolver / scheduler 做任务到机器的映射
- 把现有 `vng`、QEMU、SSH、CI 保留为不同 backend adapter
- 先做 MVP：统一注册 + 手动 `TARGET=` 选择
- 自动调度、排队、lease/heartbeat 放到后续阶段

这套方案的重点不是重写全部 benchmark 逻辑，而是先把“机器”从现有脚本里抽成一等对象。

---

## 2. 现状分析

### 2.1 本地 x86 VM：`vng` / `virtme-ng`

根入口在 root `Makefile`。

涉及 target：

- `vm-test`
- `vm-selftest`
- `vm-negative-test`
- `vm-micro-smoke`
- `vm-micro`
- `vm-corpus`
- `vm-e2e`
- `vm-all`

其中有两种风格。

#### 2.1.1 Makefile 直接内联 `vng`

`vm-test`、`vm-selftest`、`vm-negative-test`、`vm-micro-smoke`、`vm-micro`、`vm-e2e` 都直接在 `Makefile` 里拼 `$(VNG) --run ...` 命令。

关键点：

- `VNG ?= $(ROOT_DIR)/runner/scripts/vng-wrapper.sh`
- `VM_INIT := $(VENV_ACTIVATE) "$(ROOT_DIR)/module/load_all.sh" 2>/dev/null || true;`
- guest 里默认加载 kinsn modules
- guest 代码目录通过 `--rwdir "$(ROOT_DIR)"` 暴露给 VM
- `vm-micro` / `vm-micro-smoke` 在 guest 内拉起 daemon，再运行 `micro/driver.py`
- `vm-e2e` 在 host 先做 `tracee/setup.sh` 预下载，然后 guest 内执行 `python3 e2e/run.py all`

这条路径的特点是：

- 机器生命周期完全隐含在 target recipe 里
- 没有独立的 machine object / machine state
- 没有 busy/idle 追踪
- 没有 target -> machine 的可配置映射

#### 2.1.2 `vm-corpus` 不是同一套实现

`vm-corpus` 并不直接在 `Makefile` 里跑 `vng` guest 命令，而是先在 host 运行：

- `python3 corpus/driver.py packet --kernel-image ... --vng "$(VNG)" ...`

真正的 VM batch 逻辑在 `corpus/modes.py`：

- `build_vng_command()`
- `build_guest_exec()`
- `run_targets_in_guest_batch()`

这里又自己封装了一套 VM 路径：

- 自己决定 `--memory 4G --cpus 2`
- 自己拼 `vng --exec`
- 自己做 guest JSON event stream
- 自己在 guest 里注入 `module/load_all.sh`
- 自己创建 repo-root 下的临时 JSON payload

结果是：`vm-corpus` 名义上和其他 `vm-*` 同类，但技术实现不是同一个控制面。

#### 2.1.3 `vng` 逻辑实际分散在 4 处

当前与本地 VM 相关的 `vng` 封装至少有 4 份：

1. root `Makefile` 的内联 `vng --run`
2. `corpus/modes.py` 的 `build_vng_command()`
3. `runner/libs/vm.py` 的 `run_in_vm()`，被 `e2e/cases/scx/case.py` 使用
4. `docs/paper/scripts/run_micro.sh` 的旧版兼容逻辑（已标记 deprecated）

其中只有 `runner/scripts/vng-wrapper.sh` 是共享的，它解决的是 PTY 问题，不是机器抽象问题。

#### 2.1.4 当前状态小结

本地 x86 VM 当前是“功能可用，但控制面复制粘贴”：

- 同样是 `vng` VM，参数来源不统一
- guest 初始化不统一
- 任务入口不统一
- 没有统一注册/状态/锁

---

### 2.2 本地 ARM64：QEMU + rootfs + cross build

ARM64 路径也在 root `Makefile`，但完全是另一套系统。

涉及 target：

- `arm64-worktree`
- `kernel-arm64`
- `arm64-rootfs`
- `arm64-crossbuild-image`
- `cross-arm64`
- `selftest-arm64`
- `vm-arm64-smoke`
- `vm-arm64-selftest`

#### 2.2.1 ARM64 kernel 构建

ARM64 kernel 不是直接在 `vendor/linux-framework` 上原地编，而是：

- 建独立 worktree：`.worktrees/linux-framework-arm64-src`
- 输出到 `vendor/linux-framework/build-arm64`
- config 由 `runner/scripts/arm64-kernel-config.sh` 生成

这条路径已经隐含了“同一份 kernel 源被多套环境复用”的资源竞争问题。

#### 2.2.2 ARM64 userspace 产物依赖 Docker

`cross-arm64` 和 `selftest-arm64` 依赖：

- `runner/docker/arm64-crossbuild.Dockerfile`
- `runner/scripts/cross-arm64-build.sh`
- `runner/scripts/cross-arm64-selftest.sh`

这里的 Docker image 实际上是“AL2023-compatible ARM64 build profile”，不是机器注册表的一部分，但它决定了远端 ARM64 机器能否直接执行本地产物。

尤其 `cross-arm64-build.sh` 会：

- 在容器里交叉编译 `micro_exec` 与 `bpfrejit-daemon`
- 收集动态库
- 生成带 `LD_LIBRARY_PATH` 的 wrapper

这明显是“面向特定机器类型的构建准备”，但现在这些信息分散在 Makefile、Dockerfile、脚本里。

#### 2.2.3 ARM64 运行时又是一套单独 backend

`vm-arm64-smoke` / `vm-arm64-selftest` 依赖：

- `runner/scripts/arm64_qemu_smoke.py`

这个脚本直接调用：

- `qemu-system-aarch64`
- 9p rootfs
- 可选 host-share mount
- 通过 stdin 注入 guest shell command

这和 `vng` VM 路径完全平行：

- 不是 `virtme-ng`
- 不是 SSH
- 也没有统一 machine state

#### 2.2.4 当前状态小结

本地 ARM64 路径已经具备完整的 build + boot + smoke/selftest 骨架，但：

- 只覆盖 ARM64 smoke / selftest，不覆盖 corpus/e2e
- 与 x86 `vm-*` target 完全脱节
- 与 AWS ARM64 远端路径也完全脱节
- 没有统一 target 选择模型

---

### 2.3 AWS ARM64：SSH 远端机 + 本地准备 + 远端执行

AWS ARM64 路径的入口是：

- `aws-arm64-launch`
- `aws-arm64-setup`
- `aws-arm64-benchmark`
- `aws-arm64-terminate`
- `aws-arm64`

真正逻辑集中在 `runner/scripts/aws_arm64.sh`。

#### 2.3.1 这已经是一套“半成品 machine manager”

`aws_arm64.sh` 已经在做很多 machine-management 事情：

- 使用 tag 发现 / 复用实例
- 使用 `.cache/aws-arm64/state/instance.env` 记录 state
- 管理本地缓存目录：
  - `artifacts/`
  - `state/`
  - `results/`
  - `benchmark-bundle/`
- 封装 SSH / SCP
- 等待 SSH ready
- 安装远端 runtime prerequisite
- 安装 custom kernel + modules
- 远端 reboot + verify
- 上传 benchmark bundle
- 拉回结果 tarball

换句话说，AWS 这条路径已经不是“benchmark 脚本”，而是一套专门为 ARM64 EC2 写的机器控制器。

#### 2.3.2 但它是 benchmark-specific，而不是通用 machine abstraction

当前 AWS 路径高度特化：

- 机器类型默认就是 `t4g.micro`
- 远端 stage dir 是硬编码的
- bundle 内容是硬编码的
- benchmark entrypoint 是硬编码的 `arm64_t4g_remote_benchmark.py`
- benchmark 内容也是硬编码的：
  - llvmbpf vs kernel micro
  - daemon stock vs recompile micro
  - Katran smoke

这意味着：

- 它能跑“当前这套 ARM64 benchmark”
- 但不能自然泛化为“任意远端机器执行器”

#### 2.3.3 远端同步方式是 ad-hoc 的 tar + scp

当前远端代码/产物同步方式是：

- host 上构造 benchmark bundle 目录
- 打成 tar.gz
- `scp` 到远端
- 远端解包后运行

优点：

- 简单
- 和远端 OS ABI 兼容问题分离得比较清楚

缺点：

- bundle 内容是按脚本手写维护的
- 不是统一的 workspace sync 抽象
- 未来加其他远端机器时很容易复制出第二套、第三套 bundle 逻辑

#### 2.3.4 当前状态小结

AWS ARM64 路径是目前最接近“机器管理系统”的一条，但它的问题是：

- 只服务一类机器
- 只服务一类 benchmark
- 只支持 SSH/scp 风格
- 没有跟本地 VM / CI 共用 machine registry

---

### 2.4 CI：GitHub Actions 自己就是另一套机器注册系统

当前 CI 里机器信息并不在 repo 配置里，而在 workflow YAML 里。

#### 2.4.1 ARM64 CI

`.github/workflows/arm64-benchmark.yml`：

- `runs-on: ubuntu-24.04-arm`
- 手动 `workflow_dispatch`
- 直接在 CI host 上构建并运行
- 主要做 ARM64 baseline，不是 custom-kernel VM 流程

它没有复用：

- root `Makefile` 的 `vm-*`
- `aws_arm64.sh`
- `arm64_qemu_smoke.py`

#### 2.4.2 x86 CI

`.github/workflows/x86-benchmark.yml`：

- `runs-on: ubuntu-latest`
- 直接 host 跑 micro baseline
- 最后还直接 commit/push 结果

它也没有复用统一 machine abstraction，因为目前根本没有。

#### 2.4.3 CI 现状问题

CI 实际上已经在做“机器选择”，只是选择逻辑在 GitHub Actions 的 `runs-on` label 里，而不在仓库自己的配置里。

结果是：

- 本地 / AWS / CI 的机器命名空间不同
- 同一个 benchmark 在本地和 CI 上无法通过同一个 `TARGET=` 语义表达
- CI 无法自然复用本地的 machine capability 定义

---

### 2.5 现有约束与隐含规则

从 `docs/kernel-jit-optimization-plan.md` §6、root `Makefile`、脚本实现，可以提炼出几个明确约束：

1. 当前 x86 主力开发环境是 `QEMU/KVM + virtme-ng`，kernel 是 `vendor/linux-framework` 的 custom 7.0-rc2 分支。
2. ARM64 需要单独 worktree、单独 build dir、单独 rootfs、单独 cross-build image。
3. AWS ARM64 需要：
   - 先本地交叉编译 userspace
   - 再本地编 custom kernel + modules
   - 再远端安装 kernel
   - 再通过 SSH 执行 benchmark
4. VM 测试当前必须串行执行；“同一时间只能一个 agent 跑 VM 测试”只是文档约束，不是实现约束。
5. 本地 VM 和远端 SSH 的代码同步模式不同：
   - 本地 VM：mount/share
   - 远端 SSH：bundle + scp
6. CI 目前并不使用同一套配置；它把 runner 信息写在 workflow 里。

这些约束正是统一方案必须显式建模的对象。

---

## 3. 当前痛点

### 3.1 没有统一的机器注册表

目前“可用机器”散落在以下位置：

- `Makefile` 变量与 target
- `corpus/modes.py`
- `runner/libs/vm.py`
- `runner/scripts/aws_arm64.sh`
- `.github/workflows/*.yml`

系统并不知道：

- 现在有哪些机器
- 哪台机器是什么 arch
- 哪台机器支持哪些 benchmark
- 哪台机器是否独占
- 哪台机器如何连接

### 3.2 同类 backend 有多份实现

`vng` 至少有 4 份入口，QEMU 有单独入口，SSH 有单独入口。

这会导致：

- 参数不一致
- timeout 不一致
- guest init 不一致
- 维护成本随机器数量线性恶化

### 3.3 任务选择接口不统一

现在用户要记住多种命名空间：

- `vm-micro`
- `vm-arm64-smoke`
- `aws-arm64-benchmark`
- GitHub workflow 名字

这不是“一个任务在不同机器上执行”，而是“每种机器一套单独命令”。

### 3.4 没有系统级 exclusivity / scheduling

当前最关键的约束是：

- 同一时间只能一个 agent 跑 VM 测试

但现状只有文档提醒，没有 lock / lease / queue。

结果是：

- 并发 agent 很容易互相踩资源
- kernel worktree、VM、结果目录都会冲突
- 失败时也看不到“谁占着机器”

### 3.5 没有统一的状态追踪

当前状态管理分散：

- 本地 x86 VM：无状态
- 本地 ARM64 QEMU：无状态
- AWS ARM64：`.cache/aws-arm64/state/instance.env`
- CI：GitHub Actions job 页面

系统无法统一回答这些问题：

- 哪台机器现在忙不忙
- 正在跑哪个任务
- 是谁在跑
- 任务开始多久了
- 上次 heartbeat 是什么时候

### 3.6 代码/产物同步策略是 per-backend、per-benchmark 硬编码

当前存在三种同步模式：

- `vng` / QEMU: mount share
- AWS SSH: bundle + `scp`
- CI: `actions/checkout`

这些策略本身合理，但它们没有被抽象成 machine property，只是散落在脚本里。

### 3.7 CI 与本地配置割裂

“CI 和本地应该用同一套配置”目前没有做到。

当前 CI workflow 自己定义：

- `runs-on`
- benchmark 参数
- 依赖安装

本地 Makefile / AWS 脚本完全不知道这些 runner 的存在。

### 3.8 机器定义和构建定义混在一起

例如 ARM64 路径里：

- Docker image
- cross-build 脚本
- rootfs 生成
- QEMU 启动
- AWS 远端安装

这些都和“ARM64 机器”有关，但缺少中间层把它们组织为一个 machine profile。

---

## 4. 统一设计方案

### 4.1 设计目标

统一方案应该满足：

1. 同一个任务可以通过 `TARGET=` 指定在哪台机器上执行。
2. 所有机器都在一个中心 YAML 中注册。
3. 每台机器显式声明 arch、capabilities、连接方式、独占策略。
4. 调度器先支持手动选择，再逐步支持自动选择和排队。
5. 本地、远端、CI 使用同一套 machine naming / capability model。
6. 先复用现有脚本，不强行重写 benchmark 内部逻辑。

---

### 4.2 总体架构

建议增加一个轻量 machine control plane：

```text
Make target / CLI
        |
        v
Machine Resolver / Scheduler
        |
        +-- reads config/machines.yaml
        +-- checks capability / arch / locks
        +-- records state / lease
        |
        v
Backend Adapter
        |
        +-- vng backend
        +-- qemu backend
        +-- ssh backend
        +-- ci backend
        |
        v
Existing scripts / commands
```

关键原则：

- 机器注册统一
- backend 多态保留
- benchmark 实现先不大改

---

### 4.3 中心配置文件：`config/machines.yaml`

建议引入中心注册文件：

- `config/machines.yaml`

再配一个本地 override：

- `config/machines.local.yaml`

用法：

- `machines.yaml` 存 repo 中的共享定义
- `machines.local.yaml` 放主机路径、SSH key、私有主机名等本地信息
- CI 也读取同一 schema，只是 machine entry 不同

#### 4.3.1 建议 schema

每台机器建议至少声明以下字段：

- `id`
- `aliases`
- `backend`
- `arch`
- `os`
- `capabilities`
- `exclusive`
- `lock_groups`
- `connection`
- `workspace`
- `kernel`
- `build`
- `ci`

#### 4.3.2 示例

```yaml
version: 1

lock_groups:
  vm_global:
    max_parallel: 1
  arm64_crossbuild:
    max_parallel: 1

machines:
  - id: local-kvm
    aliases: [x86, local-x86, local-kvm]
    backend: vng
    arch: x86_64
    os: linux
    capabilities:
      - vm
      - custom-kernel
      - selftest
      - negative-test
      - micro
      - corpus
      - e2e
    exclusive: true
    lock_groups: [vm_global]
    connection:
      type: local
      launcher: runner/scripts/vng-wrapper.sh
    workspace:
      mode: rw-mount
      host_path: .
    kernel:
      image: vendor/linux-framework/arch/x86/boot/bzImage
      btf: vendor/linux-framework/vmlinux
      module_loader: module/load_all.sh
    defaults:
      cpus: 2
      memory: 4G

  - id: arm64-qemu
    aliases: [arm64-local, qemu-arm64]
    backend: qemu
    arch: arm64
    os: linux
    capabilities:
      - vm
      - custom-kernel
      - smoke
      - selftest
      - arm64
    exclusive: true
    lock_groups: [vm_global, arm64_crossbuild]
    connection:
      type: local
      launcher: qemu-system-aarch64
    workspace:
      mode: 9p-share
      host_path: .
      guest_mount: /mnt
    kernel:
      image: vendor/linux-framework/build-arm64/arch/arm64/boot/Image
      rootfs: ~/.cache/bpf-benchmark/arm64-rootfs
    build:
      crossbuild_image: bpf-benchmark-arm64-crossbuild:latest

  - id: aws-arm64-t4g
    aliases: [arm64, aws-arm64, t4g]
    backend: ssh
    arch: arm64
    os: amazonlinux2023
    capabilities:
      - remote
      - ssh
      - custom-kernel
      - arm64
      - micro
      - katran-smoke
    exclusive: true
    connection:
      type: ssh
      user: ec2-user
      host_env: AWS_ARM64_HOST
      key_env: AWS_ARM64_KEY_PATH
      stage_dir: /home/ec2-user/bpf-benchmark-arm64
      kernel_stage_dir: /home/ec2-user/codex-kernel-stage
    sync:
      mode: bundle
      strategy: tar+scp
    provision:
      instance_type: t4g.micro
      name_tag: bpf-benchmark-arm64
      profile_env: AWS_ARM64_PROFILE

  - id: gha-arm64
    aliases: [ci-arm64]
    backend: ci
    arch: arm64
    os: ubuntu
    capabilities:
      - ci
      - arm64
      - baseline
    exclusive: true
    ci:
      provider: github-actions
      runs_on: ubuntu-24.04-arm
      workflow: .github/workflows/arm64-benchmark.yml

  - id: gha-x86
    aliases: [ci-x86]
    backend: ci
    arch: x86_64
    os: ubuntu
    capabilities:
      - ci
      - x86
      - baseline
    exclusive: true
    ci:
      provider: github-actions
      runs_on: ubuntu-latest
      workflow: .github/workflows/x86-benchmark.yml
```

这个 schema 的核心不是字段名本身，而是把“机器事实”从脚本里抽出来。

---

### 4.4 Machine capability 模型

每台机器至少要能回答 4 个问题：

1. 它是什么架构？
2. 它能跑什么任务？
3. 它如何连接？
4. 它是不是独占资源？

建议 capability 粒度不要只停留在 `arch`，而要同时建模：

- 执行环境：`vm` / `remote` / `ci`
- 内核能力：`custom-kernel`
- benchmark 能力：`micro` / `corpus` / `e2e` / `selftest`
- 连接方式：`local` / `ssh` / `github-actions`
- 资源属性：`exclusive`

这样调度器才能做正确过滤。

例如：

- `local-kvm`：`x86_64 + vm + micro + corpus + e2e + selftest`
- `arm64-qemu`：`arm64 + vm + smoke + selftest`
- `aws-arm64-t4g`：`arm64 + remote + ssh + custom-kernel + micro`
- `gha-arm64`：`arm64 + ci + baseline`

---

### 4.5 Scheduler / Resolver 设计

### 4.5.1 输入

调度器输入建议是：

- `task_name`
- `TARGET`（可选）
- `arch` / `capability` 需求
- `exclusive` / `lock_group` 需求

例如：

- `make vm-micro TARGET=local-kvm`
- `make vm-micro TARGET=arm64`
- `make vm-corpus TARGET=local-kvm`

其中 `TARGET` 可以是：

- machine id
- alias
- 未来也可以是 capability selector

### 4.5.2 输出

调度器输出应该是一个 resolved machine record：

- 选中了哪台机器
- 为什么选中
- 需要 export 哪些参数
- 需要申请哪些 lock

### 4.5.3 调度策略

完整方案里建议支持三层约束：

1. **兼容性过滤**
   - arch 是否匹配
   - capability 是否满足
2. **独占过滤**
   - machine 是否正忙
   - shared lock group 是否可用
3. **选择策略**
   - 手动 `TARGET=` 优先
   - 否则选 `preferred` machine
   - 否则报 ambiguous

当前最重要的 shared lock group 是：

- `vm_global`: `max_parallel = 1`

这正好把“同一时间只能一个 agent 跑 VM 测试”的文档约束变成系统约束。

---

### 4.6 状态追踪与 lease

建议增加统一状态目录：

- `.cache/machine-manager/`

其中至少包含：

- `state.json`
- `leases/<machine-id>.json`
- `locks/<lock-group>.lock`

每条 lease 建议记录：

- `machine_id`
- `task_name`
- `owner`
- `pid`
- `hostname`
- `started_at`
- `heartbeat_at`
- `output_path`
- `status`

这样可以直接回答：

- 哪台机器空闲
- 谁正在占用
- 跑了多久
- 是不是 stale lease

#### 4.6.1 MVP 行为

MVP 不需要真正的排队系统，但至少应做到：

- 申请 machine lease
- 申请 lock group
- 失败时输出“busy because ...”
- 任务结束后释放

#### 4.6.2 后续扩展

后续才考虑：

- 队列
- wait / wake-up
- 自动重试
- lease heartbeat
- stale cleanup

---

### 4.7 Makefile 集成

目标不是替换现有 user-facing target，而是保留它们，并给它们加统一 machine 选择入口。

#### 4.7.1 建议接口

```bash
make vm-micro TARGET=local-kvm
make vm-corpus TARGET=local-kvm
make vm-micro TARGET=arm64
make vm-selftest TARGET=arm64-qemu
make benchmark-baseline TARGET=gha-arm64
```

这里：

- `TARGET=local-kvm` 明确指定机器
- `TARGET=arm64` 走 alias / preferred machine 解析

#### 4.7.2 Makefile 层只做两件事

1. 调用 resolver，得到 resolved machine config
2. 把已有 benchmark target 交给 backend adapter 执行

即：

- 不是在 `Makefile` 里继续堆更多 `if TARGET=...`
- 而是 `Makefile -> machine resolver -> backend adapter`

#### 4.7.3 backend adapter 如何复用现有实现

建议先包裹现有逻辑，而不是一口气重写：

- `vng backend`
  - 复用 `runner/scripts/vng-wrapper.sh`
  - 逐步收敛 `Makefile` / `corpus/modes.py` / `runner/libs/vm.py`
- `qemu backend`
  - 复用 `runner/scripts/arm64_qemu_smoke.py`
- `ssh backend`
  - 先复用 `runner/scripts/aws_arm64.sh`
  - 后续再把 bundle/sync 抽象出来
- `ci backend`
  - 先做 metadata / validation
  - 让 workflow 用同一 registry 做自检与参数解析

这能显著降低迁移风险。

---

### 4.8 代码同步模型

统一系统必须把“代码如何进入目标机器”也显式建模。

建议在 machine config 里声明 `workspace.mode` / `sync.mode`：

- `mount`
  - 本地 `vng`
  - 本地 ARM64 QEMU host-share
- `bundle`
  - AWS ARM64 tar + scp
- `checkout`
  - GitHub Actions

这样同一个 task 可以根据 machine backend 自动选择：

- 本地 VM：挂 repo
- 远端 SSH：打包上传
- CI：直接用 checkout 后 workspace

这比现在把同步逻辑埋在脚本里更可维护。

---

### 4.9 CI 与本地共用配置

“CI 和本地应该用同一套配置”可以这样落地：

1. workflow 仍然保留 `runs-on`
   - 这是 GitHub Actions 的平台事实，不能取消
2. 但 workflow 在 repo 内部把自己标识为某个 machine id
   - 例如 `TARGET=gha-arm64`
3. benchmark 参数、capability 定义、任务兼容性检查都从 `config/machines.yaml` 读取

这样可以做到：

- 本地文档和 CI runner 说的是同一套 machine name
- capability 变更只改一处
- workflow 能在启动时验证自己确实匹配 machine profile

如果未来改用 self-hosted runner，这个模型也不需要推倒重来，只需要把 `ci` backend 从 hosted label 换成 self-hosted label/group。

---

## 5. 参考业界方案

### 5.1 Buildbot

Buildbot 的有用点是：

- worker 注册
- builder -> worker capability 匹配
- worker locks
- scheduler 与 queue

对本项目最有借鉴意义的是：

- **静态 worker registry**
- **lock / exclusivity**
- **builder 与 worker 解耦**

本项目不需要它的完整 master/worker 体系，但很适合借它的“注册 + 匹配 + locks”思想。

### 5.2 Bazel Remote Execution

Bazel Remote Execution 的有用点是：

- action 与 execution platform 分离
- platform properties 约束匹配
- 远端执行与本地执行统一接口

对本项目最值得借鉴的是：

- **task requirement 与 machine property 的解耦**
- **capability / platform property 匹配**

但它的 CAS、hermetic execution、分布式调度对当前项目明显过重。这里借鉴概念，不借鉴完整系统复杂度。

### 5.3 GitHub Actions self-hosted runners

GitHub Actions self-hosted runner 的有用点是：

- runner labels
- runner groups
- 每台 runner busy/idle 状态明确
- job -> label -> runner 的映射模型简单直观

对本项目最直接的借鉴是：

- **用 label / alias 表达 capability**
- **每台机器天然独占一个 job**
- **统一 machine naming，让 CI 与本地说同一种语言**

### 5.4 对本项目最合适的组合

本项目最适合的不是完整 Bazel RE，而是：

- Buildbot 风格的 worker registry + lock
- GitHub Actions 风格的 label/alias + busy/idle
- Bazel 风格的 capability/property 匹配

---

## 6. 最小 MVP

### 6.1 MVP 目标

MVP 只做：

1. 统一机器注册
2. 手动 `TARGET=` 选择
3. 基础 busy/idle / lease
4. 统一 machine metadata

MVP 不做：

1. 自动最佳机器选择
2. 自动排队
3. 自动 EC2 伸缩
4. 通用 rsync/cas artifact system
5. 跨多用户的复杂公平调度

### 6.2 MVP 的最小功能面

建议 MVP 至少包含：

- `config/machines.yaml`
- `config/machines.local.yaml`（gitignored）
- `machine list`
- `machine status`
- `machine resolve --task vm-micro --target arm64`
- `make vm-micro TARGET=local-kvm`
- `make vm-corpus TARGET=local-kvm`
- `make vm-selftest TARGET=arm64-qemu`

### 6.3 MVP 的实现原则

MVP 应该复用现有 backend：

- 本地 x86 继续调用现有 `vng` 路径
- ARM64 QEMU 继续调用现有 `arm64_qemu_smoke.py`
- AWS 继续调用现有 `aws_arm64.sh`
- CI 先只读取 machine metadata

换句话说，MVP 的核心是“先统一控制面，不先重写执行面”。

---

## 7. 建议的演进顺序

### Phase 0：注册与解析

- 增加 `config/machines.yaml`
- 增加 resolver
- 明确 machine id / alias / capabilities

### Phase 1：Makefile 接口统一

- 所有 VM / ARM64 / AWS 相关 target 增加 `TARGET=`
- backend adapter 先包现有脚本
- 增加 basic lease / busy 检查

### Phase 2：状态与锁

- 落地 `vm_global` lock
- 落地 `.cache/machine-manager/state.json`
- 增加 `machine status`

### Phase 3：CI 收敛

- workflow 读取同一 machine config
- 本地 / CI 共用 task -> machine requirement 定义

### Phase 4：自动调度与排队

- 支持 `TARGET=auto`
- 支持 preferred machine
- 支持 queue / heartbeat / stale lease cleanup

---

## 8. 关键设计取舍

### 8.1 为什么先做“注册 + 手动选择”，不先做自动调度

因为当前真正缺的不是复杂算法，而是基础事实模型：

- 有哪些机器
- 各自能干什么
- 谁现在忙

在这些都没有统一之前，自动调度只会把混乱自动化。

### 8.2 为什么 machine config 要区分 repo-shared 与 local override

因为机器定义里会混入：

- SSH key path
- 私有 IP / host
- 用户目录

这些不能全部进 repo。

所以共享文件描述机器“形状”，本地 override 填具体连接信息，是更现实的方式。

### 8.3 为什么要单独建 `lock_groups`

因为“独占”不是只有“某台机器一次只能跑一个任务”。

当前已经存在跨机器共享资源：

- VM 测试全局串行约束
- ARM64 worktree / build dir
- 可能未来还会有共享 AWS quota、共享物理机等

所以需要：

- `machine exclusive`
- `shared lock group`

两层模型。

---

## 9. 风险与未决问题

1. `TARGET=arm64` 如果同时匹配 `arm64-qemu` 和 `aws-arm64-t4g`，是自动选 preferred，还是要求明确指定？
2. AWS 的 `launch/setup/benchmark/terminate` 是否继续保留显式命令，还是最终折叠成通用 `machine provision` / `machine run`？
3. 本地 ARM64 QEMU 是否应该扩展到支持完整 `vm-micro` / `vm-corpus`，还是只保留 smoke/selftest？
4. CI 是否要继续使用 GitHub-hosted runner，还是未来迁到 self-hosted 并与 machine registry 更紧密对齐？
5. 远端同步是否长期保持 `tar + scp`，还是未来抽象成 `rsync` / content-addressed cache？

这些问题不阻塞 MVP，但应该在 Phase 1-3 期间明确。

---

## 10. 建议落地结论

推荐结论如下：

1. 把机器管理问题正式建模为“machine registry + resolver + backend adapter”。
2. 中心事实源放在 `config/machines.yaml`。
3. 先不做自动调度，先做手动 `TARGET=` 与统一 lease/state。
4. 把当前“只能一个 agent 跑 VM 测试”从文档规则升级为 `vm_global` lock。
5. 保留现有 `vng` / QEMU / AWS 脚本，先包一层，不先重写 benchmark 实现。
6. 让 CI runner 也进入同一 machine naming / capability 体系，至少共享配置与校验逻辑。

如果只做一个最小可落地版本，我建议是：

- `config/machines.yaml`
- `machine resolve/list/status`
- `make vm-micro TARGET=...`
- `make vm-corpus TARGET=...`
- `vm_global` file lock

这一步就足以把当前“多套入口、无注册、无锁、无状态”的问题收敛到一个可演进的控制面。
