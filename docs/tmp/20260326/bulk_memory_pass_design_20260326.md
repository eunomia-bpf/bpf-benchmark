# BulkMemoryPass 实现设计

日期：2026-03-26  
状态：design-only  
范围：只设计 daemon 侧 Rust pass；不修改 kernel module / JIT / verifier 源码

## 0. 结论摘要

`BulkMemoryPass` 的目标是把 BPF 字节码里已经被 LLVM 标量化的大块 copy / zero run 收拢成 bulk-memory kinsn 调用：

- `bpf_memcpy_bulk(dst_base, dst_off, src_base, src_off, len)`
- `bpf_memset_bulk(dst_base, dst_off, val, len)`

daemon 侧采用和 `rotate` / `extract` / `endian_fusion` 一致的 packed transport：

- `sidecar pseudo-insn`
- `BPF_PSEUDO_KINSN_CALL`

本设计的关键约束如下：

- 只处理严格直线型、无中间 branch target 的 memory run。
- `memcpy` 只处理同宽度、连续偏移、`LDX_MEM + STX_MEM` 紧邻 pair。
- `memset` v1 以 zeroing 为主；非零只保留 repeated-byte 扩展位，默认不启用。
- 最小替换门槛是 `32B`；小于 `32B` 的 run 保持原始标量指令。
- 单个 bulk kinsn chunk 上限是 `128B`；更长 run 由 daemon 分裂成多个 chunk。
- pass 顺序放在 `wide_mem` 之后、`rotate` 之前；也必须在 `map_inline + const_prop + dce` 之后。

和 2026-03-24 的旧 bulk-memory 设计相比，本文有两个明确收敛：

1. 最小门槛从 `16B` 提高到 `32B`。这意味着旧报告里的 `20B` copy case 不再进入 v1。
2. verifier 语义按题设假定为 `model_call -> memory range effect`，而不是把 `32B~128B` run 全量展开成 proof sequence。

## 1. 设计目标与非目标

### 1.1 目标

- 在 daemon 新增 `BulkMemoryPass`，文件建议为 `daemon/src/passes/bulk_memory.rs`。
- 识别两类模式：
  - `memcpy`：连续 `LDX_MEM + STX_MEM` pair。
  - `memset`：连续 store-only run，主要是 zeroing。
- 用现有 pass 框架完成：
  - site 扫描
  - 安全过滤
  - `sidecar + CALL` 发射
  - branch fixup
  - `required_btf_fds` 填充

### 1.2 非目标

- 不在本轮实现 kernel module。
- 不实现通用 `memmove` 语义。
- 不做跨基本块、跨 helper/call、跨 branch target 的重排。
- 不做 mixed-width run 的全局重构。
- 不做 arbitrary repeated-64-bit-pattern store 合并。`memset_bulk` 只对应 byte-fill 语义。

## 2. 与现有 daemon 框架的衔接

## 2.1 新 pass 的仓库接入点

