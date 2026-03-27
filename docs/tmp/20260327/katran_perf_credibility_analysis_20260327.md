# Katran corpus 性能测量可信度审查（2026-03-27）

## 结论摘要

- 当前 artifact `corpus/results/vm_corpus_20260327_152910/` 可以可信回答“到底 apply 了什么、哪些 PC 命中了、代码尺寸怎么变了、返回值是否一致”。
- 当前 artifact **不可以** 可信回答“Katran 在 corpus 里到底快了多少”。原因不是单点噪声，而是测量设计本身对 `<100ns` 的程序不稳。
- 关键澄清：当前代码里 `speedup_ratio = baseline_exec_ns / rejit_exec_ns`，所以：
  - `0.75` 不是“快 25%”，而是 `18ns -> 24ns`，即 **rejit 更慢**。
  - `0.625` 不是“快 37.5%”，而是 `15ns -> 24ns`，即 **rejit 更慢**。
  - `0.5` 不是“快 50%”，而是 `10ns -> 20ns`，即 **rejit 更慢**。
  - `1.048` 才表示 `22ns -> 21ns`，即 **rejit 约快 4.8%**。
- `balancer_ingress` 的 7 个 `map_inline` hit 和 `jited_size -13 bytes` 是真的；但 `exec_ratio=0.75` 这个 runtime 结论 **不可信**。
- 对 `balancer_ingress` 的真实性能判断，应优先相信 live e2e：`229.58ns -> 225.86ns`，约 **1.6%** 改善，而不是这次 corpus 的 `18ns -> 24ns`。

## 1. 本次检查读了什么

已读 artifact：

- `corpus/results/vm_corpus_20260327_152910/details/result.json`
- `corpus/results/vm_corpus_20260327_152910/metadata.json`
- `corpus/results/vm_corpus_20260327_152910/details/progress.json`

raw sample 检查结果：

- `find corpus/results/vm_corpus_20260327_152910 -name '*.json' -o -name '*.jsonl'`
- 只找到 3 个文件：`metadata.json`、`details/result.json`、`details/progress.json`
- **没有** per-program raw sample JSON/JSONL
- 因此这次 run **无法** 从 artifact 里恢复 `REPEAT=50` 的 per-repeat 分布，也无法计算真正意义上的 `median/mean/p5/p95`

## 2. 这次 run 到底 apply 了什么、怎么 apply 的

### 2.1 Pass 集合

`metadata.json` / `result.json` 显示：

- `benchmark_profile = null`
- `repeat = 50`
- `warmups = null`
- `selected_passes = null`

默认 pass 集合来自 `corpus/config/benchmark_config.yaml:8-17`：

- `performance = [map_inline, const_prop, dce]`
- `active = performance`

当前 Katran 结果里的 `pass_details` 也只出现了：

- `map_inline`
- `const_prop`
- `dce`

所以这次 Katran corpus 确实是在做 request-level 的：

- `map_inline -> const_prop -> dce`

没有混入 live e2e 里看到的 `wide_mem` / `endian_fusion`。

### 2.2 apply 方式

`corpus/modes.py:1544-1715` 的 `build_object_batch_plan_v2()` 明确把每个 object 的 batch 顺序固定为：

1. baseline object compile
2. baseline per-program compile
3. baseline per-program run
4. rejit object compile
5. rejit per-program compile
6. rejit per-program run

也就是说：

- baseline 总是在前
- rejit 总是在后
- 二者是两个独立 `prepared_group`
- 不是 paired alternating，也不是 randomized order

另外，rejit jobs 是通过 `daemon_socket + enabled_passes` 下发的，见 `corpus/modes.py:1643-1713`。所以这次不是“静态预先改 object”，而是运行时 request-level apply。

### 2.3 ratio 怎么算

`corpus/modes.py:652-664`：

