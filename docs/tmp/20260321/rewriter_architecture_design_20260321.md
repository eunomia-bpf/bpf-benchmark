# BpfReJIT v2 Bytecode Rewriter 架构设计

日期: 2026-03-21

## 0. 目标

设计一个完整的 **BPF bytecode rewriter**，实现：

```
原始 BPF insns (GET_ORIGINAL) + 元信息 → 分析 → pattern match → 变换决策 → bytecode rewrite → 验证 → 新 BPF insns (REJIT)
```

输出的新 insns 数组可直接传给 `BPF_PROG_REJIT`，kernel 执行完整 re-verify + re-JIT + image swap。

---

## 1. 输入与输出

### 1.1 输入

```cpp
struct RewriterInput {
    // 原始 BPF 指令流（从 BPF_PROG_GET_ORIGINAL / bpf_prog_info.orig_prog_insns 获取）
    std::vector<bpf_insn> orig_insns;

    // 程序元信息
    uint32_t prog_id;
    uint32_t prog_type;         // BPF_PROG_TYPE_XDP, BPF_PROG_TYPE_SCHED_CLS, etc.
    uint32_t expected_attach_type;
    std::string prog_name;
    std::array<uint8_t, 8> prog_tag;

    // Map 信息（从 bpf_prog_info.map_ids 获取）
    std::vector<uint32_t> map_ids;

    // 可选：BTF 信息
    uint32_t btf_id;            // 0 = 无 BTF
    uint32_t nr_func_info;
    uint32_t nr_line_info;

    // 可选：profiling 数据
    struct ProfileData {
        uint64_t run_cnt;
        uint64_t run_time_ns;
        // branch_flip 需要的 per-branch taken/not-taken 计数
        // 当前阶段暂不实现
    };
    std::optional<ProfileData> profile;

    // 平台能力
    uint32_t cpu_features;      // BPF_JIT_X86_CMOV | BPF_JIT_X86_BMI2 | ...

    // kfunc BTF ID 缓存（daemon 启动时预解析）
    struct KfuncRegistry {
        int32_t rotate64_btf_id;    // -1 = 不可用
        int32_t select64_btf_id;
        int32_t extract64_btf_id;
    };
    KfuncRegistry kfunc_ids;
};
```

### 1.2 输出

```cpp
struct RewriterOutput {
    // 新的完整 BPF 指令数组，可直接传给 BPF_PROG_REJIT
    std::vector<bpf_insn> new_insns;

    // 是否有实际变换（如果无，不调用 REJIT）
    bool has_transforms;

    // 变换摘要
    struct TransformSummary {
        uint32_t orig_insn_cnt;
        uint32_t new_insn_cnt;
        uint32_t sites_applied;
        uint32_t sites_skipped;
        std::vector<std::string> families_applied;  // e.g. ["wide", "rotate"]
        std::vector<std::string> skip_reasons;
    };
    TransformSummary summary;

    // 可选：fd_array（当引入 module kfunc 时需要）
    // 当前阶段：只用 vmlinux kfunc，fd_array 为空
    std::vector<int> fd_array;

    // 诊断信息
    std::vector<std::string> warnings;
};
```

---

## 2. Pipeline 设计

### 2.1 总览

```
┌─────────────────────────────────────────────────────────────────────┐
│                      Rewriter Pipeline                              │
│                                                                     │
│  ┌──────────┐   ┌──────────┐   ┌──────────┐   ┌──────────┐        │
│  │  Parse &  │   │  Pattern  │   │ Transform │   │ Emit &   │        │
│  │  Analyze  │──>│  Match    │──>│ Decision  │──>│ Fixup    │        │
│  │          │   │          │   │          │   │          │        │
│  └──────────┘   └──────────┘   └──────────┘   └──────────┘        │
│       │              │              │              │                │
│    InsnStream     SiteList      RewritePlan    NewInsns            │
│    CFGInfo        + Bindings    (filtered)     + BranchFixup      │
│    BranchTargets                                                   │
│    SubprogBounds                                                   │
└─────────────────────────────────────────────────────────────────────┘
```

### 2.2 阶段 1: Parse & Analyze

**目的**：解析原始 insn 流，构建程序结构信息。

```cpp
struct InsnInfo {
    bool is_branch_target;    // 有其他指令跳到这里
    bool is_subprog_entry;    // BPF-to-BPF subprog 入口
    bool is_ldimm64_hi;       // LD_IMM64 的第二条（不可独立寻址）
    int32_t subprog_id;       // 所属 subprog，-1 = main
};

struct CFGInfo {
    uint32_t insn_cnt;
    std::vector<InsnInfo> insn_info;

    // branch_target_set[i] = true 表示 insn[i] 是某个跳转的目标
    std::vector<bool> branch_target_set;

    // subprog 边界：[start, end) 对
    struct SubprogRange {
        uint32_t start;
        uint32_t end;
    };
    std::vector<SubprogRange> subprogs;
};
```

**算法**：

```
procedure analyze(insns):
    1. 遍历所有指令，标记 LD_IMM64（双宽指令，insn[i].code == 0x18）
       - insn[i+1] 标记为 is_ldimm64_hi = true

    2. 收集所有 branch target：
       for each insn[i]:
         if is_jmp_class(insn[i]):
           if is_conditional_jump(insn[i]) or is_ja(insn[i]):
             target = i + 1 + insn[i].off    // JA32 用 insn[i].imm
             branch_target_set[target] = true
           if insn[i].code == (BPF_JMP | BPF_CALL) and insn[i].src_reg == BPF_PSEUDO_CALL:
             target = i + 1 + insn[i].imm
             branch_target_set[target] = true
             mark target as subprog_entry

    3. 构建 subprog 范围（如果有 BPF_PSEUDO_CALL）
       - subprog entry 排序，每个到下一个 entry（或末尾）为一个 subprog

    4. 返回 CFGInfo
```

### 2.3 阶段 2: Pattern Match

**目的**：在 insn 流上发现所有可重写站点。

**直接复用** scanner 的 `scan_v5_builtin()` 核心，但需要改输出类型：

