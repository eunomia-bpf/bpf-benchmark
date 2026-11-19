# Concrete ARRAY facts in checked C/LTO

PERF source review, 2026-11-19. Candidate after the NUMERIC phase-1 repair;
no source change, profile, guest or performance result in this review.

`kprog/x86/trusted_specializer.py:198-209` recognizes named, concrete ARRAY
symbols from the existing artifact map metadata, but passes only their names
to compile-sim-ir. That compiler selects one generic C lookup body at
`kprog/x86/compile_sim_ir.cpp:169-172`.

`kprog/x86/micro-prog/inline_array.py:38-44` emits a key read and three map
field reads: max_entries, elem_size and index_mask. Element addressing uses
a runtime stride multiplication. The C body is always_inline, so this is a
per-lookup data dependency rather than necessarily a remaining helper call.
Whether final installed code retains those reads needs a retained-object
check; this review does not claim an observed instruction count or hot app.

The sole kernel's `kernel/bpf/arraymap.c:220-254` embeds all three facts in
the JIT lookup sequence. A power-of-two element size becomes a shift. The
allocation code at lines 94-109 derives stride and mask from the concrete
map dimensions. Existing artifact records already carry max_entries and
value_size (`kprog/trusted_generation.py:63-77`). The current C helper instead
receives only layout offsets from BTF, with no concrete dimension constants.

Next evidence: inspect retained checked-sim native IR/object and its exact
map metadata for a program that actually uses this C helper. Confirm the
three reads and map identity before choosing a runtime change. Constant
propagation should use the loaded map's own facts. A template for a returned
inner map is not its concrete max_entries: the kernel explicitly declines
JIT dimension specialization for BPF_F_INNER_MAP at arraymap.c:230-231.
Keep the kernel's existing speculation-mask behavior when specializing.

Expected effect, if the reads survive in a hot path: remove three immutable
field loads and expose constant stride arithmetic. No measured ns/call,
throughput, helper share or installed-byte change is available. No new
runtime dispatch, check, map exclusion or Rust helper routine is proposed.
