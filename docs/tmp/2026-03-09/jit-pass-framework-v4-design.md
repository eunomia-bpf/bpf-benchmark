# BPF JIT 后端策略框架 v4 设计

日期：2026-03-09

## 1. 摘要

v4 是对 v3 的根本重新思考。v3 试图构建一个复杂的可扩展框架（family 抽象、plan system、alt table、region dispatcher、overlap arbitration、budget system），但在 POC 阶段引入了过多的间接层，而回避了论文最核心的两个创新点。v4 回到第一性原理，只聚焦两个关键设计变化：

**创新 1：机器码级 instruction selection 是 userspace policy 的一部分。**

v3 明确说"userspace 不能请求'发 rorx 而不是 ror'这类机器码级别决策"（v3 §7）。v4 认为这恰恰是错的。论文的核心 thesis 是 userspace 控制 backend policy；而 instruction selection——选择用哪条 native 指令实现某个语义操作——正是 backend policy 的核心内容。`rorx` vs `ror`、`cmovcc` vs `jcc+mov`、`lea` vs `mov+shl+add`、`movzx` vs `xor+mov`，这些决策的最优解取决于 CPU 微架构、workload 特征和部署上下文。Kernel 的职责只是验证所选指令在当前 CPU 上合法（feature gating），而不是代替 userspace 做选择。

**创新 2：从 `BPF_PROG_LOAD` 分离出 `BPF_PROG_JIT_RECOMPILE`。**

v3 把 policy blob 绑在 `BPF_PROG_LOAD` 上，这意味着每次更改 policy 都要重新加载和验证程序。v4 引入独立的 `BPF_PROG_JIT_RECOMPILE` subcommand：拿着一个已加载程序的 `prog_fd` + policy blob，触发 re-JIT。这使得 runtime PGO、dynamic A/B testing、policy hot-reload 成为可能，而且避免了昂贵的重新验证。

这两个创新加在一起，构成了论文真正的系统贡献：**一个 post-load、可迭代的 native instruction selection policy 框架**。

### 1.1 与 v3 的关系

v4 不是 v3 的增量改进，而是对同一问题的不同回答。

| 维度 | v3 | v4 |
|------|----|----|
| 核心抽象 | Family / Alt table / Plan system | Rewrite rule (pattern → native emission) |
| Userspace 控制粒度 | 选择 kernel 预注册的 semantic alt | 指定具体 native instruction sequence |
| 传输时机 | 绑定在 BPF_PROG_LOAD | 独立 BPF_PROG_JIT_RECOMPILE |
| 可迭代性 | 需要重新加载程序 | 运行中程序可反复 re-JIT |
| 实现复杂度 | 5 个通用基础设施层 | 扁平 rule 列表 + 简单验证 |
| 框架 overhead | ~2000 LOC 基础设施 | ~800-1200 LOC 总量 |
| 扩展模型 | 新 family = validator + emitter/arch | 新 rule = pattern + emission spec |

核心不变量保持一致：
- `xlated_prog_len` 不变
- 只改变 `jited_prog_len`
- Fail-closed：任何 rule 失败回退到 stock JIT emission

---

## 2. 为什么 v4 是正确的 POC 设计

### 2.1 "机器码选择就是 policy"的论证

v3 的 §7 写道：

> userspace 只能请求 family 和 alt preference，不能请求"发 `rorx` 而不是 `ror`"这类机器码级别决策

这个限制在 production 系统中有道理——UAPI 稳定性要求不暴露机器码细节。但对 POC 和论文来说，这个限制直接削弱了核心 thesis：

1. **论文 thesis 就是 userspace backend policy**。如果 userspace 只能从 kernel 预定义的 alt 中选，那 kernel 就是 policy maker，userspace 只是 policy selector。这不够强。

2. **Instruction selection IS the backend decision**。编译器后端的核心工作就是 instruction selection——把抽象操作映射到具体机器指令。论文说的"backend policy"如果不包含 instruction selection，那它到底包含什么？

3. **profitability 依赖微架构细节**。`rorx`（VEX 编码，non-destructive）在某些 CPU 上比 `ror` 快（不需要 mov 保存原值）。`lea` 的 latency/throughput 在不同微架构上不同。这些差异正是 userspace policy 存在的理由。

4. **这是 POC，不需要 UAPI 稳定性**。POC 的目的是证明概念，不是设计 20 年不变的 API。让 userspace 直接说"用 cmovcc"比让它说"请求 SELECT family 的 alt #3"更清晰、更直接。

5. **Kernel 的合法性检查依然存在**。Userspace 说"用 rorx"，kernel 检查 `CPUID.BMI2`。Userspace 说"用 cmovcc"，kernel 检查 `CPUID.CMOV`。这就是 mechanism/policy 分离的正确形态——userspace 选指令，kernel 验合法性。

