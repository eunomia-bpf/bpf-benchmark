# LLVM IR 替代 BPF Bytecode 层做 `map_inline + const_prop + DCE` 可行性调研

日期：2026-03-29  
范围：实现可行性调研，不改代码，不跑 host kernel BPF 测试

## 结论摘要

- **可行，但建议做成“新增的 LLVM-specialization 子路径”，不要直接 wholesale 替换当前全部 BPF-level pass。**
- **最小 POC 不需要改 LLVM BPF backend**，前提是 scope 只做 `map_inline + const_prop + dce`，且输出里**不保留**新的 global/map-address 语义，也**不碰 kinsn**。
- **最大技术风险不是 lifter，也不是 SCCP，而是 verifier 兼容性**：`llvmbpf` 从 bytecode lift 出来的 IR 是“弱类型/弱语义”的，缺少 BPF verifier 真正在乎的 `PTR_TO_CTX` / static-offset / loop-bound / pointer provenance 信息。`bpftime` 自己的文档也明确写了这一点。
- `llvmbpf` **现有** array-map inline 实现可以证明“helper call 在 LLVM IR 里可重写、再让 LLVM 做级联优化”这条路是对的；但它的实现方式是把 `value_base` 变成**宿主机地址常量**，这条路**不能直接**拿来回到 kernel verifier。
- **kinsn 不适合放进第一阶段 LLVM 路线。** 当前树里的 kinsn 是 `sidecar + BPF_PSEUDO_KINSN_CALL` 自定义传输格式；upstream LLVM BPF backend 没有直接支持。第一阶段应继续保留现有 bytecode/kinsn 路线。
- 时间线判断：
  - **1 周**：可以做出一个窄 POC，覆盖 `ARRAY + constant key + fixed-offset scalar loads`，并在 1-2 个小程序上 round-trip 成功。
  - **2 周**：有机会把它接到 daemon 的旁路工具里，并在 1 个真实程序上拿到 verifier-stable 结果。
  - **1 个月**：才接近“可默认开启”的工程化水平；如果把 `kinsn` 也纳入 LLVM 路线，1 个月都偏乐观。

## 调研方法与来源

本报告基于四类来源：

1. 本仓库当前实现与已有调研文档：
   - [`docs/daemon-architecture.md`](../../daemon-architecture.md)
   - [`docs/kinsn-design.md`](../../kinsn-design.md)
   - [`docs/tmp/20260326/map_inline_coverage_analysis_20260326.md`](../20260326/map_inline_coverage_analysis_20260326.md)
   - [`docs/tmp/20260326/map_inline_performance_validation_20260326.md`](../20260326/map_inline_performance_validation_20260326.md)
   - [`docs/tmp/2026-03-11/llvmbpf-array-map-inline-poc.md`](../2026-03-11/llvmbpf-array-map-inline-poc.md)
2. `llvmbpf` / `bpftime` 源码与文档：
   - <https://github.com/eunomia-bpf/llvmbpf>
   - <https://github.com/eunomia-bpf/bpftime>
3. upstream LLVM BPF backend 源码：
   - <https://github.com/llvm/llvm-project/tree/main/llvm/lib/Target/BPF>
4. 论文/文档：
   - `bpftime` 论文：<https://arxiv.org/abs/2311.07923>
   - `!XDP` 论文：<https://marioskogias.github.io/docs/uxdp.pdf>
   - LLVM LangRef `llvm.assume`：<https://llvm.org/docs/LangRef.html#llvm-assume-intrinsic>

---

## 1. BPF -> LLVM IR lifter 现状

### 1.1 代码位置

`llvmbpf` 的 lifter 主体就在这几个文件里：

- `generateModule()`：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler.cpp#L89-L1091>
- helper call lowering：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler_utils.cpp#L313-L349>
- array-map helper inline：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/llvm_jit_context.cpp#L374-L470>
- public API：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/include/llvmbpf.hpp#L29-L147>
- CLI `-emit-llvm`：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/cli/main.cpp>

`bpftime` 直接把 `llvmbpf` 当它的 LLVM backend 用：

- runtime program wrapper：
  <https://github.com/eunomia-bpf/bpftime/blob/master/runtime/src/bpftime_prog.cpp#L106-L218>
