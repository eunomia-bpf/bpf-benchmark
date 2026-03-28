# Tetragon `event_execve` REJIT `Permission denied` 修复记录

日期：2026-03-28

## 结论

最新 Tetragon E2E 的 `event_execve` `BPF_PROG_REJIT: Permission denied (os error 13)`，根因在 `const_prop`，不是 `map_inline`、也不是“typed `LD_IMM64` 被错误折叠”，`dce` 这里更多是放大或掩盖后续症状。

具体来说，`const_prop` 会把恒真条件分支改写成 `JA`。但同一轮里如果别的常量折叠把中间指令从 1 条扩成 2 条 `LD_IMM64`，这个新 `JA` 仍保留旧的 `off`，因为通用 branch fixup 只修“原样保留”的跳转，不修这种新生成的 `JA`。结果就是：

- 跳到错误 PC
- 可能跳进 `LD_IMM64` continuation
- 或直接形成 verifier 报的 `jump out of range`
- 在 live `event_execve` 上最终表现成 `BPF_PROG_REJIT: Permission denied`

## 证据链

1. 最新结果目录是 `e2e/results/tetragon_20260328_143149`。
2. 这个结果里 `execve_rate` 是 `no_change`，真正失败的是活跃程序 `event_execve`。
3. 同一个结果里 `map_inline` 对 Tetragon 仍被 tail-call guard 全量跳过，所以这次最新 `EACCES` 不是 `map_inline` 直接生成坏字节码。
4. 旧的 authoritative Tetragon artifact `e2e/results/tetragon_authoritative_20260327.json` 保留了 rollback attempts，`event_execve` 的第一次失败被归因到 `const_prop`，verifier 关键报错是：
   - `jump out of range from insn 1619 to 1793`
5. 这和 `const_prop` 当前实现完全吻合：
   - `fold_jump_instruction()` 直接把恒真条件分支改成 `JA(insn.off)`
   - 后面虽然调用了 `fixup_all_branches()`
   - 但那个 fixup 只修“survived unchanged”的 branch
   - 新生成的 `JA` 不在这个集合里，所以 `off` 变成 stale

## 修复

修改文件：`daemon/src/passes/const_prop.rs`

- 在 `const_prop` 重建新指令流并执行通用 branch fixup 后，新增 `fixup_folded_jumps()`
- 它专门遍历本轮 `const_prop` 生成的 folded conditional jumps
- 对“恒真分支折叠成的 `JA`”按 `addr_map` 重新计算目标 `off`
- 对 `nop` / `JA +0` 保持不动，避免把“恒假分支”错误改回跳转

同时补了一个最小回归测试：

- `const_prop_fixups_folded_jump_after_ldimm64_growth`
- 场景是：分支和目标之间的指令在同一轮常量传播里扩成 `LD_IMM64`
- 这个测试直接卡住此前的 stale-offset bug

## 为什么不是另外两个方向

不是 typed `LD_IMM64` 折叠：

- `const_prop` 已经显式把 `src_reg != 0` 的 `LD_IMM64` 当成不可折叠 typed pseudo-imm
- 现有测试 `const_prop_does_not_fold_typed_ldimm64_map_value` 仍通过

不是 `map_inline`：

- 最新 E2E 里 `map_inline` 对 `event_execve` 被 tail-call guard 跳过
- 所以这轮 `EACCES` 的直接坏 rewrite 不可能来自 `map_inline`

不是这次先修 `dce`：

- 旧 artifact 的第一跳 verifier 报错先落在 `const_prop` 的 `jump out of range`
- `dce` 相关的 `call unknown` / `R4 !read_ok` 更像是上游 CFG/branch 已经损坏后的次生症状
- 先修 `const_prop` 的 branch target 才是主线

## 验证

已完成：

- `cargo test --manifest-path daemon/Cargo.toml const_prop_fixups_folded_jump_after_ldimm64_growth -- --nocapture`
- `cargo test --manifest-path daemon/Cargo.toml const_prop_folds_branch_after_map_inline -- --nocapture`
- `make daemon-tests`
  - 结果：`499 passed; 0 failed; 13 ignored`

未完成：

- `make vm-static-test STATIC_VERIFY_ARGS='--filter bpf_execve_event --max-objects 1' TARGET=x86`
  - 本次尝试时被现有 VM lock 阻塞
  - 锁持有者是仓库内另一个长跑 `vm-corpus` 进程
  - 因此没有拿到新的 guest-side verifier 结果

## 后续建议

1. 等当前 VM lock 释放后，重新跑：
   - `make vm-static-test STATIC_VERIFY_ARGS='--filter bpf_execve_event --max-objects 1' TARGET=x86`
2. 如果 guest-side static verify 通过，再补一轮 Tetragon E2E，确认 `event_execve` 不再返回 `Permission denied`
3. daemon rollback 逻辑后续还可以单独改进：
   - 当前“verifier log 完整”的 `EACCES` 不会走 verifier-attribution rollback
   - 这会让类似问题在 artifact 里只剩最终失败，不保留 disable-pass 尝试链
