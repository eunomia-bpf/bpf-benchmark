# Digest Binding And Template Emitter Architecture

Date: 2026-03-20

Scope:
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/jit_policy.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `scanner/src/pattern_v5.cpp`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/emitter_cost_and_branchflip_analysis_20260320.md`
- `docs/tmp/form_cost_reduction_design_20260320.md`

Constraint:
- 只做调研设计，不改现有实现。

## Executive Summary

结论先行：

1. `template emitter` 方向总体可行，尤其适合 `ROTATE / ADDR_CALC / BITFIELD_EXTRACT / ENDIAN_FUSION`。`WIDE_MEM` 也可模板化，但不是“简单 byte template”，而是“小型 template program / token stream”。
2. `digest binding` 如果按“kernel 只做通用 hash check，不再验证 form shape/params”来理解，在当前 **fail-closed / userspace 不可信** 的安全模型下 **不成立**。
3. 原因不是 hash 强度，而是 **digest 不能证明 userspace 给的 params 是从这个 site 正确提取出来的，也不能证明这个 site 本身属于 kernel 认可的 safe pattern**。用户态可以对任意 site 计算 digest。
4. 因此，纯 `digest-only validator` 只有在你把 scanner 纳入 trusted computing base，或者引入签名/attestation 机制时才成立；这与当前设计原则 `Validator = 唯一安全门` 冲突。
5. 可落地的版本是 **hybrid**：
   - `prog_tag + insn_cnt` 继续做 whole-program binding
   - 新增 `site_digest` 做 per-site stale binding
   - 新增 `binding_id` 指向一个 kernel-known binding/template descriptor
   - kernel 不再“搜索所有 pattern”，而是只验证 **claimed binding_id**
   - simple form 改成 template emitter
   - `COND_SELECT / BRANCH_FLIP` 继续走 hand-written validator + emitter
6. 在这个 hybrid 方案下，simple form 的内核边际成本可以降到大约 **25-60 LOC/x86-only form** 或 **35-75 LOC/cross-arch form**。这已经接近 kernel peephole 的量级，但不会达到“每个 form 只剩 20 行模板数据”那么激进。
7. 如果接受 weaker trust model，纯 digest-only 版本在 LOC 上确实能接近你的目标；但我不建议把它作为主方案。

我的推荐：

- **推荐主方案**：`safe hybrid`
- **不推荐主方案**：`pure digest-only`
- **复杂 form 处理**：
  - `COND_SELECT` 保留 custom validator，emitter 暂不强行模板化
  - `BRANCH_FLIP` 保留 custom validator + emitter，另行推进 shared linear emitter helper

## 1. 当前 Validator 到底在做什么

当前 kernel validator 不只是 pattern matching。

### 1.1 通用层 checks

`bpf_jit_validate_rule()` 里现在做了这些共享检查：

- rule 头是否合法：`site_len > 0` 且不超过 `BPF_JIT_MAX_PATTERN_LEN` [`vendor/linux-framework/kernel/bpf/jit_validators.c:1898`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)
- site range 是否越界 [`vendor/linux-framework/kernel/bpf/jit_validators.c:1950`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)
- `native_choice` 是否属于该 form，且该 arch/CPU 是否支持 [`vendor/linux-framework/kernel/bpf/jit_validators.c:1956`](../../vendor/linux-framework/kernel/bpf/jit_validators.c), [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5734`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c), [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3850`](../../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)
- site 是否有 side effect，如 `CALL`/`ST`/`STX` [`vendor/linux-framework/kernel/bpf/jit_validators.c:1806`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)
- site 内是否有 interior edge [`vendor/linux-framework/kernel/bpf/jit_validators.c:158`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)

这些检查不因为引入 digest 就消失。特别是 `interior edge` 和 side effect gate，本质上是 CFG / safety gate，不是 pattern duplication。

### 1.2 form-specific validator 还做了什么

除 pattern match 外，当前 validator 还负责：

- **canonical params 提取**
  - 通用表驱动 path：`bpf_jit_pattern_extract_params()` [`vendor/linux-framework/kernel/bpf/jit_validators.c:397`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)
  - 结果写入 `struct bpf_jit_canonical_params` [`vendor/linux-framework/include/linux/bpf_jit_directives.h:35`](../../vendor/linux-framework/include/linux/bpf_jit_directives.h)
- **param bounds / normalization**
  - 通用 bounds：`bpf_jit_pattern_bounds_ok()` [`vendor/linux-framework/kernel/bpf/jit_validators.c:433`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)
  - `ROTATE` 会推导 `rot_amount` 并验证 `rot + rsh == width`
  - `BITFIELD_EXTRACT` 会做 mask normalization
  - `ENDIAN_FUSION` 会从 mem opcode 推导 width
- **semantic post-check**
  - `COND_SELECT` 还要做 alias check [`vendor/linux-framework/kernel/bpf/jit_validators.c:744`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)
  - `BRANCH_FLIP` 还要做 diamond CFG、body linearizability、x86 native byte budget，并 `kmemdup()` 两个 body [`vendor/linux-framework/kernel/bpf/jit_validators.c:1662`](../../vendor/linux-framework/kernel/bpf/jit_validators.c), [`vendor/linux-framework/kernel/bpf/jit_validators.c:1749`](../../vendor/linux-framework/kernel/bpf/jit_validators.c)

所以当前 validator 的职责是：

1. 证明 site 属于某个 kernel-known safe shape
2. 从 live xlated site 提取 canonical params
3. 证明这些 params 在 arch-independent 语义上安全

这是当前安全模型的核心。

## 2. Digest Binding 可行性

## 2.1 现在已经有 whole-program binding

当前 policy header 已经带：

- `insn_cnt`
- `prog_tag`
- `arch_id`

定义在 [`vendor/linux-framework/include/uapi/linux/bpf.h:1475`](../../vendor/linux-framework/include/uapi/linux/bpf.h)，验证在 [`vendor/linux-framework/kernel/bpf/jit_policy.c:302`](../../vendor/linux-framework/kernel/bpf/jit_policy.c) 和 [`vendor/linux-framework/kernel/bpf/jit_policy.c:312`](../../vendor/linux-framework/kernel/bpf/jit_policy.c)。

也就是说，**policy 已经绑定到“这个 live xlated program”**。  
`site_digest` 不是从 0 到 1 的 binding；它是从 whole-program binding 再细化到 per-site binding。

## 2.2 纯 digest-only 为什么不安全

如果新方案是：

1. scanner 识别某个 form
2. scanner 把 `site_digest + canonical params` 填进 blob
3. kernel 只验证 `hash(site bytes) == site_digest`
4. emitter 无条件相信 params

那么这个设计有两个根本问题。

### 问题 A：digest 不能证明 site 是 safe pattern

userspace 完全可以对一个 **不属于任何 safe pattern** 的 site 计算 digest。  
digest 只能说明“blob 里的 digest 和当前 site bytes 一致”，不能说明“这个 site bytes 是 kernel 认可的 pattern”。

### 问题 B：digest 不能证明 params 是从 site 正确提取的

哪怕 site 本身是一个 safe pattern，userspace 也可以：

- 给出错误的 `dst_reg`
- 给出更大的 offset / width
- 给出与 site 不一致的 mask / shift / direction

然后自己计算与这些恶意 params 相匹配的 digest。

**注意**：即使用 crypto hash，也解决不了这个问题。  
因为攻击者不是在找 collision 来匹配一个 kernel-chosen digest，而是在自己选择 `(site, params, digest)` 三元组。

所以：

- **hash collision 不是主问题**
- **缺少 kernel-owned semantic proof 才是主问题**

结论：

> 在当前“userspace 不可信、validator 是唯一安全门”的模型下，digest 本身不能替代 kernel-side form validation。

## 2.3 什么情况下 digest-only 才成立

只有以下两类前提下，纯 digest-only 才能成立：

1. **scanner 被纳入 TCB**
   - 也就是内核明确把 scanner 当成 trusted code
2. **policy blob 带可信 attestation**
   - 例如由 kernel-trusted signer 对 `(program, site, params, form)` 签名

这两条都不是当前 BpfReJIT 的设计方向。

## 2.4 推荐的 digest 角色：stale binding，不是 safety proof

我建议把 `site_digest` 的角色限定为：

- 检测 stale site
- 避免 scanner 输出和 live xlated site 漂移
- 给 policy debug / cache / incremental update 提供稳定 key

不要把它当成：

- pattern safety proof
- param authenticity proof

## 2.5 params 应该从哪来

### 纯 digest-only 版本

如果走纯 digest-only，就只能让 scanner 预提取 params，放进 blob。

scanner 现在已经有这部分“知识基础”：

- descriptor 里有 binding 表 `V5Binding` [`scanner/src/pattern_v5.cpp:116`](../../scanner/src/pattern_v5.cpp)
- scanner 在 match 成功后会知道 `canonical_form` / `native_choice` / `pattern_kind` [`scanner/src/pattern_v5.cpp:378`](../../scanner/src/pattern_v5.cpp)

所以 **userspace 预提取 params 在工程上没有障碍**。

### safe hybrid 版本

推荐这样做：

1. scanner 预提取 compact canonical params，写入 blob
2. scanner 同时写 `binding_id`
3. kernel 按 `binding_id` 找到一个 kernel-known binding descriptor
4. kernel 不再“遍历所有 pattern 去 match”
5. kernel 只验证这个 claimed `binding_id`
   - site digest 是否匹配
   - site bytes 是否满足该 binding descriptor
   - blob params 是否满足该 descriptor 的 bounds / post-check

这样 kernel 没有再做“大海捞针式的 pattern search”，但仍然保留 fail-closed。

## 2.6 hash 算法选择

先说结论：

- 如果 digest 只是 **stale binding / cache key**：`64-bit non-crypto hash` 就够
- 如果 digest 是长期 ABI 字段、你想把 accidental collision 风险压低：推荐 **128-bit**
- 即便用 crypto hash，也 **不能** 单独提供 params/site 安全性

### 性能影响

性能几乎不是问题。

原因：

- 计算发生在 scanner 构造 blob 时
- kernel 只在 policy parse / recompile 时验证
- 不是 packet hot path
- 单个 site 最多 `64` 条 BPF 指令，最多约 `64 * 8 = 512B`

即便一份 policy 有 `1024` 个规则，全部重算也不过几百 KB 输入。相比 re-JIT 开销可忽略。

### 推荐

我建议：

- **主推荐**：`BLAKE2s-128` 或 `SHA-256` 截断到 `128` 位
  - 原因：ABI 稳定、 accidental collision 风险极低、parse-time 成本可忽略
- **如果只想最小工程量**：`XXH3-64`
  - 前提：明确声明 digest 不是安全边界

## 2.7 xlated 在 load 后被修改怎么办

当前实现里，这个问题没有看起来那么严重。

### 事实 1：live scanner 读的是已经加载后的 xlated

scanner 现在扫描的是 live xlated program，而不是原始 ELF 指令流 [`scanner/src/pattern_v5.cpp:1817`](../../scanner/src/pattern_v5.cpp)。

### 事实 2：kernel validator 也看 `prog->insnsi`

policy parse 时直接用 `prog->insnsi` 做验证 [`vendor/linux-framework/kernel/bpf/jit_policy.c:199`](../../vendor/linux-framework/kernel/bpf/jit_policy.c)。

### 事实 3：blinded program 现在直接拒绝 recompile

当前 recompile syscall 对 `prog->blinded` 直接 `-EOPNOTSUPP` [`vendor/linux-framework/kernel/bpf/jit_directives.c:652`](../../vendor/linux-framework/kernel/bpf/jit_directives.c)。

所以：

- load-time verifier / fixup 已经体现在 live xlated 里
- scanner 和 kernel 看的都是同一份 live xlated
- 当前唯一明确会破坏 offset/stability 的 blinding 已被禁止

结论：

- **正常 live-scanner 流程下，load 后 fixup 不会导致 digest mismatch**
- **会 mismatch 的场景**：
  - 你拿 pre-load/raw ELF 指令算 digest
  - 你拿 stale xlated snapshot 生成 policy
  - 将来支持 blinding 后却还沿用 pre-blind digest

## 3. Template Emitter 可行性

## 3.1 先给结论表

| Form | x86 | ARM64 | 结论 |
|---|---|---|---|
| `WIDE_MEM` | 可做 template program，不适合简单 byte template | 可做 template program，且比 x86 更顺手 | 可行，但不是最小模板 |
| `ROTATE` | 适合结构化模板 | 非常适合模板 | 强烈推荐模板化 |
| `ADDR_CALC` | 适合结构化单指令模板 | 未来也很适合 | 强烈推荐模板化 |
| `BITFIELD_EXTRACT` | 适合结构化 2-insn 模板 | 非常适合模板 | 强烈推荐模板化 |
| `ENDIAN_FUSION` | 适合结构化单/双指令模板 | ARM64 未来也容易 | 推荐模板化 |
| `COND_SELECT` | 不建议先做 | 不建议先做 | 保留 custom |
| `BRANCH_FLIP` | 不建议塞进模板引擎 | ARM64 目前无实现 | 保留 custom |

## 3.2 x86 不能只做“raw byte template”

x86 emitter 的问题不是 form 逻辑，而是编码细节：

- `REX` prefix 可选 [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2109`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
- `ModRM`
- `SIB`
- `disp8 / disp32 / no-disp` 三种 memory suffix [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1360`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
- `VEX3` prefix [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1884`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)

因此，x86 需要的不是：

- “一个 `u8[]` 模板 + 几个 offset patch”

而是：

- **一个小型结构化 encoding template engine**

也就是模板 token 里能表达：

- emit literal byte
- emit `REX` from reg fields
- emit `ModRM`
- emit `SIB`
- emit memory suffix with variable displacement size
- emit `VEX3`
- emit `imm8/imm32`

这仍然是 template emitter；只是它比“memcpy 固定 bytes”高一级。

## 3.3 各 form 具体判断

### `ROTATE`

x86 当前逻辑：

- `RORX` 路径：一条带 `VEX3 + ModRM + imm8` 的指令 [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2169`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
- `ROR` 路径：可能先 `mov`，再 `ror reg, imm`

判断：

- **可以模板化**
- 但需要两种模板：
  - `RORX`
  - `MOV(optional) + ROR`
- scanner 预提取的参数只需：
  - `dst_reg`
  - `src_reg`
  - `ror_imm`
  - `is64`

ARM64 当前就是单条 `A64_ROR_I()` [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:638`](../../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)，几乎是理想模板。

### `ADDR_CALC`

x86 当前就是：

- `lea dst, [base + index*scale]`

编码逻辑在 `emit_lea_base_index()` [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2109`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)，主要复杂度是：

- REX bits
- `rbp/r13` 需要强制 `disp8=0`

判断：

- **非常适合模板化**
- 不是简单 raw bytes，但就是一个结构化单指令模板

### `BITFIELD_EXTRACT`

x86 当前逻辑：

- fast path：`mov`/noop
- normal path：`mov imm32 AUX_REG, control; bextr dst, src, AUX_REG` [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2989`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)

关键点：

- `bextr` 本身需要 `VEX3`
- 但这并不阻碍模板化；只要求 engine 能表达 `VEX3`

判断：

- **可以模板化**
- 需要一个很薄的 guard：
  - `field_width == reg_width && lsb == 0` 时走 copy/noop 模板
  - 否则走 `mov imm32 + bextr` 模板

ARM64 当前就是单条 `UBFX` [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:712`](../../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)，更适合模板。

### `ENDIAN_FUSION`

x86 当前逻辑：

- `movbe load`
- `movbe store`
- `16-bit load` 还要追加零扩展 [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2443`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)

判断：

- **可以模板化**
- 需要两个模板家族：
  - load+optional-zext
  - store

这不是“一个 byte array”，但完全是模板友好的。

### `WIDE_MEM`

x86 当前逻辑是一个 chunk loop [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2072`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)：

- 宽度 `2/4/8` 时走单次 `ldx + optional bswap`
- 其它宽度走：
  - repeated `ldx chunk`
  - optional `bswap`
  - optional `lsh`
  - optional `or`

ARM64 也是同样的 repeated chunk loop [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:654`](../../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)。

判断：

- **可以模板化**
- 但必须是“template program”，不是静态 byte template
- engine 至少要支持：
  - loop / repeat over chunks
  - derived immediate (`shift`)
  - memory access helper
  - conditional op emission

所以：

- `WIDE_MEM` 不适合你设想的“~20 行纯模板数据/form”
- 它适合的是“共享 micro-emitter substrate + 少量 form data”

## 3.4 ARM64 为什么更适合模板化

ARM64 的优势很直接：

- 每条指令固定 4 字节
- 大量 opcode 已有宏形式编码，例如 `A64_ROR_I` / `A64_UBFX`
- 不需要处理 x86 的 `REX/ModRM/SIB/VEX/disp8/disp32`

因此：

- `ROTATE`
- `BITFIELD_EXTRACT`
- 未来的 `ADDR_CALC`
- 未来的 `ENDIAN_FUSION`

这些在 ARM64 上都比 x86 更接近“word template + bitfield patch”。

唯一仍然不够简单的是：

- `WIDE_MEM`，因为它本质上是 variable-length instruction sequence，而不是编码细节问题

## 4. Policy Blob 格式变更

## 4.1 当前 v2 格式

当前 wire format：

- header：`32B`
- rule：`12B`

定义见 [`vendor/linux-framework/include/uapi/linux/bpf.h:1475`](../../vendor/linux-framework/include/uapi/linux/bpf.h) 和 [`vendor/linux-framework/include/uapi/linux/bpf.h:1539`](../../vendor/linux-framework/include/uapi/linux/bpf.h)。

即：

```c
struct bpf_jit_policy_hdr {
	__u32 magic;
	__u16 version;
	__u16 hdr_len;
	__u32 total_len;
	__u32 rule_cnt;
	__u32 insn_cnt;
	__u8  prog_tag[8];
	__u16 arch_id;
	__u16 flags;
}; /* 32B */

struct bpf_jit_rewrite_rule_v2 {
	__u32 site_start;
	__u16 site_len;
	__u16 canonical_form;
	__u16 native_choice;
}; /* 12B */
```

大小公式：

```text
blob_v2 = 32 + 12 * nr_rules
```

## 4.2 推荐的 v3 格式

我建议把 v3 设计成 **mixed-mode**：

- template-capable simple form：走 new bound-template rule
- `COND_SELECT / BRANCH_FLIP`：先保留 legacy rule path

### UAPI wire structs

```c
#define BPF_JIT_POLICY_VERSION_3 3

#define BPF_JIT_RULE_F_TEMPLATE   (1U << 0)
#define BPF_JIT_RULE_F_HAS_DIGEST (1U << 1)
#define BPF_JIT_RULE_F_HAS_PARAMS (1U << 2)

enum bpf_jit_tpl_param_type {
	BPF_JIT_TPARAM_REG = 0,
	BPF_JIT_TPARAM_IMM32 = 1,
};

struct bpf_jit_site_digest128 {
	__u64 lo;
	__u64 hi;
};

struct bpf_jit_template_param_wire {
	__u8  param_id;
	__u8  type;
	__u16 reserved;
	__s32 value;
} __packed; /* 8B */

struct bpf_jit_rewrite_rule_v3 {
	__u32 site_start;
	__u16 site_len;
	__u16 canonical_form;
	__u16 native_choice;
	__u16 binding_id;
	__u16 nr_params;
	__u16 flags;
	__u16 reserved;
	struct bpf_jit_site_digest128 site_digest;
	/* followed by nr_params * struct bpf_jit_template_param_wire */
} __packed; /* 32B header */
```

### 为什么 params 可以压到 32-bit

这要求 template-form 的 canonical params 重新定义成“emitter-ready compact params”，例如：

- `ROTATE`: `dst_reg, src_reg, ror_imm, width_is_64`
- `WIDE_MEM`: `dst_reg, base_reg, base_off, width_bytes, flags`
- `ADDR_CALC`: `dst_reg, base_reg, index_reg, scale`
- `BITFIELD_EXTRACT`: `dst_reg, src_reg, lsb, field_width, reg_width`
- `ENDIAN_FUSION`: `data_reg, base_reg, offset, width, direction`

这样 simple template forms 都不需要 64-bit immediate。

### 内核内部结构

```c
struct bpf_jit_rule {
	u16 canonical_form;
	u16 native_choice;
	u16 binding_id;
	u16 nr_tparams;
	u32 site_start;
	u16 site_len;
	u16 flags;
	u16 user_index;
	struct bpf_jit_site_digest128 site_digest;
	struct bpf_jit_template_param tparams[BPF_JIT_MAX_TEMPLATE_PARAMS];
	struct bpf_jit_canonical_params params; /* legacy custom forms only */
};
```

注意：

- template forms 用 `tparams`
- custom forms 仍用现有 `params`

这样可以渐进迁移，不必一次性改 `COND_SELECT / BRANCH_FLIP`

## 4.3 blob 大小影响

### 当前 v2

```text
32 + 12 * N
```

### 推荐 v3

template rule 头是 `32B`，每个 compact param 是 `8B`：

```text
32 + N * (32 + 8 * avg_params)
```

对于 simple forms：

| Form | Compact params | Per-rule bytes |
|---|---:|---:|
| `ROTATE` | 4 | 64 |
| `WIDE_MEM` | 5 | 72 |
| `ADDR_CALC` | 4 | 64 |
| `BITFIELD_EXTRACT` | 5 | 72 |
| `ENDIAN_FUSION` | 5 | 72 |

对比当前 `12B/rule`，大约是 `5.3x - 6x`。

但绝对值仍然不大：

| 规则数 | v2 | v3 @64B/rule | v3 @72B/rule |
|---:|---:|---:|---:|
| 32 | 416B | 2080B | 2336B |
| 128 | 1568B | 8224B | 9248B |
| 1024 | 12320B | 65568B | 73760B |

即使 `1024` rules，全 blob 仍远低于当前 `512KB` cap [`vendor/linux-framework/kernel/bpf/jit_policy.c:13`](../../vendor/linux-framework/kernel/bpf/jit_policy.c)。

结论：

- blob 会明显变大
- 但 **不会** 成为实际部署障碍

## 5. 推荐的 Safe Hybrid 架构

这是我认为唯一与当前安全模型兼容、同时又能明显减行的版本。

## 5.1 核心思路

1. scanner 继续做 full pattern matching
2. scanner 为每条 rule 产出：
   - `site_start`
   - `site_len`
   - `canonical_form`
   - `native_choice`
   - `binding_id`
   - `site_digest`
   - `compact template params`
3. kernel 解析 rule
4. kernel 做 shared checks：
   - program binding
   - arch binding
   - site range
   - side-effect gate
   - interior-edge gate
5. kernel 根据 `binding_id` 找到 **唯一** 一个 binding descriptor
6. kernel 验证：
   - `site_digest` matches current site
   - current site bytes satisfy that descriptor
   - compact params satisfy descriptor bounds / guard
7. 通过后走 template emitter

## 5.2 关键收益

它消掉的是：

- “每个 form 在 kernel 里搜索/匹配多组 pattern” 的重复
- “每个 emitter 手写大量参数解包 + 编码样板” 的重复

它不消掉的是：

- kernel 对 safety 的最终裁决

## 5.3 binding descriptor 结构

```c
enum bpf_jit_field_kind {
	BPF_JIT_F_CODE,
	BPF_JIT_F_CLASS,
	BPF_JIT_F_DST_REG,
	BPF_JIT_F_SRC_REG,
	BPF_JIT_F_OFF,
	BPF_JIT_F_IMM,
};

enum bpf_jit_bind_expr_kind {
	BPF_JIT_BIND_EXPR_EQ_CONST,
	BPF_JIT_BIND_EXPR_CAPTURE,
	BPF_JIT_BIND_EXPR_EQ_CAPTURE,
	BPF_JIT_BIND_EXPR_RANGE,
};

struct bpf_jit_bind_expr {
	u8 insn_idx;
	u8 field;
	u8 kind;
	u8 slot;
	s64 value;
	s64 value_hi;
};

struct bpf_jit_tpl_param_desc {
	u8 param_id;
	u8 type;
	s32 min;
	s32 max;
};

struct bpf_jit_binding_desc {
	u16 binding_id;
	u16 canonical_form;
	u16 native_choice;
	u8 site_len;
	u8 nr_exprs;
	const struct bpf_jit_bind_expr *exprs;
	u8 nr_params;
	const struct bpf_jit_tpl_param_desc *params;
	bool allow_side_effects;
	bool (*post_check)(const struct bpf_insn *site,
			   const struct bpf_jit_rule *rule);
};
```

这看起来和当前 `bpf_jit_form_pattern` 很像，但有一个关键区别：

- 当前 kernel 要在 form 内 **遍历/搜索** 多个 pattern
- hybrid 里 kernel 只验证 **scanner claim 的那一个 binding_id**

所以：

- 仍然 fail-closed
- 但 pattern duplication 被压成“共享 descriptor + 单点验证”

## 5.4 validator API

```c
bool bpf_jit_validate_rule_v3(const struct bpf_prog *prog,
			      const struct bpf_insn *insns,
			      u32 insn_cnt,
			      const struct bpf_jit_rule *rule);

bool bpf_jit_site_digest_matches(const struct bpf_insn *site,
				 const struct bpf_jit_rule *rule,
				 const struct bpf_jit_binding_desc *desc);

bool bpf_jit_binding_desc_matches(const struct bpf_insn *site,
				  const struct bpf_jit_binding_desc *desc);

bool bpf_jit_template_params_ok(const struct bpf_jit_rule *rule,
				const struct bpf_jit_binding_desc *desc);
```

## 5.5 emitter API

### x86

```c
enum bpf_jit_x86_tpl_op_kind {
	BPF_JIT_X86_OP_BYTE,
	BPF_JIT_X86_OP_IMM8_PARAM,
	BPF_JIT_X86_OP_IMM32_PARAM,
	BPF_JIT_X86_OP_REX_REG_RM,
	BPF_JIT_X86_OP_MODRM_REG_RM,
	BPF_JIT_X86_OP_SIB_SCALE_INDEX_BASE,
	BPF_JIT_X86_OP_MEM_SUFFIX,
	BPF_JIT_X86_OP_VEX3,
	BPF_JIT_X86_OP_HELPER,
};

struct bpf_jit_x86_tpl_op {
	u8 kind;
	u8 a, b, c, d;
	s32 imm;
};

struct bpf_jit_x86_template {
	u16 binding_id;
	u8 nr_ops;
	const struct bpf_jit_x86_tpl_op *ops;
	bool (*guard)(const struct bpf_jit_rule *rule, bool use_priv_fp);
};

int bpf_jit_emit_x86_template(u8 **pprog,
			      const struct bpf_jit_rule *rule,
			      const struct bpf_jit_x86_template *tpl,
			      bool use_priv_fp);
```

### ARM64

```c
enum bpf_jit_a64_patch_kind {
	BPF_JIT_A64_PATCH_REG,
	BPF_JIT_A64_PATCH_IMM,
	BPF_JIT_A64_PATCH_COND,
};

struct bpf_jit_a64_patch {
	u8 kind;
	u8 param_id;
	u8 lsb;
	u8 width;
};

struct bpf_jit_a64_tpl_word {
	u32 base_word;
	u8 nr_patches;
	const struct bpf_jit_a64_patch *patches;
};

struct bpf_jit_a64_template {
	u16 binding_id;
	u8 nr_words;
	const struct bpf_jit_a64_tpl_word *words;
	bool (*guard)(const struct bpf_jit_rule *rule);
};

int bpf_jit_emit_arm64_template(struct jit_ctx *ctx,
				const struct bpf_jit_rule *rule,
				const struct bpf_jit_a64_template *tpl);
```

## 6. `COND_SELECT` 和 `BRANCH_FLIP`

## 6.1 `COND_SELECT`

建议：

- **validator 先保留 hand-written**
- emitter 也先保留 hand-written

原因：

- site shape 不是单一 skeleton
  - guarded update / compact / diamond
- 还有 alias 语义
- true/false value 还支持 reg/imm 混合
- ARM64 emitter 里还有 `cset/csetm/csel/csinv` 等多个 special case [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:734`](../../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)

这类 form 未来可以吃到：

- shared compare/select fragment template

但不值得作为第一批 template form。

## 6.2 `BRANCH_FLIP`

建议：

- **继续保留 hand-written validator + emitter**
- 另开一条线做 shared linear emitter helper

原因：

- validator 里有 CFG / native-byte-budget / body linearizability
- x86 emitter 里最大的成本不是顶层分支翻转，而是 linear replay substrate [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2251`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c), [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2570`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c), [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2769`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c), [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2904`](../../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)

所以：

- `BRANCH_FLIP` 的正确降本方向不是 template engine
- 而是把 replay substrate 从 form-specific code 中抽共享

## 7. ARM64 方向

ARM64 很适合与 template emitter 一起推进。

### 第一批建议 template 化

- `ROTATE`
- `BITFIELD_EXTRACT`
- future `ADDR_CALC`
- future `ENDIAN_FUSION`

### 第二批

- `WIDE_MEM`
  - 需要 template program
  - 但固定 4-byte encoding 让 engine 更清晰

### 不建议首批

- `COND_SELECT`
- `BRANCH_FLIP`

## 8. LOC 估算

## 8.1 当前文件行数

当前工作树里实际行数：

| File | Current LOC |
|---|---:|
| `vendor/linux-framework/kernel/bpf/jit_validators.c` | 1990 |
| `vendor/linux-framework/kernel/bpf/jit_policy.c` | 436 |
| `vendor/linux-framework/include/linux/bpf_jit_directives.h` | 302 |
| `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` | 5764 |
| `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c` | 3922 |
| `scanner/src/pattern_v5.cpp` | 1968 |
| `scanner/include/bpf_jit_scanner/pattern_v5.hpp` | 77 |

## 8.2 不安全的 pure digest-only 估算

这是你原始想法最接近的版本，但我不推荐。

| File | Current | Estimated After | Delta |
|---|---:|---:|---:|
| `jit_validators.c` | 1990 | 760 | -1230 |
| `jit_policy.c` | 436 | 620 | +184 |
| `bpf_jit_directives.h` | 302 | 410 | +108 |
| `arch/x86/net/bpf_jit_comp.c` | 5764 | 5600 | -164 |
| `arch/arm64/net/bpf_jit_comp.c` | 3922 | 3860 | -62 |
| **Kernel subtotal** | **12414** | **11250** | **-1164** |

这就是“接近每 form 只剩模板数据”的代价与收益：

- LOC 很漂亮
- safety model 被削弱

## 8.3 推荐的 safe hybrid 估算

这是我建议落地的版本。

| File | Current | Estimated After | Delta |
|---|---:|---:|---:|
| `jit_validators.c` | 1990 | 1120 | -870 |
| `jit_policy.c` | 436 | 650 | +214 |
| `bpf_jit_directives.h` | 302 | 420 | +118 |
| `arch/x86/net/bpf_jit_comp.c` | 5764 | 5610 | -154 |
| `arch/arm64/net/bpf_jit_comp.c` | 3922 | 3870 | -52 |
| **Kernel subtotal** | **12414** | **11670** | **-744** |

scanner 侧会变大：

| File | Current | Estimated After | Delta |
|---|---:|---:|---:|
| `scanner/src/pattern_v5.cpp` | 1968 | 2190 | +222 |
| `scanner/include/bpf_jit_scanner/pattern_v5.hpp` | 77 | 125 | +48 |
| **Scanner subtotal** | **2045** | **2315** | **+270** |

project 级净变化大约：

```text
kernel -744
scanner +270
----------------
net about -474 LOC
```

这比你目标的 `-920 LOC` 小，但它是与现有 safety model 兼容的数字。

## 8.4 每新增一个 simple substrate peephole 的边际成本

### 推荐的 safe hybrid

| Component | x86-only | x86+arm64 |
|---|---:|---:|
| kernel binding descriptor / guards | 15-30 | 15-30 |
| x86 template data | 10-20 | 10-20 |
| arm64 template data | 0 | 10-20 |
| glue / dispatch | 0-5 | 0-5 |
| **kernel subtotal** | **25-55** | **35-75** |
| scanner descriptor / blob emit | 30-60 | 30-60 |
| **end-to-end subtotal** | **55-115** | **65-135** |

### 对比 kernel-only peephole

典型 kernel-only peephole 大约：

```text
~50 LOC / backend rule
```

对比：

- **kernel-side**：safe hybrid 已经接近 kernel-only
- **project total**：仍然更贵，因为还有 scanner / policy blob / cross-arch

这很合理；因为 BpfReJIT 不是单 backend peephole。

## 9. 安全模型结论

## 9.1 digest binding 是否够安全

### 纯 digest-only

不够。

### safe hybrid

够用，前提是：

- digest 只承担 stale binding
- kernel 仍验证 claimed `binding_id`
- kernel 仍验证 param bounds / post-check
- `COND_SELECT / BRANCH_FLIP` 保留 custom validator

## 9.2 malicious digest / hash collision 会怎样

### pure digest-only

风险不是 collision 本身，而是 userspace 可以构造任意 `(site, params, digest)`。

### safe hybrid

collision 最多让一个错误 site 进入 binding validation。

但因为 kernel 仍会：

- 检查 binding descriptor
- 检查 params
- 检查 side effects / interior edge

所以 collision 不再直接形成安全边界突破。

## 9.3 template emitter 是否有注入风险

有，前提是 emitter 直接相信 userspace params。

规避方法：

1. template forms 只接受 compact, bounded params
2. kernel 对每个 param 做 type/range check
3. kernel 对 claimed binding_id 做 site validation
4. custom forms 继续 hand-written

做到这四点后，template emitter 的角色就是：

- 机械编码

而不是：

- 再次承担 semantic safety

## 10. 最终建议

### 建议做

1. 推进 **template emitter**
   - 第一批：`ROTATE / ADDR_CALC / BITFIELD_EXTRACT / ENDIAN_FUSION`
   - 第二批：`WIDE_MEM`
2. 新增 **site_digest**
   - 但只把它当 stale binding
3. 新增 **binding_id**
   - kernel 只验证 claimed descriptor，不再搜索整组 pattern
4. `COND_SELECT / BRANCH_FLIP` 先保留 custom path

### 不建议做

1. 不建议把 `digest-only validator` 作为主方案
2. 不建议把 `BRANCH_FLIP` 塞进 template engine
3. 不建议为了压 blob 大小继续复用当前“大而全”的 `binding_value[16]` 线格式；simple template forms 应该改成 compact params

### 一句话版本

> `template emitter` 值得做；`digest binding` 值得做，但只能做 stale binding。  
> 真正可落地的架构是 `prog_tag + site_digest + binding_id + template emitter + custom fallback for complex forms`，而不是“kernel 只做 hash check”。

