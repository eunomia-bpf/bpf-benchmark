# BpfReJIT 优化 Pipeline Review

> 生成时间：2026-03-13
> 基于代码：`scanner/src/cli.cpp`, `scanner/src/pattern_v5.cpp`, `scanner/src/policy_config.cpp`, `scanner/include/bpf_jit_scanner/types.h`, `vendor/linux-framework/kernel/bpf/jit_directives.c`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, `docs/kernel-jit-optimization-plan.md` §3/§4

---

## 1. 完整优化 Pipeline

```
[eBPF 程序已加载到 kernel]
        |
        | BPF_PROG_GET_NEXT_ID 枚举
        v
[Scanner: enumerate 子命令]
   ├─ BPF_PROG_GET_NEXT_ID / BPF_PROG_GET_FD_BY_ID 遍历所有 live 程序
   ├─ BPF_OBJ_GET_INFO_BY_FD 获取 xlated_prog_insns（kernel 验证后的 BPF 字节码）
   └─ scan_v5_builtin() → pattern matching 找到所有 candidate sites
        |
        | per-program scan summary (JSON 或 YAML policy)
        v
[Policy: 用户态 YAML 配置]
   ├─ version: 3 + sites: [{insn, family, pattern_kind}]
   ├─ filter_rules_by_policy() 按 (insn, family, pattern_kind) 精确匹配
   └─ 未命中的 sites 发 warning + skip
        |
        | 过滤后的 V5PolicyRule 列表
        v
[Scanner: apply 子命令 → serialize_v5_policy_blob()]
   ├─ 写入二进制 blob（magic + version + rule 数组，每 rule 含 pattern + bindings）
   ├─ memfd_create() 创建密封 memfd（F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK）
   └─ BPF_PROG_JIT_RECOMPILE 系统调用（cmd=39）传入 prog_fd + policy_fd
        |
        | 进入 kernel
        v
[Kernel: bpf_jit_recompile() in jit_directives.c]
   ├─ bpf_jit_directives_valid_memfd() 验证 memfd 已密封（防篡改）
   ├─ 解析 blob：magic BPF_JIT_POLICY_MAGIC + version BPF_JIT_POLICY_VERSION_2
   ├─ 对每条 rule：
   │   ├─ bpf_jit_native_choice_valid() 验证 native_choice 属于该 form 的合法值
   │   ├─ bpf_jit_canonical_form_valid() 验证 canonical form 编号合法
   │   ├─ bpf_jit_site_range_valid() 验证 site [start, start+len) 在 insn_cnt 范围内
   │   ├─ bpf_jit_has_interior_edge() 验证 site 内部无外部跳入（防 jump target 污染）
   │   └─ 对应 form 的 bpf_jit_validate_*_rule() 精确验证 shape
   ├─ rule_cmp() 按 site_start 排序（同 site 按 priority 降序）
   ├─ bpf_jit_recompile_snapshot() 保存全部 subprog 状态（用于 rollback）
   └─ 对每个 subprog：bpf_int_jit_compile() 传入 prog->aux->jit_rules
        |
        v
[Kernel: x86 JIT emitter in bpf_jit_comp.c]
   ├─ 正常 JIT 收敛 loop 中，每条 insn 处：
   │   ├─ bpf_jit_rule_lookup_prog(bpf_prog, insn_idx) 查询当前 insn 是否有 rule
   │   ├─ 有 rule → bpf_jit_try_emit_prog_rule() → emit_canonical_*()
   │   └─ 无 rule → 原始 emission
   ├─ emit_canonical_*() 函数逐 form 分发：
   │   ├─ CF_COND_SELECT    → emit_canonical_select()    → cmovcc 指令
   │   ├─ CF_WIDE_MEM       → emit_canonical_wide_load() → movzx/mov 宽加载
   │   ├─ CF_ROTATE         → emit_canonical_rotate()    → ror/rorx
   │   ├─ CF_ADDR_CALC      → emit_canonical_lea_fusion()→ lea
   │   ├─ CF_BITFIELD_EXTRACT→ emit_canonical_bitfield_extract() → bextr/shr+and
   │   ├─ CF_ZERO_EXT_ELIDE → emit_canonical_zero_ext_elide()   → 省略 xor+mov
   │   ├─ CF_ENDIAN_FUSION  → emit_canonical_endian_fusion()     → movbe
   │   └─ CF_BRANCH_FLIP    → emit_canonical_branch_flip()       → 交换两段 body
   ├─ 失败时 fail-closed：bpf_jit_recompile_abort() + rollback
   └─ 成功后 RCU-safe 切换 bpf_func 指针
```

