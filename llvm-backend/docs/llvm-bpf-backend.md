# LLVM BPF Backend 现状调研

> **架构注记（2026-07-10）**：LLVM backend 调研本身仍有效;其中把当前
> bpfopt 描述为 daemon orchestration + per-pass `BPF_PROG_REJIT` 的段落已
> 过期。当前 bpfopt 是由 in-app shim 调用的纯 bytecode CLI,candidate 经
> stock `BPF_PROG_LOAD` 接受。

调研基准：

- LLVM checkout：`/tmp/llvm-research/llvm-project`，commit `30546911`。
- sparse checkout 范围：`llvm/lib/Target/BPF`、`llvm/lib/Target/X86`、`llvm/lib/Target/AArch64`、`llvm/lib/CodeGen`、`llvm/lib/Transforms`、`llvm/include/llvm/{IR,CodeGen,Target}`、`llvm/docs`。
- 外部参考：LLVM BPF 源树 <https://github.com/llvm/llvm-project/tree/3054691/llvm/lib/Target/BPF>、LLVM CodeGenerator 文档 <https://llvm.org/docs/CodeGenerator.html#the-extended-berkeley-packet-filter-ebpf-backend>、LLVM 贡献流程 <https://llvm.org/docs/Contributing.html>、InstCombine 变更 `acabad9ff6bf` <https://github.com/llvm/llvm-project/commit/acabad9ff6bf>。

## 1. LLVM BPF backend overview

LLVM BPF backend 是一个常规 LLVM target backend，但为了 eBPF verifier、CO-RE relocation、BTF debug info 和内核 ABI 做了不少 target-specific 保护。它的默认 instruction selection 仍是 SelectionDAG；GlobalISel 组件存在并被初始化，但 `BPFTargetMachine::addInstSelector()` 默认安装的是 `createBPFISelDag()`，不是 GlobalISel selector。

### Pass pipeline

`llvm/lib/Target/BPF/BPFTargetMachine.cpp` 的 legacy `TargetPassConfig` hook：

| 阶段 | BPF 注入的 pass | 作用 |
|---|---|---|
| `addIRPasses()` | `AtomicExpandLegacyPass` | 展开 atomic。 |
| `addIRPasses()` | `BPFCheckAndAdjustIR` | 清理 BPF builtin barrier，处理 address space、CO-RE/relocation 限制、verifier-hostile IR 形态。 |
| `addInstSelector()` | `BPFDAGToDAGISelLegacy` | SelectionDAG 指令选择。 |
| `addMachineSSAOptimization()` | `BPFMISimplifyPatchable` | 简化 BPF CO-RE patchable load/store 相关 MachineInstr。 |
| `addMachineSSAOptimization()` | `TargetPassConfig::addMachineSSAOptimization()` | 跑默认 Machine SSA 优化，例如 MachineDCE、MachineCSE、MachineLICM、PeepholeOptimizer 等。 |
| `addMachineSSAOptimization()` | `BPFMIPeephole` | ALU32 相关 zero-extension peephole。 |
| `addPreEmitPass()` | `BPFMIPreEmitChecking` | 发射前做 BPF 合法性检查。 |
| `addPreEmitPass()` | `BPFMIPreEmitPeephole` | 发射前分支距离修正、fastcall spill、冗余 move 删除等。 |

New Pass Manager callback：

| Extension point | BPF pass | 作用 |
|---|---|---|
| Pipeline start | `BPFPreserveStaticOffsetPass(true)` | 早期保护 context/static-offset load/store。 |
| Pipeline start | `BPFAbstractMemberAccessPass` | 保护 BTF/CO-RE abstract member access。 |
| Pipeline start | `BPFPreserveDITypePass` | 保留 `btf_type_id` 相关 debug type 信息。 |
| Pipeline start | `BPFIRPeepholePass` | 删除不需要的 `stacksave/stackrestore` 形态，避免生成 `r11` stack pointer。 |
| Peephole EP | `SimplifyCFGPass` with `hoistCommonInsts=true` | 额外 CFG 简化，但 BPF pass 会插 barrier 防止破坏 CO-RE/static offset。 |
| Peephole EP | `BPFASpaceCastSimplifyPass` | 简化 address-space cast + GEP。 |
| ScalarOptimizerLate EP | `BPFPreserveStaticOffsetPass(false)` | 在 loop unroll 后再次保护 static offset。 |
| PipelineEarlySimplification EP | `BPFAdjustOptPass` | 在 target-independent scalar opt 之前调整 verifier-sensitive IR。 |

