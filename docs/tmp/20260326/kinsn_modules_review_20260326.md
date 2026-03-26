# 2026-03-26 kinsn 模块审查报告

## 范围与方法

本次只审查以下 3 个新模块及其直接相关集成点：

1. `module/arm64/bpf_ldp.c`
2. `module/x86/bpf_bulk_memory.c`
3. `module/arm64/bpf_bulk_memory.c`

参考了以下文件：

- `module/x86/bpf_rotate.c`
- `module/x86/bpf_select.c`
- `module/arm64/bpf_endian.c`
- `module/arm64/bpf_rotate.c`
- `module/include/kinsn_common.h`
- `docs/kinsn-design.md`
- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/insn.rs`
- `daemon/src/kfunc_discovery.rs`
- `daemon/src/pass.rs`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/arch/{x86,arm64}/net/bpf_jit_comp.c`

说明：

- 当前仓库并没有活跃的 `model_call / bpf_kinsn_effect` 路径；`docs/kinsn-design.md:109` 已明确 verifier 语义仍以 `instantiate_insn()` 为准。因此本报告的“Verifier Modeling”审查，实际按“`instantiate_insn()` 与 native emit 是否一致”来做。
- 没有运行内核态加载或 VM 测试；结论来自源码审读、与 daemon payload 打包代码对照，以及用 `llvm-mc` 对若干 ARM64/x86 指令编码做抽样比对。

## 总体结论

结论：**需要先修复，再测试**。

主要原因有三：

1. `module/x86/bpf_bulk_memory.c` 存在一个 **CRITICAL** 级问题：缺少 `len <= 128` 校验，`instantiate_*()` 可在 verifier 为 proof sequence 分配的缓冲区上越界写。
2. `module/arm64/bpf_bulk_memory.c` 存在一个 **HIGH** 级问题：`memcpy` 的 native emitter 忽略了 payload 里的 `tmp_reg` 语义，JIT 路径与 proof 语义不一致。
3. `module/x86/bpf_bulk_memory.c` 还有一个 **HIGH** 级问题：`value_from_reg` 的 `memset` 路径在 `val_reg == BPF_REG_1` 时会读取已被改写的 `RDI`。

`module/arm64/bpf_ldp.c` 本身的 A64 编码、offset 约束和 `base != dst*` 安全性总体是对的，但目前仍有集成和 ABI fail-closed 方面的低优先级问题。

---

## 1. `module/x86/bpf_bulk_memory.c`

### CRITICAL

#### 1. 缺少 `len <= 128` 校验，`instantiate_*()` 可能越界写 proof buffer

位置：

- `module/x86/bpf_bulk_memory.c:72`
- `module/x86/bpf_bulk_memory.c:102`
- `module/x86/bpf_bulk_memory.c:123`
- `module/x86/bpf_bulk_memory.c:144`
- `module/x86/bpf_bulk_memory.c:441`
- `module/x86/bpf_bulk_memory.c:449`
- `vendor/linux-framework/kernel/bpf/verifier.c:3775`
- `vendor/linux-framework/kernel/bpf/verifier.c:3780`

问题描述：

- `decode_memcpy_payload()` 把 `len` 解成 `kinsn_payload_u8(payload, 40) + 1`，但没有像 ARM64 版本那样显式限制 `len <= 128`。
- `decode_memset_payload()` 同样没有限制 `len <= 128`。
- 但 descriptor 却声明：
  - `bpf_memcpy_bulk_desc.max_insn_cnt = 128 * 2 = 256`
  - `bpf_memset_bulk_desc.max_insn_cnt = 128`
- verifier 会先按 `max_insn_cnt` 分配 `proof_buf`，再调用 `instantiate_insn()` 写入；只有写完以后才通过 `validate_kinsn_proof_seq()` 检查 `cnt > max_insn_cnt`。

影响：

- 当 payload 带入 `129..255` 字节时：
  - `instantiate_memcpy()` 会生成 `2 * len` 条 proof 指令，可能写出 `proof_buf` 边界。
  - `instantiate_memset()` 会生成 `len` 条 proof 指令，可能写出 `proof_buf` 边界。
- 这不是“返回错误太晚”的问题，而是 **在返回错误之前已经发生越界写**。

建议修复：

- 在两个 decode 函数中统一加上 `len == 0 || len > KINSN_BULK_MAX_BYTES` 的拒绝。
- 不要依赖 daemon 当前只会发 `<=128B` chunk；kernel module 必须独立 fail-closed。

### HIGH

#### 2. `value_from_reg` 的 `memset` native emit 在 `val_reg == BPF_REG_1` 时语义错误

位置：

