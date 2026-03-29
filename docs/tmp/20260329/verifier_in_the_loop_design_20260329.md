# verifier-in-the-loop 优化架构调研

日期：2026-03-29

## 结论摘要

结论先说在前：

1. 这个方向是可行的，但不是“把现有 `parse_verifier_log()` 直接接到 `const_prop` 前面”这么简单。
2. 现在最大的障碍不在内核，而在 daemon 侧：
   - `bpf_prog_load_verify()` 成功路径默认走 `log_level=0`，所以 accepted pass 根本拿不到 verifier log。见 `daemon/src/bpf.rs:1498-1518`。
   - verify callback 现在只回 `accepted/rejected`，不能把解析后的 verifier facts 写回 `BpfProgram`，因为 callback 签名是只读的。见 `daemon/src/pass.rs:892-910`。
   - 现有 `verifier_log.rs` 数据模型太弱，只保留 `reg_type/min/max/known/off`，而且 `known/min/max` 用的是 `i64`，会丢掉高位 `u64` 信息，也丢掉 `var_off`、`precise`、`id`、32/64 位分离范围等。见 `daemon/src/verifier_log.rs:27-33`、`daemon/src/verifier_log.rs:380-419`、`daemon/src/verifier_log.rs:469-515`。
3. 内核 `log_level=2` 输出里，真正“每条指令”的 `; R...` 不是完整寄存器文件，而是 delta-only 的 scratched state。完整 state 只在 `from <prev> to <pc>:` 等点打印。见 `vendor/linux-framework/kernel/bpf/log.c:749-865`、`vendor/linux-framework/kernel/bpf/verifier.c:21553-21640`。
4. 所以 verifier-in-the-loop 想做成稳定 oracle，至少要补三层：
   - syscall 层：成功路径也抓 log，并能处理 `ENOSPC/log_true_size`
   - parser 层：区分 full-state line 和 inline delta line，并保留更多字段
   - pass manager 层：accepted pass 后把新 verifier state 挂回 `program`，供下一个 pass 用
5. 相比当前 `const_prop`，kernel verifier 的精度明显更高：它有 `tnum`、`u64/s64/u32/s32` range、pointer/type tracking、branch refinement、precision backtracking；当前 `const_prop` 只有“11 个寄存器上的 exact constant 等值传播”。见 `daemon/src/passes/const_prop.rs:21-23`、`daemon/src/passes/const_prop.rs:153-188` 对比 `vendor/linux-framework/kernel/bpf/verifier.c:2176-2242`、`vendor/linux-framework/kernel/bpf/verifier.c:2372-2434`、`vendor/linux-framework/kernel/bpf/verifier.c:16982-17320`、`vendor/linux-framework/kernel/bpf/verifier.c:5032-5440`。

一句话判断：

- “把 kernel verifier 当免费的抽象解释 oracle”这个想法是对的。
- 但落地上应该先做“accepted pass 成功日志采集 + 原始事件模型 + exact constant oracle”，再做“full per-PC state reconstruction + branch oracle”。

## 调研方法

这次只做代码调研，没有修改代码，也没有改 `vendor/linux-framework`。

阅读对象：

