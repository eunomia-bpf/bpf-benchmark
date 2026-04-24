# Feature Inventory Report (2026-04-23)

范围说明：
- 只盘点当前仓库里真实存在、能被用户或开发者触发的功能面。
- 不展开 `bpfopt-suite/`、`vendor/linux-framework/` 内核改动本体；只把 daemon 侧实际注册/发现到的 kinsn 面板算作功能。
- `Active?` 采用三档：
  - `Yes`：过去 1 个月有 authoritative 文档或最近 commit 明确使用/维护。
  - `Indirect`：不是用户主入口，但被其他活跃入口稳定调用。
  - `No evidence`：仓库里还在，但近 1 个月没有 caller/文档权威使用证据。

## 1. Makefile 功能表
Data source:
- `rg -n '^[A-Za-z0-9_./-]+:([^=]|$)' Makefile runner/mk/*.mk`
- `nl -ba Makefile | sed -n '1,110p'`
- `nl -ba runner/mk/build.mk | sed -n '1,240p'`
- `nl -ba docs/kernel-jit-optimization-plan.md | sed -n '15,40p'`

| Target | 干什么 | 主要 env / 变量 | Active? | 冗余? |
|---|---|---|---|---|
| `help` | 打印 canonical run target 和关键变量 | `SAMPLES` `WARMUPS` `E2E_ARGS` `AWS_*` | No evidence | No |
| `check` | Python `py_compile` + `cargo fmt/clippy/test` + C unittest/negative build | `PYTHON` `RUN_TARGET_ARCH` | Yes | No |
| `validate` | 纯别名，等同 `check` | 无新增变量 | Yes | `Yes`，纯 alias，见 `Makefile:137-140` |
| `vm-selftest` | KVM x86 跑 repo-owned unittest + 负向子集 | `TEST_MODE=selftest` | Yes | No |
| `vm-negative-test` | KVM x86 跑 adversarial/fuzz/scx negative | `TEST_MODE=negative` | Yes | No |
| `vm-test` | KVM x86 跑 kernel selftest + unittest + negative | `TEST_MODE=test` | Yes | No |
| `vm-micro-smoke` | KVM x86 跑 micro smoke 规模 | 固定 `--samples 1 --warmups 0 --inner-repeat 50` | Yes | `Possible alias`，可由 `vm-micro` 参数化模拟 |
| `vm-micro` | KVM x86 跑 micro benchmark | `SAMPLES` `WARMUPS` `INNER_REPEAT` `BENCH` | Yes | No |
| `vm-corpus` | KVM x86 跑 corpus benchmark | `SAMPLES/VM_CORPUS_SAMPLES` `VM_CORPUS_WORKLOAD_SECONDS` `VM_CORPUS_ARGS` | Yes | No |
| `vm-e2e` | KVM x86 跑 6-case e2e benchmark | `E2E_SMOKE` `E2E_ARGS` | Yes | No |
| `vm-all` | 串行聚合 `vm-test` + `vm-micro` + `vm-corpus` + `vm-e2e` | 继承各子 target 参数 | Indirect | No |
| `aws-arm64-test` | ARM64 AWS 跑 test suite | `AWS_ARM64_*` `AWS_ARM64_TEST_MODE` | Yes | No |
| `aws-arm64-benchmark` | ARM64 AWS 跑 `micro/corpus/e2e/all` | `AWS_ARM64_BENCH_MODE` + `AWS_ARM64_*` | Yes | No |
| `aws-arm64-terminate` | 清理 ARM64 AWS 遗留实例 | `AWS_ARM64_*` | Yes | No |
| `aws-x86-test` | x86 AWS 跑 test suite | `AWS_X86_*` `AWS_X86_TEST_MODE` | Yes | No |
| `aws-x86-benchmark` | x86 AWS 跑 `micro/corpus/e2e/all` | `AWS_X86_BENCH_MODE` + `AWS_X86_*` | Yes | No |
| `aws-x86-terminate` | 清理 x86 AWS 遗留实例 | `AWS_X86_*` | Yes | No |
| `aws-e2e` | 架构参数化的 AWS 单-suite e2e 快捷入口 | `RUN_TARGET_ARCH` + `AWS_{X86,ARM64}_*` | Yes | `Possible alias`，与 `aws-*-benchmark ... BENCH_MODE=e2e` 等价 |
| `aws-corpus` | 架构参数化的 AWS 单-suite corpus 快捷入口 | `RUN_TARGET_ARCH` + `AWS_{X86,ARM64}_*` | Yes | `Possible alias`，与 `aws-*-benchmark ... BENCH_MODE=corpus` 等价 |
| `clean` | 清理 `.cache/*-kernel-build`、`runner/build*`、`micro/results/*` 等 | `X86_BUILD_DIR` `ARM64_BUILD_DIR` `RUNNER_BUILD_DIR` | No evidence | No |
| `image-runner-runtime-image-tar` | 在 runner Dockerfile 内打 runtime image tar | `RUN_TARGET_ARCH` `IMAGE_BUILD_JOBS` | Indirect | No |
| `image-kernel-artifacts` | 在 runtime image 内提取 kernel image + modules + kinsn + manifest | `RUN_TARGET_ARCH` `ACTIVE_KERNEL_BUILD_DIR` | Indirect | No |
| `image-kernel-build` | 在 runtime image 内编 framework kernel | `RUN_TARGET_ARCH` `JOBS` | Indirect | No |
| `image-kernel-modules-artifacts` | 在 runtime image 内导出 `/lib/modules/<release>` | `RUN_TARGET_ARCH` `KERNEL_MODULES_ARTIFACT_ROOT` | Indirect | No |
| `image-kinsn-artifacts` | 在 runtime image 内编 kinsn modules | `RUN_TARGET_ARCH` `ACTIVE_KINSN_SOURCE_DIR` | Indirect | No |
| `image-katran-artifacts` | 产出 Katran runtime artifacts | `RUN_TARGET_ARCH` | Indirect | No |
| `image-runner-artifacts` | 产出 `micro_exec` runner binary | `RUN_TARGET_ARCH` `LLVM_DIR/RUN_LLVM_DIR` | Indirect | No |
| `image-daemon-artifact` | 产出 `bpfrejit-daemon` release binary | `RUN_TARGET_ARCH` | Indirect | No |
| `image-micro-program-artifacts` | 编译 micro `.bpf.o` 对象集 | `RUN_TARGET_ARCH` | Indirect | No |
| `image-test-artifacts` | 编译 unittest/negative 主 artifact | `RUN_TARGET_ARCH` | Indirect | No |

结论：
- 活跃主入口就是 root `Makefile` 的 VM/AWS/test targets，符合 plan doc 的“Makefile 是唯一构建/测试入口”约束，见 `docs/kernel-jit-optimization-plan.md:19-25`。
- 明确重复的是 `validate -> check`。
- `aws-e2e` / `aws-corpus` 是“保留中的快捷 alias”，功能上和 `aws-{x86,arm64}-benchmark` 的单-suite模式重合，但 plan doc 明确在 `docs/kernel-jit-optimization-plan.md:1033` 说明“保留”。

