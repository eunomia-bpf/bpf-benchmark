# bcc/set KVM Smoke Regression Diagnosis - 2026-05-06

Source artifact: `corpus/results/x86_kvm_corpus_20260506_223334_701834/details/apps/bcc__set.json`.

Citation shorthand: after a full `path:line` reference, a bare `:line` in the same sentence/table cell refers to the same path.

Method: `ratio = (post_rejit.run_time_ns_delta / post_rejit.run_cnt_delta) / (baseline.run_time_ns_delta / baseline.run_cnt_delta)`. Values above `1.0` mean ReJIT is slower. Qualified programs use `min(baseline_run_cnt, post_rejit_run_cnt) >= 100`. The win/loss/tie counts below use a +/-1% tie band, matching the observed `3 / 14 / 3`; with exact `ratio < 1.0` there would be `4 / 16 / 0`.

Run context: app workload is `stress_ng_os_io_network` at `bcc__set.json:6082`; this corpus run used `samples=1` and `workload_seconds=3.0` at `corpus/results/x86_kvm_corpus_20260506_223334_701834/details/result.json:6189` and `:6192`.

## 1. Per-Program Ratios

| prog_id | name | type | baseline/post runs | ratio | class | bytes_jited/xlated delta | kop sites | source lines |
|---:|---|---|---:|---:|---|---:|---|---|
| 6 | `tracepoint__raw_syscalls__sys_enter` | tracepoint | 104392491 / 94134245 | 0.9958 | tie | +0 / +0 | none | `bcc__set.json:5`, `:208`, `:411` |
| 7 | `tracepoint__raw_syscalls__sys_exit` | tracepoint | 104392661 / 94134445 | 1.0454 | loss | +0 / +0 | none | `bcc__set.json:14`, `:217`, `:687` |
| 10 | `vfs_create` | tracing | 138995 / 82650 | 1.1958 | loss | +0 / +0 | none | `bcc__set.json:23`, `:226`, `:969` |
| 11 | `kfunc__vmlinux__vfs_fsync_range` | tracing | 12349 / 12936 | 1.0103 | loss | +0 / +0 | none | `bcc__set.json:32`, `:235`, `:1248` |
| 12 | `vfs_open` | tracing | 2289165 / 2064648 | 0.9509 | win | +0 / +0 | none | `bcc__set.json:41`, `:244`, `:1527` |
| 13 | `vfs_read` | tracing | 3029274 / 3244304 | 1.0090 | tie | +0 / +0 | none | `bcc__set.json:50`, `:253`, `:1806` |
| 14 | `vfs_write` | tracing | 730597 / 978619 | 1.0080 | tie | +0 / +0 | none | `bcc__set.json:59`, `:262`, `:2085` |
| 19 | `cap_capable` | kprobe | 3970406 / 4089047 | 0.9798 | win | +3 / +0 | extract=1 | `bcc__set.json:68`, `:271`, `:2364` |
| 22 | `__x64_sys_open` | tracing | 3798 / 3747 | 2.0228 | loss | +0 / +0 | none | `bcc__set.json:77`, `:280`, `:2638` |
| 23 | `kretfunc__vmlinux____x64_sys_openat` | tracing | 1643086 / 1593640 | 0.7116 | win | +0 / +0 | none | `bcc__set.json:86`, `:289`, `:2912` |
| 24 | `kretfunc__vmlinux____x64_sys_openat2` | tracing | 596 / 644 | 1.8988 | loss | +0 / +0 | none | `bcc__set.json:95`, `:298`, `:3186` |
| 27 | `sched_switch` | raw_tracepoint | 1476356 / 1614713 | 1.0414 | loss | +116 / +208 | cond_select=7 | `bcc__set.json:104`, `:307`, `:3460` |
| 28 | `sched_wakeup` | raw_tracepoint | 1051165 / 1108719 | 1.0132 | loss | +0 / +0 | none | `bcc__set.json:113`, `:316`, `:3664` |
| 29 | `raw_tracepoint__sched_wakeup_new` | raw_tracepoint | 36240 / 24835 | 1.0544 | loss | +0 / +0 | none | `bcc__set.json:122`, `:325`, `:3938` |
| 32 | `trace_connect_entry` | kprobe | 39711 / 42805 | 1.3737 | loss | +0 / +0 | none | `bcc__set.json:131`, `:334`, `:4212` |
| 33 | `trace_connect_v4_return` | kprobe | 39711 / 42805 | 1.0469 | loss | +3 / +16 | prefetch=1 | `bcc__set.json:140`, `:343`, `:4486` |
| 37 | `tracepoint__sock__inet_sock_set_state` | tracepoint | 454575 / 408119 | 1.1316 | loss | -75 / -88 | prefetch=1 | `bcc__set.json:158`, `:361`, `:5044` |
| 38 | `trace_pid_start_tp` | tracepoint | 97166 / 56271 | 1.1488 | loss | +0 / +0 | none | `bcc__set.json:167`, `:370`, `:5327` |
| 39 | `trace_req_start` | kprobe | 97675 / 56780 | 1.1194 | loss | +11 / +24 | cond_select=1 | `bcc__set.json:176`, `:379`, `:5603` |
| 40 | `trace_req_completion_tp` | tracepoint | 98253 / 57355 | 1.2727 | loss | +0 / +0 | none | `bcc__set.json:185`, `:388`, `:5802` |

