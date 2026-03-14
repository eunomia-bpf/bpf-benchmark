# BPF_PROG_JIT_RECOMPILE 的 Re-JIT 原子性与 RCU 安全性分析

## 0. 结论

当前 `vendor/linux-framework/kernel/bpf/jit_directives.c` 里的 `bpf_prog_jit_recompile()` 只能算 benchmark/POC 机制，不是 production-safe 的 live re-JIT。

结论可以先压缩成四点：

1. 当前实现没有对正在运行的 CPU 做 RCU retirement，也没有对 image swap 做事务化提交。
2. 它通常不会把 CPU 带到 "partial native image" 上执行，因为 x86 JIT 是先生成一份完整的新 image，再把 `prog->bpf_func` 改到新地址；但这不等于整体状态原子。
3. 当前实现最大的现实问题不是旧 image 被过早 free，而是旧 image 根本没有被回收，导致永久 JIT text leak；同时 `extable`、kallsyms、tailcall/trampoline 等外部状态不会随 `prog->bpf_func` 一起一致更新。
4. 如果场景严格收窄到 "单线程 load -> recompile -> `BPF_PROG_TEST_RUN`" 的 POC，通常可以工作；一旦进入 attached / multi-CPU / tailcall / trampoline / concurrent recompile 的 production 场景，就不安全也不完整。

本文以 `linux-framework` 当前 x86_64 实现为分析对象。

## 1. 当前实现实际做了什么

### 1.1 re-JIT syscall 路径

`bpf_prog_jit_recompile()` 的核心逻辑在 `vendor/linux-framework/kernel/bpf/jit_directives.c:2490-2560`：

- 通过 `bpf_prog_get()` 拿到已加载 prog。
- 直接改 `prog->aux->jit_policy`。
- 然后直接调用 `bpf_jit_recompile_prog_images(prog)`。

这里没有：

- per-prog mutex
- RCU grace period
- old/new image 的双缓冲提交对象
- old policy 的事务化 rollback

### 1.2 实际 re-JIT 的方式

`bpf_jit_recompile_prog_images()` 在 `vendor/linux-framework/kernel/bpf/jit_directives.c:2418-2487`：

- 单函数程序：直接 `bpf_int_jit_compile(prog)`。
- 多 subprog 程序：模仿 `jit_subprogs()`，先给各 subprog 做一轮 JIT，改写 bpf-to-bpf call 目标，再做 final extra pass。
- 最后把 `prog->bpf_func`、`jited_len`、`aux->extable` 等字段改到新的主 image。

问题在于：这是把 load-time JIT machinery 直接拿来做 live program mutation，但没有补 live swap 所需的同步层。

### 1.3 x86 JIT 自身不是 in-place patch old image

`bpf_int_jit_compile()` 在 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5039-5255`：

- 先通过 `bpf_jit_binary_pack_alloc()` 分配新的 RO+X image 和 RW staging buffer。
- 在 RW buffer 中完成所有 pass。
- 通过 `bpf_jit_binary_pack_finalize()` 把 staging buffer 拷到最终 RO image。
- 最后才把 `prog->bpf_func` 指向新 image（`5231-5233`）。

因此，"新代码字节 torn read" 不是当前实现的主风险；真正的问题是 `prog` 的其他元数据、外部 direct-call 用户、以及旧 image 生命周期都没有一起被正确管理。

## 2. upstream 现有的 RCU / free 模式

### 2.1 正常 prog free 不是立即 free JIT image

当前树里的正常程序释放路径是：

- `__bpf_prog_put_noref()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:2377-2396`
- 先 `call_rcu()` 或 `call_rcu_tasks_trace()`
- 回调 `__bpf_prog_put_rcu()` 再进入 `bpf_prog_free()`
- `bpf_prog_free()` 调度 work 到 `bpf_prog_free_deferred()`（`vendor/linux-framework/kernel/bpf/core.c:2948-2957`）
- `bpf_prog_free_deferred()` 最后才调用 `bpf_jit_free()`（`2907-2945`）

这说明 upstream 对 "程序可能正在别的 CPU 上执行" 的基本答案是：先过 grace period，再 free JIT image。

### 2.2 `bpf_jit_free()` 本身不提供 RCU

`bpf_jit_free()` 在 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5281-5314`：

