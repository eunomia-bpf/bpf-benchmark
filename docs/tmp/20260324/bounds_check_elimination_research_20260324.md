# #442 冗余 Bounds Check 消除调研与设计报告

日期：2026-03-24  
任务：#442 冗余 bounds check 消除  
上下文入口：`docs/kernel-jit-optimization-plan.md`  
相关任务：#433 `LFENCE/BPF_NOSPEC` 消除、#434 全面优化调研

## TL;DR

- Linux verifier 对 direct packet access 的核心抽象不是“header parser”，而是 `PTR_TO_PACKET{id,off,range}`。真正决定一个 load/store 能否被接受的是 `check_packet_access()` 对 `reg->range` 的检查，而 `reg->range` 主要由 `find_good_pkt_pointers()` 在 packet-vs-`data_end` compare 上建立。
- 对 `cilium` / `katran` / `xdp-tools` 在 corpus 中出现的全部 XDP/TC text section 做静态扫描后，我识别到 **22 个 section / 42 个 direct packet bounds-check site**。其中：
  - `cilium`: 6 sections, 17 guards
  - `katran`: 1 section, 11 guards
  - `xdp-tools`: 15 sections, 14 guards
  - `xdp`: 18 sections, 36 guards
  - `tc`: 4 sections, 6 guards
- 用“同一 packet root + 支配 + 无 invalidation + 可比较窗口被包含”的**严格删除标准**做 lower-bound 统计，**可直接删除的冗余 guard = 0 / 42 = 0%**。
- 但这不代表 #442 没价值。相反，**35 / 42 = 83.3%** 的 guards 落在 **6 个多窗口 guard ladder section** 中，典型窗口序列是：
  - Katran `balancer.bpf.o:xdp`: `14 -> 34 -> 54`
  - Cilium `bpf_xdp.bpf.o:xdp/entry`: `14 -> 34 -> 35 -> 36 -> 38 -> 40 -> 44 -> 54`
  - xdp-tools `xdp_forward.bpf.o:xdp`: `14 -> 34 -> 54`
- 结论：**#442 的主路线不该是“删掉重复 compare”型 peephole，而应该是“bounds-window merge / guard hoisting”**。也就是把一串 phase-local 小窗口检查，合并成一个更宽、支配后续访问的窗口检查，然后删掉内部 guards。

## 调研范围与方法

我读了以下代码和文档：

- `docs/kernel-jit-optimization-plan.md`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/net/core/filter.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `runner/repos/cilium/...`
- `runner/repos/katran/...`
- `runner/repos/xdp-tools/...`

我另外写了一个一次性静态扫描脚本：

- 扫描脚本：`docs/tmp/20260324/bounds_guard_scan.py`
- 扫描结果：`docs/tmp/20260324/bounds_guard_scan_20260324.json`

扫描对象是 `macro_corpus.yaml` 中属于 `cilium` / `katran` / `xdp-tools` 的 unique object file，再展开这些 object 里的全部 `xdp*` / `tc*` text section。扫描器只统计 **direct packet access 风格** 的 guard，也就是 BPF bytecode 里“packet pointer 和 `data_end` 比较”的 site。像 `bpf_xdp_load_bytes()` 这种 helper-based access 不算在这个 pattern 内。

我把两个指标分开统计：

1. **Strict redundant rate**  
   定义：已有 dominating window 能在所有到达路径上证明后续 guard 的可读窗口，且中间无 packet-root invalidation。满足时可直接删除后者。

2. **Mergeable ladder rate**  
   定义：同一 section 内出现多个不同窗口大小的 packet guard，说明存在“guard chain / bounds ladder”结构。这类点未必能直接删除，但很适合做 guard merge。

## 1. BPF 中 bounds check 的 bytecode pattern

### 1.1 verifier 真正看的是什么

`__check_mem_access()` 的判断很直接：只要 `off >= 0` 且 `off + size <= mem_size` 就放行，否则拒绝，packet case 会报 `invalid access to packet`（`vendor/linux-framework/kernel/bpf/verifier.c:6328-6360`）。

对 packet pointer，`check_packet_access()` 不直接重新推理整个表达式，它依赖当前寄存器上已有的 `reg->range`：

- `reg->smin_value < 0` 直接拒绝
- `reg->range < 0` 或 `__check_mem_access(..., reg->range, ...)` 失败则拒绝  
见 `vendor/linux-framework/kernel/bpf/verifier.c:6819-6845`

