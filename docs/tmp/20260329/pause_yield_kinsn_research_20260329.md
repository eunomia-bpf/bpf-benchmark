# PAUSE/YIELD 在 BPF 程序中的优化价值调研

日期：2026-03-29  
面向项目：BpfReJIT / kinsn 调研  
相关入口：`docs/kernel-jit-optimization-plan.md` 的 `PAUSE/YIELD` 条目  
历史上下文：`~/.codex/sessions/2026/03/29/rollout-2026-03-29T18-33-23-019d3c5f-ca22-7140-998c-6add79dc46af.jsonl`、`~/.codex/sessions/2026/03/29/rollout-2026-03-29T18-52-29-019d3c71-4654-70b1-a9aa-6fb0dc9dfd38.jsonl`

## TL;DR

- 对当前 `authoritative compiled corpus` 做静态扫描后，`PAUSE/YIELD` 对 BPF 程序本身几乎没有可优化面。
- `corpus/results/expanded_corpus_build_authoritative_20260310.json` 记录了 `429` 个 `compiled_ok` 对象，但其中有 `1` 个 `.o` 已缺失，所以实际可扫描对象数是 `428`。
- 对这 `428` 个已存在对象做 relocation 扫描后，`bpf_spin_lock` / `bpf_spin_unlock` 的引用数都是 `0`。唯一命中的锁相关对象是 `res_spin_lock.bpf.o`，其中 `bpf_res_spin_lock` 为 `8` 处、`bpf_res_spin_unlock` 为 `9` 处。
- 更关键的是，当前锁等待发生在 kernel helper / kfunc 内部，不在 BPF JIT 出来的指令流里。也就是说，一个“简单的 PAUSE/YIELD kinsn”无法穿透 helper 调用边界，通常根本碰不到真实的 spin-wait。
- x86 普通 spinlock 路径已经通过 `cpu_relax()->pause` 获得等待 hint；arm64 普通 qspinlock 和 reserved qspinlock 主路径也优先走 `WFE` / `__cmpwait_relaxed`。`yield` 在 arm64 上只出现在某些 fallback polling loop。
- 结论是：如果只是实现一个“在 BPF 指令流中发射 PAUSE/YIELD”的低复杂度 kinsn，当前收益近似为零；如果要获得真实收益，就必须进一步做 lock helper 语义下沉或内联，这已经不再是“小 kinsn”，而是 verifier / helper / lock semantics 级别的工程。

## 1. 调研范围与方法

本文只做静态调研，不改代码，不跑 VM。

本次结论由三部分组成：

1. 恢复并复核 2026-03-29 被中断的两次 session 结论。
2. 直接使用当前仓库中的 `expanded_corpus_build_authoritative_20260310.json` 与现存 `.bpf.o` 文件重新统计 site count。
3. 追 helper / kfunc 到内核锁实现，确认 x86 与 arm64 上真实等待原语的落点。

统计口径有两个约束：

- 我只统计 `compiled corpus` 中真实存在的 `.o`，避免把源码存在但编译失败的 upstream selftest 误算成真实 workload 覆盖。
- 我统计的是 ELF relocation 对 `bpf_spin_lock` / `bpf_res_spin_lock` 等符号的引用，而不是 grep 源码字符串。这样能避开条件编译、死代码和源码缺失噪声。

## 2. Corpus 覆盖率结论

### 2.1 真实可扫描对象数

`corpus/results/expanded_corpus_build_authoritative_20260310.json` 的 summary 显示：

- `compiled_ok = 429`
- `compiled_failed = 641`

但 `429` 个 `compiled_ok` 对象中有 `1` 个文件当前并不存在：

- `/home/yunwei37/workspace/bpf-benchmark/corpus/build/libbpf-bootstrap/examples/c/profile.bpf.o`

因此本次实际扫描对象数为：

- `428` 个现存 `.bpf.o`

### 2.2 锁 helper 的静态 site count

对 `428` 个现存对象执行 `llvm-readelf -r` 扫描，结果如下。

| 指标 | 数值 |
|---|---:|
| `bpf_spin_lock` 引用数 | 0 |
| `bpf_spin_unlock` 引用数 | 0 |
| `bpf_res_spin_lock` 引用数 | 8 |
| `bpf_res_spin_unlock` 引用数 | 9 |
| 含任意 spin-lock helper/kfunc 的对象数 | 1 |

唯一命中的对象是：

- `/home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o`

