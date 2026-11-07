# Current trusted loader tail-map registration regression

Replay 38 unchanged native-only safety cases; negatives are LOADONLY after common loader commit3d0e584b5.
Same native/source objects, producer, simulator, generator, native-link,
kernel and module as the preceding x86 run. Only the trusted loader binary
and common C++ source changed. Fresh output keeps old requests intact.
No build, workload change, timing or speedup claim. Completed:38/38 cases:9 safe controls executed,29 unsafe programs rejected
(22 verifier,6 specialization,1 loader). Zero unsafe accepted or executed.
The guest Make exited0. Every native input matches the kernel-owned copy;
all generated native copies present match too. All request source identities
and host input hashes stayed stable. results.tsv retains each exact rejection
message and outcomes.json.gz the complete raw result. run-post-tail-map.tar.gz
retains all38 request archives, logs and input identities. No timing claim.

```sh
taskset -c 16-23 make -f kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/Makefile kvm RUN_OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/post-tail-map
```
