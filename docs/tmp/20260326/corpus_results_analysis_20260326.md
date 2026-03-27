# Corpus 结果分析（2026-03-26）

## 输入与口径

- 最新 run：`corpus/results/vm_corpus_20260326_201508/metadata.json` + `corpus/results/vm_corpus_20260326_201508/details/result.json` + `corpus/results/vm_corpus_20260326_201508/details/result.md`。
- `corpus/results/vm_corpus.json`：不存在。
- `corpus/results/vm_corpus.md`：不存在。
- 上一轮对比基线：`corpus/results/vm_corpus_20260326_050032/metadata.json`（292 measured / 113 applied）。该 run 只保留了 `paper_summary` 聚合数据，没有逐程序明细。
- 本文统一使用你要求的 `rejit/stock` 口径；而结果文件里的 `Exec Ratio` 实际是 `stock/rejit`（从逐程序 `baseline ns` / `rejit ns` 可验证），因此本文全部做了倒数转换。
- 术语：`compile pair` = baseline/rejit 编译都成功；`measured pair` = baseline/rejit 运行都成功；`timed pair` = `speedup_ratio` 非空，能计算执行时间比。

## 执行摘要

- 最新 run 共 **764** 个目标；`compile pair` **442**，`measured pair` **315**，其中只有 **227** 个有有效执行时间比；`applied` **130**。
- 按 `rejit/stock` 口径，最新总体几何均值为 **1.239x**，即 **回归 23.9%**。上一轮（292/113）为 **1.043x**，即 **回归 4.3%**。
- 本次 `applied` 数量从 **113 -> 130** 增加了 **17**，`measured pair` 从 **292 -> 315** 增加了 **23**，但总体性能方向明显恶化。
- 本次结果中 **没有任何程序出现 `map_inline` 或 `rotate` 命中**；因此这组 artifact **不能直接证明 speculative map inline 的收益**。
- 一个很强的噪声信号是：**138** 个“完全没有任何 pass 命中、且代码大小保持 `1.0x` 不变”的 timed 程序，其 `rejit/stock` 几何均值仍然达到 **1.249x**。这说明当前 corpus run 里，优化效果与测量/执行路径噪声被混在了一起。

## 总体统计

| 指标 | 最新 run | 上一轮 292/113 | 说明 |
| --- | --- | --- | --- |
| targets | 764 | 764 | YAML 选中的目标数 |
| compile pairs | 442 | 471 | baseline/rejit 都能编译加载 |
| measured pairs | 315 | 292 | baseline/rejit 都能运行 |
| timed pairs | 227 | n/a | 上一轮无逐程序明细，无法重算 |
| applied programs | 130 | 113 | `applied_passes` 非空 |
| `rejit/stock` geomean | 1.239x | 1.043x | <1 代表加速，>1 代表回归 |
| `applied` 子集 `rejit/stock` | 1.224x | n/a | 仅最新 run 可算 |
| `non-applied` 子集 `rejit/stock` | 1.249x | n/a | 代码完全不变的对照组 |

## 1. 分项目拆解

### 1.1 项目级统计

