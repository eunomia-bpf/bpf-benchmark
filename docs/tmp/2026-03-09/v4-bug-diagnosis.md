# v4 JIT Recompile CMOV Bug Diagnosis

## Symptom

`--recompile-cmov` on `log2_fold` changed `jited_prog_len`, but execution returned the wrong value:

- broken: `389579793`
- expected: `9`

Programs with no detected cmov sites still behaved correctly.

## Actual pattern in `log2_fold`

Disassembling `micro/programs/log2_fold.bpf.o` showed the select shape used by `micro_log2_u32()`:

```text
60: r3 = 0x1
61: if r4 > 0xffff goto +0x1
62: r3 = 0x0

65: r6 = 0x1
66: if r4 > 0xff goto +0x1
67: r6 = 0x0

70: r8 = 0x1
71: if r4 > 0xf goto +0x1
72: r8 = 0x0
```

The same 3-insn compact pattern appears twice in the function, so the runner correctly found 6 compact cmov sites.

## What the diagnostics showed

Temporary printk instrumentation showed:

- policy parsing validated all 6 `log2_fold` rules as active
- v4 dispatch applied all 6 rules successfully
- there were no validation failures and no fallback to stock emission

That ruled out:

- inactive policy rules
- emitter returning an error and falling through
- addrs update mismatches as the primary `log2_fold` failure

## Root cause 1: flags clobbered between `cmp` and `cmov`

Dumping the recompiled JIT for `log2_fold` exposed the real problem. The compact select was emitted as:

```text
mov    edx,0x1
cmp    rcx,0xffff
xor    r11d,r11d
cmovbe rdx,r11
```

The `xor r11d, r11d` came from the JIT's zero-immediate optimization in `emit_mov_imm32()`. That instruction updates flags, so the subsequent `cmovbe` no longer used the flags from the compare.

This affected v4 recompile because the compact emitter materialized the override value after `cmp`, and it also exposed the same latent issue in the diamond emitter for any post-`cmp` zero move.

### Fix

Added a flag-preserving zero-immediate path:

- new helper `emit_mov_imm32_noflags()`
- new helper `emit_bpf_mov_value_noflags()`

Then used the no-flags helper for all moves emitted after `cmp` in:

- `emit_bpf_cmov_select()`
- `emit_bpf_cmov_select_compact()`

This preserves the compare flags for the final `cmov`.

## Root cause 2: subprog sites are not safe in the current recompile flow

`cmov_select` still diverged after the flag fix. Investigation showed:

- the single detected cmov site was in the helper subprog `cmov_select_pick()`
- the runner scanned the entire xlated program, including non-main subprogs

The current `BPF_PROG_JIT_RECOMPILE` path is only safe for main-program rewrite sites in this POC. Recompiling subprog sites produced incorrect behavior.

### Fix

Restricted v4 cmov policy generation/acceptance to the main subprog:

- runner: `find_cmov_select_sites_xlated()` now scans only the main subprog range, using `func_info`
- kernel: `bpf_jit_parse_policy()` rejects rules beyond the main subprog boundary

This makes subprog-only cases fall back cleanly to stock JIT instead of miscompiling.

## Verification

### `log2_fold`

Command:

```bash
vng -r arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark \
  --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/log2_fold.bpf.o --memory micro/generated-inputs/log2_fold.mem --repeat 1 --recompile-cmov --io-mode staged"
```

Result after fix:

- `recompile-cmov: found 6 cmov-select sites in xlated program (139 insns)`
- `result: 9`
- `jited_prog_len: 682`

### `cmov_select`

Command:

```bash
vng -r arch/x86/boot/bzImage --cwd /home/yunwei37/workspace/bpf-benchmark \
  --exec "micro/build/runner/micro_exec run-kernel --program micro/programs/cmov_select.bpf.o --memory micro/generated-inputs/cmov_select.mem --repeat 1 --recompile-cmov --io-mode staged"
```

Result after fix:

- `recompile-cmov: no cmov-select sites found in xlated program (931 insns)`
- `result: 11332120082118096118`

That matches the baseline `cmov_select` result.

## Files changed

- `vendor/linux/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux/kernel/bpf/jit_directives.c`
- `micro/runner/src/kernel_runner.cpp`
