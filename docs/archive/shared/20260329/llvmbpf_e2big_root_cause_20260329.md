# llvmbpf Round-Trip 导致 Tracee E2BIG/ENOSPC 的根因分析

日期：2026-03-29

## 结论

这轮 Tracee 失败里，`E2BIG` 和 `ENOSPC` 不是同一个问题。

- `E2BIG` 的根因是：round-trip 后的 eBPF 指令数稳定膨胀，跨过了 live program 既有的 `prog->pages` 页预算。主因不是 `opt -O2`，也不是 postprocess，而是 LLVM BPF backend lowering 之后出现的大量额外 stack spill/reload、helper call 参数清零、以及 64-bit 内存访问/清零被拆成更保守的 32-bit load/store 序列。
- `ENOSPC` 的根因和 code size 无关。当前 Tracee POC guest helper 直接走 `BPF_PROG_REJIT(log_level=2)`，只给 16 MiB verifier log buffer；这批 `ENOSPC` 更像 verifier log buffer 被打满，而不是 page budget、JIT image size、也不是 1M verifier complexity limit。

量化上，15 个 `E2BIG` 程序从原始 bytecode 到 round-trip bytecode 总共净增 `9352` 条指令，平均膨胀 `1.192x`，范围 `1.081x` 到 `1.229x`。其中最主要的净增量来自：

- stack access：`+6291`
- move/constant materialization：`+3550`
- non-stack memory access：`+2053`

这些正增量被一部分更少的 64-bit ALU/jump/helper call 抵消，所以净增最终落在 `+9352`。

## 输入与方法

本报告基于 VM 内 GET_ORIGINAL 产物和同一轮 host round-trip 工件：

- 会话：`docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/sessions/tracee_live_iter4_20260329_201647`
- 背景状态：`docs/tmp/20260329/llvmbpf_kernel_stack_fix_report_20260329.md`
- VM dump 路径：
  - `guest_helper/src/main.rs` 里的 `run_dump()` 调 `bpf_prog_get_info(..., true)`，把 `orig_prog_insns` 写成 `original.bin`
  - `daemon/src/bpf.rs` 的 `bpf_prog_get_info()` 明确说明 `fetch_orig=true` 会取 kernel `orig_prog_insns`

所以这里的 `original.bin` 是 VM 里 live program 的 `GET_ORIGINAL` 结果，不是 host 侧猜测。

## 内核限制到底是什么

### E2BIG 对应哪个限制

`BPF_PROG_REJIT` 里有 3 个会返回 `-E2BIG` 的地方：

1. `attr->rejit.insn_cnt > BPF_COMPLEXITY_LIMIT_INSNS`
2. `attr->rejit.fd_array_cnt > BPF_PROG_REJIT_MAX_FD_ARRAY`
3. `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE`

这批 Tracee `E2BIG` 明确不是前两个：

- round-trip 指令数都远小于 `1,000,000`
- 15 个 `E2BIG` 样本的 map 数只有 `8..24`，远低于 `BPF_PROG_REJIT_MAX_FD_ARRAY = 64`

因此真正命中的就是第 3 个 page-budget 检查。

相关代码路径：

- `vendor/linux-framework/kernel/bpf/syscall.c`
  - `3620-3624`: `insn_cnt` / `fd_array_cnt` 的早期 `-E2BIG`
  - `3760-3777`: `bpf_check(&tmp, ...)` 之后，用 `tmp->len` 做 page-budget 检查
- `vendor/linux-framework/include/linux/filter.h`
  - `1028-1031`: `bpf_prog_size(proglen) = max(sizeof(struct bpf_prog), offsetof(struct bpf_prog, insns[proglen]))`
- `vendor/linux-framework/vmlinux`
  - 用 `pahole -C bpf_prog` 验证：`offsetof(struct bpf_prog, insns) = 96`

### 为什么要强调 `tmp->len`

`BPF_PROG_REJIT` 不是直接拿用户提交的 `attr->rejit.insn_cnt` 去做最终 size check。内核先：

