# Shipped linker PC32 support

2026-11-15T14:06:00Z: guest check passed. The sole image `af3f9d4e`
contains linker `dbac878459d6d87c5dcef36429e1233b626c351d14337bf6b635cedd8b369570`,
exactly matching the repository release binary. No further image rebuild is
needed to ship that linker for C's Katran run.

The actual image CLI generated both proof and kernel-linked output from a
Clang non-PIC fixture. Its PC32 `test_map` reference at offset 7 became a
full-width pointer patch at offset 6. Binding address 140444121986160 gave
101/202/303 for keys 0/1/2, and zero for 3/4/UINT32_MAX. This executes the
image-linked code in guest userspace with an allocated array; it does not
claim a kernel map, checked-native installation, equal-work app output or
performance result. Production `-fPIC` stays as restored by coordinator
6584e1127; the non-PIC fixture checks the linker's supported input form.

Source: 4de9a3227, staging fix 840fd2c2d. Make target `image-pc32` in
`kprog/test/native-relocations.mk`, launched through `run_verified_make.sh`
with image EX, host CPUs16–19, 16GiB address-space limit, guest2vCPU/4GiB on
CPUs16–17. Kernel build13/bdfa49b694e1, boot8cafa600, BTF27aeaae0;
no kernel/image rebuild or producer edits. Launcher1028802 completed0,
14:04:50–14:06:00Z. The release notice's 14:06:10 finish was a transcription
error; the raw `finished` file is authoritative.

Raw commands, logs and first failed launch remain under
`/workspaces/kprog-raw/perf/20261115-image-pc32`. First launcher1028665's
8GiB address-space limit failed before boot (`qemu_thread_create`), Make2;
the larger-bound retry passed. Temporary image tar/disk were removed after
both attempts; compiled fixture products replace the canonical
`/var/tmp/kprog-tmp/perf/native-relocations` outputs. No raw data was removed.
C was notified immediately after release to proceed with one A/A and one
A/B (three frozen180s samples each), per-call primary. This check adds no
application admission gate or timing requirement.
