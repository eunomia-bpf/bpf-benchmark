# Map Inline Correctness 调查报告（2026-03-26）

## 结论摘要

我的结论很直接：

1. **当前 benchmark framework 并没有形成一个强而直接的证据链，去证明“map inline 在非零真实 map 值下与 stock 语义等价”。**
2. `daemon` 里的 **unit tests 确实测试了非零 map 值的 rewrite 正确性**，但那是 pass 级单元测试，不是 benchmark framework 里的端到端 correctness 验证。
3. 在 corpus / micro / 大多数 E2E 路径里，**daemon 读取 map 值的时点，要么早于测试输入 map 的填充，要么根本没有 same-input 的 stock-vs-rejit 语义对比**。
4. 更关键的是，当前 `MapInlinePass` 的 v1 条件要求 **map 必须 `frozen` 且支持 direct value access**；而我在 benchmark framework 相关代码里**没有看到任何主动 `bpf_map_freeze()` 的运行路径**。这意味着很多“真实 workload 里的热路径 map”即使有非零数据，也**大概率根本不会被当前 v1 map inline 命中**。
5. 因此，如果论文要声称“map inlining correctness 已在 benchmark framework 中得到有意义验证”，**按当前代码是不够扎实的**。更准确的说法应该是：
   - pass 级 rewrite correctness：有单元测试；
   - benchmark 级真实 workload correctness：**证据不足**；
   - benchmark 级“非零真实 map 值” correctness：**基本没有被专门验证**。

## 调查范围

本次调查重点阅读了以下路径：

- `daemon/src/passes/map_inline.rs`
- `daemon/src/analysis/map_info.rs`
- `daemon/src/commands.rs`
- `daemon/src/bpf.rs`
- `corpus/modes.py`
- `runner/src/kernel_runner.cpp`
- `runner/src/batch_runner.cpp`
- `micro/driver.py`
- `e2e/cases/tracee/case.py`
- `e2e/cases/katran/case.py`
- `daemon/src/invalidation.rs`

另外，为回答你在问题里显式提到的 Tetragon，我补充看了：

- `e2e/cases/tetragon/case.py`
- `runner/libs/rejit.py`

## 1. 先把核心机制说清楚

### 1.1 daemon 到底在什么时候读 map 值？

`MapInlinePass` 不是离线根据 ELF 常量猜值，而是**在 pass 执行时直接读 live kernel map 的当前值**。

- `MapInlinePass::run()` 会遍历 helper lookup site，并在每个 site 上调用 `build_site_rewrite()`：`daemon/src/passes/map_inline.rs:147-250`
- `build_site_rewrite()` 里真正调用了 `bpf::bpf_map_lookup_elem_by_id(...)` 去读 live map：`daemon/src/passes/map_inline.rs:405-418`
- 返回的 raw bytes 会被拆成常量 load，替换原来的 `bpf_map_lookup_elem()` 结果消费：`daemon/src/passes/map_inline.rs:436-447`

所以，**inline 的值就是“daemon apply / optimize 当下，内核里那个 map key 的当前值”**。

### 1.2 什么 map 才会被 v1 inline？

`MapInfoAnalysis` 的条件非常严格：

- 只允许 `HASH` / `ARRAY` / `LRU_HASH` 这类 direct-value-access map：`daemon/src/analysis/map_info.rs:48-53`
- **必须 `frozen`**：`daemon/src/analysis/map_info.rs:55-62`
- `ARRAY` 才允许彻底移除 lookup/null-check pattern：`daemon/src/analysis/map_info.rs:64-68`
- `HASH` / `LRU_HASH` 属于 speculative inline：`daemon/src/analysis/map_info.rs:70-74`
- `frozen` 位来自 live map info，而不是静态假设：`daemon/src/analysis/map_info.rs:182-191`

这意味着当前 v1 不是“任何 map lookup 都 inline”，而是“**仅 frozen map lookup**”。

### 1.3 daemon apply 的优化时点

`cmd_apply()` 最终进入 `try_apply_one()`：`daemon/src/commands.rs:476-495`

`try_apply_one()` 的顺序是：

1. 打开 live prog fd；
2. 取原始指令；
3. 取当前 live map IDs；
4. 重建 `BpfProgram`；
5. 运行 pass pipeline；
6. 若成功则 `BPF_PROG_REJIT`。

