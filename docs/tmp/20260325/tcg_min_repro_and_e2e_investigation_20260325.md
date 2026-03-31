# TCG Minimal Reproduction And E2E Investigation

Date: 2026-03-25

## Scope

This note records the post-reboot investigation after host `panic_on_oops` was disabled and all follow-up reproductions were switched to QEMU TCG with hardware acceleration disabled.

The main goal was to answer three questions:

1. Is the failure reproducible without KVM?
2. Is the failure a single root cause, or multiple independent issues?
3. If `vm-static-test` does not explain the crash, does `e2e` reproduce anything useful?

## Investigation Policy

For the remainder of this investigation, userspace should be treated as an
error generator, not as the primary fix target.

Concretely:

- do not "fix" the reproducer by changing daemon / runner / probe behavior just
  to avoid the crash
- keep malformed or verifier-invalid REJIT output as a valid test input to the
  kernel boundary
- prioritize kernel-side safety properties first:
  - malformed `BPF_PROG_REJIT` input must be rejected safely
  - verifier failures must not escalate into kernel memory corruption, host
    reboot, or QEMU process crashes caused by kernel bugs
- userspace rewrite correctness issues may still be documented precisely, but
  they should be treated as bug-triggering inputs for kernel robustness work in
  this phase

## Environment Change

Host safety change:

```bash
sudo sysctl -w kernel.panic_on_oops=0
```

Runner change:

- Added `local-x86-vng-tcg` machine target in `runner/machines.yaml`
- `runner/libs/machines.py` now parses optional machine `args`
- `runner/libs/vm.py` now passes machine args to `vng`
- Current TCG target ran without hardware acceleration

This ensures guest workloads still run inside a VM, but without the host KVM path.

## Minimal Static Verify Reproductions

### 1. `sysctl_monitor`

Command:

```bash
make vm-static-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  STATIC_VERIFY_ARGS='--filter sysctl_monitor --max-objects 1'
```

Result:

- VM completed successfully under TCG
- No guest crash
- No host crash
- Deterministic REJIT failure remained

Observed failure:

- object: `corpus/build/systemd/sysctl-monitor.bpf.o`
- program: `sysctl_monitor`
- daemon reported `BPF_PROG_REJIT: Invalid argument`
- verifier log reported `call to invalid destination`

Interpretation:

- This is a correctness bug in the REJIT pipeline
- It is not evidence of a host panic or a QEMU crash

### 2. `event_execve`

Command:

```bash
make vm-static-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  STATIC_VERIFY_ARGS='--filter event_execve --max-objects 1'
```

Result:

- VM completed successfully under TCG
- No guest crash
- No host crash
- Deterministic REJIT failure remained

Observed failure:

- program: `event_execve`
- daemon first attributed a failure to `dce`
- retry disabled `dce`
- final REJIT attempt still failed with `BPF_PROG_REJIT: Invalid argument`
- verifier log reported `unreachable insn 169`

Interpretation:

- This is another correctness bug in the REJIT/userspace transform path
- It is distinct from the `sysctl_monitor` failure mode

## E2E Results Under TCG

### 1. `tracee --smoke`

Command:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && python3 e2e/run.py tracee --smoke'
```

Result:

- Guest completed successfully
- `vm-shell` exited with code 0
- E2E metadata completed successfully

Observed REJIT issue:

- program `lkm_seeker_modt`
- verifier log reported `unreachable insn 252`

Interpretation:

- `e2e` is not generically broken under TCG
- `tracee` reproduces the same class of verifier-invalid REJIT output without crashing QEMU

### 2. `scx --smoke`

Command:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && python3 e2e/run.py scx --smoke'
```

Result:

- VM entered the guest
- kinsn modules loaded
- `vm-shell` exited with code 255
- E2E metadata stayed in `running`
- Host journal showed a `qemu-system-x86_64` segfault

Observed host-side crash signature:

- process: `qemu-system-x86_64`
- signal: `SIGSEGV`
- fixed fault offset: `0x8d8f21`
- `addr2line` resolved the crash site to `tlb_set_dirty`

The same QEMU crash signature is also present in older host logs:

- 2026-03-23 11:52:09
- 2026-03-24 20:06:23
- 2026-03-24 20:13:34
- 2026-03-24 20:16:07
- 2026-03-25 11:58:49

Interpretation:

- This is a userspace QEMU crash under TCG
- It is not the same as the earlier host-kernel panic path under KVM
- It is also not reproduced by every E2E workload

## SCX Minimization

### Confirmed non-crashing steps

The following were run under TCG and did **not** crash QEMU:

- `scx_rusty --stats 1` by itself
- `bpfrejit-daemon enumerate` while `scx_rusty` was running
- single apply of program `9` (`rusty_enqueue`)

This means the full `scx --smoke` QEMU crash is not triggered by:

- merely loading `scx_rusty`
- merely enumerating programs
- the first successful struct_ops REJIT apply

### Targeted apply probe

Temporary investigation helper:

- `docs/tmp/scx_apply_probe.py`

Purpose:

- start `scx_rusty`
- enumerate struct_ops programs
- apply one or more program IDs
- capture the first failure precisely

Observed struct_ops IDs:

`7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20`

#### `prog 17` (`rusty_init_task`)

Result:

- REJIT failed
- no QEMU crash

Verifier error:

- `R2 invalid mem access 'scalar'`

#### `prog 18` (`rusty_exit_task`)

Result:

- REJIT failed
- no QEMU crash

Verifier error:

- `R2 invalid mem access 'scalar'`

#### `prog 19` (`rusty_init`)

Result:

- REJIT failed
- no QEMU crash

Verifier error:

- `R2 invalid mem access 'scalar'`

Interpretation:

- There is a real `scx` REJIT correctness bug on multiple struct_ops programs
- Those verifier failures are reproducible without any QEMU crash

#### `prog 20` (`rusty_exit`)

Command:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && timeout 90s python3 docs/tmp/scx_apply_probe.py 20'
```

Result:

- `vm-shell` exited with code 255
- host journal showed another `qemu-system-x86_64` segfault
- crash signature matched the earlier `scx --smoke` TCG crash

Observed host-side crash signature:

- process: `qemu-system-x86_64`
- signal: `SIGSEGV`
- fault offset: `0x8d8f21`
- `addr2line` previously resolved this site to `tlb_set_dirty`

Interpretation:

- `scx` no longer needs the full `e2e` path to reproduce the QEMU TCG crash
- A much smaller reproducer is now:
  - start `scx_rusty`
  - enumerate struct_ops programs
  - apply `prog 20` (`rusty_exit`)

Updated interpretation:

- `prog 17`, `18`, and `19` expose verifier-invalid REJIT output
- `prog 20` exposes a separate QEMU TCG crash path

## Current Conclusions

There are at least two issue classes:

1. REJIT correctness bugs
   - `sysctl_monitor`: `call to invalid destination`
   - `event_execve`: `unreachable insn 169`
   - `tracee` `lkm_seeker_modt`: `unreachable insn 252`
   - `scx` `rusty_init_task`: `R2 invalid mem access 'scalar'`
   - `scx` `rusty_exit_task`: `R2 invalid mem access 'scalar'`
   - `scx` `rusty_init`: `R2 invalid mem access 'scalar'`

2. A separate QEMU TCG userspace crash
   - reproduced on the full `scx --smoke` path
   - also reproduced by targeted `scx_apply_probe.py 20`
   - crash site consistently resolves near `qemu-system-x86_64:tlb_set_dirty`

These should not be treated as a single root cause.

## Update After Rebuilding The Current Daemon

After rebuilding the current source-tree daemon binary on 2026-03-25, the
earlier `rusty_exit` corruption no longer reproduced:

- `rewrite 20` changed from `30 -> 31 insns` down to `30 -> 29 insns`
- the two bogus plain `LD_IMM64` scalar loads disappeared
- `apply 20` completed with `REJIT ok`
- re-running the original `e2e/run.py scx --smoke` path no longer produced a
  new `qemu-system-x86_64` segfault on the host

The remaining `scx` failure on the current tree is a normal verifier rejection:

- `rusty_init_task` / `prog 17`
- `BPF_PROG_REJIT: Permission denied`
- verifier error: `R2 invalid mem access 'scalar'`

## Kernel Boundary Replay Check

To answer the kernel safety-boundary question directly, a dedicated replay
harness was added:

- `tests/negative/scx_bad_rejit_replay.c`
- `docs/tmp/scx_replay_bad20.sh`

The harness reconstructs the previously observed bad `rusty_exit` rewrite
pattern and submits it directly through `BPF_PROG_REJIT`, bypassing daemon pass
logic.

Observed result on 2026-03-25:

- current kernel rejected the malformed replay with `errno=13`
- verifier stopped at insn 9
- failure reason:
  - `R1 type=scalar expected=fp, pkt, pkt_meta, map_key, map_value, mem, ringbuf_mem, buf, trusted_ptr_`
- no host `qemu-system-x86_64` segfault was emitted during this replay

Interpretation:

- the safety boundary behaves correctly for this reconstructed malformed input
  on the current tree
- the historical TCG crash was real, but it is not currently reproduced once
  the source-tree daemon binary is rebuilt and the malformed replay is sent
  directly
- there is currently no live kernel-boundary crash reproducer in the updated
  tree; the remaining reproducible issue is the verifier rejection on
  `rusty_init_task`

## Update After Restoring Daemon Sources To `HEAD`

On 2026-03-25, the local daemon source files were restored to `HEAD` and the
daemon was rebuilt again. After that, the historical TCG userspace crash path
came back.

### Reproduction 1: historical `make vm-shell` path

Command:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && timeout 90s python3 docs/tmp/scx_apply_probe.py 20'
```

Observed result:

- guest printed only the module-load preamble
- `vm-shell` exited with code `255`
- no `APPLY 20 rc=...` line was emitted
- host journal recorded a new `qemu-system-x86_64` segfault

Host-side crash record:

- time: `2026-03-25 13:23:43 PDT`
- process: `qemu-system-x86_64`
- fixed image offset: `0x8d8f21`
- journal line:

```text
Mar 25 13:23:43 lab kernel: qemu-system-x86[21271]: segfault at 556411681fcd ip 0000599a60510f21 sp 00007b8e4affce48 error 4 in qemu-system-x86_64[8d8f21,599a6009c000+6e5000] likely on CPU 1 (core 4, socket 0)
```

### Reproduction 2: shorter direct `run_vm_shell.py` path

