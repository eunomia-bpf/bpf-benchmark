# Linux kfunc 机制与 `kinsn` 可行性调研

日期: 2026-03-20

范围:
- 内核源码: `vendor/linux-framework/`
- 重点文件:
  - `kernel/bpf/btf.c`
  - `include/linux/btf.h`
  - `include/linux/btf_ids.h`
  - `include/linux/bpf.h`
  - `include/linux/filter.h`
  - `include/uapi/linux/bpf.h`
  - `include/uapi/linux/bpf_common.h`
  - `kernel/bpf/verifier.c`
  - `kernel/bpf/core.c`
  - `arch/x86/net/bpf_jit_comp.c`
  - `tools/testing/selftests/bpf/test_kmods/bpf_testmod.c`

## TL;DR

结论先说:

1. `kfunc` 之所以能做成“模块可注册”，核心原因是它扩展的是“call target 集合”，不是 eBPF ISA。本质上它仍然复用现有 `BPF_JMP | BPF_CALL` 编码，只是把 `imm/off/src_reg` 解释为 BTF kfunc 元数据。
2. 现有 verifier 和 x86 JIT 的指令 dispatch 都是强耦合、硬编码、闭集合的。当前内核里没有任何类似 `register_new_bpf_opcode()` 的扩展点。
3. 因此，`kinsn` 如果想做成“kernel module 注册新 BPF 指令”，不能像 `kfunc` 一样只加一个薄注册 API。它至少需要改 core verifier、core opcode whitelist、core interpreter、每个目标架构 JIT 的主 dispatch。
4. 一个“原始回调版”接口

   ```c
   int (*verify)(struct bpf_verifier_env *, const struct bpf_insn *);
   int (*emit_x86)(struct jit_context *, const struct bpf_insn *);
   ```

   从工程上能做成 vendor-only 方案，但安全模型与 `kfunc` 完全不同: 这会把每个扩展模块都变成 verifier/JIT TCB 的一部分。
5. 如果要做，推荐的方向不是“任意新 opcode + 任意 verify 回调”，而是:
   - core 预留一个或两个 escape opcode
   - core 统一做 lookup/生命周期管理
   - phase 1 只允许 privileged + GPL + JIT-only
   - verifier 只允许有限语义类: 纯标量 ALU、简单 load/store、简单 branch
   - 复杂的 pointer/ref/lock/RCU 状态迁移仍然必须留在 core
6. 对 BpfReJIT 的近中期目标而言，更现实的低风险路径仍然是:
   - bytecode 层重写保持在现有 BPF ISA 内
   - 利用这个 vendor tree 里已经存在的 `jit_policy`/rewrite 入口做 native lowering
   - 把 `kinsn` 当作后续需要时再推进的 phase 2

## 1. kfunc 注册机制深度分析

### 1.1 静态声明与注册数据结构

`kfunc` 的声明不是直接注册函数指针，而是先把“函数的 BTF ID + flags”编进一个 `btf_id_set8`:

- `struct btf_kfunc_id_set` 定义在 `include/linux/btf.h:121-125`
  - `owner`: 所属模块
  - `set`: `struct btf_id_set8 *`
  - `filter`: 可选的 per-prog 过滤回调
- `struct btf_id_set8` 定义在 `include/linux/btf_ids.h:16-23`
  - 每个元素是 `{ id, flags }`
  - `flags` 可承载 `KF_ACQUIRE`、`KF_RELEASE`、`KF_SLEEPABLE` 等 kfunc 属性
- `BTF_KFUNCS_START/END` 宏在 `include/linux/btf_ids.h:212-216`
  - 本质是生成 `.BTF_ids` section 里的 `btf_id_set8`
  - `BTF_ID_FLAGS()` 在 `include/linux/btf_ids.h:67-72`

示例:

- `tools/testing/selftests/bpf/test_kmods/bpf_testmod.c:1225-1272` 定义了一个 module kfunc 集合
- `tools/testing/selftests/bpf/test_kmods/bpf_testmod.c:1303-1306` 把它包装成 `struct btf_kfunc_id_set`
- `tools/testing/selftests/bpf/test_kmods/bpf_testmod.c:1857-1861` 在 module init 里调用 `register_btf_kfunc_id_set()`

`__bpf_kfunc` 宏本身也只是帮助确保 kfunc 定义不会被优化掉或内联，见 `include/linux/btf.h:83-90`。

### 1.2 `register_btf_kfunc_id_set()` 具体做了什么

核心入口在 `kernel/bpf/btf.c:8930-8946`:

- 只接受 `BTF_SET8_KFUNCS` 标记过的 set
- 先把 `prog_type` 映射到一个 hook enum，见 `kernel/bpf/btf.c:8806-8850`
- 再进入 `__register_btf_kfunc_id_set()`，见 `kernel/bpf/btf.c:8903-8927`

`__register_btf_kfunc_id_set()` 的步骤:

