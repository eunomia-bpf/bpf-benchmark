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
explicitly unbound experiment. The registered service's loader seals its freshly generated proofs.

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
offset positive/negative. A’s actual Arm userspace source-map positive and erased-offset negative
also pass; the full29-micro QEMU run is recorded in the Arm lane’s
[source-map result](../../corpus/results/kprog_arm64_app_coverage_20261106/source-map-result/README.md). Consume the updated loader **and**
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

TRACING programs use the kernel’s raw-tracepoint variants of perf output,
stack ID and stack capture, including fentry programs. The loader now selects
those exact symbols, matching `tracing_prog_func_proto`’s delegation to
`raw_tp_prog_func_proto`. The regression loads each actual clang artifact,
binds the original maps/context, attaches the native fentry replacement and
triggers its real target; all three native programs execute. Both libraries
build and the complete x86 binding/loader regression passes. No kernel helper
identity comparison is relaxed.

The `context-v2-exclusive-choice` handoff pairs the new Arm Image/EFI kernel,
all stock modules, all11 kinsn modules and both loader libraries. Every kinsn
module inserts together before the complete binding regression runs in QEMU.
Both unsafe exclusive-choice branches and retry/chunk/site negatives reject.
The actual Arm capture of the complete simple proof also matches the entire
checked x86 physical byte stream and type6/attach37/flags0; this supplies a real
Arm platform input for the entry proof. `kernel-check-arm64-all` and
`simple-context-kernel-check-arm64` reproduce these checks. The original
six-field x86 capture and all four context mutations still pass after the
capture entry point was factored for the small Arm guest.

`exclusive-runtime-arm64` builds the matching EFI kernel, stock modules and
kinsn modules in T’s private output directories. The final core archive and
full build log are retained with the result. Exported kernel objects and the
duplicate installed stock-module tree were removed after the immutable full
handoff was complete; final images, vmlinux/BTF, symvers, generated headers,
tools and the earlier runtime pairs remain. A later kernel rebuild after
that cleanup requires recompilation. These runtime checks and captures do not
substitute for the continuing whole-program translation-validation proof.

`simple-entry-negative-check` validates the actual simple-program entry
instruction and the entire seven-instruction compiled entry prefix. The
native theorem retains every architectural field and both possible read
faults. The compiled theorem quantifies over every BPF environment and
complete input state; it preserves all registers except the actual three
outputs, checks the real two spills and reloads, and records all six ordered
physical memory effects. Reloaded values follow from the stores.

`PrivateSpills.lean` proves the two eight-byte slots preserve every guest
byte, initialization bit, permission and read outside their16-byte private
frame, including wraparound. The projection erases only complete reads/writes
to those exact slots; every erased byte is proved private. Atomic, helper,
exclusive/order and fault effects remain. `entry_translation` composes real
native/BPF executions with complete resulting states, equal guest memory and
exactly equal projected guest reads, and includes the private-effect proof.

Its explicit premises describe a mapped XDP context, the kernel’s private BPF
frame and their disjointness, plus the same entry memory. They insert no
executable guard or initialization. The platform/ABI relation must establish
them. The native entry profile is explicitly Cortex-A72’s two-access LDP;
CPU-profile metadata binding remains part of the continuing composition work.
Eight mutations of the actual extracted streams reject, covering native pair
width/register/access and physical pointer width/end offset/spill slot/reload
register/access. The unchanged streams pass. Entry/read/fault slice axioms
are propext/Quot.sound; the composed spill results additionally use
Classical.choice/Lean.ofReduceBool. No passing result contains sorryAx.
This entry-prefix certificate is now available for composition with the
existing guard/store certificates and the real return path.

`simple-blocks-check` now proves the complete first native basic block
(LDP/MOV/CMP/BHI) against all eight actual physical proof instructions.
`SimpleBlocks.first_block` composes actual executions, complete resulting
states, guest-memory agreement, ordered projected reads, both real branch
successors and a proof that every erased effect touches only private bytes.
The body transport lemma checks decoded instructions against both complete
captured streams; it does not introduce another instruction semantics.
The real kernel-mode linker output is exactly the complete84-byte native
stream in the certificate, with ABI mask0 and no relocation/environment sites.
All eight entry mutations still reject. The composed theorem uses propext,
Classical.choice, Lean.ofReduceBool and Quot.sound, without sorryAx.

This result covers BB0 of the physical-context capture. Whole-program
validation is continuing with the actual generation-bound expanded proof:
the loader redirects clang EXITs, the module appends ABI clobbers, and the
verifier interprets virtual context accesses before physical conversion.
Those exact expanded bytes and platform rules must be included in the final
certificate; the standalone physical capture is not that expanded artifact.

Both native modules now offer opt-in `capture_checked=1`. After each
successful bound load, `checked_proof` under that module's debugfs directory
contains the exact expanded virtual program at `validate_native_proof`, before
restoration/context conversion. Read it before the next upload: every blob,
proof, relocation or binding mutation invalidates new opens. Each already-open
FD retains its own immutable copy. Capture is disabled by default; enabled
capture failures propagate. This read-only interface requires CAP_SYS_ADMIN.

`native_lab_checked_wire.h` defines version1:120-byte header (six32-bit
fields followed by binding96), program instructions,16-byte region records,
40-byte map records and16-byte helper records. It preserves region payloads,
source/context identity, actual map IDs/layouts/resolved pointers, and helper
IDs/functions. A callback snapshot alone does not establish load acceptance.
The per-program record must also retain the successful load result and exact
native output/metadata. There is one latest snapshot, rather than a queue.

`simple-checked-kernel-check-arm64` exercises the production loader against
the actual clang/native objects and captures its complete29-instruction
expanded proof. Both original and native programs return2, perform the exact
eight-byte packet update and preserve120 other bytes. The capture includes
the actual EXIT-to-JA rewrite and final stub EXIT; virtual context offsets
remain0/4. `simple-checked-artifact-check` preserves every snapshot byte and
checks its27-instruction clang prefix, redirected exit and stub exit in Lean.
`checked-artifact-negative-check` rejects14 corrupted records and four actual
instruction mutations. The prefix equality uses Lean.ofReduceBool explicitly.
Whole-program context/state/effect simulation remains active; these byte
identity checks do not replace that theorem. Both complete x86/Arm binding
regressions also verify resolved map/helper facts, invalidation and stable FDs.
The inputs archive includes the exact small guest runtime used by this test.

`BPFREJIT_NATIVE_LOADER_TV_DIR=<directory>` optionally exports each successful
bound load while the existing upload lock still protects its snapshot. Enable
`capture_checked=1` on the paired native-lab module. Each source-ID/native-ID
subdirectory contains the exact expanded verifier snapshot, linked native bytes
and relocations, linked proof input, actual JIT bytes/addresses/function lengths,
and restored stub. `load.json` is written last; a failed export propagates and
closes the candidate program. An incomplete directory carries no success claim.
The loader checks generation, entry/ABI/chunk layout and the complete serialized
load context before exporting. It never substitutes a later program's snapshot.

`capture-loader-build` builds both libraries; `checked-kernel-check-x86`
exercises the export on the existing real loader/map/helper/multichunk regression.
`simple-checked-kernel-check-arm64` exercises two distinct successful records,
stable history after another upload, and a real output-path IO failure. Its log
retains all exported bytes as `TV_EXPORT` records. Reconstruct them with
`python3 kprog/tv/extract_checked.py <guest-log> <simple-output> --exports <directory>`.
The resulting inventory explicitly marks translation validation `not_validated`;
these are complete inputs to TV, rather than TV certificates.

`checked-platform-check` proves that all29 actual expanded instruction positions
agree with the captured physical context conversion for arbitrary complete BPF
states and memory, including read/write faults. It includes the loader's real
JA-to-final-EXIT rewrite. `accepted_step` derives the PC extent from successful
byte decoding; `execution_transport` lifts every actual physical execution to
that exact virtual verifier program with identical complete states and ordered
events. There is no caller-supplied safety premise or forced successor in this
transport. Its axioms are propext/Quot.sound; byte-prefix identity separately
uses Lean.ofReduceBool. Native-to-proof block composition, invocation ABI
premises and CPU-profile binding remain separate obligations.

Map lookup inlining and the proof boundary (2026-11-07)
-----------------------------------------------------

The checked virtual B may retain `BPF_FUNC_map_lookup_elem`. When final native P
inlines that operation, its TV comparison must model the actual lowered memory
accesses, branches and remaining calls. Retaining an opaque helper event in the
comparison would change the ordered trace: `BPF.execute` currently appends
`Event.helper` after the platform helper effects, while an inline array lookup
contains no helper call. Only proved-private simulator effects may be erased;
map implementation memory and LRU state are shared objects.

A compatible bridge keeps the verifier's checked call and proves its platform
expansion against the exact bound kernel's `map->ops->map_gen_lookup` output,
then compares that expanded behavior with final native bytes using V's canonical
ISA. Explicit matching operations in B are another representation if the
verifier accepts them. Neither representation may assume the desired result or
hide an extra native access. The existing `BPFPlatform` expansion theorem covers
context-memory conversion; its step currently rejects expansion of a call, so
it does not already supply this helper-lowering bridge.

The concrete distinctions matter: array lookup reads the key and performs the
bounds/null choice; per-CPU array adds the slot-pointer and CPU-base operations;
hash lookup retains `__htab_map_lookup_elem` followed by null/offset handling;
LRU hash additionally reads and conditionally writes its reference byte. Check
the actual memory order, addresses, sizes, faults, remaining helper identities,
arguments/effects/clobbers, control successors and complete native state. Bind
the exact map identity, generated expansion and every layout/specialization or
per-CPU/platform input it consumes to the accepted and emitted artifact. A
shared semantic map result alone does not establish those facts.

This affects existing code: `configure_lookup_site_for_shape` in
[the loader](../libnativeloader/src/native_loader.cpp) and
`build_x86_array_lookup` / `build_x86_lookup_call_postprocess` in
[the linker](../x86/native_lab/native_link/src/x86.rs) already implement candidate
lowerings for several map kinds. Their use in a particular run requires the
actual final linked image and link plan; source presence and pre-link call
counts do not establish it. The kernel's [`do_misc_fixups`](../../vendor/linux-framework/kernel/bpf/verifier.c)
uses the real map generator after checking the virtual helper operation;
[`array_map_gen_lookup`](../../vendor/linux-framework/kernel/bpf/arraymap.c) and
[`htab_map_gen_lookup`](../../vendor/linux-framework/kernel/bpf/hashtab.c) define
the corresponding concrete expansions. Their correct realization of the
verifier's map contract belongs to the assumed kernel/verifier platform
soundness until separately proved; native lowering remains a TV obligation.

`native_lab_map_helper_target` in
[the binding code](../../kinsn/module/include/native_lab_group.h) checks a
resolved target against the map operations/generator, not equivalence of the
whole inline sequence. Current capture records the pre-fixup checked program,
map facts and original helper prototype target, without the generated sequence
or all its layout/CPU inputs. These records alone do not discharge this bridge.
A direct `rel32` call to the same resolved helper still represents an actual
helper call and is a separate transformation. This analysis changes no runtime
default or measurement admission rule; unbound performance work continues.

`checked-first-block-check` now composes the complete native BB0 with the exact
accepted expanded virtual B. `SimpleCheckedBlocks.first_block` retains full
native/proof post-states, both actual successors, guest-memory agreement,
ordered guest read equality and privacy of every erased spill effect. The
mapped-context/private-frame entry conditions are the existing explicit ABI
premises; the proof inserts no executable guard. Ordinary prefix instructions
are compared directly, and only a real wide immediate requires equality of a
following continuation. The theorem's axioms are
propext/Classical.choice/Lean.ofReduceBool/Quot.sound, without sorryAx.
Second-block/store/return and invocation/CPU-profile composition remain active
before this becomes a whole-program TV certificate.

For a direct map-type call, B can keep the checked map-lookup operation while
its platform helper contract resolves to the exact pinned map's
`ops->map_lookup_elem` (or the generated internal call). Unlike the fully
inlined array case, the comparison retains an actual call event for that
selected callee. Its contract must relate the same map/key arguments, result,
null case, memory effects and ABI clobbers under the same kernel invocation and
map lifetime/RCU conditions. This is a certified helper specialization, not
permission to equate arbitrary function addresses with Linux helper ID1.
The wrapper in `kernel/bpf/helpers.c` delegates to the map operation and checks
the RCU context; `do_misc_fixups` provides the kernel's concrete specialization.
The existing target check establishes eligibility/identity, while the composed
semantic and binding relation must establish the rest. In both cases the proof
models the final emitted P, including any surviving internal hash call and
post-call lookup operations.

