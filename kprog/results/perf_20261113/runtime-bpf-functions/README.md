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
