# TCG Minimal Reproduction And E2E Investigation

Date: 2026-03-25

## Scope

This note records the post-reboot investigation after host `panic_on_oops` was disabled and all follow-up reproductions were switched to `QEMU TCG` (`local-x86-vng-tcg`, `--disable-kvm`).

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
- Current TCG target uses `--disable-kvm`

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
- `vendor/linux-framework/include/linux/filter.h`
  - switch `__bpf_prog_run()` to `smp_load_acquire(&prog->bpf_func)` so the
    runtime execution path pairs with the release-store publish above
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
  - make `bpf_struct_ops_refresh_prog()` tolerate already-updated call sites
  - add local rollback of already-patched call sites if a later `text_poke`
    fails, instead of leaving a partial mixed old/new trampoline image behind

One candidate fix was reviewed and then intentionally dropped from the current
dirty tree:

- `bpf_prog_get_info_by_fd()` is **not** serialized under `prog->aux->rejit_mutex`
  in the current tree.
  - Reason: the live crash reproducer that remains under investigation does not
    require `BPF_PROG_REJIT`; it is a `probe struct_ops register` + second
    `scx_rusty --stats 1` loader + repeated `bpftool prog show` path.
  - So serializing `prog show` against in-place REJIT was judged too speculative
    to keep as a real fix for this bug.

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
