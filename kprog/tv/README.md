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
The environment is lane V's canonical `Refinement.EntryEnvironment.Environment`.
`compiled_x86_entry` and `compiled_arm64_entry` connect those actual clang
instructions to one native state witness, with explicit stack/code biases and
argument-register/return-slot mappings. The kernel and each program's ABI
certificate must establish the witness; these theorems never assume a return
address at the current x86 stack pointer.
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
`blob<N>.binding` accepts a version-2, 96-byte `native_lab_binding` record followed by
the exact native bytes, relocation records and proof instructions. It checks
these against the current upload under the blob mutex, then advances the
generation. Entry is explicitly byte zero of an inline chunk; ABI version 1
uses the architecture's BPF register mapping and the declared callee-save
mask. Architecture, chunk offset/extent/count, program type, expected attach
type, raw load flags, interface, GPL status, attachment BTF/function, target
program and original source program ID are recorded. Sealing pins the source
and target programs; both the verifier callback and JIT emission compare exact
BTF, token and device objects as well as the serialized attributes. The source's
own BTF object and main function prototype are also carried into the stub and
checked against the pinned source. Mutation releases all pinned objects and
invalidates the generation. Both callbacks reject an unsealed snapshot,
subsequent mutation, changed context or a different ABI mask. Generation-zero remains the existing
explicitly unbound experiment. The shared loader seals its supplied proofs.

The C entry `native_loader_load_from_fd_with_manifest_path_btf_and_context`
accepts the existing BTF/attach arguments followed by a pointer to a 16-byte
`native_loader_source_load_context` before the result pointer. Its version is 1,
with the original raw `prog_flags`, signed `prog_token_fd`, and zero reserved
word. The token FD must come from the captured load. Legacy C entries supply
zero flags/no token; a source with different flags rejects instead of silently
changing its verifier context. C++ callers supply `FdLoadOptions.prog_flags`
and `prog_token_fd`, and the actual expected attach type. For a libbpf object,
copy `bpf_program__flags` and `bpf_program__expected_attach_type`. The original
FD supplies GPL/interface/BTF entry identity. Binding wire version 2, input-marker
ABI 2 and the unchanged bound-proof capability version 1 are separate contracts.

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
and reject a program-type mismatch before proof lowering. They also run an ordered
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
maps. A noninternal map declared with zero `max_entries` receives the original
application map's configured capacity before relocation and FD reuse. The binder
compares type, key/value sizes and declared nonzero capacity against that FD.
Unmatched writable declarations are disabled; referencing one fails.
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
The loader links native code before final proof preparation. The proof ELF's
`.native_lab.rodata` version-1 JSON binds each `.rodata.native.N` DATASEC and its
single complete BTF variable to an exact canonical native symbol and size.
Native-link's version-1 `--output-data-layout` table gives that symbol's final
blob offset and size; the loader checks the exact bytes at that extent.
Identical constants at different native addresses remain distinct objects.
Missing, duplicate, conflicting, malformed or unknown metadata rejects.
Relocation
metadata kind 8 records `offset=0` and
`target=map_id | (global_native_byte_offset << 32)`. The kernel pins that exact
single-entry ARRAY, requires `BPF_F_RDONLY_PROG` and a successful freeze,
compares every value byte against the sealed native group (across chunks),
rejects overlap with any JIT-patched relocation and checks that the proof
actually loads the same map value. This record patches no native instruction.
Both raw and manifest proof paths use it. Changed bytes, native address,
map identity and unfrozen maps reject. Native-derived data should have its own
`.rodata.native.N` sections when the object also declares the application's
original `.rodata` variables, so their DATASEC layouts remain distinct.
Raw-proof callers supply `FdLoadOptions.proof_object_path` for the same metadata;
the micro runner forwards its actual proof ELF, expected attach type and flags.
The link cache stores the exact native extent table alongside its blob and ABI.
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

