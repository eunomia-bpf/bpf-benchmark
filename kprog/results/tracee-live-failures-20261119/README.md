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

PERF 2026-11-19T15:27:20Z: Live loading-stage snapshot (metadata only): request49 is
uprobe_syscall_table_check, temporary request-6fb7926d. At15:26:58Z its
generated/trusted_x86.bpf.c was2,287,234B (mtime14:51:56Z), preprocessed
trusted_x86.bpf.i was7,111,263B (mtime14:52:04Z), and the frontend temporary
trusted_x86.bpf.bounds-input-84c2f86b.bc.tmp was0B (mtime14:52:04Z).
commands.jsonl's last completed command is successful preprocessing of
piece8. No completed frontend/bounds/MIR or stock result exists for this
request in this observation. Its source preamble declares288 arena bytes
and36 named ghost-cache cells (M0 through M35). Full live path is the
coordinator run from provenance.json, timing/state/session-x9mp5xyg/requests.

trusted_specializer.py:79-95 runs preprocessing, then the O1 LLVM frontend
before the bounds pass and MIR backend. Source metadata therefore locates
the unresolved completion before bounds/MIR; it does not establish which
LLVM pass is expensive, a process-level hang, or a new B rejection. The
preprocessor splits source-location expansion into pieces (:39-76), but
the joined token stream is compiled as one translation unit. Dense cache
fanout is a review candidate already seen in Tetragon, not a measured cause
for this program. Preserve the run and inspect its eventual stage logs; no
repeat frontend, flag change, timeout, cancellation or limit change.

PERF 2026-11-19T15:44:16Z: Operator's newer instruction, recorded in user-instruction.md
and implemented by0a993eb37, restores direct-native execution when B fails:
"恢复这个, 吧 verify 和运行分开看". This supersedes the earlier c3960d089
policy above. Coverage counts actual execution_path/status independently of
B-generation/stock acceptance: a successful direct-native request remains
native even if B fails; only a failed request contributes to kept_on_ebpf.
The current Tracee batch's direct-native results therefore agree with the
restored policy, and are still never called stock-verified. No rebuild
targeting the superseded c3960d089 policy is queued. Future base/image
batches use current HEAD normally. Reader replay433910 remains pending.

PERF 2026-11-19T16:48:10Z: Completed capsule recovery7a67a8cfa packages only the three
existing completed capsules, explicitly not a final service archive or
app census. Initial recovery17194 failed before inspection because
inspect.py shadowed Python's standard module;167f1540b renames the reader.
The successful mapped result and PC/generated-C windows are committed.
Raw /workspaces/kprog-raw/perf/tracee-live-failures-20261119/recovery-20261119T163803Z-17194/source-mapping; no frontend replay, stock load or guest.

-27sys_dup_exit_tail: BPC959 maps to generated C1723, native0xa04
 MOV_STORE_REG [rsp+0xa8],rbx.
-30lkm_seeker_modtree_loop: BPC27607 maps to C49145, native0x11cc6
 CMP_IMM rbx,0x7d00, following a16-bit load into RBX.
-28tracepoint__sched__sched_process_fork: BPC1 is a536-byte frame
 write at function entry (C70), not a native source memory access.

Both arithmetic sites consume numeric register values. Store-value and
comparison macros call X86_SIM_L_READ_REG, whose conditional STACK case
uses STACK_NUMERIC_BITS_INTO (:588-594), subtracting arena top before
adding native stack base. The rejecting B subtraction precedes its emitted
tag test (27insn962;30insn27613). Thus the earlier alias-offset/cache-restore
source guesses are superseded for these two PCs. Inspect retained frontend
and bounds IR to identify which optimization speculates this numeric
conversion and how to preserve its branch/provenance. No B-only numeric
abstraction, changed shared header or extra check is implemented here.
