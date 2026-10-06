# runner 代码审查报告

审查对象：`/home/yunwei37/workspace/bpf-benchmark/runner`

审查时间：2026-04-11

背景先读：`docs/kernel-jit-optimization-plan.md`。关键背景是 runner 控制面已经从早期 `machines.yaml` 迁移到 `runner/targets/*.env`、`runner/suites/*.env` 与显式 KVM/AWS executors（文档第 852 行）；第 1024-1028 行记录了 micro/corpus/e2e/test 独立 suite entrypoint、旧统一入口删除、suite 参数旁路 `suite-args.json` 等重构。

当前工作树状态提醒：审查时 `runner/` 已有大量未提交改动和新增文件，例如 `runner/suites/_common.py`、`runner/suites/*.py`、`runner/libs/suite_args.py` 为未跟踪文件。本报告按当前工作树内容审查，不假设这些改动已经提交。

## 行数清单

按要求执行：

```text
$ find runner/libs -name '*.py' | xargs wc -l | sort -rn
 11302 total
   784 runner/libs/app_runners/katran.py
   752 runner/libs/rejit.py
   749 runner/libs/case_common.py
   705 runner/libs/workload.py
   679 runner/libs/input_generators.py
   611 runner/libs/run_contract.py
   593 runner/libs/reporting.py
   524 runner/libs/app_runners/tracee.py
   510 runner/libs/aws_executor.py
   406 runner/libs/aws_remote_host.py
   373 runner/libs/app_runners/scx.py
   340 runner/libs/app_runners/bcc.py
   315 runner/libs/app_runners/process_support.py
   278 runner/libs/run_artifacts.py
   276 runner/libs/run_target_suite.py
   269 runner/libs/app_runners/tetragon.py
   257 runner/libs/kvm_executor.py
   217 runner/libs/kinsn.py
   208 runner/libs/results.py
   207 runner/libs/aws_common.py
   207 runner/libs/app_runners/bpftrace.py
   191 runner/libs/__init__.py
   185 runner/libs/suite_args.py
   182 runner/libs/statistics.py
   174 runner/libs/workspace_layout.py
   174 runner/libs/app_suite_schema.py
   165 runner/libs/vm.py
   149 runner/libs/agent.py
   123 runner/libs/bpf_stats.py
   115 runner/libs/app_runners/__init__.py
    99 runner/libs/app_runners/base.py
    96 runner/libs/metrics.py
    91 runner/libs/state_file.py
    85 runner/libs/app_runners/setup_support.py
    76 runner/libs/environment.py
    45 runner/libs/benchmarks.py
    40 runner/libs/kernel_modules.py
    28 runner/libs/process_fd.py
    24 runner/libs/cli_support.py

$ find runner/suites -name '*.py' | xargs wc -l | sort -rn
 1389 total
  413 runner/suites/_common.py
  384 runner/suites/test.py
  213 runner/suites/micro.py
  193 runner/suites/corpus.py
  185 runner/suites/e2e.py
    1 runner/suites/__init__.py
```

## 总体结论

1. 独立 suite entrypoint 的方向是合理的。`runner/suites/micro.py`、`corpus.py`、`e2e.py`、`test.py` 分别封装旧统一入口里的 suite-specific 行为，符合文档第 1024-1028 行描述的迁移目标。

2. 现在最大的可删死代码是明确的：`runner/libs/app_runners/process_support.py:212-315` 的 `NativeProcessRunner`、`runner/libs/results.py:77-93` 的 `UnifiedResultRecord`、`runner/libs/rejit.py:333-359` 的 benchmark 配置包装函数、`runner/libs/__init__.py:120-138` 的 `resolve_perf_binary`。这些均经 `grep -R` 确认没有仓库内调用。

3. 最大的机械重复不是 4 个 suite 脚本本身，而是 suite 命令构造重复了三层：KVM executor `runner/libs/kvm_executor.py:32-192`、AWS remote helper `runner/libs/aws_remote_host.py:181-325`、suite 脚本自己的 `_module_argv`。其中 KVM 与 AWS 远端命令构造最值得合并。

4. `runner/suites/_common.py` 总体合理，但现在已经混合了容器、路径、artifact 校验、sysctl、TMPDIR、argparse 等职责。继续扩张会变成新的“统一入口工具箱”。建议只做小范围拆分，不要重新发明一个大基类。

