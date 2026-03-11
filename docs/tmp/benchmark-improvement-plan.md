# Benchmark 改进方案

Generated: 2026-03-11

## 1. 背景与判断

基于 `docs/tmp/benchmark-diversity-audit.md`，当前问题不是“仓库里没有非 XDP 程序”，而是“不同层的 benchmark 没把现有多样性真实暴露出来”。

当前状态可以概括为：

- `micro` 共 `67` 个 benchmark，其中 `64` 个是 XDP，只有 `2` 个 tc 和 `1` 个 cgroup_skb。
- `corpus recompile` 共 `79` 个 paired benchmark，其中 `61` 个 tc、`16` 个 xdp、`2` 个 cgroup_skb。
- `corpus census` 已经覆盖 `220` 个对象、`17637` 个 directive sites，类型本身是全的。
- `e2e` 主线目前是 Tracee / Tetragon / bpftrace，偏 tracing/security，一侧缺网络 datapath。
- 对 `kprobe` / `tracepoint` / `LSM`，本方案按保守约束处理，不把 `BPF_PROG_TEST_RUN` 当成主路径；它们的主测量方式仍应是 attach-trigger。

因此，改进重点不是继续堆 XDP benchmark，而是把 benchmark 体系拆成几条清晰的测量轨道，并给每条轨道定义明确的类型职责。

## 2. 目标

### 2.1 总目标

在不牺牲测量真实性的前提下，把 benchmark 体系重构成：

1. `packet test_run` 轨：覆盖 `xdp`、`tc`、`cgroup_skb`
2. `attach-trigger` 轨：覆盖 `kprobe`、`tracepoint`、`raw_tracepoint`、`LSM`
3. `real e2e` 轨：覆盖 tracing/security/scheduling，并补一个真实网络 datapath case
4. `compile-only / census` 轨：继续承担全类型代码尺寸和 directive 普查

### 2.2 论文层面的最小覆盖目标

下一轮论文主结果至少应做到：

- `XDP`: micro + corpus timed + e2e
- `tc`: micro + corpus timed + e2e
- `cgroup`: micro + corpus timed
- `tracing/kprobe`: corpus attach-trigger + e2e
- `LSM`: corpus attach-trigger 或 Tracee 类 e2e
- `struct_ops`: 先靠 `scx` e2e 兜底，后续再考虑 corpus 级 timed harness

## 3. 设计原则

### 3.1 不做“伪多样性”

不要为了让表格好看，把 tracing/LSM 程序包成 XDP 风格 wrapper 再塞进 micro。那只是在测 XDP harness，不是在测对应 hook family。

### 3.2 分层负责

- `micro` 负责 JIT 机理隔离，不负责覆盖全部 eBPF hook universe。
- `corpus timed` 负责真实程序上的可重复执行时间对比。
- `e2e` 负责系统级真实性和 workload 影响。
- `census` 负责“语料里确实有这些类型和 directive”。

### 3.3 报告必须区分 harness

后续所有表格和图都要显式区分：

- `packet_test_run`
- `attach_trigger`
- `registration/e2e`
- `compile_only`

不能把它们混成一个“exec-time benchmark”总数，否则结论会失真。

## 4. 目标状态

### 4.1 Micro

`micro` 不追求覆盖 kprobe/LSM/struct_ops，但要从“几乎纯 XDP”提升到“XDP 为主、tc/cgroup_skb 有实质存在”。

建议目标：

- 总量从 `67` 提升到 `75` 到 `80`
- 至少新增 `4` 个 tc benchmark
- 至少新增 `4` 个 cgroup_skb benchmark
- `micro_runtime` 中至少加入 `2` 个 tc runtime benchmark 和 `2` 个 cgroup_skb runtime benchmark

### 4.2 Corpus timed

把当前单一的 packet `test_run` timed 集扩展为双轨：

- `packet timed`：`xdp` / `tc` / `cgroup_skb`
- `attach-trigger timed`：`kprobe` / `tracepoint` / `raw_tracepoint` / `LSM`

这里的关键不是把 `79` 个 paired benchmark 盲目翻倍，而是建立第二条真实可解释的非 packet 执行时间轨道。

### 4.3 E2E

E2E 需要从“主要是 tracing/security”扩展成“两端平衡”：

- 保留 Tracee / Tetragon / bpftrace
- 补一个网络 datapath case，优先 `tc`，次选 `XDP`
- `scx` 继续作为 `struct_ops`/scheduling 的代表

## 5. 分阶段方案

### 5.1 P0：先把现有能力用满

时间目标：1 个迭代

### 工作包 A：把 `tc` 和 `cgroup_skb` 从“顺带覆盖”变成“显式主结果”

直接复用现有 `packet test_run` 能力，不改 runner，只改 shortlist、报告和分组。

优先纳入的 timed benchmark：

