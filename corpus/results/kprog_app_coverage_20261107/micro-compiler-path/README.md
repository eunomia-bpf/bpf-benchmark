# Standard micro bootstrap provides its external compiler PATH

R actual182314_422946 registers the service and generates C for all29
pure micro inputs, then every request fails with FileNotFoundError: clang.
No compiler child starts, and no request reaches verifier acceptance. The
service is outside the application container, so an image's compiler does
not provide the VM service toolchain. This is separate from the previous
ET_DYN validation rejection and from the later26/29 admission outcomes.

The standard VM micro Make entrypoint now prepends the existing
/usr/lib/llvm-18/bin to the service's PATH, matching the compiler environment
already used by the successful C corpus/micro recipes. Native ELF bytes,
compiler flags, worker authorization and application proof-upload rejection
are unchanged. No image/kernel/module rebuild or new configuration is added.
Kernel-only Make expansion continues to omit the service entirely.

With PATH=/usr/bin:/bin, the actual production worker reproduces the missing
clang failure on the original kernel-copied simple ELF. Adding only that
existing tool directory generates and compiles the SAME input successfully.
Both Make expansions pass shell syntax checks. These host checks establish
compiler resolution and fresh compilation, not kernel acceptance. A standard
VM smoke without an outer custom PATH will be queued after the active12GiB
run, preserving the lane memory cap and its pinned worker inputs.

raw.tar.gz contains commands, exact input-generated sources/objects, before/
after stdout/stderr and source snapshots. T's published original29-request
archive is referenced with its hash in checks.json; it is not duplicated.
R can use the normal micro command with the current Makefile and existing
incremental artifacts. The external broker/compiler environment must be
refreshed even when the application image and loader binaries are current.
