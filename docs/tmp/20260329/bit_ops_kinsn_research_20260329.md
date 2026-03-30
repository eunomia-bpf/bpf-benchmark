# 2026-03-29 bit-ops kinsn research

## Scope

- 目标：评估 `POPCNT/CLZ/CTZ + PDEP/PEXT + SHRX/SHLX` 在 BPF 程序里的优化价值。
- 约束：只做静态调研，不改代码，不跑 VM。
- 输入：
  - 读取了两份中断 session 历史：
    - `/home/yunwei37/.codex/sessions/2026/03/29/rollout-2026-03-29T18-32-47-019d3c5f-3a93-7fe1-ae68-365d93988c0b.jsonl`
    - `/home/yunwei37/.codex/sessions/2026/03/29/rollout-2026-03-29T18-52-12-019d3c71-024d-7ba3-8c3c-19cff622693a.jsonl`
  - 对 `corpus/build/` 下全部 `.bpf.o` 重新执行 `llvm-objdump -d` 扫描。

## Executive Summary

- 在当前 corpus 里，`POPCNT`、`CLZ/CTZ`、`PEXT/PDEP` 都没有扫描到可支撑投入的模式站点，主结论是：**现在不值得做新的 bit-op kinsn。**
- `SHRX/SHLX/SARX` 的站点很多，`3025` 个，但这组不是新机会：上游 x86 BPF JIT 已经在 `BPF_*SH|X` 的变量移位路径里直接发 `shrx/sarx/shlx`，条件是 `BMI2` 可用且 shift-count 不在 `rcx`。也就是说，这一类机会已经被内核 JIT 吃掉了。
- 如果将来必须在这组里挑一个方向继续看，只有 `CLZ/CTZ` 还勉强有“指令本身优雅、跨 x86/arm64 语义较清晰”的优点；但在当前 corpus 上仍然没有数据支撑。
- `PDEP/PEXT` 应该直接排除：站点为零，AMD Zen1/2 上还有明显性能悬崖，ARM64 也没有对等单指令。

## 历史工作继承

这次不是从零开始，前两次 session 里最有价值的两个结论已经继承并复核：

1. `18:32` 那次 session 已经确认：
   - 现有 kinsn plumbing 的主路径在 `daemon/src/pass.rs`、`daemon/src/kfunc_discovery.rs`、`daemon/src/passes/*.rs`、`module/x86/*.c`、`module/arm64/*.c`。
   - 现有 x86/arm64 模块和 pass 的代码体量，可以作为新 kinsn 复杂度的 baseline。
   - 对严格多 bit `PDEP/PEXT-like` 连续模式的初扫结果是 `candidates 0`。

2. `18:52` 那次 session 已经确认：
   - corpus 里的变量移位站点很多，数量级在几千级。
   - 只在 `loxilb` 里扫到 `24` 个“单 bit 插入”样式的序列，但不是严格多 bit `PDEP/PEXT` 候选。

本次重新在当前工作树上复扫后，以上两个方向的结论都成立。

## Method

- 扫描范围：`917` 个 `.bpf.o`，覆盖 `23` 个 repo 分组。
- 主统计基于 `llvm-objdump -d corpus/build/**.bpf.o` 的文本反汇编，按 repo 聚合。
- 模式定义：
  - `popcount`：连续 `shift + and 1 + add` 聚合 bit count 的序列。
  - `clz/ctz loop`：带回边的循环，循环体内有 `<<= 1` 或 `>>= 1`、零比较、计数器 `+= 1` 或 `-= 1`。
  - `pext-like`：连续多个单-bit extract，source bit 非连续而 output bit 连续。
  - `pdep-like`：连续多个单-bit deposit，source bit 连续而 output bit 非连续。
  - `variable shift`：`rX <<= rY` / `rX >>= rY` / `rX s>>= rY`。
- 辅助检查：
  - SWAR popcount 常量组 `0x5555.. / 0x3333.. / 0xf0f0.. / 0x0101..` 全量搜索。
  - 反汇编文本里 `popcount|clz|ctz|ffs|fls` 名称搜索。

## Corpus Site Count

### Repo-level summary

