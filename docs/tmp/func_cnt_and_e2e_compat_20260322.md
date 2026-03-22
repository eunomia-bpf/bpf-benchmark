# func_cnt 限制 + E2E workload REJIT 兼容性

日期：2026-03-22

## TL;DR

- 当前 `BPF_PROG_REJIT` 在 `vendor/linux-framework/kernel/bpf/syscall.c:3169-3170` 直接拒绝 `aux->func_cnt || aux->real_func_cnt`，也就是任何带 BPF-to-BPF subprog 的程序。
- 这主要是实现上的技术限制，不是独立的安全策略。verifier/JIT 本身已经会处理多 subprog；真正不完整的是 REJIT 的 swap/publish 路径。
- 现在如果直接放开 `func_cnt` 检查，会出错，因为 `bpf_prog_rejit_swap()` 没有交换 `aux->func`、`func_cnt`、`real_func_cnt`、`bpf_exception_cb`，也没有重新发布 subprog kallsyms。
- E2E workload 里，当前最明显被这个限制挡住的是 Katran 的 `balancer_ingress`。Tracee 的 live set 里也有一个 `sys_dup_exit_tail` 带 `.text` pseudo-call；Tetragon 当前 E2E live programs 和 checked-in bpftrace 脚本则基本都是单函数程序。
- 最小可行方案更接近“方案 A”，但条件不能只看 `insn_cnt` 和 `func_cnt`。最少也要要求 subprog entry 布局一致，并把整套 multi-subprog JIT state 一起 swap。

## 0. 调研方法

- 内核路径分析基于：
  - `vendor/linux-framework/kernel/bpf/syscall.c`
  - `vendor/linux-framework/kernel/bpf/verifier.c`
  - `vendor/linux-framework/kernel/bpf/core.c`
  - `vendor/linux-framework/include/linux/{bpf.h,filter.h}`
  - `vendor/linux-framework/include/uapi/linux/bpf.h`
- workload 兼容性分析基于两层信息：
  - E2E harness / authoritative JSON 里实际加载的 live program 集合
  - 对对应 `.bpf.o` 做 `llvm-readelf` / `llvm-objdump -dr` 静态扫描
- 我把 section 里出现 `call -1` 或 `R_BPF_64_32 .text` 视为 BPF-to-BPF pseudo-call 证据，也就是 `func_cnt > 0` 的强信号。
- 这份文档没有去 live dump 当前内核里的 `prog->aux->func_cnt`；workload 部分是静态结构判断，不是运行时 `bpftool prog show` 的直接字段读数。

## 1. `func_cnt` 检查在哪里

### 1.1 直接 reject 点

`bpf_prog_rejit()` 自己不单独检查 `func_cnt`，而是通过 `bpf_prog_rejit_supported()` 统一拒绝：

```c
static bool bpf_prog_rejit_supported(const struct bpf_prog *prog)
{
	const struct bpf_prog_aux *aux = prog->aux;

	if (!prog->jited || prog->is_func)
		return false;

	if (bpf_prog_is_offloaded(aux) || bpf_prog_is_dev_bound(aux))
		return false;

	if (aux->dst_prog || aux->dst_trampoline || aux->func_cnt ||
	    aux->real_func_cnt || aux->poke_tab || aux->size_poke_tab ||
	    rcu_access_pointer(aux->st_ops_assoc))
		return false;

	return true;
}
```