Losses: prog_ids `7, 10, 11, 22, 24, 27, 28, 29, 32, 33, 37, 38, 39, 40`. Max loss is prog 22 at `2.0228x` (+102.3% slower). Median loss ratio is `1.1255x` (+12.6% slower).

Wins: prog 23 at `0.7116x` (40.5% speedup as `1/ratio - 1`), prog 12 at `0.9509x` (5.2% speedup), and prog 19 at `0.9798x` (2.1% speedup).

Ties: prog_ids `6, 13, 14`, all within +/-1%.

## 2. Per-Pass Attribution

All 20 qualified programs have `passes[]`, but only 5 qualified programs have any kop site applied. The full 13/13 kop site distribution includes one unqualified zero-run program, prog 34.

| prog_id | class | applied pass sites from `passes[]` | final/status note | source |
|---:|---|---|---|---|
| 6 | tie | none | all `sites_applied=0` | `bcc__set.json:411` |
| 7 | loss | none | all `sites_applied=0` | `bcc__set.json:687` |
| 10 | loss | none | all `sites_applied=0` | `bcc__set.json:969` |
| 11 | loss | none | all `sites_applied=0` | `bcc__set.json:1248` |
| 12 | win | none | all `sites_applied=0` | `bcc__set.json:1527` |
| 13 | tie | none | all `sites_applied=0` | `bcc__set.json:1806` |
| 14 | tie | none | all `sites_applied=0` | `bcc__set.json:2085` |
| 19 | win | `extract` 1/1, insn_delta 0 | ok | `bcc__set.json:2434` |
| 22 | loss | none | all `sites_applied=0` | `bcc__set.json:2638` |
| 23 | win | none | all `sites_applied=0` | `bcc__set.json:2912` |
| 24 | loss | none | all `sites_applied=0` | `bcc__set.json:3186` |
| 27 | loss | `cond_select` 7/7, insn_delta +28; `const_prop` 6/6, insn_delta 0; `dce` 21/21, insn_delta -21 | final program status `error`; `dce` failed ReJIT | `bcc__set.json:3511`, `:3618`, `:3640`, `:3662` |
| 28 | loss | none | all `sites_applied=0` | `bcc__set.json:3664` |
| 29 | loss | none | all `sites_applied=0` | `bcc__set.json:3938` |
| 32 | loss | none | all `sites_applied=0` | `bcc__set.json:4212` |
| 33 | loss | `prefetch` 1/1, insn_delta +2 | ok | `bcc__set.json:4741` |
| 37 | loss | `const_prop` 8/8, insn_delta -9; `dce` 4/4, insn_delta -4; `prefetch` 1/1, insn_delta +2 | ok | `bcc__set.json:5200`, `:5223`, `:5303` |
| 38 | loss | none | all `sites_applied=0` | `bcc__set.json:5327` |
| 39 | loss | `cond_select` 1/1, insn_delta +3; `dce` 5/5, insn_delta -5 | final program status `error`; `dce` failed ReJIT | `bcc__set.json:5654`, `:5778`, `:5800` |
| 40 | loss | none | all `sites_applied=0` | `bcc__set.json:5802` |
| 34 | unqualified | `endian_fusion` 1/1, insn_delta 0; `prefetch` 1/1, insn_delta +2 | run_cnt 0/0, excluded from ratio table | `bcc__set.json:149`, `:352`, `:4855`, `:5020` |

KOperation site distribution:

| pass | sites | programs |
|---|---:|---|
| `cond_select` | 8 | prog 27: 7 sites; prog 39: 1 site |
| `prefetch` | 3 | prog 33: 1 site; prog 34: 1 site; prog 37: 1 site |
| `extract` | 1 | prog 19: 1 site |
| `endian_fusion` | 1 | prog 34: 1 site |

Among the 14 qualified losses, only 4 have kop sites: prog 27, 33, 37, and 39. The other 10 losses have no applied sites and no bytecode metadata change. Therefore the app-level 13/13 apply rate does not imply all loss rows were transformed.

## 3. Bytecode Metadata

