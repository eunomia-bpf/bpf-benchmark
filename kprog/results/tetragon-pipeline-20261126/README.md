# Tetragon output binding and tail accounting

PERF 2026-11-26T15:39:26Z.

This phase1 inspection uses the existing image68655f5c6c0d captures. No new
guest, producer flags, optimization selection, kernel or benchmark change is
introduced. Run `python3 kprog/results/tetragon-pipeline-20261126/audit.py`
from the checkout to reproduce audit.json and the two disassemblies.

The source is the retained same-app-load pair in
cmov-branches-20261126/post-branch-profiles-20261126T145836Z/tetragon-profile,
run x86_kvm_corpus_20261126_150046_350964, snapshot411.78:

| captured output | program ID | JIT bytes | translated bytes |
|---|---:|---:|---:|
| original retained by the loader | 709 | 1,881 | 3,160 |
| installed native | 710 | 1,189 | 16 |

Both contain one direct call site to bpf_ringbuf_output at0xffffffff904d2120,
matching the captured kernel kallsyms. Immediately before it, both load the
same ring-buffer map address0xffff8a76cd461600 into RDI and clear RCX, the
flags argument. The original moves its event pointer R13 to RSI and its
length R14 to RDX; native moves event pointer R14 to RSI and length R15 to
RDX. Original/native-output.dis retain the complete actual machine code.
The output proof's map-patches.tsv identifies tg_rb_events at blob offset847;
its early link-plan map addresses are0 placeholders, not final runtime
bindings. The actual installed code above supplies the bound addresses.

Both length paths load event->common.size at offset4, add0x90, mask0x7fff
and clamp to9000. The original uses a64-bit add and branch, native a32-bit
add and cmov. The final15-bit mask makes32-bit wrap equivalent here even
at the largest32-bit input. This agrees with generic_output in
vendor/repos/tetragon/bpf/process/generic_calls.h and event_output_metric in
vendor/repos/tetragon/bpf/lib/process.h. The latter selects either perf-event
output or ring-buffer output from tg_conf_map, with error/statistics handling;
the inspected native code does not add a second ring-buffer call site.

The three existing default10s checks retain six generic_tracepo records in
each phase. Exactly one has nonzero invocation/time deltas in each capture:

| repetition | eBPF counted ID / invocations | native counted ID / invocations |
|---|---:|---:|
| 1 | 214 / 14,157,514 | 704 / 19,213,740 |
| 2 | 210 / 13,431,409 | 712 / 20,165,790 |
| 3 | 215 / 17,572,507 | 710 / 17,166,955 |

The other five tail targets have zero counters in each phase. These IDs
belong to their own app runs; ID710 is the root in repetition3 and the
output target in the separate profile run. This matches evaluation.md§5.6:
the attached caller's time includes its descendants; adding uncounted tail
targets to the denominator would be wrong. No counter adjustment is made.

The normal native-link build_x86_tail_call_inline and the sole kernel's
emit_bpf_tail_call_indirect both check index, check the33-transfer budget,
load/test the target, increment the budget only for a populated slot, then
transfer to bpf_func+12 after their respective frame cleanup. The budget
word is not bpf_prog->stats.cnt. The kernel's prose postincrement comment
does not override its emitted increment-after-nonnull instruction order.

This closes the inspected wrong-helper/map/flags/length and counter-mix
explanations, without proving equality of all dynamic event payloads or
event counts. No production defect or performance fix is established here.
The existing common flags and LTO pieces stay on together. The dominant
profiled kernel lock and one losing short check per target remain recorded
in cmov-branches-20261126; the performance objective stays open. Full timing
remains frozen.
