# Exclusive architectural-observation replay

Replay of the identical8192 captured QEMU/C states, with results below. The canonical
load/store independence proofs erase only hidden monitor/environment fields,
retaining all GPR/SP/flags/vectors/memory/PC plus canonical events/faults.
An explicit abstract representative uses physical0 and an8-byte reservation;
this is not a claim about hardware physical addresses. The theorem quantifies
all environments; the load representative separately covers both widths.
The empty-store theorem additionally requires aligned/writable memory and
empty initial monitor. The adapter checks actual pre-PC CLREX bytes and all
captured cases'8-byte alignment/mapping/initialization. No paired or successful
store, monitor/platform, acquire/release ordering or whole O1–O4 claim.
Original missing-input rejections remain in the parent directory.

## Completed observed-state result

All8 forms ×1024 =8192 identical captured states now agree with the SAME
canonical instruction semantics: zero QEMU/reference and C/reference
observational differences and zero unavailable forms. There was no new
native run, no canonical/runtime change, and no weakening of the required
wire inputs. The original eight missing-input rejections are preserved.

The3 final Lean declarations pass; axiom audits report only propext and
Quot.sound. Load observations are independent of every environment; stores
use the explicit empty-monitor, aligned/mapped writable-memory premises.
The concrete abstract representative is admissible for W and X loads. The
adapter validates actual ELF CLREX and X4 base plus every case's alignment,
mapping and permissions, then supplies the explicit witness. It changes no
ordinary/default request. Physical0 is an arbitrary representative, never a
hardware translation claim. This closes the captured architectural-state
comparison; reservation/physical invocation/ordering and universal O1–O4
remain separate. CPU memory-event order/atomicity is not measured here.

Per-form counts, empty failure streams, final proof/axiom log and witness are
retained. The verified archive captures the adapter/proof and frozen
canonical source closure. The identical native/static/source artifacts and
trace SHA are in the parent directory. The exact f1c5 canonical executable
is archived in differential/x86-control/canonical-reference.gz.

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive/observed-projection/Makefile proof
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive/observed-projection/Makefile reference
```