对应代码在：`daemon/src/commands.rs:583-775`

因此，**map inline 读取的是“程序已经 load 到内核之后、但 benchmark workload/测试运行之前或中途某个时点”的 live map 值**。这和 benchmark 自己何时填充 map 直接相关。

### 1.4 live map lookup 的语义

底层 map read 语义来自 `daemon/src/bpf.rs`：

- `bpf_map_get_info_by_id()` 取 live map info 和 best-effort `frozen` 状态：`daemon/src/bpf.rs:506-517`
- `bpf_map_lookup_elem()` 真正执行 `BPF_MAP_LOOKUP_ELEM` syscall：`daemon/src/bpf.rs:519-541`
- `bpf_map_lookup_elem_by_id()` 先按 map id 打开 fd，再做 lookup：`daemon/src/bpf.rs:543-565`

这有两个重要后果：

1. **ARRAY** 如果 key 在范围内但用户从未写过，通常读到的是默认零值；
2. **HASH / LRU_HASH** 如果 key 不存在，lookup 会失败，site 会被跳过，而不是“inline 零”。

## 2. Question 1: Corpus `test_run` mode

## 2.1 实际执行顺序

`corpus/modes.py` 里真正的 batch plan 顺序是：

1. `baseline_compile`
2. `baseline_run`
3. `pgo_warmup`（仅 test_run path）
4. `rejit_compile`
5. `rejit_run`

实现见：`corpus/modes.py:520-685`

注意：`build_markdown()` 里的说明写成了 “baseline compile-only, REJIT compile-only, baseline test_run, REJIT test_run” (`corpus/modes.py:1541-1546`)，但**这和代码实现不完全一致**。判断时应以 `build_target_batch_plan()` 的真实调度逻辑为准。

## 2.2 `BPF_PROG_TEST_RUN` 时，map 会不会被填充？

会，但要区分**谁在什么时候填**。

在 runner 的 `run_kernel()` / `run_prepared_kernel()` 里，如果 `io_mode == "map"`，会在真正执行 `BPF_PROG_TEST_RUN` 之前：

- 把 `input_bytes` 写进 `input_map[0]`
- 把 `result_map[0]` 清零

对应代码：

- 非 prepared 路径：`runner/src/kernel_runner.cpp:2517-2561`
- prepared 路径：`runner/src/kernel_runner.cpp:1885-1929`

所以问题的精确答案是：

- **会填充 harness 自己的 `input_map` / `result_map`**
- 填充值来自 benchmark 输入文件 `memory_path` 或补零后的 `input_bytes`
- `result_map` 被置零作为输出槽位

但是，这个结论**不能直接推导出 daemon 读到了这些值**，因为 daemon 的时点更早。

## 2.3 daemon 是在 program load 后、test_run 前读取 map 吗？

**是。**

对于 corpus 的 `rejit_compile`，`runtime="kernel-rejit"` 且 `compile_only=True`，batch runner 会先 `prepare_kernel()`，再把 prepared state 留给后续 `rejit_run`：`runner/src/batch_runner.cpp:1483-1498`

而 `prepare_kernel()` 中如果 `compile_only && rejit`，会立刻调用 daemon optimize：`runner/src/kernel_runner.cpp:2266-2287`

这意味着在 corpus `test_run` 模式里，**REJIT 那次 daemon map read 发生在 compile-only prepare 阶段**，也就是：

- 程序已经 load 完；
- 但 `rejit_run` 还没开始；
- `input_map` / `result_map` 还没被 runtime path 写入。

因此，**daemon 读不到 `rejit_run` 这次 test input 所写进去的 map 值**。

## 2.4 它会 inline 什么值？

分情况：

1. **如果目标 lookup 是 frozen ARRAY，且 key 在范围内，但 benchmark 没在 daemon apply 之前预写这个元素**
   - daemon 读到的通常就是默认零值；
   - inline 出去的也就是零常量。

2. **如果目标 lookup 是 frozen HASH / LRU_HASH，但 key 在 daemon apply 时还不存在**
   - lookup 失败；
   - site 被跳过，不会 inline 为零。

