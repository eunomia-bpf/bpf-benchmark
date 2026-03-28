# BpfReJIT E2E / Corpus Code Review

日期：2026-03-28

范围：
- `e2e/run.py`
- `e2e/case_common.py`
- `e2e/cases/{tracee,tetragon,katran,bcc,bpftrace,scx}/case.py`
- `corpus/modes.py`
- `corpus/driver.py`
- `corpus/config/benchmark_config.yaml`
- `corpus/config/macro_corpus.yaml`（抽样检查）
- `runner/libs/rejit.py`
- `runner/libs/results.py`
- `runner/src/kernel_runner.cpp`
- `runner/src/batch_runner.cpp`

本次是纯 review，没有修改业务代码，也没有运行内核/BPF 相关测试。

## Executive Summary

- 结论：代码主路径已经具备可用的 benchmark 框架，但 E2E 失败语义、corpus v2 参数接线、`enabled_passes` 空列表语义、daemon 启动可靠性这几处仍会直接影响结果可信度。
- 严重级别统计：`CRITICAL x1`，`HIGH x3`，`MEDIUM x4`，`LOW x4`
- 跨文件一致性结论：
  - `speedup_ratio` 方向是一致的，都是 `baseline / rejit`，未发现反向计算。
  - pass 名从 `benchmark_config.yaml` 到 Python driver，再到 daemon socket 请求，正常非空列表路径下基本一致。
  - `enabled_passes` 的 `None` / `[]` / `list[str]` 语义不一致，是本轮最明显的数据流 bug。
  - runner JSON 总体结构大体一致，但 Python “canonical schema” 已经开始落后于 C++ 实际输出。

## 主要问题

### [CRITICAL] E2E 会把真实失败降级成 `skipped` / `ok`，suite 还能继续报成功

影响：
- 真实的 loader / daemon / attach / case runtime 失败，可能不会让 E2E suite fail。
- 结果文件会被写成 `completed`，从 artifact 视角看像一次合法 benchmark，而实际上可能根本没跑完。

证据：
- `tracee` 在 case 顶层把任何异常都包装成 `skip_payload(...)`，直接返回 `status: "skipped"`：`e2e/cases/tracee/case.py:926-935`
- `tetragon` 也是同样模式：`e2e/cases/tetragon/case.py:1013-1040`
- `tetragon` 甚至在 agent 已经退出后，仍然构造 `status: "ok"` 的 payload，只是加 limitation，并把 `rejit_result` 填成未应用：`e2e/cases/tetragon/case.py:903-945`
- `scx` 捕获所有异常后只记录 `loader_error` 和 limitation，最终 payload 连 `status` 字段都没有：`e2e/cases/scx/case.py:703-744`
- 统一调度层 `_run_single_case()` 只要拿到了 payload 就会把 artifact 标成 `completed`：`e2e/run.py:299-323`
- `all` 模式只在抛异常时才把 case 记为失败；`skipped` 只打印 `SKIP`，不会 fail suite：`e2e/run.py:366-379`

建议：
- case 内部不要把“运行失败”伪装成 `skipped`。
- 明确区分三种状态：`ok`、`skipped`、`error`。
- `e2e/run.py` 应该把 `status != ok` 的 payload 当成失败，除非是预期、显式、可审计的 skip。

### [HIGH] corpus v2 路径解析了 `--blind-apply` / `--skip-families`，但执行时完全没有接线

影响：
- CLI、报告 metadata、markdown notes 都在宣称“本次跑法用了某种 REJIT policy”，但当前 strict/v2 执行路径实际上没有使用这些参数。
- 这会直接污染 debugging / ablation / policy 实验结论。