| 类型 | 对象 / 程序 | 作用 | 路径 |
| --- | --- | --- | --- |
| tc | `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main` | 代表主 tc classifier/policy path | 现成可跑 |
| tc | `corpus/build/calico/to_wep_debug.bpf.o:calico_tc_main` | 第二个真实 tc datapath 视角 | 现成可跑 |
| tc | `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 包重写/响应类路径 | 现成可跑 |
| tc | `corpus/build/calico/to_nat_debug.bpf.o:calico_tc_skb_send_tcp_rst` | 与主 path 形成功能对照 | 现成可跑 |
| cgroup_skb | `corpus/build/tracee/tracee.bpf.o:cgroup_skb_ingress` | 安全侧 cgroup packet path | 现成可跑 |
| cgroup_skb | `corpus/build/tracee/tracee.bpf.o:cgroup_skb_egress` | 与 ingress 成对 | 现成可跑 |
| cgroup_skb | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.bpf.o:direct_packet_access` | 自带 direct packet access 特征 | 现成可跑 |

P0 交付目标：

- 主结果表中单列 `tc` 与 `cgroup_skb`
- `cgroup_skb` 不再只有 `2` 个 paired benchmark 的象征性存在
- `packet timed` 报告中同时给出按 `prog_type` 和按 `project` 的 breakdown

### 工作包 B：先把报告体系改对

需要修改或扩展的入口：

- `corpus/run_corpus_runnability.py`
- `corpus/_driver_impl_run_corpus_v5_framework.py`
- `corpus/config/corpus_manifest.yaml`

改动目标：

- 为每个 benchmark 记录 `prog_type`、`measurement_lane`、`project`
- 输出按 `lane x prog_type` 的计数和结果汇总
- 在 markdown 和 JSON 中把 `packet_test_run` 与 `attach_trigger` 分开

P0 的核心不是新增大量代码，而是先让现有 `tc` / `cgroup_skb` 能见度上来。

### 5.2 P1：建立非 packet 的 timed 轨道

时间目标：1 到 2 个迭代

这一步不依赖 `BPF_PROG_TEST_RUN`，而是基于已有 `corpus/run_corpus_tracing.py` 的 attach-trigger 路径，统一把 `run_cnt` / `run_time_ns` 作为内核侧执行时间指标。

### 首批 attach-trigger 候选

| 类型 | 对象 / 程序 | 建议 trigger | 备注 |
| --- | --- | --- | --- |
| raw_tracepoint | `corpus/build/bcc/libbpf-tools/runqlat.bpf.o:handle_sched_switch` | 调度压力或 `sched_yield`/负载线程 | 已有正向样本 |
| tracepoint | `corpus/build/bcc/libbpf-tools/execsnoop.bpf.o:tracepoint__syscalls__sys_enter_execve` | `execve` storm | 稳定、易触发 |
| kprobe | `corpus/build/bcc/libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect` | loopback tcp connect | 用户态触发容易 |
| tracing/tp_btf | `corpus/build/bcc/libbpf-tools/biolatency.bpf.o:block_rq_issue_btf` | 受控磁盘 I/O | 可作为 BTF tracing 代表 |

这一层的关键产出：

- 给每类程序定义稳定 trigger recipe
- 定义 `positive run_cnt delta` 作为有效性门槛
- 输出每次 workload 的 `run_cnt`、`run_time_ns`、每次触发的外部吞吐

### 为什么先做 attach-trigger，而不是强行扩展 micro

因为 tracing/security 类型的真实性来自真实 hook 触发，而不是 synthetic wrapper。先把 attach-trigger 路线做扎实，比新增几个“看起来像 tracing、实际仍走 packet path”的 micro 更有价值。

### 5.3 P2：修正 micro 的结构性失衡

时间目标：1 个迭代

### 纯 JIT 类 benchmark

建议新增：

- `tc_packet_parse`：tc wrapper 下的 packet parse / bounds chain
- `tc_cmov_select`：tc wrapper 下的 branch-to-cmov 敏感路径
- `cgroup_skb_parse`：cgroup_skb 下的 direct packet parse
- `cgroup_skb_hash_policy`：cgroup_skb 下的 policy/hash style path

### runtime 类 benchmark

建议新增：

- `tc_map_lookup`：tc wrapper 下 map lookup/update
- `tc_helper_mix`：tc wrapper 下 helper-heavy path
- `cgroup_skb_map_policy`：cgroup_skb 下 policy map 查询
- `cgroup_skb_counter`：cgroup_skb 下 per-cpu/atomic counter path

对应修改入口：

- `micro/programs/*.bpf.c`
- `config/micro_pure_jit.yaml`
- `config/micro_runtime.yaml`

验收标准：

