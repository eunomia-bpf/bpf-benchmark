# bpftool 替代 `micro_exec` 可行性调研

日期：2026-03-29

## TL;DR

结论先说：

- `bpftool` 可以覆盖当前 `micro_exec test-run` 的一大块核心能力：`loadall`、`prog run`、`prog show`、`map update/dump`、JIT/xlated dump、读取 `run_cnt/run_time_ns`。
- 但如果要求“**纯 bpftool 命令行** 100% 替代当前 C++ `micro_exec`，并且不额外写 Python/libbpf helper”，答案是：**不能**。
- 如果目标放宽为“**删掉 C++，改成 Python orchestration + bpftool + 少量 ctypes/libbpf 调用**”，则对当前 HEAD 的 `test-run` 路径是**大体可行**的。

最主要的硬缺口有 6 个：

- `bpftool` 没有离线枚举 `.bpf.o` 内 program 列表的命令，当前 repo 仍依赖 `micro_exec list-programs`。
- `bpftool` 没有 `bpf_enable_stats()` CLI；只能走全局 sysctl，或者额外用 Python ctypes/libbpf。
- `bpftool prog run` 只返回 `retval/duration` 和可选原始输出字节，不负责当前 `micro_exec` 的输入构造、结果抽取、fixture 解析、perf counter 采集。
- `bpftool` 是短命进程模型，不提供 keep-alive FD/进程内复用。
- 单次 `bpftool prog run` 的用户态开销很高；本次 VM 实测平均约 **37.7 ms/次**，而程序本体平均 `duration` 只有 **0.56 us**。
- `prog run` 的能力仍受内核 `prog->ops->test_run` 覆盖范围限制；不是所有 prog type 都支持，`ctx_in`/`ctx_out` 也不是所有 type 都能用。

## 0. 范围与证据

本报告基于**当前 checked-out tree** 调研，没有切分支。

注意：用户背景里提到 `runner/src/` 约 5000 行 C++。但当前 HEAD 上的 `micro_exec` 已经明显收缩，核心 CLI 只有两类：

- `micro_exec test-run`
- `micro_exec list-programs`

当前 `test-run` 路径已经是“单次 load -> `BPF_PROG_TEST_RUN` -> JSON 输出”，很多批处理/编排逻辑已经移到 Python 侧。也就是说：

- 对**当前 HEAD**，`bpftool` 替换的难度比“老的 5000 行 C++ runner”小。
- 如果你实际上想评估的是更早那套“大而全”的 C++ runner，可替代性只会更差，不会更好。

本次证据来自两类来源：

- vendored source inspection
  - `vendor/linux-framework/tools/bpf/bpftool/Documentation/bpftool-prog.rst`
  - `vendor/linux-framework/tools/bpf/bpftool/Documentation/bpftool-map.rst`
  - `vendor/linux-framework/tools/bpf/bpftool/prog.c`
  - `vendor/linux-framework/tools/bpf/bpftool/map.c`
  - `vendor/linux-framework/tools/lib/bpf/libbpf.c`
  - `vendor/linux-framework/kernel/bpf/syscall.c`
  - `vendor/linux-framework/net/core/filter.c`
  - `vendor/linux-framework/kernel/trace/bpf_trace.c`
  - `vendor/linux-framework/net/netfilter/nf_bpf_link.c`
- VM 实测
  - 使用 repo 规定入口：`make vm-shell ...`
  - 在 VM 内使用 vendored `bpftool` 进行 `loadall/run/show/map update/dump` 验证

本次没有修改 repo 代码；只新增了本文档和一个临时 VM 验证脚本：

- `docs/tmp/20260329/bpftool_feasibility_guest_check.sh`

## 1. `bpftool prog loadall`

### 1.1 能否加载任意 `.bpf.o` 并 pin 到 `/sys/fs/bpf/`？

结论：

