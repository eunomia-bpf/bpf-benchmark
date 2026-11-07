# Independent review of the canonical original-input pure micro route

F independently checked the published raw archives of C's standard
x86_kvm_micro_20261107_175810_925495 run (5004364f). All29 native ELF
payloads are byte-identical to the original pre-fix R inputs, the kernel
copies and the service-generation inputs. They remain ET_DYN; no native
program recompilation or catalog alternative is used in this result.

All29 JIT samples and26 bound-native samples return the exact configured
64-bit result and program-specific return value. The29 native requests
include26 successful bound loads,1 compiler SIGKILL and2 loader refusals.
Every original input remains represented, including the three failures.
verification.json retains each result, native/request/source identity,
actual compiler return code and full source archive hashes.

| Remaining program | Actual stage |
| --- | --- |
| trace_event_type_switch_dispatch | Loader/verifier complexity refusal after successful compile |
| siphash_rotate64_mixer | clang signal9; cause is not inferred as OOM |
| cilium_socket_lb_service_select | Loader/verifier scalar-access refusal after successful compile |

This analysis reads the raw result JSON and every nested service request.
It does not rely on C's runtime.json aggregate. All three owner raw archive
blobs match commit5004364f exactly. The runtime binary SHA and the single
request-source identity set are recorded; they are not replaced by newer
source or image tags.

The former29 EINVAL failures were Python specialization-format validation
before generation, as the original error tracebacks show. Client strerror
alone does not locate that failure in the kernel/module. a974c406f adds
existing ET_DYN support with executable-section-relative entry bounds.
The application/proof split remains enforced; no worker-field exemption
is needed. The earlier13-case stage2 run and F's withdrawn4GiB relocatable
diagnostic are separate evidence and are not merged into this denominator.

This is functional evidence on C20-23,4vCPUs/8GiB,1sample1repeat through
the standard Make target. It is not all29 acceptance, a performance result
or a whole-ISA/ABI safety theorem. C owns the remaining failure fixes.
The exact executed command, runtime binary, original inputs and request
archives remain in the
[owner evidence](../../../../../corpus/results/kprog_app_coverage_20261107/micro-shared-elf/README.md).

The standard functional request after refreshing the native-only runtime
artifacts is:

~~~sh
taskset -c 16-23 make micro PLATFORM=kvm ARCH=x86 SUITE=micro/config/micro_pure_jit.yaml RUNTIMES="kernel native_proof" SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
~~~

The immutable archived command additionally records the cached TV kernel,
matching modules and private image used in this specific run. A later
simulator revision needs its own actual runtime result.