`BPFPassRegistry.def` 暴露了三个可在 NPM pipeline 中显式调用的 pass：`bpf-aspace-simplify`、`bpf-ir-peephole`、`bpf-preserve-static-offset<allow-partial=...>`。

### SelectionDAG vs GlobalISel

- 默认路径：SelectionDAG。`BPFISelDAGToDAG.cpp` 做 DAG-to-DAG selection，`BPFISelLowering.cpp` 做 legalization/lowering，`BPFSelectionDAGInfo.cpp` 做 target memcpy。
- GlobalISel：`llvm/lib/Target/BPF/GISel/` 存在 `BPFCallLowering`、`BPFInstructionSelector`、`BPFLegalizerInfo`、`BPFRegisterBankInfo`，`LLVMInitializeBPFTarget()` 也初始化了这些 pass；但 backend 默认 selector hook 仍是 SelectionDAG。这意味着 GlobalISel 更像可选/实验路径，不是当前主路径。

### TableGen 覆盖范围

`BPF*.td` 定义了：

- 寄存器：`R0`-`R11`、`W0`-`W11`，`GPR`/`GPR32` register class；`R10` 是只读 frame pointer，`R11` 在 backend 中保留。
- calling convention：参数走 `R1`-`R5`/`W1`-`W5`，返回值走 `R0`/`W0`，另有 `R2`/`W2` shadow。
- ALU/JMP/LD/ST 指令族：64-bit 和 ALU32 变体，`JMP32`、`LDX/STX`、atomic、`LD_imm64`、`addrspacecast` pseudo、frame-index pseudo。
- v4 相关 feature pattern：`BSWAP`、signed load、signed div/mod、store immediate、acquire/release、long jump `JMPL`、indirect jump `gotox`。
- pattern lowering：`BPFselectcc` pseudo、packet load intrinsics `bpf_load_byte/half/word`、byte swap/endian pattern、memcpy pseudo、atomic fetch/no-fetch pattern、jump table/global wrapper pattern。

## 2. 已实现优化清单 + 位置

### IR 层：优化保护和 verifier-friendly canonicalization

| 文件 | 优化/调整 | 说明 |
|---|---|---|
| `BPFAdjustOpt.cpp` | `adjustICmpToBuiltin()` | 暂时把某些 `(trunc x) u< pow2` compare 包成 `llvm.bpf.compare`，避免 InstCombine 把它 canonicalize 成 mask+cmp 后触发 verifier 精度问题。背景对应 InstCombine commit `acabad9ff6bf`。 |
| `BPFAdjustOpt.cpp` | `serializeICMPInBB()` / `serializeICMPCrossBB()` | 插入 `__builtin_bpf_passthrough` barrier，防止多个条件被合并成 verifier 不友好的形式。 |
| `BPFAdjustOpt.cpp` | `avoidSpeculation()` | 对 guarded load/call 的跨 block 使用插 barrier，防止普通优化把访问 hoist 到 guard 之前。 |
| `BPFCheckAndAdjustIR.cpp` | passthrough/bpf.compare cleanup | 在 target-independent 优化之后删除 BPF builtin barrier，恢复普通 IR。 |
| `BPFCheckAndAdjustIR.cpp` | `sinkMinMax()` | 把 LICM/InstCombine 可能制造的 min/max 形态 sink 回 verifier 更容易接受的位置；源码注释引用了 BPF mailing list 讨论。 |
| `BPFCheckAndAdjustIR.cpp` | address-space 调整 | 对 load/store/mem intrinsic 插入 addrspace(0) cast，并给非 0 address-space global 指定 section。 |
| `BPFPreserveStaticOffset.cpp` | static offset preservation | 把 `llvm.preserve.static.offset + GEP + load/store` 临时替换成 `llvm.bpf.getelementptr.and.load/store`，避免 InstCombine/GVN/SimplifyCFG 改写 context/static-offset 访问。 |
| `BPFAbstractMemberAccess.cpp` | CO-RE access preservation | 保护 abstract member access；用 passthrough 防止 SimplifyCFG tail merging relocation global，避免 relocation 失去可定位对象。 |
| `BPFPreserveDIType.cpp` | BTF type id preservation | 保留 `__builtin_btf_type_id()` 需要的 debug type 信息。 |
| `BPFIRPeephole.cpp` | stack save/restore peephole | 删除无动态 alloca 时的 `llvm.stacksave/stackrestore` 残留，避免后端生成不支持的 `r11` stack pointer 使用。 |
| `BPFASpaceCastSimplifyPass.cpp` | address-space cast + GEP 简化 | 把 `addrspacecast(gep(addrspacecast(ptr)))` 简化为原 address-space 上的 GEP。 |

