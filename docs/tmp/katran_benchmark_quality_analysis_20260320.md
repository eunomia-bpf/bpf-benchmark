# Katran E2E Benchmark 质量与性能瓶颈深度分析

日期：2026-03-20
分析对象：`e2e/cases/katran/case.py` + 最新权威数据 `e2e/results/katran_authoritative_20260320.json`

---

## 摘要

Katran `balancer_ingress`（2322 BPF insns, Meta 生产级 XDP L4 负载均衡器）当前 E2E benchmark 显示 BPF avg ns 改进仅 **~8.2%**（346.75 → 318.48 ns），但这个数据建立在 **sample_count=1 的 smoke-grade 测量** 之上，不具备统计显著性。更关键的问题是：**74 个 live scanner sites 中只有 4 个被 applied**（全部是 wide-load-2），policy 层面过滤掉了 70 个潜在优化站点。

本报告从 SOSP/OSDI 评审标准、性能瓶颈根因分解、测量方法学三个维度进行分析，给出优先级排序的改进方案。

---

## 1. SOSP/OSDI 标准差距分析

### 1.1 顶会 load balancer benchmark 的典型做法

文献中 XDP load balancer 的 benchmark 通常包含以下维度：

| 维度 | SOSP/OSDI 惯例 | 当前 Katran E2E | 差距 |
|------|-----------------|-----------------|------|
| **吞吐量指标** | PPS (Mpps/Gbps)，通常用专用 packet generator (pktgen/MoonGen/TRex/DPDK) | HTTP request latency + BPF `run_time_ns` | 严重不足 — 没有真正的 PPS throughput 指标 |
| **延迟指标** | p50/p95/p99/p999 percentile breakdown | 只有 mean/median/min/max | 缺少 tail latency 分析 |
| **流量规模** | 连续发包 10-60s，≥10M packets per measurement | 200-250 HTTP requests per phase（约 1200-1500 BPF events） | 差 3-4 个数量级 |
| **连接复杂度** | 多 VIP、多 real、LRU miss/hit 比例控制、varying flow count | 1 VIP、1 real、F_LRU_BYPASS（跳过连接表） | 极度简化 |
| **拓扑** | 多 NIC、RSS 队列、多核 scaling | 单 veth pair → router → client/real namespaces | 简单但可接受（VM 限制） |
| **样本数** | ≥5 runs × bootstrap/CI | sample_count=1 (smoke), sample_count=3 (full, 但跑不通) | 严重不足 |
| **对照** | A/B test across kernel versions / config variants | same-image stock→recompile paired | 方向正确，但只有 1 对 |
| **误差分析** | 标准差、置信区间、变异系数 | 只有单个 summary statistic（因为 sample_count=1） | 不可能有置信区间 |

### 1.2 当前指标体系的核心缺陷

**缺陷 1：HTTP 延迟 ≠ XDP 性能**

当前 workload 是从 client namespace 发 HTTP GET 到 real namespace 的 Python `http.server`。路径是：
```
client → router → Katran XDP (IPIP encap + XDP_TX) → router → real (ipip decap) → HTTP server → reverse
```

HTTP 延迟包含了 Python HTTP server 处理、TCP stack、route lookup、IPIP decap 等大量非 BPF 开销。BPF 每次执行仅 ~300ns，但 HTTP latency 是 ~7-10ms — 即 BPF 占 HTTP 延迟的 **<0.005%**。一个 ~30ns 的 BPF 改进在 HTTP latency 上基本不可见。

当前结果中 HTTP median latency 从 10.04ms → 7.64ms 降低了 24%，但这几乎不可能是 BPF 优化导致的（BPF 改进只有 ~28ns/packet）。这个 HTTP latency 变化更可能来自 warmup 状态差异（baseline 有明显的 cold-start 长尾，前 20 个请求 >14ms）。

**缺陷 2：BPF events 太少**

200-250 HTTP requests 产生 1200-1500 BPF events（每个 HTTP request 约 6 个 XDP events：SYN/SYN-ACK/ACK + data + FIN 等）。`bpf_prog_get_info_by_fd` 返回的 `run_time_ns` 是 **ktime 精度**（ns 级），但聚合时 `avg_ns_per_run = total_time / total_events`。1200 events 下每 event 仅 ~347ns，总 run_time ~416us — 这接近 ktime 的可测量下限。

作为对比，Tracee E2E 每个 workload 产生 >50000 BPF events。Tetragon stress_exec 产生 >100000 events。Katran 1200 events 差了 1-2 个数量级。

**缺陷 3：F_LRU_BYPASS 跳过了核心热路径**

