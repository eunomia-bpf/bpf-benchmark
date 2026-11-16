# Actual ARM combined-reader prefix

`Arm64RegisterReads.gpr_read_prefix` proves 55 actual internal Clight
transitions of the exported `kprog_arm64_program_read` for every GPR index
0–30. It follows the entry's individual raw and tag pointer tables and reaches
the actual inlined materializer with their loaded values. Complete memory is
unchanged. The premise uses the actual imported loads and ulong cast; it does
not assume a dense register bank or invent native pointer bits.

The ordinary constructor equations shared with `Arm64OriginCache` now live in
`StepEquations`; the actual interpreter and existing cache contracts are
unchanged. Extraction of the stages is checked from the generated function
body by the kernel.

The focused build passes 143 jobs at default limits. The public axiom query
reports only `propext`, `Classical.choice` and `Quot.sound`. Raw attempts are retained
under `/workspaces/kprog-raw/formal/m5-program-read`. The relative-tag combined calls,
their warm/cold cache and invocation-origin binding remain M5. This is a prefix
law and adds zero complete ISA-handler refinements.

Reproduce: `lake build KProgFormal.ClightRefinement.Arm64RegisterReads
KProgFormal.ClightRefinement.Arm64OriginCache`, then
`LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-program-read/Query.lean` from `kprog/formal`.

The prefix now composes with an 18-transition materialization tail to prove the
complete actual `program_read` call for all 254 non-relative tags. The public
`gpr_read_nonrelative` law quantifies every GPR index, represented scalar or
pointer, checked entry observation, memory and continuation. It executes 73
internal transitions and returns the same loaded value with complete memory
unchanged. It requires no cache, native-input-provider or dense-bank premise.

`gpr_read_return_corresponds` covers every proposed Clight return at `Kstop`,
with empty trace, original complete memory and `ValueRep` at the M3 materialized
bits. Other continuations use the complete internal-run law; no external-call
determinism assumption is introduced. The default export's identity cell
selection is proved by its actual index expressions, not supplied as an
interpreter callback. Undefined/unbound values remain excluded by `ValueRep`.

The complete reader subset passes 141 Lake jobs at default limits. The two new
public statements and their axiom queries are in `Query.lean`; raw attempts and
query output are retained in `m5-program-read`. These remain helper-component
laws, adding zero complete ISA-handler refinements. STACK/RETURN warm and cold
paths, SP, producer initialization/compact maps, physical origin/cache/native
memory and general compiled control remain M5, followed by recount and M6
closure. This step changes no canonical C or Clight export.

The new relational laws report the three standard axioms plus clean's opaque
`CC.externalFunctionsSem` and `CC.inlineAssemblySem` constants, which occur in
the imported `Step2` relation. Their internal paths execute neither boundary.
No external determinism axiom, external outcome or new semantic axiom is used.
The executable 55-transition prefix still reports only the three standard
axioms. The query log preserves these exact dependency lists.
