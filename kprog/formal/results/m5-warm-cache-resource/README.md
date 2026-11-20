# Warm SP cache retained through both actual calls

The actual cold-SP MOV_IMM call now returns all 12 canonical header pointers
and WarmEntryCache at its original caller frontier after its real frame free.
The existing reader's actual cache stores and warm witness supply this fact;
canonical local observations carry it through writing and free. No warm or
post-memory premise is added, and the provider is not run again.

The full-word ordinary MOVK call returns exact canonical local observations
outside its selected word/tag cells, derived across its actual allocation,
writer certificate and free. The original source pair uses those observations
to retain the same header pointers and warm cache through the second call.
Existing source/native wrappers preserve these added resources alongside all
scalar readbacks, complete register relations, source traces and both releases.

The actual wrapper prefix now exposes its same canonical header witnesses,
final pointers and warm cache after both calls. The cache frontier remains the
original reached producer frontier; warm_iff can move it to the actual final
memory frontier. This supplies the next SP32/ADD_IMM read. It does not claim
ADD execution, physical ABI/provider validity, all outcomes or final return.
Completed ISA-family count is zero; M5/M6 remain open.

Focused checks pass: cold call 227 jobs, entry resources 236, all affected
consumers 237 and nine public type/axiom queries at original caps on CPU 17,
nice 0, one worker and 32 GiB address space. Whole proof-library confirmation
follows this batch. Raw: `/workspaces/kprog-raw/formal/m5-warm-cache-resource`.
