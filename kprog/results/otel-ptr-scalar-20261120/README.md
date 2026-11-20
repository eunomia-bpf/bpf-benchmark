# OTel's fallbacks: `scalar -= pointer`, two verifier messages, one cause (OMP 2026-11-20T06:45Z)

Request 7 (`526c5a5b`) of the OTel capture fails verification at insn 3137 with

```
math between fp pointer and register with unbounded min value is not allowed
```

I first read that as `check_reg_sane_offset`'s `smin == S64_MIN` test, then "corrected" it to
`R%d tried to subtract pointer from scalar`. Both are right; they are **two branches of one illegal form**,
`ALU64 SUB` with a scalar destination and a pointer source. Which message appears depends only on whether the
scalar still has a bound:

| scalar on the left | message | errno |
|---|---|---|
| bounded (`r1 = 24`) | `R1 tried to subtract pointer from scalar` (verifier.c:14990) | 13 |
| unbounded (`r1` reloaded from a spill of `ctx`) | `math between fp pointer and register with unbounded min value` (verifier.c:14503) | 13 |

Mechanism: `adjust_scalar_min_max_vals` sends any pointer operand to `adjust_ptr_min_max_vals`, which runs
`check_reg_sane_offset` on **both** the offset register and the pointer at line 14931. An unbounded scalar
fails there first; a bounded one passes it and is then rejected by the `BPF_SUB` branch at 14990. Either way
the program is refused; the exact text is cosmetic.

## Reproduced by hand, minimal

`otel_shape.o` holds exactly the eight instructions OTel emits at 3134–3137, hand-assembled so nothing else
can be responsible:

```
r1 = 24; *(u64*)(fp-152) = r1;      # scalar, bounded
r2 = fp; r2 += -128;
r1 = *(u64*)(fp-152);                # reload (OTel's is from a map: unbounded)
r1 -= r2                             # scalar -= fp pointer
```

Bounded reload → `R1 tried to subtract pointer from scalar`. The same object with the spill replaced by a
reload of `ctx` (unbounded) → `math between fp pointer and register with unbounded min value`, i.e. the
message the real request shows. Both on the host; the guest kernel 7.0.0-rc2+ rejects both the same way.

## What this means for the emitter

`24 - d < 8` must not be formed as `constant - scalar` when `d` came from a pointer arithmetic chain that the
anchoring pass turned back into a scalar (`pointer_difference`); the natural fix is to stop creating the
subtraction at all and emit the equivalent range test:

```
24 - d < 8   ⟺   16 < d < 25
```

which keeps `d` a plain scalar and forms no `scalar - pointer`. This applies to the 13 fallbacks in the
`verified-coverage-20261120` record that share this shape.

Files: `otel_shape.o` (hand-assembled), `scalar_minus_pointer.bpf.c` (C form), `rewritten_bounds.bpf.c`
(accepted alternative), `vlog.c` (static loader: `gcc -static -o vlog vlog.c`; `vlog <obj> classifier 3`,
exit 0 = ACCEPT, 1 = REJECT, prints the verifier log).
