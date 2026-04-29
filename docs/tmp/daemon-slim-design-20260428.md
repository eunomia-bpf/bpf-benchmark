# daemon 瘦身设计调研

日期：2026-04-28

范围：只读调研 `daemon/src/*.rs`、`daemon/Cargo.toml`、`docs/tmp/bpfopt_design_v3.md` 相关章节和 runner 当前 daemon 调用路径。本文只新增调研报告，不修改实现代码，不修改 v3 设计文档。

## 结论

当前 `daemon/src/*.rs` 合计 8151 行，不是一个小 daemon。它现在是 live-kernel orchestration 层：Unix socket server 接收 runner 请求，枚举 live BPF program，读取原始 bytecode，调用 `bpfopt` 的 `PassManager`，做 per-pass `BPF_PROG_LOAD` verify，最终 `BPF_PROG_REJIT`，同时还内置 profiling、kfunc discovery、map invalidation 和大量 raw BPF syscall wrapper。

v3 目标下，daemon 应缩成事件源和脚本触发器：

- watch 新 BPF program，然后调用 `on_new_prog_script`
- 轮询 map inline hints 对应的 map values，变化时调用 `on_invalidation_script`
- 可选保留只读 status socket

删除重点是：daemon 不再依赖 `bpfopt::{pass, passes, verifier_log}`，不再维护 `DaemonContext`、`FdArrayKinsnCallResolver`、`PassManager` 包装层，不再有 profiler 线程，不再做 kfunc discovery，不再解析 verifier log，不再处理 socket `optimize` / `optimize-all` / `profile-*` 命令。

runner 迁移顺序必须是先 #44，再 #45：当前 runner 仍启动 `bpfrejit-daemon serve --socket ...` 并发送 `optimize`、`profile-start`、`profile-stop` JSON 请求；如果先删 socket optimize 协议，corpus/e2e 会直接断。

## 当前 daemon 解剖

### 文件清单

| 文件 | 行数 | 当前功能 | 瘦身处理 |
|---|---:|---|---|
| `daemon/src/bpf.rs` | 1773 | 自写 raw `bpf(2)` syscall wrappers；program/map/BTF/link 枚举；`BPF_OBJ_GET_INFO_BY_FD`；map lookup；map FD relocation；`BPF_PROG_LOAD` dry-run verify；`BPF_PROG_REJIT`；`iter_prog_ids()` | 删除或重写为极薄适配。最终 daemon 不应直接做 syscall，应通过 `kernel-sys`；只需要 program 枚举、program info、map lookup/map fd 等 watch/invalidation 最小 API |
| `daemon/src/bpf_tests.rs` | 782 | `bpf.rs` ABI/layout、enum 常量、relocation、name parsing 回归测试 | 随 `bpf.rs` 删除大部分；对应 ABI/layout 测试迁到 `kernel-sys` |
| `daemon/src/commands.rs` | 963 | socket `optimize` 的核心：response schema、live map provider、map inline records、verifier log parse、PassManager pipeline、per-pass verify、final REJIT、debug payload | 删除。少量 map-inline hint 记录思路可重写到 invalidation hints loader；优化逻辑交给外部脚本/CLI |
| `daemon/src/commands_tests.rs` | 640 | optimize response serialization、pass detail、map inline record tracking、verifier log parse、pipeline smoke | 删除 optimize/profile/pass/verifier 相关测试；保留思路迁为 invalidation hint loader 测试 |
| `daemon/src/invalidation.rs` | 368 | `MapInvalidationTracker`：记录 `(prog_id, map_fd, key, expected_value)`，轮询 map value，变化或缺失则返回 affected prog ids | 保留核心算法，重写输入源。从 daemon 内部 pass result 改成读取 `invalidation-hints.json` |
| `daemon/src/kfunc_discovery.rs` | 872 | 扫 `/sys/kernel/btf/vmlinux` 和 module BTF，发现 kinsn stub func BTF ID，保活 BTF fd | 删除出 daemon。迁到 `bpfget --target` / target.json 生成路径 |
| `daemon/src/main.rs` | 72 | 只支持 `serve --socket`；启动时做 kfunc discovery、platform detect、构造 `PassContext` 和 `DaemonContext` | 重写为 slim daemon CLI：config flags、watch loop、script runner、可选 status socket |
| `daemon/src/pipeline.rs` | 546 | daemon-owned PassManager wrappers：fd_array kinsn resolver、per-pass verifier、rollback、debug trace | 删除。per-pass verify loop 属于外部脚本/CLI，不在 daemon 内 |
| `daemon/src/platform_detect.rs` | 48 | 解析 `/proc/cpuinfo`，给 pass policy 填 CPU capabilities | 删除出 daemon。target discovery 属于 `bpfget --target` |
| `daemon/src/profiler.rs` | 969 | PGO snapshot、background profiler thread、BPF run stats、PMU branch counters、hotness ranking | 删除出 daemon。核心采样逻辑迁到 `bpfprof` CLI |
| `daemon/src/server.rs` | 1118 | Unix socket server；每秒 invalidation tick；处理 `optimize`、`optimize-all`、`profile-start/stop/save/load`、`status` | 大幅重写或删除。推荐 benchmark 不使用 socket；若保留，只做 status/event 订阅，不做 optimize pipeline |
| `daemon/Cargo.toml` | 22 | 当前依赖 `bpfopt`、`clap`、`goblin`、`libc`、`serde`、`serde_json` 等 | 移除 `bpfopt` 和 `goblin`；保留 `clap`、`serde_json` 仅用于 config/status/hints；BPF 访问走 `kernel-sys` |

