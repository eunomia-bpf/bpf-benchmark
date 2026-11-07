# x86 application follow-up, 2026-11-07 UTC

This directory records x86 application repairs and native-only runtime results. The standard BCC corpus now completes25/25 fresh generation-bound loads; the other five applications remain to be completed on that path. Historical unbound experiments below retain their original evidence boundaries.

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

Each row follows actual application startup through the common registered
native-only service. Application totals count accepted baseline load instances;
resident snapshots and feature-probe counts appear in each linked batch. Source
and image epochs stay separate across rows. Whole-application completion and
matching-work measurement continue from the reported failure classes.

| Application | Observed app loads | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections | Runtime evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [Earlier functional batch153239](native-only-runtime/standard-bcc-8g.json) |
| OTel | 14 | 3 | 3 | 2 | 0 | 1: exploration limit | [192310 batch](otel-narrow-load/README.md) |
| Cilium | 163 | 1 | 0 | 0 | 1: map declaration | 0 | [201146 batch](native-modules-cilium__agent/README.md) |
| Tetragon | 289 | 2 | 2 | 2 | 1: helper stack relation | 0 | [201956 batch](native-coherent-tetragon__observer/README.md) |
| Katran | 1 | 1 | 1 | 0 | 0 | 1: partial pointer-register write | [201524 batch](native-coherent-katran/README.md) |
| Tracee | 151 | 2 | 2 | 1 | 0 | 1: raw-context scalar address | [200640 batch](native-modules-tracee__monitor/README.md) |

Tracee baseline now completes151 application loads on the coherent kernel BTF
epoch. The shared native CORE helper-preservation repair48ff82cfb restores its
upstream fault/helper contract in a new native-input epoch; whole-application
replay follows the current OTel private generic stack candidate. The native
symbol inventory remains173 functions/87 maps and input025fe5e116ed becomes
7479850e2345. All application/workload sources and baseline BPF objects retain
their captured identities. The generic CORE mechanism result records102400
valid reads per epoch and84 protected reads across x86/ARM and kernel/legacy
helper variants. Universal safety evidence comes from simulator/token/link
laws; these tables and archives record runtime observations.
