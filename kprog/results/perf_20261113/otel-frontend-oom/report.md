# Actual OTel optimized frontend: memory failure

2026-11-15. The original normal optimized frontend completed with failure,
not a B program. LLVM reported `out of memory` / `Allocation failed` under
the 16 GiB address-space limit. The Make wrapper exited2; the Clang driver
returned1 and reported frontend exit134. The optimized LLVM stage took
2,564.727s (42.75min), with maximum RSS16,620,472KiB; proof/render/CPP plus
frontend took2,579.132s. Address-space and RSS limits are different measures.

The entry is `perf_unwind_hotspot`, program type7, with seven historical
matching map bindings. Native SHA256 is
`c50a8df99505eead7881bbd9bebb8eb9357fd53106feb7ff58a8f7781e393150`,
proof SHA256 is
`717ece2934366ecfd4b61c0118e460153048cdce657a66d416df29ca5d823452`.
The exact normal `-O3` command, CPP identity (289,568,784bytes), stack trace,
resource counters and failure are in the accompanying files. This stops
before bounds/MIR/all-pairs/llc and has no kernel or application acceptance.
Early and late compiler sampling in `../pre-sroa-constants/report.md` locates
SROA/PromoteMemToReg; sampling pauses and host debugger installation mean
this run is not an uninstrumented compile-speed baseline.

The revised immutable-width/selector frontend started after this process
ended, on the same canonical build and unchanged normal optimization flags.
Its CPP is297,172,962bytes, **2.63% larger**, despite the smaller isolated
pre-SSA handler graph. It is still running at10:25UTC, Clang911032; no full
compile gain follows from the small probe. Native/proof/metadata identities
match; header/specializer fingerprints are recorded in its raw `result.json`.
It releases imageSH after capturing inputs, before expensive LLVM work.

Raw original: `/workspaces/kprog-raw/perf/20261115-current-otel-frontend`.
Raw revised: `/workspaces/kprog-raw/perf/20261115-width-constants/otel-frontend`.
Reproduction uses the committed `current-otel-frontend` Make target through
`kprog/test/run_verified_make.sh`, CPUs8–11/16GiBAS, with all LTO together.
Both jobs and all evidence are retained; no failed artifact is reused as B.
