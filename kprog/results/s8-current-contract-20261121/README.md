# S8 context, tail-frame and stock metadata result

This finite lane publishes context-handler dispatch and x86 tail cleanup. The current ordinary B pipeline supplies stock rewrite metadata. All current observations below use the 2026-11-21 epoch. Historical 2026-11-09 records retain their original identity in the raw reconciliation receipt.

## Item 3: context layout

Commit `f94db22b7` selects implemented handlers in the shared function used by both ISA specializers. The current user instruction explicitly requests this behavior after historical `421c97bb8` selected RAW for those families. `context.json` lists all 32 types, public/physical types and actual stock verifier-ops declarations and converters.

| Handling on both ISAs | Program types |
| --- | --- |
| Typed | 3 SCHED_CLS, 6 XDP, 8 CGROUP_SKB |
| Identity RAW | 2 KPROBE, 5 TRACEPOINT, 15 CGROUP_DEVICE, 17 RAW_TRACEPOINT, 20 LIRC_MODE2, 24 RAW_TRACEPOINT_WRITABLE, 26 TRACING, 27 STRUCT_OPS, 28 EXT, 29 LSM, 31 SYSCALL, 32 NETFILTER |
| Generation handler required | 1 SOCKET_FILTER, 4 SCHED_ACT, 7 PERF_EVENT, 9 CGROUP_SOCK, 10 LWT_IN, 11 LWT_OUT, 12 LWT_XMIT, 13 SOCK_OPS, 14 SK_SKB, 16 SK_MSG, 18 CGROUP_SOCK_ADDR, 19 LWT_SEG6LOCAL, 21 SK_REUSEPORT, 22 FLOW_DISSECTOR, 23 CGROUP_SYSCTL, 25 CGROUP_SOCKOPT, 30 SK_LOOKUP |

`context-layout.json` records an actual harmless RAW store on local storage: UAPI `__sk_buff.mark` is offset8; both current vmlinux layouts place `sk_buff.prev` at8 and `mark` at168. The RAW store changes the local previous-pointer slot; the converted store changes mark. The stock `bpf_convert_ctx_access` mark arm selects the physical offset. Baseline dispatch remains in raw `context-before.json`.

## Item 4: actual native tail frame

Commit `5c77f7a9d` includes stack restoration preceding immediate return-value setup in synthesized tail cleanup. Cleanup carries frame operations and preserves the counter pointer. Existing admission conditions retain their behavior.

The current x86 native JIT calls `emit_prologue(..., 0, ...)`: its JIT-owned stack depth is zero even when verified B uses stack. `[rbp-16]` therefore matches this frame. P's own stack cleanup precedes callee-save and counter-slot pops. This differs from the historical swapped-instruction JIT frame in the audit.

Before the fix, the host wrapper reports a frame mismatch for the 24-byte return-after-cleanup layout at initial counters0/1/32. `tail-before.json` preserves those observations. The fixed host replay passes48 cases across depths24/64/128, return-after-cleanup, counters0/1/32/33, populated/empty maps and index overflow. Eight focused Rust frame tests pass, including MOV/XOR setup after cleanup.

The fresh2GiB tc guest passes through the registered service and stock verifier. P has a24-byte stack plus savedRBX; the stock companion has a volatile stack array. Both routes return2 after34 invocations and33 tail transfers. `tc.json` holds the actual command/result; the raw request archive retains B, native inputs, compiler/verifier/service records and JIT bytes.

Intermediate fixtures preserve two generation diagnostics: a map-value alias reaches an undeclared identifier in B; spilling the typed physical context reaches `R1 type=trusted_ptr_ expected=ctx` at the tail helper. The published fixture keeps context in a saved register and uses the ordinary lookup helper. Their raw archives remain available to the context/helper owners.

## Item 6: stock rewrite effects

The current verifier runs `do_check_main`, `convert_ctx_accesses`, `do_misc_fixups`, then `fixup_call_args` on B. The current integration retains B through the stock rewrite passes. The native-image path returns early inside final `fixup_call_args`, after the metadata effects. The historical restore-before-rewrite function belongs to the earlier implementation. This pipeline integration supplies the fix through existing stock passes.

`flags.json` records six executed host cases using actual extracted helper-metadata statements: route-realm sets `dst_needed`; prandom invokes the initialization branch; override-return sets `kprobe_override`; tail-call sets `cb_access` and `max_pkt_offset`, with both subprogram stack-depth modes. Stock context conversion also supplies cb-access metadata. The host oracle establishes these statements and source stage order; attachment behavior remains a separate kernel property. `current-source.json` pins the source/kernel/image/module/linker identities.

## Item 7 proposal, first priority

Produce P with `-mgeneral-regs-only`, using scalar lowering at the source/LLVM production stage for vector operations. Arbitrary supplied vector code requires the same production transformation and universal correspondence. This follows the standing scalar-only configuration while preserving the submitted-copy path. Harmless host probes establish that the proof linker currently retains x86 PXOR XMM0 and ARM MOVI V0.

Cost: a128-bit vector value becomes two64-bit lanes; full ARM vector logical state spans512bytes with memory backing. Scalar operations add lane instructions and potential spills. Workload latency remains a measurement goal. Balanced kernel FPU/NEON wrappers additionally require legality across tracing/NMI/IRQ hooks, preemption/saved-state handling and tail-transfer cleanup. Scalar production is the proposed first implementation.

## Item 8 proposal, second priority

Generate x86 P with `-mindirect-branch=thunk-extern -mfunction-return=thunk-extern` and configured `-fcf-protection=branch`; existing relocations resolve kernel thunks. Linker-created tail transfers use the same selected thunk, and ABI lowering preserves required landing pads. ARM production uses `-mbranch-protection=standard` plus configured BTI/PAC handling and pads on generated targets. Universal correspondence covers the generic production/link rules.

Actual compiler probes measure x86 indirect-jump function size12 to15bytes and returning function9 to13bytes; ARM sizes16 to20 and8 to12bytes. Kernel thunk bodies are shared. Exact branch latency remains a target-kernel measurement goal. `proposals.json` and raw disassembly hold the observations. Implementation stays with the coordinator's chosen production path.

## Reproduction and ownership

From `/workspaces/repository`, use `taskset -c 8-23 make -f kprog/results/s8-current-contract-20261121/Makefile <target>`. `host` uses `KPROG_S8_LINKER` to select the tested linker. `tc-build` writes S8 temporary objects; capture that input set under the raw `tc-inputs` directory, then `safety GUEST=tc-guest` runs the2GiB guest. `micro` compiles30 captured sources per ISA. `safety` replays the original38 positive/negative controls, executing only positives. Guest invocations serialize within S8.

Raw evidence remains at `/workspaces/kprog-raw/S8/20261121`. Source growth is confined to shared dispatch and tail cleanup; fixtures and receipts provide the requested reproductions. Shared base/image, papers, frozen workload, peer source and staging retain their existing owners.

## Final suite outcomes

The final micro run compiles30x86 and30ARM sources successfully, with stable per-case source hashes. The38-case safety replay records9 positive executions,24 verifier refusals,1 specialization refusal and4 accepted load-only findings: `uninitialized_stack`, `immediate_push_branch`, `entry_return_slot_overwrite`, `stack_base_flags`. Negative native executions remain0. Its Make exit is2 and preserves those findings for S1/C. Tail guest exit0,48host tail cases,32context dispatches,6stock metadata cases and8Rust tests establish the finite S8 implementation scope; overall safety completion still requires the recorded findings and existing universal source/physical correspondence goals. `final-tests.json`, `safety.json` and raw archives retain the measured state.
