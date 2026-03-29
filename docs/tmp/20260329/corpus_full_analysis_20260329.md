# Corpus Full Analysis (2026-03-29)

- Primary artifact: `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`
- Scope: full 469-object corpus run, `status=completed`
- Primary summary:
  - `compile_pairs=1114`
  - `measured_pairs=705`
  - `comparable_pairs=415`
  - `applied_comparable_pairs=212`
  - `applied_programs=429`
  - `applied-only geomean=1.042827240424557`
  - `all-program geomean=1.0031117689474556`

## Source Note

`091745` guest invocation points at `docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-s7ih7dzs.json` and `...result-wzjd5pr6.json`, but those exact files are not present in the workspace. The accessible raw batch files under `docs/tmp/20260329/corpus-rejit-batch/` match the nearby rerun artifact `runner/corpus/results/vm_corpus_20260329_124613/details/result.json`, not `091745`.

Therefore:

- All headline counts and conclusions for this note come from `vm_corpus_20260329_091745/metadata.json`.
- I only use the accessible raw batch data as secondary evidence for pass mix and noise assessment, and I call that out explicitly where used.

## Executive Takeaways

1. The main funnel loss is still before comparability: only `415/2009 = 20.7%` of selected programs become comparable pairs, and only `212/2009 = 10.6%` become transformed comparable pairs.
2. The measured-to-comparable loss is well explained: `290` pairs drop there, mostly because attach-trigger programs never fired (`214`, 73.8%) or because both sides reported `exec_ns=0` (`49`, 16.9%).
3. `katran`'s `1.544x` is not strong evidence of a repo-wide speedup. It is based on only 2 transformed comparable pairs, and `all-comparable` katran is actually `0.923x`.
4. `calico`'s `0.914x` is a much larger-sample result (`54` transformed comparable pairs), but it is concentrated in a few objects and the code-size delta is tiny. Trust the repo-level negative direction more than any single-object ranking.
5. Kinsn modules did load: the guest log reports `5/5 loaded` twice on x86, so zero hit rate for `rotate` is a pattern issue, not a module-loading issue.
6. This artifact records `--repeat 50`, but not `--profile dev`; the often-quoted `iterations=1` is not actually recorded for `091745`. The statistical discussion should be about 50-repeat averaged samples with no preserved variance, not about a confirmed `iterations=1` run.

## 1. Funnel: How Much Drops at Each Step, and Why

The summary definitions are exact:

- `compile_pairs`: both baseline compile and REJIT compile succeeded
- `measured_pairs`: both baseline run and REJIT run succeeded
- `comparable_pairs`: measured pair with non-null `speedup_ratio`
- `applied_comparable_pairs`: comparable pair with non-empty `applied_passes`

| Stage | Count | Retain vs previous | Retain vs total | Drop at this step | Main reason |
| --- | ---: | ---: | ---: | ---: | --- |
| Selected programs | 2009 | 100.0% | 100.0% | 0 | corpus selection |
| Compile pairs | 1114 | 55.5% | 55.5% | 895 | load / prepare / attach failures dominate early attrition |
| Measured pairs | 705 | 63.3% | 35.1% | 409 | post-compile run/attach failures |
| Comparable pairs | 415 | 58.9% | 20.7% | 290 | no-fire attach programs and `exec_ns=0` |
| Applied comparable pairs | 212 | 51.1% | 10.6% | 203 | measured and comparable, but no pass fired |

Additional coverage fact:

- `applied_programs = 429`, so REJIT changed `21.4%` of all selected programs.
- But only `212/429 = 49.4%` of transformed programs became transformed comparable pairs. The rest were transformed but not comparable because of run failures, no-fire exclusions, unsupported attach measurement, or `exec_ns=0`.

### What explains the `895` compile-pair loss?

`metadata.json` only preserves a failure-event histogram, not a de-duplicated per-program partition. So the counts below are reason mix, not an exact partition of the `895` programs:

- Direct load failures: `724` events
- Prepared-state cascade after earlier load failure: `932` events
- Direct attach failures: `692` events

The largest direct failures are:

- `bpf_object__load failed: Invalid argument`: `567`
- `bpf_program__attach failed: Operation not supported`: `420`
- `bpf_program__attach failed: No such file or directory`: `190`
- `bpf_program__attach failed: Invalid argument`: `82`
- `bpf_object__load failed: Permission denied`: `81`
- `bpf_object__load failed: No such process`: `76`

Interpretation:

- Early funnel loss is still mostly a strict-kernel coverage problem, not a REJIT pass problem.
- `bpf_object__load failed: Invalid argument` remains the single biggest root cause.
- Attach failures are the main reason that a compile-success case still fails to become a measured pair.

### What explains the `290` measured-to-comparable loss?

This step is fully explained by `comparison_exclusion_reasons`, and the counts sum exactly to `290`:

| Exclusion reason | Count | Share of 290 |
| --- | ---: | ---: |
| `attach_trigger did not fire the target program in baseline or REJIT` | 211 | 72.8% |
| `bpf_prog_test_run reported exec_ns=0 in baseline and REJIT` | 49 | 16.9% |
| unsupported `iter/*` attach-trigger sections | 27 | 9.3% |
| `attach_trigger did not fire ... in baseline` | 3 | 1.0% |

