# Lane T results, 2026-11-06

**O1–O4 are not discharged end to end.** No micro or application program has a
translation-validation certificate. The records deliberately distinguish
kernel binding tests, a conditional composition theorem and artifact inventory.

Completed results:

- `8d4d57957`: `kprog/tv/Composition.lean` composes native-to-proof block
  simulation across every finite prefix, then exact artifact binding, entry
  compatibility and verifier soundness imply every native memory/helper event
  was checked. The current statement explicitly quantifies those events.
  Lean reports only `propext`; the ISA/block certificate remains a premise.
- `062d9b378`: explicit native/proof/relocation byte equality and entry/ABI/
  specialization seals. Both verifier instantiation and JIT check the seal;
  JIT also checks program/attach type. Host rejection tests use ASan/UBSan.
- `543e80b1e`: whole-program generation vectors, contiguous native extents,
  identical context/ABI metadata, ordered sidecar groups and rejection of BPF
  edges into a proper suffix. Real x86 KVM and AArch64 full-system QEMU tests
  execute a valid two-chunk native program and reject incomplete, reordered,
  missing, duplicated and mutated-peer groups.
- `f322609b7`: the actual shared loader native-links, uploads, seals and runs
  one-chunk and three-chunk x86 fixtures, both returning 2. These fixtures test
  binding and are not simulator TV certificates.

Raw logs are retained alongside this file. The initial AArch64 test wrote its
result to x0 rather than BPF r0/x7; the initial long loader fixture consisted
of NOPs that native-link removed. Both harness mistakes were corrected, and
their failed logs remain with the successful reruns. No shared runtime image
or module artifact was replaced and no benchmark timing was run.

`programs.jsonl.gz` is a lossless snapshot of 6,064 phase/program records:
29 micro programs per ISA, 3,685 x86 application phase entries and 2,321 AArch64
application/diagnostic phase entries. Those cover 1,136 native application
input paths per ISA, plus one AArch64 uninitialized-stack diagnostic. Variants
and failures are retained, with file/section hashes, ELF function offsets,
relocation counts, source-inventory hashes and compiler/load-record provenance.
Every record is **not_validated**. These artifact counts are not a live
application-startup inventory or verified-path coverage.

Outstanding dependencies and defects:

- O1: lane V now exports canonical byte-decoded CMOV state/memory transitions.
  The remaining reference operations and lane F's CPU counterexamples are
  assigned work; bounded handler contracts alone cannot certify whole programs.
- O2/O3: there is no compiled-BPF semantics or per-block translation checker.
  The actual post-link, verifier-instantiated instruction stream has not been
  certified against native bytes. No second native ISA model was introduced.
- Application integration now has compiled proof lookup/linking and a
  helper/map-capable native-proof interface, detailed below. Actual six-app
  program integration and unresolved subprogram/kfunc metadata remain active
  work, together with per-program TV. Original app BPF must not be substituted
  for the simulator proof.
- The TV entry relation must still establish the linked source entry, ABI
  compatibility and specialization fidelity. Kernel identity binding alone
  proves none of these semantic facts.

The exact trusted base is in [the checker README](../../tv/README.md).
It explicitly includes the verifier policy. Native-proof regions now force
initialized-stack checking even with CAP_PERFMON.

The helper/map increment passes real x86 KVM and AArch64 QEMU tests; both
`helper-map-final-*.status` files contain 0. The x86 public manifest C ABI
selects an actual clang object/entry and runs helper and map native code
returning 2. The map proof uses exactly the original map ID; an invented
internal zero-map state is rejected. Both ISAs reject uninitialized-stack,
bad-helper-argument and map-value out-of-bounds proofs and accept 70,000 proof
instructions restored to short native code. These runs completed before the
08:34 container restart. No timing result or per-program TV certificate is
claimed by them.

Two accepted-wrong behaviors were fixed, retaining their evidence:

- `map-pc32-jit-before.bin` is the 93-byte x86 JIT image whose PC32 map LEA
  addressed embedded ELF descriptor data, producing 0xCCCCCCCC while the
  original map still held 2. The linker now loads the actual kernel map
  identity from its relocated pointer literal. Raw and manifest map cases pass.
- `arm64-prefix-stack-negative-before.log` records a synthetic chunk-prefix
  reservation store initializing fp-512 and admitting an unsafe proof. The
  store was removed; kernel stack-depth metadata reserves space without
  initializing proof state. The same negative rejects on both ISAs.

Earlier stale-symbol-version module-load failures and verbose-log ENOSPC
failures are retained. Paired kernel/module exports and quiet successful-load
logs correct the harness; verifier rejection cases retain verbose diagnostics.

The external-identity/frame follow-up also passes on both ISAs
(`external-binding-final-{x86,arm64}.status`: 0). Both reject surrounding stack
and helper code, a two-map swap despite retaining both maps, a post-seal FD
rebind, a map pointer/value kind swap and a mismatched value offset. Matching
map pointer and value relocations execute native code returning 2. The x86
shared-loader tests additionally pass actual array and hash lookup paths through
the manifest C ABI, preserving original map IDs, and reject a real kernel
helper target different from the proof's helper. Specialized hash targets are
matched using the kernel's own map lookup generator rather than a second
userspace/kernel lookup table.

