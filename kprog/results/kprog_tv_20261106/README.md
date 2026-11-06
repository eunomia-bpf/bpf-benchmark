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
