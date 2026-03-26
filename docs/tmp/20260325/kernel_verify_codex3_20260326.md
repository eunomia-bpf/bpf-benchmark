# kernel_vs_upstream_diff.patch 验证结果

已完整通读 `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260325/kernel_vs_upstream_diff.patch`（2935 行），并核对实际源码：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/syscall.c`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

为确认锁语义和架构差异，额外核对了：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/arraymap.c`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

## 1. [HIGH] rollback 用裸 memcpy 恢复 poke_tab 不拿 poke_mutex

- 结论：确认存在，是真问题。

### 关键代码

- `kernel/bpf/syscall.c:3524-3544`
  - `bpf_prog_rejit_rollback()` 在 swap-back 后直接：
  - `memcpy(prog->aux->poke_tab, saved_poke_tab, saved_poke_cnt * sizeof(*saved_poke_tab));`
- `kernel/bpf/syscall.c:3218-3278`
  - 正向更新 `poke_tab` 的 `bpf_prog_rejit_update_poke_tab()` 明确按 entry 获取 `array->aux->poke_mutex`，并在更新期间把 `tailcall_target_stable` 置为 `false/true`。
- `kernel/bpf/arraymap.c:900-945`
  - `bpf_fd_array_map_update_elem()` / delete 路径在 `array->aux->poke_mutex` 下调用 `map_poke_run()`。
- `kernel/bpf/arraymap.c:1107-1152`
  - `prog_array_map_poke_run()` 在持有 `poke_mutex` 时遍历 `elem->aux->poke_tab[]`，并依赖 `tailcall_target_stable` 判断该 entry 是否可用。

### 为什么确认是 bug

- `rejit_mutex` 只串行化同一个 prog 的 REJIT；它并不和各个 `PROG_ARRAY` 的 `array->aux->poke_mutex` 建立互斥关系。
- rollback 路径的这次 `memcpy()` 没有拿任何 `poke_mutex`，也没有先把相关 entry 的 `tailcall_target_stable` 清成 `false`。
- 与此同时，另一个线程完全可以通过 `map_update_elem()` / `map_delete_elem()` 进入 `prog_array_map_poke_run()`，在只持有 `poke_mutex` 的情况下读取同一个 `prog->aux->poke_tab[]`。
- 结果就是 rollback 的整表 `memcpy()` 可以和 `prog_array_map_poke_run()` 并发，后者可能看到被部分恢复的 descriptor，读到混合态的：
  - `tailcall_target`
  - `tailcall_bypass`
  - `bypass_addr`
  - `adj_off`
  - `tailcall_target_stable`
- 这会把 map poke patch 到错误地址，或者把 `stable` 状态和地址字段恢复成彼此不一致的组合。

### 修复建议

- 不要在 rollback 里对整张 `poke_tab` 做裸 `memcpy()`。
- 增加一个和 `bpf_prog_rejit_update_poke_tab()` 对称的 restore helper，按 entry 恢复：
  - 找到对应 `struct bpf_array`
  - `mutex_lock(&array->aux->poke_mutex)`
  - `WRITE_ONCE(old_poke->tailcall_target_stable, false)`
  - 仅恢复 JIT 相关字段：`tailcall_target`、`tailcall_bypass`、`bypass_addr`、`adj_off`
  - `WRITE_ONCE(old_poke->tailcall_target_stable, true)`
  - `mutex_unlock(&array->aux->poke_mutex)`
- 最好只恢复 JIT 地址字段，不要整结构体覆盖，避免把并发期间可能变化的其他状态一起抹回旧值。

## 2. [HIGH] ARM64 emit 回调直接写 JIT image 无 scratch buffer

- 结论：确认差异存在；这是 ARM64 侧真实的接口级缺陷/健壮性问题。当前树里没有现成 `emit_arm64` 实现来直接触发，但 core 侧确实没有 x86 的保护。

### 关键代码

- `arch/arm64/net/bpf_jit_comp.c:1195-1216`
  - `emit_kinsn_desc_call_arm64()` 直接把 `ctx->image` 和 `&ctx->idx` 传给 `kinsn->emit_arm64(...)`。
- `arch/arm64/net/bpf_jit_comp.c:110-123`
  - ARM64 通用 `emit()` / `emit_u32_data()` 会在 `ctx->write == false` 时避免写 image，但这是 JIT 内部 helper 的约束，不会自动约束外部 `emit_arm64` 回调。
