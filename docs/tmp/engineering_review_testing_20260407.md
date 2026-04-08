# bpf-benchmark 工程化 Review: Testing

本文件是 2026-04-07 某一轮 testing review 的历史快照，不是当前
canonical runner contract 或当前 active findings。当前有效的设计、todo、
和最新状态统一以 `docs/tmp/aws_arm64_remote.md` 为准。

日期：2026-04-07

范围：已逐个阅读以下范围内的文件内容，而不是只按文件名判断。

- `tests/python/`
- `tests/integration/`
- `tests/unittest/`
- `tests/negative/`
- `tests/helpers/`
- `corpus/driver.py`
- `e2e/driver.py`
- `micro/driver.py`
- `runner/libs/`
- 根 `Makefile` 的 test targets

评判基线：

- `docs/kernel-jit-optimization-plan.md:160-168` (`§4.6 Daemon 设计约束`)
- `docs/kernel-jit-optimization-plan.md:420-430` (`§5.6 框架架构`)
- `docs/kernel-jit-optimization-plan.md:641-655` (`§6.4`)
- `docs/kernel-jit-optimization-plan.md:697` (`#306: 删全部 v1 scanner/policy/directive 代码`)
- `docs/kernel-jit-optimization-plan.md:1016` (`#640: 删除 object-centric dead code / 旧测试`)
- `docs/kernel-jit-optimization-plan.md:1020` (`#644: BCC execsnoop 单独 rejit_passes 已删除；报告只统计 applied sites`)
- `docs/kernel-jit-optimization-plan.md:1022` (`#646: daemon 退化为薄壳，pipeline 外提`)

## 应删除

### 1. 删除 object/program 级 policy 层及其测试

- 文件：`runner/libs/rejit.py:168-403`，`runner/libs/case_common.py:300-359`，`runner/libs/case_common.py:396-433`，`runner/libs/case_common.py:538-545`，`runner/libs/case_common.py:672-694`，`corpus/driver.py:722-727`，`corpus/driver.py:880-933`，`e2e/cases/bcc/case.py:184-195`，`e2e/cases/scx/case.py:430-436`，`e2e/cases/tetragon/case.py:684-695`，`e2e/cases/tracee/case.py:1368-1375`，`tests/python/test_rejit.py:218-260`，`tests/python/test_rejit.py:282-322`，`tests/python/test_case_common.py:409-533`，`tests/python/test_e2e_driver.py:217-239`
- 问题：这里仍然按 `object/program/section/prog_type/has_sites` 做匹配，按 program 计算 pass，再按 pass tuple 拆分 `apply_rejit()`；结果里还回写 `effective_enabled_passes_by_program`。这与 `§5.6` 的“生命周期单元是 loader instance，不是 object/program”直接冲突，也与 `#306/#640` 已声明删除 v1 scanner/policy/directive/object-centric 代码不一致。
- 建议操作：删除整层 `policy`/`rejit_policy_context`/`effective_enabled_passes_by_program` 逻辑和对应 Python 测试；只保留 loader-instance 级 pass 选择与结果。

### 2. 删除 BCC per-tool `rejit_passes` 覆盖和对应测试

- 文件：`e2e/cases/bcc/case.py:56-65`，`e2e/cases/bcc/case.py:75-86`，`e2e/cases/bcc/case.py:490-632`，`tests/python/test_bcc_case.py:13-39`，`tests/python/test_bcc_case.py:41-63`，`tests/python/test_bcc_case.py:154-242`
- 问题：BCC case 仍支持 tool 级 `rejit_passes`、`tool_rejit_passes`、`tool_requested_rejit_passes`。`#644` 已明确写明 “BCC `execsnoop` 的单独 `rejit_passes` 缩窄配置已删除”。
- 建议操作：删除 `ToolSpec.rejit_passes`、config 解析、payload 中的 per-tool pass provenance，以及对应测试；BCC 跟其他 benchmark 一样走统一的 benchmark pass 入口。

### 3. 删除重复的 BPF stats 实现和重复测试

- 文件：`runner/libs/metrics.py:16-206`，`runner/libs/bpf_stats.py:11-187`，`tests/python/test_metrics.py:13-62`，`tests/python/test_bpf_stats.py:11-41`
- 问题：两套代码都在做 `libbpf` 加载、`bpf_enable_stats()`、`bpf_prog_get_fd_by_id()`、`bpf_prog_get_info_by_fd()` 和 stats 读取。测试也在重复覆盖 “FD 解析失败 / info 读取失败 / 关闭 FD / libbpf symbol 缺失” 这一类分支。
- 建议操作：保留一个 canonical stats 模块；删除 `metrics.py` 中重复的 stats 半段，或删除 `bpf_stats.py`，不要两套都留。测试也收敛成一份。

### 4. 删除无人调用的 integration 脚本和随之变成死代码的 helper