`SimpleCheckedBlocks.second_block` now matches the second native guard block,
including CCMP's real fallback, with the accepted expanded B for all wrapping
64-bit pointer/end values. Both native successors and their actual BPF
successors remain explicit, with complete post-states and empty effect traces.
`return_executions` checks the real linked `X7 <- X0` trampoline ending at byte84
against the actual BPF JA27/EXIT28 sequence ending halted at PC29, for every
64-bit return value, retaining all other state and unchanged memory. The second
block's axioms retain the existing bitvector reduction trust; the return theorem
uses only propext/Quot.sound. These are composing components, not yet a complete
invocation/whole-program certificate. The existing
`SimpleStoreCertificate.including_faults` already covers each first store fault
without store-permission premises; its connection to this expanded program is
next, along with rejection-path and complete state-relation composition.

`store_including_faults` now transports the existing store/fault certificate to
the actual expanded B. For arbitrary memory and wrapping pointers it matches
complete resulting memory, ordered writes and fault, exact fault identity and
corresponding native/proof PC, without a writable-memory premise. Its finite
witness stops at the real first fault or block successor; those predicates add
no executable checks. The reused certificate accepts an explicit BPF environment
with the original default preserved. Full architectural/block-edge and private
memory composition remains required beyond this store observation theorem.

`first_rejection` composes the first complete invocation path: when the real
first native comparison rejects, native entry/guard/reject/return execution
matches entry/spills/guard/JA/EXIT in the actual expanded B. Both complete final
states, the guest-memory relation and exact projected ordered context reads are
retained. The return value is zero and only proved-private spill effects are
erased. Its hypotheses are the existing explicit mapped-context/frame entry
relation and the real branch outcome, with no added executable test. This path
certificate does not yet cover the second-guard rejection or store paths.

`second_rejection` now covers the other complete rejected invocation path,
starting at the original native/BPF entries, traversing the real first and
second guards, then native rejection/trampoline and expanded JA/EXIT. The
native/proof block-edge equalities preserve all fields; no new entry state is
substituted at the second block. Complete final states, private-frame guest
memory agreement and the exact ordered context reads are retained. Together
with `first_rejection`, both guard-rejected paths are composed; store/fault and
accepted-return paths still require the same whole-invocation relation.

`store_with_spills` now runs the actual store/fault block on native memory and
the proof's real spilled memory, retaining complete architectural state shapes,
ordered events, fault identity and corresponding PC. Canonical writes preserve
`AgreesOutside` without replacing either memory; all short-write/fault events
survive projection. The older equal-memory observation is derived as an Eq
instance of this transition relation. The full existing dependency check passes
without sorryAx; exact inputs/logs are under results/kprog_tv_20261107. Original
entry-to-store/return and invocation/profile binding composition remain active.

`passed_guards_store` now starts at the original entries, traverses both passed
guards and the real store sequence through success or first fault, preserving
full state-edge identities and both actual memories. `passed_guards_complete`
adds the actual native/BPF returns exactly when the store execution has no
fault; otherwise both fault witnesses and full states remain at the real first
fault. Alongside both rejection theorems, all guard outcomes are covered under
the existing entry premises. Exact inputs and successful Lean output are in
results/kprog_tv_20261107/checked-entry-stores-return-*. Whole-invocation safety,
CPU-profile and emitted-artifact binding remain to compose before declaring a
whole-program certificate.

`matched_invocation` now exhausts simple's guard outcomes and supplies exact
native/proof traces and closed native terminal states. Using determinism,
`every_native_prefix_checked` proves that EVERY finite native execution prefix
has only events checked in the actual expanded B, under explicit verifier and
platform soundness. `bound_native_prefix_checked` adds verifier acceptance,
admitted proof entry and equality of the entire executed/validated Artifact;
the executed native bytes and entry are used directly. Full state and private
memory proofs above provide the concrete TV, rather than assuming TV as an
unproved premise. The generic prefix theorem uses only propext; concrete
axioms retain the existing reduction oracle and have no sorryAx.

Remaining real-world trust/obligations are verifier/platform soundness, the
canonical ISA's CPU fidelity and kernel/loader binding of actual invocation,
entry/ABI and specialization inputs. The explicit split-pair CPU profile and
mapped-context/private-frame premises must be established for the real load.
These concrete conditional safety theorems do not yet claim that bridge, other
programs' certificates or the producer-independent trusted loading component.
Exact evidence is in results/kprog_tv_20261107/checked-simple-prefix-* and
checked-simple-bound-prefix-final.log.

ARM opt-in capture now exports emitted.bin: final RX entry addresses reported
by the real JIT callback, with each bound generation/ABI/extent. The loader
matches those addresses to the actual JIT function ranges and unrelocated
native bytes, and preserves distinct successful per-load records. The export
parser's exact-byte certificate currently requires an unrelocated artifact;
final-patch validation for relocated programs is active work. Ordinary loads
and generation-zero timing keep their existing behavior.

`make simple-emitted-check` regenerates each actual simple load's Lean Artifact,
checks emitted/native/checked-B identity and its actual RX byte interval, then
instantiates concrete accepted/bound prefix safety. `make
simple-emitted-negative-check` rejects metadata-consistent changed native/JIT
code or changed checked B at the corresponding Lean identity theorem. Both
actual GEN4/GEN8 instances pass without sorryAx, as do36 site/JIT corruptions,
old metadata/instruction/multichunk negatives and legacy captures. Evidence and
remaining invocation/CPU-profile/native-PC-relocation obligations are recorded
under results/kprog_tv_20261107/emitted-*. This is conditional per-load safety;
the real invocation bridge and producer-independent loading remain to complete.

`SimplePCRelocation` now proves full-state/event PC translation for all21 actual
simple native instructions, including both pair profiles and faults, then lifts
it to canonical byte fetching at any RX base (`step_at`). Only PC changes; all
other architectural fields, memory and ordered effects remain identical.
`make simple-pc-relocation-check` checks these theorems with their dependencies;
both use only propext/Quot.sound. Whole-execution transport to the captured RX
entry and the actual initial-state/profile bridge remain to compose.

Native-link's x86 inline ABI mask now comes from actual native writes over all
reachable symbols, after entry stripping/renaming, before tail-call lowering.
This fixes bare RBX/R13/R14/R15 writes that had no stripped save prologue.
Subregisters, implicit/conditional writes and raw synthetic instruction chunks
are included; a .proof.o declaring too few save bits is rejected before loading.
The existing binding carries the resulting mask through verifier and JIT use.
`x86-native-abi-check` exercises real ELF producer/kernel metadata; the private
KVM regression inspects actual JIT save/restore before safe positive execution.
79 Rust tests,15 ELF cases/12 metadata negatives and6 KVM controls pass; evidence
is results/kprog_tv_20261107/x86-abi-*. This increment covers the existing four-bit
preservation ABI; reserved RBP/R12/frame and whole-program TV remain separate.

`SimpleExecutionRelocation` now proves successor-PC closure and complete
canonical execution transport to any RX base, with unchanged memory/events
and full non-PC state, including faults. Its `every_RX_prefix_checked` covers
every finite native prefix at that base. Both captured SimpleEmitted records
instantiate `accepted_RX_prefix_checked` at their actual callback-reported RX
addresses, preserving acceptance/admitted-entry/full-Artifact binding premises.
The transport invariants use only propext/Quot.sound; concrete safety retains the
existing reduction oracle with no sorryAx. Exact positive/negative/source inputs
are in results/kprog_tv_20261107/actual-rx-prefix-*. Initial invocation/CPU-profile
obligations remain; actual-PC relocation is no longer an assumed bridge.


The actual-entry `simple` invocation and host ABI
----------------------------------------------

`SimpleInvocationABI` checks all 21 decoded native instructions against V's
canonical step. It proves that every actual RX execution prefix preserves SP,
all 32 SIMD registers, and x12..x30, including faults and conditional paths.
The instruction and execution/ABI proofs use only `propext` and `Quot.sound`.
This establishes this body's zero callee-save mask independently of a producer
annotation or compiler prologue pattern.

`EntryState` states the actual entry requirements explicitly: PC is the
callback-reported RX entry, x0 contains the kernel context pointer, and the
selected Cortex-A72 profile uses split pair accesses. `entry_is_model` proves
that the complete actual state equals the state used by the TV invocation;
it changes no register, memory, flag, profile or environmental input. It does
not infer these requirements by overwriting an unrelated actual state.
`actual_entry_prefix_checked` then proves both checked effects and ABI
preservation for every execution from that actual state.

Each captured GEN4/GEN8 module additionally instantiates
`accepted_actual_entry_prefix_checked` with its exact native/checked-B bytes,
entry RX address and full Artifact identity. Verifier acceptance and its
soundness for the admitted proof entry remain explicit. `EntryConditions`
records equal initial architectural memory, the two valid kernel context
reads, the private proof frame's permissions and its separation from context.
The paired kernel/JIT is trusted to supply this entry/ABI relation and to emit
and execute the sealed artifact. The Cortex-A72/no-LSE2 hardware-to-reference
profile is explicit; the current capture recipe selects `-cpu cortex-a72`.
There is no theorem that an arbitrary CPU or kernel provides these guarantees.
Kernel-side CPU-profile metadata enforcement remains active binding work.

For this specific artifact the complete native-to-checked-B execution argument
now comes from byte-level TV, including guards, actual private spills, ordered
memory/fault effects, return, actual RX fetch and host ABI preservation. The
remaining trusted components are verifier/platform soundness, the canonical
ISA/hardware connection with the stated profile and the kernel binding/entry
implementation, plus Lean and the printed logical axioms. Clang and the native
specializer do not supply the semantic correspondence as an assumption for
this artifact. This result does not certify other micro/application artifacts,
relocated native patches or the producer-independent loading boundary still
being implemented.


The next micro: actual `simple_packet` guard certificate
------------------------------------------------------

The same capture harness accepts an explicit native entry symbol and compares
the bound native extent with the actual exported native bytes. Its packet/return
checks remain specific to the simple family. The default `simple` fixture keeps
its existing paths; another artifact uses separate capture directories:

```
make -C kprog/tv simple-checked-kernel-check-arm64 \
  CAPTURE_ARM64_PROGRAM=simple_packet \
  CAPTURE_ARM64_ARTIFACTS=build/simple-packet-arm64 \
  CAPTURE_ARM64_OUTPUT=build-arm64/simple-packet
make -C kprog/tv simple-packet-guard-check
```

`extract_simple_packet.py` reuses the ELF entry extractor and compares both
actual loader captures with the exact native entry and clang proof input.
It emits the full 68 native bytes, 200 clang BPF bytes and 208 checked BPF bytes;
Lean checks the actual redirected exit and unchanged prefix. The old staged
proof split native stores into byte writes. Recompilation with the current
production header retains the actual 4/1/2/1-byte stores. No native instruction
or runtime guard is changed by this capture work.

`PacketGuardCertificate` proves full native and actual checked-B states for
both guard outcomes, with no memory/helper effects, and proves corresponding
native/BPF successors. It uses V's existing arithmetic/conditional semantics
and the earlier proved comparison lemmas. The explicit sequence is the actual
five native instructions after LDP and the one/four checked-B instructions
after the real compiler spills; native flags and all untouched fields remain
in the post-state. Entry/spill composition, all store faults, return, RX/ABI
transport and the complete accepted invocation still need to be composed for
this new program. Its successful runtime and guard proof alone do not certify
the whole program.


`simple_packet` entry through both guard successors
-------------------------------------------------

`make -C kprog/tv simple-packet-entry-check` additionally composes the actual
entry LDP, the seven-instruction compiler prefix and the whole guard. It
proves complete native and verifier-facing checked-B executions, ordered guest
reads, the private memory relation and corresponding successors (32/11 for
stores,24/24 for rejection). Only the two proved private8-byte compiler spill
regions can be projected out; the proof retains every native guest event.
The `SimpleBlocks.EntryConditions` mapped-context/private-frame premises remain
explicit. The whole accepted invocation, store faults, return and ABI/RX prefix
composition are subsequent obligations for this program.

`PacketEntryCertificate` reuses the existing canonical LDP and exact physical
prefix/private-spill proofs. `PacketCheckedPlatform` transports every successful
physical step, including faults and returns, to the actual expanded virtual B.
Its two XDP pointer-load conversions reuse the same already checked conversion
rules for the bound XDP type/attach/flags. Generic program-congruence theorems
in BPFPlatform compare the same byte-decoded BPF instruction and explicitly
require the continuation bytes when it is LDDW. No native or BPF ISA is replaced.
Kernel/platform agreement with these context conversions remains in the
previously stated verifier/platform trusted base.

