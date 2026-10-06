# Katran E2E Benchmark 可行性调研

日期：2026-03-18  
仓库：`/home/yunwei37/workspace/bpf-benchmark`  
结论对象：是否用 Katran 替换当前 `xdp_forwarding` E2E

## TL;DR

- **推荐把 Katran 作为下一代 XDP E2E 候选，但不建议现在直接硬替换。**
- **推荐 scope 不是“完整 Katran 系统”，而是只做 `balancer_ingress` 这个主 XDP datapath。**
- 当前 corpus 里 Katran 的 **`0.872x` 不能直接解读为“Katran 不适合”**。原因是当前权威 rerun 中，**Katran 5 个程序里 0 个真正 applied recompile**，结果主要反映的是：
  - checked-in policy 漂移 / stale allowlist
  - 小程序的 sub-100ns 噪声
  - `balancer_ingress` 的 no-op baseline drift
- 真正有价值的信号是：
  - `balancer_ingress` live scan 有 **94 个 sites**
  - 比当前 `xdp_forwarding` 的 **3 个 sites** 强很多
  - 2026-03-12 的 `v2_fixed` corpus rerun 中，`balancer_ingress` 单程序达到 **1.118x**
  - 但 **CMOV/COND_SELECT 对 Katran 明显是负面的**，在 CMOV ablation 里 `balancer_ingress` 只有 **0.187x**
- **工程上可行，但比当前 `xdp_forwarding` case 重很多。**
  - 如果做一个只测 `balancer_ingress`、禁用 healthcheck、standalone attach 的 MVP，估计 **3-5 engineer-days**
  - 如果坚持用 Katran 上游的 C++ server / gRPC server 路线，在 VM 内完整构建，估计 **5-8+ engineer-days**，而且依赖风险更高

我的建议是：

1. **先新增 `katran_balancer` case，不立即删除 `xdp_forwarding`**
2. **先把 Katran policy 修正到 live/family-level 可用**
3. **跑通并确认有稳定正向数据后，再 retire `xdp_forwarding`**

---

## 1. Katran 项目分析

### 1.1 上游项目是什么

Katran 是 Meta/Facebook 开源的 **XDP L4 load balancer**。上游 README/USAGE 把它描述为：

- 一个 **XDP forwarding plane**
- 外加一个 **C++ library / server**，负责装载程序、初始化 maps、添加 VIP / real、healthcheck 配置等
- 网络模型是 **DSR + load balancer on a stick**

上游文档明确写了几点约束：

- 只支持 **DSR**
- 网络拓扑应当是 **L3 routed**
- 默认是 **单接口 ingress + egress 同口**
- 主 datapath 会把匹配 VIP 的包做 **session lookup / consistent hash / encapsulation**，然后发给 real

### 1.2 Katran 的 BPF 程序有哪些

本仓库 `corpus/build/katran/` 当前有 5 个 `.bpf.o`：

| 对象 | 程序 | 类型 | insn 数 | 备注 |
| --- | --- | --- | ---: | --- |
| `balancer.bpf.o` | `balancer_ingress` | XDP | 2322 | 主负载均衡 datapath |
| `healthchecking.bpf.o` | `healthcheck_encap` | TC (`sched_cls`) | 325 | healthcheck 封装 |
| `healthchecking_ipip.bpf.o` | `healthcheck_encap` | TC (`sched_cls`) | 103 | 更小的 healthcheck 变体 |
| `xdp_pktcntr.bpf.o` | `pktcntr` | XDP | 22 | 计数辅助程序 |
| `xdp_root.bpf.o` | `xdp_root` | XDP | 17 | shared-mode root dispatcher |

对“替换 `xdp_forwarding` E2E”真正 relevant 的，只有：

- **`balancer_ingress`**

其余几个不是：

- `healthcheck_*` 是 TC，不是 XDP 主 datapath
- `xdp_root` 只是 shared-mode root program
- `xdp_pktcntr` 太小，不适合作为 headline case

### 1.3 主 XDP 程序在做什么

`balancer_ingress` 的主路径大致是：

1. 解析 Ethernet + IPv4/IPv6
2. 查 `vip_map`
3. 做连接表 / LRU lookup
4. miss 时做 consistent hashing（`ch_rings`）
5. 查 `reals`
6. 更新 per-VIP / per-real stats
7. 进行 IPIP/GUE 封装
8. 返回 `XDP_TX`