位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:3159`
- `vendor/linux-framework/kernel/bpf/syscall.c:3169-3170`
- 调用点在 `vendor/linux-framework/kernel/bpf/syscall.c:3280` 和 `vendor/linux-framework/kernel/bpf/syscall.c:3384`

### 1.2 `func_cnt` / `real_func_cnt` 的含义

- `vendor/linux-framework/include/linux/bpf.h:1704`
  - `func_cnt`: non-func prog 持有的 func prog 数量
- `vendor/linux-framework/include/linux/bpf.h:1705`
  - `real_func_cnt`: 包含 hidden subprog，仅用于 JIT / free

对单函数程序：

- `func_cnt == 0`
- `real_func_cnt == 0`

对多 subprog 程序：

- `jit_subprogs()` 会把 `prog->aux->func = func`
- 同时把 `prog->aux->func_cnt = env->subprog_cnt - env->hidden_subprog_cnt`
- 把 `prog->aux->real_func_cnt = env->subprog_cnt`

对应位置：

- `vendor/linux-framework/kernel/bpf/verifier.c:23137-23142`

注意：这里的 `func_cnt` 不是“额外 subprog 个数”，而是 multi-function program 的总 function 数。

## 2. 为什么当前必须拒绝

### 2.1 不是 verifier/JIT 不支持，而是 REJIT swap 路径没接完整

多 subprog 在正常 load 路径里是支持的：

- `add_subprog_and_kfunc()` 发现 subprog 边界：`vendor/linux-framework/kernel/bpf/verifier.c:3731-3790`
- `check_subprogs()` 校验 jump 不跨 subprog、末尾不 fall-through：`vendor/linux-framework/kernel/bpf/verifier.c:3794-3846`
- `fixup_call_args()` 在 JIT 模式下调用 `jit_subprogs(env)`：`vendor/linux-framework/kernel/bpf/verifier.c:23188-23193`
- `jit_subprogs()` 会：
  - 拆分 `func[i]`
  - 逐个 JIT
  - 第二遍把 pseudo call 改成真实 callee 地址
  - 填 `aux->func` / `func_cnt` / `real_func_cnt`
  - 发布 subprog kallsyms

关键位置：

- `vendor/linux-framework/kernel/bpf/verifier.c:22900-23142`

所以“为什么拒绝”不是因为 verifier 不会识别多函数，也不是因为 arch JIT 完全不会编，而是 REJIT 的“把新 JIT 镜像换进 live prog”这一步只按单函数程序写了。

### 2.2 现在的 swap 明显缺字段

`bpf_prog_rejit_swap()` 当前会交换很多 metadata，但没有交换：

- `prog->aux->func`
- `prog->aux->func_cnt`
- `prog->aux->real_func_cnt`
- `prog->aux->bpf_exception_cb`

位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:3184-3252`

但这些字段对 multi-subprog 是 runtime-critical：

- JIT call fixup / far call lookup 依赖 `aux->func`
  - `vendor/linux-framework/kernel/bpf/core.c:1268-1270`
- free path 依赖 `aux->real_func_cnt` 和 `aux->func`
  - `vendor/linux-framework/kernel/bpf/core.c:2933-2942`
- kallsyms 删除也会遍历全部 subprog
  - `vendor/linux-framework/kernel/bpf/core.c:534-540`
- `BPF_OBJ_GET_INFO_BY_FD` 输出 jited ksyms / func_lens / prog_tags 也会走 `aux->func`
  - `vendor/linux-framework/kernel/bpf/syscall.c:5409-5572`

### 2.3 直接放开会发生什么

如果只删掉 `func_cnt` reject：

- `tmp` 会带着新的 `aux->func[]` 和新的 subprog JIT image
- `prog` 还是旧的 `aux->func[]`
- swap 后 live prog 的 `prog->bpf_func` 变成新主函数，但 `prog->aux->func` 仍然可能指向旧 subprog 数组
- 之后 `__bpf_prog_put_noref(tmp, tmp->aux->real_func_cnt)` 会 free `tmp` 持有的 subprog JIT image
- 如果 `tmp` 还握着新的 `aux->func[]`，就等于把刚编出来的新 subprog 释放了

相关 free 点：

- `vendor/linux-framework/kernel/bpf/syscall.c:3415`
- `vendor/linux-framework/kernel/bpf/syscall.c:3421`
- `vendor/linux-framework/kernel/bpf/syscall.c:2376-2394`

这已经不只是“调试信息不准”，而是 live program 的 JIT state 会不一致。

### 2.4 这更像“正确性 + 内存安全边界”，不是策略性拒绝

结论：

- 首因是技术实现不完整
- 但这个技术问题一旦放开就是 correctness / UAF 风险，不是 harmless 的 metadata 偏差
- 所以当前 reject 是合理的保护性 gate

## 3. 多 subprog 程序要处理什么

### 3.1 subprog boundary / `func_info` 怎么更新

`func_info` 的约束在 verifier 里是很严格的：

- `check_btf_func()` 要求：
  - `func_info_cnt == env->subprog_cnt`
  - `func_info[i].insn_off == env->subprog_info[i].start`
