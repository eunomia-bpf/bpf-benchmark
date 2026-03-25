# kinsn 伪指令编码统一到 kfunc CALL 路径 — 可行性调研报告

日期：2026-03-25
作者：Claude Agent (调研)

---

## 1. 两条路径的完整 Call Graph

### 1.1 kfunc 路径（BPF_PSEUDO_KFUNC_CALL = 2）

```
用户空间 CALL insn: { code=BPF_JMP|BPF_CALL, src_reg=2, imm=btf_func_id, off=fd_array_idx }
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 1. add_subprog_and_kfunc()          │ verifier.c:4149
                 │    └→ add_kfunc_call()              │ verifier.c:3512
                 │       ├→ find_kfunc_desc_btf()      │ verifier.c:3405
                 │       │   └→ __find_kfunc_desc_btf()│ verifier.c:3301
                 │       │      (off>0 → fd_array[off] │
                 │       │       → btf_get_by_fd()     │
                 │       │       → btf_try_get_module() │
                 │       │       off==0 → btf_vmlinux) │
                 │       ├→ fetch_kfunc_meta()         │ verifier.c:3449
                 │       │   ├→ btf_kfunc_flags()      │ btf.c:8903
                 │       │   ├→ btf_type_by_id()       │ (BTF_KIND_FUNC 查找)
                 │       │   └→ btf_type_is_func_proto │
                 │       ├→ kallsyms_lookup_name()     │ (获取函数地址)
                 │       ├→ btf_distill_func_proto()   │ (构建 func_model)
                 │       └→ tab->descs[nr++] = desc    │ (记录 desc)
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 2. do_check_main() → do_check_insn()│ verifier.c:21665
                 │    └→ check_kfunc_call()            │ verifier.c:14632
                 │       ├→ fetch_kfunc_arg_meta()     │ verifier.c:14424
                 │       │   └→ fetch_kfunc_meta()     │ (同上)
                 │       │      + btf_kfunc_is_allowed()│ (检查 KF_* flags)
                 │       ├→ check_kfunc_args()         │ (参数类型检查)
                 │       ├→ caller_saved regs 清除     │ (r0-r5 clobber)
                 │       └→ 设置 r0 返回值类型         │
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 3. convert_ctx_accesses()           │ verifier.c:23966
                 │    → fixup_kfunc_call()             │ verifier.c:23760
                 │       ├→ find_kfunc_desc()          │ (imm+off → desc)
                 │       ├→ specialize_kfunc()         │ (特化地址)
                 │       ├→ insn->imm = BPF_CALL_IMM() │ (imm 改为地址偏移)
                 │       └→ 可选：前插 insn_buf[]      │ (obj_new 等需要)
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 4. JIT (x86) do_jit()               │ bpf_jit_comp.c:2484
                 │    BPF_JMP|BPF_CALL:                │
                 │    ├→ bpf_jit_get_func_addr()       │ core.c:1241
                 │    │   (supports_far_kfunc_call()   │
                 │    │    → bpf_get_kfunc_addr())     │
                 │    └→ emit_call()                   │ (标准 x86 CALL)
                 └─────────────────────────────────────┘
```

**关键特征：**
- `imm` = BTF_KIND_FUNC 的 btf_id（函数类型）
- `off` = fd_array 索引（0=vmlinux, >0=module BTF fd）
- `add_kfunc_call()` 需要通过 `kallsyms_lookup_name()` 解析出函数地址
- `fetch_kfunc_meta()` 需要函数是 BTF_KIND_FUNC，且必须有 `btf_kfunc_flags()` 注册
- `check_kfunc_call()` 做完整的参数类型检查、KF_* flag 处理
- `fixup_kfunc_call()` 把 imm 从 btf_id 改成 `__bpf_call_base` 相对偏移（或保持 btf_id 给 far call）

### 1.2 kinsn 路径（BPF_PSEUDO_KINSN_CALL = 4）

