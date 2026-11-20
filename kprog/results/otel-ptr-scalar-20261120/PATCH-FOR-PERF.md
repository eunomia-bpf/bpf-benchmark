# fp-arithmetic class: the transform is pinned, the patch is one function

For PERF (owner of `kprog/x86/packet_bounds_ir.cpp`). OMP 2026-11-20. Everything below is verified on the guest
kernel (7.0.0-rc2+); the change itself is not made, because the file is yours and no open freeze row covers this
class (the rows for it expire 2026-11-21).

## What fails

The five OTel fallbacks (`kprog/results/otel-ptr-scalar-20261120/`, requests 7/9/10/13/14, PCs 3137/4561/1583/
153/130) all fail on one instruction, `ALU64 SUB` with a `PTR_TO_STACK` operand, and the whole class reduces to:

```
r1 = 24; *(u64 *)(fp-152) = r1     # scalar (OTel's comes from a map: unbounded)
r2 = fp; r2 += -128
r1 = *(u64 *)(fp-152)              # reload
r1 -= r2                           # scalar -= stack pointer
```

Verified on the guest, four hand-assembled objects plus two C forms:

| shape | verdict |
|---|---|
| `stack_ptr - scalar` | REJECT errno 13, `R1 tried to subtract pointer from scalar` |
| `scalar - stack_ptr` | REJECT errno 13, `R2 subtraction from stack pointer prohibited` |
| bounded scalar operand | REJECT errno 13, `R1 tried to subtract pointer from scalar` |
| `(s - p) < K` rewritten to `s < p + K` | survives both subtraction checks |
| `16 < d < 25` (subtraction removed, two pointer compares) | **ACCEPT** |

So: bounding the scalar does not help, reordering does not help, and a `PTR_TO_STACK` operand cannot participate
in a subtraction in either position. The subtraction has to go.

## The patch

`anchor_pointer_differences()` (`kprog/x86/packet_bounds_ir.cpp:200`) already finds every `sub i64` whose two
operands are pointer-derived, then wraps it in a tied inline asm `"$0 -= $2"` so the arithmetic stays on its CFG
path. That asm is exactly the instruction the verifier refuses when one operand is a stack pointer.

The transform to add beside it: for a `BinaryOperator` `Sub` whose result feeds an `ICmp` against a `ConstantInt`
`K`, and where one operand is pointer-derived while the other is a plain scalar, replace

```
%d = sub i64 %s, %p        ; %p pointer-derived, %s scalar
%t = icmp ult i64 %d, K
```

with

```
%pb = add i64 %p, K        ; (or sub i64 %p, K for the mirrored form)
%t  = icmp ult i64 %s, %pb
```

The comparison is preserved for the value range the verifier already proves for `%p` (the pointer's own offset
bounds), which is why the `16 < d < 25` C form is accepted. Guard it: apply only when the `Sub` has exactly one
`ICmp` user, `%s` is not pointer-derived, and `%p`'s provenance is `PtrToInt` (possibly through constant
`add`/`sub`) — the same `pointer_bits()` predicate the existing function already uses.

Do **not** apply it where both operands are pointer-derived: that is the ordinary pointer difference the current
anchor handles, and it verifies because neither side is `PTR_TO_STACK`.

## What it buys, and what it does not

OTel goes from 4/14 to at most 9/14 installed programs on this class. The other four OTel fallbacks
(`R invalid mem access 'scalar'`) and the one `unbounded memory access` are a different class and are untouched —
the rewritten object above is still refused by that second class, so expect the subtraction rejections to
disappear while the count only moves once that class is fixed too.

## Verification to run with the patch

`vlog` (`kprog/results/otel-ptr-scalar-20261120/vlog.c`, `gcc -static -o vlog vlog.c`) on the five captured
request objects, guest kernel, expecting `R1 tried to subtract pointer from scalar` and `math between fp pointer
and register with unbounded min value` to disappear from each; then one `checked-corpus` for OTel to read the
coverage line.