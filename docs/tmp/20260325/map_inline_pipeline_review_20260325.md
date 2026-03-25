# Map Inline Pipeline 代码审查报告

**日期**: 2026-03-25
**审查范围**: `daemon/src/passes/map_inline.rs`, `const_prop.rs`, `dce.rs`, `analysis/map_info.rs`, `passes/mod.rs`, `passes/utils.rs`
**审查人**: Claude Opus 4.6

---

## P0: 正确性 Bug

### P0-1: `classify_r0_uses_from()` 不跟踪控制流，HASH map speculative inline 可能替换错误路径的 load

**文件**: `daemon/src/passes/map_inline.rs:673-699`

`classify_r0_uses_from()` 从 null check 之后线性扫描指令流，收集所有 `r0` 的 `LDX_MEM` 使用。但它不跟踪控制流分支。对于 HASH map speculative inline，null check (`JEQ r0, 0, +N`) 之后有两条路径：

- **non-null path** (fall-through): 字段 load 是安全的
- **null path** (跳转目标): `r0` 为 NULL，字段 load 不应替换

当前实现从 null check PC 之后顺序扫描，**只会收集 non-null path 的 load**（因为 null path 是 jump target），这在典型的 clang 生成模式下是正确的。但如果 null path 的跳转目标在 non-null path 之后（即 null path 代码在 non-null path 下方），线性扫描会在遇到 `r0` 重定义前扫过 null path 代码，可能错误地收集 null path 中对 `r0` 的 load。

**风险评估**: 低。clang 生成的 null check 几乎总是 `JEQ r0, 0, +N`（正向跳转到 null handler），non-null path 紧跟在 null check 之后。但非 clang 编译器或手写 BPF 可能不遵循此模式。

**建议**: 在 `classify_r0_uses_from()` 中遇到分支指令时停止扫描，或使用 CFG 信息限制扫描范围到 null check 的 fall-through 基本块。

---

### P0-2: `insn_defines_reg()` 对 CALL 指令的寄存器定义过于宽泛

**文件**: `daemon/src/passes/map_inline.rs:729-735`

```rust
fn insn_defines_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        // ...
        BPF_JMP | BPF_JMP32 => insn.is_call() && reg <= 5,
        // ...
    }
}
```

BPF CALL 指令 clobber r0-r5，所以 `reg <= 5` 是正确的。但 `is_call()` 只检查 `code == (BPF_JMP | BPF_CALL)`，这**包括 pseudo-call (src_reg=1)** 和 **kfunc call (src_reg=2)**，这些调用也确实 clobber r0-r5，所以这是正确的。

**结论**: 无 bug，但 `reg <= 5` 的意图不够明显，建议加注释说明 "CALL clobbers r0-r5"。

---

### P0-3: `const_prop` 的 `solve_block_entry_states()` 数据流分析对入口块初始状态处理有问题

**文件**: `daemon/src/passes/const_prop.rs:136-160`

入口块（block 0）没有前驱，`merge_predecessor_states(&[], &block_out)` 返回 `unknown_state()`（全 None）。这意味着**函数入口的参数寄存器 r1-r5 被认为是未知的**，这是正确的——const_prop 不应该假设入口参数的值。

但对于 **subprog 入口块**，如果 subprog 入口也没有前驱（CFG 不跟踪 inter-procedural edges），其初始状态也是全 None，这也是安全的（保守的）。

**结论**: 正确，无 bug。保守处理保证了安全性。

---

### P0-4: `const_prop` 的 NOP 替换在 `fixup_all_branches` 之后重写可能破坏分支目标

**文件**: `daemon/src/passes/const_prop.rs:111-117`

```rust
super::utils::fixup_all_branches(&mut new_insns, &program.insns, &addr_map);
for old_pc in nop_pcs {
    let new_pc = addr_map[old_pc];
    if new_pc < new_insns.len() {
        new_insns[new_pc] = BpfInsn::nop();
    }
}
```

`fixup_all_branches()` 根据 addr_map 修正了所有分支偏移。然后循环把折叠为 not-taken 的条件跳转强制写为 NOP（`ja +0`）。这是因为 `fold_jump_instruction` 产生的 NOP 在 `fixup_all_branches` 中可能被错误修正（它看到 old insn 是 cond_jmp，就会尝试 fixup new insn 的 off 字段）。

