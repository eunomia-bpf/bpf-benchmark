# x86 protected-read recovery
S1 integrates the existing protected-read environment pattern into the production x86 header and generator. Read recovery precedes the scalar-address instruction effects, uses the current native-link exception-table destination, and resumes the next simulated instruction. Register destinations clear their full saved GPR; resume-only profiles retain the complete original state. The successful non-REP macro-body tokens reproduce the entry source after the added recovery arms are erased. REP assigns its completed count inside the recovery branch and preserves the original successful pointer advancement.

Production: `0ee16fa8f66cb723f65878ea18a5e8a833e04127`. REP success preservation: `a146b630aeeafb83fef036f6cb605cde3b3a8032`. ANDN host environment alignment: `493df264e461c002ab9aa3986b313c577e6f72e7`.

| Accepted read forms | Stock table destination | Recovery state |
| --- | --- | --- |
| mov/movabs/movzx/movsx/movsxd/movbe including AH/BH/CH/DH | explicit destination GPR | whole GPR zero; flags, memory and other registers preserved |
| add/adc/sub/sbb/and/or/xor/imul register,memory | explicit destination GPR | whole GPR zero; original complete frame retained |
| binary/unary/shift/ROL/ROR memory destinations | resume-only | original full state |
| cmp/test/bt memory forms | resume-only | original full state including flags |
| imul immediate,popcnt,shlx/shrx/sarx,rorx,bzhi,andn | explicit destination GPR | whole GPR zero; original complete frame retained |
| cmovcc memory source for every condition | explicit destination GPR | whole GPR zero for both condition outcomes |
| div memory source8/16/32/64 | implicit RAX | whole RAX zero; RDX/flags/original frame retained |
| push word/qword memory source | resume-only | old RSP and complete original frame |
| pop word/qword GPR and memory destination | explicit destination GPR or resume-only | stack-read fault preserves old RSP except explicit POP RSP clear |
| movups/movaps XMM0 memory source | resume-only | both original XMM lanes and complete frame |
| forward REP MOVS byte/word/dword/qword | implicit RCX | completed iterations retained; RSI/RDI advance by completed bytes; RCX zero |

The MOV high-byte and DIV memory encodings carry reads inside their immediate expression. Their generator recovery arm surrounds expression evaluation. XMM0 preserves both original vector lanes because its table destination is resume-only. Forward REP retains every completed copy and advances RSI/RDI by that prefix; the table clears RCX.

Validation: 135 existing host executables and 136 compile recipes finish with make exit 0 from a private source snapshot. The 244 MOV forms, 520 ALU forms and 621 additional forms exercise the actual encoder-emitted handlers. GCC and Clang each pass 7,430,016 full-state cases, including 549,120 protected-page REP cases over every count 0-64, every completed prefix, all four widths and all 64 incoming flag states. The existing host oracles retain their original input domains. ANDN explicitly supplies the valid read outcome before both original independent PF/AF choices, and checks consumption of all three outcomes.

The 29 positive micro cases and the existing negative compile case all compile from the final production header. The final 2 GiB guest safety cohort completes all 38 original cases: 9 valid executions, 28 verifier rejections and 1 generation frontier (`unbounded_indirect_jump`). Risky native executions: 0. The final guest pins its source, native link, loader library, module and kernel. It runs the original fixture bytes and annotation expectations.

An initial REP oracle exposed a new success-path truncation, corrected by the REP commit above. The initial combined Clang fixture reached its source-location capacity; eight translation units retain all 621 forms and all 2,623,104 cases. Initial compiler diagnostics and oracle observations accompany the terminal results. Component MOV/ALU/additional receipts use the first production epoch; the final REP, host snapshot, 30 compile cases and 38 safety cases use the final header. summary.json records both epochs.

Named completion interfaces:

- **RET entry and subroutine**: Structured return/entry-ABI macros require an explicit physical next-PC fallthrough relation for a recovered return-stack read.
- **CALL_MEMCPY and CALL_MEMCPY_REG**: The external-body abstraction requires actual called instruction bytes, per-PC exception sites and completed-prefix/clobber mapping.
- **PUSH memory later stack write; POP memory destination write; REP destination write**: The source-read recovery component is measured. Later write-side faults require a transactional full-instruction/prefix relation, including saved-SP ordering and completed stores.
- **Typed context/stack/map/packet/immutable reads**: Existing typed routes retain their universal valid-address/lifetime and permission premise. The fresh read-recovery choice is attached to scalar-address routes.
- **Whole compiled-B/native platform relation**: V retains universal O1/O2/O3/compiler, exact decoder-site/frame/handler registration and physical event projection obligations.

These are measured production/model components and explicit universal interfaces. V owns the full formal check and the universal recovery/compiler/platform rows. Runtime admission additions: 0. The frozen workload and paper paths retain their recorded definitions.

raw.tar.gz contains commands, fixture generators, original/derived host inputs, source snapshots and hashes, all terminal logs, the final safety native/B/request records and micro compiler metadata. Build executables, compiler caches and kernel trees remain temporary outputs.