```python
baseline_ns = ((baseline_record.get("sample") or {}).get("exec_ns"))
rejit_ns = ((rejit_record.get("sample") or {}).get("exec_ns"))
return float(baseline_ns) / float(rejit_ns)
```

所以：

- `speedup_ratio = baseline_exec_ns / rejit_exec_ns`
- `> 1.0` 表示 rejit 更快
- `< 1.0` 表示 rejit 更慢

### 2.4 结果里保留的到底是什么样本

`corpus/modes.py:784-804` 的 `batch_job_invocation_summary()` 只保留 `samples[-1]`。

`runner/src/main.cpp:62-70` 也明确写了：

> keep-alive mode returns the final measured sample for multi-phase kernel REJIT runs

所以当前 corpus 结果不是“50 个独立样本的统计摘要”，而是：

- 一次 `BPF_PROG_TEST_RUN(repeat=50)` 返回的 **单个平均 duration**
- 再加上该 phase 的单个 `wall_exec_ns` / `exec_cycles`

这也是为什么当前 artifact 根本没有可用的分布信息。

### 2.5 `exec_ns` 的来源

`runner/src/kernel_runner.cpp:417-429`：

- `bpf_prog_test_run_opts(...)`
- `measurement.exec_ns = context.test_opts->duration`

内核实现 `vendor/linux-framework/net/bpf/test_run.c:36-60,389-427` 说明：

- 定时器来自 `ktime_get_ns()`
- `repeat` 次循环后把总时间除以 `repeat`
- 输出的是 **平均 duration**

因此当前 `exec_ns` 不是 wall clock per invocation 分布，而是：

- 一次 syscall 内部的 `ktime_get_ns()` 平均值

对 `10ns ~ 24ns` 这种量级，这个指标本身已经非常接近计时分辨率边界。

### 2.6 warmup 现状

这里要区分“配置没传”和“最终测量是否真的有 warmup”：

- `build_test_run_batch_job()` 只写入 `repeat`，不写 `warmup_repeat`，见 `corpus/modes.py:722-760`
- `batch_runner.cpp:1249-1250` 的默认值是 `repeat=...`、`warmup_repeat=5`
- 但是 `kernel_runner.cpp:2948-3004` 和 `3628-3678` 说明：
  - 只有 `measure_same_image_pair` 时才会用 `options.warmup_repeat`
  - 当前 daemon/request-level corpus 路径因为有 `daemon_socket`，`measure_same_image_pair == false`
  - 最终 measured run 调用的是 `execute_kernel_measurement_pass(..., 0u, ...)`

结论：

- 这条 corpus 路径 **没有把 benchmark config 的 warmups 显式接进来**
- 对当前 daemon/request-level measured run 来说，**最终测量 pass 实际是 0 warmup**

### 2.7 correctness check 现状

当前结果里有：

- `retval`
- `result`

但 corpus 层并没有做显式的 stock/rejit equality gate。

`runner/include/micro_exec.hpp:166` 和 `runner/src/kernel_runner.cpp:3036-3042,3718-3723` 里的 `correctness_mismatch` 只在 **same-image paired** 路径下设置。当前 daemon/request-level corpus 不走这个分支。

所以本次 artifact 能说的是：

- stock / rejit 返回值看起来一致

但不能说：

- 当前 corpus 路径有强 correctness assertion 机制

## 3. 五个 Katran 程序逐个分析

## 3.1 `balancer_ingress`

对象：

- `katran:balancer.bpf.o:balancer_ingress`

### 实际 apply 了什么

只看到 `map_inline` 改写，`const_prop` / `dce` 都没有变化：

- `map_inline`: `sites_found=64`, `sites_applied=7`, `sites_skipped=57`
- `const_prop`: `sites_applied=0`
- `dce`: `sites_applied=0`

7 个成功 inlining 的 PC：

- `1059`
- `1248`
- `1354`
- `1636`
- `1764`
- `1952`
- `2267`

主要 skip reason：

