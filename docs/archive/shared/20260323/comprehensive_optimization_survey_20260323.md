# Comprehensive Optimization Survey for BpfReJIT (2026-03-23)

## Scope and exclusions

本次调研阅读了下列必读材料，并以 `corpus/build/` 的真实 `.bpf.o` 语料做了补充统计：

- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md`
- `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md`
- `docs/tmp/20260322/related_work_eval_analysis_20260322.md`

先说明两个边界：

- 这棵树里**没有** `fixup_bpf_calls()` 这个函数。对应逻辑被拆分到了 `convert_ctx_accesses()` 和 `do_misc_fixups()`。
- 用户已给出的已实现优化，以及已单独写过调研的 `SIMD kinsn`、`map inlining`、`verifier-assisted const propagation`、`dynamic map inlining + invalidation`，本报告只做定位，不重复展开。

已实现优化：

- `wide_mem`
- `rotate`
- `extract`
- `endian_fusion`
- `cond_select`
- `branch_flip`
- `speculation_barrier`

已单独调研、本文不重复展开：

- `SIMD kinsn`
- `Frozen map inlining`
- `Verifier-assisted constant propagation`
- `Dynamic map inlining + invalidation`

## Executive summary

结论先行：

1. **如果目标是论文核心“只有 post-load/runtime 才能做”**，最强的点仍然不是再加一个静态 peephole，而是：
   - `dynamic map specialization + invalidation`（已单独调研）
   - `tail-call direct-target specialization / inline-cache / deopt`
   - `PGO hot/cold multi-versioning`

2. **如果目标是短期工程收益**，最值得优先做的是：
   - `LFENCE/BPF_NOSPEC` 消除或 `safe_load` 风格 lowering
   - `packet bounds-window` / 冗余 bounds check 消除
   - `skb_load_bytes/xdp_load_bytes` 直接访问特化
   - const-prop/map specialization 之后的 `DCE`

3. **Spill/fill 泛化优化优先级低。**
   `verifier.c` 已经有 `mark_fastcall_patterns()` + `remove_fastcall_spills_fills()`；`KF_FASTCALL` 只影响 spill/fill 删除，不改变 verifier 的 clobber 语义。新的大收益更可能来自“helper 变 non-call kinsn”或“新增更精细的 clobber metadata”，不是再做一个通用 spill/fill peephole。

4. **Loop 方向里真正值得做的是 LICM / loop predication，不是 blanket unrolling。**
   内核已经会 inline `bpf_loop()` helper，而源码侧 `#pragma unroll` 已经很多。真正剩下的空间主要是把 invariant 的 map/config 读取和 bounds check 提到循环外。

5. **对比 K2/Merlin/EPSO 时，BpfReJIT 不应该把 generic static CP/DCE 当核心卖点。**
   `Merlin` 已明确做 `CP + DCE`，`K2` 做了 map/type/offset concretization，`EPSO` 做 offline superoptimization + rule cache。BpfReJIT 的差异点在于：
   - 不需要 `.bpf.o`
   - 能看到 verifier/fixup 后的真实 live program
   - 能利用 runtime PGO 和 live kernel state
   - 能做 invalidation / deopt

## Master table

下表按“是否需要 runtime 信息”和“是否已被 K2/Merlin/EPSO 覆盖”来整理机会。`dynamic` 这里指**pre-load 编译器拿不到必要信息，或者无法处理 live invalidation/deopt**。