- 否则直接报：
  - `"number of funcs in func_info doesn't match number of subprogs"`
  - `"func_info BTF section doesn't match subprog layout in BPF program"`

位置：

- `vendor/linux-framework/kernel/bpf/verifier.c:19309-19340`

另外，正常 load 路径在代码重写后还会把 `func_info[i].insn_off` 修正为最新 start：

- `vendor/linux-framework/kernel/bpf/verifier.c:19376-19381`

问题在于：当前 REJIT ABI 本身不重新携带 `prog_btf_fd/func_info/line_info`。

证据：

- `BPF_PROG_REJIT_LOAD_ATTR_SIZE` 截到 `keyring_id`，理论上能容纳这些字段：
  - `vendor/linux-framework/kernel/bpf/syscall.c:3156`
  - `vendor/linux-framework/include/uapi/linux/bpf.h:1588-1650`
- 但 `bpf_prog_rejit()` 实际只填了：
  - `prog_type`
  - `expected_attach_type`
  - `insn_cnt`
  - `insns`
  - `log_*`
  - `prog_flags`
  - `fd_array_cnt`
  - `fd_array`
- 没有填 `prog_btf_fd` / `func_info*` / `line_info*`
  - `vendor/linux-framework/kernel/bpf/syscall.c:3285-3324`

所以：

- 如果要支持“任意新 subprog 布局”，当前 REJIT syscall ABI 不够
- 如果只做最小方案，最容易的是要求 subprog 布局不变，然后沿用旧 `func_info`

### 3.2 subprog 之间的 call 怎么 fixup

这部分 verifier/JIT 已经会做，不需要 REJIT 重新发明：

- `add_subprog_and_kfunc()` 扫描 pseudo call / pseudo func，把 target insn 收进 `env->subprog_info`
  - `vendor/linux-framework/kernel/bpf/verifier.c:3731-3774`
- `jit_subprogs()` 第一阶段把 call 的 target subprog id 暂存在 `insn->off`
  - `vendor/linux-framework/kernel/bpf/verifier.c:22905-22931`
- 拆分 `func[i]` 后，第二阶段把：
  - pseudo func 改成 callee `bpf_func` 地址
  - pseudo call 改成 `BPF_CALL_IMM(func[subprog]->bpf_func)`
  - `func[i]->aux->func = func`
  - `func[i]->aux->func_cnt` / `real_func_cnt` 也一并填好
  - 对全部 `func[i]` 再跑最后一遍 JIT

关键位置：

- `vendor/linux-framework/kernel/bpf/verifier.c:23032-23095`

所以“call fixup”本身不是 blocker；blocker 是这些 fixup 产出的 `func[]` / subprog image 没被 REJIT swap 正确接管。

### 3.3 JIT 多 subprog 程序需要什么

至少要满足：

- arch JIT 已经支持 bpf-to-bpf calls
  - 否则 `jit_subprogs()` 会报 `"JIT doesn't support bpf-to-bpf calls"`
  - `vendor/linux-framework/kernel/bpf/verifier.c:23083-23090`
- REJIT swap 要同时发布：
  - 新主函数 `prog->bpf_func`
  - 新 `aux->func[]`
  - 新 `func_cnt` / `real_func_cnt`
  - 新 `bpf_exception_cb`
- REJIT swap 要重新处理 subprog kallsyms
  - 现在只 `bpf_prog_kallsyms_del(prog)` / `bpf_prog_kallsyms_add(prog)`
  - 对 multi-subprog 不够
  - `vendor/linux-framework/kernel/bpf/syscall.c:3212`
  - `vendor/linux-framework/kernel/bpf/syscall.c:3251`

### 3.4 “只要 `insn_cnt` 和 `func_cnt` 都匹配就允许”够不够

不够。

原因有四个：

- 同样的 `func_cnt` 不保证 subprog entry offset 一样
- 同样的 `func_cnt` 不保证 subprog 顺序一样
- `bpf_exception_cb` / hidden subprog 也受 `real_func_cnt` 和 index 影响
- 即使计数都一样，当前 swap 仍然没有搬 `aux->func[]`

更强一点的条件至少要是：

- `real_func_cnt` 相同
- 每个 subprog 的 entry offset 相同
- exception callback subprog index 相同

也就是“layout match”，而不是“count match”。

## 4. E2E workload 兼容性

### 4.1 Tracee

