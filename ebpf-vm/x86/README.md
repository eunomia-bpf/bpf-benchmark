# x86 eBPF VM Prototype

This prototype asks one small question: can an eBPF program interpret a compact
x86-like instruction stream and pass the normal eBPF verifier?

Hard rule: the proof program must not use a runtime check, trap, fallback,
synthetic bound, or verifier-only assertion to make native execution safe. If a
native path is not modeled exactly, the artifact must fail before native
execution, or a proof must show that the path is unreachable.

The initial smoke case mirrors `micro/programs/simple.bpf.c`:

```c
*out = 12345678ULL;
```

The hardcoded verifier artifact represents this x86-like instruction sequence:

```text
mov rax, 12345678
ret
```

The BPF program interprets the hardcoded instruction stream, writes `rax` to the
first eight packet bytes, and returns `XDP_PASS`. The loader runs it with
`BPF_PROG_TEST_RUN` and checks that the output value is `12345678`.

The instruction sequence is hardcoded in the `.bpf.c` file, while all VM
machinery lives in headers.

The specialized artifact is the more relevant ReverseJIT verification
direction. It uses a single include plus one macro-expanded interpreter call per
native instruction:

```c
#include "x86_vm_bpf.h"

SEC("xdp")
int x86_vm_hardcoded_xdp(struct xdp_md *ctx)
{
	return X86_VM_BEGIN_XDP(ctx)
	/* 0x0: mov rax, 12345678 */
	X86_VM_STEP_OP(X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0, 12345678ULL)
	/* 0x5: ret */
	X86_VM_STEP_OP(X86_OP_RET, 0, 0, 0, 0, 0)
	X86_VM_END_XDP();
}
```

The program is not a global variable, is not a local BPF stack array, and is not
emitted as a `.rodata` map. Each instruction field is a compile-time immediate.
The generator must only encode the native instruction as opcode/operand
constants; helper selection, packet-memory fast paths, and verifier-friendly
typed execution stay inside the C-authored interpreter/header. This is
intentionally not a JIT-shaped prototype: generated `.bpf.c` fixes the guest
instruction stream, but each step still executes VM semantics in
`x86_interp.h` / `x86_vm_bpf.h`.

Clang inlining and constant propagation are allowed as an engineering mechanism
for making the normal eBPF verifier accept the proof program. They are not the
correctness boundary. Correctness is stated over the C-authored interpreter
semantics: one encoded x86 instruction refines one x86 step. The compiler is
only used to specialize that same semantics for verifier analysis.

## Build And Run

```sh
make -C ebpf-vm/x86 run
```

This is a functional prototype, not a benchmark entrypoint.

If unprivileged BPF is disabled, build as the normal user and run the loader with
privilege:

```sh
make -C ebpf-vm/x86 build
sudo ebpf-vm/loader/target/debug/ebpf-vm-loader \
  --object ebpf-vm/x86/build/x86_vm_hardcoded.bpf.o \
  --program x86_vm_hardcoded_xdp \
  --case simple
```

Observed smoke result:

```text
case=simple retval=2 result=12345678 repeat=1 data_size_out=48
```

Object inspection for the hardcoded artifact:

```text
no .maps section
no .rodata section
xdp section size: 0xa0 bytes
```

The current interpreter has prototype coverage for integer register moves,
immediates, ALU ops, compares/tests, conditional branches, stack push/pop,
native direct calls lowered to BPF subprogram calls, conditional moves,
byte/word/dword/qword loads/stores, sign/zero extension, `bswap`, `popcnt`,
`xchg`, `div`, and double shifts. This is enough to exercise many generated
micro proofs, but it is not a complete x86 ISA model.

Register numbers follow the usual x86 encoding order: `rax=0`, `rcx=1`,
`rdx=2`, `rbx=3`, `rsp=4`, `rbp=5`, `rsi=6`, `rdi=7`, `r8=8`, ... `r15=15`.

## Micro Program Status

Current active track: generated-C interpreter proof path first. The JSON-linker
path is recorded below, but it is paused until generated-C coverage stays
stable.

Latest complete generated-C batch after removing benchmark-name special
renderers and moving loop/ABI capability protocol into C-authored helpers:

```sh
python3 ebpf-vm/x86/micro-prog/run_micro_interpreter_batch.py \
  --native-source object-no-jump-tables --no-build-loader
```

`run_micro_interpreter_batch.py` is the single active generated-C batch entry.
It records `compile_s` in the Python harness and parses loader-reported
`verify_s`/`test_s`, where `verify_s` is measured inside the Rust loader around
`bpf_object__load()` or raw `bpf_prog_load()`. It runs in parallel by default
with `--jobs min(8, ncpu)`; use `--jobs 1` only when a serial run is needed.
Unless `--markdown` is specified, each run writes a timestamped result file
under `ebpf-vm/x86/results/README-<timestamp>.md`; do not write status output to
`/tmp`.

The batch harness must not kill `clang` because compilation is slow. Clang
compile time is part of the experiment surface for large generated verifier
artifacts; a slow compile should be observed, not converted into a synthetic
compile-fail timeout.

Current observation: after removing Python helper selection, large generated-C
artifacts can make `clang -O2 -target bpf` significantly slower while it
specializes the C-authored interpreter dispatch. That is a real cost of the
cleaner proof boundary, not a reason for the harness to kill clang.
If this remains too expensive, the next design change must still keep helper
selection out of Python; it should use C-authored templates/macros or a smaller
interpreter state shape.

### Micro Compile And Verify Matrix

Latest safety-first generated-C run is 29/29:
[`results/README-20260518-201933.md`](./results/README-20260518-201933.md).
This run keeps the previous proof-only branch assertions and `last_cmp_*`
metadata deleted. The remaining SKB and checksum fixes are C-authored x86/ABI
semantics: `ctx+0x70` carries a `PACKET_LEN` ghost tag that proves
`data + skb_len == data_end`, and same-register `xchg` is treated as the real
x86 no-op it is. They are not branch assertions, synthetic bounds checks, or
Python renderers.

`current` is the active C-dispatch path (`generate_micro_proofs.py` +
`x86_vm_bpf.h`). `helper-selection` is historical baseline data from the
restored backup path (`generate_micro_proofs_helper_selection.py` +
`x86_vm_bpf_helper_selection.h`); the separate compile-cost measurement script
has been removed so new runs use only `run_micro_interpreter_batch.py`. The
historical helper-selection numbers remain in the table only as compile-cost
evidence.

