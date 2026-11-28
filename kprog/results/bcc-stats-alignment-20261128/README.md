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

## Completed pair and actual code/RO review (2026-11-28T12:27:15Z)

Consumed SAME1454977, finished12:16:09Z. Both guests exit0, both applications statusok, both images6b88c0ba4c22, source4153eb39d. **Both perf wrappers exit143**; they wrote perf files, but this is not a clean PMU exit or automatic sample validity. The queued offline reader must validate report decoding, phase coverage and explicit ownQEMU. The actual observed process ancestry binds stats0QEMU1455056/stats1QEMU1455627; pmu-owner-evidence.json and process-observations.jsonl preserve provenance.

The10s diagnostic has stats0total662591.73eBPF/540806.88nativeops/s, and stats1total424099.34/511042.41. Multiple components move in this short pair, unlike the long-run sockfd-focused loss. Native stats0parent workload lasted13.020s (most stressors individually10s); metadata/PMU/scheduling and observer costs matter. In particular the2s loop copies the full native cache, with little/no equivalent baseline cache. These snapshots help inspect code, but do not isolate native instruction cost or causally reproduce the original0.877x result. No rerun has been started.

review_pair.py inspects12actual in-phase JIT captures: sys_enter/sys_exit/sched_switch, both arms and both stats modes. After resolving exact captured symbols/local function targets, all6off/on instruction-shape comparisons match. Native lengths are74/272/995B, original108/406/935B. Unknown high-address literals remain unresolved; this does not prove final map-binding or literal equality. The initial reader treated concatenated BPF subprograms as one contiguous VMA and reported a false sched_switch difference. Its exact recipe/report remain as attempt1; the corrected reader segments by each captured function address/length. Original binary captures/profile jobs are unchanged.

Across4arm/mode snapshots,7queried rodata maps each match byte-for-byte after masking only capable.my_pid. That field matches the actual capable process in each shim log; source assigns getpid() and the BPF excludes itself. Other readonly bytes, including syscount/runqlat controls, match. summarize_review.py/review-summary.json preserve full assertions/source anchors. No stats-specific compiled configuration change is established in these observed controls; HASH values, unresolved pointer bindings and other programs remain separate gaps.

The ORIGINAL3x180s sockfd data distinguishes execution rate from CPU availability: stats0median CPU seconds275.31eBPF/180.53native, while reported CPU-normalized operation rates162290.13/180198.47ops per CPU second. Stats1CPU seconds271.93/272.32 and CPU-normalized rates140649.33/143586.72. The native off case performs fewer wall-time operations while consuming far fewer CPU seconds, and performs more operations per CPU second. These are descriptive medians, not proof of external interference, throttling or a particular blocker. The pending PMU/scheduler review should explain where worker time/work differs before any code change.

SAME offline PMU reader1456924 is queued/running onCPU16/48GiB. analyse_pair.py retains perf143 explicitly and excludes unrelated QEMUs. **After collecting it, run normalize_pmu.py once on the existing decoded JSON:** the raw field named periods_per_total_bogo_op used metric_rate*whole_shim_window, which is a nominal normalization, not actual operation count when cleanup duration differs. The correction retains that nominal value separately and divides raw period sums by actual recorded summed bogo counts. It requires no perf decode or profile rerun. Sampling/observer/mixed-component limits still apply.

Prepared archive_pair.py to preserve EVERY closed rawprofile and originalcorpus file into48,000,000Bparts with SHA256 verification of each payload and original, CPU19/48GiB, after recipepublication. It does not delete raw/native/source or label capturedELFs/PMU valid simply because archival succeeds. Analysis outputs are reviewed/published separately. The archive controller/parts will be collected next turn, along with SAME1456924; no fullrawarchive-publication claim yet.

No production fix, new profile, image rebuild or fulltiming this step. Continue BCCcause, then ordered ee7f45f55/6c8fdc70f currentimage plus six-app10s. Latest order11:20 and OTel2689HOLD/STOP remain.

## PMU decoded and complete raw archive (2026-11-28T12:39:44Z)