Command:

```bash
python3 runner/scripts/run_vm_shell.py \
  --target local-x86-vng-tcg \
  --action vm-test \
  --kernel-image vendor/linux-framework/arch/x86/boot/bzImage \
  --cpus 2 \
  --mem 8G \
  --timeout 360 \
  --command 'cd "/home/yunwei37/workspace/bpf-benchmark" && source "/home/yunwei37/workspace/.venv/bin/activate" && "/home/yunwei37/workspace/bpf-benchmark/module/load_all.sh" 2>/dev/null || true; cd "/home/yunwei37/workspace/bpf-benchmark" && timeout 90s python3 docs/tmp/scx_apply_probe.py 20'
```

Observed result:

- the wrapper exited almost immediately with code `255`
- host journal recorded another `qemu-system-x86_64` segfault
- the crash hit the same image offset `0x8d8f21`

Host-side crash record:

- time: `2026-03-25 13:24:24 PDT`
- process: `qemu-system-x86_64`
- fixed image offset: `0x8d8f21`
- journal line:

```text
Mar 25 13:24:24 lab kernel: qemu-system-x86[21945]: segfault at ffffffff9aed0120 ip 000058bcbc0b0f21 sp 00007eba7b5fde48 error 5 in qemu-system-x86_64[8d8f21,58bcbbc3c000+6e5000] likely on CPU 1 (core 4, socket 0)
```

Additional observations:

- `docs/tmp/20260325/scx_apply_probe.progress.log` existed but was empty
- this suggests the crash happened before `scx_apply_probe.py` reached its
  first durable progress write
- the faulting virtual address changed between the two crashes, but the image
  offset stayed fixed at `0x8d8f21`

Updated interpretation:

- the TCG userspace crash is live again once the daemon sources are restored to
  `HEAD`
- the targeted `scx_apply_probe.py 20` path is now a direct live reproducer
- this was reproduced twice in a row on 2026-03-25, both at the same QEMU text
  offset `0x8d8f21`

## Output Replay Differential

After the two direct `scx_apply_probe.py 20` reproductions, the path was
split into smaller variants to determine whether the crash really requires the
REJIT itself or whether it depends on how guest userspace reports the results.

### Shell stage script: no QEMU crash

Temporary helper:

- `docs/tmp/scx_probe_stage.sh`

Behavior:

- start `scx_rusty`
- sleep 3 seconds
- run `bpfrejit-daemon enumerate`
- run `bpfrejit-daemon apply 20`
- persist a stage log into hostfs after each step

Observed result on 2026-03-25:

- guest completed `enumerate`
- guest reached `apply 20`
- `apply 20` returned the expected verifier rejection
- no host `qemu-system-x86_64` segfault was emitted

Captured stage log:

```text
2026-03-25 13:27:04.682849487 -0700 start
2026-03-25 13:27:04.783356527 -0700 scx_started pid=198
2026-03-25 13:27:07.881005264 -0700 after_sleep
2026-03-25 13:27:08.391046501 -0700 after_enumerate
```

And the saved `apply.stderr` still showed the same verifier failure:

- `prog 20 (rusty_exit): 4 sites, 30 -> 31 insns`
- malformed `LD_IMM64` scalar folds were present
- verifier stopped at insn 9 with
  `R1 type=scalar expected=... map_value ...`

Interpretation:

- `scx_rusty -> enumerate -> apply 20` is not, by itself, sufficient to crash
  QEMU under TCG
- the direct REJIT verifier failure is reproducible without any QEMU crash

### Silent Python probe: no QEMU crash

Temporary helper:

- `docs/tmp/scx_apply_probe_silent.py`

Behavior:

- preserves the original Python `subprocess.run(..., capture_output=True)`
  structure
- does **not** replay `enumerate` / `apply` output back onto guest
  stdout/stderr
- saves the captured text into hostfs instead

Observed result on 2026-03-25:

- `enumerate_rc=0`
- `apply20_rc=1`
- no host `qemu-system-x86_64` segfault was emitted

Captured progress log:

```text
scx_started
before_enumerate
enumerate_rc=0
before_apply_20
apply20_rc=1
```

Interpretation:

- preserving the daemon/scx subprocess topology is still not enough to crash
  QEMU
- removing only the stdout/stderr replay step is enough to make the crash
  disappear in this variant

### Output replay alone

Using the saved outputs from the silent run:

1. Replaying only `enumerate.stdout` + `enumerate.stderr` back to guest
   stdout/stderr under TCG:
   - completed successfully
   - no QEMU crash

2. Replaying only `apply.stdout` + `apply.stderr` back to guest stdout/stderr:
   - command itself completed successfully
   - no `qemu-system-x86_64` segfault was emitted into the host journal
   - however, the host later rebooted again

Host reboot evidence after the `apply` output replay run:

- current host boot started at `2026-03-25 13:30 PDT`
- previous boot covered `2026-03-25 13:17-13:31 PDT`
- previous boot journal contains the earlier `13:23:43` and `13:24:24`
  QEMU segfaults, but no fresh `qemu-system-x86_64` segfault line near
  `13:29-13:30`

Updated interpretation:

- the reproducible TCG userspace crash is tightly correlated with the original
  `scx_apply_probe.py 20` behavior, not merely with the underlying
  `enumerate/apply` syscalls
- the silent and shell variants show that the malformed `rusty_exit` rewrite
  itself can be verifier-rejected cleanly without crashing QEMU
- replaying guest output is a strong differentiator, but the exact minimal
  crash trigger is still not fully isolated
- the later `13:30 PDT` host reboot is real, but because no fresh QEMU
  segfault line was recorded for that window, it should currently be tracked as
  a separate host-level failure, not yet as the same confirmed
  `qemu-system-x86_64@0x8d8f21` path

## Most Likely Next Steps

1. Continue minimizing the `scx` path:
   - reduce `scx_apply_probe.py 20` to an even smaller direct apply reproducer
   - check whether `prog 20` crashes with no prior apply history
   - inspect the transformed insn stream for `rusty_exit`

2. Fix the REJIT correctness bugs independently:
   - broken call-target fixup for `call to invalid destination`
   - CFG / branch / DCE / const-prop interaction for `unreachable insn`
   - `scx` struct_ops rewrite bug leading to `scalar` dereference

3. Keep TCG and KVM conclusions separate:
   - KVM path was capable of taking down the host before `panic_on_oops` was disabled
   - TCG path reproduces a QEMU userspace crash instead

## Manual Diff Review Of `rusty_exit`

After extracting the compact bytecode dumps from the failed `apply 20`
(`rusty_exit`) run and decoding them instruction-by-instruction, the verifier
failure is not best explained as a kernel verifier regression. The rewritten
program is already invalid before the kernel attempts to publish it.

Key observation from the current failing sample:

- before `const_prop`, the program carries typed map-value provenance through
  pointer arithmetic:
  - `pc 4: r1 = map_value`
  - `pc 6: r1 += 16`
  - later again `r1 = map_value`, then `r1 += 144`
- after `const_prop`, those two pointer adds become fresh `ldimm64` loads:
  - `pc 4: r1 = map_value`
  - `pc 6: r1 = 0x...21`
  - `pc 10: r1 = map_value`
  - `pc 12: r1 = 0x...a1`
- this destroys verifier-visible pointer type information and turns `r1` into a
  plain scalar immediately before `bpf_probe_read_kernel_str`

That matches the verifier rejection exactly:

- `R1 type=scalar expected=... map_value ...`
- failure occurs at the helper call after the rewritten `ldimm64`

This same shape is also visible in the older historical `rusty_exit_task`
failure embedded in `e2e/results/scx_20260325_053204/metadata.json`:

- verifier log shows `pc 4: r1 = map_value(...)`
- immediately followed by `pc 6: r1 = 0x1a800000021`
- then the helper call rejects `R1` as scalar

Current conclusion:

- the reproducible `rusty_exit` verifier failure is a REJIT rewrite bug
- the most specific root cause is `const_prop` materializing adjusted
  map-value pointers as raw scalar immediates
- this should be tracked separately from the TCG `qemu-system-x86_64`
  userspace crash

## Kernel Code Review Notes

I manually reviewed the kernel-side change set around
`kernel/bpf/syscall.c`, `kernel/bpf/trampoline.c`, `kernel/bpf/verifier.c`,
and `kernel/bpf/btf.c`.

Findings:

- the current dirty working-tree changes in `syscall.c` /
  `trampoline.c` are small and do not explain the `rusty_exit`
  verifier rejection:
  - `smp_wmb()` -> `smp_store_release(&prog->bpf_func, ...)`
  - `bpf_trampoline_refresh_prog(prog, old_bpf_func)` ->
    `bpf_trampoline_refresh_prog(prog)`
  - `bpf_free_kfunc_desc_tab()` callers replaced with `kfree()`
- `bpf_prog_rejit_swap()` initially looked suspicious because it copies
  `tmp->insnsi` into the original `prog`, but `bpf_prog_alloc()` rounds the
  allocation up to whole pages and `bpf_prog_rejit()` rejects replacements that
  exceed the original page budget. So the observed `30 -> 31 insns` case is not
  by itself evidence of an out-of-bounds write there.
- the verifier/kinsn refactor between `03cad9145` and `f0e7f673e` is mostly
  cleanup/inlining; I do not yet have a direct path from that refactor to the
  present `rusty_exit` failure

One kernel-side regression candidate did stand out during review:

- `kernel/bpf/btf.c` removed the defensive
  `if (!prog->aux->dst_prog) return -EINVAL;` check in the
  `BPF_PROG_TYPE_EXT` path and now dereferences `prog->aux->dst_prog`
  unconditionally

Current status of that finding:

- it is a real code-review concern
- it does not match the present `scx` / struct_ops reproducer
- it should not be confused with the already confirmed `const_prop`
  rewrite bug above

## 2026-03-25 Build Validation Notes

Re-ran the canonical repository kernel compile entrypoint:

- `make kernel-build JOBS=1`

This first exposed a branch-local compile break in the REJIT/kinsn series,
not a generic unrelated kernel build failure:

- `kernel/bpf/verifier.c:23776`: implicit declaration of
  `bpf_kinsn_has_native_emit`
- the same block also had misleading indentation, making the intended control
  flow around the `jit_requested && native_emit` fast path ambiguous

Minimal local compile fix applied:

- added `bpf_kinsn_has_native_emit()` in
  `vendor/linux-framework/include/linux/bpf.h`
