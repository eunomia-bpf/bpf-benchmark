# Superseded contract-route retirement

The coordinator’s 2026-11-16 19:19 instruction moves deletion of the obsolete
proof route ahead of continued M5 work. This removes its source, rather than
excluding failing modules from Lake. The library still discovers all remaining
modules with its original glob. Git history retains the removed source; raw
results and historical receipts remain in place.

`deleted.json` lists 233 old proof modules, 140 generated Lean contracts, 140
JSON contract inputs and 149 obsolete generators/exporters/mutation or source
scan tools. The aggregate import module now imports the current Clight proofs,
mature reference bindings and retained relocation-producer interface laws.
`removed-build-products.json` records 2,853 obsolete rebuildable proof artifacts
removed from the sole build. No raw data or benchmark path was removed.

The 140 simulator C headers stay canonical C and keep their existing include
paths. The independent native/hardware comparisons and host checks still run
from `make check`. The C helper oracle is also retained as plain C. Obsolete
JSON regeneration and admission scans are removed from that entry. The two
source-extracted relocation interfaces and their conditional producer laws are
retained; this cleanup does not strengthen their source/compiler assumptions.

The retained producer proofs are adjusted for Lean 4.35. Field-selection
simplification now closes its goal, so its redundant final `rfl` is removed.
The image/window proof explicitly transports the unchanged record kind before
splitting both emitters on the same condition. Both statements are unchanged.

The map-lookup host harness now uses exact named map facts, the current complete
link-plan schema and required exception ABI output. Its layout fixture is
explicitly synthetic; it does not claim boot-kernel BTF correspondence. All 90
existing linked ARRAY/PERCPU_ARRAY execution paths pass. The resolver command
now selects the current exact-name unit test instead of matching zero tests.
Both use the existing production Cargo target directory. Its duplicate formal
Cargo output (1,323 rebuildable files, 717,571,677 bytes) is removed.

The host entry environment explicitly chooses zero for each unspecified-input
visit (kind 6), as it already does for stack/return origins. Unsupported kinds
still fail. These are test-environment choices, never production invariants.
This repairs the current inline-wrapper sign-high test: 1,415 reference cases,
6,144 CPU/encoded-handler cases and all three BPF compilations pass.

The complete `lake build` passes 270 jobs with zero failures. All 23 generated
Clight exports remain byte-identical to `9c617740f`; see `export-parity.json`.
The complete `make check` is still running at this commit; its retained retries
and final status will be recorded separately.

`frozen-paths.json` compares 162 May-frozen files directly with `9f3855f6f`.
158 match. Four inherited differences (top-level Makefile, two micro YAMLs,
runner/mk/build.mk) are byte-identical to the pre-turn `2be755991` state. This
step changes none of them. The timing entry also remains byte-identical to
that pre-turn state. The inherited differences are recorded, not repaired by
changing benchmark files.
Raw attempts are under `/workspaces/kprog-raw/formal/legacy-retirement`.
M5 still needs complete exported-handler correspondence and O1/O2/O4 recount;
the obsolete theorem total is not migrated coverage. M6 remains open for any
remaining retirement and final frozen-path verification.

The seven BPF compile checks now select v3, matching the ALU32 operand constraint
already required by the simulator. Their focused results, including initial
failures and repairs, are in `bpf-checks.json`. Existing computed-displacement
cases now check their supported emitted loads instead of expecting the removed
signed16-only refusal: four dynamic arguments plus both signed16 boundaries
retain one 32-bit read at the complete effective address.

The ordinary host fixed-address load now forms unsigned address bits before
casting back to a pointer. This avoids Clang UBSan's null-base arithmetic failure
for RIP-symbol fixtures, while preserving the accessed address and width. Both
GCC and Clang pass all 88,704 POPCNT full-state cases. The BPF and Clight header
preprocessing streams are byte-identical to `01b18b84b` (3,411 and 5,751 bytes);
`memory-header-parity.json` records the exact commands. The earlier sole-writer
agreement is recorded in COORDINATION before this change. This host repair adds
no new production check or external interpretation.

Both retained producer axiom queries pass with only standard axioms; reproduce
with `LEAN_NUM_THREADS=1 lake env lean -j1 results/legacy-retirement/Query.lean`.
The complete check is being repeated after these focused fixes.

The current linker shares selected ARRAY bodies through local calls. The map
harness still checks all 90 actual load/bounds fragments and their complete
state, ordered reads and faults; local calls must target that fragment and no
external helper relocation is present. Wrapper CALL/RET stack effects are
explicitly outside these fragment observations, as wrapper entry/exit were
before sharing. They remain a general-control refinement obligation; this
receipt does not infer their performance or whole-wrapper equivalence.

The complete current ARM protocol checks pass. Reserved logical-immediate
encodings now require LNSym's explicit `StateError.Illegal` refusal, replacing
retired local-decoder messages. Six formerly rejected legal words are retained
as fixed complete-state positives (plus both outcomes of BC.HI). LLVM decodes
them independently; FP16 and HBC assumptions are explicit. All 48,384 logical
immediate states, 1,580 reserved encodings, 1,280 MRS states, the full main ARM
matrix, 962 addressed/vector states and 84 exclusive states pass. This is model
and wire regression evidence. `arm64-model-regressions.json` preserves the six
observations and LLVM commands; the unchanged mature model supplies execution.