### 2.2 "Post-load re-JIT"的论证

v3 把 policy 绑在 `BPF_PROG_LOAD` 上。这带来几个问题：

1. **无法做 runtime PGO**。最有说服力的 policy 场景是：先加载运行、收集 profile 数据、再据此选择最优 lowering。绑在 LOAD 上就做不到。

2. **Policy 迭代代价高**。每次改 policy 都要 re-load + re-verify。Verification 是 O(n) 甚至 O(n^2) 的昂贵操作；re-JIT 是 O(n) 且通常很快。

3. **无法对运行中程序做 A/B testing**。一个 XDP 程序已经 attach 并处理流量了，你想试试新 policy——v3 下必须重新加载、重新 attach。v4 下只需 re-JIT，程序 fd 不变，attachment 不变。

4. **正交性**。验证和 JIT 优化是正交的关注点。验证确保安全性，JIT 优化追求性能。把它们绑在一个 syscall 里是混淆关注点。

5. **Security 模型更清晰**。程序已经过验证。Re-JIT 只改变 native code emission，不改变 BPF 语义。`xlated_prog_len` 不变这个不变量天然成立。安全性论证更简单。

### 2.3 论文故事线中的位置

完整故事线：

```
Characterization → 差距在 backend lowering（不是 bytecode）
                 → bytecode 优化器（K2/Merlin/EPSO）无法触及
                 → 部分 backend 决策的 profitability 依赖部署环境

v4 Framework   → 分离验证和 JIT 优化
               → userspace 直接指定 native instruction selection
               → load → profile → apply policy → re-JIT → measure → iterate
               → Kernel 只做 legality gating
```

这比 v3 更直接地回答了"为什么需要 userspace 控制"：因为 instruction selection 的最优解依赖运行时信息和部署上下文，而这些信息只有 userspace 有。

---

## 3. 系统架构

### 3.1 总览

```text
┌─────────────────────────────────────────────────┐
│  Userspace Policy Plane                         │
│                                                 │
│  1. 分析已加载程序的 BPF 指令流                    │
│  2. 识别可优化 site（pattern matching）            │
│  3. 根据 CPU/workload/profile 选择具体 native 指令 │
│  4. 构建 policy blob（flat rule list）            │
│  5. 调用 BPF_PROG_JIT_RECOMPILE(prog_fd, blob)  │
│  6. 测量效果 → 迭代                               │
└──────────────────┬──────────────────────────────┘
                   │
      BPF_PROG_JIT_RECOMPILE(prog_fd, policy_fd)
                   │
┌──────────────────▼──────────────────────────────┐
│  Kernel Legality Plane                          │
│                                                 │
│  1. 验证 prog_fd 有效且已验证                      │
│  2. 解析 policy blob + digest 绑定                │
│  3. 逐条 rule 验证：                              │
│     - BPF 指令模式匹配                            │
│     - CPU feature gating                        │
│     - 结构约束（直线段、无副作用等）                  │
│  4. 构建 validated rule set                      │
│  5. 触发 re-JIT（hot-swap native code）           │
│  6. 原子切换 jited_image                          │
└─────────────────────────────────────────────────┘
```

### 3.2 生命周期

```text
Phase 1: 正常加载
  BPF_PROG_LOAD → verify → stock JIT → attach → 运行

Phase 2: 收集 profile（可选）
  perf_event / bpf_perf_event / external profiler → 识别 hot path

Phase 3: 应用优化 policy
  BPF_PROG_JIT_RECOMPILE(prog_fd, policy_fd) → 验证 rules → re-JIT → atomic swap

Phase 4: 测量 + 迭代
  测量改善 → 如果不满意 → 修改 policy → 再次 BPF_PROG_JIT_RECOMPILE
  或者：BPF_PROG_JIT_RECOMPILE(prog_fd, NULL) → 回退到 stock JIT
```

### 3.3 安全模型

为什么 post-load re-JIT 是安全的：

1. **程序已经过验证**。`BPF_PROG_LOAD` 时 verifier 已证明程序安全。Re-JIT 不改变 BPF 指令流，不需要重新验证。

2. **`xlated_prog_len` 不变**。这是硬不变量。Re-JIT 只影响 `jited_prog_len`。

3. **Digest 绑定**。Policy blob 包含 `prog_tag`（BPF 指令流的 SHA hash），re-JIT 时验证 tag 匹配。如果程序被 constant blinding 修改了 BPF 流，则 reject 整个 policy（与 v3 一致）。

