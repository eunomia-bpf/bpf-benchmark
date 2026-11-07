# Final published x86 DIV replay

The exact production simulator, encoder and canonical reference revision is
`a689ff8d69cf3e640f2c14046a2336263a61b162`. All 86 production dependency
files were byte-checked against that Git revision, and all three generated
CPU/negative/positive dependency snapshots were checked against the archive.
Only the F observer adds a second input-generation phase.

| Observation | Cases | CPU/C differences | CPU/reference differences | C/reference differences |
| --- | ---: | ---: | ---: | ---: |
| 30 operand forms, 2,048 states each | 61,440 | 0 | 0 | 0 |
| First phase: original generation rules | 30,720 | 0 | 0 | 0 |
| Added phase: zero high dividend | 30,720 | 0 | 0 | 0 |

The CPU faults 31,506 times and completes 29,934 instructions normally.
The added phase has 19,959 successful zero-high-dividend cases, including
3,840 actual 64-bit high=0 fast-path completions. Faulting source/high-register
aliases are retained. Per-form counts are in `forms.tsv`,
`reference-forms.tsv` and `input-phases.tsv`; all input/output states and
memory bytes are in `observations.jsonl.gz`. No mismatch record is omitted.
The original generation rules remain for each form's first 1,024 states;
this new run advances the random stream through the additional phase too,
so it is not a bit-identical replay of the earlier run. Its historical
observations remain in the 20261106 result directory.

The existing native DIV observer executes actual instruction bytes, accepts
SIGFPE only at the exact instruction PC, uses an alternate signal stack, and
compares 16 GPRs, six arithmetic flags on faults, XMM0, 64 stack bytes and
256 external memory bytes. Successful DIV's undefined arithmetic flags are
excluded. The production fault macro alone is redirected to state export in
the host observer; arithmetic, fault conditions and state write order remain
unchanged. The canonical executable receives the same raw instructions and
states. No second instruction semantics is implemented by F.

The frozen producer/reference sources, generated observer, static native
binary, reference executable, logs and hashes are retained. `reference.gz`
was built from the pinned source using `lake build reference`; its temporary
source/cache export was removed after completion. The separate final bound
safety and valid execution results are in
[../../negative/x86-divide-published/](../../negative/x86-divide-published/).

Commands, through bws.sh from `/workspaces/repository`:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-divide-published build cpu
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-divide-published reference
```

`build` extracts the frozen producer archive into the F build directory;
`reference` can unpack the archived observations and executable on a clean
artifact checkout. Vendor headers/toolchain are the Workspace's existing
ones. The remaining x86 SP counterexamples and reference coverage gaps are
separate active work; this focused DIV result does not close them.
