# P74 daemon + bpfopt architecture/dead-code review

日期：2026-04-29

范围：`daemon/src/`，`bpfopt/crates/bpfopt/src/`，`bpfopt/crates/{bpfget,bpfrejit,bpfverify,bpfprof,kernel-sys}/`，以及相关 `Cargo.toml`。本次只 review，没有修改源码，也没有运行 KVM/AWS/cargo build/test。

## 总评

架构干净度：7/10。

P66/P71 后，最大的一类历史债已经清掉：daemon 不再链接 `bpfopt` lib，不再维护 `PassManager`，不再内嵌 pass 实现；CLI crate 之间没有 path dependency；直接 `libc::syscall(SYS_bpf, ...)` 也只剩在 `kernel-sys`。但是仍有几个 v3/fail-fast 约束层面的硬问题：daemon socket 和 `PassManager` 仍保留 `disabled_passes` 过滤表面；daemon watcher/status 有错误降级；map-inline side-input 仍由 daemon 进程内读 live map 值生成；`branch_flip` 在缺少 per-site PGO 时仍会 heuristic fallback 变换。

## ❌ Critical

1. `disabled_passes` 仍是可见过滤/排除 API，违反 No ReJIT Filtering / no exclusion surface。
   - daemon socket 仍解析并从 enabled list 中扣掉 disabled list：`daemon/src/server.rs:448-462`。
   - 相关测试只验证该旧接口：`daemon/src/server.rs:957-982`。
   - daemon result attempt 仍序列化 `disabled_passes`，但生产路径全是空数组：`daemon/src/commands.rs:582-600`、`daemon/src/commands.rs:696-700`、`daemon/src/commands.rs:1382-1389`、`daemon/src/commands.rs:1473-1489`。
   - bpfopt pass policy 也保留 disabled list，并会跳过 pass：`bpfopt/crates/bpfopt/src/pass.rs:817-822`、`bpfopt/crates/bpfopt/src/pass.rs:1122-1134`。
   - grep 结果：除测试和旧结果 JSON 外，真实 runner 只消费 `final_disabled_passes` 结果字段；没有真实请求方需要 `disabled_passes` 输入。
   - 建议：删除 daemon request `disabled_passes`、`AttemptRecord.disabled_passes`、`PolicyConfig.disabled_passes` 和对应测试/fixture 字段。pass 选择只允许显式 `enabled_passes`/`--passes`。

2. daemon watcher 对 BPF 枚举失败只打印后继续服务，违反 fail-fast / no silenced syscall errors。
   - 初始化 watcher 时 `iter_prog_ids()` 出错只 `eprintln!` 后 `break`，最后仍返回 `Self { seen }`：`daemon/src/server.rs:228-242`。
   - tick 时错误也只打印后 `break`：`daemon/src/server.rs:244-258`。
   - watch 是 v3 daemon 的核心职责之一；这里应把错误传播到 `serve` 主循环并退出，而不是用不完整 watcher 状态继续。

3. daemon `status` 会隐藏 CLI discovery 失败并返回 `"status": "ok"`。
   - `commands::available_passes_help(config)` 失败时被格式化成 `"unavailable: ..."`：`daemon/src/server.rs:749-752`。
   - 同一个 response 仍返回 `"status": "ok"`：`daemon/src/server.rs:753-760`。
   - 这会把缺少 `bpfopt`、PATH 错误、CLI 执行错误编码成信息字段。按 fail-fast，应让 status 返回 error，至少不能把 daemon health 报成 ok。

4. daemon 仍在进程内生成 map-inline live value side-input，超出“socket -> CLI adapter”的瘦身边界。
   - optimize 中直接调用 `write_live_map_values(...)` 生成 `map_values.json`：`daemon/src/commands.rs:1306-1320`。
   - 该函数循环运行 `bpfopt scan-map-keys`，但 live map fd 打开和 value lookup 由 daemon 闭包完成：`daemon/src/commands.rs:1746-1808`。
   - 具体 BPF map lookup 在 daemon adapter 里通过 `kernel_sys::bpf_map_lookup_elem` 进行：`daemon/src/bpf.rs:25-50`。
   - v3/plan 文档把 kernel-facing side-input 生成放在 `bpfget`，daemon 只保留 socket/watch/invalidation/CLI fork+exec。map invalidation 读 map 值是 daemon 职责，但“优化前 side-input 采集”更适合移入 `bpfget` 或独立 CLI，否则 daemon 仍承担 pipeline 业务逻辑。

