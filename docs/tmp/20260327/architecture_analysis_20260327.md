# Architecture Analysis 2026-03-27

Scope: source-only analysis of `daemon/`, `runner/`, and `corpus/` for `map_inline` no-hit behavior and cross-component coupling. I did not run kernel/BPF tests on the host.

## Part 1: Map Inline 架构验证

### 假设 1: `LD_IMM64 -> map_id` 映射可能断裂

结论: 否定为“完全没有映射逻辑”这一说法；代码里有映射，但它是 daemon 本地重建、并且依赖顺序的隐式映射，不是协议里显式传进来的绑定表。

证据:

| 检查点 | 结果 | 代码位置 |
| --- | --- | --- |
| `try_apply_one()` 里的 `map_ids` 从哪来 | 先拿 `prog_fd`，再调用 `bpf_prog_get_map_ids(fd)`，然后把结果塞进 `BpfProgram::set_map_ids()` | `daemon/src/commands.rs:661-662`, `daemon/src/commands.rs:740-753` |
| `BpfProgram` 如何保存映射元数据 | `BpfProgram` 同时保存 `map_ids` 和 `map_fd_bindings`；`set_map_ids()` 会先构建 `old_fd -> map_id` 绑定 | `daemon/src/pass.rs:71-77`, `daemon/src/pass.rs:105-109` |
| 绑定逻辑在哪里 | `build_map_fd_bindings()` 扫原始指令流，收集所有 `LD_IMM64` 的旧 fd，按首次出现顺序与 `map_ids[index]` 配对 | `daemon/src/pass.rs:178-203` |
| `MapInfoAnalysis` 是否使用这些绑定 | 会优先用 `map_fd_bindings[old_fd]`，找不到再回退到 `map_ids[map_index]` | `daemon/src/analysis/map_info.rs:117-123`, `daemon/src/analysis/map_info.rs:169-177` |
| REJIT 前 map fd relocation 是否也用同一逻辑 | 是，`resolve_map_ids_for_relocation()` 也是先看 `map_fd_bindings`，再按索引回退 | `daemon/src/bpf.rs:946-947`, `daemon/src/bpf.rs:1000-1015` |

结论细化:

- daemon 不是“完全不知道 fd number 对应哪个 map_id”。
- 但它也没有从 runner 收到一个显式的 `(old_fd, map_id)` 表。
- 当前设计是假设“原始字节码里 `LD_IMM64` 的首次出现顺序”与“kernel `prog_info.used_maps`/`map_ids[]` 顺序”一致，然后在 daemon 本地重建绑定。

所以:

- “没有映射逻辑，所以必然 0 hits”这一假设不成立。
- 但这是一个脆弱耦合点，因为协议只传了 `prog_id`，没有传 map binding schema。

### 假设 2: ARRAY map zero-value lookup 是否成功

结论: 可以成功；即使 kernel lookup 返回 `ENOENT`，daemon 也会为 `ARRAY`/`PERCPU_ARRAY` 合成全零值。返回全零 buffer 不会让 `map_inline` 跳过。

证据:

| 检查点 | 结果 | 代码位置 |
| --- | --- | --- |
| `bpf_map_lookup_elem_by_id()` 怎么做 lookup | 先 `bpf_map_get_fd_by_id(map_id)`，再 lookup；如果是 `ENOENT`，继续查 map info 并尝试零值回退 | `daemon/src/bpf.rs:581-610` |
| zero-filled fallback 条件 | 仅对 `ARRAY`/`PERCPU_ARRAY`，要求 key size/value size 匹配，且索引 `< max_entries` | `daemon/src/bpf.rs:686-703` |
| serve 模式是否丢权限 | `start_daemon_server()` 只是 `subprocess.Popen([daemon, "serve", ...])`，没有降权逻辑；如果来宾里以 root 启动，它就保留 root | `corpus/modes.py:548-558` |
| `map_inline` 是否会因为值是 0 而 skip | 不会。`build_site_rewrite()` 直接把 lookup 结果喂给 `prepare_inline_value()`，最后 `emit_constant_load()` 甚至会为 0 生成 `mov64_imm(dst, 0)` | `daemon/src/passes/map_inline.rs:498-580`, `daemon/src/passes/map_inline.rs:662-673` |

测试也明确覆盖了这个行为:

- `daemon/src/bpf.rs:2161` `test_mock_array_lookup_returns_zero_for_in_range_missing_key()`
- `daemon/src/bpf.rs:2233` `test_mock_percpu_array_lookup_returns_zero_for_in_range_missing_key()`
- `daemon/src/passes/map_inline.rs:2575` `map_inline_pass_inlines_zero_filled_array_maps()`
- `daemon/src/passes/map_inline.rs:2612` `map_inline_pass_inlines_zero_filled_percpu_array_maps()`

