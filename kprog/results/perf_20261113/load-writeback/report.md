# Shared load writeback

2026-11-15. Implementation 2c6ae7717, focused input fixture corrected in
3c958eb22. The existing memory, context and saved-stack-fact branches now
compute a result before one common scalar-or-pointer destination write.
This removes repeated expansion of register-write/stack-release bodies.
No P source, native flags, opcode, upstream application or benchmark change.
All native LTO remains enabled together.

Same current OTel perf hotspot inputs as f1527d02a: native SHA c50a8df9,
proof 717ece29, metadata e5c8459b, normal CLI45c33e7e; 6,945 instructions,
1,032,341 generated C bytes. Type7/perf_unwind_hotspot and seven matching
historical map bindings remain an offline diagnostic, not a fresh app capture.
Full identities and production command/resource records are in `preprocess`.

| CPP attribution | Before | After |
|---|---:|---:|
| Total bytes | 384,511,544 | 309,459,472 |
| MOV_LOAD | 127,980,936 | 55,080,144 |
| STORE | 114,820,691 | 114,820,691 |

Total reduction is **75,052,072 bytes (19.52%)** for this step, or **28.31%**
relative to the pre-BMI2 431,680,679-byte frontend. Proof/render/CPP takes
15.05s in this single observation, with unchanged production chunking/flags,
CPUs8–11 and 8GiB address space. This is a frontend-size result, not a
compiler-speed or application-performance measurement. No full OTel B backend,
stack verification or application acceptance is claimed.

Independent load and stack byte-model oracles pass before and after:
713 load cases and117,782 stack cases. The new focused fixture passes14
cases for saved STACK/MAP_VALUE/PACKET representatives, RSP/alias sources,
destination/base overlap, RSP release and memory-recovery early exits. It
checks all six flag bits, stack bytes, stale facts and environment draw count.
The first fixture incorrectly counted draws through the header's existing
host zero shortcut; diagnostics show correct pointer/tag/bytes but zero draws.
The corrected fixture explicitly binds `X86_SIM_L_UNSPECIFIED` to the real
environment-input interface and passes. Production behavior was unchanged by
that fixture repair.

One older oracle remains a visible baseline failure: the helper-output
lifetime test refers to removed `X86_SIM_L_HELPER_WRITE_ARG_PTR` and fails
to link both before and after the change. Consequently the combined
`load-oracles` target still exits2, with all command failures preserved;
this is not reported as a clean whole-suite pass. Its obsolete helper-output
contract needs reconciliation under the formal work.

Sixteen actual native CPU/shared-C fixtures pass4,032 comparisons after
the refactor, including nonzero displacement and defined flags. Every fixture
compiles through the normal B pipeline, and all16 generic/direct allocated
section sets match. After the all-pairs policy becomes the single path
(8f48bf443), the same checks pass again. Comparing their direct allocated
hashes against `bmi2-specialization/displaced/result.json` shows all16
identical to the pre-load-refactor B sections. Full ELFs may differ in debug
information. This is subset evidence, not full OTel B equivalence.

Raw: `/workspaces/kprog-raw/perf/20261115-load-writeback` and
`/workspaces/kprog-raw/perf/20261115-all-pairs-single/native-b`.
Canonical builds remain `/var/tmp/kprog-tmp/perf/load-writeback`,
`bmi2-specialization`, and the reused `otel-whole-word-checked` directory.
Only logs, measurements and hashes are copied here; no build copies or raw
data deletion. Kernel/base/image/CLI unchanged. The current frontend is still
309.5MB; STORE is now its largest macro bucket. Its duplicate tagged-store
calls are the next candidate, before another large backend attempt.

Reproduce with the committed Make targets `load-oracles`,
`bmi2-specialization`, and `current-otel-preprocess` in
`kprog/test/native-relocations.mk`, setting OUTPUT to a persistent run path.
