# BpfReJIT 内核代码膨胀审查报告 (2026-03-20)

## 概览

当前 diff：17 files, +6612/-263 = net +6349 行（git diff master --stat）。
本报告逐文件审查是否有不必要的代码膨胀，并给出可削减的估算。

---

## 1. jit_validators.c (1791 行) — 最大文件

### 1.1 结构评价

该文件包含 7 个 canonical form 的 pattern validator（ZERO_EXT_ELIDE 已删除），
采用 **parse_shape + fill_params + validate_rule** 三层结构。这个结构是合理的——
每个 form 的 BPF pattern 完全不同（COND_SELECT 检查 diamond/compact/guarded_update，
WIDE_MEM 检查 load-shift-or chain，ROTATE 检查 4 种变体，BRANCH_FLIP 检查
if/else diamond），不存在可以跨 form 提取的通用 pattern matcher。

### 1.2 发现的重复/可优化点

#### (a) `bpf_jit_alu32_insn_linearizable` vs `bpf_jit_alu64_insn_linearizable` (行 760-828)
这两个函数有 ~90% 的相同逻辑，唯一区别是：
- ALU32 检查 `BPF_CLASS == BPF_ALU`，ALU64 检查 `BPF_ALU64`
- ALU64 的 DIV/MOD 始终返回 true（不检查 off==0）
- ALU64 的 MOV 额外检查 `insn_is_cast_user` 和 `insn_is_mov_percpu_addr`
- ALU64 的 MOV 多一个 `off == 32` case

可以合并为一个 `bpf_jit_alu_insn_linearizable(insn, width)` 函数。
**估算节省：~25 行。**

#### (b) `bpf_jit_is_cmov_cond_jump` vs `bpf_jit_cond_op_valid` (行 10-34, 1612-1633)
这两个函数几乎完全相同——都是检查 BPF conditional jump opcodes。
`bpf_jit_is_cmov_cond_jump` 额外检查了 class 和 source，而 `bpf_jit_cond_op_valid`
只检查 op code。但 `bpf_jit_is_cmov_cond_jump` 调用处已经在外层做了 class 检查。
可以让 `bpf_jit_is_cmov_cond_jump` 调用 `bpf_jit_cond_op_valid`。
**估算节省：~10 行。**

#### (c) x86-specific code 在 arch-neutral validator 里 (行 1315-1511)
`bpf_jit_branch_flip_x86_cmp_max_native_bytes`、
`bpf_jit_branch_flip_x86_insn_max_native_bytes`、
`bpf_jit_branch_flip_x86_body_native_bytes` 等函数是**纯 x86 架构特定的**
native 字节长度估算。它们被放在 `kernel/bpf/jit_validators.c`（arch-neutral）中，
这是一个**设计问题**：ARM64 不需要这些代码，但编译时仍然包含。

这 ~90 行应该通过 weak function 或 arch callback 移到 `arch/x86/net/`。
不过当前 ARM64 的 BRANCH_FLIP 不支持（form_meta 里没有条件检查 ARM64），
所以这段代码只在 x86 上被调用，实际不影响正确性——但这是不干净的设计。
**可迁移：~93 行（不减少 net LOC，但改善 arch 分离）。**

#### (d) param_set 小函数族 (行 223-264)
`bpf_jit_param_set_reg`、`bpf_jit_param_set_imm`、`bpf_jit_param_set_ptr`、
`bpf_jit_param_set_value` 加上 `bpf_jit_cond_select_get_mov_value`——5 个小函数共 ~42 行。
这些函数被所有 validator 的 fill_params 路径使用，是合理的封装。
考虑到内核代码风格和安全需求（每个赋值路径清晰可审计），保留是合理的。
**不建议合并。**

### 1.3 结论

jit_validators.c 的核心逻辑（7 个 form 各自的 pattern matching）没有显著重复。
每个 form 的匹配逻辑本质不同。可优化的地方主要是 (a)(b) 两处小重复，
总共可省 ~35 行。x86-specific 代码放错位置 (c) 是设计问题但不减少总 LOC。

**总评：1791 行对 7 个 form 平均 256 行/form，合理。可削减 ~35 行 (~2%)。**

---

