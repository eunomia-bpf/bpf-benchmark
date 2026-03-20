# rotate_dense Regression Debug 2026-03-19

## Executive Summary

- I could **not** reproduce the reported `rotate_dense` regression on the current `vendor/linux-framework` source + `bzImage`.
- The negative run in `docs/tmp/micro_post_p0p1p2_fix_20260319.md` was generated at `2026-03-20T00:45:06+00:00` (`2026-03-19 17:45:06 -0700`), but the current VM kernel image was built later at `2026-03-19 18:09:09 -0700`.
- The current image repeatedly shows `rotate_dense` still improving after recompile, which strongly indicates the documented regression came from an **older pre-18:09 kernel image**, not from the current built tree.
- `rotate_dense` rules are still applied: the recompile path keeps `256/256` rotate rules, and the recompiled JIT image shrinks from `10198` bytes to `7638` bytes.
- I audited the P0/P1/P2 changes (trampoline guard, reserved flags, overlap detection, branch-flip body normalization/copy). I did **not** find a remaining correctness bug in those areas on the current tree.

## Context

- Project context: `docs/kernel-jit-optimization-plan.md`
- Regression input: `docs/tmp/micro_post_p0p1p2_fix_20260319.md`
- Kernel commit at `HEAD`: `b50fd6279`
- Current worktree state: dirty on top of `b50fd6279`
  - `arch/x86/net/bpf_jit_comp.c`
  - `include/linux/bpf.h`
  - `include/linux/bpf_jit_directives.h`
  - `kernel/bpf/jit_directives.c`
- Current `bzImage` mtime: `2026-03-19 18:09:09 -0700`

## Investigation

### 1. Reviewed the P0/P1/P2 fix commit

`git diff HEAD~1 HEAD` shows four change buckets:

- `ZERO_EXT_ELIDE` emitter params converted from internal pointers to scalarized canonical params.
- `BRANCH_FLIP` normalization rewritten to copy validated body slices into rule-owned buffers.
- Policy parsing hardened:
  - fail closed on non-zero header flags
  - sort rules by `site_start`
  - reject overlapping sites
- Recompile guard extended to reject trampoline-linked programs that need trampoline regeneration.

None of those committed changes directly touches `ROTATE` validator/emitter logic.

### 2. Checked whether `rotate_dense` rules still apply

On the current kernel image:

- `rotate_dense` recompile path still selects `256/256` rotate rules.
- `rotate64_hash` still selects `116/116` rotate rules.
- `rotate_dense` policy contains only rotate sites; there are no branch-flip rules in `micro/policies/rotate_dense.yaml`.

Evidence from a direct VM run of `micro_exec`:

- stderr: `recompile-policy: kept 256 of 256 eligible rules`
- JSON summary:
  - `rotate_sites = 256`
  - `applied = true`
  - `policy_bytes = 3104`

So the issue is **not** “rules stopped applying”.

### 3. Checked overlap detection

Current overlap validation:

- sorts rules by `site_start`
- computes half-open intervals `[site_start, site_start + site_len)`
- rejects overlap when `rule->site_start < prev_end`

This is the correct predicate for sorted half-open intervals. Adjacent rules where `rule->site_start == prev_end` are allowed. I did not find an off-by-one bug here.

Also, `rotate_dense` uses only rotate rules and the policy is accepted with all `256` sites active, so overlap validation is not rejecting this policy.

### 4. Checked BRANCH_FLIP body copy / normalization

`rotate_dense` does not use branch-flip sites, but I still audited the new code:

- validator duplicates `body_a` and `body_b` with `kmemdup()`
- failure path frees partially allocated buffers
- policy free path releases both copied bodies via `bpf_jit_rule_release()`
- policy allocation switched to `kvzalloc()`, so untouched pointers are zero-initialized before free

I did not find a memory-safety or adjacent-rule corruption bug in the current implementation.

### 5. Compared JIT output

I dumped stock and recompiled JIT images for `rotate_dense` on the current VM kernel.

Artifacts:

- stock:
  - `docs/tmp/rotate_dense_debug_20260319/stock/rotate_dense.kernel.bin`
  - `docs/tmp/rotate_dense_debug_20260319/stock/rotate_dense.stock.xlated.bin`
