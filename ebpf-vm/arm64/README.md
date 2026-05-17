# arm64 eBPF VM Prototype

This directory is reserved for the arm64 version of the eBPF VM prototype.

The intended shape mirrors `../x86`:

- a verifier-facing BPF interpreter for a compact arm64-like instruction stream;
- a Rust loader that supplies benchmark input through `BPF_PROG_TEST_RUN`;
- smoke cases derived from the simplest `micro/programs` benchmarks.

The x86 prototype is implemented first because the current ReverseJIT/k-insn
discussion and micro handcraft path are x86-centered.
