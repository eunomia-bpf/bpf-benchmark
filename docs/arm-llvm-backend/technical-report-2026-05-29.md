# ARM64 LLVM Backend 技术报告

日期：2026-05-29

本文面向项目读者，目标是自包含说明：

- 这个项目要解决什么问题。
- ARM64 kinsn lowering 在 LLVM BPF backend 里具体做了什么。
- 已经实现了哪些 ARM64 kinsn family。
- 现有 micro benchmark 实验怎么跑、指标怎么计算、结果是什么。
- 当前有证据支持的性能结论和默认策略是什么。

本文不是实验流水账。完整原始数据和长报告见文末“数据位置”。

## 目录

1. 结论
2. 背景和目标
3. 实现机制
4. 当前实现范围
5. 实验方法
6. 实验结果
7. 当前解释和默认策略
8. 未完成事项
9. 数据位置

章节目的：

| 章节 | 想表达的内容 |
|---|---|
| 1. 结论 | 先给当前成果和默认策略，便于快速了解当前状态。 |
| 2. 背景和目标 | 说明这里的 ARM64 LLVM backend 是 BPF backend 里的 kinsn lowering，不是 AArch64 backend。 |
| 3. 实现机制 | 说明 LLVM、BPF object、kernel verifier/module/JIT 各自承担什么职责，并用 `EXTR` 给出具体例子。 |
| 4. 当前实现范围 | 列出全部已有 ABI family、kfunc 数量和当前状态。 |
| 5. 实验方法 | 说明实验分组、AWS 设置、micro benchmark suite 和指标公式。 |
| 6. 实验结果 | 按实验逐个说明目的、做法、结果和 takeaway。 |
| 7. 当前解释和默认策略 | 把实验结果收敛成默认策略决策。 |
| 8. 未完成事项 | 明确哪些结论还只是 development-grade，后续还需要补什么。 |
| 9. 数据位置 | 指向完整 raw data、analysis TSV 和长报告。 |

## 1. 结论

目标是在 LLVM 的 BPF backend 中实现 ARM64 kinsn lowering。这里不是新增 AArch64 backend；
LLVM 的输出仍然是 BPF object，只是在 BPF object 里用 `KINSN_SIDECAR +
KINSN_CALL bpf_arm64_*` 表达可以由 kernel 替换成 ARM64 native instruction 的 kinsn。

截至 2026-05-29：

- 已有 ARM64 module ABI 的 25 个 `bpf_arm64_*` target 已全部进入 LLVM。
- full micro correctness 通过：34 个 benchmark，0 个 bad sample。
- target isolation 通过：ARM64 treatment 里 0 个 `bpf_x86_*` relocation。
- family-only 和 true all-on same-LLC attribution 已完成。
- targeted native JIT dump 已证明两个主要收益来源：
  - `EXTR`：把 rotate 的 shift/or sequence 替换成 native `ror`。
  - selected `LDR`：把 byte-load/shift/or 合成替换成更短 load sequence。
- 当前默认候选策略是：

```text
EXTR + selected LDR
```

不建议默认打开 `PRFM`、`CCMP/CMP/CSET`、`CSEL`、`STR`、`LDP/STP`、`REV`、`UBFM`、`MOV`。
这些 family 已经有 coverage / correctness，但当前 micro 数据不足以支持默认启用。

## 2. 背景和目标

BPF 程序最终会被 kernel JIT 编译成机器码。普通路径是：

```text
BPF C program
  -> clang / LLVM BPF backend
  -> BPF object
  -> kernel verifier
  -> ARM64 BPF JIT
  -> native AArch64 code
```

本项目加入的路径是：

```text
BPF C program
  -> clang / LLVM BPF backend
  -> LLVM BPF backend 识别特定 BPF MIR sequence
  -> emit KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
  -> verifier 检查 proof expansion
  -> ARM64 kinsn module / JIT lower 成 native AArch64 instruction
```

关键词：

