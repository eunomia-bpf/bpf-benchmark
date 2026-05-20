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

If an optimization can be represented by an existing kinsn, the backend should
select that kinsn rather than only replacing the sequence with verifier-native
BPF. Plain BPF rewrites are useful for correctness and verifier proof shape, but
they do not exercise the module/native-instruction path. For example, little
endian byte-ladder load packing must lower to `bpf_x86_movzwl`, `bpf_x86_movl`,
or `bpf_x86_movq` when legal, not just to `LDH`, `LDW`, or `LDD`.

The exception is local bpf2bpf subprogram code. Current kinsn proof sequences
can consume verifier stack, and verifier combines caller/callee stack depth.
Inside local subprograms, the backend may still use verifier-native wide-load
canonicalization to reduce register pressure, but it must not force a
stack-using kinsn proof until the local proof-stack model is fixed.

## Experiment protocol

For each optimization step:

1. Build the BPF backend:
   `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`
2. Generate micro objects with kinsn selection:
   `make -C micro/programs OUTPUT_DIR=$PWD/micro/results/llvm_kinsn_programs_<tag> KERNEL_OFFSETS_INPUT=$PWD/micro/programs/build-x86/kernel_offsets.h BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm BPF_KINSN_LLC=$PWD/llvm-backend/build-bpf-kinsn/bin/llc all`
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

### Step 12: final-MI LEA pair selection

The bpfopt LEA pass runs on final BPF bytecode, so it sees verifier-native
`MOV dst, base; ADD dst, imm/reg` pairs. The first LLVM LEA attempts selected
too early in MachineSSA and sometimes rewrote scalar in-place adds that
register allocation would already lower to a single destructive x86 `add`.
That explains why bpfopt LEA looked stronger: it was matching the final
bytecode opportunity, while LLVM was selecting a broader and less profitable
pre-RA shape.

The LLVM selector was moved to the pre-emit peephole after redundant move
elimination. It now only rewrites adjacent final physical pairs:

- `MOV_rr dst, base; ADD_ri dst, dst, imm` -> `bpf_x86_leaq/leal`
- `MOV_rr dst, base; ADD_rr dst, dst, index` -> `bpf_x86_leaq/leal`

Normal BPF-register LEA does not need kinsn scratch initialization, because the
module verifier proof instantiates to ordinary BPF `MOV/ADD` over the original
BPF registers. `BPFAsmPrinter::functionNeedsKinsnScratch()` therefore no longer
marks LEA pseudos as scratch users. Shadow/arch-register LEA remains a module
internal proof form and is not used by this verifier-facing LLVM path.

Objects:

- `micro/results/llvm_kinsn_programs_lea_reg_pair_20260518_215822`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 159 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 23 |
| `bpf_x86_movbe16` | 5 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Single-sample full micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_050046_753367/metadata.json`
- Command:
  `make micro COMMON_DEPS= TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_lea_reg_pair_20260518_215822"`

Summary versus the same-environment LEA-disabled run
`micro/results/x86_kvm_micro_20260519_045526_806779`:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| final-MI LEA vs LEA-disabled | 0.9926 | +77 ns | -466 bytes | 8/9/12 |

The single-sample summed runtime was distorted by one noisy checksum sample, so
the same two object sets were rerun with `SAMPLES=3`.

Three-sample full micro status:

- LEA-disabled run:
  `micro/results/x86_kvm_micro_20260519_050426_627389/metadata.json`
- final-MI LEA run:
  `micro/results/x86_kvm_micro_20260519_050757_122739/metadata.json`
- Both runs passed: 29/29 correct.
- Command shape:
  `make micro COMMON_DEPS= TIMEOUT=7200 MICRO_ARGS="--samples 3 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir <object-dir>"`

Summary using analysis-side per-benchmark mean over three raw samples:

| Comparison | Geomean ratio | summed mean exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| final-MI LEA vs LEA-disabled | 0.9902 | -29.3 ns | -466 bytes | 15/7/7 |

Key deltas versus LEA-disabled, three-sample mean:

| Benchmark | LEA-disabled | final-MI LEA | JIT bytes |
|---|---:|---:|---:|
| `packet_checksum_fold` | 13329.3 ns | 13308.3 ns | 360 -> 352 |
| `trace_event_type_switch_dispatch` | 290.7 ns | 283.7 ns | 1536 -> 1528 |
| `tc_packet_checksum_fold` | 13336.3 ns | 13331.0 ns | 292 -> 284 |
| `packet_toeplitz_rss_hash` | 225.0 ns | 228.3 ns | 991 -> 975 |
| `bcc_runqlat_log2_histogram_bucket` | 1039.7 ns | 1044.3 ns | 664 -> 629 |

The JIT dump for `tc_packet_checksum_fold` confirms the intended native change:
the hot loop's `mov rax, rsi; add rax, r8` becomes a single
`lea (%rsi,%r8), %rax`, and the bounds setup uses `lea disp(%rsi), %rcx`.
This is the same kind of final bytecode opportunity bpfopt LEA exploits. The
remaining mixed cases are mostly code-layout and benchmark noise rather than a
verifier-facing LEA semantic problem.

### Step 13: little-endian byte ladder -> native wide load

Rationale:

- Several packet/parser micros still lowered simple little-endian
  `u16/u32` field reads as byte ladders: `ldb; shl; ldb; or`.
- This is not a kinsn-only opportunity. For naturally aligned little-endian
  byte ladders, ordinary verifier-facing BPF `LDH32/LDW32` is the right
  canonical form because the normal kernel JIT already emits the target native
  memory load.
- The selector therefore rewrites only local same-block one-use byte ladders
  with a single base register, contiguous offsets, and natural alignment. It
  keeps packet/verifier safety by avoiding unaligned wide loads.

Objects:

- `micro/results/llvm_kinsn_programs_wideload_20260519_024858`

