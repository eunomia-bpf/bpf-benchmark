# 6 个 BPF app 预编译安装方式调研（2026-04-25）

## 当前 VM 环境

- 内核：`6.15.11-061511-generic`
- OS：`Ubuntu 24.04.3 LTS (noble)`
- `suricata`：未安装（`dpkg -l | grep -i suricata` 无输出）
- `cilium`：未安装（`dpkg -l | grep -i cilium` 无输出）
- `systemd-run`：`/usr/bin/systemd-run`
- `systemd --version`：`systemd 255 (255.4-1ubuntu8.14)`，编译特性中明确包含 `-BPF_FRAMEWORK`

## 结论总表

| app | apt/dnf 包 | GitHub Release | 官方容器镜像 | 其他包管理器 | 安装后是否可直接运行并加载 BPF | 明确结论 |
| --- | --- | --- | --- | --- | --- | --- |
| `calico` | Ubuntu 官方源无；官方文档有旧 PPA `ppa:project-calico/calico-3.31`，包名 `calico-felix`，但仅覆盖 Felix/policy-only，文档明确说“要 networking 请改用 container install” | 有 `calicoctl-*` 二进制和 `release-v<V>.tgz`，但不是完整 datapath 主程序 | 有，推荐 `quay.io/calico/node:v<V>` / `docker.io/calico/node:v<V>` | Helm、Tigera Operator | 标准容器化安装可以，不需要额外编译 BPF 对象；但 `apt`/`calicoctl` 本身不能直接把 eBPF datapath 跑起来 | **不可行**（如果要求“像普通主机 app 一样直接 apt/release-binary 安装并启用 eBPF datapath”）；**容器化标准安装可行** |
| `suricata` | **有**。Ubuntu 24.04 官方源直接有 `suricata`；官方也有 PPA `ppa:oisf/suricata-stable` | GitHub Release 页面有 tag，但**没有预编译二进制资产** | 未找到 OISF 官方稳定镜像分发文档；官方主推 apt/PPA/RPM | 无主程序级 pip/cargo；`suricata-update` 是单独工具 | **可以**。Ubuntu `.deb` 已内置 `/usr/lib/suricata/ebpf/*.bpf`；启用 XDP/eBPF 只需改配置，不需要再编译对象文件 | **可以直接 apt install（推荐）** |
| `systemd` | **有**，包名 `systemd`，本机已装 | 无面向运行时的 release binary 分发 | 不适合作为普通容器 app 分发 | 无 | **不满足你的严格目标**。systemd 资源控制可挂接 pinned BPF 程序，但当前 Ubuntu 24.04 默认包是 `-BPF_FRAMEWORK`，且 `IPIngressFilterPath=`/`IPEgressFilterPath=` 要求你先准备好 `/sys/fs/bpf/...` 程序 | **需要从源码编译**（如果要 systemd 自带 BPF framework / 内置 BPF 程序能力） |
| `loxilb` | Ubuntu/Debian 官方源无，PPA 无；但官方文档提供可下载 `.deb` | **有**。稳定版示例：`https://github.com/loxilb-io/loxilb/releases/download/v0.9.7/loxilb_0.9.7-amd64.deb`；夜版示例：`https://github.com/loxilb-io/loxilb/releases/download/vlatest/loxilb_0.99rc-amd64.deb` | **有**，`ghcr.io/loxilb-io/loxilb:latest` / `:v0.9.8` | 无常用包管理器分发 | **可以**。官方文档说明 agent 默认会把 eBPF 程序加载到系统接口；`.deb` 内也直接包含 `llb_*.o` 对象和 `systemd` service | **可以下载 release binary（推荐）**；做容器基线时也可直接用官方镜像 |
| `cilium` | Ubuntu 官方源无；本机 `apt-cache policy cilium` 无候选包 | `cilium/cilium` release **无 agent 二进制资产**；另有 `cilium-cli` release，但那只是安装/运维 CLI，不是 `cilium-agent` 主程序 | **有**，推荐 `quay.io/cilium/cilium:v<V>` | Helm chart、`cilium-cli` | **部分满足**。官方镜像可以直接部署并由 agent 管理 eBPF；但文档明确写 `clang+LLVM` 在镜像里，Cilium 用 LLVM 生成 eBPF bytecode，说明它不是“agent 自带固定预编译 BPF 对象”的模式 | **不可行**（按你的严格条件“agent binary 自带预编译 BPF 程序”）；**官方容器化安装可行** |
| `opentelemetry-ebpf-profiler` | 无 Ubuntu/Debian 官方包 | **严格按该仓库名**：无 release（GitHub API 返回 `0` 个 release） | 该仓库本身未见官方稳定镜像分发文档 | 无 | 该仓库 README 明确主线是源码构建；它会在运行时加载 eBPF 程序，但预编译安装件不是这个 repo 的官方主路径 | **需要从源码编译**（严格按 `opentelemetry-ebpf-profiler` 仓库） |

