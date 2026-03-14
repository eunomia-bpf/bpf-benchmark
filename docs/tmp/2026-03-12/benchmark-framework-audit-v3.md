# Benchmark Framework Audit V3

日期：2026-03-12

范围：
- 项目背景：`docs/kernel-jit-optimization-plan.md`
- Micro runner：`micro/runner/src/llvmbpf_runner.cpp`，`micro/runner/src/kernel_runner.cpp`
- Micro orchestrator：`micro/run_micro.py`，`micro/_driver_impl_run_micro.py`，`micro/orchestrator/commands.py`，`micro/orchestrator/results.py`
- Micro suite / policy：`config/micro_pure_jit.yaml`，`micro/policies/*.yaml`
- Corpus runner：`corpus/_driver_impl_run_corpus_v5_vm_batch.py`，`corpus/run_corpus_runnability.py`，`micro/orchestrator/inventory.py`，`micro/orchestrator/corpus.py`，`corpus/common.py`
- 验证相关：`tests/kernel/test_recompile.c`，`corpus/_driver_impl_run_corpus_perf.py`
- 内核 `bpf_prog_test_run` 语义：`vendor/linux-framework/tools/lib/bpf/bpf.h`，`vendor/linux-framework/net/bpf/test_run.c`

## Executive Summary

结论先行：

1. 当前 `corpus 0.875x / 0.868x` 级别的负面结果，**不能直接当成“wide/rotate/extract/endian 在真实 steady-state 上普遍有害”的证据**。最大问题不是计时器本身，而是 **construct validity**：同一套固定 64B dummy packet 被用于所有 corpus 程序，而且框架没有证明这个输入真的触发了被优化的路径。
2. 当前 `micro applied-only` 结果，**也不足以支持“这些 canonical form 净负收益”**。主要原因是 applied 集合太小，而且混合了多种 family；checked-in authoritative fixed-policy 结果里只有 **8/56** benchmark 真正 applied，而不是规划文档里写的 **11/56**。
3. `ktime` 精度问题是实存问题，但**比文档里暗示的要小**。`kernel_runner` 不是测单次 `<100ns` 执行，而是拿 `bpf_prog_test_run` 返回的 **repeat-average**。在当前默认 `repeat=200` 下，若底层 `ktime` 粒度是 30-100ns，则摊到单次样本上的量化步长只有 **0.15-0.5ns**。它会污染 tiny rows，尤其 corpus，但**单靠这一点解释不了整套 0.875x 回归**。
4. 统计方法偏弱。Micro 当前只是描述性统计；Corpus 基本是一目标一次 fresh pair，没有 CI、显著性检验、outlier 处理，也没有 VM-to-VM 方差估计。

可信度评估：

- `micro kernel stock vs kernel-recompile`：
  对单个 benchmark 的方向性结论，`>200ns` 行为有中等可信度；对“这些 family 整体净收益”的结论是 **低可信度**，因为 coverage 太差。
- `corpus exec_ratio_geomean`：
  方向上说明“当前 harness 下的 corpus numbers 很差”是可信的；但把它解释为“优化本身在真实 hot path 上普遍变慢”是 **低可信度**。
- `llvmbpf vs kernel` 绝对值比较：
  **低可信度**，因为两条路径的 timing source 不一致：`llvmbpf` 用 `rdtsc`，kernel path 用 `ktime`。

## 0. 结果溯源先有漂移

严重程度：`P1`

发现：
- 规划文档写的是 `Micro applied-only (11/56) = 0.986x`，`Corpus v2 fixed = 0.875x`，见 `docs/kernel-jit-optimization-plan.md:56-59`。
- 但 checked-in authoritative artifact 里，micro fixed-policy 总结是 `applied_pairs = 8`，`applied_only_geomean_stock_over_recompile = 1.049031...`，见 `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json:101637-101643`。
- checked-in corpus authoritative artifact 是 `measured_pairs = 163`，`applied_programs = 92`，`exec_ratio_geomean = 0.868144...`，见 `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json:117-121`。

影响：
- 当前“最新结论”与 repo 内可复核 artifact 不一致。报告以下分析以 **代码 + checked-in authoritative artifacts** 为准。

修复建议：
- 每次出结论时，把 figure/table 绑定到具体 artifact path 和 git SHA。
- 在文档里标记 “checked-in authoritative” 和 “latest local rerun” 两种状态，避免口径漂移。

