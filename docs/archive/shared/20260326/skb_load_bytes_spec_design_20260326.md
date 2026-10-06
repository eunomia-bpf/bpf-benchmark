# SkbLoadBytesSpecPass 设计文档

日期：2026-03-26

## 1. 目标与范围

`docs/kernel-jit-optimization-plan.md` 在 §3.1 的 #444 已把 `skb_load_bytes -> direct packet access` 定为 P0；`docs/tmp/20260324/helper_call_inlining_research_20260324.md` 的结论也是：在当前候选 helper 里，`skb_load_bytes` 最适合先做纯 bytecode specialization。

本设计文档的 v1 目标很明确：

- 新增 `SkbLoadBytesSpecPass`
- 只在 BpfReJIT daemon 的纯 bytecode pass 管线中实现
- 不引入 kinsn
- 不改源码语义，只把一部分 `bpf_skb_load_bytes()` helper 调用改写成“站点内 direct packet access fast path + 原 helper slow path”
- v1 只支持 `BPF_PROG_TYPE_SCHED_CLS` / `BPF_PROG_TYPE_SCHED_ACT`

这份设计故意不追求“一次覆盖所有 skb 类 prog_type”。当前 corpus 里 `skb_load_bytes` 可归因站点的绝大多数已经在 `sched_cls/TC`：`532` 个 `sched_cls`，而且项目侧主要集中在 Cilium、Calico、linux-selftests、loxilb。

## 2. 关键设计结论

### 2.1 只改写 helper call，本地保留 slow path

v1 不删除原参数准备窗口，也不尝试吃掉 call 后的外层错误检查。改写策略是：

- 保留 helper 前的原始参数准备指令
- 把 `call bpf_skb_load_bytes` 这一条替换成更长的序列
- 新序列内部先走 direct packet access fast path
- bounds 失败时，跳到新序列内部的 `call #26` slow path
- 新序列结束后继续落到原程序的后续字节码；原来的 `if r0 != 0 goto error` 可保持不变

这样做的直接好处：

- 语义最稳
- 不需要模拟 helper 失败时的 zero-fill
- 不需要删除 setup 窗口，也不需要回收 post-call error check
- 分支修正和地址映射最简单，完全符合 `map_inline.rs` / `bounds_check_merge.rs` 现有风格

### 2.2 v1 只支持 TC_ACT

虽然内核里 `BPF_FUNC_skb_load_bytes` 不只出现在 TC，但 v1 只开：

- `BPF_PROG_TYPE_SCHED_CLS`
- `BPF_PROG_TYPE_SCHED_ACT`

明确不做：

- `SOCKET_FILTER`
- `CGROUP_SKB`
- `FLOW_DISSECTOR`
- `SK_SKB`
- `SK_REUSEPORT`
- 其他 skb 类上下文

原因不是“理论上不可能”，而是首版 pass 应该先收窄到 verifier 合同最清楚、语料收益最大的主战场。`skb_load_bytes` 在 corpus 里的主收益本来就几乎都在 TC。

### 2.3 这是对 `orig_insns` 的改写，不是对 `xlated_prog_insns`

这一点必须写清楚。daemon 当前在 `cmd_rewrite` / `cmd_apply` 里用的是 `orig_insns` 构造 `BpfProgram`，然后把改写结果送回 `BPF_PROG_REJIT`。也就是说，本 pass 面对的是“原始 eBPF bytecode”，不是 verifier 已经转换过的 `xlated_prog_insns`。

因此：

- pass 识别 helper 参数时，识别的是原始 `r1/r2/r3/r4`
- pass 发射 direct packet access 时，发射的是原始用户可见 ctx 访问
- verifier 在 REJIT 阶段再次看到 `*(u32 *)(r1 + offsetof(struct __sk_buff, data))` / `data_end`，并重新做 ctx access 转换与 packet-proof 推导

这也是为什么本 pass 必须使用 UAPI `struct __sk_buff` 偏移，而不是内核内部 `struct sk_buff` 已转换偏移。

## 3. Program Type 与 ctx 布局

### 3.1 v1 支持矩阵

