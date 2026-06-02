# Kinsn Prefetch Policy Matrix

最后更新：2026-06-02。

## 结论

Kinsn prefetch 的 selector v3 不是新的 kfunc ABI，也不是 LLVM ARM backend 的 MachineInstr
selector。它是 `bpfopt --pass prefetch` 的 **BPF bytecode-level policy**：扫描 BPF 程序里的
memory access，判断哪些 access 值得额外插入 prefetch kinsn，哪些必须跳过。

当前结论：

- `PREFETCHT0` / `PRFM` 的 kfunc ABI、payload、BPF object、kernel JIT native emit 都已经能工作。
- 早期 policy v1 是 structural coverage policy：能找到 packet/map pointer dereference 并插入
  prefetch，但不是成熟性能策略。
- 已有 micro 结果不支持默认启用 prefetch。大多数策略探针是 mixed 或 slowdown。
- selector v3 已收紧 admission：只允许 packet first-deref final load；map value candidate
  需要 profile/PMU evidence；profile gate 已实现第一版 pass-local side input；hot/sequential/
  indirect/no-lead-time 都不应默认 admission。
- 当前 selector v3 smoke 已在 x86 和 ARM64 AWS kernel runtime 上通过；随后完成的 x86/ARM64
  same-LLC attribution 结果是 mixed，不支持 default-enable。
- profile-fed map-value gate 已完成一轮 x86/ARM64 AWS paired attribution：admission 机制可用，
  但结果仍只是 preliminary signal，不支持 default-enable。
- PMU capability smoke 也已完成：默认 AWS micro 环境下 x86 `t3.small` 没有硬件 PMU counters，
  ARM64 `t4g.small` 只有 `cycles`，没有 `cache_misses` / `cache_references` / `instructions`。
  因此当前不能用这个环境做 cache-miss attribution。
- 2026-06-02 又新增了 `prefetch_upper_page_stride` 作为更偏向 prefetch 的 upper-bound
  synthetic-control case。它使用 1 MiB map working set、page-stride access、profile gate 和
  independent ALU lead time。结果仍不稳定：x86 只有约 0.2% nominal speedup，ARM64 约 0.7%
  slowdown。因此当前 blocker 不只是“旧 micro 不敏感”；same-iteration prefetch placement 本身
  仍不足以证明有效。
- 2026-06-02 又完成了 next-iteration / software-pipeline prefetch probe：
  `prefetch_pipeline_page_stride` 显式维护 `cur` 和 `next` pointer，并通过 profile point 对
  下一轮 pointer 发 prefetch。本地实现、object evidence、x86 / ARM64 AWS smoke 和 5-sample
  stability run 都已通过。x86 paired geomean treatment/control `0.985484`，是 weak positive
  signal；ARM64 paired geomean treatment/control `0.858777`，是第一轮 positive signal。
  但该 probe 仍是 hand-profiled best-case placement，不是 default-enable 证据。
- 2026-06-02 又做了一轮 independent rerun。ARM64 paired geomean treatment/control 是
  `0.962181`，方向仍然是 treatment 更快，但没有复现前一轮 `0.858777` 的幅度。x86 control
  timing 异常波动，不能作为性能结论。因此 P19 的当前状态是 positive direction but unstable
  effect size。

## 策略选择依据

prefetch strategy 的选择依据是 literature review、policy matrix 和逐项 micro 实验，而不是单次
benchmark 的最快结果。

选择链条：

1. **文献和体系结构约束**：prefetch 是 non-faulting hint，可能隐藏 cache miss，也可能增加
   frontend cost、bandwidth pressure 和 cache pollution。
2. **BPF/kfunc 约束**：Kinsn prefetch 在 BPF bytecode 层插入 `KINSN_SIDECAR + KINSN_CALL`，
   原始 load 保留；因此它必须比替换型 kinsn 更保守。
3. **策略矩阵拆分**：把 packet、map、hot、sequential、large-stride、indirect、guarded、
   cacheline-dedup、budget、profile/PMU gate 分开测。