- `daemon/src/passes/const_prop.rs`
- `daemon/src/verifier_log.rs`
- `daemon/src/commands.rs`
- `daemon/src/bpf.rs`
- `daemon/src/pass.rs`
- `daemon/src/passes/map_inline.rs`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/log.c`
- `vendor/linux-framework/include/linux/bpf_verifier.h`

另外跑了几项现有定向单测来校验静态结论：

- `cargo test verifier_log:: -- --nocapture`
- `cargo test test_verify_rejection_restores_last_accepted_snapshot_before_next_pass -- --nocapture`
- `cargo test test_optimize_one_result_records_rejected_pass_verify_status -- --nocapture`
- `cargo test test_populate_prog_load_attr_includes_btf_and_debug_info -- --nocapture`

全部通过。

## 1. 当前 `const_prop` 怎么算常量

### 1.1 当前数据模型

`const_prop` 的核心状态就是：

- `type RegConstState = [Option<u64>; 11]`，只跟踪 11 个寄存器是否是“精确常量”。见 `daemon/src/passes/const_prop.rs:21-23`。
- 没有 `tnum`
- 没有 signed/unsigned range
- 没有 32/64 位分离抽象值
- 没有 stack spill / stack slot 常量
- 没有 memory value tracking
- 没有 path-sensitive facts，只有 basic-block 入口 meet

block 级 fixed-point 是标准前向数据流：

- block entry 由前驱 `meet` 得到
- `meet` 规则是“所有前驱都 `Some(v)` 且值完全相等，才保留该常量；否则降成 `None`”  
  见 `daemon/src/passes/const_prop.rs:153-188`、`daemon/src/passes/const_prop.rs:473-485`。

这意味着它本质上是一个非常保守的 exact-equality lattice：

- `Some(42)` 和 `Some(42)` 合并后仍然是 `Some(42)`
- `Some(42)` 和 `Some(43)` 合并后直接退化成 `None`
- `Some(42)` 和 “已知在 `[40,44]`”这种信息根本无法表达

### 1.2 它实际支持什么

`analyze_instruction()` 只特别处理四类指令。见 `daemon/src/passes/const_prop.rs:210-259`。

1. `BPF_LD`
   - 普通 `ldimm64` 且 `src_reg == 0` 时，能解出 64-bit 立即数并把 `dst` 标成常量。见 `daemon/src/passes/const_prop.rs:218-234`、`daemon/src/passes/const_prop.rs:522-529`。
   - pseudo `ldimm64`（如 `MAP_FD` / `MAP_VALUE`）直接当成不可折叠，避免把 typed pseudo-imm 误重写成 plain scalar `LD_IMM64`。见 `daemon/src/passes/const_prop.rs:224-229`。

2. `BPF_LDX`
   - 无论 load 什么，`dst` 直接变未知。见 `daemon/src/passes/const_prop.rs:236-239`。

3. `BPF_ALU` / `BPF_ALU64`
   - 如果 `dst` 和 `src/imm` 都是 exact constant，就直接在 pass 里算结果。见 `daemon/src/passes/const_prop.rs:240-245`、`daemon/src/passes/const_prop.rs:294-319`、`daemon/src/passes/const_prop.rs:351-420`。
   - 支持的算子主要是 `MOV/NEG/ADD/SUB/MUL/DIV/MOD/OR/AND/XOR/LSH/RSH/ARSH`。见 `daemon/src/passes/const_prop.rs:298-319`、`daemon/src/passes/const_prop.rs:351-420`。
   - 对 32-bit ALU 会做零扩展/截断语义处理。见 `daemon/src/passes/const_prop.rs:423-460`。
   - 能把结果直接折成 `mov32_imm` / `mov64_imm` / `ldimm64`。见 `daemon/src/passes/const_prop.rs:262-277`、`daemon/src/passes/const_prop.rs:488-518`。

4. `BPF_JMP` / `BPF_JMP32`
   - helper / subprog call 之后，把 `R0-R5` 全部置未知。见 `daemon/src/passes/const_prop.rs:246-251`。
   - 条件跳转只有在比较双方都是 exact constant 时，才会折成 `JA` 或 `NOP`。见 `daemon/src/passes/const_prop.rs:252-254`、`daemon/src/passes/const_prop.rs:279-291`、`daemon/src/passes/const_prop.rs:321-349`。

### 1.3 它做不到什么

当前 `const_prop` 做不到这些：

- 不能利用 range 信息折叠 branch  
  例如 verifier 已知 `R0 in [0,1]`，那么 `if r0 > 1` 一定不成立；当前 `const_prop` 表达不了。
- 不能利用 `tnum` 折叠 bit-test  
  例如 `JSET` 在 verifier 的 `tnum` 上经常能提前判定；当前 pass 只有 exact constant 才能做。
- 不能利用 branch refinement  
  例如 true/false 分支后，verifier 会 refine range / `var_off`；当前 pass 完全不做这类 refine。
- 不能利用 pointer-null / pointer-type 语义  
  verifier 能处理 pointer-vs-0 比较、packet range、map/value pointer 类型；当前 pass 只看 `u64` 常量。
- 不能跨 stack spill/load 传递常量  
  `STX` 到栈上，再 `LDX` 回寄存器，当前 pass 完全丢失。
- 不能跟踪 helper 返回值、map value load 的 refined scalar、packet load 形成的 byte-range。
- 不能表达 path-sensitive 同一 PC 多个观察，只能 block entry 处做“相等才保留”的 meet。

### 1.4 和 kernel verifier 的精度差多少

差距很明显，而且不是一个量级上的微调。

kernel verifier 至少有这些当前 `const_prop` 没有的能力：

1. `tnum` 级别的 unknown-bit tracking
   - 常量判定直接看 `tnum_is_const()`。见 `vendor/linux-framework/kernel/bpf/verifier.c:5438-5455`。
2. 同时维护 `smin/smax/umin/umax/s32_min/s32_max/u32_min/u32_max`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:2176-2242`、`vendor/linux-framework/kernel/bpf/verifier.c:2372-2434`。
3. 算术后自动用 `var_off` 和 range 相互收紧
   - `__update_reg32_bounds()` / `__update_reg64_bounds()` 会用 `tnum` 推 bounds，甚至在交集只剩一个值时直接把寄存器收敛成 exact constant。见 `vendor/linux-framework/kernel/bpf/verifier.c:2372-2434`。
4. branch direction 判定不要求双方 exact constant
   - `is_scalar_branch_taken()` 会结合 `tnum overlap`、signed/unsigned range、32-bit subrange 来判定 `JEQ/JNE/JSET/JGT/...` 是否必然成立/不成立。见 `vendor/linux-framework/kernel/bpf/verifier.c:16982-17135`。