| prog_type | helper #26 可能出现 | 允许 direct packet access | v1 是否支持 | 说明 |
|---|---:|---:|---:|---|
| `BPF_PROG_TYPE_SCHED_CLS` | 是 | 是 | 是 | 主目标 |
| `BPF_PROG_TYPE_SCHED_ACT` | 是 | 是 | 是 | 主目标 |
| `BPF_PROG_TYPE_XDP` | 否 | 是 | 否 | 不是 `skb_load_bytes`，应走单独 `xdp_load_bytes` 设计 |
| `BPF_PROG_TYPE_SOCKET_FILTER` | 是 | 否 | 否 | helper 可用，但 direct `data/data_end` 不可用 |
| `BPF_PROG_TYPE_CGROUP_SKB` | 是 | 条件允许 | 否 | 首版不引入 capability/token 分支 |
| `BPF_PROG_TYPE_SK_SKB` | 是 | 是 | 否 | 未来可扩展，但 verifier access path 需单独验证 |
| `BPF_PROG_TYPE_FLOW_DISSECTOR` | 是 | 是 | 否 | 未来可扩展 |

### 3.2 v1 的 `PacketCtxLayout`

虽然 v1 只支持 TC_ACT，仍建议把 ctx 布局抽象出来，放在 `daemon/src/passes/utils.rs` 或新 pass 私有模块里：

```rust
struct PacketCtxLayout {
    data_off: i16,
    data_end_off: i16,
    ptr_load_size: u8,
}
```

v1 的表只有一项：

```rust
PacketCtxLayout {
    data_off: 76,      // offsetof(struct __sk_buff, data)
    data_end_off: 80,  // offsetof(struct __sk_buff, data_end)
    ptr_load_size: BPF_W,
}
```

这里顺便澄清一个容易混淆的点：在当前内核树里，`SK_SKB` 使用的 UAPI ctx 仍然是 `struct __sk_buff`，所以 `data/data_end` 的 UAPI byte offset 仍是 `76/80`。`SK_SKB` 和 TC_ACT 的差异主要在 `sk_skb_is_valid_access()` / `sk_skb_convert_ctx_access()` 这条 verifier access path，而不是 UAPI 偏移本身。因此 v1 直接把 `SK_SKB` 视为未支持，而不是复用 TC_ACT 假设强行打开。

## 4. 需要匹配的 BPF bytecode 形态

## 4.1 helper call 本体

`bpf_skb_load_bytes()` 在 bytecode 里就是 regular helper call：

```text
insn.code == (BPF_JMP | BPF_CALL)
insn.src_reg() == 0
insn.imm == 26
```

这里的 `26` 来自 `vendor/linux-framework/include/uapi/linux/bpf.h` 中的 `BPF_FUNC_skb_load_bytes` helper id。

helper 参数按 eBPF calling convention 固定为：

- `r1 = ctx`
- `r2 = offset`
- `r3 = to`
- `r4 = len`

因此 matcher 的核心问题不是“认出 helper id”，而是“在 call 点证明这四个寄存器正好是我们能专门化的形态”。

## 4.2 本 pass 需要的局部符号状态

现有 analysis 里没有现成的常量传播结果；`bounds_check_merge.rs` 也是自己做线性状态扫描。因此 `SkbLoadBytesSpecPass` 建议沿用同一风格，在 pass 内做一个轻量寄存器状态机：

```rust
enum RegValue {
    Unknown,
    Ctx,
    Const(u64),
    FpPlusConst(i32),
}
```

### 4.2.1 初始状态

- `r1 = Ctx`
- `r10 = FpPlusConst(0)`
- 其余 `Unknown`

### 4.2.2 支持的转移

为了命中 corpus 里的常见 helper 参数准备序列，至少要识别：

- `mov64 dst, imm`
- `mov32 dst, imm`
- `ldimm64 dst, imm64`
- `mov64 dst, src`
- `alu64 add/sub imm` 到 `Const` 或 `FpPlusConst`

规则建议如下：

- `mov64_imm`: `dst = Const(sign_extended_i32_as_u64)`
- `mov32_imm`: `dst = Const(zext_u32(imm))`
- `ldimm64`: `dst = Const(imm64)`
- `mov64_reg`: 复制 `src` 状态到 `dst`
- `add/sub imm`:
  - `Const(c)` -> `Const(c +/- imm)`
  - `FpPlusConst(off)` -> `FpPlusConst(off +/- imm)`
- 其他任何定义寄存器的指令：把该 `dst` 状态清成 `Unknown`

### 4.2.3 basic block 边界

扫描依赖 `BranchTargetAnalysis`：

- 如果 `pc` 是 branch target，则清空 `r0-r9`
- 但保留 `r1 = Ctx` 和 `r10 = FpPlusConst(0)` 作为新的 block 入口假设