```
daemon emit: { sidecar: code=BPF_ALU64|BPF_MOV|BPF_K, src_reg=3, payload编码在 dst_reg+off+imm }
             { call:    code=BPF_JMP|BPF_CALL, src_reg=4, imm=btf_var_id, off=fd_array_idx }
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 1. add_subprog_and_kfunc()          │ verifier.c:4149
                 │    └→ add_kinsn_call()              │ verifier.c:3643
                 │       ├→ fetch_kinsn_desc_meta()    │ verifier.c:3607
                 │       │   ├→ find_kfunc_desc_btf()  │ (复用 kfunc 的 BTF 查找!)
                 │       │   └→ btf_try_get_kinsn_desc()│ btf.c:9175
                 │       │      (btf->kinsn_tab bsearch │ → struct bpf_kinsn*)
                 │       └→ tab->descs[nr++] = desc    │
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 2. lower_kinsn_proof_regions()      │ verifier.c:3958
                 │    (在 verifier 主循环之前执行)      │
                 │    遍历所有 kinsn call:              │
                 │    ├→ bpf_jit_find_kinsn_desc()     │
                 │    ├→ kinsn->instantiate_insn()     │ (生成 proof 指令序列)
                 │    ├→ validate_kinsn_proof_seq()    │ (校验：无 call/exit/back-edge)
                 │    ├→ verifier_remove_insns()       │ (删除 sidecar)
                 │    └→ bpf_patch_insn_data()         │ (替换 call → proof 序列)
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 3. do_check_main() → do_check_insn()│ verifier.c:21602
                 │    a) sidecar → 已被 lower 删除     │
                 │    b) kinsn call → 已被 proof 替换  │
                 │    → verifier 看到的是普通 BPF insn │
                 │    (如果未 lower: 报 EFAULT)        │
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 4. restore_kinsn_proof_regions()    │ verifier.c:4042
                 │    (验证通过后恢复 sidecar+call)     │
                 │    ├→ bpf_patch_insn_data(orig,2)   │ (恢复原始 2-insn)
                 │    └→ scrub_restored_kinsn_aux()    │ (清理 aux 状态)
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 5. convert_ctx_accesses()           │ verifier.c:23967
                 │    ├→ sidecar 检测                  │
                 │    │   ├→ build_kinsn_inst_seq()    │ (再次生成 proof 序列)
                 │    │   ├→ 检查 native emit          │
                 │    │   │   有 → goto next_insn      │ (保留 sidecar+call 给 JIT)
                 │    │   │   无 → patch proof 序列     │ (展开为 BPF insn)
                 │    │   └→ BPF_PSEUDO_KINSN_CALL →   │
                 │    │      goto next_insn (跳过)     │ verifier.c:24304
                 │    └→ fixup_kfunc_call() 不处理      │
                 └─────────────────────────────────────┘
                                    │
                 ┌──────────────────┴──────────────────┐
                 │ 6. JIT (x86) do_jit()               │ bpf_jit_comp.c:2488
                 │    BPF_JMP|BPF_CALL, src==4:        │
                 │    └→ emit_kinsn_desc_call()        │ bpf_jit_comp.c:579
                 │       ├→ bpf_jit_get_kinsn_payload()│ verifier.c:4111
                 │       │   ├→ bpf_jit_find_kinsn_desc()│ (kinsn_tab 查找)
                 │       │   └→ bpf_prog_find_kinsn_sidecar()│ (前一条指令)
                 │       └→ kinsn->emit_x86()          │ (模块提供的原生 emit)
                 │                                      │
                 │ JIT (arm64) build_insn()             │ bpf_jit_comp.c:1628
                 │    └→ emit_kinsn_desc_call_arm64()  │ bpf_jit_comp.c:1195
                 │       └→ kinsn->emit_arm64()        │
                 └─────────────────────────────────────┘
```

**关键特征：**
- `imm` = BTF_KIND_VAR 的 btf_id（不是函数类型，是变量类型！）
- `off` = fd_array 索引（与 kfunc 共享 `find_kfunc_desc_btf()` 机制）
- sidecar insn 编码 payload（dst_reg[3:0] + off[15:0] + imm[31:0] → 52bit）
- 不走 `check_kfunc_call()`，不做参数检查
- 通过 lower/restore 机制：先展开为 proof 序列让 verifier 验证，验证完后恢复原始 2-insn
- kinsn 不需要函数地址（不调用真实函数），而是通过 emit_x86/emit_arm64 直接发射机器码
- 独立注册表：`btf->kinsn_tab`（与 `btf->kfunc_set_tab` 并行）

---

## 2. 合并可行性分析

### 2.1 核心冲突：imm 语义完全不同

| 维度 | kfunc (PSEUDO_KFUNC_CALL=2) | kinsn (PSEUDO_KINSN_CALL=4) |
|------|---------------------------|---------------------------|
| `imm` 含义 | BTF_KIND_FUNC 的 btf_id | BTF_KIND_VAR 的 btf_id |
| BTF 类型 | 函数 (func → func_proto) | 变量 (var → struct bpf_kinsn) |
| 是否有函数地址 | 是（kallsyms_lookup_name） | 否（无真实函数） |
| 参数检查 | 完整的 BTF 类型检查 | 无（proof 序列代替） |
| 返回值 | BTF 类型驱动 | 无（不修改 reg 状态） |
| fixup | imm → 地址偏移 | 不 fixup（保留原始 imm） |
| JIT | 发射 CALL 指令 | 发射自定义机器码 |