The x86 recovery exposed a truncated copied `kernel/.freezer.o.cmd` ending at
`/wo`. Its stale object carried a 1344-byte `bpf_prog_aux` beside the new
1352-byte type, causing ambiguous base BTF and module registration failure.
Only T's rebuildable object/dependency file was removed; make rebuilt it with
correct dependencies. The failed module diagnostics and corrupted dependency
file are retained. AArch64 needed its development libraries reinstalled after
the container restart. Neither issue changed verifier policy or bypassed BTF.

`helper-pointer-{x86,arm64}.status` are both 0. Relocation kind 7 executes a
verified indirect helper call on both architectures; changing it to a different
valid helper or changing its zero literal rejects the load. The full existing
identity, frame, helper/map and large-proof suites also pass. C/A can use this
interface for bounded helper tables; matching table selection to native control
flow remains part of the per-program translation certificate.

`raw-proof-map-relink-final-x86.status` is 0. The runner's separate proof load
previously created different maps from the original/native program. The shared
loader now links raw proof FD operands to the original maps. A regression uses
an identically named second map holding 13 and an original holding 2: native
execution returns 2 and the bound program retains only the original map ID.
A wrong value-size declaration rejects at the loader. This corrects the map
identity failure behind R's stage2 rejections; the reported odd x86 chunk tail
was legal, and the diagnostic now limits word-alignment checks to AArch64.

`bpf-path-check.log` checks the byte-decoded BPF model and its boundary cases.
`KProgTV.BPFPath.evaluate_sound` proves that a successful path witness has the
same full BPF state and exact ordered events as actual BPF execution. The proof
depends only on `propext` and `Quot.sound`; no `sorry` or solver result is an
assumption. Wrong successors and execution after return/fault reject. This
establishes checker machinery; native block/entry relations remain to be
instantiated for each micro/application artifact. No program is relabelled
validated by this component theorem.

`cmov-certificate-check.log` records `make -C kprog/tv cmov-negative-check`:
the actual clang ELF's production CMOVE scalar handlers pass for all inputs at
16/32/64 bits, with native byte decoding and BPF execution checked against V's
reference. An unchanged ELF copy passes; condition-mask, branch-successor and
source-register mutations reject. `cmov-block.bpf.o`, `cmov-CompiledBlocks.lean`
and `cmov-clang-version.txt` retain the exact positive input; the three
`cmov-wrong-*.log` files retain semantic rejection diagnostics. This scalar
component is not a full architectural-state or application certificate.
Its printed logical dependencies include `Lean.ofReduceBool` for native
certificate checking as well as `propext`, `Classical.choice` and `Quot.sound`.

`data-layout-host-check.log` passes the host binding/Lean checks and the
ASan/UBSan DATASEC name/offset/size/section rejection matrix.
`data-layout-kernel-x86-final.log` passes the existing kernel/helper/map suite
plus actual manifest and raw-proof internal-map reuse and same-sized wrong-BTF
variable rejection. Both loader entry paths check the original DATASEC layout
before replacing proof map identities. The manifest positive verifies the
original map ID is retained. The initial fixture attempts exposed a test-side
`bpf_prog_info` reuse error; the query is now zeroed before each syscall.
These remain binding checks, not per-program translation certificates.

`readonly-data-final2-{x86,arm64}.log` pass exact frozen readonly-data binding,
including a real native load from embedded data spanning two chunks. They
reject unfrozen maps, changed native bytes, wrong native offsets, a swapped map
with identical values, a different chunk's data mutation and overlap with a
JIT helper-pointer relocation. The x86 log also passes both actual clang
manifest and raw-proof loader paths and rejects mutated compiler data.
Relocation metadata kind 8 pins the proof map and records the complete native
address extent without patching native code. No original writable application
map is synthesized. These checks establish immutable specialization binding;
the reference-ISA address/state/trace relation is still a TV obligation.

`bpf-atomic-check.log` passes the byte-decoded BPF path theorem plus atomic
read-modify-write regressions: 32-bit fetch returns the old zero-extended word,
non-fetch preserves the full source, signed offsets select the actual memory,
neighbor bytes survive a narrow update, compare/exchange narrows its comparison
and preserves memory/initialization on mismatch, 64-bit exchange returns the
full old value, and permission faults change neither state nor event prefix.
Atomic operations use the existing canonical atomic-event kind. These are
checker semantics checks; they do not relabel any micro or app TV record.

