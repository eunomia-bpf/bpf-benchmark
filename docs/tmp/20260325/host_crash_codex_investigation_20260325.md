# Host Crash Investigation - 2026-03-25

Scope: investigate why the host reboots while running repo VM tests (`make vm-micro`, `make vm-corpus`, `make vm-e2e`) against the modified `rejit-v2` guest kernel under `virtme-ng`.

## Executive Summary

- The repo-managed VM test path does not launch multiple VMs in parallel by default. `make vm-micro`, `make vm-corpus`, `make vm-e2e`, and `make vm-selftest` all resolve to the same `local-x86-vng` machine definition, defaulting to 19 vCPUs and 16G RAM, and every VM launch is wrapped by `runner/scripts/with_vm_lock.py` under the shared `vm_global` lock.
- Host-side memory pressure from repo-managed VMs alone is unlikely to explain the reboots on this 125 GiB host. One VM is 16G. Even if the lock were bypassed, 2/3/4 concurrent VMs would request about 32/48/64 GiB before host overhead.
- I found no host-kernel evidence of OOM, panic, oops, BUG, or BPF/REJIT-related failure around boot `-1` or boot `-2`. `/sys/fs/pstore` is empty. `/var/crash/` contains only user-space crash files, not a kernel dump.
- The strongest time correlation is boot `-2`: `micro/results/vm_micro_20260325_114452/metadata.json` shows `vm_micro` started at 2026-03-25 04:44:52 PDT, remained `status=running`, had `completed_benchmarks=0`, last updated at 04:44:53 PDT, and the host boot ended at 04:46:56 PDT. This looks like an abrupt interruption during `vm-micro`.
- The weaker boot `-1` case does not line up with an active repo VM workload. The last completed repo VM artifacts that boot were `vm_micro` at 2026-03-25 07:07:31 PDT and `vm_corpus` at 2026-03-25 07:11:28 PDT; boot `-1` ended at 10:17:20 PDT.
- `bpf_prog_rejit_swap()` and `bpf_struct_ops_refresh_prog()` are still guest-crash-risk code, but on their own they should crash or hang the guest kernel, not reboot the host. A host reboot would require a separate host-side problem such as QEMU/KVM, thermal/power instability, or unrelated host resource exhaustion.
- The only host-kernel anomaly I found near the boot `-2` reboot was CPU thermal throttling at 2026-03-25 04:43:15 PDT. That is not proof of root cause, but it is the only host-kernel warning close to the reset.

## 1. VM Test Launch Path And Memory Configuration

### 1.1 What files actually exist

- `runner/scripts/vm-selftest.sh` exists and is only a guest helper for `vm-selftest`.
- `runner/scripts/vm-micro.sh`, `runner/scripts/vm-corpus.sh`, and `runner/scripts/vm-e2e.sh` do not exist in the current tree.
- The real launch path for `vm-micro` / `vm-e2e` is:
  - root `Makefile`
  - `runner/Makefile`
  - `runner/scripts/run_vm_shell.py`
  - `runner/libs/vm.py`
  - `runner/scripts/vng-wrapper.sh`
  - `vng` / `virtme-ng`
- The real launch path for `vm-corpus` is:
  - root `Makefile`
  - `runner/Makefile`
  - `corpus/driver.py`
  - `corpus/modes.py`
  - `runner/libs/vm.py`
  - `runner/scripts/vng-wrapper.sh`
  - `vng` / `virtme-ng`

### 1.2 Default VM sizing

Relevant definitions:

- `runner/machines.yaml:1-29`
- `runner/libs/vm.py:65-111`
- `runner/Makefile:68-70`

Key facts:

- Default target is `local-x86-vng`.
- `local-x86-vng` is configured with `memory: 16G`.
- CPU count is auto-sized from host CPU count. On this host, `resolve_machine(action=...)` returns 19 vCPUs for `vm-micro`, `vm-corpus`, `vm-e2e`, and `vm-selftest`.
- If `VM_MEM` or `VM_CPUS` is set, `runner/Makefile` forwards those overrides as `--mem` / `--cpus`.

Directly reconstructed repo-side `vng` command for the `make vm-*` path:

```text
.../with_vm_lock.py --target x86 --action vm-micro -- \
.../vng-wrapper.sh --run .../bzImage --cwd .../bpf-benchmark \
--disable-monitor --cpus 19 --mem 16G --rwdir .../docs/tmp \
--rwdir .../bpf-benchmark --exec /tmp/guest.sh
```

The same `19 CPU / 16G` default applies to `vm-corpus`, `vm-e2e`, and `vm-selftest`.

### 1.3 QEMU memory parameter

- The repo itself does not build the final `qemu-system-x86_64` command line; it passes `--mem 16G` to `vng`.
- Inference from a live host `virtme-ng` instance observed during this investigation: `vng --mem 8G` became `qemu-system-x86_64 -m 8G`. Therefore the repo-managed `--mem 16G` should map to QEMU `-m 16G`.
- This is an inference from observed `virtme-ng` behavior, not a directly captured historical `make vm-*` QEMU command.

### 1.4 Host-visible concurrency

Relevant definitions:

- `runner/scripts/with_vm_lock.py:41-70`
- `runner/machines.yaml:1-38`
- `Makefile:306-310`
- `runner/Makefile:279-283`

Key facts:

- All x86 repo VM targets share `lock_scope: vm_global`.
- Every `build_vng_command()` result is wrapped by `with_vm_lock.py`.
- `with_vm_lock.py` takes an exclusive `flock()` on the per-scope lock file.
- Root `vm-all` is sequential: `vm-test`, then `vm-micro`, then `vm-corpus`, then `vm-e2e`.
- `runner/Makefile` `vm-all` is also sequential.

Conclusion:

- Repo-owned `make vm-*` launches are serialized on the host.
- Multiple host VMs only happen if the lock is bypassed or if some other non-repo launch path is used.

### 1.5 In-guest parallelism

Relevant definitions:

- `micro/driver.py:137-138`, `micro/driver.py:421-571`
- `corpus/modes.py:434-435`, `corpus/modes.py:523-700`

Key facts:

- `vm-micro` and `vm-corpus` do parallelize compile/preparation jobs inside one guest.
- With 19 guest vCPUs, the current formulas imply about 15 parallel guest jobs.
- This increases guest CPU and heat load, but it does not increase the number of host VMs.

Rough host memory demand if the VM lock were bypassed:

- 1 VM: about 16G guest RAM plus QEMU overhead
- 2 VMs: about 32G plus overhead
- 3 VMs: about 48G plus overhead
- 4 VMs: about 64G plus overhead

On a 125 GiB host, that still does not by itself explain a host OOM.

## 2. Makefile Serialization Check

Relevant definitions:

- root `Makefile:290-310`
- `runner/Makefile:248-283`

Findings:

- Root `make vm-micro`, `make vm-corpus`, and `make vm-e2e` are thin wrappers into `runner/Makefile`.
- There is no `-j`-style parallel composition between these VM targets in either `Makefile`.
- The repo path is intentionally serialized both by make target order and by the global VM lock.

## 3. Host Memory Snapshot

Current `free -h`:

```text
Mem:   125Gi total, 5.5Gi used, 114Gi free, 119Gi available
Swap:  8.0Gi total, 0 used
```

Interpretation:

- The host currently has ample free memory.
- This is only a current snapshot, not proof of memory state at reboot time.
- Historical OOM evidence exists on 2026-03-21, but it was a non-VM process:
  - `claude` was OOM-killed with about 124,911,356 kB anon RSS.

## 4. Previous Investigation Report

Read: `docs/tmp/20260324/vm_crash_investigation_20260324.md`

What still holds:

- `bpf_prog_rejit_swap()` is still a sensitive hot-swap path.
- `bpf_struct_ops_refresh_prog()` is still a sensitive direct text-poke path.
- These are credible guest-crash mechanisms.

What changed in the current tree:

- The previous report described a `struct_ops` refresh failure being swallowed and leading to a silent UAF.
- In the current code, that specific failure is not swallowed:
  - `vendor/linux-framework/kernel/bpf/syscall.c:3748-3764`
  - on failure, the code logs the error and attempts rollback
