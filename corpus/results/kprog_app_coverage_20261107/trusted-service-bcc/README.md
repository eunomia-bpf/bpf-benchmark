# Actual upstream BCC startup through the trusted service

`make -C kprog/libnativeloader trusted-bcc-kvm` runs the unchanged upstream vfsstat binary with the current shim/library, REQUIRE_BOUND_PROOF=1 and REQUIRE_PREBUILT_PROOF=1. It uses the canonical shared native stage manifest and a registered COMMON service, CPU16-19/2GiB, existing matched kernel/module, with no image rebuild or workload change.

The first real application load reaches the kernel and service. App exit97 propagates service-EINVAL before proof generation. Observed submissions1, generated0, compiled0, verifier accepted0/rejected0; one specialization preparation failure. Subsequent intended auto-load entries are not reached after this failure. This is not full BCC coverage or an unsupported-program exclusion.

The kernel-copied envelope names only data map vfsstat_.bss(map3,40-byte value) as a map handle. Native code relocates stats, a40-byte global object, which requires the same map's direct value at offset0. The app frontend has not exported that native-symbol alias. Allowing a dot in a C identifier would leave the identity defect unresolved. T owns the native-loader envelope/extern relocation fix; C keeps kernel map membership/shape checks and records the exact failure instead of guessing a map.

summary.json retains counters/cause and exact typed metadata. requests/1.failure.tar.gz retains kernel-owned ELF/entry/metadata; logs.gz retains guest, upstream libbpf and shim output. Rerun this same target after the shared loader fix; all six applications remain required. No timing interpretation is made.
