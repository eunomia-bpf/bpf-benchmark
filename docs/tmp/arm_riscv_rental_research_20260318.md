# ARM64 / RISC-V 租用方案补充调研（2026-03-18）

> 说明：workspace 中未找到同名旧文件或旧版正文；以下内容按“补充追加段落”组织，可直接接到前一版调研之后。

## 8. 更便宜的 ARM64 方案补充

### 8.1 AWS Spot（c7g / c6g）

- AWS 官方仍把 Spot 定义为“最高可比 On-Demand 便宜 90%”，但前提是实例可被回收；Spot 和 On-Demand 的核心差异就是可中断，通常只有约 2 分钟中断通知。
- EC2 支持按秒计费，最小 60 秒；如果 benchmark 真的是“创建 -> 跑 2-3 小时 -> 删除”，AWS 这种按需/Spot 都能精确吃到短时计费收益。
- 自定义 kernel 可行，但路径不是“在 GitHub-hosted runner 那样直接换 kernel”，而是用自定义 AMI / 自带 bootloader 的实例镜像。AWS 文档也明确支持 user-provided kernel；对 Graviton，默认 boot mode 是 `uefi`。
- 是否适合 benchmark：
  - 适合：开发期 smoke、功能验证、便宜地多跑几轮、可重试的 batch benchmark。
  - 不适合：单次长跑且不能中断的 authoritative benchmark；尤其是你要稳定测 tail latency / 细微速度差时，Spot 的中断风险会让脚本和结果管理复杂很多。
  - 实践建议：Spot 用于 exploratory run；最终要写结论的数字，尽量切回 On-Demand 或至少做自动重试和多次重复。

### 8.2 Oracle Cloud Free Tier ARM

- Oracle 官方 Always Free ARM 额度仍是 `4 OCPU + 24 GB RAM`，文档同时给出了等价月额度：`3000 OCPU-hours + 18000 GB-hours`。
- Oracle 文档说明 Always Free 资源本身“不被回收”；但 Oracle FAQ 也明确写了 Free Tier **没有 SLA**。
- 对本仓库是否够用：
  - 如果采用“本地交叉编译 + 远端只跑测试”，`4 OCPU / 24 GB` 明显够。
  - 如果要在远端本机编 `micro_exec`/`scanner`，也够。
  - 如果还要在远端频繁 full kernel build、并行多任务、跑更重的 e2e/corpus，全流程会偏慢，但不是内存瓶颈，主要是 CPU 和容量/稳定性预期问题。
- 结论：Oracle Free Tier ARM 很适合“零租金 ARM64 smoke / CI worker / 夜间验证”，但不适合把“作者最终性能结论”绑定在一个无 SLA 的免费共享环境上。

### 8.3 Hetzner Cloud CAX（共享 ARM）

- Hetzner 官方云页把 shared ARM/cloud 直接定位为：
  - `Perfect for test environments`
  - `shared resources`
  - 更适合“low to medium CPU usage”
- 这和你的需求基本吻合：它非常适合初步验证、CI、自托管 runner、可接受一些噪声的 benchmark screening。
- 但它**不适合**把很细的 perf delta 当最终结论，因为 shared CPU 本身就意味着邻居噪声和时间片抖动。
- 成本上，用户给出的 `CAX21 ≈ €6/月` 量级基本就是这类方案的优势所在：如果真按 3 小时创建后立刻释放，单次成本通常就是几欧分。
- 这条路的最大价值不是“绝对性能最好”，而是“比 GitHub-hosted ARM64 更便宜、比 Oracle 免费层更可控、还能当自托管 runner”。

### 8.4 3 小时 benchmark 的粗略成本

以下统一按“创建后即跑，跑完立即删除/terminate”估算；不含持久卷、快照、流量等附加项。