这些不是传统意义上的“让机器码更快”的优化，更多是在 LLVM 中间优化和 BPF verifier 之间做语义保护。BPF backend 的大量工程价值在这里。

### SelectionDAG / instruction lowering 层

| 文件 | 优化/调整 | 说明 |
|---|---|---|
| `BPFISelLowering.cpp` | `SELECT_CC` custom lowering | LLVM IR `select` 最终变成 BPF select pseudo，再由 custom inserter 展开成 branch diamond + PHI。BPF ISA 没有 cmov。 |
| `BPFISelLowering.cpp` | unsupported op fail-fast | dynamic stackalloc、varargs、byval、部分 builtin、seq_cst atomic load/store、无 v4 feature 的 signed div/rem 等直接报错。 |
| `BPFISelLowering.cpp` | `ROTR/ROTL/CTPOP/CTTZ/CTLZ` expand | BPF ISA 没有对应通用 opcode，默认展开成普通指令序列。 |
| `BPFISelLowering.cpp` | `shouldReduceLoadWidth=false` | 禁止 SelectionDAG 自动把宽 load 缩成窄 load，源码注释给了 verifier/relocation 会被破坏的例子。 |
| `BPFISelLowering.cpp` | addressing-mode 限制 | 合法地址基本是 `reg + imm` 或 immediate，不支持一般的 `reg + reg` addressing。 |
| `BPFSelectionDAGInfo.cpp` | constant-size memcpy pseudo | 常量大小且 store 数量可控时生成 BPF `MEMCPY` pseudo。 |
| `BPFISelDAGToDAG.cpp` | base+offset selection | 将 frame/global/普通地址尽量选成 BPF 可表达的 base + 16-bit offset。 |
| `BPFISelDAGToDAG.cpp` | constant global load fold | 对简单 constant global struct/array load 做 compile-time fold，避免运行时只读 section load。 |
| `BPFISelDAGToDAG.cpp` | packet load trunc cleanup | `bpf_load_byte/half/word` intrinsic 已经 zero-extend 时删除冗余 `AND`/trunc 形态。 |

### MachineInstr 层