**关键问题：如果把 kinsn 的 src_reg 改成 BPF_PSEUDO_KFUNC_CALL (=2)，`add_kfunc_call()` 会被触发。这个函数会：**

1. **`fetch_kfunc_meta()` 会失败**：它期望 imm 是 BTF_KIND_FUNC 的 id，但 kinsn 的 imm 是 BTF_KIND_VAR 的 id。`btf_type_is_func()` 检查会失败，报 `"kernel btf_id %d is not a function"`。

2. **`kallsyms_lookup_name()` 会失败**：kinsn 没有对应的内核函数。

3. **`check_kfunc_call()` 会被触发**：verifier 会尝试做参数类型检查，但 kinsn 不是真正的函数调用。

4. **`fixup_kfunc_call()` 会修改 imm**：把 btf_id 替换成地址偏移，破坏 kinsn 需要在 JIT 中保留的 btf_var_id。

### 2.2 sidecar insn 在 kfunc 路径下的命运

kfunc 路径完全不知道 sidecar 的存在。在 `resolve_pseudo_ldimm64()` 中，sidecar（编码为 `BPF_ALU64|BPF_MOV|BPF_K, src_reg=3`）会被当作普通 ALU 指令，在 `do_check_insn()` 中走 `check_alu_op()` 路径。

当前 kinsn 路径中，sidecar 在 `do_check_insn()` 最顶部被特殊拦截（verifier.c:21602），直接跳到 `check_kinsn_sidecar_insn()`，验证下一条是 kinsn call 后跳过。如果改成 kfunc 编码，这个拦截逻辑仍然可以保留，因为 sidecar 检测基于 `bpf_kinsn_is_sidecar_insn()`（检查 code 和 src_reg=3），与 CALL insn 的 src_reg 无关。

但 **lower_kinsn_proof_regions()** 依赖 `bpf_pseudo_kinsn_call()` 来识别 kinsn call。如果改成 kfunc 编码，这个函数需要用其他方式区分 kinsn 和普通 kfunc。

### 2.3 `fixup_kfunc_call()` 的破坏性

这是最关键的冲突点。在 `convert_ctx_accesses()` 中（verifier.c:24306）：

```c
if (insn->src_reg == BPF_PSEUDO_KFUNC_CALL) {
    ret = fixup_kfunc_call(env, insn, insn_buf, i + delta, &cnt);
    ...
}
```

`fixup_kfunc_call()` 会：
1. 调用 `find_kfunc_desc()` — 但 kinsn 不在 kfunc_tab 中，会返回 NULL → **BUG**
2. 把 `insn->imm` 改成 `BPF_CALL_IMM(desc->addr)` — 破坏 kinsn 的 btf_var_id

如果要统一编码，必须在 `fixup_kfunc_call()` 之前或之中加入分支逻辑来识别和跳过 kinsn。

### 2.4 JIT 中 kfunc CALL emit 路径

**x86 (bpf_jit_comp.c:2484-2510)**：
```c
case BPF_JMP | BPF_CALL: {
    u8 *ip = image + addrs[i - 1];
    func = (u8 *) __bpf_call_base + imm32;
    if (src_reg == BPF_PSEUDO_KINSN_CALL) {  // 当前：独立分支
        err = emit_kinsn_desc_call(...);
        break;
    }
    if (src_reg == BPF_PSEUDO_CALL && tail_call_reachable) { ... }
    if (!imm32) return -EINVAL;
    // ... emit_call()
}
```

如果改成 kfunc 编码，JIT 中需要在 kfunc 路径内加判断。但 JIT 没有方便的方式区分"这是普通 kfunc"还是"这是 kinsn"，因为 src_reg 相同了。

**可能的区分方式：**
- 在 kfunc_tab 中加标记？但 kinsn 不在 kfunc_tab 中。
- 检查 kinsn_tab？在 JIT 中多一次 `find_kinsn_desc()` 查找。
- 添加 KF_KINSN flag？但 kinsn 不是真正的 kfunc，没有 kfunc flags 基础设施。

### 2.5 `core.c` 地址解析

