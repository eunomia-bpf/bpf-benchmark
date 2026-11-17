# Share structurally identified read-error zero tails

The smallest source change carries the existing zero-fill boundary through
branch compaction and reuses an identical tail already emitted in the same
program. Local success and zero-size returns keep their original labels;
error paths reach the shared suffix after their own policy/copy/cleanup.
The error value, destination and original count remain in RAX/R8/R9D.
The existing block encoder maps branches and protected source-load offsets.
The production transform uses emitter metadata and exact suffix identity.

The current 295-request inventory establishes a local bound of 1552 B for
Tetragon and 11268 B for Tracee. Actual code layout, metadata, execution and
all captured requests follow before an installed-size or per-call claim.
The focused regression first observes duplicated user/kernel tails. The
existing full fault/string/SMAP/fixed-count driver then executes the second
of two emitted leaves, whose error tail reaches the first leaf's suffix.

Host work uses timing SH/image SH, CPU 19, one Cargo worker and 32 GiB AS.
The live canonical CLI and checked guest retain their image lease. Omp owns
the later frozen image/check/affected-app batch with all LTO on.

First run 2817773 ended 101 at 23:44:37Z on compile errors: the new test used Clone on the layout, the decoder needed into_iter, and the fixture Path type needed qualification. The focused baseline also ended on the layout compile error; retained current-zero-tail emissions supply the actual duplication evidence. The source/test stage already applied; resume-host.sh continues full tests and replay after the forward compile correction. All initial raw logs remain.

Resume 2818089 passed all 61 tests with four existing opt-in tests at 23:46:09Z. It then ended 1 because the blanket old-fixture cmp reached compat-string.bin, which combines user/kernel leaves and intentionally changes under this sharing. after-tests.sh retains the completed suite and reports every fixture equality/difference before source publication and 295-request emission. It repeats neither the source application nor the completed full tests. Existing compat execution vectors passed in the full suite.

2026-11-17T23:47:29Z — Structural shared zero-tail source and full host tests completed; actual logs and source.patch committed. Raw: /workspaces/kprog-raw/perf/shared-zero-tails-20261117/host-20261117T234518Z-2818089. Production unit-entry build and captured-request emission follow; canonical CLI stays unchanged; installed/time results remain pending.

2026-11-17T23:50:44Z — Production source `a4d1e0588` is pushed. The complete Rust suite passes **61 tests**, with four existing opt-in tests. The new sharing fixture runs 96 additional driver invocations over the existing generic scalar, string, compact/wide and 0–1024-byte fixed-count fault matrices; shared-executions.json retains each output. Existing compat dispatch tests also pass. Of 649 old fixture/metadata files, 647 remain identical and only compat.bin/compat-string.bin change; their source-status metadata stays identical.

All 295 actual captured production requests emit successfully through the existing unit executable. Compared with named-map CFG source 9cf2726e0:

| App | Requests | Neutral bytes before | Neutral bytes after | Changed payloads | Growth cases |
| --- | ---: | ---: | ---: | ---: | ---: |
| bcc/set | 25/25 | 11028 | 11028 | 0 | 0 |
| cilium/agent | 47/47 | 178766 | 178766 | 0 | 0 |
| katran | 1/1 | 9241 | 9241 | 0 | 0 |
| otelcol-ebpf-profiler/profiling | 14/14 | 129734 | 129734 | 0 | 0 |
| tetragon/observer | 39/39 | 284119 | 282567 | 33 | 0 |
| tracee/monitor | 169/169 | 1744643 | 1733375 | 140 | 0 |

The reductions are **1552 B Tetragon and 11268 B Tracee**, exactly matching the 12820-byte local bound. Every changed payload's size reduction equals its probe-region reduction. The other four applications stay byte-identical. External helper-target multisets, map-patch name multisets, callee-saved masks, four-byte tail-counter observations, all recovery length/destination shapes and R11 protected-load instruction bytes/lengths remain equal in every request.

The decoded structural audit covers all **358 duplicate suffixes**, with zero prefix/target/return failures. Each retained suffix is byte-identical, every policy/copy/cleanup prefix instruction is preserved, each prefix branch reaches the corresponding instruction or local success return, and each error jump targets the correct previously emitted zero suffix. The actual source transform grows production code by roughly fifty lines, chiefly carrying one structural offset and remapping existing branch/load metadata; the focused driver extension supplies execution coverage. The six-byte cost comparison is a load-time code-size choice. Runtime policy, helper selection and workload settings stay as before.

The initial baseline and first new-source compile failures are retained as compile failures, with the API/test fixes documented above. The later blanket fixture-identity stop is retained as exit1; the full tests had already passed and the two changed compat outputs are part of the measured transformation. The continuation reused those completed tests and emitted all requests. Source, initial failures and final results remain forward changes.

These are neutral host-code and execution observations. Installed native/JIT bytes, app per-call and throughput, and body/helper/map time remain the frozen image/check/affected-app batch measurements under Omp, with all LTO enabled. The successful path keeps its instruction sequence; shared zeroing adds one error-path jump. The hard app targets remain open. Canonical CLI size/mtime stays2978744/1794948232 and the checked Tracee guest continues using its current base/image.

Raw success: /workspaces/kprog-raw/perf/shared-zero-tails-20261117/host-20261117T234518Z-2818089. Initial compile run: /workspaces/kprog-raw/perf/shared-zero-tails-20261117/host-20261117T234433Z-2817773. Continuation2819178 ended0 at23:47:43Z; prefix reader4558ded49 completed358/358 cases. All own workers are terminal.
