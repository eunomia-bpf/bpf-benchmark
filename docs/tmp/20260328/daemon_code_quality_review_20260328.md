# BpfReJIT Daemon Code Quality Review (2026-03-28)

## 范围与方法

本次审查覆盖了以下内容：

- `daemon/src/main.rs`
- `daemon/src/pass.rs`
- `daemon/src/commands.rs`
- `daemon/src/server.rs`
- `daemon/src/**/*.rs`
- `daemon/src/passes/*.rs`
- `daemon/tests/`
- `daemon/Cargo.toml`

额外做了两项 host-side 验证：

- `make daemon-tests`：结果为 `556 passed / 13 ignored / 0 failed`
- `cargo run --manifest-path daemon/Cargo.toml -- --list-passes`：CLI 直接报错，要求必须提供 subcommand

补充观察：

- `daemon/Cargo.toml` 没有 crate 级 `[features]`；“feature flag”问题主要不在 Cargo feature，而在运行时配置和兼容别名层。
- 当前默认 pipeline 的实际构造入口不是 `pass.rs` 里的 `build_default_pipeline`，而是 `daemon/src/commands.rs` 里的 `build_pipeline()`，它直接调用 `daemon/src/passes/mod.rs` 的 `build_full_pipeline()`。

## 总结

结论分三类：

- 高优先级问题主要集中在回滚归因、默认 pipeline、CLI 可用性。
- 中优先级问题主要集中在字符串化错误传递、静默吞错、配置面过于复杂但部分失效、测试覆盖错位。
- 结构上存在多个 God File，以及 `pass` 核心框架与 `passes` 注册表之间的反向依赖。

## 详细发现

### HIGH 1. 回滚归因机制当前几乎退化为“总是怪最后一个发生修改的 pass”

- 证据：
  `daemon/src/pass.rs:774-787` 在构造 `PipelineResult.attribution` 时，把每个发生过修改的 pass 都标成 `0..program.insns.len()` 的整段范围。
- 证据：
  `daemon/src/commands.rs:319-335` 的 `attribute_verifier_failure()` 会遍历这些范围，并返回最后一个覆盖失败 PC 的 pass。
- 结果：
  由于每个 changed pass 的范围都覆盖整个最终程序，真实行为基本等价于“把 verifier 失败归因给最后一个 changed pass”。
- 测试缺口：
  `daemon/src/commands.rs:1572-1645` 的归因测试使用的是手工构造的精确范围；`daemon/src/pass.rs:1889-1998` 的 attribution 测试只检查“有条目/有名字”，没有检查范围语义，因此没有覆盖真实集成行为。
- 影响：
  rollback 会禁错 pass，导致重试行为失真，调试结论也会误导。
- 建议：
  让 pass 在 rewrite 阶段产出真实的 `old_pc -> new_pc` / `new_pc range` 归因数据；至少先做到“仅标记实际变更窗口”，不要把整段程序都归给每个 pass。

### HIGH 2. 默认 pipeline 包含了生产路径上实际不会生效的 `branch_flip`

- 证据：
  `daemon/src/passes/mod.rs:132-140` 把 `branch_flip` 放进默认注册表，`daemon/src/passes/mod.rs:164-168` 没把它排除在默认 pipeline 之外，`daemon/src/passes/mod.rs:239-246` 因此会默认加入它。
- 证据：
  `daemon/src/passes/branch_flip.rs:80-96` 在 `program.branch_miss_rate == None` 时直接返回 skip。
- 证据：
  `branch_flip` 还要求 per-site PGO 注解，见 `daemon/src/passes/branch_flip.rs:153-166`。
- 证据：
  生产入口 `daemon/src/commands.rs:526` 和 `daemon/src/commands.rs:814` 都调用的是 `pm.run(...)`，不是 `run_with_profiling(...)`。
- 证据：
  `run_with_profiling()` 在生产代码没有调用点，只有测试使用，见 `daemon/src/pass.rs:804-814` 和 `daemon/src/test_utils.rs:196-209`。
- 证据：
  `collect_program_profiling()` 目前也是未接线代码，`make daemon-tests`/`cargo run` 都报告它未使用，定义在 `daemon/src/profiler.rs:164-203`。
- 影响：
  默认 pipeline 多了一个在生产永远只会 skip 的 pass，增加复杂度、日志噪音和维护负担，也会误导读代码的人以为 branch flip 已经是默认生效能力。
