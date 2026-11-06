# First complete real ARM Katran bound workload

The unchanged two-start QEMU corpus run finishes Katran with status `ok`.
The actual upstream loader loads balancer_ingress; all one resident application
programs have simulator proofs and are replaced on the generation-bound path.
The shim records prebuilt_proof=1, bound_required=1, original_id=48/native_id=53
and one actual replacement. No application program falls back to eBPF.

| Phase | Program run count | pktgen packets | pktgen errors |
| --- | ---: | ---: | ---: |
| JIT baseline | 250388 | 250388 | 0 |
| Bound native | 268634 | 268634 | 0 |

Both arms complete the same UDP workload and retain XDP action, map,
receiver/interface/drop counters in katran-work-counters.json and katran.json.
Counts differ across the time-bounded runs; QEMU timing is functional evidence.
The measured application program uses its original18 maps. This is real
balancer application closure for this recorded workload, not six-app closure.

The previous full/truncated map-name ordering failure is fixed by resolving
native ELF data symbols before opening/reusing proof maps. No identity or
layout check is removed. Exact packaged input triples and both applications'
raw run are archived here; build, pin and corpus logs are retained.

OTel remains failed: read_task_struct has source-map extern relocations plus
private readonly string relocations, but the source-map relocation path treats
all relocations as externs. All startup loads and baseline counters remain;
there are zero OTel native replacements. This concrete loader defect is the
next repair. Other application coverage and all safety obligations remain active.

The current portable runtime is kprog/arm64/build/app-runtime-v10/spark with
image.tar alongside it. See ../DGX-SPARK.md for the hardware replay sequence;
these QEMU timings are not hardware performance measurements.