这意味着：从当前 `compiled corpus` 的真实覆盖看，普通 `bpf_spin_lock` 根本没有进入样本，只有一个 reserved spinlock 的 selftest 对象进入了样本。

### 2.3 为什么“源码里有 spin_lock”不等于“compiled corpus 里有机会”

同一份 authoritative build 清单里，和 spin lock 相关但编译失败的 upstream selftest 还有不少，例如：

- `tools/testing/selftests/bpf/progs/arena_spin_lock.c`
- `tools/testing/selftests/bpf/progs/test_spin_lock.c`
- `tools/testing/selftests/bpf/progs/test_spin_lock_fail.c`
- `tools/testing/selftests/bpf/progs/verifier_spin_lock.c`
- `tools/testing/selftests/bpf/progs/stream.c`
- `tools/testing/selftests/bpf/progs/stream_fail.c`

这说明源码树里不是完全没有 spin lock 用例，但它们没有进入当前可运行、可度量的 compiled corpus。对 OSDI 评估和当前 benchmark pipeline 来说，应该以 `compiled corpus` 为主，不应以“源码里曾出现过”替代“真实 workload 覆盖”。

### 2.4 唯一命中对象的性质

唯一命中的 `res_spin_lock.bpf.o` 也不是业务型程序，而是专门做死锁、超时和 held-lock-table 边界覆盖的 selftest。

从 `vendor/linux-framework/tools/testing/selftests/bpf/progs/res_spin_lock.c` 可以直接看到：

- `res_spin_lock_test()` 在同一 map element 上做双重加锁，验证返回值与 `-EDEADLK`。
- `res_spin_lock_test_AB()` / `res_spin_lock_test_BA()` 明确构造 AB/BA 锁顺序。
- `res_spin_lock_test_held_lock_max()` 刻意填满 held lock table，并验证超时路径与 `> 1/4s` 的等待行为。

因此，这个对象能证明“reserved spinlock 相关指令在 corpus 中不是绝对零”，但它更像 adversarial correctness test，而不是 production hot path。

## 3. 真实等待发生在哪里

### 3.1 普通 `bpf_spin_lock` 不是 BPF 指令内联循环

`vendor/linux-framework/kernel/bpf/helpers.c` 里，`bpf_spin_lock()` 的实现路径是：

- `bpf_spin_lock()`
- `__bpf_spin_lock_irqsave()`
- `__bpf_spin_lock()`
- `arch_spin_lock()`

也就是说，BPF 程序看到的是一次 helper call。真实 spin-wait 发生在 helper 进入内核锁实现之后，而不是 BPF JIT 展开的指令流里。

这点对 kinsn 很关键：

- 如果我们只是给 BPF 指令集新增一个 `PAUSE` / `YIELD` hint 指令，它只能优化“BPF 程序自己写出来的 busy loop”。
- 它不能自动改变 helper 内部已经存在的 kernel spinlock 等待逻辑。

### 3.2 `bpf_res_spin_lock` 也一样

`vendor/linux-framework/kernel/bpf/rqspinlock.c` 里，`bpf_res_spin_lock()` 只是：

- `preempt_disable()`
- `res_spin_lock((rqspinlock_t *)lock)`

`res_spin_lock()` 本身先尝试 fast-path `atomic_try_cmpxchg_acquire()`，失败后再进入 `resilient_queued_spin_lock_slowpath()`。

所以 reserved spinlock 也不是“BPF 程序里有一个可直接替换成 hint 指令的自旋循环”；真正等待依然在 kernel 里的 lock implementation。

## 4. 现有内核路径已经怎么做等待 hint

### 4.1 x86 普通 spinlock：native/generic 路径已经有 `PAUSE`

普通 `bpf_spin_lock` 在 queued spinlock 路径上最终会走到：

- `arch_spin_lock -> queued_spin_lock -> queued_spin_lock_slowpath`

`queued_spin_lock_slowpath()` 里的等待点包括：

- `atomic_cond_read_relaxed(&lock->val, ...)`
- `smp_cond_load_acquire(&lock->locked, !VAL)`
- 某些退化路径中的 `while (!queued_spin_trylock(lock)) cpu_relax();`

而 generic spin-wait 宏 `smp_cond_load_relaxed()` 明确在循环中调用 `cpu_relax()`。

x86 上，`vendor/linux-framework/arch/x86/include/asm/vdso/processor.h` 定义：

