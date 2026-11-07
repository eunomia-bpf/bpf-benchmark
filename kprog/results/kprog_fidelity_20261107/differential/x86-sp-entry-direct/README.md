# Published direct-SP repair: independent CPU replay

C's published f734ec402 fixes eight of the eleven previously observed SP
differences. Three forms still differ on every tested state. This replay
uses the real CPU entry stack base in the F observer's simulator state,
matching the existing ABI2 input rather than assuming a zero native SP.

| Form | Cases | CPU/C differences | CPU/reference differences |
| --- | ---: | ---: | ---: |
| mov rax, rsp | 1,024 | 1,024 | 0 |
| lea rax, [rsp+16] | 1,024 | 1,024 | 0 |
| mov rsp, rax | 1,024 | 1,024 | 0 |
| mov eax, esp | 1,024 | 0 | 0 |
| cmp rsp, 0 | 1,024 | 0 | 0 |
| mov esp, eax | 1,024 | 0 | 0 |
| lea rsp, [rsp+16] | 1,024 | 0 | 0 |
| add rsp, 16 | 1,024 | 0 | 0 |
| push rsp / pop rsp / push sp / pop sp | 4,096 | 0 | 0 |

All twelve forms, 12,288 CPU/reference cases, agree with V's exact47de9665d
native-byte semantics. C/reference retains the same 3,072 differences as
CPU/C. Per-form tables and every mismatch's input/CPU/C/reference state are
retained in the compressed JSONL files. Another 42 auxiliary observers pass
43,008 CPU/C cases; they were not canonically replayed here. Total CPU/C:
54 forms, 55,296 cases, 3,072 differences. Exit1 is the expected actual
mismatch result, not an infrastructure success or a safety rejection.

The two source changes in generate.py only declare and populate the existing
native_stack_base state field from the hardware wrapper's saved base. The
production simulator/headers and all other frozen producer sources are
byte-identical to published f734ec402. The first preparation lacked the
new native_lab_input.h dependency and failed before CPU execution; its exact
source and diagnostic remain under first-infrastructure/. The retry adds
that published dependency. Concurrent ROOT stack-write work is excluded.

At case0, native entry SP is 0x7ffdb9d8b910. MOV RAX,RSP returns that value
natively but C exposes its private arena address 0x7ffdb9d8b930. LEA with
+16 similarly exposes 0x7ffdb9d8b940 instead of 0x7ffdb9d8b920. MOV RSP,RAX
with input RAX=0 should leave normalized RSP=0xffff8002462746f0; C leaves0.
These are numeric projection/writeback bugs. A private F candidate is being
checked separately; this directory remains the unmodified production
baseline. No unsafe kernel-native body was executed in this experiment.

All observed GPRs, six defined arithmetic flags, XMM0, 64 stack bytes and
256 external-memory bytes are compared. For these PUSH/POP cases, the
wrapper normalizes its private RSP slot and restores its host frame before
observation. The raw internal stack pointer aliases are retained in the
baseline, exposing the missing architectural projection.

Commands through bws.sh from /workspaces/repository:

```sh
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-sp-entry-direct build cpu
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-sp-entry-direct reference
```

Both comparisons return nonzero for the three real differences. The recipe
uses a new fresh-run/ directory; future runs have new native addresses and
must not be described as the same saved states. Canonical source/executable
are retained in sibling x86-multiply-xchg. Per coordinator disk instruction,
the completed raw trace is retired after this summary is committed and no
readers remain. Its hash/size are recorded; all mismatch inputs stay saved.
