# 内核侧 root cause 复核报告（Codex）

日期：2026-03-25

## 结论摘要

先给结论：

1. `rusty_exit`（prog 20）的 malformed rewrite 本身是明确的 userspace rewrite bug：把 `map_value + const offset` 错改成了裸 `LD_IMM64` 标量，破坏了 verifier 可见的指针类型信息。这个结论来自复现报告本身，不需要内核代码才能成立。
2. 但把它归因到 `bpf_prog_rejit()` 的 verifier bypass，当前源码对不上。当前树里：
   - `prog_flags` 已正确透传；
   - struct_ops 的 `attach_btf/attach_btf_id/expected_attach_type` 也被正确预填到 `tmp->aux` 和 `tmp`；
   - `fd_array` 也被复制到内核缓冲区并按 `KERNEL_BPFPTR` 语义传给 verifier。
   所以“live 放过 malformed、replay 拒绝”这一差异，不能用 `load_attr` 构造不完整来解释。
3. 当前代码里能坐实的 REJIT bug，主要是两个：
   - `bpf_prog_rejit_swap()` 发布的新程序状态不完整，遗漏了多个 verifier/JIT 产出字段；其中 `tail_call_reachable` 和 `arena` 是最危险的两个。
   - `bpf_struct_ops_refresh_prog()` 不是“吞错误”，而是“非事务性部分更新”；失败后错误会往上传播，但 rollback 只能退化到“保留新旧 image 并容忍部分不一致”。
4. `smp_wmb() + WRITE_ONCE(prog->bpf_func)` 也是实打实的内存序 bug，但它是弱序架构问题。当前复现环境是 x86_64/TCG，它解释不了报告里的这次 live crash。
5. `bpf_kinsn_has_native_emit()` 在当前树里已经定义在 header 里。旧 review 里“未定义”的结论已经过时。
6. 结合复现报告，当前最像真正 live crash 根因的，仍然是 `bpftool prog show` 触发的 prog-info / metadata 路径竞态，而不是 `bpf_prog_rejit()` verifier 放过 malformed `rusty_exit`。这一点超出了你要求核对的 3.1-3.5 范围，但必须说明，否则会把 root cause 认错。

## 一、复现报告关键信息复述

### 1. 哪些程序 REJIT 失败，错误是什么

- `sysctl_monitor`
  - `BPF_PROG_REJIT: Invalid argument`
  - verifier: `call to invalid destination`
- `event_execve`
  - `BPF_PROG_REJIT: Invalid argument`
  - verifier: `unreachable insn 169`
- `tracee/lkm_seeker_modt`
  - verifier: `unreachable insn 252`
- `scx` struct_ops:
  - `prog 17` / `rusty_init_task`: `R2 invalid mem access 'scalar'`
  - `prog 18` / `rusty_exit_task`: `R2 invalid mem access 'scalar'`
  - `prog 19` / `rusty_init`: `R2 invalid mem access 'scalar'`
  - `prog 20` / `rusty_exit`: 报告中最初被怀疑和 crash 相关

### 2. `rusty_exit` 的 malformed rewrite 是什么

复现报告已经把形状讲得很清楚：

- rewrite 前：
  - `pc 4: r1 = map_value`
  - `pc 6: r1 += 16`
  - 后面又一次 `r1 = map_value`，再 `r1 += 144`
- rewrite 后：
  - `pc 4: r1 = map_value`
  - `pc 6: r1 = 0x...21`
  - `pc 10: r1 = map_value`
  - `pc 12: r1 = 0x...a1`

也就是把“保持 pointer provenance 的指针加常数”错误地 materialize 成了裸 `LD_IMM64` 标量。这样一来，helper 调用前的 `r1` 不再是 `map_value` 指针，而是 scalar，所以 replay/静态变体里 verifier 才会在 helper 调用点报：

- `R1 type=scalar expected=... map_value ...`

### 3. QEMU crash 的具体触发路径

