# M5: all 98 Numeric input visits, including vector words

The actual vector call setup and return/store laws now accept their execution
world, input symbol/fundef64 binding and matching composite layout where
needed. The source declaration metadata, continuations, temporary keys,
field offsets, pointer arithmetic and existing store construction are reused.
Each visit executes three call-setup and four return/store transitions around
its actual external outcome. The two public standalone statements remain
projections of these shared laws; the already generic LR-zero law is unchanged.

`ProviderAt` carries the actual world's Senv, full post-memory, trace and
explicit frame/local-read/access/nextblock ABI. The old `Provider` selects its
original world. The existing 64-visit induction now runs in the actual world,
retaining earlier vector words, all other locals and temporary-key facts.
The old complete-vector API remains a projection and its clients still build.

`initialized_vectors` starts with actual Numeric initialization and the
previous 34 input visits, x30 zero, tables and LR zero. Its 64 genuine vector
visits derive every Mint64 word at offset `8*i` in the real 512-byte array,
with the original alternating low/high order across 32 vector slots. It
stops exactly at `afterVectorInputs`, before RAW/header processing. The real
three provider premises keep actual post-memory and traces explicit; they do
not establish native/runtime protocol availability or admission.

All 98 actual provider traces concatenate in source order. Both 31-slot typed
pointer tables and all 62 pointer loads, all 31 GPR word/tag values, four
masked flag bytes, LR zero, both cold caches and `_ctx` remain derived.
Every initial global below frontier 204 keeps its contents and both permission
maps; allocation access/nextblock remain. No final register relation, empty
traces, post-memory=pre-memory or old-vs-Numeric Senv equality is assumed.

Actual RAW/header/register Storage/caller transport and provider/native
admission, relative caches/materialization, native physical memory/alias/origin,
source control and all-family O1/O2/O4 recount remain M5. Complete ISA-handler/
family count remains 0; M6 follows M5. No C/runtime, benchmark, paper/design,
kernel, base or image change is made here.

Validation and retained attempts are in validation.json. Raw data:
/workspaces/kprog-raw/formal/m5-numeric-producer-vectors. Builds use one worker
on CPU 17; reads/queries/Git use CPU 16. Every host command holds timing SH,
with 32 GiB address space and normal 200000 heartbeats / 512 recursion limits.
No new trusted axioms or increased proof limits are introduced.

Final result: shared focused build passes 169 jobs and actual composition
passes 183 jobs, both first attempt. Full Lake passes 328 jobs once
at the end; all seven public type/axiom queries and 23 direct export comparisons
pass. The exports total 243,488,732 unchanged bytes against 9c617740f. Queried
laws use standard axioms and the existing Clight external-function/assembly
parameters. Native make check remains due at final goal confirmation
(last whole pass 5236c0e9677f635526fdd515cde5195b2ba0810c).