4. **Native emission 来自 kernel 代码**。Userspace 不上传机器码。它只指定"在这个位置用 cmovcc 而不是 jcc+mov"。实际的 native byte emission 仍然由 kernel 的 emitter 函数产生。

5. **Fail-closed**。任何 rule 验证失败，该 site 回退到 stock emission。所有 rule 都失败，程序继续用 stock JIT image 运行，没有中断。

6. **原子切换**。Re-JIT 产生新 image 后原子替换旧 image（与现有 kernel JIT 的 `bpf_jit_binary_pack_finalize()` 机制一致）。运行中的 CPU 看到的要么是旧 image 要么是新 image，不会看到半成品。

7. **权限要求**。`BPF_PROG_JIT_RECOMPILE` 需要 `CAP_BPF`（或 `CAP_SYS_ADMIN`），与 `BPF_PROG_LOAD` 相同权限级别。

---

## 4. `BPF_PROG_JIT_RECOMPILE` 接口设计

### 4.1 Syscall 接口

```c
/* bpf() syscall 新增 subcommand */
#define BPF_PROG_JIT_RECOMPILE  42  /* 具体编号 POC 阶段不重要 */

union bpf_attr {
    struct {  /* BPF_PROG_JIT_RECOMPILE */
        __u32 prog_fd;        /* 已加载程序的 fd */
        __u32 policy_fd;      /* sealed memfd，包含 policy blob；0 = 回退到 stock JIT */
        __u32 flags;          /* 预留 */
        __u32 log_level;      /* 0=silent, 1=reject only, 2=all */
        __aligned_u64 log_buf;
        __u32 log_size;
    } jit_recompile;
};
```

当 `policy_fd == 0` 时，执行 stock re-JIT（回退到默认 emission），这给了 userspace 一个简单的"撤销"机制。

### 4.2 Policy Blob 格式

```c
#define BPF_JIT_POLICY_MAGIC   0x4A495450  /* "JITP" */
#define BPF_JIT_POLICY_VERSION 1

struct bpf_jit_policy_hdr {
    __u32 magic;
    __u16 version;
    __u16 hdr_len;           /* sizeof(this struct) */
    __u32 total_len;         /* 整个 blob 的大小 */
    __u32 rule_cnt;          /* rule 数量 */
    __u32 insn_cnt;          /* 绑定的 BPF 程序 insn_cnt */
    __u8  prog_tag[8];       /* BPF_TAG_SIZE, 绑定到程序 digest */
    __u16 arch_id;           /* BPF_JIT_ARCH_X86_64 = 1, ARM64 = 2 */
    __u16 flags;             /* 预留 */
};

struct bpf_jit_rewrite_rule {
    __u32 site_start;        /* BPF 指令偏移 (orig_idx) */
    __u16 site_len;          /* 被替换的 BPF 指令数 */
    __u16 rule_kind;         /* enum bpf_jit_rule_kind */
    __u16 native_choice;     /* enum，指定用哪种 native emission */
    __u16 priority;          /* 重叠时高优先级胜出 */
    __u64 cpu_features_required;  /* 所需 CPU feature bits */
    __u32 payload_off;       /* rule-specific payload 在 blob 中的偏移 */
    __u16 payload_len;
    __u16 reserved;
};
```

### 4.3 Rule Kind 与 Native Choice

这是 v4 与 v3 的关键差异。v3 用 family + alt_id 间接指定；v4 直接说"用什么指令"。

```c
enum bpf_jit_rule_kind {
    /* 条件选择：jcc+mov diamond/compact → 指定 native lowering */
    BPF_JIT_RK_COND_SELECT     = 1,
    /* 地址计算融合：mov+shl+add → 指定 native lowering */
    BPF_JIT_RK_ADDR_CALC       = 2,
    /* 旋转融合：shl+shr+or → 指定 native lowering */
    BPF_JIT_RK_ROTATE          = 3,
    /* 宽内存访问：byte ladder → 指定 native lowering */
    BPF_JIT_RK_WIDE_MEM        = 4,
};

/* COND_SELECT 的 native_choice 值 */
enum bpf_jit_select_native {
    BPF_JIT_SEL_CMOVCC   = 1,   /* x86: cmp + cmovcc */
    BPF_JIT_SEL_BRANCH   = 2,   /* x86: cmp + jcc + mov (stock) */
    BPF_JIT_SEL_CSEL     = 3,   /* arm64: cmp + csel */
    BPF_JIT_SEL_CBRANCH  = 4,   /* arm64: cmp + b.cond + mov (stock) */
};

/* ADDR_CALC 的 native_choice 值 */
enum bpf_jit_addr_native {
    BPF_JIT_ADDR_LEA     = 1,   /* x86: lea [base + index*scale + disp] */
    BPF_JIT_ADDR_SEPARATE = 2,  /* x86: mov + shl + add (stock) */
    BPF_JIT_ADDR_ADD_SHIFT = 3, /* arm64: add (shifted register) */
};

/* ROTATE 的 native_choice 值 */
enum bpf_jit_rotate_native {
    BPF_JIT_ROT_ROR      = 1,   /* x86: ror */
    BPF_JIT_ROT_RORX     = 2,   /* x86: rorx (BMI2, non-destructive) */
    BPF_JIT_ROT_ROR_ARM  = 3,   /* arm64: ror */
    BPF_JIT_ROT_EXTR     = 4,   /* arm64: extr */
};

/* WIDE_MEM 的 native_choice 值 */
enum bpf_jit_wide_mem_native {
    BPF_JIT_WMEM_WIDE_LOAD  = 1,  /* x86: mov + shift/mask extract */
    BPF_JIT_WMEM_BYTE_LOADS = 2,  /* x86: 多个 movzx (stock) */
    BPF_JIT_WMEM_LDR_UBFX   = 3,  /* arm64: ldr + ubfx */
};
```