当前 E2E case 线索：

- case 配置在 `e2e/cases/tracee/config.yaml`
- real daemon path 使用 `corpus/build/tracee/tracee.bpf.o`
  - `e2e/README.md`
  - `e2e/cases/tracee/case.py`
- authoritative JSON 里这套 workload 实际观测到 13 个 live programs
  - `e2e/results/tracee_authoritative_20260313_postfix.json`

主要程序类型：

- 以 `raw_tracepoint` 为主
- authoritative run 里还能看到少量 `kprobe`
- 当前 E2E 配置没有走 fentry/fexit；仓库对象里虽然有更多 probe 类型，但不是这条 benchmark path 的主集合

我对 13 个 live program 对应 section 做了 pseudo-call 静态检查，结论是：

| live program | section | pseudo-call 到 `.text` | 结论 |
| --- | --- | --- | --- |
| `tracepoint__raw_syscalls__sys_enter` | `raw_tracepoint/sys_enter` | 否 | 单函数 |
| `sys_enter_init` | `raw_tracepoint/sys_enter_init` | 否 | 单函数 |
| `sys_enter_submit` | `raw_tracepoint/sys_enter_submit` | 否 | 单函数 |
| `tracepoint__raw_syscalls__sys_exit` | `raw_tracepoint/sys_exit` | 否 | 单函数 |
| `sys_exit_init` | `raw_tracepoint/sys_exit_init` | 否 | 单函数 |
| `sys_exit_submit` | `raw_tracepoint/sys_exit_submit` | 否 | 单函数 |
| `syscall__execve_enter` | `raw_tracepoint/sys_execve` | 否 | 单函数 |
| `syscall__execve_exit` | `raw_tracepoint/sys_execve` | 否 | 单函数 |
| `syscall__execveat_enter` | `raw_tracepoint/sys_execveat` | 否 | 单函数 |
| `syscall__execveat_exit` | `raw_tracepoint/sys_execveat` | 否 | 单函数 |
| `sys_dup_exit_tail` | `kprobe/sys_dup` | 是 | 多 subprog |
| `tracepoint__sched__sched_process_fork` | `raw_tracepoint/sched_process_fork` | 否 | 单函数 |
| `lkm_seeker_modtree_loop` | `uprobe/lkm_seeker_modtree_loop_tail` | 否 | 单函数 |

补充证据：

- `tracee.bpf.o` 确实有 4 个 `.text` helper：`ipv6_addr_any` / `murmur32` / `hash_u32_and_u64` / `hash_task_id`
- 但当前 live set 里，只有 `kprobe/sys_dup` 能看到 `R_BPF_64_32 .text`
- `lkm_seeker_modtree_loop` 这一项在 authoritative JSON 里记录成 `type=kprobe`，但对象静态符号映射落到 `uprobe/...` section；这不影响这里关于“是否调用 `.text` subprog”的判断

结论：

- 当前 Tracee E2E live programs 预计大约 `12/13` 能通过当前 REJIT
- 会被 `func_cnt` 挡住的主要是 `sys_dup_exit_tail`
- 如果解除 multi-subprog 限制并把 swap 路径补齐，Tracee 这组 live programs 理论上可以到 `13/13`

### 4.2 Tetragon

当前 E2E case 线索：

- harness 明确说当前 case 主要使用：
  - `corpus/build/tetragon/bpf_execve_event.bpf.o`
  - `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`
  - `e2e/README.md`
- current policy path 加载的是 exec/fork 相关 kprobe/tracepoint/socket_filter
  - `e2e/cases/tetragon/case.py:456-483`
  - `e2e/results/tetragon_authoritative_20260318.json`

当前 E2E authoritative live programs 共 7 个：

- `event_exit_acct_process` (`kprobe`)
- `event_wake_up_new_task` (`kprobe`)
- `execve_send` (`tracepoint`)
- `execve_rate` (`tracepoint`)
- `event_execve` (`tracepoint`)
- `tg_kp_bprm_committing_creds` (`kprobe`)
- `execve_map_update` (`socket_filter`)

静态 pseudo-call 检查结果：

- 上面 7 个 live program 对应 section 都没有 `.text` pseudo-call
- 也就是当前这条 E2E workload 里，加载到内核的程序看起来都是单函数程序

需要特别区分两件事：

