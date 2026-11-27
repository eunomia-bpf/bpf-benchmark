# Eight residual scalar loads

All8 use ENTRY_RAW; a64 RAW ABI 64-bit loads recursively retain TAG_ABI. Current kernel-memory predicate excludes that tag, and64-bit ABI_PTR_LOAD also bypasses the NORMAL_LOAD-only probe condition. Four32-bit andfour64-bit nested raw-context/pointee loads therefore remain direct while the verifier sees scalar addresses.

The exact archived C/B/log bytes were checked against the committed archive receipt and B compiler hashes. Source-annotated disassembly locates each failed B instruction at a native LDR comment; this is debug-location evidence, not a native execution trace. All8 use RAW entry.

The accompanying common BPF-only probe candidate keeps the current context access first and broadens the existing probe predicate to nested RAW ABI pointers. It is not applied or compiled. Active Tetragon headers are unchanged; host/Clight source, flags, tags, kernel, framework and full timing stay unchanged. A paired sweep and native stage2 would still be needed before claiming repair. See sites.json for all8 exact source/assembly/log windows and candidate status.