| Micro program | Status | Current clang s | Current verify s | Current verify | Helper clang s | Helper verify s | Helper verify | Note |
| --- | --- | ---: | ---: | --- | ---: | ---: | --- | --- |
| `simple` | ok | 0.351 | 0.000 | ok | 0.202 | 0.013 | ok |  |
| `simple_packet` | ok | 0.433 | 0.000 | ok | 0.184 | 0.015 | ok |  |
| `bitmap_popcount_scan` | ok | 1.360 | 0.001 | ok | 0.414 | 0.037 | ok |  |
| `sorted_rule_binary_search` | ok | 1.324 | 0.029 | ok | 0.581 | 0.187 | ok |  |
| `bcc_runqlat_log2_histogram_bucket` | ok | 5.440 | 0.095 | ok | 1.917 | 0.947 | ok |  |
| `trace_event_type_switch_dispatch` | ok | 2.842 | 0.076 | ok | 1.451 | 0.908 | ok |  |
| `packet_checksum_fold` | ok | 2.043 | 0.040 | ok | 0.381 | 0.523 | ok | Still passes after deleting branch assertions. |
| `payload_prefix_memcmp_scan` | ok | 6.961 | 0.001 | ok | 3.193 | 0.029 | ok |  |
| `packet_vlan_tcpopt_parser` | ok | 7.825 | 0.000 | ok | 3.257 | 0.019 | ok | Hidden packet-offset metadata stays verifier-visible. |
| `bpf_local_call_fanout_dispatch` | ok | 29.576 | 0.021 | ok | 1.748 | 2.542 | run-fail | C-owned call/frame semantics pass; slot7/slot8 pointer payloads model real stack spills. |
| `flow_5tuple_rss_hash` | ok | 11.715 | 0.000 | ok | 4.854 | 0.017 | ok |  |
| `katran_lb_consistent_hash_select` | ok | 45.789 | 0.001 | ok | 22.169 | 0.020 | ok |  |
| `cilium_policy_guard_tree_filter` | ok | 5.427 | 0.003 | ok | 3.178 | 0.046 | ok |  |
| `siphash_rotate64_mixer` | ok | 58.022 | 0.000 | ok | 24.311 | 0.016 | ok |  |
| `packet_record_bounds_window` | ok | 4.985 | 0.002 | ok | 1.347 | 0.037 | ok |  |
| `flow_record_field_scan` | ok | 6.442 | 0.001 | ok | 1.713 | 0.028 | ok |  |
| `packed_header_bitfield_decode` | ok | 23.092 | 0.002 | ok | 14.250 | 0.121 | ok |  |
| `bpftrace_string_search_prefix_scan` | ok | 4.657 | 0.135 | ok | 0.677 | 2.589 | run-fail | Passes via C/header state-shape fixes, not branch assertions. |
| `tracee_syscall_name_table_lookup` | ok | 4.673 | 0.016 | ok | 1.347 | 0.121 | ok |  |
| `tracee_http_method_prefix_detect` | ok | 4.521 | 0.002 | ok | 1.911 | 0.029 | ok |  |
| `cilium_socket_lb_service_select` | ok | 7.313 | 0.012 | ok | 2.584 | 0.159 | ok |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok | 8.265 | 0.007 | ok | 2.335 | 0.082 | ok |  |
| `tetragon_process_event_arg_filter` | ok | 27.778 | 0.106 | ok | 18.292 | 0.531 | ok |  |
| `otel_stack_frame_unwind_scan` | ok | 5.514 | 0.004 | ok | 2.424 | 0.047 | ok |  |
| `cilium_ct_nat_tuple_rewrite` | ok | 6.592 | 0.003 | ok | 3.420 | 0.077 | ok |  |
| `packet_toeplitz_rss_hash` | ok | 7.594 | 0.005 | ok | 2.290 | 0.052 | ok |  |
| `bpftrace_comm_key_fnv_hash` | ok | 38.966 | 0.003 | ok | 24.316 | 0.094 | ok |  |
| `tc_packet_checksum_fold` | ok | 3.190 | 0.039 | ok | 0.404 | 0.648 | ok | `PACKET_LEN` proves `data + skb_len == data_end`; `xchg ax,ax` is no-op. |
| `cgroup_skb_hash_chain` | ok | 3.241 | 0.001 | ok | 0.923 | 0.026 | ok | `PACKET_LEN` proves SKB end pointer without proof-only branch assertions. |

For verifier diagnostics, capture the kernel verifier log through the loader:

```sh
sudo -n ebpf-vm/loader/target/debug/ebpf-vm-loader \
  --object ebpf-vm/x86/micro-prog/build/packet_checksum_fold.bpf.o \
  --program packet_checksum_fold_x86_vm_xdp \
  --case packet_checksum_fold \
  --load-only \
  --verifier-log ebpf-vm/x86/results/packet_checksum_fold.verifier.log
```

### Direct BPF Control For Verifier-Complexity Cases

These controls check whether verifier failures come from the original micro
programs or from the x86-VM proof shape. The original `micro/programs/*.bpf.c`
objects were compiled and loaded with the same loader, same generated inputs,
same expected result, and same program-type retval on 2026-05-18. The direct eBPF
programs pass verifier and `BPF_PROG_TEST_RUN`.

These rows compare direct eBPF against x86-VM proof shape. Both x86-VM rows now
pass in the active safety-first path without restoring proof-only branch
assertions. The x86-VM proof is still larger and more verifier-expensive than
direct eBPF, but the failures are no longer active blockers.

