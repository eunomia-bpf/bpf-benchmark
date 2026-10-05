# Userspace speculative re-optimization design

> **历史迁移分析（2026-07-10 标记）**：本文写于 daemon→userspace shim
> 迁移之前,其中 `daemon/src/*`、fork-only syscall 和 runner 限制描述仅解释
> 当时的设计选择。当前实现已采用 `bpfopt/shim/` 的 load-time plan 与
> running-process reload/reattach;以 `bpfopt/shim/README.md` 为准。

本文评估把当前 in-place `BPF_PROG_REJIT` 路径改成纯 userspace speculative re-optimization:

1. daemon 在程序加载时捕获原始 bytecode 和 load 属性。
2. daemon 对原始 bytecode 跑 `bpfopt` pass。
3. daemon 用 stock `BPF_PROG_LOAD` 加载 candidate。
4. daemon 通过 stock attach/swap 机制把流量从 old prog 切到 candidate。

结论先行:

- 原始 bytecode 必须在 `BPF_PROG_LOAD` verifier 之前捕获。加载完成后，标准 `BPF_OBJ_GET_INFO_BY_FD` 只给 verifier/JIT 之后的 `xlated_prog_insns`，stock UAPI 没有 `orig_prog_insns` 字段；当前 daemon 依赖 fork-only `BpfProgInfoFork.orig_prog_len/orig_prog_insns`。
- candidate 切流不是一个统一替代 REJIT 的 API。`BPF_LINK_UPDATE` 只覆盖带 `update_prog`/`update_map` 的 link；当前 kernel 里的 perf-event/kprobe/tracepoint/raw_tracepoint/tracing/LSM link ops 没有 `update_prog`，这些正好覆盖 tracing/security/profiling app 的大多数程序。
- map state 可以保留，前提是 candidate load 使用原程序的同一批 map fd。当前 UAPI 的 `BPF_PROG_LOAD` 也有 `fd_array/fd_array_cnt`，所以可以沿用 canonical map index 方案；旧内核才需要 fallback 到 `BPF_PSEUDO_MAP_FD` immediate。
- benchmark runner 不能在完全不改的情况下得到正确 post-ReJIT 计数。userspace swap 产生新 prog id；当前 runner 仍按旧 prog id 采样，且 refresh 逻辑明确拒绝 tracked id 变化。

## 1. 原始 bytecode 获取

### 当前 daemon 没有 load-event watcher

当前 daemon 不是通过 tracepoint/kprobe 监听 `BPF_PROG_LOAD`。它只暴露固定 Unix socket `/var/tmp/bpfrejit-daemon.sock`，处理 runner 发来的 `execute_plan` 请求:

- daemon 入口固定 socket: `daemon/src/main.rs:15-24`。
- server 只分发 `"execute_plan"`: `daemon/src/server.rs:251-269`。
- `execute_plan` 的每个 program 通过 runner 传入的 `prog_id` 做 on-demand snapshot: `daemon/src/commands.rs:511-519`。
- snapshot 路径打开 prog fd 后调用 fork-only original-bytecode 读取: `daemon/src/bpf.rs:71-86`。

runner 侧的“watcher”也不是 kernel load hook，而是应用启动前后轮询 `bpftool prog show` 的差集:

- generic process runner 在启动前保存 `before_ids`，健康检查只要求出现新 BPF programs: `runner/libs/app_runners/process_support.py:202-260`。
- `programs_after()` 从 `bpftool_prog_show_records()` 过滤 `before_ids`: `runner/libs/app_runners/process_support.py:18-27`。
- `wait_until_program_set_stable()` 持续轮询直到 program id 集合稳定: `runner/libs/app_runners/process_support.py:54-106`。

因此，userspace path 需要新增一个真正的 load-event capture 组件；现有 daemon/src 没有这个模块。

### 为什么 prog fd 取不到原始 bytecode

stock UAPI 的 `struct bpf_prog_info` 只有 `xlated_prog_len/xlated_prog_insns`，没有 `orig_prog_len/orig_prog_insns`: `vendor/libbpf/include/uapi/linux/bpf.h:6659-6699`。内核 `BPF_OBJ_GET_INFO_BY_FD` 填的是当前 `prog` 的 xlated 指令:

- map ids 来自 `prog->aux->used_maps`: `vendor/linux-framework/kernel/bpf/syscall.c:5024-5039`。
- `info.xlated_prog_len = bpf_prog_insn_size(prog)`: `vendor/linux-framework/kernel/bpf/syscall.c:5065-5067`。
- 指令通过 `bpf_insn_prepare_dump(prog, file->f_cred)` 拷给用户: `vendor/linux-framework/kernel/bpf/syscall.c:5071-5078`。

verifier 会在 load 流程中修改指令流。证据:

- `bpf_prog_load()` 先从用户态把 insns 拷到 `prog->insns`: `vendor/linux-framework/kernel/bpf/syscall.c:3019-3022`。
- 随后调用 `security_bpf_prog_load()`，再进入 `bpf_check()`: `vendor/linux-framework/kernel/bpf/syscall.c:3084-3090`。
- verifier 后半段明确标注 “instruction rewrites happen after this point”，然后执行 dead-code rewrite、ctx access conversion 和 misc fixups: `vendor/linux-framework/kernel/bpf/verifier.c:26481-26502`。
- `convert_ctx_accesses()` 会插入 prologue/nospec/ctx rewrite 指令并调用 `bpf_patch_insn_data()`: `vendor/linux-framework/kernel/bpf/verifier.c:22815-22904`。
- `do_misc_fixups()` 是“post-verification rewrites”，会 patch helper、ALU、kop 等: `vendor/linux-framework/kernel/bpf/verifier.c:23703-23810`。
- `bpf_patch_insn_data()` 和 `verifier_remove_insns()` 会真正替换/删除指令并维护 aux data: `vendor/linux-framework/kernel/bpf/verifier.c:22347-22377`, `vendor/linux-framework/kernel/bpf/verifier.c:22558-22587`。

当前 daemon 通过自定义布局绕过这个限制:

- `BpfProgInfoFork` 注释写明 upstream libbpf 没有 fork-only original fields: `daemon/src/syscall.rs:37-41`。
- 该 struct 增加 `orig_prog_len` 和 `orig_prog_insns`: `daemon/src/syscall.rs:44-84`。
- `prog_get_original()` 先读 `orig_prog_len`，再用 `BPF_OBJ_GET_INFO_BY_FD` 填充 `orig_prog_insns`: `daemon/src/syscall.rs:481-526`。
- layout test 固定 `orig_prog_len`/`orig_prog_insns` offset: `daemon/src/syscall.rs:620-631`。

去掉 fork patch 后，依赖 `prog_fd + BPF_OBJ_GET_INFO_BY_FD` 只能得到 verifier rewrite 之后的 bytecode，不能作为 `bpfopt` 的原始输入。

### 可选 hook 点

| Hook | 捕获时机 | 证据 | 评价 |
| --- | --- | --- | --- |
| `raw_syscalls:sys_enter` tracepoint | `__sys_bpf()` 之前，只能看到 syscall args，包括 `cmd/uattr/size` | raw syscall tracepoint 记录 syscall id 和 6 个 args: `vendor/linux-framework/include/trace/events/syscalls.h:18-35`; `__sys_bpf()` 随后才 copy `union bpf_attr`: `vendor/linux-framework/kernel/bpf/syscall.c:6199-6205` | 覆盖所有进程、stock kernel 可用。但读取的是用户地址，存在 TOCTOU；大程序需要 chunk/ringbuf 协议；还必须复制 license、func_info、line_info、BTF、attach attrs 等 load metadata。 |
| fentry/ftrace/kprobe on `bpf_prog_load()` | `copy_from_bpfptr(prog->insns, attr->insns, ...)` 之后、`bpf_check()` 之前 | copy 发生在 `vendor/linux-framework/kernel/bpf/syscall.c:3019-3022`，verifier 在 `3088-3090` | 比 raw syscall 少 TOCTOU，可以读 kernel `prog->insns`。需要 BTF/fentry 或 kallsyms/kprobe 可用；`bpf_prog_load` 是 static 函数，部署可移植性弱于 raw syscall/LSM。 |
| BPF LSM `bpf_prog_load` | `security_bpf_prog_load(prog, attr, ...)`，在 verifier 前 | LSM hook signature 含 `struct bpf_prog *prog, union bpf_attr *attr`: `vendor/linux-framework/include/linux/lsm_hook_defs.h:431-438`; hook 在 `bpf_check()` 之前调用: `vendor/linux-framework/kernel/bpf/syscall.c:3084-3090`; BPF LSM sleepable set 包含 `bpf_lsm_bpf_prog_load`: `vendor/linux-framework/kernel/bpf/bpf_lsm.c:285-295` | 最适合作为 production capture: 已有 kernel-side `prog->insns`，不需要从用户地址竞态读取。限制是需要启用 BPF LSM/BTF，且 eBPF 程序向用户态导出大 bytecode 仍要设计 chunk/ringbuf 协议。 |
| `bpf_prog__attach` uprobe/LD_PRELOAD | 用户库 attach 阶段，不是 kernel load 阶段 | 本 repo 没有依赖该 hook；7 个 app 通过 upstream binary 启动并用 bpftool delta 发现程序: `runner/libs/app_runners/process_support.py:336-355` | 只能覆盖使用 libbpf 且被 instrumentation 命中的进程；BCC、bpftrace、Go/libbpfgo、cilium/tracee/tetragon 不能假定都经过同一个 `bpf_prog__attach`。不能作为跨进程全局方案。 |
| bpftrace 脚本 | 可原型化 kprobe/raw syscall 采集 | bpftrace corpus 自己就是 app runner，直接启动 upstream script 集合: `runner/libs/app_runners/bpftrace_set.py:68-92` | 适合调试，不适合 daemon 数据面：输出/二进制 framing、buffer backpressure、large bytecode 都不可控。 |

### 必须放弃优化的场景

daemon 必须 fail-fast 放弃该 program 的 userspace optimization，而不是用 xlated bytecode 冒充原始 bytecode:

- daemon 启动晚于目标 app，错过 `BPF_PROG_LOAD` capture。
- hook 丢事件、ringbuf 溢出、bytecode chunk 不完整、或 load metadata 不完整。
- 无法捕获/重建 `BPF_PROG_LOAD` 必需属性: `prog_type`, `expected_attach_type`, `prog_flags`, `license`, `kern_version`, `prog_ifindex`, `attach_btf_id`, `attach_btf_obj_fd`, `attach_prog_fd`, BTF/func_info/line_info/core relo 相关信息。`bpf_prog_load()` 会检查 attach type 和 attach target: `vendor/linux-framework/kernel/bpf/syscall.c:2946-2989`。
- 原程序是 freplace/tracing/LSM 等需要 target prog/BTF 上下文的程序，但原 target fd/BTF id 不能重建。
- map pseudo references 不能映射回同一批 map fd。

## 2. 原子切换替代 REJIT

### Stock swap primitives

`BPF_LINK_UPDATE` 的 UAPI 描述是“把指定 link_fd 的程序更新为 new_prog_fd”: `vendor/libbpf/include/uapi/linux/bpf.h:799-802`，attr 包含 `link_fd/new_prog_fd/flags/old_prog_fd`: `vendor/libbpf/include/uapi/linux/bpf.h:1867-1885`。内核实现只在 link ops 提供 `update_prog` 时工作，否则返回 `-EINVAL`: `vendor/linux-framework/kernel/bpf/syscall.c:5816-5860`。

这意味着不能把 `bpf_link_update` 当成所有 attach type 的通用 REJIT 替代。

| Attach / prog class | Stock swap 机制 | Atomic / race | 当前证据和限制 |
| --- | --- | --- | --- |
| `kprobe`, `kretprobe`, `tracepoint` via perf_event | 如果是 legacy perf event fd，理论上可用 `PERF_EVENT_IOC_SET_BPF` 重新设置；如果是 `BPF_LINK_TYPE_PERF_EVENT`，当前 kernel link ops 没有 `update_prog` | 无通用 atomic swap。需要 perf event fd 或 app/link ownership；daemon 从 prog id 不能拿到这些 fd | `bpf_perf_link_lops` 只有 release/dealloc/fill_info/show_fdinfo，没有 update: `vendor/linux-framework/kernel/bpf/syscall.c:4164-4169`; ioctl attach 路径是 `PERF_EVENT_IOC_SET_BPF`: `vendor/linux-framework/kernel/events/core.c:6657-6666`, 验证/attach 在 `11621-11665`。 |
| `perf_event` program type | 同上，perf event fd ioctl 或 perf link | 无通用 atomic swap | OTel 主要是 `perf_event` progs: result file `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/otelcol-ebpf-profiler__profiling.json:12-111`。 |
| `raw_tracepoint` | `BPF_RAW_TRACEPOINT_OPEN` / raw_tp link 重新 attach | 无 `BPF_LINK_UPDATE` | raw_tp link ops 无 update: `vendor/linux-framework/kernel/bpf/syscall.c:3850-3855`; attach 创建 raw_tp link: `vendor/linux-framework/kernel/bpf/syscall.c:4223-4287`。 |
| `tracing`, `fentry/fexit`, `LSM`, `freplace/ext` | tracing link 重新 attach | 无 `BPF_LINK_UPDATE` | tracing link ops 无 update: `vendor/linux-framework/kernel/bpf/syscall.c:3559-3564`; link_create 对 EXT/TRACING/LSM 走 tracing/raw_tp attach: `vendor/linux-framework/kernel/bpf/syscall.c:5711-5727`。 |
| XDP link (`BPF_LINK_TYPE_XDP`) | `BPF_LINK_UPDATE` | 是。内核检查 old prog/type/attach type，安装后 `xchg(&link->prog, new_prog)` | `bpf_xdp_link_update()` 检查并 `dev_xdp_install()`，再 xchg: `vendor/linux-framework/net/core/dev.c:10599-10642`; ops 暴露 update: `vendor/linux-framework/net/core/dev.c:10649-10655`。 |
| legacy XDP netlink attach | netlink `XDP_FLAGS_REPLACE` + expected old fd | 是，RTNL 下检查 active prog 是否等于 expected old prog；无 detach window | flags 定义: `vendor/libbpf/include/uapi/linux/if_link.h:1886-1895`; `dev_xdp_attach()` 检查 `XDP_FLAGS_REPLACE` 和 `cur_prog != old_prog`: `vendor/linux-framework/net/core/dev.c:10418-10448`; `dev_change_xdp_fd()` 传入 expected old fd: `vendor/linux-framework/net/core/dev.c:10742-10752`。当前 katran runner 使用 detach 再 attach，不是 atomic: `runner/libs/app_runners/katran.py:122-138`。 |
| TCX (`sched_cls` as BPF link) | `BPF_LINK_UPDATE` on TCX link | 是，RTNL + `bpf_mprog_attach(... BPF_F_REPLACE | BPF_F_ID ...)` + commit | TCX update: `vendor/linux-framework/kernel/bpf/tcx.c:203-239`; ops update: `vendor/linux-framework/kernel/bpf/tcx.c:289-295`。 |
| legacy TC cls_bpf | netlink `tc filter replace` with same chain/prio/handle/direct-action | Per filter replacement under rtnl, but daemon must reconstruct filter identity; not covered by `bpf_link_update` | `link_create()` only covers TCX/netkit link for `BPF_PROG_TYPE_SCHED_CLS`: `vendor/linux-framework/kernel/bpf/syscall.c:5750-5755`; Cilium keeps TC/XDP datapath attached after userspace pause, implying interface-scoped legacy attachments: `runner/libs/app_runners/cilium.py:549-557`, `runner/libs/app_runners/cilium.py:614-618`。 |
| cgroup / sockops | cgroup `BPF_LINK_UPDATE` if link-backed; legacy `BPF_PROG_ATTACH` with `BPF_F_REPLACE` if target cgroup fd and attach flags known | link-backed path is atomic under cgroup lock; legacy path requires reconstructing cgroup fd/attach type | cgroup link update xchg + effective prog propagation: `vendor/linux-framework/kernel/bpf/cgroup.c:967-1032`; ops update: `vendor/linux-framework/kernel/bpf/cgroup.c:1461-1468`; legacy attach replace reads `replace_bpf_fd`: `vendor/linux-framework/kernel/bpf/cgroup.c:1325-1350`。 |
| `sk_msg`, `sk_skb` sockmap/sockhash | `BPF_LINK_UPDATE` if link-backed sockmap link | Atomic under sockmap mutex if link matches map slot | sockmap link update checks type/attach type and xchg link prog: `vendor/linux-framework/net/core/sock_map.c:1746-1797`; ops update: `vendor/linux-framework/net/core/sock_map.c:1833-1840`。 |
| struct_ops | `BPF_LINK_UPDATE` map-update path, not prog-update path | Atomic at struct_ops link/map level, but candidate is a new struct_ops map; stateful and app-specific | `link_update()` dispatches to `update_map` if present: `vendor/linux-framework/kernel/bpf/syscall.c:5785-5811`; struct_ops update function: `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1260-1270`。scx 已排除；当前 7-app corpus 没有 struct_ops。 |
| `PROG_ARRAY` tail-call target | `BPF_MAP_UPDATE_ELEM` on same prog_array key with candidate fd | Atomic per map slot via `xchg`; JIT tail-call poke descriptors updated under mutex | syscall special-cases `BPF_MAP_TYPE_PROG_ARRAY`: `vendor/linux-framework/kernel/bpf/syscall.c:252-267`; update path does `xchg` and `map_poke_run`: `vendor/linux-framework/kernel/bpf/arraymap.c:900-929`; JIT poke update scans tail-call descriptors: `vendor/linux-framework/kernel/bpf/arraymap.c:1107-1152`; helper semantics are jump/no-return: `vendor/libbpf/include/uapi/linux/bpf.h:2166-2174`。 |
| netns flow dissector / sk_lookup | `BPF_LINK_UPDATE` if link-backed | Atomic under netns mutex | netns link update updates run_array and xchg link prog: `vendor/linux-framework/kernel/bpf/net_namespace.c:163-201`; ops update: `vendor/linux-framework/kernel/bpf/net_namespace.c:235-240`。Not observed in current 7-app result set。 |
| netfilter | link exists but update returns `-EOPNOTSUPP` | Not swappable via link_update | `bpf_nf_link_update()` returns `-EOPNOTSUPP`: `vendor/linux-framework/net/netfilter/nf_bpf_link.c:165-178`。Not observed in corpus。 |