### 当前依赖关系

当前 `daemon/Cargo.toml` 直接依赖 `bpfopt = { path = "../bpfopt/crates/bpfopt" }`。`daemon/src/commands.rs` 导入 `bpfopt::{analysis, insn, pass, passes, verifier_log}`，`daemon/src/server.rs` 导入 `bpfopt::{pass, passes}`，`daemon/src/pipeline.rs` 以 `pass::PassManager` 为参数。也就是说，当前 PassManager 不在 `daemon/src/pass.rs`，而是在 `bpfopt/crates/bpfopt/src/pass.rs`；daemon 仍在运行它。

这正是 v3 §8 要删除的 compile-time/runtime coupling。Task #45 的目标应包括移除 daemon 对 `bpfopt` library 的依赖，让 pass 组合只发生在外部 CLI/script。

## 保留功能：watch 新程序

### 当前实现状态

当前 daemon 没有一个持续运行的“new program watcher”。

已有的 program 枚举路径是按需使用 `BPF_PROG_GET_NEXT_ID`：

- `daemon/src/bpf.rs` 定义 `bpf_prog_get_next_id(start_id)`，`ProgIdIter` 和 `iter_prog_ids()`。
- `daemon/src/server.rs` 的 `collect_live_program_candidates()` 在 socket `optimize-all` 请求中枚举所有 live programs。
- `daemon/src/profiler.rs` 的 `read_all_prog_stats()` 在 profiler session 中按 interval 枚举所有 live programs。

`server::cmd_serve()` 主循环只做两件事：

- 每 1 秒运行一次 invalidation tick。
- `UnixListener` nonblocking accept；没有 client 时 sleep 100ms。

因此，v3 的 “Watch 新程序加载” 需要新增实现，而不是保留现有 server 逻辑原样。

### 机制选择

应使用轮询 `BPF_PROG_GET_NEXT_ID`，不是 inotify。

理由：

- BPF program load 本身没有通用文件系统事件。bpffs pin/unpin 只覆盖被 pin 的对象，不覆盖普通 app startup 产生的 live program。
- 现有代码已经有 program ID 枚举模型，v3 §8 也明确写的是轮询 `BPF_PROG_GET_NEXT_ID`。
- 每 tick 成本是 O(number of live programs) 个 get-next-id syscall；只在发现新 ID 时再读取 program info 或触发脚本。以 1s 默认间隔看，成本比当前 PassManager/verify/rejit 低很多。

建议 slim watcher 行为：

1. daemon 启动时枚举一次当前 IDs，作为 `seen` baseline。
2. 每 `--watch-interval-ms` 重新枚举 IDs。
3. 对 `seen` 中不存在的新 `prog_id` 调 `on_new_prog_script prog_id`。
4. 对卸载的 IDs 从 `seen` 删除，同时清掉该 prog 的 invalidation entries。
5. 脚本非 0 exit code 记录 stderr/stdout 摘要到 daemon log，但 daemon 不吞掉该 event，也不把失败变成 metadata 字段。

默认间隔建议 1000ms。需要更低延迟时可设 100ms，但要避免默认高频扫所有 BPF programs。

## 保留功能：map invalidation 检测

### 当前实现位置和算法

核心在 `daemon/src/invalidation.rs`。

数据模型：

