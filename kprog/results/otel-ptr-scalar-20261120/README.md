# OTel's fallbacks: `scalar -= pointer`, two verifier messages, one cause (OMP 2026-11-20T06:45Z)

Request 7 (`526c5a5b`) of the OTel capture fails verification at insn 3137 with

```
math between fp pointer and register with unbounded min value is not allowed
```

I first read that as `check_reg_sane_offset`'s `smin == S64_MIN` test, then "corrected" it to
`R%d tried to subtract pointer from scalar`. Both are right; they are **two branches of one illegal form**,
`ALU64 SUB` with a scalar destination and a pointer source. Which message appears depends only on whether the
scalar still has a bound:

| scalar on the left | object | message | errno |
|---|---|---|---|
| bounded (`r1 = 24`) | `bounded_scalar.o` | `R1 tried to subtract pointer from scalar` (verifier.c:14990) | **13** (EACCES) |
| unbounded (helper return, reloaded) | `unbounded_scalar.o` | `math between fp pointer and register with unbounded min value` (verifier.c:14503) | **22** (EINVAL) |

Both verified on the guest kernel 7.0.0-rc2+ as well as the host. The real OTel request shows errno 22 with
the second message, which is how it is known to take the unbounded branch.

Mechanism: `adjust_scalar_min_max_vals` sends any pointer operand to `adjust_ptr_min_max_vals`, which runs
`check_reg_sane_offset` on **both** the offset register and the pointer at line 14931. An unbounded scalar
fails there first; a bounded one passes it and is then rejected by the `BPF_SUB` branch at 14990. Either way
the program is refused; the exact text is cosmetic.

## Reproduced by hand, minimal

`otel_shape.o` holds exactly the eight instructions OTel emits at 3134–3137, hand-assembled so nothing else
can be responsible; `bounded_scalar.o` and `unbounded_scalar.o` differ only in where the scalar comes from:

```
r1 = 24; *(u64*)(fp-152) = r1;      # scalar, bounded
r2 = fp; r2 += -128;
r1 = *(u64*)(fp-152);                # reload (OTel's is from a map: unbounded)
r1 -= r2                             # scalar -= fp pointer
```

`bounded_scalar.o` (the constant `24` spilled and reloaded) → `R1 tried to subtract pointer from scalar`,
errno 13. `unbounded_scalar.o` (a `bpf_ktime_get_ns()` return spilled and reloaded, so `smin == S64_MIN`) →
`math between fp pointer and register with unbounded min value`, errno 22 — the message and errno the real
request shows. Host and guest agree on both.

## Summary of the mechanism, in one place

1. The program forms a pointer difference against a **stack slot address** (`%fp - 128`) — OTel's
   `bpf_ringbuf_reserve` payload pointer case.
2. `anchor_pointer_differences()` turns the difference into an opaque scalar, but the *next* step subtracts
   that scalar from a constant, which re-enters the same 64-bit `ALU64|SUB|X` form with a pointer operand.
3. Concretely, in request 7's IR the subtracted pointer is `%13 = alloca %union.x86_sim_stack_mem` — the
   simulator's own frame — and **52 of the 55** `constant - scalar` sites in that module have a scalar chain
   reaching it (`trace.py` counts them).
4. `adjust_ptr_min_max_vals` refuses it: unbounded scalar → errno 22 (`unbounded min value`), bounded → errno
   13 (`tried to subtract pointer from scalar`), and if the pointer is the destination → errno 13
   (`subtraction from stack pointer prohibited`). Four variants, one form, all in
   `kernel/bpf/verifier.c` 14931 / 14990 / 14999.

## What this means for the emitter

`24 - d < 8` must not be formed as `constant - scalar` when `d` came from a pointer arithmetic chain that the
anchoring pass turned back into a scalar (`pointer_difference`); the natural fix is to stop creating the
subtraction at all and emit the equivalent range test:

```
24 - d < 8   ⟺   16 < d < 25
```

which keeps `d` a plain scalar and forms no `scalar - pointer`.

## Scope, from the capture's own journal (`otel-requests.jsonl`)

OTel served 14 requests over 14 distinct programs and installed 4. Reading every request's
`simulator-failure.json` rather than the aggregated reason counts:

