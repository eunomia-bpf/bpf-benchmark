# GitHub Actions ARM64 runner KVM 调研（2026-03-19）

## 结论先行

| 问题 | 结论 | 置信度 |
|---|---|---|
| 1. `ubuntu-24.04-arm` 有没有 `/dev/kvm`？ | 近期公开实测表明 **没有，至少不能依赖它存在**。我找到的 2025-01 公开日志在 `ubuntu-24.04-arm` 上直接报 `Could not access KVM kernel module: No such file or directory`。GitHub 官方也没有给 ARM64 standard runner 提供 `/dev/kvm` 保证。 | 高 |
| 2. GitHub larger ARM64 runner 有没有 `/dev/kvm`？ | **没有找到 GitHub 官方 ARM64-specific 的 KVM 保证**。GitHub 只确认 ARM64 Ubuntu larger runner 这个产品存在，但同时明确说 nested virtualization **不受官方支持**。因此，工程上应按“**不可依赖 `/dev/kvm`**”处理。 | 中 |
| 3. 如果有 KVM，能不能用 `vng` / QEMU 启动自定义 kernel？ | **能。** `virtme-ng`/`vng` 本来就是给“编译并启动自定义 Linux kernel”用的；它在 GitHub Actions 上也有 KVM 示例，但我找到的是 **Linux x64** 示例，不是 ARM64 runner 示例。 | 高（能力本身），中（套到 GitHub ARM64 runner） |
| 4. 我们能不能在 GitHub ARM64 runner 上跑 `make vm-micro`（`vng boot` 自定义 `bzImage`/`Image.gz`）？ | **按当前仓库和当前 GitHub ARM64 runner 情况，不建议，也不能当作可靠 CI 方案。** 原因有两个：一是 ARM64 GitHub runner 没有可靠 KVM 证据；二是仓库当前 `make vm-micro` 入口本身就是 **x86 `bzImage` 假设**。 | 高 |
| 5. 如果不行，有没有别的办法在 GitHub runner 上跑自定义 kernel？ | **有，但要换方案。** 最靠谱的是 self-hosted ARM64；次优是 GitHub 只负责构建，外部 ARM64 机器负责 boot/test；如果只做功能 smoke test，可以用纯 QEMU TCG，但不适合 benchmark。 | 高 |
| 6. 仓库里有没有已有 ARM64 CI？ | **有。** `.github/workflows/arm64-benchmark.yml` 已经在 `ubuntu-24.04-arm` 上跑 ARM64 CI，但它走的是 **native benchmark**，**不走 VM，不走 `vng`，不 boot 自定义 kernel**。 | 高 |

## 外部资料与推断

### 1. GitHub standard ARM64 runner：官方确认产品存在，但没有给 `/dev/kvm` 保证

GitHub 官方 runner 文档现在明确列出了 standard ARM64 Linux runner：

- `ubuntu-24.04-arm`
- `ubuntu-22.04-arm`

来源：

- GitHub-hosted runners reference
  - https://docs.github.com/en/actions/reference/runners/github-hosted-runners

同一套官方文档还写了一个关键 caveat：

- “While nested virtualization is technically possible while using runners, it is not officially supported.”

来源：

- GitHub-hosted runners
  - https://docs.github.com/en/actions/concepts/runners/github-hosted-runners

这句话很重要，因为它意味着：

- GitHub **没有把 nested virtualization / KVM 暴露当成承诺能力**
- 即便某些 runner、某些时间点、某些底层宿主机能工作，也不代表它是稳定 contract

### 2. `ubuntu-24.04-arm` 上有近期公开失败案例，错误就是 `/dev/kvm` 不存在

我找到一个 2025-01-27 的公开 issue，直接点名要在 `ubuntu-24.04-arm` 上跑 aarch64 guest。日志里报错：

`Could not access KVM kernel module: No such file or directory`

来源：

- lima issue #3156
  - https://github.com/lima-vm/lima/issues/3156

