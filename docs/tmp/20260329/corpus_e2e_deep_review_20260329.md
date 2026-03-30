# Corpus / E2E Deep Review (2026-03-29)

## 直接结论

- `corpus/orchestrator.py`：现在已经做对了两件关键事。
  - `corpus/orchestrator.py:150-164` 会先按 `program.measurement` 把 object 拆成 execution unit。
  - `corpus/orchestrator.py:167-201` 会按 loader instance identity 分组 app-native 单元。
  - 所以“是否按 loader instance 分组”的答案是：**是，基本符合**。
- `corpus/driver.py`：不是主逻辑，只是 CLI shim，直接转发到 `corpus.orchestrator.main()`。
  - 证据：`corpus/driver.py:11-15`
- `corpus/modes.py`：**当前工作树里已经不存在**，不是漏看。
  - 证据：`ls corpus` 仅有 `driver.py` / `orchestrator.py`；`nl corpus/modes.py` 直接报 `No such file or directory`
- `corpus/config/benchmark_config.yaml`：**还需要**，因为当前 corpus/e2e 仍通过 `benchmark_rejit_enabled_passes()` 读取 pass policy。
  - 证据：`runner/libs/rejit.py:370-392`、`corpus/orchestrator.py:492`、`e2e/case_common.py:593-596`
  - 但它里面的 `output_json` / `output_md` / `iterations` / `warmups` 已明显混入旧 driver 语义，不再是纯 daemon/pass policy 配置。

## 新设计原则对照

- 原则 1「所有程序必须用原生 app 加载，禁止 `bpftool loadall` 替代」：**不通过**
  - Katran shared runner 和 Katran case 仍然直接 `bpftool prog loadall`
- 原则 2「Corpus 和 E2E 共享同一套 app runner，只是采集不同指标」：**部分通过**
  - shared runner 已存在，但很多 case 仍自己持有 workload/measurement 逻辑
- 原则 3「生命周期单元是 loader instance」：**Corpus 通过，E2E 部分不通过**
  - corpus 已按 loader instance 分组
  - e2e 仍在 lifecycle helper 里 per-run 启 daemon / load module
- 原则 4「三维度：Loader × Workload × Measurement」：**不通过**
  - YAML 和 Python schema 没把 workload 作为一等维度建模
- 原则 5「App runner 自包含，不 import e2e」：**通过**
  - 本次检查中未发现 `runner/libs/app_runners/*` 反向 import `e2e`
- 原则 6「零 silent failure」：**不通过**
  - `except: pass`、`|| true`、fallback workload、`skipped` 降级仍大量存在
- 原则 7「Daemon session 级启动一次」：**Corpus 基本通过，E2E 不通过**
  - e2e 的共享 lifecycle helper 仍每次自己起 daemon

## 覆盖说明

- 已逐个检查用户列出的全部路径。
- 唯一的例外是 `corpus/modes.py`：该路径在当前工作树中已被删除，因此结论是“路径已不存在”，不是“未检查”。
- 额外确认：
  - `runner/libs/commands.py` 仍在被 `runner/libs/object_discovery.py` 使用，不是死代码。
  - `runner/src/common.cpp` 仍承载 `test-run` / `list-programs` CLI，不属于死文件。
  - `runner/CMakeLists.txt` 本身问题不大，但它证明了 `runner/src/batch_runner.cpp` 未被编译。

## CRITICAL

### 1. E2E 仍在每个 lifecycle 内部启动 daemon，并重复做 kinsn module loader
- 文件：`e2e/case_common.py:570-598`
- 关联文件：`runner/Makefile:84,336,356`
- 问题：
  - `run_case_lifecycle()` 在 baseline 之后、scan/apply 之前直接调用 `_run_kinsn_module_loader()` 和 `DaemonSession.start()`。
  - 这把 daemon 和 module lifecycle 绑到了单次 case lifecycle 上，而不是 benchmark session。
  - `runner/Makefile` 还通过 `VM_INIT` 给每次 VM 命令都隐式拼上 `module/load_all.sh`，进一步强化了“每次命令都重做一次环境初始化”的旧路径。