3. **如果对象加载过程或特殊 fixture 已经在 daemon apply 之前填好了这个 frozen map**
   - daemon 会 inline 那个真实值。

但对 corpus `test_run` 的一般路径来说，当前 framework 只会在**真正 run 的时候**填 `input_map` / `result_map`，不是在 `rejit_compile` 阶段填，因此**这些 harness map 的值不会被 daemon 看见**。

## 2.5 这是不是一个有意义的 map inline correctness test？

**大体上不是。**

原因有三层：

1. daemon 读值时点早于 test_run 的 map 填充；
2. 即便发生 inline，很多情况下读到的只是默认零值；
3. 当前 v1 还要求 `frozen`，而 harness 的 `input_map` / `result_map` 本身显然是运行期可写的，不属于 v1 inline 目标。

所以 corpus `test_run` 更像是在测：

- “程序 load / test_run / REJIT 流程能否跑通”
- “某些 site 在当前 live state 下是否能被改写”

而不是在测：

- “**一个带真实非零 map 数据的 map-inline specialization 是否与 stock 完全等价**”

## 3. Question 2: Corpus attach mode

## 3.1 daemon optimize 相对 workload 的时点

attach 模式下，`corpus/modes.py` 会用：

- baseline：`kernel-attach`
- rejit：`kernel-attach-rejit`

见：`corpus/modes.py:573-588` 和 `corpus/modes.py:669-685`

在 `run_kernel_attach()` 中，如果启用了 daemon REJIT，会在：

1. object load 完；
2. 取得 prog fd；
3. **先调用 daemon optimize**
4. 然后才 attach program；
5. 再跑 warmup / measured workload。

对应代码：`runner/src/kernel_runner.cpp:2836-2860`，之后 attach/workload 在 `2862-2900`

所以 attach mode 的答案也很明确：**daemon optimize 发生在 workload 之前**。

## 3.2 `stress-ng` / `fio` / `wrk` 会不会在 daemon optimize 之前把 BPF maps 填好？

**一般不会。**

`run_workload()` 只是执行这些用户态 workload：`runner/src/kernel_runner.cpp:1682-1722`

而这些 workload 是在 attach 之后才开始跑：`runner/src/kernel_runner.cpp:2888-2900`

因此在 daemon optimize 当下：

- workload 还没开始；
- workload 驱动出来的 BPF map 更新也还没发生。

换句话说，**如果某些 BPF maps 是靠实际事件流/请求流在运行中逐步积累出来的，那 daemon 看不到这些值**。

## 3.3 attach mode 下 inline 的值是否有意义？

通常也**不太有意义**，因为：

1. framework 没有通用的“attach 前预填 map”步骤；
2. workload 触发的 map 更新发生在 optimize 之后；
3. 当前 v1 只 inline `frozen` map，而 attach 热路径里最可能变化的那些统计/状态 map 本来就不该被 v1 inline。

所以 attach mode 对 map inline 的 benchmark 语义更像是：

- “优化发生前 live maps 的初始/默认状态”

而不是：

- “真实 workload 已把业务 map 填成非零后，再做 specialization 并验证等价性”

## 4. Question 3: E2E mode

## 4.1 Tracee

`TraceeAgentSession` 会先启动 Tracee，等它健康并确认 BPF programs 已加载：`e2e/cases/tracee/case.py:153-205`

真正的流程是：

1. 启动 Tracee；
2. baseline phase；
3. `scan_programs(...)`；
4. `apply_daemon_rejit(...)`；
5. post-rejit phase。

代码见：`e2e/cases/tracee/case.py:694-719`

所以对 Tracee：

- daemon 不是在 app 启动前跑；
- 也不是在 app 刚加载完程序后立刻跑；
- **而是在 baseline workload 已经跑过一轮之后才跑。**

这意味着届时 map 很可能已经被真实 workload 或 agent 自己写过。

## 4.2 Tetragon

Tetragon 的顺序和 Tracee 类似：

1. 启动 Tetragon；
2. baseline phase；
3. `scan_programs(...)`；
4. `apply_daemon_rejit(...)`；
5. post-rejit phase。

代码见：`e2e/cases/tetragon/case.py:666-682`

所以 Tetragon 也是**先运行 baseline，再 REJIT**。

## 4.3 Katran

