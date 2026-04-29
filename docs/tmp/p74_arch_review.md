# P74 daemon + bpfopt Architecture Review

日期：2026-04-29

范围：`daemon/src/`、`daemon/Cargo.toml`、`bpfopt/crates/`。本轮只做源码审计，没有改代码，没有跑 KVM/AWS，也没有跑 `cargo build/test`。

## 总评

架构干净度：7/10。

大的 v3 边界已经基本站住了：daemon 当前没有 in-process `PassManager`、pass code、profiling collector、`verifier_log` parser 或 bytecode transform；核心路径是 socket server + program watch + invalidation + CLI fork/exec。`bpfopt` 也已经是 raw `struct bpf_insn[]` stdin/stdout 的纯 bytecode CLI，ELF/goblin 残留为 0。跨 crate 依赖和 syscall 边界整体正确。

主要问题不是旧实现大面积残留，而是 v3 迁移后留下的架构边角：daemon 的裸 `optimize`/`optimize-all` socket 分支和当前 `bpfopt optimize` 默认 12-pass fail-fast 规则不兼容；daemon watch/status 还有 warning-and-continue/fallback；`commands.rs`、`bpfopt/src/main.rs`、`pass.rs` 仍是过大的职责集合；还有一批 `pub` API 只有测试 caller 或没有 caller。

## ❌ Critical

### 1. daemon 裸 `optimize` / `optimize-all` 请求路径和 bpfopt 默认 12-pass 不兼容

`daemon/README.md:41` 到 `daemon/README.md:45` 仍文档化裸请求：

```json
{"cmd":"optimize","prog_id":42}
```

但 daemon 对 `enabled_passes == None` 的处理会把 requested passes 变成空列表：`daemon/src/commands.rs:1245`。

side-input 准备全部挂在 `requested_passes` 上：

- target/kfunc: `daemon/src/commands.rs:1249`
- const-prop verifier states: `daemon/src/commands.rs:1277`
- map-inline values/map ids: `daemon/src/commands.rs:1306`
- branch-flip profile: `daemon/src/commands.rs:1329`

随后只有 requested passes 非空时才传 `--passes`：`daemon/src/commands.rs:1342` 到 `daemon/src/commands.rs:1344`。空列表会调用裸 `bpfopt optimize`。

当前 `bpfopt optimize` 的空 `--passes` 是 v3 默认 12-pass：`bpfopt/crates/bpfopt/src/main.rs:623` 到 `bpfopt/crates/bpfopt/src/main.rs:631`。它会先 fail-fast 校验 side-input：`bpfopt/crates/bpfopt/src/main.rs:633`，具体要求在 `bpfopt/crates/bpfopt/src/main.rs:722` 到 `bpfopt/crates/bpfopt/src/main.rs:746`：

- kinsn passes 需要 `--target` 或 `--kinsns`
- `branch-flip` 需要 `--profile`
- `const-prop` 需要 `--verifier-states`
- `map-inline` 需要 `--map-values` 和 `--map-ids`

所以裸 socket optimize 会启动一个注定缺 side-input 的 default optimize。`optimize-all` 有同样问题：`daemon/src/server.rs:561` 到 `daemon/src/server.rs:655` 对每个 program 透传 `enabled_passes.as_deref()`。

benchmark runner 路径目前大概率绕过了这个分支，因为它会传 effective enabled passes：`runner/libs/case_common.py:255` 到 `runner/libs/case_common.py:260`，以及 `runner/libs/rejit.py:927` 到 `runner/libs/rejit.py:932`。但 daemon 自己的 socket API 和 README 示例仍是破的。

建议：不要在 daemon 里偷偷缩默认 pass list。要么让 daemon 在缺 `enabled_passes` 时准备完整默认 12-pass 所需 side-input 并要求/加载 profile；要么在 fork 前明确拒绝裸请求，错误消息说明必须显式传 `enabled_passes` 或提供完整 default optimize 输入。

### 2. daemon program watcher 吞掉 BPF 枚举错误，继续用部分状态服务

`ProgramWatcher::from_live()` 在 BPF program 枚举失败时只打印错误然后 `break`：`daemon/src/server.rs:228` 到 `daemon/src/server.rs:241`。

`ProgramWatcher::tick()` 同样只打印错误然后 `break`：`daemon/src/server.rs:244` 到 `daemon/src/server.rs:257`。

