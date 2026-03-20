# Katran E2E Benchmark 质量分析

日期：`2026-03-20`  
仓库：`/home/yunwei37/workspace/bpf-benchmark`

## TL;DR

- **结论 1：原始 Katran E2E harness 不达 OSDI/SOSP 级别。**
  - 它证明了 Katran datapath 可以 live attach、live recompile、live 走 DSR 路径。
  - 但它长期只测了一个很弱的单 workload，而且 headline 数字基本是 **单 worker / 单 phase / 单 program / 4 个 wide sites** 的结果，不是“Katran L4 LB”整体结果。
- **结论 2：`1.042x` 不是因为 Katran 没 site。**
  - 当前在 VM 里验证到的 live `balancer_ingress` 有 **74 个 sites**：
    - `branch-flip=56`
    - `cmov=8`
    - `wide=4`
    - `endian=4`
    - `extract=2`
  - 当前 E2E policy 只保留 **4 个 `wide-load-2`**；也就是说大部分 live site family 根本没进实验。
- **结论 3：在当前单 VM (`vng + QEMU`) 环境里，可以做“有意义但受限”的 Katran benchmark。**
  - 可以稳定做的是：**timed short-flow connection-churn**，测 `req/s`、`p99 latency`、`packet PPS`、`system CPU busy`、`BPF avg ns/run`。
  - 现在还**不能**把它包装成 production-grade Katran throughput benchmark，因为并发 `>1` worker 在当前 VM lab 里会 timeout。
- **结论 4：我已经直接改了 harness 并实际跑通。**
  - 新 harness 默认改成 **timed parallel short-flow client**，保留 same-image `stock -> recompile` 配对测量，新增 `req/s`、`p50/p99`、`packet PPS`、`CPU busy`。
  - 已落盘结果：
    - `e2e/results/dev/katran_vm_smoke_parallel1_20260320.json`
    - `e2e/results/dev/katran_vm_authoritative_like_parallel1_20260320.json`
    - `e2e/results/dev/katran_vm_authoritative_like_parallel1_rerun2_20260320.json`
- **结论 5：新 harness 比旧 harness 好很多，但 Katran 现在仍不够 paper-headline。**
  - 两组 `3-cycle` VM rerun 都显示 **BPF avg ns/run 有改善**：
    - rerun1: `1.108x`
    - rerun2: `1.168x`
  - 但 outer metric 还不够稳：
    - throughput delta: `-9.0%` / `-2.4%`
    - p99 delta: `-5.6%` / `+5.5%`
  - 所以它已经是一个 **minimal viable Katran E2E**，但还不是可以在论文里当 headline throughput case 的版本。

---

## Part 1: 质量分析

## 1. 当前 benchmark 做了什么？

这里要分两个“当前”：

1. **任务开始时仓库里的 Katran harness**  
   主要对应：
   - `e2e/results/katran_authoritative_20260319.json`
   - `e2e/results/katran_authoritative_20260320.json`
   - `docs/tmp/katran_harness_fix_20260320.md`
2. **我这次改完后的 current harness**  
   主要对应：
   - `e2e/cases/katran/case.py`
   - `e2e/results/dev/katran_vm_*_20260320.json`

### 1.1 任务开始时的 harness 在测什么

它测的是一个 **单 guest 内 synthetic DSR topology**：

- load balancer 接口：`eth0` / `katran0`
- router namespace：`katran-router`
- client namespace：`katran-client`
- real namespace：`katran-real`
- real 侧建 `ipip0` 做 decap
- VIP: `10.100.1.1:8080`
- real: `10.200.0.2`

程序加载路径不是官方 Katran userspace server，而是：

- `bpftool prog loadall corpus/build/katran/balancer.bpf.o`
- pin maps / pinned prog
- 手工写 `vip_map` / `reals` / `ch_rings` / `ctl_array`
- attach `balancer_ingress`

工作负载是：

- 从 `katran-client` 对 VIP 发 **HTTP/1.0 GET**
- real namespace 跑一个 Python `http.server`
- 通过 `ipip0` 的 `rx_packets` 验证 DSR decap 确实发生

测量方法：

