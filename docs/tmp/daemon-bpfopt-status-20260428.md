# daemon / bpfopt status investigation (2026-04-28)

## Scope

调查对象：

- `docs/kernel-jit-optimization-plan.md`
- `daemon/src/`
- historical `bpfopt-suite/`
- current `bpfopt/`

未 commit。调查期间只写入本报告。

## Executive summary

- `daemon/` 当前是实际运行路径：`bpfrejit-daemon serve` 通过 raw `bpf(2)` syscall 枚举 live BPF program、读取 `orig_prog_insns`、运行 pass pipeline、per-pass `BPF_PROG_LOAD` verify，最后用 `BPF_PROG_REJIT` 做一次原地替换。
- `bpfopt-suite/` 在当前工作树已经不存在。历史上它是一个独立 BPF bytecode optimizer toolkit，后来在 `6b879a38` 被重命名/收敛为当前的 `bpfopt/` workspace。
- 当前 `bpfopt/` 只保留 `bpfopt-core` pass library 和 `bpfopt` CLI；它不是 daemon 的运行时依赖。`daemon/Cargo.toml` 没有依赖 `bpfopt-core`，`daemon/src/` 仍保留自己的 pass/analysis/IR/syscall 实现。
- 因此两者关系不是“daemon 调用 bpfopt-suite/bpfopt”，而是“复制后分叉”：daemon 和 bpfopt-core 各有一份 pass 相关源码，已经出现 API divergence。
- daemon 当前 release 构建通过且无 Rust warning：`make -C daemon release` 完成。
- bpfopt 当前没有 Makefile/canonical build target；按 plan doc 的 Makefile-only 约束，本次没有直接跑 `cargo`。但源码层面可见 bpfopt-core test 仍引用 daemon 侧旧 API（`target_btf_fds` / `btf_fd_for_pass` / `required_btf_fds`），而 bpfopt-core 当前 API 已换成 `target_call_offsets` / `call_off_for_pass`，这是未完成重构。

## Plan doc baseline

`docs/kernel-jit-optimization-plan.md` 的关键约束：

- Daemon 只通过 raw BPF syscall 与内核交互，不依赖 libbpf。
- CLI 收敛到 `serve --socket ...`；benchmark/e2e 通过 JSON `optimize` / `optimize-all` 请求驱动。
- per-pass verify 用 `BPF_PROG_LOAD` dry-run，最终只做一次 `BPF_PROG_REJIT`。
- `bpfopt` 架构在 #646 收敛：pass 提取到独立 `bpfopt/` workspace，只保留 `bpfopt-core` 和 `bpfopt` CLI；`verify` / `rejit` / `profiler` / `syscall` / `daemon` 逻辑继续留在 `daemon/`。

对照源码后，前三条 daemon 侧基本实现；最后一条“pass 提取”目前更像复制/分叉，而不是 daemon 真实依赖共享 crate。

## 1. daemon/src status

### Recent git history

`git log --oneline -20 -- daemon/`:

```text
d04a8689 Remove ReJIT skip logic and fix struct_ops prog type
f8bd2575 Remove silent daemon defensive fallbacks
a95c6466 daemon: inline single-use command wrappers
f0692904 daemon: keep elf parser test-only
358da2d5 daemon: fail optimize when original bytecode is missing
d3e2b602 [daemon] relax map_inline fp alias matching
70decbe4 [daemon] dedup PassResult skip scaffolding
c622357d [runner] drop legacy daemon response aliases
cae6d55f Refactor BPF program handling and improve stability checks
36ac742a [daemon] surface invalidation + GET_ORIGINAL + socket-remove errors
0133184c refactor: streamline ARM64 kernel artifact extraction in AWS executor
569ba4cd Refactor local preparation makefile and update environment configurations
e9c47976 Refactor and clean up local preparation and repository management
bee1b312 Refactor vng wrapper and remove arm64 sysroot script
99f72c35 Refactor KVM local preparation scripts and enhance testing
d1bf1c05 Refactor tests and enhance rejit functionality
7a626439 benchmark: fix framework blockers and strict review cleanup
31015924 Refactor TraceeRunner and introduce Tracee support utilities
f9cf9058 Refactor tests for daemon REJIT and update exclusion reason in results summary
71ec260a Enhance ARM64 cross-build and runtime library handling
```