5. `runner/libs/suite_args.py` 是必要的，因为文档第 1028 行明确把 suite 参数从 `RunConfig` 挪到 `suite-args.json` 旁路；当前 `run_target_suite.py:146-165`、`kvm_executor.py:11/214/252`、`aws_remote_host.py:176-178` 均依赖它。不过它暴露并被 `run_contract.py:15` 导入私有 `_csv_tokens/_join_csv`，这是抽象边界不干净。

6. `runner/suites/*.env` 的主体是必要的，因为它们是当前 active 控制面的 suite contract；但 4 个 `SUITE_DEFAULT_REMOTE_COMMANDS` 行没有被 Python 代码读取，实际远端命令要求写死在 `runner/libs/aws_executor.py:185-192`。

保守可删除合计：约 233 行。这个数字包括明确死代码、未使用 import/env 项、未使用 `RunConfig` 字段和与项目 root-only 约束冲突的 sudo fallback；不包括“合并 KVM/AWS 命令构造器”这类需要重构验证的重复代码。

## 可删除代码清单

| 优先级 | 文件与行号 | 名称 | grep 证据 | 建议删除行数 |
| --- | --- | --- | --- | ---: |
| P0 | `runner/libs/app_runners/process_support.py:212-315` | `NativeProcessRunner` | `grep -R NativeProcessRunner` 只返回定义行 `process_support.py:212` | 104 |
| P0 | `runner/libs/app_runners/process_support.py:13-14` | `WorkloadResult`、`run_named_workload`、`AppRunner` imports | 仅供 `NativeProcessRunner` 使用；删除类后不再需要 | 2 |
| P0 | `runner/libs/rejit.py:333-359` | `_benchmark_int`、`benchmark_config_iterations`、`benchmark_config_warmups`、`benchmark_config_repeat` | `grep -R` 只返回 `rejit.py:333/352/355/358` 定义和内部调用 | 27 |
| P0 | `runner/libs/results.py:77-93` | `UnifiedResultRecord` | `grep -R UnifiedResultRecord` 只返回定义行 | 18 |
| P0 | `runner/libs/results.py:131-150` | `collapse_command_samples`、`parse_command_samples` | `grep -R parse_command_samples` 只返回定义；`collapse_command_samples` 只被它调用 | 20 |
| P0 | `runner/libs/results.py:204-208` | `parse_runner_sample` | `grep -R parse_runner_sample` 只返回定义 | 5 |
| P0 | `runner/libs/results.py:4` | `dataclass, field` import | 仅供 `UnifiedResultRecord` 使用 | 1 |
| P1 | `runner/libs/__init__.py:19-21` | `DEFAULT_PERF_CANDIDATES` | 只被未使用的 `resolve_perf_binary` 使用 | 3 |
| P1 | `runner/libs/__init__.py:23` | `PERF_ENV_VARS` | 只被未使用的 `resolve_perf_binary` 使用 | 1 |
| P1 | `runner/libs/__init__.py:120-138` | `resolve_perf_binary` | `grep -R resolve_perf_binary` 只返回定义行 | 19 |
| P1 | `runner/suites/corpus.py:10/16/26/27` | `Sequence`、`append_bind_mount`、`normalize_target_arch`、`require_executable` imports | `grep -R` 在 suite 文件中只返回 import 或 `_common.py` 定义/内部使用 | 4 |
| P1 | `runner/suites/e2e.py:16/25` | `append_bind_mount`、`normalize_target_arch` imports | 同上 | 2 |
| P1 | `runner/suites/micro.py:20/25` | `append_bind_mount`、`normalize_target_arch` imports | 同上 | 2 |
| P1 | `runner/suites/test.py:23/30/32` | `append_bind_mount`、`normalize_target_arch`、`require_executable` imports | 同上 | 3 |
| P1 | `runner/libs/run_contract.py:64/129/189/529` | `runtime_container_image_tar` / `RUN_RUNTIME_CONTAINER_IMAGE_TAR` | `grep -R runtime_container_image_tar` 只显示 `RunConfig` 字段/序列化；实际 tar 路径由 `workspace_layout.runtime_container_image_tar_path()` 和 `_common.py:76` 计算 | 4 |
| P1 | `runner/suites/corpus.env:11` | `SUITE_DEFAULT_REMOTE_COMMANDS` | `grep -R SUITE_DEFAULT_REMOTE_COMMANDS` 只返回 4 个 env 文件；执行器不用 | 1 |
| P1 | `runner/suites/e2e.env:12` | `SUITE_DEFAULT_REMOTE_COMMANDS` | 同上 | 1 |
| P1 | `runner/suites/micro.env:8` | `SUITE_DEFAULT_REMOTE_COMMANDS` | 同上 | 1 |
| P1 | `runner/suites/test.env:14` | `SUITE_DEFAULT_REMOTE_COMMANDS` | 同上 | 1 |
| P2 | `runner/libs/bpf_stats.py:3/12-13` | 非 root 时自动加 `sudo` | 项目 runner 约束倾向 VM 内 root 执行；host 不应隐式 sudo | 3 |
| P2 | `runner/libs/kinsn.py:3/119-121` | 非 root 时自动加 `sudo` | `resolve_binary("sudo")` 只用于这里；删除 fallback 后可同步收 import | 4 |
| P2 | `runner/suites/_common.py:266-272` | `ensure_bpf_stats_enabled()` 的 sudo fallback | 同类问题；应 root-only fail fast | 7 |