### 7-app corpus matrix

Observed type distribution from `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/*.json`:

| App | Observed BPF prog types | Likely attach / current runner evidence | Userspace swap assessment |
| --- | --- | --- | --- |
| `tracee/monitor` | `raw_tracepoint`, `kprobe`, `cgroup_skb`, `lsm` | runner starts upstream Tracee with `--events *`: `runner/libs/app_runners/tracee.py:204-208`; result includes `cgroup_skb_ingress`, `cgroup_skb_egress`, `lsm_file_open_test`: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/tracee__monitor.json:1359-1416` | kprobe/raw_tp/LSM are not generally swappable because perf/raw_tp/tracing links lack update. `cgroup_skb` can be swapped only if daemon can discover link or cgroup fd/attach type. |
| `tetragon/observer` | `kprobe`, `tracepoint`, `raw_tracepoint`, `socket_filter` | Tetragon loads policies from `runner/assets/tetragon_policies`: kprobe examples at `security-socket-connect.yaml:6-13`, raw/tracepoint examples at `raw_syscalls.yaml:6-12` and `rawtp.yaml:6-12`; result has many `generic_kprobe_event`: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/tetragon__observer.json:99-180` | kprobe/tracepoint/raw_tp are not generally atomic-swappable. `socket_filter` has no obvious external attach swap from prog id alone; likely known limitation unless app exposes socket fd/link. |
| `bpftrace/set` | `perf_event`, `kprobe`, `tracepoint` | scripts explicitly use kprobe/tracepoint: `capable.bt:72-74`, `vfsstat.bt:33-38`, `runqlat.bt:44-52`, `biosnoop.bt:33-41`; runner starts upstream bpftrace scripts: `runner/libs/app_runners/bpftrace_set.py:24-30`, `68-92` | Mostly perf/kprobe/tracepoint. No generic atomic swap; would need ownership of bpftrace-created perf fds or a detach/attach window. |
| `bcc/set` | `tracepoint`, `tracing`, `raw_tracepoint`, `kprobe` | runner starts upstream BCC tools: `runner/libs/app_runners/bcc_set.py:34-43`, `85-109`; result type sample: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/bcc__set.json:12-192` | Same limitation as bpftrace plus tracing link limitation. |
| `katran` | `xdp` | upstream `katran_server_grpc` attaches XDP; runner rebinds to generic XDP by detach+attach: `runner/libs/app_runners/katran.py:524-573`, `631-633`, `731-777`; result `balancer_ingress` is XDP: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/katran.json:9-12` | Best fit. Replace current runner helper with atomic legacy XDP `XDP_FLAGS_REPLACE` or move to XDP link + `BPF_LINK_UPDATE`. |
| `cilium/agent` | `sched_cls`, `xdp`, `tracing` | runner enables XDP and datapath features: `runner/libs/app_runners/cilium.py:312-322`; it freezes userspace while TC/XDP programs and pinned maps stay resident: `runner/libs/app_runners/cilium.py:549-557`; result shows `cil_xdp_entry` and many TC/tail programs: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/cilium__agent.json:23-80` | XDP entry can be swapped atomically if attach info reconstructed. TC depends on whether Cilium used TCX/link or legacy tc filters; current runner comments point to interface-scoped legacy TC, so daemon must reconstruct netlink filter replace. Tracing helper programs not swappable. Tail targets can be swapped via prog_array only if map/key discovered. |
| `otelcol-ebpf-profiler/profiling` | `perf_event`, `tracepoint` | runner config enables profiler tracers and notes tail-called `perf_unwind_*` have zero run_cnt: `runner/libs/app_runners/otel_profiler.py:13-30`, `33-62`; result shows `perf_unwind_*` and `native_tracer_entry`: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/otelcol-ebpf-profiler__profiling.json:9-117` | Direct entry is perf_event/tracepoint, no generic atomic swap. Tail target replacement via PROG_ARRAY may be possible but measurement appears at caller and requires map/key discovery. |