`bpf_jit_get_func_addr()` (core.c:1278)：
```c
} else if (insn->src_reg == BPF_PSEUDO_KFUNC_CALL &&
           bpf_jit_supports_far_kfunc_call()) {
    err = bpf_get_kfunc_addr(prog, insn->imm, insn->off, &addr);
```

如果 kinsn 改用 kfunc 编码，这段代码会尝试在 kfunc_tab 中查找地址 → 找不到 → 失败。需要额外判断。

---

## 3. "加 KF_KINSN 标记" 方案的详细分析

假设我们定义一个 `KF_KINSN` flag（如 `#define KF_KINSN (1 << 16)`），让 kinsn 在 kfunc 注册表中注册。

### 3.1 注册时需要的改动

kinsn 当前注册路径是 `register_bpf_kinsn_set()` → `btf->kinsn_tab`。
kfunc 注册路径是 `register_btf_kfunc_id_set()` → `btf->kfunc_set_tab`。

问题：
- kfunc 注册需要 BTF_KIND_FUNC + BTF_KIND_FUNC_PROTO（函数签名），kinsn 没有这些。
- kfunc 注册需要通过 `btf_check_kfunc_protos()` 校验，kinsn 会失败。
- kfunc 的 `btf_kfunc_flags()` 查找基于 btf_id（BTF_KIND_FUNC），kinsn 的 btf_id 是 BTF_KIND_VAR。

**要让 kinsn 注册到 kfunc 表中，需要**：
1. 为每个 kinsn 创建一个虚假的 BTF_KIND_FUNC 条目（void → void）— 污染 BTF
2. 或者修改 kfunc 注册基础设施接受 VAR 类型 — 违反 kfunc 语义
3. 或者保留 kinsn_tab，但在 add_kfunc_call() 中同时查 kinsn_tab — 混合更复杂

### 3.2 验证时需要的改动

`check_kfunc_call()` (verifier.c:14632) 中的每个步骤：

| 步骤 | kinsn 需要跳过？ | 原因 |
|------|----------------|------|
| `fetch_kfunc_arg_meta()` | 需要完全替换 | kinsn 没有函数签名 |
| `check_kfunc_args()` | 需要跳过 | kinsn 不检查参数 |
| `KF_* flag 处理` | 需要跳过 | kinsn 没有 sleepable/destructive 等 |
| `caller_saved 清除` | **冲突** | kinsn 不 clobber 寄存器 |
| `r0 返回值设置` | **冲突** | kinsn 不设置返回值 |

**caller_saved 清除是关键冲突**：`check_kfunc_call()` 在 line 14864 会清除 r0-r5：
```c
for (i = 0; i < CALLER_SAVED_REGS; i++) {
    mark_reg_not_init(env, regs, caller_saved[i]);
}
```
kinsn 的 proof 序列只修改特定寄存器，不 clobber 全部。如果走 kfunc 路径，verifier 会错误地认为 r1-r5 被破坏了。

但实际上 kinsn 的验证不走 `check_kfunc_call()` — 它走 lower/restore 路径。所以这个冲突可以通过"kinsn 继续使用 lower/restore，不走 check_kfunc_call()"来回避。这需要在 do_check_insn() 中，对 kfunc call 进一步区分：
```c
} else if (insn->src_reg == BPF_PSEUDO_KFUNC_CALL) {
    if (is_kinsn_lowered(env, insn_idx)) {
        // 已经被 lower 了，这里不应该出现
        verbose(env, "internal error: ...");
        return -EFAULT;
    }
    err = check_kfunc_call(env, insn, &env->insn_idx);
```

但这恰恰说明：kinsn 的验证路径与 kfunc 根本不同，统一编码不能统一验证。

### 3.3 fixup 时需要的改动

```c
// convert_ctx_accesses() 中
if (insn->src_reg == BPF_PSEUDO_KFUNC_CALL) {
    if (find_kinsn_desc(env->prog, insn->imm, insn->off)) {
        goto next_insn;  // 跳过 kfunc fixup
    }
    ret = fixup_kfunc_call(env, insn, insn_buf, i + delta, &cnt);
}
```

### 3.4 JIT 时需要的改动

```c
// x86 do_jit()
case BPF_JMP | BPF_CALL:
    if (src_reg == BPF_PSEUDO_KFUNC_CALL) {
        // 需要判断是 kinsn 还是普通 kfunc
        const struct bpf_kinsn *kinsn = bpf_jit_find_kinsn_desc(bpf_prog, insn);
        if (kinsn) {
            err = emit_kinsn_desc_call(...);
            break;
        }
    }
    // ... 原有 kfunc JIT 路径
```

