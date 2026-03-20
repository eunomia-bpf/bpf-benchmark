# ZERO_EXT_ELIDE deletion analysis

Date: 2026-03-20
Workspace: `/home/yunwei37/workspace/bpf-benchmark`

## Bottom line

`ZERO_EXT_ELIDE` can be removed as a feature implementation from this repo without breaking normal x86_64 or arm64 recompile behavior, **provided the full stack is cleaned up**:

- kernel validator/emitter support
- scanner family support
- selftests
- corpus/micro bookkeeping

`BRANCH_FLIP` does **share** the x86 linear replay helpers, so those helpers must stay. Only the `ZERO_EXT_ELIDE`-specific wrapper and call sites are removable.

## Short answer

- Can it be safely deleted? `Yes`, in-tree, if removal is full-stack.
- Would deleting only the x86 emitter case be enough? `No`.
- Would deleting it break `BRANCH_FLIP`? `No`, if the shared replay helpers stay.
- Any active benchmark/policy dependency? `No`.
- Any historical/generated artifact dependency? `Yes`, but only as stale data/comments/counters, all zero-only.
- Any ABI caveat? `Yes`: removing or renumbering UAPI enum value `6` is an ABI change. If ABI stability matters, deprecate/reserve it instead of renumbering.

## Why the kernel-side feature is effectively dead

### 1. x86_64 does not ask the verifier to insert zext tails

Relevant code:

- `vendor/linux-framework/kernel/bpf/core.c:3165-3168`
- `vendor/linux-framework/kernel/bpf/verifier.c:22436-22447`
- `vendor/linux-framework/kernel/bpf/verifier.c:26102-26105`

What that means:

- The verifier only inserts explicit zext tails when `bpf_jit_needs_zext()` is true, or for the special `cmpxchg` case.
- The default weak implementation returns `false`.
- The x86_64 recompile path under review uses `arch/x86/net/bpf_jit_comp.c`, not the 32-bit JIT file.

`ZERO_EXT_ELIDE` specifically requires a 2-insn shape: `ALU32 op` + `zext tail`:

- `vendor/linux-framework/kernel/bpf/jit_validators.c:1187-1194`

So on x86_64, verifier-inserted zext tails do not create sites in the normal path.

### 2. arm64 has no ZERO_EXT_ELIDE emitter

Relevant code:

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:918-942`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3920-3934`

What that means:

- `bpf_jit_try_emit_rule()` has no `BPF_JIT_CF_ZERO_EXT_ELIDE` case.
- `bpf_jit_arch_form_supported()` on arm64 returns `false` for forms outside the implemented subset.
- The existing selftest already treats arm64 ZERO_EXT_ELIDE as unsupported.

### 3. No benchmark or corpus data shows real sites

Search results:

- `rg 'zero_ext' config/micro_pure_jit.yaml micro/programs/ micro/policies/` returned no actual family/policy/program use.
- The only config hit was a hypothesis string in `config/micro_pure_jit.yaml:609`, inside the `mixed-width` benchmark, not a `zero-ext` benchmark.
- Search for nonzero ZERO_EXT counts across `corpus/`, `micro/`, `config/`, `tests/`, and `scanner/` returned no matches.

Supporting evidence:

- `config/micro_pure_jit.yaml:604-614`
- `micro/README.md:9`
- `corpus/policies/...` comments consistently say `zero-ext=0`
- `corpus/results/...` and `micro/results/...` consistently show `zero_ext_sites: 0` or logs such as `no zero_ext_elide sites found`

I also checked for nonzero occurrences with:

```bash
rg -n -S 'zero_ext_sites"\s*:\s*[1-9]|zero-ext=[1-9]|ZERO_EXT_ELIDE"\s*:\s*[1-9]|ZERO_EXT_ELIDE\s*[:=]\s*[1-9]' corpus/ micro/ config/ tests/ scanner/
```

That search returned no matches.

## BRANCH_FLIP impact

### Shared x86 replay subsystem: YES

