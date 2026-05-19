# x86 ReverseSim Prototype

This prototype asks one small question: can an eBPF program simulate a compact
x86-like instruction stream and pass the normal eBPF verifier?

Hard rule: correctness cannot be supplied by generation-time rejection, formal
preconditions, runtime traps, unsupported paths, fallback returns, synthetic
bounds, verifier-only assertions, or safety guards. The simulator must execute
the same instruction semantics that the hardware would execute. Verifier
failure is acceptable during this experiment; semantic mismatch is not.
Fault-like cases such as arbitrary-address load/store, stack out-of-range
access, divide-by-zero/divide-overflow, and invalid addresses are not handled by
simulator-side checks; they remain native operations that the verifier may reject.

The initial smoke case mirrors `micro/programs/simple.bpf.c`:

```c
*out = 12345678ULL;
```

The hardcoded verifier artifact represents this x86-like instruction sequence:

```text
mov rax, 12345678
ret
```

The BPF program simulates the hardcoded instruction stream and returns the
architectural `rax` value. The smoke target uses load-only verification because
the `mov; ret` stream has no native packet bounds guard or output store.

The instruction sequence is hardcoded in the `.bpf.c` file, while all simulator machinery lives in headers.

The specialized artifact is the more relevant ReverseSim verification
direction. It uses a single include plus one macro-expanded simulator call per
native instruction:

```c
#include "x86_sim_bpf.h"

SEC("xdp")
int x86_sim_hardcoded_xdp(struct xdp_md *ctx)
{
	X86_SIM_DECLARE_XDP(ctx);
	/* 0x0: mov rax, 12345678 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0, 12345678ULL);
	/* 0x5: ret */
	X86_SIM_X86_RET();
}
```

The program is not a global variable, is not a local BPF stack array, and is not
emitted as a `.rodata` map. Each instruction field is a compile-time immediate.
The generator must only encode the native instruction as opcode/operand
constants; helper selection, packet-memory fast paths, and verifier-friendly
typed execution stay inside the C-authored simulator/header. This is
intentionally not a JIT-shaped prototype: generated `.bpf.c` fixes the guest
instruction stream, but each step still executes simulator semantics in
`x86_sim.h` / `x86_sim_bpf.h`.

Clang inlining and constant propagation are allowed as an engineering mechanism
for making the normal eBPF verifier accept the proof program. They are not the
correctness boundary. Correctness is stated over the C-authored simulator
semantics: one encoded x86 instruction refines one x86 step. The compiler is
only used to specialize that same semantics for verifier analysis.

## Build And Run

```sh
make -C native-sim/x86 run
```

This is a functional prototype, not a benchmark entrypoint.

If unprivileged BPF is disabled, build as the normal user and run the loader with
privilege:

```sh
make -C native-sim/x86 build
sudo native-sim/loader/target/debug/reversesim-loader \
  --object native-sim/x86/build/x86_sim_hardcoded.bpf.o \
  --program x86_sim_hardcoded_xdp \
  --case simple \
  --load-only
```

Observed load-only smoke result:

```text
timing verify_s=... test_s=0.000000
```

Object inspection for the hardcoded artifact:

```text
no .maps section
no .rodata section
xdp section size: 0x10 bytes
```

The current simulator has prototype coverage for integer register moves,
immediates, ALU ops, compares/tests, conditional branches, stack push/pop,
native direct calls lowered to BPF subprogram calls, conditional moves,
byte/word/dword/qword loads/stores, sign/zero extension, `bswap`, `popcnt`,
`xchg`, `div`, and double shifts. This is enough to exercise many generated
micro proofs, but it is not a complete x86 ISA model.

Register numbers follow the usual x86 encoding order: `rax=0`, `rcx=1`,
`rdx=2`, `rbx=3`, `rsp=4`, `rbp=5`, `rsi=6`, `rdi=7`, `r8=8`, ... `r15=15`.

## Micro Program Status

Current active track: generated-C simulator proof path first. The JSON-linker
path is recorded below, but it is paused until generated-C coverage stays
stable.

Latest complete generated-C batch after removing benchmark-name special
renderers and moving loop/ABI capability protocol into C-authored helpers:

```sh
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py \
  --no-build-loader
```

`run_micro_sim_batch.py` is the single active generated-C batch entry.
It records `compile_s` in the Python harness and parses loader-reported
`verify_s`/`test_s`, where `verify_s` is measured inside the Rust loader around
`bpf_object__load()` or raw `bpf_prog_load()`. It runs in parallel by default
with `--jobs min(8, ncpu)`; use `--jobs 1` only when a serial run is needed.
Direct BPF instruction counts are read from the latest micro result's existing
`details/jit_dumps/*__kernel__sample00.xlated.bin` files; the batch does not
recompile direct eBPF or derive those counts from markdown/native asm.
Unless `--markdown` is specified, each run writes a timestamped result file
under `native-sim/x86/results/README-<timestamp>.md`; do not write status output to
`/tmp`.

The batch harness must not kill `clang` because compilation is slow. Clang
compile time is part of the experiment surface for large generated verifier
artifacts; a slow compile should be observed, not converted into a synthetic
compile-fail timeout.

Current observation: after removing Python helper selection, large generated-C
artifacts can make `clang -O3 -target bpf` significantly slower while it
specializes the C-authored simulator dispatch. That is a real cost of the
cleaner proof boundary, not a reason for the harness to kill clang.
If this remains too expensive, the next design change must still keep helper
selection out of Python; it should use C-authored templates/macros or a smaller
simulator state shape.

