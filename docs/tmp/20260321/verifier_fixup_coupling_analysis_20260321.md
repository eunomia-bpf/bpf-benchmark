# BPF verifier `do_check` / fixup 耦合分析（Linux 7.0-rc2）

结论先行：对“当前 live 程序里最终 xlated 的 `prog->insnsi`”来说，答案是 **4C**。  
`do_check()` 不是面向最终 xlated 指令流设计的；它面向的是一个更早的 verifier IR：

- 已经过 `resolve_pseudo_ldimm64()` 预解析；
- 但还没经过 `convert_ctx_accesses()`；
- 还没经过 `do_misc_fixups()`；
- 还没经过 `fixup_call_args()`；
- 也还没经过最终的 `convert_pseudo_ld_imm64()`。

所以：

- **不能** 直接把 live xlated bytecode 再喂给现有 verifier；
- 真正可行的方案不是“让 verifier 直接吃最终 xlated”，而是保存一份 **pre-fixup verifier IR**，或者继续保存原始 bytecode。

---

## 1. `bpf_check()` 的完整阶段顺序

`bpf_check()` 定义在 `kernel/bpf/verifier.c:26025`。

### 1.1 `do_check()` 之前

调用顺序按 `bpf_check()` 里的实际代码如下：

| 顺序 | 阶段 | 调用点 |
|---|---|---|
| 1 | `process_fd_array(env, attr, uattr)` | `26083-26085` |
| 2 | `check_btf_info_early(env, attr, uattr)` | `26117-26119` |
| 3 | `add_subprog_and_kfunc(env)` | `26121-26123` |
| 4 | `check_subprogs(env)` | `26125-26127` |
| 5 | `check_btf_info(env, attr, uattr)` | `26129-26131` |
| 6 | `resolve_pseudo_ldimm64(env)` | `26133-26135` |
| 7 | `bpf_prog_offload_verifier_prep(env->prog)` | `26137-26140` |
| 8 | `check_cfg(env)` | `26143-26145` |
| 9 | `compute_postorder(env)` | `26147-26149` |
| 10 | `bpf_stack_liveness_init(env)` | `26151-26153` |
| 11 | `check_attach_btf_id(env)` | `26155-26157` |
| 12 | `compute_scc(env)` | `26159-26161` |
| 13 | `compute_live_registers(env)` | `26163-26165` |
| 14 | `mark_fastcall_patterns(env)` | `26167-26169` |
| 15 | `do_check_main(env)` | `26171` |
| 16 | `do_check_subprogs(env)` | `26172` |

其中：

- `do_check_main()` 在 `24843-24852`，实际先进入 `do_check_common(env, 0)`。
- `do_check_subprogs()` 在 `24793-24840`，逐个 global subprog 调 `do_check_common()`。
- `do_check_common()` 在 `24643-24770`，负责初始化 verifier state / 参数寄存器，再调用真正的 `do_check()`（`24765`）。
- `do_check()` 本体在 `21315-21487`。

### 1.2 `do_check()` 本身做什么

`do_check()` 是 verifier 的状态搜索主循环：

- 逐条取 `env->prog->insnsi[env->insn_idx]`（`21339-21340`）；
- 做 pruning / visited-state 检查（`21352-21369`）；
- 处理日志、offload 检查、栈写标记（`21383-21423`）；
- 每条指令实际由 `do_check_insn()` 验证（`21423`）；
- 分支、exit、回溯由 `process_bpf_exit` 路径统一处理（`21466-21484`）。

也就是说，**语义验证核心在 `do_check_insn()` + 它调用的 `check_*()` 家族**，而不是 fixup pass。

### 1.3 `do_check()` 之后

`do_check()` 结束后，在 `bpf_check()` 中的顺序是：

| 顺序 | 阶段 | 调用点 |
|---|---|---|
| 1 | `bpf_prog_offload_finalize(env)` | `26174-26175` |
| 2 | `remove_fastcall_spills_fills(env)` | `26183-26184` |
| 3 | `check_max_stack_depth(env)` | `26186-26187` |
| 4 | `optimize_bpf_loop(env)` | `26189-26191` |
| 5 | dead code pass / sanitize pass | `26193-26203` |
| 6 | `convert_ctx_accesses(env)` | `26205-26207` |
| 7 | `do_misc_fixups(env)` | `26209-26210` |
| 8 | `opt_subreg_zext_lo32_rnd_hi32(env, attr)` | `26215-26218` |
| 9 | `fixup_call_args(env)` | `26221-26222` |
| 10 | `convert_pseudo_ld_imm64(env)` | `26272-26276` |