所以，packet bounds check 的本质不是“出现了某条 if”，而是：

- 某个 compare 让 verifier 为一个 `PTR_TO_PACKET` root 建立了 `range`
- 后续 packet load/store 在这个 `range` 内

### 1.2 `find_good_pkt_pointers()` 给出了 canonical pattern

`find_good_pkt_pointers()` 明确写了 verifier 接受的 packet-guard 形态（`vendor/linux-framework/kernel/bpf/verifier.c:17070-17142`）：

```c
r2 = r3;
r2 += 8;
if (r2 > pkt_end) goto exception;
// or
if (pkt_end >= r2) goto access_ok;
```

它会把 root 寄存器 `r3` 标成：

- `r3=pkt(..., r=8)`，表示 `[r3, r3 + 8)` 可读
- 或对 `<` / `>=` 这类 right-open 关系记成 `8+1`

这意味着 canonical bytecode pattern 可以统一成：

1. materialize `data`
2. materialize `data_end`
3. 派生 `cursor = data + window_end`
4. `if cursor > data_end goto slow`  
   或反向写成 `if data_end >= cursor goto fast`
5. 在 fast path 内做 `*(u8/u16/u32/u64 *)(data + off)` / `*(...)(cursor0 + off)`

### 1.3 `try_match_pkt_pointers()` 规定了哪些 compare 会被认可

`try_match_pkt_pointers()` 只接受 pointer-vs-pointer 的比较，而且必须是 64-bit compare，不接受 `JMP32`（`vendor/linux-framework/kernel/bpf/verifier.c:17730-17824`）。它覆盖了 4 组关系：

- `pkt > pkt_end`
- `pkt < pkt_end`
- `pkt >= pkt_end`
- `pkt <= pkt_end`

以及左右操作数交换后的形式。

这决定了 source-level 上看似不同的写法，在 verifier 里其实都会归一到同一个“建立 readable window”的机制。

### 1.4 常见 bytecode 形态

| Source-level 形态 | 典型 bytecode | verifier 记住的窗口 |
|---|---|---:|
| `if (data + 14 > data_end) drop;` | `r1 = data; r1 += 0xe; if r1 > data_end goto drop;` | `14` |
| `if (iph + 1 > data_end) drop;` | `r3 = data; r3 += 0x22; if r3 > data_end goto drop;` | `34` |
| `if (ip6h + 1 > data_end) drop;` | `r3 = data; r3 += 0x36; if r3 > data_end goto drop;` | `54` |
| `if (cursor + 1 > data_end) drop;` | `r1 = data + off; r1 += 1; if r1 > data_end goto drop;` | `off + 1` |

### 1.5 负索引与变量 offset 的限制

`check_packet_access()` 和 `check_mem_region_access()` 都要求最小值不能是负数，否则 verifier 会要求先做 `if (index >= 0)` 风格的 guard（`vendor/linux-framework/kernel/bpf/verifier.c:6383-6397`, `6830-6837`）。

这意味着一切“删 guard”的重写都必须保证：

- packet root 没变
- variable offset 的区间没放宽到负数
- verifier 仍能在访问点看到同样或更强的 `reg->range`

## 2. 什么是“冗余 bounds check”

### 2.1 严格定义：可删除的冗余 guard

设后续访问点为 `A`，候选 guard 为 `G2`，先前 guard 为 `G1`。若满足：

1. `G1` 的 fast edge 支配 `G2`
2. `G1` 和 `G2` 绑定到**同一个 packet root**  
   直观上：同一次 `ctx->data` lineage，同一个 verifier `id`
3. `G1` 建立的 readable window `W1` 覆盖 `G2` 所需窗口 `W2`
4. 从 `G1` 到 `G2` 之间没有让 packet proof 失效的操作  
   例如：
   - `tail_call`
   - `xdp_adjust_head/meta/tail`
   - `skb_pull_data` / `ctx_pull_data`
   - 其他 `bpf_helper_changes_pkt_data()` 判定为 packet-changing 的 helper
5. 删除 `G2` 不改变可见语义  
   例如不能跨过 map update / trace / 统计 side effect 去 hoist

则 `G2` 是**strict redundant**，可以直接删除。

### 2.2 nested protocol headers 的 guard 不是天然冗余