当前 VIP 配置使用 `flags = F_LRU_BYPASS = 2`，这意味着 `balancer_ingress` 在处理该 VIP 的流量时：
- **跳过 LRU connection table lookup** (`lru_mapping`)
- **跳过 connection 缓存/miss 处理**
- 每个包直接走 **consistent hash ring → real lookup → IPIP encap** 的短路径

这导致执行路径**缺少**了 Katran 最耗时的部分：LRU hash lookup/update、连接追踪、fallback cache。balancer_ingress 中许多 optimization sites 位于 LRU 处理、server ID lookup、GUE encap 等路径中，F_LRU_BYPASS 模式可能完全不执行这些代码段。

### 1.3 与其他 E2E case 的对比

| Case | Programs | Applied sites | BPF events/phase | HTTP/app requests | PPS/throughput | 论文可用性 |
|------|----------|--------------|-------------------|-------------------|----------------|-----------|
| **Tracee** | 13 progs, 11 applied | ~100+ sites | >50K events | 1000+ exec storms | throughput 指标 | 已发表数据 |
| **Tetragon** | 7 progs, 3 applied | 49 bflip sites | >100K events | stress_exec 10s burst | throughput 指标 | 已发表数据 |
| **Katran** | 1 prog, 1 applied (4 wide) | 4 applied/74 live | 1200 events | 200 HTTP | 无 PPS | 不可用 |

结论：**当前 Katran benchmark 达不到 SOSP/OSDI 的最低标准**。核心问题不是拓扑太简单（那是 VM 环境固有限制，可以接受），而是 (1) 没有 throughput 指标 (2) 流量太少 (3) policy 太保守。

---

## 2. 性能弱的根因分解

### 2.1 整体数据

| 指标 | 值 | 来源 |
|------|-----|------|
| BPF avg_ns baseline | 346.75 ns | `e2e/results/katran_authoritative_20260320.json` |
| BPF avg_ns post-reJIT | 318.48 ns | 同上 |
| BPF delta | -8.15% | 同上 |
| BPF speedup ratio | 1.089x | 同上 |
| bytes_jited baseline | 13412 B | 同上 |
| bytes_jited post | 13364 B (-48B, -0.36%) | 同上 |
| Live scanner sites | 74 | 同上（scan_results: total_sites=74） |
| Applied sites | 4 (wide-load-2) | 同上（recompile_results: applied_sites=4） |
| Sample count | 1 | smoke run |
| BPF events per phase | 1200 (baseline), 1500 (post) | 同上 |

注意：scan_results 显示 74 个 sites（之前报告的 94 个可能来自不同版本的 scanner）。按 live family 分布：

| Family | Live sites | Applied | 被跳过 |
|--------|-----------|---------|--------|
| branch-flip | 56 | 0 | 56 (全局 skip) |
| cmov | 8 | 0 | 8 (全局 skip) |
| wide | 4 | **4** | 0 |
| endian | 4 | 0 | 4 (不在 E2E policy 中) |
| extract | 2 | 0 | 2 (全局 skip) |
| **合计** | **74** | **4** | **70** |

### 2.2 根因因素分解

#### 因素 A：Policy 过滤损耗（74 → 4 sites, 94.6% 被丢弃）

**E2E policy** (`e2e/cases/katran/balancer_ingress.e2e.policy.yaml`) 极其保守：
- 只包含 4 个 `wide-load-2` sites (insn 120, 125, 266, 271)
- 完全排除了 branch-flip (56)、cmov (8)、endian (4)、extract (2)

**Corpus policy** (`corpus/policies/katran/balancer/balancer_ingress.policy.yaml`) 略宽，包含 wide=4 + endian=4 = 8 sites。

被排除的各 family 价值分析：

| Family | 被排除数 | 在 Katran 上的已知效果 | 值得开启? |
|--------|---------|----------------------|----------|
| **branch-flip** | 56 | 无 Katran 专项数据。micro benchmark 无此 form。理论上依赖 workload 的分支可预测性 | 高风险高回报 — 56 sites 是最大来源，但 branch-flip 是 policy-sensitive directive，盲开可能导致回归 |
| **cmov** | 8 | **已确认负面** — CMOV ablation 中 `balancer_ingress` 仅 0.187x，严重回归 | 明确不开 |
| **endian** | 4 | Corpus 数据显示 same-size 重编（MOVBE = LDX+BSWAP32 相同体积）的 I-cache flush 开销 > 微架构收益 | 低价值，但 corpus policy 已包含 |
| **extract** | 2 | 全局 skip（BEXTR 在某些工作负载下有回归） | 低价值 |

