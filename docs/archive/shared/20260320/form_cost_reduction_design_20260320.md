# Form Cost Reduction Design

Date: 2026-03-20

Scope:
- `docs/kernel-jit-optimization-plan.md` §1.4 #11
- `docs/tmp/emitter_cost_and_branchflip_analysis_20260320.md`
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

Constraint summary:
- 不回退到 #218 之前的重 DSL。
- `Validator = 唯一安全门` 保持不变。
- fail-closed 保持不变。
- 不引入运行时解释器或动态代码生成。
- 本轮不改 scanner。

## Executive Summary

本轮落地的是一个“轻量 compile-time matcher + 少量 post-check callback”的中间层，只覆盖 **定长 simple form**，不强行统一 `ROTATE/WIDE_MEM/COND_SELECT/BRANCH_FLIP`。

已实施：
- 在 `jit_validators.c` 新增轻量表驱动 validator substrate：
  - `bpf_jit_pattern_check`
  - `bpf_jit_pattern_extract`
  - `bpf_jit_form_pattern`
  - `bpf_jit_validate_form_patterns()`
- 把 3 个 simple validator 切到该 substrate：
  - `ADDR_CALC`
  - `BITFIELD_EXTRACT`
  - `ENDIAN_FUSION`
- 在 `bpf_jit_directives.h` 增加 param accessor。
- 在 x86/arm64 emitter 侧增加最小的 param-unpack helper，减少新 form emitter 的固定样板代码。

核心判断：
- **kernel-side 边际成本** 已经可以降到约 **80-150 LOC/form**（simple fixed-length form）。
- **project end-to-end 边际成本** 这轮还不能稳定落到 100-150 LOC，因为 scanner 仍然是独立维护的一份 pattern 描述；当前更现实的是 **130-250 LOC/form**。
- 这轮代码有 **一次性 substrate 投资**，所以立即总 LOC 不是净减少，而是为后续 simple form 降低边际成本。

## Design

### 1. Validator substrate

数据结构：

```c
struct bpf_jit_pattern_check {
	u8 insn_idx;
	u8 field;   /* code/dst/src/off/imm */
	u8 op;      /* eq/range/capture/eq_capture/ne_capture */
	u8 slot;
	s64 value;
	s64 value2;
};

struct bpf_jit_pattern_extract {
	u8 param;
	u8 kind;    /* reg-field / imm-field / const-imm */
	u8 insn_idx;
	u8 field;
	s64 value;
};

struct bpf_jit_form_pattern {
	u8 site_len;
	const struct bpf_jit_pattern_check *checks;
	u8 nr_checks;
	const struct bpf_jit_pattern_extract *extracts;
	u8 nr_extracts;
	const struct bpf_jit_pattern_bound *bounds;
	u8 nr_bounds;
	bpf_jit_pattern_post_fn post;
	s64 post_arg;
};
```

匹配流程：

1. `bpf_jit_validate_form_patterns()` 先做 `site_range` 检查。
2. 逐个 pattern 尝试。
3. 通用 matcher 执行：
   - 字段常量检查
   - 范围检查
   - capture / equality / inequality 关系检查
4. 通用 extractor 填 canonical params。
5. 可选 `post()` 做少量 form-specific 语义归一化。
6. 任一步失败直接 `false`，保持 fail-closed。

设计边界：
- 只覆盖 **定长、无循环、参数主要来自指令字段** 的 form。
- 允许很薄的 `post()`，但不允许把整套 validator 逻辑又塞回 callback。
- 复杂 form 继续保留手写 validator，避免重新发明 DSL。

### 2. Applied forms

`ADDR_CALC`
- 纯 3-insn fixed pattern。
- 完全由 table 描述，无额外 callback。

`BITFIELD_EXTRACT`
- 用 8 个 pattern 覆盖：
  - 32/64 bit
  - with/without `mov`
  - `rsh; and` / `and; rsh`
- `post()` 只保留 mask normalization。

`ENDIAN_FUSION`
- 用 2 个 skeleton pattern 覆盖：
  - load+swap
  - swap+store
- `post()` 负责从 mem opcode 推导 width，并验证 swap opcode。

### 3. Emitter helper

本轮没有再抽新的 “site iteration / staged commit” 层，因为 x86/arm64 已经有这层共享逻辑。

本轮只做低风险收敛：
- `bpf_jit_param_value()`
- `bpf_jit_param_reg()`
- `bpf_jit_param_imm()`
- `x86_jit_param_reg()`
- `arm64_jit_param_reg()`

