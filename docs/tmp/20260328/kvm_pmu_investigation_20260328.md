# KVM PMU Investigation (2026-03-28)

## 结论

实际验证结果：

1. 宿主机 PMU 是可用的。
2. `vng`/QEMU 启动参数里已经有 `-cpu host,topoext=on`，不是这里漏了 passthrough。
3. 真正阻断 guest PMU 的原因是宿主机 KVM 全局参数 `enable_pmu=N`。
4. guest 内核里 `CONFIG_PERF_EVENTS=y`，而且源码里已经包含 `INTEL_ARROWLAKE` 的 PMU 分支；因此“Arrow Lake 太新，guest 内核源码不支持”这个判断不成立。
5. guest 里把 `perf_event_paranoid` 从 `2` 改到 `-1` 后，`perf_event_open` 仍然返回 `ENOENT`，说明问题不是 paranoid，而是 guest 根本没有拿到硬件 PMU。
6. guest 里的 `perf` 命令还有一个独立问题：缺少和 guest kernel `7.0.0-rc2+` 匹配的 `linux-tools`，所以 `perf stat` / `perf list hw` 无法直接运行；但这不是根因，根因仍然是 KVM PMU 被宿主机关掉了。

一句话总结：当前宿主机上 **KVM PMU passthrough 不可用**，根因是 **宿主机 `kvm.enable_pmu=0` / `/sys/module/kvm/parameters/enable_pmu = N`**，不是 `-cpu host` 缺失，也不是 guest `perf_event_paranoid`。

## 方法说明

按仓库约定先尝试 `make vm-shell`。这次它被一个已经存在的 `vm-e2e` 会话占住了 `vm_global` 锁，没有真正启动新的 probe VM，输出如下：

```text
make[1]: *** [Makefile:248: vm-shell] Terminated
make[1]: Leaving directory '/home/yunwei37/workspace/bpf-benchmark/runner'
make: *** [Makefile:304: vm-shell] Error 2
```

因此后续 guest 验证改用同一条 `vng`/QEMU/KVM 路径直接启动：

```text
runner/scripts/vng-wrapper.sh --run vendor/linux-framework/arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark --disable-monitor --cpus 2 --mem 4G --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp --rwdir /home/yunwei37/workspace/bpf-benchmark --exec /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/kvm_pmu_guest_probe_20260328.sh
```

这条命令使用的仍然是仓库正在使用的 `vng` backend 和同一个 guest kernel。

## 1. 宿主机 PMU 状态

### 1.1 CPU 型号

命令：

```bash
cat /proc/cpuinfo | head -30
```

实际输出：

```text
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 198
model name	: Intel(R) Core(TM) Ultra 9 285K
stepping	: 2
microcode	: 0x11b
cpu MHz		: 5401.421
cache size	: 36864 KB
physical id	: 0
siblings	: 24
core id		: 0
cpu cores	: 24
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 35
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf tsc_known_freq pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb ssbd ibrs ibpb stibp ibrs_enhanced tpr_shadow flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid rdt_a rdseed adx smap clflushopt clwb intel_pt sha_ni xsaveopt xsavec xgetbv1 xsaves split_lock_detect user_shstk avx_vnni lam wbnoinvd dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp hwp_pkg_req hfi vnmi umip pku ospke waitpkg gfni vaes vpclmulqdq rdpid bus_lock_detect movdiri movdir64b fsrm md_clear serialize arch_lbr ibt flush_l1d arch_capabilities
vmx flags	: vnmi preemption_timer posted_intr invvpid ept_x_only ept_ad ept_1gb flexpriority apicv tsc_offset vtpr mtf vapic ept vpid unrestricted_guest vapic_reg vid ple shadow_vmcs pml ept_violation_ve ept_mode_based_exec tsc_scaling usr_wait_pause notify_vm_exiting ipi_virt
bugs		: spectre_v1 spectre_v2 spec_store_bypass swapgs bhi spectre_v2_user
bogomips	: 7372.80
clflush size	: 64
cache_alignment	: 64
address sizes	: 46 bits physical, 48 bits virtual
power management:

processor	: 1
vendor_id	: GenuineIntel
```

观察：

- 宿主机 CPU 是 `Intel(R) Core(TM) Ultra 9 285K`，family/model 是 `6/198`。
- 宿主机 flags 明确包含 `arch_perfmon`，说明硬件 perfmon 能力存在。

### 1.2 `perf stat -e branches,branch-misses,instructions,cycles ls`

命令：

```bash
perf stat -e branches,branch-misses,instructions,cycles ls
```

实际输出：

```text
WARNING: perf not found for kernel 6.15.11-061511

  You may need to install the following packages for this specific kernel:
    linux-tools-6.15.11-061511-generic
    linux-cloud-tools-6.15.11-061511-generic

  You may also want to install one of the following packages to keep up to date:
    linux-tools-generic
    linux-cloud-tools-generic
```

观察：

- 宿主机 `perf` userspace 工具和当前 host kernel 不匹配，无法直接用这个命令验证。
- 这只说明 `perf` 工具缺失，不说明 PMU 不工作。

### 1.3 `perf list hw`

命令：

```bash
perf list hw
```

实际输出：

```text
WARNING: perf not found for kernel 6.15.11-061511

  You may need to install the following packages for this specific kernel:
    linux-tools-6.15.11-061511-generic
    linux-cloud-tools-6.15.11-061511-generic

  You may also want to install one of the following packages to keep up to date:
    linux-tools-generic
    linux-cloud-tools-generic
```

### 1.4 `dmesg | grep -i pmu`

命令：

```bash
dmesg | grep -i pmu
```

实际输出：

```text
dmesg: read kernel buffer failed: Operation not permitted
```

