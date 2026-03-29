# AWS x86 benchmark final report

- Report path requested by user: `docs/tmp/20260328/aws_x86_benchmark_final_20260328.md`
- Actual execution date: 2026-03-29 (America/Vancouver)
- Scope: rerun AWS x86 benchmark after the EXT4/VIRTIO `=m` boot fix, confirm kernel/benchmark status, record performance data, and ensure remote cleanup

## Final status

结论：本次 **没有成功跑完 `make aws-x86-full` benchmark**，因此 **没有可记录的性能数据**。

已完成的部分：

1. `make kernel` 成功。
2. `make daemon` 成功。
3. `make runner` 成功。
4. 本地生成的内核 release 已确认是 `7.0.0-rc2+`。
5. AWS 侧三台调试实例最终都已 `terminated`，没有残留运行中的 `bpf-benchmark-x86` 实例。
6. 本地 `.cache/aws-x86/state/instance.env` 已清理。

未完成/未能严格验证的部分：

1. 无法在远端登录后执行 `uname -r`，因为实例在切到自编内核后 SSH 没有恢复。
2. benchmark 没有完成，因此 `.cache/aws-x86/results/` 下没有结果文件。
3. 没有性能数据可记录，只能记录失败经过和阻塞点。

## Build results

### 1. `make kernel`

- 成功日志：`docs/tmp/20260328/logs/aws_x86_make_kernel_20260329T091853Z.log`
- 生成的 release：`vendor/linux-framework/include/config/kernel.release`
- 确认值：`7.0.0-rc2+`

### 2. `make daemon`

- 成功日志：`docs/tmp/20260328/logs/aws_x86_make_daemon_20260329T091853Z.log`

### 3. `make runner`

- 成功日志：`docs/tmp/20260328/logs/aws_x86_make_runner_20260329T091853Z.log`

## AWS x86 run history

### Attempt 1

- Local log: `docs/tmp/20260328/logs/aws_x86_full_20260329T091853Z.log`
- Instance: `i-0129f020b889f0a2f`
- Outcome: stock Amazon Linux 启动正常，内核 `7.0.0-rc2+` 安装并设置为默认项后重启；随后 SSH 一直没有恢复，`make aws-x86-full` 失败。
- 直接证据：
  - 本地日志记录了安装自编内核后等待 SSH 超时：`[aws-x86][ERROR] SSH did not become ready on 44.197.195.128`
  - EC2 console 可见 boot menu 已进入 `Booting \`Codex x86 (7.0.0-rc2+)\``

### Attempt 2

- Local log: `docs/tmp/20260328/logs/aws_x86_full_retry2_20260329T100856Z.log`
- Instance: `i-0eda54b36a0617330`
- Outcome: 在 `runner/scripts/aws_x86.sh` 中加入更强的 dracut 打包后再次尝试，实例仍然在切到自编内核后无法恢复 SSH。
- 已验证现象：
  - stock kernel 阶段网络正常，console 明确显示：
    - `ena ... ens5: renamed from eth0`
    - `cloud-init ... ens5 True`
    - 有默认路由 `172.31.64.1`
  - 切到 `Codex x86 (7.0.0-rc2+)` 后，cloud-init 在自编内核阶段无法访问 metadata：
    - `Failed to establish a new connection: [Errno 101] Network is unreachable`
    - `Timed out, no response from urls: ['http://169.254.169.254:80/latest/api/token', 'http://[fd00:ec2::254]:80/latest/api/token']`
    - `IMDS's HTTP endpoint is probably disabled`
    - `Datasource DataSourceNone`
- 结论：EXT4/VIRTIO `=m` 修复后，实例已经能更深入地进入 userspace，但自编内核阶段仍有网络/metadata 初始化异常，导致 SSH 不可用，benchmark 无法开始。

### Attempt 3

- Local log: `docs/tmp/20260328/logs/aws_x86_full_retry3_20260329T102232Z.log`
- Instance: `i-000a617405c0c6295`
- Outcome: 这次失败是脚本调试失误，不是 benchmark 自身结果。
- 原因：新增的网卡名探测命令写成了错误的 awk 转义，远端安装脚本在 reboot 前就退出：
  - `awk: cmd. line:1: $1 != \\\"lo\\\" { print $1; exit }`
  - `syntax error`

