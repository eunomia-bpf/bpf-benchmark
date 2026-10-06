# kernel_vs_upstream_diff.patch 验证结论

已完整通读 `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260325/kernel_vs_upstream_diff.patch`（2935 行），并回到当前源码树逐点核对。

## 结论汇总

| 问题 | 结论 |
| --- | --- |
| 1. `include/linux/filter.h` 中 `smp_load_acquire(&prog->bpf_func)` 在热路径 | 部分确认：热路径位置属实；x86 运行时开销基本可忽略，ARM64 有真实额外指令成本 |
| 2. `syscall.c` `bpf_prog_rejit_swap()` 中 `memcpy(prog->insnsi, tmp->insnsi, ...)` page 粒度越界检查 | 不确认：这是误报；按当前分配/容量模型没有 OOB 写入风险 |
| 3. `verifier.c` `validate_kinsn_proof_seq()` / `INSN_BUF_SIZE=32` 是否缺少上界约束 | 确认存在：`max_insn_cnt` 没有被约束到 `INSN_BUF_SIZE`，`do_misc_fixups()` 可写爆固定 32 insn 缓冲区 |

## 1. `smp_load_acquire(&prog->bpf_func)` 在热路径

**结论**

部分确认。

- 它确实在所有 `__bpf_prog_run()` 调用的热路径上。
- 但“x86 和 ARM64 都是 critical 开销”不成立。
- x86 上运行时代价基本等价于普通 load；ARM64 上则是每次执行多一个 acquire-load，开销真实存在。

**代码位置**

- `include/linux/filter.h:700-725`
  - `__bpf_prog_run()` 热路径，`smp_load_acquire(&prog->bpf_func)` 在 `707` 行
- `kernel/bpf/syscall.c:3479-3480`
  - `bpf_prog_rejit_swap()` 用 `smp_store_release(&prog->bpf_func, tmp->bpf_func)` 发布新 JIT 入口
- `arch/x86/include/asm/barrier.h:66-72`
  - x86 `__smp_load_acquire()`
- `arch/arm64/include/asm/barrier.h:165-194`
  - arm64 `__smp_load_acquire()`

**为什么这么判断**

- x86:
  - `__smp_load_acquire()` 展开是 `READ_ONCE(*p)` + compiler `barrier()`。
  - 这里没有额外 CPU fence，也没有 locked 指令。
  - 所以它的运行时成本基本就是一次普通指针 load；更多是编译器重排约束，而不是微架构序列化成本。
- ARM64:
  - 64-bit 指针走 `ldar`，也就是 acquire-load。
  - 它不是 `dmb ish` 这种全栅栏，但确实是每次 BPF 程序执行都多一条带 acquire 语义的指令。
  - 在 XDP/TC 这类极热路径上，这个成本是真实的。
- 这个 acquire 不是无意义的：
  - 它和 `kernel/bpf/syscall.c:3480` 的 `smp_store_release()` 配对，用来把 REJIT 后的新 `bpf_func` 作为发布点。
  - 所以不能直接无脑改回普通解引用。

**修复建议**

- 如果目标是保留现有 in-place REJIT 设计，但降低默认 fast path 成本：
  - 建议加一个 static key。
  - 默认路径用 `READ_ONCE(prog->bpf_func)`。
  - 只有在系统启用过 `BPF_PROG_REJIT`/存在 live in-place swap 时，才切到 `smp_load_acquire()`。
- 如果目标是彻底去掉热路径 acquire：
  - 需要改设计，不要原地修改 live `struct bpf_prog`。
  - 改成切换 attachment/dispatcher/trampoline 指向新的不可变 prog/image。

**维护者判断**

- x86：不建议因“性能 critical”修这个点，当前实现基本已经是 free acquire。
- ARM64：如果该树确实打算让 `BPF_PROG_REJIT` 长期开启并用于包路径，建议做 static-key fast path。

## 2. `bpf_prog_rejit_swap()` 中 `memcpy(prog->insnsi, tmp->insnsi, ...)` 是否有越界写入风险

**结论**

不确认，属于误报。

**代码位置**

- `kernel/bpf/syscall.c:3746-3748`
  - `if (bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE) return -E2BIG;`
- `kernel/bpf/syscall.c:3470-3477`
  - `memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp));`
- `include/linux/filter.h:1023-1031`
  - `bpf_prog_insn_size()` / `bpf_prog_size()`
- `kernel/bpf/core.c:106-124`
  - `bpf_prog_alloc_no_stats()` 按页向上取整分配，并记录 `prog->pages`
- `include/linux/bpf.h:1862-1866`
  - `insnsi` 是 `struct bpf_prog` 尾部的 flex-array

**为什么不是 OOB**

- `bpf_prog` 分配时不是按“精确对象大小”分配，而是：
  - 先算出 `bpf_prog_size(proglen)`。
  - 再在 `kernel/bpf/core.c:106` 向上 round 到整页。
  - `prog->pages` 记录的是实际已分配容量，不是逻辑长度。
- `bpf_prog_size(tmp->len)` 也不是“仅指令字节数”：
  - 它是 `struct bpf_prog` 头部加上 `insns[tmp->len]` 尾数组后的总对象大小。
- 因此这里检查的是：
  - “新对象总大小” 是否小于等于 “旧对象实际分配总容量”
  - 而不是粗糙的 page 近似估算。
