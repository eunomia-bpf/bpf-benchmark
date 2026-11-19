# M5: actual Numeric continuation retention

All ten actual Numeric execution-stage postconditions now retain both the
original context and continuation parameters. No C transition, input visit,
provider premise or independent execution is added. Existing memory, trace,
storage and conditional architectural-relation properties remain.

The first30 GPR visits use their real input/result-temp frame and finite
source metadata to prove that _continuation is untouched. Its original
value follows from initialTemps. The x30-zero result-temp update is distinct;
the four flag and64 vector visits use their existing temp frames. Context
and header stores preserve the same temp environment. The final pointer loop
changes only _i, and memory-only storage/view construction adds no step.

The final actual afterVectorLoop result therefore exposes _ctx = ctx,
_continuation = continuation and _i = 32 together with all92 header
readbacks, earlier data, both cache resources/cold values,62 writable cells,
complete GPR/SP/NZCV/vector readers,98 ordered traces and the original204
global frame/permissions/allocation frontier.

This lookup fact does not establish that the supplied continuation denotes
the intended handler. Actual function binding/parameter ABI and call-return-
free composition follow next, as do native register-state/provider/original-
context bindings. The joint Represents postcondition keeps those native
bindings explicit. Relative caches, physical memory/alias/origin/control,
O1/O2/O4 recount and M6 remain open; complete ISA-handler/family count stays0.
No new ISA/C body, decoder, native address map or trusted axiom is introduced.
No C/runtime, benchmark, paper/design, kernel, base or image change is made.

Raw attempts: /workspaces/kprog-raw/formal/m5-numeric-producer-continuation.
All host work uses timing SH. One-worker builds CPU17/32GiB; reads, edits,
queries and Git CPU16. Default200000 heartbeats/512 recursion/asyncfalse.
The initial source read and editing session queued behind the timing lock;
the editing session expires when idle rather than retaining a lease forever.
Validation outcomes, retained attempts and axiom sets are in validation.json.

Final validation: full Lake passes 334 jobs; all 11 public type/axiom
queries pass. Focused attempts are retained in validation.json. All ten Arm64
exports retain the byte baseline. The historical 23-file comparison records
12 changed x86 exports and exit 1; it remains an explicit
report, with no x86 atomic/alias proof claim. Current export bytes are
248620630; historical baseline bytes are 243488732. Native make check
remains due at final goal confirmation.