关键注释就在 `26189-26191`：

```c
/* instruction rewrites happen after this point */
if (ret == 0)
    ret = optimize_bpf_loop(env);
```

所以 **fixup 明确是在 `do_check()` 之后**，但要注意：`resolve_pseudo_ldimm64()` 是唯一一个在 `do_check()` 之前做的“预解析”。

---

## 2. `do_check()` 对指令格式的假设

## 2.1 `BPF_CALL` helper call

`do_check_insn()` 对 call 的分派在 `21213-21243`：

- `src_reg == BPF_PSEUDO_CALL` -> `check_func_call()`（`21235-21236`）
- `src_reg == BPF_PSEUDO_KFUNC_CALL` -> `check_kfunc_call()`（`21237-21238`）
- 否则 -> `check_helper_call()`（`21241-21242`）

`check_helper_call()` 明确把 `insn->imm` 当 helper ID 用：

- `func_id = insn->imm;`（`11747-11749`）
- `get_helper_proto(env, insn->imm, &fn)`（`11749`）
- 找不到会报 `invalid func ...`（`11750-11752`）

而 post-fixup 之后 helper call 的 `imm` 已经不是 helper ID，而是 call immediate：

- 通用 helper patch：`insn->imm = fn->func - __bpf_call_base;`（`24333-24345`）
- map op helper patch：`insn->imm = BPF_CALL_IMM(ops->...)`（`24050-24077`）
- interpreter/JIT 执行时实际按 `__bpf_call_base + insn->imm` 调用（`kernel/bpf/core.c:2040-2041`）

所以这里需要澄清一点：**严格说不是“绝对 kernel 地址”，而是相对 `__bpf_call_base` 的 call immediate**。  
但无论如何，它**已经不是 helper ID**，因此现有 `do_check()` 直接吃 xlated helper call 会在 `get_helper_proto()` 这里失败。

结论：**helper call 绝对不能直接用最终 xlated 重新 verify。**

## 2.2 `BPF_CALL` kfunc call

`do_check()` 区分 kfunc call 的唯一标志就是 `src_reg == BPF_PSEUDO_KFUNC_CALL`（`21215-21219`, `21237-21238`）。

`check_kfunc_call()` 直接把 `insn->imm` / `insn->off` 当作 kfunc 元数据 key：

- `fetch_kfunc_arg_meta(env, insn->imm, insn->off, &meta);`（`14221`）
- `fetch_kfunc_arg_meta()` 形参本身就是 `func_id` / `offset`（`13995-14003`）

而且甚至在 `do_check()` 之前，`add_subprog_and_kfunc()` 就已经扫描 pseudo kfunc call，并调用：

- `add_kfunc_call(env, insn->imm, insn->off)`（`3742-3755`）

`add_kfunc_call()` 也把它当 `func_id` / `offset` 处理，并通过 `fetch_kfunc_meta()` 建 kfunc desc（`3566-3591`）。

### `fixup_kfunc_call()` 会不会清 `src_reg`？

不会。  
`fixup_kfunc_call()` 本体在 `23297-23435`，只看到它：

- 查 desc：`find_kfunc_desc(env->prog, insn->imm, insn->off)`（`23314-23319`）
- 必要时把 `imm` 改成 `BPF_CALL_IMM(desc->addr)`（`23325-23326`）
- 然后可能额外插入 wrapper / inline 序列（`23328-23434`）

**没有任何地方把 `insn->src_reg` 清零。**

### 这意味着什么？

- 对非 far-kfunc-call 架构，fixup 后 `src_reg` 还保留 `BPF_PSEUDO_KFUNC_CALL`，但 `imm` 已经不再是原始 BTF func_id，而是 call immediate（`23325-23326`）。
- 对 far-kfunc-call 架构，desc 的 `imm` 会保持 `func_id`（`3638-3641`），但这依赖 JIT 侧约定，不是 verifier 输入格式的稳定 ABI。