**关键区别**：v3 的 userspace 说"请求 SELECT family"，kernel 从预注册 alt 中选一个。v4 的 userspace 直接说"用 cmovcc"，kernel 只验证 `CPUID.CMOV` 是否存在。

这更直接、更透明、更符合"userspace 控制 backend policy"的论文 thesis。

### 4.4 Rule-Specific Payload

每种 rule_kind 有对应的 payload 结构：

```c
/* COND_SELECT payload */
struct bpf_jit_select_payload {
    __u8  shape;       /* compact=1, diamond=2 */
    __u8  cond_code;   /* BPF_JEQ, BPF_JGT, etc. */
    __u8  cond_src;    /* BPF_K or BPF_X */
    __u8  dst_reg;
    __u8  true_src_kind;   /* IMM or REG */
    __u8  false_src_kind;
    __u16 reserved;
    __s32 true_imm;
    __s32 false_imm;
};

/* ADDR_CALC payload */
struct bpf_jit_addr_payload {
    __u8  base_reg;
    __u8  index_reg;
    __u8  dst_reg;
    __u8  scale_log2;   /* 0,1,2,3 */
    __s32 disp;
};

/* ROTATE payload */
struct bpf_jit_rotate_payload {
    __u8  dst_reg;
    __u8  src_reg;
    __u8  direction;    /* ROL=1, ROR=2 */
    __u8  width;        /* 32 or 64 */
    __u8  shift_imm;
    __u8  reserved[3];
};

/* WIDE_MEM payload */
struct bpf_jit_wide_mem_payload {
    __u8  dst_reg;
    __u8  base_reg;
    __u8  mem_class;    /* STACK=1, MAP_VALUE=2 */
    __u8  total_width;  /* 2, 4, or 8 bytes */
    __s16 base_off;     /* 最低地址的 offset */
    __u8  part_cnt;     /* byte load 数量 */
    __u8  reserved;
};
```

---

## 5. Kernel 验证流程

### 5.1 `BPF_PROG_JIT_RECOMPILE` 处理流程

```c
static int bpf_prog_jit_recompile(union bpf_attr *attr)
{
    struct bpf_prog *prog;
    struct bpf_jit_policy *policy;
    int err;

    /* 1. 权限检查 */
    if (!capable(CAP_BPF))
        return -EPERM;

    /* 2. 获取已加载程序 */
    prog = bpf_prog_get(attr->jit_recompile.prog_fd);
    if (IS_ERR(prog))
        return PTR_ERR(prog);

    /* 3. stock JIT 回退 */
    if (attr->jit_recompile.policy_fd == 0) {
        err = bpf_jit_recompile_stock(prog);
        goto out;
    }

    /* 4. 解析 policy blob */
    policy = bpf_jit_parse_policy(attr->jit_recompile.policy_fd);
    if (IS_ERR(policy)) {
        err = PTR_ERR(policy);
        goto out;
    }

    /* 5. Digest 绑定 */
    err = bpf_jit_verify_digest(prog, policy);
    if (err)
        goto free_policy;

    /* 6. Constant blinding 检查 */
    if (prog->jit_requested && prog->aux->blinding_requested) {
        err = -ENOTSUP;   /* MVP 不支持 blinded 程序 */
        goto free_policy;
    }

    /* 7. 逐条验证 rules */
    err = bpf_jit_validate_rules(prog, policy);
    if (err)
        goto free_policy;

    /* 8. 触发 re-JIT */
    err = bpf_jit_recompile_with_policy(prog, policy);

free_policy:
    bpf_jit_free_policy(policy);
out:
    bpf_prog_put(prog);
    return err;
}
```