- VM compat wrapper：
  <https://github.com/eunomia-bpf/bpftime/blob/master/vm/compat/llvm-vm/compat_llvm.hpp>
  和
  <https://github.com/eunomia-bpf/bpftime/blob/master/vm/compat/llvm-vm/compat_llvm.cpp>

### 1.2 能 lift 什么

从 `compiler.cpp` 顶部的 supported instruction comment 和主 `switch` 来看，`llvmbpf` 已覆盖：

- 大部分 ALU/ALU64
- load/store / `LDDW`
- 条件跳转 / `JA`
- helper call
- local BPF-to-BPF call / subprog
- atomic ops

直接证据：

- supported instruction 注释：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler.cpp#L41-L88>
- local function / subprog 入口和 call stack：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler.cpp#L261-L353>
  与
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler.cpp#L1058-L1091>

质量证据：

- `README` 明确接了 `bpf-conformance`：
  <https://github.com/eunomia-bpf/llvmbpf/blob/main/README.md#test-with-bpf-conformance>
- 公布的 conformance 结果里，`call_local.data`、`callx.data`、`lddw.data`、`rfc9669_call_local.data` 都是 PASS：
  <https://eunomia-bpf.github.io/llvmbpf/bpf_conformance_results.txt>

### 1.3 不能直接等同于“可回 kernel verifier 的 lifter”

这点很关键。

`bpftime` 自己的文档写得很直白：

> “Generated LLVM IR from eBPF bytecode. We don't add type information to the IR at this level, so some constraints maybe missing, such as the type of the function, loop bounds, pointer layout, etc.”

来源：

- <https://github.com/eunomia-bpf/bpftime/blob/master/tools/aot/optimize.md#llvm-jit>

这意味着：

- 它是一个**对 userspace/native JIT 很有用**的 lifter
- 但不是一个“保留 verifier 语义元数据”的 typed-lifter
- 如果目标是 `LLVM opt -> LLVM BPF backend -> kernel verifier`，这部分缺失会成为主要风险

### 1.4 feature 级判断

| 特性 | `llvmbpf` 现状 | 结论 |
| --- | --- | --- |
| local subprog | 明确支持；有自建 call stack/return block | 可用 |
| helper call | 明确支持，helper 统一成 `i64 (i64,i64,i64,i64,i64)` call | 可用 |
| `LDDW` map reloc | 明确支持，甚至可 compile-time patch `map_val` | 可用 |
| tail call | helper `12` 特判后直接 `br exit` | **仅是 userspace 语义近似，不是 kernel prog-array control transfer** |
| map-in-map / prog-array | runtime 里有 map 类型，但 lifter 不做类型语义建模 | **只能当 opaque helper/map handle，不能指望自动优化** |
| verifier-friendly type metadata | 文档明确说缺失 function type / loop bound / pointer layout | **主要短板** |

### 1.5 其他 BPF -> LLVM IR 工具

我做了 GitHub 定向搜索，公开可见、维护中的结果基本是：

- `eunomia-bpf/llvmbpf`：<https://github.com/eunomia-bpf/llvmbpf>
- `userspace-xdp` / `!XDP`：更偏“保留原始 LLVM IR + 重新编译成 eBPF”的 toolchain，不是通用 bytecode lifter；论文见 <https://marioskogias.github.io/docs/uxdp.pdf>
- `buytenh/bpf2ir`：<https://github.com/buytenh/bpf2ir>，仓库描述是 **classic BPF** 到 LLVM IR
- `mmisono/cbpf-to-llvm-ir`：<https://github.com/mmisono/cbpf-to-llvm-ir>，也是 **cBPF**

所以，**如果问题限定为“eBPF bytecode -> LLVM IR lifter”**，我没有找到第二个和 `llvmbpf` 同量级、同成熟度的公开实现。

结论：

- **现实可用的基础设施就是 `llvmbpf/bpftime`。**
- 其他公开仓库大多是 classic BPF，不能替代。

---

## 2. 在 LLVM IR 层注入 map 常量的具体方案

### 2.1 lifted IR 里 `bpf_map_lookup_elem` 长什么样

`llvmbpf` 给所有 external helper 建统一签名：

```c++
FunctionType *helperFuncTy = FunctionType::get(
    Type::getInt64Ty(*context),
    { i64, i64, i64, i64, i64 },
    false);
```

来源：

- <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler.cpp#L132-L148>

helper call lowering 是：