| 项目 | 程序数 | Compile | Measured | Timed | Applied | Applied/Measured | `rejit/stock`(Timed) | `rejit/stock`(Applied Timed) | 结论 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 417 | 251 | 156 | 104 | 37 | 23.7% | 1.437x | 1.271x | 回归 43.7% |
| calico | 59 | 59 | 59 | 59 | 54 | 91.5% | 1.257x | 1.314x | 回归 25.7% |
| bcc | 90 | 46 | 33 | 13 | 10 | 30.3% | 0.831x | 0.531x | 加速 16.9% |
| xdp-tutorial | 38 | 23 | 22 | 20 | 3 | 13.6% | 0.904x | 0.785x | 加速 9.6% |
| tetragon | 23 | 12 | 10 | 4 | 9 | 90.0% | 0.930x | 0.951x | 加速 7.0% |
| real_world_code_size | 15 | 13 | 9 | 7 | 5 | 55.6% | 0.840x | 0.898x | 加速 16.0% |
| libbpf-bootstrap | 12 | 10 | 7 | 5 | 5 | 71.4% | 0.980x | 1.743x | 加速 2.0% |
| xdp-tools | 51 | 5 | 5 | 4 | 2 | 40.0% | 1.344x | 1.293x | 回归 34.4% |
| katran | 5 | 5 | 5 | 5 | 0 | 0.0% | 1.205x | n/a | 回归 20.5% |
| tracee | 5 | 5 | 4 | 3 | 4 | 100.0% | 1.453x | 1.453x | 回归 45.3% |
| suricata | 2 | 2 | 2 | 2 | 0 | 0.0% | 1.113x | n/a | 回归 11.3% |
| coroot-node-agent | 2 | 2 | 1 | 1 | 0 | 0.0% | 1.029x | n/a | 回归 2.9% |
| datadog-agent | 1 | 1 | 1 | 0 | 0 | 0.0% | n/a | n/a | n/a |
| systemd | 9 | 4 | 1 | 0 | 0 | 0.0% | n/a | n/a | n/a |
| scx | 9 | 4 | 0 | 0 | 1 | n/a | n/a | n/a | n/a |
| KubeArmor | 5 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| bpftrace | 5 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| cilium | 3 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| loxilb | 6 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| manual-test | 2 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| netbird | 1 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| opentelemetry-ebpf-profiler | 3 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |
| tubular | 1 | 0 | 0 | 0 | 0 | n/a | n/a | n/a | n/a |

说明：`Measured` 与 `Timed` 的差值来自许多程序虽然运行成功，但 `exec_ns` 为 0 或缺失，无法形成稳定的执行时间比。

### 1.2 各项目命中的 pass

| 项目 | Applied 程序数 | 命中 pass（按程序数） |
| --- | --- | --- |
| calico | 54 | const_prop(51)、endian_fusion(42)、dangerous_helper_firewall(39)、wide_mem(28)、live_patch(21)、cond_select(9)、extract(6) |
| linux-selftests | 37 | live_patch(18)、endian_fusion(11)、const_prop(4)、dce(3)、dangerous_helper_firewall(2)、wide_mem(2)、skb_load_bytes_spec(1)、extract(1) |
| bcc | 10 | live_patch(9)、const_prop(5)、dce(5)、cond_select(1) |
| tetragon | 9 | live_patch(6)、const_prop(5)、dce(5)、dangerous_helper_firewall(3) |
| libbpf-bootstrap | 5 | live_patch(4)、const_prop(1)、dce(1)、endian_fusion(1) |
| real_world_code_size | 5 | live_patch(4)、const_prop(1)、dce(1)、endian_fusion(1) |
| tracee | 4 | const_prop(3)、dce(3)、wide_mem(2)、endian_fusion(2)、live_patch(1) |
| xdp-tutorial | 3 | wide_mem(2)、endian_fusion(1) |
| xdp-tools | 2 | endian_fusion(2) |
| scx | 1 | const_prop(1)、dce(1) |

### 1.3 项目层面的观察

- **calico**：覆盖度最高，59/59 measured、54 个程序命中优化，但 `rejit/stock` 为 **1.257x**，属于明显回归；主链是 `const_prop + endian_fusion + dangerous_helper_firewall + wide_mem (+ live_patch)`。
- **linux-selftests**：156 measured、37 applied，但 `rejit/stock` 达到 **1.437x**，是本次总体回归的最大来源之一。
- **bcc**：33 measured、10 applied，`rejit/stock` 为 **0.831x**，表面上是加速，但受单个极端样本 `vfs_read_entry`（0.078x）影响很大。
- **tracee**：4 measured、4 applied，`rejit/stock` **1.453x**，回归最明显的已优化项目之一。
- **tetragon**：10 measured、9 applied，`rejit/stock` **0.930x**，是少数仍有净加速的优化项目。
- **katran**：5 measured、0 applied，但 `rejit/stock` 仍然是 **1.205x**；这进一步说明“REJIT 路径噪声/漂移”不是只发生在命中 pass 的程序上。

## 2. Pass 效果

### 2.1 每个 pass 命中了多少程序

