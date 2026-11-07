# Native-only BCC through the standard corpus framework

Actual run `x86_kvm_corpus_20261107_153239_875135` completes with application
status **ok**, metadata **completed**, and mode **verified_native_loader**.
All25 application programs across the eight corpus BCC tools are generated
fresh by the registered service, verifier-accepted, bound and replaced. No
native load fails. The25 service-completed native IDs exactly equal the25
program IDs in the native measurement snapshot. All25 shim timing receipts
report bound_required=1 and prebuilt_proof=0. Feature probes pass unchanged
(52 observed skip receipts), as required by the operator.

| Tool | Programs total | Proof generated | Verifier accepted/bound | Specialization failed | Verifier rejected |
| --- | ---: | ---: | ---: | ---: | ---: |
| capable |2|2|2|0|0|
| biosnoop |4|4|4|0|0|
| vfsstat |5|5|5|0|0|
| opensnoop |4|4|4|0|0|
| syscount |2|2|2|0|0|
| tcpconnect |4|4|4|0|0|
| tcplife |1|1|1|0|0|
| runqlat |3|3|3|0|0|
| Total |25|25|25|0|0|

The application container supplies only native ELF/entry/typed metadata to
the kernel. A service registered OUTSIDE that container receives the retained
kernel input, generates and compiles fresh simulator BPF, and loads it through
the authenticated kernel/service route. Its0700 work directory is outside
the application result mount. The existing corpus driver owns the JIT baseline,
stop/restart, native arm and unchanged workload/counter collection. No upstream
runner, app workload, native program or simulator semantics changed here.
This is actual native-only runtime acceptance, not an all-ISA/O1-O4 theorem.

## Work and counters

Both arms run the standard stress_ng_bcc_hook_hot command with syscall-fast75,
cap, set and sockfd stressors, the same2second requested duration and one sample.
All four stressors pass in both arms. Both retain25 per-program run/time deltas.
The counts are duration-driven and include background activity; they are not
an equality assertion or a performance conclusion from this functional sample.

| Arm | syscall bogo ops | cap | set | sockfd | Aggregate BPF invocations |
| --- | ---: | ---: | ---: | ---: | ---: |
| JIT |514|208541|25344|156214|12167274|
| Verified native |514|262177|20642|75230|10359382|

Observed wall times2.083/4.082seconds can exceed the requested2second duration.
The syscall count514 occurs in BOTH arms here and in earlier no-BPF controls;
it is not alone evidence that native instrumentation changed the work. Full
stdout/stderr and counters are available for R's same-work analysis and longer
measurements. No event-count equivalence is inferred from aggregate BPF runs.

## Failures retained and changes

| Standard run | Accepted/bound | Failure class | App/native measurement |
| --- | ---: | --- | --- |
|143508_623079|0|forced noop bytecode plan fails target.json during startup probes|error/not reached|
|152434_982905 (4GiB)|23/25|2 Clang SIGKILLs: inet_sock_set_state, sched_switch|error/not reached|
|153239_875135 (8GiB)|25/25|none|ok/completed|

The bridge accidentally forced BPFREJIT_BENCH_PASSES=noop, which caused the
standard driver to run a bytecode plan before native replacement. Removing
that forced setting uses the existing empty native-arm pass list and leaves
feature probes unchanged. The first corrected4GiB run generated25 requests,
with two compiler kills; these are compilation failures, not verifier rejects.
compile-input-comparison.json proves those two generated C files AND native
proof ELFs are byte-identical to the previously accepted direct-service inputs;
the generator, simulator header and trusted worker identities also match.
Increasing only guest memory4->8GiB resolves both in the standard run. SIGKILL
alone does not prove the4GiB failure was OOM. The8GiB full dmesg contains no
OOM/killed-process/page-allocation-failure message; dmesg and meminfo are saved.

The two earlier setup errors are retained as well: first the service directory
was inside the writable result mount (stopped before any native request), then
the relocated service state was read-only in the guest (failed registration).
Its final private path/mode and all request archives are recorded. No setup
failure is counted as a generated proof, verifier rejection or app acceptance.

## Reproduction and raw evidence

```
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus
```

This uses the cached image a20b2981171de35a85d1827760701e157efa17347c8705374f146a5d7dbe1a90,
matching incremental TV kernel and15 matching kinsn modules. It does not rebuild
an image/kernel. package-inputs.json pins1546 initial source/artifact inputs;
image.json records layer ancestry, binary equality and image/tar hashes. Each
service request separately pins its actual generator/header/service/linker/
trusted-loader inputs. The per-request records are authoritative for that run.

standard-bcc-8g.json contains the per-tool table, every native/source identity,
actual native counter and both workload counters. standard-bcc-8g-result.tar.gz
is the complete raw corpus tree. corpus-20261107T153640028572Z.tar.gz retains
the complete service/driver logs, all25 request archives, full kernel log and
meminfo. Their hashes are in the receipt. standard-bcc.json and its full result
archive retain the23/25 run; initial-noop-failure.json and its full result retain
the preceding failure. All earlier setup archives/logs remain available.