这会让 daemon 在 watcher 初始化不完整或后续观察失败时继续服务。按 fail-fast/no silenced errors 规则，BPF syscall/IO 错误应该 propagate。这里建议把 `from_live()` / `tick()` 改成 `Result`，在 `cmd_serve()` 中用 `?` 退出，或者把 watcher 失败作为 socket 状态中的 hard error，而不是局部 warning。

### 3. `status` 在 `bpfopt list-passes` 失败时仍返回 `"status": "ok"`

`status` 分支把 `commands::available_passes_help(config)` 的错误降级成字符串 `"unavailable: ..."`：`daemon/src/server.rs:745` 到 `daemon/src/server.rs:752`，随后仍返回 ok：`daemon/src/server.rs:753` 到 `daemon/src/server.rs:760`。

这会掩盖 CLI 缺失、PATH 配错或权限错误。v3 daemon 是 socket-to-CLI adapter，CLI 不可用是硬故障，不应通过健康检查返回 ok。

### 4. `disabled_passes` 仍是可见过滤/排除 API

daemon socket 仍解析 `disabled_passes` 并从 enabled list 中扣掉对应 pass：`daemon/src/server.rs:448` 到 `daemon/src/server.rs:462`。相关测试只验证这个旧接口：`daemon/src/server.rs:957` 到 `daemon/src/server.rs:982`。

daemon result attempt 也仍序列化 `disabled_passes`：`daemon/src/commands.rs:582` 到 `daemon/src/commands.rs:600`、`daemon/src/commands.rs:696` 到 `daemon/src/commands.rs:700`，但生产路径目前全写空数组：`daemon/src/commands.rs:1382` 到 `daemon/src/commands.rs:1389`、`daemon/src/commands.rs:1473` 到 `daemon/src/commands.rs:1489`。

bpfopt pass policy 同样保留 disabled list，并会让 `PassManager` 跳过 pass：`bpfopt/crates/bpfopt/src/pass.rs:817` 到 `bpfopt/crates/bpfopt/src/pass.rs:822`、`bpfopt/crates/bpfopt/src/pass.rs:1122` 到 `bpfopt/crates/bpfopt/src/pass.rs:1134`。

这和 No ReJIT Filtering / no pass exclusion surface 冲突。建议删除 daemon request `disabled_passes`、`AttemptRecord.disabled_passes`、`PolicyConfig.disabled_passes` 和对应测试/fixture 字段。pass 选择只允许显式 `enabled_passes` / `--passes`，不能再有负向排除列表。

### 5. `branch_flip` 缺少 per-site branch profile 时仍会 heuristic fallback 变换

