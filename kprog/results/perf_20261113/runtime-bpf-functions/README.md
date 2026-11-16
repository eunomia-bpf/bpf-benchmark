2026-11-16T10:43:11Z

Source 0f5c55894 shares the existing exact BPF constant-leaf materializer
between producer lowering and trusted runtime LTO. Runtime LTO now accepts
explicit function bodies from a facts file and a program type; PERF_EVENT
context conversion remains selected for PERF_EVENT, with its previous default.
The runtime compiler reads embedded LLVM IR from P, materializes the supplied
MOV64/MOV32 immediate plus EXIT bodies before O3, then emits native code.
No app name, missing body or absent metadata supplies an implementation.

Validation through the committed Make entry on CPU 16 with an 8 GiB address-space
bound finished at 10:42:25 UTC: six values times 48 real indirect ABI vectors
through both compilers, five producer and four runtime malformed/unsupported
cases, and both absent-facts producer paths byte-identical to the retained
reference tool. Six signatures cover scalar widths, pointers and void returns;
MOV64 sign extension and MOV32 zero extension are checked. Existing public,
loader/cache and static-entry PERF_EVENT tests each pass 256 contexts with
zero mismatches. All fixture facts are constructed test inputs, never app facts.

```sh
make -r -f kprog/test/perf-context-lto.mk function-check check CPUS=16 \
  OUTPUT=/workspaces/kprog-raw/perf/20261116-runtime-bpf-functions
```

Raw compiler logs, exact inputs, binaries and output are retained in that raw
directory, including function-build.tar.gz and build.tar.gz. No image/base was
replaced during the active round. The live metadata consumer, shared P/B facts,
and compilation of nonconstant generated bodies remain open under P1j-d19.
This component does not establish native installation or performance.


2026-11-16T10:49:00Z: loader consumer 338d5b7df now reads the program-specific original
function sidecar, binds its program/BTF identity, resolves names in live BTF,
and slices the original bytecode. Undefined P functions receive only bodies
present in that actual table. Materialization precedes entry proof extraction
and the trusted P/B request; the cache includes exact bodies and program type.
Absent metadata keeps the existing path. Non-PERF_EVENT programs with actual
function facts now also use the same native IR LTO emitter.

Host ELF/BTF extraction, six real native signatures with empty BTF parameter
lists, 0 and -1 bodies across 48 call vectors each, distinct changed-body cache
keys, unchanged-body reuse, and program-specific metadata identities pass.
Defined/unmatched functions are not materialized. Public, loader/cache and
static PERF_EVENT regressions again pass 256 contexts each. Raw logs and exact
inputs are in /workspaces/kprog-raw/perf/20261116-runtime-bpf-functions-loader;
loader-report.json records the result. This host subset uses constructed BTF
and does not claim live-kernel BTF I/O or real Tetragon installation. C's
capture writer, actual app replay and nonconstant CEL compilation stay open.
The current image and running default rotate are unchanged.


2026-11-16T10:59:46Z: committed live-BTF regression 701d034e9 with input-mapping correction
649692654 passes on the sole kernel, CPU 16, one vCPU/2 GiB guest/8 GiB AS,
imageSH without timing lock. The fixture loads original BTF and six original
BPF instructions, with func_info at offsets 0 and 4. The loaded program's real
ID/BTF ID locate the per-program sidecar and live BTF; the consumer extracts
the two supplied callee instructions. Original BPF test execution and the
native artifact compiled from those same bytes both return 9. The callee BTF
has empty Params while its native declaration takes two arguments.

Raw: /workspaces/kprog-raw/perf/20261116-live-function-facts, including initial
job.log (guest temporary path missing), corrected job-mapped.log, actual
original bytecode/metadata, kernel.json, native output and live-build.tar.gz.
Only the recipe's input mount changed after the initial failure; no source
copy, second build, image/base publication or benchmark-entry edit was needed.
This exercises actual live BTF I/O and original function offsets. The source
is a constructed regression fixture, not a Tetragon capture. Native code ran
in userspace; native kernel installation, actual app capture, nonconstant CEL
and checked B acceptance remain separate. live-report.json records scope.


