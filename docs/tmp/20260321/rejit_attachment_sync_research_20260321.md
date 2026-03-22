# BPF_PROG_REJIT 后 attachment backend 同步调研

日期: 2026-03-21  
源码树: `vendor/linux-framework/`

## 范围与方法

本报告基于本地源码实际检索，重点看了以下路径和 grep 模式：

- XDP: `rg -n "xdp.*bpf_func|bpf_prog_run_xdp\(|xdp_do_redirect\(" vendor/linux-framework/net/core vendor/linux-framework/drivers/net`
- TC: `rg -n "cls_bpf.*bpf_func|BPF_PROG_RUN.*cls|bpf_prog_run_data_pointers\(" vendor/linux-framework/net/sched`
- cgroup: `rg -n "cgroup.*bpf_func|__cgroup_bpf_run|bpf_prog_run_array_cg\(" vendor/linux-framework/kernel/bpf/cgroup.c vendor/linux-framework/kernel/bpf/bpf_lsm.c`
- trampoline: `rg -n "bpf_trampoline.*bpf_func|arch_prepare_bpf_trampoline|bpf_arch_text_poke|extension_prog|cur_image" vendor/linux-framework/kernel/bpf/trampoline.c`
- `bpf_func` 读写方式: `rg -n "READ_ONCE\([^\n]*bpf_func|WRITE_ONCE\([^\n]*bpf_func" vendor/linux-framework`

## TL;DR

核心结论比问题表面上更收敛：

1. 大多数 backend 并不缓存 `bpf_func`，而是缓存 `struct bpf_prog *`，运行时再走通用 helper 间接执行。因此它们在 `WRITE_ONCE(prog->bpf_func)` 后天然看到新入口，不需要 backend refresh。
2. 真正会把旧 JIT 地址烙死到执行路径里的，主要是两类：
   - XDP dispatcher/static_call 路径
   - trampoline/freplace/LSM 这类会生成 trampoline image 或 text-poke 目标地址的路径
3. `struct_ops` / `sched_ext` 当前已经被 `bpf_prog_rejit_supported()` 拒绝，不是可在线支持的第一优先级。
4. 当前 `bpf_prog_rejit_supported()` 对“活跃 tracing/LSM attachment”判定不充分。`bpf_tracing_prog_attach()` 成功后会清空 `prog->aux->dst_prog` / `dst_trampoline`，所以仅靠这些 aux 字段不能识别 live trampoline user。

一句话归纳：

- 对“只缓存 `prog *`”的 backend，方案 D 已经基本成立。
- 对“缓存 raw code address / generated image”的 backend，必须做有状态 refresh，单靠 `WRITE_ONCE + smp_wmb + synchronize_rcu` 不够。

## 0. REJIT 本身做了什么

`BPF_PROG_REJIT` 的核心发布语义在 `vendor/linux-framework/kernel/bpf/syscall.c`：

- 支持条件: `bpf_prog_rejit_supported()` 在 `kernel/bpf/syscall.c:3159-3174`
- 关键 swap: `bpf_prog_rejit_swap()` 在 `kernel/bpf/syscall.c:3177-3245`
- 发布顺序:
  - 先更新元数据
  - `smp_wmb()` 后 `WRITE_ONCE(prog->bpf_func, tmp->bpf_func)` (`kernel/bpf/syscall.c:3237-3242`)
- 旧 image 回收前等待:
  - sleepable prog: `synchronize_rcu_tasks_trace()` (`kernel/bpf/syscall.c:3355-3356`)
  - non-sleepable: `synchronize_rcu()` (`kernel/bpf/syscall.c:3357-3358`)

这保证了两件事：

- 如果执行路径每次都通过 `prog->bpf_func` 取当前入口，那么新入口的发布与旧入口的回收是有序的。
- 如果某 backend 早已把旧地址复制到别处，例如 dispatcher image、trampoline image、text poke 的 jump target，那么 REJIT 根本碰不到那份缓存。

另一个重要观察：

- 读侧没有 `READ_ONCE(prog->bpf_func)`；源码检索只看到写侧 `WRITE_ONCE`，没有读侧 `READ_ONCE`（`kernel/bpf/syscall.c:3239,3242`）。
- 通用 helper 是直接读字段，例如 `include/linux/filter.h:700-724`。

因此，当前实现更像“对现有 lockless 访问做最小发布”，而不是“把 `prog->bpf_func` 作为正式的 RCU/READ_ONCE 发布对象”。

