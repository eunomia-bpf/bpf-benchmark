# Corpus Benchmark 框架如何改进，才能正确评估 Map Inlining 与其他 Runtime-Dependent Optimization

## 结论先行

当前 corpus 框架还不能严肃评估 runtime-dependent optimization，尤其不能作为 dynamic map inlining 的有效证据。核心原因不是某一个 pass 没写完，而是 **benchmark orchestration 本身没有保证 optimize 时看到的 runtime state，与 stock/rejit measurement 时看到的是同一份 state**。

最关键的几个现状结论：

- `strict corpus` 路径在 `corpus/modes.py:985-1025` 只保留了 `program_name / io_mode / input_size / test_input / can_test_run`，把 `trigger`、`trigger_timeout_seconds`、`compile_loader`、`program_names[1:]` 等信息都丢掉了。也就是说，`macro_corpus.yaml` 里的 attach 语义并没有被忠实执行。
- `attach_trigger` 目标并不会执行 YAML 里声明的 trigger；当前实际走的是 `run_kernel_attach()` 里的通用 workload，默认 `workload_type="mixed"`、`workload_iterations=2`、`warmup_repeat=5`，即大致是 “2 秒 warmup + 2 秒测量”的泛化 stress workload，而不是 `bpftool prog show` / `execve` / `fio` / 应用真实控制面事件。
- `bpf_prog_test_run` 的 REJIT 路径中，daemon 在 `rejit_compile` 阶段就读取 map 值并优化；但 `input_map` 写入、`result_map` 清零、Katran fixture 初始化都发生在后面的实际执行阶段。也就是说，**optimize 时看见的是未填充 map**。
- `attach_trigger` 的 REJIT 路径中，daemon 也是在 attach 之前、workload 之前优化；因此 workload 后续写出来的 map 状态并不参与 specialization。
- corpus 里的 stock 和 rejit 不是 “同一程序实例、同一 map snapshot、只改代码”的 paired comparison，而是两次独立 fresh load。对 runtime-dependent optimization 来说，这个比较本身就不成立。
- 当前 `map_inline` 实现仍是 v1：只允许 `frozen && direct-value-access` map（`daemon/src/analysis/map_info.rs:55-62`，`daemon/src/passes/map_inline.rs:173-179`）。所以今天的 corpus 结果最多能说明 frozen-like 场景，**不能支撑 `dynamic map inlining + invalidation` 这个 OSDI 论文主 story**。

因此，如果目标是 OSDI 论文中“map 稳定 -> inline -> invalidation -> re-REJIT”的 story，那么 benchmark 侧至少需要：

1. 恢复 target 真实 trigger / multi-program attach 语义。
2. 把 correctness 和 performance 明确拆开。
3. 引入 pre-populated fixture 与 snapshot/restore，保证 stock/rejit 看到同一份 map state。
4. 对 flagship workload 做 E2E map-state verification，而不是默认把 perf pair 当 correctness 证据。

下面按问题逐项回答。

---

## 1. 当前 Corpus Measurement Flow

### 1.1 全局流程：strict corpus 实际上如何运行

`strict corpus` 的 VM 批量路径大致是：

1. `corpus/modes.py:253-263` 启动一个常驻 daemon：`bpfrejit-daemon --pgo serve --socket ...`
2. `corpus/modes.py:985-1025` 从 `macro_corpus.yaml` 读取 target，但只保留少量字段：
   - `object_path`
   - `program_name`，若是 `program_names` 列表则只取第一个（`1000-1002`）
   - `io_mode`
   - `input_size`
   - `test_input`
   - `can_test_run = (test_method == "bpf_prog_test_run")`
3. `corpus/modes.py:483-693` 把 target 展开为 batch job
4. `runner/src/batch_runner.cpp:1107-1123` 把 runtime 映射为：
   - `kernel` -> `run-kernel`
   - `kernel-rejit` -> `run-kernel` + `rejit=true`
   - `kernel-attach` -> `run-kernel-attach`
   - `kernel-attach-rejit` -> `run-kernel-attach` + `rejit=true`
5. `runner/src/batch_runner.cpp:1479-1495` 真正执行 `run_kernel` / `run_prepared_kernel` / `run_kernel_attach`

一个很重要的前置发现是：

- `load_targets_from_yaml()` 根本没有保留 `trigger`、`trigger_timeout_seconds`、`compile_loader`、`workload_type`、`program_names[1:]`。
- 所以严格来说，当前 corpus 不是在执行 `macro_corpus.yaml` 声明的 attach workflow，而是在执行一个“只有 `can_test_run` 这个布尔开关”的降维版 workflow。

### 1.2 单个 `bpf_prog_test_run` target 的实际顺序

对单个 `can_test_run=true` target，batch plan 是在 `corpus/modes.py:520-667` 构造出来的。逻辑顺序是：