`make -C kprog/tv simple-packet-entry-negative-check` changes an LDP destination,
a compiler spill address, and a context offset. BPF mutations change both the
compiled input and expanded checked arrays consistently. Each is rejected by
its semantic entry/platform theorem. Every affected module is rebuilt in
order for each mutation; a dependent compiled against an earlier definition
is never reused. The successful original proof is checked by the positive
entry command. Results are packet-entry-* and packet-guard-full.log.


The packet certificate also proves the real native x7<-x0 return trampoline
and actual expanded-B jump/EXIT for every 64-bit return value. Under either
failed guard condition, `guard_rejection` composes the original entry, all
compiler spills/reads, guard, native zero return and both real exits, retaining
the complete post-states and justified trace projection. Native PC68 is the
end of this inline blob; the surrounding kernel/JIT ABI remains trusted.
`rejected_native_prefix_checked` uses this complete deterministic invocation
to prove every event of ANY native prefix on a rejected guard path was checked
for the same expanded B, under explicit verifier/platform soundness. The store
path, actual RX transport, host ABI and full accepted artifact binding still
need to be composed for simple_packet.


The actual packet store block and every first fault
-------------------------------------------------

`make -C kprog/tv simple-packet-store-check` proves the whole actual store block
using `PacketStoreTransport`. All eight byte-decoded native steps and thirteen
actual physical BPF steps preserve complete states, effects and fault metadata
under the checked PC correspondence. The final native branch has its real
four-byte displacement; source Simple's corresponding branch has eight bytes.
The generic execution-transport lemmas in ARM64Path/BPFPath lift successful
source witnesses through these proved actual target steps, without selecting
or forcing a target PC or adding an executable permission/termination check.

The complete store theorem reuses SimpleStoreCertificate's canonical/BPF
certificate on two related memories with equal write permissions. It retains
all architectural fields, all earlier 4/1/2/1-byte writes, the exact first fault,
corresponding successor/fault PCs and the memory relation. Faults occur at a
proved actual store position; repeating the native fault state adds only its
already observed fault event. No guest effect is erased by the PC mapping.
The two compiler-spill memories remain distinct.

The semantic negative command now additionally rejects native store width,
BPF store width and BPF address changes. Both BPF arrays change together, and
all affected modules are rebuilt against each changed definition. The full
original-entry/positive-store/return composition, RX/ABI transport and accepted
artifact theorem remain active for this program.


All packet invocation paths at the relative entry
------------------------------------------------

`make -C kprog/tv simple-packet-invocation-check` composes original entry,
private spills, both guard outcomes, all store/fault paths and actual returns.
`PacketInvocation.matched_invocation` gives complete native and checked-B
executions with the private-memory relation, exact ordered guest projection
and a closed native return/fault end. The real compiled frame crosses every
block edge; it is never replaced by native memory.
`every_native_prefix_checked` then checks EVERY native execution prefix under
explicit verifier/platform soundness for this same B. The certificate itself,
rather than an assumed translation-validation premise, supplies the complete
matching executions and closure.

`bound_native_prefix_checked` composes that result with explicit acceptance,
admitted proof entry and exact full Artifact equality, including code, B,
entry, supported ABI and specialization metadata. This theorem uses relative
native PC0. Transport to the two captured actual RX addresses, host ABI
preservation and per-load accepted-entry instantiation are the next steps.
The existing explicit kernel entry and ISA/hardware/profile trusted contracts
remain required; no runtime CPU-profile enforcement is inferred.


Packet execution at the actual RX entry and host ABI
--------------------------------------------------

`make -C kprog/tv simple-packet-emitted-check` composes the packet invocation
certificate with its actual byte fetch at any RX base. PacketPCRelocation
proves canonical full-state/effect commutation for every one of the17 native
instructions. PacketExecutionRelocation proves every successor stays within
the actual68-byte inline artifact or its real return boundary, transports the
complete execution and first-fault closure, and checks every arbitrary actual
RX execution prefix. No target PC is forced by the witness.

PacketInvocationABI proves preservation of SP, every SIMD register and x12
through x30 for every native prefix, including faults. It shares the pure ABI
and entry-contract definitions with SimpleInvocationABI. The actual-entry
contract requires the actual PC/RX entry, x0/context and Cortex-A72 split-pair
profile; the entry identity theorem proves the actual state is the modeled
one. It does not establish that contract by overwriting the actual state.

`extract_simple_emitted.py --program simple_packet` uses the same capture and
JIT-site validator as the default simple path. It produces two concrete
accepted-entry theorem instances, one for each captured load/generation,
including exact native bytes, checked B, full binding/specialization metadata,
actual JIT bytes and callback-reported RX address. The final theorem composes
verifier acceptance, admitted proof entry and full Artifact identity with the
proved prefix correspondence and ABI preservation. It has no assumed TV
premise. `simple-packet-emitted-negative-check` rejects a coherent native/JIT
store-byte change and a checked-B store change at their exact Lean byte-
identity theorems. Existing entry/store semantic mutations remain separate.

These certificates concern the frozen captured artifacts. Verifier/admitted-
entry soundness, BPF platform/context agreement, reference ISA/hardware/profile
correspondence, kernel immutable binding/JIT/entry agreement and the Lean
kernel/printed axioms remain trusted. Runtime CPU-profile metadata enforcement,
other programs and the native-only trusted loader remain active work. This
adds no performance-admission condition and changes no native/simulator code.


Registered native-only specializer transport (integration in progress)
--------------------------------------------------------------------

The kernel module exposes `native_submit` to the application and `specializer`
to a trusted service registered once at bootstrap. The fixed ioctl ABI is
`native_lab_trusted_wire.h`. SUBMIT accepts only native ELF, entry symbol and
typed metadata with the source program ID; it copies and pins these before
returning a kernel-issued request ID. The application has no proof field or
proof authority. Replacing a submission on the same file is refused.

The service uses NEXT to retrieve that immutable snapshot, ACTIVATE on its
capability file to authorize a worker, and COMPLETE with a verified program ID
or negative errno. The application uses WAIT on its original file. Closing the
service fails queued/active requests; registration cannot be taken over before
module reload. Privileged bootstrap/module administration is trusted. The
service must keep its capability and generation environment isolated from the
application, validate typed metadata against pinned kernel objects, and build
fresh B from P. C owns this userspace service and x86 worker; A owns ARM worker.

Both modules refuse application proof/binding writes and proof instantiation.
Sealed chunks retain one capsule identity. The JIT attaches that capsule to the
actual BPF program; COMPLETE accepts only a kernel-verified, JITted program with
that same object identity. A core cleanup hook releases capsule/module ownership
when the program is freed. P therefore remains kernel-owned after WAIT closes.
The reference ISA/specializer faithfulness and kernel binding remain trusted
where a per-program TV certificate is absent.

`make -C kprog/tv trusted-kernel-check` builds the current incremental T kernel
and runs transport controls without executing native code. The public loader
routes REQUIRE_BOUND_PROOF submissions through SUBMIT/WAIT before consulting
any simulator object. Application-supplied raw/ELF proofs are rejected;
manifest proof siblings and REQUIRE_PREBUILT cannot select B on this path.
The service supplies fresh native-proof and simulator objects explicitly,
with kernel-authenticated ACTIVATE authority. Success is completed while the
loader owns the program FD, so the kernel pins it before the helper exits.

CONTEXT and MAP query the active capsule's pinned source load attributes and
used maps, including actual inner-map templates. Only the service capability
can issue these queries. `make -C kprog/tv trusted-client-check` tests the public
native-only submission and controlled service-failure path; the transport test
also checks real source/map queries and rejects foreign maps, invented inner
templates, stale requests and invalid completion errnos. These real x86 KVM
controls pass, and both x86 and ARM loader libraries build. No native program
executes in these controls. Shared service/worker integration and the required
real BCC/x86 and Katran/ARM runs remain active. Generation-zero experiments
retain their explicitly unbound interpretation.


Application frontend and service kernel facts
--------------------------------------------

With `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1`, the public loader resolves
native/map metadata and uses SUBMIT/WAIT. It rejects explicit application proof
fields and does not open a manifest's simulator object. The legacy prebuilt
requirement cannot select an application proof on this route. The application
submits native ELF, entry and a JSON envelope with version1, load_context and
maps. The service must validate every assertion using the pinned source. Map
`value_offset` is null for a map object and numeric (including0) for a direct
value. Neither proof bytes, source C nor producer filenames/tool flags are in
the request. Phase/body-size counters not returned by this initial transport
remain unpopulated; they are not measured zeros.

Service-only CONTEXT returns the kernel's actual program type, attach type,
load flags/interface, attachment/BTF identity, GPL status and token presence.
MAP accepts only a used map of that source and returns its actual shape/BTF
IDs, with depth selecting its real inner template. These are48/56-byte query
records. Source/foreign-map/stale/depth controls run against real kernel maps.
They supply the common service's normalized worker declarations; an
application's asserted shape cannot establish the facts.

The C++ helper receives trusted_service_fd, trusted_request_id and its explicit
fresh trusted_native_proof_path. ACTIVATE authenticates the inherited capability.
It either opens its fresh proof_object_path/trusted_simulator_program or uses
its freshly generated raw proof. TrustedMapBinding supplies validated native
symbol/map-ID/direct-value aliases. Native linking uses an isolated directory
under that request's output, with no application prebuilt discovery/cache. The
helper automatically COMPLETEs success before returning, while its program FD
is open. The kernel pins the result before a short-lived helper can exit. The
common broker completes errors and proceeds to NEXT after helper success.
Token-bearing sources still require actual token-FD delegation; the current
frontend refuses them instead of dropping the source's token contract.

`trusted-client-check` exercises the actual public frontend and kernel queue,
including proof fields, a forged worker capability, exact native/entry/source
submission, no-proof typed metadata and real generation-error propagation.
The test uses the actual BCC vfsstat native ELF, checks the `stats` native
alias with direct-value base8 and omits two unused same-name source maps.
It executes no native instructions. C's common-service control already completes
a fresh accepted native worker and TEST_RUN returns2 (see
`corpus/results/kprog_app_coverage_20261107/trusted-service/summary.json`).
Real BCC/x86 plus Katran/ARM runs remain active. The
canonical library caches are `libnativeloader/build` and `build-arm64`; old
T-named duplicate caches are retired.

Trusted proof externs denote the already-bound native symbol address. The
linker adds the compiled REL LDDW relative addend (or explicit RELA addend)
to the capsule's nullable direct-value base, validates it against the actual
map object and uses the same native symbol address/ID for both artifacts.
Handle symbols forbid a nonzero relative addend. Intermediate arithmetic is
128-bit so negative, full-width and overflowing values cannot wrap into a
safe offset. `source-map-check` covers14 controls under ASan/UBSan. The
legacy manifest/source-instruction binding contract is unchanged.


Actual x86 emission entry on the trusted service path
----------------------------------------------------

`trusted-capture-check` uses C's unchanged common service, adapter and control
client with the existing optional TV export. The x86 callback records its
actual final RX entry (`final_ip + off`) through the same emitted-site wire
record as ARM. The loader validates the reported generation, extent, ABI,
source identity and entry against the actual JIT addresses/function lengths.
For relocation-free native code it compares every emitted byte at that entry.
Capture stays under the upload lock and completes before the helper publishes
the successful program to its application.

The retained `kprog/results/kprog_tv_20261107/trusted-capture/artifacts.tar.gz`
contains the actual expanded four-instruction verifier artifact, linked
five-byte native body, compiler proof, JIT image/layout and successful load
identity, along with the common service's immutable ELF/entry/metadata request
and fresh generation inputs. The native-only client executes that accepted
program and returns2 with prebuilt=false. Temporary run files are removed.
These are concrete binding inputs; the capture is not an ISA/translation
certificate. Relocated application bodies still need the corresponding
patch/materialization refinement.

C's first real upstream BCC vfsstat service replay is published at b37c64eaa:
five fentry programs are freshly verified, bound and attached, with
bound_required=1, prebuilt_proof=0, application exit0 and statistics output.
This is the first BCC application path; the full corpus and ARM Katran remain
separate active obligations.


Trusted service simple micro replay
----------------------------------

`make -C kprog/tv trusted-simple-check` uses the current captured x86
kernel/module pair and common service. It incrementally compiles the original
`micro/programs/simple.bpf.c` to a relocatable native ELF with the existing
kernel offsets, then submits only that P/entry/typed metadata. The client
loads the original simple BPF for its pinned ABI and compares both executions
on packet lengths14,71,72,128. All8 TEST_RUN checks require the correct return,
exact output bytes and every untouched packet byte. The common worker freshly
generates B and the loader captures actual checked bytes and final native RX
entry before publishing the result. REQUIRE_BOUND and legacy REQUIRE_PREBUILT
are both1; the accepted result is prebuilt=false.

