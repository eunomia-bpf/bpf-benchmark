# cilium-agent 是否可关闭 BPF 自动 reconcile / refresh / reload 调研（2026-04-26）

## 结论

- 没有找到一个官方公开、文档化的 `cilium-agent` 开关，可以“一键冻结” BPF datapath，彻底关闭自动 reconcile / reload / regenerate。
- 能直接相关地收紧自动行为的公开开关，主要只有两个：
  - `--endpoint-regen-interval=0`
  - `--endpoint-bpf-prog-watchdog-interval=0`
- 但这两个都不是“彻底冻结 BPF program ID”的总开关：
  - `endpoint-regen-interval` 关掉的是周期性 endpoint regeneration，而且源码显示它走的是 `RegenerateWithoutDatapath`，未必会触发 datapath program reload。
  - `endpoint-bpf-prog-watchdog-interval` 关掉的是“发现 endpoint BPF program 丢失后自动 reinitialize”的修复路径。
- 真正会导致 datapath 级别重载、从而更可能造成 BPF program ID 变化的核心路径，是 datapath orchestrator 的 `Reinitialize()`。我没有找到公开 flag 可以禁用这条主 reconcile 路径。
- 还发现一个 hidden flag：`--bpf-policy-map-full-reconciliation-interval`。它只影响 endpoint policy map 的 full reconciliation，不是 BPF program reload 总开关。
- `-D/--debug`、`--debug-verbose`、`--pprof`、`--enable-dynamic-config`、`--enable-drift-checker`、`--enable-dynamic-lifecycle-manager` 都不是“冻结 datapath”的方案。
- `DryMode` 在源码里存在，但没有发现对外 CLI flag / 官方文档入口，更像内部或测试用途。

## 调研范围

- 官方文档：Cilium stable cmdref、官方配置文档
- 源码：`cilium/cilium` `main` 分支，调研时 HEAD 为 `6e3229eb7044bb1c44f3764c50a076430d45e335`
- 社区：`cilium/cilium` issue

说明：

- 本次没有单独构建本地 `cilium-agent` 二进制执行 `--help`。
- 这里把官方 `cmdref` 视作 help output 的权威等价物，因为它就是由 CLI flag 集生成的官方命令参考。

## 1. 官方文档 / help output 里有没有“禁用 BPF reconcile”的选项

结论：没有找到公开文档化的 `disable-reconcile` / `freeze-datapath` / `disable-reload` 之类选项。

官方 cmdref 里能找到的最接近开关是：

- `--endpoint-regen-interval duration`
  - 说明：`Periodically recalculate and re-apply endpoint configuration. Set to 0 to disable`
  - 含义：关掉周期性 endpoint regeneration
- `--endpoint-bpf-prog-watchdog-interval duration`
  - 说明：`Interval to trigger endpoint BPF programs load check watchdog`
  - 含义：控制 watchdog 检查 endpoint BPF program 是否被意外移除
- `-D, --debug`
  - 说明：仅开启 debug logging
- `--debug-verbose`
  - 说明：仅选择 verbose debug group
- `--pprof`
  - 说明：仅开启 pprof debugging API

官方 cmdref 中没有发现以下类型的公开开关：

- 关闭 datapath orchestrator reconcile
- 关闭 `Reinitialize()`
- freeze endpoint datapath
- dry-run / dry-mode（公开 CLI 形式）

## 2. 源码里 reconcile / reload / regenerate 相关的 flag / config

### 2.1 `--endpoint-regen-interval`

这是最容易误判成“关闭 reload”的开关，但源码显示它只负责周期性 endpoint regeneration。

- flag 定义在 `pkg/endpointmanager/config.go`
- 默认值是 `2m`
- `pkg/endpointmanager/cell.go` 里只有当它 `> 0` 时才注册周期控制器
- 触发后走 `pkg/endpointmanager/manager.go` 的 `WithPeriodicEndpointRegeneration()`
- 关键点：这条路径的 `RegenerationLevel` 是 `RegenerateWithoutDatapath`

这意味着：

- `--endpoint-regen-interval=0` 的确能关掉“每隔一段时间做一次全 endpoint regeneration”
- 但从源码语义看，它不是 datapath program reload 的主路径
- 如果你的 benchmark 现象是 “BPF program 被卸掉又重装，program ID 变化”，单独关这个 flag 很可能不够

### 2.2 `--endpoint-bpf-prog-watchdog-interval`

这是第二个和 program churn 更直接相关的公开开关。

- flag 定义在 `pkg/endpoint/watchdog/ep-bpfprog-watchdog.go`
- 默认值是 `30s`
- 同文件里当 interval 为 `0` 时，watchdog 直接不注册
- 同文件还明确写了：如果 watchdog 发现 endpoint BPF programs 不见了，就调用 `orchestrator.Reinitialize(ctx)`

这意味着：

