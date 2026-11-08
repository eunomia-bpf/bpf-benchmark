# ARM direct native context

The shared dd144b1537 implementation accepts native P with its program load context and resource map FDs. source_prog_id0 selects the context in the kernel-owned P metadata. The ARM module uses that shared implementation directly.

Incremental ARM module, static/shared loader, trusted worker, service client and native producer builds exit0. The paired e2d3Image stays current. Runtime artifacts and exact source/build commands accompany build-inputs.tar.gz; build.json records every binary hash. Existing captured application guests retain their runtime copies.

The next full-system QEMU replay submits the same34 native ISA inputs through this direct context. Resource-only objects create their maps with every original program autoload=false. Four positive cases execute and compare results;30 risk cases use load-only submission. Generated B still reaches the stock verifier. The raw producer records source_prog_id0 for every accepted result.
