# BpfReJIT 可扩展性与内存开销分析（2026-03-26）

## 1. 结论摘要

1. `apply-all` 没有程序数量上的硬编码上限。`daemon/src/commands.rs` 中的 `cmd_apply_all()` 只是顺序遍历 `bpf::iter_prog_ids()`，对每个 prog 调一次 `try_apply_one()`；因此它的主路径是 **O(N)**，不是 O(N^2)。
2. 现有最可靠的 per-program 时间基线来自 `docs/tmp/20260326/recompile_overhead_analysis_20260326.md`：
   - userspace pipeline 中位数：**1.994 ms/prog**
   - kernel `BPF_PROG_REJIT` syscall 中位数：**13.358 ms/prog**
   - 合计：**15.352 ms/prog**
3. 按这个基线外推，一次性 `apply-all` 的总耗时约为：
   - **100 个程序：1.535 s**
   - **500 个程序：7.676 s**
   - **1000 个程序：15.352 s**
   - **5000 个程序：76.760 s**
   用 reviewer 更容易消化的整数近似，就是 **~1.5 / 7.5 / 15 / 75 秒**。
4. `watch` 模式不是每轮都重跑全量 `apply-all`。它每轮仍会 **O(N)** 扫描 live prog ID，但只对“新出现的程序”或“被 invalidation 命中的程序”做 REJIT；稳态下是增量工作负载。
5. kernel 侧的**持久**额外内存主要是 `orig_prog_insns`：每个 live prog 多保留一份原始字节码，即 **`8 * insn_cnt` 字节/prog**。
6. 用 corpus 的精确静态计数，**2019 个程序**的 `insn_count` 总和是 **1,338,109**，因此 `orig_prog_insns` 的总持久额外内存是 **10,704,872 B = 10.21 MiB**。
7. kernel 侧 `tmp prog` 是 **瞬时**开销，不会随 `N` 累加。`apply-all` 是串行的，所以峰值只相当于“当前正在 REJIT 的那一个程序”的临时副本，复杂度是 **O(max_prog_size)**，不是 O(N) 累积。
8. daemon 侧 `apply-all` 的 RSS 也没有表现出按程序数持续累积的趋势。一次 VM sanity run 中，加载 **62** 个 live micro 程序后执行真实 `apply-all`：
   - 总耗时：**579 ms**
   - `VmRSS`：**2.1 MiB -> 9.97 MiB**
   - `VmHWM`：**9.97 MiB**
   这说明 one-shot `apply-all` 的 userspace 内存是“按当前最大工作集复用”，不是“处理过的程序越多就越涨”。

## 2. 数据源与口径

- 代码路径：
  - `daemon/src/commands.rs`
  - `daemon/src/bpf.rs`
  - `daemon/src/invalidation.rs`
  - `daemon/src/server.rs`
  - `vendor/linux-framework/kernel/bpf/syscall.c`
- 时间基线：
  - `docs/tmp/20260326/recompile_overhead_analysis_20260326.md`
- corpus 静态规模：
  - `docs/tmp/20260326/corpus_call_statistics_20260326.json`
- YAML v2 总程序数背景：
  - `docs/kernel-jit-optimization-plan.md` 中 #506、#492、#493
- static verify 的代表性说明：
  - 当前 `daemon/tests/results/static_verify.json` 已被后续单程序 probe 覆盖，只剩 **1 条记录**，`insn_count_before` 平均值只有 **36**，不能代表 corpus。
  - 仓库中保留的完整 micro static verify 工件是：
    - `docs/tmp/20260324/static_verify.full_micro.json`
    - `docs/tmp/20260326/probe_outputs/static_verify_micro_20260326.json`
  - 这两个文件都覆盖 **62 个程序**，`insn_count_before` 平均值都是 **635**，更适合当“典型已验证程序规模”的参考值。

## 3. #492 可扩展性分析

### 3.1 `apply-all` 的代码路径

`cmd_apply_all()` 的核心逻辑非常直接：

1. `bpf::iter_prog_ids()` 通过 `BPF_PROG_GET_NEXT_ID` 顺序枚举所有 live prog ID。
2. 对每个 `prog_id` 调一次 `try_apply_one()`。
3. `try_apply_one()` 内部主要做：
   - `BPF_PROG_GET_FD_BY_ID`
   - 两次 `BPF_OBJ_GET_INFO_BY_FD` 取 `orig_prog_insns`
   - 两次 `BPF_OBJ_GET_INFO_BY_FD` 取 `map_ids`
   - userspace pass pipeline
   - 必要时打开 map FD 做 relocation
   - 一次 `BPF_PROG_REJIT`
4. 完成后进入下一个 prog。

结论：

