# Cilium / Calico 安装与 runner 适配总结（2026-04-25）

## 结论

- 已把 Cilium 和 Calico 的安装入口加进 `runner/containers/runner-runtime.Dockerfile`，采用“从官方多架构镜像提取运行时二进制/依赖”的方式，不再要求框架预编译它们自己的 BPF 对象。
- 已把 `runner/libs/app_runners/cilium.py` 和 `runner/libs/app_runners/calico.py` 从壳代码补成可启动 runner；两者都改为先拉起本地 `etcd`，再启动 app，自身在运行时加载 live BPF programs，由 daemon 继续对 live programs 做 ReJIT。
- Python 语法和 import/构造链已验证通过。
- 本次没有做 KVM VM 实跑，也没有完整构建 runtime image；因此下面对“能否稳定 attach 到 BPF programs”的结论必须区分：
  - Cilium：实现路径和官方文档基本一致，可信度较高，但仍待 VM 实跑确认。
  - Calico：已做最佳努力接入，但官方文档没有明确给出“非 K8s 主机 + eBPF datapath”作为标准支持路径，仍可能需要额外 datastore 资源（如 node/hostendpoint）才能稳定加载 BPF 程序，必须在 VM 里实跑确认。

## 调研结论

### 1. Cilium

- 官方文档明确写到：
  - 原生进程方式运行 `cilium-agent` 时，宿主机需要 `clang+LLVM >= 18.1`。
  - 非 Kubernetes 运行时，还需要 `etcd >= 3.1.0`。
  - 官方镜像支持 `AMD64` 和 `AArch64`。
- 因此，本次采用的落地方式是：
  - 从官方镜像 `quay.io/cilium/cilium:v1.19.3@sha256:2e61680593cddca8b6c055f6d4c849d87a26a1c91c7e3b8b56c7fb76ab7b7b10` 提取 `cilium-agent` 和配套工具。
  - 同时提取镜像内自带的 `clang` / `llc`。
  - 同时提取 `/var/lib/cilium/bpf` 下的 Cilium BPF 源树和头文件，让 agent 在 VM 内按官方方式自行编译/加载 datapath。
- runner 启动策略：
  - 本地起一个临时 `etcd`。
  - `cilium-agent` 用 `--enable-k8s=false`、`--kvstore=etcd`、`--routing-mode=native`、`--devices=<主网卡>`、`--direct-routing-device=<主网卡>` 启动。
  - 关闭 L7 proxy 和健康检查，尽量减少对额外控制面的依赖。

### 2. Calico

- 官方文档明确支持“non-cluster hosts / VMs”：
  - `calico/node` 容器方式可用于“networking + policy”。
  - `calico-felix` 包管理器安装方式只覆盖“policy only”。
  - `etcd` 支持用来保护 non-cluster hosts。
  - `calico/node` 也支持 `CALICO_NETWORKING_BACKEND=none` 的 policy-only 模式，只跑 Felix、不跑 BIRD/confd。
- 但官方 eBPF 文档是 Kubernetes 导向的，重点是替换 `kube-proxy`。我没有找到一份同等明确的官方文档，说明“非 K8s 主机 + eBPF datapath”是标准支持矩阵。
- 因此，本次对 Calico 的实现是“最佳努力”：
  - 从官方镜像 `quay.io/calico/node:v3.31.3@sha256:f2339c4ff3a57228cbc39a1f67ab81abded1997d843e0e0b1e86664c7c4eb6c0` 提取 `calico-node`。
  - 提取 `/etc/calico` 配置和 `included-source/felix-ebpf-gpl.tar.xz`。
  - 额外提取 `libpcap.so.1` 兼容库，因为 Ubuntu 24.04 默认库名是 `libpcap.so.0.8`，和 `calico-node` 期望的 SONAME 不同。
- runner 启动策略：
  - 本地起一个临时 `etcd`。
  - 先执行一次 `calico-node -startup`，让它按容器分发方式做节点初始化。
  - 再执行 `calico-node -felix`。
  - 显式打开 `FELIX_BPFENABLED=true`。
  - 显式关闭 `FELIX_BPFKUBEPROXYIPTABLESCLEANUPENABLED`，并把 `FELIX_BPFCONNECTTIMELOADBALANCING` 设为 `Disabled`，尽量降低对 Kubernetes service/kube-proxy 语义的依赖。
  - 把 `CALICO_NETWORKING_BACKEND=none` 固定成 policy-only 模式，只保留 Felix。
  - 用自动探测到的主网卡生成 `IP_AUTODETECTION_METHOD=interface=<iface>`、`FELIX_BPFDATAIFACEPATTERN`、`FELIX_BPFL3IFACEPATTERN`。