- 对于**能被 libbpf 正常打开并通过 verifier 的 BPF ELF 对象**，可以。
- 这不等于“任意 ELF 都行”。仍然要求：
  - ELF 是 libbpf 能识别的 BPF object。
  - section name 能推断 prog type，或者命令里显式给 `type TYPE`。
  - CO-RE/BTF 重定位能通过。
  - verifier 能通过。

`bpftool` 文档明确支持：

```text
bpftool prog loadall OBJ PATH [type TYPE] ... [pinmaps MAP_DIR] [autoattach] [kernel_btf BTF_FILE]
```

并且 `loadall` 会把 object 内**所有 program** pin 到 `PATH` 目录下。

### 1.2 是否支持 `btf_custom_path`？

结论：**支持**，CLI 名字叫 `kernel_btf`。

源码里 `kernel_btf` 直接赋给：

```c
open_opts.btf_custom_path = GET_ARG();
```

所以它就是 `bpf_object_open_opts.btf_custom_path` 的 CLI 封装。

对你们“guest kernel 7.0-rc2，BTF 可能和 host 不同”的场景：

- 如果 `bpftool` 在 **VM 内**执行，直接用 guest 的 `/sys/kernel/btf/vmlinux` 即可。
- 如果试图在 host 上用 `bpftool` 去对 guest 内核做事，这是不可行方向；`bpftool` 操作的是当前所在系统的内核对象。

文档还特别提醒：

- `kernel_btf` 可以替换 CO-RE relocation 所用的 vmlinux BTF。
- 但像 fentry/fexit、struct_ops 这类依赖运行时 BTF 的功能，仍需要**实际运行内核**的 BTF。

### 1.3 加载后程序会一直留在内核直到 unpin 吗？

结论：**通常是**。

`loadall` 完成后，`bpftool` 进程退出，但 bpffs pin 持有内核引用，所以：

- 程序会留在内核里，直到：
  - 你 unpin / `rm -rf` 对应 bpffs 路径；
  - 且没有其他引用（例如 attach、link、其他 FD）再持有它。

VM 实测也证明了这一点：

- `bpftool prog loadall ...`
- `bpftool` 退出
- 随后仍可 `bpftool prog show pinned /sys/fs/bpf/.../simple_xdp`
- 仍可 `bpftool prog run pinned ...`

注意一个例外：

- 如果用了 `autoattach`，pin 的是 link，不一定是 program 本身；这时语义不同。
- 对你们 `TEST_RUN` 方案，通常不需要 `autoattach`。

### 1.4 map 自动创建吗？map FDs 怎么拿？

结论：

- map **会自动创建**，因为底层仍是 `bpf_object__load()`。
- 但 `bpftool` **不会把 map FD 暴露给外部进程**。

可用方式：

- 加 `pinmaps MAP_DIR`，把 map pin 到 bpffs。
- 之后通过：
  - `bpftool map show pinned /sys/fs/bpf/...`
  - `bpftool map show id <id>`
  - `bpftool map update pinned ...`
  - `bpftool map dump pinned ...`
  来重新打开并操作 map。

不能做到的事：

- 像进程内 C++/libbpf 那样，把“刚 load 完拿到的原始 FD”继续传给后续 syscall。
- 如果你需要真实 FD 常驻、跨多次 syscall 重用，`bpftool` CLI 本身做不到。

### 1.5 多 program object 怎么处理？每个 program 各自 pin？

结论：**是**。

`bpf_object__pin_programs(obj, path)` 会对每个 program 做：

```text
<PATH>/<prog->name>
```

也就是：

- object 里有多个 program，就会各自 pin 成一个单独路径。
- 目录名由你提供，文件名是 `prog->name`。

这带来一个实际问题：

- 你必须知道 program name，或者 load 之后去扫描 pin 目录。
- 用户提的样例路径 `.../xdp_pass` 只有在 program name 真叫 `xdp_pass` 时才成立。
- 本次 VM 里 `simple.bpf.o` 实际 pin 出来的路径是 `.../simple_xdp`。

这也是为什么当前 repo 里的 Python 脚本仍然要先调用：

```text
micro_exec list-programs --program <obj>
```

来拿 program 名字。

## 2. `bpftool prog run`

