# Kinsn Prefetch Task

最后更新：2026-06-04。

## 结论

`PREFETCH` / `PRFM` 的 Kinsn 通路已经打通：`bpfopt` 能在 BPF bytecode 里插入
`KINSN_SIDECAR + KINSN_CALL`，kernel kinsn JIT 能把它们翻译成 x86 `prefetch*` 或
ARM64 `prfm`。但是当前 prefetch 还不能默认启用。

原因是 prefetch 是 **插入型优化**。它不会替换原始 load，而是在原始 load 前额外插入一个
cache hint。已有实验显示，简单地“在 load 前插 prefetch”大多没有稳定收益。

2026-06-02 已完成第一轮 hint variant、true degree 和 future-address horizon sweep，并补做
ARM64 horizon2/horizon4 L1 long-repeat run。2026-06-03 又在 AWS ARM64 `c7g.large` 上完成了
PMU-capable treatment/control attribution。默认 ARM64 micro instance `t4g.small` 缺少
`instructions/cache_references/cache_misses` counters；`c7g.large` 能提供这些 generic PMU
counters，因此这轮实验可以判断 positive timing 是否伴随 cache miss 下降。

当前有 PMU 证据支持的 candidate 是 profile-fed future-address 类 policy：

- `prefetch_mlop_index_field`：treatment/control `0.945284`，cache miss ratio `0.019193`。
- `prefetch_degree123_page_stride` degree1：treatment/control `0.958149`，cache miss ratio `0.006768`。
- `prefetch_pipeline_horizon2_page_stride`：treatment/control `0.961195`，cache miss ratio `0.009627`。
- `prefetch_pipeline_page_stride`：treatment/control `0.968297`，cache miss ratio `0.006868`。
- `prefetch_spatial_page_footprint`：treatment/control `0.971461`，cache miss ratio `0.000460`。

这说明 “提前多个 logical step 预取 future map-value pointer” 比 same-iteration prefetch 更合理。
但它们仍然不能 default-enable，因为这些 wins 依赖 hand-profiled PC/register，是
synthetic-control micro，不是自动 selector，也不是 real-derived/corpus evidence。

2026-06-03 已按 PF-LLM 的 access-pattern taxonomy 补了一批 synthetic-control micro cases：
stride-class、spatial-within-page、fixed-offset struct-field、multi-level offset、normalized degree
和 per-PC mixed policy-table stress。它们已经完成 x86 / ARM64 AWS control correctness smoke；
ARM64 `prefetch_stride64_page_stride` 还完成了 treatment emit smoke，确认 profile point 能插入
1 个 prefetch kinsn，并在 kernel JIT dump 里生成 `prfm pldl1keep, [x20]`。

2026-06-04 继续补齐此前未完成的 PF-LLM-inspired policy probes：

- `struct-field`：x86 treatment smoke 已按 profile 插入 3 个 `prefetcht0`。
- `mixed-policy-table`：profile schema 已支持 `prefetch` / `skip` action，x86 treatment smoke 插入
  1 个 `prefetcht0`。
- `stream-of-strides`：新增两个交错 stride stream 的 micro case，x86 control / treatment smoke
  通过，treatment 插入 2 个 `prefetcht0`。

这一步先完成 x86 correctness / emit smoke。

同日随后补齐了这三个 policy 的 ARM64 smoke 和 paired attribution：

- `struct-field`：ARM64 treatment 插入 3 个 `prfm`，paired treatment/control `0.959350`，
  是正向 timing signal，但还没有 PMU cache-miss 归因。
- `mixed-policy-table`：ARM64 treatment 插入 1 个 `prfm`，16 个候选 site 被 skip，
  paired treatment/control `0.990555`，接近 noise-level；它主要证明 per-PC `prefetch` /
  `skip` schema 能保护不该插的 site。
- `stream-of-strides`：ARM64 treatment 插入 2 个 `prfm`，paired treatment/control `1.553949`，
  明显变慢；当前 two-stream policy 不应作为 candidate。