- So the earlier "refresh failure is silently ignored" diagnosis is stale for the current tree.
- Residual risk remains if rollback itself fails, but the exact old silent-UAF behavior is not what the current code does.

## 5. Host Logs, Boots, And Crash Dumps

### 5.1 Boot timeline

`journalctl --list-boots` confirms:

- boot `-2`: 2026-03-25 04:23:06 PDT to 04:46:56 PDT
- boot `-1`: 2026-03-25 04:48:14 PDT to 10:17:20 PDT
- boot `0`: 2026-03-25 11:40:22 PDT to current

This matches the user-provided boot gap.

### 5.2 `kern.log` / `journalctl -k`

Searches run:

- `grep -iE "oom|kill|panic|oops|BUG|bpf|rejit" /var/log/kern.log /var/log/kern.log.1`
- `journalctl -b -1 -k`
- `journalctl -b -2 -k`

Findings:

- No host panic/oops/BUG/BPF/REJIT messages near boot `-1` end or boot `-2` end.
- No host OOM around those boots.
- The only OOM in the inspected logs is the 2026-03-21 `claude` kill.
- The only host-kernel anomaly near the boot `-2` reset is thermal throttling:
  - 2026-03-25 04:43:15 PDT: package temperature above threshold on CPUs 2, 8, and 21
  - 2026-03-25 04:43:17-04:43:18 PDT: temperature/speed returned to normal

### 5.3 `/var/crash`

`/var/crash` contains only user-space crash reports:

- `_usr_bin_python3.12.1000.crash`
- `_usr_bin_python3.12.1001.crash` (not readable as current user)
- `_usr_bin_timeout.1000.crash`
- `_usr_bin_x86_64-linux-gnu-ar.1000.crash`
- `_usr_bin_x86_64-linux-gnu-ranlib.1000.crash`

Readable details:

- `_usr_bin_python3.12.1000.crash`
  - Date: 2026-03-24 10:04:46
  - `ProcCmdline: python3 -`
  - `ProcCwd: /home/yunwei37/workspace/bpf-benchmark`
  - signal 11
- The other readable crash files are unrelated GPU / binutils user-space crashes.

What I did not find:

- no kernel `vmcore`
- no kdump output
- no panic trace

### 5.4 `/sys/fs/pstore`

- `/sys/fs/pstore` is empty.
- That further argues against a preserved host kernel panic trace.

## 6. Artifact Timeline Correlation

### 6.1 Boot `-1` does not line up with an active repo VM run

Completed repo VM artifacts during boot `-1`:

- `micro/results/vm_micro_20260325_140416/metadata.json`
  - started: 2026-03-25 07:04:16 PDT
  - completed: 2026-03-25 07:07:31 PDT
- `corpus/results/vm_corpus_20260325_140818/metadata.json`
  - started: 2026-03-25 07:08:18 PDT
  - completed: 2026-03-25 07:11:28 PDT

Boot `-1` ended at 10:17:20 PDT, about three hours later.

I found no `e2e/results/*/metadata.json` created during the 2026-03-25 04:48-10:17 PDT window.

Conclusion:

- The boot `-1` reboot does not appear to have happened while a repo `vm-micro`, `vm-corpus`, or `vm-e2e` run was still active.

### 6.2 Boot `-2` does line up with an interrupted `vm-micro`

`micro/results/vm_micro_20260325_114452/metadata.json` shows:

- `generated_at`: 2026-03-25T11:44:52.841140+00:00 = 04:44:52 PDT
- `last_updated_at`: 2026-03-25T11:44:53.670046+00:00 = 04:44:53 PDT
- `status`: `running`
- `progress.completed_benchmarks`: `0`
- no `completed_at`

Boot `-2` ended at 04:46:56 PDT.

Interpretation:

- This is the closest direct correlation between a repo VM test and a host reboot.
- The run was interrupted very early, before even one benchmark completed.
- That still does not prove the guest kernel crashed the host; it only proves the host reboot happened shortly after `vm-micro` started.

## 7. Guest Kernel Risk Review

### 7.1 `bpf_prog_rejit_swap()`

Relevant code:

- `vendor/linux-framework/kernel/bpf/syscall.c:3360-3460`

What it does:

- swaps JIT image metadata and subprog arrays
- republishes `prog->bpf_func`
- retains the old function pointer on `tmp`
- later relies on post-swap synchronization before old image teardown

Risk:

- This is still a plausible guest UAF / stale-execution risk if the ordering assumptions are wrong.
- That can crash or hang the guest kernel.

### 7.2 `bpf_trampoline_refresh_prog()`

Relevant code:

- `vendor/linux-framework/kernel/bpf/trampoline.c:928-951`

What it does:

- rebuilds each user trampoline after `bpf_func` changes

Risk:

- Trampoline refresh failures can still destabilize the guest, but this is still guest scope.

### 7.3 `bpf_struct_ops_refresh_prog()`

Relevant code:

- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1471-1565`
- `vendor/linux-framework/kernel/bpf/syscall.c:3748-3764`

What it does:

- scans struct_ops trampoline text for the old direct call target
- patches the call to `prog->bpf_func`

Current behavior:

- if the call site is not found or `text_poke` fails, the function returns an error
- caller logs the failure and attempts rollback

Risk:

- Still a guest crash risk if refresh or rollback fails.
- Not the old "silently swallow and continue freeing old image" behavior described in the earlier report.

### 7.4 Can these guest bugs directly affect the host?

Most likely no.

Reasoning:

- These code paths execute in the guest kernel, not the host kernel.
- Under virtualization, guest memory corruption should at worst crash the guest or the QEMU process.
- A host reboot would require one of:
  - a host KVM/QEMU vulnerability or bug
  - a host thermal / power / firmware issue
  - host resource exhaustion from some other workload

Evidence found here:

- no host BPF/REJIT trace
- no host kernel panic/oops
- no host OOM
- no kernel crash dump

Conclusion:

- The guest REJIT code is a credible explanation for guest crashes.
- It is not a strong explanation for host reboots, absent a separate host-side bug.

## 8. Overall Conclusion

Most likely conclusion:

1. The repo-managed `make vm-*` path is serialized and defaults to one 19-vCPU / 16G VM at a time. Memory oversubscription from repo-owned VMs alone is not a strong match for the observed host reboots.
2. There is no host-kernel evidence that the reboots were caused by host OOM, host panic, or host BPF/REJIT failure.
3. The strongest repo correlation is an interrupted `vm-micro` run during boot `-2`, not boot `-1`.
4. The current tree no longer exhibits the exact old struct_ops refresh error-swallowing behavior from the 2026-03-24 report.
5. The data fits a host-side abrupt reset or hang better than a direct guest-kernel-to-host corruption story.

Most plausible explanations, ranked:

1. Host instability under load outside the guest-kernel logic itself.
   Evidence: no host panic/OOM, abrupt boot end, thermal throttling observed near boot `-2`.
2. Host-side KVM/QEMU issue triggered by the VM workload.
   Evidence: possible in principle, but no direct log evidence was found.
3. Host memory exhaustion from some concurrent non-VM workload.
   Evidence: possible historically because `claude` previously consumed about 125 GiB RSS, but not supported by the inspected reboot-window logs.
4. Guest REJIT bug directly corrupting the host.
   Evidence: weakest explanation; the virtualization boundary argues against it, and I found no host-side trace of such a failure.

## 9. Recommended Next Steps

If this needs to be reproduced and pinned down further, the highest-value next steps are:

1. Reproduce with only one workload active:
   run only `make vm-micro` on a clean host with no extra benchmark or static-verify jobs.
2. Capture host thermal and power telemetry during the run:
   `journalctl -kf`, `sensors`, `turbostat`, firmware/BMC logs if available.
3. Capture the exact `virtme-ng` / QEMU command and stderr for the failing run:
   keep the wrapper transcript and QEMU stderr in a persistent file.
4. Compare KVM and TCG:
   rerun with the TCG-style target (`local-x86-vng-tcg`) to separate guest-kernel issues from host KVM issues.
5. If the host reboots again with no Linux panic trace:
   treat it as a hard-reset / firmware / hardware-class event first, because Linux logging is not showing a software panic path.
