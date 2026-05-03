# Round 15 — commit 07c78af9 review

**Review 时间**：2026-05-01  
**Reviewer**：Claude  
**Review 方法**：读 diff、grep 实际代码、cargo build/test/clippy 实跑

---

## 任务 1：删 DEFAULT_DAEMON_PASS_LIST + effective_pass_list()，daemon 完全接受 runner 传的 list

**结果：完成**

1. `grep -rn 'DEFAULT_DAEMON_PASS_LIST\|effective_pass_list' daemon/` → **0 hit**（含注释）
2. `grep -rn 'DEFAULT_DAEMON_PASS_LIST\|effective_pass_list' bpfopt/` → **0 hit**
3. `daemon/src/commands.rs:892` 处：`if enabled_passes.is_empty() { bail!(...) }` — fail-fast 确认
4. `daemon/src/server.rs:361-367` 新增 `require_runner_enabled_passes()` 在 `optimize` / `optimize-batch` 命令入口分别（line 435、466）fail-fast 返回 error JSON
5. `daemon/src/commands.rs` 非测试区无任何 hardcoded pass list（只有 `canonical_pass()` 归一化 map、`pass_needs_target()` dispatch，不是 list）
6. `daemon/src/commands.rs:2230-2248`：`test_runner_passes()` 是 `#[cfg(test)]` 模块内的测试 helper，仅用于单元测试。**不是生产 hardcoded list**，可接受

**CLAUDE.md 约束满足**：Fail-Fast ✅，No Dead Code ✅（DEFAULT_DAEMON_PASS_LIST 已删）

---

## 任务 2：ARM64 启用 ccmp

**结果：完成**

1. `corpus/config/benchmark_config.yaml`：从 `policy.default` 结构改为 `policy.platforms.{x86_64,arm64}`
2. `x86_64` 列表：12 pass，**不含 ccmp** ✅
3. `arm64` 列表：12 + `ccmp` = 13 pass ✅
4. `runner/libs/rejit.py:355-392` 新增 `_benchmark_policy_arch_keys()` + `_platform_policy_passes()`，优先读 `policy.platforms`，用 `RUN_TARGET_ARCH` 环境变量或 `platform.machine()` 选平台键，不支持时 `raise SystemExit`（fail-fast）
5. 仅一个 benchmark_config.yaml（corpus/config 下），e2e / micro 无独立 pass-list YAML（e2e 通过 `benchmark_rejit_enabled_passes()` 读同一文件，micro 不用 daemon）
6. 无平台 runtime check 阻止 x86 加载 ccmp：daemon 端正确实现为 `pass_needs_target("ccmp") == true`，运行时会通过 `missing_target_kinsns()` 检查 `bpf_ccmp64` 是否在线；若不在线则 fail（x86 不加载 `bpf_ccmp.ko`，自然 fail-fast）

---

## 任务 3：5 处 dead code 处理

**结果：完成（D1/D2/D3 策略正确，D4/D5 删除）**

| ID | 处理方式 | 验证 |
|----|---------|------|
| D1 `wants_branch_flip` | **保留，不再是死分支**。删除 `effective_pass_list()` 后，runner 可显式传 `branch_flip`，`wants_branch_flip` 真实可达 | grep 确认代码在 line 983-997 |
| D2 `pass_needs_target/missing_target_kinsns` 中 `"ccmp"` arm | **保留，不再是死分支**。ARM64 runner policy 含 ccmp，这些 arm 现在可达 | grep 确认 line 1226, 1450, 1466 |
| D3 loop 内 `pass == "branch_flip"` 检查 | **保留，不再是死条件**。runner-controlled list 可含 branch_flip | grep 确认 line 1046 |
| D4 `BpfProgram::has_transforms()` | **已删除** | `grep -rn 'has_transforms' bpfopt/` → 0 hit |
| D5 `scan_wide_mem` 过宽 pub | **已改为私有** `fn scan_wide_mem` | grep 确认 `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:57` |

**说明**：round15-kinsn-passes-and-deadcode.md 报告中，D1/D2/D3 的根本原因是 `effective_pass_list()` 阻止非默认 list 进入，导致这些分支不可达。删除 `effective_pass_list()` 后，这些分支自然变活，保留是正确的处理方式，不是遗漏。

---

## 额外检查

### 新引入的问题

**无新 dead code 引入**：

- `canonical_pass()` 在 6 处被调用（line 606, 897, 936, 985, 988, 1447, 1463, 1653），仍有充分 caller
- `wants_branch_flip` / `wants_prefetch` 分支均有真实 caller
- `require_runner_enabled_passes()` 在 server.rs 两处被调用（line 435, 466）

**潜在协议风险（非新引入，但值得记录）**：

`_optimize_request()`（runner/libs/rejit.py:810-812）仍有 `if enabled_passes is not None` 条件判断：若 `enabled_passes=None` 则不发送该字段。在当前生产路径中，`case_common._effective_enabled_passes()` 和 `corpus/driver.py` 均保证传非 None 列表，不会命中此路径。但 `DaemonSession.apply_rejit()` 的签名仍接受 `enabled_passes: Sequence[str] | None = None`，若未来有调用方传 `None`，daemon 会返回 error JSON（不 crash），属于软性风险。

### runner-daemon 协议一致性

- daemon 端：`optimize` / `optimize-batch` 两个命令均在 server.rs 入口强制校验非空 `enabled_passes`
- runner 端：corpus/driver.py line 534 `benchmark_rejit_enabled_passes()` 始终返回非空列表；case_common.py `_effective_enabled_passes()` 始终返回非空列表
- 两端协议对齐 ✅

### build / test / clippy 实跑结果

```
cargo build --release bpfopt:   Finished — 0 warnings, 0 errors ✅
cargo build --release daemon:   Finished — 0 warnings, 0 errors ✅
cargo test --release bpfopt:    35 pass, 0 fail ✅（含单元测试）
cargo test --release daemon:    35 pass, 0 fail ✅（含新 2 个 enabled_passes 拒绝测试）
cargo clippy bpfopt -D warnings: FAIL — kernel-sys::create_map() too-many-arguments (8/7)
cargo clippy daemon -D warnings: FAIL — commands::run_bpfopt_pass() too-many-arguments (11/7)
```

**clippy 错误是预存在问题，非 07c78af9 引入**：

- `kernel-sys/src/lib.rs:1023 create_map()` 和 `daemon/src/commands.rs:1288 run_bpfopt_pass()` 均未被本次 commit 修改（diff 中无对应 `+/-` 行）
- 两个函数在 commit 父节点 `ad3e401a` 时已存在

---

## 200 字以内总结

commit 07c78af9 **完整完成 3 件任务**：

**任务 1**：`DEFAULT_DAEMON_PASS_LIST` 和 `effective_pass_list()` 已完全删除（0 grep hit），daemon 在 `optimize` / `optimize-batch` 入口 fail-fast 拒绝缺失或空的 `enabled_passes`，无 fallback。

**任务 2**：benchmark_config.yaml 正确拆分为 `policy.platforms.{x86_64,arm64}`，x86_64 不含 ccmp，arm64 含 ccmp，runner 端 fail-fast 读取平台对应列表。

**任务 3**：D4（has_transforms 删除）和 D5（scan_wide_mem 降为私有）已完成；D1/D2/D3 不再是死代码，删除 `effective_pass_list()` 后这些分支真实可达，保留是正确处理。

**遗留问题**：clippy `-D warnings` 下 `kernel-sys::create_map` 和 `run_bpfopt_pass` 有 too-many-arguments 警告，**预存在于本次 commit 之前**，非本次引入。build 和 test 全绿。
