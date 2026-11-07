# x86 application follow-up, 2026-11-07 UTC

This directory records x86 application repairs and native-only runtime results. The standard BCC corpus completes25/25 fresh generation-bound loads, and Katran completes1/1 with packet/action counters reconciled. OTel, Cilium, Tetragon and Tracee continue from the application table below. Historical unbound experiments below retain their original evidence boundaries.

## Tracee functional repair

| Attempt | Native replacements | Loader errors | Application completion |
|---|---:|---:|---|
| readonly constant repair only |151/151|0|kernel NULL dereference in sys_exit tail-call sequence|
| readonly + tail-call frame repair |151/151|0|baseline and native phases both `ok`|

The source and native `.rodata.str1.1` pools have different offsets (e.g. `unknown` at238 vs253). LOCAL immutable literals lacking matching source BTF are now retained in the native linker's private readonly storage. Using a native section offset in the app's map corrupts even literals that fit within bounds. Declared BTF variables continue to require exact identity, size, section and bounds. The data-layout ASAN/UBSAN check passes.

The first real run exposed a separate stack bug: Tracee's `PUSH RBP; PUSH RBX; PUSH RAX` allocates an8-byte local slot with PUSH RAX. Tail-call lowering had read saved BPF RBP at rsp+8 instead of rsp+16. The linker now counts those local PUSH slots, with overflow checking, alongside SUB allocation. All77 isolated linker unit tests pass, including the actual Tracee prologue and a mixed PUSH/SUB case. The private CLI excludes the older unpublished partial-write experiment.

Successful raw result: `corpus/results/x86_kvm_corpus_20261107_040625_927045`; failed first result: `...035123_042659`. Both full result trees and build/run logs are archived in `tracee-readonly-tail-frame-evidence.tar.gz`. Exact frozen source inputs are in `tracee-private-sources.tar.gz`, with hashes/base commits in `tracee-provenance.json`.

Each successful arm records151 BPF programs. Aggregate invocation deltas were9,143,523 baseline and12,426,337 native. Both used the same2-second,7-stressor command and reported7 passed/0 failed. These duration-driven workloads performed different operation counts; this is a functional smoke, not work-equivalent final timing. No events/samples counter equivalence or generation-bound acceptance is claimed.

Commands (from repository root):

```
make -f corpus/results/kprog_app_coverage_20261107/Makefile readonly-loader-build tail-frame-build
make -f corpus/results/kprog_app_coverage_20261107/Makefile readonly-image tail-frame-image
make -f corpus/results/kprog_app_coverage_20261107/Makefile readonly-corpus IMAGE=bpf-benchmark/kprog-tail-frame:c-20261107 IMAGE_TAR=/workspaces/.agent-state/kprog-lanes/C/tail-frame-runtime.image.tar SCRATCH=readonly-v2 APP=tracee/monitor CPUS=12-15 SAMPLES=1 WORKLOAD_DURATION=2
```

The frozen base image is `sha256:4853a1a52b6a436693df471a237939755f5513abdd0f8baf2acaec483452b03a`; private source/build directories are under lane C state. Recipes never replace the shared runtime image or kernel. The cache capture wrapper runs after the suite. The legacy Make docker recipe hardcodes python3; neither runtime-python nor a caller command override reliably crosses the guest Make boundary. The follow-up capture image uses a Docker ENTRYPOINT wrapper and leaves the successful Tracee image unchanged.

## Coordinator map/compiler item

Existing runtime logs already show type-specific and inline map lowering. Katran's spec has70 lookup sites:14 ARRAY,42 PERCPU_ARRAY,4 HASH,3 LRU_HASH,7 retained calls. Tetragon hot entry has9:2 ARRAY,1 PERCPU_ARRAY,4 HASH,2 retained calls. These are plan counts; actual linked-byte call classification is pending cache capture. No duplicate map-lowering implementation was added.

The first OFF attempt completed Tetragon but Katran failed before baseline (`modprobe tunnel4 Invalid argument`). The shared bzImage had been rebuilt04:12 while the frozen image contains older modules. Suite exit0 did not imply all-app success. Full per-app/error evidence is retained in `map-off-first-attempt.tar.gz`. ON did not start because CPU0-7 was occupied by another QEMU. The follow-up uses the frozen image's matching embedded kernel (SHA256 `903dd6e3879da5ebe398f52743ee7b1b1e39f41aea4e3a5fcee830bb14db1795`), with a diagnostic linked-image capture on CPU8-11. The coordinator's SECOND correction supersedes the OFF/ON pair: no rerun is queued. The active task is fixed-input per-run perf cost attribution; see `per-run-profile/README.md`.

