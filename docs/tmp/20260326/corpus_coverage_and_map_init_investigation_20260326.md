# 2026-03-26 BpfReJIT Corpus Coverage 与 Map 初始化调查

## 调查范围与口径

本报告基于以下文件与目录：

- `runner/repos.yaml`
- `corpus/config/macro_corpus.yaml`
- `runner/scripts/build_corpus_objects.py`
- `runner/libs/repo_registry.py`
- `corpus/modes.py`
- `daemon/src/passes/map_inline.rs`
- `daemon/src/analysis/map_info.rs`
- `daemon/src/bpf.rs`
- `runner/src/kernel_runner.cpp`
- `runner/repos/`
- `corpus/build/`

我采用了三种不同但必须区分的计数口径：

1. `macro_corpus.yaml` entry 数
   - 即 `programs:` 下的 YAML 条目数。
   - 当前是 **764**。

2. `macro_corpus.yaml` 显式 program 引用数
   - 每个 entry 的 `program_name` 记 1。
   - 每个 entry 的 `program_names` 按数组长度累计。
   - 当前是 **2028** 个显式 program 引用；按“每个对象内部去重”后是 **2027**。

3. `corpus/build/**/*.bpf.o` 实际包含的可加载 program 数
   - 我按 ELF 符号表统计：`STT_FUNC`、`STB_GLOBAL/STB_WEAK`、位于“可执行且非 `.` 前缀 section”中的函数。
   - 这样比“按 section 数”更接近 libbpf 的真实可加载入口，因为一个 section 里可以有多个入口函数，例如 `xdp-tools/xdp_basic.bpf.o`。
   - 当前是 **2073** 个可加载 program。

补充说明：

- `runner/libs/repo_registry.py` 只是把权威 repo 列表指向 `runner/repos.yaml` 和 `runner/repos/`，没有隐藏的第二套注册表。
- `runner/scripts/build_corpus_objects.py` 只会对 `harvest_globs` 非空的 repo 做源码发现与编译；但它还会把 `macro_corpus.yaml` 里已经存在的对象按 `prebuilt` 方式 stage 进来，所以 `harvest_globs: []` 的 repo 仍然可能出现在 `corpus/build/` 中。
- `corpus/modes.py` 最终按“每个 YAML entry 一个 target”加载；如果只有 `program_names`，它只取第一个名字作为 `target["program_name"]`。所以运行时 target 数仍然是 **764**，不是 2028。

关键代码依据：

- repo registry 入口：`runner/libs/repo_registry.py:11-34`
- harvest/source 发现：`runner/scripts/build_corpus_objects.py:198-235`
- source -> object work item：`runner/scripts/build_corpus_objects.py:330-380`
- prebuilt stage：`runner/scripts/build_corpus_objects.py:477-520`
- YAML target 裁剪为单一 `program_name`：`corpus/modes.py:1126-1188`

## Question 1：`runner/repos.yaml` 里的 repo 是否都在 `macro_corpus.yaml` 中有表示？

### 1.1 `runner/repos.yaml` 的全部注册 repo

注册 repo 一共 **21** 个：

1. `xdp-examples`
2. `xdp-tools`
3. `xdp-tutorial`
4. `bcc`
5. `scx`
6. `katran`
7. `tetragon`
8. `cilium`
9. `netbird`
10. `systemd`
11. `KubeArmor`
12. `calico`
13. `coroot-node-agent`
14. `datadog-agent`
15. `loxilb`
16. `opentelemetry-ebpf-profiler`
17. `suricata`
18. `tracee`
19. `tubular`
20. `libbpf-bootstrap`
21. `linux-selftests`

`ls runner/repos/` 的实际结果表明：这 **21 个 checkout 全都已经抓取到本地**，没有 manifest repo 缺 checkout。

实际 `runner/repos/`：

```text
KubeArmor
bcc
calico
cilium
coroot-node-agent
datadog-agent
katran
libbpf-bootstrap
linux-selftests
loxilb
netbird
opentelemetry-ebpf-profiler
scx
suricata
systemd
tetragon
tracee
tubular
xdp-examples
xdp-tools
xdp-tutorial
```

### 1.2 `corpus/build/` 当前实际目录

`ls corpus/build/` 的实际结果：

