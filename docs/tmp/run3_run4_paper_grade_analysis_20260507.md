# Run 3 + Run 4 Paper-Grade 详细分析（含推理过程）

日期：2026-05-07
作者：Claude (dispatcher) + 用户 review
源数据：
- Run 3 noop+map_inline 7-app SAMPLES=3 → `corpus/results/x86_kvm_corpus_20260507_072543_601953`
- Run 4 kinsn-only 7-app SAMPLES=3 → `corpus/results/x86_kvm_corpus_20260507_081532_470100`
- 全 295 个 prog 的明细表 → `docs/tmp/run3_run4_detailed_20260507.txt`

## TL;DR — 修正前的粗结论 → 修正后的严谨结论

| 之前我说的 | 修正版 |
|-----------|------|
| "Run 3 wins 主要来自 tracee tail-call 子 prog" | tracee 那 8 个不是 tail-call 子 prog（run_cnt 全部 > 0，prologue 已计数）；它们是 kretprobe，**ratio 由 workload phase 间的 I/O 工作量主导** |
| "KVM 噪声" | 表述不准。**主要来源是 workload phase variance**——baseline 和 post-rejit phase 跑的 syscall/IO pattern 不一致，per-prog avg_ns 被工作量主导。CPU jitter 是次要因素 |
| Method B 0.8965 = ~10% 加速 | 误导。Run 3 applied-only Method C 实际 **+3.2% slowdown**；Run 4 applied-only Method C **+0.1% 加速**（基本持平） |

**底线判断**：1898 个 kinsn site（Run 4）和 171 个 map_inline site（Run 3）都没有产生 run-weighted 的正面信号。Method C applied-only 在两次 run 都接近 1.0，浮动幅度小于 same-prog 跨 run 的 phase variance（vfs_create 同程序 applied=0 在 Run 3 是 2.232x、Run 4 是 0.388x）。要拿 paper-grade 数字必须先跑 noop-only baseline 标定噪声楼层。

---

## 推理证据链

### 证据 1：vfs_create 同程序 applied=0 跨 run 比值倒挂 5.7×

| Run | app/prog | min_runs | baseline ns | post ns | ratio | applied |
|-----|----------|----------|-------------|---------|-------|---------|
| 3 | bcc/vfs_create | 3.16 M | 82.8 | 184.8 | **2.232×（慢）** | 0 |
| 4 | bcc/vfs_create | 3.27 M | 172.9 | 67.0 | **0.388×（快）** | 0 |

**两次都 applied=0**——bpfopt 没修改任何字节码，baseline 和 post 的程序文本完全相同。但 baseline avg 一次 82.8 ns 一次 172.9 ns（2× 跨 run 漂移），post avg 一次 184.8 ns 一次 67.0 ns（2.7× 跨 run 漂移）。同程序、同 min_runs 量级、同字节码，phase 间和跨 run 都漂移百分百以上。

**这直接否定**了"ratio 反映 ReJIT 优化"的假设——applied=0 群体不可能有任何 ReJIT 信号。

### 证据 2：trace_ret_* 系 0.07× "赢家"在 Run 3 全部 applied=0

Run 3 top 8 wins（按 ratio 升序）：

| # | app | pid | name | min_runs | baseline ns | post ns | ratio | applied |
|---|-----|-----|------|----------|-------------|---------|-------|---------|
| 1 | tracee/monitor | 616 | trace_ret_vfs_write | 2.52 M | 607.6 | 41.3 | 0.068 | **0** |
| 2 | tracee/monitor | 621 | trace_ret_vfs_writev | 1245 | 4219.4 | 289.4 | 0.069 | **0** |
| 3 | tracee/monitor | 674 | trace_ret_file_modified | 5.69 M | 423.0 | 32.4 | 0.077 | **0** |
| 4 | tracee/monitor | 672 | trace_ret_file_update_time | 611 K | 524.1 | 41.5 | 0.079 | **0** |
| 5 | tracee/monitor | 630 | trace_ret_vfs_read | 14.30 M | 743.3 | 62.5 | 0.084 | **0** |
| 6 | tracee/monitor | 633 | trace_ret_vfs_readv | 1245 | 2407.8 | 217.0 | 0.090 | **0** |
| 7 | tracee/monitor | 676 | trace_ret_inotify_find_inode | 7836 | 1361.9 | 145.5 | 0.107 | **0** |
| 8 | tracee/monitor | 622 | vfs_writev_magic_return | 1245 | 3086.2 | 380.2 | 0.123 | **0** |

