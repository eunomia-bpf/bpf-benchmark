Tetragon V61 data-event function inlining

Private candidate changes three internal function attributes in process/data_event.h: __do_str, data_event_bytes and data_event_str use FUNC_INLINE. The original O3/Os P retains480-byte maximum native stack; compiled B reaches stack offset-520. The candidate removes nested native call-frame boundaries while retaining the complete function bodies, loop counts, limits, helper arguments, error state and output fields. Every selected C/header source is identical between the native and JIT frontends; compile.json records actual hashes and compiler outcomes. Canonical O3 flags and original V61 definitions are retained.

Source publication and the required source-change row/patch follow successful paired compilation. Current running program captures remain fixed. Runtime admission additions:0.
