# Extensibility Quantification: v4 vs v5

## Scope

This note quantifies the implementation cost of adding a new optimization pattern in:

- `v4`: closed kernel enum + handwritten validator/emitter path
- `v5`: declarative userspace pattern + canonical binding

The numbers below are intended for the paper as concrete extensibility evidence.

## Methodology

- Metric: physical LOC touched/sliced, including comments and enum/struct lines. This matches `git diff --numstat` style accounting better than trying to guess "logical" LOC.
- `v4` family rows are anchored in actual git history:
  - kernel history comes from the nested repo `vendor/linux-framework`
  - tracked v4 userspace history comes from the top-level repo (`micro/runner`, `micro/tools`)
- Mixed commits were **not** counted wholesale when they contained shared framework work. Instead, I used git history to find the relevant commits, then counted only the family-specific slices (enum/native values, validator, emitter, dispatcher, scanner/plumbing).
- `v5` rows use direct code-slice counts from the current working tree because the `scanner/` implementation is currently untracked in this checkout, so there is no standalone git history to mine for `pattern_v5.cpp`.
- `v5: new canonical form` is modeled with the existing `ADDR_CALC` canonical form, counting only the pieces needed for a new `BPF_JIT_RK_PATTERN` canonical target. I intentionally exclude legacy v4-only `BPF_JIT_RK_ADDR_CALC` glue from that row.

## Summary Table

| Scenario | Kernel LOC | Userspace LOC | Total | Kernel files touched |
|----------|-----------:|--------------:|------:|---------------------:|
| v4: add `WIDE_MEM` | 179 | 98 | 277 | 3 |
| v4: add `ROTATE` (final Round-3 landed support) | 670 | 348 | 1018 | 3 |
| v5: add new `ROTATE` variant, same canonical form | 0 | 32 | 32 | 0 |
| v5: add new canonical form (`ADDR_CALC`-like) | 111 | 55 | 166 | 3 |

## Per-Scenario Breakdown

### 1. v4: add `WIDE_MEM`

History anchors:

- Kernel intro: `2793b136988d` (`v4: extensible JIT policy framework with BPF_PROG_JIT_RECOMPILE`)
- Userspace intro: `a6cb8739a0c3` (`v4 userspace: BPF_PROG_JIT_RECOMPILE support + policy blob builder`)

Kernel LOC = 179

- `vendor/linux-framework/include/uapi/linux/bpf.h`: 6
  - `BPF_JIT_RK_WIDE_MEM`
  - `enum bpf_jit_wide_mem_native`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`: 110
  - `bpf_jit_validate_wide_mem_rule()` slice: 105
  - `BPF_JIT_RK_WIDE_MEM` validator dispatch in `bpf_jit_validate_rule()`: 5
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`: 63
  - `emit_bpf_wide_load()`: 51
  - `BPF_JIT_RK_WIDE_MEM` dispatcher case in `bpf_jit_try_emit_rule()`: 12

Userspace LOC = 98

- `micro/tools/build_policy_blob.py`: 98
  - WIDE_MEM constants: 3
  - `find_wide_mem_sites()`: 86
  - CLI / rule emission for `--wide-all`: 9

Notes:

- This row counts the incremental family-specific work, not the shared `BPF_PROG_JIT_RECOMPILE` bootstrap in the same commit.
- I do **not** count the later high-byte-first WIDE_MEM extension from `3d3587b8c47a`; this row is the initial family-add cost.

### 2. v4: add `ROTATE`

History anchors:

- Initial kernel landing: `d474b80224a6` (`v4 JIT policy: fix review issues R1/R3/R5/R6/R7`)
- Kernel expansion to final multi-pattern support: `3d3587b8c47a` (`v4 Round 3: ROTATE multi-pattern support...`)
- Follow-up hardening: `8e9cfbc1e1a2` (`v4: harden 5-insn masked rotate validator field checks`)
- Userspace landing: `5af1fd131385` (`v4 Round 3: ALL 4 directive families active...`)

Kernel LOC = 670

- `vendor/linux-framework/include/uapi/linux/bpf.h`: 8
  - `BPF_JIT_RK_ROTATE`
  - `enum bpf_jit_rotate_native`
  - `BPF_JIT_X86_BMI2`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`: 489
  - rotate validator block (`bpf_jit_validate_rotate_4insn`, `_5insn`, `_5insn_masked`, `_6insn`, wrapper): 481
  - rotate native-choice / BMI2 gating hooks: 6
  - `BPF_JIT_RK_ROTATE` validator dispatch: 2
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`: 173
  - `emit_bpf_rotate()`: 154
  - `BPF_JIT_CF_ROTATE` / legacy rotate dispatcher arm in `bpf_jit_try_emit_rule()`: 19

Userspace LOC = 348

- `micro/runner/include/micro_exec.hpp`: 2
  - `recompile_rotate`
  - `recompile_rotate_rorx`
- `micro/runner/src/common.cpp`: 16
  - CLI usage string
  - CLI flag parsing / validation for rotate options
- `micro/runner/src/kernel_runner.cpp`: 330
  - rotate constants / BMI2 flag: 6
  - `cpu_features_required` in `policy_rule`: 1
  - `find_rotate_sites_xlated()`: 310
  - rotate-specific recompile plumbing (`do_recompile_rotate`, rule insertion, logging): 13

Notes:

- This row reflects the **final landed Round-3 ROTATE support**, not only the first 4-insn prototype. That is the stronger paper comparison because it is the version that actually covers the clang-emitted rotate families used in evaluation.
- Lower-bound reference: the first 4-insn-only kernel landing in `d474b80224a6` is much smaller (roughly 317 kernel LOC by the same physical-slice method), but it was not the version ultimately used for the evaluation.