- `micro_runtime` 不再是 `11/11` 全 XDP
- 新增 tc/cgroup_skb benchmark 后，micro 仍然保持“机理隔离”定位，不引入 attach-trigger 风格复杂性

### 5.4 P2：补一个网络 datapath e2e

E2E 现在的问题不是 tracing 不够，而是网络 datapath 完全缺位。

优先级建议：

1. `tc e2e`：优先用 Calico
2. `xdp e2e`：次选 Katran 或 xdp-tools
3. `cgroup e2e`：可作为后续补充，不必阻塞前两者

优先的 `tc e2e` 设计：

- 使用 veth pair + `tc clsact`
- 装载 Calico 的代表性 tc program
- 用 `pktgen` / `iperf3` / `netperf` 触发
- 记录吞吐、延迟、CPU 和 drop/redirect 计数

可复用路径：

- `e2e/run.py`
- `e2e/cases/*`

目标不是造一个非常大的网络基准，而是让论文里出现一个真实 datapath deployment case，与 Tracee/Tetragon/bpftrace 形成对称。

### 5.5 P3：高投入项，作为后续扩展

### LSM timed benchmark

LSM 不应强行塞进 `test_run`。建议沿用 attach-trigger 路线，先做一个最小可复现实验：

- 候选对象优先 `systemd` 或 `tracee` 的小型 LSM program
- workload 选择 `execve` / `open` / `socket` 等确定性触发路径

目标是先拿到 1 个可信的 LSM exec-time case，而不是一次性铺满 `83` 个 LSM 程序。

### struct_ops corpus timed

`struct_ops` 暂时由 `scx` e2e 承担论文代表性即可。后续若要补 corpus 级 timed harness，可优先考虑：

- `dummy_st_ops_success.bpf.o`
- `scx` 现有 object + registration-backed replay

但这不应阻塞前面的 packet / attach-trigger 主线。

### synthetic `test_run` 作为实验分支，而不是主路径

如果后续确认 `raw_tracepoint` 或部分 `BPF_PROG_TYPE_TRACING` 在当前内核和 repo runner 中可以稳定做 synthetic context `test_run`，可以作为实验性增强加入：

- 优先放在 `micro/runner/src/kernel_runner.cpp`
- 只在通过上下文正确性校验后开放
- 报告中单独标成 `context_test_run`

这条线不能替代 attach-trigger 主线。

## 6. 推荐的里程碑与验收标准

### M1：报告和 packet lane 纠偏

- 主结果按 `packet_test_run` / `attach_trigger` / `e2e` / `compile_only` 分栏
- `tc` 与 `cgroup_skb` 在主结果里单独可见
- `cgroup_skb` paired timed benchmark 达到至少 `4` 个，理想值 `6` 到 `8`

### M2：attach-trigger timed lane 落地

- 至少 `1` 个 raw_tracepoint benchmark
- 至少 `1` 个 tracepoint benchmark
- 至少 `1` 个 kprobe benchmark
- 输出统一的 trigger recipe、稳定性检查和 `run_cnt/run_time_ns` 指标

### M3：micro 和 e2e 两端补齐

- `micro` 新增至少 `8` 个非 XDP benchmark，其中 tc/cgroup_skb 都含 pure-jit 与 runtime
- 新增 `1` 个真实网络 datapath e2e case

### M4：论文覆盖闭环

论文正文中每个 bucket 至少有一条真实测量路径：

- `XDP`: packet timed / e2e
- `tc`: packet timed / e2e
- `cgroup`: packet timed
- `tracing/kprobe`: attach-trigger / e2e
- `LSM`: attach-trigger 或 e2e
- `struct_ops`: scx e2e

## 7. 不建议做的事情

- 不要把 `compile-only` 结果和 `exec-time` 结果混在同一统计里。
- 不要为了补类型覆盖，发明不真实的 tracing/LSM micro wrapper。
- 不要把“corpus 有这种类型”直接等同于“benchmark 已覆盖这种类型”。
- 不要在 `tc` 已经很多的情况下继续只加 `tc`，而忽略 `cgroup_skb`、attach-trigger 和 network e2e。

## 8. 建议的实施顺序

建议按下面顺序推进：

1. 先修报告和 shortlist，把 `tc` / `cgroup_skb` 的 packet lane 做成显式主结果。
2. 再建立 attach-trigger timed lane，补上 tracing/kprobe 的真实执行时间路径。
3. 然后补 micro 的 tc/cgroup_skb 缺口，修正“micro 几乎纯 XDP”的结构失衡。
4. 最后补网络 datapath e2e，并把 LSM/struct_ops 作为高投入扩展项推进。

一句话总结：下一阶段不该继续“多做几个 XDP benchmark”，而应该把 benchmark 体系改造成 `packet test_run + attach-trigger + e2e + census` 四层协同的结构，让 corpus 里已经存在的类型多样性真正进入主结果。