`helper-map-arm64-readonly/` contains the complete 13-program Arm helper/map
rerun: every original program passes kernel and bound-native result/return
checks with nonzero generations, including `map_hash_str_key` after kind-8
readonly-data binding. `RUN.txt` records the exact make commands and support
artifact staging; `readonly-stage2-arm64-inputs.tar.gz` preserves the actual
runtime initramfs, compiled/generated inputs and source snapshot. This closes
the previously recorded readonly-data load failure. It does not discharge the
per-program reference-state/trace proof.

Proof-entry ABI 2: actual compiled inputs and both kernel JITs
-----------------------------------------------------------

The dedicated eight-byte private proof instruction supplies native body SP,
body code base and saved outer return address as arbitrary initialized 64-bit
scalars. Numeric R1 preserves all actual bits and erases pointer provenance.
The shared header is copied byte-for-byte into the kernel patch, checked by the
patch regression. Binding envelope version remains 1/64 bytes; this input ABI
is separate from the native-loader bound-proof C ABI.

`make -C kprog/tv input-negative-check` passes the actual clang ELF theorem for
all 64-bit entry/argument values and arbitrary memory, unchanged memory, empty
effects and a real byte-decoded BPF execution. Selector/source/ABI mutations
fail the semantic theorem; unchanged ELF passes. Axioms are `propext` and
`Quot.sound`. Existing CMOVE compiled-artifact positives and mutations pass.

`make -C kprog/tv -o kernel-build-x86 -o linker-build kernel-check` and
`make -C kprog/tv kernel-check-arm64` pass: stable actual entry addresses,
nonzero high address bits, exact numeric 64-bit identity, forced constant
blinding, malformed ABI/kind/destination rejection, unreadable R1 rejection,
and unsafe scalar accesses hidden by an erroneous MOV-constant interpretation
reject. All four input kinds also pass through actual sealed native proof
lowering/restoration and native execution. Existing binding/helper/map/readonly
regressions and actual x86 manifest/raw loader checks remain passing.

The first Arm attempt failed to find cross libelf/zlib/zstd. The checker
Makefile now uses the existing repository AArch64 sysroot explicitly; the final
run passes without manual environment setup. Both attempt logs are retained.
`proof-input-abi2-inputs.tar.gz` retains exact source/proof ELF/Lean extraction,
mutation artifacts and logs, both test binaries/modules, Arm runtime initramfs,
kernel configurations and raw kernel build logs; the manifest hashes kernels
as well. Logs retain original bytes, including Arm serial CRLF.

This is the proof-input component and real kernel binding evidence. Full
per-program TV, the same-invocation native/source ABI relation, and closing the
production SP/LR counterexamples require the remaining C/A/V/T integration;
none is certified by these component runs. The marker verifier/JIT semantics
are explicitly part of the kernel ABI trusted base.

Exact full source BTF manifest identity
-------------------------------------

The manifest now supports `source_btf_symbol`, independently of the native
`symbol`. The source entry must be a named BTF function at instruction zero;
its full name comes from captured source metadata or the original program FD.
Conflicting captured/loaded full names reject before native upload. Truncated
kernel names cannot satisfy this selector. Empty selectors or missing BTF fail;
unknown full names do not match, and ambiguous candidates still fail.

`make -C kprog/tv manifest-check` passes ASan/UBSan host cases for two distinct
full names sharing the real BCC `tracepoint__sys` kernel-name pattern, missing
BTF, truncated/unknown full names, empty selectors and ambiguous entries.
The first host compile's missing-field-initializer failure is retained; the
fixture now initializes every BPF instruction field correctly.

The final x86 kernel run passes two actual loaded BPF functions sharing all
15 kernel-name bytes, type and bytecode size. Each selects its distinct native
entry through both FD-derived and captured full BTF metadata and completes
sealed native execution with retval 2. Swapping the full captured function
while retaining the identical short name rejects, as does using an original
program with no BTF. All prior loader/binding/input regressions also pass.
`full-btf-manifest-inputs.tar.gz` retains production/test sources, actual
compiled BPF/native objects, manifests and executables. This is source-to-native
selection/binding evidence; it does not replace their per-program TV proof.

Canonical same-invocation entry relation
--------------------------------------

The actual clang input certificate now consumes V's canonical
`Refinement.EntryEnvironment.Environment`, published in `4c6ed8913`.
`compiled_x86_entry` and `compiled_arm64_entry` prove its computed result comes
from a single source-state witness, including explicit source/body stack and
code biases, argument-register mapping and the actual x86 saved return slot or
Arm LR. All four theorem axiom reports are exactly `propext, Quot.sound`.
The unchanged ELF and all four semantic mutations pass their expected outcomes.
The first development proof needed the explicit modular add/sub cancellation
lemma; that failed log and the final passing log are retained.

These are conditional entry-component theorems, requiring actual ABI witnesses.
In particular, the x86 native emitter copies inline bytes without a hardware
CALL. Its body SP does not point at the saved outer return address; seeding
that word with a return token invents state. The producer's normalization of
linked JMP-to-end into a fictitious RET has been reported to C for correction.
This observation is not hidden by granting a guessed stack-base relation.

Load-context binding version 2
------------------------------

