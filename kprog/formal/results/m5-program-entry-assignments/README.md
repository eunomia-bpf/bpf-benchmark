# Actual production entry assignments

The actual exported arm64 function initializes its twelve scalar header
pointers in 36 imported Clight transitions. The proof derives all pointer
readbacks, preserves every load from other allocated locals, frames the
original caller blocks, and retains permissions and the allocation frontier.
The subsequent memory needs only the original allocation permissions; its
contents, temporary environment and continuation are arbitrary.

Generic scalar-store equality retains store failures and bitfields across
composite environments. Assignment transport reuses imported evaluation,
cast and store operations and gives exactly the source post-memory. The
actual header derives field and RHS correspondence from the existing
allocation/expression/field laws. Array decay and address-of require no
preinitialized values. The same Mem.store witness supplies source assignment
and production execution; provider initialization is not replayed.

The source certificate cuts the actual production body after 419 spine
statements. It checks all twelve mapped assignments and retains the actual
production successor tail. A mapped producer tail was a diagnostic intermediate;
the final theorem uses only these actual production endpoints. This region
still needs composition with the rest of initialization and native admission.

Final focused check: 167 jobs pass. Final full Lake: 342 jobs pass. Nine
public theorem/type/axiom queries pass. Scalar/expression/source laws use
standard logical axioms. Execution laws additionally retain the imported
CC.externalFunctionsSem and CC.inlineAssemblySem through the CC.Step2 alias;
AxiomOrigin.lean records the diagnostic. No new axiom or external transition
is added. Narrowing the assignment proof to its constructor does not remove
those inherited dependencies. Initial failed proof attempts and the first
full/query batch remain raw; final receipt names the superseding checks.

Run from kprog/formal on CPU17 with LEAN_NUM_THREADS=1 and 32 GiB AS:

```
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryAssignments
lake env lean -j1 results/m5-program-entry-assignments/Query.lean
lake env lean -j1 results/m5-program-entry-assignments/AxiomOrigin.lean
lake build
```

Host checks use CPUs 8–23 without the timing lock under the coordinator's
2026-11-19T18:18:59Z rule. C sources, benchmark settings and runtime inputs
are unchanged. The previous export comparison and whole make check are
identified as historical in validation.json; neither was repeated here.

M5 and M6 remain open. Completed ISA-family count stays zero. Next:
transport the actual 64 null vector-pointer stores, then the remaining tail
and full input-prefix/global/continuation/native binding; recount O1/O2/O4,
finish M6 and run fresh full Lake plus make check.

Raw: /workspaces/kprog-raw/formal/m5-program-entry-assignments
