# BpfReJIT daemon / runner 可观测性设计

日期: 2026-03-22

## 1. 现状代码结论

### 1.1 daemon `serve` 模式当前返回什么

`daemon/src/server.rs` 的 `optimize` 请求现在只返回三种形态:

- 成功且做了 REJIT: `{"status":"ok","applied":true}`
- 成功但没做 REJIT: `{"status":"ok","applied":false}`
- 失败: `{"status":"error","message":"..."}`

代码位置:

- `daemon/src/server.rs:104-113`

也就是说，`serve` 模式没有返回:

- `prog_id`
- pass 列表
- per-pass site 统计
- insn delta
- verifier retry / rollback 历史
- daemon 版本 / schema 版本

### 1.2 `try_apply_one()` 当前返回什么

`daemon/src/commands.rs` 的 `try_apply_one()` 返回类型是 `Result<bool>`。

- `Ok(true)`: 发生了 REJIT 且最终成功
- `Ok(false)`: 没有原始 insns，或者 pipeline 最终没有改动程序
- `Err(e)`: REJIT 或流程失败

代码位置:

- `daemon/src/commands.rs:505-634`

它内部其实拿到了很多更丰富的信息:

- `pipeline_result.pass_results`
- `pipeline_result.total_sites_applied`
- `program.insns.len()`
- `disabled_passes`
- verifier failure PC / retry 过程

但这些都在函数边界被压缩成了一个 `bool`。

### 1.3 `PassResult` / `PipelineResult` 当前字段

`daemon/src/pass.rs`:

`PassResult` 字段:

- `pass_name`
- `changed`
- `sites_applied`
- `sites_skipped`
- `diagnostics`

其中 `sites_skipped` 的元素 `SkipReason` 只有:

- `pc`
- `reason`

代码位置:

- `daemon/src/pass.rs:241-260`

`PipelineResult` 字段:

- `pass_results`
- `total_sites_applied`
- `program_changed`
- `attribution`

代码位置:

- `daemon/src/pass.rs:507-515`

`attribution` 当前只是 rollback 支持用的粗粒度数据。每个发生改动的 pass 都被记成覆盖整个最终程序 `0..program.insns.len()`，不是精确到变更区间。

代码位置:

- `daemon/src/pass.rs:643-657`

所以它现在最多只能做一个“很弱的最后修改 pass 猜测”，不能当成可靠的 pass blame 数据。

### 1.4 runner `daemon_socket_optimize()` 解析什么

`runner/src/kernel_runner.cpp` 的 `daemon_socket_optimize()` 只做最小字符串解析:

- 看响应里有没有 `"status":"ok"`
- 看响应里有没有 `"applied":true`
- 如果不是 ok，尽量抽取 `"message"`

对应结构体也只有:

- `ok`
- `applied`
- `error`

代码位置:

- `runner/src/kernel_runner.cpp:664-750`

这意味着即使 daemon 将来返回更丰富 JSON，runner 现在也会直接丢掉，除非这里改成结构化 JSON 解析。

### 1.5 runner 当前输出哪些 `rejit` 信息

`runner/include/micro_exec.hpp` 里的 `rejit_summary` 只有:

- `requested`
- `mode`
- `syscall_attempted`
- `applied`
- `insn_cnt`
- `error`

代码位置:

- `runner/include/micro_exec.hpp:98-105`

`runner/src/common.cpp` 最终把这些字段输出到顶层 JSON 的 `rejit` 对象:

- `rejit.requested`
- `rejit.mode`
- `rejit.syscall_attempted`
- `rejit.applied`
- `rejit.insn_cnt`
- `rejit.error`

代码位置:

- `runner/src/common.cpp:421-428`

额外还有两个“间接相关”字段:

- `compile_ns` 在 daemon 模式下会包含 socket optimize 的耗时
- `phase` 在 paired same-image 模式下可能是 `"stock"` / `"rejit"`

但 daemon 模式没有把 optimize 时间单独拆成 `phases_ns.daemon_optimize_ns`。

### 1.6 `normalize_runner_sample()` 保留什么 `rejit` 字段

`runner/libs/results.py` 的 `normalize_runner_sample()` 先做了:

- `normalized = dict(sample)`

所以输入 JSON 里原样存在的 `rejit` 对象会被“原封不动保留”。

