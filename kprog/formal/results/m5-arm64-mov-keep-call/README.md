# M5: complete MOVK WZR/XZR call and checked native correspondence

`Arm64MovKeep.call_zr_returns` composes all 156 actual Clight transitions:
27 allocated dispatch, 87 destination-read/merge/writer-call, 38 real writer,
three generic completion steps, and one successful free/return. Both callee
continuations are genuine `Kcall` values. The zero read derives its result;
the writer retains its eager SP read using the same actual producer storage,
carried through allocation. Selector31 is the zero register, distinct from SP32.

The original allocation and unshadowed-name lemmas and generic completion
lemma are now public and reused without changing their proofs or statements.
Every generic local loses its Cur/Max permissions on free. The source call
preserves contents and both permission maps below the original pre-call
frontier. Its complete post-memory retains the fresh allocation frontier;
it is not identified with the pre-call memory. The complete contents and
nextblock equal those of the actual allocated memory before it was freed.

`call_zr_represents` transports the full GPR/SP/SIMD/NZCV relation through
that actual free at the original reader frontier. `call_zr_all_behaviors`
proves every finite arbitrary-trace execution is a silent prefix of the same
represented return, every stuck endpoint is that return, and infinite
execution is impossible.

`Arm64MovKeep.Zr.native_step` uses the real LNSym decoder certificate,
fetched encoding, initial no-error state and move-wide opcode3 with Rd31.
All 16-bit immediates and legal W32 columns0..1/X64 columns0..3 are covered.
It does not assume an execution result or install a local ISA body.
`reference_step` retains the exact native wrapper, PC+4 and existing histories,
with no new event or fault. `call_corresponds` composes that checked step with
the actual 156-transition Clight call and final original-frontier register view.

The preceding [source contracts](../m5-arm64-mov-keep/README.md) retain the
actual emitter metadata audit (24 records), actual DST read and insertion
equation against LNSym's public `partInstall`. The live Python frontend itself
is not formally verified. Source merge lemmas admit all four columns; native
W32 legality remains an explicit condition.

Validation is recorded in `validation.json`: focused proof, six public
type/axiom queries, one final full Lake build and direct comparison of all
23 exports with `9c617740f`. Normal limits remain 200000 heartbeats, recursion512,
one worker, 32 GiB address space, CPU17 for builds/18 for queries and edits,
and every host command under timing SH. C/runtime remain unchanged. Native
`make check` is not repeated for this Lean-only step; last complete PASS is
`5236c0e9677f635526fdd515cde5195b2ba0810c`.

M5 and M6 remain open; complete ISA-handler/family count is **0**. Next is
ordinary MOVK's real reader in the linked Numeric environment and actual
continuation, deriving the returned scalar/materialized value and post-memory.
`ValueRep` can hold `Vptr` and does not establish the required `Vlong` result.
Native W32 insertion/upper-bit clearing, actual frontend/provider/producer/caller
admission, physical memory/alias/origin, Numeric initialization204 versus old189,
source control and all-family O1/O2/O4 recount remain before M6 and fresh final
Lake/native checks.

Raw: `/workspaces/kprog-raw/formal/m5-arm64-mov-keep-call`.
