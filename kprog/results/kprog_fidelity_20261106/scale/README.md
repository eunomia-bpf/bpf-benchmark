# Native-size verifier scale sweep

All eight completed 100/1K native-instruction variants compile, load, and
execute their expected nonzero 64-bit result with XDP_PASS under x86 KVM.
The completed16-case follow-up below includes10K scalar acceptance and all
10K/100K failures; this opening table preserves the first8-case snapshot.
Counts below are actual disassembled native instructions and loaded BPF
instructions, not the nominal size setting. Scalar constants can fold during
specialization; pointer variants retain volatile packet reads.

| Case | Native instructions | BPF instructions | Verifier us | Slab peak bytes | Vmap reserved peak bytes |
| --- | ---: | ---: | ---: | ---: | ---: |
| n1000_ptr_direct | 1015 | 3047 | 996 | 295192 | 327680 |
| n1000_ptr_indirect | 1021 | 3047 | 778 | 301816 | 327680 |
| n1000_scalar_direct | 1015 | 47 | 46 | 47976 | 20480 |
| n1000_scalar_indirect | 1021 | 46 | 44 | 47976 | 20480 |
| n100_ptr_direct | 115 | 345 | 125 | 75640 | 49152 |
| n100_ptr_indirect | 121 | 345 | 127 | 82264 | 49152 |
| n100_scalar_direct | 115 | 47 | 47 | 47976 | 20480 |
| n100_scalar_indirect | 121 | 47 | 44 | 47976 | 20480 |

Memory comes from standard trace-cmd kmalloc/kmem_cache and vmalloc events
between bpf_check entry/return probes. The earlier intervals from libbpf
capability probes are retained separately; the final interval is this single
fixture. Repeated nested kvmalloc/kmalloc events for one live pointer are
counted once. Slab figures use allocator bytes_alloc; vmap figures are reserved
virtual ranges, including allocator guards, and are not resident RAM. These
are separate metrics and are not summed into a fabricated physical-memory
number. Program memlock and loader RSS are also retained as separately named
raw counters. All eight traces report zero lost events.

Tracing adds overhead to the kernel verifier time. These are instrumented
correctness/scale observations, not workload-throughput or R timing results.
The untraced 100-case smoke is preserved as well. All raw trace.dat and trace
report files remain under first-eight/ and in the compressed evidence archive.

The native assembly has no execution fuel, synthetic safety guard, zero
fallback, or dropped instruction. It checks the actual packet end before
reading, executes direct or register-indirect branches through the production
finite-target specializer, and writes its result. Only simulator BPF is loaded
in this sweep; this is not a bound native large-program execution claim.
The current native module chunk budget must be exercised separately.

Reproduction (requires trace-cmd, here version3.2.0):

```sh
taskset -c 16-23 make -C kprog/fidelity scale-build
taskset -c 16-23 make -C kprog/fidelity scale-kvm
```

Full build uses a frozen production header closure and saves every native
assembly/object, generated proof, compiler log and terminal per-case record.
Pending cases are not exclusions. Preliminary trace-parser failures and their
successful load/execution outputs are preserved under smoke-traced* and
smoke-memory; they were not relabeled verifier failures.

## Completed16-case baseline

The resumed build and final KVM pass now have a terminal record for all16
requested cells:9 compiled/accepted/correct,3 compile timeouts at900seconds,
and4 Clang source-location exhaustion failures. No failed case is dropped.
The latter is a real front-end limit during macro expansion, not verifier
rejection, program-size rejection or lack of RAM. The 10K scalar-direct case
has10036 native instructions and specializes to80 BPF instructions; it passes
its nonzero15318568609386021639 result and retval2. This does not establish
large pointer-code acceptance. Full final per-case values:

| Case | Native instructions | Outcome | BPF instructions | Verifier us | Slab peak bytes | Vmap reserved bytes |
| --- | ---: | --- | ---: | ---: | ---: | ---: |
| n100_ptr_direct | 115 | passed (rc0) | 345 | 128 | 75640 | 49152 |
| n100_ptr_indirect | 121 | passed (rc0) | 345 | 129 | 82264 | 49152 |
| n100_scalar_direct | 115 | passed (rc0) | 47 | 48 | 47976 | 20480 |
| n100_scalar_indirect | 121 | passed (rc0) | 47 | 51 | 47976 | 20480 |
| n1000_ptr_direct | 1015 | passed (rc0) | 3047 | 795 | 295192 | 327680 |
| n1000_ptr_indirect | 1021 | passed (rc0) | 3047 | 793 | 301816 | 327680 |
| n1000_scalar_direct | 1015 | passed (rc0) | 47 | 49 | 47976 | 20480 |
| n1000_scalar_indirect | 1021 | passed (rc0) | 46 | 50 | 47976 | 20480 |
| n10000_ptr_direct | 10036 | proof_compile (rc124) | — | — | — | — |
| n10000_ptr_indirect | 10084 | proof_compile (rc124) | — | — | — | — |
| n10000_scalar_direct | 10036 | passed (rc0) | 80 | 79 | 58728 | 20480 |
| n10000_scalar_indirect | 10084 | proof_compile (rc124) | — | — | — | — |
| n100000_ptr_direct | 100036 | proof_compile (rc1) | — | — | — | — |
| n100000_ptr_indirect | 100084 | proof_compile (rc1) | — | — | — | — |
| n100000_scalar_direct | 100036 | proof_compile (rc1) | — | — | — | — |
| n100000_scalar_indirect | 100084 | proof_compile (rc1) | — | — | — | — |

`x86/*.json` retains all16 outcomes and separate allocation intervals;
`full-scale-build-artifacts.tar.gz` contains all native/proof sources, assembly,
objects, exact frozen simulator closure and compiler diagnostics.
`final-scale-traces.tar.gz` retains final raw traces/reports/guest provenance.
`preliminary-and-validation-evidence.tar.gz` retains earlier observer/parser
attempts and completed validation instead of discarding them.
The compiler queue now resumes terminal per-case records with its original
saved encoder/header source; it does not overwrite completed results after
a container restart. An isolated register-cell representation experiment is
active against the exact native CPU matrix and100K compile failure; no
production optimization or100K acceptance is claimed from it yet.