```cpp
struct RewriteBinding {
    std::string name;           // e.g. "dst_reg", "base_off", "shift_amount"
    enum Kind { Reg, Imm, Off } kind;
    int64_t value;
};

struct RewriteSite {
    V5Family family;
    std::string pattern_kind;   // e.g. "wide-load-4", "rotate-64", "cond-select-64"
    uint32_t start_pc;          // 站点在原始 insn 流中的起始偏移
    uint16_t old_len;           // 原始指令数
    uint16_t canonical_form;
    uint16_t native_choice;

    // 从 pattern matcher 捕获的 bindings（寄存器、立即数）
    std::vector<RewriteBinding> bindings;

    // 安全性检查结果
    bool has_interior_branch_target;  // 外部跳转落入 site 内部
    bool crosses_subprog_boundary;    // 跨越 subprog 边界
    bool overlaps_ldimm64;            // 切断了 LD_IMM64

    // kfunc rewrite 需要的额外信息
    // 未来扩展：live_in_mask, live_out_mask（用于判断 caller-saved 冲突）
};

struct ScanResult {
    std::vector<RewriteSite> sites;
    uint64_t site_counts_by_family[8];  // 按 family 统计
};
```

**与现有 scanner 的关系**：

现有 `match_v5_pattern_at()` + `check_v5_constraints()` + 各 `build_v5_*_descriptors()` 可以 **直接复用**。需要改的是：

1. `make_v5_policy_rule()` 改为 `make_rewrite_site()`，增加 bindings 导出
2. `scan_v5_builtin()` 返回 `ScanResult` 而非 `V5ScanSummary`
3. 在 scan 后做 safety check（interior edge、subprog boundary、LD_IMM64 切割）

**复用方式**：在 `match_v5_pattern_at()` 中，`vars[]` 数组已经捕获了所有 pattern variable 的值。目前这些值被丢弃（只保留 site_start/site_len）。rewriter 需要把它们导出到 `RewriteBinding` 中。具体改动约 50 行。

### 2.4 阶段 3: Transform Decision

**目的**：过滤不安全/不值得的站点，确定最终要重写的集合。

```cpp
struct RewritePlan {
    // 排序后的、非重叠的、安全的站点列表
    std::vector<RewriteSite> sites;

    // 被跳过的站点及原因
    struct SkippedSite {
        RewriteSite site;
        std::string reason;
    };
    std::vector<SkippedSite> skipped;
};
```

**过滤规则**：

```
procedure decide(scan_result, cfg_info, policy):
    1. 标记不安全站点：
       for each site in scan_result.sites:
         if site.has_interior_branch_target:
           skip("外部 branch 落入 site 内部")
         if site.crosses_subprog_boundary:
           skip("跨越 subprog 边界")
         if site.overlaps_ldimm64:
           skip("切断 LD_IMM64")

    2. 过滤 kfunc 依赖：
       if site.family == Rotate and kfunc_ids.rotate64_btf_id < 0:
         skip("bpf_rotate64 kfunc 不可用")
       // 同理 select64, extract64

    3. 解决重叠：
       按 start_pc 排序
       贪心：如果 site[i] 和 site[j] 重叠，保留较优的那个
       （优先级：wide > rotate > extract > cmov > endian > lea > branch_flip）

    4. 可选：policy 限制
       根据外部 policy config，只启用特定 family

    5. 返回 RewritePlan
```

### 2.5 阶段 4: Emit & Fixup

**目的**：生成新的完整 insn 流，并修正所有 branch offset。

这是整个 pipeline 中最复杂的阶段。分为三步：

1. **生成新 insn 流**（可能长度不等）
2. **构建地址映射表**
3. **修正所有 branch/call offset**

详细设计见 §5（Branch Offset 修正）和 §3/§4（各变换的具体 emit 逻辑）。

---

## 3. 不需要 kinsn 的变换（纯 BPF 指令重写）

### 3.1 WIDE_MEM: byte load+shift+or → BPF wide load

#### 3.1.1 Pattern（以 4 byte little-endian 为例）

**Before**（7 条指令）：

```
insn[0]: BPF_LDX_MEM(BPF_B, dst, base, off+0)    // r_dst = *(u8*)(r_base + off)
insn[1]: BPF_LDX_MEM(BPF_B, tmp1, base, off+1)   // r_tmp1 = *(u8*)(r_base + off+1)
insn[2]: BPF_ALU64_IMM(BPF_LSH, tmp1, 8)          // r_tmp1 <<= 8
insn[3]: BPF_ALU64_REG(BPF_OR, dst, tmp1)          // r_dst |= r_tmp1
insn[4]: BPF_LDX_MEM(BPF_B, tmp2, base, off+2)   // r_tmp2 = *(u8*)(r_base + off+2)
insn[5]: BPF_ALU64_IMM(BPF_LSH, tmp2, 16)         // r_tmp2 <<= 16
insn[6]: BPF_ALU64_REG(BPF_OR, dst, tmp2)          // r_dst |= r_tmp2
insn[7]: BPF_LDX_MEM(BPF_B, tmp3, base, off+3)   // r_tmp3 = *(u8*)(r_base + off+3)
insn[8]: BPF_ALU64_IMM(BPF_LSH, tmp3, 24)         // r_tmp3 <<= 24
insn[9]: BPF_ALU64_REG(BPF_OR, dst, tmp3)          // r_dst |= r_tmp3
```

Pattern 结构（scanner 已实现）：`3*N - 2` 条指令匹配 N byte wide load。对于 4 byte: 10 条。

**After**（1 条指令）：

```
insn[0]: BPF_LDX_MEM(BPF_W, dst, base, off)       // r_dst = *(u32*)(r_base + off)
```

BPF 编码：
- `code = 0x61`（`BPF_LDX | BPF_MEM | BPF_W`，32-bit load）
- `dst_reg` = 从 binding `WMEM_PARAM_DST_REG` 获取
- `src_reg` = 从 binding `WMEM_PARAM_BASE_REG` 获取
- `off` = 从 binding `WMEM_PARAM_BASE_OFF` 获取
- `imm = 0`

