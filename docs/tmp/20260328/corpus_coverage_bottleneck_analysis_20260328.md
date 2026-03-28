# BpfReJIT Corpus Coverage Bottleneck Analysis (2026-03-28)

## 0. 先说清楚口径

这次调查里混着三套不同日期、不同 schema 的数据：

1. `corpus/results/expanded_corpus_build.latest.json` + `expanded_corpus_build.md`
   - 生成时间：`2026-03-28T15:48:19Z`
   - 口径：当前 build availability
   - 结论：`1213` source 中，`429` built-from-source，`128` staged existing，报告里的 `available_objects=557`

2. `corpus/config/macro_corpus.yaml`
   - 当前已经是 `schema_version: 2`
   - 口径：`477` object、`2019` 显式 program、另有 `7` 个空 `programs: []` 的 object-only 占位项

3. `corpus/results/vm_corpus_20260326_201508/metadata.json`
   - 生成时间：`2026-03-26`
   - 这是最后一份完成的 full corpus run
   - 口径仍然是旧的 `selected_entries=764`
   - 这就是你给出的 `764 -> 442 -> 315 -> 130`

另外还有一份更晚但仍在运行中的新 run：

- `runner/corpus/results/vm_corpus_20260328_154829/`
- 我读取时 `details/result.json` 的 mtime 是 `2026-03-28 09:17:11 -0700`
- 当时快照是：`826` program records，`518` compile pairs，`385` measured pairs，`334` applied
- 这说明 `130 applied` 已经不是“当前 perf-only pipeline”的最新真值；它只对应 `2026-03-26` 的旧 full run

核心结论先给出来：

- `2019 -> 557 -> 764 -> 442 -> 315 -> 130` 这个漏斗本身混合了新旧两代数据，不能直接当作同一条 current pipeline。
- 真正的当前结构性问题不是 “YAML 只配了 764”，而是：
  - build report 低估了当前磁盘上已有对象；
  - current YAML 里有 `226` 个 `compile_only` program，天然不可能进入 measured；
  - current full run 正被 prepared-state orchestration bug 卡住；
  - attach / io_mode / program-type harness 仍然是 measured gap 的主要 runtime 漏斗。

## 1. 2019 -> 557：为什么只有 557 个可用对象

### 1.1 build report 的直接结论

`corpus/results/expanded_corpus_build.md` 给出的 build summary：

| 指标 | 数值 |
| --- | ---: |
| Sources considered | 1213 |
| Built from source | 429 |
| Staged existing objects | 128 |
| Available objects | 557 |
| Failures | 656 |

也就是说：

- `557 = 429` 个源码现编 + `128` 个预编译/已暂存对象
- 预编译对象占当前报告可用对象的 `23.0%` (`128 / 557`)

### 1.2 失败原因分布

按 `expanded_corpus_build.latest.json.records` 聚类后，`656` 个 build failure 的主因是：

| 类别 | 数量 | 占失败比例 | 说明 |
| --- | ---: | ---: | --- |
| `asm/types.h` 缺失 | 498 | 75.9% | 最大头部问题，集中打穿 selftests / xdp / cilium / systemd |
| `bpf_path_d_path` helper 原型冲突 | 59 | 9.0% | 全在 `linux-selftests` |
| repo-local `api.h` / `compiler.h` 缺失 | 27 | 4.1% | 基本全是 `tetragon` |
| `bpf_dynptr_slice` helper 原型冲突 | 26 | 4.0% | 全在 `linux-selftests` |
| helper / feature macro 缺失 | 12 | 1.8% | 新 helper / feature drift |
| kernel struct / API drift | 11 | 1.7% | 结构体字段或类型不匹配 |
| helper signature drift | 7 | 1.1% | helper 参数签名变了 |
| `asm/socket.h` 缺失 | 5 | 0.8% | 少量 socket 头缺失 |

补充：

- 有 `137` 个失败同时带着 `PLEASE submit a bug report` 的 LLVM/clang crash 痕迹；
- 其中 `134` 个和 `asm/types.h` 缺失重叠，本质上仍然是头文件/工具链输入问题，而不是独立的新 crash bucket。

### 1.3 哪些 repo 丢得最多

按 repo 的 build error 数：

