# ReverseSim x86

ReverseSim is the current name for the experiment: generate an eBPF proof
program that simulates native x86, let the kernel verifier analyze that proof
program, and use the result as evidence for executing the corresponding native
x86 sequence directly.

## Hard Rule

The simulator must model native execution. Correctness must not come from
verifier-only behavior:

- no runtime trap/abort/fallback return;
- no fuel guard or synthetic loop trip bound;
- no simulator-inserted packet/output/stack bounds check;
- no branch assertion derived from facts the hardware branch does not use;
- no benchmark-specific renderer or helper selection in Python;
- no old parallel implementation path kept as dead code.

If the verifier rejects the exact proof program, record that rejection. Do not
make the proof easier by changing x86 behavior.

## Active Files

| File | Role |
| --- | --- |
| `x86_sim_local_bpf.h` | The active C-authored x86 simulator. Architectural GPRs/flags are function-local variables; each x86 instruction macro expands to C semantics. |
| `x86_sim.h` | Shared ISA constants and pure arithmetic helpers only. It no longer contains `struct x86_state` or `x86_exec_*`. |
| `micro-prog/generate_micro_sim_proofs.py` | Mechanical generator: build native code through `native_lab/native_link`, disassemble the linked x86 blob, and emit one `X86_SIM_RUN_OP(...)` or native branch/call/ret macro per x86 instruction. |
| `micro-prog/run_micro_sim_batch.py` | Builds generated proof programs with `clang -O3`, loads them with `bpf_prog_test_run`, records compile time, verifier time, test time, proof BPF instruction count, and direct BPF instruction count from the latest micro result. |
| `simulator-spec.md` | The semantic contract for the active simulator path. |

Deleted old paths:

- `x86_sim_bpf.h`
- `micro-prog/generate_micro_json_sim_proofs.py`
- `micro-prog/run_micro_json_sim_link_batch.py`
- `template-catalog/spec.md`
- `TODO.md`

## Current Algorithm

1. Build the micro program native object.
2. Run the `native_lab/native_link` linker so the x86 bytes use the
   ReverseSim/kernel ABI shape.
3. Disassemble that linked x86 blob.
4. Emit a BPF C source where each native instruction remains a native
   instruction macro with the original assembly in a comment.
5. Compile with `clang -O3 -target bpf`.
6. Load and test-run the proof object with the ReverseSim loader.

The Python generator does not choose typed helpers and does not rewrite control
flow into a verifier workaround. Complexity belongs in the C simulator/spec.

## Semantics Notes

Architectural state is represented by local variables:

- `void *__x86_rax` ... `void *__x86_r15`;
- `__x86_cf`, `__x86_zf`, `__x86_sf`, `__x86_of`;
- byte-addressed modeled stack memory when the native program uses stack.

There is no per-register ghost pointer metadata. The old `__x86_p_*`,
`__x86_tag_*`, `__x86_off_*`, `X86_PTR_PACKET_LEN`, and packet-plus-length to
packet-end propagation were removed. A GPR is stored as the architectural x86
register value itself, using `void *` as the C representation so `mov`, `lea`,
packet pointers, ctx pointers, and stack pointers keep verifier-visible pointer
shape as long as the actual x86 operation is pointer-shaped. Integer
instructions still read the same register bits as `(__u64)(long)reg` when the
x86 semantics require integer arithmetic, flags, shifts, masks, or partial
register writes.

The entry ABI is represented by `X86_SIM_ENTRY_XDP(ctx)` /
`X86_SIM_ENTRY_SKB(ctx)`. These macros build a local guest ABI memory object and
set the ABI entry register to that object's address (`RDI = &abi`, modeled
`RSP = 0`). For XDP the object contains `data` at offset 0 and `data_end` at
offset 8. For skb programs the object contains the linked native ABI fields
currently used by the generated x86, including `len` and `data` at their linked
offsets. The current micro proof ABI initializes the skb `len` slot as
`ctx->data_end - ctx->data`; this is valid only for the current linear
micro/test_run skb inputs where the native `sk_buff->len` value equals the
linear packet span. It is not a general TC/cgroup skb rule for non-linear
packets. This replaces the earlier ctx-field special cases: `[rdi]`, `[rdi+8]`,
or `[rdi+0xd0]` are ordinary loads from guest ABI memory, not hidden register
tags or branch-dependent verifier facts.

Type tricks are allowed only as representation choices for the same x86 value.
Storing GPRs as `void *` is such a trick: it does not add data, does not change
flags or control flow, and does not prove packet bounds. It only lets clang
preserve pointer-shaped expressions until an actual x86 integer operation needs
the bits as an integer.

Only ABI-defined entry state is semantic. Other GPRs and flags are unspecified
at native function entry; the C simulator may initialize local variables to keep
the eBPF program well-formed, but accepted direct-native artifacts must not have
guest-visible behavior that depends on those initializer values.

The active code does not add runtime data-end checks. Packet/ctx accesses are
raw modeled memory operations. If the verifier cannot prove them safe from the
exact native control/data flow, the program fails to load. In particular,
mapping the micro skb `len` slot from `data_end - data` does not add a hidden
packet-end witness. The verifier still rejects proof programs whose native
control flow only compares against `data + len` when it cannot recognize that
expression as packet `data_end`.

## Known Semantic Boundary

Direct `call`/`ret` is represented by pushing a return address on modeled stack
memory and dispatching `ret` through generated labels. This is an explicit
accepted-subset premise for now: the native code must use compiler-generated
normal direct calls, and the callee must not modify the active return-address
slot as ordinary stack memory. This covers the current linked micro programs.
It does not cover arbitrary x86 that writes `[rsp]`, `[rbp+8]`, or another alias
of the return slot before `ret`; those programs require a PC-based dispatch
model before they can be claimed direct-native safe.