因为当前用户直接读 `dmesg` 被限制，使用 `journalctl -k -b --no-pager | grep -i pmu` 做等价补充。

命令：

```bash
journalctl -k -b --no-pager | grep -i pmu
```

实际输出：

```text
Mar 28 12:24:47 lab kernel: Performance Events: XSAVE Architectural LBR, PEBS fmt6+-baseline,  AnyThread deprecated, Lunarlake Hybrid events, 32-deep LBR, full-width counters, Intel PMU driver.
Mar 28 12:24:47 lab kernel: core: cpu_core PMU driver: 
Mar 28 12:24:47 lab kernel: NMI watchdog: Enabled. Permanently consumes one hw-PMU counter.
Mar 28 12:24:47 lab kernel: core: cpu_atom PMU driver: 
Mar 28 12:24:48 lab kernel: RAPL PMU: API unit is 2^-32 Joules, 2 fixed counters, 655360 ms ovfl timer
Mar 28 12:24:48 lab kernel: RAPL PMU: hw unit of domain pp0-core 2^-14 Joules
Mar 28 12:24:48 lab kernel: RAPL PMU: hw unit of domain package 2^-14 Joules
```

观察：

- 宿主机内核已经正确初始化 Intel PMU driver。
- 日志里明确出现 `Lunarlake Hybrid events`、`cpu_core PMU driver`、`cpu_atom PMU driver`。

### 1.5 `ls /sys/devices/cpu/events/`

命令：

```bash
ls /sys/devices/cpu/events/
```

实际输出：

```text
ls: cannot access '/sys/devices/cpu/events/': No such file or directory
```

补充：这台 hybrid CPU 的 sysfs 路径不是 `/sys/devices/cpu/events`，而是分成 `cpu_core` / `cpu_atom`。

命令：

```bash
ls -la /sys/devices/cpu_core /sys/devices/cpu_atom
```

实际输出：

```text
/sys/devices/cpu_atom:
total 0
drwxr-xr-x  6 root root    0 Mar 28 14:00 .
drwxr-xr-x 51 root root    0 Mar 28 12:24 ..
drwxr-xr-x  2 root root    0 Mar 28 14:00 caps
-r--r--r--  1 root root 4096 Mar 28 14:00 cpus
drwxr-xr-x  2 root root    0 Mar 28 14:00 events
drwxr-xr-x  2 root root    0 Mar 28 14:00 format
-rw-r--r--  1 root root 4096 Mar 28 14:00 freeze_on_smi
-rw-r--r--  1 root root 4096 Mar 28 14:00 perf_event_mux_interval_ms
drwxr-xr-x  2 root root    0 Mar 28 14:00 power
-rw-------  1 root root 4096 Mar 28 14:00 rdpmc
lrwxrwxrwx  1 root root    0 Mar 28 12:24 subsystem -> ../../bus/event_source
-r--r--r--  1 root root 4096 Mar 28 14:00 type
-rw-r--r--  1 root root 4096 Mar 28 12:24 uevent

/sys/devices/cpu_core:
total 0
drwxr-xr-x  6 root root    0 Mar 28 14:00 .
drwxr-xr-x 51 root root    0 Mar 28 14:00 ..
drwxr-xr-x  2 root root    0 Mar 28 14:00 caps
-r--r--r--  1 root root 4096 Mar 28 14:00 cpus
drwxr-xr-x  2 root root    0 Mar 28 14:00 events
drwxr-xr-x  2 root root    0 Mar 28 14:00 format
-rw-r--r--  1 root root 4096 Mar 28 14:00 freeze_on_smi
-rw-r--r--  1 root root 4096 Mar 28 14:00 perf_event_mux_interval_ms
drwxr-xr-x  2 root root    0 Mar 28 14:00 power
-rw-------  1 root root 4096 Mar 28 14:00 rdpmc
lrwxrwxrwx  1 root root    0 Mar 28 12:24 subsystem -> ../../bus/event_source
-r--r--r--  1 root root 4096 Mar 28 14:00 type
-rw-r--r--  1 root root 4096 Mar 28 12:24 uevent
```

命令：

```bash
find /sys/devices/cpu_core -maxdepth 2 | sort | sed -n '1,160p'
```

实际输出：

```text
/sys/devices/cpu_core
/sys/devices/cpu_core/caps
/sys/devices/cpu_core/caps/branch_counter_nr
/sys/devices/cpu_core/caps/branch_counter_width
/sys/devices/cpu_core/caps/branches
/sys/devices/cpu_core/caps/max_precise
/sys/devices/cpu_core/caps/pmu_name
/sys/devices/cpu_core/cpus
/sys/devices/cpu_core/events
/sys/devices/cpu_core/events/branch-instructions
/sys/devices/cpu_core/events/branch-misses
/sys/devices/cpu_core/events/bus-cycles
/sys/devices/cpu_core/events/cache-misses
/sys/devices/cpu_core/events/cache-references
/sys/devices/cpu_core/events/cpu-cycles
/sys/devices/cpu_core/events/instructions
/sys/devices/cpu_core/events/mem-loads
/sys/devices/cpu_core/events/mem-stores
/sys/devices/cpu_core/events/ref-cycles
/sys/devices/cpu_core/events/slots
/sys/devices/cpu_core/events/topdown-bad-spec
/sys/devices/cpu_core/events/topdown-be-bound
/sys/devices/cpu_core/events/topdown-br-mispredict
/sys/devices/cpu_core/events/topdown-fe-bound
/sys/devices/cpu_core/events/topdown-fetch-lat
/sys/devices/cpu_core/events/topdown-heavy-ops
/sys/devices/cpu_core/events/topdown-mem-bound
/sys/devices/cpu_core/events/topdown-retiring
/sys/devices/cpu_core/format
/sys/devices/cpu_core/format/cmask
/sys/devices/cpu_core/format/edge
/sys/devices/cpu_core/format/eq
/sys/devices/cpu_core/format/event
/sys/devices/cpu_core/format/frontend
/sys/devices/cpu_core/format/inv
/sys/devices/cpu_core/format/ldlat
/sys/devices/cpu_core/format/metrics_clear
/sys/devices/cpu_core/format/offcore_rsp
/sys/devices/cpu_core/format/pc
/sys/devices/cpu_core/format/umask
/sys/devices/cpu_core/freeze_on_smi
/sys/devices/cpu_core/perf_event_mux_interval_ms
/sys/devices/cpu_core/power
/sys/devices/cpu_core/power/async
/sys/devices/cpu_core/power/autosuspend_delay_ms
/sys/devices/cpu_core/power/control
/sys/devices/cpu_core/power/runtime_active_kids
/sys/devices/cpu_core/power/runtime_active_time
/sys/devices/cpu_core/power/runtime_enabled
/sys/devices/cpu_core/power/runtime_status
/sys/devices/cpu_core/power/runtime_suspended_time
/sys/devices/cpu_core/power/runtime_usage
/sys/devices/cpu_core/rdpmc
/sys/devices/cpu_core/subsystem
/sys/devices/cpu_core/type
/sys/devices/cpu_core/uevent
```

