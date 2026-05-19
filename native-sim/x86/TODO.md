# x86 simulator Direct-Native Safety TODO

This file tracks the remaining work needed before verifier acceptance of the
eBPF proof artifact can justify directly executing the native x86 artifact.

Hard rule: the proof program must not use a runtime check, unsupported, fallback,
synthetic bound, or verifier-only assertion to make native execution safe. If a
native path is not modeled exactly, the artifact must fail before native
execution, or a proof must show that the path is unreachable.

| Item | Status | Required completion condition |
| --- | --- | --- |
| Branch proof assertions | done | `last_cmp_*` and `x86_sim_assert_*` are removed; branches use only x86 flags. |
| Packet/output runtime bounds checks | done for active packet helpers | Packet/output helpers no longer check `data_end` before loads/stores; verifier acceptance must come from equivalent pointer state, not a proof-only guard. |
| Runtime fallback return | done | Generated top-level paths no longer return fallback values such as `XDP_ABORTED`; negative helper results are proof obligations, not native-execution safety mechanisms. |
| Stack slot range checks | done for current micro, proof open | The current generated objects only use modeled slots. Final acceptance must prove stack slot coverage before native execution or reject before native execution. |
| Runtime `X86_SIM_UNSUPPORTED` reachability | done for current micro, open for proof | Current 29/29 load/test result shows the generated corpus is accepted, but direct-native safety still needs a proof or load-time rejection rule for every unsupported path in every accepted artifact. |
| Hidden packet offset metadata | implemented, proof open | `off_<reg>` is active metadata for packet proof; prove it stays synchronized with the concrete native effective address and is observationally invisible to x86 scalar execution. |
| SKB packet-length metadata | done for current micro, proof open | `ctx+0x70` loads carry `PACKET_LEN`; `PACKET_LEN + PACKET` becomes `PACKET_END` under the ABI theorem `data + skb_len == data_end`. |
| Stack pointer payload slots | done for current micro, proof open | Low slots `0..8` carry verifier pointer payloads for real x86 stack spills, including `bpf_local_call_fanout_dispatch`; deeper pointer spills must be rejected or modeled before native execution. |
| CTX/SKB/output ABI model | implemented for current micro, proof open | XDP ctx, SKB data/len, output stores, and packet payload are modeled in C; prove the layout exactly matches the direct x86 artifact or reject before native execution. |
| RODATA model | open | Prove generated table reads match native read-only data addresses and contents. |
| Full supported flag semantics | open | Audit every supported opcode flag helper against x86 semantics; unsupported flag-dependent opcodes must be rejected before native execution. |
| Same-register `xchg` semantics | done | `xchg reg, reg`, including `xchg ax, ax`, is modeled as a no-op and preserves ghost metadata. |
| Native call return-address model | open | Either model concrete return-address contents or reject callees that read the return-address slot. |
| No Python semantic workaround | ongoing | Python remains a one-to-one native instruction/label emitter; no helper selection, benchmark renderer, loop analysis, or verifier workaround moves into Python. |
| Full micro rerun after safety cleanup | done | `results/README-20260518-210632.md` records 29/29 compile/load/test success after adding slot7/slot8 pointer payload support. |