- 一旦 `bpf_prog_size(tmp->len) <= prog->pages * PAGE_SIZE` 成立：
  - 就已经保证 `prog->insnsi` 之后的尾部空间足够容纳 `tmp->len * sizeof(struct bpf_insn)` 字节。
  - 随后的 `memcpy()` 在对象已分配范围内。

**这段代码真正允许了什么**

- 它允许 REJIT 利用原 `bpf_prog` 最后一页里原先未使用的 slack 空间，把 `len` 增长到仍然落在该已分配容量以内。
- 这是容量策略问题，不是内存安全问题。

**修复建议**

- 作为 OOB 问题：不需要修。
- 如果你们的产品策略不希望 REJIT 后的逻辑程序长度超过原始长度/原始逻辑容量：
  - 可以额外引入“逻辑容量”检查。
  - 例如对比原始 `bpf_prog_size()` 或单独记录初始可接受的 `len` 上界。
  - 但这属于语义约束，不是 memory-safety 修复。

## 3. `validate_kinsn_proof_seq()` / `INSN_BUF_SIZE=32` 是否缺少 `max_insn_cnt` 上界

**结论**

确认存在。

这是一个真实的约束缺失，当前实现里是 latent bug / API footgun。

**代码位置**

- `include/linux/bpf_verifier.h:27`
  - `#define INSN_BUF_SIZE 32`
- `include/linux/bpf_verifier.h:851`
  - `env->insn_buf[INSN_BUF_SIZE]`
- `include/linux/bpf.h:968-973`
  - `struct bpf_kinsn { u16 max_insn_cnt; int (*instantiate_insn)(...) }`
- `kernel/bpf/verifier.c:3532-3536`
  - 只检查 `instantiate_insn` 非空、`max_insn_cnt` 非零
- `kernel/bpf/btf.c:9034-9040`
  - kinsn 注册路径仅检查 owner，一样没有上界
- `kernel/bpf/verifier.c:3676`
  - `validate_kinsn_proof_seq()` 只验证 `cnt <= kinsn->max_insn_cnt`
- `kernel/bpf/verifier.c:3775-3786`
  - `lower_kinsn_proof_regions()` 用 `kvcalloc(kinsn->max_insn_cnt, ...)` 动态分配 proof buffer
- `kernel/bpf/verifier.c:26477-26510`
  - verifier 恢复原始 kinsn region 后，后续还会执行 `do_misc_fixups()`
- `kernel/bpf/verifier.c:23767-23776`
  - `do_misc_fixups()` 重新调用 `kinsn->instantiate_insn(..., env->insn_buf)`

**为什么这个问题是真的**

- 前半段验证路径是安全的：
  - `lower_kinsn_proof_regions()` 按 `kinsn->max_insn_cnt` 动态分配 `proof_buf`。
- 但后半段 `do_misc_fixups()` 不一致：
  - 它把输出直接写到固定大小的 `env->insn_buf[32]`。
  - 在调用 `instantiate_insn()` 之前，没有任何 `max_insn_cnt <= INSN_BUF_SIZE` 的保护。
- 这意味着只要某个 kinsn descriptor 声明：
  - `max_insn_cnt > 32`
  - 或 `instantiate_insn()` 实际会生成超过 32 条指令
  - 就会先写爆 `env->insn_buf`，而后面的 `cnt` 检查和 `validate_kinsn_proof_seq()` 已经来不及。
- 更糟的是，即使 native emit 路径本来不打算真正 patch proof sequence：
  - `do_misc_fixups()` 也是先 `instantiate_insn(..., env->insn_buf)`，
  - 然后才在 `23776` 行判断 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)` 并跳过。
  - 所以 native emit 场景同样带着这个溢出窗口。

**当前树里的可触发性**

- 我没有在当前源码树里找到 in-tree 的 kinsn descriptor 实例。
- 所以这更像是“基础设施已经写出 bug，但尚未有 in-tree provider 触发”的 latent bug。
- 但从 API 设计看，问题已经存在，只要后续模块/内核代码注册了 `max_insn_cnt > 32` 的 kinsn，就会踩到。

**修复建议**

- 最稳妥的修法：
  - 把 `do_misc_fixups()` 的 kinsn 分支改成动态 scratch/proof buffer，
  - 大小按 `kinsn->max_insn_cnt` 分配，
  - 与 `lower_kinsn_proof_regions()` 保持一致。
- 最小修法：
  - 在 `__register_btf_kfunc_id_set()` 或 `add_kfunc_desc()` 强制 `max_insn_cnt < INSN_BUF_SIZE`，
  - 否则拒绝注册/拒绝加载。
- 额外优化：
  - 对于 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)` 的路径，先判断是否 native emit，
  - 再决定是否需要调用 `instantiate_insn()`，避免无意义地碰固定缓冲区。

## 最终判断

建议把优先级排序为：

1. 先修问题 3：这是确实存在的边界缺失。
2. 问题 2 不要按 OOB 方向处理；如果要改，只能按“REJIT 是否允许利用页内 slack 增长逻辑长度”的策略问题处理。
3. 问题 1 不应按“x86/ARM64 都是 critical 性能 bug”定级；更准确的定性是“热路径位置属实，ARM64 有真实额外成本，x86 基本无运行时成本”。