- `lookup key is not a constant stack or pseudo-map-value materialization`: 24
- `lookup result has non-load uses`: 20
- `lookup result is not consumed by fixed-offset scalar loads`: 9
- `map type 12 not inlineable in v1`: 2
- `map type 13 not inlineable in v1`: 2

### 代码尺寸变化

- `insn_count`: `2546 -> 2546`，`delta = 0`
- `xlated_prog_len`: `23872 -> 23872`，无变化
- `jited_prog_len`: `13645 -> 13632`
- `jited_size delta = -13 bytes`
- `size_delta_pct = -0.09527299377061195%`

这是一个非常小的 code-size 变化。

### 运行时数值

- `baseline exec_ns = 18`
- `rejit exec_ns = 24`
- `speedup_ratio = 18 / 24 = 0.75`

按当前实现，这表示：

- **rejit 更慢 33.3%**

同一个 sample 里的其他指标：

- `wall_exec_ns: 324033 -> 275469`
- `exec_cycles: 1194410 -> 1015418`

也就是说：

- `exec_ns` 说“变慢”
- `wall_exec_ns` / `exec_cycles` 却说“变快”

连同一条 sample 内部的指标方向都不一致。

### `REPEAT=50` 样本分布

当前 artifact **没有 raw samples**，因此：

- 不能给出真实的 `median/mean/p5/p95`
- 也不能回答 stock/rejit 的 `exec_ns` 分布是否有 outlier

当前能看到的只有：

- 一次 `repeat=50` syscall 返回的单个平均 `exec_ns`

### correctness

当前结果里：

- `retval: 2 -> 2`
- `result: 0 -> 0`

所以这次 stock / rejit 的返回值是一样的。

但要注意：

- 这里只是“结果相同”
- 不是“当前 corpus 路径显式做了 paired correctness assertion”

### 可信度判断

`size_delta_pct` 只有 `-0.095%`，理论上当然不排除某几个热路径指令能带来超出 size change 的收益；但当前 artifact **根本不足以支持** “这个程序快了 25%” 或 “慢了 33%” 这种结论。

核心理由有两个：

- 同一次 run 里，无 pass 程序也出现了更大的 runtime 漂移
- 同一天的定向测量 `#524` 在 **同样 7 个 map_inline PC** 上给出了完全相反的结论：`14ns -> 7ns`，`2.0x`

所以这次 `0.75` 只能说明：

- 当前 corpus `exec_ns` 对 `balancer_ingress` 不稳定

不能说明：

- `map_inline` 让 `balancer_ingress` 真正变慢了 33%

## 3.2 `xdp_pktcntr`

对象：

- `katran:xdp_pktcntr.bpf.o:pktcntr`

### 实际 apply 了什么

发生了真实的级联优化：

- `map_inline`: `sites_found=2`, `sites_applied=1`, `sites_skipped=1`
- 成功 PC：`7`
- skip PC：`15`，原因 `lookup result has non-load uses`
- `const_prop`: `sites_found=1`, `sites_applied=1`
- `dce`: `sites_found=10`, `sites_applied=10`
- `dce diagnostics`: `removed 9 unreachable insns`, `removed 1 nop insns`

### 代码尺寸变化

- `insn_count`: `22 -> 12`
- `insn_delta = -10`
- `xlated_prog_len`: `288 -> 144`
- `jited_prog_len`: `177 -> 94`
- `size_delta_pct = -46.89265536723164%`

这是一个非常扎实的 shrink。

### 运行时数值

- `baseline exec_ns = 21`
- `rejit exec_ns = 21`
- `speedup_ratio = 1.0`

其他指标：

- `wall_exec_ns: 321947 -> 285118`
- `exec_cycles: 1186733 -> 1051011`

### 可信度判断

对这个程序，结论应分成两部分：

- “代码缩小了一半左右”是可信的
- “exec 没变”只能算“当前计时下看不出来”，不是强结论

这和之前 `#508` 的结论是一致的：

