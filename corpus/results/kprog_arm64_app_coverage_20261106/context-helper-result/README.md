# Original helper context and packet-view refresh on ARM

The simulator previously passed the expanded ABI mirror to context-taking
helpers. The bridge now maps only the ABI-tagged exact mirror base to the
original kernel context. Offset/scalar arguments keep their identity; ordinary
stack arguments keep the existing stack mapping. XDP adjust_head/meta/tail
helpers refresh data/data_end in the mirror after the real helper call.

Six focused identity/offset/scalar/stack/refresh cases and154 existing real
helper ABI cases pass. The shared generated context relation is composed with
arbitrary external-call effects in Lean. The exact isolated source candidate
passes the complete formal Make check (full-check.exit=0), preserving the raw
log. A checker false positive on the existing x86 compiler identity barrier
was repaired by ignoring only that exact no-write barrier; byte-lane gates
remain rejected. The two context declaration fields use unused attributes so
existing file-scope oracles remain valid C.

Both stripped and preserved entry controls run actual bpf_xdp_adjust_head(4),
reload packet bounds, write37 and return2 on source/simulator/bound native.
Both native loads have one nonzero generation. Raw verify files are retained.
The replay archive contains the exact built matched kernel/initrd, compiled
triples, inputs and context-only header; F numeric SP/LR WIP was excluded.

Extract replay.tar.gz, then `make -C runtime run`; on DGX Spark use
`make -C runtime run ACCEL=kvm CPU=host`. Rebuild through the dated Makefile:
`entry-abi-build PHASE=NEW_NAME ENTRY_ABI_ARGS=context`, followed by
`fmov-bank-check PHASE=NEW_NAME KERNEL=/path/to/matched/Image`.
This closes the exercised helper-context defect; context ABI writes and full
six-application coverage still require their remaining repairs.
