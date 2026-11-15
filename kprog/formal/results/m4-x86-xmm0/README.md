# XMM0 C-subset checks

The canonical arm selector has one declaration body, output form and native
expression facade. The actual two-lane load/store bodies use the existing
address-add helper: BPF pointer operand forms remain intact, while host and
CompCert use its address-bit form for null-base stores. Absolute loads keep
their distinct immediate-plus-index selection and lazy register operand.
No new platform import or alternate interpreter is introduced.

The actual C roots export through the existing capacity/arena/fact binding.
Historical4c35f49f8, current native and CompCert host-adapter modes each pass
1,848 complete state/bytes/fact frames across capacities16/64/200/376,
private/register/no-base addressing, aligned/unaligned windows, index operands,
tags, recovery and per-lane released-stack observations. Each also passes260
arm-capture/lazy-selection cases and two guarded second-lane C-prefix probes.
The latter retain low-lane commits, released draw order and fact invalidation
before the second store faults. They do not establish ISA fault correspondence.
Four mutations fail as intended: byte-narrowed arm truth, lost absolute index,
incorrect high-lane offset and incorrect low-store value. Existing memory,
MOVBE and physical-store checks still pass in the combined oracle.

`make clight` and the40-job targeted Pointer/Memory/Context Lean build pass.
Pointer34 functions/988,925B and Memory20 functions/458,974B regenerate exactly.
Three AST-root axiom queries return only propext/Classical.choice/Quot.sound.
The larger diff is the genuine exported two-handler AST; no manually written
Lean semantics are substituted. The exporter emits one added trailing-space
line; it is retained to preserve exact regeneration.

Historical header replay has identical allocated sections/relocations for
XMM3424B/21 and ordinary1448B/11, and current replay equals normal compilation.
These are compile fixtures, not loaded programs or whole-default coverage.
Full inline export now fails at CMOV writeback's GNU expression. Its explicit
profile preprocesses to2,443,837B; this is not a whole-application scale number.

All commands, source patch, attempted harness fixes, mutation results and
logs remain in `/workspaces/kprog-raw/formal/m4-x86-xmm0`. The normal regression
oracle and compile fixture are committed and wired into `make clight`.
Execution and replay use the same products in place, CPU15,32GiB AS and one
Lean thread. M4, all2,065 actual refinements/O1-O2-O4 recounts, M6 and final
whole-library `lake build`/`make check` remain open. Platform pointer-fragment,
native permission/volatile/fault semantics and cross-TU linking remain M5.
