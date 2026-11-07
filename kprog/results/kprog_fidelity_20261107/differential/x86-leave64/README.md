# Real CPU LEAVE64 state and fault observation

T's current simple JIT wrapper contains C9 LEAVE in its return tail. One
instruction form,8192 random states across8 input classes: aligned/unaligned
frames, last readable word, crossing a protected page, protected frame,
noncanonical frame, NULL frame and valid frame with noncanonical oldSP.
An alternate signal stack captures all16 GPRs/RSP/RBP, RFLAGS, RIP, trap/error
and fault address on faults; normal execution captures the same registers.
Only arithmetic RFLAGS are compared because exception delivery adds RF.
The complete mapped page is checked for writes. No unsafe kernel/native
program is loaded; this isolated userspace instruction observer has completed as recorded below.

The native observer restores its own stack only after capturing all target
registers. Cases retain all inputs/outputs and the accessible operand bytes.
Success is compared with Intel's LEAVE64 operation; fault precision is
measured, not assumed equivalent to two separate instructions. Canonical
LEAVE and complete CPU/reference comparison remain pending.

Primary specification: [Intel SDM Vol2](https://cdrdv2-public.intel.com/671110/325383-sdm-vol-2abcd.pdf), LEAVE.

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64/Makefile run
```

## Completed native observation

Final -Wall/-Wextra/-Werror static build and real-host execution exited0:
8192 states =4096 normal completions +4096 faults. Normal register results
agree with LEAVE64; no mapped-page memory changed. All4096 faults preserve
ALL16 incoming GPRs, including the OLD RSP/RBP, and arithmetic flags.
`forms.tsv` breaks down the8 input classes; `summary.json` records signal and
trap classes. Full raw inputs/outputs and readable operand bytes remain in
`cases.jsonl.gz`. Signal contexts include raw exception-delivery RFLAGS;
arithmetic comparison masks0x8d5 rather than treating delivery RF as an
instruction output. `native.asm.gz` shows the actual C9 observation span.

The initial completed build's longjmp-local warning and its results are
preserved as initial-*.gz. The final observer isolates sigsetjmp in an
execute frame; the full8192-case rerun builds without warnings under Werror.
Canonical LEAVE decoder/state/fault comparison remains for V/T's single ISA;
this hardware evidence establishes the measured fault rollback and normal
state behavior, not a whole JIT/ABI proof or simulator LEAVE support claim.