1. 用 `btf_get_module_btf(kset->owner)` 拿到该 owner 对应的 BTF，`kernel/bpf/btf.c:8909-8913`
2. 对集合内每个函数做 prototype sanity check，`kernel/bpf/btf.c:8915-8919`
   - `btf_check_kfunc_protos()` 在 `kernel/bpf/btf.c:8621-8647`
   - 要求 `FUNC -> FUNC_PROTO`
   - 对 iter kfunc 额外检查 `KF_ITER_*`
3. 把集合合并进该 BTF 对象上的 `kfunc_set_tab`，`kernel/bpf/btf.c:8922`

`kfunc_set_tab` 本身挂在 `struct btf` 上:

- `enum btf_kfunc_hook` 在 `kernel/bpf/btf.c:209-225`
- `struct btf_kfunc_set_tab` 在 `kernel/bpf/btf.c:238-241`
- `struct btf` 中的 `kfunc_set_tab` 指针在 `kernel/bpf/btf.c:254-281`

`btf_populate_kfunc_set()` 是真正的合并逻辑，见 `kernel/bpf/btf.c:8652-8761`:

- vmlinux 可以为同一 hook 多次注册，最后合并成一个排序后的 set
- module set 同一 hook 重复注册会 `WARN_ON_ONCE` 并失败，`kernel/bpf/btf.c:8698-8705`
- module BTF ID 会经过 `btf_relocate_id()` 重定位，`kernel/bpf/btf.c:8745-8748`
- 每个 hook 最多 256 个条目，`kernel/bpf/btf.c:227-231`

这里的设计很关键: kfunc 注册是“往已有 BTF 对象上挂一份 allowlist + flags”，不是往 verifier/JIT 注册回调。

### 1.3 verifier 是怎么发现 kfunc 的

发现分两阶段:

#### 阶段 A: 预扫描，建立 kfunc 描述表

- verifier 主流程在 `kernel/bpf/verifier.c:26004-26010` 调用 `add_subprog_and_kfunc()`
- `add_subprog_and_kfunc()` 在 `kernel/bpf/verifier.c:3616-3644`
  - 遍历所有 insn
  - 如果遇到 `bpf_pseudo_kfunc_call(insn)` 就调用 `add_kfunc_call(env, insn->imm, insn->off)`

这里也可以看到 kfunc 不是新 opcode，而是已有 `CALL` 的一种 pseudo form:

- `bpf_pseudo_kfunc_call()` 在 `kernel/bpf/verifier.c:269-272`
- 实际编码要求在 `do_check_insn()` 里体现为:
  - `insn->code == (BPF_JMP | BPF_CALL)`
  - `insn->src_reg == BPF_PSEUDO_KFUNC_CALL`
  - `insn->off` 为 0 或 module BTF fd_array 偏移
  - 见 `kernel/bpf/verifier.c:21094-21131`

#### 阶段 B: 构造 `kfunc_tab` / `kfunc_btf_tab`

相关结构:

- `struct bpf_kfunc_desc` 在 `kernel/bpf/verifier.c:3173-3178`
- `struct bpf_kfunc_desc_tab` 在 `kernel/bpf/verifier.c:3187-3195`
- `struct bpf_kfunc_btf_tab` 在 `kernel/bpf/verifier.c:3197-3200`
- `bpf_prog_aux` 里存放它们，`include/linux/bpf.h:1741-1743`

`add_kfunc_call()` 在 `kernel/bpf/verifier.c:3432-3524`，它做了几件事:

1. 强制要求 JIT 和 GPL:
   - `jit_requested` 必须为真，`kernel/bpf/verifier.c:3452-3455`
   - `bpf_jit_supports_kfunc_call()` 必须支持，`kernel/bpf/verifier.c:3457-3460`
   - `gpl_compatible` 必须为真，`kernel/bpf/verifier.c:3462-3465`
2. 如果 `off != 0`，通过 `env->fd_array` 取 module BTF fd，见 `kernel/bpf/verifier.c:3268-3279`
3. 对 module BTF 调用 `btf_try_get_module()` 并把 module ref 保存在 `kfunc_btf_tab`，见 `kernel/bpf/verifier.c:3290-3300`
4. 调 `fetch_kfunc_meta()` 获取 BTF proto/flags/name，见 `kernel/bpf/verifier.c:3497`
5. 用 `kallsyms_lookup_name(kfunc.name)` 找地址，见 `kernel/bpf/verifier.c:3501-3505`
6. 用 `btf_distill_func_proto()` 生成 `btf_func_model` 存到 desc，见 `kernel/bpf/verifier.c:3513-3522`

对 module kfunc，`off` 的意义不是普通 branch offset，而是 `fd_array` 里的 module BTF 索引。这也是 kfunc 能“模块化扩展”但不需要新 ISA 的原因之一。

### 1.4 verifier 是怎么验证 kfunc call 的

入口在 `do_check_insn()`:

- `kernel/bpf/verifier.c:21098-21127`
- `BPF_CALL` 分成三类:
  - `BPF_PSEUDO_CALL` -> `check_func_call()`
  - `BPF_PSEUDO_KFUNC_CALL` -> `check_kfunc_call()`
  - 其他 helper -> `check_helper_call()`

