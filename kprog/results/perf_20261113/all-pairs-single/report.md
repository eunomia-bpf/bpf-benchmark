# One scalar-pair spill policy

2026-11-15 coordinator08:48 directive, implemented in8f48bf443:
`KPROG_BPF_WHOLE_WORD_SPILLS_ALL`, its validation/forwarding, the
`--all-scalar-pairs` CLI selection and the last-pair-only automatic branch
are removed. The normal MIR backend always lowers every eligible scalar
pair using the existing dead-source reuse/live-scratch implementation.
Replay/test callers use that same policy; historical single-pair parity
tests and an obsolete accepted-MIR comparison are removed. Explicit low/high
diagnostic inputs remain callers of the same transformation body.

Host normal-backend check passes: production chunk joining and llc execute,
and the independent-register fixture has identical allocated sections to
direct compilation. Multi-pair/register-pressure frame checks pass on ten
variants. The same cases run in the one stock kernel, through the existing
committed functional Make entry point. CPU assignment2ed80f1c5 puts that
guest on16–17,1vCPU/2GiB/8GiB address space, imageSH only, no timing lock.
No other guest was observed; no kernel, base or image build occurred.

| Variant pair | Original frame | Packed frame | Stock execution |
|---|---:|---:|---|
| Four pairs, small | 80 | 48 | Both accepted,1,060 cases each |
| Four pairs, large | 544 | 512 | Original rejected; packed1,060 pass |
| Dead-source pressure | 16 | 8 | Both accepted,1,060 cases each |
| Live context pressure | 16 | 16 | Both accepted,1,060 cases each |
| All registers live | 16 | 24 | Both accepted,1,060 cases each |

All nine accepted variants complete **9,540 executions with zero mismatches**.
The 544-byte original naturally fails stock verification; the failure is
retained, not filtered. The all-live packed frame includes two preserved
scratch registers, so its extra8bytes are explicit rather than hidden.
The check validates values, live registers and context preservation.

After the policy change, all16 native/shared-C BMI2 fixtures also compile
through the normal B route and pass4,032 hardware comparisons. Their
generic/direct allocated sections match16/16, and match the corresponding
pre-load-refactor direct sections16/16. These are small subsets. No full
OTel B acceptance or new performance claim follows from the policy cleanup.
All native LTO remains enabled together.

Raw remains at `/workspaces/kprog-raw/perf/20261115-all-pairs-single`
(`groups`, `backend`, `native-b`, `stock`). Canonical spill build is
`/var/tmp/kprog-tmp/perf/spill-groups`; `/var/tmp/fixture.o` in the guest
aliases that one build and is overwritten for each variant. Commands,
verifier errors, executions, frame observations and result JSON stay here;
no compiled product copy is archived. Reproduce host/stock subsets with
`spill-groups-build`, `backend-check` and `spill-groups-run` in
`kprog/test/scalar-spill-precision.mk` (OUTPUT is the persistent raw path).
