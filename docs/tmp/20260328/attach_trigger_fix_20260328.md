# Corpus attach-trigger fix research (2026-03-28)

## TL;DR

结论是：

1. 当前 corpus benchmark 是否走 `BPF_PROG_TEST_RUN` 还是 attach-trigger，不是 `kernel_runner.cpp` 自动判定的，而是 manifest `test_method` 决定的。
2. Linux `7.0-rc2` 里，`kprobe` 和 `tracepoint` 根本没有 `test_run` handler；`raw_tracepoint` 有，`tracing` 也有，但 `tracing` 的实现是 selftest-oriented，不适合作为 corpus 的通用 fallback。
3. 当前 attach-trigger 只跑 manifest 的 `trigger_command`，或者默认 `mixed` workload。这个 workload 主要是 `getpid/read/write/openat/nanosleep` 一类通用 syscall，覆盖不到大量 `exec/socket/sched/block/mm/raw_tp` hook。
4. 旧的 `attach_trigger_unsupported_reason()` 又只把标准 `tracepoint/<category>/<name>` 当成“支持的 attach-trigger”，导致大量已经 attach 成功、理论上可触发的 `kprobe/raw_tp/fentry/lsm/tp_btf` 程序即使将来被触发，也不会进入 comparable set。

因此本次采用的是 `B + D` 组合：

- `B`: 增强 attach-trigger，在 primary workload 之后如果 `run_cnt` 仍然没有增长，就自动补跑一个 section-aware 的 syscall/file/network/mm/process trigger sweep。
- `D`: 保留明确 exclusion reason，同时把“静态支持判定”从“只认标准 tracepoint”扩展到 tracing/kprobe/raw_tp 家族，避免提前把可测程序排除掉。

没有采用 `A/C`：

- `A` 不可行，因为 `kprobe/tracepoint` 在 7.0-rc2 不支持 `test_run`。
- `C` 会把 attach timing 和 `test_run` timing 混在一起，`exec_ns` 语义不统一。

## 1. 当前 io-mode / runtime 选择逻辑

### 1.1 corpus side

`runner/libs/corpus.py` 的 batch plan 是 manifest-driven，不是 prog_type-driven：

- `resolve_manifest_object()` 直接读 object/program 上的 `test_method`、`io_mode`、`trigger`、`attach_group`
- `runtime_for_program()` 只根据 `program.test_method` 选 runtime：
  - `attach_trigger` -> `kernel-attach` / `kernel-attach-rejit`
  - 其他 measured path -> `kernel` / `kernel-rejit`
- `build_object_batch_plan_v2()` 再把这些字段原样写进 batch job

代码位置：

- `runner/libs/corpus.py:437-518`
- `runner/libs/corpus.py:1502-1505`
- `runner/libs/corpus.py:1581-1717`

`io_mode` 也是 manifest-driven：

- object/program 未显式填写时，默认是 `"context"`
- batch path 里不会再按 prog_type 重算一遍

代码位置：

- `runner/libs/corpus.py:440-444`
- `runner/libs/corpus.py:465-469`

`runner/libs/corpus.py` 里确实还有一个 `execution_plan()` helper，会按 section root 推断 `packet/context`，但当前 corpus batch 主路径并不使用它。

代码位置：

- `runner/libs/corpus.py:1159-1176`

### 1.2 runner side

runner 只吃上游下发的 runtime / attach_mode：

- keep-alive / batch job 里：
  - `kernel` -> `run-kernel`
  - `kernel-attach` -> `run-kernel-attach`
- `run_prepared_kernel()` 也是只看 `options.attach_mode`

代码位置：

- `runner/src/common.cpp:680-693`
- `runner/src/batch_runner.cpp:633-646`
- `runner/src/kernel_runner.cpp:3572-3579`

`io_mode` 在 kernel runner 里只做一个小修正：

- `resolve_effective_io_mode()` 只有在请求 `"map"` 且 `result_map` 不存在时，才回退成 `"staged"`

代码位置：

- `runner/src/kernel_runner.cpp:555-572`

### 1.3 manifest 当前分布

用 `corpus/config/macro_corpus.yaml` 统计：

