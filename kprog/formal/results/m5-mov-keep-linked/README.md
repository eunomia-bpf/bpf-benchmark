# MOVK in the actual linked world

`Arm64MovKeep.Linked.branch_returns` executes the actual read/merge/write branch in `Arm64ProgramEntryLinked.ge`: 175 internal transitions from the reached branch to the end statement in its live generic frame. Reader 66 and writer 107 resolve to the original exported C definitions. Their actual layout facts are kernel-checked; unrelated composites and symbols may differ.

`branch_corresponds` relates that same execution and memory to the fetched LNSym MOVK step, including width clearing, PC+4, empty new events and no fault. It retains the original reader frontier and full register relation. Scalar word/tag reads, producer write rights, temporary values, native representation, legal width/column, decode, fetch and prior error state remain explicit premises. The existing Result supplies memory effects; a separate run proves execution in the actual linked world.

The shared reader, merge, call edges and writer-return proofs now accept a world with the specific layouts and bindings they use. Prior Numeric-world APIs remain instances. No C body or ISA implementation is copied or synthesized.

Focused 194 jobs and 17 public type/axiom queries pass at original proof caps on CPU17, one worker, 32 GiB address space. Imported execution semantics retain CC.externalFunctionsSem and CC.inlineAssemblySem; exact reported dependencies are in validation.json. Whole proof-library confirmation is pending there. Existing tool binaries are used; toolchain builds remain disabled.

Next: lift the opcode-5 dispatch and actual generic allocation/release, obtaining the complete 203-step call and its native/all-outcome composition in this world. Then join the actual fixture MOV_IMM/MOVK callsites. M5/M6 and the final default Lake/make check remain open; completed ISA-family count is 0.