这个证据不是 GitHub 官方文档，但它是：

- 时间较新的公开实测
- 平台就是 `ubuntu-24.04-arm`
- 错误信息直接指向 `/dev/kvm` 缺失

所以对问题 1，我的结论是：

- **当前 standard ARM64 runner 不应假设有 `/dev/kvm`**

### 3. GitHub larger ARM64 runner：产品存在，但我没有找到 ARM64-specific 的 KVM 证据

GitHub 官方 larger runners 文档确认了 ARM64 Ubuntu larger runner 规格存在，例如：

- 2 vCPU / 8 GB / 75 GB，`x64, arm64` Ubuntu
- 4 / 8 / 16 / 32 / 64 vCPU 里也有 `arm64` Ubuntu

来源：

- Larger runners reference
  - https://docs.github.com/en/actions/reference/runners/larger-runners

但这份文档 **没有** 说：

- ARM64 Ubuntu larger runner 一定暴露 `/dev/kvm`
- ARM64 Ubuntu larger runner 支持 nested virtualization

同时，GitHub 官方仍然在通用 runner 文档里声明 nested virtualization **不受官方支持**。

因此对问题 2，更准确的回答不是“官方明确说没有”，而是：

- **我没有找到官方 ARM64-specific 的 `/dev/kvm` 支持声明**
- **官方只给了 ARM64 larger runner 产品规格，没有给 nested virtualization SLA/guarantee**
- 所以 CI 设计上应按“**不可依赖 `/dev/kvm`**”处理

### 4. `vng` / QEMU 启动自定义 kernel：工具能力本身是有的

`virtme-ng` README 明确说明它就是用来快速 build/run Linux kernel 的；示例里也展示了：

- 运行重新编译的 kernel
- 运行预编译 kernel
- 构建 ARM64 kernel（`--arch arm64`）

来源：

- virtme-ng README
  - https://github.com/arighi/virtme-ng

同一个 README 还提到：

- “You will have a much better experience if KVM is enabled.”
- 在 GitHub Actions 上，KVM 支持可用于 “larger Linux runners”，但需要手动启用

不过这里要注意边界：

- 这是 `virtme-ng` 项目的说明，不是 GitHub 官方对 ARM64 runner 的承诺
- README 里指向的工作流示例是 `ubuntu-latest`，不是 `ubuntu-24.04-arm`

来源：

- virtme-ng workflow example
  - https://github.com/arighi/virtme-ng/blob/main/.github/workflows/run.yml

这个 workflow 里的关键步骤是：

- 安装 `qemu-kvm`
- 写一条 udev rule，把 `/dev/kvm` 设成可访问
- 用 guest 里的 `kvm-clock` 验证 KVM 生效

这说明：

- **如果 runner 上确实有 `/dev/kvm`，`vng`/QEMU 启动自定义 kernel 这条路是成立的**
- 但我找到的是 **x64 GitHub Linux runner** 证据，不是 ARM64 GitHub runner 证据

## 对你 5 个问题的直接回答

### 1. GitHub standard ARM64 runner (`ubuntu-24.04-arm`) 有没有 `/dev/kvm`？

结论：

- **按最新公开信息，不能指望有。**

依据：

- GitHub 官方文档没有给 ARM64 standard runner 的 `/dev/kvm` 保证
- GitHub 官方明确说 nested virtualization 不受官方支持
- 2025-01 的公开实测在 `ubuntu-24.04-arm` 上报 `/dev/kvm` 不存在

### 2. GitHub larger ARM64 runner 有没有 `/dev/kvm`？

结论：

- **没有找到可依赖的官方肯定答案。工程上应按“不支持/不可依赖”处理。**

依据：

- GitHub 官方只说明 ARM64 Ubuntu larger runner 规格存在
- 没有找到 ARM64-specific 的 `/dev/kvm` / nested virt 支持条款
- GitHub 对 nested virtualization 的统一口径仍然是“不受官方支持”