4. **实验筛选**：已有结果显示 structural-only policy 不稳定；唯一进入 v3 admission 的是
   packet first-deref final load。map value prefetch 目前只作为 profile/PMU-gated candidate。

当前实验是系统性的第一阶段：已经覆盖主要 policy class 的 synthetic-control micro，完成 v3
x86/ARM64 correctness smoke，并完成 packet first-deref same-LLC attribution。它还不完整：
map value prefetch 已有 profile gate，并完成一轮 hand-written profile-fed AWS attribution；
PMU counter 归因在当前默认 AWS micro 环境下 blocked，仍需要独立 rerun、codegen evidence 或
PMU-capable 环境。hint variant 仍未实现。

## 基本机制

prefetch 是插入型 kinsn，不是替换型 kinsn。

替换型 kinsn 的逻辑是：

```text
BPF sequence -> 语义等价 native 指令
```

prefetch 的逻辑是：

```text
原始 BPF:
  load *(ptr)

treatment BPF:
  KINSN_SIDECAR payload = ptr_reg
  KINSN_CALL bpf_x86_prefetcht0 或 bpf_arm64_prfm_pldl1keep
  load *(ptr)
```

kernel kinsn JIT 输出：

```text
x86:   prefetcht0 [rN]
ARM64: prfm pldl1keep, [xN]
```

原始 load 仍然保留。因此 prefetch 几乎总是增加 BPF bytecode 和 native instruction。它只有在
memory latency 被隐藏、cache pollution 和额外指令成本可控时才可能快。

## 当前实现入口

当前实现位于：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
```

当前 target：

| arch | kfunc target | native hint |
|---|---|---|
| x86 | `bpf_x86_prefetcht0` | `prefetcht0 [rN]` |
| ARM64 | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [xN]` |

当前 placement / lookahead 核心常量：

| constant | value | 含义 |
|---|---:|---|
| `TARGET_PREFETCH_DISTANCE` | 8 BPF slots | 插入点尽量放在 target load 前约 8 个 BPF slot。 |
| `MAX_PREFETCH_DISTANCE` | 16 BPF slots | 只在 target load 前最多 16 个 BPF slot 的窗口内插。 |
| `POINTER_INDEX_USE_LOOKAHEAD` | 64 BPF slots | packet-derived scalar / pointer-index use 的局部扫描窗口。 |
| map-value tracking | CFG/dataflow | map lookup 返回值不再靠固定线性后扫；当前通过 basic-block CFG 和 register/stack alias propagation 找 map-value deref。 |

## Policy Matrix

表中：

- 当前 v3 的实现状态在后面的“当前 v3 状态”小节单独列出。
- “arch 是否相同”表示 BPF-level 扫描策略是否可共享；实际 performance 仍可能不同。
- “test case 来源”里的 `新增` 指本 prefetch task 新增的 synthetic-control micro。
- ratio 小于 1 表示 treatment 更快；大于 1 表示 treatment 更慢。