Fault-like x86 behavior is also not hidden by simulator checks. Raw invalid
loads/stores, stack OOB, division faults, and unsupported verifier pointer
arithmetic are allowed to surface as compiler/verifier/load failures.

## Issues And Attempts

| Issue | Attempted solution | Current status |
| --- | --- | --- |
| Userspace native runner used a fake skb layout with `data`/`data_end` at offsets 0/8, while linked native x86 reads real kernel offsets such as `sk_buff->len` at `0x70` and `sk_buff->data` at `0xd0`. This caused GPFs for skb native micro programs. | Keep the native x86/linker ABI unchanged and change only the userspace native runner's fake skb object to place fields at `kernel_offsets.h` offsets. | Fixed for the native runner. `make micro RUNTIMES=native SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` passes 29/29. |
| `__sk_buff.data_end` is not `skb->data + skb->len` in the kernel. Kernel BPF direct packet access uses the linear range `skb->data + skb_headlen(skb)`, saved in `struct bpf_skb_data_end`. | Document the real kernel target: direct-native proof must match verifier `data/data_end`, not assume general `skb->len == data_end - data`. | Recorded in this README and in `simulator-spec.md`. The kernel target is not a general linear-skb assumption; the linear equality is only a current micro/test_run input premise. |
| Runtime native/JIT ABI and eBPF ctx ABI are currently not registered to the same source for skb packet end. eBPF `ctx->data_end` is load-time rewritten to `skb->cb + offsetof(struct bpf_skb_data_end, data_end)`, and kernel runtime fills that slot before the BPF program runs. The current linked native x86 instead reads `sk_buff->len` and computes `data + len`. | Treat this as an ABI mismatch, not a verifier bug. The correct direct-native target is for native x86 to read the same runtime-prepared `bpf_skb_data_end.data_end` value, or for the linker/kernel ABI to expose an equivalent field with the same semantics. | Not fixed yet. Current proof experiment documents the mismatch; the temporary micro `len = data_end - data` initializer is not a general solution and does not make the skb proof programs pass verifier. |
| The proof ABI for skb programs initially read `ctx->len`, which does not give verifier-visible packet-end semantics and is not the same as BPF `data_end`. | Try initializing the proof guest ABI `len` slot as `ctx->data_end - ctx->data`, while leaving the native instruction stream unchanged. | Semantically acceptable only for current linear micro inputs, but it does not make the two skb proof programs pass verifier. The verifier still sees packet pointer plus scalar, not `PTR_TO_PACKET_END`. |
| `tc_packet_checksum_fold` and `cgroup_skb_hash_chain` compare packet accesses against `data + len`. | Do not add hidden packet-end metadata, branch assertions, or bounds checks. Record verifier rejection when the exact native proof cannot be accepted. | Still fail. Verifier rejects the later packet load because it does not canonicalize `data + (data_end - data)` back to packet `data_end`. |
| `payload_prefix_memcmp_scan` and `tetragon_process_event_arg_filter` contain exact x86 partial-register writes to registers that still have verifier pointer type. | Represent GPRs as `void *`/union values so pointer-shaped x86 operations keep typed shape, but keep partial-register semantics exact. | Still fail. The remaining failures are verifier expression limits: exact partial-register masking on a pointer-typed value is rejected. |
| Earlier proof attempts used ghost pointer metadata, packet length tags, branch assertions, fuel guards, fallback/trap paths, or benchmark-specific Python renderers. | Remove those mechanisms and move semantics into C-authored instruction macros. Python remains a mechanical one-native-instruction to one-macro generator. | Removed from the active path. If verifier rejects the exact proof, that is the result. |
| Direct BPF instruction counts were missing when the latest micro result was native-only and had no `jit_dumps/*xlated.bin`. | Make `run_micro_sim_batch.py` pick the latest micro result that actually contains xlated BPF dumps when `MICRO_RESULT_METADATA` is not set. | Fixed. Latest result table records both proof BPF insn count and direct BPF insn count. |

## Latest Results

Native runner check after restoring the real linked skb offsets in the userspace
fake skb object:

```bash
make micro RUNTIMES=native SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
```

Result file:

- `micro/results/x86_kvm_micro_20260519_163845_507317/metadata.json`
- 29/29 native micro programs ran successfully.

Full proof run after mapping the micro skb `len` ABI slot from
`ctx->data_end - ctx->data` and fixing direct BPF instruction counts to use the
latest micro result that contains `jit_dumps/*xlated.bin`:

```bash
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 8 \
  --markdown native-sim/x86/results/README-20260519-094100-linear-skb-len.md
```

Result file:

- `results/README-20260519-094100-linear-skb-len.md`
- 25/29 load and produce the expected result.
- Direct BPF instruction counts are recorded from
  `micro/results/x86_kvm_micro_20260519_163959_668431/details/jit_dumps`.
- Remaining failures are direct consequences of the no-hidden-proof rule:
  `payload_prefix_memcmp_scan` and `tetragon_process_event_arg_filter` hit
  verifier-prohibited partial-register bit operations on values that still have
  verifier pointer type; `tc_packet_checksum_fold` and
  `cgroup_skb_hash_chain` compare packet accesses against `data + len`, and the
  verifier does not treat `data + (data_end - data)` as packet `data_end`.

These are verifier/proof-expression failures after removing non-hardware
guards, not runtime simulator fallbacks.
