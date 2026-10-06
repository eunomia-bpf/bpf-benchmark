# Calico Bare-Metal Alignment Report

**Date**: 2026-05-04  
**Scope**: 调研 calico.py 当前实现 vs 官方 bare-metal 文档的对齐情况  
**Code under review**: `runner/libs/app_runners/calico.py`  
**Docs base**: https://docs.tigera.io/calico/latest/getting-started/bare-metal/  
**Source base**: `runner/repos/calico/` (local upstream checkout)  
**Status**: 调研报告，不实施任何代码改动

---

## 步骤 1: 当前实现摘要

### 1.1 启动流程（`start()` 方法）

```
LocalEtcdSession.start()       # 启动本地 etcd
_run_startup()                 # calico-node -startup
_set_node_bgp_ipv4()           # 手动 apply Node YAML（hack）
_apply_allow_policy()          # apply GlobalNetworkPolicy
_register_host_endpoint()      # apply HostEndpoint
NativeProcessRunner.start()    # 启动 calico-node -felix
```

### 1.2 所有非默认 FELIX_* 环境变量（`_command_env()`）

| 变量 | 值 | 说明 |
|---|---|---|
| `FELIX_DATASTORETYPE` | `etcdv3` | 使用 etcd 而非 Kubernetes datastore |
| `FELIX_ETCDADDR` | `127.0.0.1:<port>` | 本地 etcd 地址 |
| `FELIX_ETCDENDPOINTS` | `http://127.0.0.1:<port>` | etcd 端点 URL |
| `FELIX_ETCDSCHEME` | `http` | 非 TLS |
| `FELIX_FELIXHOSTNAME` | `<hostname>` | Felix 节点名 |
| `FELIX_HEALTHENABLED` | `true` | 启用健康检查 |
| `FELIX_IPV6SUPPORT` | `false` | 关闭 IPv6 |
| `FELIX_IPFORWARDING` | `Enabled` | 启用 IP 转发 |
| `FELIX_BPFENABLED` | `true` | **核心：启用 BPF dataplane** |
| `FELIX_BPFKUBEPROXYIPTABLESCLEANUPENABLED` | `false` | 关闭 kube-proxy 清理（非 K8s） |
| `FELIX_BPFCONNECTTIMELOADBALANCING` | `Disabled` | 关闭 CTLB（非 K8s，无 ClusterIP） |
| `FELIX_IPTABLESBACKEND` | `NFT` | 用 nftables backend |
| `FELIX_NFTABLESMODE` | `Enabled` | 启用 nftables mode |
| `FELIX_DEFAULTENDPOINTTOHOSTACTION` | `ACCEPT` | 默认 endpoint→host 允许 |
| `FELIX_BPFDATAIFACEPATTERN` | `^<iface_name>$` | 锁定只监控 benchmark 接口 |
| `FELIX_BPFL3IFACEPATTERN` | `^<iface_name>$` | 同上（L3 路径） |
| `FELIX_LOGFILEPATH` | `none` | 不写日志文件 |
| `FELIX_LOGSEVERITYSCREEN` | `Info` | 控制台 Info 级别 |
| `FELIX_LOGSEVERITYSYS` | `none` | 不写 syslog |
| `FELIX_GenericXDPEnabled` | `true`（仅 benchmark veth） | veth 不支持 native XDP，需要 generic |

### 1.3 `CALICO_NETWORKING_BACKEND=none`（`_startup_env()`）

```python
"CALICO_NETWORKING_BACKEND": "none",
"CALICO_IP": "autodetect",
"IP": "autodetect",
"IP_AUTODETECTION_METHOD": f"interface={self.device}",
"NO_DEFAULT_POOLS": "true",
```

### 1.4 `_run_startup()`

调用 `calico-node -startup` 并传入 `_startup_env()`。作用：初始化 etcd 中的 Node 资源。

