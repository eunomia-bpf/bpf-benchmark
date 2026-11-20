# Actual wrapper entry through setup and both MOV calls

`Arm64ProgramEntryMovPrefix.entry_pair` starts at the actual original
signed32/one-context wrapper Callstate. It reuses all 98 real input visits,
the original setup and both actual MOV call segments on the reached heap.
The first 98 traces and the later origin-provider trace remain ordered in
the resulting whole source execution to the original afterKeep successor.

The setup interface now retains its already-derived access-map equality.
The same setup result derives canonical bounds, its complete register relation,
context reads and the actual cold SP-cache byte. These facts discharge the
first call's invocation requirements; no reached Storage, register relation,
readback, permission, cold-byte or allocation premise is added to the entry.
Mark and priority remain unrestricted context uint32 values.

The theorem first exposes the actual reached setup heap. It then admits the
last origin reply and frame only at that heap's real generic-call allocation.
It does not assume availability on arbitrary other heaps. Under that explicit
outcome admission, it derives the whole source Star with the retained trace,
final scalar word/tag0, writable Storage, complete nested register update at
the reached producer frontier, original context/caller frame and both real
frees with their actual release/contents/frontier witnesses.

The nativeSetup state is the existing architectural input-view update, not
a claim that setup instructions were fetched. Unrestricted MOV_IMM's actual
native sequence, physical ABI/provenance/provider production validity, later
source instructions, all outcomes and final return remain M5 work. The fetched
ordinary MOVK source-segment correspondence is recorded in m5-entry-mov-native.
No ISA family is completed.

Focused source check passes 230 jobs and two public type/axiom queries at the
original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. The first finite attempt hit a reserved proof-local name;
its log is retained. Whole `lake build KProgFormal` proof-library/root confirmation passes 280
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-entry-mov-prefix`. M5/M6 remain open.
