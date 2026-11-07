# ARM full-system trusted transport controls

The incrementally built ARM kernel/module passed the existing portable trusted
transport control under full-system QEMU: guest status 0, QEMU exit 0. The test
checks immutable native ELF/entry/metadata, authoritative source/load attributes
and outer/inner map shapes, application proof/role rejection, stale/unrelated
result rejection and fail-closed disconnect. No submitted native payload is executed.
Exact kernel/module/helper/source hashes and console output are retained.

The retained v35 runtime root was mounted read-only over 9p. The canonical
repository mount supplied the new module/helper and one result path; no image
or root filesystem copy was built. The first bootstrap stopped on an already
mounted devtmpfs before reaching controls; its log is retained. Omitting that
redundant mount produced the passing result without recompiling the helper.

Reproduce against an existing ARM runtime root (collect/remove the previous
component result first):

    make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-transport-arm64-run TRANSPORT_ROOTFS=/workspaces/repository/kprog/arm64/build/app-runtime-v35/root

The helper is dependency-built incrementally; raw replay output stays in
kprog/arm64/build/trusted-transport. This is transport validation, not generated
Katran application admission or whole-ISA proof.