无 PMU 数据时 pass 整体不改，这是正确的：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:89` 到 `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:96`。

但单个 site 没有 `branch_profile` 时，如果 `heuristic_should_flip(site)` 为真，仍设置 `should_flip = true`：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:153` 到 `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:172`。diagnostics 也明确称为 fallback：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:191` 到 `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:196`。

这和“缺能力不能降级到别的逻辑”的约束冲突。建议 branch_flip 变成 per-site PGO-only：缺 site profile 就 skip/error，不做 heuristic transform。

## ⚠️ Minor

### 1. `daemon/src/commands.rs` 是 god module

`daemon/src/commands.rs` 当前 2991 LOC，职责包括：

- failure export/workdir: `daemon/src/commands.rs:22` 到 `daemon/src/commands.rs:466`
- profile session save/load: `daemon/src/commands.rs:516` 到 `daemon/src/commands.rs:548`、`daemon/src/commands.rs:1046` 到 `daemon/src/commands.rs:1134`
- response schema: `daemon/src/commands.rs:550` 到 `daemon/src/commands.rs:726`
- bpfopt/bpfget/bpfverify/bpfrejit JSON schema: `daemon/src/commands.rs:740` 到 `daemon/src/commands.rs:887`
- invalidation records/map snapshots: `daemon/src/commands.rs:889` 到 `daemon/src/commands.rs:1028`
- CLI orchestration and artifact handling: `daemon/src/commands.rs:1030` 到 `daemon/src/commands.rs:2185`

它没有承担 pass 逻辑，这一点是对的；但文件级职责已经过宽。建议后续拆成 `cli.rs`、`workdir.rs`、`failure_export.rs`、`profile.rs`、`map_snapshot.rs`、`response.rs` 等 crate-private modules。

### 2. daemon public surface 过大

daemon 是 binary crate，没有外部 crate consumer，但不少 helper 用了 `pub` 而不是 `pub(crate)` 或私有：

- `daemon/src/bpf.rs:13`、`daemon/src/bpf.rs:15`、`daemon/src/bpf.rs:21`、`daemon/src/bpf.rs:25`、`daemon/src/bpf.rs:53`、`daemon/src/bpf.rs:142`、`daemon/src/bpf.rs:174`
- `daemon/src/invalidation.rs:12`、`daemon/src/invalidation.rs:21`、`daemon/src/invalidation.rs:30`、`daemon/src/invalidation.rs:36`、`daemon/src/invalidation.rs:54`
- tracker methods `daemon/src/invalidation.rs:61`、`daemon/src/invalidation.rs:79`、`daemon/src/invalidation.rs:91`、`daemon/src/invalidation.rs:115`、`daemon/src/invalidation.rs:122`、`daemon/src/invalidation.rs:160`

其中 `TrackedInlineSite` 只需要模块内部构造；`BatchLookupValue`、`MapValueReader`、`BpfMapValueReader`、`MapInvalidationTracker` 最多需要 crate-level 可见性。

### 3. daemon response payload 保留了 v2/per-pass verify loop 遗留字段

daemon 已经不做 per-pass verify/rollback，但 response schema 仍暴露相关字段：

- `verifier_rejections`: `daemon/src/commands.rs:623` 到 `daemon/src/commands.rs:630`，实际固定写 0：`daemon/src/commands.rs:1524` 到 `daemon/src/commands.rs:1530`
- `PassVerifyStatus` 只有 `NotNeeded` / `Accepted`：`daemon/src/commands.rs:632` 到 `daemon/src/commands.rs:637`
- `PassRollbackResult`、`SkippedSiteDetail`: `daemon/src/commands.rs:662` 到 `daemon/src/commands.rs:672`
- `verify_error`、`rollback`、`skipped_sites` 在 `pass_detail_from_report()` 中固定 None/empty：`daemon/src/commands.rs:1690` 到 `daemon/src/commands.rs:1719`

同时 daemon 的 `BpfoptPassReport` 仍 deserialize `skipped`/`reason`：`daemon/src/commands.rs:790` 到 `daemon/src/commands.rs:796`，但当前 bpfopt report 不再输出这些字段：`bpfopt/crates/bpfopt/src/main.rs:200` 到 `bpfopt/crates/bpfopt/src/main.rs:210`。

这不是立即功能 bug，因为 serde default 让它保持兼容；但它是冗余 informational surface，和 no redundant informational fields/no dead code 规则冲突。建议先确认 runner 是否仍消费这些字段，再删或显式标为 legacy compatibility。

### 4. `bpfopt/src/main.rs` 不是 thin CLI wrapper

`bpfopt/crates/bpfopt/src/main.rs` 1589 LOC，除 clap dispatch 外还包含 pass alias、target/kfunc schema、verifier states schema、map-values schema、profile parsing、raw bytecode IO、analyze report、scan-map-keys provider、platform/prog type parsing等。

典型例子：

- pass/kfunc alias: `bpfopt/crates/bpfopt/src/main.rs:27` 到 `bpfopt/crates/bpfopt/src/main.rs:92`
- map-values schema: `bpfopt/crates/bpfopt/src/main.rs:336` 到 `bpfopt/crates/bpfopt/src/main.rs:366`
- optimize handler: `bpfopt/crates/bpfopt/src/main.rs:623` 到 `bpfopt/crates/bpfopt/src/main.rs:652`
- target/kfunc validation: `bpfopt/crates/bpfopt/src/main.rs:722` 到 `bpfopt/crates/bpfopt/src/main.rs:776`
- raw bytecode IO: `bpfopt/crates/bpfopt/src/main.rs:825` 到 `bpfopt/crates/bpfopt/src/main.rs:862`
- prog type parser: `bpfopt/crates/bpfopt/src/main.rs:958` 到 `bpfopt/crates/bpfopt/src/main.rs:1003`
- map-values parser: `bpfopt/crates/bpfopt/src/main.rs:1226` 到 `bpfopt/crates/bpfopt/src/main.rs:1271`

建议把 side-input schema/parser、raw bytecode IO、report generation、target/prog-type parsing拆到 lib 内部模块。`main.rs` 保持 command dispatch。

### 5. `pass.rs` 职责过多

`bpfopt/crates/bpfopt/src/pass.rs` 1214 LOC，同时承载：

- verifier state/profile/map snapshot data types: `bpfopt/crates/bpfopt/src/pass.rs:20` 到 `bpfopt/crates/bpfopt/src/pass.rs:203`
- map snapshot helpers: `bpfopt/crates/bpfopt/src/pass.rs:277` 到 `bpfopt/crates/bpfopt/src/pass.rs:309`
- `BpfProgram`: `bpfopt/crates/bpfopt/src/pass.rs:313` 到 `bpfopt/crates/bpfopt/src/pass.rs:429`
- analysis cache framework: `bpfopt/crates/bpfopt/src/pass.rs:464` 到 `bpfopt/crates/bpfopt/src/pass.rs:524`
- pass result/trait/context/kfunc registry: `bpfopt/crates/bpfopt/src/pass.rs:533` 到 `bpfopt/crates/bpfopt/src/pass.rs:823`
- `PassManager`: `bpfopt/crates/bpfopt/src/pass.rs:867` 到 `bpfopt/crates/bpfopt/src/pass.rs:1116`

建议拆 `program.rs`、`analysis_cache.rs`、`manager.rs`、`context.rs`、`verifier_state.rs`、`map_snapshot.rs`。这主要是降低 cognitive load，不一定带来大量 LOC 删除。

### 6. `PassManager` 对 `const_prop + dce` 做固定点循环，不是严格“一次链式 pipeline”

`PassManager::run()` 遇到相邻 `const_prop` + `dce` 会循环最多 `CONST_PROP_DCE_FIXED_POINT_MAX_ITERS`：`bpfopt/crates/bpfopt/src/pass.rs:1001` 到 `bpfopt/crates/bpfopt/src/pass.rs:1036`。

这可能是合理优化策略，但 v3 文档强调 CLI/脚本 pipeline 的可组合性。当前行为会让 `bpfopt optimize --passes const-prop,dce` 不等价于 shell 上各跑一次 `bpfopt const-prop | bpfopt dce`。建议要么文档化这个语义，要么把固定点循环上移到脚本层，保持 CLI pipeline 更透明。

### 7. `passes/utils.rs` 共享 utility 和 ad hoc analysis 混在一起

`passes/utils.rs` 有真正共享的 branch fixup/kfunc emission helper，但也会直接重跑 analysis，绕过 `PassManager` 的 cache：

- 直接跑 CFG：`bpfopt/crates/bpfopt/src/passes/utils.rs:106` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:113`
- 直接跑 liveness：`bpfopt/crates/bpfopt/src/passes/utils.rs:258` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:260`
- `PassManager` 的 cache 生命周期在 `bpfopt/crates/bpfopt/src/pass.rs:987` 到 `bpfopt/crates/bpfopt/src/pass.rs:1040`

这些 helper 被多个 pass 复用，所以不是单一 pass 私货；但“utility + analysis runner”混在一起会让分析依赖不集中。建议把 rewrite utilities 和 analysis-backed cleanup utilities 分开，或让 cleanup 接收 caller-provided analysis result。

### 8. bpfget/bpfrejit/bpfverify/bpfprof 不是完全 thin CLI wrapper

这四个 binary crate 没有互相依赖，边界是正确的；但 `main.rs` 内部仍放了较多 reusable lib 逻辑：

- `bpfget/src/main.rs` 1071 LOC；metadata validation/prog type naming/target probing在 `bpfopt/crates/bpfget/src/main.rs:262` 到 `bpfopt/crates/bpfget/src/main.rs:315`，BTF/kfunc probing在 `bpfopt/crates/bpfget/src/main.rs:395` 到 `bpfopt/crates/bpfget/src/main.rs:496`，prog/map info读写在 `bpfopt/crates/bpfget/src/main.rs:597` 到 `bpfopt/crates/bpfget/src/main.rs:855`
- `bpfverify/src/main.rs` 957 LOC；map fd/fd_array handling在 `bpfopt/crates/bpfverify/src/main.rs:312` 到 `bpfopt/crates/bpfverify/src/main.rs:551`，prog/attach type解析在 `bpfopt/crates/bpfverify/src/main.rs:681` 到 `bpfopt/crates/bpfverify/src/main.rs:848`
- `bpfrejit/src/main.rs` 569 LOC；map fd/fd_array handling在 `bpfopt/crates/bpfrejit/src/main.rs:250` 到 `bpfopt/crates/bpfrejit/src/main.rs:493`
- `bpfprof/src/main.rs` 593 LOC；profile collection/write逻辑在 `bpfopt/crates/bpfprof/src/main.rs:139` 到 `bpfopt/crates/bpfprof/src/main.rs:295`

建议不要建立 CLI crate 之间的依赖；如果要收敛重复逻辑，应新建 shared library crate，或放到 `kernel-sys` 中只处理 syscall-adjacent ABI/schema。

### 9. 注释/文档有 v2 语义残留

- daemon crate 文档仍说“Scans live kernel BPF programs for optimization sites and can apply bytecode rewrites via BPF_PROG_REJIT”：`daemon/src/main.rs:4` 到 `daemon/src/main.rs:5`
- invalidation trait 注释说 production adapter “later”，但 `BpfMapValueReader` 已存在：`daemon/src/invalidation.rs:26` 到 `daemon/src/invalidation.rs:36`
- `daemon/Cargo.toml` description 仍偏 “scans and optimizes live kernel BPF programs”：`daemon/Cargo.toml:5`

建议改成 v3 plan B 的 socket-to-CLI adapter 描述。

### 10. map-inline 优化前 side-input 仍由 daemon 进程内采集

`optimize` 中直接调用 `write_live_map_values(...)` 生成 `map_values.json`：`daemon/src/commands.rs:1306` 到 `daemon/src/commands.rs:1320`。该函数会循环运行 `bpfopt scan-map-keys`，但 live map fd 打开和 value lookup 由 daemon 闭包完成：`daemon/src/commands.rs:1746` 到 `daemon/src/commands.rs:1808`。具体 map lookup 在 daemon adapter 里通过 `kernel_sys::bpf_map_lookup_elem` 进行：`daemon/src/bpf.rs:25` 到 `daemon/src/bpf.rs:50`。

map invalidation polling 属于 daemon 职责；但“优化前 map-values side-input 采集”更像 `bpfget`/独立 CLI 的 kernel-facing side-input 生成职责。建议后续迁到 CLI，daemon 只 fork/exec 并保留 invalidation watch。

## ✅ 已经做对

- daemon module 很窄：`daemon/src/main.rs:7` 到 `daemon/src/main.rs:10` 只有 `bpf`、`commands`、`invalidation`、`server`。
- daemon `Serve` 是唯一命令：`daemon/src/main.rs:22` 到 `daemon/src/main.rs:33`。
- daemon socket loop、watch、invalidation、client handling集中在 `cmd_serve()`：`daemon/src/server.rs:268` 到 `daemon/src/server.rs:364`。
- daemon 通过 CLI subprocess 组合 v3 工具：`bpfopt list-passes` 在 `daemon/src/commands.rs:1030`，`bpfget --list` 在 `daemon/src/commands.rs:1036`，`bpfprof` 在 `daemon/src/commands.rs:1046` 到 `daemon/src/commands.rs:1088`，`bpfget --full` 在 `daemon/src/commands.rs:1218` 到 `daemon/src/commands.rs:1226`，`bpfverify` 在 `daemon/src/commands.rs:1281` 到 `daemon/src/commands.rs:1299` 和 `daemon/src/commands.rs:1394` 到 `daemon/src/commands.rs:1420`，`bpfopt optimize` 在 `daemon/src/commands.rs:1339` 到 `daemon/src/commands.rs:1354`，`bpfrejit` 在 `daemon/src/commands.rs:1431` 到 `daemon/src/commands.rs:1460`。
- daemon 没有 `PassManager`、pass module import、daemon-local verifier parser。`daemon/src/commands.rs:2` 明确是 CLI subprocess helpers；源码 grep `PassManager`/`bpfopt::passes` 在 daemon 中为 0。
- daemon 不依赖 `bpfopt` lib，只依赖 `kernel-sys`：`daemon/Cargo.toml:11` 到 `daemon/Cargo.toml:18`。
- `bpfopt` raw bytecode I/O 符合 v3 §10：stdin/file 读 raw bytes 在 `bpfopt/crates/bpfopt/src/main.rs:825` 到 `bpfopt/crates/bpfopt/src/main.rs:840`，8-byte instruction decode 在 `bpfopt/crates/bpfopt/src/main.rs:842` 到 `bpfopt/crates/bpfopt/src/main.rs:853`，stdout/file 写 raw bytes 在 `bpfopt/crates/bpfopt/src/main.rs:855` 到 `bpfopt/crates/bpfopt/src/main.rs:862`。
- `bpfopt` ELF/goblin 残留为 0：`rg "elf_parser|goblin|from_elf|ELF|\\.bpf\\.o|bpftool" bpfopt/crates/bpfopt/src bpfopt/crates/bpfopt/Cargo.toml bpfopt/crates/bpfopt/tests` 无结果。
- default optimize pass order 是 v3 12-pass：`bpfopt/crates/bpfopt/src/main.rs:27` 到 `bpfopt/crates/bpfopt/src/main.rs:42`，registry 顺序在 `bpfopt/crates/bpfopt/src/passes/mod.rs:52` 到 `bpfopt/crates/bpfopt/src/passes/mod.rs:118`。
- CLI cross-dep 干净：`bpfopt/crates/bpfopt/Cargo.toml:11` 到 `bpfopt/crates/bpfopt/Cargo.toml:16`、`bpfopt/crates/bpfget/Cargo.toml:11` 到 `bpfopt/crates/bpfget/Cargo.toml:16`、`bpfopt/crates/bpfrejit/Cargo.toml:11` 到 `bpfopt/crates/bpfrejit/Cargo.toml:16`、`bpfopt/crates/bpfverify/Cargo.toml:11` 到 `bpfopt/crates/bpfverify/Cargo.toml:16`、`bpfopt/crates/bpfprof/Cargo.toml:11` 到 `bpfopt/crates/bpfprof/Cargo.toml:18` 都没有依赖其他 CLI crate。
- `kernel-sys` 是唯一 direct `SYS_bpf` 边界：direct syscall helper 在 `bpfopt/crates/kernel-sys/src/lib.rs:193` 到 `bpfopt/crates/kernel-sys/src/lib.rs:202`；standard commands 走 libbpf-sys wrapper，如 `bpf_prog_get_next_id` 在 `bpfopt/crates/kernel-sys/src/lib.rs:324` 到 `bpfopt/crates/kernel-sys/src/lib.rs:334`，`bpf_map_get_fd_by_id` 在 `bpfopt/crates/kernel-sys/src/lib.rs:588` 到 `bpfopt/crates/kernel-sys/src/lib.rs:594`，`bpf_enable_stats` 在 `bpfopt/crates/kernel-sys/src/lib.rs:608` 到 `bpfopt/crates/kernel-sys/src/lib.rs:612`。
- fork-only `BPF_PROG_REJIT` 仍用 custom syscall wrapper，符合规则：`bpfopt/crates/kernel-sys/src/lib.rs:644`、`bpfopt/crates/kernel-sys/src/lib.rs:665` 到 `bpfopt/crates/kernel-sys/src/lib.rs:724`。
- analysis modules 不是单一 caller：CFG/liveness 被 `passes/utils.rs` 复用：`bpfopt/crates/bpfopt/src/passes/utils.rs:106` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:113`、`bpfopt/crates/bpfopt/src/passes/utils.rs:258` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:260`；map-info 被 map-inline 使用：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:805`。