```text
KubeArmor
bcc
bpftrace
calico
cilium
coroot-node-agent
datadog-agent
katran
libbpf-bootstrap
linux-selftests
loxilb
manual-test
netbird
opentelemetry-ebpf-profiler
real_world_code_size
scx
suricata
systemd
tetragon
tracee
tubular
xdp-examples
xdp-tools
xdp-tutorial
targeted-ebpf-compile-report.md
```

这里有 3 个 **不在** `runner/repos.yaml` 里的额外 family/目录：

- `bpftrace`
- `manual-test`
- `real_world_code_size`

这说明：`macro_corpus.yaml` 和 `corpus/build/` 的覆盖面，实际上比 `runner/repos.yaml` 更宽。

### 1.3 按 repo 的 corpus 表示情况

下表中的：

- `Macro entries` = `macro_corpus.yaml` 中属于该 repo 的 entry 数。
- `Built .bpf.o` = `corpus/build/<repo>/` 下的对象数。
- `Built programs` = 上述对象里实际可加载 program 总数。
- `Missing objects` = build 树中存在、但 `macro_corpus.yaml` 没有引用到的对象数。
- `Missing programs` = build 树中存在、但 `macro_corpus.yaml` 未覆盖到的 program 数。

| Repo | Macro entries | Built .bpf.o | Built programs | Missing objects | Missing programs | 备注 |
|---|---:|---:|---:|---:|---:|---|
| xdp-examples | 0 | 0 | 0 | 0 | 0 | 唯一完全未进 macro；当前 build 也没有对象（但 manifest 可 harvest 13 个源文件） |
| xdp-tools | 51 | 13 | 99 | 0 | 0 | 完整覆盖 |
| xdp-tutorial | 38 | 25 | 51 | 0 | 0 | 完整覆盖 |
| bcc | 90 | 57 | 365 | 0 | 1 | 仅 `cpudist` 有 1 个名字不匹配/漏项 |
| scx | 9 | 4 | 85 | 0 | 0 | 完整覆盖；对象来自 promoted cargo 产物 |
| katran | 5 | 5 | 5 | 0 | 0 | 完整覆盖；另有专用 fixture |
| tetragon | 23 | 23 | 90 | 0 | 0 | 完整覆盖 |
| cilium | 3 | 3 | 36 | 0 | 33 | 对象都在，但对象内大多数 program 未列入 corpus |
| netbird | 1 | 2 | 2 | 1 | 1 | 多出 1 个路径别名对象；程序名相同，偏向路径重复而非真实 coverage gap |
| systemd | 9 | 8 | 16 | 0 | 0 | 完整覆盖；build 中存在扁平/嵌套双路径对象 |
| KubeArmor | 5 | 3 | 63 | 0 | 0 | 完整覆盖 |
| calico | 59 | 8 | 59 | 0 | 0 | 完整覆盖 |
| coroot-node-agent | 2 | 1 | 46 | 0 | 0 | 完整覆盖 |
| datadog-agent | 1 | 2 | 4 | 1 | 3 | 漏了 `noisy-neighbor-kern.bpf.o` 的 3 个 `tp_btf` 程序 |
| loxilb | 6 | 3 | 18 | 0 | 0 | 完整覆盖 |
| opentelemetry-ebpf-profiler | 3 | 3 | 4 | 0 | 0 | 完整覆盖 |
| suricata | 2 | 2 | 2 | 0 | 0 | 完整覆盖 |
| tracee | 5 | 2 | 170 | 0 | 0 | 完整覆盖 |
| tubular | 1 | 1 | 1 | 0 | 0 | 完整覆盖 |
| libbpf-bootstrap | 12 | 12 | 21 | 0 | 0 | 完整覆盖 |
| linux-selftests | 417 | 369 | 901 | 89 | 9 | 对象缺口大，但 89 个未引用对象里 82 个没有可加载 program；真实程序缺口仅 9 |

### 1.4 直接回答

结论：**不是所有 `runner/repos.yaml` repo 都在 `macro_corpus.yaml` 中被表示。**

唯一完全没有 entry 的 repo 是：

- `xdp-examples`

#### `xdp-examples` 的具体情况