```c++
auto callInst = builder.CreateCall(
    helperFuncTy, itr->second,
    { load r1, load r2, load r3, load r4, load r5 });
builder.CreateStore(callInst, regs[0]);
```

来源：

- <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/compiler_utils.cpp#L313-L349>

所以 lifted IR 里，`bpf_map_lookup_elem` 本质是：

```llvm
declare i64 @_bpf_helper_ext_0001(i64, i64, i64, i64, i64)
```

即：

- arg0 = map handle / map fd-like constant
- arg1 = key pointer，按 `i64` 传
- ret = `i64` pointer-like value

后续如果程序对 lookup result 做解引用，IR 里通常会出现：

- `inttoptr i64 %lookup to ptr`
- `getelementptr`
- `load`

### 2.2 `llvmbpf` 已经证明的一件事

`llvmbpf` 已经有现成的 array-map helper inline pass，会把 `_bpf_helper_ext_0001` call 改成：

- 取 `key`
- bounds check
- `value_base + index * stride`
- `select(in_range, addr, 0)`

来源：

- <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/llvm_jit_context.cpp#L374-L470>

这证明两件事：

1. **helper-site IR rewrite 完全可行**
2. rewrite 之后再跑一轮 LLVM 优化，也完全可行：
   <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/llvm_jit_context.cpp#L496-L529>

### 2.3 但这个现成实现不能直接拿来回 kernel

原因不是 LLVM，而是 **verifier pointer provenance**。

`llvmbpf` 现有实现把 `value_base` 变成实际地址常量：

```c++
auto *address = builder.CreateAdd(builder.getInt64(valueBase), offset);
auto *result = builder.CreateSelect(inRange, address, builder.getInt64(0));
```

来源：

- <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/llvm_jit_context.cpp#L423-L460>

这在 userspace native JIT 里没问题；但对 kernel verifier 来说：

- 这不是合法的 `PTR_TO_MAP_VALUE` 来源
- 最终 BPF 里不能留下“任意绝对地址常量”
- `BPF_PROG_REJIT` ABI 也只给你 `insns + fd_array`，没有新 data/global section 传输面

直接证据：

- `BPF_PROG_REJIT` UAPI 只有 `prog_fd/insns/log_buf/fd_array/flags`：
  [`vendor/linux-framework/include/uapi/linux/bpf.h`](../../vendor/linux-framework/include/uapi/linux/bpf.h)
  第 `1936-1945` 行

这意味着：

- **“把 map value_base 变成指针常量”只适合 userspace JIT**
- **“回到 kernel 的正确方案”必须是把 lookup 的“后续 load 结果”变成常量，而不是把 lookup pointer 本身变成常量**

### 2.4 推荐的 kernel-target 方案

我认为第一阶段最对路的实现是：

1. 用 `llvmbpf` lift 全程序
2. 在 IR 里识别 `_bpf_helper_ext_0001(map_const, key_const_or_key_provable_const, ...)`
3. 追踪其后续 `load` uses：
   - `%lookup -> inttoptr -> gep const_off -> load i8/i16/i32/i64`
4. 直接用 live map snapshot 把这些 `load` 替换成 `ConstantInt`
5. 再跑 `SCCP + ADCE + SimplifyCFG` 清掉分支和 dead code
6. 最终输出的 BPF 里只剩 scalar immediates，不再依赖 fake map pointer

这条路和当前 bytecode pass 的语义是对齐的，但在 LLVM 里更容易做，因为 LLVM 有：

- SSA
- use-def chain
- CFG
- dominator-driven simplification

### 2.5 `global constant` 和 `llvm.assume` 应怎么用

我建议把它们分成主方案和辅助手段：

#### 主方案：`global constant` / 直接常量替换

适合：

- control/config map
- constant key
- fixed-offset scalar loads

目标不是让 `@snapshot_global` 最终留在输出 BPF 里，而是：

- 先用它喂 LLVM 的常量传播
- 再让 `SCCP/ADCE/SimplifyCFG` 把它**完全折掉**

如果最终 lowered BPF 里还残留这些 fake globals，那条路就不适合当前 `BPF_PROG_REJIT` ABI。

#### 辅助手段：`llvm.assume`

适合表达：

- `nonnull`
- `idx < max_entries`
- `align`
- `dereferenceable`

LLVM 官方语义：