| Repo | Total | Available | Error | Availability | 备注 |
| --- | ---: | ---: | ---: | ---: | --- |
| linux-selftests | 923 | 368 | 555 | 39.9% | 绝对主漏斗 |
| tetragon | 51 | 23 | 28 | 45.1% | 可用对象全是 prebuilt |
| xdp-tutorial | 41 | 23 | 18 | 56.1% | 可用对象全是 prebuilt |
| xdp-tools | 27 | 13 | 14 | 48.1% | 可用对象全是 prebuilt |
| xdp-examples | 13 | 0 | 13 | 0.0% | 全挂 |
| cilium | 12 | 3 | 9 | 25.0% | 可用对象全是 prebuilt |
| systemd | 14 | 8 | 6 | 57.1% | 可用对象全是 prebuilt |
| bpftrace | 5 | 0 | 5 | 0.0% | 这里是 missing object，不是现编失败 |

两个特别重要的结构事实：

1. 真正能稳定从 source build 出对象的 repo，基本只有 `linux-selftests` 和 `bcc`
2. 很多“可用 repo”其实完全靠 prebuilt 对象撑着：
   - `tetragon`
   - `xdp-tools`
   - `xdp-tutorial`
   - `cilium`
   - `systemd`
   - `katran`
   - `calico`

### 1.4 build report 其实还低估了可用对象

当前磁盘上 `corpus/build/**/*.bpf.o` 实际有 `639` 个对象，而 build report 只报 `557`。

差值：

- `639 - 557 = 82` 个对象

这 `82` 个对象不是 YAML 专属对象，它们是 “磁盘上已存在但没有进入当前 build report 的 prebuilt/on-disk object”。

所以对 `2019 -> 557` 的准确表述应该是：

- `2019` 个 program 对应的 object universe 当前至少有 `639` 个 `.bpf.o` 在磁盘上
- 但 `expanded_corpus_build.latest.json` 只把其中 `557` 个纳入了 strict report

这不是 runtime coverage 问题，而是 availability accounting 问题。

## 2. 557 -> 764：为什么看起来 YAML 只配了 764 个 target

### 2.1 结论：`764` 是旧 run 的历史口径，不是当前 YAML 的真实覆盖数

`vm_corpus_20260326_201508/metadata.json` 里的 `yaml_summary.total_entries = 764` 来自旧 schema。

当前 `macro_corpus.yaml` 已经不是这个口径：

| 指标 | 当前值 |
| --- | ---: |
| schema_version | 2 |
| manifest objects | 477 |
| explicit programs | 2019 |
| object-only placeholders (`programs: []`) | 7 |

所以：

- `764` 不是“当前 YAML 只配了 764”
- 它只是 `2026-03-26` 那次 full run 当时选中的旧式 entry 数

### 2.2 当前 YAML 对已有对象的覆盖率其实非常高

我把当前 YAML 中存在于磁盘的对象全部离线跑了一遍 `runner/build/micro_exec list-programs`：

| 指标 | 数值 |
| --- | ---: |
| YAML objects | 477 |
| 其中磁盘存在 | 469 |
| 其中磁盘缺失 | 8 |
| 现存对象里的 YAML programs | 2009 |
| 现存对象里实际枚举到的 programs | 2009 |
| `name` 命中 | 2009 / 2009 |
| `name + section` 精确命中 | 2004 / 2009 |

也就是说，当前 YAML 对“已经存在的对象”几乎是全覆盖的：

- program name 覆盖率：`100%`
- `name+section` 精确覆盖率：`99.8%`

这不是 YAML coverage bottleneck。

### 2.3 当前 YAML 里缺失的对象只有 8 个，对应 10 个 program

当前 YAML 中 “引用了但磁盘上没有 `.bpf.o`” 的对象只有 `8` 个，对应 `10` 个 program：

- `bpftrace`: 5 个 object
  - `exec_trace.bpf.o`
  - `open_latency.bpf.o`
  - `scheduler_latency.bpf.o`
  - `tcp_connect.bpf.o`
  - `vfs_read_count.bpf.o`
- `tracee`: 1 个 object
  - `lsm_check.bpf.o`
- `xdp-tutorial`: 2 个 object
  - `xdp_prog_fail3.bpf.o`
  - `xdp_prog_kern3.bpf.o`

这是当前 YAML 真实缺口，而不是 2019 vs 764。

### 2.4 反过来，有很多 `.bpf.o` 在磁盘上但 YAML 根本没引用