- `--endpoint-bpf-prog-watchdog-interval=0` 可以关闭“发现 program 丢失后自动重装”的这条路径
- 如果 benchmark 环境里有别的东西在动 tc/BPF link，导致 Cilium 的 endpoint programs 被拔掉，这个开关会明显影响自动恢复行为

### 2.3 datapath orchestrator 的主 reconcile / reload 路径

真正更接近“自动 reload”的核心逻辑在 `pkg/datapath/orchestrator/orchestrator.go`。

源码显示：

- agent 启动时会注册一个 one-shot job 跑 `o.reconciler`
- `reconciler()` 会持续观察 agent config、本机 node config、host devices、plugin registry 等
- 当 `localNodeConfig` 变化时，会调用 `o.reinitialize(...)`
- `reinitialize()` 里会：
  - 调 `Loader.Reinitialize(...)`
  - 调 `ConnectorConfig.Reinitialize()`
  - 然后 `EndpointManager.RegenerateAllEndpoints(...)`
- 这条路径的 `RegenerationLevel` 是 `RegenerateWithDatapath`

这是本次调研里最关键的点：

- 如果你看到的是 program ID 变化，优先怀疑这条 `Reinitialize()` 路径，而不是 `endpoint-regen-interval`
- 我没有找到公开 flag 可以关闭这个 orchestrator reconcile loop

### 2.4 policy / identity 变化也会触发全量 regeneration

即使关掉周期 regen，源码里仍然有其他触发源。

- `pkg/policy/trigger.go`
  - policy repository bump revision 后，会 `TriggerRegenerateAllEndpoints()`
- `pkg/policy/cell/identity_updater.go`
  - 当 incremental policy update 改动了 identities，也会 `TriggerRegenerateAllEndpoints()`

这意味着：

- 即使 `--endpoint-regen-interval=0`
- 只要 identity / policy / 设备 / 本机配置发生变化，agent 仍然可能继续 regenerate / reload

### 2.5 hidden flag：`--bpf-policy-map-full-reconciliation-interval`

源码里存在一个 hidden flag：

- 名称：`bpf-policy-map-full-reconciliation-interval`
- 在 `daemon/cmd/daemon_main.go` 定义后立刻 `MarkHidden()`
- 默认值：`15m`
- 它被 `pkg/endpoint/bpf.go` 用于 `sync-policymap-*` controller 的 `RunInterval`

它的作用边界要特别小心：

- 这是 endpoint policy map 的 full reconciliation
- 不是 endpoint BPF program attach / detach / reload 的总开关

另外，controller 框架源码显示：

- `RunInterval == 0` 时，controller 在成功跑完一次后会等待 update/stop，不再做周期循环

所以从源码推断：

- `--bpf-policy-map-full-reconciliation-interval=0` 只能停掉后续周期性 full reconciliation
- 不能阻止初始执行
- 更不能阻止 datapath program reload

### 2.6 `DryMode`

源码里确实有：

- `pkg/option/config.go`: `DryMode bool // Do not create BPF maps, devices, ..`

但我没有找到：

- 对应的 `flags.Bool("dry-mode", ...)`
- 官方 cmdref 里的 `dry-mode`

因此更稳妥的结论是：

- `DryMode` 是内部字段
- 代码里很多分支会判断它
- 但它不是一个当前公开支持、可直接拿来配 `cilium-agent` 的文档化 CLI 选项

## 3. 有没有 debug mode 或 dry-run mode 可以冻结 BPF datapath

结论：没有找到官方支持的“freeze datapath” debug / dry-run 模式。

可以明确排除的项：

- `-D/--debug`
  - 只是 debug logging
- `--debug-verbose`
  - 只是 verbose logging 分组
- `--pprof`
  - 只是暴露 pprof
- `--enable-dynamic-config`
  - 官方文档说明它只是 watch `cilium-config` ConfigMap，把期望值反映到内存表
- `--enable-drift-checker`
  - 官方文档说明它只是比较“期望配置 vs 当前运行配置”，发现 drift 后打日志/打 metric
  - 文档还明确说，要应用配置仍需要 restart agent
- `--enable-dynamic-lifecycle-manager`
  - 源码说明它管理的是 dynamic feature lifecycle，不是 datapath freeze 开关

综合判断：

- 官方没有提供一个“只启动 agent、但冻结 BPF datapath 不再自动调和”的 benchmark/debug 模式
- 如果需要尽量稳定 datapath，只能靠关闭局部周期器 + 避免外部状态变化

## 4. 社区是否有类似需求 / 讨论

有大量“频繁 regeneration / 自动重装造成噪音或故障”的讨论，但没有找到一个被官方支持的“disable reconcile / freeze datapath”方案。

比较相关的讨论：

- `#39842` `Avoid constantly reporting "regenerating all endpoints" to the log`
  - 说明社区有人明确抱怨 `regenerating all endpoints` 在正常运行时周期性刷日志
  - 这从侧面说明周期性 regeneration 是既有行为
