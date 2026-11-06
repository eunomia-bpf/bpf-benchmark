# Preserved LDR D0 upper-half finding

235 production-encoder forms ×256 QEMU states =60160 cases;3328 differences
on the13 D0-load addressing rows, with all other222 rows agreeing. Every D0
load returned the correct low64 bits but preserved the incoming high64 bits.
CPU and canonical reference clear the high64 bits. The saved-state canonical
replay checks all235 forms: CPU differences0, simulator differences3328, no
missing encoding. Every mismatch retains its complete register/flag/vector/
memory input and CPU/C/canonical output in the compressed JSONL files.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-addressed-memory FAMILY=memory CASES=256 OUT=../results/kprog_fidelity_20261106/differential/arm64-memory-matrix
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-memory-complete before-reference
```

Both return1 for the retained differences. The exact old generated C/native
assembly, header snapshot and executable are archived; the publication-time
generator includes subsequent20 pair forms and the exclusive fixture hook.
The canonical executable is frozen in ../arm64-memory-complete/. The permanent
bound negative, fix and255-form clean replay are documented there. This initial
235-form result is superseded for production correctness, never discarded.
