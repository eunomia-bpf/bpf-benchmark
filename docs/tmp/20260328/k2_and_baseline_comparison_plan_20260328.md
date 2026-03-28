# K2 与 Fixed-Kernel Baseline 对比方案调研

日期：2026-03-28

范围：纯调研，不改代码，不执行 benchmark，不 commit/push。

## 0. 结论先行

### K2

1. K2 是开源的，但不是“今天直接拿来跑我们全量 corpus”的状态。
   - 论文两处明确写了源码和实验脚本在 `https://k2.cs.rutgers.edu/`。
   - 截至 **2026-03-28**，该站点仍然可访问，并链接到两个 GitHub 仓库：
     - `https://github.com/smartnic/superopt`
     - `https://github.com/smartnic/sigcomm21_artifact`
   - `smartnic/superopt` 带 `MIT License`，是核心编译器源码；`sigcomm21_artifact` 是 SIGCOMM'21 artifact 和运行脚本。
   - 但它的环境明显偏旧：README 仍写 Ubuntu 18.04 / macOS 10.15、固定 Z3 commit、Google Drive Docker、CloudLab 复现实验。

2. K2 和 BpfReJIT 不是替代关系，而是层次不同。
   - K2 是 **pre-load 的 BPF bytecode superoptimizer**。
   - BpfReJIT v2 是 **post-load 的 backend/JIT lowering optimizer**。
   - 因此公平对比不能只做 “谁更快” 一列，必须拆成：
     - 前端 bytecode 层收益
     - 后端 JIT 层收益
     - 两者可否叠加

3. K2 与当前 BpfReJIT v2 的 **严格一一对应 overlap 很小**。
   - 明确一一对应的只有 `wide_mem` 这一类字节重组/宽 load-store 合并。
   - `const_prop` / `dce` 只有“意图上部分重叠”。
   - `rotate` / `cond_select` / `extract` / `endian_fusion` / `branch_flip` / `bulk_memory` / `map_inline` / `skb_load_bytes_spec` / `bounds_check_merge` 都不是 K2 论文/源码里明确提供的一类 pass。
   - 换句话说，**pass-family 角度严格 overlap 约 1/12；宽松算上 generic simplification，大约 3/12。**

4. K2 不能直接跑我们全量 `corpus/*.bpf.o`。
   - 它的 object-file 路径不是“直接吃任意 `.bpf.o`”。
   - 它需要：
     - 从 ELF 提取 `.insns`
     - 提取/生成 `.maps`
     - 额外提供 `.desc`
     - 指定要优化的 program/section
     - 再 patch 回新的 `.o`
   - 更关键的是它源码里只建模了 `constant / pkt / pkt_ptrs / skb` 四类输入，helper 白名单也很小，明显偏 XDP / packet path。
   - 所以它最多能覆盖我们 corpus 的一个 **XDP/packet 子集**，不可能覆盖 tracing/LSM/kprobe/struct_ops 的大头。

5. Fixed kernel baseline 的实验重点不应该放在 “ROTATE/WIDE/LEA 能不能 work”，而应该放在 **CMOV policy-sensitivity**。
   - 仓库里已有 fixed-baseline 历史结果已经非常明确：无条件 `CMOV` 会伤害 `log2_fold` 这一类 predictable branch workload。
   - 因此 “userspace policy > fixed heuristic” 的主证明链应该是：
     - 在 `rotate64_hash` / `packet_rss_hash` / `load_byte_recompose` 这类 control case 上，fixed 可能接近 userspace。
     - 但在 `log2_fold` / `binary_search` / `switch_dispatch` / `bounds_ladder` / `large_mixed_500` 这类 policy-sensitive case 上，fixed kernel heuristic 会犯系统性错误，而 userspace policy 可以选择不开 `cond_select`、改开 `branch_flip`、或按 workload 决策。

## 1. 本仓库里和问题直接相关的事实

### 1.1 当前 BpfReJIT v2 pass 集

当前 `PASS_REGISTRY` 里有 12 个 canonical passes：

- `map_inline`
- `const_prop`
- `dce`
- `skb_load_bytes_spec`
- `bounds_check_merge`
- `wide_mem`
- `bulk_memory`
- `rotate`
- `cond_select`
- `extract`
- `endian_fusion`
- `branch_flip`

