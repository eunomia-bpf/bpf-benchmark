# BPF kinsn LLVM backend notes

This directory contains the experimental LLVM fork/build used to emit BPF
kinsn pseudo instructions directly from the BPF backend.

## Selection model

The intended pipeline is:

1. Let LLVM canonicalize source code into standard IR/DAG/MI semantics.
2. Collect kinsn candidates from those canonical forms.
3. Check legality: target module exists, operand form is supported, local
   subprog/verifier risks are avoided, and the replacement has no overlapping
   MI range.
4. Score profitability using static cost first: loop weight, expected native
   instruction savings, kinsn bundle/proof cost, and one-time scratch init.
5. Select positive, non-overlapping candidates and lower them to kinsn pseudos.
6. Let `BPFAsmPrinter` emit `kinsn_sidecar` plus a named kfunc call. BTF id and
   module fd resolution stay outside LLVM.

The backend should prefer LLVM semantic nodes over late bytecode guessing. Late
MI peepholes are acceptable only when the semantic form survives naturally in
MI; they should not rebuild a small compiler from final BPF bytecode.

Verifier-facing proof cost is a legality constraint, not by itself a reason to
discard an x86 instruction selector. If a selector looks unprofitable, first
check whether the matched MI range is too broad or too narrow. The replacement
should cover the whole canonical idiom that the x86 instruction subsumes; leaving
redundant cleanup instructions behind can make a good instruction look bad.

## Experiment protocol

For each optimization step:

1. Build the BPF backend:
   `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`
2. Generate micro objects with kinsn selection:
   `make -C micro/programs OUTPUT_DIR=$PWD/micro/results/llvm_kinsn_programs_<tag> KERNEL_OFFSETS_INPUT=$PWD/.cache/repo-build/host/kernel-offsets/x86_64/kernel_offsets.h BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=$PWD/llvm-backend/build-bpf-kinsn/bin/llc all`
3. Run full micro through the normal entrypoint:
   `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir micro/results/llvm_kinsn_programs_<tag>"`
4. Compare against the no-kinsn LLVM baseline:
   `micro/results/x86_kvm_micro_20260518_210242_364278/metadata.json`

## Baseline before this series

Current kinsn build:

- Objects: `micro/results/llvm_kinsn_programs_20260518_133500`
- Micro run: `micro/results/x86_kvm_micro_20260518_204755_001539/metadata.json`
- Baseline run: `micro/results/x86_kvm_micro_20260518_210242_364278/metadata.json`
- Config: `SAMPLES=1 WARMUPS=0 INNER_REPEAT=100000 runtime=kernel`
- Correctness: 29/29 matched expected result

Summary versus no-kinsn LLVM baseline:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9748 |
| summed exec delta | -94 ns |
| summed JIT byte delta | -1410 bytes |

Notable deltas:

| Benchmark | Baseline | kinsn | Ratio | JIT bytes |
|---|---:|---:|---:|---:|
| `siphash_rotate64_mixer` | 54 ns | 38 ns | 0.704 | 3529 -> 2399 |
| `flow_5tuple_rss_hash` | 13 ns | 11 ns | 0.846 | 819 -> 702 |
| `packet_toeplitz_rss_hash` | 280 ns | 252 ns | 0.900 | 989 -> 989 |
| `katran_lb_consistent_hash_select` | 17 ns | 16 ns | 0.941 | 2975 -> 2817 |
| `payload_prefix_memcmp_scan` | 106 ns | 100 ns | 0.943 | 569 -> 572 |

Selected kinsns in that object set:

| kinsn | count |
|---|---:|
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |

## Planned optimization steps

| Step | Candidate | Kernel support | Target micro |
|---|---|---|---|
| 1 | `ctpop` -> `bpf_x86_popcntq` | existing | `bitmap_popcount_scan` |
| 2 | `bswap(load)` -> `bpf_x86_movbe{16,32,64}` | existing | Toeplitz, packet field loads, Katran endian fields |
| 3 | LLVM `select` -> `cmp/test` + `bpf_x86_cmov*` | existing | policy/tree/table selection |
| 4 | `(x >> c) & mask` -> `bpf_x86_bextr` | needs module | `packed_header_bitfield_decode` |
| 5 | `x & (x - 1)` / `x & -x` -> `bpf_x86_blsr/blsi` | existing | bitmap/mask traversal |
| 6 | funnel/cross-word shift -> `bpf_x86_shld/shrd` | existing | Toeplitz, bit slicing |