## 2. CLI 入口功能表
Data source:
- `rg -n "if __name__ ==|def main\\(|argparse.ArgumentParser|usage:" runner micro corpus e2e daemon tests -g '*.py'`
- `find . -path './.git' -prune -o -path './vendor' -prune -o -path './docs/tmp' -prune -o -path './runner/repos' -prune -o -path './runner/build-*' -prune -o -type f \\( -name '*.py' -o -name '*.sh' \\) -print | sort`
- `nl -ba runner/libs/run_target_suite.py | sed -n '1,260p'`
- `nl -ba daemon/src/main.rs | sed -n '1,80p'`

| 入口 | 职责 | Callers | Active? | 冗余? |
|---|---|---|---|---|
| `python -m runner.libs.run_target_suite` | 顶层 dispatcher，动作 `run|benchmark|terminate` | `Makefile:17,142-200` | Yes | `Partial`，`benchmark` 单-suite 时等于 `run`，见 `runner/libs/run_target_suite.py:209-211` |
| `python -m runner.libs.run_contract` | 生成/读取 run contract JSON；动作 `print-json|write-config|write-target-config` | `runner/libs/run_target_suite.py` | Indirect | No |
| `python -m runner.libs.kvm_executor` | 按 run-config 启动 KVM VM，装 runtime image，进容器跑 suite | `runner/libs/run_target_suite.py:172-179` | Indirect | No |
| `python -m runner.libs.aws_executor` | 按 run-config 启动/终止 AWS 实例并执行 suite | `runner/libs/run_target_suite.py:157-169,222-237` | Indirect | No |
| `python -m runner.suites.micro` | suite wrapper，准备 env/artifacts 后转发 `micro/driver.py` | `runner/libs/suite_commands.py:147-153` | Yes | No |
| `python -m runner.suites.corpus` | suite wrapper，准备 env/artifacts 后转发 `corpus/driver.py` | `runner/libs/suite_commands.py:164-177` | Yes | No |
| `python -m runner.suites.e2e` | suite wrapper，准备 env/artifacts 后转发 `e2e/driver.py all` | `runner/libs/suite_commands.py:187-194` | Yes | No |
| `python -m runner.suites.test` | suite wrapper，调 kernel selftest + repo tests | `runner/libs/suite_commands.py:206-213` | Yes | No |
| `python3 micro/driver.py` | micro 直接 driver；host/debug 或 local suite 默认落点 | `runner/suites/micro.py:147-148`，`micro/README:13-16` | Yes | No |
| `python3 corpus/driver.py` | corpus 直接 driver；真正跑 app-native/TEST_RUN corpus | `runner/suites/corpus.py:107-108` | Yes | No |
| `python3 e2e/driver.py` | e2e 直接 driver；跑 6 case 或 `all` | `runner/suites/e2e.py:81-82`，`e2e/README:3-5` | Yes | No |
| `bpfrejit-daemon serve --socket ...` | 唯一 daemon CLI；启动 socket server | `daemon/src/main.rs:33-40,73-75` | Yes | No |
| `python3 micro/compare_results.py` | 比较两个 micro result JSON | README/manual only | No evidence | `Yes`，usage 仍写 `make compare`，但 Makefile 无该 target |
| `python3 micro/generate_figures.py` | 从 micro result 生成论文图表 | `micro/README:16` | Yes | No |
| `python3 micro/summarize_rq.py` | 从 micro result 生成 RQ markdown summary | `micro/README:16` | Yes | No |
| `runner/scripts/bpfrejit-install` | 从 runtime image tar 安装 kernel/modules/kinsn 到宿主或 VM | `runner/mk/build.mk:43,141-145`，`runner/libs/kvm_executor.py:97-103` | Yes | No |
| `docs/paper/helpers/build_tikz_figure.sh` | 论文图单文件 LaTeX 包装和裁边 | `docs/paper/Makefile` caller，非 benchmark runtime | No evidence | No |

结论：
- 真正的 canonical CLI 栈是 `Makefile -> runner.libs.run_target_suite -> (kvm/aws executor) -> runner.suites.* -> {micro,corpus,e2e}/driver.py`。
- daemon 已经完全收敛到单一 `serve` 子命令，和 plan doc 一致，见 `docs/kernel-jit-optimization-plan.md:169`。
- `micro/compare_results.py` 还在，但它的“`make compare`”入口已经消失，是明显的 stale developer surface。

## 3. E2E Case 功能表
Data source:
- `nl -ba e2e/driver.py | sed -n '70,120p'`
- `for f in e2e/cases/*/config*.yaml; do nl -ba "$f"; done`
- `rg -n 'build_report|build_markdown|workload|scripts =|workload_specs' e2e/cases/*/case.py`
- `find e2e/cases/bpftrace/scripts -maxdepth 1 -type f | sort`

| Case | 负责什么 workload | 检查什么性能维度 | App binary 来源 | 冗余? |
|---|---|---|---|---|
| `tracee` | 当前 checked-in config 只有 `tracee_default`，见 `e2e/cases/tracee/config.yaml:15-20` | `app_throughput` `events_per_sec` `application_overhead_pct`，并保留 control/baseline/post phases | `.cache/repo-artifacts/<arch>/tracee/tracee` | No |
| `tetragon` | 当前 checked-in config 只有 `exec_storm`，见 `e2e/cases/tetragon/config_execve_rate.yaml:1-5`；runner 还支持 `tetragon_exec_connect_mix/file_io/open_storm/connect_storm` | `app_throughput` `events_per_sec`、phase summary、baseline vs post compare | `.cache/repo-artifacts/<arch>/tetragon/bin/tetragon` + bundled `.bpf.o` | No |
| `bcc` | 10 个 BCC libbpf-tools workload 变体：`tcplife` `biosnoop` `runqlat` `syscount` `execsnoop` `opensnoop` `capable` `vfsstat` `tcpconnect` `bindsnoop`，见 `e2e/cases/bcc/config.yaml:15-56` | 每 tool 的 baseline/post throughput、site totals、额外 `report.md` | `.cache/repo-artifacts/<arch>/bcc/libbpf-tools/.output/*` | No |
| `bpftrace` | 6 个固定 script：`tcplife` `biosnoop` `runqlat` `tcpretrans` `capable` `vfsstat`，见 `runner/libs/app_runners/bpftrace.py:24-55` 与 `e2e/cases/bpftrace/scripts/*` | 每 script 的 baseline/post throughput、site totals、额外 `report.md` | `.cache/repo-artifacts/<arch>/bpftrace/bin/bpftrace` + checked-in `.bt` scripts | No |
| `katran` | 固定 `{"kind":"network"}`，见 `e2e/cases/katran/case.py:106-115` | 请求吞吐、成功率、XDP attach/healthcheck correctness、site totals | `.cache/repo-artifacts/<arch>/katran/bin/katran_server_grpc` + Katran BPF objects | No |
| `scx` | 3 个固定 workload：`hackbench` `stress-ng-cpu` `sysbench-cpu`，见 `e2e/cases/scx/case.py:100-111` | throughput、context switches/s、latency p50/p95、scheduler program runtime | `.cache/repo-artifacts/<arch>/scx/bin/scx_rusty` + `scx_rusty_main.bpf.o` | No |