来源：`daemon/src/passes/mod.rs:52-118`

这已经说明一个关键点：**现在的 v2 不再只是 `map_inline/const_prop/dce` 三件套**。但 `corpus/config/benchmark_config.yaml` 当前 active profile 仍主要是这三项，因此它 **不适合原样复用** 来做 K2 或 fixed-baseline 的完整对比。

来源：`corpus/config/benchmark_config.yaml:8-46`

### 1.2 当前 micro suite 里最适合 fixed-baseline 对比的 benchmark

最关键的一组 micro benchmark 已经在 active suite 中：

- `log2_fold`
- `binary_search`
- `switch_dispatch`
- `load_byte_recompose`
- `bounds_ladder`
- `stride_load_4`
- `stride_load_16`
- `large_mixed_500`
- `packet_rss_hash`
- `rotate64_hash`

来源：`micro/config/micro_pure_jit.yaml:105-175`, `micro/config/micro_pure_jit.yaml:251-333`, `micro/config/micro_pure_jit.yaml:480-489`, `micro/config/micro_pure_jit.yaml:553-564`, `micro/config/micro_pure_jit.yaml:626-635`

这是 fixed-kernel vs userspace-policy 的最佳主战场，因为：

- family 明确
- 输入可控
- correctness 可控
- 能直接看 `jited_prog_len` 和 runtime
- 不受真实系统 attach/trigger 噪声影响

### 1.3 当前 corpus 里与 K2 benchmark 相关的对象

当前 corpus 一共 477 个对象，23 个 repo；最 relevant 的是：

- `cilium`: `bpf_lxc.bpf.o`, `bpf_overlay.bpf.o`, `bpf_xdp.bpf.o`
- `katran`: `balancer.bpf.o`, `xdp_pktcntr.bpf.o`, `xdp_root.bpf.o`
- `xdp-tools`: `xdp_forward.bpf.o`, `xdp_flowtable.bpf.o`, `xdp_flowtable_sample.bpf.o`, `xdp_monitor.bpf.o`, `xdp_redirect_*.bpf.o`

但需要注意：

- 当前 `cilium` 三个对象在 `macro_corpus.yaml` 里都是 `compile_only`
- 按本仓库 `AGENTS.md` 的 benchmark 约束，**runtime 对比不应使用 compile_only/object-only 作为最终实验**

来源：

- `corpus/config/macro_corpus.yaml:4695-4709`
- `corpus/config/macro_corpus.yaml:5085-5155`
- `corpus/config/macro_corpus.yaml:16778-17072`

## 2. K2 对比

### 2.1 K2 是否开源？在哪里？

是，至少从“源码可获取”的意义上是开源的。

#### 论文声明

SIGCOMM'21 论文两处明确写了：

- “K2’s source code, including all of our experimental scripts, is available at `https://k2.cs.rutgers.edu/`.”

来源：

- paper PDF `https://michaeldwong.github.io/papers/k2_sigcomm21.pdf`，第 2 页和第 11 页对应位置

#### 当前可访问入口

截至 **2026-03-28**：

- `https://k2.cs.rutgers.edu/` 返回 200
- 站点首页能解析出两个 GitHub 链接：
  - `https://github.com/smartnic/superopt`
  - `https://github.com/smartnic/sigcomm21_artifact`

#### 代码形态

1. `smartnic/superopt`
   - 核心 K2/superopt 源码
   - 有 `MIT License`
   - README 写明安装方式和 `make main_ebpf.out`

2. `smartnic/sigcomm21_artifact`
   - SIGCOMM artifact
   - 包含 object-file 路径示例、CloudLab throughput/latency 脚本、Docker image 说明

#### 实际可复现性判断

“开源”不等于“今天直接可复现全部论文结果”。

我对当前状态的判断是：

- **源码是公开可获得的**
- **artifact 也是公开可获得的**
- 但环境高度依赖旧版本用户态和 CloudLab，因此可复现性是“中等偏低”，不是 turnkey

### 2.2 K2 支持哪些优化？和 BpfReJIT 的 pass 有多少重叠？