- `llvm.assume` 允许 optimizer 假定条件为真
- 不生成代码
- 条件被违反时是 UB

来源：

- LLVM LangRef：
  <https://llvm.org/docs/LangRef.html#llvm-assume-intrinsic>
- 对应本地源码：
  `/tmp/llvm-project-research/llvm/docs/LangRef.rst:30825-30866`

但它有个边界：

- `llvm.assume` **不能凭空制造常量值**
- 它更适合去掉 null-check / bounds-check
- 真正让 `constprop + dce` 爆发，还是得靠**把 load 结果本身替换成常量**

### 2.6 LLVM 标准 pass 会不会自动级联

会，但要分开看：

- `SCCP`：最重要，负责跨 CFG 的常量传播
- `GVN`：负责重复 load / 冗余计算合并
- `SimplifyCFG`：负责分支折叠、空块清理、merge blocks
- `ADCE/DCE`：在条件分支被折叠后把 dead path 删掉

LLVM 文档里的定义：

- `GVN`：<https://llvm.org/docs/Lexicon.html#gvn>
- `SCCP`：<https://llvm.org/docs/Lexicon.html#sccp>

### 2.7 LLVM IR 示例

下面这个例子不是从仓库里直接 dump 出来的 `.ll`，但**helper ABI 是按 `llvmbpf` 真实生成方式写的**，用于说明 transformation shape。

#### Before：lifted helper call

```llvm
declare i64 @_bpf_helper_ext_0001(i64, i64, i64, i64, i64)

define i32 @bpf_main(ptr %ctx, i64 %len) {
entry:
  %key.slot = alloca i32, align 4
  store i32 0, ptr %key.slot, align 4
  %key64 = ptrtoint ptr %key.slot to i64

  %lookup = call i64 @_bpf_helper_ext_0001(i64 5, i64 %key64, i64 0, i64 0, i64 0)
  %nonnull = icmp ne i64 %lookup, 0
  br i1 %nonnull, label %load, label %ret0

load:
  %p = inttoptr i64 %lookup to ptr
  %flag = load i32, ptr %p, align 4
  %enabled = icmp ne i32 %flag, 0
  br i1 %enabled, label %fast, label %ret0

fast:
  ret i32 1

ret0:
  ret i32 0
}
```

假设 live snapshot 里：

- map id `5`
- key `0`
- value bytes `[01 00 00 00]`

#### After A：map snapshot injection

```llvm
@map5_key0_snapshot = private unnamed_addr constant [1 x i32] [i32 1], align 4

define i32 @bpf_main(ptr %ctx, i64 %len) {
entry:
  %flag = load i32, ptr getelementptr ([1 x i32], ptr @map5_key0_snapshot, i64 0, i64 0), align 4
  %enabled = icmp ne i32 %flag, 0
  br i1 %enabled, label %fast, label %ret0

fast:
  ret i32 1

ret0:
  ret i32 0
}
```

#### After B：`SCCP + SimplifyCFG + ADCE`

```llvm
define i32 @bpf_main(ptr %ctx, i64 %len) {
entry:
  ret i32 1
}
```

如果只是已知 non-null / in-range，而值本身不常量，可以辅以：

```llvm
declare void @llvm.assume(i1)

; e.g. key 已知永远 < max_entries
call void @llvm.assume(i1 %in.range)
```

---

## 3. kinsn 在 LLVM IR 里的表示

### 3.1 当前树里的 kinsn 不是普通 helper/kfunc

当前实现的核心事实：

- transport 是 `BPF_PSEUDO_KINSN_SIDECAR + BPF_PSEUDO_KINSN_CALL`
- canonical semantics 来自 `instantiate_insn(payload, insn_buf)`
- verifier 先 lower 成 proof sequence，再 restore
- JIT 侧再走 native emit callback

来源：

- [`docs/kinsn-design.md`](../../kinsn-design.md)
- `BPF_PSEUDO_KINSN_*` UAPI：
  [`vendor/linux-framework/include/uapi/linux/bpf.h`](../../vendor/linux-framework/include/uapi/linux/bpf.h)
  第 `1382-1394` 行

这不是 upstream LLVM BPF backend 天然会生成的东西。

### 3.2 LLVM IR 里可选的三种表示