### Pipeline 关键属性

| 属性 | 实现方式 |
|------|---------|
| **不可篡改** | memfd + F_SEAL_WRITE/GROW/SHRINK；kernel 验证密封 |
| **安全边界** | Kernel 从不执行用户态代码；只在预定义安全变体间切换 |
| **Fail-closed** | 任何 validate 失败 → abort + rollback 到原始 image |
| **原子性** | snapshot + RCU + smp_store_release；旧 image synchronize_rcu 后退役 |
| **可回滚** | bpf_jit_recompile_snapshot() 保存所有 subprog 状态 |
| **Xlated 不变** | 只改 native code emission，BPF 字节码不变 |

---

## 2. 8 个 Canonical Form 逐个说明

### CF_COND_SELECT（family: cmov）

**识别**：Scanner 在 BPF xlated 中寻找以下 pattern（在 `add_v5_cond_select_descs_for_jump` 中定义）：
- Diamond pattern：`jcc +2, mov_false, ja +1, mov_true`（4 insn）
- Compact pattern：`mov_default, jcc +1, mov_override`（3 insn）
- Guarded-update：`jcc +1, mov_true`（2 insn，条件写）
- Switch-chain：多跳 cond 序列

**约束**：
- 两个 mov 的 dst_reg 必须相同
- 无外部跳入 interior edge（bpf_jit_has_interior_edge）
- 仅 diamond/compact 两种 shape 被 x86 emitter 支持（broadened patterns fail-close）

**Kernel 验证**：`bpf_jit_validate_cond_select_rule()` 检查 site_len==4（diamond）或 site_len==3（compact）

**X86 优化**：`emit_canonical_select()` → `cmovcc reg, reg/imm`（替换原 jcc+mov）

**Policy**：native_choice=BPF_JIT_SEL_CMOVCC（优化）或 BPF_JIT_SEL_BRANCH（保持原始）

**实测结果**：log2_fold +28.3%（unpredictable branch），cond_select_dense 0.482x（predictable branch，CMOV policy-sensitive）

---

### CF_WIDE_MEM（family: wide）

**识别**：Scanner 识别连续 byte-load+shift+or 序列（BPF 编译器将 multi-byte load 展开为多个 1-byte load）：
```
ldxb dst, [base+off]
ldxb tmp, [base+off+1]; lsh tmp, 8; or dst, tmp
ldxb tmp, [base+off+2]; lsh tmp, 8; or dst, tmp
...
```

**Kernel 验证**：`bpf_jit_parse_wide_mem_shape()` 解析 offsets 和 shifts，检查：
- 所有 ldxb 的 base_reg 相同
- offsets 连续无重复，且 [min_off, max_off+1) 对齐 width
- shift 序列为 little-endian 或 big-endian（两者之一）

**X86 优化**：`emit_canonical_wide_load()` → 一条 movzx/mov 宽读（2-8 字节）+ bswap（big-endian 场合）

**实测结果**：load_byte_recompose -13%，packet_redundant_bounds 1.306x；byte-recompose 占 gap 的 50.7%

---

### CF_ROTATE（family: rotate）

**识别**：BPF 没有 rotate 指令，编译器展开为 `lsh r, amount; mov tmp, src; rsh tmp, (64-amount); or r, tmp`

Scanner 识别 32/64-bit 两种形式，支持 lsh-or 和 rsh-or 两种排列。

**Kernel 验证**：`bpf_jit_validate_rotate_rule()` 解析 dst_reg、src_reg、width、amount

**X86 优化**：`emit_canonical_rotate()` → `ror reg, imm`（BPF_JIT_ROT_ROR）或 `rorx reg, src, imm`（需 BMI2，BPF_JIT_ROT_RORX）

**实测结果**：rotate64_hash 1.600x，packet_rss_hash 1.273x；rotate_dense 1.167x（256 sites）

---

### CF_ADDR_CALC（family: lea）

**识别**：`r = base; r <<= scale; r += offset` 序列（stride 地址计算，常见于数组索引）

Scanner 绑定 base_reg、dst_reg、scale、offset 变量。