| Micro program | Direct eBPF result | Direct load/test s | Direct static BPF insns | Direct verifier processed / total / peak / max-state | x86 VM result | x86 VM verify s | x86 VM static BPF insns | x86 VM verifier processed / total / peak / max-state | Reason |
| --- | --- | ---: | ---: | --- | --- | ---: | ---: | --- | --- |
| `bpf_local_call_fanout_dispatch` | ok | 0.03 | 528 | `9572 / 120 / 70 / 10` | ok | 0.055 | 10985 | `22584 / 1430 / 583 / 8` | Native 16-record loop dispatches into four local-call targets. The active C-owned call/frame model greatly increases static BPF size, but the verifier can analyze the resulting shape. |
| `bpftrace_string_search_prefix_scan` | ok | 0.07 | 200 | `21394 / 546 / 143 / 47` | ok | 0.396 | 148 | `326956 / 7055 / 108 / 5` | The current pass uses C/header state-shape fixes and exact x86 flags, not branch assertions. It remains much more expensive than direct eBPF but stays below the verifier limit. |

Latest safety-first generated-C run: [`results/README-20260518-201933.md`](./results/README-20260518-201933.md).
The active path now passes 29/29 programs while keeping `last_cmp_*` and
`x86_vm_assert_*` deleted. The remaining verifier fixes moved into C-authored
ISA/ABI semantics: exact same-register `xchg` behavior, packet-end metadata
derived from SKB length, and helper shape changes that do not change native x86
semantics.

The backup `helper-selection` path had lower clang cost but still failed
`bpf_local_call_fanout_dispatch` and `bpftrace_string_search_prefix_scan` at
the verifier. The active C-owned path trades more C/header complexity for a
cleaner Python proof boundary and now fixes both cases.

Python LOC check for this cleanup and backup:

```text
generate_micro_proofs.py current:            737 lines
generate_micro_proofs_helper_selection.py: backup at 1503 lines
x86_vm_bpf.h latest:                       776 lines
x86_interp.h latest:                      2756 lines
x86_vm_bpf_helper_selection.h:           backup at 533 lines
```

The line movement is intentional: proof protocol complexity is being moved out
of Python and into the C-authored interpreter/header where it can be specified
and eventually verified with the helper semantics. The helper-selection backup is
kept only as historical compile-cost evidence for this experiment; new
generated-C timing runs use `run_micro_interpreter_batch.py`.

The immediate generated-C target is now cleaner but not complete. JSON-link
completion is a separate next experiment.

The formalization target for the generated-C path is
[`intepreter-spec.md`](./intepreter-spec.md). That spec is intentionally tied to
the current code: instruction helper steps, native branch/call/return lowering,
low-stack pointer payloads, and ABI output-store capability preservation are
named proof obligations rather than benchmark-specific fixes.

Active generator rule: Python must not rewrite native return semantics, branch
semantics, or opcode semantics. A native `ret` is emitted as
`X86_VM_X86_RET();`; one native instruction becomes one interpreter-helper step
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
metadata and `x86_vm_assert_*` branch helpers. Proof-only packet/output bounds
checks were removed from the active packet helpers. Stack-slot dispatch and
other remaining model checks are tracked in [`TODO.md`](./TODO.md): they cannot
be used as final safety arguments unless a proof shows they are unreachable or
exactly equivalent to the native x86 ABI/path condition.

Runtime trap rule: native x86 will not return `XDP_ABORTED` when the proof
interpreter would trap. The active top-level trap path is now fail-closed: a
reachable trap calls an invalid helper so load/verifier fails instead of
accepting a fallback-returning interpreter. Final acceptance still requires a
proof that all `X86_INTERP_TRAP` paths are unreachable for the accepted native
artifact, or rejection before native execution.

Generator complexity rule: the Python proof generator must stay below 800
lines. Its only semantic output should be a simple native stream such as
`label: insn` plus metadata needed to preserve labels, native operands,
expected retval/result, and input selection. Python must not own loop lowering,
call lowering, liveness, state-shape selection, helper selection, or
verifier-workaround logic. Those belong in C-authored interpreter/spec code
where they can be written once, specified, and eventually verified.

Compile-cost reduction rule: keep the Python side simple even when clang
compile time is high. Any attempt to reduce compile cost must happen inside the
C-authored interpreter/header/macro layer, for example by changing helper
structure, inline boundaries, macro shape, verifier-visible state layout, or
instruction semantics factoring. Do not move control-flow reconstruction,
helper selection, loop-shape analysis, state specialization, or benchmark
workarounds back into Python to make a hard case compile faster.

