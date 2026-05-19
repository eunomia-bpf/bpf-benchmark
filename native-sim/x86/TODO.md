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
| Branch proof assertions | done | `last_cmp_*` and `x86_sim_assert_*` are removed; branches use only architectural x86 flags or an exactly equivalent pointer-compare lowering. |
| Runtime fallback/trap/unsupported path | done in active code | Active simulator/linker code has no accepted `X86_SIM_UNSUPPORTED`, trap, fallback return, or fail-closed safety path. |
| Runtime packet/output bounds checks | done in active packet helpers | Packet/output helpers do not add `data_end` guards that native x86 would not execute. |
| Exact scalar pointer values | in progress | `ctx`, packet, packet-end, `lea`, and pointer `ADD/SUB` paths now write architectural pointer values into GPRs while keeping metadata separate. Audit remaining ABI table/stack cases. |
| Pointer arithmetic flags | done for active ADD/SUB paths | `ADD/SUB` on pointer-tagged registers updates `CF/ZF/SF/OF` before metadata updates. |
| Pointer compare flags | done | `CMP` involving pointer-tagged registers computes flags from architectural scalar address values; metadata only supports an exactly equivalent packet/end branch lowering. |
| Full supported flag semantics | in progress | `SBB`, `POPCNT`, shift/rotate count-zero behavior, `SHLD`, `SHRD`, and `IMUL` `CF/OF` were tightened. Continue auditing x86 undefined-flag cases and non-current opcodes. |
| `SBB` borrow semantics | done | `SBB` uses `dst - src - CF` and computes borrow without source wraparound loss. |
| `POPCNT` flags | done | `POPCNT` clears `CF/OF/SF` and sets `ZF` from the source operand. |
| `DIV` semantics | open | Unsigned division must use `RDX:RAX` and write quotient/remainder. Do not add simulator-side zero/overflow guards or trap paths; possible divide faults must stay visible to the verifier/native operation rather than being converted into checked-simulator behavior. |
| `CMOV` metadata synchronization | done | A taken 64-bit `CMOV` copies pointer metadata including offset. |
| `XCHG` metadata synchronization | done | 64-bit `XCHG` exchanges pointer metadata; same-register no-op preserves metadata. |
| CTX output retag helper | done | `x86_sim_prepare_ctx_output()` was removed; stores use state produced by prior x86 instructions. |
| Packet fastpath tag fallback | done, verifier-hostile | Packet helpers fall back to generic memory semantics when runtime tag is not packet. This is semantically cleaner but makes verifier explore impossible tag/scalar joins. |
| Stack model extent | in progress | The stack is byte-addressed and stack-disabled push/pop/call is forbidden by generated macro contracts. Pointer payload metadata was removed from stack because hardware stack memory stores bytes, not verifier tags. |
| Native call return-address model | open | Calls must write a return-address value that matches the generated x86 control-flow model; callees reading the return-address slot must observe that value. |
| RODATA model | open | RODATA loads must read from a simulator memory image that corresponds to native read-only data, not a benchmark-specific hardcoded sentinel. |
| No Python semantic workaround | ongoing | Python remains a one-to-one native instruction/label emitter; no helper selection, benchmark renderer, loop analysis, or verifier workaround moves into Python. |
| Correctness-first micro compile/verify check | latest: 4/29 verifier ok | `results/README-20260518-222101.md`: all 29 compiled; `bitmap_popcount_scan`, `sorted_rule_binary_search`, `packet_checksum_fold`, and `tc_packet_checksum_fold` loaded/tested. Most failures are verifier loss of correlation between runtime tag fields and scalar pointer types or verifier stack spills beyond `fp-512`. |