Fresh captures accept `TRUSTED_SIMPLE_OUTPUT=/absolute/fresh/directory` on
`make -C kprog/tv trusted-simple-check`; the capture script also exposes
`--output-dir`. An existing summary or archive is preserved rather than
overwritten. Each new archive includes raw running-kernel ELF notes, `uname`,
GNU build-ID comparisons against the cached `vmlinux` and loaded module,
streamed kernel-image hashes, and the structural XDP layout receipt identity.
These provenance checks concern this capture tool; the common specialization
service and application admission are unchanged. A matching layout receipt
still does not constitute a post-conversion instruction capture or establish
the physical entry/return ABI.

`kprog/results/kprog_tv_20261107/trusted-simple/` retains the compact result and
compressed complete request/compiler/kernel/JIT inputs. The two initial
harness input-selection diagnostics are compressed separately: a previously
RET-rewritten proof object fails relinking, and an ET_DYN shared object fails
the service's ET_REL contract. The final input is compiled directly from the
original micro source; service/generator policy is unchanged. These runtime
checks and bound artifacts are inputs to the whole-program certificate; they
do not establish full-state or exact-event ISA refinement on their own.

`trusted-binding-check` validates the two retained native-only service exports
with the existing checked-artifact and RX-entry parsers. The RX parser now
accepts x86 byte alignment as well as ARM's four-byte alignment. The checker
requires external expected entry/ISA/ABI, pins every exported accepted file,
compares immutable capsule context to actual pinned source facts and binding,
reconstructs the real EXIT-to-JA proof instantiation, and compares all native
bytes at the reported RX entry. It rejects11 mismatches per accepted program
(entry, ISA, ABI, metadata, proof/native/checked bytes and RX entry), including
three structural mismatches tested without the external byte pins. These are
offline evidence checks, not additional kernel rejection tests or an ISA
refinement proof. The supported check here is the actual single-region,
mapless, relocation-free, zero-ABI-mask records; other artifacts retain their
own existing checks and still require refinement/materialization certificates.
The currently trusted specialization/link service still has to be connected
to immutable P by per-program TV. Accepted-byte provenance and the kernel
capture/binding implementation remain explicit trust assumptions. Extending
RX checks to x86 retains the existing ARM simple/simple_packet regression:
four actual captures pass and all72 corruptions remain rejected.

First actual x86 simple entry-load refinement
--------------------------------------------

`trusted-simple-entry-certificate` checks the retained native/B literals and
compiles `TrustedSimpleX86.lean` against V's canonical X86/X86Path and the
existing BPFPlatform semantics. The public canonical decoder lemma
`decode_mov_rcx_rdi` unfolds the same private decoder helpers; it changes no
ISA semantics. `entry_load_correspondence` connects actual native bytes0..3
to virtual B pc0 under the explicit XDP32-to-64 context expansion. It proves
both complete successor states, the same single8-byte event, corresponding
loaded values and equal memory. Native flags/other registers/vector/profile
and all untouched BPF fields remain in those state equalities.

The original single-step theorem requires initial entry PCs, an active proof,
related context/memory, and a successful context-read witness. Its original
scope and hashes remain in `trusted-simple-entry.json`.

`two_load_prefix_correspondence` now composes both actual native loads
(bytes0..7) with actual BPF steps0,1,2, including the real8-byte spill at
r10-40. Both complete successor states are fixed, loaded registers correspond,
and guest memory agrees outside the existing private-spill model shifted by24.
The second post-spill read is derived from that store and byte disjointness;
its value is not assumed. The full proof trace contains the spill write.
Only after proving its private bytes does the existing projection produce the
two ordered native read events. Permissions, successful reads and private/
guest disjointness are explicit hypotheses, including wraparound addresses.

The rest of BB0/program still needs later spills, flags/native input, reloads,
guards, stores, exit, fault cases and ABI composition. Context conversion
still needs bound kernel/platform transport. The axiom audit has no sorryAx;
the existing BV/private-spill proofs introduce Lean.ofReduceBool, so native
proof evaluation is an explicit proof-tool trust item alongside Lean's logical
axioms. Exact prefix scope/dependencies are in `trusted-simple-prefix.json`.
This is a concrete partial refinement, not a whole-program certificate.

The captured compiler initializer (B pc3..10) now has a complete-state path
proof, `initialization_block`. It checks the actual second8-byte spill,
32-bit register zeroing, two8-byte and one4-byte initialization writes,
explicit native-stack input, and both8-byte reloads. Every write/read remains
in the six-event trace. A generic disjoint-store lemma in `PrivateSpills`
preserves read values, permissions and initialization bits with architectural
wraparound. The two reload values follow from actual stores and this lemma.
`initialization_after_context_prefix` derives the first saved-pointer read
from the earlier real spill before constructing the actual BPF execution.
The native stack input is an arbitrary bound environment value, with an
explicit nativeInput witness; it is not substituted with zero.

The original pc3..10 subpath and its scope remain recorded in
`trusted-simple-initialization.json`. The unified environment composition below
now connects it to pc0..2. Privacy projection for all initializer accesses and
the native register/flag operations and guard remain. Successful accesses and
actual stack permissions are explicit kernel/platform premises; whole-BB/
program, fault, ABI and immutable-P materialization obligations remain open.


Unified initialized environment
-------------------------------

`initializedPlatform env` is a separate, explicit environment value over the
same captured context classifier. Existing `platform`, fail-closed `externals`,
and all earlier theorem declarations retain their original contracts.
`entry_environment_independent` proves equality of complete transitions at
pc0,1,2 for arbitrary environments/states, including faults: these instructions
observe no environment input. `initialized_body` reuses the existing path
transport theorem to lift actual pc3..10 steps to this same platform.
`initialized_complete_prefix` composes a single execution from pc0 to pc11,
with an explicit native-stack input witness and all nine ordered memory
accesses retained. No PC, successor or trace element is forced or erased.

The captured literal/binding checks and the complete supported Make target
remain in place. This composition needs no runtime/wire/interface change.
It closes the common-environment gap between the two proved subpaths; the
native register/flags/guard, whole-program, fault and ABI/materialization
refinement remain separate obligations. Scope/compatibility/axiom audit:
`trusted-simple-environment.json`. The precise initializer footprint and its
projection are composed below.


The actual x86 simple initializer's private footprint

`initializationPrivateByte` covers exactly the 36 bytes from `r10-40` through
`r10-5`, including architectural address wraparound. The last four bytes of
the 40-byte stack layout remain outside this footprint;
`initialization_untouched_top` proves this. `initialization_memory_agrees`
derives unchanged guest values, initialization bits and permissions from all
five actual stores. It makes no assumption about the resulting memory.

`initializationProjectEvent` hides only complete accesses to the four actual
8-byte slots and the actual 4-byte slot. `initialization_erased_private`
proves that every byte of every hidden event is inside the footprint.
Atomic, helper, fault and exclusive effects are always retained.
`initialization_event_projection` proves that the nine actual ordered events
reduce to exactly the two original guest reads; both read events are derived
from the successful reference-memory reads and kept under explicit guest
address disjointness premises. The execution itself retains all nine events.

`initialized_prefix_correspondence` now composes the byte-decoded native
bytes0..7 and accepted Bpc0..10 under one explicit environment, their complete
resulting states, native RCX/BPF r2 and native RDX/BPF r3 correspondence,
precise guest-memory agreement, and the ordered event projection. It uses
the same canonical ISA/memory semantics and existing actual execution
witnesses. This is still a successful two-native-load prefix: later native
register/flags/CMP/Jcc, guards, stores, exits, faults, ABI/platform transport
and immutable-P/materialized-artifact transport remain open. It is not a
whole-basic-block or whole-program certificate. The supported Make target
and bound-artifact mismatch checks remain unchanged; see
`trusted-simple-privacy.json` for hashes, premises and the axiom audit.


The first unsigned guard of the actual x86 simple artifact

`native_decode7`, `native_decode10`, `native_decode12`, and `native_decode15`
check the actual MOV RSI,RCX / XOR EAX,EAX / CMP RSI,RDX / JA bytes. The
first three reduce directly through the canonical decoder; the last uses
one public `Reference.X86.decode_ja_rel8` lemma over that same decoder,
including the signed byte displacement. No ISA definition changes.

`native_first_guard` checks the actual path from native PC7 through these
four instructions, with complete resulting state and an empty effect trace.
Its successor is PC60 when pointer > limit and PC17 otherwise.
`proof_first_guard` checks actual accepted Bpc11, whose corresponding
successors are pc34 and pc12. `first_guard_correspondence` derives both
executions and those successor choices from matching pointer/limit values;
no branch outcome is a premise. The same explicit B environment/platform is
used as at entry. Both guards perform no memory access or helper call.

`compare_ja_predicate` proves the unsigned comparison from the canonical
CMP flags for arbitrary incoming flags. `xor_compare_flags_choice` proves
that every flags value allowed by XOR's mask, including every undefined AF
choice, yields the same complete subsequent CMP flags;
`guard_final_flags` specializes this to the captured guard. The native path
witness uses the existing executable `X86Path.Execution`; universal local
relational transport across the undefined intermediate flag is supplied below. The path evaluator's conservative flag mask
is retained unchanged.

This discharges the local first-guard correspondence, not a whole-program
certificate. The entry-prefix composition is supplied below. Later guards/stores/exit,
fault and ABI/platform behavior, relational transport and the bound
immutable-P/materialized-artifact connection remain open. Evidence and the
complete supported-target/axiom audit are in `trusted-simple-first-guard.json`.


Actual entry through the first guard

`native_execution_append` concatenates witnesses for the existing canonical
byte-decoded execution relation, preserving every instruction and successor.
`entry_first_guard_correspondence` now instantiates this with the actual two
entry loads and four-instruction guard. Its B execution is likewise one
`initializedInstructionStep env` execution from pc0 through pc11. Neither
branch outcome is a premise: loaded pointer > limit leads to native PC60 /
Bpc34; the other outcome leads to native PC17 / Bpc12.

The theorem retains the complete native and B states and all nine B memory
events. The precise private-slot projection yields exactly the two original
guest reads; outside memory agreement includes values, initialization and
permissions. Native EAX/B r1 zero, native RSI/B r2 pointer and the complete
post-CMP flags are derived from the composed states. All earlier declarations
and the fail-closed environment/interface/binding contracts remain unchanged.
This is an actual first-basic-block correspondence for successful entry
loads/stack initialization under the explicit platform premises, not a
whole-program certificate or a universal fault/relational-execution theorem.
The remaining work is the later guards, stores and exit, program-level
relational composition (the local guard transport is supplied below),
fault/ABI/platform behavior and immutable-P/materialized-artifact transport. Audit and hashes:
`trusted-simple-entry-first-guard.json`.


Universal canonical relational transport for the first guard

`compare_after_relational_xor` quantifies over every transition allowed by
canonical `X86.Step` for the actual XOR, including every undefined AF choice.
It derives an empty trace, no fault, PC12, and exactly the same complete
subsequent CMP transition. It constrains no undefined flag beyond the
reference ISA's own observation mask.

`fully_observed_step_unique` proves uniqueness when both canonical flag and
register observations are complete; the guard's MOV/CMP/JA meet these
premises. `native_guard_relational_block` combines those unique steps with
the arbitrary XOR transition. `native_guard_decoded_relational_block` then
admits unknown decoded instructions and arbitrary canonical relational
transitions at all four actual artifact extents. The decoder determines the
operations from the captured bytes and actual intermediate states. It
proves every fault absent, the concatenated actual trace empty and the final
transition exactly `guardFinal`, including every register, memory field,
flag and the selected PC60/17. Neither an AF value nor a branch outcome is
selected as a premise.

`relational_first_guard_correspondence` connects every such actual decoded
relational native execution directly to an `initializedInstructionStep env`
execution of the actual B guard with the same ordered effect trace. It
derives both corresponding successors from the pointer/limit relation and
retains the complete native final transition and B state. Thus the B witness
is no longer limited to matching the executable XOR representative.

This closes the undefined-AF/local-relational gap for native bytes7..17.
It uses existing canonical `Step`, `matchesTransition`, `definedFlags`,
`observedRegisters` and the same decoder; it adds no ISA semantics or runtime
check. Whole-program relational composition, later guards/stores/exit,
entry faults/ABI/platform behavior and immutable-P/materialized-artifact
transport remain open. Evidence and axiom audit:
`trusted-simple-relational-guard.json`.


Actual accepted B's remaining bounds guards

