# Remaining zero-tail duplication

This static inventory follows `a5bb61c40`'s known-count error-zeroing.
It decodes the eight current generic scalar/string user/kernel fixtures
and inventories read-helper PLT32 relocations in the 239 retained
2026-11-16 six-app extracted entry requests. It emits no candidate code,
builds no tool and starts no guest or image.

The generic error tail restores RDI from R8 and ECX from R9D, preserves
RAX's error, zeros the full destination and returns. If an existing tail
is reused, each additional leaf needs an error jump and its own success
return. The size bound charges five bytes for that jump and one byte
for the return. Fixed counts now have smaller tails; the inventory does
not guess their count meets. This gives an upper bound rather than an
installed-size saving.

Read-helper relocations identify possible leaf combinations under the
current source selection. They do not infer numeric transfers, current
loaded-program counts or unrecorded generated Tetragon functions. The
historical payload totals belong to the retained outputs, not today's
image. Runtime/helper facts absent from a capture are not synthesized.

`run.sh` runs on CPU 19 under timing SH and retains all raw output in
`/workspaces/kprog-raw/perf/zero-tail-inventory-20261117`. It records only
actual output under the Git lock. Results and a source-change decision
are pending. Any future sharing must carry structural tail offsets
through branch sizing, preserve success returns and protected loads,
and avoid fake helper identities or a new public relocation format.