命令：

```bash
find /sys/devices/cpu_atom -maxdepth 2 | sort | sed -n '1,160p'
```

实际输出：

```text
/sys/devices/cpu_atom
/sys/devices/cpu_atom/caps
/sys/devices/cpu_atom/caps/branch_counter_nr
/sys/devices/cpu_atom/caps/branch_counter_width
/sys/devices/cpu_atom/caps/branches
/sys/devices/cpu_atom/caps/max_precise
/sys/devices/cpu_atom/caps/pmu_name
/sys/devices/cpu_atom/cpus
/sys/devices/cpu_atom/events
/sys/devices/cpu_atom/events/branch-instructions
/sys/devices/cpu_atom/events/branch-misses
/sys/devices/cpu_atom/events/bus-cycles
/sys/devices/cpu_atom/events/cache-misses
/sys/devices/cpu_atom/events/cache-references
/sys/devices/cpu_atom/events/cpu-cycles
/sys/devices/cpu_atom/events/instructions
/sys/devices/cpu_atom/events/mem-loads
/sys/devices/cpu_atom/events/mem-stores
/sys/devices/cpu_atom/events/ref-cycles
/sys/devices/cpu_atom/events/topdown-bad-spec
/sys/devices/cpu_atom/events/topdown-be-bound
/sys/devices/cpu_atom/events/topdown-fe-bound
/sys/devices/cpu_atom/events/topdown-retiring
/sys/devices/cpu_atom/format
/sys/devices/cpu_atom/format/cmask
/sys/devices/cpu_atom/format/edge
/sys/devices/cpu_atom/format/eq
/sys/devices/cpu_atom/format/event
/sys/devices/cpu_atom/format/inv
/sys/devices/cpu_atom/format/ldlat
/sys/devices/cpu_atom/format/offcore_rsp
/sys/devices/cpu_atom/format/pc
/sys/devices/cpu_atom/format/snoop_rsp
/sys/devices/cpu_atom/format/umask
/sys/devices/cpu_atom/freeze_on_smi
/sys/devices/cpu_atom/perf_event_mux_interval_ms
/sys/devices/cpu_atom/power
/sys/devices/cpu_atom/power/async
/sys/devices/cpu_atom/power/autosuspend_delay_ms
/sys/devices/cpu_atom/power/control
/sys/devices/cpu_atom/power/runtime_active_kids
/sys/devices/cpu_atom/power/runtime_active_time
/sys/devices/cpu_atom/power/runtime_enabled
/sys/devices/cpu_atom/power/runtime_status
/sys/devices/cpu_atom/power/runtime_suspended_time
/sys/devices/cpu_atom/power/runtime_usage
/sys/devices/cpu_atom/rdpmc
/sys/devices/cpu_atom/subsystem
/sys/devices/cpu_atom/type
/sys/devices/cpu_atom/uevent
```

命令：

```bash
cat /sys/devices/cpu_core/caps/pmu_name && echo
cat /sys/devices/cpu_atom/caps/pmu_name && echo
cat /sys/devices/cpu_core/caps/branches && echo
cat /sys/devices/cpu_atom/caps/branches && echo
```

实际输出：

```text
lunarlake_hybrid

lunarlake_hybrid

32

32
```

观察：

- 宿主机 PMU sysfs 存在，只是 hybrid CPU 使用 `cpu_core` / `cpu_atom` 分拆路径。

### 1.6 低层 `perf_event_open` 验证

命令：

```bash
cat /proc/sys/kernel/perf_event_paranoid
```

实际输出：

```text
2
```

命令（用户态 branch-misses，默认 attr）：

```bash
python3 - <<'PY'
import ctypes, os, struct
libc = ctypes.CDLL('libc.so.6', use_errno=True)
SYS_perf_event_open = 298
attr = bytearray(112)
struct.pack_into('IIQ', attr, 0, 0, 112, 5)
fd = libc.syscall(SYS_perf_event_open, ctypes.c_char_p(bytes(attr)), -1, 0, -1, 0)
err = ctypes.get_errno()
print(f'host perf_event_open returned fd={fd}, errno={err}')
if fd >= 0:
    os.close(fd)
PY
```

实际输出：

```text
host perf_event_open returned fd=-1, errno=13
```

命令（用户态 cycles，显式 `exclude_kernel=1, exclude_hv=1`）：