- 建议：
  二选一。
  1. 把 `branch_flip` 从默认 pipeline 移除，改成显式 profile/pgo 模式才启用。
  2. 或者把 profiling 注入真正接进 `rewrite/apply/watch/serve` 的某个受控入口。

### HIGH 3. `--list-passes` 设计成全局参数，但实际上不能单独使用

- 证据：
  `daemon/src/main.rs:27-41` 把 `list_passes` 放在全局 `Cli` 上，同时把 `command` 定义成必填的 `Command` 而不是 `Option<Command>`。
- 证据：
  `daemon/src/main.rs:103-106` 明确希望 `--list-passes` 直接打印后退出。
- 实测：
  `cargo run --manifest-path daemon/Cargo.toml -- --list-passes` 报错：`requires a subcommand but one was not provided`。
- 相关复杂度问题：
  `daemon/src/main.rs:32-38` 的全局 `--no-rollback` 只在 `Apply/ApplyAll/Serve/Watch` 使用，见 `daemon/src/main.rs:139-152`；对 `Enumerate/Rewrite/Profile` 是无效参数。
- 影响：
  最基础的 pass 可发现性被破坏；同时 CLI 暴露了对部分子命令无意义的参数。
- 建议：
  把 `command` 改成 `Option<Command>`，或用 clap 显式放宽 subcommand 必填；并把 `--no-rollback` 下沉到真正会触发 REJIT 的子命令。

### MEDIUM 4. pass 选择配置过于字符串化，且兼容别名在真实入口上并不工作

- 证据：
  `daemon/src/passes/mod.rs:45-55` 明确维护了一层 pass registry + legacy alias。
- 证据：
  例如 `skb_load_bytes` / `bulk_mem` / `dangerous_helper` 别名分别定义在 `daemon/src/passes/mod.rs:84-87`、`daemon/src/passes/mod.rs:102-105`、`daemon/src/passes/mod.rs:149-152`。
- 证据：
  `daemon/src/passes/mod.rs:209-224` 提供了 `validate_pass_names()` 和 `selected_pass_names()`，可以把 alias 规范化为 canonical name。
- 证据：
  但 `daemon/src/server.rs:171-205` 的 `request_context()` 只是把请求里的 `enabled_passes` / `disabled_passes` 原样拷贝到 `PolicyConfig`。
- 证据：
  `daemon/src/pass.rs:858-872` 的 `pass_allowed()` 只做精确字符串匹配。
- 结果：
  serve 模式里传 alias 不会报错，但也不会命中真实 pass；传未知 pass 名也不会报错，只会静默变成 no-op。
- 证据：
  `daemon/src/pass.rs:573-580` 的 `PolicyConfig` 还有 `pipeline_profile`，但全仓库唯一引用就是字段定义本身，见 grep 结果和 `make daemon-tests` 的 dead-code warning。
- 影响：
  这是“有兼容层但入口没接上”的典型情况，也让 `enabled_passes` / `disabled_passes` / `pipeline_profile` 这组配置显得过度设计且部分失效。
- 建议：
  统一入口。
  1. 所有外部 pass 名先经过 `selected_pass_names()` 规范化和校验。
  2. `enabled_passes` 直接构造 custom pipeline，而不是 build full pipeline 后再字符串过滤。
  3. `pipeline_profile` 要么真正接线，要么删除。

### MEDIUM 5. REJIT 错误是“字符串协议”，错误类型不清晰，verifier log 通过字符串反解析

- 证据：
  `daemon/src/bpf.rs:1041-1090` 的 `run_rejit_once()` 在失败时用 `anyhow::bail!` 拼接出 `"BPF_PROG_REJIT: ...\nverifier log:\n..."` 这种字符串错误。
- 证据：
  `daemon/src/bpf.rs:1116-1125` 还会基于字符串内容再做一次特殊分支。
- 证据：
  `daemon/src/commands.rs:1029-1034` 通过 `find("verifier log:\n")` 从错误字符串里反提取 verifier log。
- 影响：
  errno、verifier log、第一次失败/第二次失败、是否 fast-path、是否 post-verify 这些语义都被压扁成字符串，导致调用方只能靠 brittle heuristics 解析。
- 结果：
  调试体验差，也让后续做稳定的 API/JSON 错误输出很困难。
- 建议：
  给 REJIT 建立结构化错误类型，例如 `RejitError { errno, stage, verifier_log, first_failure, second_failure }`；`commands.rs` 直接读取字段，不要再做字符串解析。