证据：
- CLI 确实定义了这两个参数：`corpus/modes.py:315-323`
- `run_guest_batch_mode()` 只从 benchmark config 读取 `enabled_passes`，然后把它传给 `run_objects_locally_batch()`；这里完全没有使用 `args.skip_families` 或 `args.blind_apply`：`corpus/modes.py:1279-1317`
- 当前 v2 计划构建函数只接收 `enabled_passes`，没有 policy mode / skip family 的入口：`corpus/modes.py:1653-1850`
- 结果 JSON 和 artifact metadata 却仍然把这两个字段写出去：`corpus/modes.py:2923-2924`, `corpus/modes.py:2974-2975`
- markdown notes 还显式说明了 `--blind-apply` 的行为：`corpus/modes.py:2829-2833`

建议：
- 要么把 `blind_apply` / `skip_families` 接进 v2 job spec、guest batch、runner/daemon 请求链路。
- 要么在 v2 完成前移除这些 CLI / metadata / notes，避免结果自我描述与真实执行不一致。

### [HIGH] `enabled_passes=[]` 的语义在 corpus batch / C++ runner 边界上丢失

影响：
- “显式零 pass” 与 “未指定，走 daemon 默认 pass” 无法区分。
- 这会让 zero-pass baseline / ablation 误跑成默认 pass 集，结果方向性错误。

证据：
- Python socket 路径会无条件发送 `enabled_passes`，即使是空列表也会带上：`runner/libs/rejit.py:503-509`
- `apply_daemon_rejit()` 也明确把 `enabled_passes is not None` 视为走 socket/serve 模式：`runner/libs/rejit.py:593-615`
- 但 corpus job 构建时只有 truthy 才写字段，空列表会被直接丢掉：`corpus/modes.py:807-810`
- `kernel_runner.cpp` 只有 `!enabled_passes.empty()` 时才把 `enabled_passes` 写进请求：`runner/src/kernel_runner.cpp:1662-1675`
- `batch_runner.cpp` 也是同样逻辑：`runner/src/batch_runner.cpp:730-742`

建议：
- 在所有层统一约定：
  - `None` = 未指定，daemon 自己选默认。
  - `[]` = 显式零 pass。
  - `["..."]` = 显式 pass 列表。
- job spec 和 C++ 请求构造都应保留“字段存在但为空数组”的语义。

### [HIGH] corpus 的 daemon 启动方式脆弱且无诊断信息，容易出现启动 race

影响：
- daemon 刚起时 socket 未就绪，首个 optimize 很容易偶发失败。
- stdout/stderr 全部重定向到 `DEVNULL`，定位 guest 侧问题成本很高。

证据：
- `corpus/modes.py` 里的 `start_daemon_server()` 只是 `Popen(..., DEVNULL)` 后固定 `sleep(0.5)`：`corpus/modes.py:606-616`
- 同模块的 `stop_daemon_server()` 也只做进程终止和 socket 删除，没有任何失败上下文：`corpus/modes.py:619-629`
- 仓库里已经存在更可靠的实现：`runner/libs/rejit.py::_start_daemon_server()` 会等待 socket 真正出现，并在提前退出/超时时回传 daemon log tail：`runner/libs/rejit.py:441-479`

建议：
- 不要维护两套 daemon 启动逻辑。
- 直接复用或移植 `runner/libs/rejit.py` 的启动/停止实现，保留日志文件和超时错误。

### [MEDIUM] `--capture-maps` 在 tracee / tetragon / katran 上当前基本是自我跳过

影响：
- 用户显式打开 map capture 时，产物看起来“支持了”，但实际上大多数情况下会得到 `status: skipped`。
- 这会让 fixture 采集路径处于表面可用、实际无效的状态。

证据：
- `capture_map_state()` 会先根据 `optimize_results` 中“确实有 applied sites 或 inlined entries 的程序”筛选目标；如果筛完为空，就直接返回 `status: "skipped"`：`e2e/case_common.py:157-207`
- `tracee` 调用时把 `optimize_results={}` 传进去：`e2e/cases/tracee/case.py:886-904`
- `tetragon` 同样传 `{}`：`e2e/cases/tetragon/case.py:873-891`
- `katran` 也是 `{}`：`e2e/cases/katran/case.py:2237-2253`

