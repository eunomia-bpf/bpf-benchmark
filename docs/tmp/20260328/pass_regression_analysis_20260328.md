# Corpus Pass Regression Analysis (2026-03-28)

## 1. 范围与口径

本报告分析 corpus dev run `vm_corpus_20260328_194356` 的 pass-regression 关联，目标是回答：

1. 哪些 pass/组合导致回归。
2. 哪些 pass/组合带来加速。
3. 是否存在“几乎总是帮倒忙”或“几乎总是有帮助”的 pass。
4. 不同 repo 的 pattern 是否明显不同。
5. 基于现有数据，给出一个简单可执行的默认策略。

使用的数据源：

- `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json`
- `runner/corpus/results/vm_corpus_20260328_194356/metadata.json`

运行状态与覆盖范围：

- `metadata.status = error`
- guest batch 在 `2026-03-28 13:34:31 -07:00` 以 `exit=139` 结束
- 本次只完成了 `288 / 469 objects`
- 已执行 `1149 / 2009 programs`
- 其中有 `255` 个 comparable programs 有 `speedup_ratio`
- comparable programs 中：
- `170` 个 program 至少有一个 pass 实际改了代码
- `85` 个 program `applied_passes = []`

统计口径：

- `speedup_ratio = baseline_exec_ns / rejit_exec_ns`
- `> 1.0` 表示 rejit 更快
- `< 1.0` 表示 rejit 更慢
- 显著加速：`ratio > 1.05`
- 显著回归：`ratio < 0.95`
- `size_delta_pct > 0` 表示 rejit native code 变大
- `size_delta_pct < 0` 表示 rejit native code 变小
- geomean 一律按 ratio 计算

需要先说明两个限制：

- 这次真正出现的 pass 只有三个：`const_prop`、`map_inline`、`dce`
- `dce` 和 `map_inline` 几乎总是和 `const_prop` 绑定出现；因此“单独 blame 某一个 pass”在统计上并不完全可辨识，真正可辨识的是 `const_prop-only` 与 `const_prop + map_inline + dce` 两种模式

## 2. Executive Summary

- 最清晰的结论不是“某个单 pass 总是坏”，而是“`const_prop-only` 和 `const_prop + map_inline + dce` 是两种完全不同的行为模式”。
- `const_prop-only` 是当前最像默认启用候选的 pass 组合：全体样本 geomean `1.031`，在 `baseline_exec_ns >= 200ns` 的更可信子集里 geomean 提升到 `1.154`。
- `const_prop + map_inline + dce` 是当前最明显的风险组合：全体 geomean `0.977`，在 `baseline_exec_ns >= 200ns` 的子集里 geomean 进一步下降到 `0.952`。
- repo pattern 很强：`calico` 主要命中 `const_prop-only` 且总体受益；`bcc` 几乎全是三连组合且总体偏负。
- 代码膨胀不是主要解释。很多高置信度回归发生在 native code 变小的情况下，说明更可能是代码布局、I-cache、branch predictability 或测量噪声，而不是单纯“代码更大所以更慢”。
- `ratio < 0.95` 中有大量极小程序噪声，尤其是 `applied_passes = []` 的 selftests。不能把这些样本直接当成 pass bug。
- 没看到直接支持“语义错误”的证据：255 个 comparable 程序里 `retval` 没有任何 baseline/rejit mismatch。

## 3. 全局快照

全体 comparable programs 的总体表现：

- overall geomean: `0.980`
- applied-only geomean: `0.995`
- unapplied-only geomean: `0.951`
- overall median: `0.995`
- 显著加速：`88 / 255 = 34.5%`
- 显著回归：`103 / 255 = 40.4%`

这里最需要警惕的是 `unapplied-only`：

- `applied_passes = []` 的样本 geomean 只有 `0.951`
- 但它们的 `baseline_exec_ns median` 只有 `44ns`
- 同一组里同时出现了 `34` 个显著回归和 `36` 个显著加速

这说明本数据集里存在很强的“无代码变化也会抖”的噪声/布局扰动底噪。后面凡是谈 pass 回归，都必须拿这组作为噪声基线。

## 4. Per-pass 统计

| pass | 命中程序数 | `>1.05` | `<0.95` | ratio geomean | ratio median |
|---|---:|---:|---:|---:|---:|
| const_prop | 169 | 52 | 68 | 0.996 | 0.992 |
| dce | 107 | 24 | 42 | 0.977 | 0.988 |
| map_inline | 108 | 24 | 43 | 0.975 | 0.987 |

解读：

