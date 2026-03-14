# K2 / Merlin / EPSO 与 BpfReJIT 的定量对比分析

日期：2026-03-11

## 1. 结论先行

核心结论不是“bytecode optimizer 没用”，而是：

1. **K2 / Merlin / EPSO 与 BpfReJIT 是正交的，不是可互相替代的。**
2. **bytecode/IR 级优化可以改变 verifier 可见的 BPF 程序，但不能直接消除 backend lowering gap。**
3. **当前 characterization 中最大的 gap 正是 backend-only gap：**
   - `byte-recompose` 占 kernel instruction surplus **50.7%**
   - `cmov` 差距表现为 kernel **0** vs llvmbpf **31** 个 `cmov`
   - `branch` 相关 surplus **19.9%**
   - `prologue/epilogue` surplus **18.5%**
4. **LLVM pass ablation 已经表明 bytecode/IR 侧“真正会动结果”的 pass 很少**；本次新增的 dual-pass spot check 进一步说明，在 `load_byte_recompose` / `stride_load_16` / `packet_rss_hash` 这类 backend-gap benchmark 上，同时关闭 `InstCombinePass` 和 `SimplifyCFGPass` 后，llvmbpf 的 native code 几乎不变。
5. **BpfReJIT 能直接作用于这些 backend-only gap**：`rotate` 严格结果为 **1.193x / 1.235x**，`lea` 为 **1.052x**；`cmov` 的 `log2_fold` 结果 **0.655x** 反过来证明了 lowering profitability 是 workload-sensitive，需要 backend policy，而不是固定 bytecode rewrite。

一句话总结：

> **bytecode optimizer 可以改“BPF 长什么样”，但不能替代“同一份 BPF 最后怎样被 lowering 成 native code”。**

---

## 2. 从现有文档提取的定性对比

### 2.1 计划文档中的核心定位表

来源：`docs/kernel-jit-optimization-plan.md` §1.2