| 文件 | 优化/调整 | 说明 |
|---|---|---|
| `BPFMISimplifyPatchable.cpp` | CO-RE patchable simplification | 把通过 relocation global 间接表达的 load/store/add/shift 形态转成 BPF CORE pseudo，便于 BTF relocation 输出。 |
| `BPFMIPeephole.cpp` | ALU32 zero-extension peephole | 在 ALU32 feature 下删除或改写 `MOV_32_64; SLL 32; SRL 32` 等 32-to-64 zero-extension 序列。 |
| `BPFMIPeephole.cpp` | redundant self-move removal | 发射前删除 `MOV rA, rA`；不会删除带 zero-upper-side-effect 的 32-bit move。 |
| `BPFMIPeephole.cpp` | branch relaxation | v4/gotol 之前普通 BPF branch offset 是 16-bit；发射前把过远 jump 改成 `JMPL` 或 short conditional + long jump trampoline。 |
| `BPFMIPeephole.cpp` | fastcall spill insertion | 为 `bpf_fastcall` 周围补 caller-saved spill。 |
| `BPFMIPeephole.cpp` | may_goto cleanup | 删除跳到紧随 block 的 `may_goto`。 |
| `BPFMIPeephole.cpp` | unreachable exit fixup | 在末尾 `call bpf_unreachable` 后补 `exit`。 |
| `BPFInstrInfo.cpp` | memcpy pseudo expansion | post-RA 把 `MEMCPY` pseudo 展开为按 alignment/size 分块的 load/store 对。 |
| `BPFMIChecking.cpp` | XADD result check | 发射前检查 XADD 结果不能被使用。 |
| `BPFFrameLowering.cpp` / `BPFRegisterInfo.cpp` | BPF stack lowering | prologue/epilogue 基本为空，frame index 消解为 `R10 + offset`；默认超过 512B stack 会警告。 |

## 3. 不跑的 generic pass + 原因

先区分两条 pipeline：

- Clang/LLVM middle-end 的 scalar pass，例如 InstCombine、SCCP、GVN、DCE、LoopUnroll、SimplifyCFG，主要由 PassBuilder/优化级别控制。BPF backend 没有在 `BPFTargetMachine` 里“一键关闭”这些通用 IR pass；相反，它通过 NPM extension point 插入 barrier/protection pass，让通用优化在不破坏 verifier/CO-RE 语义的前提下运行。
- CodeGen pass 由 `TargetPassConfig` 控制。BPF backend 大多沿用默认 CodeGen pass，只在关键点添加少量 BPF pass。和 X86/AArch64 相比，BPF 少了很多 target-specific scheduling/combiner/if-conversion/load-store 优化。

### 明确没有 BPF target-specific 版本的 pass

| pass/能力 | BPF 当前状态 | X86/AArch64 对照 | 原因/影响 |
|---|---|---|---|
| if-conversion / cmov conversion | 没有 BPF target if-converter 或 cmov conversion；`select` 展开为 branch diamond。 | X86 有 `X86CmovConversion`，AArch64 有 conditional compare / branch tuning。 | BPF ISA 没有 cmov、predication、ccmp。LLVM AOT 无法凭空生成宿主 JIT 指令，只能发 BPF bytecode。 |
| MachineCombiner / target ILP opts | BPF 没有覆盖 `addILPOpts()`，只跑默认 machine SSA 优化。 | X86/AArch64 都有 target combiner/ILP pass。 | BPF 指令集简单、无复杂 addressing/vector/pairing，且 verifier 限制使 aggressive reassociation 风险更高。 |
| target loop data prefetch | BPF backend 没有插入 prefetch pass，也没有 prefetch lowering。 | AArch64 有 loop data prefetch 相关 pass。 | BPF ISA 没有 prefetch opcode；需要 helper/kfunc/kop 级 ABI 才能表达。 |
| vector/interleaved access lowering | BPF 没有 vector register/向量 load-store 优化。 | AArch64/X86 有 interleaved/vector 相关 lowering。 | BPF 是 scalar ISA。 |
| load/store pair combine | BPF 没有 AArch64 风格 LDP/STP 或 X86 风格复杂 memory op combine。 | AArch64 有 load/store optimizer。 | BPF memory op 是简单 `LDX/STX`，没有 pair op；verifier 还要求部分访问形态保持显式。 |
| MachineOutliner | BPF 没有像 X86/AArch64 那样默认启用 outliner。 | X86/AArch64 target machine 显式支持 outliner。 | BPF subprog/call、verifier、stack/call-clobber 约束和 code-size tradeoff 更敏感；源码没有显式注释说明。 |
| target post-RA scheduler | BPF 没有 target-specific post-RA scheduling model/hook。 | 部分 target 有复杂 scheduler model。 | BPF bytecode 到 native JIT 的真实 latency 由内核 JIT 和宿主 ISA 决定，LLVM AOT 阶段缺少最终机器信息。 |

### 通用 pass 会跑，但对 BPF 效果受限或被 BPF pass 约束