**Kernel 验证**：`bpf_jit_validate_addr_calc_rule()` 检查 mov+shl+add 形状和参数

**X86 优化**：`emit_canonical_lea_fusion()` → `lea dst, [base + (src << scale) + offset]`（三合一）

**实测结果**：addr_calc_stride 1.401x（8 sites，stride=4），LEA 1.052x（corpus 综合）

---

### CF_BITFIELD_EXTRACT（family: extract）

**识别**：`r = (src >> shift) & mask` 或 `r = src & mask; r >>= shift`（两种 order）

Scanner 有 8 个 descriptor 变体（32/64-bit × shift→mask/mask→shift × with-copy/in-place）

**Kernel 验证**：`bpf_jit_validate_bitfield_extract_rule()` 验证 shift+mask 参数

**X86 优化**：`emit_canonical_bitfield_extract()` / `emit_bitfield_extract_core()`
- 有 BMI2 → `bextr reg, src, start+(width<<8)`（一条指令）
- 无 BMI2 → `shr + and`

**已知 Bug（已修复）**：BEXTR src==dst guard 过严，修复后 `extract_dense` code size -768B（1.5B/site）

**实测结果**：bitfield_extract benchmark 1.288x；extract_dense 0.556x（512 sites，I-cache flush 开销仍高）

---

### CF_ZERO_EXT_ELIDE（family: zero-ext）

**识别**：BPF 验证器在 32-bit ALU 之后插入 `zext` 操作（`mov.64 dst, dst, imm=1`），但 x86 已自动零扩展。Scanner 识别 `ALU32 + zext(imm=1)` pair。

**Kernel 验证**：`bpf_jit_validate_zero_ext_elide_rule()` 检查位置和 ALU32 形状

**X86 优化**：`emit_canonical_zero_ext_elide()` 省略显式的 `xor reg32, reg32`（x86-64 写 32-bit reg 已隐式零扩展）

**实测结果**：corpus census 中 zero-ext sites = 0（因为 `bpf_jit_needs_zext()`=false，x86 不插 zext pair）；实际 corpus 覆盖为零

---

### CF_ENDIAN_FUSION（family: endian）

**识别**：`ldxh/ldxw + bswap16/32`（load-swap）或 `bswap16/32 + sth/stw`（swap-store）序列

Scanner 识别两个方向，支持 16/32-bit。

**Kernel 验证**：`bpf_jit_validate_endian_fusion_rule()` 检查 load/store + bswap 对

**X86 优化**：`emit_canonical_endian_fusion()` → `movbe reg, [mem]` 或 `movbe [mem], reg`（MOVBE 指令需要 CPU feature gate BPF_JIT_X86_MOVBE）

**实测结果**：endian_swap_dense 持续回归（0.695x pre-fix → 1.013-1.139x post-BEXTR-fix with 256 sites 恢复）。MOVBE=5B 与原 LDX+BSWAP32=5B 等大，I-cache flush 开销 ≥ 微架构收益，policy-sensitive（需 big-endian 数据路径证据才有净收益）

---

### CF_BRANCH_FLIP（family: branch-flip）

**识别**：`jcc +skip, body_a..., ja +skip, body_b...`（if/else diamond）→ 识别完整 pattern 包括 jcc + body_a + ja + body_b（最大 site_len=34）

`build_branch_flip_rule()` 验证：
- jcc.off 在 [2,17] 范围（body_a 最多 16 insn）
- body_a 和 body_b 只含支持的指令（ALU/load，无 call/exit）
- 无 interior edge
- body_a/body_b 长度均 [1,16]

**Kernel 验证**：`bpf_jit_validate_branch_flip_rule()` 校验 site 形状和参数（BODY_A_START/LEN、BODY_B_START/LEN、JOIN_TARGET）

**X86 优化**：`emit_canonical_branch_flip()` 交换 body_a 和 body_b 的 emit 顺序（将"热 taken 分支"变为 fallthrough），重新 patch 跳转 offset

**实测结果**：branch_flip_dense 1.052x win（255 sites），large_mixed_1000 1.137x。但 same-size 重编在 dense 场景下 I-cache flush 开销显著。Policy-sensitive。

---

## 3. Scanner 文档现状

### 现有文档