合并判断：
- `bcc` 和 `bpftrace` 覆盖了相近的 workload 家族，但一个衡量 compiled BCC 工具，一个衡量 bpftrace 脚本，binary provenance 和 attach 路径不同，不应合并。
- `tracee`、`tetragon` 都属于安全/可观测类，但一个是 event-file / Tracee pipeline，一个是 Tetragon 原生 CLI + BPF lib 资产，也不重复。
- 当前 active checked-in case 就是 `tracee/tetragon/bpftrace/scx/bcc/katran` 六个，见 `e2e/driver.py:78-116,157-167`。

## 4. App Runner 功能表
Data source:
- `nl -ba runner/libs/app_runners/__init__.py | sed -n '1,100p'`
- `rg -n 'kheaders|sched_ext|bpftool|bpftrace|test_run|wait_until_program_set_stable|run_workload' runner/libs/app_runners/*.py`
- `nl -ba runner/libs/app_runners/bcc.py | sed -n '296,340p'`

| App Runner | 启动什么二进制 | 依赖什么系统库 / kheaders | 独有 feature |
|---|---|---|---|
| `BCCRunner` | BCC libbpf-tools 单 tool binary | 运行时 `/sys/kernel/kheaders.tar.xz`，必要时 `modprobe kheaders`，见 `runner/libs/app_runners/bcc.py:300-340` | 自动提取运行中 kernel headers，做 BCC compat 头修补 |
| `BpftraceRunner` | `bpftrace` + checked-in `.bt` 脚本 | 需要 `bpftrace`、`bpftool`、对应 workload tool | 固定 script registry，见 `runner/libs/app_runners/bpftrace.py:24-55` |
| `KatranRunner` | `katran_server_grpc` + Katran BPF object | 需要 `bpftool`、netns/XDP、Katran runtime libs | 既支持真实 `network`，也支持 corpus-only `test_run` 驱动，见 `runner/libs/app_runners/katran.py:996-1001` |
| `ScxRunner` | `scx_rusty` 调度器 | 依赖 `/sys/kernel/sched_ext/*`、`hackbench`、`stress-ng`、`sysbench`，见 `runner/libs/app_runners/scx.py:38-69,254-262` | 读取 sched_ext 状态并报告 scheduler-specific latency / run_cnt |
| `TetragonRunner` | Tetragon 原生 binary + bundled `.bpf.o` | 依赖 `stress-ng` `fio` `curl` `tar`，见 `runner/libs/app_runners/tetragon.py:92-107` | 先 `inspect_tetragon_setup()`，再把 setup state 注入 runner，见 `runner/libs/app_runners/__init__.py:51-59` |
| `TraceeRunner` | Tracee binary | 依赖 `stress-ng` `fio` `wrk` `hackbench` 等，见 `runner/libs/app_runners/tracee.py:457-484` | 支持最多 workload 变体，且带 event-file 结构化读取/活动校验 |
| `process_support.py` | 不直接启动业务 binary；提供 runner 共享进程壳 | 依赖 `bpftool prog show` 观测稳定集 | `wait_until_program_set_stable()`、`AgentSession`、`ManagedProcessSession`，见 `runner/libs/app_runners/process_support.py:27,85,132` |

结论：
- `runner/libs/app_runners/__init__.py:69-76` 只暴露 6 个业务 runner，没有历史遗留 runner alias。
- 共享抽象只剩 `process_support.py`，其他 runner 都是 case/app-specific。

## 5. Workload 功能表
Data source:
- `nl -ba runner/libs/workload.py | sed -n '1130,1218p'`
- `nl -ba corpus/config/macro_apps.yaml | sed -n '1,147p'`
- `for f in e2e/cases/*/config*.yaml; do nl -ba "$f"; done`
- `nl -ba runner/libs/app_runners/tracee.py | sed -n '457,484p'`
- `nl -ba runner/libs/app_runners/tetragon.py | sed -n '119,130p'`
- `nl -ba runner/libs/app_runners/scx.py | sed -n '254,262p'`
- `nl -ba runner/libs/app_runners/katran.py | sed -n '996,1001p'`

说明：
- 这里把三层 workload 一起盘点：`runner.libs.workload.run_named_workload()` 的 generic kind、runner-local only kind、manifest/case 真正暴露出来的 kind。
- “真跑”指当前 corpus manifest 或 checked-in e2e case config 会触发；“latent”指代码支持但当前 manifest/case 不暴露；“dead/unused”指 repo-wide 只在 dispatcher 里出现。

