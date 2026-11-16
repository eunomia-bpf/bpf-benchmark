# B empty memory barriers

2026-11-16T01:39:11Z

B normalization removes only no-argument, void inline asm with an empty template and exactly the memory clobber, without stack alignment or unwind effects. These templates emit no architectural operation. Actual helper/memory asm and typed register operations keep their existing treatment; volatile nonlocal accesses stay volatile. Shared I, native P, flags and published compiler stay unchanged.

The regression puts barriers before and after a real external helper which reads and mutates private bytes, checks both select aliases and external context, and retains/executes a real nop asm with a memory clobber. Thirty scalar cases, sixty identity/context cases, thirty equality cases, twenty helper mutations, twenty mixed aliases and forty other accesses pass. These checks cover the compiler subset; full refinement remains M5 and real OTel frame/kernel/app acceptance follows.

Raw commands and outcomes: /workspaces/kprog-raw/perf/20261116-empty-barriers/check.

2026-11-16T01:47:45Z: actual main removes646 empty barriers, code289560->288400B, frame remains824B/52spills. The 243 call-minus-one templates are unresolved indirect-target guards, not helpers; they remain. Typed helper inventory finds110 map-lookups (id1),108 trace_printk (id6),24 probe_read_user (id112) and one tail-call (id12). Current calls lack the helper input/output memory contract. Next investigate B-only attributes from the actual kernel ABI; no whole-app acceptance claim.
