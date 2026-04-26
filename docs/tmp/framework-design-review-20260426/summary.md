# Benchmark Framework Design Review (2026-04-26)

## 范围

本次 review 基于当前仓库代码，先阅读了以下背景材料：

- `CLAUDE.md`
- `docs/kernel-jit-optimization-plan.md` 前 200 行
- `docs/tmp/code-review-new-runners-20260426/summary.md`
- `docs/tmp/p0-fix-review-20260426/summary.md`

随后重点审查了这些实现：

- `corpus/driver.py`
- `runner/libs/app_runners/`
- `runner/libs/case_common.py`
- `runner/libs/workload.py`
- `e2e/cases/`
- `runner/libs/benchmark_catalog.py`
- `runner/libs/bpf_stats.py`
- `Makefile`

本报告不涉及代码修改，只给设计层面的结论和修复优先级。

## 总结

当前框架最大的问题不是某一处单点 bug，而是 **测量隔离性和 workload 命中证明不足**。这会直接影响结果可解释性，尤其是 corpus。

最关键的结论有 4 个：

1. `corpus` 的 post-ReJIT 吞吐量不是单 app 隔离测量，而是“所有存活 app 都已经 ReJIT 后”的混合结果。`tetragon 287 个 program 全 applied，但吞吐只有 0.365x` 很可能不能直接归因到 tetragon 本身。
2. 框架没有验证 workload 是否真的触发了被追踪的 BPF 程序。即使 `run_cnt_delta == 0`，当前 app 仍可能报 `status=ok`。
3. 新增的 `calico` / `cilium` corpus workload 现在是 `exec_storm`，这和它们的设备绑定 datapath 程序不匹配，结果目前不可信。`otel` 比前两者更有可能被触发，但框架同样没有证明。
4. `corpus` 的 program 重新发现逻辑仍会接受部分匹配集合，可能静默缩小或替换 session 的 tracked program set，进而污染后续 stats。

所以，当前框架在“能不能跑通”层面基本可用，但在“结果能不能可信地解释”层面，尤其是 corpus，仍然没有过线。

## 详细问题

### P0: Corpus 的 post-ReJIT 吞吐量被整套 app 的全局 ReJIT 污染，不能解释成单 app 效果

相关位置：

- `corpus/driver.py:396-410`
- `corpus/driver.py:436-450`
- `runner/libs/case_common.py:240-299`

问题机制：

- `corpus/driver.py` 先把 suite 里的所有 app 全部启动起来。
- 然后调用 `run_lifecycle_sessions()` 统一跑 baseline / apply / post-ReJIT。
- `run_lifecycle_sessions()` 的顺序是：
  - 对所有 session 先测 baseline。
  - 对所有 session 依次执行 ReJIT。
  - 对所有 session 再测 post-ReJIT。

这意味着：

- 当测 `app A` 的 baseline 时，其他 app 也已经在系统里。
- 当测 `app A` 的 post-ReJIT 时，`app B..N` 也已经被 ReJIT 过。

因此 corpus 里记录的吞吐量比值，并不是“只改了 app A 的 BPF 程序之后的影响”，而是“整套并行存活 app 里，已有若干 app 先后被 ReJIT 后的混合影响”。

这对共享 workload 特别致命，例如：

- `exec_storm`
- `open/file` 类 workload
- `connect` / `network` 类 workload

这些 workload 会同时命中多个观测器类 app。最后拿到的吞吐下降，无法可靠归因到单个 app。

这也是我对 `tetragon 287 个 program 全 applied 但吞吐 0.365x` 的第一判断：**当前 corpus 方法学本身就不足以支持“这是 tetragon 自身导致的 63% 退化”这个结论**。

### P0: 框架没有验证 workload 是否真的触发了 tracked BPF programs

相关位置：

- `corpus/driver.py:96-112`
- `corpus/driver.py:475-507`
- `runner/libs/bpf_stats.py:72-92`

当前 `_measure_runner_phase()` 的逻辑只是：

- workload 前采一次 `sample_bpf_stats()`
- workload 跑若干次
- workload 后再采一次
- 用 `compute_delta()` 算差值

但它没有做任何“正触发”验证，例如：

