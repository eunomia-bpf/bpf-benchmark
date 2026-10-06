# SETcc/CSET kinsn 调研

日期：2026-04-30  
HEAD：`ddba9a58164187475e049aed47db36414461aaac`

## 结论

建议状态：`📝 调研完成（待实现）`。

`SETcc/CSET` 值得做，但应作为独立的 boolean materialization kinsn，而不是并入现有 `cond_select`。当前 supported runtime corpus 中有 **9417** 个强匹配 boolean-set site，集中在 Tetragon/Cilium/BCC/Calico；请求指定的 `corpus/bcf` + `runner/repos` broad census 中有 **28653** 个 raw object-level site。大多数是 `MOV 1; Jcc +1; MOV 0`，正好对应 `cmp/test; setcc` 或 `cmp/test; cset`。

核心原因：

- `cond_select` 是 “A/B select based on condition value”，当前实现还要求 `JEQ/JNE reg, 0` 且 true/false 都是寄存器。
- 这里的机会是 “compare flags -> 0/1”，即 standalone boolean set；true/false 是 immediate `0/1`，多数条件还不是 zero-test。
- x86 和 ARM64 都有直接原语：x86 `SETcc`，ARM64 `CSET`。

## 1. 覆盖关系

已读：

- `bpfopt/crates/bpfopt/src/passes/cond_select.rs`
- `bpfopt/crates/bpfopt/src/main.rs`
- `docs/tmp/p89_research_audit.md`
- `docs/tmp/20260329/arm64_kinsn_research_20260329.md`
- `docs/tmp/20260329/memory_hints_kinsn_research_20260329.md`
- `docs/tmp/20260319/arm64_emitter_design_20260319.md`
- `docs/tmp/pass-coverage-analysis-20260428.md`

`cond_select` 的 matcher 会识别两类 branch+mov shape：

```text
Jcc +2; MOV dst,false; JA +1; MOV dst,true
MOV dst,true; Jcc +1; MOV dst,false
```

但当前 pass 的实际可应用范围很窄：

- `is_simple_zero_test()` 只接受 `JNE reg, 0` 或 `JEQ reg, 0`。
- `packed_supported_for_site()` 要求 true/false operands 都是 `Reg(_)`。
- boolean-set site 的 true/false 是 `Imm(1)` / `Imm(0)`，因此即便 matcher 能看见，也会被 `"packed ABI requires register true/false operands"` 跳过。
- 任意比较，如 `r2 > 0xffff`、`w2 == 0xa00`、`r8 != r0`，也不能映射到 `bpf_select64(a,b,cond)` 的 `cond != 0` 参数。

`main.rs` 中 `cond_select` 已在 x86/ARM64 默认 optimize pipeline 里，但这不改变覆盖结论。它覆盖的是条件选择 kfunc，不覆盖 standalone compare-to-boolean。

历史文档关系：

- `arm64_emitter_design_20260319.md` 在 `COND_SELECT` lowering 里提到 `cset/csetm` boolean fast paths，但那是旧 canonical directive 设计的一部分，不是当前 bpfopt pass 的专项调研。
- `arm64_kinsn_research_20260329.md` 没有 SETcc/CSET corpus census；只把 `cond_select` 作为复杂度参照。
- `memory_hints_kinsn_research_20260329.md` 与 CSET 无关。
- `pass-coverage-analysis-20260428.md` 已把 “Immediate-operand `cond_select` / boolean `SETcc`”列成 P1 opportunity。

## 2. Corpus census

### 方法

静态扫描 `llvm-objdump -d` 输出，匹配低误报 boolean-set shape：

```text
MOV dst,1; Jcc +1; MOV dst,0
Jcc +2; MOV dst,0; JA +1; MOV dst,1
```

对 `MOV dst,1; Jcc +1; MOV dst,0`，额外排除 `MOV` 写入被后续 `Jcc` 条件读取的寄存器，避免改变条件值。扫描包含 `rN` 和 `wN` immediate move。`corpus/bcf` 中大量 eBPF 文件以 `.o` 命名，因此扫描包括 `.o/.bpf.o/.bcf`，再用 `file` 过滤 eBPF。

### 请求指定根目录：`corpus/bcf` + `runner/repos`

| 指标 | 数量 |
| --- | ---: |
| candidate object files | 1762 |
| eBPF objects scanned | 1710 |
| non-BPF skipped | 52 |
| failed disassembly | 0 |
| boolean-set sites | 28653 |
| short pattern | 28653 |
| diamond pattern | 0 |
| simple zero-tests | 10537 |
| `eq/ne` family | 25267 |
| unsigned relational | 3305 |
| signed relational | 81 |

