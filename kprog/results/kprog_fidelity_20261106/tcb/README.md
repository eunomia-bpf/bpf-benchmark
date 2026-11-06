# Trusted-computing-base source inventory, 2026-11-06

This inventory counts every project component on the current native-proof path,
including generated headers, both specializers, the native ELF linker, loader,
application shim, native kernel modules, binding, and the kernel patch. It does
not equate a line count with correctness or claim that the simulator is the
only trusted component. Byte-level translation validation has not yet removed
Clang, the specializer or their output from the semantic trust boundary.

Counts are physical source lines and nonblank physical lines; comments count.
They are not executable SLOC. `files.csv` lists every counted file. Both ISA
simulator include closures are resolved recursively; two shared headers are
counted once in their own row. The specializer rows include their local Python
imports. Tests, build products, archived implementations and formal host
oracles are excluded. `provenance.txt` records repository/kernel revisions and
the shared checkout's dirty state. This is a measured snapshot; the inventory
command is rerun as the active fixes change source sizes.

| Component | Files | Physical lines | Nonblank lines |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 67 | 5,816 | 5,613 |
| arm64 simulator (including ISA-specific generated C) | 68 | 5,439 | 5,243 |
| shared simulator generated C | 2 | 38 | 33 |
| x86 native-to-proof generator (including local imports) | 6 | 1,690 | 1,564 |
| arm64 native-to-proof generator (including local imports) | 4 | 972 | 881 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 9 | 6,632 | 6,229 |
| native ELF linker (both ISAs) | 2 | 9,604 | 9,003 |
| standalone proof loader | 1 | 1,290 | 1,196 |
| application syscall shim | 11 | 9,888 | 9,365 |
| x86 native kernel module | 1 | 931 | 832 |
| arm64 native kernel module | 1 | 1,159 | 1,052 |
| shared binding wire contract | 1 | 115 | 107 |
| formal model and proofs (Lean, including generated) | 310 | 34,389 | 30,791 |
| formal contracts (JSON) | 138 | 2,284 | 2,284 |
| formal contract generators | 138 | 28,726 | 26,027 |
| translation-validation composition theorem | 1 | 109 | 96 |
| existing verifier context (not incremental kernel changes) | 2 | 27,732 | 24,619 |

Kernel changes against `6f0caf14e995^` span 11 files, with **961
added and 122 deleted lines**. `kernel-changes.tsv` identifies every
file and its additions/deletions. The separate verifier-context row counts the
current verifier implementation and its state header in full; it is context,
not a second count of incremental patch lines. The kernel base is the parent
of the first project kinsn commit, resolved to a full revision in provenance.

Binding is not confined to the 115-line wire header.
`binding-functions.json` additionally identifies 21 production functions
(710 physical lines) for payload/generation decoding, native
instantiation, immutable upload/seal operations, generation reads, proof
normalization and loader sealing. These function lines **overlap** the module
and loader rows; they must not be added again. Native emission and the rest of
the upload path are already included in the full module/loader counts.

The Lean rows include the models, generated definitions and refinement proofs;
they are proof-artifact size, not a count of Lean's trusted kernel. The
translation-validation composition theorem is counted separately. The JSON
and generator rows expose the authoring surface for those contracts rather
than hiding it inside a generated-header count.

The existing trusted environment also includes Linux's verifier/helper/map and
context semantics, ABI/ISA definitions, the host compiler and linker, Clang's
BPF lowering until an actual output certificate exists, libbpf, libc/libelf,
and Lean's checking kernel. Installed binary packages have no meaningful
source-line count in this checkout; none is assigned a fabricated zero or
silently declared untrusted. The counts here quantify the complete
project-owned source increment and the local verifier context, with those
external trust dependencies stated explicitly.

Reproduce from the repository root:

```sh
taskset -c 16-23 make -C kprog/fidelity tcb
```


## Recovery snapshot

