# Native simulator verification

## External-base migration (M1 complete)

The operator's replacement plan is in [todo section 4](../docs/todo.md).
The external bases are forks, pinned as Git submodules; changes needed by
kprog belong in those forks. No replacement ISA semantics is defined locally.

| Base | Fork / submodule | Pinned source | Upstream toolchain |
|---|---|---|---|
| AArch64 | [eunomia-bpf/LNSym](https://github.com/eunomia-bpf/LNSym), `external/LNSym` | `da428593b21d` | Lean 4.35.0 |
| x86-64 | [eunomia-bpf/x86lean](https://github.com/eunomia-bpf/x86lean), `external/x86lean` | `ebf6519ea76d` | Lean 4.32.0-rc1 |
| Clight | [eunomia-bpf/clean](https://github.com/eunomia-bpf/clean), `external/clean/export` | `123f7f7767e2` | Lean 4.32.1 |

`make -C kprog/formal mature` builds the migration Lake package on Lean 4.35.0,
importing the external `Arm`, `X86`, `CCLib` and `Clightdefs` libraries directly.
The combined build passed on 2026-11-14 (121 Lake jobs), importing all four
libraries on the common toolchain. The x86lean fork patch `74a2e2849cde`
uses an explicit Boolean-decision bridge for the existing masked-count
hypothesis; its theorem statement and instruction semantics are unchanged.
Build output and the earlier failed attempts are retained in
`/workspaces/kprog-raw/formal/m1-compat-2` and `m1-compat-1`.
The legacy package remains on Lean 4.19.0 while M3-M5 migrate its references
and theorems. M2 is in progress; the legacy counts below describe the old
foundation, not proofs against these external bases. Retirement occurs at M6.

LNSym and x86lean retain their Apache-2.0 licenses. Clean retains its own
[LICENSE](external/clean/LICENSE): its tree is under INRIA non-commercial
terms, with the listed components, including `export/`, also offered under
LGPL-2.1-or-later. Keep those license terms separate. Clean explicitly labels
its C-to-Lean exporter/semantics experimental in its upstream README; the
CompCert front end and the Lean export/semantics have separate trust claims.

## Operation coverage (M2 in progress)

LNSym `da428593b21d6dfa02c6d063600d9ed817747fd5`, x86lean `ebf6519ea76d9f9ab3af1e143fca6442c02373b0`.

Source inspection, not refinement proofs or conformance results. `present` means an execution path exists; `partial`/`missing` remain M2 work; `layer` identifies linking/ABI transport above an existing ISA form. Memory permissions, initialization, fault prefixes, exclusive ordering and ABI require explicit relations.

LNSym `4a9bc9df5a6e` adds the conditional increment/invert/negate forms through
its existing execution function and expands its random conformance generator.
The combined build and 24 encoded regression vectors passed on 2026-11-14
(`m2-select-3`, 122 Lake jobs). These use upstream-style `native_decide` finite
checks; they are not hardware differential results or migrated refinement counts.

LNSym `093c3a4d9eea` also fixes FMOV field31 to use XZR/WZR rather than SP.
The combined build passed 123 Lake jobs including the conditional-select suite
and the existing XZR suite with four new FMOV regressions (`m2-fmov-zr-1`).

LNSym `7f683544abb7` adds MSUB, UMADDL/UMULL, SMADDL and UMULH plus W/X UDIV.
Twenty-nine encoded vectors and an invalid-width check passed in the combined
124-job build (`m2-multiply-divide/build-1`), covering aliasing, zero division,
32-bit truncation, signed widening, high-half multiplication and the GPR/flag frame.
These are finite regression checks; M2 remains open for the remaining forms.

LNSym `78658b3affc4` adds decoded EXTR/ROR and conditional compare (CCMP/CCMN,
register/imm5), including the flags-only register footprint. Eleven extraction
vectors, 23 comparison vectors and three invalid extraction encodings passed
with the previous suites in a 127-job combined build (`m2-extract-compare/build-1`).

LNSym `de5a36443abd` extends the shared single-register transfer path with signed
GPR loads, halfwords, unscaled GPR, pre-index and register-offset forms. Execution
and register-footprint decoding share the scalar/SIMD load classification; SP
alignment failure commits neither data/writeback nor PC advance. The combined
129-job build passed 68 load vectors, 33 store vectors and four refusal checks,
plus the retained LDST suite (`m2-single-memory/build-2`). Permission, initialization
and ordered-fault profiles remain part of the cross-cutting work below.

LNSym `d1b4b01d8879` adds CNT 8B/16B and all five UADDLV arrangements through
its SIMD dispatcher. The combined 131-job build passed 512 exhaustive byte cases,
126 varied encoded vectors, nine illegal encodings and a retained REV64 check
(`m2-vector-reductions/build-2`). These check upper clearing, V31, aliases and the
GPR/SFP/flag frame within LNSym's enabled-SIMD domain. Exception-level trap profiles
remain separate work. ARM source statuses are 60 present, four missing, eight
partial and two linking-layer labels; these are not migrated theorem counts.

LNSym `9bd0c0f609fb` adds W/X extended-register ADD/ADDS/SUB/SUBS with all eight
extension options, shifts 0..4, SP/ZR distinctions and CMP/CMN footprints. The
combined 133-job build passed 160 retained encoded vectors and 12 invalid shifts
(`m2-extended-arithmetic/build-2`). An expanded 832-case matrix also passed and is
retained in raw; the committed suite uses representative cases to limit fixture
size. ARM source statuses are now 66 present, four missing, two partial and two
linking-layer labels. Exclusives, LSE and the pair/fault profiles remain open.

LNSym `1a5034a5a4d5` adds LSE LDADD/LDCLR/LDSET in B/H/W/X forms and all A/R
variants, including store-only aliases. Each successful RMW records its captured
address, old/new values and effective acquire/release attributes; acquire is
suppressed for Rt=ZR. The combined 143-job build passed 240 encoded vectors,
six refusal paths, encoding/footprint checks and existing memory proofs
(`m2-lse/build-8`). It assumes enabled FEAT_LSE, flat little-endian memory and
natural alignment; permission, initialization, translation and LSE2 profiles
remain open. ARM source statuses are 69 present, one missing, two partial and
two linking-layer labels, with exclusives and pair/fault work still pending.

The same acceptance also passed 108 LNSym symbolic-test jobs in its own package
context, avoiding the two forks' overlapping `Tests` library names. Fork
`dd1cfdb` fixes the initial field-reflexivity proof's type and simplifies
conditional PC updates with the existing validity/alignment premises. A direct
kernel check and a fully proved final-state store regression cover the fixes.
Imported upstream AES-GCM modules still contain existing `sorry` declarations;
this validation is not a claim of migrated M5 refinements or an admission-free
upstream proof corpus.

LNSym `88fcbc0754ee` adds LDXR/LDAXR/STXR/STLXR B/H/W/X and CLREX, with an
explicit physical reservation range and per-attempt virtual/local/global/commit
outcomes. Missing platform inputs are refused. The implementation preserves
monitor-failure versus abort priority, status/ZR/SP identities and acquire/release
observations; failed stores emit no memory write. The 146-job combined build
passed 96 load vectors, 144 store vectors, 22 refusals, 32 CLREX cases and a real
reserve/commit/clear/retry sequence; standalone symbolic checks passed 110 jobs
(`m2-exclusive/build-2`). Pinned Sail ASL2023-03 sources were inspected, without
claiming a new differential run. The flat-memory/natural-alignment profile still
lacks permission/translation/LSE2 fault handling. ARM source statuses are now
70 present, zero missing, two partial and two linking-layer labels; this does
not complete M2's remaining pair/fault and retained-environment work.

LNSym `faa8ac3504f5` fixes the shared pair executor so SP-alignment faults do
not advance PC. The 147-job combined build and 110-job symbolic check passed
75 encoded pair loads, 68 stores and 75 refusal paths across W/X/S/D/Q, LDPSW,
signed-offset/pre/post addressing, ZR/SP, V31, aliases, sign/upper bits, writeback
and both access-history frames (`m2-pair/build-2`). That checkpoint left
LDP/STP partial for permission, initialization, LSE2 granularity and ordered
partial-fault behavior; the checked-memory extension below addresses that gap.

LNSym `581d57515080` adds `stepi_checked`, using the same instruction bodies as
the existing total-memory API. An explicit optional `MemoryProfile` supplies byte
permissions, initialization and SP/pair access attributes. Missing profiles are
refused. Successful writes initialize only written bytes; reads retain actual
values even when their initialization observation is false. Typed memory events
and faults preserve ordered prefixes. A second pair-store fault retains the
first write without committing register/writeback/PC changes; pair-load faults
commit neither destination. Effective single accesses apply to scalar unsigned
pairs; SIMD pairs and LDPSW retain two accesses, as in pinned Sail ASL2023-03.

The 149-job combined build and 111-job standalone symbolic check passed 180
single-transfer and 462 pair-profile cases, plus SP-policy, missing-profile,
unsupported-class and legacy-API checks (`m2-checked-memory/build-3`). Generic
monad normalization rules preserve existing symbolic proofs without adding
admissions or changing their premises. The original total API still has its
original memory domain; M3 must use the checked interface for retained fault
observations. At this checkpoint, checked atomic/exclusive and multiple-structure
SIMD paths were refused; the atomic extension below addresses that class.
Flat little-endian platform binding, x86 memory/canonicality and retained control/system forms remain work. The source
table now has 72 present and two linking-layer ARM labels; M2 remains open.

LNSym `176be60339e6` extends the same checked step with B/H/W/X LSE ADD/CLR/SET
and store aliases. Both read and write byte permissions are checked before
committing an indivisible RMW. One typed atomic event captures old/new values,
ordering and old initialization; only committed bytes become initialized.
SP and effective LSE2 alignment faults preserve data registers, memory and PC.
LSE2 relaxation requires the range to fit one aligned 16-byte quantity and an
explicit platform attribute; pair access shape alone does not enable it.

The 149-job combined build and 111-job standalone symbolic check passed all
prior suites, 1,920 permission/initialization profiles over the existing 240
assembled goldens, and 64 alignment/SP/permission combinations
(`m2-checked-atomic/build-3`). Two earlier build failures (field notation and a
test parser error) remain archived. No new admissions or legacy theorem premise
changes were introduced. These finite checks do not establish MMU, external-abort
or concurrent-memory conformance and are not M5 refinement counts. That
checkpoint still refused checked exclusives and multiple-structure SIMD.

LNSym `909f455bd66d` adds checked B/H/W/X exclusive transfers and CLREX through
the same opcode bodies. Byte permissions, initialization, SP policy and effective
LSE2 alignment use the existing checked access layer. In the pinned Sail ordering,
VA failure precedes translation; once VA passes, write-permission denial precedes
local monitor clearing even if the local/global/commit outcome would fail.
Successful loads record reservation before their read, stores record an attempt
before a committed write, and CLREX records a clear without requiring memory
or exclusive inputs. All actions share the ordered memory-effect trace.

The 149-job combined build and 111-job standalone symbolic check passed 672
load and 1,008 store profile cases over the unchanged 96/144 assembled goldens,
320 alignment/SP/permission/VA/abort-priority combinations, 64 CLREX binding
combinations and a four-step reserve/commit/clear/failure sequence with exact
events and initialization (`m2-checked-exclusive/build-3`). Earlier list-type
and record-layout failures remain archived. Default total-domain behavior and
legacy theorem premises are unchanged; no admissions were added.

The old `Reference/AArch64.lean` currently emits read-before-reserve and models
store permission faults after clearing/recording an attempt, with different
monitor-failure permission gating. This differs from the checked fork's source
ordering. The native binding and retained fault observations need explicit
reconciliation in M2/M3; these finite checks do not migrate those theorems.
MMU/physical external aborts/concurrency remain outside this flat profile.
At this checkpoint, the retained ARM controls and x86 fault/canonicality bindings
were still open. M2 is not complete; M3-M6 have not started.

LNSym `dc8bd3f3ec9d` adds retained TBZ/TBNZ and plain BR/BLR, and fixes register31
in register branches to read XZR. BLR captures its target before writing X30,
including BLR X30. BL/BLR now report X30 in their register footprint. TBZ/TBNZ
have both CFG edges with the actual branch predicate; unresolved BR/BLR targets
are explicitly refused by static CFG analysis rather than classified as RET.
The plain branch projection excludes PAC, GCS and BTI state.

The 151-job combined build and 112-job symbolic check passed 768 bit/PC-wrap
cases covering all 64 tested bits, 40 signed-boundary/ZR cases, 54 indirect
branch/alias/frame cases, six unsupported neighbors and two footprint checks,
plus the original BranchTest regressions (`m2-control-branches/build-3`).
GNU as assembled all 161 positive fixture words independently. Earlier test
elaboration failures remain archived; no instruction assertions or old theorem
premises were weakened, and no admissions were added.

Scope inspection also confirms that LD1/ST1 multiple-structure instructions are
absent from both the 74-operation roster and the old AArch64 reference. Their
checked refusal is retained; expanding that class is not required for this
migration. That checkpoint left MRS thread-pointer inputs, x86 fault and
canonicality bindings, and old exclusive fault observations to reconcile.

LNSym `da428593b21d` adds decoded TPIDR_EL1/TPIDR_EL2 MRS with explicit per-step
`ThreadPointerInputs`. Missing bindings are refused; a bound denial returns typed
`SystemRegisterDenied` with the register encoding, preserving Xt/PC and all effect
histories. Permitted reads write Xt and advance PC; Xt=31 still checks access and
discards the value. Canonical state equality includes the new input component.
The 153-job combined build and 113-job symbolic check passed 288 profiles across
six GNU-as words, two PCs, four values and six independent input bindings, plus
three unsupported MRS forms, a changing-input sequence and NOP frame
(`m2-thread-pointer/build-2`). The initial existing memory proof SAT timeout is
retained; identical-source retry passed without proof or timeout-setting changes.

These are resolved access outcomes for the current EL/trap/virtualization
configuration. In pinned Sail, an EL1 TPIDR_EL2 read may redirect to NVMem under
NV2/NV, trap or be undefined; permitted outcomes are not universally physical
register constants. Full privilege decisions and exception-vector entry remain
outside this projection. M3 must prove binding admissibility and map the typed
denial to the retained fault observation. M2 remains open for x86 fault/canonical
support and native exclusive-observation reconciliation; M3-M6 are untouched.

x86lean `4777fb8e1b84` adds explicit `LinearAddressWidth.la48/la57` to the existing
`canonical`, `Cpu.setRipChecked`, `step` and `run` functions. Default 48-bit
behavior and all prior characterization statements/proofs remain unchanged.
The selected width reaches existing JMP/CALL/Jcc/JCXZ/LOOP/RET target checks and
the bit-string byte-address check. Two generic kernel proofs relate the test to
selected-width sign extension and show that 48-bit canonicality implies 57-bit.
Their inspected axiom dependencies stay within the upstream allowlist
(`propext`, `Classical.choice`, `Quot.sound`); no native-reduction axiom, admission
or proof-policy exception was added.

The 154-job combined build and 113-job independent LNSym symbolic check passed
632 kernel-`decide` checks: literal boundary classifications, actual step target
selection, rejected CALL/RET stack preservation, conditional branches, LOOP,
signed bit-byte addressing, run forwarding and stopped-state stability
(`m2-x86-canonical/build-4`). Earlier lemma-name, conditional-proof and test-layout
failures remain archived, with no assertion removed. These are post-decode AST
checks, not encoded-form/hardware/ACL2 differential results or M5 refinements.
That step uses the external model's refusal convention on noncanonical inputs.
Existing fallthrough and LOOP model-stop behavior is retained. The optional
checked scalar entry below adds flat-memory faults; control transfers remain
unported to that entry. LAM/tag masking and page translation are outside this input.

x86lean `9e6f4fe02488` adds [stepChecked/runChecked](external/x86lean/X86/CheckedMemory.lean)
over the existing numeric step. An explicit byte-permission/initialization profile
surrounds the unchanged Cpu. Effective addresses use the existing Ea.addr;
selected-width canonicality checks every byte before permissions. Successful
reads expose actual bytes and ghost initialization, successful stores initialize
their exact wrapping range, and a denied store retains the read prefix without
committing CPU state. MOV, ordinary binary/unary arithmetic, extending loads,
CMOV and SETcc are supported; LEA/NOP need no memory access. False-condition
CMOV still reads its memory source. UD2/illegal LOCK have typed invalid-opcode
outcomes. Missing profiles and unported instruction classes explicitly refuse;
there is no total-memory fallback. These are flat access outcomes, without MMU,
CR2/error codes, concurrency or exception-vector entry.

The final 156-job combined build and 113-job standalone LNSym check passed
793 kernel-decide cases (712 operand/permission/init, 56 canonical spans,
16 malformed operands, nine capability/terminal/sequence checks), including
literal values, flags/oracle/frame preservation, base/destination aliasing,
RIP-relative/FS/GS addresses and ordered fault prefixes. The stopped-state
theorem uses simp and only the existing allowed axioms. Numeric Semantics,
State, Memory and all existing Theorems files are byte-identical to the entry
pin. Raw `m2-x86-checked-access/build-3` retains the accepted result and earlier
parser failure/successful revision; no assertion removed or admission added.
These are post-decode finite checks, not hardware/ACL2 differential results or
M5 refinements. At that checkpoint, checked stack/control, shifts/rotates,
strings, vectors and atomic classes remained open, alongside ARM native exclusive
binding.

x86lean `ebf6519ea76d` extends that checked entry to shifts/rotations/double shifts,
flagless shifts/rotations, MOVBE, bit counts/scans, BZHI, ANDN, IMUL and
MUL/DIV/MULX; BSWAP needs no memory access. Zero-count memory shifts/rotations
retain read-modify-write permissions and exact initialization. The original
shared division helpers classify typed divide errors after successful source
access: read faults take priority, and divide errors retain the read prefix
without CPU commit. The existing undefined double-shift memory-result refusal
retains its read and does not validate or invent a store.

Another 1,828 kernel-decide cases passed, for 2,621 total in the focused suite:
896 shift/rotate, 192 double-shift, 480 scalar-source, 56 address/destination
alias, 12 register-only, eight undefined-result refusal, 32 invalid operand,
144 division and eight multiplication cases. Signed/unsigned division covers
all four widths, AX byte pairing, zero divisors, overflow, permission priority
and missing profiles. The 156-job combined and 113-job standalone symbolic
builds passed (`m2-x86-scalar/build-3`). Earlier parser/default proof-resource
failures remain archived; identical cases were partitioned without removing
assertions or changing resource-limit settings. Numerical Semantics, State,
Memory, Value, Flags and Theorems files are byte-identical to the entry pin;
actual checked-step/stopped-theorem axiom lists match the existing allowlist.
These remain finite post-decode checks, not M5 refinements. Checked stack/control,
bit tests, strings, vectors and atomics, plus native exclusive/fault bindings,
keep M2 open. The byte/word access granularity of native bit-test observations
also needs an explicit relation; a constructor match alone does not prove it.

### AArch64: 74 simulator operations

| Code | Operation | Source status | LNSym source (Arm/Insts unless Arm/) | Constraint / work |
|---|---|---|---|---|
| 0x00 | `NOP` | present | [BR/Hints.lean](external/LNSym/Arm/Insts/BR/Hints.lean) | NOP encoding |
| 0x01 | `MOV_IMM` | present | [DPI/Move_wide_imm.lean](external/LNSym/Arm/Insts/DPI/Move_wide_imm.lean) | MOVZ/MOVN/MOVK, retain width and encoding |
| 0x02 | `MOV_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | ORR alias for GPR/ZR; ADD immediate0 alias for SP, keep register identities |
| 0x03 | `ADD_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x04 | `SUB_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x05 | `MOVK` | present | [DPI/Move_wide_imm.lean](external/LNSym/Arm/Insts/DPI/Move_wide_imm.lean) | MOVZ/MOVN/MOVK, retain width and encoding |
| 0x06 | `ALU_IMM` | present | [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Requires architectural bitmask encoding |
| 0x07 | `ALU_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x08 | `SHIFT_IMM` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean); [DPI/Extract.lean](external/LNSym/Arm/Insts/DPI/Extract.lean) | LSL/LSR/ASR bitfield aliases and EXTR-based ROR |
| 0x09 | `SHIFT_REG` | present | [DPR/Data_processing_two_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_two_source.lean) | LSLV/LSRV/ASRV/RORV |
| 0x0a | `MADD` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | MUL aliases MADD with Ra=XZR |
| 0x0b | `MSUB` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | W/X forms; accumulator captured before destination write |
| 0x0c | `MUL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | MUL aliases MADD with Ra=XZR |
| 0x0d | `UMULL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | UMADDL alias with Ra=XZR |
| 0x0e | `UDIV` | present | [DPR/Data_processing_two_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_two_source.lean) | W/X forms; divisor zero returns zero, flags unchanged |
| 0x0f | `MVN` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x10 | `NEG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x11 | `EXTR` | present | [DPI/Extract.lean](external/LNSym/Arm/Insts/DPI/Extract.lean) | Decoded W/X extraction, including ROR alias and shift-bound checks |
| 0x12 | `BITFIELD` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x13 | `REV` | present | [DPR/Data_processing_one_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_one_source.lean) | REV widths per legal opcode |
| 0x14 | `REV16` | present | [DPR/Data_processing_one_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_one_source.lean) | REV widths per legal opcode |
| 0x15 | `SXTH` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x16 | `CMP_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x17 | `CMP_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x18 | `TST_IMM` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x19 | `TST_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x1a | `CCMP_IMM` | present | [DPR/Conditional_compare.lean](external/LNSym/Arm/Insts/DPR/Conditional_compare.lean) | Unsigned imm5 operand; arithmetic or literal fallback NZCV, empty GPR footprint |
| 0x1b | `CCMP_REG` | present | [DPR/Conditional_compare.lean](external/LNSym/Arm/Insts/DPR/Conditional_compare.lean) | GPR/ZR operand; arithmetic or literal fallback NZCV, empty GPR footprint |
| 0x1c | `CSEL` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSEL plus CSINC/CSINV/CSNEG, legal S=0/op2[1]=0 |
| 0x1d | `CINC` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x1e | `CSET` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x1f | `LOAD` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Unsigned GPR sizes B/H/W/X; unsigned/unscaled/pre/post/register offsets |
| 0x20 | `STORE` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | GPR sizes B/H/W/X; unsigned/unscaled/pre/post/register offsets |
| 0x21 | `LDP` | present | [LDST/Reg_pair.lean](external/LNSym/Arm/Insts/LDST/Reg_pair.lean); [Arm/Memory/Access.lean](external/LNSym/Arm/Memory/Access.lean) | Checked permission/init/prefix faults; scalar unsigned single-access profile, SIMD/LDPSW ordered accesses; platform binding remains |
| 0x22 | `STP` | present | [LDST/Reg_pair.lean](external/LNSym/Arm/Insts/LDST/Reg_pair.lean); [Arm/Memory/Access.lean](external/LNSym/Arm/Memory/Access.lean) | Checked permission/init/prefix faults; scalar unsigned single-access profile, SIMD/LDPSW ordered accesses; platform binding remains |
| 0x23 | `FMOV` | present | [DPSFP/Conversion_between_FP_and_Int.lean](external/LNSym/Arm/Insts/DPSFP/Conversion_between_FP_and_Int.lean) | Both GPR directions use ZR for field31; four encoded W/X ZR regressions pass |
| 0x24 | `CNT` | present | [DPSFP/Advanced_simd_two_reg_misc.lean](external/LNSym/Arm/Insts/DPSFP/Advanced_simd_two_reg_misc.lean) | CNT 8B/16B; five UADDLV arrangements; upper clearing, alias and V31 checks |
| 0x25 | `UADDLV` | present | [DPSFP/Advanced_simd_across_lanes.lean](external/LNSym/Arm/Insts/DPSFP/Advanced_simd_across_lanes.lean) | CNT 8B/16B; five UADDLV arrangements; upper clearing, alias and V31 checks |
| 0x26 | `ADRP_GOT` | layer | [DPI/PC_rel_addressing.lean](external/LNSym/Arm/Insts/DPI/PC_rel_addressing.lean) | ADRP exists; relocation/GOT/readonly resolution is linking premise |
| 0x27 | `ADRP_RODATA` | layer | [DPI/PC_rel_addressing.lean](external/LNSym/Arm/Insts/DPI/PC_rel_addressing.lean) | ADRP exists; relocation/GOT/readonly resolution is linking premise |
| 0x28 | `LOAD_D0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | D load via all five address modes; upper vector bits cleared |
| 0x29 | `STORE_D0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | D store via all five address modes |
| 0x2a | `LOAD_Q0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Q load via all five address modes, including extended/scaled register offsets |
| 0x2b | `STORE_Q0` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Q store via all five address modes, including extended/scaled register offsets |
| 0x2c | `TST_BIC_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x2d | `ANDS_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x2e | `UMULH` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Full 128-bit product, high64 result; Ra ignored |
| 0x2f | `SXTW` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x30 | `SUBS_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x31 | `ADDS_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x32 | `SUBS_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x33 | `CMN_IMM` | present | [DPI/Add_sub_imm.lean](external/LNSym/Arm/Insts/DPI/Add_sub_imm.lean) | S/op/Rd encode CMP/CMN |
| 0x34 | `CINV` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x35 | `ORN_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x36 | `LDRSB` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed byte to W/X across all five address modes; W writes zero-extend in X |
| 0x37 | `ANDS_IMM` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x38 | `STLXR` | present | [LDST/Exclusive_single.lean](external/LNSym/Arm/Insts/LDST/Exclusive_single.lean); [BR/Clear_exclusive.lean](external/LNSym/Arm/Insts/BR/Clear_exclusive.lean) | B/H/W/X exclusive loads/stores and CLREX; checked permission/init/SP/LSE2 and ordered monitor effects; retained fault binding needs reconciliation |
| 0x39 | `LDRSW` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed word to X across all five address modes |
| 0x3a | `CMN_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x3b | `UMADDL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Unsigned32 multiplicands widened before multiplication |
| 0x3c | `SXTB` | present | [DPI/Bitfield.lean](external/LNSym/Arm/Insts/DPI/Bitfield.lean) | BFM/SBFM/UBFM and extension aliases |
| 0x3d | `CSINV` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x3e | `CSINC` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x3f | `LDRSH` | present | [LDST/Reg_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_imm.lean); [LDST/Reg_unscaled_imm.lean](external/LNSym/Arm/Insts/LDST/Reg_unscaled_imm.lean) | Signed halfword to W/X across all five address modes; W writes zero-extend in X |
| 0x40 | `SMADDL` | present | [DPR/Data_processing_three_source.lean](external/LNSym/Arm/Insts/DPR/Data_processing_three_source.lean) | Signed32 multiplicands widened before multiplication |
| 0x41 | `CNEG` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x42 | `ADDS_REG` | present | [DPR/Add_sub_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_shifted_reg.lean); [DPR/Add_sub_extended_reg.lean](external/LNSym/Arm/Insts/DPR/Add_sub_extended_reg.lean); [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean) | Shifted/logical and all eight extended-register ADD/SUB options; SP/ZR and NZCV checks |
| 0x43 | `BICS_REG` | present | [DPR/Logical_shifted_reg.lean](external/LNSym/Arm/Insts/DPR/Logical_shifted_reg.lean); [DPI/Logical_imm.lean](external/LNSym/Arm/Insts/DPI/Logical_imm.lean) | Alias encodings |
| 0x44 | `CSETM` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x45 | `CSNEG` | present | [DPR/Conditional_select.lean](external/LNSym/Arm/Insts/DPR/Conditional_select.lean) | CSINC/CSINV/CSNEG and aliases; 24 encoded W/X branch/ZR/wrap/frame checks pass |
| 0x46 | `LDADD` | present | [LDST/Atomic_memory_op.lean](external/LNSym/Arm/Insts/LDST/Atomic_memory_op.lean) | B/H/W/X, A/R and ST aliases; old/new/order observations; checked byte permissions/init/SP and effective LSE2 alignment, flat little-endian domain |
| 0x47 | `LDSET` | present | [LDST/Atomic_memory_op.lean](external/LNSym/Arm/Insts/LDST/Atomic_memory_op.lean) | B/H/W/X, A/R and ST aliases; old/new/order observations; checked byte permissions/init/SP and effective LSE2 alignment, flat little-endian domain |
| 0x48 | `LDCLR` | present | [LDST/Atomic_memory_op.lean](external/LNSym/Arm/Insts/LDST/Atomic_memory_op.lean) | B/H/W/X, A/R and ST aliases; old/new/order observations; checked byte permissions/init/SP and effective LSE2 alignment, flat little-endian domain |
| 0xff | `RET` | present | [BR/Uncond_branch_reg.lean](external/LNSym/Arm/Insts/BR/Uncond_branch_reg.lean) | Plain RET/BR/BLR; XZR for Rn31, BLR captures target before LR update; unresolved indirect CFG targets refuse |

Outside the 74-operation roster, LDXR/LDAXR/STXR and CLREX now execute in the fork. B/B.cond/CBZ/CBNZ/TBZ/TBNZ, plain BR/BLR and TPIDR_EL1/EL2 MRS have paths; system access outcomes need explicit per-step bindings. These are not extra completed operation tokens.

### x86-64: 75 simulator operations

| Code | Operation | Source status | x86lean constructor | Constraint / work |
|---|---|---|---|---|
| 0x00 | `nop` | present | [nop](external/x86lean/X86/Syntax.lean) |  |
| 0x01 | `movImm` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x02 | `movReg` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x03 | `addImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x04 | `addReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x05 | `xorReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x06 | `movLoad` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x07 | `movStoreImm` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x08 | `movStoreReg` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x09 | `lea` | present | [lea](external/x86lean/X86/Syntax.lean) |  |
| 0x0a | `aluImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0b | `aluReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0c | `cmpImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0d | `cmpReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0e | `testImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x0f | `testReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x10 | `jcc` | present | [jcc](external/x86lean/X86/Syntax.lean) |  |
| 0x11 | `jmp` | present | [jmp](external/x86lean/X86/Syntax.lean) |  |
| 0x12 | `push` | present | [push](external/x86lean/X86/Syntax.lean) |  |
| 0x13 | `pop` | present | [pop](external/x86lean/X86/Syntax.lean) |  |
| 0x14 | `call` | present | [call](external/x86lean/X86/Syntax.lean) | Native CALL; external ABI/effects separate |
| 0x15 | `cmov` | present | [cmov](external/x86lean/X86/Syntax.lean) | Read memory before condition test |
| 0x16 | `setcc` | present | [setcc](external/x86lean/X86/Syntax.lean) |  |
| 0x17 | `bswap` | present | [bswap](external/x86lean/X86/Syntax.lean) |  |
| 0x18 | `popcnt` | present | [bitcnt .popcnt](external/x86lean/X86/Syntax.lean) |  |
| 0x19 | `xchg` | present | [xchg](external/x86lean/X86/Syntax.lean) |  |
| 0x1a | `div` | present | [muldiv .div / .idiv](external/x86lean/X86/Syntax.lean) | Signed/unsigned subopcodes, all sizes |
| 0x1b | `shldImm` | present | [dshift](external/x86lean/X86/Syntax.lean) | 16-bit memory destination with masked count>16 explicitly stops as unimplemented; preserve actual register/memory domain |
| 0x1c | `shrdImm` | present | [dshift](external/x86lean/X86/Syntax.lean) | 16-bit memory destination with masked count>16 explicitly stops as unimplemented; preserve actual register/memory domain |
| 0x1d | `cmpMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x1e | `testMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x1f | `cmpMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x20 | `movzxReg` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x21 | `movsxReg` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x22 | `movsxLoad` | present | [movx](external/x86lean/X86/Syntax.lean) |  |
| 0x23 | `aluMem` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x24 | `cmpRegMem` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x25 | `movLoadScalar` | present | [mov](external/x86lean/X86/Syntax.lean) |  |
| 0x26 | `shiftx` | present | [shiftx](external/x86lean/X86/Syntax.lean) |  |
| 0x27 | `rorx` | present | [rorx](external/x86lean/X86/Syntax.lean) |  |
| 0x28 | `movbeLoad` | present | [movbe](external/x86lean/X86/Syntax.lean) |  |
| 0x29 | `movbeStore` | present | [movbe](external/x86lean/X86/Syntax.lean) |  |
| 0x2a | `shiftxMem` | present | [shiftx](external/x86lean/X86/Syntax.lean) |  |
| 0x2b | `rorxMem` | present | [rorx](external/x86lean/X86/Syntax.lean) |  |
| 0x2c | `movLoadMapPtr` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2d | `movLoadHelperId` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2e | `callHelper` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x2f | `callReg` | present | [call](external/x86lean/X86/Syntax.lean) | Native CALL; external ABI/effects separate |
| 0x30 | `loadXmm0` | present | [vload/vstore; vloadq/vstoreq](external/x86lean/X86/Syntax.lean) | Retain actual D/Q width, alignment, scalar upper bits |
| 0x31 | `storeXmm0` | present | [vload/vstore; vloadq/vstoreq](external/x86lean/X86/Syntax.lean) | Retain actual D/Q width, alignment, scalar upper bits |
| 0x32 | `aluMemUnary` | present | [un / shift](external/x86lean/X86/Syntax.lean) |  |
| 0x33 | `aluMemImm` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x34 | `bzhi` | present | [bzhi](external/x86lean/X86/Syntax.lean) | Already implemented30c9b2e: Value.bzhi, Flags.bzhi, step_bzhi_cf and bzhi_index_past; coverage T-frame, x86isa refuses |
| 0x35 | `bzhiMem` | present | [bzhi](external/x86lean/X86/Syntax.lean) | Already implemented30c9b2e: Value.bzhi, Flags.bzhi, step_bzhi_cf and bzhi_index_past; coverage T-frame, x86isa refuses |
| 0x36 | `aluMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x37 | `bt` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x38 | `imulImm` | present | [imulr](external/x86lean/X86/Syntax.lean) |  |
| 0x39 | `mulx` | present | [mulx](external/x86lean/X86/Syntax.lean) |  |
| 0x3a | `repMovs` | present | [repstrop .rep .movs](external/x86lean/X86/Syntax.lean) | Rep semantics and fault-prefix transport remain explicit |
| 0x3b | `testMemReg` | present | [bin / un / shift](external/x86lean/X86/Syntax.lean) | Select ALU subopcode, retain width/high8/old flags |
| 0x3c | `callMemset` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x3d | `andn` | present | [andn](external/x86lean/X86/Syntax.lean) |  |
| 0x3e | `setccMem` | present | [setcc](external/x86lean/X86/Syntax.lean) |  |
| 0x3f | `callMemcpy` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x40 | `cmovMem` | present | [cmov](external/x86lean/X86/Syntax.lean) | Read memory before condition test |
| 0x41 | `imulMemImm` | present | [imulr](external/x86lean/X86/Syntax.lean) |  |
| 0x42 | `btImm` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x43 | `btMemImm` | present | [bit .bt](external/x86lean/X86/Syntax.lean) |  |
| 0x44 | `andnMem` | present | [andn](external/x86lean/X86/Syntax.lean) |  |
| 0x45 | `callMemsetReg` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x46 | `callMemcpyReg` | layer | [mov / call](external/x86lean/X86/Syntax.lean) | Symbol/helper resolution or library effects belong to decoded-sequence/ABI relation |
| 0x47 | `popcntMem` | present | [bitcnt .popcnt](external/x86lean/X86/Syntax.lean) |  |
| 0x48 | `ror` | present | [rot .ror](external/x86lean/X86/Syntax.lean) |  |
| 0x49 | `rorMem` | present | [rot .ror](external/x86lean/X86/Syntax.lean) |  |
| 0xff | `ret` | present | [ret](external/x86lean/X86/Syntax.lean) | Native stack pop; simulator return modes need relation |

Cross-cutting gaps: X86.Mem retains its finite byte association list with implicit zero background and total default reads/writes. Its optional checked step now handles explicit permissions, initialization, canonical spans and ordered flat/divide faults for the scalar subset above, including shifts and retained scalar-source families; other instruction classes refuse. The default step selects 48/57-bit canonicality for its existing target/bit-byte checks. Checked stack/control/bit-test/string/vector/atomic and remaining families, plus precise platform fault delivery, remain open. LNSym retains its total-byte-memory API and now also has a checked step for single/pair/exclusive transfers and LSE RMWs with byte permissions, initialization and ordered fault observations. That profile must be bound explicitly; it is not a full MMU/concurrency model. LSE RMWs retain old/new/order metadata in one checked effect; exclusives bind physical-monitor inputs and ordered monitor/memory effects. Out-of-roster multiple-structure SIMD paths remain explicitly refused. Old exclusive fault/trace bindings differ and require reconciliation. Thread-pointer outcomes now bind explicitly; native admissibility and the remaining memory/platform bindings are open. These are not closed by listing instruction constructors; M2/M3 must preserve the existing theorem domains through external-model extensions and explicit relations. x86lean takes post-decode Instr.op/len. BZHI is absent from the differential roster, not absent from step: do not duplicate its semantics.

## Legacy foundation (migration pending)

Safety uses two facts: the stock verifier accepts B, and B faithfully simulates
P. This directory proves generic simulator and token laws; native-link
preservation lives in [tv/](../tv/). The current
[coverage ledger](../results/kprog_verification_20261107/README.md) records every
operation/token, its exact theorem domain, replay source epoch and remaining
implementation interface. It currently records71 x86-64 complete current C-model token-body equalities and73 of74
AArch64 operation bodies, plus an explicit current RET exit-contract interface
and two returning-helper interface equalities. LDADD/STADD0x46, LDSET/STSET0x47 and LDCLR/STCLR0x48 share canonical atomic access, typed success laws and unified token bindings. Additional helper macro-routing and two-mode RET control laws retain their
parametric/source bindings and do not increase the71 complete current x86 bodies.
Full ISA and compiled-simulator closure remain active work. The production DIV signed AUX1 branch has its canonical signed reference and554 semantic scenes. Signed/unsigned AUXbit0 dispatch and arbitrary fresh flags compose through the generic step/token laws. The current signed DIV raw/tag body directly executes all four widths of word arithmetic, the complete restoring loop/zero-high fast path, word-limit comparison and unsigned sign restoration, composing captured operands and whole state/fresh flags through current dispatcher/O2 laws. Both unsigned and signed domains now meet the concrete C-model token category used by the other complete rows. C-source extraction, compiled-B and physical/ABI transport remain explicit interfaces.

`X86RemainingTokenO2.StackRelease` adds seventeen universal component laws for
internal RET lifetime: ordered fresh-byte writes over the released signed
interval, clearing every declared below-SP word tag/valid field, preserving
pointer/scalar payloads and live cells, pre-release saved-word capture and
selected/default token transport. Sparse declared-word lists and arbitrary fresh
bytes are quantified. Source owned-read/forwarding, signed-coordinate validity,
live-stack/native-memory representation and compiler/physical transport remain
explicit interfaces; RET retains its partial category.

Nine additional owned-read laws cover full64 scalar forwarding, unaligned byte
assembly, saved-word projection, live-read preservation and byte reads after
reallocation. Source byte/scalar coherence supplies the saved-read premise;
computed index, union memory and physical/compiler transport retain their
explicit source profile.

Twelve source-coordinate/coherence laws connect the actual wrapping generated
stack index, signed raw-SP coordinate and native byte addresses. An allocated
eight-byte return interval derives exact signed RSP advance and supplies the
source read projection. The live byte/scalar relation survives release and
composes current source RET with the reference step and selected/default token.
C/compiler establishment of that relation, producer mode and physical control
transport remain explicit interfaces.

`ControlABI.ArmReturn` adds twelve current ARM RET component laws: raw target
decides RETURN-tag invocation or CODE-tag finite continuation/default, with
complete scratch capture and tag-aware X0 numeric materialization. Internal
branches refine the reference branch step in the stated numeric image, and
outer source callee/SP guards derive the native ABI contract. Actual producer
operand/table extraction and physical LR/code-PC/compiler transport remain
explicit; ARM RET retains its partial category.

Actual compiled scalar coverage is16 of75 x86 operations across158 combined
units, including two partial returning-helper units. Classic ROR adds five
width/lane units with arbitrary values, counts and fresh inputs; actual BPF
execution preserves memory/exclusive state and consumes the23 captured input
positions. Whole flags/tag/frame and physical/compiler embedding retain their
explicit simulator interfaces.

ADD_IMM contributes five actual scalar units for8-bit low/high lanes and16/32/64-bit
writeback, with the encoded imm32 sign extension at64-bit width. Seven execution
laws quantify every operand, immediate, fresh stream and initial visit, preserving
memory/exclusive state, consuming23 inputs and reaching the stated result.
The complete flags/tag/register frame and physical/compiler embedding remain
explicit interfaces.

ADD_REG adds seven actual scalar units: all four low/high byte-lane pairs and
16/32/64-bit writeback. Nine execution laws quantify every operand and fresh
stream and preserve memory/exclusive state with23 consumed inputs. Complete
flags/tag/GPR-frame, operand mapping and physical/compiler transport remain
explicit interfaces.

x86 raw handler/dispatcher refinement covers34/75 operations. JCC/JMP now
retain the full raw GPR/tag/flags/memory frame and select PC through generated
source shapes and a native label map. Source ordering and native address
ordering can differ. Ten control laws compile with module/root0 and sorryAx0;
the existing entry image and native/source/physical/compiler interfaces retain
their domains.

ARM raw handler/dispatcher refinement covers58/74 operations: immediate moves,
multiply/divide, shift/unary, ORN, extract/reverse/extension, conditional select,
bitfields, conditional compare, logical flags, arithmetic flags, MOV_REG, resolved GOT/RODATA addresses, CNT/UADDLV vector reductions, ADD/SUB immediate aliases, shared ALU tokens and FMOV.
One hundred and ninety-four laws audit and compile with module/root0 and sorryAx0. All raw64-bit
words, byte tags, STACK4/RETURN10 materialization, register aliases/XZR and the
complete architectural image compose through one58-operation emission step theorem.
CSEL/X retains its selected raw word/tag; scalar results use width/scalar-tag
writes. CNT/UADDLV capture both input halves and retain the complete raw GPR/tag,
SP, flags, memory, exclusive and other vector-bank frame. FMOV covers all32 vector banks and four directions, full raw/tag materialization,
vector high-half clearing and scalar-tag GPR width writes. Their token laws cover
all ignored fields; the current scalar producer policy retains its own domain. The six ALU selectors cover the arithmetic and logical domains of ALU_IMM/REG:
source provenance derives from captured tags, pointer increments commute with
materialization, and SP32/STACK writes retain their relative coordinates.
Native shifts/extensions and immediate aliases share the production dispatcher. STACK ORR transports its low-bit update through an explicitly aligned entry
stack origin; preceding emission bindings retain their origin domains. CCMP updates NZCV and preserves its complete raw GPR/tag frame. ANDS/BICS scalarize their destination; TST preserves the full raw tag map. ADDS/SUBS/CMP/CMN retain SP32-source materialization, shifted/extended operands and the full compare-only frame. MOV retains full raw/tag copies and SP coordinate writes; address writes retain generated GOT7/RODATA8 tags and resolved-IMM identities. SHIFT and conditions consume the actual whole AUX, while unary uses
AUX byte1/byte2. Native widths, amount/alias domains and NV normalization stay
explicit. The ledger retains production dispatcher equalities and arbitrary
unused-field domains. Entry origin identity, C extraction/union and physical/
compiler transport remain interfaces independent of B forwarding storage. Six
additional source-emitted branch families (B/B.cond/CBZ/CBNZ/TBZ/TBNZ) compose
with these58 numeric operations through one source-emission step theorem.
Source/current/next/target label-to-native-address identities stay explicit;
NZCV/value/bit tests derive the outcome and preserve the entire data/tag frame.
Their source-operation/token rows retain a separate6/6 raw count.


## Specification and proof scope

The reference ISA is defined once in
[Reference/X86.lean](KProgFormal/Reference/X86.lean) and
[Reference/AArch64.lean](KProgFormal/Reference/AArch64.lean), with shared
[memory, permissions, initialization and ordered effects/faults](KProgFormal/Reference/Memory.lean).
These definitions cite Intel/Arm sources and are independent of generated
implementation contracts. [ReferenceMain.lean](ReferenceMain.lean) executes
these same definitions through JSON for hardware and artifact comparisons.
The [Arm ASL state comparison](../results/kprog_verification_20261107/reference-arm-asl.md)
records5016 agreeing observations across74 operation labels and explicit STLXR
monitor profiles. LDADD adds1344 agreeing cases and stated atomic/compiler premises. It retains its source/binary
identities and platform premises alongside the [x86 Sail comparison](../results/kprog_verification_20261107/reference-x86-sail.md),
which, together with the [direct ACL2 comparison](../results/kprog_verification_20261107/reference-x86-acl2.md),
records63 agreeing operation labels and four ANDN/BZHI model-stopped labels
in the current selected comparison. Historical source epochs retain their observations. ACL28.7 retains72 memory-SHIFTX PC-1 observations
with matching GPR/flags/XMM/memory, plus48 REP element/whole-step differences.
Original source/certificate diagnostics and separate CPU evidence remain recorded.

Handler/dispatcher and specialized-token laws compose modeled registers,
PC, ordered memory effects, faults and defined architectural outputs under
their stated operand, address, access and platform premises. Undefined outputs
use the reference step's observation mask; uninitialized memory has arbitrary
values. The theorem statements and coverage rows give each operation's domain.
FreshAux composes the production ANDN/BZHI independent PF/AF choices, proves
complete local output realization and transports a two-position fresh stream.
Global incoming-state/other undefined-output and compiler/ABI transport remain
explicit interfaces.
The x86 pointer bodies share the extended dispatcher and refine resolved moves
for all sixteen registers, including the RSP coordinate. Native symbol/helper
address transport remains an explicit interface. Four memory-call token bodies
include sequential byte effects and the fresh caller-clobber frame; their
native call/ABI and physical memory relations remain explicit. Two helper token
wrappers prove full64-bit sparse ID routing, pre-call capture, result/memory/events
and fresh caller/callee-frame laws over a returning helper-effect interface;
typed arguments, native ABI and successful tail transfer remain explicit. Internal RET includes a total label/unresolved continuation result, with
complete captured read/SP advance in both alternatives. O2 covers its default;
O4 carries CALL -1 decode/error semantics and derives case membership for
accepted entered states under explicit compiled-edge/stock rejection premises.
The shared architectural-fault prefix also has actual byte decode/execution
and a complete scratch/memory/ghost frame at every linked instruction offset,
under literal-copy, entry/reachability, NULL-unmapped and verifier premises.
Actual returning BPF CALL laws also retain the pre-call argument snapshot,
full-width resolved identity, result/memory/effects and caller/callee/ghost frame
through identity-preserving resolution; physical/native ABI and C/compiler
correspondence remain explicit.
The existing x86/ARM callee-tag/value/SP exit predicates now derive the
quantified ABI contract and exact normal-return value/frame. The x86 RET-token
guard and native-return/JIT-result laws compose this contract under explicit
snapshot, stack-origin and tag-projection inputs. Internal return stack erasure,
ARM return-mode/LR binding, native-to-B entry and C/compiler/physical transport
remain explicit.

Architectural profiles are stated in the reference and theorem premises:
x86 near control uses 48/57-bit canonical addresses with CET disabled, and
LEAVE uses the LASS-disabled frame profile. ARM uses the Cortex-A72 base
profile with explicit SP alignment, pair-access granularity and exclusive
monitor/order inputs. Each dynamic exclusive attempt receives its own
possible failure outcome. Concurrent memory behavior retains its physical
profile obligations. The safety argument uses generic simulator, token and
link-transformation theorems; historical per-program artifacts stay frozen.

The typed byte atomic kfunc C model now composes ADD/SET/CLR operand truncation,
old-value return and one-byte state commit through the unified dispatcher.
Primitive ordering, kfunc identity/call ABI and compiler transport remain explicit.

The read-only helper return also composes its valid-cell stack-tag map with the
full return observation. Its index origin and signed below-SP policy are proved;
physical frame ownership, helper effects/provenance and ABI remain explicit.

## Trusted boundary

The boundary includes Lean's kernel/toolchain and executable reduction bridge
(`Lean.ofReduceBool`), contract generation and C/Lean correspondence, native
decoding/encoding, and the C/BPF compilation path. Entry ABI, physical
memory/provenance, exclusive monitor/order/site identity and native address
transport are caller/platform interfaces. The ledger distinguishes proved
model laws, finite oracle/hardware evidence and complete-check outcomes.
The generic readonly finite-case law also composes object identity and shifted
aliases with canonical memory reads; final byte transfer transports its frozen
image premise. Every permitted canonical guest write preserves the frozen
image and its write permissions. Physical symbol/map lifetime, helper/platform
state effects and C/compiler transport stay explicit.
The private-spill projection also proves actual decoded STXDW/LDXDW pair execution,
whole BPF register/input-frame and public-memory preservation, and exact owned
event erasure for every signed16-bit offset. Finite disjoint-write histories
preserve the saved read; actual decoded spill/arbitrary finite body/reload
composition restores the captured word and preserves the other body state
and ordered projected trace. Actual compiler ownership/layout, body control
and slot/frame liveness plus physical frame/ABI correspondence remain explicit.
[Composition](../tv/Composition.lean) and the
[artifact work](../tv/README.md) track the generic link/compiler obligations.

The existing X86StackIndex module also proves inactive stack-ghost payload
initialization/replacement is erased through finite save/invalidate/frame/clear
histories and complete lookup traversals, retaining active STACK pointers.
This metadata C-model law leaves C definedness and compiler/physical ABI explicit.

Arm64NumericAddress also proves sparse tag-table store/clear/copy preservation
under explicit initial-support and producer-domain coverage premises, plus
packed-word whole-byte-table store refinement. Actual CFG producer soundness
and C/clang storage correspondence remain explicit interfaces.

## Run

```sh
make -C kprog/formal check
```

Use an x86-64 Linux host with BMI1/BMI2 and POPCNT, Lean/Elan, Python3,
Rust/Cargo, a C compiler with UBSan, clang 18/LLVM 18, GNU objdump,
AArch64 cross-GCC, QEMU user emulation, and the vendor/libbpf and
vendor/linux-framework submodules. This entry point builds all Lean modules,
checks generated contracts and proof hygiene, and runs retained semantic C
oracles and executable-reference comparisons. The existing compiled CMOV unit covers all16 conditions and16/32/64 widths
through decoded clang bytes, arbitrary fresh inputs and whole-memory preservation;
The same fixture proves all32 SETCC condition/low-high-byte units and their actual
decoded executions, with arbitrary old value/flags/fresh inputs and whole-memory preservation;
BSWAP adds both32/64-bit widths with complete arbitrary BPF register/memory/ghost-frame
preservation and actual decoded executions. Their scalar-register mapping,
initial scratch state and invocation interface remain explicit. MOV_REG adds7 scalar byte-lane/width units with arbitrary whole memory and both
ghost indices; pointer/RSP frame and physical ABI embedding remain explicit.
MOVZX/MOVSX add15 scalar source-lane/width units with canonical extension,
whole memory and both ghost indices; register/tag frame and ABI embedding
remain explicit.
SHIFTX adds6 scalar width/count units with arbitrary counts and both SARX
control paths; complete register/flag/tag frame and ABI embedding remain
explicit.
UD2 adds exact0f0b decode and an unchanged-state #UD terminal, plus the
actual shared architectural-fault byte prefix and generic O2/O4 transport.
Its12 ACL2 observations retain the explicit model RIP+2 profile difference.
Compiler/link/entered-state and stock-soundness premises remain explicit.
ANDN adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
Two returning helper scalar units (lookup1/ktime5) retain argument/result,
complete helper memory/effects and independent clobbers under a matched platform
contract; full helper registry/tag/frame/native ABI/compiler transport remains
explicit. These are partial helper-body units, not a completed token family.
RORX adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
MOV_IMM adds5 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
BZHI adds2 scalar width/writeback units with width32 zero extension;
flags/native-frame/physical ABI embedding remain explicit.
POPCNT adds3 scalar width/writeback units, with high48 preservation at16
bits and zero extension at32 bits; full flags/register/tag frame and ABI
embedding remain explicit.
Existing build caches are reused. Generator checks compare locked numeric contracts
and generated artifacts; compiled oracles exercise the current production bodies.
The dated ledger retains exact source hashes, commands and original outcomes.

Caller-owned helper frames preserve exact saved reads through disjoint memory
effects; actual returning BPF CALL/LDXDW Execution retains the full helper/read
trace. Selected helper footprint, pointer lifetime and native ABI stay explicit.

Native x86 CALL/RET laws account for the actual RSP-8 return-slot write,
separate caller and return-slot footprints, saved PC and unsigned SP release.
Selected native helper stack restoration and physical native-to-B ABI remain explicit.

Conditional scalar read-recovery laws above the raw ISA account for stock-frame
x86/ARM zero-and-resume, including nativeX5/XZR and the raw fault prefix.
Actual site/table/exception-class/B-observation and O3 correspondence stay open.

x86 exception-table encoding also composes saved-GPR offsets, fixup fields and
relative final-PC entries with whole-register/PC recovery. Actual frame/site/table
lifetime and B/physical fault correspondence remain explicit.

ARM native-marker and paired-register fields likewise compose with whole-X/PC4
recovery, X5/XZR semantics and the actual raw fault state. Production site/frame
and B ordered-prefix correspondence remain explicit.

BPFPlatform also models seven kernel-internal nonarena PROBE_MEM/SX load
codes with full success/fault/frame and decoded-step laws. Actual conversion,
physical guard and O3/native fault-prefix correspondence remain explicit.

## Layout

- [Reference/](KProgFormal/Reference/): canonical ISA and memory specifications.
- [contracts/](contracts/), [generated/](generated/) and
  [Generated/](KProgFormal/Generated/): JSON inputs and generated C/Lean contracts.
- [KProgFormal/](KProgFormal/) and [Refinement/](KProgFormal/Refinement/):
  primitives, full-state refinements, dispatcher/token and environment laws.
- [oracles/](oracles/): retained semantic C oracles.
- [tools/](tools/): generators and semantic tooling.
  build/ and .lake/ hold incremental outputs.

Canonical ARM LDP recovery also proves first-element, second-element and
FEAT_LSE2 double-width fault paths, retaining ordered read events and clearing
both whole X destinations from the input frame before PC4 continuation.
Physical site/frame, pre/post writeback and compiled-B/O3 bindings remain explicit.

Kind4 per-CPU final-byte laws compose the selected entered thread-pointer
profile with canonical X10 materialization, preserving the full state and
empty trace through the final copied word. Physical CPU/profile and C/compiler
entry/copy/lifetime bindings remain explicit.

LEA adds12 scalar width/scale units with canonical writeValue, complete memory
and exclusive-index preservation and actual decoded execution. Field/address
mapping, pointer/RSP and physical native frame/compiler embedding remain explicit.
The current lookup1/ktime5 units include their decoded private byte store at
R10-8: the full execution has exact scratch memory and ordered store event,
under explicit successful-store/slot ownership premises. Prefix and suffix
composition retains the complete helper result and effects.
