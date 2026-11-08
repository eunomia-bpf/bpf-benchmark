# Arm ASL reference comparison

The current canonical reference and Armv9.4 ASL2023-03 Sail model agree on
2328 instruction-state comparisons across all72 enumerated operation labels.
The current run contains2340 comparisons:2328 agree and12 STLXR inputs retain
the explicitly different monitor profiles. The82-form operation sample adds
112 LDADD/STADD forms over four widths, four order-bit choices and seven
register/base/SP/ZR alias profiles, with six boundaries and two NZCV inputs.

The original996-case source epoch remains in the first archive member:972
agree across71 labels,12 LDADD inputs reach its then-current Lean decode
boundary and12 STLXR inputs expose the recorded monitor profiles.

The observations include X0..X30, SP, PC, NZCV, V0 and every supplied memory
byte. Six scalar boundary pairs run with NZCV0 and0xf0000000. The platform is
EL3 AArch64, little endian, MMU disabled, SCTLR.SA enabled, aligned SP0x8000
and flat readable/writable initialized memory0x4000..0x401f. V1..V31 start at
zero. Ordered events, access permissions, translation and monitor implementation
remain explicit proof interfaces.

Upstream [sail-arm](https://github.com/rems-project/sail-arm/tree/7d0581642d0e3aaca367bbc5650aca7c53057543/arm-v9.4-a)
is pinned to7d0581642d0e3aaca367bbc5650aca7c53057543. Its40 source file hashes
are verified, Sail0.20.3 generation and GCC compilation both exit0, and the
one-step driver build exits0. The receipt includes exact source, binary and
input identities.

Upstream impdefs.sail supplies true for IsExclusiveLocal, IsExclusiveGlobal
and AArch64_IsExclusiveVA. The first12 STLXR inputs use Lean's empty monitor
and false pass inputs; their status and eight memory bytes differ. The next12
use Lean's explicit matching reservation and true pass inputs; every observed
state agrees. Both cohorts retain their original inputs and outputs.

LDADD/STADD now has one canonical8/16/32/64-bit reference step and actual
native-word decoding. Its numeric handler success law, AUX ordering identity,
unified dispatcher binding, direct memory-token equality and invocation-step
composition pass Lean. The existing complete Lean build and ARM native-link
checks pass, including81996 host and81996 QEMU per-CPU emitter cases.

The success law states SP/atomic alignment and readable/writable access as
platform premises. Physical atomic execution, pointer/tag provenance, complete
native-field coverage, interthread ordering, compiler and invocation ABI remain
explicit interfaces. SCTLR.A is clear and memory is Normal, flat and little
endian in the current reference profile. ADRP_GOT and ADRP_RODATA share the native
ADRP observation; O4 supplies their symbol/load relation.

[Structured receipt](reference-arm-asl.json) records every total and premise.
[Raw archive](reference-arm-asl.log.gz) retains the comparison scripts, native
assembly and object bytes, driver source, build receipts and every observation from both source epochs.
Each archive entry carries its length and SHA256. The existing full make check
retains its own fixed source and receipt.

## Current logical atomic reference epoch

The current frozen reference binary records5028 state comparisons across74
operation labels:5016 agree;12 original STLXR inputs retain the explicit
empty-monitor/fixed-success profile difference. The matched monitor cohort
agrees. LDSET/STSET and LDCLR/STCLR add224 forms and2688 agreeing cases, covering
8/16/32/64 bits, acquire/release combinations, SP/ZR and source/base/destination
aliases. LDADD's112-form1344-case grid and the complete82-form cohort were
repeated against this same binary. The source/model/binary SHA256 values and
raw observations are under `logical_atomic_current_reference` in the JSON.

The canonical atomic access/commit function is shared by ADD, OR and
AND-with-complement. Typed full-state handler laws and the unified dispatcher,
invocation and direct-token laws pass the379-module Lean build and existing ARM
link target. Atomic physical/tag mapping, access/alignment, compiler/ABI and
interthread ordering remain explicit premises. A's11520-scene C receipt includes
32/64-bit BPF units and Clang18 subword8/16-bit lowering diagnostics.