建议：
- 把 `apply_daemon_rejit(...).per_program` 或其他真实 apply 结果接给 `capture_map_state()`。
- 如果当前 case 暂不支持 map capture，就在 CLI 或 payload 里明确标 unsupported，不要伪装成“运行后 skipped”。

### [MEDIUM] 两个 C++ runner 都在手写 JSON parser，逻辑脆弱且重复

影响：
- daemon 返回里的字符串一旦包含转义引号、换行、`[]` 内容等，解析很容易截断。
- 这类 bug 最先损坏的是错误信息和 debug 信息，排查时最痛苦。

证据：
- `kernel_runner.cpp` 的 `extract_json_string()` 直接找下一个 `"` 作为字符串结束，不处理转义：`runner/src/kernel_runner.cpp:1400-1416`
- `extract_json_string_array()` 直接找第一个 `]`，再用成对引号扫元素，同样不处理转义：`runner/src/kernel_runner.cpp:1533-1564`
- `batch_runner.cpp` 复制了几乎同一套实现：`runner/src/batch_runner.cpp:465-486`, `runner/src/batch_runner.cpp:602-639`

建议：
- 用统一 JSON 库或已有 helper 解析 daemon socket 返回。
- 至少把解析代码收敛到一个共享实现，不要继续双份维护。

### [MEDIUM] Python 侧“canonical ReJIT schema”已经和 C++ 实际输出开始漂移

影响：
- `runner/libs/results.py` 名义上是“所有 driver 共用的规范化 schema”，但它已经不是单一真相来源。
- 后续只要字段再演化一次，很容易出现 driver 侧静默漏字段。

证据：
- `RejitSummary` 声明了 `pass_details`、`daemon_response`：`runner/libs/results.py:35-50`
- `_default_rejit()` 却没有给这两个字段默认值，docstring 还写着“all canonical fields”：`runner/libs/results.py:156-170`
- C++ runner 实际上会输出 `pass_details`、`daemon_response`，还可能输出 `daemon_debug_stripped`：`runner/src/common.cpp:950-973`
- Python `RejitSummary` 并没有声明 `daemon_debug_stripped`：`runner/libs/results.py:35-50`

建议：
- 给 runner JSON 做一份真实的 schema fixture / round-trip test。
- 让 C++ 输出字段和 Python 规范化类型定义同源，避免“类型定义看起来规范，真实 wire format 另算”。

### [MEDIUM] `bcc` / `bpftrace` 没有复用共享持久化逻辑，而且 cleanup 错误被吞掉

影响：
- E2E 输出行为在不同 case 之间不一致。
- 清理/收尾异常不会进入 payload 或 artifact，后续定位过程信息丢失。

证据：
- 仓库已经有共享 `persist_results()`：`e2e/case_common.py:319-331`
- `bcc` 仍然手写 `write_json` / `write_text` 输出：`e2e/cases/bcc/case.py:861-877`
- `bpftrace` 也一样：`e2e/cases/bpftrace/case.py:733-748`
- `bcc.finalize_process_output()` 里有裸 `except Exception: pass`：`e2e/cases/bcc/case.py:348-357`
- `bpftrace.finalize_process_output()` 里也有广义异常吞掉：`e2e/cases/bpftrace/case.py:312-324`

建议：
- 对齐到统一的持久化 / artifact 行为。
- cleanup 允许降级，但至少要把异常转成可见的 warning 字段，不要完全吞掉。

## 死代码与组织问题

### [LOW] 确认存在未使用 import

`pyflakes` 可直接复现以下未使用 import：
- `e2e/cases/tracee/case.py:49` `git_sha`
- `e2e/cases/tetragon/case.py:48` `git_sha`
- `e2e/cases/tetragon/case.py:48` `relpath`
- `e2e/cases/katran/case.py:42` `git_sha`
- `e2e/cases/bcc/case.py:28` `which`
- `e2e/cases/bcc/case.py:58` `git_sha`
- `e2e/cases/bpftrace/case.py:39` `run_file_open_load`
- `e2e/cases/bpftrace/case.py:47` `git_sha`
- `e2e/cases/scx/case.py:35` `git_sha`