| 术语 | 含义 |
|---|---|
| BPF backend | LLVM 中负责把 IR / MachineInstr 降到 BPF object 的 target backend。 |
| kinsn | kernel instruction substitution。本文中指通过 `KINSN_SIDECAR + KINSN_CALL` 表达的可替换指令。 |
| kfunc | kernel function。这里的 `bpf_arm64_*` kfunc 是 verifier / module 识别 kinsn 的入口。 |
| ABI | ARM64 kinsn module 暴露给 LLVM 和 verifier 的约定，包括 kfunc 名、payload 格式、寄存器限制、proof expansion、native lowering。不是用户态 C ABI。 |
| family | 一组语义相关的 kfunc target。例如 `EXTR` 对应 rotate，`LDR` 对应 load。 |
| selector | LLVM BPF backend 中识别 BPF MIR sequence 并替换成 kinsn pseudo 的逻辑。 |
| pseudo | LLVM 内部伪指令，最终由 AsmPrinter 打包成 sidecar payload。 |
| same-LLC | 同一个 custom LLVM `llc`。这里不是 CPU cache，而是指 control 和 treatment 都用同一个 `llc`，只改变 kinsn selector 开关。 |

## 3. 实现机制

每个 kinsn family 的 LLVM 实现由四层组成：

| 层 | 文件 / 目录 | 作用 |
|---|---|---|
| ARM64 module ABI | `/home/ruoji/github/bpf-opt/code/module/arm64` | 定义 kfunc、payload decoder、proof expansion、native lowering descriptor。 |
| LLVM pseudo | `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFInstrInfo.td` | 定义 BPF backend 内部使用的 ARM64 kinsn pseudo。 |
| LLVM selector | `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFKinsnSelect.cpp` | 识别 BPF MIR sequence，并替换成 pseudo。 |
| LLVM AsmPrinter | `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFAsmPrinter.cpp` | 把 pseudo operand 按 module ABI 打包成 `KINSN_SIDECAR` payload，并 emit `KINSN_CALL`。 |

### 示例：rotate 到 EXTR

一个 64-bit rotate 可以写成：

```c
u64 rotl64(u64 x)
{
    return (x << 13) | (x >> 51);
}
```

关闭 kinsn selector 时，BPF assembly 是普通 shift/or sequence：

```asm
r0 = r1
r1 >>= 51
r0 <<= 13
r0 |= r1
exit
```

打开 `rotate=force` 后，LLVM BPF backend 识别这个 sequence，并输出：

```asm
kinsn_sidecar 0, 8401, 0
kinsn_call bpf_arm64_extr_x
exit
```

这个 object 仍然是 BPF object，不是 AArch64 object。`kinsn_sidecar` 携带 payload；
`kinsn_call` 通过 relocation 指向 `bpf_arm64_extr_x`。加载到 kernel 后，verifier 先用
proof expansion 证明语义等价，然后 ARM64 kinsn module / JIT 才能 lower 成 native
`extr`，objdump 中常显示为 `ror`。

## 4. 当前实现范围

已有 ARM64 ABI 的 25 个 target 已全部实现到 LLVM：

| Family | kfunc count | 语义 | 当前状态 |
|---|---:|---|---|
| `REV` | 3 | byte reverse / endian swap | correctness complete；不默认启用。 |
| `EXTR` | 2 | rotate / extract | correctness complete；默认候选。 |
| `UBFM` | 1 | bitfield extract | correctness complete；当前不默认启用。 |
| `LDR` | 4 | load | correctness complete；selected wide-load 默认候选。 |
| `STR` | 4 | store | correctness complete；不默认启用。 |
| `LDP/STP` | 2 | pair load/store | stack-only subset complete；不默认启用。 |
| `CSEL` | 2 | conditional select | correctness complete；不默认启用。 |
| `CCMP/CMP/CSET` | 5 | compare / conditional compare / condition set | correctness complete；不默认启用。 |
| `PRFM` | 1 | prefetch hint | correctness / codegen evidence complete；不默认启用。 |
| `MOV` | 1 | register move | object path complete；micro 无自然命中，不默认启用。 |

当前默认候选只保留：

```text
EXTR + selected LDR
```

原因是它们有 family-only performance 信号和 native JIT dump 证据。其他 family 只证明了可
emit、可加载、可运行，尚未证明默认打开能带来稳定收益。

## 5. 实验方法

### 5.1 编译分组

可信性能比较至少需要三组：

| group | 编译方式 | 用途 |
|---|---|---|
| `baseline` | 普通 clang | 辅助观察普通 clang 与 custom LLVM 的差异；不是主性能对照。 |
| `control-disabled` | custom `llc` + `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable` | same-LLC 主对照。 |
| `treatment-*` | 同一个 custom `llc` + 打开某些 selector policy | 测某个 family 或组合的影响。 |

主性能口径是：

