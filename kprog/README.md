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

### Kernel-backed trusted specialization

The verified route submits native ELF bytes, entry and typed context/map metadata
through the kernel's `native_submit` endpoint. A bootstrap-owned service opens
`specializer` once, receives the kernel copy and queries its pinned source context
and map shapes. `trusted_service.py` validates the envelope, calls the ISA worker
and delegates fresh proof loading to `trusted-native-loader`; the loader completes
the request before closing its program FD. Applications receive the resulting
bound program through SUBMIT/WAIT. The service accepts no application proof, source
C, tool flags or filenames, and reads no application manifest.

Build/check the shared bridge with `make -C kprog/libnativeloader trusted-service-check`.
`trusted-worker-check` compiles actual BCC native entries without proof siblings;
`trusted-service-kvm` runs the real x86 kernel queue, generation, binding and native
execution control using the existing incremental TV kernel/module. The service CLI
requires its architecture, kernel endpoint, private state directory and trusted
native-link/loader executable paths. Start it before applications; disconnect
fails pending requests. Per-request compressed artifacts and errors are retained.
[Current evidence](../corpus/results/kprog_app_coverage_20261107/trusted-service/README.md)
distinguishes component acceptance from the pending six-application integration.

### Instruction-fidelity evidence snapshots

The November 7 results below identify their actual compiled source snapshots.
Each linked report includes per-form counts, source/binary hashes, commands and
complete mismatch streams. Counts describe the enumerated forms in that report.

| Snapshot | Forms / states | Reviewed comparison |
| --- | ---: | --- |
| [x86 CMP, header 4fe6817](results/kprog_fidelity_20261107/differential/x86-cmp-signed-current/README.md) | 1144 / 1,171,456 | Real CPU/C/canonical: zero differences, zero unavailable forms |
| [x86 RORX, header 47fb5565](results/kprog_fidelity_20261107/differential/x86-rorx-current/README.md) | 4 / 4096 | Real CPU/C/canonical: zero differences, zero unavailable forms |
| [ARM core, header c21833de](results/kprog_fidelity_20261107/differential/arm64-current-core/README.md) | 807 / 826,368 | QEMU/C/canonical: zero differences, zero unavailable forms; real ARM execution pending |

The focused RORX result checks the four existing register/memory forms at
32/64-bit widths and immediate 7. It does not relabel the older 1144-form CMP
snapshot as a full run of the newer RORX source. The earlier dated result
directories retain their original source attribution and failure history.

The [generic memory-load mechanism check](results/kprog_fidelity_20261107/differential/x86-load-width/README.md)
covers the BPF-only narrow-load casts separately: both source versions, 35 forms
and 286,720 inputs each, with zero differences between compiled BPF JIT,
host CPU loads and an independent byte oracle. This is supporting mechanism
evidence; kernel acceptance and the generic safety theorems remain separate.

The existing hardware-only script now defaults to the reviewed ARM core
static artifact above. The coordinator runs it on a real AArch64 host:

~~~sh
sh kprog/fidelity/run-arm64.sh
~~~

QEMU agreement is kept separate from real hardware evidence. These sampled
observations support O1. Safety must follow for every program from generic
per-operation refinement, per-token specialization and binding theorems, and
preservation of each native-link transformation, composed through
Composition.lean. The formal lanes develop these universal theorems;
historical program-specific proof files remain frozen in the archive.
