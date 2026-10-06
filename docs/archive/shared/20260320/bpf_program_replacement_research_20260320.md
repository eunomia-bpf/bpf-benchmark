# Linux BPF 程序热替换机制调研

日期: 2026-03-20

调研范围:
- 内核源码: `vendor/linux-framework/`（本地 7.0-rc2 树）
- libbpf: `vendor/libbpf/`
- Cilium 实践: `/tmp/cilium-src-191417`，commit `7be1b3108f6801a2a204bddcf2a52102cd99759d`

## 结论摘要

结论先说清楚:

1. 一个 privileged daemon 确实可以读取 live BPF program 的大量运行时信息，包括:
   - `prog_id -> prog_fd -> prog_info`
   - verifier 后导出的 `xlated_prog_insns`
   - `map_ids`
   - `btf_id`
   - 在权限足够时的 `jited_prog_insns`
2. 但它不能把任意 live BPF program 普遍地当成“可逆对象”，即不能泛化为:
   - 读出 live program
   - 在 bytecode 层改写
   - 重新提交
   - 对所有 attach 家族都做原子替换
3. 根本障碍有四类:
   - `xlated_prog_insns` 不是原始 ELF 指令，而是 verifier 改写后的、再经过导出清洗的指令视图。
   - `bpf_prog_info` 不足以恢复完整 attach 上下文；真正的 attach 位置/对象通常要从 `bpf_link_info` 或子系统专有句柄恢复。
   - `bpf_link_update()` 只对少数 link 类型真正支持；大量 attach 家族并没有统一的原子 update 入口。
   - 每次 `BPF_PROG_LOAD` 都重新走 verifier + runtime/JIT；在当前内核树里没有发现增量验证路径。
4. 所以:
   - “daemon 管理自己装载、自己持有元数据、自己维护 link/map pin”的受控架构是可行的。
   - “仅靠 live prog_id + xlated bytecode，对任意外部已加载程序做通用热替换”的架构不可行。

下面按问题逐项展开。

## 1. 读取 live BPF program

### 1.1 `BPF_PROG_GET_NEXT_ID -> BPF_PROG_GET_FD_BY_ID -> BPF_OBJ_GET_INFO_BY_FD`

内核中的对象枚举和取 FD 路径很直接:

- `bpf_obj_get_next_id()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:4731-4755`
- program 枚举 helper `bpf_prog_get_curr_or_next()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:4776-4793`
- `bpf_prog_get_fd_by_id()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:4814-4835`
- `bpf_obj_get_info_by_fd()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:5424-5449`
- `struct bpf_prog_info` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:6753-6793`

标准 userspace 链路就是:

```text
prog_id = BPF_PROG_GET_NEXT_ID(...)
prog_fd = BPF_PROG_GET_FD_BY_ID(prog_id)
info    = BPF_OBJ_GET_INFO_BY_FD(prog_fd)
```

`prog_info` 读取 `xlated_prog_insns`/`jited_prog_insns` 时通常要走两次调用。内核 selftest 里的 helper `get_xlated_program()` 明确展示了这个模式:

- 第一次调用只拿长度
- 分配 buffer
- 第二次调用拿实际指令

参考 `vendor/linux-framework/tools/testing/selftests/bpf/testing_helpers.c:455-489`。

### 1.2 `xlated_prog_insns` 到底是什么

这不是“原始编译器输出的 eBPF bytecode”。

`bpf_prog_get_info_by_fd()` 在导出 `xlated_prog_insns` 时调用 `bpf_insn_prepare_dump()`，代码见:

- `vendor/linux-framework/kernel/bpf/syscall.c:5059-5085`
- `vendor/linux-framework/kernel/bpf/syscall.c:4903-4959`

`bpf_insn_prepare_dump()` 直接从 `prog->insnsi` 复制当前程序指令，然后再做导出清洗:

- `BPF_TAIL_CALL` 被改写回 helper call 形式
- `BPF_CALL_ARGS` 被规范化为普通 `BPF_CALL`
- 对无 raw-dump 权限的调用者，call imm 会被清零
- `BPF_PROBE_MEM` / `BPF_PROBE_MEM32` 会被还原成普通内存访问编码
- `LD_IMM64` 中的 map kernel pointer 会被还原成 pseudo-map 形式，`imm` 里写 map id，下一条写 offset

也就是说，userspace 看到的是:

```text
verifier/loader 内核内部最终指令流
-> 再经过 export sanitizer 处理后的视图
```

不是:

```text
原始 ELF 指令流
```

更重要的是，verifier 在程序通过验证后还会继续做一轮真实的代码重写。`bpf_check()` 的后半段明确写着 “instruction rewrites happen after this point”，并顺序调用:

- `optimize_bpf_loop()`
- `opt_hard_wire_dead_code_branches()`
- `opt_remove_dead_code()`
- `opt_remove_nops()`
- `convert_ctx_accesses()`
- `do_misc_fixups()`
- `opt_subreg_zext_lo32_rnd_hi32()`
- `fixup_call_args()`

见 `vendor/linux-framework/kernel/bpf/verifier.c:26076-26109`。

另外，`func_info->insn_off` 的注释也直接说明它是在 “all code rewrites” 之后才设定，见 `vendor/linux-framework/kernel/bpf/verifier.c:22121-22123`。

因此结论是:

- `xlated_prog_insns` 不是原始 bytecode
- 它更接近“verifier 最终接受并导出的内核指令流”
- 这个对象适合做运行后分析和模式匹配
- 但不适合作为“无损重建原程序”的唯一输入

### 1.3 能否读到完整 BTF、map 定义、attach 信息

#### BTF

可以读到 program 关联的完整 raw BTF blob，只要 program 有 `prog->aux->btf`。

- `prog_info.btf_id` 在 `vendor/linux-framework/kernel/bpf/syscall.c:5051-5053`
- `BPF_BTF_GET_FD_BY_ID` 路径在 `vendor/linux-framework/kernel/bpf/syscall.c:5483-5513`
- `btf_get_info_by_fd()` 会把 `btf->data` 原样拷给 userspace，见 `vendor/linux-framework/kernel/bpf/btf.c:8180-8205`
- libbpf wrapper 在 `vendor/libbpf/src/bpf.c:1159-1225`

所以 daemon 可以走:

```text
prog_info.btf_id
-> BPF_BTF_GET_FD_BY_ID
-> BPF_OBJ_GET_INFO_BY_FD(btf_fd)
-> raw BTF blob
```

#### map 定义

`prog_info` 本身只给 `map_ids`，见 `vendor/linux-framework/include/uapi/linux/bpf.h:6763-6764`，填充逻辑在 `vendor/linux-framework/kernel/bpf/syscall.c:5025-5040`。

要进一步恢复 map 对象，daemon 还需要:

```text
map_id
-> BPF_MAP_GET_FD_BY_ID
-> BPF_OBJ_GET_INFO_BY_FD(map_fd)
```

其中:

- `bpf_map_get_fd_by_id()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:4839-4868`
- libbpf wrapper 在 `vendor/libbpf/src/bpf.c:1121-1141`
- `struct bpf_map_info` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:6795-6824`

但要注意，这里恢复的是“运行时 map 对象属性”，不是原始 ELF map 声明本身。也就是说你通常能拿回:

- map type
- key/value size
- max_entries
- flags
- BTF type id
- map name

但拿不回完整的原始 libbpf 语义，例如:

- 原始 ELF 中的 pinning 策略
- CO-RE relocation 上下文
- 某些 loader-time 常量改写语义
- data section 的原始初始化布局意图

所以 “能恢复 map 对象” 和 “能无损恢复原始 map 定义” 不是一回事。

#### attach 信息

这里是一个关键坑。

`struct bpf_prog_info` 虽然带有一些 attach 相关字段，例如 `attach_btf_id`、`attach_btf_obj_id`、`ifindex`、`netns_dev`、`netns_ino`，见 `vendor/linux-framework/include/uapi/linux/bpf.h:6766-6793`，但在当前 `bpf_prog_get_info_by_fd()` 实现中，常规 program info 主要填的是:

- `map_ids`
- `btf_id`
- `attach_btf_id`
- func/line info
- jited info

代码见 `vendor/linux-framework/kernel/bpf/syscall.c:4992-5279`。

我在当前树上搜索 `info.ifindex` / `info.netns_dev` / `info.netns_ino`，没有找到常规 `prog_info` 填充路径。也就是说，仅靠 `prog_id -> prog_info`，通常不足以可靠恢复 attach 位置。

真正可用的 attach 元数据要看 `bpf_link_info`:

- `bpf_link_get_info_by_fd()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:5369-5404`
- link 枚举和 `BPF_LINK_GET_FD_BY_ID` 在 `vendor/linux-framework/kernel/bpf/syscall.c:5924-5965`
- `struct bpf_link_info` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:6825-6950`

`bpf_link_info` 按 link type 暴露更具体的目标信息，例如:

- cgroup id
- tracing target obj/btf id
- xdp ifindex
- netns inode
- netfilter hook 参数
- tcx ifindex
- sockmap map id

因此，如果 daemon 要做可靠替换，它不能只枚举 `prog_id`，还必须枚举 `link_id`，并建立:

```text
prog_id <-> link_id(s) <-> attach target
```

这个映射。

### 1.4 `jited_prog_insns` 能否读到 native code

可以，但有权限门槛。

`bpf_prog_get_info_by_fd()` 中:

- 对不满足 `bpf_capable()` 的调用者，`jited_prog_len` / `xlated_prog_len` / 各类 jited info 都被清零，见 `vendor/linux-framework/kernel/bpf/syscall.c:5055-5063`
- `jited_prog_insns` 的 copy path 在 `vendor/linux-framework/kernel/bpf/syscall.c:5098-5140`

此外，真正是否允许 raw dump 还要看 `bpf_dump_raw_ok(file->f_cred)`。这个 helper 在 `vendor/linux-framework/include/linux/filter.h:1178-1184`，依赖 `kallsyms_show_value()`。`bpf_capable()` 定义在 `vendor/linux-framework/include/linux/capability.h:195-198`，需要 `CAP_BPF` 或 `CAP_SYS_ADMIN`。

结论:

- 有足够权限的 daemon 可以读到 native JIT code bytes
- 但它依赖 raw-dump policy，不是所有 privileged 场景都默认可见

## 2. BPF program 替换机制

### 2.1 `bpf_link_update(link_fd, new_prog_fd, flags)` 的真实语义

syscall 入口在 `vendor/linux-framework/kernel/bpf/syscall.c:5815-5865`。

核心语义:

1. 只接受 `BPF_F_REPLACE`
2. 从 `link_fd` 取 link
3. 从 `new_prog_fd` 取新 program
4. 如果设置了 `BPF_F_REPLACE`，再从 `old_prog_fd` 取旧 program，作为 compare-and-swap guard
5. 调用 `link->ops->update_prog(link, new_prog, old_prog)`

也就是说:

- `old_prog_fd` 不是“要替换哪个旧 program 的名字”
- 它是防并发错替换的 guard
- 如果当前 link 上挂的 program 不是你认为的 old program，内核会拒绝

libbpf 封装:

- syscall wrapper: `vendor/libbpf/src/bpf.c:940-963`
- 高层 API `bpf_link__update_program()`: `vendor/libbpf/src/libbpf.c:11073-11085`
- API 声明: `vendor/libbpf/src/libbpf.h:493`

### 2.2 哪些 attach 类型支持 link-based update

在当前内核树中，repo-wide 搜索 `.update_prog =` 只找到这些实现:

- cgroup: `vendor/linux-framework/kernel/bpf/cgroup.c:1465`
- tcx: `vendor/linux-framework/kernel/bpf/tcx.c:293`
- netns: `vendor/linux-framework/kernel/bpf/net_namespace.c:239`
- iter: `vendor/linux-framework/kernel/bpf/bpf_iter.c:494`
- XDP link: `vendor/linux-framework/net/core/dev.c:10655`
- sockmap/sockhash link: `vendor/linux-framework/net/core/sock_map.c:1837`
- netfilter link: `vendor/linux-framework/net/netfilter/nf_bpf_link.c:177`

但 netfilter 只是“有 update hook”，实现本身直接返回 `-EOPNOTSUPP`，见 `vendor/linux-framework/net/netfilter/nf_bpf_link.c:163-168`。

所以当前树里实际可 update 的 link 类型是:

- XDP link
- cgroup link
- tcx link
- netns link
- sockmap/sockhash link
- iter link

而不是“所有 bpf_link”。

没有出现在这份 `.update_prog` 列表里的 link 家族，例如 tracing/raw_tp/perf/kprobe_multi/uprobe_multi，当前树里都没有统一的 link update 支持。

### 2.3 替换是否原子，会不会丢事件

对“支持 update 的 link 类型”，内核里的切换语义是原子的指针替换，而不是 detach-to-null 再 attach。

几个代表性实现:

- cgroup replace 使用 `xchg(&link->link.prog, new_prog)`，并把 effective array 中对应 slot 用 `WRITE_ONCE()` 改成新 prog，见 `vendor/linux-framework/kernel/bpf/cgroup.c:924-1033`
- XDP link update 在 driver 安装成功后执行 `xchg(&link->prog, new_prog)`，见 `vendor/linux-framework/net/core/dev.c:10599-10646`
- 通用 prog array 更新使用 `WRITE_ONCE(item->prog, prog)`，见 `vendor/linux-framework/kernel/bpf/core.c:2814-2845`
- tcx 的多程序基础设施专门强调 `READ_ONCE()/WRITE_ONCE()` + RCU 访问模型，见 `vendor/linux-framework/include/linux/bpf_mprog.h:20-113`

因此对这些支持 update 的路径:

- 不存在“先 detach 掉导致一段时间无程序挂载”的空窗
- 旧程序会和新程序通过 RCU 生命周期平滑交接
- 不应因为 update 本身出现明显的“丢事件窗口”

但这不等于“全系统所有 CPU 在同一个瞬间都只看到新程序”。准确说法是:

- 指针替换是原子的
- 旧程序在 grace period 内仍可能被并发执行路径短暂持有
- 这是标准 RCU 语义，不是 detach gap

### 2.4 旧程序的 RCU 生命周期

program 最终释放走 `bpf_prog_put()`:

- `__bpf_prog_put_noref()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:2377-2395`
- `bpf_prog_put()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:2426-2428`

其中:

- 普通 program 走 `call_rcu()`
- 某些需要更强同步语义的路径会走 `call_rcu_tasks_trace()`

也就是说 link update 之后，旧 program 并不是立刻 free，而是等 RCU grace period 后回收。

### 2.5 非 link attach 的程序能否替换

能不能替换，取决于 attach 家族，不存在统一答案。

#### cgroup / mprog 家族

`BPF_PROG_ATTACH` 入口在 `vendor/linux-framework/kernel/bpf/syscall.c:4483-4563`。

UAPI 注释明确写了:

- 对 cgroup multi attach，可以用 `BPF_F_REPLACE`
- 用 `replace_bpf_fd` 指定要替换的位置

见 `vendor/linux-framework/include/uapi/linux/bpf.h:1208-1244`。

所以 cgroup 的非-link attach 仍然有 replace 语义。

#### legacy socket attach (`SO_ATTACH_BPF`)

这是 socket 子系统自己的替换语义，不是通用 link update。

- `SO_ATTACH_BPF` 调到 `sk_attach_bpf()`，见 `vendor/linux-framework/net/core/sock.c:1471-1481`

这类路径必须用 socket 句柄和对应 socket API 操作，daemon 不能只拿 `prog_id` 做通用替换。

#### legacy tc filter

`tc` 的 eBPF filter replace 走的是 qdisc/classifier 语义，也不是 `bpf_link_update()`。

- `cls_bpf_change()` 在 `vendor/linux-framework/net/sched/cls_bpf.c:407-528`
- 替换时执行 `idr_replace()` + `list_replace_rcu()`，然后异步清理旧 prog

这说明 legacy tc 的替换是子系统专有的 RCU replace。

结论:

- 非 link attach 并非“完全不能替换”
- 但它们没有统一热替换 API
- daemon 如果要支持它们，必须理解各子系统的 attach 句柄、定位方式和替换协议

### 2.6 `BPF_PROG_REPLACE` 语义

在这棵 7.0-rc2 树里，没有独立的 `BPF_PROG_REPLACE` syscall command。

用户口中的 “BPF_PROG_REPLACE” 在当前语境里通常混淆了三件事:

1. `BPF_F_REPLACE` 这个 flag
2. `BPF_PROG_ATTACH` / `BPF_LINK_UPDATE` 中的 replace 语义
3. `freplace`，也就是 `BPF_PROG_TYPE_EXT`

代码证据:

- `BPF_F_REPLACE` 定义在 `vendor/linux-framework/include/uapi/linux/bpf.h:1244`
- `replace_bpf_fd` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:1758`
- `attach_prog_fd` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:1698`
- `BPF_PROG_TYPE_EXT` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:1090`