Object-level effect versus final-MI LEA objects:

| BPF shape | final-MI LEA | wideload |
|---|---:|---:|
| `*(u8 *)` | 950 | 776 |
| `*(u16 *)` | 2 | 11 |
| `*(u32 *)` | 174 | 215 |
| `*(u64 *)` | 331 | 328 |
| kfunc calls | 441 | 443 |

Micro status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_095437_720881/metadata.json`
- Command:
  `make micro MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_wideload_20260519_024858"`

Summary versus final-MI LEA single-sample run
`micro/results/x86_kvm_micro_20260519_050046_753367`:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| wideload vs final-MI LEA | 0.9945 | -189 ns | -1408 bytes | 15/8/6 |

Key deltas:

| Benchmark | final-MI LEA | wideload | JIT bytes |
|---|---:|---:|---:|
| `tc_packet_checksum_fold` | 13378 ns | 13241 ns | 284 -> 205 |
| `packet_record_bounds_window` | 107 ns | 84 ns | 638 -> 500 |
| `packet_checksum_fold` | 13310 ns | 13294 ns | 352 -> 270 |
| `bpf_local_call_fanout_dispatch` | 113 ns | 102 ns | 1924 -> 1803 |
| `trace_event_type_switch_dispatch` | 287 ns | 280 ns | 1528 -> 1457 |

This is the strongest post-LEA result in this series because it removes whole
byte-ladder idioms rather than replacing one scalar ALU instruction with another
machine instruction. It also shows the intended LLVM-backend boundary: use
ordinary BPF when normal BPF is already a verifier-safe native instruction, and
reserve kinsn for instructions the kernel JIT cannot otherwise emit.

### Step 14: big-endian byte ladder -> `bpf_x86_movbe16/32`

Rationale:

- Network-order packet fields often appear as unaligned big-endian byte ladders.
  Ordinary BPF `LDH/LDW` is not a safe blanket replacement for these because
  alignment and verifier packet-access rules matter.
- `bpf_x86_movbe16/32` gives the final x86 JIT a real `movbe` memory operand,
  while the module's verifier proof now expands to verifier-visible byte loads,
  shifts, and ORs. That keeps unaligned packet fields safe without relying on a
  wide packet load proof.
- The first full run exposed a module scratch bug in the 16-bit proof: the
  high-bit-preserve register could alias the computed address register, causing
  verifier rejection with a pointer `OR`. The module now chooses the high
  scratch register while avoiding destination, base, computed address, and byte
  value scratch registers.

Objects:

- `micro/results/llvm_kinsn_programs_movbe_be_20260519_030015`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 160 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 24 |
| `bpf_x86_movbe16` | 9 |
| `bpf_x86_movbe32` | 4 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Single-sample status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_101047_239434/metadata.json`

Incremental single-sample summary versus wideload:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| movbe BE vs wideload | 0.9956 | -48 ns | -124 bytes | 11/5/13 |

Three-sample status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_101946_349411/metadata.json`
- Command:
  `make micro COMMON_DEPS= TIMEOUT=7200 MICRO_ARGS="--samples 3 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_movbe_be_20260519_030015"`

Summary using analysis-side per-benchmark mean over three raw samples:

| Comparison | Geomean ratio | summed mean exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| movbe BE vs final-MI LEA | 0.9852 | -190.7 ns | -1532 bytes | 16/8/5 |
| movbe BE vs LEA-disabled | 0.9756 | -220.0 ns | -1998 bytes | 23/4/2 |
| movbe BE vs no-kinsn LLVM baseline | 0.9289 | -926.7 ns | -3534 bytes | 22/5/2 |

Key three-sample deltas versus final-MI LEA:

| Benchmark | final-MI LEA | movbe BE | JIT bytes |
|---|---:|---:|---:|
| `tc_packet_checksum_fold` | 13331.0 ns | 13246.3 ns | 284 -> 205 |
| `packet_checksum_fold` | 13308.3 ns | 13256.7 ns | 352 -> 270 |
| `packet_record_bounds_window` | 107.3 ns | 83.3 ns | 638 -> 500 |
| `bcc_runqlat_log2_histogram_bucket` | 1044.3 ns | 1023.7 ns | 629 -> 597 |
| `bpf_local_call_fanout_dispatch` | 113.7 ns | 102.0 ns | 1924 -> 1803 |
| `packet_toeplitz_rss_hash` | 228.3 ns | 232.3 ns | 975 -> 916 |

The `packet_toeplitz_rss_hash` runtime remains noisy and slightly slower than
the final-MI LEA three-sample mean despite having smaller JIT code. The code
shape is still the intended one: the latest JIT dump contains real `movbe`
loads for Ethernet/IP/TCP fields, including `movbe si, WORD PTR [rdi+0x14]` and
`movbe edx, DWORD PTR [rdi+0x22]`. The current conclusion is to keep the
selector because full-suite correctness holds, total JIT bytes drop materially,
and the three-sample geomean is positive.

I also tested extending the final-MI LEA peephole from adjacent `MOV+ADD` pairs
to `MOV+ADD+ADD/disp` chains. The generated object set had exactly the same
kinsn distribution as the movbe BE objects, so there were zero new hits in the
current micro suite. That change was not kept; the pair-only LEA selector is
the cleaner default until a real scaled-index or displacement-chain opportunity
shows up in final MI.

### Step 15: local-subprog little-endian 64-bit byte ladders -> ordinary `LDD`

Rationale:

- The remaining native/JIT gap after movbe BE was dominated by byte-ladder
  recomposition in local subprograms, especially `bpf_local_call_fanout_dispatch`.
- Enabling every kinsn selector inside local subprograms is not verifier-safe
  today. A test version that allowed local `rolq` kinsns failed with:
  `combined stack size of 2 calls is 544. Too large`. The cause is kinsn proof
  stack usage inside a bpf2bpf callee, combined with the caller stack.
