# Cilium / Calico Workload Routing Research (2026-05-04)

## 摘要

corpus benchmark 跑 cilium/agent 和 calico/felix 时，49 + 6 = 55 个 BPF program 全部 REJIT applied，
但全部 run_cnt_delta = 0，无法进入 per_program geomean 计算。
根本原因是：wrk 产生的 HTTP traffic 走的是 veth pair (bpfbench0 ↔ bpfbenchns/bpfbench1)，
但 cilium/calico 的主力 datapath 程序需要 **控制面注册的 endpoint** 才会 attach 到 datapath。
没有 endpoint，主 TC datapath 就不存在，流量当然不经过 BPF 程序。

**推荐方案：方案 A-2（使用 calicoctl 向 etcd 注册 HostEndpoint，再配合已有 veth 流量）**，
改动约 40 行 Python，不引入新工具进程，流量路径真实。

---

## 1. cilium 和 calico 当前 attach 了什么

### 1.1 数据来源

- `corpus/results/x86_kvm_corpus_20260504_060930_581549/details/apps/cilium__agent.json`（cilium）
- `corpus/results/x86_kvm_corpus_20260504_061209_985057/details/apps/calico__felix.json`（calico）

### 1.2 Cilium：49 个 BPF program

Cilium 在非 K8s 模式下用 `--routing-mode=native --devices=bpfbench0` 启动，
会自动在配置 device 和每个"endpoint 所在 device"上 attach TC 程序。

这次 49 个 program 的类型分布：

| 程序名 | 类型 | 数量 | 含义 |
|-------|------|:----:|------|
| `dump_bpf_map` | `tracing` | 1 | 内部 BPF map 诊断 hook |
| `dump_bpf_prog` | `tracing` | 1 | 内部 BPF prog 诊断 hook |
| `cil_from_host` | `sched_cls` | 6 | TC egress on host-facing device（从 host NS 出流量） |
| `cil_to_host` | `sched_cls` | 5 | TC ingress on host-facing device（到 host NS 进流量） |
| `cil_host_policy` | `sched_cls` | 6 | host endpoint policy tail program |
| `cil_from_netdev` | `sched_cls` | 5 | TC ingress on external netdev（从外部到 host） |
| `cil_to_netdev` | `sched_cls` | 4 | TC egress on external netdev（从 host 到外部） |
| `tail_handle_ipv4_from_netdev` | `sched_cls` | 7 | IPv4 forward tail call（netdev 来源） |
| `tail_handle_ipv4_from_host` | `sched_cls` | 7 | IPv4 forward tail call（host 来源） |
| `tail_drop_notify` | `sched_cls` | 7 | 丢包通知 tail call |

**关键观察**：
- `cil_from_host` 和 `cil_to_host` 是 host-endpoint（host namespace 方向）程序。
- `cil_from_netdev` 和 `cil_to_netdev` 是 netdev-side（外部方向）程序。
- 多实例重复是因为 Cilium 为每个 **endpoint** 和每个 **device** 各编译一份 datapath。
- 这次跑了 49 个 program，说明 Cilium agent 启动后 attach 了多组（约 6-7 个 device/endpoint 组）。
  这些额外的 device 通常是 Cilium 自动创建的内部 veth（如 `lxc_*`、`cilium_host`、`cilium_net`）。

**run_cnt_delta 情况**：
- `cil_from_host` (id=111): run_cnt_delta = 1
- `cil_to_host` (id=122): run_cnt_delta = 1
- 其余 47 个 program: run_cnt_delta = 0

只有 host device 上的 ingress/egress 各被命中 1 次（可能是初始化探测包），
之后的 wrk 流量（127 req/s）完全没有经过任何 cilium BPF program。

### 1.3 Calico：6 个 BPF program

Felix 在 `FELIX_BPFENABLED=true`、`FELIX_BPFDATAIFACEPATTERN=^bpfbench0$`、
无 K8s 纯 etcd 模式下启动。这次加载的程序：