**潜在问题**: 如果某条原始条件跳转被折叠为 NOP，`fixup_all_branches` 看到原始指令是 `is_jmp_class()` 且非 call/exit，就会修改 `new_insns[new_pc].off`，把 NOP 的 `off` 改成一个非零值。随后 `nop_pcs` 循环再把它写回 `BpfInsn::nop()`（off=0）。**这个顺序是正确的——先 fixup（会破坏 NOP），再恢复 NOP**。

但如果一个被折叠为 `JA offset`（taken 分支）的条件跳转，`fixup_all_branches` 看到原始指令是 cond_jmp，也会对 `new_insns[new_pc]` 做 fixup。新指令是 `JA`（也是 `is_jmp_class()`），所以 fixup 会修正其 `off` 字段。但 fixup 使用的是**原始跳转目标**（`old_pc + 1 + old_off`），而 fold 产生的 JA 使用的是**相同的 old_off**，所以 fixup 后目标一致。这是正确的。

**结论**: 正确。NOP 恢复步骤弥补了 fixup 的副作用。

---

### P0-5: `emit_constant_load()` (map_inline) 对负值 u32 范围常量的处理

**文件**: `daemon/src/passes/map_inline.rs:502-508`

```rust
fn emit_constant_load(dst_reg: u8, value: u64, size: u8) -> Vec<BpfInsn> {
    if size == BPF_DW || value > i32::MAX as u64 {
        return emit_ldimm64(dst_reg, value);
    }
    vec![BpfInsn::mov64_imm(dst_reg, value as i32)]
}
```

`i32::MAX as u64` = `0x7FFF_FFFF`。如果 map value 中的一个 u32 字段值为 `0x8000_0000`（2147483648），`value > i32::MAX as u64` 为 true，会生成 LDIMM64。但实际上这是一个 32 位 load（size != BPF_DW），用 `mov64_imm` 加一个负 i32 就可以表示。LDIMM64 也能正确加载这个值，只是多用了一条指令。

**这不是 correctness bug**——LDIMM64 的语义是正确的，只是代码效率略低。对比 `const_prop.rs:443-448` 中的 `emit_constant_load()`，那个版本使用 `as_mov64_imm()` 检查 sign-extension 兼容性，更精确。

**建议**: 统一两处 `emit_constant_load` 实现。map_inline 版本可以用 `as_mov64_imm()` 逻辑替代 `value > i32::MAX as u64` 检查。

---

## P1: E2E 失败根因分析

### P1-1: "no direct value access support for this map type" — 非 map_inline 导致

**E2E 错误**: `vfs_unlink_ret` (prog 259), scx progs, Tracee lkm_seeker 等

**根因**: 此错误发生在 verifier 验证 `BPF_LD_IMM64` 指令时，`src_reg = BPF_PSEUDO_MAP_VALUE (2)` 引用了不支持直接值访问的 map 类型（如 `perf_event_array` (type 4)、`prog_array` (type 3)、`ringbuf` (type 27) 等）。

**关键证据**:
- `vfs_unlink_ret` 的 daemon log 显示 `map_inline` pass `changed: false, sites_applied: 0`，skip reasons: `"map type 6 not inlineable in v1": 1, "map type 1 not inlineable in v1": 1`。**map_inline 正确跳过了这些 map**。
- 错误发生在 `const_prop` + `dce` 变换后的 REJIT 阶段。

**实际原因**: 这不是 map_inline pipeline 的 bug。这是 **fd relocation (`relocate_map_fds`)** 的问题。`relocate_map_fds` 处理 `BPF_PSEUDO_MAP_VALUE` (src_reg=2) 引用时，正确替换了 FD，但某些 map 类型（如 percpu_array type 6）在 REJIT 上下文中不支持 `BPF_PSEUDO_MAP_VALUE` 直接值访问。这可能是因为原始程序的 `BPF_PSEUDO_MAP_VALUE` 引用指向了一个在原始 load 时被 verifier 特殊处理的 map 类型。

**注意**: `map_info.rs` 中 `MapInfoAnalysis` 只扫描 `BPF_PSEUDO_MAP_FD` (src_reg=1)，完全忽略 `BPF_PSEUDO_MAP_VALUE` (src_reg=2)。虽然这不是当前错误的直接原因（因为 map_inline 不处理 MAP_VALUE 引用），但未来如果需要处理 MAP_VALUE 引用，需要扩展分析。

**建议**:
- 在 daemon 的 REJIT pipeline 入口处，检测 `BPF_PSEUDO_MAP_VALUE` 引用的 map 类型，如果不支持直接值访问，跳过 REJIT。
- 这不是 map_inline/const_prop/dce 的 bug，而是 REJIT 前置检查的缺失。

