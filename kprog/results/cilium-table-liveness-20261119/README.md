# Cilium table-result spill observations

PERF 2026-11-19T21:27:36Z. The original relative-table rejection is reproduced on
requests22,40,58. The first consumed code-address bits are RAX8..31 after
MOV AL,5 followed by a DWORD spill. The original register/flag liveness
analysis treats that store as an observation and rejects the lowering.

The committed `make memory` diagnostic uses the existing provisional CFG
solely to obtain dispatch edges and the existing ABI pointer analysis.
It emits no program and changes no production lowering. It inventories
stack accesses, follows all CFG branches from the rejected spill until the
first direct cell access, and asks the existing register-mask liveness
analysis about each readback's retained upper24bits.

| request | private spill offset from entry RSP | spill PC | first direct readback PC | readback register | upper24bits dead afterward |
|---|---:|---:|---:|---|---|
|22|-248|3735|8953 (0x22f9)|ESI|yes|
|40|-268|3693|9152 (0x23c0)|EDI|yes|
|58|-268|3697|9156 (0x23c4)|EDI|yes|

Each has one first direct readback, with no unresolved memory aliases on
that prefix in the provisional ABI inventory. Each prefix also has five
helper call sites: two map lookups, two map updates, and a tail call.
Their tracked stack pointer arguments start above the saved cell: request22
has roots-232,-208,-104 versus cell[-248,-244); requests40/58 have
roots-248,-224,-112 versus cell[-268,-264). These pointer roots alone are
not a proof about helper memory effects. Two unresolved aliases elsewhere
in each whole function remain in the full raw inventory; neither is on this
spill-to-first-access prefix.

This locates a path toward preserving observations without binding a physical
code base: prove the upper bits dead through the private spill, including
helper effects and every path, then extend the compiler's current liveness
analysis. The current compiler still rejects these requests. The existing
guard is unchanged; no code bits are zeroed or discarded by this diagnostic.
Future coverage must also examine any later table rejection after this first
one is resolved. No native, B, stock or runtime improvement is claimed.

Raw `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/prefix-20261119T212638Z`; log `/workspaces/kprog-raw/perf/cilium-table-liveness-20261119/prefix-20261119T212638Z.log`.
`memory-result.json` retains the focused facts. The initial whole-function
inventory remains at `memory-20261119T212500Z`, and the first readback version
at `readback-20261119T212700Z`, both under the same persistent raw directory.
Workers311804,312395,314409 are terminal; all raw data stays.
