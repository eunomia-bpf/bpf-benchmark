# OTel's 13 fallbacks: `scalar - pointer` is a verifier EACCES, not an unbounded-min problem (OMP 2026-11-20T06:33Z)

Corrects the earlier reading of OTel request 7 (`526c5a5b`), which was attributed to
`check_reg_sane_offset`'s `smin == S64_MIN` test. That test is not what fires. The kernel rejects the
instruction outright:

```
R2 tried to subtract pointer from scalar
```

**Where**: `vendor/linux-framework/kernel/bpf/verifier.c:14990-14995`, `adjust_scalar_min_max_vals`, case
`BPF_SUB`:

```c
case BPF_SUB:
    if (dst_reg == off_reg) {
        /* scalar -= pointer.  Creates an unknown scalar */
        verbose(env, "R%d tried to subtract pointer from scalar\n", dst);
        return -EACCES;
    }
```

`-EACCES` = 13, which is what every OTel rejection carries. Nothing about bounds, `S64_MIN`, or
`anchor_pointer_differences()` is involved: the LLVM IR `%2030 = sub i64 24, %2027` becomes exactly
`rX = 24; rX -= rY` where `rY` still holds a pointer, and the verifier refuses the form itself.

## Reproduced on the guest kernel, not just the host

The guest kernel is 7.0.0-rc2+ (the image's own `bzImage`); the host is 7.3.0, so a host-only result would
not have settled it. Both reject, both with errno 13:

| program | form | host 7.3 | guest 7.0-rc2+ |
|---|---|---|---|
| `scalar_minus_pointer.bpf.c` | `u64 r = 24 - (u64)ctx;` | REJECT 13 | **REJECT 13** (`R2 tried to subtract pointer from scalar`) |
| `rewritten_bounds.bpf.c` | `ctx > 0x18 → 2; ctx < 0x11 → 3;` | ACCEPT | **ACCEPT** |
| control: `u64 c = 24; c - (u64)ctx` in 32-bit (`w0 -= w1`) | 32-bit ALU | ACCEPT | ACCEPT |

Note the last row: the **32-bit** form passes. The verifier's `dst_reg == off_reg` branch is reached only for
the 64-bit `ALU64|SUB|X` when the destination is the scalar; a 32-bit `w0 -= w1` over the same values is
accepted. So the trigger is precise: `ALU64 SUB` with the scalar as destination and a pointer as source.

## What a fix looks like (for whoever owns the emitter)

`24 - d < 8` is equivalent to `16 < d < 25`, which is `d > 16 && d < 25`; `d` stays a plain scalar and no
`scalar - pointer` is formed. `rewritten_bounds.bpf.c` shows the accepted shape. Alternatively keep the
subtraction but put the **pointer** on the left and the scalar on the right (`d = p - q` is legal; only
`scalar - pointer` is banned) and then compare `(d - 17) < 8` with `d >= 17`, which keeps `d` scalar
throughout.

Files: `scalar_minus_pointer.bpf.c`, `rewritten_bounds.bpf.c`, `vlog.c` (the static loader used; build
`gcc -static -o vlog vlog.c`, run `vlog <obj> classifier 3`, exit 0 = ACCEPT, 1 = REJECT with the verifier
log).
