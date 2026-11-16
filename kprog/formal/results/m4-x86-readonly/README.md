# Readonly native-data Clight export (M4)

The real x86 parser/renderer consumes the proof object produced by the normal
native-link from `oracles/x86_readonly_profile.S`. Its 15 instructions read one
16-byte relocated object through indexed, overlapping and unaligned loads;
the declared arena is 8 bytes with one named fact. The assembler object alone
has no native-link readonly metadata and is not the input for this route.

The actual frontend rejected the GNU selector, then its 53 `__builtin_memcpy`
sites. `readonly_load_declarations` now emits one declaration/output body,
retaining the native expression facade. The CompCert inline adapter calls that
same body. The copy platform macro selects upstream alignment-1
`__builtin_memcpy_aligned`; native compilation retains `__builtin_memcpy` and
the original empty value asm. No new memory semantics or external is added.

Final checks pass:

- `make clight` and all 23 Clight modules (60 Lake jobs).
- Exact reexport: 124 bodies, 19,988,248 bytes. All prior 22 ASTs remain exact.
  Producer C is 11,924 bytes; extraction preprocessing is 2,551,815 bytes.
  These describe this extraction unit, not application compiler performance.
- Mature Clight layout, symbol resolution and initial-memory checks read the
  actual immutable global bytes; five axiom queries contain only `propext`,
  `Classical.choice` and `Quot.sound`.
- Both UBSan host modes pass 124 width/window/identity frames, ordered captures,
  four bad-width refusals and 16 hardware-matched complete producer returns.
  The existing scalar-tagged readonly address takes four explicit recovery
  choices; these executions choose nonrecovery. Each return consumes exactly
  29 inputs, including one SP input. This does not establish arbitrary fault
  behavior, private-state framing or a kernel/native-memory refinement.
- In-memory missing-zero-initialization, lost-output and wrong-copy-width
  mutations fail the intended runtime assertion. The normal executable is
  rebuilt afterward.
- Historical readonly emitter `a85db64d2`, current emitter and ordinary current
  compilation have identical allocated code/data/relocations: socket 2616 B,
  readonly 16 B, metadata 163 B, license 4 B and 11 relocations. Historical
  emitter source is evaluated in memory with the actual current renderer;
  no private source tree is created.

`native_compare.py --output <new-raw-dir>` reproduces the native comparison;
`compare.py --output <new-raw-dir>` reproduces the runtime checks and mutations.
Run from this single checkout after `make -C kprog/formal clight`, using the
existing normal native-link product. Exact commands and outcomes accompany
this receipt. Host work uses CPUs 17–19, 8 GiB AS; Lean uses 32 GiB AS, `-j1`
and default limits. Final indexed export leaf build took 194 seconds.

Raw diagnostics, initial wrong-input/nonindexed probes and interim oracle or
harness failures stay in `/workspaces/kprog-raw/formal/m4-x86-readonly`.
Final receipts use the indexed fixture and corrected harness. This step advances
M4; no M5 refinement theorem is counted. M5's 2,065 refinements/O1/O2/O4 recount,
M6 retirement and whole-package `lake build`/`make check` remain afterward.
