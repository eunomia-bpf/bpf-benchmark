# Recover narrow scalar spill shapes

Actual OTel MIR has eight-byte spill declarations accessed by STW32/LDW32.
The existing all-pairs packer selects four-byte declarations, so it misses
these slots and the liveness diagnostic conservatively keeps unread upper
bytes live.

The normal MIR route now reduces an eight-byte/aligned-eight spill declaration
to four bytes only when every operand use is a direct32-bit load/store at
offset zero. Full-width operations, other offsets and address-taking retain
the original object. The existing whole-word packer then handles the exposed
scalar shapes; flags, source I/P and helper behaviour remain unchanged.

Compilation regression covers eight widened scalar descriptors plus a genuine
64-bit slot, packed result frame48 bytes, and negative64-bit-store/offset/address
uses. Existing sparse-ID/544-to512/dead-reload/scratch-pressure cases pass.
Actual kernel execution and OTel frame observations follow; production base
and image stay unchanged during this compiler change.

Twelve kernel cases complete, including the expected544-byte rejection and
11660 passing executions. The widened-descriptor case executes1060 times at
frame48 bytes. Actual OTel main narrows zero slots: every8-byte slot also has
full-width uses. Therefore code295336/frame784 is unchanged. Early32-bit store
examples were insufficient evidence of a narrow-only slot. The general storage
normalization passes its kernel regression; it solves no main-frame issue here.
