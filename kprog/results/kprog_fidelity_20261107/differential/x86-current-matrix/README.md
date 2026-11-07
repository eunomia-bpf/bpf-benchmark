# Current full x86 CPU and canonical replay

This run rebuilds the existing complete generated x86 instruction-form matrix
against the production source after088f426a9 and530ce848c, then applies1,024
random register/flag/memory inputs per form on the real CPU and the canonical
reference. It supplements the focused47-stack-sequence replay; it is not a
new ISA model and does not replace application or safety acceptance evidence.

The detached runner uses only existing `make -C kprog/fidelity build`,
`reference-build`, and `reference-check ARCH=x86 CASES=1024` targets on host
CPUs16-19. It retains the current component build at
`kprog/fidelity/build-x86` and reuses the shared warm Lake reference cache;
there is no clean/image/kernel build. A root formal writer is allowed to
finish before the reference build. Source fingerprints, exact commands,
compiler output and later per-form observations are stored here.

```sh
python3 kprog/results/kprog_fidelity_20261107/differential/x86-current-matrix/run.py
```

The complete real-CPU/C stage PASS: **1,077 forms x1,024 inputs =1,102,848
cases, zero architectural-state or memory mismatches**. `forms.tsv` records
all per-form counts; `native-code.json` retains native encodings, and
`cpu-mismatches.jsonl.gz` is the empty counterexample stream. The source
snapshot actually compiled by the existing generator, generatedC/nativeASM
and observer source are preserved in `current-cpu-inputs.tar.gz`, with exact
hashes in `compiled-source-pins.json`. `cpu-summary.json` pins the binary.
The completed build and warm-reference build logs are compressed separately.

The canonical replay completed at11:39:43UTC with exit2: **1,039 forms,
1,063,936 states, zero CPU/reference or C/reference mismatches**. Another38
control-flow observer forms were explicitly `awaiting_reference_block`, not
counted as agreement. `reference-forms.tsv`, `reference-unavailable.jsonl`,
`reference-summary.json` and `state.json` retain every per-form count/status
and the unchanged executable hash. The existing finite-path replay interface
can consume these saved control observer states without rebuilding or rerunning
the CPU matrix; that follow-up is separate. The raw trace no longer has an
active reader and is retained for this follow-up. No complete O1 claim is made.
