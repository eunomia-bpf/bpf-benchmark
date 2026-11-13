# Target-BTF resolution for unchanged BPF source

`core-ir-resolve` is an optional compiler step. It consumes the BPF frontend's
optimized LLVM IR and a BPF ELF built from the same source/configuration. Its
local BTF supplies the access specifications; the sole kernel's BTF supplies the
target. No application source or replacement header is used by the translator.
Default native builds do not invoke it.

```sh
make -f kprog/perf/native-context/Makefile core-ir-check
make -f kprog/perf/native-context/Makefile core-ir-resolve \
  CORE_IR_INPUT=/path/to/source.bc CORE_IR_LOCAL_BPF=/path/to/source.bpf.o \
  CORE_IR_OUTPUT=/path/to/resolved.bc CORE_IR_REPORT=/path/to/relocations.json
```

The BPF frontend encodes CO-RE queries as `btf_ama` and `btf_type_id` globals.
The tool associates their debug root types with the local ELF's BTF, checks the
local layout and encoded default, and invokes the vendored libbpf relocation
resolver. Candidate narrowing, anonymous members, arrays, bitfields, flavors,
existence, size, enum and type-ID queries use that implementation. Every query's
original/target value, field sizes and missing-target decision are recorded.

Loads from these globals become resolved constants. BPF passthrough markers
become their original values. Missing value/access relocations become explicit
unresolved calls until optimization removes unreachable branches. A reachable
unresolved query fails compilation. Unsigned direct scalar accesses now resize
narrowing loads/stores, widening loads with pure zero-extension users, and
widening register stores that consume a source truncation. Volatility is kept and
the rewritten accesses allow unaligned fields. Signed size changes retain
libbpf's poisoned-memory behavior. Other widening expressions still report a
compiler error and remain open under P1h. Offset changes to aggregates do not imply resizing a scalar
load, and helper-only source reads retain their source size. The retained Tracee
input has no pending direct scalar access resizing.

Run this step before native context/helper retargeting and app-specific asm
lowering. It leaves the BPF target triple in place. The host fixture subsequently
uses `socket-context-lower --native-codegen` to strip target attributes and compile
for x86; the translator alone does not install a runtime manifest or execute
application code.

The fixtures exercise every CO-RE relocation kind against the sole target BTF,
including negative local enum values, missing field/type/enum guards, target
bitfield shifts and independent local/target type-ID lookups. Separate cases
require diagnostics for reachable missing fields, mismatched source metadata,
signed memory poisoning and an unimplemented widened comparison. Additional
host cases exercise narrowing/widening reads and stores over eight boundary
values, checking all neighboring bytes and the unchanged helper-copy length.
The reference test patches the original ELF's five actual BPF relocations with
libbpf: four memory widths change, while a helper's address-only immediate keeps
its compiled copy length. A signed access is poisoned in the original BPF too.
The real Tracee compiler result is a host
integration observation. It establishes neither application output parity nor
native execution correctness; P1h and the equal-work task remain open.
