# Key-size C hash-family calls (P3)

Coordinator assignment 2026-11-26T06:25Z: use header C routines returning the
hash-table element for HASH, LRU_HASH, PERCPU_HASH and HASH_OF_MAPS. Preserve the
LTO value-returning entry and native-link's existing direct-call postprocessing.
The module derives its private layout from the boot kernel BTF at build time;
both loaders select its key-size symbol when present and otherwise retain
`__htab_map_lookup_elem`. The x86 full timing run stays frozen.

The host check reuses the kernel-header oracle and guarded-key/collision/nulls
restart driver, adding an assertion relating the element and value entries.
The offline target reuses the existing whole-stage linker check for both ISAs.
Raw check results and guest logs will be retained here as they complete.

## Offline results

Source 655ae2755: host check passes 1,032 kernel hash oracle cases, 143,388
C/native lookups, one nulls restart, 589 generic calls and 560 same-map alias
cases (`host-first/report.json`). This reuses the requested LTO driver and its 8- and 16-byte fixture maps;
the guarded driver also covers every key size through 256 bytes. Both element and value returns are checked.

Whole-stage offline links: x86 289/289; arm64 287/289. The two existing arm64
BCC ADR_GOT failures remain (`biosnoop.native.o:block_rq_insert` is the example).
Both architecture loader shared libraries and modules build successfully.
The first module builds report missing prototypes for the exported routines;
the follow-up adds their declarations before the image build.

`run.sh` rebuilds the sole x86 image under the image lock, removes the replaced
image, then runs the unchanged six-app functional target with its default
one 10-second sample. Build concurrency is two; no timing setting changes.

The attempted recursive image dry-run entered the kernel link recipe despite
`make -n` (GNU make executes recursive recipes). Its process group was stopped
before publication; the log stays in `image-dry-run.log`. The normal image
build below replaces any partial build output in the canonical base.

## Corpus key-size census

The staged x86 objects' DWARF map declarations contain hash-family keys of
2, 4, 8, 12, 14, 16, 20, 24, 32, 36, 38, 40, 41, 48, 64, 88, 224, 256 and
260 bytes (`key-sizes.json`, with each map and object). The module now emits
exactly these 19 routines instead of 66; 88 and 260 were absent from the first
set. The first image build was stopped before publication to include these
sizes in the one guest confirmation. Its raw log is `image-first.log`.
The guarded host driver is extended through 260 bytes for this actual corpus
boundary. The first census attempts exposed pointer-width and section-symbol
handling gaps in the census script; both failed logs are retained.

The loader-selection fixture invokes each production loader's selection code
for all four map types, with specialized, zero and absent symbols. Its first
missing-generic test accidentally cleared the initialized cache and caused a
real kallsyms reread; retaining an unrelated sentinel tests the intended missing
symbol case. `loader-selection-first.log` preserves that fixture failure.

## Final host subset

The 260-byte driver passes 1,044 kernel hash oracle cases, 145,628 lookups,
one nulls restart, 589 generic calls and 560 same-map alias cases
(`host/report.json`). Both production loader-selection fixtures pass 12
specialized/zero/absent target cases plus missing-generic failure. Both modules
export exactly the 19 corpus key-size entries, with layout constants from
that architecture's boot kernel BTF (`module-coverage.json`). The final arm64
module build is warning-free. The two fixture setup failures remain in their
original logs; neither was a production lookup failure.

`finish.sh` is a finite callback for the running build/check controller. It
collects each app's status, native replacements and native-load failures,
commits the raw app/counter/shim records under the git lock, and wakes the
stopped perf lane to review the outcome and complete its todo record. It also
wakes the lane on failure. The full timing target is never invoked.

## First callback outcome, 2026-11-26T06:50Z

Publication 3b7bf174a contains an incomplete attempt: `controller_completed`
is false and `checks` is empty. The callback's status 0 describes collection
and publication, not the build or functional check. The image build log ends
in native Tetragon compilation without a compiler error or Make completion.
The foreground controller disappeared when its owning turn ended; the
detached callback survived. No guest started, no replacement image was
published, and no image cleanup occurred. The original x86 image remains
17aaf1ff3dda. This is a job-lifetime failure, not an application test result.

The retry launches both controller and callback with `setsid nohup`, retains
outputs in a fresh attempt directory, and records the controller's own exit
status separately. The frozen image and functional-check Make targets remain
unchanged. All first-attempt records are retained.

## Detached retry outcome, 2026-11-26T07:10Z

`retry-20261126T065149Z/image.log` confirms the image build and tar export
completed, publishing x86 image fb53150e89ea. The controller then exited 1:
its redundant `docker image rm` reported the previous image 17aaf1ff3dda was
already absent. The actor that removed it is not established. No guest check
started (`checks=[]`); this is a cleanup-step failure, not an application
functional failure. The previous image is absent and only the current x86
image remains alongside the arm64 image.