**Size mapping**（width binding → BPF size code）:

| width (bytes) | BPF_LDX code | BPF size |
|:---:|:---:|:---:|
| 2 | `0x69` | `BPF_H` (16-bit) |
| 4 | `0x61` | `BPF_W` (32-bit) |
| 8 | `0x79` | `BPF_DW` (64-bit) |
| 3, 5, 6, 7 | N/A | 无对应 BPF 指令，跳过 |

**重要**：BPF 只支持 1/2/4/8 byte load。对于 3/5/6/7 byte 的 wide 站点，如果目标不是 2/4/8，则必须跳过或部分合并（如 7 byte → 4+2+1 或 跳过）。

第一版建议：**只处理 width=2/4/8 的站点**。

#### 3.1.2 大端序 (big-endian load)

对于 big-endian byte-recompose（高字节先加载），After 为：

```
insn[0]: BPF_LDX_MEM(BPF_W, dst, base, off)
insn[1]: BPF_ENDIAN(BPF_TO_LE, dst, 32)           // bswap（将 BE 转为 host LE）
```

但注意：x86-64 是 LE，BPF 语义也是 LE，所以 BE byte-recompose 替换后需要额外 bswap。这使得 BE 站点的替换是 N→2 而非 N→1，收益更小。

#### 3.1.3 NOP padding vs 不等长替换

**推荐方案：全程序重发射（不等长替换）**。

理由：
- `BPF_PROG_REJIT` 的目标语义是接受完整新 bytecode，不要求等长
- 当前内核原型要求等长只是临时限制，最终会移除
- NOP padding 浪费 I-cache，违背优化目的

对于当前原型兼容：如果必须等长，用 `BPF_JA +0`（`0x05, 0x00, 0x0000, 0x00000000`）做 NOP 填充。

### 3.2 BRANCH_FLIP: if/else body 重排

#### 3.2.1 Pattern

```
Before:
  insn[i]:   JCC cond, r_a, r_b, +N  // if (cond) goto body_B
  insn[i+1]: body_A[0]               // not-taken path (N insns)
  ...
  insn[i+N]: body_A[N-1]
  insn[i+N+1]: JA +M                 // goto join
  insn[i+N+2]: body_B[0]             // taken path (M insns)
  ...
  insn[i+N+M+1]: body_B[M-1]
  insn[i+N+M+2]: join                // join point

After (flipped):
  insn[i]:   JCC !cond, r_a, r_b, +M // 反转条件
  insn[i+1]: body_B[0]               // 原 taken 现在在 fallthrough
  ...
  insn[i+M]: body_B[M-1]
  insn[i+M+1]: JA +N                 // goto join
  insn[i+M+2]: body_A[0]             // 原 not-taken 现在在 taken
  ...
  insn[i+M+N+1]: body_A[N-1]
  insn[i+M+N+2]: join                // join point
```

**等长替换**：BRANCH_FLIP 天然是等长的（`1 + N + 1 + M = 1 + M + 1 + N`），不需要 offset 全局修正。

#### 3.2.2 条件反转映射

| 原始 JCC op (code & 0xF0) | 含义 | 反转 op |
|:---:|:---:|:---:|
| `0x10` (JEQ) | == | `0x50` (JNE) |
| `0x20` (JGT) | > (unsigned) | `0xB0` (JLE) |
| `0x30` (JGE) | >= (unsigned) | `0xA0` (JLT) |
| `0x40` (JSET) | & != 0 | 无直接反转，跳过 |
| `0x50` (JNE) | != | `0x10` (JEQ) |
| `0x60` (JSGT) | > (signed) | `0xD0` (JSLE) |
| `0x70` (JSGE) | >= (signed) | `0xC0` (JSLT) |
| `0xA0` (JLT) | < (unsigned) | `0x30` (JGE) |
| `0xB0` (JLE) | <= (unsigned) | `0x20` (JGT) |
| `0xC0` (JSLT) | < (signed) | `0x70` (JSGE) |
| `0xD0` (JSLE) | <= (signed) | `0x60` (JSGT) |

注意：`JSET` (`0x40`) 没有直接反转，scanner 的 `build_branch_flip_rule()` 已经排除了这种情况。

#### 3.2.3 Profile 信息

BRANCH_FLIP 是 **policy-sensitive** 变换：只有当原始 not-taken path 实际上是 hot path（即分支条件通常不成立）时，flip 才有收益。

**需要的信息**：
- 每个条件跳转的 taken/not-taken 比例
- 来源：perf branch profiling，或 BPF stats 的 future extension

**第一版实现**：无 profile → 盲 flip（baseline 实验用）或按 static heuristic（后向跳转 predicted taken）。

---

## 4. 需要 kinsn 的变换（注入 kfunc call）

### 4.1 BPF kfunc call 的精确编码

一条 kfunc call 在 BPF bytecode 中的编码：

```c
struct bpf_insn kfunc_call = {
    .code    = BPF_JMP | BPF_CALL,  // 0x85
    .dst_reg = 0,
    .src_reg = BPF_PSEUDO_KFUNC_CALL,  // 2
    .off     = 0,                       // 0 = vmlinux kfunc; >0 = fd_array slot for module
    .imm     = btf_id,                  // BTF_KIND_FUNC 的 BTF ID
};
```

BPF 调用约定：
- 参数：`R1`, `R2`, `R3`, `R4`, `R5`
- 返回值：`R0`
- Caller-saved（被调用者不保护）：`R0`-`R5`
- Callee-saved（被调用者保护）：`R6`-`R9`
- Frame pointer：`R10`（只读）

### 4.2 ROTATE: shift+or → `bpf_rotate64()` kfunc call

#### 4.2.1 Before（4 条，以 64-bit 标准形式为例）

```
insn[0]: MOV64_REG  r_tmp, r_src       // r_tmp = r_src
insn[1]: LSH64_IMM  r_src, lsh_amt     // r_src <<= lsh_amt
insn[2]: RSH64_IMM  r_tmp, rsh_amt     // r_tmp >>= rsh_amt  (lsh+rsh == 64)
insn[3]: OR64_REG   r_src, r_tmp       // r_src |= r_tmp → rotate result
```