### 1.5 `_set_node_bgp_ipv4()` — 手动 apply 的 Node YAML

```yaml
apiVersion: projectcalico.org/v3
kind: Node
metadata:
  name: <node_name>
spec:
  bgp:
    ipv4Address: <interface_ip/cidr>
```

注释说明这是一个 hack：`CALICO_NETWORKING_BACKEND=none` 时，`-startup` 跳过写入 BGP IPv4 地址，而 Felix 的 `bpf_ep_mgr.go` 需要 `hostIP` 才能 attach TC datapath。

### 1.6 `_apply_allow_policy()` — GlobalNetworkPolicy YAML

```yaml
apiVersion: projectcalico.org/v3
kind: GlobalNetworkPolicy
metadata:
  name: bpfbench-allow-all
spec:
  selector: all()
  order: 0
  ingress:
    - action: Allow
  egress:
    - action: Allow
  types:
    - Ingress
    - Egress
```

### 1.7 `_register_host_endpoint()` — HostEndpoint YAML

```yaml
apiVersion: projectcalico.org/v3
kind: HostEndpoint
metadata:
  name: bpfbench-hep
  labels:
    benchmark: "true"
spec:
  interfaceName: bpfbench0
  node: <node_name>
  expectedIPs:
  - 198.18.0.1      # 仅当使用 benchmark veth 时
```

---

## 步骤 2: Calico Bare-Metal 文档调研

### 信息来源

1. 官方文档（通过 WebFetch 获取）：
   - https://docs.tigera.io/calico/latest/getting-started/bare-metal/about
   - https://docs.tigera.io/calico/latest/getting-started/bare-metal/installation/binary-mgr
   - https://docs.tigera.io/calico/latest/getting-started/bare-metal/installation/binary
   - https://docs.tigera.io/calico/latest/operations/ebpf/install
   - https://docs.tigera.io/calico/latest/operations/ebpf/enabling-ebpf
   - https://docs.tigera.io/calico/latest/reference/resources/hostendpoint
   - https://docs.tigera.io/calico/latest/reference/resources/globalnetworkpolicy
   - https://docs.tigera.io/calico/latest/reference/resources/node
   - https://docs.tigera.io/calico/latest/network-policy/hosts/protect-hosts
   - https://docs.tigera.io/calico/latest/network-policy/hosts/protect-hosts-tutorial

2. 源码（本地 `runner/repos/calico/`）：
   - `node/pkg/lifecycle/startup/startup.go`
   - `felix/calc/dataplane_passthru.go`
   - `felix/config/config_params.go`
   - `libcalico-go/lib/backend/syncersv1/updateprocessors/felixnodeprocessor.go`

---

### Q1: bare-metal mode 是否支持 `BACKEND=none`？

**官方文档原文**（`binary-mgr` 安装页）：

> `CALICO_NETWORKING_BACKEND` 三个选项：
> - `bird`: "Calico will provide BGP networking using the BIRD BGP daemon; VXLAN networking can also be used"
> - `vxlan`: "only VXLAN networking is provided; BIRD and BGP are disabled"
> - `none`: "Set to `none` if you want to run Calico for policy only"

> "For a deployment that does not include the Calico/BGP integration, the specification of a node resource just requires the name of the node."

**结论**：`BACKEND=none` 是官方文档明确支持的 bare-metal 选项，专为 "policy only" 场景设计。没有 BGP daemon（BIRD），没有路由广播，只做 policy enforcement。这与我们的使用完全一致（我们只要 TC/XDP policy 程序运行，不需要 BGP 路由）。

**`none` vs `bird` 的本质差别**：
- `bird`：需要运行 BIRD daemon，在 Node 资源写入 `spec.bgp.ipv4Address`，Felix 从这里获取 hostIP
- `none`：跳过 BGP 配置（startup.go:369 `if os.Getenv("CALICO_NETWORKING_BACKEND") == "none" { return false }`），Node 资源只有 `metadata.name`，不写 `spec.bgp`