## 1. 测量精度

### 1.1 Kernel path 并不是在测单次 `<100ns`，而是在测 `repeat` 平均值

严重程度：`P2`

证据：
- `llvmbpf` path 在用户态围绕每次 `vm.exec()` 做 `rdtsc` 计时，最后再除以 `repeat`，见 `micro/runner/src/llvmbpf_runner.cpp:42-55`，`micro/runner/src/llvmbpf_runner.cpp:750-786`，`micro/runner/src/llvmbpf_runner.cpp:875-882`。
- kernel path 调用 `bpf_prog_test_run_opts()`，并直接信任 `test_opts.duration` 作为 `exec_ns`，见 `micro/runner/src/kernel_runner.cpp:1306-1314`，`micro/runner/src/kernel_runner.cpp:1345-1360`。
- libbpf 头文件明确说明 `duration` 是 “average per repetition in ns”，见 `vendor/linux-framework/tools/lib/bpf/bpf.h:687-690`。
- 内核实现中先累计总 `ktime_get_ns()`，完成后再 `do_div(..., repeat)`，见 `vendor/linux-framework/net/bpf/test_run.c:50-59`；执行循环见 `vendor/linux-framework/net/bpf/test_run.c:389-427`。
- Micro 默认 `repeat=200`，见 `config/micro_pure_jit.yaml:23-27`。我复核了 suite manifest：56 个 benchmark 里 `map=48`、`packet=5`、`staged=3`、`context=0`，因此 micro 里所有 benchmark 都走 `repeat=200` 路径。
- Corpus v5 batch 默认 `repeat=200`，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:113`，`corpus/_driver_impl_run_corpus_v5_vm_batch.py:175`。

结论：
- 文档中的 “sub-ktime noise” 方向没错，但“kernel 在测单次 `<100ns` 程序”这个直觉在当前 harness 下不成立。
- 在 `repeat=200` 下，如果底层 `ktime` 粒度真是 30-100ns，那么摊到每个 reported `exec_ns` 的量化步长只有 0.15-0.5ns。

量化影响：
- 我从 `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json` 重新统计：
  - stock kernel：56 行里有 `8/56` median `<100ns`，`16/56` `<200ns`
  - kernel-recompile：56 行里有 `9/56` median `<100ns`，`16/56` `<200ns`
- 我从 `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json` 重新统计：
  - `163` 个 measured pairs 里有 `101/163` 至少一侧 `<100ns`
  - `151/163` 至少一侧 `<200ns`
- 若按 30-100ns 粒度估算：
  - micro `<100ns` 的 kernel-recompile 行，最坏量化误差约 `1.36%-4.55%`
  - corpus `<100ns` 行，最坏量化误差约 `2.14%-7.14%`

判断：
- 这足以污染 tiny rows，尤其 corpus。
- 但它**不太可能单独把一整套 corpus geomean 从“应当恒快”扭成 `0.868x/0.875x`**。真正更严重的问题在第 4 节和第 7 节。

修复建议：
- 对 kernel path 做 adaptive repeat：把 `repeat` 提高到总计时窗口至少 50-100us，而不是固定 200。
- 报告里同时存 `ktime` 和 outer `TSC`，对 tiny row 做交叉校验。
- 对 `<200ns` 行单独打标签，不允许它们直接主导 suite headline geomean。

### 1.2 真正的实现问题是：kernel runner 明明采了 TSC，却几乎从不使用

严重程度：`P1`

证据：
- `kernel_runner` 在 `bpf_prog_test_run_opts()` 外层记录了 `tsc_before/after`，并计算了 `wall_exec_ns`，见 `micro/runner/src/kernel_runner.cpp:1294-1354`。
- 但只有 `test_opts.duration == 0` 时才 fallback 到 `wall_exec_ns`；否则一律把 timing source 标成 `ktime`，见 `micro/runner/src/kernel_runner.cpp:1356-1360`。

影响：
- tiny program 最需要 cross-check 的地方，框架没有用。
- 这会让 report 看起来像“只有一种时间真相”，实际上 runner 已经拿到了第二种时间源。

修复建议：
- 无论 `duration` 是否为零，都记录 `ktime_exec_ns` 和 `wall_tsc_exec_ns` 两列。
- 若二者偏差超过阈值，例如 `max(3ns, 3%)`，把该 row 标为 unstable。
- 对 kernel-only A/B headline，优先使用更稳定的那一个，或者同时报告两者。

### 1.3 `llvmbpf` 和 kernel 的绝对值不应直接放在同一坐标系解释

严重程度：`P2`

证据：
- `llvmbpf` timing source 是 `rdtsc`，见 `micro/runner/src/llvmbpf_runner.cpp:875-882`。
- kernel timing source 默认是 `ktime`，见 `micro/runner/src/kernel_runner.cpp:1345-1360`。

影响：
- `llvmbpf vs kernel` 的绝对值差异掺入了 timing-source 差异。
- 这不影响 `kernel stock vs kernel-recompile` 这种同源比较，但会污染跨 runtime headline。

修复建议：
- 若要比较 `llvmbpf` 与 kernel，至少让两边都输出 TSC-based outer timing。

## 2. A/B 测量方法

严重程度：`P2`

证据：
- `micro/run_micro.py` 只是 wrapper，真正逻辑在 `_driver_impl_run_micro.py`，见 `micro/run_micro.py:12-17`。
- 每次 sample 都是单独 `subprocess.run(...)`，见 `micro/_driver_impl_run_micro.py:122-135`。
- warmup 先按 runtime 分别跑完，见 `micro/_driver_impl_run_micro.py:403-404`。
- measured phase 只是在 Python 层交替 runtime 顺序；若有两个 runtime，则偶数轮正序、奇数轮逆序，见 `micro/_driver_impl_run_micro.py:413-425`。
- `kernel-recompile` runtime 不是单独 runner，而是同一个 `run-kernel` 子命令加 recompile 标志，见 `micro/orchestrator/commands.py:159-177`。

结论：
- stock 和 recompile **不是**在同一个 `micro_exec` 进程里 back-to-back 测的。
- 它们是 **两个独立子进程**，只是在同一个 Python orchestrator 里交替发起。
- 这样做的好处是顺序被 counterbalance 了。
- 但代价是 L1/L2/L3、TLB、branch predictor、i-cache 状态没有被严格配平；warmup 也主要只会热 page cache / binary pages / loader path，不会保留到下一个子进程里的精确微架构状态。

偏差判断：
- 这不是当前负面结果的第一嫌疑，因为 order alternation 至少消掉了单方向顺序偏差。
- 但它意味着 micro A/B 不是“严格配对”的 same-process steady-state 实验。

修复建议：
- 增加 same-process paired mode：一个 `micro_exec` 进程里按 `A/B/B/A` 方式重复 load+run。
- 把 warmup 也做成交替顺序，而不是先把某个 runtime 全部 warmup 完。
- 对 tiny row 加 cache state stress test，例如随机插入干扰工作负载，确认结论是否翻转。

## 3. Recompile 测量路径

### 3.1 `exec_ns` 不包含 recompile syscall 本身

严重程度：`P2`

证据：
- `BPF_PROG_JIT_RECOMPILE` 在 `recompile_start/recompile_end` 之间计时，见 `micro/runner/src/kernel_runner.cpp:1113-1136`。
- `sample.compile_ns` 明确把 `recompile` 时间加进去，见 `micro/runner/src/kernel_runner.cpp:1162-1165`。
- `sample.exec_ns` 在后面通过 `bpf_prog_test_run_opts()` 获取，见 `micro/runner/src/kernel_runner.cpp:1306-1360`。

结论：
- 当前实现里，`exec_ns` 测的确实是 BPF 执行阶段，不直接包含 recompile syscall 开销。

### 3.2 但 re-JIT 后没有任何 post-recompile warmup，steady-state 被污染

严重程度：`P1`

证据：
- recompile 完成后直接进入 test-run，见 `micro/runner/src/kernel_runner.cpp:1149-1165` 之后的执行路径，以及 `micro/runner/src/kernel_runner.cpp:1274-1360`。
- `micro_exec` 虽然接受 `--warmup/--warmups` 参数，但直接丢弃，没有落到 `options` 结构里，见 `micro/runner/src/common.cpp:338-340`，`micro/runner/include/micro_exec.hpp:62-72`。

影响：
- re-JIT 后的第一次执行若带有 i-cache cold、BTB cold、JIT patching 后的前几次前端扰动，这些成本会混进 `repeat` 平均值。
- stock path 也会测到 “fresh load 后的第一次执行”，所以不是单边问题；但 recompile path 在执行前额外做过一次 JIT 变更，理论上更容易出现 post-reJIT transient。
- 因为 `repeat=200`，这个污染被稀释了；对长程序影响有限，对 `<100ns` 小程序可能仍然明显。

修复建议：
- 在 `run-kernel` 内增加 in-process warmup 次数，并把 warmup 放在 load/recompile 之后、正式计时之前。
- 同时输出 `first_hit_exec_ns` 和 `steady_state_exec_ns`，不要混成一个数字。

## 4. 统计方法

### 4.1 Micro 当前只是描述性统计，不是推断性统计

严重程度：`P1`

证据：
- 默认样本量是 `iterations=10`，`warmups=2`，`repeat=200`，见 `config/micro_pure_jit.yaml:23-27`。
- `ns_summary()` 只算 `count/mean/median/min/max/p95/stdev`，见 `micro/orchestrator/results.py:260-282`。
- `_driver_impl_run_micro.py` 只是保存 sample 列表和 summary，没有 outlier 处理或检验，见 `micro/_driver_impl_run_micro.py:440-468`。
- `run_kernel_recompile_per_family.py` 用的是各 run 的 median，再对 benchmark ratio 做 geomean，见 `micro/run_kernel_recompile_per_family.py:427-438`，`micro/run_kernel_recompile_per_family.py:830-848`，`micro/run_kernel_recompile_per_family.py:886-980`。
- repo 里其实已经有更严谨的 path，包含 bootstrap CI、IQR outlier fence、Wilcoxon signed-rank，但当前 audited driver 没有接这条路，见 `micro/_driver_impl_run_rigorous.py:740-795`。

影响：
- `10` 个 outer iterations 对微架构噪声估计偏弱。
- geomean of medians 适合做 dashboard，不适合当强统计结论。

修复建议：
- headline 结果切到 rigorous driver，至少输出 paired bootstrap CI 和 signed-rank p-value。
- 对 tiny rows 加稳定性门槛，例如 CI half-width 超过 2% 则不计入 headline。

### 4.2 Corpus 统计问题更严重：基本是一目标一次 fresh pair

严重程度：`P0`

证据：
- `build_summary()` 只是筛 `compile_pairs` / `measured_pairs`，然后做 geomean / median / min/max / wins/losses，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:861-1009`。
- measured pairs 的定义是 baseline 和 v5 当次 fresh run 都成功，没有任何重复采样，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:868-873`。
- checked-in authoritative corpus 也确实只给出 `measured_pairs = 163`、`exec_ratio_geomean = 0.868144...` 这类聚合值，见 `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json:117-121`。

影响：
- 现在的 corpus headline 更像 “163 个 fresh pair 的一次性快照”，不是可给论文写强结论的统计结果。
- 没有 per-target 重复，就没有 target-level CI，也无法估计 VM boot variance、guest scheduling variance、host placement variance。
- 没有 outlier 处理，小量极端 regressions 会强烈拉低 geomean。

修复建议：
- 每个 corpus target 至少做 `N>=10` 个独立 paired reruns；若保留 VM，至少跨多个 guest boot 复测。
- 对 per-target ratio 做 paired bootstrap CI。
- 对 suite geomean 做 block bootstrap；同时报告 trimmed geomean / median ratio。

## 5. Coverage 分析

严重程度：`P0`

证据：
- Micro suite 一共 56 个 benchmark，见 `config/micro_pure_jit.yaml` manifest；我复核计数后为 `56`。
- 其中只有 `24` 个 benchmark 带 `policy_file`。
- checked-in authoritative fixed-policy 结果里，总结写的是 `applied_pairs = 8`，见 `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json:101641`。
- 这 8 个 applied benchmark 分别是：`log2_fold`、`cmov_select`、`cmov_dense`、`bounds_ladder`、`mixed_alu_mem`、`large_mixed_500`、`bpf_call_chain`、`memcmp_prefix_64`。这是我从该 artifact 的 per-benchmark run records 重新统计出来的。

更关键的问题不是“少”，而是“混”：
- 纯 `cmov`：`micro/policies/cmov_select.yaml:1-10`
- 纯 `wide`：`micro/policies/log2_fold.yaml:1-16`
- 纯 `branch-flip`：`micro/policies/large_mixed_500.yaml:1-16`
- 纯 `rotate`：`micro/policies/memcmp_prefix_64.yaml:1-16`
- `wide + cmov` 混合：`micro/policies/bounds_ladder.yaml:1-19`，`micro/policies/bpf_call_chain.yaml:1-16`，`micro/policies/binary_search.yaml:1-16`，`micro/policies/switch_dispatch.yaml:1-16`
- `wide + extract` 混合：`micro/policies/mixed_alu_mem.yaml:1-16`
- `wide + branch-flip + cmov` 混合：`micro/policies/branch_dense.yaml:1-28`
- 名称与实际 selected family 不匹配：`cmov_dense` benchmark 在 manifest 里被描述为 cmov 密集程序，见 `config/micro_pure_jit.yaml:210-221`；但 checked-in fixed policy 实际选的是 `rotate=26`，见 `micro/policies/cmov_dense.yaml:1-85`

缺口：
- checked-in fixed-policy applied set 里，没有隔离 `endian`、`zero-ext`、`lea` 的专门 benchmark。
- `extract` 也没有单独 isolation benchmark；当前是和 `wide` 混在 `mixed_alu_mem` 里。

影响：
- 当 applied-only headline 只有 8 个 benchmark，而且其中多个 benchmark 同时覆盖多个 family 时，不能把结果解释成“某个 canonical form 天生 net-negative”。
- 现有 suite 更像 “少数有 site 的程序样本”，而不是 “按 canonical form 做干净隔离的实验设计”。

修复建议：
- 每个 family 至少做一组 isolated benchmark：
  - `wide-only`
  - `rotate-only`
  - `extract-only`
  - `endian-only`
  - `cmov-only`
  - `zero-ext-only`
  - `lea-only`
  - `branch-flip-only`
- 每个 isolated benchmark 再拆成 1-site / 8-site / 32-site 三档。
- 多 family benchmark 继续保留，但只能归类为 interaction suite，不能拿去支撑单 family headline。

## 6. JIT image 验证与行为验证

### 6.1 有 dump 能力，但没有自动化 “只改 site-local bytes” 验证

严重程度：`P1`

证据：
- `llvmbpf` 可以 dump JIT image，见 `micro/runner/src/llvmbpf_runner.cpp:705-708`。
- kernel runner 有 `load_jited_program()` / `load_xlated_program()`，见 `micro/runner/src/kernel_runner.cpp:502-515`，`micro/runner/src/kernel_runner.cpp:529`。
- kernel runner 也支持 `dump_jit` / `dump_xlated`，见 `micro/runner/src/kernel_runner.cpp:1152-1159`。
- 但我没有在 micro/corpus 主测量路径里找到任何自动化 diff：没有 “baseline JIT image vs recompiled JIT image” 的字节级比对，也没有 “差异必须落在 site 覆盖的 allowed ranges 内” 的检查。
- corpus v5 batch 只会从 baseline compile 导出 `xlated` 给 scanner，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:525-560`，没有对 pre/post JIT image 做对比。

