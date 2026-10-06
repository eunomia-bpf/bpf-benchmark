# Policy Improvement Analysis

## Scope and Method

This analysis uses:

- `corpus/results/corpus_v5_tuned_policy.json` as the main artifact for the current tuned-policy behavior.
- `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json` only as a comparison point on the 142 shared measured programs.
- `corpus/policies/` for the current shipped policy corpus.
- `corpus/auto_tune.py`, `corpus/generate_default_policies.py`, `corpus/policy_utils.py`, `scanner/src/policy_config.cpp`, and `config/micro_pure_jit.yaml` for representation and tuner capability.

Conventions used below:

- "Measured" means a row with a numeric `speedup_ratio`.
- Geomeans are over `baseline/v5` exec-time ratios, so `>1.0x` is good.
- "High-confidence" means stock `exec_ns >= 100`.
- The March 11 blind artifact is not a perfect apples-to-apples baseline for the March 12 tuned run: the blind run is effectively a 5-family all-apply run, while the tuned-policy run applies the newer 8-family surface except for object-level `cmov: skip` on 18 objects. So blind-vs-tuned deltas mix two effects:
  - removing CMOV on some objects
  - adding ENDIAN and BRANCH_FLIP under the policy path

## Executive Summary

The current tuned-policy result is still below break-even because two different problems are mixed together:

1. Real policy loss remains in non-CMOV families, especially medium/high-`exec_ns` Calico programs that now run `branch-flip`, `endian`, `extract`, and `wide` combinations. CMOV is no longer the dominant residual problem.
2. The raw 142-row geomean is also dragged down by sub-ktime/no-op noise. There are 48 measured programs where the tuned policy applied nothing; those alone still geomean only `0.873x`, and 42 of those 48 are below `100ns`.

The fastest path to a trustworthy `>1.0x` result is:

- move from object-level corpus policies to per-program policies
- first tune `branch-flip`/`endian` on high-confidence Calico regressors
- treat sub-`100ns` no-op rows as measurement noise, not policy evidence
- run a simplified per-program family sweep before the full auto-tuner

Policy changes alone can plausibly push the applied/high-confidence slice above break-even. They are unlikely to push the raw unfiltered 142-row geomean above `1.0x` unless the no-op sub-ktime rows are also remeasured or filtered.

## 1. Why Tuned Policy Is Still `0.898x`

### 1.1 Overall Breakdown

| Metric | Value |
| --- | --- |
| Measured programs | 142 |
| Exec geomean | `0.898x` |
| Regressions | 84 |
| Wins | 42 |
| Ties | 16 |
| Applied-family programs | 94 |
| Applied-family geomean | `0.911x` |
| No-op programs (`applied_families_run = []`) | 48 |
| No-op geomean | `0.873x` |
| No-op regressions | 26 |

Regression severity among the 84 regressions:

| Ratio bucket | Programs |
| --- | --- |
| `<0.60x` | 11 |
| `0.60x-0.75x` | 27 |
| `0.75x-0.90x` | 23 |
| `0.90x-0.95x` | 13 |
| `0.95x-1.00x` | 10 |

The regressing subset itself has geomean `0.762x`, median `0.786x`, worst case `0.467x`.

### 1.2 Remaining Loss Is Mostly Not CMOV

Among the 84 regressions:

- 26 are pure no-op rows: the tuned policy applied nothing.
- 58 regressions still had some family applied.
- Of those 58 applied regressions, 53 do **not** include CMOV.
- In the high-confidence `>=100ns` applied slice, CMOV is actually the only family that is not obviously net-harmful.

Tuned-run overlap summary by applied family:

| Family | Applied programs | Regressions | Wins | Geomean | Applied `>=100ns` | Geomean `>=100ns` |
| --- | --- | --- | --- | --- | --- | --- |
| `cmov` | 12 | 5 | 6 | `1.196x` | 9 | `1.314x` |
| `wide` | 33 | 21 | 10 | `0.915x` | 27 | `0.912x` |
| `rotate` | 2 | 2 | 0 | `0.641x` | 1 | `0.582x` |
| `extract` | 30 | 24 | 3 | `0.824x` | 18 | `0.864x` |
| `endian` | 59 | 38 | 15 | `0.904x` | 47 | `0.899x` |
| `branch-flip` | 73 | 47 | 20 | `0.931x` | 56 | `0.946x` |
| `none` | 48 | 26 | 16 | `0.873x` | 6 | `0.968x` |