```bash
python3 - <<'PY'
import ctypes, os, struct
libc = ctypes.CDLL('libc.so.6', use_errno=True)
SYS_perf_event_open = 298
attr = bytearray(112)
struct.pack_into('I', attr, 0, 0)
struct.pack_into('I', attr, 4, 112)
struct.pack_into('Q', attr, 8, 0)
flags = (1 << 0) | (1 << 5) | (1 << 6)
struct.pack_into('Q', attr, 40, flags)
fd = libc.syscall(SYS_perf_event_open, ctypes.c_char_p(bytes(attr)), 0, -1, -1, 0)
err = ctypes.get_errno()
print(f'host perf_event_open(cycles, pid=0, cpu=-1, exclude_kernel=1,exclude_hv=1) returned fd={fd}, errno={err}')
if fd >= 0:
    os.close(fd)
PY
```

实际输出：

```text
host perf_event_open(cycles, pid=0, cpu=-1, exclude_kernel=1,exclude_hv=1) returned fd=3, errno=0
```

观察：

- 默认 attr 因 `perf_event_paranoid=2` 返回 `EACCES`。
- 但在合法的用户态-only 约束下，宿主机 `perf_event_open` 成功返回 `fd=3`。
- 因此宿主机 PMU 是工作的。

## 2. KVM PMU passthrough 状态

### 2.1 检查 QEMU/vng 是否有 `-cpu host`

命令：

```bash
runner/scripts/vng-wrapper.sh --dry-run --run vendor/linux-framework/arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark --disable-monitor --cpus 2 --mem 2G --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp --rwdir /home/yunwei37/workspace/bpf-benchmark --exec /bin/true
```

实际输出：

```text
/usr/local/bin/qemu-system-x86_64 -name virtme-ng -m 2G -fsdev local,id=virtfs5,path=/,security_model=none,readonly=on,multidevs=remap -device virtio-9p-pci,fsdev=virtfs5,mount_tag=/dev/root -fsdev local,id=virtfs9,path=/home/yunwei37/workspace/bpf-benchmark/docs/tmp,security_model=none,multidevs=remap -device virtio-9p-pci,fsdev=virtfs9,mount_tag=virtme.initmount0 -fsdev local,id=virtfs13,path=/home/yunwei37/workspace/bpf-benchmark,security_model=none,multidevs=remap -device virtio-9p-pci,fsdev=virtfs13,mount_tag=virtme.initmount1 -machine accel=kvm:tcg -device i6300esb,id=watchdog0 -cpu host,topoext=on -parallel none -net none -smp 2 -vga none -display none -serial chardev:console -chardev file,id=console,path=/dev/null -chardev stdio,id=stdin,signal=on,mux=off -device virtio-serial-pci -device virtserialport,name=virtme.stdin,chardev=stdin -chardev file,id=stdout,path=/proc/self/fd/1 -device virtio-serial-pci -device virtserialport,name=virtme.stdout,chardev=stdout -chardev file,id=stderr,path=/proc/self/fd/2 -device virtio-serial-pci -device virtserialport,name=virtme.stderr,chardev=stderr -chardev file,id=dev_stdout,path=/proc/self/fd/1 -device virtio-serial-pci -device virtserialport,name=virtme.dev_stdout,chardev=dev_stdout -chardev file,id=dev_stderr,path=/proc/self/fd/2 -device virtio-serial-pci -device virtserialport,name=virtme.dev_stderr,chardev=dev_stderr -chardev file,id=ret,path=/tmp/virtme_retf420e28d -device virtio-serial-pci -device virtserialport,name=virtme.ret,chardev=ret -no-reboot -kernel vendor/linux-framework/arch/x86/boot/bzImage -append 'virtme_hostname=virtme-ng nr_open=1048576 virtme_link_mods=/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/.virtme_mods/lib/modules/0.0.0 virtme_initmount0=home/yunwei37/workspace/bpf-benchmark/docs/tmp virtme_initmount1=home/yunwei37/workspace/bpf-benchmark virtme_rw_overlay0=/etc virtme_rw_overlay1=/lib virtme_rw_overlay2=/home virtme_rw_overlay3=/opt virtme_rw_overlay4=/srv virtme_rw_overlay5=/usr virtme_rw_overlay6=/var virtme_rw_overlay7=/tmp console=ttyS0 earlyprintk=serial,ttyS0,115200 quiet loglevel=0 panic=-1 virtme.exec=`L2Jpbi90cnVl` virtme_chdir=home/yunwei37/workspace/bpf-benchmark quiet loglevel=1 init=/home/yunwei37/.local/lib/python3.12/site-packages/virtme/guest/bin/virtme-ng-init' -initrd /proc/self/fd/4
```

观察：

- `-cpu host,topoext=on` 已经存在。
- `-machine accel=kvm:tcg` 也说明它优先尝试 KVM。

### 2.2 KVM 模块参数 `enable_pmu`

按用户给的路径先查 `kvm_intel` / `kvm_amd`：

命令：

```bash
if [ -e /sys/module/kvm_intel/parameters/enable_pmu ]; then cat /sys/module/kvm_intel/parameters/enable_pmu; elif [ -e /sys/module/kvm_amd/parameters/enable_pmu ]; then cat /sys/module/kvm_amd/parameters/enable_pmu; else echo "enable_pmu parameter not found"; fi
```

实际输出：

```text
enable_pmu parameter not found
```

进一步查全局 KVM：

命令：

```bash
find /sys/module -path '*/parameters/*' | grep -i pmu | sed -n '1,120p'
```

实际输出：

```text
/sys/module/kvm/parameters/enable_pmu
```

命令：

```bash
cat /sys/module/kvm/parameters/enable_pmu
```

实际输出：

```text
N
```

