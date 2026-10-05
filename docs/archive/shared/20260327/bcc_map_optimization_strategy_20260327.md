# BCC libbpf-tools map 优化策略报告

日期：2026-03-27

## 结论摘要

1. 当前 daemon 的 `const_prop` 不会处理 `.rodata/.bss/.data` 这类 `BPF_PSEUDO_MAP_VALUE` 读取；它把 typed `LD_IMM64` 明确当作 non-foldable 值处理。
2. 我没有把“读 live map 值并改写 load”塞进 `const_prop`，而是扩展了 `map_inline`：新增一条 Pattern A 路径，专门把 frozen pseudo-map-value 基址上的 fixed-offset scalar load 改写成常量装载。
3. 为了让 real fixture 和 corpus 统计真正看见这类站点，我同时扩展了 ELF parser，使其识别 `.rodata/.data/.bss/.kconfig` section 的 relocation，并将其解析成 synthetic global-data map + `BPF_PSEUDO_MAP_VALUE` relocation。
4. 对前 20 个 BCC `libbpf-tools/*.bpf.o` 的统计显示，Pattern A 明显是主覆盖面：
   - `BPF_PSEUDO_MAP_VALUE` 全局数据读取：169 个
   - 其中 `.rodata`：151 个，`.bss`：18 个，`.data/.kconfig`：0 个
   - `bpf_map_lookup_elem`：38 个
   - 这 38 个 helper lookup 中：`HASH/LRU_HASH=37`，`PERCPU*=1`，`ARRAY=0`
   - constant-key helper lookup：0，dynamic-key helper lookup：38
5. 因此，BCC 在这个 slice 上几乎不可能从“helper lookup inlining”受益，但可以直接从 `.rodata` 常量化受益。
6. Pattern C（`PERCPU_ARRAY key=0` scratch buffer -> stack）在前 20 个对象上没有候选站点；从工程复杂度和当前覆盖面看，不值得优先做。

## 1. 前 20 个 BCC 对象的 pattern 分布

对象集合：`corpus/build/bcc/libbpf-tools` 中按文件名排序的前 20 个 `*.bpf.o`（排除 `*.tmp.o`）。

逐对象统计：

| object | pseudo-map-value loads | lookup calls | constant-key lookups |
| --- | ---: | ---: | ---: |
| `bashreadline.bpf.o` | 0 | 0 | 0 |
| `bindsnoop.bpf.o` | 6 | 0 | 0 |
| `biolatency.bpf.o` | 0 | 0 | 0 |
| `biopattern.bpf.o` | 2 | 2 | 0 |
| `biosnoop.bpf.o` | 16 | 6 | 0 |
| `biostacks.bpf.o` | 8 | 7 | 0 |
| `biotop.bpf.o` | 6 | 12 | 0 |
| `bitesize.bpf.o` | 0 | 0 | 0 |
| `cachestat.bpf.o` | 13 | 0 | 0 |
| `capable.bpf.o` | 8 | 2 | 0 |
| `cpudist.bpf.o` | 0 | 0 | 0 |
| `cpufreq.bpf.o` | 5 | 2 | 0 |
| `drsnoop.bpf.o` | 10 | 2 | 0 |
| `execsnoop.bpf.o` | 64 | 2 | 0 |
| `exitsnoop.bpf.o` | 4 | 0 | 0 |
| `filelife.bpf.o` | 5 | 3 | 0 |
| `filetop.bpf.o` | 0 | 0 | 0 |
| `fsdist.bpf.o` | 10 | 0 | 0 |
| `fsslower.bpf.o` | 8 | 0 | 0 |
| `funclatency.bpf.o` | 4 | 0 | 0 |

总计：

| metric | count |
| --- | ---: |
| `BPF_PSEUDO_MAP_VALUE` global-data loads | 169 |
| `.rodata` loads | 151 |
| `.bss` loads | 18 |
| `.data` loads | 0 |
| `.kconfig` loads | 0 |
| `bpf_map_lookup_elem` calls | 38 |
| array lookups | 0 |
| hash/lru-hash lookups | 37 |
| percpu lookups | 1 |
| other lookup types | 0 |
| constant-key lookups | 0 |
| dynamic-key lookups | 38 |