- fixed the indentation/control flow in
  `vendor/linux-framework/kernel/bpf/verifier.c`

After that fix, the same `make kernel-build JOBS=1` re-run progressed past:

- `kernel/bpf/syscall.o`
- `kernel/bpf/verifier.o`
- `arch/x86/net/bpf_jit_comp.o`
- the full `kernel/bpf/` built-in archive build phase

At the time of writing this note, the single-threaded full kernel build was
still continuing beyond `kernel/bpf/` into the generic kernel and filesystem
subtrees. The important immediate result is that the current REJIT/kinsn patch
set did have a real compile blocker, and that blocker is now locally repaired
enough for the BPF/JIT objects to compile.

## 2026-03-25 VM Test Results

### 1. REJIT negative tests on `local-x86-vng-tcg`

Ran:

- `make vm-negative-test TARGET=local-x86-vng-tcg FUZZ_ROUNDS=1000`

Result:

- `adversarial_rejit`: `23 passed, 0 failed, 0 skipped`
- `fuzz_rejit`: `1000/1000` rounds passed
- accepted fuzzed replacements: `39`
- rejected fuzzed replacements: `961`

So the current kernel patch set did not immediately regress the existing
negative REJIT safety suite on the pure userspace QEMU TCG path.

### 2. Minimal `scx_rusty` loader on `local-x86-vng-tcg`

Ran a minimal guest command equivalent to:

- `timeout 20s runner/repos/scx/target/release/scx_rusty`

Observed behavior:

- `scx_rusty` starts successfully
- `sched_ext` becomes active
- after timeout / teardown it unregisters cleanly from userspace

So a single `scx_rusty` loader session by itself is not sufficient to crash the
TCG guest.

### 3. `e2e/run.py scx --smoke` failure shape

Ran:

- `make vm-shell TARGET=local-x86-vng-tcg VM_COMMAND='... python3 e2e/run.py scx --smoke'`

Observed behavior:

- guest prints a manual `PRE_E2E` marker
- no `scx` case output is emitted after that
- the VM session terminates with wrapper exit code `255`
- the new result directory
  `e2e/results/scx_20260325_210933/metadata.json`
  is left stuck in `"status": "running"`

This means the failure occurs inside the `python3 e2e/run.py scx --smoke`
path before the case can finalize its metadata.

### 4. Narrowed failure trigger inside `run_scx_case()`

To isolate the `scx` failure, I ran the `run_scx_case()` setup steps manually in
the guest with explicit progress markers:

- `STEP probe`: call `probe_bpftool_register()`
- `STEP session`: then attempt `ScxSchedulerSession(...).__enter__()`

Observed behavior:

- `STEP probe` completes successfully
- `bpftool struct_ops register` returns `0`
- but it leaves `sched_ext` still disabled and no active ops, matching the old
  "probe not actually usable" behavior
- after that, entering the `ScxSchedulerSession` path causes the VM session to
  die with exit `255`

Most important current conclusion:

- the current TCG guest failure is no longer "generic `scx_rusty` load crashes"
- it is specifically narrowed to the sequence:
  `probe_bpftool_register()` followed by the normal `scx_rusty` userspace loader
  session

That sequence is exactly present in `run_scx_case()`, which explains why
`python3 e2e/run.py scx --smoke` dies while a standalone `scx_rusty` invocation
can still succeed.

## 2026-03-25 Additional Narrowing After Exact Session Recheck

### 5. Canonical parallel kernel build now completes

Re-ran the canonical repo entrypoint with full parallelism:

- `make kernel-build JOBS=24`

Result:

- completed successfully
- produced `arch/x86/boot/bzImage`
- so the two local compile fixes in
  `vendor/linux-framework/include/linux/bpf.h` and
  `vendor/linux-framework/kernel/bpf/verifier.c`
  are sufficient for a clean full parallel kernel build, not merely a partial
  single-threaded BPF/JIT compile

### 6. `ScxSchedulerSession` is stable when the raw probe is skipped

Ran a minimal guest script that does only:

- skip `probe_bpftool_register()`
- enter `ScxSchedulerSession(...)`
- print discovered struct_ops prog ids
- exit the session cleanly

Observed behavior:

- `ScxSchedulerSession` succeeds
- discovered prog ids: `7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20`
- guest exits normally with wrapper exit code `0`

This matters because it proves the normal `scx_rusty` loader/session path is
not intrinsically unstable on this kernel. The raw `bpftool struct_ops register`
probe is a necessary precondition for the `exit 255` failure.

### 7. Failure now narrowed below `ScxSchedulerSession`

I then reduced the reproducer below the session wrapper itself.

Minimal failing sequence:

- `probe_bpftool_register()`
- `start_agent("bash", ["-lc", "exec scx_rusty --stats 1"])`
- `wait_healthy(proc, ..., lambda: read_scx_state() == "enabled" and bool(find_bpf_programs(proc.pid)))`

Observed behavior:

- the guest reaches `after_start_agent`
- the guest dies before `after_wait_healthy`
- wrapper exits with `255`

So the failure is no longer just "probe + `ScxSchedulerSession`". It is already
reproducible with the smaller sequence:

- raw `struct_ops register` probe
- start the normal loader
- while the loader is still coming up, poll `find_bpf_programs(pid)` as part of
  the health check

This points much more specifically at a kernel-visible race during the startup
window, likely involving one or both of:

- `/proc/<pid>/fdinfo` reads for in-flight struct_ops program FDs
- `bpftool prog show` enumeration while the new struct_ops set is being loaded
  after an earlier raw `struct_ops register` attempt

### 8. Current best differential conclusion

The following now hold simultaneously:

- `probe` alone does not crash
- `scx_rusty` session alone does not crash
- `probe + session` crashes
- `probe + start_agent + state-only wait` had previously succeeded
- `probe + start_agent + exact health check including find_bpf_programs(pid)`
  crashes

So the best current root-cause direction is not generic userspace loader logic,
and not generic daemon apply logic. It is the kernel boundary exposed by
enumerating live program ownership/metadata during the narrow post-probe,
pre-stable-load window of a second struct_ops loader attempt.

## 2026-03-25 Differential follow-up on `find_bpf_programs()`

I split the post-probe metadata path more aggressively inside the guest.

### 9. Raw probe alone is still stable

Ran:

- `probe_bpftool_register()` only

Observed behavior:

- `before_probe`
- `after_probe 0 disabled False`
- wrapper exit code `0`

So the raw `struct_ops register` probe by itself is not sufficient to kill the
guest.

### 10. `probe + state-only wait + find_bpf_programs(pid)` is still the best
live reproducer, but timing-sensitive

Ran:

- `probe_bpftool_register()`
- `start_agent(scx_rusty --stats 1)`
- `wait_healthy(..., lambda: read_scx_state() == "enabled")`
- `find_bpf_programs(pid)`

Observed twice:

- one run reached `after_wait_state True` and then died before the `after_find`
  marker
- a later re-run died even earlier with wrapper exit `255`, before any guest
  marker was emitted after boot

So this remains a live reproducer, but it is timing-sensitive rather than
perfectly deterministic at an instruction-exact point.

### 11. `/proc/<pid>/fdinfo` alone is stable

Ran:

- `probe`
- start `scx_rusty`
- wait for `sched_ext` to become `enabled`
- read every file under `/proc/<pid>/fdinfo`
- extract `prog_id:` values

Observed behavior:

- wrapper exit code `0`
- discovered live struct_ops prog ids:
  `37, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50`

This weakens the hypothesis that plain fdinfo walking is the primary bug.

### 12. `bpftool -j -p prog show` alone is also stable

Ran:

- `probe`
- start `scx_rusty`
- wait for `sched_ext` to become `enabled`
- run `/usr/local/sbin/bpftool -j -p prog show`

Observed behavior:

- wrapper exit code `0`
- `bpftool` returned `0`
- payload length was `13`

This weakens the hypothesis that a standalone `prog show` is sufficient to
trigger the failure.

### 13. `fdinfo` followed immediately by `bpftool prog show` is also stable

Ran:

- `probe`
- start `scx_rusty`
- wait for `enabled`
- scan `/proc/<pid>/fdinfo`
- immediately run `bpftool -j -p prog show`

Observed behavior:

- wrapper exit code `0`
- both phases completed

### 14. Current interpretation after the split

At this point:

- `probe` alone is stable
- `probe + second loader session` crashes
- `probe + state-only wait + find_bpf_programs(pid)` crashes/flakes
- `probe + state-only wait + fdinfo only` is stable
- `probe + state-only wait + bpftool prog show only` is stable
- `probe + state-only wait + fdinfo then bpftool show` is stable

So the remaining best interpretation is:

- the failure is a narrow timing-sensitive kernel boundary bug in the
  post-probe / second-loader startup window
- it is *not* explained by "fdinfo alone always crashes"
- it is *not* explained by "`bpftool prog show` alone always crashes"
- the combined helper path is still the best reproducer, but the exact race
  likely depends on when the metadata query lands relative to the second
  struct_ops loader becoming visible

One practical next step is kernel-side instrumentation in
`bpf_prog_get_info_by_fd()` and related prog-id iteration paths to learn how far
the `bpftool prog show` request gets before the guest dies.

## 2026-03-25 Kernel instrumentation follow-up in `bpf_prog_get_info_by_fd()`

I then moved the investigation into the kernel and kept userspace unchanged.
The goal was to determine whether the crash sits in the metadata path behind
`find_bpf_programs(pid)`.

### 15. Full parallel kernel build passed

Ran:

- `make kernel-build JOBS=24`

Observed behavior:

- full build completed successfully
- the latest successful image was built as `bzImage #82`

So the later investigation below was done against a clean, fully rebuilt kernel
rather than a partially compiled tree.

### 16. Added phase markers in `bpf_prog_get_info_by_fd()` and
`bpf_prog_get_fd_by_id()`

Instrumentation was added in `kernel/bpf/syscall.c` for `BPF_PROG_TYPE_STRUCT_OPS`
programs named `rusty_init*` and `rusty_exit*`.

The following phases were logged:

- `get_fd_by_id.enter`
- `get_fd_by_id.fd_ok`
- `get_info.enter`
- `get_info.after_maps`
- `get_info.after_stats`
- `get_info.done`

This let the guest print kernel-side progress immediately before the crash
window.

### 17. The first confirmed kernel bug was a null `prog->stats` dereference

Before any guard was added, one reproducer run died after the kernel emitted:

- `get_info.after_maps ... name=rusty_exit`

