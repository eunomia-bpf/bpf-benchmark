## Observed deltas (cilium)

Doc baseline source:

- `docs/evaluation-05-07-2026.md` section 6.1.1.
- KOperation/doc multi-pass result: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260507_200821_664435`.
- Map-inline/doc result: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260507_195045_528717`.
- Prefetch/doc result: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260507_224441_710356`.

Current evidence sources:

- 5-pass kop: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_190158_334233`.
- Prefetch-only: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_185702_727232`.
- `noop,map_inline`: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_185218_803256`.

Observed cilium deltas:

| pass | doc baseline | current actual | delta | main assignment | confidence |
|---|---:|---:|---:|---|---|
| `cond_select` | 208 applied / 218 matched | 20 applied / 22 matched | -188 applied / -196 matched | code regression in `cond_select`/BBProgram diamond handling | high |
| `bulk_memory` | 5 / 5 | 0 / 0 | -5 / -5 | downstream casualty of `cond_select` aborts, not proven bulk-specific | high for casualty, low for bulk-specific regression |
| `endian_fusion` | 24 / 24 | 0 / 0 | -24 / -24 | downstream casualty of `cond_select` aborts | high |
| `prefetch` | 430 / 430 | 411 / 416 | -19 applied / -14 matched | live program set plus current skip behavior | high |
| `map_inline` | 1454 / 1824 | 1452 / 1865 | -2 applied / +41 matched | small map-inline/ReJIT side effect, not version drift | medium |

Important raw observations:

- The doc kop run used pass order `rotate,cond_select,extract,endian_fusion,bulk_memory,skb_load_bytes_spec,wide_mem`.
- The current 5-pass run used `rotate,cond_select,extract,endian_fusion,bulk_memory`.
- In the doc kop run, cilium had 53 programs and no `failed_bpfopt:cond_select`.
- In the current 5-pass run, cilium had 60 programs, `cond_select=20/22`, and 37 `failed_bpfopt:cond_select` failures.
- The current `cond_select` bpfopt failure is consistently `error: diamond join BlockId(...) has external predecessor BlockId(...)`.
- The current 5-pass extra programs relative to the doc kop run are duplicate live cilium programs: `cil_from_host:1194` x2, `cil_from_netdev:1113` x1, `cil_host_policy:2` x2, `cil_to_host:351` x1, and `cil_to_netdev:1281` x1.
- The current prefetch-only and `noop,map_inline` runs each have 53 programs, and their program name plus instruction-count multisets match the relevant May 7 baselines except for the known prefetch live-set difference.

## Hypothesis 1: methodology mismatch (multi-pass vs isolated)

The hypothesis as stated is not supported for `cond_select`, `bulk_memory`, or `endian_fusion`.

The May 7 doc kop source run did include `wide_mem`, but `wide_mem` was last in the pass list. It could not have produced upstream bytecode for `cond_select`, `bulk_memory`, or `endian_fusion`. It also reported `wide_mem=0/0` for cilium, so there is no evidence that `wide_mem` generated the missing sites.

The doc kop run also included `skb_load_bytes_spec`, but it was after `bulk_memory` in the configured order. It likewise cannot explain missing `cond_select`, `bulk_memory`, or `endian_fusion` opportunities.

The 60 vs 53 program-count difference in the current 5-pass run is real, but it points to live discovery/workload topology rather than the pass-composition explanation. Extra duplicate programs would normally increase candidate opportunities. They do not explain why `cond_select` collapsed from 208/218 to 20/22.

The decisive signal is that the current run aborts `cond_select` on 37 cilium programs with a bpfopt error before later passes can see those programs. The doc run had no `failed_bpfopt:cond_select` failures. That is not a normal multi-pass vs isolated accounting difference.

This hypothesis does partially explain `prefetch`:

- The doc prefetch run had 56 cilium programs.
- The current prefetch run had 53 cilium programs.
- Missing `cil_from_host:1194` accounts for 13 applied sites.
- Missing `cil_to_host:351` accounts for 4 applied sites.
- `cil_host_policy:2` contributes 0.
- Two current `cil_lxc_policy:2446` skips account for the remaining 2 applied-site loss.