| 方案 | 计费口径 | 3 小时粗估 | 备注 |
| --- | --- | ---: | --- |
| AWS c7g.xlarge On-Demand | 约 `$0.145~0.15/h` 量级 | `$0.44~0.45/次` | 适合需要更稳定环境的正式跑数 |
| AWS c7g.xlarge Spot | 若按 On-Demand 的 `30%-70%` 折扣 | 约 `$0.13~0.31/次` | 便宜，但要处理中断 |
| Hetzner CAX21 | 约 `€6/月` 量级折算小时 | 约 `€0.02~€0.03/次` | 很适合 screening / self-hosted runner |
| Oracle Free Tier ARM | Always Free 配额内 | `$0/次` | 无 SLA，适合开发/验证 |
| GitHub-hosted ARM64 standard | `Linux 2-core (arm64) = $0.005/min` | `$0.90/次` | 私有仓库计费；公有仓库 standard runner 免费 |
| GitHub-hosted ARM64 larger 4-core | `Linux 4-core (arm64) = $0.008/min` | `$1.44/次` | 比自租 Hetzner/AWS ARM64 通常更贵 |
| Scaleway EM-RV1 | 你给出的 `€0.04/h` 估算 | `€0.12/次` | 本轮未找到足够清晰的当前官方 hourly 页面，先当 provisional 预算值 |

结论很直接：

- **最便宜 ARM64**：Oracle Free Tier。
- **最便宜且可控的付费 ARM64**：Hetzner CAX。
- **最适合“自定义 kernel + 自动化”**：AWS。
- **最不划算的长跑 ARM64**：GitHub-hosted ARM64（除非你是公有仓库，或只跑很短的 CI）。

## 9. 自动化租用与自动释放

### 9.1 CLI 自动创建 / 删除完全可行

三家都可以做成脚本：

| 平台 | 创建 | 删除 | 凭证 |
| --- | --- | --- | --- |
| AWS | `aws ec2 run-instances` | `aws ec2 terminate-instances` | `~/.aws/config` + `~/.aws/credentials`，或 GitHub OIDC |
| Hetzner | `hcloud server create` | `hcloud server delete` | `HCLOUD_TOKEN` |
| OCI | `oci compute instance launch` | `oci compute instance terminate` | `~/.oci/config` + API signing key，或 token-based auth |

### 9.2 凭证与安全建议

- AWS：
  - 本地脚本可直接用 `aws configure` 写入 `~/.aws/credentials`。
  - GitHub Actions 里优先用 OIDC 假设 IAM role，不要放长期 `AWS_ACCESS_KEY_ID` / `AWS_SECRET_ACCESS_KEY`。
  - 权限建议收敛到最小集：`ec2:RunInstances`、`ec2:TerminateInstances`、`ec2:Describe*`、必要时 `iam:PassRole`。
- Hetzner：
  - 使用 project API token，放在 `HCLOUD_TOKEN`。
  - GitHub Actions 里直接放 repo/org secret 即可；Hetzner 官方 `setup-hcloud` action 也是这么要求的。
- OCI：
  - OCI CLI 默认是 `~/.oci/config` + API signing key。
  - 如果放进 CI，建议单独 compartment、单独 user、单独 key。
- 通用建议：
  - 所有 destroy/terminate 操作都放在 shell `trap` 里，保证失败也自动清理。
  - 提供 `KEEP_ON_FAILURE=1` 开关，调试时保留机器，默认关闭。
  - 结果先 `scp/rsync` 回本地，再 terminate。
  - 远端尽量不用开放公网 root SSH；AWS 可优先用 SSM，会更干净。

### 9.3 适合本仓库的自动化骨架

建议做成一个 provider-neutral 脚本，例如 `scripts/benchmark_arm64.sh`：

1. 本地构建 ARM64 artifacts。
2. `create_instance(provider=aws|hcloud|oci)`。
3. 等 SSH/SSM 可用。
4. `rsync` 上传 `micro_exec`、`.bpf.o`、可选 `scanner`、可选 kernel image。
5. 远端安装最小运行时依赖。
6. 远端跑 benchmark。
7. `rsync` 拉回 JSON / logs。
8. `trap` 中统一 destroy。

伪代码：