Qualified `bytes_jited` deltas: 15 unchanged, 2 at `+3`, 1 at `+116`, 1 at `+11`, and 1 at `-75`. Qualified `bytes_xlated` deltas: 16 unchanged, 1 at `+208`, 1 at `+16`, 1 at `+24`, and 1 at `-88`.

Loss bytecode split:

| group | prog_ids | count | note |
|---|---|---:|---|
| loss + unchanged bytes | 7, 10, 11, 22, 24, 28, 29, 32, 38, 40 | 10 | no applied site and no metadata change |
| loss + grew | 27, 33, 39 | 3 | kop applied; jited grew +116, +3, +11 |
| loss + shrank | 37 | 1 | prefetch plus const_prop/dce; jited/xlated shrank -75/-88 |

Win bytecode split: prog 12 and 23 are unchanged; prog 19 grew by `bytes_jited +3` with `extract=1`. So byte growth is not sufficient to predict regression, but the largest code growth rows are losses.

Type distribution:

| type | qualified | wins/losses/ties | geomean ratio |
|---|---:|---:|---:|
| tracepoint | 5 | 0 / 4 / 1 | 1.1149 |
| tracing | 8 | 2 / 4 / 2 | 1.1562 |
| kprobe | 4 | 1 / 3 / 0 | 1.1207 |
| raw_tracepoint | 3 | 0 / 3 / 0 | 1.0362 |

Regression is not isolated to one BPF program type. All three raw_tracepoint rows are losses, but the largest ratios are tracing/kprobe rows with unchanged bytecode.

## 4. Root-Cause Hypotheses

### H1: Measurement/workload skew dominates the app-level 12% signal

Evidence for:

- 10 of 14 losses have no applied sites and unchanged `bytes_jited`/`bytes_xlated`: prog_ids `7, 10, 11, 22, 24, 28, 29, 32, 38, 40`. Their geomean is `1.264x`, worse than the kop-applied qualified subset (`1.062x`).
- Workload throughput changed materially between phases: baseline `duration_s=5.8398`, `ops_per_sec=8510962`, `ops_total=49702497` at `bcc__set.json:197-199`; post `duration_s=5.4462`, `ops_per_sec=6395861`, `ops_total=34833163` at `bcc__set.json:400-402`. That is about -29.9% total ops and -24.9% ops/sec in post.
- 7 of 20 qualified programs have run-count deltas above 10%; several are losses with no bytecode change, for example prog 10 (-40.5%), prog 29 (-31.5%), prog 38 (-42.1%), and prog 40 (-41.6%).

Evidence against / limit:

- Some unchanged-byte losses have stable run counts but large ratios, especially prog 22 (`3798/3747` runs, ratio `2.0228`) and prog 24 (`596/644`, ratio `1.8988`). These are still small absolute run-count rows, so repeated samples are needed to distinguish real counter variance from phase effects.

Current read: H1 is the strongest explanation for the app-level 1.120x geomean. The no-applied rows regress more than transformed rows, which means the 12% headline cannot be attributed cleanly to kop transforms.

### H2: `cond_select` can locally regress short BCC hot paths, but it is not the whole app regression

Evidence for:

- `cond_select` applied all 8 matched sites: prog 27 has 7 sites and ratio `1.0414`; prog 39 has 1 site and ratio `1.1194` (`bcc__set.json:3511`, `:5654`).
- Both `cond_select` rows grew bytecode metadata: prog 27 `+116/+208`, prog 39 `+11/+24`. The pass also increased bpfopt instruction count before later passes: `+28` on prog 27 and `+3` on prog 39.
- A branch-to-select rewrite can lose when the original branch is highly predictable and the rewritten sequence adds data-dependency or sidecar overhead. These rows are compatible with that failure mode.

Evidence against / limit:

- `cond_select` explains only 2 of 14 qualified losses. The top two ratios, prog 22 and 24, have no applied sites and unchanged bytecode.
- Prog 27 is only +4.1% despite 7 sites, so site count alone is not predictive. Prog 39 also has a failed later `dce` ReJIT, which confounds attribution (`bcc__set.json:5778`, `:5800`).

Current read: investigate `cond_select` profitability, but do not treat it as the root cause of the app-level 12% regression without pass-isolated reruns.

### H3: `prefetch` may be unprofitable in these BCC paths; `extract`/`endian_fusion` have little regression evidence here

Evidence for:

- `prefetch` applied on two qualified loss rows: prog 33 ratio `1.0469`, `+3/+16` bytes; prog 37 ratio `1.1316`, `-75/-88` bytes after const_prop/dce plus prefetch (`bcc__set.json:4741`, `:5303`).
- The selected workload is short syscall/network/filesystem stress. A speculative prefetch that adds two instructions can be net negative if the memory use is already hot or too close to the load.

