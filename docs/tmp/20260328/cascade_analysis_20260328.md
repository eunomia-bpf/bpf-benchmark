# map_inline -> const_prop -> dce 级联分析（2026-03-28）

## 0. 结论先行

这条级联在真实程序上并不是“根本没发生”，而是经常只发生到一半：

1. `map_inline` 经常确实命中，但很多命中只是把 `*(value + off)` 改成常量，不会把 `bpf_map_lookup_elem()` helper 和 null-check 一起拿掉。
2. `const_prop` 也确实继续工作了，但它大多只能把局部寄存器算术折叠掉，或者把条件跳转折成 `JA 0` / `NOP`，很少形成大块 CFG collapse。
3. `dce` 目前非常弱，只会删不可达块和 `NOP`，不会删“仍然可达但结果已无用”的寄存器定义、helper 参数准备、dead store，也不会做跨 subprog 的清理。
4. `HASH/LRU_HASH` 的 v1 设计是按构造就“不删 lookup”的：它只做 speculative value-load replacement。于是最贵的那部分路径没有被打掉，这正是 applied-only geomean 只有 `0.995307457x` 的核心原因之一。

所以论文 story 里的“map value 内联成常量 -> const_prop 把整个条件分支打平 -> dce 把整条路径删掉”在机制上是成立的，但在 2026-03-28 这批 corpus 里，真正长成这个形状的程序不多；大部分命中更像“常量替换 + 局部折叠 + 删 1-2 个 NOP”。

## 1. 数据源与方法

### 1.1 本次分析对应的真实 corpus run

- headline 对应的是 2026-03-28 的 partial dev run：
  - `runner/corpus/results/vm_corpus_20260328_194356/metadata.json`
  - 原始 batch 结果：`docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json`
- 我重新计算得到：
  - numeric comparable programs: `255`
  - 其中 `applied_passes` 非空: `170`
  - overall exec geomean: `0.980326755x`
  - applied-only exec geomean: `0.995307457x`
  - non-applied-only exec geomean: `0.951038396x`

### 1.2 一个重要限制

这次 raw batch JSON 只保留了 program-level summary，没有保存：

- per-pass `debug_traces`
- pass 前后 bytecode dump
- `map_inline` 的 site-level 详细记录

我确认过：

- `runner/corpus/results/vm_corpus_20260328_194356/` 只有 `metadata.json`
- `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-l3_nwgyk.json` 里没有 `debug_traces` / `pass_results`
- 同目录的 stdout log 里也没有可用的 `map_inline` / `const_prop` / `dce` debug trace

因此下面的 bytecode 链路分析采用了**离线重放**：

- 对同一批 `.bpf.o` 重新跑 `map_inline` / `const_prop` / `dce`
- 产物在：
  - [`docs/tmp/20260328/cascade_inspect_output`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output)
  - 复现工具在：
    - [`docs/tmp/20260328/cascade_inspect_tool/src/lib.rs`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_tool/src/lib.rs)

### 1.3 离线重放的 map 值来源

这点必须说明白：

- `katran_xdp_pktcntr_xdp`
- `katran_balancer_xdp`
- `bindsnoop_kprobe_inet_bind`

这 3 个案例用的是 **deterministic synthetic frozen maps**，不是 2026-03-28 真实 runtime map 值。

对应逻辑在：