The aborted `__noinline -> __always_inline` plus `bpf_loop -> C for-loop`
experiment showed why this line matters: doing that transformation in
`generate_micro_proofs.py` only adds more Python-owned lowering logic. The
current generator shrink instead removed Python `bpf_loop` lowering and
internal call-return stack lowering outright. C now consumes the simple labeled
instruction stream through ISA-level branch/call/return macros
(`X86_VM_X86_JCC`, `X86_VM_X86_JMP`, `X86_VM_X86_CALL`,
`X86_VM_X86_RET`): branch macros lower native x86 control flow to C labels and
`goto`; call macros model the native return-address slot; generated callee frame
instructions execute as x86 instructions. There is no fuel guard or synthetic
trip bound in the active path because that is not x86 ISA semantics; verifier
rejection for a loop is recorded as a verifier result.

C state-layout changes in the active path:

- `X86_VM_EXEC` performs C-owned typed opcode dispatch; Python still emits only
  `X86_VM_RUN_OP(X86_OP_..., operands...)`.
- Stack slots keep value/tag state, while low stack slots `0..8` also carry real
  verifier pointer payloads (`p_stack0..p_stack8`). This models real x86 stack
  spills used by the current micro corpus, including `bpf_local_call_fanout_dispatch`
  spills through `[rbp-0x40]`. A reachable deeper pointer spill rejects load; it
  is not an accepted runtime safety check.
- Top-level packet memory loads use a verifier-proven raw-load fastpath for
  packet bases that already have verifier-visible range. Subfunction steps use
  the checked typed interpreter path so local-call proof state stays stable.
- Packet pointer arithmetic preserves concrete scalar register semantics and
  tracks packet offsets in hidden per-register metadata. Proven packet loads may
  recompute `data + offset + disp` for the verifier without changing the modeled
  x86 register value.
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
| Native return ABI lives in metadata/header, not Python rewrites | done | `ret` emits `X86_VM_X86_RET();`; runner checks `expected_retval` from YAML. |
| Remove benchmark-name renderers from Python | done | `generate_micro_proofs.py` no longer dispatches on `packet_checksum_fold`, `bpftrace_string_search_prefix_scan`, `bpf_local_call_fanout_dispatch`, or other benchmark names. |
| Remove stale C special templates | done | Unused checksum/string-scan C helper templates were deleted from `x86_vm_bpf.h`; the header now contains generic VM plumbing only. |
| Move proof protocol out of Python | done | Python pc-dispatch, ctx-store write-set insertion, `bpf_loop` lowering, internal call-return stack lowering, helper selection, and benchmark-name renderers were removed; remaining Python CFG work is mechanical label/branch emission. |
| C-owned loop/call protocol | done for current micro | `X86_VM_X86_JCC/JMP` lower native branches directly to C labels; `X86_VM_X86_CALL` models call stack adjustment; generated callee frame instructions execute through normal x86 helpers. |
| Shrink Python generator below 800 lines | done | `generate_micro_proofs.py` is 737 lines. |
| Run full safety-first generated-C batch | done | `results/README-20260518-201933.md`: 29/29 pass after deleting proof-only branch assertions. |
| Delete non-x86 loop fuel guard | done | Active branch macros no longer decrement `X86_VM_LOOP_FUEL`; backward edges use plain x86 branch semantics. |
| Move opcode dispatch specialization into C | done | `X86_VM_EXEC_TYPED` selects C helpers from constant `X86_OP_*`; Python does not choose helpers. |
| Stack pointer metadata | done for current micro | `x86_state` stores stack value/tag per slot and verifier pointer payloads for low slots `0..8`; deeper pointer spills must reject or be modeled before native execution. |
| Verifier-proven packet load fastpath | done | Top-level packet loads can rely on verifier-visible packet range instead of adding per-load bounds helpers. |
| Delete SKB length branch range hook | done | The proof-only `cmp [ctx+0x70], imm; ja target` range assertion was removed. |
| Model SKB packet end through ABI metadata | done | `ctx+0x70` loads carry `PACKET_LEN`; `PACKET_LEN + PACKET` becomes `PACKET_END`, matching `data + skb_len == data_end`. |
| Preserve same-register `xchg` semantics | done | `xchg ax, ax` is modeled as the real x86 no-op, so it does not clear packet pointer metadata. |
| Hidden packet-offset metadata | done | Packet-capable registers carry an offset field used only to make packet bounds visible to the verifier. |
| Delete branch-proof metadata | done | `last_cmp_*` state and `x86_vm_assert_*` helpers were removed from active C. |
| Remove packet/output runtime bounds checks | done | Active packet/output helpers no longer guard loads/stores with proof-only `data_end` checks. |
| Make top-level traps fail-closed | done | A reachable trap calls an invalid helper, forcing load rejection instead of returning `XDP_ABORTED`. |
| Split memory-domain helpers | done for current micro | Top-level packet loads have a raw verifier-proven path; subfunctions and stack/ctx accesses keep checked typed helpers. |
| Remaining generated-C verifier failures | done for current micro | Current safety-first full batch passes 29/29 without proof-only assertions/bounds checks. |
| Direct-native safety TODO | open | See [`TODO.md`](./TODO.md) for remaining stack, trap, metadata, ABI, rodata, flag, and call-return proof obligations. |