**关键发现**：真正有大量未开发潜力的是 **branch-flip 的 56 个 sites**。这些 sites 遍布 balancer_ingress 全程序（从 insn 15 到 insn 2734），覆盖了解析、lookup、encap 各阶段。但 branch-flip 是 policy-sensitive directive（哪个分支 body 先走取决于运行时数据分布），盲开风险很大。

**估算**：如果假设 4 个 wide sites 贡献了当前的 ~28ns 改进（每 site ~7ns），那 70 个额外 sites（假设平均价值相当）理论上可以贡献 ~490ns 改进 — 但这个估算不可靠，因为不同 family 的价值差异巨大，且 branch-flip/cmov 可能是负面的。

#### 因素 B：Applied sites 在 hotpath 中的覆盖率

4 个 wide-load-2 sites 位于 insn 120/125 和 266/271。在 2322 insns 中，这些位于程序开头约 5-12% 的位置，对应的是**以太网/IP header 解析阶段**的 byte-recompose pattern。

Katran `balancer_ingress` 的执行路径（简化）：
1. **[insn 0-150]** 以太网 + IP header 解析 ← wide sites 120/125 在这里
2. **[insn 150-300]** VIP lookup (`vip_map`) ← wide sites 266/271 在这里
3. **[insn 300-800]** 连接表 lookup / consistent hash
4. **[insn 800-1500]** Real selection / stats update
5. **[insn 1500-2322]** IPIP/GUE 封装 + XDP_TX

wide sites 覆盖的是**解析阶段**，这是每个包都会执行的冷路径前缀。但解析阶段本身的计算量很小（只是 load 几个 header 字段），wide-load-2 的改进（将 2 个连续 byte-load 合并为一个 wide load）在纯计算层面的收益有限。

真正耗时的热路径（步骤 3-5：hash、lookup、encap）中的 optimization sites 几乎全是 branch-flip 和 cmov — 这些恰恰被 policy skip 了。

#### 因素 C：Workload coverage — 当前流量模式是否覆盖了主热路径？

当前 workload 是 **HTTP GET over TCP to VIP**。数据从 JSON 中确认：
- `ipip_rx_packets_delta = 1200/1500` — 说明 IPIP encap 路径确实被执行了
- `F_LRU_BYPASS = 2` — 跳过 LRU，走 consistent hash 直通路径
- 只有 1 个 VIP + 1 个 real

这意味着：
- **DSR encap 路径确实被触发**（IPIP decap 在 real 端有 rx_packets 增长）
- **但 LRU/connection tracking 被 bypass** — 这是 production 最耗时的部分
- **Consistent hash ring 被执行**，但只有 1 个 real，ring 中 65537 个 entry 全部指向同一个 real — 没有 hash 冲突或 miss

**结论**：workload 覆盖了 balancer_ingress 的主路径（VIP match → CH → real → IPIP encap → XDP_TX），但**跳过了 LRU connection tracking 这个最重的子路径**。优化 sites 是否在被执行的路径上取决于具体 insn 位置，但 F_LRU_BYPASS 确实跳过了大量分支路径（其中包含许多 branch-flip sites）。

#### 因素 D：测量精度

从权威 JSON 中提取的方差分析：

**Baseline phase (stock)**：
- BPF: 1200 events, 416101ns total → 346.75 ns/run
- HTTP latencies (200 requests): mean=10.67ms, median=10.04ms, min=6.47ms, max=23.35ms
- 前 20 个请求明显偏高（15-23ms），后面稳定在 7-12ms — **典型 cold-start warmup 未完全剥离**

**Post-reJIT phase (recompile)**：
- BPF: 1500 events, 477725ns total → 318.48 ns/run
- HTTP latencies (250 requests): mean=8.22ms, median=7.64ms, min=6.10ms, max=17.68ms
- 请求更均匀，cold-start tail 更小 — **可能受益于 baseline phase 留下的 cache/state warmth**

**核心问题**：
1. **events 数不对等**：baseline 1200 events vs post 1500 events（post phase 更多 batches）
2. **只有 1 个 paired cycle** — 无法计算任何置信区间
3. **BPF total runtime 差异**：416101ns vs 477725ns — post 的总时间反而更高（因为更多 events），只是 per-event 更低
4. **ktime 精度问题**：在 ~300ns/event 的尺度下，ktime 的量化误差（~几 ns）被 1200-1500 events 平均后可接受，但 **系统性偏差**（第一次执行 vs 第二次执行的 I-cache 状态差异）无法通过增加 events 消除 — 只能通过多轮 paired cycling 或 A/B/A 设计来控制