## 2. arch/x86/net/bpf_jit_comp.c (+2160 行)

### 2.1 最大膨胀点：`emit_bpf_alu32_insn` + `emit_bpf_alu64_insn` + `emit_linear_bpf_insn`

这三个函数（共 ~500 行）是为 BRANCH_FLIP 而添加的——需要能在 canonical emitter
内部独立 emit 任意 ALU/LDX 指令。然而，`do_jit()` 主循环里已经有完全相同的
ALU emission 代码。这是**最大的代码膨胀来源**。

**重复程度**：`emit_bpf_alu32_insn` (行 872-1062) 和 `emit_bpf_alu64_insn`
(行 1191-1388) 几乎是 `do_jit()` 里 ALU 分支的逐字复制，唯一区别是：
- 接受 `use_priv_fp` 参数用于 FP register remapping
- 返回 int 而不是直接在 do_jit 上下文中操作

理论上可以重构 `do_jit()` 里的 ALU 代码为独立函数，然后两处共享。
但这需要大规模重构 `do_jit()` 本身（目前是一个巨大的 switch case），
在内核 upstream 场景下风险较高。

**估算重复：~420 行。如果重构可省 ~350 行，但重构风险高。**

### 2.2 opcode mapping 函数的重复

- `bpf_jmp_invert` (38 行)：BPF jump op 反转表
- `bpf_jmp_to_x86_cond` (34 行)：BPF jump op -> x86 jcc opcode
- `bpf_jmp_to_x86_cmov` (34 行)：BPF jump op -> x86 CMOVcc opcode

这些都是 switch-case 形式的 opcode 映射表，~106 行。可以用 lookup table
（数组索引）替代 switch-case，但内核代码风格倾向于显式 switch。
`bpf_jmp_to_x86_cond` 在原有 `do_jit()` 代码里其实已有类似映射（通过
`X86_JA` 等宏和内联 case），但格式不同，不能直接共享。

**估算可省：~30 行（用 const array 替代 switch，但收益有限，风格偏好问题）。**

### 2.3 `emit_bpf_jmp_cmp` (84 行)

从 `do_jit()` 的 JMP handler 中提取的比较指令 emitter。这是必要的——被
COND_SELECT 和 BRANCH_FLIP 两个 emitter 共享。**合理，不重复。**

### 2.4 per-form canonical emitters

| 函数 | 行数 | 评价 |
|------|------|------|
| `emit_canonical_select` | ~88 | 逻辑复杂（3 种 pattern、noop 优化），合理 |
| `emit_canonical_wide_load` | ~40 | 含 `emit_wide_load_sequence`，合理 |
| `emit_canonical_rotate` | ~63 | RORX + ROR 两种 native choice，合理 |
| `emit_canonical_lea_fusion` | ~23 | 简洁 |
| `emit_canonical_bitfield_extract` | ~62 | 含 BEXTR VEX encoding，合理 |
| `emit_canonical_endian_fusion` | ~24 | MOVBE load/store，简洁 |
| `emit_canonical_branch_flip` | ~72 | 最复杂的 emitter，合理 |

总计 ~372 行。这些是核心代码，每个 form 的 x86 lowering 本质不同，无重复。

### 2.5 helper 函数

`emit_or64_reg`、`emit_lsh64_imm`、`emit_bswap_width`、`pick_wide_chunk`、
`wide_chunk_bpf_size`、`emit_movbe_load`、`emit_movbe_store` 等小 helper 共 ~120 行。
其中 `pick_wide_chunk` 和 `bitfield_mask_width` 在 ARM64 有完全相同的实现
（见下文 3.1）。

### 2.6 其他新增

- `emit_mov_imm32_noflags` (22 行)：避免 XOR-zero 破坏 flags，被 COND_SELECT 使用。合理。
- `emit_st_imm32` (8 行) + `emit_store_stack_imm64` 优化路径 (5 行)：小优化。
- `emit_priv_frame_ptr` 重排（0 行 net change，只是被移动了）。
- `bpf_jit_rule_lookup_prog` + `bpf_jit_try_emit_rule` (63 行)：JIT 主循环入口。简洁。
- `bpf_jit_arch_form_supported` (40 行)：CPU feature 检测。必需。

