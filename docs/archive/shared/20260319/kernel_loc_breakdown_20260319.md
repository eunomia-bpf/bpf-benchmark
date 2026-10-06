# Kernel LOC Breakdown for BpfReJIT (2026-03-19)

## Baseline and counting rules

- Vendor kernel repo: `vendor/linux-framework`
- Feature branch analyzed: `jit-directive-v5` at `cc0f4f6d3`
- Stock baseline used for counts: merge-base with `master`, commit `c23719abc3308df7ed3ad35650ad211fb2d2003d`
- Added-line totals come from `git -C vendor/linux-framework diff --numstat master...HEAD`
- For modified existing files, component counts below are added lines only, mapped to the enclosing function or top-level declaration in `HEAD`
- For new files (`kernel/bpf/jit_directives.c`, `include/linux/bpf_jit_directives.h`), every line is an addition, so section/function counts are whole-file physical LOC
- `tests/kernel/test_recompile.c` is outside `vendor/linux-framework`; you asked for "all of it", so its counts are full-file LOC, not git-delta LOC

## Vendor kernel delta summary

Runtime-kernel files in `vendor/linux-framework` add 5800 lines across 11 files. If you also count the mirrored userspace header under `tools/`, the vendor-tree total is 5895 added lines across 12 files.

`kernel/bpf/jit_directives.c` and `arch/x86/net/bpf_jit_comp.c` dominate the runtime delta: 5296 / 5800 added LOC, or 91.3%.

| File | Added LOC | Notes |
| --- | ---: | --- |
| `kernel/bpf/jit_directives.c` | 3114 | New syscall/control-plane implementation; all new |
| `arch/x86/net/bpf_jit_comp.c` | 2182 | x86 backend emitters, dispatch, staged commit/abort |
| `include/linux/bpf_jit_directives.h` | 238 | New internal header |
| `kernel/bpf/core.c` | 101 | Kallsyms/extable replacement, aux lifecycle |
| `include/uapi/linux/bpf.h` | 94 | UAPI command, policy blob format, attr payload |
| `include/linux/bpf.h` | 58 | Aux state, kallsyms metadata, inline helpers |
| `kernel/bpf/helpers.c` | 5 | Safe exception callback load |
| `kernel/bpf/syscall.c` | 4 | Syscall switch wiring |
| `kernel/bpf/verifier.c` | 2 | Preserve `orig_idx` across aux-data expansion |
| `kernel/bpf/Makefile` | 1 | Build `jit_directives.o` |
| `include/linux/filter.h` | 1 | `bpf_jit_supports_recompile()` prototype |
| `tools/include/uapi/linux/bpf.h` | 95 | Mirror sync of runtime UAPI header; not runtime kernel code |

## Deep Dive: `kernel/bpf/jit_directives.c`

Total added LOC: 3114  
Function-body LOC: 2772  
Top-level scaffolding/comments/types: 342

### Category breakdown

| Category | LOC | Share |
| --- | ---: | ---: |
| Top-level scaffolding, types, comments | 342 | 11.0% |
| Logging and rule accounting | 139 | 4.5% |
| Snapshot, rollback, stage and ksym management | 217 | 7.0% |
| Generic helpers and common validation | 518 | 16.6% |
| COND_SELECT validator | 146 | 4.7% |
| WIDE_MEM validator | 148 | 4.8% |
| ROTATE validator family | 461 | 14.8% |
| BITFIELD_EXTRACT validator | 121 | 3.9% |
| ADDR_CALC validator | 74 | 2.4% |
| ZERO_EXT_ELIDE validator | 73 | 2.3% |
| ENDIAN_FUSION validator | 113 | 3.6% |
| BRANCH_FLIP validator | 115 | 3.7% |
| Policy parsing and lookup | 256 | 8.2% |
| Recompile orchestration and syscall entry | 391 | 12.6% |

### Essential logic vs validation/boilerplate

Judgement-based split for this file:

- Essential logic: 2115 LOC, or 67.9%
  - Snapshot/rollback and staged-image management
  - Per-form parsing and canonical parameter synthesis
  - Policy parsing/lookup
  - Recompile orchestration and syscall flow
- Boilerplate/validation/error-handling: 999 LOC, or 32.1%
  - Top-level scaffolding and comments
  - Logging
  - Generic/common validation and safety gates

This is the most conservative file-level split. At the whole runtime-kernel delta level, the x86 backend makes the branch more logic-heavy overall; rough branch-wide read is closer to 80% feature/integration logic and 20% scaffolding/validation/header boilerplate.

### Largest buckets

- ROTATE alone is 461 LOC in this file, mostly because it supports four distinct source shapes
- Common validation plus logging is 657 LOC (`518 + 139`)
- Policy I/O and parse/lookup is 256 LOC
- Top-level non-function scaffolding is 342 LOC

### Function-by-function inventory

Top-level scaffolding outside functions: 342 LOC

- Includes, hard limits, log/snapshot state structs, banner comments, doc comments, and inter-function whitespace

#### Logging and rule accounting (139 LOC)

- `bpf_jit_recompile_log_ctx` - 11 LOC: fetches the main-program log context from `bpf_prog_main_aux()`
- `bpf_jit_recompile_log_appendv` - 21 LOC: bounded `vsnprintf()` append into the kernel-side recompile log buffer
- `bpf_jit_recompile_prog_log` - 9 LOC: varargs wrapper for program-level log lines
- `bpf_jit_recompile_rule_log` - 33 LOC: prefixes log lines with rule index, form, and site range
- `bpf_jit_recompile_log_alloc` - 28 LOC: allocates bounded kernel/user log buffers from syscall attributes
- `bpf_jit_recompile_log_copy_to_user` - 17 LOC: NUL-terminates and copies the kernel log back to userspace
- `bpf_jit_recompile_log_free` - 8 LOC: frees log buffers
- `bpf_jit_recompile_note_rule` - 12 LOC: increments the per-recompile applied-rule counter

#### Snapshot, rollback, stage and ksym management (217 LOC)

- `bpf_jit_recompile_save_prog_state` - 19 LOC: snapshots live JIT state and clones the translated instruction stream
- `bpf_jit_recompile_snapshot_free` - 16 LOC: frees rollback allocations and resets snapshot metadata
- `bpf_jit_recompile_restore_prog_state` - 22 LOC: restores one program from saved state and clears stale staged output
- `bpf_jit_recompile_snapshot` - 43 LOC: snapshots the main program plus subprogram images for rollback
- `bpf_jit_recompile_restore` - 14 LOC: restores all snapped programs and the saved exception callback
- `bpf_jit_recompile_real_func_cnt` - 4 LOC: resolves the true `func[]` count when `real_func_cnt` is present
- `bpf_jit_recompile_stage_begin` - 5 LOC: resets per-prog aux state and marks a program as actively recompiling
- `bpf_jit_recompile_stage_end` - 4 LOC: clears the active recompile flag
- `bpf_jit_recompile_stage_ok` - 19 LOC: validates staged-output invariants after a JIT pass
- `bpf_jit_recompile_next_func` - 4 LOC: returns staged function pointer if one exists, else the live one
- `bpf_jit_recompile_shadow_ksym_prepare` - 20 LOC: fills shadow kallsyms metadata for a staged image
- `bpf_jit_recompile_shadow_ksym_add` - 17 LOC: publishes a shadow ksym for the staged image
- `bpf_jit_recompile_shadow_ksym_del` - 5 LOC: removes the shadow ksym if installed
- `bpf_jit_recompile_image_prog` - 10 LOC: maps image index to the actual program object to re-JIT
- `bpf_jit_recompile_ksym_prog` - 15 LOC: maps image index to the program that owns kallsyms state

#### Generic helpers and common validation (518 LOC)

