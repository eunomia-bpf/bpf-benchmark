# Single approved x86 native-copy bound: serial guest observations

The private module built from c2b96d6c3 contains exactly one approved1GiB bound, at actual x86 chunk blob.len allocation/copy. Its existing fail path releases the blob and capsule reference. Shared ELF SUBMIT and SUBMIT_RESOURCES retain their ordinary source lookup/allocation behavior. Build 6f8e87e795447a8c779f97b2644a4ac36950430c completed with exit0.

The next existing2GiB safety guest records24 ioctl outcomes. Sixteen SUBMIT controls use an absent source program ID and retain ENOENT across all sizes. Eight CHUNK observations use an actual active kernel-copied one-byte capsule: the same invalid eight-byte load-site span selects existing EFAULT below1GiB, while sizes1GiB and larger select approved E2BIG before that copy. Native allocation at the boundary stays behind the approved branch; smaller controls touch only the eight-byte metadata span. The copied capsule receives execution calls0. Every native_size, expected/observed errno and setup/unload result is recorded.

The guest unloads this private module, then loads the original captured module for its existing original38 replay and complete BCC/Katran cohort. Existing C application guest lifetimes, native fixtures, model/runtime epochs and serial12GiB envelope retain their definitions.
