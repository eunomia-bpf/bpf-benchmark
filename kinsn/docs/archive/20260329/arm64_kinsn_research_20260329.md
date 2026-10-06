# ARM64 CCMP/MADD/MSUB/UBFX/BFI 在 BPF 程序中的优化价值调研

日期：2026-03-29

## 范围与方法

- 本次只做静态调研，不改代码，不跑 VM。
- 读取了两段历史 session：
  - `/home/yunwei37/.codex/sessions/2026/03/29/rollout-2026-03-29T18-32-53-019d3c5f-538f-7de2-aee4-7d0f51468dc0.jsonl`
  - `/home/yunwei37/.codex/sessions/2026/03/29/rollout-2026-03-29T18-52-16-019d3c71-1116-7632-8f5d-f1dbdf14d86f.jsonl`
- 上一次 session 其实已经跑出一版完整 corpus 扫描，但没有落盘；本次把那段 Python/`llvm-objdump -dr --triple=bpfel` 统计结果恢复出来，并对当前 tree 做 spot check。
- 当前 `corpus/build` 下共有 **917** 个 `.bpf.o`，repo 分布与历史扫描一致。

### 计数口径

- `CCMP`
  - 统计“连续、前向、same-target 的 compare+branch 链”，长度 `>= 2`。
  - 目标是估计可被 `cmp; ccmp; ...; b.<cond>` 吃掉的中间 branch 数。
  - 这是保守口径：排除了 interior edge 进入链中部的情况。
- `MADD`
  - 统计直接两条指令序列：`rD *= rX; rD += rY`。
  - 这是一个可一条 `madd` 覆盖的强匹配。
- `MSUB`
  - 历史扫描口径是直接 two-insn same-dst：`rD *= rX; rD -= rY`。
  - 该口径下结果为 0。注意这会漏掉更宽松的“`tmp *= x; acc -= tmp`”形式，因此这里的 0 是**保守下界**，不是“理论上绝对没有 MSUB 机会”。
- `UBFX`
  - 统计 `>> imm` 后接 contiguous-lowmask `& mask` 的 bitfield extract。
  - 分成两类：
    - `in_place`: `rX >>= imm; rX &= mask`
    - `with_copy`: `rT = rS; rT >>= imm; rT &= mask`
- `BFI`
  - 统计强 5 指令 idiom：
    - `tmp = src`
    - `tmp &= lowmask`
    - `tmp <<= lsb`
    - `dst &= ~(lowmask << lsb)`
    - `dst |= tmp`
  - 这是一个很强的 canonical insert 口径，误报低，但会漏掉更松散的插位模式。

结论上，这套口径更适合做 first-wave 决策，而不是宣称“所有理论可优化位点”。

## 现有代码基线

现有 kinsn v2 机制已经提供了一个很清楚的复杂度基线：

- 默认 pipeline 已经有 `rotate` / `cond_select` / `extract` / `branch_flip` 等 pass。
  - 见 `daemon/src/passes/mod.rs`
- kinsn 目标发现、BTF transport、packed-call 支持已经在 daemon 中成形。
  - 见 `daemon/src/pass.rs`
  - 见 `daemon/src/kfunc_discovery.rs`
- 当前 fallback 语义是：
  - 无 JIT 或当前架构无 native emit：lower 成普通 BPF 序列
  - 有 native emit：保留 kinsn site 给 JIT
  - 见 `docs/kinsn-design.md`

这意味着：

- **ARM64-only target 在正确性上不是问题**，因为 generic fallback 会退回普通 BPF。
- 但 **ARM64-only target 在工程上仍有代价**，因为 daemon registry / discovery / tests / module Makefile / unit test 枚举都要补。

### 现有实现规模参考

| 现有目标 | Rust pass LOC | ARM64 module LOC | 复杂度特征 |
| --- | ---: | ---: | --- |
| `cond_select` | 442 | 121 | 固定形态，主要是 CFG 安全检查 |
| `extract` | 871 | 106 | 简单 pattern，但要做 branch fixup |
| `rotate` | 832 | 111 | 需要 tmp-reg live-out 检查 |
| `branch_flip` | 1168 | n/a | branch/profile 逻辑更重 |

