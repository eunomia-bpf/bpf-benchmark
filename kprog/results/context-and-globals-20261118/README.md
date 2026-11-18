# Context-only prototype lifetime and BCC data-folding coverage

The common-FD query draft in helper-fd-boundary-20261118 covers the normal
and registered source-ID routes. This review follows the remaining
context-only case before choosing another helper optimization.

The successful verification phase creates a real B program FD in
native_loader.cpp:4062–4072. trusted_loader.cpp:73–76 reads its ID, calls
close_loaded_program and then prints JSON. close_loaded_program at
native_loader.cpp:4336–4344 closes the descriptor. The later Python phase
retains checked-simulator-verification.json (trusted_service.py:191),
with an ID and status rather than an owned FD. That ID supplies a diagnostic
identity; its lifetime in a later link step has no ownership guarantee.

The direct-native branch at trusted_service.py:192–199 also executes when
generation or stock verification fails. A future context-only prototype
fix must cover it, preserving the operator's native-first behavior. Making
successful B verification a prototype prerequisite would change that flow.
For source ID zero, kernel_facts uses the captured envelope at lines83–91;
the capsule source is populated only for a positive ID
(native_lab_trusted.h:140–147). Its GET_CONTEXT implementation at355–372
reads the original aux fields when that source exists. A type-only fake
program or a closed B verification ID cannot replace the source contract.
Any ownership/metadata change belongs to the frozen loader/service owner.

The independent performance check inventories actual BCC executable-section
relocations bound in each captured kernel plan. This checks the produced
code, alongside the source's immutable-global folding implementation.
Only code relocations count: debug and BTF references can retain a variable
name after all executable reads disappear. Remaining bindings may be maps
or mutable data, so the reader retains names/types/offsets and avoids
claiming frozen values from a symbol name alone. Source, compiler flags,
canonical tools, guests and the image stay unchanged.