- `macro_corpus.yaml` entry 数：**0**
- `corpus/build/xdp-examples/**/*.bpf.o`：**0**
- 但按照 `runner/repos.yaml` 的 `harvest_globs`，当前 checkout 可发现 **13** 个 source-backed 候选文件。
- 我对这 13 个源文件做了保守静态扫描，按 `SEC("...")`（排除 `.maps/.rodata/.bss/license/...`）粗略统计，大约有 **31** 个“program-like section”。

这里要明确区分两件事：

- 这 **13 / ~31** 是“当前 checkout 中能看到的候选规模”。
- 因为它们 **还没有被构建成 `corpus/build/xdp-examples/*.bpf.o`**，所以我不能像其他 repo 那样给出“基于 build tree 验证过的精确 program 数”。

也就是说，`xdp-examples` 当前不是“对象已建好但没进 corpus”，而是更早一层的问题：**repo 已注册、已抓取，但当前 corpus build 树里没有它的对象产物。**

### 1.5 哪些 repo “明确有 `.bpf.o`，但还没加完整”？

如果只看 **当前已经存在于 `corpus/build/` 的对象**，真正的 gap 集中在下面几类：

1. `cilium`
   - 对象都已经在 build 里：3 个对象。
   - 但 3 个对象合计有 **36** 个 program，`macro_corpus.yaml` 只覆盖了 **3** 个，漏了 **33** 个。
   - 漏项基本都在：
     - `bpf_lxc.bpf.o`
     - `bpf_overlay.bpf.o`
     - `bpf_xdp.bpf.o`
   - 本质上这是“对象已入 corpus，但对象内只挑了代表程序，没有穷举 tail/helper datapath 程序”。

2. `datadog-agent`
   - 当前 build 有 **2** 个对象 / **4** 个程序。
   - macro 只覆盖 `oom-kill-kern.bpf.o`。
   - 未覆盖对象是：
     - `corpus/build/datadog-agent/noisy-neighbor-kern.bpf.o`
   - 该对象漏掉的 3 个程序：
     - `tp_sched_wakeup`
     - `tp_sched_wakeup_new`
     - `tp_sched_switch`

3. `linux-selftests`
   - 当前 build 有 **369** 个对象 / **901** 个程序。
   - macro 覆盖 **280** 个对象。
   - 但这 89 个“未引用对象”里，**82 个根本没有可加载 program**；它们大多是 BTF/CO-RE 结构探测、最小支持对象、或纯辅助测试产物。
   - 真正有程序却没进 macro 的，只有 **7 个对象 / 9 个程序**：
     - `linked_maps1.bpf.o`：2
     - `linked_maps2.bpf.o`：2
     - `linked_funcs1.bpf.o`：1
     - `linked_funcs2.bpf.o`：1
     - `linked_vars1.bpf.o`：1
     - `linked_vars2.bpf.o`：1
     - `test_usdt_multispec.bpf.o`：1

4. `bcc`
   - 不是对象缺口，而是 **1 个名字漂移**。
   - `cpudist.bpf.o` 中实际程序名是 `sched_switch_btf` / `sched_switch_tp`。
   - YAML 中写的是 `sched_switch` / `sched_switch_tp`。
   - 结果：
     - 1 个 YAML 名字匹配不到真实对象；
     - 同时也留下 1 个 built program 没被覆盖。

5. `netbird`
   - build 里有两个对象路径：
     - `corpus/build/netbird/prog.bpf.o`
     - `corpus/build/netbird/client/internal/ebpf/ebpf/src/prog.bpf.o`
   - 两者都只含同一个程序：`nb_xdp_prog`
   - 所以它更像 **路径别名/平铺与保留相对路径的并存**，而不是“多出一个真实未覆盖程序”。

### 1.6 为什么 build 树与 manifest source 路径对不上？

这是这次调查里非常重要的背景，不然会误判 gap：

1. `build_corpus_objects.py` 的源码编译路径是按 source 相对路径保留层级构造的。
2. 但同一个脚本也会把 `macro_corpus.yaml` 里已存在的对象以 `prebuilt` 方式直接 stage 进来。
3. 当前 `corpus/build/` 里混合了：
   - source-backed 编译产物
   - prebuilt/staged 对象
   - 平铺命名对象
   - 保留原始相对路径的对象

因此：

- `systemd` 同时出现了扁平路径和嵌套路径对象；
- `netbird` 也出现了同一程序的双路径对象；
- `katran`、`tetragon`、`xdp-tools` 里，build 对象名和 repo 内源码相对路径不总是一一对应。

