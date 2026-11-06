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
`BPF.lean` provides byte-decoded BPF arithmetic, branches, wide immediates,
ordinary memory operations and platform-bound helper calls. Its registers,
memory and ordered events use lane V's canonical types. The PC is a signed
instruction index; an invalid negative index fails. Helper arguments come from
the actual argument registers, while identity, prototype arity, effects and
caller clobbers are explicit platform inputs. Instruction offsets, BTF selectors
and PC are available to that binding rather than silently discarded.
Atomic read-modify-write instructions model 32/64-bit ADD/OR/AND/XOR, FETCH,
exchange and compare/exchange. One indivisible atomic event contains the old
bytes; the complete resulting memory and returned registers contain the update.
Failed compare/exchange preserves both byte values and initialization state.

The private proof-input ABI is defined in
`kinsn/module/include/native_lab_input.h` (ABI 2, eight-byte MOV64K marker,
source nibble 9). Kinds 1/2/3 expose native body-entry SP, code base and saved
outer return address; kind 4 preserves the current R1 word while erasing
pointer provenance. These are explicit invocation inputs, with no guest memory
access or helper event. The verifier quantifies over all 64-bit scalar values,
requires initialized R1 for kind 4, checks the exact kind/version/destination,
and requires pointer-leak privilege and the x86/arm64 host JIT. Constant blinding
preserves the marker. Entry inputs are restricted to the main body. Both JITs
implement the same values for standalone proof execution, including the
physical CPU frame when the BPF stack is private. Bound native execution removes
the private proof instructions as part of the existing proof-region restoration.
The entry relation must instantiate the inputs with the same native invocation;
source/body stack and code offsets, rewritten register mappings and return
provenance still require that program's ABI certificate. An arena offset is
never an absolute native address.

`make -C kprog/tv input-negative-check` extracts the actual clang-compiled marker block
and proves its result for arbitrary 64-bit SP/code/return/argument values and
arbitrary memory, with unchanged memory and empty effects. The resulting
execution theorem uses `BPFPath.evaluate_sound`; it is an input-ABI component,
not a whole-program native certificate. Mutated stack/return selectors, numeric
source and input ABI each fail the semantic theorem; the unchanged ELF passes.
Kernel regressions check stable actual
entry values, 64-bit numeric identity, malformed markers, unreadable arguments,
unsafe branches that an erroneous MOV-immediate interpretation would prune,
input markers inside generation-bound native proofs, and forced constant
blinding. The private input
verifier/JIT implementation and its native invocation relation are part of the
explicit kernel ABI trusted base.

`BPFPath.evaluate` checks a finite instruction-position witness against every
actual successor, with no forced branch or PC update. `evaluate_sound` proves
that success gives a real execution prefix with exactly the same full BPF state
and ordered effects. It rejects continued execution after return or fault.
This finite witness is a certificate component; block composition imposes no
native execution fuel limit. `BPFChecks.lean` checks wire layout, arithmetic
boundaries, memory initialization/faults, helper arguments/clobbers and invalid
path witnesses.

The per-program native-to-proof block relation, its kernel context/helper
instantiation and architectural-state projection are still being implemented.
Lane V exports byte-decoded, whole-state CMOV transitions and
canonical memory/helper events in `KProgFormal.Reference`; the remaining
reference operations are under construction. The composition uses those
canonical event types. This directory must not introduce a second native ISA
semantics. No micro program or application artifact is certified by
`Composition.lean` alone.

`make -C kprog/tv cmov-negative-check` checks a first clang-output component.
The fixture compiles the production register CMOVE handler at widths 16/32/64
with arbitrary destination, source and flag inputs. `extract_blocks.py` reads
the actual ELF entry extents, rejects unresolved relocations, and emits raw
arrays plus kernel-checked decoding facts. `CmovCertificate.compiled_execution`
proves actual BPF execution returns V's canonical CMOV value, with no fault or
memory/helper events, for every input and both successors. Native instruction
bytes are decoded by the same canonical reference. Condition-mask,
successor-offset and source-register mutations all fail the semantic proof;
an unchanged copy passes through the same extraction/check path.

This fixture exposes a scalar return value. It does not expose every native
register/flag as an output or instantiate an application entry relation, so it
is a compiler-block component, not a whole-program TV certificate. Its
`bv_decide` proof prints `propext`, `Classical.choice`, `Quot.sound` and
`Lean.ofReduceBool`: this last dependency trusts Lean's native reduction used
for certificate checking, in addition to the Lean kernel. The ELF extractor
is trusted to select the supplied object's intended entry bytes; the saved
object and generated byte arrays make that boundary inspectable. No solver
success flag is accepted as a certificate.

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

The x86 guest also exercises the real shared loader's `FdLoadOptions` path and
public manifest C ABI, including short, three-chunk, helper and map entries.
It prepares a real clang BPF object, reuses the original map ID, uploads its
proof and seal, and runs native code returning 2. Both architectures reject
uninitialized stack, bad helper arguments and out-of-bounds map values, and
accept a 70,000-instruction proof restored to short native code. These are
binding regression fixtures, not simulator translation-validation certificates.