Interpretation:

- CMOV is no longer the main remaining problem in the tuned run.
- `branch-flip`, `endian`, `extract`, and `wide` all remain below break-even.
- `rotate` looks bad only in overlap form; standalone evidence says the opposite (see below).

### 1.3 Family-Only Programs

Programs whose eligible sites are in exactly one family:

| Only-family eligible set | Programs | Regressions | Wins | Geomean | Programs `>=100ns` |
| --- | --- | --- | --- | --- | --- |
| `cmov` | 11 | 7 | 3 | `0.832x` | 1 |
| `wide` | 0 | 0 | 0 | n/a | 0 |
| `rotate` | 2 | 0 | 2 | `1.084x` | 2 |
| `extract` | 9 | 7 | 1 | `0.738x` | 0 |
| `endian` | 1 | 1 | 0 | `0.583x` | 0 |
| `branch-flip` | 11 | 4 | 4 | `0.936x` | 1 |

Conclusions from the family-only slice:

- `extract` is a direct regressor.
- `endian` also has direct regressions.
- `branch-flip` has direct regressions, though its family-only set is mostly tiny programs.
- `rotate` is **not** a standalone regressor in the current data; both rotate-only programs win.
- There is no measured wide-only eligible program, so wide needs to be inferred from overlaps.

### 1.4 Which Families Actually Cause the Remaining Regressions?

#### CMOV

Current tuned policies already removed CMOV on 18 objects. The measured CMOV-applied subset is now small and positive:

- 12 tuned programs still apply CMOV and geomean `1.196x`.
- In the high-confidence `>=100ns` slice, CMOV-applied programs geomean `1.314x`.

CMOV is now mostly thesis evidence, not the main blocker for the corpus result.

#### WIDE_MEM

WIDE is still implicated, but mainly in combinations:

- Overlap geomean is `0.915x` overall and `0.912x` for `>=100ns`.
- There is no measured wide-only eligible program, so there is no clean isolated wide regression.
- The harmful cases are mostly Calico combinations such as `wide + endian + branch-flip` and `wide + extract + endian + branch-flip`.

So: WIDE is part of the remaining loss, but the current data do not say "wide alone is bad."

#### ROTATE

ROTATE is not a standalone culprit:

- Rotate-only eligible programs geomean `1.084x` and both win.
- The two rotate regressions are:
  - `calico/from_hep_debug.bpf.o:calico_tc_maglev` (`0.582x`, `rotate + endian + branch-flip`)
  - `katran/balancer.bpf.o:balancer_ingress` (`0.706x`, `wide + rotate + extract + endian + branch-flip`)

`calico_tc_maglev` is especially revealing: the blind run applied only ROTATE and got `1.103x`; the tuned run adds ENDIAN and BRANCH_FLIP and drops to `0.582x`. That points away from ROTATE and toward the added families.

#### EXTRACT

EXTRACT is definitely causing regressions:

- Extract-only eligible programs geomean `0.738x`.
- 7 of the 9 extract-only programs regress.
- All 9 are `test_tc_tunnel` subprograms, so they are direct evidence but all are tiny (`7ns-10ns`).

EXTRACT also participates in the larger Calico losses, especially:

- `extract + endian + branch-flip`
- `wide + extract + endian + branch-flip`

#### ENDIAN

ENDIAN is also causing regressions:

- Direct isolated regressions exist:
  - `libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress` -> `0.583x`
  - `test_tc_tunnel:__encap_udp_mpls` -> `0.615x`
- In the high-confidence slice, ENDIAN overlap geomean is still only `0.899x`.

The strongest evidence is not the tiny direct cases; it is the large Calico overlap slice where ENDIAN appears in nearly every meaningful regression.

#### BRANCH_FLIP