影响：
- 当前 benchmark framework 不能自动证明 “re-JIT 只在目标 site 改了预期字节，没有意外改动其他位置”。

修复建议：
- 增加 `jit_diff_audit.py`：
  - dump baseline 和 recompiled JIT image
  - 解析 policy sites
  - 验证 diff 只出现在允许的机器码窗口内
  - 把 diff 摘要写入结果 JSON

### 6.2 行为验证是局部存在、主路径缺失

严重程度：`P1`

证据：
- Micro 路径会检查 sample `result` 是否等于 benchmark `expected_result`，见 `micro/benchmark_catalog.py:184`，`micro/_driver_impl_run_micro.py:427-431`。
- 但这不是 stock-vs-recompile paired equivalence check，也不检查 `retval`。
- `corpus/_driver_impl_run_corpus_perf.py` 有 `compute_correctness()`，会比对 `result` 和 `retval`，见 `corpus/_driver_impl_run_corpus_perf.py:267-289`，并在该 driver 中写入结果，见 `corpus/_driver_impl_run_corpus_perf.py:416-417`。
- `run_corpus_runnability.py` 也复用了 correctness 结果，见 `corpus/run_corpus_runnability.py:612`。
- 但 **当前被用来出 authoritative corpus numbers 的 `corpus/_driver_impl_run_corpus_v5_vm_batch.py` 没有 correctness 字段**。它只保存 `baseline_run`、`v5_run` 和 `speedup_ratio`，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:632-653`。
- kernel unit tests 里有少量行为保持测试：wide 保持，见 `tests/kernel/test_recompile.c:1157-1203`；diamond cmov 保持，见 `tests/kernel/test_recompile.c:1503-1550`；rotate 保持，见 `tests/kernel/test_recompile.c:1553-1600`；还有 `recompile_count` 自增测试，见 `tests/kernel/test_recompile.c:1205-1252`，`tests/kernel/test_recompile.c:1602-1655`。

影响：
- authoritative corpus benchmark 没有把行为等价性作为 fresh measurement 的 hard gate。
- 单元测试覆盖了一些 toy case，但没有替代主 benchmark 流水线里的自动校验。

修复建议：
- 在 `corpus_v5_vm_batch` 中引入和 `corpus_perf` 相同的 `compute_correctness()`，默认把 mismatch 视为 invalid pair。
- Micro 也应补上 `retval` 校验，并允许 benchmark 定义多维 expected outputs。

## 7. Corpus 测量路径

### 7.1 最大问题：所有 packet 程序都吃同一个固定 64B dummy packet，而且没有证明它走到了优化路径

严重程度：`P0`

证据：
- runnability 把 packet-capable 程序统一归到 `packet_test_run`，见 `corpus/run_corpus_runnability.py:243-251`。
- 对 `packet_test_run`，execution plan 固定为 `io_mode="packet"`、`input_size=64`、`raw_packet=True`，见 `corpus/run_corpus_runnability.py:308-315`。
- dummy packet 是固定的 Ethernet/IPv4/TCP 64B 包，见 `micro/orchestrator/corpus.py:26-55`。
- inventory 只挑 `strategy == "packet_test_run"` 且此前 baseline run 成功的目标，见 `micro/orchestrator/inventory.py:214-220`。
- corpus v5 batch 通过 `memory_path` 复用 inventory 给的包，runner 也把 `raw_packet=(io_mode == "packet")` 带进去，见 `micro/orchestrator/inventory.py:229-233`，`corpus/common.py:221-230`。
- 我复核了 checked-in authoritative corpus 结果：166 个 program 只有 **1 个 distinct `memory_path`**，就是 `micro/generated-inputs/corpus_dummy_packet_64.bin`。

结论：
- 现在的 corpus benchmark 只证明了：这些程序在 **同一份固定 dummy packet** 上的 `bpf_prog_test_run` 表现如何。
- 它没有证明：
  - 该包真的走到了被优化 site
  - 该包覆盖的是热路径
  - 该包对不同源码来源的程序具有可比性

这件事为什么是 `P0`：
- 如果一个 `rotate/endian/extract/wide` site 根本没被这个 dummy packet 触发，那么把该程序纳入 “优化后变慢” 的分母，本质上是在测 framework 噪声与 unrelated path，而不是在测优化本身。

修复建议：
- 每个 corpus 程序至少要有 “path witness”：
  - 要么动态 site counter 证明 selected site 执行过
  - 要么 scanner + symbolic / heuristic input generation 给出能命中的输入
  - 要么基于程序返回值/side effect 设计 targeted packet family
- 若无法证明 site 被触发，该程序不能进入 optimization-performance headline。

### 7.2 顺序固定，而且偏向让 v5 更热；即便如此结果仍然负面

严重程度：`P1`

证据：
- 在同一个 guest boot 内，执行顺序固定为：
  - `baseline_compile_raw`
  - scanner
  - `v5_compile_raw`
  - `baseline_run_raw`
  - `v5_run_raw`
  见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:525-624`。