but before it emitted:

- `get_info.after_stats`
- `get_info.done`

That narrowed the crash to the `bpf_prog_get_stats()` call inside
`bpf_prog_get_info_by_fd()`.

Manual code review then found that `bpf_prog_get_stats()` iterated
`per_cpu_ptr(prog->stats, cpu)` without checking whether `prog->stats` was
NULL, even though other hot paths in the same kernel already guard that case.

I added a minimal guard:

```c
if (unlikely(!prog->stats)) {
	stats->nsecs = 0;
	stats->cnt = 0;
	stats->misses = 0;
	return;
}
```

This is a real kernel-side safety fix and should stay, independent of the
remaining race.

### 18. The null-stats fix helps, but does not fully eliminate the crash

After rebuilding with the null-stats guard:

- the reproducer sometimes survived longer than before
- but `probe + start_agent + wait(enabled) + repeated find_bpf_programs(pid)`
  could still kill the guest with wrapper exit `255`

One representative run reached:

- `MARK after_find_iter 2`
- `MARK before_find_iter 3`

and then the guest died.

In that later run, the kernel had already emitted successful completion logs
for the watched `rusty_init*` / `rusty_exit*` programs from earlier iterations,
including `get_info.done`.

So the current interpretation is:

- `prog->stats == NULL` was one genuine kernel bug in the metadata path
- fixing it was necessary, but not sufficient
- there is still at least one additional lifetime/race bug in the same broader
  program-enumeration window

### 19. Current best reproducer remains a kernel metadata race

The strongest reproducer remains:

- `probe_bpftool_register()`
- start `scx_rusty --stats 1`
- wait until `read_scx_state() == "enabled"`
- repeatedly call `find_bpf_programs(pid)`

What is now ruled out:

- `probe` alone
- `fdinfo` walking alone
- `bpftool -j -p prog show` alone

What remains most plausible:

- a timing-sensitive bug in kernel program enumeration / metadata reporting
- triggered during the unstable post-probe, second-loader struct_ops window
- not explained by a single unconditional crash in either `fdinfo` scanning or
  standalone `bpftool prog show`

### 20. Repeating `bpftool prog show` is sufficient; repeating `fdinfo` is not

I then split the repeated helper path into repeated `fdinfo` scans versus
repeated `bpftool` program metadata queries.

Ran:

- `probe`
- start `scx_rusty --stats 1`
- wait until `read_scx_state() == "enabled"`
- either:
  - loop `fdinfo` scans 20 times
  - or loop `bpftool -j -p prog show` 20 times

Observed behavior:

- repeated `fdinfo` scans completed 20/20 iterations successfully
- repeated `bpftool -j -p prog show` was sufficient by itself to kill the guest
  with wrapper exit `255`

This is a materially stronger isolation result than the earlier single-shot
tests. The remaining crash no longer requires the full `find_bpf_programs(pid)`
wrapper. The `bpftool prog show` metadata path by itself is enough, provided it
is exercised repeatedly during the unstable post-probe / second-loader window.

### 21. Owner-program subset probing narrowed the crash to a single live
struct_ops query window

I then queried only the program IDs discovered from `/proc/<pid>/fdinfo`,
instead of enumerating the whole global program table on every iteration.

One representative run observed:

- owner ids: `37, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50`
- successful per-id `bpftool prog show id <id>` for:
  `37, 39, 40, 41, 42, 43, 44, 45, 46, 47`
- crash immediately after `before_owner_prog 0 48`

After widening kernel-side `struct_ops` debug logging and rebuilding as
`bzImage #83`, a later rerun died earlier in the same style:

- successful per-id queries for `37, 39`
- crash immediately after `before_owner_prog 0 40`

So the exact victim ID is timing-sensitive, but the reproducer window is now
much tighter:

- we do not need the entire helper wrapper
- we do not need all global program IDs
- repeatedly querying the currently owned live `struct_ops` program subset is
  enough

### 22. The latest disconnect was accompanied by host-side `qemu-system-x86_64`
segfaults before the reboot

After the most recent disconnect/restart, I checked the host boot history and
previous-boot journals.

Observed on the host:

- previous boot `-1` ended at `2026-03-25 14:58:18 PDT`
- current boot `0` started at `2026-03-25 15:11:39 PDT`
- `who -b` reported current system boot at `2026-03-25 15:11`
- host QEMU version is `8.2.2 (Debian/Ubuntu package 1:8.2.2+ds-0ubuntu1.13)`
- the previous boot's kernel log recorded:
  - `qemu-system-x86[551224]: segfault ...` at `2026-03-25 14:54:52 PDT`
  - `qemu-system-x86[562212]: segfault ...` at `2026-03-25 14:55:39 PDT`
  - `qemu-system-x86[575051]: segfault ...` at `2026-03-25 14:57:59 PDT`

I also resolved the repeated QEMU code offsets with `addr2line` against the host
binary `/usr/bin/qemu-system-x86_64`:

- the dominant crash offset `0x8d8f21` resolves to `tlb_set_dirty`
- one nearby crash offset `0x8dbe6b` resolves to `tlb_set_page_full`

This matters because it sharpens the host-side symptom:

- at least some of the "guest died / session dropped" events are preceded by a
  host userspace `qemu-system-x86_64` segfault, not just a silent guest-only
  exit
- the host-side failure is not random in QEMU userspace; it repeatedly lands in
  the same TLB/dirty-page tracking area
- the exact crash mechanism still needs more evidence, but the boundary is now
  "triggered by guest-side repeated `bpftool prog show`, expressed on the host
  as a QEMU userspace crash"

At the time of this note, the latest reboot/disconnect evidence has been
recorded, but the final surviving kernel phase immediately before the QEMU crash
still needs one more successful line-buffered capture run.

## 2026-03-25 Later host evidence: repeated `qemu-system-x86_64` userspace segfaults

After the later disconnect/reboot, I rechecked host boot history and the
previous boot logs.

Observed boot timeline:

- previous boot `-1` ran from `2026-03-25 13:30:58 PDT` to
  `2026-03-25 14:58:18 PDT`
- current boot `0` started at `2026-03-25 15:11:39 PDT`

This means the later disconnect was not only a guest-side wrapper failure. The
host had in fact rebooted again.

### 20. The previous boot contains repeated `qemu-system-x86_64` segfaults

From `journalctl -k -b -1`, the previous boot recorded many explicit QEMU
userspace crashes, including:

- `2026-03-25 14:54:52 PDT`
- `2026-03-25 14:55:39 PDT`
- `2026-03-25 14:57:59 PDT`

The latest of these lines was:

- `Mar 25 14:57:59 ... qemu-system-x86[575051]: segfault at 11 ... error 4 in qemu-system-x86_64 ...`

This is especially important because it overlaps with the later
`manual-owner-id-loop` / repeated `bpftool prog show` narrowing work.

### 21. Current interpretation after this log review

The investigation picture is now more precise:

- there is at least one real kernel bug in the prog-info path
  (`bpf_prog_get_stats()` lacking a null `prog->stats` guard), and that fix
  should stay
- there is still an unresolved remaining bug after that fix
- for the later failures, the strongest direct host-side evidence is no longer
  "mysterious reboot with no trace", but repeated `qemu-system-x86_64`
  userspace segfaults during the same broader reproducer family

So for this later phase of the investigation, the practical question is:

- which kernel-side metadata / struct_ops state transition is causing QEMU TCG
  userspace to crash while serving the repeated `bpftool prog show` path

That does not weaken the kernel-boundary requirement. It only sharpens the
crash shape:

- the remaining issue may be triggering a QEMU TCG userspace fault rather than
  only a silent host hard hang
- the best live reproducer is still centered on repeated `bpftool prog show`
  against live `struct_ops` programs after the probe + second-loader sequence

## 2026-03-25 Later narrowing to specific `scx_rusty` callbacks

To avoid broad repeated enumeration, I changed the guest debug helper so it
could query owner program IDs one at a time and print the returned program
name/type.

### 22. `prog_id=40` and `prog_id=41` are stable; the next failure boundary is
at `prog_id=42`

Ran:

- `probe_bpftool_register()`
- start `scx_rusty --stats 1`
- wait until `sched_ext == enabled`
- query owner IDs one by one with `bpftool -j -p prog show id <prog_id>`
- first narrowed run started from `prog_id >= 40`

Observed behavior:

- `prog_id=40` returned successfully as `rusty_dispatch`
- `prog_id=41` returned successfully as `rusty_runnable`
- the guest then died before completing `prog_id=42`

So the crash window is no longer "somewhere in the owner set". It is now
bounded to:

- after successful `rusty_dispatch`
- after successful `rusty_runnable`
- before successful completion of the next owner callback query

### 23. Single-program query for `owner_only_id=42` is sufficient to crash QEMU

I then ran a more targeted reproducer that queried only owner id `42`.

Observed host-side evidence on the current boot:

- `2026-03-25 15:23:04 PDT`
- `qemu-system-x86[22443]: segfault ... in qemu-system-x86_64 ...`

So by this point, repeated whole-set enumeration is no longer necessary. A
single focused owner-id query is sufficient to trigger the host-side QEMU
userspace crash.

### 24. Best current inference: `prog_id=42` is likely `rusty_running`

This inference is not yet directly proven by a successful `bpftool` response
for id `42`, but it is strongly supported by two facts:

- successful live mappings already observed:
  - `40 -> rusty_dispatch`
  - `41 -> rusty_runnable`
- the `scx_rusty` object defines the next struct_ops callbacks in this order:
  - `rusty_running`
  - `rusty_stopping`
  - `rusty_quiescent`
  - `rusty_set_weight`
  - `rusty_set_cpumask`
  - `rusty_init_task`
  - `rusty_exit_task`
  - `rusty_init`
  - `rusty_exit`

So the strongest current working hypothesis is:

- `prog_id=42` corresponds to `rusty_running`
- the smallest known live reproducer is now effectively "query the next
  callback after `rusty_runnable`"

## 2026-03-25 Historical snapshot check: `2026-03-21` snapshot does not
reproduce this minimal trigger

To answer whether this behavior already existed in the earlier `2026-03-21`
snapshot, I set up a *matching* historical top-level repo snapshot instead of
mixing the current top-level tree with an old kernel worktree.

Important compatibility note:

- using the current top-level repo together with old kernel commit
  `1d040ec0c3f1819b33999f94fec4e171dda07a81` is **not** a valid reproducer
  environment