### 2.2.1 K2 的 optimizer 形态

K2 不是 LLVM 风格命名 pass 列表，而是一个 stochastic superoptimizer。

论文第 3.1 节的 proposal generation 有 6 类 rewrite moves：

1. 替换整条 instruction
2. 替换 operand
3. 替换为 NOP
4. memory exchange type 1
5. memory exchange type 2
6. 替换最多 2 条连续指令

来源：paper §3.1

这意味着 K2 的能力边界是：

- 它在 **BPF bytecode** 空间里搜索
- 输出仍是 **BPF bytecode**
- 它可以发现很多 peephole-like rewrites
- 但它不能直接表达 x86 backend-only 选择，例如 `ROR/RORX`、`CMOVcc`、`LEA`、`BEXTR`、`MOVBE`

### 2.2.2 K2 源码里显式支持的 BPF 子集

K2 源码里显式枚举的 ISA/环境边界非常重要：

- 支持的指令子集包含常见 ALU64/ALU32、byteswap、memory、jump、call、exit
- helper 白名单只有：
  - `map_lookup_elem`
  - `map_update_elem`
  - `map_delete_elem`
  - `ktime_get_ns`
  - `get_prandom_u32`
  - `get_smp_processor_id`
  - `tail_call`
  - `redirect`
  - `xdp_adjust_head`
  - `redirect_map`
  - `fib_lookup`
- 输入模型只有：
  - `PGM_INPUT_constant`
  - `PGM_INPUT_pkt`
  - `PGM_INPUT_pkt_ptrs`
  - `PGM_INPUT_skb`

来源：

- `/tmp/k2_superopt/src/isa/ebpf/inst.h:24-119`
- `/tmp/k2_superopt/src/isa/ebpf/inst_var.h:46-64`

这也解释了为什么它明显更偏 XDP / packet / skb，而不是通用 eBPF 全生态。

### 2.2.3 论文中明确展示出来的优化类型

论文 Appendix G / Table 11 明确展示了几类优化：

- 多个 8-bit load/store 合并成 16/32-bit load/store
  - 这和 `wide_mem` 最接近
- `load; add; store` 变成 `xadd`
  - BpfReJIT 当前没有对应 pass
- `mov + store` 折叠成 immediate store
  - 近似 `const_prop`
- 死寄存器赋值 / 死 store 删除
  - 近似 `dce`
- 利用 preconditions/postconditions 的非平凡局部重写
  - BpfReJIT 当前并没有这个 superoptimization 风格能力

来源：paper Table 11

### 2.2.4 与 BpfReJIT 的 overlap

建议分三档说，不要混成一句。

| 关系 | BpfReJIT pass | 结论 |
| --- | --- | --- |
| 严格一一对应 | `wide_mem` | 是，最明确的 overlap |
| 部分语义重叠 | `const_prop`, `dce` | K2 可发现类似结果，但不是以 pass family 暴露 |
| 基本正交 | `rotate`, `cond_select`, `extract`, `endian_fusion`, `branch_flip`, `bulk_memory`, `map_inline`, `skb_load_bytes_spec`, `bounds_check_merge` | K2 没有 paper/source 级别明确对应；尤其 backend-only passes 无法由 bytecode optimizer 直接替代 |

所以我的判断是：

- **strict overlap：1/12**
- **宽松算上 generic simplification：3/12 左右**

更重要的是：**最有论文价值的 BpfReJIT passes 恰恰是 K2 不直接覆盖的 backend-only families。**

### 2.3 K2 需要 `.bpf.o` 输入（pre-load），BpfReJIT 是 post-load，如何做公平对比？

这里不能只做一个 “最终 runtime” 表格，否则会混淆两个不同优化边界。

我建议分成两层：

### 2.3.1 Steady-state datapath fairness

用同一份原始 `.bpf.o`、同一 workload、同一 VM、同一 kernel build root，比较四种模式：

| 模式 | 输入对象 | 是否预先改 bytecode | 是否 post-load REJIT |
| --- | --- | --- | --- |
| M0 | original `.bpf.o` | 否 | 否 |
| M1 | K2-optimized `.bpf.o` | 是 | 否 |
| M2 | original `.bpf.o` | 否 | 是 |
| M3 | K2-optimized `.bpf.o` | 是 | 是 |