- `const_prop` 的整体 geomean 只有 `0.996`，看起来接近持平；但这是因为它同时出现在 `const_prop-only` 和“三连组合”里，被后者拖低。
- `map_inline` 和 `dce` 的 presence signal 都偏负：
- `map_inline` 命中样本 geomean `0.975`，不命中样本 geomean `0.984`
- `dce` 命中样本 geomean `0.977`，不命中样本 geomean `0.983`
- 但这里不能直接得出“`dce` 一定比 `map_inline` 更坏”之类的结论，因为这两者几乎总是和 `const_prop` 一起出现。

结论：

- 没有任何单 pass 达到“几乎总是有益”或“几乎总是有害”的统计强度。
- 当前真正能成立的结论是：
- `const_prop` 单独使用时偏好
- 把 `map_inline`/`dce` 叠加上去后，整体风险明显增大

## 5. Pass 组合分析

### 5.1 最常见组合

| 组合 | count | 占比 | `>1.05` | `<0.95` | geomean | median | size_delta median | baseline_exec_ns median |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| `const_prop,dce,map_inline` | 107 | 42.0% | 24 | 42 | 0.977 | 0.988 | -1.600% | 495 |
| `(none)` | 85 | 33.3% | 36 | 34 | 0.951 | 1.000 | 0.000% | 44 |
| `const_prop` | 62 | 24.3% | 28 | 26 | 1.031 | 1.001 | +0.014% | 345 |
| `map_inline` | 1 | 0.4% | 0 | 1 | 0.822 | 0.822 | -0.161% | 83 |

最重要的对比是：

- `const_prop-only`: geomean `1.031`
- `const_prop + map_inline + dce`: geomean `0.977`

也就是说，当前负信号并不是来自 `const_prop` 本身，而是来自“在 `const_prop` 之外又做了 `map_inline/dce` 这一层”。

### 5.2 热程序过滤后，组合差异更明显

为了排除 `7ns`、`30ns`、`40ns` 这种极小程序对比值的大幅抖动，我对 `baseline_exec_ns` 做了门槛过滤：

| baseline_exec_ns cutoff | `const_prop,dce,map_inline` | `const_prop` | `(none)` | total |
|---|---:|---:|---:|---:|
| `>= 0ns` | 0.977 | 1.031 | 0.951 | 0.980 |
| `>= 100ns` | 0.978 | 1.030 | 1.176 | 1.023 |
| `>= 200ns` | 0.952 | 1.154 | 1.411 | 1.072 |
| `>= 500ns` | 0.950 | 1.697 | 1.243 | 1.086 |
| `>= 1000ns` | 0.974 | 1.287 | 0.901 | 0.994 |

解读：

- `const_prop-only` 在热程序上明显更好，不是噪声带出来的假阳性。
- 三连组合在 `>= 200ns` 和 `>= 500ns` 这两个子集里依然低于 1，说明它不是“只在微小程序上显得差”，而是真有一批热程序被拖慢。
- `(none)` 组在热程序里也会大起大落，这进一步说明本数据集存在显著的 run-to-run / layout noise。

### 5.3 是否存在 “pass X + pass Y 特别好/特别差” 的 pattern

存在，但只能看到“三个一起”的 pattern，看不到 pair-only 的独立效果：

- 所有 `const_prop + map_inline`
- 所有 `const_prop + dce`
- 所有 `map_inline + dce`

几乎都来自同一组样本，也就是 `const_prop + map_inline + dce`。因此：

- 可以确认“把 `map_inline/dce` 叠加到 `const_prop` 上”这一整组操作有风险
- 但不能仅靠这批数据把锅精确拆成“`map_inline` 更坏”还是“`dce` 更坏”

### 5.4 prog_type pattern

三连组合在不同 prog type 上差异明显，尤其是热程序子集：

`baseline_exec_ns >= 200ns` 时：

| prog_type | count | geomean | `<0.95` | `>1.05` |
|---|---:|---:|---:|---:|
| kprobe | 36 | 0.934 | 17 | 5 |
| tracepoint | 18 | 1.017 | 6 | 7 |
| tracing | 6 | 0.937 | 3 | 2 |
| raw_tracepoint | 5 | 0.969 | 2 | 1 |
| sched_cls | 1 | 0.578 | 1 | 0 |

`baseline_exec_ns >= 500ns` 时：

| prog_type | count | geomean | `<0.95` | `>1.05` |
|---|---:|---:|---:|---:|
| kprobe | 31 | 0.935 | 13 | 5 |
| tracepoint | 12 | 1.029 | 4 | 4 |
| tracing | 5 | 0.939 | 2 | 2 |
| raw_tracepoint | 3 | 0.971 | 1 | 1 |
| sched_cls | 1 | 0.578 | 1 | 0 |