```bash
trap cleanup EXIT

build_local_arm64_artifacts
instance_id=$(create_instance)
wait_until_ready "$instance_id"
sync_artifacts "$instance_id"
run_remote_benchmark "$instance_id"
fetch_results "$instance_id"
```

## 10. GitHub Actions ARM64 / RISC-V 可行性

### 10.1 GitHub-hosted ARM64 现在有什么

- GitHub 官方标准 hosted runner 现在已经有 ARM64 Linux：
  - `ubuntu-24.04-arm`
  - `ubuntu-22.04-arm`
- 官方文档给出的资源：
  - 公有仓库 standard ARM64：`4 CPU / 16 GB RAM / 14 GB SSD`
  - 私有仓库 standard ARM64：当前文档仍以 `2-core arm64` 计费，适合普通 CI，但不适合重 build + 长 benchmark
- GitHub-hosted runner 是“每个 job 一台新的 VM”；因此它是很好的 CI 执行环境，但不是长期稳定的 benchmark 主机。

### 10.2 GitHub-hosted ARM64 价格

截至 2026-03-18，这一轮能确认到的官方价格是：

- standard `Linux 2-core (arm64)`: `$0.005/min`
- larger `Linux 4-core (arm64)`: `$0.008/min`
- 所以连续 3 小时：
  - standard：`180 × 0.005 = $0.90`
  - 4-core larger：`180 × 0.008 = $1.44`

和 Hetzner / AWS Spot 相比，这个价格对长时间 benchmark 明显不占优。

### 10.3 自托管 runner

- GitHub 官方 self-hosted runner 支持的处理器架构是：
  - `x64`
  - `ARM64`
  - `ARM32`
- 这意味着 ARM64 自托管是官方支持路径。
- 当前 GitHub 文档仍写明：**self-hosted runners 免费**。注意：
  - GitHub 在 2025-12-16 公布过一个“从 2026-03-01 起对 self-hosted 加平台费”的计划。
  - 但同一变更在后续又被官方宣布 **postponed**。
  - 所以按 2026-03-18 的文档状态，结论仍然是：**自托管 runner 只付机器费，不付 GitHub runner 分钟费**。

这很重要，因为它使得“Hetzner/Oracle/AWS ARM64 机器 + self-hosted runner”成为比 GitHub-hosted ARM64 更省钱的长期方案。

### 10.4 GitHub-hosted runner 上能不能跑 custom kernel / insmod / BPF

- Linux / macOS 的 GitHub-hosted runner 有 passwordless `sudo`，所以“普通 root 用户态操作”是可以的。
- 但 GitHub-hosted runner 本质上仍是 GitHub 管理的临时 VM：
  - 不能把它当成你自己的裸机。
  - 不能可靠依赖“我要重启进自己的 kernel”。
  - larger runner 的 custom image 只是在 VM 镜像层面预装工具和依赖，不等于你获得 bootloader / hypervisor 控制权。
  - GitHub 文档还明确写了 nested virtualization “technically possible but not officially supported”。
- 对你的场景的真实含义：
  - `apt install clang bpftool`、普通编译、用户态测试：可以。
  - 基于 stock kernel 的 BPF smoke：可能可以。
  - 依赖你自己 patch 的 kernel、`BPF_PROG_JIT_RECOMPILE`、稳定 perf 环境：**不应该指望 GitHub-hosted runner**。
  - `qemu` / `vng` 在 GitHub runner 上即便能跑，也只是实验性路径，不适合拿结果做 benchmark 结论。

### 10.5 RISC-V GitHub Actions

- **官方 GitHub-hosted runner：没有 RISC-V。**
- **官方 self-hosted 支持矩阵：也没有 RISC-V。**
- 所以结论是：GitHub Actions 对 RISC-V 的官方支持目前仍然不完整，至少不是一条“装上官方 runner 就完事”的路径。
- 对你最现实的做法是：
  - GitHub Actions 仍在 x86/ARM64 runner 上执行 orchestration；
  - workflow 通过 SSH/API 去控制外部 RISC-V 机器；
  - 真正的 benchmark 在外部 RISC-V 机器跑；
  - GitHub 只负责触发、收集结果和归档 artifact。

