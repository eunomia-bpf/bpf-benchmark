# Actual upstream BCC startup through the trusted service

`make -C kprog/libnativeloader trusted-bcc-kvm` runs the unchanged upstream vfsstat binary with the current shim/library, REQUIRE_BOUND_PROOF=1 and REQUIRE_PREBUILT_PROOF=1. It uses the canonical shared native stage manifest and a registered COMMON service, CPU16-19/2GiB, existing matched kernel/module, with no image rebuild or workload change.

The first real application load reaches the kernel and service. App exit97 propagates service-EINVAL before proof generation. Observed submissions1, generated0, compiled0, verifier accepted0/rejected0; one specialization preparation failure. Subsequent intended auto-load entries are not reached after this failure. This is not full BCC coverage or an unsupported-program exclusion.

The kernel-copied envelope names only data map vfsstat_.bss(map3,40-byte value) as a map handle. Native code relocates stats, a40-byte global object, which requires the same map's direct value at offset0. The app frontend has not exported that native-symbol alias. Allowing a dot in a C identifier would leave the identity defect unresolved. T owns the native-loader envelope/extern relocation fix; C keeps kernel map membership/shape checks and records the exact failure instead of guessing a map.

summary.json retains counters/cause and exact typed metadata. requests/1.failure.tar.gz retains kernel-owned ELF/entry/metadata; logs.gz retains guest, upstream libbpf and shim output. Rerun this same target after the shared loader fix; all six applications remain required. No timing interpretation is made.

## Successful replay at shared loader 5d545ea7b

The queued replay now exits0. All five actual vfsstat fentry program loads generate and compile fresh proofs, pass the kernel verifier/binding and return native programs6/8/10/12/14. The real application attaches them and prints READ70, WRITE11, OPEN122 for its observed one-second output interval. These are raw functional work observations, not matching-work timing. coverage.csv retains every submitted entry; summary.json and its compressed request_archive retain exact ELF/metadata/proof/native artifacts and tool/kernel/module hashes. Private .live state is removed after archive completion.

The earlier metadata rejection and its compressed counterexample remain above. The whole native ELF hash also changed between those runs; payload-comparison.json records both identities and every defined function's byte hash, so this replay is not presented as a single-variable experiment. Both records remain required provenance. This closes vfsstat startup on the new service, not all eight BCC tools or all six applications. Full BCC is next; no timing request is made before its work evidence is available.