The isolated compiler experiment enables jump/switch tables and sibling-call optimization. Both PIC hot-entry objects compile and produce proofs. Non-PIC large-model Katran currently exposes an absolute code-address relocation misidentified as helper0; Tetragon exposes unsupported R_X86_64_32 against a map. Those failures are retained in `native-options-v2/commands.json`; no candidate is installed or app program omitted. All canonical proof siblings must be regenerated before any changed object is timed.

## OTel fifth coverage pass

All14 captured programs generated, compiled and linked. The actual-type verifier accepts9 and rejects5: HotSpot pointer shift; Python partial-pointer masking; native unwinder complexity; Ruby BPF stack offset-528; Go labels unbounded helper destination. No specialization failure or omitted program. `otel5-coverage.json` records every identity/stage; `otel5-verifier-evidence.tar.gz` retains raw commands/logs. The earlier four-failure pass used older simulator inputs; the new Ruby failure remains open rather than being hidden by that result. These are verifier load results, not generation-bound runtime acceptance.

## Matching-kernel linked capture

`x86_kvm_corpus_20261107_042741_542193` completes both applications with statusok. Raw logs show Katran1 native replacement and Tetragon118, each0 loader failures; this is the observed replacement count, not a claim that every loaded program was native/verified. Exact cache-keyed templates, relocations, ABI/map/data layouts and full result/logs are in `linked-app-capture.tar.gz`. These are linked templates before final live map literal patch/upload; do not present them as final JIT bytes. Per-run profiling separately captures real JIT bytes and IDs.

## Direct SP numerical safety increment

`sp-entry-v1/` records the entry-SP correction:40,960 independent CPU ADD/SUB width cases0differences, SAME25negativecases19verifier/6specialization rejects and0accepted, and paired29microcompile/load checks with unchanged28accept/1oldCiliumreject. Private FULLv1's explicit legacy-environment failure and final FULLv2 exit0 are both retained. This closes the previously accepted direct-SP flag fixture; copied-stack pointer/alias numeric observations remain active work. No whole simulator or six-app bound-coverage completion is claimed.

## Fixed-input perf results

`per-run-profile/READY2M.md` records exclusiveCPU0 five-event PMU and actual BPF runtime for balancer_ingress/generic_kprobe_event, with loaded JIT bytes and full logs. Waiting for upstream Tetragon event-reader readiness fixes the initial startup confound. Katran nominal-warm native executes2M misses versus JIT0, so its slower observed path includes different state work; lowering-OFF/cache-key diagnostics investigate that defect. Original compiler-table single-window results show no benefit. No six-app bound-coverage completion is claimed.

Lowering-OFF follow-up completed12windows on exclusiveCPU0. Both Katran arms now have0warm-cache misses/2M inputs and matching VIP packets/bytes; actual ns/run77.360JIT/79.862native. `per-run-profile/LOWERING-OFF.md` separates this observation from the ON behavior defect and retains all5PMU counters, exactcachekeys, JITbytes and rawlogs. The production lowering fix remains pending.

## Map identity repair

`map-identity-v1/README.md` closes the observed Katran all-miss lowering defect. Actual IPv4 native code treated the dynamic LRU map as a1024-entry percpu array because source/native call orders were mistaken for map identity. General lookup/update selector changes retain the original helper when identity is unknown. Four regressions fail before and pass after; all83current/81frozen-linker tests pass. Same guest/input native-ON misses improve100->1/100, matching JIT/OFF with unchanged cache bytes/output. Fixed-image Tetragon retains118 native replacements/0failures and completes both10k-open/close controls. Unbound functional evidence; no timing on12-15 and no six-app verified-path completion claimed.

### Native-only service continuation, 2026-11-07

The current framework-priority work is in [trusted-service-bcc-set](trusted-service-bcc-set/README.md): actual frozen eight-tool BCC startup through the kernel-capsule service, fresh proofs, and strict bound mode. All thirteen completed replay archives are retained, including startup failures. Source-used map projection and valid dotted ELF symbol support are published; verified startup now awaits native load completion. The latest native-only replay accepted all25 observed loads with8/8 tools ready after the kernel-memset binding repair, then completed10000 opens/writes/closes. This is not complete BCC coverage or a same-work timing result. The earlier full formal check exited at the existing CMOV route cross-check with shared SP/CMOV work in progress; it is recorded as failure.