- that mixed setup fails before VM boot in `module/x86/bpf_rotate.c`, because
  the current repo's kinsn module sources expect newer `struct bpf_kinsn` /
  `DEFINE_KINSN_V2_MODULE` interfaces that do not exist in `1d040ec0c`

The valid historical test environment was:

- top-level repo snapshot: `909f6efe30d0caa8e8fbd33c31eba2a2429993f8`
- `vendor/linux-framework` commit:
  `1d040ec0c3f1819b33999f94fec4e171dda07a81`
- guest command:
  `python3 -u docs/tmp/20260325/bisect_scx_repro.py --iterations <N> --load-timeout 20`

The guest script performed the same minimal chain:

- `probe_bpftool_register()`
- start `scx_rusty --stats 1`
- wait for `sched_ext == enabled`
- repeat `bpftool -j -p prog show`

Observed results on the historical snapshot:

- `--iterations 20`: completed successfully
- `--iterations 100`: completed successfully
- every iteration returned `returncode=0`
- every iteration returned a stable payload length of `13`
- no guest failure, no host QEMU crash, and no host disconnect occurred during
  these runs

So the current evidence now supports a meaningful temporal split:

- the minimal trigger **does reproduce** on the current investigation tree
- the same minimal trigger **does not reproduce** on the matched
  `2026-03-21` snapshot tested above

This does **not** yet prove the exact first bad commit, but it does show that
the issue is not an unavoidable property of the older `2026-03-21` baseline.

## 2026-03-25 Follow-up historical check: later `2026-03-21` snapshot also
does not reproduce

I then tested a later `2026-03-21` matched snapshot:

- top-level repo snapshot: `72051ac300293dd6542cd3963bc94300b528feaf`
- `vendor/linux-framework` commit:
  `e7d27ef37317d4004e2eb83958512ec2536b1444`

This kernel worktree initially needed two compatibility accommodations for the
historical VM runner environment:

- copy a known-good `.config` and run `olddefconfig`
- generate the expected `modules.order` metadata for the same minimal set of VM
  support modules used in the earlier snapshot

Those steps were only to satisfy the historical VM launch environment. They do
not change the guest reproducer itself.

The guest reproducer remained the same:

- `probe_bpftool_register()`
- start `scx_rusty --stats 1`
- wait for `sched_ext == enabled`
- repeat `bpftool -j -p prog show`

Observed results on `72051ac / e7d27ef37`:

- `--iterations 20`: completed successfully
- `--iterations 100`: completed successfully
- every iteration returned `returncode=0`
- every iteration returned a stable payload length of `13`
- no guest failure, no host QEMU crash, and no host disconnect occurred during
  these runs

So the current bisect state is now:

- `good`: `909f6ef / 1d040ec0c`
- `good`: `72051ac / e7d27ef37`
- `bad`: current investigation tree

That strengthens the regression claim substantially:

- this issue is **not** reproduced on the two tested `2026-03-21` matched
  historical snapshots
- it is very likely introduced by a later change set, not by the older
  baseline itself

## 2026-03-25 Current-tree hardening patch set applied during investigation

While the historical bisect continued, I also applied a first current-tree
hardening pass against the confirmed REJIT / struct_ops review findings.

The current dirty tree now includes these targeted kernel-side changes:

- `vendor/linux-framework/kernel/bpf/syscall.c`
  - keep the existing `prog->stats == NULL` guard in `bpf_prog_get_stats()`
  - extend `bpf_prog_rejit_swap()` so the in-place publish also swaps or
    restores additional verifier/JIT-derived metadata that had been left behind,
    including `ctx_arg_info{,_size}`, `tail_call_reachable`, `arena`,
    `attach_func_{proto,name}`, `exception_cb`, `might_sleep`,
    `saved_dst_{prog,attach}_type`, `mod`, and `jit_requested`
  - restore release semantics for publishing the replacement image with
    `smp_store_release(&prog->bpf_func, tmp->bpf_func)`
  - serialize `bpf_prog_get_info_by_fd()` under `prog->aux->rejit_mutex`
    and snapshot `func[]/func_cnt/real_func_cnt` before walking subprog
    metadata, so `bpftool prog show` fails closed with `-EIO` instead of
    continuing through an internally inconsistent function array
  - defer main-program kallsyms re-registration until `post_swap_sync`,
    after the REJIT grace period
- `vendor/linux-framework/kernel/bpf/core.c`
  - restore `__bpf_ksym_del()` to `list_del_rcu()` semantics without the
    early `INIT_LIST_HEAD_RCU()` self-loop, matching original `master`
- `vendor/linux-framework/include/linux/filter.h`
  - switch `__bpf_prog_run()` to `smp_load_acquire(&prog->bpf_func)` so the
    runtime execution path pairs with the release-store publish above
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
  - make `bpf_struct_ops_refresh_prog()` tolerate already-updated call sites
  - add local rollback of already-patched call sites if a later `text_poke`
    fails, instead of leaving a partial mixed old/new trampoline image behind

I then ran a targeted host-side build check for the touched code:

```bash
make -C vendor/linux-framework -j4 \
  kernel/bpf/core.o kernel/bpf/syscall.o \
  kernel/bpf/bpf_struct_ops.o kernel/bpf/verifier.o
```

This completed successfully.

These changes do **not** yet prove that the live QEMU/host crash is fully
resolved, but they remove several confirmed correctness holes from the current
investigation tree before the next narrow VM reproducer pass.

## 2026-03-25 Daemon fix and current-tree validation after the crash-path split

After the crash-path review converged on "two independent bugs were being mixed
together", I applied a separate daemon-side fix and reran the narrow VM probes
against the current kernel tree.

### Daemon-side fix (`const_prop` typed `LD_IMM64`)

The daemon-side malformed rewrite bug is now fixed in the current tree:

- `daemon/src/passes/const_prop.rs`
  - `const_prop` no longer treats typed `LD_IMM64` (`src_reg != 0`) as a plain
    scalar constant
  - this prevents it from folding `BPF_PSEUDO_MAP_VALUE` into a replacement
    `LD_IMM64(src=0)` and losing verifier-visible pointer provenance
  - a regression test was added to pin this behavior

Host-side daemon validation:

```bash
make daemon-tests
```

Result:

- `340 passed`
- `0 failed`
- `12 ignored`

So the daemon-side `const_prop` bug is fixed and test-covered locally.

### Current-tree VM validation: full `bpftool prog show` path still crashes

I reran the previously crashing minimal live reproducer on the current tree:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-bpftool-loop --find-iterations 20 --load-timeout 20'
```

Observed guest output:

- `MARK after_probe 0 disabled False`
- `MARK after_start_agent 201`
- `MARK after_wait_state True`
- `MARK after_bpftool_iter 0 0 13`
- `MARK after_bpftool_iter 1 0 13`
- crash/hang before `after_bpftool_iter 2`

Host-side evidence for the same run:

- `2026-03-25 16:57:24 PDT`
- `qemu-system-x86_64` segfault
- fixed fault offset still `0x8d8f21`

So the current kernel-side hardening patches did **not** fully resolve the live
crash. The failure now occurs even earlier in the repeated `bpftool prog show`
loop than the earlier `iter 7` observation.

### Current-tree VM validation: minimal raw prog-info loop is stable

To separate "early `BPF_OBJ_GET_INFO_BY_FD` scalar fields" from the fuller
metadata that `bpftool prog show` requests, I then ran the raw-syscall probe:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- every iteration returned the same 13 live program ids:
  - `[37, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50]`
- `after_stop_agent 0`
- VM exited normally with `COMMAND_EXIT_CODE="0"`

This is an important narrowing result:

- the current crash is **not** triggered by the minimal `BPF_OBJ_GET_INFO_BY_FD`
  scalar snapshot alone
- the remaining failure is now more likely in the richer metadata requested by
  `bpftool -j -p prog show`
- in other words, the bug window is narrower than "all of get_info"; it is in
  the later metadata/reporting path that the raw minimal loop does not touch

That means the next reproducer pass should focus on isolating which owner
program id and which later metadata block inside `bpftool prog show` is still
capable of killing the live TCG guest.

### Current-tree VM validation: raw prog + `map_ids` loop is also stable

I then extended the raw-syscall probe to include the second
`BPF_OBJ_GET_INFO_BY_FD` call that fetches `map_ids[]` for each live program:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-mapids-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- every iteration returned the same 13 records and the same stable map-counts:
  - `[(37, 11), (39, 11), (40, 5), (41, 7), (42, 7), (43, 6), (44, 7),`
    `(45, 6), (46, 10), (47, 10), (48, 9), (49, 10), (50, 4)]`
- `after_stop_agent 0`
- VM exited normally with `COMMAND_EXIT_CODE="0"`

This narrows the remaining crash window again:

- the residual crash is **not** in the initial raw prog-info snapshot
- it is also **not** in the second raw `map_ids[]` fetch alone
- the next most likely trigger is later in the `bpftool prog show` metadata
  expansion, i.e. `show_prog_metadata()` and its per-map map-info / rodata /
  BTF follow-up path rather than the earliest `bpf_prog_get_info_by_fd()` calls

### Mitigation note only: repo-side workaround exists, but is intentionally not landed

At this point there is a straightforward repo-side mitigation available:

- replace the current health-check discovery path that shells out to
  `bpftool -j -p prog show` with a raw-syscall-based discovery path that only
  needs stable prog ids and, if necessary, stable `map_ids[]`

This would likely avoid the current live crash in the short term, but I am
**not** landing that workaround in the repo now for two reasons:

- the user explicitly asked to treat it as a mitigation note, not as the fix
- the current evidence says the real kernel-side bug is still somewhere deeper
  in the live metadata expansion path, and masking it would make root-cause
  confirmation harder

So the workaround is recorded here as a fallback mitigation option only. The
active investigation continues to optimize for a narrower and more stable
kernel-side reproducer instead of routing around the bug in repo code.

### Further narrowing after the `show_prog_metadata()` split

I then continued slicing the full `bpftool -j -p prog show` path into smaller
raw-syscall probes that each emulate one later stage of `bpftool`'s metadata
expansion.

#### Raw prog + `map_info` loop is stable

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-mapinfo-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- all 13 live programs remained stable
- each live program consistently exposed exactly one `.rodata` metadata-map
  candidate
- VM exited normally with `COMMAND_EXIT_CODE="0"`

#### Raw prog + `.rodata` map lookup loop is stable

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-rodata-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- every live program consistently resolved the same metadata map
  (`map_id=36`, value size `12192`)
- VM exited normally with `COMMAND_EXIT_CODE="0"`

#### Raw prog + BTF FD/info/blob loop is stable

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-btf-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- every live program consistently resolved the same metadata map BTF
  (`map_id=36`, `btf_id=47`, blob size `79341`)
- VM exited normally with `COMMAND_EXIT_CODE="0"`

#### Raw full `struct bpf_prog_info` loop is stable

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-fullinfo-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- the first `show_prog(fd)`-style full `struct bpf_prog_info` query remained
  stable across all 13 live programs
- representative returned fields such as `nr_map_ids`, `btf_id`,
  `nr_func_info`, `nr_line_info`, `nr_jited_ksyms`, `nr_jited_func_lens`, and
  `nr_prog_tags` were stable across iterations
- VM exited normally with `COMMAND_EXIT_CODE="0"`

#### Raw `get_prog_full_name()` path is stable

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u docs/tmp/20260325/debug_scx_sequence.py \
    --mode manual-raw-prog-fullname-loop --find-iterations 10 --load-timeout 20'
```