- `module/x86/bpf_bulk_memory.c:87`
- `module/x86/bpf_bulk_memory.c:109`
- `module/x86/bpf_bulk_memory.c:417`
- `module/x86/bpf_bulk_memory.c:421`
- `module/x86/bpf_bulk_memory.c:424`

问题描述：

- `decode_memset_payload()` 允许 `value_from_reg = 1`，也允许 `val_reg == BPF_REG_1`。
- 但 `emit_memset_x86()` 先：
  1. `push` 保存旧 `RDI`
  2. 用 `emit_addr_setup()` 把 `RDI` 改写成目标地址
  3. 然后才在 `value_from_reg` 分支执行 `movzx eax, <val_reg>.b`

如果 `val_reg == BPF_REG_1`：

- proof 语义是“按原始 `r1` 的低 8 bit 填充”
- native emit 实际读取的却是“改写后的 dst pointer 的低 8 bit”

这会直接导致 JIT 路径与 proof 语义不一致。

说明：

- 当前 daemon v1 的 `pack_memset_payload()` 并不发 `value_from_reg = 1`，所以这条 bug 暂时不一定从现有 pass 触发。
- 但模块 ABI 已经接受该 payload 形态，因此模块自身仍然是错误的。

建议修复：

- 最稳妥的方式是在 clobber `RDI` 之前，先把 `val_reg` 的 byte 冻结到 `RAX`。
- 如果短期不想支持该形态，至少要在 decode 阶段拒绝 `value_from_reg && val_reg == BPF_REG_1`。

### LOW

#### 3. packed payload 的保留高位没有 fail-closed

位置：

- `module/x86/bpf_bulk_memory.c:68`
- `module/x86/bpf_bulk_memory.c:99`

问题描述：

- `memcpy` payload 当前只消费到 bit 51。
- `memset` payload 当前只消费到 bit 43。
- 但 x86 版本 decode 没有像 ARM64 版本那样检查高位保留位是否为 0。

影响：

- 一旦 daemon 侧 payload 布局未来漂移，x86 module 可能静默接受并“部分忽略”额外位，调试难度高。

建议修复：

- `memcpy` 增加 `if (payload >> 52) return -EINVAL;`
- `memset` 增加 `if (payload >> 44) return -EINVAL;`

### 其他核对结果

- `REP MOVSB` / `REP STOSB` 前缀编码正确，分别是 `F3 A4` 和 `F3 AA`。
- `RDI/RSI/RCX` 在 `memcpy` 路径上的保存/恢复逻辑总体是对的：
  - 当某个寄存器被 payload 选作最终 `tmp_reg` 时，模块有意不恢复它，这与 proof 序列“`tmp_reg` 持有最后一个字节”一致。
  - 其余情况下会正确恢复。
- `RBP/R13` 作为 base 的 ModRM 特例处理是对的，和现有 x86 模块风格一致。
- `max_emit_bytes = 48` 从静态长度上看足够，没有看到 emit buffer 溢出的风险。

---

## 2. `module/arm64/bpf_bulk_memory.c`

### HIGH

#### 1. `memcpy` native emitter 忽略了 payload 的 `tmp_reg`，与 proof 语义不一致

位置：

- `module/arm64/bpf_bulk_memory.c:66`
- `module/arm64/bpf_bulk_memory.c:135`
- `module/arm64/bpf_bulk_memory.c:427`
- `module/arm64/bpf_bulk_memory.c:441`
- `module/arm64/bpf_bulk_memory.c:445`
- `module/arm64/bpf_bulk_memory.c:473`

问题描述：

- `decode_memcpy_payload()` 明确把 `tmp_reg` 作为 ABI 的一部分解出来。
- `instantiate_memcpy_bulk()` 也确实用这个 `tmp_reg` 展开成字节级 `LDX_MEM/STX_MEM`；因此 proof 语义是“copy 结束后，`tmp_reg` 持有最后一个被加载的 byte”。
- 但 `emit_memcpy_bulk_arm64()` 在 native 路径里直接 `(void)tmp_reg;`，完全忽略该寄存器，只用内部 scratch `x11/x12` 做 `LDP/STP` 和 tail load/store。

结果：

- proof/JIT 两条执行路径的寄存器效果不一致。
- 只要 payload 合法、且调用方对 `tmp_reg` 的最终值有依赖，native JIT 就会 miscompile。

补充说明：

- 当前 `daemon/src/passes/bulk_memory.rs` 的确通过 liveness 过滤，尽量只重写 `tmp_reg` dead-out 的 site。
- 但这是 pass 的当前策略，不是 module ABI 的一部分；module 本身没有任何检查去拒绝“`tmp_reg` 语义可观察”的 payload。

建议修复：

