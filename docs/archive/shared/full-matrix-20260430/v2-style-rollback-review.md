# v2-Style Rollback Implementation Audit (commit 522e810e)

## Verdict

**部分合格。** commit 522e810e 已把 daemon 主路径切到 `snapshot -> bpfopt CLI -> kernel_sys::prog_rejit()`，旧的 `bpfverify`/`bpfrejit` crate、`map_fds.json`/`fd_array.json`/`btf-info`/`verifier-states-out` 协议和 BTF func/line replay 基本删干净；这部分符合 rollback 目标。

未完全达标的地方集中在四类：量化报告用了“生产行数且只数三文件”的口径，raw `wc -l` 不满足 <=2400；`PassContext::default()` 仍默认启用全量 registry（含 `const_prop`）；thin dry-run/const_prop opt-in 测试不足；REJIT verifier log 的 256MB retry 日志没有可靠落到 failure artifact。整体不是严重不合格，但 vm-corpus 前建议先补 P1 项，避免失败时缺证据或默认路径语义漂移。

## 各 review 维度

### 1. 三条设计原则严守度：WARN

- **零 reconstruction：大体 OK，但仍有 context reconstruction 残留。** daemon active code 中未发现 `normalize_func_info` / `normalize_line_info` / `relocate_for_load` / `capture_verifier_states_for_replay`，`ProgramSnapshot` 只含 `info/maps/insns`，没有 BTF func/line bytes：`daemon/crates/bpfget/src/lib.rs:64-69`。但 `expected_attach_type` 仍通过 link enumeration 反推，而不是“直接从 prog_info read-as-is”：`daemon/crates/bpfget/src/lib.rs:132-133` 调 `expected_attach_type_json()`，`bpfopt/crates/kernel-sys/src/lib.rs:692-729` 逐个 link 恢复 attach type。这不是旧 BTF/map replay，但违反 plan §B “所有字段直接从 prog_info 读”的字面原则。
- **不传 BTF func_info/line_info：OK。** thin dry-run 明确传 `func_info: None`、`line_info: None`：`daemon/src/dry_run.rs:61-69`；`kernel-sys` 只有在 option 为 Some 时才设置 `opts.func_info_cnt` / `opts.line_info_cnt`：`bpfopt/crates/kernel-sys/src/lib.rs:540-552`。注意 dry-run 仍打开并传 `prog_btf_fd` / `attach_btf_obj_fd`：`daemon/src/dry_run.rs:58-67`，如果验收口径是“完全不传任何 BTF object metadata”，这里应算 WARN；按计划伪代码保留 BTF id/attach fields，则可接受。
- **const_prop 默认关：WARN。** CLI 默认 optimize pass list和 corpus config 不含 `const_prop`：`bpfopt/crates/bpfopt/src/main.rs:41-68`、`corpus/config/benchmark_config.yaml:1-14`。但 library 默认仍是 `PASS_REGISTRY` 全量，且 registry 第 2 项是 `const_prop`：`bpfopt/crates/bpfopt/src/passes/mod.rs:59-69`、`bpfopt/crates/bpfopt/src/pass.rs:784-789`、`bpfopt/crates/bpfopt/src/pass.rs:1031-1039`。当前 CLI 会覆盖 `ctx.policy.enabled_passes`：`bpfopt/crates/bpfopt/src/main.rs:464-480`，所以主路径没中招；但“默认 enabled_passes list 不含 const_prop”并未全局成立。

### 2. 量化目标核实：WARN

- implementation report 声称 2,327 行的口径是：`commands.rs` 截到 `#[cfg(test)]` 前 1643 行 + `dry_run.rs` 161 行 + `bpfget` 523 行，合计 2327。该口径可复现。
- raw `wc -l` 不是 2,327：`daemon/src/commands.rs` 1967、`daemon/src/dry_run.rs` 192、`daemon/crates/bpfget/src/lib.rs` 523，三文件合计 **2682**，超过 2400，净减也只有 6756 -> 2682 = -4074，未达到 net -4300。
- 若沿用上轮 review 的 daemon surface 口径（`daemon/src/*.rs + daemon/crates/bpfget`），当前 raw 为 **3995** 行：`daemon/src/server.rs` 715、`daemon/src/invalidation.rs` 346、`daemon/src/bpf.rs` 213、`daemon/src/main.rs` 39 也仍在。它们不全是 rollback 目标，但报告没有把排除口径写清。
- 模块预期未完全满足：`bpfget` 523 > plan 250-450；`commands.rs` raw/prod 1967/1643，均明显高于 plan 700-1000。

### 3. 主路径完整性：OK/WARN

