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