所以真正可靠的 coverage 分析，应该像本报告一样，直接以 **`corpus/build/` 当前对象 + ELF program 名** 为准，而不是只按 source 相对路径猜。

## Question 2：如何初始化 maps，才能让 map inline 测试更有意义？

### 2.1 当前代码的真实行为

#### 1. map 是如何创建的

`runner/src/kernel_runner.cpp:1338-1375` 的 `create_kernel_maps()` 会按 `program_image` 创建 map 并复用到 object 上，但**不会填充值**。默认就是空 map / 零值 map。

#### 2. 目前唯一的通用外部写 map 逻辑

`runner/src/kernel_runner.cpp:325-361` 只有一个显式的、非 `input_map/result_map` 的 fixture：`initialize_katran_test_fixture()`。

而且它会在 daemon optimize 之前调用（`runner/src/kernel_runner.cpp:1888-1908`），所以 Katran 的 map inline 能看到非空 live map 状态。

#### 3. `input_map/result_map` 的写入时机

`runner/src/kernel_runner.cpp:1937-1980` 里，`input_map` / `result_map` 的写入发生在 `daemon_socket_optimize(...)` 之后。

这意味着：

- 如果以后要给“通用 map 自动填充”找插入点，**时机非常重要**。
- 任何发生在 optimize 之后的 map 变更，都可能让 stock 和 rejit 看到不同的 live map 状态。

#### 4. map inline 到底依赖什么

`daemon/src/analysis/map_info.rs:35-75` 表明，v1 只允许：

- `ARRAY`
- `HASH`
- `LRU_HASH`

这些支持 direct value access 的 map 进入 inline 逻辑；`PERCPU_*` 被明确排除。

`daemon/src/passes/map_inline.rs:159-249` 还要求：

- lookup key 必须是常量栈物化；
- 结果用途必须是固定偏移 scalar load；
- `HASH/LRU_HASH` 这种 speculative inline 还要求紧跟的 null-check。

真正的值读取发生在：

- `daemon/src/passes/map_inline.rs:418-449`
- `daemon/src/bpf.rs:575-596`

即 daemon 会按 `map_id + key bytes` 直接对 live map 做 `BPF_MAP_LOOKUP_ELEM`，拿到当前 value bytes，再把固定偏移 load 改写成常量。

这有两个重要推论：

1. **BTF 不是 inline 的必要前提。**
   - 现在的 pass 根本不按字段语义推断值，它只是读“当前 live bytes”。

2. **空 map 对 ARRAY 和 HASH 的影响不一样。**
   - 这是我基于内核 map 语义做的推论。
   - `ARRAY` 即便“没初始化”，对应 key 的槽位也存在，只是 value 默认为 0，所以 map inline 仍可能发生，只是读到的是零值。
   - `HASH/LRU_HASH` 如果没插入对应 key，则 lookup 会失败，site 会直接 skip。

因此，“maps start empty”真正最伤 coverage 的，主要不是 ARRAY，而是 **HASH/LRU_HASH**。

### 2.2 对五种方案的逐项评估

| 方案 | 优点 | 关键问题 | 结论 |
|---|---|---|---|
| a) Auto-init from BTF | 泛化强；理论上能按类型生成非零值 | 实现复杂；当前 `MapInfo` 不携带 BTF type id，需额外 plumbing；更关键的是它解决“value 长什么样”，**不解决 HASH 应该插哪些 key** | 不建议作为第一实现 |
| b) Capture from E2E | 最真实；对 Tracee/Katran/Tetragon 这类真实应用最有价值 | 覆盖面窄；依赖每个 app 的 userspace；版本漂移大；采集/回放成本高 | 适合作为后续旗舰样本，不适合作为 corpus 通用方案 |
| c) Per-target fixtures in YAML | 精确、可审查、可复现 | 对 764 个 entry 不可扩展；维护成本高 | 适合作为少量例外/逃生阀，不适合作为主路径 |
| d) Runner auto-populate | 最容易落地；对所有 corpus 程序都生效；对 ARRAY 很有效 | 如果只是“随机非零”，对 HASH 几乎没用，因为随机 key 基本撞不上程序里写死的常量 key；还必须处理 optimize 前后的状态一致性 | **最佳起点，但必须做成 deterministic + key-aware** |
| e) Two-phase measurement | 能保证 stock/rejit 用同一份 map 状态；对 correctness/fairness 非常关键 | 它不是初始化策略本身，只是执行纪律 | **必须和 d/b/c 之一组合使用** |

