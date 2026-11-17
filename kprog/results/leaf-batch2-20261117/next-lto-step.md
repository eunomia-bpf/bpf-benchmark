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
a known RSI size does not imply user or kernel source memory. Probe-read's
SysV arguments are RDI destination, RSI size and RDX source; the memory
routine analysis originally consumes RDX as memcpy/memset length instead.
Use the correct register when reusing those general constant facts. Preserve
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

## Constant-size scalar reads without cloning policy bodies

Implementation direction, 2026-11-17, still unimplemented: first specialize
a shared scalar leaf only when every original call that reaches it has the
same known u32 RSI size. Include compat callers in both possible domains.
Keep one body for that domain; conflicting or unknown counts require the
current dynamic body. This avoids duplicating the full policy/SMAP/fault
cleanup for each size. Strings remain unchanged in this first step.

For a known scalar count, emit a counted qword loop and fixed 4/2/1 tail.
Zero words need no word loop; one word needs no loop counter. Larger
counts need a fixed-size loop with count N/8, not N/8 copies of its text.
Keep each protected load's status branch before its store and retain the
original full N for fault zeroing. Do not introduce a size refusal or an
unroll limit. Static code and executed-instruction effects need actual
host/app measurement; the old fully-unrolled model is not the code-size
decision for this implementation.

Carry the count with the helper branch patch through encoding. Inferring
it solely from `insn_local_ip` during final layout is insufficient:
`push_x86_synthetic` writes `u64::MAX` (`x86.rs:648`), including the
conditional helper-tail rewrite at `:1235-1239`. The ordinary and finite
numeric helper paths also need the same original-site fact. An optional
internal count on `HelperBranchRel32`, then a map keyed by its final
global slot offset at relocation construction, avoids guessing a source
IP or changing the existing synthetic-IP layout contract. This is internal
linker metadata, with no new loader/module schema or public ABI.

Native helper size is the low u32 of RSI, even if a constant fact carries
64 bits; it is not a source-domain proof. Exercise equal/different joins,
missing facts, calls clobbering RSI, partial writes, normal and conditional
tails, finite helper-ID joins and a nonzero ELF address. Compare source
read order, faults/full zeroing, policy/nesting and actual native bytes
across boundary sizes. Leave unresolved paths dynamic; do not invent facts
to increase the specialized count.
