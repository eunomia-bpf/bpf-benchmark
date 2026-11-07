# Generic x86 memory-load mechanism: compiled BPF zero extension

Published source: C commit c0b8e9cfaf9298c565c5f35a9ae8f8f25ceec307.
This experiment checks the shared mechanism across application inputs.
The six added casts belong to the BPF preprocessor branch. This check
compiles that branch; the existing 40,260-case host oracle covers host loads.

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
signed offset; its remaining instructions perform register operations and return.
The existing llvmbpf JIT executes those bytes on the x86 CPU; the host build
of the same generic loads and an independent little-endian byte sum receive
the same input. The JIT uses four existing cached llvmbpf objects,
individually hashed in launch.json; the archived executable preserves the
actual linked engine. These observations support shared-mechanism fidelity.
The formal lanes develop the universal safety argument through per-operation,
per-token, binding and native-link preservation theorems; the framework suites
supply kernel-verifier and generation-bound execution results.

From the repository root:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-load-width/Makefile check
~~~

The Makefile reuses the existing runner/build-llvmbpf objects and system LLVM18.
Production generator, simulator, reference ISA, kernel and service retain
their captured identities. The run uses host execution. inputs.tar.gz contains
the actual test sources, both exact Git header snapshots, existing llvmbpf
source snapshot and driver; launch.json also hashes the compiled cached objects.
forms.tsv records every form and all three comparison counts. bytecode.json
records all actual instructions and hashes. The mismatch stream has zero
records; the recorder captures eight input bytes, alignment, sample,
expected/host/JIT values and write indicator for each difference. status.json
records zero source drift. environment.json captures compiler, CPU and dynamic
library identities at review time.

Three initial build attempts ended during compilation and are preserved
completely in attempts.tar.gz: two root-directory errors in the result
Makefile, followed by the llvmbpf/src include-path error. The completed run
uses paths checked against the existing runner build flags, with syntax and
dry-run checks. Production sources and the byte oracle retain their initial
bytes. Cleanup removed the exact owned object produced outside the repository
by the first root error, together with its empty parent directories.

The committed ELF objects and bytecode.json retain all 70 function bodies.
Cleanup verified every extracted slice against both artifacts, verified their
published Git bytes and checked file readers before retiring the 70 temporary
.bin files. The existing extract.py reconstructs these slices during make check;
the warm executable, host object, cached VM objects and complete raw archives
remain available.