- 文件：`tests/integration/vm_comprehensive.sh:46-68`，`tests/integration/vm_comprehensive.sh:91-120`，`tests/integration/vm_comprehensive.sh:189-199`，`tests/integration/vm_comprehensive.sh:252-307`，`tests/integration/vm_daemon_live.sh:42-64`，`tests/integration/vm_daemon_live.sh:70-72`，`tests/helpers/Makefile:8-14`，`tests/helpers/hold_bpf_prog.c:1-45`
- 问题：这两个 shell integration 脚本没有任何 Makefile/runner 入口；`rg` 结果显示仓库内只有文档在提它们。两者都各自 copy 了一份 `daemon_request()`。`vm_daemon_live.sh` 是 `hold_bpf_prog` helper 的唯一消费者，因此脚本一旦删除，helper 也随之变成死代码。
- 建议操作：删除 `vm_comprehensive.sh`、`vm_daemon_live.sh`，并连带删除 `tests/helpers/Makefile` 与 `tests/helpers/hold_bpf_prog.c`；如果确实要保留 live serve 检查，应改成一个被 `Makefile`/runner 调用的单一入口，而不是散落的手工脚本。

### 5. 删除重复的 SCX repro 路径，保留一个 repo-owned 版本

- 文件：`tests/integration/scx_prog_show_race.py:15-24`，`tests/integration/scx_prog_show_race.py:42-88`，`tests/integration/scx_prog_show_race.py:103-169`，对照 `tests/negative/scx_prog_show_race.c:1-18`，`tests/negative/scx_prog_show_race.c:272-350`，`tests/negative/scx_prog_show_race.c:525-693`
- 问题：Python integration 脚本和 C negative test 在做同一件事：拉起 `scx_rusty` 后循环 `bpftool prog show` 复现 live crash path。runner 真正在执行的是 C 版本（`runner/scripts/run_all_tests.sh:197-205`，`runner/scripts/suite_entrypoint.sh:255`）；Python 版本没有任何测试入口，只剩文档引用。
- 建议操作：删除 `tests/integration/scx_prog_show_race.py`，保留 `tests/negative/scx_prog_show_race.c` 作为唯一 repo-owned reproducer。

### 6. 删除“只编译不执行”的 negative test

- 文件：`tests/negative/scx_bad_rejit_replay.c:1-153`，`tests/negative/Makefile:10`，`tests/negative/Makefile:22-28`，`runner/scripts/vm-selftest.sh:61-88`
- 问题：`scx_bad_rejit_replay` 被加入 `TESTS`，但 `tests/negative/Makefile` 的 `run` 不跑它，`vm-selftest.sh` 也只留下“以后通过 make vm-negative-test 跑”的注释，而根 `Makefile` 根本没有 `vm-negative-test` 目标。
- 建议操作：把 `scx_bad_rejit_replay.c` 从测试树删除；如果只是手工复现工具，应移出 `tests/`。

### 7. 删除 `tests/unittest/rejit_daemon_e2e.c`

- 文件：`tests/unittest/rejit_daemon_e2e.c:1-554`，对照 `tests/unittest/rejit_hotswap_socket_filter.c:24-329`
- 问题：这个文件本质上是 integration test，不是 unittest。它自己起 daemon、建 Unix socket、发 JSON 请求、检查 `optimize-all`，同时还复制了 socket-filter live harness。和 `rejit_hotswap_socket_filter.c` 的主体结构高度重复，只是额外包了一层 daemon 通讯。
- 建议操作：直接删除；如果唯一价值是保留 daemon 通路断言，应并入一个真正被调度的 integration 入口，而不是挂在 `tests/unittest/`。

### 8. 删除纯 contract/signature 测试

- 文件：`tests/python/test_katran_runner_contract.py:13-28`，`tests/python/test_app_runners_contract.py:16-84`
- 问题：这两份测试主要在断言 constructor 参数列表、parser flag 是否不存在、类是否继承 `AppRunner`。它们不验证真实运行行为，回归价值极低，却增加维护成本。
- 建议操作：删除整文件；真正重要的回归应该由 case/runner 行为测试覆盖。

## 应简化

### 9. 大量 Python orchestration 测试过度 mock，只在测元数据拼接

- 文件：`tests/python/test_bcc_case.py:65-152`，`tests/python/test_e2e_driver.py:32-145`，`tests/python/test_e2e_driver.py:168-239`，`tests/python/test_corpus_driver.py:454-721`，`tests/python/test_case_common.py:536-615`
- 问题：这些测试把 daemon、runner、stats、CPU sampler、workload 全部 monkeypatch 成假的，只断言 payload 某个键存在或某个列表被拼出来。结果是测不到真实逻辑边界，只在重复测“字典长什么样”。
- 建议操作：每层 abstraction 保留 1 个最小 plumbing test 即可，其余删掉或合并；不要在 `driver`、`case_common`、`case` 三层重复验证同一份 metadata 拼接。

### 10. `tests/negative/` 和 `tests/unittest/` 对 verifier rejection 做了重复覆盖