The wrapper now lists images successfully before deciding whether removal
is needed, and retains the image lock through publication and cleanup.
`check.sh` runs the frozen functional target against the image already built;
it avoids a redundant image rebuild. The check keeps the default six apps,
one 10-second sample and stats on. Its outer address-space limit is 80 GiB;
no benchmark setting changes. Full timing remains frozen.

## Completed six-app functional confirmation, 2026-11-26T07:38:26Z

The unchanged `make -C kprog/perf/one-image check` completed on image
fb53150e89ea, one 10-second sample per app with stats on. Controller exit is 0.
Every raw run has metadata status `completed`, suite/app status `ok`, and an
empty app error. `check-20261126T071525Z/guest-summary.json` agrees with all
six raw app records and shim logs. Raw records were pushed in ce6ab9416.

| App | Make rc | App status | Native replacements | Native-load failures | Raw run |
|---|---:|---|---:|---:|---|
| otelcol-ebpf-profiler/profiling | 0 | ok | 14 | 0 | [x86_kvm_corpus_20261126_072004_258004](../../../corpus/results/x86_kvm_corpus_20261126_072004_258004) |
| bcc/set | 0 | ok | 25 | 0 | [x86_kvm_corpus_20261126_072235_795145](../../../corpus/results/x86_kvm_corpus_20261126_072235_795145) |
| cilium/agent | 0 | ok | 135 | 0 | [x86_kvm_corpus_20261126_072536_648665](../../../corpus/results/x86_kvm_corpus_20261126_072536_648665) |
| tetragon/observer | 0 | ok | 288 | 0 | [x86_kvm_corpus_20261126_072843_366158](../../../corpus/results/x86_kvm_corpus_20261126_072843_366158) |
| tracee/monitor | 0 | ok | 169 | 0 | [x86_kvm_corpus_20261126_073319_240233](../../../corpus/results/x86_kvm_corpus_20261126_073319_240233) |
| katran | 0 | ok | 1 | 0 | [x86_kvm_corpus_20261126_073722_681565](../../../corpus/results/x86_kvm_corpus_20261126_073722_681565) |

P3's requested implementation, host checks, both-ISA builds/offline links and
x86 guest functional confirmation are complete. The earlier arm64 offline
result remains 287/289 with its two existing BCC ADR_GOT cases. No functional
repair or repeat run is needed after this confirmation. These are functional
diagnostics; the full x86 timing run stays frozen and no speedup is inferred.
The cleanup record was already committed in 2a35bf339; this check reused the
published image and removed no image or raw data.


## Application-independent key range, 2026-11-26

Coordinator11:06Z and the operator's11:03Z words replace the historical
19-size corpus census above with one general mechanism: every key size from
1 through 512 bytes (MAX_BPF_STACK). The same C source emits all 512 entries
on x86 and arm64. Both loaders explicitly use the kernel lookup above 512;
there is no app/program list or selection configuration. Missing specialized
symbols within the range retain the existing kernel lookup behavior.

`range-512-20261126` records the subset checks: both modules build and export
exactly all 512 sizes, with BTF layout448,824,832,16,0,0,0,40,48; x86 module
5,555,112 B, arm64 module8,360,328 B. Both loader libraries build. Each loader
selection fixture passes72 specialized/zero/absent cases across the four map
types and sizes1,14,511,512,513,1024, including an available but deliberately
ignored symbol above512, plus the missing-generic error. The guarded kernel
oracle now covers every size0..512:2052 hash cases,286748 element/value lookup
cases,one nulls restart,589 generic calls and560 same-map aliases. Its initial
invocation also refreshed the existing host receipt; the subsequent scoped
receipt is in range-512-20261126/host. Prior receipts remain in Git history.

The next step rebuilds the sole x86 image and runs the unchanged six-app
functional check, defaults1x10s,stats-on. Image/check outcomes will be recorded
in a fresh range-512 attempt directory. No full timing is authorized here.
The separate Tetragon/OTel within-design optimization remains open.


## Completed 512-size functional confirmation

Source42cd0d591 rebuilt the sole x86 image as7a11cb60285a on2026-11-26.
The unchanged six-app check completed with controller0, all six make rc0,
app ok/error empty, samples1/workload10s/stats true. Raw publicationc5dc2391b
and range-512-image-20261126T121638Z/guest-summary.json record:

| app | native replacements | native-load failures | raw run |
|---|---:|---:|---|
| otelcol-ebpf-profiler/profiling | 14 | 0 | 20261126_122957_348057 |
| bcc/set | 25 | 0 | 20261126_123242_613594 |
| cilium/agent | 135 | 0 | 20261126_123546_793159 |
| tetragon/observer | 288 | 0 | 20261126_123833_463916 |
| tracee/monitor | 169 | 0 | 20261126_124300_184529 |
| katran | 1 | 0 | 20261126_124642_748933 |

No functional failure needs a fix. The512-size range task is complete.
The old imagefb53150e89ea was already absent when the wrapper checked it;
the removal actor is unknown. The cleanup record reflects that observation,
not a successful redundant removal. The generic_tracepoint and
native_tracer_entry performance task remains open. These10s counters are
diagnostics; full timing is frozen.
