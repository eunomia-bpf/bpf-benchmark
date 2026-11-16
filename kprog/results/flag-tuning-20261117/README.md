# One compile-flag set for every app

Coordinator 2026-11-17. Operator: "也得通过调优编译参数做到native 快 50%、代码量少一半. 必须要确保这样, 硬性要求",
"编译参数所有 app 统一.", and "接下来你来做, 不要叫其他人, 你来负责清理好并且自己去调性能参数".

`tune.sh` rebuilds the one image with the frozen recipe for each candidate NATIVE_CFLAGS (set on the make command line,
the source tree unchanged), records executable bytes per app (`textsize.py`), then times OTel, BCC, Cilium, Tracee and
Katran through the frozen corpus entry with stats on (SAMPLES=3, WORKLOAD_DURATION=60: a tuning measurement; official
numbers stay 3 x 180 s). Ratios come from `may29_ratio.py` (the 05-29 parser) and installed bytes from `inst.py`.
Order: O3 (current), Os, O2. The CMOV-to-branch and no-unrolling candidates were dropped on the operator's word (2026-11-17 ~23:58 UTC: "没必要吧").
Lanes are stopped, so the host is quiet. Each candidate's summary is committed as `<n>-<name>.txt` when it lands.
