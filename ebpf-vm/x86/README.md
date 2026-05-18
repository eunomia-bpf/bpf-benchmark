# x86 eBPF VM Prototype

This prototype asks one small question: can an eBPF program interpret a compact
x86-like instruction stream and pass the normal eBPF verifier?

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
sudo -n python3 ebpf-vm/x86/micro-prog/run_micro_interpreter_batch.py \
  --native-source object-no-jump-tables --no-build-loader \
  --markdown /tmp/reversejit-current-micro-status-$(id -u).md
```

The batch harness must not kill `clang` because compilation is slow. Clang
compile time is part of the experiment surface for large generated verifier
artifacts; a slow compile should be observed, not converted into a synthetic
compile-fail timeout.

For failing objects, capture the kernel verifier log through the loader:

```sh
sudo -n ebpf-vm/loader/target/debug/ebpf-vm-loader \
  --object ebpf-vm/x86/micro-prog/build/bpf_local_call_fanout_dispatch.bpf.o \
  --program bpf_local_call_fanout_dispatch_x86_vm_xdp \
  --case bpf_local_call_fanout_dispatch \
  --load-only \
  --verifier-log /tmp/bpf_local_call_fanout_dispatch.verifier.log
```

Result: 27 of 29 selected micro programs loaded in the kernel, passed
`BPF_PROG_TEST_RUN`, and matched expected output/retval. The remaining two
failures are verifier/proof-shape issues after removing Python special
renderers, not benchmark-name dispatch in the generator.

Python LOC check for this cleanup:

```text
generate_micro_proofs.py: 1763 -> 1421 lines
x86_vm_bpf.h:           202 -> 522 lines
```

The line movement is intentional: proof protocol complexity is being moved out
of Python and into the C-authored interpreter/header where it can be specified
and eventually verified with the helper semantics.

| Micro program | Status | Note |
| --- | --- | --- |
| `simple` | ok |  |
| `simple_packet` | ok |  |
| `bitmap_popcount_scan` | ok |  |
| `sorted_rule_binary_search` | ok |  |
| `bcc_runqlat_log2_histogram_bucket` | ok |  |
| `trace_event_type_switch_dispatch` | ok |  |
| `packet_checksum_fold` | ok | XDP return value is `2`; exact-bound loop back-edges now use verifier-visible callback index fallback instead of aborting at bound exhaustion. |
| `payload_prefix_memcmp_scan` | ok |  |
| `packet_vlan_tcpopt_parser` | ok |  |
| `bpf_local_call_fanout_dispatch` | fail | Verifier `E2BIG`: `Processed 1000001 insn`, limit `1000000`, `max_states_per_insn 33`, `total_states 30881`; log: `/tmp/bpf_local_call_fanout_dispatch.verifier.log`. |
| `flow_5tuple_rss_hash` | ok |  |
| `katran_lb_consistent_hash_select` | ok |  |
| `cilium_policy_guard_tree_filter` | ok |  |
| `siphash_rotate64_mixer` | ok |  |
| `packet_record_bounds_window` | ok |  |
| `flow_record_field_scan` | ok |  |
| `packed_header_bitfield_decode` | ok |  |
| `bpftrace_string_search_prefix_scan` | fail | Verifier `E2BIG`: `Processed 1000001 insn`, limit `1000000`, `max_states_per_insn 95`, `total_states 49270`; log: `/tmp/bpftrace_string_search_prefix_scan.verifier.log`. |
| `tracee_syscall_name_table_lookup` | ok |  |
| `tracee_http_method_prefix_detect` | ok |  |
| `cilium_socket_lb_service_select` | ok |  |
| `bcc_tcpconnect_ipv4_tuple_filter` | ok |  |
| `tetragon_process_event_arg_filter` | ok |  |
| `otel_stack_frame_unwind_scan` | ok |  |
| `cilium_ct_nat_tuple_rewrite` | ok |  |
| `packet_toeplitz_rss_hash` | ok |  |
| `bpftrace_comm_key_fnv_hash` | ok |  |
| `tc_packet_checksum_fold` | ok | Return value is `0` by TC ABI, as declared in `micro_pure_jit.yaml`. |
| `cgroup_skb_hash_chain` | ok | Return value is `1` by cgroup skb ABI, as declared in `micro_pure_jit.yaml`. |

The immediate generated-C target is now cleaner but not complete. JSON-link
completion is a separate next experiment.

The formalization target for the generated-C path is
[`intepreter-spec.md`](./intepreter-spec.md). That spec is intentionally tied to
the current code: instruction helper steps, exact-trip loop lowering, loop
frame preservation, and ABI output-store capability preservation are named
proof obligations rather than benchmark-specific fixes.

Active generator rule: Python must not rewrite native return semantics, branch
semantics, or opcode semantics. A native `ret` is emitted as
`X86_VM_RET_RAX();`; one native instruction becomes one interpreter-helper step
plus explicit native branch/return structure. Program-type return mapping lives
in `micro/config/micro_pure_jit.yaml` via `expected_retval`, and the runner
reuses that metadata for XDP (`2` default), TC (`0`), and cgroup skb (`1`).

Generated-C migration todo:

| Item | Status | Completion check |
| --- | --- | --- |
| Native return ABI lives in metadata/header, not Python rewrites | done | `ret` emits `X86_VM_RET_RAX();`; runner checks `expected_retval` from YAML. |
| Remove benchmark-name renderers from Python | done | `generate_micro_proofs.py` no longer dispatches on `packet_checksum_fold`, `bpftrace_string_search_prefix_scan`, `bpf_local_call_fanout_dispatch`, or other benchmark names. |
| Remove stale C special templates | done | Unused checksum/string-scan C helper templates were deleted from `x86_vm_bpf.h`; the header now contains generic VM plumbing only. |
| Move proof protocol out of Python | partial | Python pc-dispatch and ctx-store write-set insertion were removed; loop RDI restore, native-call loop marking, and ABI output-store preparation now live in `x86_vm_bpf.h`. |
| Generic loop lowering | partial | Structural loop detection lowers selected high-pressure loops to `bpf_loop`; two micro programs still need a cleaner C typed-helper/state-abstraction proof shape. |
| Run full generated-C batch | partial | 27/29 selected micro programs currently pass. |

Remaining generated-C failures:

| Micro program | Current blocker | Required proof-shape change |
| --- | --- | --- |
| `bpf_local_call_fanout_dispatch` | The callback joins states across generated native subfunctions (`local_call_*`) until the verifier hits `Processed 1000001 insn` (`max_states_per_insn 33`). | Reduce verifier-visible state joins while preserving one-instruction interpreter semantics; do not move helper selection into Python. |
| `bpftrace_string_search_prefix_scan` | Repeated prefix-compare memory/ALU steps hit `Processed 1000001 insn` with higher state fanout (`max_states_per_insn 95`). | Reduce pointer/flag state churn in C-authored interpreter helpers or loop state abstraction; do not replace it with a Python renderer. |

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
4. Treat any local abort/fuel bound/tail-inline shortcut as a proof obligation;
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
code shape, but the direct-helper generator no longer relies on compiler
constant propagation to select opcode semantics.

## Current Issues

This prototype has already exposed several verifier-facing design constraints:

- Hardcoding the guest instruction stream as C data is not enough. Large local
  arrays become BPF stack pressure, so generated proof sources use one immediate
  macro call per native instruction.
- Native packet addressing needs to support both positive and negative
  displacement. `x86_packet_bounds()` now allows negative displacement when the
  computed address remains inside the packet window; otherwise helpers like
  `movzx ecx, BYTE PTR [rdi-0xf]` trap incorrectly.
- Input-dependent interpreter loops are a state-explosion risk. The generator
  should still hardcode the instruction sequence, but it must stay mechanical:
  one native instruction becomes one helper step plus explicit native
  branch/return structure. Bounded-loop proof obligations need to live in
  interpreter/helper templates, not in Python semantic rewrites.
- Native stack state must be modeled explicitly for programs with `push`, `pop`,
  or `[rsp]` accesses. A generic pointer-tag path made the verifier explore
  impossible `rsp`-as-packet states, so RSP stack accesses now need dedicated
  stack fast paths.
- `bpf_local_call_fanout_dispatch` showed that dumping only the entry symbol is
  incomplete for native direct calls. The generator now rebuilds the native
  object and disassembles call-target symbols when the markdown `## Native ASM`
  block has unresolved call targets.