## 1. XDP dispatcher

### 1.1 `bpf_func` 怎么缓存

XDP 有两层状态：

- netdev attach 状态只缓存 `struct bpf_prog *`
  - `dev->xdp_state[mode].prog` / `link->link.prog`，见 `net/core/dev.c:10224-10305`
- 真正的 fast path dispatcher 会把每个 prog 的 `bpf_func` 抽出来烙进 dispatcher image
  - `bpf_dispatcher_prepare()` 遍历 `d->progs[i].prog->bpf_func`，见 `kernel/bpf/dispatcher.c:94-103`
  - dispatcher 自身支持 `static_call` 替换，见 `include/linux/bpf.h:1490-1508`
  - XDP 执行实际走 `bpf_prog_run_xdp()` -> `__bpf_prog_run(..., BPF_DISPATCHER_FUNC(xdp))`，见 `include/net/xdp.h:689-703`

实际 grep `drivers/net/` 结果也支持这个判断：driver 普遍传的是 `xdp_prog` 指针给 `bpf_prog_run_xdp()`，没有直接使用 `prog->bpf_func`。代表性结果见：

- `drivers/net/virtio_net.c:1798,1825`
- `drivers/net/veth.c:657,679`
- `drivers/net/ethernet/intel/ixgbe/ixgbe_main.c:2417,2435`

所以 XDP 的 stale-address 风险不在 `net_device->xdp_state[].prog`，而在 dispatcher image / static_call target。

### 1.2 正常更新路径

- 非 link 更新: `dev_change_xdp_fd()` -> `dev_xdp_attach()` -> `dev_xdp_install()`，见 `net/core/dev.c:10385-10510`, `10726-10752`
- link 更新: `bpf_xdp_link_update()`，见 `net/core/dev.c:10599-10646`
- dispatcher 更新 helper: `bpf_prog_change_xdp()` -> `bpf_dispatcher_change_prog()`，见 `net/core/filter.c:11899-11904`

### 1.3 REJIT 后需要做什么

需要 refresh dispatcher image / static_call。

原因：

- dispatcher image 内部已嵌入旧的 `prog->bpf_func` 地址，见 `kernel/bpf/dispatcher.c:99-103`
- `bpf_dispatcher_change_prog()` 在 `from == to` 时直接 return，见 `kernel/bpf/dispatcher.c:137-145`
- `bpf_xdp_link_update()` 也把“新旧 prog 相同”当 no-op，见 `net/core/dev.c:10626-10629`

因此，REJIT 后不能靠现有 “update same prog” 路径刷新 XDP backend；需要新增一个“same-prog refresh”入口。

### 1.4 开销

- rebuild dispatcher image
- 可能触发 `static_call` 更新
- 一次 `synchronize_rcu()`，见 `kernel/bpf/dispatcher.c:126-134`
- 不需要 netdev down/up
- 不需要重绑 driver，只需要重编程 dispatcher

### 1.5 可复用 API

可部分复用：

- `bpf_dispatcher_change_prog()`
- `bpf_prog_change_xdp()`

但要么新增 `bpf_dispatcher_refresh_prog()`，要么允许 `from == to` 时强制 rebuild。现状 API 不够。

### 1.6 结论

XDP 是必须做 backend refresh 的一类，但需要刷新的不是 `net_device` 上的 `prog *`，而是 dispatcher/static_call 这条快路径。

## 2. TC / cls_bpf / act_bpf

### 2.1 `bpf_func` 怎么缓存

软件路径只缓存 `struct bpf_prog *`：

- `cls_bpf` 的 `struct cls_bpf_prog { struct bpf_prog *filter; }`，见 `net/sched/cls_bpf.c:38-52`
- 分类执行时调用 `bpf_prog_run_data_pointers(prog->filter, skb)`，见 `net/sched/cls_bpf.c:81-130`
- `act_bpf` 也是 `struct bpf_prog *filter`，运行时 `rcu_dereference(prog->filter)` 后调用通用 helper，见 `net/sched/act_bpf.c:35-90`

grep 没有看到 qdisc 层直接缓存 `bpf_func`，只看到 `bpf_prog_run_data_pointers()` 调用。

### 2.2 正常更新路径

- `cls_bpf_change()` 用 `list_replace_rcu()` 替换 filter 节点，见 `net/sched/cls_bpf.c:407-523`
- `act_bpf` 通过 `tcf_bpf_init()` 更新 `prog->filter`，用 `rcu_assign_pointer()` 发布，并在替换时 `synchronize_rcu()`，见 `net/sched/act_bpf.c:277-373`

