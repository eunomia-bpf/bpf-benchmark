# JIT Pass Implementation Detail

This note is based on:

- `docs/tmp/bpf-jit-advisor-v5r2.md`, especially sections 10-11;
- `docs/kernel-jit-optimization-plan.md`, especially the directive list;
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`;
- `vendor/linux/kernel/bpf/verifier.c`;
- `vendor/linux/include/linux/bpf_verifier.h`;
- `vendor/linux/kernel/bpf/core.c`;
- `vendor/linux/kernel/bpf/bpf_insn_array.c`.

The target is the current x86-64 kernel BPF JIT in this tree, not a hypothetical backend.

## 1. Current JIT Architecture Summary

### 1.1 `do_jit()` structure

The x86 JIT entry point is `bpf_int_jit_compile()` in `vendor/linux/arch/x86/net/bpf_jit_comp.c:3716-3933`.

The actual instruction emitter is `do_jit()` in `vendor/linux/arch/x86/net/bpf_jit_comp.c:1652-2792`.

Its structure is:

1. Read program-global state:
   - `bpf_prog->len`, `bpf_prog->insnsi`;
   - stack depth, private stack, arena VM base, exception-table count;
   - callee-saved register usage.
2. Emit the prologue into a temporary buffer `temp[]`, copy it into `rw_image` if this is the final image pass, then set `addrs[0]`.
3. Walk the BPF program linearly with:

   ```c
   for (i = 1; i <= insn_cnt; i++, insn++) {
   	switch (insn->code) {
   	...
   	}
   	ilen = prog - temp;
   	if (image)
   		memcpy(rw_image + proglen, temp, ilen);
   	proglen += ilen;
   	addrs[i] = proglen;
   	prog = temp;
   }
   ```

4. Emit the cleanup/epilogue at the first `BPF_EXIT`; later exits branch to `ctx->cleanup_addr`.
5. Populate exception-table entries for `PROBE_MEM`/`PROBE_MEMSX` loads.

Important implementation detail: `do_jit()` is not a block scheduler. It is a linear emitter with one large `switch` over `insn->code`. Every optimization that wants to fit naturally into this backend should either:

- emit one fused native sequence at a BPF instruction boundary and skip a contiguous BPF range; or
- keep the original one-insn-at-a-time linear model.

### 1.2 `EMIT*` macros and helper style

All x86 bytes eventually go through the `EMIT`/`EMIT1`/`EMIT2`/`EMIT3`/`EMIT4`/`EMIT5` and `EMIT*_off32` macros in `vendor/linux/arch/x86/net/bpf_jit_comp.c:38-57`.

The backend is written in a very regular style:

- helper computes REX/ModRM/SIB bytes with `add_1mod()`, `add_2mod()`, `add_1reg()`, `add_2reg()`, `emit_insn_suffix()`, `emit_insn_suffix_SIB()` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:247-285`, `1024-1082`);
- helper emits raw x86 bytes with `EMIT*`;
- `do_jit()` chooses which helper to call.

The existing helpers most relevant to the directives are:

- `emit_ldx()` and `emit_ldsx()` for memory loads (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1085-1135`);
- `emit_mov_reg()`, `emit_mov_imm32()`, `emit_mov_imm64()` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:909-990`);
- direct compare/jump emission in the `BPF_JMP*` cases (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2481-2719`).

### 1.3 Pass model: conceptually two phases, actually multi-pass

The requested model is "pass 1 size estimation, pass 2 actual emission". That is the right conceptual model, but the current x86 JIT is more precise:

- there is an address-discovery phase, which may take multiple dry passes until the code size converges because jumps can shrink from rel32 to rel8;
- there is then one final image-emission pass into `rw_image`.

`bpf_int_jit_compile()` seeds `addrs[]` with a rough 64-byte-per-insn upper bound, then calls `do_jit()` repeatedly until `proglen` stabilizes (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3794-3815`).

Only after convergence does it allocate executable text and run the final emission pass (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3840-3862`).

So the current backend is:

- Phase A: repeated "size estimation + address discovery" passes;
- Phase B: final emission pass.

Directive code must preserve this property. In particular:

- pass A must be able to compute the exact native length of every directive expansion;
- pass B must reproduce exactly the same lengths, or the final-pass assertion will fire.

### 1.4 `addrs[]` semantics

`addrs[]` is the core BPF-PC to native-offset map.

The exact semantics in the current x86 JIT are:

- `addrs[0]` = native offset of BPF instruction 0, i.e. end of prologue (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1710-1715`);
- after emitting BPF instruction `k`, the loop stores `addrs[k + 1] = proglen`;
- therefore, for `0 <= k < prog->len`, `addrs[k]` is the native offset of BPF instruction `k`;
- `addrs[prog->len]` is the native end-of-program offset.

This is why branches use:

```c
jmp_offset = addrs[i + insn->off] - addrs[i];
```

inside the 1-based `do_jit()` loop (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2605`, `2656`, `2661`): `addrs[i]` is the start of the next BPF instruction, so the displacement is "target start minus next-instruction start".

Two other consumers matter:

- `bpf_prog_update_insn_ptrs()` expects `offsets[xlated_off]` to point to the beginning of the jitted instruction (`vendor/linux/kernel/bpf/bpf_insn_array.c:268-303`);
- `bpf_prog_fill_jited_linfo()` historically consumes `addrs + 1` (`vendor/linux/kernel/bpf/core.c:228-255`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:3893-3918`).

For fused directives, `addrs[]` handling is not optional. It is the main correctness constraint.

### 1.5 `image[]` and `rw_image`

The JIT allocates executable module text as `image` and a writable alias as `rw_image` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3848-3860`).

During final emission:

- PC-relative calculations use `image`;
- the actual bytes are written into `rw_image`;
- exception-table deltas are computed relative to `image`, then written through `rw_image` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2303-2327`).

This means any post-emission code patching would have to reason about:

- text packing;
- PC-relative displacement recalculation;
- extable fixups;
- padding passes.

That is why post-processing native text is the wrong place to consume these directives.

### 1.6 `jit_context`

`struct jit_context` in the current x86 backend is deliberately small (`vendor/linux/arch/x86/net/bpf_jit_comp.c:310-320`):

```c
struct jit_context {
	int cleanup_addr;
	int tail_call_direct_label;
	int tail_call_indirect_label;
};
```

It tracks only:

- `cleanup_addr`: where later `BPF_EXIT` instructions should branch;
- two tail-call labels that are discovered on an earlier pass and used on a later pass.

The persisted per-program JIT state is actually `struct x64_jit_data` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3704-3710`), which keeps:

- `addrs`;
- `image`;
- `proglen`;
- `jit_context`;
- text-pack headers.

For directives, the current `jit_context` is not the right place to store per-site plans. Those should live in a new directive-plan object in `prog->aux`, not in `jit_context`.

## 2. Directive Consumption Point

### 2.1 Option A: pre-process the BPF instruction stream before `do_jit()`

This means:

1. after verification/remap, clone or rewrite the post-verifier BPF program;
2. materialize directive effects as actual BPF instruction reordering/replacement;
3. run the stock x86 JIT on that transformed BPF program.

Pros:

- natural fit for true block layout changes such as `branch_reorder`;
- existing `do_jit()` mostly unchanged;
- native `addrs[]` stays monotonic in transformed BPF order.

Cons:

- extremely invasive to kernel verifier/JIT plumbing;
- must clone and re-adjust:
  - jump offsets;
  - line info;
  - `insn_aux_data`;
  - subprogram boundaries;
  - poke descriptors;
  - jited instruction pointers;
  - any directive-to-original mapping;
- `jit_subprogs()` creates separate `struct bpf_prog` instances for subprograms (`vendor/linux/kernel/bpf/verifier.c:22837-22910`), so any JIT-only transformed clone must be sliced again there;
- very hard to keep fail-closed fallback simple;
- easy to diverge from the actual verified program semantics.

Conclusion: do not use this for `wide_load` or `cmov_select`. Only true layout-changing directives make this attractive.

### 2.2 Option B: consume directives inside `do_jit()`

This means:

1. arch-neutral code parses the blob, remaps original coordinates to the post-verifier program, validates legality, and builds a per-site lowering plan;
2. the plan table is stored in `prog->aux`;
3. `do_jit()` checks "does a plan start at this BPF instruction?" before entering the stock opcode switch;
4. if yes, it emits one directive-specific native sequence, fills `addrs[]` for the covered range, and skips the covered BPF instructions.

Pros:

- best fit for the current x86 backend;
- no mutation of the verified BPF stream;
- reuses existing x86 helpers such as `emit_ldx()`, `emit_mov_reg()`, `emit_mov_imm32()`, `emit_mov_imm64()`;
- easy to keep fail-closed: if the plan is rejected or unsupported, `do_jit()` just falls back to the stock switch path;
- easiest place to control `addrs[]` for fused ranges.

Cons:

- `do_jit()` needs an explicit "directive fast-path" before the stock `switch`;
- the implementation must manually handle:
  - covered-range skipping;
  - `addrs[]` filling for non-1:1 lowering;
  - final-pass length stability;
  - per-site metadata such as extable prohibition.
- true layout-changing directives such as `branch_reorder` fit only awkwardly here.

Conclusion: this is the right design for `wide_load` and `cmov_select`.

### 2.3 Option C: post-process native code after `do_jit()`

This means:

1. emit stock native code first;
2. inspect native bytes;
3. patch them into another native sequence.

Pros:

- apparently little verifier coupling.

Cons:

- wrong abstraction level for this JIT;
- would have to re-open:
  - `addrs[]` mapping;
  - rel8 vs rel32 branch sizing;
  - convergence logic and padding passes;
  - extable fixups;
  - CFI/text-pack placement;
  - jited line info;
- `wide_load` and `cmov_select` both want to collapse multiple BPF PCs into one native entry, which must be reflected in `addrs[]` before the final image is published;
- branch layout changes are fundamentally not local byte patches.

Conclusion: do not do this.

### 2.4 Recommendation

Recommended design:

1. Add a shared arch-neutral preparation stage after verifier rewrites and before runtime selection:

   - remap original directive coordinates to the final post-verifier instruction stream;
   - validate legality;
   - build a compact `bpf_jit_site_plan[]` indexed by start BPF instruction;
   - store it in `prog->aux`.

2. Teach `do_jit()` a directive fast-path:

   - if no plan starts at instruction `i`, execute the stock switch;
   - if a plan starts at `i`, call the x86 emitter for that plan;
   - emit one native region;
   - populate `addrs[]` for every covered BPF instruction;
   - advance `i` to the first uncovered instruction.

3. Keep post-processing out of the design.

In short:

- `wide_load`: Option B;
- `cmov_select`: Option B;
- `branch_reorder`: either a much more invasive special-case regional emitter, or a separate pre-JIT block-scheduling design. It does not fit the simple fused-range path cleanly.

## 3. `wide_load` Implementation Detail

### 3.1 Current emission path

Assume this concrete BPF sequence, using the current x86 register mapping:

- `r0` -> `%rax`
- `r1` -> `%rdi`
- `r2` -> `%rsi`

Example ladder:

```c
r1 = *(u8 *)(r0 + 0x10)
r1 <<= 8
r2 = *(u8 *)(r0 + 0x11)
r1 |= r2
...
```

The stock x86 JIT emits:

1. `r1 = *(u8 *)(r0 + 0x10)`

   Source path:

   - `do_jit()` hits `case BPF_LDX | BPF_MEM | BPF_B`
   - calls `emit_ldx(&prog, BPF_B, BPF_REG_1, BPF_REG_0, 0x10)` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2230-2301`)
   - `emit_ldx()` does:

     ```c
     EMIT3(add_2mod(0x48, src_reg, dst_reg), 0x0F, 0xB6);
     emit_insn_suffix(&prog, src_reg, dst_reg, off);
     ```

   Exact bytes for `%rdi = *(u8 *)(%rax + 0x10)`:

   - `add_2mod(0x48, r0, r1)` -> `0x48`
   - `add_2reg(0x40, ptr=r0, val=r1)` -> `0x78`
   - disp8 = `0x10`

   Result:

   ```text
   48 0f b6 78 10    movzbq 0x10(%rax), %rdi
   ```

2. `r1 <<= 8`

   Source path:

   - `do_jit()` hits `case BPF_ALU64 | BPF_LSH | BPF_K`
   - executes:

     ```c
     maybe_emit_1mod(&prog, dst_reg, true);
     EMIT3(0xC1, add_1reg(0xE0, dst_reg), imm32);
     ```

   Exact bytes for `%rdi <<= 8`:

   - `maybe_emit_1mod(..., r1, true)` -> `0x48`
   - `add_1reg(0xE0, r1)` -> `0xE7`

   Result:

   ```text
   48 c1 e7 08       shl $0x8, %rdi
   ```

