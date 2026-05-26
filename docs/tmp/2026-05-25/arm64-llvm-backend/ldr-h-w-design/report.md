# ARM64 LLVM backend: LDRH/LDR_W design

Date: 2026-05-25.

## Conclusion

The load-side implementation should add only:

```text
bpf_arm64_ldrh
bpf_arm64_ldr_w
```

as selected-safe `wide-load` byte-ladder collapses.

Do not add a normal `bpf_arm64_ldrb` selector in this step. A direct single-byte load is already
ordinary BPF `LDB` / `LDB32`; replacing it with a kfunc whose proof expansion is the same
`BPF_LDX_MEM(BPF_B)` does not create a useful optimization.

## Current Progress

The ARM LLVM backend goal is to emit ARM64 kinsn requests from LLVM's BPF backend:

```text
BPF MachineInstr pattern
  -> ARM64 kinsn pseudo
  -> KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
  -> verifier proof expansion
  -> ARM64 module native lowering
```

Current family status:

| Family | Status |
|---|---|
| REV | development-complete on micro |
| EXTR | development-complete on micro |
| UBFM | development-complete on micro |
| LDR | partial; `LDR_X` selected-safe subset is development-complete on micro; `LDRH/LDR_W` design is complete and later passed LLVM object smoke; `LDRB` normal selector is deferred |
| STR | design-complete; direct-store selector deferred |
| LDP/STP | not started |
| CSEL | design-complete; next gate is LLVM implementation |
| CCMP/CMP/CSET | not started |
| PRFM | not started |
| MOV | not started |

## ABI

Source:

```text
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_ldr.c
```

All LDR kfuncs share the same payload:

| bits | field | constraint |
|---|---|---|
| 0..3 | dst_reg | `< BPF_REG_10`; cannot write `r10` |
| 4..7 | base_reg | `<= BPF_REG_10`; `r10` base is allowed |
| 8..23 | offset | signed 16-bit |
| 24..63 | reserved | must be zero |

ARM64 offset encoding constraints:

| kfunc | size | scaled unsigned offset | unscaled signed offset |
|---|---:|---|---|
| `bpf_arm64_ldrh` | 2 | `0 <= off <= 0xfff << 1`, 2-byte aligned | `-256 <= off <= 255` |
| `bpf_arm64_ldr_w` | 4 | `0 <= off <= 0xfff << 2`, 4-byte aligned | `-256 <= off <= 255` |

LLVM must fail fast if the payload or native offset cannot be encoded.

## Design

Implement:

| kfunc | selector source | proof expansion | native lowering |
|---|---|---|---|
| `bpf_arm64_ldrh` | little-endian 2-byte `wide-load` ladder | `BPF_LDX_MEM(BPF_H, dst, base, off)` | `LDRH Wd, [Xn, #off]` |
| `bpf_arm64_ldr_w` | little-endian 4-byte `wide-load` ladder | `BPF_LDX_MEM(BPF_W, dst, base, off)` | `LDR Wd, [Xn, #off]` |

Do not implement direct `LDH` / `LDW` replacement as the first step. Ordinary BPF already
represents those loads directly. The useful case is collapsing byte recomposition:

```text
LDB32 + shift/or + LDB32 ...
  -> LDRH or LDR_W kinsn
```

The existing LLVM selector already has `collectWideLoadLE()` for width 2 / 4 / 8. The current
ARM64 branch only accepts width 8 and maps it to `BPF_KINSN_ARM64_LDR_X`. The next patch should
extend that mapping:

```text
width 2 -> BPF_KINSN_ARM64_LDRH  -> bpf_arm64_ldrh
width 4 -> BPF_KINSN_ARM64_LDR_W -> bpf_arm64_ldr_w
width 8 -> BPF_KINSN_ARM64_LDR_X -> bpf_arm64_ldr_x
```

Keep the first implementation conservative: reuse existing `validateWideLoadLanes()` constraints
and do not broaden unaligned-offset handling in the same patch.

## Evidence

Raw evidence files:

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-design/data/ir-load-counts.tsv
code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-design/data/x86-wide-load-proxy.tsv
```

The LLVM IR has many direct loads, but direct-load count is not enough to justify kfunc selection:

| IR load | instances | objects |
|---|---:|---:|
| `load i8` | 744 | 26 |
| `load i16` | 2 | 1 |
| `load i32` | 63 | 29 |
| `load i64` | 2 | 1 |

The better proxy is the existing x86 scoped `wide-load` result, because it uses the same
`collectWideLoadLE()` matcher:

| x86 kfunc | relocations | objects |
|---|---:|---:|
| `bpf_x86_movzwl` | 11 | 4 |
| `bpf_x86_movl` | 43 | 21 |
| `bpf_x86_movq` | 8 | 1 |

This suggests `LDRH` and `LDR_W` should have broader coverage than the already-completed `LDR_X`
subset.

## Implementation Checklist

1. Add `BPF_KINSN_ARM64_LDRH` and `BPF_KINSN_ARM64_LDR_W` pseudos.
2. Reuse `packARM64LdrPayload()` in `BPFAsmPrinter.cpp` with shift 1 and shift 2.
3. Extend ARM64 `collectWideLoadLE()` width mapping for 2 and 4.
4. Extend `isARM64LdrPseudo()`.
5. Add FileCheck for width 2, width 4, target isolation, and `all=disable`.
6. Run local object smoke.
7. Run AWS selected correctness, then full micro correctness.
8. Run same-LLC performance attribution.
9. Run combined regression with `REV+EXTR+UBFM+LDR_X+LDRH+LDR_W`.

## Next Step

`LDRH` / `LDR_W` selected-safe subset was implemented after this design note and later passed
local object smoke, AWS correctness, same-LLC performance attribution, and combined regression.
Follow-up records:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-llvm-object-smoke
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-llvm-object-smoke/report.md
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-aws-correctness
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-aws-correctness/report.md
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-performance-attribution/report.md
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-h-w-combined-regression/report.md
```

Keep `LDRB` deferred until there is a non-redundant pattern that ordinary BPF cannot already
express compactly. `STR` design was also completed after this note and concluded that direct-store
selector should stay deferred. The next family design target is `CSEL`.
