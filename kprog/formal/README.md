# Native simulator verification

Run the complete local check on an x86-64 host:

```sh
make -C kprog/formal check
```

It requires Lean/Elan, Python3, Rust/Cargo, a C compiler with UBSan,
clang18/LLVM18 tools, GNU objdump, and the `vendor/libbpf` and
`vendor/linux-framework` submodules. The target builds every Lean theorem
module, checks generated contracts and routing, rejects proof placeholders,
and runs the C semantic oracles and executable-reference checks. Papers and
paper/count checkers are not inputs.

The specification is the single executable ISA model in
[`Reference/X86.lean`](KProgFormal/Reference/X86.lean) and
[`Reference/AArch64.lean`](KProgFormal/Reference/AArch64.lean), with the shared
memory, permissions, initialization, effects and faults in
[`Reference/Memory.lean`](KProgFormal/Reference/Memory.lean). Their headers
identify the Intel/Arm architectural sources; they import no simulator or
generated implementation contracts. Unwritten native memory has arbitrary
contents, not invented zeros. Undefined x86 flags and double-shift destination bits are masked by the
relational step instead of assigning them architectural guarantees. Single-step
responses include `defined_registers` when destination bits are undefined. ARM memory and
exclusive accesses carry their explicit architectural/environment inputs;
control uses the current Cortex-A72 base profile without GCS/BTI state. Logical
immediates decode native bitmask fields and reserved encodings, including
SP destinations for AND/ORR/EOR and ZR destinations for ANDS/TST. Their generated
value/width/flag lift preserves the same complete numeric state. Actual logical-immediate
ALU AUX selection and all six TST/ANDS/BICS numeric dispatch rows compose
with their generated operand/value/write/flag primitives. Test aliases retain
DST/SRC routing; register forms retain native shift bounds and SP/ZR rules. Generic ALU_REG
logical forms also compose the generated register RHS with AUX extraction,
including the stack-ORR path and bare NONE modifiers.

The proofs establish arithmetic/flags, register and tag operations, memory
accesses, routing tables, and selected whole-state handler refinements.
[`Refinement/`](KProgFormal/Refinement/) connects generated implementation
slices to those same ISA steps, retaining registers, flags, vectors, memory,
PC and ordered effects/faults. This includes scalar/logical/unary operations,
width/sign extensions, signed and unsigned multiplication, conditional operations, shifts, bit operations,
stack transfers, LEA, DIV, register XCHG, classic ROR, REP MOVS iteration progress and XMM0 successful-access
lane projections, and the ARM arithmetic, vector, memory, exclusive and control
families represented there. Exclusive load/store core lifts additionally compose
the generated native-width memory primitives and W-status writeback, retaining
both outcomes. Monitor state and ordering events are ghost annotations whose
platform witnesses remain explicit; this does not certify ordinary stores as
atomic exclusive operations. D0 load/store lifts compose generated eight-byte
memory operations, upper-half clearing, indexed addressing and the two singleton
dispatch arms, retaining full state, ordered effects and faults under the explicit
SP-alignment witness. XMM0 MOVUPS/MOVAPS references include 16-byte
permission and alignment faults; the two-lane C projection currently requires
successful, suitably aligned access. REP MOVS includes direction, address32,
segments and restart faults; its C core lift requires a matching bounded count,
forward direction, default addressing and successful accesses. Near CALL/RET
uses explicit 48/57-bit paging canonicality (default 48, optional
`state.linear_address_bits`) with CET (IBT and shadow stacks) disabled. Internal call/return
stack cores are distinct from helper and outer-invocation platform certificates. D0 pre/access/post success cores and their two dispatcher arms additionally
compose generated base updates with the transfer, under explicit accessible-memory
and original-SP alignment witnesses. Their numeric projection still needs Entry/O4
tag and address transport. Faulting pre/post accesses remain a separate obligation.
The scalar writeback lift in `Arm64WritebackMemory.lean` composes the actual
pre/access/post order for ordinary and signed loads/stores, all four widths,
and generated register-offset modifiers. It uses the canonical writeback-alias
restriction and explicit successful-access/original-SP witnesses; its LOAD and
STORE singleton compositions preserve the same complete numeric state and effects.
LDRSB/LDRSH/LDRSW additionally compose their generated opcode, memory width and
sign-operation selections with the same core and numeric family-dispatch gate,
including no-writeback register-offset forms.
LDP/STP also compose the two generated element transfers and pre/post updates,
retaining both ordered effects on the explicit two-access (non-LSE2) profile;
original-SP alignment, per-element access and canonical alias validity remain explicit.
The FMOV/CNT/UADDLV dispatcher tail composes numeric opcode/AUX selection,
all32 vector banks and legacy NONE→V0, generated direction/destination/width
selection and full-state steps; invalid fields retain rejection. Native decoding
and Entry/O4 must bind the typed operands, bank, direction and width flags.
BITFIELD, MOVK and SHIFT compose packed AUX extraction with generated value
operations, typed native bounds and dispatcher gates, independently of unused
AUX bytes. SHIFT also binds immediate/register count selection and the two
generated tables' numeric operation codes. MVN/NEG also compose AUX modifier/count
selection, including the identity modifier and its unused shift byte. MOV binds the two
operand-source tables and the full-width pointer/narrowing branch order;
immediate field31 remains ZR, while register operands distinguish SP and ZR. The eight-member
multiply dispatcher includes UDIV input narrowing, unused alias operands and
explicit X-width validity for long/high multiplies. EXTR/REV/REV16/SXT* bind
the six numeric labels, EXTR-only input narrowing and unused operand fields. A concrete
SHIFT→multiply→unary→CNEG→extract/reverse/extend segment composes the production
branch order and proves that preceding numeric gates cannot intercept later
family members. CSEL/CNEG also
compose whole-AUX condition decoding, NV normalization and the generated
CSEL/X pointer-preserving gate; alias condition validity remains explicit. CCMP also
binds both numeric operand rows and packed condition/fallback bytes: only
the fallback ignores its upper four bits. ADDS/SUBS/CMP/CMN compose their
eight numeric rows and packed modifiers with immediate, shifted and extended
arithmetic steps, preserving writeback versus compare-only behavior.
Individual module statements define their
exact scope. Dispatcher coverage/exclusivity is
**not yet a full simulator-step refinement theorem**; completing the remaining
handler lifts and their dispatcher composition is ongoing work.

