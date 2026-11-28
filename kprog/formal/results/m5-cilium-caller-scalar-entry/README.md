# Actual whole entry through SP and XDP initialization

This entry theorem composes the actual function entry through all vector and stack-tag initializers with the real six-step SP-zero/is_xdp-one sequence. It uses the same heap, trace and temporary environment, and reaches the original helper_ctx assignment sequenced with source9287.

The is_xdp byte was already initialized to zero as default index6. The later original assignment deliberately overwrites it with one. The first draft incorrectly required every default to be separate from both scalar targets; that false finite certificate failed kernel checking. The corrected proof preserves only the other eight default values and uses actual environment bindings to identify default6 with the real is_xdp store block, deriving its new one readback. No false frame or old zero postcondition remains.

Actual block/name frames retain eight zero stack tags, all 64 vector reads, LR zero, 31 GPR values/tags, four flags, 62 table slots, two ABI pointers and five CB zero words. Both genuine table initializer resources keep their original execution/store fields; only their current memory frames extend. The two real scalar reads are retained alongside the updated nine-default readback specification.

Five root queries check observer separation, the replaced default identity, physical/logical frames and the full entry theorem. The failed first log remains recorded. Original build limits and explicit external outcome assumptions remain unchanged. Helper_ctx and subsequent source9287 updates, LINK/native/global/universal refinement and M6 remain open.