| policy | 解释 | 如何实现：扫描什么 pattern | 如何插入 prefetch | arch 是否相同 | 什么情况下触发 | test case | 来源 | 已跑结果 |
|---|---|---|---|---|---|---|---|---|
| P0. target lowering | 不是性能策略，只证明 kfunc 到 native hint 的通路能工作。 | 不扫描 pattern；由 forced object 或 `bpfopt` 插入 kinsn call。 | payload 只带 `ptr_reg`，x86 emit `prefetcht0 [rN]`，ARM64 emit `prfm pldl1keep, [xN]`。 | BPF payload 相同；native hint 不同。 | forced prefetch 或 policy 命中后。 | 全部 prefetch micro 都可用于 codegen evidence。 | 新增 | 已通过；JIT dump 能看到 `prefetcht0` / `prfm`。 |
| P1. verifier-safe insertion window | correctness gate：不能把 hint 插到 pointer 被证明安全之前，也不能跨 call/jump/exit。 | 对 candidate pointer definition 到 target load 之间取窗口；拒绝窗口内的 call、exit、jump、pseudo func。 | 在同一 basic block 中，选接近 target 前 8 slots 的 instruction boundary。 | 相同。 | pointer def 和 target load 在同一 frame，窗口无 control-flow。 | 所有 case 都间接覆盖。 | 新增 | 已实现；没有 verifier/runtime correctness failure。 |
| P2. pointer register stability | correctness gate：prefetch 用的 register 在插入点到 load 之间不能被重定义。 | 扫描 insertion window，检查 `insn_use_def_set` 是否重新定义 `ptr_reg`。 | 若被重定义，skip；否则插入。 | 相同。 | load base register 在窗口内稳定。 | 所有 case 都间接覆盖。 | 新增 | 已实现；当前报告没有 register clobber 失败。 |
| P3. packet pointer tracking | 识别 XDP/skb packet data pointer dereference。 | 从 context register 读 `data` / `data_end`，把寄存器标为 `PacketData` / `PacketEnd`；追踪 MOV、ADD/SUB imm/reg、stack spill/reload。 | 对以 `PacketData` register 为 base 的 `LDX` load 插入 prefetch。 | 相同。 | packet data pointer 被计算出来，后续有 load。 | `prefetch_packet_first_deref`、`prefetch_hot_l1_load`、`prefetch_sequential_scan` 等。 | 新增 | 已实现；但多数 packet case 性能 mixed。 |
| P4. map value first deref tracking | 识别 `bpf_map_lookup_elem` 返回 map value 后的 first deref。 | 看到 helper `BPF_FUNC_map_lookup_elem` 后，把 `r0` 作为 map value alias；通过 CFG/dataflow 传播 register 和 stack alias，找到后续 map-value load。 | v3 默认不插；profile gate 允许 `map_value_pcs` 或 `map_value_sites` 指定的 PC 通过。 | BPF-level tracking 相同；PMU event 和阈值 arch-specific。 | map lookup 成功路径上，map value pointer 后续被 load，并且 profile 证明该 site miss-prone。 | `prefetch_map_page_stride`、`prefetch_map_indirect_page`、`prefetch_map_line_dedup`、`prefetch_upper_page_stride`。 | 新增 | 无 profile 时 x86/ARM64 smoke 均 skipped；profile-fed `prefetch_map_page_stride` AWS attribution 已 applied 1 site。x86 `exec_mean` T/C `0.897679` 但 wall timing 不强；ARM64 `exec_mean` T/C `0.966154`，median T/C `0.989836`。upper-bound `prefetch_upper_page_stride` applied 1 site 后，x86 paired geomean T/C `0.998018`，ARM64 `1.007389`。PMU smoke 显示当前默认 AWS 环境不能提供 cache-miss counters；仍需 independent rerun 或另建 PMU-capable 环境。 |
| P5. load-only target | prefetch 只针对 read load，不对 store 插入。 | `load_base_reg()` 只接受 `BPF_LDX`，不接受 `BPF_STX` / `BPF_ST`。 | 只在 target 是 load 时插入。 | 相同。 | memory access 是 load。 | 所有 current case。 | 新增 | 已实现；降低误报面。 |
| P6. same-cacheline dedup | 同一 pointer definition、同一 cacheline 多个 load 不应重复插 prefetch。 | candidate 按 insert、ptr_def、target 排序；若 `ptr_reg`、`ptr_def` 相同且 `mem_off / 64` 相同，只保留一个。 | 只保留第一个 candidate。 | 相同；cacheline 默认按 64 bytes 处理。 | 同一 cacheline 内多个 load。 | `prefetch_cacheline_dedup_scan`、`prefetch_map_line_dedup`。 | 新增 | 已实现基础 dedup；ARM64 packet case median `0.999139` mixed，map line dedup `1.002829` slower。 |
| P7. fixed-distance lead time | 需要 prefetch 和 target load 之间有足够 independent work。 | 当前只用 slot distance，不识别 independent work 类型；目标距离 8 slots，最大窗口 16 slots。 | 插到 target load 前最接近 8 slots 的位置。 | 相同；最佳距离可能 arch-specific。 | target load 前存在合法窗口。 | `prefetch_distance_0/2/4/8/16/32`。 | 新增 | ARM64 distance geomean `1.004928` slower；没有稳定 win。 |
| P8. hot-load skip | hot L1 或反复访问同一地址不应插 prefetch。 | v2 应扫描同一 base/off 是否在短窗口内重复出现，或通过 profile/PMU 判断 hot。当前 v1 未实现 hot skip。 | v2 应 skip，不插。 | 扫描相同；阈值可能 arch-specific。 | 同一 packet offset 被反复读，数据很可能 hot。 | `prefetch_hot_l1_load`。 | 新增 | ARM64 median `0.862559` 但 mixed；wall/PMU 不支持强结论。应作为 skip/control，不作为 default win。 |
| P9. sequential streaming skip | 顺序 scan 常被硬件 prefetcher 覆盖，软件 hint 可能重复。 | v2 应识别连续 stride-1 cacheline/word scan，例如 base 相同、offset 单调递增。当前 v1 未实现 sequential skip。 | v2 应 skip 或只允许 profile 证明 miss 的 site。 | 扫描相同；硬件 prefetcher 效果 arch-specific。 | 连续读 packet/map buffer。 | `prefetch_sequential_scan`。 | 新增 | ARM64 median `0.922705` 但 mixed；不能作为 default evidence。 |
| P10. large-stride candidate | 跨 cacheline / page 的 stride access 可能超出硬件 prefetcher能力。 | v2 可识别固定大 stride 或 page-spread offset；当前 selector 主要依靠 profile gate 指定具体 PC。 | 只有存在 lead time 和 budget 时插。 | 扫描相同；收益 arch-specific。 | cacheline/page stride load，并有独立 work。 | `prefetch_large_stride_scan`、`prefetch_map_page_stride`、`prefetch_upper_page_stride`。 | 新增 | ARM64 large-stride packet median `0.999614` mixed；ARM64 map-page `0.997014` weak faster；x86 map-page `exec_ns 1.026784` slower、wall/cycles `0.92387` faster，结论不稳定。upper-bound case 仍不稳定：x86 `0.998018` weak/noise-level，ARM64 `1.007389` slower。 |
| P11. packet first deref admit | 从 packet 读 index，再 deref packet 另一块区域；当前唯一允许的 non-profile candidate。 | v3 识别 “packet load -> packet-derived scalar -> ALU32 index math -> pointer/offset compute -> bounds-safe final load”。 | 在 final load 前、bounds proof 后插；每个 program 只保留 1 个 site。 | 扫描相同；收益 arch-specific。 | packet first deref 且 dependent depth 等于 1。 | `prefetch_packet_first_deref`、`prefetch_single_first_deref`。 | 新增 | v3 x86/ARM64 smoke 均 applied 1；same-LLC attribution mixed。ARM64 packet geomean T/C `0.998441`，x86 packet wall/cycles geomean T/C 约 `0.9756`，但方向 mixed；不能默认启用。 |
| P12. permuted / irregular packet access | verifier-safe permutation 可能模拟 irregular access，但不一定有足够 miss/lead time。 | v2 可识别非单调 offsets，但需要 profile 或 cold working set 证据。当前 v1 不区分。 | 默认 skip；只有 profile gate 允许时插。 | 扫描相同；收益 arch-specific。 | fixed permutation access。 | `prefetch_permuted_index_scan`。 | 新增 | ARM64 median `1.003846` mixed/slower；应 skip。 |
| P13. indirect lookup skip | dependent address chain 的 prefetch 通常太晚，或者地址依赖未解析前不能提前。 | v2 应识别 target address 依赖前一次 load 的 value；当前 v1 可能只看到后续 packet/map load。 | 默认 skip，除非能插到真正 target load 前且有 independent work。 | 相同。 | second-stage address depends on first load. | `prefetch_indirect_lookup`、`prefetch_indirect_two_stage`、`prefetch_map_indirect_page`。 | 新增 | ARM64 indirect lookup mixed `0.997764`；two-stage stable loss `1.002285`；map indirect `1.005259` slower。应 skip。 |
| P14. guarded variable offset | 显式 bounds check 后的 variable offset 理论上 safe，但不一定 profitable。 | v2 应识别 bounds-check dominated target load；当前 v1 没有 dominance-level profitability model。 | 默认 skip 或需要 profile gate。 | 相同。 | variable offset 已被 verifier 接受。 | `prefetch_packet_offset_guarded`。 | 新增 | ARM64 median `1.001067` mixed/slower；应 skip。 |
| P15. full packet ring scan | 在 1400-byte packet 内扩大访问面，但 working set 仍小。 | v2 可识别 ring/loop scan，但 staged packet 不能证明 cold miss。 | 默认 skip；若要研究应换 map/corpus。 | 相同。 | packet 内 ring pattern。 | `prefetch_full_packet_ring_scan`。 | 新增 | ARM64 median `0.999441` mixed；不支持 default。 |
| P16. site budget | 限制每个 block/program 最多插几个 prefetch，避免 frontend/code-size 回归。 | v3 统计 program candidates，按 source/depth 排序保留 top-N；当前 N=1。 | 超过 budget 的 candidate skip。 | 扫描相同；budget 数值可能 arch-specific。 | 一个 program 有多个 candidate。 | `prefetch_packet_first_deref`、`prefetch_single_first_deref` 间接覆盖；仍可新增 stress case。 | 新增/待补 stress | v3 smoke 中 packet cases applied 1，其他 depth 0 packet load skipped。 |
| P17. profile / PMU gate | 只对 miss-prone site 插 prefetch，避免 structural-only 误判。 | `bpfopt --pass prefetch -- --profile FILE` 读取 profile JSON；map-value candidate 用 report PC 查询 allow-list 或 PMU-style metrics。 | 只有 profile 标记为 cold/miss-prone 的 site 才插。 | policy 框架相同；PMU event 和阈值 arch-specific。 | 真实 workload 显示该 load miss-prone。 | `prefetch_map_page_stride` 和 `prefetch_upper_page_stride` 已用 hand-written profile；PMU capability smoke 已跑。 | 新增 profile 文件；PMU capability smoke 已跑 | gate 已实现并通过 Rust 单测；profile-fed AWS attribution 已跑两轮。结论是 admission 可用，但即使 upper-bound case 也没有稳定 win。PMU capability smoke 显示默认 x86/ARM64 AWS micro 环境缺少 cache-miss counters，不能做 cache attribution。 |
| P18. hint variant selection | x86 `T0/T1/T2/NTA` 或 ARM64 `L1/L2/L3/SLC KEEP/STRM` 可能影响结果。 | 需要扩展 kfunc ABI 或新增 target，policy 根据 working-set/streaming 选择 hint。当前只支持 x86 `T0`、ARM64 `PLDL1KEEP`。 | 插不同 target/hint。 | 不相同，架构强相关。 | streaming、last-use、large working set 等 hint-specific 场景。 | 可复用 existing case，但需要新增 target/ABI 和 hint-variant experiment。 | 部分复用 + 新增实现 | 未测。不能在当前 ABI 下回答。 |
| P19. next-iteration / software-pipeline prefetch | 不预取当前 load，而是在第 i 轮提前预取第 i+1 轮要用的 pointer，增加 lead time。 | 当前不让 pass 合成未来地址；micro 显式维护 `cur` 和 `next` pointer，profile 用 `map_value_prefetch_points` 指定某个 PC 和 live register。 | 在 profile point 前插入 prefetch；该 point 必须位于 `next` pointer 已物化、当前轮 demand load 尚未开始的位置。 | BPF-level 机制相同；收益 arch-specific。 | loop/body 能提前计算未来 pointer，并且当前轮还有足够 independent work。 | `prefetch_pipeline_page_stride`。 | 新增 | 本地 Rust test、release build、Makefile object build 已通过。object evidence 显示 profile `pc=45, reg=1` 指向 next pointer，当前 demand load 到 local PC 68 才开始。x86 / ARM64 AWS smoke 和 5-sample stability run 已完成；两边 treatment 都 applied 1 site。第一轮 ARM64 paired geomean T/C `0.858777`，independent rerun ARM64 paired geomean T/C `0.962181`。方向复现为 treatment 更快，但幅度不稳定；x86 timing 不稳定，不能作为性能结论。 |

