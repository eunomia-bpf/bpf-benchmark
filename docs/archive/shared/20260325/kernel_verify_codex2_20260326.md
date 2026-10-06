# kernel_vs_upstream_diff.patch 验证结果（Codex2，2026-03-26）

已通读 `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260325/kernel_vs_upstream_diff.patch` 全量 diff，并结合当前源码核对 `kernel/bpf/core.c`、`kernel/bpf/verifier.c`、`kernel/bpf/syscall.c` 的实际实现。

## 结论摘要

| 问题 | 结论 |
| --- | --- |
| 1. kinsn 程序不强制 `jit_needed=true` | **确认存在** |
| 2. `bpf_prog_rejit_swap` 漏掉 `has_callchain_buf` | **确认存在** |
| 3. REJIT 没重放 BTF / func_info / line_info | **确认存在** |

---

## 1. [HIGH] kinsn 程序不强制 `jit_needed=true`

### 结论

**确认存在。**

这不是“所有 kinsn 程序都会直接落到 interpreter”的问题，而是一个更具体但真实的漏洞窗口：

- `jit_requested=true`
- 程序只有主程序（`subprog_cnt <= 1`）
- verifier 保留了 kinsn pseudo-insn
- 之后主程序 JIT 在 `bpf_prog_select_runtime()` 里失败

在这个窗口下，代码会允许 interpreter fallback，而 interpreter 对 `BPF_PSEUDO_KINSN_CALL`/sidecar 并不安全。

### 关键代码

- `kernel/bpf/core.c:2521-2554`
  - `bpf_prog_select_runtime()` 只在 `CONFIG_BPF_JIT_ALWAYS_ON` 或 `bpf_prog_has_kfunc_call(fp)` 时把 `jit_needed` 置为 `true`。
- `kernel/bpf/verifier.c:3634-3647`
  - `bpf_prog_has_kfunc_call()` 明确**忽略** `desc->kinsn`，所以 kinsn-only 程序不会因为这里而强制 JIT。