5. `branch_flip` 缺少 per-site branch profile 时仍会启用 size-asymmetry heuristic fallback 做变换。
   - 无 PMU 时 pass 会整体不改，这是好的：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:89-96`。
   - 但单个 site 没有 `branch_profile` 时，如果 `heuristic_should_flip(site)` 为真，仍设置 `should_flip = true`：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:153-172`。
   - diagnostics 明确称为 fallback：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:191-196`。
   - 这和“缺能力不能降级到别的逻辑”的约束冲突。建议 branch_flip 明确变成 per-site PGO-only：缺 site profile 就 skip/error，不做 heuristic transform。

## ⚠️ Minor

1. `daemon/src/commands.rs` 仍是 2991 LOC 的“大适配器”，职责边界过宽。
   - 同一文件包含 CLI config/workdir/failure export、profile session、map snapshot、target/fd_array、optimize orchestration、verify/rejit failure capture、JSON schema 和测试。
   - 例子：profile 进程管理在 `daemon/src/commands.rs:1046-1135`；optimize pipeline 在 `daemon/src/commands.rs:1216-1354`；map snapshot 在 `daemon/src/commands.rs:1746-1865`；subprocess runner 在 `daemon/src/commands.rs:2105-2139`。
   - 建议拆成 `subprocess.rs`、`profile.rs`、`map_snapshot.rs`、`failure_export.rs`、`optimize.rs`。这主要是降低耦合，不一定带来大量净删。

2. daemon 文档注释仍停留在旧架构。
   - `daemon/src/main.rs:4-5` 说 daemon “scans live kernel BPF programs for optimization sites and can apply bytecode rewrites via BPF_PROG_REJIT”，但现在应是 socket/watch/invalidation + CLI subprocess adapter。
   - `bpfopt/crates/bpfopt/src/pass.rs:156-160` 仍说 daemon installs live raw-syscall provider；daemon 已不链接 bpfopt lib。

3. `bpfopt` pass registry/order 有三份 truth source，后续新增/删除 pass 很容易漂移。
   - `ALL_PASS_ORDER` / `DEFAULT_OPTIMIZE_PASS_ORDER`：`bpfopt/crates/bpfopt/src/main.rs:27-42`。
   - `Command::canonical_pass_name()` 手写 match：`bpfopt/crates/bpfopt/src/main.rs:395-415`。
   - `PASS_REGISTRY`：`bpfopt/crates/bpfopt/src/passes/mod.rs:52-118`。
   - `list_passes()` 仍遍历 `ALL_PASS_ORDER` 再查 registry：`bpfopt/crates/bpfopt/src/main.rs:418-438`。
   - 建议让 `PASS_REGISTRY` 成为唯一顺序/描述源；CLI 别名和 clap subcommand 可以保留，但 list/default optimize order 应直接来自 registry。

4. `pass.rs` 1214 LOC，包含 ABI/data model、provider traits、analysis cache/registry、pass trait、policy、PassManager、debug trace、fixed-point logic。
   - `PolicyConfig`、`AnyAnalysis`、`AnalysisRegistry`、`PassManager` 都在一个文件：`bpfopt/crates/bpfopt/src/pass.rs:817-901`。
   - 建议按职责拆分为 `program.rs`/`context.rs`、`analysis_cache.rs`、`manager.rs`、`providers.rs`。这不是行为 bug，但会让 public surface 审计更清晰。

5. CLI crates 不是 thin wrapper。
   - `bpfget/src/main.rs` 1071 LOC，包含 load metadata validation、target BTF probing、map manifest、atomic output：`bpfopt/crates/bpfget/src/main.rs:262-313`、`bpfopt/crates/bpfget/src/main.rs:395-461`、`bpfopt/crates/bpfget/src/main.rs:625-690`。
   - `bpfverify/src/main.rs` 957 LOC，另有 `verifier_log.rs` 1039 LOC。
   - `bpfprof/src/main.rs` 593 LOC；PMU fail-fast 已做，但 nullable branch metrics 测试仍在：`bpfopt/crates/bpfprof/src/main.rs:1-6`、`bpfopt/crates/bpfprof/src/main.rs:330-353`、`bpfopt/crates/bpfprof/src/main.rs:471-492`。
   - `bpfrejit/src/main.rs` 569 LOC，包含 map/fd_array replay。
   - 建议先只抽共享 raw bytecode/map-fd/fd-array manifest helpers 到独立 lib module/crate，不要在 CLI crates 之间互相依赖。

6. `map_inline` 内部仍有多级 fallback key extraction。
   - verifier-guided miss 后 fallback backward scan，再 fallback pseudo-map-value：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1155-1220`。
   - 非 verifier path 也 fallback pseudo-map-value：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1228-1268`。
   - 这里可能是“多种合法分析策略”而不是错误降级；建议在设计上明确哪些 strategy 是同级支持，哪些是 fallback。若 verifier state 是必需 side-input，就不要静默退回旧扫描。

## ✅ 已经做对

1. daemon 基本不再内嵌 optimizer。
   - `daemon/Cargo.toml` 只依赖 `kernel-sys`，没有 `bpfopt` path dependency：`daemon/Cargo.toml:11-18`。
   - optimize 路径通过 subprocess 串联 `bpfget --full`、`bpfget --target`、`bpfverify`、`bpfopt optimize`、`bpfrejit`：`daemon/src/commands.rs:1216-1354`。
   - subprocess 失败大多会 bail：`daemon/src/commands.rs:2105-2139`。
   - `rg "PassManager"` 在 daemon 没有生产命中；`verifier_log_summary` 只是错误文本截断，不是 verifier state/parser 决策：`daemon/src/commands.rs:2172-2185`。

2. kernel syscall 边界基本干净。
   - 直接 `libc::syscall(SYS_bpf)` 只在 `kernel-sys`：`bpfopt/crates/kernel-sys/src/lib.rs:193-202`。
   - 该 direct syscall 用在 fork-only `BPF_PROG_REJIT`：`bpfopt/crates/kernel-sys/src/lib.rs:644`。
   - 标准 BPF 操作使用 libbpf-sys/libbpf-rs：`bpfopt/crates/kernel-sys/src/lib.rs:13-16`、`bpfopt/crates/kernel-sys/src/lib.rs:275-283`、`bpfopt/crates/kernel-sys/src/lib.rs:324-365`、`bpfopt/crates/kernel-sys/src/lib.rs:541-613`。

3. CLI crate cross-dependency 约束满足。
   - `bpfopt`、`bpfget`、`bpfrejit`、`bpfverify`、`bpfprof` 都只 path-depend `../kernel-sys`：`bpfopt/crates/bpfopt/Cargo.toml:11-16`、`bpfopt/crates/bpfget/Cargo.toml:11-16`、`bpfopt/crates/bpfrejit/Cargo.toml:11-16`、`bpfopt/crates/bpfverify/Cargo.toml:11-16`、`bpfopt/crates/bpfprof/Cargo.toml:11-18`。
   - `daemon` 只 path-depend `../bpfopt/crates/kernel-sys`：`daemon/Cargo.toml:14`。

4. `bpfopt` stdin/stdout raw `struct bpf_insn[]` 设计遵守得较好。
   - 输入从 `--input` 或 stdin 读 raw bytes：`bpfopt/crates/bpfopt/src/main.rs:825-840`。
   - 严格校验 8-byte multiple 并按 raw insn 解码：`bpfopt/crates/bpfopt/src/main.rs:842-852`。
   - 输出逐条写 `raw_bytes()` 到 file/stdout：`bpfopt/crates/bpfopt/src/main.rs:855-862`。
   - grep `goblin|ELF|elf_parser|from_elf|parse_elf` 在 `bpfopt/crates/bpfopt/src` 和 `bpfopt/Cargo.toml` 无残留。

5. `analysis/` module 不是单一调用方私货。
   - `BranchTargetAnalysis` 被 rotate/endian/bulk_memory/skb_load_bytes/map_inline/branch_flip/cond_select/bounds_check_merge 及 analyze 使用。
   - `CFGAnalysis` 被 dce/const_prop/utils/analyze 使用。
   - `LivenessAnalysis` 被 rotate/bulk_memory/wide_mem/bounds_check_merge/utils 使用。
   - `MapInfoAnalysis` 被 map_inline/analyze 使用。
   - production passes 之间没有直接互相 import；互通基本经 `analysis` 和 `passes/utils.rs`。

## Dead Public Surface

| Item | Location | grep/caller result | Recommendation |
| --- | --- | --- | --- |
| `disabled_passes` request field | `daemon/src/server.rs:448-462` | no real runner caller; tests only at `daemon/src/server.rs:957-982` | delete |
| `AttemptRecord.disabled_passes` | `daemon/src/commands.rs:696-700` | production always serializes empty vectors at `daemon/src/commands.rs:1382-1389` and `daemon/src/commands.rs:1473-1489` | delete result field and stale fixtures |
| `PolicyConfig.disabled_passes` | `bpfopt/crates/bpfopt/src/pass.rs:817-822` | only tests mutate it: `bpfopt/crates/bpfopt/src/pass_tests.rs:506` and `bpfopt/crates/bpfopt/src/pass_tests.rs:749` | delete |
| `passes::available_passes_help()` | `bpfopt/crates/bpfopt/src/passes/mod.rs:121-127` | no caller; daemon has its own `commands::available_passes_help` and shells out to `bpfopt list-passes` | delete |
| `passes::validate_pass_names()` | `bpfopt/crates/bpfopt/src/passes/mod.rs:153-155` | test-only caller `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:235` | make `#[cfg(test)]` or delete with low-value test |
| `passes::build_full_pipeline()` | `bpfopt/crates/bpfopt/src/passes/mod.rs:166-175` | test-only callers `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:194` and `:363` | make `#[cfg(test)]` or route CLI through it |
| `PassManager::pass_at()` | `bpfopt/crates/bpfopt/src/pass.rs:943-946` | no caller outside definition | delete |
| `PassManager::pass_allowed()` | `bpfopt/crates/bpfopt/src/pass.rs:948-952` | only internal calls at `bpfopt/crates/bpfopt/src/pass.rs:996` and `:1004` | make private |
| `PassManager::run_required_analyses()` | `bpfopt/crates/bpfopt/src/pass.rs:954-966` | only internal call at `bpfopt/crates/bpfopt/src/pass.rs:1082` | make private |
| `analysis` result reexports with `#[allow(unused_imports)]` | `bpfopt/crates/bpfopt/src/analysis/mod.rs:14-22` | explicitly allow unused; mostly tests/cache consumers | remove allow; make test imports concrete or `#[cfg(test)]` |
| `AnyAnalysis` / `AnalysisRegistry` | `bpfopt/crates/bpfopt/src/pass.rs:833-867` | implementation detail of `PassManager`, exported through public `pass` module | make private/crate-private |
| `CondSelectSite`, `CondSelectValue`, `CondSelectPass::analyze()` | `bpfopt/crates/bpfopt/src/passes/cond_select.rs:37-69` | production callers are same module; tests consume internals via module imports | make private or `pub(crate)` only if tests require |
| `Binding`, `RewriteSite`, `scan_wide_mem()` | `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:21-57` | production callers are same module; external callers are tests in `wide_mem_tests.rs` | make private/test-only public |
| `MapLookupSite`, `ConstantKey`, `FixedLoadUse`, `R0UseClassification`, `find_map_lookup_sites()` | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:33-111` | production callers are same module; external callers are tests in `map_inline_tests.rs` | make private/test-only public |
| `PassCategory` / `BpfPass::category()` | `bpfopt/crates/bpfopt/src/pass.rs:608-625` | already `#[cfg(test)]`; low bug-detection value unless category tests catch real policy bugs | consider deleting with tests |