---

## 3. 可执行的改进方案（按优先级排序）

### P0：增加流量规模和 BPF event 数（1-2 天）

当前瓶颈：200-250 HTTP requests → 1200-1500 BPF events

**改进方案**：
1. 将 `DEFAULT_PACKET_REPEAT` 从 25 提高到 200-500
2. 将 `DEFAULT_DURATION_S` 从 10 提高到 30
3. 将 `DEFAULT_MIN_MEASUREMENT_REQUESTS` 从 1000 提高到 10000
4. 目标：每个 phase 产生 **>50000 BPF events**

这不需要改拓扑或 workload 模式，只需调参数。HTTP 请求依赖 Python http.server，单线程串行处理，250 requests 已经要 3s — 要达到 10K requests 需要 ~120s。可以考虑：
- 换成更快的 HTTP server（netcat 循环或自定义 TCP echo）
- 或放弃 HTTP 走 raw UDP（见 P1）

### P1：添加 PPS throughput 指标（2-3 天）

当前完全没有 PPS 指标。方案：

**方案 A（推荐）：raw packet generator + interface counter**

不走 HTTP，直接在 client namespace 用 `nping` / `hping3` / 自定义 raw sender 对 VIP:8080 发 TCP SYN flood 或 UDP flood：
```bash
# 在 client namespace 中：
ip netns exec katran-client hping3 --flood -S -p 8080 10.100.1.1
```
用 `ip -s link show` 的 rx_packets delta 计算 PPS。

优点：
- 脱离 HTTP stack 的瓶颈
- 可以产生百万级 BPF events
- PPS 是 load balancer 的核心指标

缺点：
- TCP SYN flood 不走完整的 Katran datapath（没有 established connection）
- 需要验证 Katran 对 SYN 包的处理路径也经过 optimization sites

**方案 B：BPF_PROG_TEST_RUN**

Katran 上游 `katran_tester` 使用 `bpf_prog_test_run` 做 perf testing。可以在当前 harness 之外添加一个 `bpf_prog_test_run`-based 的 PPS 测量作为补充：
- 优点：高度受控，可以精确控制 packet content
- 缺点：不是 "live traffic" — 审稿人可能质疑 end-to-end 属性

### P2：Policy 调优 — 开启 endian 和 selective branch-flip（1-2 天）

当前 E2E policy 只有 4 wide sites。改进路径：

**第一步**：将 E2E policy 与 corpus policy 对齐，加入 endian=4 → 共 8 sites
- 这是低风险操作，corpus policy 已经包含这 4 个 endian sites
- 从 `corpus/policies/katran/balancer/balancer_ingress.policy.yaml` 复制 endian entries 到 E2E policy

**第二步**：尝试 selective branch-flip
- branch-flip 有 56 个 sites，但它是 policy-sensitive — 不能全部盲开
- 方案：选择 **header 解析阶段**（insn <400）的 branch-flip sites 先开启，这些位于快路径且分支方向通常确定性高（e.g., "if IPv4 → ..." 或 "if TCP → ..."）
- 从 scan results 看，insn 15, 370 在解析阶段 — 可以先试这 2 个
- 然后逐步添加 encap 路径的 branch-flip

**绝对不做**：开启 cmov（已确认在 Katran 上 0.187x）

### P3：关闭 F_LRU_BYPASS 以覆盖完整热路径（1 天）

当前 `F_LRU_BYPASS = 2` 导致 LRU connection table 整个被跳过。改为 `flags = 0`：

```python
# case.py 中 configure_katran_maps():
VIP_FLAGS = 0  # 而不是 F_LRU_BYPASS = 2
```

这会让 balancer_ingress 执行完整路径：
1. 第一个 SYN 包：VIP match → LRU miss → consistent hash → create LRU entry → real → encap
2. 后续包：VIP match → LRU hit → real → encap

好处：
- 更接近生产行为
- 覆盖更多 code path（更多 branch-flip sites 被执行）
- BPF 执行时间可能从 ~300ns 增加到 ~500-1000ns — 更容易测量差异

风险：
- LRU map 状态管理变复杂
- state reset 需要覆盖 `lru_mapping`（当前跳过了因为 bypass 模式下无数据）

### P4：增加 paired cycles 到 ≥5（1 天，但依赖 VM 稳定性修复）

当前 full run (sample_count=3) 在 VM 中因 HTTP timeout 跑不通。原因是 sustained Katran traffic 在 VM guest 中不稳定。