Earlier full-state layouts exceeded the kernel BPF 512-byte stack. The active
default path uses `x86_sim_local_bpf.h`, which represents x86 GPRs, flags, and
metadata as function-local variables and expands instruction helpers as macros
so clang can eliminate unused state. Programs with native local-call
subfunctions still use the older struct/subfunction path until call-frame
macro semantics are specified. Stack-enabled local-state programs use a
C-owned shallow/deep byte-stack layout: push/pop-only programs get 64 bytes,
and programs with real `[rsp/rbp + disp]` local memory get 128 bytes. This is a
state-layout choice, not a runtime guard. The batch still passes
`-mllvm -bpf-stack-size=4096` so clang does not abort before we can inspect
verifier behavior, but latest verifier failures are now dominated by pointer
representation and packet-range visibility rather than stack-frame overflow.

### Micro Compile And Verify Matrix

Historical safety-first generated-C run was 29/29 before the current
correctness-first cleanup:
[`results/README-20260518-210632.md`](./results/README-20260518-210632.md).
That run is no longer a direct-native-safety result: it used verifier-friendly
facts and paths that have since been deleted. The current active code removes
runtime unsupported checks, abort/fallback returns, loop guards, branch range
assertions, stack-slot rejection, and generated fallback returns.

Latest correctness-first local-state batch:
[`results/README-20260519-local-state.md`](./results/README-20260519-local-state.md).
All 29 generated micro sources compile with `clang -O3`; 22 load and pass
`BPF_PROG_TEST_RUN`. The generated-C path always uses native-link output and uses
`x86_sim_local_bpf.h` for programs without native local-call subfunctions.

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Current verifier result |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.426 | 19 | 24 | 0.000 | ok |
| `simple_packet` | ok | 0.371 | 16 | 21 | 0.000 | ok |
| `bitmap_popcount_scan` | ok | 0.886 | 56 | 87 | 0.018 | ok |
| `sorted_rule_binary_search` | ok | 1.104 | 65 | 158 | 0.115 | ok |
| `bcc_runqlat_log2_histogram_bucket` | ok | 2.577 | 115 | 153 | 0.989 | ok |
| `trace_event_type_switch_dispatch` | ok | 6.035 | 775 | 239 | 0.570 | ok |
| `packet_checksum_fold` | ok | 1.273 | 163 | 67 | 0.450 | ok |
| `payload_prefix_memcmp_scan` | ok | 4.107 | 184 | 135 | 0.007 | ok |
| `packet_vlan_tcpopt_parser` | run-fail | 4.784 | 218 | 222 | 0.001 | `invalid access to packet, off=42 size=1, r=0`; native guard is through an alias after variable IP header offset, and verifier does not propagate that range to the load base. |
| `bpf_local_call_fanout_dispatch` | run-fail | 8.199 | 3750 | 466 | 0.001 | still on old struct/subfunction path; verifier rejects pointer-typed stack helper arithmetic. |
| `flow_5tuple_rss_hash` | run-fail | 5.381 | 269 | 179 | 0.001 | `invalid access to packet, off=22 size=2, r=0`; same alias/range visibility issue after variable header length. |
| `katran_lb_consistent_hash_select` | ok | 24.382 | 723 | 682 | 0.003 | ok |
| `cilium_policy_guard_tree_filter` | ok | 3.229 | 164 | 134 | 0.030 | ok |
| `siphash_rotate64_mixer` | ok | 18.738 | 747 | 772 | 0.002 | ok |
| `packet_record_bounds_window` | ok | 2.452 | 97 | 118 | 0.010 | ok |
| `flow_record_field_scan` | ok | 2.543 | 97 | 91 | 0.010 | ok |
| `packed_header_bitfield_decode` | run-fail | 8.818 | 410 | 254 | 0.001 | `pointer arithmetic with <<= operator prohibited`; byte stack stores a packet pointer as x86 bytes, and verifier will not shift pointer-typed values. |
| `bpftrace_string_search_prefix_scan` | ok | 2.769 | 161 | 164 | 0.606 | ok |
| `tracee_syscall_name_table_lookup` | ok | 3.394 | 275 | 176 | 0.122 | ok |
| `tracee_http_method_prefix_detect` | ok | 4.271 | 209 | 151 | 0.009 | ok |
| `cilium_socket_lb_service_select` | ok | 3.551 | 210 | 216 | 0.124 | ok |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 3.176 | 180 | 190 | 0.051 | ok |
| `tetragon_process_event_arg_filter` | run-fail | 5.970 | 568 | 250 | 0.001 | `pointer arithmetic with >>= operator prohibited`; byte stack stores a packet pointer as x86 bytes. |
| `otel_stack_frame_unwind_scan` | ok | 3.069 | 156 | 212 | 0.044 | ok |
| `cilium_ct_nat_tuple_rewrite` | ok | 3.189 | 197 | 195 | 0.047 | ok |
| `packet_toeplitz_rss_hash` | ok | 4.368 | 334 | 211 | 0.032 | ok |
| `bpftrace_comm_key_fnv_hash` | run-fail | 6.682 | 631 | 217 | 0.001 | `pointer arithmetic with >>= operator prohibited`; byte stack stores a packet pointer as x86 bytes. |
| `tc_packet_checksum_fold` | ok | 2.233 | 167 | 52 | 0.341 | ok |
| `cgroup_skb_hash_chain` | run-fail | 2.814 | 829 | 100 | 0.007 | `cannot write into packet`; native SKB result ABI writes packet head, but cgroup_skb verifier policy rejects packet writes. |

For verifier diagnostics, capture the kernel verifier log through the loader:

```sh
sudo -n native-sim/loader/target/debug/reversesim-loader \
  --object native-sim/x86/micro-prog/build/packet_checksum_fold.bpf.o \
  --program packet_checksum_fold_x86_sim_xdp \
  --case packet_checksum_fold \
  --load-only \
  --verifier-log native-sim/x86/results/packet_checksum_fold.verifier.log
```

### Direct BPF Control For Verifier-Complexity Cases

These controls check whether verifier failures come from the original micro
programs or from the x86-simulator proof shape. The original `micro/programs/*.bpf.c`
objects were compiled and loaded with the same loader, same generated inputs,
same expected result, and same program-type retval on 2026-05-18. The direct eBPF
programs pass verifier and `BPF_PROG_TEST_RUN`.