当前磁盘上有 `170` 个 `.bpf.o` 不在 YAML 里。

repo 分布：

| Repo | Objects not in YAML |
| --- | ---: |
| linux-selftests | 89 |
| tetragon | 63 |
| bpftrace | 7 |
| cilium | 4 |
| libbpf-bootstrap | 3 |
| tracee | 2 |
| datadog-agent | 1 |
| netbird | 1 |

我对这 `170` 个对象做了离线 program 枚举：

| 指标 | 数值 |
| --- | ---: |
| On-disk-only objects | 170 |
| 其中可被 `list-programs` 正常解析 | 57 |
| 这些可解析对象合计可贡献 programs | 202 |
| 其中 `tetragon` 一家就占 | 188 programs / 51 objects |

注意：

- 这 `202` 不是全都值得加进 corpus
- 其中很多是 `tetragon` 的 versioned variant（如 `_v53` / `_v61` / `_v511`）
- 还有不少 selftests type-only 或 no-program object，不适合测量

### 2.5 当前 YAML 还有一个结构性上限：226 个 `compile_only`

当前 `2019` 个显式 program 里，按 `test_method` 分布是：

| test_method | programs |
| --- | ---: |
| `attach_trigger` | 1475 |
| `bpf_prog_test_run` | 318 |
| `compile_only` | 226 |

这 `226` 个 `compile_only` program 天生不可能进入 measured。

把缺失对象里的 `10` 个 program 扣掉之后，当前磁盘上真实可测量 ceiling 是：

- `1467 + 316 = 1783`

所以在 current v2 world 里，理论上限都不是 2019 measured，而是 `1783 measured max`。

## 3. 764 -> 442：为什么只有 442 个 compile/load 成功

这一层的精确总数来自 `2026-03-26` full run。

由于 `corpus/results/vm_corpus_20260326_201508/details/result.json` 现在已经不在工作区，我复用了当时保存在 `docs/tmp/20260326/corpus_results_analysis_20260326.md` 里的逐程序聚合结果。

### 3.1 旧 full run 的精确 compile gap

`764 - 442 = 322` 个 target 没有形成 compile pair。

按首个失败原因汇总：

| 首个失败阶段 | 原因 | 数量 |
| --- | --- | ---: |
| baseline_compile | `bpf_object__load failed: Invalid argument` | 217 |
| baseline_compile | `bpf_object__load failed: No such file or directory` | 33 |
| baseline_compile | `bpf_object__load failed: Permission denied` | 32 |
| baseline_compile | `bpf_object__load failed: No such process` | 22 |
| baseline_compile | `bpf_object__load failed: Bad file descriptor` | 9 |
| baseline_compile | `bpf_object__open_file failed: Operation not supported` | 5 |
| baseline_compile | `bpf_object__open_file failed: No such file or directory` | 2 |
| baseline_compile | `bpf_object__load failed: Argument list too long` | 1 |

这 8 个 bucket 加起来正好是 `322`。

### 3.2 哪些 source 丢得最多

按 source 的 compile gap：

| Source | Programs | Compile | Compile Gap |
| --- | ---: | ---: | ---: |
| linux-selftests | 417 | 251 | 166 |
| xdp-tools | 51 | 5 | 46 |
| bcc | 90 | 46 | 44 |
| xdp-tutorial | 38 | 23 | 15 |
| tetragon | 23 | 12 | 11 |
| loxilb | 6 | 0 | 6 |
| scx | 9 | 4 | 5 |
| systemd | 9 | 4 | 5 |
| KubeArmor | 5 | 0 | 5 |
| bpftrace | 5 | 0 | 5 |

观察：

- 旧 full run 的 compile gap 主体并不是“build 没有 object”，而是 “object 有了，但 load/loader/verifier/runtime 前置条件不满足”
- `xdp-tools`、`bcc`、`linux-selftests` 是 compile/load harness 的三大主漏斗

### 3.3 当前 v2 run 又出现了一个新的 compile-side blocker：prepared state

当前 `2026-03-28` 仍在运行的 v2 run（partial snapshot，`826` program records）里，compile/load failure 的最大单点已经不是 `EINVAL`，而是 orchestration：