效果：
- simple emitter 不再重复手写 `params->params[...]` 解包。
- 新 form emitter 更接近“参数读取 + 真实编码逻辑”两段式。

### 4. Why not convert everything

`ROTATE`
- 仍有 masked / two-copy / swapped-shift 等组合，继续手写更稳。

`WIDE_MEM`
- 可变长度，且 shape 不是简单定长 tuple。

`COND_SELECT`
- 还有 alias / compact / diamond / guarded-update 等 control/data relation。

`BRANCH_FLIP`
- 真正大头是 x86 replay substrate，不是 validator boilerplate。

结论：
- 本轮 substrate 是 **fixed-length simple form substrate**，不是“万能 matcher”。
- 这正是避免重走重 DSL 回头路的关键。

## LOC Evaluation

### 1. 开工前工作树计数

本 turn 开工前记录：

| File | Before |
|---|---:|
| `kernel/bpf/jit_validators.c` | 1749 |
| `arch/x86/net/bpf_jit_comp.c` | 5772 |
| `arch/arm64/net/bpf_jit_comp.c` | 3934 |
| `include/linux/bpf_jit_directives.h` | 256 |

### 2. 实施后计数

| File | After | Delta |
|---|---:|---:|
| `kernel/bpf/jit_validators.c` | 2056 | +307 |
| `arch/x86/net/bpf_jit_comp.c` | 5764 | -8 |
| `arch/arm64/net/bpf_jit_comp.c` | 3922 | -12 |
| `include/linux/bpf_jit_directives.h` | 302 | +46 |
| **Touched kernel total** | **12044** | **+333** |

解释：
- 这是 **一次性 substrate 投资**，不是立即减法。
- `validator` 的共享 matcher 还没被更多 form amortize，所以当前 net LOC 为正。

### 3. Per-form marginal cost after this change

对“定长 simple form”：

| Component | New marginal LOC |
|---|---:|
| validator descriptor + wrapper | 25-70 |
| small post-check callback | 0-25 |
| x86 emitter | 25-45 |
| arm64 emitter | 15-35 |
| **kernel total** | **80-150** |

这已经达到我认为可兑现的 **kernel-side 目标**。

但 scanner 本轮没改，因此 project total 仍是：

| Component | Marginal LOC |
|---|---:|
| kernel | 80-150 |
| scanner (current practice) | 50-130 |
| **end-to-end total** | **130-250** |

所以：
- **这轮没有单独把全系统稳定打到 100-150 LOC/form。**
- 但它已经把 kernel 侧降到了目标区间，并为后续 scanner/kernel 统一描述打好了接口形状。

### 4. Amortization

当前一次性投资大约 `+333 LOC`。

如果后续 simple form 的 kernel 节省是：
- 保守 `70 LOC/form`，约 5 个 form 回本。
- 中位 `100 LOC/form`，约 3-4 个 form 回本。
- 乐观 `120 LOC/form`，约 3 个 form 回本。

## Validation

已通过：

1. `make -C vendor/linux-framework -j$(nproc) bzImage`
2. `make vm-selftest`
   - `PASS all 35 test(s)`
3. `make vm-micro-smoke`
4. `make scanner-tests`

额外检查：
- `make -C vendor/linux-framework kernel/bpf/jit_validators.o`
- `make -C vendor/linux-framework arch/x86/net/bpf_jit_comp.o`
- `git diff --check`

未完成的额外检查：
- 独立 `ARCH=arm64` object build 我尝试过，但 Kbuild 因 source tree 非 clean 而拒绝在新的 `O=` 目录启动；我没有执行 `mrproper`，避免破坏当前工作树。

## Recommendation

下一步如果要把 **全系统** marginal cost 真正压到 100-150 LOC，需要继续两件事：

1. scanner 侧消费同一份 compile-time descriptor，至少消掉 `ADDR_CALC / ENDIAN / BITFIELD` 这类双写。
2. 对 `ROTATE/WIDE_MEM` 再加一层“有限可变长度 pattern”模板，但不要把 `BRANCH_FLIP` 也塞进去。

当前结论：
- 这轮方案 **可行**。
- 风险 **可控**。
- 已经把 **kernel-side simple form** 新增成本压到 100 行级别。
- 但因为 scanner 不在本轮范围内，**project-wide 100-150 LOC/form 还需要下一步 scanner/kernel 统一工作**。