推荐做法：

- 对 K2 vs BpfReJIT 的主比较，优先都放在 **同一个 REJIT-capable kernel 上**
- M0/M1 中“no apply”时不要触发 REJIT
- 这样 kernel branch drift 最小

然后拆解：

- `M1 / M0` = K2 frontend-only 收益
- `M2 / M0` = BpfReJIT backend-only 收益
- `M3 / M1` = K2 后还能不能再吃到 backend-only 收益
- `M3 / M0` = 组合上限

### 2.3.2 Optimization overhead fairness

优化时间必须单独报，不能混进 steady-state runtime：

- K2：离线 compile time / search time / patch object time
- BpfReJIT：load 后 enumerate/rewrite/apply latency

原因很简单：

- K2 是 offline/off-path superoptimization
- BpfReJIT 是 online/post-load apply

二者 operational cost 模型不同。把它们硬塞进同一列 “优化耗时” 没意义，但必须并列报告。

### 2.3.3 Acceptance fairness

还要单独报一个 acceptance/loadability 维度：

- K2 可能改变 verifier-visible bytecode，因此可能让原程序更容易或更难 load
- BpfReJIT 只处理已经 load 的程序

所以要区分：

- `K2 optimize success / K2 load success`
- `BpfReJIT apply success among already-loadable programs`

不要把这两者混成一个 success rate。

### 2.4 能否在同样的 corpus `.bpf.o` 上跑 K2？

### 2.4.1 结论

**能，但只能跑一个窄子集；不能跑全量 corpus。**

### 2.4.2 为什么不是直接 “yes”

K2 的 object-file 路径要求：

1. `elf_extract` 从 ELF 中拆出 `<prog>.insns`
2. 生成/读取 `<prog>.maps`
3. 额外提供 `<prog>.desc`
4. 调 `main_ebpf.out`
5. 再用 patcher 写回新的 `.o`

来源：

- `/tmp/k2_artifact/2_different_inputs/3_object_file/run_k2.py:32-78`
- `/tmp/k2_artifact/2_different_inputs/3_object_file/README.md:4-23`

也就是说，K2 不是 “把 `.bpf.o` 直接喂进去就结束”。它要求一层 K2-specific metadata/translation pipeline。

### 2.4.3 哪些 corpus 对象有机会

最有机会的是当前 corpus 里 **runtime-testable 的 XDP/packet 子集**：

- `corpus/build/katran/xdp_pktcntr.bpf.o`
- `corpus/build/katran/balancer.bpf.o`
- `corpus/build/xdp-tools/xdp_forward.bpf.o`
- `corpus/build/xdp-tools/xdp_flowtable.bpf.o`
- `corpus/build/xdp-tools/xdp_flowtable_sample.bpf.o`
- `corpus/build/xdp-tools/xdp_redirect_basic.bpf.o` 的 XDP section
- `corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o` 的 XDP section
- `corpus/build/xdp-tools/xdp_redirect_devmap.bpf.o` 的 XDP section
- `corpus/build/xdp-tools/xdp_redirect_devmap_multi.bpf.o` 的 XDP section

理由：

- 都是 packet/XDP oriented
- 当前 corpus manifest 已经有 runtime harness
- 更接近 K2 的 input model 和 helper whitelist

### 2.4.4 哪些 corpus 对象不应作为 K2 首批目标

1. `cilium` 当前三项
   - 当前 manifest 是 `compile_only`
   - 不适合做最终 runtime 对比

2. tracing / LSM / kprobe / struct_ops / large helper-rich programs
   - 超出 K2 当前 input model / helper whitelist 的概率很高

3. 我们的 micro suite
   - 它是 staged synthetic input benchmark
   - 不是 K2 论文那种 packet/XDP bytecode 优化对象
   - K2 也没有现成模型去表达我们这类 micro 的 staged buffer ABI

### 2.4.5 `.desc` 能否从 corpus 自动推导？

**推断：对 XDP 子集，基本可以；对全量 corpus，不行。**

依据：

