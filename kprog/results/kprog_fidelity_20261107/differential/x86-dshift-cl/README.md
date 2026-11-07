# SHLD/SHRD CL hardware and canonical replay

The production x86 encoder and current C simulator agree with the real x86-64
CPU and V's canonical reference on 32 native CL-count forms, exercised through
both raw and direct APIs. The 64 route/form groups contain 65,536 shared-state
CPU/C/reference observations, with zero differences and zero forms awaiting
reference.

| Operation | Width | Route | Forms | Cases | Differences CPU/C/reference |
| --- | ---: | --- | ---: | ---: | --- |
| X86_OP_SHLD_IMM | 32 | direct | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHLD_IMM | 32 | raw | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHLD_IMM | 64 | direct | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHLD_IMM | 64 | raw | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHRD_IMM | 32 | direct | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHRD_IMM | 32 | raw | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHRD_IMM | 64 | direct | 8 | 8,192 | 0 / 0 / 0 |
| X86_OP_SHRD_IMM | 64 | raw | 8 | 8,192 | 0 / 0 / 0 |

Each operation and width covers eight destination/source combinations: distinct
registers, the same register, RCX destination, RCX source, RCX in both positions,
RSP destination, RSP source, and RSP in both positions. The CL byte comes from
the actual prestate, including aliases that also supply the value operands.
observations.tsv gives every form's counts and effective-count histogram.

Every 32-bit group observes all counts 0–31; every 64-bit group observes all
counts 0–63. Count 0 occurs 1,567 times and count 1 occurs 1,527 times across
the 64 groups. All 65,536 memory observations retain their original bytes.
The existing observer compares architectural GPRs, modeled vector/stack state,
defined arithmetic flags and memory. reference_check.py supplies the canonical
defined-flag mask and final-PC checks. Raw/direct groups share the existing
advancing fixed-seed stream; each CPU/C/reference tuple uses the same input.

## Source and artifact identities

All 93 files in the actual-compilation archive match its manifest. Its 82
production snapshot inputs match launch Git 7a3c371961132b24e8a064d5167ec3e39e1ed0e9
byte for byte. The existing production encoder recreates every captured encoded
field exactly; all 32 raw/direct pairs have identical actual native bytes.
The observer, flag masks and simulator sources retain their launch inputs.
The launch source-drift map is empty.

| Artifact | SHA-256 |
| --- | --- |
| Static x86 observer | e5e5a54ce159ffe215db7523cd91a61bb6662e463111ac1ca9ac8718403fa16b |
| Canonical executable | c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96 |
| Full 119,013,400-byte trace | 957e4496265ab1ba04d05466908459288467a7c632f2ac052511528f05a483c6 |

actual-compiled-inputs.tar.gz retains generated C/native assembly, the complete
production include snapshot, driver and encoded fields. launch-inputs.tar.gz
retains the launch reader/generator/headers and job wrapper.
cpu-differential-x86.gz is the exact static observer. The full trace remains in
the Workspace alongside these records. Existing canonical source/executable
archives are shared with the published c110b03a replay cohorts.

The initial selector assertion included the shared generator's appended branch
and REP fixtures. initial-attempt.tar.gz retains that source/run. The final
selector retains the requested CL forms and duplicates each across raw/direct
entry APIs. Both APIs preserve the production encoding. The final detached job
3692138 exited 0 at 2026-11-07T20:24:20.612759+00:00.

## Commands

Run from /workspaces/repository:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-dshift-cl/Makefile reference
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/differential/x86-dshift-cl/review.py
~~~

The existing incremental fidelity Makefile builds the selected observer. The
result Makefile uses the retained frozen canonical executable at
/workspaces/.agent-state/kprog-lanes/F/reference-control-frozen.
review.py checks the archived source manifest, production Git inputs, every
encoded field/native-byte pair, complete trace and per-form tables before
writing summary.json and observations.tsv.