解读：

- 三连组合最坏的落点是 `kprobe`
- `raw_tracepoint` 和 `tracing` 也偏负
- `tracepoint` 至少没有明显系统性回归，甚至略偏正

因此，“只要出现 `map_inline` 就关掉”太粗暴；更像是：

- `kprobe/raw_tracepoint/tracing + map_inline/dce` 是高风险组合
- `tracepoint + map_inline/dce` 需要继续观察，但目前不如 `kprobe` 那么差

## 6. Per-repo breakdown

| repo | comparable | applied | applied geomean | overall geomean | applied `>1.05` | applied `<0.95` | 主组合 |
|---|---:|---:|---:|---:|---:|---:|---|
| bcc | 103 | 94 | 0.969 | 0.978 | 21 | 36 | `const_prop,dce,map_inline` |
| linux-selftests | 70 | 7 | 1.036 | 0.874 | 1 | 3 | `(none)` |
| calico | 59 | 51 | 1.037 | 1.125 | 24 | 24 | `const_prop` |
| coroot-node-agent | 11 | 11 | 1.005 | 1.005 | 4 | 2 | `const_prop` |
| libbpf-bootstrap | 7 | 5 | 0.981 | 0.997 | 1 | 3 | `const_prop,dce,map_inline` |
| katran | 5 | 2 | 1.063 | 0.919 | 1 | 1 | `(none)` |

### 6.1 哪个 repo 受益最大

按 applied geomean 看：

- 如果不设最小样本数，`katran = 1.063`，但 applied 样本只有 `2`，不够稳
- 设一个更合理的样本下限 `applied_count >= 10`：
- `calico = 1.037`，是最明显的受益 repo
- `coroot-node-agent = 1.005`，基本持平略正

再看热程序：

- `calico` 在 `baseline_exec_ns >= 200ns` 的 applied 子集 geomean 是 `1.176`
- 在 `>= 500ns` 的子集 geomean 进一步到 `2.122`

所以 `calico` 的正信号非常强，且主要来自 `const_prop-only`。

### 6.2 哪个 repo 回归最严重

按 applied geomean 看：

- `bcc = 0.969`，是最明确的负收益 repo
- `libbpf-bootstrap = 0.981`，样本小但也偏负

更关键的是结构原因：

- `bcc` 的 `94 / 103` comparable programs 都命中了 `const_prop + map_inline + dce`
- 这组样本的 geomean 是 `0.969`
- 在 `baseline_exec_ns >= 200ns` 的 bcc 子集里，geomean 仍然只有 `0.957`
- 在 `>= 500ns` 的 bcc 子集里，geomean 仍然只有 `0.954`

这不是 tiny-program noise 能解释掉的。

### 6.3 repo pattern 细看

`calico`

- 几乎全是 `const_prop-only`
- 热程序总体偏正
- `calico_tc_skb_accepted_entrypoint` 是最强受益簇，多个对象都能到 `3x+`
- `calico_tc_main` 整体也偏正
- 但 `*_drop`、`*_ipv4_frag`、`host_ct_conflict` 仍有明显回归样本，说明 `const_prop` 也不是“无脑全开零风险”

`bcc`

- 几乎全是三连组合
- 明确的回归簇集中在 TCP tracing 与 lock tracing
- 代表性负样本：
- `tcpconnlat/tcptracer/tcpconnect` 的 `tcp_v4_connect` / `tcp_rcv_state_process`
- `klockstat` 的 `mutex_lock*` / `down_read*`
- 这些程序很多本来就是 `1us ~ 4us` 量级，不属于纯噪声

`linux-selftests`

- overall geomean 很差，`0.874`
- 但主要原因不是 applied passes，而是 `63 / 70` 个样本压根没有 pass 变化，且大量程序极小
- applied 样本只有 `7` 个，geomean `1.036`
- 所以当前不能把 `linux-selftests` 的整体负值直接归因于 pass

`coroot-node-agent`

- 全是 `const_prop-only`
- 总体接近持平略正
- 暂时更像“可保守默认开启”的证据，而不是需要特别规避的证据

## 7. 回归根因假说

### 7.1 先把噪声和真实回归分开

总共有 `103` 个 `ratio < 0.95` 的回归样本：

- applied regressions: `69`
- unapplied regressions: `34`

按 baseline 执行时间切：

