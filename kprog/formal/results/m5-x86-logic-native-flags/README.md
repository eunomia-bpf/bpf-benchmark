# Actual logical stores with native final flag bytes

One theorem now combines the original31-step CF/ZF/SF/OF/PF store execution,
final header preservation and actual final-heap readback of the five bytes.
Those bytes represent the single external x86lean logical-flags result for
the actual width-truncated word and every undefined-AF oracle choice.

The theorem derives every intermediate header observation and each preserved
flag byte from the actual initial loads and successful ordered stores.
Its explicit domains separate the header block from flag data and require
distinct flag byte addresses, permitting shared flag allocations at different
offsets. The native view states exactly the five bytes in the source ABI.
Full handler/caller, remaining native state and dispatcher composition continue.

Focused74 jobs and the public type/axiom query pass at200000/512 budgets,j1,
32GiB under shared timing. Runtime, imported semantics and the single ISA
specification retain their definitions. Latest whole confirmation remains
the DIV regression in `m5-xor-full-20261123`.