- `attach_trigger`: 1536 programs
- `bpf_prog_test_run`: 415 programs
- `compile_only`: 65 programs

attach-trigger 里，和这次问题最相关的分布是：

- `kprobe`: 626
- `tracing`: 392
- `tracepoint`: 165
- `raw_tracepoint`: 111

## 2. 7.0-rc2 中 BPF_PROG_TEST_RUN 支持矩阵

### 2.1 syscall dispatch

`BPF_PROG_TEST_RUN` syscall 的核心 dispatch 很直接：

- 先拿到 `struct bpf_prog *prog`
- 然后只在 `prog->aux->ops->test_run` 非空时调用对应 handler

代码位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:5501-5524`

这意味着是否支持 `test_run`，完全取决于对应 prog type 的 `bpf_prog_ops.test_run` 是否被填了。

### 2.2 确认支持的类型

从 `7.0-rc2` 树里的 `.test_run = ...` 可见，支持 `test_run` 的主要类型包括：

- `socket_filter`
- `sched_cls` / `sched_act`
- `xdp`
- `cgroup_skb`
- `lwt_in` / `lwt_out` / `lwt_xmit`
- `flow_dissector`
- `raw_tracepoint`
- `tracing`
- `sk_lookup`
- `syscall`
- `netfilter`
- `struct_ops`

代码位置：

- `vendor/linux-framework/net/core/filter.c:11214-11346`
- `vendor/linux-framework/kernel/trace/bpf_trace.c:1797-1809`
- `vendor/linux-framework/kernel/bpf/syscall.c:7402`
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:76-81`
- `vendor/linux-framework/net/netfilter/nf_bpf_link.c:270`

### 2.3 不支持的类型

这次最关键的是：

- `kprobe_prog_ops` 是空的，没有 `.test_run`
- `tracepoint_prog_ops` 是空的，没有 `.test_run`
- `raw_tracepoint_writable_prog_ops` 也是空的

代码位置：

- `vendor/linux-framework/kernel/trace/bpf_trace.c:1369-1371`
- `vendor/linux-framework/kernel/trace/bpf_trace.c:1475-1477`
- `vendor/linux-framework/kernel/trace/bpf_trace.c:1830-1832`

所以：

- `kprobe`：7.0-rc2 不支持 `BPF_PROG_TEST_RUN`
- `tracepoint`：7.0-rc2 不支持 `BPF_PROG_TEST_RUN`
- `raw_tracepoint`：支持
- `tracing`：支持，但有很强限制

### 2.4 tracing / raw_tracepoint 的真实语义

#### raw_tracepoint

`bpf_prog_test_run_raw_tp()` 支持 synthetic `ctx_in`，要求：

- 不支持 `data_in/out`
- 不支持 `ctx_out`
- 不支持 `duration`
- 不支持 `repeat`
- `ctx_size_in >= prog->aux->max_ctx_offset`
- `ctx_size_in <= MAX_BPF_FUNC_ARGS * sizeof(u64)`

本质上它吃的是一块原始的 `u64 args[]` synthetic ctx。

代码位置：

- `vendor/linux-framework/net/bpf/test_run.c:746-797`

#### tracing

`bpf_prog_test_run_tracing()` 并不是“给任意 tracing program 一个 synthetic ctx 然后直接跑”。

它做的是：

- 对 `BPF_TRACE_FENTRY/FEXIT/FSESSION`，调用内核里硬编码的 `bpf_fentry_test1..10`
- 对 `BPF_MODIFY_RETURN`，调用硬编码的 `bpf_modify_return_test*`

也就是说它本质上是 selftest trampoline path，不是 corpus 里 arbitrary `fentry/tcp_v4_connect`、`lsm/socket_connect` 这种 hook 的通用 test_run 方案。

代码位置：

- `vendor/linux-framework/net/bpf/test_run.c:673-721`
- `vendor/linux-framework/net/bpf/test_run.c:510-583`

因此：

- `raw_tracepoint` 理论上可以考虑 future synthetic ctx path
- `tracing` 不能被看作 corpus 通用 fallback

