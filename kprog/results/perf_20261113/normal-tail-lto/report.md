# Normal kernel-resolved tail-counter frame

2026-11-15T02:13:16Z. Source cc2a20e23 removes the tail-count opt-in and its unrelocated path. Every x86 kernel tail stub now emits kind10 for the physical counter-pointer displacement after final instruction/chunk layout. The target program entry offset remains a separate kernel fact. Proof helper semantics stay symbolic. The obsolete on/off TV invocation becomes one normal invocation; the frame-test wrapper still selects runtime map dispatch until that remaining selection is consolidated.

36 Rust tests pass, one existing ignored. The count removes three obsolete opt-in/off tests and adds one production ELF regression covering both immediate helper-ID and PLT calls. It checks the final relocation kind, target and byte offset, changes the displacement from -16 to -32, and confirms the target-entry add remains12. The saved/live-RBP stub regression also patches a different displacement. Existing GPR-memory execution, map dispatch, hash/LPM, fault-recovering reads and relative-table checks pass.

Raw `/workspaces/kprog-raw/perf/20261115-normal-tail-lto`; canonical linker build stays in the repository release target. No new guest, stock-kernel execution, checked installation, base/image/kernel publication or app timing. This completes only the tail-counter selector removal; remaining map/layout/helper selectors and their wrappers are next. All LTO pieces will be measured together.

2026-11-15T02:15:24Z: canonical release build completed successfully in place (build launcher763988 exit0,14.46s). SHA256 `5907ef565668ff72ce29e31712746ec5ebd6da2bd656761adfe9b06354d97d8d`. The installed base remains unchanged. Build command/log accompany this result.
