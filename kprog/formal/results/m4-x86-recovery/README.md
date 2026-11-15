# x86 recovery and effective-address C-subset checks

Five extraction roots share production statement-output kernels. Address and
index reads stay behind their original gates; low addresses skip the input,
only its low bit selects recovery, and an RSP destination faults before a write.
Full operand comparisons, byte index/scale decoding and wrapping offsets remain.
The generic C roots and by-reference inline adapters are compared with native
facades and independently computed outcomes, including complete state frames.

Run `make clight` and `lake build KProgFormal.Clight.X86Pointer` in
`kprog/formal`. The new oracle runs in native and CompCert host-adapter forms.
Its 45,785 inline count records returning calls; trapping calls are also checked
against the expected fault/frame. Historical bodies, mutation recipes, command
logs and full failed diagnostics remain in the raw directory in metadata.json.
The two initial harness compile failures are retained there; both were fixed
before final confirmation. No assertion or input was relaxed.

The allocated-code comparison streams historical inline/local/x86_sim/offset
headers at the fixture's actual include sites, using one replaced build product.
It checks code/data and relocations; it does not claim debug metadata or a whole
application is byte-identical. Preprocessing size describes the explicit-profile
extraction translation unit, not P-SPECIALIZE scale or runtime performance.

Full inline export still fails at the MOV-load width-selector GNU expression.
Nineteen exported functions are not nineteen migrated instruction proofs.
Actual Clight/native memory, input and nonreturning-fault interpretations remain
M5 obligations, with all 2,065 theorem migrations/recounts still outstanding.
M4 remains open; M6 and whole-library acceptance follow later.