| repo | `.bpf.o` count | popcount | clz/ctz loop | pdep-like | pext-like | variable shift |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| KubeArmor | 3 | 0 | 0 | 0 | 0 | 66 |
| bcc | 57 | 0 | 0 | 0 | 0 | 121 |
| bpftrace | 7 | 0 | 0 | 0 | 0 | 0 |
| calico | 8 | 0 | 0 | 0 | 0 | 8 |
| cilium | 7 | 0 | 0 | 0 | 0 | 452 |
| coroot-node-agent | 1 | 0 | 0 | 0 | 0 | 18 |
| datadog-agent | 2 | 0 | 0 | 0 | 0 | 0 |
| katran | 5 | 0 | 0 | 0 | 0 | 0 |
| libbpf-bootstrap | 14 | 0 | 0 | 0 | 0 | 4 |
| linux-selftests | 656 | 0 | 0 | 0 | 0 | 103 |
| loxilb | 3 | 0 | 0 | 0 | 0 | 38 |
| manual-test | 2 | 0 | 0 | 0 | 0 | 0 |
| netbird | 2 | 0 | 0 | 0 | 0 | 0 |
| opentelemetry-ebpf-profiler | 3 | 0 | 0 | 0 | 0 | 6 |
| scx | 4 | 0 | 0 | 0 | 0 | 110 |
| suricata | 2 | 0 | 0 | 0 | 0 | 0 |
| systemd | 10 | 0 | 0 | 0 | 0 | 1 |
| tetragon | 86 | 0 | 0 | 0 | 0 | 2022 |
| tracee | 3 | 0 | 0 | 0 | 0 | 73 |
| tubular | 1 | 0 | 0 | 0 | 0 | 0 |
| xdp-examples | 5 | 0 | 0 | 0 | 0 | 0 |
| xdp-tools | 13 | 0 | 0 | 0 | 0 | 3 |
| xdp-tutorial | 23 | 0 | 0 | 0 | 0 | 0 |
| **total** | **917** | **0** | **0** | **0** | **0** | **3025** |

### Notes per family

#### 1. POPCNT

- 严格 `shift + and 1 + add` 聚合模式：`0` site。
- SWAR-popcount 常量组搜索：`0` hit。
- 反汇编文本里的 `popcount|ffs|fls|clz|ctz` 名称搜索：`0` hit。

结论：当前 corpus 里没有看见值得为 `bpf_popcnt64` 投入的真实工作负载。

#### 2. CLZ / CTZ

- 回边循环 + `<<=1`/`>>=1` + zero-compare + counter-update 的 heuristic：`0` site。

结论：当前 corpus 里没有看见 `__builtin_clz*` / `__builtin_ctz*` 被展开成 loop 的痕迹。

#### 3. PDEP / PEXT

- 严格多 bit `pdep-like`：`0` site。
- 严格多 bit `pext-like`：`0` site。

辅助观察：

- 用更宽松的四指令模板再扫一遍，能找到 `24` 个 `single_bit_deposit_like`，全部来自 `loxilb`。
- 代表性序列是：

```text
r2 &= 0xfe
r1 >>= 0x6
r1 &= 0x1
r1 |= r2
```

这类只是“清掉 LSB 后塞回一个单 bit”，不是多 bit gather/scatter，不足以支撑 `PDEP/PEXT`。

#### 4. SHRX / SHLX / SARX

- 变量移位总数：`3025`。
- 主要集中在：
  - `tetragon`: `2022`
  - `cilium`: `452`
  - `bcc`: `121`
  - `scx`: `110`
  - `linux-selftests`: `103`

分布细节：

- `32-bit` variable shift：`201`
- `64-bit` variable shift：`2824`
- `arithmetic right shift`：`81`