These rows compare direct eBPF against an earlier x86-simulator proof shape.
They are historical verifier-complexity controls from the safety-first path, not
current correctness-first load results. The current active path prioritizes
exact simulator semantics and currently has 22/29 verifier/load/test success.

| Micro program | Direct eBPF result | Direct load/test s | Direct static BPF insns | Direct verifier processed / total / peak / max-state | x86 simulator result | x86 simulator verify s | x86 simulator static BPF insns | x86 simulator verifier processed / total / peak / max-state | Reason |
| --- | --- | ---: | ---: | --- | --- | ---: | ---: | --- | --- |
| `bpf_local_call_fanout_dispatch` | ok | 0.03 | 528 | `9572 / 120 / 70 / 10` | ok | 0.055 | 10985 | `22584 / 1430 / 583 / 8` | Native 16-record loop dispatches into four local-call targets. The active C-owned call/frame model greatly increases static BPF size, but the verifier can analyze the resulting shape. |
| `bpftrace_string_search_prefix_scan` | ok | 0.07 | 200 | `21394 / 546 / 143 / 47` | ok | 0.396 | 148 | `326956 / 7055 / 108 / 5` | The current pass uses C/header state-shape fixes and exact x86 flags, not branch assertions. It remains much more expensive than direct eBPF but stays below the verifier limit. |

Latest historical safety-first generated-C run:
[`results/README-20260518-210632.md`](./results/README-20260518-210632.md).
The current active path is stricter about simulator semantics and no longer
claims 29/29 verifier success.

The backup `helper-selection` path had lower clang cost but still failed
`bpf_local_call_fanout_dispatch` and `bpftrace_string_search_prefix_scan` at
the verifier. The active C-owned path keeps the cleaner Python proof boundary,
but after the direct-native cleanup those two programs currently fail for the
same pointer-representation reasons as the other large cases.

Python LOC check for this cleanup and backup:

```text
generate_micro_sim_proofs.py current:       778 lines
x86_sim_local_bpf.h latest:               1108 lines
x86_sim_bpf.h latest:                      661 lines
x86_sim.h latest:                         1918 lines
loader/src/main.rs latest:             1192 lines
removed x86_sim_template_helpers.bpf.c: 2010 lines
```

The line movement is intentional: proof protocol complexity is being moved out
of Python and into the C-authored simulator/header where it can be specified
and eventually verified with the helper semantics. The helper-selection backup is
kept only as historical compile-cost evidence for this experiment; new
generated-C timing runs use `run_micro_sim_batch.py`.

The immediate generated-C target is now cleaner but not complete. JSON-link
completion is a separate next experiment.

The formalization target for the generated-C path is
[`simulator-spec.md`](./simulator-spec.md). That spec is intentionally tied to
the current code: instruction helper steps, native branch/call/return lowering,
byte-addressed stack layout, hidden packet metadata, and ABI output-store
capability preservation are named proof obligations rather than
benchmark-specific fixes.

Active generator rule: Python must not rewrite native return semantics, branch
semantics, or opcode semantics. A native `ret` is emitted as
`X86_SIM_X86_RET();`; one native instruction becomes one simulator-helper step
plus explicit native branch/return structure. Program-type return mapping lives
in `micro/config/micro_pure_jit.yaml` via `expected_retval`, and the runner
reuses that metadata for XDP (`2` default), TC (`0`), and cgroup skb (`1`).

C macro and inline-helper boundary rule: C may use macros, `__always_inline`,
`__builtin_constant_p`, and clang constant propagation to specialize local x86
ISA semantics such as opcode, register, width, memory operand, and flag
handling. C must not become a hidden cross-instruction renderer: no
benchmark-name logic, no algorithm reconstruction, no semantic shortcut for a
known output store, no proof-only branch assertion, and no proof-only bounds
check that native x86 would not execute. Python remains a one-to-one producer of
native x86 instruction steps and explicit native control-flow labels.

Native-direct safety rule: verifier acceptance must come from
semantics-preserving optimization and state layout, not from facts that native
x86 does not guarantee. The active code deletes the previous `last_cmp_*`
metadata and `x86_sim_assert_*` branch helpers. Proof-only packet/output bounds
checks and stack-slot runtime rejection were removed from the active simulator.
Remaining model extent questions are tracked in [`TODO.md`](./TODO.md): they
must be resolved by implementing the exact simulator semantics, not by adding
proof-only guards or generation-time exclusions.

Runtime unsupported rule: native x86 will not return `XDP_ABORTED` or take an
`X86_SIM_UNSUPPORTED` branch. The active simulator path must not contain such a
runtime safety branch. Any native construct outside the modeled subset is a
simulator implementation gap.

Generator complexity rule: the Python proof generator must stay below 800
lines. Its only semantic output should be a simple native stream such as
`label: insn` plus metadata needed to preserve labels, native operands,
expected retval/result, and input selection. Python must not own loop lowering,
call lowering, liveness, state-shape selection, helper selection, or
verifier-workaround logic. Those belong in C-authored simulator/spec code
where they can be written once, specified, and eventually verified.

Compile-cost reduction rule: keep the Python side simple even when clang
compile time is high. Any attempt to reduce compile cost must happen inside the
C-authored simulator/header/macro layer, for example by changing helper
structure, inline boundaries, macro shape, verifier-visible state layout, or
instruction semantics factoring. Do not move control-flow reconstruction,
helper selection, loop-shape analysis, state specialization, or benchmark
workarounds back into Python to make a hard case compile faster.