## 逐项调研

### 1. calico

#### apt/dnf 包

- Ubuntu 官方源：未发现当前可直接 `apt install calico` 的主程序包。
- 官方文档确实保留了 package-manager 安装页，但内容明确是：
  - PPA：`ppa:project-calico/calico-3.31`
  - 包名：`calico-felix`
  - 作用：只覆盖 Felix，文档写明“**If you want to install Calico with networking ... you should choose the container install method**”。
- 这说明 `calico-felix` 不是完整的 Calico datapath 安装，更不是 eBPF datapath 的标准安装路径。

#### GitHub Release

- `projectcalico/calico` release 有预编译资产，但主要是：
  - `calicoctl-linux-amd64`
  - `calicoctl-linux-arm64`
  - `release-v<VERSION>.tgz`
  - `tigera-operator-v<VERSION>.tgz`
- 可直接写成的 URL 模式：
  - `https://github.com/projectcalico/calico/releases/download/v<VERSION>/calicoctl-linux-amd64`
  - `https://github.com/projectcalico/calico/releases/download/v<VERSION>/release-v<VERSION>.tgz`
- 但这些资产里，真正负责节点 datapath 的仍然是 `calico/node` 容器，不是单个宿主机二进制。

#### 容器镜像

- 官方标准路径是 `calico/node`。
- 文档给出了公开 registry 示例：
  - `docker pull quay.io/calico/node:v3.31.5`
  - 也支持 `docker.io/calico/node:<tag>`
- 非集群主机的“container install”页面明确写：容器安装**同时包含 networking 和 policy**。

#### pip/cargo/其他包管理器

- 官方主流分发是 Helm / Tigera Operator，而不是 pip/cargo。
- eBPF 模式安装依赖 Kubernetes 安装对象；文档中的关键配置是 `linuxDataplane: BPF`。

#### 安装后是否可直接运行并自动加载 BPF 程序

- **如果采用标准容器化安装（`calico/node` + Operator/manifest）**：可以，不需要额外编译 BPF 对象。
- **如果采用 PPA 的 `calico-felix` 或单独 `calicoctl`**：不可以，这不是完整 eBPF datapath 安装。

#### 结论

- **不可行**（如果你的要求是“直接 apt/release-binary 安装成一个主机 app，然后自动启用 eBPF datapath”）。
- **可行的免源码路径**是官方容器化/Kubernetes 标准安装，而不是 apt 或单个 release binary。

#### 关键来源

- https://docs.tigera.io/calico/latest/getting-started/bare-metal/installation/binary-mgr
- https://docs.tigera.io/calico/latest/getting-started/bare-metal/installation/container
- https://docs.tigera.io/calico/latest/operations/ebpf/install
- https://docs.tigera.io/calico/latest/operations/image-options/alternate-registry
- https://api.github.com/repos/projectcalico/calico/releases/latest

### 2. suricata

#### apt/dnf 包

- Ubuntu 24.04 官方源直接提供：
  - 包名：`suricata`
  - 本机 `apt-cache policy suricata` 显示候选版本：`1:7.0.3-1build3`
  - 来源：`http://archive.ubuntu.com/ubuntu noble/universe amd64 Packages`
- 官方文档另有 PPA：
  - `ppa:oisf/suricata-stable`