### 2.1 是否支持 `repeat N`？

结论：**支持**。

命令形式：

```text
bpftool prog run PROG data_in FILE [ctx_in FILE ...] [repeat N]
```

`prog.c` 里会把它填到：

```c
test_attr.repeat = repeat;
```

### 2.2 输出格式是什么？`duration` 是 total 还是 per-run？

结论：

- `duration` 是**每次运行的平均值**，不是 total。
- 文档明确写了：`repeat` 情况下输出的是 average。
- 非 JSON 文本输出也会打印：

```text
duration (average)
```

因此：

- 想要总时间，只能自己 `duration * repeat` 做近似换算。
- 但这是整数平均值，存在舍入损失。
- `bpftool` 不直接返回 total duration。

### 2.3 `-j` JSON 输出包含哪些字段？

结论：

- 最小集合：
  - `retval`
  - `duration`
- 如果请求了 `data_out -` 或 `ctx_out -`，还会额外带：
  - `data_out`
  - `ctx_out`

注意：

- `data_out` / `ctx_out` 的 JSON 是**十进制 byte array**。
- 不是十六进制字符串，也不是结构化解析结果。
- `repeat > 1` 时，输出 data/context 对应**最后一次运行**。

一个最小 JSON 例子就是本次 VM 的实际输出：

```json
{
  "retval": 2,
  "duration": 108
}
```

### 2.4 支持 `data_in`（packet input）吗？

结论：**支持**。

`data_in FILE` 会把文件按**原始字节流**读入内核。

这意味着：

- 如果你已经有原始 packet bytes，那么可以直接拿它做 `data_in`。
- 这相当于支持“raw packet 输入”。

但它**不等于**当前 repo 的高层输入构造逻辑。当前 `micro_exec` 还会做：

- `io-mode packet|staged|map|context`
- 根据 prog type 自动构造 XDP / skb packet
- `--raw-packet` 控制是否绕过这个构造
- 结果抽取（从 packet / skb ctx / map 里读出 benchmark result）

`bpftool` 本身只吃原始字节，不帮你做这些高层语义转换。

### 2.5 支持 `ctx_in`（context input）吗？

结论：**CLI 支持**，但是否真能跑取决于 prog type 的内核 `test_run` 实现。

文档明确说：

- 不是所有支持 `test_run` 的 program type 都接受 `ctx_in/ctx_out`。
- `bpftool` 自己**不做 type 检查**。

也就是说：

- CLI 层面可以传。
- 内核不支持时会直接失败。

另外一个实际限制是：

- `ctx_in` 需要你自己准备**正确的原始 struct bytes**。
- `bpftool` 不知道你的 context layout，也不会帮你构造。

### 2.6 支持哪些 prog type？XDP / TC / socket_filter / cgroup 都行吗？

结论：在你们 vendored 7.0-rc2 kernel 里，这 4 类都**可以**。

从内核里带 `.test_run = ...` 的 `prog_ops` 看，当前 7.0-rc2 明确支持至少这些类型：

- `socket_filter`
- `sched_cls`
- `sched_act`
- `xdp`
- `cgroup_skb`
- `lwt_in`
- `lwt_out`
- `lwt_xmit`
- `flow_dissector`
- `sk_lookup`
- `netfilter`
- `raw_tracepoint`
- `tracing`
- `syscall`
- `struct_ops`

其中用户关心的几类结论是：

- XDP：支持
- TC（`sched_cls` / `sched_act`）：支持
- socket_filter：支持
- cgroup：`cgroup_skb` 支持，但并不是所有 cgroup family 都支持

反例也很重要：不是所有 BPF prog type 都有 `.test_run`。例如当前树里这些常见类型就**没有**看到 `test_run`：

- `cgroup_sock`
- `cgroup_sock_addr`
- `sock_ops`
- `sk_skb`
- `sk_msg`
- `lwt_seg6local`

所以“bpftool 支持 `prog run`”不等于“所有 BPF 程序类型都能 test-run”。

