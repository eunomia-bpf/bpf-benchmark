# Host Crash Investigation Report - 2026-03-25

## Executive Summary

The host machine (ASRock Z890M, Intel Core Ultra 9 285K, 125 GiB RAM) has experienced **19 reboots in 6 days** (March 19-25). There are多个互相关联的原因：

1. **BPF_PROG_REJIT verifier 安全边界失效**：daemon 生成的 malformed bytecode（错误的 LD_IMM64 scalar loads）通过 REJIT verifier 进入 JIT 执行，导致 guest kernel 执行非法代码。**无论 daemon 发送什么 bytecode，kernel verifier 必须拦住** — 这是内核侧 bug，不是用户态问题。
2. **Guest kernel crash → QEMU segfault**：malformed JIT code 在 guest 中执行导致非法内存访问，QEMU TCG 在 `tlb_set_dirty` 处 segfault（5 个 boot 中反复出现）。这不是"QEMU bug"，而是我们的 guest kernel 产生了非法行为。
3. **struct_ops refresh 吞错误导致 UAF**：`bpf_struct_ops_refresh_prog()` 失败时 err=0 静默继续，释放旧 JIT image 后 trampoline 指向已释放内存 — 经典 use-after-free。
4. **Host kernel slab corruption**：pstore 确认 `kfree` 栈损坏（ext4 路径触发），但 kernel tainted `[O][E]` 表示 kinsn OOT module 已加载 — **slab corruption 可能由 kinsn module 或 REJIT 内存管理 bug 引起**，只是被 ext4 路径触发。
5. **`panic_on_oops=1` 放大效应**：以上任何 oops 都被放大为硬重启。
6. **MCE 硬件问题**（可能的额外因素）：5/18 boots 有 MCE。

## 1. Root Causes (Ranked by Confidence)

### #1: Host Kernel Stack Corruption in ext4 (CONFIRMED - pstore evidence)

**Confidence: HIGH (direct evidence)**

The pstore at `/var/lib/systemd/pstore/1774383382/` contains the actual panic trace from the crash at **2026-03-24 13:16:22 PDT** (between boot -7 and boot -6):

```
Kernel panic - not syncing: stack-protector: Kernel stack is corrupted in: kfree+0x352/0x360
CPU: 1 UID: 1000 PID: 20816 Comm: pet Tainted: G   OE   6.15.11-061511-generic
Call Trace:
  kfree+0x352/0x360
  free_rb_tree_fname+0x47/0x70
  ext4_release_dir+0x1b/0x40
  __fput+0xea/0x2d0
  fput_close_sync+0x3d/0xa0
  __x64_sys_close+0x3e/0x90
```

