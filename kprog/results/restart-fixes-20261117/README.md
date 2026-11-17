# Fixes made before the 2026-11-11 restart (audit detour-20261117T03Z)

e6808c073 restarted the shim, loader and linker from their 2026-05-29 source. commits.txt lists every commit from
2026-05-29 02:22 UTC to the restart that touched bpfopt/shim, kprog/libnativeloader or the native_link sources
(146 commits; 13 name a fix, a fallback or retention). The coordinator checks each against the current tree;
the shim fallback (7734afc52) returned in c03737bf4.

## Verdicts, 2026-11-17 (omp)

Each of the 13 fix-class commits checked against the current tree. "Restored" means put back with a test that
fails on the pre-fix code; "recorded" means the fix is missing on a frozen path, so the line-adds are listed under
item 5 of `kprog/docs/todo.md` section 0 before any edit.

| Commit | Subject | Current tree | Where |
|---|---|---|---|
| cfa82fc7f | Tracee readonly identity and tail-call stack allocation | x86.rs half **restored** (`8273b93af`, test `tail_call_frame_counts_caller_saved_push_allocation`); loader half **absent** | `native_link/src/x86.rs` `plan_x86_entry_abi_strip`; `native_loader.cpp:2910-2977`, `native_loader_data_layout.hpp` |
| 8b36bf31f | Fix the kernel-symbol scan dominating native load time | **regressed** | `native_loader.cpp:1418-1483` |
| 13c6725a9 | (same class) gate the scan on need | **absent** | `native_loader_link_schema.hpp:71,72,84,100,131`, `native_loader_link_plan.hpp:134` |
| 56965bf5b | preserve verifier log segments | **regressed** (8192-byte tail only) | `native_loader.cpp:1163-1171` |
| e189b3a87 | retain complete verifier diagnostics | **regressed** | same |
| 3d0e584b5 | Retain kernel-owned PROG_ARRAY identities in tail-call linking | **absent, superseded** by `companion.has_tail_call` + `create_tail_call_marker_map` + `NATIVE_LAB_RELOC_X86_TAIL_COUNT` | `native_loader.cpp:1065,1073,2201,3060,3421,4023` |
| 9962aec5e | Keep unbound native runs measuring when one program fails | **half absent**: load failure still logs then falls through to the `!result.replaced` return, but no `requires_bound_proof` / `fatal_reason` gate | `bpfopt/shim/shim_native_loader.h:310-328` |
| c52568758 | await trusted native loads, retain full BCC coverage | **half absent**: no `native_loads_inflight` / `native_bound_completed` in the RPC; the rwlock half survived separately as `1af32bdae` | `bpfopt/shim/libbpfrejit_shim.c:1166`, `shim_native_loader.h:5-10`; `runner/libs/rejit.py:314-360` |
| deeee301e | bind trusted maps to source resources | **half**: Python side present (`trusted_generation.py`, `trusted_service.py`); `original_map_ids` alias filter absent, replaced by per-symbol `map_addr_ids` lookup | `native_loader.cpp:2197-2214,3572-3602` |
| 9220b9b44 | Restore the published May29 map snapshot RPC | **present** (all 169 added lines) | `corpus/driver.py` |
| 7f70d5ca9 | Fix native Cilium data symbol layout | **half**: layout helper survives; `runner/libs/app_outcomes.py`, `runner/libs/bpf_evidence.py` absent (frozen `corpus/driver.py`); `b83eef4a6`'s skip-don't-fail is gone and the loader **fails again** | `native_loader.cpp:2957-2960` |
| 14df099f5 | arm64 finite helper target sets | **absent, N/A** for the timed x86 KVM path (`arm64_helper_*`, `Arm64HelperState` gone; `a64_*` helpers remain) | `native_link/src/main.rs` |
| f197f00a9 / a7c4192c2 | verifier proof dependencies, platform proofs | **absent**: `native_tv_capture.hpp`, `kinsn/module/include/native_lab_checked*.h`, `kprog/tv`; only the frozen `write_binary_file` shape differs | `native_loader.cpp:177-189` |
| 1508a2e58 | per-app table | **N/A**: `kprog/tv` gone, zero surviving lines | — |

The cost of the largest regression is measured: the linear scan of `/proc/kallsyms` (440 839 lines) against the
146-name list takes **457–473 ms** per app startup, against **286–292 ms** for 8b36bf31f's `unordered_set<string_view>`
+ `from_chars` version (both found the same 108 symbols; `/tmp/kscan`). That is ~170 ms of native load time per start,
paid once per app process.