这和 `bounds_check_merge.rs` 的保守做法一致。v1 不做跨 CFG merge 的 dataflow join，因此：

- `call_pc` 本身如果是 branch target，直接 skip
- 参数值如果来自复杂控制流 merge，也直接 skip

这样可以把实现复杂度控制在当前 pass 框架可自然承载的范围内。

## 4.3 站点命中条件

当扫描到 `call #26` 时，命中条件是：

- `ctx.prog_type` 为 `SCHED_CLS` 或 `SCHED_ACT`
- `call_pc` 不是 branch target
- `r1 == Ctx`
- `r2 == Const(offset)`
- `r3 == FpPlusConst(dest_off)`，且 `dest_off < 0`
- `r4 == Const(len)`
- `1 <= len <= 8`
- `offset <= i32::MAX`
- `offset + len <= i32::MAX`

这里 `r3 == FpPlusConst(dest_off)` 的意义不是为了在 emitter 里重新生成 `r3`，而是为了确保：

- helper 的目标缓冲区确实是栈
- 我们可以在 fast path 上对 `r3 + delta` 做直接栈写回

v1 不要求 `offset` 是“紧邻 call 的 `mov imm`”，也不要求 `len` 是“紧邻 call 的 `mov imm`”。只要线性扫描在当前 basic block 内能证明 `r2/r4` 是常量即可。

## 4.4 call 后错误检查如何处理

用户侧最常见的源码是：

```c
ret = bpf_skb_load_bytes(...);
if (ret)
    goto error;
```

在 bytecode 里常见为紧跟在 call 后的一条 compare-to-zero branch，例如：

```text
call 26
if r0 != 0 goto error
```

或等价的反向极性：

```text
call 26
if r0 == 0 goto continue
```

v1 的设计点是：

- 可以识别这个 pattern，用于测试和诊断
- 但 rewrite 正确性不依赖于识别它

原因很简单：我们保留外层 post-call check，本 pass 只保证：

- fast path 成功时显式写 `r0 = 0`
- slow path 真正执行 `call #26`，返回原 helper `r0`

因此无论调用点后面有没有立即 `if r0 != 0 goto error`，程序语义都保持成立。

换句话说：

- “找到 error check” 是文档和测试层面的辅助能力
- 不是 v1 rewrite 的必要前提

如果实现里要显式分类，建议只检测最简单的 immediate-next-insn compare-to-zero：

- `BPF_JEQ/BPF_JNE` against `0`
- `dst_reg == 0`
- `src_reg == 0` 或 `imm == 0`

不需要在 v1 里做更远距离的 return-value use slicing。

## 5. 改写算法

## 5.1 站点内重写形态

给定原始形态：

```text
...                       ; 原 setup 保留
r1 = ctx
r2 = offset
r3 = fp + dest_off
r4 = len
call 26
if r0 != 0 goto error     ; 外层检查保留
... use stack bytes ...
```

v1 把 `call 26` 这一条替换成：

```text
r5 = *(u32 *)(r1 + 76)        ; data
r0 = *(u32 *)(r1 + 80)        ; data_end
r2 = r5
r2 += offset + len
if r2 > r0 goto slow
r5 += offset

; fast copy: v1 全部按 byte chunk
r4 = *(u8 *)(r5 + 0)
*(u8 *)(r3 + 0) = r4
...
r4 = *(u8 *)(r5 + len - 1)
*(u8 *)(r3 + len - 1) = r4

r0 = 0
ja done

slow:
r2 = offset
r4 = len
call 26

done:
; 直接落回原 call 后的下一条指令
```

这里最关键的设计选择有两个：

- `r3` 保留为原先 helper 的目标栈指针，不在 fast path 里重建
- slow path 只需重建 `r2` 和 `r4`，因为 `r1` 和 `r3` 整个替换序列都不被 clobber

这比“fast path 直接写回 `[r10 + dest_off]`，然后 slow path 再重建 `r3`”更省指令，也更贴近原调用点寄存器布局。

## 5.2 为什么选择“站点内 slow path”，而不是直接删掉 helper

`bpf_skb_load_bytes()` 的语义比“返回 0 / 负值”更强：

- 它能处理 non-linear skb
- 失败时会对目标缓冲区做 zero-fill

如果把 helper 完全删掉，那么首版 pass 还得自己复制这两块 helper-only 语义，风险完全不值得。站点内 slow path 保留原 helper，能自动保住：