### 2.7 性能：每次调用 `bpftool` 的 overhead 是多少？

结论：**很高**，而且远高于程序本体执行时间。

本次在 VM 内、vendored `bpftool` 上，对一个已 pin 的 `simple_xdp` 连续做 20 次：

```text
bpftool -j -p prog run pinned <pin_path> data_in <packet> repeat 1
```

实测结果：

```json
{
  "iterations": 20,
  "wall_ns_min": 30839424,
  "wall_ns_mean": 37706994.8,
  "wall_ns_max": 54814575,
  "prog_duration_ns_min": 269,
  "prog_duration_ns_mean": 559.9,
  "prog_duration_ns_max": 1202,
  "approx_user_overhead_ns_min": 30838832,
  "approx_user_overhead_ns_mean": 37706434.9,
  "approx_user_overhead_ns_max": 54813786
}
```

也就是：

- 平均 wall time：约 **37.7 ms/次**
- 程序本体 `duration`：约 **0.56 us/次**
- 绝大部分开销都在：
  - process spawn
  - CLI parse
  - libbpf 初始化
  - pin path reopen
  - JSON 编解码

这意味着：

- 如果你只是想拿 `duration` 这个内核返回值，`bpftool` 可以做到。
- 但如果你要高吞吐地做大量 sample，CLI 开销会非常重。
- `repeat N` 可以**摊薄**这部分 overhead，但只适用于“同一输入重复多次取平均”的场景。

## 3. `bpftool prog show`

### 3.1 能否读 `run_cnt` / `run_time_ns`（在 bpf_stats 开启后）？

结论：**能**。

前提：

- stats 必须已开启。
- 字段是**累计值**。
- 字段为 0 时，JSON 里可能不出现。

本次 VM 里，在 `repeat 100` 跑完后读到：

```json
{
  "id": 7,
  "type": "xdp",
  "name": "simple_xdp",
  "run_time_ns": 5259,
  "run_cnt": 100,
  ...
}
```

注意这组值和 `prog run` 的 `duration=108` 不完全一致：

- `108 * 100 = 10800`
- 但 `run_time_ns = 5259`

说明：

- `prog run` 返回的 `duration`
- 和 stats 累计里的 `run_time_ns`

不是同一个计时口径，不能直接视为严格等价。

如果要用 `run_cnt/run_time_ns` 做 benchmark：

- 应该做 before/after snapshot，再取 delta。
- 当前 repo 的 `runner/libs/metrics.py` / `runner/libs/profiler.py` 已经是这个思路。

### 3.2 通过 ID 还是 pinned path 查询？

结论：**两种都支持**。

program handle 解析支持：

- `id <id>`
- `tag <tag>`
- `name <name>`
- `pinned <path>`

你们这个场景最常用的是：

- `bpftool prog show pinned /sys/fs/bpf/.../prog_name`
- `bpftool prog show id <id>`

### 3.3 JSON 输出格式？

常见字段包括：

- `id`
- `type`
- `name`
- `tag`
- `gpl_compatible`
- `run_time_ns` / `run_cnt`（非零时）
- `loaded_at`
- `uid`
- `orphaned`
- `bytes_xlated`
- `jited`
- `bytes_jited`
- `bytes_memlock`
- `map_ids`
- `btf_id`
- `pinned`（仅在 `--bpffs/-f` 扫描 pin 信息时出现）

一个实际例子（本次 VM）：

```json
{
  "id": 7,
  "type": "xdp",
  "name": "simple_xdp",
  "tag": "96f2ea6bee402317",
  "gpl_compatible": true,
  "loaded_at": 1774820771,
  "uid": 0,
  "orphaned": false,
  "bytes_xlated": 192,
  "jited": true,
  "bytes_jited": 116,
  "bytes_memlock": 4096,
  "btf_id": 23
}
```

## 4. `bpftool map update / dump`

### 4.1 能否用来做 fixture replay（给 map 填值）？

结论：**能，但需要你自己做 fixture->CLI 翻译层**。

`bpftool map update` 已经支持：