所以：

- 如果 `src_reg` 被清零，`do_check()` 会把它当 helper call，直接错；
- 现实里 `src_reg` 没清，但 **`imm` 语义已经变了**，而且 `add_subprog_and_kfunc()` / `check_kfunc_call()` 都依赖原始 `func_id/off`。

结论：**最终 xlated kfunc call 也不能直接走现有 verifier。**

## 2.3 map 引用 `ldimm64`

`check_ld_imm()` 在 `17822-17917`。它对 `ldimm64` 的判断是：

- `src_reg == 0` -> 普通 64-bit immediate，记成 `SCALAR_VALUE`（`17844-17849`）
- `src_reg == BPF_PSEUDO_MAP_VALUE / _IDX_VALUE` -> `PTR_TO_MAP_VALUE`（`17897-17908`）
- `src_reg == BPF_PSEUDO_MAP_FD / _IDX` -> `CONST_PTR_TO_MAP`（`17908-17910`）

也就是说，**`do_check()` 并不是通过 `imm` 猜 map，而是通过 `src_reg` + `insn_aux_data` 识别 map pseudo load。**

### `resolve_pseudo_ldimm64()` 在哪里，做什么？

它在 `bpf_check()` 里位于 `do_check()` 之前（`26133-26135`）。

它会：

- 识别 `BPF_LD | BPF_IMM | BPF_DW` pseudo map load（`21889-21936`）
- `add_used_map()` 并填 `aux->map_index`（`21955-21961`）
- 对 map value 再填 `aux->map_off`（`21967-21983`）
- **把 `imm` 改成真正的 map 指针 / direct value 地址**（`21985-21986`）

但它**不会**把 `src_reg` 清零；相反，注释明确说 final conversion 在更后面：

- “In final `convert_pseudo_ld_imm64()` step ...” （`21921-21923`）

最终真正清 `src_reg` 的是 `convert_pseudo_ld_imm64()`：

- `insn->src_reg = 0;`（`22028-22034`）
- 调用点在 `26272-26276`

### 所以 `do_check()` 看到的到底是什么？

是一个很特殊的中间格式：

- `imm` 已经是 map pointer / direct value addr；
- 但 `src_reg` 还是 pseudo map tag；
- `insn_aux_data[i].map_index/map_off` 已经填好。

这正是你问题 6 里最关键的点：

**是的，`resolve_pseudo_ldimm64()` 在 `do_check()` 之前。  
因此 `do_check()` 看到的 `ldimm64` 已经不是用户态 `fd`，而是内核 map pointer。**

但这不等于“最终 xlated 格式和 `do_check()` 期望相同”，因为最终 live 程序还会再执行 `convert_pseudo_ld_imm64()`，把 `src_reg` 清成 0。  
一旦 `src_reg == 0`，`check_ld_imm()` 就会把它当普通常数（`17844-17849`），不再是 map 引用。

结论：

- **map 这部分不是“原始格式”依赖，而是依赖一个 pre-do_check 的中间格式。**
- 最终 xlated `ldimm64` 不能直接被现有 verifier 还原成 map 引用语义。

## 2.4 ctx 访问

`check_mem_access()` 对 `PTR_TO_CTX` 的路径在 `7911-7964`：

- 先做 `check_ptr_off_reg()`（`7925-7927`）
- 再做 `check_ctx_access(env, insn_idx, off, size, t, &info)`（`7929`）

而 `check_ctx_access()` 本体在 `6481-6510`，核心调用是：

- `env->ops->is_valid_access(off, size, t, env->prog, info)`（`6484-6485`）

这说明 verifier 检查的就是 **BPF-visible ctx offset**，不是 raw kernel struct offset。  
`convert_ctx_accesses()` 的注释也写得很直白：

```c
/* convert load instructions that access fields of a context type into a
 * sequence of instructions that access fields of the underlying structure:
 *     struct __sk_buff    -> struct sk_buff
 *     struct bpf_sock_ops -> struct sock
 */
```

见 `22588-22592`。