### 2.3 最重要的深层问题：HASH 不是“填点随机值”就够了

这次调查里最关键的技术点是：

- `map_inline` 只对“常量 key 的 lookup”起作用。
- 所以对 `HASH/LRU_HASH`，如果 runner 只是“插几个随机 key/value”，大概率对 inline coverage **几乎没有帮助**。

换句话说：

- `ARRAY`：可以直接把所有 index 填上 deterministic 非零模式，收益明确。
- `HASH/LRU_HASH`：需要知道程序实际上会 lookup 哪些 key，至少要把这些 key 插进去。

这也是为什么我不建议先做方案 a)：

- BTF 只能告诉你“value type 长什么样”；
- 但 map inline 先卡死在“key 是否命中 live map”这一步；
- 对 HASH 而言，**key selection 比 value synthesis 更重要**。

### 2.4 推荐方案

我的建议是：**以 d + e 为主，辅以少量 c，b 放到后面；a 不作为第一优先级。**

#### 推荐组合：`d + e + 少量 c`

1. 先做 `d) Runner auto-populate`
   - 但不是“随机非零”版本，而是：
   - `ARRAY`：
     - 对所有 index 统一填 deterministic、稳定的非零模式；
     - 例如基于 `map_id + key + offset` 生成固定字节模式。
   - `HASH/LRU_HASH`：
     - 不要随机插 key；
     - 要先从程序里静态提取“会被常量 lookup 的 key”，然后只填这些 key。

2. 强制配套 `e) Two-phase measurement`
   - baseline 和 rejit 必须看到同一份 map 状态。
   - 最稳妥的执行原则是：
     - 先把最终要测试的 map 状态准备好；
     - stock 跑一遍；
     - 在**不再改 map** 的前提下做 rejit；
     - 然后 rejit 再跑。

3. 保留 `c) YAML fixtures` 作为例外机制
   - 例如 Katran 这类“语义要求很强”的对象，或者以后某些需要特定 key/value 关系的 target。

4. `b) E2E capture` 只用于少量旗舰应用
   - 我会把它定位在“真实性验证”和“后续高价值样本”。
   - 不会把它当成 corpus 的基础设施。

### 2.5 为什么不是先做 a) BTF auto-init

原因有四个：

1. 现在 pass 读的是 live bytes，不是类型语义。
2. 当前 `BpfMapInfo` 确实带了 `btf_id` / `btf_key_type_id` / `btf_value_type_id`，但 `MapInfo` 目前并没有把这部分信息往上传。
3. 即使拿到了 BTF，仍然解决不了 HASH “该插什么 key” 的核心问题。
4. 对 correctness testing 而言，deterministic non-zero bytes 已经足够；没必要先上类型级生成器。

对应代码：

- `BpfMapInfo` 里的 BTF 字段：`daemon/src/bpf.rs:168-189`
- `MapInfo` 当前只保留了 map type / key_size / value_size / max_entries / frozen / map_id：`daemon/src/analysis/map_info.rs:24-33`

## Question 3：`runner/repos` 与 `macro_corpus.yaml` 的总量差距到底是多少？

### 3.1 总量

#### 整个 `corpus/build/`

- `.bpf.o` 对象总数：**568**
- 可加载 program 总数：**2073**

#### 其中，来自 `runner/repos.yaml` 注册 repo 的部分

- 对象：**546**
- 程序：**2038**

#### 其中，来自 manifest 之外的额外 family

| 额外目录 | Macro entries | Built .bpf.o | Built programs |
|---|---:|---:|---:|
| bpftrace | 5 | 5 | 7 |
| manual-test | 2 | 2 | 4 |
| real_world_code_size | 15 | 15 | 24 |

也就是说，`macro_corpus.yaml` 不是简单的“manifest repo 子集”，它额外纳入了 **22** 个 entry / **22** 个对象 / **35** 个程序的 manifest 外样本。

### 3.2 `macro_corpus.yaml` 里到底有多少

整个 `macro_corpus.yaml` 当前包含：

