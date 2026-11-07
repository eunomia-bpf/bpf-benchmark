# x86 register clearing, context loads and host pointer alignment

The canonical header includes three reviewed repairs: same decoded register
lane XOR uses its exact zero result before pointer/scalar storage conversion;
XDP context reads remain volatile and their full-width loaded value crosses
the existing compiler barrier (T handoff); host pointer loads use an aligned(1),
may_alias pointer typedef for native x86 unaligned accesses (V handoff).
Different lanes, including AL/AH, retain the existing operand/flag path.
There is no program-specific rendering, fuel, bound or branch assertion.

The unchanged actual OTel native unwinder previously compiled in12GiB, then
failed verifier admission on pointer XOR at proofPC33648, from native
xor edx,edx at0x5fd5. Its complete12GiB failed startup is recorded separately
in native-only-runtime/otel-native-12g.json and the associated raw archives.
No OTel native workload completed from that failure. With ONLY the XOR
repair in a private header, the exact captured generated C compiles successfully;
this is compilation evidence, not kernel acceptance or whole-app coverage.

94208 host CPU comparisons pass across seven physical XOR forms, incoming
arithmetic flags, pointer/scalar words, nine full-width tags and unchanged
other GPRs. Native-defined flag comparison mask is0x8c5; undefined native AF
is excluded and the simulator AF-preservation policy is checked separately.
Canonical CMOV host and route oracles pass484369 and26526735 cases under
GCC13 UBSan. Isolating the host alignment hunk leaves BPF preprocessed
declarations AND macro definitions byte-identical. The context hunk has
first-guard/full64-bit/order supporting evidence from T; this is not a whole
ISA, later-guard, or complete translation-validation certificate.

Reproduction commands, exact before/after headers, all three patch hunks,
XOR CPU source, compiler command/resource record, actual unwinder C/object,
canonical oracle logs and BPF token equivalence are in raw.tar.gz. Use the
archived Makefiles from their recorded Workspace paths; all source artifacts
are retained. Failed harness preparations (asm escaping, absent clang UBSan
runtime, incorrect width fixture units) are retained explicitly; final tests
use correctly asserted byte-width units and existing GCC UBSan. No native
program, generator, kernel, module or application workload changes here.