- 文件：`tests/negative/common.h:149-236`，`tests/negative/adversarial_rejit.c:187-208`，`tests/negative/adversarial_rejit.c:303-340`，`tests/negative/adversarial_rejit.c:428-433`，`tests/negative/adversarial_rejit.c:817-828`，`tests/unittest/rejit_safety_tests.c:211-230`，`tests/unittest/rejit_safety_tests.c:654-879`，`tests/unittest/rejit_safety_tests.c:888-899`，`tests/unittest/rejit_safety_tests.c:973-1034`，`tests/unittest/rejit_safety_tests.c:1408-1423`，`tests/unittest/rejit_verifier_negative_tests.c:296-467`
- 问题：`run_negative_test()`、`load_good_prog()`、`verify_retval()` 这套 harness 在 `tests/negative/common.h` 和 `rejit_safety_tests.c` 里各有一份。测试内容也大量重叠：非法 helper、错误 helper type、oversized program、invalid register、truncated `LD_IMM64`、backward jump、失败后原程序仍可运行等。
- 建议操作：把“verifier 应拒绝坏字节码”统一留在 `tests/negative/`；`tests/unittest/` 只保留 daemon/hotswap/特定回归语义，不再重复做 rejection catalog。

### 11. hotswap unittest 按 attach type 拆成了大量近似拷贝

- 文件：`tests/unittest/rejit_hotswap_xdp.c:232-360`，`tests/unittest/rejit_hotswap_kprobe.c:172-260`，`tests/unittest/rejit_hotswap_tracepoint.c:250-330`，`tests/unittest/rejit_hotswap_lsm.c:209-300`，`tests/unittest/rejit_hotswap_fentry.c:212-305`，`tests/unittest/rejit_hotswap_perf_event.c:311-390`，`tests/unittest/rejit_hotswap_socket_filter.c:204-299`
- 问题：这些文件都在重复同一套模式：open/load/attach，读原始 insns，patch 一个 immediate，循环 `HOTSWAP_ROUNDS`，等待 counter/packet 变化。差异主要只在 attach 和 worker。实测文本相似度在多个文件对之间已达到 0.69 到 0.74。
- 建议操作：抽成一个共享 harness，只保留 attach-specific setup/trigger/assertion；否则后续每加一个 attach type 都要继续复制整份测试体。

### 12. 根 `Makefile` 的 test target 面与 `§6.4` 不一致

- 文件：`Makefile:146-147`，`Makefile:159-160`，`Makefile:370-382`，`Makefile:385-401`，对照 `docs/kernel-jit-optimization-plan.md:641-655`，以及 `runner/scripts/vm-selftest.sh:87-88`，`tests/negative/Makefile:10`，`tests/negative/Makefile:22-28`，`runner/scripts/run_all_tests.sh:180-205`
- 问题：文档要求 `vm-selftest`、`vm-micro-smoke`、`validate = check + vm-test + vm-micro-smoke`，但根 Makefile 只暴露 `vm-test/vm-micro/vm-corpus/vm-e2e/vm-all`。`python-tests` 只跑 `tests/python/`，直接把 `tests/integration/`、`tests/unittest/`、`tests/negative/` 排除在外；`validate` 还绕开 canonical target，直接调用脚本跑 micro。脚本里甚至提到不存在的 `make vm-negative-test`。
- 建议操作：删掉误导性的 target/help 文案和裸脚本调用，收敛成 plan `§6.4` 的 canonical target surface；至少不要让文档、脚本注释和根 Makefile 各说各话。

## 低优先级

### 13. 低价值的 markdown/string-formatting 单文件测试可以并掉

- 文件：`tests/python/test_scx_case.py:11-44`，`tests/python/test_tracee_case.py:28-58`，`tests/python/test_bpftrace_case.py:11-61`，`tests/python/test_tetragon_case.py:79-175`
- 问题：这几份测试主要在断言 markdown 某一行字符串出现，或者 applied-site summary 的文本格式。它们与更高层 case 测试的收益重叠，而且通常一改输出文案就要跟着重写。
- 建议操作：并入各 case 的主测试，或直接删掉只验证文案格式的部分。

### 14. 单独的 alias BPF 源文件不值得保留

- 文件：`tests/unittest/progs/test_hotswap_struct_ops_late_rollback.bpf.c:1-4`
- 问题：文件只做了一次宏定义然后 `#include` 另一个 `.bpf.c`，属于纯别名壳。
- 建议操作：删掉该源文件，放到构建层做 alias/生成更合适。

## 汇总统计

- 高置信度“直接删除”范围：约 `2800` 到 `3050` 行。
- 如果把“应简化”项一起执行，预计还能再收掉约 `1800` 到 `2300` 行重复/样板代码。
- 合计可删/可简化规模：约 `4600` 到 `5350` 行。
- 高置信度直接删除涉及文件：约 `26` 个。
- 连同简化项一起算，受影响文件：约 `40+` 个。

口径说明：

- 上述行数按最小实施范围估算，只统计本次 review 范围内的测试与测试相关 driver/lib/Makefile 代码。
- 没把 build 产物、结果目录、未跟踪二进制算进删除量。
- 我刻意把“正常工作但只是可读性一般”的代码排除在外，只统计重复、过时、与设计不符、或测试价值明显偏低的部分。
