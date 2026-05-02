# Round 15：runner 控制 pass list

## 改动摘要

- `daemon/src/commands.rs:33` 删除 `DEFAULT_DAEMON_PASS_LIST`；`daemon/src/commands.rs:892-900` 直接使用 runner 传入的 `enabled_passes`，只做非空校验和 `canonical_pass()` 归一化。
- `daemon/src/commands.rs:1217-1231` 保留 per-pass side-input 判断；`daemon/src/commands.rs:1459-1467` 的 `ccmp` target 检查现在可由 runner arm64 policy 触达。
- `daemon/src/server.rs:361-366` 新增 `require_runner_enabled_passes()`；`daemon/src/server.rs:435-446` 和 `daemon/src/server.rs:466-483` 在 `optimize` / `optimize-batch` 缺失或空列表时返回 `no enabled_passes provided by runner`。
- `runner/libs/rejit.py:357-410` 支持 `policy.platforms.<arch>.passes`，优先用 `RUN_TARGET_ARCH`，否则用 `platform.machine()`。
- `runner/libs/rejit.py:21-45` 增加 `ccmp_sites`，避免 arm64 `ccmp` 结果在 artifact compact 时被当成未知 pass。
- `docs/tmp/bpfopt_design_v3.md:33-41`、`docs/tmp/bpfopt_design_v3.md:167-171`、`CLAUDE.md:24,44`、`daemon/README.md:39-40` 同步为 runner 是 pass policy 配置中心。

## Dead Code 清单

- D1 `daemon/src/commands.rs` `wants_branch_flip` 不再是死分支：删除 `DEFAULT_DAEMON_PASS_LIST` / `effective_pass_list()` 后，runner 可以显式传 `branch_flip`，所以保留真实 profile fail-fast 逻辑。
- D2 `daemon/src/commands.rs:1221-1231,1459-1467` 的 `ccmp` target 分支不再是死分支：arm64 runner policy 会传 `ccmp`。
- D3 `daemon/src/commands.rs` loop 内 `pass == "branch_flip"` 不再是死条件：runner-controlled list 可以包含 `branch_flip`。
- D4 `bpfopt/crates/bpfopt/src/pass.rs:379-384` 删除无调用者 `BpfProgram::has_transforms()`。
- D5 `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:57` 将 `scan_wide_mem()` 从公开函数降为模块私有，只保留同模块运行路径和测试访问。

## ccmp ARM64 启用

- `corpus/config/benchmark_config.yaml:1-31` 从单一 `policy.default.passes` 拆成 `policy.platforms.x86_64.passes` 和 `policy.platforms.arm64.passes`。
- x86_64 仍是原 12 pass；arm64 在相同顺序末尾追加 `ccmp`：`corpus/config/benchmark_config.yaml:31`。
- 未发现 e2e / micro 自有 pass-list YAML；e2e 通过 `runner.libs.rejit.benchmark_rejit_enabled_passes()` 读取同一 benchmark config，micro 配置没有 ReJIT pass list。

## 为什么必须删除 daemon default

runner 是 benchmark 配置中心，负责决定平台、实验 pass policy 和结果 provenance。daemon 只拥有 live discovery、side-input 准备、fd-array 构造和 per-pass `BPF_PROG_REJIT`。daemon-side default list 会把 policy 分裂成两份，并让 runner arm64 `ccmp`、未来 Paper B `branch_flip` 等显式配置被内部默认吞掉；这违反 fail-fast 和“runner 传什么就执行什么”的边界。

## 验证

- `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml`：通过，0 warning。
- `cargo build --release --workspace --manifest-path daemon/Cargo.toml`：通过，0 warning。
- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`：通过。
- `cargo test --release --workspace --manifest-path daemon/Cargo.toml`：通过。
- `python3 -m runner.libs.rejit --help`：退出码 0。
- 额外解析检查：默认 x86_64 pass list 为 12 个；`RUN_TARGET_ARCH=arm64` 时列表末尾为 `ccmp`。