### 2.7 `freplace` / `BPF_PROG_TYPE_EXT` 是什么，不是什么

`freplace` 是用 `BPF_PROG_TYPE_EXT` 把一个 BPF program 挂到另一个 BPF program/subprog 的 trampoline target 上。

相关路径:

- load-time target 处理在 `vendor/linux-framework/kernel/bpf/syscall.c:2947-3055`
- `BPF_PROG_TYPE_EXT` link create 分派在 `vendor/linux-framework/kernel/bpf/syscall.c:5712-5737`
- target 检查在 `vendor/linux-framework/kernel/bpf/trampoline.c:991-1034`
- libbpf API `bpf_program__attach_freplace()` 在 `vendor/libbpf/src/libbpf.c:13304-13331`

这不是通用 XDP/tc/cgroup hook 程序的热替换机制。它解决的是 BPF-to-BPF extension/trampoline 场景，不是 “拿任意 live hook program 原子换新版本”。

## 3. Map 跨程序持久化

### 3.1 Map 是独立对象，程序替换不必丢数据

这点成立。

map 本身是独立内核对象，可以 pin 在 bpffs。新程序如果复用旧 map object，那么 key/value 数据自然保留。

从 live program 出发，daemon 可以拿到 `map_ids`，然后进一步拿到 `map_fd`:

```text
prog_info.map_ids
-> BPF_MAP_GET_FD_BY_ID(map_id)
-> reuse existing map fd while loading new prog
```

### 3.2 新程序怎么复用旧 map

libbpf 的直接 API 是 `bpf_map__reuse_fd()`:

- 实现在 `vendor/libbpf/src/libbpf.c:4979-5030`
- 声明在 `vendor/libbpf/src/libbpf.h:1097`

这个函数会:

- 读取现有 map fd 的 `bpf_map_info`
- dup 一份 fd
- 把当前 map spec 的 fd 改成这个已有对象
- 用运行时对象信息回填 `type/key_size/value_size/max_entries/map_flags/map_extra`
- 标记 `map->reused = true`

兼容性检查在 `map_is_reuse_compat()`:

- `vendor/libbpf/src/libbpf.c:5166-5198`

它要求基本参数匹配:

- type
- key_size
- value_size
- max_entries
- map_flags
- map_extra

`bpf_object__reuse_map()` 则展示了 pinned-map reuse 的标准流程:

- `vendor/libbpf/src/libbpf.c:5201-5234`

结论:

- 如果新程序的 map 定义与旧 map 兼容，可以直接 reuse old map fd
- reuse 的是同一个 map object，不是 copy
- 因此 map 中已有 key/value 数据保留

### 3.3 只凭 live program 能否无损复用 map

不能保证无损。

live `prog_info` 只给 `map_ids`，不直接给你一份“新的可加载 program 需要的 map spec”。daemon 仍然需要二选一:

1. 自己维护新程序的完整 map schema，然后把旧 map fd 注入进去
2. 从运行时 map 对象反推 schema，再构造一个兼容的新 load 请求

这意味着 “bytecode 层热替换” 如果完全不依赖原始 ELF/spec，工程上会变得很脆弱。

### 3.4 全局变量 `.data/.rodata/.bss`

这些在 libbpf 里也是 map。

libbpf 头文件直接说明 global data section maps 属于特殊情况，见 `vendor/libbpf/src/libbpf.h:1123-1131`。

初始化与 freeze 逻辑在:

- `vendor/libbpf/src/libbpf.c:5237-5268`

关键点:

- `.data` / `.bss` / `.rodata` / `.kconfig` 都是 data-section map
- libbpf 会把初始内容写进 map
- `.rodata` 和 `.kconfig` 之后会 `bpf_map_freeze()`

这对热替换有两个重要后果:

1. 如果新程序只是换控制流，但全局数据 layout 和常量语义不变，那么 reuse 这些 map 是可能的。
2. 如果新程序改变了:
   - 全局变量布局
   - 常量数量/排列
   - `.rodata` 内容语义
   - `.kconfig` 依赖

   那么直接 reuse 旧 global-data map 可能是错误的，甚至会因为 freeze 而无法重新初始化。

所以 data-section map 不能简单等同于“普通业务 map”。

## 4. 完整 daemon 工作流设计与障碍分析

用户设想的工作流是:

```text
daemon:
  for each live BPF prog:
    1. BPF_PROG_GET_FD_BY_ID -> fd
    2. BPF_OBJ_GET_INFO_BY_FD -> xlated insns + map_ids + attach_type
    3. analyze xlated insns -> find optimization sites
    4. rewrite bytecode -> optimized version
    5. BPF_PROG_LOAD(optimized bytecode, reuse maps) -> new_fd
    6. bpf_link_update(link_fd, new_fd) or equivalent
```

逐步判断如下。

### 4.1 第 1 步: 读 live prog fd

可行。

前提:

- 进程有足够权限
- program 没在枚举期间消失

### 4.2 第 2 步: 读 `prog_info`

部分可行，但信息不完整。

你能稳定拿到:

- verifier 后导出的 xlated insns
- map ids
- btf id
- 部分 attach 相关字段
- 统计信息和 jited 信息

你拿不到或拿不稳的:

- 原始 ELF bytecode
- 完整 loader-time relocation 语义
- 可靠的 attach target 定位信息
- “如何替换这个 attach”的统一句柄

所以这一步必须扩展成:

```text
2a. prog_info
2b. link enumeration/link_info
2c. map_info for each map_id
2d. optional BTF dump
```

### 4.3 第 3 步: 基于 `xlated_prog_insns` 做优化分析

可行，但要接受分析对象已经不是原始 bytecode。

如果你的优化器像当前 scanner 一样，做的是:

- peephole match
- 指令模式识别
- verifier 后控制流上的局部优化机会发现

那 `xlated_prog_insns` 是可以分析的。

如果你的目标是:

- 回到源级语义
- 重新做完整 relocation
- 还原原始 helper/map/ctx 访问意图

那么只靠 `xlated_prog_insns` 不够。

### 4.4 第 4 步: 重写 bytecode

这是整个方案的最大工程风险点。

原因不是“不能改指令”，而是“改完之后你要重新构造一个可通过 verifier 的全新 load 单元”。

至少要正确处理:

- map pseudo relocation
- helper call immediate
- subprog / BTF func info / line info 一致性
- attach type / expected attach type
- global-data map 布局
- 被 verifier 改写后再导出的指令与原始 load 输入之间的差异

换句话说，这一步不是 “patch live prog in place”，而是:

```text
构造一个新的可加载 BPF program object
```

### 4.5 第 5 步: `BPF_PROG_LOAD(optimized bytecode, reuse maps)`

只在受控条件下可行。

内核 load 路径见 `vendor/linux-framework/kernel/bpf/syscall.c:2990-3100`:

- 分配新 prog
- 拷入 insns
- `security_bpf_prog_load()`
- `bpf_check()` 跑 verifier
- `bpf_prog_select_runtime()` 走 JIT/runtime select

然后 `bpf_prog_select_runtime()` 在 `vendor/linux-framework/kernel/bpf/core.c:2599-2652` 中调用:

- `bpf_prog_alloc_jited_linfo()`
- `bpf_int_jit_compile()`

所以每次 load 都是全新的一次 verifier + runtime select/JIT。

如果 daemon 自己持有:

- 原始可加载程序 schema
- map schema
- attach metadata
- link pin/path

那这一步可行。

如果 daemon 只有:

- live `xlated_prog_insns`
- `prog_id`

那这一步很难做成稳定产品。

### 4.6 第 6 步: `bpf_link_update(link_fd, new_fd)` 或等价物

这一步不是通用的。

只有两种情况可做:

1. 原 attach 是支持 `update_prog` 的 link 类型
2. daemon 知道该 attach 家族的专有 replace 协议

否则就做不了原子替换。

### 4.7 真正的阻碍在哪里

如果把问题表述成:

```text
一个 privileged daemon 能否对“任意 live BPF program”完成：
读取 -> bytecode 重写 -> 提交新程序 -> 原子替换
```

答案是: 不能通用成立。

阻碍分别是:

1. `xlated_prog_insns` 不是原始程序，不足以无损重建 load 输入。
2. `prog_info` 不足以恢复 attach 目标和 attach 句柄。
3. 不是所有 attach 类型都支持 update/replace，更不是都支持原子 update。
4. map/global-data reuse 需要额外 schema 信息。
5. load 一定重新 verifier + JIT，代价远高于当前 repo 的 recompile-only 路线。

如果把问题收缩成:

```text
daemon 只管理自己装载/登记的 BPF 程序，
保存原始 schema、map pin、link pin、attach family 元数据，
并且只覆盖支持热替换的 attach 家族
```

那答案是: 可以。

## 5. 性能开销分析

### 5.1 当前内核路径一定重新 verifier + JIT

`bpf_prog_load()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:2990-3100` 中无条件重新走:

- `bpf_check()` verifier
- `bpf_prog_select_runtime()` runtime selection / JIT

`bpf_prog_select_runtime()` 的 JIT 路径在 `vendor/linux-framework/kernel/bpf/core.c:2599-2652`。

verifier 自己记录 `env->verification_time`，见:

- `vendor/linux-framework/kernel/bpf/verifier.c:26111`

只有在打开 `BPF_LOG_STATS` 时才会把它打印成:

- `verification time %lld usec`

见 `vendor/linux-framework/kernel/bpf/verifier.c:24742-24760`。

所以:

- verifier 时间是内核内部实际有统计的
- 但它不是一个可直接从 `prog_info` 读回的常驻字段
- 如果想拿精确 verifier-only 时间，要在 load 时开启 verifier log/stats