**8 个 0.07-0.12× "赢家"全部 applied=0**——map_inline 没碰这些程序。但 baseline avg 显示明显比 post 重（607 ns vs 41 ns，14×差距）。两种可能：
1. baseline phase 上 tracee 的 kretprobe 处理了大量重 I/O（深目录扫描、大文件 readv 等），post-rejit phase 没跑到这些路径；
2. baseline 路径比 post-rejit 多了某种 helper 调用（不可能，bytecode 没变）。

只剩可能性 1。

### 证据 3：Run 4 同一组 trace_ret_* 程序 applied=17 比值仅小幅变化

Run 4（kinsn-only）同一组：

| 程序 | Run 3 ratio (applied=0) | Run 4 ratio (applied=17) | 差异 |
|------|---|---|---|
| trace_ret_vfs_write | 0.068 | 0.066 | -3% |
| trace_ret_file_modified | 0.077 | 0.074 | -4% |
| trace_ret_file_update_time | 0.079 | 0.081 | +3% |
| trace_ret_vfs_read | 0.084 | 0.089 | +6% |
| trace_ret_inotify_find_inode | 0.107 | 0.089 | -17% |
| trace_ret_vfs_readv | 0.090 | 0.147 | +63% |

加 17 个 kinsn site 之后比值平均变动只有几个百分点（且方向不一致），远小于 baseline-vs-post phase 间的 baseline avg 变动。

**结论**：0.07× 加速的主要驱动是 phase 间 workload pattern 差异（kretprobe 当 phase 1 重活在 phase 2 没复现），kinsn 的 17 个 site 只是叠加了 < 5% 的小修正。

### 证据 4：trace_X 系 1.5-2.2× "输家"两次都 applied=0

Run 3 + Run 4 cross-check：

| 程序 | Run 3 ratio (applied=0) | Run 4 ratio (applied=0) |
|------|---|---|
| trace_vfs_write | 1.649 | 1.547 |
| trace_vfs_read | 1.157 | 1.630 |
| trace_do_mmap | 1.531 | 1.666 |
| trace_vfs_readv | 1.597 | 1.499 |
| trace_vfs_writev | 1.550 | 1.473 |
| trace_file_update_time | 1.332 | 1.342 |
| trace_security_sk_clone | 1.319 | 1.247 |

→ kprobe entry 全部 applied=0，但 **两次 run 都给出 1.3-1.7× slowdown**。如果是 ReJIT bug 必须能从 bytecode 解释；既然 bytecode 没改，唯一解释是 phase 偏置——baseline phase 跑了"小 size"事件，post-rejit phase 跑了"大 size"事件。

### 证据 5：applied vs not-applied 切片揭示真信号

| Run | 群体 | n | Method B (per-prog geomean) | Method C (run-weighted) |
|-----|------|---|----------|----------|
| 3 noop+map_inline | applied-only | 9 | 0.9378 | **1.0319 ← +3.2% slowdown** |
| 3 noop+map_inline | not-applied | 139 | 0.8939 | 0.9767 |
| 3 noop+map_inline | 全体 | 148 | 0.8965 | 0.9768 |
| 4 kinsn-only | applied-only | 112 | 0.8305 | **0.9989 ← essentially flat** |
| 4 kinsn-only | not-applied | 35 | 1.1090 | 1.0124 |
| 4 kinsn-only | 全体 | 147 | 0.8897 | 1.0008 |

**Method C 分群体看：**
- Run 3 map_inline 实际命中的 9 个 prog 是 **+3.2% slowdown**，不是加速。九个里面只有 otel 54/sched_process_free（applied=6 sites, ratio 0.423, min_runs=163）拉低了 Method B；其他 8 个全部 ≥ 0.997。
- Run 4 kinsn 命中的 112 个 prog 是 **+0.1% 加速**——基本持平。
- 整体 Method C 的"加速"主要落在 not-applied 群体 → 那部分由 phase 偏置主导，不是 ReJIT 信号。

