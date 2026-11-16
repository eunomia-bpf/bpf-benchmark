# M4 closure review

M4 establishes the directly edited C and its actual Clight exports. It does not
establish the exported handlers' refinement of either ISA. That is M5, including
all 2,065 old theorem migrations and O1/O2/O4 recount. Old generators/contracts/
Lean artifacts stay until M6; their stale rendering checks must not overwrite
this C or be mistaken for correspondence proofs.

| M4 requirement | Current implementation and evidence |
|---|---|
| Checked-in C edited directly | Canonical x86/ARM simulator headers and the C under `formal/generated` are the source. The latter directory keeps its historical name until retirement; the 97 remaining origin comments now explicitly say to edit the C directly. No C token or line count changes in this closure step. |
| Export the real bodies | `c/X86Inline.c` roots the generic production family dispatcher and live binding structure. `c/Arm64Program.c` roots the generic instruction dispatcher, libc and 95 typed helper bodies. They include canonical production bodies rather than reimplementing them. `make clight` also exports numeric, memory, stack, context, entry and helper roots; 23 modules are listed in `exports.json`. |
| Preserve caller-owned storage | Generic x86 roots take arena capacity and references to either scalar or array facts. ARM roots take live entry cells, capacity, signed bias and actual producer payload callbacks. Prior binding/producer receipts cover these boundaries; universal representation and admissibility relations are M5. |
| Adapt unsupported C syntax and platform interfaces | Shared declaration/output bodies replace GNU expression consumers under CompCert. Public typed helper callees, alignment-1 copies, explicit context-pointer/atomic/trap imports and empty-asm adapters are declared in `c/Platform.h` and binding headers. Exact native expansions remain where Clang requires its original operand form. |
| Export producer control/declarations | Actual CALL/RET tables, XDP/SKB contexts, compact payload callbacks, scalarized facts, readonly values and register-indirect branches now have real exports. The retained Tetragon source is checked in as plain C. These are extraction regressions, not a per-program proof strategy. Generic body refinement and structural composition are M5. |
| Measure expansion and align with PERF | The production x86 inline template contains calls to separately defined family bodies, with known instruction fields and helper IDs passed as arguments. PERF's matched OTel proof shrank from 297,172,962 to 5,729,367 preprocessed bytes (1,090,696 bytes C, 6945 native instructions). See `kprog/results/perf_20261113/inline-interpreter/report.md`; full compiler cost, B frame and app performance remain PERF's separate work. |
| Preserve ordinary native compilation | Per-change receipts compare historical/current allocated code/data/relocations, including actual Cilium and retained Tetragon inputs, plus normal current compilation. This closure step changes comments only: four native preprocessing streams compare byte-for-byte, with exact commands attached. No frozen benchmark path or compiler flag changes. |

The preservation requirement applies to the C-subset adaptations. Two discovered
semantic defects have explicit forward repairs and regressions: INC/DEC pointer
tags (`e12d4c34f`) and dropped symbolic helper tails (`6ed48e9b3`). Preserving
the defective execution is not claimed. The helper-tail profile's ordinary and
expanded control graphs have separately reported sizes. No universal theorem
about compiler output bytes or whole-application correctness is inferred from
finite compilation checks.

Earlier receipts' phrases such as “arbitrary program closure,” “platform
correspondence,” and “full default coverage” do not add unspecified M4 gates.
The source/frontend/binding work above addresses the concrete extraction tasks.
Native/Clight memory, initialization, provenance, permissions, volatile effects,
helper targets, fault prefixes, declaration admissibility and control composition
are explicit M5 proof obligations. Each must retain the original observation
domain; a finite fixture, chosen recovery input, free zero input or copied state
cannot discharge them. Existing numerical/fault discrepancies stay recorded.

M4 acceptance uses the final `make clight`, all 23 Clight module builds, the
existing ABI/layout/link/producer checks and exact unchanged ASTs after comment
promotion. Whole-package `lake build` and `make check` remain required after
M5/M6; the old generated-model tests are not silently counted as migrated proofs.

This review adds no fixed checker or action gate. Small metadata and receipts
are committed here; raw commands/logs remain under
`/workspaces/kprog-raw/formal/m4-closure`. The initial comment-edit attempt met a
multiline origin comment; its diagnostic is retained, and the final complete
promotion/preprocessing comparison passes. The one checkout, sole image/base,
peer jobs and frozen benchmark stay preserved.

A subsequent M5 entry proof exposed the concrete canonical-identifier overflow
in the normalized export. The [identifier repair](../m4-clight-identifiers/README.md)
records the kernel-proved old entry refusal, the imported frontend/codec repair
and regenerated exports. Their temporary IDs intentionally change in that
forward repair; the unchanged-AST statement above describes the earlier
comment-only closure step. Canonical simulator C and frozen paths stay intact.