| pass/能力 | 状态 | BPF 特殊点 |
|---|---|---|
| LoopUnroll | 不在 `BPFTargetMachine::addIRPasses()` 中单独开关；Clang 优化 pipeline 可运行。 | BPF static-offset pass 特意在 loop unroll 后再跑一次，说明 LLVM 允许 unroll 发生，但要修复 unroll 后的 verifier-sensitive access。现代 verifier 支持 bounded loop，旧 LLVM 文档里“verifier prevents loops”的说法已经过时。 |
| DCE | IR DCE 由 middle-end 控制；MachineDCE 在默认 CodeGen pipeline 中运行。 | BPF 仍会用 passthrough barrier 保住 verifier/CO-RE 关键形态，避免 DCE/cleanup 把 relocation 或 guard 关系弄丢。 |
| GVN / CSE | IR GVN/CSE 由 middle-end 控制；MachineCSE 在默认 CodeGen pipeline 中运行。 | `BPFPreserveStaticOffset` 和 `BPFAbstractMemberAccess` 的核心工作就是阻止 GVN/SimplifyCFG/InstCombine 把 static offset 或 relocation access 拆散、合并、sink/hoist 到不可 relocation 的形态。 |
| Branch folding / tail duplication | 默认 late machine pipeline 中存在 BranchFolder/TailDuplicate；早期也有 EarlyTailDuplicate。 | `BPFInstrInfo::analyzeBranch()` 只完整处理 unconditional branch，遇到 conditional/indirect 多数返回“不能分析”，所以 generic branch folding 对条件 CFG 的效果有限。CO-RE pass 还会主动用 barrier 阻止某些 IR tail merge。 |
| PrologEpilogInserter | 默认运行。 | BPF prologue/epilogue 基本为空；实际重要逻辑是 frame index 到 `R10 + offset`、callee-save 策略和 stack limit 检查。 |
| PostRA scheduling | 默认框架存在，但 BPF 没有 target-specific 调度收益建模。 | 对 BPF bytecode 的收益不稳定，因为最终 native 指令由内核 JIT 决定。 |
| BoundsCheckPass | LLVM 有 bounds checking/instrumentation pass，但 BPF backend 没用它做 packet bounds 合并。 | BPF packet/map bounds 依赖 verifier 语义、helper 语义和 program type，不是 LLVM 普通数组 bounds check 模型。 |

结论：BPF backend 不是“少跑所有 scalar opt”，而是“跑通用 opt，但在 verifier/CO-RE 敏感区域插保护；同时缺少大 target 的 target-specific machine optimizations”。

## 4. TODO / known limitations

### TODO/FIXME/XXX grep 结果

`rg -n "TODO|FIXME|XXX" llvm/lib/Target/BPF` 只有一个命中：

- `llvm/lib/Target/BPF/BTFDebug.cpp:1121`：`FIXME(sandboxing)`，传播 `vfs::FileSystem` 到该位置工作量较大。这个 FIXME 属于 LLVM sandboxed filesystem plumbing，不是 BPF codegen optimization TODO。

当前 `llvm/lib/Target/BPF/` 没有 `README` 文件。

### 源码中实际暴露的 known limitations