- [`daemon/src/test_utils.rs:37-53`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/test_utils.rs#L37)
- [`daemon/src/test_utils.rs:335-390`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/test_utils.rs#L335)

这意味着：

- “inline 了什么具体常量值”这件事，对这 3 个案例来说是**离线重放值**
- 但 “命中的是哪类 site、helper 是否保留、后续常量传播有没有继续、为什么 DCE 没把路径删掉” 这些**结构性结论**不依赖具体 value，仍然有效

另外我补了 1 个真实 captured fixture：

- `tracee:sys_enter_submit`
- 用的是捕获下来的 map 内容，而不是 synthetic map
- capture 在：
  - [`corpus/fixtures/tracee/tracee.bpf.o/sys_enter_submit.json`](/home/yunwei37/workspace/bpf-benchmark/corpus/fixtures/tracee/tracee.bpf.o/sys_enter_submit.json)

## 2. 先看代码：这条级联现在到底能做什么

### 2.1 pass 顺序没有问题，`const_prop` + `dce` 也已经做 fixed-point

- canonical pipeline 顺序是：
  - `map_inline`
  - `const_prop`
  - `dce`
- 代码位置：
  - [`daemon/src/passes/mod.rs:52-67`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs#L52)
- 而且 `const_prop` 与 `dce` 不是只跑一轮，它们会成对 fixed-point 最多 5 轮：
  - [`daemon/src/pass.rs:684`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/pass.rs#L684)
  - [`daemon/src/pass.rs:769-809`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/pass.rs#L769)

所以问题**不是**“顺序排错了”或者“`dce` 没机会看到 `const_prop` 的结果”。

### 2.2 `map_inline` 的真实能力边界

map type capability 来自：

- [`daemon/src/analysis/map_info.rs:48-81`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/analysis/map_info.rs#L48)

当前 v1 的关键分界是：

- `supports_direct_value_access()` 支持：
  - `HASH`
  - `ARRAY`
  - `PERCPU_ARRAY`
  - `LRU_HASH`
- `can_remove_lookup_pattern_v1()` 只支持：
  - `ARRAY`
  - `PERCPU_ARRAY`
- `is_speculative_v1()` 只标记：
  - `HASH`
  - `LRU_HASH`

这意味着：

- `HASH/LRU_HASH` 可以被 inline，但只能走 speculative 路线
- `HASH/LRU_HASH` **按设计不能删掉 lookup/null-check**
- 真正能把 helper lookup pattern 整块拿掉的，只有 `ARRAY/PERCPU_ARRAY`

site 级别的 gate 在：

- [`daemon/src/passes/map_inline.rs:833-883`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L833)

主要限制有：

- key 必须可恢复为常量
- `HASH/LRU_HASH` 必须有 immediate null check
- lookup result 必须只被 fixed-offset scalar loads 消费
- mutable map 的 lookup result 不能有非 load use

即便是 `ARRAY/PERCPU_ARRAY`，也不是只要命中就删 helper。真正删 pattern 还要过两个额外安全门：

- null-check removal window 必须 trivial：
  - [`daemon/src/passes/map_inline.rs:2421-2455`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L2421)
- 被删掉的 lookup pattern 必须是“first load 之前的紧凑连续块”：
  - [`daemon/src/passes/map_inline.rs:1592-1614`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L1592)

这条 contiguous-block 要求非常重要。它直接解释了为什么不少 `ARRAY` 命中也只做 load replacement，没有把 helper 拿掉。

### 2.3 `const_prop` 并不只是 local peephole，但它的 domain 很窄

`const_prop` 的 block-entry state 是通过 CFG 数据流求出来的：

- [`daemon/src/passes/const_prop.rs:146-180`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L146)

所以：

- 它**会**跨 basic block 传播
- “`const_prop` 完全不做 inter-block 传播”这个猜测是不对的

但它只跟踪：

- `11` 个寄存器上的 `Option<u64>`
  - [`daemon/src/passes/const_prop.rs:19-24`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L19)

merge 规则也很保守：

- 两个前驱上的同一寄存器只有“常量且相等”才保留
- 否则直接变 `unknown`
- 代码在：
  - [`daemon/src/passes/const_prop.rs:466-478`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L466)

另外：

- `LDX` 一律把目的寄存器打成 unknown：
  - [`daemon/src/passes/const_prop.rs:229-231`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L229)
- helper call 会清空 `r0..r5` 的常量状态：
  - [`daemon/src/passes/const_prop.rs:239-244`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L239)

所以它的能力是：

- 能折叠常量寄存器上的算术
- 能把条件跳转折成 `JA` / `NOP`

但它**不能**：

- 跟踪 memory object 级别的不变量
- 跟踪 stack slot 的常量内存语义
- 做真正的 SSA/phi 级别稀疏 SCCP
- 跨 helper 维持 richer state

### 2.4 `dce` 目前非常弱

`dce` 的注释写得很直接：

- 只做 CFG-unreachable block removal
- 只做 `ja +0` / `nop` elimination
- dead register definition elimination 留到以后

代码位置：

- [`daemon/src/passes/dce.rs:9-16`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/dce.rs#L9)
- [`daemon/src/passes/dce.rs:39-54`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/dce.rs#L39)

所以如果 `const_prop` 只是把某个寄存器计算折成常量，但没有让整块 CFG 不可达，`dce` 是不会继续把这串计算删掉的。

## 3. 真实程序跟踪：级联到底有没有发生

下面选 3 个真实 corpus 命中程序，再加 1 个“理想 work case”。

---

## 3.1 案例 A：`katran:xdp_pktcntr.bpf.o:xdp`

### 3.1.1 这是不是 2026-03-28 corpus 里的真实命中程序？

是。

从 `corpus-rejit-vm-batch-result-l3_nwgyk.json` 里看到：

- object: `katran:xdp_pktcntr.bpf.o`
- section: `xdp`
- `applied_passes = ["map_inline", "const_prop", "dce"]`
- `speedup_ratio = 1.375`
- `size_ratio = 1.8829787234042554`

### 3.1.2 离线重放结果

产物：

- [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/summary.json)
- [`00_original.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/00_original.txt)
- [`03_after_full_pipeline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/03_after_full_pipeline.txt)

重放条件：

- synthetic maps
- `ctl_array[0]` 被重放为 `7`
- `cntrs_array[0]` 被重放为 `0`

stage 统计：

| stage | insns |
| --- | ---: |
| original | 22 |
| after `map_inline` | 22 |
| after `map_inline + const_prop` | 22 |
| after full pipeline | 21 |

pass 统计：

| pass | changed | sites_applied | before | after |
| --- | --- | ---: | ---: | ---: |
| `map_inline` | yes | 2 | 22 | 22 |
| `const_prop` | yes | 2 | 22 | 22 |
| `dce` | yes | 1 | 22 | 21 |

### 3.1.3 具体改了什么

`map_inline` 命中了两个 lookup load：

```diff
-0009: code=0x61 dst=r1 src=r0 off=0 imm=0
+0009: code=0xb4 dst=r1 src=r0 off=0 imm=7
-0017: code=0x79 dst=r1 src=r0 off=0 imm=0
+0017: code=0xb7 dst=r1 src=r0 off=0 imm=0
```

也就是：

- 第一个 map lookup 的 value load 变成常量 `7`
- 第二个 map lookup 的 value load 变成常量 `0`

接着 `const_prop` 确实继续推进：

```diff
-0010: code=0x15 dst=r1 src=r0 off=9 imm=0
+0010: code=0x05 dst=r0 src=r0 off=0 imm=0
-0018: code=0x07 dst=r1 src=r0 off=0 imm=1
+0018: code=0xb7 dst=r1 src=r0 off=0 imm=1
```

含义是：

- `if r1 == 0` 这个分支被折成了恒定跳转
- `r1 = 0; r1 += 1` 这类算术被折成了直接常量 `1`

最后 `dce` 只删掉了 1 个 `NOP`。

### 3.1.4 为什么这是“级联发生了，但收益很小”

这是一个真实发生的级联，但幅度极小：

- `map_inline` 命中
- `const_prop` 继续传播
- `dce` 也确实工作

但最终只少了 `1` 条指令。

更重要的是：**helper lookup 本身还在**。最终 bytecode 前 20 条仍然保留了两次 `bpf_map_lookup_elem#1`：

```text
0007: code=0x85 ... imm=1   ; 第一次 map_lookup_elem
0014: code=0x85 ... imm=1   ; 第二次 map_lookup_elem
```

这说明这里的 `map_inline` 实际做成的是：

- 把 lookup 结果上的 load 改成常量
- 但没有把整个 lookup pattern 删掉

为什么？从字节码形态看，我的判断是：

- 这两个 lookup 共享前面的常量零 materialization
- `ARRAY/PERCPU_ARRAY` 虽然理论上允许 remove lookup pattern
- 但 `lookup_pattern_removal_is_safe()` 要求“被删掉的 pattern 是 first load 前的紧凑连续块”
- 这里前面的 stack store / source imm 准备是交错共享的，不满足这条 gate

这点是**从字节码结构推断**，不是 log 直接打印出来的原因；但它和 [`daemon/src/passes/map_inline.rs:1592-1614`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L1592) 的实现完全一致。

结论：

- 这是 corpus 内“级联真的 work”的现实例子
- 但它只打掉了 1 个小分支，不足以撑起“大幅加速”的 story

---

## 3.2 案例 B：`bcc:libbpf-tools/bindsnoop.bpf.o:kprobe/inet_bind`

### 3.2.1 这是不是 2026-03-28 corpus 里的真实命中程序？

是。

raw batch 里：

- object: `bcc:libbpf-tools/bindsnoop.bpf.o`
- section: `kprobe/inet_bind`
- `applied_passes = ["map_inline", "const_prop", "dce"]`
- 这条记录没有 numeric `speedup_ratio`

### 3.2.2 这次命中的其实不是 `map_lookup_elem`

这是个很有代表性的反例。

这里 `map_inline` 命中的不是 helper lookup，而是 `.rodata` 的 pseudo-map-value load：

- 代码入口在：
  - [`daemon/src/passes/map_inline.rs:1330-1421`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L1330)

离线重放结果：

- [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/bindsnoop_kprobe_inet_bind/summary.json)

stage 统计：

| stage | insns |
| --- | ---: |
| original | 30 |
| after `map_inline` | 30 |
| after `map_inline + const_prop` | 30 |
| after full pipeline | 28 |

pass 统计：

| pass | changed | sites_applied | before | after |
| --- | --- | ---: | ---: | ---: |
| `map_inline` | yes | 3 | 30 | 30 |
| `const_prop` | yes | 2 | 30 | 30 |
| `dce` | yes | 2 | 30 | 28 |

### 3.2.3 具体改了什么

`map_inline` 把 3 个 `.rodata` load 常量化成 `11`：

```diff
-0003: code=0x71 dst=r1 src=r1 off=0 imm=0
+0003: code=0xb4 dst=r1 src=r0 off=0 imm=11
-0015: code=0x61 dst=r2 src=r1 off=0 imm=0
+0015: code=0xb4 dst=r2 src=r0 off=0 imm=11
-0017: code=0x61 dst=r1 src=r1 off=0 imm=0
+0017: code=0xb4 dst=r1 src=r0 off=0 imm=11
```

然后 `const_prop` 把两个分支折掉：

```diff
-0004: code=0x15 dst=r1 src=r0 off=5 imm=0
+0004: code=0x05 dst=r0 src=r0 off=0 imm=0
-0016: code=0x15 dst=r2 src=r0 off=3 imm=0
+0016: code=0x05 dst=r0 src=r0 off=0 imm=0
```

最后 `dce` 删除两个 `NOP`，`30 -> 28`。

### 3.2.4 为什么收益还是很小

因为这里虽然形成了完整级联，但它只影响两个很小的 config check：

- `.rodata` 常量被传播到了条件判断
- 条件判断被折掉
- 但被折掉的只是两条小 guard

它没有：

- 删除 helper 热路径
- 删除大块主要逻辑
- 删除任何跨 call 的准备代码

所以这类 case 对“证明级联存在”很有用，但对“解释为什么没有大幅提速”也同样有用：**因为它删掉的只是 2 个很薄的分支壳子**。

---

## 3.3 案例 C：`katran:balancer.bpf.o:xdp`

### 3.3.1 这是不是 2026-03-28 corpus 里的真实命中程序？

是，而且它正好是最关键的 `HASH` 现状样本。

raw batch 里：

- object: `katran:balancer.bpf.o`
- section: `xdp`
- `applied_passes = ["map_inline"]`
- `speedup_ratio = 0.8217821782178217`
- `size_ratio = 1.0016136130262578`

也就是说：

- 这次 run 里它只有 `map_inline` 被 summary 记为“改了代码”
- 实测还是回归的

### 3.3.2 离线重放结果

产物：

- [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/summary.json)
- [`00_original.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/00_original.txt)
- [`03_after_full_pipeline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/03_after_full_pipeline.txt)

重放条件：

- synthetic maps
- 因此 inline 的具体常量值是 synthetic 的
- 但“只替换 value load、helper/null-check 保留”的结构现象不依赖具体值

stage 统计：

| stage | insns |
| --- | ---: |
| original | 2318 |
| after `map_inline` | 2318 |
| after `map_inline + const_prop` | 2318 |
| after full pipeline | 2316 |

pass 统计：

| pass | changed | sites_applied | before | after |
| --- | --- | ---: | ---: | ---: |
| `map_inline` | yes | 44 | 2318 | 2318 |
| `const_prop` | yes | 35 | 2318 | 2318 |
| `dce` | yes | 2 | 2318 | 2316 |

这 3 行已经把问题说得很清楚了：

- `map_inline` 命中了很多
- `const_prop` 也继续改了不少点
- 但整条链最后只少了 `2` 条指令

### 3.3.3 `map_inline` 具体改了什么

在入口处，第一个 lookup 的 value load 被换成常量，但 helper 与 null-check 都还在：

原始：

```text
0011: code=0x18 ...        ; map fd
0013: code=0x85 ... imm=1  ; bpf_map_lookup_elem
0014: code=0x15 ...        ; null check
0016: code=0x79 dst=r1 src=r0 off=8
0019: code=0x79 dst=r1 src=r0 off=0
0020: code=0x07 dst=r1 src=r0 off=0 imm=1
```

最终：

```text
0011: code=0x18 ...        ; map fd 还在
0013: code=0x85 ... imm=1  ; helper 还在
0014: code=0x15 ...        ; null check 还在
0016: code=0xb7 dst=r1 ... imm=0
0019: code=0xb7 dst=r1 ... imm=0
0020: code=0xb7 dst=r1 ... imm=1
```

这个例子就是当前 `HASH/LRU_HASH` 模式的原样写照：

- lookup call 保留
- null check 保留
- 只把后面的 fixed-offset load 变成立即数

中段还有更典型的例子：6 个按字节读 value 的 load 被改成常量，但这串常量随后只是拿去拼装数据，不是拿去做控制流判断：

原始：

```text
1159: code=0x71 dst=r2 src=r6 off=0
1160: code=0x71 dst=r3 src=r6 off=1
1161: code=0x71 dst=r4 src=r6 off=2
1162: code=0x71 dst=r5 src=r6 off=3
1163: code=0x71 dst=r0 src=r6 off=4
1164: code=0x71 dst=r6 src=r6 off=5
```

最终：

```text
1159: code=0xb4 dst=r2 src=r0 off=0 imm=8
1160: code=0xb4 dst=r3 src=r0 off=0 imm=0
1161: code=0xb4 dst=r4 src=r0 off=0 imm=0
1162: code=0xb4 dst=r5 src=r0 off=0 imm=0
1163: code=0xb4 dst=r0 src=r0 off=0 imm=0
1164: code=0xb4 dst=r6 src=r0 off=0 imm=0
```

这类 rewrite 的意义是“少做若干 value load”，不是“删掉整条分支路径”。

### 3.3.4 `const_prop` 在这里为什么没能继续打平大量路径

`const_prop` 不是完全没做事。它做了很多局部折叠，例如：

```diff
-0020: code=0x07 dst=r1 src=r0 off=0 imm=1
+0020: code=0xb7 dst=r1 src=r0 off=0 imm=1
...
-1263: code=0x25 dst=r1 src=r0 off=1 imm=125000
+1263: code=0x05 dst=r0 src=r0 off=0 imm=0
...
-1799: code=0x2d dst=r2 src=r1 off=-28 imm=0
+1799: code=0x05 dst=r0 src=r0 off=-28 imm=0
```

但它没能形成大规模 collapse，主要因为：

1. 很多被 inline 出来的常量只流向了算术/打包/拷贝，而不是 dominator branch。
2. helper call 和 null-check 都还在，主控制骨架没动。
3. `const_prop` 的 domain 只看寄存器精确常量，不会把这种“对象一部分字段已知”为条件继续放大。

### 3.3.5 `map_inline` 为什么在这个程序里经常断掉

我统计了离线重放里 `map_inline` 的 skip reason：

| skip reason | count |
| --- | ---: |
| `lookup result is not consumed by fixed-offset scalar loads` | 36 |
| `lookup key is not a constant stack or pseudo-map-value materialization` | 24 |
| `map type 12 not inlineable in v1` | 2 |
| `map type 13 not inlineable in v1` | 2 |

这张表很关键。

它说明在真实大程序里，`map_inline` 不是“命中了就能继续引发级联”，而是大量 lookup 会在更早阶段就卡住：

- key 不是常量
- lookup result 的 use 不是 fixed-offset scalar load
- map type 本身不支持

### 3.3.6 这个案例对论文 story 的真正含义

这是我认为最关键的现实证据：

- 一个真实的、lookup 很多的程序
- `map_inline` 命中 `44` 次
- `const_prop` 也继续改了 `35` 个点
- 但整个链最终只删了 `2` 条指令

所以 applied-only geomean 接近 `1.0x` 不是偶然噪声，而是因为：

- 现在的 `HASH` 路线本质上只是“value load specialization”
- 不是“lookup fast-path elimination”

---

## 3.4 理想 work case：`tracee:sys_enter_submit` captured fixture

这不是来自 `vm_corpus_20260328_194356` numeric subset 的一条 raw 记录，但它是一个真实程序、真实 capture 的 map 状态，而且非常适合回答“这条级联如果真的咬住控制流，会长成什么样”。

产物：

- [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/tracee_sys_enter_submit_captured/summary.json)

stage 统计：

| stage | insns |
| --- | ---: |
| original | 3731 |
| after `map_inline` | 3731 |
| after `map_inline + const_prop` | 1640 |
| after full pipeline | 1591 |

pass 统计：

| pass | changed | sites_applied | before | after |
| --- | --- | ---: | ---: | ---: |
| `map_inline` | yes | 5 | 3731 | 3731 |
| `const_prop` | yes | 36 | 3731 | 1640 |
| `dce` | yes | 49 | 1640 | 1591 |

这里最值得注意的是：

- `map_inline` 只改了 `5` 个 site
- 但 `const_prop` 之后字节码直接 `3731 -> 1640`
- 总体删掉了 `2140` 条指令，约 `57.4%`

原始到 `map_inline` 的变化其实很小：

```diff
-0635: code=0x61 dst=r1 src=r9 off=4
+0635: code=0xb4 dst=r1 src=r0 off=0 imm=0
-0712: code=0x69 dst=r2 src=r9 off=14
+0712: code=0xb4 dst=r2 src=r0 off=0 imm=1
-0785: code=0x61 dst=r4 src=r9 off=0
+0785: code=0xb4 dst=r4 src=r0 off=0 imm=367
```

但 `map_inline -> const_prop` 的 diff 行数是：

- `5225` 行

`const_prop -> full` 的 diff 行数还有：

- `2999` 行

这说明：

- 论文 story 在机制上确实能成立
- 当 map 常量真正控制了大块 feature gating / branch skeleton 时，后续 collapse 会非常大

所以问题不是“这条链不 work”，而是“**当前 corpus 的真实命中分布，大多数不长成这种形状**”。

## 4. 回答核心问题：级联为什么断裂

### 4.1 不是 pass 顺序问题，而是 `map_inline` 结果经常不够“强”

这是第一性原因。

当前很多命中只做到：

- `rX = *(value + off)` -> `rX = CONST`

但没做到：

- 删除 helper call
- 删除 null-check
- 删除整段 key materialization / alias copy / setup

于是后面的 CFG 主骨架还在，`const_prop` 只能在骨架内部做局部折叠。

### 4.2 即便是 `ARRAY/PERCPU_ARRAY`，也经常只能做 load replacement

这点容易被忽略。

当前代码只有在 lookup pattern 是“first load 之前的紧凑连续块”时才愿意整个删掉：

- [`daemon/src/passes/map_inline.rs:1610-1613`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L1610)

现实里 clang 生成的代码经常会有：

- 共享的常量准备
- 交错的 stack store
- 多个 lookup 共享前面的 zero materialization
- lookup setup 与其他安全指令交织

于是虽然 `map_inline` 能确认 value 是常量，但仍然只敢改 load，不敢删整段 pattern。

`xdp_pktcntr` 就是这个现象的现实例子。

### 4.3 `HASH/LRU_HASH` 现在是按构造就断在 helper 之前

这是最硬的一条。

因为：

- `MapInfo::can_remove_lookup_pattern_v1()` 不包含 `HASH/LRU_HASH`
- `MapInfo::is_speculative_v1()` 只把它们标为 speculative inline

所以在 `build_site_rewrite()` 里：

- `remove_lookup_pattern = info.can_remove_lookup_pattern_v1()`
- 对 `HASH/LRU_HASH` 来说，这个值恒为 `false`

也就是说当前 `HASH` 模式的天花板就是：

- 保留 lookup
- 保留 null-check
- 把若干 value load 变成常量

这也是为什么 `katran_balancer_xdp` 明明有 `44` 个 hit，最后只删了 `2` 条指令。

### 4.4 `const_prop` 的范围比猜测里强，但 still too weak for this story

逐条回应用户列出的猜测：

#### 猜测 A：`const_prop` 不做 inter-block 传播？

不对。

它会跨 basic block 做数据流求解，见：

- [`daemon/src/passes/const_prop.rs:146-180`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L146)

#### 猜测 B：inline 的值如果用于计算而不是分支，`const_prop` 不跟踪？

部分不对。

它**会**折叠常量寄存器算术，见：

- [`daemon/src/passes/const_prop.rs:255-312`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs#L255)

但问题在于：

- 它只跟踪寄存器上的精确常量
- helper call 会打掉很多寄存器状态
- 一旦 merge 点两边常量不同，就退化成 unknown
- 它不会跟踪“某个 object 的某个字段是常量”这种 richer invariant

所以对于 `HASH` case 里常见的：

- 常量字节被读出来
- 做打包、copy、helper 参数准备
- 最后才影响复杂控制

这类链条，当前 `const_prop` 很难把它一路放大成大块 CFG collapse。

#### 猜测 C：程序结构太复杂（subprog、callback）会不会阻断？

会，但不是这 3 个案例里最主要的瓶颈。

当前 `dce` 没有 interprocedural dead code elimination；`const_prop` 也不是跨 subprog 的 SCCP。所以：

- 多个 subprog
- callback-only subprog
- pseudo-call 边界

都会削弱后续清理力度。

这更像是“第二层限制”，不是 `katran_balancer_xdp` 这类 case 的第一原因。

### 4.5 `dce` 太弱，很多“死了但还可达”的代码根本删不掉

现在的 `dce` 只能删：

- 不可达块
- `NOP`

删不掉：

- dead register definition
- 被后续 branch folding 弄成无用的 helper 参数准备
- dead store
- 仅在 subprog 内才无用的残留计算

所以当前链条常见的终局是：

1. `map_inline` 把 load 变常量
2. `const_prop` 把一条条件跳转折成 `NOP`
3. `dce` 删掉这条 `NOP`
4. 其余一大串已经“语义上变薄”的准备代码仍然留在程序里

这正是 `bindsnoop` 与 `xdp_pktcntr` 的实际样子。

## 5. HASH map inline 的现状与改进方向

### 5.1 当前 `HASH` 到底做了什么

当前 `HASH/LRU_HASH` 走的是：

- speculative inline
- 需要 immediate null check
- 保留 lookup helper
- 保留 null check
- 仅替换 lookup result 上的 fixed-offset scalar loads

限制在代码里非常明确：

- map capability：
  - [`daemon/src/analysis/map_info.rs:68-81`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/analysis/map_info.rs#L68)
- site gate：
  - [`daemon/src/passes/map_inline.rs:852-871`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L852)

### 5.2 这种 inline 的效果上限有多高

上限其实不高。

它能省掉的是：

- 若干 `ldx` / `ldxb` / `ldxh` / `ldxdw`

它省不掉的是：

- `bpf_map_lookup_elem()` helper 本身
- key materialization
- `r0 != NULL` guard
- 大多数 surrounding control flow

如果 map value 的字段只是拿来做：

- arithmetic
- packing
- helper arg construction

那 `const_prop` 最多也只是把局部计算折成常量，整体收益有限。

### 5.3 能不能做得更好

可以，而且我认为这是最大的收益来源。

#### 方向 1：constant-key lookup result cache

如果 key 是编译时常量，可以在 specialization 时把：

- `(map_id, key_bytes) -> expected_value`

缓存下来，减少重复 site 的重复 lookup / 重复 materialization。

这本身不一定删 helper，但可以为更 aggressive 的 fast-path 建基础设施。

#### 方向 2：guard + fallback 的 speculative full inline

这是我最推荐的方向。

对 `HASH/LRU_HASH` 的 constant-key site，可以生成：

1. fast path guard：
   - map generation / invalidation epoch 未变
   - key 仍然是这个常量
   - value shape / existence 符合预期
2. fast path body：
   - 直接 materialize inline value
   - 跳过 helper lookup
3. fallback：
   - 走原来的 `bpf_map_lookup_elem()` 路线

这会把当前的“value-load replacement”升级为真正的“lookup fast-path elimination”。

#### 方向 3：对热点 key 做多版本 specialization

如果 profile 能证明某个 key 常见，可以：

- 为常见 key 生成 fast path
- 其他 key 走 fallback

这比“一刀切所有 HASH 都强行 full inline”更务实，也更容易控制 verifier 与代码膨胀风险。

#### 方向 4：扩大 `map_inline` 可覆盖的 use 形状

现在它只认：

- fixed-offset scalar loads

可以继续扩大到：

- 小范围 byte sequence load
- 常见的 packed field materialization
- 紧跟着的一小段 `memcpy` / store 序列

这对 `katran_balancer_xdp` 这类“先把几个字节取出来再拼结构”的程序尤其重要。

## 6. 具体改进建议：按文件落地

## 6.1 [`daemon/src/analysis/map_info.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/analysis/map_info.rs)

建议改动：

1. 把 map capability 从现在的三元判断拆得更细：
   - `supports_direct_value_access`
   - `supports_full_lookup_elision`
   - `supports_guarded_fast_path`
   - `requires_epoch_guard`
2. 对 `HASH/LRU_HASH` 暴露“可 guard 的 speculative full inline”能力，而不是只暴露 `is_speculative_v1()`
3. 如果 invalidation tracker 已经有 generation/epoch 概念，这里直接把它抽象成 pass-level capability

目标：

- 不要让 `HASH` 永久卡在 “speculative but never helper-elidable” 这个状态上

## 6.2 [`daemon/src/passes/map_inline.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs)

这是主战场。

建议优先级从高到低：

1. 为 `HASH/LRU_HASH` 增加 `guard + fallback` 的 full speculative inline 模式
2. 把常量 key 的 lookup 结果做 site-local / pass-round cache，避免重复查同一个 `(map_id, key)`
3. 放宽 `ARRAY/PERCPU_ARRAY` 的 pattern removal 条件

当前的 contiguous-block 规则：

- [`daemon/src/passes/map_inline.rs:1592-1614`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs#L1592)

太保守了。更合理的方向是：

- 不要求整段严格连续
- 允许共享 setup 保留，只删真正 lookup-specific 的 helper/null-check/load
- 或者做更细粒度的 use-def safety check，而不是简单 contiguous gate

4. 扩展可识别 use：
   - 从 fixed scalar loads 扩展到常见小结构 materialization
5. 加强 observability：
   - 在 `PassResult` / diagnostics 里显式区分
     - `pseudo_map_value_constantized`
     - `array_full_lookup_elided`
     - `hash_value_only_inlined`
     - `hash_guarded_fast_path`

这对后续 corpus 分析非常重要，不然 summary 里一个 `map_inline` 看不出到底做成了哪一类事情。

## 6.3 [`daemon/src/passes/const_prop.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/const_prop.rs)

当前最值得做的不是“再多几个 peephole”，而是升级成更接近 SCCP 的东西。

建议：

1. 引入 stack slot / small memory object 常量跟踪
   - 至少覆盖 pass 自己刚刚 materialize 出来的常量块
2. 在 block merge 上从“精确相等常量”扩展到 richer lattice
   - 比如常量范围
   - 或少量 tagged symbolic state
3. 做 branch threading
   - 现在很多 branch 虽然被折了，但控制骨架没进一步 thread
4. 如果要做更大升级，直接考虑 SSA 化后的 sparse conditional constant propagation

我不建议一开始就冲“完整 phi-node 框架”的大工程；更现实的路线是：

- 先做 stack slot / object-field constant tracking
- 再做 jump threading

## 6.4 [`daemon/src/passes/dce.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/dce.rs)

这部分当前收益明显被低估了。

建议：

1. 增加 liveness-based dead definition elimination
2. 增加 dead store elimination
3. 在 branch folding 之后清掉残留的 helper 参数准备
4. 对 pseudo-call / callback subprog 做更强的 reachability + liveness 清理

优先级上，我会先做：

- dead register def elimination
- dead store elimination

因为这两条就已经能把大量“还可达但已经没意义”的残留指令清掉。

## 6.5 新 pass 的优先级建议

如果只允许有限增量，我建议顺序是：

1. `map_inline` 升级 `HASH` guarded fast path
2. `const_prop` 升级为 stronger SCCP-ish propagation
3. 新增 `jump_thread`
4. `dce` 升级为 ADCE / liveness-aware DCE

`loop unrolling` 与 `branch threading` 里，我优先做 `branch threading`。

原因很简单：

- 当前瓶颈是“常量已经出现，但没有沿 CFG 继续放大”
- 不是“循环边界还没被展开”

## 7. 对用户列出问题的逐条回答

### 7.1 级联在真实程序上到底发生了吗？

发生了。

证据：

- `katran:xdp_pktcntr.bpf.o:xdp`
  - `map_inline` 改 2 个 site
  - `const_prop` 改 2 个 site
  - `dce` 删 1 条指令
- `bcc:libbpf-tools/bindsnoop.bpf.o:kprobe/inet_bind`
  - `map_inline` 常量化 3 个 `.rodata` load
  - `const_prop` 折 2 个分支
  - `dce` 删 2 个 `NOP`

但大多数现实 case 不会继续长成“大块路径删除”。

### 7.2 如果 `const_prop` 没有继续传播，为什么？

主要原因有 4 类：

1. `map_inline` 只给出了“字段常量”，没删掉 helper/null-check/control skeleton
2. 常量流向算术/打包，而不是 dominator branch
3. helper call 会杀掉大量寄存器常量状态
4. merge 点上的常量一旦不一致，就退化成 unknown

### 7.3 如果 `dce` 没有消除路径，为什么？

因为当前 `dce` 根本不做真正的 ADCE。

它只能删：

- 不可达块
- `NOP`

所以如果 `const_prop` 只是把若干条件折掉，但没让整块 block 不可达，剩下那些寄存器定义和 helper 参数准备都会继续留着。

### 7.4 HASH map inline 的现状是什么？

一句话：

- 现在是 speculative value inline，不是 speculative full inline

它保留：

- lookup call
- null check

只替换：

- fixed-offset scalar loads

### 7.5 有没有真正 work 的理想 case？

有。

`tracee:sys_enter_submit` captured fixture 里：

- `map_inline` 只改 5 个点
- 但 `const_prop` 把 `3731 -> 1640`
- 最终 `3731 -> 1591`

这说明级联的理论 story 不是假的；只是当前 corpus 的主流 hit 形状不长这样。

## 8. 预期改进效果估计

下面是我的保守估计，明确属于**推断**，不是 benchmark 承诺。

### 8.1 只加强 `const_prop` + `dce`

我预计：

- code size 会有可见改善
- runtime headline 只会有小幅变化

原因：

- 当前主要瓶颈在 `map_inline` 给出的结果不够强
- 只靠后两步，很难把 `HASH` helper 路径凭空删掉

对 applied-only geomean，我的保守预期是：

- 从 `0.9953x` 提到大约 `0.998x ~ 1.005x`

### 8.2 加上 `ARRAY/PERCPU_ARRAY` 的更激进 pattern removal

这会改善像 `xdp_pktcntr` 这种“明明 value 已知，但 helper 还留着”的 case。

我预计：

- 单程序代码体积会更整洁
- 但 corpus headline 不会根本性改变

原因：

- 这类 case 在当前 corpus 里存在，但不是最大头

### 8.3 加上 `HASH/LRU_HASH` 的 guarded full inline

这是我认为**唯一可能显著移动 headline** 的方向。

如果把 `katran_balancer_xdp` 这类现有 `44` 个 hit，从：

- “保留 helper，只替换 load”

变成：

- “hot key fast path 直接走 inline value，helper 退到 fallback”

那么：

- 单程序内可能直接消掉几十次 helper/null-check 热路径
- code size 也会出现更像 `tracee` 那样的放大级联

对 applied-only geomean，我认为合理的目标区间是：

- `1.01x ~ 1.03x`

再往上我不会在当前证据下做承诺。

### 8.4 为什么我不预测更激进的提升

因为当前 corpus 的现实分布告诉我们：

- 很多 hit 只是 `.rodata` guard
- 很多 `HASH` hit 只是 value-load replacement
- 很多 site 根本过不了 constant-key / fixed-load use gate

也就是说，光把单个最佳案例放大，不等于 headline 会自动大幅跳升。

## 9. 我认为最值得做的事情

如果只能做 3 件事，我的排序是：

1. `map_inline`：给 `HASH/LRU_HASH` 做 `guard + fallback` 的 full speculative inline
2. `dce`：补上 liveness-based dead def / dead store elimination
3. `const_prop`：从寄存器精确常量升级到更接近 SCCP 的 object-aware propagation

如果只做第 2 和第 3，不做第 1，这条级联会更“干净”，但不会更“凶”。

真正被留在桌上的收益，主要还是 `HASH` helper fast path 没被拿掉。

## 10. 附：本次离线分析产物

### 10.1 真实 corpus case

- `katran:xdp_pktcntr.bpf.o:xdp`
  - [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/summary.json)
  - [`00_original.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/00_original.txt)
  - [`01_after_map_inline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/01_after_map_inline.txt)
  - [`02_after_map_inline_const_prop.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/02_after_map_inline_const_prop.txt)
  - [`03_after_full_pipeline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_xdp_pktcntr_xdp/03_after_full_pipeline.txt)

- `bcc:libbpf-tools/bindsnoop.bpf.o:kprobe/inet_bind`
  - [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/bindsnoop_kprobe_inet_bind/summary.json)
  - [`00_original.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/bindsnoop_kprobe_inet_bind/00_original.txt)
  - [`01_after_map_inline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/bindsnoop_kprobe_inet_bind/01_after_map_inline.txt)
  - [`02_after_map_inline_const_prop.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/bindsnoop_kprobe_inet_bind/02_after_map_inline_const_prop.txt)
  - [`03_after_full_pipeline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/bindsnoop_kprobe_inet_bind/03_after_full_pipeline.txt)

- `katran:balancer.bpf.o:xdp`
  - [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/summary.json)
  - [`00_original.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/00_original.txt)
  - [`01_after_map_inline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/01_after_map_inline.txt)
  - [`02_after_map_inline_const_prop.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/02_after_map_inline_const_prop.txt)
  - [`03_after_full_pipeline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/katran_balancer_xdp/03_after_full_pipeline.txt)

### 10.2 理想 work case

- `tracee:sys_enter_submit`
  - [`summary.json`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/tracee_sys_enter_submit_captured/summary.json)
  - [`00_original.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/tracee_sys_enter_submit_captured/00_original.txt)
  - [`01_after_map_inline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/tracee_sys_enter_submit_captured/01_after_map_inline.txt)
  - [`02_after_map_inline_const_prop.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/tracee_sys_enter_submit_captured/02_after_map_inline_const_prop.txt)
  - [`03_after_full_pipeline.txt`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/cascade_inspect_output/tracee_sys_enter_submit_captured/03_after_full_pipeline.txt)
