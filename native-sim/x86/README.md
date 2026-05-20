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
offset 8. For skb programs the object now mirrors the kernel/eBPF runtime ABI
used by the linked native micro code: BPF-visible `__sk_buff.cb[]` scratch
storage starts at `sk_buff->cb + offsetof(struct qdisc_skb_cb, data)`, the
BPF `data_end` value is loaded from `sk_buff->cb + offsetof(struct
bpf_skb_data_end, data_end)`, and packet `data` is loaded from
`sk_buff->data`. On the current x86 kernel those offsets are `0x30`, `0x50`,
and `0xd0`.

The simulator does not model `skb->len` as packet end. The previous
`len = ctx->data_end - ctx->data` experiment was removed because it was only a
linear test-input premise and did not match the kernel BPF ctx ABI. This
replaces the earlier ctx-field special cases: `[rdi+0x30]`, `[rdi+0x50]`, and
`[rdi+0xd0]` are ordinary loads/stores to guest ABI memory, not hidden register
tags or branch-dependent verifier facts.

For skb proof programs, `X86_SIM_X86_RET()` projects guest ABI `cb[0..1]` back
to the typed `struct __sk_buff` test-run output context. That projection is the
proof-side representation of the same kernel scratch storage that native x86
writes. It is not a fallback result path: the x86 return value remains `RAX`.
For `cgroup_skb`, that return value is only the kernel action
(`CGROUP_SKB_OK`/`CGROUP_SKB_DROP`); the 64-bit benchmark result must stay in
`__sk_buff.cb[]`. Packet writes are not a valid result channel for cgroup_skb
because the verifier rejects packet writes for that program type.

Shared benchmark logic should remain shared. Conditional compilation is limited
to the minimum ABI shim needed to expose the same kernel fields to native x86
and eBPF. The native and kernel builds must not maintain separate benchmark
algorithms or result semantics.

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
exact native control/data flow, the program fails to load.

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
| Userspace native runner used a fake skb layout with `data`/`data_end` at offsets 0/8, while linked native x86 reads real kernel offsets. This caused GPFs for skb native micro programs. | Keep benchmark logic shared and use a minimal native ABI shim that places fields at `kernel_offsets.h` offsets. | Fixed for the native runner. `make micro RUNTIMES=native SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` passes 29/29. |
| `__sk_buff.data_end` is not `skb->data + skb->len` in the kernel. Kernel BPF direct packet access uses the runtime-prepared `struct bpf_skb_data_end` slot in `skb->cb`. | Change the native micro skb helper to read `K_SK_BUFF_BPF_DATA_END_OFFSET`, so native x86 and eBPF proof both read the kernel BPF ABI value. | Fixed for the two skb micro programs. Generated native asm now loads `[rdi+0x50]`, not `skb->len`. |
| `__sk_buff.cb[0]` is not raw `sk_buff->cb[0]`; kernel ctx access maps it through `bpf_skb_cb(skb)`, which is `skb->cb + offsetof(struct qdisc_skb_cb, data)`. | Generate `K_SK_BUFF_BPF_CB_OFFSET` from BTF and write native skb benchmark results there. Kernel runner, proof loader, and native kernel runner read `ctx_out.cb[0..1]`. | Fixed. Current x86 offset is `0x30`. cgroup_skb no longer tries packet writes or return-value result encoding. |
| `cgroup_skb` return value is semantic action, not a benchmark result channel. | Keep expected retval as `CGROUP_SKB_OK`/`CGROUP_SKB_DROP`; carry the 64-bit benchmark result through BPF-visible `__sk_buff.cb[]`. | Fixed in native userspace runner, native kernel runner, and proof loader. |
| `payload_prefix_memcmp_scan` and `tetragon_process_event_arg_filter` contain exact x86 partial-register writes to registers that still have verifier pointer type (`mov sil/r8b` in payload, `mov dl` in tetragon). | Use minimal source shaping while keeping the simulator hardware-exact: widen only the payload pattern/temporary byte values to `u32`, and rewrite the tetragon event-weight table as the same integer expression so clang emits full 32-bit writes instead of low-byte writes. | Adopted as a source-code shaping experiment. The generated proof artifacts now load; runtime still shows a clear native-vs-kernel gap. Current full proof: `native-sim/x86/results/README-20260520-041226-full-proof.md`. Runtime: `native-sim/x86/results/README-20260520-041226-full-dataset-runtime.md`. |
| Same partial-register failure, simulator-only direction. | Tested a C-only lazy partial-register representation with per-register low 8/16-bit lane variables plus bool flags, materializing only on wider reads. | Rejected. It moved `payload_prefix_memcmp_scan` from failing at `mov sil,0x1d` to failing at the later exact `lea r10d,[rsi-0x1d]` materialization, and it made `tetragon_process_event_arg_filter` exceed the verifier stack limit. Results: `native-sim/x86/results/README-20260519-195148-partial-lazy-known-failures.md`. |
| Earlier proof attempts used ghost pointer metadata, packet length tags, branch assertions, fuel guards, fallback/trap paths, or benchmark-specific Python renderers. | Remove those mechanisms and move semantics into C-authored instruction macros. Python remains a mechanical one-native-instruction to one-macro generator. | Removed from the active path. If verifier rejects the exact proof, that is the result. |
| Direct BPF instruction counts were missing when the latest micro result was native-only and had no `jit_dumps/*xlated.bin`. | Make `run_micro_sim_batch.py` pick the latest micro result that actually contains xlated BPF dumps when `MICRO_RESULT_METADATA` is not set. | Fixed. Latest result table records both proof BPF insn count and direct BPF insn count. |

