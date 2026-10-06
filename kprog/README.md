# kprog native simulator and loader

This directory holds the kprog native loader/linker, proof-producing
simulators, and formal contracts. Start with the current
[design](docs/design.md) and [evaluation](docs/evaluation.md).

The goal is deliberately narrow: use a real eBPF program as a verifier-facing simulator
for a native-like instruction stream, then execute it through
`BPF_PROG_TEST_RUN`. Current x86 proof artifacts hardcode the guest instruction
stream in the `.bpf.c` source so the verifier sees a fixed program, while packet
input supplies only the benchmark data.

Current layout:

- `loader/`: shared Rust loader that opens a BPF object and runs
  `BPF_PROG_TEST_RUN`. The planned next shape is to keep it as a very thin
  bytecode linker for JSON-generated proof artifacts, not a semantic optimizer:
  C supplies verifier-visible simulator/helper bytecode, Python emits concrete
  proof fragments, and the loader only links/fixes/loads them.
- `x86/`: simulator for the x86-64 instruction subset emitted by the current
  native micro and application kernels.
- `arm64/`: simulator for the AArch64 instruction subset emitted by the same
  workload-derived kernels. Neither directory implements the complete target
  ISA.
- `formal/`: a Lean 4 model and machine-checked refinement theorem for the
  shared register-transfer/tag-policy fragment. Its scope is intentionally
  smaller than either C simulator implementation.
- `libnativeloader/`: shared native loader and linker integration used by the
  benchmark paths.
- `test/`: workload-derived native and BPF test programs.

Build and smoke targets, plus the raw result locations, are listed in the
[kprog entry point](docs/README.md). The framework stores raw benchmark
results under `micro/results/` and `corpus/results/`.
