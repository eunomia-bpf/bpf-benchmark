# Pointer-difference launder in the packet-bounds pass

2026-11-22, OMP lane. Change: `kprog/x86/packet_bounds_ir.cpp`.

## What was wrong

B's `rX -= rY` sites subtract the simulator frame (`r10 + off`) from an
integer scalar. The verifier refuses that: `scalar -= fp` is
`R7 tried to subtract pointer from scalar`. `anchor_pointer_differences` and
the direct rewrite already removed the subtraction, but the replacement
value kept the frame's stack-pointer type, so the anchored asm
(`"$0 -= $2"`) still handed the verifier a pointer operand.

## The launder

The verifier drops a value's pointer type only across a mixed-slot stack
round trip that ends in a **32-bit register self-move**:

```
st64  ptr -> slot        ; slot now holds a stack-pointer value
<32-bit self-move>       ; type destroyed: bc / "w1 = w1"
st32  laundered -> slot  ; stored from the laundered register
ld64  slot               ; scalar
```

Probed directly against `BPF_PROG_LOAD` (prog_type 1, syscall 321, cmd 5):

|Encoding|Verdict|
|---|---|
|`scalar(5) -= r7(fp-8)`|REJECTED `R6 tried to subtract pointer from scalar`|
|`r1(scalar=0) += r2(fp-64)`; then `r0 -= r1`|REJECTED — `+=` result stays `fp-64`, so `scalar += ptr` does not launder|
|`st64 ptr` then `st32` straight from the same register|REJECTED `invalid size of register spill`|
|`st64 ptr` then `stx32` of a fresh 32-bit load of the slot|REJECTED `invalid size of register fill`|
|`st64 ptr` then `r1 = r1` (`bf`, 64-bit self-move)|REJECTED `invalid size of register spill` — `bf` keeps the pointer|
|`st64 ptr` then `w1 = w1` (`bc`, 32-bit self-move) then `stx32` then `ld64`|**ACCEPTED**|
|any 32-bit ALU op on the pointer (`xor32 0`, `or32 0`, `and32 -1`, `mul32 1`, `lsh32 0`, `add32 0`)|REJECTED `32-bit pointer arithmetic prohibited`|
|`scalar += frame` (the `outers` product)|ACCEPTED|

## How the pass emits it

`frame_scalar` (entry block, after every alloca of the block) materialises
the frame once per frame alloca:

```llvm
%frame_scalar_slot = alloca i64
%frame_address = ptrtoint ptr %frame to i64
store volatile i64 %frame_address, ptr %frame_scalar_slot
%3 = call i64 asm sideeffect "r1 = $1\012w1 = w1\012$0 = r1", "=r,r,~{r1}"(i64 %frame_address)
store volatile i32 (trunc %3), ptr %frame_scalar_slot     ; 32-bit store of the laundered register
%frame_scalar = load volatile i64, ptr %frame_scalar_slot
```

Three points are load-bearing:

1. The asm takes and returns **i64**. Truncating the pointer to i32 before
   the asm makes clang build the 32-bit value with `r2 <<= 32`, and the
   verifier refuses any 32-bit shift of a pointer. The truncation happens
   after the asm, where the value is already a scalar.
2. The asm text names **literal registers**, not `$` placeholders
   (`"r1 = $1 ; w1 = w1 ; $0 = r1"`). A one-line `"w1 = w1"` lets the
   backend rematerialise the frame into a different register for the 32-bit
   store, so the stored register is not the laundered one.
3. `r1` is declared clobbered so the register allocator keeps the input
   live across the asm.

The newline must be written as the octal escape `\012`. `\0A` inside a C++
string literal terminates the string after `\0`, leaving `A` as a stray
character, and clang then silently drops the asm.

## Result on OTel request 10

`stack pointer subtractions eliminated` 72 → 149; `pointer differences
anchored` 77 → 77.

|B|Verdict|
|---|---|
|archived, pre-fix|REJECTED `insn 1583: (1f) r7 -= r3` — `R7 tried to subtract pointer from scalar`|
|with the launder|**ACCEPTED**, `processed 7299 insns`|

Both were loaded with `BPF_PROG_LOAD` (prog_type 1) after resolving the
object's map relocations to maps built from `kernel.metadata.json`.

## Regression

Every archived request (`/tmp/ocov/r*`, `/tmp/bcov/b*`): no elimination
count falls. Twelve rise: OTel r10 72→149, r9 118→274, r3 69→172,
r5 2→22, r11 7→10; BCC b17 0→39, b20 0→26, b22 0→39, b3 0→14,
b12 0→1, b18 0→1, b24 0→2.

Accept/reject status was re-measured on both the archived B and the new B
for all 37 archived requests (`ab-all-requests.txt`), each loaded with
`BPF_PROG_LOAD` after resolving the object's map relocations against maps
built from the request's `kernel.metadata.json`/`generation.metadata.json`
(a map carrying `value_offset` is relocated with `BPF_PSEUDO_MAP_VALUE`,
everything else with `BPF_PSEUDO_MAP_FD`). The harness reproduces every
archived `verify.stdout` verdict, so it is a faithful stand-in for the
loader's B step.

OTel r10 and r9 go REJECTED → ACCEPTED. No request changes
ACCEPTED → REJECTED, and the 18 requests the archive records as accepted
stay accepted.