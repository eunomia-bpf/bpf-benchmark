# ARM BCC corrected source-frame runtime

Run arm64_qemu_corpus_19700101_000101_970418 retains all141 startup load attempts
(137loaded, four unfinished),63 generation-bound replacements and23 baseline
program-counter rows. Source-frame helper113 probes now pass: the lifter
allocates eight bytes, and the native16-byte frame keeps its destination at
SP+8 separate from saved LR. The retained optimized IR and exact packaged
32-entry BCC payload establish which artifacts were exercised.

Four application loads subsequently fail with EINVAL after their verifier logs
complete, including perf-output paths. These are recorded as native-load
failures, not assumed verifier rejections. The app reaches native workload
measurement, then fails on a refused shim socket; no native counter rows are
returned. The original app error and complete logs remain, without excluding
any program or relabeling incomplete measurement as success.

The published0bff849bf strict shim and context-v2-source-map library/module
are unchanged from v6; all eight startup selectors remain paired. This image
predates the coordinator's updated feature-probe pass-through instruction;
the next shim export follows20aae50eb. The correct resident-program bound
requirement remains. Kernel/stock modules/ten other kinsn use6836f7d44.
Run/build logs retain exact Make commands; QEMU timings are functional.

Only current app-runtime-v7 root/image remain. Superseded v6 was removed after
its exact payload/raw results were committed; its retirement inventory is
retained with the CODE dispatch result. All failed attempts remain evidence.