- Ordinary BPF wide loads do not have that proof-stack problem. The kept change
  allows local subprograms to use only verifier-native little-endian wide-load
  canonicalization, while kinsn selectors that instantiate proof stack remain
  disabled in local subprograms.

Objects:

- `micro/results/llvm_kinsn_programs_local_ldd_20260519_034100`

Object-level effect:

- kinsn count is unchanged from movbe BE: 358 total kinsn calls.
- `bpf_local_call_fanout_dispatch` direct `*(u64 *)` loads increased from 6 to
  14, replacing the main 8-byte byte ladders in local callees.
- The local all-kinsn attempt is not kept; only verifier-native `LDD` in local
  subprograms is kept.

Single-sample status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_103705_813710/metadata.json`

Three-sample status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_104019_462499/metadata.json`
- Command:
  `make micro COMMON_DEPS= TIMEOUT=7200 MICRO_ARGS="--samples 3 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_local_ldd_20260519_034100"`

Summary using analysis-side per-benchmark mean over three raw samples:

| Comparison | Geomean ratio | summed mean exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| local `LDD` vs movbe BE | 0.9872 | +42.3 ns | -1494 bytes | 10/13/6 |
| local `LDD` vs final-MI LEA | 0.9726 | -148.3 ns | -3026 bytes | 16/8/5 |
| local `LDD` vs LEA-disabled | 0.9631 | -177.7 ns | -3492 bytes | 21/6/2 |

Key three-sample deltas versus movbe BE:

| Benchmark | movbe BE | local `LDD` | JIT bytes |
|---|---:|---:|---:|
| `bpf_local_call_fanout_dispatch` | 102.0 ns | 84.3 ns | 1803 -> 1089 |
| `siphash_rotate64_mixer` | 38.3 ns | 30.7 ns | 2345 -> 1565 |
| `packet_toeplitz_rss_hash` | 232.3 ns | 225.0 ns | 916 -> 916 |
| `trace_event_type_switch_dispatch` | 288.7 ns | 280.0 ns | 1457 -> 1457 |
| `tc_packet_checksum_fold` | 13246.3 ns | 13303.0 ns | 205 -> 205 |
| `bcc_runqlat_log2_histogram_bucket` | 1023.7 ns | 1043.3 ns | 597 -> 597 |

The checksum and runqlat losses have unchanged JIT bytes, so they are likely
run-to-run noise or layout/cache effects outside the local `LDD` hit set. The
directly affected local-call and SipHash cases improve substantially and the
suite code size drops by another 1494 bytes versus movbe BE. This change is
kept, with the explicit rule that local subprograms may receive verifier-native
wide-load canonicalization but not stack-using kinsn proof sequences until the
local proof-stack model is fixed.

### Step 16: 64-bit OR trees may carry 16/32-bit little-endian byte ladders

Rationale:

- Some 16-bit and 32-bit little-endian byte ladders are widened into a 64-bit
  OR tree before the final mask/truncation. The previous recognizer only
  selected the native-width root and missed these strict sub-width loads.
- The kept change lets `collectWideLoadLE()` use `LDH/LDW` when a 16/32-bit
  byte ladder is carried by a 64-bit OR tree. This is still verifier-native BPF,
  not a kinsn proof, so it is allowed in local subprograms as well.

Objects:

- `micro/results/llvm_kinsn_programs_wideload64_20260519_035538`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 160 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 24 |
| `bpf_x86_movbe16` | 13 |
| `bpf_x86_movbe32` | 6 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Three-sample status:

- Full `make micro` passed: 29/29 correct.
- Run:
  `micro/results/x86_kvm_micro_20260519_110037_284774/metadata.json`

Summary using analysis-side per-benchmark mean over three raw samples:

| Comparison | Geomean ratio | summed mean exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| 64-bit carried wide-load vs local `LDD` | 0.9973 | +9.7 ns | -329 bytes | 15/6/8 |

Key three-sample deltas versus local `LDD`:

| Benchmark | local `LDD` | 64-bit carried wide-load | JIT bytes |
|---|---:|---:|---:|
| `packet_record_bounds_window` | 83.0 ns | 72.7 ns | 500 -> 401 |
| `bitmap_popcount_scan` | 496.3 ns | 491.3 ns | 375 -> 337 |
| `bcc_runqlat_log2_histogram_bucket` | 1043.3 ns | 1104.3 ns | 597 -> 559 |
| `packet_toeplitz_rss_hash` | 225.0 ns | 234.7 ns | 916 -> 916 |

This change is kept because it is verifier-native, reduces code size, and adds
coverage without introducing kinsn proof stack. Runtime is mixed and the main
runqlat loss in this run is not supported by a larger JIT body; the next step
therefore targeted the actual indexed byte-load shape instead of widening this
rule further.

### Step 17: indexed byte loads -> `bpf_x86_movzbl` SIB form

Rationale:

- The native x86 gaps in `bcc_runqlat_log2_histogram_bucket`,
  `sorted_rule_binary_search`, and `payload_prefix_memcmp_scan` include
  repeated byte loads from `base + index + offset`. Ordinary BPF represents this
  as address arithmetic plus `LDX_MEM`; x86 can issue one SIB memory operand.
- The LLVM selector now recognizes a same-block one-use `ADD_rr` feeding an
  `LDB/LDB32` and emits `BPF_KINSN_X86_MOVZBL dst, base, index, scale, off`.
- The first attempt exposed two verifier-facing module bugs:
  - non-arch SIB proof read BPF registers through the shadow-register path,
    losing packet-pointer provenance and failing with `invalid mem access
    'scalar'`;
  - scratch fallback forced a deep proof stack when the register allocator chose
    `dst == index`, increasing final JIT stack frames from `0x40/0x48` to
    `0x178`.
