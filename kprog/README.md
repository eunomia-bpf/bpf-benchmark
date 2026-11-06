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

### Readonly object identity at the proof/native boundary

Native-link kernel mode accepts `--output-data-layout PATH` and writes
`{"version":1,"objects":[{"native_symbol":"…","offset":0,"size":120}]}`.
Offsets address the final linked native blob; sizes describe complete objects,
without instruction relocation addends. Repeated references share one entry.
Distinct objects retain distinct identities even when their bytes are equal.
Proof mode carries canonical object keys in ELF symbols and rejects this
kernel-only output option.

Both proof generators emit one `.rodata.native.N` DATASEC/map per private
readonly object and a `.native_lab.rodata` JSON section (version1). Each record
contains `proof_section`, `proof_symbol`, `native_symbol` and `size`. The BTF
variable starts at offset0 and spans the map value. This metadata connects the
proof object to the canonical native object; byte searching cannot establish
that identity. See the dated application coverage results for the paired
x86/AArch64 relocation regressions.

Kernel-mode ARM linking also accepts `--output-environment-layout PATH`,
writing `{"version":1,"sites":[{"source_pc":16,"offset":20,"width":8,"release":true}]}`.
Each source proof byte PC maps to the exact final STXR/STLXR instruction after
helper expansion. Width/release are checked against that final word; source
PCs are unique/aligned and fit the signed32 marker payload. This ARM-only
sideband supplies instruction identity for bound environment witnesses and
does not alter native instructions. Proof mode rejects the sideband.
