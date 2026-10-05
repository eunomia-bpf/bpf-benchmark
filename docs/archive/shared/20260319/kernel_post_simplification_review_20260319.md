# Kernel Post-Simplification Review (2026-03-19)

## Score

**8/10**

## Verdict

No P0/blocking issues found in the current post-simplification kernel tree. The main remaining correctness issue is in masked `ROTATE` validation: the spec-driven merge preserved an over-permissive mask check that can still accept a non-rotate sequence and lower it as a rotate.

The requested verification is green:

- `make -C vendor/linux-framework -j$(nproc) bzImage`: PASS
- `make vm-selftest`: PASS (`19/19`)
- `make vm-micro-smoke`: PASS
- `cmake --build scanner/build --target test_scanner && ./scanner/build/test_scanner`: PASS (`180`)

## Findings

### P1

#### 1. Masked `ROTATE` validation still accepts non-rotate low-mask sites

- Location:
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:948`
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:1002`
- Description:
  - `bpf_jit_rotate_mask_matches()` accepts both `low_mask` and `high_mask`.
  - For the accepted masked shape, the copied temporary always feeds the `rsh64 tmp, (32-N)` path. In that shape, only the **high-bit** mask preserves rotate semantics.
  - A sequence such as:
    - `mov64 tmp, src`
    - `and64 tmp, 0x00ffffff`
    - `rsh64 tmp, 24`
    - `lsh64 src, 8`
    - `or64 src, tmp`
    matches today, but computes `src << 8`, not a rotate-left by 8. The emitter then lowers it as a rotate (`ror width-N`), which is semantically different.
  - This weakens the Layer-2 canonical-form validation guarantee: a user-selected site can pass validation even though the accepted BPF shape is not actually equivalent to the emitted rotate.
- Suggested fix:
  - Tighten the masked rotate proof so the current accepted shape requires the **high-bit** mask only.
  - If a genuine low-mask rotate variant is intended, model it as a separate spec with its own proven shape and emitter semantics instead of accepting both masks in the same validator.
  - Add a negative selftest that feeds the low-mask sequence and expects rejection.

### P2

#### 2. Scanner masked-rotate discovery is broader than kernel acceptance

- Location:
  - `scanner/src/pattern_v5.cpp:1450`
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:1002`
- Description:
  - The scanner still emits masked `ROTATE` candidates for both `AND_K` and `AND_X` forms.
  - The kernel validator explicitly accepts `AND_K` only.
  - That means scanner coverage/counts for masked rotate are optimistic relative to what the kernel can actually activate, and a policy generated from an `AND_X` site will be deactivated kernel-side.
- Suggested fix:
  - Either remove the `AND_X` masked-rotate descriptors from the scanner, or add a proven kernel validator/emitter path for `AND_X`.
  - Whichever side is chosen, keep scanner and kernel acceptance criteria identical.

#### 3. Dead high-bit check in `bpf_prog_has_active_trampoline()`

- Location:
  - `vendor/linux-framework/kernel/bpf/trampoline.c:171`
  - `vendor/linux-framework/include/linux/bpf_verifier.h:927`
- Description:
  - `bpf_trampoline_unpack_key()` already masks the high bit out of `btf_id` (`key & 0x7FFFFFFF`).
  - The subsequent `(btf_id & 0x80000000)` test in `bpf_prog_has_active_trampoline()` is therefore unreachable.
  - This does not break the trampoline guard, but it is dead code and obscures the actual key semantics.
- Suggested fix:
  - Remove the dead bit test.
  - If the raw key-bit distinction is actually needed, inspect the raw key before unpacking instead of testing the already-masked `btf_id`.

## Criteria Review

- 1. Canonical-form validators fill `canonical_params` correctly for **7/8** forms.
  - `ROTATE` is the exception: the merged validator still over-accepts the masked low-mask variant described above.
- 2. Emitters correctly consume params only: **yes**
- 3. Spec-driven `ROTATE` unification is structurally correct for the 4 intended shapes, but the masked-mask proof remains too weak: **partial**
- 4. Overlap detection (`site_start < prev_end`) is correct and not off by one: **yes**
- 5. Trampoline guard covers the requested classes (`fentry/fexit/LSM/freplace/struct_ops/EXT`): **yes**
- 6. Reserved flags fail closed: **yes**
- 7. Form metadata table is correct for all 8 forms: **yes**
- 8. Three-layer security model (`bounds -> form validation -> fail-closed emit`) is intact overall: **yes**, with the `ROTATE` caveat above
- 9. Unchecked user input reaching emitters: **not found**
- 10. Error-path cleanup / dangling pointers: **looks correct in the reviewed paths**
- 11. `BRANCH_FLIP` body-copy cleanup: **correct**
- 12. Trivial wrappers still worth inlining: **no obvious remaining must-inline wrappers**
- 13. Dead code / unreachable paths: **one minor case** (`btf_id & 0x80000000`)
- 14. Further duplication to consolidate: **some repeated `image_prog` / `ksym_prog` selection remains, but it is cosmetic**
- 15. Verifier-log integration: **clean; no leftover custom-log references found**
- 16. All 8 forms still have validator + emitter pairs: **yes**
- 17. Scanner compatibility: **build/test green**, but masked-rotate discovery is broader than kernel acceptance
- 18. `tests/kernel/test_recompile.c` compatibility: **yes**

## Positive Changes From The Simplification

- Reusing verifier-log infrastructure is a good cleanup.
  - The bespoke JIT recompile log context/plumbing is gone.
  - No leftover references to the old logging implementation remain.
- The param-only emitter contract is now cleanly enforced.
  - `ZERO_EXT_ELIDE` rebuilds the ALU32 insn from normalized params.
  - `BRANCH_FLIP` consumes copied body fragments from normalized params instead of raw site pointers.
- The form metadata table is a good consolidation.
  - Native-choice masks, CPU support checks, side-effect policy, names, and validator dispatch are all centralized and easier to audit.
- The `ROTATE` spec-driven merge is a substantial LOC reduction without obvious regression in the four intended shape mappings.
- Overlap validation and branch-flip body cleanup are materially better than the earlier state.

## Residual Risk

Runtime kernel selftest coverage is still concentrated on `COND_SELECT`, `WIDE_MEM`, and `ROTATE`. The remaining forms now read coherently and the scanner tests are green, but there is still no equivalent end-to-end kernel selftest for `ADDR_CALC`, `BITFIELD_EXTRACT`, `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`, and `BRANCH_FLIP`.