大致可以把新工作的复杂度放到这个坐标系里看：

- 纯固定形态、payload 小、无 liveness 的，接近 `cond_select`
- 需要 tmp/liveness 或 branch fixup 的，接近 `extract` / `rotate`
- 需要 branch-chain / mixed compare / payload 变长的，复杂度会逼近甚至超过 `branch_flip`

## Corpus Site Count

### 总量

| 指标 | 数量 |
| --- | ---: |
| `.bpf.o` 文件数 | 917 |
| `CCMP` sites | 4957 |
| `CCMP` 可消除中间 branches | 6228 |
| `MADD` direct two-insn sites | 47 |
| `MSUB` direct same-dst sites | 0 |
| `UBFX` total sites | 321 |
| `UBFX` in-place | 247 |
| `UBFX` with-copy | 74 |
| `BFI` strong sites | 0 |

### 按 repo 分组

| Repo | `.bpf.o` | CCMP sites | Saved branches | MADD | MSUB | UBFX total | UBFX in-place | UBFX with-copy | BFI |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `KubeArmor` | 3 | 153 | 431 | 0 | 0 | 0 | 0 | 0 | 0 |
| `bcc` | 57 | 5 | 6 | 0 | 0 | 4 | 3 | 1 | 0 |
| `bpftrace` | 7 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| `calico` | 8 | 36 | 44 | 0 | 0 | 13 | 1 | 12 | 0 |
| `cilium` | 7 | 342 | 357 | 0 | 0 | 0 | 0 | 0 | 0 |
| `coroot-node-agent` | 1 | 2002 | 2739 | 0 | 0 | 0 | 0 | 0 | 0 |
| `datadog-agent` | 2 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| `katran` | 5 | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 0 |
| `libbpf-bootstrap` | 14 | 0 | 0 | 0 | 0 | 2 | 2 | 0 | 0 |
| `linux-selftests` | 656 | 165 | 170 | 1 | 0 | 18 | 14 | 4 | 0 |
| `loxilb` | 3 | 37 | 37 | 0 | 0 | 34 | 32 | 2 | 0 |
| `manual-test` | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `netbird` | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `opentelemetry-ebpf-profiler` | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `scx` | 4 | 60 | 64 | 18 | 0 | 5 | 0 | 5 | 0 |
| `suricata` | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `systemd` | 10 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `tetragon` | 86 | 2093 | 2313 | 0 | 0 | 198 | 148 | 50 | 0 |
| `tracee` | 3 | 48 | 51 | 0 | 0 | 47 | 47 | 0 | 0 |
| `tubular` | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `xdp-examples` | 5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `xdp-tools` | 13 | 12 | 12 | 28 | 0 | 0 | 0 | 0 | 0 |
| `xdp-tutorial` | 23 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

### 读表重点

- `CCMP` 极度集中：
  - `coroot-node-agent` 单个对象就有 **2002** 个 site
  - `tetragon` 有 **2093** 个 site
  - 两者合计 **4095 / 4957 = 82.6%**
- `MADD` 很少，而且高度集中在两类 workload：
  - `xdp-tools`: 28
  - `scx`: 18
  - `linux-selftests`: 1
- `UBFX` 中等偏多，但主要集中在需要大量 field parsing 的 tracing/security/networking repo：
  - `tetragon`: 198
  - `tracee`: 47
  - `loxilb`: 34
  - `linux-selftests`: 18
  - `calico`: 13
- `BFI` 在强 canonical 口径下为 **0**

## 分项分析

### 1. CCMP

#### 价值

- 这是本次唯一一个**位点多到足以影响真实 workload**的候选。
- 4957 个 site 对应 6228 个可消除的中间 branch，上限收益明显高于 MADD / BFI。
- 对 ARM64 来说，`ccmp` 的价值不是“省一条 ALU”，而是：
  - 减少 branch 数
  - 降低分支预测压力
  - 缩短短路判断链的 I-cache / frontend 占用