合计：233 行。

未计入合计但建议后续处理：`runner/libs/bpf_stats.py:18-19` 的 `enable_bpf_stats()` 当前只是 no-op context manager。它仍被 `corpus/driver.py:1284/1356` 和多个 `e2e/cases/*/case.py` 使用，所以不能直接删；可以先把调用点改成普通代码块或显式 `ensure_bpf_stats_enabled()` 前置后再删除。

## suite 脚本重复检查

4 个脚本的结构高度同构：

| 文件 | 主要结构 | 结论 |
| --- | --- | --- |
| `runner/suites/micro.py` | `_parse_args` `38-72`、`_module_argv` `75-118`、`_runtime_env` `121-135`、`_micro_driver_argv` `138-173`、`_run_micro_suite` `176-192`、`main` `195-209` | 独立入口合理；与其他 suite 共享入口骨架，但 driver 参数差异大。 |
| `runner/suites/corpus.py` | `_parse_args` `39-86`、`_module_argv` `89-122`、`_runtime_env` `125-129`、`_corpus_driver_argv` `132-154`、`_run_corpus_suite` `157-172`、`main` `175-189` | 与 e2e 最像；SCX/Katran artifact、daemon、native repo/scx package 逻辑可用小 helper 去重。 |
| `runner/suites/e2e.py` | `_validate_e2e_cases` `38-45`、`_parse_args` `48-85`、`_module_argv` `88-117`、`_runtime_env` `120-124`、`_e2e_driver_argv` `127-134`、`_run_e2e_suite` `143-164`、`main` `167-181` | 与 corpus 重复：daemon、artifact 校验、runtime env、module re-entry；但 case 循环是 e2e-specific。 |
| `runner/suites/test.py` | `_parse_args` `44-71`、`_module_argv` `74-104`、test mode helpers `111-337`、`_run_test_suite` `340-363`、`main` `366-380` | 比其他 suite 更特殊；不建议强行合并到通用 runner 类。 |

具体重复：

1. `_module_argv` 四处重复传 `--workspace/--target-arch/--target-name/--executor/--run-token/--python-bin/--bpftool-bin/--container-runtime/--runtime-container-image/--runtime-python-bin`。对应行：micro `75-118`、corpus `89-122`、e2e `88-117`、test `74-104`。可以抽一个 `_common.base_module_argv(args, module_name)`，但只抽共同 prefix 和 container args，不要抽成 suite base class。

2. corpus/e2e/test 三处重复：解析/传递 `--daemon-binary`，调用 `resolve_daemon_binary()`，追加 `--native-repo` 和 `--scx-package`，校验 SCX/Katran artifacts。对应行：corpus `89-122/157-172`、e2e `88-117/143-164`、test `74-104/340-363`。

3. corpus/e2e 的 `_runtime_env` 完全同构，只有函数名不同：corpus `125-129`，e2e `120-124`。可以共用一行 helper。