- 是否至少一个 program 的 `run_cnt_delta > 0`
- 是否至少核心 target program 被命中
- 是否 stats 全部为 0 但 workload 又成功返回

结果分类只看这些条件：

- lifecycle/fatal error
- ReJIT apply error
- baseline 缺失

没有把“workload 完全没打到程序”当成错误或至少警告。

后果：

- workload 可能完全 miss 掉目标程序，结果仍显示 `status=ok`
- 新增 app 即使从未真正触发其关键 BPF 路径，也能生成“看起来正常”的 benchmark JSON
- 这使得 corpus 结果在统计上可读，但在语义上可能是空转数据

这也是目前新 app 可信度不足的根本原因之一。

### P0: `calico` / `cilium` 的新 workload 设计仍然不可信

相关位置：

- `runner/libs/benchmark_catalog.py:79-81`
- `runner/libs/app_runners/calico.py:54-100`
- `runner/libs/app_runners/cilium.py:42-80`
- `runner/libs/workload.py:460-496`

当前 catalog 里：

- `calico/felix -> exec_storm`
- `cilium/agent -> exec_storm`
- `otelcol-ebpf-profiler/profiling -> exec_storm`

但 runner 本身清楚表明：

- `CalicoRunner` 通过 `FELIX_BPFDATAIFACEPATTERN` / `FELIX_BPFL3IFACEPATTERN` 绑定某个网络设备
- `CiliumRunner` 通过 `--devices` / `--direct-routing-device` 绑定某个网络设备

它们的关键程序是网络 datapath / tc / XDP 方向，而 `exec_storm` 只是 `stress-ng --exec`。

也就是说，当前 workload 形状和被测程序形状根本不一致。

这比之前“loopback `wrk` 未必经过 datapath”更严重，因为现在连网络形状都没有了。对 `calico` / `cilium` 来说，当前 corpus 结果几乎没有证明力。

对 `otelcol-ebpf-profiler`，情况略好一些，因为它是主机侧 profiler，CPU/exec 活动有可能触发采样程序；但当前框架仍然没有验证 `run_cnt_delta > 0`，所以依然不能证明 workload 真的命中了期望的 BPF 逻辑。

### P0: Corpus 的 program rediscovery 仍会接受“部分替换集合”，可能静默污染后续测量

相关位置：

- `corpus/driver.py:167-240`
- `corpus/driver.py:243-320`

当前 rediscovery 路径是：

- 若 tracked ids 消失，则尝试从 runner refresh 或全局 `bpftool prog show` 中重新发现
- 通过 `_program_identity()` 做匹配
- 只要匹配到非空集合，就接受

问题有两个：

1. `_program_identity()` 过弱，只用 `name/type/attach_type/attach_target/attach_btf_name/attach_btf_id`。
2. `_refresh_active_session_programs()` 只在“一个都找不到”时抛错；如果只找回部分集合，只会打印 warning，然后继续用刷新后的子集覆盖状态。

这意味着：

- 一个 session 原本跟踪 20 个程序，丢了 7 个，只找回 13 个，当前逻辑仍继续测。
- 更糟的是，如果系统里存在相同 identity 的别的程序，可能被错误认领到该 session。

后果不是立即 crash，而是 **静默地自我腐蚀测量对象**。这种问题对 benchmark 最危险，因为输出看上去仍然完整。

### P1: Runner 的进程生命周期设计不稳，可能导致残留进程和脏环境

相关位置：

- `runner/libs/app_runners/process_support.py:202-281`
- `runner/libs/app_runners/process_support.py:357-372`
- `runner/libs/app_runners/etcd_support.py:163-250`
- `runner/libs/agent.py`（`stop_agent()` 只停直接子进程）

观察：

- `ManagedProcessSession` 和 `LocalEtcdSession` 都是 plain `subprocess.Popen(...)`
- 没有 `start_new_session=True`
- 没有统一的 process group 管理
- `close()` / `stop_agent()` 只对主 PID 发信号

如果 app 或 etcd 再 fork 子进程，当前设计不能保证：

- 全部子进程被清干净
- 所有 fd / mount / helper 进程都被回收
- BPF 程序不会跨 case / 跨 app 泄漏

