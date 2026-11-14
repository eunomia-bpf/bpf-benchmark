# OTel main: stock acceptance with whole-word scalar spills

The stock verifier accepted the retained OTel main proof after two compiler
scalar spill slots were represented by one aligned 64-bit word. The compiled
frame is 512 bytes. `verify.stdout` records `phase=verify`, `status=0`, and
program id 11. The replay then cancelled the submission; native compilation,
installation and application execution remain the next steps.

The same native P and entry `perf_unwind_native` came from the recorded main
request. `generation.metadata.json` matches its original normalized metadata.
The diagnostic creates real maps from the original source BPF object and uses
libbpf setters to reproduce the application's captured map sizes and flags;
`resources.json` records those adjustments. Captured program type 7 supplies
the type for the source's `perf_event/unwind_native` section.

The run-only MIR transform handles direct 32-bit scalar spill loads and stores.
A store reads the word, retains the other half, inserts the source's low 32
bits, and writes all 64 bits. Loads extract their half with zero extension.
The entry initializes the private word. Physical-register liveness chooses
dead scratch registers for each store. This main's final scalar slots 17 and
18 required 27 transformed accesses. The remaining slots retain eight-byte
alignment, and the native VM's 376-byte private stack retains its layout.
Both LLVM `-verify-machineinstrs` checks completed successfully. The earlier
four-byte packing attempt's verifier log identifies the context-tag precision
loss; the six committed scalar-spill cases separately demonstrate whole-word
tracking with runtime-unknown values in the other half.

The accepted object is retained as `accepted.bpf.o`. The compiler transform is
`kprog/test/whole_word_spill_probe.py`, exercised through
`make -f kprog/test/scalar-spill-precision.mk whole-word`, with original
pre-PEI MIR and `LOW=17 HIGH=18`. `whole.lowering.json` lists every replacement.
`command.json` records the actual loader verification command.
The diagnostic VM used the sole kernel build, a shared image lock, CPUs 22–23,
one vCPU and 8 GiB. The default compiler path retains its existing bytes.

Raw data and launch logs are under
`/workspaces/kprog-raw/perf/20261114-scalar-spill-precision/`. The initial
resource-discovery errors and the 2,096-byte boot command are retained there.
`boot-command-line-failure.json` records the x86 2,048-byte truncation; the
argument-file launcher resolves it. Accepted proof generation is a compiler
milestone; the combined OTel runtime results retain their prior scope.