1. `tmp->len = attr->rejit.insn_cnt`
2. `bpf_check(&tmp, ...)`
3. `bpf_prog_select_runtime(tmp, ...)`
4. 再检查 `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE`

也就是说，最终触发 `E2BIG` 的是 verifier/runtime 处理后的 `tmp->len`，不是单纯的 `roundtrip.bin` 行数。

## 5 个 E2BIG 样本

### 原始 vs round-trip 指令数

| program | original insns | round-trip insns | delta | ratio |
| --- | ---: | ---: | ---: | ---: |
| `22_sys_exit_init` | 482 | 521 | +39 | 1.081x |
| `28_sys_dup_exit_tail` | 2342 | 2735 | +393 | 1.168x |
| `29_tracepoint__sched__sched_process_fork` | 4042 | 4911 | +869 | 1.215x |
| `36_tracepoint__sched__sched_process_exec` | 4364 | 5364 | +1000 | 1.229x |
| `42_syscall__accept4` | 1702 | 2032 | +330 | 1.194x |

15 个 `E2BIG` 样本整体统计：

- 净增：`+9352` insns
- 平均每个程序净增：`+623.5`
- 平均膨胀比例：`1.192x`
- 最小膨胀：`1.081x`
- 最大膨胀：`1.229x`

### 原始程序离 page budget 多远

用 `offsetof(struct bpf_prog, insns)=96` 和 `PAGE_SIZE=4096` 计算最小页预算时，5 个样本如下：

| program | original pages | original slack bytes | raw round-trip result |
| --- | ---: | ---: | --- |
| `22_sys_exit_init` | 1 | 144 | 超 168B |
| `28_sys_dup_exit_tail` | 5 | 1648 | 超 1496B |
| `29_tracepoint__sched__sched_process_fork` | 8 | 336 | 超 6616B |
| `36_tracepoint__sched__sched_process_exec` | 9 | 1856 | 超 6144B |
| `42_syscall__accept4` | 4 | 2672 | 原始 `roundtrip.bin` 仍剩 32B |

这里 `42_syscall__accept4` 很关键：

- 它的 `roundtrip.bin` 自身按 96B header 仍然能塞进 4 页，剩余 `32B`
- 但 `BPF_PROG_REJIT` 实际还是 `E2BIG`
- 由于 size check 用的是 `bpf_check()` 之后的 `tmp->len`，这意味着 verifier/runtime 只要再把它扩 `>= 5` 条 insn（`40B`）就会越线

换句话说：

- 14/15 个 `E2BIG` 程序，raw round-trip bytecode 已经足以解释 page-budget 溢出
- 只有 `42_syscall__accept4` 是边界 case，需要再叠加 verifier-side 的轻微扩张

## Bytecode 对比：大在哪里

### 一个代表性例子：`22_sys_exit_init`

原始程序在 map value 清零时，直接用 64-bit store：

```text
24: *(u64 *)(r0 +192) = r6
25: *(u64 *)(r0 +184) = r6
...
48: *(u64 *)(r0 +0) = r6
```

round-trip 后，同一段变成了 32-bit scalarized store：

```text
123: r1 = 0x0
124: *(u32 *)(r9 + 0xc4) = r1
125: *(u32 *)(r9 + 0xc0) = r1
...
173: *(u32 *)(r9 + 0x0) = r1
```

这类变化会把一串 `stxdw` 变成更多的 `stxw`，而且还多出一条 `mov imm 0`。

同一个程序在 helper call 入口也更臃肿。原始开头很短：

```text
0: r9 = r1
1: call 35
2: r7 = r0
3: call 14
4: *(u32 *)(r10 -84) = r0
```

round-trip 开头变成了：

```text
0: r7 = r1
1: r1 = 0x0
2: *(u64 *)(r10 - 0x80) = r1
3: r1 = r7
4: r2 = 0x0
5: r3 = 0x0
6: r4 = 0x0
7: r5 = 0x0
8: call 0x23
9: *(u64 *)(r10 - 0x90) = r0
```

