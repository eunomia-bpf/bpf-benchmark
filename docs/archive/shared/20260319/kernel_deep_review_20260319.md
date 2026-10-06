# BpfReJIT 内核改动深度 Review

日期：2026-03-19

评审范围：

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/syscall.c`

对比基线：

- `master..jit-directive-v5`

## 总结

这套改动的核心方向是可行的：`x86` 侧没有把 directive dispatch 带到最终执行中的 JIT 代码里，所以运行时 hot path 基本没有新增开销；主要新增成本集中在“编译期”和“recompile 发布/回滚路径”。

当前最需要优先修的是两类问题：

1. `func_cnt` / `real_func_cnt` 混用导致 hidden subprog 的 kallsyms/extable 生命周期不一致，可能留下指向已释放 JIT image 的陈旧 `bpf_ksym`。
2. `BPF_PROG_JIT_RECOMPILE` 的 UAPI / rollback 语义还没有收敛：`policy_fd == 0` 设计有歧义，`BPF_F_RECOMPILE_ROLLBACK` 的行为和注释不一致，而且 generic syscall 入口对非 x86 也暴露了半实现能力。

性能上最明显的问题不是运行时，而是：

- `do_jit()` 每条指令都走一次 rule lookup/dispatch，即使没有 policy。
- recompile 在真正 parse policy 之前就先完整 snapshot 了所有 prog/subprog 状态。

## 主要问题

### 1. P1: hidden subprog 的 kallsyms/extable 在 recompile 后不会被替换，但旧 image 会被释放

位置：

- `vendor/linux-framework/kernel/bpf/jit_directives.c:450`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:458`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3417`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3461`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3474`
- `vendor/linux-framework/include/linux/bpf.h:1677`
- `vendor/linux-framework/include/linux/bpf.h:1678`
- 旁证：`vendor/linux-framework/kernel/bpf/verifier.c:22999`

问题：

`image_cnt` 使用的是 `real_func_cnt`，也就是会对 hidden subprog 一起做 recompile、commit，并在成功后释放旧 header。

但 `bpf_jit_recompile_ksym_prog()` 只给 `idx == 0` 的主 prog 和 `idx < func_cnt` 的可见 subprog 返回 `ksym_prog`；`idx >= func_cnt` 的 hidden subprog 直接返回 `NULL`。结果是：

- hidden subprog 不会走 `bpf_jit_recompile_shadow_ksym_add()`
- hidden subprog 不会走 `bpf_prog_kallsyms_replace()`
- 但 hidden subprog 的旧 `old_headers[i]` 仍然会在 `3474-3476` 被释放

如果 hidden subprog 在初始 load 时已经注册过 kallsyms，那么 recompile 后会留下指向旧 JIT image / 旧 extable 的陈旧 `bpf_ksym` 条目。

风险：

- `search_bpf_extables()` / `bpf_address_lookup()` / unwinder 可能命中陈旧条目。
- 陈旧条目里的 `extable`、`owner` 和地址范围都可能已经对应到被释放或复用的文本内存。
- 这是标准的“元数据悬挂到已释放 JIT image”问题，属于需要尽快修的 correctness 风险。

修复建议：

- `bpf_jit_recompile_ksym_prog()` 不要用 `func_cnt` 截断，至少要和 `image_cnt` 一样按 `real_func_cnt` 覆盖。
- 如果 hidden subprog 本来就不应该暴露 kallsyms，那么应当在初始 load 路径就不要对它们调用 `bpf_prog_kallsyms_add()`；现在 load 和 recompile 的策略不一致。
- 修完后保证“每一个会被 `bpf_jit_binary_pack_free()` 释放的旧 image，都先对应做一次 `bpf_prog_kallsyms_replace()` 或 `bpf_ksym_del()`”。

### 2. P1: syscall 是 generic 暴露的，但 staged recompile 实际只在 x86 backend 实现

位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:6333`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3188`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3592`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5750`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:6070`

问题：

`BPF_PROG_JIT_RECOMPILE` 在 syscall 层是无条件暴露的，但 staged image / commit / abort / shadow ksym 这些关键能力只在 `arch/x86/net/bpf_jit_comp.c` 实现。

policy 路径在 `bpf_jit_parse_policy()` 里有 `#if defined(CONFIG_X86_64)` 的架构检查，但 stock re-JIT 路径：

- `policy_fd == 0` 时直接走 `do_recompile`
- 没有统一的 “recompile supported” 检查

