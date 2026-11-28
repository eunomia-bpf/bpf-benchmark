# BCC stats-off alignment diagnosis

Newest order: **COORDINATOR 2026-11-28T11:20Z**. Tetragon's retained selector-continuation skipped-work defect is now confirmed (aaba957ee; common repair2d006f5d8 already present). Continue with the BCC stats-off anomaly before the ordered current-image rebuild and six-app check. OTel remains at2689a430.

Existing full3x180s stats-off throughput is0.877248x, stats-on1.020368x. The off-mode loss is concentrated in **sockfd0.727961x**, with cap0.968510x/set0.987506x; on-mode component ratios are allabout1.02. This localization is not a causal stats-switch result.

inspect_runs.py uses the frozen05-29 parser on actual retained runs11-28_061040_622818(stats0) and_085002_496250(stats1). It preserves original metadata/app/log SHAs, complete program counters, all sample component metrics/commands and actual original/native load receipts in retained-runs.json. Both runs statusok. Stats0zero counters mean accounting disabled, not zero program execution.

| Stats | Component | eBPF median ops/s | Native median ops/s | Native/eBPF |
|---|---|---:|---:|---:|
| off | cap | 381586.05 | 369570.03 | 0.9685 |
| off | set | 29021.44 | 28658.84 | 0.9875 |
| off | sockfd | 248266.73 | 180728.58 | 0.7280 |
| off | syscall | 2.84 | 2.84 | 1.0000 |
| on | cap | 284707.44 | 289694.46 | 1.0175 |
| on | set | 22130.10 | 22560.90 | 1.0195 |
| on | sockfd | 212594.21 | 217226.70 | 1.0218 |
| on | syscall | 2.86 | 2.86 | 1.0000 |

The frozen overall metric is median(sum of components per sample), not sum(component medians). The table localizes the loss; do not present component-median differences as an exact additive decomposition of the overall median.

Both modes contain25native loading receipts with an equal multiset of name, originalBPFtag/JITlength and nativeJITlength. This does not establish actual native-byte, frozen-global, map-binding, dynamic-path or output equivalence. The two long runs were sequential at different times, so flags, scheduling and environment have not been isolated causally. No configuration defect or code fix is established yet.

Prepared one current-image stats0/stats1 host-PMU/code observation pair in profile_pair.py. Each uses the existing profile/check entry with1sample/10s/64G/CPUs0-7 and all normalBCCprograms through the same native manifest, one compile-flag policy. The stats switch is the intended variable. timingEX/imageSH/batchEX protect shared guest state. Host PMU runsCPU19; read-only observer captures full linkcache, map metadata/RO-array values and the hot sys_enter/sys_exit/sched_switch code. Names select only observation, not which programs compile or install. Existing SysRq stack requests are removed; no benchmark/default/workload source is changed. Both generated scripts passed bash -n and heredoc escaping checks before launch.

The pair is prepared on unchanged image6b88c0ba4c22; no image refresh is performed for this diagnosis. After publication it starts once with setsid nohup, stdin/dev/null; collect the same paired-profile/controller.json and raw path recorded in lane/bcc-stats-profile.json next turn. No profile result, reproduction or performance acceptance is claimed now. Stats0 has no entry-call denominator, so interpret PMU with phase windows/ownQEMU attribution and actual component metrics; do not divide by its disabled counters. Diagnostic observers/PMU have overhead, sampling/skid limits, and the pair is sequential. Use results to inspect real instructions/helpers/maps/scheduler work, not to tune flags speculatively.

Next: collect/review the same pair, identify whether the sockfd loss reproduces and which native work or alignment differs. Then rebuild currentx86 with ee7f45f55/6c8fdc70f and run the ordered six-app10s check. Frozen OTel/application/kernel/benchmark/paper stay. Published 2026-11-28T12:08:06Z.