多出来的是：

- helper arg 清零
- helper return spill 到 stack
- 后续再从 stack reload

### `42_syscall__accept4` 也是同一模式

它虽然只是 `+330` insns，但增长来源仍然是同一类形态：

- `ldx_dw_stack +192`
- `ldx_w_mem +145`
- `mov64_x +143`
- `lsh64_imm +58`
- `or64_x +58`

也就是说，这不是“大程序特有 bug”，而是 lowering 形态本身不够紧凑。`accept4` 只是刚好踩在 page-budget 边上。

### 5 个样本的净增构成

下面把每个样本的净增按大类拆开。这个分桶是互斥的，能精确求和回总 delta。

| program | net delta | stack access | move/const | non-stack mem | ALU | control | helper calls |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `22_sys_exit_init` | +39 | +29 | +45 | +31 | -36 | -22 | -8 |
| `28_sys_dup_exit_tail` | +393 | +358 | +65 | +96 | -52 | -57 | -17 |
| `29_tracepoint__sched__sched_process_fork` | +869 | +491 | +232 | +265 | +51 | -120 | -50 |
| `36_tracepoint__sched__sched_process_exec` | +1000 | +592 | +297 | +257 | -57 | -70 | -19 |
| `42_syscall__accept4` | +330 | +215 | +72 | +91 | -6 | -33 | -9 |

### 全部 15 个 E2BIG 的净增构成

| bucket | net delta | interpretation |
| --- | ---: | --- |
| stack access | +6291 | 新增 spill/reload 是绝对主因 |
| move/const | +3550 | helper marshaling 和寄存器搬运明显增加 |
| non-stack mem | +2053 | 64-bit field access / zero-fill 被拆成更多内存指令 |
| ALU | -1407 | 一部分 64-bit ALU 被更保守 lowering 替换掉 |
| control | -872 | 原始程序里一些 jump 反而更少 |
| helper calls | -263 | helper call 本身没有变多，问题在 call 周围的铺垫 |

结论很直接：真正把程序撑大的不是 `call` 数量，而是 `call` 前后的搬运/落栈/回栈。

### 更细的“形态级”证据

下面这些不是互斥分桶，而是 gross instruction-shift，用来说明“多出来的指令是什么”：

- stack spill/reload：
  - `ldx_dw_stack +5505`
  - `stx_dw_stack +706`
- 64-bit 内存访问被拆成 32-bit halves：
  - `ldx_w_mem +2376`
  - `lsh64_imm +1030`
  - `or64_x +1056`
  - 同时 `ldx_dw_mem -1229`
- 64-bit 清零/写回被拆成窄 store：
  - `stx_w_mem +1784`
  - 同时 `stx_dw_mem -820`
- helper marshaling / 常量物化：
  - `mov64_x +2161`
  - `mov64_imm0 +1331`
  - `ldimm64 pair +1238`
  - 同时 `mov64_imm -2125`

这些形态和肉眼看 disassembly 的感觉一致：

- 多出来的不是 NOP
- 主体不是 verifier patch-up
- 主要是 stack traffic、冗余 MOV、helper call marshaling、32-bit scalarization

## LLVM IR 对比：opt -O2 在缩小，不是在放大

### lifted IR 的确先是“寄存器全内存化”

`22_sys_exit_init/lifted.ll` 开头是：

```llvm
%r0 = alloca i64, align 8
%r1 = alloca i64, align 8
...
%r10 = alloca i64, align 8
store i64 0, ptr %r0, align 4
...
%stackBegin = alloca i8, i32 120, align 8
%stackEnd = getelementptr i8, ptr %stackBegin, i32 120
store ptr %stackEnd, ptr %r10, align 8
```

这是 llvmbpf lifter 的“寄存器 alloca + 单个真实栈对象”形态。

### 但 `opt -O2` 已经把它压扁了

同一个程序的 `opt.bc` 反汇编后只剩一个真实栈对象：

