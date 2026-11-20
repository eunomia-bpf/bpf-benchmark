# The two "hangs" were the measurement window, not a stall (OMP 2026-11-20, corrected)

Withdrawal of an earlier reading in this file. Two arms (Tetragon 19:14Z, Tracee 20:40Z) appeared to stall after
`socket: cmd=measure_start`, and this file had listed image, loader, shim and CPU affinity as excluded causes.

The 540 s is the workload. Guest-timestamped `socket: cmd=` lines from two arms:

| arm | `measure_start` | `measure_finish` | gap |
|---|---|---|---|
| OTel, x86_kvm_corpus_20261120_081247_049639 (quoted as healthy) | 1255.94 | 1798.52 | **542.6 s** |
| Tetragon, x86_kvm_corpus_20261120_222740_505433 (called hung) | 308.82 | 849.02 | 542.6 s |

3 x 180 s = 540 s. So `emit_measure_finish` arrives exactly when the three samples end, and the shim log is
silent in between because that is the measurement window. A 30 s probe of the same app and image confirms the
recipe (`measure_start` 169.78 -> `measure_finish` 199.85, run completed):
x86_kvm_corpus_20261120_224639_547587.

Why an arm takes so long: Tetragon's own load takes ~600 s of guest time, so with two arms of 3 x 180 s a leg is
25-35 minutes wall. Nothing was hung; my arms were inside their window when I looked, and the three rc=2 legs in
the coordinator's rotation were my kills.

Superseded: the shim-side mechanisms considered earlier in this file (a kernel-id scan, `query_prog_info` cost, a
single-threaded server) - none of them is the explanation, and none is a defect.

What still stands: the stale base loader and 0e4f2da6f's gs loads both cost coverage, both are fixed
(02429959e/3b5fa4b40 plus the rebuilt loader), and the arms need re-running - at ~30 minutes each, not as hangs.


## What the re-runs must satisfy to give a per-call number

Two arms of the same app on the 3b5fa4b40 image, counted from the app detail records:

| run | baseline loaded | post loaded | calls post/base |
|---|---|---|---|
| Tracee 10:01 (pre-fix, 140 failures) | 167 | 167 | 0.97 |
| Tracee 18:43 (3b5fa4b40 check) | 167 | 167 | 1.46 |
| Tetragon 11:51 (pre-fix) | 287 | 123 | 0.53 |

Both arms load the same program set on the fixed image, so a per-call ratio from a fixed-image arm is a
program-for-program comparison; on the pre-fix Tetragon arm it was not (123 vs 287), which is why that one quotes
no ratio.