从 bindings 提取：
- `dst_reg` = bindings[ROT_PARAM_DST_REG]
- `src_reg` = bindings[ROT_PARAM_SRC_REG]
- `amount`  = bindings[ROT_PARAM_AMOUNT]（右旋转量）
- `width`   = bindings[ROT_PARAM_WIDTH]（32 或 64）

#### 4.2.2 After

kfunc 签名：`u64 bpf_rotate64(u64 val, u32 shift)`

需要生成的 BPF 指令序列：

```
// 1. 设置参数
insn[0]: MOV64_REG  R1, r_src          // R1 = val（第一个参数）
insn[1]: MOV64_IMM  R2, amount         // R2 = shift amount（第二个参数）
// 2. kfunc call
insn[2]: CALL kfunc bpf_rotate64       // code=0x85, src_reg=2, off=0, imm=btf_id
// 3. 取结果
insn[3]: MOV64_REG  r_dst, R0          // r_dst = 返回值
```

**指令编码**：

```c
// insn[0]: MOV64_REG R1, r_src
{ .code = 0xbf, .dst_reg = 1, .src_reg = r_src, .off = 0, .imm = 0 }

// insn[1]: MOV64_IMM R2, amount
{ .code = 0xb7, .dst_reg = 2, .src_reg = 0, .off = 0, .imm = amount }

// insn[2]: kfunc call
{ .code = 0x85, .dst_reg = 0, .src_reg = 2, .off = 0, .imm = rotate64_btf_id }

// insn[3]: MOV64_REG r_dst, R0
{ .code = 0xbf, .dst_reg = r_dst, .src_reg = 0, .off = 0, .imm = 0 }
```

**优化**：
- 如果 `r_src == R1`，省略 insn[0]
- 如果 `r_dst == R0`，省略 insn[3]
- 如果 `r_src == r_dst == R1`，只需 insn[1] + insn[2]（2 条）

**等长分析**：
- 原始 4 条 → 新 2-4 条，通常 <=4，很多情况下等长或更短

#### 4.2.3 Caller-saved 冲突处理

**关键问题**：kfunc call 会 clobber R1-R5。如果 site 前后有活跃值还在 R1-R5 中（不包括 r_src 本身和 rotate 使用的 r_tmp），rewrite 可能破坏程序语义。

**第一版策略**：保守跳过。

```
procedure check_rotate_safety(site, cfg_info):
    // 确定 site 使用的寄存器
    used_regs = {r_src, r_tmp, r_dst}

    // 对 R1-R5 中每个不在 used_regs 中的寄存器 R：
    //   如果 R 在 site 之后立即被使用（且未被重新定义），
    //   则该 site 不安全
    //
    // 精确分析需要 liveness analysis，第一版用 conservative heuristic：
    //   如果 site 后 3 条指令内读取了 R1-R5 中任何非 used_regs 的寄存器，跳过

    return safe
```

**第二版策略**：如果不安全，插入 spill/restore：

```
// Spill: MOV64_REG R6, R3  (如果 R3 活跃且 R6 空闲)
// ... kfunc call ...
// Restore: MOV64_REG R3, R6
```

但这需要完整的 liveness analysis + register allocator，代码量大，第一版不做。

### 4.3 COND_SELECT: branch+mov → `bpf_select64()` kfunc call

#### 4.3.1 Before（4 条，标准 diamond 形式）

```
insn[0]: JCC cond R_a R_b +2        // if (cond) goto insn[3]
insn[1]: MOV r_dst, false_val       // not-taken: r_dst = false_val
insn[2]: JA +1                      // goto join
insn[3]: MOV r_dst, true_val        // taken: r_dst = true_val
```

从 bindings 提取：
- `dst_reg` = bindings[SEL_PARAM_DST_REG]
- `cond_op` = bindings[SEL_PARAM_COND_OP]
- `cond_a`  = bindings[SEL_PARAM_COND_A] (reg)
- `cond_b`  = bindings[SEL_PARAM_COND_B] (reg or imm)
- `true_val` = bindings[SEL_PARAM_TRUE_VAL] (reg or imm)
- `false_val` = bindings[SEL_PARAM_FALSE_VAL] (reg or imm)
- `width`   = bindings[SEL_PARAM_WIDTH] (32 or 64)

#### 4.3.2 After

kfunc 签名：`u64 bpf_select64(u64 cond_a, u64 cond_b, u32 cond_op, u64 true_val, u64 false_val)`

```
insn[0]: MOV64_REG  R1, r_cond_a       // R1 = cond_a
insn[1]: MOV64_REG/IMM  R2, cond_b     // R2 = cond_b
insn[2]: MOV64_IMM  R3, cond_op        // R3 = condition opcode
insn[3]: MOV64_REG/IMM  R4, true_val   // R4 = true value
insn[4]: MOV64_REG/IMM  R5, false_val  // R5 = false value
insn[5]: CALL kfunc bpf_select64       // kfunc call
insn[6]: MOV64_REG  r_dst, R0          // r_dst = result
```

**指令编码示例**（全部寄存器参数的情况）：

```c
{ .code = 0xbf, .dst_reg = 1, .src_reg = r_cond_a, .off = 0, .imm = 0 }
{ .code = 0xbf, .dst_reg = 2, .src_reg = r_cond_b, .off = 0, .imm = 0 }
{ .code = 0xb7, .dst_reg = 3, .src_reg = 0,        .off = 0, .imm = cond_op }
{ .code = 0xbf, .dst_reg = 4, .src_reg = r_true,   .off = 0, .imm = 0 }
{ .code = 0xbf, .dst_reg = 5, .src_reg = r_false,  .off = 0, .imm = 0 }
{ .code = 0x85, .dst_reg = 0, .src_reg = 2,        .off = 0, .imm = select64_btf_id }
{ .code = 0xbf, .dst_reg = r_dst, .src_reg = 0,    .off = 0, .imm = 0 }
```