同时，`check_ctx_access()` 会把 `ctx_field_size` 记进 `insn_aux_data`（`6500-6505`）；  
`check_load_mem()` / `check_store_reg()` 还会把这条 memory insn 关联的 base ptr type 记进 `insn_aux_data[insn_idx].ptr_type`（`8084-8094`, `8116-8122`）。

这些 aux 信息随后正是 `convert_ctx_accesses()` 的输入（`22759-22849`）。

结论：

- `do_check()` 校验的是 **BPF ctx 语义**，不是 raw struct 偏移；
- `convert_ctx_accesses()` 在 **`do_check()` 之后**（`26205-26210`）；
- 所以现有 verifier **不能直接接受已转换的 raw ctx offset**。

而且不仅仅是 offset 问题：`convert_ctx_accesses()` 还可能插入 `BPF_ST_NOSPEC`、`BPF_PROBE_MEM*`、`BPF_PROBE_ATOMIC` 等内部 opcode（见后文），这些在 verifier 前端本来就不是用户输入格式。

---

## 3. fixup 阶段的精确时序

## 3.1 `resolve_pseudo_ldimm64()`

调用点：`26133-26135`，**在 `do_check()` 之前**。

它做两类事（注释 `21864-21868`）：

- map FD / map idx -> map pointer / direct value addr；
- pseudo BTF ID -> var pointer。

对 map load 的具体 rewrite 在 `21955-21986`。

所以问题 6 的答案是：

- **是的，`do_check()` 看到的 `ldimm64` 已经有 map pointer，不再是用户 fd。**
- 但它仍依赖 pseudo `src_reg` 和 `insn_aux_data`，因此**和最终 live xlated 仍不一样**。

## 3.2 `do_misc_fixups()`

调用点：`26209-26210`，**在 `do_check()` 之后**。  
函数本体：`23468-24426`。

### 它做的所有变换类型

下面按代码分支列全：

| 类型 | 代码位置 | 是否影响“让 `do_check()` 直接吃 xlated” |
|---|---|---|
| 为异常回调追加 hidden subprog | `23486-23500` | 是，程序结构变了 |
| addr-space cast 规范化为普通 mov32 | `23503-23513` | 是，指令编码变了 |
| `needs_zext` 时把 `ALU64` 改成 32-bit `ALU` | `23516-23518` | 一般否，更多是 post-pass 优化 |
| `sdiv/smod imm -1` rewrite | `23520-23547` | 是，插入新指令 |
| `div/mod reg` 的 0 / -1 安全 rewrite | `23549-23638` | 是 |
| `BPF_PROBE_MEM/BPF_PROBE_MEMSX` 增加 userspace 地址上界保护 | `23640-23668` | 是 |
| `LD_ABS/IND` rewrite 为 `gen_ld_abs()` 生成序列 | `23670-23688` | 是 |
| 指针算术 Spectre sanitize rewrite | `23690-23741` | 是 |
| `may_goto` rewrite（timed / non-timed） | `23743-23807` | 是 |
| kfunc call fixup（含 specialize / inline / 包装） | `23813-23827` + `23297-23435` | 是 |
| tail call 改成 `BPF_TAIL_CALL` | `23840-23912` | 是 |
| `timer_set_callback` 前插 `prog->aux` 参数 | `23915-23945` | 是 |
| storage-get helper 前插 `GFP_KERNEL` / `GFP_ATOMIC` | `23948-23964` | 是 |
| percpu alloc helper 前插 `r1 = *(u64 *)(r1 + 0)` | `23966-23983` | 是 |
| map helper inline / 或改写为 map op 函数 call imm | `23985-24081` | 是 |
| inline `bpf_jiffies64` | `24084-24106` | 是 |
| inline `bpf_get_smp_processor_id` | `24109-24135` | 是 |
| inline `bpf_get_current_task(_btf)` | `24137-24153` | 是 |
| inline `bpf_get_func_arg` | `24155-24187` | 是 |
| inline `bpf_get_func_ret` | `24189-24217` | 是 |
| inline `bpf_get_func_arg_cnt` | `24219-24243` | 是 |
| inline `bpf_get_func_ip` | `24245-24258` | 是 |
| inline `bpf_get_branch_snapshot` | `24260-24314` | 是 |
| inline `bpf_kptr_xchg` | `24316-24332` | 是 |
| 普通 helper call 的 `imm` 改为 `fn->func - __bpf_call_base` | `24333-24345` | **是，helper ID 丢失** |
| 为 `may_goto` 在各 subprog 入口补初始化栈槽 | `24364-24403` | 是 |
| tail-call poke tracking 元数据 | `24405-24420` | 否，非 verifier 语义问题 |
| `sort_kfunc_descs_by_imm_off()` | `24422-24426` | 间接是，服务于 post-fixup kfunc 调用模型 |

