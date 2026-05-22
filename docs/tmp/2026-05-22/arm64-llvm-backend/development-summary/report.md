# ARM64 LLVM Backend Development Summary

## Summary

This work adds the first ARM64 kinsn path to the LLVM BPF backend. The LLVM
backend now has an explicit kinsn target selector, ARM64 pseudo instructions for
`REV` and `EXTR`, AsmPrinter payload emission for `bpf_arm64_*` externs, and
selector logic for byte-swap and rotate idioms.

The main repository changes make those LLVM changes usable in the benchmark
environment. The build system can pass kinsn `llc` flags into micro object
generation, the runner container carries the runtime libraries needed by the
ARM64 runner build, and the ELF loader marks both `bpf_x86_*` and
`bpf_arm64_*` extern calls as kinsn calls.

## LLVM Submodule

Repository:

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm
```

Branch:

```text
codex/llvm-arm-backend
```

Pushed fork:

```text
https://github.com/zhengjieji/bpf-kinsn-llvm/tree/codex/llvm-arm-backend
```

Commits:

```text
cd4c34a61c92 bpf: add target selection for kinsn lowering
6f8bacbcd19b bpf: add ARM64 kinsn pseudos and payload emission
d30b7118fb94 bpf: select ARM64 REV and EXTR kinsns
```

Relevant files:

```text
llvm/lib/Target/BPF/BPF.h
llvm/lib/Target/BPF/BPFAsmPrinter.cpp
llvm/lib/Target/BPF/BPFISelLowering.cpp
llvm/lib/Target/BPF/BPFInstrInfo.td
llvm/lib/Target/BPF/BPFKinsnSelect.cpp
llvm/lib/Target/BPF/BPFMIPeephole.cpp
llvm/test/CodeGen/BPF/kinsn-arm64-extr-select.ll
llvm/test/CodeGen/BPF/kinsn-arm64-pseudos.mir
llvm/test/CodeGen/BPF/kinsn-arm64-rev-select.ll
llvm/test/CodeGen/BPF/kinsn-target.ll
```

The target selector is exposed through:

```text
-bpf-kinsn-target=x86
-bpf-kinsn-target=arm64
```

The default remains x86 to preserve existing behavior.

## Implemented Families

| Family | LLVM pseudo | Emitted extern | Selector input |
|---|---|---|---|
| `REV16` | `BPF_KINSN_ARM64_REV16_W` | `bpf_arm64_rev16_w` | 16-bit byte swap / endian conversion |
| `REV32` | `BPF_KINSN_ARM64_REV_W` | `bpf_arm64_rev_w` | 32-bit byte swap / endian conversion |
| `REV64` | `BPF_KINSN_ARM64_REV_X` | `bpf_arm64_rev_x` | 64-bit byte swap / endian conversion |
| `EXTR32` | `BPF_KINSN_ARM64_EXTR_W` | `bpf_arm64_extr_w` | 32-bit rotate idiom |
| `EXTR64` | `BPF_KINSN_ARM64_EXTR_X` | `bpf_arm64_extr_x` | 64-bit rotate idiom |

The `REV` payload records the destination/source BPF register. The pseudo ties
destination and source because the kernel-side decoder expects an in-place
operation.

The `EXTR` payload records destination, source, temporary register, and shift.
The temporary register is early-clobber and must not alias the source or
destination.

## Main Repository Support

Relevant files in `/home/ruoji/github/bpf-opt/code`:

```text
llvm-backend/llvm
micro/programs/Makefile
runner/CMakeLists.txt
runner/containers/runner-runtime.Dockerfile
runner/libs/suite_commands.py
runner/mk/build.mk
runner/src/elf_program_loader.cpp
runner/suites/test.py
tests/unittest/Makefile
vendor/Makefile
```

The main repository changes cover:

- forwarding `BPF_KINSN_LLC`, `BPF_KINSN_LLC_FLAGS`, `BPF_KINSN_TRIPLE`, and
  `BPF_KINSN_CPU` through Makefile-based micro object builds;
- rebuilding micro BPF objects when the selected compiler or kinsn flags change;
- cross-building ARM64 runner/runtime dependencies with the LLVM 17 sysroot;
- packaging runtime libraries needed by the ARM64 runner container;
- marking `bpf_arm64_*` extern relocations as `BPF_PSEUDO_KINSN_CALL`;
- allowing ARM64 test image builds to include unittest and negative-test
  artifacts.

Diffstat snapshots are in:

```text
data/llvm-commit-stats.txt
data/main-repo-support-diffstat.txt
```

## Remaining Work

The implemented ARM64 coverage is intentionally narrow. The next candidate
families are direct load/store, `UBFM`, `CSEL`, `CCMP`, `LDP/STP`, and `PRFM`.

The userspace `llvmbpf` runtime path still does not support objects with
`bpf_arm64_*` externs, so it is excluded from the current correctness and
performance validation.