`BRANCH_FLIP` uses the shared x86 linear replay helpers:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2501` `emit_bpf_alu32_insn`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2577-2643` `emit_bpf_end_insn`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2645-2842` `emit_bpf_alu64_insn`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2844-2910` `emit_linear_bpf_insn`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2912-3049` `measure_branch_flip_body`, `emit_branch_flip_body`, `emit_canonical_branch_flip`

How the dependency works:

- `emit_canonical_branch_flip()` calls `measure_branch_flip_body()` and `emit_branch_flip_body()`.
- Both of those call `emit_linear_bpf_insn()`.
- `emit_linear_bpf_insn()` dispatches ALU32 bodies through `emit_bpf_alu32_insn()`.

So the shared replay subsystem is **not** ZERO_EXT-only.

### ZERO_EXT-specific x86 code: NO shared dependency

The x86 ZERO_EXT implementation itself is tiny:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2503-2516` `emit_canonical_zero_ext_elide`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3184-3189` rule dispatch case

This wrapper reconstructs the original ALU32 instruction and emits it without the redundant tail. `BRANCH_FLIP` does not call this wrapper.

## What can be removed vs what must stay

### Must stay for BRANCH_FLIP

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2501`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2577-2643`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2645-2842`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2844-2910`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2912-3049`

That shared replay subsystem is about `523 LOC` for the generic replay helpers alone:

- `2311-2501` = 191
- `2577-2643` = 67
- `2645-2842` = 198
- `2844-2910` = 67

Total = `523`

### Can be removed as ZERO_EXT-specific

- x86 ZERO_EXT wrapper and switch case
- generic validator shape/metadata for ZERO_EXT
- ZERO_EXT UAPI/header constants
- scanner family support
- kernel selftest and dedicated BPF program
- corpus/micro bookkeeping for the family

## Maintained-source reference list

This is the complete maintained-source reference set I found.

### Kernel / ABI / arch code

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2503-2516`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3184-3189`
- `vendor/linux-framework/kernel/bpf/jit_validators.c:1147-1232`
- `vendor/linux-framework/kernel/bpf/jit_validators.c:1613-1617`
- `vendor/linux-framework/include/uapi/linux/bpf.h:1493`
- `vendor/linux-framework/include/uapi/linux/bpf.h:1524-1527`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h:1493`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h:1524-1527`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:77-83`

### Scanner

- `scanner/include/bpf_jit_scanner/types.h:26`
- `scanner/include/bpf_jit_scanner/types.h:41`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp:21`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp:49`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp:62`
- `scanner/src/cli.cpp:160`
- `scanner/src/cli.cpp:963`
- `scanner/src/cli.cpp:1013`
- `scanner/src/cli.cpp:1090`
- `scanner/src/cli.cpp:1108-1109`
- `scanner/src/cli.cpp:1260-1261`
- `scanner/src/pattern_v5.cpp:356-357`
- `scanner/src/pattern_v5.cpp:1177-1178`
- `scanner/src/pattern_v5.cpp:1220-1222`
- `scanner/src/pattern_v5.cpp:1736-1808`
- `scanner/src/pattern_v5.cpp:1934-1935`
- `scanner/src/pattern_v5.cpp:1983-1984`
- `scanner/src/policy_config.cpp:144-145`
- `scanner/src/policy_config.cpp:431-432`
- `scanner/src/policy_config.cpp:484`
- `scanner/README.md:111`
- `scanner/README.md:126`
- `scanner/README.md:157`
- `scanner/tests/test_scanner.cpp:391-435`
- `scanner/tests/test_scanner.cpp:951`

### Kernel selftests

- `tests/kernel/progs/test_zero_ext_elide.bpf.c:1-39`
- `tests/kernel/test_recompile.c:73`
- `tests/kernel/test_recompile.c:1510-1550`
- `tests/kernel/test_recompile.c:1807-1820`
- `tests/kernel/test_recompile.c:1989-1994`
- `tests/kernel/test_recompile.c:3435-3490`
- `tests/kernel/test_recompile.c:3942`

### Corpus / micro / automation / docs

- `micro/README.md:9`
- `config/micro_pure_jit.yaml:609` (hypothesis string only; not a zero-ext benchmark)
- `corpus/auto_tune.py:62`
- `corpus/directive_census.py:34`
- `corpus/directive_census.py:38`
- `corpus/directive_census.py:469`
- `corpus/directive_census.py:555`
- `corpus/driver.py:75`
- `corpus/modes.py:140`
- `corpus/modes.py:150`
- `corpus/modes.py:213`
- `corpus/modes.py:263-266`
- `corpus/modes.py:276`

## Generated / historical references

There are also many generated or archival references outside maintained source:

- `998 files` under `corpus/policies/`, `corpus/results/`, and `micro/results/`
- These are all zero-only mentions:
  - `zero_ext_sites: 0`
  - `zero-ext=0`
  - `ZERO_EXT_ELIDE: 0`
  - log lines like `recompile-zero-ext: no zero_ext_elide sites found`

These are not runtime dependencies, but they would become stale after removal and should be regenerated or left as historical archives.

Representative examples:

- `corpus/policies/.../*.policy.yaml:6`
- `corpus/results/archive/corpus-8families-persection.json:230` and many similar lines
- `corpus/results/...json` entries containing `zero_ext_sites: 0`
- `micro/results/...json` entries containing `zero_ext_sites: 0`

I counted the generated/historical files with:

```bash
rg -l -S 'zero_ext_sites|ZERO_EXT_ELIDE|zero-ext' corpus/policies corpus/results micro/results | wc -l
```

Result: `998`

## What code would be removed

Approximate maintained-source cleanup if the feature is deleted end-to-end:

| Area | File/range(s) | Est. LOC |
|---|---|---:|
| x86 ZERO_EXT wrapper | `arch/x86/net/bpf_jit_comp.c:2503-2516`, `3184-3189` | 20 |
| Generic ZERO_EXT validator | `kernel/bpf/jit_validators.c:1147-1232`, `1613-1617` | 91 |
| UAPI / internal param enums | `include/uapi/linux/bpf.h`, `tools/include/uapi/linux/bpf.h`, `include/linux/bpf_jit_directives.h` | 17 |
| Scanner headers | `scanner/include/...` refs above | 5 |
| Scanner sources | `scanner/src/cli.cpp`, `pattern_v5.cpp`, `policy_config.cpp` refs above | 97 |
| Scanner docs/tests | `scanner/README.md`, `scanner/tests/test_scanner.cpp` | 49 |
| Kernel selftests | `tests/kernel/test_recompile.c`, `tests/kernel/progs/test_zero_ext_elide.bpf.c` | 158 |
| Corpus/micro bookkeeping | `corpus/*.py`, `micro/README.md` | 15 |
| Total maintained-source removal | all above | about 452 |

This estimate excludes:

- regenerated `corpus/results/*`
- regenerated `micro/results/*`
- regenerated `corpus/policies/*`

## Would deleting ZERO_EXT_ELIDE break anything?

### If you remove the full stack

Likely no functional regression in the current repo:

- x86_64 does not generate verifier zext tails for normal ALU32 lowering.
- arm64 does not implement the form.
- no benchmark, policy, or result shows a nonzero ZERO_EXT site.
- `BRANCH_FLIP` does not depend on the ZERO_EXT-specific wrapper.

### If you remove only the kernel x86 emitter case

Yes, repo breakage is likely:

- scanner builds/tests would still reference the family
- kernel selftests would still try to compile/apply it
- corpus scripts would still track `zero_ext_sites`
- policy/CLI family parsing would still accept `zero-ext`

### ABI caveat

This is the only real reason to avoid deleting it "entirely":

- `BPF_JIT_CF_ZERO_EXT_ELIDE = 6` is in UAPI headers
- deleting and renumbering `ENDIAN_FUSION` and `BRANCH_FLIP` would change the userspace ABI

Recommendation:

- delete the implementation and all in-tree users
- keep canonical form id `6` reserved/deprecated in UAPI instead of renumbering

## Recommended deletion plan

1. Delete ZERO_EXT implementation and validation:
   - x86 wrapper/switch case
   - generic validator shape/meta

2. Delete scanner support:
   - family enum/constants
   - descriptors
   - CLI flag
   - policy parsing and summary counters
   - scanner tests/docs

3. Delete selftest coverage:
   - `test_zero_ext_elide.bpf.c`
   - ZERO_EXT-specific code in `test_recompile.c`

4. Delete corpus/micro family bookkeeping:
   - `zero-ext` family aliases/counters/docs

5. Do **not** delete the shared x86 replay helpers used by `BRANCH_FLIP`.

6. If ABI compatibility matters, leave UAPI id `6` reserved instead of reusing it.

## Final verdict

`ZERO_EXT_ELIDE` looks removable as dead feature/bloat in this tree.

The safe interpretation is:

- `Yes, delete the feature.`
- `No, do not delete the shared x86 replay subsystem.`
- `No, do not renumber the UAPI form ids unless ABI churn is acceptable.`