The aborted `__noinline -> __always_inline` plus `bpf_loop -> C for-loop`
experiment showed why this line matters: doing that transformation in
`generate_micro_sim_proofs.py` only adds more Python-owned lowering logic. The
current generator shrink instead removed Python `bpf_loop` lowering and
internal call-return stack lowering outright. C now consumes the simple labeled
instruction stream through ISA-level branch/call/return macros
(`X86_SIM_X86_JCC`, `X86_SIM_X86_JMP`, `X86_SIM_X86_CALL`,
`X86_SIM_X86_RET`): branch macros lower native x86 control flow to C labels and
`goto`; call macros model the native return-address slot; generated callee frame
instructions execute as x86 instructions. There is no fuel guard or synthetic
trip bound in the active path because that is not x86 ISA semantics; verifier
rejection for a loop is recorded as a verifier result.

C state-layout changes in the active path:

- `X86_SIM_EXEC` performs C-owned typed opcode dispatch; Python still emits only
  `X86_SIM_RUN_OP(X86_OP_..., operands...)`.
- The stack model is byte-addressed stack memory. Pointer payload metadata was
  removed from stack because hardware x86 stores bytes, not verifier tags. The
  generated source selects 64-byte or 128-byte state layout, but no runtime
  stack bounds guard is inserted. Stack helper signatures now carry only bytes,
  offsets, and widths; they no longer accept or return hidden pointer payloads.
- Top-level packet memory loads use a raw-load fastpath for
  packet bases that already have verifier-visible range. Subfunction steps use
  the generic typed simulator path so local-call proof state stays stable.
- Packet pointer arithmetic preserves concrete scalar register semantics and
  tracks packet offsets in hidden per-register metadata. Raw packet loads may
  recompute `data + offset + disp` for the verifier without changing the
  modeled x86 register value.
- SKB length loads from `ctx+0x70` produce the native scalar length and a
  `PACKET_LEN` ghost capability tied to `data_end`. Adding that length to the
  packet `data` pointer produces `PACKET_END`, which expresses the real SKB ABI
  relation `data + len == data_end` without adding a runtime bounds check.
- The previous `cmp`/`test` branch-proof metadata and SKB branch range hook were
  deleted. Branch macros now only evaluate x86 flags through `x86_eval_cc()` and
  transfer control.

Generated-C migration todo:

| Item | Status | Completion check |
| --- | --- | --- |
| Native return ABI lives in metadata/header, not Python rewrites | done | `ret` emits `X86_SIM_X86_RET();`; runner checks `expected_retval` from YAML. |
| Remove benchmark-name renderers from Python | done | `generate_micro_sim_proofs.py` no longer dispatches on `packet_checksum_fold`, `bpftrace_string_search_prefix_scan`, `bpf_local_call_fanout_dispatch`, or other benchmark names. |
| Remove stale C special templates | done | Unused checksum/string-scan C helper templates were deleted from `x86_sim_bpf.h`; the header now contains generic simulator plumbing only. |
| Move proof protocol out of Python | done | Python pc-dispatch, ctx-store write-set insertion, `bpf_loop` lowering, internal call-return stack lowering, helper selection, and benchmark-name renderers were removed; remaining Python CFG work is mechanical label/branch emission. |
| C-owned loop/call protocol | done for current micro | `X86_SIM_X86_JCC/JMP` lower native branches directly to C labels; `X86_SIM_X86_CALL` models call stack adjustment and writes the next native instruction address as the return address; generated callee frame instructions execute through normal x86 helpers. |
| Shrink Python generator below 800 lines | done | `generate_micro_sim_proofs.py` is 778 lines. |
| Historical safety-first generated-C batch | recorded | `results/README-20260518-210632.md`: 29/29 pass before the later no-trap/no-guard cleanup. |
| Delete non-x86 loop fuel guard | done | Active branch macros no longer decrement `X86_SIM_LOOP_FUEL`; backward edges use plain x86 branch semantics. |
| Move opcode dispatch specialization into C | done | `X86_SIM_EXEC_TYPED` selects C helpers from constant `X86_OP_*`; Python does not choose helpers. |
| Stack pointer metadata | correctness-first rewrite | `x86_state` stores only byte-addressed stack contents, with a 64-byte shallow or 128-byte deep layout selected at generation time; no runtime slot rejection remains in the active simulator. |
| Raw packet load fastpath | done | Top-level packet loads use verifier-visible packet pointers directly instead of adding per-load bounds helpers. |
| Delete SKB length branch range hook | done | The proof-only `cmp [ctx+0x70], imm; ja target` range assertion was removed. |
| Model SKB packet end through ABI metadata | done | `ctx+0x70` loads carry `PACKET_LEN`; `PACKET_LEN + PACKET` becomes `PACKET_END`, matching `data + skb_len == data_end`. |
| Preserve same-register `xchg` semantics | done | `xchg ax, ax` is modeled as the real x86 no-op, so it does not clear packet pointer metadata. |
| Non-faulting `DIV` semantics | done | `div` now uses `AX`, `DX:AX`, `EDX:EAX`, or `RDX:RAX` according to operand width and writes quotient/remainder to the architectural destinations. Divide faults remain unguarded fault-like behavior. |
| Hidden packet-offset metadata | done | Packet-capable registers carry an offset field used only to make packet bounds visible to the verifier. |
| Delete branch-proof metadata | done | `last_cmp_*` state and `x86_sim_assert_*` helpers were removed from active C. |
| Remove packet/output runtime bounds checks | done | Active packet/output helpers no longer guard loads/stores with proof-only `data_end` checks. |
| Remove top-level fallback returns | done | Generated paths no longer translate helper results into `XDP_ABORTED` or any other fallback return. |
| Delete hardcoded rodata sentinel | done | The old benchmark-specific rodata switch was removed. RIP-relative `lea` now keeps only the architectural scalar address until a real read-only memory image is specified. |
| Split memory-domain helpers | done for current micro | Top-level packet loads have a raw pointer path; subfunctions and stack/ctx accesses keep typed helpers. |
| Per-instruction const record | done | `X86_SIM_EXEC` creates a local `const struct x86_insn` for each macro-expanded native instruction so clang can specialize C-authored semantics without Python helper selection. |
| Remove generated fallback returns | done | Generated entry and subfunction tails use `__builtin_unreachable()` after the native CFG; no fallback return value is emitted. |
| Correctness-first compile/verify check | latest: 22/29 verifier ok | [`results/README-20260519-local-state.md`](./results/README-20260519-local-state.md): all 29 generated micro sources compile with `clang -O3`; 22 load and test successfully. Remaining failures are verifier rejection of byte-stack pointer stores, native-call struct path state, packet alias range visibility, and cgroup_skb packet-write policy. |
| Local-register macro state experiment | default for non-call micro | `x86_sim_local_bpf.h` represents x86 GPRs/flags/metadata as function-local variables and makes helper steps scoped macros/templates. This keeps Python a one-to-one native instruction emitter while reducing proof BPF size for most micro programs. Native local-call subfunctions still need a separately specified macro-frame path. |
| Direct-native safety TODO | open | See [`TODO.md`](./TODO.md) for remaining stack, metadata, ABI, rodata, flag, and call-return proof obligations. |