### 5.2 Per-Rule 验证

每条 rule 的验证分三层，由简到深：

```text
Layer 1: 结构验证（通用，所有 rule 共享）
  - site_start + site_len 在程序范围内
  - site 在单一 subprog 内
  - rule_kind 是已知值
  - payload 偏移和长度合法
  - CPU feature bits 满足

Layer 2: 模式验证（通用，所有 rule 共享）
  - site 是直线段（无 interior branch edge）
  - site 内无 helper call / store / atomic / side effect
  - site 内无 PROBE_MEM access（MVP）

Layer 3: Kind-specific 验证（每种 rule_kind ~50-100 LOC）
  - COND_SELECT: 验证 diamond/compact 形状、mov arms、单一 liveout
  - ADDR_CALC:   验证 scale ∈ {1,2,4,8}、disp 范围合法
  - ROTATE:      验证两侧 shift 互补 (a + b == width)
  - WIDE_MEM:    验证 contiguous byte ladder、same base、mem class
```

验证结果是 per-rule 的 accept/reject。Reject 不会导致整个 re-JIT 失败——被 reject 的 site 保持 stock emission。

### 5.3 CPU Feature Gating

```c
struct bpf_jit_cpu_features {
    u64 bits;
};

/* x86 feature bits */
#define BPF_JIT_X86_CMOV     (1ULL << 0)
#define BPF_JIT_X86_BMI2     (1ULL << 1)
#define BPF_JIT_X86_AVX      (1ULL << 2)
/* 按需扩展 */

static bool bpf_jit_check_cpu_features(u64 required)
{
    u64 available = bpf_jit_get_cpu_features();
    return (required & available) == required;
}
```

Userspace 在每条 rule 中声明 `cpu_features_required`。Kernel 简单检查当前 CPU 是否满足。这是整个安全模型中最直观的部分——它就是 CPUID 检查。

---

## 6. Re-JIT 流程

### 6.1 核心流程

```c
static int bpf_jit_recompile_with_policy(struct bpf_prog *prog,
                                          struct bpf_jit_policy *policy)
{
    struct bpf_jit_rule_set *ruleset;
    void *new_image;

    /* 1. 从 validated rules 构建 rule_set（按 site_start 排序的 lookup table） */
    ruleset = bpf_jit_build_ruleset(policy);

    /* 2. 调用 arch-specific JIT，传入 ruleset */
    new_image = bpf_int_jit_compile_with_rules(prog, ruleset);
    if (IS_ERR(new_image))
        return PTR_ERR(new_image);

    /* 3. 原子替换 jited image */
    bpf_jit_swap_image(prog, new_image);

    /* 4. 释放旧 image（RCU 延迟） */
    bpf_jit_free_old_image_rcu(prog);

    return 0;
}
```

### 6.2 JIT 主循环中的 Rule Dispatch

在 `do_jit()` 主循环中，rule dispatch 在每条 BPF 指令处理前插入：

```c
/* 在 do_jit() 的主循环顶部 */
for (i = 1; i <= insn_cnt; i++, insn++) {
    u32 bpf_idx = i - 1;
    const struct bpf_jit_rewrite_rule *rule;
    int emit_len;

    /* 查找是否有 rule 覆盖当前位置 */
    rule = bpf_jit_lookup_rule(ruleset, bpf_idx);
    if (rule) {
        emit_len = bpf_jit_emit_rule_x86(prog, &ctx, rule, addrs, bpf_idx);
        if (emit_len >= 0) {
            /* 成功：跳过 rule 覆盖的 BPF 指令 */
            bpf_jit_commit_addrs(addrs, bpf_idx, rule->site_len, emit_len);
            i += rule->site_len - 1;
            insn += rule->site_len - 1;
            continue;
        }
        /* 失败：fallback 到 stock emission */
    }

    /* stock emission（原有 switch-case） */
    ...
}
```

`bpf_jit_lookup_rule()` 是 O(1) 查找——ruleset 按 site_start 排序，用位图或直接数组索引。

### 6.3 Atomic Image Swap

Re-JIT 不中断运行中的程序。机制利用 kernel 已有的 `bpf_jit_binary_pack_*()` 基础设施：

1. 分配新 image buffer
2. 在新 buffer 上执行带 policy 的 JIT
3. 原子更新 `prog->bpf_func` 指针
4. 通过 RCU 回收旧 image

这与 kernel 现有的 JIT image 更新机制一致（参考 `bpf_jit_free()` 和 `bpf_prog_pack_free()`）。

---

## 7. 与 v3 的详细对比

### 7.1 简化了什么