- 它只负责释放当前 `prog->bpf_func` 对应的 pack/header 和私有栈。
- 它假定调用者已经把并发执行问题解决了。

也就是说：

- RCU 语义在 `bpf_prog_put` / `bpf_prog_free` 路径里，
- 不在 `bpf_jit_free()` 里。

如果 live re-JIT 想回收旧 image，不能直接照着 `bpf_jit_free()` 干，必须先有与 `bpf_prog_put` 同级别的 grace-period 协议。

### 2.3 `bpf_prog_pack` 只是 allocator，不是 live swap 协议

`bpf_prog_pack_alloc/free()` 与 `bpf_jit_binary_pack_alloc/finalize/free()` 在 `vendor/linux-framework/kernel/bpf/core.c:939-1211`。

它们提供的是：

- RO+X pack allocator
- RW staging buffer
- finalize copy
- free 时的 text invalidate

它们不提供：

- old/new image publish
- external call site refresh
- retired image 的 RCU 延迟回收

所以 `bpf_prog_pack` 是必要基础设施，但不是 live re-JIT 完整解法。

## 3. 当前实现的安全性分析

## 3.1 use-after-free 风险

### 3.1.1 对旧 JIT image：当前实现更接近 "leak" 而不是 "UAF"

单线程 recompile 时，当前代码不会主动 free 旧 image。

原因是：

- `bpf_int_jit_compile()` 为新 image 重新分配 header/pack。
- 成功后直接覆盖 `prog->bpf_func`（`5231-5233`）。
- 旧 image 的 header 指针从此丢失。
- 程序最终 unload 时，`bpf_jit_free()` 只能释放最后一次 `prog->bpf_func` 指向的 image。

因此当前状态是：

- 旧 image 不会在 re-JIT 时被过早释放。
- 但每次 re-JIT 都会永久 leak 一份 JIT text / extable / pack chunk。

这不是小问题。它意味着即便在 POC 中，每次 `BPF_PROG_JIT_RECOMPILE` 都可能永久消耗一份 executable memory，直到 reboot。

### 3.1.2 对 policy：存在并发 recompile 下的 UAF / corruption 风险

`bpf_prog_jit_recompile()` 直接改 `prog->aux->jit_policy`，并立即 free `old_policy`（`2543-2547`）。与此同时，x86 JIT 在 `do_jit()` 中每条指令都可能读取 `main_aux->jit_policy`（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2976-2999`）。

如果两个线程同时对同一个 prog 做 recompile：

- 线程 A 开始 JIT，正在读 policy A。
- 线程 B 把 `prog->aux->jit_policy` 改成 policy B，并 free policy A。
- 线程 A 继续在 `do_jit()` 里解引用已经释放的 policy A。

这是真正的 UAF 风险，而且不需要任何 data-plane 并发，只需要 concurrent control-plane recompile。

### 3.1.3 对 `jit_data`：并发 recompile 也可能破坏 subprog extra-pass 状态

subprog re-JIT 会依赖 `prog->aux->jit_data` 保存 first pass 的中间状态；`bpf_int_jit_compile()` 在 `5073-5109` / `5207-5214` / `5247-5249` 明确把 `jit_data` 当成 "是否处于 extra_pass" 的状态机。

没有锁意味着：

- 一个线程可能刚完成 first pass，`jit_data` 仍挂在 prog 上。
- 另一个线程就可能把同一个 prog 当作 extra-pass 对象继续编译。

这会把同一份 staging/header 状态交叉使用，属于明显的 data race / state corruption。

## 3.2 torn read / partial image 风险

### 3.2.1 对 native text 本身：风险相对低

当前实现不是在 old image 上原地改字节，而是：

- 新建 image
- 完整生成
- finalize copy
- 最后改 `prog->bpf_func`

对 x86_64 来说，这意味着：

- `prog->bpf_func` 是一次指针更新，而不是边执行边 patch 整段 text
- CPU 不太会跳进 "写了一半的新 image"

所以如果问题是狭义的 "会不会执行到半成品机器码"，答案偏向不会。

### 3.2.2 但整体状态不是原子交换

虽然 native text 不是 torn write，`struct bpf_prog` 的整体状态仍然不是原子提交：

- `aux->extable` 在分配新 image 时就被提前改写（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5175-5183`）
- `prog->bpf_func`、`jited_len`、`aux->extable`、kallsyms 信息不是一个单一对象一起 swap
- 没有 `rcu_assign_pointer(current_image, new_image)` 这种单指针 publish