The 96-byte version-2 envelope binds raw BPF_PROG_LOAD flags, interface, GPL
status, attachment BTF/function and target, and the original source program ID.
Sealing pins the source/target programs; verifier-side and JIT-side callbacks
compare resolved BTF, token and device objects, as well as every serialized
attribute. The original source BTF object and main function prototype are
forwarded into the actual stub and checked against the pinned original.
Mutation releases the pinned references. The kernel patch includes the small
GPL exports used to pin/query those existing kernel objects.

The new typed C context entry has a checked 16-byte layout (all four offsets,
not just sizeof), version 1, raw flags, signed token FD and zero reserved word.
The old C entry remains a zero-flags wrapper. Original flags that differ reject;
the loader preserves actual non-GPL licensing. The bound-proof capability
version stays 1; the private input marker ABI stays 2. The fidelity probe now
copies libbpf's real expected attach type and flags.

`make -C kprog/tv check`, x86 kernel/loader regression and Arm kernel regression
pass. They reject all eight load-context metadata changes at seal, flags/GPL
mismatches before proof lowering, and C-context ABI/reserved drift. Closing the
original FD after sealing retains its pinned identity. Exact nonzero flags and
non-GPL native execution pass. Existing BTF-name collisions, DATASEC, map/helper,
immutable data, chunk ordering, generation and input-ABI regressions still pass.
The real C API propagates nonzero flags through sealing, verification and native
execution. The initial loader fixture omitted libbpf's actual XDP attach type;
that rejection is retained and the fixture now copies the captured value.
A development retry initially missed the diagnostic-call BTF-FD argument; its
compile failure is retained and both calls now pass the same pinned BTF FD.

All 13 original Arm helper/map programs also pass kernel and context-bound
native execution via the new library. Their per-program raw outputs are in
`helper-map-arm64-context-v2/`. The exact runtime initramfs, source and compiled
inputs are in `context-v2-inputs.tar.gz`. No program is removed or relabeled a
translation certificate by these functional checks. An additional loopback
fixture failed during the original kernel load, before binding; its log/source
are retained as a setup failure rather than a verifier rejection.

Both stock module sets, all 15 x86/11 Arm kinsn modules, and the actual Arm EFI
image were rebuilt. Modules_install and depmod succeeded. Immutable matched
runtime bundles live in the lane checkpoint area under `paired-context-v2/`;
the committed per-file manifests cover kernels, EFI, loaders and stock/kinsn
module trees. Source/core outputs from other lanes were not replaced. Full
per-program TV and its concrete entry witnesses remain active work; the
conditional composition theorem is unchanged and its trusted kernel binding
base now includes these context and BTF-prototype checks.

Application-configured proof map capacity
----------------------------------------

Real application map declarations can have zero max_entries until userspace
configures the map. The proof binder now sets that noninternal declaration's
capacity from the exact original application FD before strict shape validation
and reuse_fd. This addresses the two real BCC capable declarations without
creating a replacement map or substituting another program.

The actual x86 kernel/C loader regression passes a clang-produced zero-capacity
proof against a configured original map: bound native execution returns 2 and
the loaded program retains that exact original map ID. A declared nonzero
capacity that differs from the original rejects. All prior binding, BTF,
context, DATASEC, helper/map and readonly tests also pass. Both architecture
libraries build; kernel/module wire ABI stays at version 2. Sources, both
capacity variants and native/BPF artifacts are retained in the input archive.
Updated libraries are separately snapshotted under the lane checkpoint's
context-v2-map-capacity/ directory for use with the existing matched v2 pair.

Internal DATASEC identity across object names
-------------------------------------------

libbpf prefixes default internal map names with the object name. Matching the
entire proof name against the original therefore disabled vfsstat's real .bss
map. Both compiled-object and separately loaded raw-proof paths now select the
original FD by canonical BTF DATASEC section and exact variable names, offsets,
and sizes. Kernel object prefixes are not section identities. Multiple matching
original map IDs reject rather than choosing one.

Actual x86 kernel tests pass for differently named original/proof objects, both
.bss and .rodata, retaining the exact original map IDs and returning 2 through
generation-bound native execution. The raw-proof path also relinks both data
sections. Renamed same-sized BTF variables reject in both paths; two distinct
original maps with identical BTF layouts reject as ambiguous. Existing capacity,
context, helper/map, readonly, entry, ABI and generation regressions still pass.
Host sanitizer checks and both architecture library builds pass. Raw logs and
exact fixtures/libraries are retained alongside this file. Updated libraries
are in the lane checkpoint's context-v2-datasec/ directory and use the existing
6836f7d44 kernel/module pair without a wire or C ABI change. This fixes binding;
it does not constitute a per-program translation certificate.

Actual tracing attachment context
---------------------------------

