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
  x86/AArch64 condition tables, x86/AArch64 ALU decode tables, logical/
  ADD/SUB/ADC/SBB/INC/DEC/NEG/NOT flag and result production, shift results
  and flags, register-lane AUX layout, register-destination immediate handler
  compositions for ADD/ADC/SUB/SBB/CMP/TEST/AND/OR/XOR/SHL/SHR/SAR/ROL,
  register-register AND/OR/XOR/SHL/SHR/SAR/ROL handler compositions, the
  carry-sensitive handler classification (SBB/ADC routing through generated C
  predicates), the AArch64 NZCV flag and decode-table contracts, the
  eight-operation AArch64 multiply-family value contract, the six-operation
  AArch64 extract/reverse/extend (EXTR/REV/REV16/SXTH/SXTW/SXTB) value
  contract, the eight-operation AArch64 conditional-select family
  (CSEL/CINC/CSET/CSETM/CINV/CSINV/CSINC/CSNEG) value contract composed with
  the condition table, and the four-kind AArch64 compare-and-branch
  (CBZ/CBNZ/TBZ/TBNZ) predicate contract that completes the
  condition-to-next-PC relation.
- The immediate-opcode handler composition pattern is: select the typed lane
  and raw immediate field, decode with the generated immediate contract,
  compute the generated result, write back the selected lane with tag
  scalarization, and take flags from the generated flag contract; each
  generated handler refines an independently stated spec.

### Current boundary and open work

- Open x86 proof surface: IMUL (immediate and register-register), memory
  lanes and stores, the objdump/parser-to-AUX selection relation, C-to-Lean
  unsigned-semantics correspondence, compiler/native-byte correspondence,
  multi-step control-flow traces, helpers, and specialization preservation.
- Open on the AArch64 side: the ALU op-step and register-lane handler
  compositions (in progress), the remaining load/store address and tag paths,
  the vector/`.D0`/`.Q0` paths, `MADD`/`MSUB`/`UMULH` flag consequences if any
  (the multiply family writes no NZCV, matching the absence of
  MADD/MSUB-with-flags opcodes), and the bridge from the proved branch
  predicates to the generator's actual `goto`/label emission. Both halves of the
  condition-to-next-PC relation (flag-based `arm64_conditional_branch_refines`
  and compare-and-branch `arm64_branch_next_pc_refines`) are now proved against
  independent statements over the emitted domain. The AArch64 condition table,
  width/NZCV flag contract, decode tables, and
  bitfield/multiply/extract/reverse/extend/conditional-select/branch contracts,
  and pointer-add/ABI-load contracts are already shared. The `arm64_umulh`,
  `arm64_reverse_bytes`, `arm64_reverse_bytes16`, `arm64_width_mask`,
  `arm64_width_bits`, `arm64_sign_bit`, `arm64_sign_extend` and
  `arm64_bits_mask` helpers were removed once
  `native-sim/arm64/arm64_sim_local_bpf.h` delegated to the generated contracts.
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

### Runtime status (2026-09-15/16)

- The KVM runtime path is operational in this Workspace: writable `/dev/kvm`,
  running `dockerd`, `virtme-ng` 1.41, `qemu-system-{x86_64,aarch64}`, the
  framework x86 `bzImage`, and both runner image tars. `make micro BENCH="simple"
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` passes (result `12345678` on the native/
  kernel/llvmbpf runtimes; `micro/results/x86_kvm_micro_20260915_194201_705027/`).
- `make corpus` completes a full two-start load-time comparison with a policy
  that avoids the currently failing optimizer passes:
  `BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop" SAMPLES=1
  WORKLOAD_DURATION=10 make corpus` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_031856_977978/` with suite
  `status: "completed"` and app `status: "ok"`. Baseline and post-ReJIT both ran
  the upstream Katran under KVM with a 10-second pktgen workload (raw thread pps
  858–879k baseline, 876–887k post). Single sample, one app, one pass: provenance,
  not a paper-grade speedup.
- With the default policy, `make corpus` currently aborts in the load-time shim
  because optimizer passes fail on this tree: `kop` fails even on a trivial
  2-instruction program, and `map_inline` fails on `balancer_ingres`. The shim
  reports the step failure and the app aborts, so no post-ReJIT workload is
  produced. `bcc/set` and `cilium/agent` additionally fail at application
  startup (BCC `capable` skeleton load `-22`; Cilium XDP compile canceled).
  These are x86 pass-policy/app-startup issues, unrelated to the AArch64 proof
  line, and are kept as raw failures. Run one corpus invocation at a time; runs
  share `.cache/container-images/*.image.tar`.

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