- `TrackedInlineSite { prog_id, map_fd, key, expected_value }`
- `MapInvalidationTracker<A> { map_reader, entries, owned_map_fds }`
- production reader 是 `BpfMapValueReader`

检查过程：

1. 将 entries 按 `map_fd` 分组，并对同一 map 的 keys 去重。
2. 对每个 map/key 读取当前 value。
3. 对每个 tracked site 比较 `current_value == expected_value`。
4. 如果当前 value 不同，或者 key missing，返回对应 `prog_id`。

注意当前 `BatchLookupValue` 是逻辑批量接口；production reader 内部仍是逐 key 调 `BPF_MAP_LOOKUP_ELEM`，没有使用 kernel batch lookup syscall。当前 reader 每次还会先取 map info 计算 value size。复杂度约为每 tick O(unique maps + unique map keys + tracked sites)。

当前 wire-up 在 `daemon/src/commands.rs`：

- `map_inline` pass 的 `MapInlineRecord` 由 `collect_map_inline_records()` 收集。
- `record_map_inline_records()` 把 map_id 转成 owned map fd，保活 fd，并记录 key/value。
- final REJIT 成功后 `refresh_invalidation_tracking()` 更新 tracker。

当前触发在 `daemon/src/server.rs`：

- `cmd_serve()` 每 1 秒检查一次。
- invalidated prog 会直接调用 `commands::try_apply_one()`，也就是在 daemon 内部重新跑 PassManager 和 REJIT。

### 瘦身后设计

保留 `MapInvalidationTracker` 的核心比较算法，但重写数据入口和触发动作：

- 数据入口不再来自 daemon 内部 pass result，而是来自外部 pipeline 输出的 `invalidation-hints.json`。
- daemon 读取 hints 后打开 map_id 对应 fd，记录 `(prog_id, map_fd, key, expected_value)`。
- 检测到 invalidation 后不调用 `try_apply_one()`，只调用 `on_invalidation_script prog_id`。
- 脚本成功后 daemon 重新加载该 program 的 hints；脚本失败则记录错误，下一个 tick 仍会自然再次检测到该 invalidation。

建议 hints schema 最小化：

```json
{
  "programs": {
    "123": [
      {"map_id": 77, "key_hex": "01000000", "value_hex": "0b000000"}
    ]
  }
}
```

也可以按文件拆成 `hints-dir/<prog_id>.json`，避免多 script 并发更新同一文件。无论哪种，daemon 只消费 map_id/key/value/prog_id 这些必要字段，不增加 `limitations`、`workload_miss` 之类信息字段。

## 删除功能：PassManager / pipeline

当前 pipeline 分两层：

- `bpfopt::passes::build_full_pipeline()` 构造 PassManager。
- `daemon/src/pipeline.rs` 包装 `PassManager`，在每个 changed pass 后调用 verifier closure，失败就 rollback。

`daemon/src/commands.rs::try_apply_one()` 是核心调用点。它做：

1. open program fd。
2. 读取 `orig_prog_insns`。
3. 获取 map IDs 和 verifier states。
4. 构造 `pass::BpfProgram`，挂 live map provider。
5. `passes::build_full_pipeline()`。
6. apply mode 下跑 `pipeline::run_with_verifier()` 或 `run_with_profiling_and_verifier()`。
7. final changed 时 relocation map fd、build kinsn fd_array、调用 `BPF_PROG_REJIT`。

瘦身后这些都不属于 daemon。外部 pipeline 示例：

```bash
PROG_ID="$1"
bpfget "$PROG_ID" \
  | bpfopt optimize --target /etc/bpfopt/target.json --report "/run/bpfrejit/hints/$PROG_ID.json" \
  | bpfverify --prog-id "$PROG_ID" \
  | bpfrejit "$PROG_ID"
```

删除依赖迁移顺序：

1. runner 先切 CLI，不再要求 socket `optimize` 返回旧 schema。
2. 新增 slim daemon script runner 和 watcher。
3. 删除 `server.rs` 对 `commands::try_apply_one()` 的调用。
4. 删除 `commands.rs`。
5. 删除 `pipeline.rs`。
6. 删除 `main.rs` 里 `PassContext`、kfunc discovery、platform detect 初始化。
7. 从 `daemon/Cargo.toml` 移除 `bpfopt`。

## 删除功能：profiler

当前 `daemon/src/profiler.rs` 有两条 profiling 路径：