也就是说，generic UAPI 现在对“非 x86 + stock re-JIT”暴露了一个没有明确 contract 的半实现入口。

风险：

- 最轻是返回 `-EIO`。
- 更糟的是非 x86 JIT backend 根本不理解 `jit_recompile_active` / staged state，rollback 正确性没有保证。
- UAPI 同时又公开了 `BPF_JIT_ARCH_ARM64`，会让用户空间误以为 arm64 也有完整支持。

修复建议：

- 在 `bpf_prog_jit_recompile()` 一开始加统一能力检查，例如 `bpf_jit_supports_recompile()`。
- 在未实现 backend 的架构上直接返回 `-EOPNOTSUPP`，不要进入后续状态机。
- 如果短期只支持 x86，建议先不要在 UAPI 里公开 `BPF_JIT_ARCH_ARM64`。

### 3. P1: `policy_fd == 0` 作为“stock re-JIT”哨兵值，UAPI 有歧义

位置：

- `vendor/linux-framework/include/uapi/linux/bpf.h:2173`
- `vendor/linux-framework/include/uapi/linux/bpf.h:2175`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3536`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3537`

问题：

`fd 0` 在 Linux 里是完全合法的文件描述符。当前 UAPI 把 `policy_fd == 0` 解释成 “clear policy / stock re-JIT”，意味着：

- 用户没法传一个真正位于 `fd 0` 的 sealed memfd
- 某些 userspace 封装如果把 memfd dup 到 `0`，内核会静默走错语义

这是典型的 syscall 设计歧义。

修复建议：

- 把哨兵值改成 `-1`，并显式 reject `< -1`。
- 或者改成独立 flag，例如 `BPF_F_RECOMPILE_CLEAR_POLICY`。
- 如果保留当前 ABI，至少要在文档里明确“不允许 policy memfd 使用 fd 0”；但这仍然不是好接口。

### 4. P1: `BPF_F_RECOMPILE_ROLLBACK` 的语义和实现不一致，而且 snapshot 成本被无条件支付

位置：

- `vendor/linux-framework/include/uapi/linux/bpf.h:1721`
- `vendor/linux-framework/include/uapi/linux/bpf.h:1723`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3584`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3608`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3641`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3643`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3654`

问题：

UAPI 注释写的是：

`BPF_F_RECOMPILE_ROLLBACK`: “preserve the current JIT image and policy until recompile succeeds.”

但实现里：

- `bpf_jit_recompile_snapshot()` 是无条件执行的
- recompile 失败时，`bpf_jit_recompile_restore(&rollback)` 也是无条件执行的
- 这个 flag 实际上只影响“policy 指针要不要恢复”，而不是“image 要不要 rollback”

另外，snapshot 发生在：

- policy parse 之前
- `prog->blinded` 的 reject 之前

所以即使是非法 policy、unsupported case，也先把所有 prog/subprog 的 `insnsi` 整体 `kmemdup()` 一遍。

风险：

- UAPI 语义误导 userspace。
- 没有真正的“快速 no-rollback 模式”。
- 对大 prog / 多 subprog 的 recompile，请求还没过 cheap validation 就先付出 O(total_insns) 的复制成本。

修复建议：

- 先明确语义。
  - 如果 image 在失败时必须总是恢复，那么就把这个 flag 改成“policy rollback”语义，并更新 UAPI 注释。
  - 如果想保留真正的 rollback flag，就需要实现一个不依赖原地修改 live prog 状态的 fast path。
- 至少把 `bpf_jit_recompile_snapshot()` 挪到所有 cheap reject 之后：
  - JITed 检查
  - 架构支持检查
  - blinded 检查
  - policy parse/validate 成功之后

### 5. P2: `do_jit()` 在 non-recompile / no-policy 场景下仍然每条指令做 rule dispatch

位置：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3473`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3632`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3803`

问题：

`do_jit()` 主循环里无条件调用 `bpf_jit_apply_prog_rule()`。即使：

- 当前不是 recompile
- `main_aux->jit_policy == NULL`
- `active_cnt == 0`

也还是每条 BPF 指令走一层：

- `bpf_jit_apply_prog_rule()`
- `bpf_jit_try_emit_prog_rule()`
- `bpf_jit_rule_lookup_prog()`
- `policy/null` 检查

结论：

- 这不会给最终执行中的 JIT 代码带来运行时开销。
- 但会给 JIT 编译期 hot path 带来稳定的额外分支/调用成本。

