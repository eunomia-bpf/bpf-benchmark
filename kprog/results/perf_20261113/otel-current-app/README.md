# Current-image OTel checked-C application attempt

2026-11-15, source612c9fc18. Completed18:02:35Z. Make status0, application status error.

The existing checked-corpus entry previously selected a manifest from the
removed 2026-11-14 producer route. It now uses verified_corpus.py's normal
manifest inside the sole current image. The functional recipe exposes resource
parameters while keeping its defaults, and removes its completed scratch
Docker disk after the guest exits; raw logs/service archives remain.

Command: make-command.txt. Image d4b19c9f, native OTel590aa121 (2341976B),
CLI64eb98aa, normal B1965, checked compiler907b. This fresh application startup
supplies actual program/map/context requests; it does not reuse the historical
c50a OTel hotspot or its seven-map envelope. The image native object and all
compiler/header input hashes are in metadata.json. FORMAL owns live interpreter
primitive edits; this metadata records the starting header epoch, while each
actual service request records its own generated inputs.

The existing registered service uses checked-sim-c, with all linker LTO enabled,
and the frozen corpus runs one10s sample/stats1 for functional checking. Guest
2vCPU/16GiB, host CPUs16-19,32GiB address-space cap, imageSH only. No timing lock,
host CPU-control change, producer build or base/image replacement. These are
functional observations, not benchmark performance measurements.

Launcher1100852/QEMU1100882 started18:00:45Z. At18:01:42 the image had loaded,
the frozen corpus reported app_start, and the current-image manifest was
visible in the recorded Docker command. Raw captures are in
corpus/results/verified-captures-fduq8ysu. All running logs/state and eventual
service archive/status stay at:
/workspaces/kprog-raw/perf/20261115-otel-current-app/.

Next: read actual request identities, compile/stock/checked install outcomes
and both-arm outputs; isolate any real rejection. P-SPECIALIZE-app remains
open. A448B historical frame and16/16scale stock passes do not establish this
whole-app result. Katran fixed-frequency A/A+A/B and live-plan capture remain
C's independent task on CPUs0-7.

Actual outcome: the baseline finished OK. Both fresh read_task_struct requests
(type17 RAW_TRACEPOINT, native590aa121) passed stock B verification (programs24
and30), completed the normal checked-native compiler, then failed installation
with error524 after165 verifier instructions. The application subsequently
reported the refused shim socket. This is a phase1 failure, not whole-app
acceptance despite Make0. Raw corpus metadata/result are committed at
corpus/results/x86_kvm_corpus_20261115_180139_894113/.

The kernel relocation switch in bdfa49b694e1 lets MAP_POINTER/MAP_VALUE fall
through IMAGE_POINTER. For a packed map-value offset, it range-rejects the
large64bit target as a code offset; a smaller target can be misrebased as a
code address. Kernel099357174783 (parent5c3c95a4d) jumps map cases directly to
the64bit literal write, leaving image-relative rebasing only for kind12.
The real old-kernel regression independently reproduces map-value-offset
load=-524 with a valid four-instruction B, expected42. See map-image-relocs/.
The in-place kernel/image rebuild and corrected executions remain pending.

All service archives and logs stay under the raw root. The completed scratch
Docker disk was removed (removed-build-copies.txt); no result data was removed.