- 全部 regressions 里：
- `< 100ns`: `35`
- `< 200ns`: `54`
- `< 500ns`: `80`
- `>= 1000ns`: `11`
- applied regressions 里：
- `< 100ns`: `8`
- `< 200ns`: `21`
- `< 500ns`: `47`
- `>= 1000ns`: `10`

结论：

- 噪声确实很重，尤其在 sub-100ns / sub-200ns
- 但仍然有 `10` 个 applied regressions 落在 `>= 1000ns`，说明至少有一批是真实热路径回归，不是只有噪声

### 7.2 代码膨胀不是主因

如果“变慢的主要原因是 native code 变大”，那回归程序应该大多呈现 `size_delta_pct > 0`。实际不是这样：

- 在 `69` 个 applied regressions 中：
- `27` 个 native code 变大
- `36` 个 native code 变小
- `37` 个落在 `|size_delta_pct| <= 0.5%`

更关键的是，三连组合本身就直接否定了“代码膨胀主导”这个解释：

- 三连组合 regressions 的 median `size_delta_pct = -1.47%`
- 三连组合 speedups 的 median `size_delta_pct = -1.53%`

也就是说：

- 同一个组合里，回归和加速都经常发生在“代码变小”时
- native size 变化解释不了符号本身，只能解释很小一部分方差

`const_prop-only` 也是类似结论：

- `const_prop-only` regressions 的 median `size_delta_pct = +0.018%`
- `const_prop-only` speedups 的 median `size_delta_pct = +0.014%`

这几乎可以视为“size 不变”。所以 `const_prop-only` 的正负更多像是控制流/布局/寄存器分配后的微架构效应，而不是代码大小效应。

### 7.3 更像 I-cache / layout / branch predictability 问题

当前数据更支持以下解释：

- `map_inline + dce` 虽然经常让代码更短，但它也在改 basic-block 形状、分支布局和常量物化位置
- 对 `bcc` 的 `kprobe` / TCP tracing 这类程序，这种 layout perturbation 更容易伤到前端取指、I-cache 或 branch predictor
- 同类程序的回归和加速都存在，说明效果高度依赖具体 hot path，而不是 pass 本身在语义层面“总是错”

代表性高置信度热程序回归如下：

| program | repo | pass | ratio | baseline ns | rejit ns | size delta |
|---|---|---|---:|---:|---:|---:|
| `bcc:libbpf-tools/tcpconnlat.bpf.o:fentry_tcp_rcv_state_process` | bcc | `const_prop,dce,map_inline` | 0.593 | 1003 | 1691 | -0.298% |
| `bcc:libbpf-tools/tcptracer.bpf.o:tcp_v4_connect` | bcc | `const_prop,dce,map_inline` | 0.597 | 1204 | 2016 | +0.562% |
| `bcc:libbpf-tools/tcpconnect.bpf.o:tcp_v4_connect` | bcc | `const_prop,dce,map_inline` | 0.666 | 1137 | 1708 | +0.870% |
| `bcc:libbpf-tools/tcptracer.bpf.o:tcp_v4_connect_ret` | bcc | `const_prop,dce,map_inline` | 0.838 | 1028 | 1226 | +0.000% |
| `bcc:libbpf-tools/klockstat.bpf.o:kprobe_mutex_lock_interruptible` | bcc | `const_prop,dce,map_inline` | 0.859 | 3076 | 3580 | -1.303% |
| `libbpf-bootstrap:examples/c/bootstrap_legacy.bpf.o:handle_exec` | libbpf-bootstrap | `const_prop,dce,map_inline` | 0.893 | 1225 | 1372 | -2.350% |

这些样本同时覆盖了：

- 代码变大但变慢
- 代码不变但变慢
- 代码变小但变慢

所以“代码大小”最多只是次要因素。

### 7.4 语义问题的证据很弱

从现有数据看，语义 bug 不是当前最优先的解释：

- 255 个 comparable programs 里，`retval` 的 baseline/rejit mismatch 数量是 `0`
- `result` 字段有 `53` 个 mismatch，但这些大多来自 tracing/计数类程序，更可能是运行时事件数本身不稳定，而不是 pass 改坏了语义

因此目前更合理的判断是：

- 先把问题归为 performance regression
- 不把它直接归为 semantic miscompile
- 真要继续追 semantic angle，需要额外的 deterministic replay 或更强的功能一致性校验

## 8. 是否有 pass 几乎总是帮倒忙 / 几乎总是有帮助

严格回答：

- 没有任何单 pass 在这批数据里达到“几乎总是有帮助”或“几乎总是帮倒忙”
- 但存在很明显的“组合层级”结论

更实用的结论是：