- **OK：主路径确实是 snapshot -> bpfopt -> REJIT。** snapshot/write original 在 `daemon/src/commands.rs:843-850`；调用 `bpfopt optimize` 在 `daemon/src/commands.rs:957-972`；direct REJIT 在 `daemon/src/commands.rs:998-1008`，底层 `rejit_program()` 直接调 `kernel_sys::prog_rejit()`：`daemon/src/commands.rs:427-443`。
- **OK：没有 hidden final dry-run。** active `BPF_PROG_LOAD` 只在 const_prop thin dry-run：`daemon/src/dry_run.rs:61-75`；daemon 只有 `wants_const_prop` 时才生成 verifier states：`daemon/src/commands.rs:866-927`。
- **WARN：REJIT failure artifact 不保证含完整 verifier log。** daemon 写 `verifier.log` 时只读传入的初始 16MB buffer：`daemon/src/commands.rs:436-440`。但 `kernel_sys::prog_rejit()` 在 ENOSPC 时会内部扩容到 256MB 并用临时 `retry_log_buf`：`bpfopt/crates/kernel-sys/src/lib.rs:1576-1617`；这个 retry log 没有回填给 daemon。因此 error message 可能有 summary，但 preserved workdir 的 `verifier.log` 可能是截断首包，甚至缺失。`normalize_failure_artifacts()` 也允许没有 `verifier.log`：`daemon/src/commands.rs:226-229`，弱于 plan “含 verifier_log”的验收。
- **OK：单 prog 主流程失败不会阻断后续 prog。** runner 逐 prog 发请求并累积 `per_program`：`runner/libs/rejit.py:837-849`。但 map invalidation reoptimization 中单 prog 失败会让 `serve()` 返回 error：`daemon/src/server.rs:214-245`，这是后台 reapply 风险，不是 corpus 主 apply 路径。

### 4. 残留协议代码：OK/WARN

- `map_fds` / `fd_array.json` / `btf-info` / `verifier-states-out` / `replay_bpfverify_report` 在 active daemon/kernel-sys/bpfopt 代码里没有旧协议残留；命中只剩 docs 说明和 `owned_map_fds` 字段名（不是 JSON 协议）。
- `FdArray::from_json_file` 已删除；`rg from_json_file|FdArray` 只剩 in-memory fd_array 逻辑：`daemon/src/commands.rs:1280-1357`、`bpfopt/crates/kernel-sys/src/lib.rs:555-560`。
- WARN：`kernel-sys` 仍有 stale 注释说 "`BPF_PROG_LOAD` replay needs it"：`bpfopt/crates/kernel-sys/src/lib.rs:692-696`。这会误导后续实现把 replay 需求带回来。
- 旧 5/30/60 ramp 已删；thin dry-run 是单 5s timeout：`daemon/src/dry_run.rs:11-12`、`daemon/src/dry_run.rs:113-140`。

### 5. const_prop 实施：WARN

- 显式启用路径存在：`enabled_passes` 含 `const_prop` 时 daemon 调 `write_original_verifier_states()`，再把 `--verifier-states` 传给 bpfopt：`daemon/src/commands.rs:914-927`。bpfopt 对 `const_prop` 缺 states 会 fail-fast：`bpfopt/crates/bpfopt/src/main.rs:573-593`，并读取 `VerifierStatesJson`：`bpfopt/crates/bpfopt/src/main.rs:1120-1142`。
- 测试不足。`daemon/src/dry_run.rs` 只有 timeout 和 zero BTF id 两个 unit tests：`daemon/src/dry_run.rs:167-190`；没有 plan 要求的“合法 bytecode 接受 / 非法 bytecode 拒绝 / 5s timeout”三件套。daemon command tests 默认路径还显式 `bail!("test did not expect verifier-state capture")`：`daemon/src/commands.rs:1864-1870`，没有 const_prop opt-in 集成测试。

### 6. “不要做的事”核查：OK

- daemon 没有带回 `PassManager`；`PassManager` 只在 `bpfopt` 内：`bpfopt/crates/bpfopt/src/main.rs:512-535`。
- bpfopt 仍是 CLI；daemon 通过 subprocess 调 `bpfopt`：`daemon/src/commands.rs:957-972`，`daemon/Cargo.toml:26-33` 也没有依赖 bpfopt lib。
- commit 没有修改 `vendor/linux-framework/`，未动 `BPF_PROG_REJIT` kernel ABI。
- commit 文件列表没有 corpus/e2e/micro result 文件；当前 worktree 有未提交 corpus result 脏文件，但不属于 522e810e。

### 7. 文档一致性：OK/WARN

- `CLAUDE.md` 已同步新主路径和 const_prop-only dry-run：`CLAUDE.md:42-63`。
- `docs/tmp/bpfopt_design_v3.md` 已反映 direct REJIT、no main-path dry-run、const_prop opt-in：`docs/tmp/bpfopt_design_v3.md:50-65`、`docs/tmp/bpfopt_design_v3.md:108-151`。
- plan doc 已记录 Implementation Status：`docs/tmp/full-matrix-20260430/v2-style-rollback-plan.md:14-22`。
- `daemon/README.md` 已同步 socket `enabled_passes` 和 direct REJIT：`daemon/README.md:22-33`。
- WARN：docs 声称 default 11-pass 不含 const_prop：`docs/tmp/bpfopt_design_v3.md:79`，但 library `PassContext::default()` 仍含 const_prop，需统一口径。