另外，`NativeProcessRunner.run_workload()` 和 `run_workload_spec()` 只检查 `self.session is not None`，不检查实际进程是否已经退出。如果原始进程启动后崩溃，但残留 BPF 对象还在，后续 workload 仍可能继续跑，产生误导性结果。

### P1: 新增 app 没有自己的 E2E case，只有 corpus 覆盖，验证闭环不完整

相关位置：

- `e2e/driver.py:66-92`
- `e2e/driver.py:124`
- `corpus/config/macro_apps.yaml:15-17`

当前 E2E 驱动只覆盖：

- `tracee`
- `tetragon`
- `bpftrace`
- `bcc`
- `katran`

新增的：

- `calico`
- `cilium`
- `otelcol-ebpf-profiler`

只出现在 corpus suite 里，没有专门 E2E case。

这会产生两个问题：

- runner 改动没有 app-specific 验证闭环
- corpus 又不验证命中性，所以“能跑通”不等于“真的测到了目标程序”

对新 app 来说，这相当于只有启动冒烟测试，没有真正的 benchmark correctness case。

### P1: App/workload 定义面已经开始漂移，框架表面通用，实际能力被压扁

相关位置：

- `runner/libs/app_suite_schema.py:20-24`
- `runner/libs/app_suite_schema.py:83-150`
- `runner/libs/app_runners/__init__.py:11-72`
- `corpus/config/macro_apps.yaml:1-26`
- `runner/libs/benchmark_catalog.py:68-93`

这里有三层漂移：

1. `AppSpec.workload_for(mode)` 接收 `mode`，但无论 `corpus` 还是 `e2e` 都返回同一个 workload。
2. schema v2 的 YAML 只允许写 app `name`，实际 runner/workload/duration 都锁死在 Python catalog 中。
3. adapter 层把 workload 进一步压扁成单个 `kind` 或 `workload_kind` 字符串。

例如：

- `_adapt_native_process()` 只留下 `workload_kind`
- `_adapt_bcc()` 也把 richer `workload_spec` 压成 `{"kind": ...}`

这和设计文档里“YAML 可按 mode 组织 app/workload”以及“app-centric workload 建模”的方向已经明显偏离。结果就是：

- 表面上看有 suite schema / catalog / adapter 三层抽象
- 实际上很多 runner 只能消费一个字符串
- 一旦新 app 需要更精细的触发条件，就容易被塞进错误的 generic workload

`calico/cilium -> exec_storm` 就是这个问题的直接体现。

### P1: Makefile 把 corpus 默认样本数压成 1，和 Python 层默认值冲突，显著降低结果稳定性

相关位置：

- `runner/libs/benchmark_catalog.py:7`
- `corpus/driver.py:91-93`
- `runner/suites/corpus.py:39`
- `Makefile:34`
- `Makefile:55-58`
- `Makefile:98-99`

Python 层默认值是：

- `DEFAULT_CORPUS_SAMPLES = 30`
- 当 `--samples=0` 时回退到 30

但 suite 入口层：

- `runner/suites/corpus.py` 强制要求 `--samples`
- `Makefile` 又把 `VM_CORPUS_SAMPLES ?= 1`
- `vm-corpus` 默认总是传 `--samples 1`

所以实际 canonical 入口 `make vm-corpus` 跑出来的是单样本 corpus，不是驱动层默认的 30 样本。

影响：

- 噪声大
- 对短 workload 更敏感
- 更容易把偶发波动误读成 ReJIT 效果

如果要讨论 10% 以内的变化，默认 1 sample 基本不够；即使是 63% 这种大波动，也会让定位更加困难。

### P2: E2E case 结构已经分叉，公共 lifecycle 没有形成统一结果契约

相关位置：

- `e2e/cases/bcc/case.py:69-98`
- `e2e/cases/bcc/case.py:121-172`
- `e2e/cases/katran/case.py:93-131`
- `e2e/cases/tetragon/case.py:87-101`
- `e2e/cases/tetragon/case.py:283-300`
- `e2e/cases/tracee/case.py:330-348`

目前至少有两条风格：

- `bcc` / `katran` 走 `run_app_runner_lifecycle()`，再用 `phase_payload()` 显式包装 `status/reason/measurement`
- `tetragon` / `tracee` 返回的是自定义结构，比如 `{"phase": ..., "records": [...]}`，没有完全复用相同的 phase envelope

