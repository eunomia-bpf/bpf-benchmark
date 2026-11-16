# Actual x86 producer program composition

The real parser and renderer consume `oracles/x86_program_profile.S`: a native
entry with two CALL sites sharing one clock-calling subroutine. They derive a
48-byte frame, six named fact cells and return offsets 15/24. The generated C
retains those labels, CALL/RET operations and the actual return dispatch table.
The existing driver relocates only its relative header include.

`KPROG_X86_PROGRAM_EXPORT` includes `X86ProgramCallees.h` before the inline body
definitions. Its public libbpf-typed declarations replace integer-valued helper
pointers with explicit named platform callees. Native preprocessing keeps the
existing route. No instruction/helper body, state representation or input
initialization is copied. The compiler checks all 81 external callee types
against the real public pointers before their names are rebound. Actual
ID-selected kernel targets and effects remain M5 obligations.

The export contains 126 internal functions/21,189,154B. Exact regeneration and
all 18 earlier ASTs remain byte-identical. `make clight`, all 19 Clight modules/
56 Lean jobs and five standard-axiom queries pass at unchanged limits. The
Clight check uses mature composite construction and label lookup: frame 48,
the typed external clock, its actual helper-body call and both exact return
continuations are checked. This is computation over real exported data, not a
refinement theorem. Extraction preprocessing is 2,618,469B for 3,804B of rendered
source; it is not an application compiler performance result.

Native and named-callee/CompCert executions agree on all 42,496 capture bytes,
without masks. Each mode runs 32 independent high64 stack-base/clock-return
cases and 32 nonreturning second-helper prefixes. Normal cases consume 63 entry/
clobber/release inputs and two helper events; refusal prefixes consume 41 inputs
and two helper events. Independent expected arithmetic folds high clock and SP
bits into the result. Five negatives catch an unknown first return case, wrong
helper ID, low32 stack-base image, omitted RET release inputs, and a mismatched
callee return type. The first two also check the exact pre-refusal prefix.
Normal products and the ABI object are rebuilt and rechecked afterward.

The host environment gives the producer's specialization-refusal declaration
an always-inline, nonreturning observer body. This permits runtime inspection
of the table's default branch without removing the producer's error attribute.
The Clight export retains the original declaration, and these tests do not
assert arbitrary invalid native programs have defined Clight behavior. Valid
program branches and the helper operation remain unchanged.

Default BPF allocated sections/relocations match header revision `eca861996`
and ordinary current builds: program socket 1,704B/three relocations, existing
inline fixture 1,448B/11, producer frame 376 fixture 5,184B/24. All phases use
the current fixture source. These are compile comparisons; stock acceptance,
full default/application bytes and kernel helper equivalence are not claimed.

Reproduce with `make clight`, the Clight Lake targets, and
`lake env lean -j1 oracles/test_x86_program_profile.lean`. The committed
`compare.py --output <new-raw-directory>` reproduces captures and negatives.
All full commands, captures, initial include-order failure, unbound-ID diagnostic
AST and native replay include-chain correction remain under
`/workspaces/kprog-raw/formal/m4-x86-program`. M4 remains open for remaining
producer/C-subset/default-byte work; all 2,065 M5 refinements/recount and M6
retirement follow. No theorem migration is inferred here.