它不是像 `xdp_forwarding` 那样的“简单 FIB forward”，而是一个真实的 **production LB datapath**。

### 1.4 是否有多个部署模式

有两个模式：

- **standalone**
  - 直接把 Katran XDP 程序 attach 到接口
- **shared**
  - 先挂 `xdp_root`
  - Katran 自己注册到一个 pinned `prog_array`

对 benchmark 来说，**推荐 standalone**：

- 少一个 `xdp_root` 干扰
- 少一个 prog array / pinned map
- 更容易隔离 `balancer_ingress`

### 1.5 依赖与构建复杂度

上游文档和当前 checkout 表明：

- BPF 对象本身已经在 `corpus/build/katran/` 预编译好了
- 但上游的 userspace library / server 构建依赖较重：
  - `folly`
  - `fmt`
  - `glog`
  - `gflags`
  - `libelf`
  - `libmnl`
  - `libzstd`
  - 如果要例子 server，还需要 `fbthrift` / `gRPC`

另外，本仓库当前 `corpus/repos.yaml` 对 Katran 是 **sparse checkout**，只保留了：

- `katran/lib`
- 根目录文档和脚本

而 **`example/` 和 `example_grpc/` 目录并不在当前 checkout 里**。这意味着：

- 虽然上游脚本 `start_katran_simple_server.sh` / `start_katran_grpc_server.sh` 还在
- 顶层 `CMakeLists.txt` 也还引用了 example 目录
- **但当前本地 checkout 不能直接把 example server build 出来**

这会显著抬高“像 Tracee 一样直接起 daemon”的实现成本。

### 1.6 能否在 VM 中部署运行

**能，但建议只部署主 XDP 程序，不要把上游整套系统一口气搬进来。**

具体判断：

- `balancer_ingress` 是 XDP，**不存在 scx/struct_ops 那种 `EOPNOTSUPP` blocker**
- healthcheck 可以先禁用，避免 TC / `clsact` / tunnel interface 复杂度
- 当前 framework VM 虽然没有 `CONFIG_VETH`，但 `xdp_forwarding` 已证明可以通过 `vng --network loop` 注入预先连好的 virtio NIC 对
- Katran 的 single-interface 模型比 `xdp_forwarding` 更适合这种 loop NIC 方案

### 1.7 是否有不依赖真实拓扑的 benchmark / test mode

**有。**

上游 `katran_tester` 使用 `bpf_prog_test_run` 做：

- fixture-based correctness test
- `perf_testing`

它的 perf mode 会输出：

- 平均每包 duration（ns）
- 推导出的 Mpps

所以 Katran **确实有“无需真实网络拓扑”的离线 perf/test 模式**。  
但这更像：

- correctness / fixture perf harness

而不是：

- live attach + live traffic + live program enumerate 的 E2E

因此它适合：

- 作为 harness bring-up / object-level sanity check

不适合直接替代论文里的 deployment-layer E2E。

---

## 2. Corpus 中 Katran 的现有数据

### 2.1 当前权威 rerun（`corpus_recompile_authoritative_20260313.json`）

Katran 当前 5 个程序在权威结果中的情况如下：

| 程序 | live sites | family 分解 | policy | applied | ratio |
| --- | ---: | --- | --- | --- | ---: |
| `balancer_ingress` | 94 | `bflip=56, rotate=20, cmov=8, wide=4, endian=4, extract=2` | 有 | 否 | 0.567x |
| `healthcheck_encap` (`healthchecking.bpf.o`) | 9 | `bflip=7, cmov=1, endian=1` | 有 | 否 | 1.333x |
| `healthcheck_encap` (`healthchecking_ipip.bpf.o`) | 3 | `bflip=3` | 无 | 否 | 1.000x |
| `pktcntr` | 2 | `bflip=2` | 无 | 否 | 0.857x |
| `xdp_root` | 0 | `0` | 无 | 否 | 0.778x |

Katran family geomean 正是：

- **`0.872x`**

### 2.2 这个 `0.872x` 代表什么

**它不代表“Katran 应用 recompile 后回归”。**

因为当前这次权威 rerun 里：

- **5/5 程序全部 `v5_run_applied=false`**
- 也就是 **0 个 Katran 程序实际吃到了 recompile**