所以:

- “ARRAY key=0 读出来全 0，所以 `map_inline` skip”这一假设不成立。
- 如果 serve 模式里 daemon 确实以 root 运行，这条路径本身没有额外权限障碍。

### 假设 3: Key 提取失败率

结论: 这是当前代码里最强、也最像 0 hits 真因的架构限制。

`map_inline` 的 key 提取条件非常苛刻:

- lookup helper 调用点必须先被 `find_map_lookup_sites()` 识别出来。
- 它要求 `r1` 最近一次定义必须是直接的 `LD_IMM64 BPF_PSEUDO_MAP_FD`。否则这个 helper call 连 site 都不会被记录。见 `daemon/src/passes/map_inline.rs:76-96` 和 `daemon/src/passes/map_inline.rs:692-705`。
- `extract_constant_key()`/`try_extract_constant_key()` 又要求 `r2` 最终能解析到 `fp` 相对栈地址，并且那个栈槽最近一次写入必须是常量可恢复的 materialization。见 `daemon/src/passes/map_inline.rs:98-120`, `daemon/src/passes/map_inline.rs:787-914`, `daemon/src/passes/map_inline.rs:979-1049`。

如果 key 提取失败，pass 会:

- 记录标准化 skip reason: `lookup key is not a constant stack materialization`
- 同时记录 detail diagnostic: `site at PC=...: key extraction failed: ...`

对应代码:

- `daemon/src/passes/map_inline.rs:214-242`
- `daemon/src/passes/map_inline.rs:1161-1175`

这一点和仓库里“真实一点”的 BPF 程序模式是对不上的。这个仓库里我没有找到 vendored BCC corpus 对象，所以这里的“典型模式”只能做保守推断；但仓库内的代表性 BPF 程序已经显示，多数 lookup key 是运行时数据，不是字面量常量:

- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:143-159` 先算 hash，再构造 `key = RING_SIZE * vip_num + hash` 后 lookup。
- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:185-199` 直接用 `pckt->flow` 做 key lookup。
- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:619-635` 用 `pckt->flow` 做 LRU key。
- `runner/repos/xdp-examples/pping/pping_kern.c:1142-1161` 用结构体 `key` lookup 聚合 map。
- `runner/repos/xdp-examples/pping/pping_kern.c:1240-1248` 用 `p_info->reply_pid` lookup。
- `runner/repos/xdp-examples/pping/pping_kern.c:1482-1493` 用运行时生成的 `df_key`/`local_pid` 操作 map。

反过来，常量 key 的例子反而主要出现在为 `map_inline` 量身做的简单测试里:

- `tests/unittest/progs/test_daemon_e2e_socket_filter.bpf.c:16-23` 用 `__u32 key = 0` lookup `ARRAY` map。

所以:

- 对真实 workload，`map_inline` 很容易在 key 提取这里失败。
- 对常量零 key 的简化单元测试，`map_inline` 可以成功。

### `map_inline 0 hits` 的精确根因

我能从源码精确确认的根因是:

1. 当前实现确实有 `old_fd -> map_id` 重建逻辑，所以“完全没有 map 绑定”不是根因。
2. 当前实现对 `ARRAY`/`PERCPU_ARRAY` 的 zero-filled lookup 有专门支持，零值本身不会导致 skip。
3. 当前实现只支持“常量、栈物化、可逆向追踪”的 lookup key；这是一个强硬的功能边界。`try_extract_constant_key()` 失败后，site 会被归一化为 `lookup key is not a constant stack materialization`，最终导致 `no map_inline rewrites prepared`。

代码上能直接看到的功能性根因，就是第 3 点。

运行时上的保守结论:

- 如果你的 corpus 里大多数 lookup key 是 pid/cpu/flow/hash/bucket 这类运行时值，那么 `map_inline` 变成 0 hits 是完全符合当前实现的。
- 要把这个判断从“强代码结论”升级成“你那批 corpus 的最终实测根因”，还需要看 daemon 返回的 `passes[].skip_reasons`/`diagnostics` 统计。

### 完整的 skip / no-hit 路径列表

#### A. 顶层 no-hit / no-change 路径

| 路径 | 表现 | 代码位置 |
| --- | --- | --- |
| 原始字节码不可得 | `orig_insns.is_empty()`，优化直接返回 no-op | `daemon/src/commands.rs:723-738` |
| helper site 根本没被识别到 | `map_inline: found 0 lookup sites` | `daemon/src/passes/map_inline.rs:158-160` |
| 找到了 site，但没有一个 site 产出 rewrite | `map_inline: no map_inline rewrites prepared` | `daemon/src/passes/map_inline.rs:350-359` |
| 产出了 rewrite，但全都因冲突被丢弃 | `map_inline: all prepared rewrites were discarded` | `daemon/src/passes/map_inline.rs:369-417` |
| pipeline 最终没改程序 | `try_apply_one()` 返回 `no_change` / `restored_original` | `daemon/src/commands.rs:776-842` |

注意一个“静默 no-hit”路径:

- `find_map_lookup_sites()` 只接受“`r1` 最近定义是 `LD_IMM64 dst=r1 src=BPF_PSEUDO_MAP_FD`”这一种 map 参数装载模式；如果不是这种模式，helper call 连 site 都不会计入。见 `daemon/src/passes/map_inline.rs:76-96` 和 `daemon/src/passes/map_inline.rs:692-705`。

#### B. `record_skip()` 记录的标准化 skip reason

| Skip reason | 触发位置 | 说明 |
| --- | --- | --- |
| `map reference metadata unavailable` | `daemon/src/passes/map_inline.rs:167-174` | `map_info.reference_at_pc()` 取不到 map ref |
| `map info unavailable` | `daemon/src/passes/map_inline.rs:180-183` | 有 map ref，但 live map info 解析失败 |
| `map type {map_type} not inlineable in v1` | `daemon/src/passes/map_inline.rs:195-211` | map 类型不在 v1 inline 支持集 |
| `lookup key is not a constant stack materialization` | `daemon/src/passes/map_inline.rs:214-242` | key 提取失败后的统一理由 |
| `key width {width} is smaller than map key size {info.key_size}` | `daemon/src/passes/map_inline.rs:244-250` | key 宽度不够 |
| `constant key {key} out of range for max_entries {info.max_entries}` | `daemon/src/passes/map_inline.rs:252-258` | ARRAY/PERCPU_ARRAY 索引越界 |
| `speculative map inline requires an immediate null check` | `daemon/src/passes/map_inline.rs:267-270` | 推测式 inline 需要紧邻 null-check |
| `lookup result is not consumed by fixed-offset scalar loads` | `daemon/src/passes/map_inline.rs:280-284` | 没有固定偏移标量 load 可替换 |
| `lookup result has non-load uses` | `daemon/src/passes/map_inline.rs:286-289` | 结果指针逃逸或有非 load 用途 |
| `failed to materialize replacement constants` | `daemon/src/passes/map_inline.rs:292-299` | 生成替换常量失败 |
| `map lookup failed: ...` | `daemon/src/passes/map_inline.rs:300-316` | live map read 真正报错 |
| `lookup pattern contains a branch target` | `daemon/src/passes/map_inline.rs:320-327` | 待删片段被跳转目标穿过 |
| `internal rewrite overlap` | `daemon/src/passes/map_inline.rs:330-337` | 同一 site 内删改区间重叠 |
| `overlapping map inline rewrite` | `daemon/src/passes/map_inline.rs:380-388` | 多个 site 之间 rewrite 冲突 |

#### C. 通过 detail diagnostic 暴露的低层失败文本

这些文本不一定成为最终 `skip_reasons` key，但会出现在 `diagnostics` 里:

- `site pc=... skip: map reference unavailable` at `daemon/src/passes/map_inline.rs:168-171`
- `site pc=... skip: map type ... not inlineable` at `daemon/src/passes/map_inline.rs:196-199`
- `site pc=... skip: ...` at `daemon/src/passes/map_inline.rs:229-230`
- `site at PC=...: key extraction failed: ...` at `daemon/src/passes/map_inline.rs:236-239`
- `site at PC=...: value read failed: ...` at `daemon/src/passes/map_inline.rs:311-314`
- `site at PC=...: bpf_map_lookup_elem_by_id(...) failed: ...` at `daemon/src/passes/map_inline.rs:522-529`

`key extraction failed` 下层可能的原始错误文本包括:

- `no stack store found for fp...` at `daemon/src/passes/map_inline.rs:787-823`
- `stack store at pc ... uses unsupported width opcode ...` at `daemon/src/passes/map_inline.rs:801-806`
- `constant register resolution for r... exceeded 64 steps` at `daemon/src/passes/map_inline.rs:841-845`
- `source register r... is a function argument` at `daemon/src/passes/map_inline.rs:848-852`
- `no definition for source register r...` at `daemon/src/passes/map_inline.rs:848-852`
- `register r... at pc ... is loaded from pseudo source ...` at `daemon/src/passes/map_inline.rs:856-864`
- `register r... definition at pc ... uses unsupported constant op ...` at `daemon/src/passes/map_inline.rs:898-903`
- `register r... definition at pc ... is not a supported constant materialization` at `daemon/src/passes/map_inline.rs:910-913`
- `stack pointer resolution for r... exceeded 64 steps` at `daemon/src/passes/map_inline.rs:995-999`
- `key pointer flows from function argument r...` at `daemon/src/passes/map_inline.rs:1005-1009`
- `no definition for key pointer register r...` at `daemon/src/passes/map_inline.rs:1005-1009`
- `resolved stack offset ... from r... does not fit in i16` at `daemon/src/passes/map_inline.rs:1037-1042`
- `register r... definition at pc ... does not resolve to fp-relative stack memory` at `daemon/src/passes/map_inline.rs:1046-1049`

`prepare_inline_value()` 还会抛出这几类 site-level veto:

- `PERCPU_ARRAY has zero value_size` at `daemon/src/passes/map_inline.rs:614-617`
- `PERCPU_ARRAY lookup blob length ... is inconsistent with slot stride ...` at `daemon/src/passes/map_inline.rs:619-626`
- `PERCPU_ARRAY value differs across CPUs for ... slot(s)` at `daemon/src/passes/map_inline.rs:630-637`

#### D. daemon 返回给 runner 的可观测字段

`PassResult` 会聚合 `sites_skipped` 和 `skip_reason_counts()`，然后 `PassDetail::from()` 把这些内容放进 `OptimizeOneResult.passes[]` 里:

- `daemon/src/pass.rs:283-304`
- `daemon/src/commands.rs:68-95`

这意味着，只要保留 `passes[].skip_reasons` / `passes[].diagnostics`，就能直接看到 0-hit 到底卡在哪条路径上。

## Part 2: 工程质量分析

### Runner 文件统计

| 文件 | 行数 | 结论 |
| --- | --- | --- |
| `runner/src/kernel_runner.cpp` | 3841 | 严重过长，应拆分 |
| `runner/src/batch_runner.cpp` | 1927 | 严重过长，应拆分 |
| `runner/src/common.cpp` | 1024 | 已超过 1000，且职责混杂 |
| `runner/src/main.cpp` | 107 | 简单 dispatch，基本正常 |
| `runner/include/micro_exec.hpp` | 222 | 不算巨大，但耦合面很宽 |

### `runner/src/kernel_runner.cpp`

行数: 3841。

职责分布:

- daemon socket 协议与手写 JSON 解析: `runner/src/kernel_runner.cpp:1162-1511`
- libbpf/manual load/REJIT 逻辑: `runner/src/kernel_runner.cpp:1623-1934`
- prepared state / prepared run orchestration: `runner/src/kernel_runner.cpp:2312-3141`
- 实际 run/attach measurement 主流程: `runner/src/kernel_runner.cpp:2561-3841`

回答你的问题: 是，`kernel_runner.cpp` 同时承担了 loading、measuring、daemon communication、结果封装。

明显的 God Object / God File:

- `prepared_kernel_state` 同时持有 CLI 参数、输入数据、对象句柄、程序句柄、REJIT 状态、计时数据、多程序缓存。见 `runner/src/kernel_runner.cpp:2323-2342`。
- `prepared_program_state` 把 live program handle、program_info、REJIT 状态、fixture 状态绑在一起。见 `runner/src/kernel_runner.cpp:2312-2321`。

重复逻辑:

- 与 `batch_runner.cpp` 基本重复的 daemon socket client。
- 与 `batch_runner.cpp` 基本重复的 ad-hoc JSON 提取逻辑。
- runner 层既保留 raw daemon JSON，又自己解析一遍 summary/pass details，存在两套真相来源。

### `runner/src/batch_runner.cpp`

行数: 1927。

职责分布:

- batch spec / batch job 结构与 prepared store: `runner/src/batch_runner.cpp:39-210`
- daemon 协议与本地 JSON 输出: `runner/src/batch_runner.cpp:390-452`, `runner/src/batch_runner.cpp:641-805`
- YAML spec 解析与 job 生成: `runner/src/batch_runner.cpp:1105-1277`
- static verify 对象加载/比对: `runner/src/batch_runner.cpp:1314-1661`
- scheduler / chunk 执行 / 结果写入: `runner/src/batch_runner.cpp:1632-1927`

问题:

- 也是 God File。
- `daemon_socket_optimize_batch()` 基本复制了 `kernel_runner.cpp` 的 socket 客户端，只是提取的字段略有不同。见 `runner/src/batch_runner.cpp:703-791` 与 `runner/src/kernel_runner.cpp:1416-1511`。
- `extract_pass_details_batch()` 与 `extract_pass_details()` 也是重复实现。见 `runner/src/batch_runner.cpp:641-688` 与 `runner/src/kernel_runner.cpp:1348-1395`。

### `runner/src/common.cpp`

行数: 1024。

职责分布:

- 通用 JSON 输出工具: `runner/src/common.cpp:17-88`
- keep-alive 模式的手写 JSON reader: `runner/src/common.cpp:119-345`
- CLI 参数解析: `runner/src/common.cpp:506-664`
- keep-alive JSON 到 `cli_options` 的转换: `runner/src/common.cpp:666-842`
- `sample_result` / `rejit` JSON 序列化: `runner/src/common.cpp:844-1024`

问题:

- 一个文件同时做 CLI、stdin keep-alive 协议、JSON parser、JSON serializer，边界很差。
- 手写 JSON parser 与 `kernel_runner.cpp`/`batch_runner.cpp` 的字符串扫描 parser 并存，重复且脆弱。

### `runner/src/main.cpp`

行数: 107。

职责:

- 单纯做单次 CLI、`run-batch`、keep-alive loop 的入口 dispatch。见 `runner/src/main.cpp:9-107`。

结论:

- 这个文件本身不是问题。

### `runner/include/micro_exec.hpp`

行数: 222。

结构观察:

- `cli_options` 已经是跨 runtime / fixture / BTF / REJIT / daemon / perf / attach / workload 的大而全配置对象。见 `runner/include/micro_exec.hpp:43-75`。
- `daemon_pass_detail` 和 `rejit_summary` 直接把 daemon 协议细节暴露到公共 runner 头文件。见 `runner/include/micro_exec.hpp:112-140`。
- `sample_result` 又把 timing、code size、perf、rejit、correctness 打在一起。见 `runner/include/micro_exec.hpp:143-166` 附近。

结论:

- 文件不算很长，但它是跨模块耦合的总入口头。
- 它不是“一个类过大”，而是“一个公共接口层承载了太多不相关模式的共享状态”。

### Runner 超长函数列表（>100 行）

#### `runner/src/kernel_runner.cpp`

| 函数 | 行号 | 长度 |
| --- | --- | --- |
| `read_nominal_tsc_freq_hz()` | `runner/src/kernel_runner.cpp:119-239` | 121 |
| `load_map_fixtures()` | `runner/src/kernel_runner.cpp:882-1059` | 178 |
| `run_mixed_syscall_fallback()` | `runner/src/kernel_runner.cpp:2007-2189` | 183 |
| `execute_prepared_kernel_attach()` | `runner/src/kernel_runner.cpp:2561-2665` | 105 |
| `execute_prepared_kernel_run()` | `runner/src/kernel_runner.cpp:2667-2974` | 308 |
| `prepare_kernel()` | `runner/src/kernel_runner.cpp:2978-3141` | 164 |
| `run_kernel()` | `runner/src/kernel_runner.cpp:3174-3650` | 477 |
| `run_kernel_attach()` | `runner/src/kernel_runner.cpp:3657-3841` | 185 |

#### `runner/src/batch_runner.cpp`

| 函数 | 行号 | 长度 |
| --- | --- | --- |
| `run_batch_cli()` | `runner/src/batch_runner.cpp:1821-1927` | 107 |

注: `batch_runner.cpp` 的其他函数虽然没超过 100 行，但模块整体仍然过宽，问题主要在职责堆叠与重复协议代码。

#### `runner/src/common.cpp`

| 函数 | 行号 | 长度 |
| --- | --- | --- |
| `parse_args()` | `runner/src/common.cpp:506-664` | 159 |
| `parse_keep_alive_request()` | `runner/src/common.cpp:666-842` | 177 |
| `print_sample_json()` | `runner/src/common.cpp:844-972` | 129 |

### Daemon 文件统计

`wc -l daemon/src/*.rs daemon/src/**/*.rs` 当前结果如下:

| 文件 | 行数 |
| --- | --- |
| `daemon/src/bpf.rs` | 2254 |
| `daemon/src/commands.rs` | 1756 |
| `daemon/src/elf_parser.rs` | 1063 |
| `daemon/src/insn.rs` | 600 |
| `daemon/src/invalidation.rs` | 378 |
| `daemon/src/kfunc_discovery.rs` | 989 |
| `daemon/src/main.rs` | 151 |
| `daemon/src/pass.rs` | 2015 |
| `daemon/src/profiler.rs` | 621 |
| `daemon/src/server.rs` | 404 |
| `daemon/src/test_utils.rs` | 497 |
| `daemon/src/verifier_log.rs` | 585 |
| `daemon/src/analysis/branch_target.rs` | 129 |
| `daemon/src/analysis/cfg.rs` | 244 |
| `daemon/src/analysis/liveness.rs` | 274 |
| `daemon/src/analysis/map_info.rs` | 497 |
| `daemon/src/analysis/mod.rs` | 22 |
| `daemon/src/passes/bounds_check_merge.rs` | 1020 |
| `daemon/src/passes/branch_flip.rs` | 1110 |
| `daemon/src/passes/bulk_memory.rs` | 1372 |
| `daemon/src/passes/cond_select.rs` | 1129 |
| `daemon/src/passes/const_prop.rs` | 726 |
| `daemon/src/passes/dangerous_helper_firewall.rs` | 760 |
| `daemon/src/passes/dce.rs` | 289 |
| `daemon/src/passes/endian.rs` | 989 |
| `daemon/src/passes/extract.rs` | 871 |
| `daemon/src/passes/live_patch.rs` | 1334 |
| `daemon/src/passes/map_inline.rs` | 2905 |
| `daemon/src/passes/mod.rs` | 1836 |
| `daemon/src/passes/rotate.rs` | 832 |
| `daemon/src/passes/skb_load_bytes.rs` | 871 |
| `daemon/src/passes/spectre.rs` | 696 |
| `daemon/src/passes/utils.rs` | 407 |
| `daemon/src/passes/wide_mem.rs` | 1615 |

其中，超过 500 行的文件有:

| 文件 | 行数 |
| --- | --- |
| `daemon/src/passes/map_inline.rs` | 2905 |
| `daemon/src/bpf.rs` | 2254 |
| `daemon/src/pass.rs` | 2015 |
| `daemon/src/passes/mod.rs` | 1836 |
| `daemon/src/commands.rs` | 1756 |
| `daemon/src/passes/wide_mem.rs` | 1615 |
| `daemon/src/passes/bulk_memory.rs` | 1372 |
| `daemon/src/passes/live_patch.rs` | 1334 |
| `daemon/src/passes/cond_select.rs` | 1129 |
| `daemon/src/passes/branch_flip.rs` | 1110 |
| `daemon/src/elf_parser.rs` | 1063 |
| `daemon/src/passes/bounds_check_merge.rs` | 1020 |
| `daemon/src/kfunc_discovery.rs` | 989 |
| `daemon/src/passes/endian.rs` | 989 |
| `daemon/src/passes/extract.rs` | 871 |
| `daemon/src/passes/skb_load_bytes.rs` | 871 |
| `daemon/src/passes/rotate.rs` | 832 |
| `daemon/src/passes/dangerous_helper_firewall.rs` | 760 |
| `daemon/src/passes/const_prop.rs` | 726 |
| `daemon/src/passes/spectre.rs` | 696 |
| `daemon/src/profiler.rs` | 621 |
| `daemon/src/insn.rs` | 600 |
| `daemon/src/verifier_log.rs` | 585 |

结论:

- daemon 的大文件问题不是个别文件，而是系统性问题。
- `map_inline.rs` 2905 行，已经明显超过“一个 pass 文件”的合理体量。

### `map_inline.rs` 是否需要拆分

结论: 需要，而且优先级很高。

它现在把这些东西都塞在一个文件里:

- site 扫描: `daemon/src/passes/map_inline.rs:76-96`
- key 提取: `daemon/src/passes/map_inline.rs:98-120`, `daemon/src/passes/map_inline.rs:787-1049`
- 主 pass 调度与 skip reason 记录: `daemon/src/passes/map_inline.rs:147-417`
- live map value read / rewrite 构建: `daemon/src/passes/map_inline.rs:498-640`
- 日志/diagnostic helper: `daemon/src/passes/map_inline.rs:1148-1175`
- 大量测试: `daemon/src/passes/map_inline.rs:1750` 之后的大段区域

建议最少拆成:

1. `map_inline/mod.rs`
2. `map_inline/scan.rs`
3. `map_inline/key.rs`
4. `map_inline/rewrite.rs`
5. `map_inline/tests.rs`

### `server.rs` 是否职责过多

结论: 是，虽然只有 404 行，但职责边界已经混在一起。

目前混合了:

- socket server 生命周期: `daemon/src/server.rs:57-104`
- per-client 读写与 JSON 解析: `daemon/src/server.rs:106-136`
- 协议分发: `daemon/src/server.rs:139-192`
- watch/polling/invalidation loop: `daemon/src/server.rs:196-324`

这意味着:

- `serve` 和 `watch` 两个运行模式共居一个文件。
- transport、protocol、scheduler 三层没有拆开。

### `commands.rs` 是否是 God Module

结论: 是。

它同时承载:

- `OptimizeOneResult` / `PassDetail` / `AttemptRecord` 等返回 schema: `daemon/src/commands.rs:16-148`
- invalidation tracker 包装与 map-inline 追踪: `daemon/src/commands.rs:157-266`
- 子命令入口: `daemon/src/commands.rs:439-647`
- optimize/apply 核心执行引擎 `try_apply_one()`: `daemon/src/commands.rs:654-1149`

`try_apply_one()` 本身又把这些事缠在一起:

- live program 元数据获取
- map id 获取与 map-fd relocation
- pipeline 执行
- REJIT 调用
- verifier retry / attribution / disable-pass 回退
- invalidation tracking refresh
- 最终 JSON 结果构造

这就是典型的 God Module + God Function。

### 耦合分析

#### 1. runner 和 daemon 的接口是什么

接口是 Unix socket 上的换行分隔 JSON 协议。

协议实现:

- daemon 服务端: `daemon/src/server.rs:123-145`, `daemon/src/server.rs:147-192`
- runner 单次 client: `runner/src/kernel_runner.cpp:1411-1511`
- batch client: `runner/src/batch_runner.cpp:703-791`

#### 2. 这个协议有没有 schema / 文档

结论: 有人类文档，没有共享 schema。

- 有 README 文档: `daemon/README.md:57-82`
- 没有共享 IDL / JSON schema / 生成代码
- request 是手工字符串拼接:
  - `runner/src/kernel_runner.cpp:1411-1414`
  - `runner/src/batch_runner.cpp:729-730`
- response 是手工字符串扫描解析:
  - `runner/src/kernel_runner.cpp:1177-1409`
  - `runner/src/batch_runner.cpp:465-701`

这本质上仍然是 ad-hoc protocol。

#### 3. `corpus/modes.py` 和 runner C++ 的接口是什么

对 corpus batch 路径来说，接口不是 daemon socket，而是:

- Python dict batch plan
- 写成 YAML `spec.yaml`
- 调用 `micro_exec run-batch`
- runner 再产出 `result.json`

证据:

- corpus 组装 plan: `corpus/modes.py:1504-1678`
- Python wrapper 写 YAML 并调用 `run-batch`: `runner/libs/batch_runner.py:29-58`
- C++ 解析 batch spec: `runner/src/batch_runner.cpp:1165-1277`

补充:

- `micro_exec` 另有 keep-alive stdin/stdout JSON 协议，但 corpus batch 模式不走那条路径。见 `runner/src/main.cpp:34-100` 与 `runner/src/common.cpp:666-842`。

#### 4. 多层间接调用是否让 debug 变难

结论: 是，而且这正是 `map_inline` 难 debug 的核心原因之一。

实际链路是:

```text
corpus/modes.py
  -> runner/libs/batch_runner.py
  -> spec.yaml
  -> micro_exec run-batch
  -> runner/src/batch_runner.cpp
  -> runner/src/kernel_runner.cpp
  -> Unix socket JSON
  -> daemon/src/server.rs
  -> daemon/src/commands.rs::try_apply_one()
  -> PassManager / MapInlinePass
  -> JSON response
  -> runner 手工解析为 rejit_summary/pass_details
  -> result.json
  -> corpus/modes.py 再做 sanitize