所以准确说法应当是：

- "partial text" 风险低
- "partial program state" 风险高

## 3.3 `extable` / kallsyms / jited_linfo 不一致

### 3.3.1 `extable` 可能和正在执行的 image 不匹配

`search_bpf_extables()` 在 `vendor/linux-framework/kernel/bpf/core.c:786-801`：

- 先通过 BPF ksym tree 找到哪个 prog 覆盖了 faulting IP
- 再用 `prog->aux->extable` 查异常表

但 re-JIT 时：

- `aux->extable` 可能已经指向新 image 的 extable
- kallsyms / ksym tree 仍然保留旧 image 的地址范围

结果是：

- old IP 可能还命中旧 ksym range
- 但 lookup 使用的是新 extable

这会导致异常处理 lookup 错位。

### 3.3.2 kallsyms 根本没有在 re-JIT 后更新

`bpf_prog_kallsyms_add()` 只在初次 load 成功时调用（`vendor/linux-framework/kernel/bpf/syscall.c:3118-3133`），它会把 `aux->ksym.start/end` 设成当前 `prog->bpf_func` / `jited_len`（`vendor/linux-framework/kernel/bpf/core.c:557-564`），并插入 RCU 保护的 BPF ksym tree/list（`642-682`）。

当前 re-JIT 路径没有：

- `bpf_prog_kallsyms_del()`
- `bpf_prog_kallsyms_add()`
- 也没有新的 retired ksym node

因此 re-JIT 之后：

- 新 image 地址不在 BPF ksym tree 中
- 旧 image 地址仍被认为是该 prog 的 text range

这会影响：

- `search_bpf_extables()`
- `is_bpf_text_address()`
- BPF 地址到符号名的 lookup
- unwind / debug / perf 符号化

### 3.3.3 `jited_linfo` 是原地改写，不是带 RCU 的版本切换

`bpf_prog_fill_jited_linfo()` 在 `vendor/linux-framework/kernel/bpf/core.c:229-256` 直接原地写 `prog->aux->jited_linfo[]`。

这不是 data-plane 热路径，但它说明当前 re-JIT 不是 "build shadow metadata -> publish" 模式，而是直接改 live aux state。

## 3.4 `bpf_prog_test_run` 场景是否安全

### 3.4.1 单线程、顺序式 POC：大体可用

`bpf_prog_test_run()` 只是取 prog ref 后调用 `prog->aux->ops->test_run()`，而常见 test path 最终走到 `bpf_prog_run()` / `bpf_prog_run_xdp()`（`vendor/linux-framework/kernel/bpf/syscall.c:4713-4738`，`vendor/linux-framework/net/bpf/test_run.c:389-435`）。

这条路径每次执行时直接读取当前 `prog->bpf_func`（`vendor/linux-framework/include/linux/filter.h:700-730`）。

因此如果满足下面条件：

- prog 没 attach 到真实 data-plane
- 没有别的 CPU 正在跑它
- 没有第二个线程同时做 recompile
- 典型顺序是 `load -> recompile -> test_run`

那么当前实现通常能工作。

### 3.4.2 但它仍然有两个 POC 层面的硬限制

1. 每次 recompile 都 leak 一份旧 image，哪怕后面把 prog close 了也不会回收那份旧 text。
2. 如果 `test_run` 正在 repeat loop，另一个线程同时 recompile，同一个 benchmark 过程中不同 iteration 可以看到不同 `prog->bpf_func`。