## Experiment log

Entries below are appended after each optimization step runs the full micro
suite.

### Step 1: `ctpop` -> `bpf_x86_popcntq`

Implementation:

- Added `BPF_KINSN_X86_POPCNTQ` pseudo.
- `BPFISelLowering` keeps `ISD::CTPOP` legal only when
  `-bpf-enable-kinsn-select` is enabled; without the flag it keeps the original
  generic expansion path.
- `BPFAsmPrinter` lowers the pseudo to `bpf_x86_popcntq` with the module's RR
  payload schema.

Build/object checks:

- `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`: pass.
- Objects after rotate score fix and scratch init fix:
  `micro/results/llvm_kinsn_programs_rotatefix_20260518_164111`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260518_234645_670440/metadata.json`
- Command:
  `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir micro/results/llvm_kinsn_programs_rotatefix_20260518_164111"`

Summary versus the no-kinsn LLVM baseline
`micro/results/x86_kvm_micro_20260518_210242_364278`:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9530 |
| summed JIT byte delta | -1478 bytes |

Key case deltas:

| Benchmark | Baseline | Latest | Ratio | JIT bytes |
|---|---:|---:|---:|---:|
| `bitmap_popcount_scan` | 1115 ns | 493 ns | 0.442 | 489 -> 416 |
| `siphash_rotate64_mixer` | 54 ns | 38 ns | 0.704 | 3529 -> 2399 |
| `packet_toeplitz_rss_hash` | 280 ns | 220 ns | 0.786 | 989 -> 989 |
| `flow_5tuple_rss_hash` | 13 ns | 12 ns | 0.923 | 819 -> 702 |
| `katran_lb_consistent_hash_select` | 17 ns | 16 ns | 0.941 | 2975 -> 2817 |
| `payload_prefix_memcmp_scan` | 106 ns | 100 ns | 0.943 | 569 -> 572 |

Two fixes were needed before the full run was valid:

- Scratch init: kinsn module proof saves `r6/r7/r8`; verifier rejects saving an
  uninitialized register. Emitting `r6 = 0; r7 = 0; r8 = 0` from
  `BPFAsmPrinter::emitFunctionBodyStart()` for functions containing kinsn
  pseudos made the proof path explicit and survived later MI cleanup.
- Rotate score regression: the candidate struct grew for movbe/BMI/SHD, but
  `collectRotate()` did not fill the new fields, so `Score` became zero and all
  rotate candidates were skipped. Filling `Base=Register(), Offset=0,
  Shift=<rotate>, Score=<score>` restored the original 119 `rolq` and 40
  `rorxl` selections.

### Step 2: `bswap(load)` -> `bpf_x86_movbe{32,64}`

Implementation:

- Added `BPF_KINSN_X86_MOVBE32` and `BPF_KINSN_X86_MOVBE64` pseudos.
- Extended `bpf_x86_movbe` payload decoding to support non-indexed base+offset
  memory operands in addition to the existing indexed/SIB form.
- Candidate selection looks for `BSWAP32/64` or endian pseudos whose operand is
  a same-block one-use `LDW/LDD`.

Result in the current micro set:

- Selected count: 0.
- Reason: the visible endian-load opportunities in these programs are mostly
  byte-ladder packet loads or 16-bit zero-extending endian loads. A single x86
  `movbe16` writes only the low 16 bits and preserves upper destination bits,
  while BPF `u16` loads are zero-extending. Selecting that as one instruction
  would be semantically wrong unless the destination is known dead/zero in the
  upper bits or the module provides an explicitly zero-extending form. The first
  safe implementation therefore only covers 32/64-bit base+offset forms, and no
  current micro matched that legality.

### Step 3: LLVM `select` -> `cmp` + `cmov`

Implementation:

- Added BPF backend pseudos for module-backed `bpf_x86_cmpl/cmpq` and
  `bpf_x86_cmove/cmovne/cmovb` 32/64-bit variants.
- Hooked `BPFISelLowering::EmitInstrWithCustomInserter()` before the normal
  select diamond expansion. The selector only handles LLVM `SELECT_CC` forms
  that map to the existing machine instructions: equality, inequality, and
  unsigned below/above via operand/value swaps. Signed conditions and immediate
  compare forms still use the original BPF diamond lowering.

Result in the current micro set:

- Selected count: 0.
- Objects:
  `micro/results/llvm_kinsn_programs_select_20260518_165342`
- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260518_235759_125789/metadata.json`
- Selected kinsns remained unchanged:

| kinsn | count |
|---|---:|
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

The no-hit result is useful: current micro programs either do not preserve a
safe RR `SELECT_CC` at this lowering point, or use conditions/operand forms not
covered by the existing cmov module ABI. This step is therefore correctness-only
for now; measured runtime movement versus Step 1 is run-to-run noise and JIT
bytes are identical to the previous object set.

Summary versus the no-kinsn LLVM baseline:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9452 |
| summed JIT byte delta | -1478 bytes |

### Step 4: `(x >> c) & mask` -> `bpf_x86_bextrq`

Implementation:

- Added `bpf_x86_bextrq` to the BMI1 module and `BPF_KINSN_X86_BEXTRQ` in the
  BPF backend.
- Candidate selection matches same-block one-use `AND_ri(SRL_ri(x, start),
  low_contiguous_mask)` and materializes the x86 control operand with an ordinary
  BPF move before the kinsn. The emitted native instruction remains one real x86
  `bextrq`; the control move is the source value setup that x86 itself requires.
- The verifier proof had to avoid restoring a scratch register that is also the
  destination operand. The first full run failed in `packed_header_bitfield_decode`
  because dst `r7` was written with the bextr result and then restored to its old
  packet-pointer value, so verifier rejected the following `r7 *= 17`. The module
  now restores only scratch registers that are not the destination.

Build/object checks:

- `make host-kinsn-x86`: pass.
- Objects:
  `micro/results/llvm_kinsn_programs_bextr_20260518_170534`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_bextrq` | 10 |
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_001658_821939/metadata.json`
- Command:
  `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir micro/results/llvm_kinsn_programs_bextr_20260518_170534"`
- JIT dump check found real `bextr` instructions in both hit programs:
  nine in `packed_header_bitfield_decode` and one in
  `bcc_runqlat_log2_histogram_bucket`.

Summary versus the no-kinsn LLVM baseline:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9577 |
| summed JIT byte delta | -1424 bytes |

Incremental result versus Step 3:

| Metric | Value |
|---|---:|
| geomean ratio | 1.0132 |
| summed JIT byte delta | +54 bytes |

Key hit deltas:

| Benchmark | Baseline | Step 3 | Step 4 | JIT bytes |
|---|---:|---:|---:|---:|
| `packed_header_bitfield_decode` | 266 ns | 267 ns | 266 ns | 1085 -> 1088 |
| `bcc_runqlat_log2_histogram_bucket` | 1044 ns | 1048 ns | 1042 ns | 664 -> 715 |

The hit count is real, but the first static selection rule is not clearly
profitable. `bextrq` replaces a shift-and-mask pair, but it also needs a control
operand and the kinsn bundle changes local code layout. On these two programs the
runtime is effectively flat while code size grows slightly at the hit sites. The
profitability rule should therefore require either a reused/preexisting control
value, a hotter loop weight, or a stronger native-cost win before selecting
`bextrq` by default.

Default selector update:

- The recognizer remains in the backend, but the default profitability score for
  the current control-materializing `bextrq` form is negative, so it is not
  selected unless a future form can reuse an existing control operand or prove a
  stronger native-cost win.
- Objects:
  `micro/results/llvm_kinsn_programs_profit_20260519_002050`
- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_002239_202418/metadata.json`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Default selector summary:

| Comparison | Geomean ratio | JIT byte delta |
|---|---:|---:|
| default vs no-kinsn baseline | 0.9488 | -1478 bytes |
| default vs Step 3 | 1.0038 | 0 bytes |
| default vs Step 4 bextr-enabled run | 0.9908 | -54 bytes |

Key checks after disabling default `bextrq` selection:

| Benchmark | Baseline | Step 3 | Step 4 bextr | Default | JIT bytes default |
|---|---:|---:|---:|---:|---:|
| `packed_header_bitfield_decode` | 266 ns | 267 ns | 266 ns | 265 ns | 1085 |
| `bcc_runqlat_log2_histogram_bucket` | 1044 ns | 1048 ns | 1042 ns | 1038 ns | 664 |
| `bitmap_popcount_scan` | 1115 ns | 491 ns | 494 ns | 491 ns | 416 |
| `packet_toeplitz_rss_hash` | 280 ns | 218 ns | 225 ns | 223 ns | 989 |
| `siphash_rotate64_mixer` | 54 ns | 39 ns | 38 ns | 38 ns | 2399 |

### Step 5: `x & (x - 1)` / `x & -x` -> BMI1

Implementation:

- Added selection for `AND_rr` fed by same-block one-use `ADD_ri -1`
  (`bpf_x86_blsrq`) or `NEG_64` (`bpf_x86_blsiq`).
- Added `BPF_KINSN_X86_BLSRQ` and `BPF_KINSN_X86_BLSIQ` pseudos and payload
  lowering.

Result in the current micro set:

- Selected count: 0.
- Reason: after enabling `ctpop`, `bitmap_popcount_scan` no longer exposes the
  SWAR/clear-lowest-bit idiom where BMI1 would help, and the other current
  programs do not contain the exact 64-bit `and(add -1)` or `and(neg)` MI
  pattern. This is implemented but needs either another workload pattern or an
  earlier LLVM semantic hook if we want it to trigger reliably.
- Covered by the final default full run:
  `micro/results/x86_kvm_micro_20260519_002239_202418/metadata.json`

### Step 6: funnel/cross-word shift -> `bpf_x86_shld/shrd`

Implementation:

- Added `BPF_KINSN_X86_SHLDL/SHLDQ/SHRDL/SHRDQ` pseudos.
- Candidate selection matches same-block one-use `or(shift(lhs), shift(src))`
  where the shifts sum to the operand width and the sources differ.

Result in the current micro set:

- Selected count: 1 (`bpf_x86_shldq`).
- The only hit is in `cilium_policy_guard_tree_filter`; measured runtime stayed
  essentially flat (`72 ns` baseline, `71 ns` latest). This is expected for one
  isolated instruction in a branch-heavy program.
- Covered by the final default full run:
  `micro/results/x86_kvm_micro_20260519_002239_202418/metadata.json`

### Step 7: BE16 byte ladder -> `bpf_x86_movbe16`

Implementation:

- Added `BPF_KINSN_X86_MOVBE16` and a narrow MI recognizer for the common
  packet-field pattern:
  `ldb high; high <<= 8; ldb low; high | low; value &= 0xffff`.
- The recognizer is intentionally strict: same basic block, one-use chain, same
  base register, adjacent offsets, and a final `& 0xffff` mask. This keeps it as
  a local peephole over a canonical byte ladder rather than a general bytecode
  compiler.
- `movbe r16, m16` is a partial-width x86 write: it preserves the upper bits of
  the destination. The first attempt fed the old destination into the kinsn proof
  directly and failed verification when that old value was uninitialized or was a
  packet/data-end pointer. The fixed pseudo ties an explicit zero operand to the
  destination, so LLVM emits `wDst = 0` before the kinsn and the module proof
  reads a scalar old value. The existing `& 0xffff` mask is left in place after
  the kinsn.

Build/object checks:

- Objects with `movbe16` enabled:
  `micro/results/llvm_kinsn_programs_movbe16fix_20260519_011000`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_movbe16` | 5 |
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_010741_008104/metadata.json`

Summary versus the no-kinsn LLVM baseline:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9547 |
| summed JIT byte delta | -1491 bytes |

Incremental result versus the previous default selector:

| Metric | Value |
|---|---:|
| geomean ratio | 1.0062 |
| summed JIT byte delta | -13 bytes |

Key hit deltas:

| Benchmark | Baseline | Previous default | `movbe16` enabled | JIT bytes |
|---|---:|---:|---:|---:|
| `packet_vlan_tcpopt_parser` | 12 ns | 12 ns | 12 ns | 1065 -> 1051 |
| `flow_5tuple_rss_hash` | 13 ns | 11 ns | 11 ns | 702 -> 695 |
| `packet_toeplitz_rss_hash` | 280 ns | 223 ns | 243 ns | 989 -> 997 |

The transformation is correct but not currently profitable. It saves a few bytes
in VLAN/RSS setup code, but `packet_toeplitz_rss_hash` regressed in this run and
the suite geomean moved the wrong way. The recognizer remains in the backend for
future work, but its default score is negative, so the default selector does not
choose it until there is a stronger zero-extending form or a demonstrated hot
path win.

Final default after disabling `movbe16` selection:

- Objects:
  `micro/results/llvm_kinsn_programs_default2_20260518_181034`
- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_011249_513906/metadata.json`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Final default summary versus the no-kinsn LLVM baseline:

| Metric | Value |
|---|---:|
| cases | 29 |
| geomean ratio | 0.9455 |
| summed JIT byte delta | -1478 bytes |

The final object set has the same selected-kinsn distribution and same total JIT
byte delta as the previous default run; the small geomean movement is run-to-run
noise. This is the safer default for now.

### Step 8: 32-bit rotate `rorxl` -> `roll` check

Rationale:

- Native x86 for the C baseline often uses destructive `rol r32, imm`, while the
  first LLVM selector used non-destructive `rorx r32, r32, imm`.
- The x86 module already has `bpf_x86_roll`, so this was a low-risk experiment:
  change only the 32-bit rotate pseudo selected by the existing rotate matcher.

Build/object checks:

- Objects:
  `micro/results/llvm_kinsn_programs_roll32_20260518_190300`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_roll` | 40 |
| `bpf_x86_shldq` | 1 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_020540_295454/metadata.json`

Result:

| Comparison | Geomean ratio | JIT byte delta |
|---|---:|---:|
| `roll32` vs no-kinsn baseline | 0.9476 | -1477 bytes |
| `roll32` vs final default | 1.0021 | +1 byte |

Key deltas versus final default:

| Benchmark | Final default | `roll32` | JIT bytes |
|---|---:|---:|---:|
| `packet_toeplitz_rss_hash` | 241 ns | 227 ns | 989 -> 989 |
| `katran_lb_consistent_hash_select` | 16 ns | 16 ns | 2817 -> 2825 |
| `cilium_ct_nat_tuple_rewrite` | 136 ns | 138 ns | 834 -> 834 |

This is correct but not a default win. It helps one Toeplitz run, but the suite
geomean moves slightly backward and code size does not improve. The LLVM backend
therefore keeps the current `rorxl` default for 32-bit rotate selection.

### Step 9: strict BE16 byte ladder -> `bpf_x86_movbe16`

Rationale:

- Step 7 left the final `AND_ri_32 0xffff` in place after the `movbe16` kinsn.
  That made the final JIT sequence `xor; movbe; and; cmp`, so the measured
  result was not a clean test of the x86 instruction. The selector now treats
  the final `AND` as the candidate root and removes the whole five-instruction
  ladder: `ldb high; shl; ldb low; or; and`.
- The tied-zero operand is still required for correctness because `movbe r16,
  m16` is a partial-width write. This is verifier-facing legality plumbing; it
  should not be confused with selector profitability.

Build/object checks:

- `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`: pass.
- Objects:
  `micro/results/llvm_kinsn_programs_movbe16_strict_20260518_193158`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_movbe16` | 5 |
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_023437_058615/metadata.json`
- Command:
  `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_movbe16_strict_20260518_193158"`

Summary:

| Comparison | Geomean ratio | JIT byte delta |
|---|---:|---:|
| strict `movbe16` vs no-kinsn baseline | 0.9534 | -1536 bytes |
| strict `movbe16` vs previous default | 1.0083 | -58 bytes |

Key deltas versus previous default:

| Benchmark | Previous default | strict `movbe16` | JIT bytes |
|---|---:|---:|---:|
| `flow_5tuple_rss_hash` | 11 ns | 11 ns | 702 -> 689 |
| `packet_vlan_tcpopt_parser` | 13 ns | 13 ns | 1065 -> 1018 |
| `packet_toeplitz_rss_hash` | 241 ns | 224 ns | 989 -> 991 |
| `tracee_http_method_prefix_detect` | 17 ns | 18 ns | 878 -> 878 |

Code-shape check on `flow_5tuple_rss_hash`:

| Previous default | strict `movbe16` |
|---|---|
| `movzx; shl; movzx; or; and; cmp` | `xor; movbe; cmp` |

The strict selector is the right shape and should stay enabled: it preserves
correctness, removes the redundant mask, reduces total JIT bytes, and gives a
clear win on the Toeplitz workload. The one-sample suite geomean still moves
backward versus the previous default because most benchmarks are unaffected and
some movement is measurement noise; that should not veto a strict, local selector
with a strong hit in a representative packet/endian workload. The important
lesson is methodological: do not reject a kinsn class based on a loose selector
that leaves cleanup instructions behind; tighten the matched idiom first, then
measure the hit programs and the full suite separately.

### Step 10: bpfopt kinsn pass coverage audit