```

几个具体的 debug 难点:

- daemon 协议只传 `prog_id`，不传显式 map binding，所以 map 绑定是假设 + 本地重建，不是协议级可见数据。见 `daemon/src/commands.rs:740-753`, `daemon/src/pass.rs:178-203`。
- runner 有两套几乎重复的 daemon response parser。见 `runner/src/kernel_runner.cpp:1348-1409` 与 `runner/src/batch_runner.cpp:641-688`。
- runner 会保留 `pass_details`，但默认仍会去掉完整 `daemon_response`。见 `runner/src/common.cpp:957-964`, `runner/src/batch_runner.cpp:1757-1770`。
- `corpus/modes.py` 会进一步递归删除 `daemon_response`。见 `corpus/modes.py:1162-1176`, `corpus/modes.py:1243-1246`。

这里要特别校正一点:

- 现在不是“所有 map_inline debug 信息都丢了”。
- `kernel_runner.cpp` / `batch_runner.cpp` 已经把 `passes[].skip_reasons` 和 `passes[].diagnostics` 提取为 `pass_details`，这些信息会继续出现在 runner 结果里。见 `runner/src/kernel_runner.cpp:1348-1395`, `runner/src/batch_runner.cpp:641-688`, `runner/src/common.cpp:68-90`, `runner/src/common.cpp:957-958`, `runner/src/batch_runner.cpp:1458-1467`。
- 但完整 `OptimizeOneResult` 里还有 `attempts`、`timings_ns`、`inlined_map_entries`、`error_message` 等 richer context。见 `daemon/src/commands.rs:21-34`。这些字段默认不会完整穿透到 corpus 最终产物里。

所以更准确的说法是:

- 当前链路不会把所有 skip 原因都丢掉。
- 但它确实会丢掉最完整的 daemon 端原始上下文，使 post-mortem 调试变得更难。

## 具体重构建议（按优先级排序）

### P0

1. 给 runner/daemon 协议引入共享 schema。
   目标: 不再靠字符串拼接 request、字符串扫描 response。
   最小版本: 明确定义 request/response struct，并在 Rust/C++/Python 三端共享字段约束。

2. 在 protocol 或 debug 输出里显式暴露 map binding。
   目标: 让 `old_fd -> map_id` 不再只是 daemon 内部的顺序假设。
   最小版本: 把 `map_fd_bindings` 或每个 map reference 的 `(pc, old_fd, map_id)` 放进 `OptimizeOneResult`。

3. 拆 `map_inline.rs`。
   原因: 2905 行已经妨碍定位问题，尤其是“site 发现 / key 提取 / live read / rewrite”几类失败缠在一起。

### P1

4. 拆 `commands.rs`。
   建议拆成:
   - `commands/result.rs`
   - `commands/invalidation.rs`
   - `commands/optimize.rs`
   - `commands/cli.rs`

5. 抽出统一的 runner daemon client。
   目标: `kernel_runner.cpp` 与 `batch_runner.cpp` 不再各自实现 socket client、JSON parser、pass-detail parser。

6. 拆 `kernel_runner.cpp`。
   建议拆成:
   - `daemon_client.cpp`
   - `prepared_kernel.cpp`
   - `kernel_load.cpp`
   - `kernel_measure.cpp`
   - `kernel_attach.cpp`
   - `fixture_loader.cpp`

### P2

7. 拆 `common.cpp`。
   建议拆成:
   - `cli_args.cpp`
   - `keep_alive_protocol.cpp`
   - `json_output.cpp`

8. 缩小 `micro_exec.hpp`。
   把 `cli_options`、batch schema、result schema、daemon transport structs 分头。

9. 保留更完整的 daemon 调试信息。
   既然 `pass_details` 已经单独提取了，下一步应把 `attempts` / `inlined_map_entries` / `timings_ns` 也变成结构化字段，而不是只在 raw `daemon_response` 里存在。

## 哪些耦合问题直接导致了 `map_inline` 难以 debug

1. `prog_id` 是 runner->daemon 的唯一上下文字段，map 绑定依赖 daemon 本地重建。

2. `commands.rs::try_apply_one()` 把“map-inline 产出 0 rewrites”“REJIT 是否执行”“invalidation restore”“verifier retry”揉在一个函数里，导致 no-hit 与 apply/no-op 的边界不清。

3. `kernel_runner.cpp` 和 `batch_runner.cpp` 各自维护 daemon 协议解析逻辑，协议演进容易漂移。

4. `map_inline.rs` 本身过大，site 识别、key 提取、live lookup、rewrite 构建分散在同一文件的远距离段落中。

5. corpus 最终记录虽然还保留了 `pass_details.skip_reasons` 和 `diagnostics`，但默认不保留完整 `daemon_response`，因此丢失了 `attempts`、原始 verifier/debug trace、`inlined_map_entries` 等更细粒度上下文。

## 总结

对 `map_inline 0 hits` 这件事，源码给出的结论很清楚:

- 不是“完全没有 fd->map_id 映射逻辑”。
- 不是“ARRAY zero-value lookup 会自然失败”。
- 当前最强的功能性根因，是 `map_inline` 只支持常量栈 key；真实程序的 lookup key 往往是运行时值，因此大量 site 会在 `lookup key is not a constant stack materialization` 上被过滤掉。

对工程质量这件事，最大的结构问题也很清楚:

- runner 侧是 `kernel_runner.cpp` / `batch_runner.cpp` 两个 God File 加一堆重复协议代码。
- daemon 侧是 `commands.rs` God Module 和 `map_inline.rs` 超大 pass 文件。
- `corpus -> runner -> daemon` 这条链路跨 Python/C++/Rust 三层、协议又是 ad-hoc，导致调试成本被明显放大。