---

### P1-2: "unreachable insn 4" — DCE 或 const_prop 产生的 unreachable 代码

**E2E 错误**: Tracee lkm_seeker 系列程序

**根因分析**:

从 daemon log 中 `prog 740 (lkm_seeker_mod_)` 的记录可以看到：
```
WARN: pass 'dce' caused verifier rejection at PC 94 for prog 740 (lkm_seeker_mod_)
      Disabling 'dce', retrying...
```

**daemon 已有 pass-level retry 机制**——当某个 pass 导致 verifier 拒绝时，禁用该 pass 并重试。这说明 DCE 在某些情况下确实会产生 verifier 不接受的 unreachable code。

**具体原因**: BPF verifier 要求程序中**不能有 unreachable 指令**。如果 const_prop 折叠了一个分支但 DCE 未能完全清除 dead code（例如某个 dead 块通过非标准跳转仍可达），verifier 会拒绝。另一种情况是 DCE 正确删除了 unreachable block 但**分支修正**有误，导致某条指令变成 unreachable。

对于 "unreachable insn 4" 的具体 Tracee 程序（131 条指令），bytecode 开头是：
```
insn 0: MOV64 r9, r1
insn 1-2: LDIMM64 r1, ...
insn 3: MOV64_IMM r1, 0
insn 4: STX_W [r10-64], r1
```

insn 3 (`MOV64_IMM r1, 0`) 覆盖了 insn 1-2 加载到 r1 的值。如果 const_prop 在 insn 1-2 和 insn 3 之间插入了额外的逻辑或者 DCE 删除了 insn 1-2 但没有正确处理后续引用，可能导致 insn 4 变成 unreachable。

**但更可能的原因是**: 此程序原本包含 `BPF_PSEUDO_MAP_FD` 或 `BPF_PSEUDO_MAP_VALUE` 引用导致 verifier 在 PC 0 就失败（"func#0 @0, unreachable insn 4"），这意味着 verifier 在分析 func#0 的入口时就发现 PC 4 unreachable——这可能是 LDIMM64 (2 条指令) 被某种方式破坏后，verifier 在 PC 2 处看到了一个无效的 insn 从而跳过了后续指令。

**建议**:
- 在 DCE 的 `eliminate_unreachable_blocks_with_cfg()` 中增加 sanity check：删除后的程序不应有 verifier 认为 unreachable 的指令。
- daemon 的 pass-level retry 机制已能缓解此问题，但应追踪 root cause 以修复。

---

### P1-3: "Permission denied (os error 13)" — 非 pipeline 相关

**E2E 错误**: 多个 Tetragon/scx 程序

这些错误发生在程序 **load** 阶段（`load_error: "Permission denied"`），与 map_inline pipeline 无关。可能原因：
- 缺少 CAP_BPF/CAP_SYS_ADMIN 权限
- pinned map 文件权限问题
- 程序类型不被当前内核版本支持

---

### P1-4: "call to invalid destination" — DCE 删除 subprog 后 pseudo-call 目标失效

**文件**: `daemon/tests/results/static_verify.daemon.log:123`

`prog 151 (sysctl_monitor)`: DCE 删除了 21 条 unreachable insns 后，REJIT 失败，verifier 报 "call to invalid destination"。

**根因**: DCE 使用 `eliminate_unreachable_blocks_with_cfg()` 删除 unreachable blocks，然后 `fixup_surviving_branches()` 修正分支偏移。但如果 DCE 删除了 **subprog 内部的 unreachable 代码**，可能导致 pseudo-call 的目标偏移计算错误。

查看 `daemon/src/passes/utils.rs:82-88`:

```rust
for subprog in &cfg.subprogs {
    if subprog.start < insns.len() {
        entry_blocks.insert(cfg.insn_to_block[subprog.start]);
    }
}
```

**DCE 正确保留了 subprog 入口块**。但问题可能在于 `fixup_surviving_branches()` 修正 pseudo-call 偏移时：

```rust
if insn.is_call() && insn.src_reg() == 1 {
    let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
    ...
    let new_imm = new_target as i64 - (new_pc as i64 + 1);
    new_insns[new_pc].imm = new_imm as i32;
}
```

