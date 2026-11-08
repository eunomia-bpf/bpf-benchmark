# Stack pointer representatives stored as arena offsets

The private generic representation stores the full modular byte offset of each STACK-tagged value from the modeled stack arena. Readback reconstructs the identical pointer with existing `KPROG_PTR_ADD64_BITS`. The eight-bit tag retains its representation. MOV and PUSH/POP keep the original numeric bytes, partial-overwrite erasure and helper frame lifetime.

All five CPU regression domains compile and run with ASan/UBSan, exit0:240 PUSH/POP pointer scenes,463 existing handler cases,347152 existing routing cases,52992 MOV pointer-byte cases and552 helper-lifetime cases. These are supporting ISA/representation observations. Universal O2/compiler correspondence and stock-verifier/application outcomes retain their own evidence stages. The full original Tetragon event_execve compiler runs separately on the identical P75318 object.

The layout comparison starts from the earlier PUSH/POP candidate in `../pushpop`; canonical d963788c0 remains the production source. The patch, exact headers/hosts/assembly/commands and diagnostics accompany this result. Runtime admission additions0.