结合此前 `c7g.large` PMU diagnosis，最新结论是：stride64/stride256、
same-iteration map/upper-bound、default structural policy 基本不是好 candidate；spatial、
MLOP、horizon/pipeline 和 degree1 值得继续做 profile/schema 和 corpus site census。

因此当前状态是：

```text
prefetch = research-only / profile-gated candidate
default policy = disabled
```

## 文档结构

Prefetch task 的文档按层次拆开，避免混淆 policy 和非 policy：

| file | 内容 | 是否 policy |
|---|---|---|
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md` | 从机制到 integrated prefetcher 的阶段计划、当前进度、下一步 gate。 | 否 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/mechanism.md` | ABI、`KINSN_SIDECAR + KINSN_CALL`、kernel JIT emit、runner / loader 路径。 | 否 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/safety-rules.md` | verifier-safe insertion、register stability、load-only、dedup、site budget、profile gate。 | 否 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md` | 真正的 prefetch policy：地址、时机、horizon、degree、hint variant、skip decision。 | 是 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md` | 每类 microbenchmark test case 怎么构造、服务哪个 policy、有什么局限。 | 否 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md` | 实验列表、结果、non-win evidence、artifact。 | 否 |
| `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/literature-review.md` | 预取论文、工业实现、开源实现综述和 source cache 索引。 | 否 |

## 背景：prefetch 和替换型 kinsn 的区别

Kinsn 的共同机制是：BPF object 中用 sidecar 携带 payload，再用 kinsn call 指定目标 kfunc。
Verifier 仍检查普通 BPF 语义，目标架构 JIT 在 verifier 之后生成 native instruction。

多数 kinsn family 是替换型优化：

```text
BPF sequence:
  shift + shift + or

native execution:
  rotate/extr instruction
```

这种优化的性能逻辑通常是 native 指令更少、dependency 更短。

Prefetch 不同：

```text
control:
  load *(ptr)

treatment:
  KINSN_SIDECAR(ptr_reg)
  KINSN_CALL(bpf_x86_prefetcht0 or bpf_arm64_prfm_pldl1keep)
  load *(ptr)
```

也就是说，treatment 保留原始 load，并额外增加 native hint：

| arch | kfunc target | native hint |
|---|---|---|
| x86 | `bpf_x86_prefetcht0` | `prefetcht0 [rN]` |
| ARM64 | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [xN]` |

因此 prefetch 只有在下面条件同时满足时才可能变快：

- 目标地址大概率不在目标 cache 中。
- prefetch 到 demand load 之间有足够 lead time。
- 插入点已经在 verifier-safe bounds/null check 之后。
- 额外 hint 不造成明显 frontend、bandwidth 或 cache pollution 成本。

## 当前实现

主要实现路径：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
```

运行路径：

```text
BPF object
  -> runner 读取 object
  -> 如果设置 BPFREJIT_BENCH_PASSES=prefetch，先调用 bpfopt
  -> bpfopt 输出 transformed raw BPF bytecode
  -> raw kinsn loader 加载 BPF
  -> kernel kinsn JIT emit native prefetch hint
  -> micro kernel runtime 测量 execution time
```

已实现能力：

| component | 实现内容 |
|---|---|
| `bpfopt` prefetch pass | packet/map pointer tracking、stack alias、register offset、same-cacheline dedup、site budget。 |
| profile gate | `bpfopt --pass prefetch -- --profile FILE`，只允许 profile 指定的 map-value PC 或 prefetch point。 |
| hint selection | `bpfopt --pass prefetch -- --hint VALUE`，支持 x86 `t0/t1/t2/nta` 和 ARM64 `pldl1keep/pldl1strm/pldl2keep/pldl2strm`。 |
| site budget | `bpfopt --pass prefetch -- --max-sites N`，允许一个 program 最多插入 N 个 independent candidates。注意这不是 true future-address degree。 |
| micro kernel runtime | 支持先应用 `bpfopt` pass，再加载 raw kinsn BPF。 |
| raw kinsn loader | 支持 BTF `.maps` 和 map relocation。 |
| micro benchmark | 新增 packet、map、upper-bound、next-iteration、PF-LLM-inspired access-shape policy probes。 |

当前支持的 native hint：