The real x86 loader now has an fentry regression attached to the kernel's
bpf_fentry_test1 target. Replacing its BTF target with bpf_fentry_test2 or its
expected attach type with FEXIT rejects at sealing. The exact context seals,
loads and attaches a generation-bound native return-zero body. The kernel's
tracing test-run invokes the actual target and the attached native program's
run_cnt increases. This checks attachment execution, rather than merely opening
a tracing FD. All previous kernel/loader regressions pass. The retained binary
archive includes the exact manifest header used, which contained lane C's
concurrent anonymous-selector work; that header is not part of this commit.

Shared kernel stale BTF repair
-----------------------------

The coordinator reported all custom module loads failing on the moving shared
kernel with duplicate bpf_prog BTF candidates. The kernel's BTF contained two
bpf_prog_aux layouts: current 1360 bytes/90 members and old 1352 bytes/88 members,
missing native_load_flags and native_load_ifindex. All 2502 recorded objects
that depend on bpf.h had newer mtimes than the header. An exhaustive DWARF name
scan found 958 current-layout compilation units and exactly one old-layout
unit: net/ipv6/netfilter/nf_defrag_ipv6_hooks.c. Its object mtime was only eight
milliseconds after the header edit, consistent with an overlapping compile
that read the old header before writing the object. The individual object's
DWARF independently confirmed the stale definition. No duplicate C declaration
or reference semantics defect caused this failure.

A top-level make -W attempt did not reach the recursive Kbuild compilation;
that failed repair log is retained. Touching only that source's mtime, then
ordinary make bzImage, actually rebuilt the object. No source content changed.
The resulting shared kernel has exactly one bpf_map, bpf_prog and bpf_prog_aux
BTF record. All 15 fresh kinsn modules insert together in actual KVM; all T
binding/loader regressions, including real fentry execution, pass on this
shared kernel. Reproduce the module load and regressions with
`taskset -c 8-23 make -C kprog/tv shared-kernel-check` after rebuilding the
kernel. This is a diagnostic correctness target, outside benchmark launchers.
The exact repaired bzImage, modules, config, symbol versions, before/after
layouts and exhaustive pre-repair DWARF evidence are retained. Frozen 6836f7d44
runtime pairs were neither modified nor replaced. Full TV remains active.

Actual kernel context expansions
--------------------------------

BPFPlatform.lean adds an explicit platform layer over the existing byte BPF
interpreter, without another native ISA. Its universal expansion theorem gives
real physical BPF execution, full state and identical ordered effects; success
reaches the complete conversion boundary or faults. Missing conversion,
original-instruction drift, premature boundary, forced successor, early return
and zero-length expansion reject. Faults preserve the virtual PC and pointer,
rather than inventing a zero load. Axioms remain propext and Quot.sound.

Actual clang-produced field fixtures were loaded under the paired x86 kernel
and their raw and translated byte streams captured. The six fields produce
1/1/1/3/2/3 physical loads: data/end/meta retain all 64 pointer bits, while
interface and queue lookups retain every ordered access and scalar width.
The egress program uses BPF_XDP_DEVMAP explicitly; the kernel rejects it under
ordinary XDP. The initial masked-pointer fixture also correctly rejected and
was replaced with a field read that preserves the pointer. Raw setup rejection
logs are retained. No native program is executed by these capture fixtures.

Lean checks the actual captured bytes and rejects four mutations (pointer
width, physical end offset, nested-load order, erased access); an unchanged
copy passes through the same extractor and semantic checker. Logs, all six
per-program raw/translated/context records, generated Lean definitions,
mutation failures and compiled inputs are archived. This discharges a platform
component required by the real simple micro; native block state projection,
private spills and full per-program certificates remain active work. Binding
and the conditional composed theorem do not substitute for those certificates.

Explicit readonly object identity
--------------------------------

The loader consumes C3b19ec714's exact canonical readonly object table and A/C's
proof ELF metadata. Each private DATASEC has one complete BTF variable, its
explicit native symbol and size, and a checked final native blob extent. The
same mechanism serves manifest proofs and already-loaded raw proofs. Byte
search is removed; identical bytes at different native addresses remain
separate objects. The cache includes the exact native extent table. Kernel
kind8 byte/identity/freeze/address/relocation checks remain unchanged.

Actual x86 tests pass for two identical constants through both manifest and raw
proof loading: bound native execution returns2 and the raw program retains two
distinct private map IDs. Missing raw ELF metadata rejects. Changed data bytes
reject, and existing binding, context, FENTRY, DATASEC, helper/map and capacity
regressions pass. A handwritten fixture initially supplied a C source symbol
while its native relocation used a canonical section symbol; exact lookup
rejected it. The final fixture exports named objects to test the named-symbol
contract; C's committed tests cover canonical section keys on both ISAs.

Host ASAN/UBSAN checks reject duplicate/unknown fields, versions, fractional or
overflowed integers, bad sizes/bounds, missing native symbols and malformed
JSON. Both architecture libraries and the real micro runner build. The runner
now forwards its actual proof ELF and source attach type/flags, preserving the
same binding contract as application loads. Readonly DATASEC regressions query
the actual original map count as private declarations are added, while checking
every retained map ID against the original set.

