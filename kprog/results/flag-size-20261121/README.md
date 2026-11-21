# Executable bytes per app for one flag set (2026-11-21, coordinator)

Operator 2026-11-17: "也得通过调优编译参数做到native 快 50%、代码量少一半. 必须要确保这样, 硬性要求", "编译参数所有 app 统一.";
2026-11-16: "接下来你来做, 不要叫其他人, 你来负责清理好并且自己去调性能参数".

`flagsz.sh` builds the six apps' x86 natives into a scratch BUILD tree (`/tmp/flagsz/<level>`, the image inputs stay as
they are) with the current flag set and only the optimization level changed, then counts executable section bytes
(`kprog/results/flag-tuning-20261117/textsize.py`). The O3 column equals the image 3b5fa4b40 inventory (21:30 report).
Logs: `/workspaces/kprog-raw/coordinator/flagsz-20261121/`.

| App | O3 | Os | Oz | Os / O3 | Oz / O3 |
|---|---|---|---|---|---|
| BCC | 8,559 | 7,061 | 7,439 | 0.825 | 0.869 |
| Cilium | 256,770 | 240,881 | 232,256 | 0.938 | 0.905 |
| Katran | 9,600 | 9,191 | 9,141 | 0.957 | 0.952 |
| OTel | 528,274 | 400,919 | 372,506 | 0.759 | 0.705 |
| Tetragon | 5,952,963 | 5,263,794 | 4,745,326 | 0.884 | 0.797 |
| Tracee | 1,630,163 | 1,400,511 | 1,736,116 | 0.859 | 1.065 |
| All | 8,386,329 | 7,322,357 | 7,102,784 | 0.873 | 0.847 |

- Os shrinks every app; Oz grows Tracee. Os is the one-flag-set candidate; its timing round (image, six-app check,
  frozen-entry rotate, then the default image back) is queued as kprog-raw/coordinator/tune-os-20261121T075220Z.
- Against the installed native/JIT bytes at O3 (11-17: OTel 0.80, BCC 1.00, Cilium 0.83, Tracee 0.82, Katran 0.69), Os
  gives about OTel 0.61, BCC 0.83, Cilium 0.78, Tracee 0.70, Katran 0.66: the level alone leaves every app above one half.