- 从 sample 看，高频 case 不只是“连续判零”，还包括：
  - `reg != reg`
  - `reg == 0`
  - mixed compare form，但 target 相同

#### 实现复杂度

- **如果走当前 daemon + kinsn 路线，复杂度是本组最高。**
- daemon 侧需要：
  - 新增 1 个 pass，做 same-target compare-chain 识别
  - 做 interior target / CFG 安全检查
  - 处理 mixed compare opcode、imm/reg 源、分支极性
  - 很可能还要限制 chain 长度
- kinsn/ABI 侧是最大难点：
  - 当前 packed ABI 本质上是一个固定 64-bit payload
  - 现有 `rotate/select/extract` 都是在 payload 里塞几个固定字段
  - `CCMP` 的 compare chain 是**变长**的，天然和当前 packed payload 不匹配
- ARM64 module emit 反而不算最难：
  - 一旦 payload 能表达，native emit 只是 `cmp + ccmp + ... + b.<cond>`
  - 指令条数不多

#### 风险

- **payload/transport 风险最高**
  - 如果想覆盖通用 2/3/4 compare chain，很可能需要多个固定 arity descriptor
  - 或者引入超出当前 packed-call 的 transport
- **条件语义风险**
  - `CCMP` 链要求把 BPF Jcc 的语义精确映射到 ARM64 flags
  - mixed `eq/ne/ugt/uge/...` 的组合不是所有都适合 first wave
- **CFG 风险**
  - compare 链里任何一条被外部跳转打进来，都会让融合失效
- **跨架构风险**
  - 如果这是 ARM64-only target，x86 大概率只能跳过 pass 或走普通 BPF fallback
  - correctness 没问题，但 cross-arch benchmark 对比会不对称

#### 判断

- **收益最高，但不适合直接做“完全通用的 CCMP kinsn”。**
- 如果要做 first wave，我更建议二选一：
  - ARM64 JIT-local peephole，只认 very-restricted same-target chain
  - 或者做固定 arity 的 `ccmp2/ccmp3` kinsn，而不是变长通用版

### 2. MADD

#### 价值

- direct two-insn site 只有 **47** 个。
- 主要是重复的索引/偏移计算模板，例如 `xdp-tools` 中典型的：

  ```text
  r1 *= r6
  r1 += r0
  ```

- 这类模式非常适合一条 `madd`，收益是：
  - 省 1 条指令
  - 少一个数据依赖节点
  - 对 tight index arithmetic 有一点 frontend / scheduler 帮助

#### 实现复杂度

- **中低**
- 按当前仓库风格实现，通常是：
  - 1 个新 pass
  - 1 个新 ARM64 module
  - 1 个新 kinsn target（或与 MSUB 共用一个模块 + mode bit）
  - `pass.rs` / `kfunc_discovery.rs` / `tests/unittest/rejit_kinsn.c` / `module/arm64/Makefile` 补齐
- 这类 payload 是固定小字段：
  - `dst`
  - `mul lhs`
  - `mul rhs`
  - `acc`
  - 可完全塞进现有 packed ABI
- ARM64 emit 很简单：
  - 一条 `madd`
- generic fallback 也很简单：
  - instantiate 回 `mul; add`

#### 风险

- 最大风险不是正确性，而是**收益太小**。
- 如果以后想扩到“`tmp *= x; acc += tmp`”这种 accumulator-distinct 形式，还要做 live-out 检查，不再是纯固定形态。

#### 判断

- **可以做，但优先级明显低于 CCMP。**
- 更像是“顺手收掉的局部 peephole”，不是需要单独排期的主力优化。

### 3. MSUB

#### 价值

- 按本次保守口径，direct same-dst two-insn site 为 **0**。
- 这和 ARM64 `msub` 的语义也一致：
  - `msub` 是 `Ra - Rn*Rm`
  - 而 BPF 里最常见的 two-insn 写法通常不是这个 accumulator 方向