So the comparability bottleneck is measurement coverage, not transform coverage.

## 2. Is `katran 1.544x` Noise?

Short answer: treat it as a weak anecdotal signal, not a robust repo result.

Why:

- `katran` has only `5` comparable pairs total.
- Only `2` of those `5` are transformed comparable pairs.
- `applied-only geomean = 1.5439`, but `all-comparable geomean = 0.9231`.

That gap is the warning sign: the repo-level story flips depending on whether you condition on just the 2 transformed programs.

Within the exact `091745` summary:

- `katran:balancer.bpf.o`: `1` transformed comparable pair, geomean `2.0976x`
- `katran:xdp_pktcntr.bpf.o`: `1` transformed comparable pair, geomean `1.1364x`

Log-space contribution to the `1.5439x` headline:

- `katran:balancer.bpf.o`: `85.3%` of the positive log mass
- `katran:xdp_pktcntr.bpf.o`: `14.7%`

So the repo headline is basically one pair plus a small second pair.

Secondary evidence from the nearest accessible raw rerun (`vm_corpus_20260329_124613/details/result.json`, not `091745`):

- The transformed code-size ratios are identical to `091745`, which strongly suggests the same compile-time transforms re-fired.
- But katran's applied-only geomean drops from `1.5439x` to `1.2467x`.
- `balancer.bpf.o` drops from `2.0976x` to `1.1304x`.
- The two transformed katran programs live at very small absolute times in the accessible raw rerun:
  - baseline median `44.5 ns`
  - range `11 ns` to `78 ns`

Conclusion:

- `katran 1.544x` is too sample-starved to be called a stable repo result.
- The conditional speedup is directionally interesting, but the evidence is not strong enough for a paper-level claim.

## 3. Why Is `calico 0.914x` Negative?

This one is more credible than katran because the sample is much larger:

- `59` comparable pairs
- `54` transformed comparable pairs
- `54` transformed programs
- `applied-only geomean = 0.9143x`
- `all-comparable geomean = 0.9170x`

That last point matters: unlike katran, calico's negative direction is not created by conditioning on transformed-only pairs. The whole comparable repo is already slightly negative.

### The regression is concentrated, not uniform

Negative log contribution inside the exact `091745` calico transformed subset:

| Object | Applied comparable pairs | Geomean | Share of calico negative log mass |
| --- | ---: | ---: | ---: |
| `calico:from_wep_debug.bpf.o` | 8 | `0.4208x` | `59.3%` |
| `calico:to_hep_debug.bpf.o` | 9 | `0.7078x` | `26.6%` |
| `calico:to_nat_debug.bpf.o` | 9 | `0.9026x` | `7.9%` |
| `calico:xdp_no_log.bpf.o` | 1 | `0.6667x` | `3.5%` |
| `calico:xdp_debug.bpf.o` | 2 | `0.8524x` | `2.7%` |

Positive offsets partially cancel that:

- `calico:from_nat_debug.bpf.o`: `1.4566x` on `8` pairs
- `calico:to_wep_debug.bpf.o`: `1.3963x` on `8` pairs
- `calico:from_hep_debug.bpf.o`: `1.1385x` on `9` pairs

So the repo-wide `0.914x` is driven mostly by two objects:

- `from_wep_debug.bpf.o`
- `to_hep_debug.bpf.o`

Together they explain about `85.9%` of calico's negative log mass.

### It is not a code-bloat regression

The exact `091745` code-size signal for calico is tiny:

- repo code-size geomean: `1.004956x` baseline/rejit

That means REJIT code is only about `0.5%` smaller on geomean. This is not a "smaller code but much slower because of code explosion" story. The transformed code is almost the same size either way.

### Likely pass mix

Exact pass-level raw for `091745` is missing, so this part is an inference from the nearest accessible rerun raw. I am using it only because the rerun has:

- the same calico transformed-pair counts as `091745`
- identical calico object-level code-size ratios to many decimal places

In that nearby raw rerun, calico's `54` transformed comparable pairs are almost entirely:

- `const_prop` + `dce`: `51/54`
- `endian_fusion`: `48/54`
- `wide_mem`: `28/54`
- `cond_select`: `14/54`
- `extract`: `7/54`
- `bulk_memory`: `6/54`
- `map_inline`: only `1/54`

So calico's negative result is very unlikely to be a `map_inline` issue. It looks much more like sensitivity in the TC debug paths to the `const_prop`/`dce`/`endian_fusion`/`wide_mem` bundle.

### How stable is the calico negative direction?

Secondary evidence from the nearby rerun raw:

- calico applied-only geomean stays negative: `0.9143x` in `091745` vs `0.8874x` in the nearby rerun
- but `6/8` calico object geomeans flip sign between the two runs, despite identical object-level code-size ratios

Interpretation:

- The repo-level negative direction looks more believable than katran's positive spike.
- But object-by-object rankings are not stable enough to over-interpret.

