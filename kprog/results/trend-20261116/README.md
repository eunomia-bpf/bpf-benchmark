# Every timing run since 2026-11-11, one line each

Coordinator, 2026-11-16T23:27:56Z. Operator 2026-11-16: "你看看数据, 是不是越来越慢了? 为啥这样?"

`runs.txt`: each completed run of `kprog/perf/one-image/Makefile rotate` in /workspaces/kprog-raw/one-image-runs/progress.log,
with the official throughput ratio (may29_ratio.py off=), each arm's mean, per-sample ratios, and per call (on=) for stats-on runs.
No timing ran between 2026-11-12 19:31 and 2026-11-16 01:32 UTC.

What the series shows:
- Unequal work behind the early highs: OTel 1.83-1.89x (05-29 context read wrong, no unwinding) and Katran 1.09-1.13x
  (05-29 linker skipped LRU lookups) on 11-11/12; equal-work OTel was 1.021x on 3a1906ab1, Katran about 1.0.
- Regressions from our own changes: Tetragon ran at 1.25-1.33x on 11-11/12 and errors on every run since 11-16;
  OTel went 1.021x (3a1906ab1) -> 0.801x (6641a7e1), cause open.
- The eBPF arm itself (same JIT code) slowed on 11-16 from about 10:00: BCC 661,016 (04:16) -> 501,333 (18:19);
  Tracee 390,243-401,747 (11-12) -> 287,571 (19:28). Per-sample spread grew from about 2% (11-11/12) to 15-30%
  (Katran 1.377/0.895/0.783). That started after the lanes moved back into the Workspace and ran Lean builds, tool
  and image builds and 32 GiB diagnostic guests on CPUs 8-23 next to the timing guest on 0-7.
