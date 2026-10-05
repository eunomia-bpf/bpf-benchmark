# daemon/ Postfix Review - 2026-03-22

审查范围：已逐个阅读 `daemon/src/` 下全部 18 个 Rust 源文件，并额外运行：

- `cargo test --manifest-path daemon/Cargo.toml`
- `cargo check --manifest-path daemon/Cargo.toml --all-targets`

结论先行：本轮 11 个历史问题里，确认**完全修复 5 项**，**部分修复 3 项**，**仍未修复/修复错误 3 项**。另外，新增的 `serve` 子命令里还有 1 个新的高风险可用性问题。当前实现比第一轮明显前进，但还不能认为“上一轮 11 个高优问题已全部关闭”。

## Findings

- **HIGH** `daemon/src/passes/cond_select.rs:377`
  `emit_safe_params()` 仍然不是 swap-safe，上一轮的别名误编译并没有真正修掉。最直接的反例仍成立：当 `cond_reg == r2` 时，当前实现会先发出 `r2 = b_val`，再发出 `mov r3, r2`，于是 `r3` 读到的是新写入的 `b_val`，不是原始条件值。更一般地，`r1 <- r2; r2 <- r1` 这类循环别名也会被当前的 `r0` fallback 破坏，因此问题 4 应判定为“修复错误而非已修复”。

- **HIGH** `daemon/src/passes/rotate.rs:219`
  `find_provenance_mov()` 只检查了 `tmp` 在回扫路径上是否被改写，没有检查 `dst` 是否在 `MOV tmp, dst` 之后、第一条 shift 之前被改写。于是 `mov r3, r2; add r2, 1; rsh r2, 56; lsh r3, 8; or r2, r3` 这类序列仍会被错误识别成 rotate。问题 5 只修了一半，误命中窗口仍然存在。

- **HIGH** `daemon/src/kfunc_discovery.rs:293`, `daemon/src/pass.rs:267`, `daemon/src/passes/rotate.rs:169`, `daemon/src/passes/cond_select.rs:281`, `daemon/src/main.rs:314`
  `fd_array` 确实已经从 pass 打到 `cmd_apply()`/`try_apply_one()`，但契约仍然不完整：registry 里还是单个全局 `module_fd`，而且是“第一个发现到的模块 FD”。`bpf_rotate64` 和 `bpf_select64` 显然来自不同模块时，`cond_select` 仍会把 rotate 模块的 FD 传给 REJIT；一条程序同时命中多个 kfunc pass 时也拿不到完整的 `fd_array`。问题 9 只能算部分修复。

- **HIGH** `daemon/src/main.rs:456`, `daemon/src/main.rs:486`
  新增的 `serve` 子命令存在 head-of-line blocking。server accept 到一个连接后会同步进入 `handle_client()`，而 `handle_client()` 用阻塞的 `reader.lines()` 一直读到客户端断开为止。任何一个慢客户端或长连接客户端都能独占整个 daemon，后续连接无法被 accept。这是本轮新增问题。

- **HIGH** `daemon/src/pass.rs:92`, `daemon/src/pass.rs:427`, `daemon/src/passes/branch_flip.rs:120`
  `InsnAnnotation` 仍然没有 remap。`sync_annotations()` 还是只做 `resize`，而 `branch_flip` 仍直接读取 `program.annotations[site.pc].branch_profile`。只要前面 pass 改过指令长度，注解依然会错位粘在新 PC 上。问题 10 仍未修复。

- **HIGH** `daemon/src/pass.rs:32`, `daemon/src/profiler.rs:76`, `daemon/src/passes/branch_flip.rs:120`, `daemon/src/main.rs:372`
  `analysis/pgo.rs` 虽然删掉了，但 PGO 仍没有收敛成单一路径。`profile` 子命令产出的是 `profiler::PgoAnalysis`，`branch_flip` 消费的还是 `InsnAnnotation::branch_profile`，二者没有任何接线。问题 11 只能算“删了一套实现，但没有闭环”。

- **MEDIUM** `daemon/src/passes/spectre.rs:9`, `daemon/src/passes/spectre.rs:29`, `daemon/src/main.rs:29`
  `JA +0` 已经在注释和 diagnostics 里明确写成 placeholder，这是进步；但 pass 名字仍叫 `spectre_mitigation`，分类仍是 `Security`，CLI 帮助文本也继续把它列成 mitigation。问题 3 不再像第一轮那样完全错误地“无提示冒充 barrier”，但仍未完全去掉误导性接口语义。

## 11 项修复核对

