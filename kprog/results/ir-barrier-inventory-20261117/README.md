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