因此这组数据只能说明：

- 当前 checked-in Katran policy / live remap 失效
- 再叠加很小程序的 timing noise

不能说明：

- `rotate`
- `branch-flip`
- `wide`
- `endian`

这些 family 在 Katran 上整体是负面的

### 2.3 Katran 的 policy 明显需要调整

本地 `corpus/policies/katran/` 只有两个 policy 文件：

- `corpus/policies/katran/balancer/balancer_ingress.policy.yaml`
- `corpus/policies/katran/healthchecking/healthcheck_encap.policy.yaml`

而且它们都是 **`version: 3` 的 explicit site allowlist**。

更关键的是，这两个 policy 与当前 live scanner 之间有明显漂移：

| 程序 | inventory scan | checked-in policy 注释 | live VM scan | 结论 |
| --- | ---: | ---: | ---: | --- |
| `balancer_ingress` | 29 (`cmov=5, wide=4, rotate=20`) | 18 (`cmov=8, wide=4, extract=2, endian=4`) | 94 (`cmov=8, wide=4, rotate=20, extract=2, endian=4, bflip=56`) | 三份数据互相不一致，policy 明显 stale |
| `healthcheck_encap` | 1 (`cmov=1`) | 2 (`cmov=1, endian=1`) | 9 (`cmov=1, endian=1, bflip=7`) | 同样 stale |

当前权威 rerun 里，Katran 两个带 policy 的程序都出现了典型问题：

- `policy site ... was not found in the live program`
- `policy selected 0 of N eligible rules`

所以这个 `0.872x` 的第一根因不是“family 本身有毒”，而是：

- **Katran 当前 checked-in corpus policy 已经失效**

### 2.4 什么时候 Katran 是正的，什么时候是负的

把较早几次 artifact 连起来看，结论更清楚：

| Artifact | `balancer_ingress` | `healthcheck_encap` | Katran geomean | 说明 |
| --- | ---: | ---: | ---: | --- |
| `corpus_v5_vm_batch_authoritative_20260311.json` | 0.846x | 0.529x | 0.776x | 主要含 CMOV |
| `corpus_v5_v2_fixed_20260312.json` | **1.118x** | 0.563x | 0.803x | family-level non-CMOV policy，`balancer` 转正 |
| `corpus_v5_tuned_policy.json` | 0.706x | 1.000x | 0.777x | mixed policy，波动较大 |
| `corpus_recompile_authoritative_20260313.json` | 0.567x | 1.333x | 0.872x | **0 applied，no-op + noise** |

这里最重要的观察是：

- **`balancer_ingress` 在可用的 family-level policy 下是可以正向的**
- 真正不稳定、拖 family geomean 的，反而是：
  - healthcheck 辅助程序
  - 小程序 no-op noise

### 2.5 哪个 family / form 导致回归

这个问题需要分开回答。

#### 2.5.1 对“当前权威 0.872x”来说

**不能归因到某个 family。**

因为：

- 当前权威 Katran rerun **没有 applied sites**
- 所以 `0.872x` 不是某个 family 的 applied regression
- 它更接近：
  - stale policy
  - no-op baseline drift
  - tiny programs noise

#### 2.5.2 对“已知被证实是负面的 family”来说

**CMOV / COND_SELECT 是 Katran 上最明确的负面 family。**

在 `post-cmov-fix-corpus-ablation` 里：

- Katran source-level normalized ratio：**0.342x**
- `balancer_ingress`：**0.187x**
- `healthcheck_encap`：**0.625x**

而这个 ablation 的 live CMOV pattern 全是：

- `cond-select-64`

所以至少对 Katran 来说，当前 E2E / corpus policy 的起点应当是：

- **`cmov: skip`**

#### 2.5.3 对“最值得尝试的 family”来说

对 `balancer_ingress` 的 live scan，family 规模排序是：

1. `branch-flip = 56`
2. `rotate = 20`
3. `cmov = 8`
4. `wide = 4`
5. `endian = 4`
6. `extract = 2`

结合已有 artifact，我认为：

- **最值得做 E2E 的 family 组合是：`branch-flip + rotate + wide + endian + extract`**
- **最明确应该先禁掉的是：`cmov`**

---

## 3. Katran E2E 可行性

### 3.1 能否像 Tracee 那样在 VM 中部署 Katran daemon