- `sample_bpf_stats()` 在 phase 前后读 live program 的 `run_cnt` / `run_time_ns`
- `compute_delta()` 算 `avg_ns_per_run`
- 只测 **一个 live program**：`balancer_ingress`
- live enumerate 后立即 `BPF_PROG_JIT_RECOMPILE`
- 再测一次 post-reJIT phase

### 1.2 2026-03-19 那个 headline 结果实际上有多弱

`e2e/results/katran_authoritative_20260319.json` 的核心事实是：

- `sample_count = 1`
- `packet_repeat = 5`
- `duration_s = 10` 只是 metadata，当时并没有真正驱动 timed load
- 每 phase 只有 **5 个 HTTP request**
- 每 phase 只有 **30 个 BPF events**
- 固定顺序：**stock first, then recompile**
- 没有 repeated pairing
- 没有 order randomization
- 没有 CPU utilization
- 没有 throughput / p99 / PPS / connection rate

所以 `407.6 -> 507.0 ns` 的 `+24.4%` 后来被判定为 **harness artifact** 是对的。

### 1.3 2026-03-20 修完后的旧 harness提升了什么

`docs/tmp/katran_harness_fix_20260320.md` 对旧 harness 做了重要修正：

- phase 改成 same-image `stock -> recompile`
- 增加 warmup
- 每 phase 前清 mutable Katran maps
- `duration_s` 终于参与 measurement loop
- 支持 `sample_count > 1`
- 用 phase median 做汇总

但这个版本本质上还是：

- **单 workload**
- **单 client worker**
- **没有 outer throughput / p99 / PPS / CPU**
- 只是把“非常弱的单点测量”修成了“更像 benchmark 的单点测量”

### 1.4 我这次改完后的 harness 在测什么

我这次把 Katran case 改成了 **timed short-flow connection-churn benchmark**：

- 仍然保留 live DSR topology
- 仍然保留 same-image `stock -> recompile` pairing
- 仍然只测 `balancer_ingress`
- 但 traffic driver 改成 **timed parallel Python short-flow client**
- 每个 request 都是新连接 + `HTTP/1.0`
- 每个 phase 输出：
  - `req/s`
  - `latency p50 / p90 / p99`
  - `packet PPS`（由 `ipip0 rx_packets / duration` 得到）
  - `system CPU busy`
  - `BPF avg ns/run`

换句话说，当前 harness 测的已经不是“5 个 HTTP 探针”，而是：

- **固定 topology 上的短流连接 churn**
- **同一 live program image 的 stock/recompile 配对对比**

这已经比原始 harness 更接近 L4 LB metric 了。

---

## 2. 为什么只有 `1.042x`？

这里的 `1.042x` 指的是计划文档里保留的 2026-03-20 smoke 结果，来源于：

- `docs/tmp/katran_smoke_final_20260320.json`
- `e2e/results/katran_authoritative_20260320.json`

根因不是单一的，而是三层叠加。

### 2.1 最主要原因：policy 太窄，只打到 4 个 wide sites

当前 E2E policy 文件：

- `e2e/cases/katran/balancer_ingress.e2e.policy.yaml`

里面只有 4 条：

- `(120, wide, wide-load-2)`
- `(125, wide, wide-load-2)`
- `(266, wide, wide-load-2)`
- `(271, wide, wide-load-2)`

在当前 VM live enumerate 里，`balancer_ingress` 的 verified live site 分布是：

- `branch-flip=56`
- `cmov=8`
- `wide=4`
- `endian=4`
- `extract=2`
- total `74`

也就是说：

- **应用的 site = 4**
- **未应用但 live 存在的 site = 70**

所以 `1.042x` 只是在回答：

- “4 个 `wide-load-2` site 在这个 lab path 上大概带来多少 BPF-side gain？”

它**没有**回答：

- “BpfReJIT 对 Katran 这个 L4 LB 整体能带来多少 gain？”

### 2.2 benchmark path 本身也弱

即使先不看 policy，原始 Katran harness 也是一个非常弱的 datapath stress：

- 单 VIP
- 单 real
- 单 workload
- 单 client
- 无并发或极低并发
- client 和 LB 和 real 都在同一 guest
- HTTP Python server / client 开销很大