## Dead Code / Oversized Public Surface

grep 方法：对 `pub fn` / `pub struct` / `pub trait` / `pub enum` / `pub const` 做 name grep，区分 production caller、test-only caller 和 no caller。下面只列确认有问题或值得收窄的项。

### 确认 no production caller

- `daemon/src/server.rs:448` 到 `daemon/src/server.rs:462` `disabled_passes` request path。grep 结果：真实 runner 只传 `enabled_passes`，`disabled_passes` 输入路径只有 daemon tests 和旧结果字段。
- `daemon/src/commands.rs:696` 到 `daemon/src/commands.rs:700` `AttemptRecord.disabled_passes`。grep 结果：生产路径只写 `Vec::new()`；旧 runner artifact reader 只汇总 `final_disabled_passes`，不是请求方。
- `bpfopt/crates/bpfopt/src/pass.rs:817` 到 `bpfopt/crates/bpfopt/src/pass.rs:822` `PolicyConfig.disabled_passes`。grep 结果：只有 tests 直接赋值，生产 CLI 没有负向 pass policy。
- `bpfopt/crates/bpfopt/src/passes/mod.rs:121` `pub fn available_passes_help() -> String`。grep 结果：bpfopt crate 内只有定义；daemon 有自己的 `commands::available_passes_help` shell out：`daemon/src/commands.rs:1030`。
- `bpfopt/crates/bpfopt/src/passes/mod.rs:153` `pub fn validate_pass_names(...)`。grep 结果：只有测试 `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:235`。
- `bpfopt/crates/bpfopt/src/passes/mod.rs:166` `pub fn build_full_pipeline() -> PassManager`。grep 结果：只有测试 `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:194` 和 `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:363`。production CLI 自己按 registry build：`bpfopt/crates/bpfopt/src/main.rs:675` 到 `bpfopt/crates/bpfopt/src/main.rs:687`。
- `bpfopt/crates/bpfopt/src/pass.rs:718` `KinsnRegistry::call_off_for_pass(...)`。grep 结果：只有 `bpfopt/crates/bpfopt/src/pass_tests.rs:590` 到 `bpfopt/crates/bpfopt/src/pass_tests.rs:592`；production 走 trait method `KinsnCallResolver::call_off_for_pass`：`bpfopt/crates/bpfopt/src/pass.rs:761` 到 `bpfopt/crates/bpfopt/src/pass.rs:765`，调用点在 `bpfopt/crates/bpfopt/src/passes/utils.rs:420` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:422`。
- `bpfopt/crates/bpfopt/src/pass.rs:943` `PassManager::pass_at(...)`。grep 结果：只有定义，没有 caller。
- `bpfopt/crates/bpfopt/src/insn.rs:29` `pub const BPF_MEMSX`。grep 结果：只有定义，没有 caller。
- `bpfopt/crates/bpfopt/src/insn.rs:188` `BpfInsn::from_kernel(...)`。grep 结果：只有定义，没有 caller。
- `bpfopt/crates/bpfopt/src/insn.rs:198` `BpfInsn::as_kernel_mut(...)`。grep 结果：只有定义，没有 caller。
- `bpfopt/crates/bpfopt/src/insn.rs:203` `BpfInsn::into_kernel(...)`。grep 结果：只有定义，没有 caller。
- `bpfopt/crates/bpfopt/src/insn.rs:223` `BpfInsn::set_regs(...)`。grep 结果：只有定义，没有 caller。
- `bpfopt/crates/bpfopt/src/insn.rs:249` `BpfInsn::off()` 和 `bpfopt/crates/bpfopt/src/insn.rs:259` `BpfInsn::imm()`。grep `.off()` / `.imm()` 结果：没有 caller；代码直接通过 deref 访问 `off` / `imm` 字段。

### 过宽但有内部 caller

- `bpfopt/crates/bpfopt/src/lib.rs:8` 到 `bpfopt/crates/bpfopt/src/lib.rs:17` 把 `analysis`、`insn`、`pass`、`passes` 全部公开。文件注释说 workspace-internal/not published：`bpfopt/crates/bpfopt/src/lib.rs:4` 到 `bpfopt/crates/bpfopt/src/lib.rs:6`，所以这里可以更窄地 re-export bin/test 真正需要的 API。
- `bpfopt/crates/bpfopt/src/analysis/mod.rs:15` 到 `bpfopt/crates/bpfopt/src/analysis/mod.rs:22` 对 result type re-export 加了 `#[allow(unused_imports)]`。这些类型当前有实际使用，但 allow 本身是 surface smell；建议删除 allow 后按真实 caller 调整 export。
- `bpfopt/crates/bpfopt/src/pass.rs:948` 到 `bpfopt/crates/bpfopt/src/pass.rs:966` 的 `PassManager::pass_allowed()` 和 `PassManager::run_required_analyses()` 只有 `PassManager` 内部调用：`bpfopt/crates/bpfopt/src/pass.rs:996`、`bpfopt/crates/bpfopt/src/pass.rs:1004`、`bpfopt/crates/bpfopt/src/pass.rs:1082`。应改私有。
- daemon internal `pub` 见上文 Minor 2。它们不是 dead，但在 binary crate 内不该是 public API。