- 正确做法是让 native emitter 也把最后一个 byte 写回 payload 指定的 `tmp_reg`。
- 如果暂时不想支持该语义，就必须在 decode 或 emit 阶段显式拒绝此类 payload；不能一边接受 ABI，一边静默丢掉寄存器效果。

### LOW

#### 2. `LDP/STP` loop 没有做地址对齐门控，正确性依赖于 ARM64 对 unaligned normal-memory access 的容忍

位置：

- `module/arm64/bpf_bulk_memory.c:59`
- `module/arm64/bpf_bulk_memory.c:90`
- `module/arm64/bpf_bulk_memory.c:453`
- `module/arm64/bpf_bulk_memory.c:462`
- `module/arm64/bpf_bulk_memory.c:520`

问题描述：

- `memcpy` / `memset` 的 native 路径会直接走 `LDP/STP` 16B loop。
- decode 只验证 byte window 和长度，不验证 `src_off` / `dst_off` 的 8-byte 或 16-byte 对齐。
- proof 语义是纯字节 load/store，不携带这类对齐假设。

这在当前 Linux/ARM64 的 normal memory 上大概率可以工作，但它意味着：

- native 路径比 proof 语义引入了更强的隐含前提；
- 如果未来想把这个 kinsn 明确定义成“对所有 proof-legal payload 都无条件等价”，这里还不够 fail-closed。

建议修复：

- 如果项目希望严格保守：
  - 让 daemon 只在可证明对齐时才发 ARM64 bulk site；
  - 或在 module 里对齐不足时拒绝 native emit。
- 如果决定接受当前假设，建议至少把这一点写进模块注释或设计文档，避免后续把它误当成“无条件等价”的通用 memcpy。

### 其他核对结果

- `a64_ldp_post_x()` / `a64_stp_post_x()`、`a64_add_imm()`、`a64_sub_imm()`、`a64_subs_imm()`、`a64_movz()`、`a64_orr_lsl()`、`a64_and_imm_0xff()` 的编码常量与 `llvm-mc` 抽样结果一致。
- `x9/x10/x11/x12` 在当前 JIT 映射下是可用 scratch：
  - `x9 = BPF_REG_AX`
  - `x10/x11/x12 = TMP_REG_1/2/3`
  - `x13` 在当前 vendor arm64 JIT 里未被映射到 BPF 可见寄存器
- `payload >> 52` / `payload >> 44` 的高位保留位校验做得比 x86 版本更好。
- `len <= 128`、byte window 和 `len % width == 0` 的约束是齐的，不存在 x86 版本那种 proof buffer 上界漏洞。
- `max_emit_bytes = 160/128` 从静态 emitted instruction 数量估算是够的。

---

## 3. `module/arm64/bpf_ldp.c`

### LOW

#### 1. `bpf_ldp128` / `bpf_stp128` 还没有接到当前 daemon discovery / registry 流水线

位置：

- `module/arm64/bpf_ldp.c:9`
- `module/arm64/bpf_ldp.c:10`
- `daemon/src/kfunc_discovery.rs:22`
- `daemon/src/pass.rs:337`
- `daemon/src/pass.rs:368`

问题描述：

- 模块侧已经导出了 `bpf_ldp128` / `bpf_stp128` stub，并在 `module/arm64/Makefile` 中接入构建。
- 但当前 daemon registry 里没有这两个 target：
  - `KNOWN_KINSNS` 没有对应项
  - `KinsnRegistry` 也没有对应 BTF ID 字段

影响：

- 就当前仓库状态而言，这两个 kinsn 还不能通过现有 daemon 的自动发现/发射路径端到端使用。
- 因此“packed ABI / sidecar 与 emit 端一致性”的验证目前只能做到 module 单边审查，做不到整条用户态流水线闭环。

建议修复：

- 如果这两个模块的目标是“本轮就可用”，需要补上 discovery / registry / emit 侧集成。
- 如果只是先落模块，建议在文档里明确标注“module ready, daemon integration pending”。

### LOW

#### 2. payload 保留位校验不完整，只检查了 bit 31:28，没有拒绝 bit 63:32

位置：

- `module/arm64/bpf_ldp.c:45`
- `module/arm64/bpf_ldp.c:54`

问题描述：

- 当前 payload 实际只消费到：
  - `lane0` bits `[3:0]`
  - `lane1` bits `[7:4]`
  - `base` bits `[11:8]`
  - `offset` bits `[27:12]`
- `decode_pair_payload()` 只用 `kinsn_payload_reg(payload, 28)` 检查了 `[31:28]` 这 4 bit。
- `payload` 的其余高位 `[63:32]` 如果非零，模块会静默忽略。

影响：