1. `baseline_compile`
   - `runtime="kernel"`
   - `compile_only=True`
   - 走 `prepare_kernel()`，但不执行程序
   - 若 target 可 test_run，则把 prepared state 存下来（`prepared_key`）

2. `baseline_run`
   - `runtime="kernel"`
   - `compile_only=False`
   - 使用 `prepared_ref` 复用 `baseline_compile` 的 prepared image
   - 实际执行 stock measurement

3. `pgo_warmup`
   - 只对 `can_test_run=true` target 生成
   - `runtime="kernel"`
   - `repeat=10`
   - 这是一个**独立 fresh load 的 stock job**，不是沿用 `baseline_run` 或 `rejit_compile` 的那份程序实例

4. `rejit_compile`
   - `runtime="kernel-rejit"`
   - `compile_only=True`
   - fresh load 另一份 object
   - 立即通过 daemon socket 执行 optimize
   - prepared 后等待后续 `rejit_run`

5. `rejit_run`
   - `runtime="kernel-rejit"`
   - `compile_only=False`
   - 复用 `rejit_compile` 那份已经 optimize 过的 prepared image
   - 实际执行 rejit measurement

也就是说，用户问题里的“load -> stock measure -> daemon optimize -> rejit measure”在当前实现里更精确地写应当是：

```text
load(stock, compile-only)
-> stock measure
-> optional stock pgo_warmup on another fresh instance
-> load(rejit, compile-only)
-> daemon optimize on that fresh instance
-> rejit measure
```

### 1.3 单个 `attach_trigger` target 的实际顺序

对 `can_test_run=false` target，`build_target_batch_plan()` 在 `corpus/modes.py:573-587` 和 `670-684` 生成的是：

1. `baseline_run`
   - `runtime="kernel-attach"`
   - fresh load object
   - 只 autoload 选中的一个 program（`runner/src/kernel_runner.cpp:1011-1020`, `2814-2826`）
   - attach
   - warmup workload
   - 读 `bpf_stats` before
   - measured workload
   - 读 `bpf_stats` after
   - detach

2. `rejit_run`
   - `runtime="kernel-attach-rejit"`
   - fresh load object
   - daemon optimize
   - attach
   - warmup workload
   - 读 `bpf_stats` before
   - measured workload
   - 读 `bpf_stats` after
   - detach

`run_kernel_attach()` 的关键顺序在 `runner/src/kernel_runner.cpp:2836-2904`：

```text
load
-> daemon optimize (only rejit path)
-> attach
-> warmup workload
-> stats snapshot before measured workload
-> measured workload
-> stats snapshot after measured workload
-> detach
```

### 1.4 attach 路径的 workload 不是 YAML trigger，而是通用 mixed workload

这里有一个比 map state 更基础的问题：**attach target 当前根本没有执行 YAML 声明的 trigger**。

证据：

- `macro_corpus.yaml` 里 390 个 `attach_trigger` entry 都有 `trigger` 字段；但 `load_targets_from_yaml()` 没保留它。
- `batch_runner` 也没有 `trigger` 字段，只会解析 `workload_type` / `workload_iterations`（`runner/src/batch_runner.cpp:1154-1155`）。
- `cli_options` 的默认值是 `workload_type="mixed"`、`workload_iterations=2`（`runner/include/micro_exec.hpp:69-71`）。
- `run_kernel_attach()` 使用的正是 `run_workload(options.workload_type, ...)`（`runner/src/kernel_runner.cpp:2881-2899`）。

因此当前 attach path 的默认真实执行是：

- warmup：约 2 秒 `mixed`
- measured：约 2 秒 `mixed`

而 `mixed` 本质上就是 `stress-ng` 或其 syscall fallback（`runner/src/kernel_runner.cpp:1682-1721`），并不是 target-specific trigger。

这意味着：

- `systemd_sysctl_monitor` 并没有真的执行 `cat /proc/sys/...`
- `tetragon_execve` 并没有真的跑 YAML 里写的 `for i in $(seq 200); do /bin/true; done`
- `tracee_lsm_bpf` 也没有真的跑它声明的 `bpftool prog show`

换言之，当前 attach corpus 对“真实应用怎样把 map 填起来”的建模非常弱。

### 1.5 daemon 何时读取 map 值

`serve` 模式只是对每个 `optimize` 请求调用一次 `try_apply_one()`（`daemon/src/server.rs:103-130`）。

在 `try_apply_one()` 里：

1. 先拿 live prog fd / original insns / map IDs（`daemon/src/commands.rs:591-668`）
2. 再跑 pipeline：`pm.run_with_profiling(...)`（`687-690`）
3. `map_inline` 在 pipeline 内部调用 `bpf_map_lookup_elem_by_id()` 读取 live map value（`daemon/src/passes/map_inline.rs:413-418`）

所以 daemon 读取 map 值的时刻是：

- 在 optimize syscall 期间
- 在 `BPF_PROG_REJIT` 之前
- 在 measurement 之前
- 读的是“当时那份 fresh live program 所关联的 map”

