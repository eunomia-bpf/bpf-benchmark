# 删除 filter/select，改为直接加载全部 program

## 调研清单

- Tracee 旧逻辑确认：
  [runner/libs/app_runners/tracee.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tracee.py:438) 之前承担 `events` 参数和命令拼装；
  [e2e/cases/tracee/config.yaml](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/config.yaml:1) 之前带 `events` / `primary_events` / `latency_probe_events`；
  [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:326) 之前按 event 名称做 case 内过滤统计。
- Tetragon 旧逻辑确认：
  [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:89) 现在改为静态 policy 目录；整改前这里是启动时程序化生成临时 YAML；
  [e2e/cases/tetragon/config_execve_rate.yaml](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/config_execve_rate.yaml:1) 之前承载 `--cgroup-rate 1000,1s`；
  [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:576) 原先 artifacts / lifecycle 仍围绕旧 synthetic pack。
- BCC 旧逻辑确认：
  [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:68) 原先会在 suite tools 上再做 smoke / 选择分支，没做到“配置里全跑即全跑”。
- bpftrace 旧逻辑确认：
  [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:90) 原先仍保留按脚本子集执行的分支。
- Katran 复核：
  [runner/libs/app_runners/katran.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/katran.py:337) 只剩 `rp_filter` sysctl 配置，未发现 `-hc_forwarding=false` 残留。
- SCX 旧逻辑确认：
  [runner/libs/app_runners/scx.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/scx.py:112) 之前保留按 scheduler 程序名筛 live programs 的路径；
  [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:301) 之前还保留 post-rejit 的 fallback 分支。
- 全局 grep 结论：
  program-level select/filter 相关分支已从 `runner/libs/app_runners/` 与 `e2e/cases/` 主路径删除；
  目前 `grep 'fallback|legacy|compat'` 仅剩 [runner/libs/app_runners/bcc.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/bcc.py:351) 的 Python compatibility shim，这不是 program selection 逻辑。

## 删除清单

- Tracee
  [runner/libs/app_runners/tracee.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tracee.py:438)
  删除 `events` 形参链，`build_tracee_commands(...)` 直接硬编码 `--events "*"`。
  [runner/libs/app_runners/tracee.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tracee.py:499)
  删除 `TraceeRunner.__init__` 的 `events` 参数和启动前 “至少一个 event” 校验。
  [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:326)
  `measure_latency_probes()` 改为对 collector 全量事件做匹配，不再按 latency probe event 名过滤。
  [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:403)
  `verify_phase_measurement()` 删除 primary-event 断言，改为直接看全量 `events_total`。
  [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:421)
  `measure_workload()` 删除 `primary_events_*` 派生字段，统一按全量 Tracee 事件统计。
  [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:550)
  `summarize_phase()` / [617](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:617) `summarize_workload_samples()` / [808](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:808) `compare_phases()` 全部切到 `events_per_sec`。
  [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:1138)
  `run_tracee_case()` 删除配置侧 `events` 读取与传递。

- Tetragon
  [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:89)
  用固定 `DEFAULT_POLICY_DIR` + `_tetragon_policy_paths()` 取代启动期 synthetic YAML 生成。
  [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:251)
  `TetragonRunner` 删除临时 policy 目录生命周期管理，直接引用静态目录。
  [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:283)
  `start()` 固定传 `--tracing-policy-dir <static dir>`。
  [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:319)
  `stop()` 删除临时目录清理。
  [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:136)
  删除整条 `cgroup-rate` workload 支持链和其中的 fallback，`run_tetragon_workload()` 只保留普通路径。
  [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:122)
  `measure_workload()` 删除 `exec_workload_cgroup` 透传。
  [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:226)
  `run_phase()` 删除 `exec_workload_cgroup` 分支参数。
  [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:559)
  case lifecycle 删除 `--cgroup-rate` 派生布尔量，只保留静态 policy pack 路径。
  [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:592)
  artifacts 里的 `policy_dir` / `policy_paths` 现在直接指向静态目录。

- BCC
  [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:68)
  删除 suite tools 子集选择逻辑，始终执行 `config.yaml` 中全部 tools。