| prog ID | 程序名 | 类型 | attach 语义 |
|---------|-------|------|------------|
| 56 | `conntrack_cleanup` | `sched_cls` | Felix 定时用 `RunBPFProgram()` 调用的清理程序，非 TC attach |
| 59 | `cali_tcx_test` | `sched_cls` | TCX 能力探测程序（只用于检测内核是否支持 TCX attach） |
| 67 | `calico_tc_allow` | `sched_cls` | policy tail call：允许包通过 |
| 68 | `calico_tc_deny` | `sched_cls` | policy tail call：拒绝包 |
| 70 | `calico_tc_allow` | `sched_cls` | policy tail call（另一对） |
| 71 | `calico_tc_deny` | `sched_cls` | policy tail call（另一对） |

**关键缺失**：Calico 的主 TC datapath 程序是 `calico_tc_main`（`bpf_ep_mgr.go` 里 `attachDataIfaceProgram()` 
装载的是 `from_hep_debug.bpf.o` / `to_hep_debug.bpf.o` / `from_wep_debug.bpf.o` 里的主程序）。
这些程序**完全没有出现**在本次 result.json 里。

查看 `corpus/build/calico/` 目录确认 calico 的真实 BPF 对象文件：
```
from_hep_debug.bpf.o   # HostEndpoint 方向（进）
to_hep_debug.bpf.o     # HostEndpoint 方向（出）
from_wep_debug.bpf.o   # WorkloadEndpoint 方向（进）
to_wep_debug.bpf.o     # WorkloadEndpoint 方向（出）
from_nat_debug.bpf.o   # NAT 方向（进）
to_nat_debug.bpf.o     # NAT 方向（出）
xdp_debug.bpf.o        # XDP 层
```

Felix 的 `bpf_ep_mgr.go` 代码明确显示：
`attachDataIfaceProgram()` 只在 `hostIfaceToEpMap` 里有对应 HostEndpoint 时才为接口 attach 主 TC 程序。
没有 HostEndpoint 注册，`bpfbench0` 上就没有任何 `calico_tc_main` / `calico_tc_skb_*` 系列程序。

6 个被记录的 program 是 Felix 自己内部 bootstrap 时加载的辅助/probe 程序，不是真正的 datapath 程序。

**全部 run_cnt_delta = 0**：即使是 policy tail call（calico_tc_allow / calico_tc_deny）
也没有被命中，这进一步证明主 TC entry program 根本不存在，tail call 自然也不会被触发。

---

## 2. 当前 wrk traffic 路径

### 2.1 架构

```
runner/libs/app_runners/cilium.py（calico.py）
  → _ensure_benchmark_interface()
    → ip link add bpfbench0 type veth peer name bpfbench1
    → ip netns add bpfbenchns
    → ip link set bpfbench1 netns bpfbenchns
    → ip addr add 198.18.0.1/30 dev bpfbench0
    → ip netns exec bpfbenchns ip addr add 198.18.0.2/30 dev bpfbench1
```

### 2.2 workload 执行

`run_named_workload("network", seconds, network_device="bpfbench0")` 调用链：
```
run_network_load(duration_s, network_device="bpfbench0")
  → _network_http_server("bpfbench0")
      → NamespacedHttpServer("bpfbenchns", "198.18.0.2", 18080)
          # 在 bpfbenchns 内启动 Python HTTP server 监听 198.18.0.2:18080
  → _network_client_command(["wrk", ...], "bpfbench0")
      → ["ip", "netns", "exec", "bpfbenchns", "wrk", "-t2", "-c10", ...]
          # 在 bpfbenchns 内执行 wrk，访问 http://198.18.0.2:18080/
```

结论：

- HTTP server 在 `bpfbenchns` 内监听 `198.18.0.2:18080`
- wrk client 也在 `bpfbenchns` 内运行（`ip netns exec bpfbenchns wrk ...`）
- 流量路径：`bpfbenchns 内 wrk → 198.18.0.2:18080 → bpfbenchns 内 HTTP server`
- 这是 **纯 loopback 路径**，完全不经过 veth pair，也不经过 bpfbench0

*注：wrk stdout 显示 "Running 1s test @ http://198.18.0.2:18080/"，速率 115–140 req/s，
但 run_cnt_delta = 0 证明实际没有经过 bpfbench0 上的任何 TC BPF 程序。*

