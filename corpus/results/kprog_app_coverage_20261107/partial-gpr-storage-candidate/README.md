# Private partial-GPR storage candidate

Katran's observed verifier rejection reaches a low-byte update of a helper-returned
map pointer; the compiler lowers the ordinary union update to a pointer mask.
This private generic candidate copies the complete register representation to a
volatile local union, writes the low byte, high byte or low word, then reloads all
64 bits. The remaining upper bits and scalar tag follow the existing x86 register
write contract. The 32/64-bit write bodies retain their original source.

The existing MOV handler host oracle passes100448 cases with UBSan, using this
candidate include ahead of the canonical generated header. The complete command,
prior/candidate headers and raw output are archived. This is finite bit-preservation
evidence for the generic mechanism. Production header and generator retain their
current source. A whole Katran application replay follows the running Tetragon/
Tracee slot-join batch, using the common native-only registered service and this
captured include via its existing CLANG environment interface. Actual verifier
and application outcomes will be recorded with that runtime epoch.