Katran 是 E2E 里最特殊、也是最接近“真实非零 map 数据”的路径。

### 4.3.1 Katran 会显式填充非零 map

`configure_katran_maps()` 会显式往这些 pinned maps 写值：

- `ctl_array`
- `vip_map`
- `reals`
- `ch_rings`

代码见：`e2e/cases/katran/case.py:1600-1635`

这些显然不是全零默认值。

### 4.3.2 Katran 还有一个 stock `prog_test_run` 验证

在每个 cycle 里，Katran 会：

1. 建 topology
2. 启动 HTTP server
3. 加载并 attach Katran BPF program
4. `configure_katran_maps(session)`
5. `run_katran_prog_test_run(session)`
6. baseline 测量
7. `apply_daemon_rejit(...)`
8. post-rejit 测量

代码见：`e2e/cases/katran/case.py:2200-2256`

`run_katran_prog_test_run()` 会对 pinned prog 做 `BPF_PROG_TEST_RUN`，要求返回 `XDP_TX`：`e2e/cases/katran/case.py:1033-1062`

这说明 Katran 至少在 **stock 阶段** 有一个“非零 map 配置下程序行为正常”的检查。

### 4.3.3 但它不是 post-rejit 语义等价验证

关键缺口有三个：

1. `run_katran_prog_test_run()` 只在 baseline 前跑一次，**没有在 REJIT 之后再跑同样输入做 stock-vs-rejit 直接比对**；
2. `apply_daemon_rejit()` 发生在 baseline phase 之后，daemon 看到的是“baseline 跑完后的 live map 状态”，不是初始配置值：`e2e/cases/katran/case.py:2235-2236`
3. Katran 的 phase 比较是 aggregate summary，而不是逐包语义比较：`e2e/cases/katran/case.py:486-489`

另外，`measure_phase()` 每次 phase 开头会 reset 一批 mutable state maps：`e2e/cases/katran/case.py:1995-2003` 和 `1112-1165`

这件事有两个影响：

- baseline 和 post-rejit 不是完全相同的 live state 连续执行；
- daemon optimize 读取到的 map 值，与 post-rejit phase 真正开始时的 live map 值，也不一定完全相同。

不过这里还有一个更重要的现实问题：

**Katran 这些 map 在当前 framework 里并没有 freeze。**

- `MapInlinePass` v1 明确要求 `frozen`：`daemon/src/analysis/map_info.rs:55-62`
- `configure_katran_maps()` 只 update，没有 freeze：`e2e/cases/katran/case.py:1600-1635`
- 我对 benchmark framework 相关代码做搜索，没有找到实际运行路径中的 `bpf_map_freeze()` 调用

所以 Katran 虽然“确实有非零真实 map 数据”，但**这些 map 大概率并不是当前 v1 map inline 的真实命中对象**。

## 4.4 E2E correctness check 到底比较了什么？

Tracee / Tetragon / Katran 的 compare 都是**phase summary / 吞吐 / 事件数 / bpf avg ns/run** 这类聚合指标，不是语义等价检查：

- Tracee：`e2e/cases/tracee/case.py:472-520`
- Tetragon：`e2e/cases/tetragon/case.py:477-508`
- Katran：`e2e/cases/katran/case.py:486-489`

也就是说，即使 map 值在 stock 与 rejit 两个 phase 之间发生变化，当前 E2E 结果仍然可能“看起来正常”，因为它压根没有做：

- 相同输入的直接对照；
- 相同 map snapshot 下的输出字节比对；
- 相同 request / packet 的 stock-vs-rejit semantic diff。

## 5. Question 4: 有没有任何 test 真正验证了“非零真实 map 值 inline 后与 stock 等价”？

## 5.1 如果只看 benchmark framework：**基本没有**

这是本次调查最重要的结论。

### micro

`micro/driver.py` 会比较 `kernel` 和 `kernel-rejit` 的 modal `result`：`micro/driver.py:872-891`

但当前 micro 的问题是：

1. daemon REJIT path 仍然是 prepare/compile-only 阶段先 optimize，和 corpus `test_run` 一样：`micro/driver.py:515-548` + `runner/src/kernel_runner.cpp:2266-2287`
2. micro suite 当前配置中没有 `io_mode: map`；我对 `micro/config` 做搜索，没有发现 map-mode benchmark
3. 我对 `micro/programs` 做搜索，`bpf_map_lookup_elem` 只出现在公共宏 `micro/programs/common.h:211`，说明当前 micro 程序本身**并没有专门覆盖 helper-based map lookup specialization**

