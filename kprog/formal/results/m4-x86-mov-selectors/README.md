# MOV-load selector C-subset checks

Three roots export the actual write-width, memory-width and arm selector bodies.
Shared declaration kernels preserve the native expression and const initializer
forms; the CompCert declaration adapter uses standard statement outputs. The
physical load, value transformation and ABI tag handling remain in the single
MOV-load body.

The write selector tests the raw operand before byte capture: flags256 produce0,
not8. Nonzero flag expressions are evaluated again for the captured value. The
memory selector reads AUX first, and reads flags only on a zero memory-width
field. The arm selector delays its tag observation until the stack, opcode and
both width checks permit it. NULL state pointers test the unused tag paths.

Run `make clight` and `lake build KProgFormal.Clight.X86Pointer` in
`kprog/formal`. The oracle runs native and CompCert host forms; historical
selector bodies and their actual declaration prefix are replayed from50d949d1b
in RAM. Exact replay, mutation recipes, input patch and logs stay in the raw
directory recorded in metadata.json. No second source tree or build is needed.
The same allocated fixture code/data and relocations are compared with the
historical inline/local/selector headers and an ordinary current compilation.
Debug metadata and complete-application byte identity are not claimed.

Twenty-two exported functions are not migrated instruction proofs. Full inline
export still fails at the SKB context-read expression. Clight/native memory,
input/fault and source-binding proofs remain M5 work; M4, all2,065 migrations,
recounts, archival and whole-library acceptance remain open.