The new library requires a native-link with --output-data-layout and proof
objects regenerated with explicit metadata; it does not change binding wire2
or the C shim API. Compatible libraries are snapshotted separately under
context-v2-rodata; frozen6836 kernel/module pairs remain intact. Actual Arm
loader execution and all per-program translation certificates remain active;
these x86 binding tests and cross builds do not claim those results.

Application-configured map value size
------------------------------------

The real BCC capable stack-trace map declares both value_size=0 and
max_entries=0; its application configures the actual values. The proof binder
now adopts an undeclared noninternal value size from the exact original FD,
alongside the existing capacity adoption, before strict shape validation and
reuse. An explicit nonzero declaration remains strict. Internal DATASEC maps
are unchanged. The actual x86 kernel/C API regression accepts a proof declaring
both fields zero, retains the original map ID and returns2 through native
execution. Explicit size8 versus original4 rejects, as does the existing
capacity mismatch. All earlier regressions pass; the Arm library builds.
The fixture uses explicit key_size/value_size declarations like capable, so it
does not depend on libbpf retrying a partially typed map without BTF. Updated
compatible libraries are separately snapshotted under context-v2-map-value;
the new readonly native-link interface remains required.

Coarse-clock helper identity
---------------------------

The loader's public helper-symbol table now includes helper160,
bpf_ktime_get_coarse_ns, needed by a real startup probe reported by C. Actual
x86 tests exercise the real helper through raw proof and clang-compiled proof
loading, sealing and native execution. Both return the expected fixture result;
existing different-helper identity negatives and all prior regressions pass.
The Arm library builds. This adds symbol resolution rather than another ISA
model or a fabricated helper result. C owns the typed simulator dispatch and
its formal contract for the startup probe itself.

The existing compiled input and CMOV component proofs, context-expansion
proofs and all their byte-mutation negatives also pass against V's updated
memory reference. Their raw combined log is retained; these are component
proofs, and no whole-program TV status is inferred from their success.

Attachment-specific get_func_ip helpers
--------------------------------------

Kernel helper173 has distinct tracing, ordinary kprobe, kprobe-multi/session
and uprobe-multi/session implementations. The generic public helper name has
no kallsyms address. The loader now carries the captured expected attach type
into its contextual helper selection and wanted-symbol set, including the
closed link-plan helper list. It selects the same implementation as the
kernel's actual get_func_proto callback, with no address guess.

Actual x86 tests pass for all five probe attachment profiles (0/42/56/48/57)
through generation-bound load/JIT admission; these probe cases are load-only.
The fentry positive now calls helper173 in the bound native body and executes
attached to the real bpf_fentry_test1 target. Its original kernel program also
calls the same helper. Wrong tracing target/type negatives and all existing
binding regressions pass. Both architecture libraries build. Latest compatible
libraries are under context-v2-func-ip; binding wire2, C shim ABI and the required
readonly native-link interface are unchanged.

Actual clang store-width counterexample
--------------------------------------

`simple-arm64-before-width-inputs.tar.gz` retains the exact 84-byte native
entry/text including its return trampoline, 224-byte/28-instruction clang BPF
entry, generated C, both disassemblies, and frozen production specialization
dependencies. The canonical ISA step functions, rather than disassembly or a
second interpreter, evaluate native PCs44/48/52/56/60/64/68/72 and proof PCs14
through26. At the matching successful-block entry, the native writes widths
4/1/2/1 at data+3/+7/+0/+2; clang writes eight individual bytes at
+3/+4/+5/+6/+7/+0/+1/+2. Both return2 and produce equal packet bytes, but the
requested ordered address/size/kind traces differ. The Lean result is a real
compiled-block counterexample, not a positive whole-program certificate.

`simple-arm64-counterexample.log` checks both concrete effect lists, their
strict inequality, equal packet bytes, and existence of actual reference
executions using the generic checked-path soundness theorems. Those generic
theorems trust only propext/Quot.sound. The concrete evaluation uses
native_decide and additionally trusts Lean.ofReduceBool; no solver success
or clang correctness is assumed. The original direct reduction consumed too
much memory and was stopped; its raw attempt is retained. The completed run
uses a12GiB address-space limit and has no sorryAx.

A's production width repair is separately pushed as1d260495a. This archived
result preserves the before-repair bug; T continues on a newly compiled pair
and does not weaken the strict trace requirement. Full micro/application
translation validation and concrete end-to-end composition remain active.

Universal validation of the repaired compiled store block
-------------------------------------------------------

The new 84-byte native/224-byte clang pair is frozen in
`simple-arm64-after-width-inputs.tar.gz`. Decoder equations are checked by
Lean reduction against these exact ELF entry bytes. Full successful-state
theorems quantify over arbitrary architectural registers, flags, vector bank,
SP, memory values/permissions/initialization and every64-bit packet pointer.
They retain complete post-states and prove equality of guest memory and all
four ordered width4/1/2/1 effects, with native exit80 corresponding to BPF27.
Actual execution follows from the two generic checked-path soundness theorems.

