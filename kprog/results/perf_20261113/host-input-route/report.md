# Explicit host environment inputs

2026-11-15.080a1aa08 removes the host-only zero branch from both shared
simulator headers. Host, B and CompCert now use the explicit unspecified-input
entry. B/CompCert expressions, native P, compile flags and all LTO are unchanged.
This fixes the host's restricted environment, not the remaining hardware
input-matching or formal proof obligations.

49195146e first removes test macro overrides from the independent output-
lifetime, load-writeback and alias-store oracles. On the old host header,
four groups fail: x86/ARM64 output lifetime, RSP writeback and alias stores.
The entire failed run is in `before`. After the header change, the actual
route passes200 helper-output cases per ISA,14 pointer/RSP/recovery cases,
4,224 complete alias-store cases and the existing713 load/117782 stack/
1292621 store/65538 width checks. Zero and nonzero choices and exact draw
counts are checked; no local replacement of the input macro remains in them.

The existing generic/canonical storage profiles now use the actual shared
header route as well (8ef77c1a1). With UBSan enabled, **925,344 x86** and
**1,474,560 ARM64** comparisons pass. These observe every register, private
byte, saved fact, guard/padding field, input identity/order and complete
deterministic stream of distinct words. They include six capacities per ISA,
x86 array/scalarized fact layouts, and ARM64 negative/nonzero stack biases.
This is full-state exported-C/canonical-C equivalence on those cases, not a
complete ISA proof or hardware input witness.

Host callers explicitly supply their chosen environment. Existing small
fixtures choose zero origin/free words; the jump-table fixture supplies its
seed through the real entry provider (84cc846f6). CPU/shared-C checks pass512
store and4,032 BMI2 cases. All32 normal B allocated section hashes match
their preceding outputs; generic/direct BMI2 matches16/16. Further passing
host subsets:20 map capability/tag cases;128 map/helper consumer cases;
64 shared-code-table,64 scheduled-table,512 native+512 shared context-table,
64 scalar-data cases;320 native+320 shared code-table executions and two
private-state refusal cases. Exact commands/results remain in each directory.
No new B kernel run or application acceptance is claimed.

Two caller problems remain visible in the receipts. The control observer
initially failed to link without an input provider (`control-before`);
1acc704a1 supplies the same explicit zero choice it previously got implicitly.
It then builds and runs **8,960 cases with4,864 mismatches**, the same known
released-stack hardware/model difference (`control-after`). Fields and cases
are preserved; the header fix does not solve that witness. Numeric/full-ISA
and remaining host-caller migration/AST/formal checks are not certified here.

The first code-table check stopped on an outdated diagnostic assertion, while
the linker correctly rejected the interior target with `helper CFG branch
targets an interior byte`. fada46340 asserts the current rejection; all
positive/negative cases then pass. Both attempts are retained. No linker
acceptance logic was weakened or changed by that test repair.

Raw `/workspaces/kprog-raw/perf/20261115-host-input-route` remains complete.
CPU recordings/mismatches are archived losslessly as `control-*.tar.gz`;
`control-identities.json` binds their original files. No compiled programs or
source copies are archived. Existing canonical builds are reused, including
the formal binding objects and CPU observer. Make entrypoints, CPU/AS limits,
exact source/header identities and logs are retained. Host-only work, no guest,
timing lock, base/image update or performance claim. OTel911032 still runs on
its earlier captured input;921682/928246 remain queued.