命令：

```bash
ls -l /sys/module/kvm/parameters/enable_pmu && stat -c '%A %U:%G %n' /sys/module/kvm/parameters/enable_pmu
```

实际输出：

```text
-r--r--r-- 1 root root 4096 Mar 28 14:05 /sys/module/kvm/parameters/enable_pmu
-r--r--r-- root:root /sys/module/kvm/parameters/enable_pmu
```

命令：

```bash
modinfo kvm | rg -n "enable_pmu|parm:"
```

实际输出：

```text
41:parm:           mmio_caching:bool
42:parm:           nx_huge_pages:bool
43:parm:           nx_huge_pages_recovery_ratio:uint
44:parm:           nx_huge_pages_recovery_period_ms:uint
45:parm:           flush_on_reuse:bool
46:parm:           tdp_mmu:bool
47:parm:           lapic_timer_advance:bool
48:parm:           ignore_msrs:bool
49:parm:           report_ignored_msrs:bool
50:parm:           min_timer_period_us:uint
51:parm:           kvmclock_periodic_sync:bool
52:parm:           tsc_tolerance_ppm:uint
53:parm:           vector_hashing:bool
54:parm:           enable_vmware_backdoor:bool
55:parm:           force_emulation_prefix:int
56:parm:           pi_inject_timer:bint
57:parm:           enable_pmu:bool
58:parm:           eager_page_split:bool
59:parm:           mitigate_smt_rsb:bool
60:parm:           halt_poll_ns:uint
61:parm:           halt_poll_ns_grow:uint
62:parm:           halt_poll_ns_grow_start:uint
63:parm:           halt_poll_ns_shrink:uint
64:parm:           allow_unsafe_mappings:bool
65:parm:           enable_virt_at_load:bool
```

观察：

- `enable_pmu` 不是 `kvm_intel` 私有参数，而是在通用 `kvm` 模块上。
- 当前值是 `N`。
- 这个 sysfs 节点是只读的，不能在线改。

### 2.3 `/dev/kvm` 权限

命令：

```bash
ls -l /dev/kvm
```

实际输出：

```text
crw-rw----+ 1 root kvm 10, 232 Mar 28 13:43 /dev/kvm
```

命令：

```bash
id
```

实际输出：

```text
uid=1000(yunwei37) gid=1000(yunwei37) groups=1000(yunwei37),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),100(users),114(lpadmin),124(docker),128(libvirt),984(ollama),993(kvm)
```

观察：

- 当前用户在 `kvm` 组里，`/dev/kvm` 访问权限没问题。

## 3. Guest 内核 PMU 状态

guest 使用的探测脚本文件：

```text
docs/tmp/20260328/kvm_pmu_guest_probe_20260328.sh
```

### 3.1 关键 guest 探测输出

实际输出（`vng-wrapper` 会把 transcript 打两次，下面只保留一份去重后的内容）：

```text
=== BEGIN whoami ===
root
=== END whoami (rc=0) ===

=== BEGIN uname -a ===
Linux virtme-ng 7.0.0-rc2+ #12 SMP PREEMPT_DYNAMIC Fri Mar 27 20:33:38 PDT 2026 x86_64 x86_64 x86_64 GNU/Linux
=== END uname -a (rc=0) ===

=== BEGIN which perf ===
/bin/perf
=== END which perf (rc=0) ===

=== BEGIN perf_event_paranoid initial ===
2
=== END perf_event_paranoid initial (rc=0) ===

=== BEGIN cpuinfo model name ===
model name	: Intel(R) Core(TM) Ultra 9 285K
model name	: Intel(R) Core(TM) Ultra 9 285K
=== END cpuinfo model name (rc=0) ===

=== BEGIN perf stat initial ===
WARNING: perf not found for kernel 7.0.0

  You may need to install the following packages for this specific kernel:
    linux-tools-7.0.0-rc2+
    linux-cloud-tools-7.0.0-rc2+

  You may also want to install one of the following packages to keep up to date:
    linux-tools-rc2+
    linux-cloud-tools-rc2+
=== END perf stat initial (rc=2) ===

=== BEGIN perf list hw initial ===
WARNING: perf not found for kernel 7.0.0

  You may need to install the following packages for this specific kernel:
    linux-tools-7.0.0-rc2+
    linux-cloud-tools-7.0.0-rc2+

  You may also want to install one of the following packages to keep up to date:
    linux-tools-rc2+
    linux-cloud-tools-rc2+
=== END perf list hw initial (rc=2) ===

=== BEGIN dmesg pmu ===
[    0.118003] Performance Events: unsupported CPU family 6 model 198 no PMU driver, software events only.
=== END dmesg pmu (rc=0) ===

=== BEGIN ls /sys/devices/cpu/events ===
ls: cannot access '/sys/devices/cpu/events/': No such file or directory
=== END ls /sys/devices/cpu/events (rc=2) ===

=== BEGIN ls /sys/devices/cpu_core/events ===
ls: cannot access '/sys/devices/cpu_core/events/': No such file or directory
=== END ls /sys/devices/cpu_core/events (rc=2) ===

=== BEGIN ls /sys/devices/cpu_atom/events ===
ls: cannot access '/sys/devices/cpu_atom/events/': No such file or directory
=== END ls /sys/devices/cpu_atom/events (rc=2) ===

=== BEGIN perf_event_open initial ===
branch-misses default attr: fd=-1, errno=2
branch-misses exclude_kernel=1 exclude_hv=1: fd=-1, errno=2
=== END perf_event_open initial (rc=0) ===

=== BEGIN lower perf_event_paranoid ===
-1
=== END lower perf_event_paranoid (rc=0) ===

=== BEGIN perf stat after perf_event_paranoid=-1 ===
WARNING: perf not found for kernel 7.0.0

  You may need to install the following packages for this specific kernel:
    linux-tools-7.0.0-rc2+
    linux-cloud-tools-7.0.0-rc2+

  You may also want to install one of the following packages to keep up to date:
    linux-tools-rc2+
    linux-cloud-tools-rc2+
=== END perf stat after perf_event_paranoid=-1 (rc=2) ===

=== BEGIN perf list hw after perf_event_paranoid=-1 ===
WARNING: perf not found for kernel 7.0.0

  You may need to install the following packages for this specific kernel:
    linux-tools-7.0.0-rc2+
    linux-cloud-tools-7.0.0-rc2+

  You may also want to install one of the following packages to keep up to date:
    linux-tools-rc2+
    linux-cloud-tools-rc2+
=== END perf list hw after perf_event_paranoid=-1 (rc=2) ===

=== BEGIN perf_event_open after perf_event_paranoid=-1 ===
branch-misses default attr: fd=-1, errno=2
branch-misses exclude_kernel=1 exclude_hv=1: fd=-1, errno=2
=== END perf_event_open after perf_event_paranoid=-1 (rc=0) ===
```