5. 条件之后的 range refinement
   - `regs_refine_cond_op()` 会把比较结果反向灌回两个寄存器的 `range/var_off`。见 `vendor/linux-framework/kernel/bpf/verifier.c:17273-17320`。
6. pointer/type-aware reasoning
   - pointer 与 0 的比较、packet pointer range、map value pointer、BTF pointer、stack pointer 都有专门语义。
7. precision backtracking
   - verifier 只有在确实需要 exact scalar 时才回溯标记 precise，这正是很多 “range -> exact const” 场景成立的原因。见 `vendor/linux-framework/kernel/bpf/verifier.c:5032-5440`。

所以如果目标是“常量传播尽量贴近内核真实接受条件”，verifier oracle 的信息量确实远大于当前 `const_prop` 自算。

## 2. 当前 verifier log 解析能力

### 2.1 已经存在 parser

`daemon/src/verifier_log.rs` 已经存在，不是空白起步。见 `daemon/src/verifier_log.rs:1-55`。

当前 parser 能解析三种 line：

- `from <prev> to <pc>: R...`
- `<pc>: R...`
- `<pc>: (insn) ... ; R...`

产物是 `Vec<VerifierInsn>`，每个元素有：

- `pc`
- `frame`
- `from_pc`
- `regs: HashMap<u8, RegState>`
- `stack: HashMap<i16, StackState>`  
  见 `daemon/src/verifier_log.rs:17-51`。

### 2.2 当前 parser 能提取什么

当前 parser 已经能提取：

- `from_pc`
- `frameN:` 前缀
- bare constant，例如 `R2=1`
- `fp-24` 这类 stack/pointer offset
- `off=...`
- `smin/smax/umin/umax/smin32/smax32/umin32/umax32`
- stack slot type 字符串，例如 `0000????`
- stack spill 的内嵌 `RegState`

另外还实现了 `extract_failure_pc()`，用于从 rejection log 里猜失败点 PC。见 `daemon/src/verifier_log.rs:57-112`。

### 2.3 当前 parser 的明显缺口

现有 parser 更像“为了 map_inline 和错误归因写的轻量 tokenizer”，不是“可供 const_prop 复用的 verifier trace IR”。

关键缺口如下。

1. 它把 full-state line 和 inline delta line 都压成同一种 `VerifierInsn`
   - `parse_pc_state_line()` 既接受 `<pc>: R...`，也接受 `<pc>: (insn) ... ; R...`，但返回的都是同一种 `VerifierInsn`。见 `daemon/src/verifier_log.rs:169-184`。
   - 这会丢失一个关键信息：这个 state 是完整寄存器文件，还是仅仅是“这一条指令执行后被 scratch 的增量”。

2. 它没有保存 instruction text
   - 只保留 `pc` 和 state，不保留 `(71) r3 = *(u8 *)(r2 +0)` 这一段。
   - 如果后面要用 parser 自己推 branch outcome / delta apply，instruction text 会很有用。

3. 它没有保存 speculative 标志
   - `parse_from_state_line()` 会把 `" (speculative execution)"` 吃掉，但没有把它存下来。见 `daemon/src/verifier_log.rs:159-166`。

4. 它没有解析 `var_off`
   - 当前 `parse_reg_attributes()` 只认 range 和 `off`，不认 `var_off=(value; mask)`。见 `daemon/src/verifier_log.rs:380-419`。
   - 这意味着 parser 目前拿不到 verifier 最核心的 tnum 信息。

5. 它把 8 类边界压成了 2 个字段
   - `RegState` 只有 `min_value/max_value`，没有分别保存 `smin/smax/umin/umax/smin32/smax32/umin32/umax32`。见 `daemon/src/verifier_log.rs:27-33`。
   - `parse_reg_attributes()` 最后只是 `state.min_value = smin.or(umin).or(smin32).or(umin32)`、`max_value = ...`。见 `daemon/src/verifier_log.rs:418-419`。
   - 这会把 signed/unsigned、32/64 位信息全部压扁。

6. 它用 `i64` 表示 known/min/max
   - `parse_signed_value()` 对正 hex 直接 `as i64`，`parse_unsigned_value()` 直接 `i64::try_from(unsigned)`。见 `daemon/src/verifier_log.rs:469-515`。
   - 结果是 `u64 > i64::MAX` 的值要么被截断成负数，要么直接解析失败。
   - 这对 BPF 标量是不够的，因为 verifier 的常量本质上是 `u64`。

7. 它没有保存很多对后续优化有价值的元数据
   - `P` precise 前缀
   - `id`
   - `ref_obj_id`
   - `map=..., ks=..., vs=...`
   - packet `r=...`
   - mem `sz=...`
   - callback / async callback / refs 列表

8. 它没有 branch direction 抽象
   - 现在最多只能拿到 `from_pc`
   - 没有“该条件跳转恒真/恒假”的结构化结果

### 2.4 当前 parser 现在被谁用

当前 verifier log parser 主要用于两个地方：

