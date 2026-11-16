Inner ARRAY type flow in trusted LTO, 2026-11-16

Source 3e5f70e4b/ec4aaeca6 adds compatible map-type flow through immutable
pointer tables, PHI/select, full-width pointer/integer copies and lookup
returns. Missing or mixed types, mutable tables, arithmetic, narrowed handles
and nonempty asm keep their original helper calls. Empty helper-ID asm is
recognized through LLVM's explicitly tied input; the side-effecting barrier
itself remains. Direct named ARRAYs keep the linker's constant specialization.

The coordinator's 20:20 decision moved type/size provenance to libbpf.
f0add8697 binds original source map symbols to actual source resource IDs,
then reads bpf_map__inner_map for type and value size. All four module replies
and the pointer parser are byte-identical to before this item (3c5384aed).
There is no kernel/module change or new production refusal for inner types.
The existing compiler receives these facts; its generated helper/proof flows
through the existing linker. Uniform value sizes select a constant rounded
stride; heterogeneous or unknown sizes retain the live map stride. Every map
retains its live bounds/mask, so differing capacities do not acquire one fixed
size from a call ordinal.

Original OTel contains static program entries that current libbpf rejects.
4aa983499 gives libbpf a maps-only in-memory view by clearing executable
section discovery. Instructions, symbols, BTF, map data and the original file
remain unchanged. The independent section-content comparison passes. No
modified source object or alternate source tree is written.

Host result (report.json): 11 fixture cases, 2,520 execution vectors across
bounds, null returns, differing live capacities/strides and tied asm; all pass.
The numeric, modified-handle and nonempty-asm cases include static checks.
Original-symbol/current-FD binding preserves resource ID501 despite a renamed
map, and all 16 actual OTel inner ARRAY/value-size4 templates pass through
libbpf. The compiler and production loader builds and both active x86 module
syntax checks pass. Final subset controller1900127 returns zero. The first
include-path failure, static-entry failure and test iterator failure remain
in raw directories, along with the initial zero-site real-object result.

| Actual OTel native unwinder host replay | Baseline | Typed inner ARRAY |
|---|---:|---:|
| Selected function bytes | 27,689 | 27,893 |
| Linked payload bytes | 30,383 | 30,410 |
| Inner sites selected | 0 | 68 |

The 204-byte entry growth replaces 68 two-byte indirect calls with direct
calls before kernel linking; the baseline linker already expanded those
calls. Final payload grows only the one 27-byte selected routine. These are
host payloads, not installed sizes or a per-call gain. B generation/stock
verification and affected-app body/helper/map timing remain publication work.
All existing LTO pieces remain on; image6641a7e1 and C's baseline stay intact.

Raw: /workspaces/kprog-raw/perf/20261116-inner-array-lto (including retry1,
libbpf, libbpf-subset, maps-only, section-check and section-check2).
The 20:20 priority is now the hash regression diagnostic, before further
lookup tuning. See ../shared-hash-regression-20261116/.