同样需要在 arm64、riscv、loongarch、s390、x86-32 等所有架构中添加。

---

## 4. 精确改动清单

### 4.1 统一编码方案（如果执行）

#### 内核侧

| 文件 | 函数/位置 | 操作 | 行号 |
|------|----------|------|------|
| `include/uapi/linux/bpf.h` | `BPF_PSEUDO_KINSN_CALL` | 删除常量定义 | :1391-1394 |
| `include/uapi/linux/bpf.h` | `BPF_PSEUDO_KINSN_SIDECAR` | **保留**（sidecar 与 CALL 编码无关） | :1386-1390 |
| `tools/include/uapi/linux/bpf.h` | 同步删除 | | :1391-1394 |
| `include/linux/filter.h` | `BPF_CALL_KINSN` | 改 src_reg=BPF_PSEUDO_KFUNC_CALL | :489-495 |
| `include/linux/bpf.h` | 无改动 | kinsn 结构体和 API 保留 | |
| `kernel/bpf/verifier.c` | `bpf_pseudo_kinsn_call()` | 删除或改用其他检测方式 | :275-278 |
| `kernel/bpf/verifier.c` | `add_subprog_and_kfunc()` | kinsn 分支检测方式改变 | :4165,4177-4179 |
| `kernel/bpf/verifier.c` | `lower_kinsn_proof_regions()` | 用 `find_kinsn_desc()` 而非 src_reg 检测 | :3978 |
| `kernel/bpf/verifier.c` | `do_check_insn()` BPF_CALL 分支 | 删除 KINSN_CALL 检查，加 kinsn_tab 查找 | :21667-21697 |
| `kernel/bpf/verifier.c` | `convert_ctx_accesses()` sidecar | 改检测条件 | :23967-23993 |
| `kernel/bpf/verifier.c` | `convert_ctx_accesses()` fixup | 加 kinsn_tab 守卫跳过 fixup_kfunc_call | :24304-24306 |
| `kernel/bpf/verifier.c` | `fixup_call_args()` | 删除 has_kinsn_call 检查（合并到 kfunc） | :23643,23661-23664 |
| `kernel/bpf/verifier.c` | `bpf_prog_has_kinsn_call()` | 不能再用 src_reg 检测，需查 kinsn_tab | :3765-3776 |
| `kernel/bpf/core.c` | `bpf_jit_get_func_addr()` | 加 kinsn_tab 检查跳过地址解析 | :1278 |
| `kernel/bpf/disasm.c` | `__func_get_name()` | 改检测方式 | :39-40 |
| `arch/x86/net/bpf_jit_comp.c` | `do_jit()` BPF_CALL | 改 src_reg==4 → kinsn_tab 查找 | :2488-2493 |
| `arch/arm64/net/bpf_jit_comp.c` | `build_insn()` | 同上 | :1628-1633 |
| `arch/riscv/net/bpf_jit_comp64.c` | | 需加 kinsn 处理（当前无） | :1817 |
| `arch/loongarch/net/bpf_jit.c` | | 同上 | :1000 |
| `arch/s390/net/bpf_jit_comp.c` | | 同上 | :1795 |
| `arch/x86/net/bpf_jit_comp32.c` | | 同上 | :2094 |

**每个改动点都需要从"简单的 src_reg 比较"变成"kinsn_tab 动态查找"。**

#### daemon 侧

| 文件 | 函数/位置 | 操作 |
|------|----------|------|
| `daemon/src/insn.rs` | `BPF_PSEUDO_KINSN_CALL` | 删除，改用 `BPF_PSEUDO_KFUNC_CALL` |
| `daemon/src/insn.rs` | `call_kinsn_with_off()` | 改 src_reg 为 `BPF_PSEUDO_KFUNC_CALL` |
| `daemon/src/insn.rs` | `is_kinsn_sidecar()` | 保留（sidecar 不变） |
| `daemon/src/passes/utils.rs` | `emit_packed_kinsn_call_with_off()` | call insn 的 src_reg 改为 2 |
| `daemon/src/passes/rotate.rs` | 所有 `BPF_PSEUDO_KINSN_CALL` 引用 | 改为 `BPF_PSEUDO_KFUNC_CALL` |
| `daemon/src/passes/cond_select.rs` | 同上 | |
| `daemon/src/passes/extract.rs` | 同上 | |
| `daemon/src/passes/endian.rs` | 同上 | |
| `daemon/src/passes/spectre.rs` | 同上 | |

### 4.2 行数估算