`components.json`, `files.csv`, `binding-functions.json` and
`kernel-changes.tsv` were refreshed through the same `make tcb` command after
the restart; the table above retains the earlier snapshot. The inventory now
also names `prepare_simulator_proof` explicitly and counts
`kprog/tv/native-proof-regions.patch` plus its application script separately.
The loader's counted manifest source includes `simulator_object` and
`simulator_program`. Patch text counts are physical diff/script lines, not
executable SLOC, and overlap the kernel-change inventory. Binding-function
counts similarly overlap their full source components and are not summed
again. `recovery.log.gz` retains the exact component counts for this snapshot.

## Shared helper ABI and binding-group refresh

The current inventory also follows Python imports through `kprog/` and the
repository root, so the x86 generator includes the shared helper prototype
reader instead of hiding that dependency. The Arm runtime generator imports
its generated ID table; its helper contract generator is counted separately
with the formal generators. The shared reader's real input,
`vendor/libbpf/src/bpf_helper_defs.h`, is counted in a separate upstream row;
it is not project-owned code. The binding wire row includes both the original
header and `native_lab_group.h`. Counts below are this later dirty-worktree
snapshot, including ongoing producer fixes; the earlier table stays historical.

| Component | Files | Physical | Nonblank |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 67 | 6295 | 6032 |
| arm64 simulator (including ISA-specific generated C) | 68 | 5162 | 4959 |
| shared simulator generated C | 2 | 38 | 33 |
| x86 native-to-proof generator (including local imports) | 8 | 2288 | 2117 |
| arm64 native-to-proof generator (including local imports) | 4 | 1139 | 1045 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 9 | 6856 | 6449 |
| native ELF linker (both ISAs) | 2 | 9679 | 9077 |
| standalone proof loader | 1 | 1290 | 1196 |
| application syscall shim | 11 | 9888 | 9365 |
| x86 native kernel module | 1 | 964 | 863 |
| arm64 native kernel module | 1 | 1191 | 1082 |
| shared binding wire contract | 2 | 500 | 458 |
| vendored helper declarations (ABI input, not project-owned) | 1 | 4785 | 4570 |
| formal model and proofs (Lean, including generated) | 314 | 35033 | 31353 |
| formal contracts (JSON) | 138 | 2643 | 2643 |
| formal contract generators | 138 | 28721 | 26031 |
| translation-validation composition theorem | 1 | 97 | 86 |
| native-proof kernel patch and application (patch text, not SLOC) | 2 | 342 | 311 |
| existing verifier context (not incremental kernel changes) | 2 | 27796 | 24679 |

The 22 named binding functions occupy 846 physical lines, overlapping their full source rows. Kernel changes span12 files with1053 added/123 deleted lines. No overlapping counts are summed into a TCB total. `helper-refresh.log.gz` records this `make tcb` run.

## Executable translation-validation surface

The latest inventory counts all five `kprog/tv/*.lean` model/checker/proof files
(610physical/536nonblank lines), instead of only the composition theorem.
The55-line ELF extractor is separate. A's97-line mechanical constant-op
dispatch generator is also explicit; generated C remains in the simulator
include closure. The loader row includes the new DATASEC-layout helper.
`tv-refresh.log.gz`, `components.json` and `files.csv` give the exact current
snapshot. These proof-source counts do not measure Lean's trusted kernel;
T's use of native reduction remains an external compiler/runtime trust
assumption, not erased by these line counts.


## Current proof preparation and ABI snapshot

The inventory command exposed a stale function list after proof preparation
split into `open_simulator_proof` and `finish_simulator_proof`. The old name
caused an explicit failure rather than silently omitting binding code.
The inventory now names both current functions; a fresh `make tcb` completes
and records every span in `binding-functions.json`. The initial failed run
is retained in `current-prefix-refresh.log.gz`; `current-proof-refresh.log.gz`
is the successful rerun. This is a dirty shared-source snapshot, including
T's in-progress version2 context wire and other lanes' source changes, not a
claim that all changes were already committed or validated together.