### 10.6 QEMU RISC-V 在 x86 runner 上跑 benchmark 有意义吗

- 有意义的场景：编译验证、功能自测、内核/程序可启动性、回归测试。
- 没意义的场景：性能 benchmark。
- 原因很简单：你测到的是“x86 host + QEMU 模拟器 + RISC-V guest”的复合开销，不是 native RISC-V JIT/backend 的真实性能。

## 11. 本地交叉编译 + 远端只跑测试：对本仓库的可行性

这一条是本轮最值得推进的方向。

### 11.1 总体判断

- **可行，而且很适合当前仓库。**
- 最核心的原因：
  - `.bpf.o` 已经是 `clang -target bpf` 产物，不需要为 ARM64 重新“跨 ISA”编译。
  - 真正跟目标架构强绑定的，主要是 `micro_exec`、`scanner`、kernel image。
  - 如果把这些都在本地 x86 机器交叉编好，远端 ARM64 机器只负责“跑已经编好的二进制 + stock/custom kernel”，租机时长就能明显缩短。

### 11.2 逐项回答 a-f

#### a) `micro_exec` 能交叉编译吗？

- **能，但现在不是 turn-key。**
- 从仓库看，`micro_exec` 是标准 C/C++ CMake binary，不含写死的 x86-only 源码路径。
- 但它的依赖比表面上更多：
  - `libelf`
  - `zlib`
  - `libzstd`
  - `yaml-cpp`
  - `libbpf`（静态 vendor lib）
  - `llvmbpf` / LLVM 目标工具链
- 当前 `micro/Makefile` 没有显式透传 `CMAKE_TOOLCHAIN_FILE`、`CC/CXX`、`PKG_CONFIG_LIBDIR`、`AR/RANLIB/STRIP` 等交叉编译参数；`vendor/libbpf` 也是直接按当前环境编的。
- 所以结论是：**技术上可交叉编，工程上需要给 Makefile/CMake 加 cross-toolchain plumbing。**

#### b) `scanner` 能交叉编译吗？

- **能，也比 `micro_exec` 稍简单。**
- `scanner` library 本身只是 C++20 + `yaml-cpp`。
- CLI 额外依赖 `libbpf`。
- 当前 `scanner/CMakeLists.txt` 也是普通 CMake，天然可配 toolchain file；问题同样在于你需要提供目标架构的 `yaml-cpp` / `libbpf` / `pkg-config`。

#### c) BPF programs 不需要交叉编译（`.bpf.o` target-independent）

- **基本同意。**
- 当前仓库 `micro/programs/Makefile` 本来就是 `clang -target bpf`。
- 对 ARM64 / x86 host 来说，`.bpf.o` 仍是 eBPF ISA，不是 host ISA。
- 这一块正是“本地编译，远端只跑”的成本优势来源。

#### d) ARM64 kernel 怎么交叉编译？

- 重要细节：**ARM64 不是 `bzImage` 路径。**
- 当前仓库顶层 `Makefile` 写死的是 x86：
  - `BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage`
- 但 `vendor/linux-framework/arch/arm64/Makefile` 里，默认 `KBUILD_IMAGE` 是：
  - `arch/arm64/boot/Image.gz`
- 所以 ARM64 kernel 交叉编译应走类似：

```bash
make -C vendor/linux-framework ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image.gz -j$(nproc)
```

或 LLVM 工具链方式：

```bash
make -C vendor/linux-framework LLVM=1 ARCH=arm64 Image.gz -j$(nproc)
```

- 结论：要支持 ARM64，顶层 `Makefile` 至少要把 `bzImage` 抽象成按架构切换的 `KERNEL_IMAGE`。

#### e) 远端 ARM64 机器上需要什么依赖？

如果只是“上传编好的产物然后运行”，最小运行时依赖比想象中少。

按当前仓库实测 `ldd`：

- `micro_exec` 运行时依赖：
  - `libelf1`
  - `zlib1g`
  - `libzstd1`
  - `libyaml-cpp0.8`
  - `libstdc++6`
