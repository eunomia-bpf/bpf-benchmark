# x86 application follow-up, 2026-11-07 UTC

This directory records unbound-native loader/runtime repairs and the coordinator's linked-image/map-lowering/compiler experiments. It does not establish generation-bound verification of these applications.

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
