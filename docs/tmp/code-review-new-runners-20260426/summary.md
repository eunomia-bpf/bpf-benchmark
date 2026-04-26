# New Runner Code Review

## runner/libs/app_runners/process_support.py

- [BUG] `wait_until_program_set_stable()` 只用“程序数量是否变化”判断稳定（`45-93`，尤其 `68-73`）。如果 app 在相同 program count 下做 one-for-one program replacement，这里会把仍在变动的集合误判为稳定，返回过期或中间态的 program set。对会动态 reconcile datapath 的 agent（Cilium/Calico）这是实质性错误。
- [WARN] `ManagedProcessSession`/`NativeProcessRunner.stop()` 只管理直接子进程（`198-206`, `259-268`, `361-373`），没有 `start_new_session=True` / process-group kill。若 loader/wrapper 再 fork 子进程，`stop()` 可能只杀掉父进程，遗留子进程和未关闭的 stdout/stderr fd，形成资源泄漏或僵尸进程。
- [WARN] `run_workload()` / `run_workload_spec()` 只检查 `self.session is not None`（`344-359`），不检查进程是否已经退出。`corpus/driver.py` 会先把所有 app 拉起来再做 baseline，这给“start 成功后、baseline 前进程已崩”的错误路径留下了窗口。
- [WARN] `ManagedProcessSession.__enter__()` 把“看到了任意新 BPF program”当作 app 健康条件（`213-218`）。这对有多阶段初始化的 agent 不够强，可能在 control-plane 尚未 ready 时就开始后续流程。

## runner/libs/app_runners/etcd_support.py

- [WARN] `_reserve_local_port()` 是典型 bind-close-reuse TOCTOU（`136-140`），而 `LocalEtcdSession.start()` 在真正拉起 etcd 前连续做两次 reservation（`169-172`）。这两个端口既可能被其他进程抢占，也可能两次都拿到同一个端口，导致 etcd client/peer listener 冲突。
- [WARN] `detect_primary_interface()` 在没有 default route 时退化成“取第一个非 lo 网卡”（`127-133`）。在有 `docker0`、`cilium_*`、残留 veth 的环境里，这很容易选错 attach 设备，导致后续 workload 根本打不到目标 datapath。
- [NOTE] `ensure_benchmark_interface()` 会创建全局共享的 `bpfbench0`/`bpfbench1` veth pair（`79-109`），但当前模块和调用者都没有在 `stop()` 里回收它。固定名字避免了无限累积，但会把共享网络状态留到后续测试。
- [NOTE] 这组代码没有发现 ReJIT filtering/skip 逻辑，也没有直接加载 `.bpf.o`，符合当前设计约束。

## runner/libs/app_runners/calico.py

- [BUG] `CalicoRunner` 没有自定义 workload，最终经由 `_adapt_native_process()` + `NativeProcessRunner._run_workload()` 走了 catalog 里的通用 `network` workload（[__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/__init__.py:69), [benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:79), [process_support.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/process_support.py:318), [workload.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py:1061)）。这个 workload 只是 `wrk` 打本机 loopback HTTP server，不会经过 Felix 绑定的 `self.device`（`54-56`, `74-91`），所以很可能完全没有触发要测的 BPF datapath 程序。
- [NOTE] 启动路径是 `calico-node -startup` + `calico-node -felix`（`58-68`），没有直接 load `.bpf.o`，满足 app-level loader only。
- [NOTE] 该文件未发现 ReJIT filtering/skip 逻辑。

## runner/libs/app_runners/cilium.py

- [BUG] 和 Calico 一样，`CiliumRunner` 没有覆盖 workload，`cilium/agent` 当前也落到 catalog 的通用 `network` workload（[benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:81), [process_support.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/process_support.py:318), [workload.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py:1061)）。但 agent 明确把 datapath 绑定在 `--devices` / `--direct-routing-device` 上（`52-82`），loopback `wrk` 基本不会穿过这些程序。
- [WARN] runner 只是在 runtime dir 下创建了一个普通目录并作为 `--bpf-root` 传给 `cilium-agent`（`45-48`, `77`），`stop()` 端则只做 `shutil.rmtree(..., ignore_errors=True)`（[etcd_support.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/etcd_support.py:300)）。如果 agent 在该路径下 mount 了 bpffs，这里会静默泄漏 mountpoint。
- [NOTE] 启动路径走的是 `cilium-agent` 自身，没有直接 load `.bpf.o`。
- [NOTE] 该文件未发现 ReJIT filtering/skip 逻辑。