| Workload kind | 来源 | 当前是否真跑 | 说明 / 冗余判断 |
|---|---|---|---|
| `exec_storm` | generic + corpus/e2e | Yes | BCC/BPFTrace/Tetragon/BCC-case 都用 |
| `exec_loop` | generic + `bcc/config.yaml` | Yes | BCC `execsnoop` 用；是 deterministic exec loop |
| `file_open` | generic + `bcc/config.yaml` | Yes | BCC `syscount`/`opensnoop` 用 |
| `file_open_storm` | generic + `macro_apps.yaml` | Yes | corpus 里给 `bcc/syscount` 用；与 `file_open` 同实现但 caller 语义不同 |
| `open_family_storm` | generic + `macro_apps.yaml` | Yes | corpus 里给 `bcc/opensnoop` |
| `block_io` | generic + BCC/BPFTrace/Tracee | Yes | biosnoop / bpftrace biosnoop / tracee latent |
| `bind_storm` | generic + `macro_apps.yaml` / BCC case | Yes | `bcc/bindsnoop` |
| `network` | generic + corpus/e2e + Katran | Yes | BCC/BPFTrace/Katran/Tracee 都可能用 |
| `tcp_connect` | generic + BCC/BPFTrace script layer | Yes | BCC case 和 bpftrace `tcplife` 用 |
| `tcp_retransmit` | generic + `macro_apps.yaml` | Yes | `bpftrace/tcpretrans` |
| `scheduler` | generic + BCC/BPFTrace case | Yes | BCC `runqlat` 和 bpftrace `runqlat` 仍用该名字 |
| `hackbench` | generic + corpus/e2e + SCX | Yes | SCX 主 workload；generic 实现复用 scheduler load |
| `vfs_create_write_fsync` | generic + BCC/BPFTrace | Yes | BCC case + bpftrace `vfsstat` |
| `vfs_create_fsync_exact` | generic + corpus | Yes | corpus `bcc/vfsstat` 用精确版 |
| `tracee_default` | generic + tracee config | Yes | Tracee checked-in case 唯一 active config |
| `tracee_system_edge_mix` | generic + macro apps | Yes | corpus `tracee/default` 用 |
| `tetragon_exec_connect_mix` | generic + macro apps | Yes | corpus `tetragon/default` 用 |
| `test_run` | Katran runner-local | Yes | corpus `katran` 用；不是 test suite，而是 BPF_PROG_TEST_RUN benchmark path |
| `stress_ng_cpu` | SCX runner-local | Yes | SCX e2e fixed workload |
| `sysbench_cpu` | SCX runner-local | Yes | SCX e2e fixed workload |
| `tracee_module_load_loop` | generic + Tracee runner | Latent | 代码支持，当前 checked-in config 不用 |
| `tracee_io_vector_mix` | generic + Tracee runner | Latent | 代码支持，当前 checked-in config 不用 |
| `connect_storm` | Tracee/Tetragon runner-local | Latent | runner 支持，当前 manifest/config 不暴露 |
| `file_io` | Tracee/Tetragon runner-local | Latent | runner 支持，当前 checked-in config 不暴露 |
| `open_storm` | Tracee/Tetragon runner-local | Latent | runner 支持，当前 checked-in config 不暴露 |
| `mixed` | generic | No evidence | 仅 generic dispatcher 使用；当前 manifest/case 无 caller |
| `minimal_syscall` | generic alias | No evidence | 与 `exec_loop` 完全同实现，见 `runner/libs/workload.py:1148-1149` |
| `mixed_system` | generic alias | No evidence | 与 `system_telemetry_mix` 一起折叠到 `run_mixed_workload()`，见 `runner/libs/workload.py:1185-1186` |
| `system_telemetry_mix` | generic alias | No evidence | 同上 |
| `iterator_poll` | generic | No evidence | dispatcher-only |
| `security_policy_mix` | generic | No evidence | dispatcher-only |
| `oom_stress` | generic | No evidence | dispatcher-only，依赖 `stress-ng` |
| `sysctl_write` | generic | No evidence | dispatcher-only |
| `userns_unshare` | generic | No evidence | dispatcher-only |
| `fio` | generic | No evidence | dispatcher-only；当前 manifest/case 无 caller |

结论：
- 现在真正产品化的 workload 集合集中在 `macro_apps.yaml` 和 3 个 checked-in case config 上。
- 明确冗余 alias 只有 `minimal_syscall`、`mixed_system`、`system_telemetry_mix`。
- `file_open`/`file_open_storm`、`scheduler`/`hackbench` 看起来像重复，但 caller 语义不同，后面归到“看似重复但合理”。

## 6. Daemon Pass 功能表
Data source:
- `nl -ba daemon/src/passes/mod.rs | sed -n '36,118p'`
- `nl -ba daemon/src/pass.rs | sed -n '672,676p'`
- `nl -ba corpus/config/benchmark_config.yaml | sed -n '1,61p'`

说明：`typical site count contribution` 只能做定性判断，因为仓库里没有一张现成的 per-pass authoritative count 表；这里按代码语义、当前 benchmark default profile、以及 active app workload 覆盖面分成 `High/Medium/Low/Rare`。

| Pass | 干什么 | 输入条件 | 典型 site count 贡献 | benchmark 默认启用? |
|---|---|---|---|---|
| `map_inline` | inline stable map lookups / pseudo-map-value | 需要 direct value access；struct_ops 有 policy exclusion | High | Yes |
| `const_prop` | 常量折叠到 MOV/JA/LD_IMM64 | 需要 verifier/analysis 提供精确常量 | High | Yes |
| `dce` | 清 unreachable/NOP/dead cleanup | 常在 map_inline/const_prop 后触发 | High | Yes |
| `skb_load_bytes_spec` | skb helper 专化为 direct packet access | 只对 `skb_load_bytes` 类 helper site | Medium | Yes |
| `bounds_check_merge` | 合并 packet bounds-check ladder | 需要 packet parser 形状 | Medium | Yes |
| `wide_mem` | byte-by-byte load 融成宽 load | 需要 byte-load chain pattern | Medium-High | Yes |
| `bulk_memory` | scalarized memcpy/memset -> bulk-memory kinsn | 需要 bulk-memory kfunc 可用 | Medium | Yes |
| `rotate` | shift+or -> rotate kfunc | 需要 rotate kfunc + arch support | Low-Medium | Yes |
| `cond_select` | branch-over-mov -> select kfunc | 需要 select kfunc + arch support | Low-Medium | Yes |
| `extract` | shift+mask -> bitfield-extract kfunc | 需要 extract kfunc + arch support | Low | Yes |
| `endian_fusion` | load+bswap -> endian-load kfunc | 需要 endian kfunc + arch support | Low-Medium | Yes |
| `branch_flip` | PGO branch polarity flip | 需要 profile / PMU gate；policy-sensitive | Rare | `No`，benchmark default list 不含它，见 `corpus/config/benchmark_config.yaml:1-14` |

结论：
- daemon 的 internal default 是“全 registry 开启”，见 `daemon/src/pass.rs:672-676`。
- benchmark default profile 只启 11 个 pass，故 `branch_flip` 是“实现了但不在默认 benchmark 面上”的唯一 pass。

## 7. Kinsn / Kfunc 功能表
Data source:
- `nl -ba daemon/src/kfunc_discovery.rs | sed -n '17,31p'`
- `rg -n 'ROR|ROL|RORX|CMOV|CSEL|BEXTR|MOVBE|REV|LDP|STP|LEA' module/x86 module/arm64`
- `nl -ba docs/kernel-jit-optimization-plan.md | sed -n '198,216p'`

说明：
- 本树里没有 `vendor/linux-framework/include/uapi/linux/bpf_kinsn*.h`，`find vendor/linux-framework/include/uapi/linux -name '*kinsn*'` 为空；因此 daemon discovery registry 才是当前仓库的“真实功能面板”。
- daemon 已注册的是 8 个 kfunc target；`LEA` 和 `ARM64 LDP/STP pair-load/store` 只有 plan/module 侧存在，不在当前 daemon registry。