- 这不是立即的功能性 bug，但 packed ABI 不够 fail-closed。
- 与 `module/arm64/bpf_bulk_memory.c` 的高位保留位校验风格也不一致。

建议修复：

- 如果这套 payload 打算长期稳定，建议直接做整段高位保留位检查，例如拒绝 `payload >> 32` 非 0。

### 其他核对结果

- `a64_ldp_x()` / `a64_stp_x()` 的 signed-offset 编码是对的；抽样对照 `llvm-mc` 结果一致。
- `imm7` 范围检查 `[-512, 504]` 且要求 `off % 8 == 0`，与 `LDP/STP Xt, Xt2, [Xn, #imm]` 的 64-bit pair form 一致。
- `decode_ldp_payload()` 对 `dst_lo == dst_hi`、`dst_* == BPF_REG_10`、`base == dst_*` 的禁止是必要且正确的：
  - 这不是 ARM64 ISA 的硬性写回约束；
  - 但如果不禁止，proof 展开里的第二条 `LDX_MEM` 会在 `base` 被首条 load 覆盖后读错地址，和 native `LDP` 语义不一致。
- `decode_stp_payload()` 不禁止 `base == src*` 是可以接受的；对于 signed-offset `STP`，这与 proof 里的两条 `STX_MEM` 语义一致。
- `max_emit_bytes = 4`、`max_insn_cnt = 2` 与实现匹配。
- 模块生命周期、`MODULE_*` 信息和 Makefile 接入方式与现有 ARM64 模块风格一致，没有看到额外问题。

---

## Makefile 与生命周期检查

### `module/x86/Makefile`

- `obj-m += bpf_bulk_memory.o` 已加入，集成正确。

### `module/arm64/Makefile`

- `obj-m += bpf_ldp.o`
- `obj-m += bpf_bulk_memory.o`

两项都已加入，集成正确。

### 生命周期 / 元数据

- 三个模块都通过 `DEFINE_KINSN_V2_MODULE(...)` 注册，风格与现有模块一致。
- `MODULE_DESCRIPTION` / `MODULE_LICENSE("GPL")` / `MODULE_AUTHOR("BpfReJIT")` 都由公共宏统一提供。
- 没有看到和现有模块风格不一致的 init / metadata 问题。

---

## 问题汇总

### CRITICAL

1. `module/x86/bpf_bulk_memory.c`：缺少 `len <= 128` 校验，`instantiate_*()` 可能在 verifier proof buffer 上越界写。

### HIGH

1. `module/arm64/bpf_bulk_memory.c`：`memcpy` native emit 忽略 `tmp_reg`，proof/JIT 语义不一致。
2. `module/x86/bpf_bulk_memory.c`：`value_from_reg` 的 `memset` 在 `val_reg == BPF_REG_1` 时会读取被改写后的 `RDI`。

### LOW

1. `module/x86/bpf_bulk_memory.c`：payload 保留高位未 fail-closed。
2. `module/arm64/bpf_bulk_memory.c`：`LDP/STP` loop 未对齐门控，native 等价性依赖于当前 ARM64 对 unaligned normal-memory access 的假设。
3. `module/arm64/bpf_ldp.c`：当前 daemon 尚未接入 `bpf_ldp128` / `bpf_stp128`。
4. `module/arm64/bpf_ldp.c`：payload 高位保留位校验不完整。

---

## 推荐修复顺序

1. 先修 `module/x86/bpf_bulk_memory.c` 的长度上界校验。这是唯一的 CRITICAL，且会影响 verifier proof lowering 的内存安全。
2. 再修两个 native/proof 语义不一致问题：
   - ARM64 `memcpy_bulk` 的 `tmp_reg`
   - x86 `memset_bulk(value_from_reg)` 的 `RDI` 覆盖
3. 最后补 fail-closed 和集成问题：
   - x86/ARM64 payload 保留位校验
   - `bpf_ldp128` / `bpf_stp128` 的 daemon 发现与发射链路
   - 如项目希望严格保守，再决定是否为 ARM64 bulk path 增加对齐门控

---

## 最终评估

### `module/arm64/bpf_ldp.c`

- **编码和基本语义层面基本可以接受**
- 但当前还不是“端到端 ready”，因为 daemon 侧尚未接线，且 payload fail-closed 还不够完整

### `module/x86/bpf_bulk_memory.c`

- **不建议进入测试**
- 需要先修复 proof-buffer 越界和 `value_from_reg` 语义错误

### `module/arm64/bpf_bulk_memory.c`

- **不建议进入测试**
- A64 编码本身没看到明显问题，但 `memcpy` native emit 与 proof 语义不一致，属于先修复再测的类型

### Overall

**整体结论：needs fixes first，不适合直接开始功能测试或 VM 回归。**