## 3. 当前 attach-trigger 实现和为什么大多不触发

### 3.1 当前实现

attach path 在 runner 里有两份实现：

- `execute_prepared_kernel_attach()`
- `run_kernel_attach()`

核心流程一致：

1. `bpf_program__attach()`
2. `bpf_enable_stats(BPF_STATS_RUN_TIME)`
3. warmup workload
4. 记录 `before_stats`
5. 跑 measured workload
6. 记录 `after_stats`
7. 用 `run_cnt_delta` / `run_time_ns_delta` 算 `exec_ns`

代码位置：

- `runner/src/kernel_runner.cpp:2936-3064`
- `runner/src/kernel_runner.cpp:4112-4294`

### 3.2 trigger 具体做了什么

`run_attach_workload()` 的逻辑是：

- 如果 manifest 提供了 `trigger_command`，就原样 `bash -lc` 执行它
- 否则跑 `workload_type`

代码位置：

- `runner/src/kernel_runner.cpp:2468-2478`

默认 `mixed` workload 实际上并不“广”：

- 先尝试 `stress-ng`
- 如果没有 `stress-ng`，fallback 到 `run_mixed_syscall_fallback()`
- 这个 fallback 只是反复做：
  - `getpid`
  - `read(/dev/null)`
  - `write(/dev/null)`
  - `nanosleep`
  - `openat(/dev/null)`

代码位置：

- `runner/src/kernel_runner.cpp:2480-2510`
- `runner/src/kernel_runner.cpp:2581-2620`

### 3.3 为什么 miss

这套 trigger miss 大量 hook 是很自然的：

- `execve/bprm` 类 hook：默认 workload 根本不 exec
- `socket_connect/socket_accept/tcp_*` 类 hook：默认 workload 不建 loopback socket
- `sched_process_exec/sched_process_fork`：默认 workload 不 fork/exec
- `mmap/mm_vmscan/file_mprotect`：默认 workload 不做 `mmap/mprotect`
- `block/writeback`：默认 workload 没有真实文件 IO / fsync 路径
- `raw_tp/tp_btf` 类 hook 只要不在这些少量 syscall 上，就完全 miss

所以会出现：

- attach 成功
- `run_cnt_delta = 0`
- `exec_ns = 0`

## 4. 方案分析

### A. 让更多程序走 BPF_PROG_TEST_RUN

优点：

- 语义最稳定
- 不依赖真实事件

问题：

- `kprobe` / `tracepoint` 在 7.0-rc2 直接不支持
- `tracing` 的 `test_run` 不是通用 synthetic ctx 方案
- `raw_tracepoint` 虽然支持，但还需要构造合理 `ctx_in`

结论：不能作为这次主方案。

### B. 增强 attach-trigger

优点：

- 不改 kernel
- 和现有 corpus/runtime 语义一致
- 对 `kprobe/tracepoint/raw_tp/fentry/lsm` 都能提升覆盖

问题：

- 不可能覆盖所有 hook point
- 最终仍然会有 genuinely untriggerable 的程序

结论：这是这次最合理的主方案。

### C. attach 失败后 fallback 到 test_run

优点：

- 组合覆盖面更大

问题：

- attach 的 `exec_ns` 来自 `bpf_stats`
- `test_run` 的 `exec_ns` 来自 kernel test_run duration
- 不能直接混算 geomean

结论：这次不做。

### D. 诚实报告 untriggerable

这是必须保留的：

- 不能让 `exec_ns=0` 静默消失
- 要么是静态 unsupported
- 要么是 attach 后 `run_cnt_delta=0`

现有 `comparison_exclusion_reason()` 已经有这条机制，本次继续保留。

代码位置：

- `runner/libs/corpus.py:1335-1358`

## 5. 本次实现

### 5.1 kernel_runner.cpp

实现内容：

- attach measured workload 跑完后，先读一次 `after_stats`
- 如果 `run_cnt` 仍然没有增长，再按 section name 补跑一次 auto-trigger fallback
- fallback 是 bounded 的，不会按大 `repeat` 无限制放大
- fallback suite 按 section root / keyword 选组合，覆盖：
  - `exec`
  - `process/fork/wait/pipe`
  - `sched_yield/nanosleep`
  - `file open/read/write/fsync/rename/unlink`
  - `mmap/mprotect/munmap`
  - `loopback TCP socket/bind/listen/connect/accept/send/recv`