### 2.7 结论

**x86 的 2160 行新增中，约 420 行是 `do_jit()` ALU emission 的近乎逐字复制。**
这是最大的膨胀来源。其余 ~1740 行是 7 个 canonical emitter + helper + plumbing，
密度合理。

**可削减估算：理论上 ~350 行（通过重构 do_jit ALU 为共享函数），实践中考虑到
kernel upstream 难度和重构风险，short-term 可省 ~30 行（opcode table 优化）。**

---

## 3. arch/arm64/net/bpf_jit_comp.c (+853 行)

### 3.1 跨 arch 重复代码

以下函数在 x86 和 ARM64 中有**几乎相同的实现**：

| 函数 | x86 版本 | ARM64 版本 | 行数 |
|------|----------|-----------|------|
| `binding_value_is_noop` | `bpf_jit_binding_value_is_noop` | `arm64_binding_value_is_noop` | 4 |
| `pick_wide_chunk` | `pick_wide_chunk` | `arm64_pick_wide_chunk` | 7 |
| `bitfield_mask_width` | `bitfield_mask_width` | `arm64_bitfield_mask_width` | 9 |

这些是纯算法函数（不涉及 arch 特定 encoding），理论上可以提到 `kernel/bpf/` 的
共享 header 或 .c 文件中。但总共只有 ~20 行重复，在内核代码中这种级别的重复
通常被接受（避免跨 subsystem 的依赖）。

**估算可省：~20 行（通过提到 bpf_jit_directives.h 为 static inline）。**

### 3.2 ARM64 emitter 密度

ARM64 支持 4 个 form（ROTATE, WIDE_MEM, BITFIELD_EXTRACT, COND_SELECT），
共 ~625 行 emitter + ~100 行 helper + ~128 行 plumbing。
每个 form 的 ARM64 lowering 天然比 x86 简洁（ARM64 有 ROR, UBFX, CSEL 指令）。

### 3.3 `a64_invert_cond` (30 行)

ARM64 insn 库应该已有类似函数，但检查后 `AARCH64_INSN_COND_*` 的 encoding
规律是 `cond ^ 1`——可以用 1 行 `*inv = cond ^ 1` 替代 30 行 switch-case。
**估算可省：~28 行。**

### 3.4 结论

**ARM64 的 853 行合理，密度高（4 个 form，ARM64 指令天然对齐）。**
可优化 ~48 行（20 行跨 arch 重复 + 28 行 cond_invert 简化）。

---

## 4. jit_directives.c (744 行)

### 4.1 结构

这个文件是 recompile 的 orchestration 层——snapshot/rollback state machine、
多 subprog image 管理、ksym 替换、trampoline regeneration 触发。

### 4.2 发现的重复

#### (a) `bpf_jit_recompile_prog_images` 中的 image_prog 查找模式
```c
struct bpf_prog *image_prog = main_aux->func_cnt && main_aux->func ?
    main_aux->func[i] : prog;
```
这个 pattern 出现了 **7 次**。可以提取为 `get_image_prog(main_aux, i, prog)` helper。
**估算可省：~10 行 + 可读性提升。**

#### (b) ksym_prog 查找 pattern
类似的 ksym_prog 三元表达式出现了 3 次。
**估算可省：~8 行。**

### 4.3 log 函数 (行 37-85)

`bpf_jit_recompile_prog_log` 和 `bpf_jit_recompile_rule_log` 共 ~48 行。
是标准的 variadic log wrapper，必需，不冗余。

### 4.4 结论

**744 行合理。主要复杂度在于 rollback state machine 和多 subprog image 管理。
可削减 ~18 行（helper 提取）。**

---

## 5. jit_policy.c (436 行)

### 5.1 结构评价

Policy blob parsing（memfd seal 验证、header 检查、v2 format 解析）+ binary search
lookup。非常干净的单一职责文件。

### 5.2 发现

- `bpf_jit_rule_within_single_subprog` (38 行)：subprog boundary 检查，复杂但必需。
- `bpf_jit_parse_policy` (170 行)：多层 validation 的 early-return 风格，每个
  check 约 7-10 行（包括 error log）。可以更紧凑但会牺牲可读性。