---

## 3. 路径差异：traffic 路径 vs attach 点

### 3.1 Cilium

```
实际 traffic 路径：
  bpfbenchns/bpfbench1(lo) → 198.18.0.2:18080
  [完全在 bpfbenchns 内，不经过 bpfbench0]

Cilium 程序 attach 位置：
  bpfbench0（host NS 侧）: cil_from_host(TC egress), cil_to_host(TC ingress)
  Cilium 内部 veth（lxc_*, cilium_host 等）: cil_from_netdev, cil_to_netdev, tail calls

结论：
  traffic 完全在 bpfbenchns 内部绕回（loopback），
  bpfbench0 上的 TC hook 不会命中，
  Cilium 也没有注册 bpfbenchns 里的进程为 endpoint，
  因此不会有 lxc veth pair 为其 attach 任何程序。
```

### 3.2 Calico

```
实际 traffic 路径：
  bpfbenchns(lo) → 198.18.0.2:18080
  [完全在 bpfbenchns 内]

Calico 程序 attach 条件：
  Felix bpf_ep_mgr.go → attachDataIfaceProgram() 
    只有在 hostIfaceToEpMap[ifaceName] 存在时才为 ifaceName attach 主 TC 程序
  hostIfaceToEpMap 来源：Felix 从 etcd 读取 HostEndpoint CRD 资源

当前 etcd 中无任何 HostEndpoint 资源 →
  bpfbench0 没有被 Felix attach 任何主 TC 程序 →
  加载的 6 个 program 全是辅助/probe 程序 →
  traffic 不经过任何 BPF TC hook
```

### 3.3 根本矛盾

| | Traffic 实际路径 | BPF attach 位置 | 命中 |
|-|-----------------|----------------|:----:|
| Cilium | bpfbenchns 内 loopback | bpfbench0 TC hook + 内部 lxc veth | 0 |
| Calico | bpfbenchns 内 loopback | 主 TC 程序根本不 attach（无 HEP） | 0 |

两个问题叠加：
1. **Traffic 路径错误**：wrk 和 server 都在 bpfbenchns 里，流量走 loopback，不经过 bpfbench0
2. **控制面缺失**：没有注册 endpoint，Cilium/Calico 的主 datapath TC 程序要么不存在，
   要么挂在错误的 device 上

---

## 4. 修复方案分析

**禁止**：任何使用 `BPF_PROG_TEST_RUN` 或合成 packet inject 的方案。

### 方案 A：纠正 traffic 路径，让 wrk 的包跨过 bpfbench0

**A-1 子方案：wrk 在 root ns，server 在 bpfbenchns**

修改思路：`run_network_load` 的 HTTP server 留在 bpfbenchns（现状不变），
但 wrk client 改到 root namespace 运行，从 198.18.0.1 发包到 198.18.0.2，
让流量实际穿过 bpfbench0 veth。

```
root ns (wrk) → bpfbench0 → bpfbench1/bpfbenchns → HTTP server
```

- 这样 bpfbench0 上的 TC hook 会被命中
- 前提：Cilium 已经在 bpfbench0 上 attach 了程序（现状是有 cil_from_host/cil_to_host）
- Calico 仍然需要 HostEndpoint 注册（见下面 A-2）

改动位置：`runner/libs/workload.py` 中 `_network_client_command()`，
当 network_device=bpfbench0 时，不要用 `ip netns exec bpfbenchns`，
而是直接在 root ns 运行 wrk。

改动量估算：约 **15 行 Python**（修改 `_network_client_command()` 逻辑，
同时需要保证其他不依赖 BENCHMARK_IFACE 的 runner 不受影响）。

但对 Cilium 只能解决"traffic 不穿越 veth"的问题。对 Calico，main TC program 仍然不存在。

**A-2 子方案：向 etcd 注册 HostEndpoint（Calico），修 Cilium 配置**

对 Calico：在 Felix 启动前，用 `calicoctl`（或直接写 etcd API）向 etcd 注册一个 HostEndpoint 资源，
指向 bpfbench0：