1. `map_inline`
   - `program.verifier_states` 现在是给 `map_inline` 做 verifier-guided constant key extraction 用的。见 `daemon/src/passes/map_inline.rs:1122-1149`。
   - 只取 `scalar + known_value`，完全没把 parser 当通用 oracle。见 `daemon/src/passes/map_inline.rs:661-665`。
   - 并且只在 `map_inline` fixed-point 的第一轮启用，避免改写后 PC 漂移造成 state 失效。见 `daemon/src/passes/map_inline.rs:707-708`。

2. final REJIT failure 归因
   - 失败时用 `extract_failure_pc()` 找 failure PC。见 `daemon/src/commands.rs:736-771`。

所以现在虽然“已经有 verifier log parser”，但它的目标和 verifier-in-the-loop `const_prop` 需要的 parser 不是同一个级别。

## 3. `BPF_PROG_LOAD(log_level=2)` 实际输出什么

### 3.1 `log_level=2` 的含义

在这棵 vendor kernel 里：

- `BPF_LOG_LEVEL1 = 1`
- `BPF_LOG_LEVEL2 = 2`
- `BPF_LOG_STATS = 4`
- `BPF_LOG_FIXED = 8`  
  见 `vendor/linux-framework/include/linux/bpf_verifier.h:627-633`。

`bpf_vlog_init()` 要求：

- 有 log buffer 时 `log_level` 不能是 0
- `log_level` 不能超出 `BPF_LOG_MASK`  
  见 `vendor/linux-framework/kernel/bpf/log.c:16-40`。

### 3.2 `log_level=2` 会比普通 log 大很多

`do_check()` 和 `do_check_common()` 里都有：

- `bool pop_log = !(env->log.level & BPF_LOG_LEVEL2);`  
  见 `vendor/linux-framework/kernel/bpf/verifier.c:21553-21556`、`vendor/linux-framework/kernel/bpf/verifier.c:24943-24946`。

配合 `pop_stack()` 的：

- `if (pop_log) bpf_vlog_reset(&env->log, head->log_pos);`  
  见 `vendor/linux-framework/kernel/bpf/verifier.c:2088-2104`。

这意味着：

- `log_level < 2` 时，回溯/分支探索产生的一部分日志会被 reset 掉
- `log_level == 2` 时，verifier 会保留更多路径日志，不再 aggressively pop

这也是为什么成功程序的 `level2` log 体积会非常大，尤其在大量分支、循环、子程序场景下会涨到几十 MB。

### 3.3 输出格式不是“每条指令一个完整 state”

这是本次调研里最重要的一个细节。

`log_level=2` 主要会打印两类 state。

1. full-state line
   - `from <prev> to <pc>:` 后接 `print_verifier_state(..., true)`  
     见 `vendor/linux-framework/kernel/bpf/verifier.c:21621-21627`
   - 这类是完整寄存器/栈状态

2. inline per-insn line
   - `print_insn_state(..., false)` 最终调用 `print_verifier_state(..., false)`  
     见 `vendor/linux-framework/kernel/bpf/log.c:749-865`
   - `print_verifier_state(..., false)` 只打印 scratched regs/stack：
     - `if (!print_all && !reg_scratched(...)) continue;`
     - `if (!print_all && !stack_slot_scratched(...)) continue;`  
       见 `vendor/linux-framework/kernel/bpf/log.c:756-845`

因此：

- `6: (71) ... ; R3=scalar(...)` 这种 `; R...` 不是 full register file
- 它只是“挂在该条指令后面的 delta-like state”
- 如果要得到“每个 PC 的完整寄存器状态”，必须把 full-state line 和 inline delta line 按 verifier trace 顺序重放

这件事非常关键。它决定了：

- 现有 parser 对 `map_inline` 足够，因为 `map_inline` 只抓局部 known scalar
- 但对 verifier-in-the-loop `const_prop` 来说，现有 parser 直接拿来用是不够的

### 3.4 register state 具体长什么样

`print_reg_state()` 的格式大致是：

- 精确 scalar constant：直接打印数字，必要时前缀 `P`
- 非精确 scalar：`scalar(smin=...,umax=...,var_off=(...; ...))`
- stack pointer：`fp-24`
- map value pointer：`map_value(map=...,ks=...,vs=...,off=...,imm=...)`
- packet pointer：`pkt(off=8,r=8)`
- BTF pointer：`ptr_<type>(...)`

具体见 `vendor/linux-framework/kernel/bpf/log.c:673-747`。

stack state 由 `print_verifier_state()` 输出，例如：

- `fp-8=0000????`
- `fp-24=scalar(id=1)`
- `fp-40=fp-56`  
  见 `vendor/linux-framework/kernel/bpf/log.c:749-845`。

所以从文本能力上看，verifier 确实暴露了很多有价值信息：

- exact constant
- full `var_off`
- signed/unsigned 32/64 bounds
- pointer type
- stack spill type

### 3.5 能不能可靠地解析出 per-instruction 精确常量

答案分两层。