所以更准确的表述是：

- "单线程 test_run benchmark 勉强 OK"
- 不是 "任何 test_run 都安全"

## 3.5 production 多 CPU 并发执行是否安全

结论：不安全，也不完整。

原因不是单一的一条，而是四类问题叠加。

### 3.5.1 没有 old image retirement 协议

upstream 的 whole-prog free 会先经过 `call_rcu()` / `call_rcu_tasks_trace()`，当前 re-JIT 没有任何等价步骤。

当前代码之所以暂时没把 data-plane 立刻打成 UAF，只是因为它根本没 free old image，而不是因为 swap protocol 正确。

这意味着：

- 现在是 leak 替代了 UAF
- 以后如果有人天真地在 recompile 后补一行 "free old image"，没有 RCU 就会立刻变成真正的 UAF

### 3.5.2 tailcall direct-jump 用户不会跟着更新

prog array poke 机制会把 caller text 直接 patch 到 callee 的 `bpf_func + adj_off`（`vendor/linux-framework/kernel/bpf/arraymap.c:1107-1152`，`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5346-5392`）。

当前 re-JIT 没有重新跑这些 poke update，因此：

- 现有 tailcall caller 会继续跳到旧 callee image
- re-JIT 对这些调用点没有生效

更糟的是，x86 `__bpf_arch_text_poke()` 会校验当前 text 是否仍等于 `old_addr` 对应的旧指令（`593-635`）。如果后续 map update / teardown 时：

- patch site 里还是更老的一份地址
- 但 `old->bpf_func` 已经被 re-JIT 改成新地址

那么 tailcall unpatch/repatch 会出现 `-EBUSY`，而 `bpf_arch_poke_desc_update()` 对负值是 `BUG_ON(ret < 0)`（`5362-5390`）。
也就是说，当前 re-JIT 和 tailcall direct-patch 组合起来不仅是不生效，还可能把后续更新路径带到 BUG。

### 3.5.3 trampoline / freplace / extension 这类 direct target 也不会自动刷新

trampoline link/update 路径会把具体的 `prog->bpf_func` 地址 patch 进目标 call/jump site（`vendor/linux-framework/kernel/bpf/trampoline.c:370-386`, `402-435`, `795-798`, `863-865`）。

当前 re-JIT 没有调用任何 trampoline refresh/update，因此：

- 已安装的 trampoline / extension 仍可能继续落到旧 image
- 后续 unlink / modify 时又会按新的 `prog->bpf_func` 作为 old target 去 patch，和实际 text 中的旧 target 不一致

这至少会导致 detach/update 失败，严重时可能留下 stale call target。

### 3.5.4 dispatcher 是最接近 "可容忍" 的例外，但也不是完整支持

dispatcher 路径比 tailcall/trampoline 好一些：

- dispatcher image 保存的是 "已知 prog->bpf_func 集合"
- 如果传进来的 `bpf_func` 不在缓存集合里，x86 dispatcher 会回退成对 `rdx` 的间接跳转（`vendor/linux-framework/kernel/bpf/dispatcher.c:94-135`，`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4910-4975`）

所以对 dispatcher 而言，re-JIT 后通常是：

- correctness 还能成立
- 但 direct-call optimization cache 失效，性能退回 indirect path

这说明 dispatcher 的设计比当前 re-JIT 更接近 live swap 需要的模型，但它仍然没有帮你解决 retired image 的 RCU 回收。

## 4. 当前实现在 POC 阶段应如何表述 limitation

如果当前 POC 只面向 benchmark / `bpf_prog_test_run`，建议在文档里明确写成下面这种限制集，而不是暗示 production-safe：