**原则上能，但不建议把“上游 daemon 全套构建”作为第一版路线。**

原因：

- Tracee/Tetragon 的 daemon 二进制更容易直接下载或 setup
- Katran 的上游用户态路径依赖 C++ + Folly + gRPC/Thrift
- 当前本地 sparse checkout 还缺少 example server 源码目录

所以“完全像 Tracee 一样”的路径是：

- **可行**
- **但不是最省工程量**

### 3.2 更现实的两种加载路径

#### 方案 A：用 Katran 自己的 loader / server

优点：

- 自动完成 VIP / real / consistent-hash ring / control maps 初始化
- 更接近真实部署
- 如果 server 进程常驻，可以直接复用 `TraceeAgentSession` 那种“按进程找 live prog fd”的思路

缺点：

- 本地 checkout 不完整
- 构建依赖重
- 需要额外解决 example/server binary 产物问题

#### 方案 B：只复用 `balancer.bpf.o`，自己写一个 minimal loader

优点：

- 只 benchmark 真正想测的 `balancer_ingress`
- 不需要完整 Katran server
- 可以直接用本仓库现有预编译 `.bpf.o`
- 更容易进 VM

缺点：

- 需要自己初始化 Katran 关键 maps
- 需要自己写 VIP / real / ring / `ctl_array` / `pckt_srcs` 配置逻辑

**我更推荐方案 B。**

原因是 benchmark 目标不是“验证 Katran 控制面是否能起”，而是：

- 用一个有论文价值的真实 XDP datapath 替换掉太弱的 `xdp_forwarding`

### 3.3 Katran XDP 程序如何加载

可以分成三层：

1. **对象加载**
   - `bpftool prog loadall ... type xdp`
2. **map 初始化**
   - 至少要写：
     - `vip_map`
     - `ch_rings`
     - `reals`
     - `ctl_array`
     - `pckt_srcs`
3. **接口 attach**
   - standalone：直接 attach 到接口
   - shared：先装 `xdp_root` 再注册到 `prog_array`

对 benchmark，建议：

- **standalone**
- **disable healthcheck**
- **只 attach `balancer_ingress`**

### 3.4 scanner enumerate 能否发现 live programs

**能。**

本仓库当前 `e2e/common/recompile.py` 已经默认优先走：

- `scanner enumerate --prog-id <id>`

所以 Katran live program discovery 有两条路：

#### 路 1：Katran server 常驻进程

可以像 Tracee 一样：

- 用 `/proc/<pid>/fdinfo`
- `bpftool prog show`
- 找到该进程持有的 prog fd

#### 路 2：没有常驻进程，只是 attach 到接口

也没问题：

- 直接 `bpftool -j prog show`
- 按 interface / program name 拿 `prog_id`
- 再喂给 `scanner enumerate --prog-id`

因此，**Katran 不需要“必须有 daemon”才可扫描**。

### 3.5 能否 recompile

**能。**

这里没有像 scx 那样的 `struct_ops` blocker：

- `balancer_ingress` 是标准 XDP program
- 当前 corpus 已经多次对它做过 VM recompile
- 说明 `BPF_PROG_JIT_RECOMPILE` 路径本身是通的

### 3.6 测什么指标

我不建议把 Katran E2E 做成“应用吞吐量”。

更合适的指标是：

1. **primary：PPS**
2. **secondary：丢包率 / peer RX 成功率**
3. **tertiary：BPF avg ns/run**

原因：

- Katran 是 L4 LB datapath，不是用户态 daemon workload
- 它的价值在于 live XDP packet processing
- 用 PPS 比延迟/应用层吞吐更直接

### 3.7 真实网络拓扑是否必须

**不必须。**

最省事的 E2E 方案其实不需要完整的“client -> router -> lb -> real”拓扑。

可以做一个更务实的单对口方案：

- 用一个 `vng --network loop` 注入的 virtio NIC pair
- LB 侧接口 attach Katran XDP
- peer 侧 namespace 负责发包
- Katran 处理后 `XDP_TX` 把封装后的包打回 peer
- 用 peer 侧 `rx_packets` / AF_PACKET counter 记接收 PPS

这不是“完整 DSR 生产拓扑”，但它满足：

- live attach
- live traffic
- live recompile
- live PPS 对比

对 E2E benchmark 已经足够 honest。