- `bpf_jit_directives_valid_memfd` - 11 LOC: enforces the sealed-memfd requirement for policy blobs
- `bpf_jit_is_cmov_cond_jump` - 25 LOC: recognizes conditional jumps that can map to `cmovcc`
- `bpf_jit_is_simple_mov` - 18 LOC: recognizes plain register or immediate `mov` instructions
- `bpf_jit_cmov_select_match_diamond` - 35 LOC: matches the 4-insn diamond select shape
- `bpf_jit_cmov_select_match_compact` - 31 LOC: matches the 3-insn compact select shape
- `bpf_pseudo_call_insn` - 5 LOC: recognizes pseudo-call instructions
- `bpf_jit_free_policy` - 8 LOC: frees a parsed policy object and its retained blob
- `rule_cmp` - 15 LOC: sort comparator for rules by site and original user order
- `bpf_jit_rule_form` - 4 LOC: returns `rule->canonical_form`
- `bpf_jit_native_choice_valid` - 24 LOC: validates `native_choice` against the chosen canonical form
- `bpf_jit_canonical_form_valid` - 16 LOC: validates the canonical-form enum
- `bpf_jit_pattern_rule_shape_valid` - 6 LOC: performs basic user-rule shape checks
- `bpf_jit_compute_site_end` - 4 LOC: overflow-safe `site_end` calculation
- `bpf_jit_site_range_valid` - 15 LOC: validates site bounds against program length
- `bpf_jit_has_interior_edge` - 51 LOC: rejects sites with control flow entering the middle of the region
- `bpf_jit_param_set_reg` - 6 LOC: writes a validated register binding
- `bpf_jit_param_set_imm` - 6 LOC: writes a validated immediate binding
- `bpf_jit_param_set_ptr` - 5 LOC: writes an internal pointer binding
- `bpf_jit_param_set_value` - 9 LOC: copies a generic binding value into canonical params
- `bpf_jit_site_has_side_effects` - 23 LOC: rejects stores, atomics, and helper/callback side effects inside a rewrite site
- `bpf_jit_cond_op_valid` - 18 LOC: validates conditional ops shared by select/flip forms
- `bpf_jit_branch_flip_cond_op_valid` - 4 LOC: narrows allowed conditional ops for branch flip
- `bpf_jit_canonical_site_fail` - 10 LOC: standard failure logger for invalid canonical sites
- `bpf_jit_validate_canonical_site` - 69 LOC: form-independent site validation before per-form parsing
- `bpf_jit_validate_rule` - 47 LOC: dispatches a rule to the correct per-form validator
- `bpf_jit_rule_within_single_subprog` - 39 LOC: rejects rules that cross subprogram boundaries
- `bpf_jit_alloc_policy` - 14 LOC: allocates the kernel policy object and flexible rule array

#### COND_SELECT validator (146 LOC)

- `bpf_jit_cond_select_get_mov_value` - 12 LOC: converts a `mov` instruction into a normalized binding value
- `bpf_jit_cmov_select_match_guarded_update` - 24 LOC: matches the 2-insn guarded-update select pattern
- `bpf_jit_parse_cond_select_shape` - 69 LOC: parses any supported select shape into one normalized descriptor
- `bpf_jit_cond_select_fill_params` - 20 LOC: serializes normalized select info into canonical params
- `bpf_jit_validate_cond_select_rule` - 21 LOC: end-to-end COND_SELECT validator

#### WIDE_MEM validator (148 LOC)

- `bpf_jit_parse_wide_mem_shape` - 116 LOC: parses byte-load-and-pack sequences into one wide-memory description
- `bpf_jit_validate_wide_mem_rule` - 32 LOC: validates WIDE_MEM and emits canonical params

#### ROTATE validator family (461 LOC)

- `bpf_jit_parse_rotate_4insn` - 108 LOC: parses classic and commuted 4-insn rotate idioms
- `bpf_jit_parse_rotate_5insn` - 87 LOC: parses 5-insn two-copy rotate idioms
- `bpf_jit_rotate_mask_matches` - 14 LOC: checks masked-rotate immediates against the rotate amount
- `bpf_jit_parse_rotate_5insn_masked` - 103 LOC: parses 5-insn masked rotate forms
- `bpf_jit_parse_rotate_6insn` - 102 LOC: parses 6-insn masked two-copy rotate forms
- `bpf_jit_validate_rotate_rule` - 47 LOC: validates ROTATE and chooses canonical params

