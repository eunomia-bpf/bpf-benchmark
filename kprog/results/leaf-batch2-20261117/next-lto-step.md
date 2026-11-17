# Next LTO step after the batch-2 image snapshot

Source review, 2026-11-17T13:16Z, at `3ff2ac946`. No emitted candidate or
additional host build accompanies this note; the timed image remains sealed.

The demand-only part of todo item 3 already holds for direct probe-read
variants. `x86_probe_read.rs:344-355` creates a user/kernel, scalar/string
leaf only after finding a call relocation, and records its start in the
four-slot table. `:357-375` creates a compat dispatcher only when called,
reuses those leaves, and creates missing ones once. A dynamic compat source
can require both address domains even when the program never calls the
direct helper spelling. Removing one branch requires proven source-domain
facts; its absence from direct calls is insufficient evidence. Do not add
another eager/lazy selector around this existing mechanism. This does not
establish that every other LTO family emits only needed code.

For todo item 1c, the existing constant-register analysis is the useful
starting point. `x86.rs:1123-1125` currently computes memory constants before
helper provenance, while known-map propagation already consumes the latter's
resolved branch targets (`:1163-1165`). `x86_memory.rs:157-168` drops all
constant facts for a symbol containing an indirect branch. Its worklist
already merges equal facts and clears call-clobbered registers
(`:225-260`). Reusing the resolved code-table edges needs helper provenance
first and correctly mapped original instruction addresses. Unresolved
branches and genuine local calls still need their current conservative
semantics; do not guess a target or turn an unproven count into a constant.

Keep constant-size probe specialization separate from source-domain proof:
a known RDX size does not imply user or kernel source memory. Preserve
zero-size returns, signed size/result conversion, exact fault recovery,
zero-fill length, pagefault/SMAP cleanup and the compat address split.
Known size variants also consume installed bytes; count their actual
call sites and resulting shared bodies before proliferating them.

The adjacent compact-global opportunity remains fresh live loads in
`x86_probe_read.rs:153,171-173,228,236-238,295`. Use signed disp32 absolute
operands only when the full effective address fits, with the original wide
form otherwise. Do not use an address-size prefix that changes high-half
addressing or replace a live kernel variable with its load-time value.
Existing fixtures use wide synthetic addresses, so execution/encoding
coverage must retain wide addresses as well as the compact kernel case.

Next implementation validation belongs under timing SH on CPU 19, after
Omp's image snapshot. App per-call, body/helper/map attribution and installed
native/JIT totals remain the measurement, rather than these source savings.