1. “能不能从文本里抽出很多 exact constant？”
   - 可以。
   - bare scalar constant、singleton range、某些 pointer fixed offset 都能可靠识别。

2. “能不能直接得到每个 PC 的完整寄存器文件，并拿它做 const_prop oracle？”
   - 不能直接得到。
   - 因为 inline `; R...` 是 partial state，不是 full state。
   - 如果想要稳定的 per-PC oracle，必须先做 trace reconstruction。

所以更准确的结论是：

- `log_level=2` 足够强，可以做 oracle
- 但需要一个比现有 `parse_verifier_log()` 更强的“raw event parser + state replayer”

## 4. 当前 per-pass verify 流程

### 4.1 原始 program 的 verifier state 现在怎么来的

当前只在一种很窄的场景下，给 `program.verifier_states` 填数据：

- `maybe_attach_original_verifier_states()` 只有在原始程序包含 `bpf_map_lookup_elem` helper call 时才触发。见 `daemon/src/commands.rs:374-382`。
- 它会把原始指令复制一份、重定位 map FD，然后走 `BPF_PROG_REJIT(log_level=2)` 抓 log，再 `parse_verifier_log()`。见 `daemon/src/commands.rs:384-405`。
- 随后把这些 parsed states 挂到 `program.verifier_states`。见 `daemon/src/commands.rs:493-509` 与 `daemon/src/pass.rs:68-69`、`daemon/src/pass.rs:152-155`。

这个设计明显是为了 `map_inline`，不是为了全通用 per-pass oracle：

- 只抓 original program
- 只在有 `map_lookup_elem` 时抓
- 后续 pass 接受后不会刷新

### 4.2 当前 per-pass verify 走的是 `BPF_PROG_LOAD`

apply 模式下，pipeline 外层会先构造 `ProgLoadMeta`：

- `prog_type`
- `ifindex`
- `expected_attach_type`
- `attach_btf_id`
- `prog_name`
- GPL compatibility
- `prog_btf_fd`
- `func_info`
- `line_info`
- `attach_fd`（attach prog fd 或 attach BTF fd）  
  见 `daemon/src/bpf.rs:1109-1167`。

这个 metadata reconstruction 再配合 `populate_prog_load_attr()` 填到 `AttrProgLoad` 里。见 `daemon/src/bpf.rs:1452-1496`。

verify callback 的流程是：

1. clone 当前 pass 产物的 `program.insns`
2. 做 map FD relocation
3. 校验 required BTF fds
4. 调 `bpf_prog_load_verify()`  
   见 `daemon/src/commands.rs:517-579`。

### 4.3 当前是否传了 `log_level`、是否捕获了 verifier log

传了，但只在失败重试路径里。

`bpf_prog_load_verify()` 的行为是：

1. 先 `run_prog_load_once(..., log_level=0, log_buf=None)`
2. 只有失败时，才分配 16 MB buffer 重试 `log_level=2`
3. 成功路径如果第一轮就过，直接返回空字符串  
   见 `daemon/src/bpf.rs:1498-1518`。

也就是说：

- 当前 per-pass verify 的 accepted pass 几乎一定没有 verifier log
- 这和 verifier-in-the-loop 的核心需求正相反

另外，即便 `bpf_prog_load_verify()` 返回了 `result.verifier_log`，verify callback 也只是：

- `let _verifier_log = result.verifier_log;`  
  然后直接丢弃。见 `daemon/src/commands.rs:560-564`。

所以当前答案是：

- `log_level` 在代码里已经具备
- 但成功路径不抓 log
- 抓到的 log 也没有解析
- 更没有喂回下一 pass

### 4.4 当前 rollback 逻辑是否正确

从静态代码和已有测试看，rollback 逻辑本身是正确的。

`PassManager::run_single_pass()` 对 changed pass 的处理是：

1. 先 clone 整个 `before_program`
2. 跑 pass
3. 调 verifier
4. 若 rejected：
   - `*program = before_program`
   - `result.changed = false`
   - `result.rollback = Some(restored_pre_pass_snapshot(...))`  
     见 `daemon/src/pass.rs:900-928`。

这意味着 rollback 恢复的是整个 `BpfProgram`，不只是 `insns`：

- 包括 annotations
- map metadata
- `verifier_states`
- 其它 program-level state

相关测试也覆盖了“rejected pass 后恢复到上一个 accepted snapshot，再继续跑下一个 pass”。见 `daemon/src/pass_tests.rs` 中对应 case，本次定向单测已通过。

### 4.5 当前 structured JSON 记录是否完整

不完整，至少对 verifier-in-the-loop 目标来说不完整。

现在 JSON 里有：

- 每个 pass 的 `accepted/rejected/not_needed`
- `verify_error`
- rollback 结果
- pass 前后 bytecode dump
- final REJIT 的 verifier log（attempt-level，不是 per-pass）  
  见 `daemon/src/commands.rs:148-182`、`daemon/src/pass.rs:670-679`。

但没有：

