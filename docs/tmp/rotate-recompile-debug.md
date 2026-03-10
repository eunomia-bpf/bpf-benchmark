# ROTATE recompile debug: `BPF_PROG_JIT_RECOMPILE` returns `-EINVAL`

## Repro

Running:

```bash
vng --run /home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/boot/bzImage --exec \
  "/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec run-kernel \
   --program /home/yunwei37/workspace/bpf-benchmark/micro/programs/rotate64_hash.bpf.o \
   --memory /home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/rotate64_hash.mem \
   --input-size 64 --io-mode staged --repeat 5 --recompile-rotate"
```

produces:

```text
recompile-rotate: found 115 rotate sites in xlated program (998 insns)
BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)
```

So userspace is now finding sites and building a policy blob correctly. The failure is kernel-side validation.

## Root cause

The syscall returns `-EINVAL` because **all ROTATE rules are rejected during per-rule validation**, leaving `policy->active_cnt == 0`.

Top-level failure path in `vendor/linux/kernel/bpf/jit_directives.c`:

```c
if (policy->active_cnt == 0) {
	bpf_jit_free_policy(policy);
	err = -EINVAL;
	goto out_put;
}
```

That is at lines `1434-1437`.

### Exact validator rejection

The ROTATE validator only accepts:

- `site_len == 4` for the classic `mov + lsh + rsh + or` form
- `site_len == 6` for the masked 32-bit `mov + and + rsh + mov + lsh + or` form

Relevant code in `vendor/linux/kernel/bpf/jit_directives.c:965-978`:

```c
if (rule->site_len == 4)
	shape_ok = bpf_jit_validate_rotate_4insn(insns, insn_cnt,
						  rule->site_start);
else if (rule->site_len == 6)
	shape_ok = bpf_jit_validate_rotate_6insn(insns, insn_cnt,
						  rule->site_start);
else
	return false;
```

This means every userspace-emitted `site_len == 5` ROTATE rule is rejected immediately.

### Why the 4-insn rules also fail

The userspace scanner now matches a commuted 4-insn form:

```text
mov, rsh, lsh, or
```

but the kernel validator for `site_len == 4` is hardcoded to:

```text
mov, lsh, rsh, or
```

Relevant check in `vendor/linux/kernel/bpf/jit_directives.c:821-845`:

```c
/* [1] lsh dst, N */
if (BPF_OP(lsh_insn->code) != BPF_LSH || BPF_SRC(lsh_insn->code) != BPF_K)
	return false;

/* [2] rsh tmp, (W - N) */
if (BPF_OP(rsh_insn->code) != BPF_RSH || BPF_SRC(rsh_insn->code) != BPF_K)
	return false;
```

For a real `mov, rsh, lsh, or` site, `insns[idx + 1]` is `RSH`, so the validator fails on the first `LSH` check.

## What userspace is emitting

Current scanner in `micro/runner/src/kernel_runner.cpp` emits three ROTATE families:

1. `site_len == 6`: masked 32-bit form
2. `site_len == 5`: 64-bit two-copy form
3. `site_len == 4`: commuted 64-bit form (`mov, rsh, lsh, or`) and classic form

The new 5-insn matcher is at `kernel_runner.cpp:807-845`:

```text
mov64 tmp, src
rsh64 tmp, 64-N
mov64 dst, src
lsh64 dst, N
or64  dst, tmp
```

This is the real clang-emitted pattern described in `docs/tmp/rotate-scanner-debug.md`.

## Why this is not fixable by “normalizing to a 4-insn rule” in userspace

This should be fixed in the kernel, not in the scanner.

Reasons:

1. A policy rule only carries `site_start` and `site_len`; the kernel re-validates against the real BPF instructions at that site.
2. A 5-insn site cannot be represented as a 4-insn site without leaving one original BPF instruction unconsumed.
3. The commuted 4-insn form also cannot be “normalized” away, because the kernel validator and emitter both assume the classic instruction order.
4. Filtering userspace back down to only kernel-supported classic 4-insn sites would avoid `-EINVAL`, but for `rotate64_hash` it would effectively regress back to near-zero or zero useful coverage.

So the correct fix is **kernel-side support for the real clang-emitted shapes**.

## Emitter also needs changes

Even if the validator accepted these shapes, the current x86 emitter would still decode them incorrectly.

`vendor/linux/arch/x86/net/bpf_jit_comp.c:2212-2234` only distinguishes:

- `site_len == 6`
- everything else treated as classic 4-insn

Relevant code:

```c
if (rule->site_len == 6) {
	...
} else {
	/* 4-insn classic rotate */
	const struct bpf_insn *mov_insn = &insns[idx];
	const struct bpf_insn *lsh_insn = &insns[idx + 1];
	...
	rot_amount = (u32)lsh_insn->imm;
}
```

Problems:

- For `site_len == 5`, `insns[idx + 1]` is `RSH`, not `LSH`, and the destination register is `mov2.dst_reg`, not `mov1.src_reg`.
- For commuted `site_len == 4`, `insns[idx + 1]` is also `RSH`, so `rot_amount` is decoded incorrectly.

So validator-only changes are insufficient. The x86 emitter must learn the same additional shapes.

## Conclusion

The `Invalid argument` is caused by this chain:

1. Userspace emits 115 ROTATE rules from real xlated code.
2. Kernel ROTATE validation only accepts classic `site_len == 4` and masked `site_len == 6`.
3. Real `rotate64_hash` sites are primarily:
   - `mov, rsh, lsh, or`
   - `mov, rsh, mov, lsh, or`
4. Those shapes all fail validation.
5. `policy->active_cnt` becomes `0`.
6. `bpf_prog_jit_recompile()` returns `-EINVAL`.

## Proposed fix

### Recommended fix: kernel-side

Update `vendor/linux/kernel/bpf/jit_directives.c` and `vendor/linux/arch/x86/net/bpf_jit_comp.c` together:

1. Extend ROTATE validation to accept the commuted 4-insn form:

```text
mov, rsh, lsh, or
```

with the same dataflow and complement check (`lsh_imm + rsh_imm == width`).

2. Add a new ROTATE validator for the 5-insn split-source form:

```text
mov, rsh, mov, lsh, or
```

with constraints:

- both `mov`s read the same source register
- `rsh` operates on the first temp
- `lsh` operates on the second temp / destination
- `or dst, tmp`
- `lsh_imm + rsh_imm == width`

3. Extend `emit_bpf_rotate()` to decode:

- classic 4-insn
- commuted 4-insn
- 5-insn split-source
- existing 6-insn masked-32

4. Prefer factoring shape decoding into a small shared helper that canonicalizes a rotate site into:

```text
{ width, src_reg, dst_reg, tmp_reg, ror_imm, needs_copy }
```

so validator and emitter stay aligned.

### Not recommended as the real fix: userspace-side filtering

Userspace can temporarily suppress unsupported 5-insn / commuted-4 rules to avoid the syscall returning `-EINVAL`, but that only hides the bug and loses the newly discovered rotate coverage. It does not solve the actual mismatch between real clang output and kernel ROTATE support.