## 重复 Utility / Helper

- hex 编码重复：`daemon/src/commands.rs:893` 到 `daemon/src/commands.rs:901`，`bpfopt/crates/bpfopt/src/pass.rs:301` 到 `bpfopt/crates/bpfopt/src/pass.rs:309`。另有 decode 在 `daemon/src/commands.rs:903` 到 `daemon/src/commands.rs:923` 和 `bpfopt/crates/bpfopt/src/main.rs:1298` 到 `bpfopt/crates/bpfopt/src/main.rs:1314`。
- pass alias/canonicalization 重复：`bpfopt/crates/bpfopt/src/main.rs:44` 到 `bpfopt/crates/bpfopt/src/main.rs:69`，`bpfopt/crates/bpfopt/src/main.rs:704` 到 `bpfopt/crates/bpfopt/src/main.rs:720`，daemon 版在 `daemon/src/commands.rs:2022` 到 `daemon/src/commands.rs:2041`。
- kinsn/target requirement mapping 重复：bpfopt 在 `bpfopt/crates/bpfopt/src/main.rs:71` 到 `bpfopt/crates/bpfopt/src/main.rs:92` 和 `bpfopt/crates/bpfopt/src/main.rs:754` 到 `bpfopt/crates/bpfopt/src/main.rs:776`；daemon 在 `daemon/src/commands.rs:1883` 到 `daemon/src/commands.rs:2014`。
- map-values JSON schema 生产/消费重复：daemon writer 在 `daemon/src/commands.rs:833` 到 `daemon/src/commands.rs:853`；bpfopt reader 在 `bpfopt/crates/bpfopt/src/main.rs:336` 到 `bpfopt/crates/bpfopt/src/main.rs:366`。
- `map_fds` / `fd_array` handling 在 bpfverify 和 bpfrejit 重复：`bpfopt/crates/bpfverify/src/main.rs:312` 到 `bpfopt/crates/bpfverify/src/main.rs:551`，`bpfopt/crates/bpfrejit/src/main.rs:250` 到 `bpfopt/crates/bpfrejit/src/main.rs:493`。
- prog type / attach type metadata规则重复：bpfget validates live metadata at `bpfopt/crates/bpfget/src/main.rs:262` 到 `bpfopt/crates/bpfget/src/main.rs:315`；bpfverify validates replay metadata at `bpfopt/crates/bpfverify/src/main.rs:787` 到 `bpfopt/crates/bpfverify/src/main.rs:848`；bpfopt has its own `parse_prog_type` at `bpfopt/crates/bpfopt/src/main.rs:958` 到 `bpfopt/crates/bpfopt/src/main.rs:1003`。
- branch fixup 逻辑在 `passes/utils.rs` 内部重复：通用 `fixup_all_branches()` 是 `bpfopt/crates/bpfopt/src/passes/utils.rs:23` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:76`，`fixup_surviving_branches()` 又重复处理 pseudo-func、pseudo-call、jmp 三类 target：`bpfopt/crates/bpfopt/src/passes/utils.rs:343` 到 `bpfopt/crates/bpfopt/src/passes/utils.rs:394`。
- `eliminate_dead_register_defs()` 目前只有 DCE production caller：`bpfopt/crates/bpfopt/src/passes/utils.rs:239`，调用点是 `bpfopt/crates/bpfopt/src/passes/dce.rs:55`。它不是 dead code，但不是 shared utility；可以搬到 DCE 私有 helper。

## 建议立刻派 Codex 修的优先级

1. 修 daemon 裸 `optimize`/`optimize-all` 分支。最小安全修法是 fork 前拒绝缺 `enabled_passes` 的请求并更新 README/test；完整修法是准备 default 12-pass 所需 side-input，并对 `branch-flip` 明确要求 profile。
2. 修 daemon watcher/status 的 fallback。`ProgramWatcher::from_live()` / `tick()` 返回 `Result` 并 propagate；`status` 对 `bpfopt list-passes` 失败返回 error JSON。
3. 删除 `disabled_passes` 全链路：daemon request/result、`PolicyConfig`、tests、fixture/result reader stale fields。
4. 删除 `branch_flip` per-site profile 缺失时的 heuristic fallback。
5. 删或收窄确认 dead public APIs：`available_passes_help`、`validate_pass_names`、`build_full_pipeline`、`PassManager::pass_at`、`KinsnRegistry::call_off_for_pass`、未用的 `BpfInsn` constructors/accessors、`BPF_MEMSX`。
6. 收窄 daemon `pub` 为 `pub(crate)`/private，并清掉 stale doc comments。
7. 把 map-inline 优化前 side-input 采集从 daemon 移到 `bpfget`/独立 CLI，daemon 只 fork+exec 并保留 invalidation polling。
8. 清理 daemon response legacy fields；如果 runner 仍依赖旧字段，先写 compatibility 注释并限制字段范围。
9. 拆 `daemon/src/commands.rs`、`bpfopt/src/main.rs`、`pass.rs`。这是结构债，不建议和 critical bug 混在同一个 patch。

## LOC 净删预估

- 只做 critical 修复：约 -20 到 +80 LOC，取决于选择“拒绝裸请求”还是“完整准备 default side-input”。
- dead public API + stale comments + daemon pub 收窄：约 -80 到 -180 LOC。
- response legacy fields 清理：约 -150 到 -300 LOC。
- utility/schema consolidation：约 -150 到 -350 LOC，前提是新 shared module 不引入过多 glue。
- 大文件拆分主要改善结构，净删可能很少。

综合估计：如果按本报告建议清理，保守还能净删约 400 到 800 LOC；若连 `bpfverify`/`bpfrejit` 的 fd_array/map_fds 重复逻辑一起抽 shared crate，净删可能接近 1000 LOC。