4. micro/corpus/e2e/test 的 `main()` 都是 `parse -> suite_main_setup -> container re-entry -> run`；对应行：micro `195-209`、corpus `175-189`、e2e `167-181`、test `366-380`。这个重复可接受，因为每个 suite 的前置条件不同；建议只去掉 unused imports。

## `_common.py` 合理性检查

`runner/suites/_common.py` 现在做五类事情：

1. 字符串和参数归一化：`normalize_target_arch` `29-35`、`csv_tokens` `38-39`、`merge_csv_and_repeated` `42-48`。
2. runtime container：`append_bind_mount` `59-64`、`_ensure_runtime_container_image` `67-88`、`run_in_runtime_container` `91-124`。
3. runtime library/env：`cross_runtime_ld_library_path` `131-138`、`suite_runtime_ld_library_path` `141-160`、`env_with_cross_runtime_ld` `163-168`。
4. artifact/path/command helpers：`resolve_executable` `175-187`、`require_executable` `190-194`、`resolve_daemon_binary` `202-204`、`ensure_scx_artifacts` `234-240`、`ensure_katran_artifacts` `243-256`。
5. suite args/env/TMPDIR：`ensure_bpf_stats_enabled` `263-288`、`base_runtime_env` `302-308`、`setup_tmpdir` `311-320`、`add_common_args` `327-344`、`suite_main_setup` `365-378`、`base_suite_runtime_env` `385-413`。

结论：它是合理的 shared utility 文件，不是多余抽象。特别是 `_ensure_runtime_container_image()` `67-88` 与 `run_in_runtime_container()` `91-124` 解决了独立 suite 入口在 VM/远端里加载本地镜像 tar 的问题，不是死代码；`grep -R runtime_container_image_tar_path` 显示 `_common.py:76` 和 `workspace_layout.py:46/124/140` 都相关。

问题：

1. `ensure_bpf_stats_enabled()` `266-272` 隐式 sudo fallback 不符合项目 runner 的 root-only/VM 内执行倾向。建议改为非 root 直接 fail，或者把 root escalation 明确限制在 AWS remote helper，不要在 suite common helper 里偷偷 sudo。

2. `csv_tokens/merge_csv_and_repeated` 与 `runner/libs/suite_args.py:40-54` 重复；`run_contract.py:15` 还直接导入 `suite_args` 的私有 `_csv_tokens/_join_csv`。建议把 CSV helper 做成公开函数，或者各文件局部保留但不要跨模块导入私有函数。

3. 文件职责已经偏宽。后续如果继续增长，建议拆成 `runtime_container.py`、`suite_env.py`、`artifact_checks.py` 三个小模块；不要引入 suite base class。

## `suite_args.py` 和 env 文件必要性

`runner/libs/suite_args.py` 必要。它承担了从 Make/env 到 suite CLI 的翻译，并通过 `suite-args.json` 传给 KVM/AWS executor：

1. `run_target_suite.py:146-165` 生成并写入 suite args。
2. `kvm_executor.py:11/214/252` 读取或直接生成 suite args。
3. `aws_remote_host.py:176-178` 在远端读取 suite args。
4. `run_contract.py:375-378` 用同一套 suite args 解析 selection，从而决定 corpus/e2e/test 的 artifact 需求。

问题：

1. `run_contract.py:15` 导入 `suite_args._csv_tokens/_join_csv` 是私有函数泄露。建议改成公开 `csv_tokens/join_csv`，或者放到 `runner/libs/cli_support.py` 之类共享工具里。

2. AWS test suite 参数只有 `TEST_MODE` 走了 prefix；`suite_args.py:139-149` 仍然读非 prefix 的 `FUZZ_ROUNDS`、`SCX_PROG_SHOW_RACE_*`。如果 AWS 目标期望 `AWS_ARM64_FUZZ_ROUNDS` 或 `AWS_X86_FUZZ_ROUNDS`，当前会被忽略。

3. `runner/suites/test.env:7-11` 定义了 `SUITE_DEFAULT_FUZZ_ROUNDS` 和 `SUITE_DEFAULT_SCX_PROG_SHOW_RACE_*`，但 `suite_args.py:139-149` 使用硬编码默认值，没有读取这些 suite env 默认。现在数值一致，所以不表现为 bug；但这会让 env contract 产生漂移。