| Registry / family | daemon 注册键 | x86 lowering | arm64 lowering | 当前是否接入 daemon pass |
|---|---|---|---|---|
| Rotate | `bpf_rotate64` | `ROR/ROL/RORX`，见 `module/x86/bpf_rotate.c:3,139-140` | `EXTR`，见 `module/arm64/bpf_rotate.c:3,110-111` | Yes |
| Conditional select | `bpf_select64` | `CMOV`，见 `module/x86/bpf_select.c:3,160-161` | `CSEL`，见 `module/arm64/bpf_select.c:3,120-121` | Yes |
| Bitfield extract | `bpf_extract64` | `BEXTR`，见 `module/x86/bpf_extract.c:3,141-142` | `UBFM` family，见 `module/arm64/bpf_extract.c:3,105-106` | Yes |
| Bulk memcpy | `bpf_memcpy_bulk` | x86 bulk copy lowering，见 `module/x86/bpf_bulk_memory.c:449-467` | ARM64 `LDP/STP` loops，见 `module/arm64/bpf_bulk_memory.c:558-580` | Yes |
| Bulk memset | `bpf_memset_bulk` | x86 bulk memset lowering | ARM64 `LDP/STP` loops | Yes |
| Endian load 16 | `bpf_endian_load16` | `MOVBE` family，见 `docs/kernel-jit-optimization-plan.md:207` / `module/x86/bpf_endian.c` | `REV16` | Yes |
| Endian load 32 | `bpf_endian_load32` | `MOVBE` | `REV` 32-bit | Yes |
| Endian load 64 | `bpf_endian_load64` | `MOVBE` | `REV` 64-bit | Yes |
| `ADDR_CALC (LEA)` | 无 | plan doc 标成低优先级未实现，见 `docs/kernel-jit-optimization-plan.md:214` | 无 | No |
| ARM64 pair load/store | `bpf_ldp` module only | x86 不需要 | `LDP/STP`，见 `module/arm64/bpf_ldp.c:3,212` | No，module 有但 daemon registry 无项 |

结论：
- 当前 daemon 真正能发现并用到的 kinsn family 只有 `rotate/select/extract/bulk/endian`。
- `LEA` 不存在于 `daemon/src/kfunc_discovery.rs:22-31`，因此不是“隐藏功能”，而是明确未接入。
- ARM64 `bpf_ldp` 也是“module 已有、benchmark surface 未暴露”的能力缺口。

## 8. 测试模式功能表
Data source:
- `nl -ba runner/suites/test.py | sed -n '40,67p'`
- `nl -ba runner/suites/test.py | sed -n '249,326p'`
- `nl -ba tests/unittest/Makefile | sed -n '66,132p'`
- `nl -ba tests/negative/Makefile | sed -n '10,32p'`
- `nl -ba micro/driver.py | sed -n '413,425p'`

| Mode | 命令 | 目的 | Active? |
|---|---|---|---|
| `unittest` | `make -C tests/unittest run`；被 `vm-selftest/vm-test` 间接调用 | 跑 repo-owned `rejit_*` binaries 和 module tests | Yes |
| `negative` | `make -C tests/negative run`；被 `vm-negative-test/vm-test` 间接调用 | adversarial + replay + fuzz 负向健壮性 | Yes |
| `fuzz` | `python -m runner.suites.test --test-mode fuzz` | 只跑 `fuzz_rejit` | Yes |
| `selftest` | `make vm-selftest` / `runner.suites.test --test-mode selftest` | load kinsn + unittest + negative 子集，不含 scx race | Yes |
| `test` | `make vm-test` / `runner.suites.test --test-mode test` | kernel selftest + unittest + negative 全套 | Yes |
| `full` | `runner.suites.test --test-mode full` | `test` 的纯 alias，见 `runner/suites/test.py:51-55,65` | Yes |
| `smoke` | `make vm-micro-smoke`；`runner.suites.e2e --e2e-smoke`；`e2e/driver.py --smoke` | 小样本/短 duration 快速验证 | Yes |
| `authoritative` | 无独立命令；micro 通过默认 benchmark+runtime 组合自动命名为 authoritative，见 `micro/driver.py:420-425` | 论文/权威产物命名与目录分类 | Yes |

结论：
- `full` 是测试模式里最明确的冗余 alias。
- `smoke` 和 `authoritative` 不是独立子系统，而是 run-shape / artifact-shape。

## 9. Report 格式清单
Data source:
- `nl -ba runner/libs/run_artifacts.py | sed -n '21,84p'`
- `nl -ba micro/driver.py | sed -n '311,319p'`
- `nl -ba corpus/driver.py | sed -n '1438,1565p'`
- `nl -ba e2e/driver.py | sed -n '207,314p'`

`metadata.json`
- 写入位置和入口在 `runner/libs/run_artifacts.py:66-84`。
- 载 run-level summary：`status`、`started_at`、`last_updated_at`、可选 `completed_at/error_message`。
- micro 会把 `summarize_benchmark_results(results)` 的摘要塞进去，见 `micro/driver.py:311-319`。
- corpus 会记录 `suite/manifest/samples/workload_seconds/kinsn_enabled/optimization_summary`，见 `corpus/driver.py:1445-1456`。
- e2e 会记录 `suite/case/smoke/kinsn_enabled/optimization_summary`，见 `e2e/driver.py:207-221`。

`result.json`
- 是完整结构化 payload；artifact writer 在 `runner/libs/run_artifacts.py:58-64,76-79`。
- corpus 直接手写到 run dir，再重复交给 `ArtifactSession`，见 `corpus/driver.py:1506-1538`。
- e2e 同样写完整 case payload，见 `e2e/driver.py:293-314`。
- micro 的 `result.json` 是唯一详细结构化文件；没有 `result.md`。

`result.md`
- corpus 总是写 `result.md`，见 `corpus/driver.py:1508-1525`。
- e2e 总是写 `result.md`，内容来自 `spec.build_markdown(payload)`，见 `e2e/driver.py:276-314`。
- micro 不写 `result.md`。

`report.md`
- 只对带 `build_report` 的 e2e case 写，目前只有 `bcc` 与 `bpftrace`，见 `e2e/driver.py:91-109,277-300`。
- 它是 case-specific narrative report，不是统一 schema。

字段覆盖关系：
- `metadata.json` 和 `result.json` 有明确重复：前者复制后者的 run summary 子集，目的是“快速发现 + 状态轮询 + 无需打开大文件”。
- `result.md` 是 `result.json` 的 markdown render，不引入新机器字段。
- `report.md` 不是 `result.md` 的严格超集，只在 `bcc/bpftrace` 追加更论文化的解释。
- 额外还有 `progress.json`，但它是辅助状态文件，不是用户要求的四个主格式。

结论：
- 真正重复字段最多的是 `metadata.json` vs `result.json`；这是有意 duplication，不建议删。
- `result.md` 和 `report.md` 不属于同一层级，不应合并成统一 mandatory file。

## 10. Config 可调参数总表
Data source:
- `nl -ba Makefile | sed -n '31,77p'`
- `nl -ba runner/libs/suite_args.py | sed -n '71,145p'`
- `nl -ba runner/libs/run_contract.py | sed -n '224,320p'`
- `nl -ba runner/targets/x86-kvm.env`
- `nl -ba runner/targets/aws-x86.env`
- `nl -ba runner/targets/aws-arm64.env`
- `nl -ba runner/suites/*.env`
- `nl -ba corpus/config/benchmark_config.yaml | sed -n '1,61p'`