修复建议：

- 在 `do_jit()` 进入主循环前先缓存 `policy` / `has_active_rules`。
- 没有 active rule 时直接跳过 `bpf_jit_apply_prog_rule()`。
- 更进一步可以把规则遍历改成“当前 insn_idx 是否等于 next_rule->site_start”，避免每条指令做 binary search。

### 6. P2: `COND_SELECT` 的 2-insn guarded-update 发射路径目前是死代码

位置：

- `vendor/linux-framework/kernel/bpf/jit_directives.c:804`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:813`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1488`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1544`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1557`

问题：

validator 只接受：

- `site_len == 4` 的 diamond
- `site_len == 3` 的 compact

但 emitter 还保留了：

- `emit_bpf_cmov_guarded_update()`
- `emit_canonical_select()` 里的 `site_len == 2` 分支

按当前 policy framework，这条路径永远不会被激活。

修复建议：

- 如果 2-insn guarded-update 不是近期要公开的 UAPI 能力，直接删掉这段 emitter/helper。
- 如果确实要支持，就补 validator、binding 约束和测试，不要让 emitter 先走在 validator 前面。

### 7. P2: hidden subprog 边界校验同样错误地用了 `func_cnt`，会把跨 hidden subprog 的规则误标成 active

位置：

- `vendor/linux-framework/include/linux/bpf.h:1677`
- `vendor/linux-framework/include/linux/bpf.h:1678`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2807`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2818`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2821`

问题：

`bpf_jit_rule_within_single_subprog()` 用 `func_cnt` 枚举 subprog 边界，而不是 `real_func_cnt`。有 hidden subprog 时：

- 末尾 hidden subprog 的边界不会参与检查
- 某些实际上跨越 visible -> hidden 边界的 rule 会被错误标成 “within single subprog”

后果是这类 rule 会在 parse 阶段进入 `active_cnt`，但到了 emitter 阶段又因为 local site 越界而 fallback。

这不会直接破坏正确性，但会让：

- `active_cnt`
- trace/log
- “policy 是否生效” 的判断

都变得不准确。

修复建议：

- 边界判断统一改用 `bpf_jit_recompile_real_func_cnt(main_aux)`。
- 这和问题 1 本质上是同一个 root cause：hidden subprog 处理不能混用 `func_cnt`。

### 8. P2: 公共 helper / stage-reset / pattern 解析逻辑存在明显重复，已经开始出现漂移

位置：

- `vendor/linux-framework/include/linux/bpf.h:1842`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:59`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:239`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5750`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:480`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:796`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1068`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1544`

问题：

目前至少有三组重复：

1. `bpf_jit_main_aux()` 和已经加到公共头文件里的 `bpf_prog_main_aux()`
2. `bpf_jit_recompile_reset_prog_aux()` 和 x86 侧的 `bpf_jit_recompile_clear_stage()`
3. validator 和 emitter 各自维护一套 `COND_SELECT` 的 pattern 识别/解析逻辑

这类重复已经开始产生漂移，最明显的例子就是上一条里的 dead `site_len == 2` 路径。

修复建议：

- 直接删掉 `bpf_jit_main_aux()`，统一复用 `bpf_prog_main_aux()`。
- stage 字段清零逻辑只保留一份，最好放公共层。
- emitter 尽量直接消费 `rule->params`；不要在 validator 已经 canonicalize 过之后，再在 x86 里从原始 insn 重新 parse 一遍。

### 9. P2: `recompile_count` 会在“没有实际替换 image”的情况下增加

位置：

