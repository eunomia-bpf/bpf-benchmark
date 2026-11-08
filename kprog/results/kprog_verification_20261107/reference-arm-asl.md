# Arm ASL reference comparison

The Armv9.4 ASL2023-03 Sail model and the canonical Lean reference agree on
972 instruction-state comparisons across71 enumerated operation labels.
The complete run contains996 comparisons:972 agree,12 LDADD inputs reach the
Lean decode boundary, and12 STLXR inputs expose the two recorded monitor
profiles. The original82 native forms cover all72 current operation labels.

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

LDADD's12 upstream executions complete; the canonical Lean decoder reports
its current instruction boundary. The LDADD reference step, handler refinement
and token binding remain active work. ADRP_GOT and ADRP_RODATA share the native
ADRP observation; O4 supplies their symbol/load relation.

[Structured receipt](reference-arm-asl.json) records every total and premise.
[Raw archive](reference-arm-asl.log.gz) retains the comparison scripts, native
assembly and object bytes, driver source, build receipts and all996 observations.
Each archive entry carries its length and SHA256. The existing full make check
retains its own fixed source and receipt.