- per-pass verifier log
- per-pass parsed verifier state
- `log_true_size`
- buffer 是否截断
- parser 是否成功
- parser 版本 / kernel 版本绑定

所以当前 JSON 适合“debug 最终 apply/reject”，不适合“记录每个 accepted pass 的 oracle facts”。

## 5. verifier-in-the-loop 改造方案

这里按你给的 A/B/C/D/E 拆。

### A. `BPF_PROG_LOAD` 加 `log_level=2` + 足够大的 log buffer

这个改造是必须的，但建议不要直接改掉现有 `bpf_prog_load_verify()` 语义。

更稳的做法是新增一条 oracle 专用路径，例如：

```rust
pub struct ProgLoadOracleResult {
    pub verifier_log: String,
    pub log_true_size: u32,
    pub truncated: bool,
}

pub fn bpf_prog_load_capture_verifier_log(
    meta: &ProgLoadMeta,
    insns: &[BpfInsn],
    fd_array: &[RawFd],
) -> Result<ProgLoadOracleResult>;
```

建议行为：

1. 直接走 `log_level=2`
   - 不再先 `log_level=0` fast path，因为目标就是拿 success log。
2. 读取 `attr.log_true_size`
   - `AttrProgLoad` 结构里已经有 `log_true_size` 字段，但当前 wrapper 没有使用。见 `daemon/src/bpf.rs:113-145`、`daemon/src/bpf.rs:1452-1496`。
   - 内核在 verifier 结束时会通过 `bpf_vlog_finalize()` 计算并回写 `log_true_size`。见 `vendor/linux-framework/kernel/bpf/verifier.c:26536-26543`。
3. 遇到 `ENOSPC` 时自适应扩 buffer 重试
   - 当前代码只是 special-case 了 `"No space left on device"`，但不会根据 `log_true_size` 重新申请更大的 buffer。见 `daemon/src/bpf.rs:1513-1518`。
4. 需要一个上限
   - 建议默认 64 MB，上限可配
   - 超过上限时把该 pass 标记成 “verify accepted but oracle unavailable”，不能因为日志太大就把优化整体判失败

建议补充考虑：

- 如果想让截断语义更可预测，可以试 `BPF_LOG_LEVEL2 | BPF_LOG_FIXED`
- 但核心不是 fixed 与否，而是一定要利用 `log_true_size` 做 resize

### B. 解析 verifier log 提取 per-instruction register state

这里不能只在现有 `VerifierInsn` 上打补丁，最好分两层。

第一层：`RawVerifierEvent`

- 保留原始 line kind：
  - `edge_full_state`
  - `pc_full_state`
  - `insn_delta_state`
  - `safe`
  - `info/stats`
  - `error`
- 保留：
  - `pc`
  - `from_pc`
  - `frame`
  - `speculative`
  - `regs`
  - `stack`
  - 可选 `insn_text`

第二层：`VerifierOracleTrace`

- 基于 raw event 顺序重放
- 把 full-state 和 delta-state 合成完整 trace state
- 最终再导出给优化 pass 的 facts

为什么一定要分层：

- 现在 parser 已经把 full-state 和 delta-state 拍平了
- 一旦拍平，就没法可靠重建完整状态

### C. 把 register state 转换成 `const_prop` 可用的格式

这里建议不要直接把 parser 输出绑定成 `RegConstState = [Option<u64>; 11]`。

更合理的是新增一个更宽的数据模型，例如：

```rust
pub struct ScalarFacts {
    pub exact_u64: Option<u64>,
    pub exact_u32: Option<u32>,
    pub smin: Option<i64>,
    pub smax: Option<i64>,
    pub umin: Option<u64>,
    pub umax: Option<u64>,
    pub smin32: Option<i32>,
    pub smax32: Option<i32>,
    pub umin32: Option<u32>,
    pub umax32: Option<u32>,
    pub var_off: Option<(u64, u64)>,
    pub precise: bool,
}

pub struct PcOracleFacts {
    pub regs: [Option<ScalarFacts>; 11],
    pub branch_outcome: Option<bool>,
}
```

然后 `const_prop` 只消费自己真正需要的子集：

- `exact_u64` / `exact_u32`
- 必要时 `branch_outcome`

关键的 merge 规则要保守：

- 同一个 `pc/frame/reg` 如果所有观察都是 scalar 且 exact value 相同，才给 exact constant
- 只要有一路不是 scalar、或者 exact value 不同，就降为 unknown

这和当前 `const_prop` 的 meet 语义是一致的，只是输入来源换成 verifier。

### D. `const_prop` 改成：优先用 verifier 的常量，自己不再重复计算

这里我建议分两步，而不是一步到位删掉现有 evaluator。

#### 第一步：oracle mode 先和现有逻辑并存，用于对比

原因很简单：

- 现有 parser 还不够
- accepted pass 的 verifier state 回灌链路还不存在
- branch oracle 的可用性要靠 reconstruction 才能做稳

这一阶段建议：