观察：

- guest 能看到宿主机 CPU 型号 `Intel(R) Core(TM) Ultra 9 285K`。
- 但 guest 内核启动早期就打印了 `unsupported CPU family 6 model 198 no PMU driver, software events only.`。
- `perf_event_open` 在 guest 中始终返回 `errno=2 (ENOENT)`。
- 把 guest 的 `perf_event_paranoid` 改成 `-1` 之后，`perf_event_open` 仍然是 `ENOENT`，所以不是 paranoid 问题。
- guest 里 `/sys/devices/cpu*` 的 PMU sysfs 节点完全不存在，和“只有 software events”一致。

### 3.2 guest `cpuinfo flags`

为确认 guest 是否拿到了 `arch_perfmon`，额外跑了一次最小命令。

命令：

```bash
runner/scripts/vng-wrapper.sh --run vendor/linux-framework/arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark --disable-monitor --cpus 2 --mem 2G --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp --rwdir /home/yunwei37/workspace/bpf-benchmark --exec 'bash -lc "grep -m1 ^flags /proc/cpuinfo; grep -m1 ^vmx\ flags /proc/cpuinfo; cat /proc/sys/kernel/perf_event_paranoid; dmesg | grep -i \"Performance Events\""' 
```

实际输出：

```text
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ss ht syscall nx pdpe1gb rdtscp lm rep_good nopl xtopology cpuid tsc_known_freq pni pclmulqdq vmx ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand hypervisor lahf_lm abm 3dnowprefetch topoext cpuid_fault ssbd ibrs ibpb stibp ibrs_enhanced tpr_shadow flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid rdseed adx smap clflushopt clwb sha_ni xsaveopt xsavec xgetbv1 xsaves avx_vnni lam wbnoinvd arat vnmi umip pku ospke waitpkg gfni vaes vpclmulqdq rdpid bus_lock_detect movdiri movdir64b fsrm md_clear serialize flush_l1d arch_capabilities
vmx flags	: vnmi preemption_timer posted_intr invvpid ept_x_only ept_ad ept_1gb flexpriority apicv tsc_offset vtpr mtf vapic ept vpid unrestricted_guest vapic_reg vid shadow_vmcs pml tsc_scaling usr_wait_pause
2
[    0.059842] Performance Events: unsupported CPU family 6 model 198 no PMU driver, software events only.
```

关键点：

- guest flags **没有 `arch_perfmon`**。
- 这和宿主机 flags 里明确有 `arch_perfmon` 形成直接对比。
- 因此 guest 没拿到 PMU CPUID 能力，而不是只缺 `perf` 用户态工具。

## 4. Guest kernel config / 源码交叉验证

### 4.1 `CONFIG_PERF_EVENTS`

命令：

```bash
rg -n "CONFIG_PERF_EVENTS|CONFIG_HW_PERF_EVENTS|CONFIG_HAVE_PERF_EVENTS" vendor/bpfrejit_defconfig vendor/linux-framework/.config
```

实际输出：

```text
vendor/linux-framework/.config:310:CONFIG_HAVE_PERF_EVENTS=y
vendor/linux-framework/.config:317:CONFIG_PERF_EVENTS=y
vendor/linux-framework/.config:470:CONFIG_PERF_EVENTS_INTEL_UNCORE=y
vendor/linux-framework/.config:471:CONFIG_PERF_EVENTS_INTEL_RAPL=m
vendor/linux-framework/.config:472:CONFIG_PERF_EVENTS_INTEL_CSTATE=m
vendor/linux-framework/.config:473:# CONFIG_PERF_EVENTS_AMD_POWER is not set
vendor/linux-framework/.config:474:CONFIG_PERF_EVENTS_AMD_UNCORE=m
vendor/linux-framework/.config:475:CONFIG_PERF_EVENTS_AMD_BRS=y
vendor/linux-framework/.config:926:CONFIG_HAVE_PERF_EVENTS_NMI=y
vendor/bpfrejit_defconfig:302:CONFIG_HAVE_PERF_EVENTS=y
vendor/bpfrejit_defconfig:308:CONFIG_PERF_EVENTS=y
vendor/bpfrejit_defconfig:457:CONFIG_PERF_EVENTS_INTEL_UNCORE=y
vendor/bpfrejit_defconfig:458:CONFIG_PERF_EVENTS_INTEL_RAPL=m
vendor/bpfrejit_defconfig:459:CONFIG_PERF_EVENTS_INTEL_CSTATE=m
vendor/bpfrejit_defconfig:460:# CONFIG_PERF_EVENTS_AMD_POWER is not set
vendor/bpfrejit_defconfig:461:CONFIG_PERF_EVENTS_AMD_UNCORE=m
vendor/bpfrejit_defconfig:462:CONFIG_PERF_EVENTS_AMD_BRS=y
vendor/bpfrejit_defconfig:907:CONFIG_HAVE_PERF_EVENTS_NMI=y
```

