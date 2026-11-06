# Native artifact translation validation

Lane T owns this directory. The required certificate is about clang's compiled
BPF instructions as instantiated into the verifier program, paired with the
exact linked native bytes. A source macro census, a hash, a successful compile,
a verifier acceptance, or a differential test does not supply that certificate.

`make -C kprog/tv check` checks `Composition.lean` using lane V's Lean toolchain.
It proves that block simulation composes across every finite execution prefix,
then combines this with exact artifact binding and explicit verifier soundness.
The native-to-proof simulation direction prevents an extra simulator check from
hiding a native path. The relation must preserve the full architectural state,
including the next PC, and the ordered memory and helper effects. Simulator
spills can be erased only after proving they are private. Helper results and
arguments remain observable.

This is a conditional composition theorem, not a per-program validation result.
There is currently no compiled-BPF execution semantics or byte-decoding,
whole-state native block semantics exported by `kprog/formal`. Its handler
and condition-table theorems cannot instantiate this certificate. The checker
must consume lane V's reference semantics when those interfaces exist; this
directory must not introduce a second native ISA semantics. No micro program
or application artifact is certified by `Composition.lean` alone.

The trusted base of an instantiated proof consists of:

- Kernel verifier soundness for the **instantiated** BPF program, including its
  helpers, context conversion, maps, verifier rewrites and execution environment.
- Lane V's reference ISA specification and its connection to the hardware,
  checked independently by lane F. ISA decoding, ABI entry conditions and the
  trace projection must either be proved or explicitly added to this base.
- Kernel binding and native emission: the accepted proof, bytes, entry, ABI,
  specialization metadata, relocations and chunk order describe the same
  immutable artifact through verification and JIT emission. Debugfs writers
  have kernel privilege. Generation counters must not wrap or be reused across
  module lifetimes while a verification/JIT operation remains in progress.
- Lean's kernel and the logical axioms printed by the check command. This file
  adds no axioms, `sorry`, unchecked certificates or solver-success assumptions.

Clang and the C/Python simulator generator can leave the semantic trusted base
only once a byte-level TV certificate exists for their actual output. Until
then their correctness remains an unresolved obligation, not a discharged O2
or O3. Binding is necessary but cannot establish translation correctness.