### 哪些最致命

对“直接 reverify xlated”最致命的不是性能优化，而是这几类：

- helper call 的 `imm` 不再是 helper ID（`24333-24345`）；
- kfunc call 的 `imm` / `off` 语义变化（`23310-23327`）；
- tail call 变成内部 opcode `BPF_TAIL_CALL`（`23856-23857`）；
- 一堆 helper 被直接 inline 成普通指令序列（`24084-24332` 等）；
- `LD_ABS/IND` 被重写（`23670-23688`）。

## 3.3 `convert_ctx_accesses()`

调用点：`26205-26207`，**在 `do_check()` 之后**。  
函数本体：`22593-22890`。

### 它修改了哪些指令

它不只改 ctx，还做了一批同类 memory access rewrite：

| 类型 | 代码位置 |
|---|---|
| 插 epilogue，并在入口保存 `ARG_PTR_TO_CTX` | `22608-22630` |
| 插 prologue / direct-write prologue | `22633-22655` |
| 在 `nospec` insn 前插 `BPF_ST_NOSPEC()` | `22669-22689` |
| arena atomic -> `BPF_PROBE_ATOMIC` | `22708-22715` |
| 在需要 `nospec_result` 的 store 后插 `BPF_ST_NOSPEC()` | `22739-22756` |
| `PTR_TO_CTX` / `PTR_TO_SOCKET` / `PTR_TO_SOCK_COMMON` / `PTR_TO_TCP_SOCK` / `PTR_TO_XDP_SOCK` 访问 rewrite | `22759-22849` |
| untrusted `PTR_TO_BTF_ID` / `PTR_TO_MEM` read -> `BPF_PROBE_MEM` / `BPF_PROBE_MEMSX` | `22775-22794` |
| `PTR_TO_ARENA` -> `BPF_PROBE_MEM32` / `BPF_PROBE_MEM32SX` | `22795-22806` |
| 窄 load 扩宽为更大 load，再补 mask / sign-extend | `22815-22876` |
| 主程序 `EXIT` 改跳 epilogue | `22716-22735` |

### rewrite 后的 ctx 指令，`do_check()` 能不能验证？

**不能。**

原因有三层：

1. `do_check()` 的 ctx 检查仍走 `is_valid_access(off, ...)`，消费的是 BPF-visible offset（`6484-6485`, `7911-7930`），不是 raw offset。
2. `convert_ctx_accesses()` 之后已经不一定还是“单条 ctx load/store”，可能变成多条 underlying-struct load + mask 序列（`22815-22876`）。
3. 它还会引入 verifier 前端原本不接受的内部 opcode：
   - `BPF_ST_NOSPEC()` 是 `BPF_ST | BPF_NOSPEC`（`include/linux/filter.h:509-515`），而 `do_check_insn()` 对 `class == BPF_ST` 只接受 `BPF_MODE == BPF_MEM`（`21184-21190`），所以会直接拒绝。
   - `resolve_pseudo_ldimm64()` 对 `BPF_LDX` 只接受 `BPF_MEM` / `BPF_MEMSX`（`21882-21887`），因此 `BPF_PROBE_MEM*` / `BPF_PROBE_MEM32*` 这样的 post-fixup opcode 作为 verifier 输入也会在前置检查就失败。

因此 ctx rewrite 后的最终 xlated **不能** 直接重跑现有 verifier。

## 3.4 `fixup_call_args()` / `fixup_kfunc_call()`

### `fixup_kfunc_call()`

- 函数定义：`23297-23435`
- 调用位置：`do_misc_fixups()` 中的 `23813-23827`

它做的事：