The [exact memory count repair](exact-memory-count/README.md) removes simulator truncation; the [XDP context identity repair](xdp-context-identity/README.md) retains actual context writes and passes13 unchanged positive generation-bound helper/map executions. Independent safety replay and full application completion remain pending.

The complete native-only BCC receipt is [native-only-complete.json](trusted-service-bcc-set/native-only-complete.json). It records25/25 generated, verifier-accepted and bound loads with per-program counters. Standard JIT/native paired work and timing remain pending.


### Current standard-runtime continuation

[Cilium full-identity replay](cilium-update-identity/README.md) closes R's33
update-name ambiguities: actual stats-off unbound151633_102078 replaces all177
application loads,0native failures, applicationok and bidirectional packet
counts/errors retained. Old/new linkers on16 identical captured plans fail/pass
respectively; all16 corrected blobs equal actual cached bytes. This is functional
unbound evidence, not generation-bound Cilium or performance acceptance.

[Standard native-only BCC bridge](native-only-runtime/README.md) now reaches the
kernel-backed service after removing its accidental forcednoop bytecode plan.
Run152434_982905 records25 requests,23 fresh compiled/accepted/bound, and2 Clang
SIGKILL compilation failures (inet_sock_set_state, sched_switch); zero recorded
verifier rejections. The native workload is not reached. Full raw results and
requests are retained. One identical8GiB replay is active, with full kernel logs
saved; no program was dropped or simulator rule changed to obtain acceptance.


### Standard BCC native-only runtime completed

[Standard BCC receipt](native-only-runtime/standard-bcc-8g.json) records actual
153239_875135 appok/metadata completed/verified_native_loader: all25 source
programs generate fresh proofs, are verifier-accepted/bound, and replace their
originals; zero specialization failures or verifier rejects. Every service native
ID matches the25-program post snapshot; prebuilt_proof=0 on all25 receipts.
Both unchanged four-stressor workload arms complete; syscall bogo counts are514
in both, other duration-driven operation counts differ and raw per-program
counters are retained. This is functional runtime evidence, not equal-work or
performance acceptance. The preceding two Clang SIGKILLs resolve at8GiB with
byte-identical generated C/native proofs;4GiB OOM remains unconfirmed. All failed
and successful raw data are retained; the closed guest disk/tar are removed.
R timing commands and exact reproduction inputs are in the linked README.


## Native-only application coverage, November7 evening batch

Each row records the latest closed application batch through the common
registered native-only service. The baseline census lists startup syscall
attempts (including probes) and resident application snapshots where available;
each linked report keeps the full named-load inventory. Source and image epochs
stay separate across rows. Whole-application completion and matching-work
measurement continue from the reported failure classes.

| Application | Baseline census | Generated | Compiled | Accepted/bound | Submission / specialization errors | Verifier rejections | Runtime evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [Earlier functional batch153239](native-only-runtime/standard-bcc-8g.json) |
| OTel | 13 resident | 3 | 3 | 2 | 0 | 1: verifier exploration limit | [233455 batch](otel-cmp-identity/README.md) |
| Cilium | 72 resident | 2 | 2 | 1 | 0 | 1: BPF stack offset -536 | [232956 batch](cilium-helper-scoped/README.md) |
| Tetragon | 311 startup attempts; 287 resident | 4 | 4 | 3 | 0 | 1: 8193-jump complexity | [225009 batch](tetragon-cmp-resources/README.md) |
| Katran | 1 | 1 | 1 | 1 | 0 | 0 | [213447 bound batch](katran-tagged-storage/README.md) |
| Tracee | 151 resident | 6 | 6 | 5 | 0 | 1: readonly index range | [231936 batch](tracee-resource-scoped/README.md) |

