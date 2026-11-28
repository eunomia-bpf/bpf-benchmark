# Actual whole entry through helper context initialization

The entry theorem composes the accepted actual function entry with the original helper_ctx cast/store once, on the same heap, trace and temporary environment. The actual context-preservation theorem derives the original function argument from the reached temporary environment. No new context oracle is supplied.

Default7 is the actual helper_ctx local. Its old null readback is replaced by the genuine original-context pointer readback, using actual environment bindings to prove the same block. Default6 retains is_xdp=1 and the other seven old defaults remain intact. Actual block frames also retain the SP/XDP scalar reads, eight zero stack tags, 64 vector lanes, LR zero, 31 GPRs, four flags, 62 table slots, two ABI pointers and five CB zero words.

Both genuine table initializer resources keep their original before/initialized/temporary/continuation/run/store fields; only current memory frames extend. Caller memory, permissions and allocation frontier remain related. Control reaches source9287, before helper ABI-base, R0/tag and entry-field assignments.

Five root queries check observer separation, default7 identity, physical/logical frames and the full entry theorem. The exact accepted direct source bytes are promoted unchanged. Original limits and standard Lean plus existing CompCert external semantics remain in force. First LINK/native/global/universal refinement and M6 remain open.