**bare-metal 用 `none` 是否合理**：完全合理，是 docs 推荐的 policy-only 部署方式。

---

### Q2: bare-metal mode 下 Node resource 怎么创建？

**官方文档（binary-mgr 页）**：

```yaml
calicoctl create -f - <<EOF
- apiVersion: projectcalico.org/v3
  kind: Node
  metadata:
    name: <node name or hostname>
EOF
```

"The database is initialized after creating the first node resource and specification of a node resource just requires the name of the node."

文档推荐：先 `calico-node -startup`（自动创建 Node），如果没有，手动用 `calicoctl create` 只填 `metadata.name`。

**我们的做法**：`_run_startup()` 先调 `-startup`，然后 `_set_node_bgp_ipv4()` 把 `spec.bgp.ipv4Address` patch 进去。

**为什么需要这个 hack**：这在代码注释中有详细解释，此处从源码角度验证：

1. `startup.go:369`：当 `CALICO_NETWORKING_BACKEND=none` 时，`configureAndCheckIPAddressSubnets()` 直接 `return false`，不写 `spec.bgp.ipv4Address`。
2. `felixnodeprocessor.go:73-80`：Felix node processor 把 `node.Spec.BGP.IPv4Address` 解析为 `model.HostIPKey{Hostname: name}` 下发给 Felix。
3. `felixnodeprocessor.go:97-108`：有 fallback：如果 `spec.bgp` 为 nil，会尝试从 `node.Spec.Addresses`（`InternalIP`/`ExternalIP`）里找。
4. `bpf_ep_mgr.go:2714-2716`：`if d.hostIP == nil { return nil, fmt.Errorf("unknown host IP") }` — 没有 hostIP 就无法 attach TC 程序。

**文档是否推荐手动 apply bgp.ipv4Address**：文档不推荐（policy-only 模式不需要 BGP），但也没有明确禁止。这是我们的必要 hack，因为 Felix BPF datapath 需要 hostIP，而 BACKEND=none 不写 bgp.ipv4Address。

**更轻量的替代方案**（docs 不明确，我推断 X）：可以在 `spec.addresses` 里填 InternalIP，这样 `felixnodeprocessor.go:97-108` 的 fallback 会找到它，不需要 `spec.bgp`。但这超出文档范围，需要验证。

---

### Q3: HostEndpoint 在 bare-metal 模式下完整 schema

**官方文档（reference/resources/hostendpoint）**：

```yaml
apiVersion: projectcalico.org/v3
kind: HostEndpoint
metadata:
  name: some.name
  labels:
    type: production
spec:
  interfaceName: eth0    # optional: "*" 或 具体接口名
  node: myhost           # required: 节点名
  expectedIPs:
    - 192.168.0.1        # optional: 接口关联的 IPv4/IPv6 地址
    - 192.168.0.2
  profiles:
    - profile1           # optional: 引用的 Profile 资源
    - profile2
  ports:                 # optional: 命名端口
    - name: some-port
      port: 1234
      protocol: TCP
```

**字段说明**：
- `interfaceName`：optional，`*` 表示所有接口，具体名表示单一接口
- `node`：required
- `expectedIPs`：optional，用于检验接口 IP；如果未填，Felix 仍会处理此 HEP
- `profiles`：optional，文档说 profile 的 policy rule 字段已 deprecated，只保留 `labelsToApply`
- `ports`：optional，命名端口
- `untracked`/`preDNAT`：这两个字段**不在 HostEndpoint 资源上**，在 GlobalNetworkPolicy 资源的 spec 里

**我们的 HEP YAML** 符合文档：包含 `interfaceName`、`node`、`labels`，可选 `expectedIPs`。无需 `profiles`（我们用 GNP 控制策略）。

---

### Q4: GlobalNetworkPolicy 在 bare-metal 模式下怎么写？