```text
treatment / control-disabled
```

这样可以避免把 custom LLVM 自身变化误认为 kinsn 收益。

### 5.2 AWS 和 benchmark 设置

主要 micro benchmark 在 AWS ARM64 上跑：

| item | value |
|---|---|
| workspace | `/home/ruoji/github/bpf-opt` |
| code repo | `/home/ruoji/github/bpf-opt/code` |
| platform | AWS ARM64 |
| region | `us-east-1` |
| instance | `t4g.small` |
| kernel | `7.0.0-rc2+` |
| container | `bpf-benchmark/runner-runtime:arm64` |
| runtimes | `native kernel` |
| common samples | `SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000` |

典型命令形态：

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu ./aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-disable-gotox -bpf-kinsn-target=arm64 ..." \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

所有 benchmark 都通过 Makefile / AWS wrapper 入口运行。

### 5.3 micro benchmark suite

当前 full micro suite 有 34 个 benchmark。它不是一个单一 workload，而是一组小 BPF 程序，
覆盖 packet parsing、hash、bitfield、stack memory、conditional select 等场景。

相对 `code` 仓库 `origin/main`：

| 类别 | 数量 | 说明 |
|---|---:|---|
| 原有 benchmark | 29 | 原 benchmark suite 已有。 |
| 新增 targeted coverage benchmark | 5 | 为覆盖 ARM64 ABI / family 补充：`arm64_direct_abi_coverage`、`ccmp_all_nonzero`、`csel_select64`、`ldp_stack_pair`、`stp_stack_pair`。 |

每个 benchmark 只会触发一部分 kinsn。打开所有 selector 不等于每个 benchmark 都用到所有
family。因此性能分析必须同时看：

- object 里实际出现了哪些 `bpf_arm64_*` relocation。
- runtime ratio 是多少。
- 必要时看 native JIT dump。

### 5.4 指标定义

raw sample 是一个固定 `rep / group / benchmark / runtime / sample_index` 的测量结果。

`SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000` 的含义是：

| 参数 | 含义 |
|---|---|
| `SAMPLES=3` | 每个 `group / benchmark / runtime` 记录 3 个 measured sample。 |
| `WARMUPS=0` | measured sample 前不额外跑 warmup。 |
| `INNER_REPEAT=100000` | 一个 sample 内部重复执行 benchmark 100000 次，runner 把总时间除以 100000。 |

关键字段：

| 字段 | 来源 | 单位 | 用途 |
|---|---|---|---|
| `exec_ns` | `kernel` runtime 下来自 `bpf_prog_test_run_opts(...).duration`。 | ns / call | 主性能口径。 |
| `wall_exec_ns` | runner 在 kernel test-run 外层用 TSC 估算。 | ns / call | sanity reference，不用于 ratio。 |
| `compile_ns` | object open + load 等阶段耗时。 | ns | 不用于 runtime ratio。 |
| `jited_prog_len` | kernel JIT 后 native code 字节数。 | bytes | code size / native dump 分析。 |
| `xlated_prog_len` | kernel 内部 BPF instruction stream 字节数。 | bytes | object/JIT attribution。 |

每轮 ratio：

```text
ratio =
  median_exec_ns(treatment, benchmark, runtime)
  /
  median_exec_ns(control-disabled, benchmark, runtime)
```

解释：

| ratio | 含义 |
|---|---|
| `< 1` | treatment 更快。 |
| `= 1` | 没变化。 |
| `> 1` | treatment 更慢。 |

geomean treatment/control：

```text
geomean = exp(mean(log(ratio_1), log(ratio_2), ..., log(ratio_N)))
```

它是 benchmark ratio 的几何平均，不是总时间相除。下文的 `geomean` 默认报告 ratio 本身。
如果换成百分比，必须区分：

```text
time reduction      = (1 - ratio) * 100%
reciprocal speedup  = (1 / ratio - 1) * 100%
```

本文 per-case 表中的 `speedup` 使用 reciprocal speedup。

## 6. 实验结果

### 实验 1：ABI completeness 和 correctness

目的：确认已有 ARM64 module ABI 的 25 个 target 都能由 LLVM emit，并且 full micro runtime
correctness 通过。

做法：

- 本地 rebuild LLVM，并跑 targeted FileCheck。
- 用 Makefile 生成 final combined treatment object。
- 在 AWS ARM64 `t4g.small` 上跑 full micro correctness。
- treatment 使用 `RUNTIMES=native kernel`，`SAMPLES=1 WARMUPS=0 INNER_REPEAT=1`。

