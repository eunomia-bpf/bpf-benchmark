# ARM exclusive retry: relation required by the current source

This is the FORMAL response to PERF's 2026-11-27T18:26:01Z request.
It fixes the relation boundary for choosing a common B form; it does not
certify a production rewrite or add an assumption to the current ABI.

## Decision

Keep the original per-visit load, arithmetic, Boolean failure query,
conditional store and Wstatus/CBNZ transition as the semantic unit.
A finite callback/chunk can implement a finite prefix of these units, with
three distinct observations: retry at the original loop head, original fault,
or original successful continuation. Exhaustion belongs to retry; it cannot
be treated as the native return, successful store, or fall-through.

Under ABI2's arbitrary per-dynamic-visit failure outcomes, a fixed finite
callback/iterator bound alone cannot give whole-program, terminating
input/output equivalence. Neither can replacing the block by one unconditional
atomic fetch. The exact unit can be used in a bounded prefix proof now;
a complete common lowering still needs either unbounded resumption with its
own verified continuation relation, or a different, explicitly justified
safety-proof construction. Neither mechanism is established by the current
216-site inventory or stock-verifier acceptance. This is a semantic dependency,
not a request to change the ABI, impose fairness, or cap native executions.

## Relation at the original loop head

Let R relate the actual Clight caller state, native LNSym checked state and
candidate B state at the decoded load address. R must retain the original
program/fetched words, continuation, error/fault state, all live registers
including SP, tags and pointer provenance, memory contents/permissions and
the chosen observer trace. Native exclusive monitor/platform inputs stay
explicit. Source external outcomes, supplied heaps and effects also stay
explicit; a volatile or external read is not assumed pure.

For each reached state satisfying R:

1. Couple the same actual exclusive load, including width, address/alignment,
   source read effects and native acquire/reservation observations. On a fault,
   relate the actual fault state before performing later arithmetic or choice.
2. Couple the real ADD/OR/AND operation at its architectural width, including
   the 32-bit zero extension and all live register aliases. Stable inputs in
   the census do not imply stable memory values across attempts.
3. Obtain one Boolean outcome for this dynamic store visit, not one outcome
   per static site or one cached result for the whole loop. Its coupling to
   the native monitor/translation/global/commit inputs must be proved.
4. Preserve original store rejection/SP checks and their order. On source
   failure, skip the memory-write helper, set zero-extended Wstatus to 1 and
   execute the actual CBNZ backedge. Establish R at the next load using the
   reached heap and trace. On success, use the genuine write effect, Wstatus0
   and the actual successor PC, retaining the last loaded/arithmetic value
   and all other live-outs. A fault during the write is not a successful exit.

The reusable safety obligation is entry implies invariant I; every actual
failed iteration from I is safe and re-establishes I; successful/faulting exits
have their original postconditions. This proves all finite failure prefixes
by induction, without choosing a maximum number of failures. A B verifier
proof of a bounded run from one concrete entry is not automatically this
inductive invariant certificate.

For an exact finite-prefix relation, quantify over every finite sequence of
supplied outcomes, actual load effects and matching platform inputs. Compose
the SAME reached states and traces at each retry boundary. For complete
behavior correspondence, also account for an infinite all-failure run;
finite-prefix existence by itself is not a termination or divergence theorem.
Any stuttering/projection must be declared and must preserve faults and
external observations. An empty silent step cannot erase an observable load.

## Two concrete obstructions to shortcuts

For any fixed bound N, choose N+1 failed visits followed by success, all with
valid stable memory and stable operands. The original source reaches its
successor only after those visits. The N-visit candidate reaches exhaustion
earlier. Treating exhaustion as a normal exit changes the continuation and
possibly memory/status; treating it as refusal or abort changes the outcome.
The infinite all-failure stream exposes the same missing behavior. This is
a reasoning counterexample, not a new measured workload or Lean theorem.

There is also a fault-domain difference that an unconditional whole-domain
source/native relation must resolve. LNSym Exclusive_single.lean, checked
mode, lines53-55, tests writable permission when virtualPass is true EVEN IF
the local/global monitor will fail. The current simulator failure branch in
arm64_sim_local_bpf.h lines1938-1942 skips MEM_WRITE_REG and writes Wstatus1.
Consider an aligned, non-SP, legal non-overlapping STXR, with virtualPass=true,
failed local monitor, and readable but non-writable target memory. The
preceding LDXR can read; the checked native store faults on write permission
before recording its attempt/status, whereas source failure skips that
memory-write check and continues with status1. This follows from the two
actual function bodies, not from an observed application fault. A proven
loop-head permission invariant may exclude this state; do not silently assume
that invariant for every captured block. Existing check_reference_exclusive.py
lines67-85 explicitly retain the native permission-before-monitor cases.

Native attempt/reservation and ordering events are also retained in LNSym.
ABI2's one Boolean is not by itself a proof about monitor clearing, acquire/
release order, external interference, or all these fault paths. The existing
numeric status macro is not a whole-loop memory/ordering refinement theorem.

## Applying the relation to PERF's common form

The 70-request/216-site/33-distinct-source census supports using one unit
schema for the recorded 32/64-bit ADD/OR/AND forms, with their original order
bits. It does not establish an inductive memory invariant, entry closure,
or a whole-program replacement. All70 requests contain indirect control;
zero parsed direct branches into the middle does not close indirect targets.

A resumable chunk must carry the actual loop-head/success/fault PC, whole
required live state, reached heap, trace/effect state and any native
reservation state. Calling a chunk again must neither replay earlier effects
nor reset failure choices. Such resumption is an obligation on a proposed
implementation, not a new runtime interface installed here.

A proof-only loop summary could instead supply an invariant and prove
safety for each arbitrary failed visit plus the successful continuation.
It must connect that certificate to the actual stock-B verifier semantics
and the same native/source domain; simply making B return after one safe
iteration does not prove safety of the original whole P.

No bounded total B form is admitted as an exact whole-program implementation
by this record. PERF can choose the implementation route autonomously against
these obligations. Canonical/runtime headers, compiler flags, kernel,
benchmark and active Tetragon inputs remain unchanged. M5/M6 and theorem
counts are unchanged. This source-grounded analysis has no new kernel-checked
theorem or production acceptance claim.

## Evidence and validation

[evidence.json](evidence.json) pins the source bodies, ABI header, native model
revision, captured counterexample source trace and PERF contract/census.
Line references above were checked in those pinned bytes. Validation was a
focused source/diff/links review; no additional Lean build or test was needed
for this content-only decision. The already-running GPR execution full-root
check continues independently.