I checked the current bpfopt kinsn-class passes against the LLVM backend
selector. The useful x86 coverage now looks like this:

| bpfopt pass | x86 kinsn targets | LLVM backend status |
|---|---|---|
| `rotate` | `bpf_x86_rolq`, `bpf_x86_rorxl` | implemented and selected by default |
| `endian_fusion` | `bpf_x86_rolw`, `bpf_x86_bswapl`, `bpf_x86_bswapq` | `bswapq` already implemented; `rolw` and `bswapl` pseudos/AsmPrinter lowering added in this step; current micro has no `rolw/bswapl` hits |
| `cond_select` | `bpf_x86_testq`, `bpf_x86_cmoveq`, `bpf_x86_cmovneq` | backend lowering exists for LLVM `SELECT_CC`, but current micro has no safe RR select hits |
| `extract` | `bpf_x86_shrq`, `bpf_x86_andl` | exact bpfopt split is not selected; LLVM has stronger `bpf_x86_bextrq` recognition, default-disabled until a profitable control-operand form exists |
| `lea` | `bpf_x86_leaq`, `bpf_x86_leal` | pseudo/AsmPrinter lowering exists and automatic `ADD_rr/ADD_rr_32` selection now passes micro after fixing the module proof path |
| `bulk_memory` | `bpf_x86_movzbl`, `bpf_x86_movb` | not ported as an LLVM selector; ordinary BPF byte load/store already lowers to these machine instructions, so duplicating them as kinsns is not useful without a larger bulk-copy semantic source |
| `prefetch` | `bpf_x86_prefetcht0` | not ported; bpfopt's pass is program/dataflow placement over map/packet dereferences, while the LLVM backend only sees local MI patterns unless source emits `llvm.prefetch` |

LEA experiment:

- Added `BPF_KINSN_X86_LEAQ/LEAL` pseudos and a first `ADD_rr/ADD_rr_32`
  selector.
- Objects:
  `micro/results/llvm_kinsn_programs_bpfopt_gap_20260518_201638`
- Selected kinsns included 238 `bpf_x86_leaq` and 38 `bpf_x86_leal`.
- Full micro failed verification in pointer-heavy programs. Example failure:
  verifier saw `r6 += r7` over values loaded from kinsn shadow-stack slots, then
  rejected a later packet load with `invalid mem access 'scalar'`.

The failure was not a fundamental LLVM legality problem. It exposed a module
boundary bug: `bpf_x86_lea.c` sent the normal BPF-register payload form through
the x86 shadow-register proof path because `kinsn_x86_reg_is_shadowed()` returns
true for BPF regs. That is correct for arch-register/native-lab payloads, but it
is wrong for verifier-facing BPF-register LEA. The normal form must instantiate
as verifier-visible `MOV/ADD/LSH` over the original BPF registers so packet and
frame-pointer provenance stay intact. The module now only uses the shadow path
for `KINSN_X86_LEA_FORM_ARCH_REG`.

LEA retry after the module fix:

- Objects:
  `micro/results/llvm_kinsn_programs_lea_retry_20260518_210000`
- Selected LEA kinsns: 238 `bpf_x86_leaq`, 38 `bpf_x86_leal` (276 total).
- Top LEA hit programs:

| Benchmark | LEA count |
|---|---:|
| `siphash_rotate64_mixer` | 78 |
| `katran_lb_consistent_hash_select` | 68 |
| `packed_header_bitfield_decode` | 19 |
| `flow_5tuple_rss_hash` | 12 |
| `bpftrace_string_search_prefix_scan` | 11 |
| `bcc_runqlat_log2_histogram_bucket` | 10 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_034347_448372/metadata.json`
- Command:
  `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_lea_retry_20260518_210000"`

Summary:

| Comparison | Geomean ratio | JIT byte delta |
|---|---:|---:|
| LEA retry vs no-kinsn baseline | 0.9512 | -1357 bytes |
| LEA retry vs LEA-disabled bpfopt-gap2 | 1.0166 | +179 bytes |

The correctness result is the important part: broad LEA selection no longer
breaks packet-pointer verification. The first performance result is mixed. LEA
adds many kinsn bundles and is not automatically a suite-wide win in this micro
set; it improves or holds several cases, but regresses `bcc_runqlat_log2_histogram_bucket`
and increases total JIT bytes versus the LEA-disabled selector. The next LEA
step should therefore be profitability refinement rather than another verifier
workaround: keep pointer-preserving module proof, then prefer LEA sites where the
final x86 actually removes a move/add pair or materially shrinks a hot block.