| # | 历史问题 | 结论 | 依据 |
|---|---|---|---|
| 1 | `branch_flip` CFG 模式错误，应改为 `then_len = off - 1`，PGO-only | **FIXED** | `daemon/src/passes/branch_flip.rs:263-296` 已按 true diamond 扫描，`then_len = off - 1`；`daemon/src/passes/branch_flip.rs:119-136` 只在有 PGO 注解时触发，无 heuristic fallback。 |
| 2 | `cond_select` Pattern B 误编译，应删除 Pattern B | **FIXED** | `daemon/src/passes/cond_select.rs:317-347` 只保留 4-insn diamond；`test_cond_select_pattern_b_removed` / `test_cond_select_no_emit_3insn_pattern_b` 已覆盖。 |
| 3 | spectre `JA+0` 不是真 barrier，应标注 placeholder | **PARTIAL** | `daemon/src/passes/spectre.rs:9-21` 与 diagnostics 已写明 placeholder；但 `name/category/CLI` 仍把它暴露为 mitigation/security。 |
| 4 | `cond_select` 寄存器别名，应 swap-safe 参数搬运 | **NOT FIXED** | `daemon/src/passes/cond_select.rs:377-434` 仍会在 `cond_reg == r2` 和寄存器交换环上误编译。 |
| 5 | `rotate` 未验证 tmp provenance，应回扫 `MOV tmp, dst` | **PARTIAL** | `daemon/src/passes/rotate.rs:219-251` 新增回扫，但未检查 `dst` 在 MOV 之后是否被改写，因此仍会误命中。 |
| 6 | `rotate` 未检查 tmp live-out，应做 LivenessAnalysis 检查 | **FIXED** | `daemon/src/passes/rotate.rs:69-82` 已对 `tmp_reg` 做 live-out 拦截，并有 `test_rotate_pass_tmp_live_out_conflict`。 |
| 7 | liveness call def 只有 `r0`，应改为 `r0-r5` | **FIXED** | `daemon/src/analysis/liveness.rs:95-103` 已把 call defs 扩展到 `r0..=5`，并补了 `use_def_call` / `liveness_call_clobbers_caller_saved`。 |
| 8 | kfunc BTF kind 编号错误，应对齐 `linux/btf.h` | **FIXED** | `daemon/src/kfunc_discovery.rs:28-66` 常量已与内核对齐；`daemon/src/kfunc_discovery.rs:164-176` skip table 已重写，并有 mixed-kind 测试。 |
| 9 | `fd_array` 未打通，应传到 `cmd_apply` | **PARTIAL** | `daemon/src/main.rs:314-316`, `daemon/src/main.rs:430-431` 已传入 REJIT；但 `module_fd` 仍是单值 first-wins，不能正确表达按-kfunc 的模块依赖。 |
| 10 | `InsnAnnotation` 改写后不重映射 | **NOT FIXED** | `daemon/src/pass.rs:90-95` 仍只有 `resize`；`daemon/src/pass.rs:427-431` 改写后仍调用这套逻辑。 |
| 11 | PGO 两套 abstraction，应删一套 | **PARTIAL** | `analysis/pgo.rs` 已删除，但 `daemon/src/profiler.rs:76-92` 与 `daemon/src/pass.rs:32-42` 仍是两套模型，且未闭环。 |

## 新增代码专项检查

- `emit_safe_params`
  结论：有 bug。当前实现不满足 parallel-copy 语义，别名场景仍会误编译。

- `find_provenance_mov`
  结论：有 bug。它只证明了 “tmp 曾经来自 dst”，没有证明 “tmp 与进入 rotate pattern 时的 dst 仍是同一个值”。

- `serve` 子命令
  结论：有 bug。当前是单线程、阻塞式 client loop，一个连接就能卡住整个 server。

## 构建与测试

- `cargo test --manifest-path daemon/Cargo.toml`
  结果：通过，`147 passed; 0 failed`。

- `cargo check --manifest-path daemon/Cargo.toml --all-targets`
  结果：通过。

## 总体判断

这一轮修复把真正“已经关掉”的问题数量提升到了 5 个，尤其是 `branch_flip` 形状、`Pattern B` 删除、`liveness` call clobber、BTF kind 修正、`rotate` live-out 检查都已经落地。但 `cond_select` 别名、`rotate` provenance、annotation remap、PGO 闭环、以及按-kfunc 的 `fd_array` 契约仍然没有关闭；再加上 `serve` 新引入的阻塞问题，这一版还不适合宣称“第一轮 11 个高优问题全部修复完成”。