| 参数名 | 来源 | 默认值 | 被哪些 module 读 | 冗余 surface 分析 |
|---|---|---|---|---|
| `RUN_TARGET_ARCH` / `--target-arch` / target `TARGET_ARCH` | target `.env` + suite common args | `x86_64` / `arm64` 按 target | `runner/libs/run_contract.py` `runner/suites/_common.py` `runner/mk/build.mk` | No；这是跨 build/runtime 的主轴参数 |
| `SAMPLES` | root Make env | `3` | `Makefile:37,69-74` -> `runner/libs/suite_args.py:71-80,93-107` | 与 AWS-prefixed sample 参数是命名空间重复，但意图不同 |
| `WARMUPS` | root Make env | `1` | `Makefile:38,72` -> `runner/libs/suite_args.py:71-80,93-97` | 只给 micro 用，No |
| `INNER_REPEAT` | root Make env | `100` | `Makefile:39,72` -> `runner/libs/suite_args.py:71-80,93-97` | 只给 micro 用，No |
| `BENCH` | root Make env | 空 | `Makefile:46,71-72` -> `runner/libs/suite_args.py:95-97` | No |
| `VM_CORPUS_SAMPLES` | root Make env | `30` | `Makefile:40,69-74` -> `runner/libs/suite_args.py:104-109` | 与 `SAMPLES` 有双 surface，但 root Make 明确规定 `SAMPLES` 显式传入时覆盖它 |
| `VM_CORPUS_WORKLOAD_SECONDS` | root Make env | 空 | `Makefile:41,74` -> `runner/libs/suite_args.py:105-109` | No |
| `VM_CORPUS_ARGS` | root Make env | 空 | `Makefile:35,74` -> `runner/libs/suite_args.py:106-109` -> `runner/suites/corpus.py` | `Partial redundancy`：还能隐式塞 `--rejit-passes`，与 `BPFREJIT_BENCH_PASSES` 重复 |
| `E2E_SMOKE` | root Make env | `0` | `Makefile:34,75` -> `runner/libs/suite_args.py:112-121` | No |
| `E2E_ARGS` | root Make env | 空 | `Makefile:33,75` -> `runner/libs/suite_args.py:115-121` -> `runner/suites/e2e.py` | 同样可隐式塞 `--rejit-passes`，存在重复面 |
| `TEST_MODE` | root Make env | `test` | `Makefile:36,77` -> `runner/libs/suite_args.py:124-142` -> `runner/suites/test.py` | `full` alias 造成下游纯重复值 |
| `FUZZ_ROUNDS` | root Make env | `1000` | `Makefile:47,76` -> `runner/libs/suite_args.py:130-142` -> `runner/suites/test.py` | No |
| `SCX_PROG_SHOW_RACE_*` | root Make env | `bpftool-loop / 20 / 20 / 0` | `Makefile:48-51,76` -> `runner/libs/suite_args.py:132-141` -> `runner/suites/test.py` | No |
| `VM_{TEST,MICRO,CORPUS,E2E}_TIMEOUT` | root Make env | `3600/7200/7200/7200` | `Makefile:42-45,62` -> `runner/libs/run_contract.py:230-238` | No |
| `AWS_{X86,ARM64}_BENCH_MODE` | root Make env | 空 | `Makefile:18,29,173,182` -> `runner/libs/run_target_suite.py:192-206` | `Possible redundancy`：单-suite 时与 `run` 等价 |
| `AWS_{X86,ARM64}_TEST_MODE` | AWS env | `test` | `runner/libs/suite_args.py:124-142` | 与 root `TEST_MODE` 是 target namespace duplication，合理 |
| `AWS_{X86,ARM64}_BENCH_{SAMPLES,WARMUPS,INNER_REPEAT}` | AWS env | `1/0/10` | `runner/libs/suite_args.py:71-80` | 与 root micro 参数平行 duplication，合理 |
| `AWS_{X86,ARM64}_CORPUS_WORKLOAD_SECONDS` | AWS env | 空 | `runner/libs/suite_args.py:100-109` | No |
| `AWS_{X86,ARM64}_{CORPUS_ARGS,E2E_ARGS,E2E_SMOKE}` | AWS env | 空 / `0` | `runner/libs/suite_args.py:100-121` | 同 root 同名 surface；合理 namespace duplication |
| `AWS_{X86,ARM64}_{REGION,PROFILE,INSTANCE_TYPE,ROOT_VOLUME_GB,...}` | AWS env | target `.env` 给默认，见 `runner/targets/aws-*.env:5-14` | `runner/libs/run_contract.py:303-320` 及后续 AWS context | No |
| `SUITE_DEFAULT_VM_TIMEOUT_SECONDS` | suite `.env` | benchmark suites `7200`，test `3600` | `runner/libs/run_contract.py:298-300` | No |
| `SUITE_DEFAULT_NATIVE_REPOS` | suite `.env` | corpus/e2e 默认 `bcc,bpftrace,katran,tracee,tetragon` | `runner/libs/run_contract.py:296-299` -> `runner/libs/suite_commands.py` -> suite wrappers | No |
| `SUITE_DEFAULT_SCX_PACKAGES` | suite `.env` | `scx_rusty` | `runner/libs/run_contract.py:297-299` -> `runner/libs/suite_commands.py` -> suite wrappers | No |
| `macro_apps.yaml defaults.samples` | YAML | `30` | `corpus/driver.py:207-211,1463-1465` | 与 `--samples` 是正常 override 关系 |
| `macro_apps.yaml defaults.duration_s` | YAML | `1` | `corpus` case/app suite load path | No |
| tracee/tetragon/BCC case durations | case YAML | per file fixed values | respective `e2e/cases/*/case.py` | No |
| benchmark profile `passes.active` / `profiles.*.active_list` | `corpus/config/benchmark_config.yaml` | `performance` / explicit lists | `runner/libs/rejit.py:478-493` | No；但 `branch_flip` 不在 default profile |
| benchmark policy `rules.disable` | same YAML | `struct_ops -> disable map_inline,dce` | `runner/libs/rejit.py:471-475,496-500` | No |
| `BPFREJIT_BENCH_PASSES` | runtime env | unset -> benchmark default | `runner/libs/rejit.py:486-493` | `Yes`，和 wrapper-hidden `--rejit-passes` 是双 surface |
| `BPFREJIT_MICRO_PROGRAM_DIR` | runtime env | unset -> wrapper computes | `runner/suites/micro.py:145-147` / `micro/driver.py` | No |
| `BPFREJIT_MICRO_RUNNER_BINARY` | runtime env | unset -> wrapper computes | `runner/suites/micro.py:145-147` / `micro/driver.py` | No |
| `BPFREJIT_INSTALL_{EXTRACT_KERNEL,KERNEL_OUT_DIR,SKIP_KINSN}` | install script env | `0/""/0` | `runner/scripts/bpfrejit-install:10-23,106-147` | No |

额外 dead / ambiguous surface：
- `Makefile:93-94` help 还在示例里宣传 `--rejit-passes`，但 direct corpus/e2e driver 已按 `docs/kernel-jit-optimization-plan.md:1036` 删除该 CLI，只剩 wrapper 兼容层在偷偷吃掉它。
- `runner/libs/suite_commands.py:164-170` 还会给 corpus suite 注入 `--output-md`，但 repo 搜索只有这一处 producer，没有任何 parser/reader。这是 dead arg surface。

