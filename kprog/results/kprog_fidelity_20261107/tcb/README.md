# TCB source snapshot, 2026-11-07

The existing inventory now includes the native-only trusted service, its native
input declarations, both specialization adapters, the trusted-loader entrypoint,
and the kernel queue/authorization and checked-capture headers. These components
were absent from the earlier inventory scope. This change measures source size;
it does not change the production proof or native execution path.

Counts below are physical and nonblank physical lines; comments count. The ISA
simulator rows follow quoted C include closures and put their common headers in
a separate row. Generator rows follow static local Python imports. The service's
dynamic ISA worker/generator imports are represented by the explicit adapter and
generator rows. The loader rows include the production local C++ headers.
Test programs, build products, old implementations and host proof oracles are
excluded. Formal/translation-validation source is reported separately from the
runtime source; these lines do not measure Lean's checking kernel.

| Component | Files | Physical lines | Nonblank lines |
| --- | ---: | ---: | ---: |
| x86 simulator (including ISA-specific generated C) | 69 | 6652 | 6370 |
| arm64 simulator (including ISA-specific generated C) | 69 | 5991 | 5773 |
| shared simulator headers | 3 | 107 | 98 |
| x86 native-to-proof generator (including local imports) | 10 | 3018 | 2823 |
| arm64 native-to-proof generator (including local imports) | 7 | 1926 | 1780 |
| trusted service and native input declarations | 2 | 391 | 350 |
| x86 trusted specialization adapter | 1 | 61 | 55 |
| arm64 trusted specialization adapter | 1 | 76 | 67 |
| trusted service loader entrypoint | 1 | 91 | 88 |
| proof build/load orchestration | 1 | 616 | 549 |
| native shared loader/linker integration | 13 | 8377 | 7920 |
| native ELF linker (both ISAs) | 2 | 10931 | 10279 |
| standalone proof loader | 1 | 1290 | 1196 |
| application syscall shim | 11 | 9976 | 9448 |
| x86 native kernel module | 1 | 1026 | 923 |
| arm64 native kernel module | 1 | 1259 | 1147 |
| trusted kernel queue and checked capture (including wire headers) | 5 | 1086 | 1045 |
| shared native module support | 1 | 204 | 185 |
| x86 native module emitter support | 1 | 206 | 177 |
| shared binding and proof-input contracts | 5 | 958 | 885 |
| loader artifact-binding headers (overlap with loader) | 4 | 365 | 338 |
| vendored helper declarations (ABI input, not project-owned) | 1 | 4785 | 4570 |
| formal model, reference API and proofs (Lean, including generated) | 369 | 47873 | 42672 |
| formal contracts (JSON) | 140 | 2696 | 2696 |
| formal contract generators | 140 | 28653 | 25975 |
| translation-validation model, checker and proofs (Lean) | 30 | 9921 | 8852 |
| translation-validation source and ELF extraction | 10 | 653 | 619 |
| constant-op dispatch generator | 1 | 97 | 90 |
| native-proof kernel patch and application (patch text, not SLOC) | 2 | 721 | 672 |
| existing verifier context (not incremental kernel changes) | 2 | 27873 | 24752 |

The kernel delta is **1271 added and 123 deleted lines across 14
files**, against the full kernel base recorded in `provenance.txt` (the parent
of the first project kinsn commit). `kernel-changes.patch.gz` and
`kernel-changes.tsv` describe the same captured patch bytes. Patch/script rows
and the full existing verifier context overlap that delta and are not added to
it. The patch includes the shared kernel worktree's recorded uncommitted edits.

`binding-functions.json` records **38 functions / 1479 physical lines**,
including kernel request ownership, immutable submission, activation,
authorization/seal, completion, pinned context/maps, service lifecycle, and loader
submission. These spans overlap the full module/header/loader rows. They are a
named binding subset, not a second component total or a claim to include every
binding-relevant line. Shared Python imports and loader header subsets also
have explicitly overlapping memberships. No overlapping rows are summed into a
TCB total.

`counted-source.tar.gz` retains the exact 895 unique counted files;
`source-manifest.json` pins their byte lengths and SHA256 hashes. `files.csv`
retains every component membership; `components.json` is the table above.
`verification.json` records an independent recount from the archive, all source
hashes, binding spans and patch-numstat agreement. `inventory.log.gz` retains
the Make invocation/output. `provenance.txt` records the dirty shared checkout;
start/end revisions are also recorded in the manifest. Active C/A/V/T source
may change after capture: this is the captured-byte inventory, not a claim that
the whole shared tree was clean or tested at one revision.

External trust dependencies still include Linux's verifier/helper/map/context
semantics, compiler and BPF lowering, native ELF decoding/rewriting libraries,
Python/pyelftools, libbpf/libelf/libc, ABI/ISA definitions and Lean's checking
kernel. Installed packages have no source-size figure assigned here. The
upstream helper declarations and existing verifier are labeled separately;
neither is hidden inside project-owned source counts. Source line counts do not
establish fidelity, specialization preservation, boundary safety or binding.

Reproduce from the repository root (preserves older dated inventories):

```sh
taskset -c 16-23 make -C kprog/fidelity tcb TCB_OUT=../results/kprog_fidelity_20261107/tcb
```