Evidence against / limit:

- Only two qualified loss rows contain `prefetch`, and prog 37 has multiple non-kop changes, so prefetch is not isolated.
- `extract` has the only qualified extract site and it is a win: prog 19 ratio `0.9798` with `extract=1` (`bcc__set.json:2434`).
- `endian_fusion` only applied on prog 34, which has `run_cnt=0/0`, so this artifact has no performance evidence for or against it.
- `wide_mem`/bulk-memory-like rewrites had no applied sites in the qualified rows, so this artifact does not support a bulk-memory overhead hypothesis.

Current read: prefetch needs an isolated A/B check; extract/endian_fusion are not implicated by this data.

## 5. Historical Comparison

`micro/results/vm_micro_authoritative_20260314.json` is not a BCC corpus run. It is `suite: micro_staged_codegen` and uses `config/micro_pure_jit.yaml` at lines `2-3`; benchmark entries start at line `1112` and are synthetic micro benchmarks. `rg -n 'bcc' micro/results/vm_micro_authoritative_20260314.json` returns no matches. Also note the file name says `20260314`, but `generated_at` is `2026-03-18T18:18:36Z` at line `4`.

`memory/MEMORY.md` is not present in this checkout, so there is no readable MEMORY source to cite.

The plan doc has older corpus context, not per-program bcc/set data: v2 2026-04-02/03 reports `make vm-corpus` geomean `1.033x` and BCC apply-side site total `961` at `docs/kernel-jit-optimization-plan.md:25`. That line does not say BCC regressed.

The older `vm_corpus_20260403_201849` BCC rows are mixed and use the old `baseline/rejit` direction (`corpus/results/vm_corpus_20260403_201849/details/result.md:8`). Comparable BCC apps at lines `17-26` include slight wins (`bcc/capable 1.034x`, `bcc/syscount 1.027x`, `bcc/tcplife 1.085x`) and slight losses (`bcc/execsnoop 0.949x`, `bcc/bindsnoop 0.985x`, `bcc/opensnoop 0.991x`, `bcc/tcpconnect 0.994x`). Converting those seven rows to the current post/baseline direction gives a rough geomean of `0.992x`, so the 2026-04-03 corpus does not show a persistent BCC-wide 12% regression.

A later 2026-04-27 analysis did show BCC apps with mixed regressions, for example `bcc/biosnoop 2.029`, `bcc/execsnoop 1.888`, `bcc/tcpconnect 1.386`, and `bcc/runqlat 0.935` at `docs/tmp/per-program-analysis-20260427.md:32-40`. That same analysis attributes much of the corpus movement to low run counts and stress-ng instability, so it is warning evidence rather than proof that bcc/set has always regressed.

Conclusion from history: this is not supported as an always-regressing BCC behavior by the March/early-April sources. It looks either new to the current combined `bcc/set` workload/pass mix, or exposed by SAMPLES=1 workload skew in this smoke artifact.

## 6. Recommended Fix and Validation

Do not fix this by filtering ReJIT programs or adding benchmark-side exclusions. The data points to two separate tracks:

1. Measurement validation: rerun the exact `bcc/set` KVM corpus with `SAMPLES=3` and compare three groups separately: unchanged/no-applied rows, kop-applied rows, and failed-ReJIT rows. Success criterion for noise diagnosis: unchanged/no-applied rows should move near `1.0`; if they remain around `1.26x`, the counter/workload harness needs investigation before pass tuning.

2. `cond_select` profitability: build a pass-isolated experimental run for the two affected programs, prog 27 and 39. If the regression survives repeated samples while no-applied rows normalize, tighten `cond_select` profitability in `bpfopt` for shapes that add sidecar/extra instructions without reducing final JIT size, especially BCC tracing/kprobe hot paths. Validate with both micro `cond_select_dense` and corpus `bcc/set`.

3. `prefetch` profitability: isolate prog 33 and 37 with and without `prefetch`. If it regresses, require a stronger local criterion before emitting prefetch, such as enough distance to use the prefetched line and no net instruction-count increase on short paths. Validate that prog 34 remains behaviorally ok even though it has zero runs in this workload.

4. ReJIT error cleanup: prog 27 and 39 record failed later passes (`errno 22` and `errno 13`) at `bcc__set.json:3461`, `:5604`, `:3646`, and `:5784`. These failures are not the main 12% explanation, but they confound pass attribution. Fix them forward in the pass/kernel interface so the final applied state is unambiguous.

The first rerun should be diagnostic, not a policy change. The current artifact is useful for triage, but because 10/14 losses are no-op bytecode rows and the workload total ops differs by ~30%, it is not sufficient to blame a single kop pass.
