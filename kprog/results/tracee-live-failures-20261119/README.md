# Tracee checked-generation failures while the run continues

PERF 2026-11-19T14:23:33Z: The coordinator's current main C/LTO run has completed
its baseline and is loading native programs. This snapshot retains every
record of the first33 completed requests, including checked and direct
paths; it is not the final app census or a performance result. Full logs
and capsules remain at the path in provenance.json. No guest, profile or
production change was started for this inspection.

Two distinct verification classes are already concrete:

- Request27, sys_dup_exit_tail: B generated, stock rejected at instruction959,
  `r7 -= r1`; r7 is an unbounded scalar and r1 is fp-280. The verifier says
  math between fp pointer and an unbounded register is not allowed.
- Request28, tracepoint__sched__sched_process_fork: B generated, stock
  rejected at instruction1, an eight-byte write to R10-536. This exceeds
  the unchanged512-byte stock frame limit.
- Request30 repeats the arithmetic class at instruction27607: R2 tried
  to subtract a pointer from a scalar. Its full symbol/source location is
  still to be resolved from the retained capsule.
- Requests29 and31-33 pass checked-sim-c. The rejected B requests above
  all install direct native with status0, as recorded. They are not skipped.

The arithmetic is separate from the repaired SKB NUMERIC input boundary.
Shared source x86_sim_local_bpf.h:948-953 forms an integer difference
between an address and the arena base, and :1645 performs another arena
difference for cache restoration. These are candidate origins, not an
exact debug-location mapping of the failing instructions yet. BPF register
provenance can survive C pointer-to-integer casts; do not fix this by
deleting the observation, removing alias semantics, choosing a constant
stack base or accepting unverified B. Native compilation must retain the
actual bits. A sound B-only numeric abstraction is a candidate to study,
with correlation/precision and source preservation still to establish.

Next after the active timing lease: inspect request27/30's completed
frontend and source debug mapping, reproduce the subtraction with a small
real B fixture, and test a general compiler transformation on that retained
IR. For request28 inspect actual packed frame objects and lifetimes before
choosing a change. No full frontend replay, relaxed compiler/kernel limit,
new refusal or runtime check is implied. Preserve the current run and report
all final checked/direct paths and samples when it finishes.

PERF 2026-11-19T14:40:08Z: Committed capsule inspector ed1a2a43e is corrected to
consume the final timing/service.tar.gz. trusted_service.py:305 uses a
temporary session and removes that directory after archiving it, so its
live request paths are not stable post-run inputs. I ended only my queued
flock429804 (parent429797) before execution and retained its cancellation
record/raw directory. No coordinator or peer process was stopped.

The replacement streams the final service archive once, selects the three
already known capsules27/28/30, and saves B disassembly/PC windows plus
retained frontend/bounds LLVM text. It runs after timing SH is available,
without a new compiler build, frontend run, stock reload, image or guest.
An unresolved PC or missing capsule is an inspection failure, never an app
coverage conclusion. Full artifacts remain raw; only compact evidence will
be committed after the tool runs.

PERF 2026-11-19T14:59:03Z: Replacement inspector430344 waits timing SH on CPU19/4GiB.
Raw: /workspaces/kprog-raw/perf/tracee-live-failures-20261119/inspect-20261119T144031Z-430344.
The input is the coordinator run's final timing/service.tar.gz, not the
temporary request directory. Neither mapping nor LLVM inspection has run yet.

Coordinator c3960d089 changes subsequent checked-sim-c requests: B failure
keeps the original program on eBPF. The prefix above describes the older
running batch and retains its actual direct-native records. The existing
coverage reader now reports kept_on_ebpf for failed requests; it preserves
execution_mode when supplied and never relabels historical direct successes.
The base loader still needs rebuilding in the next authorized base/image
batch; this records source behavior, not a claim that the running guest has
changed. No production source or running batch input is changed here.

Future Cilium measurement uses the existing lto-apps-20261119/Makefile
checked-timing APP=cilium/agent entry with 3 x 180 s and stats on, after
reading OMP's result and respecting its queue. The canonical checked-corpus
1 x 10 s functional check is not a complete timing measurement.

PERF 2026-11-19T15:12:40Z: The service's new failure branch raises before returning
B flags to the completion record (trusted_service.py:194-199). The reader
therefore supplements absent flags only from an actual retained simulator
object named by artifacts.json or a checked-simulator-verification.json
receipt. Explicit flags are preserved. simulator-failure.json supplies
the actual failing stage. An early failed request without kernel.facts.json
retains its source ID/error and a null program type; a successful request
still requires its facts. These are archive-analysis changes only. The
completed-BCC reader worker433910 remains queued; no host pass yet.