- `scanner` CLI 运行时依赖：
  - 上述全部
  - 再加 `libbpf1`

若远端要执行 `run-kernel`，还需要：

- `sudo` / root
- 开启 BPF/JIT 的内核
- 如果要测你们的 recompile path，则必须是带 `BPF_PROG_JIT_RECOMPILE` patch 的目标 kernel

若远端只执行 `run-llvmbpf`：

- 不需要 custom kernel
- 只要用户态依赖齐全即可

#### f) 远端如果是 bare metal，能直接 native 跑 `micro_exec` 吗？不需要 `vng`？

- **能，且这是更自然的路径。**
- 当前仓库里的 `vng` 只是顶层 `Makefile` 为了“在不替换本机 kernel 的情况下 boot 一个 framework VM”准备的。
- `micro_exec` 本身只提供三类命令：
  - `run-llvmbpf`
  - `run-kernel`
  - `list-programs`
- 所以如果远端 ARM64 机器本来就跑着你想测的 kernel，直接 native 执行 `micro_exec run-kernel` 即可；不需要 `vng`。

### 11.3 仓库内证据与工程含义

从当前仓库看，支持这条路线的几个关键点：

- `micro/programs/Makefile` 已经是 `clang -target bpf`，BPF 对象不依赖 host ISA。
- `micro_exec` 已经把 scanner library 链进来了，所以远端如果用 `micro_exec --recompile-*` 自动扫描，其实**不一定还要单独上传 scanner CLI**。
- 顶层 `Makefile` 现在只照顾 x86 kernel image；ARM64 需要单独补 target。

建议新增的工程项：

1. `make build-arm64-cross`
2. `make kernel-arm64`
3. `make package-arm64`
4. `make benchmark-arm64 PROVIDER=aws|hcloud|oci`

其中 `package-arm64` 输出一个 tarball，包含：

- `micro_exec`
- 可选 `scanner`
- `micro/programs/*.bpf.o`
- 运行脚本
- 可选 `Image.gz`

## 12. 推荐流程设计

### 12.1 最推荐的便宜方案

如果目标是“尽量低成本完成 ARM64 benchmark”，我建议优先级如下：

1. **本地 x86 交叉编译 + Oracle Free Tier ARM / Hetzner CAX 远端 native 跑**
   - 成本最低
   - 适合 smoke / 回归 / 初步数值
2. **本地 x86 交叉编译 + AWS Graviton On-Demand/Spot + 自定义 AMI**
   - 最适合 custom kernel
   - 适合正式 benchmark
3. **GitHub Actions 只做 orchestrator，不做 benchmark host**
   - GitHub workflow 触发外部 ARM64/RISC-V 机器
   - 比直接在 GitHub-hosted ARM64 上长跑更合理

### 12.2 GitHub Actions 的最佳用法

推荐不要把 GitHub-hosted ARM64 当 benchmark 机器，而是把它当“控制平面”：

- GitHub x86/ARM64 runner：
  - 交叉编译
  - 打包 artifact
  - 调用 AWS/Hetzner/OCI API 创建实例
  - 上传 artifact
  - 触发远端 benchmark
  - 拉回结果
  - 删除实例

这样可以同时得到：

- GitHub 的触发/审计/artifact 能力
- 外部 ARM64/RISC-V 机器的真实性能
- 按需租用 + 自动释放的低成本

### 12.3 建议的 `make benchmark-arm64`

建议目标形态：

```make
make benchmark-arm64 PROVIDER=aws
```

执行逻辑：

1. 本地交叉编译 ARM64 `micro_exec`
2. 本地编 `.bpf.o`
3. 可选：本地编 ARM64 `Image.gz`
4. CLI 创建 ARM64 实例
5. 上传 artifacts
6. 远端安装最小运行时依赖
7. 若走 stock kernel：直接 native 跑
8. 若走 custom kernel：切到自定义镜像/实例后再跑
9. 拉回结果到 `micro/results/` 或 `docs/tmp/`
10. 删除实例

### 12.4 最终建议

