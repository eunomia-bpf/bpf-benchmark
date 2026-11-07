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

`state.json` and F/matrix-current.state record progress. The compiler is
currently active; no all-form mismatch/coverage total is claimed before its
CPU/reference stages complete. Eventual `forms.tsv`, mismatch inputs and
reference status must be read together. Any unsupported reference encoding or
source drift is retained explicitly, not counted as agreement or hidden.
Build and replay logs are separate, and the full dataset stays intact on a
mismatch. Do not start another writer for this current build while it runs.
