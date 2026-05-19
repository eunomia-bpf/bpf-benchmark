# ReverseSim Prototypes

This directory holds proof-of-concept simulators for the ReverseSim research
direction.

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
- `x86/`: minimal x86-like simulator prototype and hardcoded/simple verifier artifact.
- `arm64/`: placeholder for the matching arm64 simulator shape.

This is not part of the benchmark framework and does not write benchmark result
payloads.