| 操作 | 估算行数 |
|------|---------|
| 内核删除 `BPF_PSEUDO_KINSN_CALL` 和 `bpf_pseudo_kinsn_call()` | -15 行 |
| 内核添加 kinsn_tab 查找守卫（verifier 3处 + JIT 6架构 + core 1处 + disasm 1处） | +40~60 行 |
| 内核修改 `bpf_prog_has_kinsn_call()` | +5 行 |
| daemon 改编码常量和引用 | ~20 行修改 |
| **净变化** | **约 +30~50 行（内核侧更复杂）** |

---

## 5. 风险评估

### 5.1 风险矩阵

| 风险 | 概率 | 影响 | 描述 |
|------|------|------|------|
| **区分逻辑遗漏** | 高 | 高 | 每个检查 src_reg==KFUNC_CALL 的地方都需要额外判断是否 kinsn，遗漏一处就是 bug。当前有 15+ 处。 |
| **fixup 路径破坏 kinsn** | 高 | 高 | `fixup_kfunc_call()` 修改 imm，一旦 kinsn_tab 查找失败就会破坏 kinsn insn。 |
| **JIT 多架构遗漏** | 中 | 高 | 6 个架构后端都需要改，容易遗漏。当前 kinsn 只在 x86/arm64 有 native emit，但其他架构的 kfunc 路径也需要跳过。 |
| **bpf_jit_get_func_addr 失败** | 高 | 高 | core.c 的地址解析会在 kinsn 上失败（找不到 kfunc desc），如果没加守卫就是 JIT 编译失败。 |
| **精度追踪 (backtrack) 混淆** | 低 | 中 | `verifier.c:4953` 处的 sidecar 检测与 CALL 编码无关，应该不受影响。 |
| **daemon tests 破坏** | 低 | 中 | daemon 侧改动是简单的常量替换，tests 应该能适配。但内核侧改动如果有 bug，vm-selftest 会失败。 |
| **module 生命周期** | 低 | 低 | kinsn 的 module 生命周期通过 btf->kinsn_tab 管理，与 CALL 编码无关。 |

### 5.2 现有测试影响

| 测试集 | 影响 | 原因 |
|--------|------|------|
| **333 daemon tests** | 中等风险 | daemon tests 中大量检查 `src_reg() == BPF_PSEUDO_KINSN_CALL`，需要全部改成 `BPF_PSEUDO_KFUNC_CALL`。但这些是单元测试，不跑内核，改常量即可。 |
| **vm-selftest (70/70)** | 高风险 | selftests 中有 kinsn 相关测试（如果有的话），内核侧改动可能导致 verifier 行为变化。 |
| **vm-micro** | 高风险 | micro benchmarks 使用 kinsn（rotate/extract/select/endian），如果编码改错会直接 verifier reject。 |
| **vm-corpus** | 中等风险 | corpus programs 不使用 kinsn，但 daemon 的 pass 会注入 kinsn call。如果内核侧有 bug，corpus 中有 kinsn 优化的程序会失败。 |

### 5.3 sidecar 编码安全性

sidecar 编码（`BPF_ALU64|BPF_MOV|BPF_K, src_reg=3`）与 CALL insn 的编码完全正交。改 CALL 的 src_reg 不影响 sidecar 的检测和 payload 解码。

但有一个微妙问题：当前在 `do_check_insn()` 中，sidecar 检测后会验证下一条是 kinsn call：
```c
if (!bpf_pseudo_kinsn_call(next)) {
    verbose(env, "kinsn sidecar must be immediately followed by a kinsn call\n");
```
如果改用 kfunc 编码，这里需要改成"检查下一条是 kfunc call 且在 kinsn_tab 中"。

---

## 6. 上游接受性分析

### 6.1 当前内核 diff

从 stock 7.0-rc2 baseline 到 HEAD，BpfReJIT 总共新增 **2024 行**（14 个文件）。其中 kinsn 相关约：
- btf.c: ~240 行（kinsn_tab 注册/查找）
- verifier.c: ~400 行（lower/restore/check/build 等）
- bpf.h: ~50 行（struct bpf_kinsn 等）
- JIT: ~55 行（x86 + arm64 emit hook）
- UAPI: ~12 行（常量定义）
- 其他: ~20 行

kinsn 相关约 **~777 行**，占总新增的 38%。

### 6.2 统一后 diff 变化