| 限制 | 位置 | 说明 |
|---|---|---|
| dynamic stack allocation unsupported | `BPFISelLowering.cpp` | BPF 不支持动态 alloca；`BPFIRPeephole` 只处理无动态 alloca 的 stacksave/restore 残留。 |
| varargs unsupported | `BPFISelLowering.cpp` | lowering 中直接 fail。 |
| byval unsupported | `BPFISelLowering.cpp` | pass-by-value 参数直接 fail。 |
| LLVM tail-call optimization unsupported | `BPFISelLowering.cpp` | 这里指 LLVM function call 的 tail-call optimization，不是 eBPF helper `bpf_tail_call()`。 |
| stack return unsupported | `BPFISelLowering.cpp` | 返回值走寄存器模型。 |
| unsupported builtin fail-fast | `BPFISelLowering.cpp` | 除 trap、除法 helper、memcpy/memset/memmove 等受支持 builtin 外直接报错。 |
| signed div/rem feature-gated | `BPFISelLowering.cpp` | 无 v4 `sdiv_smod` feature 时 signed div/rem 报错。 |
| seq_cst atomic load/store unsupported | `BPFISelLowering.cpp` | atomic load/store order 受限。 |
| stack size 默认 512B 警告 | `BPFRegisterInfo.cpp` | 超过 `BPFStackSize` 会 warning。 |
| conditional branch analysis limited | `BPFInstrInfo.cpp` | branch analyze/insert 主要只处理 unconditional branch，限制 generic BranchFolder 等 pass。 |
| LLVM docs 部分过时 | `llvm/docs/CodeGenerator.rst` / 在线 CodeGenerator 文档 | 文档仍提到 4K 指令限制、verifier prevents loops、main routine only 等旧约束；当前源码和现代内核能力已经更丰富。 |

## 5. bpfopt vs LLVM BPF backend 对比表

| bpfopt pass | LLVM BPF backend 做不做 | LLVM 位置/形态 | 重叠程度 | bpfopt 额外价值 |
|---|---|---|---|---|
| `rotate` | LLVM 能在 IR/DAG 中识别 rotate/funnel-shift 概念，但 BPF lowering 把 `ROTR/ROTL` 标成 `Expand`。 | `BPFISelLowering.cpp`。 | 低。LLVM 最终只能生成 shift/or 序列。 | bpfopt 把 bytecode shift/or rotate pattern 改成 `bpf_rotate{32,64}` kfunc/kop，内核 JIT 可降成 native rotate。 |
| `cond_select` | LLVM 有 `select`，BPF 有 `SELECT_CC` custom lowering，但最终展开为 branch diamond。 | `BPFISelLowering.cpp` custom inserter。 | 中。都识别 select 语义，但 LLVM 无 branchless BPF 表达。 | bpfopt 用 `bpf_select64`/kop 映射到 x86 CMOV 或 arm64 CSEL，绕过 BPF ISA 没有 cmov 的限制。 |
| `ccmp` | LLVM AArch64 有 conditional-compare 相关优化；BPF target 没有。 | AArch64 target pass；BPF 无对应 pass。 | 低。 | bpfopt 只在 arm64 kop 路径表达 native CCMP 类优化，属于 post-load/host-JIT 维度。 |
| `bulk_memory` | LLVM 会把常量大小 memcpy 生成 BPF `MEMCPY` pseudo，再展开成 load/store 对；不会生成 REP MOVS/kfunc。 | `BPFSelectionDAGInfo.cpp`、`BPFInstrInfo.cpp`。 | 中。都处理 memcpy，但 LLVM 是 scalar expansion。 | bpfopt 可在 bytecode scalar copy 已形成后重新识别 bulk copy/memset，并替换为 `bpf_bulk_memcpy/memset` kop。 |
| `endian_fusion` | LLVM 有 BSWAP/endian pattern；v4 有 `BSWAP` 指令 pattern。没有 load+bswap 融合成 MOVBE，因为 BPF ISA 不表达 memory-endian fused op。 | `BPFInstrInfo.td`、`BPFISelLowering.cpp`。 | 中。LLVM 处理 endian op，但不做 native fused memory op。 | bpfopt 把 load + endian ladder 改成 `bpf_endian_loadXX`，JIT 可降成 x86 MOVBE 或 arm64 LDR+REV。 |
| `prefetch` | BPF backend 不 lower `llvm.prefetch` 到 BPF op，也没有 loop prefetch pass。 | BPF 无对应实现。 | 低。 | bpfopt 基于 packet/map access pattern 和可选 PMU 数据插入 `bpf_prefetch` kop，属于运行时/JIT 语义。 |
| `extract` | LLVM 通用 combine 可识别 bitfield extract，但 BPF 没有 BEXTR-like opcode；BPF target 没有把 shift+and 映射为 helper/kfunc。 | BPF lowering/tablegen 无 BEXTR pattern。 | 低。 | bpfopt 将 `rsh + and contiguous mask` 改成 `bpf_extract64` kop，JIT 可降成 native bit extract。 |
| `map_inline` | LLVM 不能做。BPF map 是运行时 kernel object，AOT 编译期没有 map fd/value snapshot。 | 无。 | 无。 | bpfopt/daemon 可在程序加载后读取 map side input，结合 verifier/ReJIT 接受性做 map value inline。 |
| `const_prop` | LLVM 有 SCCP/InstCombine/ConstProp/GVN 等编译期常量传播；BPF 默认也跑 generic IR/machine cleanup。 | middle-end + default CodeGen。 | 中。只重叠静态常量。 | bpfopt 使用 ReJIT verifier state、map_inline 后的 runtime 常量、bytecode-level defs 做 post-load const propagation。 |
| `dce` | LLVM 有 IR DCE 和 MachineDCE。 | middle-end + `TargetPassConfig::addMachineSSAOptimization()`。 | 中。 | bpfopt 在每轮 runtime rewrite/ReJIT 后做 bytecode-level DCE，可删除 LLVM 编译期看不到的死定义或 rewrite 后变死的代码。 |
| `bounds_check_merge` | LLVM 可做普通 CFG/compare 简化，但 BPF backend 没有 packet bounds-check merge pass。 | 无；BPF 反而有 verifier-friendly guard barrier。 | 低。 | bpfopt 知道 BPF packet pointer、helper/program type、verifier range 语义，可合并 packet bounds-check ladder。 |
| `skb_load_bytes_spec` | LLVM 只看到 helper call，不能把 `bpf_skb_load_bytes()` 语义特化成 direct packet access。 | 无。 | 无。 | bpfopt 根据 helper id、prog type、verifier 接受性做 helper specialization。 |
| `wide_mem` | LLVM 有一般 memory combine/InstCombine，但 BPF backend 明确禁用 load-width reduction；不会可靠把 byte ladder 合成 verifier-safe wide load。 | `BPFISelLowering::shouldReduceLoadWidth(false)`，generic mem opt。 | 中低。 | bpfopt 在 bytecode 层识别 byte-ladder，并结合 CFG/liveness/branch-target 约束生成 wide `LDX_MEM`。 |
| `branch_flip` | LLVM 有 PGO/block placement 能力，但 BPF backend 没有 post-load per-site PMU profile 输入。 | generic PGO/block placement，需要 profile metadata。 | 低。 | bpfopt 使用外部 profiler 的真实 per-site `branch_count/misses/taken/not_taken`，在 lift 后的 LLVM IR 上写入 branch-weight metadata，再走同一轮 O3 roundtrip。 |
| `noop` | LLVM 无“产生 verifier state”的 noop pass 概念。 | 无。 | 无。 | bpfopt 的 `noop` 价值是触发 ReJIT/verifier log，给后续 verifier-state pass 提供 side input。 |