- 对程序数量 `N` 而言，这是一个**单层 for-loop**。
- 对每个程序，工作量主要与该程序自己的 `insn_cnt`、map 引用数、verifier/JIT 成本有关。
- 因此总复杂度是：
  - **程序数维度：O(N)**
  - **程序大小维度：Σ O(size_i)**

### 3.2 哪些东西线性增长，哪些不是

线性项：

- `BPF_PROG_GET_NEXT_ID` 枚举：每个 live prog 至少 1 次 syscall。
- `try_apply_one()` 调用次数：每个 prog 1 次。
- userspace bytecode clone / pass 扫描：近似与 `insn_cnt` 线性相关。
- kernel verifier/JIT：近似与 `insn_cnt` 线性相关。
- CLI `apply-all` 的 debug JSON 输出：`emit_debug_result()` 对每个 prog 序列化一次，属于 **O(N)** 的附加 I/O 成本。

非二次项：

- 没有“对每个 prog 再扫一次全体 prog”的嵌套循环。
- 没有全局 pairwise 比较。
- 没有任何与 `N^2` 成比例的数据结构操作。

唯一需要额外指出的“比纯 O(N) 稍差”的地方在 `watch`/`serve` 的 invalidation 路径，而不是 `apply-all`：

- `MapInvalidationTracker::check_all()` 先把 entries 按 `map_fd` 和 `key` 放进 `BTreeMap/BTreeSet`，再逐项比对。
- 这条路径更准确地说是 **O(E log E + U)**：
  - `E` = tracked inline sites 数
  - `U` = 去重后的 `(map_fd, key)` 数
- 另外需要注意：当前 `BpfMapValueReader::lookup_values_batch()` 虽然接口名叫 batch，但生产实现仍是“**每个 key 一次 `BPF_MAP_LOOKUP_ELEM`**”，所以 watch-mode invalidation 的 syscall 数量也是 **O(U)**。
- 仍然**不是 O(E^2)**。

### 3.3 时间基线：per-program cost

现有时间分解里，最适合做 reviewer 回答的是 `recompile_overhead_analysis_20260326.md` 中 applied-only micro 中位数：

| 组成部分 | 中位数 |
| --- | ---: |
| daemon pipeline | 1.994 ms/prog |
| kernel REJIT syscall | 13.358 ms/prog |
| 合计 | 15.352 ms/prog |

这和 reviewer 口径里的“**daemon ~2 ms/prog，kernel ~13 ms/prog，合计 ~15 ms/prog**”一致。

### 3.4 外推：100 / 500 / 1000 / 5000 programs

按精确中位数 1.994 ms + 13.358 ms 外推：

| live programs | daemon pipeline | kernel REJIT | 总计 one-shot apply-all |
| ---: | ---: | ---: | ---: |
| 100 | 0.199 s | 1.336 s | 1.535 s |
| 500 | 0.997 s | 6.679 s | 7.676 s |
| 1000 | 1.994 s | 13.358 s | 15.352 s |
| 5000 | 9.970 s | 66.790 s | 76.760 s |

按更粗的 reviewer 近似值 2 ms + 13 ms：

| live programs | daemon pipeline | kernel REJIT | 总计 one-shot apply-all |
| ---: | ---: | ---: | ---: |
| 100 | 0.2 s | 1.3 s | 1.5 s |
| 500 | 1.0 s | 6.5 s | 7.5 s |
| 1000 | 2.0 s | 13.0 s | 15.0 s |
| 5000 | 10.0 s | 65.0 s | 75.0 s |

### 3.5 一次真实 `apply-all` sanity run

为了验证上面的线性推断没有离谱，我在 VM 里做了一次真实 one-shot `apply-all`：

- 先用 `bpftool prog loadall` 加载 `micro/programs/*.bpf.o`
- 成功加载：**62 objects / 62 live programs**
- 然后运行真实 CLI：`bpfrejit-daemon apply-all`

结果：

| 指标 | 数值 |
| --- | ---: |
| scanned programs | 62 |
| applied programs | 55 |
| 总 wall time | 579 ms |
| 平均到 scanned prog | 9.34 ms/prog |
| 平均到 applied prog | 10.53 ms/prog |

这个数字比 15.352 ms/prog 更低，不矛盾，原因有两个：

1. micro 套件本身比真实 tracee/tetragon/corpus 大程序更轻。
2. 62 个程序里有 **7 个 no-op**，它们不会走完整的成功 REJIT 成本。

因此我更建议 reviewer 主文中使用**保守外推值**（15 s / 1000 progs），把这个 579 ms sample 当作“线性模型的 sanity check”。

### 3.6 `watch` 模式为什么是增量的

`cmd_watch()` 里有三组集合：

- `optimized`: 已成功优化过，不再重试
- `no_op`: 证明无变换收益，不再重试
- `fail_count`: 最多重试 3 次

