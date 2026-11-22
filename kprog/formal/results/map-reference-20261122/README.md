# Current named-helper map reference oracle

The whole check's485-job Lean build passed. The following map oracle exposed
three historical fixture assumptions: numeric helper-ID calls, shared-routine
RET boundaries and scale/LEA flag retention. The fixture now uses the actual
named `bpf_map_lookup_elem` path and verifies the common exit of today's inline
ARRAY/PERCPU_ARRAY branches. Final status flags come from the real trailing
ADD sequence, checked independently on the CPU.

All90 existing complete-fragment state, ordered-read, fault and map-kind cases
remain. Twelve additional scale-prefix cases preserve the prior SHL/IMUL flag
observation before the subsequent ADDs overwrite it. The102 comparisons against
the same canonical x86 ISA pass. The four named direct-call targets and two
opaque-map generic helper targets retain their relocation checks. Entry-wrapper
stack effects retain their original separate scope.

The tool's own [result output](result.txt) records the successful subset run.
Raw failed/successful commands and the original inline-array disassembly remain
in `/workspaces/kprog-raw/V/x86-alu-decode-20261122` (map-fixture1/2/3 and
map-inline-array-first.asm). Complete confirmation follows this correction.
The patch touches the verification fixture; runtime/linker/reference ISA and
benchmark definitions retain their existing contents.
