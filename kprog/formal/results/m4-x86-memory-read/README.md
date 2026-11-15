# x86 shared memory and MOVBE C-subset checks

The MOVBE width/arm selectors and shared memory read have standard output
forms sharing their native declaration/expression bodies. CompCert inline
adapters pass the binding itself. Native fixed-offset and context operand
forms remain. Four roots export selectors, the generic shared read and the
complete MOVBE-load body in a15-function X86Memory module.

The CompCert pointer-slot load uses upstream alignment-one memcpy into a
volatile pointer local, preserving the full source window and pointer-valued
representation. Native BPF and unaligned host pointer loads stay as before.
The roots call actual X86Pointer C definitions for register reads, indexed
offsets, stack reads and recovery. Their existing exports supply those bodies;
linking their identifiers/types/effects in Clight remains M5 proof work, rather
than an assumed semantic bridge.

Historical/current native/host-adapter modes pass260 selector,51,520 read/frame
and4,060 handler-composition/frame cases each. The MOVBE check composes the
independently tested writer with an independent byte reversal, comparing
registers, arena bytes, facts and draw counts, including aliases and RSP
release. It is not an independent proof of the reused writer. Fixed ordinary
reads retain their existing difference from indexed tagged reads on released
stack aliases. Unaligned pointer slots are covered in the finite indexed cases. Four
exact-width guard windows, an indexed full-pointer window, a read-before-release fault and RSP recovery nonreturn are checked.
Native trap is SIGILL; the CompCert platform fixture exits77. Initial harness
logs used a wrong raw-ABI constant and a native/import trap mismatch; corrected
historical and current checks both pass, with original logs retained.

The existing context oracle additionally tests the full shared read through
19,200 context/frame cases per native/adapter mode. Its pointer imports still
interpret the full native pointers separately from host UAPI32 values; these
fixtures do not prove concrete context/view coherence. Eight mutations catch
width/arm truncation, dropped indexing, changed fixed/tagged selection,
pointer copy alignment/size, missing recovery and missing byte reversal.

`make clight` and the targeted Memory/Pointer/Context Lean build pass40 jobs.
Regeneration is deterministic189,714B; four root queries have only the usual
Lean axioms. Pointer export changes only printer-generated anonymous names.
Native allocated sections/relocations match historical four-header replay and
normal compilation: memory1680B/5relocs, stack2856B/8relocs, ordinary1448B/11,
contextXDP360B/TC760B/4. Fixtures were not loaded or timed, and whole-default
byte identity remains open.

Full inline export still exits2 at MOV-store width/displacement/value GNU
selectors. CPP2,442,636B is extraction-profile size only. M4/full handlers and
default coverage, actual Clight linking/platform/native-memory refinements,
all2,065 theorem migrations/recounts, M6 and whole-library checks remain open.
