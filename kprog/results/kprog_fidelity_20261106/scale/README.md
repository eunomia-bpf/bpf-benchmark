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


## Delayed-promotion prototype: the10K pointer fixture passes

The previously timed-out direct pointer fixture now compiles in an isolated
F-only representation/compiler experiment and passes the actual KVM verifier
and result check. Its native source and expected result are unchanged.
The100-instruction pointer control also passes. Both traces lose zero events.

| Case | Native instructions | BPF instructions | Result / retval | Verifier us | Slab peak bytes | Vmap reserved bytes |
| --- | ---: | ---: | --- | ---: | ---: | ---: |
| n100_ptr_direct | 115 | 345 | 56 / 2 | 131 | 75640 | 49152 |
| n10000_ptr_direct | 10036 | 30055 | 5015 / 2 | 7890 | 2305488 | 3149824 |

The large program records120245 JIT bytes,241664 program memlock bytes,
2196KiB loader maximum RSS and peak verifier states1. Allocation metrics use
the same separately named trace intervals as the baseline. These instrumented
verifier measurements belong to this scale diagnosis; workload timing remains
with lane R. Native-bound large-program execution has not been exercised here.

GDB confirms that the long10K compiles spend time in
`SROAPass -> PromoteMemToReg -> IDFCalculatorBase::calculate`, before the
verifier. Changing only register storage or adding const selectors did not
remove this promotion cost. Prepending ordinary CSE/CFG simplification also
still reached SROA with3739180 IR instructions and stalled. The successful
prototype defers promotion, simplifies first, explicitly promotes later, then
runs the normal O2 pipeline. Its exact opt invocation is in the archived
Makefile/log. An initial InstCombine one-iteration failure is retained; the
successful command explicitly allows100 compiler optimization iterations.
This bound affects compiler optimization, not native execution or loop safety.

The prototype also uses F-only pointers to the existing named register/tag
cells, readonly decode selectors, a smaller equivalent MOV-load width
expression, and removes only unreferenced C labels. These header changes have
not been installed in the production simulator. The two successful fixture
results do not establish full-state ISA agreement for the prototype.
A separate original-header trial is active to isolate whether compiler-pass
ordering suffices; it retains the original C and all original native inputs.
The baseline16 terminal records and all earlier failures remain unchanged.

Commands as executed:

```sh
taskset -c 20-21 timeout 900 make -C /workspaces/.agent-state/kprog-lanes/F/scale-regref-width n100_ptr_direct.late.bpf.o n10000_ptr_direct.pruned.late.bpf.o
taskset -c 16-19 make -C kprog/fidelity scale-kvm SCALE_BUILD=build-x86/scale-late-regref SCALE_OUT=../results/kprog_fidelity_20261106/scale/late-regref-kvm
```

`late-regref-kvm/` publishes both full JSON outcomes and guest provenance.
`late-promotion-prototype-traces.tar.gz` retains every raw trace, trace report,
verifier log and loader log for these two passes.
`late-promotion-prototype-artifacts.tar.gz` retains exact experimental headers,
C sources, Makefiles, all preceding representation/ordering diagnostic logs,
the unchanged native assembly/objects/disassembly, and both accepted BPF
objects with their build records. Its `lane-F/` subtree restores under
`/workspaces/.agent-state/kprog-lanes/F/`; `accepted-artifacts/` contains the
files used as `SCALE_BUILD`. The original frozen baseline source closure
remains in `full-scale-build-artifacts.tar.gz` above.


## Both10K indirect fixtures now pass

The unchanged pointer-heavy indirect program now compiles through the same
frozen experimental delayed-promotion path and passes KVM. The scalar-heavy
indirect program exposed a second compiler bottleneck: the later default O2
InstCombine pass stalled for15minutes on21937 IR instructions. An explicit
ADCE/SCCP/CFG cleanup after promotion avoids that pass and produces the
correct scalar result. The failed optimizer log/backtrace remains archived;
this is a separately selected compiler pipeline, with no automatic fallback.

| Case | Native instructions | BPF instructions | Result / retval | Verifier us | Slab peak bytes | Vmap reserved bytes |
| --- | ---: | ---: | --- | ---: | ---: | ---: |
| n10000_ptr_indirect | 10084 | 30047 | 5023 /2 | 9213 | 2312112 | 3149824 |
| n10000_scalar_indirect | 10084 | 104 | 12877716020613431511 /2 | 99 | 78584 | 24576 |

Both traces report zero lost events. Pointer indirect records120225 JIT bytes,
241664 program memlock bytes and2272KiB loader maximum RSS. Scalar indirect
records418 JIT bytes,4096 memlock bytes,1248KiB maximum RSS and peak verifier
states9. Scalar constants fold extensively; its104 BPF instructions are not a
claim that arbitrary10K scalar programs verify at that size. Across the original
and experimental records, all four10K shapes now have accepted, correct
artifacts. The original baseline failures and all100K frontend failures remain
recorded; no experimental header optimization is silently promoted to production.