这意味着 outer throughput 很容易被：

- Python userspace
- namespace TCP stack
- guest CPU sharing

这些因素淹没。

### 2.3 不是因为 Katran “site 少”

这点要明确：

- **Katran 不是 site 少**
- 当前 verified live program 是 **74 sites**
- 而且绝大头是 `branch-flip=56`

所以 Katran 不是 `xdp_forwarding` 那种 “3 sites, 结构上没什么可测”的 case。

### 2.4 也不完全是 harness bug

2026-03-19 那个 `+24.4%` regression 主要是 harness bug。  
但 `1.042x` 这个小 gain 并不主要说明 harness 还有 bug。

它更说明：

1. 当前 policy 只打了 4 个 wide sites
2. 当前 path 只是一个弱短流 lab path
3. outer metric 还没真正进入 benchmark headline

所以 `1.042x` 更像：

- **policy coverage 太低 + workload 太弱 + metric 太窄**

而不是：

- Katran 本身不值得做

---

## 3. 与 OSDI/SOSP E2E evaluation 标准的差距

## 3.1 Tracee/Tetragon 做到了什么

### Tracee harness

当前 `tracee` case 具备：

- daemon mode
- `duration_s = 60`
- 多 workload：
  - `exec_storm`
  - `file_io`
  - `network`
- outer metric：
  - app throughput
  - events/s
  - drop counters
  - agent CPU
  - system CPU
  - BPF avg ns/run
- compare output 是 per-workload 的

### Tetragon harness

当前 `tetragon` case 具备：

- daemon mode
- `duration_s = 30`
- 多 workload：
  - `stress_exec`
  - `file_io`
  - `open_storm`
  - `connect_storm`
- outer metric：
  - app throughput
  - events/s
  - agent CPU
  - system CPU
  - per-program summary
  - BPF avg ns/run

所以 Tracee/Tetragon 至少已经接近：

- “一个 agent 在固定 workload set 下，对外部 workload throughput / CPU / BPF time 的影响”

## 3.2 Katran 原始 harness 缺什么

原始 Katran case 的缺口非常具体：

1. **没有 workload family**
   - 只有一个 HTTP correctness-style path
   - 没有 short-flow / long-flow / throughput / conn-rate 区分

2. **没有 outer throughput headline**
   - 没有 `req/s`
   - 没有 `conn/s`
   - 没有 `PPS`

3. **没有 latency distribution**
   - 没有 `p50`
   - 没有 `p99`

4. **没有 CPU utilization**
   - 没有 system CPU
   - 没有 generator / server / LB CPU 分解

5. **没有 scaling story**
   - 没有不同 concurrency
   - 没有多 real
   - 没有多 queue / 多 CPU

6. **控制面不真实**
   - 不是官方 Katran server loader
   - 是 direct map emulation

7. **网络实验设计还太 lab**
   - client / LB / real 在同一 guest
   - generator 争用 guest CPU

## 3.3 一个真正的 L4 LB benchmark 应该测什么

至少应分成两类：

### A. 短流 / connection churn

- `conn/s`
- `req/s`
- `latency p50 / p99`
- timeout / error rate
- CPU utilization
- packet PPS

### B. 稳态 forwarding / bulk throughput

- `PPS`
- `Gbps`
- tail latency
- CPU busy / cycles per packet
- 随 concurrency / queue / real 数量的 scaling curve

### C. 对 Katran 还特别重要的

- DSR correctness
- per-real distribution / fairness
- VIP / real map state reset
- connection cache / LRU 行为
- 多 real / hashing path

当前 Katran harness 只有：

- 单 VIP / 单 real
- bypass LRU
- 单 short-flow path

所以离真正的 Katran LB evaluation 还有明显差距。

---

## 4. Site 分析

## 4.1 raw object scan

命令：

```bash
scanner/build/bpf-jit-scanner scan corpus/build/katran/balancer.bpf.o \
  --program-name balancer_ingress --all --json
```

当前 raw object 结果是：

- total `18`
- `wide=4`
- `cmov=8`
- `extract=2`
- `endian=4`
- `branch-flip=0`
- `rotate=0`

