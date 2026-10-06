# Benchmark Framework Dead Code Audit

日期：2026-03-26

## 范围与方法

- 只做静态审查，不改代码，不跑 benchmark。
- 调用链按 `Makefile -> runner/Makefile -> Python/C++ entrypoint` 追踪。
- 引用关系用 `rg` 和 AST 扫描确认；结论分成两类：
  - `全仓库无引用`：可以直接视为死代码。
  - `当前 vm-* 主路径无调用`：对现在的 benchmark 框架是死代码，但仍保留手工入口。

## 1. vm-* target 实际调用了什么

根 `Makefile` 的 `vm-*` target 本质上都下沉到 `runner/Makefile`。实际入口如下。

| vm target | 最终入口 | 实际 Python/C++ 命令与关键参数 |
| --- | --- | --- |
| `vm-shell` | `runner/Makefile:195-202` | `python3 runner/scripts/run_vm_shell.py --action vm-test --kernel-image <bzImage> --command 'cd <repo> && <VM_INIT> <VM_COMMAND>'` |
| `vm-test` | `runner/Makefile:204-216` | `python3 runner/scripts/run_vm_shell.py --action vm-test --kernel-image <bzImage> --command '<VM_INIT> scripts/run_all_tests.sh <repo>'`，同时注入 `SCX_*` 环境变量 |
| `vm-selftest` | `runner/Makefile:218-225` | `python3 runner/scripts/run_vm_shell.py --action vm-selftest --kernel-image <bzImage> --command '<VM_INIT> scripts/vm-selftest.sh <repo> <tests/unittest> <kinsn_module_dir> <negative_test_dir> <fuzz_rounds>'` |
| `vm-static-test` | `runner/Makefile:227-235` | `python3 runner/scripts/run_vm_shell.py --action vm-static-test --kernel-image <bzImage> --command 'cd <repo> && <VM_INIT> python3 daemon/tests/static_verify.py --daemon-binary <daemon> --daemon-args=<args> --output <json> <STATIC_VERIFY_ARGS>'` |
| `vm-negative-test` | `runner/Makefile:237-245` | `python3 runner/scripts/run_vm_shell.py --action vm-negative-test --kernel-image <bzImage> --command '<VM_INIT> adversarial_rejit && fuzz_rejit && scx_prog_show_race <repo> --mode <mode> --iterations <n> --load-timeout <n> [--skip-probe]'` |
| `vm-micro-smoke` | `runner/Makefile:247-255` | 先在 VM 内后台启动 `bpfrejit-daemon --pgo serve --socket <sock>`，再执行 `python3 micro/driver.py --runtime kernel --runtime kernel-rejit --daemon-socket <sock> <VM_SMOKE_ARGS> --output <json>` |
| `vm-micro` | `runner/Makefile:257-265` | 先在 VM 内后台启动 `bpfrejit-daemon --pgo serve --socket <sock>`，再执行 `python3 micro/driver.py --runtime llvmbpf --runtime kernel --runtime kernel-rejit --daemon-socket <sock> --iterations <n> --warmups <n> --repeat <n> [--bench ...] --output <json>` |
| `vm-corpus` | `runner/Makefile:267-276` | `python3 corpus/driver.py packet --kernel-image <bzImage> --runner runner/build/micro_exec --daemon daemon/target/release/bpfrejit-daemon --btf-custom-path <vmlinux> --repeat <n> --output-json <json> --output-md <md>` |
| `vm-e2e` | `runner/Makefile:278-286` | `python3 runner/scripts/run_vm_shell.py --action vm-e2e --kernel-image <bzImage> --command 'cd <repo> && <VM_INIT> python3 e2e/run.py all'` |
| `vm-all` | 根 `Makefile:319-323` | 只是顺序执行 `vm-test`、`vm-micro`、`vm-corpus`、`vm-e2e`，自己不直接调用 Python/C++ 入口 |

补充：

- `micro/driver.py` 和 `corpus/modes.py` 最终都会通过 `runner.libs.batch_runner.run_batch_runner()` 调 `runner/build/micro_exec run-batch`。
- 当前 `vm-*` 主路径里，真正高频在用的 C++ 入口是 `run-batch`；`list-programs` 只在对象清点阶段用；keep-alive 没有调用者。