因此每轮虽然仍会 `iter_prog_ids()` 扫一遍 live 集合，但真正进入 `try_apply_one()` 的只是不在这几类集合里的候选 prog。稳态下：

- 新 prog 出现：才有新增 REJIT 开销
- 既有 prog 无变化：只剩枚举成本
- map inline invalidation 命中：只重编译被命中的 prog

所以 reviewer 可以把 `watch` 理解成：

- **枚举成本：O(N)**
- **重编译成本：O(new + invalidated)**
而不是“每轮重跑一次全量 apply-all”。

## 4. #493 内存开销分析

### 4.1 kernel 持久开销：`orig_prog_insns`

在 program load 和 REJIT 路径里，kernel 都会保存一份原始 BPF 字节码：

- 初始 load：`prog->aux->orig_insns = kvmemdup(prog->insns, ...)`
- REJIT tmp prog：`tmp->aux->orig_insns = kvmemdup(tmp->insns, ...)`
- swap 时：`bpf_prog_rejit_swap()` 交换 `orig_insns` / `orig_prog_len`

因此一个 live prog 的**持久**额外内存可以近似写成：

`persistent_kernel_overhead_per_prog = sizeof(struct bpf_insn) * insn_cnt = 8 * insn_cnt`

典型量级：

| 口径 | 平均/范围 | 折算内存 |
| --- | ---: | ---: |
| 当前 `daemon/tests/results/static_verify.json` | 36 insns | 288 B |
| 完整 micro static verify 平均值 | 635 insns | 5,080 B = 4.96 KiB |
| corpus 平均值（2019 programs） | 662.8 insns | 5,302 B = 5.18 KiB |
| corpus 中位数 | 31 insns | 248 B |
| corpus P95 | 3830 insns | 30,640 B = 29.92 KiB |
| corpus 最大值 | 23,706 insns | 189,648 B = 185.20 KiB |

这里最重要的观察是：**分布很重尾**。

- 中位数只有 **31 insns**
- 但平均值达到 **662.8 insns**

这说明 corpus 里有大量很小的 BCC/selftest 样式程序，同时也有少量非常大的 tracee / KubeArmor / tetragon 程序把均值拉高。

### 4.2 2019 个 corpus 程序的总 kernel 持久开销

我直接对 `docs/tmp/20260326/corpus_call_statistics_20260326.json` 中 `objects[*].programs[*].insn_count` 求和：

- 程序总数：**2019**
- `insn_count` 总和：**1,338,109**
- 按 `8 * insn_count` 换算：
  - **10,704,872 B**
  - **10,454.0 KiB**
  - **10.21 MiB**

按项目看，贡献最大的几类是：

| 项目 | programs | insn_count 总和 | `orig_prog_insns` 总内存 |
| --- | ---: | ---: | ---: |
| tracee | 170 | 436,205 | 3.33 MiB |
| KubeArmor | 63 | 342,444 | 2.61 MiB |
| tetragon | 90 | 172,508 | 1.32 MiB |
| calico | 59 | 158,995 | 1.21 MiB |
| loxilb | 18 | 77,314 | 0.59 MiB |

这说明 reviewer 如果问“2019 个程序会不会把内核内存压爆”，答案是否定的：
**单看持久保存的原始字节码，总量也只有约 10.2 MiB。**

### 4.3 kernel 瞬时开销：`tmp prog`

REJIT 时 kernel 还会为当前正在重编译的程序临时分配一个 `tmp`：

- `tmp->insns`
- `tmp->aux->orig_insns`
- verifier/JIT 元数据
- 新 JIT image

但这个开销是**串行一次只存在一个**的：

- `apply-all` 不是并发 REJIT
- 成功后 `tmp` 会被 `__bpf_prog_put_noref(tmp, ...)` 释放

因此：

- 瞬时 tmp prog 开销的数量级是 **O(max_prog_size)**
- 不是 “N 个程序就堆 N 份 tmp prog”

用 corpus 最大程序估算，仅 raw BPF bytes 这一项：

| 组成 | 估算 |
| --- | ---: |
| `tmp->insns` | 185.20 KiB |
| `tmp->aux->orig_insns` | 185.20 KiB |
| 两者合计 | 370.40 KiB |

再加上 JIT image、verifier aux、BTF/func_info 等元数据，瞬时峰值还会更高，但依然是“**由最大单程序决定**”，不是“**随程序总数线性累积**”。

### 4.4 daemon 侧内存

#### 4.4.1 one-shot `apply-all`

one-shot CLI `apply-all` 里没有长期 invalidation tracker：

- `cmd_apply_all()` 直接调用 `try_apply_one(..., None)`
- 所以 tracker memory 不在这条路径里

它的 userspace 峰值主要来自：