### 2.3 REJIT 后需要做什么

软件路径不需要做任何额外通知。

理由：

- qdisc 只缓存 `prog *`
- 真正执行点仍走 `bpf_prog_run_*()`，最终读取当前 `prog->bpf_func`

唯一例外是 HW offload，但 REJIT 已经拒绝 offloaded/dev-bound prog：

- `bpf_prog_rejit_supported()` 拒绝 `bpf_prog_is_offloaded(aux)` / `bpf_prog_is_dev_bound(aux)`，见 `kernel/bpf/syscall.c:3166-3167`

### 2.4 开销

无额外开销。REJIT 自带的 RCU 等待已足够。

### 2.5 可复用 API

不需要额外 API。现有 `cls_bpf_change()` / `tcf_bpf_init()` 是普通替换路径，不是 REJIT 必需路径。

### 2.6 结论

TC 软件路径属于“天然安全”的 backend。

## 3. cgroup BPF

### 3.1 `bpf_func` 怎么缓存

标准 cgroup BPF 缓存的是 `bpf_prog_array` 中的 `item->prog`：

- `struct bpf_prog_array_item { struct bpf_prog *prog; ... }`，见 `include/linux/bpf.h:2378-2389`
- 运行路径 `bpf_prog_run_array_cg()` 在 RCU 下 `READ_ONCE(item->prog)`，再调用 `run_prog(prog, ctx)`，见 `kernel/bpf/cgroup.c:62-93`

这里缓存的是 prog 指针，不是 raw `bpf_func`。

#### 特例: `BPF_LSM_CGROUP`

这个路径容易误判。它确实借用了 trampoline，但 trampoline 挂的是 shim prog，不是用户 prog 本身：

- `bpf_lsm_find_cgroup_shim()` 选的是 `__cgroup_bpf_run_lsm_*` 这几个 shim 入口，见 `kernel/bpf/bpf_lsm.c:91-113`
- `cgroup_shim_alloc()` 造了一个新的 shim prog，并设置 `p->bpf_func = bpf_func`，见 `kernel/bpf/trampoline.c:923-956`
- shim 最终回到 `bpf_prog_run_array_cg()` 去执行 cgroup array 中的真实 user prog，见 `kernel/bpf/cgroup.c:95-155`

所以 `BPF_LSM_CGROUP` 的 trampoline 并不缓存用户 prog 的 `bpf_func`；它只缓存 stable shim 函数。

### 3.2 正常更新路径

- attach: `__cgroup_bpf_attach()` / `cgroup_bpf_attach()`，见 `kernel/bpf/cgroup.c:785-919`
- effective array 重算并发布: `compute_effective_progs()` + `activate_effective_progs()`，见 `kernel/bpf/cgroup.c:432-500`
- link update: `cgroup_bpf_replace()` -> `__cgroup_bpf_replace()` -> `replace_effective_prog()`，见 `kernel/bpf/cgroup.c:921-1033`
- `bpf_link_ops.update_prog = cgroup_bpf_replace`，见 `kernel/bpf/cgroup.c:1461-1468`

### 3.3 REJIT 后需要做什么

普通 cgroup backend 不需要 refresh。

原因：

- effective array 里是 `prog *`
- 执行时现取当前 prog
- `BPF_LSM_CGROUP` 也只是 trampoline 到 shim，再间接到 prog array

### 3.4 开销

无额外 backend 开销。

### 3.5 可复用 API

不需要额外 API。`replace_effective_prog()`（`kernel/bpf/cgroup.c:924-964`）是一个很好的“in-place prog 指针替换”示例，但 REJIT 不需要它。

### 3.6 结论

cgroup BPF 属于“缓存 `prog *`，无需 refresh”的安全类，连 `BPF_LSM_CGROUP` 这个交叉路径也成立。

## 4. LSM / KRSI hooks

### 4.1 `bpf_func` 怎么缓存

LSM / KRSI 走的是 trampoline backend：

- trampoline 保存 attached prog 列表 `tr->progs_hlist[]` 和当前执行 image `tr->cur_image`，见 `include/linux/bpf.h:1352-1380`
- `bpf_trampoline_update()` 重新生成 trampoline image，并替换 `tr->cur_image`，见 `kernel/bpf/trampoline.c:620-718`

这意味着真正被 CPU 执行的是 trampoline image，不是每次现场去读 `prog->bpf_func`。