- `ProfilerSession` 后台线程：启动时读取所有 program 初始 run stats，按 interval 轮询，停止时输出 `ProfileSnapshot`。
- one-shot helpers：`collect_program_profiling()` 和 `collect_hotness_ranking()`。

`server.rs` 通过 `profile-start`、`profile-stop`、`profile-save`、`profile-load` 管理 `ProfilingState`，并在 `optimize` / `optimize-all` 时把 profile 转成 `pass::ProfilingData` 传给 `try_apply_one()`。

v3 下 daemon 不做 profiling，也不内部驱动 PGO。profile 数据如果要影响优化，应由外部脚本显式调用 `bpfprof` 并把 profile file 传给 `bpfopt`。例如：

```bash
bpfprof --prog-id "$PROG_ID" --duration 1s --output "/run/bpfrejit/profile/$PROG_ID.json"
bpfget "$PROG_ID" | bpfopt branch-flip --profile "/run/bpfrejit/profile/$PROG_ID.json" | bpfrejit "$PROG_ID"
```

因此 `profiler.rs` 和 socket `profile-*` 命令应整体删除。对应测试也删除或迁到 `bpfprof` CLI。

## 删除功能：kfunc discovery

当前 `daemon/src/main.rs` 启动时调用 `kfunc_discovery::discover_kinsns()`，并把 registry 和 BTF fds 塞进 `PassContext` / `DaemonContext`。`kfunc_discovery.rs` 自己解析 BTF blob、扫固定模块名和函数名，并通过 `bpf_btf_get_fd_by_module_name()` 获取 verifier 可用 BTF fd。

瘦身后 daemon 不运行 pass，也不组装 REJIT fd_array，所以不需要 kfunc discovery。目标位置是 `bpfget --target` 或 target.json 生成工具，供外部 `bpfopt` CLI 使用。

删除顺序：先保证外部 pipeline 能获取 target.json，再从 `main.rs` 删 discovery 初始化，最后删除 `kfunc_discovery.rs` 和 tests。

## 删除功能：verifier log 解析

当前 daemon 没有 `daemon/src/verifier_log.rs`，但 `commands.rs` 和 `pipeline.rs` 使用 `bpfopt::verifier_log`：

- 捕获原始程序 verifier states。
- per-pass `BPF_PROG_LOAD(log_level=2)` 后解析 states。
- final REJIT failure 时提取 failure PC。

这些逻辑属于 verifier CLI 或 pipeline script，不属于 slim daemon。Task #48 应把 verifier log parse/summary 输出放到 `bpfverify`，daemon 删除 `parse_verifier_states_from_log()` 和所有 `verifier_log` import。

## 删除功能：commands.rs socket optimize pipeline

当前 socket 命令：

- `optimize`
- `optimize-all`
- `profile-start`
- `profile-stop`
- `profile-save`
- `profile-load`
- `status`

当前 `status` 也返回 `available_passes_help()`，说明 socket 仍暴露 pass 层概念。

瘦身后有两个选择：

| 方案 | 行为 | 适用场景 | 建议 |
|---|---|---|---|
| A. 删除 socket | daemon 只 watch + trigger scripts，runner 直接调 CLI | benchmark/corpus/e2e | 推荐 |
| B. 保留 optional socket | 只支持 `status` 和可选 event stream；不支持 optimize/profile/pass flags | 长驻运维模式 | 可选 |

如果保留 socket，协议应大幅缩小：

```json
{"cmd": "status"}
```

返回只包含 daemon 健康状态、watch counters、tracked invalidation site count、last script failures 等运行状态。不要保留 `enabled_passes`、`disabled_passes`、`dry_run`、`profile-*`、`optimize-all`。

## 新设计：daemon 配置 flag 草案

建议 CLI 不再有 `serve` 子命令，直接运行：

```bash
bpfrejit-daemon \
  --on-new-prog /opt/bpfrejit/on-new-prog.sh \
  --on-invalidation /opt/bpfrejit/on-invalidation.sh \
  --invalidation-hints-dir /run/bpfrejit/invalidation-hints \
  --watch-interval-ms 1000 \
  --socket /var/run/bpfrejit.sock
```

Flags：