- 原始 bytes key/value
- 对 `prog_array` 的 program 引用更新
- 对 map-in-map 的 inner map 引用更新

也就是说，作为“底层执行器”它够用；但它不负责：

- 解析你们当前 YAML/JSON fixture 文件
- 做字段校验
- 做批量编排

这部分如果移除 C++，要挪到 Python。

### 4.2 支持哪些 map type？

结论：

- 普通 key/value map：支持
- `PROG_ARRAY`：支持
- `ARRAY_OF_MAPS` / `HASH_OF_MAPS`：支持
- 其他特殊 map type 是否适合做 fixture replay，取决于 value 是否能由原始 bytes 或 `id/pinned` 引用表达

更准确地说：

- `bpftool map update` 没有一个“只允许某些常规 map type”的硬编码白名单。
- 但能否实际 replay，要看该 map type 的 update 语义。

对你们问题里明确点名的两类：

- `PROG_ARRAY`：支持
- map-in-map：支持

### 4.3 `PROG_ARRAY / map-in-map` 是否真的可用？

结论：**可用，而且本次已在 VM 实测通过**。

VM 里实际跑过：

```text
bpftool map create <root>/prog_array type prog_array key 4 value 4 entries 1 name demo_prog_array
bpftool map update pinned <root>/prog_array key hex 00 00 00 00 value pinned <prog_pin>
bpftool -j -p map dump pinned <root>/prog_array
```

输出：

```json
[{
  "key": ["0x00","0x00","0x00","0x00"],
  "value": ["0x07","0x00","0x00","0x00"]
}]
```

map-in-map 也已验证：

```json
[{
  "key": ["0x00","0x00","0x00","0x00"],
  "value": ["0x12","0x00","0x00","0x00"],
  "inner_map_id": 18
}]
```

一个值得注意的细节：

- `bpftool` 文档特别提醒，`prog_array` update 要确保 map 被 pin 或被某进程持有。
- 否则 `bpftool` 退出后，如果 map 没其他引用，更新可能丢失。

这点对你们 benchmark 编排是完全可控的，因为本来就会把对象 pin 在 bpffs。

### 4.4 与当前 C++ fixture loader 的对比

一个意外结论是：

- 在 fixture replay 这件事上，`bpftool` 某些方面**比当前 C++ 更强**。

因为当前 `micro_exec` 的 fixture loader 明确拒绝：

- `BPF_MAP_TYPE_PROG_ARRAY`
- `BPF_MAP_TYPE_ARRAY_OF_MAPS`
- `BPF_MAP_TYPE_HASH_OF_MAPS`

而 `bpftool map update` 对这些是有支持路径的。

## 5. `bpf_enable_stats`

### 5.1 `bpftool` 能开启 `bpf_stats` 吗？

结论：**没有专门的 bpftool 子命令**。

`bpftool` 文档只提到：

```text
sysctl -w kernel.bpf_stats_enabled=1
```

这说明 CLI 层面推荐的是**全局 sysctl 开关**，而不是一个 `bpftool prog enable-stats` 命令。

### 5.2 如果 `bpftool` 不支持，Python ctypes 能做吗？

结论：**能，而且 repo 里已经有现成实现**。

`runner/libs/metrics.py` 已经通过 ctypes 调 libbpf：

```python
fd = int(_libbpf().bpf_enable_stats(BPF_STATS_RUN_TIME))
```

这条路径的优点是：

- 它对应的是 `BPF_ENABLE_STATS` syscall 包装。
- 打开 stats 返回一个 FD。
- 该 FD 生命周期内 stats 生效；FD 关闭后结束。

相比之下，`sysctl -w kernel.bpf_stats_enabled=1` 的问题是：

- 它是全局开关。
- 对 benchmark harness 更“脏”，也更不容易做精细范围控制。

因此：

- 如果要“无 C++ 化”，我不建议把 stats 控制退化成 shell `sysctl`。
- 推荐直接复用现有 Python ctypes/libbpf helper。

## 6. 实际验证

### 6.1 环境