- `#25786` `DNS GC collector cleans up DNS cache too often`
  - issue 日志里能看到频繁的 `regenerating all endpoints`
- `#40551` / `#40552` `Frequent endpoint regeneration and identity churn after upgrade to v1.12.x`
  - 这是最接近你描述的现象：频繁 regeneration 和 identity churn
- `#41996` `Cilium 1.18.0 networking failure - ... unexpected BPF program removal`
  - 用户侧直接报告 endpoint BPF program 被移除后自动恢复
- `#39452` `Detected unexpected endpoint BPF program removal leading to pod connectivity loss`
  - 明确描述“program 被移除后，Cilium 过一段时间又自动 reinstates them”
- `#44078` `CI: v1.19: E2E Upgrade: Detected unexpected endpoint BPF program removal`
  - 连 Cilium 自己的 CI 也会打到 watchdog 相关告警

本次没有找到的东西：

- 官方建议的 benchmark mode
- 官方建议的 freeze datapath mode
- 官方建议的 “disable reconcile but keep existing BPF state intact” 运行模式

## 对 benchmark 场景的实用判断

如果目标是“尽量减少 Cilium 自己主动引发的 BPF program ID 变化”，从源码推断可优先尝试：

1. `--endpoint-regen-interval=0`
2. `--endpoint-bpf-prog-watchdog-interval=0`
3. 视情况尝试 hidden flag `--bpf-policy-map-full-reconciliation-interval=0`

但要清楚边界：

- 这不是官方支持的“freeze datapath”配置组合
- 它们也不能阻止 orchestrator 因设备/配置变化触发 `Reinitialize()`
- 它们也不能阻止 policy / identity 变化触发 endpoint regeneration
- 因此不能保证 program ID 完全不变

换句话说：

- `cilium-agent` 当前更像是“持续调和型控制面”
- 而不是“启动后静态保留现有 datapath，不再动”的 agent

## 参考链接

### 官方文档

- Cilium agent cmdref:
  - https://docs.cilium.io/en/stable/cmdref/cilium-agent.html
- Config drift detection:
  - https://docs.cilium.io/en/stable/configuration/configmap-drift-detection.html

### 源码（基于 commit `6e3229eb7044bb1c44f3764c50a076430d45e335`）

- `endpoint-regen-interval` 定义与默认值：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpointmanager/config.go#L44-L63
- `endpoint-regen-interval > 0` 时才注册：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpointmanager/cell.go#L254-L256
- 周期 regeneration 走 `RegenerateWithoutDatapath`：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpointmanager/manager.go#L152-L177
- `endpoint-bpf-prog-watchdog-interval` 定义、默认值、`0` 时不注册：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go#L31-L33
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go#L54-L63
- watchdog 发现 program 丢失后调用 `Reinitialize()`：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go#L130-L140
- orchestrator reconciler / `Reinitialize()` / `RegenerateWithDatapath`：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/datapath/orchestrator/orchestrator.go#L162-L220
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/datapath/orchestrator/orchestrator.go#L248-L260
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/datapath/orchestrator/orchestrator.go#L330-L366
- hidden flag `bpf-policy-map-full-reconciliation-interval`：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/daemon/cmd/daemon_main.go#L605-L607
- policy map full reconciliation controller：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/endpoint/bpf.go#L1528-L1555
- controller 框架里 `RunInterval == 0` 的行为：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/controller/controller.go#L392-L400
- policy 更新触发全量 regeneration：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/policy/trigger.go#L17-L20
- identity 变化触发全量 regeneration：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/policy/cell/identity_updater.go#L230-L235
- `DryMode` 内部字段：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/option/config.go#L1222-L1228
- dynamic lifecycle manager 说明：
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/dynamiclifecycle/cell.go#L12-L20
  - https://github.com/cilium/cilium/blob/6e3229eb7044bb1c44f3764c50a076430d45e335/pkg/dynamiclifecycle/cell.go#L41-L53

### 社区讨论

- `#39842` Avoid constantly reporting "regenerating all endpoints" to the log
  - https://github.com/cilium/cilium/issues/39842
- `#25786` DNS GC collector cleans up DNS cache too often
  - https://github.com/cilium/cilium/issues/25786
- `#40551` Frequent endpoint regeneration and identity churn after upgrade to v1.12.x
  - https://github.com/cilium/cilium/issues/40551
- `#40552` Frequent endpoint regeneration and identity churn after upgrade to v1.12.x
  - https://github.com/cilium/cilium/issues/40552
- `#41996` Cilium 1.18.0 networking failure - unexpected BPF program removal
  - https://github.com/cilium/cilium/issues/41996
- `#39452` Detected unexpected endpoint BPF program removal leading to pod connectivity loss
  - https://github.com/cilium/cilium/issues/39452
- `#44078` CI: v1.19: E2E Upgrade: Detected unexpected endpoint BPF program removal
  - https://github.com/cilium/cilium/issues/44078