- K2 的 `xdp1` 示例 `.desc` 只写了 `pgm_input_type` 和 `max_pkt_sz`
- 对 XDP 程序，合理推断可以映射到 `PGM_INPUT_pkt_ptrs`
- 对 `sched_cls` / skb 程序，可能可以映射到 `PGM_INPUT_skb`
- 但 tracing/LSM/kprobe 没有对应 generic model

这是推断，不是源码里直接写明的自动化能力。

### 2.5 K2 论文里的 benchmark 是什么？我们的 corpus 和它有多少重叠？

### 2.5.1 论文里的 benchmark 组

K2 论文里其实有三套 benchmark 视角：

1. **19 个 instruction-count / estimated-performance benchmark**
   - 见 paper Table 7 / Table 9
   - 名字是：
     - `xdp_exception`
     - `xdp_redirect_err`
     - `xdp_devmap_xmit`
     - `xdp_cpumap_kthread`
     - `xdp_cpumap_enqueue`
     - `sys_enter_open`
     - `socket/0`
     - `socket/1`
     - `xdp_router_ipv4`
     - `xdp_redirect`
     - `xdp1_kern/xdp1`
     - `xdp2_kern/xdp1`
     - `xdp_fwd`
     - `xdp_pktcntr`
     - `xdp_fw`
     - `xdp_map_access`
     - `from-network`
     - `recvmsg4`
     - `xdp-balancer`

2. **4 个 throughput benchmark（Table 2）**
   - `xdp2`
   - `xdp_router_ipv4`
   - `xdp_fwd`
   - `xdp1`

3. **4 个 latency-under-load benchmark（Table 3 / Appendix H）**
   - `xdp2`
   - `xdp_router_ipv4`
   - `xdp_fwd`
   - `xdp-balancer`

artifact 里还保留了一个更小的可复现子集。

### 2.5.2 与我们当前 corpus 的重叠

重叠明显是 **部分的，不是大面积 exact overlap**。

#### A. 明确 exact / near-exact overlap

- `katran/xdp_pktcntr.bpf.o`
  - 这是最明确的 exact overlap
- `xdp_redirect`
  - 当前 corpus 中有 exact program name
- `xdp_exception`
- `xdp_redirect_err`
- `xdp_devmap_xmit`
- `xdp_cpumap_kthread`
- `xdp_cpumap_enqueue`
  - 这些在 `xdp-tools/xdp_monitor.bpf.o` 和相关 `xdp_redirect_*` 对象里都有对应 tracepoint/program name

#### B. 同 repo / 同功能，但不是 exact 同 benchmark

- K2 的 `from-network`
  - 当前 corpus 有 `cilium/bpf_xdp.bpf.o` 等对象
  - 但不是 exact 同 benchmark 名，且当前是 `compile_only`
- K2 的 `xdp-balancer`
  - 当前 corpus 有 `katran/balancer.bpf.o`
  - 非 exact 同名，但功能族非常接近
- K2 的 `xdp_fwd` / `xdp_fw`
  - 当前 corpus 有 `xdp-tools/xdp_forward.bpf.o`, `xdp_flowtable*.bpf.o`
  - 是 forwarding family 的近似对应

#### C. 当前 corpus 里基本缺失

- `xdp_router_ipv4`
- `xdp1`
- `xdp2`
- `xdp_map_access`
- `recvmsg4`
- `socket/0`
- `socket/1`

### 2.5.3 对 overlap 的总体判断

如果按“完全同名/同对象”算，重叠不高。

如果按“同系统/同家族/同 XDP datapath 类型”算，重叠中等，主要集中在：

- Katran
- Cilium
- xdp-tools / Linux XDP tracepoints

因此我建议报告里不要写“我们的 corpus 和 K2 benchmark 高度重叠”。

更准确的表述是：

> 当前 corpus 与 K2 benchmark 在 XDP/packet family 上有 **可用但有限的交集**；足以做一个 K2-subset 对比，但不足以把全量 corpus 当成 K2 paper benchmark 的直接延伸。

### 2.6 具体对比实验设计

我建议分两层设计。

### 2.6.1 设计 A：repo 内可执行的 K2 subset 对比

目标：

- 用 **同一批 runtime-testable XDP `.bpf.o`**，比较 K2 vs BpfReJIT vs 组合

对象集合：

