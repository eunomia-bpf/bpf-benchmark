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

The native-lab modules now require a seal for nonzero-generation calls.
`blob<N>.binding` accepts a 64-byte `native_lab_binding` record followed by
the exact native bytes, relocation records and proof instructions. It checks
these against the current upload under the blob mutex, then advances the
generation. Entry is explicitly byte zero of an inline chunk; ABI version 1
uses the architecture's BPF register mapping and the declared callee-save
mask. Architecture, chunk offset/extent/count, program type and expected attach
type are recorded. Both instantiation and JIT reject an unsealed snapshot,
subsequent mutation or a different ABI mask; JIT also checks the loading
program's type and expected attach type. Generation-zero remains the existing
explicitly unbound experiment. The shared loader seals its supplied proofs.

Sealing the final chunk captures every chunk's generation and checks contiguous
native extents and matching ABI/context metadata. Both callbacks validate that
whole-program snapshot. The JIT checks its restored BPF stream contains exactly
one consecutive group of sidecar/call pairs in order, with the same call
identity and no BPF edge into a proper suffix. Omitting, duplicating, reordering
or mutating a peer chunk cannot reuse the accepted final proof.

Checks, all from the repository root:

```sh
taskset -c 8-23 make -C kprog/tv check
taskset -c 8-23 make -C kprog/tv kernel-check
taskset -c 8-23 make -C kprog/tv kernel-check-arm64
```

The kernel tests load the real modules, reject entry/ABI/metadata and byte
mismatches, run an exact bound artifact returning 2, reject post-seal mutation,
and reject a program-type mismatch during JIT. They also run an ordered
two-chunk program and reject incomplete, reordered, missing and duplicated
chunks, plus a peer mutation. x86 uses KVM; AArch64 uses
full-system QEMU with a static test as PID 1 in a minimal initramfs. Their
module builds are isolated under this directory and do not replace shared
runtime artifacts. The host test checks relocation-byte mismatches, all wire
offsets, generation boundaries and the shared production validation functions
with ASan/UBSan. Results are in `../results/kprog_tv_20261106/`.

The x86 guest also exercises the real shared loader's `FdLoadOptions` path.
It native-links one short and one long test entry, uploads the proof and seal,
and runs the resulting one-chunk and three-chunk native programs. These are
binding regression fixtures, not simulator translation-validation certificates.

The group seal identifies byte zero and the ordered immutable upload. The TV
certificate must still establish source-entry correspondence, reference-ISA
ABI compatibility and specialization fidelity. The
application C loader entry point currently supplies no simulator proof, and
the kernel proof-region interface forbids helper calls and pseudo map loads.
Consequently neither application binding nor helper/map program validation is
completed by this change. Substituting the original application's BPF for
the simulator proof would not meet the translation-validation obligation.

`make -C kprog/tv inventory` records both architectures' 29 configured micro
programs and every entry in the C/A application generation inventories. Each
record retains ELF machine, executable-section and file hashes, function
offsets, relocation counts, compiler/load-record provenance and missing inputs.
`programs.jsonl.gz` retains all phase variants losslessly. Every record states
`not_validated`: neither these pre-link ELF inputs nor a standalone BPF load
establishes the identity of the linked native and instantiated proof bytes.
This command inventories evidence; it does not run translation validation.

The trusted base of an instantiated proof consists of:

- Kernel verifier soundness for the **instantiated** BPF program, including its
  helpers, context conversion, maps, verifier rewrites and execution environment.
  This must name the actual privilege-dependent policy: this kernel permits
  uninitialized stack reads with CAP_PERFMON. Acceptance cannot establish
  stack-initialization safety or any property stronger than that policy.
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
