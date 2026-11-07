# Current ARM full-register-bank supplemental matrices

Replay the unchanged FMOV128, bitfield70, memory255 and exclusive8 observer
matrices with current production source snapshots. Seed each missing owned
build cache from its committed harness archive, preserving historical data;
then use existing incremental bank32.mk targets on CPUs16-19. No shared
kernel/module/image or production source is rebuilt or changed.

All CPU/QEMU and reference results are pending. Canonical ordinary-family
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
retained in the corresponding directories. Memory and exclusive results
remain pending; no complete four-family or actual-hardware claim is made.