The lifts consume materialized native register/address values.
[`EntryEnvironment.lean`](KProgFormal/Refinement/EntryEnvironment.lean)
states the same-invocation SP/code/return relation, with explicit frame biases
and argument/return witnesses. Kernel/JIT, ABI and artifact certificates must
establish those witnesses and code/provenance/profile bindings. A private
stack offset alone is not a native numeric address. The entry arithmetic and
partial-write theorems preserve this distinction.

Trust boundary: Lean checks Lean models, not arbitrary C source or compiled
BPF. The Lean kernel/toolchain are trusted; `native_decide` additionally trusts
compiled evaluation. JSON-to-C/Lean generators, C compilation and native
byte lowering remain cross-language boundaries: freshness checks, independent
semantic oracles, real CPU examples and BPF access checks test them. They do
not prove compiler correctness. Hardware fidelity, verifier acceptance,
platform helpers and artifact/invocation binding require their corresponding
evidence and proofs; a local passing check does not establish them by itself.

Actual linked ARRAY/PERCPU_ARRAY instruction paths are checked against the
canonical x86 model, including bounds, reads and first faults. Inline lookup
blocks emit no helper event; direct map-type calls retain their exact target
and relocation. Callee effects, arguments, map layout, CPU inputs and checked
helper expansion use the [TV platform contract](../tv/README.md#map-lookup-inlining-and-the-proof-boundary-2026-11-07).
These fixture paths are not application invocation certificates.

Layout:

- `KProgFormal/Reference/`: executable reference ISA and shared effects.
- `KProgFormal/Refinement/`: lifts against that reference; other modules in
  `KProgFormal/` retain the original bounded handler/table theorems.
- `contracts/`, `tools/generate_*`, `generated/`, `KProgFormal/Generated/`:
  implementation contracts, generators and emitted C/Lean expressions.
- `oracles/`: retained semantic C hosts, including the former build hosts.
- `tools/`: executable reference, encoding and semantic checks;
  `tools/mutations/` retains the tracked semantic mutation batteries.
- `build/`, `.lake/`: disposable generated/compiled outputs.

The same reference builds as `.lake/build/bin/reference`: JSON lines on stdin,
one complete transition per output line. Inputs provide native bytes, actual
registers/PC and explicit memory cells (value, permissions, initialization).
x86 also supplies XMM0/FS/GS and supports finite native paths whose byte extents
and actual successors are checked. Path outputs are executable representatives;
the producer's definedness evidence must justify observations of undefined state. AArch64 currently accepts one four-byte
instruction per request, with explicit SIMD/environment fields when needed.
The `tools/check_reference*` scripts are concrete examples. They execute these
Lean definitions, not a second Python/C ISA interpreter. F's hardware replay
and T's path/artifact checks consume this same canonical specification.