解读：

- 这批对象里，Pattern A 的规模是 helper lookup 的约 4.4 倍。
- helper lookup 基本全是 HASH + dynamic key，和背景假设一致。
- 前 20 个对象里没有看到 Pattern C 所需的 “ARRAY/PERCPU_ARRAY + constant key” helper lookup。

## 2. Pattern A：`.rodata` / global-data 读取常量化

### 2.1 现状分析

当前 `const_prop` 不会处理：

```c
LD_IMM64 rX, BPF_PSEUDO_MAP_VALUE
LDX_MEM  rY, [rX + off]
```

原因不是缺少分支折叠，而是它根本不知道这个内存读对应的 live map 值；typed `LD_IMM64` 也被显式视为 non-foldable。

### 2.2 采用的实现方式

我选择扩展 `map_inline`，而不是扩展 `const_prop` 本身。理由：

- `const_prop` 的职责是纯寄存器常量传播，不适合直接做 live map 读取。
- `map_inline` 已经具备：
  - live map value 读取路径
  - `old_fd -> map_id` 绑定
  - 固定偏移 scalar load 改写成常量装载的基础设施
- Pattern A 本质上也是 “map-backed constant materialization”。

实现点：

1. ELF parser 现在会把 `.rodata/.data/.bss/.kconfig` section relocation 识别成 synthetic global-data map，并强制标成 `BPF_PSEUDO_MAP_VALUE`。
2. `map_inline` 新增 direct pseudo-map-value rewrite：
   - 扫描所有 `LDX_MEM`
   - 反向解析其 base reg 是否可归约到 `BPF_PSEUDO_MAP_VALUE + constant offset`
   - 用 `old_fd -> map_id` 找到 live map
   - 只对 frozen map 生效
   - 用 key=`0` 读取 map value
   - 将 fixed-offset scalar load 改写为 `MOV_IMM` 或 `LD_IMM64`
3. 原始 pseudo-map-value 基址装载不会被删掉；这让 rewrite 更保守，避免引入新的 verifier 风险。
4. 改写后的分支折叠交给现有 `const_prop + dce` 完成。

### 2.3 当前实现能覆盖的形态

- 直接 `LDX_MEM` from pseudo-map-value base
- 经过 `MOV` alias 的 base
- 经过 constant `ADD/SUB` 调整过偏移的 base
- `B/H/W/DW` fixed-offset scalar load

### 2.4 当前实现刻意不做的事

- 不对 mutable `.data/.bss` 做常量化
- 不删除 pseudo-map-value `LD_IMM64` 本身
- 不做任意内存形态重写，只做 fixed-offset scalar load

### 2.5 实际效果

新增/更新的测试覆盖了三类事实：

1. frozen pseudo-map-value load 会被 `map_inline` 直接常量化
2. mutable pseudo-map-value load 会被跳过
3. 经过 `map_inline -> const_prop -> dce` 后，条件分支会被折叠并清理 dead path

另外，真实 BCC fixture `bindsnoop.bpf.o:kprobe/inet_bind` 现在在测试里稳定命中 `map_inline`，观察到 3 个 `.rodata` load site 被 constantize。

## 3. Pattern B：HASH + dynamic key lookup

对前 20 个对象，这仍然是所有 helper lookup 的主形态：38 个 lookup 里 37 个是 HASH/LRU_HASH，且 38/38 都是 dynamic key。

这类站点从架构上就不是现有 `map_inline` 的目标：

- key 不是编译期常量
- lookup 成败和值都依赖运行时 map state
- helper/null-check 消除不成立

结论：继续跳过是对的。

## 4. Pattern C：`PERCPU_ARRAY key=0` scratch buffer -> stack

### 4.1 在本次统计 slice 上的观察

前 20 个 BCC 对象里：

- `ARRAY` helper lookup：0
- `PERCPU*` helper lookup：1
- constant-key helper lookup：0

也就是说，这个 slice 上没有 Pattern C 候选。

### 4.2 可行性判断

方向本身不是完全不可做，但它和 Pattern A 不是一个难度级别。要把 scratch map lookup 安全替换成 stack buffer，至少要解决：