### 8. 测试覆盖：WARN

- 静态 `#[test]` 计数 daemon 为 23，和 implementation report “23 daemon tests”一致；本 audit 未重跑 `cargo test` / `make` / vm。
- 有 REJIT error artifact 单测：`daemon/src/commands.rs:1742-1758`，但它只 mock 写入 verifier log，不覆盖 `kernel_sys::prog_rejit()` ENOSPC retry 后 artifact 是否保留完整 log。
- 缺 const_prop opt-in daemon integration test；缺 thin dry-run 合法/非法真实 load case。
- bpfopt CLI 有默认 11-pass 不含 const_prop 的测试：`bpfopt/crates/bpfopt/tests/cli_pipeline.rs:268-327`，但它仍传了无用 `--verifier-states`，不能证明默认路径不会依赖 states。

### 9. 风险项：WARN

- daemon hang watchdog 只有部分兜底。thin dry-run 超时后 request 会返回，但 worker thread 仍 detached：`daemon/src/dry_run.rs:131-136`；如果线程卡在 kernel verifier，会留在进程内。main `BPF_PROG_REJIT` 是同步 syscall：`daemon/src/commands.rs:437`，没有 timeout/restart 边界。
- REJIT log buffer 初始 16MB、kernel-sys 最高 retry 256MB 仍存在：`daemon/src/commands.rs:36`、`bpfopt/crates/kernel-sys/src/lib.rs:38`、`bpfopt/crates/kernel-sys/src/lib.rs:1641-1655`。风险是 retry log 没暴露给 failure artifact，不是 retry 缺失。
- map fd lifecycle OK：`RejitFdArray` 用 `_owned_fds` 长持 fd：`daemon/src/commands.rs:1280-1283`，dry-run 和 REJIT 都在该对象 drop 前使用：`daemon/src/commands.rs:914-1008`。

### 10. review means delete：WARN

该删的旧协议基本删了，但还可以继续删/收紧：

- 删除或改写 `kernel-sys` 中 stale “BPF_PROG_LOAD replay needs it” 注释：`bpfopt/crates/kernel-sys/src/lib.rs:692-696`。
- 把 `bpfopt::pass::default_enabled_passes()` 改为默认 11-pass，或删掉这个 public 默认并强制调用方显式传 pass list：`bpfopt/crates/bpfopt/src/pass.rs:784-789`。
- 给 `prog_rejit()` 返回结构化 `RejitError { errno, log }`，删掉 daemon 侧读初始 buffer 的脆弱路径：`daemon/src/commands.rs:436-443`。
- 若 `expected_attach_type` 只服务 const_prop dry-run，考虑把 link enumeration 移入 dry-run-only 路径，避免 snapshot 默认做 context reconstruction：`daemon/crates/bpfget/src/lib.rs:132-133`。
- dry-run tests 补齐后，可以删除 mock-only “不期望 verifier-state capture”的盲区测试形态，改成真实 opt-in 覆盖。

## 风险残留 + 优先级

- **P0：无明确 P0。** direct REJIT 主路径和旧协议删除没有发现会立刻破坏 corpus apply 的实现错误。
- **P1：默认 pass 语义漂移。** `PassContext::default()` 含 `const_prop`，和文档/验收标准不一致；先修，防止后续 library/test caller 重新把 const_prop 当默认。
- **P1：REJIT failure artifact 不可靠。** 需要让 `kernel_sys::prog_rejit()` 把最终 retry log 返回给 daemon，并让 failure artifact 至少在 verifier reject 时强制包含非空 `verifier.log`。
- **P1：watchdog 仍非强隔离。** main REJIT 无 timeout；thin dry-run timeout 不能杀 stuck kernel thread。至少文档化接受该风险，或把 const_prop dry-run 放到可杀进程边界。
- **P2：测试缺口。** 补 const_prop opt-in integration test、dry-run legal/illegal/timeout case、ENOSPC/retry-log artifact test。
- **P2：量化口径不透明。** implementation report 应明确“2327 是三文件 production-before-tests，不是 raw wc，也不是 full daemon surface”。

## 给 Claude 的提示

vm-corpus 可以验证大方向，但建议先补 P1 小修再跑：统一 `default_enabled_passes` 口径、修 REJIT log artifact 返回、至少加 const_prop opt-in 和 dry-run legal/illegal 覆盖。否则 vm-corpus 一旦遇到 REJIT reject，failure workdir 可能缺完整 verifier log，后续归因会再次浪费时间。跑前无需回滚本 commit；主架构方向是对的，当前问题是边界收紧和证据质量。
