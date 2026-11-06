# Actual ARM Katran and OTel runtimev8 attempts

The unchanged two-start workloads ran under full-system QEMU TCG. Katran
run `arm64_qemu_corpus_19700101_000109_245314` returns one baseline program
counter row; OTel run `arm64_qemu_corpus_19700101_000008_240450` returns12.
Both native starts fail, with zero native counter rows and no bound replacements.
All31 startup attempts are retained:27 loaded, two failed and two unfinished.

Katran first fails to find the simulator for actual `balancer_ingres`
(BTF symbol `balancer_ingress`), before its root program can be replaced.
The previously passing root fixture therefore does not establish application
coverage. OTel first fails to find the simulator for `read_task_struc`
(BTF `read_task_struct`). Its later measurement socket refusal is retained.
The next runtime includes the newly generated actual Katran balancer proof;
OTel's corresponding original-map proof is being generated. Neither program
is excluded from the coverage denominator.

The two packaged-input archives contain the exact manifests and native/proof/
simulator payloads exported from this image before staging changed. The raw
run archives include app errors, stdout/stderr, lifecycle and shim logs and
per-program baseline counters. The CSV/table files index those raw records.
The image uses the published9962aec5e shim: feature probes load unchanged;
resident native programs still require generation-bound proofs. Runtimev8
uses the earlier paired-context-v2 kernel and context-v2-source-map library.

The portable application launcher was exercised through OTel's real startup
and workload. Its first invocation used the invalid bare OTel selector;
the outer failure and captured serial excerpt remain. That first full serial
file was overwritten before capture, explicitly recorded in the excerpt.
The corrected `otelcol-ebpf-profiler/profiling` invocation has its complete
serial log. Subsequent replay invocations archive the prior serial and host
identity automatically. These QEMU times are functional, not hardware performance.

Runtimev9 has been built with the matching new exclusive-choice kernel,
all11 kinsn modules and loader. Runtimev8's exported root/image can now be
retired after this raw record is committed; the exact inputs and all collected
raw results remain here.