`remaining_proof72_block` checks actual pc12..15 (MOV/MOV/ADD/JGT), including
its real pc34 or pc16 successor. `remaining_proof8_block` checks actual
pc16..17 (ADD/JGT), including its real pc34 or pc18 successor.
`remaining_proof_guards` transports and composes these paths under the same
explicit `initializedPlatform env`. It derives the early-exit or continued
path from the actual register comparison, retains complete resulting states,
and proves the entire guard region has an empty effect trace.

`remaining_proof_successor` derives the exact pc34/18 decision from the two
unsigned comparisons. All additions are the canonical 64-bit operations,
including wraparound; no monotonicity, pointer range, non-overflow, branch
outcome or environment-input premise is added. The only entry premises are
pc12 and an active B state. `ordinary_path_execution` reuses the existing
path transport for ordinary instructions, checking every actual PC and
successor. The native order is +8 then +72, whereas this B order is +72 then
+8; native-state correspondence and composition with the entry prefix remain
separate work. This is a B-subpath certificate, not whole-program TV.
Evidence: `trusted-simple-remaining-B-guards.json`.


Native remaining guards and their reordered B counterpart

`native_decode17/21/24/26/30/33` check the actual LEA/CMP/JA/ADD/CMP/JA
bytes. Two public decoding lemmas expose the same canonical decoder's LEA
and signed-immediate ADD; no ISA definition changes. `add72_value` proves
the reference widened/narrowed ADD result equals modular 64-bit addition.
Every actual instruction step fixes its complete successor state, including
RFLAGS, all GPRs, XMM0, memory, bases and the address-width profile.

`remaining_native8_block` and `remaining_native72_block` validate the actual
byte extents and branch targets. `remaining_native_guards` composes the
actual +8-first native paths, taking the second segment only when the first
JA falls through. `remaining_guard_correspondence` pairs this with the
actual +72-first B execution. Both complete final states and empty ordered
effect traces are retained; both memories are unchanged. The same disjunction
of the two modular unsigned comparisons determines native PC60/Bpc34 or
native PC35/Bpc18. No pointer monotonicity, no-overflow or branch-outcome
premise occurs. The separate native/B state functions retain their different
schedules and temporary values.

This is an actual guard-region execution/control certificate. Full entry
composition is provided below. Subsequent stores/exit, program-wide state
relations and canonical relational execution, faults, ABI/platform behavior
and immutable-P/materialized-artifact transport remain open. Evidence:
`trusted-simple-remaining-guards.json`.


Actual entry through all three bounds guards

`entry_all_guards_correspondence` composes the actual context loads, private
initialization, first guard and remaining reordered guards into one native
execution and one `initializedInstructionStep env` execution. The three
actual modular comparisons choose all paths. Any failed comparison leads to
native PC60/Bpc34; otherwise execution reaches native PC35/Bpc18, immediately
before the packet-write body. No branch outcome or no-overflow premise is
added. The theorem retains complete successor states and all nine original
B memory events; the proved-private projection yields exactly the two
original native guest reads.

Guest memory agreement outside the precise 36-byte initializer footprint,
including permissions and initialization bits, survives every guard. The
store-address registers retain the same loaded pointer (native RCX/B r2),
and native EAX/B r1 remain zero at this boundary. The frame lemmas prove that
later native guards modify only RSI/RDI and B guards only their actual r4/r5
temporaries. Thus these field relations follow from actual instructions.

The premises remain successful context reads and private-slot permissions,
explicit native stack input, entry context/memory relation and private/guest
disjointness. This does not yet cover packet writes, return/exit, arbitrary
entry faults, the program-wide architectural/relational simulation or
ABI/platform and immutable-P/materialized-artifact transport. It is not a
whole-program TV certificate. Scope and audit:
`trusted-simple-entry-all-guards.json`.


Actual accepted B packet writes and exit

`packet_proof_block` checks actual Bpc18..33 and its complete resulting state.
Its four guest writes remain ordered as 2 bytes at pointer, 1 byte at +2,
4 bytes at +3 and 1 byte at +7, with the exact values from the artifact.
`packet_proof_execution` transports this witness to the same explicit
`initializedInstructionStep env` relation. The only success premises beyond
PC18/active are the four actual writable-memory permissions; no packet event
is projected away.

`proof_exit_block` and `proof_exit_execution` check the accepted artifact's
actual MOV32 at pc34, rewritten JA at pc35 and appended EXIT at pc36. The
complete final state has PC37, halted=true, and the actual zero-extended
32-bit return value. `packet_proof_return` composes writes through this real
EXIT and derives returned value2 with all four write events retained.

This is a successful B-subpath/exit certificate. Native byte decoding,
write-memory/event correspondence, failed-store paths, complete entry/program
composition, canonical relational simulation and ABI/immutable-artifact
transport remain open. Scope, source hashes and audit:
`trusted-simple-B-packet-return.json`.


Actual native packet-write bytes paired with accepted B through EXIT

`native_decode35/40/44/51/55` check the five actual native instructions.
The public `Reference.X86.decode_simple_packet_tail` theorem exposes the
same canonical decoder, including signed immediate decoding of 0xbc.
`store_byte_value_congr` proves that a one-byte store depends on the low
byte in the existing memory model, including architectural wraparound.
The actual sign-extended native immediate therefore has exactly B's byte188
store state and event; the decoder's operand is retained unchanged.

`native_packet_execution` checks every actual extent/successor, all four
ordered memory writes, complete successor states and the zero-extending
EAX write. `packet_body_correspondence` pairs this with the actual B body
through MOV32/JA/EXIT under the same explicit platform environment. Both
ordered guest traces are identical. Equal actual writes preserve the prior
private-footprint memory relation, including initialization and permissions;
the final native and B return values agree at2. No packet event is erased.

The premises explicitly describe successful stores. Full entry/guard/body
composition, failed-store and entry-fault cases, program-wide canonical
relational simulation, ABI/return-boundary/platform behavior and immutable-P/
materialized-artifact transport remain open. This is a successful body
certificate, not whole-program TV. Evidence:
`trusted-simple-native-B-packet.json`.


Conditional complete captured payload and proof executions

`conditional_complete_payload_correspondence` composes entry, private
initialization, all three guards, the selected packet-write body and the
actual accepted EXIT. It proves complete native execution to payload PC60
and complete B execution to a halted EXIT state, with equal return values
and related memories. Guard rejection takes the zero-return path; the
other path performs the four actual writes and returns2. Writable-memory
premises are required only when the guards select that write path.

The native guest trace has the two original reads and zero or four actual
writes. B retains its complete nine-event initializer/entry prefix and that
same guest-write suffix. Private projection applies to the initializer
prefix alone; the suffix is retained unconditionally, so an address alias
cannot cause a packet event to be erased. Memory agreement includes outside
values/initialization and globally equal permissions. All branch outcomes
come from the actual loaded values with 64-bit wraparound retained.

This is conditional complete execution correspondence for the captured
60-byte materialized native payload and 37-instruction accepted B, under
the existing successful context/private-access and platform premises.
It is not an unconditional whole-program translation-validation result:
failed context/store accesses, program-wide architectural/relational
simulation, ABI/return-boundary/platform transport and binding the original
immutable ELF to the materialized payload remain open. Verifier soundness,
the canonical reference ISA/platform, kernel binding/capture, and the
registered specialization/link service until complete TV remain trusted.
Evidence and axiom audit: `trusted-simple-conditional-complete.json`.

### Generation-zero ABI output initialization regression

`make -C kprog/tv unbound-kernel-check` uses the existing x86 kernel and
incrementally builds its module. The actual verifier/JIT test covers every
callee-saved output mask across three generation-zero chunks, followed by a
shared-loader native ELF case requiring mask15 and multiple chunks. Both execute
and return2. Unbound instantiation now initializes r0 before ABI marker reads on
both ISAs; nonzero-generation proof ordering is unchanged. Raw evidence is in
`../results/kprog_tv_20261107/unbound-abi-regression/`.

The actual upstream Katran balancer is also in the regression run:
`make -C kprog/tv unbound-katran-inputs` extracts its existing runtime dependencies,
then `make -C kprog/tv unbound-loader-regression` runs both the synthetic loader
cases and unchanged KatranServerSession. The captured GET_INFO stub must contain
multiple sequential generation-zero chunks with mask15. The current real
balancer passes with80 chunks and driver-mode attachment. The AArch64 module
also passes all16 masks/three chunks under QEMU; see the same dated evidence.

### First guest-store fault

`first_store_fault_correspondence` pairs the captured native MOV16 atPC35
with the actual accepted B path18..22 when its write permission is false.
Both retain the exact width2/address fault, perform no write, and preserve
outside-private memory agreement. The canonical native state remains atPC35;
B retains its actual setup state atPC22. This is a model-only component proof;
no unsafe native test is executed. Remaining fault positions, entry composition,
ABI/materialization and unconditional whole-program TV remain open.

### All four guest-store fault positions

`all_store_fault_correspondence` covers the first failing store at native
PC35/40/44/51 and actual B PC22/26/29/32, widths2/1/4/1. Both actual artifact
paths retain exactly the successful preceding writes and then the same fault.
Complete partial memory, initialization bits and outside-private36 agreement
are preserved; the failed write and later writes do not occur. Only earlier
store permissions are required. This extends the first-store component without
changing earlier theorems or the ISA. The dated all-store-faults JSON/log records
the checked certificate. Entry composition, context faults, relational/ABI and
materialization obligations still remain; no unsafe native test was executed.

### Packet body with arbitrary write permissions

`packet_body_any_permissions` now covers every canonical write-permission
assignment. The first failed store is derived from memory permissions; no guest
write success/failure premise or branch outcome is assumed. Actual executions
either reach nativePC60/B EXIT with return2 or preserve the exact first-fault
prefix and full partial state. The selection function is proof-only and adds
no artifact checks. Entry/context/private-frame/ABI and whole-program relational
transport remain separate obligations. Evidence: dated body-any-permissions JSON/log.

### Entry through every packet-store outcome

`complete_all_store_outcomes_correspondence` composes the actual entry, all
three guards, arbitrary packet write permissions and real EXIT or first fault
in one native/B execution pair. It requires no packet-write permission or branch
outcome premise. The two actual successful context reads, exact private-frame
permissions, stack-input witness, context/private disjointness and captured kernel
platform remain explicit. Private projection applies only to the9-event setup;
every guest suffix event remains, including fault and alias cases. This extends
the earlier conditional-complete certificate; context faults, universal relational
simulation and ABI/original-ELF materialization still prevent an unconditional TV
claim. The entry-any-permissions JSON/log gives the exact checked checkpoint.

### Both context-load faults

`first_context_fault_correspondence` and `second_context_fault_correspondence`
cover failed8-byte context reads at nativePC0/3 and actual B virtualPC0/2,
including their captured physical context expansion. Neither failed read commits
its destination or advances its PC. The second fault retains the first read
and B's first private spill; only that proved-private spill is projected away.
Full states and outside-private36 memory values/init/permissions are retained.
These are model-only proofs, with no unsafe native execution. The dated
context-faults JSON/log records all six axiom audits. All-outcome composition,
universal relational simulation and ABI/platform/materialization remain open.

### All context-read and packet-write outcomes

`captured_all_read_write_outcomes` now constructs the actual canonical native
and B platform executions from entry for every guest read/write permission
assignment: either context-load fault, guard return0, four writes/return2, or
any first packet-store fault. No guest access success/failure or branch outcome
is assumed. Complete partial/final states and precise private memory agreement
are retained. Setup-only projection keeps every guest suffix and fault.
Private-frame permissions, entry/context relation, stack-input witness and
captured platform remain explicit. This is a canonical representative execution
correspondence, not yet a universal relational or unconditional artifact TV
certificate. Evidence: all-read-write-outcomes JSON/log in the dated results.

### Immutable ELF entry to emitted payload byte identity

The existing `trusted-binding-check` also anchors the complete kernel-owned
native ELF to its archived completion SHA and checks the whole accepted archive
SHA. For the captured control and simple inputs, it requires one defined global
entry spanning the only readonly executable section, supported x86-64 SysV
ET_REL format, no code relocations, and exact equality:
`immutable entry bytes = captured/emitted payload bytes ++ c3`.
The generated request-native ELF must be byte-identical to the immutable input;
its generated blob, native-link-abi-v2/mask0, empty data layout/map patches and
empty relocations must agree with the bound artifact. Current entry/payload
sizes are6/5 and61/60. The final RX comparison remains in the existing checker.

The28 added mutation controls cover original ELF SHA, generated-copy identity,
entry offset/code/terminal RET, ELF machine/type, ABI version/mask, generated blob,
data/map/relocation metadata and duplicate materialization components. Alongside
the original22 controls, both actual archives pass and all50 mismatches reject.
Most new controls exercise structural relations directly without byte-hash pins.
Results remain per program in `trusted-binding.json`.