| 当前 partial failure category | 数量 |
| --- | ---: |
| prepared state missing | 308 |
| attach failure | 91 |
| no runtime attempt recorded | 35 |
| io_mode mismatch | 7 |

其中 prepared-state miss 主要打在：

| Repo | Count |
| --- | ---: |
| bcc | 124 |
| linux-selftests | 118 |
| KubeArmor | 63 |

按 prog_type 看：

| Prog type | Count |
| --- | ---: |
| kprobe | 138 |
| tracing | 87 |
| sched_cls | 25 |
| raw_tracepoint | 22 |
| struct_ops | 10 |
| lsm | 9 |

结论：

- 对 `2026-03-26` full run，compile/load 主问题是 loader/verifier/runtime precondition
- 对 `2026-03-28` current v2 run，最先要修的是 prepared-state orchestration bug

## 4. 442 -> 315：为什么 compile 成功了，还是只有 315 个 measured

### 4.1 旧 full run 的精确 measured gap

`442 - 315 = 127` 个 compile pair 没有形成 measured pair。

按原因汇总：

| 原因 | 数量 |
| --- | ---: |
| `bpf_program__attach failed: Operation not supported` | 75 |
| `bpf_program__attach failed: No such file or directory` | 17 |
| `io-mode packet requires an XDP or skb packet context` | 15 |
| `bpf_program__attach failed: Bad file descriptor` | 9 |
| `bpf_program__attach failed: Invalid argument` | 7 |
| `bpf_program__attach failed: Device or resource busy` | 3 |
| `bpf_object__load failed: No such file or directory` | 1 |

这 7 个 bucket 加起来正好是 `127`。

### 4.2 旧 run 的 measured gap 不是“跑不快”，而是 harness/attach 跑不起来

从这个分布看，`442 -> 315` 的主因很明确：

1. attach 不支持 / attach 点不存在
2. `io_mode` 和 prog_type/context 不匹配
3. 少量 runtime load / resource busy

也就是说，这一层不是优化 pass coverage 问题，而是 benchmark harness 能否把程序真正 attach/run 起来的问题。

### 4.3 current v2 manifest 里，有一部分程序天生不会 measured

如前所述，当前 YAML 里：

- `226` 个 program 是 `compile_only`
- 当前磁盘上可测量上限只有 `1783 / 2019 = 88.3%`

换句话说，未来即使把 attach/harness 全修好，也不可能让 measured 覆盖到 2019。

### 4.4 当前 partial run 里，measured gap 的类型画像

在 `2026-03-28` partial snapshot 里，runtime failure 画像是：

| 类别 | 数量 |
| --- | ---: |
| attach failure | 91 |
| no runtime attempt recorded | 35 |
| io_mode mismatch | 7 |

其中 `35` 个 “no runtime attempt recorded” 并不是 bug，而是配置本身就是：

| test_method | prog_type | 数量 |
| --- | --- | ---: |
| `compile_only` | `syscall` | 18 |
| `compile_only` | `struct_ops` | 17 |

attach failure 则主要集中在：

| Repo | Count |
| --- | ---: |
| bcc | 35 |
| linux-selftests | 28 |
| coroot-node-agent | 20 |
| libbpf-bootstrap | 8 |

按 prog_type：

| Prog type | Count |
| --- | ---: |
| kprobe | 38 |
| tracepoint | 22 |
| tracing | 14 |
| cgroup_sockopt | 8 |
| perf_event | 5 |

`io_mode mismatch` 全部集中在：

| Prog type | Count |
| --- | ---: |
| flow_dissector | 7 |

所以 current v2 world 的 measured bottleneck 可以拆成三类：

1. `compile_only` 结构性不可测
2. attach handler / attach point / attach mode 缺失
3. packet-mode 配置与 prog_type/context 不匹配

## 5. 315 -> 130：为什么只有 130 个 applied

### 5.1 `130 applied` 是旧 mixed-pass run，不是当前 active pass 的真值

`2026-03-26` 那次 full run 的 compile-pass hits 是：

| Pass | Compile hits |
| --- | ---: |
| const_prop | 71 |
| live_patch | 63 |
| endian_fusion | 60 |
| dangerous_helper_firewall | 44 |
| wide_mem | 34 |
| dce | 19 |
| cond_select | 10 |
| extract | 7 |
| skb_load_bytes_spec | 1 |
| map_inline | 0 |

所以：

