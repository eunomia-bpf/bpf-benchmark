# Benchmark Full Review Round 3

范围：静态 review `corpus/`、`e2e/`、`runner/`，对照 `docs/kernel-jit-optimization-plan.md` 的 §5.6 和 §5.35。未跑 VM，未修改代码。

## CRITICAL

- **共享 YAML 合同并没有真正落地。** [macro_apps.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml):1, [macro_apps.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml):6, [app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py):10, [app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py):54, [corpus/orchestrator.py](/home/yunwei37/workspace/bpf-benchmark/corpus/orchestrator.py):158, [e2e/run.py](/home/yunwei37/workspace/bpf-benchmark/e2e/run.py):122  
  描述：§5.6 要求同一份 YAML 同时服务 corpus 和 e2e，根结构是 app 列表，且每个 app 的 `workload` 必须拆成 `corpus` / `e2e` 两个 key。当前 live manifest 仍是 `schema_version/suite_name/defaults/apps` 旧结构；`AppSpec.workload` 仍是单个字符串；`corpus/orchestrator.py` 只能读取一个 workload；`e2e/run.py` 完全绕开 `macro_apps.yaml`，继续走 case-specific config/CLI。结果是 YAML → orchestrator → app_runner → e2e 的统一数据流并不存在，也无法表达 plan 里明确要求的 `katran: corpus=test_run, e2e=network` 这种分叉 workload。  
  违反：§5.6 “Corpus 和 E2E 共享 App Runner”“同一 YAML 服务 corpus 和 e2e”“`workload.corpus` / `workload.e2e` schema”。

  描述：daemon apply 先按 program 返回结果，但 `_apply_daemon_rejit_via_socket()` 把它们折叠成单个 `all_applied` 布尔值。之后 corpus 和 Tracee/Tetragon/BCC/bpftrace 都用这个布尔值决定是否跑 post-ReJIT phase，以及是否把 loader instance 标成 error。只要同一 loader 里任一 program 未 apply，其他已 apply program 的 paired post-ReJIT measurement 就被整个实例丢弃。共享 lifecycle 的测试已经明确覆盖“`applied=False` 但 `applied_sites>0` 仍继续测 post phase”的语义，而当前只有 scx case 实际用了这条路径。  
  违反：§5.6 “生命周期单元是 loader instance”“same-image paired measurement”；§5.35 “applied-only + all-comparable” 统计前提。

## HIGH

- **E2E 的 BPF stats 路径仍然存在 silent degrade。** [metrics.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/metrics.py):121, [metrics.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/metrics.py):148, [metrics.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/metrics.py):154, [metrics.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/metrics.py):157, [metrics.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/metrics.py):245  
  描述：`sample_bpf_stats()` 对 requested `prog_id` 的 FD lookup 失败、`bpf_prog_get_info_by_fd()` 失败都直接 `continue`，不会报错；`compute_delta()` 再对 before/after 并集补零算 delta。结果是缺失统计会被伪装成 0-event/0-time delta，而不是 fail fast。这个 collector 仍被 Tracee/Tetragon/BCC/bpftrace E2E case 使用。  
  违反：§5.35 的可解释 measurement 约束，以及仓库 `Zero Silent Failure Policy`。

- **`make vm-corpus` 的默认 repeat 实际是 1，不满足 authoritative benchmark 要求。** [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile):122, [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile):376, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):36, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):89, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):300, [corpus/orchestrator.py](/home/yunwei37/workspace/bpf-benchmark/corpus/orchestrator.py):40, [corpus/orchestrator.py](/home/yunwei37/workspace/bpf-benchmark/corpus/orchestrator.py):151, [macro_apps.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml):1  
  描述：root/runner Makefile 都只在 `REPEAT` 被显式覆写时才传 `--repeat`；`corpus/orchestrator.py` 的默认 `--repeat` 是 0；随后 `_repeat_count()` 回落到 YAML `defaults.repeat` 或 1；而 `macro_apps.yaml` 只有 `duration_s`，没有 `repeat`。因此当前 `make vm-corpus` 的默认 live 行为是 repeat=1，不是 plan/文档里的默认 200，也不满足 §5.35 要求的 `repeat ≥ 50`。  
  违反：§5.35 “repeat ≥ 50，论文级 ≥ 500”；`make vm-corpus` target 与当前实现不一致。