- `arch/arm64/net/bpf_jit_comp.c:2131-2148`
  - pass 1 构建 body 时，`ctx.image == NULL`。
- `arch/arm64/net/bpf_jit_comp.c:2176-2204`
  - pass 2 / pass 3 中，`ctx.image` 已有效，但会先经历一次 `ctx.write = false` 的 dry-run，再进入 `ctx.write = true` 的最终写入。
- `arch/x86/net/bpf_jit_comp.c:579-606`
  - x86 的 `emit_kinsn_desc_call()` 先写本地 `scratch[BPF_MAX_INSN_SIZE]`，校验完成后才在 `emit == true` 时 `memcpy()` 到最终 image。

### 为什么确认是问题

- ARM64 wrapper 没有 scratch buffer，直接把真实 JIT image 暴露给 `emit_arm64`。
- 这意味着 ARM64 core 只能“信任”回调严格遵守 `emit` 语义：
  - pass 1 时不能在 `image == NULL` 上写
  - pass 2 时不能在 `ctx.write == false` 时写真实 image
  - 出错返回前不能留下部分写入的垃圾状态
- x86 则没有把这些假设强加给回调。即便回调内部不够规矩，写的也只是本地 scratch，最终 image 只有在校验通过且 `emit == true` 时才会被复制。
- 所以这里不是“单纯实现风格不同”，而是 ARM64 缺少 x86 已有的防御层。

### 修复建议

- ARM64 这里应镜像 x86 的封装方式：
  - 使用本地 scratch buffer
  - 使用本地 `off` / `idx`
  - 先让 `emit_arm64()` 只操作 scratch
  - 校验返回的 insn 数量与 `max_emit_bytes`
  - 只有最终写入阶段才把 scratch 复制到 `ctx->image + saved_idx`
- 即使保留 `emit` 参数，也不应在 dry-run 阶段把真实 image 暴露给回调。
- 如果要保留当前接口，至少也应把“`emit_arm64()` 必须在 `emit == false` 时完全不写 image、且必须容忍 `image == NULL`”写成硬约束；但更稳妥的做法仍然是加 scratch wrapper。

## 3. [HIGH] bpf_arch_text_poke 传了两个 BPF_MOD_CALL

- 结论：不成立，属于误报。

### 关键代码

- `kernel/bpf/bpf_struct_ops.c:1596-1600`
  - `bpf_arch_text_poke(call_sites[i], BPF_MOD_CALL, BPF_MOD_CALL, (void *)old_bpf_func, new_bpf_func);`
- `kernel/bpf/bpf_struct_ops.c:1605-1608`
  - rollback 也是同样的 `CALL -> CALL` 反向切换。
- `include/linux/bpf.h:3923-3925`
  - 函数签名是：
  - `bpf_arch_text_poke(void *ip, enum bpf_text_poke_type old_t, enum bpf_text_poke_type new_t, void *old_addr, void *new_addr);`
- `arch/x86/net/bpf_jit_comp.c:621-649`
  - x86 实现会用 `old_t/old_addr` 生成旧指令，再用 `new_t/new_addr` 生成新指令。
- `arch/arm64/net/bpf_jit_comp.c:3067-3074`
  - ARM64 实现同样把 `BPF_MOD_CALL` 映射成 branch-with-link（`BL`）。

### 为什么这是误报

- 这里的需求不是把 call site 从 `CALL` 改成 `NOP` 或 `JUMP`，而是把：
  - `CALL old_bpf_func`
  - 改成
  - `CALL new_bpf_func`
- 因此 `old_t = BPF_MOD_CALL`、`new_t = BPF_MOD_CALL` 正是正确用法。
- `bpf_arch_text_poke()` 的两个 type 参数表示“旧指令类型”和“新指令类型”，不是“只允许一个 CALL 枚举值”。
- 如果这里传成别的类型，反而会生成错误 opcode。

### 修复建议

- 无需功能修复。
- 如果想减少后续误报，可以在 `bpf_struct_ops_refresh_prog()` 这两处调用前补一行注释，明确这是在做 `CALL old_bpf_func -> CALL new_bpf_func` 的重定向。

## 最终结论

- 问题 1：确认存在，是真实并发缺陷。
- 问题 2：确认差异存在，ARM64 core 缺少 x86 的 scratch-buffer 防护，属于真实接口级缺陷；当前树内暂无 in-tree `emit_arm64` 用户。
- 问题 3：不成立，`BPF_MOD_CALL, BPF_MOD_CALL` 是按函数签名正确传参。
