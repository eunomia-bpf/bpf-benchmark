# ROTATE scanner debug: `rotate64_hash`

## Summary

- ELF `rotate64_hash.bpf.o` contains `992` BPF insns (`7936` bytes).
- Verifier/xlated program contains `998` insns (`7984` bytes).
- The `+6` insns are the expected array-map lookup expansion in the prologue:
  - ELF:
    - `10: r1 = 0x0 ll`
    - `12: call 0x1`
    - `13: if r0 == 0x0 goto ...`
  - xlated:
    - `10: r1 = map[id:1]`
    - `12: r1 += 296`
    - `13: r0 = *(u32 *)(r2 +0)`
    - `14: if r0 >= 0x1 goto pc+3`
    - `15: r0 <<= 6`
    - `16: r0 += r1`
    - `17: goto pc+1`
    - `18: r0 = 0`
    - `19: if r0 == 0x0 goto ...`
- The rotate scanner misses this program because clang is **not** emitting the two shapes currently matched by `find_rotate_sites_xlated()`.
- For constant `micro_rotl64(value, N)` callsites, clang does **not** materialize `shift &= 63U` as an `and64`.

## First 50 xlated instructions

The first `50` xlated instructions are still in the verifier-added map lookup + byte-recomposition prelude. They do **not** contain the hot rotate idioms yet. The first rotate shows up later, at xlated insn `129`.

## What clang actually emits

### 1. `rotl64(..., 16)` with an inserted spill

First xlated rotate instance:

```text
129: (bf) r5 = r8
     bf 85 00 00 00 00 00 00
130: (7b) *(u64 *)(r10 -16) = r8
     7b 8a f0 ff 00 00 00 00
131: (77) r5 >>= 48
     77 05 00 00 30 00 00 00
132: (67) r8 <<= 16
     67 08 00 00 10 00 00 00
133: (4f) r8 |= r5
     4f 58 00 00 00 00 00 00
```

Equivalent ELF neighborhood:

```text
123: bf 85 00 00 00 00 00 00  r5 = r8
124: 7b 8a f0 ff 00 00 00 00  *(u64 *)(r10 - 0x10) = r8
125: 77 05 00 00 30 00 00 00  r5 >>= 0x30
126: 67 08 00 00 10 00 00 00  r8 <<= 0x10
127: 4f 58 00 00 00 00 00 00  r8 |= r5
```

This is logically a rotate, but the first copy is separated from the shifts by a stack spill, so it is not a contiguous 4-insn match.

### 2. `micro_rotl64(v, 21)` emits a 4-insn rotate with the shifts in the opposite order

```text
212: (bf) r4 = r8
     bf 84 00 00 00 00 00 00
213: (77) r4 >>= 43
     77 04 00 00 2b 00 00 00
214: (67) r8 <<= 21
     67 08 00 00 15 00 00 00
215: (4f) r8 |= r4
     4f 48 00 00 00 00 00 00
```

This is the classic rotate dataflow, but as:

```text
mov64_x, rsh64_k, lsh64_k, or64_x
```

not:

```text
mov64_x, lsh64_k, rsh64_k, or64_x
```

### 3. `micro_rotl64(v, 13)` emits a 5-insn two-copy form

This is the key answer for `micro_rotl64(v, 13)`:

```text
220: (bf) r6 = r4
     bf 46 00 00 00 00 00 00
221: (77) r6 >>= 51
     77 06 00 00 33 00 00 00
222: (bf) r5 = r4
     bf 45 00 00 00 00 00 00
223: (67) r5 <<= 13
     67 05 00 00 0d 00 00 00
224: (4f) r5 |= r6
     4f 65 00 00 00 00 00 00
```

Equivalent ELF bytes:

```text
214: bf 46 00 00 00 00 00 00  r6 = r4
215: 77 06 00 00 33 00 00 00  r6 >>= 0x33
216: bf 45 00 00 00 00 00 00  r5 = r4
217: 67 05 00 00 0d 00 00 00  r5 <<= 0x0d
218: 4f 65 00 00 00 00 00 00  r5 |= r6
```

So for `rotl64(v, 13)`, clang emits:

```text
mov64_x, rsh64_k, mov64_x, lsh64_k, or64_x
```

with both `mov`s reading from the same source register.

### 4. Other rotate sites follow the same two families

Examples from xlated output:

```text
263: (bf) r3 = r1
264: (77) r3 >>= 47
265: (bf) r2 = r1
266: (67) r2 <<= 17
267: (4f) r2 |= r3
```