- spot check 确实能看到更宽松的形态，例如 `scx` 里有：

  ```text
  r5 *= r3
  r4 -= r5
  ```

  这类可以视为潜在 `msub` 机会，但它依赖：
  - 乘积临时寄存器随后是否 dead
  - 是否值得用一个 ARM64-only peephole 吃掉

#### 实现复杂度

- 如果只做 same-dst 两条指令，复杂度很低，但没有 site。
- 如果做真正有意义的“temp multiply + accumulator subtract”：
  - 需要新识别器
  - 需要 liveness
  - 需要更严格的语义证明
  - 复杂度会接近 `rotate`

#### 判断

- **不建议 first wave 单独做。**
- 最多作为未来 `mul-accumulate fusion` 的一部分，和 `MADD` 一起统一设计。

### 4. UBFX

#### 价值

- 静态候选总数 **321**，不算少。
- 但这里有一个关键事实：
  - **仓库里已经有 `extract` pass**
  - **ARM64 已经有 `bpf_extract64` module emit**
  - **x86 也已经有对应的 `bpf_extract64` target**
- 也就是说，“UBFX 作为 canonical bitfield extract”这件事，**不是待做项，而是已落地项**。

当前剩余增量主要在：

- `in_place`: 247
  - 这类基本就是现有 `ExtractPass` 的覆盖面
- `with_copy`: 74
  - 这是更有价值的增量方向
  - 只要把 `ExtractPass` 从 2-insn 扩到 `mov + rsh + and` 三指令 copy form，就能吃掉这部分

#### 实现复杂度

- **如果只看新增工作，复杂度低于重做一个新 UBFX target。**
- 因为：
  - daemon 已经有 `ExtractPass`
  - ARM64 module 已经有 `bpf_extract64`
  - x86 target 也已有 fallback parity
- 实际新增更像是：
  - 扩展 `scan_extract_sites()`
  - 加一点 branch/liveness 安全检查
  - 补测试

#### 风险

- 风险已经比 CCMP/MADD 低得多，因为 transport / module / cross-arch parity 都已存在。
- 主要风险是：
  - 扩到 with-copy 后要确认 source/dst 关系与 live-out
  - 不要把非 contiguous mask 的 bit twiddling 误吃成 extract

#### 判断

- **UBFX 不该再作为“新 ARM64-only 优化”排期。**
- 如果想继续做，应该写成：
  - “扩展现有 `extract` pass 覆盖 copy form”
- 这属于低风险、小中收益的补强项。

### 5. BFI

#### 价值

- 按强 canonical field-insert 口径，**0 site**。
- 这说明至少在当前 corpus 中：
  - 编译器没有稳定地产生 clear-mask + shifted-insert 的强模式
  - 或者这些 field insert 被拆散在更长的逻辑中，不适合 first-wave peephole

#### 实现复杂度

- 不算特别高：
  - payload 只需要 `dst/src/lsb/width` 这一类固定字段
  - ARM64 emit 也是单条 `bfi`
- 但和 `UBFX` 不同，当前仓库里没有现成 pass / module / cross-arch target 可复用。

#### 风险

- 最大风险是**做出来也没地方用**。
- 如果为了“ARM64 指令覆盖度”引入 BFI target，会把发现/registry/tests/module 维护面扩大，但 corpus 没有对应收益。

#### 判断

- **不建议做。**

## 实现复杂度总结

### 按当前仓库架构估算

| 目标 | daemon pass | kinsn 数量 | ARM64 module emit | 额外 plumbing | 总体复杂度 |
| --- | --- | --- | --- | --- | --- |
| `CCMP` | 1 个新 pass，且最复杂 | 现实上需要 2-3 个 fixed-arity target 才合理 | 不难 | 高：registry/discovery/tests/payload 设计都重 | 高 |
| `MADD` | 1 个新 pass | 1 个 target，或与 `MSUB` 共模块 | 很简单 | 中：标准 kinsn plumbing | 中低 |
| `MSUB` | 若做有效版，也要 1 个 pass 且要 liveness | 1 个 target 或与 `MADD` 共用 | 很简单 | 中：但 site 稀少 | 中 |
| `UBFX` | 无需新 pass；更合理是扩展现有 `extract` | 0 个新增 target | 0 个新增 module | 低：主要是 pass/test 扩覆盖 | 低 |
| `BFI` | 1 个新 pass | 1 个新 target | 简单 | 中：但 corpus 为 0 | 中 |

