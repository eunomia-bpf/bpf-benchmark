ARM helper argument restoration

The coordinator decision of 2026-11-09 21:50 restores the existing helper argument projection for all 31 output-wrapper uses. The separate below-SP output wrapper and its libc prefetch expressions are removed, together with the memcpy scalar-source fault arm. Helper result/clobber operations, memory tag transfer, SP release, architectural predicates and read-fault recovery retain their existing bodies.

The original invocation-stack host runs successfully with GCC and Clang18 under UBSan, covering allocated, released, below-SP, boundary and provenance cases. Source, commands, compiler output and raw outcomes accompany the receipt. Native executions: 0. The unified-kernel guest replay follows the coordinated shared reverts.