Internal simulator maps bind by canonical BTF DATASEC section and exact layout,
independently of libbpf's object-name prefix. Both compiled-object and raw-proof
paths retain the original application FD; duplicate matching original map IDs
reject. Kernel regressions cover different object names for writable and
readonly data, wrong same-sized BTF variables, and ambiguous original identities.

`BPFPlatform.lean` handles verifier context conversion explicitly. A platform
instance classifies each instruction at its actual PC; a context rule binds the
original decoded instruction to the kernel-produced physical BPF expansion.
Missing context metadata rejects. The existing byte interpreter and
`BPFPath.evaluate` execute every physical operation and check every successor.
A successful expansion must reach its exact boundary or fault; it cannot return
early, erase a load, or force a successor. `expand_sound` proves actual physical
BPF execution with the same full registers, memory and ordered effects, with
only the local physical PC projected to the virtual instruction's successor.
Its axioms are `propext` and `Quot.sound`. Agreement of the captured conversions
and classifier with the bound kernel/type/attach context remains in the
explicit platform trusted base; it is not a second native ISA specification.

`make -C kprog/tv context-kernel-check context-negative-check` captures actual
clang and kernel bytes for all six XDP context fields, including DEVMAP's
required egress attach type. Lean checks 64-bit packet pointers despite the
virtual LDXW opcode, physical offsets and all ordered nested loads. Changed
pointer width, end-pointer offset, load ordering, and an erased nested access
fail the same semantic checks that the unchanged captured copy passes.
These platform fixtures do not certify the micro or application native blocks.

`ARM64Path.lean` fetches actual native bytes by the reference PC, decodes
with V's canonical AArch64 decoder and executes its full-state transition.
Its position witness checks each real successor and cannot force a branch or
continue after a fault. `evaluate_sound` proves an actual reference execution;
its only printed axioms are `propext` and `Quot.sound`.

The archived `simple-arm64-before-width-inputs.tar.gz` contains an actual
native/clang pair and its specialization dependencies from before the memory
width repair. To replay, extract it in this directory, then run
`make -C kprog/tv simple-arm64-counterexample` from the repository root.
The counterexample proves that the successful store block has four native
writes versus eight clang writes, despite equal final packet bytes. It also
proves both observed traces are real executions of the canonical semantics.
This is a block counterexample, not a whole-program entry certificate.
Concrete observations use `native_decide`, adding `Lean.ofReduceBool` to
their trusted base; the generic path/composition theorems do not.
`simple-arm64-artifacts` regenerates a fresh pair with the current producer;
it must not be run over the archived before-repair input when replaying this
counterexample.

`make -C kprog/tv simple-arm64-artifacts simple-arm64-negative-check`
checks the corrected clang/native success block. `SimpleStoreCertificate.lean`
quantifies over every packet pointer and complete input states/memory. It
proves both complete successful post-states, equal guest memory, all ordered
effects and exact exit PCs. Without any permission premise, it proves both
checked paths succeed as certificates and match memory, effects, faults and
corresponding fault/exit locations. The certificate prefix ends at a real
fault; it adds no executable guard. Scalar BPF stores reuse the canonical
reference memory update. These universal results print only `propext`,
`Classical.choice` and `Quot.sound`, without native reduction or solver axioms.
Six actual-byte negatives cover narrow/erased/address-mutated stores, native
width and successor changes, and the archived broken clang output. The whole
program still needs entry/context/private-spill and preceding-block proofs;
this result certifies its store block, not those additional obligations.

Source-map symbols bind by actual original LDDW instruction sites. A manifest
entry can declare `source_map_bindings:[{native_symbol,source_insn}]`; the
consumer checks instruction boundaries, map-object/value kind, continuation,
FD and original retained kernel map ID. Value aliases include the original
second-LDDW offset within the real map extent. Unnamed maps retain their
actual identity and layout. `source_map_fd_sites:[0]` allows an exact source
byte template to normalize only the declared LDDW's FD word to zero. All other
bytes, including kind and value offset, remain exact; unrelated templates
are skipped before interpreting source operands.

