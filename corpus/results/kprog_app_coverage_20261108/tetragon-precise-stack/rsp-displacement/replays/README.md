# Existing native safety and micro compiler replay with private RSP displacement representation

private RSP displacement existing native cases38, stages{"accepted_finding": 6, "specialization_rejected": 2, "valid_executed": 9, "verifier_rejected": 21}, compiler rows30, exits{"micro": 0, "safety": 0}.

The exact saved private C header is selected by both absolute and relative simulator includes; every derivative source stays under lane C. Existing38native safety inputs and29+1micro compiler cases retain their original populations. Negative native controls use load-only submission. Actual verifier errors, native objects, generated BPF and commands remain in the archive. This is private model evidence; whole-application completion and universal compiler/erasure correspondence retain their own stages. Source adoption0 and runtime admission additions0.

The coordinator's RSP-displacement item is resolved by a static compiler trace of the six installed findings. `compiler-mechanism.tar.gz` contains the exact saved BPF disassembly, frontend and optimized LLVM IR, compiler identity and Make command. Existing archived P/C/B inputs supply the original source population; the replay submitted each negative control for loading only, with native execution count 0.

| Existing case | Request | Saved BPF instructions | Saved BPF memory loads | Saved BPF memory stores | Fresh optimized LLVM return |
| --- | ---: | ---: | ---: | ---: | --- |
| stack_oob | 16 | 25 | 0 | 0 | `ret i32 poison` |
| entry_return_slot_overwrite | 22 | 33 | 0 | 7 | `ret i32 2` |
| high32_positive_byte | 35 | 27 | 0 | 1 | `ret i32 poison` |
| high32_positive_qword | 36 | 27 | 0 | 1 | `ret i32 poison` |
| high32_negative_byte | 37 | 27 | 0 | 1 | `ret i32 poison` |
| high32_negative_qword | 38 | 27 | 0 | 1 | `ret i32 poison` |

The candidate exposes constant MOV-load/store displacement to clang whenever the decoded base register is RSP. The canonical representation keeps its existing displacement compiler barrier for that base. RSP remains a full 64-bit relative word; stack addressing adds the specialized arena capacity. The candidate keeps the ISA expression and exposes its complete value to ordinary C array analysis.

For `stack_oob`, capacity 1 plus the native negative displacement yields an address outside the private union. For the four high32 cases, capacity 16 cancels the initial allocation, leaving the complete positive or negative high32 displacement as the array index. The frontend expresses these accesses with `getelementptr inbounds`. C object-boundary semantics give clang an undefined execution at these indices, and the optimized result is `ret i32 poison`. All five saved BPF sections have memory-load count 0. The high32 BPF retains the earlier ordinary private initialization store; its later native read has disappeared. These observations identify access erasure, distinct from an integer truncation or a stock-verifier classification error.

For `entry_return_slot_overwrite`, capacity 1 maps entry RSP to index 1. The rounded union occupies 8 bytes. Its eight-byte store covers indices 1 through 8. Clang keeps seven volatile private byte stores, erases the write past the allocated union, and returns constant 2. Native-link has already translated the entry RET to the generated exit, whose C body returns RAX. The native saved-return-slot/control effect therefore also needs preservation through the entry-return transformation. Seven surviving private stores provide the precise observed distinction from complete store erasure.

`volatile` preserves accesses within defined C executions; C object-boundary undefined behavior remains available to the optimizer. The two-barrier candidate is one concrete instance of the general compiled-B obligation. Every later stack/register/memory representation, tag fast path, private-spill erasure and entry-return/link transformation carries the same obligation: native memory effects and architectural fault/control behavior remain visible after optimization, including values outside the represented arena. Host equality on valid addresses and smaller generated B establish their measured domains. Universal O2/O4 and compiled-B preservation supply the safety correspondence for all programs. V owns that shared theorem interface; C owns the concrete representation and lowering. Runtime predicate/gate/limit additions: 0.

Static investigation command: `make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tetragon-precise-stack/rsp-displacement/mechanism-ir.mk ir`. The command emits frontend IR with `-O0 -Xclang -disable-O0-optnone` and optimized IR with the original `-O3 -mcpu=v4 -target bpf` flags, using the captured header. The existing compiled object remains the evidence for the originally installed B. Each IR source changes its simulator include to that byte-identical captured header. Exact compiler/source/object/IR hashes accompany the trace.
