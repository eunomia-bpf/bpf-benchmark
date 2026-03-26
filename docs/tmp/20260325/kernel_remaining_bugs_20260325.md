# 内核残留 Bug 清单（2026-03-25 最终确认）

日期：2026-03-25
方法：完整阅读全部 7 份调查文档 + 当前内核代码静态审查

## 已修复的 Bug

| Bug | 状态 | 修复位置 |
|-----|------|----------|
| const_prop 丢弃 map_value 指针类型 | **已修** | daemon/src/passes/const_prop.rs:202-217 |
| bpf_prog_get_info_by_fd metadata 竞态 | **已修** | syscall.c:5772 guard(mutex) |
| bpf_prog_get_stats null deref | **已修** | syscall.c:2466 |
| smp_wmb → smp_store_release | **已修** | syscall.c:3455 |
| tail_call_reachable 未 swap | **已修** | syscall.c swap 函数 |
| arena 未 swap | **已修** | syscall.c swap 函数 |
| bpf_kinsn_has_native_emit 未定义 | **已修** | include/linux/bpf.h:981 |
| prog_flags 不完整 | **已修** | syscall.c:3558 aux->prog_flags |

## 仍存在的 Bug

### P1-1: bpf_prog_rejit_swap() one-way copy 字段导致 rollback 不可逆

**文件**: `vendor/linux-framework/kernel/bpf/syscall.c:3431-3466`

**问题**: `bpf_prog_rejit_swap()` 对 ~20 个 `struct bpf_prog` 字段和 ~10 个 `struct bpf_prog_aux` scalar 字段使用了**单向 copy**（`prog->X = tmp->X`）而非 `swap()`。包括：
- `prog->len`（行 3466）
- `prog->insnsi` content（行 3465, memcpy）
- `prog->aux->stack_depth`（行 3450）
- `prog->digest`, `prog->gpl_compatible`, `prog->cb_access`, `prog->blinded` 等

当 `bpf_prog_rejit_rollback()` 调用第二次 `bpf_prog_rejit_swap(prog, tmp)` 时，one-way copy 无法还原这些字段。rollback 后：
- `prog->bpf_func` 正确恢复到旧 JIT image
- `prog->len` 仍是新程序长度（与旧 JIT image 不匹配）
- `prog->insnsi` 仍是新 bytecode
- `prog->aux->stack_depth` 仍是新值

**触发条件**: `bpf_trampoline_refresh_prog()` 或 `bpf_struct_ops_refresh_prog()` 失败进入 rollback 路径。

**影响**: rollback 后 metadata 与运行中的 JIT image 不一致。`bpf_prog_get_info_by_fd()` 返回错误的 xlated bytecode。后续再次 REJIT 可能产生不可预测行为。

**修复方案**: 把 one-way copy 改为 `swap()`，或在 swap 前保存原始值供 rollback 恢复。

### P1-2: find_call_site() 只返回第一个匹配的 CALL 指令

**文件**: `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1471-1512`

**问题**: `find_call_site()` 扫描 trampoline binary image 寻找 `CALL rel32` 指令匹配 `old_bpf_func`，找到第一个就返回。如果同一 trampoline 中同一 BPF 程序被多个 callback 调用（例如 struct_ops 的多个方法使用同一 BPF 程序），只有第一个 call site 被 patch。

**触发条件**: struct_ops map 中同一 BPF 程序注册了多个 callback。

**影响**: REJIT 后，未 patch 的 call site 继续调用旧 JIT image。`synchronize_rcu` + free 后变成 dangling call（use-after-free）。

**修复方案**: `find_call_site()` 返回所有匹配的 call site（改为返回数组），或在构建 trampoline 时保存每个 callback 的 call site 偏移，REJIT 直接按偏移 patch。

### P2-1: orig_insns 无条件分配

**文件**: `vendor/linux-framework/kernel/bpf/syscall.c:3032-3035`

**问题**: 每个 BPF 程序 load 时都分配 `orig_insns` 副本，即使永远不用 REJIT。

**修复方案**: 延迟到第一次 REJIT 时分配，或用 load flag 控制。

### P2-2: poke_target_phase 全量 map 扫描

**文件**: `vendor/linux-framework/kernel/bpf/syscall.c:3323-3370`

**问题**: O(total_maps * max_entries) 线性扫描。

**修复方案**: 维护反向索引。

### P2-3: struct_ops refresh 非事务性

**文件**: `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1587-1597`

**问题**: text_poke 中途失败后 rollback 也可能失败，导致部分 site 新地址、部分旧地址的混合状态。

**修复方案**: 保存 callsite 偏移做事务性 patch/rollback。

### P2-4: __bpf_prog_put_noref 参数类型不匹配

**文件**: `vendor/linux-framework/kernel/bpf/syscall.c:3815,3828`

**问题**: `__bpf_prog_put_noref(tmp, tmp->aux->real_func_cnt)` — 第二个参数是 `u32` 被当 `bool deferred`。当前碰巧正确但是维护隐患。

**修复方案**: 改为显式 `tmp->aux->real_func_cnt > 0`。