- 最接近“默认启用候选”的是 `const_prop-only`
- 最接近“需要 profiling-gated”的是 `map_inline + dce` 这层叠加

原因：

- `const_prop-only`: geomean `1.031`
- `const_prop-only` 且 `baseline_exec_ns >= 200ns`: geomean `1.154`
- 三连组合: geomean `0.977`
- 三连组合且 `baseline_exec_ns >= 200ns`: geomean `0.952`
- 三连组合在 `kprobe` 热程序上: geomean 约 `0.934 ~ 0.942`

## 9. Policy 建议

### 9.1 默认启用

建议默认启用：

- `const_prop`

理由：

- 单独命中时总体偏正
- 在更可信的热程序子集里正信号更强
- `calico` 和 `coroot-node-agent` 的 applied 样本基本都支持这一点

但要保留一个现实 caveat：

- `const_prop` 不是零风险
- `calico` 里仍有 `drop` / `ipv4_frag` / `host_ct_conflict` 之类的负样本
- 所以“默认开启”是对总体收益最优，而不是“每个程序都赢”

### 9.2 profiling-gated

建议改为 profiling-gated：

- `map_inline`
- `dce` 在 `map_inline` 之后的这层 cleanup

理由：

- 当前数据里，这两者的主要呈现形式就是三连组合
- 三连组合总体偏负，且在热程序上仍偏负
- 最明显的受害者是 `bcc` 的 `kprobe` tracing 程序

### 9.3 更保守的 pattern matching

建议首先收紧以下命中条件：

- `kprobe`
- `raw_tracepoint`
- `tracing`

对这些 prog type，如果 `map_inline` 准备触发，默认先不要直接放行；至少应满足更强证据，例如：

- 有明确的多处热点 map load 被消除
- 不是只带来 `0% ~ 2%` 这种边缘级 size 改动
- 或者已有该 exact program 的 profiling 证明它会受益

因为从现有数据看：

- `kprobe + map_inline/dce` 是最稳定的负信号簇
- 很多样本即使代码变小，也还是更慢

### 9.4 一个简单的 per-program policy

可以先落一个非常朴素、但和数据一致的规则：

1. 先运行 `const_prop`。
2. 如果 `map_inline` 没有命中任何 site，就停在这里，不要为了“顺手清理”再启用 `dce`。
3. 如果 `map_inline` 命中了，而 prog type 是 `kprobe`、`raw_tracepoint`、`tracing`，默认关闭 `map_inline + dce`，除非有 profiling 证明该程序受益。
4. 如果程序只有 `const_prop` 命中，则保持开启；当前这类程序的总体信号最好。
5. 如果 `baseline_exec_ns < 100ns`，不要用单次 dev-run 的 ratio 做策略决策；至少需要更多重复测量或多次 run geomean。

把这个规则翻译成更工程化的话就是：

- `const_prop` 默认开
- `map_inline/dce` 默认保守
- “没有 map-inline 机会”时，不要把 pass pipeline 拉长
- 对 tracing/kprobe 类程序，先站在关闭 `map_inline/dce` 一边

## 10. 图表描述

建议在后续 paper / note 里配三张图，最能把这次数据说明白：

- 图 1：按组合绘制 ratio geomean 条形图。
- 预期结论是 `const_prop-only > 1.0`，而 `const_prop + map_inline + dce < 1.0`；`(none)` 组会显得很吵，但这恰好说明噪声地板存在。

- 图 2：`ratio` 对 `baseline_exec_ns` 的散点图，x 轴取 log scale，并按组合着色。
- 预期会看到 `<100ns` 区域点云上下乱飞，而 `const_prop-only` 的热程序更多落在 `>1`，`kprobe + 三连组合` 更多落在 `<1`。

- 图 3：`ratio` 对 `size_delta_pct` 的散点图。
- 预期会看到三连组合的加速和回归都集中在 `-2% ~ 0%` 这一区间，说明“代码变小”并不足以预测“程序会更快”。

## 11. 结论

这批数据最重要的结论不是“某个 pass 坏”，而是：

- `const_prop` 单独使用时是可接受、且往往有益的
- 真正的风险来自在它之上叠加 `map_inline + dce`
- 这个风险在 `bcc`、尤其是 `kprobe` tracing 程序上最明显
- 回归主要不像是 code bloat，更像是 layout / I-cache / branch predictability 问题外加一层小程序噪声

如果现在就要落默认策略，我会选：

- 默认开 `const_prop`
- 默认把 `map_inline + dce` 改成 profiling-gated
- 对 `kprobe/raw_tracepoint/tracing` 先更保守

这是当前最符合数据、且工程风险最低的方案。