#### 元数据获取

`check_kfunc_call()` 先调用 `fetch_kfunc_arg_meta()`:

- `kernel/bpf/verifier.c:14106-14110`
- `fetch_kfunc_arg_meta()` 在 `kernel/bpf/verifier.c:13880-13904`
  - 先 `fetch_kfunc_meta()`
  - 再检查 `kfunc.flags` 是否存在且 `btf_kfunc_is_allowed()` 为真

`fetch_kfunc_meta()` 在 `kernel/bpf/verifier.c:3369-3430`:

- 先按 `func_id + off` 找到对应 BTF
- 再从 `btf_kfunc_flags()` 取 flags，`kernel/bpf/verifier.c:3397`
- 对 `KF_IMPLICIT_ARGS` 这种情况，真实 proto 从 `_impl` 版本找，`kernel/bpf/verifier.c:3407-3414`

`btf_kfunc_is_allowed()` 在 `kernel/bpf/btf.c:8853-8871`:

- 先查 common hook
- 再查 prog-type-specific hook
- 同时执行注册时带上的 `filter` 回调，`kernel/bpf/btf.c:8784-8804`

#### 参数语义从哪里来

这部分是 kfunc 机制最重要、也最容易误判的点:

module 可以注册一个 kfunc，但 module 不能注册任意 verifier 逻辑。verifier 对 kfunc 的理解来自以下几类 core-owned 元信息:

1. `KF_*` flags
   - 定义在 `include/linux/btf.h:18-81`
2. BTF 函数原型
3. 参数名后缀约定
   - `__k`, `__sz`, `__szk`, `__nullable`, `__map`, `__alloc`, `__uninit`, `__irq_flag` 等
   - 识别逻辑在 `kernel/bpf/verifier.c:12221-12276`
   - 底层字符串匹配在 `kernel/bpf/btf.c:9728-9743`
   - 源码里明确写了 “In the future, this can be ported to use BTF tagging”，说明现在很多语义仍是命名约定，不是完整的类型系统
4. 参数是否是特定 vmlinux 类型
   - 例如 `struct bpf_dynptr` / `bpf_list_head` / `bpf_rb_root`
   - 见 `kernel/bpf/verifier.c:12311-12410`
5. 大量 `special_kfunc_list[]` 驱动的 core special cases

`check_kfunc_args()` 在 `kernel/bpf/verifier.c:13333-13877`，它会:

- 基于 BTF/后缀推导 `enum kfunc_ptr_arg_type`
  - 入口在 `kernel/bpf/verifier.c:12656-12758`
- 复用现有 verifier helper 检查:
  - `check_reg_arg()`
  - `check_func_arg_reg_off()`
  - `check_mem_reg()`
  - `process_dynptr_func()`
  - `process_spin_lock()`
  - `process_kf_arg_ptr_to_*()`
- 跟踪引用对象、锁、dynptr、iter、graph node/root 等复杂状态

#### call 语义验证与返回值建模

`check_kfunc_call()` 主体在 `kernel/bpf/verifier.c:14088-14480`。它做的不只是“参数类型匹配”，还直接操作 verifier abstract state:

- sleepable/RCU/preempt/IRQ 上下文检查，`kernel/bpf/verifier.c:14147-14261`
- release kfunc 触发 `release_reference()`，`kernel/bpf/verifier.c:14263-14279`
- graph/refcount 等特殊对象的 owning/non-owning 转换，`kernel/bpf/verifier.c:14281-14300`
- `bpf_throw`、callback-calling kfunc 等控制流相关行为，`kernel/bpf/verifier.c:14167-14199`, `14302-14317`
- 根据返回 BTF 类型更新 `R0` 的 reg state，`kernel/bpf/verifier.c:14327-14444`

尤其要注意:

- `check_special_kfunc()` 在 `kernel/bpf/verifier.c:13911-14083`
- 一上来就有:

  ```c
  if (meta->btf != btf_vmlinux)
      return 0;
  ```

  即 `kernel/bpf/verifier.c:13918-13919`

这意味着:

- module kfunc 只能享受“generic kfunc verifier semantics”
- 真正复杂的 alloc/refcount/graph/cast/dynptr slice 等特殊状态迁移逻辑，只存在于 core 针对 vmlinux special kfunc 的硬编码里

这也是为什么 `kfunc` 不能直接类比成“模块可注册新 verifier 语义”。

### 1.5 kfunc 是怎么被 JIT 编译的

这里也有一个关键结论:

对 x86-64 来说，kfunc 没有独立的 JIT 指令分派路径。它在 verifier fixup 之后，基本被当成普通 `CALL` 处理。

#### fixup 阶段

`fixup_kfunc_call()` 在 `kernel/bpf/verifier.c:23184-23295`:

- 找到之前建立的 `kfunc_desc`
- 根据 `desc->addr` 回填 call immediate，`kernel/bpf/verifier.c:23197-23214`
- 对少数 special kfunc 额外插入 `LD_IMM64` / `MOV` / inline sequence
  - 例如 `bpf_obj_new_impl`、`bpf_obj_drop_impl`、graph insert、`bpf_session_*`

`do_misc_fixups()` 里真正把 patch 写回 program，见 `kernel/bpf/verifier.c:23696-23714`。

#### x86 JIT 阶段

x86 主循环在 `arch/x86/net/bpf_jit_comp.c:3187-3290`，之后直接 `switch (insn->code)`。

`CALL` case 在 `arch/x86/net/bpf_jit_comp.c:4001-4019`:

- `func = (u8 *)__bpf_call_base + imm32`
- 调 `emit_call(&prog, func, ip)`

x86-64 这里并不区分 helper vs kfunc。对它来说，kfunc 已经在 verifier fixup 后变成“一个普通可调用内核地址”。

补充:

- `bpf_jit_supports_kfunc_call()` 在 x86 返回 true，`arch/x86/net/bpf_jit_comp.c:5548-5551`
- `bpf_jit_supports_far_kfunc_call()` 没有 x86 override，默认 false，`kernel/bpf/core.c:3212-3215`
- 也就是说 x86 依赖 verifier 预先把 `imm` fix 成相对 `__bpf_call_base` 的 immediate，而不是在 JIT 时重新查 kfunc 地址

### 1.6 kfunc 生命周期与 module load/unload

这是 kfunc 机制最像 `kinsn` 可以复用的部分。

#### BTF 生命周期

module BTF 由 module notifier 管理:

- `btf_module_notify()` 在 `kernel/bpf/btf.c:8294-8398`
- `MODULE_STATE_COMING`:
  - parse module BTF
  - 分配 BTF ID
  - 放进 `btf_modules` 链表
- `MODULE_STATE_LIVE`:
  - 设置 `BTF_MODULE_F_LIVE`，`kernel/bpf/btf.c:8368-8377`
- `MODULE_STATE_GOING`:
  - 从链表摘掉
  - `btf_put()`
  - 移除 sysfs 节点

`btf_try_get_module()` 在 `kernel/bpf/btf.c:8414-8438`:

- 只对 `BTF_MODULE_F_LIVE` 的模块做 `try_module_get()`
- 所以 verifier/JIT 不会对尚未 fully live 的模块建立依赖

#### BPF program 对 module 的持有

对 module kfunc，verifier 在解析 BTF fd 时会:

- `btf_try_get_module(btf)`，`kernel/bpf/verifier.c:3290-3294`
- 把 `module` 与 `btf` 一起保存到 `prog->aux->kfunc_btf_tab`，`kernel/bpf/verifier.c:3296-3300`

释放路径:

- `bpf_free_kfunc_btf_tab()` 在 `kernel/bpf/verifier.c:3313-3323`
  - 对每个 desc 做 `module_put()` 和 `btf_put()`
- `bpf_prog_free_deferred()` 会调它，`kernel/bpf/core.c:2984-2993`

另外 `btf_kfunc_flags()` 的注释也明确要求 verifier 调用时必须持有对应 module ref，见 `kernel/bpf/btf.c:8873-8879`。

#### 是否存在 unregister API

源码里有:

- `register_btf_kfunc_id_set()`，`kernel/bpf/btf.c:8930-8946`
- `register_btf_fmodret_id_set()`，`kernel/bpf/btf.c:8948-8953`

但没有对应的 `unregister_btf_kfunc_id_set()`。

这意味着 kfunc 当前模型是:

- 注册只在 initcall/module init 做
- 不支持运行时撤销单个 kfunc set
- module unload 依赖 module refcount 阻止仍被 BPF program 使用的模块退出

selftest 也体现了这个模式:

- `tools/testing/selftests/bpf/test_kmods/bpf_testmod.c:1893-1910` 的 exit path 没有 unregister kfunc set
- 它只是在退出前等待相关引用下降

## 2. verifier 的指令 dispatch 分析

### 2.1 现有 verifier 是闭集合 dispatch

verifier 对 opcode 的第一层白名单在 `bpf_opcode_in_insntable()`:

- `kernel/bpf/core.c:1651-1812` 枚举了 public opcode table
- `kernel/bpf/verifier.c:21879-21883` 在 verifier 早期就拒绝未知 opcode

这一步本身就意味着:

- 任何新指令首先必须改 core opcode 白名单
- 单靠 module 无法把新 opcode 放进 verifier pipeline

### 2.2 `do_check()` 与 `do_check_insn()`

主循环:

- `kernel/bpf/verifier.c:21200-21340`

真正的单条指令 dispatch:

- `kernel/bpf/verifier.c:21032-21195`

结构非常直接:

- `ALU/ALU64` -> `check_alu_op()`
- `LDX` -> `check_load_mem()`
- `STX` -> `check_atomic()` or `check_store_reg()`
- `ST` -> `check_mem_access()`
- `JMP/JMP32` -> `check_func_call()` / `check_kfunc_call()` / `check_helper_call()` / `check_cond_jmp_op()`
- `LD` -> `check_ld_abs()` / `check_ld_imm()`
- 其他 class -> reject

没有任何 “prog type verifier ops 可以注册新 instruction verifier” 的接口。

### 2.3 instruction semantics 与 abstract state 的耦合程度

耦合非常高，且不是“validate then pass-through”模式，而是“validate + mutate abstract machine state”模式。

几个代表性例子:

#### `check_alu_op()`

- `kernel/bpf/verifier.c:16332-16572`
- 对 opcode 做闭集合判断:
  - `opcode == BPF_END || opcode == BPF_NEG`
  - `opcode == BPF_MOV`
  - `opcode > BPF_END` 直接无效，`kernel/bpf/verifier.c:16520-16523`
- 同时更新:
  - scalar bounds
  - var_off/tnum
  - subreg/zext state
  - pointer arithmetic legality

#### `check_cond_jmp_op()`

- `kernel/bpf/verifier.c:17449-17704`
- 对 branch 做:
  - reserved-field check
  - pointer compare legality
  - `is_branch_taken()` 预测
  - `push_stack()` 分叉 verifier state
  - `reg_set_min_max()` 细化两边的范围
  - nullness propagation
  - packet pointer special handling

这不是一个 module callback 能轻易接入的简单框架。新 branch 指令如果改变控制流，就必须接进这整套 state split/refinement 逻辑。

#### `check_ld_imm()`, `check_load_mem()`, `check_store_reg()`, `check_atomic()`

这些路径分别耦合了:

- map pointer / map value provenance
- stack slot state
- context access rules
- pointer type/offset bounds
- memory access size/alignment/fault model

也就是说 verifier 不是“每条指令一个独立 validator”，而是一个统一 abstract interpreter。

### 2.4 现有 extension point 有哪些

现有 `struct bpf_verifier_ops` 在 `include/linux/bpf.h:1099-1124`，只提供:

- `get_func_proto`
- `is_valid_access`
- `gen_prologue` / `gen_epilogue`
- `gen_ld_abs`
- `convert_ctx_access`
- `btf_struct_access`

这些都是:

- helper 选择
- ctx field access
- prologue/epilogue 生成

没有 per-insn verifier callback。

另一个“钩子”是 offload:

- `kernel/bpf/verifier.c:21289-21293` 会调用 `bpf_prog_offload_verify_insn()`

但这不是通用 ISA 扩展点，它也没有替代 core abstract-state engine。

### 2.5 对 `kinsn` 的直接结论

当前 verifier 没有可供 module 注册“新指令验证逻辑”的扩展点。

如果要支持 `kinsn`，至少要新增以下 core 接口中的一个:

方案 A: 中央 escape dispatch

- 在 `do_check_insn()` 最前面加:

  ```c
  if (bpf_is_ext_insn(insn))
      return check_ext_insn(env, insn, &env->insn_idx);
  ```

- `check_ext_insn()` 再做 registry lookup

方案 B: 每个 class 下加 sub-dispatch

- 比如在 `check_alu_op()` 里保留 `BPF_EXT_ALU`
- 在 `check_cond_jmp_op()` 里保留 `BPF_EXT_JMP`

我更倾向方案 B，因为当前 verifier 的状态迁移高度 class-specific。

## 3. JIT 指令 dispatch 分析

### 3.1 x86 JIT 同样是闭集合 switch

x86 主 JIT 在:

- `arch/x86/net/bpf_jit_comp.c:3187-3290`
- 然后进入 `switch (insn->code)`，`arch/x86/net/bpf_jit_comp.c:3290`

最终 default 分支:

- `arch/x86/net/bpf_jit_comp.c:4255-4263`

直接报:

```c
pr_err("bpf_jit: unknown opcode %02x\n", insn->code);
return -EINVAL;
```

这和 verifier 一样，是闭集合。

### 3.2 为什么 draft 里的 `emit_x86(struct jit_context *, insn)` 不够

你给的接口草案里这部分太乐观了。原因有三个:

#### 1. `struct jit_context` 不是 public ABI

x86 的 `struct jit_context` 是 file-local 的 static struct:

- `arch/x86/net/bpf_jit_comp.c:318-330`

它根本不在公共头文件里。模块没法直接安全地依赖它。

#### 2. 真正的 emit 依赖的不只是 `jit_context`

x86 `do_jit()` 里每条指令的 emit 依赖大量局部状态:

- `prog`
- `addrs`
- `image`
- `rw_image`
- `oldproglen`
- `extable`
  `num_exentries`
- 当前 pass 是否在做 jump padding/convergence
- `priv_frame_ptr`
- `callee_regs_used`

这些都在 `do_jit()` 的局部变量里，见 `arch/x86/net/bpf_jit_comp.c:3187-3267`。

因此一个可工作的接口至少需要区分:

- size estimation / pass 1
- real emission / final pass
- extable population
- branch target accounting

#### 3. 很多 helper emitter 也是 static 的

x86 JIT 大量关键 helper 都是 static:

- `emit_call()`，`arch/x86/net/bpf_jit_comp.c:584-596`
- `emit_ldx()` / `emit_stx()` / `emit_atomic_*()` 等

如果想让 module emitter 重用它们，要么导出一大批 arch-private helper，要么再包一层公共 JIT extension API。

### 3.3 x86 是否存在现成的“扩展点”

在这个 vendor tree 里，x86 JIT 确实有一个额外入口:

- `has_active_rules` 检查在 `arch/x86/net/bpf_jit_comp.c:3197`
- `bpf_jit_apply_prog_rule()` 调用在 `arch/x86/net/bpf_jit_comp.c:3276-3287`

这个机制来自本仓库已有的 `jit_policy` / `jit_directives` 系统，不是 upstream kfunc 机制的一部分。

它的特点:

- 是“rewrite existing verified instruction sequence”
- 不是“注册新 opcode”
- 仍然发生在主 switch 之前

这很适合 BpfReJIT 这类 native rewrite 项目，但它不能证明“模块注册新指令 emitter”已经有现成基础设施。

### 3.4 如果 `kinsn` 要做 JIT 扩展，需要什么

最少需要:

1. core 保留一个 ext opcode 或 ext class
2. 每个 arch 有一个 ext registry
3. 每个 ext 至少有两阶段 API:
   - `estimate()`
   - `emit()`
4. 需要把 owner/module ref 固化到 `prog->aux`
5. 如果可能 fault 或生成 extable，还要让 emitter 能访问 extable writer

也就是说，真正需要的更像:

```c
struct bpf_ext_jit_ctx_x86 {
	u8 **prog;
	int *addrs;
	u8 *image;
	u8 *rw_image;
	int insn_idx;
	bool final_pass;
	struct exception_table_entry *extable;
	u32 num_exentries;
	void *arch_ctx;
};

struct bpf_ext_arch_ops_x86 {
	int (*estimate)(struct bpf_ext_jit_ctx_x86 *ctx,
			const struct bpf_insn *insn);
	int (*emit)(struct bpf_ext_jit_ctx_x86 *ctx,
		    const struct bpf_insn *insn);
};
```

而不是单个 `emit_x86(jit_context, insn)`。

## 4. opcode 空间余量分析

### 4.1 `struct bpf_insn.code` 只有 8 bit

编码拆分在 `include/uapi/linux/bpf_common.h`:

- class: `BPF_CLASS(code)`, `include/uapi/linux/bpf_common.h:5-14`
- size: `BPF_SIZE(code)`, `include/uapi/linux/bpf_common.h:16-21`
- mode: `BPF_MODE(code)`, `include/uapi/linux/bpf_common.h:22-28`
- op: `BPF_OP(code)`, `include/uapi/linux/bpf_common.h:30-48`
- src bit: `BPF_SRC(code)`, `include/uapi/linux/bpf_common.h:49-51`

结论:

- 没有“空闲 class 空间”
- 可用余量只存在于某些 op nibble 或保留字段组合里

### 4.2 当前 public opcode 白名单是什么

最直接的答案在:

- `kernel/bpf/core.c:1651-1812`

这个表基本把公开允许的 eBPF opcode 全枚举了一遍。

从这个表和 verifier/JIT 的 reject 逻辑看:

- `ALU/ALU64`:
  - `0xe0` / `0xf0` 没被现有 ALU opcode 占用
  - `check_alu_op()` 直接把 `opcode > BPF_END` 判成非法，`kernel/bpf/verifier.c:16520-16523`
- `JMP/JMP32`:
  - `0xe0` 已被 `BPF_JCOND` 用掉，见 `include/uapi/linux/bpf.h:45`
  - `0xf0` 仍然是洞
  - `check_cond_jmp_op()` 把 `opcode > BPF_JCOND` 判成非法，`kernel/bpf/verifier.c:17464-17468`
- `LDX/ST/STX`:
  - 还有一些保留 `mode/size` 组合，但语义上更碎片化

所以:

- 可以挖洞
- 但没有一整段“干净 opcode range”

### 4.3 对 `kinsn` 的编码建议

如果真做，我不建议“module 直接占用任意 opcode”。

更现实的做法是 core 预留 escape opcode:

- 非 branch 类扩展:
  - 从 ALU/ALU64 的空洞里保留一个
- branch 类扩展:
  - 从 JMP/JMP32 的 `0xf0` 保留一个

例如:

```c
#define BPF_EXT_ALU   0xe0   /* 现有 ALU hole */
#define BPF_EXT_JMP   0xf0   /* 现有 JMP hole */
```

这样改动范围可控:

- verifier 只需在对应 class 的 switch 中插入 ext dispatch
- JIT 也只需在对应 class 的 switch 中插入 ext emit

而不是让 module 去管理整个稀缺 opcode 空间。

## 5. `kinsn` 接口设计草案