| 方案 | 形式 | 优点 | 问题 |
| --- | --- | --- | --- |
| inline asm | `call asm ...` | 最省 frontend 表达 | 语义对 LLVM 不透明，基本放弃优化，不推荐 |
| ordinary call | `declare i64 @bpf_rotate64(...)` | 最接近现有 BPF/kfunc toolchain | 只能自然 lower 成普通 call/kfunc，不会自动变成当前 kinsn transport |
| custom intrinsic | `llvm.bpf.kinsn.rotate64(...)` | 最适合以后教 backend 识别 | 需要改 backend/MC/test，第一阶段不值得 |

### 3.3 LLVM BPF backend 现在能做什么

upstream LLVM BPF backend 已经能把“普通 extern/global function call” lower 成 BPF `JAL` / call relocation：

- `LowerCall()`：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFISelLowering.cpp#L474-L619>
- call pattern：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFInstrInfo.td#L876-L880>
- `JAL` symbol fixup：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/MCTargetDesc/BPFMCCodeEmitter.cpp#L108-L117>
- `R_BPF_64_32` relocation：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/MCTargetDesc/BPFELFObjectWriter.cpp#L38-L79>

它还能给 extern function 产出 BTF FUNC 信息：

- `extern-var-func.ll` test：
  <https://github.com/llvm/llvm-project/blob/main/llvm/test/CodeGen/BPF/BTF/extern-var-func.ll>

Linux side 对普通 kfunc 的用户态写法也是 `extern ... __ksym`：

- 例如：
  [`vendor/linux-framework/tools/testing/selftests/bpf/progs/task_kfunc_success.c`](../../vendor/linux-framework/tools/testing/selftests/bpf/progs/task_kfunc_success.c)
  第 `21-30` 行

结论：

- **如果目标是“把某个 LLVM call lower 成普通 BPF kfunc call”**，LLVM 现有设施是够用的。
- **如果目标是“lower 成当前树里的 `sidecar + PSEUDO_KINSN_CALL`”**，我没有找到现成支持。

### 3.4 如果一定要让 LLVM 产出当前 kinsn 传输格式

需要的改动大致是：

1. 新的 IR 约定：
   - custom intrinsic 或 metadata 标识“这是 kinsn，不是普通 call”
2. SelectionDAG / machine IR lowering：
   - 识别该 intrinsic，产出自定义 pseudo machine op
3. BPF MC emission：
   - 在 call 前插 sidecar pseudo-insn
   - 把 `src_reg` 编成 `BPF_PSEUDO_KINSN_CALL`
4. payload 编码：
   - 把 dst/off/imm packing 回 sidecar
5. tests：
   - MIR / MC / asm / verifier round-trip test

估算：

- **不含 clang 前端语法糖**，仅 backend/MC/test，大约 `400-800` 行 C++ 改动是合理量级
- 如果再加“从 C builtin / intrinsic 到 LLVM IR 的 frontend 支持”，还要再往上加

我的判断：

- **第一阶段不该做。**
- `map_inline` 路线与 `kinsn` 路线最好先分治。

---

## 4. Verifier 兼容性

### 4.1 “LLVM BPF backend 能过 verifier 吗”

能，但要加限定词：

- **clang 生成的、带 BPF-specific metadata/IR discipline 的 IR**，当然可以
- **`llvmbpf` 从 bytecode lift 出来的 typeless IR**，不能默认认为“跑一遍 `-O3` 再 lower 回 BPF 就一定能过 verifier”

upstream LLVM 自己已经承认 BPF 有专门的“verifier-friendly” IR pass：

- `BPFCheckAndAdjustIR`：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFCheckAndAdjustIR.cpp#L1-L20>
- `BPFPreserveStaticOffset`：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFPreserveStaticOffset.cpp#L8-L103>
- `BPFAdjustOpt`：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFAdjustOpt.cpp#L1-L10>
- pass insertion点：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFTargetMachine.cpp#L122-L156>

### 4.2 已知 verifier 不兼容点

LLVM 源码里直接写出来的 BPF-specific 问题包括：

- relocation globals 不能进 PHI
- 某些 ctx field access 必须是 static immediate offset
- `PTR_TO_CTX` base pointer 访问前不能先被修改
- `SimplifyCFG / InstCombine / GVN` 会把 `gep + load/store` 形态打散，导致 verifier reject
- 某些 `icmp` canonicalization 会把 verifier 本来能证明安全的代码变成更保守、甚至被 reject 的形态
- 某些 speculative code motion 需要用 `__builtin_bpf_passthrough` 样的 barrier 挡住

