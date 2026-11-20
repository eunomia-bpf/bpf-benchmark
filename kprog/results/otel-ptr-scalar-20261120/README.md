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

So this shape accounts for **5 of OTel's 10 fallbacks, on 5 distinct programs**. Fixing the emitter would
take OTel from 4/14 installed to at most 9/14, and from 4/14 programs to 9/14 programs. The remaining 5
fallbacks (`invalid mem access 'scalar'` × 4, `unbounded memory access` × 1) are a different class and are
not addressed here.

Files: `otel_shape.o` (hand-assembled), `scalar_minus_pointer.bpf.c` (C form), `rewritten_bounds.bpf.c`
(accepted alternative), `vlog.c` (static loader: `gcc -static -o vlog vlog.c`; `vlog <obj> classifier 3`,
exit 0 = ACCEPT, 1 = REJECT, prints the verifier log).