#### BITFIELD_EXTRACT validator (121 LOC)

- `bpf_jit_parse_bitfield_extract_site` - 91 LOC: parses shift/mask bitfield-extract idioms into a normalized descriptor
- `bpf_jit_validate_bitfield_extract_rule` - 30 LOC: validates BITFIELD_EXTRACT and emits canonical params

#### ADDR_CALC validator (74 LOC)

- `bpf_jit_parse_addr_calc_shape` - 49 LOC: parses `mov + lsh + add` into an address-calculation descriptor
- `bpf_jit_validate_addr_calc_rule` - 25 LOC: validates ADDR_CALC and emits LEA-friendly params

#### ZERO_EXT_ELIDE validator (73 LOC)

- `bpf_jit_zero_ext_elide_is_alu32` - 4 LOC: identifies ALU32 producer instructions
- `bpf_jit_zero_ext_elide_is_tail` - 22 LOC: identifies removable zero-extension tails
- `bpf_jit_parse_zero_ext_elide_shape` - 26 LOC: parses the ALU32-plus-zero-extend pattern
- `bpf_jit_validate_zero_ext_elide_rule` - 21 LOC: validates ZERO_EXT_ELIDE and emits canonical params

#### ENDIAN_FUSION validator (113 LOC)

- `bpf_jit_endian_width_from_mem_opcode` - 16 LOC: extracts width from memory opcodes
- `bpf_jit_endian_fusion_is_swap` - 13 LOC: identifies endian-swap instructions for the requested width
- `bpf_jit_parse_endian_fusion_shape` - 52 LOC: parses load-swap and swap-store idioms
- `bpf_jit_validate_endian_fusion_rule` - 32 LOC: validates ENDIAN_FUSION and emits MOVBE-friendly params

#### BRANCH_FLIP validator (115 LOC)

- `bpf_jit_branch_flip_body_linear` - 23 LOC: verifies that both branch bodies are straight-line regions
- `bpf_jit_parse_branch_flip_shape` - 61 LOC: parses if/else layout into branch-flip canonical params
- `bpf_jit_validate_branch_flip_rule` - 31 LOC: validates BRANCH_FLIP and emits canonical params

#### Policy parsing and lookup (256 LOC)

- `bpf_jit_parse_policy_format_v2` - 70 LOC: parses v2 policy rules, validates each one, and records active rules
- `bpf_jit_parse_policy` - 152 LOC: reads the sealed memfd, validates header/bindings, parses the policy, and sorts rules
- `bpf_jit_rule_lookup` - 34 LOC: binary-search lookup for an active rule at a given instruction index

#### Recompile orchestration and syscall entry (391 LOC)

- `bpf_jit_recompile_prog_images` - 228 LOC: stages, recompiles, patches subprog references, commits, replaces kallsyms, and handles no-op re-JIT cases
- `bpf_prog_jit_recompile` - 163 LOC: syscall entry that checks perms, allocates log state, parses policy, snapshots state, swaps policy, triggers re-JIT, and rolls back on failure

## Deep Dive: `arch/x86/net/bpf_jit_comp.c`

Total added LOC: 2182  
These counts are added lines only inside the existing x86 JIT backend.

### Canonical emitter implementations (429 LOC)

| Canonical emitter | Added LOC | Role |
| --- | ---: | --- |
| `emit_canonical_select` | 109 | `COND_SELECT` to `cmp/test + cmovcc` |
| `emit_canonical_wide_load` | 30 | `WIDE_MEM` wide byte-load lowering |
| `emit_canonical_rotate` | 79 | `ROTATE` to `ror` or `rorx` |
| `emit_canonical_lea_fusion` | 31 | `ADDR_CALC` to `lea` |
| `emit_canonical_zero_ext_elide` | 21 | `ZERO_EXT_ELIDE` by reusing ALU32 lowering |
| `emit_canonical_endian_fusion` | 39 | `ENDIAN_FUSION` to `movbe` |
| `emit_canonical_branch_flip` | 80 | `BRANCH_FLIP` with inverted Jcc and swapped bodies |
| `emit_canonical_bitfield_extract` | 40 | `BITFIELD_EXTRACT` to `bextr` or shift/mask |

