# Embedded IR barriers and helper declarations

Read-only inventory of the actual objects referenced by each staged native
manifest. The purpose is to establish which inline-assembly constraints and
helper declarations the load-time LTO really receives before proposing a
transformation. Source, production manifests, compiler flags, image and
benchmark stay unchanged. This is not an installed-size or per-call result.

The committed reader extracts `.llvmbc` with `llvm-objcopy-18`, directing
its ordinary object output to `/dev/null` so the input object is not rewritten.
It retains bitcode and disassembled IR as raw evidence under `/workspaces`,
plus exact command status, object size/mtime, asm text/constraints/function
and source line. No source tree or native object copy is created or edited.

`run.sh` orders timing SH then image SH, runs on CPU 19 and limits address
space to 32 GiB. It starts no build, image publication or guest. Both empty
and nonempty asm are recorded. Presence or absence of a memory clobber is
evidence for source review, not permission to erase an assembly barrier or
alter its semantics. The existing loader helper-query class remains with
its frozen-path owner.

The host inventory finished at 20:28:24Z with status 0. All 56 distinct
objects referenced by the staged manifests carry readable embedded IR;
input sizes and mtimes are unchanged. These are distinct objects, not
program counts, all produced objects or a shipped-image census.

| App | Distinct objects | Empty asm occurrences | Nonempty asm occurrences |
| --- | ---: | ---: | ---: |
| OTel | 1 | 60 | 0 |
| BCC | 8 | 0 | 0 |
| Cilium | 6 | 31 | 0 |
| Tetragon | 35 | 27 | 5,557 |
| Tracee | 3 | 2 | 0 |
| Katran | 3 | 0 | 0 |

Counts are frontend module instruction occurrences, including internal
helper-ID factory definitions. They are not runtime frequencies or counts
after inlining. Every empty asm has a memory clobber; Tetragon's nonempty
asm performs actual helper calls with caller-saved register clobbers.
Removing these barriers or those call clobbers is not justified. No compiler
transformation is added from this inventory. BCC's 60 named helper declarations
and opensnoop's absence of asm rule out barrier removal as a BCC solution.

The next source inspection found a separate branch-label concern in
`native_link/src/x86.rs:1533`: direct-load helper replacements emit only
synthetic chunks, leaving no original call label. The tail-call stub loop
has the same form. A focused production-rewriter regression will test a
conditional branch into each replacement before any dead helper-ID-load
optimization. That is pipeline correctness, not an asm-removal proposal.
Raw commands, bitcode, full IR and instruction-level inventory stay at the
path in `host-location.txt`; the compact summary is committed here.
