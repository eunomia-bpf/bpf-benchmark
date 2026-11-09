Forwarding metadata storage: tag and validity state

A single16-bit scalar carries the complete8-bit ghost tag and independent1-bit scalar-forwarding validity. Tag access projects bits0–7; validity projects bit8. Saving a tag preserves validity; saving a scalar preserves the tag; release and overlapping-write invalidation clear both. Scalar payload, pointer payload, raw byte storage, helper wrappers and instruction operations retain their definitions.

GCC and Clang18 each pass the complete512tag/valid combinations with both array and named-cell layouts, together with the existing invocation/stack-lifetime oracle in both layouts:8host build/run outcomes, all exit0. Both compiler outputs link the installed GCC UBSan runtime. The first optional Clang runtime link diagnostic accompanies the raw record.

This receipt closes the metadata representation step. Emitted-B stack offsets and stock-verifier outcomes remain separate follow-up observations. The active grouped census retains model4f5b7ae6d; the sparse-forwarding compiler cohort retains its own frozen inputs. Runtime admission predicates added:0.
