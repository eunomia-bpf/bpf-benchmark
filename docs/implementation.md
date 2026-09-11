# Implementation state — BPF benchmark framework

This file is the current handoff pointer for the duty chain. The authoritative,
continuously updated research log is
[`docs/tmp/20260906-bpf-development-todo.md`](tmp/20260906-bpf-development-todo.md),
which supersedes stale execution boundaries without deleting them.

## Active line: kprog / native-sim semantic-refinement proof

The NativeBPF stock-kernel simulator line
(`native-sim/`, `native-sim/formal/`) is in its per-step semantic-refinement
phase, driven by the user instruction "做一步 commit push 一步" (each proven
increment is committed and pushed immediately). Current state:

- Both x86-64 and AArch64 implement and build the instruction subsets emitted
  by the 29 workload-derived micro kernels; x86-64 KVM and AArch64 full-system
  QEMU both pass the 29-case functional smoke (`make selftest`).
- `native-sim/formal` is a Lean 4 model checked with
  `make -C native-sim/formal check`. It machine-checks the generated
  JSON/C/Lean contracts: width narrowing, entry ABI loads, pointer add,
  x86/AArch64 condition tables, ALU decode, logical/ADD/SUB/ADC/SBB/INC/DEC/
  NEG/NOT flag and result production, shift results and flags, register-lane
  AUX layout, and the register-destination immediate handler compositions for
  ADD/ADC/SUB/SBB/CMP/TEST/AND/OR/XOR/SHL/SHR/SAR/ROL.
- The immediate-opcode handler composition pattern is: select the typed lane
  and raw immediate field, decode with the generated immediate contract,
  compute the generated result, write back the selected lane with tag
  scalarization, and take flags from the generated flag contract; each
  generated handler refines an independently stated spec.

### Current boundary and open work

- Open x86 proof surface: register-register AND/OR/XOR and shift handler
  compositions (immediate forms are now proven; the register-register path
  uses the same lane/flag contracts with a second lane read), IMUL, memory
  lanes and stores, the objdump/parser-to-AUX selection relation, C-to-Lean
  unsigned-semantics correspondence, compiler/native-byte correspondence,
  multi-step control-flow traces, helpers, and specialization preservation.
- Open on the AArch64 side: flag production and the register-lane handler
  compositions (the AArch64 condition table and pointer-add/ABI-load
  contracts are already shared).
- The generation binding (verifier-accepted proof + native bytes bound to one
  immutable load generation) and the functional smokes establish different
  properties from these refinement theorems; none of them claims
  complete native-byte semantic equivalence.

### Working rules for this line

- Each increment: shared JSON spec -> generated Lean + C -> Lean refine
  theorem against an independent spec -> full `make -C native-sim/formal
  check` -> (when C changed) `make -C native-sim/x86 micro-proofs-build`
  (negative artifact + 29 workload-derived artifacts) -> commit + push +
  record evidence in the research log.
- No new measurement-validity gates; no program filtering; keep all failures
  and raw results. Performance claims come only from public Make-backed runs
  (`make micro`, `make corpus`, `make selftest`).

## Speculative-optimization line (paper B)

The stock-kernel speculative-optimization experiment line and its retained
evidence (experiment 093, the corrected-protocol Tracee/BCC cross-check, the
single-pass breadth queue) are recorded in the same research log. Its
outstanding items are Make-backed KVM runs with `KEEP_WORKDIRS=1` artifact
capture and the Katran `map_inline` confirmation; the pass policy
(`runner/config/passes/`) may change freely, frozen workloads and benchmark
launchers may not.

## Toolchain note

The duty OMP binary is pinned at
`/workspaces/.agent-state/bpf-benchmark-supervisor/bin/omp` with model
`litellm/local-small` via the internal gateway
(`http://llm-gateway.llm-gateway.svc.cluster.local:4000/v1`). If OMP reports
"model not found" at startup, the gateway's `/v1/models` listing and
`$LITELLM_API_KEY` should be verified; a working previous session proves the
route was functional, so transient discovery failure does not mean the model
is gone.
