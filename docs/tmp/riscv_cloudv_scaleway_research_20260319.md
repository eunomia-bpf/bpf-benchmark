# RISC-V 方案补充调研：Cloud-V 与 Scaleway RV1（2026-03-19）

> 目的：在已有 ARM64 / RISC-V 租机调研基础上，把 `Cloud-V` 和 `Scaleway RV1` 两条 RISC-V 路线单独拉出来，回答“能不能拿来给 `bpf-benchmark` 跑 native RISC-V、怎么接入、能不能做 custom kernel、是否适合正式 benchmark”。

## 1. 结论先说

- `Cloud-V` 更像 `RISC-V 研发平台 / board farm / CI runner + SSH + LAVA`，不是传统按小时租的通用云主机。
- `Scaleway RV1` 更接近“可租 dedicated RISC-V 服务器”，更适合直接套 `create -> ssh -> upload -> run -> fetch` 这类 benchmark 流程。
- 如果目标是：
  - `尽快拿到 native RISC-V userspace 结果`：优先看 `Scaleway RV1`
  - `先把 RISC-V CI / smoke 跑起来`：优先看 `Cloud-V GitHub runner`
  - `测试 custom kernel / OpenSBI / U-Boot 能否在真实板子上启动`：优先看 `Cloud-V LAVA`
- 两者都不是像 AWS Graviton 那样“标准化、低摩擦、强 SLA”的 custom-kernel benchmark 平台。

## 2. Cloud-V

### 2.1 它是什么

- Cloud-V 官方自称是 `RISC-V based cloud computing platform`。
- 它提供的不是单一“云虚机”，而是混合资源池：
  - 实体板卡 / 桌面机
  - QEMU RISC-V 仿真环境
  - GitHub / GitLab runner
  - Jenkins / dashboard
  - KernelCI / LAVA
- 官方公开列出的设备包括：
  - `VisionFive 2`
  - `Banana Pi F3`
  - `Milk-V Jupiter`
  - `Milk-V Pioneer Box`
  - QEMU-based virtual environment

### 2.2 怎么接入

- `Get Access` 页面：先提交访问申请。
- `SSH`：文档写明管理员会提供 SSH 命令和凭证。
- `GitHub Actions runner`：可通过 Cloud-V GitHub App 或表单把 RISC-V runner 绑定到仓库。
- `LAVA / KernelCI`：适合提交 kernel / firmware 测试任务。

### 2.3 关键限制

- `SSH` 路线当前文档写的是 `unprivileged SSH access`，`sudo` 不可用。
- `GitHub runner` 不是 GitHub 官方支持的 RISC-V runner，而是 Cloud-V 用社区 port 提供的集成。
- GitHub runner 是容器 / runner 服务模式，不是给你 root 控制整块板卡。
- Cloud-V 文档里还写了一个重要限制：
  - 每个 `repo + board type` 只有 `1` 个 runner
  - 任务天然串行
- 这意味着：
  - 适合 `CI / build / smoke / native userspace run`
  - 不适合直接当“正式 benchmark 云机”

### 2.4 文档口径冲突

- Cloud-V 的 SSH 文档写的是“可以申请 SSH access”。
- 但它的 `RISC-V Labs SLA` 页面仍写：
  - `Sandboxing/SSH Access Service: TBD. It's not available for now.`
- 这说明官方材料之间有冲突。接入前应默认：
  - `GitHub runner` 和 `LAVA` 更可信
  - `SSH` 是否当前开放，必须发邮件或走表单确认

### 2.5 价格

- 没找到公开透明的 hourly / monthly 价目表。
- 当前能确认的是：
  - GitHub runner 文档写的是 `free GitHub actions runner`
  - SLA 页提到存在免费配额
  - 同时又提到 `Standard User (paid)` / `Premium Users (paid)`，但没有公开具体价格
- 结论只能写成：
  - `有免费入口`
  - `公开价格不透明`
  - `正式使用前需要联系 Cloud-V 确认当前资费和资源配额`

### 2.6 对本仓库的适配判断

- `smoke / CI`：适合
- `native userspace run`：适合，但要注意不同板卡 ISA 扩展可能不同，结果不可直接横向混用
- `custom kernel`：
  - `SSH` 路线基本不合适，因为没有 `sudo`
  - `GitHub runner` 也不合适，因为它不是宿主机控制模型
  - `LAVA` 反而是最接近“能测 kernel”的路线，但它是 job-based test lab，不是自由 SSH 主机
- `formal benchmark`：不建议

### 2.7 一句话定位

- `Cloud-V` 最适合 `RISC-V CI / smoke / board-lab`
- 不适合直接拿来当 `权威性能 benchmark 云机`

## 3. Scaleway RV1

### 3.1 它是什么

- `Elastic Metal RV1` 是 Scaleway 的 `dedicated physical server`。
- 它不是共享 runner，也不是社区板卡 farm，而是更像按需租的 dedicated bare-metal 风格服务器。

### 3.2 可用区与入口

- 可从控制台下单，也可通过 API / CLI 管理。
- 但官方页面对可用区有冲突：
  - `Product availability by region` 页面显示 `RV1 (RISC-V)` 当前在 `AMS1`
  - `Scaleway Labs EM-RV1` FAQ 仍写 “These servers are only available in the `fr-par-2` zone.”
- 当前时点更应优先信产品总览页的可用区矩阵，但文档里必须保留这个冲突，说明它仍是 `Labs` 产品，运营口径没有完全收敛。

### 3.3 怎么接入

- 官方支持控制台 / API / CLI 创建服务器。
- 典型流程是：
  - 创建 RV1 机器
  - 安装 OS
  - 配 SSH key
  - 直接 SSH 登录