| 系统 | 优化层 | 能解决 backend 差距? | 部署可控? |
|------|--------|:---:|:---:|
| K2 (SIGCOMM'21) | BPF bytecode | ❌ | ❌ |
| Merlin (ASPLOS'24) | LLVM IR + BPF | ❌ | ❌ |
| EPSO (ASE'25) | BPF bytecode | ❌ | ❌ |
| **BpfReJIT** | **Backend lowering** | **✅** | **✅** |

### 2.2 研究计划中的扩展定位

来源：`docs/ebpf-bench-research-plan.md` §4.6

| 系统 | 做了什么 | 与 BpfReJIT 的差异 |
|------|---------|-------------------|
| K2 | eBPF bytecode 超优化 | verifier 约束内改 bytecode；BpfReJIT 改 native lowering |
| Merlin | LLVM pass + bytecode rewriting | 可与 backend 优化叠加，但不能替代 backend |
| EPSO | 基于规则/缓存的 bytecode superoptimization | 仍停留在 verifier 前表示层 |

### 2.3 paper-comparison 中的 taxonomy

来源：`docs/paper-comparison.md` §11.1

| 系统 | Layer | Operates on | Constraint | Key result |
|------|-------|-------------|------------|------------|
| K2 | Bytecode synthesis | BPF bytecode | verifier-constrained | 6–26% code-size, 1.36–55% latency reduction |
| Merlin | Multi-layer | LLVM IR + BPF bytecode | verifier-constrained | Faster and more scalable than K2 |
| EPSO | Bytecode rewriting | BPF bytecode | verifier-constrained | 795 rules; up to 68.87% bytecode size; 6.60% avg runtime |
| **BpfReJIT** | **JIT backend** | **Native x86-64 code** | **optimization time not verifier-bound** | **0.849x exec, 0.496x code-size on 31 benchmarks** |

上面三张表其实都在说同一件事：**K2 / Merlin / EPSO 优化的是 verifier 前的程序表示；BpfReJIT 优化的是 verifier 后、JIT emission 时的 native code choice。**

---

## 3. 定量论证框架

### 3.1 要证明的命题

要证明的不是“bytecode optimizer 完全无效”，而是：

> **即使 bytecode optimizer 很强，它仍然无法替代 backend JIT optimization，因为它碰不到 native instruction selection / emission 层面的 gap。**

这可以分成两个子命题：

1. **能力边界命题**：bytecode optimizer 不能表达某些 native-only lowering choice。
2. **量化重要性命题**：这些 native-only gap 在现有 characterization 中占比大，而且确实影响性能。

### 3.2 推荐实验 A 的具体化

用户建议的实验 A 是正确方向：

- 用 llvmbpf 的 `--llvm-disable-pass` / `--llvm-log-passes` 做 LLVM ablation
- 用它来近似“bytecode/IR 级优化最多能贡献多少”
- 再和 BpfReJIT 的 backend recompile 结果做对照

本次实际采用的是：

1. **已有 authoritative pass ablation**
   - 文件：`micro/results/pass_ablation_authoritative.md`
   - 结论：只有 `InstCombinePass` 和 `SimplifyCFGPass` 会稳定改变结果；其他 pass 基本不动 BPF 程序
2. **本次新增 dual-pass spot check**
   - 文件：`micro/results/llvm_dual_pass_boundary_spotcheck.md`
   - 做法：对 6 个代表性 benchmark，同时关闭 `InstCombinePass` 和 `SimplifyCFGPass`
   - 目的：给出 bytecode/IR 侧“剩余可动空间”的一个上界
3. **已有 backend-side evidence**
   - characterization：`docs/micro-bench-status.md`、`docs/paper-comparison.md`
   - rigorous recompile：`docs/tmp/rigorous-benchmark-results.md`
   - fixed-kernel baselines：`docs/tmp/kernel-fixed-baselines-per-directive.md`

这套设计的逻辑是：

- **如果关闭仅有的两个“有效 pass”后，backend-gap benchmark 仍几乎不动**，说明这些 case 的主导因素不是 bytecode/IR optimization
- **如果 BpfReJIT 在同类 benchmark 上能直接带来 gain**，说明决定性因素在 backend lowering

---

## 4. Characterization 中哪些 gap 是 bytecode optimizer 触不到的

### 4.1 suite-level 量化

来源：`docs/micro-bench-status.md`、`docs/paper-comparison.md`

| 证据 | 数值 | 含义 |
|------|------|------|
| pure-JIT exec geomean (llvmbpf/kernel) | **0.849x** | native backend 质量差异真实存在 |
| pure-JIT code-size geomean (llvmbpf/kernel) | **0.496x** | kernel JIT 发射质量系统性更差 |
| byte-recompose share | **50.7%** of kernel surplus | 最大 gap 来源是 native emission |
| byte-recompose isolated penalty | **2.24x** (`load_byte_recompose` = 0.447x) | 不是“只多几条指令”，而是真的进关键路径 |
| branch surplus | **19.9%** | `cmov` / layout / branchless lowering 在这个 bucket 内 |
| cmov count | **31 vs 0** | LLVM backend 能做，kernel JIT 不做 |
| prologue/epilogue surplus | **18.5%** | 也是 backend policy |

三项大头加起来：

- `byte-recompose 50.7%`
- `branch 19.9%`
- `prologue 18.5%`

合计约 **89.1%** 的 measured native-code gap。

### 4.2 这些 gap 为什么是 backend-only

| Gap | 为什么 bytecode optimizer 不能替代 |
|-----|-----------------------------------|
| byte-recompose | 这是 **同一条 BPF load** 最终发成 `movzbq+shl+or` 还是直接 wide native load 的问题；属于 JIT emission，不是 verifier 前 program rewrite |
| cmov | **BPF ISA 没有 `cmov` / `select` native 指令**；bytecode optimizer 最多改 CFG 或算术表达，但不能要求 x86 backend 发 `cmovcc` |
| rotate fusion | BPF 里只有 `shift + or` 语义，**`ror` / `rorx` 是 native instruction selection** |
| LEA fusion | BPF 里只有 add/shift/address arithmetic，**`lea` 是 x86 addressing-mode lowering** |

注意这里的关键不是“理论上永远无法通过重写 bytecode 绕开部分问题”，而是：

> **对同一份 verifier-accepted BPF 程序，bytecode optimizer 无法直接替代 backend 在 machine code emission 上做的 instruction selection choice。**

---

## 5. LLVM pass ablation 给出的 bytecode/IR 上界

### 5.1 authoritative pass ablation：只有两类 pass 会动结果

来源：`micro/results/pass_ablation_authoritative.md`

| 配置 | Successful benchmarks | Median size ratio | Geomean exec ratio |
|------|---:|---:|---:|
| baseline | 31/31 | 1.000x | 1.000x |
| `-InstCombinePass` | 31/31 | 1.012x | 0.959x |
| `-SimplifyCFGPass` | 31/31 | 1.000x | 0.912x |

这里最重要的信息不是“这两个 pass 一定有益”，而是：

1. **只有这两个 pass 会稳定改变结果**
2. **其影响高度异质，不是对所有 benchmark 都同向**
3. **其他 7 个 pass 对 BPF benchmark 基本没有 measurable effect**

这意味着：**BPF 程序在 LLVM middle-end 可挖掘的空间本来就不大。**

### 5.2 本次新增 dual-pass spot check

来源：`micro/results/llvm_dual_pass_boundary_spotcheck.md`

做法：

- baseline：llvmbpf `-O3`
- ablated：llvmbpf `-O3 -InstCombinePass -SimplifyCFGPass`
- benchmark：选 6 个代表性 backend-gap case

结果如下：

| Benchmark | 目标 gap | ablated/base exec | ablated/base size | 解释 |
|-----------|----------|---:|---:|------|
| `switch_dispatch` | cmov / branchless lowering | **1.168x** | **0.978x** | CFG/IR 改动会影响性能，但并没有把问题变成“非 backend 问题” |
| `log2_fold` | policy-sensitive cmov | **0.518x** | **0.983x** | IR 变化很敏感，但仍不能表达 “是否发 cmovcc” 这个 lowering policy |
| `load_byte_recompose` | byte-recompose | **1.003x** | **1.000x** | 关闭两大有效 pass 后几乎完全不变 |
| `stride_load_16` | LEA fusion | **0.999x** | **1.000x** | 同上，IR 侧几乎碰不到 |
| `packet_rss_hash` | rotate fusion | **0.997x** | **1.016x** | 几乎不变 |
| `rotate64_hash` | rotate fusion | **0.811x** | **0.993x** | 执行时间可波动，但 native code size 几乎不变，说明 backend pattern 仍主导 codegen |

spot check 的整体汇总：

- exec geomean (ablated/base): **0.888x**
- size geomean (ablated/base): **0.995x**

最关键的是 **size geomean 0.995x**。
对这些 backend-gap benchmark 而言，**把 llvmbpf 里仅有的两个“有效 pass”都关掉，native code 大小整体几乎没变。**

这说明：

> 在这些 case 上，决定性因素不是 bytecode/IR canonicalization，而是 backend lowering 本身。

---

## 6. BpfReJIT 的 backend 证据

### 6.1 严格结果与 isolated kernel baselines

来源：

- `docs/tmp/rigorous-benchmark-results.md`
- `docs/tmp/kernel-fixed-baselines-per-directive.md`

| Benchmark | Gap family | BpfReJIT / fixed-kernel evidence | 结论 |
|-----------|------------|----------------------------------|------|
| `packet_rss_hash` | rotate | `recompile-v5-rotate`: **1.235x** speedup, `q=0.0033` | rotate fusion 是明确的 backend win |
| `rotate64_hash` | rotate | `recompile-v5-all`: **1.193x** speedup, code size `3559 -> 2313` | backend lowering 同时改善速度和 size |
| `stride_load_16` | lea | `recompile-v5-lea`: **1.052x**, `q=0.0146` | `lea` fusion 是 backend-only gain |
| `log2_fold` | cmov | `recompile-v5-cmov`: **0.655x**（更慢）, `q=0.0033` | 同一合法 backend choice 在不同 workload 下 profitability 不同 |
| `load_byte_recompose` | wide/byte-recompose | `WIDE-only`: `487 -> 418 ns` (**-14.2%**) in same-day kernel-only sweep；rigorous v5-wide 当前不显著 | wide-load lowering 有 backend potential，但当前 v5 path 的 paper-grade profitability 还需更稳证据 |

### 6.2 这里真正支撑论文的点

`cmov` 的 `log2_fold` 结果尤其重要，因为它证明了：

- backend alternative 是**合法的**
- 但 profitability 是**workload-sensitive 的**
- 所以你需要的是 **backend policy substrate**
- 而不是一个固定的 bytecode rewrite 或固定 kernel heuristic

这正是 BpfReJIT 的 thesis：**安全与优化分离**。

---

## 7. benchmark-by-benchmark 能力边界回答

下面只回答这次对比中最有代表性的 benchmark。

### 7.1 `load_byte_recompose`

| 问题 | 回答 |
|------|------|
| bytecode optimizer 能否消除 byte-recompose gap？ | **不能直接替代。** gap 来自 kernel JIT 把同一逻辑 load 发成 byte-by-byte recompose |
| bytecode optimizer 能否添加 cmov？ | 不能，且此 benchmark 不相关 |
| bytecode optimizer 能否做 rotate fusion？ | 不相关 |
| bytecode optimizer 能否做 LEA fusion？ | 不相关 |
| characterization 中占比多大？ | **50.7%** surplus；isolated penalty **2.24x** |
| 本次量化证据 | dual-pass ablation **1.003x exec / 1.000x size**；IR 侧几乎不动 |

### 7.2 `switch_dispatch`

| 问题 | 回答 |
|------|------|
| bytecode optimizer 能否消除 byte-recompose gap？ | 不相关 |
| bytecode optimizer 能否添加 cmov？ | **不能。** BPF ISA 没有 `cmov`; LLVM 的 `28` 个 `cmov` 来自 backend lowering |
| bytecode optimizer 能否做 rotate fusion？ | 不相关 |
| bytecode optimizer 能否做 LEA fusion？ | 不相关 |
| characterization 中占比多大？ | 属于 **19.9% branch surplus** 的一部分；`switch_dispatch` 单 benchmark 有 **28** 个 LLVM `cmov`，kernel 为 `0` |
| 本次量化证据 | dual-pass ablation 会改变 exec（**1.168x**），但这不是“bytecode side 已经等价于 backend cmov”的证据；它仍然无法要求 kernel 发 `cmovcc` |

### 7.3 `log2_fold`

| 问题 | 回答 |
|------|------|
| bytecode optimizer 能否消除 byte-recompose gap？ | 不能直接替代；这里只是次要因素 |
| bytecode optimizer 能否添加 cmov？ | **不能。** 真正的问题是 backend 是否选择 `cmovcc` |
| bytecode optimizer 能否做 rotate fusion？ | 次要 |
| bytecode optimizer 能否做 LEA fusion？ | 次要 |
| characterization 中占比多大？ | 属于 branch/cmov family；不是 suite 最大 share，但对 thesis 最关键，因为它展示 policy sensitivity |
| 本次量化证据 | dual-pass ablation **0.518x exec / 0.983x size**；BpfReJIT `cmov` 结果 **0.655x**（更慢）证明 lowering 不是“越 branchless 越好”，而是 workload-sensitive |

### 7.4 `packet_rss_hash` / `rotate64_hash`

| 问题 | 回答 |
|------|------|
| bytecode optimizer 能否消除 byte-recompose gap？ | 不是主因 |
| bytecode optimizer 能否添加 cmov？ | 不相关 |
| bytecode optimizer 能否做 rotate fusion？ | **不能直接替代。** `ror` / `rorx` 是 native instruction selection |
| bytecode optimizer 能否做 LEA fusion？ | 不相关 |
| characterization 中占比多大？ | 原始 characterization **没有把 rotate 单独作为 suite-wide share bucket**；当前能给出的量化是 **126 rotate sites**（directive census）和 benchmark-local gains |
| 本次量化证据 | `packet_rss_hash`: dual-pass **0.997x / 1.016x**，而 backend rotate 为 **1.235x**；`rotate64_hash`: dual-pass size **0.993x**，而 backend recompile 把 code size `3559 -> 2313` |

### 7.5 `stride_load_16`

| 问题 | 回答 |
|------|------|
| bytecode optimizer 能否消除 byte-recompose gap？ | 不相关 |
| bytecode optimizer 能否添加 cmov？ | 不相关 |
| bytecode optimizer 能否做 rotate fusion？ | 不相关 |
| bytecode optimizer 能否做 LEA fusion？ | **不能直接替代。** `lea` 是 x86 addressing-mode lowering |
| characterization 中占比多大？ | 原始 characterization **没有把 LEA 单列成 suite-wide share**；当前可给出的是 **5 sites** 和 benchmark-local收益 |
| 本次量化证据 | dual-pass **0.999x exec / 1.000x size**，而 `recompile-v5-lea` 为 **1.052x**，`q=0.0146` |

---

## 8. 对 K2 / Merlin / EPSO 的最终判断

### 8.1 可以直接写进论文的主张

可以安全写成：

> **K2, Merlin, and EPSO optimize verifier-visible program representations. They are complementary to BpfReJIT, but they cannot substitute for backend-native lowering control.**

更强一点也可以写：

> **Our characterization shows that the dominant native-code gap comes from backend-only mechanisms: byte-load recomposition (50.7% of kernel surplus), branchless lowering / `cmov` availability (31 vs 0), and other instruction-selection choices such as rotate and LEA fusion. These are outside the direct action space of bytecode optimizers.**

### 8.2 不能写得太绝对的地方

不建议写成：

- “bytecode optimizer 对这些 benchmark 完全没有帮助”
- “K2/Merlin/EPSO 一定比 BpfReJIT 弱”

更准确的表述是：

- **它们能改 program representation，但不能替代 backend choice**
- **收益可以叠加，但 action space 不同**

---

## 9. 外部工具可用性 spot check

截至 **2026-03-11** 的本地检查结果：

### 9.1 K2

- Repo 可访问：<https://github.com/smartnic/superopt>
- 本地 clone 成功
- 但 build 依赖较重：
  - `Makefile` 依赖 **同级目录的 Z3 源码/构建树**
  - 当前环境中没有该 sibling `z3/`
  - 输入格式不是 `.bpf.o`，而是 `--bytecode / --map / --desc` 三文件接口
- 结论：**公开代码可获得，但与当前 benchmark pipeline 不直接兼容，1-2 benchmark 快速复现成本偏高**

### 9.2 Merlin

- Repo 可访问：<https://github.com/4ar0nma0/Merlin>
- 本地 clone 成功
- 两条路径都不是 plug-and-play：
  - LLVM-pass 路径的 `CMakeLists.txt` **硬编码 LLVM 17 + `/usr/local`**
  - 当前主机是 **LLVM 18.1.3**
  - Python bytecode optimizer 需要 `lief`，当前环境 **未安装**
- 结论：**公开代码可获得，但本地直接接入当前实验流水线仍需要额外适配**

### 9.3 EPSO

- 本地文档和论文条目可定位到 paper 标题
- 但截至 **2026-03-11**，我没有通过公开 GitHub repo 探测找到明确的 EPSO 代码仓库
- 结论：**当前按“无可直接获取 artifact”处理更稳妥**

因此本轮没有做 K2 / Merlin / EPSO 的“同 benchmark set 实跑复现”，而是采用：

- 现有 characterization 数据
- LLVM pass ablation
- 本次新增 dual-pass spot check
- backend recompile 结果

来完成定量论证。

---

## 10. 最终结论

这组证据足以支持论文里的核心 claim：

1. **bytecode optimizer 与 BpfReJIT 是正交层，不是替代关系**
2. **当前最大的 gap 来自 backend-only lowering**
3. **这些 gap 在现有 characterization 中占比很高，而且可量化**
4. **LLVM middle-end 对 BPF 的可动空间有限，且效果异质**
5. **真正需要 operator policy 的，是 backend emission choice，而不是 verifier 前的固定 rewrite**

如果要把这份结论压缩成论文里的一个句子，我建议用：

> **Bytecode optimizers can reshape verifier-visible BPF, but they cannot substitute for backend JIT optimization because the dominant remaining gaps arise at native instruction selection and emission time.**