There are no active generated-C verifier/load failures in the current
safety-first micro corpus. Future work should keep reducing C/header size and
specifying helper contracts, not reintroduce benchmark renderers, branch
assertions, synthetic bounds checks, or loop-shape analysis in Python.

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
| Build reusable eBPF interpreter/helper bytecode | partial | C-authored `x86_tmpl_arg_*` template object is linked by the loader. |
| Batch runner uses JSON path as the pass/fail source | partial | It builds the C template object and runs JSON -> loader -> raw BPF load/test_run for non-call cases. |
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
| Delete Python BPF emitter | done | `reversejit_bpf_templates.py` removed. |
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
runtime opcode switch is attractive for a normal interpreter, but it makes the
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
2. A linked-path VM state that stores packet offsets/capabilities as scalars
   and recomputes `data + offset` inside each memory helper. This avoids saving
   real kernel pointers in VM state and is likely easier to formalize.

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

The JSON smoke status should be reproduced with:

```sh
python3 ebpf-vm/x86/micro-prog/run_micro_json_link_batch.py \
  --only simple simple_packet bitmap_popcount_scan \
  --native-source object-no-jump-tables
```

Do not use `--no-build-loader` when quoting JSON-link status; stale loader
binaries can otherwise make the table misleading. `ok` means JSON generation,
loader link, verifier load, test run, and expected-result check all passed.
The active completion target for now is the generated-C interpreter path below,
not the JSON linker.

## Interpreter Dispatch Boundary

The generator emits mechanical interpreter steps:

```c
X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, aux, imm);
```

Python does not choose `x86_exec_*` helpers. C macros dispatch to the
C-authored interpreter, and may use typed fast paths when opcode/operand
constants prove that the fast path is the same x86 step. This keeps the formal
object small: the proof obligation is the C interpreter/helper semantics, not a
Python helper-selection policy.

For the eventual bytecode-link path there will be no second user-space compiler
pass after program constants are attached. Any fast path that relies on
compile-time constants must therefore correspond to a C-authored template or
macro that the linker can splice unchanged, rather than Python rewriting
instruction semantics.

## JSON Bytecode Plan

This is a separate experimental path from the current generated `.bpf.c`
prototype. The core idea is to keep the interpreter semantics in C, but move
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
- x86 semantics live in a fixed template/interpreter library. Each template is
  the unit of proof: under the VM state relation, one template refines one x86
  small-step rule.
- Python may select templates for concrete x86 instructions and fill operands,
  but that selection must stay declarative and table-driven. It should not
  become a second large compiler hidden in the loader.
- Native direct execution is allowed only after a separate equivalence bridge
  proves that the native sequence and the verifier-facing BPF template sequence
  implement the same ABI, state layout, and memory/capability behavior.

This is why the interpreter/template path can be simpler than kinsn: the kernel
does not learn new instruction semantics, and the trusted kernel-side mechanism
can stay close to ordinary BPF loading. The complexity is concentrated in a
small set of reusable templates whose contracts can be proven once and reused
across micro programs.

The split is:

1. C owns the interpreter/helper semantics: guest register state, flags, memory
   capability checks, and opcode helpers such as `x86_exec_mov_load` and
   `x86_exec_alu_reg`.
