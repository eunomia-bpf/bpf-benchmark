# Independent review of ARM exclusive-retry convergence candidate

F reviewed A's private patch SHA256
`2480264e275e8dafab9f745b36f788075f2d32d373771b3780c1bf0005dcb2f3`.
Both baseline kernel source hashes match A's input manifest. This is a
source/contract review: F did not apply, compile, boot or load this patch.
`inputs.*` retain the exact candidate, its manifest, baseline kernel sources,
canonical exclusive definitions/refinement, and the existing loop diagnostic.

The candidate keeps a fresh0/1 store outcome and invokes the existing exact
abstract-state/SCC machinery after an exclusive visit in a sealed proof region.
This can be evidence toward an inductive memory-safety argument. It does not
supply a bound, progress measure or eventual-success guarantee for native retry.
The canonical environment is explicitly per dynamic attempt and permits
repeated failure. The existing iterator exception separately depends on its
sticky-NULL termination contract. Consequently, this candidate alone does not
close the user's O3 requirement that unbounded native loops be rejected.
No hardware fairness, forced store success or artificial runtime fuel is assumed.

Two details matter for the requested safety validation:

- Eligibility checks the enclosing native proof region and a changed visit
  counter. These establish neither a retry-loop identity nor a progress
  relation for every affected cycle. The loop-scope and liveness argument
  remains for A/T to resolve; this review does not prescribe an implementation.
- `states_equal(..., EXACT)` is the verifier's predicate, using live-register
  `regsafe`, `stacksafe`, `refsafe` and frame/callsite comparisons. It is not
  a byte-for-byte comparison of every field. Retaining `loop=true` and `hit`
  preserves the existing SCC/backedge read/precision path, which is essential
  for delayed branches and separate callchains. Its behavior under this new
  eligibility rule still needs actual candidate validation.

The existing ARM `unbounded_loop` fixture is rejected by the loader with:

> trusted-native-loader: native_kernel bound proof contains no BPF exit; insns=1 0:0x5

That rejection occurs before the proposed convergence branch. Passing that
marker-free/no-exit fixture cannot validate the policy for marker-bearing
cycles. This is a coverage/contract distinction, not a measured acceptance
finding. No new executable unsafe program was constructed for this review.

The independently running34-case canonical-worker regression uses the
unchanged kernel. Its eventual result must not be reported as validation of
this private verifier patch. Candidate unsafe acceptance remains unmeasured;
no complete memory-safety, termination or O1-O4 claim follows from this review.
`audit.json` records the source locations and each outstanding obligation.