对当前 corpus 而言，这个时间点非常不利，因为很多 map state 都是在后面才被写进去的。

---

## 2. Map State During Corpus Runs

### 2.1 `test_run` target：map 是怎么被填的

当前 `test_run` 路径里，runner 会主动写的 map 其实只有两类：

1. `input_map`
   - 在真正执行前写入 key `0`
   - 代码在 `runner/src/kernel_runner.cpp:1885-1914`（prepared path）和 `2517-2546`（non-prepared path）

2. `result_map`
   - 在执行前先写 `0`
   - 在每次 `bpf_prog_test_run_opts()` 前还会 reset 成 `0`
   - 代码在 `1885-1927` / `2517-2559`，以及 reset 逻辑 `372-402`

这两个事实非常重要：

- `input_map` 的写入发生在 **daemon optimize 之后**
- `result_map` 的 reset 也发生在 **daemon optimize 之后**

因此，如果未来 dynamic map inlining 想 inline 的正好是 `input_map` 之类的 map，那么当前 corpus 路径是明显错误的：optimize 看见的是空 map，执行看见的是填过值的 map。

另外，322 个 `bpf_prog_test_run` target 里：

- 49 个有 `test_input`
- 273 个没有 `test_input`

没有 `test_input` 时，`materialize_memory()` 返回的是全零 buffer；也就是说这 273 个 target 的输入本身就是 zero-filled synthetic input，而不是 workload capture。

### 2.2 Katran fixture 是唯一显式 map fixture，但 optimize 时仍然看不到它

runner 里唯一显式 map fixture 是 Katran：

- `runner/src/kernel_runner.cpp:237-240`：只要 `program_name == "balancer_ingress"` 就认为需要 fixture
- `runner/src/kernel_runner.cpp:325-360`：向 `ctl_array` / `vip_map` / `reals` / `ch_rings` 写入固定值

但 corpus 的 `test_run` REJIT 路径里，这个 fixture **不会在 optimize 前生效**：

- `prepare_kernel()` 只有在 `!options.compile_only` 时才初始化 Katran fixture（`runner/src/kernel_runner.cpp:2221-2224`）
- 而 `rejit_compile` 明确是 `compile_only=True`（`corpus/modes.py:617-642`）
- 同一个 `prepare_kernel()` 里，daemon optimize 恰恰发生在 `compile_only && rejit` 分支（`runner/src/kernel_runner.cpp:2266-2285`）

所以对于 corpus 真正使用的 `prepared` REJIT 路径：

```text
fresh load
-> daemon optimize
-> later, in rejit_run, fixture is initialized
-> warmup + measure
```

这意味着：

- stock measurement 看到的是 fixture-populated Katran map
- rejit optimize 看到的是 empty/default Katran map
- rejit measurement 又看到 fixture-populated Katran map

所以 **连唯一的显式 fixture target 也没有做到 “optimize 与 measurement 看到同一份 map state”**。

### 2.3 其他 test_run target：除 input/result map 以外，几乎没有统一的 map 预填充

除 Katran balancer 之外，当前 runner 没有通用 fixture loader。

因此其他 map 只能来自：

- ELF 初始值 / libbpf 自动初始化的 data maps
- 程序在 warmup/run 过程中自己写出来的内容
- 某些 helper 或 kernel side effect

但框架没有记录：

- 哪张 map 被填了
- 写入前后是什么值
- optimize 时读到的到底是不是非零、有意义、稳定的 data

### 2.4 test_run 内部 warmup 会改变 map state，而且这些变化会保留下来

`execute_kernel_measurement_pass()` 会先跑 warmup，再跑 measured pass（`runner/src/kernel_runner.cpp:444-457`）。

而每次 reset 时，runner 只会清：

- output packet buffer
- `ctx_out`
- `result_map`

见 `runner/src/kernel_runner.cpp:372-402`。

也就是说，**程序自己写进其他 map 的内容会跨 warmup 持续存在**。因此即便 stock/rejit 各自都在 fresh instance 上运行，它们 measured pass 看到的也不是“初始 fixture state”，而是“经过 5 次 warmup 之后的 state”。

### 2.5 `attach_trigger` target：workload 确实可能把 map 填起来，但太晚了

attach path 中，map state 的时间线是：

```text
fresh load
-> daemon optimize (rejit only)
-> attach
-> warmup workload
-> measured workload
```

因此：

- attach workload 期间，BPF 程序当然可能更新自己的统计/过滤/缓存 map
- 这些 map 在 warmup 结束后很可能已经非零
- 但 daemon optimize 发生在 attach/workload 之前，因此 specialization 根本没有看到这些值

这对 dynamic map inline 尤其致命：

- 如果目标 map 是 config/policy map，而 workload 并没有在 optimize 前把它们设好，那么优化是对 empty/default state 做的
- 如果目标 map 是程序 runtime 自己写的 map，那么 optimize 读到的也是 cold empty state，后面 warmup/workload 又把它改了