So the `prefetch` delta of -19 is explainable without a pass-code regression: -17 from live program-set difference and -2 from current skip behavior.

This hypothesis only weakly explains `map_inline`. The doc and current `noop,map_inline` program multisets are identical. The current run lost six applications from two `tail_drop_notif:88` programs that failed at `noop` ReJIT, while gaining four applications on `tail_handle_ipv:227`; the net applied delta is -2. That is not a multi-pass kop methodology issue.

## Hypothesis 2: upstream cilium version drift

This hypothesis has low support.

The current Dockerfile pins cilium to:

`quay.io/cilium/cilium:v1.19.3@sha256:2e61680593cddca8b6c055f6d4c849d87a26a1c91c7e3b8b56c7fb76ab7b7b10`

The same pin is present in the May 7-era Dockerfile checked from the repository history. That rules out a simple upstream image tag moving under the benchmark.

Program-shape evidence also argues against version drift:

- The doc kop 53-program cilium snapshot and the current 53-program snapshots have matching name plus original-instruction-count multisets.
- The doc and current `noop,map_inline` snapshots have identical cilium program multisets.
- The current 5-pass 60-program run differs by duplicate live programs, not by new program bytecode shapes.

Workload-level behavior is also comparable. The doc kop baseline cilium workload recorded roughly 4203 requests and 139.95 requests/sec with 37 socket timeouts; the current 5-pass baseline recorded roughly 4326 requests and 144.01 requests/sec with 35 socket timeouts. That looks like normal runtime variance, not an upgraded cilium agent generating a different datapath corpus.

The `prefetch` program-count difference is better explained by live endpoint/program discovery during the run than by a cilium version change.

## Hypothesis 3: cleanup code regression (which tasks)

This hypothesis is strongly supported for the large kop deltas.

The current failure mode is specific and new relative to the May 7 baseline:

- May 7 doc kop: `cond_select=208/218`, no `failed_bpfopt:cond_select`.
- May 12 5-pass kop: `cond_select=20/22`, 37 `failed_bpfopt:cond_select`.
- May 12 full default-policy run found during investigation: `cond_select=21/23`, about 30 `failed_bpfopt:cond_select`, `bulk_memory=0/0`, `endian_fusion=0/0`.
- May 12 six-pass run found during investigation: `cond_select=19/21`, about 31 `failed_bpfopt:cond_select`, `bulk_memory=0/0`, `endian_fusion=0/0`.

The repeated error is:

`diamond join BlockId(...) has external predecessor BlockId(...)`

That error maps to current `validate_diamond()` in `crates/bpfopt/src/analysis/bbprogram_api.rs`. `cond_select` tries to apply a diamond replacement and now lets this validation error escape as a pass failure. The current site selection in `cond_select` can pick a join block with an external predecessor, which trips the stricter diamond validator.

Relevant cleanup points:

- Task 17 / Terminator probe rename rollback: no exact matching named commit was found in `git log --oneline 44be6efb..HEAD`. The relevant terminator/diamond behavior appears tied to the earlier BBProgram diamond validation work plus later `cond_select` mutation changes.
- Task 18 / `try_mutate` consolidation: commit `a8c5b966` added/used the shared `try_mutate` wrapper in BBProgram mutation paths. This is not the strongest root-cause candidate because the observed error is a semantic diamond-validation rejection, but it is near the affected mutation boundary.
- Task 21 / `bulk_memory` width helpers: commit `a8c5b966` also changed width helper structure. The current dirty `bulk_memory.rs` diff is behavior-equivalent (`!is_some()` to `.is_none()`). This is low confidence as a bulk-specific cause. The stronger explanation is that `cond_select` aborts before `bulk_memory` gets to inspect many programs.
- Task 22 / `hex_bytes` merge: current `map_inline` byte-preview formatting uses `hex_bytes`. This is diagnostics-only and low confidence for any applied-count delta.
- Task 6 / `classify_r0_uses` bool parameter consolidation: `git log -S allow_helper_calls` points to `9a61ab1a`, which collapsed related helper-call booleans. This could plausibly affect `map_inline` candidate/skipped accounting, but it does not explain the kop collapse. Confidence is medium-low for the small `map_inline` delta and irrelevant for `cond_select`.

Commits in `44be6efb..HEAD` that touched relevant surfaces include:

- `9a61ab1a` around `map_inline` helper-call classification.
- `b42632e0` around pass test cleanup.
- `3969eb16` around kop-related cleanup.
- `b7e1b3a8` around `KopDescriptor` naming.
- `a8c5b966` around mutation consolidation and width helper cleanup.

One important caveat: the strict `validate_diamond()` introduction appears to predate `44be6efb` and postdate the May 7 baseline. So the root cause may be just outside the requested `44be6efb..HEAD` window, with later cleanup commits exposing or preserving the behavior.

## Verdict + confidence

`cond_select`: code regression, high confidence.

The 188-applied-site drop is not explained by pass methodology, `wide_mem`, or cilium version drift. It is explained by 37 current `failed_bpfopt:cond_select` errors on cilium programs where the May 7 doc run had none. The failure text points directly at BBProgram diamond validation and `cond_select` join selection/mutation behavior.

`bulk_memory`: downstream casualty of `cond_select` aborts, high confidence for casualty, low confidence for a standalone `bulk_memory` regression.

Because the pass sequence runs `cond_select` before `bulk_memory`, the current bpfopt abort prevents later passes from seeing many cilium programs. The current inspected `bulk_memory` cleanup is behavior-equivalent and not a strong standalone explanation.

`endian_fusion`: downstream casualty of `cond_select` aborts, high confidence.

The same pass-order argument applies. There is no evidence that `wide_mem` generated the May 7 `endian_fusion` sites; `wide_mem` ran later and had 0/0.

`prefetch`: live program set plus skip behavior, high confidence.

The -19 applied delta is accounted for by missing live programs in the current run and two current skips in `cil_lxc_policy`. This does not require cilium version drift or a prefetch code regression.

`map_inline`: small map-inline/ReJIT behavior drift, medium confidence.

The -2 applied delta happens with an identical program multiset. Current `noop` ReJIT failures remove six `tail_drop_notif:88` applications and other per-program differences add four back. `9a61ab1a` is the most relevant cleanup candidate for map-inline matching/skipping, but the observed net delta is small and mixed.

Overall verdict:

- The large kop mismatch is a real code regression in the current bpfopt `cond_select`/BBProgram diamond path.
- The doc-vs-current methodology difference is not the cause for `cond_select`, `bulk_memory`, or `endian_fusion`.
- Cilium upstream version drift is unlikely.
- `prefetch` should be treated separately as a live-program-set/skipping delta.
- `map_inline` should be treated as a small secondary drift, not part of the kop failure.

## Recommended verification path

1. Do not start with a full default-policy rerun. A current full default-policy result already reproduces the `cond_select` collapse, so it confirms the problem is not unique to the 5-pass run but does not isolate the cause.

2. Bisect or compare in a separate worktree instead of making revert/restore commits. Use the same cilium-only 5-pass command through `make`:

`BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=rotate,cond_select,extract,endian_fusion,bulk_memory SAMPLES=1 make corpus`

3. First compare the commit before strict diamond validation with the strict-validation commit. This is the highest-yield cut because the current error text is emitted by `validate_diamond()`.

4. Then compare `44be6efb^` vs `44be6efb`, because current `cond_select` trial mutation behavior is in that neighborhood and is inside the requested cleanup range.

5. Only after the kop root cause is isolated, compare `9a61ab1a^` vs `9a61ab1a` with `BPFREJIT_BENCH_PASSES=noop,map_inline` if the small `map_inline` -2 applied delta still matters.

6. Treat `a8c5b966` as lower priority. It touches mutation and width-helper structure, but the current evidence points more strongly to `cond_select` diamond validation than to `bulk_memory` width decoding.

7. Use the host-side testbin corpus as a fast bpfopt-only triage step for the same pass lists. It is useful for reproducing `diamond join ... external predecessor` without kernel, app startup, or ReJIT noise. It cannot validate cilium live program discovery, map snapshots, or kernel ReJIT failures, so it should complement but not replace the cilium `make corpus` comparison.

8. Run full default policy only after a candidate fix or candidate culprit is identified, using:

`BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=default SAMPLES=1 make corpus`

This should be used as a confirmation check against the paper/default policy, not as the primary localization tool.