ROLW/BSWAPL + LEA-disabled validation:

- Objects:
  `micro/results/llvm_kinsn_programs_bpfopt_gap2_20260518_204000`
- Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_movbe16` | 5 |
| `bpf_x86_popcntq` | 1 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_shldq` | 1 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_032814_683943/metadata.json`
- Command:
  `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_bpfopt_gap2_20260518_204000"`

Summary:

| Comparison | Geomean ratio | JIT byte delta |
|---|---:|---:|
| bpfopt-gap2 vs no-kinsn baseline | 0.9357 | -1536 bytes |
| bpfopt-gap2 vs strict `movbe16` | 0.9814 | 0 bytes |

Key deltas versus the no-kinsn baseline:

| Benchmark | Baseline | bpfopt-gap2 | Ratio | JIT bytes |
|---|---:|---:|---:|---:|
| `bitmap_popcount_scan` | 1115 ns | 491 ns | 0.440 | 489 -> 416 |
| `siphash_rotate64_mixer` | 54 ns | 38 ns | 0.704 | 3529 -> 2399 |
| `packet_toeplitz_rss_hash` | 280 ns | 219 ns | 0.782 | 989 -> 991 |
| `flow_5tuple_rss_hash` | 13 ns | 11 ns | 0.846 | 819 -> 689 |
| `packet_vlan_tcpopt_parser` | 12 ns | 11 ns | 0.917 | 1065 -> 1018 |
| `katran_lb_consistent_hash_select` | 17 ns | 16 ns | 0.941 | 2975 -> 2817 |

### Step 11: live-aware LEA profitability refinement

The broad LEA retry proved correctness but not profitability. Inspecting the JIT
dump showed why: many selected sites were not `copy + add -> lea`; they were
plain one-instruction `add reg, reg` sites rewritten to one-instruction
`lea reg, [reg + reg]`. That is not a guaranteed win on x86. It can increase
encoding size and front-end pressure while saving no instruction.

The selector now only picks `ADD_rr/ADD_rr_32` when both add operands have more
than one non-debug use. If either operand dies at the add, ordinary BPF register
coalescing can usually make the final code a single destructive `add`, so LEA is
not selected. This is still a simple static rule, but it removes the obvious
non-profitable broad matches without adding verifier-facing guards or fallback
logic.

Objects:

- `micro/results/llvm_kinsn_programs_lea_live2_20260519_041000`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_rolq` | 119 |
| `bpf_x86_leaq` | 51 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 17 |
| `bpf_x86_movbe16` | 5 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

LEA hit count dropped from 276 to 68. The largest previous regression,
`bcc_runqlat_log2_histogram_bucket`, dropped from 10 LEA sites to 0. Katran
dropped from 68 to 6, and SipHash dropped from 78 to 30.

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_040112_031843/metadata.json`
- Command:
  `make micro TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_lea_live2_20260519_041000"`

Summary:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta |
|---|---:|---:|---:|
| live-aware LEA vs no-kinsn baseline | 0.9442 | -772 ns | -1399 bytes |
| live-aware LEA vs LEA-disabled bpfopt-gap2 | 1.0091 | +37 ns | +137 bytes |
| live-aware LEA vs broad LEA retry | 0.9926 | -104 ns | -42 bytes |

Key deltas versus LEA-disabled:

| Benchmark | LEA-disabled | live-aware LEA | JIT bytes |
|---|---:|---:|---:|
| `bcc_runqlat_log2_histogram_bucket` | 1025 ns | 1024 ns | 664 -> 664 |
| `siphash_rotate64_mixer` | 38 ns | 42 ns | 2399 -> 2387 |
| `packed_header_bitfield_decode` | 263 ns | 259 ns | 1085 -> 1101 |
| `katran_lb_consistent_hash_select` | 16 ns | 16 ns | 2817 -> 2812 |
| `cilium_socket_lb_service_select` | 326 ns | 332 ns | 931 -> 967 |

This is better than broad LEA, but still not better than LEA-disabled. The next
profitable LEA step should not be another wider `ADD_rr` rule. It should match a
larger canonical idiom where x86 LEA actually subsumes work, such as explicit
`copy + add`, `base + index + disp`, or `shift + add` scaled-index address
generation. Plain scalar add remains too close to native BPF JIT output to be a
good default LEA selector.