`runner/suites/*.env` 的主体必要，因为 `run_contract.py:373-399/458-520` 会加载 suite env 并据此决定 VM class、timeout、native repo、SCX package、artifact/prep 需求。唯一明显无效项是 4 个 `SUITE_DEFAULT_REMOTE_COMMANDS`，见上方可删清单。

## 逐文件审查结论

### runner/libs

`runner/libs/__init__.py`（191 行）：基础路径、命令执行、JSON/text 写入、bpftool/perf 查找。`resolve_perf_binary()` `120-138` 以及 `DEFAULT_PERF_CANDIDATES/PERF_ENV_VARS` `19-23` 没有调用方，建议删除。其他 helper 被 micro/corpus/e2e/runner libs 广泛使用。抽象层基本合理。

`runner/libs/agent.py`（149 行）：启动/停止 `agent.py`，等待健康，按 pid 查询 BPF program。未发现死函数；`_resolve_pids` `62-87`、`_program_refs_from_pid` `90-107` 是 `find_bpf_programs` `110-141` 的内部实现。抽象合理。

`runner/libs/app_runners/__init__.py`（115 行）：把 app suite spec 转为具体 `AppRunner`。`_adapt_*` `25-81` 被 `get_app_runner()` `94-109` 分发使用。没有死代码；结构上是必要的 factory。

`runner/libs/app_runners/bcc.py`（340 行）：BCC tool runner，包含 tool spec 解析、setup 检查、进程生命周期和 workload。`BCCRunner` `165-339` 是主要入口。未发现死代码；重复主要是 app runner 生命周期模板，当前可接受。

`runner/libs/app_runners/bpftrace.py`（207 行）：bpftrace script runner，处理脚本、进程输出和 workload。`BpftraceRunner` `97-204` 是主类。未发现死代码；与 BCC/Tracee 存在进程尾日志模式重复，但底层 `process_support.py` 已承接一部分。

`runner/libs/app_runners/katran.py`（784 行）：Katran DSR topology、namespace HTTP server、map 配置、XDP attach/restore、HTTP workload 与 `KatranRunner` `680-784`。未发现死函数；文件较大但领域耦合强，拆分收益不明显。机械重复主要是 bpftool/ip 命令包装 `82-272`，属于 Katran 专用 glue。

`runner/libs/app_runners/process_support.py`（315 行）：共享进程/session/agent 管理。`wait_for_attached_programs` `17-42`、`AgentSession` `71-115`、`ManagedProcessSession` `118-209` 被 app runners 使用；`NativeProcessRunner` `212-315` 没有任何调用方或子类，建议删除。

`runner/libs/app_runners/scx.py`（373 行）：SCX scheduler app runner 与 workload。`ScxRunner` `298-373` 是主类，`run_hackbench/run_stress_ng_cpu/run_sysbench_cpu` `177-267` 支撑 workload。未发现死代码；局部 percentile `166-174` 与 `statistics.py` 功能相近但只服务本文件，不必强行抽。

`runner/libs/app_runners/tetragon.py`（269 行）：Tetragon agent session、policy 写入、setup 检查和 workload。`TetragonRunner` `198-269` 主入口。未发现死代码；`run_exec_storm_in_cgroup` `120-173` 是 Tetragon-specific。

`runner/libs/app_runners/tracee.py`（524 行）：Tracee runtime dir、输出收集、agent session、setup 检查、命令构造和 workload。`TraceeRunner` `428-524` 主入口。未发现死代码；`TraceeOutputCollector` `64-200` 较大但合理。

`runner/libs/app_suite_schema.py`（174 行）：读取 app suite YAML，构造 `AppSuite/AppSpec/AppWorkload`。`load_app_suite_from_yaml` `110-174` 是主入口。未发现死代码；抽象必要。

`runner/libs/aws_common.py`（207 行）：AWS executor 通用 context、aws/ssh/scp/rsync/helper/terminate。全部以下划线为内部 helper，被 `aws_executor.py` 调用。未发现死代码；模块边界合理。

`runner/libs/aws_executor.py`（510 行）：AWS 实例复用/启动、内核 artifact 构建同步、远端 prereq、远端 suite 执行、结果同步和失败清理。未发现死函数。问题是 `_remote_required_commands()` `185-192` 写死命令集合，导致 `runner/suites/*.env` 的 `SUITE_DEFAULT_REMOTE_COMMANDS` 无效。