## 2. 分组件审查

### 2.1 `micro/driver.py`

结论：

- 没发现未被调用的顶层函数。
- 运行时机制 `llvmbpf`、`kernel`、`kernel-rejit` 都在用，不存在已经废弃但仍保留的 runtime。
- 没看到 `directive/policy/scanner` 这类 v1 残留路径；micro 已经是 runtime 驱动，不是 policy 驱动。
- 但有一个明显的无效 feature：`--rejit`。

#### dead code / 无效 feature 清单

| 类型 | 符号 | 行号 | 行数 | 结论 |
| --- | --- | --- | --- | --- |
| unused import | `json` | `5` | `1` | 未被引用 |
| 无效 CLI feature | `--rejit` flag 定义 | `64-68` | `5` | 现在不会影响调度，只是保留参数 |
| 无效 CLI feature | `--rejit requires --runtime kernel-rejit` 校验 | `606-607` | `2` | 只校验 flag/ runtime 组合，不影响执行计划 |
| 无效 CLI feature | 结果元数据里的 `defaults.rejit` | `653` | `1` | 只是把无效 flag 写进结果 |

#### runtime 机制结论

- `vm-micro` 明确跑 `llvmbpf`、`kernel`、`kernel-rejit` 三个 runtime。
- `vm-micro-smoke` 明确跑 `kernel`、`kernel-rejit`。
- `build_micro_batch_plan()` 里 REJIT 是否发生，取决于 runtime 名称是不是 `kernel-rejit`，不是 `args.rejit`。
- `runtime_supports_prepared_state()` 仍然在用，`kernel` / `kernel-rejit` 的 prepared-state 路径是活的，不是死分支。

### 2.2 `corpus/driver.py` + `corpus/modes.py`

结论：

- `Makefile` 只会调用 `corpus/driver.py packet`。
- `packet` 是当前唯一接入 `vm-corpus` 的 mode。
- `tracing`、`perf`、`code-size` 三个 mode 共享同一套 linear-mode 实现，对当前 `vm-*` 主路径来说是死代码。
- `packet_main()` 和 `run_linear_mode()` 有明显重复的 artifact/session scaffolding。
- `policy_*` 语义还留在 schema 里，但当前 packet 路径已经不再依赖外部 policy 文件，属于 v1 命名残留。

#### 4 个 mode 的代码量

- `packet` 路径主实现位于 `119-1918`，约 `1800` 行。
- `tracing` / `perf` / `code-size` 并没有各自独立的大块实现，三者共用 `1921-2336` 这一段 linear-mode 代码，共 `416` 行。
- `tracing` 自己额外只多出两个分支点：`2015-2017` 和 `2131-2132`，合计 `5` 行。
- `perf` 自己额外只有默认输出和 `enable_exec = mode_name == "perf"` 这种轻量分支。
- `code-size` 只有默认输出分支，没有单独执行路径。

#### dead code 清单

`corpus/driver.py` 本身没有死函数；真正的死面集中在 `corpus/modes.py`。

| 类型 | 符号 | 行号 | 行数 | 结论 |
| --- | --- | --- | --- | --- |
| unused import | `ensure_parent` | `54` | `1` | 本文件未使用 |
| unused import | `write_json_output` | `66` | `1` | 本文件未使用 |
| unused import | `write_text_output` | `67` | `1` | 本文件未使用 |
| 当前 `vm-*` 主路径无调用 | `_mode_defaults` | `1921-1928` | `8` | 只服务 linear modes |
| 当前 `vm-*` 主路径无调用 | `parse_linear_mode_args` | `1931-1975` | `45` | 只服务 linear modes |
| 当前 `vm-*` 主路径无调用 | `_source_name_for_object` | `1978-1985` | `8` | 只被 linear mode discovery 用 |
| 当前 `vm-*` 主路径无调用 | `discover_linear_targets` | `1988-2059` | `72` | 只服务 linear modes |
| 当前 `vm-*` 主路径无调用 | `build_linear_summary` | `2062-2100` | `39` | 只服务 linear modes |
| 当前 `vm-*` 主路径无调用 | `build_linear_markdown` | `2103-2170` | `68` | 只服务 linear modes |
| 当前 `vm-*` 主路径无调用 | `run_linear_mode` | `2173-2336` | `164` | `vm-corpus` 从不走这里 |
| unused parameter | `build_record_from_batch_results(..., skip_families=...)` | `743` | `1` | 参数定义存在，但函数体不读取 |