- `orig_insns.clone()`
- 当前 pass pipeline 的临时 IR / analysis
- map relocation 的 `map_ids` / `OwnedFd`
- REJIT 请求缓冲
- JSON 序列化输出的临时对象

这些对象在每个 prog 结束后都会释放或复用，因此峰值更像：

`daemon_peak_rss_apply_all ~= baseline + current_largest_working_set`

而不是：

`baseline + sum(all_programs)`

#### 4.4.2 serve/watch 的 invalidation tracker

`MapInvalidationTracker` 的主 entry 是：

```rust
pub struct TrackedInlineSite {
    pub prog_id: u32,
    pub map_fd: u32,
    pub key: Vec<u8>,
    pub expected_value: Vec<u8>,
}
```

在本机 64-bit layout 下，我用 `size_of::<TrackedInlineSite>()` 实测得到：

- `TrackedInlineSite`: **56 B**
- `Vec<u8>`: **24 B**

因此一个 site 的总内存大致是：

- 结构体本体：**56 B**
- `key` 数据区：`key_size`
- `expected_value` 数据区：`value_size`

如果按最常见的 4-byte key + 4-byte value 估算：

- **56 + 4 + 4 = 64 B/site**

这和 reviewer 草算的“~64 bytes per inlined site”一致。

所以：

| 场景 | 估算 |
| --- | ---: |
| 1000 programs × 10 sites | 640,000 B = 625.0 KiB |
| 2019 programs × 10 sites | 1,292,160 B = 1.23 MiB |
| 5000 programs × 10 sites | 3,200,000 B = 3.05 MiB |

说明 tracker 也是一个**可控的线性项**，不是大头。

### 4.5 daemon RSS 实测

VM 中的真实 one-shot `apply-all` 样本：

- live programs：**62**
- `apply-all` wall time：**579 ms**
- daemon RSS 采样：
  - `VmRSS min`: **2144 KiB**
  - `VmRSS median`: **4440 KiB**
  - `VmRSS max`: **9972 KiB**
  - `VmHWM max`: **9972 KiB**
  - `VmSize max`: **12368 KiB**

解读：

1. 峰值 RSS 只有 **~9.7 MiB**，远低于“随 62 个程序线性堆叠”的量级。
2. 这与代码路径一致：`apply-all` 是串行处理，每轮只保留当前 prog 的工作集。
3. 这个样本不包含 serve/watch 的 tracker，因此它回答的是“**one-shot apply-all 的 RSS**”，不是“长驻 daemon + tracker 的总 RSS”。

## 5. Reviewer 可直接引用的回答

### 5.1 Scalability (#492)

- `apply-all` 是顺序遍历 live BPF programs 的 one-shot pass，主路径是 **O(N)**。
- 现有数据表明 userspace pipeline 约 **2 ms/prog**，kernel REJIT 约 **13 ms/prog**，所以总计约 **15 ms/prog**。
- 外推后：
  - **100 progs ≈ 1.5 s**
  - **500 progs ≈ 7.5 s**
  - **1000 progs ≈ 15 s**
  - **5000 progs ≈ 75 s**
- `watch` 模式是增量的。它仍会 O(N) 扫描 prog IDs，但只对**新程序**和**被 invalidation 命中的程序**做重编译，不会每轮重跑一次全量 `apply-all`。
- 当前实现里没有 program-count 相关的 O(N^2) 瓶颈。最接近“非纯线性”的部分是 invalidation tracker 的 `BTreeMap/BTreeSet` 去重，复杂度是 **O(E log E)**，不是 O(E^2)。

### 5.2 Memory overhead (#493)

- kernel 的**持久**额外内存主要是每个 prog 保存一份 `orig_prog_insns`，即 **`8 * insn_cnt` 字节/prog**。
- 对整个 **2019-program corpus**，这项总计只有 **10.21 MiB**。
- REJIT 期间确实还会临时创建 `tmp prog`，但这是**一次一个**的瞬时开销，峰值由**最大单程序**决定，而不是随 `N` 线性累积。
- daemon 侧 one-shot `apply-all` 的 RSS 在 62-program VM 样本里峰值只有 **9.97 MiB**，说明 userspace 工作集是复用的，不会“处理过的程序越多就一直涨”。
- serve/watch 的 tracker 也是线性项。按 **~64 B/site** 粗估，**1000 programs × 10 inline sites** 约 **625 KiB**，量级也很小。

## 6. 一句话结论

如果 reviewer 的核心担心是“BpfReJIT 在几百到几千个 live 程序时会不会失控”，当前证据支持的回答是：

- **时间上是线性的**，1000 个程序的一次性 `apply-all` 大约 **15 秒**；
- **内存上是温和的**，2019 个程序保存原始字节码也只有 **约 10.2 MiB**，tmp prog 只是瞬时峰值，daemon RSS 也没有表现出按程序数持续累积。