- 修复建议：
  - 把 daemon session 和 kinsn module 预热提升到 `e2e/run.py` 或统一 benchmark session 层。
  - `run_case_lifecycle()` 只接收已启动的 session handle，不再自己启动/关闭 daemon。
  - VM helper 不要给每条命令隐式拼 module loader。

### 2. Katran 并没有使用原生 app loader，而是继续走 `bpftool prog loadall`
- 文件：`runner/libs/app_runners/katran.py:72-91`
- 关联文件：`runner/libs/app_runners/katran_support.py:661-676`
- 关联文件：`e2e/cases/katran/case.py:1401-1423`
- 问题：
  - `KatranRunner.start()` 创建的是 `KatranDirectSession`。
  - `KatranDirectSession.__enter__()` 直接执行 `bpftool prog loadall ... pinmaps ...`。
  - `e2e/cases/katran/case.py` 还保留了一套本地 `KatranDirectSession`，再次直接 `loadall`。
  - 这直接违反新原则 1，也使“shared app runner”名不副实。
- 修复建议：
  - 用真正的 Katran userspace loader/session 替换 direct session。
  - 如果还需要 direct `TEST_RUN` 或 fixture 逻辑，单独放到 test-only helper，不要冒充 app-native runner。

### 3. 多处 setup / workload 失败被降级成继续执行或 fallback，基准语义会被改变
- 文件：`runner/Makefile:177-189`
- 关联文件：`e2e/cases/katran/case.py:1948-1964`
- 关联文件：`runner/libs/workload.py:150-225,302-313,695-721`
- 问题：
  - `e2e-tracee-setup` / `e2e-tetragon-setup` 用了 `|| true`，明确吞 setup failure。
  - Katran case 在 setup non-zero 后只记 `limitations`，继续跑；`wrk` 不可用时切到 Python client；这会改变吞吐指标含义。
  - workload 库在 `stress-ng` / `curl` / scheduler load 缺失或失败时，静默切到别的 workload 实现。
  - 这完全违背“零 silent failure / no fallback”。
- 修复建议：
  - 所有 setup failure 一律 hard fail。
  - workload driver 必须显式、可验证；缺依赖时直接失败，不允许替换 workload。
  - Katran 的 traffic generator 必须固定为一个明确、可复现实验路径。

### 4. ReJIT 失败被编码成 `skipped` 或 synthetic result，而不是 suite failure
- 文件：`e2e/case_common.py:525-568,606-607`
- 关联文件：`e2e/cases/tetragon/case.py:776-786`
- 问题：
  - `before_baseline` / `before_rejit` 返回 abort 时，helper 会写出 `status="skipped"` 的 metadata。
  - `skip_rejit_reason` 会生成一个假的 `rejit_result = {"applied": False, ...}`，而不是硬失败。
  - Tetragon case 还显式把 agent exit 变成“aborting scan and ReJIT after the baseline phase”。
  - 这会把真实 benchmark failure 伪装成可接受的“跳过”。
- 修复建议：
  - benchmark-required phase 一律用 hard error 终止 case。
  - 只保留极少数真正 optional 的观察性 artifact 为 `skipped`。
  - `run_case_lifecycle()` 不要再生成 synthetic `rejit_result`。

## HIGH

### 5. Corpus manifest/schema 仍未把 Workload 作为一等维度建模
- 文件：`corpus/config/macro_corpus.yaml:1-27,33`
- 关联文件：`runner/libs/corpus.py:18-20,151-176`
- 问题：
  - 当前 schema 有 `measurement`、有限的 `loader` 字段，但没有 `workload` 维度。
  - 结果是 workload 被硬编码在 runner/case 里，而不是 manifest 驱动。
  - `compile_loader: bpftool_loadall` 这种字段名也在持续泄漏旧架构语义。