Observed result:

- `10/10` iterations completed successfully
- all six 15-byte program names that force `bpftool` to call
  `get_prog_full_name()` remained stable:
  - `rusty_select_cp`
  - `rusty_quiescent`
  - `rusty_set_weigh`
  - `rusty_set_cpuma`
  - `rusty_init_task`
  - `rusty_exit_task`
- the nested `nr_func_info=1` prog-info query plus program-BTF load path also
  remained stable
- VM exited normally with `COMMAND_EXIT_CODE="0"`

These additional probes materially tighten the remaining crash window:

- the crash is not reproduced by:
  - minimal prog-info
  - full prog-info
  - map-ids fetch
  - per-map map-info fetch
  - `.rodata` lookup
  - map-BTF FD/info/blob fetch
  - `get_prog_full_name()`'s nested `func_info[0]` + program-BTF path
- therefore the remaining gap between "stable raw probes" and "crashing
  `bpftool -j -p prog show`" is now much smaller
- the leading suspects are now the residual `bpftool`-specific enumeration and
  dump layers that were not yet mirrored by the raw probe harness, especially:
  - object-ref/pid enumeration (`build_obj_refs_table()` / `emit_obj_refs_*()`)
  - any remaining BTF pretty-print / dumper path (`btf_dumper_type()`) that is
    specific to the final metadata rendering stage

### Host reboot note after the raw-probe sequence

After the successful raw-probe sequence above, the host later rebooted again.
Current evidence does **not** let me attribute that reboot to one of the new
raw probes directly:

- `manual-raw-prog-mapinfo-loop` completed successfully at
  `2026-03-25 17:07:57 PDT`
- `manual-raw-prog-rodata-loop` completed successfully at
  `2026-03-25 17:08:20 PDT`
- `manual-raw-prog-btf-loop` completed successfully at
  `2026-03-25 17:10:24 PDT`
- the previous host boot ended later, at `2026-03-25 17:12:40 PDT`

So this reboot happened after the last successful raw probe, but there is no
new direct `qemu-system-x86_64` segfault record or kernel panic/oops/OOM log
that pins the reboot to one of these narrower reproducer runs.

## 2026-03-25 Follow-up fixes for the later REJIT review findings

After a later code-review pass identified two more real REJIT-side bugs, I
re-checked both against the current tree and then fixed them in the
investigation branch.

## 2026-03-25 `bpftool prog show` A/B split: `build_obj_refs_table()` is required

I then switched from the host-installed `/usr/local/sbin/bpftool` binary to a
repo-local debug build from `vendor/bpftool/src`, using the existing
`tests/negative/scx_prog_show_race.c` reproducer with `BPFTOOL_BIN=...`.
That debug build added temporary environment toggles to selectively disable:

- `show_prog()` map-id expansion
- `show_prog_metadata()`
- `build_obj_refs_table()` / PID-reference enumeration
- the post-refs `prog show` enumeration itself

This was done to answer one narrow question: which `bpftool prog show` stage is
still necessary for the live crash after all earlier raw-probe work had already
shown that plain `BPF_OBJ_GET_INFO_BY_FD`, `map_ids[]`, `map_info`,
`.rodata` lookup, full prog-info, and program-name/BTF lookup were stable on
their own.

### Control: debug `bpftool` binary is actually used

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
    export BPFTOOL_BIN="/home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool" && \
    ./tests/negative/build/scx_prog_show_race \
      "/home/yunwei37/workspace/bpf-benchmark" \
      --skip-probe --mode bpftool-loop --iterations 0 --load-timeout 20'
```

Observed result:

- the guest printed
  `MARK paths ... /home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool`
- the control path remained stable and exited `0`

### Baseline with debug `bpftool`: still reproduces

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
    export BPFTOOL_BIN="/home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool" && \
    ./tests/negative/build/scx_prog_show_race \
      "/home/yunwei37/workspace/bpf-benchmark" \
      --mode bpftool-loop --iterations 200 --load-timeout 20'
```

Observed result:

- the reproducer still crashed
- this run failed very early:
  - `MARK bpftool 0 rc 0`
  - `MARK bpftool 1 rc 0`
  - `MARK bpftool 2 rc 0`
  - then `COMMAND_EXIT_CODE="255"`

So the debug user-space binary did not perturb the bug away.

### `SKIP_REFS=1`: 200/200 stable

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
    export BPFTOOL_BIN="/home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool" && \
    export BPFTOOL_PROG_SHOW_SKIP_REFS=1 && \
    ./tests/negative/build/scx_prog_show_race \
      "/home/yunwei37/workspace/bpf-benchmark" \
      --mode bpftool-loop --iterations 200 --load-timeout 20'
```

Observed result:

- `MARK bpftool 0 rc 0` through `MARK bpftool 199 rc 0`
- `MARK completed bpftool-loop`
- VM exited normally with `COMMAND_EXIT_CODE="0"`

This is the strongest result in the whole investigation so far:

- disabling only `build_obj_refs_table()` / `emit_obj_refs_*()` removes the
  crash entirely
- therefore object-ref / PID-reference enumeration is a necessary ingredient of
  the reproducer

### `SKIP_METADATA=1`: still crashes

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
    export BPFTOOL_BIN="/home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool" && \
    export BPFTOOL_PROG_SHOW_SKIP_METADATA=1 && \
    ./tests/negative/build/scx_prog_show_race \
      "/home/yunwei37/workspace/bpf-benchmark" \
      --mode bpftool-loop --iterations 200 --load-timeout 20'
```

Observed result:

- the reproducer still crashed
- this run survived longer than the full baseline, but still died at:
  - `MARK bpftool 0 rc 0`
  - ...
  - `MARK bpftool 8 rc 0`
  - then `COMMAND_EXIT_CODE="255"`

So `show_prog_metadata()` is **not** a necessary precondition. It may still
affect timing, but removing metadata rendering does not remove the bug.

### `SKIP_ENUM=1` + `SKIP_METADATA=1` + `SKIP_MAPS=1`: refs-only still crashes

I then added one more temporary `bpftool` toggle to return immediately after
`build_obj_refs_table()` and before any `show_prog()` enumeration. That lets
the reproducer repeatedly run the refs path alone.

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
    export BPFTOOL_BIN="/home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool" && \
    export BPFTOOL_PROG_SHOW_SKIP_ENUM=1 && \
    export BPFTOOL_PROG_SHOW_SKIP_METADATA=1 && \
    export BPFTOOL_PROG_SHOW_SKIP_MAPS=1 && \
    ./tests/negative/build/scx_prog_show_race \
      "/home/yunwei37/workspace/bpf-benchmark" \
      --mode bpftool-loop --iterations 200 --load-timeout 20'
```

Observed result:

- the reproducer still crashed
- this refs-only run died at:
  - `MARK bpftool 0 rc 0`
  - ...
  - `MARK bpftool 11 rc 0`
  - then `COMMAND_EXIT_CODE="255"`

This narrows the live crash much further than anything earlier:

- the crash does **not** require:
  - `show_prog()` enumeration
  - `show_prog_metadata()`
  - `show_prog_maps()`
- it **does** require repeated `build_obj_refs_table()`
- therefore the remaining primary suspect is now the PID-reference path itself:
  - `vendor/bpftool/src/pids.c:build_obj_refs_table()`
  - `tools/bpf/bpftool/skeleton/pid_iter.bpf.c`
  - the kernel `iter/task_file` execution path in `kernel/bpf/task_iter.c`

At this point the previous “live prog-info / struct_ops metadata race” label is
too broad. The best current statement is narrower:

- the reproducible live crash is dominated by repeated `bpftool` PID-reference
  enumeration (`build_obj_refs_table()`), not by the later metadata dump path

Important context:

- these two bugs are real and worth fixing
- but they are **not** the leading explanation for the current live
  `bpftool -j -p prog show` / QEMU crash, because the live crash reproducer does
  not require `BPF_PROG_REJIT`
- the raw-probe narrowing above still points to a different residual gap
  between the stable raw probes and the full `bpftool prog show` path

### Fix 1: REJIT rollback now restores non-swappable metadata

The review finding was correct: `bpf_prog_rejit_swap()` still had a set of
one-way metadata copies that made rollback non-reversible for some fields.

I fixed the current tree in `vendor/linux-framework/kernel/bpf/syscall.c` by:

- making the scalar metadata exchanges reversible instead of one-way for the
  relevant `struct bpf_prog` / `struct bpf_prog_aux` fields
- swapping the digest content instead of doing a one-way overwrite
- adding an explicit rollback snapshot for the non-pointer/non-swappable parts
  that cannot be made reversible with a simple `swap()`
  - saved old `insnsi`
  - saved old `len`
  - saved old `load_time`
- restoring that snapshot after the swap-back path in
  `bpf_prog_rejit_rollback()`
- also making the ambiguous `__bpf_prog_put_noref(tmp, tmp->aux->real_func_cnt)`
  sites explicit with `tmp->aux->real_func_cnt > 0`

This means rollback no longer leaves the old JIT image paired with the new
rewritten instruction stream or the new metadata length.

### Fix 2: struct_ops refresh now patches all matching call sites

The second review finding was also correct in substance: the refresh logic was
still assuming a single matching direct-call site per trampoline image.

I fixed the current tree in `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
by:

- replacing the single-hit `find_call_site()` scan with an iterator-style
  `find_next_call_site()` helper