```llvm
%stackBegin663 = alloca [120 x i8], align 8
%stackEnd = getelementptr inbounds i8, ptr %stackBegin663, i64 120
...
call void @llvm.memset.p0.i64(..., i64 200, ...)
```

`sched_process_fork` 也一样：`lifted.ll` 里是 12 个 alloca，`opt -O2` 后只剩 1 个。

### IR 统计

| program | IR | total inst | alloca | phi | call | load | store | memset |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `sys_exit_init` | lifted | 1597 | 12 | 0 | 55 | 723 | 448 | 0 |
| `sys_exit_init` | opt-O2 | 253 | 1 | 6 | 49 | 47 | 24 | 3 |
| `sched_process_fork` | lifted | 13574 | 12 | 0 | 337 | 5988 | 3577 | 0 |
| `sched_process_fork` | opt-O2 | 3339 | 1 | 239 | 299 | 553 | 461 | 11 |

这说明：

- `opt -O2` 已经把 lifter 的大部分 memory-form 清掉了
- 剩余膨胀来自优化后的 IR 被 BPF backend lowering 时，落成了更保守、更不紧凑的 BPF 序列

### 直接跳过 opt，反而会更大

对 5 个样本直接 `llc lifted.ll`，不经过 `opt -O2`，结果反而更糟：

| program | llc on lifted.ll | opt -O2 final | shrink |
| --- | ---: | ---: | ---: |
| `sys_exit_init` | 1159 | 521 | 2.22x |
| `sys_dup_exit_tail` | 5778 | 2735 | 2.11x |
| `sched_process_fork` | 10211 | 4911 | 2.08x |
| `sys_enter_submit` | 9755 | 4609 | 2.12x |
| `sched_process_exec` | 11475 | 5364 | 2.14x |

所以 `opt -O2` 不是放大器，而是大幅缩小器。

### `-Oz` 也救不了

`size_opt_experiments/` 里 4 个代表程序的结果是：

| program | O1 | O2 | O3 | Os | Oz |
| --- | ---: | ---: | ---: | ---: | ---: |
| `sys_exit_init` | 522 | 521 | 521 | 521 | 521 |
| `sys_dup_exit_tail` | 2719 | 2735 | 2735 | 2735 | 2735 |
| `sched_process_fork` | 4873 | 4911 | 4911 | 4911 | 4911 |
| `sys_enter_submit` | 4640 | 4609 | 4609 | 4609 | 4609 |

结论：

- `-Oz` 基本和 `-O2` 一样
- `-O1` 在个别样本上略小，但差距只有十几到几十条 insns，远不足以把 E2BIG 大样本救回来

## postprocess 和 subprogram handling 贡献很小

5 个样本里，`roundtrip_raw.bpf.o` 到最终 `roundtrip.bin` 的增量几乎为零：

| program | raw .text insns | final roundtrip insns | postprocess delta | appended original subprog insns |
| --- | ---: | ---: | ---: | ---: |
| `22_sys_exit_init` | 521 | 521 | +0 | 0 |
| `28_sys_dup_exit_tail` | 2722 | 2735 | +13 | 13 |
| `29_tracepoint__sched__sched_process_fork` | 4911 | 4911 | +0 | 0 |
| `36_tracepoint__sched__sched_process_exec` | 5364 | 5364 | +0 | 0 |
| `42_syscall__accept4` | 2032 | 2032 | +0 | 0 |

只有 `sys_dup_exit_tail` 因为 pseudo-call hybrid append 多了 `13` 条，其余样本都是 `0`。

所以：

- map relocation postprocess 不是主因
- subprogram append 只解释一个样本里的极小增量

## ENOSPC：不是 code size 限制

当前 Tracee POC guest helper 的 REJIT 路径是：

- `guest_helper/src/main.rs:568`
  - 直接调用 `bpf_prog_rejit_capture_verifier_log(...)`
- `daemon/src/bpf.rs:1679-1687`
  - 固定分配 `16 MiB` log buffer
  - 直接走 `run_rejit_once(..., log_level=2, ...)`