- 修复建议：
  - 在 manifest 中引入显式 `workload` / `workloads`。
  - Loader instance 要能直接携带 loader 配置和 workload 配置。
  - `compile_loader` 若不再承担 runtime orchestration 含义，应删除或重命名。

### 6. `corpus/orchestrator.py` 仍然过度了解各 repo 的 runner 构造细节，不够“thin”
- 文件：`corpus/orchestrator.py:252-377`
- 问题：
  - orchestrator 里仍有一整块 `_runner_kwargs_for_repo()` 的 repo switch。
  - 这意味着编排层仍然知道 BCC/Tracee/Katran/Tetragon/Bpftrace/SCX 的构造参数形状。
  - 新设计要求 orchestrator 只做 Loader × Workload × Measurement 编排，而不是 repo adapter。
- 修复建议：
  - 把 repo-specific kwargs 组装挪到 runner registry/factory。
  - orchestrator 只传统一的 loader instance descriptor。

### 7. `e2e/run.py` 仍是大一统 parser，携带旧参数和 case-specific 补丁逻辑
- 文件：`e2e/run.py:135-205`
- 关联文件：`e2e/cases/katran/case.py:1881-1882`
- 问题：
  - 所有 case 的参数都堆在一个 parser 里，`apply_case_defaults()` 还要二次补丁。
  - `--katran-skip-attach` 仍暴露在全局 CLI，但 Katran case 运行时直接拒绝该参数。
  - 这类“参数存在但逻辑已废弃”的状态会持续制造误导。
- 修复建议：
  - 为每个 case 建 subparser 或 case-local parser fragment。
  - 删除 runtime 明确不支持的参数。
  - 只保留跨 case 真正共享的选项在顶层入口。

### 8. Shared runner 虽然存在，但 workload ownership 仍然被 case 和 runner 分裂持有
- 文件：`e2e/cases/tracee/case.py:503-507,1401-1421`
- 关联文件：`e2e/cases/tetragon/case.py:204-250`
- 关联文件：`e2e/cases/scx/case.py:135-137`
- 关联文件：`runner/libs/app_runners/tracee.py:57,129-132`
- 关联文件：`runner/libs/app_runners/tetragon.py:60-61,133-136`
- 关联文件：`runner/libs/app_runners/scx.py:42,63-68`
- 问题：
  - case 侧频繁直接改 `runner.workload_spec`，甚至在 Tracee 里会绕过 runner 直接调用 `run_tracee_workload()`。
  - 这导致 Loader 和 Workload 不是两个清晰维度，而是互相渗透的 mutable state。
  - “Corpus 和 E2E 共享同一套 runner”在接口层还没有落地为稳定 contract。
- 修复建议：
  - runner API 改成 `run_workload(workload, duration)` 这种显式参数接口。
  - 删除 runner 内部 mutable `workload_spec`。
  - 对 app-native path，case 不再直接调用 workload helper。

### 9. Katran case 与 `katran_support.py` 大量重复，shared runner 实际上没有共享起来
- 文件：`e2e/cases/katran/case.py:600,1376,1673`
- 关联文件：`runner/libs/app_runners/katran_support.py:91,661,792`
- 问题：
  - 两边都定义/保留了 `bpftool_binary`、`KatranDirectSession`、`run_parallel_http_load`、network namespace/topology 辅助等。
  - 这不是轻微重复，而是整套 support stack 双份维护。
  - 结果是 case 修一处、runner 漏一处，行为极易分叉。
- 修复建议：
  - 只保留一套 Katran support 层。
  - case 只调 shared runner/support，不再重写 direct session 和流量逻辑。