所以 micro 目前**基本不构成 map inline correctness 的实证覆盖**。

### corpus

corpus 的 `test_run` / `attach` 两条路径都存在前面说的时点问题：

- `test_run`：daemon optimize 早于 harness map 填充；
- `attach`：daemon optimize 早于 workload 导致的 live map 演化。

这两个路径都**没有形成“先用已知非零 map 值 specialize，再和 stock 在相同输入下逐项比对”的测试设计**。

### E2E

Tracee / Tetragon / Katran 都没有：

- 同一输入下的 stock-vs-rejit 直接语义比对；
- REJIT 后再次执行 deterministic `prog_test_run` 并与 stock 基线比较。

Katran 虽然最接近，但也只是：

- baseline 前做一次 stock `prog_test_run`
- REJIT 后做性能 phase

并没有完成真正的 semantic equivalence check。

## 5.2 但如果把 daemon unit tests 算上：**pass 级有覆盖**

`daemon/src/passes/map_inline.rs` 里有明确的非零值测试：

- `map_inline_pass_rewrites_lookup_and_scalar_loads()`：
  - 安装一个数组 map，值里有 `7` 和 `0xaa`
  - 验证 rewrite 后常量正是这两个非零值
  - 代码：`daemon/src/passes/map_inline.rs:981-1017`

- `map_inline_pass_rewrites_struct_value_multiple_fields()`：
  - 安装 16-byte 非零结构体值
  - 验证 32-bit / 64-bit 字段都被正确 materialize
  - 代码：`daemon/src/passes/map_inline.rs:1019-1057`

还有一些“不要错误 inline”的测试：

- mutable array 应跳过：`daemon/src/passes/map_inline.rs:1344-1370`
- percpu array/hash/lru_percpu_hash 应跳过：`daemon/src/passes/map_inline.rs:1372-1456`

此外，repo 里还有 verifier negative test，专门覆盖 “unsupported map type 上错误生成 direct value access” 的历史 bug：`tests/unittest/rejit_verifier_negative_tests.c:406-446`

所以必须区分：

- **pass/unit correctness：有**
- **benchmark framework end-to-end correctness：没有形成强证据**

## 5.3 风险到底是什么？

风险有两类，而且都真实存在。

### 风险 A：只在“零值/default state”下看起来没问题

如果 benchmark 某条路径确实命中了 inline，但 optimize 时 map 还没被预填，那 frozen ARRAY 读到的可能只是零值。这样可能掩盖如下 bug：

- 非零字节拼接错误；
- 偏移/宽度读取错误；
- 结构体字段 endianness 或对齐错误；
- 只在高位非零时暴露的 `ldimm64`/sign-extension 问题。

这种 bug 在“inline 0”时未必暴露。

### 风险 B：benchmark 根本没有真正命中当前 v1 map inline

当前 v1 要求 `frozen`。而 benchmark framework 代码里没有显式 freeze path，这意味着很多真实 workload map：

- 即使有非零业务数据；
- 即使 helper lookup 很热；
- 也**很可能不满足当前 v1 inline 条件**。

这种情况下 benchmark 可能仍然全部通过，但那只能说明：

- REJIT framework 没把程序搞坏；
- 其他 pass 没出问题；

**并不能说明 map inline 本身在真实 workload 上被验证过。**

我认为对论文来说，后者甚至比前者更关键，因为它意味着：

- 不是“map inline 在真实非零数据上被证明正确”；
- 而是“当前 benchmark 可能压根没形成这类证据”。

## 6. Question 5: 应该怎么修

下面这些改动是我认为最值得做、而且对论文最有帮助的。

## 6.1 加一个专门的 map-inline correctness VM 测试

这是最应该做的补洞。

建议新增一个 repo-owned test（放 `tests/`，走 VM，不碰 host kernel），特点如下：

