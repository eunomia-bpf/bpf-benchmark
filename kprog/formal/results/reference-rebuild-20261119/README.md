# Reference rebuild and shared ARRAY fragment repair

The coordinator reported `native path continues after fault` after linker
cleanup07d9c4c96 and requested a fresh Lean reference binary. Initial
`lake build ... reference` and explicit reconfiguration replayed native
objects: the executable remained dated November14, alongside generated C
updated November16. The executable and its87 `.c.o.export` dependencies
listed in its actual link response were removed with rebuildable sidecars.
`lake build @/reference` then genuinely recompiled them and linked the sole
reference executable in place: 184 jobs, exit0. Cleanup paths are recorded
in docs/cleanup-log.md and raw/stale-native-products-removed.txt.

The failure survived this rebuild. It was a fragment-harness defect:
`array.bin` contains the bounds routine at0x25, successful-path RET at0x34,
and null-path RET at0x37. The harness stopped both paths at0x37 and walked
the success path through RET without supplying its stack return-address
memory. The checked model correctly faulted, and its path evaluator correctly
rejected subsequent instructions. A stale date alone did not establish the
failure's cause.

Each branch now ends at its actual RET boundary, matching the existing stated
load/bounds-fragment observation. CALL/RET execution remains a separate control
obligation. Jump witnesses retain the actual decoded target. No native path
semantics, memory permission model or linker output was weakened or changed.

That repair exposed another stale expectation: the shared stride32/stride12
routines compute SHL/IMUL followed by LEA, which preserves their flags. The old
expectation assumed later ADDs. Existing hardware flag fixtures now also
execute the real shift-by5 and multiply-by12 operations; all defined bits
are compared. Existing conservative path masks for undefined bits remain.

The obsolete native_link/target/debug build was removed; the release build
and all raw fixture evidence remain. The checker uses that canonical release
native-link output and reports
the reference's stderr on failure. The array-only layout from07d9c4c96 is
retained. All90 ARRAY/PERCPU_ARRAY fragments pass: strides8/32/12, keys
0/1/15/16/17/0xffffffff, key faults, in-range percpu slot/CPU faults, full
state and ordered events. Four direct target bindings and two opaque-map
helper bindings also pass. No helper or wrapper execution is claimed.

Raw directory: /workspaces/kprog-raw/formal/m5-arm64-mov-keep-ordinary.
Attempts: map-reference1 failed with the old binary; map-reference2 failed
after genuine rebuild; map-reference3 isolated stride flags after fixing
RET boundaries; map-reference4 passes every case. reference-rebuild2 replayed
native artifacts; reference-rebuild3 genuinely rebuilt them. Every attempt
is retained. One worker, CPU17, timing SH,32GiB address space. The final full
Lake321 and all23 direct export comparisons pass as recorded in the adjacent
MOVK receipt. Full make check remains due at final M5/M6 goal closure.
