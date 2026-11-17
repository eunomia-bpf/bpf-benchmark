# ARRAY lookup return layout

This implements finding 11 in `lto-review-20261117`: the known-map
routine's successful lookup jumps over a null result to a shared RET;
runtime ARRAY does that on success and also emits a jump-to-next-RET on
a miss. Separate success/null returns are smaller and remove those
executed jumps. There is no change to key reads, bounds, masking,
wide-product/value-pointer arithmetic, per-CPU adjustment or map work.

The smallest change replaces the shared-return branches with direct
returns. The runtime type branch reaches the same aligned generic E8
helper call for non-ARRAY maps, preserving its arguments and external
relocation ABI. Existing memory facts, checks and sharing keys remain.
No new policy, runtime check, flag, limit, metadata or public API is added.

The existing key/bounds/mask/wide-product/generic-fallback execution and
shared CALL/JMP-site tests run under timing SH then image EX on CPU 19,
one worker/32 GiB. Decoder assertions catch reintroduced return jumps;
three actual generated fixtures record local bytes/disassembly. Previous
unrelated leaf/metadata and memory files compare unchanged. Host results
are pending. The applier is one-shot; after source apply, use a forward
repair on failure instead of rerunning it.

This changes a hot instruction path, but no per-call gain is inferred
from a removed jump. App per-call/body/helpers/maps, throughput and
installed native/JIT bytes remain for Omp's image/check/target-app batch.
All LTO stays on; PERF starts no guest or image. Raw output is retained
under `/workspaces/kprog-raw/perf/array-returns-20261117`.