| v3 组件 | v4 处理 | 理由 |
|---------|---------|------|
| Family 抽象 | 扁平 rule_kind | POC 不需要 family/sub-family 层次 |
| Alt table + emitter registry | native_choice 枚举 | 直接指定，不需要间接查找 |
| Plan system + plan materialization | Validated rule set | 扁平数据结构，不需要 plan/private payload 分层 |
| Region dispatcher + start_map | 简单 O(1) rule lookup | 数组索引即可 |
| Overlap arbitration + budget system | 简单 priority 排序 | POC 不需要 budget system |
| Constant blinding 复杂处理 | 直接 reject blinded prog | 与 v3 策略一致，但表述更简单 |
| 5 步渐进实现路径 | 一步到位 | POC 不需要 v2 compat shim |

### 7.2 强化了什么

| 能力 | v3 | v4 |
|------|----|----|
| Userspace 控制粒度 | 从预注册 alt 中选择 | 直接指定 native instruction |
| Policy 迭代 | 需要 re-load | Post-load re-JIT，可反复迭代 |
| Runtime PGO | 不支持 | load → profile → re-JIT → measure |
| Policy 回退 | 需要 re-load stock 版本 | `BPF_PROG_JIT_RECOMPILE(fd, NULL)` |
| Dynamic A/B | 需要两个程序实例 | 同一个 prog_fd 切换 policy |
| 论文故事 | "框架" | "post-load iterative instruction selection" |

### 7.3 不变量保持一致

两者共享的核心不变量：

1. `xlated_prog_len` 不变——BPF 指令流不被修改
2. Userspace 不上传 raw machine code——kernel 的 emitter 函数产生 native bytes
3. Fail-closed——任何 rule 失败回退到 stock emission
4. Per-site granularity——一个 rule 失败不影响其他 rule
5. Digest 绑定——policy 绑定到特定 BPF 程序的 `prog_tag`
6. 权限要求——`CAP_BPF`

---

## 8. 4 个具体 Rule（POC 实现）

### 8.1 COND_SELECT：cmovcc vs branch

**论文定位**：最强的 policy-sensitive 证据。Paper 数据：31 vs 0 cmov；no-cmov ablation 显示收益不单调。

**Userspace 指定**：`native_choice = BPF_JIT_SEL_CMOVCC`

**Kernel 验证**：
- 检查 diamond/compact 形状
- 检查 mov arms 是 simple move
- 检查 CPU 支持 cmov（x86 上几乎总是支持）

**为什么 native_choice 重要**：cmov 在高度可预测的分支上比 branch 更慢（POC v2 已验证：cmov_select 13.2% 更慢）。Userspace 可以根据 workload profile 决定哪些 site 用 cmov、哪些保持 branch。这恰恰是 `BPF_JIT_SEL_BRANCH` 选项存在的理由——it's not always better to use cmov。

**实现量**：~150 LOC（从 POC v2 迁移 + 适配新接口）

### 8.2 ADDR_CALC：lea 融合

**论文定位**：extensibility 证据。

**Userspace 指定**：`native_choice = BPF_JIT_ADDR_LEA`

**Kernel 验证**：
- 检查 `scale ∈ {1,2,4,8}`
- 检查 displacement 在 32-bit 范围内
- 检查指令序列是 `mov+shl+add` 或 `shl+add` 形状

**实现量**：~100 LOC

### 8.3 ROTATE：旋转融合

**论文定位**：extensibility + CPU feature sensitivity 证据（rorx 需要 BMI2）。

**Userspace 指定**：
- `native_choice = BPF_JIT_ROT_ROR`（通用）
- `native_choice = BPF_JIT_ROT_RORX`（BMI2 CPU）

**Kernel 验证**：
- 检查两侧 shift 互补
- 如果选择 rorx，检查 `CPUID.BMI2`

**为什么这是好例子**：`rorx` vs `ror` 就是典型的 "userspace 指定 native instruction" 场景。
- `rorx`：VEX 编码，non-destructive（不需要 mov 保存原值），需要 BMI2
- `ror`：legacy 编码，destructive（需要 mov 保存原值），universal
- 选择取决于 CPU 代际和上下文中的寄存器压力

**实现量**：~100 LOC

### 8.4 WIDE_MEM：宽内存访问

**论文定位**：最大 backend gap 的 JIT-only 修复（50.7% surplus, 2.24x penalty）。

**Userspace 指定**：`native_choice = BPF_JIT_WMEM_WIDE_LOAD`

**Kernel 验证**：
- 检查 contiguous byte ladder 形状
- 检查 same base register
- 检查 mem_class ∈ {STACK, MAP_VALUE}
- 检查 total_width ∈ {2, 4, 8}
- 排除 PROBE_MEM