- collecting **all** matching direct-call sites to `old_bpf_func` across the
  relevant struct_ops trampoline images
- patching every collected call site
- rolling back every already-patched call site if a later `text_poke` fails

This removes the remaining "first hit only" assumption from the refresh path.

### Validation for these follow-up fixes

Host-side object build:

```bash
make -C vendor/linux-framework -j4 kernel/bpf/syscall.o kernel/bpf/bpf_struct_ops.o
```

Result:

- build passed

VM-side regression sweep with the existing audit suite:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  ./tests/unittest/build/rejit_audit_tests ./tests/unittest/build/progs'
```

Observed result:

- `9 PASS, 0 FAIL, 0 SKIP`
- notable relevant coverage that still passed:
  - `T2_M4_xlated_prog_len`
  - `T3_M4_xlated_content`
  - `T8_M4_multi_length_transitions`
  - `T9_H3_struct_ops_multi_slot`

### What is still missing test-wise

I do **not** yet have a deterministic `make vm-test` reproducer that isolates
either of these two new bugs on demand:

- the rollback bug needs a controllable refresh failure after successful REJIT
  so that the kernel actually enters the swap-back path
- the multi-call-site struct_ops bug needs a trampoline image that reliably
  contains multiple direct calls to the same target in one refreshable image

So these two are now patched and compile/VM-smoke-validated, but they are not
yet covered by a dedicated, minimal, deterministic regression testcase in the
same way that the older `M4/H3` audit cases are.

## 2026-03-25 Repo-owned crash-path reproducer for the live `scx` / `bpftool` path

I moved the previously ad-hoc crash path out of `docs/tmp` and into a repo-owned
script:

- `tests/integration/scx_prog_show_race.py`

This reproducer intentionally follows the exact mainline path identified by the
later crash-path reports instead of any REJIT-specific path:

1. `probe_bpftool_register()` on `scx_rusty_main.bpf.o`
2. start a second `scx_rusty --stats 1`
3. once `read_scx_state() == "enabled"`, repeatedly execute
   `bpftool -j -p prog show`

The command I ran was:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u tests/integration/scx_prog_show_race.py \
    --mode bpftool-loop --iterations 20 --load-timeout 20'
```

Observed result:

- `vm-shell` exited with status `255`
- the guest-side script did not make it far enough to emit any `MARK before_probe`
  / `after_wait` lines back through the wrapper
- host-side journal shows a fresh `qemu-system-x86_64` userspace crash at the
  same known code offset:

```text
Mar 25 17:47:48.942900 lab kernel: qemu-system-x86[260944]: segfault at 890 ip ... in qemu-system-x86_64[8d8f21,...]
```

This is important because it means:

- the crash is now reproduced by a **repo-owned** path, not only by the
  earlier `docs/tmp/20260325/debug_scx_sequence.py` helper
- the reproducer does **not** depend on daemon code or on the REJIT replay path
- the current mainline root-cause track remains:
  `probe struct_ops register + second scx_rusty load + repeated bpftool prog show`

### Control: the same repo-owned script is stable when the raw probe is skipped

I also ran the exact same script with the probe removed and with zero
`bpftool prog show` iterations:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  python3 -u tests/integration/scx_prog_show_race.py \
    --skip-probe --mode bpftool-loop --iterations 0 --load-timeout 20'
```

Observed result:

- command exited `0`
- the script printed:
  - `MARK skip_probe`
  - `MARK after_wait healthy True state enabled pid 195`
  - `MARK completed bpftool-loop`
- `scx_rusty` started and unregistered cleanly
- there was no new host-side `qemu-system-x86_64` segfault during this control

So the new repo-owned path already reproduces the same high-level split that the
earlier ad-hoc investigation established:

- `skip probe + second scx_rusty load` is stable
- `probe + second scx_rusty load + repeated bpftool prog show` still triggers
  the known `qemu-system-x86_64` crash signature

## 2026-03-25 C testcase integrated into existing `vm-negative-test` / `vm-shell`

I then moved the crash-path reproducer into a repo-owned C testcase under the
existing negative-test framework:

- `tests/negative/scx_prog_show_race.c`

This binary now builds together with the other negative tests via:

```bash
make -C tests/negative clean all
```

and it is exercised through the existing root-level VM entrypoints instead of a
one-off script.

### Control: existing `vm-negative-test` entrypoint is stable with `--skip-probe`

I ran:

```bash
make vm-negative-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_NEGATIVE_TIMEOUT=1800 FUZZ_ROUNDS=1 \
  SCX_PROG_SHOW_RACE_SKIP_PROBE=1 \
  SCX_PROG_SHOW_RACE_ITERATIONS=0
```

Observed result:

- the suite exited `0`
- the new testcase printed:
  - `MARK skip_probe 1`
  - `MARK after_wait healthy 1 state enabled pid 196`
  - `MARK completed bpftool-loop`
- this matches the earlier Python control exactly:
  - second `scx_rusty` load is healthy
  - skipping the raw probe keeps the path stable

### Existing `vm-negative-test` entrypoint: `bpftool-loop` at 20 iterations is now stable

I then ran the same root entrypoint with the real trigger chain but only 20
`bpftool prog show` iterations:

```bash
make vm-negative-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_NEGATIVE_TIMEOUT=1800 FUZZ_ROUNDS=1 \
  SCX_PROG_SHOW_RACE_SKIP_PROBE=0 \
  SCX_PROG_SHOW_RACE_ITERATIONS=20 \
  SCX_PROG_SHOW_RACE_MODE=bpftool-loop
```

Observed result:

- the suite exited `0`
- the testcase printed `MARK bpftool 0 rc 0` through `MARK bpftool 19 rc 0`
- `scx_rusty` stayed enabled and then unregistered cleanly

This means the crash remains timing-sensitive on the current tree: the old
20-iteration crash is no longer enough once the reproducer is run through the
current integrated path.

### Existing `vm-negative-test` entrypoint: `bpftool-loop` at 200 iterations reproduces again

To push the same integrated path harder, I ran:

```bash
make vm-negative-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_NEGATIVE_TIMEOUT=1800 FUZZ_ROUNDS=1 \
  SCX_PROG_SHOW_RACE_SKIP_PROBE=0 \
  SCX_PROG_SHOW_RACE_ITERATIONS=200 \
  SCX_PROG_SHOW_RACE_MODE=bpftool-loop
```

Observed result:

- the suite reached:
  - `MARK before_probe 1`
  - `MARK after_probe 0`
  - `MARK after_wait healthy 1 state enabled pid 199`
  - `MARK bpftool 0 rc 0` through `MARK bpftool 27 rc 0`
- after `MARK bpftool 27 rc 0`, the wrapper stopped abruptly with:

```text
Script done on 2026-03-25 18:09:04-07:00 [COMMAND_EXIT_CODE="255"]
```

- `make vm-negative-test` therefore failed with `Error 255`
- unlike the earlier `17:47:48` repro, this specific run did **not** leave a
  fresh host-side `journalctl` `qemu-system-x86_64 segfault` line or kernel log

So the repo-owned C testcase is now strong enough to reproduce the failure on
the existing root-level VM entrypoint, but the host-side crash signature is not
logged every time.

### `owner-id-loop`: 1 iteration per owner is stable

I then switched the same integrated testcase to owner-scoped queries:

```bash
make vm-negative-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_NEGATIVE_TIMEOUT=1800 FUZZ_ROUNDS=1 \
  SCX_PROG_SHOW_RACE_SKIP_PROBE=0 \
  SCX_PROG_SHOW_RACE_ITERATIONS=1 \
  SCX_PROG_SHOW_RACE_MODE=owner-id-loop
```

Observed result:

- the suite exited `0`
- the testcase collected:

```text
MARK owner_ids 52 54 55 56 57 58 59 60 61 62 63 64 65
```

- and completed:
  - `MARK owner_bpftool 52 0 rc 0`
  - ...
  - `MARK owner_bpftool 65 0 rc 0`
  - `MARK completed owner-id-loop`

This shows that one query per owner prog is not enough to reproduce.

### `owner-id-loop`: 3 iterations per owner reproduces and narrows the failing window

I then increased the per-owner repeat count:

```bash
make vm-negative-test TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G \
  VM_NEGATIVE_TIMEOUT=1800 FUZZ_ROUNDS=1 \
  SCX_PROG_SHOW_RACE_SKIP_PROBE=0 \
  SCX_PROG_SHOW_RACE_ITERATIONS=3 \
  SCX_PROG_SHOW_RACE_MODE=owner-id-loop
```

Observed result:

- the testcase again reached:
  - `MARK before_probe 1`
  - `MARK after_probe 0`
  - `MARK after_wait healthy 1 state enabled pid 198`
- it successfully completed:
  - `52 x 3`
  - `54 x 3`
  - `55 x 3`
  - `56 x 3`
  - `57 x 3`
- the last emitted line before failure was:

```text
MARK owner_bpftool 58 0 rc 0
```

- immediately after that, the wrapper again ended with:

```text
Script done on 2026-03-25 18:10:44-07:00 [COMMAND_EXIT_CODE="255"]
```

and again there was no fresh host-side `journalctl` crash signature.

This is still very useful: it shrinks the failing window from “global repeated
`bpftool prog show`” to “owner-id query sequence after the first fifteen
successful owner-specific queries, when entering the sixth owner in that run”.

### The failure is not reproduced by hammering a single selected owner in isolation

To test whether the issue is tied to one owner prog by itself, I added two tiny
debug-only filters to `tests/negative/scx_prog_show_race.c`:

- `--only-id N`
- `--owner-ordinal N`

Then I used the existing `vm-shell` root entrypoint to query only one selected
owner from the current run:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  ./tests/negative/build/scx_prog_show_race \
    "/home/yunwei37/workspace/bpf-benchmark" \
    --mode owner-id-loop --iterations 10 --owner-ordinal 5 --load-timeout 20'
```

Observed result:

- command exited `0`
- the testcase resolved the selected owner to a single current-run prog id:

```text
MARK owner_ids 34
```

- and completed:
  - `MARK owner_bpftool 34 0 rc 0`
  - ...
  - `MARK owner_bpftool 34 9 rc 0`

So the current evidence points away from “one specific owner prog id always
crashes when repeated in isolation” and toward a broader cumulative sequence /
orchestration effect across multiple owner queries in one live session.

### Strongest current repo-owned reproducer: pure `vm-shell` + C harness, no extra prelude

