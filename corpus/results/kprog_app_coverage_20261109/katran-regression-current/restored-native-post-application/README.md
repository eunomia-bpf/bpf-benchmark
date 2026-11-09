# Current master selected Katran runtime

The complete rebuilt4object native producer runs with sourceb0b0824c2bbf31fdd4ef370a412322f74a77cd55, matching kernel/module461258 artifacts, updated failure-pass-through shim and current loader/linker. Runtime source is a read-only committed export. Original May29 framework/workload bytes retain their definitions; generated corpus directories and service requests stay in /var/tmp/kprog-tmp/C. Baseline/native work and every native fallback remain in the raw result. One2s functional sample precedes R unbound throughput timing.

Actual requests1/generated1/compiled1/installed0/failed1.

The zero-request b288ec52f result stopped at driver import: the restored driver imports `snapshot_app_maps`, absent from current `runner.libs.rejit`. The frozen driver already supports `post` -> `1` on its second startup. Recipe b0b0824c2 exports the matching support module from 9f3855f6f into the image and uses existing `SKIP_REJIT=norejit` to retain native loading without a bytecode plan. The intermediate empty-plan setup error is retained in restored-framework-application (16c6e4530).

Actual terminal: one balancer_ingress native request, generated and compiled, rejected by the stock verifier: `invalid write to stack R10 off=-624 size=8` (177 instructions processed). No native installation or execution succeeded. The unchanged application completed baseline and second-phase workloads through the existing eBPF fallback; their BPF run counts are 4,774,294 and 5,052,581. Raw packet counts and errors for all four workers remain in result.tar.gz. This is a functional routing receipt, with native acceptance still open.

All 162 tracked frozen files were SHA256-identical before and after this repair. The driver is byte-for-byte 9f3855f6f; only the external recipe, task record and result artifacts changed.
