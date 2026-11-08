# ARM direct native context

The shared dd144b1537 implementation accepts native P with its program load context and resource map FDs. source_prog_id0 selects the context in the kernel-owned P metadata. The ARM module uses that shared implementation directly.

Incremental ARM module, static/shared loader, trusted worker, service client and native producer builds exit0. The paired e2d3Image stays current. Runtime artifacts and exact source/build commands accompany build-inputs.tar.gz; build.json records every binary hash. Existing captured application guests retain their runtime copies.

The next full-system QEMU replay submits the same34 native ISA inputs through this direct context. Resource-only objects create their maps with every original program autoload=false. Four positive cases execute and compare results;30 risk cases use load-only submission. Generated B still reaches the stock verifier. The raw producer records source_prog_id0 for every accepted result.

## Complete34-case result

The paired-cache rebuildfb9a581c6 and full-system QEMU cohort80ae3beda finish with Make/host/guest/QEMU/compiler exits0. All34 requests carry source_prog_id0. Four named valid native programs execute with matching results;28 unsafe programs reach stock-verifier rejection;2 deliberate generation cases retain their unbounded-target/unsupported-instruction classification. The8 previously observed architectural findings all reach stock-verifier rejection. Risk-case native executions0.

The producer opens resource objects with every original program autoload=false, creates and pins their maps, and submits native P with its program context. This supplies the ARM direct-native route for upstream annotated C selftests, whose original __failure companions have their own verifier verdict. direct-context-summary.json joins these counts to every raw request in retry/safety-complete.json and its guest archive.

The initial module trial2bab28f0b stopped at module loading before native submission. The kernel log in module-diagnostic/ identifies symbol-version mismatches. Its generated cache Makefile exports vendor/build/arm64/linux as KBUILD_OUTPUT; the corrected incremental build binds the paired warm cache there. rebuild/ retains exact commands, matching symbol CRCs, source/binaries and the original diagnostic module. The published e2d3Image and existing application runtime copies retain their original bytes.