Tracee baseline now completes151 application loads on the coherent kernel BTF
epoch. The shared native CORE helper-preservation repair48ff82cfb restores its
upstream fault/helper contract in a new native-input epoch; whole-application
replay follows the current OTel private generic stack candidate. The native
symbol inventory remains173 functions/87 maps and input025fe5e116ed becomes
7479850e2345. All application/workload sources and baseline BPF objects retain
their captured identities. The generic CORE mechanism result records102400
valid reads per epoch and84 protected reads on the x86-64 host, using x86/ARM
field-selector configurations and kernel/legacy helper contract models. Universal safety evidence comes from simulator/token/link
laws; these tables and archives record runtime observations.


The closed [OTel generic narrow-stack candidate202331](otel-stack-narrow/README.md)
also generates/compiles3 requests and binds2, reaching1,000,001 verifier
instructions (75,937 total states). Its636,928-case byte oracle passes; the
candidate stays private and the production header remains47fb. The next
representation repair continues from this complete runtime result. Tracee's
helper-preserving whole-application replay is now active in a separate serial
batch with native input7479850e2345 and exact new image/input identities.


The [Tracee CORE helper-preserving batch203243](tracee-core-helper/README.md)
closes the register-frame read failure at sys_enter_init and fresh-binds two
entries. Its next request reaches helper source stack relation analysis. The
shared [affine stack-origin repair](helper-stack-affine/README.md) preserves
finite private-stack/external alternatives through displacement, known index
and constant ADD/SUB while retaining opaque-byte checks. The generic checker
passes141 cases; whole Tetragon/Tracee replay follows the new source epoch.

The affine/readonly/LEA producer replay records two bound requests for each of
Tetragon and Tracee, followed by helper-source stack relation errors. Their new
linked archives keep the exact source epoch. The shared slot-join repair aligns
external-value defaults across reads and merges, passes143generic ABI controls,
and proceeds to a fresh whole-application batch.

The consistent-slot-join runtime batch closes both recorded helper-source
relation failures. Tetragon reaches3generated/compiled and2bound, followed by
native-stub EINVAL with34919processed instructions. Tracee reaches6generated/
compiled and5bound, followed by an indexed readonly-map extent rejection.
The linked batch reports distinguish that native-stub error from a confirmed
verifier rejection and preserve the full current source epochs.


[Katran private complete-register storage](katran-partial-storage/README.md) moves
past the partial pointer mask to an unbounded index after a scalar spill/reload.
The original native input stays fixed; provenance-selected storage is the next
generic candidate. The production RSP LEA sum now uses unsigned wrapping addition,
with48553route/62400composition/8401offset cases underUBSan and V's universal law.

Katran's whole native-only registered-service epoch213447 binds1/1 and completes
the existing workload. Both arms report one BPF invocation and one XDP TX per
sent packet, with LRU hit-path counters and miss0. JIT2318117packets reaches the
receiver; native2386430packets yields2377743received plus5158TX and3529receiver
drops. The exact generic provenance-selected write include is retained in the
linked raw archive; production generator adoption follows the current Tracee epoch.


The whole Katran header cf27e323c885 is now the production generated register-write
header, with its common generator synchronized. Regeneration,143encoder/ABI,
3072CLhost/19renderedMOVX and100448MOVhost cases pass. R receives the trusted-path
Katran timing request; the complete29suite follows this source adoption.


The [current complete pure29 suite](micro-wrapping-epoch/README.md) generates,
compiles, accepts and binds29/29 through the common kernel-owned service.
All58JIT/native samples match the expected64-bit result and action; all29
terminal archives match their kernel native hashes. Launch sources retain
their captured identities, with driver/collector exit0 and actual result215009.


The [shared readonly-label repair](x86-readonly-labels/README.md) aligns proof
and kernel PC32 addresses for zero-size LCPI/anonymous labels through one
section-identity/displacement resolver. Current production native-link tests
pass88/88, including243constructedELF address/extent combinations and the
prior-source failure control. Runtime adoption follows the coherent image
boundary while active runtime inputs retain their recorded executable bytes.


The [Tracee whole-application narrow-read replay214037](tracee-narrow-range/README.md)
records151JIT app loads,6fresh generated/compiled requests and5bound. The next
request, sys_exit_submit, reaches the verifier indexed-read boundary:80-byte
readonly object,maximum offset1036,read4bytes,2154processed instructions/91states.
All6terminal native identities and full logs remain retained; private executed
sources and the concurrent shared guest.py change are recorded separately.
The generic CMP representation trial continues from this observed failure class.