- 风险说明：
  - Calico 在非 K8s 主机上即使 Felix 成功启动，也不一定立刻有 BPF program。因为没有 workload endpoint 时，Felix 可能还需要额外的 datastore 资源（如 node / hostendpoint / pool）才会真正 attach。
  - 这部分本次没有在 VM 里跑通，所以不能宣称“已确认稳定加载 BPF”。只能说 runner 和安装链路已准备好，下一步应在 KVM VM 里实跑。

## 代码改动

### runner

- 新增 `runner/libs/app_runners/etcd_support.py`
  - 统一封装本地临时 `etcd` 生命周期。
  - 提供主网卡自动探测、接口正则辅助函数。
  - 新增 `EtcdBackedNativeRunner`，供 Cilium/Calico 共用。
- 更新 `runner/libs/app_runners/cilium.py`
  - 改为继承 `EtcdBackedNativeRunner`。
  - 自动探测主网卡。
  - 通过 `kvstore=etcd` 走非 K8s 启动路径。
  - 默认加载超时提高到 120 秒，避免首启编译 BPF 过慢。
- 更新 `runner/libs/app_runners/calico.py`
  - 改为继承 `EtcdBackedNativeRunner`。
  - 自动探测主网卡。
  - 启动顺序改为 `-startup` 后接 `-felix`。
  - 补齐 etcd / BPF / 日志 / IP 自动探测环境变量。
  - 修正一次性 `-startup` 调用的环境继承，避免丢失 `PATH`。

### Dockerfile

- 在 `runner/containers/runner-runtime.Dockerfile` 中新增两个 upstream stage：
  - `runner-runtime-cilium-upstream`
  - `runner-runtime-calico-upstream`
- 从 Cilium 镜像提取：
  - `cilium-agent`
  - `cilium-dbg`
  - `cilium-bugtool`
  - `cilium-health`
  - `cilium-health-responder`
  - `cilium-mount`
  - `cilium-sysctlfix`
  - `clang`
  - `llc`
  - `/var/lib/cilium`
- 从 Calico 镜像提取：
  - `calico-node`
  - `/etc/calico`
  - `/included-source`
  - `libpcap.so.1*`
- runtime image 额外安装：
  - `etcd-server`
- repo-artifact 目录新增：
  - `repo-artifacts/<arch>/cilium/bin/cilium-agent`
  - `repo-artifacts/<arch>/cilium/bin/cilium-dbg`
  - `repo-artifacts/<arch>/calico/bin/calico-node`

## 验证

- 已执行：

```bash
python -m py_compile \
  runner/libs/app_runners/cilium.py \
  runner/libs/app_runners/calico.py \
  runner/libs/app_runners/etcd_support.py
```

- 已执行 import / 构造链检查：

```bash
python - <<'PY'
import runner.libs.app_runners.cilium
import runner.libs.app_runners.calico
import runner.libs.app_runners.etcd_support
from runner.libs.app_runners import get_app_runner
print(type(get_app_runner('cilium', workload='network')).__name__)
print(type(get_app_runner('calico', workload='network')).__name__)
PY
```

- 结果：
  - `py_compile` 通过。
  - `get_app_runner('cilium', ...)` 返回 `CiliumRunner`。
  - `get_app_runner('calico', ...)` 返回 `CalicoRunner`。

## 未完成 / 需要后续确认

- 未执行 `docker build -f runner/containers/runner-runtime.Dockerfile ...`，所以 Dockerfile 目前只做了静态路径核对和 Python 侧适配，没有做整镜像构建验收。
- 未在 KVM VM 内实跑：
  - `CiliumRunner.start()` 是否能稳定看到 live programs。
  - `CalicoRunner.start()` 在非 K8s、policy-only、BPF enabled 条件下是否一定会 attach 到 BPF programs。
- 如果下一步做 VM 验证，我建议按下面顺序排：
  1. 先验证 Cilium，因为官方“native + no-K8s + etcd”路径更明确。
  2. 再验证 Calico；若 Felix 起得来但没有 program，应优先检查是否还需要最小 `Node` / `HostEndpoint` / `IPPool` 资源。

## 参考资料

- Cilium System Requirements:
  - https://docs.cilium.io/en/stable/operations/system_requirements/
- Calico non-cluster hosts:
  - https://docs.tigera.io/calico/latest/getting-started/bare-metal/about
- Calico Docker container install for non-cluster hosts:
  - https://docs.tigera.io/calico/latest/getting-started/bare-metal/installation/container
- Calico binary install with package manager (`apt install calico-felix`):
  - https://docs.tigera.io/calico/latest/getting-started/bare-metal/installation/binary-mgr
- Calico Felix configuration reference:
  - https://docs.tigera.io/calico/latest/reference/felix/configuration
- Calico component architecture:
  - https://docs.tigera.io/calico/latest/reference/architecture/overview
- Calico eBPF dataplane overview / enablement:
  - https://docs.tigera.io/calico/latest/about/kubernetes-training/about-ebpf
  - https://docs.tigera.io/calico/latest/operations/ebpf/enabling-ebpf