### 10. SCX case 仍保留旧的 raw-bpftool 探测和 host/guest 双路径
- 文件：`e2e/cases/scx/case.py:241-272,376-382,526-573`
- 关联文件：`runner/libs/vm.py:190-200`
- 问题：
  - case 里还在探测 `bpftool struct_ops register` 是否“可用”。
  - 同一文件同时带 `run_scx_case()` 和 `run_scx_vm()` 两条路径。
  - `runner/libs/vm.py` 又在 guest exec helper 里隐式插入 `module/load_all.sh`。
  - 这说明 host/guest 双路径和旧 raw path 残留还没有清干净。
- 修复建议：
  - VM transport 只放在顶层 harness。
  - raw bpftool probe 若只是诊断，挪到单独 debug 工具。
  - guest exec helper 不要再隐式改 benchmark 语义。

### 11. `benchmark_config.yaml` 不是死文件，但 schema 已经混合了“仍在用的 pass policy”和“旧 driver 默认值”
- 文件：`corpus/config/benchmark_config.yaml:1-6,8-21,39-48`
- 关联文件：`runner/libs/rejit.py:33,370-392`
- 关联文件：`corpus/orchestrator.py:492`
- 关联文件：`e2e/case_common.py:593-596`
- 问题：
  - 当前 corpus/e2e 只会消费 enabled passes。
  - 但 YAML 里还保留 `output_json` / `output_md` / `iterations` / `warmups` 等旧框架默认值。
  - 这让文件看起来像“半死不活的总配置”，职责不清。
- 修复建议：
  - 把 pass policy 单独拆成 daemon policy config。
  - 或反过来，把旧 output/iteration 字段从这里删掉，只保留当前仍有效的字段。

### 12. `e2e/case_common.py` 已经演化成新的“中心大文件”，职责再次膨胀
- 文件：`e2e/case_common.py:479-635`
- 问题：
  - 这个 helper 同时承载 lifecycle orchestration、daemon lifecycle、kinsn module 管理、skip policy、artifact metadata、map capture 挂载点。
  - import cycle 是修掉了，但复杂度被整体搬到了 `case_common.py`。
- 修复建议：
  - 至少拆成 `lifecycle.py`、`map_capture.py`、`daemon_benchmark_session.py` 三层。
  - `case_common.py` 应只保留真正通用的 case dataclass / render helper。

## MEDIUM

### 13. `runner/libs/corpus.py` 还残留 guest-batch / 旧 API 出口，且 `__all__` 已经不可信
- 文件：`runner/libs/corpus.py:227-241,776-777,868-879`
- 问题：
  - `sanitize_guest_batch_record()` 和 `packet_batch_timeout_seconds()` 明显是旧 batch 路径残留。
  - `__all__` 里导出了 `add_daemon_argument` / `add_filter_argument` 等一组根本不存在的函数。
- 修复建议：
  - 删掉 batch-only helper。
  - 修正 `__all__`，只导出真实仍被使用的符号。
  - 清理命名中的 `batch` / `guest_batch` 旧语义。

### 14. `runner/libs/rejit.py` 仍是 1034 行大杂烩，并保留“scan 时自动起 daemon”的旧 API
- 文件：`runner/libs/rejit.py:33-111,455-510,545-553,746-784`
- 问题：
  - 一个文件同时做 config 读取、policy 解析、daemon 进程管理、socket transport、scan/apply 结果规范化。
  - `scan_programs()` 在没有 socket 时会自己 `_start_daemon_server()`，这与 session-level daemon 设计相冲突。
  - `_scan_programs_via_socket()` 和 `_daemon_request()` 遇到错误时常返回 error dict，而不是直接 fail-fast。
- 修复建议：
  - 至少拆成 `policy.py`、`daemon_transport.py`、`scan_apply.py`。
  - corpus/e2e path 禁止调用 auto-start daemon API，只允许显式 session。

