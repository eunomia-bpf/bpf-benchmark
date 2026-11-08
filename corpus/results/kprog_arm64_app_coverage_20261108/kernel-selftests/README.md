ARM native compilation of annotated upstream kernel BPF selftests

The existing R enumeration and __failure/__success markers use upstream source files. The architecture port selects AArch64, the current default native ABI/reserved registers, the retained ARM sysroot and vmlinux.h dumped from the vmlinux paired with the e2d3 QEMU Image. Raw compiler commands and outcomes, all enumerated programs, built native/BPF objects and exact source inputs accompany this result. The compilation phase precedes kernel submission and annotation comparison. R retains ownership of the shared submission harness.

Measured counts: {"asm": 1260, "c": 657, "entries_present": 0, "failure": 916, "files": 180, "files_compiled": 0, "programs": 1917, "success": 1001}.
