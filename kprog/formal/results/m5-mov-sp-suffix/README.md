# Actual linked MOV_IMM cold-SP suffix

`Arm64MovImmediateLinkedRead.lean` composes the actual scalar branch with
reader 66, its cold STACK provider call at input 59, and writer 107 in the
fixture/handler world. The incoming SRC is 32. Both widths and arbitrary
64-bit immediates are covered, including every widened uint32 mark.

The shared suffix now takes its world/actual bindings, selector and returned
word. Its five-transition reader edge and eighteen-transition selection/
writer edge retain the real `_t'4` and operand temporary updates. The prior
NONE APIs instantiate these proofs with selector 255 and returned zero.

The linked proof retains the full provider trace and supplied memory. It
constructs post-provider cache storage, derives both real cache stores and
both GPR word/tag stores, and reaches the handler's actual Sskip/Kstop with
its frame still live. It derives the complete register relation for the
existing `nativeUpdate`, the original caller frame, and unchanged permissions
and frontier. It does not assume successful stores or a post-register relation.
The provider result/frame and pre-read storage/native relation remain explicit
invocation admission. No availability or production provider validity follows
from the host zero-origin fixture.

The theorem starts at the scalar branch. It does not yet establish dispatch,
handler allocation/free, the actual fixture callsite or a fetched ISA step.
At this receipt's source checkpoint, a closed query confirmed that the
fixture/handler world bound `kprog_arm64_mov_path` at block 98 externally;
the older 54-transition Numeric dispatch could not be instantiated there.
The [Numeric support migration](../m5-entry-support/README.md) now links the
complete exported unit and resolves that selector internally. Query.lean
tracks the new binding; the original validation/source checkpoint remains
recorded below. Fixture callsite/free and fetched ISA composition remain open.

Validation: shared 182 jobs, final linked subset 221 jobs, six public type/axiom
queries and one closed source-binding query pass at original proof caps.
Focused checks use CPU 17, nice 0, one worker and 32 GiB address space.
The first linked check also rebuilt the MOV dependents. The whole
`lake build KProgFormal` proof library/root passes 273 jobs on CPUs 16–23,
nice 19, one worker and 32 GiB address space. Executable/tool builds are
excluded under the current tool-build directive. Existing logic and external-semantics axioms are
listed in validation.json; no new axiom is introduced. Raw logs are retained
under `/workspaces/kprog-raw/formal/m5-mov-sp-suffix`. M5/M6 remain open and
completed ISA-family count is zero.