| Component | Files | Physical lines | Nonblank lines |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 67 | 6339 | 6073 |
| arm64 simulator (including ISA-specific generated C) | 69 | 5724 | 5518 |
| shared simulator generated C | 2 | 38 | 33 |
| x86 native-to-proof generator (including local imports) | 8 | 2493 | 2318 |
| arm64 native-to-proof generator (including local imports) | 6 | 1536 | 1410 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 9 | 7006 | 6592 |
| native ELF linker (both ISAs) | 2 | 9955 | 9342 |
| standalone proof loader | 1 | 1290 | 1196 |
| application syscall shim | 11 | 9918 | 9393 |
| x86 native kernel module | 1 | 967 | 866 |
| arm64 native kernel module | 1 | 1194 | 1085 |
| shared binding wire contract | 2 | 601 | 551 |
| vendored helper declarations (ABI input, not project-owned) | 1 | 4785 | 4570 |
| formal model and proofs (Lean, including generated) | 324 | 36196 | 32361 |
| formal contracts (JSON) | 138 | 2644 | 2644 |
| formal contract generators | 138 | 28654 | 25967 |
| translation-validation model, checker and proofs (Lean) | 5 | 706 | 620 |
| translation-validation ELF extraction | 1 | 55 | 53 |
| constant-op dispatch generator | 1 | 97 | 90 |
| native-proof kernel patch and application (patch text, not SLOC) | 2 | 342 | 311 |
| existing verifier context (not incremental kernel changes) | 2 | 27796 | 24679 |

The 23 named binding functions contain 875 physical lines, overlapping their loader/module rows. Kernel changes span 12 files, with 1053 additions and 123 deletions against the recorded base. No overlapping rows are added into a TCB total.

## Scale-completion source snapshot

The same inventory command was rerun after the LEA/parser, context-v2,
map-capacity and arithmetic-reference increments. This is a dirty shared-source
snapshot, including other lanes' in-progress edits; provenance records that
state. Earlier tables remain historical. Function counts overlap component
counts, and allocation/trust dependencies are unchanged.

| Component | Files | Physical | Nonblank |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 67 | 6357 | 6089 |
| arm64 simulator (including ISA-specific generated C) | 69 | 5798 | 5588 |
| shared simulator generated C | 2 | 40 | 35 |
| x86 native-to-proof generator (including local imports) | 8 | 2544 | 2367 |
| arm64 native-to-proof generator (including local imports) | 6 | 1663 | 1535 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 9 | 7218 | 6798 |
| native ELF linker (both ISAs) | 2 | 10151 | 9528 |
| standalone proof loader | 1 | 1290 | 1196 |
| application syscall shim | 11 | 9941 | 9415 |
| x86 native kernel module | 1 | 978 | 877 |
| arm64 native kernel module | 1 | 1205 | 1096 |
| shared binding wire contract | 2 | 689 | 635 |
| vendored helper declarations (ABI input, not project-owned) | 1 | 4785 | 4570 |
| formal model and proofs (Lean, including generated) | 333 | 37616 | 33592 |
| formal contracts (JSON) | 138 | 2648 | 2648 |
| formal contract generators | 138 | 28660 | 25972 |
| translation-validation model, checker and proofs (Lean) | 6 | 847 | 740 |
| translation-validation ELF extraction | 1 | 55 | 53 |
| constant-op dispatch generator | 1 | 97 | 90 |
| native-proof kernel patch and application (patch text, not SLOC) | 2 | 636 | 591 |
| existing verifier context (not incremental kernel changes) | 2 | 27843 | 24724 |

```sh
taskset -c 16-19 make -C kprog/fidelity tcb
```

`scale-completion-inventory.log.gz` retains the exact command output.

This snapshot identifies 23 binding functions (912 overlapping physical lines). Kernel changes span 13 files, with 1167 added and 123 deleted lines against the recorded kernel base.

## Snapshot after full-bank FMOV and LDP source validation

`after-fmov-ldp/README.md` contains the separate updated component table and
exact counted-source archive, without replacing the historical snapshots above.
It includes the full32-vector simulator, LDP/SP source validation, readonly
binding integration and current generators. The binding subset is23 functions,
917 overlapping physical lines; incremental kernel changes remain1167 added
and123 deleted across13 files. Full file/provenance records accompany the table.