---

## 4. E2E Harness 设计建议

### 4.1 推荐目标：新增 `e2e/cases/katran/`

建议新 case 只做：

- `balancer_ingress`
- `standalone`
- `enableHc=false`

不要第一版就做：

- healthcheck
- shared mode
- `xdp_root`
- gRPC / Thrift server

### 4.2 可以复用哪些现有基础设施

可直接复用：

- `e2e/common/vm.py`
  - guest script
  - `vng --network loop`
- `e2e/common/recompile.py`
  - live `scan_programs`
  - `apply_recompile`
- `e2e/common/metrics.py`
  - `enable_bpf_stats`
  - BPF runtime 计数
- `e2e/common/agent.py`
  - 如果最终走常驻 loader / server 进程，可复用按 PID 找 prog

需要新增：

- Katran minimal loader / setup helper
- raw traffic generator / interface counter measurement
- Katran-specific policy resolution

### 4.3 建议的 harness 流程

#### 方案 B MVP（推荐）

1. 在 guest 中准备一个 `loop` NIC pair
2. root namespace 的 `eth0` 挂 Katran `balancer_ingress`
3. peer namespace 的 `eth1` 作为 traffic generator
4. minimal loader 完成：
   - load object
   - attach XDP
   - 初始化 `vip_map` / `reals` / `ch_rings`
   - 设置 `ctl_array` 的 default router MAC
   - 设置 `pckt_srcs`
5. baseline phase
   - peer namespace 用 `nping` 或自带 raw sender 连续发 VIP 包
   - 记录 peer 接口 `rx_packets` delta
6. `scanner enumerate --prog-id`
7. `BPF_PROG_JIT_RECOMPILE`
8. post-rejit phase
9. 比较：
   - peer RX PPS
   - BPF avg ns/run
   - bytes_jited

### 4.4 与现有 `xdp_forwarding` case 的差异

`xdp_forwarding` 是：

- 双腿 router 拓扑
- devmap/FIB 风格转发
- 可以直接用 `iperf3` 做 app-like UDP PPS

Katran 则是：

- 单接口 LB-on-a-stick
- XDP_TX 封装回同口
- 更适合“raw sender + peer RX counter”测法

所以 Katran case **不能简单复制** `xdp_forwarding/case.py`，但能复用其：

- VM injection
- preexisting topology
- baseline/post-rejit skeleton

### 4.5 实现工作量估算

| 任务 | 估算 |
| --- | --- |
| 读 Katran struct/map 布局，写 minimal loader | 1-2 天 |
| 做单 loop-pair live traffic harness | 0.5-1 天 |
| 接入 scanner/recompile/result schema | 0.5 天 |
| policy 修复与稳定性调参 | 0.5-1 天 |
| VM 调试与 authoritative run | 0.5-1 天 |

合计：

- **MVP：3-5 engineer-days**

如果改走“上游完整 daemon / gRPC server”路线：

- 还要加上依赖和构建问题
- **总量更像 5-8+ engineer-days**

---

## 5. 与当前 `xdp_forwarding` 的对比

| 维度 | `xdp_forwarding` | Katran `balancer_ingress` |
| --- | --- | --- |
| 程序复杂度 | 151 insns，1 map | 2322 insns，17 maps |
| live sites | 3 | 94 |
| 现有 E2E 结果 | `1.003x`，`+0.27%` | 暂无 E2E |
| 现有 corpus 信号 | 站点太少，E2E 很弱 | 当前 family geomean `0.872x` 但属 no-op；`balancer` 在可用 policy 下到过 `1.118x` |
| family 风险 | 少，几乎没东西可调 | `cmov` 明确有风险，但 `rotate/branch-flip/...` 站点丰富 |
| 部署难度 | 低 | 中高 |
| 论文价值 | 低 | 高 |

核心判断：

- `xdp_forwarding` 太像 control case，不像有优化空间的真实系统
- Katran 至少从程序规模、family 丰度、系统语义三个维度都更强

---

## 6. 替代方案

如果 Katran 最终因为实现成本过高而延期，我会这样排序：

### 6.1 Suricata XDP filter

优点：

- 真实生产系统
- XDP
- 本地已有 runnable corpus object
- 部署难度可能低于 Katran

缺点：

- 不是 forwarding / LB datapath
- 叙事上和当前 `xdp_forwarding` 不完全同类

