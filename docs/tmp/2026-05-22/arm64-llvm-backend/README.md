# ARM64 LLVM Backend Notes

This directory contains the development and validation notes for adding an
ARM64 kinsn path to the LLVM BPF backend.

The implementation does not add a normal LLVM AArch64 backend. It extends the
existing LLVM BPF backend so selected BPF instruction sequences can be emitted
as `bpf_arm64_*` kfunc extern requests. The kernel-side ARM64 kinsn module then
decodes those requests and emits native ARM64 instructions.

Implemented families:

| Family | BPF pattern | Emitted externs |
|---|---|---|
| `REV` | byte-swap / endian-conversion idioms | `bpf_arm64_rev16_w`, `bpf_arm64_rev_w`, `bpf_arm64_rev_x` |
| `EXTR` | rotate idioms lowered from shift/or pairs | `bpf_arm64_extr_w`, `bpf_arm64_extr_x` |

Reports:

- `development-summary/report.md`: what changed in LLVM and the main repo.
- `correctness-and-regression/report.md`: LLVM checks, object-symbol checks,
  AWS correctness smoke, and target-isolation regression results.
- `performance/report.md`: ARM64 microbenchmark setup and current performance
  results.

The data files under each `data/` directory are copied from the local experiment
records and reduced to the parts needed to review the implementation. Full
session directories, JIT dump binaries, and transient AWS output directories are
not included here.

Known limitation: the userspace `llvmbpf` runtime path is not part of this
validation because it does not currently support objects that reference
`bpf_arm64_*` externs.