## 4. Per-Pass Hit Rate

Denominator choices:

- compile hit rate denominator: `1114 compile_pairs`
- run hit rate denominator: `705 measured_pairs`

`pass_counts` in the summary are pass applications, so one program can contribute to multiple pass counts.

| Pass | Compile hits | Compile hit rate | Run hits | Run hit rate |
| --- | ---: | ---: | ---: | ---: |
| `dce` | 384 | 34.5% | 282 | 40.0% |
| `const_prop` | 376 | 33.8% | 273 | 38.7% |
| `map_inline` | 292 | 26.2% | 208 | 29.5% |
| `endian_fusion` | 95 | 8.5% | 79 | 11.2% |
| `wide_mem` | 40 | 3.6% | 33 | 4.7% |
| `extract` | 32 | 2.9% | 14 | 2.0% |
| `cond_select` | 20 | 1.8% | 16 | 2.3% |
| `bulk_memory` | 16 | 1.4% | 8 | 1.1% |
| `skb_load_bytes_spec` | 1 | 0.09% | 1 | 0.14% |
| `rotate` | 0 | 0.0% | 0 | 0.0% |
| `bounds_check_merge` | 0 | 0.0% | 0 | 0.0% |

Takeaways:

- The corpus is still overwhelmingly a `dce` / `const_prop` / `map_inline` story.
- Kinsn-backed passes are active, but sparse.
- `rotate` is enabled in config but produced zero hits in this full run.

## 5. Were the Kinsn Modules Loaded?

Yes.

The exact `091745` guest log says:

- `Loaded bpf_bulk_memory`
- `Loaded bpf_endian`
- `Loaded bpf_extract`
- `Loaded bpf_rotate`
- `Loaded bpf_select`
- `kinsn modules: 5/5 loaded`

This appears twice in the same `stdout_tail`, once before the VM script banner and once inside the captured script transcript.

The x86 module snapshot under `guest-inputs/module/x86` contains exactly these five `.ko` files:

- `bpf_bulk_memory.ko`
- `bpf_endian.ko`
- `bpf_extract.ko`
- `bpf_rotate.ko`
- `bpf_select.ko`

So:

- missing pass hits are not caused by missing kinsn modules
- `rotate=0` means "no corpus opportunities fired", not "module failed to load"

## 6. Code Change Quantification

Exact `091745` quantification:

- transformed programs: `429/2009 = 21.4%`
- transformed comparable pairs: `212/415 = 51.1%`
- compile-passing code-size geomean: `1.03718x` baseline/rejit
  - equivalently, REJIT code is about `3.6%` smaller on geomean where compile succeeded
- compile-passing median code-size delta: `0.0%`

Interpretation:

- Most compile-passing programs do not materially change.
- The aggregate code-size improvement comes from a transformed minority, not from broad corpus-wide shrinkage.

Useful repo contrasts:

- `katran` code-size geomean: `1.14229x`
- `calico` code-size geomean: `1.00496x`

So:

- katran's transformed cases do shrink noticeably
- calico's transformed cases barely shrink at all, which is consistent with "small structural rewrites, noisy timing response"

## 7. Statistical Credibility of `repeat=50 / iterations=1`

### First, correct the configuration statement

For the exact artifact `vm_corpus_20260329_091745`:

- the guest command records `--repeat 50`
- it does **not** record `--profile dev`
- corpus packet mode CLI does **not** expose an `--iterations` argument at all

So "`repeat=50 / iterations=1`" is not the exact recorded config for this run.

What the code says:

- benchmark config defaults: `iterations: 3`, `warmups: 1`, `repeat: 200`
- dev profile: `iterations: 1`, `warmups: 0`, `repeat: 50`
- but `091745` did not pass `--profile dev`
- guest batch mode still pulls `warmup_repeat` from benchmark config and passes it down

### What the measurement actually stores

The runner records one averaged sample per side:

- `kernel_runner` divides `exec_cycles` and `wall_exec_ns` by `repeat`
- `llvmbpf_runner` divides `exec_ns`, `exec_cycles`, and `wall_exec_ns` by `repeat`

So each final point is:

- one average over `50` repeats
- not a per-repeat distribution
- with no preserved variance, standard deviation, or confidence interval

### What is credible and what is not

High confidence:

- funnel counts
- exclusion reasons
- pass hit rates
- kinsn module load status
- code-size ratios

Medium confidence:

- overall transformed geomean `1.0428x` across `212` transformed comparable pairs
- calico repo-level negative direction, because it uses `54` transformed comparable pairs and `all-comparable` is also negative

Low confidence:

- katran `1.544x`, because it is only `2` transformed comparable pairs
- single-object rankings inside calico, because same-day nearby rerun evidence shows large object-level sign flips with identical transformed code

Bottom line:

- `repeat=50` is enough to suppress some timer quantization, but not enough to make pair-level or object-level claims statistically secure without multiple independent reruns.
- For this corpus artifact, trust aggregate funnel/pass/code-size conclusions first, repo-level calico direction second, and katran/object-level performance claims last.