- 我在本机下载了 `.deb` 而未安装，确认包内直接包含：
  - `/usr/lib/suricata/ebpf/bypass_filter.bpf`
  - `/usr/lib/suricata/ebpf/filter.bpf`
  - `/usr/lib/suricata/ebpf/lb.bpf`
  - `/usr/lib/suricata/ebpf/vlan_filter.bpf`
  - `/usr/lib/suricata/ebpf/xdp_filter.bpf`
  - `/usr/lib/suricata/ebpf/xdp_lb.bpf`
- 同时该包依赖 `libbpf1` 和 `libxdp1`，说明 XDP/eBPF 支持已被打进默认包。

#### GitHub Release

- `OISF/suricata` 的 release tag 存在，但 GitHub API 显示最新 release **没有二进制资产**。
- 因而不适合作为“下载预编译 release binary”的路径。

#### 容器镜像

- 官方文档和 release 路径主要强调 apt/PPA/RPM。
- 我没有找到 OISF 官方稳定镜像作为主分发路径的明确文档，因此这里不作为推荐安装结论。

#### pip/cargo/其他包管理器

- 主程序没有官方 pip/cargo 分发。
- `suricata-update` 是单独规则更新工具，不能替代 Suricata 引擎本体。

#### 安装后是否可直接运行并自动加载 BPF 程序

- **能直接使用打包好的 `.bpf` 对象，不需要额外编译**。
- 但要注意：
  - 不是“装完即默认启用 XDP”
  - 需要在 `suricata.yaml` 中启用 `cluster_ebpf` 或 `xdp-mode` / `xdp-filter-file`
- 也就是说：**BPF 对象已经随包提供，运行时按配置加载；不需要你自己再编译对象文件。**

#### 结论

- **可以直接 apt install（推荐）**

#### 关键来源

- 本机 `apt-cache policy suricata`
- 本机 `apt-cache show suricata`
- 本机对 `suricata_1%3a7.0.3-1build3_amd64.deb` 的 `dpkg-deb -c` 检查
- https://docs.suricata.io/en/latest/install/debian.html
- https://docs.suricata.io/en/latest/capture-hardware/ebpf-xdp.html
- https://api.github.com/repos/OISF/suricata/releases/latest

### 3. systemd

#### apt/dnf 包

- Ubuntu/Debian 官方源当然有：
  - 包名：`systemd`
- 当前 VM 已安装：
  - `systemd 255 (255.4-1ubuntu8.14)`

#### GitHub Release

- systemd 不是通过“下载单个预编译 release binary”来面向终端用户分发。
- 现实可用路径仍然是发行版打包。

#### 容器镜像

- 不适合作为普通 Docker app 的标准分发对象。
- 即使放进容器，也通常需要特权运行并把它当 init/system manager 使用，和你这里要对比的“BPF app”形态不一致。

#### pip/cargo/其他包管理器

- 无。

#### 安装后是否可直接运行并自动加载 BPF 程序

- 这里要分两层：
  1. `systemd` 确实有一些与 BPF/cgroup-bpf 相关的资源控制接口，比如 `IPIngressFilterPath=` / `IPEgressFilterPath=`，但这些接口要求你先准备好**已经 pinned 到 `/sys/fs/bpf/` 的程序**。
  2. upstream 构建系统里存在 `bpf-framework` 编译选项；而当前 VM 的 `systemctl --version` 明确显示 `-BPF_FRAMEWORK`。
- 这意味着：
  - 当前 Ubuntu 默认包**并没有启用 systemd 的 BPF framework 构建能力**
  - 即便安装后能识别某些 BPF 相关配置，你仍需要外部准备 BPF 程序，而不是“systemd 自己带着预编译对象并直接加载”

#### 结论

- **需要从源码编译**（如果你的目标是验证 `systemd` 自带 BPF framework / 内置 BPF 程序能力）。
- 如果只是把它当成“可以挂接已存在 pinned BPF 程序的管理器”，那它是预编译可用的；但这不符合你这里“app 自己带 BPF 程序”的目标。

#### 关键来源

- 本机 `systemctl --version`
- https://github.com/systemd/systemd/blob/main/meson_options.txt
- https://www.freedesktop.org/software/systemd/man/248/systemd.resource-control.html
- https://www.freedesktop.org/software/systemd/man/devel/systemd.resource-control.html

### 4. loxilb

#### apt/dnf 包