### 5.1 先说不推荐的版本

最接近题目里的版本是:

```c
struct bpf_insn_extension {
	u8 opcode;
	const char *name;
	int (*verify)(struct bpf_verifier_env *, const struct bpf_insn *);
	int (*emit_x86)(void *arch_ctx, const struct bpf_insn *);
	int (*emit_arm64)(void *arch_ctx, const struct bpf_insn *);
	int (*interpret)(const struct bpf_insn *, u64 *regs);
	struct module *owner;
};
```

问题:

1. `opcode` 空间并不干净
2. `verify(env, insn)` 让 module 直接操作 verifier internals，安全边界过大
3. `emit_x86()` 缺少 size/pass/extable/addrs/image 等上下文
4. 现有 verifier/JIT helper 大多是 static，模块没法复用

所以它只适合“完全 vendor-private，且接受 extension module 进入 TCB”的方案。

### 5.2 推荐的受限版本

我建议把它做成“core-owned extension framework”，模块只提供有限语义和 emitter。

#### 编码

- 保留 1-2 个 escape opcode
- 指令里编码 `ext_id`
- 复杂 immediate 需求用 wide form 解决

#### verifier 侧

```c
enum bpf_ext_sem_class {
	BPF_EXT_SEM_SCALAR_UNARY,
	BPF_EXT_SEM_SCALAR_BINARY,
	BPF_EXT_SEM_LOAD,
	BPF_EXT_SEM_STORE,
	BPF_EXT_SEM_BRANCH,
};

struct bpf_ext_verifier_ops {
	enum bpf_ext_sem_class sem_class;
	u64 flags; /* PRIV_ONLY, GPL_ONLY, JIT_ONLY, MAY_FAULT, MAY_BRANCH ... */
	int (*check)(struct bpf_ext_verifier_ctx *ctx,
		     const struct bpf_insn *insn);
	int (*transfer)(struct bpf_ext_verifier_ctx *ctx,
			const struct bpf_insn *insn);
};
```

其中:

- `bpf_ext_verifier_ctx` 不应该裸露整个 `struct bpf_verifier_env`
- core 只暴露受限 helper
- phase 1 只允许纯标量和简单 mem/branch 语义
- pointer/ref/lock/RCU 相关扩展不允许模块自定义

#### JIT 侧

```c
struct bpf_ext_jit_ctx_x86 {
	u8 **prog;
	int *addrs;
	u8 *image;
	u8 *rw_image;
	int insn_idx;
	bool final_pass;
	void *arch_ctx;
	struct exception_table_entry *extable;
	u32 num_exentries;
};

struct bpf_ext_arch_ops_x86 {
	int (*estimate)(struct bpf_ext_jit_ctx_x86 *ctx,
			const struct bpf_insn *insn);
	int (*emit)(struct bpf_ext_jit_ctx_x86 *ctx,
		    const struct bpf_insn *insn);
};
```

#### 总体注册对象

```c
struct bpf_insn_ext {
	u16 ext_id;
	const char *name;
	u64 prog_type_mask;
	u64 flags;
	struct module *owner;
	btf_kfunc_filter_t filter;

	const struct bpf_ext_verifier_ops *vops;
	const struct bpf_ext_arch_ops_x86 *x86;
	const struct bpf_ext_arch_ops_arm64 *arm64;

	int (*interpret)(struct bpf_ext_interp_ctx *ctx,
			 const struct bpf_insn *insn); /* optional */
};

int register_bpf_insn_ext(const struct bpf_insn_ext *ext);
```

#### 生命周期

要完全复用 kfunc 的思路:

- verifier 在 program load 时，把用到的 ext desc/module ref 固化到 `prog->aux->kinsn_tab`
- `bpf_prog_free_deferred()` 释放时 `module_put()`
- 不提供 unregister API

也就是说，应该做一个和 `kfunc_btf_tab` 对称的新表。

### 5.3 phase 1 约束建议

如果目标是给 BpfReJIT 提供更稳的“bytecode 层新原语”，我建议 phase 1 只支持:

- rotate / funnel shift / bit extract / byte swap 变体
- 简单 widen/narrow move
- 对现有 `check_mem_access()` 可表达的 load/store 变体
- 不分配对象
- 不引入新 pointer type
- 不改变 refcount/lock/RCU state
- 不调用 callback
- 不睡眠

这样 verifier 可复用现有 abstract state machinery，而不是把它开放给模块。

## 6. 关键障碍和风险

### 6.1 verifier 抽象状态机是否能“通用化”到任意新指令

对通用新指令，答案基本是否定的。

原因不是“检查代码太多”，而是状态空间本身复杂:

- reg type lattice
- scalar bounds + tnum
- stack slot type
- dynptr/iter state
- reference objects
- active lock/preempt/RCU/IRQ state
- packet pointer range refinement

这些都散落在 `check_alu_op()`、`check_cond_jmp_op()`、`check_kfunc_call()`、`check_load_mem()`、`check_store_reg()` 等 core 函数里。

