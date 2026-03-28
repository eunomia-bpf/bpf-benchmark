# Corpus Data / Statistics Review 2026-03-28

## 审计范围与数据源

- 最新 `vm_corpus_20260328*` 里真正还带 `details/result.json` 的最新 artifact 是 [`vm_corpus_20260328_212026/metadata.json:5`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_212026/metadata.json#L5) 对应的 `ablation_map_inline_full` 单对象跑，只有 `1 object / 1 program`，不是用户提到的 dev run（见 [`vm_corpus_20260328_212026/metadata.json:1092`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_212026/metadata.json#L1092) 和 [`vm_corpus_20260328_212026/details/result.json:1514`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_212026/details/result.json#L1514)）。
- `483 measured / 364 applied / 0.980x` 来自 dev run artifact [`vm_corpus_20260328_194356/metadata.json:5`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L5)。这个目录现在只剩 `metadata.json`，但 metadata 仍指向 VM 内原始产物：[`vm_corpus_20260328_194356/metadata.json:1002`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L1002) 的 guest result JSON 和 [`vm_corpus_20260328_194356/metadata.json:1004`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L1004) 的 target JSON。
- 本报告的 source of truth 是：
  - [`runner/corpus/results/vm_corpus_20260328_194356/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json)
  - [`docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json)
  - [`docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-clil6g9e.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-clil6g9e.json)
  - [`corpus/results/expanded_corpus_build.latest.json:214`](/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.latest.json#L214)
  - 代码路径 [`runner/libs/results.py:232`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L232), [`runner/libs/statistics.py:18`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/statistics.py#L18), [`runner/libs/corpus.py:1218`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1218), [`runner/libs/corpus.py:1263`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1263), [`runner/libs/corpus.py:1526`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1526), [`corpus/modes.py:251`](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py#L251), [`runner/src/batch_runner.cpp:435`](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp#L435), [`runner/src/batch_runner.cpp:890`](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp#L890)。

## 结论摘要

1. `exec geomean` 是按 program 直接做几何平均，不是先按 object 聚合再平均。一个 object 有多少个 program，就在 overall geomean 里占多少份权重。定义在 [`runner/libs/results.py:246`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L246), [`runner/libs/results.py:279`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L279), [`runner/libs/statistics.py:18`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/statistics.py#L18)。
2. `measured_pairs = 483` 的定义是 “`baseline_run.ok && rejit_run.ok` 的 program 数”，但 geomean 并不是对 483 个 program 算，而是只对其中 `speedup_ratio != null` 的 `255` 个 program 算。`228` 个 `measured_pairs` 因为 `exec_ns` 为 `0` 或缺失，根本没进 geomean。定义路径是 [`runner/libs/results.py:246-280`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L246) 和 [`runner/libs/corpus.py:1122-1134`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1122)。
3. summary 里的 `applied_programs = 364` 不是 C++ 输出里的 `rejit.applied == true`。它实际统计的是 `applied_passes` 非空，也就是至少一个 pass 真正改写了程序；代码在 [`runner/libs/corpus.py:1540-1545`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1540) 和 [`runner/libs/results.py:254`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L254)。C++ 原始布尔值来自 [`runner/src/batch_runner.cpp:458`](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp#L458) 和 [`runner/src/batch_runner.cpp:903`](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp#L903)。
4. 对这次 partial dev run，用户担心的“同一个大 object 里 1 个 apply、19 个 non-apply ratio≈1.0 把 geomean 拉平”现象没有出现。原始数据里有 numeric ratio 的 object 一共 `89` 个，其中 `35` 个 object 全是 applied numeric program，`54` 个 object 全是 non-applied numeric program，mixed object 数量是 `0`。
5. non-applied numeric 程序也确实进入了 overall exec geomean，但它们不是“接近 1.0 的中性项”。`85` 个 non-applied numeric program 的 geomean 是 `0.9510x`，明显比 applied-only 的 `0.9953x` 更差；所以它们不是把结果往 `1.0` 稀释，而是把结果往更差方向拉低。
6. 这次 run 确实没有跑完。raw guest result 已经持久化了 `288` 个 object / `1149` 个 program，随后 `python3 corpus/driver.py` 因 `exit 139` 崩溃；剩余 `181` 个 object / `860` 个 program 完全缺失。因为 guest 端 `chunk_size=1` 且 “先写 JSON 再发 progress”，所以前 288 个 object 的数据是完整持久化的，不是半条记录。

## 1. 统计单位审计

### 1.1 geomean 是按 program，不是按 object

- overall summary 先在 `program_records` 上构造 `compile_pairs` 和 `measured_pairs`，然后直接对 program 级的 `size_ratio` / `speedup_ratio` 做 `geometric_mean`，见 [`runner/libs/results.py:238-280`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L238)。
- `geometric_mean()` 本身只是对正值列表求 log-mean-exp，不做任何 object 聚合或加权修正，见 [`runner/libs/statistics.py:18-22`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/statistics.py#L18)。
- `by_object` 只是 summary 的附带分组输出，不参与 overall geomean 的最终计算，见 [`runner/libs/results.py:305-336`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L305)。

结论：

- `exec geomean = 0.9803x` 是 `255` 个 program ratio 的几何平均。
- 一个 object 有 41 个 numeric program，就比只有 1 个 numeric program 的 object 在 overall geomean 里重 41 倍。

### 1.2 `measured_pairs` 和 `applied` 的代码定义

- `measured_pairs` 定义：
  - `record.get("baseline_run") and baseline_run.ok and record.get("rejit_run") and rejit_run.ok`
  - 代码见 [`runner/libs/results.py:246-253`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L246)
- `speedup_ratio` 定义：
  - 只有当 baseline/rejit run 都 `ok` 且两边 `exec_ns` 都非零时才返回 `baseline_exec_ns / rejit_exec_ns`
  - 代码见 [`runner/libs/corpus.py:1122-1134`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1122)
- `applied_programs` 定义：
  - `record.get("applied_passes")` 为真
  - 代码见 [`runner/libs/results.py:254`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L254)
- `applied_passes` 定义：
  - 来自 `compile_passes_applied` 与 `run_passes_applied` 的 merge
  - `compile_passes_applied` / `run_passes_applied` 又只读取 `sample.rejit.passes_applied`
  - 代码见 [`runner/libs/corpus.py:1143-1145`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1143) 和 [`runner/libs/corpus.py:1540-1542`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1540)

这意味着 summary 里的 `applied` 实际语义是：

- “至少一个 pass 报告自己改写了程序”
- 不是 “daemon REJIT 路径执行成功”
- 更不是 “C++ `sample.rejit.applied == true`”

这次 partial run 的原始数字：

| 口径 | 程序数 |
| --- | ---: |
| `applied_passes` 非空（summary `applied_programs`） | 364 |
| 任一 compile/run sample 里 `rejit.applied == true` | 645 |
| `rejit.applied == true` 但 `passes_applied == []` | 281 |

在 numeric exec subset 里更明显：

| 口径 | 程序数 |
| --- | ---: |
| numeric `speedup_ratio` 总数 | 255 |
| 其中 `applied_passes` 非空 | 170 |
| 其中 `rejit.applied == true` | 254 |
| 其中 `rejit.applied == true` 但 `passes_applied == []` | 84 |

所以 “364 applied” 如果被理解成 “只有 364 个程序真的经过 REJIT 生效” 是不准确的。更准确的说法是：

- `364` 个程序至少有一个 pass 发生了实际变换。
- `645` 个程序在 raw sample 中标成了 `rejit.applied=true`。

### 1.3 一个 object 有多个 program 时怎么处理

- object 级 prepare/load 只做一次：baseline 一次、rejit 一次，见 [`runner/libs/corpus.py:1290-1310`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1290) 和 [`runner/libs/corpus.py:1372-1393`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1372)。
- 然后每个 program 再各自生成 baseline compile、baseline run、rejit compile、rejit run job，见 [`runner/libs/corpus.py:1312-1451`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1312)。
- 所以 object prepare 失败时，会把该 object 下面的所有 program 一次性打掉；但 overall geomean 一旦进入 ratio 计算，仍然是 program 一票，不是 object 一票。

## 2. 漏斗分析

### 2.1 Build / selection

`load_targets_from_yaml()` 按 build report 的 `available_objects` 过滤 object，可见 benchmark 的 build gate 实际是 “对象文件是否可用”，不是 “fresh compile 必须成功”，见 [`runner/libs/corpus.py:454-479`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L454) 和 [`runner/libs/corpus.py:523-573`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L523)。

这次 dev run 的 selection / build 真实数字：

| 阶段 | Objects | Programs | 说明 |
| --- | ---: | ---: | --- |
| Manifest 选中 | 469 | 2009 | [`vm_corpus_20260328_194356/metadata.json:3748-3753`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L3748) |
| Build gate 后仍可用 | 469 | 2009 | 没有被 build gate 丢掉的 selected object |
| 其中 fresh `ok/complete` | 354 | 1282 | 来自 `expanded_corpus_build.latest.json` 与 target JSON 交叉统计 |
| 其中 `existing/prebuilt` | 115 | 727 | 来自同上 |
| 其中 `supplemented_existing` | 81 | n/a | 全局 build report 层面的补充存在对象数，见 [`vm_corpus_20260328_194356/metadata.json:3751`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L3751) |

补充发现：

- build report 全局摘要是 `built_ok=740`, `staged_existing=115`, `available_total=855`，见 [`expanded_corpus_build.latest.json:214-216`](/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.latest.json#L214)。
- metadata 里 `available_objects=936` 是把 `supplemented_existing=81` 加进来的结果，见 [`vm_corpus_20260328_194356/metadata.json:3743`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L3743)。
- 选中对象里有 `11` 个 object / `30` 个 program 在 build report 里同时出现了 `existing/prebuilt` 和 `error/clang` 记录。这说明 build gate 是 availability-based，不是 strict fresh-build-based。

### 2.2 运行漏斗

这次 run 的 raw guest result 有 `288` 条 object record；和 metadata summary 完全一致。用仓库内 `summarize_corpus_batch_results()` 重新计算，得到同样的 `648 compile_pairs / 483 measured_pairs / 364 applied_programs / 0.980326755 exec geomean`，代码入口是 [`runner/libs/results.py:232`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L232)。

#### Object 漏斗

| 阶段 | Objects | 损失 | 主要原因 |
| --- | ---: | ---: | --- |
| Selected / build-available | 469 | 0 | build gate 未丢 selected object |
| Completed before crash | 288 | 181 | VM `exit 139` 后未进入剩余对象 |
| Object prepare success | 188 | 100 | `bpf_object__load failed: Invalid argument` 56；`No such process` 18；`Permission denied` 15；`prepared kernel state did not load any programs` 6；`bpf_object__open_file failed: Operation not supported` 3；其他 2 |

#### Program 漏斗

| 阶段 | Programs | 损失 | 说明 |
| --- | ---: | ---: | --- |
| Selected / build-available | 2009 | 0 | target JSON 全部可用 |
| Completed before crash | 1149 | 860 | 未跑到剩余对象 |
| Runtime-eligible completed (`!= compile_only`) | 1093 | 56 | `compile_only` 不进入 measured |
| Compile pairs success | 648 | 501 | `499` 个被 object prepare 失败卡死，另有 `2` 个 `prepared kernel state is missing program` |
| Runtime-eligible compile success | 620 | 473 | 648 里包含 `28` 个 compile-only 成功程序 |
| Measured pairs (`run.ok && run.ok`) | 483 | 137 | attach / io-mode 失败 |
| Numeric `speedup_ratio` | 255 | 228 | `exec_ns` 为 `0` 或缺失，未进入 geomean |
| Summary `applied_programs` | 364 | 785 | 语义是 “至少一条 pass 真的改写” |
| Numeric + summary-applied | 170 | 85 vs all-numeric | applied-only exec geomean 的真实分母 |

#### Compile 丢失原因（unique program counts）

| 原因 | Programs |
| --- | ---: |
| prepare failed: `bpf_object__load failed: Invalid argument` | 325 |
| prepare failed: `bpf_object__load failed: No such process` | 92 |
| prepare failed: `bpf_object__load failed: Permission denied` | 51 |
| prepare failed: `prepared kernel state did not load any programs` | 29 |
| prepare failed: `Argument list too long` | 1 |
| prepare failed: `Unknown error 524` | 1 |
| `prepared kernel state is missing program: not_valid_dynptr` | 1 |
| `prepared kernel state is missing program: not_ptr_to_stack` | 1 |

#### Measured 丢失原因（compile 成功后仍未进入 `measured_pairs`）

| 原因 | Programs |
| --- | ---: |
| `bpf_program__attach failed: Operation not supported` | 58 |
| `bpf_program__attach failed: No such file or directory` | 35 |
| `bpf_program__attach failed: Invalid argument` | 26 |
| `bpf_program__attach failed: Bad file descriptor` | 10 |
| `io-mode packet requires an XDP or skb packet context` | 7 |
| `bpf_program__attach failed: Device or resource busy` | 1 |

#### `summary.failure_reasons` 不能直接当 funnel 数

`summary.failure_reasons` 是 failure event 计数，不是 unique program 计数。因为代码会对 `baseline_compile / rejit_compile / baseline_run / rejit_run` 四个字段逐一累计，见 [`runner/libs/results.py:261-277`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L261)。

例子：

- `prepared ... Invalid argument` 在 summary 里是 `627` 个 baseline event，但 unique program 只有 `325` 个。
- `bpf_program__attach failed: Operation not supported` 在 summary 里是 `116` 个 event，但 unique program 只有 `58` 个。

所以 funnel 应该用 unique object / unique program 重新统计，不能直接抄 `summary.failure_reasons`。

## 3. Geomean 方法审计

### 3.1 代码路径

- overall geomean 使用 [`runner/libs/results.py:279-327`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py#L279)。
- 真正的几何平均实现是 [`runner/libs/statistics.py:18-22`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/statistics.py#L18)。
- [`runner/libs/corpus.py:1045-1049`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py#L1045) 里还有一个同名 `geomean()` helper，但 `summarize_corpus_batch_results()` 并不走它。

### 3.2 这次 dev run 的真实分母

| 指标 | 分母 | geomean |
| --- | ---: | ---: |
| Overall exec geomean | 255 numeric program ratios | `0.980326755x` |
| Applied-only exec geomean（summary `applied_passes` 口径） | 170 | `0.995307457x` |
| Non-applied exec geomean（summary `applied_passes` 口径） | 85 | `0.951038396x` |
| Overall code-size geomean | 648 compile pairs | `1.006269825x` |
| Applied-only code-size geomean | 364 | `1.011188954x` |
| Non-applied code-size geomean | 284 | `1.000000000x` |

关键判断：

- overall exec geomean 确实包含了 summary 定义下的 `applied=false` 程序。
- 但这些程序不是“接近 1.0 的中性稀释项”。它们自己的 geomean 是 `0.9510x`，比 applied-only 的 `0.9953x` 更差。
- 如果把这 `85` 个 non-applied numeric 程序都假设成完美中性 `1.0x`，则 combined geomean 会是 `0.996869186x`；而真实 overall 是 `0.980326755x`。也就是说，当前数据里的 non-applied 项把结果额外拉低了约 `1.65` 个百分点。

### 3.3 `measured_pairs=483` 但 geomean 只用了 `255`

原因不是代码 bug，而是定义本身如此：

- `measured_pairs` 只要求 run job `ok=true`
- `speedup_ratio` 还要求 baseline/rejit 两边 `exec_ns` 都非零

这次的 `228` 个 “measured but not numeric” 里：

| 子集 | 数量 |
| --- | ---: |
| `attach_trigger` | 210 |
| `bpf_prog_test_run` | 18 |
| `(baseline_exec_ns, rejit_exec_ns) = (0, 0)` | 226 |
| `(0, 2073)` | 1 |
| `(17941, 0)` | 1 |

所以当前报告里 “Measured pairs: 483” 和 “Exec geomean: 0.980x” 用的是两个不同分母，这正是用户感觉“单位不清晰”的根因。

### 3.4 `applied=false` 的真实含义

如果按 summary 当前实现，`applied=false` 包含两类程序：

| 子类 | 数量 | exec geomean |
| --- | ---: | ---: |
| `rejit.applied=true` 但 `passes_applied=[]` | 84 | `0.953552146x` |
| `rejit.applied=false` 的真失败项 | 1 | `0.761904762x` |

这说明 summary 里的 `applied=false` 大部分不是 “daemon 没有做 REJIT”，而是 “daemon 跑了 REJIT，但没有任何 pass 报告改写”。这一点如果不单独写清楚，很容易误读。

## 4. Per-object vs Per-program 稀释

### 4.1 用户提出的“同 object 混合稀释”在这次数据里不存在

我对 `255` 个 numeric ratio 做了 object 分组：

- 有 numeric ratio 的 object 总数：`89`
- 全部 numeric program 都属于 summary-applied 的 object：`35`
- 全部 numeric program 都属于 summary-non-applied 的 object：`54`
- 同一个 object 内同时出现 applied numeric 和 non-applied numeric 的 object：`0`

所以这次 partial run 里不存在 “一个 object 20 个 numeric program，其中 1 个 applied、19 个 non-applied，一起拉平同一个 object 的 geomean” 的现象。

### 4.2 真正存在的是 cross-object program weighting

overall geomean 是 program-weighted，不是 object-equal-weighted。因此大 object 会显著主导 overall：

| Object | Numeric programs | Applied numeric | Object geomean |
| --- | ---: | ---: | ---: |
| `bcc:libbpf-tools/klockstat.bpf.o` | 41 | 41 | `0.9810x` |
| `coroot-node-agent:ebpf.bpf.o` | 11 | 11 | `1.0045x` |
| `calico:from_hep_debug.bpf.o` | 9 | 9 | `0.8553x` |
| `calico:to_hep_debug.bpf.o` | 9 | 9 | `1.0253x` |
| `calico:to_nat_debug.bpf.o` | 9 | 9 | `1.0756x` |

前 5 个 object 就占了 `79 / 255 = 31.0%` 的 numeric exec 权重。

如果改成 “每个 object 先求 object geomean，再给每个 object 一票”，结果会变成：

| 口径 | Object 数 | geomean |
| --- | ---: | ---: |
| Program-weighted overall | 255 program ratios | `0.9803x` |
| Object-equal-weighted overall | 89 objects | `0.9260x` |
| Program-weighted applied-only | 170 program ratios | `0.9953x` |
| Object-equal-weighted applied-only | 35 objects | `1.0150x` |

这说明：

- 这次数据里真正强烈存在的是 “program 权重压过 object 权重”。
- 如果论文或报告只给 program-weighted geomean，读者会低估 many-small-objects 的波动。

## 5. 数据完整性与 crash

### 5.1 这次 run 是否完整

不完整。证据：

- metadata 明确记录了 `returncode=139`、`completed_objects=288`、`completed_programs=1149`、`total_objects=469`、`total_programs=2009`，见 [`vm_corpus_20260328_194356/metadata.json:1009`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L1009) 和 [`vm_corpus_20260328_194356/metadata.json:1031-1040`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json#L1031)。
- stdout log 的最后几行是 `index 288` 后紧跟 `Segmentation fault` 和 `COMMAND_EXIT_CODE="139"`，见 [`corpus-rejit-vm-batch-result-l3_nwgyk.json.stdout_log.txt:594-597`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json.stdout_log.txt#L594)。

### 5.2 `test_map_init.bpf.o` 到底有没有写进去

有。这里需要纠正旧文档 [`corpus_dev_full_results_20260328.md:12-14`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/corpus_dev_full_results_20260328.md#L12) 的说法：

- 旧文档把 `progress.current_target = test_map_init.bpf.o` 解读成 “崩在 test_map_init 上”。
- 但 guest 端代码设定 `GUEST_BATCH_TARGETS_PER_CHUNK = 1`，并且是 `write_guest_batch_records()` 之后才 `emit_guest_event("program_progress")`，见 [`corpus/modes.py:87`](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py#L87) 和 [`corpus/modes.py:319-323`](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py#L319)。
- raw guest result JSON 里第 288 条 record 确实就是 `test_map_init.bpf.o` 的完整 object/program 记录。

所以更准确的表述是：

- `test_map_init.bpf.o` 是最后一个成功持久化的 object。
- crash 发生在写完第 288 条 record 之后。
- 第一条缺失的 object 是 target JSON 顺序上的下一个对象，而不是 `test_map_init` 本身。

### 5.3 crash 影响了多少结果

- 完整缺失：`181` 个 object，`860` 个 program。
- 没有证据表明前 `288` 个 object 的 persisted 数据损坏。guest result JSON 可正常解析，且用仓库代码重算 summary 与 metadata 完全一致。
- 但 persisted prefix 里仍有一个语义异常样本：`for_each_array_map_elem.bpf.o:test_pkt_access` 的 `sample.rejit.error` 非空，却因为 run job `ok=true` 且 `speedup_ratio` 有值，仍被 overall geomean 纳入。去掉这一条后 overall exec geomean 从 `0.98033x` 变成 `0.98130x`。影响不大，但说明 “进入 geomean”的判定略宽于“没有 REJIT 错误字符串”。

## 6. 建议修复

1. 把 `applied` 拆成两个显式字段并分别报表。
   - `rejit_applied_bool`: 直接抄 C++ `sample.rejit.applied`
   - `pass_changed`: `passes_applied` 非空
   - 当前 `applied_programs` 应改名为 `pass_changed_programs`，否则极易误解。

2. 在 summary 里显式输出 geomean 分母。
   - 至少增加 `numeric_exec_pairs`
   - 最好同时增加 `numeric_exec_pairs_pass_changed`
   - 否则 `measured_pairs=483` 和 `exec geomean` 的实际分母 `255` 会长期混淆。

3. 同时输出 program-weighted 和 object-equal-weighted geomean。
   - 当前 only-program-weighted 会让大 object 过度主导 overall
   - 推荐至少增加 `exec_ratio_geomean_by_program` 和 `exec_ratio_geomean_by_object`

4. Build funnel 里把 “available” 和 “fresh build ok” 分开。
   - 当前 selected build success 实际表示 “对象文件可用”
   - 对于既有 `existing/prebuilt` 又有 `error/clang` 的对象，应单列为 `prebuilt_fallback`

5. `failure_reasons` 不要只报 raw event count。
   - 现有实现把 compile/run、baseline/rejit 全部累加
   - 建议增加 `failure_program_counts` 和 `failure_object_counts`
   - 另外不要只保留 top 16，至少应在明细 JSON 里提供完整 breakdown

6. crash 恢复信息应更精确。
   - metadata 里增加 `last_persisted_object`
   - 单独记录 `next_object_to_run`
   - 避免把 `current_target` 误读成“崩溃发生在该对象内部”

7. 对 `exec_ns == 0` 的 measured pair 单独分桶。
   - 当前它们算进 `measured_pairs`，但不进入 geomean
   - 推荐增加 `measured_pairs_zero_exec_ns`
   - attach_trigger workload 尤其需要单独说明统计口径