```yaml
apiVersion: projectcalico.org/v3
kind: HostEndpoint
metadata:
  name: bpfbench0-ep
  labels:
    host: benchmark
spec:
  node: <hostname>
  interfaceName: bpfbench0
  expectedIPs:
    - 198.18.0.1
```

Felix 启动后读取 etcd 发现 HostEndpoint，
会触发 `attachDataIfaceProgram()` 为 bpfbench0 attach 真正的 `from_hep_debug.bpf.o` 程序。
然后流量从 root ns 穿越 bpfbench0（A-1 的修改），就会命中这些 TC program。

改动位置：
- `runner/libs/app_runners/calico.py`：`start()` 方法里，在 Felix 启动前，
  调用 `run_command(["calicoctl", "create", "-f", hep_yaml_path])` 注册 HEP；
  `stop()` 方法里清理。
- 需要 calicoctl 工具可用（或直接用 etcd client 写 JSON）

改动量估算：约 **40 行 Python** + calicoctl 工具依赖（或 ~20 行额外 etcd API 调用）

对 Cilium：在本次结果里，traffic 路径问题解决后（wrk 在 root ns），
cil_from_host 和 cil_to_host 理论上会命中。
但 Cilium 的"endpoint"需要通过 etcd 注册（类似创建一个 logical endpoint），
否则只有 host-level program，没有 workload-level 的 lxc veth 对应程序。
建议先验证 cil_from_host/cil_to_host 是否达到足够的 run_cnt。

**A 方案总体估算**：
- 改动行数：40–60 行 Python
- 依赖：calicoctl binary 或 etcd Python client（etcd3 库）
- 真实性：流量真实穿越 veth，经过 production-like TC attach 路径
- 可移植性：KVM VM 和 AWS EC2 都可以，bpfbench0 veth 在两种环境都有

### 方案 B：强制 daemon 在已知 device 上 attach（配置 Cilium/Calico 监听真实 lo 或特定 veth）

Cilium 没有"强制不 attach endpoint，只 attach host-device"的简单开关。
`--routing-mode=native --devices=bpfbench0` 已经是最小配置。
核心问题在于：即使 Cilium attach 在 bpfbench0，wrk 也在 bpfbenchns loopback，不穿越。

Calico 的 `FELIX_BPFDATAIFACEPATTERN` 已经设置为 `^bpfbench0$`，
但 Felix 代码（`bpf_ep_mgr.go:3491`）明确要求 `hostIfaceToEpMap[ifaceName]` 存在，
即必须有 HostEndpoint 对应这个 interface，才会 attach 主 TC 程序。
没有配置开关可以绕过这一要求。

**结论**：方案 B 单独不可行，必须配合方案 A（注册 HEP + 修正 traffic 路径）。

### 方案 C：创建 minimal namespace/veth 模拟 K8s pod，让 daemon 视其为 endpoint

对 Calico：创建一个 workload netns（类似 pod 网络 namespace），
在里面启动 HTTP server，并通过 calicoctl 注册 WorkloadEndpoint。
Felix 检测到 WEP 后会创建 lxc-like veth pair，attach `from_wep_debug.bpf.o`/`to_wep_debug.bpf.o`。

这比 HostEndpoint 更接近 Calico 的真实生产场景（K8s pod 流量），
但配置更复杂：需要 ip netns + veth + calicoctl create WorkloadEndpoint。

对 Cilium：Cilium 在无 K8s 时无法方便地创建 endpoint（`cilium endpoint create` 需要特定内部资源）。
历史记录 `docs/tmp/cilium-calico-install-20260425/summary.md` 已经指出：
Cilium 官方文档只说明了 native + no-K8s + etcd 路径，但 endpoint 创建没有标准 CLI 文档化。

改动量估算：约 **80–100 行 Python** + 复杂的 WEP YAML 生成逻辑
- 依赖：calicoctl、ip netns、额外 veth pair 管理
- 真实性：更接近 K8s pod 路径，但 standalone 模式 Felix WEP 可能有未知 bug
- 可移植性：KVM 和 AWS EC2 均可

