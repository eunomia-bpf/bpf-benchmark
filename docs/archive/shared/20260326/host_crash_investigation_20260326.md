# 宿主机崩溃调研报告（2026-03-26）

## 结论

这次 `make kernel-rebuild` 后紧接着 `make vm-shell` 期间发生的宿主机重启，最像**宿主机侧的硬件/热/MCE 相关硬复位**，而不是：

- guest 内核正常 panic
- OOM / systemd-oomd
- 之前那类 QEMU 8.2.2 TCG 用户态崩溃
- repo 里的 REJIT/kinsn 代码直接“越过 VM”打坏宿主机

我对下面几点判断有较高把握：

- `2026-03-26 15:50:47` 前一轮 boot 日志直接截断，`2026-03-26 15:52:09` 新 boot 开始，中间没有正常关机记录。
- 前一轮 boot 在崩溃前**没有** panic/oops/call trace/OOM killer 记录。
- 崩溃前最后一个贴近时间点的内核异常是 `2026-03-26 15:49:46` 的温度阈值/降频：
  - `CPU9: Package temperature is above threshold, cpu clock is throttled`
  - `CPU2: Package temperature is above threshold, cpu clock is throttled`
- 当前 boot 一开始就记录了：
  - `mce: [Hardware Error]: Machine check events logged`
- `/sys/fs/pstore` 为空，`/var/crash/` 里没有本次宿主机内核崩溃转储；只有旧的用户态 crash。
- 资源侧没有 OOM 迹象：`15:50:00` 的 `sar` 显示内存只用了约 `6.08%`，swap 仍为 `0`。

综合来看，这次更像是：

1. `make kernel-rebuild` 默认 `-j24` 持续压 CPU
2. 随后 `make vm-shell` 默认再起一个 `19 vCPU / 16G` 的 KVM VM
3. 宿主机在高负载/高温背景下触发热节流，并且伴随已有的 MCE/硬件异常历史，最终硬复位

现有证据**不支持**“guest 内的 REJIT bug 直接导致 host 崩溃”。

## 调查范围

本次检查覆盖了：

- repo 里的 VM 启动路径和默认资源配置
- `journalctl --list-boots`
- `journalctl -b -1`
- `journalctl -b -1 -p err..alert`
- `journalctl -k -b -1`
- `/var/log/syslog`
- `/var/log/kern.log`
- `/var/log/sysstat/sa26`
- `/var/crash/`
- `/sys/fs/pstore`
- 当前 boot 的 MCE 相关日志
- `vendor/linux-framework` 里 REJIT / kinsn / `text_poke` / `bpf_prog_pack` 相关路径

## 1. VM 实际是怎么启动的

### 1.1 make 路径

- 根 `Makefile` 中：
  - `NPROC ?= $(shell nproc ...)`
  - `JOBS ?= $(NPROC)`
  - `kernel-build` 调用 `$(MAKE) -C "$(KERNEL_DIR)" -j"$(JOBS)" bzImage modules_prepare`
  - 也就是默认按宿主机 CPU 数并行编内核
- `runner/Makefile` 中：
  - `vm-shell` 会调用 `runner/scripts/run_vm_shell.py`
  - 如果没有显式传 `VM_CPUS` / `VM_MEM`，就走机器默认值

对应代码位置：

- `Makefile:79-80`
- `Makefile:218-220`
- `runner/Makefile:55-76`
- `runner/Makefile:185-192`

### 1.2 vng / QEMU / KVM 参数

- `runner/machines.yaml` 的默认目标是 `local-x86-vng`
- `local-x86-vng`：
  - `backend: vng`
  - `memory: 16G`
  - 默认启用硬件加速
- 只有旧的 TCG 对照路径才会关闭硬件加速

对应代码位置：

- `runner/machines.yaml:1-6`
- `runner/machines.yaml:23-38`

### 1.3 默认 CPU / 内存