- `daemon/src/bpf.rs:1576-1627`
  - 失败时只返回当前 buffer 里的字符串，不暴露 `log_true_size`

这意味着当前 Tracee 会话里的 `ENOSPC`，首先要怀疑的是 verifier log buffer 被打满。

证据：

1. 8 个 `ENOSPC` 里有 2 个程序 round-trip 后反而变小：

   - `31_lkm_seeker_kset_tail`: `14857 -> 14800`
   - `33_lkm_seeker_proc_tail`: `13806 -> 13658`

   如果 `ENOSPC` 是 page budget / JIT image size，这两个不应该因为“变小”还继续触发。

2. verifier log 里已经能看到：

   - `processed 169197 insns (limit 1000000)`
   - `processed 704492 insns (limit 1000000)`
   - `processed 787434 insns (limit 1000000)`

   都低于 `1,000,000`，所以不是 complexity limit。

3. 这 8 个 `ENOSPC` 样本的 helper `#12`（tail call）数量只有 `0..2`，远不像 poke descriptor 上限问题。

因此当前最稳的结论是：

- `ENOSPC` 对应的是 `BPF_PROG_REJIT(log_level=2)` 这条路径上的 verifier log buffer 空间不足
- 它不是这一轮 round-trip code-size 膨胀的直接体现

## 根因归纳：到底是哪几个原因

按照你给的备选项，结论如下。

### 1. llvmbpf lifter 的 synthetic scaffolding

不是当前主因。

证据：

- kernel-compatible 模式已经去掉旧的 multi-page synthetic stack / call stack
- `opt -O2` 后只剩 1 个真实栈对象，不再是 `r0..r10` 全内存化的最终形态

### 2. LLVM opt 引入冗余

不是主因，而且方向相反。

证据：

- 不做 `opt -O2` 会再放大约 `2.08x..2.22x`
- `-Oz` 基本不比 `-O2` 更小

### 3. LLVM BPF backend lowering 不紧凑

是主因。

具体表现：

- 新增大量 stack spill/reload
- helper call 周围出现成批参数清零和寄存器搬运
- 64-bit field access / zero-fill 被拆成 32-bit load/store + shift/or

### 4. llc prologue/epilogue 开销

有贡献，但只是 “backend lowering 不紧凑” 的一部分，不是独立主因。

### 5. map relocation post-processing

贡献极小。

- 4/5 样本 `+0`
- 1/5 样本 `+13`

### 6. subprogram handling 导致代码复制

只在 `sys_dup_exit_tail` 里看到 `+13`，不是 Tracee `E2BIG` 主体。

## 最终定量归因

如果只看 15 个 `E2BIG` 程序，最稳的定量归因是：

1. 主因：backend 产生的 stack spill/reload
   - 净增 `+6291`
   - 占总净增 `9352` 的 `67.3%`
2. 次因：helper marshaling / register shuffling / constant materialization
   - 净增 `+3550`
   - 占总净增的 `38.0%`
3. 次因：non-stack memory scalarization
   - 净增 `+2053`
   - 占总净增的 `22.0%`
4. 可忽略：postprocess / subprogram append
   - 典型样本里 `+0`
   - 最多只看到 `+13`

注意第 1-3 项不是简单相加关系，因为后两项的一部分又被更少的 64-bit ALU/jump/helper call 抵消了；真正的净增总量仍然是 `+9352`。

## 一句话版

Tracee 这批 `E2BIG` 的根因不是“llvmbpf lift 之后 IR 变胖”，也不是 “opt 把程序做大了”，而是：

> `lifted IR --opt(O2)--> 合理的 SSA IR --llc/backend lowering--> 不够紧凑的 BPF`

最后落地成：

- 更多 stack spill/reload
- 更多 helper call marshaling
- 更多 32-bit scalarized load/store

于是把本来已经靠近 live page budget 的 Tracee 程序推过了 `prog->pages` 上限。