统一到 kfunc 编码后：
- **不能删除**：btf.c 的 kinsn_tab（注册/查找机制不变）
- **不能删除**：verifier.c 的 lower/restore 机制（验证策略不变）
- **可以删除**：UAPI 中 `BPF_PSEUDO_KINSN_CALL` 常量定义（~4 行）
- **可以删除**：`bpf_pseudo_kinsn_call()` 函数（~4 行）
- **需要添加**：每个 kfunc 路径上的 kinsn_tab 守卫（~40-60 行）
- **需要添加**：JIT 中的 kinsn_tab 查找（每个架构 ~3-5 行，6 架构 ~30 行）

**净效果：删 ~8 行 + 增 ~70-90 行 = 净增 ~60-80 行**

这不仅没有减少代码量，反而增加了。而且引入了分散在 15+ 处的"这是 kinsn 还是 kfunc？"条件判断，增加了代码复杂度。

### 6.3 reviewer 视角

upstream reviewer 看到的会是：
1. kinsn 使用 kfunc 编码（src_reg=2），但不走 kfunc 验证路径
2. 每个 kfunc 处理点都有 `if (find_kinsn_desc(...))` 守卫
3. kinsn_tab 和 kfunc_tab 并行存在
4. verifier 的 lower/restore 机制完全独立于 kfunc 验证

reviewer 很可能会问："既然 kinsn 和 kfunc 的行为完全不同，为什么要共享编码？这只增加了混乱。"

---

## 7. 结论和建议

### 7.1 核心判断：**不建议统一编码**

原因排序：

1. **语义不兼容**：kfunc 是"调用内核函数"，kinsn 是"模块提供的指令替换"。两者的 IMM 字段含义（func_id vs var_id）、验证策略（check_kfunc_call vs lower/restore proof）、fixup 策略（地址替换 vs 保留原样）、JIT 策略（CALL 指令 vs 自定义机器码）全部不同。统一编码只能做到"共享 2-bit src_reg 值"，但所有后续处理都需要分开。

2. **代码量不减反增**：删除 `BPF_PSEUDO_KINSN_CALL` 只省 ~8 行，但需要在 15+ 处添加 kinsn_tab 守卫判断，净增 60-80 行。

3. **bug 风险极高**：每个 kfunc 处理点（verifier + fixup + JIT × 6 架构 + core + disasm）都需要正确处理"这可能是 kinsn"的情况。遗漏任何一处都是严重 bug。当前独立的 src_reg 值提供了简单、可靠的分发机制。

4. **上游接受性差**：reviewer 会看到一个更复杂、更混乱的设计，而不是更简洁的设计。

### 7.2 更好的替代方案

如果目标是"让 kinsn 看起来更像 kfunc"以减少审查阻力，建议考虑：

**方案 A：保持现状（推荐）**
- `BPF_PSEUDO_KINSN_CALL = 4` 是干净的、正交的设计
- 代码审查时可以清楚地解释："kinsn 是独立的指令替换机制，不是函数调用"
- 独立编码使得所有 dispatch 逻辑都是简单的 `if (src_reg == 4)`

**方案 B：把 kinsn 伪装成特殊 kfunc（不推荐但可行）**
- 为每个 kinsn 创建虚假的 BTF_KIND_FUNC（例如 `void bpf_rotate64(void)`）
- 注册到 kfunc_set_tab 中，带 KF_KINSN flag
- 在 verifier 和 JIT 中用 KF_KINSN 分流
- 问题：需要修改 BTF 生成、kfunc 注册、所有验证路径，工作量巨大

**方案 C：减少 kinsn 独立基础设施（渐进式）**
- 保留 `BPF_PSEUDO_KINSN_CALL` 编码
- 合并 `kinsn_tab` 到 `kfunc_tab`（在 kfunc_desc 中加 `is_kinsn` 标记）
- 这样 JIT 中只需查 kfunc_tab 一次，减少重复代码
- 但 verifier 路径仍然需要分开（lower/restore vs check_kfunc_call）

### 7.3 最终建议

**保持 `BPF_PSEUDO_KINSN_CALL = 4` 独立编码不变。** 当前设计在语义清晰度、代码安全性、维护便利性上都优于统一编码方案。如果上游 reviewer 质疑"为什么不用 kfunc"，可以用本文档的分析来解释两者的根本差异。

论文中应当强调：kinsn 不是"另一种 kfunc"，而是"模块提供的、经过形式化验证的指令替换"。这种语义差异决定了编码必须独立。

---

## 附录：引用的代码位置索引