### [LOW] 有几处高概率 dead code / 旧路径残留

`rg` 未找到站内调用点的 helper：
- `e2e/cases/katran/case.py:206` `extract_request_latencies`
- `e2e/cases/katran/case.py:1294` `KatranDsrTopology.ipip_stats`
- `e2e/cases/katran/case.py:1854` `run_warmup_requests`
- `e2e/cases/katran/case.py:1916` `execute_http_measurement_loop`
- `corpus/modes.py:541` `resolve_target_name`
- `corpus/modes.py:1150` `run_targets_locally_batch`
- `corpus/modes.py:1637` `attach_trigger_unsupported_reason`
- `corpus/modes.py:2597` `build_summary`

其中 `corpus/modes.py` 这几项明显带有旧 batch/v1 路径残影。

### [LOW] God File 问题明显，职责分层偏弱

按 `wc -l` 统计，以下文件已经明显超出“单文件可维护 review 范围”：
- `e2e/cases/katran/case.py` 2408 行
- `corpus/modes.py` 3085 行
- `runner/src/kernel_runner.cpp` 4340 行
- `runner/src/batch_runner.cpp` 1962 行
- `e2e/cases/tetragon/case.py` 1076 行
- `e2e/cases/tracee/case.py` 995 行

建议：
- `corpus/modes.py` 至少拆成：manifest/config、plan builder、guest orchestration、summary/report。
- `kernel_runner.cpp` / `batch_runner.cpp` 应共享 daemon client、JSON parsing、result serialization。
- `katran` case 已经同时承担 topology、session、measurement、markdown/report，应该拆模块。

### [LOW] `runner/libs/results.py` 里还有一些未被当前 review 范围主路径使用的 helper

高概率未进入当前主路径的符号包括：
- `runner/libs/results.py:78` `UnifiedResultRecord`
- `runner/libs/results.py:99` `load_json`
- `runner/libs/results.py:152` `parse_command_samples`

建议和上面的死代码清理一起做，避免“看起来是公共入口，实际上没人依赖”的错觉。

## 跨文件一致性检查结论

### 已确认一致

- `speedup_ratio` 方向一致：
  - `e2e/case_common.py:308-312` 返回 `before / after`
  - `corpus/modes.py:681-694` 返回 `baseline_ns / rejit_ns`
- benchmark pass 配置入口一致：
  - `corpus/config/benchmark_config.yaml:8-46`
  - `corpus/modes.py:216-241`
  - `runner/libs/rejit.py:37-79`

### 已确认不一致

- `enabled_passes` 的 `None` / `[]` / `list[str]` 语义不一致，见上文 `[HIGH]`。
- Python 规范化 schema 与 C++ 实际输出字段有轻度漂移，见上文 `[MEDIUM]`。

## 可靠性结论

- 当前 strict corpus v2 路径没有明显 batch race：
  - 计划里 `max_parallel_jobs` 固定为 `1`：`corpus/modes.py:1844-1849`
  - `batch_runner` 主循环也按 spec 串行执行非 parallel job：`runner/src/batch_runner.cpp:1875-1945`
- `macro_corpus.yaml` 抽样未见明显 schema 错误：
  - `programs: []` 的对象同时标了 `allow_object_only_result: true`，与 resolver 逻辑匹配：`corpus/config/macro_corpus.yaml:4695-4709`, `corpus/modes.py:1577-1602`
- `corpus/driver.py` 只是薄封装入口，本身没有明显问题：`corpus/driver.py:1-19`

## 优先级建议

建议按这个顺序处理：

1. 先修 E2E 的失败语义，让 `error` 不能伪装成 `skipped/ok`。
2. 再修 `enabled_passes` 空列表语义，保证 ablation / zero-pass 数据可信。
3. 把 `blind_apply` / `skip_families` 接入 v2 主路径，或暂时下线这些选项。
4. 统一 daemon 启动和 socket client 逻辑，删除 corpus 里的脆弱重复实现。
5. 最后再做 dead code / God File 拆分，这属于重要但不最紧急的工程治理项。