| request | program | outcome |
|---|---|---|
| 3, 4, 6, 12 | 33, 40, 53, 90 | installed (`checked-sim-c`) |
| **7, 9, 10, 13, 14** | **60, 72, 78, 97, 103** | `math between fp pointer and register with unbounded min value` |
| 1 | — | `R1 invalid mem access 'scalar'` |
| 2, 5, 8 | — | `R0 invalid mem access 'scalar'` |
| 11 | — | `R1 unbounded memory access` |

Every one of the five rejects on the same instruction and the same message — the destination differs because
the compiler picked a different register, the loaded pointer register differs for the same reason:

| request | PC | failing insn | scalar register |
|---|---|---|---|
| 7 | 3137 | `r1 -= r2` | `r1` = stack reload, `smin == S64_MIN` |
| 9 | 4561 | `r1 -= r2` | same |
| 10 | 1583 | `r7 -= r3` | same |
| 13 | 153 | `r9 -= r1` | `r9` = `kprog_unspec` map load, unbounded |
| 14 | 130 | `r9 -= r2` | same |

(`requests/*.json` holds each site verbatim from the capture.) So this shape accounts for
**5 of OTel's 10 fallbacks, on 5 distinct programs**. Fixing the emitter would
take OTel from 4/14 installed to at most 9/14, and from 4/14 programs to 9/14 programs. The remaining 5
fallbacks (`invalid mem access 'scalar'` × 4, `unbounded memory access` × 1) are a different class and are
not addressed here.

Files: `otel_shape.o` (hand-assembled), `scalar_minus_pointer.bpf.c` (C form), `rewritten_bounds.bpf.c`
(accepted alternative), `vlog.c` (static loader: `gcc -static -o vlog vlog.c`; `vlog <obj> classifier 3`,
exit 0 = ACCEPT, 1 = REJECT, prints the verifier log).

## The constraint that decides the fix: the stack pointer may not be subtracted from at all

Testing operand order shows the ban is wider than "scalar on the left". With the pointer as the
**destination** — the legal direction for every other pointer type — the stack register still fails:

```
2: (bf) r2 = r10        ; R2 = fp0
3: (07) r2 += -128      ; R2 = fp-128
4: (1f) r2 -= r1        ; ptr -= scalar
→ R2 subtraction from stack pointer prohibited   (errno 13, guest 7.0.0-rc2+ and host)
```

`vendor/linux-framework/kernel/bpf/verifier.c:14999-15003`, `adjust_ptr_min_max_vals`, case `BPF_SUB`:
`if (ptr_reg->type == PTR_TO_STACK) → "subtraction from stack pointer prohibited"`. The comment says the
reason is that JITs may not handle it.

So for a `PTR_TO_STACK` operand **any** subtraction involving it is refused, in either operand position:

| object | form | result |
|---|---|---|
| `stack_ptr_minus_scalar.o` | `fp_ptr -= scalar` | REJECT 13, `subtraction from stack pointer` |
| `scalar_minus_stack_ptr.o` | `scalar -= fp_ptr` | REJECT 13, `tried to subtract pointer from scalar` |
| `bounded_scalar.o` | `24 -= fp_ptr` | REJECT 13, same |
| `unbounded_scalar.o` | `helper_scalar -= fp_ptr` | REJECT 22, `unbounded min value` |

This is why the `16 < d < 25` rewrite is the right shape: it never forms a subtraction with the stack
pointer as an operand at all. Merely swapping operands does not help.


## Re-confirmed on the guest kernel (OMP 2026-11-20T17:5xZ), and the fix shape passes

Re-ran the decisive objects through the static verifier inside the guest (kernel 7.0.0-rc2+, `vlog_s`, rebuilt
from `vlog.c`), after a first attempt segfaulted because the object paths were not in the guest's working
directory:

| shape | verdict |
|---|---|
| `stack_ptr - scalar` | REJECT errno=13, `R1 tried to subtract pointer from scalar` |
| `scalar - stack_ptr` | REJECT errno=13, `R2 subtraction from stack pointer prohibited` |
| bounded scalar operand | REJECT errno=13, `R1 tried to subtract pointer from scalar` |
| `(u64)ctx > 0x18` / `(u64)ctx < 0x11` (i.e. `16 < d < 25`) | **ACCEPT** |

So a `PTR_TO_STACK` operand cannot take part in a subtraction in either position, bounding the scalar does not
help, and the shape that removes the subtraction entirely is accepted. That is the whole requirement for the
5 OTel fp-arithmetic fallbacks: eliminate the subtraction rather than reorder or bound it.