## 6. 上游贡献机会

适合贡献到 LLVM BPF backend 的方向，是那些在 AOT 编译期就能安全判断、只依赖 BPF ISA/LLVM IR/MachineInstr、不依赖 live kernel object 或 fork-only ReJIT 的优化：

1. **文档修正**：更新 LLVM CodeGenerator 的 BPF 章节。当前在线文档仍有 4K 指令、loop、main-only 等旧描述，容易误导 backend 使用者。
2. **BPF branch analysis 改进**：扩展 `BPFInstrInfo::analyzeBranch()` 对 conditional branch 的理解，让 generic BranchFolder/TailDuplicate/MachineBlockPlacement 能在安全范围内发挥更多作用。
3. **静态 byte-ladder/wide-load combine**：在严格 verifier-safe 条件下，把明显的 byte load ladder 合成宽 load。需要非常保守，且要和 `shouldReduceLoadWidth=false` 的 verifier/relocation 约束保持一致。
4. **endian/bswap pattern 补强**：继续完善 load + bswap 邻近 pattern 的 instruction selection/peephole，但只能发 BPF ISA 已有指令，不能直接生成 MOVBE。
5. **BPF TTI/cost model**：更精确地告诉 LLVM BPF 上 select、branch、memcpy、icmp、wide load 的代价，减少 middle-end 生成 verifier-hostile 或 BPF-cost-hostile 的形态。
6. **GlobalISel parity**：补齐 BPF GlobalISel 路径和 SelectionDAG 的 feature/test parity。当前源码已有 GISel，但默认主路径还是 SelectionDAG。
7. **更多 verifier-friendly IR protection tests**：对 `BPFAdjustOpt`、`BPFPreserveStaticOffset`、`BPFAbstractMemberAccess` 增加 regression coverage，防止新的 InstCombine/GVN/SimplifyCFG 变更破坏 BPF。