这会带来两个问题：

1. case 之间 payload 契约不一致，调用方和 review 逻辑都更难复用。
2. 同一类错误在不同 case 的呈现方式不同，更容易再次出现“某个 case 自己忘了把 apply error 映射到 phase status”的回归。

之前 tetragon 的问题已经证明这不是理论风险，而是已发生过的设计后果。

### P2: `enable_bpf_stats()` 这个 API 现在是误导性的 no-op

相关位置：

- `runner/libs/bpf_stats.py:9-12`
- `runner/suites/_common.py:156-174`
- `runner/suites/corpus.py:76`

当前 `enable_bpf_stats()` 只是：

```python
@contextmanager
def enable_bpf_stats():
    yield {"mode": "bpftool"}
```

真正启用 `/proc/sys/kernel/bpf_stats_enabled=1` 的逻辑在 suite 入口层。

这本身不会让标准 `vm-corpus` / `vm-e2e` 路径直接出错，但会造成两个设计问题：

- API 名称和行为不一致
- 如果有人直接调用 case 或 driver，以为 `with enable_bpf_stats():` 已足够，结果其实不安全

这种表面“有保护”，实际“没做事”的接口很容易让后续维护者误判。

### P2: 设备选择和清理逻辑对环境过于敏感，影响可复现性

相关位置：

- `runner/libs/app_runners/etcd_support.py:79-133`
- `runner/libs/app_runners/calico.py:54-57`
- `runner/libs/app_runners/cilium.py:42-50`
- `runner/libs/app_runners/cilium.py:77-80`

`detect_primary_interface()` 的策略是：

- 优先 default route 设备
- 否则取第一个非 `lo` 设备
- 再不行才创建 benchmark veth

这对通用“能跑”没问题，但对 benchmark 不够可控。它可能选到：

- `docker0`
- 历史残留的 `cilium_*`
- 宿主机上并非期望 datapath 的接口

当前 `calico` / `cilium` 又把这个接口直接拿来作为关键 attach 目标，因此结果会强依赖环境布局，不利于复现。

此外，`ensure_benchmark_interface()` 还在，但新路径几乎不主动使用它，说明仓库里仍保留了一套网络 scaffold，却没有被整合成当前 network app 的确定性基线。

### P2: Cilium / Otel 还有一些次一级可维护性问题

相关位置：

- `runner/libs/app_runners/etcd_support.py:300-307`
- `runner/libs/app_runners/otel_profiler.py:106-122`

观察：

- `CiliumRunner` 把 `runtime_dir/bpffs` 作为 `--bpf-root`，`stop()` 最终只是 `shutil.rmtree(...)`。如果该路径上真的被 mount 成 bpffs，删除目录未必等于清掉 mount。
- `OtelProfilerRunner.start()` 把 `config_path` 放进 artifacts，但 `stop()` 会删掉整个 runtime dir，导致结果里保存的 artifact 路径在事后通常已经不存在。

这两点不是当前最严重的问题，但都削弱了复盘和环境清理的可靠性。

## 关于 workload / BPF stats 采集是否“科学”

结论分两层：

1. **BPF stats 数学本身基本合理。**
   - `sample_bpf_stats()` 直接读 `bpftool prog show` 暴露的 `run_cnt/run_time_ns`
   - `compute_delta()` 计算 `run_cnt_delta/run_time_ns_delta/avg_ns_per_run`
   - 这套统计口径本身没有明显方向性错误

2. **真正的问题在编排，不在公式。**
   - 没有验证 workload 是否命中程序
   - corpus 在多 app 并存下做“单 app”吞吐解释
   - rediscovery 可能替换 program set
   - 默认样本数过低

所以不能简单说“BPF stats 采集错了”；更准确地说，是 **stats 读法基本对，但实验设计和对象绑定还不够严谨**。

## 关于 “tetragon 287 个 program 全 applied，但吞吐 0.365x” 的判断

基于当前框架，我不认为可以直接把这个结果解释成：

> ReJIT 成功应用到 tetragon 全部程序，但 tetragon 自身导致吞吐下降 63%

更合理的解释顺序应该是：