- `130 applied` 主要不是 current `[map_inline, const_prop, dce]` 的结果
- 它主要来自一堆后来已经不该混进 perf benchmark 的 pass
- 最关键的是：`map_inline = 0`

这也是为什么 `130` 不能回答 “当前 active passes 覆盖面到底如何”

### 5.2 当前 perf-only partial run 的 applied coverage 已经明显高于 130

在 `2026-03-28` 的 partial snapshot（`826` records）里：

| 指标 | 数值 |
| --- | ---: |
| compile pairs | 518 |
| measured pairs | 385 |
| applied programs | 334 |

pass 组合分布：

| Pass combo | Programs |
| --- | ---: |
| `const_prop + dce + map_inline` | 226 |
| `const_prop` only | 97 |
| `const_prop + dce` | 7 |
| `map_inline` only | 4 |

repo / pattern 画像：

| 画像 | 主要集中区 |
| --- | --- |
| `map_inline + const_prop + dce` 三连击 | `bcc` 的 `kprobe / tracepoint / raw_tracepoint` |
| `const_prop` only | `calico`、`coroot-node-agent` |
| `map_inline` only | 少量 `linux-selftests` / `katran` / `xdp` |

按 repo 的 pass hit：

| Repo | const_prop | dce | map_inline |
| --- | ---: | ---: | ---: |
| bcc | 204 | 204 | 199 |
| calico | 51 | 0 | 0 |
| coroot-node-agent | 46 | 0 | 0 |
| linux-selftests | 18 | 18 | 22 |
| libbpf-bootstrap | 9 | 9 | 8 |

结论：

- current perf-only pipeline 的 applied coverage 已经明显不是 130 这个量级
- 真正限制 current run 的不是 pass 命中，而是 prepared-state / attach / test_method ceiling

### 5.3 如果换成 `wide_mem + [map_inline,const_prop,dce]`，applied 会是多少

不能在不 rerun 的情况下给出精确值，但可以做保守估计。

历史证据：

- 在 `2026-03-26` 的旧 full run 里，`wide_mem` 命中了 `34` 个 compile-pair 程序
- 但其中大头在 `calico`，而 `calico` 同时已经有 `const_prop(51)` 的大面积覆盖
- `wide_mem` 的 source 分布主要是：
  - `calico`: 28
  - `tracee`: 2
  - `xdp-tutorial`: 2
  - `linux-selftests`: 2

因此：

- `wide_mem` 的绝对命中不低
- 但它对 “unique applied programs” 的边际增量很可能没有 `34` 那么大，因为和 `const_prop` 高度重叠

保守估计：

- 对旧 `764` target set：加上 `wide_mem` 的 unique applied 增量大概率是 `+5 ~ +15`
- 对 current `2019` program set：如果 harness 修好、全量跑完，增量大概率是低两位数，而不是几百

也就是说：

- `wide_mem` 值得加回做对照
- 但它不是当前 coverage bottleneck 的主杠杆

## 6. 每一级瓶颈的修复方案

### 6.1 Stage A: build availability (`2019 -> 557/639`)

| 项目 | 结论 |
| --- | --- |
| 短期修复（1-2 天） | 统一 availability 口径，把 on-disk existing object 也纳入 build summary；同时修掉 YAML 缺失的 8 个 object/10 个 program |
| 中期改进（1 周） | 修 `asm/types.h` 头路径、selftests helper prototype drift、tetragon repo-local include 路径 |
| 预估收益 | 报告口径立刻从 `557 -> 639`（`+82` object）；真实可新增 target 先是 `+10` YAML-missing program，再往上才取决于是否把新构建对象写进 YAML |

优先级说明：

- 如果目标是“把 current corpus 可测程序数拉高”，先修 report accounting 和缺失 object
- 如果目标是“扩充对象池”，再投入 `asm/types.h` / selftests / tetragon include

### 6.2 Stage B: manifest coverage (`557/639 -> 2019`)

| 项目 | 结论 |
| --- | --- |
| 短期修复（1-2 天） | 停止在分析里继续使用旧的 `764 selected_entries` 口径；所有 coverage 统一改看 v2 的 `selected_programs` / `total_programs` |
| 中期改进（1 周） | 从 `170` 个 on-disk-only object 里挑 `57` 个可枚举、且非明显重复/空壳的对象进 YAML |
| 预估收益 | 理论上限 `+202` program；扣掉 versioned duplicates 之后，保守更像 `+60 ~ +120` 个“有意义”的新增 target |