## Duplicate Utility / Helper Notes

1. Hex formatting is duplicated.
   - `daemon/src/commands.rs:893-901`
   - `bpfopt/crates/bpfopt/src/pass.rs:301-309`
   - `bpfopt/crates/bpfopt/src/main.rs:1370-1378`
   - This is small, but the same map key/value hex convention now affects daemon, bpfopt CLI reports, and map snapshot errors. Prefer one helper in the bpfopt crate and keep daemon-local only if cross-crate sharing would create a bad dependency.

2. Branch target fixup logic is duplicated inside `passes/utils.rs`.
   - Generic branch/pseudo-call retargeting: `bpfopt/crates/bpfopt/src/passes/utils.rs:23-76`.
   - Surviving-branch retargeting repeats the same three cases: `bpfopt/crates/bpfopt/src/passes/utils.rs:343-394`.
   - Suggest extracting a shared “compute old target -> write new offset/imm” helper. This reduces verifier-sensitive drift.

3. `eliminate_dead_register_defs()` is DCE-only but lives in shared utils.
   - Function: `bpfopt/crates/bpfopt/src/passes/utils.rs:239`.
   - Production caller: only `bpfopt/crates/bpfopt/src/passes/dce.rs:55`; remaining callers are utils tests.
   - Not dead, but it is not shared utility. Move to `dce.rs` or a DCE-specific helper module if `utils.rs` is meant to contain multi-pass helpers only.