| arch | hint arg | kfunc target | native hint |
|---|---|---|---|
| x86 | `t0` / `l1keep` | `bpf_x86_prefetcht0` | `prefetcht0 [addr]` |
| x86 | `t1` / `l2keep` | `bpf_x86_prefetcht1` | `prefetcht1 [addr]` |
| x86 | `t2` / `l2strm` | `bpf_x86_prefetcht2` | `prefetcht2 [addr]` |
| x86 | `nta` | `bpf_x86_prefetchnta` | `prefetchnta [addr]` |
| ARM64 | `pldl1keep` / `l1keep` | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [addr]` |
| ARM64 | `pldl1strm` / `l1strm` | `bpf_arm64_prfm_pldl1strm` | `prfm pldl1strm, [addr]` |
| ARM64 | `pldl2keep` / `l2keep` | `bpf_arm64_prfm_pldl2keep` | `prfm pldl2keep, [addr]` |
| ARM64 | `pldl2strm` / `l2strm` | `bpf_arm64_prfm_pldl2strm` | `prfm pldl2strm, [addr]` |

## Safety / admission 和 policy 的区别

当前 prefetch selector 包含两类逻辑：

```text
safety / admission rules:
  判断能不能安全插。

policy:
  判断值不值得插，以及插哪个 future address / hint / degree。
```

不要把这两类混在一起。Safety rule 不证明性能收益。

Safety / admission rules：

| rule | 实现方式 | 当前结果 |
|---|---|---|
| verifier-safe insertion | 只在同一 basic block 内插入；插入窗口不能跨 call、jump、exit 或 pseudo func。 | correctness 通过。 |
| pointer register stability | 插入点到 target load 之间，prefetch 使用的 register 不能被重定义。 | correctness 通过。 |
| packet pointer tracking | 从 packet `data` / `data_end` 派生 pointer fact，追踪 MOV、ADD/SUB、stack spill/reload。 | 能识别 packet load。 |
| map value tracking | 识别 `bpf_map_lookup_elem` 返回的 `r0`，通过 CFG/dataflow 传播 map-value alias。 | 结构可识别，但默认不应用。 |
| load-only filtering | 只对 `BPF_LDX` read load 插入，不对 store 插入。 | 降低误报。 |
| same-cacheline dedup | 同一 pointer / cacheline 多个 load 只保留一个 candidate。 | 已实现。 |
| dependent depth | `packet load -> scalar index -> final deref` 只允许 depth 1；depth 0 和 depth > 1 默认跳过。 | selector v3 行为正确。 |
| profile gate | map-value load 只有 profile allow-list 或 profile point 指定时才应用；显式 profile PC/register 可作为 trusted future-pointer admission point。 | admission 可控；c7g PMU 结果支持部分 future-address profile-fed policy，但仍不是自动 selector。 |
| next-iteration / horizon point | profile 指定某个 BPF PC 和 live register，表示这里已有未来轮次 pointer。 | ARM64 horizon2/horizon4 + L1 hint 是当前候选，但还不是自动 selector。 |

真正 policy 见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md
```

## Micro benchmark 是什么

`micro` 是 isolated pure-JIT benchmark。它不是 corpus，也不是 end-to-end app。它的目的不是证明
真实应用收益，而是控制某种 BPF code shape，观察 control 和 treatment 的 native code 与 runtime
差异。

每个 prefetch micro 都包含：

- BPF C program，例如 `prefetch_research.bpf.c`。
- manifest entry：`/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`。
- deterministic input generator。
- expected result。
- source type：当前 prefetch probes 都是 `synthetic-control`，用于策略筛选，不是 real-derived case。

典型实验流程：

```text
control:
  运行同一个 micro benchmark，不应用 prefetch pass

treatment:
  设置 BPFREJIT_BENCH_PASSES=prefetch
  可选：设置 BPFREJIT_BENCH_PASS_ARGS='--profile ...'
  runner 调用 bpfopt，把 prefetch kinsn 插入 raw BPF
  kernel JIT 生成 prefetcht0 / prfm

analysis:
  检查 sites_applied、native JIT dump、BPF/native code size、exec_ns 或 wall/cycles
  计算 treatment/control ratio
```

