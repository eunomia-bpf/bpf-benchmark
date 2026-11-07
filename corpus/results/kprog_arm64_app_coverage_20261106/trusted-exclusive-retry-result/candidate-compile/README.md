# Private exclusive-retry convergence compiler check

The proposed two-file kernel change compiles to an AArch64 relocatable C object
using the existing ARM Kbuild/config and compiler. This is an external-object
type/code-generation check, without modpost, kernel link, boot or loading. The
first incorrect absolute Kbuild target error and corrected relative-target
command are retained. No shared kernel source, Image/module or ARM producer changed.

All seven assembly fixtures generate and compile through the canonical ARM
worker: two safe private retry shapes, unsafe memory on a later failure, unsafe
memory after later success, a failure-dependent pointer used after the loop,
unsafe first-failure memory and a marker-free infinite native loop. These are
compiler results only; no candidate verifier/runtime acceptance is claimed.

`summary.json` records actual object/config/source hashes and each compiler case.
`inputs.tar.gz` contains the proposed patch, original/modified kernel sources,
object/Kbuild dependencies and command data, assembly/ELF/generated C/BPF, logs
and CONTRACT.md. The contract separates inductive proof memory safety from native
termination: both dynamic exclusive outcomes and original native instructions
remain, using exact state/SCC propagation. The sealed proof is restored before
JIT emission; ordinary BPF/kinsn and marker-free loops retain termination checks.
This source argument is not a proof of kernel SCC soundness or actual admission.

The BCC guest closed while this archive was prepared; its completed input pins
remain unchanged. Candidate kernel checks, delayed-branch/read-precision behavior,
existing safety regressions and a successful application run remain open.