- `vendor/linux-framework/kernel/bpf/jit_directives.c:3679`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3685`
- `vendor/linux-framework/kernel/bpf/syscall.c:5052`
- `vendor/linux-framework/include/uapi/linux/bpf.h:6956`

问题：

当 custom policy 最终 `jit_recompile_num_applied == 0` 时，代码会：

- restore 旧 image
- 记录 “no rules applied; kept the pre-recompile image”
- 但仍然把 `recompile_count++`

这使得 `BPF_PROG_INFO.recompile_count` 更像“成功返回的 syscall 次数”，而不是“成功替换 live image 的次数”。

修复建议：

- 如果这个字段想表达“image 被真正切换过的次数”，应当只在至少一个 image commit 成功、且最终没有走 `restore(old image)` 时递增。
- 如果想表达“successful recompile attempts”，UAPI 字段名和注释都需要改。

## 额外设计建议

### A. `policy blob` 目前更像“作者格式”，不是“内核运行时格式”

当前 v2 blob 让内核在 runtime 做了很多 DSL 解析工作：

- pattern match
- constraint check
- binding extraction
- canonical param 验证
- canonical site 再解析

这对 debug/实验阶段是方便的，但对内核长期 ABI 不够经济。更合理的方向是：

- userspace authoring format 保留 declarative pattern DSL
- 进入内核的 runtime format 收敛成紧凑的 `{site_start, site_len, canonical_form, native_choice, params[]}` 结构

这样可以直接减少：

- parse 成本
- validator / emitter 双份逻辑
- no-op rule / stock-choice rule 的复杂度

### B. “stock native choice” 建议不要继续保留在 runtime policy 里

当前这些 choice 本质上都代表“保持 stock emission”：

- `BPF_JIT_SEL_BRANCH`
- `BPF_JIT_WMEM_BYTE_LOADS`
- `BPF_JIT_ROT_SHIFT`
- `BPF_JIT_ACALC_SHIFT_ADD`
- `BPF_JIT_BFLIP_ORIGINAL`

x86 emitter 对它们最终都是返回 `0` 走 stock path。建议把这类 choice 从 runtime policy 里剥掉，改成“没有 rule 就表示 stock”。这会直接简化：

- `active_cnt` 语义
- “no rules applied” 分支
- UAPI 的 canonical/native 枚举规模

### C. validator 模板建议按 canonical form 合并，而不是 pattern DSL 和 emitter 双维护

现在很多 canonical form 实际上已经有稳定的 shape parser；但这些 parser 只在 validator 用，emitter 还会重新看 raw insns。建议方向是：

- 每个 canonical form 只保留一份 shape extraction
- validator 负责产出 canonical params
- emitter 只消费 canonical params，不再回看原始 insn

这会比现在“pattern DSL 一层 + canonical site 一层 + emitter 再 parse 一层”更稳。

## 可复用的内核 API / 机制清单

下面这些是我认为应该直接复用，或者至少作为优先选项的内核现有接口：

1. `bpf_prog_main_aux()`
   - 位置：`vendor/linux-framework/include/linux/bpf.h:1842`
   - 可以直接替代 `jit_directives.c` 里的本地 `bpf_jit_main_aux()`。

2. `bpf_prog_has_trampoline()`
   - 位置：`vendor/linux-framework/include/linux/bpf.h:1554`
   - 适合做 recompile 前的统一 preflight guard，而不是只手工 special-case `struct_ops`。

3. `bpf_prog_kallsyms_replace()`
   - 位置：`vendor/linux-framework/include/linux/bpf.h:1545`
   - 已经是这套方案正确的发布 API；问题不在 API 本身，而在 hidden subprog 没有全量复用到。

4. `bpf_jit_binary_pack_alloc()` / `bpf_jit_binary_pack_finalize()` / `bpf_jit_binary_pack_free()`
   - 当前已经在用，这条方向是对的。
   - 这里不建议改成自己发明一套 `bpf_jit_alloc/free`；pack API 就是内核现成的 JIT image 生命周期边界。

5. `text_poke_copy()`
   - 当前通过 `bpf_arch_text_copy()` 间接用了。
   - 但对这套 out-of-line recompile 方案来说，`text_poke` 不应该成为主发布机制；“编译新 image + `bpf_func` 指针切换 + RCU 后 free old image”是更合适的现有模式。

6. `bsearch()`
   - 如果后续想简化 `bpf_jit_rule_lookup()` 的自写 binary search，可以考虑复用内核通用查找接口。
   - 这不是 correctness 问题，只是代码可读性建议。

## 结论

如果按修复优先级排，我建议顺序是：

1. 先修 hidden subprog 的 `real_func_cnt`/kallsyms 问题。
2. 再把 syscall/UAPI 语义收敛：架构 gating、`policy_fd` 哨兵、rollback 语义。
3. 然后再做 compile-time 性能清理：parse-first、snapshot 后移、无 policy 时绕过 dispatch。
4. 最后统一重复 helper 和 validator/emitter 的双份 shape 逻辑。

就当前版本而言，我不认为它已经达到了“可长期维护的 upstream 级设计”；更像是功能已经接近闭环，但生命周期、UAPI 语义和 hidden subprog 细节还需要再打一轮磨。