### 证据 6：Method B 被低 min_runs 程序主导

Run 3 整体 Method B 0.8965：8 个 trace_ret_* 程序的 0.07× 比值（min_runs 1245-14M）让 log-mean 拉到 -0.1 以下。
- 如果剔除 min_runs<10 K 的程序：Method B 接近 0.95
- 如果剔除 not-applied 群体：Method B 0.94（applied-only）

→ paper 报 0.89 会被审稿人质疑是 noise-floor 残留。**Method C 比 Method B 更稳健**（按 run 计数加权，自然抑制低-runs 噪声 prog）。

### 证据 7：cilium / otel applied prog 单点观察

Run 3 cilium/otel applied prog（这是 map_inline 唯一出力的地方）：

| app | pid | name | applied | min_runs | ratio |
|-----|-----|------|---------|----------|-------|
| otel | 54 | tracepoint__sched_process_free | 6 | 163 | 0.423 ← min_runs 太低，paper-grade 边缘 |
| otel | 55 | native_tracer_entry | 30 | 142 K | 1.021 ← +2% slowdown |
| cilium | 200 | cil_from_container | 9 | 4.02 M | 0.997 ← flat |
| cilium | 162 | cil_from_host | 41 | 1.60 M | 1.003 ← flat |
| cilium | 191 | cil_to_netdev | 48 | 1.83 M | 1.007 ← flat |
| cilium | 183 | cil_from_netdev | 26 | 1.62 M | 1.026 ← +2.6% slowdown |
| cilium | 159 | cil_xdp_entry | 1 | 1.62 M | 1.048 ← +5% slowdown |
| cilium | 210 | cil_from_container | 9 | 2508 | 1.131 ← min_runs 低，phase 偏置 |
| tracee | 570 | tracepoint__sched__sched_process_f | 1 | 727 K | 1.061 ← +6% slowdown |

**map_inline 9 个 applied prog 里 6 个是 slowdown / flat**，只有一个 min_runs 极低的 otel sched_process_free 拉出 0.423 拉低了 Method B。这九个里 cilium 5 个（41+48+26+9+1=125 sites）合起来是 +1% slowdown。

Run 4 kinsn 112 个 applied prog 里的代表点：

| app | pid | name | applied | min_runs | ratio |
|-----|-----|------|---------|----------|-------|
| katran | 530 | balancer_ingress | 55 | 3.21 M | 0.998 |
| otel | 55 | native_tracer_entry | 15 | 142 K | 1.019 |
| cilium | 159 | cil_xdp_entry | 8 | 1.60 M | 1.032 ← +3% slowdown |
| cilium | 164 | cil_from_host | 23 | 1.58 M | 1.044 ← +4% slowdown |
| cilium | 187 | cil_from_netdev | 22 | 1.60 M | 1.024 ← +2% slowdown |
| cilium | 186 | cil_to_netdev | 20 | 1.85 M | 1.022 ← +2% slowdown |
| tracee/694 | cgroup_bpf_run_filter_skb | 4 | 30.6 M | 1.078 ← +8% slowdown |
| tetragon | 422 | generic_tracepoint_event | 30 | 636 M | 0.986 ← -1.4% |

**主流量 cilium prog 全部 +2-4% slowdown**，katran balancer_ingress 持平，tetragon flagship `generic_tracepoint_event`（636 M runs）-1.4%——这个最接近"真信号"，因为 min_runs 是亿级，phase 偏置的相对影响最小。

---

## 噪声机制：workload phase variance 的物理来源

为什么 baseline 和 post-rejit phase 工作量会差？

corpus 框架的运行流程（每个 app 独立执行）：
1. App 启动 → 等 BPF 程序就绪 → spawn workload 进程
2. **baseline phase**：`bpf_enable_stats(BPF_STATS_RUN_TIME)` → 跑 30 秒 workload → 抓 `prog_info.run_cnt`/`run_time_ns` 增量
3. App 不重启，直接 ReJIT 全部 prog
4. **post_rejit phase**：再 spawn workload → 跑 30 秒 → 抓增量
5. App 关闭

