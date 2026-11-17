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

The host job 2750151 completed successfully at 20:44:03Z. The original
regression failed after compiling successfully (status 101): the branch
into `bpf_jiffies64` did not target its emitted load. After the fix,
**57 tests pass**, with three existing ignored tests. The new regression
executes 96 branch/fallthrough/live-value/tail-miss cases across both helper
families, named/numeric calls, symbol bases 0/32 and call/NOP entry targets.
The existing tail frame and counter relocation tests also pass.

All **647** prior unrelated payload/metadata files are byte-identical.
The sole main linker rebuilt in 29.42 seconds and successfully emitted all
**295/295** current six-app requests, without adding facts or dropping
requests. Source/test is only `native_link/src/x86.rs`; the original-label
fix uses the existing replacement emitter for the first chunk. Proof mode,
helper policy, source memory barriers, runtime work and frame-counter
relocation stay intact. The obsolete first-chunk synthetic-label behavior
is replaced directly, with no switch or new runtime guard.

Neutral host replay totals in `replay-summary.txt` are not installed native
size or per-call time. App body/helper/map, throughput and installed-size
measurements remain for the owner image/check/timing batch with all LTO on.
Full commands, before/after logs, source patch, emitted images/relocations
and per-request replay metadata remain at `host-location.txt`'s raw path.
The affected application branch sites are classified separately from mere
byte-layout differences; no branch execution frequency is inferred here.