`including_faults` has no permission precondition: it proves both checked
paths produce a successful transition certificate with identical memory,
effects and faults, and corresponding exact fault PCs or successful exits.
All16 permission combinations, including wrapping pointers and initially
uninitialized/unreadable memory, are covered. No extra guard is inserted
into either program. The successful post-state theorems cover all state
fields; the fault theorem compares memory/effects/fault/PC. Their printed
axioms are propext, Classical.choice and Quot.sound, without
Lean.ofReduceBool or sorryAx. BPF scalar stores now use the canonical
Reference.writeMemory instead of a separate byte-recursive update.

The unchanged actual pair passes, while six actual-byte negatives reject in
the same canonical decoder certificates: narrow store, wrong store address,
erased store, native wrong width, native wrong successor, and the original
before-width clang artifact. Raw per-case logs/artifacts are archived. The
existing BPF/input/CMOV/context checks and all their mutation negatives pass.
This is a universal certificate for the real store block. Full-program entry,
context access, private spill, preceding CFG and composition obligations
continue separately; no whole-program pass is inferred from this block.

Unicode metadata identity rejection
-----------------------------------

The old central JSON parser replaced every Unicode escape with a question
mark. The before run against the committed parser actually accepts native
layout symbol `\\u0061` (Unicode a) for a distinct proof symbol `?`. The
repaired parser decodes the exact UTF-8 identity; the same negative rejects.
Literal a matches its escaped spelling. Accented, Chinese and surrogate-pair
emoji identities decode exactly; malformed hex, unpaired surrogates,
non-scalar/overlong UTF-8 and embedded NUL reject.

The isolated after run uses precisely the proposed string-parser hunk and
the otherwise unchanged committed readonly metadata consumer. Both the
negative and full readonly metadata regression pass under ASan/UBSan.
The input archive retains old/new headers, the actual negative, regression
source and Makefile; no unfinished source-map consumer code is needed to
reproduce this result. This fixes an accepted metadata negative; it does not
add a whole-program TV claim.

Coordinator-requested disk cleanup
----------------------------------

Removed13,398 rebuildable object/archive files and unstripped intermediate
kernels only from T's two private kernel build directories:11.40GiB logical.
Filesystem free space increased from24GiB to36GiB (91% to86% used). The
compressed inventory records each removed path, size and reason. Final
bzImage/Image, vmlinux BTF, Module.symvers, generated headers, scripts/tools
and exported module trees remain. Both current paired-context-v2 runtime
bundles used by C/A/R, and the small complete shared-btf-fixed and older
paired-input-abi2 snapshots, remain intact. Shared vendor outputs, committed
evidence and unfinished source changes were not removed.

Original source-map sites and actual BCC probe
--------------------------------------------

The manifest now binds each imported native map symbol to an actual original
LDDW instruction index. The original program must retain the resolved kernel
map ID. Object/value kind and value offset come from source bytes, never
symbol spelling or a process-wide name search. Unnamed maps work. Exact
source templates may normalize only declared map-FD words; nonmatching
startup-program templates remain nonmatches. Duplicate/unknown metadata,
fractional/overflowed indices, continuation sites, invalid kinds and foreign
FD identities reject. Readonly/source metadata share one strict field parser.

Strong proof externs use the agreed version1 `.native_lab.source_maps`
section. The consumer checks actual ELF entry bytes and relocations, then
patches original map-object/value-base FDs while retaining clang's ADDs and
addends. It does not prepare a synthetic data map or reset live app values.
Kernel binding checks the exact derived value offset, including actual
MOV-constant/register-ADD sequences with CFG-bypass rejection. Existing
different-offset, kind, map-swap, frozen-data and context negatives still reject.

`source-map-bcc-probe-inputs.tar.gz` freezes C's real five-instruction BCC
global-data probe and its generated native/proof artifacts. The x86 KVM
regression substitutes only its runtime FD, checks exact source matching,
loads the original socket filter, binds the generated clang artifact and
executes original/native programs. Both write42 at offset16 in the original
32-byte map; all other bytes remain0xa5. Binding itself changes no map byte.
Unnamed object and value+offset1 cases also execute with the exact original
map ID. Wrong sites, foreign same-shaped maps, out-of-range values and proof
metadata mismatches reject. The complete earlier x86 kernel/loader regression
suite passes. ASan/UBSan host tests pass. Both libraries build, and the Arm
module passes the complete actual QEMU binding suite including exact derived
offset checks. New source-map userspace cases still need Arm execution.

Raw earlier failures are retained: unsupported native direct-PC32 data read,
then C's LEA-only fix against that folded read, then the real BCC proof's
register-zero ADD exposing the missing exact offset derivation. The completed
run uses the actual producer pair and checks that derivation. The own native
byte-read fixture materializes its pointer explicitly; C owns the additional
direct-PC32 memory-import repair, which remains active. A recursive Arm
kernel-build invocation after object cleanup was stopped; the final run uses
the retained exported Image through an explicit Make prerequisite override.
No shared image or current runtime pair was overwritten. These results
establish binding/runtime behavior, not whole-program translation validation.

