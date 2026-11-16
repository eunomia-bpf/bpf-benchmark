# Retained Tetragon program exports through CompCert

`c/TetragonWake.c` is the retained C for the real `event_wake_up_new_task`
request with 738 entry instructions. It is now checked-in C, edited directly.
Its body matches PERF's archived simulator source apart from the two relative
includes and a provenance comment. This snapshot keeps its native-link dynamic
memcpy/memset subroutines, indirect helper and code-target switches, four CALL
continuations, 336-byte private arena and 42 named fact cells. It is the
retained proof epoch, not a claim about a newly rebuilt application object.

The actual frontend first stopped on GNU register/tag expressions at generated
indirect-target sites. In the existing `KPROG_X86_PROGRAM_EXPORT` mode, CompCert
now calls the existing inline C read/tag bodies over the live entry binding.
No copied state or new input initialization is introduced. Generic consumers
retain their restored macros. The typed callee aliases now apply only to calls,
preserving the public `struct bpf_fib_lookup` tag. A new static ABI assertion
rejects the old object-like alias and accepts all 81 public callee types. The next failure was the empty memory barrier
at 79 conditional branches. The shared platform adapter retains the native
asm and memory clobber; its CompCert statement has no C data effect. Branch
conditions and targets are unchanged. Native memory/order interpretation
remains a proof obligation.

`make clight` exports the retained program as `Clight.X86TetragonWake`. The
actual Clight oracle checks mature composite construction, arena size, all 42
named fact types, real copy/set loop labels, the typed probe-read ABI, 11 map
symbol identities and the four exact return cases/labels. External map memory,
actual kernel helper behavior and arbitrary-program refinements remain M5.
The existing sparse-binding/frame test also runs with the new producer facades.

The host observer exercises 16 complete returns and 24 helper-refusal prefixes
per mode: null task, null parent and nonreturning first/second/third probe reads,
across eight high stack-base/input seeds. It checks exact helper source/destination
relationships and widths, input counts, return values and unchanged complete
context/task/parent input buffers. All storage read by these paths is initialized.
The native-body and CompCert-adapter modes share explicit typed callees. These
are selected entry paths; they do not execute all application branches or the
copy/set loops and do not expose all private entry state. No whole-state capture
comparison or full application/kernel equivalence is inferred.

Clang 18 compiles the retained entry normally and instruments its observer
with UBSan. The initial GCC host-only probe was terminated after reaching
about 14 GiB RSS. The instrumented full-entry Clang probe was sampled in LLVM
InstCombine and terminated after about 15 minutes. Their process status,
commands and stack sample remain in raw. Generic handler and binding grids
retain UBSan; no full-entry sanitizer result is claimed. Clang requires the producer's existing error attribute
on the first observer declaration. The host environment now carries it there;
the producer refusal attribute and its nonreturning observer remain intact.
Host-only empty `__ksym`/fastcall spelling supplies metadata normally provided
by the public BPF header to the native stub environment.

Native comparison replays the old local header, platform header and later
inline header at their actual include positions. `tools/compare_c_header.py`
now traverses the complete translation unit for these replacements, retaining
line markers and include order; the old implementation could only replace
children of the first selected header. The retained program exercises that
later-direct-include case. Compare results and exact commands are recorded in
`result.json` and the adjacent receipts; larger compiler logs stay in raw.

Raw evidence is `/workspaces/kprog-raw/formal/m4-x86-retained-program`, including
initial path errors, both real frontend failures, the GCC probe, host attribute
diagnostics and final results. M4 remains open for its remaining C-subset and
default-byte obligations. All 2,065 M5 refinements and O1/O2/O4 recount precede
M6 retirement and final whole `lake build`/`make check`.
