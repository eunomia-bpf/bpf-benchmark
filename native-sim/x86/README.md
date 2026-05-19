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

- `__x86_rax` ... `__x86_r15`;
- `__x86_cf`, `__x86_zf`, `__x86_sf`, `__x86_of`;
- byte-addressed modeled stack memory when the native program uses stack.

The simulator still carries ghost pointer metadata (`__x86_p_*`,
`__x86_tag_*`, `__x86_off_*`) so verifier pointer types can track the same
address value held in a native register. This metadata is not x86 architectural
state and must satisfy this invariant:

> If a register has a non-`NONE` tag, the corresponding scalar register value
> must equal the same address represented by the metadata.

The metadata may guide the eBPF load/store expression used for proof, but it
must not change the scalar x86 value, branch condition, flags, or memory value.
Any violation of this invariant would make direct native execution unsafe.

The active code does not add runtime data-end checks. Packet/ctx accesses are
raw modeled memory operations. If the verifier cannot prove them safe from the
exact native control/data flow plus ABI metadata, the program fails to load.

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

## Latest Results

Smoke after pruning the old path:

```bash
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py \
  --only simple bpf_local_call_fanout_dispatch packed_header_bitfield_decode \
  --jobs 3 \
  --markdown native-sim/x86/results/README-20260519-pruned-smoke.md
```

Result:

| Micro program | Status | Proof BPF insns | Direct BPF insns | Note |
| --- | --- | ---: | ---: | --- |
| `simple` | ok | 19 | 24 | load and test pass |
| `bpf_local_call_fanout_dispatch` | ok | 277 | 295 | local-call path now uses the same local-state simulator |
| `packed_header_bitfield_decode` | run-fail | 331 | 254 | verifier rejects pointer-as-integer shift; no guard was added |

Latest full pruned run:

- `results/README-20260519-pruned-full.md`
- 25/29 loaded and produced the expected result.
- Remaining verifier failures were:
  - `packet_vlan_tcpopt_parser`: verifier loses packet range through native aliasing;
  - `flow_5tuple_rss_hash`: same packet alias/range visibility issue;
  - `packed_header_bitfield_decode`: pointer value is later used as an integer for shifts/masks;
  - `cgroup_skb_hash_chain`: cgroup skb verifier rejects packet writes.

These are verifier/proof-expression failures after removing non-hardware
guards, not runtime simulator fallbacks.