如果团队愿意花一次 paid run 去做最小验证，最便宜的办法不是改仓库，而是单独起一个探针 workflow，检查：

```bash
ls -l /dev/kvm || true
test -e /dev/kvm && sudo stat /dev/kvm || true
egrep -i 'vmx|svm' /proc/cpuinfo || true
```

但在没有这类实测前，我不会把 ARM64 larger runner 当作可用 KVM 平台写进 CI 设计。

### 3. 如果有 KVM，能不能用 `vng` / QEMU 启动自定义 kernel？

结论：

- **能。**

更准确地说：

- QEMU 本来就能 boot 自定义 kernel
- `virtme-ng` / `vng` 本来就是为“快速测试自定义 Linux kernel”设计的
- 在 GitHub Actions 上，如果 `/dev/kvm` 存在，通常还要处理 `/dev/kvm` 权限

但这不自动推出“GitHub ARM64 runner 可以这么干”，因为 ARM64 runner 是否有 `/dev/kvm` 本身就是未证实/不受支持的点。

### 4. 我们能不能在 GitHub ARM64 runner 上跑 `make vm-micro`（用 `vng boot` 自定义 `bzImage` / `Image.gz`）？

结论：

- **当前仓库下，不能把这当成现成可用方案。**

原因 A：平台侧

- `ubuntu-24.04-arm` 没有可靠 KVM 证据
- ARM64 larger runner 也没有找到官方 `/dev/kvm` 保证

原因 B：仓库实现侧

- 当前顶层 Makefile 默认 kernel 镜像就是 x86 的 `vendor/linux-framework/arch/x86/boot/bzImage`
- `make kernel` 构建的是 `bzImage`
- `$(BZIMAGE_PATH)` 的增量构建目标也构建 `bzImage`
- `verify-build` 的校验信息和 stale detection 也写死了 x86 `bzImage` 语义

因此就算把平台问题先放到一边，**当前仓库也不是“拿 ARM64 runner + `Image.gz` 就能直接跑 `make vm-micro`”**。

### 5. 如果不行，有没有别的办法在 GitHub runner 上跑自定义 kernel？

有，分成 4 条路线：

#### 路线 A：self-hosted ARM64 runner

这是最靠谱的。

适合：

- 真要 boot 自定义 ARM64 kernel
- 真要依赖 `/dev/kvm`
- 真要跑 benchmark，而不是只做功能 smoke test

推荐优先级最高，因为：

- `/dev/kvm` 是否存在、权限怎么配、CPU 型号、频率稳定性，都由你们自己控制
- benchmark 结果也更可信

#### 路线 B：GitHub-hosted ARM64 只负责 build，外部 ARM64 机器负责 boot/test

这是 CI 上最现实的折中方案。

做法：

- GitHub `ubuntu-24.04-arm` 负责编译 `Image.gz`、userspace、测试脚本、artifact
- 外部 ARM64 机器负责 `vng`/QEMU/KVM 或直接 native boot
- 再把结果回传为 artifact / PR comment / status

优点：

- 保留 GitHub Actions 的 orchestration
- 不把最脆弱的 nested virt/KVM 依赖绑在 GitHub-hosted ARM64 runner 上

#### 路线 C：纯 QEMU TCG，只做功能验证，不做 benchmark

如果目标只是：

- 自定义 kernel 能不能启动
- 基本自测能不能过
- 某个 BPF path 能不能 smoke

那可以不用 KVM，直接用纯 QEMU TCG。

但缺点非常明显：

- 慢很多
- 时间抖动大
- 不适合做 `vm-micro` 这种 benchmark

另外，对 `virtme-ng` 而言，ARM64 host 上无 KVM 跑 ARM64 guest 这条路径在 2025-01 还有公开问题，所以 **更稳妥的是直接写 `qemu-system-aarch64` 命令行**，不要把这件事完全赌在 `vng` 自动 fallback 上。