这说明 raw object 本身并不等于 live xlated reality。

## 4.2 verified live VM enumerate

基于这次 actual VM run：

- `e2e/results/dev/katran_vm_smoke_parallel1_20260320.json`
- `e2e/results/dev/katran_vm_authoritative_like_parallel1_20260320.json`

当前 verified live enumerate record 是：

- total `74`
- `branch-flip=56`
- `cmov=8`
- `wide=4`
- `endian=4`
- `extract=2`
- `rotate=0`

这也是本报告采用的 **ground truth**。

## 4.3 为什么不是之前文档里的 94？

历史文档里曾多次出现：

- total `94`
- `rotate=20`
- `branch-flip=56`

这在 2026-03-20 当前 verified VM run 里 **没有复现**。  
当前能稳定复现的是 **74-site** 版本。

因此我建议：

- 论文和计划文档里如果要写 Katran live site 数，**应以当前 verified VM enumerate 的 74 为准**
- 旧 `94` 应保留为历史 artifact，而不是当前权威数字

## 4.4 当前 policy 跳过了哪些

当前 E2E policy 只保留：

- `wide=4`

当前 live enumerate 被跳过的是：

- `branch-flip=56`
- `cmov=8`
- `endian=4`
- `extract=2`

也就是说：

- kept `4 / 74`
- skipped `70 / 74`

示例 skipped sites：

- `(15, branch-flip, branch-flip)`
- `(381, endian, endian-load-swap-32)`
- `(422, cmov, cond-select-64)`
- `(1554, extract, bitfield-extract-64-mask-shift)`

结论非常直接：

- 当前 Katran E2E 结果本质上是 **“4 个 wide site 的 effect size”**
- 不是 “Katran balancer_ingress 全程序”的 effect size

---

## 5. 可行性评估：当前 VM 里能不能做有意义的 Katran benchmark？

## 5.1 能做什么

在当前 `vng + QEMU` 单 VM 里，**可以**做一个有意义的最小方案：

- live attached Katran datapath
- same-image stock/recompile pairing
- timed short-flow connection churn
- `req/s`
- `p99 latency`
- `packet PPS`
- `system CPU busy`
- `BPF avg ns/run`

也就是我这次已经实现并跑通的版本。

## 5.2 不能做什么

当前环境下，我**不认为**已经能做出真正 paper-headline 的 Katran throughput benchmark，原因是：

1. **并发 >1 worker 当前会 timeout**
   - `2026-03-20` VM smoke with concurrency `4` 失败
   - 所以现在没有可用的并发 scaling story

2. **generator 和 datapath 共用 guest CPU**
   - outer throughput 被 guest userspace 污染

3. **没有外部 packet generator**
   - 现在没有 host-side / second-VM generator

4. **没有官方 Katran control plane**
   - 还是 direct-map emulation

5. **只有单 real**
   - 没有真实 LB distribution / fairness / hashing pressure

## 5.3 真正想做 production-grade Katran benchmark，需要什么

至少需要：

- guest 外部 traffic generator
  - host-side `wrk` / `iperf3`
  - 或 second VM
  - 或 packet generator (`pktgen`, TRex, MoonGen)
- LB / generator / real 更清晰的 CPU 隔离
- 多 real
- concurrency sweep
- official Katran userspace loader
- 更真实的 DSR return path

## 5.4 最小可行方案

因此我建议当前环境里的结论是：

- **可以**把 Katran case 升级成一个 **minimal viable short-flow L4 LB benchmark**
- **不应该**在当前环境里宣称我们已经有 production-grade Katran throughput benchmark

---

## Part 2: 直接实施的改进

## 6. 这次我实际改了什么

代码修改：

- `e2e/cases/katran/case.py`
- `e2e/run.py`

实际改动：

1. **新增 timed parallel short-flow client**
   - 默认 traffic driver 改成内建 Python 并发 client
   - 每个 request 都是新连接
   - duration-based

2. **新增 outer metrics**
   - `req/s`
   - `latency p50 / p90 / p99`
   - `packet PPS`
   - `system CPU busy`

