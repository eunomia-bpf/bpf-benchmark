# x86 physical-store C-subset checks

The CompCert branch of the existing shared scalar store reuses Platform's
upstream alignment-one copy adapter for widths1/2/4/8. Native volatile and BPF
asm bodies stay unchanged. One actual root calls that helper; X86Memory now
exports17 functions, including the newly referenced store callee.

Historical/native/host-adapter checks pass896 complete byte-frame cases per
mode, covering unaligned offsets, full values and byte width capture/defaults.
Four guard windows, a permission fault and two unsupported-width nonreturn
cases pass. Native traps remain SIGILL; the CompCert platform fixture exits77.
Three semantic mutations detect a short64-bit copy, wrong destination and
alignment8. No width mask or unsupported-width fallback is added.

The combined `make clight`/40-job targeted Lean build passes; the follow-up
physical subset passes its38-job targeted build and one standard-axiom query.
Memory re-export matches the parent's genuine194,324B export. Both sequential
workers reuse the same objects/executable/AST and are terminal. Historical
header replay retains store2272B/13 allocated relocations and memory1680B/5,
with current replay equal to normal compilation. Fixtures were not loaded or
timed. All raw inputs, commands, old queue records and results remain.

This removes the C-chunk alignment obstruction without proving native
volatile, permission, pointer-fragment or fault correspondence. Those remain
M5 obligations. M4/full handlers/default coverage, all2,065 refinements/recounts,
M6 and whole-library acceptance remain open.
