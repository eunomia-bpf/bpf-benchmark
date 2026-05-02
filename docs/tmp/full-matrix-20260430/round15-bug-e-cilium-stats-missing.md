# Round 15 Bug E: cilium/agent BPF stats missing requested program IDs

## 结论

这次错误的直接来源不是 daemon，而是 corpus runner 在 post-ReJIT measurement 里继续用 ReJIT 前保存的 cilium program ID 列表去读取 BPF stats。`sample_bpf_stats()` 用 `bpftool prog show` 的当前内核 program 表做精确匹配；如果请求的 ID 已经不在当前表里，就 fail-fast 抛出 `BPF stats missing requested program IDs: ...`。

从代码看，最可能的根因是：cilium-agent 在 ReJIT 期间或 post-ReJIT warmup workload 期间重新加载/替换了部分 BPF programs，导致旧 ID 被卸载，新 ID 出现在内核中；runner 没有在 `rejit_done` 后重新刷新 `result.state.prog_ids`，于是 post-ReJIT stats 查询拿到了 stale IDs。

这更像 app-level reload + runner state staleness 暴露出来的问题，不像 daemon 主动 detach/delete 了程序。

## 错误来源

- `runner/libs/bpf_stats.py:52-80`
  - `sample_bpf_stats()` 调 `_prog_show_payload()`，后者只读一次当前 `bpftool prog show`。
  - `sample_bpf_stats_from_records()` 构造 `wanted`，只收集当前 records 里 ID 命中的 stats。
  - `missing` 非空时在 `runner/libs/bpf_stats.py:68-73` 抛出：
    `BPF stats missing requested program IDs: ...`

- `corpus/driver.py:99-120`
  - `_measure_runner_phase()` 收到 `prog_ids` 后不会重新枚举 live programs。
  - 如果 `warmup=True`，先跑一次 workload，再对原始 `logical_prog_ids` 调 `sample_bpf_stats()`。
  - 因此 post-ReJIT 阶段的 ID 可能在 warmup workload 之前已经 stale，也可能在 warmup workload 期间变 stale。

## ID 列表如何传递

Corpus 三阶段路径在 `corpus/driver.py:569-686`：

1. `baseline_refresh`：`_refresh_active_session_programs(..., "baseline")` 刷一次 active session 的 program IDs。
2. baseline measurement：`_measure_runner_phase(session.runner, result.state.prog_ids, ..., warmup=True)`。
3. `rejit_refresh`：`_refresh_active_session_programs(..., "rejit")` 再刷一次。
4. ReJIT：`result.rejit_prog_ids = live_rejit_prog_ids(result.state)`，然后 `apply_rejit(result.rejit_prog_ids)`。
5. post-ReJIT measurement：直接调用 `_measure_runner_phase(session.runner, result.state.prog_ids, ..., warmup=True)`。

关键点是第 5 步：`rejit_done` 之后没有 `post_rejit_refresh`。如果 cilium 在 ReJIT 或 post-ReJIT warmup 中换了 program ID，post-ReJIT stats 查询仍使用 `result.state.prog_ids` 里的旧 ID。

`live_rejit_prog_ids()` 本身也不保证实时枚举内核：`runner/libs/case_common.py:73-84` 先调用 runner 的 `live_rejit_programs()`；默认实现 `runner/libs/app_runners/base.py:39-40` 只是返回 `self.programs` 快照。cilium 没有 override 这个方法。

## cilium runner 状态

`runner/libs/app_runners/cilium.py:108-224` 没有 `before_rejit` / `after_rejit` / reload hook，也没有 `refresh_programs()` override。

cilium 继承 `NativeProcessRunner`：

- `runner/libs/app_runners/process_support.py:206-210` 在进程启动前记录 `before_ids`。
- `runner/libs/app_runners/process_support.py:247-253` 等待 program set stable。
- `runner/libs/app_runners/process_support.py:350-355` 将这次启动发现的 programs 保存到 `self.programs`。
- `_discover_programs()` 在 `runner/libs/app_runners/process_support.py:266-267` 可重新从 `bpftool` 找当前 program，但 cilium runner 默认不会在 post-ReJIT measurement 前主动调用它。