- `bpf_generic_kprobe.bpf.o` 这个 object 从 ELF 角度看有很多 FUNC 符号
- 但其中 `kprobe` section 里的多个符号更像“多个 loadable entry function”，不是 `generic_kprobe_event` 的 subprog
- 对实际 E2E attach 的 `generic_kprobe_event` section 反汇编没有看到 `.text` pseudo-call

所以：

- 不要把“object 里函数多”直接等同于“已加载 prog 的 `func_cnt > 0`”

结论：

- 当前 Tetragon E2E live programs 预计 `7/7` 都能通过当前 REJIT
- 当前 benchmark path 的主要程序类型是 `kprobe + tracepoint + socket_filter`
- repo 里确实还有 `lsm` / `rawtp` / `uprobe` / `fmod_ret` 等对象，但不是这条 E2E case 当前实际加载的集合

### 4.3 Katran

当前 E2E case 很明确：

- object 是 `corpus/build/katran/balancer.bpf.o`
- selected program 是 `balancer_ingress`
- 类型是 `xdp`
  - `e2e/cases/katran/case.py`
  - `e2e/results/katran_authoritative_20260320.json`

这个 XDP 程序的函数结构：

- `.text` 里有 2 个本地函数：
  - `jhash`
  - `jhash_2words`
- `xdp` section 里主入口：
  - `balancer_ingress`
- `xdp` section 反汇编里能看到两处 `call -1` / `R_BPF_64_32 .text`

所以：

- 如果按“额外 subprog 个数”算：有 2 个 subprog
- 如果按 kernel 里 `func_cnt` 的语义算：这是 3-function program，因此 `func_cnt > 0`

结论：

- 当前 Katran E2E 的 `balancer_ingress` 会被 `func_cnt` 限制直接挡住
- 当前 REJIT 兼容性约等于 `0/1`

如果解除 `func_cnt` 限制，Katran 还剩什么阻碍：

- 主要不是 XDP-specific blocker
- XDP dispatcher refresh 现有 REJIT 代码已经做了
  - `vendor/linux-framework/kernel/bpf/syscall.c:3398-3407`
- 真正剩下的是 multi-subprog REJIT 自身：
  - `aux->func[]` / counts / exception callback 的 swap
  - subprog kallsyms 重发
  - 如果要允许 layout 改变，还要处理 BTF `func_info` / `line_info`

也就是说：

- Katran 在“程序类型”层面没有额外障碍
- 它就是现在最典型的 multi-subprog REJIT 受害者

### 4.4 bpftrace

当前 checked-in scripts：

- `open_latency.bt`
- `exec_trace.bt`
- `scheduler_latency.bt`
- `vfs_read_count.bt`
- `tcp_connect.bt`

对应生成对象静态扫描结果：

- `open_latency.bpf.o`
  - `kprobe:do_sys_openat2`
  - `kretprobe:do_sys_openat2`
  - 都没有 `.text` pseudo-call
- `scheduler_latency.bpf.o`
  - `tracepoint:sched:sched_wakeup`
  - `tracepoint:sched:sched_switch`
  - 都没有 `.text` pseudo-call
- `exec_trace.bpf.o`
  - 1 个 tracepoint program
  - 没有 `.text` pseudo-call
- `vfs_read_count.bpf.o`
  - 1 个 kprobe program
  - 没有 `.text` pseudo-call
- `tcp_connect.bpf.o`
  - 1 个 kprobe program
  - 没有 `.text` pseudo-call

所以 checked-in bpftrace case 合计：

- 5 个脚本
- 7 个程序实例
- 都是单函数程序

结论：

- 预计可以认为 `7/7` 都能通过当前 REJIT
- 如果按脚本算，就是 `5/5`
- “动态生成程序通常没有 subprog”这个判断对当前 case 是成立的

## 5. 解除 `func_cnt` 限制的最小方案

### 5.1 方案 A：要求新 bytecode 的 subprog 结构和原始完全一致

建议把“完全一致”具体化为：

- `real_func_cnt` 相同
- 每个 subprog 的 entry offset 相同
- exception callback / hidden subprog 的索引相同

不是只看 `func_cnt`。

这个方案下：

