# Actual Katran root program on the bound ARM path

The unchanged upstream xdp_root source uses its actual three-slot PROG_ARRAY,
root_array. The simulator retains that exact map declaration; normalized
include paths select the standard kernel/helper declarations. Its opaque
context passes unchanged to tail_call, using RAW entry with the actual XDP
program section. The first packet-mirror attempt correctly rejected R1fp
instead of ctx; its complete raw logs remain.

Actual source, simulator and generation-bound native QEMU execution pass:
packet result0, XDP_PASS return2, generation1. The original empty program-array
control exercises all three failed tail calls; a populated-array/application
workload is tested separately through real Katran startup. The exact selected
native proof is packaged alongside the native ELF. No other Katran manifest
entry is removed. No custom app loader is substituted; the root bootstrap is
the project's documented Katran exception, and the app run uses its existing
upstream startup path.

The archive contains unchanged original source, exact map prelude/native/proof/
simulator objects, frozen simulator headers and the matched built kernel/initrd.
Extract and run `make -C runtime run`; on DGX Spark add `ACCEL=kvm CPU=host`.
Rebuild via the dated Makefile's `katran-root-build PHASE=NEW_NAME`, followed by
`fmov-bank-check PHASE=NEW_NAME`. The separate runtimev8 Katran application run
has started with this installed triple; no full-app result is inferred here.