- The kept module proof has a verifier-native fast path:
  `dst = base; dst += index; dst = *(width *)(dst + off)` when
  `dst != base && dst != index`. The LLVM pseudo is marked early-clobber so the
  register allocator keeps that fast path legal. The final x86 emit remains one
  `movzbl disp(base,index,scale), dst` instruction.

Objects:

- `micro/results/llvm_kinsn_programs_sib_ec_20260519_043546`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 160 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 24 |
| `bpf_x86_movzbl` | 19 |
| `bpf_x86_movbe16` | 13 |
| `bpf_x86_movbe32` | 6 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Validation:

- Targeted SIB run passed for `sorted_rule_binary_search`,
  `bcc_runqlat_log2_histogram_bucket`, and `payload_prefix_memcmp_scan`.
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_113952_304271/metadata.json`
- Full three-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_114214_364050/metadata.json`

Summary using analysis-side per-benchmark mean over three raw samples:

| Comparison | Geomean ratio | summed mean exec delta | JIT byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|
| SIB early-clobber vs 64-bit carried wide-load | 0.9977 | -107.7 ns | -31 bytes | 12/6/11 |
| SIB early-clobber vs local `LDD` | 0.9951 | -104.0 ns | -360 bytes | 16/6/7 |

Key three-sample deltas versus 64-bit carried wide-load:

| Benchmark | wide-load | SIB early-clobber | JIT bytes |
|---|---:|---:|---:|
| `bcc_runqlat_log2_histogram_bucket` | 1104.3 ns | 1003.7 ns | 559 -> 542 |
| `sorted_rule_binary_search` | 524.7 ns | 533.0 ns | 660 -> 643 |
| `payload_prefix_memcmp_scan` | 100.0 ns | 113.7 ns | 528 -> 531 |
| `packet_toeplitz_rss_hash` | 234.7 ns | 221.7 ns | 916 -> 916 |

The indexed-load selector is now correctness-clean and has a measurable suite
win, but it is not universally profitable. It is excellent for runqlat's
precomputed-pointer byte loads; it is slightly negative for the memcmp-prefix
loop because register allocation and induction-update scheduling become less
favorable even though the load itself is a better x86 instruction. Keep the
selector, but do not broaden it to more memory widths or scaled forms until the
profitability model can distinguish address-ladder loads from tight induction
loops where BPF's existing `lea/add + load` schedule is already strong.

### Step 18: force-select every legal kinsn candidate

Question tested: what happens if the LLVM selector ignores profitability and
selects every currently recognized kinsn candidate?

Implementation:

- Added hidden llc flag `-bpf-kinsn-force-all` for this experiment. This was
  later replaced by the unified `-bpf-kinsn-mode=...` policy knob in Step 22.
- Added `BPF_KINSN_LLC_FLAGS` to `micro/programs/Makefile` so experiments can
  pass extra llc flags without changing the default build path.
- The flag ignores candidate score only. It does not override legality. In
  particular, local bpf2bpf subprogram kinsn selection stays disabled because
  kinsn proof sequences consume verifier stack that is combined with the caller.

The first experiment also forced local subprograms. That is not legal today:
`bpf_local_call_fanout_dispatch` failed verifier with:

```text
combined stack size of 2 calls is 544. Too large
```

That failed run is useful because it confirms the local-subprog restriction is
a verifier legality rule, not just conservative profitability.

Legal force-all objects:

- `micro/results/llvm_kinsn_programs_force_all_legal_20260519_050157`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 160 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 24 |
| `bpf_x86_movzbl` | 19 |
| `bpf_x86_movbe16` | 13 |
| `bpf_x86_bextrq` | 10 |
| `bpf_x86_movbe32` | 6 |
| `bpf_x86_rolw` | 2 |
| `bpf_x86_bswapl` | 2 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Validation:

- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_120403_748777/metadata.json`
- Full three-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_120633_074134/metadata.json`

Summary using analysis-side per-benchmark mean over three raw samples:

| Comparison | Geomean ratio | summed mean exec delta | JIT byte delta | xlated byte delta | wins/losses/ties |
|---|---:|---:|---:|---:|---:|
| legal force-all vs SIB early-clobber default | 1.0011 | +299.0 ns | +38 bytes | +168 bytes | 9/15/5 |

Key three-sample deltas versus SIB early-clobber default:

| Benchmark | SIB default | legal force-all | JIT bytes | xlated bytes |
|---|---:|---:|---:|---:|
| `bcc_runqlat_log2_histogram_bucket` | 1003.7 ns | 1086.7 ns | 542 -> 583 | 1168 -> 1216 |
| `packet_checksum_fold` | 13250.0 ns | 13462.3 ns | 270 -> 270 | 536 -> 536 |
| `packet_toeplitz_rss_hash` | 221.7 ns | 230.0 ns | 916 -> 916 | 1568 -> 1568 |
| `sorted_rule_binary_search` | 533.0 ns | 527.3 ns | 643 -> 643 | 1280 -> 1280 |
| `trace_event_type_switch_dispatch` | 283.3 ns | 277.3 ns | 1457 -> 1457 | 1912 -> 1912 |
| `packed_header_bitfield_decode` | 266.0 ns | 269.0 ns | 1006 -> 1009 | 2032 -> 2120 |

Conclusion: enabling all legal kinsn candidates is not the right default. It
mostly adds `bpf_x86_bextrq` and cold `rolw/bswapl` unary forms. Those are
correct, but not consistently profitable on this suite. The current
profitability gate is doing useful work: keep `bextrq` available for targeted
experiments, but default-enable it only after there is a control-operand form or
a better cost model that can prove the final x86 sequence is actually shorter or
faster.

### Step 19: little-endian byte-ladder packing uses MOV kinsns by default

Rationale:

- Step 13 used verifier-native `LDH/LDW/LDD` for little-endian byte-ladder
  packing. That was a useful canonicalization, but it did not exercise the
  kinsn/native-instruction path.
- The backend rule is now explicit: when an existing kinsn can represent the
  optimization, select the kinsn. Little-endian packing therefore lowers to
  `bpf_x86_movzwl`, `bpf_x86_movl`, or `bpf_x86_movq` for non-local code.
- Local bpf2bpf subprograms remain the exception. An all-kinsn local-call test
  can exceed the verifier's combined caller/callee stack depth. Local callees
  still use verifier-native `LDH/LDW/LDD` packing to reduce register pressure
  and keep the program loadable.

Implementation:

- `BPFKinsnSelect` now emits MOV-family kinsn pseudos for non-local
  little-endian byte ladders.
- The pseudo uses the existing `bpf_x86_mov*` kfuncs and a direct
  base+offset memory payload; no new module ABI was added.
- `bpf_x86_mov.c` gained a verifier-proof fast path for direct BPF-register
  memory operands: instantiate as `dst = *(width *)(base + off)` over the live
  verifier base register. This preserves packet/frame-pointer provenance. The
  previous generic shadow-base proof could read the base from shadow stack and
  turn packet pointers into scalars.

Objects:

- `micro/results/llvm_kinsn_programs_pack_kinsn3_20260519_055006`

Selected kinsns:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 160 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_movl` | 43 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 24 |
| `bpf_x86_movzbl` | 19 |
| `bpf_x86_movbe16` | 13 |
| `bpf_x86_movzwl` | 11 |
| `bpf_x86_movq` | 8 |
| `bpf_x86_movbe32` | 6 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Validation:

- Targeted packet/local tests passed after rebuilding the runtime image with the
  fixed `bpf_x86_mov.ko`.
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_125211_307977/metadata.json`
- Command:
  `make micro COMMON_DEPS= TIMEOUT=7200 MICRO_ARGS="--samples 1 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir /home/yunwei37/workspace/bpf-benchmark/micro/results/llvm_kinsn_programs_pack_kinsn3_20260519_055006"`

Summary using analysis-side per-benchmark values:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta |
|---|---:|---:|---:|
| MOV-packing kinsn vs no-kinsn LLVM baseline | 0.9164 | -990 ns | -5228 bytes |
| MOV-packing kinsn vs SIB early-clobber default | 1.0043 | -1.7 ns | +160 bytes |

Key deltas versus the no-kinsn LLVM baseline:

| Benchmark | Baseline | MOV-packing kinsn | JIT bytes |
|---|---:|---:|---:|
| `bitmap_popcount_scan` | 1115 ns | 492 ns | 489 -> 337 |
| `tc_packet_checksum_fold` | 13352 ns | 13237 ns | 292 -> 228 |
| `packet_checksum_fold` | 13322 ns | 13254 ns | 360 -> 295 |
| `packet_toeplitz_rss_hash` | 280 ns | 226 ns | 989 -> 916 |
| `bcc_runqlat_log2_histogram_bucket` | 1044 ns | 1004 ns | 664 -> 542 |
| `packet_record_bounds_window` | 108 ns | 73 ns | 644 -> 408 |
| `bpf_local_call_fanout_dispatch` | 112 ns | 84 ns | 1985 -> 1097 |

The first all-MOV-packing attempt failed only in
`bpf_local_call_fanout_dispatch` with:

```text
combined stack size of 2 calls is 528. Too large
```

That failure happened because local subprogram byte-ladder packing was converted
to MOV kinsns and the callee's proof stack combined with caller stack. The kept
version restores the earlier local-subprog rule: local code may use ordinary
wide loads, while non-local code must use the available MOV kinsns. This keeps
the suite loadable and preserves the intended native-instruction coverage for
normal packet/parser code.

JIT byte audit:

- The initial MOV-packing run was `+160` JIT bytes versus the SIB
  early-clobber default even though it still saved bytes versus the no-kinsn
  baseline.
- Root cause: `BPFAsmPrinter::functionNeedsKinsnScratch()` treated
  `BPF_KINSN_X86_MOVZBL/MOVZWL/MOVL/MOVQ` as scratch users. For the forms LLVM
  emits, `bpf_x86_mov.c` has verifier-native no-scratch fast paths, so this was
  unnecessary. The extra function-entry `r6/r7/r8 = 0` made the x86 JIT save
  callee-saved registers (`rbx/r13/r14`) and allocate stack space. In
  `packet_checksum_fold`, the +25 bytes were entirely prologue/epilogue:
  `sub rsp`, `push rbx/r13/r14`, three zeroing instructions, and three pops.
- Fix: keep the MOV-load kinsns selected, but do not count these BPF-register
  MOV-load pseudos as function-level scratch users.

Validation after the scratch-init fix:

- Objects:
  `micro/results/llvm_kinsn_programs_mov_scratchfix_20260519_061416`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_131610_476641/metadata.json`

Analysis-side deltas:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| scratch-init fix vs MOV-packing | 0.9991 | +70 ns | -142 bytes | -360 bytes |
| scratch-init fix vs SIB early-clobber default | 1.0013 | +69 ns | +18 bytes | +448 bytes |
| scratch-init fix vs no-kinsn LLVM baseline | 0.9155 | -920 ns | -5370 bytes | -9072 bytes |

The remaining `+18` bytes versus SIB are a separate regalloc/ABI effect, not a
module emit bug. The MOV-load pseudo is globally early-clobber to keep SIB
`dst` separate from address operands, which avoids scratch proof paths. For a
direct load such as `movzwl off(%r5), %r5d`, early-clobber is too conservative
and can make LLVM choose BPF r6/`rbx` as an address temporary, forcing one
callee-saved push/pop. A trial that removed early-clobber did reduce that shape,
but `sorted_rule_binary_search` then hit a SIB proof path that saved
uninitialized r6 and failed verifier with `R6 !read_ok`. That trial is not kept.

The clean follow-up is to split the internal LLVM representation or add precise
scratch metadata: direct MOV-load pseudos may allow tied `dst == base`, while
SIB MOV-load pseudos must either keep early-clobber or force function scratch
initialization only when a real SIB overlap is selected.

Follow-up implementation:

- Split the LLVM-only MOV-load pseudos into direct base+offset forms
  (`BPF_KINSN_X86_MOVZBL_MEM/MOVZWL_MEM/MOVL_MEM/MOVQ_MEM`) and SIB forms
  (`BPF_KINSN_X86_MOVZBL/MOVZWL/MOVL/MOVQ`).
- Direct forms carry only `dst, base, off` and do not use early-clobber. This
  lets LLVM keep shapes such as `dst == base` when they are valid and avoids
  introducing a callee-saved temporary only because SIB needs stricter operand
  separation.
- SIB forms keep the conservative early-clobber rule because their proof path
  must keep `dst` separate from `base/index`.

Validation:

- Objects:
  `micro/results/llvm_kinsn_programs_mov_split_20260519_090434`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_160716_947398/metadata.json`

Analysis-side deltas:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| direct/SIB split vs scratch-init fix | 0.9982 | -24 ns | -7 bytes | 0 bytes |
| direct/SIB split vs no-kinsn LLVM baseline | 0.9140 | -944 ns | -5377 bytes | -9072 bytes |

The concrete byte win was `packet_checksum_fold`: the direct MEM pseudo no
longer forced the extra `push rbx` shape that the unified early-clobber MOV
pseudo could trigger.

### Step 17: MOVBE32/64 verifier proof fast path

`bpf_x86_movbe32/64` final emit was already one `movbe` instruction, but the
verifier proof still went through the generic indexed-address scratch path for
direct base+offset loads. The direct form can be proved as ordinary BPF:

```text
dst = *(u32/u64 *)(base + off)
dst = bswap(dst)
```

Implementation:

- `bpf_x86_movbe.c` now uses the two-instruction verifier proof above for
  direct 32-bit and 64-bit MOVBE loads.
- LLVM no longer counts direct `MOVBE32/64` pseudos as function-level scratch
  users. `MOVBE16` stays scratch-using because `movbe r16, m16` is a partial
  register write and still needs the tied-zero proof shape.

Validation:

- Objects:
  `micro/results/llvm_kinsn_programs_movbe_fast_20260519_091202`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_161612_466178/metadata.json`

Analysis-side deltas:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| MOVBE fast proof vs direct/SIB split | 0.9923 | -24 ns | 0 bytes | 0 bytes |
| MOVBE fast proof vs scratch-init fix | 0.9905 | -48 ns | -7 bytes | 0 bytes |
| MOVBE fast proof vs no-kinsn LLVM baseline | 0.9068 | -968 ns | -5377 bytes | -9072 bytes |

The main value is not a new final x86 instruction; it is removing unnecessary
proof scratch pressure so future selectors do not pay accidental prologue cost.

### Step 18: precise scratch mask and POPCNT fast proof

The earlier scratch initialization was still boolean: any scratch-using kinsn
initialized all of `r6/r7/r8`, which made the x86 JIT save `rbx/r13/r14` even
when only one or two verifier scratch registers were actually needed.

Implementation:

- `BPFAsmPrinter` now computes a per-function scratch mask instead of a boolean.
  Examples: standalone `bswap` needs only `r6`; rotate/BMI/SHD use `r6/r7`;
  direct MOV-load and direct `MOVBE32/64` need no scratch.
- `bpf_x86_popcntq` gained a BPF-register verifier fast path using `dst` as the
  accumulator plus `r6/r7` as scratch. The generic shadow/arch path remains for
  operands that actually need it.

Validation:

- Objects:
  `micro/results/llvm_kinsn_programs_scratch_mask_20260519_092354`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_162833_596819/metadata.json`

Analysis-side deltas:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| precise scratch mask vs MOVBE fast proof | 1.0011 | +37 ns | -33 bytes | -56 bytes |
| precise scratch mask vs direct/SIB split | 0.9934 | +13 ns | -33 bytes | -56 bytes |
| precise scratch mask vs no-kinsn LLVM baseline | 0.9078 | -931 ns | -5410 bytes | -9128 bytes |

The runtime difference against the immediately previous run is single-sample
noise, but the code-shape fix is real. In `bitmap_popcount_scan`, the JIT
prologue changed from:

```asm
push rbx
push r13
push r14
xor ebx, ebx
xor r13d, r13d
xor r14d, r14d
```

to:

```asm
push rbx
push r13
xor ebx, ebx
xor r13d, r13d
```

The suite still keeps the large baseline win from `popcnt`, rotate, MOVBE, LEA,
and MOV-load packing, while avoiding accidental callee-saved register pressure.

### Step 19: direct MOVBE16 proof fast path

`MOVBE16` was still the main small scratch outlier. LLVM emits it only as a
direct base+offset memory operand, but the module verifier proof used the
generic indexed path:

```text
addr = base + index * scale
dst = byte0 << 8 | byte1
dst |= old_dst_high_bits
```

That needed address, byte-value, and high-bits scratch registers. For the
direct form, the proof can avoid address construction and byte-by-byte
reassembly:

```text
high = old_dst & ~0xffff
value = *(u16 *)(base + off)
value = bswap16(value)
dst = high | value
```

Implementation:

- `bpf_x86_movbe.c` now has a direct 16-bit fast path using two scratch
  registers when possible; it falls back to the existing generic path only when
  `dst/base` consume too many scratch registers.
- `BPFAsmPrinter` computes the actual two-scratch mask for `MOVBE16` from
  `dst/base` instead of always initializing all three scratch registers.