- `func_info` 不需要重新发现和重建
- 最简单的做法是直接保留旧的 `func_info` / `func_info_aux` / line info
- verifier/JIT 仍然可以对新 bytecode 做完整验证和 `jit_subprogs()`
- REJIT 只需要把 runtime-critical 的 multi-subprog JIT package 正确 swap 进去

需要补的核心点：

- 放开 `func_cnt` / `real_func_cnt` gate
- 在 `bpf_prog_rejit_swap()` 里新增 swap：
  - `aux->func`
  - `aux->func_cnt`
  - `aux->real_func_cnt`
  - `aux->bpf_exception_cb`
- swap 前后改成处理“全部 kallsyms”，不是只处理主 prog
- 在 `tmp`/`prog` mismatch 时校验 subprog layout 完全相同，否则返回 `-EOPNOTSUPP`

优点：

- 不需要改 verifier
- 不需要扩 REJIT UAPI
- 代码基本可以集中在 `kernel/bpf/syscall.c`

缺点：

- 不支持改变 subprog 边界
- 如果新 bytecode 只改了 subprog 内部指令，这个方案很合适；如果想自由重排函数，就不够

### 5.2 方案 B：允许任意新 bytecode，让 `bpf_check()` 重新发现 subprog boundary

这在“call fixup / JIT 生成”层面其实没问题，因为 verifier 已经会做。

真正难点是 metadata / ABI：

- 当前 REJIT syscall 不重新携带新的 `func_info`
- `check_btf_func()` 又要求 `func_info` 和新 subprog layout 严格对齐
- 如果要支持任意新 layout，必须至少满足以下之一：
  - 扩 REJIT ABI，让 userspace 重新传 `prog_btf_fd` / `func_info` / `line_info`
  - 或者在 kernel 里给 REJIT 做额外的 pre-pass / synthesis path，先发现新 boundary，再构造匹配的新 `func_info`

这就不再是“小补丁”。

优点：

- 能力最完整
- 长期设计最干净

缺点：

- 不再是最小方案
- 很可能要碰 UAPI、userspace 和更多 verifier 流程

### 5.3 方案 C：只要求 `insn_cnt` 和 `func_cnt` 匹配

不建议。

理由：

- `func_cnt` 一样不代表 subprog entry 一样
- `insn_cnt` 一样也不代表 subprog 切分一样
- hidden subprog / exception callback 仍可能错位
- 当前 swap 的关键 runtime state 仍然没补

所以这个方案既不充分，也不明显省代码。

### 5.4 哪个最简单

我建议：

- 短期最小方案：`A`
- 长期完整方案：`B`

更具体地说，最简单的不是“count match”，而是：

- `A' = layout match + swap whole multi-subprog JIT package`

这是当前分支上最现实的最小落地点。

## 6. 大概需要改多少行

如果做 `A'`：

- 主要改 `vendor/linux-framework/kernel/bpf/syscall.c`
- 可能再补一个很小的 kallsyms helper 到 `kernel/bpf/core.c` / `include/linux/filter.h`

粗估：

- `syscall.c`：约 40-70 行
- 如果加 helper：再 10-20 行
- 总量大概 50-90 行

如果做 `B`：

- 除了上面的 swap/kallsyms 改动
- 还要处理 `func_info` / `line_info` / BTF 的新输入或重建
- 很可能超过 100 行，并且不只一个文件

## 7. 建议的落地顺序

1. 先做 `A'`
2. 校验 Katran `balancer_ingress` 能否成功 REJIT
3. 再回头决定要不要扩到 `B`

原因：

- Katran 是当前最稳定、最直接的 multi-subprog 验证样本
- 它是 plain XDP，不需要再额外处理 tracing attach 语义
- 现有 REJIT 已经有 XDP dispatcher refresh 逻辑

## 8. 最终结论

- `func_cnt` gate 在 `bpf_prog_rejit_supported()`，不是 verifier 缺功能，而是 REJIT swap 只做了单函数版本。
- 放开 gate 之前，最少要补 `aux->func[]` / counts / exception callback / subprog kallsyms 的 publish/unpublish。
- 当前 E2E 兼容性大致是：
  - Tracee：约 `12/13`
  - Tetragon：约 `7/7`
  - Katran：`0/1`
  - bpftrace：约 `7/7`
- 最小可行方案应该是“方案 A，但要求 layout match”，而不是“只要 `insn_cnt` 和 `func_cnt` 相同”。