**Analysis:**
- The crashed process is `pet` (VS Code Python Environment Tool at `~/.vscode-server/extensions/ms-python.python-*/python-env-tools/bin/pet`) -- **NOT a BpfReJIT process**.
- The stack canary (`__stack_chk_fail`) was tripped inside `kfree`, called from `ext4_release_dir` during a `close()` syscall.
- The kernel is tainted `[O]=OOT_MODULE, [E]=UNSIGNED_MODULE` -- the kinsn out-of-tree modules were loaded, but the crash path (`ext4_release_dir -> free_rb_tree_fname -> kfree`) is entirely in the stock kernel ext4 filesystem code.
- Stack corruption in `kfree` can be caused by: a slab corruption from any part of the kernel (including OOT modules), or a hardware memory error (see #3).

**Why this causes host reboot:** The kernel cmdline includes `panic_on_oops=1 panic=10`, so any stack corruption detection immediately triggers a kernel panic and reboot after 10 seconds.

### #2: Aggressive Panic Kernel Parameters (CONFIRMED)

**Confidence: HIGH (direct observation)**

The host kernel boots with:
```
panic=10 panic_on_oops=1 softlockup_panic=1 hung_task_panic=1
```

This means:
- **ANY** kernel oops (even non-fatal ones) -> panic -> reboot after 10 sec
- **ANY** soft lockup detection -> panic -> reboot
- **ANY** hung task detection -> panic -> reboot

On a normal desktop/lab machine, most of these events would produce a warning but the system would continue running. With these parameters, every minor glitch becomes a hard reboot.

### #3: Hardware Memory Errors (MCE) (PROBABLE)

**Confidence: MEDIUM (circumstantial)**

Machine Check Exceptions (MCE) were logged at boot time in 5 of the 18 boots:
- Boot -10 (Mar 24 02:11): `mce: [Hardware Error]: Machine check events logged`
- Boot -9 (Mar 24 08:18): MCE logged
- Boot -8 (Mar 24 10:32): MCE logged
- Boot -4 (Mar 24 20:08): MCE logged
- Boot -1 (Mar 25 04:48): MCE logged

MCE events logged at boot time indicate hardware errors detected during POST or early boot, which often means **errors persisted from the previous session**. This is consistent with the stack corruption in `kfree` -- a flipped bit in a slab object could corrupt the stack canary.

**Hardware context:** Intel Core Ultra 9 285K (Arrow Lake) is a relatively new architecture. BIOS version 1.30 (Sep 2024) may not have full stability patches.

### #4: QEMU Segfaults (CONFIRMED, RECURRING)

**Confidence: HIGH (direct evidence, but QEMU crashes don't cause host reboots)**

QEMU segfaults were found in **5 boots**, with a very consistent crash pattern:

| Boot | Timestamp | Crash Offset | Notes |
|------|-----------|-------------|-------|
| -12 | Mar 22 22:55 | 0x8dbe6b | Different offset |
| -12 | Mar 22 23:21 | 0x8d8f21 | |
| -9 | Mar 24 08:34 | 0x8d8f21 | Same offset, error 5 (read) |
| -9 | Mar 24 08:35 | 0x8df000 | Different offset |
| -5 | Mar 24 20:06 | 0x8d8f21 | |
| -4 | Mar 24 20:13 | 0x8d8f21 | 2 crashes in 9 min |
| -4 | Mar 24 20:16 | 0x8d8f21 | |

The crash at offset `0x8d8f21` is **extremely consistent** -- this is the same code path crashing every time. The crash is a NULL or near-NULL dereference (error 4 = read fault, low addresses like 0x10, 0x19, 0xb5d).

**QEMU version:** 8.2.2 (Debian 1:8.2.2+ds-0ubuntu1.13) -- this is the Ubuntu stock QEMU.

**Root cause:** BPF_PROG_REJIT 的 verifier 安全边界失效 — daemon 生成的 malformed bytecode 通过了 verifier 进入 JIT 执行。guest kernel 执行 malformed JIT code 时产生非法内存访问，QEMU 未能正确隔离导致 segfault。这不是"QEMU bug"，而是**我们的内核代码产生了不应该存在的 JIT code**。

**Impact:** QEMU segfaults kill the VM process。虽然 QEMU crash 本身不直接导致 host reboot，但 guest kernel 中的内存损坏可能通过 KVM 路径影响 host（特别是在 KVM 模式下）。TCG 模式下的 QEMU crash 证实了 malformed JIT code 的存在。

**关键安全问题:** 即使用户态 daemon 生成了错误的 bytecode，BPF verifier 必须 100% 拦截。当前 REJIT 路径存在 verifier bypass — 这是必须在内核侧修复的安全 bug。

### #5: OOM from Agent Memory Consumption (CONFIRMED, HISTORICAL)

**Confidence: HIGH for past events, MEDIUM for recent crashes**

Historical OOM events from `kern.log.2.gz` (March 12):
- `bpf-jit-scanner`: 56 GB RSS (killed), then re-spawned and grew to 95 GB RSS (killed again)
- Multiple `claude` processes: 7+ instances, each with 72-76 GB virtual memory
- `qemu-system-x86`: 110K RSS pages (~430 MB) -- not the problem itself

From `kern.log.4.gz` (Feb 23):
- `claude` process: 214 GB total-vm, 123 GB anon-rss (killed)

From `kern.log.3.gz` (Mar 1):
- Multiple OOM kills in cascade

**Current state:** The system currently has 119 GB free memory (idle). During testing, running multiple claude/codex agents + QEMU + daemon + kernel build can easily exceed 125 GB total.

### #6: Long Gaps Indicate Power Loss or User-Initiated Reboot

Two gaps are notably longer than the typical 1-7 minute reboot time:
- **Boot -3 to -2:** 3h 59m gap (00:24 -> 04:23) -- machine was likely OFF (power loss, user action, or thermal shutdown)
- **Boot -1 to 0:** 1h 23m gap (10:17 -> 11:40) -- same pattern

These long gaps are consistent with either:
- The machine being on battery/UPS and eventually shutting down
- A user manually powering off/on
- A thermal shutdown (temperatures are normal at idle: 42-60C, but under full load with 24 cores + QEMU, it could exceed limits)

## 2. Evidence for Each Hypothesis

### BpfReJIT 内核代码的关联（不能排除）

1. **REJIT verifier bypass 已确认**：daemon 生成的 malformed bytecode 曾通过 verifier 进入 JIT 执行（见 `docs/tmp/20260325/tcg_min_repro_and_e2e_investigation_20260325.md`）。虽然 replay 测试显示当前 verifier 能拦截，但 live 场景下曾经放过，说明存在竞态或条件性 bypass。
2. **struct_ops refresh UAF**：`bpf_struct_ops_refresh_prog()` 失败时吞错误（err=0），释放旧 JIT image 后 trampoline 仍指向已释放内存 — 这是确认的内核 use-after-free bug。
3. **Kernel tainted [O][E]**：kinsn OOT module 已加载。pstore crash 虽在 ext4/kfree，但 slab corruption 可能来自 kinsn module 或 REJIT 的内存管理。
4. **QEMU segfault 与 BpfReJIT 直接相关**：crash 只在运行 VM 测试时出现，且 `docs/tmp/20260325/tcg_min_repro_and_e2e_investigation_20260325.md` 已精确定位到 `scx prog 20 (rusty_exit)` 的 REJIT apply。
5. **smp_wmb() 不足**：upstream review 指出 `bpf_prog_rejit_swap` 使用 `smp_wmb()` 而非 `smp_store_release()`，在弱序架构上可能导致读端看到不一致状态。

### 非 BpfReJIT 因素

1. pstore panic 的直接触发路径是 ext4/kfree — 但不能排除 BpfReJIT 是 slab corruption 的间接来源
2. MCE 硬件问题（5/18 boots）— 可能的额外因素
3. `panic_on_oops=1` 放大效应 — 已修复（已从 grub 移除）

## 3. Boot Timeline Analysis

```
Date       Boot   Duration   Gap    Events
Mar 19     -17    26m        1m
Mar 19     -16    58m        10h    (overnight gap)
Mar 20     -15    5h17m      1m
Mar 20     -14    4h48m      1m
Mar 20-22  -13    41h46m     29m    sorttable segfaults (kernel build)
Mar 22-23  -12    22h52m     1m     2x QEMU segfault, python segfault
Mar 23-24  -11    14h7m      1m
Mar 24     -10    6h         7m     MCE logged
Mar 24     -9     2h12m      1.5m   2x QEMU segfault, MCE logged
Mar 24     -8     1h58m      4m     MCE logged
Mar 24     -7     42m        1m     PSTORE PANIC (pet/ext4/kfree)
Mar 24     -6     3h19m      7m
Mar 24     -5     3h24m      1m     QEMU segfault
Mar 24     -4     9m!        3m     MCE + 2x QEMU segfault
Mar 24-25  -3     4h4m       4h!    (machine OFF ~4h)
Mar 25     -2     23m        2m
Mar 25     -1     5h29m      1h23m  (machine OFF ~1h), pahole segfault
Mar 25     0      current
```

**Pattern:** March 24 was catastrophic -- 8 reboots in one day, with progressively shorter sessions. This is consistent with a hardware instability that gets worse under sustained load (thermal or memory degradation).

## 4. Recommendations

### Immediate Actions

1. **Remove panic-on-everything from kernel cmdline:**
   Edit `/etc/default/grub` and remove `panic_on_oops=1 softlockup_panic=1 hung_task_panic=1`. Keep `panic=10` only for truly unrecoverable situations. This alone would prevent most of the reboots.

2. **Update BIOS:** BIOS 1.30 (Sep 2024) is likely outdated for Arrow Lake. Check ASRock's website for Z890M Riptide WiFi BIOS updates.

3. **Run memtest86+:** The MCE events + stack corruption pattern strongly suggest DRAM issues. Run memtest86+ for at least 8 hours.

4. **Limit concurrent agents:** Add memory limits to claude/codex processes (e.g., `ulimit -v` or cgroup limits) to prevent OOM cascade.

### VM/Benchmark Improvements

5. **Update QEMU:** QEMU 8.2.2 has known issues with newer guest kernels. Consider installing QEMU 9.x from a PPA or building from source.

6. **Add VM memory guard:** In `runner/machines.yaml`, reduce VM memory to ensure host always has at least 20 GB free:
   ```yaml
   local-x86-vng:
     memory: 16G  # Consider reducing to 8G for safety
   ```

7. **Add OOM score for QEMU:** Set `oom_score_adj=500` for QEMU processes so they are killed before system-critical processes during OOM.

### Debugging Improvements

8. **Enable KASAN in guest kernel:** Add `CONFIG_KASAN=y` to the rejit-v2 kernel config to catch any memory corruption in the BPF/REJIT code paths. This would confirm or rule out kinsn module corruption.

9. **Enable pstore in guest kernel:** Configure `CONFIG_PSTORE` in the guest kernel so guest crashes are also captured.

10. **Add coredump for QEMU:** Configure `kernel.core_pattern` to capture QEMU coredumps for debugging the segfault at offset 0x8d8f21.

### Code Fixes (from previous investigation, still relevant)

11. **Fix struct_ops refresh error swallowing** (Risk 2 from previous report): If `bpf_struct_ops_refresh_prog()` fails, do not free the old JIT image.

12. **Add explicit slab integrity checks** in kinsn module `init`/`exit` paths to rule out OOT module slab corruption.

## 5. Conclusion

崩溃涉及多个层面的问题：

**内核侧必须修复的 bug（P0）：**
1. **BPF_PROG_REJIT verifier 安全边界**：无论 daemon 发什么 bytecode，verifier 必须拦截所有非法程序。当前存在条件性 bypass，必须在内核侧修复。
2. **struct_ops refresh UAF**：`bpf_struct_ops_refresh_prog()` 吞错误导致 use-after-free，必须修复错误传播。
3. **`bpf_prog_rejit_swap` 内存序**：`smp_wmb()` 需改为 `smp_store_release()`。

**用户态修复不解决内核崩溃问题** — daemon 代码无论怎么改，只要内核 verifier 有 bypass，就可能有其他来源的 malformed bytecode 导致同样的崩溃。

**已完成的缓解措施：**
- `panic_on_oops=1` 已从 grub 移除（不再将 oops 放大为硬重启）

**仍需排查：**
- KASAN 测试确认 kinsn module 是否引入 slab corruption
- MCE 硬件问题（memtest86+）
- REJIT verifier 路径与 PROG_LOAD 路径的完整对比（调查中，见 `rejit_verifier_safety_investigation_20260325.md`）