按复现报告的后半段，live crash 后来被缩小到：

- `probe_bpftool_register()`
- 启动第二个 `scx_rusty --stats 1`
- 在 loader 仍处于不稳定窗口时，重复执行 `bpftool -j -p prog show`

进一步收敛到：

- 只查询 owner program 子集也能触发；
- 最小已知 live 触发器最后缩到单个 `owner_only_id=42` 查询；
- host 侧反复落在 `qemu-system-x86_64` 的 `tlb_set_dirty` / `tlb_set_page_full`。

这条路径和“把 malformed `rusty_exit` 通过 verifier 并真正发布执行”不是一回事。报告自己后面也承认，shell/silent 变体里同一份 malformed `apply 20` 可以被 verifier 干净拒绝，而且不 crash QEMU。

### 4. 为什么 live 场景“像是放过了 malformed”，而 replay 正确拒绝

对照当前源码，我的结论是：

- 不能把这个差异解释成 `bpf_prog_rejit()` verifier 上下文构造错误；
- 更合理的解释是：报告早期把两个现象混在了一起
  - 现象 A：daemon 生成了 malformed rewrite；
  - 现象 B：live 路径里 QEMU/guest 在另一个 metadata race 窗口崩了。
- 后续 shell/silent differential 已经说明：同一类 malformed `rusty_exit` 输入，本身可以被 verifier 正常拒绝。
- replay harness 则是把“错误 rewrite”直接送进 `BPF_PROG_REJIT`，绕开 probe/session/output replay 干扰，因此稳定命中 verifier 拒绝。

换句话说，当前树里看不到 “REJIT live 专属 verifier bypass” 的代码证据。

## 二、3.1 `bpf_prog_rejit()` verifier 路径复核

### 结论

当前树里，`bpf_prog_rejit()` 的 `load_attr` 构造不是这次 live/replay 差异的根因。旧 review 里关于 `check_struct_ops_btf_id()` 没走到、`prog_flags` 丢失、`fd_array` 传错的判断，和当前代码不符。

### 代码位置

- `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_rejit:3514`
- `vendor/linux-framework/kernel/bpf/verifier.c:bpf_check:26317`
- `vendor/linux-framework/kernel/bpf/verifier.c:check_attach_btf_id:25724`
- `vendor/linux-framework/kernel/bpf/verifier.c:check_struct_ops_btf_id:25180`

### `load_attr` 逐字段分析