**为什么这依然是 JIT-level**：v4 与 v3 一致——不改 BPF 指令流，只在 native emission 时把多个 byte load 合并为一个 wide load + extract。区别于 POC v1 的 verifier-side BPF rewrite。

**实现量**：~200 LOC

---

## 9. POC 实现计划

### 9.1 总量估算

| 组件 | LOC 估算 | 说明 |
|------|---------|------|
| `BPF_PROG_JIT_RECOMPILE` syscall plumbing | 150-200 | 新 subcommand + attr parsing |
| Policy blob parser + digest bind | 100-150 | header + rule parsing |
| Per-rule generic validation | 100-150 | structure + pattern checks |
| COND_SELECT validator + x86 emitter | 120-180 | 从 POC v2 迁移 |
| ADDR_CALC validator + x86 emitter | 80-120 | |
| ROTATE validator + x86 emitter | 80-120 | |
| WIDE_MEM validator + x86 emitter | 150-200 | |
| Rule dispatch in do_jit() | 80-120 | lookup + fallback |
| Image swap + RCU | 50-80 | 复用已有机制 |
| **Total** | **910-1320** | |

对比 v3 的 ~2000 LOC 核心 + ~800 LOC hardening，v4 总量约为 v3 的 50-65%。

### 9.2 实现步骤

**Step 1：Re-JIT 骨架**（~300 LOC）
- `BPF_PROG_JIT_RECOMPILE` subcommand
- Policy blob parsing + digest binding
- Stock re-JIT 回退路径
- Empty rule set → 验证 image swap 机制正确

**Step 2：COND_SELECT**（~200 LOC）
- 从 POC v2 迁移 cmov_select emitter
- 适配新 rule 格式
- 端到端验证：cmov_select benchmark，`xlated_prog_len` 不变

**Step 3：WIDE_MEM + ROTATE + ADDR_CALC**（~400 LOC）
- 三个新 rule kind
- 验证框架的泛化能力

**Step 4：Userspace 工具**（Python 脚本）
- 分析 BPF 程序、识别 site、生成 policy blob
- 调用 `BPF_PROG_JIT_RECOMPILE`
- 测量效果

### 9.3 Userspace 工具

```python
# 概念性伪代码
def optimize_bpf_program(prog_fd, cpu_profile, workload_profile):
    # 1. 获取 BPF 指令流
    insns = bpf_get_prog_info(prog_fd).xlated_prog_insn

    # 2. Pattern matching：识别可优化 site
    sites = []
    sites += find_cond_select_sites(insns)
    sites += find_rotate_sites(insns)
    sites += find_addr_calc_sites(insns)
    sites += find_wide_mem_sites(insns)

    # 3. Policy 决策
    rules = []
    for site in sites:
        choice = select_native_instruction(
            site, cpu_profile, workload_profile
        )
        rules.append(make_rule(site, choice))

    # 4. 构建 policy blob
    blob = build_policy_blob(prog_fd, rules)

    # 5. 应用
    bpf_prog_jit_recompile(prog_fd, blob)

    # 6. 测量
    perf_before = measure_program(prog_fd)
    # ... 对比 ...
```

---

## 10. PGO 流程示例

这是 v4 最强的独有能力——post-load iterative optimization。

```text
1. BPF_PROG_LOAD(xdp_prog.o) → prog_fd
   → verifier pass → stock JIT → attach to eth0 → 开始处理流量

2. 收集 profile（30 秒）
   → perf record -e branches:u -p $(pidof bpf_prog) ...
   → 发现 site@insn[42-47] 的 branch 95% taken

3. 生成 policy v1
   → site[42-47]: COND_SELECT, native=CMOVCC  # 高度可预测 → cmov 可能不好
   → site[100-107]: WIDE_MEM, native=WIDE_LOAD
   → site[55-58]: ROTATE, native=RORX

4. BPF_PROG_JIT_RECOMPILE(prog_fd, policy_v1)
   → kernel 验证 → re-JIT → atomic swap → 继续运行

5. 测量 policy v1（30 秒）
   → exec_ns 降低 12%
   → 但 site[42-47] 的 cmov 使该路径变慢 8%

6. 修改 policy → policy v2
   → site[42-47]: COND_SELECT, native=BRANCH  # 改回 branch
   → 其余保持

7. BPF_PROG_JIT_RECOMPILE(prog_fd, policy_v2)
   → 无需 re-load、无需 re-verify → re-JIT → atomic swap

8. 测量 policy v2
   → exec_ns 降低 15%（比 v1 好 3%）
   → 收敛
```

这个流程完全不可能在 v3 中实现——v3 每次改 policy 都需要 re-load 程序。

---

## 11. 论文贡献声明

v4 使论文贡献更清晰：

**系统贡献**：`BPF_PROG_JIT_RECOMPILE`——一个 post-load、可迭代的 native instruction selection policy 接口。