This closes a structural byte-identity gap for these two captures. The ELF/parser
checker and archive provenance are trusted, and RET/ABI/platform semantic transport
and universal native relational validation remain open. This checker does not
claim that removing RET is semantically faithful.

### Relational uniqueness for16 captured instruction extents

`simple_defined_decoded_step_unique` proves that every canonical `X86.Step`
transition at the16 listed fully observed native instruction extents equals the
complete executable representative transition, including all state, events and
faults. Observation masks and operands follow from the actual bytes; none are
supplied by the caller. NativePC10 XOR's undefined AF is handled separately by
the existing universal guard theorem through CMP. Whole-program relational path
composition, entry/platform/ABI and RET transport still remain. See the dated
defined-relational JSON/log; the reference ISA and earlier theorems are unchanged.

### Canonical relational paths and all four store faults

`CanonicalRelationalPath` composes byte-decoded canonical `X86.Step` witnesses;
a fault terminates the path. `defined_relational_path_evaluation` proves every
fully observed relational path has the complete certified representative result.
`all_store_fault_relational_correspondence` then checks every canonical relational
result on each of the four actual first-store-fault paths against the real B
execution, retaining exact prior writes, fault and full partial memory state.
The ISA is reused unchanged. Successful-body and whole-program relational path
composition, CFG/extent completeness, ABI/platform and RET transport remain open.
See relational-fault-paths JSON/log for assumptions and reference source hashes.

### Complete packet-body relational correspondence

`packet_body_relational_correspondence` covers every canonical relational result
on the actual native packet-body path, for every guest write-permission assignment.
The path ends at its first store fault or nativePC60; the actual B path reaches
the same guest effects/fault or real EXIT and return2. Complete native state and
outside-private36 memory agreement are retained. The first-failure/path selection
is computed from permissions; no store success or branch result is assumed.
Whole-program entry/guard/XOR composition, arbitrary CFG/extent completeness,
ABI/platform and RET transport remain open. See packet-relational JSON/log.

### First guard as a canonical relational path

`first_guard_path_relational_correspondence` now accepts the actual four-extent
canonical relational path at nativePC7/10/12/15, including every undefined XOR AF
choice. The actual CMP determines one complete boundary state, and actual B11
has the same empty trace and derived successor. It assumes no branch outcome
or selected AF value. This lifts the prior step-wise universal guard result to
the same path relation used by the packet body. Entry/remaining-guard/CFG and
ABI/platform/RET composition remain open; see guard-relational-path JSON/log.

### Remaining guards as a canonical relational region

`remaining_guard_path_relational_correspondence` covers every canonical relational
result on the actual native remaining-guard path, deriving nativePC60/35 and
BPC34/18 from the compared values. Native +8 then +72 and B +72 then +8
are related as one region, including modular arithmetic. The proof retains the
complete native state and actual B execution without branch-outcome assumptions.
Generic evaluation-to-relational soundness and nonfaulting path concatenation
reuse the canonical ISA. Entry/whole-CFG completeness, strict per-basic-block
mapping across reordered guards, ABI/platform and RET transport remain open.
See remaining-guards-relational JSON/log for premises and source hashes.

### Relational entry reads and first guard

`context_native_relational_result` covers every canonical relational context
prefix for any read permissions, including either first read fault, with exact
full state, ordered events and fault. `entry_first_guard_path_relational_correspondence`
connects successful actual entry reads through XOR/CMP and the first branch to
the real B entry/setup/guard execution. Every undefined XOR AF choice is retained;
the complete boundary state, setup-only projection, memory agreement and derived
successors follow. Private-frame/entry/platform premises remain explicit.
The generic nonempty-suffix split preserves faults and all relational choices.
Whole-program/CFG, ABI/platform and RET composition remain open; see
entry-guard-relational JSON/log for separate premise scopes and source pins.

### Relational entry through all guards

`entry_all_guards_path_relational_correspondence` combines the actual entry
reads, arbitrary-AF XOR/CMP region and both remaining guards into one canonical
relational path. Every result has the complete certified boundary state, two
original read events and the actual B setup/guard execution, precise setup-only
projection and memory relation. Modular comparisons select the native extents
and corresponding successors without branch-outcome assumptions. The two
actual reads, private-frame and entry/platform premises remain explicit.
Complete body/fault composition, arbitrary CFG/extent coverage, strict
per-basic-block mapping and ABI/platform/RET transport remain open. See
entry-all-guards-relational JSON/log for exact premises and source pins.

### Complete selected path for every guest permission assignment

`captured_all_permissions_relational_correspondence` now covers every canonical
relational result on the actual selected complete captured path, from entry to
return or the first guest fault. Both context faults, guard return0, all four
first-store faults and successful writes/return2 are included, with no guest
read/write success, failure or branch-outcome premise. Every undefined XOR AF
choice is retained. Complete native state and fault, exact ordered guest events,
actual B execution and outside-private36 memory/init/permissions are preserved.
Setup-only projection never erases a guest suffix, including aliases or faults.

Private-frame permissions/disjointness, initial context/memory relation and
stack-input/platform premises remain explicit. The path is selected from the
canonical reads, comparisons and store permissions; proving that every arbitrary
extent/CFG path is covered, finite-prefix closure, strict per-basic-block mapping,
ABI/platform/RET transport and unconditional artifact TV remain open. See
all-permissions-relational JSON/log for the precise scope and source pins.

### Concrete selected-path safety with exact artifact binding

`TrustedSimpleSafety.bound_captured_selected_path_effects_checked` instantiates
verifier acceptance/soundness with the actual captured B execution and the
all-permissions canonical native path. Full `Artifact` equality includes native
and proof bytes, entry, ABI and metadata; native execution decodes that executed
image, and verifier soundness applies to the accepted proof image. The setup
projection only erases events and never changes or invents a surviving event.
Every native event on the selected path is consequently checked by B.

Run `make -C kprog/tv trusted-simple-safety-certificate`. The certificate lives in
a separate module so CFG proof development does not change the established
entry/permission certificate. Evidence is in bound-selected-safety JSON/log.
Verifier soundness, canonical ISA/memory, explicit kernel platform semantics,
kernel ownership/binding code, Lean kernel/native reduction and capture/ELF
provenance remain trusted or explicit premises; the dated fidelity TCB inventory
records source scope separately. Arbitrary CFG/extent and finite-prefix coverage,
strict basic-block mapping and semantic entry/ABI/RET/platform transport remain
open. This conditional selected-path theorem is not unconditional artifact TV.

### Finite-prefix safety up to a proved state relation

`TrustedSimpleSafety.execution_checked_of_related_complete` generalizes complete-run
safety to every finite execution from a related entry. Its explicit premises
require equal step events, related successor states, checked complete-run events
and a closed checked terminal region. It assumes neither full-state determinism
nor fuel/termination for the arbitrary run. This permits the concrete proof to
retain ISA-undefined AF choices until the real CMP overwrites them. The two new
generic lemmas use only `propext`; concrete x86 relation/CFG/terminal instantiation
is still required. Run the existing `trusted-simple-safety-certificate` target.

The reference module also exports the proof-only `canonical_x86_decode` tactic.
Its hygienic quotation reduces the original private decoder helpers, enabling
external extent proofs without another ISA implementation or global simp changes.
All earlier reference definitions and theorems remain byte-identical. The17-entry
extent/CFG job remains separate and pending. Evidence for the checked generic
composition and compiled interface is in related-prefix-composition JSON/log.

### Canonical uniqueness of arbitrary native extents

`simple_native_extent_unique` in `TrustedSimpleCFG.lean` (in the shared
`KProgTV.TrustedSimpleX86` namespace) proves that any successful `decodeAt` at
one of the17 actual captured native PCs has exactly the correct byte offset
and instruction length. All272 entry/length candidates0..15 reduce through
the single canonical decoder: truncated encodings fail and extra suffix bytes
do not change its actual fallthrough. Code-range guards also exclude modular
PC aliases. Caller-selected lengths and CFG annotations are not assumed.

Run `make -C kprog/tv trusted-simple-cfg-certificate`. All21 new theorem audits
use only the listed logical axioms; earlier reference/entry/safety sources are
unchanged. Evidence is in native-extent-unique JSON/log. Reachable CFG closure,
arbitrary finite-prefix safety, strict block mapping and ABI/platform/RET
transport remain separate obligations.

### Closure of arbitrary canonical relational native paths

`simple_native_relational_path_closed` now accepts an arbitrary list of decoded
extents and proves that every final PC remains in the actual17-entry CFG or
the60-byte payload end. Each accepted instruction range is forced to the unique
canonical extent, every actual canonical/relational successor is checked, and
no instruction can decode at the payload end. PC, memory, events and faults
remain exact under the canonical undefined-output masks. No access permission
outcome, branch result or AF value is assumed. Actual entry0 satisfies the
initial closed-PC predicate.

The CFG target and all5 new theorem audits pass; earlier CFG declarations are
unchanged. See cfg-closed JSON/log. Relating every arbitrary prefix's events to
B still requires the concrete state/step relation and terminal argument. Strict
block mapping, entry/ABI/platform/RET transport and other programs remain open.

### Actual AF/CMP coupling and canonical execution lifts

`canonical_cmp12_relational_af_equivalent` proves that arbitrary canonical CMP
outputs agree in their complete state, events and fault when input states differ
only in AF. The actual CMP overwrites that bit; no representative AF value is
selected. `af_equivalent_shape` retains every other architectural field exactly.

`relationalNativeInstructionStep` composes only existing `decodeAt` and `X86.Step`
witnesses. Both representative executions and canonical relational paths lift
exactly to it, without another ISA implementation, input check or fuel limit.
Its permissive fault repeats require the upcoming terminal argument. Six audits
and the safety target pass; see af-cmp-coupling JSON/log. Full concrete step-event
matching and arbitrary-prefix checked-events composition remain open, alongside
entry/ABI/platform/RET transport and strict B block mapping.

### Concrete arbitrary-step event/state relation

`related_native_instruction_steps_match` proves equal ordered events and related
successor states for every actual decoded canonical step from related inputs.
The relation retains full architectural equality except ONLY AF atPC12, while
requiring actual CFG membership. Arbitrary supplied ranges/opcodes are forced
by the byte decoder; all16 fully observed operations and actual XOR/CMP cases
are covered, without a branch/access outcome or selected AF value.

The safety module now imports the published CFG certificate and its supported
Make target builds that dependency. Nine audits and the safety check pass; old
theorems are byte-identical apart from the import. See related-step-coupling
JSON/log. Complete-path existence and terminal quiet must still be composed
to check every finite native execution; ABI/platform/RET transport and strict
B block mapping remain open.

### Complete actual canonical witness for any guest permissions

`all_read_native_path_exists` constructs the actual selected complete canonical
relational path for any reference memory read/write permissions, assuming only
entryPC0. Both context faults, derived guard returns, every first-store fault
and successful writes are covered. The witness's full state/events/fault are
exactly `allReadNativeResult`; `all_read_native_complete_execution` lifts it to
the actual decoded relational BlockStep. All comparisons and access outcomes
come from existing canonical semantics. No successful-access or branch premise
is added. The witness chooses one allowed representative; the already proved
step coupling retains every AF choice for arbitrary actual executions.

Five audits and the safety target pass; earlier declarations are unchanged.
See canonical-complete-exists JSON/log. Terminal quiet and checked-prefix
composition, ABI/platform/RET transport and strict B block mapping remain open.

`trusted-simple-terminal-quiet.json` records six Lean certificates for actual
faulting-instruction state preservation, a checked terminal fault self-loop,
and absence of decoded instructions at payload end PC60. Published state
coupling covers every related terminal state, including the wrapper's explicit
fault-repeat overapproximation. This closes the terminal premise needed by
related-prefix composition; its final concrete instantiation and entry/ABI/RET/
platform transport remain open. No ISA or runtime behavior changes.

`trusted-simple-all-native-prefixes.json` records the concrete simple-payload
instantiation of related-prefix composition. Every finite decoded native
execution from PC0 emits only checked events if its constructed complete
canonical trace is checked. Arbitrary extents, guest permissions, branches and
undefined AF are covered, with no fuel or determinism premise. No-fault runs
reach PC60; terminal fault repeats are covered by the checked-loop theorem.
The accepted-B/full-artifact binding instantiation follows separately.

`trusted-simple-bound-all-prefixes.json` closes the concrete checked-event
composition for this captured simple payload: verifier acceptance/soundness
for the exact clang B bytes and full executed/validated artifact equality imply
that **every finite decoded native execution** emits only verifier-checked
events, under the stated entry, invocation-input and private-frame premises.
ABI and specialization metadata participate in the full equality. No selected
path-existence, guest-access outcome, fuel or determinism premise remains.
This is the payload model theorem; original ELF entry/ABI/terminal RET/physical
platform transport and strict per-B-block full-state correspondence remain open.
The result lists the exact trusted premises and all reported Lean axioms.