- Ubuntu/Debian 官方源里没有 `loxilb`。
- 官方文档也没有 PPA/apt repo；推荐的是：
  - 直接下载 `.deb`
  - 或直接使用官方容器镜像

#### GitHub Release

- 这是它最明确的“非源码安装”路径之一。
- 官方文档给出的稳定版 `.deb` 示例：
  - `https://github.com/loxilb-io/loxilb/releases/download/v0.9.7/loxilb_0.9.7-amd64.deb`
- 官方文档给出的 nightly 示例：
  - `https://github.com/loxilb-io/loxilb/releases/download/vlatest/loxilb_0.99rc-amd64.deb`
- 我实际核对了 `v0.9.7` 这个 `.deb`，包里直接包含：
  - `/usr/local/sbin/loxilb`
  - `/etc/systemd/system/loxilb.service`
  - `/opt/loxilb/llb_ebpf_main.o`
  - `/opt/loxilb/llb_ebpf_emain.o`
  - `/opt/loxilb/llb_xdp_main.o`
  - 以及多个 `sock*` / monitor 对象

#### 容器镜像

- 官方文档给出的镜像非常明确：
  - `ghcr.io/loxilb-io/loxilb:latest`
  - `ghcr.io/loxilb-io/loxilb:v0.9.8`
- 文档中直接给了 `docker pull` 和 `docker run --privileged ...` 示例。

#### pip/cargo/其他包管理器

- 未见官方 pip/cargo 分发。

#### 安装后是否可直接运行并自动加载 BPF 程序

- **可以。**
- 官方文档明确写：
  - `loxilb` 的 Go agent 默认会把 eBPF 程序加载到系统里所有真实接口
  - 这样用户不需要手工 `tc filter add ... obj ...`
- 再加上 `.deb` 已内置 `llb_*.o` 对象，因此这是一个很标准的“预编译包自带 BPF 对象并由主程序自动加载”的案例。

#### 结论

- **可以下载 release binary（推荐）**
- 如果你准备做容器镜像基线，直接 `FROM ghcr.io/loxilb-io/loxilb:<tag>` 也非常合适。

#### 关键来源

- https://docs.loxilb.io/main/standalone/
- https://docs.loxilb.io/main/loxilbebpf/
- https://api.github.com/repos/loxilb-io/loxilb/releases/tags/v0.9.7
- 本机对 `loxilb_0.9.7-amd64.deb` 的 `dpkg-deb -c` 检查

### 5. cilium

#### apt/dnf 包

- 当前 Ubuntu 24.04 环境下，`apt-cache policy cilium` 没有候选包。
- 没有发现官方 Debian/Ubuntu apt repo 用来直接分发 `cilium-agent`。

#### GitHub Release

- `cilium/cilium` 主仓库 release 存在，但 GitHub API 显示最新 release **没有二进制资产**。
- 另一个仓库 `cilium/cilium-cli` 提供预编译 CLI：
  - `https://github.com/cilium/cilium-cli/releases/download/v<VERSION>/cilium-linux-amd64.tar.gz`
- 但这个 `cilium` 只是安装/运维 CLI，不是 `cilium-agent` 主程序。

#### 容器镜像

- 官方标准安装路径非常明确：
  - `quay.io/cilium/cilium:v<VERSION>`
- Helm chart 也有 OCI 分发：
  - `oci://quay.io/cilium/charts/cilium`

#### pip/cargo/其他包管理器

- 官方主流分发是 Helm chart + `cilium-cli`。
- 不是 pip/cargo 型分发。

#### 安装后是否可直接运行并自动加载 BPF 程序

- **如果采用官方容器镜像/Helm 安装**：可以运行，agent 会管理和加载 eBPF。
- 但你特别点名要确认的一点是：**`cilium-agent` 是否自带预编译 BPF 程序？**
- 官方文档给出的答案实际上偏向 **否**：
  - 如果原生跑 `cilium-agent`，需要 `clang+LLVM >= 18.1`
  - 如果跑容器镜像，`clang+LLVM` 已经包含在镜像里
  - 文档还明确写：Cilium 使用 LLVM 生成 eBPF bytecode programs