**设计原则**：
1. Mechanism/policy 分离：kernel 验证指令合法性（CPUID gating），userspace 选择具体指令
2. 验证和优化正交：验证在 LOAD 时一次性完成，优化可以反复迭代
3. Fail-closed：任何 rule 失败不影响程序运行

**独有能力**（v3 没有的）：
1. Runtime PGO：load → profile → optimize → measure → iterate
2. Dynamic A/B：同一程序在运行中切换 policy
3. 零验证开销的 policy 迭代

**Policy-sensitive 证据**：
- cmov_select 在可预测分支上更慢（POC v2 数据）
- rorx vs ror 取决于 CPU 代际（BMI2）
- wide_load 的收益取决于 cache line 行为和 alignment
- branch layout 的收益取决于输入分布（characterization 数据：44.6% 差异）

**Falsification condition**（与 v3 一致）：如果 fixed kernel heuristics 在所有 CPU/workload/program 上恢复同等收益，正确结论是做 kernel peepholes。v4 的 post-load re-JIT 能力（runtime PGO、dynamic A/B）是 fixed heuristics 无法替代的独有价值。

---

## 12. 与 Existing Work 的差异

| 系统 | 优化层 | Post-load 可迭代 | Native instruction selection | 部署可控 |
|------|--------|:---:|:---:|:---:|
| K2 (SIGCOMM'21) | BPF bytecode | -- | -- | -- |
| Merlin (ASPLOS'24) | LLVM IR + BPF | -- | -- | -- |
| EPSO (ASE'25) | BPF bytecode | -- | -- | -- |
| GCC/LLVM | native backend | -- | Yes（内部） | -- |
| **v4** | **BPF JIT backend** | **Yes** | **Yes（userspace 控制）** | **Yes** |

v4 的独特定位：**唯一一个让部署方（而非编译器开发者）控制 native instruction selection 的 BPF JIT 框架**。

---

## 13. 已知限制与未来工作

### 13.1 POC 阶段明确不做的事

1. **Constant blinding 支持**——blinded 程序直接 reject。未来可以通过 blinding remap table 支持。
2. **arm64 实现**——POC 只做 x86。但 enum 和接口预留了 arm64 值。
3. **自动 policy 生成**——POC 阶段 userspace 工具是手动/半自动的。未来可以做 llvmbpf 驱动的自动 policy generator。
4. **Multi-subprog 程序**——POC 假设单一 subprog。扩展到 multi-subprog 只需要在 rule 中加 `subprog_idx` 字段。
5. **Code-size budget**——POC 不做 budget 管理。如果需要，加一个 `max_extra_bytes` 字段即可。
6. **UAPI 稳定性**——这是 POC，enum 值和结构体布局都会变。

### 13.2 从 POC 到 Production 的路径

1. 稳定 UAPI（enum 值固定、结构体版本化）
2. 支持 constant blinding
3. arm64 实现
4. 自动 policy generator（llvmbpf cross-compile + diff analysis）
5. Multi-subprog 支持
6. Code-size budget
7. Kernel selftests + fuzzing

### 13.3 风险

1. **`bpf_jit_binary_pack_*()` 并发安全**——re-JIT 时其他 CPU 可能正在执行旧 image。需要 RCU + text_poke 机制，但 kernel 已有类似基础设施（参考 `bpf_prog_pack` 和 `text_poke_bp()`）。
2. **JIT convergence loop**——kernel JIT 用 fixed-point iteration 确定 image 大小。Re-JIT 时 rule 改变了 emission 长度，可能需要更多 pass 收敛。但这是已有 JIT 机制的一部分，不是新问题。
3. **Feature gating 完整性**——如果遗漏某个 CPU feature check，可能生成非法指令。但这与 kernel 现有的 alternative patching 系统面临的风险相同，且验证逻辑集中在一处。

---

## 14. 总结

v4 的两个核心创新——**machine-code level userspace policy** 和 **post-load re-JIT**——直接强化了论文的核心 thesis。

v3 构建了一个精致的可扩展框架，但它的核心矛盾是：框架越通用、间接层越多，反而越看不出"为什么这件事只有 userspace 能做"。v4 砍掉了间接层，让答案变得直接：

> Userspace 直接指定 native instruction（cmovcc vs branch, rorx vs ror, lea vs mov+shl+add），因为最优选择取决于 CPU 微架构、workload profile 和部署上下文。Kernel 只验证所选指令在当前 CPU 上合法。而且这个选择可以在程序运行中反复迭代——load → profile → re-JIT → measure → iterate——不需要重新验证程序。

这就是论文要讲的故事。v4 是讲这个故事的最简设计。