不适合直接进 LLVM backend、应留在 bpfopt 的方向：

- 依赖 map runtime value 或 map fd/object 的 pass：`map_inline`。
- 依赖 verifier log/state 的 pass：verifier-state `const_prop`、ReJIT 后的 `dce`、部分 bounds reasoning。
- 依赖 helper/program type runtime 语义的 pass：`skb_load_bytes_spec`、packet bounds-check merge。
- 依赖外部 PMU profile 的 pass：`branch_flip`。
- 依赖 fork-only kop/ReJIT ABI 的 pass：`rotate`、`cond_select`、`ccmp`、`extract`、`endian_fusion`、`bulk_memory`、`prefetch`。除非这些能力先变成上游 Linux BPF ISA/helper/kfunc 的稳定 ABI，否则 LLVM upstream 不能合理默认生成它们。

贡献路径：

- LLVM backend 代码和 tests：按 LLVM 当前流程走 GitHub Pull Request；官方文档说明 LLVM 已迁移到 GitHub PR，Phabricator 只读。
- BPF ABI、helper/kfunc、verifier 语义变化：先在 Linux BPF 社区讨论，目标列表是 `bpf@vger.kernel.org`；必要时同步 LLVM reviewer。
- LLVM 测试位置：优先加 `llvm/test/CodeGen/BPF/` 和对应 IR/MIR regression test。

## 7. 我们独有的 contribution 维度

LLVM BPF backend 的优化层级是：

1. LLVM IR middle-end：通用 scalar optimization + BPF 插入的 verifier/CO-RE 保护 pass。
2. SelectionDAG：legalization、DAG combine、BPF instruction selection。
3. MachineInstr：MachineDCE/CSE/LICM、BPF peephole、branch relaxation、CORE pseudo simplification。
4. MC/AsmPrinter/BTF：生成 ELF/BTF/relocation。

bpfopt 的层级更低：它处理已经编译出的 `struct bpf_insn[]`,由 upstream
application 进程内的 shim 调用,并把 candidate 交给 stock
`BPF_PROG_LOAD` verifier/JIT。这带来几个 LLVM AOT backend 没有的维度：

- **运行时对象可见性**：bpfopt 能看到 map value、loaded program、actual program type、helper id、verifier state。LLVM 只能看到源码/IR/ELF relocation。
- **verifier feedback loop**：LLVM 只能静态猜测 verifier 是否接受；shim 可以以 candidate `BPF_PROG_LOAD` 成功/失败和 verifier log 作为事实边界。
- **宿主能力**：LLVM BPF backend 必须在 AOT 编译时做决定；bpfopt 可以在目标机器上选择普通 BPF-to-BPF 变换。KOperation 是另一论文线,不属于 speculative stock-kernel path。
- **post-load profile**：LLVM PGO 依赖编译期 profile 输入；bpfopt 的 `branch_flip` 可以消费真实 BPF program/site 的 PMU profile。
- **不改变 app build chain**：很多真实 corpus app 的 BPF 程序来自上游二进制或已有 build artifact；bpfopt 可以优化这些已存在 bytecode，而 LLVM upstream 只能影响重新编译路径。

因此，LLVM upstream 的最佳定位是让 AOT BPF 输出更 verifier-friendly、更少冗余、更好维护 CO-RE/BTF 语义；bpfopt 的最佳定位是 deployment-aware specialization，特别是 map/profile 与 loader-state 这几类 LLVM 编译期不可见的信息。