所以:

- “任意 `verify()` 回调”从表达力上是足够的
- 但从安全模型上几乎等于“把 verifier 拆成插件”

我认为 upstream 不会接受这种模型。vendor-only 可以做，但要明确这是把扩展模块纳入 verifier TCB，而不是 `kfunc` 那种较轻扩展。

### 6.2 opcode 空间是否足够

够做 escape，不够做一个宽松的新 ISA namespace。

现状更像:

- 没有空 class
- ALU 有两个 hole
- JMP 有一个 hole
- load/store 里还有碎片化 reserved combo

因此如果真做，应该保留“一个 escape opcode + ext_id”，而不是让每个模块申请原生 opcode。

### 6.3 module unload 怎么办

这个问题反而是最好解决的，kfunc 已经给了成熟模式:

- load 时 `try_module_get(owner)`
- 把 owner 记进 `prog->aux`
- prog free 时 `module_put(owner)`
- 不支持 unregister

这和 kfunc 一样能阻止“仍有程序使用自定义指令但模块先卸载”的情况。

### 6.4 安全性: module `verify()` bug 会不会破坏 verifier 保证

会。

而且这是 `kinsn` 与 `kfunc` 的根本区别。

`kfunc` 模块今天能做的事是:

- 注册一批可调用目标
- 提供 flags/filter/BTF proto

但真正决定 verifier abstract state 的逻辑仍在 core 里。

`kinsn` 如果允许模块提供 `verify()`:

- 模块就可以错误地把 pointer 变成 safe scalar
- 错误地漏掉 ref release
- 错误地放宽 branch range
- 错误地允许越界 mem access

因此它不只是“另一个注册 API”，而是“可插拔 verifier”。

我的判断:

- vendor internal, privileged-only: 可以接受，但要把扩展模块当成 kernel TCB
- 想保持 `kfunc` 那种安全边界: 不能接受，必须改成 declarative/受限语义

### 6.5 JIT 多架构负担

`kfunc` 的 JIT 成本很低，因为它最终只是 call。

`kinsn` 的 JIT 成本高很多，因为每个新指令都要:

- 每个目标 arch 都有 emitter
- 参与 code size convergence
- 可能参与 extable/fault model
- 可能参与 branch target accounting
- 可能参与 JIT recompile/policy machinery

所以即使 phase 1 只做 x86，也要在 verifier 里明确:

- `JIT_ONLY`
- `x86_only`
- 不支持 interpreter/offload

否则系统行为会很难定义。

### 6.6 interpreter / tooling / offload 风险

如果不是 JIT-only，还得改:

- interpreter opcode table 和 dispatch
  - `bpf_opcode_in_insntable()` / interpreter unknown opcode 路径见 `kernel/bpf/core.c:1795-1815`, `2363-2372`
- bpftool disassembler
- libbpf / loader pretty-printer
- 任何 offload backend

这又进一步说明: `kinsn` 的合理 phase 1 只能是 privileged + JIT-only。

## 7. 最终判断与建议

### 7.1 “能不能做”

能，但分两种含义:

#### 含义 A: 不改 core，只靠 module 像 kfunc 一样注册

不能。

原因:

- verifier 没有新指令 hook
- JIT 没有新指令 hook
- opcode whitelist 是闭集合
- interpreter 也是闭集合

#### 含义 B: 改 core，做一个 vendor-only `kinsn` 子系统

能。

但前提是承认:

- 这不是 `kfunc` 的自然推广
- 这是一个新 verifier/JIT extension subsystem

### 7.2 “是否值得做”

如果目标是尽快替换当前“改 emitter + 自写 2000 行 validator”的路线，我的建议是:

1. 近中期不要先做通用 `kinsn`
2. 优先继续把 bytecode rewrite 保持在现有 BPF ISA 内
3. 在这个 vendor tree 上优先利用已有 `jit_policy` / rewrite 入口
4. 只有当确实需要“现有 BPF ISA 无法表达、且 native lowering 收益很大”的原语时，再做受限版 `kinsn`

### 7.3 如果要立项，建议的最小可行范围

我会建议下面这个 MVP:

1. 只支持 x86-64
2. 只支持 privileged + GPL + JIT-only program
3. 只保留 1 个 ALU escape opcode
4. 只支持 pure-scalar ext ops
5. verifier 不允许模块直接碰 pointer/ref/lock/RCU state
6. module lifetime 完全复用 kfunc 模式
7. 不做 unregister
8. 不做 offload
9. 不做 userspace source-level toolchain 集成，由 daemon 直接构造 bytecode

如果这个 MVP 跑通，再考虑:

- load/store ext ops
- branch ext ops
- arm64 emitter

## 8. 一句话总结

`kfunc` 可以模块化，是因为它扩展的是“被调用的内核对象”；`kinsn` 如果要模块化，扩展的是“verifier/JIT 的核心语义”。前者是 allowlist 问题，后者是 abstract machine 问题。两者不在同一复杂度层级。
