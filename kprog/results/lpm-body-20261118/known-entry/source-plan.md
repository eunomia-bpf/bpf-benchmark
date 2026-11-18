The production change keeps exact loaded LPM12 calls as LocalLpm patches in
the existing call-slot machinery. After source instruction layout, their
resolved offsets feed the existing trie sharing routines. Dynamic calls
enter the guarded dispatch; exact calls enter its existing query-prefix
instruction. The existing compact_at offset remapper retains this one entry
through branch relaxation. Mixed callers share one body. An all-exact load
emits that same worker with its type/data-size guards and generic fallback
omitted at build time. The query bound and tree semantics remain.

Source scope is x86.rs, x86_lpm_lookup.rs, x86_runtime_array.rs and the
visibility of existing compact_at in x86_probe_read.rs. The current named
ELF test covers ARRAY layout present/absent and exact/type/layout binding;
the existing two shared-routine tests gain mixed-entry displacement cases.
The current full 62-test suite and all295 original captures run through the
parent candidate.sh, timing SH/image SH, CPU19, one worker/32GiB AS. Legacy
plans retain their original call kinds; their identical artifacts establish
compatibility. Actual candidate activation needs loaded lpm12 facts in the
next frozen image. Canonical CLI stays in use by peer checked Tracee2754970.
App installed bytes and per-call/body/helpers/maps/throughput remain omp's
all-LTO batch measurement.