**注意**：cond_select 替换后指令数通常增加（4→7 或 3→7），是 **N < M** 的情况。但 kinsn（KF_INLINE_EMIT）使 JIT 将这个 kfunc call 发射为单条 CMOV native 指令，所以 bytecode 膨胀不影响最终 native code size。

### 4.4 BITFIELD_EXTRACT: shift+and → `bpf_extract64()` kfunc call

#### 4.4.1 Before（shift-mask 形式，2 条）

```
insn[0]: RSH64_IMM  r_dst, shift       // r_dst >>= shift
insn[1]: AND64_IMM  r_dst, mask         // r_dst &= mask
```

或 mask-shift 形式（2 条）：

```
insn[0]: AND64_IMM  r_dst, mask         // r_dst &= mask
insn[1]: RSH64_IMM  r_dst, shift       // r_dst >>= shift
```

#### 4.4.2 After

kfunc 签名：`u64 bpf_extract64(u64 val, u32 shift, u64 mask)`

```
insn[0]: MOV64_REG  R1, r_src          // R1 = val
insn[1]: MOV64_IMM  R2, shift          // R2 = shift
insn[2]: MOV64_IMM  R3, mask           // R3 = mask (或 width)
insn[3]: CALL kfunc bpf_extract64      // kfunc call
insn[4]: MOV64_REG  r_dst, R0          // r_dst = result
```

**等长分析**：2→5，明显膨胀。和 cond_select 一样，bytecode 膨胀但 native code 收缩（BEXTR 是单条指令）。

---

## 5. Branch Offset 修正

### 5.1 问题

当替换不等长时（N 条 → M 条），后续所有指令的 PC 都会偏移，导致 branch offset 和 BPF_PSEUDO_CALL offset 不再正确。

### 5.2 地址映射表

核心数据结构：**old_pc → new_pc 映射**。

```cpp
// addr_map[old_pc] = new_pc
// 对于被替换的 site 内部指令，映射到 site 替换后的起始位置
std::vector<int32_t> addr_map;
```

### 5.3 算法

```
procedure build_new_program(orig_insns, plan):
    // Step 1: 构建地址映射表
    //         同时生成新 insn 流
    new_insns = []
    addr_map = array of size orig_insns.size() + 1, initialized to -1

    old_pc = 0
    while old_pc < orig_insns.size():
        // 检查是否有 rewrite site 从这里开始
        site = find_site_starting_at(plan, old_pc)

        if site != null:
            // 记录 site 起始的映射
            new_start = new_insns.size()
            addr_map[old_pc] = new_start

            // 为 site 内部每条原始指令建立映射
            // 它们全部映射到 new_start（被替换了）
            for j in range(site.old_len):
                addr_map[old_pc + j] = new_start

            // 生成替换指令
            replacement = emit_replacement(site)
            new_insns.extend(replacement)

            old_pc += site.old_len
        else:
            // 非 site 指令，直接复制
            addr_map[old_pc] = new_insns.size()
            new_insns.push_back(orig_insns[old_pc])

            // LD_IMM64 占两条 slot
            if is_ldimm64(orig_insns[old_pc]):
                old_pc += 1
                addr_map[old_pc] = new_insns.size()
                new_insns.push_back(orig_insns[old_pc])

            old_pc += 1

    // 哨兵：程序末尾 +1 的映射（用于 fall-through 计算）
    addr_map[orig_insns.size()] = new_insns.size()

    // Step 2: 修正所有 branch 和 call 的 offset
    for new_pc in range(new_insns.size()):
        insn = new_insns[new_pc]

        if is_replacement_insn(insn):
            // 替换指令内部的跳转已经在 emit 阶段正确设置
            // （它们不引用原始 PC，而是引用同一 site 内的相对位置）
            continue

        if is_conditional_jump(insn) or is_ja(insn):
            // 原始 target: old_target = old_pc_of_this_insn + 1 + insn.off
            old_pc_of_this = reverse_map(addr_map, new_pc)
            old_target = old_pc_of_this + 1 + insn.off
            new_target = addr_map[old_target]
            insn.off = new_target - (new_pc + 1)

        if is_bpf_pseudo_call(insn):
            old_pc_of_this = reverse_map(addr_map, new_pc)
            old_target = old_pc_of_this + 1 + insn.imm
            new_target = addr_map[old_target]
            insn.imm = new_target - (new_pc + 1)

    return new_insns
```

### 5.4 优化：等长情况下跳过修正

如果所有 site 都是等长替换（`old_len == new_len` for all sites），`addr_map` 是恒等映射，可以完全跳过 Step 2。

检测方法：

```cpp
bool all_equal_length = std::all_of(
    plan.sites.begin(), plan.sites.end(),
    [](const auto& site) {
        return site.old_len == emit_replacement_length(site);
    });
```

### 5.5 实现细节

为了高效实现 reverse_map（从 new_pc 找回 old_pc），我们不真的需要 reverse map。改为在 Step 2 中，直接遍历原始指令流，用 addr_map 查对应的 new_pc，然后修正：

```cpp
procedure fixup_branches(orig_insns, new_insns, addr_map, plan):
    for old_pc in range(orig_insns.size()):
        new_pc = addr_map[old_pc]

        // 跳过被替换的 site 中间指令（它们映射到同一个 new_pc）
        if old_pc > 0 and addr_map[old_pc] == addr_map[old_pc - 1]:
            continue

        // 如果这个 old_pc 是 site 的起始，跳过（替换指令不引用原始 offset）
        if is_site_start(plan, old_pc):
            continue

        insn = &new_insns[new_pc]

        // 修正条件跳转
        if is_cond_jump(insn) or is_ja(insn):
            if is_ja_imm(insn):
                // JA32 用 imm 而不是 off
                old_target = old_pc + 1 + insn->imm
                new_target = addr_map[old_target]
                insn->imm = new_target - (new_pc + 1)
            else:
                old_target = old_pc + 1 + insn->off
                new_target = addr_map[old_target]
                insn->off = (int16_t)(new_target - (new_pc + 1))

        // 修正 BPF-to-BPF call
        if is_pseudo_call(insn):
            old_target = old_pc + 1 + insn->imm
            new_target = addr_map[old_target]
            insn->imm = new_target - (new_pc + 1)
```