- fragment / non-linear skb 的语义
- 越界时的 zero-fill
- 将来 helper 行为演化时的兼容性

因此 v1 的真实优化边界不是“所有包都走 direct access”，而是：

- linear head + bounds 可证明 -> fast path
- 其余情况 -> 原 helper

## 5.3 指令数

如果把“原 helper site”按 `call` 自身计数：

- 原始：`1` 条 `call`
- 如果把最常见的外层错误检查也算作 site 的可观察主体，则通常是 `2` 条：`call + jmp`

v1 replacement 的指令数取决于 fast copy chunk 数 `c`：

- 通用公式：`11 + 2*c`

其中：

- `6` 条 preamble
- `2*c` 条 fast `load + stack store`
- `1` 条 `r0 = 0`
- `1` 条 `ja done`
- `2` 条 slow-path 参数重建
- `1` 条 slow `call`

### 5.3.1 v1 byte-copy 方案

v1 先全部按 byte chunk，因此 `c = len`：

- `len = 1` -> `13` 条
- `len = 2` -> `15` 条
- `len = 4` -> `19` 条
- `len = 8` -> `27` 条

这看起来比单条 helper call 多很多，但实际运行时：

- fast path 去掉了 helper 调用本身
- 去掉了 helper 内部 `skb_header_pointer()` / `memcpy()` / 错误处理开销
- 对 hot packet path 仍然值得

### 5.3.2 v1.1 可加的 chunk widening

后续如果 verifier 对齐条件确认清楚，可把 byte copy 换成 `1/2/4/8` chunk plan：

- `len = 4` 若可用一个 `W` chunk，则 `c = 1`，总数变成 `13`
- `len = 8` 若可用一个 `DW` chunk，则也是 `13`

但首版不建议直接开。`wide_mem.rs` 已经说明 packet pointer 上的宽访问需要特别谨慎；v1 最稳的路径仍是先做 byte copy。

## 5.4 分支修正

实现结构建议完全套用 `map_inline.rs` / `bounds_check_merge.rs` 的模式：

- 先扫描并收集 `RewriteSite`
- 用 `BTreeMap<usize, Vec<BpfInsn>>` 存 `call_pc -> replacement`
- 单次线性 rebuild 新指令流
- 构建 `addr_map[old_pc] = new_pc`
- 最后调用 `fixup_all_branches(&mut new_insns, &old_insns, &addr_map)`

因为 v1 只替换单条 `call`，不删除 setup window，也不删除 call 后错误检查，所以：

- 不需要 `skip_pcs`
- 不需要 `eliminate_unreachable_blocks()`
- 一般也不需要 `eliminate_nops()`

这是当前仓库里最简单、最稳的 rewrite 形态。

## 5.5 寄存器分配

推荐的寄存器约定如下：

- `r1`: 保留 ctx，不可 clobber
- `r3`: 保留原 helper 的目标栈指针，不可 clobber
- `r0`: `data_end` / helper return value
- `r2`: cursor scratch；slow path 前重建成 `offset`
- `r4`: fast load scratch；slow path 前重建成 `len`
- `r5`: packet data root / rebased data pointer
- `r6-r9`: 一律不碰

这么分配的理由：

- 完全使用 caller-saved 寄存器，符合“原 helper 调用之后这些寄存器本来也不可靠”的 ABI 预期
- 不影响 `r6-r9`
- 让 slow path 参数重建成本最小化

## 6. verifier 接受条件

## 6.1 verifier 需要看到标准的 `ctx->data / ctx->data_end` 形态

因为 daemon 改的是 `orig_insns`，所以 verifier 重新看到的是：

```text
r5 = *(u32 *)(r1 + 76)
r0 = *(u32 *)(r1 + 80)
```

对于 TC_ACT，这正是 verifier 已知的 direct packet access 入口。它会把：

- `ctx->data` 标成 `PTR_TO_PACKET`
- `ctx->data_end` 标成 `PTR_TO_PACKET_END`

之后再通过：

```text
r2 = r5
r2 += offset + len
if r2 > r0 goto slow
```

建立 packet range proof。

## 6.2 fast path 中间不能插入会清空 packet proof 的 helper

verifier 对 packet pointer 的要求不是“某个 helper 之前见过 bounds check”即可，而是：

- 生成 packet ptr
- 进行 bounds compare
- 直接使用 packet ptr 读数据