- `native_pause()` 发射 `pause`
- `cpu_relax()` 直接调用 `native_pause()`

因此，对普通 spinlock 而言，x86 等待路径已经天然带 `PAUSE` hint。一个额外的 BPF-side `PAUSE` kinsn 并不能替代 helper 内部已有的 `pause`。

### 4.2 arm64 普通 spinlock：主路径其实是 `WFE`，不是 `YIELD`

这次调研里最容易被旧认知误导的一点是：`docs/kernel-jit-optimization-plan.md` 里把该项写成了 “x86 `PAUSE` + ARM64 `YIELD`”，但对当前内核树的真实 helper 路径，这个表述过于简化。

在 arm64 上：

- `vendor/linux-framework/arch/arm64/include/asm/barrier.h` 重新定义了 `smp_cond_load_relaxed()` 与 `smp_cond_load_acquire()`
- 这两个宏都不是 generic 的 `cpu_relax()` polling loop
- 它们在等待时直接调用 `__cmpwait_relaxed(__PTR, VAL)`

而 `vendor/linux-framework/arch/arm64/include/asm/cmpxchg.h` 中 `__cmpwait_case_*()` 的汇编序列明确包含：

- `sevl`
- `wfe`
- `ldxr*`
- 条件不满足时再次 `wfe`

所以，对 arm64 普通 qspinlock 而言，helper 内部主等待原语已经是 `WFE-style` event wait，而不是单纯的 `yield` 自旋。

### 4.3 arm64 reserved spinlock：`WFE` 优先，`YIELD` 只在 fallback

reserved spinlock 的 arm64 特化在：

- `vendor/linux-framework/arch/arm64/include/asm/rqspinlock.h`

这里的 `smp_cond_load_acquire_timewait()` 分成两条路径：

- 如果 `arch_timer_evtstrm_available()` 为真，走 `__smp_cond_load_acquire_timewait()`，内部使用 `__cmpwait_relaxed()`，因此是 `WFE-style` 等待。
- 如果 event stream 不可用，退回 `__smp_cond_load_relaxed_spinwait()`，该路径里才会执行 `cpu_relax()`。

而 arm64 的 `cpu_relax()` 在 `vendor/linux-framework/arch/arm64/include/asm/vdso/processor.h` 中定义为：

- `asm volatile("yield" ::: "memory");`

因此，arm64 上更准确的描述应当是：

- 普通 spinlock helper 路径：主要是 `WFE-style`
- reserved spinlock timewait 路径：优先 `WFE-style`，无 event stream 时才 fallback 到 `yield`

换句话说，当前计划文档里的 “ARM64 YIELD” 更像是 fallback 心智模型，不是主路径事实。

## 5. 对 kinsn 设计的直接含义

### 5.1 “简单 PAUSE/YIELD kinsn”几乎没有收益

如果这个 kinsn 的语义只是：

- 在 BPF 指令流里发射一个 x86 `pause`
- 或在 BPF 指令流里发射一个 arm64 `yield`

那么它只有在下面这类场景里才会有意义：

- BPF 程序字节码自身包含显式 busy-wait loop
- 这个 loop 没有被 helper 调用边界包住
- 这个 loop 还是 hot path

而当前事实是：

- `compiled corpus` 中普通 `bpf_spin_lock` site count 为 `0`
- 唯一命中的 reserved spinlock 对象是自测型 selftest
- 真实等待主要发生在 helper / kfunc 内部

所以当前树上一个“简单 kinsn”的预期收益应视为近似零。

### 5.2 真正有收益的方向已经不是“小 kinsn”

如果要让这类优化在当前项目里真的产生可测收益，至少要进入下面几类更重的改造之一：

- 把 `bpf_spin_lock` / `bpf_res_spin_lock` 的语义下沉到 REJIT，跨 helper 边界识别并重写锁操作。
- 在 verifier / helper 约束不变的前提下，对 lock fast path / slow path 做更激进的 helper specialization。
- 针对 corpus 中未来可能出现的显式 BPF busy loop，单独做 pattern recognition 和 lowering。

这些方向都需要处理当前“简单 hint kinsn”完全不用处理的问题：

- `preempt_disable()` / `preempt_enable()`
- `local_irq_save()` / `irqrestore`
- lock ordering 与 deadlock detection
- `-EDEADLK` / `-ETIMEDOUT` 返回语义
- verifier 对锁 region 与 helper 可用性的约束
- x86 与 arm64 不同的真实等待原语