按 app/repo 分布：

| app/repo | sites |
| --- | ---: |
| `calico` | 27483 |
| `cilium` | 641 |
| `bpf-examples` | 289 |
| `KubeArmor` | 152 |
| `xdp-tools` | 44 |
| `xdp-tutorial` | 29 |
| `bcc` | 14 |
| `collected` | 1 |

这组 raw count 被 `corpus/bcf/calico` 的 compiler variant 大量放大，适合证明 pattern 广泛存在，但不适合作为 runtime ROI 的唯一输入。

### Supported runtime corpus：`corpus/build/{tracee,tetragon,bpftrace,bcc,katran,calico,cilium,opentelemetry-ebpf-profiler}`

| 指标 | 数量 |
| --- | ---: |
| eBPF objects scanned | 186 |
| boolean-set sites | 9417 |
| short pattern | 9417 |
| diamond pattern | 0 |
| `rN` destination | 9010 |
| `wN` destination | 407 |
| simple zero-tests | 371 |
| `eq/ne` family | 761 |
| unsigned relational | 8514 |
| signed relational | 142 |

按 supported app 分布：

| app | sites |
| --- | ---: |
| `tetragon` | 8832 |
| `cilium` | 401 |
| `calico` | 91 |
| `bcc` | 79 |
| `tracee` | 10 |
| `katran` | 2 |
| `otelcol-ebpf-profiler` | 2 |
| `bpftrace` | 0 |

### 具体 site 例子

Calico, `corpus/build/calico/from_hep_debug.bpf.o`, section `tc`, pc 893:

```text
891: r2 = *(u16 *)(r6 + 0x178)
892: r2 &= 0xff
893: r1 = 0x1
894: if r2 != 0x0 goto +0x1
895: r1 = 0x0
```

Cilium, `corpus/build/cilium/bpf_host.bpf.o`, section `tc/entry`, pc 2607:

```text
2607: w3 = 0x1
2608: if w2 == 0xa00 goto +0x1
2609: w3 = 0x0
```

BCC, `corpus/build/bcc/libbpf-tools/.output/biolatency.bpf.o`, section `.text`, pc 446:

```text
446: r1 = 0x1
447: if r2 > 0xffff goto +0x1
448: r1 = 0x0
```

Tracee, `corpus/build/tracee/tracee.bpf.o`, section `raw_tracepoint/exec_test`, pc 2618:

```text
2618: r3 = 0x1
2619: if r4 == 0x1 goto +0x1
2620: r3 = 0x0
```

Tetragon, `corpus/build/tetragon/bpf_execve_event.o`, section `tracepoint/sys_execve`, pc 433:

```text
433: r2 = 0x1
434: if r8 != r0 goto +0x1
435: r2 = 0x0
```

Otelcol eBPF profiler, `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o`, section `perf_event/unwind_native`, pc 387:

```text
387: r1 = 0x1
388: if r0 != 0x0 goto +0x1
389: r1 = 0x0
```

Katran, `corpus/build/katran/balancer.bpf.o`, section `xdp`, pc 1225:

```text
1225: r1 = 0x1
1226: if r2 == 0x0 goto +0x1
1227: r1 = 0x0
```

BCF BCC sample, `corpus/bcf/bcc/clang-20_-O1_ksnoop.bpf.o`, section `.text`, pc 381:

```text
381: w3 = 0x1
382: if r5 < r4 goto +0x1
383: w3 = 0x0
```

## 3. ROI estimate

Native lowering target:

- x86: `cmp/test; mov dst,0; setcc dstb` or equivalent, preserving flags between compare and `setcc`.
- ARM64: `cmp/test; cset wDst, cond`.

Compared with current JIT output for the BPF shape, this removes one conditional branch and one materialization move on the common short pattern. Conservative steady-state saving is **1-2 cycles per executed site**, with larger upside if the branch is hard to predict or if branch predictor pressure matters.

Using `corpus/results/aws_x86_corpus_20260430_014417_532765/details/result.json`:

| runner | baseline `run_cnt_delta` |
| --- | ---: |
| `tracee` | 6593236 |
| `tetragon` | 2062013 |
| `bcc` | 1596855 |
| `bpftrace` | 380128 |
| `katran` | 1408 |
| `otelcol-ebpf-profiler` | 257 |
| total | 10633897 |