`insn.src_reg() == 1` 检查 `BPF_PSEUDO_CALL`。但 `is_call()` 返回 true 时 `src_reg` 可能是 0（helper call）、1（pseudo-call）、2（kfunc call）。代码只修正 `src_reg == 1`，**helper call 和 kfunc call 不被修正**，这是正确的（它们的 imm 不是 PC-relative offset）。

**可能的 bug**: 如果原始程序中 pseudo-call 的目标地址计算 `old_target` 超出了 `old_n` 范围（例如 `old_pc + 1 + imm` 溢出），`old_target < old_n` check 会跳过修正，导致 REJIT 后 pseudo-call 指向错误位置。

但更可能的原因是 `sysctl_monitor` 程序中 **DCE 删除了某些指令后，REJIT 时 map FD relocation 重新分配了 LD_IMM64 的 imm 值，导致 verifier 看到的 pseudo-call 目标与实际 subprog 入口不一致**。这需要进一步分析具体 bytecode。

---

## P2: 性能问题

### P2-1: `prev_real_pc()` 每次调用 O(n) 时间复杂度

**文件**: `daemon/src/passes/map_inline.rs:647-663`

```rust
fn prev_real_pc(insns: &[BpfInsn], pc: usize) -> Option<usize> {
    let mut cursor = 0usize;
    let mut prev = None;
    while cursor < pc {
        prev = Some(cursor);
        cursor += insn_width(&insns[cursor]);
    }
    ...
}
```

此函数从指令流开头遍历到 `pc`，查找前一条真实指令的 PC。每次调用 O(n)。

`find_map_load_for_call()` 和 `find_constant_stack_store()` 都循环调用 `prev_real_pc()`，**导致最坏情况 O(n^2) 的回溯**。对于 `mega_basic_bloc` (13777 insns) 这样的大程序，如果 lookup 模式分散在程序各处，性能可能显著下降。

**建议**: 预计算一个 `prev_pc: Vec<Option<usize>>` 数组，一次 O(n) 扫描建立前驱映射，后续查找 O(1)。

---

### P2-2: `reference_at_pc()` 线性扫描

**文件**: `daemon/src/analysis/map_info.rs:75-77`

```rust
pub fn reference_at_pc(&self, pc: usize) -> Option<&MapReference> {
    self.references.iter().find(|reference| reference.pc == pc)
}
```

每次调用 O(m)，其中 m 是 map reference 数量。在 `MapInlinePass::run()` 中对每个 lookup site 调用一次。如果程序有大量 map reference（如 `lkm_seeker_kset` 有 1538 sites），总复杂度 O(n*m)。

**建议**: 将 `references` 用 `HashMap<usize, &MapReference>` 索引，或在 `MapInfoResult` 中维护一个 `pc -> index` 的 HashMap。

---

### P2-3: `solve_block_entry_states()` 迭代次数无上限保护

**文件**: `daemon/src/passes/const_prop.rs:144-157`

数据流分析 fixpoint 循环没有最大迭代次数限制。虽然 lattice 是有限的（每个寄存器从 None 变到 Some(v) 或保持 None，一旦两个路径值不同变为 None 就不再变化），**理论上保证收敛**，但对于有大量循环回边的程序，迭代次数可能较多。

实际风险低：lattice 高度为 2（unknown -> Some(v) -> unknown），每个寄存器最多变化 2 次，11 个寄存器，所以总变化上限 22 * block_count。

**建议**: 添加 `max_iterations` 安全阀（例如 `blocks.len() * 50`），超过后返回保守结果。

---

### P2-4: `program.insns.clone()` 在 DCE 中

**文件**: `daemon/src/passes/dce.rs:34`

```rust
let mut final_insns = program.insns.clone();
```

无论是否有变更都先 clone 整个指令流。对于 13000+ 条指令的大程序，这是不必要的内存开销。

**建议**: 延迟 clone，只在确定有变更时才分配新 Vec。或者直接使用引用，只在写入时 clone。

---

## P3: 代码质量

### P3-1: `emit_constant_load` 函数重复定义

**文件**:
- `daemon/src/passes/map_inline.rs:502-508` — 带 `size` 参数
- `daemon/src/passes/const_prop.rs:443-449` — 不带 `size` 参数

两个版本逻辑略有不同：
- map_inline: `value > i32::MAX as u64` (unsigned 比较)
- const_prop: `as_mov64_imm()` (sign-extension 检查)

const_prop 的版本更正确，因为它处理了负 i32 可以 sign-extend 到 64 位的情况（例如 `0xFFFFFFFF_FFFFFFFE` 可以用 `MOV64_IMM r, -2` 表示）。

