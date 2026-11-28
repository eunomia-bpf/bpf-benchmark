# Original caller vector pointer NULL source and layout

The exact next sixty-four original assignments initialize vector_lo[0..31] and vector_hi[0..31] with the original integer-zero-to-void-pointer cast. Reconstructed assignments, original source shapes, all sixty-three successor equalities and the exact retained continuation are kernel checked.

The actual header composite places the two thirty-two-pointer arrays at offsets 96 and 352. The same Header witness and its original allocation derive writable bytes 96 through 607. Original array fields decay to actual header addresses without memory loads; actual CompCert pointer addition derives each lvalue and its unsigned offset 96+8*i. Original RHS and assignment casts produce Vlong zero in the actual 64-bit pointer model.

Eleven root queries check source, shape, chain, layout, offsets, storage, first_source, array_values, target_locations, rhs_value and assignment. The failed direct diagnostic, successful direct, focused, full-root and public logs are retained. Expanding the array constructor and proving address addition with a generic environment avoid unfolding the entire allocation; no recursion, heartbeat or resource limit changed.

This module proves source/resource/expression preparation only. Actual stores, all sixty-four sequential visits and preservation of the earlier twelve fields in the same header block follow separately. Sixteen further fields precede the original vector-pointer loop. First LINK, native/global/universal refinement and M6 remain open.