`runner/libs/aws_remote_host.py`（406 行）：复制到 AWS 远端执行的 helper，负责 root 文件写入、kernel setup、run config/suite args 加载和 suite 命令分发。未发现死函数。机械重复严重：`_remote_*_suite_command` `181-325` 与 `kvm_executor.py:32-192` 基本同构，应合并命令 argv 构造。

`runner/libs/bpf_stats.py`（123 行）：bpftool program stats 采样与 delta。`enable_bpf_stats()` `18-19` 是 no-op context manager，仍有调用方，不能直接删；`_bpftool_command()` `10-14` 的 sudo fallback 建议删除。其余函数被 corpus/e2e case 使用。

`runner/libs/case_common.py`（749 行）：e2e/corpus case lifecycle，daemon session 准备、scan/apply pass 选择、结果合并、workload 测量、metadata。未发现明确死代码；大函数 `run_case_lifecycle` `391-529` 和 `run_app_runner_phase_records` `637-701` 是核心流程。抽象重但承担跨 app runner 的真实复杂度，暂不建议拆大重构。

`runner/libs/input_generators.py`（679 行）：micro benchmark 输入生成器与 YAML spec 绑定，`materialize_input` `668-679` 是入口。大量 `generate_*` 函数是动态 registry 目标，不能用简单 grep 判死。机械重复来自输入构造模板，但属于生成器表驱动代码，暂不建议压缩。

`runner/libs/kinsn.py`（217 行）：kinsn module 解析、加载、snapshot、daemon discovery。未发现死函数。`load_kinsn_modules()` `101-166` 中 `119-121` 的 sudo fallback 建议删除，并同步清理 `os/resolve_binary` import。

`runner/libs/kvm_executor.py`（257 行）：KVM guest suite 命令构造、guest script 写入、vng 执行。未发现死函数。主要问题是 `micro/corpus/e2e/test_suite_command` `32-192` 与 AWS remote helper 重复。

`runner/libs/rejit.py`（752 行）：benchmark pass config、policy selection、daemon request、apply/scan、`DaemonSession`。`_benchmark_int` `333-349` 与三个 wrapper `352-359` 无调用方，建议删除。其余 policy 与 daemon client 代码有调用路径。

`runner/libs/reporting.py`（593 行）：micro RQ/corpus summary markdown、bootstrap CI、group stats、perf counter summary。`render_rq_summary_markdown` `469-563` 与 `render_corpus_summary_markdown` `572-592` 虽在本文件内部 word-count 看似 0，但 `micro/summarize_rq.py:18/80/94` 调用它们，不是死代码。未发现可删死函数。

`runner/libs/results.py`（208 行）：runner JSON 输出解析、样本归一化、统计函数 re-export。`UnifiedResultRecord` `77-93`、`collapse_command_samples` `131-146`、`parse_command_samples` `149-150`、`parse_runner_sample` `204-208` 没有调用方，建议删除；删除后 `dataclasses` import `4` 也不需要。`parse_last_json_line` 等仍被 `micro/driver.py` 使用。

`runner/libs/run_artifacts.py`（278 行）：artifact session、run type、process identity、benchmark summary。未发现死函数；`ArtifactSession` `21-75` 和 `summarize_benchmark_results` `139-228` 是核心。

`runner/libs/run_contract.py`（611 行）：加载 target/suite env，生成 `RunConfig`，决定 executor/artifact/prep 需求。未发现死函数，但 `_build_run_config_mapping()` `364-550` 是 god function；建议后续按 AWS/KVM/suite selection 拆小。`runtime_container_image_tar` 字段和 `RUN_RUNTIME_CONTAINER_IMAGE_TAR` `64/129/189/529` 没有读取方，建议删除或真正接入。

`runner/libs/run_target_suite.py`（276 行）：顶层 runner action 编排，构建 config、local prep、KVM/AWS 分发、terminate。未发现死函数；`_effective_suite_args` `146-149` 和 `suite-args.json` 写入 `152-197` 是新 suite_args 旁路的必要部分。

`runner/libs/statistics.py`（182 行）：统计 summary、几何均值、perf counter 派生指标。未发现死函数；多函数通过 `runner/libs/results.py` re-export 给 `micro/driver.py` 使用。