| Optimization | Repo status | K2/Merlin/EPSO | Static/Dynamic | Runtime info required? | HotSpot analog | Impact | Note |
|---|---|---|---|---|---|---|---|
| Generic static const propagation + DCE | already researched separately | **Merlin done** | static | no | CCP/SCCP + DCE | high downstream | 不是 BpfReJIT 差异点 |
| Verifier-assisted const propagation | already researched separately | Merlin done (generic CP/DCE), K2 partial (offset concretization) | dynamic | yes | profile-guided speculative CP | high | 价值主要在“利用 verifier state”而非 CP 本身 |
| SIMD kinsn | already researched separately | no public evidence | static | no | SuperWord / vector intrinsics | medium-high | 主要是 XDP/TC，不是 tracing |
| Frozen map inlining | already researched separately | no public evidence | dynamic | yes | constant folding | medium | 真实生态里显式 freeze 很少 |
| Dynamic map inlining + invalidation | already researched separately | no public evidence | **dynamic** | **yes** | speculative inlining + deoptimization | **high** | 仍是最强 runtime-only 论点 |
| LFENCE/BPF_NOSPEC elimination / safe-load lowering | new | no public evidence | static | no, hotness only helps prioritize | range-check elimination / uncommon trap / intrinsic | high | 真实 barrier 插入点只有 post-verify 才能直接看到 |
| Redundant packet bounds-check elimination | new | no public evidence | static | no | range-check elimination + LoopPredication | high | XDP/TC parser 最相关 |
| Packet helper specialization: `skb_load_bytes` / `xdp_load_bytes` -> direct access | new | no public evidence | static | no | intrinsic inlining | high | 直接对 fast path 生效 |
| Narrow `probe_read_kernel` specialization | new | no public evidence | static | no | intrinsic expansion | medium | 语义风险高于 packet helper |
| Repeated map lookup CSE/cache within one invocation | new | no public evidence | static | no | CSE / load elimination | medium | 需要 alias + helper-effect 建模 |
| DCE / unreachable-block cleanup after specialization | new downstream analysis | **Merlin done** | static | no | DCE | high | 不是独立 pass，而是 specialization 的乘数 |
| Subprogram inlining | new | no public evidence | static | no | method inlining | medium-high | 需要 code-size budget |
| Spill/fill elimination beyond `KF_FASTCALL` | new | no public evidence | static | no | caller-save elimination / RA | low | 内核已有主路径优化 |
| Tail-call direct-target specialization / inline cache | new | no public evidence | **dynamic** | **yes** | inline cache + speculative inlining + deopt | **high** | 最像 HotSpot 的新方向 |
| Loop-invariant code motion / loop predication | new | no public evidence | static | no for generic LICM; yes for stable-map hoisting | LICM / LoopPredication | medium-high | 比 blanket unrolling 更值钱 |
| Bounded loop unrolling | new | compiler-standard; not a BpfReJIT-specific story | static | no | loop unrolling | low-medium | 真实收益面不大 |
| PGO hot/cold splitting and multi-versioning beyond current `branch_flip` | new | no public evidence | **dynamic** | **yes** | tiered compilation / hot-cold splitting | medium-high | 很适合作为 post-load 论文点 |
| Other low-level straight-line combines: packet/ctx wide-load, wide-store, LEA, more bit-twiddling fusions | not expanded here | K2/EPSO-like territory | static | no | peephole / superopt | medium | 值得做，但不应作为论文主贡献 |

## Why this tree inserts `BPF_NOSPEC`

先把安全屏障相关的内核事实说清楚。

### 1. `BPF_NOSPEC` 的真实插入点

`verifier.c` 中真正把 `BPF_ST_NOSPEC()` patch 进 bytecode 的不是某个 `fixup_bpf_calls()`，而是：

- `convert_ctx_accesses()`：
  - 若 `aux->nospec` 为真，则**在原指令前**插入 `BPF_ST_NOSPEC()`。
  - 若 `aux->nospec_result` 为真，则**在 write 指令后**插入 `BPF_ST_NOSPEC()`。
- 对应代码：`vendor/linux-framework/kernel/bpf/verifier.c:23252-23415`

`core.c` 里解释器把 `BPF_ST | BPF_NOSPEC` 派发到 `ST_NOSPEC`，最终调用 `barrier_nospec()`：

- `vendor/linux-framework/kernel/bpf/core.c:1762-1764`
- `vendor/linux-framework/kernel/bpf/core.c:2131-2142`

x86 JIT 把它直接降成 `LFENCE`：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:681`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2136-2138`