- arch validation 的 `#if defined` 块 (行 320-342)：可以用 build-time const
  `BPF_JIT_ARCH_CURRENT` 简化，但 ~22 行不值得。

### 5.3 结论

**436 行高密度，无显著膨胀。可削减 ~0 行。**

---

## 6. bpf_jit_directives.h (256 行)

### 6.1 结构

参数枚举定义（7 个 form x 平均 5 个 param = ~70 行）、结构体定义、
API 声明、conditional inline stubs。

### 6.2 Conditional stubs (行 207-254)

`#else` 分支的 stub 函数（~47 行）是标准的内核 header 模式，用于
非 x86/ARM64 架构的编译。**不可省。**

### 6.3 结论

**256 行合理。纯 type/API 定义，无膨胀。**

---

## 7. trampoline.c (+242 行)

### 7.1 功能

`bpf_prog_regenerate_trampolines` 在 JIT recompile 后重新生成
trampoline 使其指向新 JIT image。这是 post-recompile 正确性的关键路径。

### 7.2 评价

242 行中大部分是 trampoline state 的保存/恢复逻辑和 error handling。
没有发现重复或不必要的代码。

### 7.3 结论

**242 行合理。**

---

## 8. 其他文件

| 文件 | 新增行 | 评价 |
|------|--------|------|
| include/linux/bpf.h | +64 | 必需的 aux 字段（staged image 管理） |
| include/linux/filter.h | +1 | `bpf_jmp_offset` helper |
| include/uapi/linux/bpf.h | +94 | UAPI 常量定义（form/choice enum + syscall attr） |
| tools/include/uapi/linux/bpf.h | +95 | 上述 UAPI 的 tools/ 镜像拷贝 |
| kernel/bpf/core.c | +117 | recompile staging 基础设施 |
| kernel/bpf/helpers.c | +6 | `bpf_jit_supports_recompile` |
| kernel/bpf/syscall.c | +4 | syscall dispatch |
| kernel/bpf/verifier.c | +2 | verifier hook |
| kernel/bpf/Makefile | +1 | 新文件注册 |

以上都是必需的 plumbing，无膨胀。

---

## 9. 总结

### 可削减空间汇总

| 位置 | 描述 | 估算可省行数 | 难度 |
|------|------|:----:|------|
| x86: emit_bpf_alu32/64_insn | do_jit ALU 代码的近乎逐字复制 | ~350 | 高（需重构 do_jit） |
| x86: opcode mapping switches | 可用 array 替代 | ~30 | 低 |
| ARM64: a64_invert_cond | `cond ^ 1` 一行替代 | ~28 | 低 |
| validators: alu32/alu64 linearizable | 合并为统一函数 | ~25 | 低 |
| 跨 arch 重复 (pick_wide_chunk 等) | 提到 shared header | ~20 | 低 |
| directives: image_prog helper | 提取重复查找 pattern | ~18 | 低 |
| validators: cond_op_valid 复用 | 消除 switch 重复 | ~10 | 低 |
| **Total** | | **~481** | |

### 现实可行的短期优化

排除 do_jit 重构（高风险），短期可省 ~131 行（低难度项之和）。

### 最终判断

**当前 6349 行净增中：**
- ~4100 行是不可避免的核心代码（7 个 form 的 validator + 两架构的 emitter + orchestration + policy + UAPI + plumbing）
- ~420 行是 ALU emission 的 do_jit 复制（最大膨胀源，但重构风险高）
- ~130 行是零散重复/可简化（低难度可优化）
- 其余 ~1700 行是合理的 helper/plumbing/error handling

**结论：6349 行对于一个支持 7 个 canonical form、2 个架构、完整 orchestration
+ policy + UAPI 的内核子系统来说，是合理的规模。主要膨胀来源是 BRANCH_FLIP
的 ALU emission 复制（~420 行），这是目前最值得优化的点，但需要仔细重构
do_jit() 这个核心函数。短期可通过低风险优化省 ~130 行。**

**对于 paper 来说，6k 行内核修改对于一个 OSDI-tier 原型系统是正常的量级
（参考 sched_ext ~5k 行、XRP ~2k 行 + firmware）。当前代码质量是干净的，
没有 dead code 或 unreachable 分支。**