### 不可 detach / 不可 swap 的 known limitations

这些必须在 paper 中明确列为 coverage limits:

- perf-event backed kprobe/kretprobe/tracepoint/perf_event programs, unless daemon owns the perf fd or app provides a link/fd handoff。当前 perf link ops 没有 `update_prog`: `vendor/linux-framework/kernel/bpf/syscall.c:4164-4169`。
- raw_tracepoint links，当前 raw_tp link ops 没有 `update_prog`: `vendor/linux-framework/kernel/bpf/syscall.c:3850-3855`。
- tracing/LSM/fentry/fexit/freplace links，当前 tracing link ops 没有 `update_prog`: `vendor/linux-framework/kernel/bpf/syscall.c:3559-3564`。
- legacy TC cls_bpf: 可以做 netlink replace，但不是从 prog id 自动推出；必须知道 iface、direction、chain/prio/handle、direct-action 等 filter identity。
- unattached programs / library helper programs / freplace target fd 不可重建的程序。
- struct_ops 不在 7-app corpus；即便使用 struct_ops link update，也更新的是 struct_ops map，不是单个 prog fd。

## 3. Map state preservation

目标是 candidate 引用原程序同一批 kernel map object，而不是 clone 或重新创建 map。

当前 daemon 已经有一半所需 plumbing:

- `snapshot_program()` 读取 program info 和 map ids: `daemon/src/bpf.rs:71-86`。
- `get_prog_info_with_map_ids_from_fd()` 通过 `BPF_OBJ_GET_INFO_BY_FD` 读取 `nr_map_ids/map_ids`: `daemon/src/bpf.rs:146-154`。
- syscall helper 二次读取 map ids: `daemon/src/syscall.rs:257-277`。
- `build_rejit_fd_array()` 注释说明 fd_array 前缀按 `prog_info.map_ids` 顺序放 map fds，匹配 canonical `PSEUDO_MAP_IDX`: `daemon/src/commands.rs:1236-1257`。
- 构造时确实按 `map_ids` 打开并 append 原 map fd: `daemon/src/commands.rs:1334-1340`。

userspace `BPF_PROG_LOAD` 的 map/BTF side input:

- 当前 REJIT syscall 接受 `fd_array`，所以 `bpfopt --canonicalize-map-refs` 可以把 map references 改成 `BPF_PSEUDO_MAP_IDX`: `bpfopt/crates/bpfopt/src/main.rs:124-132`。
- 当前 `vendor/libbpf` 和 `vendor/linux-framework` UAPI 的 `BPF_PROG_LOAD` 都有 `fd_array`/`fd_array_cnt`: `vendor/libbpf/include/uapi/linux/bpf.h:1618-1639`, `vendor/linux-framework/include/uapi/linux/bpf.h:1627-1648`。
- verifier load path 会处理 `fd_array`，并把其中 map/BTF fd 预加入 verifier env: `vendor/linux-framework/kernel/bpf/verifier.c:25819-25878`, `26360-26370`。
- 因此 candidate load 可以复用当前 `PSEUDO_MAP_IDX` + fd_array 顺序，不必强制还原成 `BPF_PSEUDO_MAP_FD`。不过如果目标 kernel 没有 `fd_array_cnt`，才需要在 candidate load 前把 canonical map index 还原成 stock loader 接受的 `BPF_PSEUDO_MAP_FD`/`BPF_PSEUDO_MAP_VALUE`，把 `imm` 填为同一 map object 的 fd。`bpfopt` 里 canonical tags 定义在 `bpfopt/crates/bpfopt/src/insn.rs:58-66`。

