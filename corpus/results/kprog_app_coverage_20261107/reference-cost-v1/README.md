Archived preparation: cost attribution was deferred by the operator at07:23 UTC; no new profile is scheduled.

# Localizing the historical Tetragon gap

Inputs are the May29 stats-enabled reference run `x86_kvm_corpus_20260529_045551_393389` and R's Nov7 stats-enabled run `x86_kvm_corpus_20261107_002003_274609`. Both app records report completed statusok. The archived analysis in `kprog/docs/archive/native_eval_20260529.py` keeps records with at least100 invocations for its aggregate; the family observations below use that same existing rule. `all-program-records.csv` retains all1148 source records, including zero/low-count rows. No new run-admission or discard rule is introduced.

| Observed family | May JIT ns/run | May native ns/run | Nov JIT ns/run | Nov native ns/run |
|---|---:|---:|---:|---:|
| kprobe, truncated name generic_kprobe_ |895.18|56.13|981.53|952.63|
| tracepoint, truncated name generic_tracepo |722.74|662.40|765.42|761.94|
| kprobe, truncated name generic_retkpro |50.84|47.93|48.81|48.92|

These are invocation-weighted family observations, with exact sizes, record counts and numerators/denominators in `families.json`. The missing historical native benefit is concentrated in the generic-kprobe family. The May generic-kprobe native body is1560B, versus2047B in the Nov run; the JIT sides are1875B/1879B with3304 translated bytes. The return-kprobe Nov native-side records remain15275B, matching that run's BPF-side size, while May native-side records are13417B. Actual replacement identity and hook/policy association require their own retained objects or live metadata; these truncated names/sizes do not pair program IDs across runs.

The per-run `/dev/null` control already collected by C exercises a particular live generic-kprobe instance. Its217.63/222.44ns JIT/native result is a different controlled invocation from the historical mixed-stressor family above. It cannot by itself assign the full historical family gap to an entry shim, helper, filter or output block. Further profiles are deferred by the operator's current priorities.

Source near the historical run also contains the first-unused-source-map selection repaired in a4d37a890. The selector is recorded by its source/hash in `inputs.json` at9f3855f6f (the last source commit by time before the recorded May run). The raw app metadata does not pin that commit/image/native byte sequence, so its presence is a concrete historical source observation and does not establish that it caused the May timing. Historical raw observations are retained unchanged.

The existing policy `runner/assets/tetragon_policies/fd_install_cap_changes.yaml` uses capability-change filtering. Further work will record app-owned successful policy event submissions (`policy_stats.act_cnt[POLICY_POST]`) and kernel send failures (`tg_stats_map.sent_failed`, by message opcode/reason), plus helper error metrics. Upstream increments POLICY_POST after successful perf/ring submission. These counters measure kernel submission; userspace delivery is a separate quantity. Collection uses the unchanged application launch/policies and occurs outside perf windows. This supplies concrete work evidence for interpreting the next event-arg/filter/ring-buffer comparison without changing the workload or adding a validity gate.

Reproduce the analysis with `python3 corpus/results/kprog_app_coverage_20261107/reference-cost-v1/analyze.py`. Input hashes and the nearby-source provenance are in `inputs.json`. This directory makes no claim of restored historical speedup or complete six-app verified-path acceptance.