Validation:

- Objects:
  `micro/results/llvm_kinsn_programs_movbe16_fast_20260519_093430`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_163959_668431/metadata.json`

Analysis-side deltas:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| direct MOVBE16 proof vs precise scratch mask | 0.9992 | -88 ns | -9 bytes | -24 bytes |
| direct MOVBE16 proof vs no-kinsn LLVM baseline | 0.9072 | -1019 ns | -5419 bytes | -9152 bytes |

The code-shape win is visible but small. In `packet_toeplitz_rss_hash`, the
new proof removes the scratch zero-init for `r14`:

```asm
- xor r14d, r14d
```

The function still contains `push r14` because LLVM uses that register for the
program itself, not because the kinsn scratch init requires it. This is the
current clean boundary: the selector should remove artificial prologue cost, but
not fight normal register allocation unless a later cost model can prove that is
profitable.

### Step 20: rotate proof scratch chosen from operands

The next implementation issue was in the high-hit rotate family. The latest
object set contains 119 `bpf_x86_rolq` and 40 `bpf_x86_rorxl` calls, and some
of those pseudos use BPF `r6/r7/r8` as normal program operands after register
allocation. The old verifier proof always used fixed `r6/r7` scratch for
immediate rotates. That worked for the measured final native code, but it made
the proof path unnecessarily heavy and mixed two roles for the same registers:
program operands and verifier scratch.

Implementation:

- `bpf_x86_rotate.c` now has a BPF-register fast path for immediate
  `ROLQ`/`RORXL`. It chooses one scratch register not equal to the instruction's
  dst/src operands, saves/restores only that scratch, computes directly in the
  live BPF dst register, and then updates the shadow slot.
- `BPFAsmPrinter` uses the same operand-aware scratch rule for rotate scratch
  initialization. `ROLW` from LLVM is non-arch and lowers to a verifier-native
  `BPF_BSWAP16`, so it no longer requests scratch initialization.

Validation:

- Objects:
  `micro/results/llvm_kinsn_programs_rotate_scratch_20260519_104343`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_174650_398599/metadata.json`

Analysis-side deltas:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| operand-aware rotate proof vs direct MOVBE16 proof | 0.9929 | +37 ns | -9 bytes | -24 bytes |
| operand-aware rotate proof vs no-kinsn LLVM baseline | 0.9007 | -982 ns | -5428 bytes | -9176 bytes |

The runtime delta against the previous run is noise-level; the useful change is
that rotate proof now has a cleaner register contract. It no longer needs to
treat the fixed scratch pair as globally safe when one of those physical BPF
registers is itself a kinsn operand.

### Step 21: post-RA scaled-index folds must respect live-out registers

Rationale:

- The LLVM-side LEA/SIB work happens after register allocation, so operands are
  physical BPF registers. Deleting a `MOV; SHL` scaled-index producer is only
  legal if that physical register is not live past the local rewrite.
- One unsafe SIB-memory fold reproduced a verifier failure in
  `bcc_runqlat_log2_histogram_bucket`:

```text
R7 pointer += pointer prohibited
```

  The deleted scaled-index definition left `r2` holding the old packet
  `data_end` pointer along one loop path, and a later `r7 += r2` became pointer
  plus pointer. The bug was in the LLVM peephole's post-RA liveness handling,
  not in bpfopt or the final x86 emitter.

Implementation:

- `foldScaledIndexMemPseudos()` now computes `LivePhysRegs` for each
  `MachineBasicBlock` and refuses to erase the scaled-index temp when that
  physical register is live-out.
- The same live-out check was added to the scaled-index LEA pair fold
  (`MOV index; SHL index; MOV dst, base; ADD dst, index -> LEA`) because it has
  the same post-RA deletion hazard.
- This is not a profitability gate. It is the normal LLVM legality condition for
  deleting physical-register definitions after register allocation.

Validation:

