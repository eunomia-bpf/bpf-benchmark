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

## Completed canonical replay, including all control observers

The same pinned canonical executable now checks **all1,077 forms x1,024 =
1,102,848 states**, with zero hardware/reference or C/reference mismatches
and zero unavailable forms. `canonical-forms.tsv` is the final per-form table;
`canonical-summary.json` joins the three nonoverlapping phases. The initial
38 unavailable records remain historical evidence of the first invocation,
not an unresolved final gap. The37 Jcc/JMP forms contributed37,888 states;
the CALL/stack-read/RET/caller-JMP observer contributed1,024. Both follow-ups
reuse the saved native trace and returned0. No CPU or simulator rebuild was
performed, and the canonical executable SHA is identical in all three phases.

The existing reference adapter now supplies the actual CALL observer's four
instruction extents in executed order and includes its stack cells; the
canonical path interpreter validates every native byte and successor, stack
write, register, modeled flag and final memory. This adds no ISA semantics to
the adapter. Existing `reference-check` and `reference-replay` make targets now
request finite control paths by default. The tested canonical binary is
preserved losslessly as `canonical-reference.gz`.

Exact follow-up commands (after copying the original `forms.tsv` and
`native-code.json` into each OUT directory) were:

```sh
taskset -c 16-19 python3 kprog/fidelity/reference_check.py --reuse-trace --binary kprog/fidelity/build-x86/cpu-differential --arch x86 --cases 1024 --out kprog/results/kprog_fidelity_20261107/differential/x86-current-matrix/control-paths --trace kprog/results/kprog_fidelity_20261107/differential/x86-current-matrix/cpu-states.bin --reference /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen --control-paths --opcode X86_OP_JCC --opcode X86_OP_JMP
taskset -c 16-19 python3 kprog/fidelity/reference_check.py --reuse-trace --binary kprog/fidelity/build-x86/cpu-differential --arch x86 --cases 1024 --out kprog/results/kprog_fidelity_20261107/differential/x86-current-matrix/call-path --trace kprog/results/kprog_fidelity_20261107/differential/x86-current-matrix/cpu-states.bin --reference /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen --control-paths --opcode X86_OP_CALL
```

This is finite randomized x86 architectural evidence for this compiled source
snapshot, not a complete proof of every operand, ABI tag or application path.
ARM hardware execution and its newer logical-immediate form matrix remain
separate work.