3. `r2 = *(u8 *)(r0 + 0x11)`

   Same `emit_ldx()` path, with `dst=r2`, `src=r0`, `off=0x11`.

   - `add_2mod(0x48, r0, r2)` -> `0x48`
   - `add_2reg(0x40, ptr=r0, val=r2)` -> `0x70`

   Result:

   ```text
   48 0f b6 70 11    movzbq 0x11(%rax), %rsi
   ```

4. `r1 |= r2`

   Source path:

   - `do_jit()` hits `case BPF_ALU64 | BPF_OR | BPF_X`
   - executes:

     ```c
     maybe_emit_mod(&prog, dst_reg, src_reg, true);
     EMIT2(0x09, add_2reg(0xC0, dst_reg, src_reg));
     ```

   Exact bytes for `%rdi |= %rsi`:

   - REX = `0x48`
   - ModRM = `add_2reg(0xC0, r1, r2)` -> `0xF7`

   Result:

   ```text
   48 09 f7          or %rsi, %rdi
   ```

So the current byte-ladder starts as:

```text
48 0f b6 78 10
48 c1 e7 08
48 0f b6 70 11
48 09 f7
...
```

For a width-4 ladder, the stock emitter keeps repeating byte-load / shift / OR. For width-8 it repeats even more. Code size is large because every byte becomes its own load.

Important semantic caveat: the example above is a big-endian-style recomposition pattern. A raw x86 `movl`/`movq` is little-endian. Therefore:

- the stock JIT emits exactly the byte ladder above;
- a fused `movl`/`movq` is only equivalent for little-endian ladders, or for ladders followed by an explicit byte-swap operation;
- v1 should reject big-endian ladders if the planned lowering is only `movl`/`movq`.

### 3.2 Fused emission

The x86 implementation should not invent a new raw-byte emitter for `wide_load`. It should reuse the existing load helper.

Recommended emitter:

```c
static void emit_wide_load_plan(u8 **pprog, const struct bpf_jit_wide_load_plan *plan)
{
	if (plan->width == 4)
		emit_ldx(pprog, BPF_W, plan->dst_reg, plan->base_reg, plan->base_off);
	else
		emit_ldx(pprog, BPF_DW, plan->dst_reg, plan->base_reg, plan->base_off);
}
```

That gives:

- width 4: one `movl disp(%base), %dst32`
- width 8: one `movq disp(%base), %dst64`

For the same concrete example (`base=r0=%rax`, `dst=r1=%rdi`, `off=0x10`):

1. width = 4

   `emit_ldx(BPF_W, r1, r0, 0x10)` emits:

   ```text
   8b 78 10          mov 0x10(%rax), %edi
   ```

   This is exactly the existing stock x86 encoding for a 32-bit load, and on x86-64 it zero-extends into `%rdi`, which matches normal ALU32 zero-extension behavior.

2. width = 8

   `emit_ldx(BPF_DW, r1, r0, 0x10)` emits:

   ```text
   48 8b 78 10       mov 0x10(%rax), %rdi
   ```

For disp32 offsets, the helper naturally emits the longer `disp32` form:

- width 4: `8b b8 <off32>`
- width 8: `48 8b b8 <off32>`

Do not lower `wide_load` by stitching custom `EMIT*` sequences by hand unless there is an architecture-specific reason not to use `emit_ldx()`.

### 3.3 `addrs[]` handling

Assume the remapped directive covers post-verifier BPF instruction interval `[start, end)`, end-exclusive, with `end > start`.

The native fused region has one entry point and one native body.

Recommended `addrs[]` rule:

- `addrs[start]` remains the native start offset of the fused region;
- for every covered BPF instruction `k` with `start < k < end`, set `addrs[k] = addrs[start]`;
- after emitting the fused native sequence, set `addrs[end] = region_end`.

This is the right mapping for current kernel consumers:

- `bpf_prog_update_insn_ptrs()` wants the beginning of the jitted instruction, so every covered BPF instruction should resolve to the fused native entry;
- line info inside the covered interval will point at the same native PC, which is acceptable for a fused region.

This does require an explicit covered-range path in `do_jit()`. The stock "one `addrs[i]` write per loop iteration" is not enough.

Recommended `do_jit()` skeleton:

```c
if (site_plan && site_plan->kind == BPF_JIT_DIR_WIDE_LOAD) {
	int start = i - 1;
	int end = site_plan->end;
	int region_start = proglen;

	emit_wide_load_plan(&prog, &site_plan->wide_load);
	ilen = prog - temp;

	if (image)
		memcpy(rw_image + proglen, temp, ilen);

	for (k = start + 1; k < end; k++)
		addrs[k] = region_start;

	proglen += ilen;
	addrs[end] = proglen;

	i = end;
	insn = bpf_prog->insnsi + end;
	prog = temp;
	continue;
}
```

The key invariant is:

- every covered BPF instruction starts at the same native PC;
- the first uncovered BPF instruction starts at `region_end`.

#### `BPF_JIT_PC_NO_INTERIOR_TARGET`

The current kernel tree does not have a literal `BPF_JIT_PC_NO_INTERIOR_TARGET` implementation. It exists only in the design docs.

The actual rule that must be enforced is:

- no control-flow edge from outside `[start, end)` may target an instruction `t` with `start < t < end`.

For `wide_load`, because the region is straight-line, any interior target is automatically an external target. So the validator can simply reject any incoming edge to interior instructions.

Do not implement this as a raw check of `insn_aux_data[t].jmp_point`, because:

- that only says "someone jumps here";
- it does not distinguish incoming edges from inside the region vs outside the region;
- and the current `jmp_point` metadata is computed before later rewrite passes.

Recommended implementation:

1. after all verifier rewrites, rebuild a final-program CFG target map for directive-bearing programs;
2. when validating a candidate range, scan all jumps in the final program;
3. reject if any jump with source outside `[start, end)` lands on `t` with `start < t < end`.

### 3.4 Register allocation and liveness

There is no dynamic register allocator in this backend. BPF registers map to fixed x86 registers (`vendor/linux/arch/x86/net/bpf_jit_comp.c:171-197`).

So `wide_load` does not need register allocation in the compiler-backend sense. It needs a liveness check.

The original byte ladder may define temporary BPF registers, for example `r2` in the example. The fused native load will not write those temporaries at all. That is only valid if those temporary registers are dead after the region.

