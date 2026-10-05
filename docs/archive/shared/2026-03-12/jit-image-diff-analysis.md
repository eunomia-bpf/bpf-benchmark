# JIT Image Diff Analysis

Date: 2026-03-13

## Scope

This report analyzes the x86 re-JIT path behind `BPF_PROG_JIT_RECOMPILE`, adds JIT image diff tests in `tests/kernel/test_recompile.c`, and records the VM test results.

VM command used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --rwdir tests/kernel -- \
  bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && sudo tests/kernel/build/test_recompile'
```

## 1. Re-JIT Code Path Analysis

### 1.1 Re-JIT recompiles the whole program image

`BPF_PROG_JIT_RECOMPILE` does not patch native bytes in place at individual sites.

- The syscall handler enters `bpf_prog_jit_recompile()` and calls `bpf_jit_recompile_prog_images()` in `vendor/linux-framework/kernel/bpf/jit_directives.c`.
- `bpf_jit_recompile_prog_images()` stages every active image/subprog with `bpf_int_jit_compile()`, then commits the staged image with `bpf_jit_recompile_commit()`.
- On x86, `bpf_int_jit_compile()` reruns the normal convergence loop and `do_jit()` still walks the full BPF instruction stream. Site directives only replace the emitter for the matching BPF insns; everything else still goes through the stock backend.

Conclusion:

- Re-JIT is a full-image recompile plus staged commit.
- It is not a site-local native patching mechanism.

### 1.2 Determinism of non-site emission

For non-site BPF instructions, the stock emitter path is deterministic with respect to:

- the same BPF insn stream
- the same backend decisions
- the same `addrs[]` layout
- the same final image base

But byte-for-byte JIT identity is not guaranteed if the backend emits a fresh image at a different address, because x86 helper calls and jumps use relative displacements. A pure no-op re-JIT therefore changed non-site bytes before the fix.

I fixed the `num_applied == 0` policy-noop case by short-circuiting staged-image commit:

- If a policy is present but no rule was applied, the kernel now aborts the staged image and keeps the pre-recompile image.
- This preserves exact JIT-image identity for the zero-applied-site case.

Relevant implementation points:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:3394-3400`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3679-3683`

### 1.3 Convergence loop and pass count

The x86 JIT still uses the normal multi-pass convergence loop:

- `bpf_int_jit_compile()` iterates until `proglen` stops changing, then allocates the final image and runs the final image pass.
- The x86 file already documents a no-convergence cycle caused by branch-size oscillation.

Because site directives change emitted native length, they can change:

- `proglen`
- `addrs[]`
- the pass at which the image converges
- whether a later branch is emitted as short or near form

Conclusion:

- The number of JIT passes can change when a site optimization changes native code length.

### 1.4 Layout shift, branch offsets, and alignment

Downstream control-flow encodings depend on `addrs[]`:

- conditional jumps compute `jmp_offset = addrs[target] - addrs[cur]`
- unconditional jumps do the same
- padding decisions (`INSN_SZ_DIFF`, `jmp_padding`) also depend on how the current pass length differs from the previous pass

So if a site shrinks or grows:

- all following instruction addresses may shift
- downstream branch immediates may change
- branch short/near selection may change
- inserted NOP padding and alignment may change

Conclusion:

- A site optimization can change non-site native bytes even if only one site is logically optimized.
- This is a real regression risk for loop alignment / hot path layout.

## 2. Test Changes

Added to `tests/kernel/test_recompile.c`:

- `fetch_jit_snapshot()`
  - dumps `jited_prog_insns` through `bpf_prog_info`
- `test_wide_zero_applied_jit_identity()`
  - loads `test_wide`
  - applies a policy that selects the stock wide-load lowering (`BPF_JIT_WMEM_BYTE_LOADS`)
  - compares pre/post JIT images byte-for-byte
- `test_wide_site_only_jit_diff()`
  - loads `test_wide`
  - applies one `WIDE_MEM` site with `BPF_JIT_WMEM_WIDE_LOAD`
  - finds the site’s native byte range by matching the stock and optimized x86 byte sequences in the JIT image
  - verifies the site bytes changed
  - verifies bytes after the site window are identical after compensating for the site-length delta
  - prints the first diff if non-site bytes changed

Note:

- `jited_line_info` did not line up cleanly with `jited_prog_insns` in this build, so the `test_wide` site-range check uses direct x86 byte-sequence matching instead of line-info-only mapping.

## 3. VM Test Results

Final VM result:

- 19 passed
- 1 failed

Observed output:

- `PASS Wide Zero-Applied JIT Identity: zero-applied wide re-JIT kept 149-byte image identical`
- `FAIL Wide Site-Only JIT Diff: non-site bytes changed outside site image 149->137 pre[0x33,0x45) post[0x33,0x39) [0x91]=ef -> [0x85]=3f`

There is also an existing unrelated behavior:

- `Zero-Rule Policy Blob No-Op` still reports `EINVAL: policy has no rules`

### 3.1 Zero-site identity

Status: pass

Interpretation:

- After the new no-applied short-circuit, a policy re-JIT that applies zero sites keeps the original live image.
- This gives exact byte identity for the no-op case.

### 3.2 Site-only diff

Status: fail

Observed site window:

- pre image site window: `[0x33, 0x45)` = 18 bytes
- post image site window: `[0x33, 0x39)` = 6 bytes
- image delta: `149 -> 137` bytes, i.e. `-12` bytes

Observed non-site drift:

- a byte outside the site window changed at pre offset `0x91` / post offset `0x85`

Inference from the location and the x86 code shape:

- This is most likely a downstream relative-displacement byte, not a byte inside the wide-load site itself.
- The likely source is the later helper-call / control-flow encoding whose displacement changed after the site shrank by 12 bytes.

This is an inference from the diff location plus the x86 backend structure, not from a full disassembly dump.

## 4. Code Layout Shift Analysis

Empirical result from `test_wide`:

- The optimized site shrank by 12 native bytes.
- The whole JIT image shrank by the same 12 bytes.
- At least one non-site byte changed after the site window.

What this means:

- The current implementation does not preserve the invariant “only site bytes change”.
- Full-image recompile allows the site’s size delta to propagate into later relative encodings.
- This is exactly the layout-shift hazard anticipated in the design review.

## 5. Fix Status and Next Steps

### 5.1 Implemented fix

Implemented now:

- zero-applied-site re-JIT keeps the pre-recompile image instead of committing a fresh equivalent image

This solves the byte-identity failure for the no-op policy case.

### 5.2 Remaining problem

Still unfixed:

- one-site optimized re-JIT can change non-site bytes outside the optimized window

This is inherent to the current “recompile the whole image and swap pointers” design.

### 5.3 Recommended fix directions

If the requirement is strict non-site byte identity, the current architecture is insufficient. Viable fixes are:

1. Patch-site design
   - Precompute exact native patch ranges for eligible sites.
   - Re-JIT only the site body and text-poke that range.
   - Require a fixed-width site contract or explicit local relocation handling.

2. Fixed-width site reservation
   - Reserve worst-case native width for each patchable site in the original JIT image.
   - Use NOP padding so optimized and stock variants have the same byte span.
   - Prevent downstream address drift by construction.

3. Relaxed contract
   - Keep full-image re-JIT.
   - Explicitly document that only semantic equivalence is guaranteed, not byte identity outside the site.
   - Then tests should check semantic preservation plus bounded layout drift, not exact non-site identity.

For BpfReJIT’s current validation goal, option 1 or 2 is the correct long-term direction.

## 6. Bottom Line

- Re-JIT currently recompiles the whole x86 JIT image.
- Zero-applied-site identity is now fixed and passes.
- One-site optimized re-JIT still causes non-site byte drift because the site shrink changes downstream layout.
- Therefore the current backend does **not** satisfy “site range changes, site range outside bytes remain identical” for `test_wide`.