### 一个重要的工程现实

对当前 repo 来说，新增 target 不只是写一个 emitter。至少还要同时动：

- `daemon/src/pass.rs`
- `daemon/src/kfunc_discovery.rs`
- `daemon/src/passes/mod.rs`
- `module/arm64/Makefile`
- `tests/unittest/rejit_kinsn.c`

所以 “site 很少但 target 很多” 的东西会非常亏。

## 预期收益总结

| 目标 | 预期收益 | 为什么 |
| --- | --- | --- |
| `CCMP` | 高 | 唯一一个有数千 site、数千可省 branch 的候选；真正能碰到 branch predictor / frontend |
| `MADD` | 低到中 | 只省 1 条指令，但 47 个 site 已经不算 0；适合顺手做 |
| `MSUB` | 低 | 直接 site 为 0；有意义的宽松形态需要更复杂识别 |
| `UBFX` 增量 | 中低 | 不是新 target；主要是把现有 `extract` 从 in-place 扩到 with-copy |
| `BFI` | 极低 | corpus 强模式为 0 |

## 风险总结

### ARM64-only 风险

- correctness 不是大问题，当前 kinsn v2 有 generic fallback。
- 但 benchmark 解释会变复杂：
  - ARM64 开了 target
  - x86 跳过或 lower 回普通 BPF
  - 不再是对称特性集

### verifier / proof 风险

- 所有新 pass 都必须保持当前 v2 kinsn 语义：
  - sidecar + packed call
  - verifier proof lowering
  - no silent fallback
- `CCMP` 风险最高，因为它直接跨多条 branch 语义做融合。
- `MADD/MSUB` 的主要 verifier 风险在于 temp/liveness。
- `UBFX` 扩展风险最低，因为现有 `extract` 路已经被证明可行。

### packed payload 风险

- 当前 packed ABI 非常适合：
  - `MADD`
  - `MSUB`
  - `UBFX`
  - `BFI`
- 当前 packed ABI **不适合完全通用的 `CCMP` compare-chain**。
- 这是为什么 `CCMP` 虽然 ROI 最高，但实现形态最容易失控。

## 结论

### 排序

1. **`CCMP` 值得做，但只能做 restricted first wave。**
   - 它是唯一一个位点数量足以带来可感知收益的 ARM64 专属优化。
   - 但不要直接做“通用变长 compare-chain kinsn”。
   - 更合理的落地方式是：
     - ARM64 JIT-local peephole，或
     - fixed-arity `ccmp2/ccmp3` kinsn

2. **`UBFX` 不是新工作重点；应把它视为“扩展现有 extract 覆盖面”。**
   - 当前 `extract` 已经把 in-place 这部分做掉了。
   - 真正还值得做的是 74 个 with-copy site。

3. **`MADD` 可以做，但更像二级优化。**
   - 实现不难，payload 也适配当前架构。
   - 但只有 47 个 direct site，收益远小于 `CCMP`。

4. **`MSUB` 和 `BFI` 都不应进入 first wave。**
   - `MSUB`：direct site 为 0，宽松形式需要额外 liveness/semantic work
   - `BFI`：强模式 0 site，做出来也缺少 corpus 回报

### 推荐落地顺序

如果目标是 OSDI 范围内的增量收益，而不是“把 ARM64 指令表补全”，我建议：

1. **先做 restricted `CCMP`**
2. **再扩展现有 `extract` 到 with-copy**
3. **最后再考虑 `MADD`**
4. **暂缓 `MSUB` / `BFI`**

这是当前 corpus 下，收益/复杂度比最合理的顺序。