The current active path is correctness-first: it removes simulator-only safety
guards even when that makes the verifier unhappy. Future work should make the
state layout verifier-friendly without reintroducing benchmark renderers,
branch assertions, synthetic bounds checks, runtime traps, fallback returns, or
loop-shape analysis in Python.

## JSON-Linker Todo

Completion criteria for this experiment are stricter than the generated-C
prototype: every micro program must go through `python -> JSON proof -> Rust
loader bytecode link -> BPF_PROG_LOAD -> BPF_PROG_TEST_RUN`, with no per-micro
`.bpf.c` compile step after the JSON exists.

| Item | Status | Note |
| --- | --- | --- |
| JSON proof schema contains numeric instruction fields | done | Loader does not parse C macros. |
| JSON proof schema contains C-helper template plan | done | JSON records helper names, operands, control-flow targets, and proof metadata, not raw BPF bytes. |
| Rust loader is only a BPF linker | done | It links encoded BPF instructions and does not contain `emit_x86_*` semantics. |
| Build reusable eBPF simulator/helper bytecode | paused | The old C template object used unsupported/fallback semantics and was removed from the active build. |
| Batch runner uses JSON path as the pass/fail source | paused | The loader no longer has a default template object; a revived JSON path must provide a C-authored template object explicitly and preserve exact simulator semantics. |
| All 29 micro programs load and return expected result | blocked | Paused. Native call-flow is not implemented in the JSON linker, so the strict JSON path is not the current source of truth. |

Current strict JSON-link status:

| Micro program | JSON-link status | Note |
| --- | --- | --- |
| `simple` | ok | JSON generated by Python; loader inline-links C-authored arg templates; verifier load and test_run pass. |
| `simple_packet` | ok | Same strict JSON-link path. |
| `bitmap_popcount_scan` | ok | Same strict JSON-link path after counted-loop expansion. |
| `bpf_local_call_fanout_dispatch` | blocked | JSON contains reachable native `call`; loader currently reports `JSON template linker does not support native call flow yet`. |
| remaining micro programs | paused | Do not treat the JSON table as complete until native call/return CFG linking is implemented and the loader is rebuilt before the batch run. |

Strict JSON-link completion todo:

| Item | Status | Next step |
| --- | --- | --- |
| Delete Python BPF emitter | done | `reversesim_bpf_templates.py` removed. |
| Delete hardcoded BPF JSON catalog | done | `template-catalog/simple_mov_imm_ret.json` was removed; verifier-facing BPF should come from C helper templates. |
| Keep JSON generator semantic-free | done | It emits native/linked metadata plus a declarative C-helper template plan. |
| Define C helper-template ABI | done | Current ABI is `state*, data, data_end, packed_args, imm`; pointer tags are 64-bit scalar state. |
| Implement minimal C-template link for `simple` | done | `simple` and `simple_packet` pass verifier and expected-result checks. |
| Extend template classes one at a time | paused | Packet/integer/branch templates work for smoke cases; native call/return CFG linking remains open. |

The deliberate next step is not to add x86 semantics to the loader or to a
Python BPF emitter. Each new coverage increment should add or extend a
C-authored helper/template class, then prove that template against the x86
small-step rule it claims to implement.

## Template Granularity And Dispatch

The template unit should be an instruction class, not a whole concrete micro
program and not one bytecode blob per immediate. For example, ALU instructions
should share the existing helper families:

| x86 class | C helper family | Operation selector |
| --- | --- | --- |
| register/immediate ALU | `x86_exec_alu_imm` | `X86_ALU_*` in `aux` |
| register/register ALU | `x86_exec_alu_reg` | `X86_ALU_*` in `aux` |
| register/memory ALU | `x86_exec_alu_mem` | `X86_ALU_*` in `aux` |
| compare/test | `x86_exec_cmp_*`, `x86_exec_test_*` | helper family plus width |
| moves/loads/stores | `x86_exec_mov_*` | helper family plus width/address mode |

Top-level dispatch should be a direct scheduled sequence derived from the fixed
native program:

```text
step 0 -> x86_exec_mov_load(args...)
step 1 -> x86_exec_alu_reg(args...)
step 2 -> branch using x86_eval_cc(...)
```

It should not be a runtime `switch (op)` over arbitrary guest bytecode. A
runtime opcode switch is attractive for a normal simulator, but it makes the
verifier prove every opcode path at every program counter and brings back the
state-explosion problem. In this experiment the program is fixed, so the
verifier-facing schedule should be fixed too.

A small switch or if-chain inside a shared helper is acceptable when it is the
semantics of one instruction class. `x86_alu_result()` already does this for
`X86_ALU_ADD/SUB/XOR/...`. If a shared helper becomes too hard for the verifier,
the next split should still be by class or subgroup, such as arithmetic ALU vs
bitwise ALU, not by concrete micro program.