Apps with static SETcc/CSET sites and measured run counts account for **10253769** baseline BPF executions in that result (`tracee`, `tetragon`, `bcc`, `katran`, `otelcol-ebpf-profiler`). Cilium and Calico have many static sites but were not in this particular measured result.

Break-even at 3 GHz:

| one-time ReJIT/pass overhead | 1 cycle saved | 2 cycles saved |
| --- | ---: | ---: |
| 100 us | 300k executions | 150k executions |
| 1 ms | 3.0M executions | 1.5M executions |

This means:

- Tracee crosses even the 1 ms / 1-cycle threshold if one transformed site is hot.
- Tetragon crosses the 1 ms threshold at 2 cycles per hot site, and has 8832 static sites.
- BCC is near the 1 ms / 2-cycle threshold and clearly crosses the 100 us threshold.
- Cilium/Calico need runtime measurements for final macro ROI, but their static counts are high enough to justify implementation.

The expected benchmark effect is not “all 9417 sites execute every run”. The defensible claim is narrower: the site count is high enough, and measured run counts in Tracee/Tetragon/BCC are high enough, that a few hot sites can amortize the extra pass/JIT work.

## 4. 实现复杂度

BPF 没有原生 SETcc/CSET instruction，因此需要新 kinsn，而不是纯 bytecode rewrite：

```text
bpf_setcc(dst, lhs, rhs, cc, width, src_kind)
```

实际 packed payload 需要编码：

- destination register
- compare lhs register
- RHS source kind: register or immediate
- RHS register/immediate value
- condition code: `eq/ne`, unsigned `< <= > >=`, signed `< <= > >=`
- compare width: BPF_JMP64 vs BPF_JMP32
- result width/source move width if we want to preserve `wN` vs `rN` spelling, though 0/1 write through `wDst` zero-extends on ARM64 and full-zeroing on x86 is straightforward

Pass 侧复杂度中等，接近但略高于 `cond_select`：

- matcher 很固定，主要是 3-insn short pattern，少量 diamond 可后续补。
- 不需要 liveness 分析：compare operands 在原 Jcc 前读取；native lowering 先 compare，再写 dst，即使 dst 与 compare operand 相同也安全。
- 仍需要 branch target/interior target 检查、branch fixup、BTF/line info remap、subprog boundary check，复用现有 kinsn replacement utilities。
- verifier proof fallback 应 lower 回原始 `MOV/Jcc/MOV` 片段。

JIT/module 侧：

- x86 module 增加 `bpf_setcc` native emit，映射 BPF Jcc 到 `setcc` condition code。需要注意先 `cmp/test`，再 `mov dst,0`，最后 `setcc dstb`，避免提前清零 clobber compare operand。
- ARM64 module 增加 `bpf_cset`/同一 `bpf_setcc` target 的 ARM64 emit，映射到 `cmp`/`tst` + `cset wDst, cond`。
- immediate compare encoding 需要复用现有 JIT compare-immediate helper 或做同等合法性处理；不能静默 fallback。

## 5. 建议

状态更新为：`📝 调研完成（待实现）`。

推荐 first wave：

1. 只实现 3-insn short pattern：`MOV 1; Jcc +1; MOV 0`。
2. 覆盖 `JMP64` 和 `JMP32` 的 `eq/ne`、unsigned relational、signed relational。
3. 先不做 arbitrary `A/B select`，避免与 `cond_select` 语义混在一起。
4. diamond pattern 可以留作 follow-up；当前 supported corpus 没有 diamond hit。

不要把它写成 `cond_select` immediate support 的附带功能。`cond_select` immediate support 只能解决 “A/B value select” 的一部分问题；SETcc/CSET 的关键收益是直接消费 compare flags，消掉 branch。

## 6. 验证

本任务只做静态调研和文档更新。未修改 `bpfopt/crates/*`，未修改 `vendor/linux-framework` 或 `module/`，未运行 `cargo test`。

运行过的只读检查包括：

```bash
git status --short
sed -n '210,255p' docs/kernel-jit-optimization-plan.md
sed -n '1,560p' bpfopt/crates/bpfopt/src/passes/cond_select.rs
sed -n '1,240p' bpfopt/crates/bpfopt/src/main.rs
rg -n -i "cset|setcc|cond_select|select64|boolean" docs/tmp ...
llvm-objdump -d <corpus object>
```