结果：

| metric | value |
|---|---:|
| LLVM build | pass |
| targeted FileCheck | pass |
| final object count | 34 |
| `bpf_x86_*` symbols | 0 |
| AWS benchmarks | 34 |
| runtime samples | 68 |
| bad samples | 0 |
| AWS wall time | 379 seconds |
| estimated cost | `0.002142988 USD` |

Takeaway：

```text
已有 ABI 的 25 个 ARM64 target 已完成 LLVM implementation 和 development-grade full micro correctness。
```

这个实验只证明 correctness，不证明性能收益。

### 实验 2：family-only same-LLC attribution

目的：每次只打开一个 family 的 selector，与 same-LLC `all=disable` control 比较，判断单个
family 是否有独立性能信号。

做法：

- groups：`baseline`、`control-disabled`、11 个 family-only treatment。
- 每个 treatment 都先 `all=disable`，再 force 一个 selector policy。
- AWS ARM64 full micro，`RUNTIMES=native kernel`，`SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000`。
- 13 个 AWS group 全部完成，2652 个 runtime sample，0 bad sample。

结果，ratio 小于 1 表示 treatment 更快：

| treatment | affected benchmarks | ARM64 refs | kernel all ratio | kernel affected ratio | takeaway |
|---|---:|---:|---:|---:|---|
| `REV / unary=force` | 1 | 2 | 1.011896267 | 1.016393443 | 不是性能 win。 |
| `EXTR / rotate=force` | 10 | 10 | 0.982282564 | 0.920357048 | 明确正向信号。 |
| `UBFM / bextr=force` | 12 | 12 | 1.002549851 | 0.999867703 | 基本中性。 |
| `LDR / wide-load=force` | 24 | 27 | 0.969922486 | 0.969490539 | 正向信号。 |
| `LDR / direct-load=force` | 2 | 5 | 0.988429307 | 0.975900073 | 小样本，不作为默认策略核心证据。 |
| `STR / direct-store=force` | 2 | 5 | 0.999048242 | 1.000000000 | 中性。 |
| `LDP/STP / pair-mem=force` | 2 | 2 | 0.996459491 | 0.998865570 | 中性。 |
| `CSEL / cmov=force` | 1 | 2 | 0.987715561 | 0.928571429 | 只有单 case 信号，不足以默认启用。 |
| `CCMP/CMP/CSET / ccmp=force` | 2 | 6 | 0.995866053 | 1.007685031 | 不是性能 win。 |
| `MOV / mov=force` | 0 | 0 | 0.998393325 | N/A | full micro 无自然命中。 |
| `PRFM / prefetch=force` | 33 | 33 | 1.009434119 | 1.009656628 | 略慢，不默认启用。 |

Takeaway：

```text
单 family 里最值得保留的是 EXTR 和 selected LDR。PRFM 覆盖面大，但 family-only 不是收益来源。
```

### 实验 3：combined same-LLC attribution

目的：在实现早期，把当时已有 selector 组合打开，检查组合后是否仍然 correctness 通过，并观察
组合级性能。

做法：

- control：custom `llc` + `all=disable`。
- treatment：combined ARM64 selector policy。
- benchmark：full micro。
- runtime：`native kernel`。

结果：

| runtime | scope | benchmarks | geomean treatment/control |
|---|---|---:|---:|
| kernel | all | 34 | 0.9622314217 |
| kernel | affected | 33 | 0.9621843369 |
| native | all | 34 | 0.9831061409 |
| native | affected | 33 | 0.9834447279 |

Takeaway：

```text
组合打开有正向 development-grade 信号，但该实验不能拆分每个 family 的因果贡献。
```

这个实验后来被 family-only、true all-on、targeted JIT dump 进一步细化。

### 实验 4：true all-on same-LLC attribution

目的：把已有 selector 全部打开，记录每个 benchmark 实际触发的 kinsn，并用 3 轮独立 AWS run
检查结果稳定性。

做法：

- groups：`baseline`、`control-disabled`、`treatment-true-all-on`。
- repetitions：3。
- AWS runs：9。
- full micro：34 benchmark。
- `RUNTIMES=native kernel`，`SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000`。
- total runtime samples：1836。
- bad samples：0。

Object isolation：

