# Consistent external-value stack slot joins

The common x86 ABI analysis represents a stack slot holding ordinary external
bits with an absent pointer-provenance record. Reads already use False for this
case. Control-flow joins now use the same default, retaining finite stack/external
alternatives whenever another predecessor stores a private-stack pointer there.
Explicit unknown origins retain their existing rejection rule. Opaque source bytes
continue through helper copies and fail upon observable use.

Two generic branch fixtures exercise helper-written external bytes joined with a
saved private pointer. The defined case passes, and the opaque-byte case rejects.
The prior analysis rejects the defined case at its helper source relation. The
complete existing checker passes143encoder/ABI,3072CLhost/UBSan and19renderedMOVX
host/BPF cases, including its existing width/REX and XDP-context controls.
Commands: python3 check.py prior; python3 check.py, with exact scripts and sources
in raw.tar.gz. The archive keeps the initial hexadecimal branch-target fixture
diagnostic and the completed invocation. Generic read/join consistency and
helper taint transport remain part of the universal V/T ABI bridge.

The preceding whole Tetragon and helper-preserving Tracee epochs each bind two
requests and retain a helper-source relation failure. Their complete results are
published alongside this repair. The following whole-application replay captures
the new shared analysis; runtime outcomes and universal safety laws keep their
respective responsibilities.