| Pass | Unique Programs | Compile Hits | Run Hits | Timed Programs | Faster | Slower | `rejit/stock` gmean | 说明 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| const_prop | 71 | 71 | 67 | 55 | 8 | 47 | 1.357x | 无净加速 |
| live_patch | 63 | 63 | 53 | 35 | 11 | 21 | 1.123x | 无净加速 |
| endian_fusion | 60 | 60 | 59 | 58 | 14 | 41 | 1.312x | 无净加速 |
| dangerous_helper_firewall | 44 | 44 | 42 | 41 | 8 | 33 | 1.343x | 无净加速 |
| wide_mem | 34 | 34 | 33 | 33 | 7 | 26 | 1.275x | 无净加速 |
| dce | 19 | 19 | 15 | 4 | 0 | 4 | 1.499x | 无净加速 |
| cond_select | 10 | 10 | 9 | 9 | 2 | 7 | 1.587x | 无净加速 |
| extract | 7 | 7 | 6 | 6 | 0 | 6 | 1.351x | 无净加速 |
| skb_load_bytes_spec | 1 | 1 | 1 | 1 | 0 | 1 | 3.000x | 无净加速 |

### 2.2 结论

- **按覆盖度**：`const_prop` 命中最多，共 **71** 个程序；其后是 `live_patch` (**63**) 和 `endian_fusion` (**60**)。
- **按“最接近正收益”的关联表现**：在样本数大于 1 的 pass 里，`live_patch` 最不差，`rejit/stock` 为 **1.123x**；但它仍然是回归，不是加速。
- **按对总体性能方向的关联强度（以 pass-bearing timed 程序的对数回归总量近似）**：`const_prop` 对整体负向漂移的关联最大。这个指标不是因果归因，只能说明“带这个 pass 的程序集合”拖慢得最多。
- **按用户问题“哪个 pass 对 speedup 贡献最大”**：本次答案是 **没有任何 pass 集合表现出净 speedup**。如果硬要选“最不差”的，是 `live_patch`；如果看“覆盖最多、把总体推向回归最多”的，是 `const_prop`。
- **缺失的 pass**：`map_inline = 0`，`rotate = 0`。本次 corpus 结果实际覆盖的 pass 只有 `const_prop, live_patch, endian_fusion, dangerous_helper_firewall, wide_mem, dce, cond_select, extract, skb_load_bytes_spec`。

### 2.3 代表性已优化样本

| 类别 | 项目 | 程序 | Passes | `rejit/stock` | 备注 |
| --- | --- | --- | --- | --- | --- |
| 最好 | bcc | vfs_read_entry | live_patch | 0.078x | 加速 92.2% |
| 最好 | bcc | tracepoint__syscalls__sys_enter_execve | live_patch | 0.541x | 加速 45.9% |
| 最好 | calico | calico_xdp_main | wide_mem, endian_fusion, live_patch | 0.692x | 加速 30.8% |
| 最好 | xdp-tutorial | xdp_redirect_map_func | wide_mem | 0.696x | 加速 30.4% |
| 最好 | linux-selftests | handle_sys_prctl | live_patch | 0.755x | 加速 24.5% |
| 最差 | calico | calico_tc_skb_icmp_inner_nat | const_prop, wide_mem, cond_select, endian_fusion, dangerous_helper_firewall | 2.327x | 回归 132.7% |
| 最差 | calico | calico_tc_host_ct_conflict | const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch | 2.357x | 回归 135.7% |
| 最差 | calico | calico_tc_skb_send_tcp_rst | const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall | 2.411x | 回归 141.1% |
| 最差 | linux-selftests | __encap_udp_eth | endian_fusion | 2.500x | 回归 150.0% |
| 最差 | linux-selftests | decap_sanity | skb_load_bytes_spec | 3.000x | 回归 200.0% |

## 3. Map Inline 专项

| 指标 | 数值 |
| --- | --- |
| 命中 `map_inline` 的程序数 | 0 |
| 其中有有效执行时间比的程序数 | 0 |
| 同时命中 `const_prop` | 0 |
| 同时命中 `dce` | 0 |
| 同时命中 `const_prop + dce` | 0 |
| `map_inline` 子集 `rejit/stock` | n/a |
| 非 `map_inline` timed 子集 `rejit/stock` | 1.239x |