- 还提供：
  - `rescue mode`
  - `serial/BMC access`
  - `remote access`

### 3.4 价格与规格

- 当前官方页面能确认到的公开规格与价格：
  - `EM-RV1-C4M16S128-A`
  - `4x C910 RISC-V 64GC 1.85GHz`
  - `16 GB RAM`
  - `128 GB`
  - `100 Mb/s`
  - `€0.042/hour`
  - `€15.99/month`
- 这和之前文档里 `€0.04/h` 的 provisional 估算大体一致，现在已经可以用官方页面确认。

### 3.5 Custom kernel 这件事

- Scaleway 官方明确支持 RV1 自定义内核，但它不是常规 UEFI / BIOS / GRUB 机器。
- 官方文档明确写到：
  - `EM-RV1 does not support standard UEFI or BIOS boot`
  - 不能直接依赖主流发行版默认 kernel 的安装方式
  - 需要 `boot.itb`、设备树、OpenSBI 和 RV1 特定 boot 流程
  - 也提供 `rv1 update-kernel`，并可选 `--tree mainline`
- 这意味着：
  - `能做 custom kernel`
  - 但操作复杂度明显高于 AWS / 常规 x86 / 常规 ARM64 云机
- 如果短期目标只是先拿到 `native RISC-V benchmark`，建议先跑 stock / provider-supported kernel，不要一开始就把主线压在 custom-kernel boot 上。

### 3.6 其它限制

- 这是 `Labs` 服务，官方写明 `SLA 0%`
- 网络规格是 `100 Mbit/s`
- 启用 vector 时，官方文档还提示了 `GhostWrite` 风险和 RVV 0.7.1 相关限制

### 3.7 对本仓库的适配判断

- `smoke / CI`：适合
- `native userspace run`：适合，而且比 Cloud-V 更像“真正租了一台 RISC-V benchmark 机”
- `custom kernel`：技术上可行，但门槛高，不建议作为第一步
- `formal benchmark`：
  - 比 Cloud-V 更适合
  - 但因为它仍是 `Labs`、`0% SLA`，更准确的定位是：
    - `很好的 native RISC-V benchmark 平台`
    - 不是“企业级强 SLA 的最终归档平台”

### 3.8 一句话定位

- `Scaleway RV1` 是当前最接近“可租 native RISC-V benchmark 机”的路线
- 但仍要接受 `Labs / 0% SLA / custom-kernel boot 特殊`

## 4. 直接对比

| 维度 | Cloud-V | Scaleway RV1 |
| --- | --- | --- |
| 机器形态 | board farm + QEMU + runner + LAVA | dedicated physical server |
| 接入方式 | GitHub runner / SSH / LAVA / GitLab / Jenkins | 控制台 / API / CLI + SSH |
| 权限模型 | runner/SSH/LAVA 分裂；SSH 无 sudo | 主机控制权明显更强 |
| 价格透明度 | 弱 | 强 |
| 自定义 kernel | SSH 路线弱，LAVA 路线可做板级测试 | 可做，但 boot 流程特殊 |
| 适合 smoke | 高 | 高 |
| 适合 native userspace benchmark | 中 | 高 |
| 适合 formal benchmark | 低到中 | 中到高 |

## 5. 对 `bpf-benchmark` 的实际建议

### 5.1 最现实的优先级

1. `先用 Scaleway RV1` 拿第一批 native RISC-V userspace benchmark
2. `再评估 Cloud-V GitHub runner` 用于 CI / smoke / 持续集成
3. 如果后面真要碰 `RISC-V custom kernel bring-up`，单独开 `Cloud-V LAVA` 路线，不要和 userspace benchmark 混成一条线

### 5.2 为什么这样排

- 这和仓库已有文档的总判断一致：
  - `QEMU on x86` 只适合功能验证，不适合性能 benchmark
  - `外部租机/裸机 + GitHub orchestration` 才是 RISC-V 主路线
- 对本仓库而言，最合理的工程组织依然是：
  - 本地 x86 交叉编译
  - 远端 RISC-V 只做 native run
  - 结果回收后立即释放资源

## 6. Sources

- Cloud-V homepage: https://cloud-v.co/
- Cloud-V services: https://cloud-v.co/our-services
- Cloud-V access page: https://cloud-v.co/risc-v-access
- Cloud-V compute instances: https://10x-engineers.github.io/riscv-ci-partners/compute_instances/
- Cloud-V SSH / sandboxing: https://10x-engineers.github.io/riscv-ci-partners/sandboxing/
- Cloud-V GitHub runner: https://10x-engineers.github.io/riscv-ci-partners/setting_up_github_runner/
- Cloud-V LAVA / KernelCI: https://10x-engineers.github.io/riscv-ci-partners/getting_started_lava/
- Cloud-V RISC-V Labs SLA: https://cloud-v.co/risc-v-labs-sla
- Scaleway RV1 product page: https://www.scaleway.com/en/elastic-metal-rv1/
- Scaleway product availability by region: https://www.scaleway.com/en/product-availability-by-region/
- Scaleway Labs EM-RV1: https://labs.scaleway.com/en/em-rv1/
- Scaleway Elastic Metal API: https://www.scaleway.com/en/developers/api/elastic-metal/
- Scaleway Elastic Metal installation workflow: https://www.scaleway.com/en/docs/elastic-metal/how-to/install-server/
- Scaleway CLI baremetal docs: https://cli.scaleway.com/baremetal/
- Scaleway RV1 guidelines: https://www.scaleway.com/en/docs/elastic-metal/reference-content/elastic-metal-rv1-guidelines/
