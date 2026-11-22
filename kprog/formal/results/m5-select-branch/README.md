# Actual selected CSEL pointer/tag calls

Arm64SelectBranch checks the exact exported statement128 and both original
source/temporary names. to_writer executes the taken or untaken branch in
66 internal transitions: caller entry4, actual pointer reader28, resume/call3,
actual tag reader28, then resume/writer call3. It reaches the genuine original
pointer-writer definition at linked block67, retaining the exact caller temp
map and continuation and the complete unchanged memory.

The selected raw value, all eight tag bits and their native materialization
come from the same existing complete register relation. Both choices, every
ordinary source, arbitrary destination bits, entry offset and memory are
covered. Vlong and Vptr representatives survive the real pointer ABI cast;
the unsigned tag argument goes through the true uint-to-uchar conversion.
There is no scalar-tag restriction, independently supplied reader result,
post-memory or external-provider assumption. Actual symbol/function binding
and source name non-shadowing are used at each real call site.

The 256-job focused build and two public type/axiom queries pass at original
200000-heartbeat/512-depth caps, CPU17, nice0, one worker and32GiB address space.
Initial monolithic call simplification hit the recursion cap; the corrected
proof factors actual calls through the imported relational call rule, keeping
the cap unchanged. Diagnostics remain at the raw path. Only standard logic
and inherited CompCert external/assembly relations appear.

Whole-library confirmation follows at batch end. This certifies reaching the
writer call, not executing it. Writer post-state, generic entry/dispatch/frame
free, original seventh source call, native CSEL composition and full handlers
remain open. M5/O1/O2/O4/M6 are incomplete; complete ISA-family count is zero.
Raw: /workspaces/kprog-raw/formal/m5-select-branch/20261122T105431Z.
