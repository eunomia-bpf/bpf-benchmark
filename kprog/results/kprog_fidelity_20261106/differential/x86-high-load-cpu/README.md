# Additional real-CPU sign-high and high-byte memory forms

The expanded production CPU/C matrix executes816 forms ?1024 states =835584
cases. All17 added forms agree in17408 cases: CBW/CWDE/CWD/CDQ/CQO and all4
high-byte MOV_LOAD destinations against2 external bases and the modeled stack.
`added-forms.tsv` records each new form; `forms.tsv` retains every denominator.

806 forms have zero differences. Ten existing SP-address rows retain10240
mismatches: MOV RSP to64/32-bit register, LEA from RSP, CMP RSP, MOV64/32 to
RSP, and PUSH/POP RSP/SP. These are open fidelity defects. Their inputs, all
poststates and memory bytes are in `mismatches.jsonl.gz`; no counterexample was
normalized away. This run captures the current production simulator/encoder,
including V's arithmetic candidate, with frozen dependencies in
`observer-source.tar.gz`. Complete static CPU executable and Make build/run
logs are retained. All6 arithmetic flags are compared when architecturally
defined, using the same existing wrapper/driver and fixed seed.

The earlier published799-form MOVX canonical result checks551 forms/564224
cases with CPU0/modelSP10240 and248 remaining reference encodings/blocks.
Its exact rows and source are retained in ../x86-movx-reference/. That older
matrix did not contain the17 new forms reported here.

The expanded canonical replay now checks571/816 forms and584704 identical CPU
states against exact published fb7c2b362: zero CPU/reference differences and
9216 simulator/reference differences across9 SP rows. All17 added forms
(17408 cases) agree with both CPU and canonical reference. The remaining245
forms are244 decoder encodings and1 CALL block. `reference-forms.tsv` records
every status; `reference-unavailable.jsonl.gz` preserves each exact request
and diagnostic. `reference-mismatches.jsonl.gz` retains all9216 inputs and
poststates. The tenth raw CPU/C SP row, `lea rax,[rsp+16]`, is among the missing
LEA decodings; it was not fixed or waived by the smaller canonical count.
The immutable trace remains in this Workspace (`cpu-states.bin`, hash
recorded), and reference-run.log.gz retains the nonzero Make result.

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261106/differential/x86-high-load-cpu build cpu
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/x86-high-load-cpu reference
```

The CPU target exits nonzero to preserve the10240 differences. The reference
command uses the pinned executable from ../x86-divide-cpu/ and the frozen CPU
trace; rebuild the trace explicitly before reuse if only the published
artifacts are available. No microbenchmark workload or production semantics
were changed by this harness increment.
