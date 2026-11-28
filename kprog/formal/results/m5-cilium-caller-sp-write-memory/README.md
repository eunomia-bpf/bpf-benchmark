# Actual caller SP preindex memory operation

The actual HeaderSources field5 and EntryScalars0 refer to the same allocated scalar cell by uniqueness of the same environment lookup. The retained original header pointer at offset40 points to that exact cell; no earlier allocator or dense-array/table bridge is used.

Current allocation access rights construct the Mint64 store of preindex -32. Its successful store is derived, and the same store supplies the new SP readback. Actual header pointers, every other block's loads, the caller frame, access map and frontier are preserved. The existing allocation-independent borrowed reader derives the updated SP value from that same memory operation.

This is a memory witness for later consumption by the real helper execution. It does not execute the helper body or transport an entire entry across global worlds. The old zero-SP post changes explicitly.

Four public queries check sp_cell, header_pointer, write and borrowed_after. CPU17/j1/nice0/32GiB/default caps remain, outside timingSH under coordinator2026-11-28T05:43Z during x86 rotate, with full-check exclusion.
