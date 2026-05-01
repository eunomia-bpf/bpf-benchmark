# v2 Rollback Revision Report

Date: 2026-05-01

## Scope

本次修订推翻原 plan §B.3 的 `const_prop` 默认关闭 / opt-in side-input 策略，恢复 v2 行为：

- daemon 默认 pipeline 为 12 pass：`wide_mem`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`, `bulk_memory`, `prefetch`
- daemon 自动为 enabled pass 准备需要的 side-input，调用方不需要 opt-in
- `branch_flip` 仍保持非默认 Paper B pass，缺真实 PMU profile 继续 fail-fast

## M2 Side-Input Audit

审计结果写入 `docs/tmp/full-matrix-20260430/pass-side-input-matrix.md`。

结论：

- `map_inline` 需要 live map metadata/value snapshot，也需要 verifier states 做 lookup key extraction。
- `const_prop` 需要 verifier states。
- `dce` 不读取 verifier states。
- `bounds_check_merge` 不读取 verifier states。
- kinsn passes 需要 target/kfunc BTF fd 与 call offset side-input：`rotate`, `cond_select`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch`，以及非默认 `ccmp`。
- `prefetch` 可消费 profile，但没有 profile 时按结构规则运行，不是 daemon 必需 side-input。
- `branch_flip` 不在默认 12 pass，必须有真实 program-level 和 per-site PMU profile。

## Implementation

- `bpfopt` 默认 enabled passes 统一为 12-pass policy，并恢复 `const_prop`；`ccmp` 和 `branch_flip` 不再通过默认 list 混入。
- `corpus/config/benchmark_config.yaml` 默认 policy 加回 `const_prop`。
- daemon 根据 requested passes 自动判断 side-input：
  - `map_inline` / `const_prop` 触发 thin dry-run，生成 `verifier-states.json`
  - `map_inline` 继续自动生成 `map-values.json` 和 `--map-ids`
  - kinsn passes 继续生成 `target.json` 并构造 ReJIT `fd_array`
- `bpfopt optimize` 对 `map_inline` 的离线 CLI 要求更新为 `--verifier-states`, `--map-values`, `--map-ids` 三者都存在，避免 daemon 以外调用缺 side-input 静默跑偏。
- `kernel_sys::prog_rejit()` 的 log 参数改为 caller-owned `Vec<u8>`，ENOSPC retry 扩容后的最终 verifier log 会回填给 daemon，failure artifact 写入的是 retry 后完整 log。

## Review Issues

- M1: fixed. 默认 12 pass 包含 `const_prop`，daemon 自动准备 verifier states。
- M2: fixed. pass × side-input matrix 已落文档；发现 `map_inline` 也需要 verifier states，并已纳入自动准备逻辑。
- P1#1: verified. `PassContext::default()` 通过 `DEFAULT_ENABLED_PASS_ORDER` 对齐 12-pass policy。
- P1#2: fixed. ENOSPC retry 后的最终 verifier log 暴露给 daemon，并有 kernel-sys/daemon artifact 测试覆盖。
- P1#3: fixed by documentation. Main `BPF_PROG_REJIT` 无 daemon-side timeout；kernel verifier hang 会阻塞 daemon，这是当前接受的限制。
- P2#4: fixed. 新增 dry-run accepted / errno 22 / 5s timeout 测试、`const_prop` 自动 dry-run integration test、ENOSPC artifact test。
- P2#5: fixed. `v2-style-rollback-impl.md` 增加计数口径说明：2,327 是三文件 production-before-`#[cfg(test)]`；raw wc 三文件是 2,682；full daemon surface 是 3,995。

## Validation

允许的验证全部通过：

- `cargo test --workspace --manifest-path daemon/Cargo.toml`: passed, 28 daemon tests.
- `cargo test --workspace --manifest-path bpfopt/Cargo.toml`: passed, including bpfopt lib/bin/CLI, bpfprof, kernel-sys, and integration tests.
- `make daemon-tests`: passed, 28 daemon tests.
- `make check`: passed. This runs `vm-test`; final guest summary was `RESULTS: 27 passed, 0 failed`, including `fuzz_rejit (1000 rounds)`.

Forbidden targets were not run:

- `make vm-corpus`: not run.
- `make vm-e2e`: not run.
- `make vm-micro`: not run.

## Notes for Claude Corpus Run

Next step remains Claude-owned `make vm-corpus`. This revision intentionally does not filter or skip any ReJIT program; any ReJIT failure should surface as a result error with preserved artifacts.