- 结论很直接：**本次 latest corpus run 根本没有记录到任何 `map_inline` 命中**。
- 因此，关于 speculative inline 的三个核心问题“命中数、和 `const_prop/dce` 的联动、相对非 map-inline 程序的性能收益”，在这批 artifact 上都只能得到 **0 / 不可评估**。
- 这也意味着：虽然你要求和“pre-speculative-inline run”对比，但 **这次结果本身并没有体现出 speculative map inline 的实际发生**，因此不是一次有效的 spec-inline ablation。

## 4. 失败与问题

- **322 / 764** 个程序没有形成 compile pair。
- 在 compile 成功的 **442** 个程序里，仍有 **127** 个没能形成 measured pair。
- 最终只有 **227 / 764 = 29.7%** 的目标能给出有效执行时间比。

### 4.1 首个失败原因（按程序去重）

| 首个失败阶段 | 原因 | 程序数 | 例子 |
| --- | --- | --- | --- |
| baseline_compile | bpf_object__load failed: Invalid argument | 217 | KubeArmor:enforce_net_create |
| baseline_run | bpf_program__attach failed: Operation not supported | 75 | bcc:do_sample |
| baseline_compile | bpf_object__load failed: No such file or directory | 33 | bcc:tracepoint__syscalls__sys_enter_openat |
| baseline_compile | bpf_object__load failed: Permission denied | 32 | linux-selftests:async_call_root_check |
| baseline_compile | bpf_object__load failed: No such process | 22 | bcc:fentry_account_page_dirtied |
| baseline_run | bpf_program__attach failed: No such file or directory | 17 | bcc:__blk_account_io_start |
| baseline_run | io-mode packet requires an XDP or skb packet context | 15 | linux-selftests:_dissect |
| baseline_run | bpf_program__attach failed: Bad file descriptor | 9 | linux-selftests:dump_bpf_array_map |
| baseline_compile | bpf_object__load failed: Bad file descriptor | 9 | linux-selftests:xdp_entry |
| baseline_run | bpf_program__attach failed: Invalid argument | 7 | bcc:printret |
| baseline_compile | bpf_object__open_file failed: Operation not supported | 5 | cilium:cil_from_container |
| baseline_run | bpf_program__attach failed: Device or resource busy | 3 | bcc:blk_account_io_start |
| baseline_compile | bpf_object__open_file failed: No such file or directory | 2 | opentelemetry-ebpf-profiler:kprobe__generic |
| rejit_run | bpf_object__load failed: No such file or directory | 1 | bcc:tracepoint__syscalls__sys_enter_open |
| baseline_compile | bpf_object__load failed: Argument list too long | 1 | linux-selftests:while_true |

### 4.2 编译成功但运行失败的主要原因

| 原因 | 程序数 | 例子 |
| --- | --- | --- |
| bpf_program__attach failed: Operation not supported | 75 | bcc:do_sample |
| bpf_program__attach failed: No such file or directory | 17 | bcc:__blk_account_io_start |
| io-mode packet requires an XDP or skb packet context | 15 | linux-selftests:_dissect |
| bpf_program__attach failed: Bad file descriptor | 9 | linux-selftests:dump_bpf_array_map |
| bpf_program__attach failed: Invalid argument | 7 | bcc:printret |
| bpf_program__attach failed: Device or resource busy | 3 | bcc:blk_account_io_start |
| bpf_object__load failed: No such file or directory | 1 | bcc:tracepoint__syscalls__sys_enter_open |

### 4.3 正确性与稳定性

- `record_error` 为空的程序数：**764 / 764**。
- **`retval` mismatch = 0**：没有发现 baseline/rejit 返回值不一致。
- **`result` mismatch = 44**：有 44 个程序的 `sample.result` 不一致，其中大多数发生在 **未命中任何 pass** 的程序上（例如 `linux-selftests`）。这更像 workload/观测噪声，而不是确定性的功能错误。
- **compile 非对称失败 = 0**：没有出现“baseline compile 成功但 rejit compile 失败”的案例。
- **run 非对称失败 = 1**：只有 1 个案例，`bcc:tracepoint__syscalls__sys_enter_open`，baseline 能跑、rejit run 报 `No such file or directory`。
- 从“返回值一致 + 非优化程序同样大幅漂移”这两个信号看，本次 corpus 更像是**性能测量稳定性问题大于功能正确性问题**。