- `kernel/bpf/verifier.c:23755-23777`
  - `do_misc_fixups()` 在 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)` 时会**保留** sidecar + `BPF_PSEUDO_KINSN_CALL`，不降级成 proof sequence。
- `kernel/bpf/verifier.c:23129-23140`
  - `jit_subprogs()` 在 `env->subprog_cnt <= 1` 时直接返回 `0`。
- `kernel/bpf/verifier.c:23426-23430`
  - `fixup_call_args()` 对 `jit_requested` 程序先调用 `jit_subprogs()`，返回 `0` 就**直接返回**，从而绕过后面的 non-JIT 拒绝逻辑。
- `kernel/bpf/verifier.c:23435-23453`
  - 后面的 `has_kinsn_call` 拒绝逻辑只会在上面的早返回没有发生时才执行。
- `kernel/bpf/core.c:2036-2044`
  - interpreter 的 `JMP_CALL` 直接执行 `(__bpf_call_base + insn->imm)(...)`。对 kinsn 来说，`imm` 是 **BTF id**，不是 helper/kfunc call offset。

### 为什么这是不安全的

如果 kinsn pseudo-insn 被保留到最终程序里，而主程序 JIT 又在 `bpf_prog_select_runtime()` 阶段失败，则：

- `jit_needed` 仍是 `false`
- `!fp->jited && jit_needed` 不成立，加载不会报错
- interpreter 会把 `BPF_PSEUDO_KINSN_CALL` 当普通 `BPF_CALL` 执行

这会把 `insn->imm`（BTF id）当成 `__bpf_call_base` 相对偏移来调用，语义明显错误，且是内核侧不安全执行路径。

### 修复建议

最小修复：

- 在 `bpf_prog_select_runtime()` 中把“存在 kinsn call”也视为 `jit_needed=true`。
- 实现方式可以是新增 `bpf_prog_has_kinsn_call()`，或扩展 `bpf_prog_has_kfunc_call()` 让 runtime 选择逻辑把 kinsn 也计入“必须 JIT”集合。

建议再加一层保险：

- 在 `fixup_call_args()` 里不要因为 `jit_subprogs()==0` 就对单函数 kinsn 程序提前返回。
- 或者在进入 runtime 前显式拒绝任何仍包含 `BPF_PSEUDO_KINSN_CALL` 的 non-JIT 程序。

---

## 2. [HIGH] `bpf_prog_rejit_swap` 漏掉 `has_callchain_buf`

### 结论

**确认存在。**

### 关键代码

- `include/linux/bpf.h:1832-1847`
  - `struct bpf_prog` bitfield 里定义了 `has_callchain_buf`。
- `kernel/bpf/verifier.c:12424-12441`
  - verifier 在程序使用 `bpf_get_stack()` / `bpf_get_task_stack()` 时调用 `get_callchain_buffers()`，并设置 `env->prog->has_callchain_buf = true`。
- `kernel/bpf/core.c:2925-2927`
  - 程序销毁时，`has_callchain_buf` 为真才会 `put_callchain_buffers()`。
- `kernel/bpf/syscall.c:3445-3456`
  - `bpf_prog_rejit_swap()` 交换了多项 bitfield，包括 `call_get_stack`，但**没有交换** `has_callchain_buf`。
- `kernel/bpf/syscall.c:3888-3891`
  - swap 后旧 image 所在的 `tmp` 会被释放。

### 为什么这是 bug

`has_callchain_buf` 不是纯展示字段，而是 `get_callchain_buffers()` / `put_callchain_buffers()` 的**资源所有权位**。

现在的 swap 行为会造成“语义位”和“资源所有权位”脱钩：

- old=`false`, new=`true`
  - verifier 为 `tmp` 新拿了一次 callchain buffer 引用
  - swap 后 `prog->call_get_stack` 变成 `true`，但 `prog->has_callchain_buf` 仍是 `false`
  - `tmp` 释放时却会按旧 `tmp->has_callchain_buf=true` 提前 `put_callchain_buffers()`
  - live prog 之后执行 `bpf_get_stack*()` 可能因为 callchain buffer 已被回收而失败
- old=`true`, new=`false`
  - live prog 保留旧的 `has_callchain_buf=true`
  - 旧引用不会在 swap 时释放，只会拖到最终 prog destroy，形成资源泄漏/错误持有

### 修复建议

直接修：

- 在 `bpf_prog_rejit_swap()` 的 bitfield swap 列表里补上
  - `SWAP_PROG_BITFIELD(prog->has_callchain_buf, tmp->has_callchain_buf);`

并建议顺手复核所有 `struct bpf_prog` bitfield：

- 只要字段表示“当前 image 的语义/资源所有权”，就应该和新旧 image 一起 swap。

---

## 3. [HIGH] REJIT 没重放 BTF / func_info / line_info

### 结论

**确认存在。**

而且问题不只在 `line_info`：

- 普通程序的 `btf` / `func_info` / `line_info` 会在 swap 后丢失
- `EXT` 程序虽然做了局部补丁，但仍然没有把 metadata replay 做完整

### 关键代码

- `kernel/bpf/syscall.c:3606-3614`
  - `bpf_prog_rejit()` 构造 `load_attr` 时只填了 `prog_type`、attach type、insns、log、`prog_flags`、`fd_array_cnt`。
  - **没有 replay** `prog_btf_fd`、`func_info*`、`line_info*`。
- `kernel/bpf/verifier.c:19799-19803`
  - `check_btf_info_early()` 在 `func_info_cnt==0 && line_info_cnt==0` 时直接返回。
- `kernel/bpf/verifier.c:19826-19839`
  - `check_btf_info()` 同样在上述条件下直接返回。
- `kernel/bpf/syscall.c:3688-3724`
  - 只有 `BPF_PROG_TYPE_EXT` 被特判：复制了 `btf` 和 `func_info`，并分配了一个**空白** `func_info_aux`。
  - 这里仍然**没有处理 `line_info`**。
- `kernel/bpf/syscall.c:3394-3401`
  - `bpf_prog_rejit_swap()` 无条件 swap：
    - `aux->btf`
    - `aux->func_info`
    - `aux->func_info_aux`
    - `aux->func_info_cnt`
    - `aux->linfo`
    - `aux->jited_linfo`
    - `aux->nr_linfo`
    - `aux->linfo_idx`
- `kernel/bpf/syscall.c:2379-2383`
  - `__bpf_prog_put_noref()` 释放 `btf` / `jited_linfo` / `linfo`。
- `kernel/bpf/syscall.c:2369-2370`
  - `__bpf_prog_put_rcu()` 释放 `func_info` / `func_info_aux`。

### 为什么这是 bug

当前 REJIT 流程里，`tmp` 默认拿不到原程序的 BTF metadata：

- `load_attr` 没把 `prog_btf_fd` / `func_info` / `line_info` 带进去
- verifier 看到 count 为 0，会直接跳过 BTF metadata 构建

结果是：

1. 对普通程序：
   - `tmp->aux->btf/func_info/linfo/...` 基本都是 `NULL/0`
   - `bpf_prog_rejit_swap()` 再把这些 `NULL/0` swap 到 live `prog`
   - 原来的 metadata 被转移到 `tmp`
   - `tmp` 释放时把旧 metadata 一并释放

2. 对 `EXT` 程序：
   - 只拷了 `btf` + `func_info`
   - `line_info` 仍然没 replay
   - `func_info_aux` 只是新分配的零值数组，并没有走 `check_btf_func()` 重新建立真实派生状态
   - swap 后 live prog 的 `func_info_aux` 也会被这份不完整数据替换

所以当前实现不是“metadata preserved but stale”，而是更直接的：

- 普通程序 metadata 被清空/丢失
- `EXT` metadata 只做了不完整迁移

### 修复建议

最小安全修复：

- 在当前 UAPI 不能完整提供 metadata 的前提下，先禁止 `BPF_PROG_REJIT` 作用于带有
  - `aux->btf`
  - `aux->func_info_cnt`
  - `aux->nr_linfo`
  的程序，避免 silent metadata corruption。

完整修复：

- 让 REJIT 的 internal load path 能**完整 replay**原 metadata，至少包括：
  - `btf`
  - `func_info`
  - `func_info_aux`
  - `line_info`
  - `jited_linfo` 的重新生成
- 更稳妥的方案是扩展 `BPF_PROG_REJIT` UAPI，让调用方像 `BPF_PROG_LOAD` 一样显式提供 `prog_btf_fd` / `func_info` / `line_info`，然后重新走校验与派生状态构建，而不是静默沿用/部分沿用旧 metadata。

---

## 最终判断

这 3 个问题都不是误报：

1. `kinsn` 的 interpreter fallback 保护存在缺口，且对单函数程序可达。
2. `has_callchain_buf` 确实漏 swap，资源所有权会错位。
3. REJIT 对 BTF / func_info / line_info 的 replay 明显不完整，swap 后会丢失或污染 live prog metadata。
