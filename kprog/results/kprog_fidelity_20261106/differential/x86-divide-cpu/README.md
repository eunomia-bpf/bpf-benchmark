# Hardware DIV fault and complete-dividend observations

30 native DIV operand forms ?1024 input states =30720 CPU/C/reference cases,
all agreeing. The CPU raises20784 observed #DE faults and completes9936
instructions normally. Register operands include AL/AH and the other high
bytes, RAX/RDX aliases, REX byte and extended registers at8/16/32/64 bits;
all four memory widths are included. `reference-forms.tsv` records per-form
case/fault/mismatch counts; `forms.tsv` records the CPU/C comparison.

The native wrapper and production simulator/generator are reused. The CPU
executes one actual DIV instruction in a dedicated userspace harness process.
An alternate signal stack prevents its SIGFPE handler overwriting observed
guest stack bytes. The handler accepts only FPE_INTDIV at the exact native
instruction PC, captures all16 GPRs, all6 arithmetic flags, XMM0 and64 stack
bytes, then returns through siglongjmp. All256 external memory bytes are also
compared. Faults preserve architectural state; successful DIV's six undefined
arithmetic flags are excluded. No unsafe accepted kernel-native program runs.

The simulator uses the production arithmetic macro. Only its existing host
fault observation is redirected from fatal trap to state export in this
harness; the production arithmetic, guard and write ordering are unchanged.
Input generation includes zero, overflow, nonzero-high and random dividends.
The canonical published reference at fb7c2b362 independently decides outcomes
from the actual instruction bytes and identical input states; no second ISA
model or Python quotient/flag implementation was introduced.

`observations.jsonl.gz` contains every input, native and simulator state,
memories, fault identity and mismatch bit. `reference-mismatches.jsonl` is
empty. `observer-source.tar.gz` freezes the real observer plus production
header/generator dependencies and generated C/assembly. The static CPU binary,
canonical source/executable, source revision and complete logs are retained.
The production source was V's captured candidate, before publication; this
result identifies exact bytes rather than implying that candidate was HEAD.

The first canonical build captured a HEAD where stale-index recording had
removed81 published DIV reference lines. Its F6 decoder failure is retained
in first-reference-rejected/ with source, hash and failing requests. Rebuilding
from exact good fb7c2b362 yields the full30720-case zero-difference result.
No decoder error was counted as safety rejection or hardware disagreement.

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261106/differential/x86-divide-cpu build cpu
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261106/differential/x86-divide-cpu reference
```

The existing25-program bound safety replay is separate: see
../../negative/x86-divide-fault-fixed/. Its8 #DE negatives now verifier-reject;
the independent x86 stack-base flags acceptance remains an active defect.
This focused result makes no claim that the entire x86 form matrix is closed.