所以 cilium runner 没有显式在 `rejit_done error` 后触发 reload；如果 ID 消失，更可能是 cilium-agent 自身异步 reconcile/reload，或 post-ReJIT warmup network workload 触发了 cilium 的 datapath reload。

## daemon 失败路径复核

daemon 的 ReJIT 路径没有看到主动 detach/delete BPF program：

- `daemon/src/commands.rs:442-465` 只通过 `kernel_sys::prog_get_fd_by_id()` 打开现有 prog fd，然后调用 `kernel_sys::prog_rejit()`。失败时写 verifier log 并返回 `kernel rejected BPF_PROG_REJIT`。
- `bpfopt/crates/kernel-sys/src/lib.rs:1390-1509` 的 `prog_rejit()` 只封装 fork-only `BPF_PROG_REJIT` syscall；没有 `BPF_PROG_DETACH`、link detach 或 bpffs unlink。
- `daemon/src/commands.rs:1098-1125` 每个 pass 的 ReJIT 失败只保存失败 artifact、记录 `partial_error`、break 当前 program 的 pass loop。
- `daemon/src/commands.rs:1152-1179` 即便有 `partial_error`，per-program response 仍是 `status="ok"`，错误放在 `error_message`，表示已提交的前序 pass 可能已经生效。
- `daemon/src/server.rs:433-458` `optimize` 命令只是调用 `try_apply_one()` 并把错误转 JSON；没有清理 attach point。

`daemon/src/invalidation.rs:110-112` 的 `remove_prog()` 只是清理 daemon 内部 map-inline invalidation tracker 条目，不是 kernel detach。

## 推测根因

### 1. 最可能：cilium 自己 reload，runner post-ReJIT 使用 stale IDs

现象是 `rejit_start program_count=61`，post-ReJIT stats 缺 45 个旧 ID。这种“多数但非全部 ID 消失”的形态更符合 app reload/reconcile 替换一批 programs，而不是 daemon 的 stats query 状态错乱。runner post-ReJIT 没刷新 ID，直接用旧 `result.state.prog_ids`，所以 fail-fast。

### 2. ReJIT 部分成功改变了 cilium datapath 状态，触发 cilium reconcile

daemon 是 per-pass commit：前几个 pass 成功后会立即 `BPF_PROG_REJIT` 到 live program；后续 pass 失败只停止当前 program，不回滚已经成功的 pass。`rejit_done status=error` 不等于“所有 program 都没变”。cilium 可能观察到 BPF object/program 状态变化后重载一部分 datapath programs。

### 3. post-ReJIT warmup workload 触发 reload

`_measure_runner_phase(..., warmup=True)` 在第一次 stats sample 前先跑 network workload。round 15 的错误是在 `measurement_start phase=post_rejit` 后出现，因此 ID 可能是在 ReJIT loop 结束到 measurement 初次 sample 之间消失，也可能是 warmup 的 `wrk` 流量触发 cilium datapath 初始化/恢复/替换后消失。

## 当前不建议直接 patch

不建议现在改 runner 去自动“换成新 ID”或吞掉 missing IDs：

- 直接忽略 missing IDs 会违反 fail-fast，也会破坏 per-program baseline/post-ReJIT 配对。
- 直接在 post-ReJIT 刷新并替换 ID 需要定义如何按 program identity 重新配对 baseline 与 post-ReJIT program，否则 ratio 会混入不同 program 实例。
- 如果最终确认 cilium reload 是正常行为，修复应围绕“检测 reload 并明确报 reload/stale-id 错误”或“按稳定 program identity 建立新旧配对”，而不是把缺失 ID 当成可跳过样本。

建议下一步确认点：

1. 在保留 round 15 artifact/log 的前提下，对比 `rejit_refresh` 时的 cilium program identities 与 post-ReJIT `bpftool prog show` 当前 identities，看缺失 ID 是否有同名/同 attach 的新 ID 替代。
2. 检查 cilium-agent stdout/stderr 是否在 ReJIT/post-ReJIT warmup 附近有 datapath reload、endpoint regeneration、BPF map restore 或 attach 更新日志。
3. 如果要改 runner，先加诊断型报告字段或明确错误文本，说明 missing IDs 是否存在 identity replacements；不要先引入过滤/跳过。
