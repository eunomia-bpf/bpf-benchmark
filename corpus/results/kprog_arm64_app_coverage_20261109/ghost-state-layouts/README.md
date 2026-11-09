ARM generic ghost-state layout compilation trials

Every cohort uses the exact same four original BCC native P/metadata inputs. The first candidate makes packed scalar provenance-tag accesses ordinary local accesses; native stack bytes keep their volatile operations. The compact candidate forwards only whole-word scalar reads that the existing definedness analysis marks as potentially unspecified, with raw reads for every other access. The scalar-cell candidate names each cached value as a local C scalar and selects existing live cells by their physical word; default cases use the original raw-memory path. The final candidate also makes the relative stack/return payload ordinary ghost storage. All existing native accesses, SP/lifetime/helper/clobber/return/fault rules keep their operation bodies. Runtime admission additions:0.

| Cohort | tcplife B frame | opensnoop B frame | biosnoop B frame | capable B frame |
| --- | ---: | ---: | ---: | ---: |
| Published555 parent | 704 | 648 | 120 | 184 |
| ghost-tag-layout | 696 | 632 | 128 | 120 |
| compact-opaque-cache | 488 | 576 | 72 | 136 |
| scalar-cell-layout | 432 | 576 | 72 | 120 |
| ghost-payload-layout | 432 | 576 | 64 | 112 |

All20actual P/B generation/compile observations succeed. The scalar-cell representation brings tcplife from704to432bytes; opensnoop retains576bytes and its stock512frame frontier. The complete original13ARM host groups are run with GCC and clang18 on the final private candidate: 23/26pass; exact exits:{"0": 23, "2": 3}. Original source cases/assertions remain in host-source, with commands/binaries/diagnostics in the archive. These are compilation/layout and finite host observations. Actual verifier/application and original48safety replay remain separate receipts. The canonical555 model and active uniform-catalog/fullBCC snapshots retain their published source.

The archive holds one complete555dependency source tree, each candidate three-file override/diff, original native inputs, generated B, exact compiler commands, all host source/binaries/logs and receipts. Completed private source/generated/host binary trees retire after publication.