1. value size 必须受限，且要和 BPF stack budget 兼容
2. 必须证明指针只在当前 invocation 内使用，不能逃逸到需要 map-value provenance 的地方
3. 必须重写所有后续写入/读取/helper 传参，不能只删 helper call
4. verifier-visible pointer kind 会从 `PTR_TO_MAP_VALUE` 变成 `PTR_TO_STACK`
5. 还要考虑 alignment、subprog 传递、helper side effect、以及原 map 作为“per-CPU reusable scratch slot”的语义差异

### 4.3 优先级判断

基于这次 BCC top-20 统计，它不值得优先做：

- 当前覆盖面基本为 0
- 实现复杂度显著高于 Pattern A
- 即使做出来，也不是这批对象的主要收益来源

结论：先不做。

## 5. 预期影响评估

对 BCC libbpf-tools，这次最现实的收益路径是：

```text
frozen .rodata load
  -> map_inline constantize
  -> const_prop branch fold
  -> dce remove dead arm
```

从 top-20 统计看：

- 直接 helper lookup 优化几乎没有空间
- `.rodata/.bss` pseudo-map-value 读取则非常密集
- 其中很多都是配置过滤位、pid/tgid 过滤、开关位判断

因此我预期：

1. 对 BCC 的收益主要来自配置读取常量化，而不是 helper lookup 消除
2. 最容易受益的是 `bindsnoop/execsnoop/biosnoop/cachestat/drsnoop` 这类 heavily gated tracing tool
3. 对最终 code size/branch count 的提升，会高度依赖这些开关常量是否位于 branch condition 的支配路径上

## 6. 验证

已执行：

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
make daemon
```

结果：

- `cargo test`：`540 passed, 0 failed, 13 ignored`
- `make daemon`：成功

用于统计的额外命令：

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml \
  dump_bcc_top20_pattern_stats -- --ignored --nocapture
```

## 7. 代码改动摘要

- `daemon/src/elf_parser.rs`
  - 新增 global-data section relocation 识别
  - synthetic `.rodata/.data/.bss/.kconfig` map 建模
- `daemon/src/passes/map_inline.rs`
  - 新增 frozen pseudo-map-value scalar load constantization
  - 新增对应单测和 BCC top-20 统计辅助测试（ignored）
- `daemon/src/passes/mod.rs`
  - 更新 `map_inline` 描述文字
- `daemon/src/analysis/map_info.rs`
  - 小幅清理一个无意义 `mut`

## 8. 手工 VM 验证：`execsnoop` + `stress-ng --exec`

为了避开 `corpus` / `e2e` / `micro_exec` / `bpftool` 基础设施，我额外做了一次纯手工链路验证：

- 入口：`make vm-shell`
- guest 内直接运行：
  - `daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit.sock`
  - `runner/repos/bcc/libbpf-tools/execsnoop -T -U -u 65534`
  - `stress-ng --exec 2 --exec-method execve --timeout {3,5} --metrics-brief`
- optimize 请求走 daemon Unix socket，且只启用：
  - `["map_inline", "const_prop", "dce"]`

说明：

- `stress-ng --exec` 在 guest 里不能直接以 root 运行；需要：
  - `setpriv --reuid 65534 --regid 65534 --clear-groups`
- 之所以选 `execsnoop -u 65534`，是为了：
  - 用非 root UID 跑 `stress-ng --exec`
  - 把 `execsnoop` 输出噪音压到最低
  - 让 UID/filter 相关 `.rodata` 常量化更容易命中

这次手工验证里，`execsnoop` 启动后新增了两个 live program：

| prog_id | prog_type | insns(before) | site summary |
| --- | ---: | ---: | --- |
| `7` | `5` | `2236` | `map_inline=63 const_prop=182 dce=1490` |
| `9` | `5` | `64` | `map_inline=4 const_prop=3 dce=8` |

daemon socket optimize 结果：

| requested prog_id | orig insns | final insns | delta | map_inline | const_prop | dce |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `7` | `2236` | `806` | `-1430` | `63` | `182` | `1490` |
| `9` | `64` | `56` | `-8` | `4` | `3` | `8` |

几点观察：