The first real JSON linker implementation validated the boundary and exposed an
important verifier constraint. The initial subprogram-call form was:

```text
JSON step -> fill stack `struct x86_insn`
          -> pseudo-call C-authored `x86_tmpl_*` subprogram
          -> JSON CFG branch/fallthrough in loader glue
```

That is not sufficient for packet-pointer programs. `x86_exec_mov_load` writes
real packet pointers into `x86_state.p_*`; when a later C subprogram reloads
that pointer from the caller's stack state, the verifier no longer treats it as
a packet pointer. The observed failure on `simple` is:

```text
R4 invalid mem access 'scalar'
```

So the next ABI change must be one of:

1. C-authored inline fragments, not subprogram calls, for pointer-sensitive
   helpers. This keeps packet pointer state in one verifier frame.
2. A linked-path simulator state that stores packet offsets/capabilities as scalars
   and recomputes `data + offset` inside each memory helper. This avoids saving
   real kernel pointers in simulator state and is likely easier to formalize.

The current strict JSON-link path implements both changes for the passing
smoke cases:

```text
JSON step -> load packed args/imm constants into BPF registers
          -> inline C-authored `x86_tmpl_arg_*` body
          -> rewrite template `exit` instructions to fall through to glue
          -> store pointer tags in 64-bit scalar slots
          -> recompute packet pointers from `data + offset` inside memory helpers
```

This is still a linker, not a Python BPF emitter: Python selects helper IDs and
operands, C defines helper semantics, and the Rust loader only links bytecode,
rewrites local exits, resolves CFG branches, and supplies constant arguments.
Inlining the C-authored arg templates keeps verifier constants visible in one
frame. At the moment this has only been validated for the strict JSON smoke set
listed above; native call/return CFG linking is still missing.

Active JSON-link rules:

1. Keep the Rust loader as a BPF linker only: schema validation, label/branch
   fixups, C-template bytecode splicing, `BPF_PROG_LOAD`, and
   `BPF_PROG_TEST_RUN`.
2. Move x86 semantics into named C/bytecode templates, not loader code and not
   Python BPF emitters.
3. For each micro, require all four checks: JSON generation, kernel verifier
   load, `BPF_PROG_TEST_RUN`, and expected result.
4. Treat any local abort/bound/tail-inline shortcut as a proof obligation;
   it must be justified by a loop-bound or control-flow lemma before native
   direct execution can rely on it.

Do not quote new JSON-link status without first reviving and rebuilding that
paused path. Stale loader binaries previously made the JSON smoke table
misleading. `ok` means JSON generation, loader link, verifier load, test run,
and expected-result check all passed. The active completion target for now is
the generated-C simulator path below, not the JSON linker.

## Simulator Dispatch Boundary

The generator emits mechanical simulator steps:

```c
X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, aux, imm);
```

Python does not choose `x86_exec_*` helpers. C macros dispatch to the
C-authored simulator, and may use typed fast paths when opcode/operand
constants prove that the fast path is the same x86 step. This keeps the formal
object small: the proof obligation is the C simulator/helper semantics, not a
Python helper-selection policy.

For the eventual bytecode-link path there will be no second user-space compiler
pass after program constants are attached. Any fast path that relies on
compile-time constants must therefore correspond to a C-authored template or
macro that the linker can splice unchanged, rather than Python rewriting
instruction semantics.

## JSON Bytecode Plan

This is a separate experimental path from the current generated `.bpf.c`
prototype. The core idea is to keep the simulator semantics in C, but move
per-program specialization out of C source generation and into an explicit
bytecode-linking artifact.

## Formalization Constraint

The loader must not become an x86-to-BPF JIT compiler. If the Rust loader grows
functions such as `emit_x86_cmp_mem_imm`, `emit_x86_popcnt`, or
`emit_x86_alu_imm`, then the thing to verify becomes a compiler-sized semantic
translator rather than a small linker. That defeats the purpose of this
experiment: the user requirement is that the x86-to-BPF conversion remains
small enough to audit and eventually formalize.

The intended split is therefore stricter:

- The loader only understands already-encoded BPF instructions, labels, branch
  fixups, program metadata, and load/test-run plumbing.
- x86 semantics live in a fixed template/simulator library. Each template is
  the unit of proof: under the simulator state relation, one template refines one x86
  small-step rule.
- Python may select templates for concrete x86 instructions and fill operands,
  but that selection must stay declarative and table-driven. It should not
  become a second large compiler hidden in the loader.
- Native direct execution is allowed only after a separate equivalence bridge
  proves that the native sequence and the verifier-facing BPF template sequence
  implement the same ABI, state layout, and memory/capability behavior.

This is why the simulator/template path can be simpler than kinsn: the kernel
does not learn new instruction semantics, and the trusted kernel-side mechanism
can stay close to ordinary BPF loading. The complexity is concentrated in a
small set of reusable templates whose contracts can be proven once and reused
across micro programs.

The split is:

1. C owns the simulator/helper semantics: guest register state, flags, memory
   capability checks, and opcode helpers such as `x86_exec_mov_load` and
   `x86_exec_alu_reg`.
2. Python parses native ASM and emits declarative JSON metadata: concrete x86
   instruction records, selected template IDs, operands, labels, branch targets,
   fixups, expected result metadata, and enough source annotation to audit each
   selection. Python must not emit verifier-facing BPF instructions.
3. A fixed C-authored or checked-in bytecode catalog owns the verifier-facing
   eBPF fragments for each template ID.
4. The loader concatenates fixed bytecode fragments, links them against the
   simulator/helper bytecode, resolves local branch/call fixups, attaches
   metadata such as license/program type/name, and loads the finished BPF
   program.