## 当前 v3 状态

已实现的基础规则：

```text
P0 target lowering
P1 verifier-safe insertion window
P2 pointer register stability
P3 packet pointer tracking
P4 map value first deref tracking
P5 load-only target
P6 same-cacheline dedup
P7 fixed-distance lead time
```

v3 新增和收紧：

```text
新增:
  PacketScalar tracking
  ALU32 MOV/AND/LSH dependency propagation
  dependent_load_depth admission
  per-program site budget, N=1

允许:
  P11 packet first deref final load, dependent_load_depth == 1

默认拒绝:
  address-source packet load, dependent_load_depth == 0
  dependent chain depth > 1
  P4 map value candidate without profile/PMU evidence
  same-cacheline duplicate
  over-budget candidate
```

v3 已通过 smoke：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke/report.md`
- x86：`prefetch_single_first_deref` 和 `prefetch_packet_first_deref` 各 applied 1。
- ARM64：`prefetch_single_first_deref` 和 `prefetch_packet_first_deref` 各 applied 1。
- x86/ARM64：`prefetch_map_page_stride` 都 skipped，等待 profile/PMU evidence。

v3 仍未完成：

- PMU/corpus profile 生成 pipeline。
- profile-fed map-value PMU attribution 和 independent rerun。
- hint variant selection。

其中 PMU attribution 的状态需要明确区分：

- profile gate 已实现。
- PMU-style profile 文件格式已支持。
- 默认 AWS micro 环境已确认不能提供 `cache_misses` / `cache_references` counters，因此不能在该环境里
  继续扩大 PMU attribution。
- 后续如果要做 PMU attribution，必须先解决 PMU-capable 环境；否则只做 independent rerun 和 codegen
  evidence。

## Profile gate 格式

`prefetch` pass 现在接受 pass-local profile 文件：

```bash
bpfopt --pass prefetch -- --profile /path/to/prefetch-profile.json
```

profile 可以直接列出允许 map-value prefetch 的 BPF PC：

```json
{
  "map_value_pcs": [2]
}
```

也可以保存 PMU-style metrics：

```json
{
  "min_load_misses": 10,
  "min_miss_rate": 0.10,
  "map_value_sites": [
    { "pc": 2, "load_misses": 12, "miss_rate": 0.25 }
  ]
}
```

语义：

- `pc` 是原始 BPF load PC。
- `map_value_pcs` 是外部 profile/PMU 分析已经确认可尝试 prefetch 的 PC。
- `map_value_sites` 通过 `load_misses` 或 `miss_rate` 阈值转成 allow-list。
- profile 不包含该 PC 时，map-value prefetch 仍然 skipped。

这个 gate 只解决 admission 可控性；它不等于性能结论。性能结论仍必须通过 same-LLC
profile-fed treatment/control 实验回答。

## Test Case Inventory

所有 prefetch research micro 都是本 task 新增的 synthetic-control / strategy-probe case。
它们不是 repo 原有 micro，也不是从真实 BPF program 自动提取的 real-derived case。

| case | policy coverage | source | 当前结论 |
|---|---|---|---|
| `prefetch_distance_0` | P7 | 新增 | ARM64 mixed，median `1.018957` slower。 |
| `prefetch_distance_2` | P7 | 新增 | ARM64 mixed，median `0.992762` weak faster。 |
| `prefetch_distance_4` | P7 | 新增 | ARM64 stable loss，median `1.002508`。 |
| `prefetch_distance_8` | P7 | 新增 | ARM64 mixed，median `1.0`。 |
| `prefetch_distance_16` | P7 | 新增 | ARM64 mixed，median `1.001800` slower。 |
| `prefetch_distance_32` | P7 | 新增 | ARM64 mixed，median `1.003259` slower。 |
| `prefetch_hot_l1_load` | P8 | 新增 | ARM64 mixed；应作为 skip/control。 |
| `prefetch_sequential_scan` | P9 | 新增 | ARM64 mixed；应作为 skip/control。 |
| `prefetch_large_stride_scan` | P10 | 新增 | ARM64 mixed，median `0.999614`。 |
| `prefetch_permuted_index_scan` | P12 | 新增 | ARM64 mixed/slower，median `1.003846`。 |
| `prefetch_packet_first_deref` | P11 | 新增 | ARM64 stable weak win `0.998018`；x86 timing source 不一致。 |
| `prefetch_single_first_deref` | P11, P16 | 新增 | v3 x86/ARM64 smoke applied 1；用于 selector behavior，不是 performance evidence。 |
| `prefetch_indirect_lookup` | P13 | 新增 | ARM64 mixed，median `0.997764`。 |
| `prefetch_indirect_two_stage` | P13 | 新增 | ARM64 stable loss，median `1.002285`。 |
| `prefetch_cacheline_dedup_scan` | P6 | 新增 | ARM64 mixed，median `0.999139`。 |
| `prefetch_packet_offset_guarded` | P14 | 新增 | ARM64 mixed/slower，median `1.001067`。 |
| `prefetch_full_packet_ring_scan` | P15 | 新增 | ARM64 mixed，median `0.999441`。 |
| `prefetch_map_page_stride` | P4, P10, P17 | 新增 | 无 profile时默认 skipped；profile-fed paired attribution 已跑。x86 `exec_mean` T/C `0.897679` 但 wall timing 不强；ARM64 `exec_mean` T/C `0.966154`，median T/C `0.989836`。PMU smoke 显示默认 AWS micro 环境不能提供 cache-miss attribution。 |
| `prefetch_map_indirect_page` | P4, P13 | 新增 | ARM64 slower `1.005259`。 |
| `prefetch_map_line_dedup` | P4, P6 | 新增 | ARM64 slower `1.002829`。 |
| `prefetch_upper_page_stride` | P4, P10, P17 | 新增 | Upper-bound synthetic-control case；1 MiB map value、page stride、profile PC 62、independent lead-time work。x86 paired geomean T/C `0.998018`，约 0.2% nominal speedup，方向不稳定；ARM64 `1.007389`，约 0.7% slowdown。说明 current same-iteration map-value prefetch 仍不是稳定 win。 |
| `prefetch_pipeline_page_stride` | P4, P17, P19 | 新增 | Next-iteration synthetic-control case；1 MiB map value、page stride、显式 `cur` / `next` pointer、profile point PC 45 / r1。AWS x86 / ARM64 smoke、5-sample stability run 和 independent rerun 已完成。ARM64 第一轮 paired geomean T/C `0.858777`，rerun `0.962181`；positive direction 复现但 effect size 不稳定。x86 timing 不稳定，不能作为性能结论。 |
| `prefetch_budget_many_sites` | P16 | 需要新增 | 未测。 |
| PMU/profile-gated corpus case | P17 | 需要新增 | 未测。需要先解决 PMU-capable 环境；默认 AWS micro 环境已确认缺少 cache-miss counters。 |
| hint-variant cases | P18 | 需要新增 target/ABI，case 可复用 | 未测。 |

## Experiment References

已完成实验：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-upper-bound-map-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution/report.md`

相关实现和 micro 文档：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.md`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.md`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.md`