经典 parser 会按 header phase 扩大窗口：

- Ethernet: `14`
- IPv4: `34`
- IPv6: `54`
- TCP/UDP: 再往后

这些 check 看起来“重复”，但通常不是 strict redundant：

- `14` 不是 `34` 的冗余  
  因为没有先过 `14`，你连 `eth->h_proto` 都读不了，无法知道该走 IPv4 还是 IPv6。
- `34` 和 `54` 也不是互相冗余  
  它们处在互斥分支里，分别对应 IPv4 / IPv6。

真正的问题不是“重复 compare 文本”，而是：

- 一个 parser phase 已经进入了 side-effect-free 的局部区域
- 后续几个小 guard 只是逐步扩张同一个窗口
- 这些 guard 可以被一个更宽的 dominating window 合并

### 2.3 本任务里要区分两类机会

1. **Delete opportunity**  
   已有更强证明，后续 guard 纯属重复，可以删。

2. **Merge opportunity**  
   后续 guards 本身不是重复，但能在该 phase 的入口合并成一个更宽窗口。

我认为 #442 的价值主要在第二类。

## 3. Corpus 统计：Cilium / Katran / xdp-tools

### 3.1 总体结果

对这三个 family 的全部 XDP/TC text section 静态扫描，结果如下：

| Scope | Sections | Guards | Strict redundant | Strict redundancy rate |
|---|---:|---:|---:|---:|
| All scanned XDP/TC sections | 22 | 42 | 0 | 0.0% |
| XDP only | 18 | 36 | 0 | 0.0% |
| TC only | 4 | 6 | 0 | 0.0% |

按 family 分：

| Family | Sections | Guards | Strict redundant |
|---|---:|---:|---:|
| Cilium | 6 | 17 | 0 |
| Katran | 1 | 11 | 0 |
| xdp-tools | 15 | 14 | 0 |

### 3.2 top sections

| Section | Guards | Window pattern |
|---|---:|---|
| `corpus/build/katran/balancer.bpf.o:xdp` | 11 | `14, 34, 54` repeated |
| `corpus/build/cilium/bpf_xdp.bpf.o:xdp/entry` | 10 | `14, 34, 35, 36, 38, 40, 44, 54` |
| `corpus/build/xdp-tools/xdp_flowtable.bpf.o:xdp` | 5 | `14, 38, 54, 58, 74` |
| `corpus/build/cilium/bpf_lxc.bpf.o:tc/entry` | 3 | `14, 14, 34` |
| `corpus/build/cilium/bpf_overlay.bpf.o:tc/entry` | 3 | `14, 14, 34` |
| `corpus/build/xdp-tools/xdp_forward.bpf.o:xdp` | 3 | `14, 34, 54` |

### 3.3 strict redundancy: lower bound = 0%

用“支配 + 同 root + 无 invalidation + 窗口 subsumption”的严格标准扫下来，**没有直接可删的 guard**。

这和我此前从更大 corpus 得到的观察是一致的：真实 packet parser 很少出现“同 basic block 内连续两条完全重复的 compare”。它们的 shape 更接近：

- phase-by-phase 扩窗
- 分支内协议特化
- option/extension header 的小步推进

也就是说，**strict delete 是稀有机会**。

### 3.4 merge opportunity: 83.3%

虽然 strict delete 是 0，但 **6 个 section** 呈现明确的 multi-window ladder，共覆盖 **35 / 42 = 83.3%** 的 guards：

| Section | Guards in ladder | Distinct windows |
|---|---:|---|
| `cilium/bpf_lxc.bpf.o:tc/entry` | 3 | `14, 34` |
| `cilium/bpf_overlay.bpf.o:tc/entry` | 3 | `14, 34` |
| `cilium/bpf_xdp.bpf.o:xdp/entry` | 10 | `14, 34, 35, 36, 38, 40, 44, 54` |
| `katran/balancer.bpf.o:xdp` | 11 | `14, 34, 54` |
| `xdp-tools/xdp_flowtable.bpf.o:xdp` | 5 | `14, 38, 54, 58, 74` |
| `xdp-tools/xdp_forward.bpf.o:xdp` | 3 | `14, 34, 54` |

这说明 #442 真正应优化的是 **bounds-window ladder**。

### 3.5 为什么有些程序是 0 guard