## runner/libs/app_runners/otel_profiler.py

- [WARN] `start()` 把 `config_path` 记录到 `artifacts`（`106-107`），但 `stop()` 总会删除整个 `_runtime_dir`（`110-122`）。这意味着停止后留下的是悬空路径，不利于复现和事后分析。
- [NOTE] 本文件没有看到明显的 loader/cleanup 逻辑错误；主要风险继承自 `NativeProcessRunner` 的进程管理和 program discovery。
- [NOTE] 启动使用上游 `otelcol-ebpf-profiler` 二进制和临时配置文件，没有直接 load `.bpf.o`，也没有 ReJIT filtering/skip 逻辑。

## runner/libs/app_runners/setup_support.py

- [NOTE] 未发现明显正确性问题。
- [NOTE] `_read_elf_machine()` 用了 `candidate.read_bytes()[:20]`（`20-34`），会先把整个文件读入内存再切前 20 字节。对大二进制只是低优先级性能问题，不影响 correctness。

## runner/libs/app_runners/__init__.py

- [WARN] `_adapt_bcc()` 已经有 `BCCToolSpec.workload_spec`，但实际会丢掉它，重新构造一个只有 `kind` 的 workload（`17-33`）。现在还能工作，是因为下游 workload 名字被手工 special-case 了；以后只要某个 BCC tool 需要额外 workload 参数，这里就会静默丢失。
- [NOTE] `_adapt_native_process()` 目前完全通用（`69-72`），因此 Calico/Cilium/Otel 都会继承同一套 generic workload 语义。对 datapath 类 app，这已经直接导致了错误的 workload trigger。
- [NOTE] `get_app_runner()` 本身没有发现 ReJIT filtering/skip 逻辑。

## runner/libs/benchmark_catalog.py

- [BUG] `calico/felix` 和 `cilium/agent` 都被绑定到 `workload="network"`（`79`, `81`）。而 `network` 在 workload 层实际是 loopback `wrk`（[workload.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/workload.py:1061)），不是经过 attach 设备的数据面流量。这会让 corpus 看起来“有 workload、有 stats”，但没有真正测到目标 datapath 程序。
- [NOTE] `otelcol-ebpf-profiler/profiling` 当前使用 `exec_storm`（`80`）更像“触发一点 CPU 活动”而不是“稳定的 profiler hot path”。这不是立即的 correctness bug，但代表性偏弱。

## corpus/driver.py

- [BUG] `_refresh_active_session_programs()` 通过“当前全局 program table 减去每个 session 的 `before_prog_ids`，再按 reverse order 用 `claimed_ids` 去重”来重建 live programs（`141-151`）。这在“较早启动的 app 之后又 reload 出新 program ID”时会错配：这些新 ID 不在较晚 session 的 `before_prog_ids` 里，后面的 session 会把前面 app 的 programs 抢走。Cilium/Calico 正是最可能出现这种动态 reload 的 app。
- [WARN] driver 会先启动整个 suite 再进入 baseline（`228-245` 之后才有 `270-285`）。这显著拉长了 `runner.start()` 到第一次 measurement 的时间窗口，使 native app 崩溃、program ID 漂移、program ownership 变化更容易发生。
- [NOTE] 好的一点是，这个文件没有引入 ReJIT filtering；`apply_result.error` 会被提升为 app failure（`318-326`），不会把 ReJIT 失败伪装成成功。

## e2e/cases/bcc/case.py

- [NOTE] 未发现明显 bug。该文件会把 `rejit_result.error` 提升成 `post_rejit` 失败（`87-92`），并据此把 case 记为 error（`152-157`），符合零静默失败。

## e2e/cases/bpftrace/case.py