- `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`: pass.
- Objects:
  `micro/results/llvm_kinsn_programs_liveoutfix_20260519_114208`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_185045_458143/metadata.json`
- A follow-up build with the LEA-pair live-out check produced byte-identical
  BPF objects:
  `micro/results/llvm_kinsn_programs_lea_liveout2_20260519_115307`

Selected kinsns in the validated object set:

| kinsn | count |
|---|---:|
| `bpf_x86_leaq` | 160 |
| `bpf_x86_rolq` | 119 |
| `bpf_x86_movl` | 43 |
| `bpf_x86_rorxl` | 40 |
| `bpf_x86_leal` | 24 |
| `bpf_x86_movzbl` | 19 |
| `bpf_x86_movbe16` | 13 |
| `bpf_x86_movzwl` | 11 |
| `bpf_x86_movq` | 8 |
| `bpf_x86_movbe32` | 6 |
| `bpf_x86_shldq` | 1 |
| `bpf_x86_popcntq` | 1 |

Single-sample summary versus the no-kinsn LLVM baseline
`micro/results/x86_kvm_micro_20260518_210242_364278`:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| live-out-safe LLVM kinsn vs baseline | 0.9070 | -992 ns | -5448 bytes | -9232 bytes |

Key deltas:

| Benchmark | Baseline | live-out-safe | JIT bytes |
|---|---:|---:|---:|
| `bitmap_popcount_scan` | 1115 ns | 490 ns | 489 -> 330 |
| `tc_packet_checksum_fold` | 13352 ns | 13248 ns | 292 -> 211 |
| `packet_checksum_fold` | 13322 ns | 13258 ns | 360 -> 277 |
| `packet_toeplitz_rss_hash` | 280 ns | 232 ns | 989 -> 913 |
| `bpf_local_call_fanout_dispatch` | 112 ns | 73 ns | 1985 -> 1071 |
| `packet_record_bounds_window` | 108 ns | 73 ns | 644 -> 400 |
| `siphash_rotate64_mixer` | 54 ns | 31 ns | 3529 -> 1562 |

Incremental comparison against the previous stable rotate-scratch run
`micro/results/x86_kvm_micro_20260519_174650_398599`:

| Comparison | Geomean ratio | summed exec delta | JIT byte delta | xlated byte delta |
|---|---:|---:|---:|---:|
| live-out-safe vs rotate-scratch | 1.0070 | -10 ns | -20 bytes | -56 bytes |

The incremental geomean is slightly worse because the unsafe fold had removed a
few instructions on paths where the scaled-index temp was actually live. That
speed was invalid. The safe version keeps the suite-wide baseline win while
preserving verifier-visible pointer/scalar state.

Current LLVM optimization boundary:

- Profitable and enabled: rotate, `ctpop`/`popcnt`, final-MI LEA pairs,
  direct/SIB MOV-load packing, BE byte-ladder `movbe`, local verifier-native
  wide-load packing, and selected SHD.
- Implemented but not default-profitable in this micro set: `bextr`, BMI1
  `blsi/blsr`, standalone narrow endian/unary forms, and broad scalar LEA.
- Still worth improving in LLVM, not bpfopt: earlier semantic hooks for
  `select`/`cmov`, a better BEXTR form that reuses or cheaply materializes the
  control operand, and a more precise cost model for indexed loads in tight
  induction loops.

### Step 22: selector policy knobs for A/B experiments

The rotate amortization experiment showed why selector profitability policy
must be controllable rather than deleted after one noisy run. The rule reduced
three cold `rolq` selections and the full micro run remained correct:

- Objects:
  `micro/results/llvm_kinsn_programs_rotate_cost_20260519_134610`
- Full single-sample `make micro` passed: 29/29 correct.
  Run:
  `micro/results/x86_kvm_micro_20260519_211121_812654/metadata.json`
- Versus no-kinsn baseline:
  geomean `0.9040`, summed exec delta `-1043 ns`, JIT byte delta `-5422`,
  xlated byte delta `-9200`, result mismatches `0`.
- Versus live-out-safe:
  geomean `0.9967`, summed exec delta `-51 ns`, JIT byte delta `+26`, xlated
  byte delta `+32`, result mismatches `0`.

The result is not strong enough to hard-code a policy conclusion. The right
boundary is:

- legality/correctness checks stay unconditional, for example post-RA live-out
  checks before deleting a physical register def;
- profitability and experimental selector choices get `llc` flags and are
  exercised through `BPF_KINSN_LLC_FLAGS`.

The flag surface is intentionally compact. Do not add one boolean flag per
selector. Selector policy is one three-state option:

```text
-bpf-kinsn-mode=family=disable|cost|force
```

Entries are comma-separated or repeated. `all=...` applies to every family and
later entries override earlier entries. The default is `cost` for every family.
`disable` blocks candidate collection or early DAG legalization for that family,
`cost` runs legality plus profitability, and `force` selects every legal
candidate while keeping correctness checks unconditional. Families that do not
yet have a distinct profitability rule treat `cost` and `force` the same.

Current families:

| Family | Scope |
|---|---|
| `unary` | standalone byte-order/unary candidates |
| `wide-load` | byte-ladder wide-load packing |
| `movbe-be` | big-endian byte-ladder `movbe` |
| `movbe-load` | load + byte-swap `movbe` |
| `indexed-load` | indexed/SIB load kinsns |
| `bextr` | BEXTR candidate collection |
| `bmi1` | BLSI/BLSR candidates |
| `rotate` | rotate candidates and rotate amortization policy |
| `shd` | SHLD/SHRD candidates |
| `cmov` | LLVM `select` lowering to cmp/cmov kinsns |
| `popcnt` | `ctpop` SelectionDAG legalization to `popcntq` |
| `preemit-lea` | post-RA MOV+ADD to LEA |
| `scaled-index-mem` | post-RA scaled-index fold for SIB memory kinsns |

The only remaining numeric tuning flag is
`-bpf-kinsn-rotate-amortization-threshold=<N>`, default `4`; it is used only
when `rotate=cost`.

Validation:

- `ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4`: pass.
- `llc --help-hidden` now lists only:
  `-bpf-enable-kinsn-select`, `-bpf-kinsn-mode=<family=mode>`, and
  `-bpf-kinsn-rotate-amortization-threshold=<N>`.
- Default policy objects:
  `micro/results/llvm_kinsn_programs_mode_default_20260519_143046`
- Rotate forced objects:
  `micro/results/llvm_kinsn_programs_mode_rotate_force_20260519_143046`
- All disabled objects:
  `micro/results/llvm_kinsn_programs_mode_all_disable_20260519_143046`
- The default object set is byte-identical to the previous
  `llvm_kinsn_programs_flags_default_20260519_141800` set.
- The `rotate=force` object set is byte-identical to the previous
  `llvm_kinsn_programs_flags_rotate_nocost_20260519_141800` set.

The rotate flag changes only the intended sparse rotate sites:

| Object set | total kinsns | `bpf_x86_rolq` |
|---|---:|---:|
| default policy | 442 | 116 |
| `-bpf-kinsn-mode=rotate=force` | 445 | 119 |
| `-bpf-kinsn-mode=all=disable` | 0 | 0 |

Changed programs:

| Program | Default | `rotate=force` |
|---|---|---|
| `bpftrace_string_search_prefix_scan` | no `rolq` | +1 `rolq` |
| `payload_prefix_memcmp_scan` | no cold `rolq` | +2 `rolq` |

This keeps the default policy measurable while preserving the ability to run
the previous behavior without code changes:

```sh
BPF_KINSN_LLC_FLAGS="-bpf-kinsn-mode=rotate=force" \
make -C micro/programs OUTPUT_DIR=... \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$PWD/llvm-backend/build-bpf-kinsn/bin/llc" all
```
