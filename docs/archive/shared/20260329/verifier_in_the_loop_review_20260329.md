# verifier-in-the-loop review (2026-03-29)

## 结论

实现方向是对的，核心机制已经成立：

- per-pass verify 现在能在 accept 路径拿到 verifier success log；
- `const_prop` 能消费 verifier exact constants；
- `pass.rs` 的 accept / reject 生命周期不会把 rejected pass 的 verifier state 泄漏到后续 pass；
- `map_inline` 切到新 exact API 后没有看到功能退化。

但我确认了 2 个会影响设计目标的问题，其中 2 个都已经修复：

1. **原始 program 的 verifier state 只在含 `map_lookup_elem` 时才会 seed。**
   这会导致没有 map lookup、但依赖 helper-return exact value 的程序，第一次跑 `const_prop` 时根本拿不到 verifier oracle。
   已修复：`daemon/src/commands.rs` 现在对所有非空原始程序都尝试捕获原始 verifier states。

2. **success-log 退化路径是静默的。**
   之前如果 accept 路径拿到的 success log 超大而回退到无 log verify，或者 log 非空但 parser 一个 state 都抽不出来，后续 pass 会悄悄失去 verifier-guided states。
   已修复：`daemon/src/commands.rs` 现在会显式 warning。

## 修复内容

### 1. 原始 verifier state 不再只限 map-lookup 程序

- 文件：`daemon/src/commands.rs`
- 之前：`maybe_attach_original_verifier_states()` 先检查 program 是否含 `map_lookup_elem`，不含就直接返回。
- 问题：这把 verifier oracle 人为限制成了 “map_inline 专用”，和 `const_prop` 的设计目标不一致。
- 现在：对所有非空原始程序都尝试做 `BPF_PROG_REJIT(log_level=2)` capture，并 seed `program.verifier_states`。

### 2. success-log 丢失/不可解析时显式告警

- 文件：`daemon/src/commands.rs`
- 新增 `parse_verifier_states_from_log()`：
  - 非空 log 但 parser 没有抽到任何 state，会返回错误；
  - 原始 capture 路径会把它变成 visible warning；
  - per-pass accept 路径会 warning，并明确说明后续 pass 没有 verifier-guided states。
- 对 `BPF_PROG_LOAD` accept 路径额外处理：
  - 若 `verifier_log` 为空但 `log_true_size > 0`，说明命中了超大 log fallback；
  - 这种情况现在会明确 warning，而不是静默退化。
- 对原始 `BPF_PROG_REJIT(log_level=2)` capture：
  - 若返回空 log，也会显式报错并 warning，不再静默忽略。

## 分项 review

### 1. `bpf.rs`: success-log capture

- `bpf_prog_load_verify()` 始终传 `log_level=2` 是**设计上必需**的；否则 accept 路径拿不到 success log，verifier-in-the-loop 就不成立。
- 性能上这肯定比 `log_level=0` 慢，但这是设计 tradeoff，不是 correctness bug。
- 16MB 初始 buffer + 64MB 上限 + `log_true_size` 驱动扩容是合理的。
- 超大 log fallback 回退到无 log verify 是**安全的**：不会误 accept rejected program，但会失去 verifier states。这个退化现在已经变成显式 warning，不再 silent。
- accept 后的 verifier log 消费链路是正确的：
  - `commands.rs` 解析 success log；
  - `pass.rs` 在 accepted pass 后刷新 `program.verifier_states`；
  - rejected pass rollback 会恢复旧快照。

### 2. `verifier_log.rs`: parser 升级

我没有发现会导致当前 oracle 误判的 parser 逻辑错误。

- exact scalar：
  - `R3=42` 按 64-bit exact 处理；
  - `R3_w=42` 按 32-bit exact 处理；
  - 这部分逻辑正确。
- tnum：
  - `var_off=(0x2a; 0x0)` 会得到 exact tnum，逻辑正确。
- 32-bit / 64-bit 区分：
  - `_w` suffix 和 `exact_u64()` / `exact_u32()` 的分流是对的。
- full-state / delta-state：
  - `from ... to ...:` / `<pc>: R...` / `<pc>: (insn) ... ; R...` 三类区分正确。
- speculative：
  - 对 `from ... (speculative execution): ...` 的标记正确。
- edge case：
  - 空 log / 无 state 行不会 panic；
  - 截断 log 现在也有测试覆盖，parser 不会把已完成的 state 全丢掉。

补充测试：

- `distinguishes_exact_64bit_and_32bit_scalars`
- `truncated_log_tail_does_not_drop_complete_states`

### 3. `const_prop.rs`: verifier oracle 集成

- 优先用 verifier exact constants 的主逻辑是对的。
- exact64 / exact32 双通道处理正确：
  - 64-bit rewrite 只吃 `exact64`；
  - 32-bit rewrite 吃 `exact32`。
- fallback 到本地传播的条件正确：oracle 没有 exact 时退回现有分析。
- helper call 后 verifier 推导出的 exact return value 可以被利用。
  - 之前这个能力只在“已有 seeded verifier states”的程序上生效；
  - 修复 seed 逻辑后，原始 program 的 helper-return exact 也能进入第一次 `const_prop`。
- stale verifier state：
  - 没看到 stale-state bug；
  - accepted pass 会刷新；
  - rejected pass 会通过 pre-pass snapshot 整体回滚。

### 4. `pass.rs`: verifier_states 生命周期

- accept 后更新时机正确：在 verifier accept 之后、analysis invalidation 之前刷新。
- 多 pass 之间会不断用最新 accepted program 的 verifier states。
- rejected pass rollback 正确：因为直接恢复整个 `before_program` 快照，`verifier_states` 也一起回滚。

### 5. `map_inline.rs` 兼容性

- 从 `known_value` 切到 `exact_u64().or_else(exact_u32())` 没看到功能退化。
- 这对 32-bit exact、64-bit exact、以及 sign/zero-truncated store 场景都保持了原本语义。

### 6. 整体架构

- 之前确实存在 parser/超大 log 退化的 silent failure；已修复为 visible warning。
- 这 7 个文件里我没有再看到新增的 `unwrap_or_default()` / `.ok()` / `let _ = result` 式 silent swallow 问题，除了已有历史代码中与本次设计无关的旧位置。
- 每个 changed pass 都做 verify + parse success log，性能一定会变差；但这和 verifier-in-the-loop 的设计目标一致，属于预期成本。

## 残留风险

还有一个 robustness caveat，但我这次没有继续扩成更大的重构：

- **原始 program 的 seed capture 仍走 `BPF_PROG_REJIT(log_level=2)`，这条路径没有 `log_true_size`。**
- 结果是：如果原始 success log 本身特别大，daemon 现在会 warning 并继续跑，但拿不到原始 verifier states。
- correctness 没问题，只是会失去 seed oracle。
- 如果后续要把这条路径也做满，建议把原始 seed capture 迁到一个可重试的 `BPF_PROG_LOAD` success-log capture 流程，或者给 `REJIT` capture 单独补 structured retry。

## 验证

- 执行：`make daemon-tests`
- 结果：`534 passed; 0 failed`

## 涉及文件

- `daemon/src/commands.rs`
- `daemon/src/commands_tests.rs`
- `daemon/src/verifier_log.rs`