map state 保留规则:

- `BPF_MAP_TYPE_HASH`, `ARRAY`, `PERCPU_ARRAY`, `LRU_HASH`, `LPM_TRIE`, ringbuf/perf event array、sockmap 等 map object 的内容保留，前提是 candidate 使用同一个 map fd。
- `PROG_ARRAY` 本身也应保留为同一个 map；如果优化 tail-call target，只更新该 prog_array 的 value slot 为 candidate prog fd，不创建新 prog_array。`BPF_MAP_UPDATE_ELEM` 对 prog array 的 special path 在 `vendor/linux-framework/kernel/bpf/syscall.c:252-267`。
- map-in-map 的 outer map 也必须复用同一 outer map；inner map id/value snapshot 只能作为 side input，不能替换 map object。
- `map_inline` 目前只对一部分 map type 做 value snapshot: `daemon/src/commands.rs:1216-1227`。这是优化 side input 限制，不是 state-preservation 限制；切流时所有 referenced maps 都应复用原 object。

## 4. 当前 daemon 代码改动估算

### 直接依赖 fork-only REJIT/original 的 callsites

`daemon/src/syscall.rs`:

- fork-only command constant and attr: `BPF_PROG_REJIT = 39`, `AttrRejit`: `daemon/src/syscall.rs:15-35`。
- fork-extended `BpfProgInfoFork` with `orig_prog_len/orig_prog_insns`: `daemon/src/syscall.rs:37-86`。
- `prog_rejit()` / `prog_rejit_once()` call `sys_bpf(BPF_PROG_REJIT, ...)`: `daemon/src/syscall.rs:348-390`, `445-469`。
- `prog_get_original()`: `daemon/src/syscall.rs:481-526`。

`daemon/src/bpf.rs`:

- `snapshot_program()` calls `syscall::prog_get_original()`: `daemon/src/bpf.rs:71-78`。
- `ProgramInfo::from_info()` prefers `orig_prog_len` over `xlated_prog_len`: `daemon/src/bpf.rs:125-143`。

`daemon/src/commands.rs`:

- `rejit_program()` opens old prog id and calls `syscall::prog_rejit()`: `daemon/src/commands.rs:204-229`。
- main pass loop calls `rejit_program()` after every successful bytecode-producing pass: `daemon/src/commands.rs:780-789`。
- pass detail records `rejit_syscall_ms`: `daemon/src/commands.rs:185-202`。
- fd_array builder is explicitly for `BPF_PROG_REJIT`: `daemon/src/commands.rs:1236-1257`。

### Replacement design

Replace the current in-place function boundaries with:

1. `load_capture`: long-lived daemon component that captures `BPF_PROG_LOAD` before verifier, stores `{old_prog_id, tag/load_time/name, raw_insns, load_attr_subset, map_fd_refs, btf/line/func metadata}`. Initial implementation should prefer BPF LSM `bpf_prog_load`; raw syscall tracepoint can be fallback/prototype.
2. `snapshot_program(prog_id)` becomes lookup in capture cache plus live `BPF_OBJ_GET_INFO_BY_FD` for current map ids/stats, not `prog_get_original()`.
3. `candidate_load`: after each successful pass, call stock `BPF_PROG_LOAD` with the transformed bytecode and reconstructed original load attrs. This replaces `prog_rejit()` and verifier log collection. It must preserve verifier log handling because `map_inline` / `const_prop` consume previous successful verifier states (`runner/config/passes/map_inline/default.yaml:6`, `runner/config/passes/const_prop/default.yaml:6`).
4. `attach_swap`: classify old prog by current attachment/link/prog_array membership and perform one of: `BPF_LINK_UPDATE`, XDP netlink replace, TC netlink replace, cgroup replace, sockmap link update, prog_array map update, or fail unsupported.
5. response protocol either remains `per_program[old_id]` for runner compatibility or extends records with `candidate_prog_id`/`logical_prog_id`. The latter is needed for correct measurement; see section 5.

### Rough LOC delta

Current daemon is about 3.2 KLOC (`daemon/src/*.rs` = 3233 lines). Estimated changes:

| Area | Delete / shrink | Add |
| --- | ---: | ---: |
| Remove fork-only REJIT syscall attr, retry/log-buffer helpers, tests | -150 to -220 | 0 |
| Remove `prog_get_original` fork fields and `orig_prog_len` assumptions | -40 to -80 | 0 |
| Generalize `RejitFdArray` into candidate-load fd_array plus optional old-kernel MAP_FD fallback | -40 to -80 | +120 to +220 |
| Load-event capture cache and record format | 0 | +250 to +450 |
| Stock `BPF_PROG_LOAD` wrapper with verifier-log support | 0 | +150 to +250 |
| Attachment discovery/swap dispatcher | 0 | +400 to +800 |
| Protocol/result mapping glue | 0 | +80 to +150 |

Net estimate: delete roughly 230-380 LOC, add roughly 1.0-1.9 KLOC, for a net increase of about +750 to +1.6 KLOC. The deletion is smaller than the kernel patch removal; userspace complexity moves into attach discovery and id remapping.

