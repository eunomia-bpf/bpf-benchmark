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
unrelated leaf/metadata and memory files compare unchanged. The applier
is one-shot; after source apply, use a forward
repair on failure instead of rerunning it.

This changes a hot instruction path, but no per-call gain is inferred
from a removed jump. App per-call/body/helpers/maps, throughput and
installed native/JIT bytes remain for Omp's image/check/target-app batch.
All LTO stays on; PERF starts no guest or image. Raw output is retained
under `/workspaces/kprog-raw/perf/array-returns-20261117`.

Completed 2026-11-17T18:00:40Z. Source `eecc7e859` is pushed; host 2692136
exited 0. All 54 linker tests pass, with 3 existing ignored tests.
The key/mask/wide-product/null/generic helper execution tests, shared
CALL/JMP entries, external E8 slot and aligned nested generic call all
pass. The new decoder assertions find two RETs in a known ARRAY routine
and three in the runtime ARRAY routine, with no unconditional branch.
All 221 prior leaf/metadata files and 423 memory bodies remain identical.

| Actual local fixture | Bytes after | Source layout reduction |
| --- | ---: | ---: |
| Known ARRAY, max 3, stride 24, value offset 304 | 23 | 1 |
| Known ARRAY, max 4096, same stride/offset | 25 | 1 |
| Runtime ARRAY, full generic helper branch | 64 | 3 |

The known body replaces a two-byte jump with one RET. Runtime ARRAY's
preceding 67-byte routine is recorded by its existing shared-layout
assertion; success/null now have their own RETs instead of two shared
return jumps. The external helper slot moves from local offset 57 to
54 and is still exactly E8 plus four relocation bytes. Generic dispatch
reaches its stack-alignment instruction before that call. The production
change is one net line smaller; 14 lines extend existing tests and save
the three emitted fixtures. No new test framework or fixture driver.

Evidence: [host output](host-output.txt), [local sizes](local-sizes.txt),
[disassembly](array-disassembly.txt),
[leaf/metadata comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt), [raw location](host-location.txt).
All compiler, execution and publication output remains in
`/workspaces/kprog-raw/perf/array-returns-20261117/host-20261117T175955Z-2692136`.
The recipe is `41abf1ee0`. Source and receipts were published under the
locks before releasing image EX. No per-call, installed-size or target
achievement is inferred from the local instruction change.