因此，工程边界非常清楚：

- “新增一个 hint 指令”是低复杂度，但当前几乎无收益。
- “把 lock helper 变成可优化 IR”才可能有收益，但这已经是中高复杂度设计，不应伪装成一个小 kinsn 任务。

## 6. 结论与建议

### 6.1 结论

- 对当前 `compiled corpus`，`PAUSE/YIELD` 不是一个值得优先推进的 kinsn。
- 当前计划里“BPF spin lock 使用频率低”的方向性判断是对的，而且比原先估计更强：在 authoritative compiled corpus 中，普通 `bpf_spin_lock` 覆盖是 `0`。
- 现有 helper 内部已经带有体系结构相关等待 hint。x86 已有 `pause`，arm64 主路径实际上更接近 `WFE`，不是裸 `yield`。
- 因而一个 BPF-side `PAUSE/YIELD` hint 指令在当前工作负载上的增益，不足以支撑其进入 OSDI 评估主线。

### 6.2 建议

- 保持 `PAUSE/YIELD` 为低优先级，短期内不进入 benchmark pipeline 或 OSDI 主评估清单。
- 如果后续只想补一个“低成本 kinsn”，不建议优先做这一项。
- 只有在以下任一条件成立时，才建议重新打开该方向：
  - 未来 corpus 出现真实、可测的 BPF-level busy-wait loop。
  - 项目决定做 lock helper 语义下沉 / 内联，这时再把 `PAUSE/WFE/YIELD` 作为 lock lowering 的一部分统一处理。

## 7. 关键源码锚点

| 主题 | 位置 | 结论 |
|---|---|---|
| authoritative build summary | `corpus/results/expanded_corpus_build_authoritative_20260310.json` | `compiled_ok = 429` |
| 普通 BPF spin lock helper | `vendor/linux-framework/kernel/bpf/helpers.c` | `bpf_spin_lock()` 最终调用 `arch_spin_lock()` |
| 普通 queued spinlock 映射 | `vendor/linux-framework/include/asm-generic/qspinlock.h` | `arch_spin_lock` 映射到 `queued_spin_lock` |
| qspinlock slowpath | `vendor/linux-framework/kernel/locking/qspinlock.c` | 等待点使用 `atomic_cond_read_relaxed` / `smp_cond_load_acquire` / `cpu_relax` |
| generic spin wait | `vendor/linux-framework/include/asm-generic/barrier.h` | `smp_cond_load_relaxed()` 循环中调用 `cpu_relax()` |
| x86 wait hint | `vendor/linux-framework/arch/x86/include/asm/vdso/processor.h` | `cpu_relax() -> pause` |
| arm64 普通 wait | `vendor/linux-framework/arch/arm64/include/asm/barrier.h` | `smp_cond_load_*` 改为 `__cmpwait_relaxed()` |
| arm64 `__cmpwait` | `vendor/linux-framework/arch/arm64/include/asm/cmpxchg.h` | 汇编序列显式包含 `sevl; wfe; ...; wfe` |
| reserved spinlock helper | `vendor/linux-framework/kernel/bpf/rqspinlock.c` | `bpf_res_spin_lock()` 调 `res_spin_lock()` |
| reserved spinlock generic path | `vendor/linux-framework/include/asm-generic/rqspinlock.h` | fast path 失败后进 `resilient_queued_spin_lock_slowpath()` |
| arm64 reserved spinlock timewait | `vendor/linux-framework/arch/arm64/include/asm/rqspinlock.h` | event-stream 可用时走 `WFE-style`，否则 fallback 到 `cpu_relax()->yield` |
| arm64 `cpu_relax` fallback | `vendor/linux-framework/arch/arm64/include/asm/vdso/processor.h` | `cpu_relax() -> yield` |
| 唯一命中对象 | `vendor/linux-framework/tools/testing/selftests/bpf/progs/res_spin_lock.c` | AA/ABBA/timeout/held-lock-max 型自测，而非业务 hot path |

## 8. 置信度与未覆盖项

- 对“当前 compiled corpus 覆盖率很低”的结论，置信度高。这部分来自当前仓库内的直接静态扫描。
- 对“简单 kinsn 收益接近零”的结论，置信度较高。这来自覆盖率和 helper 边界分析。
- 本文没有跑 VM，也没有做 perf 测量，因此没有给出 cycle-level 定量收益上界。这里的判断是静态可行性和覆盖率判断，不是实测 speedup 报告。
