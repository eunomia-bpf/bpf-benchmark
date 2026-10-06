# ROTATE / WIDE_MEM Table-Driven Validators

## Goal

This turn converts the remaining linear validators for `ROTATE` and `WIDE_MEM`
to table-driven matching in `vendor/linux-framework/kernel/bpf/jit_validators.c`,
while leaving `COND_SELECT` and `BRANCH_FLIP` unchanged.

Constraints respected:

- no commit / no push
- report written here
- `COND_SELECT` / `BRANCH_FLIP` untouched
- net code reduction in `jit_validators.c`

## What Changed

### 1. ROTATE -> fixed-length table-driven patterns

`ROTATE` is now validated through declarative `bpf_jit_form_pattern` entries
instead of the previous handwritten `rotate_spec` interpreter.

Key points:

- Added two small matcher fields:
  - `CODE_CLASS`
  - `CODE_SRC`
- These are enough to describe the rotate shift slots declaratively while
  leaving the final `LSH/RSH` ordering check to one thin finalize callback.
- Implemented five descriptor-generated pattern families:
  - 32-bit in-place
  - 64-bit in-place
  - 64-bit two-copy
  - 32-bit masked in-place
  - 32-bit masked two-copy
- A shared `bpf_jit_finalize_rotate()` now handles:
  - swapped shift ordering where allowed
  - `rot + rsh == width`
  - masked 32-bit high-mask validation
  - canonical `amount` synthesis

Net effect:

- deleted the handwritten rotate matcher helpers
- kept semantics bounded to the same currently supported rotate shapes

### 2. WIDE_MEM -> bounded repeat matcher

`WIDE_MEM` is now on a table-driven linear-repeat path rather than a long
handwritten opcode parser.

Implementation shape:

- declared head/body chunk patterns:
  - head: `load` or `load + shift`
  - body: `load + or` or `load + shift + or`
- added a very small bounded matcher that walks those alternatives over the
  site and reuses the existing pattern check machinery
- retained a compact normalization step for:
  - contiguous byte offsets
  - unique offsets
  - little-endian vs big-endian shift interpretation
  - canonical param synthesis

This stays intentionally limited:

- linear only
- no control-flow modeling
- no attempt to generalize to `COND_SELECT` / `BRANCH_FLIP`

### 3. Non-goals preserved

No changes were made to:

- `COND_SELECT`
- `BRANCH_FLIP`

Those remain handwritten because they are diamond/control-flow shapes rather
than simple linear instruction sequences.

## LOC Result

Measured against `vendor/linux-framework` `HEAD` before this edit:

| File | Before | After | Delta |
|---|---:|---:|---:|
| `kernel/bpf/jit_validators.c` | 2056 | 1990 | -66 |

Extra diff stat for the touched file:

| File | Insertions | Deletions |
|---|---:|---:|
| `kernel/bpf/jit_validators.c` | 214 | 280 |

Conclusion:

- the new matcher support for `ROTATE`/`WIDE_MEM` amortizes
- `jit_validators.c` is now shorter than before this turn

## Validation

Executed with:

1. `source /home/yunwei37/workspace/.venv/bin/activate`
2. `make -C vendor/linux-framework kernel/bpf/jit_validators.o`
3. `make -C vendor/linux-framework -j$(nproc) bzImage`
4. `make vm-selftest`
5. `make vm-micro-smoke`
6. `git -C vendor/linux-framework diff --check -- kernel/bpf/jit_validators.c`

Results:

1. `kernel/bpf/jit_validators.o` built successfully
2. `bzImage` built successfully
3. `vm-selftest` passed: `PASS all 35 test(s)`
4. `vm-micro-smoke` passed and wrote:
   `micro/results/dev/vm_micro_smoke.json`
5. `git diff --check` reported no whitespace errors

## Assessment

This turn achieved the intended shape:

- `ROTATE` is on the same table-driven validator substrate used by the earlier
  simple forms
- `WIDE_MEM` is on a bounded linear-repeat table path, not a handwritten parser
- `COND_SELECT` and `BRANCH_FLIP` were correctly left alone
- `jit_validators.c` is a net reduction rather than a one-time LOC increase
