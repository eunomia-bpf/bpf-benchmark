# Actual entry prefix and admitted native MOV pair

`Arm64ProgramEntryMovPrefixNative.entry_corresponds` consumes the existing
actual wrapper's 98 input visits, setup and two original source calls. Its
final complete register relation now targets the actual second LNSym step
from the architectural setup view. Both reference event/fault deltas are empty.
The native sequence retains PC+8 and all non-written machine state.

Setup's existing native_other and native_resources facts derive unchanged
PC, program and error. Fetch and no-error admission therefore remain on the
original native input, without new premises on a setup/post-call state.
The complete source Star retains the 98 traces followed by the later origin
trace, actual reached heap, scalar word/tag0, Storage, original context frame
and both real free/contents/frontier/release witnesses.

The last origin reply/frame is admitted only at its actual reached generic
allocation. First decoded fields explicitly bind the full normalized source
literal. No numeric input bound or synthetic two-word literal is added.
This does not assert a matching MOVZ/MOVN word for every uint32 mark.
Setup remains an architectural input-view update, not a fetched setup-body
proof. Physical ABI/provenance, provider trace/production validity, other MOV
encodings/handlers, later control, all outcomes and final return remain M5 work.
Completed ISA-family count is zero.

Focused entry/native check passes 235 jobs and one public type/axiom query
at original 200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and
32 GiB address space. Whole `lake build KProgFormal` proof-library/root confirmation passes 283
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-entry-mov-prefix-native`. M5/M6 remain open.
