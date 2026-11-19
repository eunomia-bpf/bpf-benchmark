# Hash-map operation targets on the checked path

The installed BCC audit in `../checked-helper-binding-20261119/fixed.json`
has 17 generic update and 10 generic delete call sites. The original program's
maps are already reopened by real kernel ID, but translated instructions lack
the original process-FD/helper-ID facts used to populate map_ops.

Query both existing operation endpoints while each real hash-map FD is open.
Cache by kernel map ID and export the existing map_ops plan for all aliases.
The linker already selects the callback from the native RDI's proven map
identity. This applies to ordinary, per-CPU, LRU and LRU-per-CPU hash maps;
the sole kernel defines both callbacks at hashtab.c:2351/2373/2554/2576.
The verifier binds these same operations in do_misc_fixups (:23944-23948).
Other map types keep their current binding. No kernel/module/wire-format,
helper-body, compiler-flag, runtime-check or program-filter change.

Two real callers share the new helper: the loaded-program map loop and the
trusted map-binding loop (which also covers context-only map identities).
Repeated aliases query only once. Kernel query and I/O errors retain the
existing propagation. No translated map ID is used as a process FD.

Canonical loader build passes in the sole base under timing SH/image EX.
Raw log: `/workspaces/kprog-raw/perf/constant-alu32-20261119/hash-ops-loader-build-20261119T1200Z.log`.
The local Makefile runs existing linker regressions for reordered map arguments,
call forms, missing facts and exact names; it adds no mirrored switch test.
Actual callback targets, application stock/native coverage and per-call effects
remain for the functional check and later combined timing batch.

PERF 2026-11-19T12:02:02Z: Canonical loader build and both existing linker
regressions pass (one selected test each, 46 unrelated tests filtered).
Raw host log is `hash-ops-host-20261119T1202Z.log` beside the build log above.
The implementation adds 16 source lines. It queries real per-map callbacks
once per kernel ID and feeds the existing plan; it does not copy helper
implementations or add a per-call dispatch. BCC functional coverage and actual
direct callback relocations are pending; no per-call gain is claimed.