**官方文档（reference/resources/globalnetworkpolicy）**：

Selector 语法支持的运算符包括：
- `all()` — 匹配所有 in-scope endpoints（对 GNP 来说：所有命名空间的 workload endpoints + host endpoints）
- `has(k)` — 包含该 label
- `k == 'v'`、`k != 'v'`、`k in {}`、`k contains`、`k starts with`、`k ends with`
- 逻辑：`&&`、`||`、`!`

**文档关于 `all()`**：

> "a rule with a selector `all()` won't match 'all packets', it will match 'packets from all in-scope endpoints and network sets'." 
> "For GlobalNetworkPolicy specifically, the in-scope endpoints include both workload and host endpoints across namespaces."

文档中 `spec.selector` 的 **default 值就是 `all()`**，说明 `all()` 是文档认可的写法。

**文档中的 GNP 例子**（protect-hosts-tutorial）使用的是 `selector: has(host-endpoint)`（label-based），不是 `all()`。但代码注释里明确说明为什么用 `all()` 而不是 label selector：label propagation timing race 会导致 HostNormalTiers 为空 → 策略 deny。`all()` 可以避免这个 race。

Felix 自己的 BPF FV 测试（`xdp_test.go allowAllPolicy`）就用 `selector: all()` + allow all，我们的做法与 Felix 内部测试一致。

**我们的 GNP YAML 符合文档**。docs 没有禁止 `all()`，且其为 spec.selector 的 default。

---

### Q5: BPF dataplane 在 bare-metal 是否被支持？（最关键问题）

#### 官方文档的立场

所有 eBPF/BPF dataplane 相关文档页（`operations/ebpf/install`、`operations/ebpf/enabling-ebpf`、`operations/ebpf/use-cases-ebpf`）均**只讨论 Kubernetes 集群**。具体来说：

- `install` 页：要求 "Kubernetes datastore driver"，明确列出支持的 K8s distributions（kubeadm、kOps、EKS、AKS、OpenShift、RKE、MKE）
- `enabling-ebpf` 页：只讲如何在 existing K8s cluster 启用 eBPF
- `use-cases-ebpf` 页：focus 在 Kubernetes container 环境，不提 host endpoints

**bare-metal / non-cluster host 文档**（`getting-started/bare-metal/`）提到的三种安装方式：
1. Docker container（支持 networking + policy）
2. Binary with package manager（**policy only**）
3. Binary without package manager（**policy only**）

这些页面**没有任何 BPF dataplane 相关的内容**。文档既没有说 "支持"，也没有说 "不支持"。

#### 源码层面的分析

Felix 的 `BPFEnabled` 配置（`config_params.go:190`）是一个纯 bool，没有检查 datastore 类型，没有检查是否 Kubernetes。Felix 启动时：

```go
BPFEnabled bool `config:"bool;false"`
```

Felix 会读取 `FELIX_BPFENABLED` 环境变量，若为 `true` 则启用 BPF dataplane，不检查是否在 Kubernetes 环境。

从代码路径看：
- `configureAndCheckIPAddressSubnets` 在 `BACKEND=none` 时返回，不写 bgp 地址
- 但 Felix 本身的 BPF datapath（`bpf_ep_mgr.go`）只要 `BPFEnabled=true` + `hostIP != nil` 就会工作
- 我们通过 `_set_node_bgp_ipv4()` 手动设置 `spec.bgp.ipv4Address` 绕过了 hostIP 缺失问题

#### 结论

**BPF dataplane 在 bare-metal 官方文档没有明确支持，也没有明确禁止。是 ad-hoc 用法，但源码上可以工作。**

- 官方支持的 BPF dataplane 场景：Kubernetes + kubernetes datastore
- 我们的场景：non-K8s + etcdv3 datastore + `BACKEND=none` + `FELIX_BPFENABLED=true`
- Felix 代码本身不强制要求 K8s，因此 `FELIX_BPFENABLED=true` 在 bare-metal 可以工作
- 但这是无文档保证的用法，Tigera 不会为这种组合 QA/support