1. corpus 方法先天存在跨 app 污染，post-ReJIT 吞吐并非 tetragon 单独效果。
2. 如果这次是 canonical 入口跑出来的，默认 `samples=1`，结果稳定性本身也偏弱。
3. tetragon workload (`tetragon_exec_connect_mix`) 与其他观测器类 app 共存时，系统级竞争和共享 hook 干扰都可能被吸进结果。

因此，这个 `0.365x` 目前更像是：

- “整个 corpus 并行环境在某个测量时刻的复合效应”

而不是：

- “tetragon 287 个程序 individually/all-together 的纯净 ReJIT 代价”

如果想回答这个问题，至少要先做到：

- 单 app 隔离测量
- 明确证明 workload 命中了 tetragon 相关程序
- 提高 samples

## 对新增 app workload 的具体判断

### calico

当前不可信。

原因：

- runner 明确按网卡 attach
- workload 却是 `exec_storm`
- 框架没有 `run_cnt_delta > 0` 验证

### cilium

当前不可信。

原因同上，而且 `--devices/--direct-routing-device` 更明确表明它在测 datapath，不是在测 exec 事件。

### otelcol-ebpf-profiler

比前两者更 plausible，但仍然缺少证明。

原因：

- profiler 可能因整体 CPU 活动而采样
- 但当前没有任何断言证明目标 BPF 程序被实际命中
- artifact 还保留了一个 stop 后会消失的 config path，不利于复盘

## 对 CLAUDE.md 设计规则的符合性检查

### No ReJIT Filtering

本次审查范围内，**没有看到当前代码显式违反这条规则**。没有发现：

- 针对某些 program 的 `live_rejit_programs()` 过滤
- `before_rejit` 里按 app/pass 主动跳过
- benchmark 配置里的 per-prog_type exclusion
- 显式 exclusion list

但要注意，`corpus/driver.py` 的 rediscovery 逻辑虽然不是“主动过滤”，却可能在 tracked ids 丢失后 **被动缩小** session 的 program set。它不违反字面规则，但会产生近似于“测少了程序”的效果，风险同样很高。

### App-Level Loader Only

本次审查范围内，新增 app 的路径基本符合这条规则：

- `calico` / `cilium` / `otel` 都通过真实应用进程启动装载程序
- 没看到框架直接去加载这些 app 的 `.bpf.o`

`katran` 仍保留 `xdp_root` bootstrap 相关特殊处理，但这属于 `CLAUDE.md` 明确允许的例外。

## 修复优先级建议

### 第一优先级

1. 把 corpus 改成真正可解释的测量模式。
   - 至少要做到单 app 隔离 baseline/post-ReJIT。
   - 如果坚持多 app 共存，也必须把结果定义成“整套系统 effect”，不能再按单 app 解释。

2. 在 corpus 和新 app runner 路径里加入“正触发”验证。
   - 最低要求：baseline/post 两阶段都检查至少一个 target program 的 `run_cnt_delta > 0`。
   - 最好还能区分“核心程序命中”与“边缘程序命中”。

3. 为 `calico` / `cilium` 设计真实网络 workload，并让流量经过被 attach 的设备。

4. 禁止 rediscovery 接受部分 program set 继续测量。
   - 数量不一致应直接失败，而不是 warning 后继续。

### 第二优先级

5. 给 `calico` / `cilium` / `otel` 增加专门 E2E case。
6. 收敛 workload schema，别再把复杂 workload 需求压成单个字符串。
7. 修正 `Makefile` 的 corpus 默认样本数，至少不要默认 1。

### 第三优先级

8. 统一进程组清理和 liveness 检查。
9. 统一 E2E case phase payload 契约。
10. 清理 no-op / dangling artifact / 设备选择漂移这类可维护性问题。

## 最终判断

当前框架已经比之前版本更接近统一 lifecycle，也基本遵守了 `CLAUDE.md` 的显式红线；但从 benchmark 设计角度看，**结果可信度仍然没有完全建立起来**。

如果现在要我给一句话结论：

> 框架可以继续作为集成底座演进，但还不适合把 corpus 数值当成严格的单 app 性能证据，尤其不能据此解读 calico/cilium/otel 和 tetragon 的异常结果。

最需要先修的不是更多 runner，而是 **测量隔离、workload 命中验证、program 集合稳定性** 这三件事。