BRANCH_FLIP is the most important non-CMOV family in the trustworthy slice:

- Overall overlap geomean: `0.931x`
- High-confidence overlap geomean: `0.946x`
- Direct high-confidence regression:
  - `calico/from_hep_debug.bpf.o:calico_tc_skb_ipv4_frag`
    - blind run: `1.138x`
    - tuned run: `0.674x`
    - tuned applied family set: `branch-flip`

This is the cleanest current evidence that BRANCH_FLIP needs policy control, not blind apply.

### 1.5 Where the Trustworthy Loss Actually Lives

If I measure regression "mass" as the sum of `-log(ratio)` over regressions:

| Project | Regression mass, all regressions | Regression mass, `>=100ns` only |
| --- | --- | --- |
| `linux-selftests` | 10.924 | 0.348 |
| `calico` | 6.991 | 6.926 |
| `xdp-tutorial` | 3.099 | 0.016 |
| `katran` | 1.265 | 0.000 |
| `libbpf-bootstrap` | 0.539 | 0.000 |

The trustworthy loss is overwhelmingly Calico.

High-confidence non-CMOV regression mass by applied-family combination:

| Applied family combination | Regression mass (`>=100ns`) |
| --- | --- |
| `wide + endian + branch-flip` | 1.566 |
| `extract + endian + branch-flip` | 1.313 |
| `wide + extract + endian + branch-flip` | 1.227 |
| `endian + branch-flip` | 1.049 |
| `branch-flip` | 0.747 |
| `rotate + endian + branch-flip` | 0.541 |

That is the real reason the tuned policy is still below `1.0x`.

Representative high-confidence non-CMOV regressors:

| Program | Stock `exec_ns` | Ratio | Applied families |
| --- | --- | --- | --- |
| `calico/from_hep_debug:calico_tc_maglev` | 181 | `0.582x` | `rotate + endian + branch-flip` |
| `calico/from_hep_debug:calico_tc_skb_icmp_inner_nat` | 172 | `0.628x` | `wide + endian + branch-flip` |
| `calico/to_hep_debug:calico_tc_skb_new_flow_entrypoint` | 189 | `0.668x` | `extract + endian + branch-flip` |
| `calico/from_hep_debug:calico_tc_skb_ipv4_frag` | 176 | `0.674x` | `branch-flip` |
| `calico/from_hep_debug:calico_tc_skb_new_flow_entrypoint` | 170 | `0.711x` | `extract + endian + branch-flip` |
| `calico/to_hep_debug:calico_tc_skb_accepted_entrypoint` | 174 | `0.734x` | `endian + branch-flip` |
| `calico/from_hep_debug:calico_tc_skb_send_tcp_rst` | 177 | `0.734x` | `wide + extract + endian + branch-flip` |
| `calico/to_nat_debug:calico_tc_skb_new_flow_entrypoint` | 172 | `0.741x` | `extract + endian + branch-flip` |

## 2. Per-Family Ablation Gap

### 2.1 What the Current Policy Corpus Actually Does

Current corpus policy files:

| Metric | Value |
| --- | --- |
| Policy files total | 157 |
| Object-level files | 157 |
| Per-program files | 0 |
| Files with `cmov: skip` | 18 |
| Files with any non-CMOV skip | 0 |

So the current shipped corpus policy is:

- object-level
- `cmov: skip` on 18 objects
- blind apply for `wide_mem`, `rotate`, `extract`, `endian`, `branch-flip`, and everything else

### 2.2 Estimated Impact of Adding Per-Family Skip

Because the existing comparison run is confounded, the best current estimate is to use the tuned run itself and ask:

- lower bound: what if I skipped a family only on programs where that family is the only applied family and the program currently regresses?
- upper bound: what if every current non-CMOV regression involving that family were restored to stock?

Those are not causal proofs; they are bracketing estimates.

| Family | Lower-bound direct regressing programs | Raw geomean if all fixed | Upper-bound implicated regressions (non-CMOV) | Raw geomean if all fixed |
| --- | --- | --- | --- | --- |
| `cmov` | 1 | `0.901x` | 0 | n/a |
| `wide` | 0 | n/a | 18 | `0.921x` |
| `rotate` | 0 | n/a | 2 | `0.904x` |
| `extract` | 7 | `0.918x` | 22 | `0.938x` |
| `endian` | 2 | `0.905x` | 34 | `0.945x` |
| `branch-flip` | 10 | `0.914x` | 43 | `0.957x` |

