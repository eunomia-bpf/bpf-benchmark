Shared-hash regression investigation, 2026-11-16

Coordinator20:20 requests before/after-f45bb2485 diagnostics on image6641a7e1,
CPUs16-23, for OTel and Katran. Actual body/helper/map per-call comparison is
still open. The result-local diagnostic below is ready to run.

Static audit (audit.json): build_x86_lookup_call_postprocess is text-identical
before and after f45bb2485. The kernel raw __htab_map_lookup_elem returns an
htab_elem and leaves LRU marking to its caller. The kernel LRU JIT generator
and native typed LRU postprocessing test/store ref at byte35; generic LRU
map operations mark it too (hashtab.c:788-809,812-838,2441-2452).

The retained pre-f45 Katran blob has no explicit typed LRU ref compare/store;
its dynamic LRU lookups retain generic map-ops dispatch. The retained OTel
sampling-entry blob has one such compare/store sequence. Thus the source
change did not delete the caller's LRU update. This rules out deletion of
that sequence, not every possible runtime map-binding, hash-cost or eviction
mechanism. The older May-linker missing-lookup case remains distinct.

The copied raw hash is exactly identical in the two retained app blobs:
Katran [10198,12642), OTel [7685,10129), 2444 B each. Its sole external raw
fallback is at relative2434, and each region has123 retained ABI instruction
sites. audit.py extracts the retained body and ABI sites as raw inputs for
the requested current-image comparison; it builds no old tool or source copy.

A diagnostic can use the existing BPFREJIT_NATIVE_LINK_BINARY override through
the results bind mount and the current image's own linker. A retained-body
comparison must preserve map patches, helper/image-pointer relocations,
entry/end control flow and ABI sites. Keep the image, workload and frozen
entry intact. Hardware guest-only sampling is needed for OTel; software
CPU-clock missed its perf-event BPF execution in the earlier profile.

Runtime comparison recipe

`make -f kprog/results/shared-hash-regression-20261116/Makefile preflight`
checks local branch targets, shifted map/image-pointer relocations, unchanged
tail-counter values, ABI metadata, and the no-hash passthrough. This passed
before guest launch; raw preflight.json and copied-hash.disassembly.txt remain
under /workspaces/kprog-raw/perf/20261116-shared-hash-regression.

`stage` hardlinks the single committed link.py into the existing corpus result
mount as copy-link and shared-link; retained machine code and ABI sites are
data inputs there. Both names delegate proof and kernel linking to the current
image's /usr/local/bin/native-link. The shared name only archives the actual
output and plan. The copy name redirects typed raw-hash calls into the retained
2444 B body, with its fallback bound to the current boot's original raw target.
It leaves generic map operations and all LRU postprocessing intact. No second
tool build, source tree, image, base or module is created.

The copied body precedes the original image after a five-byte entry jump.
All original instructions move uniformly by 2449 B, preserving local branches;
sideband image-pointer targets and source-map ABI sites move with them. The
extra entry jump, changed alignment and placement are comparison limitations.
This isolates the hash class on the current image, rather than reproducing the
complete historical installed program. Actual installed bytes and selected
call counts come from each guest and archived adapter.json.

`run.sh` queues Katran shared/copy then OTel shared/copy via the existing
phase-profile workflow. Each case is a diagnostic 4-vCPU, 32 GiB guest on
20-23, one 60-second sample, host guest-only cycles:G at 199 Hz, image shared
lock. It exports the already-supported BPFREJIT_NATIVE_LINK_BINARY override
inside that guest; frozen files and settings remain untouched. The controller
runs with a 48 GiB address-space cap and keeps each case's log and exit code.
These profiles supplement the official default 3x180-second corpus runs.
Root cycles are not nanoseconds, and external kernel samples without caller
ownership must be reported separately from program body/inline costs.
The copied kernel image is a direct-native diagnostic; its unchanged proof
output does not establish B verification of the substituted machine code.

First completed case: Katran shared

Run x86_kvm_corpus_20261116_210136_729192 completed with status ok and controller
exit zero. This is the one-sample diagnostic, not the official default timing.

| Measure | JIT | Shared native |
|---|---:|---:|
| Counter ns/call | 207.044 | 204.532 |
| Workload packets/s | 2505432 | 2440796 |
| Installed bytes | 13641 | 10546 |
| Remaining program-text cycles/call | 225.991 | 211.142 |
| Exact ARRAY-dispatch text cycles/call | — | 3.360 |
| Exact LPM-dispatch text cycles/call | — | 2.500 |
| External hash root cycles/app call | 148.467 | 155.885 |

Remaining text includes inline context/clock/percpu/tail operations, so it is
not pure body. JIT inline maps/helpers remain inside its text bucket. External
roots have no exclusive caller attribution; they include other guest work.
The LPM dispatch range can execute its type-test/fallback on non-LPM maps.
Boot-dependent helper operands are excluded precisely from template matches;
the opcodes, branches and layout offsets must still match.

Actual installed CALL decoding resolves the JIT's dynamic LRU lookups to
bpf_map_lookup_elem; native retains that generic fallback and has six typed
raw-hash calls. Neither installed program has a typed ref35 compare/store.
Together with the kernel map-ops source, this supports preserved LRU marking
through generic operations in this case. It does not measure eviction patterns
or dynamic branch frequency. The copied case and both OTel cases remain queued.
All exact per-program calls/counters and ownership caveats are in
katran-shared.costs.json; actual loader facts are in katran-shared.link-plan.json.