`runner/libs/suite_args.py`（185 行）：从 env/target/suite 生成 suite CLI args，解析 selection，读写 suite-args JSON。必要；问题见上文：私有 CSV helper 被 `run_contract.py:15` 导入，test AWS prefix/default env 处理不完整。

`runner/libs/vm.py`（165 行）：guest script、vng 命令构造和 pty 包装执行。未发现死代码；抽象合理。

`runner/libs/workload.py`（705 行）：e2e/corpus workload 库，覆盖 exec/file/io/network/scheduler/mixed。未发现死函数；`run_named_workload` `627-703` 是 dispatch。局部 workload 函数有重复的结果收尾和 deadline loop，但领域差异大，不建议先抽。

`runner/libs/workspace_layout.py`（174 行）：artifact 路径合同和本地/远端 transfer roots。未发现死函数；大量一行 path helper 是刻意中心化，合理。`runtime_container_image_tar_path` `46-47` 被 `_common.py:76` 使用。

### runner/suites

`runner/suites/_common.py`（413 行）：独立 suite 共享 helper。总体必要；建议删除 sudo fallback `266-272`，并防止继续膨胀。

`runner/suites/corpus.py`（193 行）：corpus suite 独立入口，做 container re-entry、daemon/scx/katran artifact 校验、runtime env 和 `corpus/driver.py` 调用。未发现死函数；有 4 个未用 import：`10/16/26/27`。与 e2e 重复较多。

`runner/suites/e2e.py`（185 行）：e2e suite 独立入口，校验 case、做 artifact 校验、逐 case 调 `e2e/driver.py`。未发现死函数；有 2 个未用 import：`16/25`。与 corpus 重复较多。

`runner/suites/micro.py`（213 行）：micro suite 独立入口，准备 runner binary、program dir、runtime env，调用 `micro/driver.py`。未发现死函数；有 2 个未用 import：`20/25`。

`runner/suites/test.py`（384 行）：test suite 独立入口，覆盖 selftest/negative/test/full/fuzz，加载 kinsn modules，生成 artifact 和 summary。未发现死函数；有 3 个未用 import：`23/30/32`。比其他 suite 特殊，不建议强行合并。

## 按优先级排序的修复建议

1. P0：先删明确死代码：`NativeProcessRunner`、`results.py` 的 unused record/parser、`rejit.py` benchmark wrappers、`resolve_perf_binary`。这些没有行为风险，删除后跑 `python3 -m py_compile` 和 `make check`。

2. P1：清理 suite 脚本 unused imports 和无效 env 项；同时决定 `SUITE_DEFAULT_REMOTE_COMMANDS` 是删除，还是接入 `aws_executor._remote_required_commands()`。如果接入，就把 `aws_executor.py:185-192` 改为基础命令 + suite env 命令合并。

3. P1：把 KVM/AWS suite 命令 argv 构造合并。建议新增一个只返回 `list[str]` 的小模块，例如 `runner/libs/suite_commands.py`，供 `kvm_executor.py` 和 `aws_remote_host.py` 使用；KVM 再负责 shell quote，AWS 远端直接执行 argv。

4. P1：修正 `suite_args.py` 的边界：公开 CSV helper，停止 `run_contract.py:15` 导入私有函数；补齐 AWS prefix 下 test 参数 `FUZZ_ROUNDS` / `SCX_PROG_SHOW_RACE_*`。

5. P2：删除 runner common 路径里的隐式 sudo fallback：`bpf_stats.py:12-13`、`kinsn.py:119-121`、`_common.py:266-272`。如果 AWS 远端确实需要 sudo，应只保留在 `aws_remote_host.py:353-367` 这类远端 root escalation 边界。

6. P2：处理 `enable_bpf_stats()` no-op context manager。建议先让 suite entrypoint 明确启用 `kernel.bpf_stats_enabled`，然后把 corpus/e2e case 里的 `with enable_bpf_stats():` 改成普通代码块，最后删除 `bpf_stats.py:18-19`。

7. P3：限制 `_common.py` 继续扩张。后续只抽非常稳定的共同代码，例如 module argv prefix、container args、runtime env；避免新建 suite 基类或把 driver-specific 参数再塞回统一入口。
