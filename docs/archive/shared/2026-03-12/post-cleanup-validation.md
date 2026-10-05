# Post-cleanup Validation

Date: 2026-03-13

Scope:

- Validate the live workspace after the recent kernel-side changes called out in:
  - `#149` canonical-site validation hardening
  - `#150` cleanup bundle in `docs/tmp/kernel-engineering-cleanup.md`
  - `#152` safety fixes in `docs/tmp/kernel-safety-fixes.md`
  - `#153` zero-site identity short-circuit in `jit_directives.c`

Workspace note:

- Validation was run against the current dirty tree, including a modified `vendor/linux-framework/` worktree.
- No source changes were required to complete this validation run.

## Summary

| Step | Result | Notes |
| --- | --- | --- |
| `make -C vendor/linux-framework -j$(nproc) bzImage` | PASS | Built `arch/x86/boot/bzImage` successfully; no compile fixes needed |
| VM boot smoke (`uname -r`) | PASS | Guest booted successfully with `7.0.0-rc2-g05a1845490ed-dirty` |
| `make -C tests/kernel` | PASS | `Nothing to be done for 'all'` |
| `tests/kernel/build/test_recompile` | PASS with expected known failure | `19 passed, 1 failed`; only `Wide Site-Only JIT Diff` failed |
| Micro smoke | PASS | Stock and recompile paths both executed successfully; `load_byte_recompose` preserved the same result across stock/recompile |

`vng` printed the usual warning about `vendor/linux-framework/modules.order` not existing because modules are disabled in this kernel build. The guest still booted and all requested VM-side checks completed successfully.

## 1. Kernel Build

Command:

```bash
make -C vendor/linux-framework -j$(nproc) bzImage
```

Result:

- Success
- Final build message: `Kernel: arch/x86/boot/bzImage is ready  (#35)`
- Built image: `vendor/linux-framework/arch/x86/boot/bzImage`

## 2. VM Boot Smoke

Command:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage -- uname -r
```

Result:

- Success
- Guest kernel release: `7.0.0-rc2-g05a1845490ed-dirty`

## 3. Kernel Self-tests

Build command:

```bash
make -C tests/kernel
```

VM command:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --rwdir tests/kernel \
  -- bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && sudo tests/kernel/build/test_recompile'
```

Observed result:

- Exit status: non-zero, due to the expected single known failure
- Summary: `1 test(s) failed, 19 passed.`
- This matches the expected post-cleanup state described for this run

Passing checks included:

- `Load Simple Program And Verify Tag`
- `Zero-Rule Policy Blob No-Op`
- `Single Valid Wide Rule Recompile`
- `Wide Result Preserved After Recompile`
- `Wide Zero-Applied JIT Identity`
- `Recompile Count Increments`
- all negative validation cases (`Wrong Magic`, `Wrong Prog Tag`, `Wrong Insn Count`, `Wrong Arch Id`, `Non-Sealed Memfd`, `Truncated Header`, `Site Start Out Of Bounds`, `Zero-Length Blob`)
- `Diamond CMOV Recompile Preserves Result`
- `Rotate Recompile Preserves Result`
- `Repeated Recompile Reaches Count Two`
- `Concurrent Recompile Returns EBUSY`
- `Recompile After Attach Works`

Expected failing check:

- `Wide Site-Only JIT Diff`
  - Failure text:
    `non-site bytes changed outside site image 149->137 pre[0x33,0x45) post[0x33,0x39) [0x91]=3f -> [0x85]=67 [0x92]=d0 -> [0x86]=cf`

## 4. Micro Smoke

Build command:

```bash
make -C micro micro_exec programs 2>/dev/null
```

Result:

- Success
- `micro_exec` rebuilt successfully
- `micro/programs` were already up to date

### CLI compatibility note

The exact micro commands in the task are stale relative to the current `micro_exec` CLI:

- `--bpf-obj` is now `--program`
- `--iterations` is not a supported flag in the current CLI
- `--scanner-path` is not a supported flag in the current CLI
- staged XDP micro benchmarks now need explicit `--io-mode staged`, `--input-size`, and `--memory`

I therefore ran the current equivalent commands below to validate the same stock and recompile paths.

### 4.1 Stock smoke: `simple.bpf.o`

Command used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --rwdir micro \
  -- bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/simple.bpf.o --io-mode staged --repeat 100 --input-size 64 --memory micro/generated-inputs/simple.mem'
```

Result:

- Success
- `result=12345678`
- `retval=2`
- `exec_ns=21`
- `jited_prog_len=117`
- `recompile.requested=false`

### 4.2 Stock smoke: `load_byte_recompose.bpf.o`

Command used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --rwdir micro \
  -- bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/load_byte_recompose.bpf.o --io-mode staged --repeat 100 --input-size 1032 --memory micro/generated-inputs/load_byte_recompose.mem'
```

Result:

- Success
- `result=1253018829653002637`
- `retval=2`
- `exec_ns=290`
- `jited_prog_len=365`
- `recompile.requested=false`

### 4.3 Recompile smoke: `load_byte_recompose.bpf.o --recompile-all`

Command used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --rwdir micro \
  -- bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/load_byte_recompose.bpf.o --io-mode staged --repeat 100 --input-size 1032 --memory micro/generated-inputs/load_byte_recompose.mem --recompile-all'
```

Result:

- Success
- Scanner summary:
  - `recompile-wide: found 1 wide_load sites in xlated program (83 insns)`
  - all other enabled families reported `no ... sites found`
- JSON summary:
  - `result=1253018829653002637`
  - `retval=2`
  - `exec_ns=298`
  - `jited_prog_len=353`
  - `directive_scan.total_sites=1`
  - `recompile.requested=true`
  - `recompile.mode=auto-scan-v5`
  - `recompile.policy_generated=true`
  - `recompile.syscall_attempted=true`
  - `recompile.applied=true`
  - `recompile.wide_sites=1`

### 4.4 Stock vs recompile consistency

- `load_byte_recompose` stock result: `1253018829653002637`
- `load_byte_recompose` recompile result: `1253018829653002637`
- Result match: yes
- Recompile path was actually exercised: yes (`recompile.applied=true`, `wide_sites=1`)

## Final Assessment

- Kernel rebuild succeeded without additional fixes.
- The rebuilt kernel boots successfully in the VM.
- Kernel self-tests are in the expected post-cleanup state: `19 pass, 1 expected fail` (`Wide Site-Only JIT Diff`).
- The kernel micro runner still works on both stock and recompile paths.
- Recompile remains functionally correct on the `load_byte_recompose` smoke case, with identical observable results before and after re-JIT.
