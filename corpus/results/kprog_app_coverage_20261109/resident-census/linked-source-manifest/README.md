Linked source libraries in generic native manifests

All 549 resident instances now select a unique native entry: BCC 25, Katran 1, Cilium 72, OTel 13, Tracee 151 and Tetragon 287. The initial 275-entry selection class closes through the actual reference-object input, source-family completion, and generic BPF source-library linking.

write_native_manifest.py accepts source-library inputs and delegates their relocations to bpftool gen object. Its existing reachable-function scanner then reads the linked ELF. The Tetragon producer supplies the loader default CEL library: eight return-zero functions, 128 bytes total. The retained resident xlated dumps show these actual default bodies; native cel_expr uses the same return-zero fallback. Each policy with generated CEL code uses its corresponding source library as metadata input.

The existing three manifest tests pass. The full retained cohort selects 549 unique entries, and the credential-commit source compiles incrementally with exit 0. These are source-selection and producer results; the initial stock table retains its measured generation, compilation and verifier counts. Static continuation for the newly selected inputs follows separately. Native execution requests: 0.