- 每个 target 只 boot 一次 fresh VM，然后在该 VM 里完成上述整套流程，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:756-826`，`corpus/_driver_impl_run_corpus_v5_vm_batch.py:1358-1378`。

影响：
- `v5_run_raw` 总是最后执行，因此天然享受更热的页缓存、loader path、部分代码路径热身。
- 这意味着当前固定顺序偏差**大概率是偏向 v5 的**，而不是偏向 baseline。
- 因此如果在这种偏向下结果仍然负面，说明 regression signal 不能完全靠“后测更冷”解释掉；但它仍然不是干净实验，因为顺序没有随机化。

修复建议：
- 对每个 target 随机化或 counterbalance 顺序，至少支持 `ABBA` / `BAAB`。
- compile-only scanner pass 不应与 measured run 共用同一顺序模板；否则它会额外预热后续路径。

### 7.3 有 survivorship filtering

严重程度：`P1`

证据：
- inventory 只保留 `packet_test_run` 且 `baseline_run.ok` 的程序，见 `micro/orchestrator/inventory.py:214-220`。
- v5 batch 的 `measured_pairs` 只统计 baseline/v5 fresh run 都成功的记录，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:868-873`。
- 如果 `v5_compile_raw` 失败，则 `v5_run_raw` 直接不执行，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:605`。

影响：
- headline 只覆盖“能跑通 fresh pair 的幸存者集合”。
- 这对 “可部署性” 是合理过滤，但对 “优化本身性能” 会引入选择偏差。

修复建议：
- 把 `targets_attempted`、`compile_pairs`、`measured_pairs`、`applied_programs` 始终并列报告。
- 额外输出 “all-attempted pessimistic” 和 “measured-only optimistic” 两种 summary。

### 7.4 VM 本身会引入噪声，但不是这里的主问题

严重程度：`P2`

证据：
- target 是在 guest 里跑的，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:678-701`，`corpus/_driver_impl_run_corpus_v5_vm_batch.py:756-826`。
- 但真正的 `exec_ns` 仍来自 guest 内 `micro_exec -> bpf_prog_test_run_opts()`，而不是 host 侧 `vng` wall clock，见 `corpus/_driver_impl_run_corpus_v5_vm_batch.py:685-700` 与 `micro/runner/src/kernel_runner.cpp:1306-1360`。