Consumed SAME1456924: both perf report decodes return0 with explicit own-QEMU PIDs and positive in-phase BPF samples. Sample spans cover0.9998-1.0000of each selected common window. Original perf exits143 remain explicit; this establishes readable in-phase data, not a clean capture termination or causal precision. Applied normalize_pmu.py once to existing decoded JSON; no perf decode/profile rerun. Normalized values use actual recorded summed bogo counts, retaining the original nominal rate-window values separately.

| Stats | Phase | All sampled periods / composite bogo | BPF bodies | htab_get_next_key | clocksource |
|---|---|---:|---:|---:|---:|
| 0 | baseline | 14597.1 | 316.4 | 1980.0 | 1092.6 |
| 0 | post_rejit | 14782.8 | 307.3 | 2029.4 | 1006.0 |
| 1 | baseline | 19563.4 | 365.2 | 2817.6 | 3326.5 |
| 1 | post_rejit | 18734.7 | 320.3 | 2610.9 | 3318.5 |

The observed native BPF-body aggregate does not broadly increase in this sample. Hash-key iteration and clock reading are large kernel symbols. BCC syscount/runqlat userspace sources contain map traversal, but the PMU table alone identifies neither the calling process nor the blocker causing reduced sockfd CPU time. Composite bogo units, changing component mixes, period sampling/skid, whole-window cleanup and observers prohibit interpreting these numbers as exact per-program latency or causal speedup. review_pmu.py/paired-profile/pmu-review.json retain source anchors and actual window/sample counts.

Consumed SAME1462073 archive0: **1395files,337733095logical bytes**, all decompressed payloads and original source SHA/size verified. Complete raw profile/code/maps/perf/guest logs and original corpus records are published in two parts:48000000B SHAb9a6919e1e977bb46c07a447dde92b40f1589ae886cd08d9d9d1dcfd220ee8d0;9600048B SHA6e720b787acb80efd3567ca29cd7f2630b9ef34d8cbe664cd38c30ca60262dda. The manifest is paired-profile/archive/controller.json. Read members directly from concatenated parts with zstd/tar; observations/stats0/... and observations/stats1/... retain raw capture names, corpus/results/... retains original measurement records. This archive also preserves partial sampled artifacts without pretending they passed ELF validation. All originals remain at publication. Analysis JSON/recipes are separate canonical records; no deletion is authorized merely by archive status before committed-Git verification.

Next narrow diagnosis: one short stats0/stats1 pair with every normal BCC tool retained, recurring cache/code/map dumps and PMU removed, and only read-only task CPU/wchan/stack snapshots. Existing snapshots already supply the code/config comparison; task states should show why sockfd worker CPU availability differs without the known cache-copy asymmetry. No frozen workload, tool set, program selection, compile flags, kernel, app or image change is proposed. Cause remains open; the ordered current-image rebuild and six-app10s check follow diagnosis.

Verified raw-duplicate cleanup 2026-11-28T12:44:01Z: AFTER all1395decompressed members and originals matched the committed Git manifest/parts at6b0fa3f4c, removed only1383owned untracked raw profile/top-log copies (337397659logicalB). Exact paths/SHA/Gitblobs/removals/preserved entries: paired-profile/verified-raw-cleanup.json. Both48MB-format parts and full manifest remain; use archived observations/stats0 or stats1 members directly. Original corpus records, protected prior-staging/hardlinks and production source/nativeP remain. This supersedes publication-time raw-preserved statements; no profile rerun is needed when loose copies are gone.

Task-state follow-up prepared 2026-11-28T12:48:51Z: task_state_pair.py / observe_tasks.py / task-state-preparation.json seal ONE low-I/O stats0/1 pair on the same6b88 image. Every normal BCC tool and frozen10s workload/flags remains. Replaces recurring full-native-cache/code/map copies and PMU with read-only guest /proc CPU/schedstat/wchan and selected task stack/status/io snapshots at0.5s. This addresses the prior observer asymmetry and unresolved sockfd CPU/wait difference; it is not a new throughput acceptance run. Both generated scripts bash-n0; source hashes recorded. Runs timingEX/imageSH/batchEX and preserves prior staging. No image/app/kernel/benchmark change. Task snapshots can identify observed waits/CPU accounting but do not by themselves prove the cause of the historical180s result.