The group seal identifies byte zero and the ordered immutable upload. The TV
certificate must still establish source-entry correspondence, reference-ISA
ABI compatibility and specialization fidelity. The
application C loader entry point obtains the compiled simulator from paired
manifest fields `simulator_object` and `simulator_program` in the selected
`objects` entry. For example, add
`"simulator_object":"proof.bpf.o","simulator_program":"proof_entry"`
alongside the existing `program`, `native_object` and `symbol` fields. Paths
resolve relative to the manifest. Optional `source_btf_symbol` selects the exact
full source entry name independently of the native `symbol`. The loader uses
captured BTF function metadata or queries the original program FD, requires the
named function at instruction zero, and rejects conflicting captured/loaded
entry names. A truncated kernel name cannot satisfy this selector. Empty or
missing-BTF selectors fail; a different full name does not match. This resolves
real application entries sharing the same 15-byte name, type and bytecode size.
The explicit BPF entry must have the original program type. `bpf_object__prepare` performs real ELF/CO-RE relocations; referenced
maps reuse original-program identities with matching layouts, including internal
maps. Unmatched writable declarations are disabled; referencing one fails.
Internal maps also require the same BTF DATASEC section, byte extent and
ordered variable names, offsets and sizes. This is checked before
`bpf_map__reuse_fd` replaces the simulator's map metadata. Raw proof maps from
another loaded object receive the same DATASEC check before FD relinking.
The object keeps map FDs alive through the bound load. Supplying both raw proof
instructions and a manifest proof fails. Substituting original app BPF for the
simulator would not meet the translation-validation obligation.

Raw proof instructions from a separately loaded object also have their map FD
operands linked to original-program identities before sealing. Names and map
type/key/value/entry-count must match unambiguously; imported FDs are retained
through the bound load and shared across repeated references. A second object
with identical declarations cannot authorize a second map's state. On x86,
native chunks and their tails may have arbitrary byte lengths; only AArch64
requires word alignment.

An unmatched compiler readonly data map can represent immutable native data.
The loader links native code before final proof preparation, then matches the
actual frozen map value to a unique exact native-byte extent. Relocation
metadata kind 8 records `offset=0` and
`target=map_id | (global_native_byte_offset << 32)`. The kernel pins that exact
single-entry ARRAY, requires `BPF_F_RDONLY_PROG` and a successful freeze,
compares every value byte against the sealed native group (across chunks),
rejects overlap with any JIT-patched relocation and checks that the proof
actually loads the same map value. This record patches no native instruction.
Both raw and manifest proof paths use it. Changed bytes, native address,
map identity and unfrozen maps reject. Native-derived data should have its own
`.rodata.native` section when the object also declares the application's
original `.rodata` variables, so their DATASEC layouts remain distinct.
The TV relation must connect the recorded native address to the proof address
and its actual ordered reads; this binding check does not prove that relation.

Bound programs must contain exactly their ordered native group followed by
EXIT. The kernel checks this before proof expansion and again at JIT emission;
surrounding BPF spills, helpers or subprograms cannot share native scratch.
Stack reservation survives fastcall cleanup, and native proof loads require
successful JIT emission independently of the kernel's interpreter configuration.

Map literal relocation kinds 5/6 identify a map pointer/value by kernel map ID
and value offset (`target = id | offset << 32`), in a zero eight-byte literal.
Sealing pins those map objects until mutation/module exit. Before removing any
proof region, the kernel matches each relocation to a resolved proof map load,
including pointer/value kind and value offset; mere fd_array retention does not
qualify. Emission resolves the pointer from the program's retained kernel maps.
Helper targets must match proof helper prototypes or the kernel's operations
and generated lookup calls for the verifier-recorded map. This binds external
identities; per-block TV must additionally establish argument values, ordering,
accesses and control-flow correspondence.

Relocation kind 7 is an eight-byte helper-address literal for bounded indirect
dispatch. Its slot must be zero, and its target must equal an actual proof
helper's `get_func_proto(...)->func`. It does not admit internal map-generator
targets. Both architectures execute an indirect helper-pointer fixture and
reject a different valid helper address and a nonzero literal. Standard helper
text lifetime is the same premise used by ordinary verifier/JIT helper calls.

`native-proof-regions.patch` is applied idempotently by the existing host kernel
build recipes. Rebuild the kernel and module together: native-proof descriptors
now admit standard resolved helper calls and map FD/value loads, enforce
initialized stack independently of CAP_PERFMON, and reserve native stack through
metadata. A reservation never initializes verifier state. Proof counts use u32
and a generation-bound size query up to the kernel's million-instruction budget;
long EXIT redirections use JMP32 JA. Unresolved BPF subprogram/kfunc identities
are currently rejected; transporting their metadata and preserving their call
frames remains assigned implementation work.

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
  Native-proof regions force initialized-stack checking even with CAP_PERFMON;
  ordinary BPF and instruction-slice descriptors retain their existing policy.
  This requires the paired patched kernel and native module, not a stock image.
- Lane V's reference ISA specification and its connection to the hardware,
  checked independently by lane F. ISA decoding, ABI entry conditions and the
  trace projection must either be proved or explicitly added to this base.
- The byte-decoded BPF specification and its platform instantiation must agree
  with the instantiated kernel program, including relocated immediates,
  context accesses and helper effects. Path soundness is relative to this
  specification; it does not prove that kernel/specification agreement.
- Kernel binding and native emission: the accepted proof, bytes, entry, ABI,
  specialization metadata, relocations and chunk order describe the same
  immutable artifact through verification and JIT emission. Debugfs writers
  have kernel privilege. Generation counters must not wrap or be reused across
  module lifetimes while a verification/JIT operation remains in progress.
- Lean's kernel and the logical axioms printed by the check command. This file
  adds no axioms, `sorry`, unchecked certificates or solver-success assumptions.
  The BPF path soundness theorem prints `propext` and `Quot.sound`; composition
  prints `propext`. Neither theorem supplies a native block certificate.

Clang and the C/Python simulator generator can leave the semantic trusted base
only once a byte-level TV certificate exists for their actual output. Until
then their correctness remains an unresolved obligation, not a discharged O2
or O3. Binding is necessary but cannot establish translation correctness.