- `bpf_local_call_fanout_dispatch` no longer has a benchmark-name renderer.
  The active generator no longer uses Python pc-dispatch. Large generated native
  subfunctions still push the verifier past `E2BIG` (`Argument list too long`
  from libbpf), so the next fix must be a C-authored typed call summary or state
  abstraction.
- `bpftrace_string_search_prefix_scan` no longer uses a C-authored
  benchmark-specific scan helper. Repeated generic memory/ALU helper expansion
  still exceeds the verifier processed-insn limit, so the next fix must be a
  reusable C helper/template for the repeated byte-compare/or shape rather than
  another Python renderer.
- `packet_checksum_fold` and `tc_packet_checksum_fold` now use the same generic
  nested-loop lowering and both pass. The XDP variant needs the exact-trip
  callback-index theorem so exhausting the static trip count reaches the native
  exit path and returns XDP `2`. The TC variant additionally needs
  loop/program frame-preservation for the entry `rdi` context capability. That
  protocol now lives in `x86_vm_bpf.h`: loop callbacks track RDI writes in the C
  loop context, and ABI output stores call `x86_vm_prepare_ctx_output()` from
  `X86_VM_RUN_OP`.
- The strict JSON-link loader is not the current source of truth. It has passed
  smoke programs (`simple`, `simple_packet`, `bitmap_popcount_scan`), but native
  call-flow support is missing and stale loader binaries previously produced
  misleading status if `--no-build-loader` was used.

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
sequence as immediates and directly names the helper for each opcode. That keeps
the interpreter programming model without depending on a later compiler pass to
discover which opcode branch is reachable.
