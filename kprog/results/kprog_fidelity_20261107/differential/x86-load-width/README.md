# Generic x86 memory-load mechanism: compiled BPF zero extension

Published source: C commit c0b8e9cfaf9298c565c5f35a9ae8f8f25ceec307.
This experiment checks the shared mechanism, independent of application programs.
The six added casts are under the BPF preprocessor branch, so repeating the
existing 40,260-case host-only oracle would not exercise the changed branch.

| Measurement | Before | Current |
| --- | ---: | ---: |
| Enumerated mechanism forms | 35 | 35 |
| Input states | 286,720 | 286,720 |
| BPF JIT versus independent byte oracle differences | 0 | 0 |
| Host CPU load versus byte oracle differences | 0 | 0 |
| BPF JIT versus host CPU load differences | 0 | 0 |
| Memory modifications | 0 | 0 |

Each source variant covers five width arguments (0 defaults to 64 bits,
then 8/16/32/64 bits), the ordinary load, and fixed loads at offsets
-32768, -3, -1, 0, 88 and 32767. Each form runs 1,024 inputs at all eight
byte alignments: zero, all ones, high bits, alternating bytes and fixed-seed
random bytes. The complete 65,560-byte arena is compared after every run.

Both header versions are compiled with real Clang 18 BPF inline assembly.
Each extracted function has exactly one width-correct LDX with the expected
signed offset, no stores, calls or branches, and a return. The existing llvmbpf
JIT executes those bytes on the x86 CPU; the host build of the same generic
loads and an independent little-endian byte sum receive the same input.
The JIT uses the four existing cached llvmbpf objects, individually hashed in
launch.json; the archived executable preserves the actual linked engine.
This is empirical mechanism evidence, with no per-program proof/certificate,
no kernel verifier or generation-bound acceptance claim, and no discharge of
the generic safety obligations.

From the repository root:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-load-width/Makefile check
~~~

The Makefile reuses the existing runner/build-llvmbpf objects and system LLVM18.
No production generator, simulator, reference ISA, kernel, service or guest was
changed. inputs.tar.gz contains the actual test sources, both exact Git header
snapshots, existing llvmbpf source snapshot and driver; launch.json hashes the
compiled cached objects as well. forms.tsv records every form and all three
comparison counts. bytecode.json records all actual instructions and hashes.
mismatches.jsonl is empty; a mismatch records its eight input bytes, alignment,
sample, expected/host/JIT values and write indicator. status.json records zero
source drift.

Three initial build failures are preserved completely in attempts.tar.gz:
two root-directory mistakes in the new result Makefile, then the omitted
llvmbpf/src include directory. None reached execution or produced a semantic
mismatch. The paths were corrected against the existing runner build flags,
with syntax and dry-run checks; production sources and the oracle were unchanged.
A stray object produced outside the repository by the first root error was
removed by its exact owned path, along with empty parents.