baseline 30 秒和 post 30 秒之间，workload 进程是**新 spawn 的两个独立运行**：
- 文件系统状态变化（vfs_create 在 baseline 创建了文件，post 阶段 stat/open 这些文件 → 不同 syscall 路径）
- 内核 page cache / dentry cache 在 baseline 跑完后变热 → post 的 vfs_open 走 hit-path
- tracee 内部 maps 累积事件，post 阶段 LRU 行为不同
- KVM 宿主上其他 VM 抢 CPU（次要，但叠加）

→ trace_ret_vfs_write 在 baseline 处理了"大量 cold-cache write"（607 ns/call），post 处理了"warm-cache write"（41 ns/call）—— **这是 workload 真实差异，不是 ReJIT 优化**。

修复方向：
1. **更长 workload duration**（60-120 秒）让 cache state 收敛
2. **每个 phase 跑 N 次 workload，丢弃首次**（warmup discard）—— SAMPLES=3 现在已经 sample 3 次但都被采纳
3. **app 重启在两 phase 之间**（清 page cache + reset app 内部状态）—— 但破坏 ReJIT 测量语义
4. **paper-grade 必须在每次 run 都跑 noop baseline 配对**，做差减法去除 phase 偏置

**最低代价的修复 #4**：cron-style 跑 `noop` 和待测 pass 各 5-10 次，per-prog 算 (kinsn ratio mean) / (noop ratio mean) 抵消 phase 偏置。

---

## 接下来的 9-run dispatch 计划

已派 task `b4pgkxzaq`（log: `docs/tmp/bench_queue_20260507.log`）：

| Q | label | 命令 | 目的 |
|---|------|------|------|
| Q1 | noop-baseline-7app | `BPFREJIT_BENCH_PASSES=noop SAMPLES=3 7-app` | **噪声楼层**：所有 prog applied=0，Method B/C 应趋近 1.0；任何偏离 1.0 都是 phase variance |
| Q2 | mi-verify-3app | `noop,map_inline` on cilium+otel+tracee | #226：复测 map_inline applied prog 集中报告 |
| Q3 | kinsn-no-prefetch-7app | kinsn 去掉 prefetch | 检查 prefetch 是 Run 4 信号源否 |
| Q4 | prefetch-only-7app | prefetch only | prefetch 单 pass 净效应 |
| Q5 | wide-mem-only-7app | wide_mem only | wide_mem 单 pass 净效应 |
| Q6 | otel-prefetch | prefetch on otel | #213 native_tracer_entry isolation |
| Q7 | otel-bulk-memory | bulk_memory on otel | #213 isolation |
| Q8 | otel-cond-select | cond_select on otel | #213 isolation |
| Q9 | otel-bulk-prefetch | bulk_memory+prefetch | #213 interaction check |

**预计耗时**：5×33 min + 4×8 min ≈ 3.3 小时。串行执行不重叠。

**Run 5 (Q1) 是最关键的**：噪声楼层标定。如果 Q1 的 Method C 在 [0.97, 1.03] 区间，那 Run 4 的 0.9989 + Run 3 applied-only 1.0319 都在噪声内，**ReJIT 没有可报告的加速信号**，paper 需要换数据获取方式（更长 duration / phase-paired 设计 / 真实 e2e workload throughput delta 而非 prog timer）。

---

## 给 paper / 论文 的 honest 措辞

不要写：
- "ReJIT 实现了 10% 几何平均加速"（Method B 0.89 是 phase 偏置主导，不是 ReJIT 信号）
- "kinsn 在 1898 个 site 实现了加速"（applied-only Method C 0.9989，事实上没加速）

可以写（前提：Q1 baseline 噪声楼层确认 < ±5%）：
- "ReJIT 在大流量 prog（min_runs > 10⁸）的 Method C aggregate ratio 接近 1.0，small-prog 的 ±10% 漂移由 workload phase variance 主导，非 ReJIT 优化效果"
- "1898 kinsn sites are emitted across 112 programs without measurable run-time regression at the run-weighted aggregate (Method C 0.9989)" —— 这是 honest 的 "no harm"
- 个别 prog 的真信号需要靠 workload-side throughput 度量（见 #217 corpus app-throughput delta 分析）

不能在 paper 里报 Method B 0.89 作主指标。