最近 daemon 变更主题：

- 删除 ReJIT skip/defensive fallback，强化“错误自然浮现”。
- daemon CLI/serve wrapper 清理。
- `BPF_PROG_GET_ORIGINAL` 缺失时直接失败。
- `map_inline` / verifier / per-pass rollback 相关稳定性改动。
- runner 侧删除 legacy daemon response alias。

### Directory structure

当前 `daemon/src/` 主要模块：

```text
daemon/src/
  main.rs              # CLI entry; only `serve`
  server.rs            # Unix socket server, JSON protocol, optimize-all, profiling state, invalidation tick
  commands.rs          # optimize/apply core, per-pass verify, final REJIT, structured result
  bpf.rs               # raw BPF syscall wrappers; no libbpf
  insn.rs              # BPF instruction encoding/decoding helpers
  pass.rs              # BpfProgram IR, PassManager, PolicyConfig, KinsnRegistry
  passes/              # optimization pass implementations
  analysis/            # CFG/liveness/branch target/map info analyses
  invalidation.rs      # map-inline dependency tracking and invalidation
  profiler.rs          # bpf_stats/PMU profiling helpers
  kfunc_discovery.rs   # /sys/kernel/btf kinsn discovery
  verifier_log.rs      # verifier log parser for const/range oracle
  elf_parser.rs        # test-only object parsing support
  *_tests.rs           # unit/integration tests
```

Pass registry in `daemon/src/passes/mod.rs` contains:

- `map_inline`
- `const_prop`
- `dce`
- `skb_load_bytes_spec`
- `bounds_check_merge`
- `wide_mem`
- `bulk_memory`
- `rotate`
- `cond_select`
- `extract`
- `endian_fusion`
- `branch_flip`

### Implemented daemon flow

Key implementation points:

- `daemon/src/main.rs` exposes only `Serve { socket }`, discovers kinsns at startup, detects platform caps, constructs `PassContext`, then calls `server::cmd_serve`.
- `daemon/src/server.rs` owns the long-running Unix socket loop. It runs invalidation once per second and processes JSON requests.
- `daemon/src/server.rs` implements `optimize`, `optimize-all`, `status`, profiling start/stop/load/snapshot paths.
- `daemon/src/commands.rs::try_apply_one()` opens a live program fd, fetches original bytecode, runs the full pass pipeline, verifies each changed pass with `BPF_PROG_LOAD`, and does final `BPF_PROG_REJIT` only if the optimized program changed.
- `daemon/src/bpf.rs` defines raw syscall wrappers, including `BPF_PROG_REJIT`, `orig_prog_insns`, `bpf_prog_load_verify()`, and `bpf_prog_rejit()`.

This matches the v2 syscall + daemon flow in the plan doc.

### TODO/FIXME/WIP markers

`rg -n "TODO|FIXME|WIP|XXX|HACK" daemon/src bpfopt/crates` returned no matches.

There are no explicit TODO/FIXME/WIP markers in daemon or bpfopt source.

### Dead-code / warning status

Daemon release build:

```text
$ make -C daemon release
Finished `release` profile [optimized] target(s) ...
```

Result: daemon builds successfully, no Rust warnings printed.

There are still many `#[allow(dead_code)]` / `#[cfg_attr(not(test), allow(dead_code))]` markers. Notable examples:

- `daemon/src/invalidation.rs` has file-level `#![cfg_attr(not(test), allow(dead_code))]`, even though production serve now wires the invalidation tracker.
- `daemon/src/pass.rs` keeps `has_transforms()` as dead-code-allowed diagnostic/test helper.
- `daemon/src/profiler.rs` marks fields such as `before` / `total` as dead-code-allowed diagnostic fields.
- `daemon/src/insn.rs` marks several instruction constructors as dead-code-allowed because many are used only in tests or only by selected passes.
- `daemon/src/kfunc_discovery.rs` has several BTF constants used only by tests.

These do not produce compile warnings because they are explicitly suppressed. They are not necessarily correctness bugs, but they are cleanup debt under the plan doc's “no dead code” standard.

### Current dirty worktree relevant to daemon

The worktree is dirty. The relevant uncommitted changes observed for daemon/runner response semantics are:

```text
M daemon/src/commands.rs
M runner/libs/rejit.py
```

- `daemon/src/commands.rs`: in the “final optimized program unchanged; skipping final REJIT” path, `make_result(... applied, changed, ...)` changed `applied` from `true` to `false`.
- `runner/libs/rejit.py`: artifact compacting no longer treats `applied=false` as an error when `error==""` and `exit_code==0`; the local variable `applied` is now computed but unused.

This looks like an in-progress semantic cleanup around “no-change is not an applied ReJIT”. It is not committed and should be included in any follow-up review/test.

## 2. bpfopt-suite / bpfopt status

### Current path status

`bpfopt-suite/` does not exist in the current working tree.

Current tracked replacement is `bpfopt/`:

```text
bpfopt/
  Cargo.toml            # workspace: bpfopt-core + bpfopt
  Cargo.lock
  crates/
    bpfopt-core/
      Cargo.toml
      src/
        lib.rs
        analysis/
        insn.rs
        pass.rs
        passes/
        verifier_log.rs
        mock_maps.rs
        test_utils.rs
        elf_parser.rs
    bpfopt/
      Cargo.toml
      src/main.rs
```

`bpfopt/crates/bpfopt-core/src/lib.rs` explicitly describes the library as:

- BPF bytecode optimization passes.
- workspace-internal.
- zero kernel dependency.
- pure bytecode in / bytecode out.

`bpfopt/crates/bpfopt/src/main.rs` is a standalone CLI:

- reads raw BPF instructions from stdin or `--input`
- writes raw optimized BPF instructions to stdout or `--output`
- supports `optimize`, per-pass subcommands, `analyze`, and `list-passes`
- accepts side inputs via `--target`, `--profile`, `--map-values`, `--map-ids`

So current bpfopt is a standalone optimizer/pass toolkit, not the live daemon.

### Historical bpfopt-suite git history

`git log --oneline -20 -- bpfopt-suite/`:

```text
6b879a38 Refactor bpfopt-suite to pure bpfopt: delete non-pass crates
569ba4cd Refactor local preparation makefile and update environment configurations
ae941cf4 Refactor AWS and KVM preparation scripts, enhance benchmark functionality, and improve error handling
8b664717 fix: Fix 3 remaining bpfopt-core test failures
ea92e149 feat: Add bpfopt-suite — standalone BPF bytecode optimizer toolkit
```

`git log --oneline -20 -- bpfopt/`:

```text
8bbf5078 Update comments and archive entry for bpfopt rename
6b879a38 Refactor bpfopt-suite to pure bpfopt: delete non-pass crates
```

Important history:

- `ea92e149` added `bpfopt-suite` with many crates: `bpfopt-core`, `bpfopt`, `bpfget`, `bpfprof`, `bpfrejit-daemon`, `bpfrejit`, `bpfverify`, `kernel-sys`.
- `8b664717` fixed bpfopt-core tests.
- `6b879a38` deleted non-pass crates and renamed `bpfopt-suite` to `bpfopt`. It removed the old bpfget/bpfprof/bpfrejit-daemon/bpfrejit/bpfverify/kernel-sys crates and kept only pure pass code plus CLI.
- `8bbf5078` updated comments and plan archive references after the rename.

### Build target status