- 这说明它的模型是“agent/镜像内带编译工具链，由 agent 生成/管理 eBPF”，而不是“下载一个 agent binary，里面已经带好固定不变的预编译 `.o` 文件然后直接加载”。

#### 结论

- **不可行**（按你的严格条件“agent binary 自带预编译 BPF 程序，不再依赖运行期生成/编译”）。
- 如果你放宽条件到“官方容器镜像可直接部署、不需要用户自己从源码构建”，那 Cilium 是可行的，但它不满足你特意要求核对的这一点。

#### 关键来源

- 本机 `apt-cache policy cilium`
- https://docs.cilium.io/en/stable/operations/system_requirements/
- https://docs.cilium.io/en/stable/installation/kind/
- https://docs.cilium.io/en/latest/configuration/verify-image-signatures/
- https://api.github.com/repos/cilium/cilium/releases/latest
- https://api.github.com/repos/cilium/cilium-cli/releases/latest

### 6. opentelemetry-ebpf-profiler

#### apt/dnf 包

- 未发现 Ubuntu/Debian 官方包，也未发现 PPA。

#### GitHub Release

- **严格按 `open-telemetry/opentelemetry-ebpf-profiler` 这个仓库**：
  - GitHub API 返回 release 数量为 `0`
  - `/releases/latest` 返回 `404`
- 因此，这个 repo 本身没有可直接下载的官方 release binary。

#### 容器镜像

- 这个 repo 的 README 明确写的主线是源码构建。
- 它自己没有像 `OBI` 或 `otelcol-ebpf-profiler` 那样给出官方稳定镜像分发说明。

#### pip/cargo/其他包管理器

- 无官方 pip/cargo 分发。

#### 安装后是否可直接运行并自动加载 BPF 程序

- README 明确写：
  - agent 运行时会加载 eBPF program 和 maps
  - 但构建步骤是 `make agent` / `make otelcol-ebpf-profiler`
- 也就是说：**功能上会加载 BPF，分发上仍以源码构建为主。**

#### 一个重要的替代路径

- 如果你允许用**官方支持的分发形态**而不是死守这个 repo 名字，那么有两个免源码路线：
  1. `otelcol-ebpf-profiler`
     - 预编译 tarball：
       - `https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v<VERSION>/otelcol-ebpf-profiler_<VERSION>_linux_amd64.tar.gz`
     - 官方镜像：
       - `otel/opentelemetry-collector-ebpf-profiler:<VERSION>`
       - `ghcr.io/open-telemetry/opentelemetry-collector-releases/opentelemetry-collector-ebpf-profiler:<VERSION>`
  2. 更新一代项目 OBI（`opentelemetry-ebpf-instrumentation`）
     - 预编译 tarball：
       - `https://github.com/open-telemetry/opentelemetry-ebpf-instrumentation/releases/download/v<VERSION>/obi-v<VERSION>-linux-amd64.tar.gz`
     - 官方镜像：
       - `otel/ebpf-instrument:v<VERSION>`
       - `ghcr.io/open-telemetry/opentelemetry-ebpf-instrumentation/ebpf-instrument:v<VERSION>`

#### 结论

- **需要从源码编译**（严格按 `opentelemetry-ebpf-profiler` 仓库）。
- 如果你接受官方当前支持的分发形态，建议改用 **`otelcol-ebpf-profiler`** 或 **OBI**，这两条都能免源码。

#### 关键来源

- https://github.com/open-telemetry/opentelemetry-ebpf-profiler/blob/main/README.md
- https://api.github.com/repos/open-telemetry/opentelemetry-ebpf-profiler/releases
- https://github.com/open-telemetry/opentelemetry-collector-releases/blob/main/distributions/otelcol-ebpf-profiler/README.md
- https://github.com/open-telemetry/opentelemetry-collector-releases/blob/main/distributions/otelcol-ebpf-profiler/.goreleaser.yaml
- https://github.com/open-telemetry/opentelemetry-ebpf-instrumentation/blob/main/README.md
- https://api.github.com/repos/open-telemetry/opentelemetry-ebpf-instrumentation/releases/latest

## 最终建议

### 真正适合“免源码、可写进 Dockerfile”的对象

优先级按“离你的目标最近”排序：