1. 只支持 detached benchmark prog，不支持 attached production prog。
2. 只支持单线程 control-plane；同一个 prog 不能并发发起多个 `BPF_PROG_JIT_RECOMPILE`。
3. 不承诺与 tailcall direct-jump、trampoline/freplace/extension、sleepable tracing program 的 live attachment 兼容。
4. 每次 re-JIT 都会永久 leak 旧 JIT image；因此只适合短生命周期实验内核 / VM，不适合长时间运行。
5. failure path 不是事务性 rollback：当前代码在失败时保留 old image，但 old policy 已经丢失。

如果要给一句最短版 limitation：

> 当前 `BPF_PROG_JIT_RECOMPILE` 是单机 benchmark POC，只保证 "重新生成另一份 JIT image 并让后续直接 `bpf_prog_run()` 看到它"；不保证 live attached execution、旧 image 生命周期管理、外部 direct-call target 更新、或失败回滚的事务性。

## 5. Production-ready 需要的改动

## 5.1 必须先加串行化和事务语义

至少需要一个 per-prog `rejit_mutex`，保护：

- `prog->aux->jit_policy`
- `prog->aux->jit_data`
- live image publish

并且改成：

- parse 新 policy
- build 新 image
- 所有校验和 refresh 都成功后再 commit
- commit 成功后再 free old policy

当前这种 "先换 policy，再 JIT，失败再清空 policy" 不是事务。

## 5.2 必须把 "编译结果" 从 live `struct bpf_prog` 中拆出来

production-ready 不应让 `bpf_int_jit_compile()` 一边编译一边直接改 live `prog->bpf_func` / `aux->extable`。

更合理的形式是先产出一个 shadow object，例如：

```c
struct bpf_rejit_image {
	void *bpf_func;
	u32 jited_len;
	struct exception_table_entry *extable;
	u32 num_exentries;
	struct bpf_binary_header *ro_header;
	struct bpf_binary_header *rw_header;
	struct bpf_ksym ksym;
	void **jited_linfo;
	struct rcu_head rcu;
};
```

然后：

- 编译阶段只写 shadow image
- commit 阶段用一次 publish 把 current image 从 old 换成 new

如果继续让 JIT 直接改 live `prog` 字段，就很难得到真正的原子提交。

## 5.3 必须给 old image 做 RCU retirement

最少应 mirror whole-prog free 的语义：

- normal prog: `call_rcu()`
- sleepable prog: `call_rcu_tasks_trace()`

RCU callback 里做：

- retired ksym 删除
- old pack/header free
- old extable 一并回收

换句话说，production-ready 需要一个 "image-level deferred free"；当前 upstream 只有 "prog-level deferred free"。

## 5.4 必须把 kallsyms / extable 也纳入版本化 swap

不能只换 `prog->bpf_func`。

需要一起处理：

- `jited_len`
- `extable`
- `num_exentries`
- current ksym
- 旧 ksym 的 grace-period 保留

否则 fault lookup、地址解析、unwind 仍然会看到错位状态。

## 5.5 必须刷新所有外部 direct-call users

至少要覆盖：

1. tailcall poke descriptors
   需要把所有 `poke_tab` site 从 old image repatch 到 new image，然后再退休 old image。

2. trampoline / freplace / extension
   需要显式调用 old/new addr modify path；不能假设只改 `prog->bpf_func` 就足够。

3. dispatcher
   correctness 可以暂时依赖 indirect fallback，但如果要保持原优化效果，仍应 refresh dispatcher cache。

如果不想一次性把这些都做完，至少应该在 syscall 里显式拒绝带这些特征的 prog，而不是静默接受。

## 5.6 failure 必须保持 old image + old policy 不变

production-ready failure 语义应该是：

- 新 image build 失败：丢弃 new image
- live state 完全不变
- old policy 不丢

现在的行为是：

- old image 还在
- 但 old policy 可能已 free
- `prog->aux->jit_policy` 可能被清成 `NULL`

这不是可靠 rollback。

## 5.7 更干净的路线其实是 "whole-prog replace"，不是 "in-place mutate"

如果允许调整 UAPI / control-plane 语义，更干净的方案通常不是在已有 `struct bpf_prog` 上做 in-place image swap，而是：