| 代码位置 | 文件 | 行号 |
|----------|------|------|
| `BPF_PSEUDO_KFUNC_CALL` 定义 | `include/uapi/linux/bpf.h` | 1385 |
| `BPF_PSEUDO_KINSN_CALL` 定义 | `include/uapi/linux/bpf.h` | 1394 |
| `BPF_PSEUDO_KINSN_SIDECAR` 定义 | `include/uapi/linux/bpf.h` | 1390 |
| `struct bpf_kinsn` | `include/linux/bpf.h` | 968-979 |
| `struct bpf_kinsn_set` | `include/linux/bpf.h` | 986-990 |
| `bpf_kinsn_is_sidecar_insn()` | `include/linux/bpf.h` | 992-996 |
| `bpf_kinsn_sidecar_payload()` | `include/linux/bpf.h` | 998-1003 |
| `bpf_prog_aux.kinsn_tab` | `include/linux/bpf.h` | 1769 |
| `struct bpf_kinsn_region` | `include/linux/bpf_verifier.h` | 745-749 |
| `bpf_pseudo_kinsn_call()` | `kernel/bpf/verifier.c` | 275-278 |
| `add_kfunc_call()` | `kernel/bpf/verifier.c` | 3512-3604 |
| `add_kinsn_call()` | `kernel/bpf/verifier.c` | 3643-3678 |
| `fetch_kfunc_meta()` | `kernel/bpf/verifier.c` | 3449-3510 |
| `fetch_kinsn_desc_meta()` | `kernel/bpf/verifier.c` | 3607-3641 |
| `lower_kinsn_proof_regions()` | `kernel/bpf/verifier.c` | 3958-4039 |
| `restore_kinsn_proof_regions()` | `kernel/bpf/verifier.c` | 4042-4066 |
| `build_kinsn_inst_seq()` | `kernel/bpf/verifier.c` | 4080-4108 |
| `bpf_jit_get_kinsn_payload()` | `kernel/bpf/verifier.c` | 4111-4132 |
| `add_subprog_and_kfunc()` | `kernel/bpf/verifier.c` | 4149-4180 |
| `check_kfunc_call()` | `kernel/bpf/verifier.c` | 14632-15024 |
| `check_kinsn_sidecar_insn()` | `kernel/bpf/verifier.c` | 21576-21593 |
| `do_check_insn()` CALL 分支 | `kernel/bpf/verifier.c` | 21665-21700 |
| `fixup_call_args()` | `kernel/bpf/verifier.c` | 23637-23691 |
| `fixup_kfunc_call()` | `kernel/bpf/verifier.c` | 23760-23879 |
| `convert_ctx_accesses()` sidecar | `kernel/bpf/verifier.c` | 23967-23993 |
| `convert_ctx_accesses()` kinsn skip | `kernel/bpf/verifier.c` | 24304 |
| `bpf_jit_get_func_addr()` | `kernel/bpf/core.c` | 1278-1283 |
| `register_bpf_kinsn_set()` | `kernel/bpf/btf.c` | 9029-9089 |
| `unregister_bpf_kinsn_set()` | `kernel/bpf/btf.c` | 9092-9168 |
| `btf_try_get_kinsn_desc()` | `kernel/bpf/btf.c` | 9175-9191 |
| `emit_kinsn_desc_call()` (x86) | `arch/x86/net/bpf_jit_comp.c` | 579-607 |
| `do_jit()` kinsn dispatch (x86) | `arch/x86/net/bpf_jit_comp.c` | 2488-2493 |
| `emit_kinsn_desc_call_arm64()` | `arch/arm64/net/bpf_jit_comp.c` | 1195-1220 |
| `build_insn()` kinsn dispatch (arm64) | `arch/arm64/net/bpf_jit_comp.c` | 1628-1633 |
| daemon `BPF_PSEUDO_KINSN_CALL` | `daemon/src/insn.rs` | 60 |
| daemon `call_kinsn_with_off()` | `daemon/src/insn.rs` | 234-237 |
| daemon `kinsn_sidecar()` | `daemon/src/insn.rs` | 269-272 |
| daemon `emit_packed_kinsn_call_with_off()` | `daemon/src/passes/utils.rs` | 228-236 |
| daemon `KinsnRegistry` | `daemon/src/pass.rs` | 332-346 |
| daemon `discover_kinsns()` | `daemon/src/kfunc_discovery.rs` | 323 |
| `bpf_verifier_env` entry point | `kernel/bpf/verifier.c` | 26603 (add_subprog_and_kfunc) |
| lower before verifier | `kernel/bpf/verifier.c` | 26607 |
| restore after verifier | `kernel/bpf/verifier.c` | 26679 |