#### `run_linear_mode` vs `packet_main` 重复逻辑

重复主要在四块：

- 参数、路径、输出文件、`run_type` 初始化：
  - `packet_main: 1720-1754`
  - `run_linear_mode: 2174-2203`
- `build_artifact_metadata()` 闭包：
  - `packet_main: 1788-1834`
  - `run_linear_mode: 2224-2267`
- `flush_artifact()` 闭包：
  - `packet_main: 1844-1862`
  - `run_linear_mode: 2277-2297`
- `try/except + progressive flush` 外围框架：
  - `packet_main: 1865-1908`
  - `run_linear_mode: 2299-2333`

保守估算，纯 scaffolding 重复约 `90-120` 行；如果把 payload 字段拼装也算进去，实际重复量更高。

#### v1 残留

这部分不是“完全死代码”，但已经偏 schema baggage：

| 类型 | 符号 | 行号 | 行数 | 结论 |
| --- | --- | --- | --- | --- |
| v1 语义残留 | `policy_path` / `policy_mode` / `scan_source` 记录 schema | `411-413` | `3` | 继续写入结果，但 packet 路径已经不靠外部 policy 文件驱动 |
| v1 语义残留 | `policy_mode = "blind-apply-rejit" if blind_apply else "daemon-auto"` | `749` | `1` | 命名还是 policy 时代术语 |
| v1 语义残留 | `record["policy_path"] = None` 等固定值写入 | `766-768` | `3` | `policy_path` 现在恒为 `None` |
| v1 语义残留 | guest payload 中继续下发 `policy_mode` / `policy_path=None` | `1109-1110` | `2` | guest 侧仍带旧字段，但没有真实 policy 文件输入 |

### 2.3 `runner/src/main.cpp`

#### C++ runner 子命令

当前 `main.cpp` 暴露的模式和子命令如下：

- `run-batch`
- 单次模式 `list-programs`
- 单次模式 `run-llvmbpf`
- 单次模式 `run-kernel`
- 单次模式 `run-kernel-attach`
- 无参数 keep-alive mode

#### 哪些在用

- `run-batch`：当前 benchmark 框架核心路径，`micro` / `corpus` 都在用。
- `list-programs`：还在用，但主要是对象清点和 inventory discovery。
- 单次 `run-llvmbpf` / `run-kernel` / `run-kernel-attach`：当前 `vm-*` 主路径不用。
- keep-alive mode：没找到任何调用者，可以视为死模式。

补充：

- `kernel-attach` / `kernel-attach-rejit` 这个 runtime 仍然通过 `run-batch` 在 corpus packet path 里使用。
- 也就是说，死的是“单次 CLI attach mode”和“keep-alive mode”，不是 attach runtime 本身。

#### dead code 清单

| 类型 | 符号 | 行号 | 行数 | 结论 |
| --- | --- | --- | --- | --- |
| 当前 `vm-*` 主路径无调用 | `run_keep_alive_loop` | `34-86` | `53` | 无参数 keep-alive 没有 repo 内调用者 |
| 当前 `vm-*` 主路径无调用 | `run_single_shot` 中的 `run-llvmbpf` / `run-kernel` / `run-kernel-attach` 分支 | `15-29` | `15` | 当前框架不走单次执行，改走 `run-batch` |

说明：

- 如果真的删 keep-alive，影响不止 `main.cpp`，还会连带 `runner/src/common.cpp` 里的 request parser 和 usage 文案；本报告只把 `main.cpp` 里的直接死面计入清单。

### 2.4 `runner/libs/`

结论：

- 完全未被 import 的模块只有一个：`runner/libs/attach.py`。
- 另有一批 helper 在仓内没有任何调用者，已经可以视为真正死函数。

#### 完全未被 import 的模块

`runner/libs/attach.py` 整个模块无任何 import 方，整文件 `860` 行都可以视为死代码。