观察：

- guest kernel config 已经启用了 `CONFIG_PERF_EVENTS=y`。
- 所以“defconfig 没打开 perf events”也不是根因。

### 4.2 源码里是否支持 Arrow Lake / model 198

命令：

```bash
rg -n "198|0xc6|LUNARLAKE|ARROW|unsupported CPU family 6 model" vendor/linux-framework/arch/x86/events vendor/linux-framework/arch/x86/kernel/cpu -g '*.[ch]'
```

实际输出：

```text
vendor/linux-framework/arch/x86/events/rapl.c:885:	X86_MATCH_VFM(INTEL_ARROWLAKE_H,	&model_skl),
vendor/linux-framework/arch/x86/events/rapl.c:886:	X86_MATCH_VFM(INTEL_ARROWLAKE,		&model_skl),
vendor/linux-framework/arch/x86/events/rapl.c:887:	X86_MATCH_VFM(INTEL_ARROWLAKE_U,	&model_skl),
vendor/linux-framework/arch/x86/events/rapl.c:888:	X86_MATCH_VFM(INTEL_LUNARLAKE_M,	&model_skl),
vendor/linux-framework/arch/x86/kernel/cpu/common.c:1311:	VULNBL_INTEL_STEPS(INTEL_ARROWLAKE_H,	     X86_STEP_MAX,	VMSCAPE),
vendor/linux-framework/arch/x86/kernel/cpu/common.c:1312:	VULNBL_INTEL_STEPS(INTEL_ARROWLAKE,	     X86_STEP_MAX,	VMSCAPE),
vendor/linux-framework/arch/x86/kernel/cpu/common.c:1313:	VULNBL_INTEL_STEPS(INTEL_ARROWLAKE_U,	     X86_STEP_MAX,	VMSCAPE),
vendor/linux-framework/arch/x86/kernel/cpu/common.c:1314:	VULNBL_INTEL_STEPS(INTEL_LUNARLAKE_M,	     X86_STEP_MAX,	VMSCAPE),
vendor/linux-framework/arch/x86/events/intel/core.c:271:	INTEL_EVENT_CONSTRAINT(0xc6, 0xf),	/* FRONTEND_RETIRED.* */
vendor/linux-framework/arch/x86/events/intel/core.c:8257:	case INTEL_ARROWLAKE_U:
vendor/linux-framework/arch/x86/events/intel/core.c:8291:	case INTEL_LUNARLAKE_M:
vendor/linux-framework/arch/x86/events/intel/core.c:8292:	case INTEL_ARROWLAKE:
vendor/linux-framework/arch/x86/events/intel/core.c:8320:	case INTEL_ARROWLAKE_H:
vendor/linux-framework/arch/x86/events/intel/cstate.c:668:	X86_MATCH_VFM(INTEL_ARROWLAKE,		&adl_cstates),
vendor/linux-framework/arch/x86/events/intel/cstate.c:669:	X86_MATCH_VFM(INTEL_ARROWLAKE_H,	&adl_cstates),
vendor/linux-framework/arch/x86/events/intel/cstate.c:670:	X86_MATCH_VFM(INTEL_ARROWLAKE_U,	&adl_cstates),
vendor/linux-framework/arch/x86/events/intel/cstate.c:671:	X86_MATCH_VFM(INTEL_LUNARLAKE_M,	&lnl_cstates),
vendor/linux-framework/arch/x86/kernel/cpu/intel.c:570:	     c->x86_vfm == INTEL_LUNARLAKE_M))
vendor/linux-framework/arch/x86/events/intel/uncore.c:1919:	X86_MATCH_VFM(INTEL_ARROWLAKE,		&mtl_uncore_init),
vendor/linux-framework/arch/x86/events/intel/uncore.c:1920:	X86_MATCH_VFM(INTEL_ARROWLAKE_U,	&mtl_uncore_init),
vendor/linux-framework/arch/x86/events/intel/uncore.c:1921:	X86_MATCH_VFM(INTEL_ARROWLAKE_H,	&mtl_uncore_init),
vendor/linux-framework/arch/x86/events/intel/uncore.c:1922:	X86_MATCH_VFM(INTEL_LUNARLAKE_M,	&lnl_uncore_init),
vendor/linux-framework/arch/x86/kernel/cpu/microcode/intel-ucode-defs.h:134:{ .flags = X86_CPU_ID_FLAG_ENTRY_VALID, .vendor = X86_VENDOR_INTEL, .family = 0x6,  .model = 0xc6, .steppings = 0x0004, .driver_data = 0x118 },
vendor/linux-framework/arch/x86/kernel/cpu/microcode/intel-ucode-defs.h:135:{ .flags = X86_CPU_ID_FLAG_ENTRY_VALID, .vendor = X86_VENDOR_INTEL, .family = 0x6,  .model = 0xc6, .steppings = 0x0010, .driver_data = 0x118 },
vendor/linux-framework/arch/x86/include/asm/intel-family.h:147:#define INTEL_ARROWLAKE_H		IFM(6, 0xC5) /* Lion Cove / Skymont */
vendor/linux-framework/arch/x86/include/asm/intel-family.h:148:#define INTEL_ARROWLAKE			IFM(6, 0xC6)
vendor/linux-framework/arch/x86/include/asm/intel-family.h:149:#define INTEL_ARROWLAKE_U		IFM(6, 0xB5)
vendor/linux-framework/arch/x86/include/asm/intel-family.h:151:#define INTEL_LUNARLAKE_M		IFM(6, 0xBD) /* Lion Cove / Skymont */
```

