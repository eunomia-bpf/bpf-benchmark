# BpfReJIT 内核修改详细分析

本文档详细分析 `vendor/linux-framework` (分支 `jit-directive-v5`) 相对于上游 Linux 7.0-rc2 (`master`) 所做的全部修改。修改总量约 6759 行新增、194 行删除，涉及 13 个文件。

---

## 目录

1. [修改文件总览](#1-修改文件总览)
2. [UAPI 扩展：include/uapi/linux/bpf.h](#2-uapi-扩展)
3. [内核头文件：include/linux/bpf.h](#3-内核头文件)
4. [Directive 框架头文件：include/linux/bpf_jit_directives.h](#4-directive-框架头文件)
5. [Tracepoint：include/trace/events/bpf.h](#5-tracepoint)
6. [核心框架：kernel/bpf/jit_directives.c (3708 行)](#6-核心框架)
7. [系统调用入口：kernel/bpf/syscall.c](#7-系统调用入口)
8. [BPF 核心：kernel/bpf/core.c](#8-bpf-核心)
9. [验证器：kernel/bpf/verifier.c](#9-验证器)
10. [x86 JIT 编译器：arch/x86/net/bpf_jit_comp.c (2551 行变更)](#10-x86-jit-编译器)
11. [BPF 异常处理：kernel/bpf/helpers.c](#11-bpf-异常处理)
12. [工具链：tools/ 目录](#12-工具链)
13. [8 个 Canonical Form 详解](#13-canonical-form-详解)
14. [Recompile 工作流](#14-recompile-工作流)
15. [Policy/Directive 格式与解析](#15-policy-格式与解析)
16. [安全模型总结](#16-安全模型总结)

---

## 1. 修改文件总览

| 文件 | 变更量 | 用途 |
|------|--------|------|
| `arch/x86/net/bpf_jit_comp.c` | +2551/-194 | x86 JIT 编译器：8 种 canonical form emitter + recompile 生命周期 |
| `include/linux/bpf.h` | +33 | `bpf_prog_aux` 扩展、`bpf_ksym` 扩展、辅助函数 |
| `include/linux/bpf_jit_directives.h` | +184（新文件） | directive 框架内核内部 API |
| `include/trace/events/bpf.h` | +85（新文件） | recompile 相关 tracepoint |
| `include/uapi/linux/bpf.h` | +258 | 新 syscall、policy blob 格式、canonical form 枚举 |
| `kernel/bpf/Makefile` | +1 | 编译 `jit_directives.o` |
| `kernel/bpf/core.c` | +112/-30 | kallsyms 替换、异常表查找重构 |
| `kernel/bpf/helpers.c` | +6/-2 | `bpf_throw` 安全修复 |
| `kernel/bpf/jit_directives.c` | +3708（新文件） | **核心**：policy 解析、规则验证、recompile 协调 |
| `kernel/bpf/syscall.c` | +5 | `BPF_PROG_JIT_RECOMPILE` 命令注册 |
| `kernel/bpf/verifier.c` | +2 | `orig_idx` 保持（指令膨胀时保留原始偏移） |
| `tools/bpf/bpftool/prog.c` | +4 | bpftool 显示 `recompile_count` |
| `tools/include/uapi/linux/bpf.h` | +4 | 工具链 UAPI 同步 |

---

## 2. UAPI 扩展

文件：`include/uapi/linux/bpf.h`

### 2.1 新系统调用命令

```c
enum bpf_cmd {
    ...
    BPF_PROG_JIT_RECOMPILE,   // 新增
    __MAX_BPF_CMD,
};
```

`BPF_PROG_JIT_RECOMPILE` 是整个 BpfReJIT 框架的用户态入口。用户态通过这个命令将 policy blob 附加到已加载的 BPF 程序上，并触发 re-JIT。

### 2.2 Syscall 参数

```c
union bpf_attr {
    ...
    struct {
        __u32       prog_fd;    // 目标 BPF 程序的文件描述符
        __s32       policy_fd;  // sealed memfd，包含 policy blob；0 表示 stock re-JIT
        __u32       flags;      // BPF_F_RECOMPILE_ROLLBACK 等
        __u32       log_level;  // 日志级别
        __u32       log_size;   // 日志缓冲区大小
        __aligned_u64 log_buf;  // 用户态日志缓冲区
    } jit_recompile;
};
```

- `policy_fd = 0` 时执行 stock re-JIT（清除之前的 policy，恢复标准 emission）
- `BPF_F_RECOMPILE_ROLLBACK` 标志：当 recompile 失败时保留旧的 JIT image 和 policy

### 2.3 Policy Blob 格式

Policy blob 的头部结构：

```c
#define BPF_JIT_POLICY_MAGIC    0x4A495450U  // "JITP"
#define BPF_JIT_POLICY_FORMAT_VERSION  2

struct bpf_jit_policy_hdr {
    __u32 magic;          // 必须是 "JITP"
    __u16 version;        // 必须是 2
    __u16 hdr_len;        // sizeof(this struct)
    __u32 total_len;      // 整个 blob 大小
    __u32 rule_cnt;       // 规则数量
    __u32 insn_cnt;       // 绑定的 BPF 程序指令数（digest binding）
    __u8  prog_tag[8];    // 程序 tag，用于 digest binding 验证
    __u16 arch_id;        // BPF_JIT_ARCH_X86_64 = 1
    __u16 flags;          // 保留
};
```

每条规则的结构：

```c
struct bpf_jit_rewrite_rule_v2 {
    __u32 site_start;           // BPF 指令偏移
    __u32 cpu_features_required; // 需要的 CPU 特性位
    __u16 site_len;             // 覆盖的 BPF 指令数
    __u16 rule_kind;            // BPF_JIT_RK_PATTERN (= 6)
    __u16 canonical_form;       // enum bpf_jit_canonical_form
    __u16 native_choice;        // 选择哪种 native emission
    __u16 priority;             // 重叠时高优先级优先
    __u16 pattern_count;        // pattern 指令数
    __u16 constraint_count;     // 约束数
    __u16 binding_count;        // canonical binding 数
    __u16 rule_len;             // 本条规则的总字节数
    __u16 reserved;
};
```

### 2.4 八个 Canonical Form 枚举

```c
enum bpf_jit_canonical_form {
    BPF_JIT_CF_ROTATE         = 1,  // 循环移位
    BPF_JIT_CF_WIDE_MEM       = 2,  // 字节重组 -> 宽加载
    BPF_JIT_CF_ADDR_CALC      = 3,  // 地址计算 -> LEA
    BPF_JIT_CF_COND_SELECT    = 4,  // 条件选择 -> CMOV
    BPF_JIT_CF_BITFIELD_EXTRACT = 5, // 位域提取 -> BEXTR
    BPF_JIT_CF_ZERO_EXT_ELIDE = 6,  // 零扩展消除
    BPF_JIT_CF_ENDIAN_FUSION  = 7,  // 字节序融合 -> MOVBE
    BPF_JIT_CF_BRANCH_FLIP    = 8,  // 分支翻转
};
```

每个 form 都有对应的 native_choice 枚举和参数枚举，详见第 13 节。

### 2.5 声明式 Pattern 匹配基础设施

UAPI 定义了完整的声明式 pattern 匹配 DSL：

- **`bpf_jit_pattern_insn`**：描述一条 BPF 指令的 pattern，包含 opcode 匹配、寄存器/立即数绑定变量
- **`bpf_jit_pattern_constraint`**：7 种约束类型（EQUAL、SUM_CONST、IMM_RANGE、NOT_ZERO、MASK_BITS、DIFF_CONST、NOT_EQUAL）
- **`bpf_jit_binding`**：将 pattern 变量映射到 canonical 参数

### 2.6 CPU Feature 位

```c
#define BPF_JIT_X86_CMOV   (1U << 0)  // CMOV 指令
#define BPF_JIT_X86_BMI2   (1U << 1)  // BMI2 (RORX)
#define BPF_JIT_X86_MOVBE  (1U << 2)  // MOVBE 指令
```

### 2.7 prog_info 扩展

```c
struct bpf_prog_info {
    ...
    __u32 recompile_count;  // 成功 recompile 次数
};
```

---

## 3. 内核头文件

文件：`include/linux/bpf.h`

### 3.1 bpf_ksym 扩展

```c
struct bpf_ksym {
    ...
    struct bpf_prog  *owner;     // 指向拥有者程序（用于 recompile 后 ksym 查找）
    struct exception_table_entry *extable;  // 每个 ksym 自带异常表指针
    u32               num_exentries;        // 异常表条目数
};
```

这些字段是为了在 recompile 期间正确维护 kallsyms 和异常表查找。当 recompile 产生新 JIT image 时，新 image 和旧 image 可能短暂共存（RCU 宽限期），需要让两个 ksym 同时可查找。

### 3.2 bpf_prog_aux 扩展

新增了 15+ 个字段用于 recompile 状态管理：

```c
struct bpf_prog_aux {
    ...
    // Recompile 状态
    bool jit_recompile_active;       // 当前是否正在 recompile
    bool jit_recompile_staged;       // 新 image 是否已 staged
    bool jit_recompile_exception_boundary;
    u32 jit_recompile_fp_start;      // 新 image 的 frame pointer 起始
    u32 jit_recompile_fp_end;
    u32 jit_recompile_jited_len;     // 新 image 长度
    u32 jit_recompile_num_exentries;
    bpf_func_t jit_recompile_bpf_func;  // 新 image 入口
    void __percpu *jit_recompile_priv_stack_ptr;
    struct exception_table_entry *jit_recompile_extable;
    struct mutex jit_recompile_mutex;     // 串行化 recompile 操作
    struct bpf_jit_policy *jit_policy;     // 当前激活的 policy
    struct bpf_jit_recompile_log *jit_recompile_log;
    u32 recompile_count;                   // 成功次数
    u32 jit_recompile_num_applied;         // 本次 applied 的规则数
    ...
    struct bpf_ksym jit_recompile_ksym;   // shadow ksym（过渡期）
};
```

### 3.3 新增辅助函数

```c
void bpf_prog_kallsyms_replace(...);  // 原子替换 kallsyms 条目
static inline struct bpf_prog_aux *bpf_prog_main_aux(const struct bpf_prog *prog);
```

---

## 4. Directive 框架头文件

文件：`include/linux/bpf_jit_directives.h`（新文件，184 行）

定义了内核内部的 directive 框架 API：

### 4.1 核心数据结构

```c
struct bpf_jit_rule {
    u16 rule_kind;          // BPF_JIT_RK_PATTERN
    u16 canonical_form;     // 8 种 form 之一
    u16 native_choice;      // 选择的 native emission 方式
    u16 pattern_count;      // pattern 指令数
    u16 constraint_count;   // 约束数
    u16 binding_count;      // binding 数
    const struct bpf_jit_pattern_insn *pattern;       // 指向 blob 中的 pattern
    const struct bpf_jit_pattern_constraint *constraints; // 约束
    const struct bpf_jit_binding *bindings;               // binding
    struct bpf_jit_canonical_params params;  // 已提取的 canonical 参数
    u32 site_start;         // BPF 指令偏移
    u16 site_len;           // 覆盖的指令数
    u16 flags;              // BPF_JIT_REWRITE_F_ACTIVE
    u16 priority;
    u16 user_index;         // 在 policy 中的原始索引
    u32 cpu_features_required;
};

struct bpf_jit_policy {
    u32 rule_cnt;           // 规则总数
    u32 active_cnt;         // 通过验证的规则数
    void *blob;             // 保留的 blob 数据
    struct bpf_jit_rule rules[];  // 按 site_start 排序
};
```

### 4.2 API 函数

- `bpf_prog_jit_recompile()` — syscall handler
- `bpf_jit_parse_policy()` — 解析 sealed memfd 中的 policy blob
- `bpf_jit_free_policy()` — 释放 policy
- `bpf_jit_rule_lookup()` — O(log n) 二分查找某个 insn_idx 的规则
- `bpf_jit_recompile_commit()` / `bpf_jit_recompile_abort()` — x86 架构相关的 commit/abort

---

## 5. Tracepoint

文件：`include/trace/events/bpf.h`（新文件，85 行）

定义了 3 个 tracepoint：

1. **`bpf_jit_recompile_start`** — recompile 开始时触发，记录 prog_id 和规则数
2. **`bpf_jit_recompile_end`** — recompile 结束时触发，记录 applied 数、耗时、是否成功
3. **`bpf_jit_recompile_rule`** — 每条规则处理时触发，记录 site_insn、family、native_choice、是否 applied

---

## 6. 核心框架：kernel/bpf/jit_directives.c

这是最大的新文件（3708 行），实现了整个 BpfReJIT 框架的核心逻辑。

### 6.1 日志系统 (L29-L217)

```c
struct bpf_jit_recompile_log {
    char __user *ubuf;    // 用户态缓冲区
    char *kbuf;           // 内核态缓冲区
    u32 user_size;
    u32 kernel_size;      // 最大 64KB
    u32 len;
    u32 level;
};
```

提供 `bpf_jit_recompile_prog_log()` 和 `bpf_jit_recompile_rule_log()` 两级日志，最终通过 `copy_to_user` 返回给用户态。每条规则的日志包含 `rule index`、`form`、`site range`。

### 6.2 Rollback 状态管理 (L219-L365)

为了支持失败回滚，框架在 recompile 前保存每个 subprogram 的完整状态：

```c
struct bpf_jit_recompile_prog_state {
    struct bpf_prog *prog;
    bpf_func_t bpf_func;           // 旧 JIT 入口
    void __percpu *priv_stack_ptr;  // 私有栈
    struct exception_table_entry *extable;
    void *jit_data;
    struct bpf_insn *insnsi_copy;   // BPF 指令的深拷贝
    u32 insn_cnt;
    u32 jited_len;
    u32 num_exentries;
    bool jited;
    bool exception_boundary;
};
```

- `bpf_jit_recompile_snapshot()` — 对每个 subprogram 做快照（含指令深拷贝）
- `bpf_jit_recompile_restore()` — 恢复所有状态

### 6.3 Pattern 匹配验证器集合

#### 通用前置检查
- **`bpf_jit_has_interior_edge()`** — 扫描整个程序，检查是否有从 site 外部跳入 site 内部的跳转。这是所有 form 共用的安全检查，因为重写 site 会改变 `addrs[]` 映射，外部跳转会指向错误地址。
- **`bpf_jit_site_has_side_effects()`** — 拒绝包含 helper call 或 store 指令的 site（ENDIAN_FUSION 除外，因为它需要 store）。

#### COND_SELECT 验证 (L480-L591)
识别两种 BPF 指令模式：
1. **Diamond (site_len=4)**: `jcc+2, mov_false, ja+1, mov_true`
2. **Compact (site_len=3)**: `mov_default, jcc+1, mov_override`

验证：跳转偏移正确、两个 MOV 的 dst_reg 相同、宽度一致。

#### WIDE_MEM 验证 (L824-L993)
解析 byte-recompose 模式：多个连续的 `LDX_B` + `LSH` + `OR` 指令组合成宽加载。支持：
- 小端序和大端序
- 2-8 字节宽度
- 验证偏移连续、移位量正确

#### ROTATE 验证 (L995-L1525)
支持 4 种 rotate idiom：
1. **4-insn 经典** (site_len=4): `mov tmp,src; lsh src,N; rsh tmp,W-N; or src,tmp`（及交换序）
2. **5-insn 两拷贝** (site_len=5): `mov tmp,src; rsh tmp,W-N; mov dst,src; lsh dst,N; or dst,tmp`
3. **5-insn 掩码** (site_len=5): `mov tmp,src; and tmp,mask; rsh/lsh; lsh/rsh; or`（32-bit）
4. **6-insn 掩码** (site_len=6): `mov; and; rsh; mov; lsh; or`（32-bit）

#### ADDR_CALC 验证 (L1659-L1749)
识别 `mov dst,idx; lsh64 dst,scale; add64 dst,base` 模式（site_len=3），scale 必须在 1-3 范围内。

#### BITFIELD_EXTRACT 验证 (L1527-L1657)
识别 `[mov dst,src;] rsh dst,shift; and dst,mask` 或 `and; rsh` 序列（site_len=2 或 3）。

#### ZERO_EXT_ELIDE 验证 (L1751-L1806)
识别 `alu32 op; zext/mov64 dst,dst` 模式（site_len=2），其中 zext 是冗余的。

#### ENDIAN_FUSION 验证 (L1808-L1924)
识别两种模式：
1. **Load+Swap**: `ldx [base+off]; bswap reg` → 可融合为 `MOVBE`
2. **Swap+Store**: `bswap reg; stx [base+off]` → 可融合为 `MOVBE`

#### BRANCH_FLIP 验证 (L1926-L2035)
识别 `jcc; body_A...; ja; body_B...` if/else 结构，验证：
- body_A 和 body_B 都是线性代码（无分支/store/LD_IMM64）
- 各 body 长度 1-16
- 跳转偏移和 join target 一致

### 6.4 声明式 Pattern 引擎 (L2115-L2748)

这是 v5 的核心创新——用户态声明 BPF 指令 pattern，内核验证并匹配：

1. **`bpf_jit_match_pattern()`** — 逐指令匹配 opcode、绑定变量
2. **`bpf_jit_check_constraints()`** — 检查 7 种约束
3. **`bpf_jit_extract_bindings()`** — 从 pattern 变量提取 canonical 参数
4. **`bpf_jit_validate_canonical_params()`** — 验证参数合法性
5. **`bpf_jit_validate_canonical_site()`** — 调用 form-specific 验证器
6. **`bpf_jit_has_interior_edge()`** — 最终安全检查

这个多层验证管线确保：即使用户态构造恶意 pattern，内核也只会在安全验证通过后才激活规则。

### 6.5 Policy 解析 (L2845-L3234)

`bpf_jit_parse_policy()` 的完整流程：

1. 验证 fd 是 sealed memfd（`F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK`）
2. 读取 blob 到内核内存（最大 512KB）
3. 验证 header：magic、version、total_len、insn_cnt、prog_tag、arch_id
4. 逐条解析 `bpf_jit_rewrite_rule_v2`：
   - 验证 pattern descriptor、constraint descriptor、binding descriptor
   - 检查规则是否跨 subprogram 边界
   - 调用 `bpf_jit_validate_rule()` 做完整验证
   - 通过验证的规则标记 `BPF_JIT_REWRITE_F_ACTIVE`
5. 按 `site_start` 排序（`sort()`），用于后续 O(log n) 查找

### 6.6 BPF_PROG_JIT_RECOMPILE 主流程 (L3514-L3708)

`bpf_prog_jit_recompile()` 是 syscall handler，核心流程：

```
1. 权限检查 (CAP_BPF 或 CAP_SYS_ADMIN)
2. 获取 prog_fd 对应的 bpf_prog
3. 获取 jit_recompile_mutex (trylock，失败返回 EBUSY)
4. 分配 log 上下文
5. 检查程序已 JIT、非 blinded、非 attached struct_ops
6. 保存 rollback 快照
7. 如果 policy_fd == 0：stock re-JIT（清除 policy）
   否则：解析 policy blob
8. 交换 policy 到 prog
9. 触发 re-JIT（bpf_jit_recompile_prog_images）
10. 如果失败且 rollback_requested：恢复旧 policy 和 image
11. 更新 recompile_count
12. 释放资源、copy log 到用户态
```

`bpf_jit_recompile_prog_images()` 的详细流程：

```
对每个 subprogram:
  1. jit_recompile_stage_begin() — 标记 active
  2. bpf_int_jit_compile() — 重新 JIT（会查询 policy）
  3. 验证 staged image 有效

如果是多 subprogram：
  4. 修补 subprogram 间的 call 地址
  5. 再次 bpf_int_jit_compile()（final pass）

如果 policy 存在但没有规则 applied：
  6. 跳过 commit，保留旧 image

否则：
  7. 添加 shadow ksym
  8. bpf_jit_recompile_commit() — 原子切换
  9. smp_store_release(prog->bpf_func, new_func)
  10. synchronize_rcu()
  11. bpf_prog_kallsyms_replace() — 替换 ksym
  12. 释放旧 image
```

---

## 7. 系统调用入口

文件：`kernel/bpf/syscall.c`（+5 行）

修改极小但关键：

1. **包含头文件**：`#include <linux/bpf_jit_directives.h>`
2. **prog_info 扩展**：在 `bpf_prog_get_info_by_fd()` 中填充 `recompile_count`
3. **syscall dispatch**：在 `__sys_bpf()` 中添加 `BPF_PROG_JIT_RECOMPILE` case

```c
case BPF_PROG_JIT_RECOMPILE:
    err = bpf_prog_jit_recompile(&attr);
    break;
```

---

## 8. BPF 核心

文件：`kernel/bpf/core.c`（+112/-30 行）

### 8.1 Mutex 初始化

在 `bpf_prog_alloc_no_stats()` 中初始化 `jit_recompile_mutex` 和 `jit_recompile_ksym`。

### 8.2 Policy 释放

在 `__bpf_prog_free()` 中调用 `bpf_jit_free_policy()`。

### 8.3 Kallsyms 重构

这是最重要的改动。原始内核中，`bpf_ksym` 通过 `container_of` 反推 `bpf_prog`。Recompile 后新旧 image 共存，需要：

1. **`bpf_ksym` 新增 `owner` 字段**：直接指向 `bpf_prog`，不再依赖 `container_of`
2. **`bpf_ksym` 新增 `extable` 和 `num_exentries`**：每个 ksym 自带异常表信息
3. **`bpf_prog_kallsyms_replace()`**：原子地替换 ksym 条目（在 `bpf_lock` 下先删旧后加新）
4. **`search_bpf_extables()` 重构**：从 `bpf_prog->aux->extable` 改为 `bpf_ksym->extable`，确保在新旧 image 共存时异常表查找正确

```c
// 旧代码
prog = bpf_prog_ksym_find(addr);
e = search_extable(prog->aux->extable, prog->aux->num_exentries, addr);

// 新代码
ksym = bpf_ksym_find(addr);
e = search_extable(ksym->extable, ksym->num_exentries, addr);
```

这个改动确保了：在 RCU 宽限期内，新旧 JIT image 的异常处理都能正确工作。

---

## 9. 验证器

文件：`kernel/bpf/verifier.c`（+2 行）

在 `adjust_insn_aux_data()` 中，当验证器膨胀指令（如 16-byte 立即数展开为 2 条指令）时，保持 `orig_idx` 不变：

```c
unsigned int orig_idx = data[off].orig_idx;
...
for (i = off; i < off + cnt - 1; i++) {
    data[i].orig_idx = orig_idx;  // 新增
    data[i].seen = old_seen;
}
```

这确保了 policy blob 中的 `site_start`（基于 xlated 指令偏移）在验证器膨胀指令后仍然能正确映射到原始位置。这是 v5 声明式 pattern 的关键前提——用户态 scanner 基于 `orig_idx` 生成 site_start。

---

## 10. x86 JIT 编译器

文件：`arch/x86/net/bpf_jit_comp.c`（+2551/-194 行）

这是变更量最大的文件，包含所有 8 种 canonical form 的 native code emitter 和 recompile 生命周期管理。

### 10.1 辅助指令 Emitter

新增了一系列基础 emitter 函数，被多个 canonical form 共用：

- **`emit_mov_imm32_noflags()`** — 不影响 FLAGS 的立即数加载（CMOV 场景需要保持 FLAGS）
- **`emit_cmov_reg()`** — 发射 `CMOVcc` 指令
- **`emit_bpf_jmp_cmp()`** — 从 BPF 跳转指令提取比较操作并发射 x86 `CMP`/`TEST`
- **`bpf_jmp_to_x86_cmov()`** — BPF 条件码到 x86 CMOVcc 操作码映射
- **`bpf_jmp_invert()`** — 条件码取反
- **`emit_local_cond_jump()`** / **`emit_local_jump()`** — 发射局部跳转
- **`emit_bextr()`** — 发射 BMI1 `BEXTR` 指令
- **`emit_movbe_load()`** / **`emit_movbe_store()`** — 发射 `MOVBE` 指令
- **`emit_lea_base_index()`** — 发射 `LEA [base + index * scale]`

### 10.2 Canonical Form Emitter 汇总

#### COND_SELECT → emit_canonical_select()

支持 3 种 site_len：
- **site_len=2 (guarded update)**: `jcc +1; mov dst, src` → `cmp; cmov(NOT_cond) dst, src`
- **site_len=3 (compact)**: `mov_default; jcc +1; mov_override` → `mov_default; cmp; cmov(NOT_cond) dst, override`
- **site_len=4 (diamond)**: `jcc+2; mov_false; ja+1; mov_true` → `cmp; mov_true; cmov(cond) dst, false_val`

关键细节：当 `else_insn` 的 src 与 dst 相同时，先保存到 `AUX_REG`；MOV 使用 `noflags` 版本避免破坏比较结果。

#### WIDE_MEM → emit_canonical_wide_load()

将 N 条 byte-load + shift + OR 替换为单条宽 MOV：
- 2 字节 → `movzwl`
- 4 字节 → `mov`
- 8 字节 → `mov`
- 大端序 → 宽加载后 `bswap`

#### ROTATE → emit_canonical_rotate()

两种 native choice：
- **ROR**: `mov dst, src; ror dst, (W-N)`（使用标准 x86 `ROR`）
- **RORX**: `rorx dst, src, (W-N)`（BMI2 指令，不影响 FLAGS，且支持 non-destructive src）

VEX 编码通过 `emit_3vex()` 处理。

#### ADDR_CALC → emit_canonical_lea_fusion()

`mov dst,idx; lsh64 dst,scale; add64 dst,base` → `lea dst, [base + idx * 2^scale]`

使用 SIB 字节编码 scale。处理 `rbp/r13` 基寄存器需要 disp8 的特殊情况。

#### BITFIELD_EXTRACT → emit_canonical_bitfield_extract()

智能选择最优 emission：
1. **BMI1 BEXTR**：当 CPU 支持 BMI1、mask 是连续低位、且 src != dst 时使用（`mov_imm32 AUX, control; bextr dst, src, AUX`）
2. **SHR+AND fallback**：否则发射 `mov dst, src; shr dst, shift; and dst, mask`

关键修复（commit ac593b2c1）：BEXTR 仅在 src != dst 时使用，避免 without-copy 场景下代码膨胀（9B vs 6B）。

#### ZERO_EXT_ELIDE → emit_canonical_zero_ext_elide()

跳过冗余的零扩展指令，只发射第一条 ALU32 指令。x86-64 上 32-bit 操作自动零扩展高 32 位，所以 verifier 插入的 zext 是冗余的。

#### ENDIAN_FUSION → emit_canonical_endian_fusion()

- Load+Swap → `MOVBE dst, [base+off]`（MOVBE CPU feature required）
- Swap+Store → `MOVBE [base+off], src`

#### BRANCH_FLIP → emit_canonical_branch_flip()

完整重新发射 if/else 结构，交换 body A 和 body B 的顺序：

原始：`jcc body_B; body_A; ja join; body_B; join:`
翻转：`jcc_inv body_A; body_B; ja join; body_A; join:`

使用 `emit_linear_bpf_insn()` 独立发射每个 body 中的指令，先 measure 大小再 emit，处理跳转偏移。

### 10.3 do_jit() 集成

在主编译循环中插入规则查找和分发：

```c
// 在 switch(insn->code) 之前
err = bpf_jit_apply_prog_rule(temp, &prog, bpf_prog, addrs,
                              image, rw_image, oldproglen,
                              &proglen, i, priv_frame_ptr != NULL);
if (err < 0)
    return err;
if (err > 0) {
    insn += err - 1;  // 跳过被 rule 消耗的指令
    i += err - 1;
    continue;
}
```

`bpf_jit_apply_prog_rule()` 调用链：
1. `bpf_jit_rule_lookup_prog()` — 查找当前指令的规则
2. `bpf_jit_try_emit_rule()` — 分发到对应 form emitter
3. `bpf_jit_commit_rule_region()` — 将 emitted code 写入 image，更新 `addrs[]`

### 10.4 do_jit() 签名变更

```c
// 旧
static int do_jit(struct bpf_prog *bpf_prog, int *addrs, u8 *image,
                  u8 *rw_image, int oldproglen, struct jit_context *ctx,
                  bool jmp_padding);

// 新
static int do_jit(struct bpf_prog *bpf_prog, int *addrs, u8 *image,
                  u8 *rw_image, int oldproglen, struct jit_context *ctx,
                  bool jmp_padding,
                  void __percpu *priv_stack_ptr_override,
                  struct exception_table_entry *extable, u32 num_exentries);
```

新增参数允许 recompile 时使用独立的私有栈和异常表，而不是修改 `prog->aux` 上的字段。

### 10.5 bpf_int_jit_compile() 修改

主要改动：

1. **Recompile 模式检测**：`bool recompile = prog->aux->jit_recompile_active;`
2. **Staged image 管理**：recompile 时不直接修改 `prog->bpf_func`，而是存入 `jit_recompile_*` 字段
3. **extable 独立分配**：`extable` 在 recompile 时不写入 `prog->aux->extable`，而是存入 `jit_data->extable`
4. **私有栈分配**：recompile 时新分配的私有栈不立即写入 `prog->aux->priv_stack_ptr`
5. **fp_start/fp_end**：改为通过 `jit_context` 传递，避免直接修改 ksym

### 10.6 Commit/Abort 函数

```c
int bpf_jit_recompile_commit(struct bpf_prog *prog)
{
    // 更新 insn_ptrs、linfo
    // 将 staged 状态写入 prog->aux 和 prog
    // smp_store_release(&prog->bpf_func, staged_func)
    // 释放 jit_data
}

void bpf_jit_recompile_abort(struct bpf_prog *prog)
{
    // 释放新分配的 header (bpf_jit_binary_pack_free)
    // 释放新分配的私有栈
    // 释放 jit_data
    // 清除 staged 状态
}
```

### 10.7 其他重构

- 将 `emit_shiftx()` 等函数从 `do_jit()` 中提取为独立函数
- 条件跳转编译从 inline 代码改为调用 `emit_bpf_jmp_cmp()` + `bpf_jmp_to_x86_cond()`
- 修复 `bpf_jit_free()` 中的 recompile 状态清理

---

## 11. BPF 异常处理

文件：`kernel/bpf/helpers.c`（+6/-2 行）

修复 `bpf_throw()` 中的竞态条件：

```c
// 旧
ctx.aux->bpf_exception_cb(cookie, ctx.sp, ctx.bp, 0, 0);

// 新
exception_cb = READ_ONCE(ctx.aux->bpf_exception_cb);
if (WARN_ON_ONCE(!exception_cb))
    return;
exception_cb(cookie, ctx.sp, ctx.bp, 0, 0);
```

Recompile 可能在 `bpf_throw()` 执行期间更新 `bpf_exception_cb`，使用 `READ_ONCE` 确保原子读取。

---

## 12. 工具链

### 12.1 bpftool

`tools/bpf/bpftool/prog.c`：在 JSON 和 plain-text 输出中显示 `recompile_count`。

### 12.2 tools UAPI

`tools/include/uapi/linux/bpf.h`：同步 `BPF_F_RECOMPILE_ROLLBACK` 和 `recompile_count`。

---

## 13. Canonical Form 详解

### 13.1 COND_SELECT (CMOV)

**目标**：将 BPF 的 diamond/compact if-else-assign 模式替换为 x86 `CMOVcc`。

**BPF 模式 (Diamond, 4-insn)**:
```
[0] jcc +2           // 条件跳转到 [3]
[1] mov dst, val_F   // false 路径
[2] ja  +1           // 跳过 true 路径
[3] mov dst, val_T   // true 路径
```

**x86 Emission (CMOV)**:
```asm
cmp <operands>       ; 比较
mov dst, val_T       ; 无条件加载 true 值（不影响 FLAGS）
cmovcc dst, val_F    ; 条件选择 false 值
```

**Policy-sensitive 意义**：CMOV 在可预测分支上可能比 `jcc+mov` 更慢（因为 data dependency chain），但在不可预测分支上更快。log2_fold 上 kernel stock JIT 用 `jcc+mov` 快 28.3%，证明 CMOV 不能无条件使用。

**Native choices**: `BPF_JIT_SEL_CMOVCC` (用 CMOV) 或 `BPF_JIT_SEL_BRANCH` (保持 stock)

### 13.2 WIDE_MEM (byte-recompose → wide load)

**目标**：将 BPF 编译器生成的多字节逐一加载+移位+OR 模式替换为单条宽 MOV。

**BPF 模式 (4-byte LE)**:
```
ldxb dst, [base+0]
ldxb tmp, [base+1]
lsh64 tmp, 8
or64 dst, tmp
ldxb tmp, [base+2]
lsh64 tmp, 16
or64 dst, tmp
ldxb tmp, [base+3]
lsh64 tmp, 24
or64 dst, tmp
```

**x86 Emission**:
```asm
mov eax, [base+0]    ; 单条 4-byte load
```

**数据**：占 kernel-vs-llvmbpf surplus 的 50.7%，是最高价值的单一 form。

### 13.3 ROTATE (循环移位)

**目标**：将 BPF 的 shift+or rotate 模式替换为 x86 `ROR` 或 BMI2 `RORX`。

**BPF 模式 (4-insn)**:
```
mov tmp, src
lsh src, N
rsh tmp, (W-N)
or  src, tmp
```

**x86 Emission**:
```asm
; ROR 模式
mov dst, src
ror dst, (W-N)

; RORX 模式 (BMI2, non-destructive)
rorx dst, src, (W-N)
```

**Native choices**: `BPF_JIT_ROT_ROR` / `BPF_JIT_ROT_RORX` / `BPF_JIT_ROT_SHIFT` (stock)

### 13.4 ADDR_CALC (LEA)

**目标**：将 BPF 的 `mov+shl+add` 地址计算替换为单条 x86 `LEA`。

**BPF 模式**:
```
mov64 dst, idx
lsh64 dst, scale     // scale = 1, 2, 3
add64 dst, base
```

**x86 Emission**:
```asm
lea dst, [base + idx * 2^scale]
```

### 13.5 BITFIELD_EXTRACT (BEXTR)

**目标**：将 BPF 的 shift+mask 位域提取替换为 BMI1 `BEXTR` 或优化的 shift+and。

**BPF 模式 (3-insn, with-copy)**:
```
mov dst, src
rsh dst, shift
and dst, mask
```

**x86 Emission (BMI1, with-copy)**:
```asm
mov eax, control     ; control = (field_width << 8) | shift
bextr dst, src, eax  ; 一条指令完成
```

**x86 Emission (无 BMI1 或 without-copy)**:
```asm
[mov dst, src]       ; 仅 with-copy
shr dst, shift
and dst, mask
```

### 13.6 ZERO_EXT_ELIDE (零扩展消除)

**目标**：消除 verifier 插入的冗余 32-bit 零扩展。

**BPF 模式**:
```
alu32 op dst, ...    // 32-bit ALU 操作
mov64 dst, dst       // 或 zext dst（冗余：x86-64 上 32-bit op 已零扩展高位）
```

**x86 Emission**:
```asm
; 只发射 alu32 操作，跳过 zext
```

**注意**：x86-64 上 corpus 中 0 个 site（因为 `bpf_jit_needs_zext()=false`），此 form 为 RISC-V/ARM 架构准备。

### 13.7 ENDIAN_FUSION (MOVBE)

**目标**：将 BPF 的 load+bswap 或 bswap+store 融合为 x86 `MOVBE`。

**BPF 模式 (Load+Swap)**:
```
ldx dst, [base+off]
end_le dst, width    // bswap
```

**x86 Emission**:
```asm
movbe dst, [base+off]  ; 原子完成 load+byteswap
```

**CPU feature**: 需要 `X86_FEATURE_MOVBE`

### 13.8 BRANCH_FLIP (分支翻转)

**目标**：交换 if-else 结构中 then/else body 的物理顺序。

**原始结构**:
```
jcc body_B
body_A       // fallthrough path
ja join
body_B       // taken path
join:
```

**翻转后**:
```
jcc_inv body_A    // 条件取反
body_B            // 新的 fallthrough
ja join
body_A            // 新的 taken
join:
```

**Policy-sensitive 意义**：哪个分支作为 fallthrough 更优取决于运行时分支预测热度。Tracee 有 1791 个 sites，是 corpus 中最多的。

---

## 14. Recompile 工作流

完整的 recompile 生命周期：

```
用户态                              内核
  |                                  |
  |  BPF_PROG_JIT_RECOMPILE         |
  |  (prog_fd, policy_fd)           |
  |--------------------------------->|
  |                                  |  1. 权限检查 (CAP_BPF)
  |                                  |  2. 获取 prog, trylock mutex
  |                                  |  3. 分配 log context
  |                                  |  4. 保存 rollback snapshot
  |                                  |
  |                                  |  5. 解析 policy blob:
  |                                  |     - 验证 sealed memfd
  |                                  |     - 验证 header (magic/version/arch)
  |                                  |     - 验证 digest binding (prog_tag + insn_cnt)
  |                                  |     - 逐条验证 rule:
  |                                  |       a. pattern 匹配
  |                                  |       b. constraint 检查
  |                                  |       c. binding 提取
  |                                  |       d. canonical params 验证
  |                                  |       e. form-specific site 验证
  |                                  |       f. interior edge 检查
  |                                  |       g. CPU feature 检查
  |                                  |     - 排序 rules (by site_start)
  |                                  |
  |                                  |  6. 交换 policy 到 prog->aux
  |                                  |
  |                                  |  7. Re-JIT (bpf_jit_recompile_prog_images):
  |                                  |     对每个 subprogram:
  |                                  |       - stage_begin()
  |                                  |       - bpf_int_jit_compile()
  |                                  |         [do_jit() 中 bpf_jit_apply_prog_rule()
  |                                  |          在每条指令前查找 rule 并分发 emitter]
  |                                  |       - 验证 staged image
  |                                  |     修补 inter-subprog calls
  |                                  |     final pass JIT
  |                                  |
  |                                  |  8. 如果无 rule applied: 保留旧 image
  |                                  |     否则:
  |                                  |       - 添加 shadow ksym
  |                                  |       - commit (原子切换 bpf_func)
  |                                  |       - synchronize_rcu()
  |                                  |       - 替换 kallsyms
  |                                  |       - 释放旧 image
  |                                  |
  |  <-- err + log_buf -------------|  9. copy log to user, 释放资源
```

---

## 15. Policy 格式与解析

### 15.1 二进制布局

```
+-----------------------------------+
| bpf_jit_policy_hdr (32 bytes)     |
|   magic: 0x4A495450 ("JITP")      |
|   version: 2                      |
|   hdr_len: 32                     |
|   total_len: N                    |
|   rule_cnt: M                     |
|   insn_cnt: prog->len             |
|   prog_tag[8]: SHA-1 truncation   |
|   arch_id: 1 (x86_64)            |
+-----------------------------------+
| rule[0]: bpf_jit_rewrite_rule_v2  |
|   + pattern_insn[pattern_count]   |
|   + constraint[constraint_count]  |
|   + binding[binding_count]        |
+-----------------------------------+
| rule[1]: ...                      |
+-----------------------------------+
| ...                               |
+-----------------------------------+
```

### 15.2 验证层次

1. **Transport Layer**: sealed memfd、blob 大小 <= 512KB
2. **Header Layer**: magic、version、arch_id、total_len、rule_cnt <= 1024
3. **Digest Binding**: `insn_cnt` 和 `prog_tag` 必须匹配当前程序
4. **Rule Descriptor**: kind、form、site_len、rule_len 算术正确
5. **Pattern Descriptor**: opcode 合法、binding var ID 范围正确
6. **Constraint Descriptor**: type 合法、var ID 范围正确
7. **Binding Descriptor**: canonical_param 合法、source_type 合法、无重复 param
8. **Pattern Matching**: 逐指令匹配 opcode 和期望字段
9. **Constraint Checking**: 7 种约束全部满足
10. **Binding Extraction**: 变量到 canonical param 的映射
11. **Canonical Param Validation**: 寄存器范围、宽度、移位量等
12. **Form-specific Site Validation**: 调用 per-form 验证器
13. **Interior Edge Check**: 无外部跳转进入 site 内部
14. **CPU Feature Check**: 当前 CPU 支持所需特性
15. **Subprogram Boundary Check**: rule 不跨 subprogram

---

## 16. 安全模型总结

BpfReJIT 的安全设计基于以下核心原则：

### 16.1 Fail-closed

任何验证失败都导致规则被标记为 inactive（`flags` 清零），JIT 回退到标准 emission。不存在"部分应用"的中间状态。

### 16.2 Digest Binding

Policy blob 通过 `prog_tag`（程序 SHA-1 的 8 字节截断）和 `insn_cnt` 绑定到特定程序。如果程序被修改或重新加载，旧 policy 无法应用。

### 16.3 Sealed Memfd

Policy blob 必须通过 sealed memfd 传递（`F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK`），确保内核读取后内容不可被用户态修改。

### 16.4 内核永远不执行用户态代码

内核只在自己预定义的 safe variant 之间切换。用户态通过 `native_choice` 字段选择变体（如 CMOV vs branch），但具体的 native code emission 完全由内核控制。

### 16.5 xlated_prog_len 不变量

所有 directive 只改 native code emission，不改 BPF 指令。验证器看到的程序不变，安全性保证不变。

### 16.6 Mutex 串行化

`jit_recompile_mutex` 确保同一程序同时只有一个 recompile 操作。`trylock` 语义（失败返回 `EBUSY`）避免死锁。

### 16.7 RCU + shadow ksym

切换时使用 `smp_store_release` + `synchronize_rcu` 确保所有正在执行旧 image 的 CPU 完成后才释放旧 image。Shadow ksym 确保过渡期内异常表和 kallsyms 查找正确。

### 16.8 Constant Blinding 兼容

Blinded 程序（`prog->blinded`）直接拒绝 recompile，因为 constant blinding 会打乱 insn offset，使 policy 中的 `site_start` 无效。

---

*文档生成时间：2026-03-18*
*分析基于 `vendor/linux-framework` 分支 `jit-directive-v5`（tip commit: 7de19ef03）相对于 `master`（upstream Linux 7.0-rc2）的 diff*