**一句话**：BPF dataplane 在 bare-metal **官方不支持（无文档）**，但 Felix 代码本身不阻止它，当前实现通过手动设置 `spec.bgp.ipv4Address` 绕过 `BACKEND=none` 跳过 BGP 的问题，在实践中可以工作。

---

### Q6: 完全按 docs 跑有哪些前提依赖？

#### 是否需要 BIRD（BGP daemon）？

- `BACKEND=bird`：需要 BIRD，文档描述 "BIRD BGP daemon"
- `BACKEND=none`（我们用的）：不需要 BIRD

#### 是否需要 IPPool 资源？

文档说 IPPool 是 IPAM 管理，用于给 workload 分配 IP。在 `BACKEND=none` policy-only 场景：
- 官方 bare-metal binary 安装页提到 `NO_DEFAULT_POOLS=true`，明确**不需要** IPPool
- 我们设置了 `NO_DEFAULT_POOLS=true`，行为一致

#### 是否需要 Profile 资源？

- Profile 是 optional，用于跨 endpoint 共享 label
- policy rules 字段已 deprecated，只有 `labelsToApply` 有用
- 我们不需要 Profile（GNP `all()` 已覆盖所有 endpoint）

#### 是否需要 WorkloadEndpoint？

- WorkloadEndpoint 是 Calico CNI 为 Pod/容器自动创建的资源
- 在 bare-metal non-K8s 场景，没有 Pod，没有 CNI，不需要 WorkloadEndpoint
- 我们用 HostEndpoint 代替，这是正确做法

---

## 步骤 3: 当前实现 vs Docs Diff 表

| Item | 当前实现 | Docs 推荐 | 兼容性 | 是否需要改 |
|---|---|---|---|---|
| `CALICO_NETWORKING_BACKEND` | `none` | `none`（policy-only）/ `bird`（full networking） | **完全兼容** — docs 明确支持 `none` 用于 policy-only | 不需要改 |
| Node BGP IPv4 | 手动 `calicoctl apply` 加 `spec.bgp.ipv4Address` | Docs 说 policy-only 只需 `metadata.name`，不需要 bgp | **偏离文档，但必要** — Felix BPF datapath 需要 hostIP；BACKEND=none 不写 bgp 是 docs 行为，但与 BPF 有冲突 | 不能删（有具体技术原因） |
| HEP YAML | `{name, interfaceName, node, labels, expectedIPs?}` | Docs schema：`{node(required), interfaceName, expectedIPs, profiles, ports}` | **符合文档** — 用了所有 required 字段，optional 字段选取合理 | 不需要改 |
| GNP YAML `selector: all()` | `all()` + allow Ingress+Egress | Docs default 为 `all()`，docs 认可此写法；protect-hosts-tutorial 用 label-based 但不禁止 all() | **符合文档** — all() 是 GNP selector 的 default 值；Felix 内部测试也用 all() | 不需要改 |
| BPF dataplane（`FELIX_BPFENABLED=true`） | 在 bare-metal + etcdv3 + BACKEND=none 用 BPF | Docs 的 BPF 文档只覆盖 Kubernetes；bare-metal 文档不提 BPF | **无文档支持，ad-hoc 用法** — 代码上工作，但无官方 QA | 这是项目核心目标，不能改；须在论文中标注 |
| IPPool | 无（`NO_DEFAULT_POOLS=true`） | Docs bare-metal policy-only 模式不需要 IPPool | **完全兼容** | 不需要改 |
| Profile | 无 | Docs 说 optional，policy rules 已 deprecated | **完全兼容** | 不需要改 |
| WorkloadEndpoint | 无 | 非 K8s 场景无需，用 HEP 代替 | **完全兼容** | 不需要改 |
| `IP_AUTODETECTION_METHOD` | `interface=<device>` | Docs 未提此变量（文档只提 CALICO_IP） | **docs 不明确，我推断**：这是 calico-node startup 的合法变量，源码 `startup.go` 支持 | 不需要改 |
| `NO_DEFAULT_POOLS=true` | 设置 | Docs bare-metal binary 页明确提及此变量 | **完全兼容** | 不需要改 |
| `FELIX_BPFKUBEPROXYIPTABLESCLEANUPENABLED=false` | 设置 | Felix docs：此参数"requires Kubernetes environment"；我们关闭它正确 | **正确** — 非 K8s 场景应关闭 | 不需要改 |
| `FELIX_BPFCONNECTTIMELOADBALANCING=Disabled` | 设置 | Felix docs 描述此参数"required for reaching Kubernetes services"；关闭正确 | **正确** — 非 K8s 无 ClusterIP | 不需要改 |
| `FELIX_GenericXDPEnabled=true`（veth only） | benchmark veth 时开启 | Felix config param，无特殊要求 | **正确** — veth 不支持 native XDP | 不需要改 |