daemon 侧最终需要扩以下点：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/mod.rs`
  - `mod bulk_memory;`
  - `pub use bulk_memory::BulkMemoryPass;`
  - 在 `PASS_REGISTRY` 中插入 `bulk_memory`
- `daemon/src/pass.rs`
  - `KinsnRegistry` 新增 `memcpy_bulk_btf_id` / `memset_bulk_btf_id`
  - `btf_id_for_target_name()` 增加两个 target
  - 建议新增 `btf_fd_for_target_name()`；因为一个 pass 对应两个 target，不能只靠 `btf_fd_for_pass(self.name())`
- `daemon/src/kfunc_discovery.rs`
  - `KNOWN_KINSNS` 新增 `bpf_memcpy_bulk` / `bpf_memset_bulk`

建议的 canonical pass name：

- `bulk_memory`

可保留 alias：

- `bulk_mem`

## 2.2 复用现有 helper

实现方式应和 `rotate.rs` / `extract.rs` / `endian.rs` 保持一致：

- packed 发射复用 `emit_packed_kinsn_call_with_off()`
- BTF fd slot 复用 `ensure_btf_fd_slot()`
- branch 修复复用 `fixup_all_branches()`
- `PassResult` / `SkipReason` 结构直接沿用

## 2.3 需要的分析

`BulkMemoryPass::required_analyses()` 建议为：

- `branch_targets`
- `liveness`

理由：

- `branch_targets`：run 不能跨 basic block，不能吞掉 interior target。
- `liveness`：`memcpy` run 内 load 产生的 scratch reg 在原程序里可能 live-out；rewrite 后这些寄存器不再被定义，必须过滤。

## 3. Pattern Detection

## 3.1 总体扫描策略

scanner 采用“基本块内、最大连续 run、严格相邻”的策略，而不是全程序 dataflow 重构。

具体规则：

- 以 `BranchTargetAnalysis` 结果为边界。
- 遇到以下情况立即结束当前候选 run：
  - branch target
  - `CALL` / `EXIT`
  - `LD_IMM64` 第二槽之外的任何非匹配指令
  - 宽度变化
  - offset 不再连续
  - base reg 改变
  - `memcpy` 中 `load` 与其 `store` 不再紧邻
- 对每个最大连续 run，先做模式分类，再做 chunk 切分。

实现上建议有两个 matcher：

- `try_match_memcpy_run_at(insns, pc, bt, liveness, ctx)`
- `try_match_memset_run_at(insns, pc, bt, liveness, ctx)`

匹配顺序先 `memcpy`，后 `memset`。因为 `memcpy` 的形态更刚性，误判空间更小。

## 3.2 memcpy 模式

### 3.2.1 基本形态

一个最小 `memcpy` lane 必须是两条紧邻指令：

```text
rT = *(width *)(src_base + src_off)
*(width *)(dst_base + dst_off) = rT
```

即：

- 第 1 条：`BPF_LDX | width | BPF_MEM`
- 第 2 条：`BPF_STX | width | BPF_MEM`
- `store.src_reg == load.dst_reg`

### 3.2.2 v1 必须满足的条件

一个 `memcpy` run 只有在以下条件全部成立时才可替换：

1. 所有 lane 都是 `LDX_MEM + STX_MEM` 紧邻 pair。
2. 所有 lane 的 `width` 相同，且 `width ∈ {1, 2, 4, 8}`。
3. `src_base` 在整个 run 中保持不变。
4. `dst_base` 在整个 run 中保持不变。
5. `src_off` 严格按 `width` 递增。
6. `dst_off` 严格按 `width` 递增。
7. `load.dst_reg` 不等于 `src_base` / `dst_base`。
8. run 总字节数 `>= 32B`。
9. run 内无 interior branch target。
10. 所有 `load.dst_reg` 在 site 结束后都不是 live-out。

第 10 条很重要。例子：

```text
r3 = *(u64 *)(r6 + 0)
*(u64 *)(r10 - 16) = r3
... 后面继续使用 r3 ...
```

原标量代码会把最后一次 load 的值留在 `r3`；bulk kinsn 不会。此类 site 必须 skip。

### 3.2.3 overlap / alias 规则

`bpf_memcpy_bulk` 只承诺 `memcpy` 语义，不承诺 `memmove`。因此 daemon 必须 fail closed。

v1 建议采用保守 alias gate：

- 若 `src_base == dst_base`：
  - 只有在区间常量上可证不重叠时才允许：
    - `src_off + len <= dst_off`
    - 或 `dst_off + len <= src_off`
  - 否则 skip
- 若 `src_base != dst_base`：
  - 只接受容易证明不别名的常见组合：
    - `packet -> stack`
    - `packet -> map value`
    - `stack -> packet`
    - `stack -> map value`
    - `map value -> stack`
  - `map value -> map value`、`unknown -> unknown`、同根对象但不同寄存器的情况，v1 默认 skip

换句话说，v1 不做一般化 pointer alias analysis，只抓最稳的块拷贝。

### 3.2.4 gap / mixed width / interleaving

对 `memcpy`：

- 遇到 offset gap：结束当前段；若前缀 `>= 32B` 则前缀单独成站点。
- 遇到宽度变化：结束当前段；不跨宽度合并。
- 遇到任何非 `LDX_MEM + STX_MEM` 的插入指令：直接结束当前段。

例如：

```text
LDXDW/STXDW  x4   ; 32B
ALU64        ...  ; interleaving
LDXDW/STXDW  x4
```

v1 的行为是：

- 前 32B 可以成一个 bulk site
- 中间 ALU 保留
- 后 32B 重新开始匹配

不尝试跨过中间指令做重排。

## 3.3 memset 模式

## 3.3.1 基本形态

一个 `memset` run 是纯 store-only 序列：

- `BPF_ST | width | BPF_MEM`
- 或 `BPF_STX | width | BPF_MEM`

且满足：

- base reg 相同
- width 相同
- offset 按 `width` 连续递增
- 写入值在整个 run 中相同

### 3.3.2 v1 语义边界

虽然 target 名字叫 `bpf_memset_bulk(dst_base, dst_off, val, len)`，但 daemon v1 应把主路径收敛到“byte-fill 可证明成立”的 case：

- `ST_MEM imm == 0`
- `STX_MEM` 的 `src_reg` 可证明为 zero
- 未来可扩到 non-zero repeated-byte，但默认不启用

以下情况默认 skip：

- 同一个 `src_reg` 被重复写入，但其值不是 zero / repeated-byte
- 宽度是 `DW`，但 store value 只是“同一个 64-bit 值”，并不能证明等于 byte memset

原因很直接：

- `rep stosb`
- ARM64 `STP/STR` byte-fill loop

实现的都是 byte-fill 语义，不是 “重复写同一个任意 64-bit word” 语义。

### 3.3.3 zero provenance

为支持 `STX_MEM` zeroing，pass 需要一个很轻量的寄存器值分类：

- `Unknown`
- `KnownZero`
- `KnownByteSplat(u8)`，保留给 future non-zero memset

局部前向传播已足够，不需要全局 SSA：

- `MOV64_IMM reg, 0` -> `KnownZero`
- `MOV32_IMM reg, 0` -> `KnownZero`
- `XOR reg, reg` -> `KnownZero`
- `MOV64_REG dst, src` 且 `src` 为 `KnownZero` -> `dst = KnownZero`
- 其他写寄存器 -> `Unknown`
- 在 branch target / call 处重置

### 3.3.4 最小门槛

`memset` run 只有在总字节数 `>= 32B` 时才进入 bulk lowering。

因此：

- `74B` zeroing：会命中
- `360B` zeroing：会命中
- `464B` zeroing：会命中
- `16B` / `24B` zeroing：保留原始标量 stores

## 3.4 chunking

为了限制 payload、verifier 建模复杂度和单站点 native emit 大小，daemon 必须把长 run 切成多个 chunk。

建议常量：

- `MIN_BULK_BYTES = 32`
- `CHUNK_MAX_BYTES = 128`

切分规则：

- 尽量贪心取 `128B`
- 最后一个 chunk 只有在 `>= 32B` 时才单独发 kinsn
- 剩余尾巴 `< 32B` 时保留原始标量指令

例子：

- `40B` -> `40`
- `74B` -> `64 + 10`，其中最后 `10B` 保留原始指令
- `360B` -> `128 + 128 + 104`
- `464B` -> `128 + 128 + 128 + 80`

这正好覆盖题设里最关键的 corpus 机会，同时避免一个 super-site 吞下几百字节。

## 4. Kinsn Call Emission

## 4.1 传输格式

BulkMemoryPass 继续复用现有 packed transport：

```text
sidecar(payload)
CALL BPF_PSEUDO_KINSN_CALL imm=<btf_id> off=<fd_slot>
```

daemon 直接调用：

- `emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off)`

不引入 legacy call ABI，不引入额外 helper argument 搬运协议。

## 4.2 memcpy payload

建议的 `bpf_memcpy_bulk` payload 布局：

```text
bits [3:0]   = dst_base_reg
bits [7:4]   = src_base_reg
bits [23:8]  = dst_off (i16, two's complement)
bits [39:24] = src_off (i16, two's complement)
bits [47:40] = len_minus_1 (u8)
bits [49:48] = width_class
bits [51:50] = reserved
```

其中：

- `width_class = 0/1/2/3` 分别表示 `1/2/4/8B`
- `len = len_minus_1 + 1`
- `len <= 128`

这里保留 `width_class` 的原因不是 native emitter 必需，而是：

- kernel 侧 decode / validate 更容易做一致性检查
- 调试时更容易看出 run 的原始 lane 形态
- future verifier 若要校验 `len % width == 0`，不必重建

## 4.3 memset payload

建议的 `bpf_memset_bulk` payload 布局：

```text
bits [3:0]   = dst_base_reg
bits [7:4]   = val_reg
bits [23:8]  = dst_off (i16, two's complement)
bits [31:24] = len_minus_1 (u8)
bits [33:32] = width_class
bit  [34]    = value_from_reg
bit  [35]    = zero_fill
bits [43:36] = fill_imm8
bits [51:44] = reserved
```

daemon v1 的发射策略：

- 对 `ST_MEM imm0`：
  - `zero_fill = 1`
  - `value_from_reg = 0`
  - `fill_imm8 = 0`
- 对 `STX_MEM` known-zero：
  - `zero_fill = 1`
  - `value_from_reg` 可为 `0` 或 `1`，两者都可以；建议统一仍按 zero fastpath 处理
- non-zero repeated-byte：
  - payload 已预留，但 v1 默认不启用

## 4.4 btf_id 与 fd slot 选择

BulkMemoryPass 是一个 pass 对两个 target，因此 site 级别选择 target，而不是 pass 级别硬编码。

建议 target 名：

- `bpf_memcpy_bulk`
- `bpf_memset_bulk`

daemon 侧需要：

- `ctx.kinsn_registry.memcpy_bulk_btf_id`
- `ctx.kinsn_registry.memset_bulk_btf_id`

以及一个新 helper：

```rust
fn btf_fd_for_target_name(&self, target_name: &str) -> Option<i32>
```

发射时的逻辑应为：

1. 根据 site.kind 选 target name。
2. 从 `KinsnRegistry` 取该 target 的 `btf_id`。
3. 检查 `packed_supported_for_target_name(target_name)`。
4. 从 `target_btf_fds[target_name]` 取 BTF fd。
5. 用 `ensure_btf_fd_slot()` 得到 `CALL.off`。

如果两个 target 最终来自同一个 module BTF fd，`ensure_btf_fd_slot()` 会自然去重。

## 4.5 重写输出形态

对一个 chunk，replacement 恒为：

- 2 条指令：`sidecar + call`

对一个长 run，则 replacement 为：

- `2 * chunk_cnt` 条指令

不需要额外 NOP padding；现有 `addr_map + fixup_all_branches()` 即可处理收缩后的 PC 映射。唯一前提仍然是：

- site 内不能有 interior branch target

## 5. Verifier Acceptance

## 5.1 verifier 契约

本文按题设采用以下 kernel-side 契约：

- transport 仍然是当前仓库的 `sidecar + BPF_PSEUDO_KINSN_CALL`
- verifier 语义采用 bulk kinsn 的 `model_call -> memory range effect`

也就是说，bulk-memory 不应像 `rotate` / `extract` 那样去依赖一长段 proof sequence；否则：

- `32B~128B` 的 bulk site 会重新膨胀成大量普通 load/store
- verifier patch/remove/restore 成本会重新回到大 run 的数量级

bulk-memory kinsn 需要的 effect 很简单：

- `memcpy_bulk`
  - read: `[src_base + src_off, len]`
  - write: `[dst_base + dst_off, len]`
- `memset_bulk`
  - write: `[dst_base + dst_off, len]`

这正是 `model_call` 适合表达的范围。

## 5.2 为什么原始 site 有助于 verifier 接受

daemon 不会发明新的 pointer base，也不会引入新的变址模式：

- `src_base` / `dst_base` 都来自原始 `BPF_MEM` 指令
- `src_off` / `dst_off` 都来自原始连续 lane 的起点
- `len` 只是把原始已经发生过的连续访问长度聚合成一个区间

因此 BulkMemoryPass 对 verifier 的要求是：

- 证明“同一个 base 上的一段连续区间”可读/可写

而不是：

- 证明一个全新地址表达式
- 证明 widened load/store 的新对齐约束

这也是它和 `WideMemPass` 的根本不同点。`wide_mem` 会改变单次访问宽度；`bulk_memory` 只改变 transport 颗粒度。

## 5.3 base reg 合法性

base reg 必须对应 verifier 可识别的 pointer class。v1 只接受以下三类：

- stack pointer
- map value pointer
- packet pointer

daemon 侧不做完整 verifier，但可以利用两条事实：

1. 被匹配的原始指令本身已经是合法 `BPF_MEM` 访问。
2. run 中 base reg 不变，offset 连续，因此 bulk effect 只是原访问集合的区间并集。

实现上建议：

- `r10` 直接视为 stack
- packet pointer 复用 `wide_mem.rs` 的轻量 provenance heuristic
- map value pointer 走“非 packet、非 stack、来源于 map lookup / map_inline”保守分类
- 不确定就 skip

## 5.4 packet pointer 的特殊要求

packet pointer 仍然是最敏感的一类，因为 verifier 需要能证明整个 `[off, off+len)` 窗口在 `data_end` 之内。

v1 采取以下保守策略：

- pass 放在 `bounds_check_merge` 之后
- 只接受同一个 packet base reg 的连续窗口
- run 中不能有 pointer arithmetic / compare / guard 插入
- 不能跨 basic block

这样 bulk effect 基本对应“同一条 dominant bounds check 已经覆盖的连续包头窗口”。

## 5.5 clobber 与寄存器语义

`BulkMemoryPass` 最理想的 kernel-side `model_call` 语义应是：

- 不暴露额外的 BPF-visible clobber
- 结果寄存器无意义（void-like）
- 所有内部 scratch 都是 JIT emitter 的实现细节

这是合理的，因为 packed sidecar 已经把所有逻辑参数编码在 metadata 里，不需要把 `r1-r5` 当作普通 helper ABI 来消费。

daemon 侧仍需做的唯一寄存器安全检查是：

- `memcpy` run 内部的 load scratch reg 必须 dead-out

因为原代码会定义它们，bulk call 不会。

## 6. Pass Ordering

推荐顺序如下：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

理由：

- `map_inline + const_prop + dce` 会把很多局部初始化收敛成更规整的连续 stores。
- `bounds_check_merge` 先把 packet window canonicalize，bulk-memory 更容易证明整段区间。
- `wide_mem` 先把 byte-pack 机会变成 `B/H/W/DW` 的规整访问，bulk-memory 再去吞长 run。
- `bulk_memory` 应早于其他 peephole kinsn pass；否则长 memory burst 先被局部优化切碎，不利于整体收拢。
- 若未来有 `pair_mem` / `LDP/STP` pass，则 `bulk_memory` 应在它之前；pair 只吃 residual pair。

## 7. Rust 实现轮廓

建议的核心数据结构：

```rust
enum BulkKind {
    Memcpy,
    Memset,
}

struct BulkSite {
    kind: BulkKind,
    start_pc: usize,
    old_len: usize,
    width: u8,
    len_bytes: u16,
    src_base: Option<u8>,
    src_off: Option<i16>,
    dst_base: u8,
    dst_off: i16,
}
```

建议的实现步骤：

1. 在基本块内扫描原始指令流。
2. 先尝试 `memcpy` matcher，再尝试 `memset` matcher。
3. 对 raw run 做：
   - 长度阈值过滤
   - alias / overlap 过滤
   - scratch live-out 过滤
4. 把合格 run 切成 `<= 128B` 的 chunk。
5. 每个 chunk 生成一个 `BulkSite`。
6. site 级别按 kind 选择：
   - payload
   - target name
   - `btf_id`
   - `fd_slot`
7. 用和 `rotate` / `extract` 相同的地址映射方式重建指令流。
8. `fixup_all_branches()` 后更新：
   - `program.insns`
   - `program.remap_annotations(&addr_map)`
   - `program.log_transform(...)`

## 8. Test Plan

单元测试建议直接放在 `daemon/src/passes/bulk_memory.rs`，风格对齐 `wide_mem.rs` / `endian.rs`。

至少覆盖以下 case：

- `memcpy_dw_64b_applies`
  - `8 x (LDXDW + STXDW)`，同 base、同宽度、连续 offset
  - 期望：替换为 1 个 `sidecar + call`
- `memcpy_b_40b_applies`
  - `40B` byte copy
  - 期望：命中，且 payload `len=40`
- `memcpy_24b_below_threshold_skips`
  - `24B` copy
  - 期望：不改写
- `memcpy_gap_splits_or_skips`
  - 中间 offset 有洞
  - 期望：只吃满足 `>=32B` 的连续前缀；不足阈值的后缀保留
- `memcpy_mixed_width_skips`
  - `DW` 后接 `W`
  - 期望：不跨宽度合并
- `memcpy_interleaved_alu_breaks_run`
  - `LDX/STX` 中间夹一条 ALU
  - 期望：run 被截断
- `memcpy_live_out_tmp_skips`
  - 最后一个 load dst reg 在 site 后仍被使用
  - 期望：skip
- `memcpy_overlap_same_base_skips`
  - 同 base 且区间重叠
  - 期望：skip
- `memset_zero_st_mem_128b_applies`
  - `16 x ST_MEM(DW, ..., 0)`
  - 期望：替换为 1 个 `bpf_memset_bulk`
- `memset_zero_stx_mem_64b_applies`
  - 连续 `STX_MEM`，value reg 由 `mov64_imm 0` 提供
  - 期望：命中
- `memset_nonzero_reg_skips_by_default`
  - 同一个非零 reg 重复 store
  - 期望：v1 skip
- `memset_chunk_360b_splits_3_calls`
  - `360B` zeroing
  - 期望：切成 `128 + 128 + 104`
- `memset_chunk_464b_splits_4_calls`
  - `464B` zeroing
  - 期望：切成 `128 + 128 + 128 + 80`
- `interior_branch_target_skips`
  - site 中间被跳转落点命中
  - 期望：skip
- `required_btf_fds_recorded`
  - 触发 `memcpy_bulk` / `memset_bulk`
  - 期望：`program.required_btf_fds` 含对应 fd，且同 fd 不重复
- `pipeline_order_wide_mem_then_bulk_memory`
  - 先让 `wide_mem` 规整输入，再验证 `bulk_memory` 吃到后续 run

## 9. Quantitative Opportunity

按题设关心的 corpus 长度分布：

| run 大小 | 是否超过 32B 门槛 | 预期处理 |
| --- | --- | --- |
| `40B` | 是 | 单个 bulk chunk |
| `74B` | 是 | `64B` bulk + `10B` 标量尾巴 |
| `360B` | 是 | `128 + 128 + 104` |
| `464B` | 是 | `128 + 128 + 128 + 80` |

这四类 run 有两个直接意义：

1. `32B` 门槛不会错过主要 bulk 机会。
2. `128B` chunk 上限足以覆盖常见大 run，同时避免一个 site 过大。

同时也要明确：

- 2026-03-24 旧报告里提到的 `20B` copy，在本文门槛下不会再被 `BulkMemoryPass` 吃掉。
- 这不是回退，而是主动收敛：小于 `32B` 时，2 条 kinsn transport 指令和 verifier/jit metadata 成本不一定优于原始标量序列。

## 10. 最终建议

`BulkMemoryPass` 应作为一个新的 daemon 结构级 pass 落地，设计原则是“严格、保守、只吃最稳的大块 run”：

- `memcpy` 只吃紧邻 `LDX_MEM + STX_MEM`、同宽度、连续偏移、可证明非重叠的 run。
- `memset` v1 先专注 zeroing；非零 repeated-byte 留作扩展位。
- transport 继续复用现有 `sidecar + BPF_PSEUDO_KINSN_CALL`。
- verifier 契约按 `model_call` 的 range effect 设计，而不是回退到长 proof sequence。
- pipeline 中放在 `wide_mem` 之后、`rotate` 之前。

如果按这个边界实施，daemon 侧复杂度是可控的，同时又能覆盖题设里最有价值的 `40B / 74B / 360B / 464B` bulk-memory 机会。