### 3. v5: add new `ROTATE` variant, same canonical form

Implementation basis:

- `scanner/src/pattern_v5.cpp`
- same canonical form: `BPF_JIT_CF_ROTATE`
- same site-length whitelist: current rotate whitelist already accepts `site_len` 4/5/6

Kernel LOC = 0

- No kernel changes are needed as long as:
  - the new descriptor still lowers to `BPF_JIT_CF_ROTATE`
  - its bindings fit the existing rotate canonical parameters
  - `site_len` stays within the existing whitelist

Userspace LOC = 32

- `scanner/src/pattern_v5.cpp`: 32
  - representative descriptor block: `rotate5_two_copy` at lines 607-637 = 31
  - one registration line in `descs.push_back(rotate5_two_copy());` at line 729 = 1

Why this is the right comparison:

- The descriptor itself already contains the pattern array, constraint list, and canonical bindings.
- No new kernel enum, validator, emitter, or dispatcher arm is required.

### 4. v5: add new canonical form (`ADDR_CALC`-like)

Implementation basis:

- modeled with the existing `ADDR_CALC` canonical form in the current working tree
- counts only the pieces needed for a new v5 canonical target under `BPF_JIT_RK_PATTERN`

Kernel LOC = 111

- `vendor/linux-framework/include/uapi/linux/bpf.h`: 12
  - `BPF_JIT_CF_ADDR_CALC`: 1
  - `enum bpf_jit_addr_calc_native`: 5
  - `enum bpf_jit_addr_calc_param`: 6
- `vendor/linux-framework/kernel/bpf/jit_directives.c`: 19
  - `BPF_JIT_CF_ADDR_CALC` in `bpf_jit_native_choice_valid()`: 3
  - `BPF_JIT_CF_ADDR_CALC` in `bpf_jit_pattern_rule_shape_valid()`: 2
  - `BPF_JIT_CF_ADDR_CALC` in `bpf_jit_binding_param_valid()`: 2
  - `BPF_JIT_CF_ADDR_CALC` case in `bpf_jit_validate_canonical_params()`: 12
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`: 80
  - `emit_canonical_lea_fusion()`: 64
  - `BPF_JIT_CF_ADDR_CALC` dispatcher arm in `bpf_jit_try_emit_rule()`: 16

Userspace LOC = 55

- `scanner/include/bpf_jit_scanner/pattern_v5.hpp`: 11
  - `BPF_JIT_CF_ADDR_CALC`: 1
  - `BPF_JIT_ACALC_*` params: 6
  - `V5Family::AddrCalc`: 1
  - `scan_lea`: 1
  - `lea_sites`: 1
  - `build_v5_lea_descriptors()` declaration: 1
- `scanner/src/pattern_v5.cpp`: 44
  - `v5_family_name()` addr-calc case: 2
  - `build_v5_lea_descriptors()`: 37
  - `scan_v5_builtin()` descriptor insertion: 3
  - `scan_v5_builtin()` summary counter case: 2

## Repro Commands

Kernel history:

```bash
git -C vendor/linux-framework log --oneline -- \
  include/uapi/linux/bpf.h \
  kernel/bpf/jit_directives.c \
  arch/x86/net/bpf_jit_comp.c
```

Key history anchors:

```bash
git -C vendor/linux-framework show --stat --numstat 2793b1369
git -C vendor/linux-framework show --stat --numstat d474b8022
git -C vendor/linux-framework show --stat --numstat 3d3587b8c
git -C vendor/linux-framework show --stat --numstat 8e9cfbc1e
git show --stat --numstat a6cb873
git show --stat --numstat 5af1fd1
```

Representative slice inspection:

```bash
git -C vendor/linux-framework show 2793b1369:kernel/bpf/jit_directives.c | nl -ba | sed -n '520,646p'
git -C vendor/linux-framework show 2793b1369:arch/x86/net/bpf_jit_comp.c | nl -ba | sed -n '2051,2159p'
git show a6cb873:micro/tools/build_policy_blob.py | nl -ba | sed -n '254,339p'

git -C vendor/linux-framework show d474b8022:include/uapi/linux/bpf.h | nl -ba | sed -n '1490,1524p'
git -C vendor/linux-framework show d474b8022:kernel/bpf/jit_directives.c | nl -ba | sed -n '710,941p'
git show 5af1fd1:micro/runner/src/kernel_runner.cpp | nl -ba | sed -n '702,1011p;1395,1460p'

nl -ba scanner/src/pattern_v5.cpp | sed -n '607,637p;729p'
nl -ba scanner/include/bpf_jit_scanner/pattern_v5.hpp | sed -n '18,22p;70,75p;89,94p;170,191p'
nl -ba scanner/src/pattern_v5.cpp | sed -n '407,420p;737,800p;817,829p'
nl -ba vendor/linux-framework/include/uapi/linux/bpf.h | sed -n '1500,1530p;1610,1615p'
nl -ba vendor/linux-framework/kernel/bpf/jit_directives.c | sed -n '523,554p;1634,1642p;1780,1822p'
nl -ba vendor/linux-framework/arch/x86/net/bpf_jit_comp.c | sed -n '2658,2721p;2867,2882p'
```

## Takeaway

The extensibility gap is large and clear:

- In `v4`, each new family still means touching kernel UAPI, validator logic, x86 emission, and userspace scanning/plumbing.
- In `v5`, adding another variant of an existing canonical form collapses to a small userspace-only descriptor edit.
- Even when `v5` needs a brand-new canonical form, the kernel delta is still much smaller than the fully handwritten `v4` family path because the pattern matching/binding machinery is shared.