2. Python parses native ASM and emits declarative JSON metadata: concrete x86
   instruction records, selected template IDs, operands, labels, branch targets,
   fixups, expected result metadata, and enough source annotation to audit each
   selection. Python must not emit verifier-facing BPF instructions.
3. A fixed C-authored or checked-in bytecode catalog owns the verifier-facing
   eBPF fragments for each template ID.
4. The loader concatenates fixed bytecode fragments, links them against the
   interpreter/helper bytecode, resolves local branch/call fixups, attaches
   metadata such as license/program type/name, and loads the finished BPF
   program.

The loader should stay a thin bytecode linker, ideally around 100-200 lines for
the splicing path. It must not decode x86, choose opcode semantics, run
constant propagation, optimize control flow, or silently rewrite verifier
semantics. Python also must not become a BPF emitter; semantic decisions belong
to the fixed template catalog where they can be tested and later formalized.

In this model, "helper link" means linking against verifier-visible BPF
subprograms or inlined bytecode blocks from the interpreter library. It does not
mean adding new kernel helpers. The final verifier input is still one ordinary
eBPF program assembled from fixed pieces.

A minimal JSON shape is enough:

```json
{
  "name": "simple",
  "prog_type": "xdp",
  "entry": "simple_x86_vm_xdp",
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
python3 ebpf-vm/x86/micro-prog/generate_micro_json_proofs.py
```

It writes artifacts to
`ebpf-vm/x86/micro-prog/build/json-proofs/`. The old
`generate_micro_proofs.py` path remains the C-source prototype path; it should
not grow JSON/linker responsibilities.

The trusted boundary for this experiment is intentionally narrow:

- C interpreter helpers define the verifier-facing semantics and are the units
  to prove against the x86 subset spec.
- Python/template generation is responsible for producing a concrete proof
  program for a concrete native instruction stream.
- The loader is a mechanical linker. Its correctness obligation is byte-level
  assembly, symbol resolution, and BPF load attributes, not x86 semantics.
- Native execution is accepted only if a separate translation-validation or
  formal equivalence check proves that the native artifact follows the same ABI,
  helper sequence, and hidden state layout as the eBPF proof artifact.

## Clang Optimization Check

The generated `simple` interpreter proof was compiled at multiple optimization
levels:

| Clang mode | Result |
| --- | --- |
| `-O0` | compile-fail: BPF stack limit exceeded, then clang exits with code 70 |
| `-O1` | ok: verifier load and `BPF_PROG_TEST_RUN` return `12345678` |
| `-O2` | ok: verifier load and `BPF_PROG_TEST_RUN` return `12345678` |

So “turn optimization off to make proof simpler” is not viable for this C
interpreter shape. Without optimization, clang keeps too much generic VM state on
the BPF stack. The practical C prototype still needs `-O1`/`-O2` for sane BPF
code shape. The active generator now passes fixed opcode operands into
C-authored dispatch; clang constant propagation is an engineering mechanism for
making that C shape verifier-friendly, not part of the correctness argument. The
restored direct-helper generator is retained only as historical compile-cost
baseline evidence recorded above.

## Current Design Constraints

This prototype has already exposed several verifier-facing design constraints:

- Hardcoding the guest instruction stream as C data is not enough. Large local
  arrays become BPF stack pressure, so generated proof sources use one immediate
  macro call per native instruction.
- Native packet addressing needs to support both positive and negative
  displacement. Any packet bound proof must come from native x86 guards or a
  proved equivalent state layout. Synthetic helper checks are not enough for
  direct native execution because native x86 will not execute them.
- Input-dependent interpreter loops are a state-explosion risk. The generator
  should still hardcode the instruction sequence, but it must stay mechanical:
  one native instruction becomes one helper step plus explicit native
  branch/return structure. Any future bounded-loop proof obligations need to
  live in interpreter/helper templates, not in Python semantic rewrites.
- Native stack state must be modeled explicitly for programs with `push`, `pop`,
  or `[rsp]` accesses. A generic pointer-tag path made the verifier explore
  impossible `rsp`-as-packet states, so RSP stack accesses now need dedicated
  stack fast paths.