Important implications:

- No single non-CMOV family skip is enough to guarantee a raw `>1.0x` geomean on the current 142-row artifact.
- `branch-flip` has the largest leverage.
- `endian` is the next strongest.
- `extract` has the clearest direct evidence, but many of its current isolated regressors are tiny.
- `wide` is important, but current evidence says "combo-sensitive", not "skip-wide globally."
- `rotate` should not be skipped globally.

Applied-only upper bounds are more optimistic:

- current applied-only geomean: `0.911x`
- if all current non-CMOV `branch-flip` regressions were restored to stock: `1.003x`
- if all current non-CMOV `extract + endian + branch-flip` regressions were restored to stock: `1.049x`

Applied + high-confidence (`>=100ns`) upper bounds are even clearer:

- current applied + `>=100ns` geomean: `0.946x`
- fixing current non-CMOV `branch-flip` regressions -> `1.061x`
- fixing current non-CMOV `endian` regressions -> `1.047x`
- fixing current non-CMOV `extract` regressions -> `0.990x`
- fixing current non-CMOV `wide` regressions -> `0.994x`

So the best first non-CMOV family to tune is BRANCH_FLIP, followed by ENDIAN.

## 3. Sub-Ktime Noise Impact

### 3.1 How Much of the Tuned Run Is Sub-Resolution?

Among the 142 measured programs:

| Stock `exec_ns` bucket | Programs | Geomean | Regressions | Wins | Ties |
| --- | --- | --- | --- | --- | --- |
| `<50ns` | 79 | `0.857x` | 44 | 20 | 15 |
| `<100ns` | 80 | `0.862x` | 44 | 21 | 15 |
| `>=100ns` | 62 | `0.948x` | 40 | 21 | 1 |

Answers to the explicit questions:

- Stock `exec_ns < 50ns`: **79** programs
- Stock `exec_ns < 100ns`: **80** programs
- Geomean filtering to `>=100ns`: **`0.948x`**

### 3.2 Are Regressions Concentrated in Sub-Ktime Programs?

Partly, but not entirely.

What is true:

- 44 of the 84 regressions are below `50ns`.
- 26 regressions are pure no-op rows, and 24 of those 26 are below `50ns`.
- The no-op subset geomeans only `0.873x`, so raw corpus geomean is visibly contaminated by measurement noise.

What is also true:

- 40 of the 84 regressions are already in the `>=100ns` bucket.
- Almost all high-confidence regression mass is in applied Calico programs, not in the tiny no-op rows.

This is the right summary:

- sub-ktime noise explains a lot of the raw corpus loss
- but it does **not** explain all of it
- after filtering to `>=100ns`, the result is still only `0.948x`

## 4. Auto-Tuner Assessment

### 4.1 What `corpus/auto_tune.py` Actually Does

The current auto-tuner is a 5-phase per-program family tuner:

| Phase | What it does |
| --- | --- |
| 1 | Census: discover programs, scan each program, attach packet-test-run measurement targets |
| 2 | Measure all-apply allowlist for each measurable site-positive program |
| 3 | If all-apply regresses, run leave-one-out family skips |
| 4 | Pairwise skip search from the best leave-one-out seeds |
| 5 | Write the best per-program family allowlist policy |

Two important caveats:

- It is **per-program family allowlist** tuning, not site-level tuning.
- It does **not** implement the final "site refinement" phase described in the design docs. `site_overrides` exist in the parser, but the tuner never emits them.

### 4.2 What a Full Run Would Look Like on the Current Corpus

Using the current measurable set as a proxy:

| Quantity | Current estimate |
| --- | --- |
| Measurable site-positive programs | 105 |
| Sum of eligible family counts across those programs | 270 |
| Current regressing site-positive programs (proxy for phase 3) | 64 |
| Sum of eligible family counts across those regressors | 176 |
| Pairwise-combo upper bound with default `combo_top_k=4` | about 181 candidate runs |