Compiled proofs can import strong incomplete-array externs through
`.native_lab.source_maps` version1 JSON objects with `native_symbol`,
`source_insn` and `proof_symbol`. The ELF entry bytes/extent and each declared
R_BPF_64_64 relocation are checked explicitly, and map FDs are pinned by the
original kernel ID. Value externs denote the map base; clang's actual
addend/arithmetic supplies the displacement. No map is allocated, guessed
from a name or initialized from a proof object. Other unresolved relocation
identities fail. Kernel binding recognizes exact constant pointer arithmetic,
including a register constant whose definition cannot be bypassed by a CFG
edge; it still rejects a different native value offset. This small derivation
checker belongs to the explicitly trusted kernel binding implementation.

The real captured BCC global-data probe, both unnamed-map paths, rejection
cases and earlier loader regressions pass in x86 KVM. Both architecture
libraries build, and both binding-kernel suites pass including the new exact
offset positive/negative. New source-map fixtures have not yet been executed
through the Arm userspace loader. Consume the updated loader **and**
native_lab module from the immutable source-map handoff; wire2 and the
existing paired kernel image remain compatible. Whole-program ISA TV remains
a separate obligation from these binding/runtime checks.

`SimpleGuardCertificate.lean` validates both actual native guard blocks and
their corresponding clang paths for arbitrary64-bit packet/end pointers,
including wrapping additions. It proves complete native and BPF post-states,
exact branch PCs, no memory/helper effects and real reference executions.
The native CCMP fallback is checked rather than replaced with a forced CFG
choice. Guard axioms are propext, Classical.choice, Lean.ofReduceBool and
Quot.sound; store and generic path results retain their previously listed
axioms. Ten actual native/clang mutations now reject in the same decoder
certificates, including wrong guard successors, bounds, condition and fallback.

`simple-context-kernel-check simple-platform-check` captures and binds the
complete clang/kernel program with its actual type6/attach37/flags0 context.
`SimplePlatform.raw_is_exact_clang` checks equality to the entire extracted
clang entry. For this captured x86 kernel the only changes are the two XDP
pointer loads: physical64-bit accesses at0/8 replace virtual32-bit loads
at0/4. This capture is explicit platform input; its kernel/specification
agreement remains trusted. Entry, private-spill and return composition,
and target CPU feature/profile binding, remain active implementation work
before a whole-program native-safety certificate can be claimed.

Exclusive-store proofs use `NATIVE_LAB_EXCLUSIVE_FAILURE(source_pc)` as a
private proof-only input: MOV64K dst0/src9/off5/imm=unsigned source byte PC.
Kinds1–4 retain ABI2. The verifier gives each dynamic visit a fresh scalar
0 or1; the BPF model indexes choices by source PC and visit ordinal. The
default environment rejects an unbound choice. Host simulators supply an
explicit hook, and values outside0/1 fail with a diagnostic. No helper or
constant-success implementation substitutes for this input.

The Arm linker’s version1 environment layout names the actual STXR/STLXR
source PC, final native offset, width and release bit. The loader checks all
fields against native bytes and every compiled marker; compiler clones get
separate descriptors. Binding relocation kind9 records the final native
instruction and source-PC/proof-index pair without patching code. The kernel
checks it against the final chunk’s actual sealed proof, including markers
whose native instruction belongs to another chunk. Both instantiation and
emission recheck the immutable group. Standalone markers reject and have no
JIT implementation; bound proof regions are restored before native emission.

`environment-check bpf-check` checks the host hook, actual clang encoding,
metadata/opcode/width/order/source-PC/continuation/alias rejections, full-state
preservation and fresh retry choices. The new Arm kernel passes the complete
binding suite, both unsafe choice-branch rejections, independent repeated
visits and cross-chunk matching. The x86 binding/loader regressions also pass;
Arm-only descriptors reject on x86. This input mechanism does not by itself
prove the production simulator’s conditional write, exclusive monitor,
alignment, atomicity or acquire/release correspondence. Those are checked
against the canonical exclusive semantics and actual compiled programs.
