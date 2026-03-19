# Kernel Code Reduction Audit (2026-03-19)

## Scope

Audit target: `vendor/linux-framework` Phase A/B/C1/C2 kernel changes.

Goal: remove safe dead code / redundant helpers and reduce net kernel churn.

## Diff Summary

Initial `git diff --stat` in `vendor/linux-framework`:

```text
 arch/x86/net/bpf_jit_comp.c        | 116 +++---
 include/linux/bpf.h                |  26 ++
 include/linux/bpf_jit_directives.h |  13 +
 include/linux/filter.h             |   1 +
 kernel/bpf/core.c                  |   5 +
 kernel/bpf/jit_directives.c        | 823 ++++++++++++++++++++++++++-----------
 6 files changed, 692 insertions(+), 292 deletions(-)
```

Current `git diff --stat` after cleanup:

```text
 arch/x86/net/bpf_jit_comp.c        | 488 +++++++---------------
 include/linux/bpf.h                |  26 ++
 include/linux/bpf_jit_directives.h |  13 +
 include/linux/filter.h             |   1 +
 kernel/bpf/core.c                  |   5 +
 kernel/bpf/jit_directives.c        | 806 ++++++++++++++++++++++++++-----------
 6 files changed, 766 insertions(+), 573 deletions(-)
```

Net change improved from `+400` lines to `+193` lines.

## Removed Items

### 1. x86 emitter dead `COND_SELECT` shape parsing

File: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Removed old emitter-side insn-shape parsing / validation helpers that became redundant once validator fills normalized `rule->params`:

- `is_bpf_simple_mov`
- `is_bpf_cmov_cond_jump`
- `bpf_mov_is_noop`
- `emit_bpf_cmov_select`
- `is_bpf_cmov_select_compact`
- `emit_bpf_cmov_select_compact`
- `emit_bpf_cmov_guarded_update`
- old `emit_canonical_select(insns, insn_cnt, idx, site_len, ...)`

Replacement:

- `emit_canonical_select()` now consumes normalized canonical params directly.
- emitter no longer re-parses the original BPF site for `site_len=2/3/4`.

### 2. dead MOV helpers left behind by old `COND_SELECT` path

File: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Removed helpers that were only used by the deleted old `COND_SELECT` emitter path:

- `emit_bpf_mov_value`
- `emit_bpf_mov_value_noflags`

### 3. redundant local-site translation helper

File: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Removed:

- `bpf_jit_rule_local_site_start`

Reason:

- after moving `COND_SELECT` emission to normalized params and using validated pointer params for other forms, this helper no longer had a caller.

### 4. redundant `do_jit()` active-rule fast path

File: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

Removed:

- `main_aux` / `policy` / `has_active_rules` pre-check

Reason:

- `bpf_jit_rule_lookup_prog()` already returns `NULL` when no active policy exists.
- the extra gate was redundant code, not extra functionality.

### 5. cond-select-specific wrapper helpers in validator

File: `vendor/linux-framework/kernel/bpf/jit_directives.c`

Removed / folded away:

- custom `struct bpf_jit_cond_select_value`
- `bpf_jit_cond_select_set_reg`
- `bpf_jit_cond_select_set_imm`
- `bpf_jit_cond_select_set_value`

Replacement:

- reuse `struct bpf_jit_binding_value`
- reuse generic `bpf_jit_param_set_reg/imm`
- add one generic `bpf_jit_param_set_value()` helper

This trims Phase C2 normalization code without changing behavior.

## Reviewed But Kept

These additions were reviewed and kept because they are still required, not dead code:

- `BPF_JIT_ZEXT_PARAM_ALU32_PTR`
  - x86 zero-ext-elide still needs the validated original ALU32 insn pointer to re-emit the exact ALU32 op.
- `BPF_JIT_BFLIP_PARAM_SITE_PTR`
  - branch-flip emission still needs the validated original site instruction sequence to re-emit body A/B.
- `bpf_jit_supports_recompile()`
  - required arch capability gate so non-supporting JITs return `-EOPNOTSUPP`.
- `bpf_prog_main_aux()`, `bpf_jit_recompile_clear_stage()`, `bpf_jit_recompile_reset_prog_aux()`
  - shared helper dedup across `jit_directives.c` and x86 JIT; no dead code remained after moving them.

I did not find other safe deletable dead code in the modified files without changing current behavior.

## Validation

Executed on 2026-03-19:

1. `cd vendor/linux-framework && make -j$(nproc) bzImage`
   - PASS
   - one intermediate failure occurred due host disk space (`objcopy: vmlinux: No space left on device`); after deleting failed `.tmp_vmlinux*` link artifacts, rebuild passed cleanly.

2. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest`
   - result: `19 passed, 1 failed`
   - remaining failure: `Wide Site-Only JIT Diff`
   - this matches the pre-existing known state documented in repo notes; this cleanup did not introduce a new selftest failure.

3. `make vm-micro-smoke`
   - PASS

