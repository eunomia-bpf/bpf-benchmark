Shared-hash regression investigation, 2026-11-16

Coordinator20:20 requests before/after-f45bb2485 diagnostics on image6641a7e1,
CPUs16-23, for OTel and Katran. Both diagnostic pairs are now complete; the
counter, installed-byte and sampled cost comparisons appear below. Historical
regression attribution and the official performance targets remain open.

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

Katran pair completed

The copied case x86_kvm_corpus_20261116_210724_159080 also completes with app
status ok and controller exit zero. Six calls are redirected; the installed
routine matches all retained bytes except its fallback-call displacement.

| Measure | Shared case | Copied case |
|---|---:|---:|
| JIT counter ns/call | 207.044 | 205.679 |
| Native counter ns/call | 204.532 | 205.781 |
| JIT/native per-call ratio | 1.01228x | 0.99951x |
| JIT packets/s | 2505432 | 2510395 |
| Native packets/s | 2440796 | 2428858 |
| Installed native bytes | 10546 | 12995 |
| Native remaining-text cycles/call | 211.142 | 207.567 |
| Native copied-hash text cycles/call | 0 | 68.560 |
| Native ARRAY-dispatch text cycles/call | 3.360 | 4.037 |
| Native LPM-dispatch text cycles/call | 2.500 | 2.702 |
| Native external hash root cycles/app call | 155.885 | 97.009 |

Restoring the copied routine recovers no per-call speed in this diagnostic;
native counter time is about 0.6% higher, at 2449 additional bytes. The profile
shows hash work moving from external kernel roots into copied program text.
The roots lack exclusive ownership, so their sums are not an exact map-cost
partition. The source/installed-call evidence and this result do not support
removed LRU marking or the shared routine alone as sufficient explanations of
the reported Katran regression. Each case has one sample, separate guest/map
seeds, and the copy adds an entry jump/placement change. The original three-
sample slowdown remains an observation to explain; this pair is not its exact
historical image comparison. OTel shared/copy remains running under controller
1908860; analyze those cases before returning to lookup optimization.

OTel shared case completed

Run x86_kvm_corpus_20261116_211320_080784 completes with status ok and controller
exit zero, on the same diagnostic image/CPU/memory contract. JIT/native counter
times are 4156.394/5286.145 ns per app call; installed code is 167504/303930 B.
Integer-loop work sums 747643133/543473263 operations, or
12459976.88/9056991.57 ops/s using each worker's recorded elapsed time.
Those sums exclude stress-ng and are not the official throughput summary.
Per-language work remains in otel-shared.costs.json.

Native program-text cycles per app/root call, including samples in tail-called
programs with zero individual run_cnt, split as follows:

| Native range | Cycles/app call |
|---|---:|
| Remaining program text, including other inline work | 3570.823 |
| Exact LPM dispatch/lookup routine | 4333.540 |
| Exact ARRAY dispatch routine | 1429.922 |
| Exact user probe-read routine | 2393.348 |
| Exact kernel probe-read routine | 9.365 |

External hash roots contribute 1934.717 cycles/app call without exclusive
caller ownership (JIT: 1582.114). These are disjoint root observations, not
nanosecond cost measurements. The tail samples establish actual native
unwinder activity; retained logs contain no UnwindNativeAttempts/Frames metric
scrape, so they do not establish matching unwind totals or mix. This missing
supplement does not discard the completed run. The copied case is running.
The hash comparison remains open until that case completes.

OTel pair completed

Copied run x86_kvm_corpus_20261116_212124_709294 completes with app status ok
and exit zero. Eleven installed routines match the retained code outside the
external fallback-call displacement, with 30 typed raw calls redirected.
The unchanged native unwinder and hotspot programs have no typed raw-hash
calls; their generic map operations remain with the kernel.

| Measure | Shared case | Copied case |
|---|---:|---:|
| JIT counter ns/app call | 4156.394 | 4095.347 |
| Native counter ns/app call | 5286.145 | 5158.974 |
| JIT/native per-call ratio | 0.78628x | 0.79383x |
| Installed native bytes | 303930 | 330869 |
| Native remaining-text cycles/app call | 3570.823 | 3549.844 |
| Native copied-hash cycles/app call | 0 | 251.796 |
| Native LPM dispatch/lookup cycles/app call | 4333.540 | 4385.125 |
| Native ARRAY dispatch cycles/app call | 1429.922 | 1365.152 |
| Native user probe-read cycles/app call | 2393.348 | 2392.433 |
| Native kernel probe-read cycles/app call | 9.365 | 6.612 |
| External hash root cycles/app call, unowned | 1934.717 | 1632.635 |
| JIT integer-loop operations, excluding stress-ng | 747643133 | 743746300 |
| Native integer-loop operations, excluding stress-ng | 543473263 | 580103506 |

Copy improves native counter time by 2.4% in these two cases; its own JIT
control is also 1.5% faster. The control-normalized per-call gain is 1.00960x,
for 26939 additional installed bytes (eleven additions of 2449 B). That small
change does not explain the reported 1.021x to 0.801x historical throughput
change. LPM/ARRAY dispatch and probe-read costs remain large with either hash
routine. Root-cycle ownership and one-sample/placement limitations above still
apply, and exact unwind-counter equality remains unmeasured.

`make -f kprog/results/shared-hash-regression-20261116/Makefile compare`
reproduces comparison.json from all four completed cost reports. The copied
routine is retained as diagnostic input; the production shared-hash path stays.
Controller 1908860 is terminal and diagnostic CPUs 20-23 are released. The next
coordinator item is Katran's three-sample decay, using C's stats-on result when
it lands, before the cb-offset item.