例如 `xdp_load_bytes.bpf.o` 这类程序使用的是 helper-based access（比如 `bpf_xdp_load_bytes()`），其安全性不是靠 direct packet compare + `reg->range` 建立的，所以不属于这次统计的 direct packet guard pattern。

这也意味着：

- #442 主要覆盖 direct packet access parser
- helper specialization / inline 是另一条优化线

## 4. 消除算法设计

## 4.1 设计目标

对 #442，我建议 pass 的目标不是“全局 DCE 某类 compare”，而是：

- 在 verifier-friendly 的 packet parser 子图里，识别一个 **dominating readable window**
- 删除其覆盖的后续 guard，或把一串 guards 合并成一个 guard
- 保持 verifier 可接受
- 保持原程序的 fast/slow path 语义与 side effect 次序

## 4.2 抽象域

对每个寄存器维护以下抽象：

- `packet_root`：该指针来自哪次 `ctx->data` / `skb->data`
- `packet_end_root`
- `offset_expr`：`const` 或 `affine(sym, scale, const)`  
  例如：
  - `14`
  - `34`
  - `22 + 4 * ihl`
- `packet_epoch`：packet-changing helper / tail call / `ctx_pull_data` 之后 epoch 失效

对每个 CFG 节点维护 must-facts：

- `Readable(root, expr)`

语义是：在该点的所有到达路径上，`root + expr` 之前的字节都被 verifier 证明可读。

## 4.3 分析流程

### Step 1: CFG + dominator tree

先在 section 级别建 CFG，算：

- dominator tree
- postdominator / exit block
- side-effect region 边界

这个阶段只做结构分析，不碰 bytecode。

### Step 2: packet-root recovery

识别：

- `ctx->data` / `ctx->data_end`
- `skb->data` / `skb->data_end`
- register copy / const add / affine add
- packet-changing helper 后的 root invalidation

直接对齐 verifier 的思路：

- 能和 `PTR_TO_PACKET_END` 比较的，只能是同一 root lineage 的 packet pointer
- 一旦 `clear_all_pkt_pointers()` 语义触发，旧 proof 不可再用  
  参考 `vendor/linux-framework/kernel/bpf/verifier.c:11005-11014`, `12158-12159` 与 `vendor/linux-framework/net/core/filter.c:8099-8125`

### Step 3: interval analysis

这是为了支持 Cilium 这类 variable-header parser。

只靠 const window 不够，必须对 `ihl` / option len / extension-header len 做区间分析：

- `iph->ihl & 0xf` + `if ihl < 6` 可推出 `ihl in [6, 15]`
- `window = 22 + 4 * ihl`
- 若后续 guard 只需要 `23` / `24` / `22 + k`，则 `22 + 4 * ihl` 可以 subsume 它们

建议 production pass 至少支持：

- const
- `const + sym`
- `const + scale * sym`
- 比较后的区间 refinement

## 4.4 删除条件

对 guard `G`：

1. 恢复其 `root` 和 `window_expr`
2. 查询 `IN(block_of_G)` 上是否已有 `Readable(root, dominating_expr)`
3. 若 `dominating_expr >= window_expr` 且：
   - 中间无 packet invalidation
   - 无可见 side effect 需要 guard 保持原位置
   - 删除 guard 不改变 slow-path 可观察行为
4. 则直接删 `G`

这是 strict delete 模式。

## 4.5 合并条件

若 strict delete 不成立，但在同一个 side-effect-free parser region 内存在：

- 同 root 的多个 guards
- 它们共同保护一组后续 load
- 这些 load 的最大 byte extent 可计算为 `max_window`

则：

1. 找到 region entry 的 common dominator
2. 在入口插入一个 guard：`if root + max_window > data_end goto slow`
3. 删掉 region 内的较小 guards
4. 保持 slow block 不变

这是 #442 更应该做的主模式。

## 4.6 替换策略

推荐按如下优先级：

1. **Delete**
   最稳妥，收益来自删 compare/jcc。

2. **Merge within region**
   把多条小 guard 变成一条大 guard。

3. **Do nothing**
   对 root 不清楚、interval 不可比、跨 side effect 的 site fail-closed。

## 4.7 side-effect 约束

合并不能跨过这些点：

- map update / map delete
- trace / perf event / notify
- packet-changing helper
- tail call
- `ctx_pull_data` / `xdp_adjust_*`