### 4.2 正常更新路径

- LSM attach 走 `bpf_tracing_prog_attach()`，其中校验 `BPF_PROG_TYPE_LSM` 且 `expected_attach_type == BPF_LSM_MAC`，见 `kernel/bpf/syscall.c:3802-3836`
- tracing link ops 没有 `.update_prog`，见 `kernel/bpf/syscall.c:3795-3800`
- attach 成功时调用 `bpf_trampoline_link_prog()`，见 `kernel/bpf/syscall.c:3977` 和 `kernel/bpf/trampoline.c:767-850`

### 4.3 REJIT 后需要做什么

必须刷新 trampoline image。

而且当前 REJIT 的“是否可重 JIT”判定并不能可靠识别 live LSM attachment：

- `bpf_prog_rejit_supported()` 依赖 `aux->dst_prog` / `aux->dst_trampoline` 等字段，见 `kernel/bpf/syscall.c:3169-3171`
- 但 tracing/LSM attach 成功后会把 `prog->aux->dst_prog = NULL; prog->aux->dst_trampoline = NULL;`，见 `kernel/bpf/syscall.c:3987-4000`

所以结论是：

- live LSM/KRSI user 很可能不会被现有 REJIT guard 挡住
- 一旦 REJIT 发生，旧 trampoline image 仍可能继续调用旧入口地址

### 4.4 开销

refresh 代价明显高于普通 backend：

- 重新生成 trampoline image
- 重新注册/修改 ftrace direct call
- old image 走 tasks-trace/tasks RCU + percpu_ref 的分阶段回收，见 `kernel/bpf/trampoline.c:503-563`

### 4.5 可复用 API

可复用的内部 API 是：

- `bpf_trampoline_update()`
- `bpf_trampoline_link_prog()` / `bpf_trampoline_unlink_prog()`

但缺少“从 prog 找到所有 trampoline”这一层反向索引。

### 4.6 结论

LSM/KRSI 是 REJIT 必须同步的 backend；不解决它，方案 D 不能成立。

## 5. struct_ops

### 5.1 `bpf_func` 怎么缓存

`struct_ops` 不是简单缓存 `prog *`。它在 map 更新时为每个 function member 生成 trampoline，并把最终函数地址写进 live `kvalue.data`：

- `bpf_struct_ops_prepare_trampoline()` 负责准备 trampoline image，见 `kernel/bpf/bpf_struct_ops.c:597-640`
- `bpf_struct_ops_map_update_elem()` 为每个成员构建 trampoline，并把生成的入口写回 `*(void **)(kdata + moff)`，见 `kernel/bpf/bpf_struct_ops.c:686-917`，尤其 `:834-849`

### 5.2 正常更新路径

- 非 link 路径: `bpf_struct_ops_map_update_elem()`，见 `kernel/bpf/bpf_struct_ops.c:686-917`
- link 路径: `bpf_struct_ops_map_link_update()`，见 `kernel/bpf/bpf_struct_ops.c:1260-1307`
- 对应 link ops: `.update_map = bpf_struct_ops_map_link_update`，见 `kernel/bpf/bpf_struct_ops.c:1350-1356`

### 5.3 REJIT 后需要做什么

当前不需要设计 refresh，因为 REJIT 已被禁止：

- `bpf_prog_assoc_struct_ops()` 把关联 map 记录到 `prog->aux->st_ops_assoc`，见 `kernel/bpf/bpf_struct_ops.c:1414-1441`
- `bpf_prog_rejit_supported()` 显式拒绝 `st_ops_assoc != NULL`，见 `kernel/bpf/syscall.c:3169-3174`

如果未来要支持，refresh 基本不可能是“小修补”；需要重建 member trampoline，甚至走整张 struct_ops map 的 update/reg/unreg。

### 5.4 开销

高。比 XDP dispatcher 还重，因为它会改 live subsystem callback 表。

### 5.5 可复用 API

只能部分复用：

- `bpf_struct_ops_map_link_update()`
- 各 subsystem 的 `struct bpf_struct_ops.update`

但这些都是整 map 级 update，不是单 prog 级 refresh。

### 5.6 结论

当前最合理策略是继续禁止 struct_ops prog REJIT。

## 6. fentry / fexit / freplace trampolines

### 6.1 `bpf_func` 怎么缓存

这组 backend 是“最直接缓存 raw address”的路径：

