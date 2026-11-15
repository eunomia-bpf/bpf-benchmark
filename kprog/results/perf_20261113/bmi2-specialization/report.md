# Constant BMI2 dispatch and current OTel preprocessing

2026-11-15. Implementation bd07827e3; paired B comparison d1044c7fb;
nonzero-displacement fixture 1c2518cf7; pinned-Lean API repair 027cce145.
All work uses the single checkout and existing kernel/base/image. All native
LTO remains enabled together. No upstream application or P compiler change.

Constant SHIFTX, SHIFTX_MEM, BZHI and BZHI_MEM now use direct handler calls
from the existing generated specialization contract. The generic runtime
dispatcher uses exactly the same bodies. The two shift bodies were extracted
from its arms, preserving flags, width selection, memory recovery, the packed
displacement and the AUX count register. Existing BZHI bodies are reused.

Validation:

- Independent chain enumeration: 207 cases pass. Whole-state direct/generic
  comparison: 566 cases pass, including all newly direct tokens.
- Actual BMI2 CPU versus generated shared simulator: 16 fixtures, each with
  252 cases (4,032 total): SHLX/SHRX/SARX/BZHI, 32/64 bits, register/memory,
  seven bit patterns, twelve counts, low/high result halves and CF/ZF/SF/OF.
  The final memory fixtures read at +24 from the context; that slot differs
  from the base slot to expose an incorrectly decoded displacement. Earlier
  zero-displacement observations are retained separately.
- Each final fixture compiles through the normal B pipeline using both the
  real generic dispatcher and direct specialization. **All 16 allocated
  section sets are byte-identical.** Full ELF hashes sometimes differ due to
  debug/nonallocated sections. Only the current build remains at its canonical
  path; both variants' allocated hashes and raw command logs are retained.
- `lake build KProgFormal.X86Specialization` passes with two workers and a
  16 GiB address-space cap. Its refinement, completeness, totality and
  no-insertion theorems remain intact. This is the dispatch contract, not a
  completion claim for the full simulator semantics/AST obligations M4–M6.

The current OTel profile uses exactly the prior native object, proof object,
normal CLI, perf_unwind_hotspot/type7 and seven historical map bindings:

| Measurement | Before (9a62333d2) | After |
|---|---:|---:|
| Decoded native instructions | 6,945 | 6,945 |
| Generated C bytes | 1,032,413 | 1,032,341 |
| Preprocessed bytes | 431,680,679 | 384,511,544 |
| CPP/C expansion | 418.13x | 372.47x |
| Proof/render/CPP wall time | 19.67 s | 18.98 s |

CPP shrinks **47,169,135 bytes (10.93%)**. Both runs use the production
chunking/flags, CPUs 8–11 and an 8 GiB address-space limit with image SH.
This is one frontend observation, not an execution or compiler-speed claim.
Input identities: native c50a8df99505eead7881bbd9bebb8eb9357fd53106feb7ff58a8f7781e393150;
proof 717ece2934366ecfd4b61c0118e460153048cdce657a66d416df29ca5d823452;
metadata e5c8459b6798aa812ef24253a87a143593ad28148499c3752076f1c4603e6e4a;
CLI 45c33e7ee145c32c80a021182706e5a8c8152900bba68dd6cc78f042f09b7cb6.

MOV_LOAD still accounts for 127,980,936 CPP bytes and STORE for 114,820,691.
MOV_LOAD duplicates destination writes across memory/context/tag branches;
each write expands stack-release bookkeeping. Consolidating that writeback
while preserving pointer representatives, tags, width and RSP behavior is
the next candidate. The 384.5 MB frontend, full OTel backend/stack acceptance,
fresh application context capture and equal-work execution remain open.
No 10K/100K compile was restarted and no runtime speedup is claimed.

Failures retained: the first independent chain expectations and direct-route
count were stale after adding four direct tokens; after updating them there
were no state mismatches. The original host compilation emitted eleven
warnings, recorded in `contract/make.log`. Lake failed before elaboration at
8 GiB even with two workers (`failed to create thread`). At 16 GiB a diagnostic
build reached an existing `String.dropRight` API error on pinned Lean 4.35;
using `(s.dropEnd n).toString` preserves the suffix operation and the theorem
statements. Corrected Make/Lean status is 0, in `lean-corrected`.

Raw runs stay under `/workspaces/kprog-raw/perf/20261115-bmi2-specialization`
(`initial` observations are at its root, then `paired`, `displaced`,
`contract`, `lean`, `lean-corrected`) and
`/workspaces/kprog-raw/perf/20261115-current-otel-direct-dispatch`.
Canonical builds are `/var/tmp/kprog-tmp/perf/bmi2-specialization` and
the reused `/var/tmp/kprog-tmp/perf/otel-whole-word-checked`.
This result directory contains logs/measurements/identities, not build copies.

Reproduce the subsets with the committed Make entry point:

```
make -r -f kprog/test/native-relocations.mk bmi2-specialization OUTPUT=/workspaces/kprog-raw/perf/<run>
make -r -f kprog/test/native-relocations.mk bmi2-contract
make -r -f kprog/test/native-relocations.mk current-otel-preprocess OUTPUT=/workspaces/kprog-raw/perf/<profile>
```

The last target explicitly binds the historical matching perf metadata; it
does not claim fresh app startup or OTel B verification. Actual tests use no
guest and do not hold the timing lock. No base/image replacement was needed.