The loader should stay a thin bytecode linker, ideally around 100-200 lines for
the splicing path. It must not decode x86, choose opcode semantics, run
constant propagation, optimize control flow, or silently rewrite verifier
semantics. Python also must not become a BPF emitter; semantic decisions belong
to the fixed template catalog where they can be tested and later formalized.

In this model, "helper link" means linking against verifier-visible BPF
subprograms or inlined bytecode blocks from the simulator library. It does not
mean adding new kernel helpers. The final verifier input is still one ordinary
eBPF program assembled from fixed pieces.

A minimal JSON shape is enough:

```json
{
  "name": "simple",
  "prog_type": "xdp",
  "entry": "simple_x86_sim_xdp",
  "insns": [
    {
      "asm": "0x1100: mov rcx,QWORD PTR [rdi]",
      "helper": "x86_exec_mov_load",
      "op": "X86_OP_MOV_LOAD",
      "dst": "X86_RCX",
      "src": "X86_RDI",
      "flags": "X86_WIDTH_64",
      "aux": "X86_MEM_AUX(X86_REG_NONE, 0)",
      "imm": 0
    }
  ],
  "labels": { "x86_l_1100": 0 },
  "fixups": []
}
```

For an even smaller loader, JSON can contain encoded `struct bpf_insn` arrays
plus symbolic fixups instead of high-level opcode fields. Then the loader only
checks the schema, appends fragments, resolves fixups, and calls the BPF load
API. That is the cleanest direction for the hard constraint that appended eBPF
instructions will not pass through a second user-space compiler.

The JSON experiment has a separate generator from the existing `.bpf.c`
generator:

```sh
python3 native-sim/x86/micro-prog/generate_micro_json_sim_proofs.py
```

It writes artifacts to
`native-sim/x86/micro-prog/build/json-proofs/`. The old
`generate_micro_sim_proofs.py` path remains the C-source prototype path; it should
not grow JSON/linker responsibilities.

The trusted boundary for this experiment is intentionally narrow:

- C simulator helpers define the verifier-facing semantics and are the units
  to prove against the x86 subset spec.
- Python/template generation is responsible for producing a concrete proof
  program for a concrete native instruction stream.
- The loader is a mechanical linker. Its correctness obligation is byte-level
  assembly, symbol resolution, and BPF load attributes, not x86 semantics.
- Native execution is accepted only if a separate translation-validation or
  formal equivalence check proves that the native artifact follows the same ABI,
  helper sequence, and hidden state layout as the eBPF proof artifact.

## Clang Optimization Check

The generated `simple` simulator proof was compiled at multiple optimization
levels:

| Clang mode | Result |
| --- | --- |
| `-O0` | compile-fail: BPF stack limit exceeded, then clang exits with code 70 |
| `-O1` | ok: verifier load and `BPF_PROG_TEST_RUN` return `12345678` |
| `-O2` | ok: verifier load and `BPF_PROG_TEST_RUN` return `12345678` |
| `-O3` | active batch mode; full local-state run compiles all 29 generated sources |

So “turn optimization off to make proof simpler” is not viable for this C
simulator shape. Without optimization, clang keeps too much generic simulator state on
the BPF stack. The practical C prototype now uses `-O3` so clang applies all
available optimization before verifier load. The active generator passes fixed
opcode operands into
C-authored dispatch; clang constant propagation is an engineering mechanism for
making that C shape verifier-friendly, not part of the correctness argument. The
older direct-helper generator is retained only as historical compile-cost
baseline evidence in previous result files.

## Current Design Constraints

This prototype has already exposed several verifier-facing design constraints:

- Hardcoding the guest instruction stream as C data is not enough. Large local
  arrays become BPF stack pressure, so generated proof sources use one immediate
  macro call per native instruction.
- Native packet addressing needs to support both positive and negative
  displacement. Any packet bound proof must come from native x86 guards or a
  proved equivalent state layout. Synthetic helper checks are not enough for
  direct native execution because native x86 will not execute them.
- Input-dependent simulator loops are a state-explosion risk. The generator
  should still hardcode the instruction sequence, but it must stay mechanical:
  one native instruction becomes one helper step plus explicit native
  branch/return structure. Any future bounded-loop proof obligations need to
  live in simulator/helper templates, not in Python semantic rewrites.
- Native stack state must be modeled explicitly for programs with `push`, `pop`,
  or `[rsp]` accesses. A generic pointer-tag path made the verifier explore
  impossible `rsp`-as-packet states, so RSP stack accesses now need dedicated
  stack fast paths.
- `bpf_local_call_fanout_dispatch` showed that dumping only the entry symbol is
  incomplete for native direct calls. The generator now rebuilds the native
  object and disassembles call-target symbols when the markdown `## Native ASM`
  block has unresolved call targets.
- `bpf_local_call_fanout_dispatch` no longer has a benchmark-name renderer. It
  passed in an earlier safety-first shape after C-owned call/frame work, but the
  current correctness-first shape fails verifier because byte-wise x86 stack
  stores of pointer-typed GPR values become invalid BPF pointer spills.
- `bpftrace_string_search_prefix_scan` no longer uses a C-authored
  benchmark-specific scan helper. The local-state path now gets it through the
  verifier without adding branch assertions or safety guards.
- `packet_checksum_fold` still passes after deleting proof-only branch
  assertions. `tc_packet_checksum_fold` also passes through the `PACKET_LEN`
  ABI relation; `cgroup_skb_hash_chain` still fails because its native SKB
  result ABI writes packet memory and cgroup skb verifier policy rejects that
  write.
- `packet_vlan_tcpopt_parser` previously passed when hidden packet-offset
  metadata gave the verifier enough range information. The current
  correctness-first shape fails on a packet access with `r=0`; restoring
  verifier acceptance needs an equivalent state representation, not a bound
  check or branch assertion.