4. CLI raw bytecode/map FD manifest logic repeats across tools.
   - `bpfverify` has FD-array structs and raw bytecode decode: `bpfopt/crates/bpfverify/src/main.rs:17-22`、`bpfopt/crates/bpfverify/src/main.rs:119-149`、`bpfopt/crates/bpfverify/src/main.rs:286-310`。
   - `bpfrejit` repeats FD-array structs, map pseudo constants, and map-fd replay: `bpfopt/crates/bpfrejit/src/main.rs:15-20`、`bpfopt/crates/bpfrejit/src/main.rs:45-77`、`bpfopt/crates/bpfrejit/src/main.rs:250-300`。
   - Shared code should go to a neutral helper/lib crate or `kernel-sys` data-only module, not to one CLI crate imported by another.

## 建议立刻派 codex 修的优先级

1. 删除 `disabled_passes` 全链路：daemon request/result、`PolicyConfig`、tests、fixture/result reader stale fields。
2. 让 daemon watcher/status fail-fast：watcher BPF enumeration error 传播；`status` 的 `bpfopt list-passes` 失败返回 error。
3. 把 map-inline side-input 采集从 daemon 移到 `bpfget`/独立 CLI，daemon 只 fork+exec 并保留 invalidation polling。
4. 删除 `branch_flip` per-site profile 缺失时的 heuristic fallback。
5. 收缩 bpfopt public API：`passes/mod.rs` dead helpers、`PassManager` public methods、analysis result reexports、pass-private structs。
6. 合并 pass registry truth source，用 `PASS_REGISTRY` 驱动 default order 和 `list-passes`。
7. 后续整理 `commands.rs` 和 CLI `main.rs` 肥胖问题；这是维护性优先级，不是 correctness 优先级。

## 预估净删 LOC

保守估计 400-800 LOC。

- `disabled_passes` daemon/pass/test/fixture 清理：约 100-180 LOC。
- `passes/mod.rs` dead public helpers和低价值测试清理：约 120-220 LOC。
- `branch_flip` heuristic fallback 和相关测试/diagnostic：约 80-150 LOC。
- `PassManager`/analysis reexport public surface 收缩：净删约 20-80 LOC，更多是可见性修改。
- duplicate branch fixup/hex helper 收敛：约 40-100 LOC。
- `commands.rs` 拆文件主要是搬移，净删不一定多；若同时移走 map snapshot 到 CLI，daemon 侧可再少约 150-250 LOC。