### MEDIUM 6. 多处存在静默吞错或弱化错误的路径，尤其在 map / 枚举相关流程

- 证据：
  `daemon/src/commands.rs:474`、`daemon/src/commands.rs:521`、`daemon/src/commands.rs:783` 对 `bpf_prog_get_map_ids()` 直接 `unwrap_or_default()`。
- 影响：
  一旦 `map_ids` 获取失败，系统会把它当成“这个程序没有 map”，后续行为会偏向误判/跳过，而不是暴露根因。
- 证据：
  `daemon/src/bpf.rs:953-980` 的 `relocate_map_fds_with_bindings()` 对单个 map FD 打开失败只打印 warning 并继续。
- 证据：
  `daemon/src/commands.rs:831-843` 和 `daemon/src/commands.rs:906-918` 又把 relocation 失败包成 warning 继续 REJIT。
- 影响：
  后续 verifier / REJIT 失败会变成“后果错误”，而不是“前置 map relocation 失败”的直接错误。
- 证据：
  `daemon/src/bpf.rs:1146-1154` 的 `iter_prog_ids()` 在任意错误上都直接终止迭代，没有区分“枚举结束”和“真实错误”。
- 影响：
  `enumerate` / `apply-all` / `watch` / serve `optimize-all` 都可能在中途出错时静默得到截断列表。
- 证据：
  `daemon/src/analysis/map_info.rs:211-220` 的 `resolve_live_map_info()` 用 `.ok()?` 吞掉 live map metadata 读取错误。
- 影响：
  `map_inline` 最终只能报 `map info unavailable`，见 `daemon/src/passes/map_inline.rs:754-770`，无法告诉调用者到底是权限、ID、还是 syscall 问题。
- 建议：
  对“必需前置条件”不要再默认化。
  1. `map_ids` 获取失败应向上传播。
  2. relocation 失败应中止该次 apply，而不是继续。
  3. `iter_prog_ids()` 应只在明确的 end-of-list errno 上停止。
  4. `MapInfoAnalysis` 至少要保留底层错误用于 diagnostics。

### MEDIUM 7. `enumerate` 的 dry-run pipeline 没有设置真实 `prog_type`，结果可能和 `rewrite/apply` 不一致

- 证据：
  `daemon/src/commands.rs:460-478` 的 `enumerate_one()` 直接用传入的 `ctx` 跑 pipeline，没有把 `info.prog_type` 填到 `local_ctx.prog_type`。
- 对比：
  `daemon/src/commands.rs:524-526` 的 `cmd_rewrite()` 会设置 `local_ctx.prog_type = info.prog_type`。
- 对比：
  `daemon/src/commands.rs:807-815` 的 `try_apply_one()` 也会设置 `local_ctx.prog_type = info.prog_type`。
- 影响：
  `enumerate` 输出的 “sites” 统计可能比真实 rewrite/apply 更保守或更宽松，尤其是依赖 program-type gating 的 pass。
- 建议：
  让 `enumerate_one()` 和 `rewrite/apply` 走同样的上下文构造流程。

### MEDIUM 8. 测试数量很多，但 orchestration/serve 路径的真实覆盖并不匹配复杂度

- 证据：
  `make daemon-tests` 总数很大，但 `daemon/src/server.rs:394-490` 只有 4 个很小的测试，几乎没有覆盖 `process_request()`、JSON 参数校验、`enabled_passes/disabled_passes`、panic response JSON、`optimize-all` 等 serve 核心行为。
- 证据：
  `daemon/src/commands.rs:1767-1822` 唯一真正靠近 `try_apply_one()` 的 integration test 被 `#[ignore]`。
- 证据：
  多个“真实字节码”测试会在前置工件缺失时打印 `SKIP` 然后直接 `return`，例如 `daemon/src/passes/mod.rs:799-807`、`daemon/src/passes/mod.rs:845-853`、`daemon/src/passes/mod.rs:891-899`、`daemon/src/passes/mod.rs:936-944`、`daemon/src/passes/mod.rs:984-992`。
- 影响：
  这些测试在 Cargo 统计里会算作通过，而不是 skip；CI 绿灯不等于这些路径真的被跑过。
- 另一个错位点：
  `daemon/src/test_utils.rs:161-178` 的 `permissive_pass_ctx()` 会把所有平台/kfunc能力都打开，因此大量 real-bytecode 测试测到的是“重写形状”，不是“真实平台可用性/REJIT 可接受性”。
