# Original program FD is shared by normal and registered loads

Phase1 prototype binding stays ahead of further helper optimization. The
normal FD entry calls the existing original-program helper query only when
the manifest opt-in is true. Registered source-ID loads reopen a real FD
and use the same common companion-loading function, which also omits it.

The smallest owner-applied change queries in
`load_from_loaded_program_fd` and deletes the obsolete manifest flag,
assignment and guarded call. The existing endpoint returns the kernel's
actual `get_func_proto` result for the original program, including EXT's
destination operations. The draft patch is a review artifact in results;
the frozen core and manifest stay unchanged in this step.

This closes both routes that have a source FD using the existing module
protocol. A context-only registered request is a separate case: it supplies
type/attach metadata and has no original program object. The current query
requires a valid FD. Constructing a type-only fake program would lose aux
metadata, including extension-program destination context. Keep this case
explicit in the owner implementation and native-first coverage.

The current verified module is inspected for its source origin and helper
endpoint. The historical kinsn source and the current stock module have
different endpoint inventories, so use the actual staged module as evidence.
The reader also retains completed rows of the live checked Tracee service
with an explicit partial-run scope. It preserves every raw row and starts
zero guest, build or image. Patch context validation is separate from C++
compilation and kernel execution; the owner applies and tests the change.
