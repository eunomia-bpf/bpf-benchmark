# M5: actual Numeric register storage and reader views

`initialized_storage` consumes the actual Numeric result afterVectorLoop and
reuses the existing memory-only RegisterStorage.of_header constructor. It
adds zero C transitions and replays no input or header execution. Bool-indexed
tables use the already derived word/tag resources; their slot reads, all
scalar header pointers, live vector pointers, access map and SP-zero read
supply the constructor. All62 word/tag cell write permissions derive from
actual allocation. No writable-storage premise is added.

Existing component reader laws derive every GPR value/tag observation,
borrowed SP zero, masked NZCV tuple and all32 low/high vector pairs at the
same reached memory/header. Binding uniqueness connects flag-pointer sources
to the actual flag input cells. Pointer-valued context remains permitted;
ValueRep is not treated as a claim that every value is Vlong.

The joint Arm64Registers.Represents relation is derived there for any native
state satisfying explicit GPR materialization, SP origin, NZCV and SIMD input
bindings. This conditional postcondition does not establish those native
same-invocation bindings. Consumer-continuation retention and native/provider
admission remain separate M5 obligations.

All92 header readbacks, previous data/block identities, cache resources/cold
values, initial204 global contents/permissions/allocation frontier, counter32,
ctx temporary and the same98 provider traces remain. The storage's existing
separation/freshness lemmas apply to the actual62 cells. No new ISA model,
C body, memory decoder or native address map is introduced.

Next is actual continuation-temp retention and caller/native input/original
context/provider admission, then relative caches, physical memory/alias/
origin/control and all-family O1/O2/O4 recount. Complete ISA-handler/family
count remains0; M6 follows M5. The separate x86 atomic/released-alias formal
bindings remain open. No C/runtime, benchmark, paper/design, kernel, base or
image change is made.

Raw attempts: /workspaces/kprog-raw/formal/m5-numeric-producer-register-storage.
Every host command holds timing SH. One-worker builds CPU17/32GiB;
reads/queries/Git CPU16. Default200000 heartbeats/512 recursion/asyncfalse.
Validation outcomes, retained attempts and public axiom sets: validation.json.

Final validation: full Lake passes 334 jobs; all ten public type/axiom
queries pass. Focused attempts are retained in validation.json. All ten Arm64
exports retain the byte baseline. The historical 23-file comparison records
12 changed x86 exports and exit 1; it remains an explicit
report, with no x86 atomic/alias proof claim. Current export bytes are
248620630; historical baseline bytes are 243488732. Native make check
remains due at final goal confirmation.
