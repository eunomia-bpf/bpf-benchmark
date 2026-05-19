# x86 simulator Direct-Native Safety TODO

This file tracks the work needed to make the C-authored simulator implement
the same architectural behavior as the native x86 artifact.

Hard rule: correctness cannot be supplied by generation-time rejection,
formal preconditions, runtime traps, unsupported paths, fallback returns,
synthetic bounds, verifier-only assertions, or safety guards. The simulator
must execute the same instruction semantics that the hardware would execute.
Verifier failure is acceptable during this experiment; semantic mismatch is
not.

Fault-like cases are not a simulator safety mechanism. Arbitrary address
load/store, stack out-of-range access, divide-by-zero/divide-overflow, and
invalid-address behavior must not be converted into simulator-side checks,
traps, abort returns, or proof-only bounds. The proof program should express the
same native operation; if the eBPF verifier cannot prove it, verifier rejection
is the result.

| Item | Status | Required completion condition |
| --- | --- | --- |
| Branch proof assertions | done | `last_cmp_*`, `cmp_ptr_*`, direct pointer-compare branch lowering, and `x86_sim_assert_*` are removed; branches use only architectural x86 flags. |
| Runtime fallback/trap/unsupported path | done in active code | Active simulator/linker code has no accepted `X86_SIM_UNSUPPORTED`, trap, fallback return, or fail-closed safety path. |
| Runtime packet/output bounds checks | done in active packet helpers | Packet/output helpers do not add `data_end` guards that native x86 would not execute; the old hardcoded output-write smoke macro was removed from active headers. |
| Control-flow step dispatch | done | `X86_SIM_RUN_OP()` rejects `JCC/JMP/CALL/RET`; generated control flow must use the C-authored x86 branch/call/return macros instead of a no-op/unreachable helper. |
| Exact scalar pointer values | in progress | `ctx`, packet, packet-end, `lea`, and pointer `ADD/SUB` paths now write architectural pointer values into GPRs while keeping metadata separate. Audit remaining ABI table/stack cases. |
| Pointer arithmetic flags | done for active ADD/SUB paths | `ADD/SUB` on pointer-tagged registers updates `CF/ZF/SF/OF` before metadata updates. |
| Pointer compare flags | done, verifier-hostile | `CMP` involving pointer-tagged registers computes flags from architectural scalar address values. No branch metadata is used to turn old compares into verifier range facts. |
| Full supported flag semantics | in progress | `SBB`, `POPCNT`, shift/rotate count-zero behavior, `SHLD`, `SHRD`, and `IMUL` `CF/OF` were tightened. Continue auditing x86 undefined-flag cases and non-current opcodes. |
| `SBB` borrow semantics | done | `SBB` uses `dst - src - CF` and computes borrow without source wraparound loss. |
| `POPCNT` flags | done | `POPCNT` clears `CF/OF/SF` and sets `ZF` from the source operand. |
| Immediate sign extension | done for active imm32 forms | 64-bit `ALU/CMP/TEST r/m64, imm32` and `mov r/m64, imm32` sign-extend the low 32-bit immediate before execution. |
| `DIV` semantics | non-faulting path done | Unsigned division now uses `AX`, `DX:AX`, `EDX:EAX`, or `RDX:RAX` according to operand width and writes quotient/remainder to the x86 architectural destinations. Do not add simulator-side zero/overflow guards or trap paths; divide faults remain a fault-like behavior gap, not a checked-simulator branch. |
| `CMOV` metadata synchronization | done | A taken 64-bit `CMOV` copies pointer metadata including offset. |
| `XCHG` metadata synchronization | done | 64-bit `XCHG` exchanges pointer metadata; same-register no-op preserves metadata. |
| CTX output retag helper | done | `x86_sim_prepare_ctx_output()` was removed; stores use state produced by prior x86 instructions. |
| Packet fastpath generic path | done, verifier-hostile | Packet helpers use the raw packet path only when the metadata tag is packet; otherwise they execute the generic native memory operation for the same scalar address. This is semantically cleaner but makes verifier explore impossible tag/scalar joins. |
| x86 pointer-as-integer representation | open | Current GPR scalar fields can still hold verifier pointer-typed values. That matches native address values more closely, but verifier rejects later integer operations such as shifts, masks, byte stack stores, and scalar-pointer subtraction. A final design needs a formally specified address abstraction or another semantics-preserving representation, not a safety guard. |
| Stack model extent | in progress | The stack is byte-addressed and stack-disabled push/pop/call is forbidden by generated macro contracts. Pointer payload metadata was removed from stack because hardware stack memory stores bytes, not verifier tags; stack read/write helper signatures now carry only bytes, offsets, and widths. Current generated sources choose a 64-byte shallow layout or a 128-byte deep layout; future extent changes must enlarge exact byte memory, not add runtime bounds guards. |
| Native call return-address model | in progress | `X86_SIM_X86_CALL` now writes the next native instruction address into the modeled stack slot, and subfunction `ret` pops the modeled stack. Remaining work: dynamic/modified-return control flow still assumes the callee returns to the static call continuation. |
| RODATA model | open, sentinel removed | The benchmark-specific hardcoded rodata switch was deleted. RIP-relative `lea` now produces only the architectural scalar address; a real rodata proof still needs an exact memory image rather than a magic table. |
| No Python semantic workaround | ongoing | Python remains a one-to-one native instruction/label emitter; no helper selection, benchmark renderer, loop analysis, or verifier workaround moves into Python. |
| Generation-time unsupported forms | open | Current Python still raises on native forms not yet modeled. That is only an implementation-gap signal for non-accepted artifacts; the final simulator cannot rely on generation-time rejection as a safety argument and must implement exact semantics for every accepted native form. |
| Generated fallback returns | done | Generated entry/subfunction tails use `__builtin_unreachable()` after native-covered CFG paths; they no longer emit fallback return values. This requires the generator CFG theorem that every reachable path reaches a native branch/call/ret edge. |
| Per-instruction constant operands | done | Generated C emits one macro-expanded native instruction with constant opcode/operand fields. The older struct path may materialize a local `const struct x86_insn`; the active local-state path passes constants directly into C macros. Python still does not choose helpers. |
| Correctness-first micro compile/verify check | latest: 22/29 verifier ok | `results/README-20260519-local-state.md`: all 29 compile with `clang -O3`; 22 load/test. Logs are stored as `results/*-20260519-025825.verifier.log`; dominant failures are byte-wise pointer stack stores, the old native-call struct path, packet alias range visibility, and cgroup_skb packet-write policy. |
| Local-register macro state experiment | active default for non-call micro | `x86_sim_local_bpf.h` replaces `struct x86_state` field traffic with entry-function local variables for architectural GPRs/flags/ghost metadata and scoped instruction macros. Python still emits one native instruction macro; macro expansion must not add branch assertions, bounds checks, safety guards, or benchmark-specific logic. Native local-call subfunctions still need a separately specified macro-frame path before they move off the struct path. |