- **corpus authoritative reporting/dataflow 仍是断的。** [corpus/orchestrator.py](/home/yunwei37/workspace/bpf-benchmark/corpus/orchestrator.py):303, [corpus/orchestrator.py](/home/yunwei37/workspace/bpf-benchmark/corpus/orchestrator.py):329, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):59, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):300, [reporting.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/reporting.py):706  
  描述：new corpus live path 只产出 raw JSON。top-level `summary` 只有 `selected_apps / discovered_programs / statuses`；没有 applied-only geomean、all-comparable geomean、sample count、comparison exclusion reasons。与此同时，`vm-corpus` target 虽然定义了 `VM_CORPUS_OUTPUT_MD`，但从未调用 markdown/report 生成。也就是说，YAML → orchestrator → app_runner → bpf_stats → results 已经接上，但 `results → authoritative report` 这一步仍未接通。  
  违反：§5.35 “报告必须同时给 applied-only geomean 和 all-comparable geomean + sample count + comparison exclusion reasons”；用户要求的数据流完整性。

- **Katran 仍然不在 live benchmark framework 里。** [e2e/run.py](/home/yunwei37/workspace/bpf-benchmark/e2e/run.py):124, [e2e/run.py](/home/yunwei37/workspace/bpf-benchmark/e2e/run.py):184, [app_runners __init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/__init__.py):126, [macro_apps.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml):6  
  描述：`e2e/run.py` 的 case choices 和 `ALL_CASES` 都不包含 `katran`；shared app-runner registry 没有 `katran` runner；`macro_apps.yaml` 也没有 `katran` app entry。§5.6 明确把 Katran 作为 canonical loader instance，并且给出了 `corpus=test_run / e2e=network` 的示例 workload。当前框架无法调度这条基准线。  
  违反：§5.6 shared AppRunner 架构与示例 schema；§5.35 “有原生应用的程序必须用 app-native loader” 的覆盖要求。

## MEDIUM

- **`vm-corpus` 的参数表面仍然带着过期控制面。** [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile):177, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):34, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):35, [runner/Makefile](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile):300  
  描述：顶层 help 继续把 `ITERATIONS/WARMUPS/REPEAT` 作为统一 benchmark 参数展示，但 new corpus path 实际只认 `repeat`，而且默认 repeat 还没接通；`ITERATIONS/WARMUPS` 对 `vm-corpus` 是 no-op。这个问题不会直接篡改 measurement，但会误导 runbook 和操作者。  
  违反：Make target 完整性与参数透传一致性要求。

## LOW

- **本轮要求的旧架构残留 grep 没有再发现新的 live-code 命中，但相关清理并未弥补上面的设计断裂。**  
  描述：针对 `bpftool.*loadall`、`compile_only`、`prepared_state/prepared_group`、`batch_plan`、`trigger_timeout`、`measurement.*bpftool` 等模式，在 `corpus/`、`e2e/`、`runner/` 的 live code 中没有发现新的命中；问题已经从“旧对象中心代码残留”收敛到“新框架 contract 和统计闭环未完成”。  
  违反：无新增条目；此处仅记录本轮 grep 结论，便于区分“残留代码”与“新架构本身的缺口”。

## 总结

当前框架 **不 ready for authoritative benchmark run**。

阻塞项不是单点 bug，而是 benchmark framework 的几个核心 contract 仍未闭环：

1. §5.6 规定的共享 YAML/schema 没有真正接通，corpus 和 e2e 仍是两套控制面。
2. partial-apply 被错误当成 all-or-nothing，same-image paired measurement 会被整批丢失。
3. `make vm-corpus` 默认 repeat 实际为 1，直接不满足 §5.35 的统计门槛。
4. corpus live path 还不能产出 authoritative report 所需的 geomean/sample-count/exclusion-reason。
5. Katran 这条 plan 中明确要求的 app-native benchmark 仍未纳入 live framework。

如果以上问题不先解决，当前结果不应作为 authoritative corpus/e2e benchmark 依据。