### 2.6 多程序 attach object 还被压成了 “只测第一个 program”

在 `macro_corpus.yaml` 中，很多 attach target 声明的是一个 multi-program pipeline。例如 Tetragon、Tracee、xdp-tools 里常见 `program_names: [...]`。

但 strict loader 在 `corpus/modes.py:999-1002` 只取 `program_names[0]`。
再配合 `configure_autoload()`（`runner/src/kernel_runner.cpp:1011-1020`），最后实际只 autoload 一个 program。

我对 YAML 做了简单计数：

- 390 个 `attach_trigger` entry 中
- 228 个是 multi-program entry
- 当前 strict corpus 全部被压成单程序测量

这会带来两个问题：

1. 原本 pipeline 内其他程序负责建立/维护的 map state 不见了
2. 你以为在测 “Tracee/Tetragon pipeline”，其实往往只测到第一个 handler

### 2.7 哪些 target 可确认存在“真实非零 map 数据”

如果把“真实非零 map 数据”分层来看：

#### A. optimize 时可确认存在的非零 runtime map

当前框架下，**几乎无法确认有哪一类 mutable runtime map 在 optimize 时就已经是非零且有意义的**。

原因：

- `input_map` 是 optimize 后才写
- Katran fixture 是 corpus 实际 REJIT 路径里 optimize 后才写
- attach workload 是 optimize 后才跑

因此，当前框架里“optimize 时 guaranteed non-zero”的集合，基本只能保守地说：

- 可能存在少量 ELF 初始化 map / libbpf global-data map
- 但框架没有 telemetry 去识别它们

#### B. measurement 时可确认存在的非零 map

这个集合更大一些：

- Katran stock/rejit execution phase 会看到 fixture data
- 很多 attach target 的 warmup/workload 之后，程序内部 stats/histogram/filter/cache map 很可能变成非零

但这并不能回答 dynamic specialization 的 correctness 问题，因为 optimize 并没有用这些值。

### 2.8 11556 个 `map_lookup_elem` site 里，有多少真的在测试时对应到非零 map data？

严格答案是：

- **当前框架无法给出精确数字**

原因不是统计难，而是框架根本没记这件事：

- 没有 “site -> map -> key -> optimize-time value” telemetry
- 没有 “measurement window 前后 map state” telemetry
- 没有 “这个 target 实际执行了 YAML trigger 还是 generic mixed workload” telemetry

如果按不同口径给一个保守判断：

1. **按 optimize-time non-zero state 口径**
   - guaranteed coverage 近似为 0
   - 因为 runner 显式填 map 的动作几乎都发生在 optimize 之后

2. **按 measurement-time non-zero state 口径**
   - 肯定大于 0，因为 attach warmup/workload 和部分 test_run 会把某些 map 写成非零
   - 但这个数字对 map inline 验证并没有决定意义，因为这些值不是 optimize 时读到的值

3. **按“有意义的 control-plane/config map 在 optimize 与 measurement 期间都非零且稳定”口径**
   - 目前可以认为 coverage 极低，远远不是 11556 site 中的主流

因此，如果要把 11556 site 当论文卖点，当前 benchmark framework 还没有资格说“这些 site 里有多少在 corpus 中被真实 state 覆盖到了”。

---

## 3. Problems with Current Approach

### 3.1 当前 `stock vs rejit` 配对比较对 runtime-dependent optimization 并不成立

`corpus` 当前的比较不是：

```text
同一程序实例 + 同一 map snapshot + 只改代码
```

而是：

```text
stock: fresh load A
rejit: fresh load B
```

其中：

- `bpf_prog_test_run` 用的是两份不同 prepared image
- `attach_trigger` 用的是两次不同 fresh load

因此只要 optimization 依赖 runtime state，这个比较就不再是干净的 paired comparison。

### 3.2 如果 map 为空，inline 出来的只是 “空场景常量”，不是你真正想测的优化

这会产生两类假象：

1. **伪正确**
   - 空 map / default zero state 下，替换成 `MOV 0` 看起来没问题
   - 但真实部署里 map 可能有非零配置值，真正会走另一条 branch

2. **伪收益**
   - 你测到的是“把空场景特化成常量”的收益
   - 不是“把真实 control-plane data 特化成常量”的收益

这对 dynamic map inlining 尤其危险，因为 paper 真正想讲的是：

- 低 churn config/policy/routing map
- 在真实稳定值下触发 null-check elimination + branch/DCE cascade

而不是“空 map 时 helper 恰好返回零”的 trivial path。

### 3.3 如果 map 在 optimize 后、measurement 前变化，当前框架会产生严重 false positive

当前 corpus 里这类窗口非常多：

- `input_map`：optimize 后才写
- Katran fixture：corpus REJIT prepared path 里 optimize 后才写
- attach warmup/workload：optimize 后才产生 map update
- test_run warmup：optimize 后执行，程序自己也可能写 map