### 5.6 Edge case

1. **JA32**（`code = 0x06`）：offset 在 `imm` 字段而非 `off`
2. **LD_IMM64**（`code = 0x18`）：占 2 个 insn slot，第二个 slot 不是独立指令
3. **BPF_PSEUDO_CALL**（`src_reg = 1`）：offset 在 `imm` 字段
4. **kfunc call**（`src_reg = 2`）：`imm` 是 BTF ID，不是 offset，**不需要修正**
5. **helper call**（`src_reg = 0`）：`imm` 是 helper ID，不是 offset，**不需要修正**
6. **BPF_EXIT**（`code = 0x95`）：无 offset，不需要修正

---

## 6. kfunc Relocation

### 6.1 问题

新 bytecode 中的 kfunc call 需要正确的 BTF ID。在 ELF 加载路径中，libbpf 通过 BTF 名称 resolve；在 REJIT 路径中没有 ELF。

### 6.2 方案：Daemon 启动时预解析

```cpp
struct KfuncResolver {
    struct btf *vmlinux_btf;

    // 初始化时解析所有需要的 kfunc BTF ID
    int32_t resolve(const char *name) {
        int id = btf__find_by_name_kind(vmlinux_btf, name, BTF_KIND_FUNC);
        return id >= 0 ? id : -1;
    }
};

// Daemon 启动时：
KfuncResolver resolver;
resolver.vmlinux_btf = btf__load_vmlinux_btf();
kfunc_ids.rotate64_btf_id   = resolver.resolve("bpf_rotate64");
kfunc_ids.select64_btf_id   = resolver.resolve("bpf_select64");
kfunc_ids.extract64_btf_id  = resolver.resolve("bpf_extract64");
```

### 6.3 vmlinux vs module kfunc

| 类型 | insn.off | insn.imm | 前提 |
|:---:|:---:|:---:|:---:|
| vmlinux kfunc | 0 | BTF ID | 只需 `btf__load_vmlinux_btf()` |
| module kfunc | fd_array slot | BTF ID in module BTF | 需要 REJIT attr 扩展 fd_array |

**第一版**：只支持 vmlinux kfunc（bpf_rotate64 等注册在 vmlinux BTF 可见域），`insn.off = 0`。

**第二版**：等 REJIT UAPI 有 fd_array 后，支持 module kfunc。

### 6.4 BTF ID 缓存策略

BTF ID 是 boot-time 确定的（取决于 vmlinux 编译），daemon 运行期间不变。因此：
- 启动时解析一次
- 缓存到 `KfuncRegistry`
- 如果某个 kfunc 不存在（module 未加载），BTF ID = -1，该 family 的 rewrite 自动跳过

---

## 7. 与现有 scanner 的关系

### 7.1 复用矩阵

| Scanner 组件 | 复用方式 |
|:---:|:---:|
| `match_v5_pattern_at()` | **直接复用**（核心匹配引擎） |
| `check_v5_constraints()` | **直接复用**（约束检查） |
| `build_v5_*_descriptors()` | **直接复用**（7 个 family 的 pattern 描述库） |
| `V5PatternInsn/V5PatternConstraint/V5Binding` | **直接复用**（ABI 类型） |
| `parse_xlated_insns()` | **直接复用**（insn 解析） |
| `raw_is_cond_jump()/raw_jump_target()/raw_has_interior_edge()` | **直接复用**（CFG 辅助函数） |
| `build_branch_flip_rule()` | **直接复用**（branch flip 匹配） |
| `V5PolicyRule` | **不复用** → 替换为 `RewriteSite` |
| `build_policy_blob_v5()` | **不复用** → 删除（v2 不需要 policy blob） |
| `policy_config.cpp` | **不复用** → 重写（v2 的 policy 语义不同） |
| `cli.cpp` 的 enumerate/recompile 路径 | **不复用** → 重写 |

### 7.2 改造方案

在 scanner 项目中新增文件，不修改现有文件（保持 v1 可用性）：

```
scanner/
  src/
    pattern_v5.cpp          # 不改（现有 matcher）
    policy_config.cpp       # 不改（v1 policy）
    cli.cpp                 # 不改（v1 CLI）
    rewriter.cpp            # 新增：bytecode rewriter
    rewrite_emit.cpp        # 新增：per-family emit 逻辑
    rewrite_fixup.cpp       # 新增：branch offset fixup
    kfunc_resolver.cpp      # 新增：BTF ID 解析
  include/
    bpf_jit_scanner/
      pattern_v5.hpp        # 微调：新增 match_with_bindings() 导出接口
      rewriter.hpp          # 新增
```

唯一对现有代码的修改：在 `pattern_v5.hpp` 中新增一个带 bindings 导出的 scan 函数。现有 `scan_v5_builtin()` 保持不变。

```cpp
// 新增 API（在 pattern_v5.hpp 中）
struct V5MatchResult {
    V5PolicyRule rule;                        // 兼容现有
    std::vector<V5PatternVar> captured_vars;  // 新增：捕获的变量值
    const V5PatternDesc *matched_desc;        // 新增：匹配的 pattern 描述
};

ScanResult scan_for_rewrite(const uint8_t *insn_data,
                            uint32_t insn_len,
                            const V5ScanOptions &options);
```

---

## 8. 实现语言选择

### 8.1 推荐：C++，在 scanner 项目内实现

**理由**：

1. **代码共享**：scanner 的 matcher 是 C++，rewriter 需要直接调用 `match_v5_pattern_at()` 等函数，不需要 FFI
2. **性能**：rewriter 在 daemon hot path 上（每次发现新 prog 都要跑），C++ 零开销
3. **类型安全**：BPF insn 操作需要精确的 bit 操作，C++ 比 Python 更自然
4. **与 micro_exec 集成**：runner 是 C++ 项目，新增 `run-rejit` 子命令天然共享 rewriter 代码

### 8.2 Python 的角色

Python 仍然用于：
- daemon 主循环、discovery、policy 决策（`daemon/` 目录）
- benchmark orchestration（`micro/driver.py`）
- 调用 C++ rewriter 通过 CLI 或 shared library

