# eBPF VM Prototypes

This directory holds proof-of-concept interpreters for the ReverseJIT research
direction.

The goal is deliberately narrow: use a real eBPF program as a verifier-facing VM
for a native-like instruction stream, then execute it through `BPF_PROG_TEST_RUN`
with the instruction stream supplied as packet input.

Current layout:

- `x86/`: minimal x86-like VM prototype with a Rust loader.
- `arm64/`: placeholder for the matching arm64 VM shape.

This is not part of the benchmark framework and does not write benchmark result
payloads.