原因不是 verifier，而是**语义保持**。  
例如把 guard 提前到一个 map counter 更新之前，可能改变短包的统计行为。

## 4.8 实现建议

按风险分三阶段：

### Phase 1: constant-window merge/delete

- 只支持 const window
- 只在 side-effect-free 直线/小 CFG region 内做
- 先覆盖：
  - Katran `14/34/54`
  - xdp-tools `14/34/54`
  - Cilium `14/34`

### Phase 2: affine + interval

- 支持 `22 + 4*ihl` / `22 + opt_len` 型 window
- 覆盖 Cilium XDP option parser 这种真实复杂 case

### Phase 3: verifier-state assisted

- 若需要更高命中率，可消费 verifier log level 2 或 retained facts
- 但不是首版必需

## 5. Verifier 接受性：删掉后会不会拒绝？能否合并而不是删除？

## 5.1 不保留 proof basis 的删除会被 verifier 拒绝

答案是：**会。**

因为 direct packet access 最终还是走 `check_packet_access()`，它只认 `reg->range`（`vendor/linux-framework/kernel/bpf/verifier.c:6819-6845`）。如果你把建立 `reg->range` 的最后一个 guard 删掉，而前面没有留下一个同 root、同 path、足够宽的 dominating guard，那么后续 packet load 会在 re-verify 时直接报错。

## 5.2 什么时候删除仍会被接受

只要 verifier 还能在访问点看到完全等价或更强的 `reg->range`，删除是可以被接受的。

等价地说，必须满足：

- 同 root / 同 verifier packet id lineage
- 访问点前 `Readable(root, W_dom)` 仍在
- `W_dom` 覆盖原 guard 的窗口
- 中间无 `clear_all_pkt_pointers()` 语义

## 5.3 为什么 invalidation 很重要

一旦 helper 会改变 packet data，verifier 会 clear 旧 packet pointers。

关键点：

- `bpf_helper_changes_pkt_data(func_id)` 决定某 helper 是否 packet-changing  
  见 `vendor/linux-framework/kernel/bpf/verifier.c:12158-12159`
- 其判定列表在 `vendor/linux-framework/net/core/filter.c:8099-8125`
- 触发后 verifier 会 `clear_all_pkt_pointers()`  
  见 `vendor/linux-framework/kernel/bpf/verifier.c:11005-11014`

所以：

- `xdp_adjust_head/meta/tail`
- `skb_pull_data`
- `tail_call`

之后，旧的 packet-window proof 一律不能继续复用。

## 5.4 “合并而不是删除”通常更现实

因为 strict redundancy 在真实 corpus 里很少见，**merge 比 pure delete 更可行**。

只要新的 merged guard：

- 放在同一 parser phase 的入口
- 建立更宽窗口
- 不跨 invalidation
- 不跨可见 side effect

那么 verifier 一般是愿意接受的，因为它看到的是“更早建立了更大的 `reg->range`”。

换句话说：

- **delete** 依赖“已有证明”
- **merge** 依赖“换一种仍 verifier-friendly 的证明布局”

## 6. Case study

## 6.1 Katran `balancer.bpf.o:xdp`

Source:

- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:1084-1127`
- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:681-760`
- `runner/repos/katran/katran/lib/bpf/pckt_parsing.h:455-511`
- `runner/repos/katran/katran/lib/bpf/pckt_parsing.h:91-139`

对应 disassembly 中最明显的 triplet 是：

- insn `6`: `if r1 > r8 goto ...`，窗口 `14`
- insn `45`: `if r3 > r2 goto ...`，窗口 `34`
- 同一 section 里还会反复出现 `54` 字节窗口 site（扫描结果中的代表点是 insn `169` / `1160` / `1861`）

从源码看，这三层窗口正对应：

1. `data + sizeof(struct ethhdr) > data_end`
2. `iph + 1 > data_end`
3. `ip6h + 1 > data_end`

这组 guards **不是 strict redundant**：

- `14` 必须保留，否则连 `eth->h_proto` 都读不了
- `34` / `54` 在 IPv4 / IPv6 互斥分支里

但它非常适合当作 #442 的“mergeable ladder”教学样例：

- 结构清楚
- 窗口全是常量
- verifier-friendly
- 适合做 Phase 1 constant-window pass

## 6.2 Cilium `bpf_xdp.bpf.o:xdp/entry`