### 方案 D：跑 minikube/kind 单节点 K8s，部署 nginx pod

在 KVM VM 内启动完整的 minikube 或 kind 集群，部署带 Cilium/Calico CNI 的单节点 K8s，
创建 nginx pod，用 wrk 打 nginx pod 的 ClusterIP 或 NodePort。

- 改动量：需要在 Dockerfile 里加 kind/minikube/kubectl，
  `runner/libs/app_runners/cilium.py` 和 `calico.py` 完全重写为 K8s-aware runner
  估计 **500+ 行** Python + Dockerfile 改动
- 依赖：docker-in-docker 或 kind，k8s api server，重量级依赖
- 真实性：最真实，production K8s 路径
- 可移植性：KVM VM 内的 Docker-in-Docker 配置复杂；AWS EC2 需要额外权限
- 启动时间：kind/minikube 启动约 60–120 秒，严重影响 benchmark 吞吐

历史经验：`docs/tmp/cilium-calico-install-20260425/summary.md` 已经明确指出
Cilium 在非 K8s 模式下已经有明确的官方文档支持路径，方向正确，
只是 traffic 路径没有对上。

---

## 5. 方案评估对比

| 维度 | 方案 A（修路径 + HEP 注册） | 方案 B（配置调整） | 方案 C（WEP 模拟 pod） | 方案 D（kind K8s） |
|------|--------------------------|------------------|----------------------|------------------|
| 改动行数 | ~40–60 行 Python | 不可行（配置不够） | ~80–100 行 Python | ~500+ 行 |
| 新工具依赖 | calicoctl（已在 runner/repos） | 无 | calicoctl | kind/kubectl/minikube |
| 真实性 | 真实 TC hook，host endpoint 路径 | N/A | 更真实 workload endpoint 路径 | 最真实 K8s 路径 |
| 可移植性 | KVM VM + AWS EC2 均可 | N/A | KVM VM + AWS EC2 均可 | KVM 复杂，AWS 需权限 |
| 启动开销 | < 5 秒（calicoctl 注册） | N/A | ~5–10 秒（netns + WEP 注册） | 60–120 秒 |
| 风险 | Felix HEP 在非 K8s 模式有少量未知行为 | N/A | WEP 模式复杂，Bug 更多 | 极高复杂度 |
| 覆盖哪些 progs | calico: 主 TC HEP progs；cilium: cil_from/to_host | 无 | calico: 主 TC WEP progs；cilium 仍困难 | 全部 |

---

## 6. 推荐方案及理由

**推荐方案 A-2**：同时修正 traffic 路径（wrk 改到 root ns）+ 向 etcd 注册 HostEndpoint（Calico）。

**理由**：

1. **改动量最小**：约 40–60 行 Python，不引入新的工具进程或镜像层。
   calicoctl 已在 `runner/repos/calico/` 目录下，只需确认 binary 可用。

2. **不违反 app-level loader 原则**：不直接加载任何 `.bpf.o` 文件，
   仍然通过 Felix 自身加载 datapath，只是补上了 Felix 需要的控制面状态（HEP 资源）。

3. **traffic 真实性高**：wrk 包从 root ns 出发，穿越 bpfbench0 veth，
   经过 TC hook，到达 bpfbenchns 内的 HTTP server。
   这是真实的 host-to-network 流量路径，对应 Calico 的 host endpoint datapath。

4. **已有足够的前期调研支撑**：
   - `docs/tmp/cilium-calico-install-20260425/summary.md` 已分析过 Felix HostEndpoint 路径
   - `docs/tmp/workload-coverage-research-20260427.md` 已确认"missing prerequisite is control-plane state"
   - Felix `bpf_ep_mgr.go` 代码（`attachDataIfaceProgram` 在 `hostIfaceToEpMap` 非空时执行）
     明确证明注册 HEP 是触发主 TC program attach 的必要条件

5. **Cilium 侧附带改善**：traffic 路径修正后（wrk 在 root ns），
   cil_from_host（bpfbench0 egress）和 cil_to_host（bpfbench0 ingress）
   run_cnt 会从当前的 0–1 提升到数百次/秒。
   这不需要额外改动 Cilium runner，只改 traffic 路径即可。