**建议**: 提取到 `utils.rs` 中统一实现。

---

### P3-2: `emit_ldimm64` 函数重复定义

**文件**:
- `daemon/src/passes/map_inline.rs:510-525`
- `daemon/src/passes/const_prop.rs:456-471`

完全相同的实现。

**建议**: 提取到 `utils.rs` 或 `insn.rs` 中。

---

### P3-3: `insn_width` 函数重复定义

**文件**:
- `daemon/src/passes/map_inline.rs:665-671`
- `daemon/src/passes/const_prop.rs:492-498`
- `daemon/src/passes/utils.rs:215-221`

三处完全相同的实现。

**建议**: 在 `insn.rs` 或 `BpfInsn` 上提供 `fn width(&self) -> usize` 方法。

---

### P3-4: `insn_uses_reg` 和 `insn_defines_reg` 无单元测试

**文件**: `daemon/src/passes/map_inline.rs:701-735`

这两个函数是 `classify_r0_uses` 正确性的关键依赖，但没有独立的单元测试。特别是：
- `insn_uses_reg` 对 `BPF_ST` 的处理 (`insn.dst_reg() == reg`): BPF_ST 将 imm 存到 `[dst + off]`，`dst` 是 base address register，被当作 "use" 是正确的。
- `insn_uses_reg` 对 `BPF_ALU MOV` 的特殊处理 (line 704-706): MOV 不 "use" dst，只 define 它。这是正确的。
- `insn_defines_reg` 对 CALL 的 `reg <= 5`: CALL clobber r0-r5，所以 define 了 r0-r5。正确。

**建议**: 添加针对边界情况的单元测试。

---

### P3-5: `find_immediate_null_check` 只识别 `JEQ r0, 0, +N` 模式

**文件**: `daemon/src/passes/map_inline.rs:527-537`

```rust
fn find_immediate_null_check(insns: &[BpfInsn], call_pc: usize) -> Option<usize> {
    let pc = call_pc + 1;
    let insn = insns.get(pc)?;
    (insn.code == (BPF_JMP | BPF_JEQ | BPF_K)
        && insn.dst_reg() == 0
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0)
        .then_some(pc)
}
```

不识别以下等价模式：
1. `JNE r0, 0, +N`（跳到 non-null path）
2. `JEQ r0, r_zero` 其中 r_zero 为已知零值寄存器
3. 指令间有 NOP/JA+0 间隔
4. `JMP32` 变体

**影响**: 减少可优化的 site 数量，但不影响正确性。

**建议**: 扩展匹配模式，或使用 const_prop 的常量信息来识别。

---

### P3-6: `extract_constant_key` 的栈回溯不够完备

**文件**: `daemon/src/passes/map_inline.rs:84-98`

`find_r2_stack_pointer_setup` 严格要求 call 前两条指令分别是 `MOV r2, r10` 和 `ADD r2, -offset`。但 clang 可能生成以下变体：

1. **MOV 和 ADD 之间有其他指令**（如设置 r3-r5 参数）
2. **LEA 模式**: `r2 = r10 + offset` 用一条 `ADD` 完成（没有 MOV）
3. **key 通过多次 store 构建**（如 8 字节 key 用两次 4 字节 store）

**影响**: 减少可优化的 site 数量，但不影响正确性。

---

### P3-7: `const_prop` 不追踪 STX/ST 对内存的影响

**文件**: `daemon/src/passes/const_prop.rs:193-235`

`analyze_instruction` 的 `match` 不处理 `BPF_STX`/`BPF_ST` class——这些指令不改变寄存器状态，所以被 `_ => (next, None)` 默认处理。这是正确的（存储指令不定义寄存器）。

但这也意味着 **const_prop 无法追踪"store 后 load 同一栈位置"的常量值**，即 store-to-load forwarding。这限制了 const_prop 在 map_inline 之后的效果——如果 map_inline 的某些 pattern 依赖栈上的常量值被 load 回来，const_prop 无法折叠。

**影响**: 优化机会损失，非正确性问题。

---

### P3-8: pass 顺序隐式依赖缺乏文档

**文件**: `daemon/src/passes/mod.rs:51-117`

`PASS_REGISTRY` 定义了 pass 顺序：`map_inline -> const_prop -> dce -> wide_mem -> ...`