| 符号 | 行号 | 行数 |
| --- | --- | --- |
| `PerfEventAttr` | `73-98` | `26` |
| `_libc` | `101-107` | `7` |
| `libc` | `113-117` | `5` |
| `tracepoint_id` | `124-136` | `13` |
| `attach_tracepoint` | `139-187` | `49` |
| `_kprobe_pmu_type` | `194-199` | `6` |
| `attach_kprobe` | `202-258` | `57` |
| `attach_cgroup_sysctl` | `265-296` | `32` |
| `detach_cgroup_sysctl` | `299-311` | `13` |
| `attach_raw_tracepoint` | `318-347` | `30` |
| `_bpf_link_create` | `354-387` | `34` |
| `attach_fentry` | `390-396` | `7` |
| `attach_fexit` | `399-405` | `7` |
| `attach_lsm` | `408-414` | `7` |
| `attach_perf_event` | `417-468` | `52` |
| `attach_cgroup_skb` | `471-505` | `35` |
| `detach_cgroup_skb` | `508-525` | `18` |
| `attach_socket_filter` | `528-546` | `19` |
| `parse_section_attach_info` | `563-796` | `234` |
| `bpf_obj_get` | `799-827` | `29` |
| `managed_attachments` | `831-840` | `10` |

#### 其他全仓库无引用函数

| 文件 | 符号 | 行号 | 行数 | 结论 |
| --- | --- | --- | --- | --- |
| `runner/libs/batch_runner.py` | `write_batch_spec` | `117-119` | `3` | 无调用者 |
| `runner/libs/commands.py` | `build_micro_benchmark_command` | `84-141` | `58` | pre-batch 时代遗留，当前统一走 `run_batch_runner()` |
| `runner/libs/corpus.py` | `write_json_output` | `394-396` | `3` | ArtifactSession 取代 |
| `runner/libs/corpus.py` | `write_text_output` | `399-401` | `3` | ArtifactSession 取代 |
| `runner/libs/corpus.py` | `parse_runner_json` | `404-405` | `2` | 无调用者 |
| `runner/libs/corpus.py` | `text_invocation_summary` | `477-484` | `8` | 无调用者 |
| `runner/libs/results.py` | `parse_command_samples` | `168-169` | `2` | 无调用者 |
| `runner/libs/run_artifacts.py` | `extract_daemon_debug_details` | `340-375` | `36` | 没有调用者，现有路径直接用 `externalize_sample_daemon_debug()` |
| `runner/libs/rejit.py` | `enumerate_program_record` | `140-151` | `12` | 无调用者 |
| `runner/libs/repo_registry.py` | `resolve_repo_inventory` | `25-26` | `2` | 无调用者 |
| `runner/libs/profiler.py` | `_run_perf_collection` | `163-195` | `33` | 私有 helper，但 `profile_programs()` 已经自己展开线程池逻辑 |
| `runner/libs/profiler.py` | `render_profile_json` | `500-501` | `2` | 无调用者 |

### 2.5 `e2e/run.py` + `e2e/cases/`

结论：

- 没有 dead case。`tracee`、`tetragon`、`bpftrace`、`scx`、`katran`、`bcc` 六个 case 都在 `CASE_SPECS` 中，`vm-e2e` 跑的是 `python3 e2e/run.py all`，会执行全部 case。
- 但有一个明确的 dead feature：`--katran-policy`。

#### dead code / 无效 feature 清单

| 类型 | 符号 | 行号 | 行数 | 结论 |
| --- | --- | --- | --- | --- |
| 无效 feature | `DEFAULT_KATRAN_POLICY_FILE` | `40` | `1` | 只被 `--katran-policy` 默认值引用 |
| 无效 feature | `--katran-policy` | `150` | `1` | 参数被解析，但后续没有任何 case 消费 |
| 未使用资产 | `e2e/cases/katran/balancer_ingress.e2e.policy.yaml` | 整文件 | `24` | 没有运行路径读取它 |

## 3. 可删除总行数估算

先给保守口径，只统计我已经确认的死面。

### 3.1 全仓库无引用

