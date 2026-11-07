# x86 finite indirect control observers

All **35 forms × 1024 cases = 35,840 states** completed on the real x86-64
host CPU. CPU/production C, CPU/canonical reference and C/canonical reference
each have **zero mismatches**, with zero unavailable forms. The reference
build, native build/execution and canonical replay all exited 0.

The matrix contains CALL and JMP through each of 15 non-SP register targets,
two finite code choices (including a copied target), nested direct and
indirect calls, and an actual stack-return-address load. The target value in
RSP would also change CALL's stack; these observers keep the native call
stack inside its captured memory. `forms.tsv` and `reference-forms.tsv`
report all per-form counts. Empty compressed JSONL streams contain no
counterexamples; their schema records complete state/memory inputs if a
comparison fails.

The native CPU executes the actual instructions. The C side uses production
`indirect_targets`, `append_branch_or_ret`, finite dispatch and CALL/RET
macros. Its unresolved-target declaration is the production compile-error
attribute, so a dispatch alternative left by specialization fails the host
build. The adapter supplies only objdump instruction extents and
serialization; every successor, architectural state and memory event comes
from the single canonical instruction step. No branch condition is modeled
in the adapter. All final arithmetic flags, including PF/AF, are compared.

The captured code origin is 0x1000000. The final native JMP is an explicit
outer observer boundary; internal CALL/RET and stack writes are observed
normally. These are finite CPU fidelity observers, not an application
invocation/platform/ABI proof or acceptance of real bound manifests.
`summary.json` pins the canonical path lengths, exact binaries and both full
state traces retained in this Workspace. `compiled-inputs.json` and its
verified archive capture the actual producer/header snapshot, generated
code, observer sources and five-module canonical source closure.

The original c110 reference lacked FF /4 register JMP decoding: after
observer0 passed it rejected JMP RAX (`ff e0`) with `reference: expected
two-byte native opcode`. That complete failure input, original successful
35-form CPU/C result, binary and source closure remain in `attempt-c110`.
The minimal five-line decoder addition maps FF /4 register operands to the
existing unconditional branch step; no canonical execution primitive or
production simulator changed. The full unchanged 35-form matrix was then
rebuilt and replayed. Historical 1080-form and ARM c110 results are retained.

```sh
taskset -c 16-19 make -C kprog/fidelity x86-control-run CASES=1024
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-control/Makefile reference-build
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-control/Makefile reference
```

The reference-build target uses the private incremental canonical input
snapshot under `build-x86-control/reference`; it does not mutate another
lane's shared Lake cache. The exact compiled source and executable are also
archived here for reproduction.

The published Make rule also names the transitive helper/ABI/header and
TCB-import dependencies for correct incremental regeneration. Compiler
arguments are unchanged; the archive retains the Makefile actually used.
