# Actual SP and XDP flag initialization

This module extracts the two original scalar assignments immediately after the actual eight stack-tag stores: signed64 SP receives zero, then the uchar is_xdp flag receives one. Their typed casts, current write permissions and real CompCert stores derive both readbacks. The actual continuation is the original helper_ctx assignment sequenced with source9287.

Both local bindings and storage permissions come from the same 795-local caller allocation. The six genuine internal steps preserve the temporary environment, every other block, caller memory, permissions and allocation frontier. The SP-zero read survives the separate is_xdp store. No successful-reader or preinitialized-SP premise is supplied.

Nine root queries check the actual row and full-prefix sources, successor, declarations and separation, real storage/current rights, individual stores and complete six-step execution. The first direct failure was an incorrectly stated successor certificate: the continuation includes both the helper_ctx assignment and its following source9287. That certificate was corrected; the original statements and execution proof did not change. Failed and successful direct logs remain available.

Whole-entry composition, helper_ctx/ABI-base/entry-structure initialization and the instruction prefix remain next work. Native BL, loaded text, global/universal refinement, whole-P counts and M6 remain open. Runtime, captured frontend and benchmark inputs remain unchanged.