结论：
- VM boot 时间不会直接污染 `exec_ns`。
- baseline/v5 也在同一个 guest boot 里完成，所以大量 host-side 条件会在 pair 内抵消。
- 但由于每个 target 只有一个 guest boot，没有重复 boot 采样，VM-to-VM 方差完全没有被估计。

修复建议：
- 不是必须去掉 VM，但必须在 VM 模式下做 repeated paired reruns，并报告跨 guest boot 的方差。

## 8. 对当前性能数据可信度的最终评估

### 8.1 Micro

- `ktime` 分辨率不是当前 micro 结论的头号问题。真正的问题是 applied coverage 太小、family 混合太重、A/B 不是 same-process strict pair。
- 因此：
  - “在当前 harness + 当前 8 个 applied fixed-policy benchmark 上，recompile 没有明显大胜” 这个结论有一定可信度。
  - “wide/rotate/extract/endian 这些 canonical form 理论上恒快，但实测整体净负” 这个结论 **不成立**。现有 micro 设计还没有把这个命题测干净。

### 8.2 Corpus

- 现在的 corpus 结果最强能支持的说法是：
  - “在 VM 里的 packet_test_run harness、固定 dummy packet、单次 fresh pair、无 path witness 的设置下，当前 v5 fixed/blind numbers 很差。”