The [whole Tetragon memcpy-binding replay221545](tetragon-memcpy-replay/README.md)
closes the earlier wake_up_new_task target-materialization failure:4fresh
generated/compiled requests bind4/4, allnative hashes and shim boundIDs agree.
The next upstream execve_send load stops at its manifest length selector before
generation; libbpf appends a928-byte callback to its10368-byte entry. The common
manifest scanner is being repaired to describe the complete11296-byte source.


The [generic source-closure scanner](manifest-source-closure/README.md) now
counts reachable direct-call/function-address callbacks and their helpers,
matching libbpf assembly. Three compiled BPF regressions and existing C++
manifest checks pass. Tetragon execve_send selector becomes11296bytes; the
next whole-app replay consumes the regenerated manifest with fixed native
objects, workload and common kernel-owned generation/binding service.


The [native resource caller](native-resource-caller/README.md) now carries
deduplicated live map FDs into the kernel-owned capsule through T c94fbff01.
Its component build and12service tests pass; actual kernel resource mutation,
close and authorization controls are retained by T. The next wholeCilium
replay consumes matching caller/worker/module inputs, preserving application
workloads and the common fresh generation/verifier/binding service.


The [Tetragon complete-manifest replay223215](tetragon-manifest-replay/README.md)
closes execve_send source selection and freshly generates/compiles5requests,
with4bound. Request5reaches the actual verifier8193-jump sequence limit,
188982processed instructions and1926states. The next generic CMP representation
trial retains native/application/workload inputs and the common service.


The [Tracee CMP/read batch223700](tracee-cmp-replay/README.md) compiles6requests
and binds5, then reaches request6activation after app startup closes. The
verified-native runner now waits for actual health/process exit, using the
existing readiness loop. All16incremental-corpus tests pass, including simulated
400s successful verified startup, ordinary phase deadlines and early exit.
The next wholeTracee retry preserves native/workload/ISA/compiler inputs.


The [Cilium resource-capsule batch224658](cilium-native-resources/README.md) reaches fresh generation with kernel-authenticated extra native maps, then helper189 declaration errors during compilation. Its generic helper/XDP data_meta candidate passes four UBSan ABI controls and compiles the actual generated BPF source. The paired [entry-resource closure](native-resource-scope/README.md) passes89linker/12service checks and scopes Tracee/Cilium first-entry resources to2/6symbols. Whole Tracee then Cilium replay is active.

The [Tetragon CMP/resource batch225009](tetragon-cmp-resources/README.md) generates/compiles4requests and binds3, then reaches8193-jump verifier complexity with189726processed instructions/1926states. The [OTel batch225459](otel-cmp-resources/README.md) generates/compiles2requests and binds1, then reaches perf-event-output size range checking with805processed instructions/27states. The [Tracee verified-startup batch230126](tracee-bound-startup/README.md) records one kernel resource-count refusal before service generation; current scoped-resource replay consumes the common closure repair. Each linked report retains the exact epoch, baseline census, full raw logs and next repair class.


The current serial continuation consumes entry-scoped resource metadata for Tracee/Cilium, then the [comparison-identity and native-width stack candidates](native-compare-load-width/README.md) for OTel/Tetragon. Their component checks and compilation pass; whole-application verifier and work receipts follow each closed guest. Earlier epochs retain their individual coverage and source identities in the linked raw archives.


The [Tracee scoped-resource batch231936](tracee-resource-scoped/README.md) completes6fresh generated/compiled requests, binds5, and reaches the actual sys_exit_submit readonly-index verifier result. Entry resource selection and verified startup both reach this new service epoch; max index remains1036for80bytes,2154processed instructions/91states. The next generic narrow-value trial preserves the exact native comparisons and table address.


The [Cilium helper/scoped-resource batch232956](cilium-helper-scoped/README.md) freshly generates/compiles2requests and binds cil_xdp_entry. Its next TC request reaches stack offset-536 with312bytes of modeled native stack and a padded skb ABI mirror. Private live TC context projection continues from the exact field accesses; actual native hashes and six first-entry kernel resources remain recorded.


The [OTel CMP-operand identity batch233455](otel-cmp-identity/README.md) freshly binds read_task_struct and perf_unwind_stop, closing the perf-event size-range frontier. Its next perf_unwind_native request reaches1000001processed verifier instructions and64823total states. Generic native-width stack reads and common narrow-value identity continue with the captured native/application/workload inputs.