- 用 `(imm, off)` 找 kfunc desc（`23314-23319`）
- 可能做 specialize（`23321-23323`）
- 非 far-kfunc-call 时把 `imm` 改成 `BPF_CALL_IMM(desc->addr)`（`23325-23326`）
- 对若干特殊 kfunc 直接改成 wrapper / inline 指令序列（`23328-23434`）

### `fixup_call_args()`

- 函数定义：`23179-23228`
- 调用位置：`26221-26222`
- 时序：**在 `do_misc_fixups()` 之后**

它做两件事：

1. JIT 路径：`jit_subprogs(env)`（`23189-23196`）
2. 非 JIT 解释器路径：对 bpf-to-bpf call 执行 `bpf_patch_call_args(insn, depth)`（`23218-23224`）

而 `bpf_patch_call_args()` 的实际改写在 `kernel/bpf/core.c:2362-2368`：

- `insn->off = old imm`
- `insn->imm = interpreter thunk - __bpf_call_base_args`
- `insn->code = BPF_JMP | BPF_CALL_ARGS`

所以最终 live 程序如果走了这个路径，还会出现 `BPF_CALL_ARGS`。  
但 `do_check_insn()` 对 `class == BPF_JMP` 只把 `opcode == BPF_CALL` / `BPF_JA` / `BPF_EXIT` 当特殊分支处理（`21213-21282`）；其余跳转走 `check_cond_jmp_op()`，而那里明确只接受条件跳转，`opcode == BPF_JA || opcode > BPF_JCOND` 会报 `invalid BPF_JMP/JMP32 opcode`（`17579-17582`）。

因此 `BPF_CALL_ARGS` 这种 post-fixup internal opcode 也**不是 verifier 输入格式**。

---

## 4. 核心结论：4A / 4B / 4C

## 4A 不是事实

`do_check()` **并不能**“本来就接受 xlated”：

- helper call：依赖原始 helper ID（`11747-11759`），而 xlated 是 call immediate（`24333-24345`）
- kfunc call：依赖原始 `func_id/off`，而 xlated 可能已变（`14221`, `23325-23326`）
- map `ldimm64`：依赖 pseudo `src_reg` + `insn_aux_data`，最终 live 程序已经 `src_reg = 0`（`22028-22034`, `26272-26276`）
- ctx access：依赖 BPF-visible ctx offset，最终 xlated 已变为 raw underlying access / internal opcode（`6484-6485`, `22588-22592`, `22759-22876`）
- 还有 `BPF_TAIL_CALL` / `BPF_CALL_ARGS` / `BPF_ST_NOSPEC` / `BPF_PROBE_MEM*` 这些 internal opcode，本来就不是 verifier 前端接收的用户格式（`21184-21190`, `21882-21887`, `17579-17582`）

## 4B 只在你换“输入形态”时成立

如果你说的不是“最终 live xlated”，而是另外保存一份 **verifier-ready IR**：

- 已做 `resolve_pseudo_ldimm64()`
- 但未做 `convert_ctx_accesses()`
- 未做 `do_misc_fixups()`
- 未做 `fixup_call_args()`
- 未做 `convert_pseudo_ld_imm64()`

那么 verifier 当然可以直接复用，因为这其实就是它本来吃的格式。

但这已经不是“直接接受当前 xlated bytecode”，而是**新增一种需要额外保存的中间表示**。

## 4C 才是对“最终 live xlated”问题的准确答案

所以对你原问题的精确回答是：

**结论：4C。现有 verifier 与“最终 xlated bytecode”深度耦合于“原始/中间格式”，不能靠几处小改动就让 verifier 直接接受 live 程序里的最终 xlated 指令流。**

真正的耦合点不是一个，而是一串：

1. pre-pass `resolve_pseudo_ldimm64()` 已经说明 verifier 本来就依赖一个特殊中间格式；
2. post-pass `convert_ctx_accesses()` / `do_misc_fixups()` / `fixup_call_args()` 会生成 internal opcodes 和新语义编码；
3. `convert_pseudo_ld_imm64()` 还会擦掉 map pseudo tag；
4. kfunc 元数据在 `add_subprog_and_kfunc()` 里甚至早于 `do_check()` 就开始消费原始 `func_id/off`。

这不是“改几处 `if (is_rejit)`”能解决的。