## Latest Results

Full native smoke after aligning skb `data_end` and result scratch slots with
the kernel BPF ABI:

```bash
make micro RUNTIMES=native SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
```

Result file:

- `micro/results/x86_kvm_micro_20260519_180639_651469/metadata.json`
- 29/29 native micro programs ran successfully.

Targeted skb native runner check after aligning native skb `data_end` and
result scratch slots with the kernel BPF ABI, and after moving benchmark-local
`MICRO_NATIVE` checks into the shared helper layer:

```bash
make micro BENCH="tc_packet_checksum_fold cgroup_skb_hash_chain" \
  RUNTIMES=native SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
```

Result file:

- `micro/results/x86_kvm_micro_20260519_181243_060895/metadata.json`
- `tc_packet_checksum_fold`: result `0`, retval `0`, native code `243`
  bytes, last sample compile `43087 ns`, exec `13358 ns`.
- `cgroup_skb_hash_chain`: result `12027228624407116210`, retval `1`,
  native code `272` bytes, last sample compile `51849 ns`, exec `411 ns`.

Targeted skb proof run after regenerating linked native asm with the same ABI:

```bash
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 2 \
  --only tc_packet_checksum_fold cgroup_skb_hash_chain \
  --markdown native-sim/x86/results/README-20260519-181500-skb-kernel-abi-min-cond.md
```

Result file:

- `native-sim/x86/results/README-20260519-181500-skb-kernel-abi-min-cond.md`
- `tc_packet_checksum_fold`: ok, proof BPF 118 insns, direct BPF 55 insns,
  verifier `0.333 s`.
- `cgroup_skb_hash_chain`: ok, proof BPF 236 insns, direct BPF 102 insns,
  verifier `0.006 s`.

Earlier broad source-shaping experiment:

```bash
make micro BENCH="payload_prefix_memcmp_scan tetragon_process_event_arg_filter" \
  RUNTIMES="native kernel native_lab" \
  SAMPLES=5 WARMUPS=1 INNER_REPEAT=100000
```

Result file:

- `native-sim/x86/results/README-20260519-runtime-retry-source-shape.md`
- How it was fixed temporarily:
  - `payload_prefix_memcmp_scan`: changed `memcmp_prefix_pattern_byte`,
    `observed`, and `expected` from `u8` to `u32`, so native x86 used
    32-bit writes like `mov esi,0x1d` instead of low-byte writes like
    `mov sil,0x1d`.
  - `tetragon_process_event_arg_filter`: inlined `tetragon_event_weight()` into
    the main loop, avoiding the small helper/code shape that produced
    `mov dl,0x1`.
- Decision at the time: do not keep the broad fix. It is useful evidence for
  why verifier rejects the exact low-byte form, but it changed benchmark
  source/native code and changed native-vs-kernel performance more than needed.

Current minimal source-shaping run:

```bash
make micro BENCH="payload_prefix_memcmp_scan tetragon_process_event_arg_filter" \
  RUNTIMES="native kernel native_lab" \
  SAMPLES=5 WARMUPS=1 INNER_REPEAT=100000
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 2 \
  --only payload_prefix_memcmp_scan tetragon_process_event_arg_filter \
  --markdown native-sim/x86/results/README-20260519-202449-source-minimal-proof.md
```

Result files:

- `micro/results/x86_kvm_micro_20260520_032422_672690/metadata.json`
- `native-sim/x86/results/README-20260519-202449-source-minimal-proof.md`
- `payload_prefix_memcmp_scan`: proof ok, proof BPF 344 insns, direct BPF 142
  insns; runtime native userspace `48 ns`, kernel eBPF `82.2 ns`, native kernel
  `51 ns`.
- `tetragon_process_event_arg_filter`: proof ok, proof BPF 290 insns, direct
  BPF 282 insns; runtime native userspace `104.2 ns`, kernel eBPF `154 ns`, native kernel
  `107.2 ns`.
- A smaller tetragon attempt that kept the `switch` and only widened
  `event_id` to `u32` still generated `mov dl,0x1` and failed verifier load,
  so the active source-shaping version uses the equivalent integer expression.