中间不能有会导致 packet pointer 证明失效的 helper。v1 的 fast path 是一段纯 load/store/jump，不会打断这个 contract。

## 6.3 不需要 whole-program 禁用已有 direct packet access

首版草稿容易走向一个过保守结论：程序里只要已经出现 direct packet access，就整程序跳过。这个限制不应该有。

原因：

- 本 pass 为每个站点都重新从 `ctx->data` / `data_end` 取 fresh packet pointers
- fast path 内部没有 helper，proof 完全是局部自洽的
- 就算程序别处已有 direct packet access，也不会破坏本 site 的 verifier 正确性

因此 v1 只需要站点内安全，不需要 whole-program `data/data_end` 禁用规则。

## 6.4 非线性 skb 不是语义 blocker，只是 fast-path 边界

direct packet access 只能覆盖当前 linear/head 可见窗口；`bpf_skb_load_bytes()` 则还能跨 non-linear skb 片段。因为我们保留 slow path helper，所以：

- 语义上仍然正确
- 只是 fragmented / non-linear skb 不会命中 fast path

这比“首版完全不支持 non-linear skb”更准确。真正的限制是“首版只优化 linear fast path，不改变 non-linear 语义”。

## 7. 限制与 skip reason

v1 建议明确写入 `SkipReason` 的条件：

- `unsupported prog_type`
- `call pc is a branch target`
- `arg1 is not ctx`
- `offset is not constant`
- `len is not constant`
- `len == 0`
- `len > 8`
- `dest is not fp-relative stack`
- `offset exceeds i32`
- `offset + len exceeds i32`
- `helper is not regular call #26`

另外两条需要在文档里单独说明：

- 不处理 `bpf_skb_load_bytes_relative()`（helper #68）
- 不在 v1 里尝试专门化“offset/len 之一是 variable scalar”的情况

## 8. Pass 结构设计

## 8.1 新文件与类型

建议新增：

- `daemon/src/passes/skb_load_bytes_spec.rs`

核心类型：

```rust
pub struct SkbLoadBytesSpecPass;

struct RewriteSite {
    call_pc: usize,
    offset: i32,
    len: u32,
}
```

如果需要把 immediate post-call check 作为诊断带出来，可以再加：

```rust
enum PostCallCheckKind {
    CompareR0ToZero,
}
```

但它不应成为 rewrite 必需字段。

## 8.2 依赖的 analysis

v1 最小依赖：

```rust
fn required_analyses(&self) -> Vec<&str> {
    vec!["branch_targets"]
}
```

不需要 `cfg`、`liveness`、`map_info`。

理由：

- v1 不做跨块 dataflow join
- v1 不删除 setup window
- v1 不依赖寄存器死活性来做额外删减

## 8.3 `run()` 建议骨架

```rust
fn run(
    &self,
    program: &mut BpfProgram,
    analyses: &mut AnalysisCache,
    ctx: &PassContext,
) -> anyhow::Result<PassResult> {
    let Some(layout) = packet_ctx_layout_for_tc(ctx.prog_type) else {
        return Ok(unchanged_with_skip(...));
    };

    let bt = analyses.get(&BranchTargetAnalysis, program);
    let scan = scan_sites(&program.insns, &bt, layout);
    if scan.sites.is_empty() {
        return Ok(unchanged(scan.skips));
    }

    let old_insns = program.insns.clone();
    let (new_insns, addr_map) = rewrite_sites(&old_insns, &scan.sites, layout)?;

    program.insns = new_insns;
    fixup_all_branches(&mut program.insns, &old_insns, &addr_map);
    program.remap_annotations(&addr_map);
    program.log_transform(TransformEntry {
        sites_applied: scan.sites.len(),
    });

    Ok(PassResult {
        pass_name: self.name().into(),
        changed: true,
        sites_applied: scan.sites.len(),
        sites_skipped: scan.skips,
        diagnostics: vec![],
        ..Default::default()
    })
}
```

## 8.4 pipeline 顺序

推荐插在：

```text
map_inline
const_prop
dce
skb_load_bytes_spec
bounds_check_merge
wide_mem
...
```

原因：

- 放在 `const_prop` 之后，能多吃到 `mov32 imm` / copy-propagated 常量实参
- 放在 `bounds_check_merge` 之前，后者可以合并本 pass 新生成的 bounds guard
- 放在 `wide_mem` 之前或之后都不是 blocker，但从“先把 helper 变成普通 load/store 形态，再做 peephole”的角度，放在它前面更自然

