# Original fixture MOV_IMM call and priority successor

The actual generic call contract now returns the same final Storage together
with its real post-free GPR1 word (`mark` widened to 64 bits) and tag zero.
Both readbacks follow from the existing store certificate and canonical
ownership through the actual free frame; they are not inferred from the
register representation relation.

`Arm64ProgramEntryMovCall` caches the original exported source statements.
Its kernel-checked equations retain the mark Sset/Scall, successor, priority
Sset and next MOVK call statement. The actual fixture allocation establishes
the borrowed entry address and unshadowed execute symbol. Actual symbol 72,
the void/nine-argument signature and all C argument casts are checked in the
sole fixture/handler/Numeric world.

`enter` executes five real internal transitions from afterSetup: load mark
into `_t'168`, then call the actual handler with destination 1, SRC32, NONE
secondary sources, FLAGS8 and AUX0. `leave` resumes the actual source successor
in two transitions. `priority_ready` performs the four transitions that load
priority into `_t'167` and reach the next MOVK call statement.

`execute` composes those original caller edges with the complete actual
generic call/free. It retains the provider trace and reached heap, scalar
word/tag readbacks, writable producer Storage, nativeUpdate register relation
at the original frontier and actual generic-frame release. The original
context frame derives the post-call priority load at that same reached memory.
Mark and priority are unrestricted uint32 inputs. Provider origin reply/frame
and native register/physical-origin admission remain explicit invocation inputs.

The theorem stops at the original MOVK call statement. Its argument packing,
execution with unrestricted priority, fetched native instruction sequence,
all-outcome/final-return and remaining ISA-family obligations stay in M5.
No native MOVZ correspondence for arbitrary uint32 mark is claimed.

Validation: readbacks 226 jobs, final source edge 227 jobs and seven public
type/axiom queries pass at original caps on CPU 17, nice 0, one worker and
32 GiB address space. The whole `lake build KProgFormal` proof library/root
passes 276 jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Executable/tool builds are excluded under the current directive.
Initial finite failures and the recursion-limit attempts are retained in raw
logs; proof decomposition and restricted rewrites resolved them without raising
limits. Inherited logic/external-semantics axioms are recorded in validation.json.
Raw: `/workspaces/kprog-raw/formal/m5-entry-mov-edge`. M5/M6 remain open;
completed ISA-family count is zero.