### Rule dispatch and application path (212 LOC)

| Function | Added LOC | Role |
| --- | ---: | --- |
| `bpf_jit_rule_form` | 3 | Extracts canonical form from a rule |
| `bpf_jit_rule_lookup_prog` | 12 | Maps per-subprog instruction index to policy lookup |
| `bpf_jit_try_emit_rule` | 80 | Main canonical-form dispatcher |
| `bpf_jit_try_emit_prog_rule` | 15 | Rule lookup wrapper for the current program and insn |
| `bpf_jit_commit_rule_region` | 25 | Commits emitted bytes and updates `addrs[]` for multi-insn replacement |
| `bpf_jit_apply_prog_rule` | 38 | Applies one rule and records apply/fallback logging |
| `do_jit` | 39 | Integrates rule application into the main x86 JIT loop |

### Helper-function breakdown

| Helper block | Added LOC | Functions |
| --- | ---: | --- |
| Select/branch lowering helpers | 274 | `emit_mov_imm32_noflags`, `jit_bpf_reg`, `emit_cmov_reg`, `bpf_jmp_invert`, `bpf_jmp_to_x86_cond`, `bpf_jmp_to_x86_cmov`, `emit_bpf_jmp_cmp`, `bpf_jit_binding_value_is_noop`, `emit_bpf_binding_value` |
| Wide/LEA helpers | 115 | `x86_base_needs_disp`, `emit_insn_suffix`, `emit_st_imm32`, `emit_store_stack_imm64`, `pick_wide_chunk`, `wide_chunk_bpf_size`, `emit_wide_load_sequence`, `emit_lea_base_index` |
| Rotate helpers | 16 | `emit_or64_reg`, `emit_lsh64_imm` |
| Endian helpers | 64 | `emit_movbe_load`, `emit_movbe_store`, `emit_bswap_width` |
| Branch-flip helpers | 114 | `emit_spectre_bhb_barrier`, `measure_branch_flip_body`, `emit_branch_flip_body`, `emit_local_cond_jump`, `emit_local_jump` |
| Bitfield helpers | 136 | `bitfield_mask_from_imm`, `bitfield_mask_fits_imm`, `bitfield_low_mask_width`, `emit_bextr`, `emit_bitfield_rsh_imm`, `emit_bitfield_and_imm`, `emit_bitfield_extract_core` |
| Legacy-emitter integration | 523 | Added logic inside `emit_bpf_alu32_insn`, `emit_bpf_end_insn`, `emit_bpf_alu64_insn`, and `emit_linear_bpf_insn` so existing x86 paths can serve the new canonical forms |
| Backend staging/lifecycle | 214 | `emit_priv_frame_ptr`, `emit_shiftx`, `emit_3vex`, staged-image accessors, `bpf_int_jit_compile`, `bpf_jit_recompile_commit`, `bpf_jit_recompile_abort`, `bpf_jit_free`, `bpf_jit_supports_recompile`, `priv_stack_check_guard` |
| Top-level scaffolding | 85 | Includes, new `jit_context` fields, `x64_jit_data` staged-state fields, and comments/prototypes outside functions |

## Requested smaller files

### `include/uapi/linux/bpf.h` (94 added LOC)

- 1 LOC: adds `BPF_PROG_JIT_RECOMPILE` to `enum bpf_cmd`
- 84 LOC: policy-blob UAPI
  - Magic/version constants
  - Architecture IDs
  - `struct bpf_jit_policy_hdr`
  - `enum bpf_jit_canonical_form`
  - Per-form `native_choice` enums
  - `struct bpf_jit_rewrite_rule_v2`
- 9 LOC: adds `union bpf_attr.jit_recompile`