这意味着 rejit code 很可能是在：

- 用 stale snapshot 生成的常量
- 跑在已经变化过的 map state 上

而当前框架几乎不会发现这一点。

### 3.4 correctness 检查几乎不存在，或者过于弱

#### `bpf_prog_test_run` daemon mode

在 daemon-socket mode 下，runner 明确跳过 in-process stock+rejit paired measurement（`runner/src/kernel_runner.cpp:2416-2451`，prepared path 对应 `2054-2057`）。

也就是说 corpus 真正使用的 daemon REJIT 路径里：

- 没有同实例 stock/rejit 结果对比
- 只有分开的 baseline_run 与 rejit_run

#### 即使在 same-image mode，可用的 correctness check 也只比 `retval`

`run_prepared_kernel()` 和 `run_kernel()` 在 same-image path 下的 correctness compare 只比较：

- `stock_sample->retval`
- `sample.retval`

见 `runner/src/kernel_runner.cpp:2152-2163` 和 `2775-2786`。

它并不会比较：

- `sample.result`
- output packet bytes
- `ctx_out`
- output maps

这会产生典型 false positive：

- 返回码一样
- 实际数据结果不同
- runner 仍认为“correct”

#### attach mode 完全没有 semantic oracle

`run_kernel_attach()` 返回的 `sample.result` 其实只是 `run_cnt_delta`（`runner/src/kernel_runner.cpp:2957-2958`），并不是业务语义输出。

因此 attach path 目前只能说：

- 这个 program 被调用了多少次
- 平均每次 `run_time_ns` 是多少

却不能说：

- rejit 后语义是否等价

### 3.5 false positives：看起来没问题，其实 map inline 可能已经错了

当前框架最典型的 false positive 有：

1. map 为空，inline 成 `MOV 0`，stock/rejit 都“看起来正常”
2. optimize 后 workload 才把 map 填成非零，rejit 在 stale constant 上运行，但 attach path 没有语义校验
3. same-image correctness 只看 `retval`，真实输出变了也可能过
4. attach path 只看 `bpf_stats`，语义错了也不会报警

### 3.6 false negatives：优化明明有价值，但当前 corpus 看不出来

当前 false negative 同样严重：

1. target-specific trigger 被丢掉，真实 control-plane event 没发生
2. multi-program attach pipeline 被压成单程序，关键 map 没被 companion program 建起来
3. optimize 看见的是 empty/default state，因而：
   - 有些 site 会被错判为没有价值
   - 有些 branch/DCE cascade 根本不会出现
4. PGO warmup 跑在另一份程序实例上，其他 runtime-dependent pass 也看不到真实 hotness

### 3.7 对 “other runtime-dependent optimizations” 的影响不是 map_inline 独有

这个问题不是 map_inline 专属，而是整个 runtime-state-sensitive benchmarking 结构性失真。

一个直接例子是 PGO：

- daemon 总是用 `--pgo serve` 启动（`corpus/modes.py:253-263`）
- `try_apply_one()` 会在 optimize 时对当前 prog_id 做 profiling（`daemon/src/commands.rs:138-160`, `664-689`）
- 但 corpus 的 `pgo_warmup` 是另一份 fresh load 的程序实例，不是后面 `rejit_compile` 那份 prog_id

所以今天的 corpus 其实也没有严肃地给 `branch_flip` 这类 runtime-dependent pass 喂到真实 profile。

### 3.8 daemon 侧 invalidation 也还没进入 benchmarkable 状态

即便不谈 corpus，当前 daemon 的 `serve` / `watch` 也还不是 dynamic specialization runtime：

- `serve` 只是一次请求做一次 optimize（`daemon/src/server.rs:103-130`）
- `watch` 把成功优化过的 program 放进 `optimized` 集合后就不再看了（`daemon/src/server.rs:176-227`）

这和 `dynamic_map_inlining_design_20260324.md` 里要求的：

- specialize
- invalidation
- rollback
- respecialize

不是一回事。

所以 benchmark framework 现在最多能评估“一次性 specialization”，还不能评估完整 deopt story。

---

## 4. Proposed Improvements

在回答 a-e 之前，我认为必须先加一个 **P0 前置项**。

### P0. 先修复 corpus orchestration fidelity

如果不先做这件事，后面 a-e 只能局部成立。

#### 必须改的点

1. `load_targets_from_yaml()` 不能再只保留 `can_test_run`
   - 至少保留：
     - `test_method`
     - `program_names`
     - `trigger`
     - `trigger_timeout_seconds`
     - `compile_loader`
     - `workload_type`
     - `map_fixture`

2. attach target 需要支持真实 trigger
   - 对简单 target，可以直接执行 YAML 里的 shell trigger
   - 对需要更多结构化控制的 target，可以改成 named workload profile，再由 runner 实现