3. **保留 same-image pairing**
   - 每 cycle 仍然是：
     - baseline
     - live recompile
     - post-reJIT

4. **保持 mutable-state reset**
   - phase 前仍 reset Katran mutable maps

5. **修了 topology 幂等性 bug**
   - `eth0` 地址设置从 `ip addr add` 改成 `ip addr replace`
   - 否则 repeated VM run 会遇到 `Address already assigned`

6. **把旧“batch count”语义改成 concurrency 语义**
   - 当前对 Katran 更合理的是 client concurrency，而不是 request batch size

## 7. 实际验证结果

## 7.1 Smoke

文件：

- `e2e/results/dev/katran_vm_smoke_parallel1_20260320.json`

配置：

- `duration=3s`
- `sample_count=1`
- `client_concurrency=1`

结果：

- baseline: `47.22 req/s`, `27.12 ms p99`, `283.32 PPS`, `263.09 ns BPF`
- post: `47.77 req/s`, `27.44 ms p99`, `286.62 PPS`, `334.66 ns BPF`

这个 smoke 只说明：

- 新 driver 在 VM 里能跑通并产出 outer metric

## 7.2 Authoritative-like rerun #1

文件：

- `e2e/results/dev/katran_vm_authoritative_like_parallel1_20260320.json`

配置：

- `duration=5s`
- `sample_count=3`
- `client_concurrency=1`

phase median：

- baseline:
  - `51.56 req/s`
  - `29.52 ms p99`
  - `309.36 PPS`
  - `344.32 ns BPF`
- post:
  - `46.92 req/s`
  - `27.86 ms p99`
  - `281.53 PPS`
  - `310.89 ns BPF`

comparison：

- throughput: `-8.997%`
- p99: `-5.637%`
- packet PPS: `-8.997%`
- BPF avg ns/run: `-9.708%`
- BPF speedup: `1.108x`

## 7.3 Authoritative-like rerun #2

文件：

- `e2e/results/dev/katran_vm_authoritative_like_parallel1_rerun2_20260320.json`

phase median：

- baseline:
  - `47.89 req/s`
  - `28.33 ms p99`
  - `287.36 PPS`
  - `410.36 ns BPF`
- post:
  - `46.74 req/s`
  - `29.90 ms p99`
  - `280.43 PPS`
  - `351.40 ns BPF`

comparison：

- throughput: `-2.409%`
- p99: `+5.521%`
- packet PPS: `-2.409%`
- BPF avg ns/run: `-14.370%`
- BPF speedup: `1.168x`

## 7.4 结果 interpretation

这两组 rerun 说明了三件事：

1. **BPF-side gain 是存在的**
   - 两组 rerun 都显示 BPF avg ns/run 改善
   - `1.108x` / `1.168x`

2. **outer throughput 还不够稳**
   - 两组都略负
   - `-9.0%` / `-2.4%`

3. **p99 还不够可重复**
   - 一组改善
   - 一组变差

因此当前 Katran case 的最合理定位是：

- **可以作为“minimal viable Katran E2E”**
- **不能作为论文 headline throughput result**

---

## 8. 最终建议

### 对论文叙事

当前更安全的说法是：

- Katran E2E 现在已经从“几乎 correctness harness”提升到了“可测 short-flow connection-churn”的最小版本
- 但在当前单 VM lab 里，它还不能像真正 LB benchmark 那样给出稳健的 throughput scaling 结论

### 对下一步工程

如果还要继续把 Katran 做成 headline case，优先级应是：

1. 把 generator 移到 guest 外
2. 让并发 `>1` 稳定
3. 加 second real 或 multi-real
4. 视条件切回官方 Katran loader
5. 再讨论 long-flow / bulk throughput

### 当前可用结论

截至 `2026-03-20`：

- Katran **不是** “site 太少所以没价值”
- 当前 verified live `balancer_ingress` 是 **74 sites**
- 当前 policy 只用了 **4 个 wide sites**
- 新 harness 已经能稳定测到 **single-worker short-flow connection-churn**
- 但要把它升到 OSDI/SOSP headline 级别，还需要 **更真实的拓扑和外部 traffic generator**