1. 程序包含一个 `bpf_map_lookup_elem()` hot path；
2. map 类型用 **frozen ARRAY** 起步，先不要上 speculative HASH；
3. key 用 compile-time constant；
4. value 里放**明确的非零模式值**，例如：
   - `0x12345678`
   - `0x89abcdef01234567`
   - 多字段 struct
5. 在 `daemon apply` 之前，由测试 harness 明确预写 map；
6. 跑 stock；
7. 跑 daemon-rejit；
8. 比较：
   - `retval`
   - `result_map`
   - packet/context 输出字节（若适用）

这样才能真正回答：

> 同一个输入、同一个已知非零 map snapshot 下，map inline 后是否与 stock 完全等价？

## 6.2 扩展 runner 的 correctness check：不要只比 `retval`

当前 `run_kernel()` / `run_prepared_kernel()` 在 same-image pair 模式下，虽然会读出 `result`，但最后 `correctness_mismatch` 只比较 `retval`：

- prepared 路径：`runner/src/kernel_runner.cpp:2054-2164`
- 非 prepared 路径：`runner/src/kernel_runner.cpp:2699-2787`

而 `read_kernel_test_run_result()` 明明已经支持读取：

- packet/staged 输出
- context 输出
- `result_map`

代码见：`runner/src/kernel_runner.cpp:1259-1284`

所以 runner 至少应改成比较：

1. `retval`
2. `result`
3. 若存在，packet output bytes
4. 若存在，context output bytes

否则只要返回码碰巧一样，很多 map-inline bug 都可能漏掉。

## 6.3 给 corpus 增加“可控 pre-population”夹具

如果想让 corpus 对 map inline 有 paper-worthy 的说服力，需要一个明确的 fixture 机制：

1. 在 `rejit_compile` 之前预写目标 map；
2. 保证这个 map 是 v1 可 inline 的（最简单就是 frozen ARRAY）；
3. baseline 和 rejit 都在同一个已知 map 内容下运行；
4. 结果记录里显式写出：
   - optimize 时的 inline key
   - inline 前读到的 value bytes
   - 是否 applied

否则 corpus 只能说明“REJIT batch framework 在一堆对象上跑通了”，不能说明“map inline correctness 被测到了”。

## 6.4 给 Katran 加 post-rejit deterministic validation

Katran 是最容易补强的一条线，因为它已经有：

- 非零真实 map 配置；
- `prog_test_run` 能力；
- pinned program；
- 同一 live session。

建议在 `apply_daemon_rejit(...)` 之后，立刻再跑一次与 baseline 完全相同的 `run_katran_prog_test_run()`，并记录：

1. `retval`
2. `data_out`
3. action 名称
4. 必要时对 packet output 做字节级 diff

这样 Katran 至少能成为：

- “真实非零 map 配置”
- “真实 BPF 程序”
- “stock vs rejit deterministic semantic compare”

的一个强证据点。

## 6.5 在 managed-daemon / future mutable-map inline 中接上 invalidation

`MapInvalidationTracker` 目前只是一个独立组件：

- 定义了 `(prog_id, map_fd, key, expected_value)` 追踪模型：`daemon/src/invalidation.rs:8-15`
- 能 batch lookup 并找出被 invalidated 的 prog：`daemon/src/invalidation.rs:55-125`

但我在 repo 搜索中没有看到它被 `commands.rs` / runner / E2E 流程实际接入。

这意味着：

- 当前 one-shot `apply` 路径没有后续 invalidation 保护；
- 如果未来要放宽到 mutable-map specialization，benchmark correctness 会更脆弱。

建议：

1. one-shot benchmark 继续只允许 frozen fast path；
2. 若将来引入 live invalidation mode，则在 E2E 里把 optimize-time snapshot 和 run-time recheck 一并记录下来；
3. benchmark report 中显式输出“本次 map-inline specialization 是否在 phase 期间失效”。

## 6.6 在论文里不要把“pass unit tests”写成“benchmark correctness evidence”

这是写作层面的修正，但很重要。

当前最稳妥的表述应类似：

- `daemon` pass-level unit tests validate map-inline rewriting on synthetic non-zero map contents;
- benchmark framework validates overall REJIT execution flow on corpus/micro/E2E workloads;
- however, the current benchmark harness does **not yet provide a dedicated end-to-end semantic equivalence test for map-inline specialization under controlled non-zero live map contents**.