`bpf_prog_rejit()` 在 [`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3551-3560` 设置了：

- `prog_type = prog->type`
- `expected_attach_type = prog->expected_attach_type`
- `insn_cnt = attr->rejit.insn_cnt`
- `insns = attr->rejit.insns`
- `log_level/log_size/log_buf`
- `prog_flags = prog->aux->prog_flags`
- `fd_array_cnt = attr->rejit.fd_array_cnt`

随后在 `3561-3577`：

- 把用户传入的 `fd_array` 复制到内核缓冲区 `kfd_array`
- 再把 `load_attr.fd_array` 指向这个 kernel buffer
- `load_uattr = KERNEL_BPFPTR(&load_attr)`，所以 verifier 看到的是 kernel pointer 语义

这条 `fd_array` 路径最终在 [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25856-25888` 的 `process_fd_array()` 被消费，逻辑是完整的。

### struct_ops 程序的 `attach_btf_id` / `attach_btf` 是怎么设置的

`bpf_prog_rejit()` 在 [`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3584-3596`：

- `tmp->expected_attach_type = prog->expected_attach_type`
- 如果原程序有 `attach_btf`，先 `btf_get()`，再复制到 `tmp->aux->attach_btf`
- `tmp->aux->attach_btf_id = prog->aux->attach_btf_id`

这很关键，因为 `check_attach_btf_id()` 并不是从 `attr->attach_btf_id` 取值，而是从 `prog->aux->attach_btf_id` 取值：

- [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25727-25729`

对 `BPF_PROG_TYPE_STRUCT_OPS`，`check_attach_btf_id()` 直接转到 `check_struct_ops_btf_id()`：

- [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25747-25748`

而 `check_struct_ops_btf_id()` 继续使用：

- `prog->aux->attach_btf_id`
- `prog->aux->attach_btf`
- `prog->expected_attach_type`
- `prog->gpl_compatible`

分别见：

- [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25193-25202`
- [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25212-25230`

这说明 struct_ops 验证路径在 REJIT 上是通的。

### 为什么不是 `load_attr` 漏字段导致 live 放过、replay 拒绝

原因有三层：

1. `prog_flags` 已正确从 `prog->aux->prog_flags` 透传。
   - 原始 load 路径保存：[`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3016-3018`
   - REJIT 路径重放：[`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3558`
2. struct_ops attach 校验不是靠 `attr->attach_btf_id`，而是靠 `tmp->aux->attach_btf{,_id}` 和 `tmp->expected_attach_type`；这些都被预填了。
3. `fd_array` 通过 kernel buffer 传入 `process_fd_array()`，没有 live/replay 差异点。

### 这一项的 root cause 判断

- 结论：**不是当前树上的 bug**
- 触发条件：无
- 修复方案：不应该在这里修；应该撤销旧报告里对 `load_attr` verifier bypass 的归因
- 优先级：`N/A`

## 三、3.2 struct_ops refresh 错误处理复核

### 结论

当前代码里没有“错误被吞没”。真正的问题不是 err=0 静默继续，而是：

- `bpf_struct_ops_refresh_prog()` 对多个 call site 做逐个 `text_poke`
- 一旦中途失败，前面已经 patch 成功的 site 不会在函数内原地回滚
- 外层 rollback 再次扫描 callsite 时，只能按“当前 call 目标地址”去找，因而对“部分已改、新旧混杂”的状态不具备事务性

这会导致：

- rollback 失败；
- `bpf_prog_rejit()` 只能退化到 `retain_old_image = true`；
- 结果是“保留新 image 防止悬垂 + 状态部分不一致/泄漏”，不是“吞错继续执行”。

### 代码位置

- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:bpf_struct_ops_refresh_prog:1518`
- `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_rejit:3758`
- `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_rejit_rollback:3472`

### 错误是怎么传播的

`bpf_struct_ops_refresh_prog()` 本身直接返回负错：

- call site 找不到时：[`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`](../../../../vendor/linux-framework/kernel/bpf/bpf_struct_ops.c) `1553-1557`
- `text_poke` 失败时：[`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`](../../../../vendor/linux-framework/kernel/bpf/bpf_struct_ops.c) `1569-1575`

调用者 `bpf_prog_rejit()` 没有吞掉这个错误：

- 收到失败后 `ret = err`：[`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3760-3765`
- 然后尝试 rollback：`3765-3768`
- rollback 也失败时才设 `retain_old_image = true`：`3769-3773`
- 最终返回的仍然是失败码 `ret`：函数尾 `3801-3803`

### 真正的 bug root cause

root cause 不是 error swallowing，而是 `bpf_struct_ops_refresh_prog()` 的两阶段实现没有事务性：

- 第一阶段先全量 `find_call_site(old_bpf_func)`；
- 第二阶段再逐个 `bpf_arch_text_poke(... old_bpf_func -> prog->bpf_func)`。

如果第二阶段在第 N 个 site 失败：

- `0..N-1` 已经改成新地址；
- `N..end` 仍是旧地址；
- rollback 再用 `find_call_site(new_bpf_func)` 去找时，会只在“已经改成新地址”的 site 上找到匹配；
- 一旦先撞到一个仍是旧地址的 site，就可能 `-ENOENT` 退出。

### 触发条件

- `struct_ops` 程序 REJIT 成功过了 verifier/JIT/swap；
- `bpf_struct_ops_refresh_prog()` 在多 site 更新中途失败；
- rollback 再次刷新时面对部分新、部分旧的 trampoline 镜像。

### 修复方案

- 不要运行时线性扫描 trampoline 去找 callsite；
- 在构建 struct_ops trampoline 时，把每个 callback 的 callsite 偏移保存在 `st_map` 里，REJIT 直接按偏移 patch；
- refresh 失败时要么在函数内部做局部回滚，要么把“已 patch 的 site 列表”显式返回给 caller，保证 rollback 有确定的回滚集合。

### 优先级

- `P1`
- 它是实 bug，但不是“吞错误/UAF”那个版本。

## 四、3.3 `bpf_prog_rejit_swap()` 完整性复核

### 结论

这是当前树里最明确的 REJIT 代码缺陷。

`bpf_prog_rejit_swap()` 只手工 swap/copy 了一部分 verifier/JIT 产出字段，没有形成完整的“compile output”发布。结果是：

- `prog->bpf_func` 已经切到新 image；
- 但 `prog` / `prog->aux` 上仍可能残留旧 metadata。

### 代码位置

- `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_rejit_swap:3372`
- `vendor/linux-framework/include/linux/bpf.h:1707`
- `vendor/linux-framework/include/linux/bpf.h:1830`

### 已经被 swap/copy 的字段

`bpf_prog_rejit_swap()` 现在处理了这些字段：

- `aux`
  - `orig_insns`, `orig_prog_len`
  - `used_btfs`, `used_btf_cnt`
  - `btf`
  - `func_info`, `func_info_aux`, `func_info_cnt`
  - `linfo`, `jited_linfo`, `nr_linfo`, `linfo_idx`
  - `num_exentries`, `extable`
  - `priv_stack_ptr`
  - `jit_data`
  - `used_maps`, `used_map_cnt`
  - `kfunc_tab`, `kfunc_btf_tab`
  - `security`
  - `func`, `func_cnt`, `real_func_cnt`
  - `bpf_exception_cb`, `exception_boundary`
  - `max_ctx_offset`, `max_pkt_offset`, `max_tp_access`
  - `stack_depth`
  - `max_rdonly_access`, `max_rdwr_access`
  - `verifier_zext`
  - `changes_pkt_data`
  - `kprobe_write_ctx`
  - `verified_insns`
  - `load_time`
- `prog`
  - `digest`
  - `jited`, `jited_len`
  - `gpl_compatible`
  - `cb_access`
  - `dst_needed`
  - `blinding_requested`
  - `blinded`
  - `kprobe_override`
  - `enforce_expected_attach_type`
  - `call_get_stack`
  - `call_get_func_ip`
  - `call_session_cookie`
  - `tstamp_type_access`
  - `len`
  - `insnsi`
  - `bpf_func`

位置在：

- [`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3379-3460`

### 明确遗漏的字段

当前定义里，下列字段没有进入 swap/copy：

- `prog->jit_requested`
- `prog->aux->tail_call_reachable`
- `prog->aux->ctx_arg_info`
- `prog->aux->ctx_arg_info_size`
- `prog->aux->exception_cb`
- `prog->aux->might_sleep`
- `prog->aux->arena`
- `prog->aux->attach_func_proto`
- `prog->aux->attach_func_name`
- `prog->aux->mod`
- `prog->aux->saved_dst_prog_type`
- `prog->aux->saved_dst_attach_type`

其中真正危险的不是“有没有漏字段”这个抽象问题，而是以下几个字段在当前代码树里确实会被 verifier/JIT 改写、且后续会被使用：

#### 1. `tail_call_reachable`

- 由 verifier 写入：[`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `7187-7188`
- subprog 也会写：`23262`
- `bpf_prog_rejit_swap()` 没有复制

影响：

- 程序 REJIT 后，主程序的 tail-call reachability 可能已经变化，但 `prog->aux->tail_call_reachable` 还停留在旧值。
- 这会影响后续和该程序相关的 verifier/JIT/attach 行为，例如 `check_attach_btf_id()` 里给 trampoline 打 `BPF_TRAMP_F_TAIL_CALL_CTX`：
  - [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25808-25809`

#### 2. `arena`

- verifier 在 arena map 参与时设置：[`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `22021-22030`
- subprog 也会继承：`23241`
- `bpf_prog_rejit_swap()` 没有复制

影响：

- 新 bytecode 若换了 arena map，运行时 `prog->aux->arena` 仍指向旧 arena；
- `arena_fault_log()` 之类运行时路径会读这个指针：
  - [`vendor/linux-framework/kernel/bpf/arena.c`](../../../../vendor/linux-framework/kernel/bpf/arena.c) `949-953`

#### 3. `ctx_arg_info` / `ctx_arg_info_size`

- struct_ops verifier 在 `check_struct_ops_btf_id()` 里重新初始化：
  - [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `25282-25287`
- swap 未更新

对 struct_ops REJIT 来说，因为 attach member 没变，这组数据大概率和旧值一致，所以它更像“完整性缺口”，不是当前复现的直接触发点。

### 你点名问的三个字段

- `tail_call_reachable`
  - **没有 swap，也没有 copy**
- `jit_requested`
  - **没有 swap，也没有 copy**
  - 旧值保留在 `prog`
- `blinding_requested`
  - **有 copy，但不是对称 swap**
  - 见 [`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3425`

### root cause

root cause 是设计层面问题：`bpf_prog_rejit_swap()` 试图手工维护“哪些字段算 compile output”，但 `struct bpf_prog` / `struct bpf_prog_aux` 的 verifier/JIT 产出字段本来就分散在多个结构体成员里，手工列表必然漏。

### 触发条件

- REJIT 后新程序和旧程序在上述 metadata 上有变化；
- 运行时或后续 attach/info 路径读取了旧 metadata。

### 修复方案

- 把“verifier/JIT 产出状态”收敛成单独的 compile-output 子结构；
- `bpf_prog_rejit_swap()` 只 swap 这个子结构，而不是到处手写字段列表；
- 短期至少先补上：
  - `tail_call_reachable`
  - `arena`
  - `ctx_arg_info`
  - `ctx_arg_info_size`

### 优先级

- `P0`
- 这是当前树里最明确、最实质的 REJIT 内核 bug。

## 五、3.4 `bpf_kinsn_has_native_emit()` 搜索结果

### 结论

当前树里它已经定义了，不是未定义符号。

### 搜索结果

`grep -rn "bpf_kinsn_has_native_emit" vendor/linux-framework/` 的源码命中包括：

- `vendor/linux-framework/kernel/bpf/verifier.c:23776`
- `vendor/linux-framework/include/linux/bpf.h:981`

定义在：

- [`vendor/linux-framework/include/linux/bpf.h`](../../../../vendor/linux-framework/include/linux/bpf.h) `981-994`

引用在：

- [`vendor/linux-framework/kernel/bpf/verifier.c`](../../../../vendor/linux-framework/kernel/bpf/verifier.c) `23776`

### root cause 判断

- 结论：**不是当前树上的 bug**
- 更准确地说，这是旧报告已经过时。

### 优先级

- `N/A`

## 六、3.5 `smp_wmb()` vs 读端

### 结论

这是一个真实的内存序问题，但属于弱序架构 correctness bug，不是当前 x86_64/TCG crash 的最佳解释。

### 代码位置

- 写端：
  - [`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `3455-3457`
- 读端：
  - [`vendor/linux-framework/include/linux/filter.h`](../../../../vendor/linux-framework/include/linux/filter.h) `712`
  - [`vendor/linux-framework/include/linux/filter.h`](../../../../vendor/linux-framework/include/linux/filter.h) `723`

### 问题是什么

写端现在是：

- 先写 metadata
- `smp_wmb()`
- `WRITE_ONCE(prog->bpf_func, tmp->bpf_func)`

读端 `__bpf_prog_run()` 是普通读：

- `dfunc(ctx, prog->insnsi, prog->bpf_func);`

没有：

- `smp_load_acquire(&prog->bpf_func)`
- 也没有 `rcu_dereference()` 这类 acquire 语义封装

因此在 ARM64 这类弱序架构上，理论上可能出现：

- CPU1 先看见新的 `prog->bpf_func`
- 但还没和其它 metadata 写建立 acquire/release 配对
- 进而搭配到旧的 `prog->len` / `prog->aux` 派生状态

### root cause

root cause 是发布协议不完整：只有 release 侧语义的前半边（实际上这里还只是 `wmb`），没有读端 acquire。

### 触发条件

- SMP
- 弱序架构
- 一个 CPU 在 REJIT swap，另一个 CPU 同时执行该 prog

### 修复方案

- 最直接：
  - 写端改成 `smp_store_release(&prog->bpf_func, tmp->bpf_func)`
  - 读端改成 `smp_load_acquire()` 或 `rcu_dereference()` 风格
- 更稳妥：
  - 把 “新 image + 新 metadata” 的发布统一成一个明确的 RCU publish protocol

### 优先级

- `P1`
- 在 x86 上很难解释这次复现，但它本身是该修的。

## 七、优先级排序

### P0

1. `bpf_prog_rejit_swap()` 发布状态不完整
   - 位置：`vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_rejit_swap:3372`
   - 实锤：是
   - 关键遗漏：`tail_call_reachable`、`arena`
   - 修复：把 compile-output 打包成单独子结构整体 swap

### P1

2. `bpf_struct_ops_refresh_prog()` 非事务性部分更新
   - 位置：`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:bpf_struct_ops_refresh_prog:1518`
   - 实锤：是
   - 注意：不是“吞错误”，也不是当前代码里明确的 UAF
   - 修复：记录 callsite 偏移并做事务性 patch/rollback

3. `smp_wmb() + WRITE_ONCE()` 发布协议不完整
   - 位置：`vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_rejit_swap:3455`
   - 实锤：是
   - 但：主要是弱序架构风险

### 非 bug / 当前树不成立

4. `bpf_prog_rejit()` verifier 路径缺少 struct_ops 验证
   - 结论：不成立
   - 原因：`tmp->aux->attach_btf{,_id}` 和 `tmp->expected_attach_type` 已正确预填，`bpf_check()` 会走到 `check_struct_ops_btf_id()`

5. `bpf_kinsn_has_native_emit()` 未定义
   - 结论：不成立
   - 原因：当前定义在 `include/linux/bpf.h:981`

## 八、最终判断：哪一个才更像“这次 crash 的具体 root cause”

如果严格限定在你要求我复核的 3.1-3.5 五个方向里：

- **最明确的真实 bug** 是 `bpf_prog_rejit_swap()` 的状态发布不完整；
- **最像旧报告误判** 的是“REJIT verifier bypass”和“struct_ops refresh 吞错误”。

但如果问“复现报告里那条 live QEMU crash 最像哪一类 bug”，我的判断是：

- **不是** 当前树里的 `bpf_prog_rejit()` verifier bypass；
- **更像** `bpftool prog show` 所走的 prog-info / metadata 路径竞态；
- 复现报告里提到的 `bpf_prog_get_stats()` 空指针问题，当前源码已经有 guard：
  - [`vendor/linux-framework/kernel/bpf/syscall.c`](../../../../vendor/linux-framework/kernel/bpf/syscall.c) `2466-2470`
- 所以当前树上至少还有另一个 metadata/lifetime bug 尚未被这次 3.1-3.5 复核覆盖到。

也就是说：

- 这次 3.1-3.5 复核能帮你排除几条错误归因；
- 也能找出一个明确的 REJIT 核心 bug（swap 不完整）；
- 但“导致 live crash 的最终 bug”更可能仍在 `bpf_prog_get_info_by_fd()` 相关路径，而不是这里被怀疑的 verifier bypass。