- 现在**不能**支持的说法是：
  - “这些 canonical form 在真实 workload hot path 上普遍净负”
  - “corpus 0.875x 足以推翻这些 peephole 在 steady-state 上的理论正收益”

总体可信度评级：
- Micro headline 作为 family-level 结论：`Low`
- Corpus headline 作为 optimization-quality 结论：`Low`
- Corpus headline 作为 harness-health 警报：`High`

## 9. 修复优先级建议

### P0

1. 给 corpus 加 path witness，证明输入真的触发 selected site；否则该程序不计入优化性能 headline。
2. 重做 corpus 统计：每目标多次 fresh paired rerun，输出 CI / bootstrap / trimmed geomean。
3. 重做 micro coverage：每个 canonical form 都要有 isolated benchmark，interaction benchmark 另算。

### P1

1. kernel runner 同时输出 `ktime` 和 `wall_tsc`，并对 tiny row 做 unstable 标记。
2. 在 runner 内加入 load/recompile 后 warmup，分离 first-hit 与 steady-state。
3. 在 micro/corpus 主路径加入 automated JIT diff 和 correctness gate。
4. corpus 顺序随机化，消除固定 `baseline -> v5` 顺序。

### P2

1. 增加 same-process paired micro mode。
2. VM 模式下采多 boot 方差；若成本高，至少对 top regressors 这样做。