CPUS selects host affinity (default16-19), SAMPLES and WORKLOAD_DURATION retain
standard corpus meanings, and existing BPFREJIT_CORPUS_BPF_STATS selects stats
(default1). Timing commands on R's CPUs, when free:

```
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus CPUS=0-7 SAMPLES=3 WORKLOAD_DURATION=30 BPFREJIT_CORPUS_BPF_STATS=0
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus CPUS=0-7 SAMPLES=3 WORKLOAD_DURATION=30 BPFREJIT_CORPUS_BPF_STATS=1
```

The new affinity/stats forwarding passes make dry-run, shell syntax and Python
syntax checks; actual successful evidence above is statsON/C16-19/one2second
sample. R owns counterbalancing and same-work interpretation. These commands
are preparation for that measurement, not a claim it has already run.

The corpus EXIT trap removes its own guest var-tmp Docker disk and exported
image tar after checking open users. Later runs re-export the cached image.
The successful8GiB run's cleanup receipt confirms both removed after the guest
and collector closed (about15GiB allocated space). Raw results/requests/logs,
compiled caches and provenance remain. The initial package preparation commands
and completed build logs remain alongside for rebuilding only when inputs change.


Independent experiments can override the existing Make STATE variable. It is
forwarded explicitly into the guest driver, including the service's private
work directory and image-tar path. C's OTel continuation uses lane-private
native-only-otel state; R's BCC timing keeps the default native-only-runtime
state. Each experiment cleans only its own disk/tar. Timestamped archives are
unique; the final JSON line names the exact archive for that invocation.


## OTel native-only continuation: missing tail-map transport

Initial actual run154845_053809 completes the JIT mixed-language workload but
fails native startup. The raw log observes14 application initialization/program
loads (including read_task_struct),13 resident measurement programs, and three
feature probes. Only two application loads are reached on the strict native
restart before it stops;12 are not yet reached, not classified as unsupported.

| Native reached | Simulator generated | Compiled | Accepted/bound | Verifier rejected | Failure |
| ---: | ---: | ---: | ---: | ---: | --- |
|2|2|2|1|0|perf_unwind_stop: native-link missing perf_progs tail_call_maps entry|

read_task_struct is fresh-bound. The second request fails during native linking,
BEFORE verifier admission. Kernel capsule facts already prove PROG_ARRAY ID250
is used by the pinned source program; canonical perf_progs/kprobe_progs aliases
are present. The trusted worker reconstructed map aliases from those facts but
did not populate the existing source_tail_call_maps set. The one-line common
loader fix calls existing add_source_tail_call_map after exact source-used
map-ID validation. That helper checks the actual PROG_ARRAY type and deduplicates
by kernel ID. No map/name/ordinal guess, new authority, verifier relaxation or
native program omission is introduced. Shared x86/ARM metadata transport is fixed.

Warm static/shared loader and trusted-native-loader builds plus all9 existing
trusted-service checks pass. Live replay after the fix follows; build success
alone does not establish OTel application acceptance. The successful BCC raw
receipts remain separate and unchanged. The client image/kernel/module are reused.

otel-native-only.json is the complete initial receipt; otel-tail-call-transport.json
captures the actual missing map set and kernel-owned map identities. The receipt
names its exact service/request archive and hashes, and
otel-native-only-result.tar.gz
retains all raw app/shim/work data. otel-native-only-inputs.json pins the launch.
The process exit0 is distinct from actual application error. Guest disk/tar are
confirmed absent after this closed run; raw archives and logs are retained.

```
make -C kprog/libnativeloader trusted-service-check
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/native-only-otel APPS=otelcol-ebpf-profiler/profiling
```


### Tail-map repair confirmed; native unwinder reaches compiler OOM

Actual same-image155931_215569 now fresh-binds read_task_struct AND
perf_unwind_stop. Its real link plan carries kprobe_progs/perf_progs tail-map
aliases, so the preceding transport failure is closed by live evidence.
The third request, perf_unwind_native, generates911398bytes of C but Clang is
killed before producing its BPF object. FULL guest dmesg explicitly reports
clang invoked oom-killer/global_oom and Killed process1848(clang), with
5999204KiB anonymous RSS. This failure is confirmed guest memory exhaustion,
not a verifier rejection. Three generated/two compiled/two accepted-bound;
remaining application loads are not reached and still require completion.
No native workload measurement completes from this failed startup.

otel-tail-map-rerun.json records cause counts, full OOM lines and exact aliases;
its service archive contains ALL requests/kernel.log/meminfo, and the full raw
corpus tree, driver log and launch inputs are retained alongside. Both guest
disk and image tar are absent after closure. VM_MEM now forwards the existing
runtime memory knob (default8G, unchanged for BCC timing). Next diagnostic uses
12G, within lane C's12GiB cap, retaining the same image/kernel/workload/native
code/generator/Clang flags. No compiler-optimization or verifier workaround was
introduced. Reproduce with the preceding OTel command plus VM_MEM=12G.