- 建议：
  1. 给 serve/request parsing 增加单元测试和 golden JSON 测试。
  2. 给 `try_apply_one` 的失败路径、rollback 路径、map relocation 错误路径增加 host-side mock 测试。
  3. 把工件缺失改成显式 skip 机制，而不是 `eprintln! + return`。

### LOW 9. 有一个 `#[ignore]` 条目本质上不是测试，而是临时统计脚本

- 证据：
  `daemon/src/passes/map_inline.rs:2902-2955` 的 `dump_bcc_top20_pattern_stats()` 是模式统计/调研工具，不做断言，只是打印汇总。
- 影响：
  这会污染测试模块职责，也让“ignored tests”列表混入非测试项。
- 建议：
  把它移到 `tools/`、`scripts/` 或单独的 analysis command，而不是留在 test target 里。

### MEDIUM 10. 代码组织有明显 God File，且核心依赖方向已经开始反转

- 证据：
  行数统计显示以下文件已经明显过大。
  `daemon/src/passes/map_inline.rs` 5134 行
  `daemon/src/bpf.rs` 2271 行
  `daemon/src/pass.rs` 2060 行
  `daemon/src/passes/mod.rs` 1884 行
  `daemon/src/commands.rs` 1823 行
  `daemon/src/passes/wide_mem.rs` 1615 行
  `daemon/src/passes/bulk_memory.rs` 1372 行
  `daemon/src/passes/live_patch.rs` 1334 行
  `daemon/src/passes/cond_select.rs` 1129 行
  `daemon/src/passes/branch_flip.rs` 1110 行
  `daemon/src/passes/bounds_check_merge.rs` 1020 行
- 证据：
  `daemon/src/pass.rs:582-584` 的 `default_enabled_passes()` 反向依赖 `crate::passes::selected_pass_names(None)`。
- 证据：
  而 `daemon/src/passes/mod.rs:39-40` 又依赖 `crate::pass::{BpfPass, PassManager}`。
- 影响：
  `pass` 这种本应是“框架内核”的模块，已经开始依赖具体 pass 注册表，形成概念上的双向依赖；长期看会让框架层越来越难拆、难测、难复用。
- 建议：
  1. 把默认 pipeline / pass registry / alias 解析移出 `pass.rs`，放到单独的 `policy` 或 `pipeline_registry` 模块。
  2. 把 `map_inline.rs` 拆成 scanner、key recovery、rewrite builder、value reader、tests/support。
  3. 把 `commands.rs` 拆成 CLI actions、REJIT orchestration、JSON schema/result types。
  4. 把 `passes/mod.rs` 的大块集成测试搬到 `tests/` 或单独 test support 模块。

## 关于默认值、兼容层和 feature/config 的结论

- CLI 默认值里最明显的问题不是数字默认值，而是参数语义：
  `--list-passes` 设计意图正确，但当前不可用；`--no-rollback` 范围过大。
- Rust crate 层面没有遗留 Cargo feature flag。
- 运行时配置层面确实有“保留但未接线”的项：
  `pipeline_profile`、`build_pipeline_for_profile()`、`validate_pass_names()`、legacy alias 解析能力。
- 默认 pipeline 本身的最大问题是把 `branch_flip` 作为默认启用项，但生产路径没有提供它所需的 profiling 数据。

## 测试结论

- `#[ignore]` 里大多数 root/BPF/BTF 相关 smoke test 是合理的，例如：
  `daemon/src/bpf.rs:1969-2142`
  `daemon/src/commands.rs:1770`
  `daemon/src/kfunc_discovery.rs:906-955`
- 但当前更大的问题不是 ignored test 本身，而是：
  真实 orchestration 覆盖不足，以及多个测试用“手动 SKIP”伪装成 pass。

## 优先修复建议

建议按下面顺序处理：

1. 修正 rollback attribution 的真实归因数据模型。
2. 把 `branch_flip` 从默认 pipeline 移除，直到 profiling 真正接线。
3. 修 CLI：让 `--list-passes` 可单独运行，并缩小 `--no-rollback` 的适用范围。
4. 统一 serve/API 的 pass 名规范化和校验，删除无效的 `pipeline_profile` 或真正接线。
5. 把 REJIT 错误改成结构化错误类型，停止通过字符串拼 verifier log。
6. 消灭 map-id / relocation / program enumeration 的静默吞错。
7. 给 `server.rs` 和 `try_apply_one` 的失败路径补真实单测/集成测。
