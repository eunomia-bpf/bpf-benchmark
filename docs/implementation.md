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
  the condition table, the four-kind AArch64 compare-and-branch
  (CBZ/CBNZ/TBZ/TBNZ) predicate contract that completes the
  condition-to-next-PC relation, the four-column AArch64 move-wide
  (MOVK) insertion contract, the four-kind AArch64 shift
  (LSL/LSR/ASR/ROR) value contract shared with the decode table, the
  two-kind AArch64 byte-lane reduction (CNT/UADDLV) contract, the
  four-form AArch64 load/store address-offset contract, the four-direction
  AArch64 FMOV move contract, the four-width AArch64 little-endian
  byte-ladder load contract, and the eight-lane AArch64 byte-lane scatter
  contract (proved inverse to the load ladder).
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
  width/NZCV flag contract, decode tables, and bitfield/multiply/extract/
  reverse/extend/conditional-select/branch/move-wide/shift/reduction/
  address-offset/FMOV/load-bytes contracts, and pointer-add/ABI-load contracts
  are already shared. The `arm64_umulh`,
  `arm64_reverse_bytes`, `arm64_reverse_bytes16`, `arm64_width_mask`,
  `arm64_width_bits`, `arm64_sign_bit`, `arm64_sign_extend`,
  `arm64_bits_mask`, the `arm64_apply_width` indirection, the shift helpers
  (`arm64_lsl`/`arm64_lsr`/`arm64_asr`/`arm64_ror`/`arm64_ror32`/
  `arm64_ror64`) and the byte-lane helpers
  (`arm64_replicate_byte_popcounts`/`arm64_horizontal_add_u8`) were removed once
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
- `make corpus` now also completes a two-start load-time comparison where a real
  optimizer pass applies:
  `BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop,map_inline"
  SAMPLES=1 WORKLOAD_DURATION=10 JOBS=8 IMAGE_BUILD_JOBS=8
  VMLINUX_BTF="$(pwd)/vendor/build/x86/linux/vmlinux" make corpus` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_131646_375109/` with suite
  `status: "completed"`, app `status: "ok"`, and `map_inline` applying 16/16
  sites on the `balancer_ingres` XDP program. Raw `balancer_ingres` counters:
  168.98 ns/run baseline (4,437,801,179 ns / 26,261,979 runs) → 147.00 ns/run
  post-ReJIT (4,136,441,567 ns / 28,139,200 runs), ratio 0.870; pktgen thread
  throughput 2,632,791 → 2,819,605 pps, sum ratio 1.071. Single sample, one app,
  one pass: provenance plus a consistent direction, not paper-grade.
- The `VMLINUX_BTF` override is required in this workspace because the host
  kernel changed to `7.3.0-070300rc3-generic`, whose BTF has no
  `struct mm_struct::user_ns`; the regenerated x86 `vmlinux.h` therefore breaks
  upstream tetragon. The framework kernel BTF (`7.0.0-rc2+`) has it. Note the
  repo asymmetry worth a follow-up: `host-native-bpf-x86` passes no
  `VMLINUX_BTF` (defaults to the host BTF), while `host-native-bpf-arm64` passes
  the framework kernel's vmlinux; the native objects run under the framework
  kernel, so x86 should match arm64. `runner/mk/build.mk` is frozen, so the fix
  is not applied and the command-line override is used instead.
- With the default policy, `make corpus` previously aborted in the load-time
  shim because the `kop` pass could not run: `bpfopt` linked the system LLVM-18,
  which lacks the `-bpf-enable-kop-select`/`-bpf-kop-mode` options carried by
  the `llvm-backend/llvm` fork's `lib/Target/BPF/BPFKopSelect.cpp`. That
  prerequisite is now satisfied in this workspace: `ninja -C
  llvm-backend/build-bpf-kop -j12` completed the fork LLVM build (2116/2116,
  124 static libs, `libLLVMBPFCodeGen.a`, `lib/cmake/llvm/LLVMConfig.cmake`),
  and `cmake -S bpfopt/llvm -B <build> -DLLVM_DIR=<fork>/lib/cmake/llvm` builds
  a `bpfopt` that recognizes `-bpf-enable-kop-select` (the LLVM-18 build reports
  `Unknown command line argument`). `runner/mk/build.mk` already routes
  `BPFOPT_LLVM_BUILD_X86` to `bpfopt/llvm/build-kop` and honors
  `LLVM_DIR`/`RUN_LLVM_DIR`, so no repository change is needed; exercising the
  default corpus policy still requires rebuilding the runtime image with the
  fork-LLVM `bpfopt`. `bcc/set` and `cilium/agent` additionally fail at
  application startup (BCC `capable` skeleton load `-22`; Cilium XDP compile
  canceled); those remain raw failures.
- With the fork-LLVM `bpfopt` in the runtime image, the default `full-x86`
  prefix through `kop` now completes a two-start load-time comparison:
  `BPFREJIT_BENCH_PASSES=noop,map_inline,const_prop,dce,kop` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_172134_395628/` with suite
  `status: "completed"` and app `status: "ok"`. Applied sites: `noop: 3`,
  `map_inline: 16`, `const_prop: 1`, `dce: 1`, `kop: 71`. Raw
  `balancer_ingres`: 169.00 ns/run -> 146.01 ns/run (ratio 0.864); pktgen
  throughput 2,620,975 -> 2,799,206 pps (ratio 1.068). Single sample, one app:
  provenance plus a consistent direction, not paper-grade.
