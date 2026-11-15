# x86 context read C-subset checks

Four roots export the production SKB/XDP/cb read bodies and existing ABI tag
selector. Shared declaration/output bodies preserve byte order, raw/captured
width uses, partial scalar/pointer extraction and selected fallback reads.
Native fixed-offset, constant-predicate and asm operand forms remain. The three
MOV-load ABI tag consumers use their existing standard statement-output body.

The CompCert pointer fields use the existing typed context-pointer and
pointer-bits platform boundaries. The sole kernel's context conversion emits
pointer-sized loads for these UAPI32-bit fields. The host fixture has no verifier
conversion and expects its original32-bit field values; the adapter separately
checks full64-bit values, context/kind/UAPI field identity and ordered exposure.
No fresh or low32 substitute is used for the adapter's native pointer value.

`make clight` and `lake build KProgFormal.Clight.X86Context
KProgFormal.Clight.X86Pointer` in `kprog/formal` reproduce the final checks.
The raw directory records historical body replay, four read mutations, then the
adjacent tag-output connection and its extra mutation/final confirmation. All
prior logs stay. Guard pages catch extra bytes and the first faulting byte.
Two XDP/TC consumers and the existing ordinary fixture retain identical allocated
code/data and relocations under real BPF compilation; these fixtures were not
loaded or timed. Debug metadata and whole-application identity are not claimed.

These are extraction and finite host checks. The fixtures supply separate
logical UAPI and native-coordinate views. Actual entry binding, view/alias
coherence after writes and helper calls, pointer fragments, volatile/global
observations, permissions, initialization and native fault interpretation
remain M5 proof work; declarations and fixtures do not establish them.
Full interpreter export still fails at the memory-read source selector.
M4, all2,065 migrated refinements/recounts, M6 and whole-library acceptance remain
open. Extraction preprocessing size is profile-specific, not an app scale result.