结论：

- **如果只想换成“更真实的 XDP case”而不强求 forwarding，Suricata 是不错的 Plan B**

### 6.2 xdp-tools 的其他程序

优点：

- 最容易实现
- 可直接复用当前 `xdp_forwarding` 风格 harness

缺点：

- 仍然偏 tool / sample
- headline 价值不高

结论：

- **适合作为 control case，不适合作为替代 headline XDP E2E**

### 6.3 Calico XDP

优点：

- 真实生产 datapath

缺点：

- full agent / CNI / K8s 环境很重
- 本地 XDP 程序 site 数只有 8-12，明显弱于 Katran `balancer_ingress`

结论：

- **不比 Katran 更容易，也不比 Katran 更强**

### 6.4 Cilium

优点：

- 论文叙事价值非常高

缺点：

- 当前 corpus 路径就已经有 object-open / kfunc / tail section 问题
- 完整 live deployment 比 Katran 更重

结论：

- **短期不现实**

### 6.5 loxilb

优点：

- 也是 LB datapath

缺点：

- 当前 corpus 就有 custom section / loadability 问题

结论：

- **不比 Katran 更容易**

---

## 7. 结论与建议

### 7.1 是否推荐替换

**有条件推荐。**

但我不建议：

- 今天直接把 `xdp_forwarding` 删除

我建议：

- **先新增 `katran_balancer`**
- **等 authoritative run 稳定后，再 retire `xdp_forwarding`**

### 7.2 推荐的具体策略

#### 推荐方案

- 只做 `balancer_ingress`
- standalone attach
- healthcheck 关闭
- 自己写最小 loader
- 先从 `cmov: skip` 开始
- 优先测 PPS，而不是应用层吞吐

#### 不推荐方案

- 上来就做完整 Katran daemon / gRPC server
- 上来就做 shared mode + `xdp_root`
- 上来就把 healthcheck 也并进 benchmark

### 7.3 风险点

1. **policy 风险**
   - 当前 checked-in Katran policy 是 stale 的
   - 不修 policy，E2E 很可能测到的还是 no-op

2. **traffic generator 风险**
   - Katran 不适合 `iperf3` 这类“需要 app server”的现成 workload
   - 需要 raw sender + RX counter 方案

3. **拓扑风险**
   - Katran 是 single-interface DSR datapath
   - 不能照抄 `xdp_forwarding` 的双腿模型

4. **构建风险**
   - 如果坚持用上游 server，当前 checkout 不完整且依赖重

### 7.4 最终建议

**建议立项做 Katran E2E，但按“balancer-only MVP”推进。**

执行顺序建议是：

1. 先修 Katran corpus policy
   - 目标：live policy 可 remap
   - 默认先 `cmov: skip`
2. 做 `balancer_ingress` 的单程序 live harness
3. 在 VM 里跑 baseline / recompile 两阶段 PPS
4. 如果信号稳定且明显强于 `+0.27%`
   - 再正式替换 `xdp_forwarding`

如果只问一句话：

- **Katran 值得替换当前 `xdp_forwarding`，但应该先“新增并验证”，不应该直接“立刻替换”。**

---

## 参考资料

### 本仓库

- `CLAUDE.md`
- `docs/kernel-jit-optimization-plan.md`
- `e2e/cases/xdp_forwarding/case.py`
- `e2e/cases/tracee/case.py`
- `e2e/common/recompile.py`
- `corpus/results/corpus_recompile_authoritative_20260313.json`
- `corpus/results/archive/corpus_v5_v2_fixed_20260312.json`
- `corpus/results/archive/post_cmov_fix_corpus_ablation.json`
- `docs/tmp/2026-03-11/xdp-forwarding-live-vm-report.md`
- `docs/tmp/2026-03-10/real-world-benchmark-design.md`
- `corpus/repos/katran/README.md`
- `corpus/repos/katran/USAGE.md`
- `corpus/repos/katran/DEVELOPING.md`

### 上游

- GitHub repo: <https://github.com/facebookincubator/katran>
- README: <https://github.com/facebookincubator/katran/blob/main/README.md>
- USAGE: <https://github.com/facebookincubator/katran/blob/main/USAGE.md>
- DEVELOPING: <https://github.com/facebookincubator/katran/blob/main/DEVELOPING.md>

