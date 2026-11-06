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