There is no Makefile under `bpfopt/`, and root/runner make rules do not reference `bpfopt` as a build artifact.

Because the plan doc says Makefile is the only build/test entry and forbids manual `cargo build`, I did not run `cargo` directly for bpfopt. This leaves a coverage gap: bpfopt is not currently validated by a canonical repo target.

## 3. Relationship between daemon and bpfopt

Current relationship: independent, not called.

Evidence:

- `daemon/Cargo.toml` depends on `anyhow`, `clap`, `goblin`, `libc`, `serde`, `serde_json`; it does not depend on `bpfopt-core`.
- `daemon/src/` contains its own `analysis`, `insn`, `pass`, `passes`, and `verifier_log` modules.
- `bpfopt/` contains another copy/fork of `analysis`, `insn`, `pass`, `passes`, and `verifier_log`.
- `runner/libs/rejit.py` starts `bpfrejit-daemon serve` and sends JSON socket requests; it does not invoke `bpfopt`.

So `bpfopt` is not currently the daemon's compiler pass library. It is a standalone/offline optimizer with similar code.

## 4. Unfinished refactor / mixed APIs

### 4.1 bpfopt-core tests still reference daemon-side BTF FD API

`bpfopt-core` production API now has:

- `KinsnRegistry.target_call_offsets`
- `KinsnRegistry.call_off_for_pass()`

But tests still reference old daemon-side transport fields/methods:

- `target_btf_fds`
- `btf_fd_for_pass()`
- `all_btf_fds()`
- `BpfProgram.required_btf_fds`

Examples:

- `bpfopt/crates/bpfopt-core/src/pass_tests.rs` constructs `KinsnRegistry { target_btf_fds: ... }` and calls `btf_fd_for_pass()`.
- `bpfopt/crates/bpfopt-core/src/passes/endian.rs` test writes `ctx.kinsn_registry.target_btf_fds` and asserts `prog.required_btf_fds.contains(&42)`.
- `bpfopt/crates/bpfopt-core/src/passes/extract.rs` has the same pattern.

But `bpfopt/crates/bpfopt-core/src/pass.rs` does not define those members. This is a clear stale-test / half-refactor artifact. Under `cargo test`, these test modules would need to compile, so this is likely a test build blocker unless hidden by some target selection not visible here.

### 4.2 daemon and bpfopt kinsn transport models diverged

Daemon model:

- `BpfProgram.required_btf_fds`
- `KinsnRegistry.target_btf_fds`
- pass emits kinsn calls with `CALL.off` determined by `ensure_btf_fd_slot()`
- final `BPF_PROG_REJIT` sends `fd_array`

bpfopt model:

- no live BTF FD transport
- target JSON may provide `call_off`
- pass emits `CALL.off` from `KinsnRegistry.target_call_offsets`

This is reasonable for an offline CLI, but it means the pass code is no longer a drop-in shared library for daemon without an adapter layer. The plan doc says pass was extracted, but the implementation has split semantics.

### 4.3 bpfopt not integrated into canonical build/test/image surfaces

`runner/mk/build.mk` tracks `DAEMON_SOURCE_FILES` for image daemon artifact, but has no bpfopt source list or bpfopt build target. Root Makefile help/targets also do not mention bpfopt.

If `bpfopt` is intended to be retained as a real artifact, it needs a canonical Makefile entry and a CI/build path. If it is just a staging copy, the plan should say so explicitly.

### 4.4 daemon dead-code suppression remains

Daemon release build has no warnings, but warning suppression is still broad in places. The most visible is file-level dead-code suppression in `daemon/src/invalidation.rs`.

This is lower risk than the bpfopt API mismatch, but it conflicts with the plan's cleanup standard.

### 4.5 Current uncommitted response semantics cleanup is incomplete

The dirty worktree changes appear to align daemon and runner around “no-change is not an applied ReJIT”, but `runner/libs/rejit.py` now leaves `applied` assigned and unused.

