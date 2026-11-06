# TCB snapshot after full-bank FMOV and LDP source validation

Counts include comments: physical source lines and nonblank physical lines,
not executable SLOC. Every counted file is listed in `files.csv`; the exact
bytes read for those counts are preserved in `counted-source.tar.gz`, including
concurrent lane work identified in `provenance.txt`. Prior snapshots and their
rationale remain unchanged in the parent directory.

The ISA simulator rows include their generated C include closure; common
headers have their own row. Generator rows follow local Python imports.
The loader/linker, module, binding, shim and kernel changes remain in the trust
boundary. Line counts do not discharge semantic fidelity or remove Clang from
that boundary. Tests, result/build artifacts and archived implementations are
excluded. Binding function spans overlap their owning component counts.

| Component | Files | Physical | Nonblank |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 67 | 6377 | 6107 |
| arm64 simulator (including ISA-specific generated C) | 69 | 5809 | 5599 |
| shared simulator generated C | 2 | 40 | 35 |
| x86 native-to-proof generator (including local imports) | 8 | 2551 | 2374 |
| arm64 native-to-proof generator (including local imports) | 6 | 1683 | 1555 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 10 | 7436 | 7006 |
| native ELF linker (both ISAs) | 2 | 10253 | 9626 |
| standalone proof loader | 1 | 1290 | 1196 |
| application syscall shim | 11 | 9941 | 9415 |
| x86 native kernel module | 1 | 978 | 877 |
| arm64 native kernel module | 1 | 1205 | 1096 |
| shared binding wire contract | 2 | 689 | 635 |
| vendored helper declarations (ABI input, not project-owned) | 1 | 4785 | 4570 |
| formal model and proofs (Lean, including generated) | 337 | 38478 | 34335 |
| formal contracts (JSON) | 138 | 2660 | 2660 |
| formal contract generators | 138 | 28665 | 25977 |
| translation-validation model, checker and proofs (Lean) | 8 | 1022 | 886 |
| translation-validation ELF extraction | 1 | 55 | 53 |
| constant-op dispatch generator | 1 | 97 | 90 |
| native-proof kernel patch and application (patch text, not SLOC) | 2 | 636 | 591 |
| existing verifier context (not incremental kernel changes) | 2 | 27843 | 24724 |

The recorded binding subset contains23 named functions and917 overlapping physical lines. Kernel changes against the recorded base span13 files: 1167 added and123 deleted lines. Patch-text, full verifier-context and incremental kernel-diff counts describe different scopes and are not added.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/tcb/after-fmov-ldp count
```

`count.log.gz` retains the command output. The inventory tool's optional
`--out` writes a separate snapshot instead of replacing historical tables.
Its binding-span extraction uses the same captured source bytes as its file
counts, so later shared-tree edits cannot change the archived calculation.