- bpftrace
  [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:90)
  `suite_scripts()` 统一返回全量 `SCRIPTS`，删除按脚本名/子集再筛的路径。

- SCX
  [runner/libs/app_runners/scx.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/scx.py:112)
  删除 scheduler program name-based live filtering，只保留全量 live discovery。
  [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:301)
  `_resolve_scx_scheduler_prog_ids()` 删除 `fallback_to_all_live` / `fallback_to_logical` 兼容分支。
  [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:509)
  case workload 选择改为直接用全量 `workload_specs()`。

## 改配置清单

- [e2e/cases/tracee/config.yaml](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/config.yaml:1)
  删除顶层 `events:`，删除 workload 内 `primary_events` / `latency_probe_events`。
- [e2e/cases/tetragon/config_execve_rate.yaml](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/config_execve_rate.yaml:1)
  删除 `tetragon_extra_args: ["--cgroup-rate", "1000,1s"]`。
- [e2e/cases/tetragon/policies/10-kprobes.yaml](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/policies/10-kprobes.yaml:1)
  新增静态 kprobe policy pack，当前含 25 个 kprobe hooks。
- [e2e/cases/tetragon/policies/20-tracepoints.yaml](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/policies/20-tracepoints.yaml:1)
  新增静态 tracepoint policy pack，当前含 13 个 tracepoints。

## VM 验证结果

- `make check`
  已通过。
- `make vm-e2e`
  第一轮 run token: `run.x86-kvm.e2e.5ab0c0b5`
  结果：`tetragon` / `bpftrace` / `scx` / `bcc` / `katran` 通过，`tracee` 失败。
  失败明细：`tracee --events all` 在 guest 内被 upstream Tracee 0.24.1 拒绝，stderr 为 `Error: invalid event to trace: all`；
  对应结果目录：
  [e2e/results/tracee_20260423_193312_377876/result.json](/home/yunwei37/workspace/bpf-benchmark/e2e/results/tracee_20260423_193312_377876/result.json:1)、
  [e2e/results/tetragon_20260423_193339_605299/result.json](/home/yunwei37/workspace/bpf-benchmark/e2e/results/tetragon_20260423_193339_605299/result.json:1)、
  [e2e/results/bpftrace_20260423_193933_829543/result.json](/home/yunwei37/workspace/bpf-benchmark/e2e/results/bpftrace_20260423_193933_829543/result.json:1)、
  [e2e/results/scx_20260423_194644_839541/result.json](/home/yunwei37/workspace/bpf-benchmark/e2e/results/scx_20260423_194644_839541/result.json:1)、
  [e2e/results/bcc_20260423_195002_155387/result.json](/home/yunwei37/workspace/bpf-benchmark/e2e/results/bcc_20260423_195002_155387/result.json:1)。
  第一轮修复后，已把 Tracee 参数改成 `--events "*"`，正在用 `make vm-e2e E2E_CASE=tracee` 做单 case 复测，待通过后重跑全量 6/6。
- `make vm-corpus SAMPLES=1`
  待 `make vm-e2e` 完成并修复后执行。

## 最终 baseline.programs 总数 & per-app 分解

- 待当前 `vm-corpus` 完成后回填。

## git diff --shortstat

- 待最终整理后回填。

## 自我 review

- program-level select/filter 自查：
  当前 `runner/libs/app_runners/` 与 `e2e/cases/` 已无 `selected_tools` / `selected_scripts` / `primary_events` / `latency_probe_events` / `scheduler_program_names` / `fallback_to_all_live` / `fallback_to_logical` 残留。
- 兼容分支自查：
  Tetragon 旧 `cgroup-rate` 路径和 fallback 已删除；
  当前 `grep 'fallback|legacy|compat'` 剩余命中只在 BCC Python compatibility shim，不涉及 “全部 program / 子集 program” 二选一。
- 无谓新增代码自查：
  新增逻辑仅有静态 Tetragon policy pack 和对应静态目录装载；其余改动以删除旧分支、删配置、删 fallback 为主。