- The entire default `full-x86` group completes once `kop` is ordered after the
  LLVM-roundtrip passes:
  `BPFREJIT_BENCH_PASSES=noop,map_inline,const_prop,dce,wide_mem,
  bounds_check_merge,skb_load_bytes_spec,noop,const_prop,dce,kop` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_184607_120414/` with suite
  `status: "completed"` and app `status: "ok"`. Applied sites: `noop: 4`,
  `map_inline: 16`, `const_prop: 2`, `dce: 2`, `wide_mem: 1`,
  `bounds_check_merge: 1`, `skb_load_bytes_spec: 1`, `kop: 71`. Raw
  `balancer_ingres`: 175.79 -> 146.95 ns/run (ratio 0.836), `bytes_xlated`
  23,840 -> 19,016, `bytes_jited` 13,641 -> 11,545; pktgen throughput
  2,586,855 -> 2,838,183 pps (ratio 1.097). The original order in
  `corpus/config/benchmark_config.yaml` (`kop` before `wide_mem`) cannot work:
  the `kop` pass emits koperation payload pairs (a `BPF_MOV64_IMM` carrying the
  encoded payload followed by `BPF_CALL`), and every other LLVM-roundtrip pass
  feeds those words to the `llvmbpf` compiler, which misreads the payload word
  as `movsx` and fails (`Invalid offset -32623 for movsx at pc 7`, confirmed from
  the retained `KEEP_WORKDIRS=1` workdir). The `kop` pass itself bypasses the
  roundtrip for kop-bearing input; the pure-bytecode passes do not.
- The `full-x86` ordering fix is committed (`557a5af54`, `kop` moved after the
  LLVM-roundtrip passes), so the repository default policy now completes with no
  `BPFREJIT_BENCH_PASSES` override:
  `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_192529_199370/` with suite
  `status: "completed"` and app `status: "ok"` over all eleven passes. Raw
  `balancer_ingres`: 170.86 -> 148.00 ns/run (ratio 0.866); pktgen throughput
  2,626,908 -> 2,798,385 pps (ratio 1.065); `bytes_jited` 13,641 -> 11,545.
- The default policy across all six apps
  (`corpus/results/x86_kvm_corpus_20260916_214505_768159/`, `CORPUS_EXIT 0`)
  leaves two apps `status: "ok"`: `katran` (`balancer_ingres` 169.58 -> 146.87
  ns/run, `kop: 71` sites) and `bcc/set` (thirteen tracing programs, 342 applied
  sites total: `map_inline: 60`, `kop: 72`, `noop: 55`, `const_prop: 28`,
  `dce: 26`, `wide_mem: 13`, `bounds_check_merge: 13`,
  `skb_load_bytes_spec: 13`). The remaining four (`cilium/agent`,
  `otelcol-ebpf-profiler/profiling`, `tetragon/observer`, `tracee/monitor`) fail
  at their own application startup before the shim tracks programs; those are
  pre-existing app-startup failures, not measurement-validity gates.
- The katran `map_inline` step previously failed for a separate, fixable reason:
  `runner/config/passes/map_inline/katran.yaml` hardcoded an overlay directory
  under `/home/yunwei37/...` that does not exist here, so the step's `jq`
  overlay construction failed before `bpfopt` ran. It now resolves the path from
  the injected `BPFREJIT_REPO_ROOT`. The same stale prefix remains in the two
  non-default `const_mod_reduce*` policies (recorded as follow-up).
- Run one corpus invocation at a time; runs share
  `.cache/container-images/*.image.tar` and the framework kernel build. Under
  host memory pressure, pass `JOBS=8 IMAGE_BUILD_JOBS=8` to `make corpus` so the
  kernel `modules` build does not exhaust memory.

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
