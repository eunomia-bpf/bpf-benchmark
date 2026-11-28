# Actual caller GPR pointer-table reader

The same allocation lookup identifies the real header source/table blocks. Actual initializer/GPR source identifiers and Cells.binding transport CurrentGPR.localRead to the same current word/tag cells. The existing allocation-independent gpr_readback follows actual header roots0/8,31 word/tag pointer pairs and the pointed union/byte cell loads.

The result keeps ContextEntry.wordValue/tagValue, including pointer-valued R0 with tag1 and R30tag10. It does not substitute all-numeric words or all-zero tags, borrow the old producer allocator, or equate the independent cells with a dense array. Native physical word encoding, SP and the complete native state remain separate obligations.

Three public queries check table_blocks, cell_readbacks and gpr_readbacks. Direct/focused/full-library/public logs are retained. CPU17/one worker/nice0/32GiB and Lean caps remain fixed, outside timingSH per coordinator2026-11-28T05:43Z during the existing x86 rotate; formal-full-check exclusion remains.