2026-11-16T11:08:42Z: dae9cdac4 completes the original-record writer in the production
shim. The hook runs after the original BPF_PROG_LOAD succeeds and before the
native replacement call consumes the metadata. It queries the original FD
for program/BTF identity and normalizes the pre-syscall deep copy using its
original record stride. A program-specific sidecar avoids collisions when
multiple loads share the same bytecode. Capture I/O errors are reported through
the existing diagnostic channel; this adds no benchmark admission condition.

The actual LD_PRELOAD shim, live kernel BTF consumer and native LTO execute
successfully on the sole kernel: original record stride 16, offsets 0/4,
program 3, BTF 27, and BPF/native return 9.
This mode consumes the shim-written file; the test does not create the sidecar
itself. Host subsets also check two distinct tables for the same bytecode,
normalization of extended records and an actual ENOENT output failure, together
with the existing body/cache ABI regressions. Raw metadata/source, logs and
build archives remain at /workspaces/kprog-raw/perf/20261116-shim-function-facts.
Source and inputs are a constructed regression fixture. Nonconstant CEL,
actual Tetragon installation and checked B acceptance remain open. No image,
base, application flag or benchmark entry was changed for this check.


2026-11-16T11:31:29Z: 3e7355e51/63547fcfe extend runtime materialization to nonconstant
captured bodies through the existing canonical BPF lowering. A companion
compiler reuses the canonical runner's four LLVM/BPF object files and emits
unoptimized textual LLVM IR. It replaces the kernel-entry R2–R5 zero stores
with all five actual caller arguments before promotion/optimization. The
existing LLVM 18 native LTO tool parses that text, links the same supplied
body, preserves pointer/scalar return ABI and target/GPR/no-red-zone flags,
and then runs its existing optimization/codegen pipeline. Helper IDs remain
numeric for the normal native linker; selected program boundaries remain
separate. No vendor compiler, producer flag, second library build or benchmark
entry changed. 89330803f tracks canonical object/header dependencies normally.

6095819c3 preserves alignment 1 for ordinary BPF loads/stores, since access
width does not promise address alignment. Native execution and proof extraction
pass for seven nonconstant functions and 256 vectors each: R1–R5, aligned and
unaligned loads, stack, backward-loop byte summation, signed branching, narrow
arithmetic and side-effect stores. Producer absent-facts output remains
byte-identical; six constant values by 48 ABI vectors and nine combined
producer/runtime failure cases pass. Public, loader/cache and static PERF_EVENT
regressions each pass 256 contexts. The actual shim/live-BTF test now captures
MOV R0,R1; ADD R0,R2; EXIT: both stock original BPF and the generated userspace
native artifact return 13, with original stride 16 and function offsets 0/4.

Raw logs/inputs/build archives: /workspaces/kprog-raw/perf/20261116-bpf-callee-ir,
including alignment/ for the final memory-access subset. nonconstant-report.json
records the result. Only test input semantics changed from the earlier constant
9 fixture; old raw/receipts remain. This is compiler, ABI and live-capture
coverage, not actual Tetragon installation or full checked-B acceptance. Runtime
package staging now includes kprog-bpf-callee-ir; publication remains deferred
while the current round holds imageSH. Generated body facts participate in both
P and B through the same entry proof/request; cache identity also includes the
companion compiler when present.


2026-11-16T11:54:25Z: 3bce4215f tests the actual unmodified Tetragon celbpf.CompileFn
implementation through the native runtime compiler. Nineteen vectors over
four expressions pass native execution and entry proof extraction: uint64
and uint32 comparison, signed int32 argument equality and signed arithmetic,
including 32/64-bit boundary values. Argument offsets/data follow upstream's
own DummyMsg layout, and no application source was edited. Code is generated
by the upstream Go compiler, rather than constructed BPF instruction fixtures.
This strengthens source/ABI coverage but does not claim actual app startup,
stock verification of the generated simulator B, or runtime performance.
Raw Go/compiler/native/proof logs and build archive are retained in
/workspaces/kprog-raw/perf/20261116-upstream-cel; compact report and exact input
bodies/values are committed here. Job 1494179 is terminal.