arm64 JIT 则降成 `SB` 或 `DSB NSH; ISB`：

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1785-1793`

### 2. `aux->nospec` 是怎么来的

`aux->nospec` 来自 speculative verification：

- `error_recoverable_with_nospec()` 只允许 `-EPERM / -EACCES / -EINVAL` 这三类 speculative-only 非致命错误通过插屏障恢复。
- 当 speculative path 上某条指令本来会触发这类错误时，verifier 把该条指令标记为 `nospec`，并阻止 speculative path 继续前进。

关键代码：

- `vendor/linux-framework/kernel/bpf/verifier.c:2110-2119`
- `vendor/linux-framework/kernel/bpf/verifier.c:22073-22097`

这意味着：

- **`nospec` 保护的是“架构执行安全，但错误投机路径不安全”的访问。**
- 所以删 barrier 的正确条件不是“architectural path 仍然安全”，而是“speculative path 也变安全了”。

### 3. `aux->nospec_result` 是怎么来的

`nospec_result` 在这棵树里只在一个地方被置位：

- `check_stack_write_fixed_off()`
- `vendor/linux-framework/kernel/bpf/verifier.c:5495-5535`

具体条件是：

- `!env->bypass_spec_v4`
- 当前 write 会覆盖：
  - spillable reg type，或
  - 不是 `STACK_MISC/STACK_ZERO` 的已类型化栈槽

这对应 Spectre v4 / type-confusion 风险，所以 verifier 在**写之后**插入 `BPF_ST_NOSPEC()`。

### 4. `sanitize_ptr_alu()` 与 `BPF_NOSPEC` 不是一回事

变量 pointer arithmetic 的 Spectre v1 处理并不是 `LFENCE`，而是 `do_misc_fixups()` 里的 masking 序列：

- `can_skip_alu_sanitation()`：`vendor/linux-framework/kernel/bpf/verifier.c:15308-15314`
- `sanitize_ptr_alu()`：`vendor/linux-framework/kernel/bpf/verifier.c:15374-15467`
- 对应 fixup：`vendor/linux-framework/kernel/bpf/verifier.c:24349-24400`

也就是说：

- `BPF_NOSPEC` 主要是“在访问点前/后加屏障”
- `sanitize_ptr_alu` 主要是“把危险的 variable ADD/SUB 重写成 masked arithmetic”

这两类机会应该分开看。

## A. Security barrier optimization: LFENCE / BPF_NOSPEC elimination

### A1. 哪些 `BPF_NOSPEC` 是不必要的

严格说，不存在“看到 barrier 就删”的安全空间；只有以下几类**通过重写后才会变得不需要**：

1. **由 `aux->nospec` 产生的 barrier，但 speculative path 可被改写为始终 in-bounds。**
   例子：
   - 把分散的小 bounds check 合成一个更宽的 dominating bounds window
   - 把 variable index 访问改写为 `mask/index_nospec` 风格
   - 把 `skb_load_bytes` 一类 helper 重写成 verifier 可直接证明安全的 direct packet access

2. **由 `aux->nospec_result` 产生的 barrier，但 write 本身可以消失。**
   例子：
   - 去掉不必要的 spill/fill
   - 把 helper call 改成 non-call kinsn，避免为了保活寄存器而 spill
   - 保持栈槽处于 `STACK_ZERO/MISC` 而不是“有类型的 spill slot”

3. **屏障保护的是冷路径，但热路径可以改写成 branchless / safe-load 形式。**
   这不改变 legality，只是把 barrier 从 hot path 上拿掉。

### A2. daemon 能否通过重构 bytecode 让 fixup pass 少插 `BPF_NOSPEC`

能，而且这是本方向真正可做的工程点。

最直接的三条路径：

1. **Bounds-window 重写**
   让后续访问的 speculative path 也被更宽的 guard 覆盖，从源头上不再触发 `error_recoverable_with_nospec()`。

2. **减少 typed stack overwrite**
   如果把某些 helper site 改成 kinsn 或 direct load，原来围绕 call 的 spill/fill 和 typed spill slot 就会消失，对应的 `nospec_result` 也可能随之消失。

3. **把 variable pointer arithmetic 改成 verifier 更喜欢的形式**
   避免 `sanitize_ptr_alu()` 触发，或缩小其 mask window；虽然这不直接删 `LFENCE`，但能减少另一类 speculation hardening 代码。

### A3. `bpf_safe_load()` 新 kinsn 是否可行

可行，而且是比“先 `if` 再 load 再 barrier”更干净的方向。

理想语义应是：

- 输入：base pointer、index/offset、width、bound
- verifier callback 保证“architectural path 和 speculative path 都只会访问 safe window”
- JIT lowering：
  - x86 可用 masked address / conditional move / carefully scheduled compare-load sequence
  - arm64 可降成更适合本架构的 safe load 序列

这相当于把“安全 contract”封装进一条 intrinsic，而不是留给 verifier 事后补 `BPF_NOSPEC()`。

### A4. `LFENCE` 的实际开销

我在当前开发机/虚拟化环境上做了一个非常小的本机微测：

- 方法：`rdtscp + lfence` 计时，空循环基线相减，CPU0 pin，500 万次迭代，10 次 run
- 结果：**`LFENCE` 约 `10.8 cycles` / 次**

这是 illustrative number，不是可发表的跨机器定值，但数量级足够说明问题：

- 按约 `3.7 GHz` 估算，约 `2.9 ns`
- 100GbE 最小包 `148.8 Mpps` 下，**每包 1 个 `LFENCE` 就约消耗 `1.6e9 cycles/s`，接近 `0.43` 个 3.7GHz 核**
- 每包 2 个 barrier 时，代价就接近 `0.86` 个核

所以在 XDP/TC hot path 上，哪怕只有 1-2 个 barrier，也完全值得优化。

### A5. hot path 上到底有多少 `LFENCE`

**当前无法从 `corpus/build/*.bpf.o` 静态回答。**

原因很简单：

- `BPF_NOSPEC` 是 verifier/fixup **post-load** 插进去的
- `.bpf.o` 里根本看不到它

所以要做 corpus-wide authoritative census，必须：

1. instrument `convert_ctx_accesses()` / `do_misc_fixups()` 统计 live 插入次数，或
2. 在 live 系统上 dump `xlated_prog_insns` / JITed image 后统计 `BPF_ST | BPF_NOSPEC`

这本身反而支持 BpfReJIT 的 post-load 视角：**只有 post-load 系统能直接看到 stock kernel 真实插了什么硬化。**

### A6. 判断

- 工程收益：**high**
- 论文 novelty：**medium**
- runtime 必要性：**不是强 runtime-only；更准确地说是 static legality + dynamic prioritization**

## B. Redundant packet bounds-check elimination

### B1. XDP/TC 中的典型 pattern

真实 packet access 的典型 verifier-friendly 形态是：

1. 取 `data` / `data_end`
2. 计算 `cursor + off + width`
3. `if cursor + off + width > data_end goto drop/slow`
4. 再做 packet load

常见变体：

- 先检查更大的 header window，再检查更小的子字段
- 在不同 parser phase 中重复 reload `data` / `data_end` 后再做一次几乎相同的 guard
- loop 或多分支 join 后重新做“已经被更强前置条件覆盖”的 guard

### B2. 哪些 check 是冗余的

真正可删的是：

- **被同一 base pointer 上更宽 window 支配的更窄 check**
- **只因为重新 materialize 了 cursor/data/data_end 而重复出现的等价 check**
- **loop 内 invariant check**

不该删的是：

- base pointer 已变
- parser 改写了 cursor 且范围信息丢失
- helper / tail call / packet mutate 之后旧 window 不再成立

### B3. daemon 该怎么识别

需要的不是局部 peephole，而是一个小 CFG + range-fact pass：

- 识别 `packet_base`, `cursor`, `data_end`
- 为每个 block 维护“已知可读窗口”事实
- 在 dominator tree 上传播 `(base, safe_end)` 之类的 retained fact
- 对候选 guard 做 subsumption 检查：
  - base 相同
  - 新 guard 覆盖旧 guard
  - 中间没有 packet-mutating helper 或可能失效的 side effect

这和 HotSpot 的 `range-check elimination` / `LoopPredication` 最接近。

### B4. corpus 影响

我对 canonical XDP/TC 语料做了保守扫描，得到两个重要结论：

- 至少有 **`151` 个 packet guard site**
  - XDP: `102`
  - TC: `49`
- 至少有 **`57` 个 XDP/TC section** 带有这类 guard
  - XDP: `35`
  - TC: `22`

但同一套保守扫描**没有发现明显的“同 basic block 内直接重复 guard”**。

这说明：

- 机会是真实存在的
- 但它不是“删掉连续两条相同 compare”的级别
- 真正的收益需要 CFG/range-aware 的 `bounds_window` pass

这也和之前的内部分析一致：`bounds_window` 是 high-value，但已经超出纯 straight-line peephole。

### B5. 判断

- 工程收益：**high**
- 论文 novelty：**medium**
- runtime 必要性：**static**

## C. Dead code elimination after const propagation / map specialization

### C1. 先说内核现状

内核 verifier 在 verification 结束后已经会做 dead-code cleanup：

- `opt_hard_wire_dead_code_branches()`
- `opt_remove_dead_code()`
- `opt_remove_nops()`

对应 pipeline：

- `vendor/linux-framework/kernel/bpf/verifier.c:26839-26869`

所以 BpfReJIT 真正应该做的不是再发明一个大 DCE pass，而是：

- 把 branch condition 变成常量
- 让 stock verifier/JIT 帮你把 dead path 清掉

### C2. const prop / map inline 后能删多少

我做了一个 **lower-bound** 统计：只看 `.rodata/.kconfig` 这类“当前值一旦已知就可折叠”的分支消费者，不去算更激进的 dynamic map specialization。

结果：

- **`445` 个程序 section** 至少包含一个可折叠 branch
- **`2167` 个 foldable branch**
- **`2165` 个 dead successor block**

这还是明显低估，因为它没有包括：

- 一般的 stable map slot specialization
- verifier-state-driven scalar const
- helper-size specialization 触发的后续折叠

### C3. 哪些程序最受益

最夸张的几个 section：

| Program section | Dead successor blocks (lower bound) |
|---|---:|
| `corpus/build/cilium/bpf_lxc.bpf.o:tc/tail` | 388 |
| `corpus/build/cilium/bpf_overlay.bpf.o:tc/tail` | 244 |
| `corpus/build/cilium/bpf_xdp.bpf.o:xdp/tail` | 205 |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o:tc` | 90 |
| `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o:kprobe/unwind_native` | 31 |

按类型看，最明显的不是 tracing，而是少数**配置驱动非常重的网络 datapath section**：

- TC hit section 平均约 `104.6` 个 dead successor / hit section
- XDP hit section 平均约 `75.0`
- probe/tracing hit section 也不少，但平均远小

### C4. 结论

- DCE 本身不新
- 但在 BpfReJIT 里，**它是 dynamic specialization 的主要 pay-off**
- 论文写法上应该把它当作“const-prop/map-inline/helper specialization 的 downstream multiplier”，而不是单独贡献

### C5. 判断

- 工程收益：**high**
- 论文 novelty：**low by itself**
- runtime 必要性：**depends on upstream specialization**

## D. Helper call optimization / inlining

### D1. 哪些 helper 已经被 kernel 自己内联了

这部分不要重复发明：

- `map_lookup_elem` 等 map helpers 已在 `do_misc_fixups()` 被 lower 到 `map_gen_lookup()` 或 `ops->map_lookup_elem`
- `bpf_jiffies64`
- `bpf_get_smp_processor_id`
- `bpf_get_current_task` / `_btf`
- tracing 里的 `bpf_get_func_arg` / `bpf_get_func_ret`

对应代码：

- map helper lowering：`vendor/linux-framework/kernel/bpf/verifier.c:24644-24737`
- inline helpers：`vendor/linux-framework/kernel/bpf/verifier.c:24743-24820`

因此新的机会不在“把 helper call 改成 direct call”，而在：

- 更强的 specialization
- 去掉后续 null/bounds/size overhead
- 把 helper 语义变成 verifier 可直接证明的 local sequence

### D2. `skb_load_bytes` / `xdp_load_bytes` -> packet direct access

这是最强的 helper-side工程机会。

当前语料统计：

- `skb_load_bytes`: **`590`** 个 call site，分布在 **`24`** 个 section
- `xdp_load_bytes`: **`7`** 个 call site，分布在 **`3`** 个 section

常见长度非常小：

- `skb_load_bytes` 常见 `20 / 8 / 40 / 14 / 2 / 4`
- `xdp_load_bytes` 常见 `14 / 20 / 40 / 10`

这说明很多 call 其实是在做：

- 固定小窗口 header copy
- 固定长度 tuple load

可替代条件：

1. 当前 prog type 已允许 direct packet access
2. 请求窗口完全落在 verifier 可证明的 `data .. data_end` 内
3. 不依赖 helper 才有的“跨非线性 skb copy”语义

一旦满足，最自然的 lowering 不是“再发一个 helper”，而是：

- direct packet load
- `wide_mem` / `extract` / `endian_fusion`
- 必要时再配合一个 `safe_load` kinsn

### D3. `bpf_probe_read_kernel` 小 size -> 直接 load

语料里量非常大：

- `probe_read_kernel`: **`25296`** 个 call site，**`368`** 个 section
- 直接常量 size 至少 **`25271`** 个
- 最常见 size：`8`, `4`, `16`, `65`, `104`, `2`, `256`

但这个方向风险也最大。

原因：

- `probe_read_kernel` 的价值不只是“读内存”，而是“**带 may-fault / recover 语义地读内核地址**”
- 直接 `LDX` 不能自动复现 helper 的 fault handling / extable 语义

所以它只适合一个**明显更窄的子集**：

- pointer provenance 已被 verifier 证明为安全内核对象
- access 不会 fault
- size 小且固定

结论：

- tracing 数量上它很大
- 但第一优先级不应高于 packet helper specialization

### D4. `map_lookup_elem`

这里不重复 map-inline 报告，只记一个定位：

- 语料里有 **`11556`** 个 `map_lookup_elem` 静态 call site
- 紧跟着的空指针判断非常常见

所以 map family 的真正空间在：

- value specialization
- null-check elimination
- DCE

而不是“重复做一遍 kernel 已经做的 map helper lowering”。

### D5. 判断

优先级从高到低：

1. `skb_load_bytes` / `xdp_load_bytes` 直接访问特化
2. `probe_read_kernel` 的**窄子集**特化
3. map family 的 dynamic specialization（已单独研究）

## E. Spill/fill elimination

### E1. 内核已经做了什么

verifier pass pipeline 里已经有：

- `mark_fastcall_patterns()`
- `remove_fastcall_spills_fills()`

相关代码：

- `vendor/linux-framework/kernel/bpf/verifier.c:19156-19293`
- `vendor/linux-framework/kernel/bpf/verifier.c:25225-25257`
- pipeline 位置：`vendor/linux-framework/kernel/bpf/verifier.c:26839-26844`

关键事实：

- `KF_FASTCALL` / `bpf_fastcall` **只**帮助删除 call 前后的 spill/fill
- verifier 的寄存器语义**没有**因此变聪明，仍然按普通 call 认为 `r0-r5` clobber

`docs/tmp/20260323/kfunc_verifier_mechanisms_20260323.md` 的结论也是这一点：

- `KF_FASTCALL` 只影响 spill/fill NOP 删除
- 不影响 verifier reg-state tracking

### E2. daemon 能否做得更好

能，但前提不是“再写一个通用 spill/fill peephole”，而是下面两种之一：

1. **把 helper call 改成 non-call kinsn**
   这样 spill 根源消失。

2. **让 verifier 知道更精确的 clobber set**
   这是 `KF_FASTCALL` 没覆盖的部分。

### E3. 和 `nospec_result` 的关系

这点很重要：

- `nospec_result` 恰好来自“覆盖 typed spill slot / spilled pointer”
- 所以删掉某些 spill，不只是少几条 load/store
- 还可能**顺带删掉 write 后面的 `LFENCE`**

也就是说，spill/fill 优化是一个**间接的 security-barrier 优化器**。

### E4. 语料判断

我之前做的保守匹配里，围绕 helper 的“对称 spill/fill”并不多，数量级只有几十对；而且很多正是 fastcall/trace/debug 风格 site。结合内核现有 fastcall pass，这一项的独立优先级应判为低。

### E5. 判断

- 工程收益：**low**
- 论文 novelty：**low**
- runtime 必要性：**static**

## F. Tail call optimization

### F1. 内核已经做了什么

`do_misc_fixups()` 会把 helper form 的 `bpf_tail_call` 改写成 `BPF_JMP | BPF_TAIL_CALL`：

- `vendor/linux-framework/kernel/bpf/verifier.c:24499-24516`

如果 verifier 已知：

- map 是 `PROG_ARRAY`
- key 是常量且未 poisoned
- 程序是 privileged + JIT

则会创建 poke descriptor，走**direct tail call**：

- `vendor/linux-framework/kernel/bpf/verifier.c:24518-24538`

否则走 generic / indirect path；对 unpriv 甚至还会额外插：

- `if index >= max_entries goto out`
- `index &= index_mask`

来避免 speculative OOB：

- `vendor/linux-framework/kernel/bpf/verifier.c:24544-24563`

x86 JIT 上：

- indirect path：`emit_bpf_tail_call_indirect()`
- direct path：`emit_bpf_tail_call_direct()`

对应：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:753-839`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:841-893`

### F2. 真实语料里有多少 tail call

canonical 语料统计：

- 总 tail call：**`537`**
- 常量 index：**`460`**，约 **`85.7%`**
- 最常见 index：`1`, `5`, `2`, `3`, `4`, `0`

按类型分布：

| Kind | Calls | Sections |
|---|---:|---:|
| `tc` | 240 | 10 |
| `probe` | 113 | 46 |
| `other` | 91 | 20 |
| `trace` | 45 | 16 |
| `xdp` | 35 | 6 |
| `lsm` | 13 | 3 |

所以：

- tail call 在 tracing 里不是零，但**网络路径最集中**
- constant-index site 已经很多，说明“固定 target specialization”并不是罕见病

### F3. 真正的新机会

现有 kernel direct tail call 只是：

- 把 `prog_array[index]` 的 runtime lookup 变成 direct patched jump

它**没有**做：

- callee body inline
- monomorphic/polymorphic inline cache
- target-side REJIT invalidation/deopt framework

所以真正的新方向是：

1. **frozen / stable `prog_array` slot -> callee inline**
2. **monomorphic tail-call inline cache**
3. **slot version change -> deopt / re-REJIT**

这和 HotSpot 最像。

### F4. tail call overhead 有多少

这棵仓库里没有 authoritative 的 isolated tail-call microbench，所以我不建议写一个虚假的定值。

但从 emitted x86 sequence 可以清楚看出：

- indirect tail call 至少有：
  - index bounds check
  - tail-call-count check
  - `array->ptrs[index]` load
  - null check
  - count increment
  - indirect jump
- direct tail call 删掉了：
  - map slot load
  - null check
  - index-bounds path的大部分开销
  但仍保留 tail-call-count 检查和 patch geometry

因此可合理判断：

- **indirect tail call 是“明显的 tens-of-cycles 级别开销”**
- **direct tail call 能省掉最关键的 memory-indirection/null-check 部分**

如果做 callee inline / IC，理论上还能继续消掉：

- caller/callee 边界
- target dispatch
- 某些后续 guard / repeated map load

### F5. 为什么这是 runtime-only

因为 pre-load 编译器不知道：

- live `prog_array` 当前填了哪个 target
- 哪些 slot 长期稳定
- target program 之后会不会被 REJIT

更关键的是，**invalidation/deopt 只会在 live map update / live target replacement 时发生**。

`docs/tmp/20260322/tail_call_rejit_research_20260322.md` 已明确指出：

- indirect tail call 会自动看到新 `bpf_func`
- direct tail call 的 caller 需要 repoke / refresh

这就是 HotSpot inline-cache invalidation 的内核版。

### F6. 判断

- 工程收益：**high**
- 论文 novelty：**high**
- runtime 必要性：**dynamic**

## G. Loop optimization

### G1. 先看 kernel 已有能力

内核 verifier 已经会 inline `bpf_loop()` helper：

- `inline_bpf_loop()`：`vendor/linux-framework/kernel/bpf/verifier.c:25088-25162`
- `optimize_bpf_loop()`：`vendor/linux-framework/kernel/bpf/verifier.c:25180-25222`

也就是说，对 `bpf_loop()` 这个 helper，本身已经不是空白区。

### G2. 真实语料里的 loop 信号

当前 canonical 语料中，`bpf_loop()` helper 总量并不大：

| Kind | Calls | Sections |
|---|---:|---:|
| `other` | 34 | 7 |
| `tracing` | 10 | 5 |
| `xdp` | 2 | 2 |
| `tc` | 2 | 2 |
| `trace` | 1 | 1 |

再结合前一份单独调研：

- 源码里 `#pragma unroll` 出现 **`79`** 次
- `bpf_loop()` source-level 只出现 **`4`** 次

所以 blanket unrolling 不是最值得先做的事。

### G3. 真正值得做的 loop 方向

1. **LICM**
   - 把 stable config/map lookup 提到循环外
   - 把 invariant helper-size、header bound、constant gate 提到循环外

2. **Loop predication / bounds hoisting**
   - 把多次 packet guard 合成一次 loop-entry guard

3. **小 trip-count 的 selective unrolling**
   - 只在 trip count 极小且 hot 时做
   - 否则很容易踩 I-cache cliff

### G4. 判断

- LICM / predication：**medium-high**
- blanket unrolling：**low-medium**
- runtime 必要性：
  - generic LICM：**static**
  - hoist stable map/config out of loop：**dynamic if values/stability are runtime-derived**

## Other non-focus opportunities

### 1. Repeated map lookup CSE / intra-invocation caching

这和 dynamic map inlining 不同：

- 它不需要跨 invocation 记住值
- 只是在同一次程序执行里，消掉“同 map、同 key、无 intervening update”的重复 lookup

它更像 compiler CSE，不是论文最强点，但可以作为 static optimization 家族的一部分。

### 2. Subprogram inlining

HotSpot 有 method inlining，BPF 也有等价物：`BPF_PSEUDO_CALL` / bpf-to-bpf call 展开。

优点：

- 去掉 call/ret
- 暴露更多 local combine / bounds / DCE 机会

缺点：

- code-size budget 非常重要
- tail-call/bpf2bpf/may-fault/trampoline 交互复杂

它更像 static optimizer 机会，不是最强 runtime-only 贡献。

### 3. PGO hot/cold splitting and multi-versioning

这比当前已有的 `branch_flip` 更进一步：

- 基于 live profile 划分 hot path / cold path
- 对同一程序保留 generic 与 specialized 两个版本
- 只在 hot path 上承受 aggressive specialization 的 code-size 成本

这和 HotSpot 的 tiered compilation / hot-cold splitting 更接近，也是很好的 post-load 论证点。

## HotSpot mapping

### 1. JVM HotSpot 中有、BPF 中可映射的优化

| HotSpot concept | BPF/BpfReJIT mapping | Feasible? | Comment |
|---|---|---|---|
| Tiered compilation (`C1 -> C2`) | stock load-time JIT -> post-load REJIT optimized image | yes | 最自然的总体类比 |
| Intrinsics | helper -> kinsn / direct packet access / safe-load intrinsic | yes | `skb_load_bytes` 等最像 |
| Range-check elimination | packet bounds-window elimination | yes | XDP/TC 主战场 |
| Loop predication | loop-entry packet/window guard hoisting | yes | 比 blanket unroll 更值钱 |
| LICM | hoist invariant map/config/bounds out of loop | yes | 需要 retained facts |
| Method inlining | subprog inline | yes | 但要控 code size |
| Inline cache | stable `prog_array` slot -> direct tail-call target patch | yes | 最强对应物 |
| Polymorphic inline cache | small set of hot tail-call targets -> jump cache | maybe | 未来方向 |
| Deoptimization | map/prog_array/version change -> revert generic image or re-REJIT | yes | 但只在 invocation 边界 |
| Uncommon trap | cold/speculative path stay generic; assumption fail -> swap back | yes | 需要 baseline image |
| On-stack replacement | running frame mid-loop swap | mostly no | BPF 程序太短，且无 managed stack translation |

### 2. `C1 -> C2` 在 BPF 中怎么映射

我建议论文里这样写最稳：

- **Baseline tier (`C1`)**：
  - verifier + stock arch JIT 生成的普通 live image
- **Optimized tier (`C2`)**：
  - daemon 收集 profile / live state 后，通过 `REJIT` 生成 specialized image

区别于 JVM 的地方：

- 没有通用 managed runtime
- 没有 safepoint + stack-state translation
- deopt 只能在**下一次程序进入**时生效，而不是当前 frame 中途跳回解释器

但这反而简化了实现：

- 只需保留 generic baseline image
- 假设失效时，原子换回 baseline 或重新 REJIT
- 不做 mid-execution state reconstruction

### 3. deoptimization / uncommon trap 怎么实现

在 BPF 里最实际的做法不是“trap 到解释器”，而是：

1. 保留一份 generic baseline
2. specialized image 附带 guard / version 假设
3. 假设失效时：
   - 由外部事件触发 invalidation，例如 map update、prog_array update、target REJIT
   - daemon 重新 REJIT，或直接 swap 回 generic image

对 BPF 来说，最自然的 deopt 触发源就是：

- config/policy map 版本号变化
- `prog_array` slot 变化
- hotness 画像变化

### 4. inline cache / polymorphic dispatch 的 BPF 对应物

helper call 没有太强的 IC 意义，因为 helper ID 本来就是静态的。

真正的对应物是：

- **tail call via `prog_array`**

对应关系：

- monomorphic slot: direct patched target
- polymorphic slot: few-hot-target jump cache
- megamorphic slot: 回退 generic indirect tail call

这比 map inlining 还更像 HotSpot call-site optimization。

## Runtime necessity analysis

### Truly dynamic, only a post-load framework can do

1. **Dynamic map inlining + invalidation**
   - pre-load 看不到 live map contents 和 update frequency
   - 无法处理 invalidation / deopt

2. **Tail-call direct-target specialization / inline cache**
   - pre-load 不知道 live `prog_array` membership
   - 无法在 target REJIT/map update 后 repatch callers

3. **PGO hot/cold splitting and multi-versioning**
   - 依赖 live hotness / branch frequency / deployment-specific skew

4. **Version-based stable-map null-check elimination**
   - 依赖 live value stability 与更新节奏，不是 `.bpf.o` 本身能告诉你的

### Static in principle, but a post-load daemon still helps

1. **LFENCE/BPF_NOSPEC elimination**
   - legality 主要是 static
   - 但只有 post-load 才能直接看到 verifier 真正插了哪些 barrier

2. **Bounds-window elimination**
   - static CFG/range 问题
   - post-load 的优势是 transparent，不需要 `.bpf.o`

3. **Helper specialization**
   - `skb_load_bytes/xdp_load_bytes` 等大体是 static
   - post-load 优势仍然是“对 live program 透明生效”

4. **LICM / subprog inline / bounded unroll / spill-fill**
   - 本质都是 static compiler 问题
   - 不应当作为 BpfReJIT 论文核心论点

### What this means for the paper

如果要突出“为什么不是再做一个 pre-load optimizer”，应该把重心放在：

- live verifier/fixup visibility
- runtime PGO
- invalidation/deopt
- no-`.bpf.o`, transparent optimization of already loaded programs

而不要把重心放在：

- generic static CP/DCE
- 再多一个 straight-line peephole
- blanket loop unrolling

## Comparison with K2 / Merlin / EPSO

### What they already cover

- **K2**
  - map/helper semantics modeling
  - map type concretization
  - memory offset concretization
  - offline superoptimization

- **Merlin**
  - constant propagation
  - dead code elimination
  - instruction merging / strength reduction

- **EPSO**
  - offline superoptimization
  - rule discovery + rule cache reuse

### What remains clearly BpfReJIT-specific

1. **observe actual verifier hardening**
   - `BPF_NOSPEC`
   - ptr-alu sanitization fixups
   - direct vs indirect tail-call lowering

2. **optimize without `.bpf.o`**

3. **specialize against live kernel state**
   - map value stability
   - `prog_array` membership
   - deployment-specific hotness

4. **deopt / invalidate specialized code**

这四点里，最有论文价值的是第 3 和第 4。

## Priority recommendation

### Best engineering ROI

1. `LFENCE/BPF_NOSPEC elimination` + `safe_load` design
2. `bounds_window` for XDP/TC
3. `skb_load_bytes` / `xdp_load_bytes` specialization
4. const-prop / map specialization 后的 DCE integration
5. loop LICM / predication

### Best paper-core runtime-only story

1. `dynamic map inlining + invalidation` (already separately studied)
2. `tail-call inline cache / direct-target specialization / deopt`
3. `PGO hot/cold multi-versioning`

### Low-priority / weak story

1. generic spill/fill elimination
2. blanket loop unrolling
3. generic static CP/DCE 作为“新贡献”

## Bottom line

如果只问“下一步最值得做什么”，我的结论是：

- **短期工程优先做**：`LFENCE/BPF_NOSPEC` 消除、`bounds_window`、packet helper specialization。
- **论文核心优先做**：在已单独研究过的 dynamic map specialization 之外，再把 **tail-call inline cache / deopt** 和 **PGO multi-versioning** 做出来。

这两条线组合起来，才能同时回答：

- “为什么 BpfReJIT 在工程上有收益？”
- “为什么这不是 K2/Merlin/EPSO 那类 pre-load optimizer？”