### `include/linux/bpf_jit_directives.h` (238 added LOC, new file)

- 23 LOC: header guard, includes, sync checks, and size macros
- 101 LOC: binding model and per-form/internal parameter enums
- 34 LOC: `struct bpf_jit_rule` and `struct bpf_jit_policy`
- 19 LOC: exported parser/logging/lookup prototypes
- 59 LOC: x86 staged-image API declarations plus non-x86 inline stubs
- 2 LOC: closing guard

### `include/linux/filter.h` (1 added LOC)

- 1 LOC: declares `bpf_jit_supports_recompile()`

### `kernel/bpf/core.c` (101 added LOC)

- 10 LOC: include plus aux init/destroy hooks for `jit_recompile_ksym`, mutex, and policy free
- 46 LOC: ksym metadata helpers and add-path refactoring
  - `__bpf_ksym_add` - 2 LOC
  - `bpf_ksym_add` delta - 4 LOC
  - `bpf_ksym_reset` - 5 LOC
  - `bpf_prog_ksym_set_meta` - 11 LOC
  - `bpf_prog_ksym_set_prefix` - 13 LOC
  - `bpf_prog_kallsyms_add` delta - 11 LOC
- 33 LOC: `bpf_prog_kallsyms_replace()` for live-image replacement
- 8 LOC: owner/extable lookup changes in `bpf_prog_ksym_find()` and `search_bpf_extables()`
- 4 LOC: weak default `bpf_jit_supports_recompile()`

### `kernel/bpf/syscall.c` (4 added LOC)

- 1 LOC: includes `linux/bpf_jit_directives.h`
- 3 LOC: adds the `BPF_PROG_JIT_RECOMPILE` dispatch case in `__sys_bpf()`

## Additional touched runtime-kernel files

These were not in your explicit list, but they are part of the vendor kernel delta and should count as BpfReJIT changes.

### `include/linux/bpf.h` (58 added LOC)

- 2 LOC: forward declarations for `struct bpf_jit_policy` and `struct bpf_jit_recompile_log`
- 3 LOC: extends `struct bpf_ksym` with `owner`, `extable`, and `num_exentries`
- 6 LOC: adds the `bpf_prog_kallsyms_replace()` prototype
- 15 LOC: extends `struct bpf_prog_aux` with staged recompile state, mutex, policy pointer, log pointer, and shadow ksym
- 7 LOC: `bpf_prog_main_aux()` helper
- 12 LOC: `bpf_jit_recompile_clear_stage()` helper
- 5 LOC: `bpf_jit_recompile_reset_prog_aux()` helper
- 8 LOC: comments/spacing around the new helpers and fields

### `kernel/bpf/helpers.c` (5 added LOC)

- 5 LOC inside `bpf_throw()`: loads `bpf_exception_cb` with `READ_ONCE()` and adds a null-guard before invoking it

### `kernel/bpf/verifier.c` (2 added LOC)

- 2 LOC inside `adjust_insn_aux_data()`: preserves `orig_idx` while expanding aux-data across a patched range

### `kernel/bpf/Makefile` (1 added LOC)

- 1 LOC: builds `jit_directives.o`

### `tools/include/uapi/linux/bpf.h` (95 added LOC)

- Mirrors the 94-line runtime UAPI expansion above
- Plus 1 formatting blank line in the tools copy
- This is vendor-tree churn, but not runtime kernel code

## `tests/kernel/test_recompile.c` (full file: 2091 LOC)

This file is outside `vendor/linux-framework`, so it is not part of the kernel-delta total above. You asked for all of it, so here is the full-file breakdown.