- `katran/xdp_pktcntr.bpf.o`
- `katran/balancer.bpf.o`
- `xdp-tools/xdp_forward.bpf.o`
- `xdp-tools/xdp_flowtable.bpf.o`
- `xdp-tools/xdp_flowtable_sample.bpf.o`
- `xdp-tools/xdp_redirect_basic.bpf.o` 的 XDP program
- `xdp-tools/xdp_redirect_cpumap.bpf.o` 的 XDP program
- `xdp-tools/xdp_redirect_devmap.bpf.o` 的 XDP program
- `xdp-tools/xdp_redirect_devmap_multi.bpf.o` 的 XDP program

模式矩阵：

| 模式 | 说明 |
| --- | --- |
| `orig/no-apply` | 原始 `.bpf.o`，REJIT kernel，不 apply |
| `k2/no-apply` | K2 产出的 `.bpf.o`，同 kernel，不 apply |
| `orig/rejit` | 原始 `.bpf.o`，load 后 apply BpfReJIT v2 |
| `k2/rejit` | K2 `.bpf.o`，load 后再 apply BpfReJIT v2 |

指标：

- optimize success rate
- load success rate
- compile/apply latency
- `xlated_prog_len`
- `jited_prog_len`
- steady-state runtime / throughput / latency

核心问题：

1. `k2/no-apply` 能不能比 `orig/no-apply` 更好？
2. `orig/rejit` 能不能比 `k2/no-apply` 更好？
3. `k2/rejit` 是否还能继续变好？
   - 如果能，说明 K2 与 BpfReJIT 正交可叠加
   - 如果不能，说明该子集上二者收益高度重合

推荐结论口径：

- 如果 `k2/rejit > k2/no-apply` 且 `k2/rejit > orig/rejit`，应写成“前端+后端可叠加”
- 不要写成“K2 被 BpfReJIT 替代”或反之

### 2.6.2 设计 B：paper-anchored K2 benchmark reproduction

目标：

- 用 K2 自己的 benchmark 集合做 “paper-facing” 对比

优先 benchmark：

- `xdp2`
- `xdp_router_ipv4`
- `xdp_fwd`
- `xdp-balancer`
- `xdp_pktcntr`
- `from-network`

理由：

- 这几项要么直接出现在 Table 2 / Table 3
- 要么是 K2 论文最像 production datapath 的 benchmark

问题：

- 需要恢复 K2 artifact 的旧环境
- throughput/latency 原始方法依赖 CloudLab/traffic generator
- 与当前 repo 的 VM harness 不是同一 measurement stack

所以这层实验更像“paper bridge”，不是最先该做的工程对比。

## 3. Fixed kernel peephole baseline

### 3.1 仓库事实

`vendor/linux-framework` 本地有 `jit-fixed-baselines` 分支。

该分支的 Kconfig 里有：

- `CONFIG_BPF_JIT_FIXED_ROTATE`
- `CONFIG_BPF_JIT_FIXED_WIDE_MEM`
- `CONFIG_BPF_JIT_FIXED_LEA`
- `CONFIG_BPF_JIT_FIXED_CMOV`

并且 help 文本已经明确它们是 x86 JIT 内的 fixed baseline。

来源：`vendor/linux-framework` 的 `jit-fixed-baselines:kernel/bpf/Kconfig:73-105`

尤其是：

- `FIXED_ROTATE`: 固定发 `ROR/RORX`
- `FIXED_WIDE_MEM`: 固定把 byte-recompose ladder 融成宽 load
- `FIXED_LEA`: 固定把 `mov+shl+add` 融成 `LEA`
- `FIXED_CMOV`: 固定把 branch diamond/compact 融成 `CMOV`

其中 `CMOV` 的 help 文本已经明确承认它“可能伤害 predictable workloads”。

### 3.2 为什么这个 baseline 值得做

这个 baseline 不是普通 control，而是论文里最强的 reviewer question：

> 既然这些 pattern 都能识别，为什么不直接把它们 hardcode 到 kernel JIT 里？

所以这个 baseline 必须证明两件事：

1. 某些 family 上，fixed heuristic 的确足够接近 userspace policy
2. 至少有一个 family 上，fixed heuristic 会系统性做错决策