1. 新增 `ConstOracle` 辅助层
2. `const_prop` 先在内部支持两种 fact source：
   - `local_exact_const_analysis`（现状）
   - `verifier_oracle_exact_const`（新）
3. 在 debug / corpus 对比阶段同时统计：
   - 现有 `const_prop` 可折叠的 site 数
   - verifier oracle 可折叠的 site 数
   - 两者差异

#### 第二步：accepted pass 后刷新 `program.verifier_states`，让 oracle 真正进入 pipeline

这里需要改 pass manager API。

当前 callback 是：

- `FnMut(&str, &BpfProgram) -> Result<PassVerifyResult>`  
  见 `daemon/src/pass.rs:892-910`。

要做 oracle，建议改成类似：

```rust
pub struct PassVerifyArtifact {
    pub verify: PassVerifyResult,
    pub verifier_log: Option<String>,
    pub oracle_states: Option<Arc<[VerifierInsn]>>,
    pub log_true_size: Option<u32>,
    pub truncated: bool,
}
```

然后 `run_single_pass()` 在 accepted 时：

1. 保留变更
2. `program.verifier_states = artifact.oracle_states`
3. 再 `invalidate_all()` / `sync_annotations()`

如果 rejected：

- 保持现在的 snapshot rollback 语义不变

#### 第三步：真正把 `const_prop` 变成 oracle-first

oracle-first 版本里，`const_prop` 应该改成：

1. 不再从 CFG 上自算 exact constant
2. 扫描指令时直接看 `program` 当前版本的 oracle facts
3. 对 ALU/MOV/LD_IMM64：
   - 若 verifier 告诉你该指令后的 `dst` 是 exact scalar，则直接重写成 constant load
4. 对条件跳转：
   - 若 oracle 明确告诉你 branch 恒真/恒假，则折 `JA/NOP`
   - 如果 branch outcome 不够稳，就保持不动
5. 保留现有的 safety policy：
   - pseudo-imm type guard
   - tail-call protected prefix guard
   - jump fixup / unreachable cleanup

### E. 验证 oracle `const_prop` 是否比自己算的覆盖更多

这个阶段建议直接做 corpus 级 A/B。

建议统计：

1. `const_prop` 自算命中 site 数
2. verifier oracle 命中 site 数
3. 新增命中的原因分类
   - range-only
   - tnum-only
   - branch refinement
   - spill/load recovery
4. 最终 `const_prop+dce` 后的：
   - insn delta
   - verifier accepted rate
   - final apply/rejit 成功率

我预期 oracle 至少会在这些场景比现有实现覆盖更好：

- range-based branch fold
- `JSET` / bitmask-driven fold
- 经过比较 refine 后出现 exact singleton 的寄存器
- 某些通过 spill/load 或 helper side-effect 传播出来的 exact scalar

## 6. 风险和限制

### 6.1 log 很大

这是最现实的工程风险。

当前 wrapper 固定只给 16 MB：

- `BPF_PROG_LOAD` 16 MB。见 `daemon/src/bpf.rs:1503`
- `BPF_PROG_REJIT` 16 MB。见 `daemon/src/bpf.rs:1589`、`daemon/src/bpf.rs:1638`

对于 14k insn 级别程序，`log_level=2` 成功日志完全可能超过这个量级。

建议：

- 一定使用 `log_true_size`
- 一定支持自适应重试
- 一定有上限与 fallback 策略

### 6.2 verifier log 不是稳定 API

这是事实，但这次的上下文里风险是“可控的”：

- 你 repo 里已经 vendor 了一棵固定 kernel
- daemon 也是针对这棵 kernel 在工作

所以更实际的策略不是“追求所有上游内核兼容”，而是：

1. 明确把 parser 绑定到当前 vendor kernel grammar
2. 用这棵 kernel 的 canned log fixture 做 parser tests
3. parse 失败时 fail-open，退回现有 `const_prop`

### 6.3 `log_level=2` 会让 per-pass verify 变慢

会，而且比现在显著更慢。

现在的 per-pass verify：

- accepted pass 只走 `log_level=0`
- rejected pass 才会退到 `log_level=2`

verifier-in-the-loop 则要求：

- 每个 changed 且 accepted 的 pass 都跑一次 `log_level=2`

建议：

- 先做 feature flag
- 先只在 `const_prop` 前后的关键 pass 上启用
- 如果效果明显，再考虑扩成“所有 changed pass”

### 6.4 现有 log 里 branch direction 不是结构化字段

当前 log 里没有直接写：

- “this branch is always taken”
- “this branch is always not taken”

它更多是通过：

- range/tnum
- outgoing edge trace
- safe/prune 行为

间接体现出来。

所以 branch oracle 的实现难度高于 exact constant oracle。

建议先做：

- exact scalar oracle

再做：

- branch direction oracle

### 6.5 有没有比 log 更好的方式拿 verifier state

以当前内核/daemon 代码为准，基本没有现成稳定接口。

`bpf_prog_info` / `BPF_OBJ_GET_INFO_BY_FD` 能拿到：