So a practical full run today is approximately:

| Phase | Estimated candidate runs |
| --- | --- |
| 1 | one local census scan over the corpus |
| 2 | about 105 VM measurements |
| 3 | about 176 more VM measurements |
| 4 | about 181 more VM measurements |
| 5 | write per-program winners |

Total tuning work: roughly **462 VM candidate measurements**, plus phase-1 scanning.

### 4.3 Runtime and Infrastructure

Current VM execution model:

- each candidate measurement calls `run_target_in_guest()`
- that boots one `vng` guest
- then runs baseline compile-only, v5 compile-only, baseline test_run, and candidate test_run inside the guest

Observed wall-clock cost from the current tuned artifact:

- median guest invocation: about **7.9s**
- p90 guest invocation: about **8.7s**
- one outlier (`res_spin_lock_test_held_lock_max`): about **408s**

So a full run is roughly:

- best-case median estimate: `462 * 7.9s ~= 61 minutes`
- practical estimate with retries/outliers: **1-2 hours**

Infrastructure it needs:

- built `micro_exec`
- built `bpf-jit-scanner`
- `docs/tmp/corpus-runnability-results.json`
- framework kernel image
- matching `vmlinux` BTF
- working `vng`
- enough temporary disk and patience for hundreds of guest boots

The biggest operational risk is not scanner speed; it is repeated VM boot + the few very long-running programs.

### 4.4 Can We Run a Simpler "Stock vs Each-Family-Alone vs All" Sweep?

Yes, and it is probably the best next step.

The current code already has the right primitive: `measure_candidate()` takes an arbitrary family allowlist. Adding a single-family-alone phase is straightforward.

Estimated cost:

| Scope | All-apply trials | Single-family-alone trials | Total candidate runs |
| --- | --- | --- | --- |
| Full measurable site-positive set | 105 | 270 | 375 |
| High-confidence site-positive set (`>=100ns`) | 59 | 198 | 257 |

At the observed 7.9s median guest time:

- full simplified sweep: about **50 minutes**
- `>=100ns` simplified sweep: about **34 minutes**

Why I would run the high-confidence simplified sweep first:

- it directly identifies whether `branch-flip`, `endian`, `extract`, or `wide` is helping on each real program
- it avoids wasting time on the 7ns-20ns noise-dominated rows
- it is easier to interpret than leave-one-out over already-confounded combinations

## 5. Policy Representation Gaps

### 5.1 Current State

Current shipped corpus policies are object-level only:

- 157 files
- 0 per-program files
- 18 object-level `cmov: skip`
- no non-CMOV skips at all

But the infrastructure is already ahead of the artifacts:

- `policy_utils.resolve_policy_path()` already prefers per-program files over object-level files
- `auto_tune.py` phase 5 already knows how to write per-program policy paths
- `policy_config.cpp` already supports:
  - family allowlist / denylist
  - `families: { apply | skip }` shorthand
  - `site_overrides`

### 5.2 Should It Be Per-Program?

Yes. That should be the new default.

Why:

- The current 18 CMOV-skip objects cover 78 measured programs on the shared subset.
- Behavior within one object is not homogeneous.
- Example: `test_tc_tunnel.bpf.o` has both:
  - `__encap_ip6gre_mpls` at `1.429x`
  - `__encap_ip6gre_none` at `0.471x`

An object-level `extract: skip` would throw away the win with the regression. That is already enough to justify per-program policies.

### 5.3 Should It Be Per-Site?

Eventually yes, especially for BRANCH_FLIP and EXTRACT.

Why:

- `policy_config.cpp` already supports `site_overrides`, so the representation is partly there.
- The current auto-tuner does not use it.
- Per-program is enough for the immediate next step, but per-site is the right long-term answer for families where one site helps and another hurts inside the same program.

### 5.4 Missing Knobs

The main missing knobs are:

- per-program policy generation in the actual corpus policy corpus
- site-level tuning in the auto-tuner
- per-site native-choice control beyond enable/disable
- noise/confidence thresholds in the tuner
- budget/priority semantics for overlapping rules
- policy conditions keyed by CPU/workload profile instead of one static allowlist
- baseline reuse or multi-candidate batching in the tuner to reduce VM-boot cost

## 6. Concrete Improvement Plan

### Priority 0: Change the Policy Granularity

Stop generating object-level corpus policies as the primary artifact. Generate per-program policies under:

- `corpus/policies/<project>/<object-stem>/<program>.policy.yaml`

The path plumbing already exists. This is mostly a generation and rollout change, not a kernel or scanner rewrite.

### Priority 1: Tune BRANCH_FLIP First on High-Confidence Calico Regressors

This is the highest-leverage change.

Why BRANCH_FLIP first:

- strongest high-confidence direct evidence
- largest upper-bound leverage
- present in almost every meaningful Calico regression

First-wave candidate policy changes:

- For Calico programs with stock `exec_ns >= 100`, current ratio `<1.0`, and current `branch-flip` application:
  - create per-program policies that skip `branch-flip`
  - keep other families unchanged initially

Special case:

- `calico/from_hep_debug.bpf.o:calico_tc_maglev`
  - blind run with ROTATE only: `1.103x`
  - tuned run with `rotate + endian + branch-flip`: `0.582x`
  - recommended first candidate: keep `rotate`, skip `endian` and `branch-flip`

This is the most likely single policy change family to push the applied/high-confidence result over `1.0x`.

### Priority 2: Tune ENDIAN Next, Still Per-Program

If `branch-flip: skip` is not enough on a program, ENDIAN is the next family to test.

Most suspicious combinations are:

- `endian + branch-flip`
- `wide + endian + branch-flip`
- `extract + endian + branch-flip`
- `wide + extract + endian + branch-flip`

For the current Calico regressors, the second candidate after `branch-flip: skip` should usually be:

- `branch-flip: skip`
- `endian: skip`

or a per-program allowlist that keeps only the families already known to help on that program.

### Priority 3: Add EXTRACT Skips, But Treat Them as Low-Importance Cleanup

EXTRACT has clear direct regressions, but almost all isolated evidence is in tiny `test_tc_tunnel` programs.

Good cleanup targets:

- the 7 regressing extract-only `test_tc_tunnel` functions

This will improve raw counts and reduce obvious family-specific regressions, but it is not the main lever for the trustworthy corpus result.

### Priority 4: Do Not Start by Globally Skipping WIDE or ROTATE

Current evidence says:

- WIDE hurts in combinations, but there is no measured wide-only eligible regression.
- ROTATE-only programs are wins; the bad rotate rows are combination rows.

So:

- do **not** globally skip WIDE
- do **not** globally skip ROTATE
- use per-program tuning on the specific multi-family regressors instead

### Priority 5: Run a High-Confidence Simplified Sweep Before the Full Auto-Tuner

Recommended next experiment:

1. Restrict to measurable site-positive programs with stock `exec_ns >= 100`
2. For each program, measure:
   - all-apply
   - each-family-alone
3. Only for remaining regressors, run:
   - leave-one-out
   - pairwise skip search

This gives direct attribution with manageable cost and avoids spending time on the noisy tiny-program rows.

### Priority 6: Extend `auto_tune.py` Rather Than Replacing It

The current tuner is close to useful. I would add:

1. A single-family-alone phase
2. A minimum stock-`exec_ns` threshold or confidence gate
3. Optional blacklist for pathological long-running programs
4. Site-refinement output via `site_overrides`
5. Baseline reuse across candidates to reduce repeated guest boots

## 7. Bottom Line

If the goal is "make the raw 142-row geomean exceed `1.0x`", policy files alone are probably not enough. The raw result is still polluted by 26 no-op regressions and 80 sub-`100ns` rows.

If the goal is "make the policy-carrying, trustworthy slice exceed `1.0x`", the path is clear:

- per-program policies
- first tune `branch-flip`, then `endian`, on high-confidence Calico regressors
- use a simplified family sweep before the full auto-tuner

That is the highest-probability route from the current `0.898x` artifact to a defensible `>1.0x` result.