但它没有:

- 规范化 `rejit`
- 给 `rejit` 填默认值
- 把 `rejit` 映射成 schema 里的 canonical 字段

相反，它还在给旧字段名 `recompile` 填默认值。

代码位置:

- `runner/libs/results.py:216-250`

这说明当前 Python 侧存在 schema 漂移:

- C++ runner 输出的是 `rejit`
- Python schema / 默认值仍以 `recompile` 为主

结果是:

- 原始 `rejit` 字段 technically 被保留了
- 但很多下游逻辑未必会真正消费到它

## 2. 五个直接答案

### 2.1 daemon optimize 一个程序后，返回给 runner 的 JSON 包含哪些字段

当前只有:

- 成功: `status`, `applied`
- 失败: `status`, `message`

没有任何 per-pass、site、insn delta、verifier retry 信息。

### 2.2 runner 的 JSON 输出中，`rejit` 相关信息有哪些

当前明确输出的只有:

- `rejit.requested`
- `rejit.mode`
- `rejit.syscall_attempted`
- `rejit.applied`
- `rejit.insn_cnt`
- `rejit.error`

以及一些弱相关字段:

- `compile_ns` 包含一部分 rejit/daemon optimize 时间
- `phase` 在 paired 模式里可能出现 `"rejit"`

没有 daemon 返回的 pass 级信息，也没有 daemon 版本、retry 历史、insn delta。

### 2.3 目前能否从结果 JSON 中知道具体哪个 pass 导致了回归

不能。

原因有三层:

1. daemon `serve` 返回只剩 `applied` / `message`
2. runner 只解析 `status` / `applied` / `message`
3. 结果 JSON 只有一个非常薄的 `rejit` summary

即使只看 verifier rejection，也不行:

- daemon 内部 rollback attribution 没有暴露给 runner
- `PipelineResult.attribution` 本身也只是“所有改动 pass 覆盖整个程序”的粗粒度猜测，不足以做高置信 blame

### 2.4 daemon 的 `--passes` flag 能否单独跑某个 pass？`serve` 模式支持吗

能。

现在的 `--passes` 是 daemon 进程启动级别的 pass 过滤:

- `--passes wide_mem` 可以只跑 `wide_mem`
- `--passes rotate,extract` 可以只跑多个 pass
- 顺序仍然按 canonical pipeline order，而不是命令行顺序

代码位置:

- CLI: `daemon/src/main.rs:27-32`
- pipeline builder: `daemon/src/passes/mod.rs:136-150`

`serve` 模式支持，但只是“启动 daemon 时固定一组 pass”:

- `main()` 把 `cli.passes` 传给 `cmd_serve()`
- 每个 `optimize` 请求都会复用这组 `pass_names`

代码位置:

- `daemon/src/main.rs:155-170`
- `daemon/src/server.rs:29-46`

因此:

- 支持“serve daemon 只跑某个 pass”
- 不支持“每个 optimize 请求动态指定不同 pass 集合”

## 3. 当前 observability 断点

### 3.1 daemon 内部有数据，但在接口层全部丢失

最关键的问题不是缺少分析，而是:

- `PassResult` / `PipelineResult` 已经有基础统计
- `try_apply_one()` 拿到了 retry / rollback 信息
- 但 `Result<bool>` 把这些都压扁了

### 3.2 runner 的 socket 协议还是“字符串 contains”

这会直接限制协议演进。

只要 runner 不做结构化 JSON 解析:

- daemon 返回再多字段也没用
- 也无法安全做 schema versioning

### 3.3 Python 结果层存在 `rejit` / `recompile` 双轨漂移

当前真实输出字段名是 `rejit`，但归一化器默认字段还是 `recompile`。这会让分析脚本对 daemon 信息的可见性非常脆弱。

### 3.4 当前 verifier blame 数据也不够精确

即使把当前 rollback attribution 原样输出，也只能说:

- “最后一个修改过程序的 pass 很可疑”

不能说:

- “这个 pass 在哪些 site 上造成了 verifier failure”
- “具体哪个 pass 导致了性能回归”

## 4. 目标

需要的不是单个 debug 字段，而是一个完整链路:

1. daemon 在一次 optimize 中产出结构化、可版本化的执行记录
2. runner 原样接收并嵌入结果 JSON
3. Python 结果层把它规范成稳定 schema
4. 分析脚本据此自动做 per-pass ablation
5. 出现 regression 时能复现到“具体程序 + 具体 pass 组合 + 具体 rewritten bytecode”

## 5. 设计方案

### 5.1 daemon optimize 返回值应包含什么

建议把 `try_apply_one()` 从 `Result<bool>` 升级成 `Result<OptimizeOneResult>`，再由 `serve` 直接序列化这个结构。

建议最少包含以下字段。

#### A. 顶层身份与版本

- `schema_version`
- `status`
- `daemon.version`
- `daemon.git_commit`
- `request.cmd`
- `request.prog_id`
- `request.selected_passes`
- `request.rollback_enabled`
- `request.pgo.enabled`
- `request.pgo.interval_ms`

#### B. 程序级 summary

- `program.prog_id`
- `program.prog_name`
- `program.prog_type`
- `program.orig_insn_count`
- `program.final_insn_count`
- `program.insn_delta`
- `program.orig_bytecode_sha256`
- `program.final_bytecode_sha256`

如果成本可接受，再加:

- `program.run_cnt_before`
- `program.run_time_ns_before`

#### C. 最终 optimize 结果 summary

- `summary.applied`
- `summary.program_changed`
- `summary.result_kind`
- `summary.total_sites_applied`
- `summary.passes_considered`
- `summary.passes_executed`
- `summary.passes_changed`
- `summary.verifier_retries`
- `summary.final_disabled_passes`
- `summary.fd_array_cnt`

`result_kind` 建议枚举化:

- `applied`
- `applied_after_rollback`
- `no_orig_insns`
- `no_changes`
- `verifier_rejected`
- `internal_error`

#### D. per-pass decisions

这是最关键部分。每个 pass 至少返回:

- `pass_name`
- `selected`
- `changed`
- `sites_applied`
- `sites_skipped`
- `skip_reasons`
- `insns_before`
- `insns_after`
- `insn_delta`
- `diagnostics`

`skip_reasons` 不建议默认把所有 site 全部展开；默认返回 reason->count 汇总即可，例如:

```json
"skip_reasons": {
  "kfunc_unavailable": 3,
  "subprog_unsupported": 1,
  "insufficient_bias": 7
}
```

如果需要更深调试，再加可选 verbose/debug 字段:

- `site_examples`
- `site_details`
- `new_pc_ranges`

#### E. verifier retries / rollback 历史

建议显式返回 `attempts` 数组，每次 REJIT 尝试一条:

- `attempt`
- `disabled_passes`
- `pipeline_changed`
- `total_sites_applied`
- `result`
- `failure_pc`
- `attributed_pass`
- `attribution_confidence`
- `verifier_state_snapshots`
- `verifier_log_digest`

失败时再可选返回:

- `verifier_log_excerpt`
- `rewritten_bytecode_sha256`

#### F. profiling / hotness

如果启用了 PGO，应记录:

- `profiling.enabled`
- `profiling.interval_ms`
- `profiling.delta_run_cnt`
- `profiling.delta_run_time_ns`
- `profiling.delta_avg_ns`
- `profiling.is_hot`
- `profiling.branch_profile_count`

#### G. timings

建议 daemon 内自己拆 timing:

- `timings_ns.pgo_collect`
- `timings_ns.pipeline_run`
- `timings_ns.rejit_syscall`
- `timings_ns.total`

### 5.2 关于 verifier attribution 的设计要求

当前 `PipelineResult.attribution` 不能直接拿来做 pass blame，因为它把每个 changed pass 都映射到整个程序。

建议升级为:

- 每个 pass 返回真实的 `new_pc_ranges`
- 或者至少返回每个 transformed site 的 `old_pc` / `new_pc_range`

如果暂时做不到，就必须在输出里明确标记:

- `attribution_confidence = "low"`

不要把低质量猜测包装成确定结论。

### 5.3 runner JSON 应该记录什么

runner 侧建议保留两层数据:

#### A. 轻量 summary，方便聚合

保留现有 `rejit`，但扩展为:

- `requested`
- `mode`
- `syscall_attempted`
- `applied`
- `insn_cnt`
- `error`
- `daemon_status`
- `daemon_schema_version`
- `daemon_version`
- `total_sites_applied`
- `final_insn_delta`
- `verifier_retries`
- `final_disabled_passes`