## 11. 环境支持表
Data source:
- `nl -ba runner/targets/x86-kvm.env`
- `nl -ba runner/targets/aws-x86.env`
- `nl -ba runner/targets/aws-arm64.env`
- `nl -ba runner/suites/micro.py | sed -n '34,85p'`
- `nl -ba e2e/README.md | sed -n '1,26p'`

| Env | 命令 | 依赖 | 典型跑什么 |
|---|---|---|---|
| `host/local` | `python3 micro/driver.py`、`python3 corpus/driver.py`、`python3 e2e/driver.py`，或 `python -m runner.suites.* --target-name local` | 已准备好的 daemon/runner/repo artifacts；本机 root/工具链 | 开发调试、direct driver |
| `x86-kvm` | `make vm-selftest` `vm-test` `vm-micro` `vm-corpus` `vm-e2e` | `runner/targets/x86-kvm.env:1-12`，`TARGET_EXECUTOR=kvm`，runtime image tar，framework kernel image，`vng` | 主开发验证、x86 authoritative benchmark |
| `aws-x86` | `make aws-x86-test` / `make aws-x86-benchmark` | `runner/targets/aws-x86.env:1-14`，EC2 x86 (`t3.micro/t3.large`)，Docker，SSH | 远端 x86 benchmark / corpus / e2e |
| `aws-arm64` | `make aws-arm64-test` / `make aws-arm64-benchmark` | `runner/targets/aws-arm64.env:1-14`，EC2 arm64 (`t4g.micro/t4g.large`)，Docker，SSH | ARM64 benchmark，尤其 corpus/e2e |

结论：
- 环境支持面就是 `local / x86-kvm / aws-x86 / aws-arm64` 四档。
- plan doc 的“ARM64 默认走 AWS 远端”约束已落在 target/env 设计里，见 `docs/kernel-jit-optimization-plan.md:407`。

## 12. 功能冗余诊断
Data source:
- `nl -ba Makefile | sed -n '137,200p'`
- `nl -ba runner/suites/test.py | sed -n '50,67p'`
- `nl -ba runner/suites/_common.py | sed -n '362,372p'`
- `nl -ba runner/suites/corpus.py | sed -n '75,90p'`
- `nl -ba runner/suites/e2e.py | sed -n '71,76p'`
- `nl -ba runner/libs/rejit.py | sed -n '486,493p'`
- `nl -ba runner/libs/workload.py | sed -n '1148,1186p'`
- `nl -ba runner/libs/suite_commands.py | sed -n '164,170p'`
- `nl -ba runner/suites/corpus.py | sed -n '33,68p'`

### 🔴 明确冗余 / 应该删
- `validate` 完全重复 `check`。`Makefile:137-140` 只有 `validate: check`，没有额外命令或变量覆盖。建议删 `validate`，保留 `check`。
- `runner.suites.test` 的 `full` 完全重复 `test`。`runner/suites/test.py:51-55` 暴露 `full` 选项，但 `runner/suites/test.py:65` 立刻把它归一化成 `test`。建议删 `full` 这个 mode 字符串。
- wrapper-hidden `--rejit-passes` 和 `BPFREJIT_BENCH_PASSES` 是两套等价配置面。`runner/suites/_common.py:369-371` 把 CLI 里的 `--rejit-passes` 偷转成环境变量；`runner/libs/rejit.py:486-493` 才是真正读取处；而 direct corpus/e2e driver 的显式 CLI 已在 `docs/kernel-jit-optimization-plan.md:1036` 标记删除。建议删 wrapper 兼容层，只保留环境变量这一层。
- `minimal_syscall` 是 `exec_loop` 的纯 alias。`runner/libs/workload.py:1148-1149` 把二者映射到同一个 `run_user_exec_loop()`；repo-wide 搜索没有任何 checked-in caller 还引用 `minimal_syscall`。建议删 `minimal_syscall` 名字。
- `mixed_system` 与 `system_telemetry_mix` 都是 `mixed` 的纯 alias。`runner/libs/workload.py:1138-1139` 与 `1185-1186` 证明三者最终都落到 `run_mixed_workload()`，且 checked-in manifest/case 没 caller。建议至少删掉两个别名，只保留一个 canonical 名。

### 🟡 可能冗余 / 待定
- `aws-e2e` / `aws-corpus` 和 `aws-{x86,arm64}-benchmark` 单-suite 模式功能重合。证据：`Makefile:173-183` 已有参数化 benchmark 入口，`Makefile:188-200` 又额外给了两个快捷 target。疑问是：团队是否想保留“无需设置 `AWS_*_BENCH_MODE` 的短命令”。验证方法：看最近命令习惯或 shell history；如果没人直接用这两个 alias，就可以删。
- `vm-micro-smoke` 可能只是 `vm-micro` 的固定参数别名。证据：`Makefile:151-155,72-73`。疑问是：团队是否依赖单独 target 名称做 CI 或 summary 命名。验证方法：看 CI/文档引用量。
- `run_target_suite benchmark <single-suite>` 对单 suite 情况其实等于 `run`。证据：`runner/libs/run_target_suite.py:209-211`。疑问是：是否需要把 `benchmark` 语义保留给多-suite/`all`，而把单-suite case 规范化到 `run`。验证方法：看 Makefile/AWS 之外是否有人直接用 CLI。
- `suite_commands.py` 给 corpus suite 注入 `--output-md`，但 repo 搜索只有 producer、没有 reader。证据：`runner/libs/suite_commands.py:164-170`；`runner/suites/corpus.py:33-68` 没 parser；`rg -n 'output-md|output_md' runner corpus e2e micro -g '!**/results/**'` 只命中 `suite_commands.py:168`。疑问是：这个参数是未完成清理还是还有外部 wrapper 依赖。验证方法：抓一次实际生成的 suite argv，不执行 benchmark 也能确认 producer path。
- `micro/compare_results.py` 的 `make compare` 用法说明已经失效。证据：`micro/compare_results.py:4-6`；Makefile/`runner/mk/*.mk` 无 `compare:` target。它更像 dead developer surface，不是 runtime duplication。验证方法：确认是否还有 docs/CI 调这个脚本。