- `verified_insns`
- prog images
- map ids
- BTF / line info

但拿不到 verifier 的 per-insn abstract state。

`BTF dump` 也不是这个用途。

唯一现成且不改 kernel 的手段，就是 verifier log。

长期更好的方案只有两个：

1. 内核新增结构化 verifier trace API
2. 本地 vendor kernel 自己加一个 daemon-only 调试接口

这两个都比“先 parse 现有 log”成本高得多。

## 7. 对当前 per-pass verify via LOAD 改动的 review

### 7.1 这次改动里正确的部分

1. 用 `BPF_PROG_LOAD` 做 tentative verify，而不是对 live program 反复 `REJIT`
   - 这是对的，因为 tentative per-pass 结果不应该真的改 live program。

2. `ProgLoadMeta` 重建基本合理
   - `prog_type/ifindex/expected_attach_type/attach_btf_id/prog_name/gpl/BTF/func_info/line_info/attach_fd` 都考虑到了。见 `daemon/src/bpf.rs:1109-1167`、`daemon/src/bpf.rs:1452-1496`。

3. map FD relocation 和 required BTF fd_array 也接上了
   - 见 `daemon/src/commands.rs:538-556`。

4. rollback 语义正确
   - rejected pass 恢复到 pre-pass snapshot，并且后续 pass 继续在最后一个 accepted program 上运行。见 `daemon/src/pass.rs:900-928`。

5. JSON 层至少已经把 accepted/rejected/rollback 暴露出来了
   - 对 apply debug 来说比以前完整。

### 7.2 还存在的关键问题

1. accepted pass 不会产生日志
   - 这是 verifier-in-the-loop 最大 blocker。见 `daemon/src/bpf.rs:1498-1518`。

2. verify callback 把日志直接丢掉
   - `let _verifier_log = result.verifier_log;`。见 `daemon/src/commands.rs:560-564`。

3. callback 签名无法把 oracle state 写回 `program`
   - 这意味着就算成功抓到 log，当前 pass manager 也没法把它喂给下一个 pass。见 `daemon/src/pass.rs:892-910`。

4. `program.verifier_states` 在 accepted transform 后会 stale
   - 当前 field 只在 pipeline 开始前 seed 一次。见 `daemon/src/commands.rs:493-509`。
   - pass manager 没有 remap / refresh verifier states 的逻辑。见 `daemon/src/pass.rs:919-928`。

5. final REJIT success path 的 “empty verifier log” warning 基本是设计使然
   - 因为 `bpf_prog_rejit()` 也是先 `log_level=0` fast path，成功时返回空 log。见 `daemon/src/bpf.rs:1584-1642`。
   - 所以 `commands.rs` 里 success 时的 empty-log warning 往往不是异常，而是当前 API 设计的必然结果。见 `daemon/src/commands.rs:665-683`。

6. structured JSON 仍然不够 oracle 用
   - 没有 per-pass verifier log
   - 没有 parse result
   - 没有 truncation / `log_true_size`
   - `PassDebugTrace` 也只记 verify status 和 bytecode dump。见 `daemon/src/pass.rs:670-679`、`daemon/src/commands.rs:148-182`

7. attach metadata 仍然是 best-effort
   - `best_effort_prog_link_metadata()` 只 decode tracing/cgroup/netns 三种 link type。见 `daemon/src/bpf.rs:471-489`。
   - 对其它 attach 类型，这条 LOAD verify 路径可能仍有 false reject 风险。

## 8. 建议的落地顺序

如果目标是尽快把 verifier oracle 真正跑起来，我建议按这个顺序做。

1. 新增 success-log capture API
   - 新增 `bpf_prog_load_capture_verifier_log()`
   - 利用 `log_true_size` 做 resize
   - 先不碰旧的 `bpf_prog_load_verify()`

2. 重写 parser 为 raw-event model
   - 区分 full-state / delta-state
   - 加上 `u64` exact constant、`var_off`、32/64 位 range、`speculative`

3. 改 verify callback 返回 richer artifact
   - accepted pass 后刷新 `program.verifier_states`
   - 同时把 per-pass verifier log 落进 debug JSON

4. 先做 exact-constant oracle
   - 先只替换 `const_prop` 里的 ALU/MOV result folding
   - branch folding 暂时保守

5. 做 corpus A/B
   - 量化 coverage gain / verifier rejection / runtime overhead

6. 再做 branch oracle
   - 需要完整 trace reconstruction 或更强的 edge model

## 最终判断

这个方案值得做，而且理论收益很可能大于当前 `const_prop` 自算。

但工程上真正的分水岭不是“能不能 parse 出 `R3=42`”，而是两点：

1. accepted pass 成功路径必须稳定拿到 success verifier log
2. parser 必须从“轻量状态摘录器”升级成“能区分 full/delta、可重放 trace 的 oracle 前端”

如果这两点不到位，verifier-in-the-loop 会停留在 demo 级别；
如果这两点做好，`const_prop` 改成 verifier-driven 是现实可落地的。
