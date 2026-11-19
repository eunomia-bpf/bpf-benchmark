M5: actual Numeric consumer boundary

The actual initialized_storage result now includes Boundary on the same reached
memory, temp environment and entry. The existing 98 visits, trace, data, storage,
reader views, cache resources and conditional architectural relation remain.
The retained continuation lookup and allocation access derive argument evaluation,
one silent sequence step and every producer local's Freeable range. No provider
premise or input visit is added.

Five Lifetime laws now take an arbitrary Clight world, with only composite
layout equality needed for return/free. Their original APIs are projections.
Boundary.call uses the actual retained target and requires genuine callee lookup
and the one-entry-pointer/uint32 signature, then executes exactly two silent
steps. call_after appends them to the actual initialization trace without replay.
return_releases_locals performs three actual return/free steps, retaining bytes,
nextblock and the old-block frame while making all declared local ranges
inaccessible. call_return composes a given body execution and its actual
post-body Freeable ranges with this suffix and preserves the combined trace.

The exported void/nine-argument program_execute handler has a kernel-checked
signature inequality with the continuation. The C extraction deliberately has
a program-body hole (formal/c/Arm64Entry.c); these theorems do not supply its
wrapper, its linked callee or body proof. Post-body ownership is an obligation,
not inferred from successful return. This is partial composition, not completed
native admission or an ISA-family result. Complete family count remains zero.
M1-M4 are done; M5 and M6 remain open.

Raw logs: /workspaces/kprog-raw/formal/m5-numeric-producer-consumer.
The first focused attempt found a reserved Lean parameter name; focused2 passes
191 jobs after the rename and complete composition. No runtime C, simulator,
kernel, image/base, benchmark, paper or design change. Original proof caps remain
200000 heartbeats and recursion512, async off, one worker, 32GiB AS, CPU17;
reads/queries/Git on CPU16, all under the shared timing lease.

Next: derive the source-grounded one-pointer/uint32 body wrapper/schema and
its actual binding, compose the ordinary MOVK handler through that wrapper,
and prove its producer-local ownership preservation. Native/original-context,
physical memory/alias/origin/control and all-family O1/O2/O4 obligations remain,
then M6 and fresh final lake build plus make check.

Final validation: full Lake passes 335 jobs and all 14 public type/axiom
queries pass. All ten Arm64 exports retain the byte baseline. Historical
comparison exit1 records 12 changed x86 exports; it does not
claim x86 atomic or released-alias correspondence. Current export bytes are
248620630; historical baseline bytes are 243488732. Native make
check remains due at goal closure.