### 8.3 集成方式

```
scanner/             # C++ 项目
  src/rewriter.cpp   # rewriter 核心
  ...
  CMakeLists.txt     # 编译为 libbpf_jit_rewriter.a

runner/              # C++ 项目
  src/kernel_runner.cpp  # 新增 run-rejit，链接 libbpf_jit_rewriter.a

daemon/              # Python 项目（新增）
  rejit_daemon.py    # 主循环，通过 subprocess 调用 scanner CLI
  # 或通过 ctypes/pybind11 调用 libbpf_jit_rewriter.so
```

---

## 9. 代码量估计

### 9.1 逐模块估计

| 模块 | 文件 | 职责 | 新增代码量 (LoC) |
|:---:|:---:|:---:|:---:|
| **Parse & Analyze** | `rewriter.cpp` | CFG 构建、branch target 收集、subprog 边界 | 250-350 |
| **Pattern Match 扩展** | `pattern_v5.cpp` 微调 + `rewriter.cpp` | 导出 bindings、safety check | 80-120 |
| **Transform Decision** | `rewriter.cpp` | 站点过滤、重叠消解、policy 集成 | 150-250 |
| **Emit: WIDE_MEM** | `rewrite_emit.cpp` | wide load 替换 insn 生成 | 100-150 |
| **Emit: BRANCH_FLIP** | `rewrite_emit.cpp` | body 交换 + 条件反转 | 80-120 |
| **Emit: ROTATE** | `rewrite_emit.cpp` | kfunc call 序列生成 | 120-180 |
| **Emit: COND_SELECT** | `rewrite_emit.cpp` | kfunc call 序列生成（5 参数） | 150-200 |
| **Emit: BITFIELD_EXTRACT** | `rewrite_emit.cpp` | kfunc call 序列生成 | 80-120 |
| **Branch Fixup** | `rewrite_fixup.cpp` | addr_map 构建 + offset 修正 | 200-300 |
| **kfunc Resolver** | `kfunc_resolver.cpp` | BTF ID 查找 + 缓存 | 80-120 |
| **Rewriter API** | `rewriter.hpp` + `rewriter.cpp` 入口 | 数据结构定义 + pipeline 胶水 | 150-200 |
| **单元测试** | `tests/test_rewriter.cpp` | 各 family 的 before/after 验证 | 400-600 |
| **集成到 micro_exec** | `kernel_runner.cpp` 新增 | `run-rejit` 子命令 | 300-500 |

### 9.2 汇总

| 类别 | 代码量 (LoC) |
|:---:|:---:|
| Rewriter 核心（scanner 内） | **1,400 - 2,100** |
| 测试 | **400 - 600** |
| micro_exec 集成 | **300 - 500** |
| **总计** | **2,100 - 3,200** |

### 9.3 开发优先级

| Phase | 内容 | 工期（人日） |
|:---:|:---:|:---:|
| **Phase A** | WIDE_MEM only（等长+不等长），branch fixup，run-rejit | 3-4 |
| **Phase B** | BRANCH_FLIP（等长，不需 branch fixup） | 1-2 |
| **Phase C** | ROTATE + kfunc resolver | 2-3 |
| **Phase D** | COND_SELECT + BITFIELD_EXTRACT | 2-3 |
| **Phase E** | Liveness analysis + spill（kfunc safety） | 3-5 |

---

## 10. 完整 Emit 示例

### 10.1 WIDE_MEM 4-byte LE

```
原始程序（20 insns）:
  [0] MOV64_IMM R1, 0          // 非 site
  [1] LDX_MEM_B R2, R6, +0    // ─── site 开始 ───
  [2] LDX_MEM_B R3, R6, +1
  [3] LSH64_IMM R3, 8
  [4] OR64_REG  R2, R3
  [5] LDX_MEM_B R4, R6, +2
  [6] LSH64_IMM R4, 16
  [7] OR64_REG  R2, R4
  [8] LDX_MEM_B R5, R6, +3
  [9] LSH64_IMM R5, 24
  [10] OR64_REG R2, R5         // ─── site 结束 ───
  [11] JEQ R2, R1, +5          // 跳到 [17]
  [12] MOV64_IMM R0, 1
  [13] EXIT
  ...
  [17] MOV64_IMM R0, 0
  [18] EXIT
  [19] (padding)

替换后（11 insns）:
  [0]  MOV64_IMM R1, 0          // 不变
  [1]  LDX_MEM_W R2, R6, +0    // ─── 替换：10 insns → 1 insn ───
  [2]  JEQ R2, R1, +5           // offset 从 +5 修正为 +5（target: 原[17] → 新[8]）
                                 // 原 offset: 11 + 1 + 5 = 17 → 新 target: addr_map[17] = 8
                                 // 新 offset: 8 - (2 + 1) = 5 ✓（巧合不变）
  [3]  MOV64_IMM R0, 1
  [4]  EXIT
  ...
  [8]  MOV64_IMM R0, 0
  [9]  EXIT
  [10] (padding)

地址映射表:
  addr_map[0]  = 0
  addr_map[1]  = 1    (site start)
  addr_map[2]  = 1    (site interior)
  addr_map[3]  = 1
  addr_map[4]  = 1
  addr_map[5]  = 1
  addr_map[6]  = 1
  addr_map[7]  = 1
  addr_map[8]  = 1
  addr_map[9]  = 1
  addr_map[10] = 1
  addr_map[11] = 2    (first insn after site)
  addr_map[12] = 3
  ...
  addr_map[17] = 8
  ...
```

### 10.2 ROTATE 64-bit

```
原始:
  [0] MOV64_REG  R3, R7        // r_tmp=R3, r_src=R7
  [1] LSH64_IMM  R7, 51        // lsh_amt=51
  [2] RSH64_IMM  R3, 13        // rsh_amt=13, rotate_amount=13
  [3] OR64_REG   R7, R3        // result in R7

Bindings: dst_reg=R7, src_reg=R7, amount=13

替换:
  [0] MOV64_REG  R1, R7        // 参数1: val = R7
  [1] MOV64_IMM  R2, 13        // 参数2: shift = 13
  [2] CALL kfunc bpf_rotate64  // {0x85, 0, 2, 0, btf_id}
  [3] MOV64_REG  R7, R0        // result → R7

等长: 4→4 ✓
```

