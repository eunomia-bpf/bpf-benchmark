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

- O1: lane V confirms its canonical byte-decoding, whole-state ISA step with
  memory/helper effects is not implemented. Its bounded handler contracts
  cannot substitute for that interface; lane F has real CPU counterexamples.
- O2/O3: there is no compiled-BPF semantics or per-block translation checker.
  The actual post-link, verifier-instantiated instruction stream has not been
  certified against native bytes. No second native ISA model was introduced.
- Application O4: the C loader entry supplies no simulator proof. The kernel's
  `validate_kinsn_proof_seq` forbids calls and pseudo map loads, so helper/map
  simulator proofs cannot use this interface. Real proof lookup/linking and a
  call/map-capable verifier-region protocol remain necessary. Original app BPF
  must not be substituted for the simulator proof.
- The TV entry relation must still establish the linked source entry, ABI
  compatibility and specialization fidelity. Kernel identity binding alone
  proves none of these semantic facts.

The exact trusted base is in [the checker README](../../tv/README.md).
It explicitly includes the verifier's privilege-dependent policy; the current
kernel permits uninitialized stack reads with CAP_PERFMON. Acceptance cannot
imply a stronger initialization property.