## 5. 与上一轮（292 measured / 113 applied）对比

### 5.1 总体对比

| 指标 | 上一轮 | 本次 | 变化 |
| --- | --- | --- | --- |
| compile pairs | 471 | 442 | -29 |
| measured pairs | 292 | 315 | +23 |
| applied programs | 113 | 130 | +17 |
| `rejit/stock` geomean | 1.043x | 1.239x | 回归 18.7% |

### 5.2 分项目对比（仅能做 source 级聚合）

| 项目 | 上一轮 Compile/Measured/Applied | 本次 Compile/Measured/Applied | 上一轮 `rejit/stock` | 本次 `rejit/stock` | 观察 |
| --- | --- | --- | --- | --- | --- |
| linux-selftests | 251/123/20 | 251/156/37 | 1.062x | 1.437x | applied 增加；measured 增加；性能变差 |
| calico | 59/54/54 | 59/59/54 | 1.106x | 1.257x | measured 增加；性能变差 |
| bcc | 75/61/18 | 46/33/10 | 1.021x | 0.831x | applied 减少；measured 减少；性能改善 |
| xdp-tutorial | 23/18/3 | 23/22/3 | 0.889x | 0.904x | measured 增加；性能变差 |
| tetragon | 12/10/6 | 12/10/9 | 1.143x | 0.930x | applied 增加；性能改善 |
| real_world_code_size | 13/8/2 | 13/9/5 | 0.884x | 0.840x | applied 增加；measured 增加；性能改善 |
| libbpf-bootstrap | 10/6/2 | 10/7/5 | 1.038x | 0.980x | applied 增加；measured 增加；性能改善 |
| xdp-tools | 5/2/2 | 5/5/2 | 1.307x | 1.344x | measured 增加；性能变差 |
| katran | 5/5/1 | 5/5/0 | 0.864x | 1.205x | applied 减少；性能变差 |
| tracee | 5/2/3 | 5/4/4 | 1.000x | 1.453x | applied 增加；measured 增加；性能变差 |
| suricata | 2/0/0 | 2/2/0 | n/a | 1.113x | measured 增加 |
| coroot-node-agent | 2/1/0 | 2/1/0 | 1.105x | 1.029x | 性能改善 |
| datadog-agent | 1/1/1 | 1/1/0 | n/a | n/a | applied 减少 |
| systemd | 4/1/0 | 4/1/0 | n/a | n/a | - |
| scx | 4/0/1 | 4/0/1 | n/a | n/a | - |

### 5.3 对比结论

- **覆盖面**：本次比上一轮多测到了 23 个程序、多命中了 17 个程序，但 compile pair 反而少了 29 个。
- **性能方向**：上一轮总体只是轻微回归（`rejit/stock 1.043x`），本次变成明显回归（`1.239x`）。
- **来源结构**：新增的 applied 主要来自 `linux-selftests`、`tracee`、`libbpf-bootstrap`、`tetragon`；但这几个 source 里除了 `tetragon` 外，大多没有带来正收益。
- **关键限制**：由于上一轮没有逐程序明细，也没有 `map_inline` 命中记录可对照，所以这里只能说“latest run 相比上一轮在 coverage 上更大、在性能上更差”，**不能把差异严格归因到 speculative inline**。

## 6. 结论

1. 从这批 latest corpus artifact 看，优化“命中率”提高了，但**没有转化成总体 speedup**；按 `rejit/stock` 口径，本次总体是 **23.9% 回归**。
2. 本次真正起作用的不是 `map_inline`，而是 `const_prop` / `endian_fusion` / `live_patch` / `wide_mem` / `dangerous_helper_firewall` 等 pass；其中 `const_prop` 覆盖最大。
3. **`map_inline = 0`** 是最关键结论：这次 latest corpus run 不能回答 speculative map inline 是否有效。
4. 由于“未优化程序也显著变慢”“44 个 `result` 不一致但 0 个 `retval` 不一致”，本次 run 里**测量稳定性问题非常突出**，对 pass 级性能结论必须保守。
5. 如果下一步要专门评估 speculative inline，至少需要一组**明确记录 `map_inline` 命中**、并保留逐程序明细的 run，再和上一轮做同口径 diff。