### 15. BCC / Bpftrace / Tracee / Tetragon / SCX 的 measurement scaffolding 大量重复
- 文件：`e2e/cases/bcc/case.py:129-176`
- 关联文件：`e2e/cases/bpftrace/case.py:153-190`
- 关联文件：`e2e/cases/tracee/case.py:482-560`
- 关联文件：`e2e/cases/tetragon/case.py:219-283`
- 关联文件：`e2e/cases/scx/case.py:108-158`
- 问题：
  - 都在做一套很像的“前采样 -> 起 CPU 线程 -> 跑 workload -> 后采样 -> 汇总”。
  - 差异主要只在额外指标，不足以 justify 五份手写实现。
- 修复建议：
  - 抽共享 measurement harness。
  - case 只提供 sampler / extra metrics / summary projector。

### 16. BCC / Tetragon 的 tool resolution 仍然强依赖 fallback discovery，而不是显式 loader config
- 文件：`runner/libs/app_runners/bcc.py:103-125`
- 关联文件：`e2e/cases/bcc/case.py:595-599`
- 关联文件：`runner/libs/app_runners/tetragon_support.py:16-23,52-55`
- 关联文件：`e2e/cases/tetragon/case.py:885-888`
- 问题：
  - BCC 会按 explicit -> env -> setup_result -> default dir 顺序兜底。
  - Tetragon support 的 `_bpftool_binary()` 也会退回到默认路径或 `"bpftool"`，`current_programs()` 还会在 payload 异常时返回空列表。
  - 这类 fallback 和“loader instance 应明确可配置”的方向相反。
- 修复建议：
  - loader instance 一旦解析完成，依赖路径就应固定。
  - 非法 payload 或缺失二进制都应直接失败。

### 17. `runner/libs/results.py` 仍然围绕旧 corpus-batch schema，且会静默丢弃坏 JSON
- 文件：`runner/libs/results.py:116-125,232-372`
- 问题：
  - `parse_json_lines()` 遇到 `JSONDecodeError` 直接 `continue`。
  - `summarize_corpus_batch_results()` 仍围绕 `baseline_compile` / `rejit_compile` / `baseline_run` / `rejit_run` 这种旧 batch schema。
- 修复建议：
  - 若当前路径仍需兼容旧结果，单独拆 `legacy_results.py`。
  - 解析失败至少要留下错误计数或报错，不应静默跳过。

### 18. `runner/src/batch_runner.cpp` 是死文件，而且 CMake 明确不编它
- 文件：`runner/src/batch_runner.cpp:1-6`
- 关联文件：`runner/CMakeLists.txt:37-44`
- 问题：
  - 文件本身只剩 TODO 注释。
  - `MICRO_EXEC_SOURCES` 不包含它。
- 修复建议：
  - 直接删除。
  - 如果想保留迁移说明，放进设计文档，不要保留成源码文件。

### 19. `runner/src/kernel_runner.cpp` 仍有 silent skip 和旧批处理残影
- 文件：`runner/src/kernel_runner.cpp:355-364,974-976`
- 问题：
  - Katran fixture map 找不到时只打印 `maps not found, skipping` 然后返回。
  - 这会把 fixture 破坏伪装成“没关系”的路径。
  - 文件顶部职责也依然偏大，仍残留对旧批处理时代的兼容影子。
- 修复建议：
  - fixture 缺失改成 hard error。
  - 继续把 per-object fixture 逻辑拆出去，保留一个最小 `TEST_RUN` 内核执行器。

### 20. 多个核心文件长度已经超过 300 行，且不是单一职责文件
- 文件：`e2e/cases/katran/case.py:1`（2209 行）
- 关联文件：`e2e/cases/tracee/case.py:1`（1631 行）
- 关联文件：`runner/src/kernel_runner.cpp:1`（1185 行）
- 关联文件：`runner/libs/rejit.py:1`（1034 行）
- 关联文件：`e2e/cases/tetragon/case.py:1`（1012 行）
- 关联文件：`runner/libs/corpus.py:1`（911 行）
- 关联文件：`runner/libs/app_runners/katran_support.py:1`（911 行）
- 关联文件：`e2e/case_common.py:1`（748 行）
- 关联文件：`runner/libs/workload.py:1`（757 行）
- 关联文件：`corpus/orchestrator.py:1`（719 行）
- 问题：
  - 这些文件都不是“单一大数据表”，而是实打实混了多种职责。
  - 继续在这些文件上迭代，只会把本次 review 里发现的问题放大。
