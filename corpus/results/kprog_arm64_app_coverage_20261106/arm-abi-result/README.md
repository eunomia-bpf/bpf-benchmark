# AArch64 proof ABI mask cannot hide native register requirements

The kernel-mode producer previously trusted the proof ELF's four-bit saved
register mask. Clearing a required bit left the native bytes unchanged and
was accepted. The producer now derives a conservative mask over every included
body after entry stripping, before helper/tail cleanup is emitted. A declared
mask may include extra saves; missing required bits fail before upload.

Exact published baseline plus only this ARM patch was built in a private
source copy (foreign x86 WIP excluded).79 Rust tests pass.13 real-ELF controls
link, covering X/W19-22, pair loads, base writeback, exclusive status writes,
reachable callees and helper+callee.14 single-bit-cleared proof variants
link with the old baseline and reject with the fix; their .text is unchanged.
The earlier ROOT-source test also passed80 tests and is retained separately
in the log; it is not the source used for the final frozen evidence.

Full-system QEMU:8 positive controls (X19-22, stripped/preserved entry modes)
pass source/proof/bound-native with packet value37, retval2, one chunk and one
nonzero generation each.8 low-mask variants reject during native linking
before upload/execution. qemu-outcomes.json retains raw per-case observations.
The existing matched kernel/module is unchanged. Guest2GiB, CPUs12-15,
QEMU timings functional only. All prior failed runs remain on disk; the first
package attempt used a removed historical base path and never booted.

host-elf-inputs-and-producer-source.tar.gz contains exact baseline/fixed
Rust inputs, real ELF fixtures, mutation metadata and all commands/results.
qemu-inputs-and-runtime.tar.gz contains source/proof/native cases, frozen
simulator contracts, logs and a matching portable Image/initramfs/Makefile.
Extract it, then `make -C runtime run` (or ACCEL=kvm CPU=host on arm64).
Rebuild with native-link-check, arm-abi-cross-build, entry-abi-build
ENTRY_ABI_ARGS=callee-clobber, then fmov-bank-check, using the dated Makefile
and a retained BASE_INITRAMFS. The package's busybox/libs came from the earlier
divide-bound-v1 initramfs; kernel and module remained the paired-context-v2 set.

This closes the tested four-bit ARM metadata-understatement hole. It does not
claim all ABI/environment/ISA cases, a whole-program certificate, or six-app
completion. BCC's proof stack and exclusive retry failures remain open.

For the host before/after ELF replay, extract its archive and build
baseline-source/Cargo.toml with cargo build --release --target-dir
/workspaces/repository/kprog/arm64/build/abi-boundary-baseline/target.
Then run make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile
native-link-check native-link-build arm-abi-cross-build, followed by
arm-abi-boundary-check PHASE=NEW_HOST_RESULT. For a rebuilt guest, use
entry-abi-build PHASE=NEW_BOUND_RESULT ENTRY_ABI_ARGS=callee-clobber, then
fmov-bank-check PHASE=NEW_BOUND_RESULT BASE_INITRAMFS=ABSOLUTE_RUNTIME_INITRAMFS.
The portable archive supplies that initramfs and its matching kernel directly.