`trusted-simple-native-abi-frame.json` proves that every finite decoded native
prefix preserves RBX/RSP/RBP/R12–R15 and modeled XMM0/FS/GS/address-width fields.
All actual instruction extents, permission outcomes and undefined AF choices
remain covered. This supplies callee-save/SP evidence for ABI transport. It
does not prove return-slot memory integrity: canonical RET reads eight bytes
from native RSP and may fault, and guest writes can alias that slot without
the physical invocation/platform disjointness fact. RET transport remains open.

`trusted-simple-native-return-slot.json` supplies the return-slot memory
component: when the invocation's packet bytes are disjoint from its native
return slot, every actual complete outcome preserves the entire entry
return-slot read, including permission, byte values and initialization.
All actual read/write faults and guards remain covered, and the initial
context read determines the packet pointer. This uses the canonical memory
model and existing disjoint-store theorem. Establishing that separation for
the physical invocation and transporting the original RET remain open.

`trusted-simple-original-ret-path.json` transports every accepted payload
instruction extent/path into the archived original61B ELF entry and constructs
its complete canonical relational execution, including the real terminal RET.
All permission outcomes remain covered: body faults stop before RET; otherwise
its actual read and any read/noncanonical-target fault remain in the trace.
No valid-stack or successful-return premise is needed. The archived entry
bytes are independently rechecked against the Lean payload plus `c3`. This
does not classify RET's extra read as a verifier-checked guest event or close
the physical entry/return ABI transport.

`trusted-simple-original-invocation-return.json` derives the original RET's
exact full-state outcome from the invocation's initial return-slot read and
packet/slot separation. Normal body completion returns to the saved canonical
word, advances native RSP by8 and appends exactly the entry return-read event;
body faults stop before RET. No final return-read/success premise is supplied.
The actual kernel invocation must still establish these initial ABI facts and
continuation identity. The retained RET read is not asserted to be a guest
access checked by B. Actual codebase and strict B-block transport remain open.

`trusted-simple-canonical-code-shift.json` proves that all17 actual payload
instructions commute with an arbitrary64-bit code-origin shift under the
canonical decoder and transition. Only resulting PC shifts; complete registers,
flags, memory, events and faults remain exact for every permission/branch
outcome. Relational AF/accepted-extent/whole-execution transport follows next.
Terminal RET needs separate boundary transport: its saved absolute caller
continuation must not be shifted along with the payload's internal PCs.

`trusted-simple-based-extents.json` proves canonical accepted-extent uniqueness
and absence of payload-end decoding at every64-bit codebase. Bounded native
byte offsets prevent PC-wrap aliases, and canonical consumed lengths determine
the actual extent. Relational execution transport into the PC0 certificate
remains the next component; no new ISA or runtime behavior is introduced.

`trusted-simple-relational-code-shift.json` transports canonical relational
step observations across code origins in both directions. State translation
is invertible; all17 actual decoded instructions preserve their flag masks
and complete GPR observations. Undefined AF remains arbitrary. Events, faults
and memory stay exact; accepted-extent and whole-execution reflection are next.

`trusted-simple-based-step.json` reflects every actual decoded step at any
codebase to a logical canonical step with identical ordered events and a
full-state translated successor. Accepted extents, decoded operands, masks
and transition identities derive from captured bytes. Arbitrary AF, memory
permissions and branch outcomes remain covered, and logical CFG closure is
preserved. Whole finite-execution and bound-B composition follow next.

`trusted-simple-bound-based-prefixes.json` applies the exact accepted-B/full-
artifact safety composition to **every finite native payload execution at its
actual codebase**. Complete state/trace transport covers arbitrary accepted
extents, AF choices, guest permissions and branches without fuel, determinism
or termination assumptions. Actual entry PC equals codebase; initial registers
and memory remain exact. Physical typed-context/private-frame/invocation facts,
strict per-native-block full-state correspondence and the original terminal
RET boundary remain explicit obligations. This is a model proof for the pinned
accepted capture, not a new runtime or hardware-fidelity result.

`trusted-simple-kernel-xdp-layout.json` pins the current compiled kernel's
`xdp_md`/`xdp_buff` field layouts and exact two source conversion branches.
Those facts match the existing declared simple context expansions; the old
accepted capture does not pin its kernel binary, so this is supporting current
layout evidence, not a reconstructed historical post-conversion capture.

`make -C kprog/tv trusted-simple-platform-certificate` checks
`TrustedSimplePlatform.lean`. `trusted-simple-physical-context.json` proves
full-state equality between each declared context conversion and an ordinary
BPF step on the whole derived physical37instruction image. Both read faults
and successes are covered without access-outcome premises. The other35 bytes
retain their exact positions; all-PC/whole-execution equivalence follows next.

`trusted-simple-physical-whole.json` proves pointwise step equality for every
complete BPF state and bidirectional correspondence of **all finite executions**
between the declared platform interpretation and ordinary BPF semantics on
the whole derived37instruction image. All35 unchanged positions are decoded
from exact bytes; invalid PC, halt, environment and all fault outcomes remain
covered. Full endpoints and ordered traces are exact, with no fuel/path/access
premise. This remains a declared interpretation, not a newly captured kernel
post-conversion program or proof of historical kernel binary identity.

`trusted-simple-physical-bound-safety.json` combines exact accepted-artifact
binding with verifier soundness stated on ordinary BPF semantics for the
declared physical interpretation. Every native payload prefix at its actual
codebase has checked events under the explicit invocation/private-frame
premises. The result pins its committed dependency snapshot; F's concurrent
uncommitted decoder extension is excluded. This proves neither historical
kernel binary identity nor the remaining physical ABI/strict block obligations.

`trusted-simple-current-reference.json` records a full dependent replay of the
historical B37 certificate after F published the canonical FF/4 decoder
extension. All dependencies, axiom reports and the complete actual log are
pinned. This replay passes; it does not validate the newly produced B30.

`current-kernel/trusted-simple/` contains a fresh native-only capture on the
identified running kernel/module and matches the compiled XDP layout receipt.
All8 exact packet checks and structural artifact binding pass, including14
materialization mismatch controls. Native P remains60 bytes, but current clang
output is30 accepted instructions rather than the historical37. The existing
Lean literal comparison correctly rejects that new B. Its context loads are
reordered and its first pointer guard uses JMP32; exact ordered-event and
full-width branch correspondence need new validation. The archive and binding
report retain these observations without substituting the old producer or
claiming the old certificate covers new bytes.

`make -C kprog/tv trusted-simple-current-audit` checks canonical diagnostics for
that fresh B30. It proves a cross2^32 abstract interval takes a different first
guard successor, and constructs successful context-read traces in opposite
orders. No claim is made that the abstract interval is a realizable Linux XDP
buffer. The captured B and private candidate literals are checked against the
actual archive/ELF bytes in `trusted-simple-current-audit.json`.

The archived two-line candidate makes the XDP context view volatile and applies
the existing empty value barrier. Its exact baseline compilation reproduces
the captured proof input; the candidate restores ordered loads and a64-bit
first guard, with canonical local successor/read-order proofs. It adds no
runtime check. It remains unpromoted and was not kernel-loaded; later guard
ordering, full-state transport and physical ABI still require completion.
The canonical production header remains unchanged for the active application
runs; the patch and exact compiler inputs are retained for its owner.

The fresh `jit-invocation/trusted-simple/` capture additionally records three
live kernel symbols and their compiled addresses. They share one observed
KASLR relocation, and the actual final JIT relocation reaches the live
`its_return_thunk`. The actual capture script and common loader binary hash
are retained. Missing symbol access is reported by the capture tool without
changing application admission.

`python3 kprog/tv/check_jit_invocation.py CAPTURE_DIRECTORY` checks this exact
single-function envelope, original native/entry/ABI metadata and archived live
symbol identity. The retained run passes8 packet checks,10 invocation mismatch
controls and14 materialization mismatch controls. This binds addresses and
bytes; runtime thunk text alternatives, the caller contract and current B30
translation validation remain separate. Historical captures are preserved.

`make -C kprog/tv trusted-simple-jit-certificate` checks the exact82-byte
captured image in `TrustedSimpleJIT.lean`. Its first5 byte-decoded instructions
establish RSP=callerSP-16, RBP=callerSP-8 and the unchanged incoming RDI,
flags, SIMD and segment state. Both saves stay in the ordered trace; memory
outside those16 bytes and the complete original return-slot read stay exact.
Saved RBP/R15 words are proved from actual stores. The actual final JMP also
has a canonical full-state step and reaches the captured live return symbol.

`trusted-simple-jit-entry.json` records the9 axiom audits and exact sources.
The proof has explicit stack write/read permissions. Canonical LEAVE, the
whole epilogue, actual kernel caller/context premises, runtime thunk text and
current B30 refinement remain to be composed; no host-ABI event is silently
erased or claimed verifier-checked by this component.

`trusted-simple-jit-body-frame.json` extends the same certificate to arbitrary
8-byte save/return slots across every complete canonical body outcome. Actual
RBP/R15 readbacks and the outer return-slot read follow from the wrapper's
stores and explicit packet/host-frame separation; guest access success is not
assumed. The captured tail POP also has an exact canonical full-state step
with its read retained. The14 audit reports pass. LEAVE and whole-epilogue
composition still await the single reference rule validated by F's hardware
fault observations; no separate ISA implementation is introduced here.

`trusted-simple-jcc-candidate.json` records a private follow-up to the context
candidate: an empty memory-clobber asm on JCC fallthrough keeps the native
branch order in this compiled simple body. The actual28-instruction output
reads data before data_end and checks raw pointers, +8, then +72 with64-bit
JGT, retaining exactly3 conditional guards. Its full source/header/object and
patch are archived. This is compile-shape evidence, without a new semantic or
kernel-acceptance claim; C owns integration after its active inputs close.
The earlier2-line artifact and local Lean proofs remain separately retained.

`trusted-simple-jit-epilogue.json` records a full dependent replay against V's
published LEAVE reference and22 JIT axiom audits. Canonical POP/LEAVE/JMP
success paths retain both reads and restore the caller frame without changing
the native result, memory or flags. Read faults stop at the actual failing
instruction; a LEAVE read fault preserves its full incoming state.

This uses the reference's shared read-fault abstraction. F's real hardware
comparison reports1024 noncanonical-frame #SS fault-kind differences, tracked
by V/F; full architectural fault classification is not claimed here. Actual
caller premises, current B30 refinement and the live RET boundary remain
separate obligations.

`jit-return-text/trusted-simple/` captures the two actual bytes at its own
live return symbol through existing `/proc/kcore`, before and after the8
native packet checks. Both samples are `c3 cc` and unchanged; the captured
ELF load-segment receipt bounds their address. The checker compares the
initial identity snapshot, completed archived summary and raw samples, and
checks the relocation reaches this same symbol. It passes14 invocation
mismatch controls and14 materialization controls. Earlier captures are
preserved and do not inherit this later session's text observation.

Text unavailability is recorded without changing native admission. The proof
must still compose canonical RET and its outer return read with the actual
epilogue; observing bytes alone is not that proof.

`context-candidate/trusted-simple/` is a controlled kernel regression of the
three-line candidate through the same registered native-only service, worker,
loader and client. A bootstrap-only compiler PATH wrapper preincludes the
archived header; its actual argv, source and header are in the capture. The
application submits only P. The kernel accepted and bound the fresh B29
(input28), byte-identical to the private compile's proof input, and all8 exact
packet checks pass. Structural invocation/materialization controls also pass.
The canonical header is unchanged. This supplies the actual accepted B for TV;
it is neither a full-state certificate nor production/app promotion.

`trusted-simple-live-return.json` instantiates the JIT and thunk literals from
the same return-text capture. Its28 audits check the connected actual
POP/LEAVE/JMP and RET executions, with exact restored caller frame and original
return-slot read retained. The new LEAVE canonical-span premise and address-
fault path use the published flat NO-LASS reference;64-bit wrap is retained.
Read faults and noncanonical continuations preserve their actual state/effects.

All affected prerequisite stages were rechecked; the final changed-source
check passes after a JIT-only decode-normalization correction. Actual kernel
caller/profile/stack premises, the full native-body embedding and exact B29
TV remain explicit. The caller return read is not silently classified as a
verifier-checked guest access.

