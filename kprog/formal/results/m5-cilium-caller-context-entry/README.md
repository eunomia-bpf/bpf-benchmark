# Whole caller entry through context pointer and GPR tag updates

This theorem composes the actual whole entry through ABI-base initialization with the original nine-step R0 pointer/R30 tag/R0 tag sequence once on the same heap, trace and temporary environment. The original _ctx pointer is derived from the actual reached temporary environment, without a replacement oracle.

The new CurrentGPR postcondition states R0's word is the original context pointer, R0's tag is1 and R30's tag is10. Other GPR words retain their original values and other tags retain zero. Actual source target identities and allocation bindings derive the changed reads; only unchanged word/tag names use non-target frames. The old all-integer/all-tag-zero specification is not asserted after intentional writes.

Both helper pointers, SP/XDP reads, eight zero stack tags, 64 vector lanes, LR zero, four flags, 62 table slots, two ABI fields, five CB words and all current default values remain available. Both genuine table initializer resources keep their original execution/store fields while only current memory frames extend. Caller memory, permissions and allocation frontier remain related.

Five root queries check actual targets, selective observer separation, physical/logical frames and full entry composition. The accepted direct bytes are promoted unchanged. Original limits and standard Lean plus existing CompCert external semantics remain in force. Control reaches the original entry.cells assignment; entry fields/vector loops/first LINK/native/global/universal refinement and M6 remain open.