3. multi-program attach object 需要支持完整 pipeline attach
   - 不能再默认只测 `program_names[0]`
   - 至少要支持“全部 program attach，然后测某个 primary program 的 `bpf_stats`”

4. `compile_only` target 需要单独处理
   - 不能继续和 `attach_trigger` 一起落入 “非 test_run 分支”

#### 粗略工作量

- 约 3-5 个工作日
- 风险低于后面的 snapshot/restore，但收益非常大

---

### 4.a Pre-populated map fixtures

这是最直接、也最该先做的改进之一。

#### 目标

让优化和测量都在同一份、非零、可解释、可复现的 map state 上进行。

#### 建议 schema

在 `macro_corpus.yaml` target 上增加：

```yaml
map_fixture: corpus/fixtures/maps/tetragon_execve.yaml
```

fixture 文件格式建议：

```yaml
target: tetragon_execve
maps:
  - name: tg_conf_map
    type: array
    entries:
      - key_hex: "00000000"
        value_hex: "..."
  - name: policy_filter_maps
    type: hash
    entries:
      - key_hex: "..."
        value_hex: "..."
metadata:
  captured_from: tetragon-steady-state
  captured_at: "2026-03-26T10:00:00Z"
  volatile_fields_masked: true
```

#### runner 侧实现细节

1. `corpus/modes.py` 把 `map_fixture` 透传到 batch job
2. `batch_runner` 为 job 增加 `map_fixture_path`
3. `kernel_runner` 在 `bpf_object__load()` 成功后、daemon optimize 前调用 `apply_map_fixture(object, path)`
4. `apply_map_fixture()`：
   - 按 map name 找 object map
   - 对每个 entry 调 `bpf_map_update_elem`
   - unsupported map 直接报 skip/reason，不 silent ignore

#### 首期支持范围

建议第一版只支持：

- `ARRAY`
- `HASH`
- `LRU_HASH`

显式不支持：

- `PERCPU_*`
- `ringbuf` / `perf_event_array`
- `queue` / `stack`
- `map-in-map`
- 含 kptr / timer / spinlock / socket 的 value

#### realistic value 如何获得

建议增加一个 **VM 内 capture 工具**，从真实 app steady-state 抓一份 map snapshot：

1. 在 VM 内启动真实 workload（Tracee/Tetragon/Katran）
2. 等 control plane 完成初始化
3. 对目标 program：
   - 取 `map_ids`
   - 按 map name/type dump key/value
4. 把结果转成 YAML fixture
5. 对明显波动字段做 sanitize / mask

经验上应优先抓：

- Katran `ctl_array` / `vip_map` / `reals`
- Tetragon `tg_conf_map` / policy filter maps
- Tracee `config_map` / filter maps / `*_version`
- Cilium runtime config 的稳定 slot

#### 为什么这是必要的

如果不做 fixture，当前 corpus 基本只会测到：

- empty/default map
- optimize 后才写进去的 map

这两种都不是 paper 想讲的 steady-state specialization。

#### 粗略工作量

- runner 支持 + schema + 5 个 flagship fixture：约 1-2 周
- 如果想扩到大规模 corpus：数周到一个月以上

---

### 4.b Map snapshot + restore

这一步解决的不是“让 map 非零”，而是“让 stock 和 rejit 看到同一份 map state”。

#### 核心目标

保证 paired comparison 至少满足：

```text
same input
same map contents
different code
```

#### test_run 的最佳实现

建议引入同实例 paired mode：

1. load object
2. apply fixture
3. snapshot `S0`
4. stock warmup + measure
5. restore `S0`
6. daemon optimize
7. restore `S0` again
8. rejit warmup + measure

这样 stock 与 rejit 才是真正共享同一份 snapshot。

#### attach 的最佳实现

attach E2E 更难，但仍然可以先把 map state 做到一致：

1. load object
2. apply fixture
3. snapshot `S0`
4. attach stock
5. run target-specific trigger / workload
6. record correctness/perf
7. detach
8. restore `S0`
9. daemon optimize
10. restore `S0` again
11. attach rejit
12. run identical trigger / workload
13. record correctness/perf
14. detach

注意：

- 这只能保证 BPF map contents 一致
- 不能自动保证外部 kernel state / file system / PID / cgroup side effect 一致
- 所以 attach path 仍需要更 deterministic 的 trigger

#### snapshot/restore 具体实现

建议 runner 内新增两个 helper：

- `snapshot_maps(...)`
- `restore_maps(...)`

首期策略：

- 只 snapshot fixture-managed maps，或者 target allowlist maps
- 不追求“一上来支持所有 map type”

格式上应存：

- map name
- map type
- key bytes
- value bytes

不要只存 runtime map ID，因为每次 fresh load 的 map ID 都会变。

#### restore 时需要注意的细节

- `ARRAY`：按 snapshot 覆盖所有记录的 slot
- `HASH`：先写回 snapshot 里的 key/value，再删除当前多出来的 key
- 对 unsupported map，直接标记该 target 不可做严格 paired correctness