- [NOTE] 未发现明显 bug。和 BCC case 一样，它正确把 `rejit_result.error` 映射成 `post_rejit` 失败（`106-110`），不会把 apply 失败当成功。

## e2e/cases/katran/case.py

- [NOTE] 未发现明显 bug。该 case 同样会把 `rejit_result.error` 升级为 `post_rejit` 失败（`103-107`），并把 suite status 置为 error（`110-130`）。

## e2e/cases/tetragon/case.py

- [BUG] `rejit_result.error` 只被追加到 `limitations`（`264-269`），最终 payload 仍然返回 `status: "ok"`（`272-286`）。这会把 ReJIT/apply 失败伪装成成功，违反零静默失败。
- [BUG] `post_rejit` 缺失也只是追加 limitation（`269-270`），没有让 case fail。E2E 缺失 post-ReJIT measurement 不应该被当作成功。
- [NOTE] 好的一点是，这里显式拒绝手工 `.bpf.o` fallback（`157-165`），符合 app-level loader only。

## e2e/cases/tracee/case.py

- [BUG] success path 从头到尾都没有检查 `lifecycle_result.rejit_result["error"]`。每个 cycle 只把原始结果塞进 `rejit_result`（`339`），最后直接返回 `status: "ok"`（`355-371`）。也就是说，即使所有 apply 都失败，只要 baseline/post-ReJIT workload 跑完，这个 case 仍会被报告为成功。
- [NOTE] 最终 payload 只保留第一次 cycle 的 `tracee_programs`（`340-341`）。如果后续 cycle 有 program reload，summary 会低报实际运行过的 programs。
- [NOTE] 该文件同样拒绝手工 `.bpf.o` fallback（`230-241`），符合 app-level loader only。

## Summary

- [BUG] 最严重的问题有三类：
  1. Calico/Cilium 的 workload trigger 错了，当前测到的是 loopback `wrk`，不是 attach 设备上的 datapath。
  2. `process_support.py` / `corpus/driver.py` 的 program discovery 和 ownership 归属逻辑过于脆弱，遇到动态 reload 会错认 program set。
  3. Tracee/Tetragon E2E 会把 ReJIT/apply 失败报告成成功。
- [WARN] 进程/资源管理的主要风险是：只杀父进程、不杀 process group；Cilium 可能泄漏 bpffs mount；benchmark veth/interface 选择与回收不够确定。
- [NOTE] 本轮 review 没有在目标文件中发现违反两条硬约束的代码：
  1. 没有发现 ReJIT filtering/skip/exclusion 逻辑。
  2. 没有发现直接 load `.bpf.o` 的路径；新 runner 都是通过应用自身启动路径加载 BPF。
- [NOTE] 当前 `e2e/cases/` 里没有 Calico/Cilium/Otel 的 case，所以新增 native runner 栈的主要风险实际上只靠 corpus 覆盖，缺少针对性 E2E 兜底。

## Fix Priority

1. P0: 修正 `calico` / `cilium` 的 workload trigger。需要 runner 级自定义 workload，并同步修正 catalog，确保流量真的经过 attach 设备。
2. P0: 修正 `e2e/cases/tetragon/case.py` 和 `e2e/cases/tracee/case.py` 的错误传播，`rejit_result.error` 和缺失 `post_rejit` 必须直接让 case fail。
3. P0: 修正 `wait_until_program_set_stable()` 和 `corpus/driver.py::_refresh_active_session_programs()`，按 program identity/ownership 跟踪，而不是按 count 和“全局减基线”的启发式。
4. P1: 给 `ManagedProcessSession` / `LocalEtcdSession` 加 process-group 级 stop 和存活检查，避免子进程泄漏、早退后继续 workload。
5. P1: 给 Cilium 加显式 bpffs/mount cleanup；明确 synthetic benchmark interface 的创建、选择和回收策略。
6. P2: 清理低优先级设计问题，例如 `__init__.py` 丢弃 `BCCToolSpec.workload_spec`、`otel_profiler.py` 删除了仍被 artifact 引用的配置文件路径、`setup_support.py` 的整文件读取 ELF header。