- `runner/libs/attach.py`：`860` 行
- `runner/libs/` 其他死函数：`164` 行
- `micro/driver.py` 的 unused import：`1` 行
- `corpus/modes.py` 的 unused import：`3` 行
- `e2e/run.py` 的 `katran-policy` 死 feature：`2` 行

小计：`1030` 行代码

### 3.2 当前 vm-* 主路径无调用

- `corpus/modes.py` linear modes：`404` 行
- `runner/src/main.cpp` keep-alive + 单次 run 分支：`68` 行
- `micro/driver.py` 的 `--rejit` 无效 feature：`8` 行

小计：`480` 行代码

### 3.3 合计

- 保守代码总量：约 `1510` 行
- 另外还有 `katran` 未使用 YAML 资产：`24` 行

说明：

- 这个 `1510` 行没有把 keep-alive 配套的 `runner/src/common.cpp` request parser 一起算进去；如果 keep-alive 真删，实际可删行数会更高。
- 这个 `1510` 行也没有把 `policy_path/policy_mode` 这类 v1 schema baggage 记成“可直接删除”，因为它们还在结果 JSON 里出现，清理时需要一起处理 schema 兼容。

## 4. 建议的清理方案

建议按三批做，先删“确定死”的，再删“当前主路径不用”的，最后收 schema。

### 第一批：确定死代码，低风险直接删

- 删掉整个 `runner/libs/attach.py`。
- 删掉 `runner/libs/commands.build_micro_benchmark_command()`。
- 删掉 `runner/libs/batch_runner.write_batch_spec()`。
- 删掉 `runner/libs/corpus.py` 里四个已死 helper：
  - `write_json_output`
  - `write_text_output`
  - `parse_runner_json`
  - `text_invocation_summary`
- 删掉 `runner/libs/results.parse_command_samples()`。
- 删掉 `runner/libs/run_artifacts.extract_daemon_debug_details()`。
- 删掉 `runner/libs/rejit.enumerate_program_record()`。
- 删掉 `runner/libs/repo_registry.resolve_repo_inventory()`。
- 删掉 `runner/libs/profiler._run_perf_collection()` 和 `render_profile_json()`。

### 第二批：按“当前 benchmark 框架只保留 vm-* 主路径”收口

- 从 `corpus/driver.py` 移除 `tracing` / `perf` / `code-size` 三个 mode。
- 删掉 `corpus/modes.py` 的 linear-mode 整段实现。
- 删除 `micro/driver.py` 的 `--rejit` flag，把 REJIT 选择彻底收口到 runtime 名称。
- 删除 `e2e/run.py` 的 `--katran-policy`，同时删掉 `e2e/cases/katran/balancer_ingress.e2e.policy.yaml`。

### 第三批：收掉 v1 遗留和重复 scaffolding

- 把 `corpus/modes.py` 里的 `policy_path` 从 record schema 和 guest payload 里移除。
- 评估 `policy_mode` 是否重命名成更符合现在语义的字段，例如 `apply_mode`。
- 抽一个共享的 artifact/session helper，消除 `packet_main()` 和 `run_linear_mode()` 那一大块重复逻辑。
- 若确认 keep-alive 不再需要，再顺手删掉 `runner/src/main.cpp` keep-alive 分支和配套 parser。

## 5. 清理前需要确认的两点

- `tracing` / `perf` / `code-size` 三个 corpus mode 是否还有人工使用场景；如果只是“以后可能会用”，更合理的做法是挪到 `experimental/`，而不是继续挂在正式框架里。
- `micro_exec` 单次 `run-llvmbpf` / `run-kernel` / `run-kernel-attach` 是否还有仓外脚本在依赖；如果没有，可以和 keep-alive 一起收口，只保留 `run-batch` 和 `list-programs`。

## 6. 总结

这个 benchmark 框架的 dead surface 主要集中在三块：

- `runner/libs/attach.py` 这一整个废弃 Python attach 层；
- `corpus` 的三种 linear mode，它们已经不在 `vm-*` 主路径里；
- `micro` / `e2e` 里少量仍保留但已经不生效的 CLI feature。

保守口径下，可以删掉约 `1510` 行代码外加 `24` 行未使用 YAML 资产；如果继续把 keep-alive 的配套解析代码一起清掉，实际减量会更大。