- CPU 默认不是写死的，而是 `cpus_auto_ratio: 0.8`
- 机器解析逻辑会做 `floor(host_cpu_count * 0.8)`
- 这台宿主机当前是 `24` 逻辑 CPU，所以 VM 默认是 `floor(24 * 0.8) = 19` vCPU
- 内存则被 `local-x86-vng.memory: 16G` 覆盖，不走自动比例

对应代码位置：

- `runner/libs/machines.py:59-82`
- `runner/libs/vm.py:87-102`

### 1.4 vng-wrapper 只是 PTY 包装

`runner/scripts/vng-wrapper.sh` 并不决定 KVM/TCG，也不加资源参数。它只是在非 TTY 场景下用 `script(1)` 包一层，让 `vng` 有可用 PTY。

对应代码位置：

- `runner/scripts/vng-wrapper.sh:1-39`

### 1.5 现场确认到的实际 QEMU 路径和 dry-run 展开

当前 PATH 上 `qemu-system-x86_64` 的解析顺序是：

1. `/usr/local/bin/qemu-system-x86_64`
2. `/usr/bin/qemu-system-x86_64`

版本分别是：

- `/usr/local/bin/qemu-system-x86_64`: `9.2.2`
- `/usr/bin/qemu-system-x86_64`: `8.2.2`

repo 现在的 `vng --dry-run --verbose` 展开到的命令关键参数是：

```text
/usr/local/bin/qemu-system-x86_64
  -machine accel=kvm:tcg
  -cpu host,topoext=on
  -smp 19
  -m 16G
  ...
```

这说明：

- 本次路径是 **KVM 优先**，不是纯 TCG
- 只有 KVM 不可用时才会回落到 TCG

说明：

- 调研时 `vendor/linux-framework/arch/x86/boot/bzImage` 已不存在，所以 dry-run 用的是宿主机内核镜像来展开模板。
- 但 repo 代码里的启动模板、KVM 开关、CPU/内存默认值已经能确认；当 `bzImage` 存在时，`run_vm_shell.py` 会把它传给同一条命令模板。

## 2. 负载和资源情况

### 2.1 编译并行度

`make kernel-rebuild` 默认会用 `JOBS = NPROC = 24`。  
也就是本机默认是 `-j24` 编内核。

### 2.2 VM 资源

`make vm-shell` 默认会起：

- `19` vCPU
- `16G` 内存

### 2.3 宿主机内存并不紧张

当前机器总内存约 `125 GiB`。  
`sar -r -f /var/log/sysstat/sa26` 在 `2026-03-26 15:50:00` 记录到：

- `kbmemused = 7982396`
- `%memused = 6.08`
- `kbswpused = 0`

这说明：

- 没有内存打满
- 没有 swap 压力
- 不符合 OOM / OOMD 导致重启的特征

### 2.4 CPU 压力在崩溃前一采样点明显抬高

`sar -q -f /var/log/sysstat/sa26` 在 `2026-03-26 15:50:00` 记录到：

- `runq-sz = 38`
- `ldavg-1 = 17.01`

`sar -u -f /var/log/sysstat/sa26` 同一时刻记录到平均：

- `%user = 9.55`
- `%system = 2.55`
- `%idle = 87.32`

这不像 OOM，更像是最后一分钟内出现了显著 CPU 压力，但 `sar` 的 10 分钟采样粒度不足以还原更细的瞬时尖峰。  
结合前面的 `-j24` 编译和后面的 `19 vCPU` KVM VM，宿主机承受高热负载是完全合理的。

## 3. 宿主机崩溃证据

### 3.1 boot 时间线

`journalctl --list-boots` 与 `last -x` 一致显示：

- 前一轮 boot: `2026-03-26 14:32:50` 到 `2026-03-26 15:50:47`
- 当前 boot: `2026-03-26 15:52:09` 开始

也就是宿主机在 `15:50:47` 左右突然掉线，约 `82` 秒后重新开机。

### 3.2 前一轮 boot 没有 panic / oops / call trace / OOM

我检查了：

