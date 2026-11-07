# Current ARM full-register-bank supplemental matrices

Replay the unchanged FMOV128, bitfield70, memory255 and exclusive8 observer
matrices with current production source snapshots. Seed each missing owned
build cache from its committed harness archive, preserving historical data;
then use existing incremental bank32.mk targets on CPUs16-19. No shared
kernel/module/image or production source is rebuilt or changed.

Completed results and the retained exclusive API refusal are recorded below. Canonical ordinary-family
replay uses the same source ISA as x86-control's f1c5 executable (ARM source
verified identical to current HEAD). Exclusive rows retain the explicit CLREX
fixture. Their physical-monitor/environment API obligations stay explicit:
no guessed physical address or reservation is added to count them as checked.
A missing exclusive reference input is retained as a failure, not a pass.
Exact per-family commands, static SHA and outputs will be added on completion.
Actual ARM hardware replay remains with the coordinator.

## Published completed families

FMOV128:131072 states; bitfield70:71680 states. Both current production
snapshots have zero QEMU/C/canonical differences and no unavailable form.
Their per-form tables, archived inputs and static hardware handoffs are
retained in the corresponding directories. The later memory/exclusive outcomes are recorded below; complete four-family
canonical agreement and actual hardware evidence are not claimed.

## Final current-snapshot results

FMOV128 +bitfield70 +memory255:453 forms/463872 QEMU/C/canonical
states, all three comparisons zero and no unavailable ordinary form.
Exclusive8:8192 QEMU/C observations agree, but canonical0cases/8unavailable
(`exclusive instruction requires explicit monitor state`); Make exits2.
Thus461 forms/472064 QEMU/C states agree, while CPU/canonical is complete
for453 forms. All four static hardware handoffs and exact source snapshots
are retained per family; real ARM hardware remains pending. No production
ISA/runtime/header change or whole O1–O4 claim is made.

## Subsequent exclusive architectural-observation closure

`exclusive/observed-projection/` (or `observed-projection/` from the exclusive
subdirectory) replays the identical8192 states using an explicit abstract
witness and three checked canonical observation/admissibility declarations.
All8 forms have1024 canonical cases with zero QEMU/C/reference architectural
observation differences and no unavailable form. Actual pre-PC CLREX/X4 and
every case's memory premises are checked. The representative's physical0 is
not a hardware mapping claim; monitor/order/paired-success/platform proof
remains separate. The original generic API rejections above stay preserved.