- **ARM64 cheapest path**：`本地交叉编译 + Oracle Free Tier / Hetzner CAX native 跑`
- **ARM64 most practical formal path**：`本地交叉编译 + AWS Graviton custom AMI + 自动 terminate`
- **GitHub Actions role**：只做 orchestrator；不要把 GitHub-hosted ARM64 当 custom-kernel benchmark 平台
- **RISC-V path**：外部租机/裸机 + GitHub 远程触发；不要指望官方 RISC-V runner

## Sources

- AWS EC2 pricing and per-second billing: https://aws.amazon.com/ec2/pricing/
- AWS Spot best practices / up to 90% / interruption notice: https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/spot-best-practices.html
- AWS Spot interruption notices: https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/spot-instance-termination-notices.html
- AWS CLI `run-instances`: https://docs.aws.amazon.com/cli/latest/reference/ec2/run-instances.html
- AWS CLI `terminate-instances`: https://docs.aws.amazon.com/cli/v1/reference/ec2/terminate-instances.html
- AWS CLI credentials files: https://docs.aws.amazon.com/cli/latest/userguide/cli-configure-files.html
- GitHub OIDC for AWS: https://docs.github.com/en/actions/deployment/security-hardening-your-deployments/configuring-openid-connect-in-amazon-web-services
- AWS custom kernels on EC2: https://docs.aws.amazon.com/linux/al2/ug/UserProvidedKernels.html
- EC2 boot mode / Graviton default UEFI: https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/ami-boot-mode.html
- Oracle Always Free resources: https://docs.oracle.com/iaas/Content/FreeTier/freetier_topic-Always_Free_Resources.htm
- Oracle resource reference (`4 OCPU / 24 GB`, `3000 OCPU-hours / 18000 GB-hours`): https://docs.oracle.com/iaas/Content/FreeTier/resourceref.htm
- Oracle Free Tier FAQ (`no SLA`): https://www.oracle.com/africa/cloud/free/faq/
- OCI CLI overview / auth model: https://docs.oracle.com/iaas/Content/API/Concepts/cliconcepts.htm
- OCI CLI launch walkthrough: https://docs.oracle.com/en-us/iaas/Content/GSG/Tasks/gettingstartedwiththeCLI.htm
- OCI CLI `instance launch`: https://docs.oracle.com/en-us/iaas/tools/oci-cli/3.50.0/oci_cli_docs/cmdref/compute/instance/launch.html
- OCI CLI `instance terminate`: https://docs.oracle.com/en-us/iaas/tools/oci-cli/latest/oci_cli_docs/cmdref/compute/instance/terminate.html
- Hetzner Cloud overview / API & CLI / shared resources for test env: https://www.hetzner.com/cloud
- Hetzner Cloud API reference: https://docs.hetzner.cloud/reference/cloud
- Hetzner official setup action (`HCLOUD_TOKEN`): https://github.com/hetznercloud/setup-hcloud
- Hetzner official CLI repo: https://github.com/hetznercloud/cli
- GitHub-hosted runners overview / new VM per job / nested virtualization unsupported: https://docs.github.com/en/actions/concepts/runners/github-hosted-runners
- GitHub-hosted runner specs (`ubuntu-24.04-arm` etc.): https://docs.github.com/en/actions/using-github-hosted-runners/using-github-hosted-runners/about-github-hosted-runners?supported-runners-and-hardware-resources=
- GitHub custom images for larger runners: https://docs.github.com/en/actions/how-tos/manage-runners/larger-runners/use-custom-images
- GitHub self-hosted runner support matrix and ephemeral runners: https://docs.github.com/de/actions/reference/runners/self-hosted-runners
- GitHub Actions billing: https://docs.github.com/en/billing/managing-billing-for-github-actions/about-billing-for-github-actions
- GitHub Actions runner pricing: https://docs.github.com/billing/reference/actions-runner-pricing
- GitHub changelog: self-hosted pricing change postponed: https://github.blog/changelog/2025-12-16-coming-soon-simpler-pricing-and-a-better-experience-for-github-actions