- fentry/fexit/fmod_ret 通过 trampoline image 执行，见 `kernel/bpf/trampoline.c:620-718`
- freplace attach 时直接把目标函数 text-poke 成 jump 到 `link->link.prog->bpf_func`，见 `kernel/bpf/trampoline.c:788-799`
- freplace detach 时再把旧 jump 撤回，见 `kernel/bpf/trampoline.c:861-869`

### 6.2 正常更新路径

- attach 入口仍是 `bpf_tracing_prog_attach()`，见 `kernel/bpf/syscall.c:3802-4012`
- tracing link ops 无 `.update_prog`，见 `kernel/bpf/syscall.c:3795-3800`

### 6.3 REJIT 后需要做什么

必须 backend refresh。

其中：

- fentry/fexit/fmod_ret: 需要 `bpf_trampoline_update()`
- freplace: 需要再次 `bpf_arch_text_poke()` 把目标 site 指向新 `prog->bpf_func`

这类 backend 是方案 D 明确失败的反例。

### 6.4 开销

- fentry/fexit: trampoline image rebuild + ftrace/direct-call 修改 + RCU/tasks-trace retirement
- freplace: 至少一次额外 text poke；如果目标函数正被执行，还要依赖现有 text-poke 机制保证原子性

### 6.5 可复用 API

- `bpf_trampoline_update()`
- `bpf_arch_text_poke()`

但同样缺反向索引：REJIT 无法知道某个 prog 现在被哪些 trampoline / freplace site 使用。

### 6.6 结论

fentry/fexit/freplace 是 REJIT 同步设计的核心难点之一。

## 7. sockmap / sk_msg

### 7.1 `bpf_func` 怎么缓存

只缓存 `struct bpf_prog *`：

- `struct sk_psock_progs` 里是 `msg_parser` / `stream_parser` / `stream_verdict` / `skb_verdict` 四个 `bpf_prog *`，见 `include/linux/skmsg.h:56-65`
- 运行时 `READ_ONCE(psock->progs.*)` 后调用 `bpf_prog_run_pin_on_cpu()`，见 `net/core/skmsg.c:919-953`, `1009-1026`, `1123-1157`, `1251-1260`

### 7.2 正常更新路径

- 非 link attach/detach: `sock_map_prog_update()`，见 `net/core/sock_map.c:1524-1553`
- link update: `sock_map_link_update_prog()`，见 `net/core/sock_map.c:1746-1799`
- 相关 link ops: `.update_prog = sock_map_link_update_prog`，见 `net/core/sock_map.c:1833-1839`

### 7.3 REJIT 后需要做什么

不需要 backend 通知。

### 7.4 开销

无额外开销。

### 7.5 可复用 API

不需要。`psock_replace_prog()` / `sock_map_link_update_prog()` 只是现有的 prog pointer swap 模式，见 `include/linux/skmsg.h:526-537`。

### 7.6 结论

sockmap/sk_msg 是“缓存 `prog *`”安全类。

## 8. perf_event / kprobe / tracepoint / raw_tracepoint / kprobe_multi / uprobe_multi

这组需要拆开看。

### 8.1 perf_event program

#### 缓存方式

- `event->prog`
- 运行时 `prog = READ_ONCE(event->prog); ret = bpf_prog_run(prog, &ctx);`，见 `kernel/events/core.c:10590-10612`

#### 正常更新路径

- attach: `perf_event_set_bpf_prog()` -> `__perf_event_set_bpf_prog()`，见 `kernel/events/core.c:11621-11680`
- 非 tracing perf event 走 `perf_event_set_bpf_handler()`，见 `kernel/events/core.c:10614-10658`
- perf link ops 没有 `.update_prog`，见 `kernel/bpf/syscall.c:4400-4405`

#### REJIT 后动作

不需要 refresh；这里只缓存 `prog *`。

### 8.2 kprobe / tracepoint / syscall tracepoint 经 perf_event attach

#### 缓存方式

- `event->tp_event->prog_array`
- 其中 array item 保存 `prog *`，执行走 `trace_call_bpf()` -> `bpf_prog_run_array(..., bpf_prog_run)`，见 `kernel/trace/bpf_trace.c:109-152` 和 `include/linux/bpf.h:2473-2499`

#### 正常更新路径

- `perf_event_attach_bpf_prog()` / `perf_event_detach_bpf_prog()`，见 `kernel/trace/bpf_trace.c:1920-2005`
- attach 时用 `rcu_assign_pointer(event->tp_event->prog_array, new_array)` 发布，见 `kernel/trace/bpf_trace.c:1953-1957`