### 10.3 BRANCH_FLIP

```
原始:
  [0] JGT R1, R2, +3           // if (R1 > R2) goto [4]
  [1] MOV64_IMM R0, 10         // body_A (not-taken, 2 insns)
  [2] ADD64_IMM R0, 5
  [3] JA +2                    // goto [6] (join)
  [4] MOV64_IMM R0, 20         // body_B (taken, 2 insns)
  [5] ADD64_IMM R0, 7
  [6] EXIT                     // join

替换 (flipped):
  [0] JLE R1, R2, +3           // 反转: JGT → JLE, offset 不变(+3)
  [1] MOV64_IMM R0, 20         // body_B 移到 fallthrough
  [2] ADD64_IMM R0, 7
  [3] JA +2                    // goto [6] (join), offset 不变
  [4] MOV64_IMM R0, 10         // body_A 移到 taken
  [5] ADD64_IMM R0, 5
  [6] EXIT                     // join

等长: 7→7 ✓（body_A.len == body_B.len 时 offset 巧合不变；不等时需重算 JCC offset）
实际: JCC.off = body_B.len + 1, JA.off = body_A.len
```

---

## 11. 安全保证分析

### 11.1 Rewriter 不需要自己保证安全性

这是 BpfReJIT 架构的核心优势：

1. Rewriter 生成新 bytecode
2. `BPF_PROG_REJIT` 将新 bytecode 交给 kernel verifier（`bpf_check()`）
3. Verifier 验证通过 → re-JIT → image swap
4. Verifier 验证失败 → 什么都不改，返回错误

因此 rewriter 的 bug **不会破坏内核安全**，只会：
- 产生语义不正确的程序（correctness bug）→ daemon 负责检测和 rollback
- 产生 verifier 拒绝的程序 → 自动 fail-safe

### 11.2 Rewriter 应该做的检查（correctness，不是 safety）

| 检查 | 目的 |
|:---:|:---:|
| site 无 interior branch target | 避免截断 CFG |
| site 不跨 subprog boundary | 避免破坏函数结构 |
| site 不切割 LD_IMM64 | 避免破坏双宽指令 |
| kfunc call 的 BTF ID 有效 | 避免 verifier reject |
| branch offset 在 int16 范围内 | 避免 verifier reject |
| 新程序 insn_cnt <= 1M（BPF 限制） | 避免 verifier reject |

---

## 12. 数据流总图

```
                    ┌─────────────────────────────┐
                    │    BPF_PROG_GET_ORIGINAL     │
                    │    (kernel syscall)           │
                    └───────────┬─────────────────┘
                                │ orig_insns + prog_info
                                ▼
                    ┌─────────────────────────────┐
                    │   Stage 1: Parse & Analyze   │
                    │   → CFGInfo, branch targets, │
                    │     subprog bounds            │
                    └───────────┬─────────────────┘
                                │
                                ▼
                    ┌─────────────────────────────┐
                    │   Stage 2: Pattern Match     │
                    │   (reuse scanner matchers)   │
                    │   → ScanResult: sites +      │
                    │     bindings + safety flags   │
                    └───────────┬─────────────────┘
                                │
                                ▼
                    ┌─────────────────────────────┐
                    │  Stage 3: Transform Decision │
                    │  → RewritePlan (filtered,    │
                    │    non-overlapping sites)     │
                    └───────────┬─────────────────┘
                                │
                    ┌───────────┴─────────────────┐
                    │                              │
                    ▼                              ▼
        ┌──────────────────┐          ┌──────────────────┐
        │  kfunc Resolver   │          │   Stage 4: Emit  │
        │  (BTF ID lookup)  │─────────>│   (per-family    │
        └──────────────────┘          │    replacement   │
                                      │    generation)   │
                                      └────────┬─────────┘
                                               │
                                               ▼
                                  ┌──────────────────────┐
                                  │  Stage 5: Fixup      │
                                  │  (addr_map + branch  │
                                  │   offset correction) │
                                  └────────┬─────────────┘
                                           │ new_insns
                                           ▼
                                  ┌──────────────────────┐
                                  │  Stage 6: Validate   │
                                  │  (insn_cnt check,    │
                                  │   basic sanity)      │
                                  └────────┬─────────────┘
                                           │
                                           ▼
                                  ┌──────────────────────┐
                                  │  BPF_PROG_REJIT      │
                                  │  (kernel re-verify   │
                                  │   + re-JIT + swap)   │
                                  └──────────────────────┘
```

---

## 13. 已知限制与 Future Work

### 13.1 当前内核原型限制

| 限制 | 影响 | 解决计划 |
|:---:|:---:|:---:|
| REJIT 要求 `new_len == orig_len` | 只能做等长替换或 NOP 填充 | 扩展 REJIT 允许不等长 |
| REJIT 拒绝有 maps 的程序 | 只能测无 map 的 micro benchmark | 扩展 REJIT + fd_array |
| REJIT 拒绝有 BTF 的程序 | 类似上条 | 扩展 REJIT UAPI |
| REJIT 没有 fd_array | 无法传 module kfunc BTF fd | 扩展 REJIT UAPI |

### 13.2 Rewriter 层面 Future Work

| 项目 | 说明 |
|:---:|:---:|
| Liveness analysis | kfunc 变换的 caller-saved 冲突精确检测 |
| Spill/restore insertion | 自动插入 spill 到 R6-R9 或 stack |
| func_info/line_info fixup | 不等长替换后修正调试信息 |
| Const propagation | 利用 frozen map 值做常量折叠 |
| Subprog inline | 在 bytecode 层展开 BPF-to-BPF call |
| Security insertions | bounds check、lfence 注入 |
| ENDIAN_FUSION | load+bswap → MOVBE kinsn |
| ADDR_CALC | mov+shift+add → LEA kinsn |