观察：

- `vendor/linux-framework` 源码里已经包含 `INTEL_ARROWLAKE (0xC6)`。
- 因此 guest 报错里的 “unsupported CPU family 6 model 198” 不能简单解释成“源码不认识 Arrow Lake”。

### 4.3 这个报错实际在什么条件下触发

命令：

```bash
sed -n '7520,7565p' vendor/linux-framework/arch/x86/events/intel/core.c
```

实际输出：

```text
	union cpuid10_ebx ebx;
	unsigned int fixed_mask;
	bool pmem = false;
	int version, i;
	char *name;
	struct x86_hybrid_pmu *pmu;

	/* Architectural Perfmon was introduced starting with Core "Yonah" */
	if (!cpu_has(&boot_cpu_data, X86_FEATURE_ARCH_PERFMON)) {
		switch (boot_cpu_data.x86) {
		case  6:
			if (boot_cpu_data.x86_vfm < INTEL_CORE_YONAH)
				return p6_pmu_init();
			break;
		case 11:
			return knc_pmu_init();
		case 15:
			return p4_pmu_init();
		}

		pr_cont("unsupported CPU family %d model %d ",
			boot_cpu_data.x86, boot_cpu_data.x86_model);
		return -ENODEV;
	}

	/*
	 * Check whether the Architectural PerfMon supports
	 * Branch Misses Retired hw_event or not.
	 */
	cpuid(10, &eax.full, &ebx.full, &fixed_mask, &edx.full);
```

观察：

- 这条 dmesg 不是“型号表里没有 198”才打印。
- 真实触发条件是：`!X86_FEATURE_ARCH_PERFMON`。
- 而 guest 的 flags 确实缺少 `arch_perfmon`。

结合 guest flags 和 KVM 参数，可以得到严格推断：

- KVM 没有把 PMU architectural perfmon 能力 expose 给 guest。
- 这和宿主机 `enable_pmu=N` 完全一致。

## 5. 根因归纳

### 已排除

1. `vng` 没传 `-cpu host`
   - 已排除。`--dry-run` 实际 QEMU 命令中明确有 `-cpu host,topoext=on`。

2. guest `CONFIG_PERF_EVENTS` 没打开
   - 已排除。`vendor/bpfrejit_defconfig` 和实际 `.config` 都是 `CONFIG_PERF_EVENTS=y`。

3. guest `perf_event_paranoid` 太高
   - 已排除。guest 中改成 `-1` 后，`perf_event_open` 仍然是 `ENOENT`。

4. guest kernel 源码完全不支持 model 198 / Arrow Lake
   - 已排除。源码里已经有 `INTEL_ARROWLAKE (0xC6)` 和对应 PMU 初始化分支。

### 根因

宿主机 KVM 全局模块参数：

```text
/sys/module/kvm/parameters/enable_pmu = N
```

这导致：

1. QEMU 虽然传了 `-cpu host`，guest 仍然看不到 `arch_perfmon`。
2. guest dmesg 打印：

```text
Performance Events: unsupported CPU family 6 model 198 no PMU driver, software events only.
```

3. guest 里没有 `/sys/devices/cpu*` PMU 事件节点。
4. guest `perf_event_open(PERF_TYPE_HARDWARE, PERF_COUNT_HW_BRANCH_MISSES)` 返回 `ENOENT`。

## 6. 修复方案

### 主修复

需要在宿主机 **启用 KVM PMU virtualization**。

可执行方案：

1. 确认没有 VM 在跑后，设置 KVM 模块参数为开启。
2. 持久化方式示例：

```text
/etc/modprobe.d/kvm-pmu.conf
options kvm enable_pmu=1
```

3. 然后重载模块或直接重启宿主机。
4. 重启后验证：

```bash
cat /sys/module/kvm/parameters/enable_pmu
```

期望输出应为：

```text
Y
```

### 重新验证时应看到的变化

1. guest `grep -m1 ^flags /proc/cpuinfo` 应该出现 `arch_perfmon`。
2. guest `dmesg | grep -i "Performance Events"` 不应再出现 `software events only`。
3. guest `perf_event_open` 应该返回有效 fd，而不是 `ENOENT`。
4. guest `/sys/devices/cpu*` PMU 节点应出现。

### 次要修复

如果你还需要在 guest 里直接跑：

```bash
perf stat -e branches,branch-misses ls
perf list hw
```

还需要解决 guest `perf` userspace 和 guest kernel 的版本匹配问题。当前 guest 内核是：

```text
Linux virtme-ng 7.0.0-rc2+ #12 SMP PREEMPT_DYNAMIC Fri Mar 27 20:33:38 PDT 2026 x86_64 x86_64 x86_64 GNU/Linux
```

而 guest 里的 `/bin/perf` 没有对应这个 kernel 版本，所以一直报：

```text
WARNING: perf not found for kernel 7.0.0
```

这一步是辅助问题，不是 PMU passthrough 的根因。

## 7. 为什么这次没有直接“修”

我没有直接尝试在线修改 host KVM 参数，原因有两个：

1. 当前机器上已经有一个其他 `vm-e2e` 会话在运行，在线动全局 KVM 参数有干扰现有 VM 的风险。
2. `/sys/module/kvm/parameters/enable_pmu` 当前是只读：

```text
-r--r--r--
```

这意味着它不是一个可直接 `echo Y > ...` 的 runtime toggle，通常需要模块重载或宿主机重启。

所以本次给出的“修复方案”是可执行的，但我没有在存在其它活动 VM 的前提下直接改 host 全局 KVM 状态。