- `22 -> 12` insns、`177 -> 94` bytes 这类 code-size 收益是真的
- 但 `exec_ns` 在这个量级上非常容易被量化噪声淹没

## 3.3 `healthcheck_encap`

对象：

- `katran:healthchecking.bpf.o:healthcheck_encap`

### 实际 apply 了什么

没有任何 pass 生效：

- `map_inline`: `sites_found=9`, `sites_applied=0`, `sites_skipped=9`
- `const_prop`: unchanged
- `dce`: unchanged

代码完全不变：

- `insn_count`: `325 -> 325`
- `xlated_prog_len`: `3008 -> 3008`
- `jited_prog_len`: `1634 -> 1634`

### 运行时数值

- `baseline exec_ns = 15`
- `rejit exec_ns = 24`
- `speedup_ratio = 15 / 24 = 0.625`

按当前公式，这表示：

- **rejit 更慢 60%**

但同一条 sample 的其他指标是：

- `wall_exec_ns: 7361 -> 449`
- `exec_cycles: 27133 -> 1655`

这两个指标却像是在说：

- **rejit 大幅更快**

### 可信度判断

这是本次 artifact 最严重的红旗之一。

因为这里没有任何代码变化，所以：

- `15 -> 24`
- `7361 -> 449`
- `27133 -> 1655`

这三组互相打架的数字，唯一能证明的是：

- 当前测量链路对这种短程序极不稳定

它既不能证明“rejit 变慢 60%”，也不能证明“rejit 变快很多”；它只能证明当前方法本身有严重偏差。

## 3.4 `healthchecking_ipip`

对象：

- `katran:healthchecking_ipip.bpf.o:healthcheck_encap`

### 实际 apply 了什么

同样没有任何 pass 生效：

- `map_inline`: `sites_found=4`, `sites_applied=0`, `sites_skipped=4`
- `const_prop`: unchanged
- `dce`: unchanged

代码完全不变：

- `insn_count`: `103 -> 103`
- `xlated_prog_len`: `1000 -> 1000`
- `jited_prog_len`: `550 -> 550`

### 运行时数值

- `baseline exec_ns = 10`
- `rejit exec_ns = 20`
- `speedup_ratio = 10 / 20 = 0.5`

按当前公式，这表示：

- **rejit 更慢 100%**

但其他指标却是：

- `wall_exec_ns: 1859 -> 270`
- `exec_cycles: 6853 -> 996`

### 可信度判断

这比上一个更极端：

- 代码零变化
- `exec_ns` 却翻倍
- `wall_exec_ns` / `cycles` 却大幅下降

这基本可以视为对当前 `<100ns` corpus `exec_ns` 方法的直接否定。

如果一个完全没改代码的程序都能在这套方法下得到 `10ns -> 20ns`，那 `balancer_ingress` 的 `18ns -> 24ns` 就没有足够证据解释成真实优化效果。

## 3.5 `xdp_root`

对象：

- `katran:xdp_root.bpf.o:xdp_root`

### 实际 apply 了什么

完全没有 pass 生效：

- `map_inline`: `sites_found=0`, `sites_applied=0`
- `const_prop`: unchanged
- `dce`: unchanged

代码完全不变：

- `insn_count`: `17 -> 17`
- `xlated_prog_len`: `136 -> 136`
- `jited_prog_len`: `185 -> 185`

### 运行时数值

- `baseline exec_ns = 22`
- `rejit exec_ns = 21`
- `speedup_ratio = 22 / 21 = 1.047619...`

这次按当前公式表示：

- **rejit 约快 4.8%**

其他指标：

- `wall_exec_ns: 314922 -> 270219`
- `exec_cycles: 1160865 -> 996091`

### 可信度判断

虽然这里的漂移比两个 healthcheck 小，但本质问题一样：

- 代码零变化
- 结果仍然能给出一个“有性能差异”的答案

这说明当前 corpus 方法没有能力把“零变化”和“小幅性能变化”稳定区分开。