#### REJIT 后动作

不需要 refresh；prog_array 里也是 `prog *`。

### 8.3 raw_tracepoint

#### 缓存方式

这里名字最容易误导。`struct bpf_raw_event_map` 确实有 `bpf_func` 字段：

- 定义见 `include/linux/tracepoint-defs.h:56-61`

但这个 `bpf_func` 不是用户 prog 的 JIT 入口，而是一个稳定的 tracepoint wrapper：

- `__bpf_trace_##template` 由宏生成，见 `include/trace/bpf_probe.h:45-50`
- raw tp map 初始化时把 `.bpf_func = __bpf_trace_##template`，见 `include/trace/bpf_probe.h:75-92`
- wrapper 最终从 `link->link.prog` 取 prog 并 `bpf_prog_run(prog, args)`，见 `kernel/trace/bpf_trace.c:2072-2094`

#### 正常更新路径

- attach: `bpf_raw_tp_link_attach()` -> `bpf_probe_register()`，见 `kernel/bpf/syscall.c:4459-4523` 和 `kernel/trace/bpf_trace.c:2141-2162`

#### REJIT 后动作

不需要 refresh。raw tp 注册的是稳定 wrapper，不是用户 prog `bpf_func`。

### 8.4 kprobe_multi / uprobe_multi

#### 缓存方式

- kprobe_multi handler 直接调用 `bpf_prog_run(link->link.prog, regs)`，见 `kernel/trace/bpf_trace.c:2547-2588`
- uprobe_multi handler 也是 `bpf_prog_run(link->link.prog, regs)`，见 `kernel/trace/bpf_trace.c:3074-3113`

#### 正常更新路径

- attach: `bpf_kprobe_multi_link_attach()` / `bpf_uprobe_multi_link_attach()`，见 `kernel/trace/bpf_trace.c:2733-2815`, `3168-3286`
- link ops 都没有 `.update_prog`，见 `kernel/trace/bpf_trace.c:2478-2485`, `3065-3072`

#### REJIT 后动作

不需要 refresh；它们直接拿 `link->link.prog` 执行。

### 8.5 结论

perf_event / kprobe / tracepoint / raw_tracepoint / kprobe_multi / uprobe_multi 整组都属于“缓存 `prog *` 或稳定 wrapper”的安全类，不需要 REJIT backend 通知。

## 9. sched_ext

### 9.1 `bpf_func` 怎么缓存

`sched_ext` 本质上是 `struct_ops`：

- `bpf_sched_ext_ops` 注册了 `.reg/.unreg/.update`，见 `kernel/sched/ext.c:5523-5534`
- 模块初始化时 `register_bpf_struct_ops(&bpf_sched_ext_ops, sched_ext_ops)`，见 `kernel/sched/ext.c:7444-7445`

因此它本质上继承了 struct_ops 那套 member trampoline / callback table 模型，而不是简单的 `prog *` 缓存。

### 9.2 正常更新路径

- `bpf_scx_reg()` / `bpf_scx_unreg()` / `bpf_scx_update()`，见 `kernel/sched/ext.c:5406-5437`
- 其中 `bpf_scx_update()` 直接返回 `-EOPNOTSUPP`

### 9.3 REJIT 后需要做什么

当前不应支持。

原因有两层：

- struct_ops 关联 prog 已经被 `bpf_prog_rejit_supported()` 拒绝
- sched_ext 自己也明确不支持 live update，见 `kernel/sched/ext.c:5428-5437`

### 9.4 开销

如果未来勉强支持，代价接近“重新 enable 一个 BPF scheduler”，不适合做 REJIT 热修。

### 9.5 可复用 API

没有合适的轻量级 API。`bpf_scx_update()` 明确拒绝。

### 9.6 结论

sched_ext 应继续留在 REJIT 禁止名单里。

## 10. 哪些 backend 已经是“通过 prog 间接调用”

已基本满足“通过 `prog *` 间接执行”的 backend：

- TC / act_bpf
- cgroup BPF
- sockmap / sk_msg
- perf_event
- kprobe / tracepoint / syscall tracepoint
- raw_tracepoint
- kprobe_multi / uprobe_multi

不满足的 backend：

- XDP dispatcher
- LSM / KRSI trampoline
- fentry / fexit / freplace trampoline
- struct_ops
- sched_ext

需要注意：

