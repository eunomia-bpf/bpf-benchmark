# Restore App Runners (2026-04-25)

## Scope

本次恢复目标按用户给定优先级覆盖：

1. `calico`
2. `suricata`
3. `systemd`
4. `loxilb`
5. `cilium`

其中前四个基于 `a849f182e5615f4a1279b33de9efa4670465cabd~1` 的历史 shared runner 形态恢复；`cilium` 在历史 shared runner 中不存在，因此新增了一个同风格的 app-level runner 壳。

## Code Changes

### 1. 恢复并适配 native app runner 基类

- 在 `runner/libs/app_runners/process_support.py` 重新引入 `NativeProcessRunner`。
- 适配到当前框架：
  - 基于现有 `ManagedProcessSession` 启动真实 userspace app。
  - 使用当前的 `run_named_workload()` 执行 workload。
  - 沿用现在的 `programs_after()`/`wait_until_program_set_stable()` 检测 live BPF program。
- 这一步修复了历史 runner 对已删除依赖 `NativeProcessRunner` 的断链。

### 2. 恢复 5 个 shared runner

新增/恢复：

- `runner/libs/app_runners/calico.py`
- `runner/libs/app_runners/suricata.py`
- `runner/libs/app_runners/systemd.py`
- `runner/libs/app_runners/loxilb.py`
- `runner/libs/app_runners/cilium.py`

实现特点：

- 全部保持为 **app-level runner** 形态，runner 只负责解析和启动真实 app binary，不直接加载 `.bpf.o`。
- binary 查找顺序统一优先：
  1. `BPFREJIT_REPO_ARTIFACT_ROOT/<app>/bin/...`
  2. `corpus/build/<app>/bin/...`
  3. `runner/repos/<app>/bin/...`
  4. 常见系统路径（如适用）

`systemd` 特殊处理：

- 保留历史按 app 名映射 binary 的行为：
  - `bind-iface` / `restrict-fs` / `restrict-ifaces` / `socket-bind` -> `systemd`
  - `sysctl-monitor` -> `systemd-networkd`
  - `userns-restrict` -> `systemd-nsresourced`
- 修正为运行时动态解析 repo artifact 路径，避免 import 时环境变量未设置导致路径缓存为空。

### 3. 注册 shared runner

更新 `runner/libs/app_runners/__init__.py`：

- 恢复 `calico`
- 新增 `cilium`
- 恢复 `loxilb`
- 恢复 `suricata`
- 恢复 `systemd`

同时新增：

- `_adapt_native_process()`
- `_adapt_systemd()`

用于把当前 schema v2 catalog workload 映射到 `NativeProcessRunner(workload_kind=...)`。

### 4. 恢复 macro app catalog / suite entries

更新 `runner/libs/benchmark_catalog.py`，新增：

- `calico/felix`
- `suricata/xdp-filter`
- `suricata/xdp-lb`
- `systemd/bind-iface`
- `systemd/restrict-ifaces`
- `systemd/socket-bind`
- `systemd/restrict-fs`
- `systemd/sysctl-monitor`
- `systemd/userns-restrict`
- `loxilb/default`
- `cilium/default`

更新 `corpus/config/macro_apps.yaml`，将上述 app 注册进当前 schema v2 `macro_apps` suite。

## Files Intentionally Left Unchanged

### `runner/repos.yaml`

未修改。原因：

- `calico`
- `suricata`
- `systemd`
- `loxilb`
- `cilium`

这些 repo 条目在当前工作树中都已经存在，不需要恢复。

### `runner/containers/runner-runtime.Dockerfile`

未修改。原因：

- 当前工作树里没有这 5 个 app 的稳定 userspace artifact 构建/打包链路；
- 本次任务先恢复 shared runner、注册和 import 链；
- runner 已优先支持 `BPFREJIT_REPO_ARTIFACT_ROOT/<app>/bin/...`，后续如果补 runtime artifact，只需要把 binary 放到既定目录即可，不必再改 runner 解析逻辑。

## Validation

已执行：

```bash
python3 -m py_compile \
  runner/libs/app_runners/__init__.py \
  runner/libs/app_runners/process_support.py \
  runner/libs/app_runners/setup_support.py \
  runner/libs/app_runners/calico.py \
  runner/libs/app_runners/cilium.py \
  runner/libs/app_runners/loxilb.py \
  runner/libs/app_runners/suricata.py \
  runner/libs/app_runners/systemd.py \
  runner/libs/benchmark_catalog.py
```

以及 import / suite 解析验证：

- `load_app_suite_from_yaml(corpus/config/macro_apps.yaml)` 成功
- `get_app_runner(...)` 成功实例化：
  - `CalicoRunner`
  - `SuricataRunner`
  - `SystemdRunner`
  - `LoxilbRunner`
  - `CiliumRunner`

当前 `macro_apps` 总条目数：`30`

## Current Boundary

本次恢复完成的是：

- shared runner 代码
- runner 注册
- macro app catalog
- suite manifest
- import / compile 链修复

本次没有额外实现：

- 这 5 个 app 在 `runner-runtime` 里的 userspace binary 构建/镜像提取链
- app-specific 网络拓扑 / 配置脚本
- 端到端 runtime smoke test

因此当前状态是：**框架级恢复完成，runtime artifact provisioning 仍依赖后续单独补齐。**