1. `suricata`
   - 最干净
   - Ubuntu 官方包直接可装
   - `.deb` 已带 eBPF/XDP 对象
   - 只需改配置，不需要再编译对象文件
2. `loxilb`
   - 官方 `.deb` 直接带 eBPF 对象
   - 官方镜像也成熟
   - 主程序默认自动加载 BPF
3. `otelcol-ebpf-profiler`（如果你接受它替代原始 `opentelemetry-ebpf-profiler` repo）
   - 有官方 tarball 和官方容器镜像
   - 不需要你自己从源码 build

### 不建议纳入“Dockerfile 直装 app”基线的对象

1. `systemd`
   - 当前 Ubuntu 默认包是 `-BPF_FRAMEWORK`
   - 更像宿主机 init/system manager，不像独立 BPF app
2. `calico`
   - 正确路径是 `calico/node` + Kubernetes/Operator
   - 不适合被简化成“Dockerfile 里装个二进制”
3. `cilium`
   - 正确路径是 `quay.io/cilium/cilium` + Helm/Kubernetes
   - 且不满足你要求的“agent binary 自带预编译 BPF 程序”

## 可直接写进 Dockerfile 的安装方案

### 方案 A：`suricata`（推荐）

```dockerfile
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
 && apt-get install -y --no-install-recommends suricata \
 && rm -rf /var/lib/apt/lists/*

# Ubuntu 包内已经自带这些对象文件：
# /usr/lib/suricata/ebpf/bypass_filter.bpf
# /usr/lib/suricata/ebpf/filter.bpf
# /usr/lib/suricata/ebpf/lb.bpf
# /usr/lib/suricata/ebpf/vlan_filter.bpf
# /usr/lib/suricata/ebpf/xdp_filter.bpf
# /usr/lib/suricata/ebpf/xdp_lb.bpf
```

### 方案 B：`loxilb`（推荐）

如果你要“最少折腾”，直接用官方镜像：

```dockerfile
FROM ghcr.io/loxilb-io/loxilb:v0.9.8
```

如果你要保留 Ubuntu 基底并显式安装 release `.deb`：

```dockerfile
FROM ubuntu:24.04

RUN apt-get update \
 && apt-get install -y --no-install-recommends ca-certificates curl \
 && rm -rf /var/lib/apt/lists/*

RUN curl -fsSLo /tmp/loxilb.deb \
    https://github.com/loxilb-io/loxilb/releases/download/v0.9.7/loxilb_0.9.7-amd64.deb \
 && apt-get update \
 && apt-get install -y /tmp/loxilb.deb \
 && rm -f /tmp/loxilb.deb \
 && rm -rf /var/lib/apt/lists/*
```

### 方案 C：`otelcol-ebpf-profiler`（如果允许替代原 repo）

```dockerfile
FROM ubuntu:24.04

RUN apt-get update \
 && apt-get install -y --no-install-recommends ca-certificates curl tar \
 && rm -rf /var/lib/apt/lists/*

RUN curl -fsSLo /tmp/otelcol-ebpf-profiler.tar.gz \
    https://github.com/open-telemetry/opentelemetry-collector-releases/releases/download/v0.150.1/otelcol-ebpf-profiler_0.150.1_linux_amd64.tar.gz \
 && tar -C /usr/local/bin -xzf /tmp/otelcol-ebpf-profiler.tar.gz \
 && rm -f /tmp/otelcol-ebpf-profiler.tar.gz
```

### 方案 D：`calico` / `cilium`

- 这两个不要写成“在 Ubuntu 容器里 `apt install` 一个二进制”的模式。
- 正确做法是：
  - `calico`：拉 `calico/node`，通过 Operator/manifest 安装
  - `cilium`：拉 `quay.io/cilium/cilium`，通过 Helm / `cilium-cli` 安装
- 如果 benchmark 平台必须统一为 Dockerfile 单镜像，这两项建议从本轮“免源码主机 app 对比”中排除。

## 一句话结论

- **最符合你的目标**：`suricata`、`loxilb`
- **可免源码但应按容器化/Kubernetes 方式看待**：`calico`、`cilium`
- **默认系统包不满足目标**：`systemd`
- **严格按 repo 名称仍需源码编译**：`opentelemetry-ebpf-profiler`
