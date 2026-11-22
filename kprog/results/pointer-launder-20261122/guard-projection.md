# Class B: the 32-bit guard does not narrow the 64-bit offset (OMP 2026-11-22T17:40Z)

Request 11 of the OTel capture failed the stock verifier at insn 301,
`bpf_probe_read_user#112`, "R1 unbounded memory access". The cause is a bound
that is lost at a PHI merge, not at the shift:

```
222: r5 = *(u32 *)(r7 + 56)          ; R5=scalar(smax=umax=0xffffffff)
235: if w5 > 0x9 goto ...            ; first visit: R5 narrowed to 9
297: r5 <<= 6                        ; first visit: smax=576, accepted
315: r5 = *(u32 *)(r7 + 0x38)        ; second (loop re-entry) visit: reload
316: w5 = w5                         ; re-widened
318: w5 = w5
245: if r4 > 0x9 goto ...            ; narrows r4, a 32-bit copy, never r5
297: r5 <<= 6                        ; smax=umax=0x3fffffffc0
300: r1 += r5                        ; smax=umax=0x3ffffffffc on map_value
301: call bpf_probe_read_user#112    ; REJECTED: bound 274877906940 > 536870912
```

`r4` is made from `r5` at insns 347-350 (`r4 = r5; r4 <<= 0x20; r4 >>= 0x20`),
so the re-entry guard narrows a different register than the one the scaling
reads.

## Where the bound is lost, in the pre-bounds IR

`/tmp/r11in.ll` (the bounds pass's own input):

```
11938: %6117 = phi i64 [ %6111, %6109 ], [ %6015, %6078 ]
11923:   %6111 = ptrtoint ptr %6083 to i64
11924:   %6112 = and i64 %6111, 4294967295      ; the 32-bit projection
11925:   %6113 = icmp ult i64 %6112, 10          ; the guard, on the projection
12063: %6161 = trunc i64 %6117 to i32             ; the PHI's only real use
12065: %6162 = zext i32 %6161 to i64
12269: %6260 = shl nuw nsw i64 %6162, 6
```

The PHI carries the unprojected 64-bit value into the merge, so the value the
shift scales is the one the guard did not test. `%6117`'s only non-debug use
is that `trunc`, so the low 32 bits are all any consumer reads.

## The pass

`carry_guard_projections` in `kprog/x86/packet_bounds_ir.cpp`, run after
`fold_equality_edges`. For every `i64` (wider than 32-bit) PHI whose every
non-debug use is a `trunc` to `i32` or an `and` with `0xffffffff`, and for
every incoming arm whose block ends in a conditional branch on an `icmp`
against a constant: if one side of that compare is the arm's own low-32
projection (`and` with `0xffffffff`, or `trunc` to `i32`), the arm becomes
that projection. Same width only, so the carried value is the register the
compare narrows: a widening inserted before the terminator would not be
narrowed by the branch.

Semantically free: the arm differs from the old value only above bit 31, and
every real use reads only bits 0-31.

## Measured

`packet-bounds` sha256 `0da716379705aa65925306ba5ec6c7f4e61108aa8686112af663b4e3a4bf7517`,
`packet_bounds_ir.cpp` sha256 `737e83300a5cadeb6652e67a246a6f8dd123573fce136657c8e436f210c6070c`.

Rewritten arm (the pass prints `guard projections carried onto PHI arms=1`):

```
10112: %5717 = and i64 %5716, 4294967295
10115: %5718 = icmp ult i64 %5717, 10
10120: %5722 = phi i64 [ %5717, %5714 ], [ %5627, %5685 ]
```

Both arms now bounded: `%5717` is dominated by its own `icmp ult`, `%5627` is
`zext i32 %5626` dominated by `%5694 = icmp ult i32 %5636, 10`.

Verdict, `BPF_PROG_LOAD` on the host kernel, prog_type 7:

| | first failure | text |
|---|---|---|
| before | insn 301 | `R1 unbounded memory access` (errno 13) |
| after | insn 556 | `math between map_value pointer and register with unbounded min value is not allowed` (errno 22) |

Processed insns rise from 353 to 29210 because the program now verifies 29210
instructions before reaching the next class instead of stopping at the first
one. Class B is closed on r11; insn 556 is a separate, pre-existing shape
(`r4 -= r1` with a `map_value` destination and a scalar loaded from the
stack) that was masked by the earlier failure — its bytes are identical in
`/tmp/pre11` and `/tmp/rrr11`.

## Scope

The pass fires on exactly one module of the 14: r11. For all 13 others the
bounds output is byte-identical to the previous build (`cmp` on every
`trusted_x86.bpf.bounds.bc`). The six accepted requests keep their verdicts
(r3 127, r4 105, r6 33, r9 139, r10 84, r12 12 relocations, all ACCEPTED).