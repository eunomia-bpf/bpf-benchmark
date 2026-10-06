# CMOV Subprog Recompile Fix

Date: 2026-03-10

## Summary

`cmov_select` now produces the same result with and without `--recompile-cmov` on
`vendor/linux-framework`:

- baseline: `11332120082118096118`
- `--recompile-cmov`: `11332120082118096118`
- `log2_fold --recompile-cmov`: `9`

## What Was Broken

There were two separate issues in the v4 recompile path.

### 1. Subprog-local rules were still rejected in `jit-directive-v4`

`vendor/linux-framework/kernel/bpf/jit_directives.c` still used the old
main-subprog-only gate in the v4 policy parser. That caused
`BPF_PROG_JIT_RECOMPILE` to fail with `EINVAL` for `cmov_select`, whose only
COND_SELECT site is in the helper subprog appended at xlated insn offset `925`.

Ported fix:

- replaced `bpf_jit_main_subprog_end()` with
  `bpf_jit_rule_within_single_subprog()`
- applied that helper in both v4 policy parsers so rules are allowed in any
  single subprog, but never across a subprog boundary

### 2. Subprog-local v4 recompile was not actually subprog-aware

After enabling the rule, `cmov_select --recompile-cmov` returned the wrong
result (`9841221549609281104`).

The root cause was not the `cmovcc` encoding itself. The broken part was the
split-subprog re-JIT path:

- v4 policy `site_start` is validated as a program-absolute xlated offset
- x86 `do_jit()` was looking rules up with the current subprog-local loop index
- `bpf_jit_try_emit_rule()` also indexed the current subprog-local `insns[]`
  with that absolute `site_start`
- `BPF_PROG_JIT_RECOMPILE` recompiled only the top-level program object, while
  BPF-to-BPF programs actually execute the split `aux->func[]` images

That combination made subprog-local recompile unsafe.

## Fix

### x86 JIT: rebase policy sites for split subprogs

In `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`:

- v4 rule lookup now uses an absolute instruction index:
  `subprog_start + local_idx`
- v4 active policy rules are rebased from program-absolute `site_start` to the
  current subprog-local insn array before emission
- the rebased local site is used for COND_SELECT, WIDE_MEM, ROTATE, and LEA
  emitters

This makes the x86 JIT interpret subprog-local policy sites against the correct
instruction stream.

### Recompile path: re-JIT split `func[]` images, not just the top-level prog

In `vendor/linux-framework/kernel/bpf/jit_directives.c`:

- added a split-subprog recompile helper for `BPF_PROG_JIT_RECOMPILE`
- if `prog->aux->func_cnt > 0`, recompile now:
  1. JITs every `aux->func[i]` once
  2. repatches `BPF_PSEUDO_CALL` / `BPF_PSEUDO_FUNC` targets to the new subprog
     addresses
  3. JITs every `aux->func[i]` a second time
  4. requires non-main subprog addresses to stay stable on the second pass
  5. refreshes the top-level `prog->bpf_func` / length metadata from `func[0]`

This mirrors the initial split-subprog JIT flow closely enough for v4 recompile
to handle subprog-local rewrite sites safely.

## Validation

Kernel build:

```bash
cd vendor/linux-framework && make -j"$(nproc)" bzImage
```

Runner build:

```bash
make -C micro micro_exec
```

VM results with the final kernel:

### `cmov_select` baseline

```json
{"result":11332120082118096118,"jited_prog_len":4168,"recompile":{"requested":false,"applied":false}}
```

### `cmov_select --recompile-cmov`

```json
{"result":11332120082118096118,"jited_prog_len":4167,"directive_scan":{"cmov_sites":1},"recompile":{"requested":true,"applied":true,"error":""}}
```

### `log2_fold --recompile-cmov`

```json
{"result":9,"jited_prog_len":682,"directive_scan":{"cmov_sites":6},"recompile":{"requested":true,"applied":true,"error":""}}
```

## Files Changed

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
