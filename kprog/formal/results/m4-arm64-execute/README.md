# ARM instruction dispatcher C extraction

The real `ARM64_SIM_L_EXEC` instruction body now exports through the existing
caller-owned addressing ABI, with separate references to four byte flags and
32 vector cells. Capacity/bias and byte/tag/payload buffers remain caller-owned.
`Arm64Addressing` has31 functions/18,806,455 bytes; `Arm64Numeric` has20 functions/
167,556 bytes. This covers the instruction dispatcher, including its actual
memory and arithmetic branches. Entry initialization, helper/libc calls and
program control wrappers remain separate M4 work; this is not full ARM program
closure or a refinement theorem.

Native numeric initializers retain their expression forms and operands. The
CompCert declaration facade uses the corresponding shared output kernels;
MOV/CSEL-path, flag operand, MOVK, ALU source, ORN, condition and reduction bodies
are shared with the native facade. Conditions retain repeated code evaluation,
short-circuit flag reads and raw byte flag results. Register reads, writes and
modification reuse existing exported C primitives at their original expression
sites. These are ordinary C callees requiring linking/effect correspondence in
M5, not new semantic imports. CNT's extraction-only builtin adapter reuses the
existing pure SWAR popcount body; native compilation keeps its original builtin.

Historical4a2b31f48/current-native/CompCert-adapter runs each capture4,320 whole
numeric/vector states over six capacity/bias profiles:1/0,7/-3,9/4,160/96,
200/160 and376/280. Every capture byte, callback kind/value order and rejection
prefix agrees:7,827,228 bytes per run, without masks. The selector oracle checks
raw64-bit widths, operand capture order, defined invalid MOVK columns, repeated
condition evaluation, flags0/1/2/255 and every256 byte values in all eight CNT/
UADDLV positions. Additional null-reference probes check EQ reads only Z and AL
reads no flags. Five mutations fail their intended independent assertions.
The initial matrix mistakenly included atomic instructions without an atomic
backend; that failed attempt is retained, and memory operations use the separate
independent memory oracle.

`make clight` now links the existing address/numeric C definitions and runs both
native and extraction adapters through the instruction dispatcher for scalar/
signed loads, stores, pair operations, exclusive stores and atomic add/set/clear.
The existing memory oracle checks complete frames, provenance, writeback,
rejection prefixes, operation order and ABI fields. Its primitive-only fault,
tag-transfer and vector entry tests remain primitive tests; their counts are
not reclassified as whole-dispatch coverage. The whole dispatcher must also
leave all unrelated flags and vector cells unchanged in those memory tests.

Final `make clight`, all ten Clight modules (47 Lake jobs), deterministic
re-exports and six AST-root/program axiom queries pass. Axiom dependencies are
only propext/Classical.choice/Quot.sound. The expanded BPF fixture (numeric,
flags, FMOV, CNT/UADDLV and dynamic condition) is exact against historical
headers:5,288-byte socket section and one allocated relocation; current streamed
and ordinary compilations also agree. This is fixture coverage, not all default
program bytes. The frontend CPP measurement is2,046,516 bytes for this extraction
translation unit, not a production-scale expansion factor.

The initial21,339,760-byte export parsed but Lean exhausted its unchanged32GiB
virtual-memory limit. Reusing the existing exported write primitives removes
repeated SP-release bodies; the18,806,455-byte export builds in309 seconds with
actual `-j1` on CPU15 under that same limit. No Lean proof/recursion limits were
raised. Initial errors are retained. Final confirmation's receipt collector
also expected `clightgen -E -o` to create a file; the frontend writes stdout.
The complete stdout was retained and measured, and only the receipt/axiom tail
was completed afterward; the successful full C confirmation was not repeated.

Reproduce the historical comparison and five negative checks with
`taskset -c 15 python3 results/m4-arm64-execute/compare.py --output <new-raw-dir>`
from `kprog/formal`, keeping the32GiB address-space limit. The script streams
historical/current headers in RAM and replaces one ordinary set of build
products. Full commands, logs, complete binary frames and failed attempts are
under `/workspaces/kprog-raw/formal/m4-arm64-execute`.

The common comparison recipe was extended by the subsequent
[wrapper step](../m4-arm64-wrappers/README.md). It now also runs the wrapper
frames and six additional negative cases; the five original mutations and
this step's original raw captures remain retained.

M4 remains open for helper/libc/control wrappers, real producer/storage profile
coverage, platform correspondence and whole-default compiled bytes. Then M5
must migrate all2,065 actual Clight-vs-LNSym/x86lean refinements and recount
O1/O2/O4; M6 retirement and whole-library `lake build`/`make check` follow.