- `journalctl -b -1`
- `journalctl -b -1 -p err..alert`
- `journalctl -k -b -1`
- `/var/log/syslog`
- `/var/log/kern.log`

结果：

- 没有 `panic`
- 没有 `BUG:`
- 没有 `Oops`
- 没有 `Call Trace`
- 没有 `soft lockup`
- 没有 `hard lockup`
- 没有 `rcu stall`
- 没有 `Killed process`
- 没有 `Out of memory`

这更像“内核来不及把崩溃写进日志就直接掉电/硬复位”。

### 3.3 崩溃前最后一个贴近时间点的内核异常是热节流

在 `/var/log/kern.log` / `/var/log/syslog` 中，前一轮 boot 最贴近崩溃时间的内核异常是：

- `2026-03-26T15:49:46.428407-07:00` `CPU9: Package temperature is above threshold, cpu clock is throttled`
- `2026-03-26T15:49:46.428426-07:00` `CPU2: Package temperature is above threshold, cpu clock is throttled`
- `2026-03-26T15:49:47.451410-07:00` `CPU2: Package temperature/speed normal`
- `2026-03-26T15:49:47.451426-07:00` `CPU9: Package temperature/speed normal`

之后日志就一路正常噪声，直到 `15:50:47` 截断。

### 3.4 当前 boot 明确看到 MCE 摘要

当前 boot 的 `journalctl -k -b 0` / `dmesg` 里有：

```text
Mar 26 15:52:09 lab kernel: EDAC MC: Ver: 3.0.0
Mar 26 15:52:09 lab kernel: mce: [Hardware Error]: Machine check events logged
```

这类信息常见于：

- 机器重启后，内核在新 boot 初期发现前一次运行留下的 MCA/MCE 记录
- 或者机器一直存在底层硬件错误历史

我没有拿到更细的 MCE bank decode 文本；系统上也没有安装 `mcelog` / `ras-mc-ctl`。  
但**仅凭这条摘要，就已经比“纯代码 bug”更偏向硬件/热/平台异常**。

### 3.5 pstore 为空，说明不像内核 panic 后写出持久转储

`/sys/fs/pstore` 目录存在，但为空。  
这说明这次没有留下 EFI pstore / ramoops 之类的 panic 持久化记录。

### 3.6 下一次开机还发现用户 journal 非正常关闭

当前 boot 初期有：

- `user-1000.journal corrupted or uncleanly shut down`
- `user-1007.journal ... rotating`

这和“上一次不是有序关机，而是突然掉电/硬复位”一致。

### 3.7 历史上同类热/MCE 痕迹很多

日志里不止这一次：

- `2026-03-24` 多次温度阈值事件
- `2026-03-25` 多次温度阈值事件
- 多个 boot 起始阶段都有 `mce: [Hardware Error]: Machine check events logged`

这说明宿主机本身就存在持续性的热/硬件不稳定背景，不是一次孤立的软件症状。

## 4. 旧的 QEMU 崩溃和这次不是一回事

`/var/crash/_usr_bin_qemu-system-x86_64.1000.crash` 和 `apport.log.1` 里记录了 `2026-03-25` 多次 QEMU 用户态 crash。

关键点：

- 可执行文件是 `/usr/bin/qemu-system-x86_64`
- 版本是 `8.2.2`
- crash stack 落在：
  - `get_page_addr_code_hostp`
  - `helper_lookup_tb_ptr`
  - `accel-tcg-x86_64.so`
- 命令行里典型参数是：
  - `-m 8G`
  - `-smp 2`
  - `-machine q35`

这和本次不是同一路径：

- 这次 repo 当前默认走的是 `/usr/local/bin/qemu-system-x86_64`
- 版本是 `9.2.2`
- `vng --dry-run` 展开的是 `-machine accel=kvm:tcg`
- `local-x86-vng` 目标默认启用硬件加速

所以：

- Mar 25 的 crash 是**旧版 QEMU 8.2.2 的用户态 TCG 崩溃**
- Mar 26 这次是**宿主机整机重启**
- 两者不能混为同一根因

