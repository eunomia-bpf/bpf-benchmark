Known lookup targets, 2026-11-16

OTel's PMU profile identifies inline LPM and the ARRAY dispatch chain as large
costs. The native selector discarded complete named `call` targets, including
ARRAY_OF_MAPS and LRU_PERCPU_HASH. The loader also left known LPM maps at the
generic helper. Keep all complete named facts and select trie_lookup_elem from
the loaded LPM type, matching the sole kernel's map operation. Actual unknown
map arguments retain their dynamic semantics. No per-call check is added.

The existing named-map regression now covers call targets as well as inline
and raw-hash forms, and its ELF integration case checks that generic ARRAY
sharing leaves the named target intact. The result Makefile builds the one
linker and loader in place and replays retained Katran and OTel plans with
generic versus bound call facts. These are host payload bytes, not installed
bytes or runtime gains. OTel's extra LPM fact is source-derived and uses a
same-kernel symbol delta; actual loader capture remains a guest measurement.

Image 6641a7e1 remains in use for C's baseline round. Installed bytes, per-call
time and the body/helper/map split after publication remain open. The PMU
baseline and its attribution limits are in ../otel-regression-20261116/.
