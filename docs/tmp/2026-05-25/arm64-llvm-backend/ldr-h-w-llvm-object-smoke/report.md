# ARM64 LLVM backend: LDRH/LDR_W LLVM object smoke

Date: 2026-05-25.

## Conclusion

`LDRH` and `LDR_W` selected-safe LLVM emission is implemented and passed local object smoke.

Results:

- ARM64 all-disable: 29 objects, 0 kfunc externs.
- ARM64 wide-load treatment: 29 objects, 26 `bpf_arm64_*` symbols, 0 `bpf_x86_*` symbols.
- ARM64 treatment relocations:
  - `bpf_arm64_ldrh`: 11 relocations in 4 objects.
  - `bpf_arm64_ldr_w`: 43 relocations in 21 objects.
  - `bpf_arm64_ldr_x`: 8 relocations in 1 object.
- Scoped x86 wide-load: 29 objects, 26 `bpf_x86_*` symbols, 0 `bpf_arm64_*` symbols.
- `bpf_arm64_ldrb` is intentionally absent.

This is a local object-emission gate. AWS runtime correctness and performance attribution are not
covered by this report.

## Project Progress

The project goal is to add an ARM64 kinsn-aware path inside LLVM's BPF backend.

| Family | Status |
|---|---|
| REV | development-complete on micro |
| EXTR | development-complete on micro |
| UBFM | development-complete on micro |
| LDR | partial; `LDR_X` and `LDRH/LDR_W` selected-safe subsets are development-complete on micro; `LDRB` normal selector is deferred |
| STR | design-complete; direct-store selector deferred |
| LDP/STP | not started |
| CSEL | design-complete; next gate is LLVM implementation |
| CCMP/CMP/CSET | not started |
| PRFM | not started |
| MOV | not started |

## Code Changes

LLVM submodule:

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm
```

Changed files:

```text
llvm/lib/Target/BPF/BPFInstrInfo.td
llvm/lib/Target/BPF/BPFAsmPrinter.cpp
llvm/lib/Target/BPF/BPFKinsnSelect.cpp
llvm/test/CodeGen/BPF/kinsn-arm64-ldr-select.ll
```

Implementation summary:

- Added `BPF_KINSN_ARM64_LDRH` and `BPF_KINSN_ARM64_LDR_W`.
- Reused ARM64 LDR payload packing with shift 1 and shift 2.
- Extended ARM64 `collectWideLoadLE()` width mapping:

```text
width 2 -> bpf_arm64_ldrh
width 4 -> bpf_arm64_ldr_w
width 8 -> bpf_arm64_ldr_x
```

## Validation

Targeted FileCheck output:

```text
load16_le: kinsn_sidecar 0, 33, 0; kinsn_call bpf_arm64_ldrh
load32_le: kinsn_sidecar 0, 65, 0; kinsn_call bpf_arm64_ldr_w
load64_le: kinsn_sidecar 0, 257, 0; kinsn_call bpf_arm64_ldr_x
```

Object summary:

```text
attempt             objects  kfunc_symbols  kfunc_relocations  arm64_symbols  x86_symbols  LDRH relocations  LDR_W relocations  LDR_X relocations
arm64-all-disable   29       0              0                  0              0            0                 0                  0
arm64-wide-load     29       26             62                 26             0            11                43                 8
x86-wide-load       29       26             62                 0              26           0                 0                  0
```

Summary data:

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-llvm-object-smoke/data
```

Files:

- `object-symbol-summary.tsv`
- `arm64-wide-load-relocations.tsv`
- `filecheck-output-snippet.txt`

Full local experiment record:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-llvm-object-smoke
```

## Follow-up

AWS correctness, same-LLC performance attribution, and combined regression were completed after
this object smoke. Follow-up reports:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-aws-correctness
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-aws-correctness/report.md
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-performance-attribution/report.md
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-h-w-combined-regression/report.md
```

`STR` design was completed after that and concluded that direct-store selector should stay
deferred. The next family design target is `CSEL`.
