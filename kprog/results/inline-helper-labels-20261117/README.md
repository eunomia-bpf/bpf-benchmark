# Branches into inline helper replacements

Phase-1 regression for the production x86 rewriter. Direct-load helper and
tail-call stub sequences currently begin with synthetic chunks that discard
the original call address. Existing branch remapping can then select the
next surviving original instruction and skip the helper entirely.

The focused test constructs real ELF call relocations and numeric helper
calls, branches to the call or a removed preceding NOP, and tests zero/nonzero
symbol bases. A live jiffies word exposes skipped loads. The tail-call miss
path exposes skipped index zero-extension without touching a real BPF frame.
Both branch and fallthrough paths execute, with changing values. The fix
reuses `push_x86_replacement` for the first chunk and retains synthetic
labels for subsequent chunks. Existing frame-counter relocation and all
runtime helper work remain; no runtime check, flag, limit or new emitter.

The committed host recipe holds timing SH then image EX on CPU 19, with one
Cargo worker and 32 GiB address-space limit. It records the baseline test,
applies the forward fix, runs the existing full suite, compares unrelated
payload/metadata bytes, builds the sole main linker and replays all 295
fresh requests. It changes only open native_link source plus own records.
No guest or image build is started. The frozen helper-prototype core class
remains independently with its owner. Raw data is retained under `/workspaces`.