## 5. Corpus + runner impact

### 当前 runner 如何触发 ReJIT

The runner starts the daemon, sends a socket JSON request, and then measures baseline/post phases:

- daemon socket path is fixed in runner: `runner/libs/rejit.py:259-283`。
- `_daemon_request()` sends newline-delimited JSON over Unix socket: `runner/libs/rejit.py:308-337`。
- `apply_daemon_rejit()` validates prog ids, builds `execute_plan`, sends request, returns daemon response: `runner/libs/rejit.py:340-390`。
- `build_execute_plan_payload()` sends `{cmd:"execute_plan", programs:[{prog_id, steps}], kop_probes}`: `runner/libs/rejit_plan.py:95-130`。
- corpus driver baseline samples old prog ids, applies daemon ReJIT, then post phase samples `result.state.prog_ids`: `corpus/driver.py:576-582`, `648-654`, `680-686`。

### 如果不改 runner，userspace swap 会破坏计数

当前 REJIT 是 in-place，所以 prog id 不变。userspace candidate load 必然产生新的 prog id。现有 runner 有两处会与此冲突:

- `_refresh_active_session_programs()` 如果发现 tracked prog ids 不在当前 bpftool 输出中，会尝试 rediscover；但如果 rediscovered ids 和 tracked ids 不完全相等，会直接 error: `corpus/driver.py:303-390`，尤其 `361-371`。
- `_measure_runner_phase()` 采样传入的 `prog_ids`，`sample_bpf_stats_from_records()` 要求所有 requested ids 都存在，否则 error: `runner/libs/bpf_stats.py:52-74`。
- 即使 old prog 保持 loaded 不报 missing，流量已切到 candidate 后 old prog 的 `run_cnt_delta/run_time_ns_delta` 会接近 0，post_rejit 数据也无效。delta 计算按 id 合并 before/after: `runner/libs/bpf_stats.py:83-101`。

因此:

- 若遵守“runner 不动”的迁移约束，new daemon 必须保持 socket 协议形状，但无法让现有 raw counter collection 自动变正确。它最多能把 candidate id 写入 daemon response，现有 corpus driver 不会用它采样。
- 要得到有效 benchmark，runner 至少需要支持 logical old_id -> active candidate_id 映射，并在 post_rejit phase 采样 candidate ids，同时 result.json 要保留 old_id/candidate_id 关系，避免把 baseline old id 和 post candidate id 当成同一 kernel object。
- 另一个选择是只优化 PROG_ARRAY tail targets，而直接 attached caller id 不变；但 savings 计入 caller，且 tail target 自身 run_cnt 仍为 0。这个只覆盖 tail-call 场景，不是 general REJIT 替代。

### 7-app result.json 收集影响

当前 result.json 的 `.baseline.bpf` / `.post_rejit.bpf` 是按 prog id 组织的 raw deltas。Cilium 的结果片段显示每个 record 带 `id/name/type/run_cnt_delta/run_time_ns_delta`: `corpus/results/x86_kvm_corpus_20260517_034332_255058/details/apps/cilium__agent.json:4-31`。

userspace swap 后需要新的 raw schema 或兼容映射:

- `baseline.bpf[old_id]` 保留 old prog raw counters。
- `post_rejit.bpf[candidate_id]` 记录 candidate raw counters。
- `rejit_result.per_program[old_id].candidate_prog_id = candidate_id` 或类似字段连接两者。
- 对 PROG_ARRAY tail target，`candidate_prog_id` 可能是 tail target，而 measured counter 仍应是 caller id；这要单独记录 `measured_prog_id`，否则外部分析会误读 tail target counters。

## 6. 限制和 paper 写作角度

### 覆盖不到或高风险的优化场景

- 原始 bytecode 捕获失败的 program: 必须 fail/skip。不能从 `xlated_prog_insns` 反推原始 bytecode。
- perf_event/kprobe/kretprobe/tracepoint/raw_tracepoint/tracing/LSM/freplace: 当前 stock link ops 大多不能 update，且 app-owned perf/link fd 不归 daemon。Tracee、Tetragon、bpftrace、BCC、OTel 的大多数程序在此类。
- legacy TC: 可通过 netlink replace，但需要 per-app/per-attach 还原 filter identity。Cilium 是主要受影响 app。
- tail-call target: `PROG_ARRAY` slot swap 是可行的，但必须发现 map/key；而性能计数应看 caller。现有文档已经说明 tail targets run_cnt 为 0，caller 包含 tail descendant 时间: `docs/evaluation.md:210-235`。
- struct_ops: scx 已排除；其他 7-app 不使用。struct_ops link update 是 map-level，不是单个 BPF program replacement。
- 无 attach 的 helper prog、unreachable prog、或 app 内部保留 fd 但没有 link/map/cgroup/socket attach metadata 的 prog 无法切流。

### 与 kop 的配合

当前 kop-class pass 不是“用普通 BPF 指令重写，然后 kernel JIT 自己识别”。它们显式输出 fork-only kop pseudo instructions:

- `bpfopt` 定义 `BPF_PSEUDO_KOP_SIDECAR = 3` 和 `BPF_PSEUDO_KOP_CALL = 4`: `bpfopt/crates/bpfopt/src/insn.rs:57-66`。
- `call_kop_with_off()` 生成 `src_reg = BPF_PSEUDO_KOP_CALL`，`imm = BTF func id`，`off = fd_array/BTF module slot`: `bpfopt/crates/bpfopt/src/insn.rs:453-469`。
- `kop_sidecar()` 生成紧邻 call 的 payload pseudo-insn: `bpfopt/crates/bpfopt/src/insn.rs:541-555`。
- `emit_packed_kop_call_with_off()` 固定输出 sidecar + call 两条指令: `bpfopt/crates/bpfopt/src/insn.rs:642-653`。
- `ProgramCFG::kop_emit()` 是所有 kop pass 的 helper，直接调用上述 emit: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:625-642`。
- rotate/cond_select/extract/endian_fusion/prefetch 等 pass 都声明 kop targets 并调用 `prog.kop_emit()`: `bpfopt/crates/bpfopt/src/passes/rotate.rs:5-26`, `cond_select.rs:11-37`, `extract.rs:5-21`, `endian.rs:5-50`, `prefetch.rs:12-23`。
- pass YAML 也要求 `--target ${TARGET}` 和 kop names: `runner/config/passes/rotate/default.yaml:5-12`, `cond_select/default.yaml:5-14`, `extract/default.yaml:5-10`, `endian_fusion/default.yaml:5-19`。

kernel-side kop support is a separate patch from REJIT:

- fork UAPI adds `BPF_PSEUDO_KOP_SIDECAR` and `BPF_PSEUDO_KOP_CALL`: `vendor/linux-framework/include/uapi/linux/bpf.h:1380-1393`; stock `vendor/libbpf/include/uapi/linux/bpf.h` has no such symbols (`rg BPF_PSEUDO_KOP` only hits `vendor/linux-framework`).
- verifier recognizes kop calls: `vendor/linux-framework/kernel/bpf/verifier.c:275-279`。
- verifier resolves kop BTF descriptors and rejects unregistered/incomplete koperation: `vendor/linux-framework/kernel/bpf/verifier.c:3440-3550`。
- verifier lowers proof regions before full check and restores them afterwards: `vendor/linux-framework/kernel/bpf/verifier.c:3707-3784`, `26392-26472`。
- non-JITed programs reject kop calls: `vendor/linux-framework/kernel/bpf/verifier.c:23430-23439`。
- x86/arm64 JITs inline native kop emit callbacks: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-602`, `2524-2535`; `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1201-1228`, `1638-1648`。

Implication:

- 如果“stock kernel”严格表示 upstream 无 kop patch，则 kop-class pass 不能用于 userspace candidate load；candidate 会含 stock kernel 不认识的 pseudo src_reg。
- 如果保留 kop patch（用户背景中的目标），`BPF_PROG_LOAD` 可以成为 kop candidate 的 verifier/JIT 入口，而且当前 UAPI/verifier 已经支持 load-time `fd_array`。当前 `call_kop_with_off()` 的注释把 `off` 定义为 load/REJIT `fd_array` slot: `bpfopt/crates/bpfopt/src/insn.rs:453-458`；verifier 中 kfunc/kinn offset > 0 会从 `env->fd_array` 读取 BTF fd: `vendor/linux-framework/kernel/bpf/verifier.c:3289-3294`。需要确认目标 stock+kop kernel 保留这套 load-time fd_array 语义；否则只能使用 vmlinux-resident kop 或把 kop modules 注册成 vmlinux-visible IDs。
- 非 kop bytecode rewriting pass（`wide_mem`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`, `branch_flip`）更适合 userspace path，因为它们输出普通 BPF bytecode。

### Paper 故事的收窄和卖点

原故事: “extensible kernel JIT framework”，靠 `BPF_PROG_REJIT` 对 live prog in-place 重写，prog id 和 attach 点不变。

userspace path 的新故事应改为:

- “userspace speculative reoptimizer for live eBPF”: candidate 必须先通过 stock `BPF_PROG_LOAD` verifier；失败只记录错误，不影响 live traffic。
- “minimal kernel surface”: 去掉 `BPF_PROG_REJIT`、`orig_prog_insns` 暴露和相关 kernel syscall patch；可选保留小型 kop JIT emit patch。
- “state-preserving replacement”: candidate 复用原 map object，保留 app state；切流通过 kernel 已有 attach/link/map update primitive。
- “attachment-aware, not universal”: paper 必须诚实说明 replacement coverage 受 attach type 限制。网络类 XDP/TCX/PROG_ARRAY 最强；perf/tracing/security 类目前主要是 limitation。
- “measurement impact is first-class”: 因为 candidate 有新 prog id，benchmark framework/analysis 必须处理 logical id mapping；这不是实现细节，而是 methodology change。

建议 paper 表述:

> We remove the invasive in-place ReJIT syscall and move speculation to userspace. The daemon captures original bytecode at load time, verifies each optimized candidate with the unmodified BPF verifier via `BPF_PROG_LOAD`, and switches traffic using existing kernel attachment replacement APIs when the attach class supports atomic replacement. This trades universal in-place transparency for a much smaller kernel interface and a clear attachment-coverage boundary.