## 9. 单元测试计划

所有测试建议先放在 `daemon/src/passes/skb_load_bytes_spec.rs` 的 `#[cfg(test)]` 中，形式参考 `bounds_check_merge.rs` / `map_inline.rs`。

## 9.1 正例

- `sched_cls`，`offset=14`，`len=1`，`r3=fp-8`，成功重写
- `sched_cls`，`offset=14`，`len=4`，成功重写，`r0=0` fast path 正确落到原 post-call check
- `sched_act`，两个 helper site，均能独立重写
- `call` 之后没有立即错误检查，仍然允许重写
- `mov32 imm` 形式的 `offset/len` 也能识别为常量
- basic-block 内经由寄存器 copy 的 `r2/r4` 也能识别

## 9.2 负例 / skip

- `imm != 26`
- `src_reg != 0` 的 call
- `prog_type` 不是 `SCHED_CLS/ACT`
- `call_pc` 是 branch target
- `offset` 非常量
- `len` 非常量
- `len == 0`
- `len > 8`
- `r3` 不是 `fp + const`
- `offset > i32::MAX`
- `offset + len > i32::MAX`

## 9.3 发射与控制流

- replacement 内部 `if r2 > r0 goto slow` 偏移正确
- `ja done` 偏移正确
- 多 site 同时改写后，原程序其他 branch 仍能通过 `fixup_all_branches()` 正确指向
- call 后原有 `if r0 != 0 goto error` 分支不需要额外改写，仍然工作

## 9.4 后续管线联动

- `skb_load_bytes_spec -> bounds_check_merge`
  - 构造两个相邻 helper site
  - 确认 specialization 后生成两段标准 `data/data_end + guard`
  - 后续 `BoundsCheckMergePass` 能继续合并

## 10. Corpus 机会

`docs/tmp/20260324/helper_call_inlining_research_20260324.md` 给出的关键数据：

- 总 `skb_load_bytes` site：`590`
- 按项目：`cilium 428`、`linux-selftests 81`、`calico 56`、`loxilb 16`
- 按可归因 prog_type：`sched_cls 532`、`flow_dissector 28`、`socket_filter 7`、`cgroup_skb 4`

这说明两件事：

1. v1 只开 `SCHED_CLS/ACT` 就已经覆盖了绝大多数真实收益面。
2. 最大受益者会是 Cilium 一类的 hot packet path。

长度分布上，最常见的 `len` 是：

- `2`: `166`
- `8`: `139`
- `4`: `88`
- `20`: `62`
- `1`: `61`
- `16`: `20`
- `40`: `18`
- `14`: `12`

因此：

- v1 若先支持 `1..=8`，已经直接命中 `1/2/4/8` 这些热点长度
- 只按公开列出的 top lengths 计算，`1/2/4/8` 这四档已经覆盖至少 `454` 个站点
- 后续再加 `14/16/20/40` 等大长度时，可以考虑更激进的 chunk plan，甚至是否保留某些长度继续走 helper

## 11. 实现顺序建议

1. 先实现 `PacketCtxLayout` 和 `supported_prog_type()`，范围只开 TC_ACT。
2. 再实现局部符号扫描，只做 `Ctx` / `Const` / `FpPlusConst`。
3. 然后实现“call-only replacement” emitter，先全部按 byte chunk。
4. 补齐单元测试和 skip reason 断言。
5. 最后再评估是否加 `2/4/8` 宽 chunk，以及是否扩到 `SK_SKB` / `FLOW_DISSECTOR`。

## 12. 结论

`SkbLoadBytesSpecPass` 最合适的 v1 形态不是“把 helper 完全删掉”，而是：

- 只在 `SCHED_CLS/ACT` 上工作
- 只处理 `offset/len` 静态常量、目标为栈的 site
- 只替换 `call #26` 这一条
- 在站点内部生成 fresh `ctx->data/data_end`、显式 bounds guard、byte-copy fast path 和原 helper slow path
- 保留原 call 后错误检查不动

这个方案和当前代码库完全契合：

- 匹配风格接近 `bounds_check_merge.rs`
- rewrite 方式接近 `map_inline.rs`
- 分支修正直接复用 `fixup_all_branches()`
- 生成结果还天然适合继续喂给 `bounds_check_merge`

对当前 590 个 `skb_load_bytes` site 来说，这是收益最高、语义风险最低、最适合作为 #444 首个落地实现的版本。
