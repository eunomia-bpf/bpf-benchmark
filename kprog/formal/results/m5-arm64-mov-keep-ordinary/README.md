# M5: complete ordinary scalar MOVK calls

`Arm64MovKeepOrdinary` composes 203 actual Clight transitions: allocated
MOVK dispatch27, destination read/merge/writer edge105, ordinary writer67,
generic completion3 and genuine frame free/return1. Actual pre-call Mint64
`Vlong` and Mint8unsigned tag0 loads survive allocation; producer storage's
write permissions supply both actual stores. No reader outcome is assumed.

`call_scalar_returns` retains the actual written memory, successful free,
old-frontier frame, final contents/nextblock and revoked Cur/Max permissions
for every generic local. `call_scalar_represents` compares paired stores
across allocation and free at the ORIGINAL before.nextblock, yielding the
complete GPR/SP/SIMD/NZCV relation. `call_scalar_all_behaviors` proves every
finite arbitrary-trace run is a silent prefix of that represented return,
every stuck endpoint equals it, and infinite execution is excluded.

`Arm64MovKeepNative.merge_low_word` proves the source's 64-bit mask/merge
followed by narrowing is LNSym's 32-bit insertion. The actual native write
then clears the upper32 bits. `native_step`, `reference_step` and
`call_corresponds` bind the complete source call to real decoded/fetched
MOVK execution with no prior error. All ordinary Fin31 destinations and
16-bit immediates are covered, X64 columns0..3 and W32 columns0..1.
The whole native wrapper advances PC by4, preserves histories and introduces
no new event or fault. No local ISA body, decoder or assumed step is used.

The existing shared stores-frame and return-stuck lemmas were exposed by
visibility changes already included in coordinator commit07d9c4c96; this
step reuses them without changing their statements or proofs. The previous
24 live encoder metadata records still apply to unchanged op5/IMM/AUX inputs.

Validation and the reference-binary rebuild requested after the linker
cleanup are recorded in validation.json. Raw attempts, including the initial
X64 offset simplification failure and the missing-Coq build failure after
Workspace restart, remain under /workspaces/kprog-raw/formal/m5-arm64-mov-keep-ordinary.
The final full Lake build passes 321 jobs, all seven public type/axiom queries
pass, and all 23 regenerated exports are byte-identical (243,488,732 bytes)
to 9c617740f. Native/bitvector proofs use only standard axioms; relational
Clight contracts additionally retain the existing external-function and
inline-assembly parameters. Normal 200000 heartbeats/512 recursion remain.
The [reference rebuild and ARRAY repair](../reference-rebuild-20261119/README.md)
passes all 90 linked fragments. No benchmark or simulator C source is edited.

M5 and M6 remain open; complete ISA-handler/family count remains0. Relative
cache/materialization and actual frontend/provider/producer/caller admission,
native physical memory/alias/origin, Numeric initialization204 versus old189,
source control and all-family O1/O2/O4 recount remain. Remaining M6 follows
M5, with fresh final Lake and make check before goal closure.