1. 这条链路完全不依赖 `micro_exec`，也没有用 `bpftool`；`execsnoop` 是按 BCC `libbpf-tools` 自己的正常加载方式运行的。
2. `map_inline` 在主 tracepoint program 上命中了 `63` 个 site；从 daemon debug log 看，命中的都是 `BPF_PSEUDO_MAP_VALUE` / global-data constantization，而不是 helper lookup inline。
3. optimize 后 live enumerate 中相同 program id 的指令数已经变成：
   - `2236 -> 806`
   - `64 -> 56`
4. `execsnoop` 在 optimize 后仍持续产生日志：
   - optimize 前样本行数：`349`
   - optimize 后再跑一轮 `stress-ng --exec` 后：`898`
   - 新增事件行数：`549`
5. 两轮 `stress-ng` 都稳定跑通：
   - 3 秒轮次：`623` exec bogo ops
   - 5 秒轮次：`988` exec bogo ops

结论：

- `execsnoop + stress-ng --exec` 是一个比 `bindsnoop` 更容易手工复现、也更容易稳定看到 `map_inline` 效果的 BCC 验证路径。
- 对这个工具，收益的主来源确实是 `.rodata` / global-data constantization，再由 `const_prop + dce` 折叠过滤分支并删掉 dead code。

## 9. 手工 VM 性能采样：`execsnoop` stock vs optimized

为了回答“有没有 end-to-end 性能收益”，我又在同一条 VM 手工路径上做了一轮交错采样：

- 入口：`make vm-shell`
- 脚本：[execsnoop_perf_vm_20260327.sh](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260327/execsnoop_perf_vm_20260327.sh)
- 每轮顺序：
  1. `no_trace`
  2. `stock execsnoop`
  3. `optimized execsnoop`
- 每个 case 都跑：
  - `setpriv --reuid 65534 --regid 65534 --clear-groups`
  - `stress-ng --exec 2 --exec-method execve --timeout 10 --metrics-brief`
- `optimized` case 仍只启用：
  - `["map_inline", "const_prop", "dce"]`

采样结果使用 `stress-ng` 的 `bogo ops/s (real time)` 作为吞吐指标。

全 5 轮均值：

| mode | mean bogo ops/s | stdev |
| --- | ---: | ---: |
| `no_trace` | `172.08` | `12.30` |
| `stock` | `170.96` | `20.46` |
| `optimized` | `181.38` | `4.34` |

按这个全样本均值算：

- `optimized vs stock`: `+6.10%`

但这里要非常小心：`stock` 的第 1 轮是明显冷启动低点：

- `stock round1`: `135.74`
- `optimized round1`: `175.17`

如果把第 1 轮当暖机剔除，只看第 2-5 轮稳态均值：

| mode | steady-state mean bogo ops/s |
| --- | ---: |
| `no_trace` | `174.61` |
| `stock` | `179.76` |
| `optimized` | `182.93` |

这时：

- `optimized vs stock`: 约 `+1.76%`

解读：

1. `execsnoop` 的 live program 确实被大幅瘦身了：
   - 主程序 `2236 -> 806` insns
   - 次程序 `64 -> 56` insns
2. 但在这个 `stress-ng --exec` 压测里，end-to-end 吞吐提升没有 code size 降幅那么夸张。
3. 更保守、也更可信的说法是：
   - `steady-state` 下看到的是“小幅提升”，量级大约 `1-2%`
   - 不能把这轮数据解读成稳定的 `6%+` 提升
4. 后两轮样本里：
   - `stock`: `185.66`, `184.44`
   - `optimized`: `185.55`, `185.46`
   这也说明 steady-state 优势并不大，至少在当前 workload 上接近噪音边界。

结论：

- 对 `execsnoop`，`map_inline + const_prop + dce` 的收益在“代码体积 / dead branch 删除”上非常明显。
- 但对 `stress-ng --exec` 这个 end-to-end 压测，当前只看到“小幅或接近噪音边界”的吞吐改善，还不能宣称有很强的性能提升。

## 最终建议

1. 保留当前 Pattern A 实现，并把它视为 BCC 的主 map 优化入口。
2. 不要把精力放在 BCC 的 helper lookup inline 上；统计已经说明这条路覆盖面很小。
3. Pattern C 先不做，除非后续更大范围 census 证明 constant-key scratch lookup 在 BCC corpus 里显著存在。