### 5.2 当前树里没有看到增量验证

我没有在这棵 7.0-rc2 树里找到“对已验证旧程序做增量 verifier 复用/缓存”的路径。

目前的 load 语义仍然是:

```text
new insns
-> full verifier
-> runtime select / JIT
```

因此对于 daemon 方案，性能上最大的结构性差异就是:

- 当前 recompile-only 方案只在已有 JIT/native code 上做很轻量的重编排
- 重新 load 新 BPF program 则重新进入 verifier 和 JIT

这两者不是一个量级。

### 5.3 本地实测: Cilium 大程序 steady-state load 时间

在当前工作树上，我用本地 `micro_exec` 做了一次 `compile-only` 实测:

```text
sudo -n micro/build/runner/micro_exec list-programs \
  --program corpus/bcf/cilium/clang-21_-O1_bpf_host.o
```

可见该对象里的较大程序包括:

- `cil_to_netdev`: 3638 insns，可直接作为 `sched_cls` 入口程序装载
- `tail_handle_snat_fwd_ipv4`: 3996 insns，内部 tail program
- `tail_handle_snat_fwd_ipv6`: 3668 insns

然后对 `cil_to_netdev` 运行:

```text
sudo -n micro/build/runner/micro_exec run-kernel \
  --program corpus/bcf/cilium/clang-21_-O1_bpf_host.o \
  --program-name cil_to_netdev \
  --compile-only
```

在 maps 已经 pin 并复用的 steady-state 情况下，返回:

- `compile_ns = 26,398,902`，约 26.4 ms
- `phases_ns.object_load_ns = 24,381,784`，约 24.4 ms
- `xlated_prog_len = 29,488 bytes`
- `jited_prog_len = 17,990 bytes`

这不是 verifier-only 时间，而是当前 harness 下的 end-to-end compile-only/load 时间。但它足以说明量级:

- 这是毫秒级
- 不是几十微秒级

而 repo 现有文档里，当前 recompile-only 路径的开销被总结为 “8ms scanner + 30us syscall in real programs”，见 `docs/tmp/2026-03-13/code-review-perf-issues.md:117`。

所以把架构从:

```text
scanner -> BPF_PROG_JIT_RECOMPILE
```

换成:

```text
read live prog -> rewrite -> BPF_PROG_LOAD -> replace
```

性能上至少要接受一个根本变化:

- recompile-only 的 kernel apply 路径是十微秒量级
- 重新 load 一个大程序在本机实测是二十多毫秒量级

### 5.4 “Cilium 7000+ insns verify 时间是多少”

从当前本地 corpus 和 loader harness 看，Cilium datapath 是拆成多个入口程序和 tail programs 的；我在这份本地对象里没有拿到一个单次 load 就超过 7000 insns 的 attachable program。

当前能直接确认的是:

- attachable `cil_to_netdev` 为 3638 insns
- 内部 tail program 最大约 3996 insns

因此在这棵树和这套 harness 下，我没有得到一个“7000+ insns 单程序 verifier-only 时间”的直接测量值。

更准确的说法应该是:

1. 源码层面: verifier 时间没有固定常数，只能在 load 时通过 `BPF_LOG_STATS` 实测。
2. 本地实测层面: 一个 3638-insn 的真实 Cilium `sched_cls` 入口程序，steady-state end-to-end load 约 26.4 ms。
3. 经验层面: verifier 开销高度依赖 CFG、状态爆炸、循环、helper/kfunc/ctx fixup 形态，不能只按 insn count 线性估算。

补充参考: 本仓的 `docs/reference/papers/70-fosdem-2025-performance-evaluation-of-ebpf-verifier.pdf` 也展示了 verifier 随程序结构上升并可在病态情况下到秒级，但那是补充文献，不是当前内核源码中的固定保证。

## 6. 已有实践: Cilium 是怎么做热替换的

### 6.1 Cilium 的核心策略不是“读 live xlated 再改写”

Cilium 的现代升级路径本质上是:

1. 从 ELF/CollectionSpec 重新加载新程序
2. 复用 pinned maps
3. 对支持 bpf_link 的路径，用 pinned link 做 `link.Update()`
4. 对 legacy tc 等路径，走子系统原生 replace

它不是:

```text
读 live xlated_prog_insns
-> 改 bytecode
-> 直接回写
```

### 6.2 map 复用

`LoadCollection()` 的注释直接说明:

- pinned maps 会从 `opts.Maps.PinPath` 自动加载并复用
- 某些 pin 替换必须在程序 attach 之后再 commit
- 如果先 attach 不完整 entrypoints 就 commit，可能出现 missing tail calls

见 `/tmp/cilium-src-191417/pkg/bpf/collection.go:176-297`。

另外 `commitMapPins()` 的注释也明确说 map pin replacement 要在 programs attach 完成后做，见 `/tmp/cilium-src-191417/pkg/bpf/pinning.go:123-141`。

### 6.3 link update

Cilium 自己封装了 `UpdateLink()`:

- `/tmp/cilium-src-191417/pkg/bpf/link.go:13-30`

它就是:

```text
load pinned link
-> l.Update(prog)
```

XDP 路径:

- `/tmp/cilium-src-191417/pkg/datapath/loader/xdp.go:298-372`

逻辑是:

- 先尝试更新已有 pinned link
- 如果 link defunct，删 pin 后重建
- 如果不存在，就创建并 pin 一个新 link

### 6.4 cgroup 路径

Cilium 在 cgroup socketlb 代码的头部注释写得非常直白:

- fresh install 优先用 `bpf_link`
- 升级时 `link.Update()` 可以 atomically replace 当前 program
- 但从旧 `PROG_ATTACH` 升级时，仍继续用 `PROG_ATTACH`，避免中断

见 `/tmp/cilium-src-191417/pkg/socketlb/cgroup.go:4-20`。

具体代码先尝试 `UpdateLink()`，失败再 attach 新 link 或 fallback 到 `PROG_ATTACH`:

- `/tmp/cilium-src-191417/pkg/socketlb/cgroup.go:69-165`

### 6.5 legacy tc 路径

Cilium 的 legacy tc 不是用 `bpf_link_update()`，而是:

- `netlink.FilterReplace(filter)`

见 `/tmp/cilium-src-191417/pkg/datapath/loader/tc.go:113-157`。

这和内核 `cls_bpf_change()` 的 RCU replace 语义是一致的。

### 6.6 对 daemon 架构的启示

Cilium 的实践说明了一件很重要的事:

- 工业级系统会保存原始 load-time 元数据，并用它管理升级
- 它们不会假设“live xlated dump 足以作为重建和热替换的唯一真相源”

## 7. 最终判断

### 7.1 这个 daemon 链路在哪些场景可行

可行的前提是同时满足:

1. daemon 管理的是自己已知的程序，而不是任意第三方 live program
2. daemon 保存了原始 load-time 元数据:
   - program type / expected attach type
   - attach family
   - link pin/path 或子系统 attach handle
   - map schema / map pin/path
   - global-data schema
   - 可选的原始 ELF/BTF/spec
3. attach 家族支持:
   - `bpf_link_update()`，或者
   - 子系统原生 replace

在这些条件下，可以做出一个可靠的“load new + atomic switch”系统。

### 7.2 哪些场景不可行或不应承诺

下面这些不应承诺为通用能力:

1. 对任意 live program，仅靠 `prog_id + xlated_prog_insns` 无损重建新程序。
2. 对任意 attach 家族统一使用 `bpf_link_update()` 原子替换。
3. 在不重新 verifier/JIT 的前提下提交一个新 program。
4. 在改变 global-data 语义时，仍自动复用旧 `.rodata/.data/.bss/.kconfig` map。

### 7.3 建议的架构边界

如果要做 daemon 方案，建议边界明确设成:

```text
daemon owns the lifecycle
```

具体建议:

1. live introspection 只用于:
   - 发现对象
   - 做运行时分析
   - 做诊断/恢复

2. 真正的升级元数据来源应是 daemon 自己维护的 registry，而不是 live dump。

3. 支持范围应明确限定为:
   - XDP link
   - cgroup link / cgroup attach
   - tcx
   - sockmap/sockhash
   - netns
   - iter
   - legacy tc 如果愿意实现其专有 replace 路径

4. tracing/raw_tp/perf/kprobe_multi/uprobe_multi/netfilter 等路径，不应默认纳入“可原子热替换”承诺。

## 8. 一句话结论

一个 privileged daemon 可以完成“读取 live BPF -> 分析/重写 -> 加载新程序 -> 在受支持 attach 家族上原子替换”的受控闭环；但它不能把这件事做成对任意 live BPF program 普适成立的通用机制。最大的硬障碍是 `xlated_prog_insns` 不是原始程序、attach 元数据不完整、update 机制只覆盖 attach 家族子集，以及每次 `BPF_PROG_LOAD` 都必须重新 verifier + JIT。