### 🟢 看似重复但合理
- direct driver 与 `runner.suites.*` wrapper 同时存在是合理的。前者是 host/debug；后者是 Make/KVM/AWS 正式入口。证据：`micro/README:13-16`、`e2e/README:3-5`、`runner.libs.suite_commands.py:147-214`。
- `file_open` 与 `file_open_storm` 共用实现是合理的，因为 BCC case 和 corpus macro app 用的是不同语义层标签。证据：`runner/libs/workload.py:1150-1151` 配合 `e2e/cases/bcc/config.yaml:28-40` 与 `corpus/config/macro_apps.yaml:51-56`。
- `scheduler` 与 `hackbench` 共用底层 scheduler load 也是合理的。`scheduler` 保留给 BCC/bpftrace tool 语义，`hackbench` 保留给 SCX/宏观 app 语义。证据：`runner/libs/workload.py:1144-1145,1172-1173`。
- `metadata.json` 和 `result.json` 的字段重复是合理的。一个给 run discovery/status，一个给完整 payload。证据：`runner/libs/run_artifacts.py:38-84`。
- `result.md` 与 `report.md` 不重复。`result.md` 是统一摘要；`report.md` 只在 `bcc/bpftrace` 提供额外 narrative。证据：`e2e/driver.py:276-300`。
- `bcc` 与 `bpftrace` 两个 case/workload 家族高度重合，但它们量的是不同 app ecosystem，不能用一个替代另一个。证据：`e2e/cases/bcc/config.yaml` vs `runner/libs/app_runners/bpftrace.py:24-55`。

## 13. 功能完整度评估
Data source:
- `nl -ba docs/kernel-jit-optimization-plan.md | sed -n '368,420p'`
- `nl -ba docs/kernel-jit-optimization-plan.md | sed -n '198,216p'`
- `nl -ba corpus/config/benchmark_config.yaml | sed -n '1,61p'`
- `nl -ba daemon/src/passes/mod.rs | sed -n '52,118p'`
- `nl -ba daemon/src/kfunc_discovery.rs | sed -n '22,31p'`
- `rg -n 'bpf_ldp' module/arm64`

实现了但没暴露入口：
- `branch_flip` 已在 pass registry 里实现，见 `daemon/src/passes/mod.rs:108-117`，daemon internal default 也会启用，见 `daemon/src/pass.rs:672-676`；但 benchmark default profile 明确不把它放进 active pass list，见 `corpus/config/benchmark_config.yaml:1-14`。这属于“实现了，但 benchmark surface 默认不回答它”。
- ARM64 `bpf_ldp` module 已存在，见 `module/arm64/bpf_ldp.c:3,212`，但 `daemon/src/kfunc_discovery.rs:22-31` 没有对应 registry key，也没有 `daemon/src/passes/` 的 pass 消费它。它是“module-only capability”。

声称有但实际没功能：
- plan doc 没把 `LEA` 声称成已实现，反而明确写 `ADDR_CALC (LEA)` 低优先级未做，见 `docs/kernel-jit-optimization-plan.md:214`。所以这里不存在“文档声称有、代码没有”的矛盾。
- 反而仓库内部真正的 mismatch 是文档/usage 示例层：`micro/README:56-60` 还写 `make vm-micro PROFILE=ablation_wide_mem`，但 root `Makefile` 已无 `PROFILE` 变量，且 plan doc 在 `docs/kernel-jit-optimization-plan.md:1033` 记录它已删。这个是 stale doc，不是缺失实现。

对照 §5 Required Questions：
- `Q1 Userspace policy 是否在不同硬件/workload/程序间产生差异？`
  - 当前 benchmark 能回答。
  - 证据：micro/corpus/e2e 全都有；环境覆盖 `x86-kvm/aws-x86/aws-arm64`，见 `Makefile:154-200` 和 `runner/targets/*.env`。
- `Q2 是否 outperform fixed kernel heuristics？`
  - 只能部分回答。
  - 原因：当前 repo benchmark surface里没有 plan doc `§5.1` 列的 `kernel-fixed-cmov/wide/rotate/lea` / `advisor-static` / `advisor-profiled` 独立入口，现有公开入口主要比较 stock kernel JIT、reJIT 后结果和 llvmbpf 参考。也就是说“固定策略 baseline”这个问题没有独立 CLI/make surface。
- `Q3 Legality substrate 在真实程序上的 directive 接受率？`
  - 只能部分回答。
  - 当前 corpus/e2e payload 会记录 `passes_applied`、rollback、`program_changed` 等，但没有单独的“directive acceptance rate dashboard”入口；要从 `result.json` 二次分析。
- `Q4 系统是否泛化到多个 directive 家族？`
  - 当前 benchmark 能回答“11 个 benchmark-default pass family + 8 个 kfunc target”这个层级。
  - 但回答不到 `branch_flip`、`LEA`、`ARM64 LDP/STP` 这几类非默认/未接入家族。
- `Q5 Operators 能否在类似 production 部署中安全管理 policy？`
  - 部分能回答。
  - 能回答的部分：app-native loader、两阶段测量、零静默失败、artifact/metadata、AWS/KVM 远端跑法。
  - 不能直接回答的部分：没有单独 operator policy management CLI，只有 `BPFREJIT_BENCH_PASSES` / benchmark YAML 这种 benchmark-facing 控制面。

对照 §5.3 Required Workloads：
- `Mechanism isolation`：micro manifest 已覆盖；可以回答。
- `Policy-sensitivity`：`cond_select`/`branch_flip` 等只部分回答，因为后者未进 default benchmark。
- `Real programs`：corpus macro apps 已覆盖 20 app；可以回答。
- `End-to-end deployment`：当前有 6 case e2e，可以回答比“至少一个”更强的问题，见 `e2e/driver.py:78-116`。

总评：
- benchmark 主体已经能回答 plan doc 的大部分“已落地问题”。
- 缺口主要集中在“实现了但没纳入公开 benchmark default”的 pass family，以及“module 已有但 daemon/pass 没接线”的 ARM64 LDP/STP。

## 14. 签收意见
Data source:
- 汇总自前 13 节的代码/文档命令。

- 当前功能数量粗估：
  - `make` 入口约 30 个。
  - CLI / script 入口约 17 个。
  - E2E case 6 个。
  - app runner 7 个。
  - workload kind 约 34 个名字，其中真跑约 20 个。
  - daemon pass 12 个。
  - daemon kfunc registry 8 个 target，外加 2 个“module only / 未接线”家族。
  - 测试模式 8 个命名面。
  - 合计 developer-facing / benchmark-facing surface 粗估在 `120-140` 个之间。
- 估计冗余率：
  - 明确冗余约 `5-7%`。
  - 把快捷 alias、stale doc surface、hidden compatibility surface 都算进去，大约 `10-12%`。
- 前 3 条最值得删的冗余：
  - `validate`，因为它是无条件的 `check` alias，完全不提供新语义，见 `Makefile:137-140`。
  - `full` test mode，理由同上，是 `test` 的纯 alias，见 `runner/suites/test.py:51-55,65`。
  - wrapper-hidden `--rejit-passes`，因为 direct driver 已删该 CLI，却还在 wrapper 层保留同功能的 shadow surface，增加理解成本，见 `runner/suites/_common.py:369-371` 与 `runner/libs/rejit.py:486-493`。

总判断：
- 这个仓库的功能面已经比 Round 7 前干净很多，主路径也基本统一到 `Makefile -> run_target_suite -> suites -> drivers`。
- 真正还脏的地方不是“大功能重复造轮子”，而是少量 alias、兼容层遗留和 dispatcher-level workload 别名没有继续清掉。