## 4. 这次结果为什么不可信

## 4.1 没有 raw distribution，只有一个平均值

当前 artifact 没有保存：

- 50 次 repeat 的原始样本
- 多次 outer invocation 的样本

当前 ratio 只是：

- `一次 baseline 的平均 exec_ns`
- 除以
- `一次 rejit 的平均 exec_ns`

这不是统计分布，也不是稳健摘要。

## 4.2 当前程序太短，`exec_ns` 已经接近计时地板

这 5 个 Katran 程序的 `exec_ns` 是：

- `10ns`
- `15ns`
- `18ns`
- `21ns`
- `22ns`
- `24ns`

这种量级下，`BPF_PROG_TEST_RUN` 的 `ktime_get_ns()` 平均 duration 很容易受分辨率、调度切片、上下文噪声影响。

对这种样本，`repeat=50` 明显不够。

## 4.3 非配对、固定顺序测量，会引入系统性 phase bias

当前顺序是：

- 先 baseline 全部测完
- 再测 rejit

不是：

- `stock -> rejit -> stock -> rejit`

也不是：

- randomized order

因此 stock phase 和 rejit phase 之间可能系统性不同：

- CPU frequency ramp
- cache/TLB 状态
- prepared object 状态
- daemon apply 后的热状态
- allocator / slab / map / packet path 的残余状态

这不是猜测，因为结果里已经出现了明显相位偏差：

- `healthcheck_encap` 的 `prog_run_wall_ns: 368141 -> 22602`
- `healthchecking_ipip` 的 `prog_run_wall_ns: 93058 -> 13633`

在代码完全相同的前提下，这种数量级变化不可能被解释为“真实优化”。

## 4.4 同一个 sample 内部，指标方向互相冲突

最典型的是：

- `balancer_ingress`: `exec_ns` 说慢了，`wall_exec_ns` / `exec_cycles` 说快了
- `healthcheck_encap`: `exec_ns` 说慢了，`wall_exec_ns` / `exec_cycles` 说大幅快了
- `healthchecking_ipip`: 同上

这说明当前单次样本甚至不能稳定决定“方向”。

## 4.5 当前路径没有显式 paired correctness / paired timing

当前 daemon/request-level corpus 路径没有启用：

- same-image paired 测量
- paired correctness mismatch 标记

因此这次 run 在 runtime 可信度上，先天就弱于 live e2e 的 same-image paired 结果。

## 5. 和之前结果对比

## 5.1 `#508`：xdp_pktcntr 的 code-size 收益可信，exec_ns 不可信

`#508` 已经给出过一个方向非常一致的结论：

- `22 -> 12` insns、`177 -> 94` jited bytes 是真的
- 但这个程序太短，`exec_ns` 很容易受噪声支配

这和本次 `xdp_pktcntr` 的观察完全一致。

## 5.2 `#520` / `#521`：live e2e 的 `balancer_ingress` 只有约 1.6% 改善

live e2e 结果：

- `229.58ns -> 225.86ns`
- `speedup_ratio = 1.016x`

这比当前 corpus 的 `18ns -> 24ns` 更可信，原因很简单：

- live path 更长，远离计时地板
- 有 outer cycles
- same-image paired
- 更接近真实 workload

所以如果要回答“`balancer_ingress` 到底有没有实质收益”，当前最可信的现有证据是：

- **有，但大约只是低单百分比，而不是 25% 级别**

## 5.3 `#524`：同样 7 个 `map_inline` PC，same-day 定向 corpus 给出了相反结论

同一天的定向 run `#524` 记录为：

- 同样的 `balancer_ingress`
- 同样的 `map_inline` 7 个命中
- `jited_prog_len: 13645 -> 13632`
- 但 `exec_ns: 14 -> 7`
- `speedup_ratio = 2.0x`

这和本次 batch run 的：

- `18 -> 24`
- `0.75x`