当前仓库已有历史结果已经说明：

- `ROTATE` / `WIDE_MEM` 常常能复现主要方向
- `LEA` 不是总是稳定收益
- `CMOV` 是明确的 policy-sensitive 反例

### 3.3 具体实验设计：哪些 benchmark、什么 config、怎么对比

### 3.3.1 主实验：micro suite

这是 fixed baseline 的主战场。

#### Benchmark 分组

1. `ROTATE` control
   - `rotate64_hash`
   - `packet_rss_hash`

2. `WIDE_MEM` control
   - `load_byte_recompose`

3. `LEA/WIDE` interaction
   - `stride_load_4`
   - `stride_load_16`

4. `CMOV / policy-sensitive`
   - `log2_fold`
   - `binary_search`
   - `switch_dispatch`
   - `bounds_ladder`
   - `large_mixed_500`

推荐理由：

- 前三组回答“fixed heuristics 在 textbook peephole 上能做到什么程度”
- 最后一组回答“为什么 userspace policy 仍然必要”

#### Kernel/config 矩阵

最理想矩阵：

| 模式 | 配置 |
| --- | --- |
| `stock` | 所有 `CONFIG_BPF_JIT_FIXED_* = n` |
| `fixed-rotate` | 仅 `ROTATE=y` |
| `fixed-wide` | 仅 `WIDE_MEM=y` |
| `fixed-lea` | 仅 `LEA=y` |
| `fixed-cmov` | 仅 `CMOV=y` |
| `fixed-all` | `ROTATE/WIDE_MEM/LEA/CMOV = y` |
| `rejit-v2-policy` | fixed 全关，BpfReJIT v2 按 userspace policy apply |
| `rejit-v2-blind` | fixed 全关，BpfReJIT blind all-apply，作为负对照 |

#### 最重要的公平性要求

publication-grade 最好是 **同一个 unified kernel tree** 同时支持：

- `BPF_PROG_REJIT` v2
- `CONFIG_BPF_JIT_FIXED_*`

这样才能把 `stock` / `fixed-*` / `rejit-v2-policy` 放在同一 kernel tree 上比较。

如果当前 repo 还没有这样的 unified tree，则：

- **短期 fallback**：分别在 `jit-fixed-baselines` 和 `rejit-v2` 上做各自相对 `stock` 的 normalized effect
- **长期论文版**：必须合并成 unified tree 再出最终图表

#### 推荐比较方式

每个 benchmark 报：

- correctness
- `xlated_prog_len`
- `jited_prog_len`
- steady-state runtime
- 相对 `stock` 的 delta

重点判读：

- `fixed-rotate` vs `rejit-v2-policy` 在 `rotate64_hash` / `packet_rss_hash`
- `fixed-wide` vs `rejit-v2-policy` 在 `load_byte_recompose`
- `fixed-lea` vs `rejit-v2-policy` 在 `stride_load_*`
- `fixed-cmov` vs `rejit-v2-policy` 在 `log2_fold` / `binary_search` / `switch_dispatch` / `bounds_ladder` / `large_mixed_500`

#### 预期结论模板

预期最可能出现的格局是：

- `ROTATE`: fixed ~= userspace
- `WIDE_MEM`: fixed 接近 userspace，但不一定总最优
- `LEA`: fixed 结果不稳定，userspace policy 至少能 fail-close
- `CMOV`: fixed 明显不如 userspace policy

这就足够支撑：

> userspace policy 不是为了替代所有 fixed peephole，而是为了在 policy-sensitive family 上避免 fixed heuristic 的系统性误判。

### 3.3.2 次实验：real-world XDP corpus 子集

为避免把结论锁死在 synthetic micro 上，再做一个小而硬的 real-world 子集：

- `katran/balancer.bpf.o`
- `katran/xdp_pktcntr.bpf.o`
- `xdp-tools/xdp_forward.bpf.o`
- `xdp-tools/xdp_flowtable.bpf.o`
- `xdp-tools/xdp_flowtable_sample.bpf.o`
- `xdp-tools/xdp_redirect_basic.bpf.o` 的 XDP program
- `xdp-tools/xdp_redirect_cpumap.bpf.o` 的 XDP program
- `xdp-tools/xdp_redirect_devmap.bpf.o` 的 XDP program
- `xdp-tools/xdp_redirect_devmap_multi.bpf.o` 的 XDP program

