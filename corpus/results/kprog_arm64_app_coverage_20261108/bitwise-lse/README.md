AArch64 LSE bitwise atomic operation coverage

Canonical ARM C dispatch and native mnemonic lowering now implement LDSET/STSET and LDCLR/STCLR beside LDADD/STADD. The shared RMW body captures source/address before destination writeback, applies width-specific fetch-add/or/and, selects acquire/release ordering, returns the old value and transfers private-memory tags. The approved SP-alignment predicate remains in that shared body. The generated literal dispatch consumes the canonical bodies.

Actual host C-model observations: 11,520 scenes agree on old return value, complete16-byte memory image and destination tag, across three families, four widths, four ordering selectors, destination/source/base overlap, zero-register destinations and private-stack/map-pointer addresses. UBSan exits0. Existing micro29+negative1 compile and existing service9 tests pass. These observations supply per-operation component evidence; V owns the universal reference/token theorem lifecycle.

Clang18 BPF compile rows retain all12 attempts: six32/64-bit rows succeed; six8/16-bit rows record the compiler subword atomic diagnostic. The narrow C-model and compiler results have separate scopes. The next lowering work covers those exact subword operations. The captured complete Tetragon QEMU run uses its published source epoch and supplies application verifier/work receipts separately.

summary.json records commands, source hashes and actual outcomes. component.log.gz and inputs.tar.gz retain exact inputs, native C observations and BPF compiler diagnostics. Production/runtime admission additions:0.

An actual AArch64 assembler/objdump epoch covers72 LSE forms: three families, four widths, acquire/release variants and store aliases. Each decoded token matches its family, access width and ordering selector. forms.tar.gz retains the assembly, ELF, disassembly and token observations at source a8d17004c.