Follow-up should either remove the unused local or use it intentionally in a new condition/report field.

## 5. Compile / warning status

Verified:

- `make -C daemon release` succeeds on current worktree.
- No Rust warnings printed by that build.

Not verified:

- `bpfopt` compile/test through cargo was not run because there is no Makefile target and the plan doc forbids direct cargo build/test as a normal workflow.

Static finding:

- bpfopt-core test code contains stale references to fields/methods not present in current bpfopt-core `KinsnRegistry` / `BpfProgram`. This is more severe than a warning; it is likely a test compile failure once bpfopt tests are wired.

## 6. v2 architecture progress vs plan

### Implemented

- **syscall path**: daemon uses raw `bpf(2)` wrappers for program/map/BTF enumeration, program info, `orig_prog_insns`, `BPF_PROG_LOAD` verify, and `BPF_PROG_REJIT`.
- **daemon serve-only mode**: implemented in CLI and server. Historical apply/watch commands are gone from CLI.
- **JSON request model**: `status`, `optimize`, `optimize-all`, profiling commands, pass enable/disable override.
- **per-pass verify**: daemon verifies each changed pass with `BPF_PROG_LOAD`, updates verifier-derived state when possible, rolls back rejected pass changes.
- **final REJIT**: daemon does final `BPF_PROG_REJIT` only when the pipeline result changes the program.
- **kinsn discovery and transport**: daemon discovers kinsn BTF metadata, tracks required BTF FDs, builds `fd_array`, and emits packed kinsn calls.
- **dynamic map inlining invalidation**: serve loop owns `MapInvalidationTracker` and reoptimizes invalidated programs.
- **kernel/module side exists in tree**: vendor kernel has `BPF_PROG_REJIT`, `orig_prog_insns`, kinsn verifier/JIT hooks; `module/x86` and `module/arm64` contain kinsn modules.

### Partially implemented / mismatched

- **bpfopt architecture**: current `bpfopt/` exists and is pure optimizer code, but daemon does not use it. The codebase now has duplicate pass implementations. This is the main refactor mismatch.
- **bpfopt test state**: stale tests reference removed/daemon-only APIs.
- **canonical bpfopt build**: missing. There is no Makefile target, no runner image input, and no default validation path.
- **response semantics cleanup**: current dirty changes alter `summary.applied` behavior for no-change cases and runner compaction, but the Python side has an unused local and should be reviewed/tested.

### Still future / not in this refactor

Plan-doc future/low-priority items are still not present as default implemented passes:

- prefetch kinsn
- CCMP / SETcc / RDTSC / ADC/SBB / ANDN/BLS* families
- register reallocation / REJIT spill-to-register
- security passes remain explicitly out of current OSDI evaluation scope

These are not blockers for the daemon/bpfopt refactor itself.

## 7. Recommended next steps

1. Decide whether daemon should actually depend on `bpfopt-core`.
   - If yes: move shared pass/analysis/IR into `bpfopt-core`, add the daemon-specific transport hooks as traits/adapters, and remove duplicate daemon pass files.
   - If no: update plan wording to say `bpfopt` is an offline mirror/tool, not the daemon's pass library.

2. Fix bpfopt-core stale tests.
   - Replace `target_btf_fds` / `btf_fd_for_pass` / `required_btf_fds` expectations with `target_call_offsets` / `call_off_for_pass`, or add an explicit abstraction for both offline and live-REJIT transports.

3. Add canonical Makefile targets for bpfopt.
   - At minimum: build/check/test target that can be called by root Makefile or runner make rules.

4. Review current dirty response-semantics changes.
   - Confirm no-change `summary.applied=false` is intended.
   - Remove or use `runner/libs/rejit.py`'s now-unused `applied` variable.
   - Run daemon tests / runner artifact validation through the canonical target once available.

5. Clean up broad dead-code suppression where practical.
   - Especially `daemon/src/invalidation.rs` file-level suppression after production wiring.