当前树的 vendored kernel：

```text
VERSION = 7
PATCHLEVEL = 0
SUBLEVEL = 0
EXTRAVERSION = -rc2
```

vendored `bpftool` 构建后版本：

```text
bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons
```

VM 内默认 `bpftool` 版本也是：

```text
bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons
```

### 6.2 实际执行命令

本次使用的 canonical VM 入口：

```bash
make vm-shell VM_COMMAND='bpftool version'
make vm-shell VM_COMMAND='BPFTOOL=vendor/linux-framework/tools/bpf/bpftool/bpftool bash docs/tmp/20260329/bpftool_feasibility_guest_check.sh'
```

等价的核心验证序列是：

```bash
mount -t bpf bpf /sys/fs/bpf
sysctl -w kernel.bpf_stats_enabled=1

bpftool prog loadall micro/programs/simple.bpf.o /sys/fs/bpf/bpftool_feasibility_xxx/progs \
  kernel_btf /sys/kernel/btf/vmlinux

bpftool -j -p prog show pinned /sys/fs/bpf/bpftool_feasibility_xxx/progs/simple_xdp

bpftool -j -p prog run pinned /sys/fs/bpf/bpftool_feasibility_xxx/progs/simple_xdp \
  data_in /tmp/simple.packet \
  repeat 100

bpftool -j -p prog show pinned /sys/fs/bpf/bpftool_feasibility_xxx/progs/simple_xdp
```

### 6.3 样例命令的修正

用户给的样例：

```bash
bpftool prog loadall /path/to/simple.bpf.o /sys/fs/bpf/test && \
bpftool prog run pinned /sys/fs/bpf/test/xdp_pass repeat 100 -j && \
rm -rf /sys/fs/bpf/test
```

严格来说不够准确，原因有两个：

- `bpftool prog run` 语法里 **`data_in FILE` 是必需的**
- `-j` 是全局 flag，通常应放在 `prog` 前

可工作的等价写法应类似：

```bash
bpftool prog loadall /path/to/simple.bpf.o /sys/fs/bpf/test kernel_btf /sys/kernel/btf/vmlinux
bpftool -j -p prog run pinned /sys/fs/bpf/test/simple_xdp data_in /tmp/simple.packet repeat 100
rm -rf /sys/fs/bpf/test
```

### 6.4 实测结果

本次 VM 内实际得到的关键输出：

`prog show pinned`（load 后）：

```json
{
  "id": 7,
  "type": "xdp",
  "name": "simple_xdp",
  "tag": "96f2ea6bee402317",
  "gpl_compatible": true,
  "loaded_at": 1774820771,
  "uid": 0,
  "orphaned": false,
  "bytes_xlated": 192,
  "jited": true,
  "bytes_jited": 116,
  "bytes_memlock": 4096,
  "btf_id": 23
}
```

`prog run repeat 100`：

```json
{
  "retval": 2,
  "duration": 108
}
```

`prog show pinned`（run 后）：

```json
{
  "id": 7,
  "type": "xdp",
  "name": "simple_xdp",
  "tag": "96f2ea6bee402317",
  "gpl_compatible": true,
  "run_time_ns": 5259,
  "run_cnt": 100,
  "loaded_at": 1774820771,
  "uid": 0,
  "orphaned": false,
  "bytes_xlated": 192,
  "jited": true,
  "bytes_jited": 116,
  "bytes_memlock": 4096,
  "btf_id": 23
}
```

`prog_array` dump：

```json
[{
  "key": ["0x00","0x00","0x00","0x00"],
  "value": ["0x07","0x00","0x00","0x00"]
}]
```

`array_of_maps` dump：

```json
[{
  "key": ["0x00","0x00","0x00","0x00"],
  "value": ["0x12","0x00","0x00","0x00"],
  "inner_map_id": 18
}]
```

结论很明确：

- `loadall`：工作
- `kernel_btf`：工作
- `run repeat`：工作
- `show stats`：工作
- `prog_array` / map-in-map replay：工作