Recommended legality rule:

1. Track `defined_mask`: all BPF registers written by instructions in `[start, end)`.
2. Let `live_out_mask` be:
   - `live_regs_before[end]` if `end < prog->len`;
   - `0` if `end == prog->len`.
3. Require:

   ```text
   (live_out_mask & (defined_mask & ~BIT(dst_reg))) == 0
   ```

Meaning:

- registers defined in the region other than the final destination must not be live-out.

Important current-tree detail: `compute_live_registers()` runs before verifier rewrite expansion (`vendor/linux/kernel/bpf/verifier.c:26048`, `26090-26107`). Therefore the current `live_regs_before` metadata is for the pre-rewrite program, while directive remap is supposed to operate on the post-rewrite program.

So for a correct implementation, one of these must happen:

1. recompute CFG + liveness after all rewrites for directive-bearing programs; or
2. avoid any legality rule that depends on post-rewrite liveness.

For `wide_load`, option 2 is not good enough because "temp register is dead" is a real semantic requirement.

Recommendation: add a small post-rewrite metadata rebuild step for directive-bearing programs:

- rebuild jump targets;
- recompute postorder/successors if needed;
- recompute `live_regs_before` on the final rewritten program.

If a temporary register is live-out, v1 should reject the directive. Do not try to preserve it with extra moves; that complicates the contract and weakens code-size wins.

### 3.5 Edge cases

#### Unaligned access

x86-64 can execute unaligned `movl`/`movq` from normal kernel memory, including stack and map values, without needing an exception-table path.

But legality and profitability are different:

- legality: stack/map-value direct accesses are fine on x86;
- profitability: some cores dislike unaligned or cache-line-crossing loads.

That is why the directive carries `min_align_log2`. The shared validator should check that the retained verifier fact proves at least that much alignment, even though x86 could legally execute the load with lower alignment.

#### Stack vs map value vs packet/ctx/probe_mem

`wide_load` v1 should only accept:

- `PTR_TO_STACK`;
- `PTR_TO_MAP_VALUE`.

Reject:

- packet data;
- context accesses;
- arena accesses;
- `PROBE_MEM`/`PROBE_MEMSX`;
- anything that would require extable behavior.

Why:

- packet and context accesses have different verifier/JIT contracts;
- `PROBE_MEM` changes fault behavior and requires extable entries (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2247-2345`);
- the fused `movl`/`movq` must preserve "nonfaulting direct load" semantics.

#### Verifier rewrites

The validator must work on the final post-verifier program, not on original user coordinates.

That means:

- userspace names original instruction indices;
- verifier may expand, replace, or delete instructions;
- `orig_idx` propagation remaps the directive to the post-verifier interval;
- if the final interval is empty, non-contiguous, or no longer matches a byte ladder, reject and fall back.

Do not try to match the original program text at JIT time.

#### Endianness

This is a hard correctness point.

Raw x86 `movl`/`movq` is little-endian.

Therefore:

- accept little-endian byte ladders;
- reject big-endian ladders in v1, unless a later extension explicitly lowers them as `mov` + `bswap`.

The sample shown in section 3.1 is the big-endian pattern. It is useful to show the current stock emission, but it is not a valid v1 `movl`/`movq` fusion candidate unless the region also includes an equivalent byte-swap.

## 4. `cmov_select` Implementation Detail

### 4.1 Current diamond emission

Take this concrete BPF diamond:

```c
if (r1 > r2) goto L1
r0 = r3        // false arm
goto L2
L1:
r0 = r4        // true arm
L2:
```

Using current x86 mappings:

- `r0` -> `%rax`
- `r1` -> `%rdi`
- `r2` -> `%rsi`
- `r3` -> `%rdx`
- `r4` -> `%rcx`

Assume the false move and true move are both 3-byte register moves, so both jumps fit in rel8.

The stock JIT emits:

1. compare `r1` and `r2`

   Path:

   - `case BPF_JMP | BPF_JGT | BPF_X`
   - `maybe_emit_mod(&prog, dst_reg, src_reg, true);`
   - `EMIT2(0x39, add_2reg(0xC0, dst_reg, src_reg));`

   Bytes:

   ```text
   48 39 f7          cmp %rsi, %rdi
   ```

2. conditional jump to `L1`

   `BPF_JGT` maps to x86 `JA` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2570-2573`).

   Because the target skips:

   - false-arm move: 3 bytes
   - unconditional jump: 2 bytes

   the rel8 displacement is `5`.

   Bytes:

   ```text
   77 05             ja +5
   ```

3. false arm `r0 = r3`

   `emit_mov_reg(&prog, true, BPF_REG_0, BPF_REG_3)` expands to `EMIT_mov(BPF_REG_0, BPF_REG_3)`.

   Bytes:

   ```text
   48 89 d0          mov %rdx, %rax
   ```

4. jump over the true arm

   Target is 3 bytes ahead.

   Bytes:

   ```text
   eb 03             jmp +3
   ```

5. true arm `r0 = r4`

   Bytes:

   ```text
   48 89 c8          mov %rcx, %rax
   ```

So the current native sequence is:

```text
48 39 f7
77 05
48 89 d0
eb 03
48 89 c8
```

If the arm bodies are larger, the stock JIT will switch to:

- `0f 87 <rel32>` for the `JA`;
- `e9 <rel32>` for the unconditional jump.

### 4.2 `cmov` emission

The desired lowering is:

```asm
cmp   lhs, rhs
mov   false_val, dst
cmovCC true_val, dst
```

For the same example (`r0 = r3` on false, `r0 = r4` on true, condition `r1 > r2` unsigned):

```text
48 39 f7          cmp   %rsi, %rdi
48 89 d0          mov   %rdx, %rax
48 0f 47 c1       cmova %rcx, %rax
```

That is the exact encoding:

- `cmp %rsi, %rdi`: `48 39 f7`
- `mov %rdx, %rax`: `48 89 d0`
- `cmova %rcx, %rax`: `48 0f 47 c1`

#### Recommended helper split

1. Factor compare emission out of the conditional-jump cases into a helper that emits exactly the same compare/test bytes the stock JIT would have emitted.

   This avoids duplicating:

   - reg/reg compare;
   - reg/imm compare;
   - `test reg, reg` optimization for compare-to-zero;
   - 32-bit vs 64-bit REX handling.

2. Add a new x86 helper for register-source `cmov`:

```c
static void emit_cmov_reg(u8 **pprog, u8 cmov_op, bool is64,
			  u32 dst_reg, u32 src_reg)
{
	u8 *prog = *pprog;

	/*
	 * CMOVcc encodes dst in ModRM.reg and src in ModRM.r/m,
	 * which is the opposite of the helper argument order used by
	 * most of this file.
	 */
	maybe_emit_mod(&prog, src_reg, dst_reg, is64);
	EMIT3(0x0F, cmov_op, add_2reg(0xC0, src_reg, dst_reg));
	*pprog = prog;
}
```

This follows the same encoding rule used by the existing `cmove` site at `vendor/linux/arch/x86/net/bpf_jit_comp.c:1782-1785`.

3. Reuse `emit_mov_reg()`, `emit_mov_imm32()`, and `emit_mov_imm64()` to materialize false and true values.

#### Exact x86 opcode mapping

For the supported conditions:

| BPF cc | x86 branch today | x86 `cmov` opcode |
| --- | --- | --- |
| `BPF_JEQ` | `JE` (`0x74` / `0x84`) | `CMOVE` (`0x44`) |
| `BPF_JNE` | `JNE` (`0x75` / `0x85`) | `CMOVNE` (`0x45`) |
| `BPF_JGT` | `JA` (`0x77` / `0x87`) | `CMOVA` (`0x47`) |
| `BPF_JGE` | `JAE` (`0x73` / `0x83`) | `CMOVAE` (`0x43`) |
| `BPF_JLT` | `JB` (`0x72` / `0x82`) | `CMOVB` (`0x42`) |
| `BPF_JLE` | `JBE` (`0x76` / `0x86`) | `CMOVBE` (`0x46`) |
| `BPF_JSGT` | `JG` (`0x7f` / `0x8f`) | `CMOVG` (`0x4f`) |
| `BPF_JSGE` | `JGE` (`0x7d` / `0x8d`) | `CMOVGE` (`0x4d`) |
| `BPF_JSLT` | `JL` (`0x7c` / `0x8c`) | `CMOVL` (`0x4c`) |
| `BPF_JSLE` | `JLE` (`0x7e` / `0x8e`) | `CMOVLE` (`0x4e`) |

`BPF_JSET` should not be part of v1 `cmov_select`. It is not a select compare in the usual sense and complicates the contract for little benefit.

#### 32-bit vs 64-bit compare

The compare width must match the directive:

- width 64: emit the exact compare logic used for `BPF_JMP` cases, i.e. with `REX.W`;
- width 32: emit the exact compare logic used for `BPF_JMP32` cases, i.e. without `REX.W` except for extended registers.

Example:

- 64-bit compare `r1 > r2`: `48 39 f7`
- 32-bit compare `w1 > w2`: `39 f7`

The `cmov` width must match the directive too:

- width 64: `REX.W 0f 4x /r`
- width 32: `0f 4x /r` plus REX only if extended registers are used.

For width 32, the write to `dst32` zero-extends into `dst64`, which is exactly what we want.

### 4.3 `addrs[]` handling

For `cmov_select`, the entire diamond region is replaced by one native entry sequence.

Assume the remapped interval is `[start, end)`, end-exclusive, covering:

- the compare/jump;
- both arm assignments;
- the arm-to-join jump.

Recommended `addrs[]` rule is the same as `wide_load`:

- all covered BPF instructions share one native start offset;
- `addrs[end]` points to the first uncovered instruction after the fused `cmp/mov/cmov`.

This is legal if and only if there is no incoming edge from outside the region to an interior BPF instruction.

That is the precise implementation meaning of `BPF_JIT_PC_NO_INTERIOR_TARGET` for `cmov_select`.

Do not reject the region just because the original diamond has an internal jump from the compare to the true arm. That edge is inside the replaced region and disappears after lowering.

So the correct rule is:

- reject if an instruction outside `[start, end)` branches to any `t` with `start < t < end`;
- allow jumps whose source is also inside `[start, end)`, because the whole region is being replaced.

### 4.4 Condition-code mapping

The lowering must preserve the exact signedness and width of the original compare.

Mapping:

| BPF opcode | Meaning | x86 compare flags consumer |
| --- | --- | --- |
| `BPF_JEQ` | equal | `CMOVE` |
| `BPF_JNE` | not equal | `CMOVNE` |
| `BPF_JGT` | unsigned greater-than | `CMOVA` |
| `BPF_JGE` | unsigned greater-or-equal | `CMOVAE` |
| `BPF_JLT` | unsigned less-than | `CMOVB` |
| `BPF_JLE` | unsigned less-or-equal | `CMOVBE` |
| `BPF_JSGT` | signed greater-than | `CMOVG` |
| `BPF_JSGE` | signed greater-or-equal | `CMOVGE` |
| `BPF_JSLT` | signed less-than | `CMOVL` |
| `BPF_JSLE` | signed less-or-equal | `CMOVLE` |

Width handling:

- `BPF_JMP*` -> 64-bit compare, 64-bit `cmov`
- `BPF_JMP32*` -> 32-bit compare, 32-bit `cmov`

The emitter should derive both from the validated plan, not re-infer them from raw BPF opcodes at emission time.

### 4.5 Edge cases

#### Immediate arms that do not fit in 32 bits

`cmov` has no immediate source form.

Recommended rule:

- materialize `false_val` into `dst`;
- if `true_val` is a register and survives materialization, use it directly in `cmov`;
- if `true_val` is an immediate, materialize it into `AUX_REG` (`r11`) and `cmov` from there.

For width 64:

- use `emit_mov_imm64()` if the immediate does not fit the helper's 32-bit optimized paths;
- this may emit `movabs`.

This is correct but can become code-size heavy:

- `movabs false_imm, dst`
- `movabs true_imm, r11`
- `cmovcc r11, dst`

That is still acceptable for v1 because profitability is userspace policy.

#### `cmov` with a memory source operand

x86 supports `cmov r, m`, but v1 should not use it.

Reason:

- the validator contract says both arm values are register or immediate;
- allowing memory operands would pull memory-fault and alias concerns into `cmov_select`;
- it complicates extable and nonfaulting rules for no clear first-version benefit.

So v1 should only emit register-source `cmov`.

#### Register conflicts

This is the main subtlety.

`cmp` must happen before any false-value materialization, because:

- `cmp` reads `lhs` and `rhs`;
- after flags are set, `lhs`/`rhs` are no longer needed.

