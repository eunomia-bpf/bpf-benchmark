# Generic register-read BPF lowering observations

C candidate b756ee85 is compared with the original register-read header using
actual Clang18/mcpuv4 BPF objects, the cached llvmbpf JIT on x86-64, direct native
MOVZX/MOV reads, the host macro branch and an independent byte oracle.

| Measurement | Before | Candidate |
| --- | ---: | ---: |
| Macro parameter forms | 20 | 20 |
| Input states | 6,717,440 | 6,717,440 |
| BPF JIT versus byte oracle differences | 0 | 0 |
| Native CPU versus byte oracle differences | 0 | 0 |
| Host macro versus byte oracle differences | 0 | 0 |
| BPF JIT versus native CPU differences | 0 | 0 |
| Memory modifications | 0 | 0 |
| Guarded indexed reads taken | 123,242 | 123,242 |

The total is13,434,880 observations. Each variant has ten plain-read forms and
ten guarded-index forms: width arguments0(default64),8,16,32,64 bits, each with
byte_shift0/8. The high-byte selector applies at8 bits; the other widths retain
their ordinary lane. The guarded forms compare the narrowed value with15, index
a16-entry uint32 table and add the original value's shifted upper bits with32-bit
result wrapping, matching the generic compiler-shape fixture's value contract.

| Form | Cases per variant | Guarded table reads per variant | JIT/bytes / CPU/bytes / host/bytes / JIT/CPU differences |
| --- | ---: | ---: | --- |
| read_0_0 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_0_8 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_1_0 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_1_8 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_2_0 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_2_8 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_4_0 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_4_8 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_8_0 | 335872 | 0 | 0 / 0 / 0 / 0 |
| read_8_8 | 335872 | 0 | 0 / 0 / 0 / 0 |
| guard_0_0 | 335872 | 8208 | 0 / 0 / 0 / 0 |
| guard_0_8 | 335872 | 8208 | 0 / 0 / 0 / 0 |
| guard_1_0 | 335872 | 28721 | 0 / 0 / 0 / 0 |
| guard_1_8 | 335872 | 28697 | 0 / 0 / 0 / 0 |
| guard_2_0 | 335872 | 8272 | 0 / 0 / 0 / 0 |
| guard_2_8 | 335872 | 8272 | 0 / 0 / 0 / 0 |
| guard_4_0 | 335872 | 8224 | 0 / 0 / 0 / 0 |
| guard_4_8 | 335872 | 8224 | 0 / 0 / 0 / 0 |
| guard_8_0 | 335872 | 8208 | 0 / 0 / 0 / 0 |
| guard_8_8 | 335872 | 8208 | 0 / 0 / 0 / 0 |

Each form receives335,872 inputs: exhaustive low16 values under four upper-bit
patterns (262,144),65,536 full64-bit fixed-stream pseudorandom values, and8,192
width-selected values in0..15 with independent upper bits. Every guarded form
takes at least8,192 table reads. Table contents and four64-bit canaries vary per
input. The complete104-byte Frame is compared after each run. The mismatch
recorder preserves variant, form, sample, full value/table/canary inputs and all
observed result values; its compressed stream contains zero records.

## Actual compiled forms and source identities

The before header has SHAea2f60863873509caf64d3d1e50b69eed77248ce4347c5fbe3efc76fc677f685.
The candidate has SHAd585cf1e5e2d7ae63ceb6ee5e877ca42ff2eb7c6cfae977337c5ff0867a13621.
Both come from the exact published C archive at
b756ee85e5253b7c0997a7446aaac25ed9536b03, retained as candidate-inputs.tar.gz.
The canonical width header matches the launch Git tree.

The preprocessor capture confirms the candidate's BPF AND255/65535 branch and
the original macro's ordinary mask branch. For these20 generic forms, all paired
BPF function bytes and both ELF objects are identical. The guarded low8 fixture
uses its masked bounded register for the indexed load in both variants.
bytecode.json records every instruction and SHA, and the reviewer matches all40
extracted functions directly to their ELF sections. The bytecode contains zero
store instructions and zero helper calls.

These observations establish the sampled value/memory behavior of the shared
read mechanism. C's separately captured whole Tracee replay checks the complex
application compiler shape. V/T own universal register-read and compiler
correspondence laws. Production generated read/write headers, native application
inputs, workload sources, kernel and service retain their separate source epochs.

## Commands and artifacts

From /workspaces/repository through bws.sh:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-register-read-bpf/Makefile check
python3 kprog/results/kprog_fidelity_20261107/differential/x86-register-read-bpf/review.py
~~~

The detached launcher captures36 source/archive files and pins four existing
cached llvmbpf objects. It reuses those objects and system LLVM18. inputs.tar.gz
contains the actual mechanism headers, test sources, shared VM source snapshot
and launcher. compiled-objects.tar.gz pins the two BPF objects and host object.
The published BPF objects and extract.py reconstruct the40 temporary code slices.

The executable SHAs are in executable-pins.json; its gzip copy is check-x86.gz.
The actual checker is734babca10cc1cf4d488f837e111e860011ae5dd2c449a48c06b60542ca6413a.
environment.json records compiler, CPU, kernel and linked library identities.
launch.json pins all actual inputs and cached objects; status.json records exit0
and an empty source-drift vector. review.json records source, compiler-object and
bytecode reconciliation, with final collection exit0. All commands and outcomes
remain in run.log.gz.