- “netdev/cache 着 `prog *`”不等于“XDP 没问题”，因为真正的问题在 dispatcher/static_call。
- raw_tracepoint 虽然也有个字段名叫 `bpf_func`，但那是 wrapper，不是用户 prog JIT 入口。

## 11. 方案 A: 逐 backend 通知

### 11.1 可行性

理论上可行，但不能像现在这样在 REJIT 里“凭 prog->aux 猜”。

现状没有通用的 “prog -> 所有 live attachments” 索引：

- `struct bpf_link` 只有 `link->prog`，没有 reverse list，见 `include/linux/bpf.h:1845-1888`
- `struct bpf_prog_aux` 里只有少数专用字段，如 `dst_prog` / `dst_trampoline` / `st_ops_assoc`，见 `include/linux/bpf.h:1677-1740`
- tracing attach 成功后还会清空 `dst_prog` / `dst_trampoline`，见 `kernel/bpf/syscall.c:3987-4000`

### 11.2 怎么知道 prog attach 到了哪些地方

当前内核没有现成通用 API。

要做 A，基本只有两条路：

1. 新增一个通用 reverse registry
   - 在 `bpf_prog_aux` 里维护 attachment list / counter
   - 所有 attach/detach 路径维护它
2. 或者每个 backend 自己维护“我这里有哪些 prog 需要 refresh”的私有反向索引

从改动面看，第二条更现实，因为真正需要 refresh 的 backend 其实只有 XDP dispatcher 和 trampoline/freplace。

### 11.3 大概改多少行

这是推断，不是现成统计：

- 如果做“全内核通用 prog->attachments 基础设施”，改动大概率是 low-thousands LOC，且横跨 `kernel/bpf/`, `net/`, `kernel/trace/`, `kernel/sched/`
- 如果只做“最小闭环”，即只覆盖 XDP dispatcher + trampoline/freplace 两类真实问题 backend，量级更像几百行

### 11.4 优缺点

优点：

- 热路径零额外开销
- 保留 XDP dispatcher / trampoline 的性能模型

缺点：

- 需要引入 attachment state
- 需要解决 tracing/LSM 反向发现问题
- 实现复杂度集中在状态维护，而不是 REJIT 本身

### 11.5 结论

方案 A 只有做成“定向通知真实缓存地址的 backend”才值得；做成“全 backend 一视同仁通知”是过度设计。

## 12. 方案 B: 全部改成间接指针

### 12.1 现状上哪些 backend 已经是这样

见上文第 10 节。大多数 backend 已经是“缓存 `prog *`，执行时调用通用 helper”。

### 12.2 哪些 backend 不是

- XDP dispatcher
- trampoline/freplace
- struct_ops / sched_ext

### 12.3 性能影响

对普通 backend 几乎没必要，因为它们已经间接。

真正要改的恰恰是最在意热路径的 backend：

- XDP dispatcher 的设计目的就是避免普通间接调用/retpoline，见 `kernel/bpf/dispatcher.c:94-135` 和 `include/linux/bpf.h:1490-1508`
- trampoline/freplace 也是为了把 tracing/LSM/extension 的开销压到最低

所以 B 作为“通用 retrofit”会直接冲掉这些优化。

### 12.4 结论

方案 B 不是统一答案；它只是对已经安全的 backend 的现状描述，不适合作为 XDP/trampoline 的改造方向。

## 13. 方案 C: RCU image 对象

### 13.1 能解决什么

如果把 JIT image 独立成 refcounted + RCU 发布对象，可以把 `prog->bpf_func` 的替换和 image 生命周期管理做得更正规。

### 13.2 解决不了什么

即使 `prog->jit_image` 变成 RCU pointer，也仍然解决不了“别人已经缓存了旧 image 地址”的问题：

- XDP dispatcher image 仍然写着旧地址
- trampoline image 仍然写着旧地址
- freplace site 仍然被 text-poke 到旧地址

除非同时把这些 backend 也改成 stable veneer / extra indirection，否则 C 单独拿出来并不能闭环。

### 13.3 改动量

非常大，属于架构级改造，而不是 REJIT feature patch。

### 13.4 结论

方案 C 过重，而且并不自动解决当前最棘手的 direct-address cache。

## 14. 方案 D: `WRITE_ONCE(prog->bpf_func) + smp_wmb + synchronize_rcu` 够不够

### 14.1 什么时候够

只有在下面前提成立时才够：

- 所有执行路径都不缓存 raw code address
- 每次调用都通过 `prog->bpf_func` 取当前入口

