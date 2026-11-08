Existing kernel selftest sweep: ARM compiler and submission support

The existing selftests.py and submit.py now select AArch64 with --arch arm64. Native inputs use the corpus Armv8.1-LSE ABI flags, reserved registers and general registers; companion BPF objects use __TARGET_ARCH_arm64 and ARM system includes. The ARM output/include/vmlinux.h comes from the retained warm kernel BTF. Submission selects the existing ARM micro_exec, helper82 worker and native-link entry-resource binary. The x86 default compiler/submission commands retain their paths and flags.

The declaration scanner extracts the first argument of BPF_PROG/BPF_PROG2 and KPROBE-family function macros as the actual entry symbol. Population stays1917 annotated programs,657written in C. It resolves123 wrapper names to their declared program names. The original offsets, sections, annotations and body classification remain attached to those entries.

Actual existing verifier_mtu x86 compile before/after both exit0; both emitted objects have byte-identical allocated sections. ARM verifier_const and verifier_mtu cover all9 C entries: native compilation and symbol discovery succeed for9/9; companion-BPF outcomes remain in summary.json. These are compiler inputs to R existing sweep. R owns kernel submission and annotation agreement results.

The complete657-C ARM compiler cohort runs in the background using the same existing script; kprog/arm64/build/kernel-selftests-current/programs.json receives its terminal catalog. Source/hash/header, raw selected build outputs and the unchanged x86 comparison accompany inputs.tar.gz.