Workaround 方案：
1. 在每个 cycle 之间加 `time.sleep(2)` 让 guest 恢复
2. 降低每个 cycle 的 request batch size（牺牲 events 换取稳定性）
3. 用 `--timeout` 增大 HTTP timeout（从 3s → 10s）
4. 最激进方案：改为多次 VM boot，每次只跑 1 cycle — 用 `make vm-e2e` 跑 5 次然后 aggregate

### P5：增加 VIP/real 复杂度（2-3 天）

添加多个 VIP 和 real 以增加 consistent hash 的多样性：
- 3-5 个 VIP，每个 2-4 个 real
- 不同的 LRU mode（some bypass, some full）
- 这样 different packets hit different code paths → 更好的 site 覆盖

---

## 4. 结论：这个 benchmark 值不值得继续做？

### 值得继续做的理由

1. **program 复杂度不可替代**：2322 insns、14 maps、74 live sites — 这是当前项目中除 Cilium 外最复杂的 XDP datapath，远超 xdp_forwarding (151 insns, 3 sites)
2. **论文叙事价值高**：Meta production LB，reviewer 一看名字就知道是真实系统
3. **harness 基础已具备**：DSR topology、map 初始化、state reset、paired measurement、recompile 路径全部已打通，功能正确
4. **当前 ~8% BPF 改进是正向信号**：即使只有 4 wide sites，也已经测到了正向改进，方向正确
5. **改进空间大**：70 个被 skip 的 sites（其中 56 branch-flip + 4 endian）是巨大的未开发资源

### 不值得做的场景

1. 如果 VM HTTP timeout 问题无法解决且不愿意切换到 raw packet generator — 那 sample_count 永远只能是 1，数据永远没有统计显著性
2. 如果 branch-flip 在 Katran 上整体是负面的（需要实测验证） — 那 56 个 sites 的价值为零，只剩 4 wide + 4 endian = 8 sites，对 2322 insns 的程序来说覆盖率太低

### 最终建议

**保留 Katran E2E benchmark，但当前数据不能用于论文。** 按以下优先级执行改进：

1. **立即**（P0）：调大测量参数（`packet_repeat`, `duration_s`, `min_measurement_requests`），至少让每个 phase 有 >10K BPF events
2. **短期**（P2）：将 E2E policy 扩展到 wide=4 + endian=4 = 8 sites（与 corpus policy 对齐），然后尝试 2-5 个保守的 branch-flip sites
3. **短期**（P3）：关闭 `F_LRU_BYPASS`，覆盖 LRU 热路径
4. **中期**（P1）：添加 raw packet generator + PPS 指标，脱离 HTTP stack 瓶颈
5. **中期**（P4）：修复 VM 稳定性或采用多次 boot 的 workaround，达到 ≥5 paired cycles

如果 P0+P2+P3 执行后 BPF speedup 能达到 **>1.05x** 且有 ≥3 paired cycles 的统计支持，Katran 数据就可以进论文。如果 P0-P3 全做了还是 ~4% 且方差大 — 建议在论文中把 Katran 定位为 **functional deployment proof**（"可以在 production 级 XDP LB 上成功 recompile"），不作为主要性能数据。

### 与其他 E2E case 的优先级对比

| Case | 当前论文可用性 | 改进潜力 | 建议 |
|------|---------------|---------|------|
| Tracee | 可用（+6-7%） | 有限 | 保持 |
| Tetragon | 可用（+8-22%） | 有限 | 保持 |
| Katran | **不可用** | **高** — 74 sites, policy 未调优 | **优先改进** |
| bpftrace | 不可用（0 applied） | 无 — 纯 cmov sites 被 skip | 放弃或重新定位 |

**综合判断：Katran 是当前最值得投入改进的 E2E case。** 不是因为它已经好，而是因为它的改进空间最大，且改进方向明确。

---

## 附录：关键数据来源

| 文件 | 用途 |
|------|------|
| `e2e/results/katran_authoritative_20260320.json` | 最新权威结果（smoke, 1 cycle） |
| `e2e/cases/katran/case.py` | harness 源码 |
| `e2e/cases/katran/balancer_ingress.e2e.policy.yaml` | E2E policy (wide=4 only) |
| `corpus/policies/katran/balancer/balancer_ingress.policy.yaml` | Corpus policy (wide=4 + endian=4) |
| `docs/tmp/katran_harness_fix_20260320.md` | Harness 修复报告 |
| `docs/tmp/katran_regression_investigation_20260320.md` | 回归调查报告 |
| `docs/tmp/katran_e2e_feasibility_20260318.md` | 可行性调研报告 |
| `docs/tmp/katran_smoke_final_20260320.json` | Smoke run 原始数据 |