直接证据：

- static-offset / `PTR_TO_CTX`：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFPreserveStaticOffset.cpp#L13-L65>
- `SimplifyCFG / GVN` 会破坏 verifier-friendly 形态：
  同上 `#L51-L55`
- `icmp` / speculation 调整：
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFAdjustOpt.cpp#L83-L137>
  和
  <https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/BPF/BPFAdjustOpt.cpp#L150-L267>

### 4.3 `llvmbpf` 对这个问题的处理

几乎没有，因为它的目标不是“再回 kernel verifier”，而是：

- 直接 JIT 到宿主 native
- 或 AOT 成宿主 object

它现在的 AOT path 明确是 host target machine：

- <https://github.com/eunomia-bpf/llvmbpf/blob/main/src/llvm_jit_context.cpp#L536-L560>

所以：

- `llvmbpf` 的成功运行不能证明 kernel verifier 兼容
- 它只能证明“lift + LLVM optimize”这条路本身不是空想

### 4.4 回 kernel 的额外约束

如果目标是 `BPF_PROG_REJIT`，额外约束至少有：

1. **不能留下宿主地址常量**
   - `llvmbpf` 现有 `value_base` rewrite 不可直接复用
2. **不能依赖新的 data/global transport**
   - `BPF_PROG_REJIT` 只有 `insns + fd_array`
3. **ctx access 必须 verifier-friendly**
   - 这是最危险的部分，因为 lift 出来的 IR 缺少 typed frontend metadata
4. **loops 不能随便做激进变换**
   - `bpftime` 文档明确说 loop bounds 信息可能缺失
5. **kfunc/kinsn/BTF 关系必须保留**
   - 这也是为什么我建议第一阶段完全不碰 kinsn

我的判断：

- **窄 POC 没有 show-stopper**
- **全程序 `-O3` round-trip 到 kernel，这件事现在有很高 verifier 风险**

---

## 5. 工程量评估

### 5.1 最小 POC 建议范围

建议 scope：

- 只做 `map_inline + const_prop + dce + simplifycfg`
- 只支持 `ARRAY`
- 只支持 constant map handle + constant key
- 只支持 lookup result 的 fixed-offset scalar loads
- **不做 kinsn**
- **不做 percpu/map-in-map/prog-array**
- **尽量不动 whole-module aggressive loop/GVN pipeline**

### 5.2 推荐工程形态

我更推荐：

- **单独的 C++ 工具/库**复用 `llvmbpf + LLVM`
- daemon 继续保持纯 Rust
- Rust daemon 通过 subprocess 或薄 FFI 调这个工具

理由：

- 当前 daemon 依赖非常轻：[`daemon/Cargo.toml`](../../daemon/Cargo.toml)
- 把 `llvm-sys` / C++ ABI 直接塞进 daemon 会显著抬高复杂度
- `llvmbpf` 本来就是 C++ API，不是现成的 Rust crate

### 5.3 工作项估算

| 工作项 | 预计改动 | 估计时间 | 备注 |
| --- | ---: | ---: | --- |
| 暴露/复用 `llvmbpf` lift API | `100-200` LOC | `0.5-1` 天 | 现在 `generateModule()` 是内部接口 |
| 新 IR pass：helper-site load replacement | `300-600` LOC | `2-3` 天 | 核心逻辑 |
| 保守 pass pipeline + BPF backend driver | `200-400` LOC | `1-2` 天 | 设 `bpfel/bpfeb` target machine |
| verifier round-trip harness | `150-300` LOC | `1` 天 | 最好在 VM 路径里做 |
| daemon 集成（subprocess） | `150-300` LOC | `1-2` 天 | map snapshot 输入、结果输出 |
| 单元/fixture/real-program regression | `250-500` LOC | `2-3` 天 | 这是必须花的时间 |

### 5.4 总体估计

- **最小 POC**：`1.2k-2.3k LOC`，`5-8` 个工作日
- **可在 daemon 中可控使用**：`2-3` 周
- **如果要把 kinsn 也纳入 LLVM 路线**：再加 `1-2` 周，且风险明显上升

### 5.5 要不要改 LLVM BPF backend