---

## 5. 修改方案建议

既然结论是 4C，对“直接让 verifier 吃最终 xlated”我不建议给出伪精确的小补丁方案；那会误导实现难度。

### 5.1 不建议的方案：直接让 verifier 接受最终 xlated

这至少要同时解决：

- helper call：从 call immediate 反推 helper ID
- kfunc call：从 post-fixup `(imm, off)` 反推 / 兼容原始 `func_id/off`
- map `ldimm64`：恢复 map pseudo tag 和 `map_index/map_off`
- ctx/sock access：接受 raw underlying access，或者逆变换回 BPF-visible ctx access
- internal opcodes：接受 `BPF_TAIL_CALL` / `BPF_CALL_ARGS` / `BPF_ST_NOSPEC` / `BPF_PROBE_MEM*`

这会同时动到：

- `add_subprog_and_kfunc()`（`3731-3791`）
- `resolve_pseudo_ldimm64()`（`21871-22005`）
- `check_ld_imm()`（`17822-17917`）
- `do_check_insn()` call/jmp/st/ldx 前端（`21147-21313`）
- `check_helper_call()`（`11733-12120`）
- `check_kfunc_call()`（`14203-14595`）
- `check_ctx_access()` / `check_mem_access()`（`6481-6510`, `7796-8005`）

这已经是“新增第二套 verifier 输入 ISA”了，不是小修小补。

### 5.2 可行方案：保存 verifier-ready IR，而不是最终 xlated

更现实的 REJIT 方案是：

1. 在首次 load 成功时，额外保存一份 **pre-fixup verifier IR**：
   - 必须晚于 `resolve_pseudo_ldimm64()`；
   - 必须早于 `convert_ctx_accesses()` / `do_misc_fixups()` / `fixup_call_args()` / `convert_pseudo_ld_imm64()`。
2. REJIT 时从这份 IR 出发做变换；
3. 然后重跑 `do_check()` 及后续 fixup / JIT。

最合适的切点在 `bpf_check()` 中是：

- `resolve_pseudo_ldimm64(env)` 之后（`26133-26135`）
- 且在第一次指令 rewrite 注释之前（`26189-26191`）

如果你只想保一份“可重验可重 JIT”的 canonical form，这比保存用户原始 bytecode 更贴近 verifier 实际消费的格式。

但它仍然是“额外保存一份程序表示”，只是这份表示不是用户原始字节码，而是 verifier-ready IR。

---

## 6. `resolve_pseudo_ldimm64()` 的特殊性：精确确认

这是整个问题里最重要的特例。

答案是：

- `resolve_pseudo_ldimm64()` **在 `do_check()` 之前**（`26133-26135`）
- 它会把 map pseudo `ldimm64` 的 `imm` 从用户态 fd/index 改成内核 map pointer / direct value addr（`21955-21986`）
- 因此 **`do_check()` 看到的 `ldimm64` 确实已经不是 fd，而是 map pointer**
- 但它依赖 pseudo `src_reg` 和 `insn_aux_data.map_index/map_off`（`21960-21983`, `17894-17916`）
- 最终 live 程序返回给内核前还会执行 `convert_pseudo_ld_imm64()` 把 `src_reg` 清成 0（`22028-22034`, `26272-26276`）

所以准确表述应该是：

**map 引用这部分，`do_check()` 期望的并不是“原始用户格式”，而是“已 resolve、未 final-convert 的中间格式”；最终 xlated 并不等于这个格式。**

---

## 最终判断

**精确结论：4C。**

对“当前 live 程序的最终 xlated bytecode”：

- verifier `do_check()` 与 fixup 逻辑不是完全解耦的；
- 它们通过一套中间格式强耦合；
- `resolve_pseudo_ldimm64()` 在前，`convert_ctx_accesses()` / `do_misc_fixups()` / `fixup_call_args()` / `convert_pseudo_ld_imm64()` 在后；
- 最终 xlated 不能直接重新 verify。

如果目标是做 `BPF_PROG_REJIT`，工程上最稳的路线是：

- **保存原始 bytecode**，或者
- **保存一份 verifier-ready IR**，

而不是尝试让现有 verifier 直接吞最终 xlated。