但这组站点**不构成新增 kinsn 机会**。当前 upstream x86 JIT 已经在 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2022-2046` 中，对 `BPF_LSH|X / BPF_RSH|X / BPF_ARSH|X` 直接走：

```c
/* BMI2 shifts aren't better when shift count is already in rcx */
if (boot_cpu_has(X86_FEATURE_BMI2) && src_reg != BPF_REG_4) {
    /* shrx/sarx/shlx dst_reg, dst_reg, src_reg */
    emit_shiftx(&prog, dst_reg, src_reg, w, op);
}
```

所以 `SHRX/SHLX/SARX` 的“静态可替换 site count”虽然很大，但**增量收益已经接近零**。

ARM64 侧也是同样逻辑：变量移位本来就能直接映射到普通 ISA 指令 `LSLV/LSRV/ASRV`，不需要为了这类语义再加一层 kinsn。

## 实现复杂度

### 需要几个 kinsn

- 若硬要覆盖这批新语义，最少是 `5` 个 kinsn：
  - `bpf_popcnt64`
  - `bpf_clz64`
  - `bpf_ctz64`
  - `bpf_pdep64`
  - `bpf_pext64`
- `SHRX/SHLX` 不需要新 kinsn，因为原生 BPF ISA 已经有变量移位 opcode，x86 JIT 也已经直接发 BMI2 指令。

### 现有代码基线

现有相关模块和 pass 的体量：

| baseline | x86 module LoC | arm64 module LoC | daemon pass LoC |
| --- | ---: | ---: | ---: |
| `extract` | 142 | 106 | 871 |
| `rotate` | 140 | 111 | 832 |
| `cond_select` | 161 | 121 | 442 |
| `endian` | 265 | 320 | 989 |

这些 baseline 已经说明：哪怕是“语义相对简单”的 kinsn，也不是几十行的小补丁。

### 新增 kinsn 的大致复杂度

| target | x86 lowering | ARM64 lowering | x86 侧预估 | daemon pass 难度 | 备注 |
| --- | --- | --- | --- | --- | --- |
| `bpf_popcnt64` | `POPCNT` | 没有等价单条 GPR 指令；要么用 AdvSIMD `CNT + horizontal sum`，要么退回 SWAR | 中 | 中 | ARM64 是主要复杂度来源 |
| `bpf_clz64` | `LZCNT` | `CLZ` | 中 | 中高 | 需要严格定义 zero-input 语义 |
| `bpf_ctz64` | `TZCNT` | `RBIT + CLZ` | 中 | 中高 | zero-input 和 width 语义要锁死 |
| `bpf_pdep64` | `PDEP` | 无直接等价单指令 | 中 | 高 | ARM64 几乎没有优雅 native path |
| `bpf_pext64` | `PEXT` | 无直接等价单指令 | 中 | 高 | 模式识别最难，收益又最不稳定 |

这里的“x86 侧预估 = 中”，不是说工作量小，而是说单个 emitter 大概率会落在现有 `extract/rotate/select` 的量级，也就是每个大约 `120-180` 行上下。五个加起来，x86 侧单独就接近 `700-800` 行。

### daemon / plumbing 侧复杂度

新增任何一个 kinsn，至少都要改下面这些固定路径：

- `daemon/src/pass.rs`
  - 给 `KinsnRegistry` 增加新 `*_btf_id`
  - 扩 `target_name_for_pass()`
  - 必要时扩 `PlatformCapabilities`
- `daemon/src/kfunc_discovery.rs`
  - 扩 `KNOWN_KINSNS`
  - 扩 discovery 初始化和赋值逻辑
- `daemon/src/test_utils.rs`
  - 扩 permissive test context 的 mock BTF IDs / platform flags
- `daemon/src/pass_tests.rs`
  - 扩 registry / discovery / fd transport 测试
- `daemon/src/passes/*.rs`
  - 每个语义基本都要独立 pass 或至少独立扫描逻辑
- `module/x86/*.c` 和 `module/arm64/*.c`
  - 各自新模块、新 Makefile 项、新 BTF 导出、新 emitter

另外，当前 `PlatformCapabilities` 只跟踪了 `bmi1/bmi2/cmov/movbe/rorx`，并没有 `popcnt/lzcnt/tzcnt` 的显式 feature gate。也就是说，`POPCNT/CLZ/CTZ` 不是只写 emitter 就行，还要先补 CPU feature plumbing。

## 预期收益

| family | 理论单-site收益 | 当前 corpus 加权后的真实收益 |
| --- | --- | --- |
| `POPCNT` | 软件序列可从多条 `shift/and/add` 收缩到 `1 x POPCNT`，延迟通常在几个 cycle 量级 | `0`，因为 corpus 里根本没有 site |
| `CLZ/CTZ` | loop 或 binary-search 样式可收缩到 `1 x LZCNT/TZCNT`，ARM64 也能到 `1-2` 条 | `0`，因为 corpus 里没有 site |
| `PDEP/PEXT` | 多 bit gather/scatter 理论上可以“很多条变一条” | `0`，因为 corpus 里没有 site |
| `SHRX/SHLX/SARX` | 理论上可避免把 shift-count 挪到 `cl`，也不改 flags | **增量收益近似 `0`**，因为 upstream x86 JIT 已经这么做了 |

更直接地说：

- `POPCNT/CLZ/CTZ/PDEP/PEXT` 的问题不是“单-site 不够快”，而是“当前 corpus 根本没有 site”。
- `SHRX/SHLX` 的问题则相反：site 很多，但已经被上游 JIT 吃掉了，再做 kinsn 只会重复已有优化。

## 风险

- CPU feature 风险：
  - `POPCNT` 需要 `popcnt`
  - `LZCNT` 需要 `abm/lzcnt`
  - `TZCNT` 需要 `bmi1`
  - `PDEP/PEXT/SHRX/SHLX/SARX` 需要 `bmi2`
- 语义风险：
  - `LZCNT/TZCNT` 对 zero-input 的返回值必须和 proof path 完全一致，不能偷换成 `BSR/BSF` 风格语义。
  - `32-bit` 和 `64-bit` 宽度语义要分清，尤其是上层 BPF 用 `wX` 时的 zero-extension。
- 微架构风险：
  - `PDEP/PEXT` 在 AMD Zen1/2 上有很差的吞吐/延迟表现，常见经验值是明显慢于 Intel，同样的 rewrite 可能在不同 CPU 上从收益变成回归。
- ARM64 风险：
  - `CLZ/CTZ` 还算顺手。
  - `POPCNT` 没有简单标量单指令。
  - `PDEP/PEXT` 没有自然对应指令，跨架构一致性和实现体量都差。
- verifier / rewrite 风险：
  - packed-call 基础设施本身是现成的，真正危险的是 pattern matcher 误判。
  - `popcnt/clz/ctz` 如果要跨 basic block 或 loop 做匹配，复杂度和错配风险都会显著高于现在的 `extract`。
  - `pdep/pext` 需要证明 source bits、mask、dst 保留位和寄存器活性都完全对齐，风险最大。

## 结论

### 是否值得做

- **`SHRX/SHLX/SARX`: 不值得做 kinsn。**
  - 理由不是“site 少”，而是“site 多但上游 x86 JIT 已经做了”。
- **`PDEP/PEXT`: 不值得做。**
  - 当前 corpus 严格候选为 `0`。
  - 只有 `loxilb` 里有 `24` 个单-bit 插入样式，远达不到为 `PDEP/PEXT` 建一整套 kinsn 的门槛。
  - AMD Zen1/2 风险和 ARM64 缺口都太大。
- **`POPCNT`: 当前不值得做。**
  - 当前 corpus 为 `0` site。
  - ARM64 没有干净的标量 native path。
- **`CLZ/CTZ`: 也不建议现在做，但如果将来必须从这批里选一个方向，优先级高于 `POPCNT/PDEP/PEXT`。**
  - 原因不是当前有收益，而是它们至少在 x86/ARM64 上都有比较清楚的 ISA 语义。

### 建议优先级

如果必须给这组排优先级，我建议：

1. `SHRX/SHLX`: `N/A`
   - 不做，因为 upstream x86 JIT 已覆盖。
2. `CLZ/CTZ`: `very low`
   - 只在未来 corpus 或真实 workload 出现非零 site 时再重开。
3. `POPCNT`: `very low`
   - 需要先证明 workload 真有站点，再解决 ARM64 路径。
4. `PDEP/PEXT`: `do not pursue`
   - 现有数据和跨 CPU 风险都不支持。

## Final Call

对当前 `bpf-benchmark` 项目来说，这组 bit-op 里**没有一个值得进入近期 kinsn 路线图**。

最应该写进 roadmap 的不是“新增 `POPCNT/CLZ/CTZ/PDEP/PEXT/SHRX/SHLX`”，而是下面这句结论：

- `SHRX/SHLX/SARX` 已由 upstream x86 BPF JIT 覆盖。
- `POPCNT/CLZ/CTZ/PDEP/PEXT` 在当前 corpus 上没有站点支撑。
- 因此这批工作现在的 ROI 明显低于已有的热点 pass / benchmark gap。