Current full dataset run with the accepted source-shaping state:

```bash
make micro RUNTIMES="native kernel" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000
MICRO_RESULT_METADATA=micro/results/x86_kvm_micro_20260520_041226_759303/metadata.json \
  python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 8 \
  --markdown native-sim/x86/results/README-20260520-041226-full-proof.md
```

Result files:

- `micro/results/x86_kvm_micro_20260520_041226_759303/metadata.json`
- `native-sim/x86/results/README-20260520-041226-full-proof.md`
- `native-sim/x86/results/README-20260520-041226-full-dataset-runtime.md`
- Runtime, all 29 programs: native userspace / kernel geomean `0.594`, native
  userspace speedup `1.68x`, `27` wins and `2` losses.
- Runtime, excluding `simple` and `simple_packet`: native userspace / kernel
  geomean `0.656`, native userspace speedup `1.53x`, `25` wins and `2` losses.
- Proof: 29/29 generated ReverseSim proof programs compile, load, pass
  verifier, and pass `BPF_PROG_TEST_RUN`. Direct BPF instruction counts are
  recorded from the same micro result's `xlated.bin` dumps.
- Compared with the previous full native userspace / kernel eBPF / LLVM-BPF run
  `micro/results/x86_kvm_micro_20260520_023753_401581/metadata.json`, the
  full-dataset native userspace speedup is essentially flat to slightly lower:
  `1.71x -> 1.68x` overall and `1.55x -> 1.53x` excluding baselines. The main
  regression is `payload_prefix_memcmp_scan`, where source shaping also made
  the kernel eBPF code faster.
- Compared with the older pre-local-simulator full run
  `micro/results/x86_kvm_micro_20260520_012923_324142/metadata.json`, the
  current result is the first useful full-dataset native userspace win:
  all-program native userspace speedup moved from `0.19x` to `1.68x`, and
  non-baseline speedup moved from `0.21x` to `1.53x`.

Native kernel result-channel fix for this full dataset:

```bash
make micro RUNTIMES="native kernel native_lab" \
  SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000
```

Earlier failed result file:

- `micro/results/x86_kvm_micro_20260520_040517_640313/metadata.json`
- This run completed native userspace / kernel eBPF / native kernel for 28
  programs but failed at raw runtime case `cgroup_skb_hash_chain/native_lab`
  warmup: result `0` instead of
  `12027228624407116210`.
- Root cause: native kernel was still reading TC/cgroup benchmark result bytes
  from the packet buffer. The kernel path and proof loader read BPF-visible
  `__sk_buff.cb[]`.
- Fix: `runner/src/native_lab_runner.cpp` now requests `ctx_out` for
  TC/cgroup and extracts the 64-bit benchmark result from `cb[0..1]`.

Fixed full native userspace / kernel eBPF / native kernel result:

- `micro/results/x86_kvm_micro_20260520_044439_120822/metadata.json`
- `native-sim/x86/results/README-20260520-044439-full-native-lab.md`
- 29/29 programs completed for native userspace (`native`), kernel eBPF
  (`kernel`), and native kernel (`native_lab`).
- All-program median geomean: native userspace / kernel `0.588` (`1.70x`
  speedup), native kernel / kernel `0.707` (`1.41x` speedup).
- Excluding `simple` and `simple_packet`: native userspace / kernel `0.649`
  (`1.54x`), native kernel / kernel `0.689` (`1.45x`).

Known old-source proof failures after regenerating the two exact proof
artifacts:

```bash
python3 native-sim/x86/micro-prog/generate_micro_sim_proofs.py \
  --only payload_prefix_memcmp_scan tetragon_process_event_arg_filter
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 2 \
  --only payload_prefix_memcmp_scan tetragon_process_event_arg_filter \
  --markdown native-sim/x86/results/README-20260519-old-source-known-failures.md
```

Result file:

- `native-sim/x86/results/README-20260519-old-source-known-failures.md`
- `payload_prefix_memcmp_scan`: run-fail, proof BPF 228 insns, direct BPF 139
  insns.
- `tetragon_process_event_arg_filter`: run-fail, proof BPF 301 insns, direct
  BPF 287 insns.
- Both failures are verifier/load failures on exact old-source native code, not
  simulator traps or fallback behavior.

Targeted runtime comparison across every runtime mode available in
`micro/config/micro_pure_jit.yaml`:

```bash
make micro BENCH="payload_prefix_memcmp_scan tetragon_process_event_arg_filter" \
  RUNTIMES="native llvmbpf kernel native_lab" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=100000
```

Result file:

- `micro/results/x86_kvm_micro_20260519_213344_357618/metadata.json`
- Detailed table: `native-sim/x86/results/README-20260519-runtime-compare-proof-passing.md`

The remaining whole-suite failures, when present in future experiments, should
be verifier/proof-expression failures after removing non-hardware guards, not
runtime simulator fallbacks.