## 7. `micro_exec` 能做但 `bpftool` 做不到的事

这部分是最终结论的关键。下面分成“纯 CLI hard blocker”和“可由 Python 补齐但不是 bpftool 自带”两类。

### 7.1 纯 `bpftool` CLI 的 hard blockers

- 离线 program 枚举
  - `bpftool` 没有“列出 `.bpf.o` 内所有 programs 且不 load”的命令。
  - 当前 repo 仍依赖 `micro_exec list-programs`。
- `bpf_enable_stats()` syscall
  - `bpftool` 没有 dedicated command。
  - 只能退化成全局 sysctl，或者额外写 helper。
- 进程内 FD keep-alive
  - `bpftool` 每次都是短命进程。
  - 没法像 libbpf/C++ 那样把 FD 留在进程里长期复用。
- 进程内 perf counter 采集
  - 当前 `micro_exec` 可在 `BPF_PROG_TEST_RUN` 外围套 perf counters。
  - `bpftool prog run` 本身不做这个。

### 7.2 `bpftool` 不自带，但 Python 可以补齐的能力

- fixture 文件解析
  - 当前 C++ 读 YAML/JSON fixture，逐条 update map。
  - `bpftool` 能执行 update，但不解析 fixture 格式。
- packet/context 输入构造
  - 当前 `micro_exec` 会根据 prog type 和 `io-mode` 生成输入。
  - `bpftool` 只接受原始 bytes。
- benchmark 结果抽取
  - 当前 `micro_exec` 会从 packet、skb context、`result_map` 中抽取 `result`。
  - `bpftool` 只给你原始 `data_out/ctx_out` 或 map dump。
- 批量 warmup / sample orchestration
  - `bpftool` 只能做单条命令。
  - 批量实验流程仍需 harness。

### 7.3 当前 `micro_exec` 的额外输出里，哪些 `bpftool` 不能原样替代？

当前 `micro_exec` JSON 至少还会产出这些高层字段：

- `compile_ns`
- `exec_ns`
- `wall_exec_ns`
- `exec_cycles`
- `tsc_freq_hz`
- `result`
- `retval`
- `jited_prog_len`
- `xlated_prog_len`
- `phases_ns`
- `perf_counters`

其中：

- `retval` / `exec_ns(duration)`：`bpftool prog run` 可提供
- `jited_prog_len` / `xlated_prog_len`：`bpftool prog show` 可提供
- `dump_jit` / `dump_xlated`：可改用 `bpftool prog dump jited/xlated`
- 但下面这些不能由单条 `bpftool prog run` 原样提供：
  - `compile_ns`
  - `wall_exec_ns`
  - `exec_cycles`
  - `phases_ns`
  - `perf_counters`
  - 高层 `result`

### 7.4 用户举的几个例子逐项判断

- keep-alive 模式（持续持有 FD）
  - `bpftool` CLI 做不到。
  - 这是 pure CLI 的真实缺口。
- raw_packet 输入
  - 如果你已经有 raw packet bytes，`data_in FILE` 可以。
  - 但“从内存基准输入自动合成 packet”不是 `bpftool` 能力。
- llvmbpf runtime
  - `bpftool` 完全不覆盖。
  - 这是另一个独立运行时，不属于内核 `BPF_PROG_TEST_RUN` 路径。

### 7.5 这些局限是不是 blocker？

对“**纯 bpftool 命令行 100% 替代 C++**”这个问题：

- **是 blocker。**

对“**删除 C++，改成 Python harness + bpftool + ctypes/libbpf**”这个问题：

- 有些不是 blocker。
- 真正的 blocker 只剩：
  - 你是否接受没有进程内 FD keep-alive
  - 你是否接受每次 `bpftool` 调用带来的高 wall overhead
  - 你是否接受补一层 Python 来做 program discovery / fixture parsing / stats enable / result extraction

如果 benchmark 只关心 `BPF_PROG_TEST_RUN` 返回的 `duration`，并且可以使用 `repeat N` 摊薄 CLI 开销，那么这条路线是可行的。