6. **可移植**：KVM VM 和 AWS EC2 都运行同样的 Python runner，
   bpfbench0 veth pair 在两种环境已经存在，HEP 注册只需要 etcd 可达（已有 LocalEtcdSession）。

**方案 A-2 具体实施点**（仅供参考，不实施）：

对于 Calico (`runner/libs/app_runners/calico.py`)：
- `start()` 方法：在 `super().start()` 前，用 `calicoctl apply -f` 创建 HostEndpoint YAML，
  指向 `self.device`（bpfbench0），expectedIPs 从 `BENCHMARK_IFACE_CIDR` 取
- `stop()` 方法：清理 HostEndpoint 资源

对于 workload 路径 (`runner/libs/workload.py`)：
- `_network_client_command()` 的逻辑：
  当 `network_device = BENCHMARK_IFACE ("bpfbench0")` 时，
  wrk client **不**用 `ip netns exec bpfbenchns`，直接在 root ns 运行
- HTTP server 保持在 bpfbenchns（198.18.0.2），这样流量必须经过 bpfbench0 veth

**风险**：
- Felix HEP 在没有 IPPool 和 Route 的情况下行为可能有限制（policy-only 模式的已知限制）
- Cilium 在本次场景下能覆盖的 program 仍然有限（只有 host-facing 程序，
  没有 workload-facing 的 lxc 程序）；需要实跑验证 run_cnt 是否足够

---

## 7. 附：历史结果一致性确认

检查了 5 个不同时间点的 calico 结果，全部 6 个 program 的 run_cnt_delta = 0：
```
x86_kvm_corpus_20260504_061209_985057:  6 progs, 0 non-zero run_cnt
x86_kvm_corpus_20260503_160127_479922:  6 progs, 0 non-zero run_cnt
x86_kvm_corpus_20260503_212536_397107:  6 progs, 0 non-zero run_cnt
x86_kvm_corpus_20260503_145110_428181:  6 progs, 0 non-zero run_cnt
```

检查了 5 个 cilium 结果，非零 run_cnt 极少（0–3 个，均为 cil_from_host / cil_to_host，每次 run_cnt ≤ 3）：
```
x86_kvm_corpus_20260504_060930_581549:  49 progs, 2 non-zero (cil_from_host:1, cil_to_host:1)
x86_kvm_corpus_20260503_..._428181:     43 progs, 2 non-zero (cil_from_host:1, cil_to_host:1)
x86_kvm_corpus_20260503_..._674179:     56 progs, 3 non-zero (cil_to_host:1, cil_from_host:1, cil_to_host:1)
```

这进一步证明问题是系统性的，与 SAMPLES 数量无关。

---

## 8. 参考代码路径

- cilium runner：`runner/libs/app_runners/cilium.py`
- calico runner：`runner/libs/app_runners/calico.py`
- workload 函数：`runner/libs/workload.py:2400–2448`（`_network_http_server`, `_network_client_command`, `run_network_load`）
- 网络常量：`runner/libs/benchmark_net.py`（bpfbench0=198.18.0.1, bpfbenchns, bpfbench1=198.18.0.2）
- Felix BPF endpoint manager：`runner/repos/calico/felix/dataplane/linux/bpf_ep_mgr.go:2884`（`attachDataIfaceProgram`）
- Felix HEP mapping 逻辑：`runner/repos/calico/felix/dataplane/linux/bpf_ep_mgr.go:3489–3500`（`hostIfaceToEpMap` 判断）
- Cilium reconcile 调研：`docs/tmp/cilium-disable-reconcile-20260426/summary.md`
- Calico/Cilium 安装设计：`docs/tmp/cilium-calico-install-20260425/summary.md`
- 上次 workload coverage 研究：`docs/tmp/workload-coverage-research-20260427.md:243–255`
- 数据文件（cilium）：`corpus/results/x86_kvm_corpus_20260504_060930_581549/details/apps/cilium__agent.json`
- 数据文件（calico）：`corpus/results/x86_kvm_corpus_20260504_061209_985057/details/apps/calico__felix.json`