After additional narrowing, the cleanest reproducer on the current tree is now:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  ./tests/negative/build/scx_prog_show_race \
    "/home/yunwei37/workspace/bpf-benchmark" \
    --mode bpftool-loop --iterations 500 --load-timeout 20'
```

Observed result:

- no daemon path is involved
- no earlier REJIT testcase prelude is needed
- the testcase reached:
  - `MARK before_probe 1`
  - `MARK after_probe 0`
  - `MARK after_wait healthy 1 state enabled pid 196`
  - `MARK bpftool 0 rc 0` through `MARK bpftool 72 rc 0`
- immediately after `MARK bpftool 72 rc 0`, the wrapper ended with:

```text
Script done on 2026-03-25 18:19:56-07:00 [COMMAND_EXIT_CODE="255"]
```

- and this time the host-side journal again recorded the known QEMU crash:

```text
Mar 25 18:19:54 lab kernel: qemu-system-x86[3787603]: segfault at 10 ip ... in qemu-system-x86_64[8d8f21,...]
```

This is currently the best repo-owned reproducer because it is:

- minimal: only the live `scx` / `bpftool prog show` path
- independent of daemon serve / static verify / batch infrastructure
- independent of any earlier REJIT testcase prelude
- source-controlled and invokable through an existing root Makefile entrypoint

So the current live-crash track remains:

1. `bpftool struct_ops register scx_rusty_main.bpf.o`
2. second `scx_rusty --stats 1`
3. repeated `bpftool -j -p prog show`
4. host `qemu-system-x86_64` eventually segfaults at the same `8d8f21` offset

This is separate from the later-discovered daemon/static-verify parallel REJIT
`bpf_ksym_del()` / kallsyms panic path: that other bug requires daemon serve +
parallel `BPF_PROG_REJIT`, while the reproducer above does not require REJIT at
all.

### `bpftool` refs path A/B: crash now narrows to `pid_iter_bpf__load()`

To isolate the remaining `bpftool prog show` crash path further, I built and
used a repo-local debug `bpftool` binary from `vendor/bpftool/src` and pointed
the existing C reproducer at it via `BPFTOOL_BIN=.../runner/build/vendor/bpftool/bpftool`.

The debug `bpftool` added temporary env-gated skips in:

- `vendor/bpftool/src/prog.c`
- `vendor/bpftool/src/pids.c`

The reproducer entrypoint stayed the same:

```bash
make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=2 VM_MEM=8G VM_TEST_TIMEOUT=1800 \
  VM_COMMAND='cd "/home/yunwei37/workspace/bpf-benchmark" && \
  BPFTOOL_BIN="/home/yunwei37/workspace/bpf-benchmark/runner/build/vendor/bpftool/bpftool" \
  ./tests/negative/build/scx_prog_show_race \
    "/home/yunwei37/workspace/bpf-benchmark" \
    --mode bpftool-loop --iterations 200 --load-timeout 20'
```

Results:

- baseline with debug `bpftool`: still crashes very early
  - completed `MARK bpftool 0 rc 0`
  - completed `MARK bpftool 1 rc 0`
  - completed `MARK bpftool 2 rc 0`
  - then wrapper ended with `COMMAND_EXIT_CODE="255"`
- `BPFTOOL_PROG_SHOW_SKIP_REFS=1`: stable `200/200`
- `BPFTOOL_PROG_SHOW_SKIP_METADATA=1`: still crashes
- `BPFTOOL_PROG_SHOW_SKIP_ENUM=1 BPFTOOL_PROG_SHOW_SKIP_METADATA=1 BPFTOOL_PROG_SHOW_SKIP_MAPS=1`
  - this leaves only `build_obj_refs_table()`
  - still crashes

That already narrowed the live crash from generic `prog show` to the object-ref
collection path.

Then I split `build_obj_refs_table()` itself in `vendor/bpftool/src/pids.c`:

- `BPFTOOL_PIDS_FORCE_UNKNOWN=1`
  - makes the iterator program return early without object-type-specific
    dereference
  - still crashes
- `BPFTOOL_PIDS_SKIP_ITER_READ=1`
  - creates the iterator FD but never reads seq output
  - still crashes
- `BPFTOOL_PIDS_SKIP_ATTACH=1`
  - returns after `pid_iter_bpf__load(skel)` and before
    `pid_iter_bpf__attach(skel)`
  - still crashes
- `BPFTOOL_PIDS_SKIP_LOAD=1`
  - returns after `pid_iter_bpf__open()` / rodata setup and before
    `pid_iter_bpf__load(skel)`
  - stable `200/200`

This is the strongest current narrowing result:

- `attach`, `bpf_iter_create`, and iter `read()` are not required
- object-type-specific dereference inside the iterator program is not required
- the necessary condition is repeated `pid_iter_bpf__load()` itself

So the live-crash track is no longer best described as a generic
`bpf_prog_get_info_by_fd()` / metadata query bug. On the current tree, the
dominant necessary condition is repeated loading of bpftool's PID-iterator BPF
program under the live state created by:

1. `bpftool struct_ops register scx_rusty_main.bpf.o`
2. second `scx_rusty --stats 1`
3. repeated `pid_iter_bpf__load()` through the refs path of `bpftool prog show`

### 2026-03-25 18:30-18:50 PDT: `bpf_jit_kallsyms=0` experiment did not stop the host-side QEMU crash

After the narrowing above, I ran a guest-side A/B using the same repo-owned
reproducer path, but with:

```bash
sysctl -w net.core.bpf_jit_kallsyms=0
```

before invoking the `refs-only` / `skip-attach` case.

Observed host-side result from `journalctl -b -1`:

- `2026-03-25 18:30:18 PDT`: `qemu-system-x86_64` segfault
- `2026-03-25 18:31:52 PDT`: `qemu-system-x86_64` segfault
- `2026-03-25 18:34:37 PDT`: `qemu-system-x86_64` segfault
- `2026-03-25 18:39:49 PDT`: `qemu-system-x86_64` segfault
- `2026-03-25 18:40:21 PDT`: `qemu-system-x86_64` segfault
- `2026-03-25 18:41:58 PDT`: `qemu-system-x86_64` segfault
- host rebooted at `2026-03-25 18:50 PDT`

All of these crashes still hit the same host QEMU text offset:

```text
qemu-system-x86_64[8d8f21,...]
```

Important interpretation detail:

- this experiment did **not** show that the issue is unrelated to BPF kallsyms
- on this kernel, `/proc/sys/net/core/bpf_jit_kallsyms` gates symbol exposure
  via `bpf_get_kallsym()`, but `bpf_prog_kallsyms_add()` /
  `bpf_prog_kallsyms_del_all()` still remain in the ordinary load/unload path

So the only safe conclusion from this run is narrower:

- setting `net.core.bpf_jit_kallsyms=0` did **not** make the reproducer stable
- it did **not** change the host-side crash signature
- it therefore does **not** provide a workaround, but it also does **not**
  exclude internal `bpf_prog_kallsyms_add/del` lifecycle bugs

## 2026-03-25 QEMU 升级验证：Bug 2 (TCG crash) 根因确认为 QEMU 8.2.2 bug

### KASAN 内核验证（KVM 模式）

在升级 QEMU 之前，先用 KASAN 内核在 KVM 模式下全面测试了内核代码安全性：

| 测试 | 结果 | KASAN 报错 |
|------|------|-----------|
| REJIT regression (6 tests, 160 subprog REJITs) | 6/6 PASS | 无 |
| vm-static-test (191 objects, 616 programs) | 全通过 | 无 |
| vm-negative-test (fuzz 1000 rounds + adversarial) | 全通过 | 无 |
| scx_prog_show_race (500 iterations) | 全通过 | 无 |
| unit tests (audit/swap/safety/verifier/tail_call) | 全通过 | 无 |

结论：KASAN 未检测到任何 use-after-free、out-of-bounds 或 slab corruption。内核 BPF 代码无内存安全问题。

注意：KASAN 内核在 TCG 模式下连 boot 都无法完成（QEMU 8.2.2 在处理 KASAN shadow memory 地址空间时触发同一个 `tlb_set_dirty` crash），进一步佐证问题在 QEMU TCG 侧。

### QEMU 升级

- 从 https://download.qemu.org/qemu-9.2.2.tar.xz 下载源码
- 配置：`--prefix=/usr/local --datadir=/usr/share --target-list=x86_64-softmmu,aarch64-softmmu`
- 编译安装到 `/usr/local/bin/`（不覆盖系统 apt 包）
- 系统 apt 的 8.2.2 保留在 `/usr/bin/`，`/usr/local/bin` 在 PATH 中优先

### Bug 2 验证：QEMU 9.2.2 + TCG

配置：
- QEMU 9.2.2（`/usr/local/bin/qemu-system-x86_64`）
- TCG 模式（禁用硬件加速）
- 非 KASAN 内核（#3, 17MB）
- VM_CPUS=1, VM_MEM=8G
- reproducer: `tests/negative/build/scx_prog_show_race --mode bpftool-loop --iterations 200`

结果：
- **200/200 轮全部通过**
- host journal **零 QEMU segfault**
- scx_rusty 正常启动和退出

### 对比

| 配置 | QEMU 8.2.2 | QEMU 9.2.2 |
|------|-----------|-----------|
| TCG + scx reproducer | ~8 轮 crash (`tlb_set_dirty` at `0x8d8f21`) | **200 轮全过** |
| KVM + scx reproducer | 通过 | 通过 |
| TCG + KASAN 内核 | 连 boot 都 crash | 未测试 |

### 根因确认

Bug 2 (TCG crash) 的根因是 **QEMU 8.2.2 的 TCG softmmu `tlb_set_dirty` 实现 bug**，在处理 guest 内核快速连续的 `text_poke_copy()`（fixmap PTE 修改 + INVLPG）时触发。QEMU 9.2.2 修复了此问题。

此问题与内核 BPF/REJIT 代码无关。内核代码的行为是合法的（通过 KASAN 验证），但触发了 QEMU 8.2.2 TCG 的已知限制。

### 宿主频繁重启分析

调查期间宿主多次无明确原因重启。分析发现：
- 每次 boot 都有 `mce: [Hardware Error]: Machine check events logged`
- 有 CPU 过热降频记录（`Package temperature is above threshold`，event count 65+）
- 无 kernel panic/oops 日志
- 原因为 CPU 过热（Intel Core Ultra 9 285K 在 `-j24` 全核编译 + QEMU TCG 高负载下过热）