这里不追求 family 隔离，而追求：

- 是否在真实 XDP datapath 上重现同样趋势
- `fixed-all` 是否比 `rejit-v2-policy` 更容易出现 regression

### 3.3.3 不建议作为 fixed-baseline 主结论的数据

1. `compile_only` 对象
   - 不能作为最终 runtime 证据

2. tracing/attach 噪声太大的全量 corpus
   - 可做补充，不适合作为 fixed-vs-policy 的第一主图

3. `blind all-apply` 直接对 `fixed-all`
   - 这不是 userspace policy
   - 最多是负对照

### 3.4 如何“证明 userspace policy > fixed kernel heuristic”

建议把证明标准写成以下三条，而不是只看 geomean：

1. **No-regression count**
   - `rejit-v2-policy` 在 policy-sensitive 组上的 regression 数应少于 `fixed-all`

2. **Critical benchmark wins**
   - `log2_fold` 必须是 userspace policy 胜出
   - `binary_search` / `switch_dispatch` / `large_mixed_500` 至少应有一部分能体现 “开/不开 `cond_select` 或改用 `branch_flip`” 的优势

3. **Control-case honesty**
   - 在 `rotate64_hash` / `packet_rss_hash` / `load_byte_recompose` 这类 case 上，如果 fixed 已经接近 userspace，就要诚实承认
   - 论文主张应是 “userspace policy is necessary for the hard cases”，而不是 “fixed heuristic 永远不行”

## 4. 我建议的最终实验矩阵

### 4.1 K2

先做 repo-native subset：

- 对象：上文列出的 XDP 子集
- 模式：`orig/no-apply`, `k2/no-apply`, `orig/rejit`, `k2/rejit`
- 输出：
  - compile/apply latency
  - loadability
  - `xlated_prog_len`
  - `jited_prog_len`
  - runtime

然后再决定是否值得追加 paper-anchored reproduction。

### 4.2 Fixed baseline

主图用 micro：

- `rotate64_hash`
- `packet_rss_hash`
- `load_byte_recompose`
- `stride_load_4`
- `stride_load_16`
- `log2_fold`
- `binary_search`
- `switch_dispatch`
- `bounds_ladder`
- `large_mixed_500`

配置：

- `stock`
- `fixed-rotate`
- `fixed-wide`
- `fixed-lea`
- `fixed-cmov`
- `fixed-all`
- `rejit-v2-policy`
- `rejit-v2-blind`

real-world 子图用 XDP corpus 子集做 external validity。

## 5. 推荐落地顺序

1. 先做 fixed-baseline vs userspace-policy 的 micro 主实验
   - 这是最短路径
   - 也是最容易形成清晰结论的部分

2. 再做 K2 subset feasibility
   - 先验证哪些 corpus XDP `.bpf.o` 真能被 K2 object pipeline 接受
   - 不要一开始就尝试全量 corpus

3. 最后再考虑 K2 paper benchmark reproduction
   - 这是“加分项”，不是当前仓库论证链的最短路径

## 6. 参考资料

### 外部

- K2 论文 PDF: `https://michaeldwong.github.io/papers/k2_sigcomm21.pdf`
- K2 project page: `https://k2.cs.rutgers.edu/`
- K2 core source: `https://github.com/smartnic/superopt`
- K2 SIGCOMM artifact: `https://github.com/smartnic/sigcomm21_artifact`

### 仓库内

- BpfReJIT pass registry: `daemon/src/passes/mod.rs`
- micro suite manifest: `micro/config/micro_pure_jit.yaml`
- corpus macro manifest: `corpus/config/macro_corpus.yaml`
- current corpus benchmark config: `corpus/config/benchmark_config.yaml`
- historical fixed-baseline notes:
  - `docs/tmp/2026-03-10/kernel-fixed-baselines-design.md`
  - `docs/tmp/2026-03-10/kernel-fixed-baselines-per-directive.md`
  - `docs/tmp/2026-03-10/kernel-fixed-baselines-test-results.md`