- entry：**764**
- unique object：**477**
- 显式 program 引用：**2028**
- 去重后的 per-object unique program 引用：**2027**
- `corpus/modes.py` 实际会生成的 target 数：**764**

只看 manifest repo，对应是：

- entry：**742**
- unique object：**455**
- 显式 program 引用：**1993**
- 去重后的 per-object unique program 引用：**1992**

### 3.3 真正的 gap 有多大

#### 从对象数看

- overall object coverage：`477 / 568 = 83.98%`
- manifest-only object coverage：`455 / 546 = 83.33%`

这个百分比看起来不高，但它被 `linux-selftests` 的大量“零 program 支持对象”严重拉低了。

#### 从程序数看

整体 build tree：

- matched program：**2026**
- missing program：**47**
- unmatched YAML name：**1**
- program coverage：`2026 / 2073 = 97.73%`

只看 manifest repo：

- matched program：**1991**
- missing program：**47**
- unmatched YAML name：**1**
- program coverage：`1991 / 2038 = 97.69%`

所以更准确的结论是：

- **对象覆盖缺口看起来大；**
- **但真实可加载 program 覆盖已经接近 98%。**

### 3.4 这 47 个 missing programs 从哪来

可以拆成两类：

1. **对象未被引用**：**13** 个 program
   - 来自 **9** 个对象
   - 其中：
     - `datadog-agent`：3
     - `linux-selftests`：9
     - `netbird`：1（路径别名）

2. **对象已入 corpus，但对象内 program 没列全**：**34** 个 program
   - 来自 **4** 个对象
   - 其中：
     - `cilium`：33
     - `bcc`：1

### 3.5 为什么会缺这些

我把原因分成 5 类：

1. **repo 注册了，但当前 build 树里还没有对象**
   - 典型例子：`xdp-examples`
   - 这不是单纯“macro 没加 entry”，而是更前置的“对象还没出现在 build 树里”。

2. **对象进了 corpus，但只挑了代表程序**
   - 典型例子：`cilium`
   - 当前 corpus 更像“选 representative targets”，而不是“穷举对象里的所有入口”。

3. **确实有额外对象，但没被加进来**
   - 典型例子：`datadog-agent/noisy-neighbor-kern.bpf.o`

4. **路径平铺/别名导致的表面缺口**
   - 典型例子：`netbird`
   - 这是 object-path coverage gap，不一定是 semantic program coverage gap。

5. **support/selftest 工件膨胀了对象数**
   - 典型例子：`linux-selftests`
   - 89 个未引用对象里，82 个没有可加载 program。
   - 所以 object gap 远大于 real program gap。

## 最终建议

### 覆盖面

1. 先补 `xdp-examples`
   - 它是唯一完全没有 entry 的 manifest repo。
   - 但我建议先解决“为什么当前 `corpus/build/xdp-examples` 没对象”，再谈 macro 配置。

2. 再补 `datadog-agent/noisy-neighbor-kern.bpf.o`
   - 这是最明确、最低争议的真实漏项。

3. 把 `bcc/cpudist` 的 program name 修正掉
   - 这是 1 个纯名字漂移问题。

4. 对 `cilium` 明确策略
   - 如果 corpus 的目标是 representative benchmark，那么当前 3 个 entry 是有意抽样；
   - 如果目标是“repo 内 program 覆盖更完整”，那 `cilium` 是最大的 program-level 缺口，优先级应很高。

5. `linux-selftests` 不要只看对象数
   - 89 个未引用对象这个数字很吓人，但大多数并不是真正可跑的 benchmark target。
   - 真正有价值的 program 漏项只有 9 个。

### Map 初始化

1. 近期最佳方案：`d + e`
   - runner 侧 deterministic auto-populate；
   - 严格保证 stock/rejit 使用同一份 map 状态。

2. 对 `ARRAY` 直接全量填值
   - 这是最容易提升 map-inline 覆盖的通用手段。

3. 对 `HASH/LRU_HASH` 不要随机填 key
   - 必须 key-aware，否则收益极低。

4. `c` 作为 escape hatch 保留
   - 少量关键 target 用 YAML fixture。

5. `b` 只做旗舰样本
   - 例如 Katran / Tracee / Tetragon 这种真正需要“真实用户态 map 状态”的 case。

6. `a` 不建议先做
   - 它解决的是“值长什么样”，不是“程序实际查哪个 key”。

