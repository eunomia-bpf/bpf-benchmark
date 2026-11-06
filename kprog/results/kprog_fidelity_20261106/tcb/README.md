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