但依赖关系没有在代码中显式声明：
- `const_prop` 依赖 `map_inline` 先将 map value load 转为常量 MOV（否则无常量可传播）
- `dce` 依赖 `const_prop` 先折叠分支（否则无 dead code 可消除）
- `dce` 必须在 `wide_mem` 之前（否则 NOP 指令可能影响 wide_mem pattern 匹配）

`required_analyses()` 声明了分析依赖，但 **pass 间的变换依赖** 没有被表达。

**建议**: 在 `PASS_REGISTRY` 注释中明确记录 pass 间依赖关系。

---

### P3-9: `MapInfoAnalysis` 不处理 `BPF_PSEUDO_MAP_VALUE` (src_reg=2)

**文件**: `daemon/src/analysis/map_info.rs:112`

```rust
if insn.is_ldimm64() && pc + 1 < insns.len() && insn.src_reg() == BPF_PSEUDO_MAP_FD {
```

只扫描 `src_reg == 1`（`BPF_PSEUDO_MAP_FD`），忽略 `src_reg == 2`（`BPF_PSEUDO_MAP_VALUE`）。

`BPF_PSEUDO_MAP_VALUE` 引用表示指令直接加载 map value 的地址（已在 verifier 阶段解析），不需要 map_inline 再处理。但 `unique_maps` 中缺少这些 map 的信息，可能影响其他需要完整 map 列表的分析。

**当前影响**: 无，因为 map_inline 不需要处理 MAP_VALUE 引用。但代码注释应说明这个有意的限制。

---

## Action Items 清单

| 优先级 | ID | 描述 | 文件 |
|--------|------|------|------|
| **P1** | P1-1 | 在 REJIT 前检测 BPF_PSEUDO_MAP_VALUE 引用的 map 是否支持直接值访问，不支持则跳过 REJIT | `daemon/src/bpf.rs` |
| **P1** | P1-4 | 调查 sysctl_monitor (prog 151) DCE 后 "call to invalid destination" 的具体原因，检查 fixup_surviving_branches 在删除指令后是否正确修正 pseudo-call 偏移 | `daemon/src/passes/utils.rs:176-213` |
| **P2** | P2-1 | 将 `prev_real_pc()` 改为预计算 prev_pc 数组，消除 O(n^2) 回溯 | `daemon/src/passes/map_inline.rs:647-663` |
| **P2** | P2-2 | `reference_at_pc()` 改用 HashMap 索引 | `daemon/src/analysis/map_info.rs:75-77` |
| **P2** | P2-4 | DCE 延迟 clone insns，只在确定有变更时分配 | `daemon/src/passes/dce.rs:34` |
| **P3** | P3-1 | 统一两处 `emit_constant_load` 实现 | `map_inline.rs:502`, `const_prop.rs:443` |
| **P3** | P3-2 | 统一两处 `emit_ldimm64` 实现 | `map_inline.rs:510`, `const_prop.rs:456` |
| **P3** | P3-3 | 统一三处 `insn_width` 实现为 `BpfInsn::width()` 方法 | `map_inline.rs:665`, `const_prop.rs:492`, `utils.rs:215` |
| **P3** | P3-4 | 为 `insn_uses_reg` 和 `insn_defines_reg` 添加单元测试 | `map_inline.rs:701-735` |
| **P3** | P3-5 | 扩展 null check 识别模式（JNE, JMP32 变体） | `map_inline.rs:527-537` |
| **P3** | P3-8 | 在 `PASS_REGISTRY` 中添加 pass 间依赖关系注释 | `passes/mod.rs:51` |

---

## 总结

Map inline pipeline 的核心算法逻辑（find_map_lookup_sites, extract_constant_key, classify_r0_uses, build_site_rewrite）在 clang 生成的标准 BPF bytecode 上是正确的。const_prop 的数据流分析和分支折叠实现正确，ALU 运算的溢出和符号扩展处理无误。DCE 的 unreachable block 消除和 NOP fixpoint 消除也是正确的。

E2E 测试失败的三类错误中：
1. **"no direct value access"** 是 REJIT 前置检查缺失，与 map_inline pipeline 无关
2. **"unreachable insn"** 和 **"call to invalid destination"** 可能与 DCE/const_prop 的 branch fixup 有关，daemon 已有 pass-level retry 缓解机制
3. **"Permission denied"** 与 pipeline 完全无关

主要性能瓶颈在 `prev_real_pc()` 的 O(n^2) 复杂度和 `reference_at_pc()` 的线性扫描。代码质量方面，主要问题是跨文件的函数重复定义和缺少边界条件测试。
