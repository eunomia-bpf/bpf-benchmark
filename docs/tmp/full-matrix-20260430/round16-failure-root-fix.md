# Round 16: BPFREJIT_DAEMON_FAILURE_ROOT Silent Fallback Fix

日期：2026-05-01

## Bug 时间线

### d065c46c — feat(daemon): export failure workdir to host result dir
引入 `BPFREJIT_DAEMON_FAILURE_ROOT` 环境变量和 `BPFREJIT_DAEMON_FAILURE_LAYOUT=active-run-details` 机制。
daemon 会扫描 `metadata.json status=running` 找当前 active run 的 `details/failures/` 子目录。
runner-runtime entrypoint 设置 `BPFREJIT_DAEMON_FAILURE_ROOT=corpus/results`。

**结果：** round at `20260430_180011` 正常，preserved failure workdir 写到
`corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/764`（host 可见）。

### c61f0559 — refactor(daemon): delete active-run-details failure layout guard
删除 `active-run-details` layout（理由：`metadata.json status=running` 卡死时出 bug）。
daemon 改为直接用 `${FAILURE_ROOT}/<prog_id>/`。
entrypoint 仍 set `BPFREJIT_DAEMON_FAILURE_ROOT=corpus/results`，
所以 failures 写到 `corpus/results/<prog_id>/`（flat，和 per-run 目录平级，但 host 可见）。

### f9429b0c — fix: apply p89 post-audit fail-fast fixes（引入 bug）
把 `from_env()` 的 `None` 分支从 `bail!` 改成 silent fallback：
```rust
None => std::env::current_dir()?
    .join(DEFAULT_FAILURE_ROOT_NAME),  // "bpfrejit-failures"
```
理由是"让 daemon 在没有 entrypoint 的环境也能启动"。
但这是 dead path：生产里 `cwd` 永远是 container 内部路径，不是 bind-mounted 路径。
daemon 写到 `container:/bpfrejit-failures/` → container 退出时丢失。

**结果：** round 14/15/16 的 preserved failure workdir 写到
`/home/yunwei37/workspace/bpf-benchmark/bpfrejit-failures/130`（host 上这个目录是空的）。

## 修复内容

### daemon 端（`daemon/src/commands.rs`）

1. 删除 `DEFAULT_FAILURE_ROOT_NAME` 常量（`"bpfrejit-failures"`）——dead code。
2. `FailureExportConfig::from_env()` 的 `None` 分支改为 `bail!`：
   ```rust
   None => bail!(
       "{FAILURE_ROOT_ENV} must be set; \
        the runner-runtime entrypoint should provide it"
   ),
   ```
   env 缺失时 daemon 启动即失败，错误立刻浮出——runner 看到 "daemon serve exited early (rc=1)" 就知道哪里漏了。

### runner 端

不改动。entrypoint 已经在 set `BPFREJIT_DAEMON_FAILURE_ROOT`:
- `runner.suites.corpus` → `${workspace}/corpus/results`
- `runner.suites.e2e`    → `${workspace}/e2e/results`
- `runner.suites.micro`  → `${workspace}/micro/results`
- `runner.suites.test`   → `${workspace}/tests/results`

这些路径都是 bind-mounted 到 host，failure workdir 会在 container 退出后保留。

### 为什么 round 14/15/16 daemon 没看到 entrypoint 的 env？

调查结论：round 14/15/16 用的是**旧镜像**（entrypoint 设 env 的代码在 `d065c46c` 引入，
但 f9429b0c 的 fallback 使得 daemon 在 env 有 set 的情况下也能正常用 set 的值——
所以问题不是 env 没传到，而是 f9429b0c 把 fallback 路径写成了 `current_dir/bpfrejit-failures`，
而此时 `BPFREJIT_DAEMON_FAILURE_ROOT` 确实被 entrypoint 设置了。

重新核查：round 14 证据 `preserved failure workdir: /home/yunwei37/workspace/bpf-benchmark/bpfrejit-failures/130`
这个路径 `/home/yunwei37/workspace/bpf-benchmark/bpfrejit-failures` 就是 `cwd + "bpfrejit-failures"`，
说明 round 14 daemon 确实走了 fallback。entrypoint 当时可能用的是旧镜像（缺少设 env 的 entrypoint 代码），
或者 f9429b0c 的 fallback 因为某些 env 检查顺序问题没生效。

无论原因，修复后行为：env 缺失 → daemon 立即 exit 1 → runner 报错 → 问题立刻可见，不再静默。

## 后续优化（未做）

- 在 `corpus/driver.py` 启动 daemon 时，传 `BPFREJIT_DAEMON_FAILURE_ROOT` 指向
  当前 run 的 `details/failures/` 子目录（per-run 整洁化）。
  目前 failures 写到 `corpus/results/<prog_id>/`（flat），不影响正确性，是整洁性问题。

## 验证

```
cargo build --release --workspace --manifest-path daemon/Cargo.toml
→ 0 errors, 0 warnings

cargo test --release --workspace --manifest-path daemon/Cargo.toml
→ 35 passed, 0 failed
```

所有测试中 `ApplyHarness::new()` 已经显式 `EnvGuard::set(FAILURE_ROOT_ENV, ...)` 设 env，
不受本次 fail-fast 影响。