| 问题 | 需要改吗 |
| --- | --- |
| 仅 `map_inline + const_prop + dce`，最终全折成 scalar immediates | **大概率不需要** |
| 需要普通 kfunc call lowering | **大概率不需要** |
| 需要当前树里的 `PSEUDO_KINSN_CALL + sidecar` | **需要** |

### 5.6 要不要改 `bpftime/llvmbpf`

最小 POC 里，我认为需要的改动是“小改，不是大改”：

- 暴露一个稳定的 “bytecode -> Module/IR” API
- 可选：给 lifted helper call 加一点 metadata，方便后续 pass 识别 map lookup site
- 可选：给 ctx/register provenance 加 metadata；这是后续工程化方向，不是第一周必须项

---

## 6. 和当前 BPF-level pass 的对比

### 6.1 当前实现的现实边界

当前仓库里已有的数据很明确：

- corpus-wide：`9079` 个 daemon-recognized lookup sites，只命中 `61`
- 八个目标项目：`6271` 个 recognized lookup sites，只命中 `28`
- `katran:balancer_ingress`：`0` applied，`64` skipped
  - 其中 `42` 个是 `map type 6 not inlineable in v1`
  - `14` 个是 `lookup key is not a constant stack materialization`

来源：

- [`docs/tmp/20260326/map_inline_coverage_analysis_20260326.md`](../20260326/map_inline_coverage_analysis_20260326.md)
- [`docs/tmp/20260326/map_inline_performance_validation_20260326.md`](../20260326/map_inline_performance_validation_20260326.md)

### 6.2 LLVM IR 路线能明显解决什么

| 维度 | 当前 bytecode pass | LLVM IR 路线 |
| --- | --- | --- |
| use-def / SSA | 没有 | 有 |
| dominator / CFG simplification | 基本手写 | LLVM 现成 |
| key constant 恢复 | 依赖 stack materialization pattern matcher | 可做 SSA/dataflow 证明 |
| lookup 后 consumer 覆盖 | 主要盯 fixed-offset scalar load 形态 | 更容易追踪跨块 load/use，后续 DCE 也更强 |
| CSE/GVN | 很难做 | 现成 |
| branch collapse | 很局部 | `SCCP + SimplifyCFG` 很强 |
| LICM | 基本不可做 | 理论可做，但 verifier 风险高 |

### 6.3 但 LLVM 路线不能“自动解决”的东西

LLVM 不会凭空解决：

- `PERCPU_ARRAY`
- `HASH_OF_MAPS`
- `prog_array`
- tail call semantics
- 需要 verifier pointer provenance 的复杂 pointer program

换句话说：

- LLVM 路线**主要解决的是“分析能力不足”**
- 它**不能替代“语义范围本身没定义”**

### 6.4 Katran `balancer_ingress` 的现实预期

基于当前 skip 分布，我的判断是：

- LLVM IR 路线**很可能**能吃掉那部分“其实 key 是常量，但 bytecode matcher 没识别出来”的 site
- 也更可能在 lookup-site 之后清掉更长的 dead path
- 但对当前最主要的 `map type 6`（`PERCPU_ARRAY`）问题，**第一阶段并没有自动答案**

所以对 `balancer_ingress`，现实预期不是“64 个全转绿”，而是：

- **能恢复一部分 key/dataflow 问题**
- **不能绕过真正的 map-type semantic blocker**

按现有数据保守估计：

- `64` 个 skip 里，明显属于“LLVM SSA 能帮上忙”的至少是那 `14` 个 key-materialization misses
- `42` 个 `PERCPU_ARRAY` 仍需你先定义 snapshot 语义，LLVM 本身不解决

### 6.5 能做到当前做不到的什么

这是 LLVM 路线真正有价值的地方：

1. **PHI-aware constant propagation**
2. **跨 basic block 的 CSE / GVN**
3. **branch tree 折叠后的大块 DCE**
4. **更可靠的 null-check / bounds-check 删除**
5. **不必手写 use-def / dominator tree**

我的判断：

- 对 “control map -> branch gate -> dead code” 这类真实 pattern，LLVM 路线比现在的 bytecode pass 更像一个能扩展下去的基础设施。

---

## 7. 风险、blocker、时间线

### 7.1 风险矩阵