## 5. 代码侧评估：REJIT/kinsn 本身没有直接触碰 KVM 控制面

我重点看了这些路径：

- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`

能确认的事实：

- REJIT 通过 `bpf_prog_rejit()` 构造一个临时 BPF prog，重新验证/JIT，然后交换 `prog->bpf_func`，再刷新 trampoline/struct_ops。
- JIT 可执行内存通过 `bpf_jit_alloc_exec()` / `bpf_prog_pack_alloc()` 分配，并用 `set_memory_rox()` 保护。
- struct_ops refresh 里会调用 `bpf_arch_text_poke()` 给 guest 内核里的 trampoline 打补丁。

对应代码位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:3589-3845`
- `vendor/linux-framework/kernel/bpf/core.c:910-970`
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1596-1609`

但我在这些 repo 相关目录里搜索：

- `runner/scripts`
- `runner/libs`
- `daemon`
- `module`
- `tests`
- `micro`
- `vendor/linux-framework/kernel/bpf`

没有找到：

- `KVM`
- `/dev/kvm`
- `ioctl(...KVM...)`

也就是说，**repo 自己的 REJIT/BPF 代码没有直接操纵 host KVM 接口**。

因此更合理的边界判断是：

- guest 内的 BPF/REJIT bug，正常情况下只会打挂 guest
- 若它真的和 host 重启有关，合理链路也只能是：
  - guest workload 触发了 KVM/QEMU/CPU/firmware 层面的 bug
  - 而不是 repo 代码直接“越权”碰 host

现有日志又没有任何 KVM oops / host kernel stack / qemu 9.2.2 crash 记录来支持这条链路。

## 6. 最终判断

### 高置信度判断

- 不是 OOM。
- 不是普通 guest kernel panic。
- 不是 Mar 25 那类 QEMU 8.2.2 TCG 用户态 crash。
- 这次是宿主机硬复位，证据更偏向热/硬件/MCE。

### 中等置信度判断

- `-j24` 编内核 + 默认 `19 vCPU / 16G` KVM VM 的连续负载，是这次故障的直接诱因。
- `15:49:46` 的热节流与 `15:52:09` 新 boot 的 `Machine check events logged` 组合，说明“高负载触发宿主机平台不稳定”是最可信解释。

### 低置信度判断

- 不能完全排除“guest workload 恰好踩到 KVM/CPU/firmware bug”。
- 但按当前证据，这比“宿主机热/硬件/MCE 问题”明显更弱。

## 7. 建议的后续动作

- 优先把复现压力降下来后再验证：
  - `make JOBS=8 kernel-rebuild`
  - `make VM_CPUS=4 VM_MEM=8G vm-shell`
- 复现前先确认散热和功耗限制，至少把 `sensors`、风扇、机箱灰尘、BIOS/UEFI 温控策略看一遍。
- 下次若再重启，第一时间在新 boot 收集：
  - `journalctl -k -b 0 | rg -i 'mce|machine check|hardware error'`
  - `dmesg | rg -i 'mce|machine check|hardware error'`
  - `sudo ls -lah /sys/fs/pstore`
- 若要区分 KVM 与 workload 热负载，建议做低压力对照实验：
  - 同样 workload，先减小 `JOBS` / `VM_CPUS`
  - 再考虑用 `TARGET=local-x86-vng-tcg` 做对照
  - 但 TCG 对照只适合“确认是否是 KVM 特有问题”，不适合做性能判断
- 若这台机器需要继续做内核/VM 压测，建议安装并启用更完整的硬件错误记录链路（例如 `rasdaemon`），否则每次只能看到一句泛化的 `Machine check events logged`。

## 一句话结论

本次 `2026-03-26 15:50` 左右的宿主机重启，现有证据最支持“高负载下触发的宿主机热/硬件/MCE 相关硬复位”；不支持 OOM，也没有证据表明 repo 里的 REJIT/kinsn 代码直接导致了 host 崩溃。
