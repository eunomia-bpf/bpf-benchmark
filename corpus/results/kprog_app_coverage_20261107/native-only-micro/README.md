# Standard micro runtime through the trusted native-only service

Actual x86_kvm_micro_20261107_173730_247516 completes all13 stage2 cases.
All39 measured samples (kernel, native_kernel, native_proof) return the exact
expected64-bit result and retval2. The26 native samples produce26 successful
fresh service requests, each with a new bound native program ID, a generated
simulator object and compiler commands. Each entry has exactly two requests.
The application submits only native ELF/entry/typed metadata; it never receives
the service capability or supplies its proof. No micro_exec exemption exists.

| Scope | Programs/cases | Fresh proofs | Accepted/bound | Failed | Correct result |
| --- | ---: | ---: | ---: | ---: | ---: |
| native_kernel |13|13|13|0|13|
| native_proof |13|13|13|0|13|
| kernel JIT |13|n/a|n/a|0|13|

native_proof now executes P via run-native-kernel, rather than test-running a
prebuilt B. Historical simulator-only timings/compile metadata are not merged
into the new samples. Both native labels currently use the SAME verified
mechanism; neither is an unbound baseline. The26 service records establish
source/native/bound IDs, source hashes and generated artifacts. No numerical
generation ID is claimed where the existing service receipt does not expose it.
The kernel/service route enforces binding before execution.

The actual guest uses the standard __runtime-vm-micro target and unchanged
stage2 workload on C20-23/4vCPUs/8GiB, one sample and one repeat, with cached
TV kernel and matching15-module bundle. The private image is one small layer
over cacheda20, containing updated micro_exec/driver/suite. Root/framework
image tags and kernel/module sources were unchanged. Exact image inputs,
runner binary, launch command, full micro result and source snapshots are in
raw.tar.gz. service-requests.tar.gz contains ALL26 requests and logs. The
initial failed Docker FROM-image-ID spelling is retained as setup failure,
before application launch. Exported image tar and guest disk were removed.

11 service metadata/lifecycle checks pass; failed registration never launches
the application, and application failure status/archive survive teardown.
The final supervisor additionally closes stdout after joining its reader; all
11 checks pass with ResourceWarning treated as error. The exact supervisor
source used in the successful guest is retained separately. Make expansion
and shell syntax checks pass for native selection and kernel-only selection.

Reproduce through make micro PLATFORM=kvm ARCH=x86 with refreshed incremental
runner/image artifacts and RUNTIMES="kernel native_proof". The exact existing
TV-kernel/private-image functional command is driver/run.sh in raw.tar.gz.
R may repeat the listed simple15sample/stage2 timing requests on0-7 after
refreshing its runner/image from the published commits. This functional sample
is not a performance result; ARM standalone bootstrap remains a separate task.

The captured runtime runner binary differs from T's later current build,
which removes obsolete proof phase fields. The exact earlier binary is in
the archive; checks.json records BOTH hashes. final-source/ is the later
publication snapshot, not an assertion of byte-identical runtime build.
Worker compilation/binding and all26 requests were actual; old zero-valued
phase/code-size fields are not measurements of worker costs or native sizes.