Source:

- `runner/repos/cilium/bpf/bpf_xdp.c:312-361`
- `runner/repos/cilium/bpf/lib/common.h:105-123`
- `runner/repos/cilium/bpf/lib/ip_options.h:61-164`

Disassembly 里有一条更有代表性的 ladder：

- `14`
- `34`
- `35`
- `36`
- `38`
- `40`
- `44`
- `54`

其中 `35/36/38/40/44` 来自 IPv4 option / tracing option 的逐字节推进；对应源码里是 `trace_id_from_ctx()` / `trace_id_from_ip4()` 这一条解析链。  
这一类 case 的特点是：

- 不是简单的 fixed-header parser
- 需要 interval analysis 才能证明一个更宽窗口涵盖一串小 guard

所以 Cilium XDP entry 是 Phase 2 的理想验证对象。

## 7. 和 #433 LFENCE/BPF_NOSPEC 的关系

关系非常直接，但不能混为一谈。

### 7.1 verifier 什么时候插 `nospec`

在 speculative path 上，如果某条指令“本来会错，但可以靠 nospec 恢复”，verifier 会把 `insn_aux->nospec = true`（`vendor/linux-framework/kernel/bpf/verifier.c:21822-21845`）。

之后在 fixup 阶段，它会把目标指令 patch 成：

- `BPF_ST_NOSPEC()`
- 原指令  
见 `vendor/linux-framework/kernel/bpf/verifier.c:23077-23096`

解释器执行 `BPF_ST | BPF_NOSPEC` 时会调用 `barrier_nospec()`（`vendor/linux-framework/kernel/bpf/core.c:2141-2146`），x86 JIT 会把它降成 `LFENCE`（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2134-2137`）。

### 7.2 #442 为什么能帮 #433

如果把多个小 packet guard 合并成一个更宽、支配后续访问的 window，那么：

- speculative path 更不容易在中途触发 recoverable error
- verifier 可能不再需要给后续 packet load 前插 `BPF_NOSPEC`

也就是说：

- **#442 优化的是 safety proof 布局**
- **#433 优化的是 proof 不够干净时 verifier/JIT 不得不补进去的 barrier**

## 7.3 但静态 `.bpf.o` 看不到真实 LFENCE

这一点很重要：

- bounds check 在 `.bpf.o` 里可见
- `BPF_NOSPEC` / `LFENCE` 是 post-load verifier/JIT patch 结果

所以：

- #442 的 corpus 统计可以静态做
- #433 的 authoritative census 必须在 live xlated / JIT image 上做

结论是：

- #442 和 #433 共享一个根因：proof fragmentation
- 但二者的测量层次不同

## 8. 结论与建议

## 8.1 结论

1. verifier 接受 packet access 的关键是 `reg->range`，不是 source-level parser 结构。
2. 在 `cilium` / `katran` / `xdp-tools` 的 XDP/TC corpus 中，我识别到 **42** 个 direct packet guards。
3. 用严格删除标准统计，**冗余率 lower bound = 0%**。
4. 但 **83.3%** 的 guards 落在 multi-window ladder section 中，说明机会主要是 **merge/hoist**。
5. 因此 #442 的正确工程定义应是：  
   **bounds-window merge + selective redundant-guard delete**  
   而不是纯 delete pass。

## 8.2 推荐落地路径

1. 先做 Phase 1：constant-window merge/delete  
   目标 section：
   - `katran/balancer.bpf.o:xdp`
   - `xdp-tools/xdp_forward.bpf.o:xdp`
   - `cilium/bpf_lxc.bpf.o:tc/entry`

2. 再做 Phase 2：affine/interval  
   目标 section：
   - `cilium/bpf_xdp.bpf.o:xdp/entry`

3. 与 #433 联动，但不要合并实现  
   - #442 先把 proof window 变干净
   - #433 再做 post-load `BPF_NOSPEC/LFENCE` census 与 barrier elimination

## 8.3 最小可行 pass 形态

如果要尽快做一个可信的 v1，我建议它满足这四条：

- 只改 direct packet access
- 只在同一 root / 同一 epoch / side-effect-free parser region 内工作
- 能做 const-window merge
- 失败就 rollback site，不影响其余 program

这条路线最符合当前 corpus 的真实机会分布，也最符合 verifier 的接受边界。