Then:

1. If `false_val` already resides in `dst`, no move is needed.
2. If `dst == true_reg` and false-value materialization would overwrite it, copy `true_reg` to `AUX_REG` first.
3. If `dst == lhs` or `dst == rhs`, that is fine as long as compare happens first.
4. If both arms are immediates, `dst` gets false and `AUX_REG` gets true.

Recommended legalization logic:

- compute whether `true_val` needs preservation across `mov false, dst`;
- if yes, reserve `AUX_REG` and move true there before clobbering `dst`;
- then emit `mov false, dst`;
- then emit `cmov` from preserved true source.

Because `AUX_REG` is outside the BPF architectural register set, it is the right scratch register for this.

## 5. `branch_reorder` Implementation Detail

### 5.1 Current branch emission

Today the x86 JIT handles branches in strictly source order.

Conditional jumps:

- compare/test is emitted first;
- x86 condition opcode is selected;
- displacement is computed as `addrs[target] - addrs[next_pc]` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2481-2639`).

Unconditional jumps:

- same address-map idea;
- rel8 uses `eb`;
- rel32 uses `e9`;
- `off == -1` has a special-case `-2` encoding for convergence (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2644-2719`).

Forward vs backward jumps are not separate code paths. Both use the same `addrs[]` difference.

Near vs short selection:

- short conditional jump: `Jcc rel8`
- near conditional jump: `0f 8x rel32`
- short unconditional jump: `eb rel8`
- near unconditional jump: `e9 rel32`

To make multi-pass convergence work, x86 caps positive rel8 offsets to 123 and eventually inserts NOP padding before shrinking jumps (`vendor/linux/arch/x86/net/bpf_jit_comp.c:74-118`, `2606-2630`, `2664-2712`).

### 5.2 Can blocks be reordered in the current `do_jit()` model?

Not cleanly.

The current `do_jit()` model assumes:

- emit BPF instructions in original linear order;
- after each instruction, write one new `addrs[i] = proglen`;
- use `INSN_SZ_DIFF` and final-pass assertions based on that linear progression (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1598`, `2768-2785`).

True block reordering would violate that model because:

- a later BPF block could be emitted earlier in native order;
- `addrs[]` would become non-monotonic in BPF index order;
- the current loop body is not written to populate `addrs[]` out of order;
- line-info and per-insn native pointer mappings would no longer be monotonic either.

To support true block reordering in this backend, one of these would be required:

1. a real CFG/block emitter instead of the current linear `switch` loop; or
2. a JIT-local transformed BPF clone with blocks already reordered before entering `do_jit()`.

Either is materially more invasive than `wide_load` or `cmov_select`.

### 5.3 Is condition inversion alone sufficient?

No, not for true fall-through selection.

Suppose the original order is:

```text
cond
false block
jmp join
true block
join
```

With that physical layout, the fall-through block is the false block. Merely inverting the branch condition does not make the true block become fall-through, because the next bytes in memory are still the false block.

Condition inversion by itself can only:

- change which edge is conditional vs unconditional;
- not change physical block order.

Therefore:

- if the hot path is already the lexically next block, condition inversion may help choose the more convenient edge sense;
- if the hot path is not the lexically next block, condition inversion is not enough.

### 5.4 What would a real local reordering implementation look like?

If `branch_reorder` must exist in v1, the least invasive form is not a global block placer. It is a local one-diamond regional emitter.

Accepted shape:

- one entry conditional branch;
- two straight-line arms;
- one join;
- no incoming edge from outside the region to either arm entry;
- no side effects that make motion across the arms illegal;
- both arms remain entirely inside one subprogram.

For a region where the true arm should become hot fall-through:

1. emit compare;
2. emit inverted branch to the cold arm label;
3. emit the hot arm first;
4. emit an unconditional jump over the cold arm to join;
5. emit the cold arm;
6. let cold arm fall through to join.

Native layout:

```asm
cmp ...
j!cc cold
hot:
  ...
  jmp join
cold:
  ...
join:
```

This does work locally, but it has consequences:

- arm instructions keep distinct native addresses;
- `addrs[]` must record actual native offsets for every instruction in both arms;
- those offsets are no longer written in simple BPF-index order.

That means `branch_reorder` is fundamentally different from the fused directives:

- `wide_load` and `cmov_select` collapse many BPF instructions into one native entry;
- `branch_reorder` preserves multiple distinct native labels, just in a different order.

### 5.5 Recommendation for `branch_reorder`

Recommendation:

1. Do not try to squeeze general block reordering into the same simple "covered range shares one `addrs[]` entry" path as `wide_load` and `cmov_select`.
2. If `branch_reorder` stays in scope, implement only a one-diamond regional emitter with its own local address bookkeeping.
3. If the project wants the smallest possible implementation risk, defer true `branch_reorder` and keep v1 to `wide_load` + `cmov_select`.

Condition inversion alone is not enough. Real fall-through selection requires real native reordering.

## 6. `orig_idx` Propagation Implementation

### 6.1 Current `adjust_insn_aux_data()`

Current code:

- `orig_idx` already exists in `struct bpf_insn_aux_data` at `vendor/linux/include/linux/bpf_verifier.h:525-598`;
- `bpf_check()` initializes `env->insn_aux_data[i].orig_idx = i` at `vendor/linux/kernel/bpf/verifier.c:25934-25940`.

Relevant existing `bpf_insn_aux_data` fields for this design are:

- memory/classification:
  - `ptr_type`
  - `map_ptr_state`
  - `ctx_field_size`
- rewrite support:
  - `call_imm`
  - `seen`
  - `zext_dst`
  - `needs_zext`
- CFG / post-verifier analysis:
  - `orig_idx`
  - `jmp_point`
  - `prune_point`
  - `force_checkpoint`
  - `scc`
  - `live_regs_before`
- dynamic aux allocations:
  - `jt`
  - `kptr_struct_meta`

Current `adjust_insn_aux_data()` (`vendor/linux/kernel/bpf/verifier.c:21922-21953`) does:

- update `data[off].zext_dst`;
- if patch length is 1, return;
- `memmove()` the tail of the aux array to make room;
- `memset()` newly inserted aux slots to zero;
- propagate only:
  - `seen`
  - `zext_dst`

into the inserted slots.

So in the current tree:

- the field exists;
- propagation is incomplete.

That is exactly the gap identified by `v5r2`.

### 6.2 Required changes

The requested "add `orig_idx` field" is already done in this tree. The actual required work is:

1. Keep the existing initialization in `bpf_check()`.
2. Change `adjust_insn_aux_data()` to propagate `orig_idx` through expansion.

Recommended patch:

```c
u32 old_seen = data[off].seen;
u32 old_orig = data[off].orig_idx;
...
for (i = off; i < off + cnt - 1; i++) {
	data[i].seen = old_seen;
	data[i].orig_idx = old_orig;
	data[i].zext_dst = insn_has_def32(insn + i);
}
```

Also update the `cnt == 1` case so that if the instruction at `off` has been replaced in place, its `orig_idx` remains the original one.

3. Audit all instruction-expansion paths that go through `bpf_patch_insn_data()`.

In this tree the direct callers are:

- `opt_subreg_zext_lo32_rnd_hi32()` (`vendor/linux/kernel/bpf/verifier.c:22372-22470`);
- `convert_ctx_accesses()` (`vendor/linux/kernel/bpf/verifier.c:22478-22776`);
- `add_hidden_subprog()` (`vendor/linux/kernel/bpf/verifier.c:23323-23347`);
- `do_misc_fixups()` (`vendor/linux/kernel/bpf/verifier.c:23353-24312`);
- `inline_bpf_loop()` (`vendor/linux/kernel/bpf/verifier.c:24314-24387`).

These do not each need custom `orig_idx` logic if `adjust_insn_aux_data()` is fixed centrally, but they must be audited to confirm they all still use the common path.

4. Audit removal paths separately.

Removal does not go through `bpf_patch_insn_data()`. It goes through:

- `verifier_remove_insns()` (`vendor/linux/kernel/bpf/verifier.c:22221-22250`);
- callers such as `opt_remove_dead_code()` and `opt_remove_nops()` (`vendor/linux/kernel/bpf/verifier.c:22320-22366`).

For removals:

- no propagation is needed;
- the removed original instruction simply disappears from the post-verifier stream;
- the remap phase must reject directives whose original range becomes empty or non-contiguous.

### 6.3 Where `adjust_insn_aux_data()` is called from

`adjust_insn_aux_data()` is called only from `bpf_patch_insn_data()` (`vendor/linux/kernel/bpf/verifier.c:22010-22040`).

`bpf_patch_insn_data()` is the verifier-side wrapper around `bpf_patch_insn_single()` (`vendor/linux/kernel/bpf/core.c:455-514`):

- `bpf_patch_insn_single()` grows or rewrites the actual `prog->insnsi` array and fixes branch offsets/line info;
- `bpf_patch_insn_data()` then adjusts verifier-side metadata arrays.

This is exactly the correct choke point for `orig_idx` propagation.

## 7. Retained Memory Facts Implementation

### 7.1 Where to hook in the verifier

The right hook is `check_mem_access()` in `vendor/linux/kernel/bpf/verifier.c:7681-7905`.

Why this is the right point:

- pointer type is known (`PTR_TO_STACK`, `PTR_TO_MAP_VALUE`, etc.);
- alignment checks have already run (`check_ptr_alignment()`);
- fixed offset `reg->off` has already been folded into `off`;
- the verifier has already proved the access legal for the relevant memory class;
- direct map-value and stack handling happen here.

Recommended hook point:

- after the legality checks for `PTR_TO_STACK` or `PTR_TO_MAP_VALUE` have succeeded;
- only for `t == BPF_READ`;
- only if the instruction's original index is covered by at least one `wide_load` directive.

Pseudo-code:

```c
if (!err && t == BPF_READ && jit_dir_origidx_is_covered(env, aux[insn_idx].orig_idx))
	record_jit_mem_fact(env, insn_idx, reg, off, size);
```

Available information at that point:

- pointer base class;
- whether access is a direct nonfaulting stack/map-value access;
- whether `reg->var_off` is constant;
- the effective constant offset if it is constant;
- map read-only status;
- alignment facts via the same `tnum` arithmetic used by `check_ptr_alignment()`;
- object size / residual readable bytes.

### 7.2 Storage

Do not put `bpf_jit_mem_fact` directly into `struct bpf_insn_aux_data` unless you accept a permanent size increase for every BPF program.

Recommended storage model:

1. Verifier-time sidecar array:

   ```c
   struct bpf_jit_mem_fact *jit_mem_facts; // env-sized, parallel to insn_aux_data
   ```

   Allocate it only if:

   - directives were supplied; and
   - at least one remapped directive kind needs memory facts (`wide_load` today).

2. Post-verifier compact copy:

   - after remap and validation, keep only the facts needed by accepted sites in a compact `prog->aux->jit_dir_state`.

This is better than embedding because:

- no overhead for programs without directives;
- no permanent `bpf_insn_aux_data` growth;
- clear ownership and cleanup.

If laid out exactly as in `v5r2`, one fact record is 8 bytes:

```c
struct bpf_jit_mem_fact {
	__u8 valid;
	__u8 mem_class;
	__u8 align_log2;
	__u8 flags;
	__s16 const_off;
	__u16 min_readable;
};
```

So verifier-time memory cost is:

- `8 * prog->len` bytes if the sidecar is allocated;
- plus one original-index coverage bitset.

That is cheap enough for directive-bearing programs and avoids global verifier bloat.

### 7.3 Propagation across rewrites

If a sidecar array is used, it needs the same adjustment logic as `insn_aux_data`.

Recommended rule:

- when instruction `off` expands into `cnt` instructions, inserted slots inherit the fact of the replaced instruction;
- when instructions are removed, the facts are memmoved exactly as the program and aux arrays are.

That means:

- add `adjust_jit_mem_facts(env, new_prog, off, cnt)` right next to `adjust_insn_aux_data()`;
- call it from `bpf_patch_insn_data()`;
- mirror removal logic in `verifier_remove_insns()`.

Using `orig_idx` alone is not enough here. The sidecar must stay aligned with the current post-rewrite instruction stream.

### 7.4 How to compute the fields

Recommended field construction:

- `valid`: set to 1 only for `BPF_READ` accesses from `PTR_TO_STACK` or `PTR_TO_MAP_VALUE`.
- `mem_class`:
  - `STACK` for `PTR_TO_STACK`
  - `MAP_VALUE` for `PTR_TO_MAP_VALUE`
- `CONST_OFFSET`: set only if `tnum_is_const(reg->var_off)`.
- `const_off`: `off + reg->var_off.value` when `CONST_OFFSET` is true.
- `NONFAULTING`: true for direct stack and direct map-value accesses that do not use probe forms.
- `READONLY`: true when the map is read-only; false for stack.
- `min_readable`:
  - stack: `-const_off`
  - map value: `map->value_size - const_off`
  - both only when `const_off` is valid and non-negative within object bounds
- `align_log2`: derive from the same `tnum` used by `check_ptr_alignment()`.

For `align_log2`, use the final effective offset tnum:

```c
reg_off = tnum_add(reg->var_off, tnum_const(reg->off + insn_off));
```

then compute the largest `k` such that `tnum_is_aligned(reg_off, 1 << k)` is true.

This gives a lower bound on guaranteed alignment, which is exactly what the directive needs.

### 7.5 Cleanup

Cleanup rules:

- verifier-time sidecar array: free with `env->insn_aux_data` on all verifier exit paths;
- accepted-plan copy in `prog->aux`: free in `__bpf_prog_free()` together with other aux-owned allocations.

If per-subprogram `struct bpf_prog` objects are created in `jit_subprogs()`, directive state must be sliced or copied there too, exactly like line info and poke metadata are handled (`vendor/linux/kernel/bpf/verifier.c:22837-22910`).

## 8. Integration Test Plan

### 8.1 General test strategy

Each directive needs three classes of tests:

1. semantic correctness:
   - run the BPF program and verify result equality with and without directives;
2. JIT-shape verification:
   - dump the jited image and assert that the expected x86 idiom appears;
3. rejection/fallback:
   - load a directive that should fail validation and confirm the program still loads and runs with stock lowering, plus the expected rejection reason is reported.

New tests should live under the normal BPF selftest split:

- `tools/testing/selftests/bpf/progs/` for BPF programs;
- `tools/testing/selftests/bpf/prog_tests/` for harnesses.

### 8.2 `wide_load` tests

Write isolated tests for:

1. stack little-endian width-4 ladder -> accepted
   - expect one `mov` load in jited bytes;
   - expect no repeated byte-load/shift/or ladder.
2. stack little-endian width-8 ladder -> accepted
   - expect one `movq`.
3. map-value little-endian width-4 ladder -> accepted.
4. map-value little-endian width-8 ladder -> accepted.
5. big-endian ladder -> rejected
   - verify fallback to stock byte ladder.
6. temp live-out -> rejected
   - construct a program where the temporary register is read after the ladder.
7. packet-based byte ladder -> rejected.
8. ctx/probe-mem-based byte ladder -> rejected.
9. insufficient alignment policy -> rejected
   - request `min_align_log2 = 3` on an address the verifier can only prove 1- or 2-byte aligned.
10. directive range becomes non-contiguous after rewrite -> rejected.

JIT-byte checks:

- width 4 example should contain `8b 78 10`-style load for the chosen register tuple;
- width 8 example should contain `48 8b 78 10`-style load;
- rejected cases should still show `movzbq`/`shl`/`or` ladder bytes.

### 8.3 `cmov_select` tests

Write isolated tests for:

1. reg/reg unsigned select, width 64 -> accepted
   - expect `cmp`, `mov`, `cmova`.
2. reg/reg signed select, width 64 -> accepted
   - expect `cmovg`, `cmovge`, `cmovl`, or `cmovle`.
3. reg/reg width 32 -> accepted
   - expect 32-bit compare and 32-bit `cmov`.
4. false arm immediate, true arm register -> accepted.
5. false arm register, true arm immediate -> accepted
   - expect materialization into `AUX_REG`.
6. both arms immediate, one 64-bit-large immediate -> accepted
   - expect `movabs` plus `cmov`.
7. `dst == true_reg` conflict case -> accepted with temp preservation.
8. arm side effect (stack write/helper/call/atomic) -> rejected.
9. outside jump into true arm or false arm -> rejected.
10. width-32 zero-extension mismatch -> rejected.

JIT-byte checks:

- accepted cases must contain `0f 4x` opcodes;
- the original `jcc ...; mov ...; jmp ...; mov ...` diamond should be absent from the replaced region.

### 8.4 `branch_reorder` tests

If true branch reordering is implemented:

1. one-diamond hot-true layout -> accepted
   - verify native order is `cmp; j!cc cold; hot; jmp join; cold`.
2. one-diamond hot-false layout -> accepted
   - verify the opposite arrangement.
3. outside jump to interior arm -> rejected.
4. multi-entry or multi-exit region -> rejected.
5. arm with side effects that prevent motion -> rejected.

If `branch_reorder` is not implemented in v1, still add rejection tests so the directive path is exercised and fail-closed behavior is explicit.

### 8.5 Verifier/remap tests

These are critical because the whole design depends on original-to-post-verifier remap.

Write tests for:

1. range survives unchanged -> accepted.
2. range expands through `bpf_patch_insn_data()` and still maps contiguously -> accepted.
3. range is deleted by a verifier optimization -> rejected.
4. range crosses a subprogram boundary after remap -> rejected.
5. overlapping directives after remap -> rejected.

These can be a mix of:

- selftests that load real programs and inspect success/rejection codes;
- KUnit-style verifier unit tests if direct introspection of remapped plans is needed.

### 8.6 Fallback tests

For every directive kind, add explicit tests for:

- malformed blob;
- unsupported CPU feature gating;
- constant blinding enabled -> directive set dropped, stock compile used;
- unsupported arch -> blob ignored or rejected as designed;
- validator rejection -> stock JIT path still produces correct program behavior.

The fallback behavior is part of the contract and must be tested just as directly as the accepted path.

## Bottom line

For the current x86 JIT:

- `wide_load` and `cmov_select` should be implemented as prevalidated plans consumed inside `do_jit()` at region start;
- both need explicit covered-range `addrs[]` population;
- both depend on correct original-to-post-verifier remap;
- `wide_load` additionally needs retained memory facts and post-rewrite liveness;
- `cmov_select` additionally needs careful `cmov` register-conflict handling;
- `branch_reorder` is qualitatively more invasive because it wants true block layout changes, not just fused lowering.

The most important tree-specific corrections to earlier design assumptions are:

1. x86 is not a strict two-pass backend; it is a convergence loop plus a final image pass.
2. `orig_idx` already exists, but propagation through rewrite expansion is incomplete today.
3. post-verifier directive validation should not trust pre-rewrite liveness/CFG metadata; directive-bearing programs need a small post-rewrite metadata rebuild.
