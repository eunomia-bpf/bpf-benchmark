# BCC syscall-work counter diagnosis

The observed8434(JIT) vs514(historical bound native) short-run difference does not by itself demonstrate a native behavior regression: R's single no-application-BPF run x86_kvm_corpus_20261107_060516_326524 reports exactly8434,514,514 in its three180-second samples. Its metadata says workload_only=true; the app has mode workload_only and an empty BPF counter set. All three stress-ng invocations returned0. No new timing run was performed.

| Source | Sample/arm | Reported syscall bogo ops | Reported real seconds | User+system seconds |
|---|---|---:|---:|---:|
| C short | JIT |8434|2|0.07|
| C short | historical bound native |514|3|0.04|
| R workload only, no application BPF |0|8434|180|0.15|
| R workload only, no application BPF |1|514|180|0.11|
| R workload only, no application BPF |2|514|180|0.06|

Every record selects fast75 and reports294 system-call tests,220fastest non-failing tests fully exercised. The reported CPU time is tiny relative to elapsed time, but these logs do not identify the blocking/calibration/scheduling mechanism. They do not prove equal syscall selections or same work per bogo operation. The new trusted application path and fixed-work diagnostics still need to establish behavior; no claim that native has no effect follows.

counters.csv retains all44reported stressor rows: both short arms, all three no-BPF samples, and the JIT baseline samples from R's051705/054048 attempts. Those latter two application records have overall status error and no post_rejit record; their status/error are preserved in summary.json and they are not presented as successful native comparisons. Cap, set and sockfd rows remain included. No minimum-count filter, zero-error gate or workload/runner change was added.

Reproduce from the existing raw inputs:

```
python3 corpus/results/kprog_app_coverage_20261107/bcc-workload-check/analyze.py
```

summary.json pins all input hashes and retains the exact syscall records and source-run states. R owns publication of those original corpus run files. This C increment interprets the retained raw observations; it does not replace or modify them. Per-component cost attribution and compiler/link-time optimization remain deferred.
