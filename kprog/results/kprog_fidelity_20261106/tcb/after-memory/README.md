# TCB snapshot after canonical memory and exclusive-choice binding

Physical lines include comments and blanks; nonblank lines still include
comments. These are explicit source scopes, not executable SLOC or a claim
that line counts establish safety. Every file/component row is in files.csv;
counted-source.tar.gz preserves the exact bytes used for the counts. All archived
rows were independently recounted from those bytes and agree.

| Component | Files | Physical | Nonblank |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 69 | 6549 | 6276 |
| arm64 simulator (including ISA-specific generated C) | 70 | 5937 | 5719 |
| shared simulator headers | 2 | 43 | 37 |
| x86 native-to-proof generator (including local imports) | 9 | 2735 | 2557 |
| arm64 native-to-proof generator (including local imports) | 6 | 1725 | 1597 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 12 | 7914 | 7463 |
| native ELF linker (both ISAs) | 2 | 10733 | 10091 |
| standalone proof loader | 1 | 1290 | 1196 |
| application syscall shim | 11 | 9953 | 9427 |
| x86 native kernel module | 1 | 978 | 877 |
| arm64 native kernel module | 1 | 1206 | 1097 |
| shared native module support | 1 | 204 | 185 |
| x86 native module emitter support | 1 | 206 | 177 |
| shared binding and proof-input contracts | 5 | 940 | 869 |
| loader artifact-binding headers (overlap with loader) | 4 | 345 | 319 |
| vendored helper declarations (ABI input, not project-owned) | 1 | 4785 | 4570 |
| formal model, reference API and proofs (Lean, including generated) | 352 | 40475 | 36097 |
| formal contracts (JSON) | 140 | 2690 | 2690 |
| formal contract generators | 140 | 28886 | 26179 |
| translation-validation model, checker and proofs (Lean) | 14 | 2066 | 1771 |
| translation-validation source and ELF extraction | 7 | 313 | 294 |
| constant-op dispatch generator | 1 | 97 | 90 |
| native-proof kernel patch and application (patch text, not SLOC) | 2 | 688 | 643 |
| existing verifier context (not incremental kernel changes) | 2 | 27873 | 24752 |

The binding span inventory names 23 loader/module entry functions,
921 overlapping physical lines. It is a
selected-function view, not the entire binding implementation: dedicated
binding/input/group/map-offset/exclusive headers and loader artifact-binding
headers have explicit rows, and additional binding work remains inside the
whole loader and module rows. Overlapping views must not be added into a TCB
total. Shared simulator headers are separate from ISA-specific closure counts.
Generator rows follow project Python imports; external library/toolchain source
is not silently included in those counts.

Kernel changes against the recorded base span 13 files:
1197 added and123 deleted lines.
kernel-changes.tsv retains each file. The full verifier-context row, patch-text
row and incremental kernel diff describe different scopes and are not summed.
The external kernel/verifier, Clang/LLVM, C++/Rust toolchains and Lean checking
machinery remain trust dependencies. In particular, the new memory theorem
printout includes Lean.ofReduceBool and Classical.choice alongside propext and
Quot.sound; a small project-source table does not remove those dependencies.

Compared with earlier snapshots, the tool now includes shared proof-input,
map-offset and exclusive binding headers, dedicated loader binding headers,
common/native x86 emitter support, the reference executable API, and all current
source/ELF extractors and context-capture code. Those are scope additions, not
an asserted code-growth measurement. Existing snapshots remain unchanged.
The shared header row is named headers rather than generated C because it is
not restricted to generated files. Some captured inputs were concurrent lane
work; provenance retains the source state without claiming it was all committed.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/tcb/after-memory count
```

count.log.gz preserves the command. The current numeric-address and
application-program safety work remains separate from this accounting result.