方向完全相反。

代码变化一样，runtime 结论却从“快 2 倍”跳到“慢 33%”，这几乎已经直接证明：

- 当前 sub-100ns corpus timing 不能拿来当真值

## 5.4 `#474e`：历史 `0.854x` 结论的符号需要重新核实

当前 `corpus/modes.py:652-664` 的定义是：

- `speedup_ratio = baseline / rejit`

按这个定义，`0.854x` 数学上表示的是：

- `rejit_exec_ns > baseline_exec_ns`

而不是“rejit 更快”。

因此 `#474e` 文档里“`0.854x` 表示快约 17%”这一点，至少在当前代码语义下是 **符号相反** 的。是否当时代码语义不同，需要单独回看对应 commit；在重新核实前，不应继续引用这条数字来支持性能收益结论。

## 6. 最终判断：`balancer_ingress` 的 `exec_ratio=0.75` 到底可不可信

我的判断是：

- `map_inline` 确实命中了 7 个 site，这点可信
- `jited_size -13 bytes` 这点可信
- `retval` / `result` 一致，这点可信
- `exec_ratio=0.75` **不可信**

更具体地说：

- 它不是“快 25%”，而是当前实现下的 `18ns -> 24ns`
- 但这 6ns 差值本身没有统计意义可言
- 同一批结果里两个零变化 healthcheck 程序出现了更大的漂移
- 同一天同程序同样 7 个命中又能测出 `14ns -> 7ns`
- live e2e 真值只支持约 `1.6%` 的改善

因此对 `balancer_ingress` 的合理结论应该是：

- 当前 corpus run 只证明“7 个 map_inline site 被成功 apply，代码略微缩小”
- **不能** 证明 runtime 有 `25%` 级别的收益或损失

## 7. 建议如何改进测量方法

### 7.1 先把 artifact 保存全

必须保留：

- per-program outer samples
- 每次 outer sample 的 `exec_ns` / `wall_exec_ns` / `exec_cycles`
- batch 临时结果文件，不要在 `corpus/modes.py:2433-2435` 直接删掉

否则事后根本无法做可信度审查。

### 7.2 对短程序把 `repeat` 提高到至少 `500`

建议：

- 默认 short-program profile：`repeat >= 500`
- 对 `<50ns` 的程序：`repeat >= 1000`

`repeat=50` 对当前 Katran 这几个程序明显不够。

### 7.3 增加 outer iterations，并报告稳健统计量

至少需要：

- `N >= 9` 或 `N >= 15` 个 outer invocations

然后报告：

- `median`
- `mean`
- `p5`
- `p95`

当前“一次平均值比一次平均值”的做法不可接受。

### 7.4 改成严格 paired / alternating 测量

建议顺序改成：

- `stock -> rejit -> stock -> rejit`

或者：

- randomized order

更好的方案是：

- 直接复用 same-image paired 路径

这样可以同时得到：

- 更好的 timing pairing
- `correctness_mismatch` 检查

### 7.5 让 daemon/request-level corpus 路径真正使用 warmup

当前 measured pass 是 0 warmup。

建议：

- 把 benchmark config 的 `warmups` 显式传到 batch job
- 并在 daemon/request-level measured run 上真正执行 warmup

### 7.6 给超短程序加可信度门槛

建议把下面这类程序标记为“timing-floor dominated”：

- `median exec_ns < 100ns`

对这类程序：

- 不要用它们的 `exec_ns` 参与 geomean 主结论
- 至少要同时看 `wall_exec_ns` / `exec_cycles`

## 8. 一句话结论

`vm_corpus_20260327_152910` 对 Katran 的价值主要在于“证明 pass 确实 fire 了哪些 site、代码尺寸变了多少”；它**不具备**证明 `balancer_ingress` runtime 变化幅度的可信度。当前最可信的现有证据仍然是 live e2e 的约 `1.6%` 改善，而不是这次 corpus 的 `0.75x`。
