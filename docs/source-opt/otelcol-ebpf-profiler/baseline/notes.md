# Baseline notes

- App: `otelcol-ebpf-profiler/profiling`
- Source state: clean upstream app eBPF source before otel attempts.
- Command: see `run-command.sh`.
- Result: `corpus/results/x86_kvm_corpus_20260625_184535_486633`.
- Primary metric: `language_ops_total`, computed post-hoc from raw component stderr `ops=` values across the 10 interpreter workers in each `otel_mixed_workload` sample.
- Samples: `19476891866, 19704797451, 19752651928`; mean `19644780415`.
- Auxiliary native stress metric: `stress_cpu_bogo_ops_s` samples `1453.54, 1388.62, 1252.65`; mean `1364.94`.
- Gate: app `status=ok`, `error=""`, `baseline.workloads` length 3, all 33 component returncodes 0, `post_rejit=null`, `rejit_result.mode=skip_rejit_all`.