如果要把这件事写硬，需要先补上上面第 6.1 / 6.2 / 6.4 的测试。

## 7. 最终回答（按你的五个问题逐条）

### Q1. Corpus `test_run` mode

- **`BPF_PROG_TEST_RUN` 时 map 会被填充吗？**
  - 会，runner 会在 run 阶段把 `input_map[0]` 写成 input bytes，并把 `result_map[0]` 清零：`runner/src/kernel_runner.cpp:2517-2561`、`1885-1929`
- **daemon 是否在 program load 后、test_run 前读取 map 值？**
  - 是。对 `rejit_compile` prepared path，daemon 在 compile-only prepare 阶段就 optimize：`runner/src/kernel_runner.cpp:2266-2287`
- **它 inline 什么值？**
  - 如果目标是 frozen ARRAY 且未预填，通常就是默认零值；如果是 HASH/LRU_HASH 且 key 不存在，则 lookup 失败、site 跳过
- **这是有意义的 map inline correctness test 吗？**
  - 不是。因为 optimize 时点早于 run-time map 填充，而且当前路径没有“非零已知 map 值 + same-input stock/rejit compare”

### Q2. Corpus attach mode

- **daemon optimize 相对 workload 的时点？**
  - 在 attach 和 workload 之前：`runner/src/kernel_runner.cpp:2836-2860`
- **`stress-ng` / `fio` / `wrk` 会预先填 BPF maps 吗？**
  - 不会在 optimize 前填；这些 workload 是 attach 后才跑：`runner/src/kernel_runner.cpp:2888-2900`
- **inline 值有意义吗？**
  - 一般没有。没有通用 pre-populate 机制，workload 诱发的 map 更新发生在 optimize 之后

### Q3. E2E mode

- **Tracee / Tetragon / Katran 何时 optimize？**
  - Tracee/Tetragon：app 启动并跑完 baseline phase 之后
  - Katran：baseline phase 之后
- **那时 map 已经 populated 吗？**
  - Tracee/Tetragon：很可能已经被 workload/app 写过
  - Katran：配置 map 明确是非零；但 daemon 看到的是 baseline 后的 live state
- **stock 与 rejit 之间 map 会变吗？**
  - 会。Tracee/Tetragon 的 workload 会继续改变 live state；Katran 也有 phase reset 和流量驱动的状态演化
- **如果 map 变了，当前 correctness check 还成立吗？**
  - 不成立。当前 compare 主要是 aggregate metrics，不是 semantic equivalence

### Q4. 根本问题

- **有没有任何 benchmark test 直接验证“非零真实 map 值 inline 后与 stock 等价”？**
  - 如果只看 benchmark framework：**没有强证据**
  - 如果把 daemon unit tests 算上：**pass 级有 synthetic non-zero value 覆盖**
- **风险是什么？**
  - 完全有可能出现这种情况：
    - map inline 在真实非零值下有 bug；
    - 但 benchmark 因为 maps 为空/默认值、或者压根没触发 inline、或者只比 `retval`，所以全部通过

### Q5. 应该怎么做

最值得落地的修复是：

1. 新增一个专门的 VM map-inline correctness test，预填 frozen ARRAY 的非零值；
2. runner 把 correctness compare 扩展到 `result` / packet / context，而不是只比 `retval`；
3. corpus 增加 pre-population fixture，确保 daemon 在 optimize 时读到已知非零值；
4. Katran 在 REJIT 后重复 deterministic `prog_test_run`，做 stock-vs-rejit 直接语义对比；
5. 为 future mutable-map specialization 接上 `MapInvalidationTracker` 或等价 snapshot/recheck 机制。

## 8. 对论文表述的建议

如果现在就写论文，我建议把结论写保守一点：

- **可以 claim**
  - `MapInlinePass` 有单元测试，覆盖非零 map 值 rewrite
  - benchmark framework 能在 corpus / micro / E2E 路径中稳定执行 REJIT

- **不宜直接 claim**
  - “benchmark framework 已经充分验证 map inline 在真实非零 map 数据下的 correctness”

更准确的说法应该是：

> 当前 framework 已提供 pass 级 correctness 覆盖，但 benchmark 级针对“非零 live map contents”的 controlled end-to-end semantic validation 仍需补强。