**总结**：当前实现与文档的唯一实质性分歧是：

1. **Node bgp.ipv4Address hack**：文档说 policy-only 不需要填 bgp，但我们必须填，因为 Felix BPF path 需要 hostIP
2. **BPF dataplane 在 bare-metal**：文档只支持 K8s，我们是 ad-hoc

这两个分歧相互关联：正是因为使用了 BPF（docs 不支持的），才需要 bgp hack（否则 hostIP 为空）。

---

## 步骤 4: 推荐方案

### 方案 A：完全 docs-aligned（理想）

**内容**：
- 切换到 `BACKEND=bird`，安装 BIRD daemon
- 让 `-startup` 自动写 `spec.bgp.ipv4Address`（因为 bird 模式下它会自动写）
- 删除 `_set_node_bgp_ipv4()` hack
- HEP / GNP 保持不变（已符合 docs）
- 安装 BIRD：在 runner-runtime Dockerfile 加 `apt-get install -y bird2`

**问题**：
- BPF dataplane 在 bare-metal 仍然不是 docs 支持的，即使改了 BACKEND 也不改变这一点
- BIRD 在 VM 里需要正确配置 BGP peer 或 route reflector，否则 BIRD 进程可能 crash 或反复 reconnect，产生噪声
- 改动量：~20-40 行 calico.py，+ Dockerfile 一行，+ BIRD 配置文件
- **关键风险**：`BACKEND=bird` 需要 BIRD 运行，但我们没有 BGP peer，BIRD 会 idle/fail 但不影响 Felix policy enforcement；需要验证 Felix 是否因 BIRD 不健康而影响 BPF attach

**能否让 wrk traffic 通过 TC datapath**：理论上可以，`-startup` 会自动写 bgp 地址，Felix 获得 hostIP。但需要测试验证 BIRD 不正常时 Felix 是否仍工作。

**结论**：改动小，但引入不确定性（BIRD 配置），且 BPF-on-bare-metal 问题本质不变，不推荐。

---

### 方案 B：部分 docs-aligned + 必要 hack 标注（推荐）

**内容**：
- 保留 `BACKEND=none`（合法，docs 支持）
- 保留 `_set_node_bgp_ipv4()` hack，但：
  - 添加更详细注释说明这是 Felix BPF-on-bare-metal 的必要 workaround
  - 注明官方文档不支持此场景，引用 docs URL
  - 探索是否可用 `spec.addresses[InternalIP]` 替代 `spec.bgp.ipv4Address`（felixnodeprocessor.go:97-108 的 fallback 路径）
- HEP / GNP / IPPool 保持不变（已符合 docs）
- 在 `_command_env()` 的 BPF 相关变量附近添加注释标注 "bare-metal BPF is ad-hoc"