### Guest CPU count for verified-arm timing

VM_CPUS defaults to4 and controls vng --cpus; CPUS independently selects
host CPU affinity. The guest boots the existing incremental kernel at
kprog/tv/build-kernel-x86/arch/x86/boot/bzImage and uses the cached image
bpf-benchmark/kprog-native-only:x86-current (image ID
a20b2981171de35a85d1827760701e157efa17347c8705374f146a5d7dbe1a90).
The corpus target reuses these artifacts without rebuilding them. R's BCC
verified/JIT pair uses the following, repeated with stats0:

```
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus CPUS=0-7 VM_CPUS=8 VM_MEM=64G SAMPLES=3 WORKLOAD_DURATION=180 BPFREJIT_CORPUS_BPF_STATS=1
```

This is a timing command for R; no timing run was launched by this change.


###12GiB unwinder compile completes; exact self-XOR rejection retained

Actual160919_656980 generated and compiled3 programs, accepted/bound2, then
rejected perf_unwind_native at stub34918/proof33648: R3 pointer ^= pointer
prohibited. No compiler OOM occurred in this12GiB guest. It did not complete
application startup or native workload. Complete corpus/kernel/service/request
logs, exact inputs and the failed third proof are preserved in
otel-native-12g.json and its raw archives. The separate header-repair result
records the exact native xor edx,edx source of this rejection, CPU validation
and successful private compilation after repair; a new actual guest acceptance
remains required. Disk and exported image tar were removed on closure.


### Open-file cleanup invocation repair

The Workspace fuser implementation rejects `fuser -s -- /absolute/path`,
returning1 with usage text even for an open file. Both C corpus cleanup
recipes now use `fuser -s /absolute/path`. Testing the actual Make-expanded
cleanup functions with two genuinely open files retains both; after closing
the handles the same functions delete both. This fixes occupancy detection;
it does not change application, guest or proof behavior. Historical diagnostic
duplicate removal had already checked closed job state and byte-identical
published archives, but its fuser command was invalid and is not open-file
evidence. The correction and raw control results are in cleanup-checks.json.


### Published self-XOR repair reaches verifier complexity limit

Actual174434_111632 on published d30 header generates and compiles3 programs,
accepts/binds2, then rejects perf_unwind_native at1000001 processed verifier
instructions (limit1000000). max_states_per_insn31, total_states66201 and
peak_states2666 are retained. No compiler OOM occurs; the prior pointer ^=
pointer error is absent from this load log. The existing two accepted entries
remain read_task_struct/perf_unwind_stop. This does not establish whole-app
acceptance: startup fails before the other application loads and no native
workload completes. No program is excluded or declared unsupported.

otel-header-repair.json, input pins, driver log, complete result tree and
service archive preserve all3 requests, exact generated C/ELFs, full kernel
log and the946004-byte verifier log. The same12GiB/kernel/module/native
input/Clang flags were used; no verifier limit, fuel, branch assertion or
application code was changed. Both guest disk and exported image tar are
absent after closure. Continue from this exact complexity rejection after
the higher-priority micro shared-ELF repair.


### Module dependency indexes and matching split BTF

The 19:31–19:40 application batch records Cilium route protocol availability,
Katran tunnel4 lookup, and Tetragon/Tracee scsi_common split-BTF relocation
errors during baseline startup. Their full runtime observations are published
in the adjacent native-width application directories. OTel reaches native
loading and retains its separately measured verifier exploration limit.

The common image now generates module dependency indexes inside /artifacts,
the root used by the existing corpus module loader. The recorded host lookup
control keeps the same tunnel4 module bytes: modprobe lookup exits1 before
index generation and exits0 with the exact tunnel4 path after depmod.
module-package-index.json holds both raw command outcomes.

The modules target first advances the existing kernel module build against its
current vmlinux BTF, then installs the current module set and the matching
native modules. Packaging refreshes its owned staging copy and records every
kernel module SHA plus the vmlinux SHA. Existing kernel objects and build
caches support the incremental build. Application code and the workload
protocol retain their existing sources.

The incremental module refresh and image build completed on20–23. R's current
timing guest retains its captured image on its separate Docker disk. The host
image now carries842 kernel modules, fresh dependency indexes and the current
descriptor-stable feature-probe shim. The module-package-refresh result records
all input identities and successful image-index/module observations. The
four-application startup replay uses eight guest vCPUs for the existing Katran
NAPI CPU layout,12GiB, one sample and a two-second workload. Each application
batch records its actual refreshed image identity and startup outcome.


### Coherent boot image and split BTF

Live insertion in the a5b0/2f12 epoch identified the boot/module BTF difference.
The modules recipe now requests bzImage and modules together. The resulting
boot image df7a92936b41 and image1ead525666cc use the same5,670,459-byte kernel
BTF stream as the module build base, SHA75fe34c0e2e. kernel-image-btf preserves
the extracted stream, complete manifest and incremental build logs. The earlier
Katran/Tetragon attempts retain their original startup errors and identities;
subsequent application batches record the coherent image/kernel tuple.