- The strict JSON-link loader is not the current source of truth. It has passed
  smoke programs (`simple`, `simple_packet`, `bitmap_popcount_scan`), but native
  call-flow support is missing and stale loader binaries previously produced
  misleading status if `--no-build-loader` was used.
- The object-native SKB path must model the ABI translation in C, not Python:
  `ctx+0xd0` maps to packet `data`, and `ctx+0x70` maps to packet length for
  the generated native `sk_buff` stand-in. This is now in the C simulator
  headers, including the active local-state path.
- `mov [mem], imm` packs the low 32 bits as the immediate and the high 32 bits
  as the displacement. Negative immediates must not sign-extend into the
  displacement field; the generator now masks both fields before packing.

Current correctness-first status after removing simulator guard/retag behavior,
deleting the direct pointer-compare branch metadata, shrinking stack state, and
using local-register macro state:

- `results/README-20260519-local-state.md` is the latest run. All 29 generated
  micro proof C files compiled with `clang -O3`. 22 loaded and passed test run.
- Per-case verifier logs were captured under
  `results/*-20260519-025825.verifier.log`.
- Dominant verifier failure modes are not C compile failures:
  byte-wise stack stores of verifier pointer-typed register values, the old
  struct/subfunction path for native calls, packet accesses whose native guard
  is not visible to the verifier through the final load base (`invalid access
  to packet ... r=0`), and cgroup skb packet-write policy.
- Stack-frame overflow is no longer the dominant rejection after the shallow/deep
  byte-stack layout. That change is semantics-preserving because it changes only
  modeled stack extent, not runtime stack guards or x86 control flow.
- The result is expected after deleting `cmp_ptr_*`: branches now use only
  architectural x86 flags, so the verifier no longer receives a direct packet
  pointer comparison fact. Restoring verifier acceptance must come from a
  semantics-preserving state representation, not a branch assertion or bounds
  check.
- The most important design issue exposed by the logs is representation:
  current GPR scalar fields can hold verifier pointer-typed values, while x86
  hardware registers are integers. That is close to native address execution
  for simple loads, but it makes later integer operations on those registers
  unverifiable. A final design needs a formally specified address abstraction
  or another exact representation that preserves the x86-observable behavior
  required by the ABI.
- There must be no runtime `X86_SIM_UNSUPPORTED`/trap/fallback path in the
  simulator artifact. Correctness work should add simulator semantics rather
  than relying on generation-time rejection or unreachable-path assumptions.
- Packet/output helper `data_end` bounds checks, retag helpers, fallback
  returns, and stack-slot runtime rejection are removed from the active
  simulator. Any future verifier aid must preserve hardware x86 behavior
  exactly.
- Proof-before-implementation rule: do not add a verifier-friendly fast path,
  ghost-metadata shortcut, rewritten pointer expression, or other non-hardware
  representation until the exact equivalence theorem is written in
  `simulator-spec.md`. If the theorem is missing, the code must stay disabled
  or be deleted even when it would make a verifier failure pass.
- Control-flow opcodes are no longer accepted by the ordinary
  `X86_SIM_RUN_OP()` step dispatch; generated `jcc`, `jmp`, `call`, and `ret`
  must use the C-authored x86 control-flow macros.
- Immediate handling now sign-extends imm32 for 64-bit ALU/CMP/TEST and
  `mov r/m64, imm32`, matching the x86 encoding instead of treating those
  immediates as unsigned 64-bit constants.
- Arbitrary memory faults, stack OOB, invalid-address access, and division
  faults must not be converted into simulator traps, aborts, or checked
  fallbacks. If the resulting proof program is not verifier-provable, that is a
  verifier result rather than a reason to add a safety guard.
- The `ctx`, SKB, packet, output, and rodata layouts are modeled ABIs, not
  arbitrary x86 memory. They must match the native execution layout exactly.
- The hardcoded rodata sentinel table was removed; rodata dereferences need a
  future exact memory image instead of magic-base lookup.
- The stack model is finite byte-addressed memory. Pointer payload metadata was
  removed from stack because hardware stack memory stores bytes, not verifier
  tags. It currently uses a 64-byte shallow layout or a 128-byte deep layout;
  any future increase must remain an exact byte-memory model, not a guard.
- `DIV` now models the non-faulting architectural dividend and writeback rules
  for 8/16/32/64-bit operands. Divide-by-zero and quotient-overflow remain
  fault-like cases; the simulator does not add guards or trap returns for them.
- Flag helpers now cover the active `SBB`, `POPCNT`, shift/rotate, `SHLD`,
  `SHRD`, and `IMUL CF/OF` cases more closely, but undefined-flag cases and
  non-current opcodes still need audit.
- Native calls now write the next native instruction address into the modeled
  stack slot, and subfunction `ret` pops that modeled slot. Dynamic or modified
  return-address control flow is still not modeled.

For formal verification, clang optimization is not part of the trusted
argument. This C implementation is a prototype for finding the simulator semantics and
verifier constraints. A cleaner proof story for the simulator-only route is:

- Specify the guest x86 subset state: registers, flags, safe packet/stack/table
  memory capabilities, and termination behavior.
- Specify each opcode helper (`x86_exec_mov_load`, `x86_exec_alu_reg`, etc.) and
  prove that the eBPF helper body implements that relation.
- Generate only a fixed guest instruction stream, not replacement BPF semantics;
  the verifier proves memory safety of executing that fixed stream through the
  simulator.
- Separately prove or translation-validate that the native execution artifact
  implements the same fixed guest x86 instruction stream and ABI contract.

The key constraint is that dynamic guest bytecode is hostile to the verifier:
accepting arbitrary input makes opcode dispatch, memory tags, and loop state
input-dependent. The current proof shape therefore hardcodes the instruction
sequence as immediates and passes opcode/operand constants into C-authored
dispatch. Clang may constant-propagate those constants so the verifier sees a
smaller program, but correctness must come from the C helper semantics and the
fixed instruction stream, not from trusting an optimizer proof.