`make -C kprog/tv trusted-simple-b29-certificate` checks the actual accepted
candidate bytes in `TrustedSimpleB29.lean`. The first SP marker and two context
loads match the canonical native two-load execution with the same ordered
reads and full explicit endpoints. Offset1 selects SP; imm2 is the input ABI
version. The existing declared XDP expansions are applied at PCs1/2, with no
simulator spills. Four axiom audits pass; this initial component explicitly
assumes successful reads. Read faults, guards/stores and the full basic-block
relation remain required, so this is not a whole-program TV certificate.

`trusted-simple-b29-first-block.json` extends that same accepted-byte component
to both context-read fault cases and the first actual64-bit conditional block.
The failure state and preceding reads are retained exactly. The entry/read
success path composes through zero/JGT64 and native MOV/XOR/CMP/JA, with exact
whole endpoints and corresponding exits for either predicate value. A separate
byte-decoded relational theorem covers every permitted XOR AF choice before
CMP, without a selected branch premise. All12 audits pass with their axioms
reported, including Lean.ofReduceBool. Remaining +8/+72 guards, stores, the
full architectural relation and production-artifact TV still require proofs.

`trusted-simple-b29-remaining-guards.json` adds the exact six instructions at
PCs5..10: +8 then +72, with native-order successors and full64-bit modular
arithmetic. Complete endpoints and empty effects agree for either exit, and
the native relational path result is universal over canonical executions.
All23 accumulated audits pass. Stores, entry/all-block composition, a full
architectural reconstruction relation and whole-program TV remain open.

`canonical-context/trusted-simple/` is a fresh capture through the current
production source path, with no private compiler wrapper. Its accepted B29 is
byte-identical to `TrustedSimpleB29.lean`; all8 exact packet checks and14+14
invocation/materialization mismatch controls pass. Source hashes are stable
before/after, including the owner's physical header whose integration was
uncommitted at capture time. This establishes the actual artifact identity,
without claiming a published-header snapshot or whole-program TV. Per-session
JIT addresses are recorded separately from the earlier JIT proof literals.

`trusted-simple-b29-stores.json` checks actual PCs11..26 against the native
store block: four writes of2,1,4,1 bytes, in the same order, with identical
addresses/values, resulting memory and return value2. Both complete endpoints
retain untouched fields. All28 accumulated audits pass. Store-success
permissions are explicit; fault cases, final EXIT, full entry composition and
architectural reconstruction remain required for whole-program TV.

`micro-native-runner.json` records the runner-side native-only migration.
The micro application no longer opens or uploads a prebuilt proof and always
requires the bound route. A separately registered common service must precede
application startup. Incremental runner build and the existing BCC generation
check pass; runtime regression is pending in this source receipt. C owns the
standard micro bootstrap and driver integration. Obsolete caller proof-open
and proof-verifier timing fields are removed; native_load_ns includes waiting
for the service. This introduces no application proof-upload exemption.

The later owner commit `af2f58c89` publishes the exact d30 header used by that
capture; `source-review.json` records the committed-byte comparison. The
original capture-time attribution is preserved. B29's accepted bytes therefore
also correspond to that published producer header, without reusing another
session's JIT addresses or claiming completion of the semantic certificate.

`trusted-simple-b29-store-outcomes.json` completes all four first store faults
and the actual JA/EXIT trailer. It retains every preceding successful write,
full partial memory, fault state and fault event. The total store-block
correspondence covers every canonical permission assignment; its universal
native relational theorem fixes state/effects/fault without a next-state
premise. All35 accumulated audits pass. Entry/all-block composition, the full
architectural reconstruction relation and whole-program TV remain open.

`micro-native-only-review.json` independently checks C's standard-bootstrap
micro capture: all13x3 exact results and26 successful fresh native requests,
with distinct request/program IDs, matching immutable/generated native ELF,
actual compiler records and image binary hash. Both native labels execute P
through the bound service. The captured earlier runner and later T binary are
explicitly distinct. This functional evidence supplies no timing comparison,
numeric generation, checked-byte snapshot or per-program TV certificate.

The same review receipt pins the current classification sources: all six
application proof/worker fields remain rejected; the worker must activate a
live request through the service capability and match the kernel's worker
identity. The micro runtime has no exception, and bootstrap passes no service
FD to the application. This review required no loader or kernel rule changes.

`trusted-simple-b29-composition.json` connects actual B29 entry, every guard,
all store outcomes and JA/EXIT into one execution. It covers both context read
faults and all successful-read outcomes without permission/branch premises.
Every canonical relational result on the selected complete native path has
exactly the same ordered guest effects and final memory as that execution.
All41 accumulated audits pass. This selected-path composition still requires
full architectural reconstruction, arbitrary-prefix TV and physical caller
embedding before an end-to-end safety claim.

`trusted-simple-b29-bound-prefix.json` records the actual-B29 conditional
composition theorem `bound_native_prefix_effects_checked`. Constructed B29
execution/effect validation, assumed verifier soundness and acceptance for the
admitted B state, and complete Artifact binding imply checked effects for
every finite canonical native prefix. Bytes, entry, ABI and metadata remain
inside that equality. Arbitrary extents/branches, permission outcomes, undefined
AF and terminal-fault repeats are covered by the unchanged native-only prefix
lemma, without borrowing the older B37 correspondence. All42 audits pass.

The verifier, V's ISA/Memory reference, kernel binding and declared XDP
conversion/capture provenance remain trusted. Full per-basic-block
architectural reconstruction and physical JIT/caller transport are still
required; this is not a whole-machine safety claim or a certificate for other
programs. The B29 Make target now depends on the native safety/CFG library.

`trusted-simple-b29-based-prefix.json` transports that theorem to an arbitrary
emitted payload code base, preserving every invocation field except the
logical PC shift. All43 audits pass. Full JIT-image/caller embedding and
architectural reconstruction remain separate; an absolute return address is
not shifted by this payload transport.

`make -C kprog/tv trusted-simple-b29-state-certificate` checks full
architectural reconstruction for the first native basic block, including both
read-fault boundaries. Changed GPRs come from actual B29 registers; untouched
fields come from the immutable invocation frame. Canonical CMP rematerializes
all RFLAGS. Equality covers all16GPRs, flags, XMM0, memory, PC, segments and
address width, with actual ordered effects and every permitted XOR AF choice.
All4 state audits pass. Later guard/store boundary reconstruction and complete
full-state TV remain open; the physical context-conversion premise persists.

`trusted-simple-b29-second-block-state.json` extends the reconstruction through
+8 LEA/CMP/JA. The first-block relation is preserved into a full second-block
view using actual B registers, canonical CMP and the immutable invocation
frame. Every byte-decoded canonical native execution has that complete state,
empty effects/fault and the actual successor, including64-bit wrap. All6 state
audits pass. +72/store reconstruction and full-state TV remain open.

`trusted-cmp-overflow-review.json` is read-only mathematical support for C's
private CMP candidate: canonical OF equals SF xor signedLT of the properly
width-narrowed operands for all8/16/32/64-bit inputs and old flags. SF/result
must be from the same actual zero-borrow subtraction. The single audit passes;
source, reviewed patch, command and log are archived. C still owns actual
macro/width routing and compiler regressions; no producer or ISA change is
made by this review and no full handler/artifact TV is inferred.

`trusted-simple-b29-third-block-state.json` adds +72 ADD/CMP/JA full-state
reconstruction. Native RDI's earlier +8 value is recovered from the original
B pointer after r3 is overwritten; the prior temporary invariant is derived
from the preceding actual B ADD. Canonical ADD/CMP flag stages and modular
arithmetic are retained. All9 state audits pass. Store/fault/exit views and
composition into the full architectural TV relation remain open.

`trusted-simple-b29-store-block-state.json` adds full successful/faulting store
and exit reconstruction. End is snapped from actual B r1 at store-block entry
before B kills it, preserving native RDX and flags without an extra access.
All permission outcomes and exact partial states are covered. Guard views map
BPC27/28/29 to native payload end, and JA/EXIT preserve every view. All14 state
audits pass. The four native blocks now have correspondence lemmas; their
relations/real-load snapshots still need composition into the full TV instance.

`cmp-current/trusted-simple/` captures a fresh P-only load after the published
CMP flag rewrite and service terminal-drain fix. The actual accepted bytes are
EXACTLY the certified B29, with unchanged nativeP60;8 exact packet checks and
14+14 invocation/materialization negatives pass. Five source pins are stable
before/after and the header matches its published commit. Actual byte equality
supplies this link; per-session JIT addresses and the remaining whole-TV/caller
obligations are recorded separately.

`trusted-simple-b29-all-state.json` composes all four architectural views.
Actual B branch history distinguishes shared exits; actual context-read and
store-entry-r1 snapshots preserve killed values without program rereads.
Every selected complete canonical native result, including either context
fault and every guard/store outcome, has the reconstructed whole architecture
and a matching actual B29 execution with the same ordered effects. All21 state
audits pass. Packaging observer/CFG/fault coverage into the explicit generic
TranslationValidation instance and physical JIT/caller transport remain open.

`trusted-simple-b29-observer.json` adds a ghost observer whose physical state
and effects erase exactly to real B29 execution. Every real B execution also
lifts, so no safer subset is selected and no extra program predicate is added.
Invocation/initial-state lineage is immutable; each initially absent store
snapshot comes from an actually reached BPC11 state. The all-outcome complete
native full-state theorem now has a real observed B execution with identical
ordered events and actual fault. All9 observer audits pass. Explicit generic
per-block TV, physical JIT/caller transport and other programs remain open.

`make -C kprog/tv trusted-simple-b29-blocks-certificate` now constructs the
explicit generic `TranslationValidation` instance for all four simple native
blocks against actual accepted B29 execution. Boundary relations retain the
entire native architecture, corresponding successors and ordered effects,
including both context faults, every guard exit and all four first-store
faults. Ghost boundary tags keep branch history; the store-end snapshot is
only the actual incoming B r1. Macro steps erase to real B instructions.

`trusted-simple-b29-block-tv.json` records all11 axiom audits and the concrete
composition theorem: verifier acceptance/soundness for the admitted B entry,
the explicit TV instance and full Artifact binding imply that every event of
any finite native block execution is checked. The executed native bytes/entry
and accepted proof bytes occur in those relations; binding also retains ABI
and specialization metadata. The earlier instruction-prefix theorem covers
arbitrary instruction prefixes and terminal-fault repeats separately.

This closes the previously missing explicit block-instance packaging for
exact P60/B29 under the declared model. Physical JIT/caller/stack and context
conversion provenance remain explicit obligations, and other micro/application
programs still need certificates. This is not a whole-machine safety claim.

`micro-service-lifetime-review.json` checks the actual9bc63952 raw archive
against the reported service-after-first-request failure. It contains85
terminal requests,84 successful and only SocketLB request61 rejected by the
verifier;24 later requests succeed. The service ran about17.6minutes, with
request85 finished before cleanup SIGTERM. Current supervisor source matches
all85 captured physical service-source pins and stops after application return
and terminal-request drain. No lifecycle patch or rerun follows from that
claim. Decisive raw records are retained; no workload/timing/TV claim is added.

`trusted-simple-b29-physical-payload.json` adds exact fresh82-byte JIT-image
embedding. Canonical decoder proofs cover all17 payload instruction PCs and
every candidate extent length0..15, including suffixes into the epilogue.
Every accepted physical body extent reflects to the same canonical instruction
in P60; arbitrary physical payload prefixes retain full translated state and
identical ordered events. Complete binding and admitted-B verifier soundness
then imply checked effects through the B29 prefix certificate. All8 embedding
audits pass; no old-session return displacement/address is reused.

`payloadInstructionStep` segments at physicalPC74, the actual P60/host-wrapper
boundary, without adding an instruction or runtime check. Host prologue/
epilogue/return memory operations remain separate and retained. Current-image
wrapper composition, actual caller/context/stack provenance and other programs
remain open. Reproduce with the embedding-certificate Make target.

`trusted-simple-b29-current-wrapper.json` composes the same fresh image's
actual prologue with bound/checked B29 payload effects, and its actual
POP/LEAVE/JMP with the live C3 return. The fresh return displacement resolves
the captured JIT base to its own kernel return symbol. Both PUSH writes and
all three recovery/return reads remain in their respective ordered traces.
Actual physical payload execution proves ABI preservation and derives SP/BP/
R15 before the epilogue; no restored native endpoint is assumed. Canonical
wrapper read/address/return-target faults retain exact partial state/effects.
All21 audits pass using the single reference ISA.

Caller writable slots, canonical frame/return target, actual saved-word reads,
post-prologue memory matching the admitted B entry and physical provenance
remain explicit premises. The missing kernel stack/packet separation and
context-conversion obligations are not discharged by assuming those reads.
The earlier wrapper's pure frame constructors are reused, while actual fresh
bytes and return address are checked anew. No new guest run or timing is used.
