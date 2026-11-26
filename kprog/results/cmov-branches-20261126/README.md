# Common branch lowering after source unrolling

The current-image OTel profile is in
`../p3-attribution-20261126/otel-current-20261126T130232Z/otel-profile`.
Guest/app completed successfully on image7a11cb60285a; kernel messages show no
workload-time warning/error. Owner-specific54s workload windows use QEMU522509.
The native unwinder has90083 cycle samples versus59003 for the eBPF unwinder;
array_map_lookup_elem has28912 versus7403. Trie lookup140260 versus145689 and
copy_from_user_nofault90607 versus102169 do not show an added native cost.
The array helper's+7 region has12316 native versus1011 eBPF samples; sample
IPs may skid and are not exact instruction latencies. The native body's hot
regions repeatedly compare delta->addrLow and execute dependent cmov pairs
to update the binary-search bounds. The eBPF JIT uses conditional branches.
This identifies a dependency-chain candidate, not yet a measured fix.

LLVM18's [X86CmovConversion implementation](https://github.com/llvm/llvm-project/blob/llvmorg-18.1.8/llvm/lib/Target/X86/X86CmovConversion.cpp)
normally considers register cmovs in innermost machine loops. Source-unrolled
searches no longer have that loop structure. Its existing force-all option
also converts those groups. The candidate adds
`-mllvm -x86-cmov-converter-force-all` to the common x86 architecture flags,
used by every app including Katran. There is no app/program selection or new
configuration. Arm64 has no x86 cmov instruction or option.

The producer check rebuilt the canonical OTel objects/stage in place:
perf_unwind_native changes from140 cmovs/5517 instructions to0/5493, with
conditional jumps613 to689. Before/after disassemblies and code-generation.json
are retained here; no second object build is kept. Makefile dependencies now
rebuild every native object when the common flags change; previously most
cached objects did not depend on that file, so a flag-only edit could leave
them unchanged. Tetragon already recompiles its native set unconditionally.

run.sh produces all six apps under the same flags, records the whole-stage
offline link, then calls the existing sole-image builder and frozen six-app
make check (1x10s,stats-on). Compiler caps16GiB/CPU18-19/j2; image/timing locks
protect the shared base. The normal finite callback publishes actual results
and wakes the lane. Read the offline log's actual counts; the existing offline
tool reports failures in its output. A completed collection is not a claim of
performance improvement or that generic_tracepoint has been fixed. Review the
six app results, then take the necessary affected-app repetitions. Full timing,
workloads, paper and settings remain frozen. C5/C6 remain deferred; C7/C8 and
direct-native hash-walk unrolling remain excluded.


## First six-app result

Image68655f5c6c0d completed the frozen six-app functional check at
2026-11-26T13:55:27Z. All six make rc0/app ok/error empty; native replacements
OTel14/BCC25/Cilium135/Tetragon288/Tracee169/Katran1, failures0 each.
Raw results are published in b6d8e5b56 and trial-20261126T132308Z.
The old image7a11cb60285a was already absent when the cleanup wrapper
checked; its remover is unknown. The sole current image is68655f5c6c0d.

| app | previous eBPF/native ns per call | candidate eBPF/native ns per call |
|---|---:|---:|
| otelcol-ebpf-profiler/profiling | 3506.3 / 3726.9 | 3326.1 / 3463.1 |
| bcc/set | 107.0 / 101.0 | 103.4 / 100.6 |
| cilium/agent | 898.5 / 687.2 | 743.1 / 616.3 |
| tetragon/observer | 1250.0 / 1599.1 | 1272.2 / 687.3 |
| tracee/monitor | 397.3 / 180.9 | 379.8 / 161.3 |
| katran | 182.6 / 168.5 | 176.3 / 161.4 |

Tetragon's native generic_tracepoint is1545.3 ns versus eBPF1716.1 (previous
native3733.2); OTel native3463.1 remains slower than eBPF3326.1. Every native
absolute aggregate cost is below the previous single check, while the eBPF
costs also vary; normalized ratios are not uniformly improved. These are
single10s diagnostics, not causal speedups or a no-regression declaration.
Three Tetragon then three OTel default checks follow on the unchanged image.
The diagnostic collector now records source/image under the same timing/image
locks as each check, so later rebuilds cannot silently change its provenance.

The actual offline result is286/286, zero lookup-metadata stops. The current
x86 and arm64 catalogs have exactly the same286 distinct(object,symbol) pairs:
BCC26/Katran3/Tracee96/Cilium61/Tetragon76/OTel24. entry-census.json preserves
both sets, including compiler-internal text symbols. Older offline logs say289;
they do not include the matching manifest snapshot, so the three historical
pair identities cannot be established from those aggregate receipts alone.
This count difference is retained as a provenance limitation. It is not a
functional load failure: all loaded app programs still install natively with
the same replacement counts and zero failures. No program is excluded.


Offline scope: the existing script processes only entries with an explicit
symbol. The current manifest also contains49 groups without one (BCC3,
Tracee17,Cilium10,Tetragon17,OTel2), where the runtime loader resolves the
source program against the object's matching symbols. These groups are
recorded in entry-census.json; they are not excluded from native installation.
The guest functional check is the evidence for all actual app loads, including
these cases. The286/286 figure is the explicit-symbol offline subset.


The same existing05-29 evaluator reports workload throughput native/eBPF:
OTel0.962x, BCC0.999x, Cilium1.091x, Tetragon1.139x, Tracee1.786x,
Katran1.037x. The paired per-call figures and raw run IDs are in
trial-20261126T132308Z/diagnostic-evaluator.txt. Throughput and per-call costs
are both diagnostics here; neither changes the frozen official timing.