- `bpf_local_call_fanout_dispatch` showed that dumping only the entry symbol is
  incomplete for native direct calls. The generator now rebuilds the native
  object and disassembles call-target symbols when the markdown `## Native ASM`
  block has unresolved call targets.
- `bpf_local_call_fanout_dispatch` no longer has a benchmark-name renderer and
  now passes verifier/test-run. The active fix is C-owned: typed opcode
  dispatch, native call stack adjustment, generated callee frame execution,
  low-stack pointer payload slots, and indexed packet-pointer promotion.
- `bpftrace_string_search_prefix_scan` no longer uses a C-authored
  benchmark-specific scan helper and still passes after deleting proof-only
  branch assertions. The fix stayed in C/header state shape and flag semantics,
  not in Python renderers or assertions.
- `packet_checksum_fold`, `tc_packet_checksum_fold`, and
  `cgroup_skb_hash_chain` pass after deleting proof-only branch assertions. The
  SKB cases use C-authored ABI metadata: a `ctx+0x70` load carries
  `PACKET_LEN`, and adding it to the packet data pointer yields `PACKET_END`.
  The TC checksum case also required exact `xchg ax, ax` no-op semantics so a
  native alignment NOP does not clear packet pointer metadata.
- `packet_vlan_tcpopt_parser` now passes because packet pointer arithmetic keeps
  concrete x86 register values separate from hidden packet-offset metadata. The
  verifier load path can prove `data + offset + disp` while the x86 state still
  observes the same scalar register value.
- The strict JSON-link loader is not the current source of truth. It has passed
  smoke programs (`simple`, `simple_packet`, `bitmap_popcount_scan`), but native
  call-flow support is missing and stale loader binaries previously produced
  misleading status if `--no-build-loader` was used.
- The object-native SKB path must model the ABI translation in C, not Python:
  `ctx+0xd0` maps to packet `data`, and `ctx+0x70` maps to packet length for
  the generated native `sk_buff` stand-in. This is now in `x86_interp.h`.
- `mov [mem], imm` packs the low 32 bits as the immediate and the high 32 bits
  as the displacement. Negative immediates must not sign-extend into the
  displacement field; the generator now masks both fields before packing.

Remaining places that are not yet a complete native x86 equivalence proof:

- Runtime `X86_INTERP_TRAP` paths are interpreter behavior. The top-level
  generated path now fails closed through an invalid helper if such a path
  remains reachable, but final direct native execution still requires
  load/translation-time rejection or a proof that each trap is unreachable.
- Packet/output helper `data_end` bounds checks have been removed from active
  packet helpers. Stack slot dispatch and other model checks remain proof
  obligations; they are not final safety guards.
- The `ctx`, SKB, packet, output, and rodata layouts are modeled ABIs, not
  arbitrary x86 memory. They must match the native execution layout exactly.
- The stack model is finite and uses sparse pointer payloads; it is not a full
  x86 stack model.
- Flag helpers cover the current micro subset, not all x86 flag behavior.
- Native call return-address contents are only valid for callees that do not
  inspect the return address.

For formal verification, clang optimization is not part of the trusted
argument. This C implementation is a prototype for finding the VM semantics and
verifier constraints. A cleaner proof story for the interpreter-only route is:

- Specify the guest x86 subset state: registers, flags, safe packet/stack/table
  memory capabilities, and termination behavior.
- Specify each opcode helper (`x86_exec_mov_load`, `x86_exec_alu_reg`, etc.) and
  prove that the eBPF helper body implements that relation.
- Generate only a fixed guest instruction stream, not replacement BPF semantics;
  the verifier proves memory safety of executing that fixed stream through the
  interpreter.
- Separately prove or translation-validate that the native execution artifact
  implements the same fixed guest x86 instruction stream and ABI contract.

The key constraint is that dynamic guest bytecode is hostile to the verifier:
accepting arbitrary input makes opcode dispatch, memory tags, and loop state
input-dependent. The current proof shape therefore hardcodes the instruction
sequence as immediates and passes opcode/operand constants into C-authored
dispatch. Clang may constant-propagate those constants so the verifier sees a
smaller program, but correctness must come from the C helper semantics and the
fixed instruction stream, not from trusting an optimizer proof.