- sample 里增加一个 phase：
  - `auto_trigger_wall_ns`

代码位置：

- `runner/src/kernel_runner.cpp:1803-2243`
- `runner/src/kernel_runner.cpp:2975-3000`
- `runner/src/kernel_runner.cpp:3059-3060`
- `runner/src/kernel_runner.cpp:4189-4217`
- `runner/src/kernel_runner.cpp:4288-4289`

### 5.2 runner/libs/corpus.py

把 attach-trigger 的“静态支持判定”从“只认标准 tracepoint”扩展为：

- `tracepoint/<cat>/<name>`
- `tp/<cat>/<name>`
- `raw_tracepoint/<name>`
- `raw_tp/<name>`
- `tp_btf/<name>`
- `kprobe/*`
- `kretprobe/*`
- `ksyscall/*`
- `kretsyscall/*`
- `fentry/*`
- `fexit/*`
- `fmod_ret/*`
- `lsm/*`
- 以及 `.multi/.session/.s` 这类 auto-attach roots

仍然保持 unsupported 的典型例子：

- `tracepoint/sys_execve` 这种非标准 tracepoint section
- 以及本次没有纳入 auto-trigger 语义保证的 `uprobe/uretprobe/iter/struct_ops/...`

代码位置：

- `runner/libs/corpus.py:563-590`

### 5.3 单测

新增/更新了 Python tests，覆盖：

- 自定义 tracepoint 仍然 unsupported
- `kprobe`
- `raw_tp`
- `fentry`
- 支持的 attach-trigger 在 `run_cnt=0` 时，reason 应该走 “did not fire … (run_cnt_delta=0)” 而不是静态 unsupported

代码位置：

- `tests/python/test_corpus_modes.py`

## 6. 静态 coverage 变化

用当前 `macro_corpus.yaml` 统计 attach-trigger programs：

- 总 attach-trigger programs: `1536`
- 旧规则（只认标准 `tracepoint/<cat>/<name>`）可视为 supported 的：`111`
- 新规则可视为 supported 的：`1060`
- 净增加：`+949`

新增进入“可尝试触发”集合的主要 root：

- `kprobe`: `+224`
- `tp_btf`: `+188`
- `fentry`: `+128`
- `kretprobe`: `+102`
- `fexit`: `+65`
- `raw_tp`: `+58`
- `lsm`: `+51`
- `raw_tracepoint`: `+45`
- `tp`: `+33`

这不代表都一定会被触发，但至少不再被静态规则提前排除。

## 7. 验证

已执行：

- `python -m pytest tests/python/test_corpus_modes.py tests/python/test_runner_results.py -q`
  - `12 passed`
- `make runner`
  - 通过
- `make smoke`
  - 通过

未执行：

- full / guest corpus smoke

原因：

- 本次环境下我是普通用户（`uid=1000`），attach runtime 的有效验证更适合走 guest/root kernel path
- 在本轮里优先保证修复最小化、语义正确和基础构建/单测通过

## 8. 风险和后续建议

仍然存在的边界：

1. auto-trigger 只能覆盖“常见 kernel event families”，不能覆盖全部 hook。
2. `raw_tracepoint` 未来仍可单独研究 synthetic `ctx_in` test_run path，但需要决定 ctx shape 策略。
3. `uprobe/uretprobe/iter/struct_ops/cgroup/...` 是否该纳入 attach-trigger 支持，需要单独逐类建 trigger 语义，而不是这次一刀切放开。

下一步建议：

1. 在 guest 上挑一个小批次验证：
   - `kprobe/*exec*`
   - `tracepoint/syscalls/*`
   - `raw_tp/sched_*`
   - `fentry/*socket*`
2. 统计 `run_cnt_delta=0` 在这些 family 上的下降幅度。
3. 如果 `raw_tp` 还有明显零命中，再考虑专门的 synthetic `ctx` test_run path。