如果这个前提成立，那么现有 writer-side publish + RCU retirement 已经接近足够。

### 14.2 当前内核是否满足

不满足。

明确反例：

- XDP dispatcher 在 image 里缓存 `d->progs[i].prog->bpf_func`，见 `kernel/bpf/dispatcher.c:99-103`
- freplace attach 直接把 jump target 设成 `link->link.prog->bpf_func`，见 `kernel/bpf/trampoline.c:795-799`
- tracing/LSM trampoline 使用生成好的 `tr->cur_image`，见 `kernel/bpf/trampoline.c:678-712`

### 14.3 还缺什么

即便只讨论“已经间接”的 backend，当前读侧也没有 `READ_ONCE(prog->bpf_func)`，只有普通字段读，见 `include/linux/filter.h:700-724`。

所以如果未来要把 D 明确成官方 contract，我建议把通用 hot helper 改成：

- `READ_ONCE(prog->bpf_func)` 读取入口

这不是为了解决 XDP/trampoline，而是把现有 lockless publish 语义补完整。

### 14.4 结论

方案 D 对“安全类 backend”成立，对整个子系统不成立。

## 15. 对比表

| 方案 | 能否覆盖当前真实问题 | 热路径性能 | 改动量 | 主要问题 | 结论 |
| --- | --- | --- | --- | --- | --- |
| A. 逐 backend 通知 | 可以，但应只覆盖 XDP dispatcher + trampoline/freplace | 最好 | 中到高 | 需要反向 attachment registry；当前内核没有 | 推荐，但要做成定向版 |
| B. 全部改间接指针 | 覆盖不了 XDP/trampoline 的性能设计目标 | 最差 | 中到高 | 会把最关键的优化路径打回 indirect call | 不推荐作为统一方案 |
| C. RCU image 对象 | 单独看不够 | 取决于具体实现 | 很高 | 仍解决不了外部已缓存旧地址 | 不推荐 |
| D. 仅依赖 `WRITE_ONCE + RCU` | 只能覆盖已经间接的 backend | 最好 | 最低 | 对 dispatcher/trampoline 明确失效 | 只能作为安全类 backend 的基础语义 |

## 16. 推荐方案

推荐的是一个很明确的混合方案，而不是纯 A/B/C/D：

### 16.1 短期

先把 REJIT 的允许范围收紧到“只允许安全类 backend”：

- 继续允许:
  - TC
  - cgroup BPF
  - sockmap/sk_msg
  - perf_event / tracepoint / raw_tracepoint / kprobe_multi / uprobe_multi
- 继续禁止:
  - struct_ops
  - sched_ext
- 新增禁止或检测:
  - live XDP dispatcher user
  - live trampoline/freplace user

最重要的不是“通知谁”，而是“先别错放行”。当前 `dst_trampoline` 清空后，tracing/LSM live attachment 可能漏检。

### 16.2 中期

为真正有 stale-address 风险的 backend 增加定向 refresh：

1. XDP dispatcher
   - 新增 same-prog refresh API
   - REJIT 成功后 rebuild dispatcher image，并走已有 `synchronize_rcu()`
2. trampoline/freplace
   - 给 prog 增加反向 attachment 追踪，或给 trampoline/XDP dispatcher 增加可从 prog 发现 membership 的索引
   - REJIT 成功后调用 `bpf_trampoline_update()` / `bpf_arch_text_poke()`

### 16.3 长期

如果以后要把 “REJIT + lockless bpf_func publish” 作为正式语义，再考虑：

- 通用 helper 读侧使用 `READ_ONCE(prog->bpf_func)`
- 但不要为此牺牲 XDP dispatcher / trampoline 的 direct-call 设计

## 17. 最终判断

从当前源码看，最合理的结论不是“所有 backend 都要同步更新”，而是：

- 绝大多数 backend 根本没有缓存用户 prog 的 `bpf_func`
- 真正需要同步的只有 XDP dispatcher 和 trampoline/freplace 家族
- `struct_ops/sched_ext` 继续拒绝 REJIT
- 当前第一优先级不是实现大而全的 refresh，而是修正 REJIT 的 attachment 可见性判断，避免对 live tracing/LSM user 误放行

如果要把实现成本和性能都控制住，推荐路线是：

- 以方案 D 作为安全类 backend 的基础语义
- 以方案 A 的“定向通知版”覆盖 XDP dispatcher 和 trampoline/freplace
- 不做全局方案 B/C