Actual guard blocks and complete kernel program capture
-------------------------------------------------------

Both actual native guard blocks (PC4/8/12 and16/20/24/28/32) and their
compiled BPF paths now have universal complete-post-state and actual-execution
theorems. Every64-bit packet/end combination is covered, including wrapping
+8/+72 additions. Exact native flags, every register/SP/vector/memory field,
all BPF registers/memory and branch successors are retained. No memory or
helper effect occurs in these blocks. The canonical CMP/CCMP condition
lemmas check the real fallback2 and both condition outcomes. Their trusted
logical base explicitly includes Lean.ofReduceBool from bv_decide, alongside
propext/Classical.choice/Quot.sound. There is no sorryAx in the passing run.

Ten actual-byte mutations reject: the six prior store/CFG/before-width
cases and changed first-guard successor, bound, native condition and CCMP
fallback. Unchanged artifacts pass both store and guard certificates.
The initial single-unroll proof checked inefficiently; splitting at actual
3/5-instruction native block boundaries solves the same constraints quickly.
Failed development attempts remain in the development archive.

The complete actual clang/kernel program is captured with type6/attach37/
flags0, source ID and attach metadata. Its224bytes/28instructions differ
only at pointer loads0 and2: LDXDW/context offsets0/8 replace LDXW/0/4.
The extractor checks captured raw bytes against the actual ELF symbol extent;
Lean checks whole-array equality with the compiled artifact. This is an
x86-kernel platform capture for the Arm-native reference fixture, not a
claim that Arm hardware/kernel context conversion has been validated.

These are real per-block certificates and complete platform inputs. The
remaining entry/private-spill/return composition and explicit ISA CPU-profile
binding are still being implemented. No whole-program micro/application TV
status changes solely from these component results.

The original six-field capture regression also passes after the optional
whole-object capture arguments were added, including all four context-byte
mutation rejections (`simple-capture-default-regression.log`).

Fresh exclusive environment choices and generation binding
---------------------------------------------------------

The private kind5 marker carries the complete unsigned source PC, with
fresh0/1 failure status at each dynamic visit. Existing entry inputs retain
ABI2. Host hook values are explicit and checked. BPF proofs retain all other
registers, memory and effects and increment a ghost visit counter; an unbound
environment is an error. Actual clang markers for16 and0xfffffffc are checked.

The loader consumes A’s environment-layout API and matches actual native
opcode/width/release/PC to compiled marker positions. Kind9 descriptors are
sealed with the exact code, proof and other metadata. The kernel checks every
marker has exactly one matching descriptor against the final chunk’s proof,
including cross-chunk native sites, before instantiation and emission.

The complete new Arm kernel binding regression passes. Bound fresh choice
executes native code; unsafe success and failure branches both reject. An
unsafe path requiring unequal repeated choices rejects, detecting accidental
choice correlation. Cross-chunk positive executes. Missing/duplicate/wrong-PC/
wrong-proof-index/wrong-opcode descriptors reject. Standalone markers reject
with normal and forced constant blinding. All prior helper/map/readonly/
entry/ABI/context tests remain passing. The complete x86 loader/kernel suite
also passes and rejects Arm-only descriptors. Both loader libraries build;
all ten unchanged simple-program byte-mutation rejections still pass after
the BPF state extension. The failed initial bounded-run test (which omitted
EXIT) is retained alongside corrected finite-path results.

This result supplies the environment/binding mechanism. A’s production
conditional-store bridge and F’s canonical monitor/ordering/atomicity checks
remain part of the continuing whole-program work; this result does not
relabel the earlier accepted unsafe exclusive programs as rejected. Kernel
verifier range handling, descriptor matching and restoration join the
explicitly trusted binding code. The canonical ISA remains V/F’s single
reference, and the finite path/composition proofs retain their listed axioms.

Tracing perf/stack helper identity repair
----------------------------------------

The loader previously chose generic helper symbols for TRACING26. The kernel
delegates perf output25, stack ID27 and stack capture67 to raw-tracepoint
helper prototypes for these programs, across tracing attach types. This
explains a post-verifier exact-helper binding mismatch rather than a stock
verifier rejection. The selector now names those exact raw-TP functions.

Three actual clang-compiled fentry proofs and native inputs pass original
loading, generation binding, attachment and real target execution (positive
native run counters). Perf/stack-ID cases use original retained map identities.
The entire previous x86 loader/kernel suite also passes; both architecture
libraries build. The initial test used nonexistent C++ option fields and
failed compilation; its raw log is retained before the corrected public
proof-insns/proof-object interface run. Full application replay is performed
by C/A with their real startup captures; these controls alone make no claim
that every application now executes.