#### 路线 D：如果只是想保留当前 `make vm-micro`，那就继续用 x86 Linux runner

当前仓库 `vm-micro` 的默认入口本来就是：

- x86 `bzImage`
- `vng --run "$(BZIMAGE_PATH)"`

所以如果需求是：

- “尽快把现有 `make vm-micro` 放进 GitHub Actions”

那更顺的路径是：

- 用 **x86 Linux runner**
- 确认 `/dev/kvm` 可用
- 继续跑现有 `bzImage` 路线

而不是把当前 x86 VM harness 硬拗成 ARM64 hosted runner。

## 仓库内现状

### 6. `.github/workflows/` 里已有 ARM64 CI 吗？它怎么做的？

有。

文件：

- `.github/workflows/arm64-benchmark.yml`

它的特点：

- `runs-on: ubuntu-24.04-arm`
- 安装 clang / llvm / libbpf / libelf / zlib / libzstd / PyYAML
- `make -C micro`
- 跑 `python3 micro/driver.py suite`
- runtime 只用了 `llvmbpf` 和 `kernel`
- **没有** `vng`
- **没有** VM boot
- **没有** `kernel-recompile`
- **没有** 自定义 kernel artifact

对应地，仓库当前 VM 路径都还在 x86 假设上：

- `Makefile` 默认 `BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage`
- `make kernel` 构建 `bzImage`
- `make vm-micro` 调 `vng --run "$(BZIMAGE_PATH)"`
- `verify-build` 的 stale check 也在看 x86 路径

所以当前仓库里的 ARM64 CI 设计逻辑其实很明确：

- **ARM64 runner 只做 native benchmark**
- **VM + custom kernel 这条线仍然是 x86-first**

## 我没有找到的证据

下面这些点我专门查了，但没有找到足够强的公开证据：

- GitHub 官方明确写“ARM64 Ubuntu larger runner 暴露 `/dev/kvm`”
- GitHub 官方明确写“`ubuntu-24.04-arm` 支持 nested virtualization”
- 一份近期、可复现、公开的 **ARM64 larger runner + `/dev/kvm` 成功案例**
- 一份近期、公开的 `virtme-ng` 在 **GitHub ARM64 runner** 上成功启 ARM64 guest kernel 的 CI workflow

所以对问题 2 和问题 4，我刻意用了“**不可依赖**”而不是“绝对不可能”。

## 建议

如果目标是“尽快在 CI 上把自定义 kernel 跑起来”，优先级建议是：

1. **要 benchmark / 要稳定**：上 self-hosted ARM64
2. **想保留 GitHub 作为调度器**：GitHub-hosted ARM64 只 build，外部 ARM64 机器 boot/test
3. **只要功能 smoke**：纯 QEMU TCG
4. **想复用当前 `make vm-micro` 最少改动**：继续用 x86 Linux runner，不要先选 GitHub-hosted ARM64

## 参考资料

- GitHub-hosted runners reference
  - https://docs.github.com/en/actions/reference/runners/github-hosted-runners
- GitHub-hosted runners
  - https://docs.github.com/en/actions/concepts/runners/github-hosted-runners
- Larger runners reference
  - https://docs.github.com/en/actions/reference/runners/larger-runners
- Arm64 on GitHub Actions: Powering faster, more efficient build systems
  - https://github.blog/news-insights/product-news/arm64-on-github-actions-powering-faster-more-efficient-build-systems/
- actions/partner-runner-images: Ubuntu 24.04 by Arm Limited
  - https://github.com/actions/partner-runner-images/blob/main/images/arm-ubuntu-24-image.md
- lima issue #3156
  - https://github.com/lima-vm/lima/issues/3156
- virtme-ng README
  - https://github.com/arighi/virtme-ng
- virtme-ng GitHub Actions workflow example
  - https://github.com/arighi/virtme-ng/blob/main/.github/workflows/run.yml