- recompile:
  - `docs/tmp/rotate_dense_debug_20260319/recompile/rotate_dense.kernel.bin`
  - `docs/tmp/rotate_dense_debug_20260319/recompile/rotate_dense.recompile.xlated.bin`

Findings:

- xlated program size is unchanged: `22368` bytes in both cases
- native JIT size shrinks materially:
  - stock: `10198` bytes
  - recompile: `7638` bytes
- the recompiled native image contains dense `ror` instructions across the hot path
- direct manual run sample:
  - stock: `344 ns`
  - recompile: `213 ns`

This confirms the ROTATE lowering is active and producing the expected native pattern on the current image.

## Reproduction Results

### Smoke

`make vm-micro-smoke`

- passed
- `cmov_dense` still applies
- no regression signal relevant to `rotate_dense` because the smoke target does not include it

### Targeted Quick Run

`make vm-micro BENCH="rotate_dense rotate64_hash" ITERATIONS=1 WARMUPS=0 REPEAT=10`

- `rotate_dense`: `140 ns -> 138 ns`
- `rotate64_hash`: `105 ns -> 72 ns`

### Targeted Authoritative Runs

Run 1:

- command: `make vm-micro BENCH="rotate_dense rotate64_hash" ITERATIONS=5 WARMUPS=3 REPEAT=500`
- `rotate_dense`: `208 ns -> 177 ns` (`+17.5%`)
- `rotate64_hash`: `92 ns -> 68 ns` (`+35.3%`)

Run 2:

- same command
- `rotate_dense`: `199 ns -> 186 ns` (`+7.0%`)
- `rotate64_hash`: `88 ns -> 67 ns` (`+31.3%`)

Both reruns are positive. I could not reproduce the documented `177 ns -> 214 ns` regression on the current image.

### Selftest

`make vm-selftest`

- result: `PASS all 19 test(s)`

Relevant passing cases:

- `Rotate Recompile Preserves Result`
- `Repeated Recompile Succeeds`
- `Recompile After Attach Works`

## Audit of P0/P1/P2 Changes

### Trampoline Guard

Current status: looks correct on the current tree.

- It blocks trampoline-linked cases that require trampoline regeneration.
- It does not block ordinary XDP attach/recompile; `Recompile After Attach Works` still passes.
- I did not find evidence that it affects `rotate_dense`.

### Reserved Flags Fail-Closed

Current status: correct.

- `if (hdr->flags) -> -EINVAL`
- this is the right fail-closed behavior
- no impact on `rotate_dense` because its generated policy uses zero flags

### Overlap Detection

Current status: correct.

- half-open interval math is right
- no off-by-one seen
- `rotate_dense` still activates all `256` sites, so this path is not rejecting valid dense rotate rules

### BRANCH_FLIP Body Normalization / Copy

Current status: no bug found.

- copied bodies are freed
- partial-allocation failure is handled
- unrelated to `rotate_dense` because its policy is rotate-only

## Root Cause Conclusion

The live `rotate_dense` regression is **already fixed** in the current built kernel image.

The most plausible explanation for the negative result in `docs/tmp/micro_post_p0p1p2_fix_20260319.md` is:

1. that run used an **older kernel image**
2. the current dirty-tree source was built later into the `18:09 -0700` `bzImage`
3. the current image repeatedly restores the expected positive `rotate_dense` result

In short:

- I did **not** find a remaining live bug in the current code/image.
- I did **not** find evidence that overlap detection, reserved flags, trampoline guard, or branch-flip body normalization are causing a current `rotate_dense` regression.
- No additional kernel code change was required in this turn because the current source + built image already behaves correctly.

## Verification Summary

- `make vm-micro-smoke`: pass
- `make vm-selftest`: `19/19` pass
- `make vm-micro BENCH="rotate_dense rotate64_hash" ITERATIONS=5 WARMUPS=3 REPEAT=500`: positive twice
- direct JIT dump:
  - `rotate_dense` rule selection: `256/256`
  - native code size: `10198 -> 7638`
  - recompiled image contains native rotate instructions
