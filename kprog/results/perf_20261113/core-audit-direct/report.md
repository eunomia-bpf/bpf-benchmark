# Direct-libbpf CO-RE audit after producer cleanup

2026-11-15, lane PERF. The normal offline audit no longer depends on the
deleted CO-RE IR compiler, compiler reports, legacy stage inventory, or removed
`native_compat.h` policy. Its obsolete compiler, zero-comparison and macro
targets, tests and unused resolver-side header are deleted. Historical results
are preserved.

`core-reference` still uses actual `.BTF.ext` records and libbpf candidate
selection, relocation calculation and instruction patching. The new fixture
checks all thirteen relocation kinds in sixteen actual ELF records, including
absent field/type/enumerator answers and changed size, offset, signedness,
bitfield shifts, enum value and type match. All sixteen match independent
fixture expectations and patched instruction immediates. No production IR
transformation or program load occurs.

Native audit regression results (`native-regressions/job`, Make exit zero):

| Native observation | Relocations | Equal | Different | Unobserved |
| --- | ---: | ---: | ---: | ---: |
| Actual compiled constants | 16 | 16 | 0 | 0 |
| Wrong field offset and absent-field answer, correct DWARF | 16 | 14 | 2 | 0 |
| No native observation, same DWARF | 16 | 0 | 0 | 16 |

A stale native-object SHA256 witness is rejected. Each witness binds both
source and native hashes; DWARF remains a separate column and cannot turn a
missing or wrong native answer into an equality. The native object/shared
library product is replaced sequentially for the two cases; no per-mode build
copies are kept. Commands, reference rows, witnesses and summaries are retained.

The initial attempt failed because the host has no `bpftool` on PATH. It is
retained under `mechanism`; the corrected test reads actual BTF type IDs through
the existing base's libbpf API instead. Both the thirteen-kind check
(`mechanism-fixed`) and native regressions then ended successfully on CPU 19,
4 GiB inner/8 GiB outer address-space caps. No guest, base, image or kernel
change was needed. Raw root:
`/workspaces/kprog-raw/perf/20261115-core-audit-direct`.

Producer handoff: `kprog/test/core-audit.md` documents explicit current object
inventory and measured native-witness fields. The six-app rebuilt-object
comparison remains open until those actual outputs and observations exist.
This fixture establishes the measurement route, not correctness of an app's
compatibility header or any speed/size gain. The audit adds no load-path check
or job admission condition.