| group | objects | ARM64 relocations | x86 relocations |
|---|---:|---:|---:|
| `control-disabled` | 34 | 0 | 0 |
| `treatment-true-all-on` | 34 | 396 | 0 |

Kernel all geomean：

| rep | treatment/control |
|---:|---:|
| 1 | 0.939098387 |
| 2 | 0.935947497 |
| 3 | 0.945958541 |
| median | 0.939098387 |

Native all geomean median 是 `1.003011563`。这说明主要信号来自 kernel BPF/JIT path，而不是
userspace native 环境漂移。

Per-benchmark 稳定性：

| category | count |
|---|---:|
| 3 轮都 faster | 15 |
| 3 轮都 slower | 6 |
| 3 轮 equal | 4 |
| mixed | 9 |

代表性加速 case：

| benchmark | hit families | median kernel ratio | speedup | takeaway |
|---|---|---:|---:|---|
| `siphash_rotate64_mixer` | `EXTR,LDR,PRFM` | 0.528302 | +89.29% | rotate-heavy；主要来自 `EXTR`。 |
| `packet_record_bounds_window` | `LDR,PRFM` | 0.577259 | +73.23% | load 合成场景；主要来自 selected `LDR`。 |
| `flow_5tuple_rss_hash` | `EXTR,PRFM,UBFM` | 0.812500 | +23.08% | 主要来自 `EXTR`。 |
| `trace_event_type_switch_dispatch` | `LDR,PRFM` | 0.875358 | +14.24% | selected `LDR` 正向，但仍需 JIT 级解释。 |

代表性慢速 case：

| benchmark | hit families | median kernel ratio | slowdown | takeaway |
|---|---|---:|---:|---|
| `payload_prefix_memcmp_scan` | `EXTR,LDR,PRFM` | 1.128920 | -11.42% | family-only 显示主要风险来自 `PRFM`。 |
| `simple_packet` | `PRFM` | 1.071429 | -6.67% | PRFM-only 负例。 |
| `bpftrace_string_search_prefix_scan` | `EXTR,LDR,PRFM` | 1.052326 | -4.97% | 多个 selector 单独也略慢；不适合默认扩大。 |
| `sorted_rule_binary_search` | `LDR,PRFM` | 1.030848 | -2.99% | PRFM 是主要风险。 |
| `cilium_socket_lb_service_select` | `CCMP/CMP/CSET,LDR,PRFM,UBFM` | 1.017408 | -1.71% | `CCMP` 和 `LDR` 都有风险信号。 |

Takeaway：

```text
true all-on 整体更快，但不是所有 family 都值得默认启用。全开结果必须用 family-only 和 native JIT dump 拆解。
```

### 实验 5：targeted native JIT dump attribution

目的：对代表性快 / 慢 case 做 native instruction 级对比，解释为什么快或慢。

做法：

- 只选 4 个代表性 benchmark，不作为新的 paper-grade performance run。
- 对比 same-LLC control 和 true all-on treatment。
- 保存 `xlated` BPF dump、native JIT dump、mnemonic count。
- AWS ARM64 `t4g.small`，`SAMPLES=1 WARMUPS=0 INNER_REPEAT=100000`。

结果：

| benchmark | control ns | treatment ns | ratio | speedup | xlated delta | jited delta | native insn delta | key mnemonic delta |
|---|---:|---:|---:|---:|---:|---:|---:|---|
| `siphash_rotate64_mixer` | 173 | 84 | 0.485549 | +105.95% | -3672 B | -2344 B | -586 | `ror +116`, `lsl -172`, `lsr -116`, `orr -172` |
| `packet_record_bounds_window` | 371 | 198 | 0.533693 | +87.37% | -376 B | -232 B | -58 | `ldrb -28`, `lsl -20`, `orr -20`, `ldr +6`, `ldrh +2` |
| `payload_prefix_memcmp_scan` | 309 | 321 | 1.038835 | -3.74% | +32 B | -16 B | -4 | `prfm +5`, `ror +2` |
| `simple_packet` | 15 | 15 | 1.000000 | 0.00% | +32 B | +8 B | +2 | `prfm +2` |

Takeaway：

- `EXTR` 收益明确：rotate-heavy shift/or sequence 被 native `ror` 替换。
- selected `LDR` 收益明确：byte-load/shift/or 合成被更短 load sequence 替换。
- `PRFM` 不应默认打开：`simple_packet` 只额外引入 `prfm`，没有 latency 可隐藏。
- code size 变短不是充分条件：`payload_prefix_memcmp_scan` native instruction 略少，但 hot path
  多了 `prfm`，runtime 仍变慢。