#### 为什么它比“两个 fresh load 分别套同一 fixture”更强

因为程序自己在 warmup / measurement 里会写 map。

如果只是：

- stock 用 fixture A
- rejit 也 fresh load fixture A

那至少两次执行前状态相同；
但如果想精确比较 “同一程序演化出来的 state”，还是同实例 restore 更严谨。

#### 粗略工作量

- 只做 fixture-managed allowlist map：约 1-2 周
- 做成 generic map dumper/restorer：约 3-4 周

---

### 4.c Dedicated map inline micro benchmarks

这是 OSDI 里必须有的“机制正确性 + 小规模性能证明”。

#### 为什么 corpus 不够

corpus 更适合做：

- 覆盖面
- 现实 workload case study
- steady-state perf trend

它不适合单独承担：

- precise semantic oracle
- invalidation path regression test
- 精确的 site-level codegen 证明

#### 建议新增的 benchmark/test

建议放到 repo-owned tests 目录，遵守仓库规则：

- `tests/map_inline_array_const/`
  - `ARRAY`
  - key 固定为 0
  - value 是带多个字段的 struct
  - 程序读多个 fixed-offset field，并让这些字段决定 branch
  - 预期：`map_inline + const_prop + dce` 连锁触发

- `tests/map_inline_hash_guarded/`
  - `HASH`
  - 覆盖：
    - 当前 v1 应 skip
    - 将来 dynamic path 应保留 guard / invalidate

- `tests/map_inline_input_map_ordering/`
  - 专门验证 “optimize 前必须先把 input-like map 填好”
  - 防止当前 corpus 的时序 bug 再出现

- `tests/map_inline_invalidation/`
  - specialize
  - mutate map
  - expect dirty / rollback / respecialize

#### correctness oracle 必须比什么

不要只比 `retval`。

至少要比：

- `retval`
- `sample.result`
- output packet / `ctx_out`
- declared output map content

#### performance microbench

同一套程序可以再做 perf 版本，但前提是：

- correctness 已经通过
- fixture/snapshot 固定
- repeat 足够大

#### 粗略工作量

- 初版 correctness + perf micro suite：约 3-5 个工作日
- 若加 invalidation regression：再加 3-5 个工作日

---

### 4.d Split correctness from performance measurement

这是我认为 **对论文最 essential** 的一项。

#### 当前最大问题

现在 framework 实际上把：

- “速度快”
- “语义没变”

混在同一个 perf pair 里暗示了，但代码并没有提供足够的 correctness 保证。

#### 建议拆成两条 pipeline

##### Correctness pipeline

目标：

- 输入、map snapshot、trigger 都尽量 deterministic
- stock/rejit 跑完后做语义 diff

输出：

- `correctness_passed`
- mismatch 类型
- mismatch 具体字段

##### Performance pipeline

目标：

- 保持较接近真实 steady-state 的 workload
- 允许 map state 是 live evolving 的

输出：

- exec time
- code size
- 以及 map-state provenance 标签

#### 具体实现建议

1. 结果结构里显式分开：
   - `stock_correctness`
   - `rejit_correctness`
   - `stock_perf`
   - `rejit_perf`

2. correctness target 的判定标准：
   - test_run：必须比较完整输出，不只 `retval`
   - attach：若没有 semantic oracle，则该 target 标记为 `perf-only`

3. report 层：
   - 论文里不要再把 perf pair 当 correctness evidence
   - 只有 `correctness_passed` 的 target 才能进入 “validated speedup” 集合

#### attach correctness 的现实做法

attach target 经常没有天然 output buffer，所以要么：

- 给 target 增加专用 output map / counter oracle
- 要么用 userspace 可观测 side effect
- 要么明确标记 “只能 perf，不能 correctness”

不要再默认把 `run_cnt_delta` 当 semantic output。

#### 粗略工作量

- runner/result/report 改造：约 4-7 个工作日

---

### 4.e E2E map state verification

这是把 case study 做到“可辩护”的关键步骤。

#### 目标

对 flagship workload 明确回答：

- optimize 时 map 真的是非平凡非零的吗？
- stock/rejit measurement window 内它稳定吗？
- 如果不稳定，结果有没有被排除或标注？

#### 建议先做 3 个 workload

- Katran
- Tetragon
- Tracee

#### 需要记录的 telemetry

对每个被 specialization 用到的 `(map, key)`，记录：

- map name / map id / type
- key bytes
- optimize-time value bytes 或 digest
- 非零字节数
- 若存在 version field / sidecar version，则记录 version

建议至少打 4 个时间点：

- `t0`: optimize 时
- `t1`: stock 测量前
- `t2`: rejit 测量前
- `t3`: 测量后

#### 建议的判定规则

1. `non_trivial`
   - 若 value 全零/默认态，则不能把这个 target 当 dynamic map inline 证据

