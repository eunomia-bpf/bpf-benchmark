# M5: all 30 GPR inputs in the initialized Numeric world

The existing register-declaration call and return/store proofs now accept
an execution world, actual symbol/fundef64 binding and matching source
composite layout where needed. Their source bodies, declaration metadata
and memory-store construction are reused. The separate x30-zero law is also
parameterized; all prior standalone public statements remain projections.

`ProviderAt` names the real world's externalCall/Senv instead of identifying
it with the old world. The old `Provider` API selects its original world.
The existing suffix induction now executes in that explicit world and derives
all 30 word/tag readbacks with provider traces concatenated in source order.
Provider full post-memory, local-preservation/access/frontier ABI and caller
framing stay explicit. These conditional outcomes do not implement the native
protocol or prove its ABI admission.

`initialized_gpr_inputs` starts with actual Numeric initialization. Its 580
prefix and 9 RAW setup transitions reach declaration 0 before its call. The
actual 30-call sequence executes x0..x29 exactly once, retaining both temporary
updates per return, then stops at the x30 declaration before its separate
zero branch. The x0 call remains even though later RAW processing overwrites
its value. All source word/tag data are derived from actual admitted outcomes,
rather than supplied as an initial register relation.

Both actual caches remain cold through setup, providers and declaration
stores. The source `_ctx` temporary is retained. Every initial global below
the original 204 frontier retains contents and both permission maps; allocation
access and nextblock remain. The result keeps the real final temporary env,
all 30 ordered traces and actual allocated word/tag bindings. No empty-trace,
post-memory=pre-memory or whole-Genv/Senv equality is assumed.

The x30 zero/table prefix, four flag and 64 vector visits, native/provider ABI
and caller admission, complete register Storage transport, relative caches,
physical memory/alias/origin/control and all-family O1/O2/O4 recount remain M5.
Complete ISA-handler/family count remains 0; M6 follows M5. No C/runtime,
benchmark, kernel, base or image change is made here.

Validation and all retained attempts are in validation.json. Raw directory:
/workspaces/kprog-raw/formal/m5-numeric-producer-gpr-inputs. One worker uses
CPU 17, queries/edits/Git use 18, every command holds timing SH, 32 GiB address
space and normal 200000 heartbeats / 512 recursion. No new trusted axioms or
increased proof limits are introduced.

Final result: both focused builds pass first attempt (172 and 180 jobs);
full Lake passes 325 jobs, all nine public type/axiom queries pass, and all
23 exports remain byte-identical to 9c617740f. Only standard axioms and the
existing Clight external-function/inline-assembly parameters occur.
