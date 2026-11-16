# Preserve relocated helper-tail calls (M4)

`normalize_native_link_entry_returns` previously treated every JMP whose
placeholder disassembled to the object length as a local RET. A final symbolic
helper tail can have exactly that placeholder, so normalization erased its
relocation and the helper call. The original host oracle fails on this input.
The fix preserves jumps with symbolic relocations for the existing renderer.
It changes three producer lines and no shared instruction body or compiler flag.

The existing `x86_program_profile.S` now calls an ordinary helper subroutine
first and a helper-tail subroutine second, retaining both real return sites.
The fixture remains frame 48/six named facts. It reuses the existing export
module, typed callee bindings, return adapters and UBSan observer; no separate
interpreter or export module is added.

The corrected profile passes:

- 32 high64 return cases and 32 second-helper refusal prefixes in each mode.
  All 42,496 native/bound observation bytes agree, without masks. Independent
  expectations still check return arithmetic, 63/41 inputs, both helper events
  and one SP input. This is selected defined-path execution, not a theorem
  about arbitrary native faults or kernel-helper effects.
- Six negatives: missing tail helper, unknown return case, wrong helper ID,
  truncated stack base, missing RET releases and wrong callee ABI. Normal
  object/executable/ABI products are restored and rechecked afterward.
- Mature Clight label lookup finds the tail helper call with ID 5, immediately
  followed by the actual subroutine-return call and the return dispatcher.
  The typed external clock and both exact continuation labels remain checked.

`native_compare.py --output <new-raw-dir>` evaluates historical normalization
from `944d9793f` in memory with the actual parser/renderer. The old normalization
emits only one clock call; current emits both. Historical/current **ordinary**
profile C remains exact. Its ordinary BPF build is 1704 B/3 relocations; the
expanded two-subroutine control graph is 1952 B/8 relocations. Different fixture
control graphs do not have byte parity. The defective tail previously omitted
real work; preserving those defective bytes is not the correction.

No application performance, stock-verifier acceptance, kernel equivalence or
M5 refinement count is inferred here. The normal BPF build uses the existing
formal check recipe; the sole base/image and PERF jobs remain untouched.
Small commands/results accompany this receipt. Raw frontend, failed original
host check, initial oracle type error, initial overstrict different-fixture
byte comparison and final checks stay in
`/workspaces/kprog-raw/formal/m4-x86-helper-tail`.

Reproduce with `make -C kprog/formal clight`, the existing
`results/m4-x86-program/compare.py --output <new-raw-dir>`, and
`lake env lean -j1 oracles/test_x86_program_profile.lean` in `kprog/formal`.
Host/frontend work uses CPU 19/8 GiB AS, native comparison CPU 18/8 GiB AS;
Lean uses CPU 17/32 GiB AS and default limits.

Final confirmation: `make clight` and all 23 Clight modules (60 Lake jobs) pass.
The profile exports 126 bodies/21,214,912 bytes and reproduces exactly; the other
22 ASTs remain byte-identical to `944d9793f`. Five axiom queries use only
`propext`, `Classical.choice` and `Quot.sound`. The leaf build took 187 seconds.
Producer C is 4017 bytes; extraction preprocessing is 2,620,757 bytes, describing
this translation unit rather than application compilation performance. M4 stays
open pending its remaining closure review; M5 all 2065 refinements/recount and
M6 retirement/final whole-package checks remain ordered afterward.