### 实验 6：default candidate policy attribution

目的：决定默认策略是否只启用 `EXTR + selected LDR`，还是加入 `CSEL`。

做法：

- 比较四组：`baseline`、`control-disabled`、`candidate-conservative`、`candidate-expanded`。
- `candidate-conservative`：`EXTR + selected LDR`，即 `rotate,wide-load,direct-load`。
- `candidate-expanded`：conservative 再加 `cmov=force`，即额外打开 `CSEL`。
- 3 轮 AWS ARM64 full micro，`SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000`。
- total runtime samples：2448。
- bad samples：0。

Object result：

| group | ARM64 relocations | x86 relocations | family counts |
|---|---:|---:|---|
| `control-disabled` | 0 | 0 | none |
| `candidate-conservative` | 234 | 0 | `EXTR=162`, `LDR=72` |
| `candidate-expanded` | 238 | 0 | `EXTR=162`, `LDR=72`, `CSEL=4` |

Geomean stability：

| comparison | runtime | scope | median ratio | all reps faster |
|---|---|---|---:|---|
| conservative / control | kernel | all | 0.940471563 | yes |
| conservative / control | native | all | 0.999972404 | no |
| expanded / control | kernel | all | 0.932466234 | yes |
| expanded / control | native | all | 1.015307844 | no |
| expanded / conservative | kernel | all | 1.000359815 | no |
| expanded / conservative | kernel | CSEL | 1.000000000 | no |

Takeaway：

```text
EXTR + selected LDR 是当前有证据支持的默认候选。CSEL 相对该候选没有稳定额外收益，不应默认启用。
```

## 7. 当前解释和默认策略

当前有证据支持的默认策略：

```text
EXTR + selected LDR
```

理由：

| family | 当前判断 | 默认策略 |
|---|---|---|
| `EXTR` | family-only affected geomean `0.920357048`；JIT dump 证明 rotate shift/or 变成 `ror`。 | 默认启用。 |
| selected `LDR` | family-only affected geomean `0.969490539`；JIT dump 证明 byte-load/shift/or 合成变短。 | 默认启用。 |
| `PRFM` | family-only affected geomean `1.009656628`；JIT dump 显示慢 case 多了无收益 `prfm`。 | 不默认启用。 |
| `CCMP/CMP/CSET` | affected geomean `1.007685031`，存在慢 case。 | 不默认启用。 |
| `CSEL` | 只有单 benchmark 信号，加入默认候选没有稳定额外收益。 | 不默认启用。 |
| `UBFM` | 基本中性。 | 不默认启用。 |
| `REV` | 命中少，family-only 略慢。 | 不默认启用。 |
| `STR` | 基本中性。 | 不默认启用。 |
| `LDP/STP` | 基本中性。 | 不默认启用。 |
| `MOV` | micro 无自然命中。 | 不默认启用。 |

## 8. 未完成事项

当前结果是 development-grade micro benchmark 结论，不是 paper-grade 或 e2e 结论。

后续需要：

1. 对 `CCMP/CMP/CSET`、`CSEL`、`UBFM`、`STR`、`LDP/STP` 补 targeted native JIT dump，明确为什么中性或变慢。
2. 设计 ARM64 corpus / e2e benchmark。如果只是测 kernel pass 在 corpus 上的收益，不一定使用当前 LLVM ARM backend；如果要测 LLVM lowering，必须让 corpus object 由 custom `llc` 生成并实际触发 `bpf_arm64_*`。
3. 如果要默认启用 `EXTR + selected LDR`，需要把默认 policy、guard 条件和 regression gate 固化。

## 9. 数据位置

本地技术报告：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/group-meeting-2026-05-29.md
```

关键实验目录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-candidate-default-policy-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-29-arm64-targeted-jit-dump-attribution
```

关键 analysis 文件：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion/analysis/final-aws-correctness-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution/analysis/family-effect-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/geomean-stability.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution/analysis/ratio-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-candidate-default-policy-attribution/analysis/geomean-stability.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-29-arm64-targeted-jit-dump-attribution/analysis/jit-size-exec-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-05-29-arm64-targeted-jit-dump-attribution/analysis/mnemonic-delta.tsv
```