| 风险 | 影响 | 概率 | 说明 | 缓解 |
| --- | --- | --- | --- | --- |
| lifted IR 缺 verifier-relevant type/provenance | 高 | 高 | 最大风险 | 初期只跑保守 pass；后续给 lifter 补 metadata |
| 现有 `llvmbpf` array-map inline 用 host `value_base` | 高 | 高 | 不能直接回 kernel | 改做 load-result constant replacement |
| fake globals 最终没被折掉 | 高 | 中 | `BPF_PROG_REJIT` 没有新 global transport | 约束 pipeline；必要时直接替换成 immediates |
| `kinsn` lowering 不被 LLVM backend 支持 | 高 | 高 | 但只在你把 kinsn 纳入 scope 时成立 | 第一阶段不做 |
| `PERCPU_ARRAY` / map-in-map / prog-array 语义不清 | 中 | 高 | LLVM 不会自动补语义 | 第一阶段只做 `ARRAY` |
| daemon 集成把 LLVM 依赖灌进 Rust 主进程 | 中 | 中 | 工程复杂度上升 | 用独立 C++ 工具 |
| 性能收益不显著 | 中 | 中 | 当前 real-program 机会本来就窄 | 先证明“覆盖+code shrink”，再追 exec win |

### 7.2 show-stopper 判断

我把它分成两档：

#### 窄 POC

- **没有 show-stopper**

前提：

- 不碰 kinsn
- 不试图用 host pointer inline map value
- 只做 `ARRAY + constant key + scalar loads`

#### 全面替换当前 bytecode + kinsn 路线

- **现在有两个 show-stopper**

1. `llvmbpf` lift IR 丢失 verifier 关键信息
2. 当前树里的 kinsn transport 没有 LLVM backend 支持

### 7.3 时间线

| 时间 | 可交付物 |
| --- | --- |
| `1` 周 | standalone C++ POC，能 lift、specialize、lower，并在小样例上回到 verifier |
| `2` 周 | daemon 旁路集成，1 个真实程序稳定 round-trip |
| `1` 个月 | 才接近“可默认开启”的质量；包括更多 map type、回归测试、verifier corner cases |

---

## 8. 推荐方案

我的建议不是“彻底推翻当前 bytecode pass”，而是：

### 8.1 采用 hybrid 方案

1. **保留当前 bytecode/kinsn 路线**
   - `rotate`
   - `cond_select`
   - `extract`
   - `endian_fusion`
   - `bulk_memory`
2. **新增 LLVM specialization 子路径**
   - 只负责 `map_inline + const_prop + dce + simplifycfg`

### 8.2 第一阶段技术路线

1. `orig bytecode -> llvmbpf lift`
2. 自定义 IR pass：
   - 识别 `map_lookup_elem`
   - 用 snapshot 替换后续 scalar loads
3. 跑保守 pass：
   - `sccp`
   - `instsimplify`
   - `adce`
   - `simplifycfg`
   - `gvn` 可选，`licm` 初期关闭
4. `LLVM BPF backend -> BPF bytecode`
5. `BPF_PROG_REJIT`

### 8.3 这条路的正确目标

第一阶段不要追求：

- 全 map type 覆盖
- kinsn 全部进 LLVM
- whole-program `-O3`

第一阶段应该追求：

- **证明 LLVM IR 确实能把 current bytecode pass 很难做的 control-map specialization 做干净**
- **证明 final bytecode 还能稳定过 verifier**

---

## 9. 最终判断

如果问题是：

> “能不能用 LLVM IR 把现在手写的 `map_inline + const_prop + dce` 大幅简化？”

我的答案是：

- **能。**

如果问题是：

> “能不能把当前整个 BpfReJIT pass 体系都迁到 LLVM IR，并顺便把 kinsn 也统一进去？”

我的答案是：

- **现在不该这么做。**

更准确的建议是：

- **把 LLVM IR 路线限定为 map specialization 专线**
- **保留 bytecode/kinsn 路线处理 verifier-visible instruction synthesis**

这条路线的最大价值不是“LLVM 比手写 Rust 更聪明”这么简单，而是：

- 你终于站到了 **SSA/use-def/dominator/CFG** 上
- `constprop + dce + simplifycfg + gvn` 这套基础设施可以直接用
- 你不必继续在 flat instruction array 上堆更多一次性 matcher

但这条路线真正难的地方，也已经很清楚：

- **不是 map inline 本身**
- **而是“从 typeless lifted IR 再回到 verifier-friendly BPF”**

这决定了它值得做，但必须分阶段、保守落地。