- 修复建议：
  - 以职责切分，不以行数硬切。
  - 优先拆 measurement、lifecycle、report、support/topology、policy/config 几类。

## LOW

### 21. `corpus/driver.py` 只是兼容 shim，本身没有独立价值
- 文件：`corpus/driver.py:7-19`
- 问题：
  - 这是个纯转发入口，真实逻辑都在 `corpus/orchestrator.py`。
  - 不算死代码，因为 README / Make / 历史 artifacts 仍通过它进入。
- 修复建议：
  - 如果要保留 CLI 稳定性，可以继续保留。
  - 如果不需要兼容层，就让 Make/docs 直接调用 `corpus/orchestrator.py`。

### 22. `corpus/modes.py` 已从工作树删除，但文档/历史产物还在引用它
- 文件：`corpus/modes.py`（当前路径不存在）
- 关联文件：`docs/kernel-jit-optimization-plan.md:911`
- 问题：
  - review 清单和部分历史文档仍把它当成现存模块。
  - 这会误导后续 review / cleanup。
- 修复建议：
  - 更新 review checklist。
  - 在设计文档中明确标注该文件已退役。

### 23. `runner/libs/vm.py` 仍保留 tracee-specific 命名
- 文件：`runner/libs/vm.py:26-31`
- 问题：
  - 共享 guest script helper 仍使用 `tracee-e2e-guest-` 前缀。
  - 这是明显的命名泄漏。
- 修复建议：
  - 改成中性前缀，例如 `bpf-benchmark-guest-`。

### 24. `vm-corpus-new` 命名已经过时
- 文件：`Makefile:392-396`
- 关联文件：`runner/Makefile:338-346`
- 问题：
  - `vm-corpus-new` 现在仍然调用同一个 `corpus/orchestrator.py`。
  - “new” 已不再表达真实含义，只是在制造迁移残留。
- 修复建议：
  - 合并成一个 canonical `vm-corpus`。
  - 若需要特殊过滤器预设，用变量或专门 smoke/targeted target 表达。

### 25. `runner/libs/app_runners/__init__.py` 过度 eager-import，与当前 corpus/e2e 关注范围不匹配
- 文件：`runner/libs/app_runners/__init__.py:5-19,22-54`
- 问题：
  - shared factory 一次性 import 了很多当前 corpus/e2e review 范围之外的 runner。
  - 这会扩大 import surface，也让不相关 runner 的破损更容易影响 corpus/e2e 入口。
- 修复建议：
  - 改成 lazy registry，或在 `get_app_runner()` 内部局部 import。

## 没有发现明显问题但需要说明的文件

- `runner/libs/commands.py`
  - 仍被 `runner/libs/object_discovery.py` 使用，不是死代码。
- `runner/src/common.cpp`
  - 仍承担 `test-run` / `list-programs` CLI；本轮没有发现比 `batch_runner.cpp` 更明显的死代码问题。
- `Makefile`
  - 根层基本保持 thin，主要问题是命名残留，不是架构中心。
- `corpus/orchestrator.py`
  - 对照新设计，最重要的两项修复已经落地：measurement split 和 loader-instance grouping。

## 优先级建议

1. 先修 E2E session/daemon 生命周期，把 `e2e/case_common.py` 从“自己起 daemon”改成“消费外部 session”。
2. 直接重做 Katran 路径，删除所有 direct `bpftool loadall` app-native 冒充实现。
3. 全面清掉 fallback / `|| true` / `except: pass` / `skipped` 降级路径。
4. 再做 schema 收敛：把 workload 变成 manifest 一等维度，并把 `benchmark_config.yaml` / `runner/libs/rejit.py` 拆清楚。