| flag | 默认 | 说明 |
|---|---|---|
| `--on-new-prog PATH` | unset | 发现新 `prog_id` 时执行。argv[1] 是 prog_id |
| `--on-invalidation PATH` | unset | map value invalidates 已 inline program 时执行。argv[1] 是 prog_id |
| `--invalidation-hints PATH` | unset | 单文件 hints JSON |
| `--invalidation-hints-dir PATH` | unset | 每 program 一个 hints JSON；推荐，便于脚本原子更新 |
| `--socket PATH` | unset | 可选 status socket；不设置则不创建 socket |
| `--watch-interval-ms MS` | 1000 | program watch 和 invalidation tick 的默认轮询间隔 |
| `--script-timeout-ms MS` | 300000 | 防止事件脚本永久占用 daemon |

脚本调用约定：

- new program：`on-new-prog "$PROG_ID"`
- invalidation：`on-invalidation "$PROG_ID"`
- env：
  - `BPFREJIT_EVENT=new_prog|map_invalidation`
  - `BPF_PROG_ID=<id>`
  - `BPF_PROG_NAME=<best effort name>`
  - `BPF_PROG_TYPE=<numeric type>`
  - `BPFREJIT_HINTS_DIR=<path>` 或 `BPFREJIT_HINTS=<path>`

不建议加入 `--filter`。它很容易变成 framework-level program exclusion，违反项目的 “No ReJIT Filtering” 规则。若后续确实需要降低事件噪音，只能作为只读 status/event display filter，不能影响哪些 program 会触发 ReJIT pipeline。

## 瘦身前后对比

| 维度 | 当前 daemon | slim daemon |
|---|---|---|
| 优化执行 | daemon 内部调用 `bpfopt` PassManager | 外部脚本/CLI 组合 |
| verifier loop | daemon 内 `pipeline.rs` per-pass verify + rollback | bash/script 或 `bpfverify` |
| final REJIT | daemon 内 `bpf.rs::bpf_prog_rejit()` | `bpfrejit` CLI |
| profiler | daemon 后台线程和 socket profile commands | `bpfprof` CLI |
| kfunc target | daemon 启动时 BTF discovery | `bpfget --target` |
| verifier log parse | daemon 调 `bpfopt::verifier_log` | `bpfverify` |
| map invalidation | daemon 内部 pass result 更新 tracker，内部 reoptimize | daemon 读 hints，触发 external script |
| new program watch | 当前没有持续 watcher，只有 on-demand 枚举 | `BPF_PROG_GET_NEXT_ID` 轮询 watcher |
| socket | optimize/profile/status control plane | 无 socket，或只读 status/event |
| syscall boundary | `daemon/src/bpf.rs` 自写 syscall | `kernel-sys` + libbpf-rs/libbpf-sys |
| compile dependency | daemon 依赖 `bpfopt` | daemon 不依赖优化 crate |

## 保留 / 删除 / 重写清单

保留但重写：

- `invalidation.rs` 的 tracker 比较算法。
- `server.rs` 中 signal handling、stale socket cleanup 的少量思路。
- `bpf.rs::iter_prog_ids()` 的枚举语义，但实现应迁到 `kernel-sys`。

删除：

- `commands.rs`
- `commands_tests.rs` 中 optimize/pass/verifier/profile tests
- `pipeline.rs`
- `profiler.rs`
- `kfunc_discovery.rs`
- `platform_detect.rs`
- `main.rs` 当前 PassContext/kfunc startup path
- `bpf.rs` 中 `BPF_PROG_LOAD` verify、`BPF_PROG_REJIT`、map relocation、BTF discovery helper、runtime images dump 等非 watcher/invalidation 内容

新增或重写：

- `main.rs`：config parse + event loop entry。
- `watch.rs`：program ID poller，seen set，新 ID event。
- `script.rs`：script invocation、timeout、stdout/stderr handling。
- `hints.rs`：load invalidation hints JSON，hex decode，map_id -> fd。
- `server.rs`：可选 status socket，或完全删除。

## 过渡策略

当前 `daemon/src/*.rs` 是 8151 行，瘦身后预计：

- 无 socket 版本：production Rust 约 450-700 行，tests 约 200-300 行。
- 保留 status socket：production Rust 约 650-1000 行，tests 约 250-400 行。

推荐分步删，每步保持 build 通过：