| Area | LOC | Notes |
| --- | ---: | --- |
| Top-level headers, macros, structs, globals | 204 | Build-time paths, memfd constants, helper structs, test table |
| Harness and memory helpers | 156 | Logging, cleanup, tag formatting, memlock lift, reporting, `main()` |
| Program load and snapshot helpers | 386 | Load program, fetch metadata, snapshot JIT image/line info, region comparison |
| Execution helpers | 136 | Reset/read result map, run program, four packet-check helpers |
| Policy blob and site builders | 370 | Build policy blobs, sealed memfds, syscall wrapper, site discovery, per-shape blob builders |
| Positive tests | 439 | Happy-path and behavior-preservation checks |
| Negative-test generators | 85 | Blob mutation scaffolding for invalid input cases |
| Negative tests | 149 | Wrong magic/tag/arch/len, unsealed memfd, OOB site, truncated header |
| Concurrency and attach tests | 166 | Concurrent recompile and attached-program rejection |

Largest single functions in the test file:

- `fetch_jit_snapshot` - 98 LOC
- `test_wide_site_only_jit_diff` - 97 LOC
- `test_concurrent_recompile` - 83 LOC
- `find_site_native_range` - 65 LOC
- `load_program` - 60 LOC
- `find_rotate_site` - 59 LOC
- `run_program_and_read_result` - 55 LOC
- `test_recompile_after_attach` - 55 LOC
- `test_zero_rule_blob` - 54 LOC
- `main` - 53 LOC

## Essential logic vs boilerplate/bloat assessment

### No obvious dead code

I did not find clear dead code in the runtime kernel delta.

- `bpf_prog_jit_recompile()` is wired into `__sys_bpf()`
- `bpf_jit_rule_lookup()` is consumed by the x86 backend dispatcher
- The staged-image accessors in `bpf_jit_comp.c` are consumed from `jit_directives.c`
- `bpf_jit_supports_recompile()` is threaded through `filter.h`, weak core default, and x86 override
- `bpf_prog_kallsyms_replace()` is used by the staged-commit path

There are several very small wrapper helpers, but they are used:

- `bpf_jit_rule_form()` appears in both the control plane and backend as a tiny convenience wrapper
- The `bpf_jit_param_set_*()` helpers are tiny, but they keep canonical-param population uniform
- The staged-image accessors in `bpf_jit_comp.c` are thin, but they cleanly separate backend-owned staged state from generic control-plane code

### Where the LOC is genuinely heavy

- Rotate matching is the single biggest source of control-plane bulk: 461 LOC in `jit_directives.c`
- Generic validation plus logging in `jit_directives.c` is 657 LOC
- Header/UAPI duplication is real:
  - `include/linux/bpf_jit_directives.h` - 238 LOC
  - `include/uapi/linux/bpf.h` - 94 LOC
  - `tools/include/uapi/linux/bpf.h` - 95 LOC
  - Combined duplicated/interface footprint: 427 LOC
- The test harness is large because it carries its own policy-blob builder, snapshot reader, native-range diffing logic, and concurrency harness

### What looks like real bloat vs justified safety

Reasonable to call "bloat":

- Four separate rotate parsers instead of a more unified rotate matcher
- A lot of duplicated enum/ABI boilerplate between internal header, UAPI header, and tools mirror
- Many tiny glue wrappers whose individual value is low even if they are not dead

Harder to call bloat:

- Snapshot/rollback logic
- Kallsyms/extable replacement plumbing
- Side-effect and CFG validation
- Per-rule logging

Those sections are defensive, but they are doing real safety work. If you want to cut LOC without materially changing the feature set, the best targets are:

1. Unify the rotate-shape parsers
2. Collapse some tiny param/wrapper helpers
3. Reduce comment/debug verbosity
4. Generate or centralize mirrored UAPI/internal enum definitions where possible

## Bottom line

- Runtime kernel delta in `vendor/linux-framework`: 5800 added LOC
- Vendor-tree total including tools mirror: 5895 added LOC
- External test file requested separately: 2091 LOC
- `kernel/bpf/jit_directives.c` is the main control-plane cost center at 3114 LOC
- `arch/x86/net/bpf_jit_comp.c` is the backend cost center at 2182 added LOC
- `jit_directives.c` is roughly two-thirds essential logic and one-third scaffolding/validation/logging
- No clear dead code stood out; the branch is validation-heavy and interface-heavy more than it is unreachable-code-heavy