ratio 小于 `1` 表示 treatment 更快。完整实验表见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
```

完整 policy matrix 见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md
```

每类 micro case 的构造方式见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md
```

提交到 repo 的实验 artifact 见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/README.md
```

## 已试 policy 和结论

| policy | test case | 结论 |
|---|---|---|
| fixed-distance prefetch | `prefetch_distance_0/2/4/8/16/32` | ARM64 geomean T/C `1.004928`，没有稳定收益。 |
| packet candidate filtering | hot、sequential、large-stride、permuted、packet-first-deref | 大多数 mixed；不能 default-enable。 |
| map-backed large working set | `prefetch_map_page_stride` 等 | geomean `1.001694`，约慢 `0.17%`。 |
| selector v3 packet first-deref | `prefetch_packet_first_deref`, `prefetch_single_first_deref` | correctness/codegen 通过，performance mixed。 |
| profile-fed map-value prefetch | profile allow-list 指定 map-value PC | admission 可用；结果 preliminary。 |
| same-iteration upper-bound map | `prefetch_upper_page_stride` | x86 noise-level，ARM64 slowdown。 |
| next-iteration prefetch | `prefetch_pipeline_page_stride` | ARM64 三轮 positive direction；long-repeat T/C `0.948348`，但缺少 PMU 机理归因。 |
| hint variant sweep | horizon1/2/4 + degree cases | ARM64 L1 hints 优于 L2 hints；x86 `nta` 明显变慢。 |
| true degree sweep | `prefetch_pipeline_degree_page_stride` | ARM64 `l1keep` T/C `0.982073`，只有弱信号；不如 horizon2/horizon4。 |
| future-address horizon sweep | `prefetch_pipeline_horizon1/2/4_page_stride` | ARM64 horizon2/horizon4 + L1 hint 是当前最好的 synthetic-control candidate。 |
| ARM64 horizon L1 long-repeat | `prefetch_pipeline_horizon2/4_page_stride` | horizon2 mean T/C `0.945361`，horizon4 mean T/C `0.971207`；随后 c7g PMU run 已补 horizon2 cache-miss evidence。 |
| PF-LLM-inspired access-shape smoke | stride/spatial/fixed-offset/MLOP/degree/mixed cases | x86 / ARM64 control correctness 通过；ARM64 stride64 treatment `sites_applied=1` 且 JIT dump 有 `prfm pldl1keep`。 |
| c7g PMU policy diagnosis | 已实现且有 profile 的 ARM64 policy/case | `mlop`、`degree1`、`horizon2`、`pipeline`、`spatial` 有 cache-miss-drop evidence；plain stride / same-iteration / default structural 不支持。 |
| missing-policy x86 smoke | struct-field、mixed-policy-table、stream-of-strides | x86 treatment correctness / emit 通过：struct-field applied 3，mixed-policy applied 1，stream-of-strides applied 2；不含性能结论。 |
| missing-policy ARM64 attribution | struct-field、mixed-policy-table、stream-of-strides | ARM64 treatment correctness / emit 和 paired attribution 通过；struct-field T/C `0.959350`，mixed-policy T/C `0.990555`，stream-of-strides T/C `1.553949`。 |

非 policy 支撑实验单独记录：

| experiment | 作用 | 结论 |
|---|---|---|
| PMU capability smoke | 检查 AWS x86/ARM64 micro 环境能否提供 cache-miss / refill counters。 | 当前默认 AWS micro 环境缺少关键 PMU counters；只能看 timing / cycles，不能做 cache-miss 机理证明。 |
| c7g PMU diagnosis | 用 AWS ARM64 `c7g.large` 跑同一批 treatment/control，并采集 `cycles/instructions/cache_references/cache_misses`。 | `c7g.large` 能提供 generic PMU counters，已解决 ARM64 micro 的 cache-miss attribution 问题；它是 PMU capability exception，不是默认 instance。 |
| object / JIT dump evidence | 证明 treatment 确实插入了 `KINSN_CALL` 并由 kernel JIT 翻译成 native prefetch hint。 | 已用于 variant/degree/horizon 实验，属于机制证据，不是 policy 本身。 |