如果 benchmark 需要：

- 进程内常驻 FD
- 高频低延迟采样
- perf counter 围绕 syscall 精准采集
- 复杂 context 构造与结果解释

那么 pure bpftool 会比较别扭，甚至不合适。

## 8. 我们 7.0-rc2 tree 里的 bpftool 是否支持这些功能？

结论：**支持上文讨论的大部分功能**。

具体看点：

- `prog loadall` / `kernel_btf` / `pinmaps`
  - `vendor/linux-framework/tools/bpf/bpftool/prog.c`
- `prog run`
  - 同文件 `do_run()`
- `prog show` 的 `run_time_ns/run_cnt`
  - 同文件 `print_prog_header_json()`
- `map update` 对 `prog_array` / map-in-map 的支持
  - `vendor/linux-framework/tools/bpf/bpftool/map.c`

一个容易混淆的点是版本号：

- kernel tree 是 `7.0-rc2`
- 但 vendored `bpftool` 编译后自报：

```text
bpftool v7.7.0
using libbpf v1.7
```

这不矛盾；`bpftool` 自己的工具版本号并不等于内核发布号。

### 8.1 `prog_run` 相关源码结论

从 `vendor/linux-framework/tools/bpf/bpftool/prog.c` 可直接确认：

- `repeat` 已实现
- `data_in/data_out/ctx_in/ctx_out` 已实现
- JSON 输出仅包含 `retval/duration` 和可选原始输出
- `duration` 是内核返回的平均值

从 `vendor/linux-framework/kernel/bpf/syscall.c` 可确认：

- `bpftool` 最终还是走 `BPF_PROG_TEST_RUN`
- 真正能不能跑，取决于 `prog->aux->ops->test_run`

从 `vendor/linux-framework/net/core/filter.c` / `kernel/trace/bpf_trace.c` / `net/netfilter/nf_bpf_link.c` 可确认：

- 你们关心的 `xdp/tc/socket_filter/cgroup_skb` 都挂了 `.test_run`
- 但并不是全类型覆盖

## 最终结论

### 简短答案

- `bpftool` **不能 100% 替代当前 C++ `micro_exec`，如果要求“只用 bpftool CLI，不额外写 helper”**。
- `bpftool` **可以替代其中最核心的内核 `TEST_RUN` 执行链路**。

### 更准确的结论

如果目标是：

- 消灭 C++ `micro_exec`
- 但允许保留一层 Python harness
- 允许用 ctypes/libbpf 做 `bpf_enable_stats`
- 允许自己做 fixture parsing / program discovery / result extraction

那么：

- 对当前 HEAD 的 `test-run` 路径，这条路线是**可行**的。

推荐的替代形态会是：

- `bpftool prog loadall ... [kernel_btf ...] [pinmaps ...]`
- Python 记录 program name / pin path / prog id
- Python 通过 `bpftool map update` 回放 fixture
- Python 用 ctypes/libbpf 开启 `bpf_enable_stats`
- Python 调 `bpftool prog run pinned ... data_in ... [ctx_in ...] repeat N`
- Python 用 `bpftool prog show id/pinned` 读取 `run_cnt/run_time_ns`
- Python 做 before/after delta、结果抽取、批量编排

如果目标是：

- “一个 shell 脚本 + 纯 bpftool 命令，完全取代当前 `micro_exec` 全部功能”

那么结论是：

- **不可行**

原因不是 `loadall/run/show/map update` 不够，而是外围配套能力缺口太多，尤其是：

- 离线 program 枚举
- stats enable
- 结果抽取
- perf counter
- 高层输入构造
- CLI 进程开销

### 最终判断

本题的最终结论应写成：

> `bpftool` 可以替代当前 C++ `micro_exec` 的大部分 `BPF_PROG_TEST_RUN` 核心调用，但 **不能用纯 bpftool CLI 100% 完整替代整个 runner 语义**。  
> 如果允许使用 Python orchestration + ctypes/libbpf 补齐缺口，则“删掉 C++”对当前 HEAD 是现实可行的。