2. `stable_window`
   - 若 `t1` 到 `t2` 之间 value/version 变化，则该 pair 不能当严格 paired comparison

3. `diverged_after_optimize`
   - 若 optimize 时和测量时不同，明确标成 stale-state run

#### 为什么这项对 Tracee/Tetragon 很重要

`dynamic_map_inlining_design_20260324.md` 已经指出：

- Tracee 存在大量 `*_version` map，适合作为 invalidation substrate
- Tetragon 的 `tg_conf_map` / policy filter map 明显偏 control-plane / startup-only

如果不把这些 map 的 optimize-time / measure-time state 记录下来，论文里就只能说“理论上适合”，不能说“benchmark 确认了它真的处于合适状态”。

#### 粗略工作量

- 只做 3 个 flagship workload：约 1-2 周
- 若扩到全 corpus 自动化：数周

---

## 5. Priority And Effort Estimate

### 5.1 哪些对 OSDI 论文是 essential

我认为下面这些是 **essential**：

1. **P0：恢复真实 target 语义**
   - 不做这一步，attach corpus 本身就不是在测声明里的 workload

2. **4.d correctness/performance 拆分**
   - 不拆开，论文会把 perf pair 误当 correctness evidence

3. **4.b snapshot + restore**
   - 没有 paired state，就没有 runtime-dependent opt 的有效对照实验

4. **4.a flagship fixture**
   - 至少需要少数代表性 target 证明 optimize 时读到的不是 empty/default map

5. **4.c dedicated microbench**
   - 需要有机制级 correctness + codegen 证明

6. **4.e flagship E2E verification**
   - 至少对 2-3 个 case study，必须证明 optimize-time state 非平凡且稳定

### 5.2 哪些是 nice-to-have

这些是 nice-to-have，而不是 paper 最小闭环的必需项：

- full corpus 规模的 fixture 覆盖
- generic all-map snapshot/restore
- 几百个 attach target 的 E2E state telemetry 全量接线
- 所有 multi-program pipeline 的完全 fidelity 重建

论文最小闭环不需要一下子把 764 个 target 全修完；
但至少需要把 flagship case 做成可辩护的 gold-standard。

### 5.3 推荐优先级与粗略工作量

| 项目 | 优先级 | 是否 OSDI 必需 | 粗略工作量 |
|---|---|---|---|
| P0 恢复 target 语义（trigger / multi-program / compile_only） | P0 | 是 | 3-5 天 |
| 4.d correctness/performance 拆分 | P0 | 是 | 4-7 天 |
| 4.c micro benchmarks | P0 | 是 | 3-5 天 |
| 4.a flagship fixture（先做 3-5 个 target） | P1 | 是 | 1-2 周 |
| 4.b allowlist snapshot/restore | P1 | 是 | 1-2 周 |
| 4.e flagship E2E verification | P1 | 是 | 1-2 周 |
| full corpus fixture rollout | P2 | 否 | 数周 |
| generic all-map snapshot/restore | P2 | 否 | 3-4 周 |
| 全 corpus E2E telemetry | P2 | 否 | 数周 |

---

## 6. 我对论文闭环的具体建议

如果目标是尽快得到一套可以写进 OSDI 的证据链，我建议按下面顺序做：

### Phase 1：先把“测的是什么”修正

- 做 P0
- 拆 correctness / performance
- 增加 dedicated microbench

这一步完成后，至少不会再把“generic mixed workload 的 perf 数字”误写成 target-specific correctness evidence。

### Phase 2：做 2-3 个 flagship case 的 gold-standard

优先做：

- Katran
- Tetragon
- Tracee

每个 case 都具备：

- fixture
- snapshot/restore
- optimize-time map-state log
- stock/rejit semantic diff
- perf measurement

这一步完成后，dynamic map inline 的论文 story 就有了可辩护的核心证据。

### Phase 3：再考虑把方法外推到更大 corpus

等 Phase 2 跑通之后，再扩到：

- 更多 target
- 更多 map type
- 更自动化的 capture/restore pipeline

否则很容易陷入“覆盖面做得很大，但每个 target 的 state fidelity 都不可靠”的陷阱。

---

## 7. 最终判断

当前 corpus 框架最大的问题不是“map 可能是空的”，而是：

- **optimize 时机**
- **map state 时机**
- **真实 trigger fidelity**
- **correctness oracle**

这四件事同时都不对齐。

因此，对 map inlining 这样的 runtime-dependent optimization，当前 corpus 结果更像：

- “一次性对 fresh program 做了 daemon optimize，然后在另一个 state 上跑 perf”

而不是：

- “在同一份真实、非零、稳定的 runtime state 上，对比 stock 与 specialized code 的 correctness 与 performance”

如果论文要把 dynamic map inlining 当核心 story，那么：

- `fixture + snapshot/restore + correctness/perf split + flagship E2E verification`

不是锦上添花，而是 benchmark methodology 的基本门槛。