### Attempt 4

- Local log: `docs/tmp/20260328/logs/aws_x86_full_retry4_20260329T102232Z.log`
- Reused instance: `i-000a617405c0c6295`
- Outcome: 修正 awk 问题后再次安装并重启，自编内核依旧没有恢复 SSH，benchmark 仍未启动。
- 已验证现象：
  - 本地日志确认又一次安装了 `7.0.0-rc2+`，随后流程卡在 reboot 后，最后由本地 `TERM` 清理实例。
  - 在线 console 观察到自编内核阶段继续向前推进到更多 systemd/userspace 路径，但仍未恢复可登录状态；现场观察到过：
    - `/dev/ttyS0` 等待超时
    - `/dev/disk/by-uuid/8CC6-72F8` 等待超时（`/boot/efi` 相关）
    - `systemd-boot-update` 失败
    - instance health 为 `running ok impaired`
- 说明：这些第四次重试的后期 console 现象是在在线排障时观察到的，**没有完整持久化到本地日志文件**；当前保存下来的 retry4 本地日志只保留到了“安装内核并进入 reboot 之后未恢复 SSH、最终被 TERM 清理”的控制路径。

## Debugging changes made during the run

为推进 boot/SSH 调试，我临时修改了 `runner/scripts/aws_x86.sh`，主要是两类：

1. dracut 显式加入 AWS 需要的驱动并关闭 hostonly：
   - `ena`
   - `nvme`
   - `nvme-core`
   - `xfs`
   - `ext4`
   - `virtio`
   - `virtio_pci`
   - `virtio_blk`
   - `virtio_net`
2. 在 reboot 前按当前网卡 MAC 写入 systemd `.link` / `.network`，固定主网卡名为 `ens5` 并启用 DHCP。

这些改动的效果是：第二次及之后的尝试里，实例确实比第一次更深入地进入了自编内核后的 userspace/init 路径；但它仍然没有恢复到可 SSH/可跑 benchmark 的状态。

## Requirement-by-requirement result

1. `make kernel`
   - 已完成，成功。
2. `make daemon && make runner`
   - 已完成，成功。
3. `make aws-x86-full`
   - 多次尝试，未成功完成。
4. 确认 `uname -r == 7.0.0-rc2+`
   - 只能 **部分确认**：
   - 已确认本地构建出的 release 是 `7.0.0-rc2+`。
   - EC2 console 已显示 boot menu 进入 `Codex x86 (7.0.0-rc2+)`。
   - 但由于 reboot 后 SSH 不通，**未能在远端 shell 中执行 `uname -r` 作最终 guest userspace 验证**。
5. 确认 benchmark 完成
   - 未完成。
6. 记录性能数据
   - 无性能数据；`.cache/aws-x86/results/` 为空。
7. 确保实例被 terminate
   - 已完成。
8. 远端和本地 VM 无关，不要因本地任务停
   - 本次 AWS 操作没有停止本地 VM 相关任务。

## Cleanup status

截至 2026-03-29，以下实例都已终止：

- `i-0129f020b889f0a2f` -> `terminated`
- `i-0eda54b36a0617330` -> `terminated`
- `i-000a617405c0c6295` -> `terminated`

额外确认：

- 按 tag `bpf-benchmark-x86` 查询，AWS `us-east-1` 中没有任何 `pending/running/stopping/stopped` 实例残留。
- 本地状态文件 `.cache/aws-x86/state/instance.env` 已删除。

## Performance data

无。benchmark 未进入完成态，也没有生成结果文件。

## Practical next step

如果后续继续排 AWS x86，自编内核当前最值得先查的是：

1. AL2023 在自编内核下的 early userspace 设备/挂载假设，尤其是 `/boot/efi` 对应的 UUID `8CC6-72F8`。
2. 串口与 getty/console 路径，尤其是现场观察到的 `/dev/ttyS0` 超时。
3. 自编内核阶段网络初始化为何退化到无法访问 IMDS，尽管 stock boot 阶段 `ens5` 正常。
4. 是否需要进一步约束/修正 boot entry、dracut 内容或 AL2023 的 initramfs/systemd 依赖。