- 基于同一份 xlated insns 构造一个新 `struct bpf_prog`
- JIT 出完整的新 prog
- 复用现有 attach replace / `bpf_prog_put` / RCU 退役路径去替换旧 prog

这条路线和 upstream 现有对象生命周期更一致，也更少踩到 tailcall/trampoline/kallsyms 的隐式耦合。

如果必须保留 "same prog_fd, in-place re-JIT" 语义，那就需要前面 5.1-5.6 的整套 image-level swap 基础设施。

## 6. 与 upstream `bpf_prog_pack` / multi-shot JIT 的关系

## 6.1 `bpf_prog_pack`

`bpf_prog_pack` 解决的是：

- executable memory 分配
- RO/RW 双缓冲 finalize
- free 时 text invalidate

它没有解决：

- live image publish
- old image grace-period retirement
- external patched call-site refresh

因此它是 live re-JIT 的 building block，不是 live re-JIT 本身。

## 6.2 multi-shot JIT / `jit_subprogs()` extra pass

`jit_subprogs()` 在 `vendor/linux-framework/kernel/bpf/verifier.c:22781-23032` 的 two-pass / extra-pass 机制，解决的是：

- bpf-to-bpf call 目标地址在 final pass 前不稳定
- subprog 需要 first pass 分配 image，second pass 固定 call displacement

它成立的前提是：

- 程序还没对外公开执行
- 或至少对应 image 还没进入 live attachment / steady-state runtime

所以 multi-shot JIT 是 compile-time convergence 机制，不是 runtime-safe swap 机制。

当前 `bpf_jit_recompile_prog_images()` 本质上是在复用 `jit_subprogs()` 的 load-time JIT 逻辑，但没有补上 live system 需要的：

- serialization
- current/retired image versioning
- RCU
- external call-site refresh

换句话说：

- `jit_subprogs()` 负责 "怎么把新 image 编出来"
- live re-JIT 还需要另一层负责 "怎么把新 image 安全地替进去，并把旧 image 安全地下线"

## 6.3 真正更像 live swap 的现有参考其实是 trampoline；dispatcher 和 tailcall 只覆盖局部子问题

如果找 upstream 中更接近 live update 的模式，最值得借鉴的是 trampoline：

- trampoline update/release 是最像 "先切新入口，再延后回收旧 image" 的两段式协议
- 切换点在 `bpf_trampoline_update()` / `modify_fentry()`
- 旧 trampoline image 的退休则走 `bpf_tramp_image_put()`，其中组合了 text patch、`call_rcu_tasks()`、`percpu_ref_kill()`、再次 `call_rcu_tasks()` 等步骤

这比当前 re-JIT 缺失的东西更接近 production 需求，因为它把 "入口替换" 和 "旧 image 生命周期结束" 明确拆成了两个阶段。

相对地，dispatcher 和 tailcall 只覆盖局部子问题：

- dispatcher 提供了双 buffer + `synchronize_rcu()` 的思路（`vendor/linux-framework/kernel/bpf/dispatcher.c:106-135`）
- tailcall poke 提供了 direct text patch + `synchronize_rcu()` 的思路（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5375-5389`）
- trampoline image free 展示了 `call_rcu_tasks*` 与 text patch 的组合方式（`vendor/linux-framework/kernel/bpf/trampoline.c:520-562`）

production-ready re-JIT 更像是要把这些机制组合起来，而不是单独依赖 `bpf_prog_pack` 或 multi-shot JIT。

## 7. 建议落地表述

建议在论文 / 设计文档中把当前实现明确表述为：

- 一个 benchmark-oriented post-load re-JIT POC
- 当前安全边界是 detached `test_run` / no concurrent recompile
- 尚未实现 production-safe live swap

如果需要一句更直接的工程结论：

> 当前 `BPF_PROG_JIT_RECOMPILE` 可以证明 "userspace policy -> kernel re-JIT" 这条控制面链路是可行的；但它还没有实现 production 级的原子 image swap，也没有实现 old image 的 RCU retirement，因此不能把它描述成可安全部署在多 CPU live data-plane 上的机制。