- `scanner/include/bpf_jit_scanner/types.h`：ABI 常量定义（canonical form 编号、native choice 值、CPU feature 位），有 SPDX 和注释，是唯一公开的 ABI 参考。
- 代码注释：`jit_directives.c` 中的 kernel-side 函数有 doxygen-style 注释（如 `bpf_jit_has_interior_edge`）。
- `docs/tmp/` 下有大量调查报告，但非正式文档。

### 缺失的文档

1. **Scanner README**：`scanner/` 目录没有 README.md，没有说明三个子命令（scan/apply/enumerate）的用法、输入格式、输出格式。
2. **Pattern descriptor 说明**：`pattern_v5.cpp` 中 8 种 family 的 descriptor 构建逻辑（`add_v5_cond_select_descs_for_jump` 等）无文档，只有代码。
3. **Policy format specification**：v3 policy YAML 格式（version/program/sites 三字段，site 含 insn/family/pattern_kind）无用户可读规范（只有 `docs/tmp/policy-v2-authoritative-spec.md` 已过时）。
4. **Canonical form 参数表**：每个 form 的 canonical params（BPF_JIT_*_PARAM_* 常量）与 bindings 关系无文档记录。
5. **Safety model 说明**：memfd 密封、kernel-side validation 链条、fail-closed 语义无集中文档。

### 建议

应在 `scanner/README.md` 写入：
- 三个子命令的用法示例
- v3 policy YAML 格式规范
- 8 个 canonical form 的识别条件和 native choice 列表
- CPU feature gating 说明（CMOV/BMI2/MOVBE）

---

## 4. 当前限制

| 限制 | 说明 | 影响 |
|------|------|------|
| **Full-image recompile** | Re-JIT 是全程序重编译，site 优化改变 non-site 字节（跳转 offset 漂移）。无 patch-site 能力。 | I-cache flush 开销吃掉 dense site 的微架构收益（endian_swap_dense、extract_dense） |
| **Broadened COND_SELECT fail-close** | guarded-update/switch-chain patterns 识别但 x86 emitter 不支持，fail-close 回退 stock | 扫到的 site 实际未 apply |
| **ZERO_EXT_ELIDE corpus=0** | x86 `bpf_jit_needs_zext()`=false，BPF verifier 不插 zext pair，scanner 无法找到 live sites | corpus census 中此 family 贡献为零 |
| **BEXTR dense 劣化** | 512 sites 的 dense BEXTR 场景 code size 减少但 I-cache flush 使 exec 劣化（0.556x） | 需要 cost model 跳过 dense site 超阈值情况 |
| **ENDIAN/BRANCH_FLIP same-size** | MOVBE=LDX+BSWAP=5B，branch_flip 体积等价，微架构收益 ≤ flush 开销 | 持续 policy-sensitive，需要 branch prediction 信息才有净收益 |
| **No daemon mode** | enumerate 是一次性 CLI，不能持续监控新 BPF 程序 | 部署场景需手动重跑 |
| **No cost model** | 无法自动判断"值不值得 apply"（same-size/dense 超阈值） | 依赖手工 policy tuning |
| **Prologue 未覆盖** | 函数 prologue 优化（NOP、frame pointer 保存等）未实现任何 canonical form | 占 pure-JIT gap 约 18.5% |
| **WIDE_MEM 覆盖不足** | byte-recompose 占 gap 50.7% 但当前只覆盖 load 路径，multi_acc_4 等 benchmark 仍未命中 | 最大单 family 改进空间 |
| **struct_ops 不支持** | live attached struct_ops 需要 trampoline regeneration，当前返回 `-EOPNOTSUPP` | scx_rusty 无法 re-JIT |

---

## 5. 总结

BpfReJIT 的 pipeline 是：

**enumerate xlated bytecode → userspace pattern match → YAML policy 过滤 → memfd sealed blob → BPF_PROG_JIT_RECOMPILE syscall → kernel validate → x86 JIT 收敛 loop 中按 site 分发 canonical emitter**

系统架构实现了安全与优化的完整分离：kernel 负责验证（shape + canonical params + interior edge），userspace 负责发现（pattern match）和决策（policy YAML）。当前覆盖 8 个 canonical form，总体 micro 达到 1.006x overall / 1.040x applied-only（62 benchmarks, Build #40, policy-optimized）。主要限制是 full-image recompile 导致的 I-cache flush 开销，以及部分 canonical form（尤其 ZERO_EXT_ELIDE、prologue）覆盖空白。