**改动估算**：0 行代码改动，仅注释增强，或 ~5-10 行替换 `spec.bgp` 为 `spec.addresses`

**能否让 wrk traffic 通过 TC datapath**：是，当前就能工作。

**风险**：无功能风险，仅论文中需要标注 limitation。

---

### 方案 C：接受现状 + 文档化

**内容**：
- 当前实现"能跑但不合规"，在代码注释中说明 limitation
- 不做任何改动
- 在论文 / 报告中说明：Calico corpus 基准使用了非官方的 bare-metal + BPF 配置，该配置在 Felix 代码层面可以工作，但 Tigera 官方不提供 QA 保证

**改动估算**：0 行

**能否让 wrk traffic 通过 TC datapath**：是

**风险**：低，当前已验证可工作

---

### 方案选择建议

**推荐方案 B**（部分 docs-aligned + 必要 hack 标注），理由：

1. 当前实现在功能上是正确的（能让 wrk 流量通过 calico TC datapath，corpus 有结果）
2. 偏离 docs 的两处（bgp hack + BPF-on-bare-metal）都有具体技术原因，不是疏忽
3. 方案 A 的 BIRD 引入新风险，不值得
4. 唯一价值是改善代码可读性和注释质量

**可考虑的小优化**：将 `spec.bgp.ipv4Address` 改为 `spec.addresses[InternalIP]`（felixnodeprocessor 的 fallback 路径），这样在语义上更准确（我们不是在配置 BGP，而是告诉 Felix 节点的 IP）。但这需要验证 felixnodeprocessor 的 fallback 路径确实产生 HostIPKey，需要实际测试。

---

## 步骤 5: 补充发现 — `spec.addresses` 作为 bgp hack 替代

源码 `felixnodeprocessor.go:96-108`：

```go
// Look for internal node address, if BGP is not running
if ipv4 == nil {
    ip, _ := cresources.FindNodeAddress(node, internalapi.InternalIP, 4)
    if ip != nil {
        ipv4 = ip
    }
}
if ipv4 == nil {
    ip, _ := cresources.FindNodeAddress(node, internalapi.ExternalIP, 4)
    if ip != nil {
        ipv4 = ip
    }
}
```

这意味着，如果 `spec.bgp` 为 nil，Felix node processor 会从 `spec.addresses` 里找 `InternalIP` 或 `ExternalIP`。Node 资源的 `spec.addresses` 格式：

```yaml
spec:
  addresses:
    - address: "198.18.0.1/30"
      type: InternalIP
```

这个路径比 `spec.bgp.ipv4Address` 在语义上更准确（InternalIP 更接近 "这是节点的 IP"），且不需要设置 BGP spec。docs 未明确记录这个行为（它在源码里作为 fallback），所以如果使用这个路径，仍是 ad-hoc，但技术上更干净。

---

## 关键发现总结

| 问题 | 结论 |
|---|---|
| `BACKEND=none` 是否 docs 支持 | **是**，docs 明确支持作为 policy-only 模式 |
| Node bgp.ipv4Address hack 是否必要 | **是**，`BACKEND=none` 时 `-startup` 不写 bgp 地址，Felix BPF 需要 hostIP；有 `spec.addresses` 替代路径但需验证 |
| HEP YAML 是否符合 docs | **是**，使用了所有 required 字段，可选字段合理 |
| GNP `selector: all()` 是否符合 docs | **是**，docs 的 selector default 就是 all()；不推荐但也不禁止 |
| BPF dataplane 在 bare-metal 是否官方支持 | **否**，官方 BPF 文档只支持 Kubernetes；bare-metal 文档不提 BPF |
| 当前实现是否能工作 | **是**，源码层面 Felix 不强制要求 K8s，workaround 是必要的 |
| 推荐方案 | **方案 B**（保留现状 + 改善注释），风险最低，功能正确 |