```text
269: (bf) r3 = r4
270: (77) r3 >>= 32
271: (67) r4 <<= 32
272: (4f) r4 |= r3
```

That is:

- `rotl64(..., 17)`: `mov, rsh, mov, lsh, or`
- `rotl64(..., 32)`: `mov, rsh, lsh, or`

## Why the current scanner does not match

Current matcher in `micro/runner/src/kernel_runner.cpp` only accepts:

1. 4-insn classic:

```text
mov tmp, src
lsh src, N
rsh tmp, 64-N
or  src, tmp
```

2. 6-insn masked-32 variant:

```text
mov64 tmp, src
and64 tmp, mask
rsh64 tmp, 32-N
mov64 dst, src
lsh64 dst, N
or64  dst, tmp
```

The real xlated output here differs in three important ways:

1. The 64-bit rotate often appears as `mov, rsh, lsh, or`.
   - Same dataflow as the classic rotate.
   - Different instruction order.

2. `rotl64(..., 13)` / `rotl64(..., 17)` often appear as `mov, rsh, mov, lsh, or`.
   - Two copies from the same source register.
   - Left-shift result lives in a different register from the original source.
   - No `and64`.

3. Some sites have an intervening stack spill before the shifts.
   - Example: xlated `129-133`.
   - Exact contiguous matching misses these sites even if the core rotate shape is recognizable.

## Answers to the task questions

### a. Exact BPF opcode pattern for `micro_rotl64(v, 13)`

For this program, clang emits:

```text
MOV64_X, RSH64_K, MOV64_X, LSH64_K, OR64_X
```

Concrete example (`xlated 220-224`):

```text
bf 46 00 00 00 00 00 00   r6 = r4
77 06 00 00 33 00 00 00   r6 >>= 51
bf 45 00 00 00 00 00 00   r5 = r4
67 05 00 00 0d 00 00 00   r5 <<= 13
4f 65 00 00 00 00 00 00   r5 |= r6
```

### b. Does `shift &= 63U` create an extra `AND` here?

No, not for these callsites.

Because all shifts in `rotate64_hash.bpf.c` are compile-time constants (`13`, `16`, `17`, `21`, `32`), clang folds away both:

- `shift &= 63U`
- `if (shift == 0) return value;`

No rotate-site `and64` is present in either the ELF or xlated dump.

### c. Does the 4-insn pattern match if we just ignore an `AND`?

No.

Ignoring an `AND` would not fix this benchmark, because the mismatch is primarily:

- shift order (`rsh` before `lsh`), and
- a 5-insn two-copy form for many 64-bit rotates.

The current 6-insn masked matcher is also hardcoded to a `32`-bit width, so it is not relevant to these `64`-bit rotates.

### d. What needs to change in `find_rotate_sites_xlated()`

At minimum:

1. Accept the commuted 4-insn classic form:

```text
mov64 tmp, src
rsh64 tmp, 64-N
lsh64 src, N
or64  src, tmp
```

2. Add a 5-insn 64-bit split-source form:

```text
mov64 tmp, src
rsh64 tmp, 64-N
mov64 dst, src
lsh64 dst, N
or64  dst, tmp
```

Required constraints for the 5-insn form:

- both `mov64` instructions read the same `src`
- `rsh64` operates on the first temp
- `lsh64` operates on the second temp / destination
- `or64 dst, tmp`
- `lsh_imm + rsh_imm == 64`

Recommended implementation order:

1. Match the 5-insn 64-bit split-source form first
2. Match the existing 6-insn masked-32 form
3. Match the 4-insn classic form, but allow either `lsh/rsh` order

Optional improvement if the goal is to catch every rotate site in this program:

- tolerate a single harmless stack spill/load-store bookkeeping instruction between the initial copy and the shift pair, e.g. the xlated `129-133` shape.

This last part is not necessary to avoid the current `0 sites found` result, because there are many later rotate sites in contiguous 4-insn or 5-insn form once the matcher is generalized.

## Bottom line

The failure is **not** caused by `shift &= 63U` creating an extra `and64` in this benchmark.

The real issue is that clang emits 64-bit rotates here as:

- `mov, rsh, lsh, or`, or
- `mov, rsh, mov, lsh, or`

while the scanner only recognizes:

- `mov, lsh, rsh, or`, or
- `mov, and, rsh, mov, lsh, or` with `32`-bit width.
