# Single approved bound at the x86 native chunk copy

Coordinator direct decision2026-11-09 06:55UTC: the native extent consumed by x86 do_jit is below1GiB. The x86 TRUSTED_CHUNK path assigns the wire native_size to blob.len, returns E2BIG for blob.len>=1U<<30, and uses its existing fail label to release the allocated blob and capsule reference. This is the single approved bound, located in the existing copy/allocation error path before native-byte copying.

The shared SUBMIT/SUBMIT_RESOURCES ELF-copy path keeps its ordinary allocation and source-lookup behavior. This forward change narrows the earlier c3d/15f implementations to the actual x86 JIT input extent. The original wire layouts, source metadata, service and same-copy JIT emission retain their definitions. Historical candidate patches and build receipts retain their source epochs. S12 owns the successful whole-image arithmetic derivation.

A private incremental successor module build uses the existing configured kernel and copied warm module cache. The next existing2GiB serial safety guest observes the actual active-capsule CHUNK boundary plus ordinary SUBMIT source-lookup controls, then runs original38 with its captured canonical module. Existing application guest/model/native snapshots retain their bytes.