1. 完成 #44：runner 改为直接调用 CLI pipeline，不再依赖 daemon socket `optimize` / `profile-*`。
2. 在 daemon 中新增 slim watch/script/hints path，但先不删旧 `serve`。
3. 给 slim path 加 focused tests：new ID 只触发一次、removed ID 清理、script nonzero/timeout、hints reload、map value changed/missing invalidates。
4. runner 默认切到 CLI 后，删除 socket optimize/profile command 入口。
5. 删除 `commands.rs` 和 `pipeline.rs`，移除 daemon 对 `bpfopt` 的依赖。
6. 删除 `profiler.rs`，确认 `bpfprof` CLI 覆盖 profile 需求。
7. 删除 `kfunc_discovery.rs` 和 `platform_detect.rs`，确认 `bpfget --target` 可用。
8. 用 `kernel-sys` 替换 daemon 最小 BPF access，删除或缩空 `bpf.rs`。
9. 清理 Docker/build tracking：`DAEMON_SOURCE_FILES` 不再因 `bpfopt` pass code 变化而重建 daemon；benchmark image 改构建 CLI artifacts。

不建议一口气新写一个完全替换版然后一次性删除旧 daemon。风险点在 runner socket coupling 和 invalidation hints 数据边界，分步落地更容易定位 breakage。

## 与 #44 的协调

当前 runner 明确依赖 daemon socket：

- `runner/libs/rejit.py` 启动 `[daemon_binary, "serve", "--socket", socket_path]`。
- `apply_daemon_rejit()` 对每个 prog_id 发 `{"cmd":"optimize","prog_id":...}`。
- 启用 `branch_flip` 时还会发 `profile-start`、sleep、`profile-stop`。
- e2e/corpus/test suite 都解析 daemon binary path，并把 daemon session 传入生命周期 runner。

所以 #44 必须先完成：

1. runner 用 `bpfget | bpfopt | bpfverify | bpfrejit` 替代 socket `optimize`。
2. branch_flip profile 改成 `bpfprof` 文件输入，不再用 daemon `profile-start/stop`。
3. result parser 从 daemon response schema 切到 CLI reports。
4. container/runtime image 先包含这些 CLI binaries。
5. 确认 `make vm-corpus`、`make vm-e2e` 不需要 daemon socket。

之后 #45 才能删除 socket optimize 协议。否则 runner 会在 daemon 启动等待 socket、socket request、旧 response schema validation 三处 break。

## 测试调整

当前 daemon test 数量按 `#[test]` 粗略统计：

| 文件 | test 数 |
|---|---:|
| `bpf_tests.rs` | 17 |
| `commands_tests.rs` | 13 |
| `invalidation.rs` | 8 |
| `kfunc_discovery.rs` | 10 |
| `pipeline.rs` | 2 |
| `profiler.rs` | 6 |
| `server.rs` | 13 |

瘦身后删除的测试类别：

- optimize response schema。
- pass detail / verifier rejection / rollback。
- `build_full_pipeline()` smoke。
- verifier log parser。
- profile snapshot save/load 和 profile socket commands。
- kfunc BTF discovery tests，迁到 `bpfget --target`。
- raw BPF ABI/layout tests，迁到 `kernel-sys`。

瘦身后保留/新增的测试类别：

- `MapInvalidationTracker`：unchanged、changed、missing key、多 map 去重、remove prog、duplicate key update。
- hints loader：hex decode、unknown/malformed JSON fail-fast、reload replaces old prog entries、open map failure keeps old entries or fails atomically。
- watcher：startup baseline 不触发、new ID 触发一次、ID unload 后清理、enumeration error surfaces。
- script trigger：argv/env 正确、nonzero exit reported、timeout kills child、stdout/stderr captured to log path or error summary。
- optional socket：`status` only；unknown command fail-close；no optimize/profile commands accepted。

这些测试都有明确 bug-detection purpose；不要为 trivial getters/setters 或纯 mock 行为补无效测试。

## 风险和注意事项

1. invalidation hints 生命周期是新边界。当前 daemon 从 pass result 内存直接拿 `MapInlineRecord`，瘦身后必须定义外部脚本如何原子写 hints，以及 daemon 何时 reload。
2. script 并发需要保守。第一版建议单线程同步执行，避免同一 prog 的 new_prog 和 invalidation reoptimize 并发冲突。后续再引入 per-prog queue。
3. daemon 不能实现 program/type filter。过滤会违反 No ReJIT Filtering；所有实际是否优化的策略应由统一 pipeline 脚本和 CLI error 自然体现。
4. 当前 `bpf.rs` 自写 syscall 与项目 “kernel-sys is the only syscall boundary” 目标不一致。Task #45 是清掉这层的好时机。
5. 如果 optional socket 继续存在，协议必须与旧 optimize socket 明确断开，避免 runner 半迁移时误以为还能用旧 schema。