```sh
taskset -c 20-23 prlimit --as=12884901888 -- timeout 1800 make -C /workspaces/.agent-state/kprog-lanes/F/scale-regref-width n10000_ptr_indirect.pruned.late.bpf.o n10000_scalar_indirect.pruned.late.bpf.o
taskset -c 20-23 prlimit --as=12884901888 -- timeout 900 make -C /workspaces/.agent-state/kprog-lanes/F/scale-regref-width n10000_scalar_indirect.pruned.dce.bpf.o
taskset -c 16-19 make -C kprog/fidelity scale-kvm SCALE_BUILD=build-x86/scale-late-indirect SCALE_OUT=../results/kprog_fidelity_20261106/scale/late-indirect-kvm
taskset -c 16-19 make -C kprog/fidelity scale-kvm SCALE_BUILD=build-x86/scale-late-scalar-indirect SCALE_OUT=../results/kprog_fidelity_20261106/scale/late-scalar-indirect-kvm
```

The first command compiles the pointer fixture, then stalls on the scalar
fixture; its log explicitly records that stopped diagnostic. The second is the
successful scalar command. `indirect-scale-artifacts.tar.gz` retains exact
native assembly/objects, generated C/header closure, Makefile, accepted BPF
objects, and both optimizer diagnostics. `indirect-scale-traces.tar.gz` retains
both full trace/report/verifier/loader sets. The per-case JSON outcomes and
provenance are also published directly.

## Native CPU versus kernel proof across both branch outcomes

`branch-parity/` checks all four10K artifacts against their unchanged native
assembly executed as ordinary static user binaries on this x86 CPU. For each
program it tests packet byte8 at0,1,2,3,127,128,254,255, with the same64-byte
packet and guard length as the proof probe. Every one of the32 cases agrees
on the64-bit result and retval2. This catches bounded-dispatch or scalar-folding
mistakes that could pass the original all-ones input. It executes only these
controlled, bounds-checked helper-free native fixtures; unsafe negatives are
never executed. The native driver supplies expected outputs, adding no ISA
interpreter. The original probe still defaults to byte8=1; the optional byte
argument changes only this focused test input.

```sh
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/scale/branch-parity build
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/scale/branch-parity kvm
```

`branch-parity/outcomes.json` retains all32 native/proof result pairs and errors;
`raw-evidence.tar.gz` includes every native/probe/verifier log, guest console,
exact native binaries and the probe sources/binary. This is correctness
validation, not workload timing. A chunked-preprocessing100K trial is active
under the same12GiB process cap; its outcome will be recorded separately.

## First100K native artifact accepted after frontend factoring

The original100K scalar/direct program now passes the actual KVM verifier and
matches native CPU execution for all eight packet selectors used above.
Native instructions:100036; BPF instructions:88; verified instructions:132;
result10713441450579470919 and retval2 for the original byte8=1 input.
Verifier time92us, peak states8, slab peak77528B, vmap reserved24576B,
program memlock4096B, JIT365B, loader maximum RSS1252KiB. No trace events
were lost. This scalar fixture folds extensively;88BPF instructions do not
measure verifier scalability for a general100K-instruction scalar proof.

Two separate unchanged-C diagnostics first passed the frontend's macro
source-location limit through chunked preprocessing, then exhausted the12GiB
process address-space cap: one with debug metadata and one without it. The
chunker preserves source line numbers (including branch macro `__LINE__`)
and its1K control produced exactly the same13623470 C tokens as monolithic
preprocessing. The full1.7GiB expanded100K C remains in the owning build dir;
its generator, original C and logs are archived. These failures are retained,
not silently replaced by the successful path.

The successful experimental path factors repeated **existing** arithmetic
macro invocations into always-inline functions. Each function takes the
actual R8 register cell, provenance tag and four modeled flag cells, invokes
the exact original macro with its original literal arguments, then returns
those cells. Main-program entry initialization, native instructions, branches,
packet operations and output checks are unchanged. Optimizing these small
functions before inlining avoids100K copies of their unoptimized frontend
expansion. Only unreferenced C labels are removed. The helper bodies are
internalized and removed after inlining; the accepted object has no remaining
helper calls. This is a frozen experimental compiler representation, not a
production generator/header change or a new ISA interpreter. An earlier full
state-struct factoring prototype failed to specialize indirect targets; its
source and errors remain archived too.

The10K scalar/indirect control also passes this path (104BPF instructions,
89us verifier, slab77544B/vmap24576B, zero lost events). `factored-parity/`
retains16/16 native/proof pairs: both this10K control and the100K scalar/direct
fixture agree for bytes0,1,2,3,127,128,254,255, each with retval2.

```sh
python3 kprog/fidelity/build-x86/scale-factored-cells/factor.py kprog/fidelity/build-x86/scale-100k-preprocess/program.bpf.c kprog/fidelity/build-x86/scale-factored-cells/n100000_scalar_direct
taskset -c 20-23 prlimit --as=12884901888 -- timeout 1800 make -C kprog/fidelity/build-x86/scale-factored-cells/n100000_scalar_direct
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/scale/factored-parity build
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/scale/factored-parity kvm
taskset -c 16-19 make -C kprog/fidelity scale-kvm SCALE_BUILD=build-x86/scale-factored-accepted SCALE_OUT=../results/kprog_fidelity_20261106/scale/factored-kvm
```

`100k-scalar-direct-artifacts.tar.gz` contains the exact factoring/preprocessing
scripts, Makefiles, frozen header closure, generated sources, accepted BPF
objects and unchanged native assembly/objects, plus successful and failed
compiler diagnostics. `factored-traces.tar.gz` retains the full verifier and
allocation traces; `factored-parity/raw-evidence.tar.gz` retains every native,
probe and verifier log plus exact native binaries and the probe source/binary.
Per-case JSON and guest provenance remain directly readable. The100K scalar
indirect and pointer variants continue as separate attempts.
