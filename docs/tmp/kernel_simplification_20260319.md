# Kernel Simplification Report (2026-03-19)

## Scope

Implemented all simplification items from `docs/tmp/kernel_architecture_review_20260319.md`:

- Phase 1: reuse verifier logging, inline trivial wrappers, collapse staged getter / ksym wrappers
- Phase 2: unify ROTATE validation, deduplicate form / feature / choice validation

Touched files:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/bpf.h`

## Functional Summary

### Phase 1

- Replaced the custom recompile log object and manual alloc/copy/free path with the existing verifier log infrastructure:
  - `struct bpf_verifier_log`
  - `bpf_vlog_init()`
  - `bpf_verifier_vlog()`
  - `bpf_log()`
  - `bpf_vlog_finalize()`
- Removed dead-thin logging / accounting wrappers:
  - `bpf_jit_recompile_log_ctx()`
  - `bpf_jit_recompile_note_rule()`
  - duplicated `bpf_jit_rule_form()`
- Inlined trivial staged-image wrappers:
  - `bpf_jit_recompile_real_func_cnt()`
  - `bpf_jit_recompile_stage_begin()`
  - `bpf_jit_recompile_stage_end()`
  - `bpf_jit_recompile_next_func()`
  - `bpf_jit_compute_site_end()`
- Merged `bpf_jit_recompile_shadow_ksym_prepare()` into `bpf_jit_recompile_shadow_ksym_add()`
- Moved x86 staged getters into `include/linux/bpf_jit_directives.h` as static inlines
- Inlined trivial `image_prog` / `ksym_prog` projections at their only call sites

### Phase 2

- Replaced the separate ROTATE parsers with one shared spec-driven validator:
  - `bpf_jit_rotate_validate_common()`
  - `struct bpf_jit_rotate_spec`
- Preserved all four accepted source-shape buckets through a compact `rotate_specs[]` table
- Centralized per-form metadata in `bpf_jit_form_meta[]`:
  - canonical form validity
  - native-choice legality
  - CPU feature support
  - canonical-site validator dispatch
  - side-effect policy
- Removed duplicated per-form CPU-feature checks and large switch-based dispatch logic
- Dropped redundant local bounds checks where generic site validation already proves the site range

## LOC Delta

This section measures physical LOC in the touched files before simplification (`HEAD`) and after simplification (current worktree). This is intentionally different from the earlier `master...HEAD` added-line accounting in `docs/tmp/kernel_loc_breakdown_20260319.md`.

| File | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `kernel/bpf/jit_directives.c` | 3228 | 2797 | -431 |
| `arch/x86/net/bpf_jit_comp.c` | 6136 | 6091 | -45 |
| `include/linux/bpf_jit_directives.h` | 230 | 260 | +30 |
| `include/linux/bpf.h` | 4072 | 4071 | -1 |
| **Total** | **13666** | **13219** | **-447** |

Git diff summary for the simplification patchset:

- 447 insertions
- 894 deletions
- net **-447 LOC**

Result versus the architecture-review estimate:

- Review target: **-400 to -550 LOC**
- Actual simplification: **-447 LOC**

## Verification

| Command | Result |
| --- | --- |
| `make -C vendor/linux-framework -j$(nproc) bzImage` | PASS |
| `make vm-selftest` | PASS, 19 / 19 tests |
| `make vm-micro-smoke` | PASS; required `simple` and `cmov_dense` passed for both `kernel` and `kernel-recompile` |
| `cmake --build scanner/build --target test_scanner && ./scanner/build/test_scanner` | PASS 180 |

Additional smoke details from `make vm-micro-smoke`:

- `simple`: `kernel` PASS, `kernel-recompile` PASS
- `load_byte_recompose`: `kernel` PASS, `kernel-recompile` PASS
- `cmov_dense`: `kernel` PASS, `kernel-recompile` PASS

## Outcome

All requested simplification items are implemented and the required verification matrix is green.
