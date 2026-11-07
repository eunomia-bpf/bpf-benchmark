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
