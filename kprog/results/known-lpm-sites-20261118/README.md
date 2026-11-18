# Known LPM sites and the existing native trie routine

The next per-call opportunity is to reuse the existing native trie routine
for a map already bound to the kernel trie operation. The native linker
currently sends generic map calls through its native ARRAY/LPM dispatch,
while an exact LPM map's plan selects the kernel trie function directly.
The first step counts actual sites and direct calls before adding a new
kind, metadata or code path.

The reader uses all 295 current production emissions, including numeric
calls and generated functions. It correlates captured addresses with the
sole kernel System.map, retaining independent helper and raw-hash anchor
comparisons for every request. It records named-map lookup diagnostics,
actual external trie CALL relocations and coexisting generic native trie
ranges. Counts describe code, with hotness and per-call gain still open.
It changes zero input facts, programs, source, images, guests or workloads.

The BCC helper-context fix remains in the loader core: CompanionLoad carries
prog_type/context_helpers and maps, while build_native_link_args receives
that companion and no original program FD (native_loader_link_schema.hpp:
54–57; native_loader.cpp:2224–2244,3368). The normal FD entry retains the FD
and the opt-in query at native_loader.cpp:4195–4201. Extending the open
headers with a second helper catalogue would duplicate the authoritative
query. Omp owns that core correctness fix; this LPM inventory is independent.