#### B. 完整 daemon 原始响应

新增:

- `rejit.daemon_response`

直接嵌入 daemon optimize 的结构化 JSON，避免信息在 runner 侧再次丢失。

#### C. runner 自己补充的上下文

建议再记录:

- `rejit.daemon_socket`
- `rejit.prog_id`
- `rejit.optimize_wall_ns`
- `rejit.optimize_in_compile_ns`
- `rejit.program_before`
- `rejit.program_after`

其中 `program_before/after` 可包含:

- `xlated_prog_len`
- `jited_prog_len`
- `bpf_bytecode_sha256`
- `native_code_sha256` if available

#### D. phases_ns 要单独拆 daemon optimize

现在 daemon 模式只有 `compile_ns` 聚合了这段时间，不利于分析。

建议新增:

- `phases_ns.daemon_optimize_ns`
- `phases_ns.daemon_pgo_ns`
- `phases_ns.daemon_pipeline_ns`
- `phases_ns.daemon_rejit_ns`

如果 daemon 返回了这些 timing，runner 可以直接透传。

### 5.4 `runner/libs/results.py` 应该怎么修

建议把 `rejit` 定为 canonical 字段，`recompile` 只保留兼容层。

`normalize_runner_sample()` 建议逻辑:

1. `raw_rejit = sample.get("rejit") or sample.get("recompile") or {}`
2. 规范化为 `normalized["rejit"]`
3. 在一个过渡周期内，`normalized["recompile"] = normalized["rejit"]`
4. 如果两者都存在但不一致，显式报 schema 冲突

这样才能保证:

- C++ runner 新字段不会被 Python 丢掉
- 旧脚本还可以逐步迁移

### 5.5 分析脚本如何做 per-pass ablation

有了 `rejit.daemon_response.passes` 之后，分析脚本可以做分层 ablation，而不是盲扫所有 pass 组合。

建议流程:

1. 先跑 baseline stock
2. 再跑 full pipeline
3. 从 full pipeline 里筛出 `sites_applied > 0` 或 `changed = true` 的 passes
4. 只对这些 active passes 做 leave-one-out
5. 如果还不清楚，再做 single-pass
6. 对仍有歧义的少数 case 做 pairwise interaction

判定逻辑:

- 某 pass 去掉后 regression 消失: 它是强嫌疑
- 某 pass 单独运行就回归: 它是直接 culprit
- 只有两个 pass 组合才回归: 这是 interaction regression

脚本输出应至少包含:

- `full_vs_stock`
- `loo_vs_full`
- `single_vs_stock`
- `applied_rate`
- `verifier_retry_count`
- `code_size_delta`

关键优化点:

- 用 `sites_applied == 0` 直接剪枝
- 用 `insn_delta == 0` 的 pass 降低优先级
- 用 `skip_reasons` 区分“没跑成”和“跑了但没改”

### 5.6 serve 模式下如何支持 ablation

短期:

- 直接重启 daemon，多次传不同 `--passes`

长期更好的方案:

- 给 `optimize` 请求增加 `enabled_passes` / `disabled_passes`

例如:

```json
{"cmd":"optimize","prog_id":1234,"enabled_passes":["wide_mem","rotate"]}
```

这样分析脚本就不需要为了每个 ablation 组合重启 daemon。

### 5.7 如何复现特定程序的回归

要复现 regression，结果 JSON 里必须能回答下面这些问题:

- 跑的是哪个程序
- 用了哪组 pass
- daemon/runner/kernel 分别是什么版本
- rewrite 前后的 bytecode 是什么
- 有没有 rollback / verifier rejection
- PGO 输入是什么

因此建议在结果 JSON 里持久化:

- benchmark 名称 / ELF 路径 / program 名
- 输入数据路径或 digest
- kernel `uname -r` / build id
- daemon version / git commit
- runner version / git commit
- selected passes
- rollback 开关
- PGO 配置与 profiling snapshot
- 原始与最终 bytecode hash
- 每次 attempt 的 rewritten bytecode hash
- verifier failure PC / attributed pass / verifier log digest

如果是 debug / regression 模式，建议额外落盘 artifact:

- `orig.bin`
- `attempt_0.bin`
- `attempt_0.verifier.log`
- `attempt_1.bin`
- `daemon_response.json`

推荐复现流程:

1. 用结果 JSON 定位同一 benchmark / program / input
2. 用记录下来的 daemon flags 重启 daemon
3. 先复跑 full pipeline，确认 regression 复现
4. 再按 active passes 做 leave-one-out
5. 若是 verifier 问题，直接回放失败 attempt 对应的 rewritten artifact

## 6. 推荐的 optimize 响应骨架

下面给一个建议 schema 骨架:

```json
{
  "schema_version": 2,
  "status": "ok",
  "daemon": {
    "version": "0.1.0",
    "git_commit": "abc123"
  },
  "request": {
    "cmd": "optimize",
    "prog_id": 1234,
    "selected_passes": ["wide_mem", "rotate"],
    "rollback_enabled": true,
    "pgo": {"enabled": true, "interval_ms": 500}
  },
  "program": {
    "prog_id": 1234,
    "prog_name": "xdp_main",
    "prog_type": 6,
    "orig_insn_count": 110,
    "final_insn_count": 100,
    "insn_delta": -10,
    "orig_bytecode_sha256": "...",
    "final_bytecode_sha256": "..."
  },
  "summary": {
    "applied": true,
    "program_changed": true,
    "result_kind": "applied_after_rollback",
    "total_sites_applied": 3,
    "passes_executed": 2,
    "passes_changed": 1,
    "verifier_retries": 1,
    "final_disabled_passes": ["branch_flip"]
  },
  "profiling": {
    "enabled": true,
    "delta_run_cnt": 1000,
    "delta_run_time_ns": 900000,
    "delta_avg_ns": 900.0,
    "is_hot": true,
    "branch_profile_count": 0
  },
  "passes": [
    {
      "pass_name": "wide_mem",
      "selected": true,
      "changed": true,
      "sites_applied": 3,
      "sites_skipped": 2,
      "skip_reasons": {"subprog_unsupported": 2},
      "insns_before": 110,
      "insns_after": 100,
      "insn_delta": -10,
      "diagnostics": []
    },
    {
      "pass_name": "branch_flip",
      "selected": true,
      "changed": false,
      "sites_applied": 0,
      "sites_skipped": 5,
      "skip_reasons": {"insufficient_bias": 5},
      "insns_before": 100,
      "insns_after": 100,
      "insn_delta": 0,
      "diagnostics": []
    }
  ],
  "attempts": [
    {
      "attempt": 0,
      "disabled_passes": [],
      "result": "verifier_rejected",
      "failure_pc": 76,
      "attributed_pass": "branch_flip",
      "attribution_confidence": "low"
    },
    {
      "attempt": 1,
      "disabled_passes": ["branch_flip"],
      "result": "applied"
    }
  ],
  "timings_ns": {
    "pgo_collect": 1000000,
    "pipeline_run": 200000,
    "rejit_syscall": 300000,
    "total": 1600000
  }
}
```

## 7. 实施优先级

### P0

- 把 `try_apply_one()` 改成结构化 `OptimizeOneResult`
- `serve` 直接返回完整 optimize 响应
- runner 改成结构化 JSON 解析

### P1

- runner 结果 JSON 嵌入 `rejit.daemon_response`
- `results.py` 统一 `rejit` / `recompile`
- `phases_ns` 单独拆出 daemon optimize timing

### P2

- per-pass `skip_reasons` 汇总
- verifier retry history
- bytecode hash / artifact 持久化

### P3

- 请求级 `enabled_passes` / `disabled_passes`
- 精确 `new_pc_ranges`
- 自动 per-pass ablation 分析脚本

## 8. 结论

当前链路最大的症结不是“完全没有 observability”，而是:

- daemon 内部已有的 pipeline / rollback 信息在接口边界被压扁成了 `bool`
- runner 又只做了最小字符串解析
- Python 结果层还有 `rejit` / `recompile` schema 漂移

所以当前结果 JSON 只能回答“有没有应用 REJIT”，不能回答“哪个 pass 改了什么、为什么回退、为什么回归”。要支持 per-pass ablation 和稳定复现，必须把 daemon optimize 结果升级成结构化、可版本化、可透传的执行记录。