## 当前判断

不能 default-enable 的原因：

- structural-only policy 没有稳定收益。
- c7g PMU 结果显示 positive case 的 cache miss 确实下降，但这些 case 仍是 hand-profiled synthetic-control。
- P19/P21 仍是 hand-profiled profile point，不是自动 selector。
- 还没有 real-derived / corpus site census 证明真实 BPF 程序中足够常见这些 future-address shape。

## 已补齐的 policy-space 维度

| 能力 | 含义 | 实现方式 | 为什么必须测 |
|---|---|---|---|
| hint variant | 选择不同 cache level / temporal policy / stream policy。 | 已扩展 kfunc ABI，并完成 paired runtime sweep。 | 结果显示 ARM64 L1 hints 最好，x86 `nta` 明显慢。 |
| true degree | 一次触发预取几个未来地址。 | 已新增 degree case，对 `i+1/i+2/i+4` 三个 future pointers 分别插入 prefetch。 | 结果显示 degree 没有超过单个 horizon2/horizon4。 |
| horizon / distance | 提前多少轮或多少字节预取。 | 已新增 horizon1/2/4 cases，用 profile points 指向 future pointer。 | 结果显示 ARM64 horizon2/horizon4 比 horizon1 更合理。 |
| PF-LLM-inspired access shape | 按访问形态构造 stride、spatial、fixed-offset、MLOP、degree、mixed-policy 和 stream-of-strides cases。 | 2026-06-03 已新增第一批 cases 和 profile JSON；2026-06-04 已补 struct-field、mixed-policy-table、stream-of-strides 的 ARM64 attribution。 | spatial、MLOP、degree1 有 PMU-backed positive evidence；struct-field 有非 PMU positive timing；plain stride 弱或中性；stream-of-strides 明显变慢。 |

这些能力不是为了照搬 PF-LLM。PF-LLM 的关键启发是：先枚举 policy space，给每个 load site
找到最适合的 policy，再考虑 selector。Kinsn prefetch 也必须先完成这个 policy-space 实验。

当前 policy space 仍不完整。PF-LLM 里可借鉴但尚未完成 ARM64 runtime attribution / corpus
coverage 的部分主要是：

- 按 access pattern 选择 policy：stride、spatial within page、fixed-offset struct field、
  multi-level offset。struct-field 已有 ARM64 paired timing signal，但还缺 PMU 归因。
- normalized degree：把 conservative / moderate / aggressive 映射成 1、2、3 个 future
  address，而不是只测一个 “一次全发” 的 degree case。
- per-PC policy table：同一个 BPF program 内不同 load site 可以选择不同 horizon / hint /
  skip decision。当前 schema 和 x86 smoke 已通，ARM64 attribution / corpus site census 仍未做。
- negative filtering：明确把 hot、sequential、no-lead-time、dependent-chain 标成 no-prefetch。
- stream-of-strides：两个交错 stream 已完成 ARM64 attribution，当前结果明显变慢，除非后续有
  PMU / JIT evidence 证明可以修正 placement 或 degree，否则不进入 candidate set。

这些 testcase 的构造规则和当前状态见：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md
```

## 下一步

下一步按下面 gate 推进：

1. 对 `struct-field` 做 `c7g.large` PMU attribution，确认 timing positive 是否来自 cache miss 下降。
2. 对 `stream-of-strides` 做 slowdown 归因，区分 instruction overhead、wrong timeliness 和 cache pollution。
3. 做 corpus site census，确认真实 BPF 中是否有足够多 future-address / spatial / MLOP / struct-field /
   stream-of-strides shape。
4. 设计自动 selector：从 hand-profiled `PC/register` 过渡到自动识别 future map-value pointer。
5. 把结果按 policy × case 分类：stable win、mixed、stable slow、best-case no-win。
6. 对每个 non-win case 写 evidence classification：已排除什么、有证据支持什么、还缺什么证据。
7. 只有 stable win 的 policy 进入 selector；mixed policy 只能 profile-gated；stable slow 和
   best-case no-win 默认删除或禁用。