这里最关键的不是写更多 YAML，而是先做 curated expansion：

- `tetragon` versioned variant 可以选一版代表
- selftests 里的 type-only / no-program object 不该盲目纳入

### 6.3 Stage C: compile/load success (`764 -> 442`)

| 项目 | 结论 |
| --- | --- |
| 短期修复（1-2 天） | 对 current v2 run，先修 prepared-state ref bug；对旧 workload，补 loader/BTF/test_method preflight，把明显 unsupported 的对象在 compile 前就筛掉或改正确 loader |
| 中期改进（1 周） | 为 `kprobe / tracing / sched_cls / lsm / struct_ops` 建更细的 support matrix 和 loader policy，减少 `EINVAL/EPERM/ENOENT/ESRCH` 这类大桶 |
| 预估收益 | current partial slice 里 prepared-state bug 一项就卡了 `308` 个程序；旧 `764` workload 上，修 loader/harness 后保守可把 `442` 提到 `500+`，再往上取决于 verifier/attach 能力 |

这是当前最该优先做的 runtime coverage 杠杆。

### 6.4 Stage D: measured success (`442 -> 315`)

| 项目 | 结论 |
| --- | --- |
| 短期修复（1-2 天） | 修 `io_mode` 错配、补 attach handler、把 `compile_only` program 从 measured denominator 单独列出去 |
| 中期改进（1 周） | 为 `tracepoint / kprobe / cgroup_sockopt / perf_event / flow_dissector` 做 program-type-specific attach/test-run policy |
| 预估收益 | 旧 `764` workload 上，`15` 个 `io_mode mismatch` 基本是直接可回收；再加上 `17 ENOENT + 9 EBADF + 7 EINVAL + 3 EBUSY` 的一部分，短期可望多拿 `+25 ~ +40` measured；中期做完 attach harness 后，旧口径上看到 `350 ~ 400+ measured` 是合理目标 |

注意 current v2 的 measured ceiling 不是 `2019`，而是 `1783`。

### 6.5 Stage E: applied coverage (`315 -> 130`)

| 项目 | 结论 |
| --- | --- |
| 短期修复（1-2 天） | 不要再用 `2026-03-26` 的 `130 applied` 评估 current active passes；先把 current full run 跑完并保留 `details/result.json` |
| 中期改进（1 周） | 做一个 `[map_inline,const_prop,dce]` 与 `[map_inline,const_prop,dce,wide_mem]` 的 full-corpus ablation；保留 per-program artifact |
| 预估收益 | `wide_mem` 的边际 unique applied 增量更像低两位数；真正的 applied 覆盖提升主要还是来自把 full run 跑通，而不是再加 pass |

## 7. 优先级排序

如果目标是最快把 “paired measurement coverage” 拉高，我建议顺序是：

1. 修 current v2 run 的 prepared-state orchestration
2. 把 `compile_only` 从 measured 口径里单列，停止把结构性不可测程序算进漏斗
3. 修 `attach` / `io_mode` harness
4. 统一 build availability 统计，把 `557` 和磁盘 `639` 的差补齐
5. 再做 YAML curated expansion
6. 最后才是 `wide_mem` ablation

原因很简单：

- 现在最大的 coverage 损失不在 “pass 没命中”
- 而在 “程序没被正确准备、没被正确 attach、或者压根就不该算进 measured denominator”

## 8. 最终判断

这次调查后，我对漏斗的判断是：

1. `2019 -> 557 -> 764 -> 442 -> 315 -> 130` 不是一条单一时间点的 current pipeline，而是新旧口径混合体。
2. 当前 YAML 本身几乎不是 bottleneck；它对现存对象里的 `2009` 个 program 基本全覆盖。
3. 当前最先该修的是：
   - availability 统计低估（`557` vs 磁盘 `639`）
   - prepared-state orchestration
   - attach / io_mode harness
   - measured denominator 里混入 `compile_only`
4. `130 applied` 已经过时；当前 perf-only partial run 在还没跑完的情况下已经到 `334 applied`。
5. `wide_mem` 有价值，但不是现在 coverage 提升的主杠杆；它更像 low-teens incremental lift，而不是决定性突破。

